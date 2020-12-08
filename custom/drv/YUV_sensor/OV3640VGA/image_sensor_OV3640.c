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
 *   image_sensor_OV3640.c
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

/* #define __OV3640_DEBUG_TRACE__ */
/* #define __OV3640_TEST_PATTERN__ */

static struct
{
  kal_uint16 Contrast;
  kal_uint16 Effect;
  kal_uint16 Exposure;
  kal_uint16 Wb;
  kal_uint8 Mirror;
  kal_bool BypassAe;
  kal_bool BypassAwb;
  kal_bool NightMode;
  kal_bool VideoMode;
  kal_bool PvMode;
  kal_uint8 AutoCtrl1;
  kal_uint8 AutoCtrl2;
  kal_uint8 AutoCtrl3;
  kal_uint8 DspCtrl;
  kal_uint8 SdeCtrl;
  kal_uint16 Fps;
  kal_uint32 SysClk;
  kal_uint16 Gain; /* base on 0x40 */
  kal_uint16 Shutter;
  kal_uint16 FrameHeight;
  kal_uint16 LineLength;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} OV3640Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    OV3640HalfAdjust
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
__inline static kal_uint32 OV3640HalfAdjust(kal_uint32 DividEnd, kal_uint32 Divisor)
{
  return (DividEnd + (Divisor >> 1)) / Divisor; /* that is [DividEnd / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    OV3640SetMirror
*
* DESCRIPTION
*    This function set the mirror to the CMOS sensor
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
static void OV3640SetMirror(kal_uint8 Mirror)
{
  kal_uint8 reg = 0x10, reg1 = 0xC0;
  
  if (OV3640Sensor.Mirror == Mirror)
  {
    return;
  }
  OV3640Sensor.Mirror = Mirror;
  switch (OV3640Sensor.Mirror)
  {
  case IMAGE_SENSOR_MIRROR_H:
    reg |= 0x02;
    reg1 |= 0x08;
    break;
  case IMAGE_SENSOR_MIRROR_V:
    reg |= 0x01;
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    reg |= 0x03;
    reg1 |= 0x08;
    break;
  }
  CamWriteCmosSensor(0x307C, reg);
  /* To mirror the Array, or there is horizontal lines when turn on mirror. */
  CamWriteCmosSensor(0x3090, reg1);
}

/*************************************************************************
* FUNCTION
*    OV3640SetClock
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
static void OV3640SetClock(kal_uint32 Clk)
{
  static const kal_uint8 ClkSetting[][3] =
  {
    {0x33,0x00,0x83}, /* MCLK: 26M, SYS CLK: 56.3M, PCLK: 37.5M for preview */
    {0x38,0x00,0x82}, /* MCLK: 26M, SYS CLK: 34.7M, PCLK: 34.6M for preview */
    {0x35,0x00,0x81}, /* MCLK: 26M, SYS CLK: 47.7M, PCLK: 95.3M for capture */
    {0x39,0x00,0x81}, /* MCLK: 26M, SYS CLK: 30.3M, PCLK: 60.7M for capture */
    {0x35,0x01,0x81}, /* MCLK: 26M, SYS CLK: 23.8M, PCLK: 47.7M for capture */
    {0x39,0x01,0x81}, /* MCLK: 26M, SYS CLK: 15.2M, PCLK: 30.3M for capture */
  };
  kal_uint8 i = 0;
  
  if (OV3640Sensor.SysClk == Clk)
  {
    return;
  }
  OV3640Sensor.SysClk = Clk;
  switch (OV3640Sensor.SysClk)
  {
  case 56333333: i = 0; break;
  case 34666667: i = 1; break;
  case 47666667: i = 2; break;
  case 30333333: i = 3; break;
  case 23833333: i = 4; break;
  case 15166666: i = 5; break;
  default: ASSERT(0);
  }
/* PLL MY_OUTPUT clock(fclk)
   fclk = (0x40 - 0x300E[5:0]) x N x Bit8Div x MCLK / M, where fclk < 1GHz
      N = 1, 1.5, 2, 3 for 0x300F[7:6] = 0~3, respectively
      M = 1, 1.5, 2, 3 for 0x300F[1:0] = 0~3, respectively
      Bit8Div = 1, 1, 4, 5 for 0x300F[5:4] = 0~3, respectively
   Sys Clk = fclk / Bit8Div / SenDiv
   Sensor MY_OUTPUT clock(DVP PCLK)
   DVP PCLK = ISP CLK / DVPDiv, where
   ISP CLK =  fclk / Bit8Div / SenDiv / CLKDiv / 2, where
      Bit8Div = 1, 1, 4, 5 for 0x300F[5:4] = 0~3, respectively
      SenDiv = 1, 2 for 0x3010[4] = 0 or 1 repectively
      CLKDiv = (0x3011[5:0] + 1)
      DVPDiv = 0x304C[3:0] * (2 ^ 0x304C[4]), if 0x304C[3:0] = 0, use 16 instead
*/
  CamWriteCmosSensor(0x300E, ClkSetting[i][0]);
  CamWriteCmosSensor(0x3011, ClkSetting[i][1]);
  CamWriteCmosSensor(0x304C, ClkSetting[i][2]);
}

/*************************************************************************
* FUNCTION
*    OV3640WriteShutter
*
* DESCRIPTION
*    This function apply shutter to sensor
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
static void OV3640WriteShutter(kal_uint32 Shutter)
{
  const kal_uint16 ShutterLimit = OV3640Sensor.FrameHeight - OV3640_SHUTTER_MAX_MARGIN;
  kal_uint16 ExtraShutter = 0;
  
  if (Shutter > ShutterLimit)
  {
    ExtraShutter = Shutter - ShutterLimit;
    Shutter = ShutterLimit;
  }
  CamWriteCmosSensor(0x302D, ExtraShutter >> 8); /* AEC VTS output */
  CamWriteCmosSensor(0x302E, ExtraShutter);
  CamWriteCmosSensor(0x3002, Shutter >> 8); /* Shutter */
  CamWriteCmosSensor(0x3003, Shutter);
}

/*************************************************************************
* FUNCTION
*    OV3640ReadShutter
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
static kal_uint16 OV3640ReadShutter(void)
{
  kal_uint16 Shutter = (CamReadCmosSensor(0x3002) << 8)|CamReadCmosSensor(0x3003);
  
  Shutter += ((CamReadCmosSensor(0x302D) << 8)|CamReadCmosSensor(0x302E)); /* extra shutter */
  
  return Shutter;
}

/*************************************************************************
* FUNCTION
*    OV3640WriteGain
*
* DESCRIPTION
*    This function apply gain to sensor
*
* PARAMETERS
*    Gain: base on 0x40
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3640WriteGain(kal_uint16 Gain)
{
  kal_uint8 Reg = 0;
  
  if (Gain > 32 * 0x40 - 0x04) /* max 31.0.9375x */
  {
    ASSERT(0);
  }
  while (Gain >= 0x40 * 2)
  {
    Reg <<= 1;
    Reg |= 0x01;
    Gain >>= 1;
  }
  Reg <<= 4;
  if (Gain >= 0x40)
  {
    Reg |= ((Gain - 0x40) >> 2);
  }
  CamWriteCmosSensor(0x3001, Reg);
}

/*************************************************************************
* FUNCTION
*    OV3640ReadGain
*
* DESCRIPTION
*    This function get gain from sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    Gain: base on 0x40
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 OV3640ReadGain(void)
{
  const kal_uint8 Reg = CamReadCmosSensor(0x3001);
  
  return (((Reg&0x0F) << 2) + 0x40) * (1 + (Reg >> 4));
}

/*************************************************************************
* FUNCTION
*    OV3640LSCSetting
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
static void OV3640LSCSetting(void)
{
  /* R Gain */
  CamWriteCmosSensor(0x3367, 0x33);
  CamWriteCmosSensor(0x3368, 0xD1);
  CamWriteCmosSensor(0x3369, 0x29);
  CamWriteCmosSensor(0x336a, 0x5A);
  CamWriteCmosSensor(0x336b, 0xF7);
  CamWriteCmosSensor(0x336c, 0x00);
  
  /* G Gain */
  CamWriteCmosSensor(0x336d, 0x33);
  CamWriteCmosSensor(0x336e, 0xD8);
  CamWriteCmosSensor(0x336f, 0x30);
  CamWriteCmosSensor(0x3370, 0x51);
  CamWriteCmosSensor(0x3371, 0xF7);
  CamWriteCmosSensor(0x3372, 0x00);

  /* B Gain */
  CamWriteCmosSensor(0x3373, 0x33);
  CamWriteCmosSensor(0x3374, 0xC9);
  CamWriteCmosSensor(0x3375, 0x24);
  CamWriteCmosSensor(0x3376, 0x4D);
  CamWriteCmosSensor(0x3377, 0xF7);
  CamWriteCmosSensor(0x3378, 0x00);
}

/*************************************************************************
* FUNCTION
*    OV3640UvadjustSetting
*
* DESCRIPTION
*    This function set different mode UV adjust.
*
* PARAMETERS
*    Mode
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3640UvadjustSetting(kal_uint8 Mode)
{
  static const kal_uint8 Data[][4] =
  {
    {0x28,0x15,0x03,0x07},
    {0x19,0x0C,0x03,0x0F},
  };
  
  CamWriteCmosSensor(0x30b8, Data[Mode][0]);
  CamWriteCmosSensor(0x30b9, Data[Mode][1]);
  CamWriteCmosSensor(0x30ba, Data[Mode][2]);
  CamWriteCmosSensor(0x30bb, Data[Mode][3]);
}

#ifdef OV3640_GAIN2SHUTTER
/*************************************************************************
* FUNCTION
*    OV3640UvadjustCtrl
*
* DESCRIPTION
*    This function disable/enable uv adjust
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
static void OV3640UvadjustCtrl(kal_bool Enable)
{
  static kal_uint8 DspCtrl, SdeCtrl, uSat, vSat; /* back up value */
  
  if (Enable)
  {
    if (DspCtrl&0x40)
    {
      /* recover setting */
      CamWriteCmosSensor(0x3358, uSat);
      CamWriteCmosSensor(0x3359, vSat);
      if (!(SdeCtrl&0x02))
      {
        OV3640Sensor.SdeCtrl &= 0xFD;
        CamWriteCmosSensor(0x3355, OV3640Sensor.SdeCtrl);
      }
      OV3640Sensor.DspCtrl |= 0x40;
      CamWriteCmosSensor(0x3302, OV3640Sensor.DspCtrl); /* Enable uv adjust */
      DspCtrl = SdeCtrl = 0x00;
    }
  }
  else
  {
    DspCtrl = OV3640Sensor.DspCtrl;
    if (OV3640Sensor.DspCtrl&0x40)
    {
      kal_uint8 uvvalue;
      
      /* change saturation when diable uv adjust */
      uSat = CamReadCmosSensor(0x3358);
      vSat = CamReadCmosSensor(0x3359);
      
      /* enable saturation */
      SdeCtrl = OV3640Sensor.SdeCtrl;
      if (!(OV3640Sensor.SdeCtrl&0x02))
      {
        OV3640Sensor.SdeCtrl |= 0x02;
        CamWriteCmosSensor(0x3355, OV3640Sensor.SdeCtrl);
      }
      
      /* read uv adjust position */
      CamWriteCmosSensor(0x33A0, 0x35); /* set index */
      uvvalue = CamReadCmosSensor(0x33CA)&0x1F;
      
      /* uv value transfer to saturation value */
      CamWriteCmosSensor(0x3358, uvvalue * uSat / 0x1F);
      CamWriteCmosSensor(0x3359, uvvalue * vSat / 0x1F);
      
      /* diable uv adjust */
      OV3640Sensor.DspCtrl &= 0xBF;
      CamWriteCmosSensor(0x3302, OV3640Sensor.DspCtrl);
    }
  }
}
#endif

/*************************************************************************
* FUNCTION
*    OV3640AeEnable
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
static void OV3640AeEnable(kal_bool Enable)
{
  const kal_bool AeEnable = (OV3640Sensor.AutoCtrl1&0x05) ? KAL_TRUE : KAL_FALSE;
  
  if (OV3640Sensor.BypassAe && OV3640Sensor.PvMode)
  {
    Enable = KAL_FALSE;
  }
  if (AeEnable == Enable)
  {
    return;
  }
  if (Enable)
  {
    OV3640Sensor.AutoCtrl1 |= 0x05;
    OV3640Sensor.AutoCtrl2 |= 0x08;
  }
  else
  {
    OV3640Sensor.AutoCtrl1 &= 0xFA;
    /* extra line can not be set if not fix frame rate!!! */
    OV3640Sensor.AutoCtrl2 &= 0xF7;
  }
  CamWriteCmosSensor(0x3013, OV3640Sensor.AutoCtrl1); /* AEC/AGC on/off */
  CamWriteCmosSensor(0x3014, OV3640Sensor.AutoCtrl2);
}

/*************************************************************************
* FUNCTION
*    OV3640AwbEnable
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
static void OV3640AwbEnable(kal_bool Enable)
{
  const kal_bool AwbEnable = (OV3640Sensor.DspCtrl&0x01) ? KAL_TRUE : KAL_FALSE;
  
  if (OV3640Sensor.BypassAwb && OV3640Sensor.PvMode)
  {
    Enable = KAL_FALSE;
  }
  if (AwbEnable == Enable)
  {
    return;
  }
  if (Enable)
  {
    OV3640Sensor.DspCtrl |= 0x01;
  }
  else
  {
    OV3640Sensor.DspCtrl &= 0xFE;
  }
  CamWriteCmosSensor(0x3302, OV3640Sensor.DspCtrl);
}

/*************************************************************************
* FUNCTION
*    OV3640SetDummy
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
static void OV3640SetDummy(kal_uint16 DummyPixel, kal_uint16 DummyLine)
{
  kal_bool update = KAL_FALSE; /* need config banding */
  kal_uint16 LineLength, FrameHeight;
  
  if (OV3640Sensor.PvMode)
  {
    LineLength = DummyPixel + OV3640_PV_PERIOD_PIXEL_NUMS;
    FrameHeight = DummyLine + OV3640_PV_PERIOD_LINE_NUMS;
  }
  else
  {
    LineLength = DummyPixel + OV3640_FULL_PERIOD_PIXEL_NUMS;
    FrameHeight = DummyLine + OV3640_FULL_PERIOD_LINE_NUMS;
  }
  LineLength = (LineLength + 1)&0xFFFE; /* must be even, or image abnormal(blue) */
  /* config line length */
  if (LineLength != OV3640Sensor.LineLength)
  {
    update = KAL_TRUE;
    OV3640Sensor.LineLength = LineLength;
    if (LineLength > OV3640_MAX_LINELENGTH)
    {
      ASSERT(0);
    }
    CamWriteCmosSensor(0x3028, (LineLength - 1) >> 8); /* total HW */
    CamWriteCmosSensor(0x3029, LineLength - 1); /* -1 for register value start from 0 */
  }
  /* config frame height */
  if (FrameHeight != OV3640Sensor.FrameHeight)
  {
    /* limitation is 0xFFFF */
    update = KAL_TRUE;
    OV3640Sensor.FrameHeight = FrameHeight;
    CamWriteCmosSensor(0x302A, FrameHeight >> 8); /* total VH */
    CamWriteCmosSensor(0x302B, FrameHeight);
  }
  /* config banding */
  if (update && OV3640Sensor.PvMode)
  {
    kal_uint16 BandStep50, BandStep60;
    
    BandStep50 = OV3640HalfAdjust(OV3640Sensor.SysClk, LineLength * OV3640_NUM_50HZ * 2);
    BandStep60 = OV3640HalfAdjust(OV3640Sensor.SysClk, LineLength * OV3640_NUM_60HZ * 2);
    
    CamWriteCmosSensor(0x3070, BandStep50 >> 8); /* 50Hz banding step */
    CamWriteCmosSensor(0x3071, BandStep50);
    CamWriteCmosSensor(0x3072, BandStep60 >> 8); /* 60Hz banding step */
    CamWriteCmosSensor(0x3073, BandStep60);
    /* 50Hz max banding in a frame, -1 for register value start from 0 */
    CamWriteCmosSensor(0x301C, FrameHeight / BandStep50 - 1);
    /* 60Hz max banding in a frame, -1 for register value start from 0 */
    CamWriteCmosSensor(0x301D, FrameHeight / BandStep60 - 1);
  }
}

/*************************************************************************
* FUNCTION
*    OV3640CalFps
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
static void OV3640CalFps(void)
{
  if (OV3640Sensor.VideoMode) /* get max line length and fix frame rate when video mode */
  {
    kal_uint32 LineLength, FrameHeight;
    
    LineLength = OV3640Sensor.SysClk * OV3640_FPS(1) / (OV3640Sensor.Fps * OV3640Sensor.FrameHeight);
    if (LineLength > OV3640_MAX_LINELENGTH) /* overflow check */
    {
      OV3640SetClock(OV3640_VIDEO_LOW_CLK); /* slow down clock */
      LineLength = OV3640Sensor.SysClk * OV3640_FPS(1) / (OV3640Sensor.Fps * OV3640Sensor.FrameHeight);
      if (LineLength > OV3640_MAX_LINELENGTH) /* overflow check */
      {
        LineLength = OV3640_MAX_LINELENGTH;
      }
    }
    if (LineLength < OV3640Sensor.LineLength)
    {
      LineLength = OV3640Sensor.LineLength;
    }
    FrameHeight = OV3640Sensor.SysClk * OV3640_FPS(1) / (OV3640Sensor.Fps * LineLength);
    if (FrameHeight < OV3640Sensor.FrameHeight)
    {
      FrameHeight = OV3640Sensor.FrameHeight;
    }
    OV3640SetDummy(LineLength - OV3640_PV_PERIOD_PIXEL_NUMS, FrameHeight - OV3640_PV_PERIOD_LINE_NUMS);
    
    /* fix frame rate */
    OV3640Sensor.AutoCtrl2 &= 0xF7;
    CamWriteCmosSensor(0x3014, OV3640Sensor.AutoCtrl2);
    /* extra line can not auto be set to 0 when fix frame rate */
    CamWriteCmosSensor(0x302D, 0x00); /* AEC VTS output */
    CamWriteCmosSensor(0x302E, 0x00);
  }
  else
  {
    kal_uint16 CurFps;
    
    CurFps = OV3640HalfAdjust(OV3640Sensor.SysClk * OV3640_FPS(1),
                              OV3640Sensor.Fps * OV3640Sensor.LineLength * OV3640Sensor.FrameHeight);
    OV3640Sensor.AutoCtrl3 &= 0x8F;
    switch (CurFps)
    {
    case 0:
    case 1: break;
    case 2: OV3640Sensor.AutoCtrl3 |= 0x10; break;
    case 3: OV3640Sensor.AutoCtrl3 |= 0x20; break;
    case 4: OV3640Sensor.AutoCtrl3 |= 0x30; break;
    default: OV3640Sensor.AutoCtrl3 |= 0x40; break;
    }
    CamWriteCmosSensor(0x3015, OV3640Sensor.AutoCtrl3);
    if (!OV3640Sensor.NightMode)
    {
      /* to force frame rate change when change night mode to normal mode */
      OV3640Sensor.AutoCtrl2 &= 0xF7;
      CamWriteCmosSensor(0x3014, OV3640Sensor.AutoCtrl2);
    }
    OV3640Sensor.AutoCtrl2 |= 0x08;
    CamWriteCmosSensor(0x3014, OV3640Sensor.AutoCtrl2);
  }
}

/*************************************************************************
* FUNCTION
*    OV3640ConfigWindow
*
* DESCRIPTION
*    This function config output window
*
* PARAMETERS
*    PvMode: KAL_TRUE: switch to preview, use 2x1 binning, KAL_FALSE: switch to caputre
*    hactive: sensor output image width
*    vactive: sensor output image height
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3640ConfigWindow(kal_bool PvMode, kal_uint16 hactive, kal_uint16 vactive)
{
  const kal_uint16 zoom_out_hw = hactive + 8, zoom_out_vh = vactive + 4;
  kal_uint16 output_hs, output_vs, output_hw, output_vh; /* sensor array output */
  kal_uint16 avg_vh;
  
  /* config output window */
  if (PvMode)
  {
    output_hs = OV3640_IMAGE_SENSOR_PV_HSTART;
    output_vs = OV3640_IMAGE_SENSOR_PV_VSTART;
    output_hw = OV3640_IMAGE_SENSOR_PV_HACTIVE;
    output_vh = OV3640_IMAGE_SENSOR_PV_VACTIVE;
  }
  else
  {
    output_hs = OV3640_IMAGE_SENSOR_FULL_HSTART;
    output_vs = OV3640_IMAGE_SENSOR_FULL_VSTART;
    output_hw = OV3640_IMAGE_SENSOR_FULL_HACTIVE;
    output_vh = OV3640_IMAGE_SENSOR_FULL_VACTIVE;
  }
  avg_vh = (output_vh >> 2)&0xFFFC; /* align */
  CamWriteCmosSensor(0x3020, output_hs >> 8);
  CamWriteCmosSensor(0x3021, output_hs);
  CamWriteCmosSensor(0x3022, output_vs >> 8); /* output_vs must be even */
  CamWriteCmosSensor(0x3023, output_vs);
  CamWriteCmosSensor(0x3024, output_hw >> 8);
  CamWriteCmosSensor(0x3025, output_hw);
  CamWriteCmosSensor(0x3026, output_vh >> 8);
  CamWriteCmosSensor(0x3027, output_vh);
  CamWriteCmosSensor(0x303E, avg_vh >> 8); /* AVH: real value: reg value * 4 */
  CamWriteCmosSensor(0x303F, avg_vh);
  if (PvMode) output_hw >>= 1; /* pv binning mode */
  CamWriteCmosSensor(0x335F, ((output_vh >> 4)&0xF0)|((output_hw >> 8)&0x0F));
  CamWriteCmosSensor(0x3360, output_hw); /* zoom input hw */
  CamWriteCmosSensor(0x3361, output_vh); /* zoom input vh */
  CamWriteCmosSensor(0x3362, ((zoom_out_vh >> 4)&0xF0)|((zoom_out_hw >> 8)&0x0F));
  CamWriteCmosSensor(0x3363, zoom_out_hw); /* zoom output hw */
  CamWriteCmosSensor(0x3364, zoom_out_vh); /* zoom output vh */
  CamWriteCmosSensor(0x3088, hactive >> 8); /* output HW */
  CamWriteCmosSensor(0x3089, hactive);
  CamWriteCmosSensor(0x308A, vactive >> 8); /* output HW */
  CamWriteCmosSensor(0x308B, vactive);
}

/*************************************************************************
* FUNCTION
*    OV3640OutputWindow
*
* DESCRIPTION
*    This function config output window and set mode
*
* PARAMETERS
*    PvMode: KAL_TRUE: switch to preview, use 2x1 binning, KAL_FALSE: switch to caputre
*    hactive: sensor output image width
*    vactive: sensor output image height
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV3640OutputWindow(kal_bool PvMode, kal_uint16 hactive, kal_uint16 vactive)
{
  /* config capture/preview mode */
  if (OV3640Sensor.PvMode != PvMode)
  {
    OV3640Sensor.PvMode = PvMode;
    if (OV3640Sensor.PvMode)
    {
      CamWriteCmosSensor(0x3012, 0x10); /* sensor array size: 1024x768 */
      CamWriteCmosSensor(0x3366, 0x15);
      CamWriteCmosSensor(0x3075, 0x24); /* Vsync pulse width and start point */
      CamWriteCmosSensor(0x300D, 0x01); /* pclk output control */
      CamWriteCmosSensor(0x30D7, 0x90);
      CamWriteCmosSensor(0x3069, 0x04); /* BLC */
      OV3640Sensor.DspCtrl |= 0x20; /* enable scale */
    }
    else
    {
      CamWriteCmosSensor(0x3012, 0x00); /* sensor array size: 2048x1536 */
      CamWriteCmosSensor(0x3366, 0x10);
      CamWriteCmosSensor(0x3075, 0x44);
      CamWriteCmosSensor(0x300D, 0x00); /* pclk output control */
      CamWriteCmosSensor(0x30D7, 0x10);
      CamWriteCmosSensor(0x3069, 0x44);
      OV3640Sensor.DspCtrl &= 0xDF; /* disable scale */
    }
    CamWriteCmosSensor(0x3302, OV3640Sensor.DspCtrl);
    OV3640ConfigWindow(OV3640Sensor.PvMode, hactive, vactive);
  }
}

/*************************************************************************
* FUNCTION
*    OV3640NightMode
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
static void OV3640NightMode(kal_bool Enable)
{
  if (OV3640Sensor.NightMode == Enable && !OV3640Sensor.VideoMode)
  {
    return;
  }
  OV3640Sensor.NightMode = Enable;
  OV3640Sensor.AutoCtrl3 &= 0xF8;
  if (OV3640Sensor.NightMode)
  {
    OV3640Sensor.AutoCtrl3 |= 3; /* 16x digital gain */
    OV3640UvadjustSetting(1);
  }
  else
  {
    OV3640Sensor.AutoCtrl3 |= 2; /* 8x digital gain */
    OV3640UvadjustSetting(0);
  }
  CamWriteCmosSensor(0x3015, OV3640Sensor.AutoCtrl3);
  OV3640CalFps(); /* need cal new fps */
}

/*************************************************************************
* FUNCTION
*    OV3640SceneMode
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
static MM_ERROR_CODE_ENUM OV3640SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    OV3640NightMode(Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640Ev
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
static MM_ERROR_CODE_ENUM OV3640Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
      {0x09,0x20}, /* EV -4 */
      {0x09,0x18}, /* EV -3 */
      {0x09,0x10}, /* EV -2 */
      {0x09,0x08}, /* EV -1 */
      {0x01,0x00}, /* EV 0 */
      {0x01,0x08}, /* EV +1 */
      {0x01,0x10}, /* EV +2 */
      {0x01,0x18}, /* EV +3 */
      {0x01,0x20}, /* EV +4 */
    };
    kal_uint8 i;
    
    if (OV3640Sensor.Exposure == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    OV3640Sensor.Exposure = In->FeatureSetValue;
    switch (OV3640Sensor.Exposure)
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
    default: return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    CamWriteCmosSensor(0x3354, Data[i][0]); /* SGNSET */
    CamWriteCmosSensor(0x335E, Data[i][1]); /* YBright */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640Contrast
*
* DESCRIPTION
*    Contrast setting.
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
static MM_ERROR_CODE_ENUM OV3640Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    kal_uint8 Data;;
    
    if (OV3640Sensor.Contrast== In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    OV3640Sensor.Contrast = In->FeatureSetValue;
    switch (OV3640Sensor.Contrast)
    {
    case CAM_CONTRAST_HIGH:   Data = 0x24; break;
    case CAM_CONTRAST_MEDIUM: Data = 0x20; break;
    case CAM_CONTRAST_LOW:    Data = 0x1C; break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    CamWriteCmosSensor(0x335C, Data); /* manual Y offset */
    CamWriteCmosSensor(0x335D, Data); /* Y Contrast Gain(0x20 = 1x) */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640Wb
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
static MM_ERROR_CODE_ENUM OV3640Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    { /* R gain, B gain. base: 0x40 */
     {0x68,0x4E}, /* cloud */
     {0x5E,0x46}, /* daylight */
     {0x52,0x58}, /* INCANDESCENCE */
     {0x58,0x4F}, /* FLUORESCENT */
     {0x44,0x70}, /* TUNGSTEN */
    };
    kal_uint8 i;
    
    if (OV3640Sensor.Wb == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    OV3640Sensor.Wb = In->FeatureSetValue;
    switch (OV3640Sensor.Wb)
    {
    case CAM_WB_AUTO:
      CamWriteCmosSensor(0x332B, 0x00);
      return MM_ERROR_NONE;
    case CAM_WB_CLOUD:         i = 0; break;
    case CAM_WB_DAYLIGHT:      i = 1; break;
    case CAM_WB_INCANDESCENCE: i = 2; break;
    case CAM_WB_FLUORESCENT:   i = 3; break;
    case CAM_WB_TUNGSTEN:      i = 4; break;
    default: return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    CamWriteCmosSensor(0x332B, 0x08); /* AWB: 0: auto, 8: manual */
    CamWriteCmosSensor(0x33A7, AwbGain[i][0]); /* AWB R gain */
    CamWriteCmosSensor(0x33A9, AwbGain[i][1]); /* AWB B gain */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640Effect
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
static MM_ERROR_CODE_ENUM OV3640Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
      {0x18,0x40,0xA6}, /* SEPIA */
      {0x18,0x60,0x60}, /* SEPIAGREEN */
      {0x18,0xA0,0x40}, /* SEPIABLUE */
      {0x40,0x80,0x80}, /* COLORINV */
    };
    kal_uint8 i;
    
    if (OV3640Sensor.Effect == In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    OV3640Sensor.Effect = In->FeatureSetValue;
    switch (OV3640Sensor.Effect)
    {
    case CAM_EFFECT_ENC_NORMAL:     i = 0; break;
    case CAM_EFFECT_ENC_GRAYSCALE:  i = 1; break;
    case CAM_EFFECT_ENC_SEPIA:      i = 2; break;
    case CAM_EFFECT_ENC_SEPIAGREEN: i = 3; break;
    case CAM_EFFECT_ENC_SEPIABLUE:  i = 4; break;
    case CAM_EFFECT_ENC_COLORINV:   i = 5; break;
    default: return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    OV3640Sensor.SdeCtrl &= 0xA7; /* disable bit3/4/6 */
    OV3640Sensor.SdeCtrl |= Data[i][0];
    CamWriteCmosSensor(0x3355, OV3640Sensor.SdeCtrl);
    CamWriteCmosSensor(0x335A, Data[i][1]);
    CamWriteCmosSensor(0x335B, Data[i][2]);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640InitialSetting
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
static void OV3640InitialSetting(void)
{
  CamWriteCmosSensor(0x3012, 0x80); /* [7]: software reset */
  kal_sleep_task(1);
  CamWriteCmosSensor(0x304D, 0x45);
  CamWriteCmosSensor(0x30A7, 0x5E);
  CamWriteCmosSensor(0x3087, 0x16);
  CamWriteCmosSensor(0x309C, 0x1A);
  CamWriteCmosSensor(0x30A2, 0xE4);
  CamWriteCmosSensor(0x30AA, 0x42);
#if !defined(OV3640_INTERNAL_DVDD)
  CamWriteCmosSensor(0x30A9, 0xBD); /* use external regulator */
#endif
  CamWriteCmosSensor(0x30B0, 0xFF);
  CamWriteCmosSensor(0x30B1, 0x2F);
  /* driving current; 0x18: 1x, 0x19: 2x, 0x1A: 3x, 0x1B: 4x, enable bit3 will reduce line noise */
  CamWriteCmosSensor(0x30B2, 0x18);
  //CamWriteCmosSensor(0x3085, 0x20); /* pixel shift */
#if (defined(MT6276_S01))
  CamWriteCmosSensor(0x3600, 0xD0);
#else
  CamWriteCmosSensor(0x3600, 0xC0);
#endif
  
  /* clock */
  CamWriteCmosSensor(0x300D, 0x01);
  CamWriteCmosSensor(0x300E, 0x33);
  CamWriteCmosSensor(0x300F, 0x21);
  CamWriteCmosSensor(0x3010, 0x20);
  CamWriteCmosSensor(0x3011, 0x00);
  CamWriteCmosSensor(0x304C, 0x83);
  
  CamWriteCmosSensor(0x30D7, 0x10);
  CamWriteCmosSensor(0x30d9, 0x0d);
  CamWriteCmosSensor(0x30db, 0x08);
  /* insert dummy frame when reach 4x(0xA2:8x,0x92:4x,0x82:2x) gain */
  CamWriteCmosSensor(0x3016, 0x92);
  
  /* aec/agc auto setting */
  CamWriteCmosSensor(0x3018, 0x40);
  CamWriteCmosSensor(0x3019, 0x38);
  CamWriteCmosSensor(0x301a, 0x82);
  CamWriteCmosSensor(0x307d, 0x00);
  CamWriteCmosSensor(0x3087, 0x02);
  CamWriteCmosSensor(0x3082, 0x20);
  
  /* band filter setting */
  CamWriteCmosSensor(0x3071, 0xED);
  CamWriteCmosSensor(0x3073, 0xC5);
  CamWriteCmosSensor(0x301c, 0x02);
  CamWriteCmosSensor(0x301d, 0x03);
  
  CamWriteCmosSensor(0x3013, 0xF7);
  CamWriteCmosSensor(0x3014, 0x84); /* [7]BD selector, ni */
  CamWriteCmosSensor(0x3015, 0x12); /* 8x gain, auto 1/2 */
  
  /* average-based algorithm */
  CamWriteCmosSensor(0x303c, 0x08);
  CamWriteCmosSensor(0x303d, 0x18);
  CamWriteCmosSensor(0x303e, 0x06);
  CamWriteCmosSensor(0x303F, 0x0c);
  CamWriteCmosSensor(0x3030, 0x62);
  CamWriteCmosSensor(0x3031, 0x26);
  CamWriteCmosSensor(0x3032, 0xe6);
  CamWriteCmosSensor(0x3033, 0x6e);
  CamWriteCmosSensor(0x3034, 0xea);
  CamWriteCmosSensor(0x3035, 0xae);
  CamWriteCmosSensor(0x3036, 0xa6);
  CamWriteCmosSensor(0x3037, 0x6a);
  
  /* CCM */
  CamWriteCmosSensor(0x3340, 0x14);
  CamWriteCmosSensor(0x3341, 0x24);
  CamWriteCmosSensor(0x3342, 0x08);
  CamWriteCmosSensor(0x3343, 0x1C);
  CamWriteCmosSensor(0x3344, 0x3D);
  CamWriteCmosSensor(0x3345, 0x57);
  CamWriteCmosSensor(0x3346, 0x4E);
  CamWriteCmosSensor(0x3347, 0x40);
  CamWriteCmosSensor(0x3348, 0x0D);
  CamWriteCmosSensor(0x3349, 0x98);
  CamWriteCmosSensor(0x333F, 0x0E);
  
  /* auto denoise offset, bigger the value is, bigger denoise strength */
  CamWriteCmosSensor(0x3331, 0x0F);
  
  /* ISP Common */
  CamWriteCmosSensor(0x3104, 0x22); /* isp system control */
  CamWriteCmosSensor(0x3105, 0xDD);
  CamWriteCmosSensor(0x3106, 0x07);
  CamWriteCmosSensor(0x3107, 0xF8);
  
  CamWriteCmosSensor(0x3300, 0x10);
  CamWriteCmosSensor(0x3301, 0xde); /* aec gamma */
  CamWriteCmosSensor(0x3302, 0xEF); /* DSP ctrl, can not disable SDE ctrl!!!*/
  CamWriteCmosSensor(0x3355, 0x04); /* SDE */

  /* gamma */
  CamWriteCmosSensor(0x331b, 0x0a);
  CamWriteCmosSensor(0x331c, 0x18);
  CamWriteCmosSensor(0x331d, 0x30);
  CamWriteCmosSensor(0x331e, 0x5a);
  CamWriteCmosSensor(0x331f, 0x67);
  CamWriteCmosSensor(0x3320, 0x72);
  CamWriteCmosSensor(0x3321, 0x7e);
  CamWriteCmosSensor(0x3322, 0x87);
  CamWriteCmosSensor(0x3323, 0x8f);
  CamWriteCmosSensor(0x3324, 0x96);
  CamWriteCmosSensor(0x3325, 0xa3);
  CamWriteCmosSensor(0x3326, 0xaf);
  CamWriteCmosSensor(0x3327, 0xc4);
  CamWriteCmosSensor(0x3328, 0xd7);
  CamWriteCmosSensor(0x3329, 0xe8);
  CamWriteCmosSensor(0x332a, 0x20);
  
  /* AWB */
  CamWriteCmosSensor(0x3317, 0x10);
  CamWriteCmosSensor(0x3316, 0xf0);
  CamWriteCmosSensor(0x3312, 0x31);
  CamWriteCmosSensor(0x3314, 0x49);
  CamWriteCmosSensor(0x3313, 0x2e);
  CamWriteCmosSensor(0x3315, 0x3f);
  CamWriteCmosSensor(0x3311, 0xcd);
  CamWriteCmosSensor(0x3310, 0xa6);
  CamWriteCmosSensor(0x330c, 0x13);
  CamWriteCmosSensor(0x330d, 0x18);
  CamWriteCmosSensor(0x330e, 0x5a);
  CamWriteCmosSensor(0x330f, 0x4b);
  CamWriteCmosSensor(0x330b, 0x11);
  CamWriteCmosSensor(0x3306, 0x5e);
  CamWriteCmosSensor(0x3307, 0x11);
  CamWriteCmosSensor(0x3308, 0x20);
  
  OV3640LSCSetting();
  
  CamWriteCmosSensor(0x3366, 0x15);
  CamWriteCmosSensor(0x3300, 0x11); /* enable LENC, disable AFC */
  
  OV3640UvadjustSetting(0);
  
  CamWriteCmosSensor(0x3507, 0x06);
  CamWriteCmosSensor(0x350a, 0x4f);
  
  /* output format */
  CamWriteCmosSensor(0x3100, 0x02);
  CamWriteCmosSensor(0x3301, 0xde);
  CamWriteCmosSensor(0x3304, 0xfc);
  CamWriteCmosSensor(0x3400, 0x00);
  CamWriteCmosSensor(0x3403, 0x42);
  CamWriteCmosSensor(0x3404, 0x00);
  
  /* sleep control */
  CamWriteCmosSensor(0x308D, 0x14);
  CamWriteCmosSensor(0x3086, 0x03);
  CamWriteCmosSensor(0x3086, 0x00);
  
  /* test pattern */
#if defined(__OV3640_TEST_PATTERN__)
  CamWriteCmosSensor(0x3300, 0x1D);
#endif
}

/*************************************************************************
* FUNCTION
*    OV3640GetSensorInfo
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
static void OV3640GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = OV3640_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
#if (defined(MT6276))
  Info->PixelClkInv = KAL_TRUE;
#else
  Info->PixelClkInv = KAL_FALSE;
#endif
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_LOW;
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;
  Info->PreviewWidth = OV3640_IMAGE_SENSOR_PV_WIDTH_DRV;
  Info->PreviewHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT_DRV;
  Info->FullWidth = OV3640_IMAGE_SENSOR_PV_WIDTH_DRV;
  Info->FullHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT_DRV;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    OV3640PowerOn
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
static kal_uint16 OV3640PowerOn(void)
{
  kal_uint16 SensorId;
  
  CisModulePowerOn(OV3640Sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, OV3640_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 320);
  CamPdnPinCtrl(OV3640Sensor.SensorIdx, 1);
  CamRstPinCtrl(OV3640Sensor.SensorIdx, 0);
  kal_sleep_task(2); /* >= 5ms */
  
  CamPdnPinCtrl(OV3640Sensor.SensorIdx, 0);
  kal_sleep_task(1); /* >= 1ms */
  CamRstPinCtrl(OV3640Sensor.SensorIdx, 1);
  kal_sleep_task(5); /* >= 20ms */
  
  SensorId = (CamReadCmosSensor(0x300A) << 8)|CamReadCmosSensor(0x300B);
  if (SensorId != OV3640_SENSOR_ID) /* READ SENSOR ID */
  {
#if defined(__OV3640_DEBUG_TRACE__)
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", SensorId);
#endif
  }
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    OV3640DetectSensorId
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
static kal_uint32 OV3640DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM OV3640SensorClose(void);
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (OV3640Sensor.SensorIdx)
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
      SensorId = OV3640PowerOn();
      OV3640SensorClose();
      if (OV3640_SENSOR_ID == SensorId)
      {
        return OV3640_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    OV3640StillCaptureSize
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
MM_ERROR_CODE_ENUM OV3640StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*    OV3640Banding
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
static MM_ERROR_CODE_ENUM OV3640Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    if (CAM_BANDING_50HZ == In->FeatureSetValue)
    {
      OV3640Sensor.AutoCtrl2 |= 0x80;
    }
    else
    {
      OV3640Sensor.AutoCtrl2 &= 0x7F;
    }
    CamWriteCmosSensor(0x3014, OV3640Sensor.AutoCtrl2);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640InitOperationPara
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
static void OV3640InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 0; /* use WaitStableFrameNum instead of this */
  Para->PreviewDelayFrame = 4;
  Para->PreviewDisplayWaitFrame = 14;
}

/*************************************************************************
* FUNCTION
*    OV3640Preview
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
static void OV3640Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  const kal_bool PreMode = OV3640Sensor.PvMode;
  kal_uint16 DummyPixel;
  
#if (defined(MT6276_S01))
  CamWriteCmosSensor(0x3600, 0xD0);
  CamWriteCmosSensor(0x30B2, 0x18);
#endif
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    OV3640Sensor.VideoMode = KAL_TRUE;
    OV3640Sensor.Fps = In->MaxVideoFrameRate;
    DummyPixel = 0;
    break;
  default:
    OV3640Sensor.VideoMode = KAL_FALSE;
    OV3640Sensor.Fps = In->NightMode ? OV3640_FPS(7.5) : OV3640_FPS(15);
    DummyPixel = 0;
  }
  OV3640SetMirror(In->ImageMirror);
  OV3640SetClock(OV3640_PREVIEW_CLK);
  OV3640OutputWindow(KAL_TRUE, OV3640_IMAGE_SENSOR_PV_WIDTH_DRV, OV3640_IMAGE_SENSOR_PV_HEIGHT_DRV);
  OV3640SetDummy(DummyPixel, 0);
  if (!PreMode)
  {
    OV3640WriteShutter(OV3640Sensor.Shutter);
    OV3640WriteGain(OV3640Sensor.Gain);
#ifdef OV3640_GAIN2SHUTTER
    OV3640UvadjustCtrl(KAL_TRUE);
#endif
  }
  if (CAM_BANDING_50HZ == In->BandingFreq)
  {
    OV3640Sensor.AutoCtrl2 |= 0x80;
  }
  else
  {
    OV3640Sensor.AutoCtrl2 &= 0x7F;
  }
  CamWriteCmosSensor(0x3014, OV3640Sensor.AutoCtrl2);
  OV3640NightMode(In->NightMode);
  
  OV3640AeEnable(KAL_TRUE);
  OV3640AwbEnable(KAL_TRUE);
  
  Out->WaitStableFrameNum = 0;
  Out->GrabStartX = OV3640_PV_X_START;
  Out->GrabStartY = OV3640_PV_Y_START;
  Out->ExposureWindowWidth = OV3640_IMAGE_SENSOR_PV_WIDTH;
  Out->ExposureWindowHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    OV3640Capture
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
static void OV3640Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint16 DummyPixel;
  
  if (CAL_SCENARIO_WEBCAM_PREVIEW == Id || CAL_SCENARIO_WEBCAM_CAPTURE == Id) /* webcam mode */
  {
    DummyPixel = 0;
  }
  else
  {
    DummyPixel = 0;
  }
  OV3640SetDummy(DummyPixel, 0);
  
  Out->WaitStableFrameNum = 0;
  Out->GrabStartX = OV3640_PV_X_START;
  Out->GrabStartY = OV3640_PV_Y_START;
  Out->ExposureWindowWidth = OV3640_IMAGE_SENSOR_PV_WIDTH;
  Out->ExposureWindowHeight = OV3640_IMAGE_SENSOR_PV_HEIGHT;
}

/*************************************************************************
* FUNCTION
*    OV3640SensorOpen
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
static MM_ERROR_CODE_ENUM OV3640SensorOpen(void)
{
  if (OV3640PowerOn() != OV3640_SENSOR_ID)
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  
  OV3640InitialSetting();
  
  /* default setting */
  {
    IMAGE_SENSOR_INDEX_ENUM SensorIdx = OV3640Sensor.SensorIdx;
    sensor_data_struct *NvramData = OV3640Sensor.NvramData;
    
    kal_mem_set(&OV3640Sensor, 0xFF, sizeof(OV3640Sensor));
    OV3640Sensor.BypassAe = KAL_FALSE;
    OV3640Sensor.BypassAwb = KAL_FALSE;
    OV3640Sensor.PvMode = KAL_FALSE;
    OV3640Sensor.AutoCtrl1 = CamReadCmosSensor(0x3013);
    OV3640Sensor.AutoCtrl2 = CamReadCmosSensor(0x3014);
    OV3640Sensor.AutoCtrl3 = CamReadCmosSensor(0x3015);
    OV3640Sensor.DspCtrl = CamReadCmosSensor(0x3302);
    OV3640Sensor.SdeCtrl = CamReadCmosSensor(0x3355);
    OV3640Sensor.Shutter = OV3640ReadShutter();
    OV3640Sensor.Gain = OV3640ReadGain();
    OV3640Sensor.SensorIdx = SensorIdx;
    OV3640Sensor.NvramData = NvramData;
  }
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM OV3640SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return OV3640WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
  /* query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = OV3640Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = OV3640Contrast(In, Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = OV3640Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = OV3640Effect(In, Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = OV3640StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
    ErrCode = OV3640Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = OV3640SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = OV3640SceneMode(KAL_FALSE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    OV3640GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV3640DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV3640Sensor.Fps;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    OV3640InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(OV3640Sensor.SensorIdx, Out);
    break;
  
  /* set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(OV3640Sensor.SensorIdx, 1);
    CamRstPinCtrl(OV3640Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    OV3640Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    OV3640Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
    OV3640Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    OV3640AeEnable(OV3640Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
    OV3640Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    OV3640AwbEnable(OV3640Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    OV3640SensorCtrl
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
static MM_ERROR_CODE_ENUM OV3640SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    OV3640Preview(Id, In, Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    OV3640Capture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640SensorClose
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
static MM_ERROR_CODE_ENUM OV3640SensorClose(void)
{
  CamPdnPinCtrl(OV3640Sensor.SensorIdx, 1); /* goto standby */
  CamRstPinCtrl(OV3640Sensor.SensorIdx, 0);
  CisModulePowerOn(OV3640Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV3640SensorFunc
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
MM_ERROR_CODE_ENUM OV3640SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV3640 =
  {
    OV3640SensorOpen,
    OV3640SensorFeatureCtrl,
    OV3640SensorCtrl,
    OV3640SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncOV3640;
  
  return MM_ERROR_NONE;
}

