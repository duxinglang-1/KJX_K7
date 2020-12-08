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
 *   image_sensor_GC0308.c
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

/* #define __GC0308_DEBUG_TRACE__ */

static struct
{
  kal_bool BypassAe;
  kal_bool BypassAwb;
  kal_uint8 Ctrl3A;
  kal_uint8 AecMode3;
  kal_uint16 VideoFps;
  kal_uint32 IntClk; /* internal clock = half of pclk */
  kal_uint16 FrameHeight;
  kal_uint16 LineLength;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} GC0308Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    GC0308HalfAdjust
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
__inline static kal_uint32 GC0308HalfAdjust(kal_uint32 DividEnd, kal_uint32 Divisor)
{
  return (DividEnd + (Divisor >> 1)) / Divisor; /* that is [DividEnd / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    GC0308SetMirror
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
static void GC0308SetMirror(kal_uint8 Mirror)
{
  switch (Mirror)
  {
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
    CamWriteCmosSensor(0x14, 0x10);
  }
}

/*************************************************************************
* FUNCTION
*    GC0308SetClock
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
static void GC0308SetClock(kal_uint32 Clk)
{
  kal_uint8 ClkDiv;
  
  if (GC0308Sensor.IntClk == Clk)
  {
    return;
  }
  GC0308Sensor.IntClk = Clk;
  switch (GC0308Sensor.IntClk)
  {
  case GC0308_MCLK / 2: ClkDiv = 0x00; break; /* pclk = mclk */
  case GC0308_MCLK / 4: ClkDiv = 0x11; break; /* pclk = mclk / 2 */
  case GC0308_MCLK / 8: ClkDiv = 0x32; break; /* pclk = mclk / 4 */
  default: ASSERT(0);
  }
  CamWriteCmosSensor(0x28, ClkDiv);
}

/*************************************************************************
* FUNCTION
*    GC0308WriteShutter
*
* DESCRIPTION
*    This function apply Shutter to sensor
*
* PARAMETERS
*    Shutter: integration time
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0308WriteShutter(kal_uint32 Shutter)
{
  CamWriteCmosSensor(0x03, Shutter >> 8);
  CamWriteCmosSensor(0x04, Shutter);
}

/*************************************************************************
* FUNCTION
*    GC0308ReadShutter
*
* DESCRIPTION
*    This function get shutter from sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    Shutter: integration time
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 GC0308ReadShutter(void)
{
  return (CamReadCmosSensor(0x03) << 8)|CamReadCmosSensor(0x04);
}

/*************************************************************************
* FUNCTION
*    GC0308AeEnable
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
static void GC0308AeEnable(kal_bool Enable)
{
  const kal_bool AeEnable = (GC0308Sensor.AecMode3&0x80) ? KAL_TRUE : KAL_FALSE;
  
  if (GC0308Sensor.BypassAe)
  {
    Enable = KAL_FALSE;
  }
  if (AeEnable == Enable)
  {
    return;
  }
  if (Enable)
  {
    GC0308Sensor.AecMode3 |= 0x80;
  }
  else
  {
    GC0308Sensor.AecMode3 &= 0x7F;
  }
  CamWriteCmosSensor(0xD2, GC0308Sensor.AecMode3);
}

/*************************************************************************
* FUNCTION
*    GC0308AwbEnable
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
static void GC0308AwbEnable(kal_bool Enable)
{
  const kal_bool AwbEnable = (GC0308Sensor.Ctrl3A&0x02) ? KAL_TRUE : KAL_FALSE;
  
  if (GC0308Sensor.BypassAwb)
  {
    Enable = KAL_FALSE;
  }
  if (AwbEnable == Enable)
  {
    return;
  }
  if (Enable)
  {
    GC0308Sensor.Ctrl3A |= 0x02;
  }
  else
  {
    GC0308Sensor.Ctrl3A &= 0xFD;
  }
  CamWriteCmosSensor(0x22, GC0308Sensor.Ctrl3A);
}

/*************************************************************************
* FUNCTION
*    GC0308SetBaseShutter
*
* DESCRIPTION
*    This function set base shutter to the CMOS sensor
*
* PARAMETERS
*    Banding: 50Hz or 60Hz
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0308SetBaseShutter(kal_uint8 Banding)
{
  const kal_uint16 bandStep = GC0308HalfAdjust(GC0308Sensor.IntClk, GC0308Sensor.LineLength * Banding * 2);
  
  CamWriteCmosSensor(0xE2, bandStep >> 8);
  CamWriteCmosSensor(0xE3, bandStep);
}

/*************************************************************************
* FUNCTION
*    GC0308SetDummy
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
static void GC0308SetDummy(kal_uint16 DummyPixel, kal_uint16 DummyLine)
{
  const kal_uint16 LineLength = DummyPixel + GC0308_PERIOD_PIXEL_NUMS;
  const kal_uint16 FrameHeight = DummyLine + GC0308_PERIOD_LINE_NUMS;
  kal_bool update = KAL_FALSE;
  
  /* add default dummy */
  DummyPixel += GC0308_IMAGE_SENSOR_HBLANKING;
  DummyLine += GC0308_IMAGE_SENSOR_VBLANKING;
  
  /* config line length */
  if (LineLength != GC0308Sensor.LineLength)
  {
    if (LineLength > GC0308_MAX_LINELENGTH)
    {
      ASSERT(0);
    }
    update = KAL_TRUE;
    GC0308Sensor.LineLength = LineLength;
    CamWriteCmosSensor(0x01, DummyPixel);
  }
  /* config frame height */
  if (FrameHeight != GC0308Sensor.FrameHeight)
  {
    if (FrameHeight > GC0308_MAX_FRAMEHEIGHT)
    {
      ASSERT(0);
    }
    update = KAL_TRUE;
    GC0308Sensor.FrameHeight = FrameHeight;
    CamWriteCmosSensor(0x02, DummyLine);
  }
  if (update)
  {
    CamWriteCmosSensor(0x0F, ((DummyLine >> 4)&0xF0)|((DummyPixel >> 8)&0x0F));
  }
}

/*************************************************************************
* FUNCTION
*    GC0308SetVideoFps
*
* DESCRIPTION
*    This function calculate & fix frame rate in video mode
*
* PARAMETERS
*    Fps: video frame rate, base on GC0308_FPS(x)
*
* RETURNS
*    Fps: real frame rate set by sensor
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 GC0308SetVideoFps(kal_uint16 Fps)
{
  kal_uint32 LineLength, FrameHeight;
  kal_uint16 MaxExposure;
  
  /* get max line length */
  LineLength = GC0308Sensor.IntClk * GC0308_FPS(1) / (Fps * GC0308_PERIOD_LINE_NUMS);
  if (LineLength > GC0308_MAX_LINELENGTH) /* overflow check */
  {
    LineLength = GC0308_MAX_LINELENGTH;
  }
  if (LineLength < GC0308_PERIOD_PIXEL_NUMS)
  {
    LineLength = GC0308_PERIOD_PIXEL_NUMS;
  }
  
  /* get frame height */
  FrameHeight = GC0308Sensor.IntClk * GC0308_FPS(1) / (Fps * LineLength);
  if (FrameHeight > GC0308_MAX_FRAMEHEIGHT) /* overflow check */
  {
    FrameHeight = GC0308_MAX_FRAMEHEIGHT;
  }
  if (FrameHeight < GC0308_PERIOD_LINE_NUMS)
  {
    FrameHeight = GC0308_PERIOD_LINE_NUMS;
  }
  
  /* set max frame rate */
  GC0308SetDummy(LineLength - GC0308_PERIOD_PIXEL_NUMS, FrameHeight - GC0308_PERIOD_LINE_NUMS);
  
  /* set min frame rate */
  MaxExposure = FrameHeight - GC0308_SHUTTER_MAX_MARGIN;
  CamWriteCmosSensor(0xEC, 0x00); /* use exp level 1 */
  CamWriteCmosSensor(0xE4, MaxExposure >> 8); /* exp level 1: define max exposure */
  CamWriteCmosSensor(0xE5, MaxExposure);
  
  return GC0308Sensor.IntClk * GC0308_FPS(1) / (LineLength * FrameHeight);
}

/*************************************************************************
* FUNCTION
*    GC0308SetMinFps
*
* DESCRIPTION
*    This function calculate & set min frame rate in camera preview mode
*
* PARAMETERS
*    Fps: min frame rate, base on GC0308_FPS(x)
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0308SetMinFps(kal_uint16 Fps)
{
  kal_uint32 FrameHeight;
  kal_uint16 MaxExposure;
  
  /* get max frame height */
  FrameHeight = GC0308HalfAdjust(GC0308Sensor.IntClk * GC0308_FPS(1), Fps * GC0308Sensor.LineLength);
  
  /* set min frame rate */
  MaxExposure = FrameHeight - GC0308_SHUTTER_MAX_MARGIN;
  CamWriteCmosSensor(0xEC, 0x30); /* use exp level 4, can not use level 1??? */
  CamWriteCmosSensor(0xEA, MaxExposure >> 8); /* exp level 4: define max exposure */
  CamWriteCmosSensor(0xEB, MaxExposure);
}

/*************************************************************************
* FUNCTION
*    GC0308Ev
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
static MM_ERROR_CODE_ENUM GC0308Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    static const kal_uint8 Data[9][2]=
    {
      {0xC0,0x30}, /* EV -4 */
      {0xD0,0x38}, /* EV -3 */
      {0xE0,0x40}, /* EV -2 */
      {0xF0,0x48}, /* EV -1 */
      {0x00,0x50}, /* EV 0 */
      {0x20,0x58}, /* EV +1 */
      {0x30,0x60}, /* EV +2 */
      {0x40,0x68}, /* EV +3 */
      {0x50,0x70}, /* EV +4 */
    };
    kal_uint8 i;
    
    switch (In->FeatureSetValue)
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
    CamWriteCmosSensor(0xB5, Data[i][0]); /* SGNSET */
    CamWriteCmosSensor(0xD3, Data[i][1]); /* YBright */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0308Wb
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
static MM_ERROR_CODE_ENUM GC0308Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    static const kal_uint8 AwbGain[5][2]=
    { /* R gain, B gain. base: 2.6bits, 0x40=1x,0x60=1.5x */
     {0x70,0x4E}, /* cloud */
     {0x60,0x46}, /* daylight */
     {0x48,0x5C}, /* INCANDESCENCE */
     {0x40,0x50}, /* FLUORESCENT */
     {0x44,0x70}, /* TUNGSTEN */
    };
    static kal_uint8 BakRGain, BakBGain;
    kal_uint8 RGain, BGain;
    kal_int8 i = sizeof(AwbGain) / sizeof(AwbGain[0]);
    
    RGain = CamReadCmosSensor(0x5A);
    BGain = CamReadCmosSensor(0x5C);
    while (--i >= 0)
    {
      if (RGain == AwbGain[i][0] && BGain == AwbGain[i][1])
      {
        break;
      }
    }
    if (i < 0)
    {
      BakRGain = RGain;
      BakBGain = BGain;
    }
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO:
      CamWriteCmosSensor(0x5A, BakRGain); /* for AWB can adjust back */
      CamWriteCmosSensor(0x5C, BakBGain);
      GC0308AwbEnable(KAL_TRUE);
      return MM_ERROR_NONE;
    case CAM_WB_CLOUD:         i = 0; break;
    case CAM_WB_DAYLIGHT:      i = 1; break;
    case CAM_WB_INCANDESCENCE: i = 2; break;
    case CAM_WB_FLUORESCENT:   i = 3; break;
    case CAM_WB_TUNGSTEN:      i = 4; break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    GC0308AwbEnable(KAL_FALSE);
    CamWriteCmosSensor(0x5A, AwbGain[i][0]); /* awb R gain */
    CamWriteCmosSensor(0x5C, AwbGain[i][1]); /* awb B gain */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0308Effect
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
static MM_ERROR_CODE_ENUM GC0308Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Effect = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Effect->IsSupport = KAL_TRUE;
    Effect->ItemCount = 7;
    Effect->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    Effect->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    Effect->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    Effect->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    Effect->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    Effect->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    Effect->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    static const kal_uint8 Data[7][5]=
    {
      {0x00,0x54,0x38,0x00,0x00}, /* NORMAL */
      {0x02,0x54,0x40,0x00,0x00}, /* GRAYSCALE */
      {0x02,0x54,0x40,0xD0,0x28}, /* SEPIA */
      {0x02,0x88,0x40,0xC0,0xC0}, /* SEPIAGREEN */
      {0x02,0x54,0x40,0x50,0xE0}, /* SEPIABLUE */
      {0x01,0x54,0x40,0x00,0x00}, /* COLORINV */
      {0x03,0x54,0x40,0x00,0x00}, /* GRAYINV */
    };
    kal_uint8 i;
    
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:     i = 0; break;
    case CAM_EFFECT_ENC_GRAYSCALE:  i = 1; break;
    case CAM_EFFECT_ENC_SEPIA:      i = 2; break;
    case CAM_EFFECT_ENC_SEPIAGREEN: i = 3; break;
    case CAM_EFFECT_ENC_SEPIABLUE:  i = 4; break;
    case CAM_EFFECT_ENC_COLORINV:   i = 5; break;
    case CAM_EFFECT_ENC_GRAYINV:    i = 6; break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    CamWriteCmosSensor(0x2D, 0x0A); /* debug_mode1 */
    CamWriteCmosSensor(0x73, 0x00); /* EEINTP mode2 */
    CamWriteCmosSensor(0x23, Data[i][0]); /* special effect */
    CamWriteCmosSensor(0x77, Data[i][1]); /* edge effect */
    CamWriteCmosSensor(0xB3, Data[i][2]); /* luma contrast */
    CamWriteCmosSensor(0xBA, Data[i][3]); /* fixed Cb */
    CamWriteCmosSensor(0xBB, Data[i][4]); /* fixed Cr */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0308StillCaptureSize
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
MM_ERROR_CODE_ENUM GC0308StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*    GC0308Banding
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
static MM_ERROR_CODE_ENUM GC0308Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    GC0308SetBaseShutter(CAM_BANDING_50HZ == In->FeatureSetValue ? GC0308_NUM_50HZ : GC0308_NUM_60HZ);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0308SceneMode
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
static MM_ERROR_CODE_ENUM GC0308SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*    GC0308NightMode
*
* DESCRIPTION
*    This function set night mode to sensor.
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
static void GC0308NightMode(kal_bool Enable)
{
  kal_uint8 Offset;
  
  if (Enable)
  {
    Offset = 8;
    CamWriteCmosSensor(0x20, 0xDF); /* close CC */
  }
  else
  {
    Offset = 2;
    CamWriteCmosSensor(0x20, 0xFF); /* enable CC */
  }
  CamWriteCmosSensor(0x3C, Offset); /* manual G1 offset */
  CamWriteCmosSensor(0x3D, Offset); /* manual R offset */
  CamWriteCmosSensor(0x3E, Offset); /* manual B offset */
  CamWriteCmosSensor(0x3F, Offset); /* manual G2 offset */
}

/*************************************************************************
* FUNCTION
*  GC0308GammaSelect
*
* DESCRIPTION
*  This function config the gamma curve fitting for  
*  different LCD performances.
*
* PARAMETERS
*  level: different gamma curves.
*         Typical level value is from 1 to 5 which 
*         means small level gamma to high level gamma.
*
* RETURNS
*  NONE
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0308GammaSelect(kal_uint8 level)
{
  static const GammaData[][17] =
  {
    {0x0B,0x16,0x29,0x3C,0x4F,0x5F,0x6F,0x8A,0x9F,0xB4,0xC6,0xD3,0xDD,0xE5,0xF1,0xFA,0xFF},
    {0x0E,0x1C,0x34,0x48,0x5A,0x6B,0x7B,0x95,0xAB,0xBF,0xCE,0xD9,0xE4,0xEC,0xF7,0xFD,0xFF},
    {0x10,0x20,0x38,0x4E,0x63,0x76,0x87,0xA2,0xB8,0xCA,0xD8,0xE3,0xEB,0xF0,0xF8,0xFD,0xFF},
    {0x14,0x28,0x44,0x5D,0x72,0x86,0x95,0xB1,0xC6,0xD5,0xE1,0xEA,0xF1,0xF5,0xFB,0xFE,0xFF},
    {0x15,0x2A,0x4A,0x67,0x79,0x8C,0x9A,0xB3,0xC5,0xD5,0xDF,0xE8,0xEE,0xF3,0xFA,0xFD,0xFF},
  };
  
  if (level >= sizeof(GammaData) / sizeof(GammaData[0]))
  {
    ASSERT(0);
  }
  CamWriteCmosSensor(0x9F, GammaData[level][0]); 
  CamWriteCmosSensor(0xA0, GammaData[level][1]); 
  CamWriteCmosSensor(0xA1, GammaData[level][2]); 
  CamWriteCmosSensor(0xA2, GammaData[level][3]); 
  CamWriteCmosSensor(0xA3, GammaData[level][4]); 
  CamWriteCmosSensor(0xA4, GammaData[level][5]); 
  CamWriteCmosSensor(0xA5, GammaData[level][6]); 
  CamWriteCmosSensor(0xA6, GammaData[level][7]); 
  CamWriteCmosSensor(0xA7, GammaData[level][8]); 
  CamWriteCmosSensor(0xA8, GammaData[level][9]); 
  CamWriteCmosSensor(0xA9, GammaData[level][10]); 
  CamWriteCmosSensor(0xAA, GammaData[level][11]); 
  CamWriteCmosSensor(0xAB, GammaData[level][12]); 
  CamWriteCmosSensor(0xAC, GammaData[level][13]); 
  CamWriteCmosSensor(0xAD, GammaData[level][14]); 
  CamWriteCmosSensor(0xAE, GammaData[level][15]); 
  CamWriteCmosSensor(0xAF, GammaData[level][16]);
}

/*************************************************************************
* FUNCTION
*    GC0308InitialSetting
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
static void GC0308InitialSetting(void)
{
  CamWriteCmosSensor(0xfe, 0x80); /* reset */
  
  CamWriteCmosSensor(0xfe, 0x00); /* set page0 */
  CamWriteCmosSensor(0xd2, 0x10); /* close AEC */
  CamWriteCmosSensor(0x22, 0x55); /* close AWB */
  CamWriteCmosSensor(0x5a, 0x56);
  CamWriteCmosSensor(0x5b, 0x40);
  CamWriteCmosSensor(0x5c, 0x4a);
  CamWriteCmosSensor(0x22, 0x57); /* open AWB */
  CamWriteCmosSensor(0x01, 0xfa);
  CamWriteCmosSensor(0x02, 0x70);
  CamWriteCmosSensor(0x0f, 0x01);
  CamWriteCmosSensor(0x03, 0x01);
  CamWriteCmosSensor(0x04, 0x2c);
  CamWriteCmosSensor(0xe2, 0x00); /* anti-flicker step [11:8] */
  CamWriteCmosSensor(0xe3, 0x64); /* anti-flicker step [7:0] */
  CamWriteCmosSensor(0xe4, 0x02); /* exp level 1  16.67fps */
  CamWriteCmosSensor(0xe5, 0x58);
  CamWriteCmosSensor(0xe6, 0x03); /* exp level 2  12.5fps */
  CamWriteCmosSensor(0xe7, 0x20);
  CamWriteCmosSensor(0xe8, 0x04); /* exp level 3  8.33fps */
  CamWriteCmosSensor(0xe9, 0xb0);
  CamWriteCmosSensor(0xea, 0x09); /* exp level 4  4.00fps */
  CamWriteCmosSensor(0xeb, 0xc4);
  CamWriteCmosSensor(0x05, 0x00);
  CamWriteCmosSensor(0x06, 0x00);
  CamWriteCmosSensor(0x07, 0x00);
  CamWriteCmosSensor(0x08, 0x00);
  CamWriteCmosSensor(0x09, 0x01);
  CamWriteCmosSensor(0x0a, 0xe8);
  CamWriteCmosSensor(0x0b, 0x02);
  CamWriteCmosSensor(0x0c, 0x88);
  CamWriteCmosSensor(0x0d, 0x02);
  CamWriteCmosSensor(0x0e, 0x02);
  CamWriteCmosSensor(0x10, 0x22);
  CamWriteCmosSensor(0x11, 0xfd);
  CamWriteCmosSensor(0x12, 0x2a);
  CamWriteCmosSensor(0x13, 0x00);
  CamWriteCmosSensor(0x15, 0x0a);
  CamWriteCmosSensor(0x16, 0x05);
  CamWriteCmosSensor(0x17, 0x01);
  CamWriteCmosSensor(0x18, 0x44);
  CamWriteCmosSensor(0x19, 0x44);
  CamWriteCmosSensor(0x1a, 0x1e);
  CamWriteCmosSensor(0x1b, 0x00);
  CamWriteCmosSensor(0x1c, 0xc1);
  CamWriteCmosSensor(0x1d, 0x08);
  CamWriteCmosSensor(0x1e, 0x60);
  CamWriteCmosSensor(0x1f, 0x15); /* driving current */
  CamWriteCmosSensor(0x20, 0xff);
  CamWriteCmosSensor(0x21, 0xf8);
  CamWriteCmosSensor(0x22, 0x57);
  CamWriteCmosSensor(0x24, 0xa0);
  CamWriteCmosSensor(0x25, 0x0f);
  
  /* output sync_mode */
  CamWriteCmosSensor(0x26, 0x03);
  CamWriteCmosSensor(0x2f, 0x01);
  CamWriteCmosSensor(0x30, 0xf7);
  CamWriteCmosSensor(0x31, 0x50);
  CamWriteCmosSensor(0x32, 0x00);
  CamWriteCmosSensor(0x39, 0x04);
  CamWriteCmosSensor(0x3a, 0x18);
  CamWriteCmosSensor(0x3b, 0x20);
  CamWriteCmosSensor(0x3c, 0x00);
  CamWriteCmosSensor(0x3d, 0x00);
  CamWriteCmosSensor(0x3e, 0x00);
  CamWriteCmosSensor(0x3f, 0x00);
  CamWriteCmosSensor(0x50, 0x10);
  CamWriteCmosSensor(0x53, 0x82);
  CamWriteCmosSensor(0x54, 0x80);
  CamWriteCmosSensor(0x55, 0x80);
  CamWriteCmosSensor(0x56, 0x82);
  CamWriteCmosSensor(0x8b, 0x40);
  CamWriteCmosSensor(0x8c, 0x40);
  CamWriteCmosSensor(0x8d, 0x40);
  CamWriteCmosSensor(0x8e, 0x2e);
  CamWriteCmosSensor(0x8f, 0x2e);
  CamWriteCmosSensor(0x90, 0x2e);
  CamWriteCmosSensor(0x91, 0x3c);
  CamWriteCmosSensor(0x92, 0x50);
  CamWriteCmosSensor(0x5d, 0x12);
  CamWriteCmosSensor(0x5e, 0x1a);
  CamWriteCmosSensor(0x5f, 0x24);
  CamWriteCmosSensor(0x60, 0x07);
  CamWriteCmosSensor(0x61, 0x15);
  CamWriteCmosSensor(0x62, 0x08);
  CamWriteCmosSensor(0x64, 0x03);
  CamWriteCmosSensor(0x66, 0xe8);
  CamWriteCmosSensor(0x67, 0x86);
  CamWriteCmosSensor(0x68, 0xa2);
  CamWriteCmosSensor(0x69, 0x18);
  CamWriteCmosSensor(0x6a, 0x0f);
  CamWriteCmosSensor(0x6b, 0x00);
  CamWriteCmosSensor(0x6c, 0x5f);
  CamWriteCmosSensor(0x6d, 0x8f);
  CamWriteCmosSensor(0x6e, 0x55);
  CamWriteCmosSensor(0x6f, 0x38);
  CamWriteCmosSensor(0x70, 0x15);
  CamWriteCmosSensor(0x71, 0x33);
  CamWriteCmosSensor(0x72, 0xdc);
  CamWriteCmosSensor(0x73, 0x80);
  CamWriteCmosSensor(0x74, 0x02);
  CamWriteCmosSensor(0x75, 0x3f);
  CamWriteCmosSensor(0x76, 0x02);
  CamWriteCmosSensor(0x77, 0x36);
  CamWriteCmosSensor(0x78, 0x88);
  CamWriteCmosSensor(0x79, 0x81);
  CamWriteCmosSensor(0x7a, 0x81);
  CamWriteCmosSensor(0x7b, 0x22);
  CamWriteCmosSensor(0x7c, 0xff);
  CamWriteCmosSensor(0x93, 0x48);
  CamWriteCmosSensor(0x94, 0x00);
  CamWriteCmosSensor(0x95, 0x05);
  CamWriteCmosSensor(0x96, 0xe8);
  CamWriteCmosSensor(0x97, 0x40);
  CamWriteCmosSensor(0x98, 0xf0);
  CamWriteCmosSensor(0xb1, 0x38);
  CamWriteCmosSensor(0xb2, 0x38);
  CamWriteCmosSensor(0xbd, 0x38);
  CamWriteCmosSensor(0xbe, 0x36);
  CamWriteCmosSensor(0xd0, 0xc9);
  CamWriteCmosSensor(0xd1, 0x10);
  CamWriteCmosSensor(0xd3, 0x80);
  CamWriteCmosSensor(0xd5, 0xf2);
  CamWriteCmosSensor(0xd6, 0x16);
  CamWriteCmosSensor(0xdb, 0x92);
  CamWriteCmosSensor(0xdc, 0xa5);
  CamWriteCmosSensor(0xdf, 0x23);
  CamWriteCmosSensor(0xd9, 0x00);
  CamWriteCmosSensor(0xda, 0x00);
  CamWriteCmosSensor(0xe0, 0x09);
  CamWriteCmosSensor(0xec, 0x20);
  CamWriteCmosSensor(0xed, 0x04);
  CamWriteCmosSensor(0xee, 0xa0);
  CamWriteCmosSensor(0xef, 0x40);
  CamWriteCmosSensor(0x80, 0x03);
  CamWriteCmosSensor(0x80, 0x03);
  CamWriteCmosSensor(0x9F, 0x10);
  CamWriteCmosSensor(0xA0, 0x20);
  CamWriteCmosSensor(0xA1, 0x38);
  CamWriteCmosSensor(0xA2, 0x4E);
  CamWriteCmosSensor(0xA3, 0x63);
  CamWriteCmosSensor(0xA4, 0x76);
  CamWriteCmosSensor(0xA5, 0x87);
  CamWriteCmosSensor(0xA6, 0xA2);
  CamWriteCmosSensor(0xA7, 0xB8);
  CamWriteCmosSensor(0xA8, 0xCA);
  CamWriteCmosSensor(0xA9, 0xD8);
  CamWriteCmosSensor(0xAA, 0xE3);
  CamWriteCmosSensor(0xAB, 0xEB);
  CamWriteCmosSensor(0xAC, 0xF0);
  CamWriteCmosSensor(0xAD, 0xF8);
  CamWriteCmosSensor(0xAE, 0xFD);
  CamWriteCmosSensor(0xAF, 0xFF);
  CamWriteCmosSensor(0xc0, 0x00);
  CamWriteCmosSensor(0xc1, 0x10);
  CamWriteCmosSensor(0xc2, 0x1C);
  CamWriteCmosSensor(0xc3, 0x30);
  CamWriteCmosSensor(0xc4, 0x43);
  CamWriteCmosSensor(0xc5, 0x54);
  CamWriteCmosSensor(0xc6, 0x65);
  CamWriteCmosSensor(0xc7, 0x75);
  CamWriteCmosSensor(0xc8, 0x93);
  CamWriteCmosSensor(0xc9, 0xB0);
  CamWriteCmosSensor(0xca, 0xCB);
  CamWriteCmosSensor(0xcb, 0xE6);
  CamWriteCmosSensor(0xcc, 0xFF);
  CamWriteCmosSensor(0xf0, 0x02);
  CamWriteCmosSensor(0xf1, 0x01);
  CamWriteCmosSensor(0xf2, 0x03);
  CamWriteCmosSensor(0xf3, 0x30);
  CamWriteCmosSensor(0xf9, 0x9f);
  CamWriteCmosSensor(0xfa, 0x78);
  
  CamWriteCmosSensor(0xfe, 0x01); /* set page1 */
  CamWriteCmosSensor(0x00, 0xf5);
  CamWriteCmosSensor(0x02, 0x1a);
  CamWriteCmosSensor(0x0a, 0xa0);
  CamWriteCmosSensor(0x0b, 0x60);
  CamWriteCmosSensor(0x0c, 0x08);
  CamWriteCmosSensor(0x0e, 0x4c);
  CamWriteCmosSensor(0x0f, 0x39);
  CamWriteCmosSensor(0x11, 0x3f);
  CamWriteCmosSensor(0x12, 0x72);
  CamWriteCmosSensor(0x13, 0x13);
  CamWriteCmosSensor(0x14, 0x42);
  CamWriteCmosSensor(0x15, 0x43);
  CamWriteCmosSensor(0x16, 0xc2);
  CamWriteCmosSensor(0x17, 0xa8);
  CamWriteCmosSensor(0x18, 0x18);
  CamWriteCmosSensor(0x19, 0x40);
  CamWriteCmosSensor(0x1a, 0xd0);
  CamWriteCmosSensor(0x1b, 0xf5);
  CamWriteCmosSensor(0x70, 0x40);
  CamWriteCmosSensor(0x71, 0x58);
  CamWriteCmosSensor(0x72, 0x30);
  CamWriteCmosSensor(0x73, 0x48);
  CamWriteCmosSensor(0x74, 0x20);
  CamWriteCmosSensor(0x75, 0x60);
  CamWriteCmosSensor(0x77, 0x20);
  CamWriteCmosSensor(0x78, 0x32);
  CamWriteCmosSensor(0x30, 0x03);
  CamWriteCmosSensor(0x31, 0x40);
  CamWriteCmosSensor(0x32, 0xe0);
  CamWriteCmosSensor(0x33, 0xe0);
  CamWriteCmosSensor(0x34, 0xe0);
  CamWriteCmosSensor(0x35, 0xb0);
  CamWriteCmosSensor(0x36, 0xc0);
  CamWriteCmosSensor(0x37, 0xc0);
  CamWriteCmosSensor(0x38, 0x04);
  CamWriteCmosSensor(0x39, 0x09);
  CamWriteCmosSensor(0x3a, 0x12);
  CamWriteCmosSensor(0x3b, 0x1C);
  CamWriteCmosSensor(0x3c, 0x28);
  CamWriteCmosSensor(0x3d, 0x31);
  CamWriteCmosSensor(0x3e, 0x44);
  CamWriteCmosSensor(0x3f, 0x57);
  CamWriteCmosSensor(0x40, 0x6C);
  CamWriteCmosSensor(0x41, 0x81);
  CamWriteCmosSensor(0x42, 0x94);
  CamWriteCmosSensor(0x43, 0xA7);
  CamWriteCmosSensor(0x44, 0xB8);
  CamWriteCmosSensor(0x45, 0xD6);
  CamWriteCmosSensor(0x46, 0xEE);
  CamWriteCmosSensor(0x47, 0x0d); 
  
  CamWriteCmosSensor(0xfe, 0x00); /* set page0 */
  CamWriteCmosSensor(0xd2, 0x90); /* open AEC at last */
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
#endif
  GC0308GammaSelect(2);
  
  CamWriteCmosSensor(0xb3, 0x38);
  CamWriteCmosSensor(0x64, 0x01);
  CamWriteCmosSensor(0x77, 0x33);
  CamWriteCmosSensor(0xd0, 0xcb);
  CamWriteCmosSensor(0xd3, 0x50);
}

/*************************************************************************
* FUNCTION
*    GC0308GetSensorInfo
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
static void GC0308GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = GC0308_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_HIGH;
  Info->PreviewMclkFreq = GC0308_MCLK;
  Info->CaptureMclkFreq = GC0308_MCLK;
  Info->VideoMclkFreq = GC0308_MCLK;
  Info->PreviewWidth = GC0308_IMAGE_SENSOR_WIDTH_DRV;
  Info->PreviewHeight = GC0308_IMAGE_SENSOR_HEIGHT_DRV;
  Info->FullWidth = GC0308_IMAGE_SENSOR_WIDTH_DRV;
  Info->FullHeight = GC0308_IMAGE_SENSOR_HEIGHT_DRV;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    GC0308PowerOn
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
static kal_uint8 GC0308PowerOn(void)
{
  kal_uint8 SensorId;
  
  CisModulePowerOn(GC0308Sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, GC0308_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);
  CamPdnPinCtrl(GC0308Sensor.SensorIdx, 0);
  
  CamRstPinCtrl(GC0308Sensor.SensorIdx, 1);
  kal_sleep_task(1);
  CamRstPinCtrl(GC0308Sensor.SensorIdx, 0);
  kal_sleep_task(1);
  CamRstPinCtrl(GC0308Sensor.SensorIdx, 1);
  kal_sleep_task(3);
  
  SensorId = CamReadCmosSensor(0x00);
  if (SensorId != GC0308_SENSOR_ID) /* READ SENSOR ID */
  {
#if defined(__GC0308_DEBUG_TRACE__)
    kal_print_string_trace(MOD_ENG, TRACE_ERROR, "SENSOR ID: %x", SensorId);
#endif
  }
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    GC0308DetectSensorId
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
static kal_uint32 GC0308DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM GC0308SensorClose(void);
  kal_uint8 SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (GC0308Sensor.SensorIdx)
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
      SensorId = GC0308PowerOn();
      GC0308SensorClose();
      if (GC0308_SENSOR_ID == SensorId)
      {
        return GC0308_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    GC0308InitOperationPara
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
static void GC0308InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 0;
  Para->PreviewDelayFrame = 0;
  Para->PreviewDisplayWaitFrame = 8;
}

/*************************************************************************
* FUNCTION
*    GC0308Preview
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
static void GC0308Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint16 DummyPixel;
  
  GC0308SetMirror(In->ImageMirror);
  GC0308SetClock(GC0308_PREVIEW_CLK);
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    GC0308Sensor.VideoFps = GC0308SetVideoFps(In->MaxVideoFrameRate);
    break;
  default:
    DummyPixel = 0;
    GC0308SetDummy(DummyPixel, 0);
    GC0308SetMinFps(In->NightMode ? GC0308_FPS(5) : GC0308_FPS(10));
  }
  GC0308SetBaseShutter(CAM_BANDING_50HZ == In->BandingFreq ? GC0308_NUM_50HZ : GC0308_NUM_60HZ);
  GC0308NightMode(In->NightMode);
  GC0308AeEnable(KAL_TRUE);
  GC0308AwbEnable(KAL_TRUE);
  
  Out->WaitStableFrameNum = 0;
  Out->GrabStartX = GC0308_X_START;
  Out->GrabStartY = GC0308_Y_START;
  Out->ExposureWindowWidth = GC0308_IMAGE_SENSOR_WIDTH;
  Out->ExposureWindowHeight = GC0308_IMAGE_SENSOR_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    GC0308Capture
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
static void GC0308Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  Out->WaitStableFrameNum = 0;
  Out->GrabStartX = GC0308_X_START;
  Out->GrabStartY = GC0308_Y_START;
  Out->ExposureWindowWidth = GC0308_IMAGE_SENSOR_WIDTH;
  Out->ExposureWindowHeight = GC0308_IMAGE_SENSOR_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    GC0308SensorOpen
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
static MM_ERROR_CODE_ENUM GC0308SensorOpen(void)
{
  if (GC0308PowerOn() != GC0308_SENSOR_ID)
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  GC0308InitialSetting();
  
  /* default setting */
  GC0308Sensor.BypassAe = KAL_FALSE;
  GC0308Sensor.BypassAwb = KAL_FALSE;
  GC0308Sensor.Ctrl3A = CamReadCmosSensor(0x22);
  GC0308Sensor.AecMode3 = CamReadCmosSensor(0xD2);
  GC0308Sensor.VideoFps = 0;
  GC0308Sensor.IntClk = 0;
  GC0308Sensor.FrameHeight = 0;
  GC0308Sensor.LineLength = 0;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0308SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM GC0308SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return GC0308WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
  /* query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = GC0308Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = GC0308Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = GC0308Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = GC0308StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
    ErrCode = GC0308Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = GC0308SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = GC0308SceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    GC0308GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GC0308DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GC0308Sensor.VideoFps;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    GC0308InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(GC0308Sensor.SensorIdx, Out);
    break;
  
  /* set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(GC0308Sensor.SensorIdx, 1);
    CamRstPinCtrl(GC0308Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    GC0308Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    GC0308Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    GC0308Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    GC0308AeEnable(GC0308Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    GC0308Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    GC0308AwbEnable(GC0308Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    GC0308SensorCtrl
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
static MM_ERROR_CODE_ENUM GC0308SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    GC0308Preview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    GC0308Capture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0308SensorClose
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
static MM_ERROR_CODE_ENUM GC0308SensorClose(void)
{
  CamPdnPinCtrl(GC0308Sensor.SensorIdx, 1);
  CamRstPinCtrl(GC0308Sensor.SensorIdx, 0);
  CisModulePowerOn(GC0308Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GC0308SensorFunc
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
MM_ERROR_CODE_ENUM GC0308SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncGC0308 =
  {
    GC0308SensorOpen,
    GC0308SensorFeatureCtrl,
    GC0308SensorCtrl,
    GC0308SensorClose,
  };
  *pfSensorFunc = &ImageSensorFuncGC0308;
  
  return MM_ERROR_NONE;
}

