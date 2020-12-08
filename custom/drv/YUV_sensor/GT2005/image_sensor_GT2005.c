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
 *   image_sensor_GT2005.c
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
#include "image_sensor_GT2005.h"
//#include "direct_camera_sensor.h"

 #define __GT2005_DEBUG_TRACE__ 

//#define GT2005_PURPLE_CORRECTION
static struct
{
  kal_bool BypassAe;
  kal_bool BypassAwb;
  kal_bool PvMode;
  kal_uint16 VideoFps;
  kal_uint32 IntClk;
  kal_uint16 Shutter;
  kal_uint16 FrameHeight;
  kal_uint16 LineLength;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
  kal_uint16 Contrast;	
  kal_bool VideoMode;
  //kal_bool NightMode;
  kal_uint8 Banding;
} GT2005Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    GT2005HalfAdjust
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
__inline static kal_uint32 GT2005HalfAdjust(kal_uint32 DividEnd, kal_uint32 Divisor)
{
  return (DividEnd + (Divisor >> 1)) / Divisor; /* that is [DividEnd / Divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*    GT2005SetMirror
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
static void GT2005SetMirror(kal_uint8 Mirror)
{
  switch (Mirror)
  {
  case IMAGE_SENSOR_MIRROR_H:
    CamWriteCmosSensor(0x0101, 0x02);
    break;
  case IMAGE_SENSOR_MIRROR_V:
    CamWriteCmosSensor(0x0101, 0x01);
    break;
  case IMAGE_SENSOR_MIRROR_HV:
    CamWriteCmosSensor(0x0101, 0x00);
    break;
  default:
    CamWriteCmosSensor(0x0101, 0x03);
  }
}

/*************************************************************************
* FUNCTION
*    GT2005SetClock
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
static void GT2005SetClock(kal_uint32 Clk)
{
  static const kal_uint8 ClkSetting[][3] =
  {
    {0x60,0x01,0x01}, /* MCLK: 26M, SYS CLK: 39M, PCLK: 39M for preview */
    {0x30,0x01,0x01}, /* MCLK: 26M, SYS CLK: 19.5M, PCLK: 19.5M for preview */
    {0x60,0x00,0x02}, /* MCLK: 26M, SYS CLK: 39M, PCLK: 78M for capture */
    {0x3B,0x00,0x02}, /* MCLK: 26M, SYS CLK: 23.97M, PCLK: 47.94M for capture */
  };
  kal_uint8 i = 0;

  if (GT2005Sensor.IntClk == Clk)
  {
    return;
  }
  GT2005Sensor.IntClk = Clk;
  switch (GT2005Sensor.IntClk)
  {
  case 39000000: i = 0; break;
  case 19500000: i = 1; break;
  case 39000001: i = 2; break;
  case 23970000: i = 3; break;
  default: ASSERT(0);
  }
/* pre clock = MCLK / pre_div, where 2.5MHz < pre clock < 27MHz
   vco clock = 0x0118[7:0] x pre clock, where 300MHz < vco clock < 660MHz
   SPCK (internal clock) = vco clock / (VT_SYS_CNTL x DIV_VT_PIX), where
      VT_SYS_CNTL = 1,2,4,4,6,8,10,12 for 0x0119[2:0] = 0~7, respectively
      DIV_VT_PIX = 4,5,6,7,8,9,10,10 for 0x011A[2:0] = 0~7, respectively
   DCLK(output clock) =  vco clock / (DIV_OP_SYS x 8), where
      DIV_OP_SYS = 1,2,4,4,6,8,10,12 for 0x011B[2:0] = 0~7, respectively
   should be SPCK : DCLK = 1 : 1 or 1 : 2
*/
  CamWriteCmosSensor(0x0118, ClkSetting[i][0]);
  CamWriteCmosSensor(0x011B, ClkSetting[i][1]);
  CamWriteCmosSensor(0x011D, ClkSetting[i][2]);
}

/*************************************************************************
* FUNCTION
*    GT2005WriteShutter
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
static void GT2005WriteShutter(kal_uint32 Shutter)
{
  CamWriteCmosSensor(0x0304, Shutter >> 8); /* Shutter */
  CamWriteCmosSensor(0x0305, Shutter);
}

/*************************************************************************
* FUNCTION
*    GT2005ReadShutter
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
static kal_uint16 GT2005ReadShutter(void)//number of line
{
  return (CamReadCmosSensor(0x0012) << 8)|CamReadCmosSensor(0x0013);
}

/*************************************************************************
* FUNCTION
*    GT2005AeEnable
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
static void GT2005AeEnable(kal_bool Enable)
{
  if (GT2005Sensor.BypassAe) 
  {
    Enable = KAL_FALSE;
  }
  if (Enable)
  {
    CamWriteCmosSensor(0x0300, 0x81);
  }
  else
  {
    kal_uint16 Shutter, AGain, DGain;

    /* when disable ae, ae will use 0x304~308 as shutter and gain.
        so need to read 0x12~17 and apply to 0x304~308 to avoid ae changed.
    */
    CamWriteCmosSensor(0x0300, 0xC1); /* fix ae */
    Shutter = (CamReadCmosSensor(0x0012) << 8)|CamReadCmosSensor(0x0013);
    AGain = (CamReadCmosSensor(0x0014) << 8)|CamReadCmosSensor(0x0015);
    DGain = (CamReadCmosSensor(0x0016) << 8)|CamReadCmosSensor(0x0017);
    CamWriteCmosSensor(0x0304, Shutter >> 8);
    CamWriteCmosSensor(0x0305, Shutter);
    CamWriteCmosSensor(0x0306, AGain >> 8);
    CamWriteCmosSensor(0x0307, AGain);
    CamWriteCmosSensor(0x0308, DGain >> 2);
    CamWriteCmosSensor(0x0300, 0x01); /* disable ae */
  }
}

/*************************************************************************
* FUNCTION
*    GT2005AwbEnable
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
static void GT2005AwbEnable(kal_bool Enable)
{
  kal_uint8 Reg;
  
  if (GT2005Sensor.BypassAwb)
  {
    Enable = KAL_FALSE;
  }
  if (Enable)
  {
    Reg = CamReadCmosSensor(0x031A);
    CamWriteCmosSensor(0x31A, Reg|0x80);
  }
  else
  {
    /* when disable awb, awb will use 0x31A~31F as RGB awb gain.
        so need to read 0x26~2B and apply to 0x31A~31F to avoid awb changed.
    */
    Reg = CamReadCmosSensor(0x002B);
    CamWriteCmosSensor(0x31F, Reg);
    Reg = (CamReadCmosSensor(0x002A)&0x03)|(CamReadCmosSensor(0x031E)&0xFC);
    CamWriteCmosSensor(0x31E, Reg);
    Reg = CamReadCmosSensor(0x0029);
    CamWriteCmosSensor(0x31D, Reg);
    Reg = (CamReadCmosSensor(0x0028)&0x03)|(CamReadCmosSensor(0x031C)&0xFC);
    CamWriteCmosSensor(0x31C, Reg);
    Reg = CamReadCmosSensor(0x0027);
    CamWriteCmosSensor(0x31B, Reg);
    Reg = (CamReadCmosSensor(0x0026)&0x03)|(CamReadCmosSensor(0x031A)&0xFC);
    Reg &= 0x7F; /* disable awb */
    CamWriteCmosSensor(0x31A, Reg);
  }
}


/*************************************************************************
* FUNCTION
*    GT2005SceneMode
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
static MM_ERROR_CODE_ENUM GT2005SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005Ev
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
static MM_ERROR_CODE_ENUM GT2005Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0x30);
		CamWriteCmosSensor(0x0201, 0x95);
		break;
    case CAM_EV_NEG_3_3: 
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0x35);
		CamWriteCmosSensor(0x0201, 0xa5); 
		break;
    case CAM_EV_NEG_2_3: 
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0x40);
		CamWriteCmosSensor(0x0201, 0xb5);
		break;
    case CAM_EV_NEG_1_3: 
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0x45);
		CamWriteCmosSensor(0x0201, 0xc5);
		break;
    case CAM_EV_ZERO:    
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0x50);
		CamWriteCmosSensor(0x0201, 0xd5);
		break;
    case CAM_EV_POS_1_3: 
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0x60);
		CamWriteCmosSensor(0x0201, 0x10);
		break;
    case CAM_EV_POS_2_3: 
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0x75);
		CamWriteCmosSensor(0x0201, 0x20);
		break;
    case CAM_EV_POS_3_3: 
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0x90);
		CamWriteCmosSensor(0x0201, 0x30);
		break;
    case CAM_EV_POS_4_3: 
		CamWriteCmosSensor(0x0300, 0x81); 
		CamWriteCmosSensor(0x0301, 0xa0);
		CamWriteCmosSensor(0x0201, 0x40);
		break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005Contrast
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
static MM_ERROR_CODE_ENUM GT2005Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    
    if (GT2005Sensor.Contrast== In->FeatureSetValue)
    {
      return MM_ERROR_NONE;
    }
    GT2005Sensor.Contrast = In->FeatureSetValue;
    switch (GT2005Sensor.Contrast)
    {
    case CAM_CONTRAST_HIGH:   Data = 0x40; break;
    case CAM_CONTRAST_MEDIUM: Data = 0x20; break;
    case CAM_CONTRAST_LOW:    Data = 0x00; break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    CamWriteCmosSensor(0x0200, Data); 
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GT2005Saturation
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
static MM_ERROR_CODE_ENUM GT2005Saturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Saturation = &Out->FeatureInfo.FeatureEnum;

    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Saturation->IsSupport = KAL_TRUE;
    Saturation->ItemCount = 3;
    Saturation->SupportItem[0] = CAM_SATURATION_HIGH;
    Saturation->SupportItem[1] = CAM_SATURATION_MEDIUM;
    Saturation->SupportItem[2] = CAM_SATURATION_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    switch (In->FeatureSetValue)
    {
    case CAM_SATURATION_HIGH:
        CamWriteCmosSensor(0x0202, 0x58);
        break;
    case CAM_SATURATION_MEDIUM:
        CamWriteCmosSensor(0x0202, 0x48);
        break;
    case CAM_SATURATION_LOW:
        CamWriteCmosSensor(0x0202, 0x38); 
        break;
    default:
        return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GT2005Sharpness
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
static MM_ERROR_CODE_ENUM GT2005Sharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Sharpness = &Out->FeatureInfo.FeatureEnum;

    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Sharpness->IsSupport = KAL_TRUE;
    Sharpness->ItemCount = 3;
    Sharpness->SupportItem[0] = CAM_SHARPNESS_HIGH;
    Sharpness->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
    Sharpness->SupportItem[2] = CAM_SHARPNESS_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    switch (In->FeatureSetValue)
    {
    case CAM_SHARPNESS_HIGH:
        CamWriteCmosSensor(0x040b, 0x66);
        break;
    case CAM_SHARPNESS_MEDIUM:
        CamWriteCmosSensor(0x040b, 0x44);
        break;
    case CAM_SHARPNESS_LOW:
        CamWriteCmosSensor(0x040b, 0x22);
        break;
    default:
        return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005ReadGain
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

static kal_uint16 GT2005ReadGain(void)
{
  const kal_uint8 Reg14 = CamReadCmosSensor(0x0014);
  const kal_uint8 Reg15 = CamReadCmosSensor(0x0015);
  return (((Reg14 & 0x0F) << 8)+ Reg15);
}


/*************************************************************************
* FUNCTION
*    GT2005Wb
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
static MM_ERROR_CODE_ENUM GT2005Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    switch (In->FeatureSetValue)
    {
    case CAM_WB_AUTO:          
		CamWriteCmosSensor(0x031a, 0x81); 
		CamWriteCmosSensor(0x0320, 0x24); 
		CamWriteCmosSensor(0x0321, 0x14); 
		CamWriteCmosSensor(0x0322, 0x24); 
		CamWriteCmosSensor(0x0323, 0x1a); 
		CamWriteCmosSensor(0x0441, 0x4b); 
		CamWriteCmosSensor(0x0442, 0x00); 
		CamWriteCmosSensor(0x0443, 0x00); 
		CamWriteCmosSensor(0x0444, 0x31);
		break;
    case CAM_WB_CLOUD:         
		CamWriteCmosSensor(0x0320, 0x02); 
		CamWriteCmosSensor(0x0321, 0x02); 
		CamWriteCmosSensor(0x0322, 0x02); 
		CamWriteCmosSensor(0x0323, 0x02); 
		CamWriteCmosSensor(0x0441, 0x72); 
		CamWriteCmosSensor(0x0442, 0x00); 
		CamWriteCmosSensor(0x0443, 0x00); 
		CamWriteCmosSensor(0x0444, 0x0d);
		break;
    case CAM_WB_DAYLIGHT:      
		CamWriteCmosSensor(0x0320, 0x02); 
		CamWriteCmosSensor(0x0321, 0x02); 
		CamWriteCmosSensor(0x0322, 0x02); 
		CamWriteCmosSensor(0x0323, 0x02); 
		CamWriteCmosSensor(0x0441, 0x60); 
		CamWriteCmosSensor(0x0442, 0x00); 
		CamWriteCmosSensor(0x0443, 0x00); 
		CamWriteCmosSensor(0x0444, 0x14);
		break;
    case CAM_WB_INCANDESCENCE: 
		CamWriteCmosSensor(0x0320, 0x02); 
		CamWriteCmosSensor(0x0321, 0x02); 
		CamWriteCmosSensor(0x0322, 0x02); 
		CamWriteCmosSensor(0x0323, 0x02); 
		CamWriteCmosSensor(0x0441, 0x0b); 
		CamWriteCmosSensor(0x0442, 0x00); 
		CamWriteCmosSensor(0x0443, 0x00); 
		CamWriteCmosSensor(0x0444, 0x5e);
		break;
    case CAM_WB_FLUORESCENT:   
		CamWriteCmosSensor(0x0320, 0x02); 
		CamWriteCmosSensor(0x0321, 0x02); 
		CamWriteCmosSensor(0x0322, 0x02); 
		CamWriteCmosSensor(0x0323, 0x02); 
		CamWriteCmosSensor(0x0441, 0x43); 
		CamWriteCmosSensor(0x0442, 0x00); 
		CamWriteCmosSensor(0x0443, 0x00); 
		CamWriteCmosSensor(0x0444, 0x4b);
		break;
    case CAM_WB_TUNGSTEN: 
		CamWriteCmosSensor(0x0320, 0x02); 
		CamWriteCmosSensor(0x0321, 0x02); 
		CamWriteCmosSensor(0x0322, 0x02); 
		CamWriteCmosSensor(0x0323, 0x02); 
		CamWriteCmosSensor(0x0441, 0x0b); 
		CamWriteCmosSensor(0x0442, 0x00); 
		CamWriteCmosSensor(0x0443, 0x00); 
		CamWriteCmosSensor(0x0444, 0x5e);
		break;
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005Effect
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
static MM_ERROR_CODE_ENUM GT2005Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
      {0x00,0x60,0xA0}, /* NORMAL */
      {0x06,0x00,0x00}, /* GRAYSCALE */
      {0x0A,0x60,0xA0}, /* SEPIA */
      {0x0A,0x20,0x00}, /* SEPIAGREEN */
      {0x0A,0xFB,0x00}, /* SEPIABLUE */
      {0x09,0x00,0x00}, /* COLORINV */
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
    default:
      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    }
    CamWriteCmosSensor(0x0115, Data[i][0]); /* select picture effect */
    CamWriteCmosSensor(0x026E, Data[i][1]); /* offset of sepia color at U axis */
    CamWriteCmosSensor(0x026F, Data[i][2]); /* offset of sepia color at V axis */
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005Banding
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
static MM_ERROR_CODE_ENUM GT2005Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    CamWriteCmosSensor(0x0315, CAM_BANDING_50HZ == In->FeatureSetValue ? 0x16 : 0x56);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005StillCaptureSize
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
MM_ERROR_CODE_ENUM GT2005StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  kal_uint32 count = 0;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 4;
    CapSize->SupportItem[count++] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[count++] = CAM_IMAGE_SIZE_VGA;
    CapSize->SupportItem[count++] = CAM_IMAGE_SIZE_1M;
    CapSize->SupportItem[count++] = CAM_IMAGE_SIZE_2M;
#if (defined(__MAIN_CAMERA_IMAGE_IP_3M__) || defined(__SUB_CAMERA_IMAGE_IP_3M__))
    CapSize->ItemCount++;
    CapSize->SupportItem[count++] = CAM_IMAGE_SIZE_3M;
#endif

#if (defined(__MAIN_CAMERA_IMAGE_IP_5M__) || defined(__SUB_CAMERA_IMAGE_IP_5M__))
    CapSize->ItemCount++;
    CapSize->SupportItem[count++] = CAM_IMAGE_SIZE_5M;
#endif

  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*  GT2005GammaSelect
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
static void GT2005GammaSelect(kal_uint8 level)
{
  static const kal_uint8 GammaData[][23] =
  {
    {0x00,0x00,0x00,0x00,0x00,0x12,0x3B,0x34,0x26,0x1E,0x33,0x2E,0x2C,0x28,0x42,0x42,
     0x38,0x37,0x4D,0x48,0x44,0x40,0x56},
    {0x00,0x00,0x00,0x00,0x00,0x29,0x37,0x3A,0x26,0x21,0x34,0x34,0x2B,0x28,0x41,0x3F,
     0x3A,0x36,0x47,0x44,0x3B,0x3B,0x4D},
    {0x00,0x00,0x00,0x00,0x00,0x29,0x4B,0x41,0x2A,0x25,0x3A,0x2C,0x2B,0x28,0x40,0x3D,
     0x38,0x31,0x44,0x3E,0x3E,0x37,0x43},
    {0x00,0x00,0x00,0x00,0x00,0x2F,0x4E,0x50,0x31,0x27,0x3C,0x35,0x27,0x23,0x46,0x3A,
     0x32,0x32,0x38,0x3E,0x36,0x33,0x41},
    {0x00,0x00,0x00,0x00,0x15,0x33,0x61,0x56,0x30,0x22,0x3E,0x2E,0x2B,0x28,0x3C,0x38,
     0x2F,0x2A,0x3C,0x34,0x31,0x31,0x39},
  };
  
  if (level >= sizeof(GammaData) / sizeof(GammaData[0]))
  {
    ASSERT(0);
  }
  CamWriteCmosSensor(0x0461, GammaData[level][0]); 
  CamWriteCmosSensor(0x0462, GammaData[level][1]); 
  CamWriteCmosSensor(0x0463, GammaData[level][2]); 
  CamWriteCmosSensor(0x0464, GammaData[level][3]); 
  CamWriteCmosSensor(0x0465, GammaData[level][4]); 
  CamWriteCmosSensor(0x0466, GammaData[level][5]); 
  CamWriteCmosSensor(0x0467, GammaData[level][6]); 
  CamWriteCmosSensor(0x0468, GammaData[level][7]); 
  CamWriteCmosSensor(0x0469, GammaData[level][8]); 
  CamWriteCmosSensor(0x046A, GammaData[level][9]); 
  CamWriteCmosSensor(0x046B, GammaData[level][10]); 
  CamWriteCmosSensor(0x046C, GammaData[level][11]); 
  CamWriteCmosSensor(0x046D, GammaData[level][12]); 
  CamWriteCmosSensor(0x046E, GammaData[level][13]); 
  CamWriteCmosSensor(0x046F, GammaData[level][14]); 
  CamWriteCmosSensor(0x0470, GammaData[level][15]); 
  CamWriteCmosSensor(0x0471, GammaData[level][16]);
  CamWriteCmosSensor(0x0472, GammaData[level][17]);
  CamWriteCmosSensor(0x0473, GammaData[level][18]);
  CamWriteCmosSensor(0x0474, GammaData[level][19]);
  CamWriteCmosSensor(0x0475, GammaData[level][20]);
  CamWriteCmosSensor(0x0476, GammaData[level][21]);
  CamWriteCmosSensor(0x0477, GammaData[level][22]);
}

/*************************************************************************
* FUNCTION
*    GT2005InitialSetting
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
static void GT2005InitialSetting(void)
{
	CamWriteCmosSensor(0x0101, 0x00); 
	CamWriteCmosSensor(0x0102, 0x00); 
	CamWriteCmosSensor(0x0103, 0x00); 
	CamWriteCmosSensor(0x0105, 0x00); 
	CamWriteCmosSensor(0x0106, 0xF0); 
	CamWriteCmosSensor(0x0107, 0x00); 
	CamWriteCmosSensor(0x0108, 0x1C); 
	CamWriteCmosSensor(0x0109, 0x01); 
	CamWriteCmosSensor(0x010A, 0x00); 
	CamWriteCmosSensor(0x010B, 0x00); 
	CamWriteCmosSensor(0x010C, 0x00); 
	CamWriteCmosSensor(0x010D, 0x08); 
	CamWriteCmosSensor(0x010E, 0x00); 
	CamWriteCmosSensor(0x010F, 0x08); 
	CamWriteCmosSensor(0x0110, 0x06); 
	CamWriteCmosSensor(0x0111, 0x40); 
	CamWriteCmosSensor(0x0112, 0x04); 
	CamWriteCmosSensor(0x0113, 0xB0); 
	CamWriteCmosSensor(0x0114, 0x00); 
	CamWriteCmosSensor(0x0115, 0x00); 
	CamWriteCmosSensor(0x0116, 0x02); 
	CamWriteCmosSensor(0x0117, 0x00); 
	CamWriteCmosSensor(0x0119, 0x00); 
	CamWriteCmosSensor(0x011A, 0x04); 
	CamWriteCmosSensor(0x011B, 0x00); 
	CamWriteCmosSensor(0x011C, 0x00); 
	CamWriteCmosSensor(0x011D, 0x02); 
	CamWriteCmosSensor(0x011E, 0x00); 
	CamWriteCmosSensor(0x011F, 0x00); 
	CamWriteCmosSensor(0x0120, 0x1C); 
	CamWriteCmosSensor(0x0121, 0x00); 
	CamWriteCmosSensor(0x0122, 0x04); 
	CamWriteCmosSensor(0x0123, 0x00); 
	CamWriteCmosSensor(0x0124, 0x00); 
	CamWriteCmosSensor(0x0125, 0x00); 
	CamWriteCmosSensor(0x0126, 0x00); 
	CamWriteCmosSensor(0x0127, 0x00); 
	CamWriteCmosSensor(0x0128, 0x00); 
	CamWriteCmosSensor(0x0200, 0x00); 
	CamWriteCmosSensor(0x0202, 0x40); 
	CamWriteCmosSensor(0x0203, 0x00); 
	CamWriteCmosSensor(0x0204, 0x0C); 
	CamWriteCmosSensor(0x0205, 0x09); 
	CamWriteCmosSensor(0x0206, 0x0A); 
	CamWriteCmosSensor(0x0207, 0x20); 
	CamWriteCmosSensor(0x0208, 0x00); 
	CamWriteCmosSensor(0x0209, 0x2A); 
	CamWriteCmosSensor(0x020A, 0x01); 
	CamWriteCmosSensor(0x020B, 0x88);
	CamWriteCmosSensor(0x020C, 0xa4);
	CamWriteCmosSensor(0x020D, 0xC8); 
	CamWriteCmosSensor(0x020E, 0xBC); 
	CamWriteCmosSensor(0x020F, 0x08); 
	CamWriteCmosSensor(0x0210, 0xd6); 
	CamWriteCmosSensor(0x0211, 0x00); 
	CamWriteCmosSensor(0x0212, 0x20); 
	CamWriteCmosSensor(0x0213, 0x81); 
	CamWriteCmosSensor(0x0214, 0x15); 
	CamWriteCmosSensor(0x0215, 0x00); 
	CamWriteCmosSensor(0x0216, 0x00); 
	CamWriteCmosSensor(0x0217, 0x00); 
	CamWriteCmosSensor(0x0218, 0x46); 
	CamWriteCmosSensor(0x0219, 0x30); 
	CamWriteCmosSensor(0x021A, 0x03); 
	CamWriteCmosSensor(0x021B, 0x28); 
	CamWriteCmosSensor(0x021C, 0x02); 
	CamWriteCmosSensor(0x021D, 0x60); 
	CamWriteCmosSensor(0x021E, 0x00); 
	CamWriteCmosSensor(0x021F, 0x00); 
	CamWriteCmosSensor(0x0220, 0x08); 
	CamWriteCmosSensor(0x0221, 0x08); 
	CamWriteCmosSensor(0x0222, 0x04); 
	CamWriteCmosSensor(0x0223, 0x00); 
	CamWriteCmosSensor(0x0224, 0x1f); 
	CamWriteCmosSensor(0x0225, 0x1e); 
	CamWriteCmosSensor(0x0226, 0x18); 
	CamWriteCmosSensor(0x0227, 0x1d); 
	CamWriteCmosSensor(0x0228, 0x1f); 
	CamWriteCmosSensor(0x0229, 0x1f); 
	CamWriteCmosSensor(0x022A, 0x01); 
	CamWriteCmosSensor(0x022B, 0x04); 
	CamWriteCmosSensor(0x022C, 0x05); 
	CamWriteCmosSensor(0x022D, 0x05); 
	CamWriteCmosSensor(0x022E, 0x04); 
	CamWriteCmosSensor(0x022F, 0x03); 
	CamWriteCmosSensor(0x0230, 0x02); 
	CamWriteCmosSensor(0x0231, 0x1f); 
	CamWriteCmosSensor(0x0232, 0x1a); 
	CamWriteCmosSensor(0x0233, 0x19); 
	CamWriteCmosSensor(0x0234, 0x19); 
	CamWriteCmosSensor(0x0235, 0x1b); 
	CamWriteCmosSensor(0x0236, 0x1f); 
	CamWriteCmosSensor(0x0237, 0x04); 
	CamWriteCmosSensor(0x0238, 0xee); 
	CamWriteCmosSensor(0x0239, 0xff); 
	CamWriteCmosSensor(0x023A, 0x00); 
	CamWriteCmosSensor(0x023B, 0x00); 
	CamWriteCmosSensor(0x023C, 0x00); 
	CamWriteCmosSensor(0x023D, 0x00); 
	CamWriteCmosSensor(0x023E, 0x00); 
	CamWriteCmosSensor(0x023F, 0x00); 
	CamWriteCmosSensor(0x0240, 0x00); 
	CamWriteCmosSensor(0x0241, 0x00); 
	CamWriteCmosSensor(0x0242, 0x00); 
	CamWriteCmosSensor(0x0243, 0x21); 
	CamWriteCmosSensor(0x0244, 0x42); 
	CamWriteCmosSensor(0x0245, 0x53); 
	CamWriteCmosSensor(0x0246, 0x54); 
	CamWriteCmosSensor(0x0247, 0x54); 
	CamWriteCmosSensor(0x0248, 0x54); 
	CamWriteCmosSensor(0x0249, 0x33); 
	CamWriteCmosSensor(0x024A, 0x11); 
	CamWriteCmosSensor(0x024B, 0x00); 
	CamWriteCmosSensor(0x024C, 0x00); 
	CamWriteCmosSensor(0x024D, 0xff); 
	CamWriteCmosSensor(0x024E, 0xee); 
	CamWriteCmosSensor(0x024F, 0xdd); 
	CamWriteCmosSensor(0x0250, 0x00); 
	CamWriteCmosSensor(0x0251, 0x00); 
	CamWriteCmosSensor(0x0252, 0x00); 
	CamWriteCmosSensor(0x0253, 0x00); 
	CamWriteCmosSensor(0x0254, 0x00); 
	CamWriteCmosSensor(0x0255, 0x00); 
	CamWriteCmosSensor(0x0256, 0x00); 
	CamWriteCmosSensor(0x0257, 0x00); 
	CamWriteCmosSensor(0x0258, 0x00); 
	CamWriteCmosSensor(0x0259, 0x00); 
	CamWriteCmosSensor(0x025A, 0x00); 
	CamWriteCmosSensor(0x025B, 0x00); 
	CamWriteCmosSensor(0x025C, 0x00); 
	CamWriteCmosSensor(0x025D, 0x00); 
	CamWriteCmosSensor(0x025E, 0x00); 
	CamWriteCmosSensor(0x025F, 0x00); 
	CamWriteCmosSensor(0x0260, 0x00); 
	CamWriteCmosSensor(0x0261, 0x00); 
	CamWriteCmosSensor(0x0262, 0x00); 
	CamWriteCmosSensor(0x0263, 0x00); 
	CamWriteCmosSensor(0x0264, 0x00); 
	CamWriteCmosSensor(0x0265, 0x00); 
	CamWriteCmosSensor(0x0266, 0x00); 
	CamWriteCmosSensor(0x0267, 0x00); 
	CamWriteCmosSensor(0x0268, 0x8F);
	CamWriteCmosSensor(0x0269, 0xA3); 
	CamWriteCmosSensor(0x026A, 0xB4); 
	CamWriteCmosSensor(0x026B, 0x90); 
	CamWriteCmosSensor(0x026C, 0x00); 
	CamWriteCmosSensor(0x026D, 0xD0); 
	CamWriteCmosSensor(0x026E, 0x60); 
	CamWriteCmosSensor(0x026F, 0xA0); 
	CamWriteCmosSensor(0x0270, 0x40); 
	CamWriteCmosSensor(0x0302, 0x0D); 
	CamWriteCmosSensor(0x0303, 0x07); 
	CamWriteCmosSensor(0x0304, 0x03); 
	CamWriteCmosSensor(0x0305, 0x83); 
	CamWriteCmosSensor(0x0306, 0x00); 
	CamWriteCmosSensor(0x0307, 0x22); 
	CamWriteCmosSensor(0x0308, 0x00); 
	CamWriteCmosSensor(0x0309, 0x55); 
	CamWriteCmosSensor(0x030A, 0x55); 
	CamWriteCmosSensor(0x030B, 0x55); 
	CamWriteCmosSensor(0x030C, 0x54); 
	CamWriteCmosSensor(0x030D, 0x1F); 
	CamWriteCmosSensor(0x030E, 0x0A); 
	CamWriteCmosSensor(0x030F, 0x10); 
	CamWriteCmosSensor(0x0310, 0x04); 
	CamWriteCmosSensor(0x0311, 0xFF); 
	CamWriteCmosSensor(0x0312, 0x98); 
	CamWriteCmosSensor(0x0313, 0x35); 
	CamWriteCmosSensor(0x0314, 0x35); 
	CamWriteCmosSensor(0x0315, 0x16); 
	CamWriteCmosSensor(0x0316, 0x26); 
	CamWriteCmosSensor(0x0317, 0x02); 
	CamWriteCmosSensor(0x0318, 0x08); 
	CamWriteCmosSensor(0x0319, 0x0C); 
	CamWriteCmosSensor(0x031A, 0x81); 
	CamWriteCmosSensor(0x031B, 0x00); 
	CamWriteCmosSensor(0x031C, 0x3D); 
	CamWriteCmosSensor(0x031D, 0x00); 
	CamWriteCmosSensor(0x031E, 0xF9); 
	CamWriteCmosSensor(0x031F, 0x00); 
	CamWriteCmosSensor(0x0320, 0xE1); 
	CamWriteCmosSensor(0x0321, 0x1A); 
	CamWriteCmosSensor(0x0322, 0xDE); 
	CamWriteCmosSensor(0x0323, 0x11); 
	CamWriteCmosSensor(0x0324, 0x08); 
	CamWriteCmosSensor(0x0325, 0xf0); 
	CamWriteCmosSensor(0x0326, 0x30); 
	CamWriteCmosSensor(0x0327, 0x17); 
	CamWriteCmosSensor(0x0328, 0x11); 
	CamWriteCmosSensor(0x0329, 0x22); 
	CamWriteCmosSensor(0x032A, 0x2f); 
	CamWriteCmosSensor(0x032B, 0x21); 
	CamWriteCmosSensor(0x032C, 0xda); 
	CamWriteCmosSensor(0x032D, 0x10); 
	CamWriteCmosSensor(0x032E, 0xea); 
	CamWriteCmosSensor(0x032F, 0x18); 
	CamWriteCmosSensor(0x0330, 0x29); 
	CamWriteCmosSensor(0x0331, 0x25); 
	CamWriteCmosSensor(0x0332, 0x12); 
	CamWriteCmosSensor(0x0333, 0x0f); 
	CamWriteCmosSensor(0x0334, 0xe0); 
	CamWriteCmosSensor(0x0335, 0x13); 
	CamWriteCmosSensor(0x0336, 0xFF); 
	CamWriteCmosSensor(0x0337, 0x20); 
	CamWriteCmosSensor(0x0338, 0x46); 
	CamWriteCmosSensor(0x0339, 0x04); 
	CamWriteCmosSensor(0x033A, 0x04); 
	CamWriteCmosSensor(0x033B, 0xff); 
	CamWriteCmosSensor(0x033C, 0x01); 
	CamWriteCmosSensor(0x033D, 0x00); 
	CamWriteCmosSensor(0x033E, 0x03); 
	CamWriteCmosSensor(0x033F, 0x28); 
	CamWriteCmosSensor(0x0340, 0x02); 
	CamWriteCmosSensor(0x0341, 0x60); 
	CamWriteCmosSensor(0x0342, 0x90); 
	CamWriteCmosSensor(0x0343, 0xe4); 
	CamWriteCmosSensor(0x0344, 0x33); 
	CamWriteCmosSensor(0x0400, 0xE8); 
	CamWriteCmosSensor(0x0401, 0x40); 
	CamWriteCmosSensor(0x0402, 0x00); 
	CamWriteCmosSensor(0x0403, 0x00); 
	CamWriteCmosSensor(0x0404, 0xF8); 
	CamWriteCmosSensor(0x0405, 0x08); 
	CamWriteCmosSensor(0x0406, 0x08); 
	CamWriteCmosSensor(0x0407, 0x89); 
	CamWriteCmosSensor(0x0408, 0x44); 
	CamWriteCmosSensor(0x0409, 0x1F); 
	CamWriteCmosSensor(0x040A, 0x00); 
	CamWriteCmosSensor(0x040B, 0xF6); 
	CamWriteCmosSensor(0x040C, 0xa0); 
	CamWriteCmosSensor(0x040D, 0x00); 
	CamWriteCmosSensor(0x040E, 0x00); 
	CamWriteCmosSensor(0x040F, 0x00); 
	CamWriteCmosSensor(0x0410, 0x0d); 
	CamWriteCmosSensor(0x0411, 0x0d); 
	CamWriteCmosSensor(0x0412, 0x0c); 
	CamWriteCmosSensor(0x0413, 0x04); 
	CamWriteCmosSensor(0x0414, 0x00); 
	CamWriteCmosSensor(0x0415, 0x00); 
	CamWriteCmosSensor(0x0416, 0x07); 
	CamWriteCmosSensor(0x0417, 0x09); 
	CamWriteCmosSensor(0x0418, 0x16); 
	CamWriteCmosSensor(0x0419, 0x14); 
	CamWriteCmosSensor(0x041A, 0x11); 
	CamWriteCmosSensor(0x041B, 0x14); 
	CamWriteCmosSensor(0x041C, 0x07); 
	CamWriteCmosSensor(0x041D, 0x07); 
	CamWriteCmosSensor(0x041E, 0x06); 
	CamWriteCmosSensor(0x041F, 0x02); 
	CamWriteCmosSensor(0x0420, 0x42); 
	CamWriteCmosSensor(0x0421, 0x42); 
	CamWriteCmosSensor(0x0422, 0x47); 
	CamWriteCmosSensor(0x0423, 0x39); 
	CamWriteCmosSensor(0x0424, 0x3e); 
	CamWriteCmosSensor(0x0425, 0x4d); 
	CamWriteCmosSensor(0x0426, 0x46); 
	CamWriteCmosSensor(0x0427, 0x3a); 
	CamWriteCmosSensor(0x0428, 0x21); 
	CamWriteCmosSensor(0x0429, 0x21); 
	CamWriteCmosSensor(0x042A, 0x26); 
	CamWriteCmosSensor(0x042B, 0x1c); 
	CamWriteCmosSensor(0x042C, 0x25); 
	CamWriteCmosSensor(0x042D, 0x25); 
	CamWriteCmosSensor(0x042E, 0x28); 
	CamWriteCmosSensor(0x042F, 0x20); 
	CamWriteCmosSensor(0x0430, 0x3E); 
	CamWriteCmosSensor(0x0431, 0x3E); 
	CamWriteCmosSensor(0x0432, 0x33); 
	CamWriteCmosSensor(0x0433, 0x2e); 
	CamWriteCmosSensor(0x0434, 0x54); 
	CamWriteCmosSensor(0x0435, 0x53); 
	CamWriteCmosSensor(0x0436, 0x3c); 
	CamWriteCmosSensor(0x0437, 0x51); 
	CamWriteCmosSensor(0x0438, 0x2B); 
	CamWriteCmosSensor(0x0439, 0x2B); 
	CamWriteCmosSensor(0x043A, 0x38); 
	CamWriteCmosSensor(0x043B, 0x22); 
	CamWriteCmosSensor(0x043C, 0x3B); 
	CamWriteCmosSensor(0x043D, 0x3B); 
	CamWriteCmosSensor(0x043E, 0x31); 
	CamWriteCmosSensor(0x043F, 0x37); 
	CamWriteCmosSensor(0x0440, 0x00); 
	CamWriteCmosSensor(0x0441, 0x5C); 
	CamWriteCmosSensor(0x0442, 0x00); 
	CamWriteCmosSensor(0x0443, 0x00); 
	CamWriteCmosSensor(0x0444, 0x17); 
	CamWriteCmosSensor(0x0445, 0x00); 
	CamWriteCmosSensor(0x0446, 0x00); 
	CamWriteCmosSensor(0x0447, 0x00); 
	CamWriteCmosSensor(0x0448, 0x00); 
	CamWriteCmosSensor(0x0449, 0x00); 
	CamWriteCmosSensor(0x044A, 0x00); 
	CamWriteCmosSensor(0x044D, 0xE0); 
	CamWriteCmosSensor(0x044E, 0x05); 
	CamWriteCmosSensor(0x044F, 0x07); 
	CamWriteCmosSensor(0x0450, 0x00); 
	CamWriteCmosSensor(0x0451, 0x00); 
	CamWriteCmosSensor(0x0452, 0x00); 
	CamWriteCmosSensor(0x0453, 0x00); 
	CamWriteCmosSensor(0x0454, 0x00); 
	CamWriteCmosSensor(0x0455, 0x00); 
	CamWriteCmosSensor(0x0456, 0x00); 
	CamWriteCmosSensor(0x0457, 0x00); 
	CamWriteCmosSensor(0x0458, 0x00); 
	CamWriteCmosSensor(0x0459, 0x00); 
	CamWriteCmosSensor(0x045A, 0x00); 
	CamWriteCmosSensor(0x045B, 0x00); 
	CamWriteCmosSensor(0x045C, 0x00); 
	CamWriteCmosSensor(0x045D, 0x00); 
	CamWriteCmosSensor(0x045E, 0x00); 
	CamWriteCmosSensor(0x045F, 0x00); 
	CamWriteCmosSensor(0x0460, 0x80); 
	CamWriteCmosSensor(0x0461, 0x00); 
	CamWriteCmosSensor(0x0462, 0x00); 
	CamWriteCmosSensor(0x0463, 0x00); 
	CamWriteCmosSensor(0x0464, 0x00); 
	CamWriteCmosSensor(0x0465, 0x00); 
	CamWriteCmosSensor(0x0466, 0x25); 
	CamWriteCmosSensor(0x0467, 0x25); 
	CamWriteCmosSensor(0x0468, 0x40); 
	CamWriteCmosSensor(0x0469, 0x30); 
	CamWriteCmosSensor(0x046A, 0x28); 
	CamWriteCmosSensor(0x046B, 0x45); 
	CamWriteCmosSensor(0x046C, 0x3A); 
	CamWriteCmosSensor(0x046D, 0x33); 
	CamWriteCmosSensor(0x046E, 0x2F); 
	CamWriteCmosSensor(0x046F, 0x49); 
	CamWriteCmosSensor(0x0470, 0x46); 
	CamWriteCmosSensor(0x0471, 0x3D); 
	CamWriteCmosSensor(0x0472, 0x30); 
	CamWriteCmosSensor(0x0473, 0x3E); 
	CamWriteCmosSensor(0x0474, 0x3D); 
	CamWriteCmosSensor(0x0475, 0x32); 
	CamWriteCmosSensor(0x0476, 0x34); 
	CamWriteCmosSensor(0x0477, 0x40); 
	CamWriteCmosSensor(0x0600, 0x00); 
	CamWriteCmosSensor(0x0601, 0x24); 
	CamWriteCmosSensor(0x0602, 0x45); 
	CamWriteCmosSensor(0x0603, 0x0E); 
	CamWriteCmosSensor(0x0604, 0x14); 
	CamWriteCmosSensor(0x0605, 0x2F); 
	CamWriteCmosSensor(0x0606, 0x01); 
	CamWriteCmosSensor(0x0607, 0x0E); 
	CamWriteCmosSensor(0x0608, 0x0E); 
	CamWriteCmosSensor(0x0609, 0x37); 
	CamWriteCmosSensor(0x060A, 0x18); 
	CamWriteCmosSensor(0x060B, 0xA0); 
	CamWriteCmosSensor(0x060C, 0x20); 
	CamWriteCmosSensor(0x060D, 0x07); 
	CamWriteCmosSensor(0x060E, 0x47); 
	CamWriteCmosSensor(0x060F, 0x90); 
	CamWriteCmosSensor(0x0610, 0x06); 
	CamWriteCmosSensor(0x0611, 0x0C); 
	CamWriteCmosSensor(0x0612, 0x28); 
	CamWriteCmosSensor(0x0613, 0x13); 
	CamWriteCmosSensor(0x0614, 0x0B); 
	CamWriteCmosSensor(0x0615, 0x10); 
	CamWriteCmosSensor(0x0616, 0x14); 
	CamWriteCmosSensor(0x0617, 0x19); 
	CamWriteCmosSensor(0x0618, 0x52); 
	CamWriteCmosSensor(0x0619, 0xA0); 
	CamWriteCmosSensor(0x061A, 0x11); 
	CamWriteCmosSensor(0x061B, 0x33); 
	CamWriteCmosSensor(0x061C, 0x56); 
	CamWriteCmosSensor(0x061D, 0x20); 
	CamWriteCmosSensor(0x061E, 0x28); 
	CamWriteCmosSensor(0x061F, 0x2B); 
	CamWriteCmosSensor(0x0620, 0x22); 
	CamWriteCmosSensor(0x0621, 0x11); 
	CamWriteCmosSensor(0x0622, 0x75); 
	CamWriteCmosSensor(0x0623, 0x49); 
	CamWriteCmosSensor(0x0624, 0x6E); 
	CamWriteCmosSensor(0x0625, 0x80); 
	CamWriteCmosSensor(0x0626, 0x02); 
	CamWriteCmosSensor(0x0627, 0x0C); 
	CamWriteCmosSensor(0x0628, 0x51); 
	CamWriteCmosSensor(0x0629, 0x25); 
	CamWriteCmosSensor(0x062A, 0x01); 
	CamWriteCmosSensor(0x062B, 0x3D); 
	CamWriteCmosSensor(0x062C, 0x04); 
	CamWriteCmosSensor(0x062D, 0x01); 
	CamWriteCmosSensor(0x062E, 0x0C); 
	CamWriteCmosSensor(0x062F, 0x2C); 
	CamWriteCmosSensor(0x0630, 0x0D); 
	CamWriteCmosSensor(0x0631, 0x14); 
	CamWriteCmosSensor(0x0632, 0x12); 
	CamWriteCmosSensor(0x0633, 0x34); 
	CamWriteCmosSensor(0x0634, 0x00); 
	CamWriteCmosSensor(0x0635, 0x00); 
	CamWriteCmosSensor(0x0636, 0x00); 
	CamWriteCmosSensor(0x0637, 0xB1); 
	CamWriteCmosSensor(0x0638, 0x22); 
	CamWriteCmosSensor(0x0639, 0x32); 
	CamWriteCmosSensor(0x063A, 0x0E); 
	CamWriteCmosSensor(0x063B, 0x18); 
	CamWriteCmosSensor(0x063C, 0x88); 
	CamWriteCmosSensor(0x0640, 0xB2); 
	CamWriteCmosSensor(0x0641, 0xC0); 
	CamWriteCmosSensor(0x0642, 0x01); 
	CamWriteCmosSensor(0x0643, 0x26); 
	CamWriteCmosSensor(0x0644, 0x13); 
	CamWriteCmosSensor(0x0645, 0x88); 
	CamWriteCmosSensor(0x0646, 0x64); 
	CamWriteCmosSensor(0x0647, 0x00); 
	CamWriteCmosSensor(0x0681, 0x1B); 
	CamWriteCmosSensor(0x0682, 0xA0); 
	CamWriteCmosSensor(0x0683, 0x28); 
	CamWriteCmosSensor(0x0684, 0x00); 
	CamWriteCmosSensor(0x0685, 0xB0); 
	CamWriteCmosSensor(0x0686, 0x6F); 
	CamWriteCmosSensor(0x0687, 0x33); 
	CamWriteCmosSensor(0x0688, 0x1F); 
	CamWriteCmosSensor(0x0689, 0x44); 
	CamWriteCmosSensor(0x068A, 0xA8); 
	CamWriteCmosSensor(0x068B, 0x44); 
	CamWriteCmosSensor(0x068C, 0x08); 
	CamWriteCmosSensor(0x068D, 0x08); 
	CamWriteCmosSensor(0x068E, 0x00); 
	CamWriteCmosSensor(0x068F, 0x00); 
	CamWriteCmosSensor(0x0690, 0x01); 
	CamWriteCmosSensor(0x0691, 0x00); 
	CamWriteCmosSensor(0x0692, 0x01); 
	CamWriteCmosSensor(0x0693, 0x00); 
	CamWriteCmosSensor(0x0694, 0x00); 
	CamWriteCmosSensor(0x0695, 0x00); 
	CamWriteCmosSensor(0x0696, 0x00); 
	CamWriteCmosSensor(0x0697, 0x00); 
	CamWriteCmosSensor(0x0698, 0x2A); 
	CamWriteCmosSensor(0x0699, 0x80); 
	CamWriteCmosSensor(0x069A, 0x1F); 
	CamWriteCmosSensor(0x069B, 0x00); 
	CamWriteCmosSensor(0x069C, 0x03); 
	CamWriteCmosSensor(0x069D, 0x01); 
	CamWriteCmosSensor(0x069E, 0x02); 
	CamWriteCmosSensor(0x069F, 0xce); 
	CamWriteCmosSensor(0x06A0, 0x1b); 
	CamWriteCmosSensor(0x06A1, 0x57); 
	CamWriteCmosSensor(0x06A2, 0x1b); 
	CamWriteCmosSensor(0x06A3, 0x1e); 
	CamWriteCmosSensor(0x06A4, 0x00); 
	CamWriteCmosSensor(0x06A5, 0x30); 
	CamWriteCmosSensor(0x06A6, 0x00); 
	CamWriteCmosSensor(0x06A7, 0x2F); 
	CamWriteCmosSensor(0x0F00, 0x00); 
	CamWriteCmosSensor(0x0F01, 0x00); 
	CamWriteCmosSensor(0x0104, 0x03); 
	CamWriteCmosSensor(0x0100, 0x01); 
	CamWriteCmosSensor(0x0460, 0x80); 
	CamWriteCmosSensor(0x0461, 0x10); 
	CamWriteCmosSensor(0x0462, 0x10);	  
	CamWriteCmosSensor(0x0463, 0x10); 
	CamWriteCmosSensor(0x0464, 0x08); 
	CamWriteCmosSensor(0x0465, 0x08);	  
	CamWriteCmosSensor(0x0466, 0x11); 
	CamWriteCmosSensor(0x0467, 0x09); 
	CamWriteCmosSensor(0x0468, 0x23); 
	CamWriteCmosSensor(0x0469, 0x2a); 
	CamWriteCmosSensor(0x046A, 0x2a); 
	CamWriteCmosSensor(0x046B, 0x47); 
	CamWriteCmosSensor(0x046C, 0x52); 
	CamWriteCmosSensor(0x046D, 0x42); 
	CamWriteCmosSensor(0x046E, 0x36); 
	CamWriteCmosSensor(0x046F, 0x46); 
	CamWriteCmosSensor(0x0470, 0x3a); 
	CamWriteCmosSensor(0x0471, 0x32); 
	CamWriteCmosSensor(0x0472, 0x32); 
	CamWriteCmosSensor(0x0473, 0x38); 
	CamWriteCmosSensor(0x0474, 0x3D); 
	CamWriteCmosSensor(0x0475, 0x2f); 
	CamWriteCmosSensor(0x0476, 0x29); 
	CamWriteCmosSensor(0x0477, 0x48); 
}

/*************************************************************************
* FUNCTION
*    GT2005PvSetting
*
* DESCRIPTION
*    This function config preview settting to sensor
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
static void GT2005PvSetting(void)
{
	CamWriteCmosSensor(0x0109, 0x00);									
	CamWriteCmosSensor(0x010B, 0x03);					
	CamWriteCmosSensor(0x0110, 0x03);					
	CamWriteCmosSensor(0x0111, 0x20);					
	CamWriteCmosSensor(0x0112, 0x02);					
	CamWriteCmosSensor(0x0113, 0x58);					
	CamWriteCmosSensor(0x0107, 0x00);					
	CamWriteCmosSensor(0x0108, 0x1C);
	CamWriteCmosSensor(0x010A, 0x04);	
	CamWriteCmosSensor(0x0116, 0x02);
	CamWriteCmosSensor(0x0118, 0x40);
	CamWriteCmosSensor(0x0119, 0x01);
	CamWriteCmosSensor(0x011a, 0x04);	
	CamWriteCmosSensor(0x011B, 0x00);					
	CamWriteCmosSensor(0x0312, 0x08);				
	CamWriteCmosSensor(0x0313, 0x28);					
	CamWriteCmosSensor(0x0200, 0x2f);										
	CamWriteCmosSensor(0x0202, 0x38);					
	CamWriteCmosSensor(0x0203, 0x00);					
	CamWriteCmosSensor(0x0204, 0x03);					
	CamWriteCmosSensor(0x0205, 0x1f);					
	CamWriteCmosSensor(0x0206, 0x0b);					
	CamWriteCmosSensor(0x0207, 0x20);					
	CamWriteCmosSensor(0x0208, 0x00);					
	CamWriteCmosSensor(0x0209, 0x2A);					
	CamWriteCmosSensor(0x020A, 0x01);										
	CamWriteCmosSensor(0x0302, 0x22);		
	CamWriteCmosSensor(0x0303, 0x06);					
	CamWriteCmosSensor(0x0400, 0xE8);					
	CamWriteCmosSensor(0x0401, 0x40);					
	CamWriteCmosSensor(0x0402, 0x00);					
	CamWriteCmosSensor(0x0403, 0x00);					
	CamWriteCmosSensor(0x0404, 0xF8);					
	CamWriteCmosSensor(0x0405, 0x03);					
	CamWriteCmosSensor(0x0406, 0x03);					
	CamWriteCmosSensor(0x0407, 0x85);					
	CamWriteCmosSensor(0x0408, 0x44);					
	CamWriteCmosSensor(0x0409, 0x1F);					
	CamWriteCmosSensor(0x040A, 0x40);					
	CamWriteCmosSensor(0x040B, 0x33);


  GT2005Sensor.PvMode = KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*    GT2005CapSetting
*
* DESCRIPTION
*    This function config capture settting to sensor
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
static void GT2005CapSetting(P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In)
{
	kal_uint16 shutter,AGain_shutter,DGain_shutter;

///////cal shutter///////////////////////////////
	CamWriteCmosSensor(0x0105, 0x00);
	CamWriteCmosSensor(0x0106, 0xf0);
  
	CamWriteCmosSensor(0x0300, 0xc1);
	
	shutter= (CamReadCmosSensor(0x0012)<<8 )|( CamReadCmosSensor(0x0013));
     
   	AGain_shutter= (CamReadCmosSensor(0x0014)<<8 )|( CamReadCmosSensor(0x0015));

	DGain_shutter= (CamReadCmosSensor(0x0016)<<8 )|( CamReadCmosSensor(0x0017));

	CamWriteCmosSensor(0x0300, 0x41); //close ALC


		//shutter = shutter / 4; ///2 1311 
	
	if(shutter<1) shutter = 1;
	
	CamWriteCmosSensor(0x0305,  shutter&0xff);           
	CamWriteCmosSensor(0x0304, (shutter >>8)&0xff); 

	CamWriteCmosSensor(0x0307,  AGain_shutter&0xff);      
	CamWriteCmosSensor(0x0306, (AGain_shutter >>8)&0xff); //AG

	CamWriteCmosSensor(0x0308,  (DGain_shutter>>2)&0xff);   //DG


///////div freq//////////////////

	CamWriteCmosSensor(0x0119, 0x01);
	CamWriteCmosSensor(0x011b, 0x00);
	
	CamWriteCmosSensor(0x011D, 0x02);
	CamWriteCmosSensor(0x011E, 0x00); 


///////configuer windows size//////////////////
	CamWriteCmosSensor(0x0109, 0x01);
	CamWriteCmosSensor(0x010A, 0x00);
	CamWriteCmosSensor(0x010B, 0x00);
	CamWriteCmosSensor(0x0110, 0x06);
	CamWriteCmosSensor(0x0111, 0x40);
	CamWriteCmosSensor(0x0112, 0x04);
	CamWriteCmosSensor(0x0113, 0xb0);

	GT2005Sensor.PvMode = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    GT2005GetSensorInfo
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
static void GT2005GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = GT2005_SENSOR_ID;
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
  Info->PreviewMclkFreq = 24000000;
  Info->CaptureMclkFreq = 24000000;
  Info->VideoMclkFreq = 24000000;
  Info->PreviewWidth = GT2005_IMAGE_SENSOR_PV_WIDTH_DRV;
  Info->PreviewHeight = GT2005_IMAGE_SENSOR_PV_HEIGHT_DRV;
  Info->FullWidth = GT2005_IMAGE_SENSOR_FULL_WIDTH_DRV;
  Info->FullHeight = GT2005_IMAGE_SENSOR_FULL_HEIGHT_DRV;
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}

#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
/*************************************************************************
* FUNCTION
*    GT2005GetEvAwbRef
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
static void GT2005GetEvAwbRef(P_SENSOR_AE_AWB_REF_STRUCT Ref)  //???
{	
    Ref->SensorAERef.AeRefLV05Shutter = 2004; //0x7d4
    Ref->SensorAERef.AeRefLV05Gain = 352; /*0x058     32x, 128 base */
    Ref->SensorAERef.AeRefLV13Shutter = 22;   //0x016
    Ref->SensorAERef.AeRefLV13Gain = 136; /*0x022,  128base */
    Ref->SensorAwbGainRef.AwbRefD65Rgain = 141; //0x11a  128 base */
    Ref->SensorAwbGainRef.AwbRefD65Bgain = 110; //0x0dc  128 base */
    Ref->SensorAwbGainRef.AwbRefCWFRgain = 117; //0x0ea  128 base */
    Ref->SensorAwbGainRef.AwbRefCWFBgain = 152; //0x130  128 base */
}
/*************************************************************************
* FUNCTION
*    GT2005GetCurAeAwbInfo
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
static void GT2005GetCurAeAwbInfo(P_SENSOR_AE_AWB_CUR_STRUCT Info)
{
	const kal_uint8 Reg26 = CamReadCmosSensor(0x0026);
 	const kal_uint8 Reg27 = CamReadCmosSensor(0x0027);
	const kal_uint8 Reg2a = CamReadCmosSensor(0x002a);
 	const kal_uint8 Reg2b = CamReadCmosSensor(0x002b);
	
    Info->SensorAECur.AeCurShutter = GT2005ReadShutter();
    Info->SensorAECur.AeCurGain = GT2005ReadGain()*4; /* 128 base */

	CamWriteCmosSensor(0x031a, 0x81); 
	CamWriteCmosSensor(0x0320, 0x24); 
	CamWriteCmosSensor(0x0321, 0x14); 
	CamWriteCmosSensor(0x0322, 0x24); 
	CamWriteCmosSensor(0x0323, 0x1a); 
	CamWriteCmosSensor(0x0441, 0x4b); 
	CamWriteCmosSensor(0x0442, 0x00); 
	CamWriteCmosSensor(0x0443, 0x00); 
	CamWriteCmosSensor(0x0444, 0x31);
	Info->SensorAwbGainCur.AwbCurRgain = (((Reg26&0x03)<<8)+Reg27)/2; //   (sensorGain/1024)*128// 
  Info->SensorAwbGainCur.AwbCurBgain = (((Reg2a&0x03)<<8)+Reg2b)/2; /* 128 base */
}

#endif


/*************************************************************************
* FUNCTION
*    GT2005PowerOn
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
static kal_uint16 GT2005PowerOn(void)
{
  kal_uint16 SensorId;
  
  CisModulePowerOn(GT2005Sensor.SensorIdx, KAL_TRUE);
  CameraSccbOpen(CAMERA_SCCB_SENSOR, GT2005_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 320);

	#if defined(DUAL_CAMERA_SUPPORT)
		TYD_Dual_Cam_PWDN_Ctrl();
	#else
		CamPdnPinCtrl(GT2005Sensor.SensorIdx, 1);
	#endif	

  //CamPdnPinCtrl(GT2005Sensor.SensorIdx, 1);
  
  CamRstPinCtrl(GT2005Sensor.SensorIdx, 1);
  kal_sleep_task(2);
  CamRstPinCtrl(GT2005Sensor.SensorIdx, 0);
  kal_sleep_task(1);
  CamRstPinCtrl(GT2005Sensor.SensorIdx, 1);
  kal_sleep_task(5);
  
  SensorId = (CamReadCmosSensor(0x0000) << 8)|CamReadCmosSensor(0x0001);
  if (SensorId != GT2005_SENSOR_ID) /* READ SENSOR ID */
  {
#if defined(__GT2005_DEBUG_TRACE__)
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "SENSOR ID: %x", SensorId);
#endif
  }
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    GT2005DetectSensorId
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
static kal_uint32 GT2005DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM GT2005SensorClose(void);
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (GT2005Sensor.SensorIdx)
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
      SensorId = GT2005PowerOn();
      GT2005SensorClose();
      if (GT2005_SENSOR_ID == SensorId)
      {
        return GT2005_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    GT2005InitOperationPara
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
static void GT2005InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 0; /* use WaitStableFrameNum instead of this */
  Para->PreviewDelayFrame = 4;
  Para->PreviewDisplayWaitFrame = 6;
#if defined(LED_FLASHLIGHT_SUPPORT)
	InitOperationPara(Para);
#endif
}

/*************************************************************************
* FUNCTION
*    GT2005Preview
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
static void GT2005Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	const kal_bool PvMode = GT2005Sensor.PvMode;
	kal_uint16 DummyPixel;

#if defined(DUAL_CAMERA_SUPPORT)
	if(isSelfCaptureOn)
		#if defined(__TYD_PRO_SUB_CAM_GT2005_MIRROR_V___)
			GT2005SetMirror(IMAGE_SENSOR_MIRROR_V);
		#else
			GT2005SetMirror(IMAGE_SENSOR_MIRROR_H);
		#endif
	else
#endif
		#if defined(__TYD_PRO_MAIN_CAM_GT2005_MIRROR_HV___) 
			GT2005SetMirror(IMAGE_SENSOR_MIRROR_HV); 
		#else
			GT2005SetMirror(IMAGE_SENSOR_MIRROR_NORMAL);
		#endif

	GT2005SetMirror(IMAGE_SENSOR_MIRROR_HV);
	GT2005PvSetting();
	
	switch(Id)
	{
		case CAL_SCENARIO_VIDEO:

			if (In->NightMode == KAL_FALSE)
			{
				CamWriteCmosSensor(0x0116, 0x02);
				CamWriteCmosSensor(0x0118, 0x67);
				CamWriteCmosSensor(0x0119, 0x02);
				CamWriteCmosSensor(0x011a, 0x04);
				CamWriteCmosSensor(0x011b, 0x01);

				CamWriteCmosSensor(0x0312, 0x08);

				CamWriteCmosSensor(0x0313, 0x34);
				CamWriteCmosSensor(0x0314, 0x30);

				CamWriteCmosSensor(0x0105, 0x00);
				CamWriteCmosSensor(0x0106, 0xF0);
				
				CamWriteCmosSensor(0x011D, 0x02);
				CamWriteCmosSensor(0x011E, 0x00);
			}
			else
			{
				CamWriteCmosSensor(0x0116, 0x02);
				CamWriteCmosSensor(0x0118, 0x67);
				CamWriteCmosSensor(0x0119, 0x05);
				CamWriteCmosSensor(0x011a, 0x04);
				CamWriteCmosSensor(0x011b, 0x02);

				CamWriteCmosSensor(0x0312, 0x08);

				CamWriteCmosSensor(0x0313, 0x32);
				CamWriteCmosSensor(0x0314, 0x18);

				CamWriteCmosSensor(0x0105, 0x00);
				CamWriteCmosSensor(0x0106, 0xF0);

				CamWriteCmosSensor(0x011D, 0x02);
				CamWriteCmosSensor(0x011E, 0x00);
			}
			
			break;
		default:
			if (In->NightMode == KAL_FALSE)
			{
				CamWriteCmosSensor(0x0116, 0x02);
				CamWriteCmosSensor(0x0118, 0x67);
				CamWriteCmosSensor(0x0119, 0x01);
				CamWriteCmosSensor(0x011a, 0x04);
				CamWriteCmosSensor(0x011b, 0x00);

				CamWriteCmosSensor(0x0312, 0xa8);

				CamWriteCmosSensor(0x0313, 0x38);
				CamWriteCmosSensor(0x0314, 0x61);

				CamWriteCmosSensor(0x0105, 0x00);
				CamWriteCmosSensor(0x0106, 0xF0);

				CamWriteCmosSensor(0x011D, 0x01);
				CamWriteCmosSensor(0x011E, 0x00);
			}
			else
			{
				CamWriteCmosSensor(0x0116, 0x02);
				CamWriteCmosSensor(0x0118, 0x67);
				CamWriteCmosSensor(0x0119, 0x01);
				CamWriteCmosSensor(0x011a, 0x04);
				CamWriteCmosSensor(0x011b, 0x00);

				CamWriteCmosSensor(0x0312, 0xD8);//BIT[4:6] FRQ

				CamWriteCmosSensor(0x0313, 0x36);
				CamWriteCmosSensor(0x0314, 0x81);

				CamWriteCmosSensor(0x0105, 0x00);
				CamWriteCmosSensor(0x0106, 0xF0);

				CamWriteCmosSensor(0x011D, 0x01);
				CamWriteCmosSensor(0x011E, 0x00);

			}
			break;
	}

/*
	if (In->NightMode == KAL_FALSE)
	{
		CamWriteCmosSensor(0x0312, 0x98);
	}
	else
	{
		CamWriteCmosSensor(0x0312, 0xa8);
	}
*/
	CamWriteCmosSensor(0x0315, CAM_BANDING_50HZ == In->BandingFreq ? 0x16 : 0x56);
#if 0
/* under construction !*/
/* under construction !*/
#else
	CamWriteCmosSensor(0x031A, 0x81);//Open AWB
	CamWriteCmosSensor(0x0300, 0x81);//Open AEC
#endif

	Out->WaitStableFrameNum = 0;
	Out->GrabStartX = GT2005_PV_X_START;
	Out->GrabStartY = GT2005_PV_Y_START;
	Out->ExposureWindowWidth = GT2005_IMAGE_SENSOR_PV_WIDTH;
	Out->ExposureWindowHeight = GT2005_IMAGE_SENSOR_PV_HEIGHT;
}


#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
/*************************************************************************
* FUNCTION
*    GT2005FullPreview
*
* DESCRIPTION
*    This function set to full size preview mode ,but 2M YUV sensor can only support to 2M size
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
static void GT2005FullPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	GT2005Sensor.Banding=In->BandingFreq;	   
	GT2005Sensor.PvMode = KAL_TRUE;
	GT2005Sensor.VideoMode = KAL_FALSE;

	GT2005SetMirror(IMAGE_SENSOR_MIRROR_HV);

	if (In->NightMode == KAL_FALSE)
	{
		CamWriteCmosSensor(0x0116, 0x02);
		CamWriteCmosSensor(0x0118, 0x67);
		CamWriteCmosSensor(0x0119, 0x01);
		CamWriteCmosSensor(0x011a, 0x04);
		CamWriteCmosSensor(0x011b, 0x00);

		CamWriteCmosSensor(0x0312, 0xa8);

		CamWriteCmosSensor(0x0313, 0x38);
		CamWriteCmosSensor(0x0314, 0x61);

		CamWriteCmosSensor(0x0105, 0x00);
		CamWriteCmosSensor(0x0106, 0xF0);

		CamWriteCmosSensor(0x011D, 0x01);
		CamWriteCmosSensor(0x011E, 0x00);
	}
	else
	{
		CamWriteCmosSensor(0x0116, 0x02);
		CamWriteCmosSensor(0x0118, 0x67);
		CamWriteCmosSensor(0x0119, 0x01);
		CamWriteCmosSensor(0x011a, 0x04);
		CamWriteCmosSensor(0x011b, 0x00);

		CamWriteCmosSensor(0x0312, 0xD8);//BIT[4:6] FRQ

		CamWriteCmosSensor(0x0313, 0x36);
		CamWriteCmosSensor(0x0314, 0x81);

		CamWriteCmosSensor(0x0105, 0x00);
		CamWriteCmosSensor(0x0106, 0xF0);

		CamWriteCmosSensor(0x011D, 0x01);
		CamWriteCmosSensor(0x011E, 0x00);
	}
	CamWriteCmosSensor(0x0109, 0x01);
	CamWriteCmosSensor(0x010A, 0x00);
	CamWriteCmosSensor(0x010B, 0x00);
	CamWriteCmosSensor(0x0110, 0x06);
	CamWriteCmosSensor(0x0111, 0x40);
	CamWriteCmosSensor(0x0112, 0x04);
	CamWriteCmosSensor(0x0113, 0xb0);
	
	//GT2005AeEnable(KAL_TRUE);
	//GT2005AwbEnable(KAL_TRUE);
	CamWriteCmosSensor(0x031A, 0x81);//Open AWB
	CamWriteCmosSensor(0x0300, 0x81);//Open AE
	Out->WaitStableFrameNum = 0;
	Out->GrabStartX = GT2005_FULL_X_START;
	Out->GrabStartY = GT2005_FULL_Y_START;
	
	Out->ExposureWindowWidth = GT2005_IMAGE_SENSOR_FULL_WIDTH;
	Out->ExposureWindowHeight = GT2005_IMAGE_SENSOR_FULL_HEIGHT;
}	
#endif


/*************************************************************************
* FUNCTION
*    GT2005Capture
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
static void GT2005Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint16 DummyPixel;
  kal_uint32 shuter_div_deno = 1;
  kal_uint32 shuter_div_num = 1;
  
  if (In->ImageTargetWidth <= GT2005_IMAGE_SENSOR_PV_WIDTH_DRV && In->ImageTargetHeight <= GT2005_IMAGE_SENSOR_PV_HEIGHT_DRV)
  {
    if (CAL_SCENARIO_WEBCAM_PREVIEW == Id || CAL_SCENARIO_WEBCAM_CAPTURE == Id) /* webcam mode */
    {
      DummyPixel = 0;
    }
    else
    {
      DummyPixel = 0;
    }

    Out->WaitStableFrameNum = 0;
    Out->GrabStartX = GT2005_PV_X_START;
    Out->GrabStartY = GT2005_PV_Y_START;
    Out->ExposureWindowWidth = GT2005_IMAGE_SENSOR_PV_WIDTH;
    Out->ExposureWindowHeight = GT2005_IMAGE_SENSOR_PV_HEIGHT;
  }
  else
  {
    kal_uint32 PvClk, PvLineLength, CapShutter, CapLineLength;
    
    /* disable ae/awb */
   // GT2005AeEnable(KAL_FALSE);
  //  GT2005AwbEnable(KAL_FALSE);

    /* back up preview clock/linelength/shutter */
    PvClk = GT2005Sensor.IntClk;
    PvLineLength = GT2005Sensor.LineLength;
    GT2005Sensor.Shutter = GT2005ReadShutter();

    GT2005CapSetting(In);

    Out->WaitStableFrameNum = 4;
    Out->GrabStartX = GT2005_FULL_X_START;
    Out->GrabStartY = GT2005_FULL_Y_START;
    Out->ExposureWindowWidth = GT2005_IMAGE_SENSOR_FULL_WIDTH;
    Out->ExposureWindowHeight = GT2005_IMAGE_SENSOR_FULL_HEIGHT;
  }
}

/*************************************************************************
* FUNCTION
*    GT2005SensorOpen
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
static MM_ERROR_CODE_ENUM GT2005SensorOpen(void)
{
  if (GT2005PowerOn() != GT2005_SENSOR_ID)
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
  GT2005InitialSetting();
  
  /* default setting */
  GT2005Sensor.BypassAe = KAL_FALSE;
  GT2005Sensor.BypassAwb = KAL_FALSE;
  GT2005Sensor.PvMode = KAL_FALSE;
  GT2005Sensor.VideoFps = 0;
  GT2005Sensor.IntClk = 0;
  GT2005Sensor.Shutter = 0;
  GT2005Sensor.Shutter = GT2005ReadShutter();
  GT2005Sensor.FrameHeight = 0;
  GT2005Sensor.LineLength = 0;
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005SensorFeatureCtrl
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

extern kal_uint16 IspFrameRateBuff[ ];

static MM_ERROR_CODE_ENUM GT2005SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  
  if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
  {
    return GT2005WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
  }
  switch (Id)
  {
    case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
	//S5K4ECGXReadShutter();
	//S5K4ECGXReadGain();
	{
		kal_print_string_trace(MOD_ENG, TRACE_WARNING, "IspFrameRateBuff%d %d ", IspFrameRateBuff[0],IspFrameRateBuff[25]);
	}
	break;
	
  /* query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = GT2005Ev(In, Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = GT2005Wb(In, Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = GT2005Effect(In, Out);
    break;
#ifdef  __ZERO_SHUTTER_DELAY_SUPPORT__
  case CAL_FEATURE_CAMERA_ZSD_CAPTURE_SIZE:
#endif
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = GT2005StillCaptureSize(In, Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ:
    ErrCode = GT2005Banding(In, Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = GT2005SceneMode(KAL_TRUE, In, Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = GT2005SceneMode(KAL_FALSE, In, Out);
    break;
#if defined(LED_FLASHLIGHT_SUPPORT)
/* YUV flash light support series */
    case CAL_FEATURE_CAMERA_FLASH_MODE:
        ErrCode = Flashmodel(In, Out);
        break;
    case IMAGE_SENSOR_FEATURE_QUERY_YUV_CTRL_FLASHLIGHT_TRIGGER_MODE:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = FLASHLIGHT_CONTINUOUS_MODE;
        break;
    case IMAGE_SENSOR_FEATURE_SET_YUV_CTRL_FLASHLIGHT_TRIGGER_MODE:
        break;
    case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
        FlashlightPowerOn(GT2005Sensor.SensorIdx, ((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)In)->FeatureEnable);
        break;
    case IMAGE_SENSOR_FEATURE_YUV_CHECK_IF_TRIGGER_FLASHLIGHT:
        ((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)Out)->FeatureEnable = FlashTriggerCheck();
        break;
#else
    case CAL_FEATURE_CAMERA_FLASH_MODE:
         ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
         break;
#endif    
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    GT2005GetSensorInfo(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GT2005DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GT2005Sensor.VideoFps;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    GT2005InitOperationPara(Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    CamGetHWInfo(GT2005Sensor.SensorIdx, Out);
    break;
  
  /* set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(GT2005Sensor.SensorIdx, 0);
    CamRstPinCtrl(GT2005Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    GT2005Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    GT2005Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
//    GT2005Sensor.BypassAe = *(kal_bool *)In;
//    GT2005AeEnable(GT2005Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
    break;
  case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
//    GT2005Sensor.BypassAwb = *(kal_bool *)In;
//    GT2005AwbEnable(GT2005Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
    break;

// ASD support
//ASD function support
#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
	 case IMAGE_SENSOR_FEATURE_GET_EV_AWB_REF:
	   GT2005GetEvAwbRef(Out);
	   break;
	 case IMAGE_SENSOR_FEATURE_GET_SHUTTER_GAIN_AWB_GAIN:
	   GT2005GetCurAeAwbInfo(Out);
	   break;
	 case IMAGE_SENSOR_FEATURE_SET_SCENE_ENHANCE:
	   {
		 CAL_FEATURE_CTRL_STRUCT Para;
   
		 Para.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
		 Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneContrast;
		 GT2005Contrast(&Para,NULL);
		 Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSaturation;
		 GT2005Saturation(&Para,NULL);
		 Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSharpness;
		 GT2005Sharpness(&Para,NULL);
	   }
	   break;
 #endif


  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}

/*************************************************************************
* FUNCTION
*    GT2005SensorCtrl
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
static MM_ERROR_CODE_ENUM GT2005SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    GT2005Preview(Id, In, Out);
    break;
#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
  case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
	GT2005FullPreview(Id, In, Out);
	break;
#endif
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    GT2005Capture(Id, In, Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005SensorClose
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
static MM_ERROR_CODE_ENUM GT2005SensorClose(void)
{
  CamPdnPinCtrl(GT2005Sensor.SensorIdx, 0);
  CamRstPinCtrl(GT2005Sensor.SensorIdx, 0);
  CisModulePowerOn(GT2005Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    GT2005SensorFunc
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
IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncGT2005 =
	{
		GT2005SensorOpen,
		GT2005SensorFeatureCtrl,
		GT2005SensorCtrl,
		GT2005SensorClose,
	};
MM_ERROR_CODE_ENUM GT2005SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{

	kal_uint16 sensors_id;
	
	*pfSensorFunc = &ImageSensorFuncGT2005;
	
    return MM_ERROR_NONE;
}