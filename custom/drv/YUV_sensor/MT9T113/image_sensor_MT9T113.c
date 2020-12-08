/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   image_sensor_MT9T113.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor driver function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "isp_comm_if.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "cal_comm_def.h"
#include "isp_if.h"


static struct
{
  kal_bool BypassAe;
  kal_bool BypassAwb;
  kal_bool PvMode;
  kal_bool VideoMode;
  
  kal_uint8 Banding;
  kal_uint16 VideoFps;
  kal_uint32 IntClk; /* internal clock which is releated by exposure */
  kal_uint32 Gain; /* base on 0x40 */
  kal_uint32 Shutter;
  kal_uint32 FrameHeight;
  kal_uint32 LineLength;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} MT9T113Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

#ifdef MT9T113_LOAD_FROM_T_FLASH
/*************************************************************************
* FUNCTION
*  MT9T113_Initialize_from_T_Flash
*
* DESCRIPTION
*  Read the initialize setting from t-flash or user disk to speed up image quality tuning.
*
* PARAMETERS
*  None
*
* RETURNS
*  kal_uint8 - 0 : Load setting fail, 1 : Load setting successfully.
*
*************************************************************************/
static kal_uint8 MT9T113_Initialize_from_T_Flash()
{
#include "med_utility.h"
#include "fs_type.h"

#if MT9T113_I2C_ADDR_BITS == CAMERA_SCCB_16BIT
  #define MT9T113_REG_SKIP    0x08
#else
  #define MT9T113_REG_SKIP    0x06
#endif
#if MT9T113_I2C_DATA_BITS == CAMERA_SCCB_16BIT
  #define MT9T113_VAL_SKIP    0x08
#else
  #define MT9T113_VAL_SKIP    0x06
#endif
  
  /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
  #define MT9T113_OP_CODE_INI    0x00    /* Initial value. */
  #define MT9T113_OP_CODE_REG    0x01    /* Register */
  #define MT9T113_OP_CODE_DLY    0x02    /* Delay */
  #define MT9T113_OP_CODE_END    0x03    /* End of initial setting. */
  
  typedef struct
  {
    kal_uint16 init_reg;
    kal_uint16 init_val;  /* Save the register value and delay tick */
    kal_uint8 op_code;    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
  } MT9T113_initial_set_struct;
  
  extern kal_uint16 mmi_asc_to_ucs2(kal_char *pOutBuffer, kal_char *pInBuffer);
  static MT9T113_initial_set_struct MT9T113_Init_Reg[1000];
  static WCHAR MT9T113_set_file_name[50];
  static kal_char buf[50];
  FS_HANDLE fp = -1;        /* Default, no file opened. */
  kal_uint8 *data_buff = NULL;
  kal_uint8 *curr_ptr = NULL;
  kal_uint32 file_size = 0;
  kal_uint32 bytes_read = 0;
  kal_uint32 i = 0, j = 0;
  kal_uint8 func_ind[3] = {0};  /* REG or DLY */
  kal_int32 storage;
  
  storage = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
  if (FS_NO_ERROR != FS_GetDevStatus(storage ,FS_MOUNT_STATE_ENUM))
  {
    storage = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL|FS_DRIVE_V_REMOVABLE);
  }
  sprintf(buf, "%c:\\%s", storage, "MT9T113_Initialize_Setting.Bin");
  mmi_asc_to_ucs2(MT9T113_set_file_name, buf);
  
  fp = FS_Open(MT9T113_set_file_name, FS_READ_ONLY);
  
  if (fp < 0)    /* Error handle */
  {
  #ifdef __MT9T113_DEBUG_TRACE__
    kal_wap_trace(MOD_ENG, TRACE_INFO, "!!! Warning, Can't find the initial setting file!!!");
  #endif
  
    return 0;
  }

  FS_GetFileSize(fp, &file_size);
  if (file_size < 20)
  {
  #ifdef __MT9T113_DEBUG_TRACE__
    kal_wap_trace(MOD_ENG, TRACE_INFO, "!!! Warning, Invalid setting file!!!");
  #endif
  
    return 0;      /* Invalid setting file. */
  }

  data_buff = med_alloc_ext_mem(file_size);
  if (data_buff == NULL)
  {
  #ifdef __MT9T113_DEBUG_TRACE__
    kal_wap_trace(MOD_ENG, TRACE_INFO, "!!! Warning, Memory not enoughed...");
  #endif
  
    return 0;        /* Memory not enough */
  }
  FS_Read(fp, data_buff, file_size, &bytes_read);

  /* Start parse the setting witch read from t-flash. */
  curr_ptr = data_buff;
  while (curr_ptr < (data_buff + file_size))
  {
    while ((*curr_ptr == ' ') || (*curr_ptr == '\t'))/* Skip the Space & TAB */
      curr_ptr++;        

    if (((*curr_ptr) == '/') && ((*(curr_ptr + 1)) == '*'))
    {
      while (!(((*curr_ptr) == '*') && ((*(curr_ptr + 1)) == '/')))
      {
        curr_ptr++;    /* Skip block comment code. */
      }

      while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
      {
        curr_ptr++;
      }

      curr_ptr += 2;            /* Skip the enter line */
      
      continue ;
    }
    
    if (((*curr_ptr) == '/') || ((*curr_ptr) == '{') || ((*curr_ptr) == '}'))    /* Comment line, skip it. */
    {
      while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
      {
        curr_ptr++;
      }

      curr_ptr += 2;            /* Skip the enter line */

      continue ;
    }
    /* This just content one enter line. */
    if (((*curr_ptr) == 0x0D) && ((*(curr_ptr + 1)) == 0x0A))
    {
      curr_ptr += 2;
      continue ;
    }
    
    kal_mem_cpy(func_ind, curr_ptr, 3);
    curr_ptr += 4;          /* Skip "REG(" or "DLY(" */
    if (strcmp((const char *)func_ind, "REG") == 0)    /* REG */
    {
      MT9T113_Init_Reg[i].op_code = MT9T113_OP_CODE_REG;
      
      MT9T113_Init_Reg[i].init_reg = strtol((const char *)curr_ptr, NULL, 16);
      curr_ptr += MT9T113_REG_SKIP;  /* Skip "0x0000, " */
      
      MT9T113_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 16);
      curr_ptr += MT9T113_VAL_SKIP;  /* Skip "0x0000);" */
    }
    else                  /* DLY */
    {
      /* Need add delay for this setting. */
      MT9T113_Init_Reg[i].op_code = MT9T113_OP_CODE_DLY;
      
      MT9T113_Init_Reg[i].init_reg = 0xFF;
      MT9T113_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 10);  /* Get the delay ticks, the delay should less then 50 */
    }
    i++;
    
    /* Skip to next line directly. */
    while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
    {
      curr_ptr++;
    }
    curr_ptr += 2;
  }

  /* (0xFFFF, 0xFFFF) means the end of initial setting. */
  MT9T113_Init_Reg[i].op_code = MT9T113_OP_CODE_END;
  MT9T113_Init_Reg[i].init_reg = 0xFF;
  MT9T113_Init_Reg[i].init_val = 0xFF;
  i++;
  
#ifdef __MT9T113_DEBUG_TRACE__
  kal_wap_trace(MOD_ENG, TRACE_INFO, "%d register read...", i-1);
#endif

  med_free_ext_mem((void **)&data_buff);
  FS_Close(fp);

#ifdef __MT9T113_DEBUG_TRACE__
  kal_wap_trace(MOD_ENG, TRACE_INFO, "Start apply initialize setting.");
#endif
  /* Start apply the initial setting to sensor. */
  for (j=0; j<i; j++)
  {
    if (MT9T113_Init_Reg[j].op_code == MT9T113_OP_CODE_END)  /* End of the setting. */
    {
      break ;
    }
    else if (MT9T113_Init_Reg[j].op_code == MT9T113_OP_CODE_DLY)
    {
      kal_sleep_task(MT9T113_Init_Reg[j].init_val);    /* Delay */
    }
    else if (MT9T113_Init_Reg[j].op_code == MT9T113_OP_CODE_REG)
    {
      CamWriteCmosSensor(MT9T113_Init_Reg[j].init_reg, MT9T113_Init_Reg[j].init_val);
    }
    else
    {
      ASSERT(0);
    }
  }

#ifdef __MT9T113_DEBUG_TRACE__
  kal_wap_trace(MOD_ENG, TRACE_INFO, "%d register applied...", j);
#endif

  return 1;  
}
#endif

/*************************************************************************
* FUNCTION
*   MT9T113SetMirror
*
* DESCRIPTION
*   This function set the mirror to the CMOS sensor
*
* PARAMETERS
*   Mirror
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113SetMirror(kal_uint8 Mirror)
{
  /* ===== code modify body start ===== */
  switch (Mirror)
  {
  case IMAGE_SENSOR_MIRROR_NORMAL:
  	//[Default Orientation]
		CamWriteCmosSensor(0x098E, 0x4810);	// MCU_ADDRESS [CAM1_CTX_A_READ_MODE]
		CamWriteCmosSensor(0x0990, 0x046C);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x483D);	// MCU_ADDRESS [CAM1_CTX_B_READ_MODE]
		CamWriteCmosSensor(0x0990, 0x0024);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0
    break;
  case IMAGE_SENSOR_MIRROR_H:
  	//[Horizontal Mirror]
		CamWriteCmosSensor(0x098E, 0x4810);	// MCU_ADDRESS [CAM1_CTX_A_READ_MODE]
		CamWriteCmosSensor(0x0990, 0x046D);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x483D);	// MCU_ADDRESS [CAM1_CTX_B_READ_MODE]
		CamWriteCmosSensor(0x0990, 0x0025);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0
    break;
  case IMAGE_SENSOR_MIRROR_V:
  	//[Vertical Flip]
		CamWriteCmosSensor(0x098E, 0x4810);	// MCU_ADDRESS [CAM1_CTX_A_READ_MODE]
		CamWriteCmosSensor(0x0990, 0x046E);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x483D);	// MCU_ADDRESS [CAM1_CTX_B_READ_MODE]
		CamWriteCmosSensor(0x0990, 0x0026);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0
    break;
  case IMAGE_SENSOR_MIRROR_HV:
  	//[Flip and Mirror]
		CamWriteCmosSensor(0x098E, 0x4810);	// MCU_ADDRESS [CAM1_CTX_A_READ_MODE]
		CamWriteCmosSensor(0x0990, 0x046F);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x483D);	// MCU_ADDRESS [CAM1_CTX_B_READ_MODE]
		CamWriteCmosSensor(0x0990, 0x0027);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0
    break;
  }
  /* ===== code modify body end ===== */
}

/*************************************************************************
* FUNCTION
*   MT9T113WriteShutter
*
* DESCRIPTION
*   This function apply shutter to sensor
*
* PARAMETERS
*   Shutter: integration time, unit: (linelength / internal clock) s
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113WriteShutter(kal_uint32 Shutter)
{
    CamWriteCmosSensor(0x3012, Shutter);
}

/*************************************************************************
* FUNCTION
*   MT9T113ReadShutter
*
* DESCRIPTION
*   This function get shutter from sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   Shutter: integration time, unit: (linelength / internal clock) s
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 MT9T113ReadShutter(void)
{
    return CamReadCmosSensor(0x3012);
}

/*************************************************************************
* FUNCTION
*   MT9T113WriteGain
*
* DESCRIPTION
*   This function apply global gain to sensor
*
* PARAMETERS
*   Gain: base on 0x40
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113WriteGain(kal_uint32 Gain)
{
    CamWriteCmosSensor(0x3028, Gain / 8); /* global analogue gain */
}

/*************************************************************************
* FUNCTION
*   MT9T113ReadGain
*
* DESCRIPTION
*   This function get global gain from sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   Gain: base on 0x40
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 MT9T113ReadGain(void)
{
	return CamReadCmosSensor(0x3028) * 8; /* global analogue gain */
}

/*************************************************************************
* FUNCTION
*   MT9T113AeEnable
*
* DESCRIPTION
*   disable/enable AE
*
* PARAMETERS
*   Enable
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113AeEnable(kal_bool Enable)
{
}

/*************************************************************************
* FUNCTION
*   MT9T113AwbEnable
*
* DESCRIPTION
*   disable/enable awb
*
* PARAMETERS
*   Enable
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113AwbEnable(kal_bool Enable)
{
}

/*************************************************************************
* FUNCTION
*   MT9T113SetDummy
*
* DESCRIPTION
*   This function set the dummy pixels(Horizontal Blanking) & dummy lines(Vertical Blanking), it can be
*   used to adjust the frame rate or gain more time for back-end process.
*
* PARAMETERS
*   DummyPixel
*   DummyLine
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113SetDummy(kal_uint32 DummyPixel, kal_uint32 DummyLine)
{
	kal_uint32 LineLength, FrameHeight;
	kal_uint32 frame_rate;
	kal_uint32 base_shutter_50Hz,base_shutter_60Hz;

	if(KAL_TRUE == MT9T113Sensor.PvMode)
	{
		/* Not Support */
	}
	else
	{ 
		LineLength = MT9T113_FULL_PERIOD_PIXEL_NUMS + DummyPixel;
		
		CamWriteCmosSensor(0x98E, 0x4837);		//Line Length (B)
		CamWriteCmosSensor(0x990, LineLength); //		
		
		CamWriteCmosSensor(0x098E, 0x8400); 		// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006); 		// MCU_DATA_0

		{
			kal_uint16 temp=0;
			while(temp <60)
			{
				CamWriteCmosSensor(0x098E, 0x8400);   // MCU_DATA_0
				if(0==CamReadCmosSensor(0x990))
				{
				 break;
				}
				kal_sleep_task(4);//DELAY=100
				temp+=1;
			}
		}
		
		frame_rate = MT9T113Sensor.IntClk*100000*10/LineLength/(MT9T113_FULL_PERIOD_LINE_NUMS + DummyLine);
		
		base_shutter_50Hz = (frame_rate*MT9T113_FULL_PERIOD_LINE_NUMS/50+5)/2/10;;
		base_shutter_60Hz = (frame_rate*MT9T113_FULL_PERIOD_LINE_NUMS/60+5)/2/10;;
		CamWriteCmosSensor(0x98E, 0x4847);				//fd_period_50Hz (B)
		CamWriteCmosSensor(0x990, base_shutter_50Hz);	//		
		CamWriteCmosSensor(0x98E, 0x4849);				//fd_period_60Hz (B)
		CamWriteCmosSensor(0x990, base_shutter_60Hz);	//	
	}

}

/*************************************************************************
* FUNCTION
*   MT9T113SetVideoFps
*
* DESCRIPTION
*   This function calculate & fix frame rate in video mode
*
* PARAMETERS
*   Fps: target frame rate to fixed, base on MT9T113_FPS(x)
*
* RETURNS
*   Fps: real frame rate set by sensor
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 MT9T113SetVideoFps(kal_uint16 frame_rate)
{
  kal_uint32 LineLength, FrameHeight;
  kal_uint32 frame_rate_50Hz,frame_rate_60Hz;
  kal_uint32 base_shutter_50Hz,base_shutter_60Hz;

  LineLength = MT9T113Sensor.IntClk*100000*10/frame_rate/(MT9T113_PV_PERIOD_LINE_NUMS);
  frame_rate_50Hz	  = 50*2*10/frame_rate;
  frame_rate_60Hz	  = 60*2*10/frame_rate;

  base_shutter_50Hz = (frame_rate*MT9T113_PV_PERIOD_LINE_NUMS/50+5)/2/10;;
  base_shutter_60Hz = (frame_rate*MT9T113_PV_PERIOD_LINE_NUMS/60+5)/2/10;;
  CamWriteCmosSensor(0x98E, 0x481A);			  //fd_period_50Hz (A)
  CamWriteCmosSensor(0x990, base_shutter_50Hz);   //	  
  CamWriteCmosSensor(0x98E, 0x481C);			  //fd_period_60Hz (A)
  CamWriteCmosSensor(0x990, base_shutter_60Hz);   //  

  CamWriteCmosSensor(0x098E, 0x8400);		  // MCU_ADDRESS [SEQ_CMD]
  CamWriteCmosSensor(0x0990, 0x0006);		  // MCU_DATA_0
  {
	  kal_uint16 temp=0;
	  while(temp <60)
	  {
		  CamWriteCmosSensor(0x098E, 0x8400);	// MCU_DATA_0
		  if(0==CamReadCmosSensor(0x990))
		  {
		   break;
		  }
		  kal_sleep_task(4);//DELAY=100
		  temp+=1;
	  }
  }

  kal_sleep_task(100);

  CamWriteCmosSensor(0x098E, 0x6815);		  // MCU_ADDRESS [PRI_A_CONFIG_FD_MAX_FDZONE_50HZ]
  CamWriteCmosSensor(0x0990, frame_rate_50Hz);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098E, 0x6817);		  // MCU_ADDRESS [PRI_A_CONFIG_FD_MAX_FDZONE_60HZ]
  CamWriteCmosSensor(0x0990, frame_rate_60Hz);	  // MCU_DATA_0

  CamWriteCmosSensor(0x98E, 0x480A);	  //Line Length (A)
  CamWriteCmosSensor(0x990, LineLength); //	  

  CamWriteCmosSensor(0x098E, 0x8400);		  // MCU_ADDRESS [SEQ_CMD]
  CamWriteCmosSensor(0x0990, 0x0006);		  // MCU_DATA_0
  {
	  kal_uint16 temp=0;
	  while(temp <60)
	  {
		  CamWriteCmosSensor(0x098E, 0x8400);	// MCU_DATA_0
		  if(0==CamReadCmosSensor(0x990))
		  {
		   break;
		  }
		  kal_sleep_task(4);//DELAY=100
		  temp+=1;
	  }
  }

  return MT9T113Sensor.IntClk * 100000 * MT9T113_FPS(1) / (LineLength * FrameHeight);
}

/*************************************************************************
* FUNCTION
*   MT9T113NightMode
*
* DESCRIPTION
*   This function set night mode to sensor.
*
* PARAMETERS
*   Enable
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113NightMode(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In)
{
	if (KAL_TRUE == In->NightMode) 		/* Night Mode */
	{
		CamWriteCmosSensor(0x098E, 0x682F);	// MCU_ADDRESS
		CamWriteCmosSensor(0x0990, 0x0105);	// MCU_DATA_0// gain

		if (CAL_SCENARIO_VIDEO == Id)	/* Video */
		{
			MT9T113Sensor.VideoFps = MT9T113SetVideoFps(In->MaxVideoFrameRate);
		}
		else 										/* Camera */
		{
			//[Night mode  5-29.1fps]
			CamWriteCmosSensor(0x098E, 0x6815);	  // MCU_ADDRESS [PRI_A_CONFIG_FD_MAX_FDZONE_50HZ]
			CamWriteCmosSensor(0x0990, 0x0014);	  // MCU_DATA_0
			CamWriteCmosSensor(0x098E, 0x6817);	  // MCU_ADDRESS [PRI_A_CONFIG_FD_MAX_FDZONE_60HZ]
			CamWriteCmosSensor(0x0990, 0x0018);	  // MCU_DATA_0
		}      
	}
	else  				/* Normal Mode */
	{
		CamWriteCmosSensor(0x098E, 0x682F);	// MCU_ADDRESS
		CamWriteCmosSensor(0x0990, 0x0120);	// MCU_DATA_0// gain

		if (CAL_SCENARIO_VIDEO == Id)	/* Video */
		{
			MT9T113Sensor.VideoFps = MT9T113SetVideoFps(In->MaxVideoFrameRate);
		}
		else										/* Camera */
		{
			//[Normal mode 10-29.1fps]
			CamWriteCmosSensor(0x098E, 0x6815);	  // MCU_ADDRESS [PRI_A_CONFIG_FD_MAX_FDZONE_50HZ]
			CamWriteCmosSensor(0x0990, 0x000A);	  // MCU_DATA_0
			CamWriteCmosSensor(0x098E, 0x6817);	  // MCU_ADDRESS [PRI_A_CONFIG_FD_MAX_FDZONE_60HZ]
			CamWriteCmosSensor(0x0990, 0x000C);	  // MCU_DATA_0
		}
	}
}

/*************************************************************************
* FUNCTION
*   MT9T113Ev
*
* DESCRIPTION
*   Exposure setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Exposure = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    /* ===== code modify body start ===== */
    Exposure->IsSupport = KAL_TRUE;
    Exposure->ItemCount = 10;
    Exposure->SupportItem[0] = CAM_EV_NEG_4_3;
    Exposure->SupportItem[1] = CAM_EV_NEG_3_3;
    Exposure->SupportItem[2] = CAM_EV_NEG_2_3;
    Exposure->SupportItem[3] = CAM_EV_NEG_1_3;
    Exposure->SupportItem[4] = CAM_EV_ZERO;
    Exposure->SupportItem[5] = CAM_EV_POS_1_3;
    Exposure->SupportItem[6] = CAM_EV_POS_2_3;
    Exposure->SupportItem[7] = CAM_EV_POS_3_3;
    Exposure->SupportItem[8] = CAM_EV_POS_4_3;
    Exposure->SupportItem[9] = CAM_EV_NIGHT_SHOT;
    /* ===== code modify body end ===== */
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    /* ===== code modify body start ===== */
    kal_uint8 AeBaseTarget = 67;
    
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3:
		//[Manual EV-4]
			  CamWriteCmosSensor(0x337E, 0x8000);	// Y_RGB_OFFSET
			  break;
    case CAM_EV_NEG_3_3:
		//[Manual EV-3]
			  CamWriteCmosSensor(0x337E, 0xAC00);	  // Y_RGB_OFFSET
			  break;
    case CAM_EV_NEG_2_3:
		//[Manual EV-2]
			  CamWriteCmosSensor(0x337E, 0xCC00);  // Y_RGB_OFFSET
			  break;
    case CAM_EV_NEG_1_3:
		//[Manual EV-1]
			  CamWriteCmosSensor(0x337E, 0xEA00);  // Y_RGB_OFFSET
			  break;
    case CAM_EV_ZERO:
		//[Manual EV0]
			  CamWriteCmosSensor(0x337E, 0x0800);  // Y_RGB_OFFSET
			  break;
    case CAM_EV_POS_1_3:
		//[Manual EV+1]
			  CamWriteCmosSensor(0x337E, 0x1800);  // Y_RGB_OFFSET 0x2000-0x800
			  break;
    case CAM_EV_POS_2_3:
		//[Manual EV+2]
			  CamWriteCmosSensor(0x337E, 0x3800);  // Y_RGB_OFFSET 0x4000 - 0x400
			  break;
    case CAM_EV_POS_3_3://[Manual EV+3]
			  CamWriteCmosSensor(0x337E, 0x5C00);  // Y_RGB_OFFSET 0x6000 - 0x200
			  break;
    case CAM_EV_POS_4_3:
		//[Manual EV+4]
			  CamWriteCmosSensor(0x337E, 0x7E00);  // Y_RGB_OFFSET 0x7000 + 600
			  break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    /* ===== code modify body end ===== */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113Contrast
*
* DESCRIPTION
*   Contrast setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported contrast enum here
        Contrast->IsSupport = KAL_TRUE;
        Contrast->ItemCount = 3;
        Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
        Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
        Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust contrast here
        //kal_uint8 Data;;

        switch (In->FeatureSetValue)
        {
        case CAM_CONTRAST_HIGH:
            CamWriteCmosSensor(0x098E, 0xBC06); //  LL_GAMMA_CURVE_SELECTOR
            CamWriteCmosSensor(0x0990, 0x0002);

    		CamWriteCmosSensor(0x098E, 0xBC09);
    		CamWriteCmosSensor8(0xBC09, 0x00); 	// LL_GAMMA_CONTRAST_CURVE_0
    		CamWriteCmosSensor8(0xBC0A, 0x06); 	// LL_GAMMA_CONTRAST_CURVE_1
    		CamWriteCmosSensor8(0xBC0B, 0x12); 	// LL_GAMMA_CONTRAST_CURVE_2
    		CamWriteCmosSensor8(0xBC0C, 0x27); 	// LL_GAMMA_CONTRAST_CURVE_3
    		CamWriteCmosSensor8(0xBC0D, 0x48); 	// LL_GAMMA_CONTRAST_CURVE_4
    		CamWriteCmosSensor8(0xBC0E, 0x69); 	// LL_GAMMA_CONTRAST_CURVE_5
    		CamWriteCmosSensor8(0xBC0F, 0x8A); 	// LL_GAMMA_CONTRAST_CURVE_6
    		CamWriteCmosSensor8(0xBC10, 0xA4); 	// LL_GAMMA_CONTRAST_CURVE_7
    		CamWriteCmosSensor8(0xBC11, 0xB7); 	// LL_GAMMA_CONTRAST_CURVE_8
    		CamWriteCmosSensor8(0xBC12, 0xC6); 	// LL_GAMMA_CONTRAST_CURVE_9
    		CamWriteCmosSensor8(0xBC13, 0xD1); 	// LL_GAMMA_CONTRAST_CURVE_10
    		CamWriteCmosSensor8(0xBC14, 0xD8); 	// LL_GAMMA_CONTRAST_CURVE_11
    		CamWriteCmosSensor8(0xBC15, 0xE2); 	// LL_GAMMA_CONTRAST_CURVE_12
    		CamWriteCmosSensor8(0xBC16, 0xE9); 	// LL_GAMMA_CONTRAST_CURVE_13
    		CamWriteCmosSensor8(0xBC17, 0xEE); 	// LL_GAMMA_CONTRAST_CURVE_14
    		CamWriteCmosSensor8(0xBC18, 0xF3); 	// LL_GAMMA_CONTRAST_CURVE_15
    		CamWriteCmosSensor8(0xBC19, 0xF7); 	// LL_GAMMA_CONTRAST_CURVE_16
    		CamWriteCmosSensor8(0xBC1A, 0xFB); 	// LL_GAMMA_CONTRAST_CURVE_17
    		CamWriteCmosSensor8(0xBC1B, 0xFF); 	// LL_GAMMA_CONTRAST_CURVE_18
	        CamWriteCmosSensor8(0x8400, 0x05); 	// SEQ_CMD
            break;
        case CAM_CONTRAST_MEDIUM:
            CamWriteCmosSensor(0x098E, 0xBC06); //  LL_GAMMA_CURVE_SELECTOR
            CamWriteCmosSensor(0x0990, 0x0002);

    		CamWriteCmosSensor(0x098E, 0xBC09);
    		CamWriteCmosSensor8(0xBC09, 0x00); 	// LL_GAMMA_CONTRAST_CURVE_0
    		CamWriteCmosSensor8(0xBC0A, 0x08); 	// LL_GAMMA_CONTRAST_CURVE_1
    		CamWriteCmosSensor8(0xBC0B, 0x19); 	// LL_GAMMA_CONTRAST_CURVE_2
    		CamWriteCmosSensor8(0xBC0C, 0x31); 	// LL_GAMMA_CONTRAST_CURVE_3
    		CamWriteCmosSensor8(0xBC0D, 0x52); 	// LL_GAMMA_CONTRAST_CURVE_4
    		CamWriteCmosSensor8(0xBC0E, 0x6E); 	// LL_GAMMA_CONTRAST_CURVE_5
    		CamWriteCmosSensor8(0xBC0F, 0x87); 	// LL_GAMMA_CONTRAST_CURVE_6
    		CamWriteCmosSensor8(0xBC10, 0x9C); 	// LL_GAMMA_CONTRAST_CURVE_7
    		CamWriteCmosSensor8(0xBC11, 0xAD); 	// LL_GAMMA_CONTRAST_CURVE_8
    		CamWriteCmosSensor8(0xBC12, 0xBB); 	// LL_GAMMA_CONTRAST_CURVE_9
    		CamWriteCmosSensor8(0xBC13, 0xC6); 	// LL_GAMMA_CONTRAST_CURVE_10
    		CamWriteCmosSensor8(0xBC14, 0xD1); 	// LL_GAMMA_CONTRAST_CURVE_11
    		CamWriteCmosSensor8(0xBC15, 0xD9); 	// LL_GAMMA_CONTRAST_CURVE_12
    		CamWriteCmosSensor8(0xBC16, 0xE1); 	// LL_GAMMA_CONTRAST_CURVE_13
    		CamWriteCmosSensor8(0xBC17, 0xE8); 	// LL_GAMMA_CONTRAST_CURVE_14
    		CamWriteCmosSensor8(0xBC18, 0xEF); 	// LL_GAMMA_CONTRAST_CURVE_15
    		CamWriteCmosSensor8(0xBC19, 0xF5); 	// LL_GAMMA_CONTRAST_CURVE_16
    		CamWriteCmosSensor8(0xBC1A, 0xFA); 	// LL_GAMMA_CONTRAST_CURVE_17
    		CamWriteCmosSensor8(0xBC1B, 0xFF); 	// LL_GAMMA_CONTRAST_CURVE_18
	        CamWriteCmosSensor8(0x8400, 0x05); 	// SEQ_CMD
            break;
        case CAM_CONTRAST_LOW:
            CamWriteCmosSensor(0x098E, 0xBC06); //  LL_GAMMA_CURVE_SELECTOR
            CamWriteCmosSensor(0x0990, 0x0002);

    		CamWriteCmosSensor(0x098E, 0xBC09);
    		CamWriteCmosSensor8(0xBC09, 0x00); 	// LL_GAMMA_CONTRAST_CURVE_0
    		CamWriteCmosSensor8(0xBC0A, 0x0C); 	// LL_GAMMA_CONTRAST_CURVE_1
    		CamWriteCmosSensor8(0xBC0B, 0x22); 	// LL_GAMMA_CONTRAST_CURVE_2
    		CamWriteCmosSensor8(0xBC0C, 0x3E); 	// LL_GAMMA_CONTRAST_CURVE_3
    		CamWriteCmosSensor8(0xBC0D, 0x5D); 	// LL_GAMMA_CONTRAST_CURVE_4
    		CamWriteCmosSensor8(0xBC0E, 0x73); 	// LL_GAMMA_CONTRAST_CURVE_5
    		CamWriteCmosSensor8(0xBC0F, 0x85); 	// LL_GAMMA_CONTRAST_CURVE_6
    		CamWriteCmosSensor8(0xBC10, 0x94); 	// LL_GAMMA_CONTRAST_CURVE_7
    		CamWriteCmosSensor8(0xBC11, 0xA2); 	// LL_GAMMA_CONTRAST_CURVE_8
    		CamWriteCmosSensor8(0xBC12, 0xAE); 	// LL_GAMMA_CONTRAST_CURVE_9
    		CamWriteCmosSensor8(0xBC13, 0xB9); 	// LL_GAMMA_CONTRAST_CURVE_10
    		CamWriteCmosSensor8(0xBC14, 0xC3); 	// LL_GAMMA_CONTRAST_CURVE_11
    		CamWriteCmosSensor8(0xBC15, 0xCD); 	// LL_GAMMA_CONTRAST_CURVE_12
    		CamWriteCmosSensor8(0xBC16, 0xD7); 	// LL_GAMMA_CONTRAST_CURVE_13
    		CamWriteCmosSensor8(0xBC17, 0xDF); 	// LL_GAMMA_CONTRAST_CURVE_14
    		CamWriteCmosSensor8(0xBC18, 0xE8); 	// LL_GAMMA_CONTRAST_CURVE_15
    		CamWriteCmosSensor8(0xBC19, 0xF0); 	// LL_GAMMA_CONTRAST_CURVE_16
    		CamWriteCmosSensor8(0xBC1A, 0xF8); 	// LL_GAMMA_CONTRAST_CURVE_17
    		CamWriteCmosSensor8(0xBC1B, 0xFF); 	// LL_GAMMA_CONTRAST_CURVE_18
	        CamWriteCmosSensor8(0x8400, 0x05); 	// SEQ_CMD
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113Saturation
*
* DESCRIPTION
*   Saturation setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113Saturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Saturation = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported saturation enum here
        Saturation->IsSupport = KAL_TRUE;
        Saturation->ItemCount = 3;
        Saturation->SupportItem[0] = CAM_SATURATION_HIGH;
        Saturation->SupportItem[1] = CAM_SATURATION_MEDIUM;
        Saturation->SupportItem[2] = CAM_SATURATION_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust saturation here
        switch (In->FeatureSetValue)
        {
        case CAM_SATURATION_HIGH:
            CamWriteCmosSensor(0x098E, 0xE876);
	        CamWriteCmosSensor(0x0990, 0x00F0);
            break;
        case CAM_SATURATION_MEDIUM:
            CamWriteCmosSensor(0x098E, 0xE876);
	        CamWriteCmosSensor(0x0990, 0x00D0);
            break;
        case CAM_SATURATION_LOW:
            CamWriteCmosSensor(0x098E, 0xE876);
	        CamWriteCmosSensor(0x0990, 0x00A0);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113Sharpness
*
* DESCRIPTION
*   Sharpness setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113Sharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Sharpness = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported sharpness enum here
        Sharpness->IsSupport = KAL_TRUE;
        Sharpness->ItemCount = 3;
        Sharpness->SupportItem[0] = CAM_SHARPNESS_HIGH;
        Sharpness->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
        Sharpness->SupportItem[2] = CAM_SHARPNESS_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust sharpness here
        switch (In->FeatureSetValue)
        {
        case CAM_SHARPNESS_HIGH:
            CamWriteCmosSensor(0x326C, 0x190A);
            break;
        case CAM_SHARPNESS_MEDIUM:
            CamWriteCmosSensor(0x326C, 0x170A);
            break;
        case CAM_SHARPNESS_LOW:
            CamWriteCmosSensor(0x326C, 0x150A);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113Wb
*
* DESCRIPTION
*   Wb setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Wb = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    /* ===== code modify body start ===== */
    Wb->IsSupport = KAL_TRUE;
    Wb->ItemCount = 6;
    Wb->SupportItem[0] = CAM_WB_AUTO;
    Wb->SupportItem[1] = CAM_WB_CLOUD;
    Wb->SupportItem[2] = CAM_WB_DAYLIGHT;
    Wb->SupportItem[3] = CAM_WB_INCANDESCENCE;
    Wb->SupportItem[4] = CAM_WB_FLUORESCENT;
    Wb->SupportItem[5] = CAM_WB_TUNGSTEN;
    /* ===== code modify body end ===== */
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    /* ===== code modify body start ===== */
    kal_uint8 AwbCcmPosition;
    
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO:
      //[Auto WB]
		CamWriteCmosSensor(0x098E, 0x6848 ); // MCU_ADDRESS [PRI_A_CONFIG_AWB_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x003F ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6865 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x801F ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6867 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x12F7 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6881 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x000b ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6883 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x000B ); // MCU_DATA_0
#if 1
		CamWriteCmosSensor(0x098E, 0x8400 ); // MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006 ); // MCU_DATA_0

		{
			kal_uint16 temp=0;
			while(temp <60)
			{
				CamWriteCmosSensor(0x098E, 0x8400);	  // MCU_DATA_0
				if(0==CamReadCmosSensor(0x990))
				{
				 break;
				}
				kal_sleep_task(4);//DELAY=100
				temp+=1;
			}
		}
#endif
      return MM_ERROR_NONE;
    case CAM_WB_CLOUD:
		//[Manual WB-Cloudy]
		CamWriteCmosSensor(0x098E, 0x6848 ); // MCU_ADDRESS [PRI_A_CONFIG_AWB_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6865 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6867 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6881 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6883 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400 ); // MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006 ); // MCU_DATA_0
		
		CamWriteCmosSensor(0x098E, 0xAC3B ); // MCU_ADDRESS [AWB_R_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0034 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xAC3C ); // MCU_ADDRESS [AWB_B_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0054 ); // MCU_DATA_0
		break;
    case CAM_WB_DAYLIGHT:
		//[Manual WB-Daylight]
		CamWriteCmosSensor(0x098E, 0x6848 ); // MCU_ADDRESS [PRI_A_CONFIG_AWB_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6865 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6867 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6881 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6883 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400 ); // MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006 ); // MCU_DATA_0
		
		CamWriteCmosSensor(0x098E, 0xAC3B ); // MCU_ADDRESS [AWB_R_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0039 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xAC3C ); // MCU_ADDRESS [AWB_B_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0054 ); // MCU_DATA_0
		break;
    case CAM_WB_INCANDESCENCE:
		//[Manual WB-A28]
		CamWriteCmosSensor(0x098E, 0x6848 ); // MCU_ADDRESS [PRI_A_CONFIG_AWB_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6865 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6867 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6881 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6883 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400 ); // MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006 ); // MCU_DATA_0
		
		CamWriteCmosSensor(0x098E, 0xAC3B ); // MCU_ADDRESS [AWB_R_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0058 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xAC3C ); // MCU_ADDRESS [AWB_B_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0028 ); // MCU_DATA_0
		break;
    case CAM_WB_FLUORESCENT:
		//[Manual WB-CWF]
		CamWriteCmosSensor(0x098E, 0x6848 ); // MCU_ADDRESS [PRI_A_CONFIG_AWB_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6865 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6867 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6881 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6883 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400 ); // MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006 ); // MCU_DATA_0
		
		CamWriteCmosSensor(0x098E, 0xAC3B ); // MCU_ADDRESS [AWB_R_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0044 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xAC3C ); // MCU_ADDRESS [AWB_B_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0031 ); // MCU_DATA_0
		break;
    case CAM_WB_TUNGSTEN:
		//[WB_TUNGSTEN]
		CamWriteCmosSensor(0x098E, 0x6848 ); // MCU_ADDRESS [PRI_A_CONFIG_AWB_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6865 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6867 ); // MCU_ADDRESS [PRI_A_CONFIG_STAT_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0000 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6881 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_ENTER]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x6883 ); // MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_ALGO_RUN]
		CamWriteCmosSensor(0x0990, 0x0008 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400 ); // MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006 ); // MCU_DATA_0
		
		CamWriteCmosSensor(0x098E, 0xAC3B ); // MCU_ADDRESS [AWB_R_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0058 ); // MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xAC3C ); // MCU_ADDRESS [AWB_B_RATIO_PRE_AWB]
		CamWriteCmosSensor(0x0990, 0x0023 ); // MCU_DATA_0
		break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }

    /* ===== code modify body end ===== */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113Effect
*
* DESCRIPTION
*   Effect setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Effect = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    /* ===== code modify body start ===== */
    Effect->IsSupport = KAL_TRUE;
    Effect->ItemCount = 6;
    Effect->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    Effect->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    Effect->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    Effect->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    Effect->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    Effect->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    /* ===== code modify body end ===== */
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    /* ===== code modify body start ===== */
    kal_uint8 SpecEffects;
    
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
		//[Special Effect-OFF]
		CamWriteCmosSensor(0x098E, 0xE887);	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC87);	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0

		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0
#if 1
		{
			kal_uint16 temp=0;
			while(temp <60)
			{
				CamWriteCmosSensor(0x098E, 0x8400);	  // MCU_DATA_0
				if(0==CamReadCmosSensor(0x990))
				{
				 break;
				}
				kal_sleep_task(4);//DELAY=100
				temp+=1;
			}
		}
#endif
		break;
    case CAM_EFFECT_ENC_GRAYSCALE:
		//[Special Effect-Black/White]
		CamWriteCmosSensor(0x098E, 0xE887);	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC87);	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0	
		break;
    case CAM_EFFECT_ENC_SEPIA:
		//[Special Effect-Sepia]
		CamWriteCmosSensor(0x098E, 0xE887);	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC87);	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0


		CamWriteCmosSensor(0x098E, 0xE889); 	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SEPIA_CR]
		CamWriteCmosSensor(0x0990, 0x001D); 	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC89); 	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SEPIA_CR]
		CamWriteCmosSensor(0x0990, 0x001D); 	// MCU_DATA_0
		
		CamWriteCmosSensor(0x098E, 0xE88A); 	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SEPIA_CB]
		CamWriteCmosSensor(0x0990, 0x00D8); 	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC8A); 	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SEPIA_CB]
		CamWriteCmosSensor(0x0990, 0x00D8); 	// MCU_DATA_0


		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
      //[Special Effect-green]
		CamWriteCmosSensor(0x098E, 0xE887);	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC87);	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
		
		CamWriteCmosSensor(0x098E, 0xE889); 	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SEPIA_CR]
		CamWriteCmosSensor(0x0990, 0x00D8); 	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC89); 	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SEPIA_CR]
		CamWriteCmosSensor(0x0990, 0x00D8); 	// MCU_DATA_0
		
		
		CamWriteCmosSensor(0x098E, 0xE88A); 	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SEPIA_CB]
		CamWriteCmosSensor(0x0990, 0x00EC); 	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC8A); 	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SEPIA_CB]
		CamWriteCmosSensor(0x0990, 0x00EC); 	// MCU_DATA_0
		
		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0	
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
		//[Special Effect-Aqua]
		CamWriteCmosSensor(0x098E, 0xE887);	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC87);	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xE889);	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SEPIA_CR]
		CamWriteCmosSensor(0x0990, 0x00E2);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xE88A);	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SEPIA_CB]
		CamWriteCmosSensor(0x0990, 0x0030);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC89);	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SEPIA_CR]
		CamWriteCmosSensor(0x0990, 0x00E2);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC8A);	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SEPIA_CB]
		CamWriteCmosSensor(0x0990, 0x0030);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0	
      break;
    case CAM_EFFECT_ENC_COLORINV:
		//[Special Effect-Negative]
		CamWriteCmosSensor(0x098E, 0xE887);	// MCU_ADDRESS [PRI_A_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0003);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0xEC87);	// MCU_ADDRESS [PRI_B_CONFIG_SYSCTRL_SELECT_FX]
		CamWriteCmosSensor(0x0990, 0x0003);	// MCU_DATA_0
		CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
		CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0
		break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    /* ===== code modify body end ===== */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113StillCaptureSize
*
* DESCRIPTION
*   This function get capture size
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM MT9T113StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
	
    CapSize->IsSupport = KAL_TRUE;
    /* ===== code modify body start ===== */
    CapSize->ItemCount = 5;
    CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
    CapSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
    CapSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
	CapSize->SupportItem[4] = CAM_IMAGE_SIZE_3M;
    /* ===== code modify body end ===== */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113Banding
*
* DESCRIPTION
*   This function get banding setting
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Banding->IsSupport = KAL_TRUE;
    Banding->ItemCount = 2;
    Banding->SupportItem[0] = CAM_BANDING_50HZ;
    Banding->SupportItem[1] = CAM_BANDING_60HZ;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    /* ===== code modify body start ===== */
    switch (In->FeatureSetValue)
	  {
		  case CAM_BANDING_50HZ:
			  //[50Hz]
			  CamWriteCmosSensor(0x098E, 0x2003);  // MCU_ADDRESS [FD_ALGO]
			  CamWriteCmosSensor(0x0990, 0x0002);  // MCU_DATA_0
			  CamWriteCmosSensor(0x098E, 0xA005);  // MCU_ADDRESS [FD_FDPERIOD_SELECT]
			  CamWriteCmosSensor(0x0990, 0x0001);  // MCU_DATA_0
			  break;
		  case CAM_BANDING_60HZ:
			  //[60Hz]
			  CamWriteCmosSensor(0x098E, 0x2003);  // MCU_ADDRESS [FD_ALGO]
			  CamWriteCmosSensor(0x0990, 0x0002);  // MCU_DATA_0
			  CamWriteCmosSensor(0x098E, 0xA005);  // MCU_ADDRESS [FD_FDPERIOD_SELECT]
			  CamWriteCmosSensor(0x0990, 0x0000);  // MCU_DATA_0
			  break;
		  default:
			  return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT; 
	  }
    /* ===== code modify body end ===== */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113SceneMode
*
* DESCRIPTION
*   This function get/set scene mode of sensor.
*
* PARAMETERS
*   IsCam: camera scene mode or not
*   In, Out
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT SceneMode = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    
    if (IsCam)
    {
		SceneMode->IsSupport = KAL_TRUE;
		SceneMode->ItemCount = 2;
		SceneMode->SupportItem[0] = CAM_AUTO_DSC;
		SceneMode->SupportItem[1] = CAM_NIGHTSCENE;
    }
    else
    {
		SceneMode->IsSupport = KAL_TRUE;
		SceneMode->ItemCount = 2;
		SceneMode->SupportItem[0] = CAM_VIDEO_AUTO;
		SceneMode->SupportItem[1] = CAM_VIDEO_NIGHT;
    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*   MT9T113InitialSetting
*
* DESCRIPTION
*   This function initialize the registers of CMOS sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113InitialSetting(void)
{
  /* ===== code modify body start ===== */
  	CamWriteCmosSensor(0x0014, 0x904B); 	// PLL_CONTROL
	CamWriteCmosSensor(0x0014, 0x9049); 	 // PLL_CONTROL
	CamWriteCmosSensor(0x0010, 0x0118);	//PLL Dividers = 280
	CamWriteCmosSensor(0x0012, 0x0070);	//PLL P Dividers = 112
	CamWriteCmosSensor(0x002A, 0x76B7);	//PLL P Dividers 4-5-6 = 30391
	CamWriteCmosSensor(0x0014, 0x104B); 	// PLL_CONTROL
	CamWriteCmosSensor(0x0014, 0x904A); 	// PLL_CONTROL

	CamWriteCmosSensor(0x0018, 0x402E);	//Standby:Default = 16430
	//POLL_REG=0x0018,0x4000,==1,DELAY=10,TIMEOUT=100   // Wait for FW initialization complete
	CamWriteCmosSensor(0x0022, 0x0140);	//Reference clock count for 20 us = 320
	CamWriteCmosSensor(0x001E, 0x770);	//Pad Slew Rate = 1911
	CamWriteCmosSensor(0x3B84, 0x01B9);	//I2C Master Clock Divider = 441
	kal_sleep_task(10);//DELAY=30
	//LOAD the FW patches and recommended settings here!

	CamWriteCmosSensor(0x98E, 0x4800);	//Row Start (A)
	CamWriteCmosSensor(0x990, 0x0010);	//		= 16
	CamWriteCmosSensor(0x98E, 0x4802);	//Column Start (A)
	CamWriteCmosSensor(0x990, 0x0010);	//		= 16
	CamWriteCmosSensor(0x98E, 0x4804);	//Row End (A)
	CamWriteCmosSensor(0x990, 0x062D);	//		= 1581
	CamWriteCmosSensor(0x98E, 0x4806);	//Column End (A)
	CamWriteCmosSensor(0x990, 0x082D);	//		= 2093
	CamWriteCmosSensor(0x98E, 0x4808);	//Base Frame Lines (A)
	CamWriteCmosSensor(0x990, 0x0359);	//		= 857
	CamWriteCmosSensor(0x98E, 0x480A);	//Line Length (A)
	CamWriteCmosSensor(0x990, 0x0BD9);	//		= 3033
	CamWriteCmosSensor(0x98E, 0x480C);	//Fine Correction (A)
	CamWriteCmosSensor(0x990, 0x0399);	//		= 921
	CamWriteCmosSensor(0x98E, 0x480E);	//Row Speed (A)
	CamWriteCmosSensor(0x990, 0x0111);	//		= 273
	CamWriteCmosSensor(0x98E, 0x4810);	//Read Mode (A)
	CamWriteCmosSensor(0x990, 0x046C);	//		= 1132
	CamWriteCmosSensor(0x98E, 0x4812);	//Fine IT Min (A)
	CamWriteCmosSensor(0x990, 0x0510);	//		= 1296
	CamWriteCmosSensor(0x98E, 0x4814);	//Fine IT Max Margin (A)
	CamWriteCmosSensor(0x990, 0x01BA);	//		= 442
	CamWriteCmosSensor(0x98E, 0x482D);	//Row Start (B)
	CamWriteCmosSensor(0x990, 0x0018);	//		= 24
	CamWriteCmosSensor(0x98E, 0x482F);	//Column Start (B)
	CamWriteCmosSensor(0x990, 0x0018);	//		= 24
	CamWriteCmosSensor(0x98E, 0x4831);	//Row End (B)
	CamWriteCmosSensor(0x990, 0x0627);	//		= 1575
	CamWriteCmosSensor(0x98E, 0x4833);	//Column End (B)
	CamWriteCmosSensor(0x990, 0x0827);	//		= 2087
	CamWriteCmosSensor(0x98E, 0x4835);	//Base Frame Lines (B)
	CamWriteCmosSensor(0x990, 0x065D);	//		= 1629
	CamWriteCmosSensor(0x98E, 0x4837);	//Line Length (B)
	CamWriteCmosSensor(0x990, 0x1020);	//		= 4128
	CamWriteCmosSensor(0x98E, 0x4839);	//Fine Correction (B)
	CamWriteCmosSensor(0x990, 0x019F);	//		= 415
	CamWriteCmosSensor(0x98E, 0x483B);	//Row Speed (B)
	CamWriteCmosSensor(0x990, 0x0111);	//		= 273
	CamWriteCmosSensor(0x98E, 0x483D);	//Read Mode (B)
	CamWriteCmosSensor(0x990, 0x0024);	//		= 36
	CamWriteCmosSensor(0x98E, 0x483F);	//Fine IT Min (B)
	CamWriteCmosSensor(0x990, 0x0266);	//		= 614
	CamWriteCmosSensor(0x98E, 0x4841);	//Fine IT Max Margin (B)
	CamWriteCmosSensor(0x990, 0x010A);	//		= 266
	CamWriteCmosSensor(0x98E, 0xB81A);	//fd_zone_height
	CamWriteCmosSensor(0x990, 0x06); //		= 6
	CamWriteCmosSensor(0x98E, 0x481A);	//fd_period_50Hz (A)
	CamWriteCmosSensor(0x990, 0x0101);	//		= 257
	CamWriteCmosSensor(0x98E, 0x481C);	//fd_period_60Hz (A)
	CamWriteCmosSensor(0x990, 0x00D6);	//		= 214
	CamWriteCmosSensor(0x98E, 0xC81E);	//fd_search_f1_50hz (A)
	CamWriteCmosSensor(0x990, 0x22); //		= 34
	CamWriteCmosSensor(0x98E, 0xC81F);	//fd_search_f2_50hz (A)
	CamWriteCmosSensor(0x990, 0x24); //		= 36
	CamWriteCmosSensor(0x98E, 0xC820);	//fd_search_f1_60hz (A)
	CamWriteCmosSensor(0x990, 0x29); //		= 41
	CamWriteCmosSensor(0x98E, 0xC821);	//fd_search_f2_60hz (A)
	CamWriteCmosSensor(0x990, 0x2B); //		= 43
	CamWriteCmosSensor(0x98E, 0x4847);	//fd_period_50Hz (B)
	CamWriteCmosSensor(0x990, 0x00BD);	//		= 189
	CamWriteCmosSensor(0x98E, 0x4849);	//fd_period_60Hz (B)
	CamWriteCmosSensor(0x990, 0x009D);	//		= 157
	CamWriteCmosSensor(0x98E, 0xC84B);	//fd_search_f1_50hz (B)
	CamWriteCmosSensor(0x990, 0x19); //		= 25
	CamWriteCmosSensor(0x98E, 0xC84C);	//fd_search_f2_50hz (B)
	CamWriteCmosSensor(0x990, 0x1B); //		= 27
	CamWriteCmosSensor(0x98E, 0xC84D);	//fd_search_f1_60hz (B)
	CamWriteCmosSensor(0x990, 0x1E); //		= 30
	CamWriteCmosSensor(0x98E, 0xC84E);	//fd_search_f2_60hz (B)
	CamWriteCmosSensor(0x990, 0x20); //		= 32
	CamWriteCmosSensor(0x98E, 0x6800);	//Output Width (A)
	CamWriteCmosSensor(0x990, 0x0400);	//		= 1024
	CamWriteCmosSensor(0x98E, 0x6802);	//Output Height (A)
	CamWriteCmosSensor(0x990, 0x0300);	//		= 768
	CamWriteCmosSensor(0x98E, 0x6804);	//FOV Width (A)
	CamWriteCmosSensor(0x990, 0x0400);	//		= 1024
	CamWriteCmosSensor(0x98E, 0x6806);	//FOV Height (A)
	CamWriteCmosSensor(0x990, 0x0300);	//		= 768
	CamWriteCmosSensor(0x98E, 0xE892);	//JPEG Mode (A)
	CamWriteCmosSensor(0x990, 0x00); //		= 0
	CamWriteCmosSensor(0x98E, 0x6C00);	//Output Width (B)
	CamWriteCmosSensor(0x990, 0x0800);	//		= 2048
	CamWriteCmosSensor(0x98E, 0x6C02);	//Output Height (B)
	CamWriteCmosSensor(0x990, 0x0600);	//		= 1536
	CamWriteCmosSensor(0x98E, 0x6C04);	//FOV Width (B)
	CamWriteCmosSensor(0x990, 0x0800);	//		= 2048
	CamWriteCmosSensor(0x98E, 0x6C06);	//FOV Height (B)
	CamWriteCmosSensor(0x990, 0x0600);	//		= 1536
	CamWriteCmosSensor(0x98E, 0xEC92);	//JPEG Mode (B)
	CamWriteCmosSensor(0x990, 0x00); //		= 0

	//kal_sleep_task(28);//DELAY=100
	CamWriteCmosSensor(0x3172, 0x0033);	// ANALOG_CONTROL2
	
	//TX
	CamWriteCmosSensor(0x3C86, 0x00E1);	// OB_PCLK1_CONFIG
	CamWriteCmosSensor(0x3C20, 0x0000);	// TX_SS_CONTROL
	
	
	// K46A_REV03_PATCH01_REV1
	CamWriteCmosSensor(0x0982, 0x0000);	// ACCESS_CTL_STAT
	CamWriteCmosSensor(0x098A, 0x0A80);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x3C3C);
	CamWriteCmosSensor(0x0992, 0xCE05);
	CamWriteCmosSensor(0x0994, 0x1F1F);
	CamWriteCmosSensor(0x0996, 0x0204);
	CamWriteCmosSensor(0x0998, 0x0CCC);
	CamWriteCmosSensor(0x099A, 0x33D4);
	CamWriteCmosSensor(0x099C, 0x30ED);
	CamWriteCmosSensor(0x099E, 0x00FC);
	CamWriteCmosSensor(0x098A, 0x0A90);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x0590);
	CamWriteCmosSensor(0x0992, 0xBDA8);
	CamWriteCmosSensor(0x0994, 0x93CE);
	CamWriteCmosSensor(0x0996, 0x051F);
	CamWriteCmosSensor(0x0998, 0x1F02);
	CamWriteCmosSensor(0x099A, 0x0110);
	CamWriteCmosSensor(0x099C, 0xCC33);
	CamWriteCmosSensor(0x099E, 0xD830);
	CamWriteCmosSensor(0x098A, 0x0AA0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0xED02);
	CamWriteCmosSensor(0x0992, 0xCC05);
	CamWriteCmosSensor(0x0994, 0xB8ED);
	CamWriteCmosSensor(0x0996, 0x00C6);
	CamWriteCmosSensor(0x0998, 0x06BD);
	CamWriteCmosSensor(0x099A, 0xA8B1);
	CamWriteCmosSensor(0x099C, 0xCE05);
	CamWriteCmosSensor(0x099E, 0x1F1F);
	CamWriteCmosSensor(0x098A, 0x0AB0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x0208);
	CamWriteCmosSensor(0x0992, 0x0CCC);
	CamWriteCmosSensor(0x0994, 0x33D6);
	CamWriteCmosSensor(0x0996, 0x30ED);
	CamWriteCmosSensor(0x0998, 0x00FC);
	CamWriteCmosSensor(0x099A, 0x0592);
	CamWriteCmosSensor(0x099C, 0xBDA8);
	CamWriteCmosSensor(0x099E, 0x93CC);
	CamWriteCmosSensor(0x098A, 0x0AC0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x33F4);
	CamWriteCmosSensor(0x0992, 0x30ED);
	CamWriteCmosSensor(0x0994, 0x02CC);
	CamWriteCmosSensor(0x0996, 0xFFE9);
	CamWriteCmosSensor(0x0998, 0xED00);
	CamWriteCmosSensor(0x099A, 0xFC05);
	CamWriteCmosSensor(0x099C, 0x94C4);
	CamWriteCmosSensor(0x099E, 0x164F);
	CamWriteCmosSensor(0x098A, 0x0AD0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0xBDA9);
	CamWriteCmosSensor(0x0992, 0x0ACE);
	CamWriteCmosSensor(0x0994, 0x051F);
	CamWriteCmosSensor(0x0996, 0x1F02);
	CamWriteCmosSensor(0x0998, 0x020A);
	CamWriteCmosSensor(0x099A, 0xCC32);
	CamWriteCmosSensor(0x099C, 0x1030);
	CamWriteCmosSensor(0x099E, 0xED00);
	CamWriteCmosSensor(0x098A, 0x0AE0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x4FBD);
	CamWriteCmosSensor(0x0992, 0xA8E4);
	CamWriteCmosSensor(0x0994, 0x3838);
	CamWriteCmosSensor(0x0996, 0x393C);
	CamWriteCmosSensor(0x0998, 0x3CFC);
	CamWriteCmosSensor(0x099A, 0x0322);
	CamWriteCmosSensor(0x099C, 0xB303);
	CamWriteCmosSensor(0x099E, 0x2030);
	CamWriteCmosSensor(0x098A, 0x0AF0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0xED02);
	CamWriteCmosSensor(0x0992, 0xCE03);
	CamWriteCmosSensor(0x0994, 0x141F);
	CamWriteCmosSensor(0x0996, 0x0408);
	CamWriteCmosSensor(0x0998, 0x3ECE);
	CamWriteCmosSensor(0x099A, 0x0314);
	CamWriteCmosSensor(0x099C, 0x1F0B);
	CamWriteCmosSensor(0x099E, 0x0134);
	CamWriteCmosSensor(0x098A, 0x0B00);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x30EC);
	CamWriteCmosSensor(0x0992, 0x0227);
	CamWriteCmosSensor(0x0994, 0x2F83);
	CamWriteCmosSensor(0x0996, 0x0000);
	CamWriteCmosSensor(0x0998, 0x2C18);
	CamWriteCmosSensor(0x099A, 0xF603);
	CamWriteCmosSensor(0x099C, 0x244F);
	CamWriteCmosSensor(0x099E, 0xED00);
	CamWriteCmosSensor(0x098A, 0x0B10);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0xFC03);
	CamWriteCmosSensor(0x0992, 0x20A3);
	CamWriteCmosSensor(0x0994, 0x00B3);
	CamWriteCmosSensor(0x0996, 0x0322);
	CamWriteCmosSensor(0x0998, 0x241A);
	CamWriteCmosSensor(0x099A, 0xFC03);
	CamWriteCmosSensor(0x099C, 0x22FD);
	CamWriteCmosSensor(0x099E, 0x0320);
	CamWriteCmosSensor(0x098A, 0x0B20);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x2012);
	CamWriteCmosSensor(0x0992, 0xF603);
	CamWriteCmosSensor(0x0994, 0x244F);
	CamWriteCmosSensor(0x0996, 0xF303);
	CamWriteCmosSensor(0x0998, 0x20B3);
	CamWriteCmosSensor(0x099A, 0x0322);
	CamWriteCmosSensor(0x099C, 0x2306);
	CamWriteCmosSensor(0x099E, 0xFC03);
	CamWriteCmosSensor(0x098A, 0x0B30);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x22FD);
	CamWriteCmosSensor(0x0992, 0x0320);
	CamWriteCmosSensor(0x0994, 0xBD7D);
	CamWriteCmosSensor(0x0996, 0x9038);
	CamWriteCmosSensor(0x0998, 0x3839);
	CamWriteCmosSensor(0x099A, 0x3C3C);
	CamWriteCmosSensor(0x099C, 0xFC07);
	CamWriteCmosSensor(0x099E, 0x4327);
	CamWriteCmosSensor(0x098A, 0x0B40);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x5FDE);
	CamWriteCmosSensor(0x0992, 0x431F);
	CamWriteCmosSensor(0x0994, 0xB410);
	CamWriteCmosSensor(0x0996, 0x563C);
	CamWriteCmosSensor(0x0998, 0xFC07);
	CamWriteCmosSensor(0x099A, 0x4130);
	CamWriteCmosSensor(0x099C, 0xED00);
	CamWriteCmosSensor(0x099E, 0x3CCC);
	CamWriteCmosSensor(0x098A, 0x0B50);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x0008);
	CamWriteCmosSensor(0x0992, 0x30ED);
	CamWriteCmosSensor(0x0994, 0x00FC);
	CamWriteCmosSensor(0x0996, 0x0743);
	CamWriteCmosSensor(0x0998, 0xBDAA);
	CamWriteCmosSensor(0x099A, 0x7C38);
	CamWriteCmosSensor(0x099C, 0x38BD);
	CamWriteCmosSensor(0x099E, 0xE9E4);
	CamWriteCmosSensor(0x098A, 0x0B60);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x30ED);
	CamWriteCmosSensor(0x0992, 0x02CC);
	CamWriteCmosSensor(0x0994, 0x0064);
	CamWriteCmosSensor(0x0996, 0xED00);
	CamWriteCmosSensor(0x0998, 0xCC01);
	CamWriteCmosSensor(0x099A, 0x00BD);
	CamWriteCmosSensor(0x099C, 0xAA7C);
	CamWriteCmosSensor(0x099E, 0xFD03);
	CamWriteCmosSensor(0x098A, 0x0B70);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x103C);
	CamWriteCmosSensor(0x0992, 0xFC07);
	CamWriteCmosSensor(0x0994, 0x4530);
	CamWriteCmosSensor(0x0996, 0xED00);
	CamWriteCmosSensor(0x0998, 0x3CCC);
	CamWriteCmosSensor(0x099A, 0x0008);
	CamWriteCmosSensor(0x099C, 0x30ED);
	CamWriteCmosSensor(0x099E, 0x00FC);
	CamWriteCmosSensor(0x098A, 0x0B80);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x0743);
	CamWriteCmosSensor(0x0992, 0xBDAA);
	CamWriteCmosSensor(0x0994, 0x7C38);
	CamWriteCmosSensor(0x0996, 0x38BD);
	CamWriteCmosSensor(0x0998, 0xE9E4);
	CamWriteCmosSensor(0x099A, 0x30ED);
	CamWriteCmosSensor(0x099C, 0x02CC);
	CamWriteCmosSensor(0x099E, 0x0064);
	CamWriteCmosSensor(0x098A, 0x0B90);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0xED00);
	CamWriteCmosSensor(0x0992, 0xCC01);
	CamWriteCmosSensor(0x0994, 0x00BD);
	CamWriteCmosSensor(0x0996, 0xAA7C);
	CamWriteCmosSensor(0x0998, 0xFD03);
	CamWriteCmosSensor(0x099A, 0x1220);
	CamWriteCmosSensor(0x099C, 0x03BD);
	CamWriteCmosSensor(0x099E, 0x7993);
	CamWriteCmosSensor(0x098A, 0x0BA0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x3838);
	CamWriteCmosSensor(0x0992, 0x390F);
	CamWriteCmosSensor(0x0994, 0xF601);
	CamWriteCmosSensor(0x0996, 0x05C1);
	CamWriteCmosSensor(0x0998, 0x0326);
	CamWriteCmosSensor(0x099A, 0x14F6);
	CamWriteCmosSensor(0x099C, 0x0106);
	CamWriteCmosSensor(0x099E, 0xC106);
	CamWriteCmosSensor(0x098A, 0x0BB0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x260D);
	CamWriteCmosSensor(0x0992, 0xF630);
	CamWriteCmosSensor(0x0994, 0x4DC4);
	CamWriteCmosSensor(0x0996, 0xF0CA);
	CamWriteCmosSensor(0x0998, 0x08F7);
	CamWriteCmosSensor(0x099A, 0x304D);
	CamWriteCmosSensor(0x099C, 0xBD0B);
	CamWriteCmosSensor(0x099E, 0xC10E);
	CamWriteCmosSensor(0x098A, 0x0BC0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x39F6);
	CamWriteCmosSensor(0x0992, 0x304D);
	CamWriteCmosSensor(0x0994, 0xC4F0);
	CamWriteCmosSensor(0x0996, 0xCA09);
	CamWriteCmosSensor(0x0998, 0xF730);
	CamWriteCmosSensor(0x099A, 0x4DDE);
	CamWriteCmosSensor(0x099C, 0xF218);
	CamWriteCmosSensor(0x099E, 0xCE0A);
	CamWriteCmosSensor(0x098A, 0x0BD0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x00CC);
	CamWriteCmosSensor(0x0992, 0x001D);
	CamWriteCmosSensor(0x0994, 0xBDB5);
	CamWriteCmosSensor(0x0996, 0x31DE);
	CamWriteCmosSensor(0x0998, 0xA818);
	CamWriteCmosSensor(0x099A, 0xCE0A);
	CamWriteCmosSensor(0x099C, 0x1ECC);
	CamWriteCmosSensor(0x099E, 0x001D);
	CamWriteCmosSensor(0x098A, 0x0BE0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0xBDB5);
	CamWriteCmosSensor(0x0992, 0x31DE);
	CamWriteCmosSensor(0x0994, 0xA618);
	CamWriteCmosSensor(0x0996, 0xCE0A);
	CamWriteCmosSensor(0x0998, 0x3CCC);
	CamWriteCmosSensor(0x099A, 0x0013);
	CamWriteCmosSensor(0x099C, 0xBDB5);
	CamWriteCmosSensor(0x099E, 0x31CC);
	CamWriteCmosSensor(0x098A, 0x0BF0);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x0A80);
	CamWriteCmosSensor(0x0992, 0xFD0A);
	CamWriteCmosSensor(0x0994, 0x0ECC);
	CamWriteCmosSensor(0x0996, 0x0AE7);
	CamWriteCmosSensor(0x0998, 0xFD0A);
	CamWriteCmosSensor(0x099A, 0x30CC);
	CamWriteCmosSensor(0x099C, 0x0B3A);
	CamWriteCmosSensor(0x099E, 0xFD0A);
	CamWriteCmosSensor(0x098A, 0x0C00);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x4CCC);
	CamWriteCmosSensor(0x0992, 0x0A00);
	CamWriteCmosSensor(0x0994, 0xDDF2);
	CamWriteCmosSensor(0x0996, 0xCC0A);
	CamWriteCmosSensor(0x0998, 0x1EDD);
	CamWriteCmosSensor(0x099A, 0xA8CC);
	CamWriteCmosSensor(0x099C, 0x0A3C);
	CamWriteCmosSensor(0x099E, 0xDDA6);
	CamWriteCmosSensor(0x098A, 0x0C10);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0xC601);
	CamWriteCmosSensor(0x0992, 0xF701);
	CamWriteCmosSensor(0x0994, 0x0CF7);
	CamWriteCmosSensor(0x0996, 0x010D);
	CamWriteCmosSensor(0x098A, 0x8C18);	// PHYSICAL_ADDR_ACCESS
	CamWriteCmosSensor(0x0990, 0x0039);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x0012);	// MCU_ADDRESS [MON_ADDR]
	CamWriteCmosSensor(0x0990, 0x0BA3);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x0003);	// MCU_ADDRESS [MON_ALGO]
	CamWriteCmosSensor(0x0990, 0x0004);	// MCU_DATA_0
	kal_sleep_task(20);//DELAY=100
	//POLL_FIELD=MON_RAM_PATCH_ID,==0,DELAY=10,TIMEOUT=100		   // wait for the patch to complete initialization 
	
	//Char_settings
	CamWriteCmosSensor(0x3ED6, 0x0F00);	// DAC_LD_10_11
	CamWriteCmosSensor(0x3EF2, 0xD965);	// DAC_LP_6_7
	CamWriteCmosSensor(0x3FD2, 0xD965);
	CamWriteCmosSensor(0x3EF8, 0x7F7F);	// DAC_LD_TXHI
	CamWriteCmosSensor(0x3ED8, 0x7F1D);	// DAC_LD_12_13
	CamWriteCmosSensor(0x3172, 0x0033);	// ANALOG_CONTROL2
	CamWriteCmosSensor(0x3EEA, 0x0200);	// DAC_LD_30_31
	CamWriteCmosSensor(0x3EE2, 0x0050);	// DAC_LD_22_23
	CamWriteCmosSensor(0x316A, 0x8200);	// DAC_FBIAS
	CamWriteCmosSensor(0x316C, 0x8200);	// DAC_TXLO
	CamWriteCmosSensor(0x3EFC, 0xA8E8);	// DAC_LD_FBIAS
	CamWriteCmosSensor(0x3EFE, 0x130D);	// DAC_LD_TXLO
	CamWriteCmosSensor(0x30BC, 0x0384);	// CALIB_GLOBAL
	CamWriteCmosSensor(0x30C0, 0x1220);	// CALIB_CONTROL

	//Low_Power_Mode
	CamWriteCmosSensor(0x3170, 0x000A); //Dynamic pwr setting
	CamWriteCmosSensor(0x3174, 0x8031); //Dynamic pwr setting
	CamWriteCmosSensor(0x317A, 0x000A); //Dynamic pwr setting
	CamWriteCmosSensor(0x3ECC, 0x22B0); //Dynamic pwr setting
	CamWriteCmosSensor(0x098E, 0x482B);	
	CamWriteCmosSensor(0x0990, 0x22B0);	
	CamWriteCmosSensor(0x098E, 0x4858);	
	CamWriteCmosSensor(0x0990, 0x22B0);	
	CamWriteCmosSensor(0x098E, 0x4822);	
	CamWriteCmosSensor(0x0990, 0x000A);	
	CamWriteCmosSensor(0x098E, 0x4824);	
	CamWriteCmosSensor(0x0990, 0x000A);	
	CamWriteCmosSensor(0x098E, 0x484F);	
	CamWriteCmosSensor(0x0990, 0x000A);	
	CamWriteCmosSensor(0x098E, 0x4851);	
	CamWriteCmosSensor(0x0990, 0x000A); 

	
	//LSC
	//T-85%
	CamWriteCmosSensor(0x3640, 0x02B0);	// P_G1_P0Q0
	CamWriteCmosSensor(0x3642, 0x152E);	// P_G1_P0Q1
	CamWriteCmosSensor(0x3644, 0x01D2);	// P_G1_P0Q2
	CamWriteCmosSensor(0x3646, 0xADCE);	// P_G1_P0Q3
	CamWriteCmosSensor(0x3648, 0xBE32);	// P_G1_P0Q4
	CamWriteCmosSensor(0x364A, 0x0410);	// P_R_P0Q0
	CamWriteCmosSensor(0x364C, 0xA6EE);	// P_R_P0Q1
	CamWriteCmosSensor(0x364E, 0x71D1);	// P_R_P0Q2
	CamWriteCmosSensor(0x3650, 0x7A10);	// P_R_P0Q3
	CamWriteCmosSensor(0x3652, 0xCDF2);	// P_R_P0Q4
	CamWriteCmosSensor(0x3654, 0x04F0);	// P_B_P0Q0
	CamWriteCmosSensor(0x3656, 0x176F);	// P_B_P0Q1
	CamWriteCmosSensor(0x3658, 0x2911);	// P_B_P0Q2
	CamWriteCmosSensor(0x365A, 0xA32F);	// P_B_P0Q3
	CamWriteCmosSensor(0x365C, 0xF851);	// P_B_P0Q4
	CamWriteCmosSensor(0x365E, 0x0630);	// P_G2_P0Q0
	CamWriteCmosSensor(0x3660, 0x8CEF);	// P_G2_P0Q1
	CamWriteCmosSensor(0x3662, 0x12B2);	// P_G2_P0Q2
	CamWriteCmosSensor(0x3664, 0x5CCF);	// P_G2_P0Q3
	CamWriteCmosSensor(0x3666, 0xE752);	// P_G2_P0Q4
	CamWriteCmosSensor(0x3680, 0xA10D);	// P_G1_P1Q0
	CamWriteCmosSensor(0x3682, 0x98AF);	// P_G1_P1Q1
	CamWriteCmosSensor(0x3684, 0x730E);	// P_G1_P1Q2
	CamWriteCmosSensor(0x3686, 0x584F);	// P_G1_P1Q3
	CamWriteCmosSensor(0x3688, 0xADAD);	// P_G1_P1Q4
	CamWriteCmosSensor(0x368A, 0xBECE);	// P_R_P1Q0
	CamWriteCmosSensor(0x368C, 0x092F);	// P_R_P1Q1
	CamWriteCmosSensor(0x368E, 0x20B0);	// P_R_P1Q2
	CamWriteCmosSensor(0x3690, 0xC750);	// P_R_P1Q3
	CamWriteCmosSensor(0x3692, 0xA690);	// P_R_P1Q4
	CamWriteCmosSensor(0x3694, 0x5DCC);	// P_B_P1Q0
	CamWriteCmosSensor(0x3696, 0x680F);	// P_B_P1Q1
	CamWriteCmosSensor(0x3698, 0x48F1);	// P_B_P1Q2
	CamWriteCmosSensor(0x369A, 0x89D1);	// P_B_P1Q3
	CamWriteCmosSensor(0x369C, 0xA513);	// P_B_P1Q4
	CamWriteCmosSensor(0x369E, 0x7ACD);	// P_G2_P1Q0
	CamWriteCmosSensor(0x36A0, 0x8010);	// P_G2_P1Q1
	CamWriteCmosSensor(0x36A2, 0x0052);	// P_G2_P1Q2
	CamWriteCmosSensor(0x36A4, 0x1AD1);	// P_G2_P1Q3
	CamWriteCmosSensor(0x36A6, 0xC0F3);	// P_G2_P1Q4
	CamWriteCmosSensor(0x36C0, 0x0C92);	// P_G1_P2Q0
	CamWriteCmosSensor(0x36C2, 0x61CF);	// P_G1_P2Q1
	CamWriteCmosSensor(0x36C4, 0xE9B3);	// P_G1_P2Q2
	CamWriteCmosSensor(0x36C6, 0xF7B0);	// P_G1_P2Q3
	CamWriteCmosSensor(0x36C8, 0x2FF4);	// P_G1_P2Q4
	CamWriteCmosSensor(0x36CA, 0x2D32);	// P_R_P2Q0
	CamWriteCmosSensor(0x36CC, 0xDB2F);	// P_R_P2Q1
	CamWriteCmosSensor(0x36CE, 0xC733);	// P_R_P2Q2
	CamWriteCmosSensor(0x36D0, 0xFECE);	// P_R_P2Q3
	CamWriteCmosSensor(0x36D2, 0x5973);	// P_R_P2Q4
	CamWriteCmosSensor(0x36D4, 0x05D2);	// P_B_P2Q0
	CamWriteCmosSensor(0x36D6, 0x2D71);	// P_B_P2Q1
	CamWriteCmosSensor(0x36D8, 0xE2F3);	// P_B_P2Q2
	CamWriteCmosSensor(0x36DA, 0x8333);	// P_B_P2Q3
	CamWriteCmosSensor(0x36DC, 0x5714);	// P_B_P2Q4
	CamWriteCmosSensor(0x36DE, 0x20F2);	// P_G2_P2Q0
	CamWriteCmosSensor(0x36E0, 0xF510);	// P_G2_P2Q1
	CamWriteCmosSensor(0x36E2, 0xEB73);	// P_G2_P2Q2
	CamWriteCmosSensor(0x36E4, 0x1D12);	// P_G2_P2Q3
	CamWriteCmosSensor(0x36E6, 0x5493);	// P_G2_P2Q4
	CamWriteCmosSensor(0x3700, 0x5690);	// P_G1_P3Q0
	CamWriteCmosSensor(0x3702, 0x0430);	// P_G1_P3Q1
	CamWriteCmosSensor(0x3704, 0xC86D);	// P_G1_P3Q2
	CamWriteCmosSensor(0x3706, 0xDDCF);	// P_G1_P3Q3
	CamWriteCmosSensor(0x3708, 0xED14);	// P_G1_P3Q4
	CamWriteCmosSensor(0x370A, 0x7850);	// P_R_P3Q0
	CamWriteCmosSensor(0x370C, 0xF94E);	// P_R_P3Q1
	CamWriteCmosSensor(0x370E, 0x97EF);	// P_R_P3Q2
	CamWriteCmosSensor(0x3710, 0x5152);	// P_R_P3Q3
	CamWriteCmosSensor(0x3712, 0xEAD4);	// P_R_P3Q4
	CamWriteCmosSensor(0x3714, 0x16D0);	// P_B_P3Q0
	CamWriteCmosSensor(0x3716, 0xCBF0);	// P_B_P3Q1
	CamWriteCmosSensor(0x3718, 0x8054);	// P_B_P3Q2
	CamWriteCmosSensor(0x371A, 0x15B2);	// P_B_P3Q3
	CamWriteCmosSensor(0x371C, 0x30F5);	// P_B_P3Q4
	CamWriteCmosSensor(0x371E, 0x0691);	// P_G2_P3Q0
	CamWriteCmosSensor(0x3720, 0x4B4F);	// P_G2_P3Q1
	CamWriteCmosSensor(0x3722, 0x9034);	// P_G2_P3Q2
	CamWriteCmosSensor(0x3724, 0xAD8F);	// P_G2_P3Q3
	CamWriteCmosSensor(0x3726, 0x0655);	// P_G2_P3Q4
	CamWriteCmosSensor(0x3740, 0x9DB3);	// P_G1_P4Q0
	CamWriteCmosSensor(0x3742, 0x9452);	// P_G1_P4Q1
	CamWriteCmosSensor(0x3744, 0xA713);	// P_G1_P4Q2
	CamWriteCmosSensor(0x3746, 0x32F3);	// P_G1_P4Q3
	CamWriteCmosSensor(0x3748, 0x03B8);	// P_G1_P4Q4
	CamWriteCmosSensor(0x374A, 0xA813);	// P_R_P4Q0
	CamWriteCmosSensor(0x374C, 0x0411);	// P_R_P4Q1
	CamWriteCmosSensor(0x374E, 0x9294);	// P_R_P4Q2
	CamWriteCmosSensor(0x3750, 0x8F14);	// P_R_P4Q3
	CamWriteCmosSensor(0x3752, 0x1058);	// P_R_P4Q4
	CamWriteCmosSensor(0x3754, 0xBFD3);	// P_B_P4Q0
	CamWriteCmosSensor(0x3756, 0xFA53);	// P_B_P4Q1
	CamWriteCmosSensor(0x3758, 0x0814);	// P_B_P4Q2
	CamWriteCmosSensor(0x375A, 0x6BB5);	// P_B_P4Q3
	CamWriteCmosSensor(0x375C, 0x24F7);	// P_B_P4Q4
	CamWriteCmosSensor(0x375E, 0xBAF3);	// P_G2_P4Q0
	CamWriteCmosSensor(0x3760, 0x20D3);	// P_G2_P4Q1
	CamWriteCmosSensor(0x3762, 0xE012);	// P_G2_P4Q2
	CamWriteCmosSensor(0x3764, 0xCE75);	// P_G2_P4Q3
	CamWriteCmosSensor(0x3766, 0x1B58);	// P_G2_P4Q4
	CamWriteCmosSensor(0x3782, 0x0280);	// CENTER_ROW
	CamWriteCmosSensor(0x3784, 0x03C0);	// CENTER_COLUMN
	CamWriteCmosSensor(0x3210, 0x00B8);	// COLOR_PIPELINE_CONTROL
	
	//AWB_CCM
	CamWriteCmosSensor(0x098E, 0x4873);	// MCU_ADDRESS [CAM1_AWB_CCM_L_0]
	CamWriteCmosSensor(0x0990, 0x0206);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4875);	// MCU_ADDRESS [CAM1_AWB_CCM_L_1]
	CamWriteCmosSensor(0x0990, 0xFEDA);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4877);	// MCU_ADDRESS [CAM1_AWB_CCM_L_2]
	CamWriteCmosSensor(0x0990, 0x001F);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4879);	// MCU_ADDRESS [CAM1_AWB_CCM_L_3]
	CamWriteCmosSensor(0x0990, 0xFFC7);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x487B);	// MCU_ADDRESS [CAM1_AWB_CCM_L_4]
	CamWriteCmosSensor(0x0990, 0x014E);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x487D);	// MCU_ADDRESS [CAM1_AWB_CCM_L_5]
	CamWriteCmosSensor(0x0990, 0xFFE9);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x487F);	// MCU_ADDRESS [CAM1_AWB_CCM_L_6]
	CamWriteCmosSensor(0x0990, 0xFFAD);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4881);	// MCU_ADDRESS [CAM1_AWB_CCM_L_7]
	CamWriteCmosSensor(0x0990, 0xFF12);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4883);	// MCU_ADDRESS [CAM1_AWB_CCM_L_8]
	CamWriteCmosSensor(0x0990, 0x023F);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4885);	// MCU_ADDRESS [CAM1_AWB_CCM_L_9]
	CamWriteCmosSensor(0x0990, 0x001D);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4887);	// MCU_ADDRESS [CAM1_AWB_CCM_L_10]
	CamWriteCmosSensor(0x0990, 0x005E);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4889);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_0]
	CamWriteCmosSensor(0x0990, 0xFFA2);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x488B);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_1]
	CamWriteCmosSensor(0x0990, 0x00A5);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x488D);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_2]
	CamWriteCmosSensor(0x0990, 0xFFB6);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x488F);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_3]
	CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4891);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_4]
	CamWriteCmosSensor(0x0990, 0xFFE5);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4893);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_5]
	CamWriteCmosSensor(0x0990, 0x0017);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4895);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_6]
	CamWriteCmosSensor(0x0990, 0x004C);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4897);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_7]
	CamWriteCmosSensor(0x0990, 0x007F);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4899);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_8]
	CamWriteCmosSensor(0x0990, 0xFF34);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x489B);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_9]
	CamWriteCmosSensor(0x0990, 0x0014);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x489D);	// MCU_ADDRESS [CAM1_AWB_CCM_RL_10]
	CamWriteCmosSensor(0x0990, 0xFFCF);	// MCU_DATA_0
	
	
	CamWriteCmosSensor(0x098E, 0x48B8);	// MCU_ADDRESS [CAM1_AWB_X_SHIFT]
	CamWriteCmosSensor(0x0990, 0x001D);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48BA);	// MCU_ADDRESS [CAM1_AWB_Y_SHIFT]
	CamWriteCmosSensor(0x0990, 0x001D);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48BC);	// MCU_ADDRESS [CAM1_AWB_RECIP_XSCALE]
	CamWriteCmosSensor(0x0990, 0x00AB);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48BE);	// MCU_ADDRESS [CAM1_AWB_RECIP_YSCALE]
	CamWriteCmosSensor(0x0990, 0x0080);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48C0);	// MCU_ADDRESS [CAM1_AWB_ROT_CENTER_X]
	CamWriteCmosSensor(0x0990, 0x03F8);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48C2);	// MCU_ADDRESS [CAM1_AWB_ROT_CENTER_Y]
	CamWriteCmosSensor(0x0990, 0x03E2);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC8C4);	// MCU_ADDRESS [CAM1_AWB_ROT_SIN]
	CamWriteCmosSensor(0x0990, 0x0036);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC8C5);	// MCU_ADDRESS [CAM1_AWB_ROT_COS]
	CamWriteCmosSensor(0x0990, 0x0023);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48C6);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_0]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48C8);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_1]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48CA);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_2]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48CC);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_3]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48CE);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_4]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48D0);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_5]
	CamWriteCmosSensor(0x0990, 0x0111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48D2);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_6]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48D4);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_7]
	CamWriteCmosSensor(0x0990, 0x1000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48D6);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_8]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48D8);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_9]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48DA);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_10]
	CamWriteCmosSensor(0x0990, 0x1121);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48DC);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_11]
	CamWriteCmosSensor(0x0990, 0x1110);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48DE);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_12]
	CamWriteCmosSensor(0x0990, 0x0011);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48E0);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_13]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48E2);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_14]
	CamWriteCmosSensor(0x0990, 0x1122);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48E4);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_15]
	CamWriteCmosSensor(0x0990, 0x1110);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48E6);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_16]
	CamWriteCmosSensor(0x0990, 0x1122);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48E8);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_17]
	CamWriteCmosSensor(0x0990, 0x2322);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48EA);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_18]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48EC);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_19]
	CamWriteCmosSensor(0x0990, 0x2211);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48EE);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_20]
	CamWriteCmosSensor(0x0990, 0x1344);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48F0);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_21]
	CamWriteCmosSensor(0x0990, 0x4432);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48F2);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_22]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48F4);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_23]
	CamWriteCmosSensor(0x0990, 0x1221);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48F6);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_24]
	CamWriteCmosSensor(0x0990, 0x1244);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48F8);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_25]
	CamWriteCmosSensor(0x0990, 0x4322);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48FA);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_26]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48FC);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_27]
	CamWriteCmosSensor(0x0990, 0x1121);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x48FE);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_28]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4900);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_29]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4902);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_30]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4904);	// MCU_ADDRESS [CAM1_AWB_WEIGHT_TABLE_31]
	CamWriteCmosSensor(0x0990, 0x1111);	// MCU_DATA_0
	
	//Step6-CPIPE_Calibration
	
	//GRB - calibration - 2 sigma
	CamWriteCmosSensor(0x098E, 0xC920);	// MCU_ADDRESS [CAM1_LL_GRB_SLOPE_START]
	CamWriteCmosSensor(0x0990, 0x0016);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC921);	// MCU_ADDRESS [CAM1_LL_GRB_SLOPE_STOP]
	CamWriteCmosSensor(0x0990, 0x0042);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC922);	// MCU_ADDRESS [CAM1_LL_GRB_OFFSET_START]
	CamWriteCmosSensor(0x0990, 0x000F);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC923);	// MCU_ADDRESS [CAM1_LL_GRB_OFFSET_STOP]
	CamWriteCmosSensor(0x0990, 0x002C);	// MCU_DATA_0
	
	//aperture - calibration1
	CamWriteCmosSensor(0x098E, 0xC908);	// MCU_ADDRESS [CAM1_LL_AP_KNEE_START]
	CamWriteCmosSensor(0x0990, 0x000C);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC909);	// MCU_ADDRESS [CAM1_LL_AP_KNEE_STOP]
	CamWriteCmosSensor(0x0990, 0x0027);	// MCU_DATA_0
	
	//SFFB - calibration - 1.5sigma
	CamWriteCmosSensor(0x098E, 0x492A);	// MCU_ADDRESS [CAM1_LL_SFFB_RAMP_START]
	CamWriteCmosSensor(0x0990, 0x0028);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x492C);	// MCU_ADDRESS [CAM1_LL_SFFB_RAMP_STOP]
	CamWriteCmosSensor(0x0990, 0x0016);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x492E);	// MCU_ADDRESS [CAM1_LL_SFFB_SLOPE_START]
	CamWriteCmosSensor(0x0990, 0x001F);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4930);	// MCU_ADDRESS [CAM1_LL_SFFB_SLOPE_STOP]
	CamWriteCmosSensor(0x0990, 0x000A);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4932);	// MCU_ADDRESS [CAM1_LL_SFFB_LOW_THRESH1START]
	CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4934);	// MCU_ADDRESS [CAM1_LL_SFFB_LOW_THRESH1STOP]
	CamWriteCmosSensor(0x0990, 0x0006);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4936);	// MCU_ADDRESS [CAM1_LL_SFFB_LOW_THRESH2START]
	CamWriteCmosSensor(0x0990, 0x0003);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4938);	// MCU_ADDRESS [CAM1_LL_SFFB_LOW_THRESH2STOP]
	CamWriteCmosSensor(0x0990, 0x0007);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x493A);	// MCU_ADDRESS [CAM1_LL_SFFB_LOW_THRESH3START]
	CamWriteCmosSensor(0x0990, 0x0004);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x493C);	// MCU_ADDRESS [CAM1_LL_SFFB_LOW_THRESH3STOP]
	CamWriteCmosSensor(0x0990, 0x0008);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x493E);	// MCU_ADDRESS [CAM1_LL_SFFB_MAX_THRESH_START]
	CamWriteCmosSensor(0x0990, 0x0009);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4940);	// MCU_ADDRESS [CAM1_LL_SFFB_MAX_THRESH_STOP]
	CamWriteCmosSensor(0x0990, 0x0015);	// MCU_DATA_0
	
	//Demosaic - calibration1
	CamWriteCmosSensor(0x098E, 0xC906);	// MCU_ADDRESS [CAM1_LL_DM_EDGE_TH_START]
	CamWriteCmosSensor(0x0990, 0x000C);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC907);	// MCU_ADDRESS [CAM1_LL_DM_EDGE_TH_STOP]
	CamWriteCmosSensor(0x0990, 0x0027);	// MCU_DATA_0
	
	//Defect - calibration
	CamWriteCmosSensor(0x098E, 0x495A);	// MCU_ADDRESS [CAM1_LL_DC_START]
	CamWriteCmosSensor(0x0990, 0x007B);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x495C);	// MCU_ADDRESS [CAM1_LL_DC_STOP]
	CamWriteCmosSensor(0x0990, 0x0111);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC970);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_TO_START]
	CamWriteCmosSensor(0x0990, 0x001E);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC971);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_TO_STOP]
	CamWriteCmosSensor(0x0990, 0x0042);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC97E);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_TO_START]
	CamWriteCmosSensor(0x0990, 0x001E);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC97F);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_TO_STOP]
	CamWriteCmosSensor(0x0990, 0x0042);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4968);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_T3START]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x496A);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_T3STOP]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4976);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_T3START]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4978);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_T3STOP]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x496C);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_T4START]
	CamWriteCmosSensor(0x0990, 0x00C6);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x496E);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_T4STOP]
	CamWriteCmosSensor(0x0990, 0x000c);	// 0x01C2 MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x497A);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_T4START]
	CamWriteCmosSensor(0x0990, 0x00C6);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x497C);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_T4STOP]
	CamWriteCmosSensor(0x0990, 0x01C2);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC962);	// MCU_ADDRESS [CAM1_LL_CDC_AGG_START]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC963);	// MCU_ADDRESS [CAM1_LL_CDC_AGG_STOP]
	CamWriteCmosSensor(0x0990, 0x0003);	// MCU_DATA_0
	
	//
	CamWriteCmosSensor(0x098E, 0xBC02);	// MCU_ADDRESS [LL_MODE]
	CamWriteCmosSensor(0x0990, 0x0005);	// 0x000DMCU_DATA_0
	CamWriteCmosSensor(0x326E, 0x0006);	// LOW_PASS_YUV_FILTER
	
	//Step7-CPIPE_Preference
	//Lower Maxgain case
	CamWriteCmosSensor(0x326C, 0x170A);	// APERTURE_PARAMETERS_2D
	CamWriteCmosSensor(0x3210, 0x00B8);	// COLOR_PIPELINE_CONTROL
	
	CamWriteCmosSensor(0x098E, 0x6824);	// MCU_ADDRESS [PRI_A_CONFIG_AE_TRACK_TARGET_DGAIN]
	CamWriteCmosSensor(0x0990, 0x0080);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x682B);	// MCU_ADDRESS [PRI_A_CONFIG_AE_TRACK_AE_MAX_VIRT_DGAIN]
	CamWriteCmosSensor(0x0990, 0x0080);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x2800);	// MCU_ADDRESS [AE_TRACK_STATUS]
	CamWriteCmosSensor(0x0990, 0x001C);	// MCU_DATA_0

	CamWriteCmosSensor(0x098E, 0x682F);	// MCU_ADDRESS
	CamWriteCmosSensor(0x0990, 0x0100);	// MCU_DATA_0// gain

	
	CamWriteCmosSensor(0x098E, 0x492A);	// MCU_ADDRESS [CAM1_LL_SFFB_RAMP_START]
	CamWriteCmosSensor(0x0990, 0x0050);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC944);	// MCU_ADDRESS [CAM1_LL_SFFB_FLATNESS_START]
	CamWriteCmosSensor(0x0990, 0x003C);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC949);	// MCU_ADDRESS [CAM1_LL_SFFB_SOBEL_FLAT_STOP]
	CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC942);	// MCU_ADDRESS [CAM1_LL_SFFB_SHARPENING_START]
	CamWriteCmosSensor(0x0990, 0x00FF);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC943);	// MCU_ADDRESS [CAM1_LL_SFFB_SHARPENING_STOP]
	CamWriteCmosSensor(0x0990, 0x00FF);	// MCU_DATA_0
	
	CamWriteCmosSensor(0x098E, 0x4956);	// MCU_ADDRESS [CAM1_LL_DC_START_GAIN_METRIC]
	CamWriteCmosSensor(0x0990, 0x0040);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4958);	// MCU_ADDRESS [CAM1_LL_DC_STOP_GAIN_METRIC]
	CamWriteCmosSensor(0x0990, 0x01F4);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x495A);	// MCU_ADDRESS [CAM1_LL_DC_START]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x495C);	// MCU_ADDRESS [CAM1_LL_DC_STOP]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xBC02);	// MCU_ADDRESS [LL_MODE]
	CamWriteCmosSensor(0x0990, 0x0005);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x495E);	// MCU_ADDRESS [CAM1_LL_CDC_AGG_START_GAIN_METRIC]
	CamWriteCmosSensor(0x0990, 0x0040);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4960);	// MCU_ADDRESS [CAM1_LL_CDC_AGG_STOP_GAIN_METRIC]
	CamWriteCmosSensor(0x0990, 0x01F4);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC962);	// MCU_ADDRESS [CAM1_LL_CDC_AGG_START]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC963);	// MCU_ADDRESS [CAM1_LL_CDC_AGG_STOP]
	CamWriteCmosSensor(0x0990, 0x0003);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4964);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_START_GAIN_METRIC]
	CamWriteCmosSensor(0x0990, 0x0040);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4966);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_STOP_GAIN_METRIC]
	CamWriteCmosSensor(0x0990, 0x01F4);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4968);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_T3START]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x496A);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_T3STOP]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x496C);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_T4START]
	CamWriteCmosSensor(0x0990, 0x00C8);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x496E);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_T4STOP]
	CamWriteCmosSensor(0x0990, 0x003C);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC970);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_TO_START]
	CamWriteCmosSensor(0x0990, 0x0004);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC971);	// MCU_ADDRESS [CAM1_LL_CDC_BRIGHT_TO_STOP]
	CamWriteCmosSensor(0x0990, 0x000F);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4972);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_START_GAIN_METRIC]
	CamWriteCmosSensor(0x0990, 0x0040);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4974);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_STOP_GAIN_METRIC]
	CamWriteCmosSensor(0x0990, 0x01F4);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4976);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_T3START]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4978);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_T3STOP]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x497A);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_T4START]
	CamWriteCmosSensor(0x0990, 0x00C8);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x497C);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_T4STOP]
	CamWriteCmosSensor(0x0990, 0x003C);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC97E);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_TO_START]
	CamWriteCmosSensor(0x0990, 0x0004);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xC97F);	// MCU_ADDRESS [CAM1_LL_CDC_DARK_TO_STOP]
	CamWriteCmosSensor(0x0990, 0x000F);	// MCU_DATA_0
	
	CamWriteCmosSensor(0x098E, 0x3C42);	// MCU_ADDRESS [LL_START_GAMMA_FTB]
	CamWriteCmosSensor(0x0990, 0x0032);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x3C44);	// MCU_ADDRESS [LL_STOP_GAMMA_FTB]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4912);	// MCU_ADDRESS [CAM1_LL_START_GAMMA_BM]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4914);	// MCU_ADDRESS [CAM1_LL_MID_GAMMA_BM]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x4916);	// MCU_ADDRESS [CAM1_LL_STOP_GAMMA_BM]
	CamWriteCmosSensor(0x0990, 0x0037);	// MCU_DATA_0
	
	//Saturation
	CamWriteCmosSensor(0x098E, 0xC997);	// MCU_ADDRESS [CAM1_SYS_UV_COLOR_BOOST]
	CamWriteCmosSensor(0x0990, 0x0005);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x5C03);	// MCU_ADDRESS [SYS_ALGO]
	CamWriteCmosSensor(0x0990, 0x000B);	// MCU_DATA_0

	
	//Step8-Features
	CamWriteCmosSensor(0x098E, 0x8002);	// MCU_ADDRESS [MON_MODE]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	
	//Optimized
	//50Hz
	CamWriteCmosSensor(0x098E, 0x2003);	// MCU_ADDRESS [FD_ALGO]
	CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0xA005);	// MCU_ADDRESS [FD_FDPERIOD_SELECT]
	CamWriteCmosSensor(0x0990, 0x0001);	// MCU_DATA_0
	
	CamWriteCmosSensor(0x098E, 0xE876);
	CamWriteCmosSensor(0x0990, 0x00F0);
	CamWriteCmosSensor(0x098E, 0xE877);	
	CamWriteCmosSensor(0x0990, 0x0010);	//bao he du

	CamWriteCmosSensor(0x098E, 0xBC06);
	CamWriteCmosSensor(0x0990, 0x0002);	

	//sharpness
	//CamWriteCmosSensor(0x3210, 0x05B8);	// COLOR_PIPELINE_CONTROL


	CamWriteCmosSensor(0x98E, 0x8400);	//Refresh Sequencer Mode
	CamWriteCmosSensor(0x990, 0x06); //		= 6
	{
		kal_uint16 temp=0;
		while(temp <60)
		{
			CamWriteCmosSensor(0x098E, 0x8400);	  // MCU_DATA_0
			if(0==CamReadCmosSensor(0x990))
			{
			 break;
			}
			kal_sleep_task(4);//DELAY=20
			temp+=1;
		}
	}


	CamWriteCmosSensor(0x0018, 0x002A);	// STANDBY_CONTROL_AND_STATUS
	kal_sleep_task(20);//DELAY=100
	//STATE= Detect Master Clock, 1

	//add by junwu
	CamWriteCmosSensor(0x098E, 0xE826);	// MCU_ADDRESS [FD_FDPERIOD_SELECT]
	CamWriteCmosSensor(0x0990, 0x003D);	// MCU_DATA_0

	MT9T113Sensor.PvMode = KAL_TRUE;
	MT9T113Sensor.IntClk = 780;
  /* ===== code modify body end ===== */
}

/*************************************************************************
* FUNCTION
*   MT9T113PvSetting
*
* DESCRIPTION
*   This function apply the preview mode setting, normal the preview size is 1/4 of full size.
*   Ex. 2M (1600 x 1200)
*   Preview: 800 x 600 (use sub-sample or binning to acheive it)
*   Full Size: 1600 x 1200 (output every effective pixels.)
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113PvSetting(void)
{
	//[Go to preview]
	CamWriteCmosSensor(0x098E, 0xEC09);	  // MCU_ADDRESS [PRI_B_NUM_OF_FRAMES_RUN]
	CamWriteCmosSensor(0x0990, 0x0005);	  // MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x8400);	  // MCU_ADDRESS [SEQ_CMD]
	CamWriteCmosSensor(0x0990, 0x0001);	  // MCU_DATA_0
	{	
		kal_uint16 temp=0;
		while(temp <60)
		{
			CamWriteCmosSensor(0x098E, 0x8401);	  // MCU_DATA_0
			if(3==CamReadCmosSensor(0x990))
			{
			 break;
			}
			kal_sleep_task(4);//DELAY=20
			temp+=1;
		}
	}
	
  MT9T113Sensor.PvMode = KAL_TRUE;
  MT9T113Sensor.IntClk = 780;
  /* ===== code modify body start ===== */
  
  /* ===== code modify body end ===== */
}

/*************************************************************************
* FUNCTION
*   MT9T113CapSetting
*
* DESCRIPTION
*   This function config capture settting to sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113CapSetting(void)
{
  
  /* ===== code modify body start ===== */
  //[Go to capture]
	CamWriteCmosSensor(0x098E, 0xEC09);	// MCU_ADDRESS [PRI_B_NUM_OF_FRAMES_RUN]
	CamWriteCmosSensor(0x0990, 0x0000);	// MCU_DATA_0
	CamWriteCmosSensor(0x098E, 0x8400);	// MCU_ADDRESS [SEQ_CMD]
	CamWriteCmosSensor(0x0990, 0x0002);	// MCU_DATA_0
	CamWriteCmosSensor(0x3400, 0x7A24);	// MIPI_CONTROL

	{
		kal_uint16 temp=0;
		while(temp <60)
		{
			CamWriteCmosSensor(0x098E, 0x8401);	  // MCU_DATA_0
			if(7==CamReadCmosSensor(0x990))
			{
			 break;
			}
			kal_sleep_task(4);//DELAY=100
			temp+=1;
		}
	}
	MT9T113Sensor.PvMode = KAL_FALSE;
	MT9T113Sensor.IntClk = 780;
  /* ===== code modify body end ===== */
}

/*************************************************************************
* FUNCTION
*   MT9T113GetSensorInfo
*
* DESCRIPTION
*   This function set sensor infomation
*
* PARAMETERS
*   Info
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = MT9T113_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  
  /* ===== code modify body start ===== */
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_HIGH;
  /* ===== code modify body end ===== */
  
  Info->PreviewMclkFreq = MT9T113_MCLK;
  Info->CaptureMclkFreq = MT9T113_MCLK;
  Info->VideoMclkFreq = MT9T113_MCLK;
  
  Info->PreviewWidth = MT9T113_IMAGE_SENSOR_PV_WIDTH_DRV;
  Info->PreviewHeight = MT9T113_IMAGE_SENSOR_PV_HEIGHT_DRV;
  Info->FullWidth = MT9T113_IMAGE_SENSOR_FULL_WIDTH_DRV;
  Info->FullHeight = MT9T113_IMAGE_SENSOR_FULL_HEIGHT_DRV;
  
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
/*************************************************************************
* FUNCTION
*    MT9T113GetEvAwbRef
*
* DESCRIPTION
*    This function get sensor Ev/Awb (EV05/EV13) for auto scene detect
*
* PARAMETERS
*    Ref
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113GetEvAwbRef(P_SENSOR_AE_AWB_REF_STRUCT Ref)
{
    Ref->SensorAERef.AeRefLV05Shutter = 2568;
    Ref->SensorAERef.AeRefLV05Gain = 576 * 2; /* 9x, 128 base */
    Ref->SensorAERef.AeRefLV13Shutter = 49;
    Ref->SensorAERef.AeRefLV13Gain = 128 * 2; /* 2x, 128 base */
    Ref->SensorAwbGainRef.AwbRefD65Rgain = 225; /* 1.76x, 128 base */
    Ref->SensorAwbGainRef.AwbRefD65Bgain = 175; /* 1.37x, 128 base */
    Ref->SensorAwbGainRef.AwbRefCWFRgain = 191; /* 1.49x, 128 base */
    Ref->SensorAwbGainRef.AwbRefCWFBgain = 272; /* 2.125x, 128 base */
}

/*************************************************************************
* FUNCTION
*    MT9T113GetCurAeAwbInfo
*
* DESCRIPTION
*    This function get sensor cur Ae/Awb for auto scene detect
*
* PARAMETERS
*    Info
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113GetCurAeAwbInfo(P_SENSOR_AE_AWB_CUR_STRUCT Info)
{
    Info->SensorAECur.AeCurShutter = MT9T113ReadShutter();
    Info->SensorAECur.AeCurGain = MT9T113ReadGain() * 2; /* 128 base */
    Info->SensorAwbGainCur.AwbCurRgain = CamReadCmosSensor(0x32D4); /* 128 base */
    Info->SensorAwbGainCur.AwbCurBgain = CamReadCmosSensor(0x32DA); /* 128 base */
}
#endif

/*************************************************************************
* FUNCTION
*   MT9T113PowerOn
*
* DESCRIPTION
*   This function apply the power on sequence and read the sensor ID to check if the I2C
*  communication can work or not.
*
* PARAMETERS
*   None
*
* RETURNS
*   Sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 MT9T113PowerOn(void)
{
  static kal_uint8 MT9T113I2cAddr[] = 
  {
  	MT9T113_WRITE_ID_0,
    MT9T113_WRITE_ID_1,
    MT9T113_WRITE_ID_2,
    MT9T113_WRITE_ID_3,
  };
  kal_uint32 SensorId;
  kal_uint8 i;
  
  CisModulePowerOn(MT9T113Sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9T113_WRITE_ID_0,
    MT9T113_I2C_ADDR_BITS, MT9T113_I2C_DATA_BITS, MT9T113_HW_I2C_SPEED);
  
  /* hardware reset sensor by spec */
  /* ===== code modify body start ===== */
  {
	CamPdnPinCtrl(MT9T113Sensor.SensorIdx, 1);
	CamRstPinCtrl(MT9T113Sensor.SensorIdx, 0);
	kal_sleep_task(2); /* >= 5ms */

	CamPdnPinCtrl(MT9T113Sensor.SensorIdx, 0);
	kal_sleep_task(1); /* >= 1ms */
	CamRstPinCtrl(MT9T113Sensor.SensorIdx, 1);
	kal_sleep_task(5); /* >= 20ms */
  }
  /* ===== code modify body end ===== */
  
  for (i = 0; i < sizeof(MT9T113I2cAddr) / sizeof(MT9T113I2cAddr[0]); i++)
  {
    CameraSccbSetAddr(CAMERA_SCCB_SENSOR, MT9T113I2cAddr[i]);
    
    /* software reset sensor if needed and read sensor id */
    /* ===== code modify body start ===== */
      SensorId = CamReadCmosSensor(0x0000);
    /* ===== code modify body end ===== */
    
    if (SensorId == MT9T113_SENSOR_ID)
    {
      kal_uint8 Temp;
      
      /* swap the correct i2c address to first one, it will speed up next time read sensor ID */
      Temp = MT9T113I2cAddr[0];
      MT9T113I2cAddr[0] = MT9T113I2cAddr[i];
      MT9T113I2cAddr[i] = Temp;
      break;
    }
  }
  if (SensorId != MT9T113_SENSOR_ID) /* READ SENSOR ID */
  {
#ifdef __MT9T113_DEBUG_TRACE__
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", SensorId);
#endif
  }
  return SensorId;
}

/*************************************************************************
* FUNCTION
*   MT9T113PowerDown
*
* DESCRIPTION
*   This function power down the cmos sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113PowerDown(void)
{
  /* power down sensor through pulling up or down power down pin and reset pin by spec */
  /* ===== code modify body start ===== */
  CamRstPinCtrl(MT9T113Sensor.SensorIdx, 0);
  /* ===== code modify body end ===== */
}

/*************************************************************************
* FUNCTION
*   MT9T113DetectSensorId
*
* DESCRIPTION
*   This function detect sensor id
*
* PARAMETERS
*   None
*
* RETURNS
*   Sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 MT9T113DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM MT9T113SensorClose(void);
  kal_uint32 SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (MT9T113Sensor.SensorIdx)
  {
  case IMAGE_SENSOR_MAIN:
  case IMAGE_SENSOR_BAK1:
    InvIdx = IMAGE_SENSOR_SUB;
    break;
  default:
    InvIdx = IMAGE_SENSOR_MAIN;
    break;
  }
  for (i = 1; i >= 0; i--)
  {
    for (j = 1; j >= 0; j--)
    {
      CamRstPinCtrl(InvIdx, i);
      CamPdnPinCtrl(InvIdx, j);
      SensorId = MT9T113PowerOn();
      MT9T113SensorClose();
      if (MT9T113_SENSOR_ID == SensorId)
      {
        return MT9T113_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*   MT9T113InitOperationPara
*
* DESCRIPTION
*   This function set sensor operation para
*
* PARAMETERS
*   Para
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 0; /* use WaitStableFrameNum instead of this */
  Para->PreviewDelayFrame = MT9T113_PREVIEW_DELAY_FRAME;
  Para->PreviewDisplayWaitFrame = MT9T113_FIRST_PREVIEW_DELAY_FRAME;
}

/*************************************************************************
* FUNCTION
*   MT9T113Preview
*
* DESCRIPTION
*   This function is the most important functions of (Init, Preview & Capture). 
*   1. Apply preview setting, make sensor output preview resolution, e.g. 800x600 for 2M sensor.
*   2. Record video resolution, and set mode based on the isp operation mode.
*   3. Configure the grab window.
*
* PARAMETERS
*   Id, In, Out
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  MT9T113Sensor.Banding = (CAM_BANDING_50HZ == In->BandingFreq ? MT9T113_NUM_50HZ : MT9T113_NUM_60HZ);

  MT9T113PvSetting();
  MT9T113SetMirror(In->ImageMirror);
	
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
	MT9T113NightMode(Id, In);
    break;
  default:
	MT9T113NightMode(Id, In);
	break;
  }
  
  MT9T113AeEnable(KAL_TRUE);
  MT9T113AwbEnable(KAL_TRUE);
  
  Out->WaitStableFrameNum = 3;
  
  Out->GrabStartX = MT9T113_PV_X_START;
  Out->GrabStartY = MT9T113_PV_Y_START;
  Out->ExposureWindowWidth = MT9T113_IMAGE_SENSOR_PV_WIDTH;
  Out->ExposureWindowHeight = MT9T113_IMAGE_SENSOR_PV_HEIGHT;
}

/*************************************************************************
* FUNCTION
*   MT9T113Capture
*
* DESCRIPTION
*   This function is the most important functions of (Init, Preview & Capture). 
*   1. Apply capture setting when capture size greatter then preview size, make sensor output 
*     full size, e.g. 1600x1200 for 2M sensor.
*   2. Increase the dummy pixels or derease pixel clock based on the digital zoom factor and
*    interpolation times.
*   3. Re-Calculate the shutter and sensor gain, to make the exposure value is same with preview
*   4. Configure the grab window based on sensor output.
*
* PARAMETERS
*   Id, In, Out
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9T113Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint32 CapLineLength = 0;

  if (In->ImageTargetWidth <= MT9T113_IMAGE_SENSOR_PV_WIDTH_DRV && In->ImageTargetHeight <= MT9T113_IMAGE_SENSOR_PV_HEIGHT_DRV)
  {
	Out->WaitStableFrameNum = 0;

	Out->GrabStartX = MT9T113_PV_X_START;
	Out->GrabStartY = MT9T113_PV_Y_START;
	Out->ExposureWindowWidth = MT9T113_IMAGE_SENSOR_PV_WIDTH;
	Out->ExposureWindowHeight = MT9T113_IMAGE_SENSOR_PV_HEIGHT;
  }
  else
  {
    /* Disable ae/awb */
    MT9T113AeEnable(KAL_FALSE);
    MT9T113AwbEnable(KAL_FALSE);

    /* set dummy */
    CapLineLength = MT9T113Sensor.IntClk*100000 * MT9T113_FPS(1) / (MT9T113_FULL_PERIOD_LINE_NUMS * In->MaxVideoFrameRate);
    if (CapLineLength < MT9T113_FULL_PERIOD_PIXEL_NUMS)
    {
      CapLineLength = MT9T113_FULL_PERIOD_PIXEL_NUMS;
    }
    if (CapLineLength > MT9T113_MAX_LINELENGTH) /* register limitation */
    {
      CapLineLength = MT9T113_MAX_LINELENGTH;
    }
    MT9T113SetDummy(CapLineLength - MT9T113_FULL_PERIOD_PIXEL_NUMS, 0);
    
    /* Switch to capture mode */
    MT9T113CapSetting();

    Out->WaitStableFrameNum = MT9T113_CAPTURE_DELAY_FRAME;
	
    Out->GrabStartX = MT9T113_FULL_X_START;
    Out->GrabStartY = MT9T113_FULL_Y_START;
    Out->ExposureWindowWidth = MT9T113_IMAGE_SENSOR_FULL_WIDTH;
    Out->ExposureWindowHeight = MT9T113_IMAGE_SENSOR_FULL_HEIGHT;
  }
}

/*************************************************************************
* FUNCTION
*   MT9T113SensorOpen
*
* DESCRIPTION
*   This function read sensor id and init sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113SensorOpen(void)
{
  if (MT9T113PowerOn() != MT9T113_SENSOR_ID)
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
#ifdef MT9T113_LOAD_FROM_T_FLASH
  if (!MT9T113_Initialize_from_T_Flash()) /* for debug use. */
#endif
  {
    MT9T113InitialSetting(); /* apply the sensor initial setting */
  }
  
  /* default setting */
  MT9T113Sensor.BypassAe = KAL_FALSE;
  MT9T113Sensor.BypassAwb = KAL_FALSE;
  MT9T113Sensor.PvMode = KAL_TRUE;
  MT9T113Sensor.Banding = MT9T113_NUM_50HZ;
  MT9T113Sensor.VideoFps = 0;
  MT9T113Sensor.IntClk = 0;
  MT9T113Sensor.Shutter = MT9T113ReadShutter();
  MT9T113Sensor.Gain = MT9T113ReadGain();
  MT9T113Sensor.FrameHeight = 0;
  MT9T113Sensor.LineLength = 0;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113SensorFeatureCtrl
*
* DESCRIPTION
*   This function set sensor feature mode
*
* PARAMETERS
*   Id: scenario id
*   In: input parameter
*   Out: output parameter
*   OutLen: output parameter length
*   RealOutLen: real output parameter length
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return MT9T113WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
  /* query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = MT9T113Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = MT9T113Contrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SATURATION:
    ErrCode = MT9T113Saturation(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SHARPNESS:
    ErrCode = MT9T113Sharpness(In, Out);
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = MT9T113Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = MT9T113Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = MT9T113StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
    ErrCode = MT9T113Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = MT9T113SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = MT9T113SceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    MT9T113GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MT9T113DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MT9T113Sensor.VideoFps;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    MT9T113InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(MT9T113Sensor.SensorIdx, Out);
    break;
#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
    case IMAGE_SENSOR_FEATURE_GET_EV_AWB_REF:
        MT9T113GetEvAwbRef(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_SHUTTER_GAIN_AWB_GAIN:
        MT9T113GetCurAeAwbInfo(Out);
        break;
    case IMAGE_SENSOR_FEATURE_SET_SCENE_ENHANCE:
    {
        CAL_FEATURE_CTRL_STRUCT Para;

        Para.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneContrast;
        MT9T113Contrast(&Para, NULL);
        Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSaturation;
        MT9T113Saturation(&Para, NULL);
        Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSharpness;
        MT9T113Sharpness(&Para, NULL);
        break;
    }
#endif
  
  /* set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    MT9T113PowerDown();
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    MT9T113Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    MT9T113Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    MT9T113Sensor.BypassAe = *(kal_bool *)In;
    MT9T113AeEnable(MT9T113Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    MT9T113Sensor.BypassAwb = *(kal_bool *)In;
    MT9T113AwbEnable(MT9T113Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*   MT9T113SensorCtrl
*
* DESCRIPTION
*   This function set sensor scenario mode
*
* PARAMETERS
*   Id: scenario id
*   In/Out: parameter
*   OutLen: out parameter length
*   RealOutLen: real out parameter length
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    MT9T113Preview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    MT9T113Capture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113SensorClose
*
* DESCRIPTION
*   This function is to turn off sensor module power.
*
* PARAMETERS
*   None
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9T113SensorClose(void)
{
  MT9T113PowerDown();
  CisModulePowerOn(MT9T113Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   MT9T113SensorFunc
*
* DESCRIPTION
*   This function get sensor function pointer
*
* PARAMETERS
*   Sensor function pointer
*
* RETURNS
*   Error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM MT9T113SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncMT9T113 =
  {
    MT9T113SensorOpen,
    MT9T113SensorFeatureCtrl,
    MT9T113SensorCtrl,
    MT9T113SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncMT9T113;
  
  return MM_ERROR_NONE;
}

#ifdef __MT9T113_DEBUG_TRACE__
void at_func_test(kal_uint32 *Data)
{
  if (!Data[0]) return;
  switch (Data[1])
  {
  case 0x02:
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "Read BB Reg %x = %x", Data[2], DRV_Reg32(Data[2]));
    break;
  case 0x03:
    DRV_Reg32(Data[2]) = Data[3];
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "Write BB Reg %x = %x", Data[2], DRV_Reg32(Data[2]));
    break;
  case 0x04:
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "Read Sensor %x = %x", Data[2], CamReadCmosSensor(Data[2]));
    break;
  case 0x05:
    CamWriteCmosSensor(Data[2], Data[3]);
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "Write Sensor %x = %x", Data[2], CamReadCmosSensor(Data[2]));
    break;
  case 0x06:
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "Read Sensor16 %x = %x", Data[2], (CamReadCmosSensor(Data[2]) << 8)|CamReadCmosSensor(Data[2] + 1));
    break;
  case 0x07:
    CamWriteCmosSensor(Data[2], Data[3] >> 8);
    CamWriteCmosSensor(Data[2] + 1, Data[3]);
    kal_print_string_trace(MOD_ENG, TRACE_INFO, "Write Sensor16 %x = %x", Data[2], (CamReadCmosSensor(Data[2]) << 8)|CamReadCmosSensor(Data[2] + 1));
    break;
  case 0x08:
    CamWriteCmosSensor(0x098C, Data[2]);
    kal_print_string_trace(MOD_ENG, TRACE_INFO, "Read XDMA %x = %x", Data[2], CamReadCmosSensor(0x0990));
    break;
  case 0x09:
    CamWriteCmosSensor(0x098C, Data[2]);
    CamWriteCmosSensor(0x0990, Data[3]);
    CamWriteCmosSensor(0x098C, Data[2]);
    kal_print_string_trace(MOD_ENG, TRACE_INFO, "Write XDMA %x = %x", Data[2], CamReadCmosSensor(0x0990));
    break;
  case 0x0A:
    break;
  case 0x0B:
    break;
  case 0x0C:
    
    break;
  case 0x10:
    {
      kal_uint32 i;
      
      for (i = Data[2]; i < Data[3]; i++)
      {
        kal_print_string_trace(MOD_ENG, TRACE_INFO, "reg[%x] = %x", i, CamReadCmosSensor(i));
        if (!(i % 200))
        {
          kal_sleep_task(30);
        }
      }
    }
    break;
  case 0x11:
  
  case 0x12:
    {
      kal_uint32 i;
      
      for (i = 0; i < Data[3]; i++)
      {
        kal_print_string_trace(MOD_ENG, TRACE_INFO, "reg[%x] = %x", Data[2] + i * 4, DRV_Reg32(Data[2] + i * 4));
        if (!(i % 200))
        {
          kal_sleep_task(30);
        }
      }
    }
    break;
  default:
    break;
  }
}
#endif	/* #ifdef __MT9T113_DEBUG_TRACE__ */


