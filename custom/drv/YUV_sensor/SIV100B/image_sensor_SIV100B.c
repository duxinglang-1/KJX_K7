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
 *   image_sensor_SIV100B.c
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

/* #define SIV100B_DEBUG */
#undef DRV_ISP_YUV_BURST_MODE_SUPPORT
static struct
{
  kal_uint8   Banding;
  kal_bool    NightMode;
  kal_bool    VideoMode;
  kal_bool    CaptureMode;
  kal_uint16  Fps;
  kal_uint32  Pclk;
  kal_uint16  DummyPixel; /* for user customization */
  kal_uint16  Hblank; /* for calculating shutter step */
  kal_uint16  ShutterStep;
  kal_uint16  DelayCount;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} SIV100BSensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    SIV100BInitialSetting
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
static void SIV100BInitialSetting(void)
{
  CamWriteCmosSensor(0x04, 0x00);
  CamWriteCmosSensor(0x05, 0x07);
  CamWriteCmosSensor(0x10, 0x13);
  CamWriteCmosSensor(0x11, 0x04);
  CamWriteCmosSensor(0x12, 0x0a);
  CamWriteCmosSensor(0x13, 0x1f);
  CamWriteCmosSensor(0x16, 0x89);
  CamWriteCmosSensor(0x1b, 0x90);
  CamWriteCmosSensor(0x1f, 0x52);

  /* SIV100B  50Hz - 25.00FPS 24MHz */
  CamWriteCmosSensor(0x20, 0x00);
  CamWriteCmosSensor(0x21, 0x00);
  CamWriteCmosSensor(0x22, 0x61);
  CamWriteCmosSensor(0x34, 0x96);

  CamWriteCmosSensor(0x33, 0x0A);

  /* AE */
  CamWriteCmosSensor(0x40, 0x80);
  CamWriteCmosSensor(0x41, 0x88);
  CamWriteCmosSensor(0x42, 0x7f);
  CamWriteCmosSensor(0x43, 0xc0);
  CamWriteCmosSensor(0x44, 0x48);
  CamWriteCmosSensor(0x45, 0x28);
  CamWriteCmosSensor(0x46, 0x08);
  CamWriteCmosSensor(0x47, 0x15);
  CamWriteCmosSensor(0x48, 0x14);
  CamWriteCmosSensor(0x49, 0x0C);
  CamWriteCmosSensor(0x4a, 0x42);
  CamWriteCmosSensor(0x4b, 0xC4);
  CamWriteCmosSensor(0x4c, 0x3C);
  CamWriteCmosSensor(0x4e, 0x17);
  CamWriteCmosSensor(0x4f, 0x8A);
  CamWriteCmosSensor(0x50, 0x94);

  CamWriteCmosSensor(0x5a, 0x00);

  /* Auto White Balance  0105 */
  CamWriteCmosSensor(0x60, 0xc3); /* 0xc0 turn off Fix awb gain at high light */
  CamWriteCmosSensor(0x61, 0x88);
  CamWriteCmosSensor(0x62, 0x01);
  CamWriteCmosSensor(0x63, 0x80);
  CamWriteCmosSensor(0x64, 0x80);
  CamWriteCmosSensor(0x65, 0xd2);
  CamWriteCmosSensor(0x66, 0x83);
  CamWriteCmosSensor(0x67, 0xd6);
  CamWriteCmosSensor(0x68, 0x80);
  CamWriteCmosSensor(0x69, 0x8a);
  CamWriteCmosSensor(0x6a, 0x70);
  CamWriteCmosSensor(0x6b, 0x90);
  CamWriteCmosSensor(0x6c, 0x70);
  CamWriteCmosSensor(0x6d, 0x88);
  CamWriteCmosSensor(0x6e, 0x77);
  CamWriteCmosSensor(0x6f, 0x46);
  CamWriteCmosSensor(0x70, 0xd8);
  CamWriteCmosSensor(0x71, 0x40);
  CamWriteCmosSensor(0x72, 0x05);
  CamWriteCmosSensor(0x73, 0x02);
  CamWriteCmosSensor(0x74, 0x0c);
  CamWriteCmosSensor(0x75, 0x10);
  CamWriteCmosSensor(0x76, 0x60); /*0x50 2009.10.27 */
  CamWriteCmosSensor(0x77, 0xaf); /* 0xb7 */
  CamWriteCmosSensor(0x78, 0x8d); /* 0x95 */

  /* IDP */
  CamWriteCmosSensor(0x80, 0xbf);/*MAUI_02390833 10-04-14 0xaf*/
  CamWriteCmosSensor(0x81, 0x1d);
  CamWriteCmosSensor(0x82, 0xdd);
  CamWriteCmosSensor(0x83, 0x00);
  CamWriteCmosSensor(0x86, 0xa1);
  CamWriteCmosSensor(0x87, 0x00);
  CamWriteCmosSensor(0x88, 0x24);
  CamWriteCmosSensor(0x89, 0x0f);

  CamWriteCmosSensor(0x92, 0x44);
  CamWriteCmosSensor(0x93, 0x10);
  CamWriteCmosSensor(0x94, 0x20);
  CamWriteCmosSensor(0x95, 0x18);
  CamWriteCmosSensor(0x96, 0x10);
  CamWriteCmosSensor(0x97, 0x20);
  CamWriteCmosSensor(0x98, 0x20);
  CamWriteCmosSensor(0x99, 0x18);
  CamWriteCmosSensor(0x9a, 0x50);

  /* Shading  0106 */
  CamWriteCmosSensor(0xa0, 0x12);/*MAUI_02390833 10-04-14*/
  CamWriteCmosSensor(0xa1, 0x12);/*MAUI_02390833 10-04-14*/
  CamWriteCmosSensor(0xa2, 0x12);/*MAUI_02390833 10-04-14*/
  CamWriteCmosSensor(0xa3, 0x12);/*MAUI_02390833 10-04-14*/
  CamWriteCmosSensor(0xa4, 0xcc);
  CamWriteCmosSensor(0xa5, 0xcc);
  CamWriteCmosSensor(0xa6, 0xcc);
  CamWriteCmosSensor(0xa7, 0xcb);
  CamWriteCmosSensor(0xa8, 0xa9);
  CamWriteCmosSensor(0xa9, 0x33); /*MAUI_02835712 10-12-12  0x45*/
  CamWriteCmosSensor(0xaa, 0x47);/* 0x36 */
  CamWriteCmosSensor(0xab, 0x11);
  CamWriteCmosSensor(0xac, 0x14); /*MAUI_02835712 10-12-12  0x13*/
  CamWriteCmosSensor(0xad, 0x00);/* 0x01 */
  CamWriteCmosSensor(0xae, 0x00);
  CamWriteCmosSensor(0xaf, 0x98);
  CamWriteCmosSensor(0xb0, 0x90);

  /* Gamma  1021 */
  CamWriteCmosSensor(0xb1, 0x00);
  CamWriteCmosSensor(0xb2, 0x0b);
  CamWriteCmosSensor(0xb3, 0x16);
  CamWriteCmosSensor(0xb4, 0x2a);
  CamWriteCmosSensor(0xb5, 0x4a);
  CamWriteCmosSensor(0xb6, 0x64);
  CamWriteCmosSensor(0xb7, 0x7b);
  CamWriteCmosSensor(0xb8, 0x8f);
  CamWriteCmosSensor(0xb9, 0xa0);
  CamWriteCmosSensor(0xba, 0xAe);
  CamWriteCmosSensor(0xbb, 0xBb);
  CamWriteCmosSensor(0xbc, 0xd0);
  CamWriteCmosSensor(0xbd, 0xe2);
  CamWriteCmosSensor(0xbe, 0xF2);
  CamWriteCmosSensor(0xbf, 0xF9);
  CamWriteCmosSensor(0xc0, 0xFF);

  /* Color Matrix */
  CamWriteCmosSensor(0xc1, 0x3a);
  CamWriteCmosSensor(0xc2, 0xcb);
  CamWriteCmosSensor(0xc3, 0xfb);
  CamWriteCmosSensor(0xc4, 0x10);
  CamWriteCmosSensor(0xc5, 0x21);
  CamWriteCmosSensor(0xc6, 0x10);
  CamWriteCmosSensor(0xc7, 0xf3);
  CamWriteCmosSensor(0xc8, 0xbd);
  CamWriteCmosSensor(0xc9, 0x50);

  /* Edge */
  CamWriteCmosSensor(0xca, 0x90);
  CamWriteCmosSensor(0xcb, 0x18);
  CamWriteCmosSensor(0xcc, 0x20);
  CamWriteCmosSensor(0xcd, 0x06);
  CamWriteCmosSensor(0xce, 0x06);
  CamWriteCmosSensor(0xcf, 0x20);
  CamWriteCmosSensor(0xd0, 0x20);
  CamWriteCmosSensor(0xd1, 0x28);
  CamWriteCmosSensor(0xd2, 0x86);
  CamWriteCmosSensor(0xd3, 0x00);

  /* Contrast */
  CamWriteCmosSensor(0xd4, 0x10);
  CamWriteCmosSensor(0xd5, 0x12);
  CamWriteCmosSensor(0xd6, 0x14);/* 0x12 */
  CamWriteCmosSensor(0xd7, 0x00);
  CamWriteCmosSensor(0xd8, 0x00);
  CamWriteCmosSensor(0xd9, 0x00);
  CamWriteCmosSensor(0xda, 0x00);
  CamWriteCmosSensor(0xdb, 0xff);
  CamWriteCmosSensor(0xdc, 0x00);

  /* Saturation */
  CamWriteCmosSensor(0xe1, 0x29);
  CamWriteCmosSensor(0xe2, 0x75);

  CamWriteCmosSensor(0x40, 0x80);  /* Set the FSEL50 bit to avoid 50 Hz flicker */
  CamWriteCmosSensor(0x03, 0xC5);  /* Raise the drvie capability for to meet MTK EVB's requirment */
  CamWriteCmosSensor(0x7a, 0xa8);
  CamWriteCmosSensor(0x7b, 0xb0);
  CamWriteCmosSensor(0x7c, 0x80);

  CamWriteCmosSensor(0x40, 0x80);
  /* board 1  0x
   board 2  0x85 c5 
   board 3  0x */
}                                  

/*************************************************************************
* FUNCTION
*    SIV100BHalfAdjust
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
__inline static kal_uint32 SIV100BHalfAdjust(kal_uint32 Dividend, kal_uint32 Divisor)
{
  return (Dividend * 2 + Divisor) / (Divisor * 2); /* that is [Dividend / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    SIV100BSetShutterStep
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
static void SIV100BSetShutterStep(void)
{       
  const kal_uint8  Banding = SIV100BSensor.Banding == CAM_BANDING_50HZ ? SIV100B_NUM_50HZ : SIV100B_NUM_60HZ;
  const kal_uint16 ShutterStep = SIV100BHalfAdjust(SIV100BSensor.Pclk / 2, (SIV100BSensor.Hblank + SIV100B_PERIOD_PIXEL_NUMS) * Banding);

  ASSERT(ShutterStep <= 0xFF);    
  /* 0x34  shutter step*/
  CamWriteCmosSensor(0x34,ShutterStep);
  SIV100BSensor.ShutterStep= ShutterStep;
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "Set Shutter Step:%x",ShutterStep);
#endif
}
static void SIV100BWaitOneVd(void)
{
  kal_uint8  Count = 0;
  SIV100BSensor.DelayCount = 0;
      
  if( kal_if_hisr())
  {
    kal_uint16 Shutter,DelayTick;
#ifdef SIV100B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "kal_if_hisr");
#endif
    Shutter = (CamReadCmosSensor(0x30) << 8) | CamReadCmosSensor(0x31);
    DelayTick = Shutter / SIV100BSensor.ShutterStep * 1000 / 120;  // Transfer shutter to frame time (60Hz)
    DelayTick = DelayTick * 1000 / 4615;  // Transfer frame time to delay tick
    if (DelayTick < 8) DelayTick = 8;    // Make sure the delay is enough (30 Fps)
    
    DelayTick = DelayTick * 3 / 2; 
    kal_sleep_task(DelayTick);
    return ;
  }
  
  while(SIV100BSensor.DelayCount < 1)
  {
#ifdef SIV100B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "SIV100BWaitOneVD Count :%d",Count);
#endif
    kal_sleep_task(8);
    Count++;
    if (Count > 5) break;
    // max delay 6 *  8* 4.615 ms for min frame rate 5 fps.
  }
}

/*************************************************************************
* FUNCTION
*    SIV100BSetFrameCount
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
static void SIV100BSetFrameCount(void)
{
  kal_uint16 Shutter, FrameCount;
  kal_uint8  Banding = SIV100BSensor.Banding == CAM_BANDING_50HZ ? SIV100B_NUM_50HZ : SIV100B_NUM_60HZ;
  
  FrameCount = Banding * SIV100B_FRAME_RATE_UNIT / SIV100BSensor.Fps;
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "min_fps:%d,FrameCount:%x",SIV100BSensor.Fps / SIV100B_FRAME_RATE_UNIT, FrameCount);
#endif
  Shutter = (CamReadCmosSensor(0x30) << 8) | CamReadCmosSensor(0x31);
  if (Shutter > 0x4000)
    Shutter = 0xFFF0;
  else
    Shutter = Shutter * 4;

  /* AE must be off to do the following mode change setting.*/
  CamWriteCmosSensor(0x40, 0x00);
  SIV100BWaitOneVd();
  /*0x33  FRCNT*/
  CamWriteCmosSensor(0x33,FrameCount&0xFF);
  SIV100BWaitOneVd();
  
  /*After the above mode change setting, turn on AE again */
  CamWriteCmosSensor(0x30, Shutter>>8);
  CamWriteCmosSensor(0x31, Shutter&0x00FF);
  CamWriteCmosSensor(0x40, 0x80);
  SIV100BWaitOneVd();
}

/*************************************************************************
* FUNCTION
*    SIV100BWriteBlank
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
static void SIV100BWriteBlank(kal_uint16 Hblank,kal_uint16 Vblank)
{
 /*************************************    
  *   Register :0x20 - 0x22    
  *  0x20  [5:4]:HBANK[9:8]; 0x20  [1:0]:VBANK[9:8]
  *  0x21 HBANK[7:0]
  *  0x22 VBANK[7:0]   
  ***************************************/
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "HB:%x,VB:%x",Hblank,Vblank);
#endif
  ASSERT(Hblank <= SIV100B_BLANK_REGISTER_LIMITATION && Vblank <= SIV100B_BLANK_REGISTER_LIMITATION);
  CamWriteCmosSensor(0x20,((Hblank >> 4)&0x30)|((Vblank >> 8)&0x03));
  CamWriteCmosSensor(0x21,Hblank&0xFF);
  CamWriteCmosSensor(0x22,Vblank&0xFF);
  SIV100BSetShutterStep();
}

/*************************************************************************
* FUNCTION
*    SIV100BCalFps
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
static void SIV100BCalFps(void)
{
  const kal_uint16 MaxFps = (KAL_TRUE == SIV100BSensor.VideoMode) ? SIV100BSensor.Fps : SIV100B_MAX_CAMERA_FPS;
  kal_int16 LineLength, DummyLine;

  LineLength = SIV100BSensor.DummyPixel + SIV100B_PERIOD_PIXEL_NUMS;
  DummyLine = SIV100BSensor.Pclk * SIV100B_FRAME_RATE_UNIT / (2 * LineLength * MaxFps) - SIV100B_PERIOD_LINE_NUMS; 
  if (DummyLine > SIV100B_BLANK_REGISTER_LIMITATION)
  {
    DummyLine = SIV100B_BLANK_REGISTER_LIMITATION;
    LineLength = SIV100BSensor.Pclk * SIV100B_FRAME_RATE_UNIT / (2 * (DummyLine + SIV100B_PERIOD_LINE_NUMS) * MaxFps);
  }
  SIV100BSensor.Hblank = LineLength -  SIV100B_PERIOD_PIXEL_NUMS;
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "MaxFps:%d",MaxFps/SIV100B_FRAME_RATE_UNIT);
  kal_wap_trace(MOD_ENG,TRACE_INFO, "Dummy Pixel:%x,Hblank,Vblank:%x",SIV100BSensor.DummyPixel,SIV100BSensor.Hblank,DummyLine);
#endif
  SIV100BWriteBlank((SIV100BSensor.Hblank > 0) ? SIV100BSensor.Hblank : 0, (DummyLine > 0) ? DummyLine : 0);
}

/*************************************************************************
* FUNCTION
*    SIV100BSetHVMirror
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
static void SIV100BSetHVMirror(kal_uint8 Mirror)
{
  kal_uint8 Ctrl = 0;
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Mirror:%d",Mirror);
#endif 
  switch (Mirror)
  {
  case IMAGE_SENSOR_MIRROR_HV: Ctrl = 0x03; break;
  case IMAGE_SENSOR_MIRROR_H:  Ctrl = 0x01; break;
  case IMAGE_SENSOR_MIRROR_V:  Ctrl = 0x02; break;
  default: break;
  }
  CamWriteCmosSensor(0x04, Ctrl);
}

/*************************************************************************
* FUNCTION
*    SIV100BNightMode
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
static void SIV100BNightMode(kal_bool Enable)
{    
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIV100B NightMode %d",Enable);
#endif
  if (SIV100BSensor.VideoMode == KAL_FALSE)// camera mode
  {
    if (KAL_TRUE == Enable)
    { /* camera night mode */
#ifdef SIV100B_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
#endif
      CamWriteCmosSensor(0xD7, 0x11);
      CamWriteCmosSensor(0x44, 0x50);
    }
    else
    {   /* camera normal mode */
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
#endif
      CamWriteCmosSensor(0xD7, 0x02);
      CamWriteCmosSensor(0x44, 0x50);
    }
  }
  else //video mode
  {
    if (KAL_TRUE == Enable)
    {   /* video night mode */
#ifdef SIV100B_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
#endif
      CamWriteCmosSensor(0xD7, 0x12);
      CamWriteCmosSensor(0x44, 0x50);
    }
    else
    {   /* video normal mode */
#ifdef SIV100B_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
#endif
      CamWriteCmosSensor(0xD7, 0x02);
      CamWriteCmosSensor(0x44, 0x50);
    }
  }
}

/*************************************************************************
* FUNCTION
*    SIV100BSceneMode
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
static MM_ERROR_CODE_ENUM SIV100BSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    if (SIV100BSensor.NightMode != Enable)
    {
      SIV100BNightMode(Enable);
      SIV100BSensor.NightMode = Enable;
    }   
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BEv
*
* DESCRIPTION
*    SIV100B EV setting.
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
static MM_ERROR_CODE_ENUM SIV100BEv(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIV100B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_EV_NEG_4_3: EvTemp = 0xa0; break;
    case CAM_EV_NEG_3_3: EvTemp = 0x98; break;
    case CAM_EV_NEG_2_3: EvTemp = 0x90; break;
    case CAM_EV_NEG_1_3: EvTemp = 0x88; break;
    case CAM_EV_ZERO:    EvTemp = 0x00; break;
    case CAM_EV_POS_1_3: EvTemp = 0x08; break;
    case CAM_EV_POS_2_3: EvTemp = 0x10; break;
    case CAM_EV_POS_3_3: EvTemp = 0x18; break;
    case CAM_EV_POS_4_3: EvTemp = 0x20; break;
    default: break;
    }
    CamWriteCmosSensor(0xd7, EvTemp);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BContrast
*
* DESCRIPTION
*    SIV100B Contrast setting.
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
static MM_ERROR_CODE_ENUM SIV100BContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIV100B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   Contrast = 0x18; break;
    case CAM_CONTRAST_MEDIUM: Contrast = 0x10; break;
    case CAM_CONTRAST_LOW:    Contrast = 0x08; break;
    default: break;
    }
    CamWriteCmosSensor(0xd4, Contrast);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BWb
*
* DESCRIPTION
*    SIV100B WB setting.
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
static MM_ERROR_CODE_ENUM SIV100BWb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIV100B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO: /* enable AWB */
      /* CAM_WB_AUTO mode should not update R/G/B gains */
      CamWriteCmosSensor(0x60, 0xc3);
      break;
    case CAM_WB_CLOUD:
      CamWriteCmosSensor(0x60, 0x00);  /* disable AWB */
      CamWriteCmosSensor(0x7a, 0xd0);
      CamWriteCmosSensor(0x7b, 0x88);
      break;
    case CAM_WB_DAYLIGHT:
      CamWriteCmosSensor(0x60, 0x00);  /* disable AWB */
      CamWriteCmosSensor(0x7a, 0xc2);
      CamWriteCmosSensor(0x7b, 0x9e);
      break;
    case CAM_WB_INCANDESCENCE:
      CamWriteCmosSensor(0x60, 0x00);  /* disable AWB */
      CamWriteCmosSensor(0x7a, 0x98);
      CamWriteCmosSensor(0x7b, 0xc8);
      break;
    case CAM_WB_FLUORESCENT:
      CamWriteCmosSensor(0x60, 0x00);  /* disable AWB */
      CamWriteCmosSensor(0x7a, 0xaa);
      CamWriteCmosSensor(0x7b, 0xbe);
      break;
    case CAM_WB_TUNGSTEN:
      CamWriteCmosSensor(0x60, 0x00);  /* disable AWB */
      CamWriteCmosSensor(0x7a, 0x90);
      CamWriteCmosSensor(0x7b, 0xc0);
      break;
    default:
      break;
    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV100BEffect
*
* DESCRIPTION
*    SIV100B Effect setting.
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
static MM_ERROR_CODE_ENUM SIV100BEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 8;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
    EffectPara->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
    //EffectPara->SupportItem[8] = CAM_EFFECT_ENC_SKETCH;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef SIV100B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
      CamWriteCmosSensor(0xD8, 0x00);
      break;
    case CAM_EFFECT_ENC_GRAYSCALE:
      CamWriteCmosSensor(0xD8, 0x40);
      break;
    case CAM_EFFECT_ENC_SEPIA:
      CamWriteCmosSensor(0xD8, 0x80);
      CamWriteCmosSensor(0xD9, 0x60);
      CamWriteCmosSensor(0xDA, 0xc0);
      break;
    case CAM_EFFECT_ENC_SEPIAGREEN:
      CamWriteCmosSensor(0xD8, 0x80);
      CamWriteCmosSensor(0xD9, 0x50);
      CamWriteCmosSensor(0xDA, 0x50);
      break;
    case CAM_EFFECT_ENC_SEPIABLUE:
      CamWriteCmosSensor(0xD8, 0x80);
      CamWriteCmosSensor(0xD9, 0xc0);
      CamWriteCmosSensor(0xDA, 0x60);
      break;
    case CAM_EFFECT_ENC_COLORINV:
      CamWriteCmosSensor(0xD8, 0x10);
      break;
    case CAM_EFFECT_ENC_GRAYINV:
      CamWriteCmosSensor(0xD8, 0x20);
      break;
    case CAM_EFFECT_ENC_EMBOSSMENT:
      CamWriteCmosSensor(0xD8, 0x08);
      break;
    case CAM_EFFECT_ENC_SKETCH:
      CamWriteCmosSensor(0xD8, 0x04);
      break;
    default:
      break;
    }
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BStillCaptureSize
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
static MM_ERROR_CODE_ENUM SIV100BStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*    SIV100BBanding
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
static MM_ERROR_CODE_ENUM SIV100BBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
#ifdef SIV100B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
#endif
    if (SIV100BSensor.Banding == In->FeatureSetValue)
      return MM_ERROR_NONE;
    
    SIV100BSensor.Banding = In->FeatureSetValue;
    SIV100BSetShutterStep();
    SIV100BSetFrameCount();    
  }  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BGetSensorInfo
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
static void SIV100BGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = SIV100B_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_LOW;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;
#else
  Info->PreviewMclkFreq = 24000000;
  Info->CaptureMclkFreq = 24000000;
  Info->VideoMclkFreq = 24000000;
#endif
  Info->PreviewWidth = SIV100B_IMAGE_SENSOR_VGA_WIDTH;
  Info->PreviewHeight = SIV100B_IMAGE_SENSOR_VGA_HEIGHT;
  Info->FullWidth = SIV100B_IMAGE_SENSOR_VGA_WIDTH;
  Info->FullHeight = SIV100B_IMAGE_SENSOR_VGA_HEIGHT;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    SIV100BDetectSensorId
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
static kal_uint32 SIV100BDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM SIV100BSensorClose(void);
  kal_uint16 SIV100BPowerOn();
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == SIV100BSensor.SensorIdx)
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
      SensorId = SIV100BPowerOn();
      SIV100BSensorClose();
#ifdef SIV100B_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"SIV100BDetectSensorId:%x",SensorId);
#endif
      if (SIV100B_SENSOR_ID == SensorId)
      {
        return SIV100B_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL ;
}

/*************************************************************************
* FUNCTION
*    SIV100BInitOperationPara
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
static void SIV100BInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 1; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    SIV100BAeEnable
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
static MM_ERROR_CODE_ENUM SIV100BAeEnable(kal_bool Enable)
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
#ifdef SIV100B_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x40, AeTemp);

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BAwbEnable
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
static MM_ERROR_CODE_ENUM SIV100BAwbEnable(kal_bool Enable)
{
  kal_uint8 AwbTemp;

  if (Enable)
  {
    AwbTemp = 0xC3;
  }
  else
  {
    AwbTemp = 0x00;
  }
#ifdef SIV100B_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif
  CamWriteCmosSensor(0x60, AwbTemp);

  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    SIV100BPowerOn
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
static kal_uint16 SIV100BPowerOn(void)
{
  kal_uint16 SensorId;
  /* PowerOn the sensor */
  CisModulePowerOn(SIV100BSensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, SIV100B_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);
  kal_sleep_task(2);  /* delay for power stable */
  
  /* set sensors chip enable pin to low to activate SIV100B */
  CamPdnPinCtrl(SIV100BSensor.SensorIdx, 0);
  
  /* Reset the sensor */
  CamRstPinCtrl(SIV100BSensor.SensorIdx, 1);
  CamRstPinCtrl(SIV100BSensor.SensorIdx, 0);
  kal_sleep_task(1);
  CamRstPinCtrl(SIV100BSensor.SensorIdx, 1);
  /* delay for stable sensor */  
  kal_sleep_task(1);
  
  /* Read Sensor ID  */
  SensorId = (CamReadCmosSensor(SIV100B_ID_REG) << 8)|CamReadCmosSensor(SIV100B_INFO_REG);
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SIV100B Sensor ID: %x ",SensorId);
#endif
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    SIV100BPreview
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
static void SIV100BPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;

#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIV100B Preview");
#endif

  if (SIV100BSensor.CaptureMode == KAL_FALSE)
  {
  SIV100BSensor.Banding = In->BandingFreq;
  SIV100BSensor.NightMode = In->NightMode;
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    SIV100BSensor.VideoMode = KAL_TRUE;
    SIV100BSensor.Fps = In->MaxVideoFrameRate * SIV100B_FRAME_RATE_UNIT / 10;
    break;
  case CAL_SCENARIO_CAMERA_PREVIEW:
    SIV100BSensor.VideoMode = KAL_FALSE;
    SIV100BSensor.Fps = SIV100B_FRAME_RATE_UNIT * (SIV100BSensor.NightMode ? 5 : 10);
    break;
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    StartX += 40;
    StartY += 30;
    SIV100BSensor.VideoMode = KAL_FALSE;
    SIV100BSensor.Fps = SIV100B_FRAME_RATE_UNIT * (SIV100BSensor.NightMode ? 5 : 10);
    break;
  default:
    break;
  }

  SIV100BSetHVMirror(In->ImageMirror);
  SIV100BNightMode(SIV100BSensor.NightMode);
  SIV100BCalFps();
  SIV100BSetFrameCount();
  }
  else
  {
    SIV100BSensor.CaptureMode = KAL_FALSE;
  }
  
  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = SIV100B_IMAGE_SENSOR_VGA_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = SIV100B_IMAGE_SENSOR_VGA_HEIGHT - 2 * StartY;
}

/*************************************************************************
* FUNCTION
*    SIV100BCapture
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
static void SIV100BCapture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 0, StartY = 1;

#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "SIV100B Capture");
#endif
  SIV100BSensor.CaptureMode = KAL_TRUE;
  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = SIV100B_IMAGE_SENSOR_VGA_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = SIV100B_IMAGE_SENSOR_VGA_HEIGHT - 2 * StartY;
}

/*************************************************************************
* FUNCTION
*    SIV100BSensorOpen
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
static MM_ERROR_CODE_ENUM SIV100BSensorOpen(void)
{
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SIV100BSensorOpen");
#endif
  if (SIV100B_SENSOR_ID != SIV100BPowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  SIV100BInitialSetting();
  SIV100BSensor.VideoMode = KAL_FALSE;
  SIV100BSensor.CaptureMode = KAL_FALSE;  
  SIV100BSensor.NightMode = KAL_FALSE;
  SIV100BSensor.Banding = CAM_BANDING_50HZ;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  SIV100BSensor.Pclk = 26000000;
#else
  SIV100BSensor.Pclk = 24000000;
#endif
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  SIV100BSensor.DummyPixel = 0x1c;
#else
  SIV100BSensor.DummyPixel = 0x0;
#endif
  SIV100BSensor.Fps = 10 * SIV100B_FRAME_RATE_UNIT;
  SIV100BSensor.ShutterStep= 0x96;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BSensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM SIV100BSensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  kal_bool FeatureValueTemp = KAL_FALSE;
#ifdef SIV100B_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "SIV100B FeatureCtrl Id:%x",Id);
#endif
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return SIV100BWebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
   /* CAL Query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = SIV100BEv(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = SIV100BContrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = SIV100BWb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = SIV100BEffect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = SIV100BStillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* Only query here, set function move to preview */
    ErrCode = SIV100BBanding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = SIV100BSceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = SIV100BSceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;

  /* Get Info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    SIV100BGetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIV100BDetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = SIV100BSensor.Fps * 10 / SIV100B_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    SIV100BInitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(SIV100BSensor.SensorIdx, Out);
    break;
    
  /* Set Para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(SIV100BSensor.SensorIdx, 1);   
    CamRstPinCtrl(SIV100BSensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    SIV100BSensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    SIV100BSensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    FeatureValueTemp = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue ? KAL_FALSE : KAL_TRUE;
    ErrCode = SIV100BAeEnable(FeatureValueTemp);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    FeatureValueTemp = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue ? KAL_FALSE : KAL_TRUE;
    ErrCode = SIV100BAwbEnable(FeatureValueTemp);
    
  case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
    SIV100BSensor.DelayCount ++; 
#ifdef SIV100B_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "SIV100BSensor.DelayCount %d",SIV100BSensor.DelayCount);
#endif
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    SIV100BSensorCtrl
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
static MM_ERROR_CODE_ENUM SIV100BSensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    SIV100BPreview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    SIV100BCapture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BSensorClose
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
static MM_ERROR_CODE_ENUM SIV100BSensorClose(void)
{
  /* power down sensor */
  CamPdnPinCtrl(SIV100BSensor.SensorIdx, 1);
  CamRstPinCtrl(SIV100BSensor.SensorIdx, 0);
  CisModulePowerOn(SIV100BSensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    SIV100BSensorFunc
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
MM_ERROR_CODE_ENUM SIV100BSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncSIV100B =
  {
    SIV100BSensorOpen,
    SIV100BSensorFeatureCtrl,
    SIV100BSensorCtrl,
    SIV100BSensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncSIV100B;
  
  return MM_ERROR_NONE;
}

