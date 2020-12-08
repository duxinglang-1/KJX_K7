/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   image_sensor_HM0356.c
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
 *
 * removed!
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
#include "sensor_frame_rate_lut.h"
#include "sensor_comm_def.h"

#define HM0356_DEBUG //modify by hesong for debug
static struct
{
  kal_uint8   Banding;
  kal_bool    NightMode;
  kal_bool    VideoMode;
  kal_bool    BypassAe;
  kal_bool    BypassAwb;
  kal_uint16  Fps;
  kal_uint32  Pclk;
  kal_uint16  DummyPixel; /* for user customization */
  kal_uint16  Hblank; /* for calculating shutter step */
  kal_uint16  ShutterStep;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} HM0356Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif
 
#if (defined(__SENSOR_FRAME_RATE_SUPPORT__))
	 SENSOR_FRAMERATE_IN_STRUCT  HM0356_SensorCommonFrameIn;
	 SENSOR_FRAMERATE_OUT_STRUCT HM0356_SensorCommonFrameOut;
	 kal_uint32 HM0356_retFrameRateResult;
#endif	/* #if (defined(__SENSOR_FRAME_RATE_SUPPORT__)) */

const HM0356_SENSOR_INIT_INFO HM0356YyuvSensorInitialSettingInfo[]=
{
	// Init
	{0x1E, 0x01}, // Reset																
	{0x18, 0x80}, // By pass PLL, pclk = Mclk
	
	{0x1C, 0x3D}, // increase IO strength 								

	//Basic
	{0x06, 0x08}, //imager readout configuration																			
	{0x07, 0x02}, // high speed read out									
	{0x1C, 0xDD}, //																			
	{0x39, 0x12}, //																			
	{0x5D, 0x90}, //																			
	{0x5E, 0x90}, // 80->90  @ 0324					
	{0x5F, 0x80}, // Contrast Center											
	//{0x60, 0x40}, // Saturation 42->3C->40 @ 0324 		
	{0x60, 0x48}, // Saturation 42->3C->40 @ 0324 	
	//{0x64, 0x05}, // decrease edge enhance to reduceª¬		
	{0x64, 0x0A}, // decrease edge enhance to reduceª¬
	{0xA7, 0x08}, //																			
	{0xA8, 0x08}, //																			
	{0xA9, 0xF1}, // select option 1 for UV denoise 			
	{0xAA, 0x10}, //																			
	{0xAC, 0x40}, //																			
	{0xAE, 0x08}, //																			
	{0xAF, 0x10}, //																			
	{0xB6, 0x04}, //																			
	{0xB7, 0x04}, //																			
	{0xB8, 0x10}, // Bayer De-Noise Strength							
	{0xB9, 0x10}, // Y De-Noise BPC 											
	{0xBA, 0x10}, //																			
	{0xBB, 0x10}, //																			
	{0xBF, 0xE0}, // R																		
	{0xC0, 0x00}, // G																		
	{0xC1, 0x52}, // B																		
	{0xE3, 0x90}, //																			
	{0xE4, 0x0E}, //																			
	{0xF5, 0x89}, //																			

	//windowing
	/*
	{0x28, 0x00}, //																			
	{0x29, 0x00}, //																			
	{0x2A, 0x48}, // StartX:72														
	{0x2B, 0xF9}, // ImageSizeX,0xF9:249, 249-72=177			
	{0x2C, 0x30}, // StartY:48														
	{0x2D, 0xC3}, // ImageSizeY,0xC3:195, 195-48=147			
	{0x22, 0x47}, // [4]windowing enable		
	*/
	{0x28, 0x20}, //																			
	{0x29, 0x10}, //																			
	{0x2A, 0x00}, // StartX:	2													
	{0x2B, 0x80}, // ImageSizeX,0xF9:249, 249-72 640			
	{0x2C, 0x00}, // StartY:	2													
	{0x2D, 0xe0}, // ImageSizeY,0xC3:195, 195-48 480
	{0x22, 0x47},

	{0x26,0x02},//yuv format
	//AE stragtic windowing
	{0xD0, 0x77}, //																			
	{0xD1, 0x12}, //																			
	{0xD2, 0x04}, //																			
	{0xD3, 0x1D}, //																			
	{0xD4, 0x2E}, //																			
	{0xD5, 0x18}, //																			
	{0xD6, 0x20}, //																			
	{0xD7, 0x90}, //																			
	{0xD8, 0xC0}, //																			

	//AWB stragtic windowing
	{0xEB, 0x18}, //																			
	{0xEC, 0x20}, //																			
	{0xED, 0x90}, //																			
	{0xEE, 0xC0}, //																			

	//AWB Control
	//{0xC3, 0x58}, //		
	{0xC3, 0x40}, //	
	
	{0xCB, 0xF0}, //																			
	{0xCC, 0x10}, //																			
	{0xC5, 0x3D}, //																			
	{0xC6, 0xA7}, //																			
	{0xC7, 0x58}, //																			
	//{0xC8, 0x80}, //		
	{0xC8, 0x78}, //
	{0xC9, 0x70}, //																			
	{0xCA, 0x50}, //																			
	{0xCD, 0x80}, //																			
	{0xCE, 0x60}, //																			
	//{0xCF, 0x90}, //	
	//{0xCF, 0x88}, //
	{0xCF, 0x90}, //
	//{0xF5, 0x88}, //

	
	//AE
	{0x12, 0x00}, //																			
	{0x14, 0x01}, //00																			
	{0x15, 0x40}, //FC																			
	{0x30, 0x45}, // AE target														
	//{0x31, 0x02}, // Max Exposure 												
	//{0x32, 0xE4}, // Max Exposure 19.9f	
	{0x31, 0x01}, // Max Exposure 												
	{0x32, 0xF5}, // Max Exposure  30f
	
	{0x33, 0x10}, // Min Integration Time 								
	{0x34, 0x02}, // Max Analog Gain											
	//{0x35, 0xFF}, // Max Digital Gain 	
	{0x35, 0xC8}, // Max Digital Gain
	{0x38, 0x4A}, // 50Hz Flicker Step										
	{0xDA, 0x55}, // AE upper bond												
	{0xDB, 0x35}, // AE lower bond												
	{0xE3, 0x90}, // AE T-Damping 												
	{0xE4, 0x0E}, // AE N-Damping 
	
	//{0x36, 0xD0}, // fix_pattern
	
	//AE Framerate Control
	{0x25, 0x09}, // AE Framerate Control OFF 						
	{0x40, 0x01}, //																			
	{0x41, 0xF0}, //																			
	{0x42, 0x02}, //																			
	{0x43, 0xE8}, //																			
	{0x44, 0x05}, //																			
	{0x45, 0xD0}, //																			
	{0x46, 0x20}, //																			
	{0x47, 0x84}, //																			
	{0x48, 0x40}, //																			
	{0x49, 0x2E}, //																			
	{0x4A, 0x0E}, //																			

	//matrix
	{0x50, 0x00}, //																			
	{0x51, 0x91}, //																			
	{0x52, 0x8C}, //																			
	{0x53, 0x64}, //																			
	{0x54, 0x81}, //																			
	{0x55, 0x3B}, //																			
	{0x56, 0x46}, //																			
	{0x57, 0x55}, //																			
	{0x58, 0xBF}, //																			
	{0x59, 0x6A}, //																			
	{0x5A, 0x2D}, //																			
	{0x5B, 0x8E}, //																			
	{0x5C, 0xBB}, //																			

	//LSC
	{0x80, 0x10}, //																			
	{0x81, 0xF0}, //																			
	{0x82, 0xAF}, //																			
	{0x83, 0x49}, //																			
	{0x84, 0x83}, //																			
	{0x85, 0x85}, //																			
	{0x86, 0x49}, //																			
	{0x87, 0x88}, //																			
	{0x88, 0x84}, //																			
	{0x89, 0x49}, //																			
	{0x8A, 0x88}, //																			
	{0x8B, 0x6A}, //																			
	{0x8C, 0x4C}, //																			
	{0x8D, 0x75}, //																			
	{0x8E, 0x10}, //																			
	{0x8F, 0x0C}, //																			
	{0x90, 0x10}, //																			
	{0x91, 0x0C}, //																			
	{0x92, 0x10}, //																			
	{0x93, 0x0C}, //																			
	{0x94, 0x10}, //																			
	{0x95, 0x0C}, //																			
	{0x96, 0x01}, //																			
	{0x97, 0x01}, //																			
	{0x98, 0x01}, //																			
	{0x99, 0x01}, //																			
	{0x9A, 0x00}, //																			
	{0x9B, 0x00}, //																			
	{0x9C, 0x00}, //																			
	{0x9D, 0x00}, //																			
	{0x9E, 0x42}, //																			
	{0x9F, 0x42}, //																			
	{0xA0, 0x42}, //																			
	{0xA1, 0x42}, //																			
	{0xA2, 0xE8}, //																			
	{0xA3, 0xE8}, //																			
	{0xA4, 0xE8}, //																			
	{0xA5, 0xE8}, //																			

	//gamma
	{0x6C, 0x40}, //																			
	{0x6D, 0x95}, //																			
	{0x6E, 0xAA}, //																			
	{0x6F, 0x3F}, //																			
	{0x70, 0x24}, //																			
	{0x71, 0x48}, //																			
	{0x72, 0x8C}, //																			
	{0x73, 0x20}, //																			
	{0x74, 0x60}, //																			
	{0x75, 0x9C}, //																			
	{0x76, 0xD4}, //																			
	{0x77, 0x00}, //																			
	{0x78, 0x28}, //																			
	{0x79, 0x50}, //																			
	{0x7A, 0x88}, //																			
	{0x7B, 0xC4}, //																			
	{0x7C, 0x28}, //																			
	{0x7D, 0x7C}, //																			
	{0x7E, 0xB4}, //																			
	{0x7F, 0x64}, //																			

	//Bank 01
	{0x21, 0x01}, //																			
	{0x3A, 0x04}, //																			
	{0x5D, 0x20}, //																			
	{0x5E, 0x90}, //																			
	{0x5F, 0xd0}, //																			
	{0x60, 0x05}, // Saturation alpha1=1/4 03->05 @ 0324	
	{0x64, 0x04}, // Edge enhance alpha1=1/2							
	{0xB6, 0x18}, //																			
	{0xB7, 0x20}, //																			
	{0xBB, 0x10}, //																			
	{0xAD, 0x02}, // Add original pixel for Y denoise 		
	{0x21, 0x00}, //																			

	//Bank 3
	{0x21, 0x03}, //																			
	{0x68, 0x20}, //																			
	{0x6C, 0x28}, // 3C 																	
	{0x71, 0x00}, // BLC setting													
	{0x73, 0x70}, //																			
	{0x7C, 0x0B}, //																			
	{0x80, 0xAA}, //																			
	{0x81, 0x2A}, //																			
	{0x83, 0xCA}, //																			
	{0x90, 0x1E}, //;troy 																
	{0x91, 0x16}, //;troy 																
	{0x92, 0x6B}, // 8B->6B, fix pattern noise @ willie 20
	{0x95, 0x08}, //																			
	{0x96, 0x01}, //																			
	{0xA0, 0x00}, // DLB Digital Offset 									
	{0xA1, 0x00}, //																			
	{0xA2, 0x00}, //																			
	{0xA3, 0x00}, //																			
	{0xA4, 0x00}, // AWB R offset 												
	{0xA5, 0x00}, // AWB G offset 												
	{0xA6, 0x01}, // AWB B offset 												
	{0xB7, 0x10}, //																			
	{0xB8, 0x10}, // ABLCMAX															
	{0xBB, 0x10}, // ABLC upper count high byte 					
	{0x21, 0x00}, //																			

	//NewBLC from Andrew suggestion 
	{0x21, 0x03}, //																			
	{0x6C, 0x2A}, //																			
	{0x6D, 0xB0}, //																			
	{0x6E, 0x38}, //																			
	{0x70, 0x50}, //																			
	{0x71, 0x03}, //																			
	{0x73, 0x70}, //																			
	{0x7C, 0x0B}, //																			
	{0x21, 0x00}, //																			

	//Start
	{0x00, 0x01}, //																			
	{0x05, 0x01}, // Turn on rolling shutter							
	{0x00, 0x01}, //

	{0xff,0xff} //array endFlag
};

/*************************************************************************
* FUNCTION
*    HM0356InitialSetting
*
* DESCRIPTION
*    This function initialize the registers of CMOS sensor.
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
static void HM0356InitialSetting(void)
{
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #else
   
   kal_uint32 iEcount;
   for(iEcount=0;(!((0xff==(HM0356YyuvSensorInitialSettingInfo[iEcount].address))&&(0xff==(HM0356YyuvSensorInitialSettingInfo[iEcount].data))));iEcount++)
   {   
	   CamWriteCmosSensor(HM0356YyuvSensorInitialSettingInfo[iEcount].address, HM0356YyuvSensorInitialSettingInfo[iEcount].data);
   }

   #endif
}                                  

/*************************************************************************
* FUNCTION
*    HM0356HalfAdjust
*
* DESCRIPTION
*    This function Dividend / Divisor and use round-up.
*
* PARAMETERS
*    Dividend
*    Divisor
*
* RETURNS
*    [Dividend / Divisor]
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint32 HM0356HalfAdjust(kal_uint32 Dividend, kal_uint32 Divisor)
{
  return (Dividend * 2 + Divisor) / (Divisor * 2); /* that is [Dividend / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    HM0356SetShutterStep
*
* DESCRIPTION
*    This function is to calculate & set shutter step register .
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
static void HM0356SetShutterStep(void)
{    
	
  const kal_uint8  Banding = HM0356Sensor.Banding == CAM_BANDING_50HZ ? HM0356_NUM_50HZ : HM0356_NUM_60HZ;
  const kal_uint16 ShutterStep = HM0356HalfAdjust(HM0356Sensor.Pclk / 2, (HM0356Sensor.Hblank + HM0356_PV_PERIOD_PIXEL_NUMS) * Banding);
  return;// HM0356 is VGA size cature,needn't set shutter

  ASSERT(ShutterStep <= 0xFF);    
  /* 0x34  shutter step*/
  CamWriteCmosSensor(0x34,ShutterStep);
  HM0356Sensor.ShutterStep= ShutterStep;
#ifdef HM0356_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "Set Shutter Step:%x",ShutterStep);
#endif
}

/*************************************************************************
* FUNCTION
*    HM0356SetFrameCount
*
* DESCRIPTION
*    This function is to set frame count register .
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
static void HM0356SetFrameCount(void)
{
  
  kal_uint16 Shutter, FrameCount, DelayTick;
  kal_uint8  Banding = HM0356Sensor.Banding == CAM_BANDING_50HZ ? HM0356_NUM_50HZ : HM0356_NUM_60HZ;
  return;
  FrameCount = Banding * HM0356_FRAME_RATE_UNIT / HM0356Sensor.Fps;
#ifdef HM0356_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "min_fps:%d,FrameCount:%x",HM0356Sensor.Fps / HM0356_FRAME_RATE_UNIT, FrameCount);
#endif
  Shutter = (CamReadCmosSensor(0x30) << 8) | CamReadCmosSensor(0x31);
  DelayTick = Shutter / HM0356Sensor.ShutterStep * 1000 / 120;  // Transfer shutter to frame time (60Hz)
  DelayTick = DelayTick * 1000 / 4615;  // Transfer frame time to delay tick
  if (DelayTick < 8) DelayTick = 8;    // Make sure the delay is enough (30 Fps)

  if (Shutter > 0x4000)
    Shutter = 0xFFF0;
  else
    Shutter = Shutter * 4;

  /* AE must be off to do the following mode change setting.*/
  CamWriteCmosSensor(0x40, 0x00);
  kal_sleep_task(DelayTick);
  /*0x33  FRCNT*/
  CamWriteCmosSensor(0x33,FrameCount&0xFF);
  kal_sleep_task(DelayTick);
  
  /*After the above mode change setting, turn on AE again */
  CamWriteCmosSensor(0x30, Shutter>>8);
  CamWriteCmosSensor(0x31, Shutter&0x00FF);
  CamWriteCmosSensor(0x40, 0x80);
  kal_sleep_task(DelayTick);
}

/*************************************************************************
* FUNCTION
*    HM0356WriteBlank
*
* DESCRIPTION
*    This function write Hblank and Vblank.
*
* PARAMETERS
*    Hblank
*    Vblank
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HM0356WriteBlank(kal_uint16 Hblank,kal_uint16 Vblank)
{
 /*************************************    
  *   Register :0x20 - 0x22    
  *  0x20  [5:4]:HBANK[9:8]; 0x20  [1:0]:VBANK[9:8]
  *  0x21 HBANK[7:0]
  *  0x22 VBANK[7:0]   
  ***************************************/
  //return;
#ifdef HM0356_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HB:%x,VB:%x",Hblank,Vblank);
#endif
  ASSERT(Hblank <= HM0356_BLANK_REGISTER_LIMITATION && Vblank <= HM0356_BLANK_REGISTER_LIMITATION);
  CamWriteCmosSensor(0x12,((0x120/12)&0xFF));
  CamWriteCmosSensor(0x10,((0x14&&0xFF00)>>8));
  CamWriteCmosSensor(0x11,(0x14&0xFF));
  HM0356SetShutterStep();
}

/*************************************************************************
* FUNCTION
*    HM0356CalFps
*
* DESCRIPTION
*    This function calculate & set frame rate and fix frame rate when video mode
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
static void HM0356CalFps(void)
{
  const kal_uint16 MaxFps = (KAL_TRUE == HM0356Sensor.VideoMode) ? HM0356Sensor.Fps : HM0356_MAX_CAMERA_FPS;
  kal_int16 LineLength, DummyLine;
//return;
  LineLength = HM0356Sensor.DummyPixel + HM0356_PV_PERIOD_PIXEL_NUMS;
  DummyLine = HM0356Sensor.Pclk * HM0356_FRAME_RATE_UNIT / (2 * LineLength * MaxFps) - HM0356_PV_PERIOD_LINE_NUMS; 
  if (DummyLine > HM0356_BLANK_REGISTER_LIMITATION)
  {
    DummyLine = HM0356_BLANK_REGISTER_LIMITATION;
    LineLength = HM0356Sensor.Pclk * HM0356_FRAME_RATE_UNIT / (2 * (DummyLine + HM0356_PV_PERIOD_LINE_NUMS) * MaxFps);
  }
  HM0356Sensor.Hblank = LineLength -  HM0356_PV_PERIOD_PIXEL_NUMS;
#ifdef HM0356_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "MaxFps:%d",MaxFps/HM0356_FRAME_RATE_UNIT);
  kal_wap_trace(MOD_ENG,TRACE_INFO, "Dummy Pixel:%x,Hblank,Vblank:%x",HM0356Sensor.DummyPixel,HM0356Sensor.Hblank,DummyLine);
#endif
  HM0356WriteBlank((HM0356Sensor.Hblank > 0) ? HM0356Sensor.Hblank : 0, (DummyLine > 0) ? DummyLine : 0);
}

/*************************************************************************
* FUNCTION
*    HM0356SetHVMirror
*
* DESCRIPTION
*    This function set sensor Mirror
*
* PARAMETERS
*    Mirror
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HM0356SetHVMirror(kal_uint8 Mirror)
{
  kal_uint8 Ctrl = 0;
#ifdef HM0356_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Mirror:%d",Mirror);
#endif 
  Ctrl =  (CamReadCmosSensor(0x06)&(0x77));
  switch (Mirror)
  {
  case IMAGE_SENSOR_MIRROR_HV: Ctrl |= 0x84; break;
  case IMAGE_SENSOR_MIRROR_H:  Ctrl |= 0x80; break;
  case IMAGE_SENSOR_MIRROR_V:  Ctrl |= 0x04; break;
  case IMAGE_SENSOR_MIRROR_NORMAL: Ctrl |= 0x00; break;
  default: Ctrl |= 0x00; break;
  }
  CamWriteCmosSensor(0x06, Ctrl);
  
}

/*************************************************************************
* FUNCTION
*    HM0356Ev
*
* DESCRIPTION
*    HM0356 EV setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_TRUE;
    EvPara->ItemCount = 9;
    EvPara->SupportItem[0] = CAM_EV_NEG_4_3;
    EvPara->SupportItem[1] = CAM_EV_NEG_3_3;
    EvPara->SupportItem[2] = CAM_EV_NEG_2_3;
    EvPara->SupportItem[3] = CAM_EV_NEG_1_3;
    EvPara->SupportItem[4] = CAM_EV_ZERO;
    EvPara->SupportItem[5] = CAM_EV_POS_1_3;
    EvPara->SupportItem[6] = CAM_EV_POS_2_3;
    EvPara->SupportItem[7] = CAM_EV_POS_3_3;
    EvPara->SupportItem[8] = CAM_EV_POS_4_3;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_uint8 EvTemp = 0x00;
#ifdef HM0356_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3: 
		//EvTemp = 0xa0;
		CamWriteCmosSensor(0x5d, 0x50);
		CamWriteCmosSensor(0x30, 0x25);
		CamWriteCmosSensor(0xda, 0x35);
		CamWriteCmosSensor(0xdb, 0x15);
		CamWriteCmosSensor(0x00, 0x01);
		break;
    case CAM_EV_NEG_3_3: 
		//EvTemp = 0x98; 
		CamWriteCmosSensor(0x5d, 0x60);
		CamWriteCmosSensor(0x30, 0x2d);
		CamWriteCmosSensor(0xda, 0x3d);
		CamWriteCmosSensor(0xdb, 0x1d);
		CamWriteCmosSensor(0x00, 0x01);
		break;
    case CAM_EV_NEG_2_3: 
		//EvTemp = 0x90; 
		CamWriteCmosSensor(0x5d, 0x70);
		CamWriteCmosSensor(0x30, 0x35);
		CamWriteCmosSensor(0xda, 0x45);
		CamWriteCmosSensor(0xdb, 0x25);
		CamWriteCmosSensor(0x00, 0x01);
		break;
    case CAM_EV_NEG_1_3: 
		//EvTemp = 0x88; 
		CamWriteCmosSensor(0x5d, 0x80);
		CamWriteCmosSensor(0x30, 0x3d);
		CamWriteCmosSensor(0xda, 0x4d);
		CamWriteCmosSensor(0xdb, 0x2d);
		CamWriteCmosSensor(0x00, 0x01);
		break;
    case CAM_EV_ZERO:    
		//EvTemp = 0x00; 
		CamWriteCmosSensor(0x5d, 0x90);
		CamWriteCmosSensor(0x30, 0x45);
		CamWriteCmosSensor(0xda, 0x55);
		CamWriteCmosSensor(0xdb, 0x35);
		CamWriteCmosSensor(0x00, 0x01);
		break;
    case CAM_EV_POS_1_3: 
		//EvTemp = 0x08; 
		CamWriteCmosSensor(0x5d, 0x98);
		CamWriteCmosSensor(0x30, 0x55);
		CamWriteCmosSensor(0xda, 0x65);
		CamWriteCmosSensor(0xdb, 0x45);
		CamWriteCmosSensor(0x00, 0x01);
		break;
    case CAM_EV_POS_2_3: 
		//EvTemp = 0x10; 
		CamWriteCmosSensor(0x5d, 0xa0);
		CamWriteCmosSensor(0x30, 0x65);
		CamWriteCmosSensor(0xda, 0x75);
		CamWriteCmosSensor(0xdb, 0x55);
		CamWriteCmosSensor(0x00, 0x01);
		break;
    case CAM_EV_POS_3_3: 
		//EvTemp = 0x18; 
		CamWriteCmosSensor(0x5d, 0xa8);
		CamWriteCmosSensor(0x30, 0x75);
		CamWriteCmosSensor(0xda, 0x85);
		CamWriteCmosSensor(0xdb, 0x65);
		CamWriteCmosSensor(0x00, 0x01);
		break;
    case CAM_EV_POS_4_3: 
		//EvTemp = 0x20; 
		CamWriteCmosSensor(0x5d, 0xb0);
		CamWriteCmosSensor(0x30, 0x85);
		CamWriteCmosSensor(0xda, 0x95);
		CamWriteCmosSensor(0xdb, 0x75);
		CamWriteCmosSensor(0x00, 0x01);

		break;
    default: 
		break;
    }
    //CamWriteCmosSensor(0xd7, EvTemp);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356Contrast
*
* DESCRIPTION
*    HM0356 Contrast setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_TRUE;
    EvPara->ItemCount = 3;
    EvPara->SupportItem[0] = CAM_CONTRAST_HIGH;
    EvPara->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    EvPara->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_uint8 Contrast = 0x10;
#ifdef HM0356_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   
		//Contrast = 0x18; 
		break;
    case CAM_CONTRAST_MEDIUM: 
		//Contrast = 0x10; 
		break;
    case CAM_CONTRAST_LOW:  
		//Contrast = 0x08; 
		break;
    default: break;
    }
    //CamWriteCmosSensor(0xd4, Contrast);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356Wb
*
* DESCRIPTION
*    HM0356 WB setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT WBPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    WBPara->IsSupport = KAL_TRUE;
    WBPara->ItemCount = 6;
    WBPara->SupportItem[0] = CAM_WB_AUTO;
    WBPara->SupportItem[1] = CAM_WB_CLOUD;
    WBPara->SupportItem[2] = CAM_WB_DAYLIGHT;
    WBPara->SupportItem[3] = CAM_WB_INCANDESCENCE;
    WBPara->SupportItem[4] = CAM_WB_FLUORESCENT;
    WBPara->SupportItem[5] = CAM_WB_TUNGSTEN;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef HM0356_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO: /* enable AWB */
      /* CAM_WB_AUTO mode should not update R/G/B gains */
      CamWriteCmosSensor(0x23, 0xFF);
      break;
    case CAM_WB_CLOUD:
      CamWriteCmosSensor(0x23, 0xFD);  /* disable AWB */
	  kal_sleep_task(125);//delay 500ms for wb effect about 1 to 2 frame
      CamWriteCmosSensor(0xbe, 0x15);
      CamWriteCmosSensor(0xbf, 0x20);// Red channel gain
	  CamWriteCmosSensor(0xc0, 0x00);// Green channel gain
	  CamWriteCmosSensor(0xc1, 0x00);// Blue channel gain
	  CamWriteCmosSensor(0x00, 0x01);//Update regester
      break;
    case CAM_WB_DAYLIGHT:
		CamWriteCmosSensor(0x23, 0xFD);  /* disable AWB */
		kal_sleep_task(125);//delay 500ms for wb effect about 1 to 2 frame
		CamWriteCmosSensor(0xbe, 0x15);
		CamWriteCmosSensor(0xbf, 0x1e);// Red channel gain
		CamWriteCmosSensor(0xc0, 0x00);// Green channel gain
		CamWriteCmosSensor(0xc1, 0x01);// Blue channel gain
		CamWriteCmosSensor(0x00, 0x01);//Update regester
      break;
    case CAM_WB_INCANDESCENCE:
		CamWriteCmosSensor(0x23, 0xFD);  /* disable AWB */
		kal_sleep_task(125);//delay 500ms for wb effect about 1 to 2 frame
		CamWriteCmosSensor(0xbe, 0x25);
		CamWriteCmosSensor(0xbf, 0x00);// Red channel gain
		CamWriteCmosSensor(0xc0, 0x1b);// Green channel gain
		CamWriteCmosSensor(0xc1, 0x40);// Blue channel gain
		CamWriteCmosSensor(0x00, 0x01);//Update regester
      break;
    case CAM_WB_FLUORESCENT:
		CamWriteCmosSensor(0x23, 0xFD);  /* disable AWB */
		kal_sleep_task(125);//delay 500ms for wb effect about 1 to 2 frame
		CamWriteCmosSensor(0xbe, 0x25);
		CamWriteCmosSensor(0xbf, 0x56);// Red channel gain
		CamWriteCmosSensor(0xc0, 0x00);// Green channel gain
		CamWriteCmosSensor(0xc1, 0x08);// Blue channel gain
		CamWriteCmosSensor(0x00, 0x01);//Update regester
      break;
    case CAM_WB_TUNGSTEN:
		CamWriteCmosSensor(0x23, 0xFD);  /* disable AWB */
		kal_sleep_task(125);//delay 500ms for wb effect about 1 to 2 frame
		CamWriteCmosSensor(0xbe, 0x25);
		CamWriteCmosSensor(0xbf, 0x00);// Red channel gain
		CamWriteCmosSensor(0xc0, 0x2b);// Green channel gain
		CamWriteCmosSensor(0xc1, 0x40);// Blue channel gain
		CamWriteCmosSensor(0x00, 0x01);//Update regester
      break;
    default:
		return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356Effect
*
* DESCRIPTION
*    HM0356 Effect setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 6;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    //EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
    //EffectPara->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
    //EffectPara->SupportItem[8] = CAM_EFFECT_ENC_SKETCH;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef HM0356_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
 //return MM_ERROR_NONE;
	CamWriteCmosSensor(0x05, 0x00);
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
      CamWriteCmosSensor(0x25, 0x09);
	  CamWriteCmosSensor(0x50, 0x10);
	  CamWriteCmosSensor(0x62, 0x00);
	  CamWriteCmosSensor(0x63, 0xFF);
	  CamWriteCmosSensor(0x00, 0x01);

	  CamWriteCmosSensor(0x05, 0x01);
	  CamWriteCmosSensor(0x00, 0x01);
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
      CamWriteCmosSensor(0x25, 0x49);
	  CamWriteCmosSensor(0x50, 0x10);
	  CamWriteCmosSensor(0x62, 0x80);
	  CamWriteCmosSensor(0x63, 0x80);
	  CamWriteCmosSensor(0x00, 0x01);

	  CamWriteCmosSensor(0x05, 0x01);
	  CamWriteCmosSensor(0x00, 0x01);
      break;
    case CAM_EFFECT_ENC_SEPIA:
      CamWriteCmosSensor(0x25, 0x49);
	  CamWriteCmosSensor(0x50, 0x00);
	  CamWriteCmosSensor(0x62, 0x40);
	  CamWriteCmosSensor(0x63, 0x90);
	  CamWriteCmosSensor(0x00, 0x01);

	  CamWriteCmosSensor(0x05, 0x01);
	  CamWriteCmosSensor(0x00, 0x01);
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
      CamWriteCmosSensor(0x25, 0x49);
	  CamWriteCmosSensor(0x50, 0x10);
	  CamWriteCmosSensor(0x62, 0x60);
	  CamWriteCmosSensor(0x63, 0x60);
	  CamWriteCmosSensor(0x00, 0x01);

	  CamWriteCmosSensor(0x05, 0x01);
	  CamWriteCmosSensor(0x00, 0x01);
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
      CamWriteCmosSensor(0x25, 0x49);
	  CamWriteCmosSensor(0x50, 0x10);
	  CamWriteCmosSensor(0x62, 0xB0);
	  CamWriteCmosSensor(0x63, 0x80);
	  CamWriteCmosSensor(0x00, 0x01);

	  CamWriteCmosSensor(0x05, 0x01);
	  CamWriteCmosSensor(0x00, 0x01);
      break;
    case CAM_EFFECT_ENC_COLORINV:
      CamWriteCmosSensor(0x25, 0x09);
	  CamWriteCmosSensor(0x50, 0x90);
	  CamWriteCmosSensor(0x62, 0x00);
	  CamWriteCmosSensor(0x63, 0xFF);
	  CamWriteCmosSensor(0x00, 0x01);

	  CamWriteCmosSensor(0x05, 0x01);
	  CamWriteCmosSensor(0x00, 0x01);
      break;
    
    default:
		return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
      break;
    }
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356StillCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out, OutLen, RealOutLen
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_GET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 2;
    CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356Banding
*
* DESCRIPTION
*    This function get banding setting
*
* PARAMETERS
*    In, Out, OutLen, RealOutLen
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = &Out->FeatureInfo.FeatureEnum;
  //return MM_ERROR_NONE;
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
#ifdef HM0356_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif
    HM0356Sensor.Banding = In->FeatureSetValue;
    HM0356SetShutterStep();
    HM0356SetFrameCount();    
  }  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356GetSensorInfo
*
* DESCRIPTION
*    This function get sensor infomation
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HM0356GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = HM0356_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_HIGH;
  //Info->DrivingCurrent = ISP_DRIVING_8MA;
//#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
#if 1
  Info->PreviewMclkFreq = 24000000;
  Info->CaptureMclkFreq = 24000000;
  Info->VideoMclkFreq = 24000000;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
  Info->PreviewWidth = HM0356_IMAGE_SENSOR_VGA_WIDTH;
  Info->PreviewHeight = HM0356_IMAGE_SENSOR_VGA_HEIGHT;
  Info->FullWidth = HM0356_IMAGE_SENSOR_VGA_WIDTH;
  Info->FullHeight = HM0356_IMAGE_SENSOR_VGA_HEIGHT;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;

}
/*************************************************************************
* FUNCTION
*    HM0356DetectSensorId
*
* DESCRIPTION
*    This function detect sensor Id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor Id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 HM0356DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM HM0356SensorClose(void);
  kal_uint16 HM0356PowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  kal_prompt_trace(MOD_ENG,"HM0356DetectSensorId");
  if (IMAGE_SENSOR_MAIN == HM0356Sensor.SensorIdx)
  {
    AnotherSensorIdx = IMAGE_SENSOR_SUB;
  }
  else
  {
    AnotherSensorIdx = IMAGE_SENSOR_MAIN;
  }
  for (i = 1; i >= 0; i--)
  {
    for (j = 1; j >= 0; j--)
    {
      CamRstPinCtrl(AnotherSensorIdx, i);
      CamPdnPinCtrl(AnotherSensorIdx, j);
      SensorId = HM0356PowerOn();
      HM0356SensorClose();
#ifdef HM0356_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"HM0356DetectSensorId:%x",SensorId);
#endif
      if (HM0356_SENSOR_ID == SensorId)
      {
          kal_prompt_trace(MOD_ENG,"HM0356 has Detected SensorId");
        return HM0356_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    HM0356InitOperationPara
*
* DESCRIPTION
*    This function set sensor operation Para
*
* PARAMETERS
*    Para
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HM0356InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 3; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    HM0356AeEnable
*
* DESCRIPTION
*    disable/enable AE
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356AeEnable(kal_bool Enable)
{
  kal_uint8 AeTemp;
  if (HM0356Sensor.BypassAe)
	{
		Enable = KAL_FALSE;
	}
  AeTemp = CamReadCmosSensor(0x23);

  if (Enable)
  {
    AeTemp |= 0x01;
  }
  else
  {
    AeTemp &= 0xFE;
  }
#ifdef HM0356_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x23, AeTemp);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356AwbEnable
*
* DESCRIPTION
*    disable/enable awb
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356AwbEnable(kal_bool Enable)
{
  kal_uint8 AwbTemp;
  if (HM0356Sensor.BypassAwb)
	{
		Enable = KAL_FALSE;
	}
  AwbTemp = CamReadCmosSensor(0x23);

  if (Enable)
  {
    AwbTemp |= 0x02;
  }
  else
  {
    AwbTemp &= 0xFD;
  }
#ifdef HM0356_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x60, AwbTemp);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356_cal_fps
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
static void HM0356FixFrameRate(kal_uint8 fps)
{
    kal_uint32 Dummy_Line;

	//return;
    Dummy_Line = HM0356Sensor.Pclk * HM0356_FRAME_RATE_UNIT / (2 * HM0356_FULL_PERIOD_PIXEL_NUMS * fps) - HM0356_FULL_PERIOD_LINE_NUMS; 

#ifdef HM0356_DEBUG
   kal_wap_trace(MOD_ENG,TRACE_INFO, "max_fps:%d",fps/HM0356_FRAME_RATE_UNIT);
   kal_wap_trace(MOD_ENG,TRACE_INFO, "Dummy Pixel:%x,",Dummy_Line);
#endif
	//fix 15fps
	CamWriteCmosSensor(0x10, ((Dummy_Line>>8)&0xff));//high vblank
	CamWriteCmosSensor(0x11, (Dummy_Line&0xff));//low vblank
}
/*************************************************************************
* FUNCTION
*    HM0356NightMode
*
* DESCRIPTION
*    This function switch on/off night mode
*
* PARAMETERS
*    enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HM0356NightMode(kal_bool Enable)
{
	
#ifdef HM0356_DEBUG
	  kal_wap_trace(MOD_ENG,TRACE_INFO, "HM0356 NightMode %d",Enable);
#endif
	if(Enable)
	{

		//night
		CamWriteCmosSensor(0x21, 0x00);
		CamWriteCmosSensor(0x60, 0x49);
		CamWriteCmosSensor(0xC3, 0x38);

		//
		//{0x31, 0x02}, // Max Exposure 												
		//{0x32, 0xE4}, // Max Exposure 19.9f	
		//CamWriteCmosSensor(0x31, 0x05);
		//CamWriteCmosSensor(0x32, 0xC2);
		CamWriteCmosSensor(0x31, 0x0B);
		CamWriteCmosSensor(0x32, 0xBF);
		//HM0356_write_cmos_sensor(0x35, 0xC0);
		CamWriteCmosSensor(0x35, 0xD0); //Dgain
	
		CamWriteCmosSensor(0x70, 0x0B);
		CamWriteCmosSensor(0x71, 0x2B);
	
		CamWriteCmosSensor(0x21, 0x01);
		CamWriteCmosSensor(0xB6, 0x25);
		CamWriteCmosSensor(0xB7, 0x25);
		CamWriteCmosSensor(0xAD, 0x04);
	
		CamWriteCmosSensor(0x21, 0x03);
		CamWriteCmosSensor(0x90, 0x12);
		CamWriteCmosSensor(0x91, 0x96);
		CamWriteCmosSensor(0x21, 0x00);

		//SECONDE DEBUG ADD REG
		CamWriteCmosSensor(0x35, 0xC8);
		CamWriteCmosSensor(0x21, 0x01);
		CamWriteCmosSensor(0x5D, 0x10);
		CamWriteCmosSensor(0x60, 0x4C);
		CamWriteCmosSensor(0x21, 0x00);

		
		if (HM0356Sensor.VideoMode == KAL_TRUE) //night 15p
		{   // MPEG4 Encode Mode

		#ifdef HM0356_DEBUG
			  kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
		#endif
			
		#if (defined(__SENSOR_FRAME_RATE_SUPPORT__))
			HM0356_SensorCommonFrameIn.NighhtMode = Enable;
			HM0356_retFrameRateResult = SensorCommonGetFrameRate(&HM0356_SensorCommonFrameIn, &HM0356_SensorCommonFrameOut);
		
			if(HM0356_retFrameRateResult == MM_ERROR_NONE)
			{
				HM0356FixFrameRate(HM0356_SensorCommonFrameOut.MaxSensorFrameRate);
			}
		#else
			//fix 15fps
			CamWriteCmosSensor(0x10, 0x02);
			CamWriteCmosSensor(0x11, 0x02);//?
		#endif	/* #if (defined(__SENSOR_FRAME_RATE_SUPPORT__)) */
		
			CamWriteCmosSensor(0x31, 0x01);
			CamWriteCmosSensor(0x32, 0xff);
			CamWriteCmosSensor(0x38, 0x99);
			CamWriteCmosSensor(0x21, 0x03);
			CamWriteCmosSensor(0x89, 0x00);
			CamWriteCmosSensor(0x8a, 0x45);
			CamWriteCmosSensor(0x21, 0x00);
		}
		
		#ifdef HM0356_DEBUG
			  kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
		#endif
	}
	else
	{	
		//day
		CamWriteCmosSensor(0x21, 0x00);
		CamWriteCmosSensor(0x60, 0x48);
		CamWriteCmosSensor(0xC3, 0x58);
	
		CamWriteCmosSensor(0x31, 0x02);
		CamWriteCmosSensor(0x32, 0xE4);
		CamWriteCmosSensor(0x35, 0xFF);
		
		CamWriteCmosSensor(0x70, 0x24);
		CamWriteCmosSensor(0x71, 0x48),
		
		CamWriteCmosSensor(0x21, 0x01);
		CamWriteCmosSensor(0xB6, 0x18);
		CamWriteCmosSensor(0xB7, 0x20);
		CamWriteCmosSensor(0xAD, 0x02);
		
		CamWriteCmosSensor(0x21, 0x03);
		CamWriteCmosSensor(0x90, 0x1E);//
		CamWriteCmosSensor(0x91, 0x16);//
		
		CamWriteCmosSensor(0xAC, 0xD0);
		CamWriteCmosSensor(0xAD, 0xA8);
		
		CamWriteCmosSensor(0x21, 0x00);

		//second add
		CamWriteCmosSensor(0x82, 0x90);
		CamWriteCmosSensor(0x8b, 0x60);
		
		CamWriteCmosSensor(0xc8, 0x80);//cwf
		CamWriteCmosSensor(0xc3, 0x38);
		CamWriteCmosSensor(0xca, 0x5a);
		
		CamWriteCmosSensor(0x21, 0x01);
		CamWriteCmosSensor(0x5d, 0x50);//80 70 5b
		CamWriteCmosSensor(0x80, 0x0B);
		
		CamWriteCmosSensor(0x21, 0x00);
		
		if (HM0356Sensor.VideoMode == KAL_TRUE) // 30f
		{   // MPEG4 Encode Mode
		
	#ifdef HM0356_DEBUG
		  kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
	#endif
		#if (defined(__SENSOR_FRAME_RATE_SUPPORT__))
			HM0356_SensorCommonFrameIn.NighhtMode = Enable;
			HM0356_retFrameRateResult = SensorCommonGetFrameRate(&HM0356_SensorCommonFrameIn, &HM0356_SensorCommonFrameOut);
		
			if(HM0356_retFrameRateResult == MM_ERROR_NONE)
			{
				HM0356FixFrameRate(HM0356_SensorCommonFrameOut.MaxSensorFrameRate);
			}
		#endif	/* #if (defined(__SENSOR_FRAME_RATE_SUPPORT__)) */
			//fix 30fps
			CamWriteCmosSensor(0x31, 0x01);
			CamWriteCmosSensor(0x32, 0xff);
			CamWriteCmosSensor(0x38, 0x99);
			CamWriteCmosSensor(0x21, 0x03);
			CamWriteCmosSensor(0x89, 0x00);
			CamWriteCmosSensor(0x8a, 0x45);
			CamWriteCmosSensor(0x21, 0x00);
		}
		
		#ifdef HM0356_DEBUG
			  kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
		#endif
	}

		
	
}
/*************************************************************************
* FUNCTION
*    MT9D112SceneMode
*
* DESCRIPTION
*    This function get/set scene mode of sensor.
*
* PARAMETERS
*    IsCam: camera scene mode or not
*    In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356SceneMode(kal_bool IsCam, P_CAL_FEATRUE_CTRL_STRUCT In, P_CAL_FEATRUE_CTRL_STRUCT Out)
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
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_bool Enable;
    
    if (CAM_NIGHTSCENE == In->FeatureSetValue || CAM_VIDEO_NIGHT == In->FeatureSetValue)
    {
      Enable = KAL_TRUE;
    }
    else
    {
      Enable = KAL_FALSE;
    }
    HM0356NightMode(Enable);
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    HM0356PowerOn
*
* DESCRIPTION
*    This function reset sensor and read Id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor Id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 HM0356PowerOn(void)
{
  kal_uint16 SensorId,temp1,temp2;
  /* PowerOn the sensor */
  kal_prompt_trace(MOD_ENG,"OV2659PowerOn_enter");
  CisModulePowerOn(HM0356Sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, HM0356_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 100);
  kal_sleep_task(2);  /* delay for power stable */
  
  /* set sensors chip enable pin to low to activate HM0356 */
  CamPdnPinCtrl(HM0356Sensor.SensorIdx, 0);
  kal_sleep_task(1);
  
  /* Reset the sensor */
  CamRstPinCtrl(HM0356Sensor.SensorIdx, 1);
  kal_sleep_task(2);
  CamRstPinCtrl(HM0356Sensor.SensorIdx, 0);
  kal_sleep_task(4);
  CamRstPinCtrl(HM0356Sensor.SensorIdx, 1);
  /* delay for stable sensor */  
  kal_sleep_task(2);
  
  /* Read Sensor ID  */
  temp1 = CamReadCmosSensor(HM0356_ID_REG);
  temp2 = CamReadCmosSensor(HM0356_INFO_REG);
  SensorId = (temp1 << 8)|temp2;
 // SensorId = (CamReadCmosSensor(HM0356_ID_REG) << 8)|CamReadCmosSensor(HM0356_INFO_REG);
#ifdef HM0356_DEBUG
	kal_prompt_trace(MOD_AUX,"HM0356 Sensor ID: %x,%x,%x ",temp1,temp2,SensorId);
  kal_wap_trace(MOD_ENG, TRACE_INFO, "HM0356 Sensor ID: %x,%x,%x ",temp1,temp2,SensorId);
#endif
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    HM0356Preview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HM0356Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  //kal_uint8 StartX = 0, StartY = 1;
  kal_uint8 StartX = 4, StartY = 4;

#ifdef HM0356_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HM0356 Preview");
#endif

  HM0356Sensor.Banding = In->BandingFreq;
  HM0356Sensor.NightMode = In->NightMode;
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    HM0356Sensor.VideoMode = KAL_TRUE;
    HM0356Sensor.Fps = In->MaxVideoFrameRate * HM0356_FRAME_RATE_UNIT / 10;
    break;
  //case CAL_SCENARIO_CAMERA_PREVIEW:
  //  HM0356Sensor.VideoMode = KAL_FALSE;
  //  HM0356Sensor.Fps = HM0356_FRAME_RATE_UNIT * (HM0356Sensor.NightMode ? 5 : 10);
	//break;
  //case CAL_SCENARIO_WEBCAM_PREVIEW:
  //case CAL_SCENARIO_WEBCAM_CAPTURE:
  default:
    //StartX += 40;
    //StartY += 30;
    HM0356Sensor.VideoMode = KAL_FALSE;
    HM0356Sensor.Fps = HM0356_FRAME_RATE_UNIT * (HM0356Sensor.NightMode ? 15 : 30);
    break;
  //default:
   // break;
  }

 // if(mmi_camco_setting_p->camzoom.)
  HM0356SetHVMirror(In->ImageMirror);
  HM0356NightMode(HM0356Sensor.NightMode);
  HM0356CalFps();
  //HM0356SetFrameCount();

  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = HM0356_IMAGE_SENSOR_VGA_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = HM0356_IMAGE_SENSOR_VGA_HEIGHT - 2 * StartY;
}

/*************************************************************************
* FUNCTION
*    HM0356Capture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void HM0356Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 4, StartY = 4;

#ifdef HM0356_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HM0356 Capture");
#endif
  #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #else
  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = HM0356_IMAGE_SENSOR_FULL_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = HM0356_IMAGE_SENSOR_FULL_HEIGHT - 2 * StartY;
  #endif
}

/*************************************************************************
* FUNCTION
*    HM0356SensorOpen
*
* DESCRIPTION
*    This function read sensor Id and init sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356SensorOpen(void)
{
  if (HM0356_SENSOR_ID != HM0356PowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  HM0356InitialSetting();
  HM0356Sensor.VideoMode = KAL_FALSE;
  HM0356Sensor.NightMode = KAL_FALSE;
  HM0356Sensor.Banding = CAM_BANDING_50HZ;
//#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
#if 1
  HM0356Sensor.Pclk = 24000000;
#else
/* under construction !*/
#endif
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  HM0356Sensor.DummyPixel = 0x1c;
#else
  HM0356Sensor.DummyPixel = 0x0;
#endif
  HM0356Sensor.Fps = 30 * HM0356_FRAME_RATE_UNIT;
  HM0356Sensor.ShutterStep= 0x96;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356SensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    Id: scenario Id
*    In: input parameter
*    Out: output parameter
*    OutLen: output parameter length
*    RealOutLen: real output parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
#ifdef HM0356_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "HM0356 FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return HM0356WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = HM0356Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = HM0356Contrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = HM0356Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = HM0356Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = HM0356StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* Only query here, set function move to preview */
    ErrCode = HM0356Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
	ErrCode = HM0356SceneMode(KAL_TRUE, In, Out);
	break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
	ErrCode = HM0356SceneMode(KAL_FALSE, In, Out);
	break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    HM0356GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = HM0356DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = HM0356Sensor.Fps * 10 / HM0356_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    HM0356InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(HM0356Sensor.SensorIdx, Out);
	//CamGetHWInfo(Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(HM0356Sensor.SensorIdx, 0);  
	CamRstPinCtrl(HM0356Sensor.SensorIdx, 1); 
    CamRstPinCtrl(HM0356Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    HM0356Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    HM0356Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    HM0356Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    HM0356AeEnable(HM0356Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    HM0356Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    HM0356AwbEnable(HM0356Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    HM0356SensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    Id: scenario Id
*    In/Out: parameter
*    OutLen: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    HM0356Preview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    HM0356Capture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356SensorClose
*
* DESCRIPTION
*    This function is to turn off sensor module power.
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM HM0356SensorClose(void)
{
  /* power down sensor */
  CamPdnPinCtrl(HM0356Sensor.SensorIdx, 0);
  CamRstPinCtrl(HM0356Sensor.SensorIdx, 0);
  CisModulePowerOn(HM0356Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    HM0356SensorFunc
*
* DESCRIPTION
*    This function get sensor function pointer
*
* PARAMETERS
*    sensor function pointer
*
* RETURNS
*    error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM HM0356SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncHM0356 =
  {
    HM0356SensorOpen,
    HM0356SensorFeatureCtrl,
    HM0356SensorCtrl,
    HM0356SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncHM0356;
  
  return MM_ERROR_NONE;
}

