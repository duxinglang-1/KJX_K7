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
 *   image_sensor_OV7690.c
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

/* #define __OV7690_DEBUG_TRACE__ */
/* #define __OV7690_TEST_PATTERN__ */

static struct
{
  kal_uint16 Effect;
  kal_uint16 Exposure;
  kal_uint16 Wb;
  kal_uint8 Mirror;
  kal_bool BypassAe;
  kal_bool BypassAwb;
  kal_bool VideoMode;
  kal_uint8 Ctrl3A;
  kal_uint8 SdeCtrl;
  kal_uint8 Reg15;
  kal_uint16 Fps;
  kal_uint32 IntClk; /* internal clock = half of pclk */
  kal_uint16 FrameHeight;
  kal_uint16 LineLength;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} OV7690Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    OV7690HalfAdjust
*
* DESCRIPTION
*    This function dividend / divisor and use round-up.
*
* PARAMETERS
*    DividEnd
*    Divisor
*
* RETURNS
*    [DividEnd / Divisor]
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint32 OV7690HalfAdjust(kal_uint32 DividEnd, kal_uint32 Divisor)
{
  return (DividEnd + (Divisor >> 1)) / Divisor; /* that is [DividEnd / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    OV7690SetMirror
*
* DESCRIPTION
*    This function set the Mirror to the CMOS sensor
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
static void OV7690SetMirror(kal_uint8 Mirror)
{
  kal_uint8 Reg = 0x16;
  
  if (OV7690Sensor.Mirror == Mirror)
  {
    return;
  }
  OV7690Sensor.Mirror = Mirror;
  switch (OV7690Sensor.Mirror)
  {
  case IMAGE_SENSOR_MIRROR_H:
    Reg |= 0x40;
    break;
  case IMAGE_SENSOR_MIRROR_V:
    Reg |= 0x80;
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    Reg |= 0xC0;
    break;
  }
  CamWriteCmosSensor(0x0C, Reg);
}

/*************************************************************************
* FUNCTION
*    OV7690SetClock
*
* DESCRIPTION
*    This function set sensor vt clock and op clock
*
* PARAMETERS
*    Clk: vt clock
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV7690SetClock(kal_uint32 Clk)
{
  static const kal_uint8 ClkSetting[][1] =
  {
    {0x00}, /* MCLK: 26M, INTERNAL CLK: 13M, PCLK: 26M */
    {0x01}, /* MCLK: 26M, INTERNAL CLK: 6.5M, PCLK: 13M */
  };
  kal_uint8 i = 0;
  
  if (OV7690Sensor.IntClk == Clk)
  {
    return;
  }
  OV7690Sensor.IntClk = Clk;
  switch (OV7690Sensor.IntClk)
  {
  case 13000000: i = 0; break;
  case 6500000:  i = 1; break;
  default: ASSERT(0);
  }
/*
  PLL Control:
  PLL clock(f1) = MCLK x N / M, where
    reg29[7:6]: PLL divider
      00: /1, 01: /2, 10: /3, 11: /4
    reg29[5:4]: PLL output control
      00: Bypass PLL, 01: 4x, 10: 6x, 11: 8x
  Int. clock(f2) = f1 / (reg0x11[5:0] + 1)
  PCLK = f2 / 2 / L, where L = 1 if 0x3E[4] = 1, otherwise L = 2
*/
  CamWriteCmosSensor(0x11, ClkSetting[i][0]);
}

#if 0 /* not referenced currently */
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
#endif
/*************************************************************************
* FUNCTION
*    OV7690LSCSetting
*
* DESCRIPTION
*    This function set Lens Shading Correction.
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
static void OV7690LSCSetting(void)
{
  static const kal_uint8 Data[] =
  {
#if 0 /* Sunny F28 */
/* under construction !*/
#elif 0 /* Sunny F24 */
/* under construction !*/
#elif 0 /* Phoenix F28 */
/* under construction !*/
#elif 1 /* Phoenix F24 */
    0x90,0x00,0xa0,0x80,0x18,0x14,0x15,
#elif 0 /* Dongya F24 */
/* under construction !*/
#endif
  };
  
  CamWriteCmosSensor(0x85, Data[0]);
  CamWriteCmosSensor(0x86, Data[1]);
  CamWriteCmosSensor(0x87, Data[2]);
  CamWriteCmosSensor(0x88, Data[3]);
  CamWriteCmosSensor(0x89, Data[4]);
  CamWriteCmosSensor(0x8a, Data[5]);
  CamWriteCmosSensor(0x8b, Data[6]);
}

/*************************************************************************
* FUNCTION
*    OV7690AeEnable
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
static void OV7690AeEnable(kal_bool Enable)
{
  const kal_bool AeEnable = (OV7690Sensor.Ctrl3A&0x05) ? KAL_TRUE : KAL_FALSE;
  
  if (OV7690Sensor.BypassAe)
  {
    Enable = KAL_FALSE;
  }
  if (AeEnable == Enable)
  {
    return;
  }
  if (Enable)
  {
    OV7690Sensor.Ctrl3A |= 0x05;
    OV7690Sensor.Reg15 |= 0x80;
  }
  else
  {
    OV7690Sensor.Ctrl3A &= 0xF8;
    /* extra line can not be set if not fix frame rate!!! */
    OV7690Sensor.Reg15 &= 0x7F;
  }
  CamWriteCmosSensor(0x13, OV7690Sensor.Ctrl3A);
  CamWriteCmosSensor(0x15, OV7690Sensor.Reg15);
}

/*************************************************************************
* FUNCTION
*    OV7690AwbEnable
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
static void OV7690AwbEnable(kal_bool Enable)
{
  const kal_bool AwbEnable = (OV7690Sensor.Ctrl3A&0x02) ? KAL_TRUE : KAL_FALSE;
  
  if (OV7690Sensor.BypassAwb)
  {
    Enable = KAL_FALSE;
  }
  if (AwbEnable == Enable)
  {
    return;
  }
  if (Enable && CAM_WB_AUTO == OV7690Sensor.Wb)
  {
    OV7690Sensor.Ctrl3A |= 0x02;
  }
  else
  {
    OV7690Sensor.Ctrl3A &= 0xFD;
  }
  CamWriteCmosSensor(0x13, OV7690Sensor.Ctrl3A);
}

/*************************************************************************
* FUNCTION
*    OV7690SetDummy
*
* DESCRIPTION
*    This function add DummyPixel and DummyLine.
*
* PARAMETERS
*    DummyPixel
*    DummyLine
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV7690SetDummy(kal_uint16 DummyPixel, kal_uint16 DummyLine)
{
  kal_bool update = KAL_FALSE; /* need config banding */
  const kal_uint16 LineLength = DummyPixel + OV7690_PERIOD_PIXEL_NUMS;
  const kal_uint16 FrameHeight = DummyLine + OV7690_PERIOD_LINE_NUMS;
  
  /* config line length */
  if (LineLength != OV7690Sensor.LineLength)
  {
    if (LineLength > OV7690_MAX_LINELENGTH)
    {
      ASSERT(0);
    }
    update = KAL_TRUE;
    OV7690Sensor.LineLength = LineLength;
    CamWriteCmosSensor(0x2B, LineLength); /* Actually, the 0x2a,0x2b is not DummyPixel, it's the total line length */
  }
  /* config frame height */
  if (FrameHeight != OV7690Sensor.FrameHeight)
  {
    if (DummyLine > OV7690_MAX_FRAMEHEIGHT)
    {
      ASSERT(0);
    }
    update = KAL_TRUE;
    OV7690Sensor.FrameHeight = FrameHeight;
    CamWriteCmosSensor(0x2C, DummyLine);
  }
  /* config banding */
  if (update)
  {
    kal_uint8 BandStep50, BandStep60, MaxBand50, MaxBand60;
    
    CamWriteCmosSensor(0x2A, ((LineLength >> 4)&0x70)|((DummyLine >> 8)&0x0F)|(CamReadCmosSensor(0x2A)&0x80));
    BandStep50 = OV7690HalfAdjust(OV7690Sensor.IntClk, LineLength * OV7690_NUM_50HZ * 2);
    BandStep60 = OV7690HalfAdjust(OV7690Sensor.IntClk, LineLength * OV7690_NUM_60HZ * 2);
    
    CamWriteCmosSensor(0x50, BandStep50); /* 50Hz banding step */
    CamWriteCmosSensor(0x51, BandStep60); /* 60Hz banding step */
    
    /* max banding in a frame */
    MaxBand50 = FrameHeight / BandStep50;
    MaxBand60 = FrameHeight / BandStep60;
    CamWriteCmosSensor(0x20, ((MaxBand50&0x10) << 3)|((MaxBand60&0x10) << 2));
    CamWriteCmosSensor(0x21, ((MaxBand50&0x0F) << 4)|(MaxBand60&0x0F));
  }
}

/*************************************************************************
* FUNCTION
*    OV7690CalFps
*
* DESCRIPTION
*    This function calculate & set frame rate and fix frame rate when video mode
*    MUST BE INVOKED AFTER OV7690_preview() !!!
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
static void OV7690CalFps(void)
{
  /* camera preview also fix frame rate for auto frame rate will cause AE peak */
  if (OV7690Sensor.VideoMode) /* fix frame rate when video mode */
  {
    kal_uint32 LineLength, FrameHeight;
    
    /* get max line length */
    LineLength = OV7690Sensor.IntClk * OV7690_FPS(1) / (OV7690Sensor.Fps * OV7690Sensor.FrameHeight);
    if (LineLength > OV7690_PERIOD_PIXEL_NUMS * 2) /* overflow check */
    {
      OV7690SetClock(OV7690_VIDEO_LOW_CLK); /* slow down clock */
      LineLength = OV7690Sensor.IntClk * OV7690_FPS(1) / (OV7690Sensor.Fps * OV7690Sensor.FrameHeight);
      if (LineLength > OV7690_MAX_LINELENGTH) /* overflow check */
      {
        LineLength = OV7690_MAX_LINELENGTH;
      }
    }
    if (LineLength < OV7690Sensor.LineLength)
    {
      LineLength = OV7690Sensor.LineLength;
    }
    /* get frame height */
    FrameHeight = OV7690Sensor.IntClk * OV7690_FPS(1) / (OV7690Sensor.Fps * LineLength);
    if (FrameHeight < OV7690Sensor.FrameHeight)
    {
      FrameHeight = OV7690Sensor.FrameHeight;
    }
    OV7690SetDummy(LineLength - OV7690_PERIOD_PIXEL_NUMS, FrameHeight - OV7690_PERIOD_LINE_NUMS);
    
    /* fix frame rate */
    OV7690Sensor.Reg15 &= 0x7F;
    CamWriteCmosSensor(0x15, OV7690Sensor.Reg15);
  }
  else
  {
    kal_uint16 CurFps;
    
    CurFps = OV7690HalfAdjust(OV7690Sensor.IntClk * OV7690_FPS(1),
                              OV7690Sensor.Fps * OV7690Sensor.LineLength * OV7690Sensor.FrameHeight);
    /* to force frame rate change when change night mode to normal mode */
    OV7690Sensor.Reg15 &= 0x0F;
    switch (CurFps)
    {
    case 0:
    case 1: break;
    case 2: OV7690Sensor.Reg15 |= 0x10; break;
    case 3: OV7690Sensor.Reg15 |= 0x20; break;
    case 4: OV7690Sensor.Reg15 |= 0x30; break;
    default: OV7690Sensor.Reg15 |= 0x40; break;
    }
    CamWriteCmosSensor(0x15, OV7690Sensor.Reg15);
    OV7690Sensor.Reg15 |= 0x80;
    CamWriteCmosSensor(0x15, OV7690Sensor.Reg15);
  }
}

/*************************************************************************
* FUNCTION
*    OV7690SceneMode
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
static MM_ERROR_CODE_ENUM OV7690SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*    OV7690Wb
*
* DESCRIPTION
*    Wb setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7690Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    const static kal_uint8 AwbGain[5][2]=
    { /* R gain, B gain. base: 0x40 */
     {0x56,0x5c}, /* cloud */
     {0x56,0x58}, /* daylight */
     {0x40,0x67}, /* INCANDESCENCE */
     {0x60,0x58}, /* FLUORESCENT */
     {0x40,0xA0}, /* TUNGSTEN */
    };
    kal_uint8 i;
    
    if (OV7690Sensor.Wb == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    OV7690Sensor.Wb = In->FeatureSetValue;
    switch (OV7690Sensor.Wb)
    {
    case CAM_WB_AUTO:
      OV7690AwbEnable(KAL_TRUE);
      return MM_ERROR_NONE;
    case CAM_WB_CLOUD:         i = 0; break;
    case CAM_WB_DAYLIGHT:      i = 1; break;
    case CAM_WB_INCANDESCENCE: i = 2; break;
    case CAM_WB_FLUORESCENT:   i = 3; break;
    case CAM_WB_TUNGSTEN:      i = 4; break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    OV7690AwbEnable(KAL_FALSE);
    CamWriteCmosSensor(0x02, AwbGain[i][0]); /* AWb R gain */
    CamWriteCmosSensor(0x01, AwbGain[i][1]); /* AWb B gain */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7690Ev
*
* DESCRIPTION
*    Exposure setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7690Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Exposure = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Exposure->IsSupport = KAL_TRUE;
    Exposure->ItemCount = 9;
    Exposure->SupportItem[0] = CAM_EV_NEG_4_3;
    Exposure->SupportItem[1] = CAM_EV_NEG_3_3;
    Exposure->SupportItem[2] = CAM_EV_NEG_2_3;
    Exposure->SupportItem[3] = CAM_EV_NEG_1_3;
    Exposure->SupportItem[4] = CAM_EV_ZERO;
    Exposure->SupportItem[5] = CAM_EV_POS_1_3;
    Exposure->SupportItem[6] = CAM_EV_POS_2_3;
    Exposure->SupportItem[7] = CAM_EV_POS_3_3;
    Exposure->SupportItem[8] = CAM_EV_POS_4_3;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    static const kal_uint8 Data[9][2]=
    {
      {0x09,0x40}, /* EV -4 */
      {0x09,0x30}, /* EV -3 */
      {0x09,0x20}, /* EV -2 */
      {0x09,0x10}, /* EV -1 */
      {0x01,0x00}, /* EV 0 */
      {0x01,0x10}, /* EV +1 */
      {0x01,0x20}, /* EV +2 */
      {0x01,0x30}, /* EV +3 */
      {0x01,0x40}, /* EV +4 */
    };
    kal_uint8 i;
    
    if (OV7690Sensor.Exposure == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    OV7690Sensor.Exposure = In->FeatureSetValue;
    switch (OV7690Sensor.Exposure)
    {
    case CAM_EV_NEG_4_3: i = 0; break;
    case CAM_EV_NEG_3_3: i = 1; break;
    case CAM_EV_NEG_2_3: i = 2; break;
    case CAM_EV_NEG_1_3: i = 3; break;
    case CAM_EV_ZERO:    i = 4; break;
    case CAM_EV_POS_1_3: i = 5; break;
    case CAM_EV_POS_2_3: i = 6; break;
    case CAM_EV_POS_3_3: i = 7; break;
    case CAM_EV_POS_4_3: i = 8; break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    CamWriteCmosSensor(0xDC, Data[i][0]); /* SGNSET */
    CamWriteCmosSensor(0xD3, Data[i][1]); /* YBright */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7690Effect
*
* DESCRIPTION
*    Effect setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7690Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    static const kal_uint8 Data[6][3]=
    {
      {0x00,0x80,0x80}, /* NORMAL */
      {0x18,0x80,0x80}, /* GRAYSCALE */
      {0x18,0x40,0xA0}, /* SEPIA */
      {0x18,0x60,0x60}, /* SEPIAGREEN */
      {0x18,0xA0,0x40}, /* SEPIABLUE */
      {0x40,0x80,0x80}, /* COLORINV */
    };
    kal_uint8 i;
    
    if (OV7690Sensor.Effect == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    OV7690Sensor.Effect = In->FeatureSetValue;
    switch (OV7690Sensor.Effect)
    {
    case CAM_EFFECT_ENC_NORMAL:     i = 0; break;
    case CAM_EFFECT_ENC_GRAYSCALE:  i = 1; break;
    case CAM_EFFECT_ENC_SEPIA:      i = 2; break;
    case CAM_EFFECT_ENC_SEPIAGREEN: i = 3; break;
    case CAM_EFFECT_ENC_SEPIABLUE:  i = 4; break;
    case CAM_EFFECT_ENC_COLORINV:   i = 5; break;
    default: return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    OV7690Sensor.SdeCtrl &= 0xA7; /* disable bit3/4/6 */
    OV7690Sensor.SdeCtrl |= Data[i][0];
    CamWriteCmosSensor(0xD2, OV7690Sensor.SdeCtrl);
    CamWriteCmosSensor(0xDA, Data[i][1]);
    CamWriteCmosSensor(0xDB, Data[i][2]);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7690InitialSetting
*
* DESCRIPTION
*    This function initialize the registers of CMOS sensor
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
static void OV7690InitialSetting(void)
{
  CamWriteCmosSensor(0x12, 0x80); /* [7]: software reset */
  kal_sleep_task(1);
  CamWriteCmosSensor(0x0C, 0x16);
/*
  Please update reg0x48 from 40 to 42. Also, please apply the rule for OV7690.
  If DOVDD = 1.7 - 2.0V, then reg0x49 = 0x0C
  IF DOVDD = 2.1 - 2.5V, then reg0x49 = 0x04
  If DOVDD = 2.6 - 3.0V, then reg0x49 = 0x0D
  
  That is, for example, if your DOVDD = 2.8v, please insert setting as below.
  reg0x48 = 0x42
  reg0x49 = 0x0D
*/
  CamWriteCmosSensor(0x48, 0x42); /* 1.75x pre-gain */
  CamWriteCmosSensor(0x49, 0x0D); /* releated IO voltage */
  CamWriteCmosSensor(0x41, 0x43);
  CamWriteCmosSensor(0x81, 0xFF); /* do not disable SDE!!! */
  CamWriteCmosSensor(0x16, 0x03);
  CamWriteCmosSensor(0x39, 0x80);
  
  /* Clock */
  CamWriteCmosSensor(0x11, 0x00);
  CamWriteCmosSensor(0x3E, 0x30);
  
  /* Isp common */
  CamWriteCmosSensor(0x13, 0xF7);
  CamWriteCmosSensor(0x14, 0x21); /* 8x gain ceiling, PPChrg off */
  CamWriteCmosSensor(0x15, 0x04);
  CamWriteCmosSensor(0x1E, 0x33);
  CamWriteCmosSensor(0x0E, 0x03); /* driving capability: 0x00:1x, 0x01:2x, 0x02:3x, 0x03:4x */
  CamWriteCmosSensor(0xD2, 0x04); /* SDE ctrl */
  
  /* Format */
  CamWriteCmosSensor(0x12, 0x00);
  CamWriteCmosSensor(0x82, 0x03);
  CamWriteCmosSensor(0xd0, 0x48);
  CamWriteCmosSensor(0x80, 0x7f);
  CamWriteCmosSensor(0x22, 0x00); /* Disable Optical Black Output Selection bit[7] */
  
  /* Resolution */
  CamWriteCmosSensor(0x2A, 0x30); /* linelength */
  CamWriteCmosSensor(0x2B, 0x4E);
  CamWriteCmosSensor(0x2C, 0x00); /* dummy line */
  CamWriteCmosSensor(0x17, OV7690_IMAGE_SENSOR_HSTART); /* H window start line */
  CamWriteCmosSensor(0x18, (OV7690_IMAGE_SENSOR_HACTIVE + 0x10) >> 2); /* H sensor size */
  CamWriteCmosSensor(0x19, OV7690_IMAGE_SENSOR_VSTART); /* V window start line */
  CamWriteCmosSensor(0x1A, (OV7690_IMAGE_SENSOR_VACTIVE + OV7690_IMAGE_SENSOR_VSTART) >> 1); /* V sensor size */
  CamWriteCmosSensor(0xC8, OV7690_IMAGE_SENSOR_HACTIVE >> 8);
  CamWriteCmosSensor(0xC9, OV7690_IMAGE_SENSOR_HACTIVE);/* ISP input hsize */
  CamWriteCmosSensor(0xCA, OV7690_IMAGE_SENSOR_VACTIVE >> 8);
  CamWriteCmosSensor(0xCB, OV7690_IMAGE_SENSOR_VACTIVE);/* ISP input vsize */
  CamWriteCmosSensor(0xCC, OV7690_IMAGE_SENSOR_HACTIVE >> 8);
  CamWriteCmosSensor(0xCD, OV7690_IMAGE_SENSOR_HACTIVE);/* ISP output hsize */
  CamWriteCmosSensor(0xCE, OV7690_IMAGE_SENSOR_VACTIVE >> 8);
  CamWriteCmosSensor(0xCF, OV7690_IMAGE_SENSOR_VACTIVE);/* ISP output vsize */
  
  OV7690LSCSetting();
  
  /* Color Matrix */
  CamWriteCmosSensor(0xbb, 0xac);
  CamWriteCmosSensor(0xbc, 0xae);
  CamWriteCmosSensor(0xbd, 0x02);
  CamWriteCmosSensor(0xbe, 0x1f);
  CamWriteCmosSensor(0xbf, 0x93);
  CamWriteCmosSensor(0xc0, 0xb1);
  CamWriteCmosSensor(0xc1, 0x1A);
  
  /* Edge + Denoise */
  CamWriteCmosSensor(0xb4, 0x06);
  CamWriteCmosSensor(0xb7, 0x07);
  CamWriteCmosSensor(0xb8, 0x06);
  CamWriteCmosSensor(0xb9, 0x00);
  CamWriteCmosSensor(0xba, 0x40);
  
  /* AEC/AGC target */
  /*This only in fixed frame change!*/
  CamWriteCmosSensor(0x24, 0x58);
  CamWriteCmosSensor(0x25, 0x48);
  CamWriteCmosSensor(0x26, 0x92);
  
  /* UV adjust */
  CamWriteCmosSensor(0x5A, 0x74);
  CamWriteCmosSensor(0x5B, 0x9f);
  CamWriteCmosSensor(0x5C, 0x42);
  CamWriteCmosSensor(0x5d, 0x42);
  
  /* Gamma */
  CamWriteCmosSensor(0xa3, 0x05);
  CamWriteCmosSensor(0xa4, 0x10);
  CamWriteCmosSensor(0xa5, 0x25);
  CamWriteCmosSensor(0xa6, 0x4f);
  CamWriteCmosSensor(0xa7, 0x5f);
  CamWriteCmosSensor(0xa8, 0x6c);
  CamWriteCmosSensor(0xa9, 0x78);
  CamWriteCmosSensor(0xaa, 0x82);
  CamWriteCmosSensor(0xab, 0x8b);
  CamWriteCmosSensor(0xac, 0x92);
  CamWriteCmosSensor(0xad, 0x9f);
  CamWriteCmosSensor(0xae, 0xAc);
  CamWriteCmosSensor(0xaf, 0xC1);
  CamWriteCmosSensor(0xb0, 0xD5);
  CamWriteCmosSensor(0xb1, 0xE7);
  CamWriteCmosSensor(0xb2, 0x21);
  
  /* Advance AWB */
  CamWriteCmosSensor(0x8c, 0x5c);
  CamWriteCmosSensor(0x8d, 0x11);
  CamWriteCmosSensor(0x8e, 0x12);
  CamWriteCmosSensor(0x8f, 0x19);
  CamWriteCmosSensor(0x90, 0x50);
  CamWriteCmosSensor(0x91, 0x00);
  CamWriteCmosSensor(0x92, 0x86);
  CamWriteCmosSensor(0x93, 0x80);
  CamWriteCmosSensor(0x94, 0x13);
  CamWriteCmosSensor(0x95, 0x1b);
  CamWriteCmosSensor(0x96, 0xff);
  CamWriteCmosSensor(0x97, 0x00);
  CamWriteCmosSensor(0x98, 0x3e);
  CamWriteCmosSensor(0x99, 0x31);
  CamWriteCmosSensor(0x9a, 0x4e);
  //(0x9b, 0x41)20081217 Here adjust AWb, when enter preview, AWb didn't work!
  CamWriteCmosSensor(0x9b, 0x3d);
  CamWriteCmosSensor(0x9c, 0xf0);
  CamWriteCmosSensor(0x9d, 0xf0);
  CamWriteCmosSensor(0x9e, 0xf0);
  CamWriteCmosSensor(0x9f, 0xff);
  CamWriteCmosSensor(0xa0, 0x6a);
  CamWriteCmosSensor(0xa1, 0x65);
  CamWriteCmosSensor(0xa2, 0x11);
  
  /* test pattern */
#if defined(__OV7690_TEST_PATTERN__)
  CamWriteCmosSensor(0x82, 0x0F);
#endif
}

/*************************************************************************
* FUNCTION
*    OV7690GetSensorInfo
*
* DESCRIPTION
*    This function set sensor infomation
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
static void OV7690GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = OV7690_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_LOW;
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;
  Info->PreviewWidth = OV7690_IMAGE_SENSOR_WIDTH_DRV;
  Info->PreviewHeight = OV7690_IMAGE_SENSOR_HEIGHT_DRV;
  Info->FullWidth = OV7690_IMAGE_SENSOR_WIDTH_DRV;
  Info->FullHeight = OV7690_IMAGE_SENSOR_HEIGHT_DRV;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    OV7690PowerOn
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
static kal_uint16 OV7690PowerOn(void)
{
  kal_uint16 SensorId;
  
  CisModulePowerOn(OV7690Sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, OV7690_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);
  CamPdnPinCtrl(OV7690Sensor.SensorIdx, 1);
  CamRstPinCtrl(OV7690Sensor.SensorIdx, 0);
  kal_sleep_task(2); /* >= 5ms */
  
  CamPdnPinCtrl(OV7690Sensor.SensorIdx, 0);
  kal_sleep_task(1); /* >= 1ms */
  CamRstPinCtrl(OV7690Sensor.SensorIdx, 1);
  kal_sleep_task(5); /* >= 20ms */
  
  SensorId = (CamReadCmosSensor(0x0A) << 8)|CamReadCmosSensor(0x0B);
  if (SensorId != OV7690_SENSOR_ID) /* READ SENSOR ID */
  {
#if defined(__OV7690_DEBUG_TRACE__)
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", SensorId);
#endif
  }
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    OV7690DetectSensorId
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
static kal_uint32 OV7690DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM OV7690SensorClose(void);
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (OV7690Sensor.SensorIdx)
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
      SensorId = OV7690PowerOn();
      OV7690SensorClose();
      if (OV7690_SENSOR_ID == SensorId)
      {
        return OV7690_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    OV7690StillCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM OV7690StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7690Banding
*
* DESCRIPTION
*    This function get banding setting
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
static MM_ERROR_CODE_ENUM OV7690Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    CamWriteCmosSensor(0x14, CAM_BANDING_50HZ == In->FeatureSetValue ? 0x21 : 0x20);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7690InitOperationPara
*
* DESCRIPTION
*    This function set sensor operation para
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
static void OV7690InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 0;
  Para->PreviewDelayFrame = 0;
  Para->PreviewDisplayWaitFrame = 8;
}

/*************************************************************************
* FUNCTION
*    OV7690Preview
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
static void OV7690Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint16 DummyPixel;
  
  switch (Id)
  {
  case  CAL_SCENARIO_VIDEO:
    OV7690Sensor.VideoMode = KAL_TRUE;
    OV7690Sensor.Fps = OV7690_FPS(In->MaxVideoFrameRate) / 10;
    DummyPixel = 0;
    break;
  default:
    OV7690Sensor.VideoMode = KAL_TRUE; /* OV7690 bug: auto mode will cause AE peak!!! */
    OV7690Sensor.Fps = In->NightMode ? OV7690_FPS(15) : OV7690_FPS(30);
    DummyPixel = 0;
  }
  OV7690SetMirror(In->ImageMirror);
  OV7690SetClock(OV7690_PREVIEW_CLK);
  OV7690SetDummy(DummyPixel, 0);
  OV7690CalFps(); /* need cal new fps */
  CamWriteCmosSensor(0x14, CAM_BANDING_50HZ == In->BandingFreq ? 0x21 : 0x20);
  OV7690AeEnable(KAL_TRUE);
  OV7690AwbEnable(KAL_TRUE);
  
  Out->WaitStableFrameNum = 0;
  Out->GrabStartX = OV7690_X_START;
  Out->GrabStartY = OV7690_Y_START;
  Out->ExposureWindowWidth = OV7690_IMAGE_SENSOR_WIDTH;
  Out->ExposureWindowHeight = OV7690_IMAGE_SENSOR_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    OV7690Capture
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
static void OV7690Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  Out->WaitStableFrameNum = 0;
  Out->GrabStartX = OV7690_X_START;
  Out->GrabStartY = OV7690_Y_START;
  Out->ExposureWindowWidth = OV7690_IMAGE_SENSOR_WIDTH;
  Out->ExposureWindowHeight = OV7690_IMAGE_SENSOR_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    OV7690SensorOpen
*
* DESCRIPTION
*    This function read sensor id and init sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7690SensorOpen(void)
{
  if (OV7690PowerOn() != OV7690_SENSOR_ID)
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  OV7690InitialSetting();
  
  /* default setting */
  {
    IMAGE_SENSOR_INDEX_ENUM SensorIdx = OV7690Sensor.SensorIdx;
    sensor_data_struct *NvramData = OV7690Sensor.NvramData;
    
    kal_mem_set(&OV7690Sensor, 0xFF, sizeof(OV7690Sensor));
    OV7690Sensor.BypassAe = KAL_FALSE;
    OV7690Sensor.BypassAwb = KAL_FALSE;
    OV7690Sensor.Ctrl3A = CamReadCmosSensor(0x13);
    OV7690Sensor.SdeCtrl = CamReadCmosSensor(0xD2);
    OV7690Sensor.Reg15 = CamReadCmosSensor(0x15);
    OV7690Sensor.SensorIdx = SensorIdx;
    OV7690Sensor.NvramData = NvramData;
  }
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7690SensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    Id: scenario id
*    In: input parameter
*    Out: output parameter
*    OutLen: output parameter length
*    RealOutLen: real output parameter length
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7690SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  kal_uint32 i=0;
  
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return OV7690WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
  /* query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = OV7690Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = OV7690Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = OV7690Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = OV7690StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
    ErrCode = OV7690Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = OV7690SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = OV7690SceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    OV7690GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV7690DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV7690Sensor.Fps * 10 / OV7690_FPS(1);
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    OV7690InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(OV7690Sensor.SensorIdx, Out);
    break;
	case IMAGE_SENSOR_FEATURE_SET_REGISTER:
	  for (i=0;i<((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->RegNum;i++)
	  {
		 CamWriteCmosSensor(((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->pRegAddr[i],((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->pRegData[i]);
	  }
		 break;
	case IMAGE_SENSOR_FEATURE_GET_REGISTER:
	  ((P_IMAGE_SENSOR_REG_IN_STRUCT)Out)->RegNum = ((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->RegNum;
	   for (i=0;i<((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->RegNum;i++)
	   {
		  ((P_IMAGE_SENSOR_REG_IN_STRUCT) Out)->pRegAddr[i]=((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->pRegAddr[i];
		  ((P_IMAGE_SENSOR_REG_IN_STRUCT) Out)->pRegData[i]=CamReadCmosSensor(((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->pRegAddr[i]);
	   }
	   break;
	case IMAGE_SENSOR_FEATURE_GET_DATA_INFO:
	   ((P_SENSOR_REG_WIDTH_STRUCT)Out)->AddrWidth=8;
	   ((P_SENSOR_REG_WIDTH_STRUCT)Out)->ParaWidth=8;
		break;


  
  /* set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(OV7690Sensor.SensorIdx, 1);
    CamRstPinCtrl(OV7690Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    OV7690Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    OV7690Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    OV7690Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    OV7690AeEnable(OV7690Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    OV7690Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    OV7690AwbEnable(OV7690Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    OV7690SensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    Id: scenario id
*    In/Out: parameter
*    OutLen: Out parameter length
*    RealOutLen: Real out parameter length
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7690SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
  case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
#endif
    OV7690Preview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    OV7690Capture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7690SensorClose
*
* DESCRIPTION
*    This function is to turn off sensor module power.
*
* PARAMETERS
*    None
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV7690SensorClose(void)
{
  CamPdnPinCtrl(OV7690Sensor.SensorIdx, 1); /* goto standby */
  CamRstPinCtrl(OV7690Sensor.SensorIdx, 0);
  CisModulePowerOn(OV7690Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV7690SensorFunc
*
* DESCRIPTION
*    This function get sensor function pointer
*
* PARAMETERS
*    sensor function pointer
*
* RETURNS
*    Error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM OV7690SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV7690 =
  {
    OV7690SensorOpen,
    OV7690SensorFeatureCtrl,
    OV7690SensorCtrl,
    OV7690SensorClose,
  };
  *pfSensorFunc = &ImageSensorFuncOV7690;
  
  return MM_ERROR_NONE;
}

