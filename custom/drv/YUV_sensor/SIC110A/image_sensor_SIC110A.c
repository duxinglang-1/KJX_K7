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
 *   image_sensor_SIC110A.c
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

/* #define SIC110A_DEBUG */
static struct
{
  kal_uint8 Banding;
  kal_uint8 Control;
  kal_bool NightMode;
  kal_bool VideoMode;
  kal_uint16 Fps;
  kal_uint32 Pclk;
  kal_uint16 DummyPixel; /* for user customization */
  kal_uint16 Hblank; /* for calculating shutter step */
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} SIC110ASensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    SIC110ASetPage
*
* DESCRIPTION
*    This function set the register page of CMOS sensor.
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
static void SIC110ASetPage(kal_uint8 Page)
{    
    CamWriteCmosSensor(0x00,Page);
}

/*************************************************************************
* FUNCTION
*    SIC110AInitialSetting
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
static void SIC110AInitialSetting(void)
{
  ////SNR Block
  SIC110ASetPage(0);
  CamWriteCmosSensor(0x03,0x55);
  CamWriteCmosSensor(0x04,0x00);//
  CamWriteCmosSensor(0x05,0x02);//CIF
  CamWriteCmosSensor(0x10,0x00);//0x01//0x00
  CamWriteCmosSensor(0x11,0x01);//0x34//0x01 //3 --> For mode Detailed Image
  CamWriteCmosSensor(0x12,0x11);//0x23//0x13 
  CamWriteCmosSensor(0x13,0x17);
  CamWriteCmosSensor(0x20,0x10); //HBNKT,VBNKT
  CamWriteCmosSensor(0x21,0x37); //HBNKT
  CamWriteCmosSensor(0x23,0xBF); //HBNKT
  //CamWriteCmosSensor(0x15,0x7f);
  ////Flicker
  CamWriteCmosSensor(0x40,0x00);
  CamWriteCmosSensor(0x41,0x16);
  CamWriteCmosSensor(0x42,0x32);
  CamWriteCmosSensor(0x43,0x80);
  //AEBlock
  //AEB
  SIC110ASetPage(1);
  CamWriteCmosSensor(0x10,0x00);////0603
  CamWriteCmosSensor(0x11,0x0a);////0x10
  CamWriteCmosSensor(0x12,0x65);////a target
  CamWriteCmosSensor(0x13,0x65);////a target
  CamWriteCmosSensor(0x14,0x65);////a target
  CamWriteCmosSensor(0x18,0x8f);
  CamWriteCmosSensor(0x19,0x00);
  CamWriteCmosSensor(0x1c,0x00);////0603
  CamWriteCmosSensor(0x34,0x96);//increase the VBLANK time
  CamWriteCmosSensor(0x40,0x4C);////0603
  CamWriteCmosSensor(0x41,0x18);////09-11-14 for peak and AE vibrate

  ////AWB Block
  SIC110ASetPage(2);
  CamWriteCmosSensor(0x10,0xd3);
  CamWriteCmosSensor(0x11,0xc0);////0x00
  CamWriteCmosSensor(0x13,0x80);
  CamWriteCmosSensor(0x14,0x7f);
  CamWriteCmosSensor(0x15,0xfe);
  CamWriteCmosSensor(0x16,0x80);
  CamWriteCmosSensor(0x17,0xea);
  CamWriteCmosSensor(0x18,0x80);
  CamWriteCmosSensor(0x19,0xa0);//0xdd
  CamWriteCmosSensor(0x1a,0x70);//0x50
  CamWriteCmosSensor(0x1b,0xa0);//0xdd
  CamWriteCmosSensor(0x1c,0x70);//0x50
  CamWriteCmosSensor(0x1d,0xb0);//0x90
  CamWriteCmosSensor(0x1e,0x70);
  CamWriteCmosSensor(0x20,0xfe);//0xe8
  CamWriteCmosSensor(0x21,0x98);//0x20
  CamWriteCmosSensor(0x22,0x9d);
  CamWriteCmosSensor(0x23,0x18);
  CamWriteCmosSensor(0x25,0x20);
  CamWriteCmosSensor(0x26,0x0f);
  CamWriteCmosSensor(0x27,0x00);//0x0d
  CamWriteCmosSensor(0x28,0x00);//0x90
  CamWriteCmosSensor(0x29,0xd0);
  CamWriteCmosSensor(0x2a,0x90);
  CamWriteCmosSensor(0x30,0x05);
  CamWriteCmosSensor(0x41,0x04);
  CamWriteCmosSensor(0x44,0x13);
  CamWriteCmosSensor(0x45,0x6b);
  CamWriteCmosSensor(0x46,0xa3);//0x64
  //RGB to YCbCr CSC no used
  CamWriteCmosSensor(0x50,0x33);
  CamWriteCmosSensor(0x51,0x20);
  CamWriteCmosSensor(0x52,0xe5);
  CamWriteCmosSensor(0x53,0xfb);
  CamWriteCmosSensor(0x54,0x13);
  CamWriteCmosSensor(0x55,0x26);
  CamWriteCmosSensor(0x56,0x07);
  CamWriteCmosSensor(0x57,0xf5);
  CamWriteCmosSensor(0x58,0xea);
  CamWriteCmosSensor(0x59,0x21);

  CamWriteCmosSensor(0x62,0x88);  //AWB G Gain up.
  //D65 D30 D20
  CamWriteCmosSensor(0x63,0x90); // 0x93);//0xbd
  CamWriteCmosSensor(0x64,0xb1); // 0xbf);
  CamWriteCmosSensor(0x65,0x90); // 0x93);//0xbd
  CamWriteCmosSensor(0x66,0xb3); // 0xbf);//0xc2
  CamWriteCmosSensor(0x67,0xb0); // 0xb0);//0xef
  CamWriteCmosSensor(0x68,0xa0); // 0xa0);
  //AWB
  CamWriteCmosSensor(0x69,0xb0); //0xef
  CamWriteCmosSensor(0x6a,0x98); // 0xa0);
  //IDP
  SIC110ASetPage(3);
  CamWriteCmosSensor(0x10,0xEF);
  CamWriteCmosSensor(0x11,0x19);//YUV Full mode
  CamWriteCmosSensor(0x12,0x3d);//ouput data synchronizing PCLK edge polarity control 
  //Shading
  CamWriteCmosSensor(0x27,0xFF);
  CamWriteCmosSensor(0x28,0xFF);
  CamWriteCmosSensor(0x29,0xDF);
  CamWriteCmosSensor(0x2a,0x95);
  CamWriteCmosSensor(0x2b,0x31);
  
  CamWriteCmosSensor(0x2c,0xBE);//0xCF
  CamWriteCmosSensor(0x2d,0xC9);//0x30
  CamWriteCmosSensor(0x2e,0x06);
  CamWriteCmosSensor(0x2f,0x00);
  CamWriteCmosSensor(0x30,0x00);
  CamWriteCmosSensor(0x31,0x00);
  CamWriteCmosSensor(0x32,0x61);
  CamWriteCmosSensor(0x33,0x3F);
  //gamma
  CamWriteCmosSensor(0x34,0x00);
  CamWriteCmosSensor(0x35,0x0b);
  CamWriteCmosSensor(0x36,0x15);
  CamWriteCmosSensor(0x37,0x29);
  CamWriteCmosSensor(0x38,0x4a);
  CamWriteCmosSensor(0x39,0x66);
  CamWriteCmosSensor(0x3a,0x7a);
  CamWriteCmosSensor(0x3b,0x8d);
  CamWriteCmosSensor(0x3c,0x9d);
  CamWriteCmosSensor(0x3d,0xaa);
  CamWriteCmosSensor(0x3e,0xb6);
  CamWriteCmosSensor(0x3f,0xcb);
  CamWriteCmosSensor(0x40,0xde);
  CamWriteCmosSensor(0x41,0xf0);
  //RGB
  CamWriteCmosSensor(0x42,0xf8);
  CamWriteCmosSensor(0x43,0xff);
  //DPC,De-Noise
  CamWriteCmosSensor(0x44,0xbb);
  CamWriteCmosSensor(0x45,0x10);
  CamWriteCmosSensor(0x46,0x47);//0x27,0603 //091028
  CamWriteCmosSensor(0x47,0x00); //091028
  CamWriteCmosSensor(0x48,0x08);//de-noise threshold
  CamWriteCmosSensor(0x49,0x8f);
  CamWriteCmosSensor(0x4a,0xff);
  CamWriteCmosSensor(0x4b,0x30);//de-noise start gain
  CamWriteCmosSensor(0x4c,0xb1);//interpolation
  CamWriteCmosSensor(0x4d,0x05);
  CamWriteCmosSensor(0x4e,0xff);
  CamWriteCmosSensor(0x4f,0x04);//LPF Threshold
  CamWriteCmosSensor(0x53,0x00);//edge detection
  //D65 CMA 
  CamWriteCmosSensor(0x54,0x3a);
  CamWriteCmosSensor(0x55,0xcb);
  CamWriteCmosSensor(0x56,0xfb);
  CamWriteCmosSensor(0x57,0x13);
  //IDP
  CamWriteCmosSensor(0x58,0x26);
  CamWriteCmosSensor(0x59,0x07);
  CamWriteCmosSensor(0x5a,0xf3);
  CamWriteCmosSensor(0x5b,0xbd);
  CamWriteCmosSensor(0x5c,0x50);
  //D30
  CamWriteCmosSensor(0x5d,0x48);
  CamWriteCmosSensor(0x5e,0xc0);
  CamWriteCmosSensor(0x5f,0xf9);
  CamWriteCmosSensor(0x60,0x0e);
  CamWriteCmosSensor(0x61,0x2d);
  CamWriteCmosSensor(0x62,0x05);
  CamWriteCmosSensor(0x63,0xea);
  CamWriteCmosSensor(0x64,0xc4);
  //Shad
  CamWriteCmosSensor(0x65,0x52);
  //D20
  CamWriteCmosSensor(0x66,0x3a);
  CamWriteCmosSensor(0x67,0xcb);
  CamWriteCmosSensor(0x68,0xfb);
  CamWriteCmosSensor(0x69,0x0e);
  CamWriteCmosSensor(0x6a,0x2d);
  CamWriteCmosSensor(0x6b,0x05);
  CamWriteCmosSensor(0x6c,0xea);
  CamWriteCmosSensor(0x6d,0xc4);
  //gamm
  CamWriteCmosSensor(0x6e,0x52);
  CamWriteCmosSensor(0x6f,0xc0);//CMA D65,D30,D20
  //Edge
  CamWriteCmosSensor(0x70,0x20);
  CamWriteCmosSensor(0x71,0x30);
  CamWriteCmosSensor(0x72,0x01);
  CamWriteCmosSensor(0x73,0x01);
  CamWriteCmosSensor(0x74,0x20);
  CamWriteCmosSensor(0x75,0x20);
  CamWriteCmosSensor(0x76,0x30);
  CamWriteCmosSensor(0x77,0x10);
  CamWriteCmosSensor(0x79,0x20);
  CamWriteCmosSensor(0x7a,0x20);
  CamWriteCmosSensor(0x7b,0x03);
  CamWriteCmosSensor(0x7c,0x03);
  CamWriteCmosSensor(0x7d,0x20);
  CamWriteCmosSensor(0x7e,0x20);
  CamWriteCmosSensor(0x7f,0x30);//start gain
  CamWriteCmosSensor(0x80,0x10);
  CamWriteCmosSensor(0x81,0x00);
  CamWriteCmosSensor(0x82,0x58);
  CamWriteCmosSensor(0x83,0x10);//flat region sensing threshold
  //color gain
  CamWriteCmosSensor(0x86,0x14);//10
  CamWriteCmosSensor(0x87,0x14);//10
  CamWriteCmosSensor(0x92,0x30);//GSTRT
  CamWriteCmosSensor(0x93,0x0f);//0x26 //GSLOP 
  
  /*Window Setting first */   
  CamWriteCmosSensor(0xA0,0x14);//YUV
  CamWriteCmosSensor(0xA1,0x00);
  CamWriteCmosSensor(0xA2,0x61);
  CamWriteCmosSensor(0xA3,0x01); 
  CamWriteCmosSensor(0xA4,0x20);
  
  SIC110ASetPage(1);
  CamWriteCmosSensor(0x10,0x80);

  SIC110ASetPage(2);
  CamWriteCmosSensor(0x10,0xd3);
  //CMA[END]
}                                  

/*************************************************************************
* FUNCTION
*    SIC110AHalfAdjust
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
__inline static kal_uint32 SIC110AHalfAdjust(kal_uint32 Dividend, kal_uint32 Divisor)
{
  return (Dividend * 2 + Divisor) / (Divisor * 2); /* that is [Dividend / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    SIC110ASetShutterStep
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
static void SIC110ASetShutterStep(void)
{       
  const kal_uint8 Banding = SIC110ASensor.Banding == CAM_BANDING_50HZ ? SIC110A_NUM_50HZ : SIC110A_NUM_60HZ;
  const kal_uint16 ShutterStep = SIC110AHalfAdjust(SIC110ASensor.Pclk / 2, (SIC110ASensor.Hblank + SIC110A_PERIOD_PIXEL_NUMS) * Banding);

  ASSERT(ShutterStep <= 0xFF);    
  /* 0x34  shutter step*/
  SIC110ASetPage(1);
  CamWriteCmosSensor(0x34,ShutterStep);
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "Set Shutter Step:%x",ShutterStep);
#endif
}

/*************************************************************************
* FUNCTION
*    SIC110ASetFrameCount
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
static void SIC110ASetFrameCount(void)
{
  kal_uint16 FrameCount;
  kal_uint8 Banding = SIC110ASensor.Banding == CAM_BANDING_50HZ ? SIC110A_NUM_50HZ : SIC110A_NUM_60HZ;
  
  FrameCount = Banding * SIC110A_FRAME_RATE_UNIT / SIC110ASensor.Fps;
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "min_fps:%d,FrameCount:%x",SIC110ASensor.Fps / SIC110A_FRAME_RATE_UNIT, FrameCount);
#endif
  ASSERT(FrameCount <= 0x3F);    
  /*Block 01: 0x11 [5 -0] Max shutter step,for Min frame rate */
  SIC110ASetPage(1);
  CamWriteCmosSensor(0x11,FrameCount);    

}

/*************************************************************************
* FUNCTION
*    SIC110AWriteBlank
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
static void SIC110AWriteBlank(kal_uint16 Hblank,kal_uint16 Vblank)
{
  /********************************************    
  *   Register :0x20 - 0x22
  *  Block 00
  *  0x20  [7:4]:HBANK[11:8]; 0x20  [3:0]:VBANK[11:8]
  *  0x21 HBANK[7:0]
  *  0x23 VBANK[7:0]  
  ********************************************/
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Hblank:%x,Vblank:%x",Hblank,Vblank);
#endif 
  ASSERT(Hblank <= SIC110A_BLANK_REGISTER_LIMITATION && Vblank <= SIC110A_BLANK_REGISTER_LIMITATION);
  SIC110ASetPage(0);
  CamWriteCmosSensor(0x20,((Hblank>>4)&0xF0)|((Vblank>>8)&0x0F));
  CamWriteCmosSensor(0x21,Hblank & 0xFF);
  CamWriteCmosSensor(0x23,Vblank & 0xFF);
  SIC110ASetShutterStep();
}

/*************************************************************************
* FUNCTION
*    SIC110ACalFps
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
static void SIC110ACalFps(void)
{
  const kal_uint16 MaxFps = (KAL_TRUE == SIC110ASensor.VideoMode) ? SIC110ASensor.Fps : SIC110A_MAX_CAMERA_FPS;
  kal_int16 LineLength, DummyLine;

  LineLength = SIC110ASensor.DummyPixel + SIC110A_PERIOD_PIXEL_NUMS;
  DummyLine = SIC110ASensor.Pclk * SIC110A_FRAME_RATE_UNIT / (2 * LineLength * MaxFps) - SIC110A_PERIOD_LINE_NUMS; 
  if (DummyLine > SIC110A_BLANK_REGISTER_LIMITATION)
  {
    DummyLine = SIC110A_BLANK_REGISTER_LIMITATION;
    LineLength = SIC110ASensor.Pclk * SIC110A_FRAME_RATE_UNIT / (2 * (DummyLine + SIC110A_PERIOD_LINE_NUMS) * MaxFps);
  }
  SIC110ASensor.Hblank = LineLength -  SIC110A_PERIOD_PIXEL_NUMS;
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "MaxFps:%d",MaxFps/SIC110A_FRAME_RATE_UNIT);
  kal_wap_trace(MOD_ENG,TRACE_INFO, "Dummy Pixel:%x,Hblank:%x,Vblank:%x",SIC110ASensor.DummyPixel,SIC110ASensor.Hblank,DummyLine);
#endif
  SIC110AWriteBlank((SIC110ASensor.Hblank > 0) ? SIC110ASensor.Hblank : 0, (DummyLine > 0) ? DummyLine : 0);
}

/*************************************************************************
* FUNCTION
*   SIC110A_FixFrameRate
*
* DESCRIPTION
*   This function fix the frame rate of image sensor.
*
*************************************************************************/
static void SIC110AFixFrameRate(kal_bool Enable)
{
  if(Enable == KAL_TRUE)
  {   //fix frame rate
    SIC110ASensor.Control |= 0xC0;
    SIC110ASetPage(0);
    CamWriteCmosSensor(0x04,SIC110ASensor.Control);
  }
  else
  {        
    SIC110ASensor.Control &= 0x3F;
    SIC110ASetPage(0);
    CamWriteCmosSensor(0x04,SIC110ASensor.Control);
  }
}   /* SIC110A_FixFrameRate */

/*************************************************************************
* FUNCTION
*    SIC110ASetHVMirror
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
static void SIC110ASetHVMirror(kal_uint8 Mirror)
{
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Mirror:%d",Mirror);
#endif 

  SIC110ASensor.Control = SIC110ASensor.Control & 0xFC;  
  switch (Mirror) 
  {
  case IMAGE_SENSOR_MIRROR_H:
    SIC110ASensor.Control |= 0x01;
    break;
  case IMAGE_SENSOR_MIRROR_V:
    SIC110ASensor.Control |= 0x02;
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    SIC110ASensor.Control |= 0x03;
    break;
  case IMAGE_SENSOR_MIRROR_NORMAL:
  default:
    SIC110ASensor.Control |= 0x00;
    break;
  }    
  SIC110ASetPage(0);
  CamWriteCmosSensor(0x04,SIC110ASensor.Control);
}

/*************************************************************************
* FUNCTION
*    SIC110ANightMode
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
static void SIC110ANightMode(kal_bool Enable)
{    
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIC110A NightMode %d",Enable);
#endif
  if (SIC110ASensor.VideoMode == KAL_FALSE)// camera mode
  {
    if (KAL_TRUE == Enable)
    { /* camera night mode */
#ifdef SIC110A_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
#endif
    }
    else
    {   /* camera normal mode */
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
#endif
    }
  }
  else //video mode
  {
    if (KAL_TRUE == Enable)
    {   /* video night mode */
#ifdef SIC110A_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
#endif
    }
    else
    {   /* video normal mode */
#ifdef SIC110A_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
#endif
    }
  }
}

/*************************************************************************
* FUNCTION
*    SIC110ASceneMode
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
static MM_ERROR_CODE_ENUM SIC110ASceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    SIC110ANightMode(Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110AEv
*
* DESCRIPTION
*    SIC110A EV setting.
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
static MM_ERROR_CODE_ENUM SIC110AEv(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIC110A_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3: EvTemp = 0x40; break;
    case CAM_EV_NEG_3_3: EvTemp = 0x50; break;
    case CAM_EV_NEG_2_3: EvTemp = 0x60; break;
    case CAM_EV_NEG_1_3: EvTemp = 0x70; break;
    case CAM_EV_ZERO:    EvTemp = 0x80; break;
    case CAM_EV_POS_1_3: EvTemp = 0x90; break;
    case CAM_EV_POS_2_3: EvTemp = 0xA0; break;
    case CAM_EV_POS_3_3: EvTemp = 0xB0; break;
    case CAM_EV_POS_4_3: EvTemp = 0xC0; break;
    default: break;
    }
    SIC110ASetPage(1); //bank 1
    CamWriteCmosSensor(0x12,EvTemp); 
    CamWriteCmosSensor(0x13,EvTemp);
    CamWriteCmosSensor(0x14,EvTemp);
  }
  return MM_ERROR_NONE;
}
/*************************************************************************
* FUNCTION
*    SIC110AContrast
*
* DESCRIPTION
*    SIC110A Contrast setting.
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
static MM_ERROR_CODE_ENUM SIC110AContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIC110A_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   Contrast = 0x18; break;
    case CAM_CONTRAST_MEDIUM: Contrast = 0x10; break;
    case CAM_CONTRAST_LOW:    Contrast = 0x08; break;
    default: break;
    }
    SIC110ASetPage(3);
    CamWriteCmosSensor(0x85, Contrast);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110AWb
*
* DESCRIPTION
*    SIC110A WB setting.
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
static MM_ERROR_CODE_ENUM SIC110AWb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIC110A_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
    SIC110ASetPage(2);    //bank 2
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO: /* enable AWB */
      // CAM_WB_AUTO mode should not update R/G/B gains
      CamWriteCmosSensor(0x10, 0xD3);
      break;
    case CAM_WB_CLOUD:
      CamWriteCmosSensor(0x10, 0x00);  // disable AWB
      CamWriteCmosSensor(0x60, 0xD0);
      CamWriteCmosSensor(0x61, 0x88);
      break;
    case CAM_WB_DAYLIGHT:
      CamWriteCmosSensor(0x10, 0x00);  // disable AWB
      CamWriteCmosSensor(0x60, 0xC2);
      CamWriteCmosSensor(0x61, 0x9E);
      break;
    case CAM_WB_INCANDESCENCE:
      CamWriteCmosSensor(0x10, 0x00);  // disable AWB
      CamWriteCmosSensor(0x60, 0x98);
      CamWriteCmosSensor(0x61, 0xC8);
      break;
    case CAM_WB_FLUORESCENT:
      CamWriteCmosSensor(0x10, 0x00);  // disable AWB
      CamWriteCmosSensor(0x60, 0xAA);
      CamWriteCmosSensor(0x61, 0xBE);
      break;
    case CAM_WB_TUNGSTEN:
      CamWriteCmosSensor(0x10, 0x00);  // disable AWB
      CamWriteCmosSensor(0x60, 0x90);
      CamWriteCmosSensor(0x61, 0xC0);
      break;
    default:
      break;
    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIC110AEffect
*
* DESCRIPTION
*    SIC110A Effect setting.
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
static MM_ERROR_CODE_ENUM SIC110AEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 9;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
    EffectPara->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
    EffectPara->SupportItem[8] = CAM_EFFECT_ENC_SKETCH;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef SIC110A_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif

    SIC110ASetPage(3);  //bank 3
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
      CamWriteCmosSensor(0x89, 0x00);
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
      CamWriteCmosSensor(0x89, 0x40);
      break;
    case CAM_EFFECT_ENC_SEPIA:
      CamWriteCmosSensor(0x89, 0x80);
      CamWriteCmosSensor(0x8A, 0x60);
      CamWriteCmosSensor(0x8B, 0xA0);
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
      CamWriteCmosSensor(0x89, 0x80);
      CamWriteCmosSensor(0x8A, 0x50);
      CamWriteCmosSensor(0x8B, 0x50);
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
      CamWriteCmosSensor(0x89, 0x80);
      CamWriteCmosSensor(0x8a, 0xC0);
      CamWriteCmosSensor(0x8b, 0x60);
      break;
    case CAM_EFFECT_ENC_COLORINV:
      CamWriteCmosSensor(0x89, 0x10);
      break;
    case CAM_EFFECT_ENC_GRAYINV:
      CamWriteCmosSensor(0x89, 0x20);
      break;
    case CAM_EFFECT_ENC_EMBOSSMENT:
      CamWriteCmosSensor(0x89, 0x08);
      break;
    case CAM_EFFECT_ENC_SKETCH:
      CamWriteCmosSensor(0x89, 0x04);
      break;
    default:
      break;
    }
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110AStillCaptureSize
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
static MM_ERROR_CODE_ENUM SIC110AStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_QVGA;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110ABanding
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
static MM_ERROR_CODE_ENUM SIC110ABanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIC110A_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif
    SIC110ASensor.Banding = In->FeatureSetValue;
    SIC110ASetShutterStep();
    SIC110ASetFrameCount();    
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110AGetSensorInfo
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
static void SIC110AGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = SIC110A_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_HIGH;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;
#else
  Info->PreviewMclkFreq = 24000000;
  Info->CaptureMclkFreq = 24000000;
  Info->VideoMclkFreq = 24000000;
#endif
  Info->PreviewWidth = SIC110A_IMAGE_SENSOR_CIF_WIDTH;
  Info->PreviewHeight = SIC110A_IMAGE_SENSOR_CIF_HEIGHT;
  Info->FullWidth = SIC110A_IMAGE_SENSOR_CIF_WIDTH;
  Info->FullHeight = SIC110A_IMAGE_SENSOR_CIF_HEIGHT;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    SIC110ADetectSensorId
*
* DESCRIPTION
*    This function detect sensor id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 SIC110ADetectSensorId(void)
{
  MM_ERROR_CODE_ENUM SIC110ASensorClose(void);
  kal_uint16 SIC110APowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == SIC110ASensor.SensorIdx)
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
      SensorId = SIC110APowerOn();
      SIC110ASensorClose();
#ifdef SIC110A_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"SIC110ADetectSensorId:%x",SensorId);
#endif
      if (SIC110A_SENSOR_ID == SensorId)
      {
        return SIC110A_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    SIC110AInitOperationPara
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
static void SIC110AInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 1; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 4; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 8; /* wait stable frame when sensor change mode (init to pre) */
}


/*************************************************************************
* FUNCTION
*    SIC110AAeEnable
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
static MM_ERROR_CODE_ENUM SIC110AAeEnable(kal_bool Enable)
{
  kal_uint8 AeTemp;

  if (Enable)
  {
    AeTemp = 0x80;
  }
  else
  {
    AeTemp = 0x00;
  }
#ifdef SIC110A_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif
  SIC110ASetPage(1);
  CamWriteCmosSensor(0x10,AeTemp);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110AAwbEnable
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
static MM_ERROR_CODE_ENUM SIC110AAwbEnable(kal_bool Enable)
{
  kal_uint8 AwbTemp;

  if (Enable)
  {
    AwbTemp = 0xD3;
  }
  else
  {
    AwbTemp = 0x00;
  }
#ifdef SIC110A_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif
  SIC110ASetPage(2);
  CamWriteCmosSensor(0x10,AwbTemp);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110APowerOn
*
* DESCRIPTION
*    This function reset sensor and read id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 SIC110APowerOn(void)
{
  kal_uint8 SensorId;
  /* PowerOn the sensor */
  CisModulePowerOn(SIC110ASensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, SIC110A_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 300);
  kal_sleep_task(2);  /* delay for power stable */
  
  /* set sensors chip enable pin to high to activate SIC110A */
  CamPdnPinCtrl(SIC110ASensor.SensorIdx, 1);
  kal_sleep_task(1);
  /* Reset the sensor */  
  CamRstPinCtrl(SIC110ASensor.SensorIdx, 1);
  /* delay for stable sensor */  
  kal_sleep_task(1);
  
  /* Read Sensor ID  */
  SIC110ASetPage(0);
  SensorId = CamReadCmosSensor(0x01);
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SIC110A Sensor ID: %x ",SensorId);
#endif
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    SIC110APreview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIC110APreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;

#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIC110A Preview");
#endif

  SIC110ASensor.Banding = In->BandingFreq;
  SIC110ASensor.NightMode = In->NightMode;
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    SIC110ASensor.VideoMode = KAL_TRUE;
    SIC110ASensor.Fps = In->MaxVideoFrameRate * SIC110A_FRAME_RATE_UNIT / 10;
    break;
  case CAL_SCENARIO_CAMERA_PREVIEW:
    SIC110ASensor.VideoMode = KAL_FALSE;
    SIC110ASensor.Fps = SIC110A_FRAME_RATE_UNIT * (SIC110ASensor.NightMode ? 5 : 10);
    break;
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    SIC110ASensor.VideoMode = KAL_FALSE;
    SIC110ASensor.Fps = SIC110A_FRAME_RATE_UNIT * (SIC110ASensor.NightMode ? 5 : 10);
    break;
  default:
    break;
  }
  SIC110AFixFrameRate(SIC110ASensor.VideoMode);
  SIC110ASetHVMirror(In->ImageMirror);
  SIC110ANightMode(SIC110ASensor.NightMode);
  SIC110ACalFps();
  SIC110ASetFrameCount();

  /* Add more delay frame for video call capture */
  Out->WaitStableFrameNum = SIC110ASensor.VideoMode ? 4:0; 
  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = SIC110A_IMAGE_SENSOR_CIF_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = SIC110A_IMAGE_SENSOR_CIF_HEIGHT - 2 * StartY;
}

/*************************************************************************
* FUNCTION
*    SIC110ACapture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void SIC110ACapture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;

#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIC110A Capture");
#endif

  Out->WaitStableFrameNum = 0;
  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = SIC110A_IMAGE_SENSOR_CIF_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = SIC110A_IMAGE_SENSOR_CIF_HEIGHT - 2 * StartY;
}

/*************************************************************************
* FUNCTION
*    SIC110ASensorOpen
*
* DESCRIPTION
*    This function read sensor id and init sensor
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
static MM_ERROR_CODE_ENUM SIC110ASensorOpen(void)
{
  if (SIC110A_SENSOR_ID != SIC110APowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  SIC110AInitialSetting();
  SIC110ASensor.VideoMode = KAL_FALSE;
  SIC110ASensor.NightMode = KAL_FALSE;
  SIC110ASensor.Banding = CAM_BANDING_50HZ;
  SIC110ASensor.Control = 0x00;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  SIC110ASensor.Pclk = 26000000;
#else
  SIC110ASensor.Pclk = 24000000;
#endif
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  SIC110ASensor.DummyPixel = 0x137;
#else
  SIC110ASensor.DummyPixel = 0x0;
#endif
  SIC110ASensor.Fps = 10 * SIC110A_FRAME_RATE_UNIT;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110ASensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    id: scenario id
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
static MM_ERROR_CODE_ENUM SIC110ASensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  kal_bool FeatureValueTemp = KAL_FALSE;
  
#ifdef SIC110A_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SIC110A FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return SIC110AWebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = SIC110AEv(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = SIC110AContrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = SIC110AWb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = SIC110AEffect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = SIC110AStillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
    ErrCode = SIC110ABanding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = SIC110ASceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = SIC110ASceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    SIC110AGetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIC110ADetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIC110ASensor.Fps * 10 / SIC110A_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    SIC110AInitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(SIC110ASensor.SensorIdx, Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(SIC110ASensor.SensorIdx, 0);   
    CamRstPinCtrl(SIC110ASensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    SIC110ASensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    SIC110ASensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    FeatureValueTemp = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue ? KAL_FALSE : KAL_TRUE;
    ErrCode = SIC110AAeEnable(FeatureValueTemp);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    FeatureValueTemp = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue ? KAL_FALSE : KAL_TRUE;
    ErrCode = SIC110AAwbEnable(FeatureValueTemp);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    SIC110ASensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    In/Out: parameter
*    OutLen: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIC110ASensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    SIC110APreview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    SIC110ACapture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110ASensorClose
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
static MM_ERROR_CODE_ENUM SIC110ASensorClose(void)
{
  /* power down sensor */
  CamPdnPinCtrl(SIC110ASensor.SensorIdx, 0);
  CamRstPinCtrl(SIC110ASensor.SensorIdx, 0);
  CisModulePowerOn(SIC110ASensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIC110ASensorFunc
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
MM_ERROR_CODE_ENUM SIC110ASensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncSIC110A =
  {
    SIC110ASensorOpen,
    SIC110ASensorFeatureCtrl,
    SIC110ASensorCtrl,
    SIC110ASensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncSIC110A;
  
  return MM_ERROR_NONE;
}

