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
 *   image_sensor_SIC320A_SERIAL.c
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
 * removed!
 * removed!
 *
 * removed!
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
	CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq; /* SIC320A_SERIAL_50HZ or SIC320A_SERIAL_60HZ for 50Hz/60Hz */

	kal_bool sccb_opened;			/* The I2C can work when sccb_opened is KAL_TRUE */
} SIC320A_SERIALSensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

#ifdef SIC320A_SERIAL_LOAD_FROM_T_FLASH
/*************************************************************************
* FUNCTION
*  SIC320A_SERIAL_Initialize_from_T_Flash
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
static kal_uint8 SIC320A_SERIAL_Initialize_from_T_Flash()
{
#include "med_utility.h"
#include "fs_type.h"

#if SIC320A_SERIAL_I2C_ADDR_BITS == CAMERA_SCCB_16BIT
  #define SIC320A_SERIAL_REG_SKIP    0x08
#else
  #define SIC320A_SERIAL_REG_SKIP    0x06
#endif
#if SIC320A_SERIAL_I2C_DATA_BITS == CAMERA_SCCB_16BIT
  #define SIC320A_SERIAL_VAL_SKIP    0x08
#else
  #define SIC320A_SERIAL_VAL_SKIP    0x06
#endif
  
  /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
  #define SIC320A_SERIAL_OP_CODE_INI    0x00    /* Initial value. */
  #define SIC320A_SERIAL_OP_CODE_REG    0x01    /* Register */
  #define SIC320A_SERIAL_OP_CODE_DLY    0x02    /* Delay */
  #define SIC320A_SERIAL_OP_CODE_END    0x03    /* End of initial setting. */
  
  typedef struct
  {
    kal_uint16 init_reg;
    kal_uint16 init_val;  /* Save the register value and delay tick */
    kal_uint8 op_code;    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
  } SIC320A_SERIAL_initial_set_struct;
  
  static SIC320A_SERIAL_initial_set_struct SIC320A_SERIAL_Init_Reg[1000];
  static WCHAR SIC320A_SERIAL_set_file_name[256] = {0};
  FS_HANDLE fp = -1;        /* Default, no file opened. */
  kal_uint8 *data_buff = NULL;
  kal_uint8 *curr_ptr = NULL;
  kal_uint32 file_size = 0;
  kal_uint32 bytes_read = 0;
  kal_uint32 i = 0, j = 0;
  kal_uint8 func_ind[3] = {0};  /* REG or DLY */
  
  kal_mem_cpy(SIC320A_SERIAL_set_file_name, L"C:\\SIC320A_SERIAL_Initialize_Setting.Bin", sizeof(L"C:\\SIC320A_SERIAL_Initialize_Setting.Bin"));
  
  /* Search the setting file in all of the user disk. */
  curr_ptr = (kal_uint8 *)SIC320A_SERIAL_set_file_name;
  while (fp < 0)
  {
    if ((*curr_ptr >= 'c' && *curr_ptr <= 'z') || (*curr_ptr >= 'C' && *curr_ptr <= 'Z'))
    {
      fp = FS_Open(SIC320A_SERIAL_set_file_name, FS_READ_ONLY);
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
    SIC320A_SERIAL_TRACE("!!! Warning, Can't find the initial setting file!!!");
    return 0;
  }

  FS_GetFileSize(fp, &file_size);
  if (file_size < 20)
  {
    SIC320A_SERIAL_TRACE("!!! Warning, Invalid setting file!!!");
    return 0;      /* Invalid setting file. */
  }

  data_buff = med_alloc_ext_mem(file_size);
  if (data_buff == NULL)
  {
    SIC320A_SERIAL_TRACE("!!! Warning, Memory not enoughed...");
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
      SIC320A_SERIAL_Init_Reg[i].op_code = SIC320A_SERIAL_OP_CODE_REG;
      
      SIC320A_SERIAL_Init_Reg[i].init_reg = strtol((const char *)curr_ptr, NULL, 16);
      curr_ptr += SIC320A_SERIAL_REG_SKIP;  /* Skip "0x0000, " */
      
      SIC320A_SERIAL_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 16);
      curr_ptr += SIC320A_SERIAL_VAL_SKIP;  /* Skip "0x0000);" */
    }
    else                  /* DLY */
    {
      /* Need add delay for this setting. */
      SIC320A_SERIAL_Init_Reg[i].op_code = SIC320A_SERIAL_OP_CODE_DLY;
      
      SIC320A_SERIAL_Init_Reg[i].init_reg = 0xFF;
      SIC320A_SERIAL_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 10);  /* Get the delay ticks, the delay should less then 50 */
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
  SIC320A_SERIAL_Init_Reg[i].op_code = SIC320A_SERIAL_OP_CODE_END;
  SIC320A_SERIAL_Init_Reg[i].init_reg = 0xFF;
  SIC320A_SERIAL_Init_Reg[i].init_val = 0xFF;
  i++;
  
  SIC320A_SERIAL_TRACE("%d register read...", i - 1);
  med_free_ext_mem((void **)&data_buff);
  FS_Close(fp);
  
  SIC320A_SERIAL_TRACE("Start apply initialize setting.");
  /* Start apply the initial setting to sensor. */
  for (j=0; j<i; j++)
  {
    if (SIC320A_SERIAL_Init_Reg[j].op_code == SIC320A_SERIAL_OP_CODE_END)  /* End of the setting. */
    {
      break ;
    }
    else if (SIC320A_SERIAL_Init_Reg[j].op_code == SIC320A_SERIAL_OP_CODE_DLY)
    {
      kal_sleep_task(SIC320A_SERIAL_Init_Reg[j].init_val);    /* Delay */
    }
    else if (SIC320A_SERIAL_Init_Reg[j].op_code == SIC320A_SERIAL_OP_CODE_REG)
    {
      CamWriteCmosSensor(SIC320A_SERIAL_Init_Reg[j].init_reg, SIC320A_SERIAL_Init_Reg[j].init_val);
    }
    else
    {
      ASSERT(0);
    }
  }
  SIC320A_SERIAL_TRACE("%d register applied...", j);
  return 1;  
}
#endif

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSetMirror
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
static void SIC320A_SERIALSetMirror(kal_uint8 Mirror)
{
  kal_uint8 CntrB;
  
  CamWriteCmosSensor(0x00, 0x00);
  CntrB = CamReadCmosSensor(0x04)&0xFC;
  switch (Mirror)
  {
  case IMAGE_SENSOR_MIRROR_NORMAL:
  	CntrB |= 0;
    break;
  case IMAGE_SENSOR_MIRROR_H:
    CntrB |= 1;
    break;
  case IMAGE_SENSOR_MIRROR_V:
    CntrB |= 2;
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    CntrB |= 3;
    break;
  default:
    /* no need to do error handling */
    break;
  }
  CamWriteCmosSensor(0x04, CntrB);
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSetClock
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
static void SIC320A_SERIALSetClock(kal_uint32 InternalClock)
{
  SIC320A_SERIAL_CHECK_AND_SET(InternalClock, InternalClock, ); /* the 3rd parameter is none for void function */
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
#if SIC320A_SERIAL_MCLK == 24000000
    case 16000000: /* MCLK: 24M, INTERNAL CLK: 16M, PCLK: 32M */
      SIC320A_SERIALSensor.Pclk = 32000000;
      CamWriteCmosSensor(0x0A, 0x12); /* group B */
      break;
    case 24000000: /* MCLK: 24M, INTERNAL CLK: 24M, PCLK: 48M */
      SIC320A_SERIALSensor.Pclk = 48000000;
      CamWriteCmosSensor(0x0A, 0x11);
      break;
    default: /* MCLK: 24M, INTERNAL CLK: 24M, PCLK: 48M */
      SIC320A_SERIAL_TRACE("clock: %dHz error!!!", InternalClock);
      SIC320A_SERIALSensor.Pclk = 48000000;
      CamWriteCmosSensor(0x0A, 0x11);
      break;
#else
    case 13000000: /* MCLK: 26M, INTERNAL CLK: 13M, PCLK: 26M */
      SIC320A_SERIALSensor.Pclk = 26000000;
      CamWriteCmosSensor(0x0A, 0x13); /* group B */
      break;
    case 26000000: /* MCLK: 26M, INTERNAL CLK: 26M, PCLK: 52M */
      SIC320A_SERIALSensor.Pclk = 52000000;
      CamWriteCmosSensor(0x0A, 0x11);
      break;
    case 17333333: /* MCLK: 26M, INTERNAL CLK: 17.3M, PCLK: 34.67M */
      SIC320A_SERIALSensor.Pclk = 34666667;
      CamWriteCmosSensor(0x0A, 0x12);
      break;
    default: /* MCLK: 26M, INTERNAL CLK: 17.3M, PCLK: 34.67M */
      SIC320A_SERIAL_TRACE("clock: %dHz error!!!", InternalClock);
      SIC320A_SERIALSensor.Pclk = 34666667;
      CamWriteCmosSensor(0x0A, 0x12);
      break;
#endif
    }
  }
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALWriteShutter
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
static void SIC320A_SERIALWriteShutter(kal_uint32 Shutter)
{
  // TODO: set integration time here
  return ;
  
  CamWriteCmosSensor(0x00, 0x01);
  CamWriteCmosSensor(0x30, Shutter >> 8);
  CamWriteCmosSensor(0x31, Shutter);
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALReadShutter
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
static kal_uint32 SIC320A_SERIALReadShutter(void)
{
  // TODO: read integration time here
  return 0;
  
  CamWriteCmosSensor(0x00, 0x01);
  return (CamReadCmosSensor(0x30) << 8)|CamReadCmosSensor(0x31);
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALWriteGain
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
static void SIC320A_SERIALWriteGain(kal_uint32 Gain)
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
*   SIC320A_SERIALReadGain
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
static kal_uint32 SIC320A_SERIALReadGain(void)
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
*   SIC320A_SERIALAeEnable
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
static void SIC320A_SERIALAeEnable(kal_bool Enable)
{
  if (SIC320A_SERIALSensor.BypassAe && SIC320A_SERIALSensor.PvMode)
  {
    Enable = KAL_FALSE;
  }

  {
    kal_uint8 AeCtrl;
    
    /* should not enable bit2(adjust BLC) else cause brightness different in pv/cap */
    if (Enable)
    {
      AeCtrl = 0x80;
    }
    else
    {
      AeCtrl = 0x00;
    }
    CamWriteCmosSensor(0x00, 0x01);
    CamWriteCmosSensor(0x10, AeCtrl);
  }
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALAwbEnable
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
static void SIC320A_SERIALAwbEnable(kal_bool Enable)
{
  if (SIC320A_SERIALSensor.BypassAwb && SIC320A_SERIALSensor.PvMode)
  {
    Enable = KAL_FALSE;
  }

  {
    kal_uint8 AwbCtrl;
    
    if (Enable)
    {
      AwbCtrl = 0xD3;
    }
    else
    {
      AwbCtrl = 0x00;
    }
    CamWriteCmosSensor(0x00, 0x02);
    CamWriteCmosSensor(0x10, AwbCtrl);
  }
}


/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSetBandingStep
*
* DESCRIPTION
*   This function is to calculate & set shutter step register .
*
*************************************************************************/
static void SIC320A_SERIALSetBandingStep(CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq)
{
    kal_uint8 banding = 0;
    kal_uint16 shutter_step = 0;
	kal_uint32 line_length = 0;

	if (SIC320A_SERIALSensor.BandingFreq == BandingFreq)
		return ;

	SIC320A_SERIALSensor.BandingFreq = BandingFreq;

	if (CAM_BANDING_50HZ == BandingFreq)
	{
		banding = 100;
	}
	else
	{
		banding = 120;
	}

	line_length = SIC320A_SERIAL_PV_PERIOD_PIXEL_NUMS + SIC320A_SERIALSensor.dummy_pixels;
	shutter_step = (SIC320A_SERIALSensor.Pclk + (((line_length * 2) * banding)>>2)) / ((line_length * 2) * banding);

    ASSERT(shutter_step <= 0xFF);
    /* Block 1:0x34  shutter step*/
	CamWriteCmosSensor(0x00, 0x01);
    CamWriteCmosSensor(0x34, shutter_step);

#if 1
	// AE Off
    CamWriteCmosSensor(0x00, 0x01);
    CamWriteCmosSensor(0x10, 0x00);

	//camera_wait_sensor_vd_done();
	kal_sleep_task(50);		// Wait the disable ae take effect.

	// AE on
    //SIC320A_SERIAL_set_page(1);
	CamWriteCmosSensor(0x00, 0x01);
    CamWriteCmosSensor(0x10, 0x80);
#endif
	
    SIC320A_SERIAL_TRACE("Set Shutter Step:%x", shutter_step);
}/* SIC320A_SERIALSetBandingStep */


/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSetDummy
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
static void SIC320A_SERIALSetDummy(kal_uint32 DummyPixel, kal_uint32 DummyLine)
{
  kal_uint32 LineLength, FrameLength;

	SIC320A_SERIALSensor.dummy_pixels = DummyPixel;
	SIC320A_SERIALSensor.dummy_lines = DummyLine;
  
  if (SIC320A_SERIALSensor.PvMode)
  {
    LineLength = DummyPixel + SIC320A_SERIAL_PV_PERIOD_PIXEL_NUMS;
    FrameLength = DummyLine + SIC320A_SERIAL_PV_PERIOD_LINE_NUMS;
  }
  else
  {
    LineLength = DummyPixel + SIC320A_SERIAL_FULL_PERIOD_PIXEL_NUMS;
    FrameLength = DummyLine + SIC320A_SERIAL_FULL_PERIOD_LINE_NUMS;
  }
  
  if (LineLength > SIC320A_SERIAL_MAX_LINELENGTH)
  {
    SIC320A_SERIAL_TRACE("linelength: %d, dummypixel: %d overflow!!!", LineLength, DummyPixel);
    LineLength = SIC320A_SERIAL_MAX_LINELENGTH;
    DummyPixel = LineLength - (SIC320A_SERIALSensor.PvMode ? SIC320A_SERIAL_PV_PERIOD_PIXEL_NUMS : SIC320A_SERIAL_FULL_PERIOD_PIXEL_NUMS);
  }
  if (FrameLength > SIC320A_SERIAL_MAX_FRAMELENGTH)
  {
    SIC320A_SERIAL_TRACE("framelength: %d, dummyline: %d overflow!!!", FrameLength, DummyLine);
    FrameLength = SIC320A_SERIAL_MAX_FRAMELENGTH;
    DummyLine = FrameLength - (SIC320A_SERIALSensor.PvMode ? SIC320A_SERIAL_PV_PERIOD_LINE_NUMS : SIC320A_SERIAL_FULL_PERIOD_LINE_NUMS);
  }
  
  /* config line length */
  if (LineLength != SIC320A_SERIALSensor.LineLength)
  {
    SIC320A_SERIALSensor.LineLength = LineLength;
    {
		kal_uint16 temp_reg = 0;
		CamWriteCmosSensor(0x00, 0x00);

		temp_reg = (CamReadCmosSensor(0x20) & 0x0F);
		CamWriteCmosSensor(0x20, ((DummyPixel >> 4)&0xF0)|temp_reg);
		CamWriteCmosSensor(0x21, DummyPixel);
    }
  }
  
  /* config frame height */
  if (FrameLength != SIC320A_SERIALSensor.FrameLength)
  {
    SIC320A_SERIALSensor.FrameLength = FrameLength;
    {
		kal_uint16 temp_reg = 0;
		CamWriteCmosSensor(0x00, 0x00);

		temp_reg = (CamReadCmosSensor(0x20) & 0xF0);
		CamWriteCmosSensor(0x20, (temp_reg|((DummyLine >> 8)&0x0F)));
		CamWriteCmosSensor(0x23, DummyLine);
    }
  }
}


/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSetMaxShutterStep
*
* DESCRIPTION
*   This function is to set frame count register .
*
*************************************************************************/
static void SIC320A_SERIALSetMaxShutterStep(CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq, kal_uint32 MinFrameRate)
{
    kal_uint8 banding = 100;
	kal_uint8 max_shutter_step = 0;

	if (CAM_BANDING_50HZ == BandingFreq)
	{
		banding = 100;
	}
	else
	{
		banding = 120;
	}

	max_shutter_step = banding * SIC320A_SERIAL_FRAME_RATE_UNIT / MinFrameRate;
	/*Block 01: 0x11  Max shutter step,for Min frame rate */
	//SIC320A_SERIAL_set_page(1);
	CamWriteCmosSensor(0x00, 0x01);
	CamWriteCmosSensor(0x11, max_shutter_step&0xFF);

	SIC320A_SERIAL_TRACE("MinFrameRate:%d, max_shutter_step:%x", MinFrameRate, max_shutter_step);
}/* SIC320A_SERIALSetMaxShutterStep */



/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSetFixFrameRate
*
* DESCRIPTION
*   This function fix the frame rate of image sensor.
*
*************************************************************************/
 static void SIC320A_SERIALSetFixFrameRate(kal_bool IsFixFrameRate)
 {
 	kal_uint8 SIC320A_SERIAL_Control;
  
	CamWriteCmosSensor(0x00, 0x00);
	SIC320A_SERIAL_Control = CamReadCmosSensor(0x04);
	 if (IsFixFrameRate == KAL_TRUE)
	 {
		 SIC320A_SERIAL_Control |= 0xC0;
		 CamWriteCmosSensor(0x04, SIC320A_SERIAL_Control);
	 }
	 else
	 {
		 SIC320A_SERIAL_Control &= 0x3F;
		 CamWriteCmosSensor(0x04, SIC320A_SERIAL_Control);

	 }
 }	/* SIC320A_SERIALSetFixFrameRate */


/*************************************************************************
* FUNCTION
*    SIC320A_SERIALSetFrameRate
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
static void SIC320A_SERIALSetFrameRate(kal_uint32 MinFrameRate, kal_uint32 MaxFrameRate)
{
    kal_uint32 line_length = 0;
	kal_uint32 frame_length = 0;

	SIC320A_SERIAL_TRACE("[Target] MinFrameRate:%d, MaxFrameRate:%d", MinFrameRate, MaxFrameRate);
	
	//4 Step 1 Set the max frame rate
    line_length = SIC320A_SERIAL_PV_PERIOD_PIXEL_NUMS + SIC320A_SERIALSensor.dummy_pixels;

    frame_length = SIC320A_SERIALSensor.Pclk * SIC320A_SERIAL_FRAME_RATE_UNIT / (2 * line_length * MaxFrameRate);
	if (frame_length < SIC320A_SERIAL_PV_PERIOD_LINE_NUMS)
	{
		frame_length = SIC320A_SERIAL_PV_PERIOD_LINE_NUMS;

		SIC320A_SERIAL_TRACE("Warining!!! Target frame rate exeed sensor limitation: tar=%d, lim=%d", \
			MaxFrameRate, SIC320A_SERIALSensor.Pclk*SIC320A_SERIAL_FRAME_RATE_UNIT / line_length*2 / frame_length);

		MaxFrameRate = SIC320A_SERIALSensor.Pclk*SIC320A_SERIAL_FRAME_RATE_UNIT / ((SIC320A_SERIAL_PV_PERIOD_PIXEL_NUMS + SIC320A_SERIALSensor.dummy_pixels) * 2) / (SIC320A_SERIAL_PV_PERIOD_LINE_NUMS + SIC320A_SERIALSensor.dummy_lines);
	}
	
    if (frame_length > (SIC320A_SERIAL_PV_PERIOD_LINE_NUMS + 0xFFF))
    {
        frame_length = SIC320A_SERIAL_PV_PERIOD_LINE_NUMS + 0xFFF;
        line_length = SIC320A_SERIALSensor.Pclk * SIC320A_SERIAL_FRAME_RATE_UNIT / (2 * frame_length * MaxFrameRate);
    }

    SIC320A_SERIALSetDummy(line_length-SIC320A_SERIAL_PV_PERIOD_PIXEL_NUMS, frame_length-SIC320A_SERIAL_PV_PERIOD_LINE_NUMS);

	//4 Step 2 Set the minmum frame rate
	SIC320A_SERIALSetMaxShutterStep(SIC320A_SERIALSensor.BandingFreq, MinFrameRate);

	//4 Step 3 Fix the frame rate.
	if (MinFrameRate == MaxFrameRate)
	{
		SIC320A_SERIALSetFixFrameRate(KAL_TRUE);
	}
	else
	{
		SIC320A_SERIALSetFixFrameRate(KAL_FALSE);
	}
}



/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSetNightMode
*
* DESCRIPTION
*   This function switch on/off night mode of SIC320A_SERIAL.
*
*************************************************************************/
MM_ERROR_CODE_ENUM SIC320A_SERIALSetNightMode(CAL_SCENARIO_ENUM ScenarioId, 
								kal_bool night_enalbe)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
    SIC320A_SERIAL_TRACE("NightMode %d", night_enalbe);

	if (KAL_TRUE == night_enalbe)
	{
		switch (ScenarioId)
		{
		case CAL_SCENARIO_VIDEO:
			CamWriteCmosSensor(0x00,0x01);
            CamWriteCmosSensor(0x40,0x66); //Max Analog Gain Value @ Shutter step = Max Shutter step  0x7D
            
            CamWriteCmosSensor(0x00,0x03);
			CamWriteCmosSensor(0xB3,0x04);//1001_03:0X0D //Brightness Control 0x11
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			/* camera night mode */
			CamWriteCmosSensor(0x00,0x01);
            CamWriteCmosSensor(0x1c,0x04); //AEBLC value in dark condition
            CamWriteCmosSensor(0x40,0x66); //Max Analog Gain Value @ Shutter step = Max Shutter step  0x7D
            
            CamWriteCmosSensor(0x00,0x03);
			CamWriteCmosSensor(0xB3,0x04);//1001_03:0X0D //Brightness Control 0x11
            CamWriteCmosSensor(0xB6,0x14); //Color Suppression Change Start State  0x17            
            CamWriteCmosSensor(0xB7,0x53); //1001_03:0X40//Slope
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
			CamWriteCmosSensor(0x00,0x01);
            CamWriteCmosSensor(0x1c,0x02);
            
			CamWriteCmosSensor(0x00,0x03);
            CamWriteCmosSensor(0xB3,0x02); //1001_03:0X02 //0x04 
			break;
		case CAL_SCENARIO_CAMERA_PREVIEW:
		case CAL_SCENARIO_WEBCAM_PREVIEW:
		case CAL_SCENARIO_WEBCAM_CAPTURE:
			/* camera normal mode */
			CamWriteCmosSensor(0x00,0x01);
            CamWriteCmosSensor(0x1c,0x02);
            CamWriteCmosSensor(0x40,0x65);//1001_03:0X66// 0x7F
            
			CamWriteCmosSensor(0x00,0x03);
            CamWriteCmosSensor(0xB3,0x02); //1001_03:0X02 //0x04 
            CamWriteCmosSensor(0xB6,0x18);            
            CamWriteCmosSensor(0xB7,0x30); //Slope
			break;
		default:
			ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
		}
	}

	return ErrCode;
}   /* SIC320A_SERIALSetNightMode */

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALEv
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALEv(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0x44); 
		CamWriteCmosSensor(0x13,0x44);
		CamWriteCmosSensor(0x14,0x44);
      break;
    case CAM_EV_NEG_3_3:
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0x54); 
		CamWriteCmosSensor(0x13,0x54);
		CamWriteCmosSensor(0x14,0x54);
      break;
    case CAM_EV_NEG_2_3:
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0x64); 
		CamWriteCmosSensor(0x13,0x64);
		CamWriteCmosSensor(0x14,0x64);
      break;
    case CAM_EV_NEG_1_3:
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0x74); 
		CamWriteCmosSensor(0x13,0x74);
		CamWriteCmosSensor(0x14,0x74);
      break;
    case CAM_EV_ZERO:
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0x80); //0x84
		CamWriteCmosSensor(0x13,0x80);
		CamWriteCmosSensor(0x14,0x80);
      break;
    case CAM_EV_POS_1_3:
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0x94); 
		CamWriteCmosSensor(0x13,0x94);
		CamWriteCmosSensor(0x14,0x94);
      break;
    case CAM_EV_POS_2_3:
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0xA4); 
		CamWriteCmosSensor(0x13,0xA4);
		CamWriteCmosSensor(0x14,0xA4);
      break;
    case CAM_EV_POS_3_3:
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0xB4); 
		CamWriteCmosSensor(0x13,0xB4);
		CamWriteCmosSensor(0x14,0xB4);
      break;
    case CAM_EV_POS_4_3:
		CamWriteCmosSensor(0x00, 0x01);
		CamWriteCmosSensor(0x12,0xC4); 
		CamWriteCmosSensor(0x13,0xC4);
		CamWriteCmosSensor(0x14,0xC4);
      break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALContrast
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    // TODO: add supported contrast enum here
    Contrast->IsSupport = KAL_FALSE;
    //Contrast->ItemCount = 3;
    //Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
    //Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    //Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    // TODO: adjust contrast here
    //switch (In->FeatureSetValue)
    //{
    //case CAM_CONTRAST_HIGH:
    //  break;
    //case CAM_CONTRAST_MEDIUM:
    //  break;
    //case CAM_CONTRAST_LOW:
    //  break;
    //default:
    //  return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    //}
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSaturation
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALSaturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*   SIC320A_SERIALSharpness
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALSharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*   SIC320A_SERIALWb
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALWb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    // TODO: adjust manual WB here
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO:
      SIC320A_SERIALAwbEnable(KAL_TRUE);
      break;
    case CAM_WB_CLOUD:
      SIC320A_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x60, 0xD0); /* AWB R gain */
      CamWriteCmosSensor(0x61, 0x88); /* AWB B gain */
      break;
    case CAM_WB_DAYLIGHT:
      SIC320A_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x60, 0xC2);
      CamWriteCmosSensor(0x61, 0x9E);
      break;
    case CAM_WB_INCANDESCENCE:
      SIC320A_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x60, 0x98);
      CamWriteCmosSensor(0x61, 0xC8);
      break;
    case CAM_WB_FLUORESCENT:
      SIC320A_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x60, 0xAA);
      CamWriteCmosSensor(0x61, 0xBE);
      break;
    case CAM_WB_TUNGSTEN:
      SIC320A_SERIALAwbEnable(KAL_FALSE);
      CamWriteCmosSensor(0x60, 0x90);
      CamWriteCmosSensor(0x61, 0xC0);
      break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALEffect
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Effect = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

    Effect->IsSupport = KAL_TRUE;
    Effect->ItemCount = 3;
    Effect->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
	Effect->SupportItem[1] = CAM_EFFECT_ENC_GRAYINV;
    Effect->SupportItem[2] = CAM_EFFECT_ENC_GRAYSCALE;
   
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
		CamWriteCmosSensor(0x00, 0x03);
		CamWriteCmosSensor(0xC0, 0x00);
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
		CamWriteCmosSensor(0x00, 0x03);
		CamWriteCmosSensor(0xC0, 0x40);
      break;
    case CAM_EFFECT_ENC_GRAYINV:
		CamWriteCmosSensor(0x00, 0x03);
		CamWriteCmosSensor(0xC0, 0x20);
      break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALStillCaptureSize
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
MM_ERROR_CODE_ENUM SIC320A_SERIALStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*   SIC320A_SERIALBanding
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
	   SIC320A_SERIALSetBandingStep((CAL_CAMERA_BANDING_FREQ_ENUM)(In->FeatureSetValue));
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSceneMode
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*   SIC320A_SERIALInitialSetting
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
static void SIC320A_SERIALInitialSetting(void)
{
	CamWriteCmosSensor(0x00, 0x00);
	CamWriteCmosSensor(0x04, 0x00);	//# CNTR_B
	CamWriteCmosSensor(0x07, 0x33);//csk driving//0x11);	//# CNTR_C//CamWriteCmosSensor(0x07, 0x00);	//# CNTR_C


	CamWriteCmosSensor(0x13, 0x14);	//For fixing Black Sun. Encreases to fix but noisy 0x10-->enable, 0x0X--> data

	//# 48MHz 20FPS(PREVIEW_50Hz)
	CamWriteCmosSensor(0x20, 0x00);	//# P_BNKT
	CamWriteCmosSensor(0x21, 0x31);	//# P_HBNKT
	CamWriteCmosSensor(0x22, 0x01);	//# P_FRM_FILL
	CamWriteCmosSensor(0x23, 0x0A);	//# P_VBNKT

	//# 48MHz 20FPS(STILL_50Hz)
	CamWriteCmosSensor(0x24, 0x00);	//# S_BNKT
	CamWriteCmosSensor(0x25, 0x31);	//# S_HBNKT
	CamWriteCmosSensor(0x26, 0x01);	//# S_FRM_FILL
	CamWriteCmosSensor(0x27, 0x0A);	//# S_VBNKT


	//#### Sensor Setting : AE #######
	//CamWriteCmosSensor(0x00, 0x01);	//# Block Select
	CamWriteCmosSensor(0x00, 0x01);

	CamWriteCmosSensor(0x10, 0x8e);	//# AE_CNT
	CamWriteCmosSensor(0x11, 0x0F);	//# MAX_SHUTSTEP
	CamWriteCmosSensor(0x1c, 0x04); //0x06);	
	CamWriteCmosSensor(0x1D, 0x01);	//# INI_SHUT
	CamWriteCmosSensor(0x1E, 0x00);	//# INI_CGAIN
	CamWriteCmosSensor(0x22, 0x28);	//# INI_FGAIN
	CamWriteCmosSensor(0x34, 0x3F);	//# STST_P
	CamWriteCmosSensor(0x35, 0x3F);	//# STST_S
	CamWriteCmosSensor(0x36, 0x40);	//# SF_P2S

	//#### Sensor Setting : AWB #######
	//CamWriteCmosSensor(0x00, 0x02);	//# Block Select
	CamWriteCmosSensor(0x00, 0x02);

	CamWriteCmosSensor(0x10, 0xd3); 	//# 0xd3
	CamWriteCmosSensor(0x11, 0xc0);
	CamWriteCmosSensor(0x13, 0x80);
	CamWriteCmosSensor(0x14, 0x80);
	CamWriteCmosSensor(0x15, 0xff);	//# R gain Top
	CamWriteCmosSensor(0x16, 0x70);	//# R gain bottom
	CamWriteCmosSensor(0x17, 0xcb);	//# B gain Top
	CamWriteCmosSensor(0x18, 0x70);	//# B gain bottom 0x80
	CamWriteCmosSensor(0x19, 0x94);	//# Cr top value 0x90
	CamWriteCmosSensor(0x1a, 0x6c);	//# Cr bottom value 0x70
	CamWriteCmosSensor(0x1b, 0x94);	//# Cb top value 0x90
	CamWriteCmosSensor(0x1c, 0x6c);	//# Cb bottom value 0x70
	CamWriteCmosSensor(0x1d, 0x8a);	//# 0xa0
	CamWriteCmosSensor(0x1e, 0x76);	//# 0x60
	CamWriteCmosSensor(0x20, 0xe8);	//# AWB luminous top value
	CamWriteCmosSensor(0x21, 0x30);	//# AWB luminous bottom value 0x20


	CamWriteCmosSensor(0x22, 0xa3);//R+B gain average line
	CamWriteCmosSensor(0x23, 0x10);
	CamWriteCmosSensor(0x25, 0x20);
	CamWriteCmosSensor(0x26, 0x05);
	CamWriteCmosSensor(0x27, 0x0A);	//# BRTSRT
	CamWriteCmosSensor(0x28, 0xb8);	//# BRTRGNTOP
	CamWriteCmosSensor(0x29, 0xa8);	//# BRTRGNBOT
	CamWriteCmosSensor(0x2a, 0x90);	//# BRTBGNTOP
	CamWriteCmosSensor(0x2b, 0x88);	//# BRTBGNBOT
	CamWriteCmosSensor(0x2c, 0x00);	//# GAINCONT


	CamWriteCmosSensor(0x30, 0x03);
	CamWriteCmosSensor(0x31, 0x0a);
	CamWriteCmosSensor(0x32, 0x0a);
	CamWriteCmosSensor(0x33, 0x56);
	CamWriteCmosSensor(0x34, 0x16);
	                       
	CamWriteCmosSensor(0x40, 0x01);
	CamWriteCmosSensor(0x41, 0x04);
	CamWriteCmosSensor(0x42, 0x08);
	CamWriteCmosSensor(0x43, 0x10);
	CamWriteCmosSensor(0x44, 0x12);
	CamWriteCmosSensor(0x45, 0x35);
	CamWriteCmosSensor(0x46, 0x64);

	CamWriteCmosSensor(0x63, 0xb3);	//# R D30 to D20
	CamWriteCmosSensor(0x64, 0xc3);	//# B D30 to D20
	CamWriteCmosSensor(0x65, 0xb3);	//# R D20 to D30
	CamWriteCmosSensor(0x66, 0xc3);	//# B D20 to D30

	CamWriteCmosSensor(0x67, 0xdd);	//# R D65 to D30
	CamWriteCmosSensor(0x68, 0xa0);	//# B D65 to D30
	CamWriteCmosSensor(0x69, 0xdd);	//# R D30 to D65
	CamWriteCmosSensor(0x6a, 0xa0);	//# B D30 to D65

	//# DNP Viewer Detection
	CamWriteCmosSensor(0x74, 0x00);	//# T1RGAINBOT
	CamWriteCmosSensor(0x75, 0xff);	//# T1RGAINTOP
	CamWriteCmosSensor(0x76, 0x00);	//# T1BGAINBOT
	CamWriteCmosSensor(0x77, 0xff);     // 	# T1BGAINTOP
	CamWriteCmosSensor(0x80, 0xff);	//# YDIFFTH
	CamWriteCmosSensor(0x81, 0xff);	//# DNPEXPOTOP
	CamWriteCmosSensor(0x82, 0x00);	//# DNPEXPOBOT

	//# Overall Cloudy Sky Detection
	CamWriteCmosSensor(0x78, 0x00);	//# T2RGAINBOT
	CamWriteCmosSensor(0x79, 0xff);	//# T2RGAINTOP
	CamWriteCmosSensor(0x7a, 0x00);	//# T2BGAINBOT
	CamWriteCmosSensor(0x7b, 0xff);	//# T2BGAINTOP
	CamWriteCmosSensor(0x83, 0xff);	//# YDIFFTH2
	CamWriteCmosSensor(0x84, 0xff);	//# SKYEXPOTOP
	CamWriteCmosSensor(0x85, 0x00);	//# SKYEXPOBOT

	//#### Sensor Setting : IDP #######
	//CamWriteCmosSensor(0x00, 0x03);	//# Block Select
	CamWriteCmosSensor(0x00, 0x03);

	//# IDP Control
	CamWriteCmosSensor(0x10, 0xFF);    //# [7] : pchen
	/*		# [6] : Dark Filter
		# [5] : BLC
		# [4] : Shading
		# [3] : AWB Gain
		# [2] : Dark Offset
		# [1] : Gamma
		# [0] : DPC/Bayer-NR 		*/
	CamWriteCmosSensor(0x11, 0x40);	//# [6] : vblken
	CamWriteCmosSensor(0x13, 0xFC);    //# [7] : interpolation
	/*		# [6] : CMA & CSC
		# [5] : edge enhancement
		# [4] : color improve
		# [3] : hue control
		# [2] : InvCSC			*/
	CamWriteCmosSensor(0x14, 0x81);   //Enable AEBLC in dark condition //# [7] : function working always
	/*		# [6] : memkill
		# [5] : mem working always
		# [0] : AEBLC after AWB	*/

	//# format
	CamWriteCmosSensor(0x1A, 0x80);	//# TOGCTRL
	CamWriteCmosSensor(0x1B, 0x10);	//# POSTOG
	CamWriteCmosSensor(0x1C, 0x80);	//# NEGTOG

	//# SPI control
	CamWriteCmosSensor(0x1E, 0x20);	//# 0x80 #0x20 0x00	# SPI_CNTR

	//# BLC
	CamWriteCmosSensor(0x25, 0x00);	//# BLCCTRL

	//# syncdat
	CamWriteCmosSensor(0x2D, 0x40);	//# [7] TSTMEM
	/*		# [6] SREGRD
		# [5] SELLOW
		# [4] TSTOVR
		# [3] TSTFIX
		# [2] TSTVRAMP
		# [1] TSTVST
		# [0] TSTCBAR		*/
	CamWriteCmosSensor(0x2E, 0x01);
	CamWriteCmosSensor(0x2F, 0x65); 

	//# shading
	CamWriteCmosSensor(0x30, 0x00);	//# SHDDRKCTRL1
	CamWriteCmosSensor(0x31, 0x00);	//# SHDDRKCTRL2
	CamWriteCmosSensor(0x32, 0x00);	//# SHDDRKCTRL3
	CamWriteCmosSensor(0x33, 0x00);	//# SHDHORR
	CamWriteCmosSensor(0x34, 0x00);	//# SHDVERR
	CamWriteCmosSensor(0x35, 0x00);	//# SHDHORGR
	CamWriteCmosSensor(0x36, 0x00);	//# SHDVERGR
	CamWriteCmosSensor(0x37, 0x00);	//# SHDHORGB
	CamWriteCmosSensor(0x38, 0x00);	//# SHDVERGB
	CamWriteCmosSensor(0x39, 0x00);	//# SHDHORB
	CamWriteCmosSensor(0x3A, 0x00);	//# SHDVERB
	CamWriteCmosSensor(0x3B, 0x00);	//# SHDCNTH
	CamWriteCmosSensor(0x3C, 0xb4);	//# SHDCNTX
	CamWriteCmosSensor(0x3D, 0x94);	//# SHDCNTY
	CamWriteCmosSensor(0x3E, 0x80);	//# SSRT
	CamWriteCmosSensor(0x3F, 0x00);	//# SHDOFSRR
	CamWriteCmosSensor(0x40, 0x00);	//# SHDOFSGR
	CamWriteCmosSensor(0x41, 0x00);	//# SHDOFSGB
	CamWriteCmosSensor(0x42, 0x00);	//# SHDOFSBB
	CamWriteCmosSensor(0x43, 0x88);	//# SPOSIAB
	CamWriteCmosSensor(0x44, 0x88);	//# SPOSICD
	CamWriteCmosSensor(0x45, 0x88);	//# SPOSIEF
	CamWriteCmosSensor(0x46, 0x88);	//# SPOSIGH
	CamWriteCmosSensor(0x47, 0x88);	//# SPOSIIJ

	//# Digital Gain
	CamWriteCmosSensor(0x48, 0x0C);    //# [3] : D-gain enable
	/*		# [2] : DGAIN set by AE
		# [1:0] : AE gain delay		*/
	CamWriteCmosSensor(0x49, 0x20);

	//# drkoffset
	CamWriteCmosSensor(0x4A, 0x1F);	//# DRKSTART
	CamWriteCmosSensor(0x4B, 0x80);	//# DRKOFSYTARGET
	CamWriteCmosSensor(0x4C, 0xFF);	//# DRKOFSSTART
	CamWriteCmosSensor(0x4D, 0x00);	//# DRKOFSSLOP
	CamWriteCmosSensor(0x4E, 0x00);	//# DRKOFSMAX
	CamWriteCmosSensor(0x4F, 0x00);	//# DRKOFSLVL

	//# gamma
	CamWriteCmosSensor(0x50, 0x00);	//# Gma0
	CamWriteCmosSensor(0x51, 0x04);	//# Gma1
	CamWriteCmosSensor(0x52, 0x0d);//0x0b	//# Gma2
	CamWriteCmosSensor(0x53, 0x22);//0x24	//# Gma3
	CamWriteCmosSensor(0x54, 0x49);	//# Gma4
	CamWriteCmosSensor(0x55, 0x66);	//# Gma5
	CamWriteCmosSensor(0x56, 0x7c);	//# Gma6
	CamWriteCmosSensor(0x57, 0x8e);	//# Gma7
	CamWriteCmosSensor(0x58, 0x9e);	//# Gma8
	CamWriteCmosSensor(0x59, 0xac);	//# Gma9
	CamWriteCmosSensor(0x5A, 0xb7);	//# GmaA
	CamWriteCmosSensor(0x5B, 0xcf);	//# GmaB
	CamWriteCmosSensor(0x5C, 0xe1);	//# GmaC
	CamWriteCmosSensor(0x5D, 0xf1);	//# GmaD
	CamWriteCmosSensor(0x5E, 0xf9);	//# GmaE
	CamWriteCmosSensor(0x5F, 0xFF);	//# GmaF

	//# DPC & Bayer-NR
	CamWriteCmosSensor(0x60, 0xF0);	//# DPCNRCTRL
	CamWriteCmosSensor(0x61, 0x00);	//# DPTHR
	CamWriteCmosSensor(0x62, 0x04);	//# DPTHRMIN
	CamWriteCmosSensor(0x63, 0x04);	//# DPTHRMAX
	CamWriteCmosSensor(0x64, 0x14);	//# DPTHRSLP
	CamWriteCmosSensor(0x65, 0x11);	//# DPNUM
	CamWriteCmosSensor(0x66, 0x10);//0x08	//# NRTHR
	CamWriteCmosSensor(0x67, 0x10);//0x08	//# NRTHRMIN
	CamWriteCmosSensor(0x68, 0x08);	//# NRTHRMAX
	CamWriteCmosSensor(0x69, 0x88);	//# NRTHRSLP
	CamWriteCmosSensor(0x6A, 0x80);	//# NRNEICNT
	CamWriteCmosSensor(0x6B, 0x02);	//# STRTNOR
	CamWriteCmosSensor(0x6C, 0x0F);	//# STRTDRK

	//# CSCFUN
	CamWriteCmosSensor(0x70, 0x14);	//# CMASEL
	CamWriteCmosSensor(0x71, 0x3c);//0x40	//# 0x20	# 0x40	# 0x41	# CMA11
	CamWriteCmosSensor(0x72, 0xc6);//0xC2	//# 0xE5	# 0xc2	# 0xc2	# CMA12
	CamWriteCmosSensor(0x73, 0xfe);	//# 0xFB	# 0xfe	# 0xfe	# CMA13
	CamWriteCmosSensor(0x74, 0x0d);	//# 0x13	# 0x0d	# 0x0e	# CMA21
	CamWriteCmosSensor(0x75, 0x34);	//# 0x25	# 0x34	# 0x34	# CMA22
	CamWriteCmosSensor(0x76, 0xff);	//# 0x07	# 0xff	# 0xfe	# CMA23
	CamWriteCmosSensor(0x77, 0xfc);//0xf9	//# 0xF5	# 0xf9	# 0xf8	# CMA31
	CamWriteCmosSensor(0x78, 0xc4);//0xc1	//# 0xEB	# 0xc1	# 0xc1	# CMA32
	CamWriteCmosSensor(0x79, 0x40);//0x46	//# 0x20	# 0x46	# 0x47	# CMA33
	CamWriteCmosSensor(0x7A, 0x4d);	//# 0x20	# 0x4d	# 0x4d	# CMB11
	CamWriteCmosSensor(0x7B, 0xb8);	//# 0xE5	# 0xb8	# 0xb8	# CMB12
	CamWriteCmosSensor(0x7C, 0xfb);	//# 0xFB	# 0xfb	# 0xfb	# CMB13
	CamWriteCmosSensor(0x7D, 0x0d);	//# 0x13	# 0x0d	# 0x0d	# CMB21
	CamWriteCmosSensor(0x7E, 0x3c);	//# 0x25	# 0x3c	# 0x3c	# CMB22
	CamWriteCmosSensor(0x7F, 0xf7);	//# 0x07	# 0xf7	# 0xf6	# CMB23
	CamWriteCmosSensor(0x80, 0xef);	//# 0xF5	# 0xef	# 0xef	# CMB31
	CamWriteCmosSensor(0x81, 0xC5);	//# 0xEB	# 0xC5	# 0xC5	# CMB32
	CamWriteCmosSensor(0x82, 0x4c);	//# 0x20	# 0x4c	# 0x4d	# CMB33
	CamWriteCmosSensor(0x83, 0x42);	//# 0x20	# 0x42	# 0x42	# CMC11
	CamWriteCmosSensor(0x84, 0xc1);	//# 0xE5	# 0xc1	# 0xc1	# CMC12
	CamWriteCmosSensor(0x85, 0xfd);	//# 0xFB	# 0xfd	# 0xfd	# CMC13
	CamWriteCmosSensor(0x86, 0x16);	//# 0x13	# 0x16	# 0x16	# CMC21
	CamWriteCmosSensor(0x87, 0x37);	//# 0x25	# 0x37	# 0x37	# CMC22
	CamWriteCmosSensor(0x88, 0xf3);	//# 0x07	# 0xf3	# 0xf2	# CMC23
	CamWriteCmosSensor(0x89, 0xea);	//# 0xF5	# 0xea	# 0xea	# CMC31
	CamWriteCmosSensor(0x8A, 0xbc);	//# 0xEB	# 0xbc	# 0xbc	# CMC32
	CamWriteCmosSensor(0x8B, 0x5a);	//# 0x20	# 0x5a	# 0x5b	# CMC33

	//# Edge Enhancement
	CamWriteCmosSensor(0x90, 0x13);	//# GESTART
	CamWriteCmosSensor(0x91, 0x20);	//# GESLOP
	CamWriteCmosSensor(0x92, 0x60);	//# Geugain
	CamWriteCmosSensor(0x93, 0x60);	//# Gedgain
	CamWriteCmosSensor(0x94, 0x02);	//# Geucore
	CamWriteCmosSensor(0x95, 0x12);	//# GeucoreStrt
	CamWriteCmosSensor(0x96, 0xFF);	//# GeucoreEnd
	CamWriteCmosSensor(0x97, 0x20);	//# GeucoreSlop
	CamWriteCmosSensor(0x98, 0x02);	//# Gedcore
	CamWriteCmosSensor(0x99, 0x12);	//# GedcoreStrt
	CamWriteCmosSensor(0x9A, 0xFF);	//# GedcoreEnd
	CamWriteCmosSensor(0x9B, 0x20);	//# GedcoreSlop
	CamWriteCmosSensor(0x9C, 0x60);	//# Geuclip
	CamWriteCmosSensor(0x9D, 0x60);	//# Gedclip
	CamWriteCmosSensor(0x9E, 0x00);	//# Gedglevel
	CamWriteCmosSensor(0x9F, 0x13);	//# YESTART
	CamWriteCmosSensor(0xA0, 0x20);	//# YESLOP
	CamWriteCmosSensor(0xA1, 0x60);	//# Yeugain
	CamWriteCmosSensor(0xA2, 0x60);	//# Yedgain
	CamWriteCmosSensor(0xA3, 0x02);	//# 1Yeucore
	CamWriteCmosSensor(0xA4, 0x02);	//# 1Yedcore
	CamWriteCmosSensor(0xA5, 0x60);	//# Yeuclip
	CamWriteCmosSensor(0xA6, 0x60);	//# Yedclip
	CamWriteCmosSensor(0xA7, 0x00);	//# Yedglevel
	CamWriteCmosSensor(0xA8, 0x09);	//# enhctrl1
	CamWriteCmosSensor(0xA9, 0x10);	//# enhctrl2
	CamWriteCmosSensor(0xAA, 0x10);	//# enhctrl3
	CamWriteCmosSensor(0xAB, 0x20);	//# enhctrl4
	CamWriteCmosSensor(0xAC, 0x94);	//# NOIZCTRL

	//# colimpv
	CamWriteCmosSensor(0xB0, 0x10);	//# YGAIN
	CamWriteCmosSensor(0xB1, 0x10);	//# CRGAIN
	CamWriteCmosSensor(0xB2, 0x10);	//# CBGAIN
	CamWriteCmosSensor(0xB3, 0x00);	//# BRTCNT
	CamWriteCmosSensor(0xB4, 0x10);	//# CONTGAIN
	CamWriteCmosSensor(0xB5, 0x00);	//# IMGYOFST
	CamWriteCmosSensor(0xB6, 0x13);	//# GSTRT
	CamWriteCmosSensor(0xB7, 0x10);	//# GSLOP
	CamWriteCmosSensor(0xB8, 0xFE);	//try to fix drop line issue but never over-exposured.# YTOP
	CamWriteCmosSensor(0xB9, 0x00);	//# YBOT
	CamWriteCmosSensor(0xBA, 0xFF);	//# CRTOP
	CamWriteCmosSensor(0xBB, 0x00);	//# CRBOT
	CamWriteCmosSensor(0xBC, 0xFF);	//# CBTOP
	CamWriteCmosSensor(0xBD, 0x00);	//# CBBOT
	CamWriteCmosSensor(0xBE, 0x40);	//# HUECOS
	CamWriteCmosSensor(0xBF, 0x00);	//# HUESIN
	CamWriteCmosSensor(0xC0, 0x00);	//# IEFCT
	CamWriteCmosSensor(0xC1, 0x60);	//# CBEFCT
	CamWriteCmosSensor(0xC2, 0xA0);	//# CREFCT

	//# Memory Speed
	CamWriteCmosSensor(0xe8, 0x15);	//# MEMSPDA
	CamWriteCmosSensor(0xe9, 0x20);	//# MEMSPDB
	CamWriteCmosSensor(0xea, 0x04);	//# MEMSPDB

	//#### Sensor Setting : SNR #######
	//CamWriteCmosSensor(0x00, 0x00);	//# Block Select     
	CamWriteCmosSensor(0x00, 0x00);
	CamWriteCmosSensor(0x03, 0x05);	//# CNTR_A   

	SIC320A_SERIALSensor.Pclk = 6000000;	//48000000/8 is the CSK	// No PLL, Equal MCLK 24Mhz
	SIC320A_SERIALSensor.dummy_pixels = 0x31;
	SIC320A_SERIALSensor.dummy_lines = 0x0A;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALPvSetting
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
static void SIC320A_SERIALPvSetting(void)
{
	
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALCapSetting
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
static void SIC320A_SERIALCapSetting(void)
{
	
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALGetSensorInfo
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
static void SIC320A_SERIALGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
	Info->SensorId = SIC320A_SERIAL_SENSOR_ID;
	Info->SensorIf = IMAGE_SENSOR_IF_SERIAL;

	Info->PreviewMclkFreq = SIC320A_SERIAL_MCLK;
	Info->CaptureMclkFreq = SIC320A_SERIAL_MCLK;
	Info->VideoMclkFreq = SIC320A_SERIAL_MCLK;

	Info->PreviewWidth = SIC320A_SERIAL_IMAGE_SENSOR_PV_WIDTH;
	Info->PreviewHeight = SIC320A_SERIAL_IMAGE_SENSOR_PV_HEIGHT;
	Info->FullWidth = SIC320A_SERIAL_IMAGE_SENSOR_FULL_WIDTH;
	Info->FullHeight = SIC320A_SERIAL_IMAGE_SENSOR_FULL_HEIGHT;

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
*    SIC320ASerialSensorFeatureCtrl
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
MM_ERROR_CODE_ENUM SIC320A_SERIALGetSerialSensorInfo(P_SERIAL_SENSOR_INFO_IN_STRUCT In,P_SERIAL_SENSOR_INFO_OUT_STRUCT Out)
{
	if (In->ScenarioId == CAL_SCENARIO_CAMERA_STILL_CAPTURE)
	{
		Out->para_1 = KAL_TRUE; 								/* SCK clock inverse */
		Out->para_2 = 4;										/* Cycle */
		Out->para_3 = SIC320A_SERIAL_IMAGE_SENSOR_PV_WIDTH; 	/* Sensor capture data valid width */
		Out->para_4 = SIC320A_SERIAL_IMAGE_SENSOR_PV_HEIGHT;	/* Sensor capture data valid height */
	}
	else
	{
		Out->para_1 = KAL_TRUE; 								/* SCK clock inverse */
		Out->para_2 = 4;										/* Cycle */
		Out->para_3 = SIC320A_SERIAL_IMAGE_SENSOR_FULL_WIDTH; 	/* Sensor preview data valid width */
		Out->para_4 = SIC320A_SERIAL_IMAGE_SENSOR_FULL_HEIGHT; 	/* Sensor preview data valid height */
	}

	return MM_ERROR_NONE; 
}




/*************************************************************************
* FUNCTION
*   SIC320A_SERIALPowerOn
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
static kal_uint32 SIC320A_SERIALPowerOn(void)
{
  static kal_uint8 SIC320A_SERIALI2cAddr[] = {
  	SIC320A_SERIAL_WRITE_ID_0,
#if (SIC320A_SERIAL_WRITE_ID_1 != 0xFF)
    SIC320A_SERIAL_WRITE_ID_1,
#endif
#if (SIC320A_SERIAL_WRITE_ID_2 != 0xFF)
    SIC320A_SERIAL_WRITE_ID_2,
#endif
#if (SIC320A_SERIAL_WRITE_ID_3 != 0xFF)
    SIC320A_SERIAL_WRITE_ID_3,
#endif
  };
  kal_uint32 SensorId = 0;
  kal_uint8 i = 0;
  
  CisModulePowerOn(SIC320A_SERIALSensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, SIC320A_SERIAL_WRITE_ID_0,
    SIC320A_SERIAL_I2C_ADDR_BITS, SIC320A_SERIAL_I2C_DATA_BITS, SIC320A_SERIAL_HW_I2C_SPEED);
  SIC320A_SERIALSensor.sccb_opened = KAL_TRUE;
  kal_sleep_task(3);

	/* Enable the MCLK */
	ENABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;
	kal_sleep_task(2);
  
  for (i = 0; i < sizeof(SIC320A_SERIALI2cAddr) / sizeof(SIC320A_SERIALI2cAddr[0]); i++)
  {
    CameraSccbSetAddr(CAMERA_SCCB_SENSOR, SIC320A_SERIALI2cAddr[i]);
	kal_sleep_task(1);

	/* Do the Software Reset Here */
    {
		CamWriteCmosSensor(0x00, 0x00);
		CamWriteCmosSensor(0x03, 0x05);	// 0x09->0x05//# CNTR_A	 
		kal_sleep_task(2);
    }

	CamWriteCmosSensor(0x00, 0x00);
    SensorId = CamReadCmosSensor(0x01);
	SIC320A_SERIAL_TRACE("SIC320A Sensor ID = %x, write_id=%x", SensorId, SIC320A_SERIALI2cAddr[i]);
	
    if (SIC320A_SERIAL_SENSOR_ID == SensorId)
    {
      kal_uint8 Temp;
      
      /* swap the correct i2c address to first one, it will speed up next time read sensor ID */
      Temp = SIC320A_SERIALI2cAddr[0];
      SIC320A_SERIALI2cAddr[0] = SIC320A_SERIALI2cAddr[i];
      SIC320A_SERIALI2cAddr[i] = Temp;
      break;
    }
  }
  
  return SensorId;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALPowerDown
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
static void SIC320A_SERIALPowerDown(void)
{
	if (KAL_TRUE == SIC320A_SERIALSensor.sccb_opened)
	{
		CamWriteCmosSensor(0x00, 0x00);
		CamWriteCmosSensor(0x03, 0x02);	// Software Power Down
		kal_sleep_task(3);
	}
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALPreview
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
static void SIC320A_SERIALPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	const kal_bool PvMode = SIC320A_SERIALSensor.PvMode;

	SIC320A_SERIALSensor.PvMode = KAL_TRUE;

	SIC320A_SERIALPvSetting();

	switch (Id)
	{
	case CAL_SCENARIO_VIDEO:
		SIC320A_SERIALSensor.MaxFrameRate = In->MaxVideoFrameRate;
		SIC320A_SERIALSensor.MinFrameRate = In->MaxVideoFrameRate;
		Out->WaitStableFrameNum = 10;
		break;
	default:

		SIC320A_SERIALSensor.MaxFrameRate = SIC320A_SERIAL_MAX_CAMERA_FPS;
		SIC320A_SERIALSensor.MinFrameRate = 10 *  SIC320A_SERIAL_FRAME_RATE_UNIT;
		if (In->NightMode)
		{
			SIC320A_SERIALSensor.MinFrameRate = SIC320A_SERIALSensor.MinFrameRate >> 1;
		}

		Out->WaitStableFrameNum = 10;
		break;
	}
  
	SIC320A_SERIALSetMirror(In->ImageMirror);

	SIC320A_SERIALSetFrameRate(SIC320A_SERIALSensor.MinFrameRate, SIC320A_SERIALSensor.MaxFrameRate);
	SIC320A_SERIALSetBandingStep(In->BandingFreq);

	SIC320A_SERIALSetNightMode(Id, In->NightMode);

	SIC320A_SERIALAeEnable(KAL_TRUE);
	SIC320A_SERIALAwbEnable(KAL_TRUE);

	Out->WaitStableFrameNum = 3;

	Out->GrabStartX = SIC320A_SERIAL_PV_GRAB_START_X;
	Out->GrabStartY = SIC320A_SERIAL_PV_GRAB_START_Y;
	Out->ExposureWindowWidth = SIC320A_SERIAL_PV_GRAB_WIDTH;
	Out->ExposureWindowHeight = SIC320A_SERIAL_PV_GRAB_HEIGHT;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALCapture
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
static void SIC320A_SERIALCapture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	Out->WaitStableFrameNum = SIC320A_SERIAL_CAPTURE_DELAY_FRAME;

	Out->GrabStartX = SIC320A_SERIAL_FULL_GRAB_START_X;
	Out->GrabStartY = SIC320A_SERIAL_FULL_GRAB_START_Y;
	Out->ExposureWindowWidth = SIC320A_SERIAL_FULL_GRAB_WIDTH;
	Out->ExposureWindowHeight = SIC320A_SERIAL_FULL_GRAB_HEIGHT;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALDetectSensorId
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
static kal_uint32 SIC320A_SERIALDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM SIC320A_SERIALSensorClose(void);
  kal_uint32 SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (SIC320A_SERIALSensor.SensorIdx)
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
      SensorId = SIC320A_SERIALPowerOn();
      SIC320A_SERIALSensorClose();
      if (SIC320A_SERIAL_SENSOR_ID == SensorId)
      {
        return SIC320A_SERIAL_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALInitOperationPara
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
static void SIC320A_SERIALInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 0; /* use WaitStableFrameNum instead of this */
  Para->PreviewDelayFrame = SIC320A_SERIAL_PREVIEW_DELAY_FRAME;
  Para->PreviewDisplayWaitFrame = SIC320A_SERIAL_FIRST_PREVIEW_DELAY_FRAME;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSensorOpen
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALSensorOpen(void)
{
  if (SIC320A_SERIALPowerOn() != SIC320A_SERIAL_SENSOR_ID)
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
#ifdef SIC320A_SERIAL_LOAD_FROM_T_FLASH
  if (!SIC320A_SERIAL_Initialize_from_T_Flash()) /* for debug use. */
#endif
  {
    SIC320A_SERIALInitialSetting(); /* apply the sensor initial setting */
  }
  
  /* default setting */
  SIC320A_SERIALSensor.BypassAe = KAL_FALSE;
  SIC320A_SERIALSensor.BypassAwb = KAL_FALSE;
  SIC320A_SERIALSensor.PvMode = KAL_TRUE;
  SIC320A_SERIALSensor.BandingFreq = CAM_BANDING_50HZ;
  SIC320A_SERIALSensor.InternalClock = 0;
  SIC320A_SERIALSensor.Shutter = 1;
  SIC320A_SERIALSensor.Gain = 0x40;
  SIC320A_SERIALSensor.FrameLength = 0;
  SIC320A_SERIALSensor.LineLength = 0;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALSensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return SIC320A_SERIALWebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
  /* query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = SIC320A_SERIALEv(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = SIC320A_SERIALContrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SATURATION:
    ErrCode = SIC320A_SERIALSaturation(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SHARPNESS:
    ErrCode = SIC320A_SERIALSharpness(In, Out);
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = SIC320A_SERIALWb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = SIC320A_SERIALEffect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = SIC320A_SERIALStillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
    ErrCode = ErrCode = SIC320A_SERIALBanding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = SIC320A_SERIALSceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = SIC320A_SERIALSceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    SIC320A_SERIALGetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIC320A_SERIALDetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIC320A_SERIALSensor.MaxFrameRate;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    SIC320A_SERIALInitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(SIC320A_SERIALSensor.SensorIdx, Out);
    break;
  
  /* Set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    SIC320A_SERIALPowerDown();
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    SIC320A_SERIALSensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    SIC320A_SERIALSensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    SIC320A_SERIALSensor.BypassAe = *(kal_bool *)In;
    SIC320A_SERIALAeEnable(SIC320A_SERIALSensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
	  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
	    SIC320A_SERIALSensor.BypassAwb = *(kal_bool *)In;
	    SIC320A_SERIALAwbEnable(SIC320A_SERIALSensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
	    break;
	case IMAGE_SENSOR_FEATURE_GET_SERIAL_SENSOR_INFO:
		SIC320A_SERIALGetSerialSensorInfo(In, Out);
		break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSensorCtrl
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALSensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    SIC320A_SERIALPreview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    SIC320A_SERIALCapture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSensorClose
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
static MM_ERROR_CODE_ENUM SIC320A_SERIALSensorClose(void)
{
	SIC320A_SERIALPowerDown();

	/* Set Low to MCLK */
	DISABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;

	CisModulePowerOn(SIC320A_SERIALSensor.SensorIdx, KAL_FALSE);
	kal_sleep_task(2);

	SIC320A_SERIALSensor.sccb_opened = KAL_FALSE;
	CameraSccbClose(CAMERA_SCCB_SENSOR);

	return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   SIC320A_SERIALSensorFunc
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
MM_ERROR_CODE_ENUM SIC320A_SERIALSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncSIC320A_SERIAL =
  {
    SIC320A_SERIALSensorOpen,
    SIC320A_SERIALSensorFeatureCtrl,
    SIC320A_SERIALSensorCtrl,
    SIC320A_SERIALSensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncSIC320A_SERIAL;
  
  return MM_ERROR_NONE;
}

#ifdef __SIC320A_SERIAL_DEBUG_TRACE__

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

static kal_bool SIC320A_SERIALAtGetValue(char *Str, kal_uint32 *Data)
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

    if (!SIC320A_SERIALAtGetValue(Str, Data))
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

            SIC320A_SERIAL_TRACE("Current Frame Rate: %d.%d fps", IspCurrentFrameRate / 10, IspCurrentFrameRate % 10);
        }
        break;
    case 0x02:
        SIC320A_SERIAL_TRACE("Read BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x03:
        DRV_Reg32(Data[2]) = Data[3];
        SIC320A_SERIAL_TRACE("Write BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x04:
        SIC320A_SERIAL_TRACE("Read Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x05:
        CamWriteCmosSensor(Data[2], Data[3]);
        SIC320A_SERIAL_TRACE("Write Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x06:
        CamWriteCmosSensor(Data[2], Data[3]);
        SIC320A_SERIAL_TRACE("Read Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x07:
        CamWriteCmosSensor(Data[2], Data[3]);
        CamWriteCmosSensor(Data[4], Data[5]);
        CamWriteCmosSensor(Data[2], Data[3]);
        SIC320A_SERIAL_TRACE("Write Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x08:
	{
		SGPT_CTRL_START_T start;
		//GPTI_GetHandle(&AT_Camera_hdl);
		AT_Camera_hdl = DclSGPT_Open(DCL_GPT_CB,0);
		
		SIC320A_SERIAL_TRACE("CATS start...");
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
		
		SIC320A_SERIAL_TRACE("CATS stop!!!");
	}
	break;
    case 0x0A:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                SIC320A_SERIAL_TRACE("Read Sensor Reg[%x] = %x", Data[2] + i, CamReadCmosSensor(Data[2] + i));
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
                SIC320A_SERIAL_TRACE("Read BB Reg[%x] = %x", Data[2] + i * 4, DRV_Reg32(Data[2] + i * 4));
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

#endif	/* #ifdef __SIC320A_SERIAL_DEBUG_TRACE__ */


