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
 *   image_sensor_GC6113_SERIAL.c
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
 *
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

  kal_bool CapState; /* KAL_TRUE: in capture state, else in preview state */
  kal_bool PvMode; /* KAL_TRUE: in preview mode, else in capture mode */
  //kal_uint8 BandingFreq; /* 100 or 120 for 50Hz/60Hz */
  
  kal_uint32 InternalClock; /* internal clock which using process pixel(for exposure) */
  kal_uint32 Pclk; /* output clock which output to baseband */
  kal_uint32 Gain; /* base on 0x40 */
  kal_uint32 Shutter; /* unit is (linelength / internal clock) s */
  
  kal_uint32 FrameLength; /* total line numbers in one frame(include dummy line) */
  kal_uint32 LineLength; /* total pixel numbers in one line(include dummy pixel) */
  
  //IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  	sensor_data_struct *NvramData;

  	kal_uint16 MinFrameRate;	/* 150 means 15.0fps. */
	kal_uint16 MaxFrameRate;	/* 300 means 30.0fps. */

	kal_uint32 dummy_lines;
    kal_uint32 dummy_pixels;

	kal_uint32 curr_frame_time;	/* It's get from the TG Int. */
	
    IMAGE_SENSOR_INDEX_ENUM SensorIdx;
	CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq; /* GC6113_SERIAL_50HZ or GC6113_SERIAL_60HZ for 50Hz/60Hz */

	kal_bool sccb_opened;			/* The I2C can work when sccb_opened is KAL_TRUE */
} GC6113_SERIALSensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

#ifdef GC6113_SERIAL_LOAD_FROM_T_FLASH
/*************************************************************************
* FUNCTION
*  GC6113_SERIAL_Initialize_from_T_Flash
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
static kal_uint8 GC6113_SERIAL_Initialize_from_T_Flash()
{
#include "med_utility.h"
#include "fs_type.h"

#if GC6113_SERIAL_I2C_ADDR_BITS == CAMERA_SCCB_16BIT
  #define GC6113_SERIAL_REG_SKIP    0x08
#else
  #define GC6113_SERIAL_REG_SKIP    0x06
#endif
#if GC6113_SERIAL_I2C_DATA_BITS == CAMERA_SCCB_16BIT
  #define GC6113_SERIAL_VAL_SKIP    0x08
#else
  #define GC6113_SERIAL_VAL_SKIP    0x06
#endif
  
  /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
  #define GC6113_SERIAL_OP_CODE_INI    0x00    /* Initial value. */
  #define GC6113_SERIAL_OP_CODE_REG    0x01    /* Register */
  #define GC6113_SERIAL_OP_CODE_DLY    0x02    /* Delay */
  #define GC6113_SERIAL_OP_CODE_END    0x03    /* End of initial setting. */
  
  typedef struct
  {
    kal_uint16 init_reg;
    kal_uint16 init_val;  /* Save the register value and delay tick */
    kal_uint8 op_code;    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
  } GC6113_SERIAL_initial_set_struct;
  
  static GC6113_SERIAL_initial_set_struct GC6113_SERIAL_Init_Reg[1000];
  static WCHAR GC6113_SERIAL_set_file_name[256] = {0};
  FS_HANDLE fp = -1;        /* Default, no file opened. */
  kal_uint8 *data_buff = NULL;
  kal_uint8 *curr_ptr = NULL;
  kal_uint32 file_size = 0;
  kal_uint32 bytes_read = 0;
  kal_uint32 i = 0, j = 0;
  kal_uint8 func_ind[3] = {0};  /* REG or DLY */
  
  kal_mem_cpy(GC6113_SERIAL_set_file_name, L"C:\\GC6113_SERIAL_Initialize_Setting.Bin", sizeof(L"C:\\GC6113_SERIAL_Initialize_Setting.Bin"));
  
  /* Search the setting file in all of the user disk. */
  curr_ptr = (kal_uint8 *)GC6113_SERIAL_set_file_name;
  while (fp < 0)
  {
    if ((*curr_ptr >= 'c' && *curr_ptr <= 'z') || (*curr_ptr >= 'C' && *curr_ptr <= 'Z'))
    {
      fp = FS_Open(GC6113_SERIAL_set_file_name, FS_READ_ONLY);
      if (fp >= 0)
      {
        break;      /* Find the setting file. */
      }

      *curr_ptr = *curr_ptr + 1;
    }
    else
    {
      break ;
    }
  }
  
  if (fp < 0)    /* Error handle */
  {
    GC6113_SERIAL_TRACE("!!! Warning, Can't find the initial setting file!!!");
    return 0;
  }

  FS_GetFileSize(fp, &file_size);
  if (file_size < 20)
  {
    GC6113_SERIAL_TRACE("!!! Warning, Invalid setting file!!!");
    return 0;      /* Invalid setting file. */
  }

  data_buff = med_alloc_ext_mem(file_size);
  if (data_buff == NULL)
  {
    GC6113_SERIAL_TRACE("!!! Warning, Memory not enoughed...");
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
      GC6113_SERIAL_Init_Reg[i].op_code = GC6113_SERIAL_OP_CODE_REG;
      
      GC6113_SERIAL_Init_Reg[i].init_reg = strtol((const char *)curr_ptr, NULL, 16);
      curr_ptr += GC6113_SERIAL_REG_SKIP;  /* Skip "0x0000, " */
      
      GC6113_SERIAL_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 16);
      curr_ptr += GC6113_SERIAL_VAL_SKIP;  /* Skip "0x0000);" */
    }
    else                  /* DLY */
    {
      /* Need add delay for this setting. */
      GC6113_SERIAL_Init_Reg[i].op_code = GC6113_SERIAL_OP_CODE_DLY;
      
      GC6113_SERIAL_Init_Reg[i].init_reg = 0xFF;
      GC6113_SERIAL_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 10);  /* Get the delay ticks, the delay should less then 50 */
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
  GC6113_SERIAL_Init_Reg[i].op_code = GC6113_SERIAL_OP_CODE_END;
  GC6113_SERIAL_Init_Reg[i].init_reg = 0xFF;
  GC6113_SERIAL_Init_Reg[i].init_val = 0xFF;
  i++;
  
  GC6113_SERIAL_TRACE("%d register read...", i - 1);
  med_free_ext_mem((void **)&data_buff);
  FS_Close(fp);
  
  GC6113_SERIAL_TRACE("Start apply initialize setting.");
  /* Start apply the initial setting to sensor. */
  for (j=0; j<i; j++)
  {
    if (GC6113_SERIAL_Init_Reg[j].op_code == GC6113_SERIAL_OP_CODE_END)  /* End of the setting. */
    {
      break ;
    }
    else if (GC6113_SERIAL_Init_Reg[j].op_code == GC6113_SERIAL_OP_CODE_DLY)
    {
      kal_sleep_task(GC6113_SERIAL_Init_Reg[j].init_val);    /* Delay */
    }
    else if (GC6113_SERIAL_Init_Reg[j].op_code == GC6113_SERIAL_OP_CODE_REG)
    {
      CamWriteCmosSensor(GC6113_SERIAL_Init_Reg[j].init_reg, GC6113_SERIAL_Init_Reg[j].init_val);
    }
    else
    {
      ASSERT(0);
    }
  }
  GC6113_SERIAL_TRACE("%d register applied...", j);
  return 1;  
}
#endif

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSetMirror
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
static void GC6113_SERIALSetMirror(kal_uint8 Mirror)
{
  kal_uint8 CntrB;
  
  CamWriteCmosSensor(0xFE, 0x00);	/* Page 0 */
  switch (Mirror)
  {
  case IMAGE_SENSOR_MIRROR_NORMAL:
  	CamWriteCmosSensor(0x14, 0x10); 
    break;
  case IMAGE_SENSOR_MIRROR_H:
    CamWriteCmosSensor(0x14, 0x11); 
    break;
  case IMAGE_SENSOR_MIRROR_V:
    CamWriteCmosSensor(0x14, 0x12); 
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    CamWriteCmosSensor(0x14, 0x13); 
    break;
  default:
    /* no need to do error handling */
    break;
  }
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSetClock
*
* DESCRIPTION
*   This function set sensor internal clock and output clock
*
* PARAMETERS
*   Clk: internal clock
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6113_SERIALSetClock(kal_uint32 InternalClock)
{
  GC6113_SERIAL_CHECK_AND_SET(InternalClock, InternalClock, ); /* the 3rd parameter is none for void function */
  // TODO: set internal clock(use process pixel) and output clock(ouput to baseband) here
  {
    /* [7:4] Control Fref Clock Frequency. (Fref Range = 9MHz~18MHz)
          Fref = MCLK / (GB_PRE_DIV[3:0] + 1)
        [2:0] Control Fvco Clock Frequency. (Fvco Range = 144MHz~288MHz)
          Fvco = (Fref x 16 ) / (2 * (GB_POST_DIVE[2:0] +1))
        PCLK = Fvco / 2
    */
    CamWriteCmosSensor(0x00, 0x00);
    switch (InternalClock)
    {
#if GC6113_SERIAL_MCLK == 24000000
    case 16000000: /* MCLK: 24M, INTERNAL CLK: 16M, PCLK: 32M */
      GC6113_SERIALSensor.Pclk = 32000000;
      CamWriteCmosSensor(0x0A, 0x12); /* group B */
      break;
    case 24000000: /* MCLK: 24M, INTERNAL CLK: 24M, PCLK: 48M */
      GC6113_SERIALSensor.Pclk = 48000000;
      CamWriteCmosSensor(0x0A, 0x11);
      break;
    default: /* MCLK: 24M, INTERNAL CLK: 24M, PCLK: 48M */
      GC6113_SERIAL_TRACE("clock: %dHz error!!!", InternalClock);
      GC6113_SERIALSensor.Pclk = 48000000;
      CamWriteCmosSensor(0x0A, 0x11);
      break;
#else
    case 13000000: /* MCLK: 26M, INTERNAL CLK: 13M, PCLK: 26M */
      GC6113_SERIALSensor.Pclk = 26000000;
      CamWriteCmosSensor(0x0A, 0x13); /* group B */
      break;
    case 26000000: /* MCLK: 26M, INTERNAL CLK: 26M, PCLK: 52M */
      GC6113_SERIALSensor.Pclk = 52000000;
      CamWriteCmosSensor(0x0A, 0x11);
      break;
    case 17333333: /* MCLK: 26M, INTERNAL CLK: 17.3M, PCLK: 34.67M */
      GC6113_SERIALSensor.Pclk = 34666667;
      CamWriteCmosSensor(0x0A, 0x12);
      break;
    default: /* MCLK: 26M, INTERNAL CLK: 17.3M, PCLK: 34.67M */
      GC6113_SERIAL_TRACE("clock: %dHz error!!!", InternalClock);
      GC6113_SERIALSensor.Pclk = 34666667;
      CamWriteCmosSensor(0x0A, 0x12);
      break;
#endif
    }
  }
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALWriteShutter
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
static void GC6113_SERIALWriteShutter(kal_uint32 Shutter)
{
  // TODO: set integration time here
  return ;
  
  CamWriteCmosSensor(0x00, 0x01);
  CamWriteCmosSensor(0x30, Shutter >> 8);
  CamWriteCmosSensor(0x31, Shutter);
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALReadShutter
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
static kal_uint32 GC6113_SERIALReadShutter(void)
{
  // TODO: read integration time here
  return 0;
  
  CamWriteCmosSensor(0x00, 0x01);
  return (CamReadCmosSensor(0x30) << 8)|CamReadCmosSensor(0x31);
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALWriteGain
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
static void GC6113_SERIALWriteGain(kal_uint32 Gain)
{
  // TODO: set global gain here
  kal_uint8 Reg = 0;

  return ;
  
  if (Gain > 32 * 0x40 - 0x20) /* max 31.5x */
  {
    ASSERT(0);
  }
  while (Gain >= 0x40 * 2)
  {
    Reg++;
    Gain >>= 1;
  }
  Reg <<= 5;
  if (Gain >= 0x40)
  {
    Reg |= ((Gain - 0x40) >> 1);
  }
  CamWriteCmosSensor(0x00, 0x01);
  CamWriteCmosSensor(0x32, Reg);
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALReadGain
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
static kal_uint32 GC6113_SERIALReadGain(void)
{
  // TODO: read global gain here
  kal_uint8 Reg;

  return 0;
  
  CamWriteCmosSensor(0x00, 0x01);
  Reg = CamReadCmosSensor(0x32);
  if (Reg > 0x9F)
  {
    Reg &= 0x9F;
  }
  return ((((Reg&0x1F) << 1) + 0x40) << (Reg >> 5));
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALAeEnable
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
static void GC6113_SERIALAeEnable(kal_bool Enable)
{
  if (GC6113_SERIALSensor.BypassAe && GC6113_SERIALSensor.PvMode)
  {
    Enable = KAL_FALSE;
  }

  {
  	kal_uint16 temp_AE_reg = 0;
	
    CamWriteCmosSensor(0xfe, 0x00);	
	temp_AE_reg = CamReadCmosSensor(0xe5);
    
    /* should not enable bit2(adjust BLC) else cause brightness different in pv/cap */
    if (Enable)
    {
      CamWriteCmosSensor(0xe5, (temp_AE_reg | 0x01));	/* Turn ON AEC/AGC*/
    }
    else
    {
      CamWriteCmosSensor(0xe5, (temp_AE_reg&(~0x01))); /* Turn OFF AEC/AGC*/
    }
  }
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALAwbEnable
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
static void GC6113_SERIALAwbEnable(kal_bool Enable)
{
  if (GC6113_SERIALSensor.BypassAwb && GC6113_SERIALSensor.PvMode)
  {
    Enable = KAL_FALSE;
  }

  {
  	kal_uint16 temp_AWB_reg = 0;
	
    CamWriteCmosSensor(0xfe, 0x00);	
	temp_AWB_reg = CamReadCmosSensor(0x22);
    
    if (Enable)
    {
      CamWriteCmosSensor(0x22, (temp_AWB_reg | 0x02));
    }
    else
    {
      CamWriteCmosSensor(0x22, (temp_AWB_reg& ~0x02));
    }
  }
}


/*************************************************************************
* FUNCTION
*   GC6113_SERIALSetBandingStep
*
* DESCRIPTION
*   This function is to calculate & set shutter step register .
*
*************************************************************************/
static void GC6113_SERIALSetBandingStep(CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq)
{
    kal_uint32 sensor_pclk = 0, base_shutter = 0;

	sensor_pclk = GC6113_SERIALSensor.Pclk;

	GC6113_SERIALSensor.BandingFreq = BandingFreq;

	switch (BandingFreq)
	{
	case CAM_BANDING_50HZ:
		base_shutter = (sensor_pclk) / ((GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels) * 2) / 100;
		break;
		
	case CAM_BANDING_60HZ:
		base_shutter = (sensor_pclk) / ((GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels) * 2) / 120;
		break;
		
	default:
		/* Enable Auto Anti-Flicker if the sensor support it. */
		return ;
	}

	CamWriteCmosSensor(0xfe, 0x01);	// Page 1
	CamWriteCmosSensor(0x42, (base_shutter >> 8) & 0x0F); // SEt Flicker Step.
	CamWriteCmosSensor(0x43, (base_shutter & 0xFF));
	
    GC6113_SERIAL_TRACE("Set Shutter Step:%x", base_shutter);
}/* GC6113_SERIALSetBandingStep */


/*************************************************************************
* FUNCTION
*   GC6113_SERIALSetDummy
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
static void GC6113_SERIALSetDummy(kal_uint32 DummyPixel, kal_uint32 DummyLine)
{
	kal_uint32 sensor_pclk = 0, base_shutter = 0;

	/*
	* Line length = win_width(Reg[0.0x0b], reg[0.0x0c]) + sh_delay[0.0x12] + 4 + HB[0.0x0F, 0.0x01]
	* Frame length = 
	*	if exp_time(Reg[0.0x03], Reg[0.0x04]) <= win_height(Reg[0.0x09], Reg[0x0a]) + VB([0.0x0f], Reg[0.0x02])
			frame_length = win_height + VB
		else
			frame_length = exp_time.
	*/

	DummyPixel += 240*4;
	DummyLine += 0x08;
	
	if (DummyPixel > GC6113_SERIAL_MAX_LINELENGTH)
	{
		DummyPixel = GC6113_SERIAL_MAX_LINELENGTH;
	}
	if (DummyLine > GC6113_SERIAL_MAX_FRAMELENGTH)
	{
		DummyLine = GC6113_SERIAL_MAX_FRAMELENGTH;
	}

	/* NOTICE:  HB >= 240*8, VB >= 8 */
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0x01, (DummyPixel & 0xFF)); 
	CamWriteCmosSensor(0x02, (DummyLine & 0xFF));
	CamWriteCmosSensor(0x0f, ((DummyPixel >> 8) & 0x0F) | ((DummyLine >> 4) & 0xF0));

	/* Re-calculate the flicker step (Base Shutter). */
	sensor_pclk = GC6113_SERIALSensor.Pclk;
	if (GC6113_SERIALSensor.BandingFreq == CAM_BANDING_50HZ)
	{
		/* 50Hz base shutter */
		base_shutter = (sensor_pclk) / ((GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels) * 2) / 100;
	}
	else
	{
		/* 60Hz base shutter */
		base_shutter = (sensor_pclk) / ((GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels) * 2) / 120;
	}

	CamWriteCmosSensor(0xfe, 0x01);	// Page 1
	CamWriteCmosSensor(0x42, (base_shutter >> 8) & 0x0F); // SEt Flicker Step.
	CamWriteCmosSensor(0x43, (base_shutter & 0xFF));
}


/*************************************************************************
* FUNCTION
*   GC6113_SERIALSetMaxShutterStep
*
* DESCRIPTION
*   This function is to set frame count register .
*
*************************************************************************/
static void GC6113_SERIALSetMaxShutterStep(CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq, kal_uint32 MinFrameRate)
{
	kal_uint32 Max_aec_exposure_level = 0;
	kal_uint32 sensor_pclk = 0;

	sensor_pclk = GC6113_SERIALSensor.Pclk;
	
    CamWriteCmosSensor(0xfe, 0x01);

	Max_aec_exposure_level = (sensor_pclk) / ((GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels) * 2) / MinFrameRate / GC6113_SERIAL_FRAME_RATE_UNIT;
	CamWriteCmosSensor(0x4a, (Max_aec_exposure_level >> 8) & 0xFF);	// level 3
	CamWriteCmosSensor(0x4b, Max_aec_exposure_level & 0xFF);	// 24Mhz, 5fps.

	GC6113_SERIAL_TRACE("MinFrameRate:%d, max_shutter_step:%x", MinFrameRate, Max_aec_exposure_level);
}/* GC6113_SERIALSetMaxShutterStep */



/*************************************************************************
* FUNCTION
*   GC6113_SERIALSetFixFrameRate
*
* DESCRIPTION
*   This function fix the frame rate of image sensor.
*
*************************************************************************/
 static void GC6113_SERIALSetFixFrameRate(kal_bool IsFixFrameRate)
 {
	CamWriteCmosSensor(0xfe, 0x01);
	if (IsFixFrameRate == KAL_TRUE)
	{
		 /* Fix frame rate, limit the max exposure time to frame length. */
		CamWriteCmosSensor(0x4c, 0x00);
	}
	else
	{
		 CamWriteCmosSensor(0x4c, 0x20);	// Max AEC Exposure level 2
	}
 }	/* GC6113_SERIALSetFixFrameRate */


/*************************************************************************
* FUNCTION
*    GC6113_SERIALSetFrameRate
*
* DESCRIPTION
*    This function calculate & set frame rate and fix frame rate when video mode
*    MUST BE INVOKED AFTER SIM120C_preview() !!!
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6113_SERIALSetFrameRate(kal_uint32 MinFrameRate, kal_uint32 MaxFrameRate)
{
    kal_uint32 line_length = 0;
	kal_uint32 frame_length = 0;
	
	GC6113_SERIAL_TRACE("[Target] MinFrameRate:%d, MaxFrameRate:%d", MinFrameRate, MaxFrameRate);
	
	//4 Step 1 Set the max frame rate
    line_length = GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels;

    frame_length = GC6113_SERIALSensor.Pclk * GC6113_SERIAL_FRAME_RATE_UNIT / (2 * line_length * MaxFrameRate);
	if (frame_length < GC6113_SERIAL_PV_PERIOD_LINE_NUMS)
	{
		frame_length = GC6113_SERIAL_PV_PERIOD_LINE_NUMS;

		GC6113_SERIAL_TRACE("Warining!!! Target frame rate exeed sensor limitation: tar=%d, lim=%d", \
			MaxFrameRate, GC6113_SERIALSensor.Pclk*GC6113_SERIAL_FRAME_RATE_UNIT / line_length*2 / frame_length);

		MaxFrameRate = GC6113_SERIALSensor.Pclk*GC6113_SERIAL_FRAME_RATE_UNIT / ((GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels) * 2) / (GC6113_SERIAL_PV_PERIOD_LINE_NUMS + GC6113_SERIALSensor.dummy_lines);
	}
	
    if (frame_length > (GC6113_SERIAL_PV_PERIOD_LINE_NUMS + 0xFFF))
    {
        frame_length = GC6113_SERIAL_PV_PERIOD_LINE_NUMS + 0xFFF;
        line_length = GC6113_SERIALSensor.Pclk * GC6113_SERIAL_FRAME_RATE_UNIT / (2 * frame_length * MaxFrameRate);
    }

    GC6113_SERIALSetDummy(line_length-GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS, frame_length-GC6113_SERIAL_PV_PERIOD_LINE_NUMS);

	CamWriteCmosSensor(0xfe, 0x01);
	CamWriteCmosSensor(0x44, (frame_length & 0xFF00) >> 8);
	CamWriteCmosSensor(0x45, frame_length & 0xFF);

	//4 Step 2 Set the minmum frame rate
	GC6113_SERIALSetMaxShutterStep(GC6113_SERIALSensor.BandingFreq, MinFrameRate);

	//4 Step 3 Fix the frame rate.
	if (MinFrameRate == MaxFrameRate)
	{
		GC6113_SERIALSetFixFrameRate(KAL_TRUE);
	}
	else
	{
		GC6113_SERIALSetFixFrameRate(KAL_FALSE);
	}
}



/*************************************************************************
* FUNCTION
*   GC6113_SERIALSetNightMode
*
* DESCRIPTION
*   This function switch on/off night mode of GC6113_SERIAL.
*
*************************************************************************/
MM_ERROR_CODE_ENUM GC6113_SERIALSetNightMode(CAL_SCENARIO_ENUM ScenarioId, 
								kal_bool night_enalbe)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	kal_uint32 Max_aec_exposure_level = 0;
	kal_uint32 sensor_pclk = 0;

	sensor_pclk = GC6113_SERIALSensor.Pclk;

    GC6113_SERIAL_TRACE("NightMode %d", night_enalbe);

	if (KAL_TRUE == night_enalbe)
	{
		switch (ScenarioId)
		{
		case CAL_SCENARIO_VIDEO:
			// Do nothing
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			CamWriteCmosSensor(0xfe, 0x01);

			Max_aec_exposure_level = (sensor_pclk) / ((GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels) * 2) / 5;
			CamWriteCmosSensor(0x4a, (Max_aec_exposure_level >> 8) & 0xFF);	// level 3
			CamWriteCmosSensor(0x4b, Max_aec_exposure_level & 0xFF);	// 24Mhz, 5fps.
			CamWriteCmosSensor(0x4c, 0x30);	// Max AEC Exposure level 3
			break;
		default:
			ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
		}
	}
	else
	{
		switch (ScenarioId)
		{
		case CAL_SCENARIO_VIDEO:
			// Do nothing
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			CamWriteCmosSensor(0xfe, 0x01);

			Max_aec_exposure_level = (sensor_pclk) / ((GC6113_SERIAL_PV_PERIOD_PIXEL_NUMS + GC6113_SERIALSensor.dummy_pixels) * 2) / 10;
			CamWriteCmosSensor(0x48, (Max_aec_exposure_level >> 8) & 0xFF);	// level 2
			CamWriteCmosSensor(0x49, Max_aec_exposure_level & 0xFF);	// 24Mhz, 10fps.
			CamWriteCmosSensor(0x4c, 0x20);	// Max AEC Exposure level 2
			break;
		default:
			ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
		}
	}

	return ErrCode;
}   /* GC6113_SERIALSetNightMode */

/*************************************************************************
* FUNCTION
*   GC6113_SERIALEv
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
static MM_ERROR_CODE_ENUM GC6113_SERIALEv(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Exposure = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

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
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x58);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0xc0);
      break;
    case CAM_EV_NEG_3_3:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x60);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0xd0);
      break;
    case CAM_EV_NEG_2_3:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x68);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0xe0);
      break;
    case CAM_EV_NEG_1_3:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x70);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0xf0);
      break;
    case CAM_EV_ZERO:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x78);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0x00);
      break;
    case CAM_EV_POS_1_3:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x80);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0x10);
      break;
    case CAM_EV_POS_2_3:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x88);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0x20);
      break;
    case CAM_EV_POS_3_3:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x90);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0x30);
      break;
    case CAM_EV_POS_4_3:
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x98);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0xb5, 0x40);
      break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALContrast
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
static MM_ERROR_CODE_ENUM GC6113_SERIALContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

    Contrast->IsSupport = KAL_TRUE;
    Contrast->ItemCount = 3;
    Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
    Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
  	CamWriteCmosSensor(0xfe, 0x00);
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:
		CamWriteCmosSensor(0xb3, 0x48);
      break;
    case CAM_CONTRAST_MEDIUM:
		CamWriteCmosSensor(0xb3, 0x40);
      break;
    case CAM_CONTRAST_LOW:
		CamWriteCmosSensor(0xb3, 0x38);
      break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSaturation
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
static MM_ERROR_CODE_ENUM GC6113_SERIALSaturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Saturation = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    // TODO: add supported saturation enum here
    Saturation->IsSupport = KAL_FALSE;
    //Saturation->ItemCount = 3;
    //Saturation->SupportItem[0] = CAM_SATURATION_HIGH;
    //Saturation->SupportItem[1] = CAM_SATURATION_MEDIUM;
    //Saturation->SupportItem[2] = CAM_SATURATION_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    // TODO: adjust saturation here
    //switch (In->FeatureSetValue)
    //{
    //case CAM_SATURATION_HIGH:
    //  break;
    //case CAM_SATURATION_MEDIUM:
    //  break;
    //case CAM_SATURATION_LOW:
    //  break;
    //default:
    //  return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    //}
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSharpness
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
static MM_ERROR_CODE_ENUM GC6113_SERIALSharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Sharpness = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    // TODO: add supported sharpness enum here
    Sharpness->IsSupport = KAL_FALSE;
    //Sharpness->ItemCount = 3;
    //Sharpness->SupportItem[0] = CAM_SHARPNESS_HIGH;
    //Sharpness->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
    //Sharpness->SupportItem[2] = CAM_SHARPNESS_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    // TODO: adjust sharpness here
    //switch (In->FeatureSetValue)
    //{
    //case CAM_SHARPNESS_HIGH:
    //  break;
    //case CAM_SHARPNESS_MEDIUM:
    //  break;
    //case CAM_SHARPNESS_LOW:
    //  break;
    //default:
    //  return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    //}
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALWb
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
static MM_ERROR_CODE_ENUM GC6113_SERIALWb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Wb = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

    Wb->IsSupport = KAL_TRUE;
    Wb->ItemCount = 6;
    Wb->SupportItem[0] = CAM_WB_AUTO;
    Wb->SupportItem[1] = CAM_WB_CLOUD;
    Wb->SupportItem[2] = CAM_WB_DAYLIGHT;
    Wb->SupportItem[3] = CAM_WB_INCANDESCENCE;
    Wb->SupportItem[4] = CAM_WB_FLUORESCENT;
    Wb->SupportItem[5] = CAM_WB_TUNGSTEN;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
	CamWriteCmosSensor(0xfe, 0x00);
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO:
      GC6113_SERIALAwbEnable(KAL_TRUE);
      break;
    case CAM_WB_CLOUD:
      GC6113_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x5a, 0x8c);
		CamWriteCmosSensor(0x5b, 0x50);
		CamWriteCmosSensor(0x5c, 0x40);
      break;
    case CAM_WB_DAYLIGHT:
      GC6113_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x5a, 0x74);
		CamWriteCmosSensor(0x5b, 0x52);
		CamWriteCmosSensor(0x5c, 0x40);
      break;
    case CAM_WB_INCANDESCENCE:
      GC6113_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x5a, 0x48);
		CamWriteCmosSensor(0x5b, 0x40);
		CamWriteCmosSensor(0x5c, 0x5c);
      break;
    case CAM_WB_FLUORESCENT:
      GC6113_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x5a, 0x40);
		CamWriteCmosSensor(0x5b, 0x42);
		CamWriteCmosSensor(0x5c, 0x50);
      break;
    case CAM_WB_TUNGSTEN:
      GC6113_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x5a, 0x40);
		CamWriteCmosSensor(0x5b, 0x54);
		CamWriteCmosSensor(0x5c, 0x70);
      break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALEffect
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
static MM_ERROR_CODE_ENUM GC6113_SERIALEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Effect = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

    Effect->IsSupport = KAL_TRUE;
    Effect->ItemCount = 6;
    Effect->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    Effect->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    Effect->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    Effect->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    Effect->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    Effect->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
  	CamWriteCmosSensor(0xfe, 0x00);
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
		CamWriteCmosSensor(0x23, 0x00);
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
		CamWriteCmosSensor(0x23, 0x02);
		CamWriteCmosSensor(0xba, 0x00);
		CamWriteCmosSensor(0xbb, 0x00);
      break;
    case CAM_EFFECT_ENC_SEPIA:
		CamWriteCmosSensor(0x23, 0x02);
		CamWriteCmosSensor(0xba, 0xd0);
		CamWriteCmosSensor(0xbb, 0x28);
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
		CamWriteCmosSensor(0x23, 0x02);
		CamWriteCmosSensor(0xba, 0xe8);
		CamWriteCmosSensor(0xbb, 0xf8);
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
		CamWriteCmosSensor(0x23, 0x02);
		CamWriteCmosSensor(0xba, 0x50);
		CamWriteCmosSensor(0xbb, 0xe0);
      break;
    case CAM_EFFECT_ENC_COLORINV:
		CamWriteCmosSensor(0x23, 0x01);
      break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALStillCaptureSize
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
MM_ERROR_CODE_ENUM GC6113_SERIALStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 2;
    CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_QVGA;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALBanding
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
static MM_ERROR_CODE_ENUM GC6113_SERIALBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
	   GC6113_SERIALSetBandingStep((CAL_CAMERA_BANDING_FREQ_ENUM)(In->FeatureSetValue));
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSceneMode
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
static MM_ERROR_CODE_ENUM GC6113_SERIALSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT SceneMode = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    SceneMode->IsSupport = KAL_TRUE;
    SceneMode->ItemCount = 2;
    if (IsCam)
    {
      SceneMode->SupportItem[0] = CAM_AUTO_DSC;
      SceneMode->SupportItem[1] = CAM_NIGHTSCENE;
    }
    else
    {
      SceneMode->SupportItem[0] = CAM_VIDEO_AUTO;
      SceneMode->SupportItem[1] = CAM_VIDEO_NIGHT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALInitialSetting
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
static void GC6113_SERIALInitialSetting(void)
{
	
	CamWriteCmosSensor(0xfe, 0x80);
	CamWriteCmosSensor(0xfc, 0x12); //clk_en
	CamWriteCmosSensor(0xfa, 0x10); // Cis clock config.
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0x09, 0x01); //[8]cis_win_height  486,1e6
	CamWriteCmosSensor(0x0a, 0x48); //[7:0]cis_win_height
	CamWriteCmosSensor(0x0b, 0x00); //[9:8]cis_win_width 646,286
	CamWriteCmosSensor(0x0c, 0xf8); //[7:0]cis_win_width
	CamWriteCmosSensor(0x12, 0x2a); //sh_delay
	CamWriteCmosSensor(0x14, 0x10); 
	CamWriteCmosSensor(0x16, 0x06); //[3:0]number of a/d pipe stages 
	CamWriteCmosSensor(0x1c, 0x49);	//0x41
	CamWriteCmosSensor(0x1d, 0xa5);	//95
	CamWriteCmosSensor(0x20, 0x7f);
	CamWriteCmosSensor(0x21, 0x3c);	//38
	CamWriteCmosSensor(0x22, 0x73);
	CamWriteCmosSensor(0x50, 0x14);
	/********************************************/
	/******************* BLK ********************/
	/********************************************/
	CamWriteCmosSensor(0x30, 0xf7);
	CamWriteCmosSensor(0x39, 0x09);  // exp_rate_darkc
	CamWriteCmosSensor(0x3a, 0x18);
	CamWriteCmosSensor(0x3b, 0x20);
	CamWriteCmosSensor(0x3c, 0x22);
	CamWriteCmosSensor(0x3d, 0x22);
	/********************************************/
	/******************* LSC ********************/
	/********************************************/
	CamWriteCmosSensor(0x88, 0x20);
	CamWriteCmosSensor(0x8b, 0x78);
	CamWriteCmosSensor(0x8c, 0x74);
	CamWriteCmosSensor(0x8d, 0x70);

	/********************************************/
	/******************* DNDD ********************/
	/********************************************/
	CamWriteCmosSensor(0x62, 0x02);  // b_base
	CamWriteCmosSensor(0x64, 0x05);

	/********************************************/
	/******************* ASDE********************/
	/********************************************/
	CamWriteCmosSensor(0x69, 0x28);  //38//[5]auto_disable_dn when b<2, [4] 1->enhance dn when dark, 0->decrease dn when dark,
					  //[3:0]c_slope
	CamWriteCmosSensor(0x6a, 0x88);  // [7:4]b_slope , [3:0]n_slope
	CamWriteCmosSensor(0x6e, 0x50);  // ee1_effect,  ee1_slope
	CamWriteCmosSensor(0x6f, 0x40);  // ee2_effect,  ee2_slope


	/********************************************/
	/******************* EEINTP ********************/
	/********************************************/
	CamWriteCmosSensor(0x72, 0x6c);  


	/********************************************/
	/******************* AWB ********************/
	/********************************************/
	CamWriteCmosSensor(0xfe, 0x01);	
	CamWriteCmosSensor(0x00, 0xf5);		
	CamWriteCmosSensor(0x02, 0x20);	
	CamWriteCmosSensor(0x03, 0x10);	
	CamWriteCmosSensor(0x04, 0x10);	
	CamWriteCmosSensor(0x05, 0x22);	//08
	CamWriteCmosSensor(0x06, 0x20);	
	CamWriteCmosSensor(0x08, 0x20);	
	CamWriteCmosSensor(0x0a, 0x40);	
	CamWriteCmosSensor(0x11, 0x3c);	
	CamWriteCmosSensor(0x12, 0x72);	
	CamWriteCmosSensor(0x13, 0x11);	
	CamWriteCmosSensor(0x14, 0x42);	//awb_r_5_gain
	CamWriteCmosSensor(0x15, 0x43);	//43//awb_b_5_gain
	CamWriteCmosSensor(0x16, 0xb4);	//c2 //sinT
	CamWriteCmosSensor(0x17, 0xb5);	//a6 //cosT
	CamWriteCmosSensor(0x18, 0x28);	//22
	CamWriteCmosSensor(0x19, 0x4b);
	CamWriteCmosSensor(0x1a, 0xb0);
	CamWriteCmosSensor(0x1b, 0xf5);


	CamWriteCmosSensor(0xc0, 0x08);	
	CamWriteCmosSensor(0xc1, 0x06);	
	CamWriteCmosSensor(0xc2, 0x3e);	
	CamWriteCmosSensor(0xc3, 0x4e);	

	/********************************************/
	/******************* ABS ********************/
	/********************************************/
	CamWriteCmosSensor(0xb0, 0x02);
	CamWriteCmosSensor(0xb1, 0x01);
	CamWriteCmosSensor(0xb2, 0x02);   //00
	CamWriteCmosSensor(0xb3, 0x30);   //10    y strech limit

	/********************************************/
	/******************* YCP ********************/
	/********************************************/
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0xb1, 0x38);
	CamWriteCmosSensor(0xb2, 0x38);
	CamWriteCmosSensor(0xb3, 0x40);
	CamWriteCmosSensor(0xbe, 0x21);
	CamWriteCmosSensor(0x93, 0x48);
	CamWriteCmosSensor(0x94, 0xf6);
	CamWriteCmosSensor(0x95, 0xf8);
	CamWriteCmosSensor(0x96, 0x00); 
	CamWriteCmosSensor(0x97, 0x50); 
	CamWriteCmosSensor(0x98, 0xfa);
	CamWriteCmosSensor(0x9d, 0x03);

	/********************************************/
	/*******************Gamma********************/
	/********************************************/
	CamWriteCmosSensor(0x9F, 0x0E);		  
	CamWriteCmosSensor(0xA0, 0x1C);  
	CamWriteCmosSensor(0xA1, 0x34);
	CamWriteCmosSensor(0xA2, 0x48);
	CamWriteCmosSensor(0xA3, 0x5A);
	CamWriteCmosSensor(0xA4, 0x6B);
	CamWriteCmosSensor(0xA5, 0x7B);
	CamWriteCmosSensor(0xA6, 0x95);
	CamWriteCmosSensor(0xA7, 0xAB);
	CamWriteCmosSensor(0xA8, 0xBF);
	CamWriteCmosSensor(0xA9, 0xCE);
	CamWriteCmosSensor(0xAA, 0xD9);
	CamWriteCmosSensor(0xAB, 0xE4);
	CamWriteCmosSensor(0xAC, 0xEC);
	CamWriteCmosSensor(0xAD, 0xF6);
	CamWriteCmosSensor(0xAE, 0xFa);
	CamWriteCmosSensor(0xAF, 0xFF);

	/********************************************/
	/******************* AEC ********************/
	/********************************************/
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0xe5, 0x01);  //AEC enable
	CamWriteCmosSensor(0x01, 0x9b);  //hb[7:0]
	CamWriteCmosSensor(0x02, 0x4e);  //vb[7:0]
	CamWriteCmosSensor(0x0f, 0x07);  //vb[11:8] , hb[11:8]  6
	CamWriteCmosSensor(0xfe, 0x01);  
	CamWriteCmosSensor(0x30, 0x09);
	CamWriteCmosSensor(0x31, 0x90); //10
	CamWriteCmosSensor(0x32, 0x00);
	CamWriteCmosSensor(0x33, 0x78); // Y target
	CamWriteCmosSensor(0x3b, 0x92);
	CamWriteCmosSensor(0x3c, 0xa5);

	CamWriteCmosSensor(0x41, 0x21); 
	CamWriteCmosSensor(0x42, 0x00);   //step[11:8]
	CamWriteCmosSensor(0x43, 0x3a);   //step[7:0]
	CamWriteCmosSensor(0x44, 0x02);  // level 0
	CamWriteCmosSensor(0x45, 0x44);  
	CamWriteCmosSensor(0x46, 0x02);  // level 1
	CamWriteCmosSensor(0x47, 0x44);
	CamWriteCmosSensor(0x48, 0x02);  // level 2
	CamWriteCmosSensor(0x49, 0x44);
	CamWriteCmosSensor(0x4a, 0x04);  // level 3
	CamWriteCmosSensor(0x4b, 0x88);
	CamWriteCmosSensor(0x4c, 0x20);  // exp_level
	CamWriteCmosSensor(0x4d, 0x02);  // min_exp
	CamWriteCmosSensor(0x4e, 0xa8);  //aec post gain limit
	CamWriteCmosSensor(0x4f, 0x48);  //aec pre gain limit

	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0x1f, 0x15);	// bit[7:6] CSK driving current

	/********************************************/
	/******************* SPI ********************/
	/********************************************/
	CamWriteCmosSensor(0xfe, 0x02);
	CamWriteCmosSensor(0x01, 0x03);
	CamWriteCmosSensor(0x02, 0x02);	// 0x80->0x02, LSB & Falling edge sample
	CamWriteCmosSensor(0x03, 0x20);
	CamWriteCmosSensor(0x04, 0x20);   //[4] master_outformat
	CamWriteCmosSensor(0x05, 0x00);   // Set to 0x01 if no sp_clk divide.
	CamWriteCmosSensor(0x09, 0x00);   //Reverse the high<->low byte.
	CamWriteCmosSensor(0x0a, 0x00);   //Data ID, 0x00-YUV422, 0x01-RGB565
	CamWriteCmosSensor(0x13, 0xf0);

	/********************************************/
	/******************* OUT ********************/
	/********************************************/
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0x24, 0xa2);
	CamWriteCmosSensor(0xf0, 0x1f); //output_en

	GC6113_SERIALSensor.Pclk = 6000000;//24000000;		/* It is the PCLK for sensor internal parallel interface */
	GC6113_SERIALSensor.dummy_pixels = 0;
	GC6113_SERIALSensor.dummy_lines = 0;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALPvSetting
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
static void GC6113_SERIALPvSetting(void)
{
	GC6113_SERIALSensor.Pclk = 6000000;//24000000;		/* It is the PCLK for sensor internal parallel interface */	
	GC6113_SERIALSensor.PvMode = KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALCapSetting
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
static void GC6113_SERIALCapSetting(void)
{
	GC6113_SERIALSensor.Pclk = 6000000;//24000000;		/* It is the PCLK for sensor internal parallel interface */	
	GC6113_SERIALSensor.PvMode = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALGetSensorInfo
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
static void GC6113_SERIALGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
	Info->SensorId = GC6113_SERIAL_SENSOR_ID;
	Info->SensorIf = IMAGE_SENSOR_IF_SERIAL;

	Info->PreviewMclkFreq = 12000000;	//GC6113_SERIAL_MCLK;
	Info->CaptureMclkFreq = 12000000;	//GC6113_SERIAL_MCLK;
	Info->VideoMclkFreq = 12000000;	//GC6113_SERIAL_MCLK;

	Info->PreviewWidth = GC6113_SERIAL_IMAGE_SENSOR_PV_WIDTH;
	Info->PreviewHeight = GC6113_SERIAL_IMAGE_SENSOR_PV_HEIGHT;
	Info->FullWidth = GC6113_SERIAL_IMAGE_SENSOR_FULL_WIDTH;
	Info->FullHeight = GC6113_SERIAL_IMAGE_SENSOR_FULL_HEIGHT;

	/* data format */
	Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
	Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
	Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
	Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
	Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;

	/* isp pclk invert switch */
	Info->PixelClkInv 			= KAL_FALSE;
	Info->PixelClkPolarity 		= POLARITY_LOW;

	/* HSYNC/VSYNC polarity */
	Info->HsyncPolarity = POLARITY_LOW; /* Actually high active when set POLARITY_LOW */
	Info->VsyncPolarity = POLARITY_LOW;

	Info->SensorAfSupport = KAL_FALSE;
	Info->SensorFlashSupport = KAL_FALSE;

	/* If IsSensorDriverCtrlMCLK is TRUE, then the MCLK turn on/off is controlled by sensor driver.*/
	Info->IsSensorDriverCtrlMclk = KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*    GC6113SerialSensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    id: scenario id
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM GC6113_SERIALGetSerialSensorInfo(P_SERIAL_SENSOR_INFO_IN_STRUCT In,P_SERIAL_SENSOR_INFO_OUT_STRUCT Out)
{
	if (In->ScenarioId == CAL_SCENARIO_CAMERA_STILL_CAPTURE)
	{
		Out->para_1 = KAL_TRUE; 								/* SCK clock inverse */
		Out->para_2 = 4;										/* Cycle */
		Out->para_3 = GC6113_SERIAL_IMAGE_SENSOR_PV_WIDTH; 	/* Sensor capture data valid width */
		Out->para_4 = GC6113_SERIAL_IMAGE_SENSOR_PV_HEIGHT;	/* Sensor capture data valid height */
	}
	else
	{
		Out->para_1 = KAL_TRUE; 								/* SCK clock inverse */
		Out->para_2 = 4;										/* Cycle */
		Out->para_3 = GC6113_SERIAL_IMAGE_SENSOR_FULL_WIDTH; 	/* Sensor preview data valid width */
		Out->para_4 = GC6113_SERIAL_IMAGE_SENSOR_FULL_HEIGHT; 	/* Sensor preview data valid height */
	}

	return MM_ERROR_NONE; 
}




/*************************************************************************
* FUNCTION
*   GC6113_SERIALPowerOn
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
static kal_uint32 GC6113_SERIALPowerOn(void)
{
  static kal_uint8 GC6113_SERIALI2cAddr[] = {
  	GC6113_SERIAL_WRITE_ID_0,
#if (GC6113_SERIAL_WRITE_ID_1 != 0xFF)
    GC6113_SERIAL_WRITE_ID_1,
#endif
#if (GC6113_SERIAL_WRITE_ID_2 != 0xFF)
    GC6113_SERIAL_WRITE_ID_2,
#endif
#if (GC6113_SERIAL_WRITE_ID_3 != 0xFF)
    GC6113_SERIAL_WRITE_ID_3,
#endif
  };
  kal_uint32 SensorId = 0;
  kal_uint8 i = 0;
  
  CisModulePowerOn(GC6113_SERIALSensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, GC6113_SERIAL_WRITE_ID_0,
    GC6113_SERIAL_I2C_ADDR_BITS, GC6113_SERIAL_I2C_DATA_BITS, GC6113_SERIAL_HW_I2C_SPEED);
  GC6113_SERIALSensor.sccb_opened = KAL_TRUE;
  kal_sleep_task(3);

	/* Enable the MCLK */
	ENABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;
	kal_sleep_task(2);

	GC6113_SERIAL_SET_RST_HIGH;
	kal_sleep_task(1);
  
  for (i = 0; i < sizeof(GC6113_SERIALI2cAddr) / sizeof(GC6113_SERIALI2cAddr[0]); i++)
  {
    CameraSccbSetAddr(CAMERA_SCCB_SENSOR, GC6113_SERIALI2cAddr[i]);
	kal_sleep_task(1);

	/* Do the Software Reset Here */
    {
		CamWriteCmosSensor(0xFC, 0x12);	// Enable Digital Clock.
		CamWriteCmosSensor(0xFE, 0xA0);
		kal_sleep_task(1);
    }

    SensorId = CamReadCmosSensor(0x00);
	GC6113_SERIAL_TRACE("GC6113 Sensor ID = %x, write_id=%x", SensorId, GC6113_SERIALI2cAddr[i]);
	
    if (GC6113_SERIAL_SENSOR_ID == SensorId)
    {
      kal_uint8 Temp;
      
      /* swap the correct i2c address to first one, it will speed up next time read sensor ID */
      Temp = GC6113_SERIALI2cAddr[0];
      GC6113_SERIALI2cAddr[0] = GC6113_SERIALI2cAddr[i];
      GC6113_SERIALI2cAddr[i] = Temp;
      break;
    }
  }
  
  return SensorId;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALPowerDown
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
static void GC6113_SERIALPowerDown(void)
{
	GC6113_SERIAL_SET_RST_LOW;
	kal_sleep_task(1);
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALPreview
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
static void GC6113_SERIALPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{

	GC6113_SERIALPvSetting();

	switch (Id)
	{
	case CAL_SCENARIO_VIDEO:
		GC6113_SERIALSensor.MaxFrameRate = In->MaxVideoFrameRate;
		GC6113_SERIALSensor.MinFrameRate = In->MaxVideoFrameRate;
		Out->WaitStableFrameNum = 3;
		break;
	default:

		GC6113_SERIALSensor.MaxFrameRate = GC6113_SERIAL_MAX_CAMERA_FPS;
		GC6113_SERIALSensor.MinFrameRate = 10 *  GC6113_SERIAL_FRAME_RATE_UNIT;
		if (In->NightMode)
		{
			GC6113_SERIALSensor.MinFrameRate = GC6113_SERIALSensor.MinFrameRate >> 1;
		}

		Out->WaitStableFrameNum = 3;
		break;
	}
  
	GC6113_SERIALSetMirror(In->ImageMirror);

	GC6113_SERIALSetFrameRate(GC6113_SERIALSensor.MinFrameRate, GC6113_SERIALSensor.MaxFrameRate);
	GC6113_SERIALSetBandingStep(In->BandingFreq);

	GC6113_SERIALSetNightMode(Id, In->NightMode);

	GC6113_SERIALAeEnable(KAL_TRUE);
	GC6113_SERIALAwbEnable(KAL_TRUE);

	Out->GrabStartX = GC6113_SERIAL_PV_GRAB_START_X;
	Out->GrabStartY = GC6113_SERIAL_PV_GRAB_START_Y;
	Out->ExposureWindowWidth = GC6113_SERIAL_PV_GRAB_WIDTH;
	Out->ExposureWindowHeight = GC6113_SERIAL_PV_GRAB_HEIGHT;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALCapture
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
static void GC6113_SERIALCapture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	GC6113_SERIALCapSetting();
	
	Out->WaitStableFrameNum = GC6113_SERIAL_CAPTURE_DELAY_FRAME;

	Out->GrabStartX = GC6113_SERIAL_FULL_GRAB_START_X;
	Out->GrabStartY = GC6113_SERIAL_FULL_GRAB_START_Y;
	Out->ExposureWindowWidth = GC6113_SERIAL_FULL_GRAB_WIDTH;
	Out->ExposureWindowHeight = GC6113_SERIAL_FULL_GRAB_HEIGHT;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALDetectSensorId
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
static kal_uint32 GC6113_SERIALDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM GC6113_SERIALSensorClose(void);
  kal_uint32 SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (GC6113_SERIALSensor.SensorIdx)
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
      SensorId = GC6113_SERIALPowerOn();
      GC6113_SERIALSensorClose();
      if (GC6113_SERIAL_SENSOR_ID == SensorId)
      {
        return GC6113_SERIAL_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALInitOperationPara
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
static void GC6113_SERIALInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 0; /* use WaitStableFrameNum instead of this */
  Para->PreviewDelayFrame = GC6113_SERIAL_PREVIEW_DELAY_FRAME;
  Para->PreviewDisplayWaitFrame = GC6113_SERIAL_FIRST_PREVIEW_DELAY_FRAME;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSensorOpen
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
static MM_ERROR_CODE_ENUM GC6113_SERIALSensorOpen(void)
{
  if (GC6113_SERIALPowerOn() != GC6113_SERIAL_SENSOR_ID)
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
#ifdef GC6113_SERIAL_LOAD_FROM_T_FLASH
  if (!GC6113_SERIAL_Initialize_from_T_Flash()) /* for debug use. */
#endif
  {
    GC6113_SERIALInitialSetting(); /* apply the sensor initial setting */
  }
  
  /* default setting */
  GC6113_SERIALSensor.BypassAe = KAL_FALSE;
  GC6113_SERIALSensor.BypassAwb = KAL_FALSE;
  GC6113_SERIALSensor.PvMode = KAL_TRUE;
  GC6113_SERIALSensor.BandingFreq = CAM_BANDING_50HZ;
  GC6113_SERIALSensor.InternalClock = 0;
  GC6113_SERIALSensor.Shutter = 1;
  GC6113_SERIALSensor.Gain = 0x40;
  GC6113_SERIALSensor.FrameLength = 0;
  GC6113_SERIALSensor.LineLength = 0;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM GC6113_SERIALSensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return GC6113_SERIALWebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
  /* query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = GC6113_SERIALEv(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = GC6113_SERIALContrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SATURATION:
    ErrCode = GC6113_SERIALSaturation(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SHARPNESS:
    ErrCode = GC6113_SERIALSharpness(In, Out);
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = GC6113_SERIALWb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = GC6113_SERIALEffect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = GC6113_SERIALStillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
    ErrCode = ErrCode = GC6113_SERIALBanding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = GC6113_SERIALSceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = GC6113_SERIALSceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    GC6113_SERIALGetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GC6113_SERIALDetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GC6113_SERIALSensor.MaxFrameRate;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    GC6113_SERIALInitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(GC6113_SERIALSensor.SensorIdx, Out);
    break;
  
  /* Set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    GC6113_SERIALPowerDown();
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    GC6113_SERIALSensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    GC6113_SERIALSensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    GC6113_SERIALSensor.BypassAe = *(kal_bool *)In;
    GC6113_SERIALAeEnable(GC6113_SERIALSensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
	  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
	    GC6113_SERIALSensor.BypassAwb = *(kal_bool *)In;
	    GC6113_SERIALAwbEnable(GC6113_SERIALSensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
	    break;
	case IMAGE_SENSOR_FEATURE_GET_SERIAL_SENSOR_INFO:
		GC6113_SERIALGetSerialSensorInfo(In, Out);
		break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSensorCtrl
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
static MM_ERROR_CODE_ENUM GC6113_SERIALSensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    GC6113_SERIALPreview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    GC6113_SERIALCapture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSensorClose
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
static MM_ERROR_CODE_ENUM GC6113_SERIALSensorClose(void)
{
	GC6113_SERIALPowerDown();

	/* Set Low to MCLK */
	DISABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;

	CisModulePowerOn(GC6113_SERIALSensor.SensorIdx, KAL_FALSE);
	kal_sleep_task(2);

	GC6113_SERIALSensor.sccb_opened = KAL_FALSE;
	CameraSccbClose(CAMERA_SCCB_SENSOR);

	return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6113_SERIALSensorFunc
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
MM_ERROR_CODE_ENUM GC6113_SERIALSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncGC6113_SERIAL =
  {
    GC6113_SERIALSensorOpen,
    GC6113_SERIALSensorFeatureCtrl,
    GC6113_SERIALSensorCtrl,
    GC6113_SERIALSensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncGC6113_SERIAL;
  
  return MM_ERROR_NONE;
}

#ifdef __GC6113_SERIAL_DEBUG_TRACE__

#include "kbd_table.h"
#include "keypad_sw.h"
#include "stack_ltlcom.h"
#include "dcl.h"

extern kal_bool             kbd_push_assert;
extern kbd_buffer_struct    kbd_buffer;

kal_uint8 CATS_curr_state = 0;		// 0 - Idle
//kal_uint8 AT_Camera_hdl = 0;
DCL_HANDLE AT_Camera_hdl=NULL;


static void CATS_kbd_push_onekey(kbd_event event,kal_uint8 key)  
{
     ASSERT(kbd_push_assert == KAL_FALSE);
   kbd_push_assert = KAL_TRUE;
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = event;
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = key;
   //kbd_push_time_stamp();
   kbd_buffer.kbd_data_buffer_windex++;
   kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);
   kbd_push_assert = KAL_FALSE;
}


void CATS_press_one_key(kal_uint32 key_code)
{
	ilm_struct 	*Kp_ilm = NULL;

	CATS_kbd_push_onekey(kbd_onekey_press, key_code);
	DRV_BuildPrimitive(Kp_ilm,
						MOD_DRVKBD,
						MOD_UEM,
						MSG_ID_DRVUEM_KEYPAD_IND,
						NULL);
	msg_send_ext_queue(Kp_ilm);

	CATS_kbd_push_onekey(kbd_onekey_release, key_code);
	DRV_BuildPrimitive(Kp_ilm,
						MOD_DRVKBD,
						MOD_UEM,
						MSG_ID_DRVUEM_KEYPAD_IND,
						NULL);
	msg_send_ext_queue(Kp_ilm);
}

void CATS_Callback(void *args)
{
	static kal_uint8 idx = 3;
	SGPT_CTRL_START_T start;

	switch (CATS_curr_state)
	{
		case 0:		// Idle screen state.
			CATS_press_one_key(DEVICE_KEY_SK_LEFT);
			CATS_press_one_key(DEVICE_KEY_RIGHT);
			CATS_press_one_key(DEVICE_KEY_SK_LEFT);
			CATS_press_one_key(DEVICE_KEY_DOWN);
			CATS_press_one_key(DEVICE_KEY_SK_LEFT);
			idx = 3;
			CATS_curr_state = 1;
			break;
		case 1:		// Preview state
			CATS_press_one_key(DEVICE_KEY_MENU);
			idx = 3;
			CATS_curr_state = 2;
			break;
		case 2:		// Capture state
			CATS_press_one_key(DEVICE_KEY_END);
			idx = 3;
			CATS_curr_state = 0;
			break;
		case 3:		// Error state
			CATS_press_one_key(DEVICE_KEY_END);
			idx = 5;
			CATS_curr_state = 0;
			break;
			
	}

	//GPTI_StartItem(AT_Camera_hdl,
	///	(idx*100),
	//	CATS_Callback,
	//	NULL);		 // 3s

	start.u2Tick=(idx*100);
	start.pfCallback=CATS_Callback;
	start.vPara=NULL;
	DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start); 	
}

static kal_bool GC6113_SERIALAtGetValue(char *Str, kal_uint32 *Data)
{
    extern int isdigit(int c);
    extern int isxdigit(int c);
    extern int tolower(int c);
    char CmdName[15];
    kal_uint8 TmpIdx = 0, Index = 3;
    kal_uint32 Value;

    while (Str[Index] != '=' && Str[Index] != 13)
    {
        CmdName[TmpIdx++] = Str[Index++];
    }
    CmdName[TmpIdx] = '\0';

    if (strcmp(CmdName, "DO"))
    {
        return KAL_FALSE;
    }
    Value = Data[0] = 0;
    while (1)
    {
        TmpIdx = Str[++Index];
        switch (TmpIdx)
        {
        case 13:
        case ',':
            Data[++Data[0]] = Value;
            if (Data[0] == 9 || TmpIdx == 13)
            {
                return KAL_TRUE;
            }
            Value = 0;
            break;
        default:
            if (isdigit(TmpIdx))
            {
                Value = Value * 16 + TmpIdx - '0';
            }
            else if (isxdigit(TmpIdx))
            {
                Value = Value * 16 + tolower(TmpIdx) - 'a' + 10;
            }
            else
            {
                return KAL_TRUE;
            }
            break;
        }
    }
}

kal_bool AtFuncTest(kal_char *Str)
{
    kal_uint32 Data[10];

    if (!GC6113_SERIALAtGetValue(Str, Data))
    {
        return KAL_FALSE;
    }
    if (!Data[0])
    {
        return KAL_TRUE;
    }
	
    switch (Data[1])
    {
    case 0x00:
        {
            extern kal_uint32 IspCurrentFrameRate;

            GC6113_SERIAL_TRACE("Current Frame Rate: %d.%d fps", IspCurrentFrameRate / 10, IspCurrentFrameRate % 10);
        }
        break;
    case 0x02:
        GC6113_SERIAL_TRACE("Read BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x03:
        DRV_Reg32(Data[2]) = Data[3];
        GC6113_SERIAL_TRACE("Write BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x04:
        GC6113_SERIAL_TRACE("Read Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x05:
        CamWriteCmosSensor(Data[2], Data[3]);
        GC6113_SERIAL_TRACE("Write Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x06:
        CamWriteCmosSensor(Data[2], Data[3]);
        GC6113_SERIAL_TRACE("Read Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x07:
        CamWriteCmosSensor(Data[2], Data[3]);
        CamWriteCmosSensor(Data[4], Data[5]);
        CamWriteCmosSensor(Data[2], Data[3]);
        GC6113_SERIAL_TRACE("Write Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x08:
	{
		SGPT_CTRL_START_T start;
		//GPTI_GetHandle(&AT_Camera_hdl);
		AT_Camera_hdl = DclSGPT_Open(DCL_GPT_CB,0);
		
		GC6113_SERIAL_TRACE("CATS start...");
		//GPTI_StartItem(AT_Camera_hdl,
		//  300,
		//  CATS_Callback,
		//  NULL);		// 3s

		start.u2Tick=300;
		start.pfCallback=CATS_Callback;
		start.vPara=NULL;
		DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start); 	
		break;
    }
	case 0x09:
	{
		//GPTI_StopItem(AT_Camera_hdl);
		DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_STOP,0);

		DclSGPT_Close(&AT_Camera_hdl);
		AT_Camera_hdl = NULL;
		
		GC6113_SERIAL_TRACE("CATS stop!!!");
	}
	break;
    case 0x0A:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                GC6113_SERIAL_TRACE("Read Sensor Reg[%x] = %x", Data[2] + i, CamReadCmosSensor(Data[2] + i));
                if (!(i % 200))
                {
                    kal_sleep_task(30);
                }
            }
        }
        break;
    case 0x0B:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                GC6113_SERIAL_TRACE("Read BB Reg[%x] = %x", Data[2] + i * 4, DRV_Reg32(Data[2] + i * 4));
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
    return KAL_TRUE;
}

#endif	/* #ifdef __GC6113_SERIAL_DEBUG_TRACE__ */


