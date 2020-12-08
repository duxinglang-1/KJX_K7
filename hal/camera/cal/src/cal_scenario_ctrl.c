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
 *   cal_main.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   CAL interface
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "stack_timer.h"

#include "cal_api.h"
#include "cal_if.h"
#include "cal_drv_features.h"
#include "cal_task_msg_if.h"

#include "sensor_comm_def.h"
#include "image_sensor.h"
#include "isp_if.h"
#include "idp_cam_if.h"

#include "pp_api.h"
#include "pp_comm_def.h"
#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */

#include "Cct_comm_def.h"

#include "jpeg_mem.h"
#include "idp_mem_def.h"
#include "isp_mem.h"
#include "pp_mem_def.h"
#include "jaia_mem.h"
#include "cal_mem_def.h"
#include "mpl_recorder.h"
#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
#include "feature_comm_def.h"
#endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
#if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
#include "isp_comm_def.h"
#endif //__ZERO_SHUTTER_DELAY_SUPPORT__

#include "drv_features.h"
#include "drv_sw_features_mdp.h"

#include "sensor_frame_rate_lut.h"
//#include "wfc\wfc.h" // The include path is "mcu\interface\hal\display\api"
#include "wfc\inc\wfc_mm_api.h"     // The include path is "mcu\hal\display\wfc\inc"
#include "common\owftypes.h" // The include path is "mcu\interface\hal\display\api"
#include "common\owfnativestream.h" // The include path is "mcu\interface\hal\display\api"
#include "Owfimage.h"

#include "cache_sw.h"   /* For dynamic switch cacheability */
#include "mmu.h"        /* For dynamic switch cacheability */

#if defined(__RF_DESENSE_TEST__)
#include "rf_desense_test.h"
#endif

// That I can turn it all off here...
#ifndef CAL_DD_ASSERT
#define CAL_DD_ASSERT(_expr_) ASSERT(_expr_)
#endif

#include "lcd_sw_inc.h"
#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
#include "lcd_if_hw.h"
extern WFD_LCD_DC_ENGINE_ENUM __wfd_lcd_dc_engine;
#endif

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__))
#include "mav_encoder.h"
#include "mav_mem.h"
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif

P_ISP_SCENARIO_CTRL_STRUCT pIspScenarioCtrl=(P_ISP_SCENARIO_CTRL_STRUCT) CalFeatureCtrlBuff1;
P_ISP_FEATURE_GET_OUTPUT_RESOLUTION_IN_STRUCT pIspGetOutResParaIn=(P_ISP_FEATURE_GET_OUTPUT_RESOLUTION_IN_STRUCT) CalFeatureCtrlBuff1;
P_ISP_FEATURE_GET_OUTPUT_RESOLUTION_OUT_STRUCT pIspGetOutResParaOut=(P_ISP_FEATURE_GET_OUTPUT_RESOLUTION_OUT_STRUCT) CalFeatureCtrlBuff2;
IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT SensorScenarioParaIn;
IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT SensorScenarioParaOut;
ISP_FEATURE_CURRENT_ZOOM_INFO_STRUCT CurrentZoomInfo;
//ISP_FEATURE_SET_TG_STRUCT IspTgSettingInfo;
CAL_MDP_PREVIEW_STRUCT CalPreviewInfo;
CAL_MDP_STILL_CAPTURE_STRUCT CalStillCaptureInfo;
CAL_MDP_VIDEO_STRUCT CalVideoInfo;
CAL_SCENARIO_ENUM CurrentStillScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;

// MDP
kal_uint32 IdpCalKey;
Camera_Capture_Idp_Cal_Struct MdpStillCapturePara;
MM_IMAGE_ROTATE_ENUM MdpDisplayImageRotAngle;
MM_IMAGE_ROTATE_ENUM DisplayImageSrcRotAngle;

kal_uint32 QuickViewImageDestBuffAddr;

#ifndef __CAL_MINIMIZE_GLOBAL_VARIABLE__
Camera_Preview_Idp_Cal_Struct MdpPreviewPara;
Video_Encode_Idp_Cal_Struct MdpVideoPara;
Mjpeg_Encode_Idp_Cal_Struct MdpMjpegVideoPara;
#endif
kal_bool MjpegVideoEnable=KAL_FALSE;

// JPEG encoder
JPEG_ENCODER_HANDLE JpegWrapperHandle;
JPEG_WRAPPER JpegWrapper;
kal_uint8 *pJpegEncodedDataAddr;
kal_uint32 JpegEncodedDataSize;

// Display
kal_bool DisplayPreviewFrameFlag=KAL_FALSE;
MM_IMAGE_ROTATE_ENUM DisplayImageRotAngle=MM_IMAGE_ROTATE_0;

WFCDevice CalDisplayDevice = WFC_INVALID_HANDLE;
WFCContext CalDisplayContext = WFC_INVALID_HANDLE;
WFCElement CalDisplayElement = WFC_INVALID_HANDLE;
WFCSource CalDisplaySource = WFC_INVALID_HANDLE;
WFCSource CalDisplayImgSource = WFC_INVALID_HANDLE;
OWFNativeStreamType CalDisplayStream = OWF_INVALID_HANDLE;
kal_uint32 CalDisplayFBs[3][2] = { 0 };
kal_uint32 Newest_FrameBuf_Addr = 0;

// JAIA
kal_uint32 CurrentStillCaptureStatus=0;     // to keep how many images (main/quick view/thumbnail) are ready for still capture
kal_uint32 CurrentStillCaptureMask=0;       // to keep how many images (main/quick view/thumbnail) has to be captured

// VAL
kal_uint32 VideoRotBuffAddr;
MPL_BUFFER_INFO_T MplBuffInfo={NULL, 0, MPL_OK, 0};

// CCT
CAL_CCT_SCENARIO_PARA_STRUCT CctScenarioParaSet = {KAL_FALSE};

//sensor frame rate lut
//SENSOR_FRAMERATE_IN_STRUCT    SensorQueryFrameRateIn;
//SENSOR_FRAMERATE_OUT_STRUCT   SensorQueryFrameRateOut;

#if (defined(__JPEG_SENSOR_SUPPORT__))
extern IMAGE_SENSOR_CAPTURE_FORMAT_STRUCT CaptureFormatInfo;
kal_uint8 CalJpegCaptureRetry;

kal_uint32 CalJpegCaptureBufferSize[CAM_IMAGE_SIZE_NOT_SUPPORT] =
{
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_OTHER,    //CAM_IMAGE_SIZE_WALLPAPER=0,
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_VGA,    //CAM_IMAGE_SIZE_QVGA,
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_VGA,    //CAM_IMAGE_SIZE_VGA,/* 300KB for VGA */
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_1M,    //CAM_IMAGE_SIZE_1M, /* 896KB for 1.3M *
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_2M,    //CAM_IMAGE_SIZE_2M, /* 1536KB for 2M */
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_3M,    //CAM_IMAGE_SIZE_3M, /* 2048KB for 3M */
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_4M,    //CAM_IMAGE_SIZE_4M, /* 3072KB for 5M */
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_5M,    //CAM_IMAGE_SIZE_5M, /* 5600KB for 8M */
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_8M,    //CAM_IMAGE_SIZE_8M,
  MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_OTHER,    //CAM_IMAGE_SIZE_OTHER,
};
#endif

#ifdef __CAL_NEED_SW_ROTATE__
// for sw rotate only, we need to use software rotation to avoid tearing by HW LCD rotate
MM_IMAGE_ROTATE_ENUM ImageSwRotateAngleForDisplay = MM_IMAGE_ROTATE_0;
#endif

kal_bool CalPanoEnabled = KAL_FALSE;

#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
//Pano
CAL_PANO_POSTPROC_STRUCT CalPanoPostProcPara;
CAL_PANO_STATE_ENUM CalPanoState = CAL_PANO_STANDBY_STATE;
kal_bool PauseAfterStitchFinished=KAL_FALSE;
kal_bool IsPanoPaused=KAL_FALSE;
//extern CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT MainImageResizePara;
#endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__

#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
//Hdr
kal_bool CalHdrEnabled = KAL_FALSE;
kal_bool CalHdrUseSwEncoder = KAL_FALSE;
kal_bool CalHdrUseSwDecoder = KAL_FALSE;
kal_bool IsHdrAborted=KAL_FALSE;
kal_bool CalHdrQviDitheringOn = KAL_FALSE;
CAL_MDP_POSTPROC_STRUCT CalMdpPostProcPara;
CAL_HDR_STATE_ENUM CalHdrState = CAL_HDR_IDLE_STATE;
CAL_JPEG_DECODE_STRUCT CalHdrJpegDecodePara;
extern CAMERA_POST_PROCESS_PARA_STRUCT PpTuningOperPara;
#endif  //__HIGH_DYNAMIC_RANGE_SUPPORT__

#if defined(__AUTO_SCENE_DETECT_SUPPORT__)
//Asd
kal_bool CalAsdEnabled = KAL_FALSE;
CAL_CAMERA_SCENE_MODE_ENUM CalAsdSceneType = CAM_AUTO_DSC;
CAL_CAMERA_SCENE_MODE_ENUM CalAsdBackupSceneType = CAM_AUTO_DSC;
ISP_CAMERA_AWB_AF_REF_STRUCT IspAwbAfRefBuff;
ISP_CAMERA_INFO_3A_STRUCT IspInfoAaaBuff;
ISP_CAMERA_SCENE_COMPENSATION_STRUCT IspSceneCompensationParaIn;
//kal_uint8 CalAsdFaceLuminance = 0;
#endif  //__AUTO_SCENE_DETECT_SUPPORT__

#ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
MM_IMAGE_ROTATE_ENUM SwVideoRotAngle=MM_NO_OF_IMAGE_ROTATE;
#endif

#if (defined(__CAL_CAMERA_OVERLAY_SUPPORT__) && (defined(__LCM_SCANLINE_ROTATION_SUPPORT__)))
    MM_IMAGE_ROTATE_ENUM StillImageOverlayRotateAngle=MM_IMAGE_ROTATE_0;
#endif

#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
kal_bool IsZsdScenario=KAL_FALSE;
#endif
// map the MM_IMAGE_ROTATE_ENUM to exif orientation definition
kal_uint8 ExifOrientationMapTable[MM_NO_OF_IMAGE_ROTATE]={1, 6, 3, 8, 2, 5, 4, 7};

#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
CAL_CAMERA_IMAGE_EFFECT_ENUM CalImageEffect = CAM_EFFECT_ENC_NORMAL;
kal_bool CalImageEffectEnable = KAL_FALSE;
#endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

MM_IMAGE_ROTATE_ENUM PpMainImageRotAngle=MM_IMAGE_ROTATE_0;

//Mav & 3D Image
#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
WFCDevice CalMavDisplayDevice = WFC_INVALID_HANDLE;
WFCContext CalMavDisplayContext = WFC_INVALID_HANDLE;
WFCElement CalMavDisplayElement = WFC_INVALID_HANDLE;
CAL_ISP_PREVIEW_STRUCT CalMavIspPreviewPara = {0};
kal_bool CalMavEnabled=KAL_FALSE;
CAL_MAV_STATE_ENUM CalMavState=CAL_MAV_STANDBY_STATE;
CAL_MAV_POSTPROC_STRUCT CalMavPostProcPara = {0};
kal_bool IsMavReadyToShot=KAL_FALSE;
kal_bool CalMav3DImageMode = KAL_FALSE;
kal_int16 CalMavMV[2]={0,0};
kal_uint16 CalMavSrcImageWidth;
kal_uint16 CalMavSrcImageHeight;
kal_uint16 CalMavResizeImageWidth;
kal_uint16 CalMavResizeImageHeight;
kal_uint32 CalMavResizeImageBufferAddr;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
MAV_ENCODER_HANDLE MavEncWrapperHandle;
MAV_ENC_WRAPPER MavEncWrapper;
#endif
kal_uint8 CalMavCaptureTimeoutFrameCount=0;
#endif

//Camera Gyro
#if defined(__CAMERA_GYRO_SUPPORT__)
kal_bool CalCamGyroEnabled = KAL_FALSE;
kal_uint32 CalCamGyroCopyBuffAddr = 0;
#endif

#if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
CAL_CAMERA_STILL_CAPTURE_ENUM CalStillCaptureMode;
#endif

kal_uint32 CalExtraQVIBuffAddr = NULL;
kal_uint32 CalExtraQVIBuffSize;


#if defined(__JPEG_SENSOR_SUPPORT__) || defined(__POSTPROC_SUPPORT__)
kal_bool CalExtMemSwitchCachableRegion(kal_uint32 *pMemAddr, kal_uint32 BufferSize, kal_bool CacheableFlag)
{
    kal_bool Ret = KAL_FALSE;
#if (defined(__MTK_TARGET__)&&(defined(__ARM9_DCACHEABLE__)||defined(__DYNAMIC_SWITCH_CACHEABILITY__)))
    kal_uint8   RemainBits;

    // size alignment
    if((BufferSize%CPU_CACHE_LINE_SIZE) != 0)
    {
        BufferSize = ((BufferSize+CPU_CACHE_LINE_SIZE-1)/CPU_CACHE_LINE_SIZE)*CPU_CACHE_LINE_SIZE;
    }

    // addr alignment
     RemainBits =  (*pMemAddr & (0x1f));
    *pMemAddr &= (~0x1f);
    if(CacheableFlag == KAL_TRUE)
    {
        if(INT_QueryIsNonCachedRAM(*pMemAddr, BufferSize) == KAL_TRUE)
        {
            dynamic_switch_cacheable_region((void*)pMemAddr, BufferSize, PAGE_CACHEABLE);
            Ret = KAL_TRUE;
        }
    }
    else
    {
        if(INT_QueryIsCachedRAM(*pMemAddr, BufferSize) == KAL_TRUE)
        {
            dynamic_switch_cacheable_region((void*)pMemAddr, BufferSize, PAGE_NO_CACHE);
            Ret = KAL_TRUE;
        }
    }
    *pMemAddr |= RemainBits;
#endif  // __MTK_TARGET__ && (__ARM9_DCACHEABLE__ || __DYNAMIC_SWITCH_CACHEABILITY__)
    return Ret;
}
#endif

#if (defined(__POSTPROC_SUPPORT__))
//PP
kal_bool PostProcImageFromDisplayImage=KAL_FALSE;
 PP_FEATURE_CONFIG_INFO_STRUCT      PpFeatureConfigPara;
kal_bool gMdpPostProcTrigger = KAL_TRUE;    /* reduce dummy PpCtrl() calls in MdpCallback to optimize SD capture performance */
#endif /* defined(__POSTPROC_SUPPORT__) */

#if defined(__JPEG_SENSOR_SUPPORT__)
extern JPEG_SENSOR_SRC_BUFFER_STRUCT JpegSensorParaIn;
extern JPEG_SENSOR_PARSE_DATA_STRUCT JpegSensorParaOut;
#endif


JPEG_YUV_FORMAT_ENUM GetJpegWrapperFormat(MM_IMAGE_FORMAT_ENUM ImageFormat)
{
    JPEG_YUV_FORMAT_ENUM JpegYuvFormat=JPEG_YUV_FORMAT_YUV420;

    switch (ImageFormat)
    {
        case MM_IMAGE_FORMAT_YUV420:
            JpegYuvFormat=JPEG_YUV_FORMAT_YUV420;
        break;
        case MM_IMAGE_FORMAT_YUV422:
            JpegYuvFormat=JPEG_YUV_FORMAT_YUV422;
        break;
        default:
            ASSERT(0);
        break;
    }

    return JpegYuvFormat;
}   /* GetJpegWrapperFormat() */

MM_IMAGE_ROTATE_ENUM GetRestRotAngle(MM_IMAGE_ROTATE_ENUM DesiredRotAngle,
                                     MM_IMAGE_ROTATE_ENUM AlreadyRotAngle)
{
    MM_IMAGE_ROTATE_ENUM RestRotAngle=MM_IMAGE_ROTATE_0;

    if (DesiredRotAngle<MM_IMAGE_H_MIRROR)
    {
        if (AlreadyRotAngle<MM_IMAGE_H_MIRROR)
        {
            RestRotAngle = (MM_IMAGE_ROTATE_ENUM) (DesiredRotAngle + MM_IMAGE_H_MIRROR - AlreadyRotAngle);
            RestRotAngle %= MM_IMAGE_H_MIRROR;
        }
        else
        {
            RestRotAngle = (MM_IMAGE_ROTATE_ENUM) (AlreadyRotAngle - DesiredRotAngle);
            RestRotAngle %= MM_IMAGE_H_MIRROR;
            RestRotAngle += MM_IMAGE_H_MIRROR;
        }
    }
#if 1//def __CAL_DUAL_CAMERA_SUPPORT__  // only front camera need to do H mirror
    else if (DesiredRotAngle<MM_NO_OF_IMAGE_ROTATE)
    {
        if (AlreadyRotAngle<MM_IMAGE_H_MIRROR)
        {
            RestRotAngle = (MM_IMAGE_ROTATE_ENUM) (DesiredRotAngle - AlreadyRotAngle);
            RestRotAngle %= MM_IMAGE_H_MIRROR;
            RestRotAngle += MM_IMAGE_H_MIRROR;
        }
        else
        {
            RestRotAngle = (MM_IMAGE_ROTATE_ENUM)(AlreadyRotAngle + MM_IMAGE_H_MIRROR - DesiredRotAngle) ;
            RestRotAngle %= MM_IMAGE_H_MIRROR;
        }
    }
#endif
    else
        ASSERT(0);

    return RestRotAngle;
}   /* GetRestRotAngle() */

MM_ERROR_CODE_ENUM ConfigIspGetResPara(kal_uint16 ZoomStep, kal_uint16 TargetWidth, kal_uint16 TargetHeight,
                                       CAL_CAMERA_DIGITAL_ZOOM_TYPE_ENUM DzType)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    kal_uint32 FeatureOutLen;

        pIspGetOutResParaIn->ZoomStep=ZoomStep;
        pIspGetOutResParaIn->SensorImageGrabStartX=SensorScenarioParaOut.GrabStartX;
        pIspGetOutResParaIn->SensorImageGrabStartY=SensorScenarioParaOut.GrabStartY;
        pIspGetOutResParaIn->SensorImageWidth=SensorScenarioParaOut.ExposureWindowWidth;
        pIspGetOutResParaIn->SensorImageHeight=SensorScenarioParaOut.ExposureWindowHeight;
        pIspGetOutResParaIn->WaitStableFrameNum=SensorScenarioParaOut.WaitStableFrameNum;
        pIspGetOutResParaIn->TargetWidth=TargetWidth;
        pIspGetOutResParaIn->TargetHeight=TargetHeight;
        pIspGetOutResParaIn->DzType=DzType;
        pIspGetOutResParaIn->pZoomFactorListTable=CurrentDzInfo.pZoomFactorListTable;
        ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_OUTPUT_RESOLUTION, pIspGetOutResParaIn,
                                            pIspGetOutResParaOut, sizeof(ISP_FEATURE_GET_OUTPUT_RESOLUTION_OUT_STRUCT),
                                            &FeatureOutLen);
    return ErrorCode;
}   /* ConfigIspGetResPara() */

void SaveDisplyHandle(P_CAL_LCD_STRUCT pLcdPara)
{
    CalDisplayDevice = pLcdPara->WfcDeviceHandle;
    CalDisplayContext = pLcdPara->WfcContextHandle;
    CalDisplayElement = pLcdPara->WfcElementHandle;
}   /* SaveDisplyHandle() */

MM_IMAGE_ROTATE_ENUM GetSensorRotAngle(MM_IMAGE_ROTATE_ENUM ImageRotAngle,
                                       img_rot_angle_enum_t *MdpRotAngle,
                                       IMAGE_SENSOR_MIRROR_ENUM *SensorMirror)
{
    MM_IMAGE_ROTATE_ENUM SensorRotate;

    switch (ImageRotAngle)
    {
        case MM_IMAGE_ROTATE_180:
            *MdpRotAngle= (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
            *SensorMirror = IMAGE_SENSOR_MIRROR_HV;
            SensorRotate = MM_IMAGE_ROTATE_180;
        break;
        case MM_IMAGE_ROTATE_270:
            *MdpRotAngle = (img_rot_angle_enum_t) MM_IMAGE_ROTATE_90;
            *SensorMirror = IMAGE_SENSOR_MIRROR_HV;
            SensorRotate = MM_IMAGE_ROTATE_180;
        break;
    #ifdef __CAL_DUAL_CAMERA_SUPPORT__
        case MM_IMAGE_H_MIRROR_ROTATE_90:
            *MdpRotAngle = (img_rot_angle_enum_t) MM_IMAGE_ROTATE_270;
            *SensorMirror = IMAGE_SENSOR_MIRROR_H;
            SensorRotate = MM_IMAGE_H_MIRROR;
        break;
        case MM_IMAGE_H_MIRROR_ROTATE_180:
            *MdpRotAngle = (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
            *SensorMirror = IMAGE_SENSOR_MIRROR_V;
            SensorRotate = MM_IMAGE_H_MIRROR_ROTATE_180;
        break;
        case MM_IMAGE_H_MIRROR_ROTATE_270:
            *MdpRotAngle = (img_rot_angle_enum_t) MM_IMAGE_ROTATE_90;
            *SensorMirror = IMAGE_SENSOR_MIRROR_H;
            SensorRotate = MM_IMAGE_H_MIRROR;
        break;
        case MM_IMAGE_H_MIRROR:
            *MdpRotAngle = (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
            *SensorMirror = IMAGE_SENSOR_MIRROR_H;
            SensorRotate = MM_IMAGE_H_MIRROR;
        break;
    #endif
        default :
            *MdpRotAngle = (img_rot_angle_enum_t) ImageRotAngle;
            *SensorMirror = IMAGE_SENSOR_MIRROR_NORMAL;
            SensorRotate = MM_IMAGE_ROTATE_0;
        break;
    }

#ifdef __CAL_MATV_SUPPORT__
    if (CurrentCameraId == CAL_CAMERA_SOURCE_MATV)
    {
        *MdpRotAngle = (img_rot_angle_enum_t) ImageRotAngle;
        *SensorMirror = IMAGE_SENSOR_MIRROR_NORMAL;
        SensorRotate = MM_IMAGE_ROTATE_0;
    }
#endif

    return SensorRotate;
}

#if !defined(DRV_IDP_6252_SERIES)
// function to get Multimedia Display Image format
// Input: DisplayImageFormat for MM color format, *image_format to write result
// Output: bpp value for the color format
OWFint GetMMDisplayImageFMT(MM_IMAGE_FORMAT_ENUM DisplayImageFormat,
                                     OWF_IMAGE_FORMAT *image_format)
{
    OWFint pixel_size = 0;
    image_format->linear = OWF_FALSE;
    image_format->premultiplied = OWF_FALSE;
    image_format->rowPadding = 0;

    switch(DisplayImageFormat)
    {
    case MM_IMAGE_FORMAT_RGB565:
      image_format->pixelFormat= OWF_IMAGE_RGB565;
      pixel_size = 2;
    break;

    case MM_IMAGE_FORMAT_RGB888:
      image_format->pixelFormat = OWF_IMAGE_RGB888;
      pixel_size = 3;
    break;

    case MM_IMAGE_FORMAT_BGR888:
      image_format->pixelFormat = OWF_IMAGE_BGR888;
      pixel_size = 3;
    break;

    case MM_IMAGE_FORMAT_ARGB888:
      image_format->pixelFormat = OWF_IMAGE_ARGB8888;
      pixel_size = 4;
    break;

    case MM_IMAGE_FORMAT_PACKET_UYVY422:
      image_format->pixelFormat = OWF_IMAGE_UYVY;
      pixel_size = 2;
    break;

    default:
      CAL_DD_ASSERT(0);
    break;
    }
    return pixel_size;
}
#endif


#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
/* When sensor or MATV dead with ESD, MMI will hang because wait LCD blt when auto mode and no data in.
   To config LCD sync to timer will finish MMI blt and have change to reset sensor or MATV */
void CalLcdFroceAutoUpdate()
{
    wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_TIMER);
    wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);

    // Commmit
    wfcMMCommit(CalDisplayDevice, CalDisplayContext, CalDisplayElement, WFC_COMMIT_CONTEXT_AND_ELEMENT);
}
#endif


#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
kal_uint32 WfcDisplayCB = NULL;
#endif
void CameraImageDisplayConfig(kal_uint32 CtrlCode, MM_IMAGE_FORMAT_ENUM DisplayImageFormat,
                              MM_IMAGE_ROTATE_ENUM MdpRotAngle,
                              WFCint DisplayInputWidth, WFCint DisplayInputHeight,
                              kal_uint32 FrameBuffAddr1, kal_uint32 FrameBuffAddr2, kal_uint32 FrameBuffAddr3)
{
#if (defined(__MTK_TARGET__))
    WFCint displayInputWidth, displayInputHeight;
#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
    kal_bool triple_display_buffer_support = KAL_FALSE;
#endif

    if (CAL_CTRL_CODE_STOP & CtrlCode)
    {
        if (OWF_INVALID_HANDLE != CalDisplayStream)
        {
            if ((WFC_INVALID_HANDLE == CalDisplayDevice) ||
                (WFC_INVALID_HANDLE == CalDisplayContext) ||
                (WFC_INVALID_HANDLE == CalDisplayElement))
            {
                CAL_DD_ASSERT(0);
            }

        #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            if (NULL != CalDisplayFBs[2][0])
            {
                triple_display_buffer_support = KAL_TRUE;
            }
        #endif

#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
            //if (CurrentScenarioId==CAL_SCENARIO_VIDEO || CurrentScenarioId==CAL_SCENARIO_VIDEO_TELEPHONY)
            if (CurrentScenarioId==CAL_SCENARIO_VIDEO)
            {
                wfcMMSetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_DC_LAYER_MTK, WFC_FALSE);
            }
#endif  // #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)

        #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            // Remove previously registed MDP cb function
            if (NULL != WfcDisplayCB)
            {
                WFCint array[4];

                array[0] = (WFCint) WFC_CONTEXT_EVENT_REALSE_READ_BUFFER_DONE_CALLBACK_MTK;
                array[1] = (WFCint) WfcDisplayCB;
                array[2] = (WFCint) WFC_NONE;
                array[3] = (WFCint) WFC_FALSE;
                wfcMMSetContextAttribiv(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
                WfcDisplayCB = NULL;
            }
        #endif

            // set sync mode for auto mode
            {
                wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_TIMER);
                wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 0);
                wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) 0);
                wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
            }

            // Set an image source back to element
            {
              OWF_IMAGE image;

              // destroy previous image source if existed
              if (CalDisplayImgSource != WFC_INVALID_HANDLE)
              {
                wfcDestroySource(CalDisplayDevice, CalDisplayImgSource);
              }
              // TODO: buffer address refer to CalDisplayFBs[?][1] == 0x0
              // TODO: fill in this structure

              // MAUI_02907760 always insert FrameBuffAddr1 for display
              // CAL will pass APP frame buffer address by FrameBuffAddr1
              // APP's frame buffer won't be free unless stop process is done
              image.data = (void*)FrameBuffAddr1;

              {
                if (MdpRotAngle & 0x01)
                {
                  image.width = DisplayInputHeight;
                  image.height = DisplayInputWidth;
                }
                else
                {
                  image.width = DisplayInputWidth;
                  image.height = DisplayInputHeight;
                }

#if defined(DRV_IDP_6252_SERIES)
                image.format.linear = OWF_FALSE;
                image.format.premultiplied = OWF_FALSE;
                image.format.rowPadding = 0;
                image.format.pixelFormat = OWF_IMAGE_UYVY;
                image.pixelSize = 2;
#else
                // get image fo format and pixel size
                image.pixelSize = GetMMDisplayImageFMT(DisplayImageFormat, &image.format);
#endif
                image.foreign = OWF_TRUE; // don't care.
                image.alpha = 0xFF;
                image.stride = image.width * image.pixelSize; /**< number of bytes per line */
                image.dataMax = image.stride * image.height; /* data buffer max size */

                // MAUI_02907760 always use FrameBuffAddr1 for display image because first buffer is bring from MMI
                // if last frame is 2nd or 3rd buffer, copy contain to 1st buffer
                {
                    kal_uint8* dst_addr;
                    kal_uint8* src_addr;
                    // this case is for ZSD shot, FrameBuffAddr1(from APP) is different from CalDisplayFBs[0][0](from MED)
                    // we should copy the latest frame buffer content to FrameBuffAddr1 because
                    // CalDisplayFBs[0][0] will be freed after capture done.
                    if (Newest_FrameBuf_Addr == 0x0)
                    {
                        if (FrameBuffAddr1 != CalDisplayFBs[0][0])
                        {
                            dst_addr= (kal_uint8*)FrameBuffAddr1;
                            src_addr= (kal_uint8*)CalDisplayFBs[0][0];
                            kal_mem_cpy(dst_addr, src_addr, image.dataMax);
                        }
                    }
                    else
                    {
                        dst_addr= (kal_uint8*)FrameBuffAddr1;
                        src_addr= (kal_uint8*)Newest_FrameBuf_Addr;
                        if (dst_addr != src_addr)
                        {
                            kal_mem_cpy(dst_addr, src_addr, image.dataMax);
                        }
                    }
                }

                CalDisplayImgSource = wfcCreateSourceFromImage(CalDisplayDevice, CalDisplayContext, (WFCHandle) &image, NULL);
                CAL_DD_ASSERT(CalDisplayImgSource != WFC_INVALID_HANDLE);
                wfcMMSetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_SOURCE, CalDisplayImgSource);
                wfcMMCommit(CalDisplayDevice, CalDisplayContext, CalDisplayElement, WFC_COMMIT_CONTEXT_AND_ELEMENT);
              }
            }
            wfcDestroySource(CalDisplayDevice, CalDisplaySource);

            owfNativeStreamDestroy(CalDisplayStream);
            CalDisplayStream = OWF_INVALID_HANDLE;

            kal_mem_set((void*) CalDisplayFBs, 0x0, sizeof(kal_uint32)*3*2);
        }
    }

    if (CAL_CTRL_CODE_START & CtrlCode)
    {
        // TODO: [m] Which variable can decide if display needs to work?
        if ((((CAL_SCENARIO_VIDEO == CurrentScenarioId)
            #ifdef __MEDIA_VT__
/* under construction !*/
            #endif
              ) &&
             (KAL_TRUE == CalVideoInfo.LcdUpdateEnable)) ||
            (((CAL_SCENARIO_CAMERA_PREVIEW == CurrentScenarioId)
            #ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
               ||(CAL_SCENARIO_CAMERA_ZSD_PREVIEW == CurrentScenarioId)
            #endif
            #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__) || defined(__3D_IMAGE_SUPPORT__))
               ||(CAL_SCENARIO_CAMERA_MAV_CAPTURE == CurrentScenarioId)
            #endif
              ) &&
             (KAL_TRUE == CalPreviewInfo.LcdUpdateEnable))
            #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
              ||(CAL_SCENARIO_VIDEO_MJPEG == CurrentScenarioId)
            #endif
             )
        {
            if ((WFC_INVALID_HANDLE == CalDisplayDevice) ||
                (WFC_INVALID_HANDLE == CalDisplayContext) ||
                (WFC_INVALID_HANDLE == CalDisplayElement))
            {
                CAL_DD_ASSERT(0);
            }

        #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            if (NULL != FrameBuffAddr3)
            {
              triple_display_buffer_support = KAL_TRUE;
            }
        #endif

            // Check if this element is a video layer...for debug only and can be removed for last QC stage...
            if (WFC_FALSE == wfcGetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_VIDEO_LAYER_MTK))
            {
                // TODO: [m] Make GDI add this line...
                wfcMMSetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_VIDEO_LAYER_MTK, WFC_TRUE);
            }

#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
            //if (CurrentScenarioId==CAL_SCENARIO_VIDEO || CurrentScenarioId==CAL_SCENARIO_VIDEO_TELEPHONY)
            if (CurrentScenarioId==CAL_SCENARIO_VIDEO)
            {
                __wfd_lcd_dc_engine = WFD_LCD_DC_ENGINE_IRT2;
                wfcMMSetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_DC_LAYER_MTK, WFC_TRUE);
            }
#endif  // #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)

            wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_ELEMENT);
            wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 30);
            wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) CalDisplayElement);

#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)

            wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
            //if (CurrentScenarioId==CAL_SCENARIO_VIDEO || CurrentScenarioId==CAL_SCENARIO_VIDEO_TELEPHONY)
            if (CurrentScenarioId==CAL_SCENARIO_VIDEO ||
                CurrentCameraId == CAL_CAMERA_SOURCE_MATV)
            {
                wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 0);
            }
#else
        #ifdef __CAL_MATV_SUPPORT__
            if (CurrentCameraId == CAL_CAMERA_SOURCE_MATV)
            {
                wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 0);
            }
            else
        #endif
            {
                if (CurrentScenarioId==CAL_SCENARIO_VIDEO)
                {
                    wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 20);
                }
                else //CAL_SCENARIO_CAMERA_PREVIEW
                {
                #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
                    if (KAL_FALSE == triple_display_buffer_support) // 2 display buffers
                    {
                        wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
                    }
                    else // 3 display buffers
                    {
                        WFCint LCDRefreshRate = 0;
                        // switch to sync to timer mode to ensure refresh rate in Camera Preview
                        wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK, (WFCint) WFC_AUTONOMOUS_SYNC_TO_TIMER);
                        wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK, (WFCint) 0);
                        wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK, (WFCint) 0);

                        // query LCD refresh rate for reference
                        LCDRefreshRate = wfcMMGetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_BLT_MAX_REFRESH_RATE_MTK);
                        if (LCDRefreshRate >= 30)
                        {
                            wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
                        }
                        else
                        {
                            wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, LCDRefreshRate);
                        }
                    }
                #else
                    wfcMMSetContextAttribi(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK, 30);
                #endif
                }
            }
#endif  // #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)

            // Config Display Source width/height (The output of MDP) and source clip/pitch
            {
                WFCint srcRect[4];
                WFCint ClipX, ClipY, Width, Height;
                WFCRotation layerRotation;

                // The naming is only to avoid name conflict...
                WFCint elementFlip = (WFCint) WFC_FALSE;
                WFCint elementRotation = (WFCint) WFC_ROTATION_0;

                wfcGetElementAttribiv(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);

                layerRotation = (WFCRotation)
                wfcGetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_SOURCE_ROTATION);

                // Derive the output width/height of MDP, which should be the input width height of Display
                displayInputWidth = DisplayInputWidth;
                displayInputHeight = DisplayInputHeight;

                if (MdpRotAngle & 0x01)
                {
                    // Swap width and height if MDP rotate 90 or 270 degree...
                    displayInputWidth ^= displayInputHeight;
                    displayInputHeight ^= displayInputWidth;
                    displayInputWidth ^= displayInputHeight;
                }

                // Config Display Rotation angle & flip
                if (DisplayImageRotAngle >= MM_IMAGE_H_MIRROR)
                {
                    elementFlip = (WFCint) WFC_TRUE;
                    elementRotation += (WFCint)(DisplayImageRotAngle - MM_IMAGE_H_MIRROR);
                }
                else
                {
                    elementRotation += (WFCint)DisplayImageRotAngle;
                }

                wfcMMSetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_SOURCE_FLIP, (WFCint) elementFlip);
                wfcMMSetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_SOURCE_ROTATION, (WFCint) elementRotation);

                // Need re-config src rect.
                if (elementRotation != layerRotation)
                {
                    // layerRotation is the original LCD roate angle, DisplayImageRotAngle is final LCD rotate angle.
                    // In 76 56 55, DisplayImageRotAngle will be 0, because all rotate by MDP.
                    // LCD will be change to elementRotation and elementFlip, thus 0 and no flip.
                    // Diff(layerRotation, elementRotation=0) is the src rect need to be change.
                    //
                    // In 52 50, DisplayImageRotAngle will be 0, flip, 180 flip.
                    // Since 52 never have front sensor, then we claim DisplayImageRotAngle only 0 or 0 flip.
                    // Thus elementRotation = 0, flip setting may be different.
                    // Diff(layerRotation, elementRotation=0) is the src rect need to be change.
                    // Same as 76, 56, 55 src rect setting, the different is final LCD(elementFlip) need flip or not.
                    //
                    // In 53 35, DisplayImageRotAngle will be the total rotate angle need be handled by LCD.
                    // So, we change LCD rotate angel to elementFlip and elementRotation which is DisplayImageRotAngle
                    // Thus will be 0 or 90 or 270 and no flip, because sensor will handle all filp and 180.
                    // Since 53 never have front sensor, then we claim DisplayImageRotAngle only 0 or 90.
                    // ie, elementRotation = 0 or 90.
                    // In SCANLINE = 0, because MMI never set 180 and 270 to LCD layerRotation.
                    // So layerRotation is also 0 or 90.
                    // If SCANLINE = 270, MMI only set 0 and layerRotation = 90. (Add SCANLINE angle).
                    // In really case, we only have handle Diff(layerRotation=0, elementRotation=90) (53 Wallpaper).
                    // or Diff(layerRotation=90, elementRotation=0) (never test but all chip have do).
                    // But think about SCANLINE, we need handle Diff(layerRotation, elementRotation=90).
                    // and Diff(layerRotation, elementRotation=0) <- this is all chip have do.
                    // Now we only handle Diff(layerRotation=0, elementRotation=90) is ok.
                    // If layerRotation = 180 or 270 and elementRotation = 90, it must think twice.

                #if defined(MT6235) || defined(MT6235B) || defined(MT6253)
                    // 90 -> 0, 0 -> 90, 53 only need check this case.
                    if ((WFC_ROTATION_90 == layerRotation) || (WFC_ROTATION_90 == elementRotation))
                    {
                        ClipX = displayInputWidth - srcRect[1] - srcRect[3];
                        ClipY = srcRect[0];
                        Width = srcRect[3];
                        Height = srcRect[2];
                    }
                #else
                    // 90 -> 0
                    if (WFC_ROTATION_90 == layerRotation)
                    {
                        ClipX = displayInputWidth - srcRect[1] - srcRect[3];
                        ClipY = srcRect[0];
                        Width = srcRect[3];
                        Height = srcRect[2];
                    } // 270 -> 0
                    else if (WFC_ROTATION_270 == layerRotation)
                    {
                        ClipX = srcRect[1];
                        ClipY = displayInputHeight - srcRect[0] - srcRect[2];
                        Width = srcRect[3];
                        Height = srcRect[2];
                    } // 180 -> 0
                    else if (WFC_ROTATION_180 == layerRotation)
                    {
                        ClipX = displayInputWidth - srcRect[0] - srcRect[2];
                        ClipY = displayInputHeight - srcRect[1] - srcRect[3];
                        Width = srcRect[2];
                        Height = srcRect[3];
                    }
                #endif
                    else // 0 -> 0
                    {
                        ClipX = srcRect[0];
                        ClipY = srcRect[1];
                        Width = srcRect[2];
                        Height = srcRect[3];
                    }

                    srcRect[0] = ClipX;
                    srcRect[1] = ClipY;
                    srcRect[2] = Width;
                    srcRect[3] = Height;
                    wfcMMSetElementAttribiv(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_SOURCE_RECTANGLE, 4, &srcRect[0]);
                }
            }


            // Create stream...
            {
                OWF_IMAGE_FORMAT imageFormat;
                kal_uint32 bufs[3];
                kal_uint32 bufnum;

#if defined(DRV_IDP_6252_SERIES)
                imageFormat.linear = OWF_FALSE;
                imageFormat.premultiplied = OWF_FALSE;
                imageFormat.rowPadding = 0;
                imageFormat.pixelFormat = OWF_IMAGE_UYVY;
#else
                // get image fo format and pixel size
                GetMMDisplayImageFMT(DisplayImageFormat, &imageFormat);
#endif
#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
                //if (CurrentScenarioId==CAL_SCENARIO_VIDEO || CurrentScenarioId==CAL_SCENARIO_VIDEO_TELEPHONY)
                if (CurrentScenarioId==CAL_SCENARIO_VIDEO)
                {
                    imageFormat.pixelFormat = OWF_IMAGE_ARGB8888;
                }
#endif  // #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)

                CalDisplayFBs[0][0] = bufs[0] = FrameBuffAddr1;
                CalDisplayFBs[1][0] = bufs[1] = FrameBuffAddr2;

            #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
                if (KAL_TRUE == triple_display_buffer_support)
                {
                  CalDisplayFBs[2][0] = bufs[2] = FrameBuffAddr3;
                  bufnum = 3;
                }
                else
            #endif
                {
                  CalDisplayFBs[2][0] = NULL;
                  bufnum = 2;
                }
                // TODO: [m] When to destroy the stream? Where is the exit function?
                // TODO: [o] magical number here...
                CalDisplayStream =
                    owfNativeStreamCreateImageStreamEx((OWFint) displayInputWidth,
                                                       (OWFint) displayInputHeight,
                                                       &imageFormat, (OWFint) bufnum, (void**) &bufs[0]);
                // default latest buffer address is NULL
                Newest_FrameBuf_Addr = 0x0;

                // This code segment is used to do buffer control...
                {
                    void * bufPtr;
                    OWFNativeStreamBuffer buf;
                    kal_uint32 i, j;

                    for (i=0; i< bufnum; i++)
                    {
                        buf = owfNativeStreamAcquireWriteBuffer(CalDisplayStream);
                        bufPtr = owfNativeStreamGetBufferPtr(CalDisplayStream, buf);
                        CAL_DD_ASSERT(NULL != bufPtr);

                        j = 0;
                        while (CalDisplayFBs[j][0] != (kal_uint32) bufPtr)
                        {
                            j++;
                        }
                        CalDisplayFBs[j][1] = (kal_uint32) buf;
                    }
                }

                CalDisplaySource = wfcCreateSourceFromStream(CalDisplayDevice, CalDisplayContext, (WFCNativeStreamType) CalDisplayStream, NULL);

                // TODO: [m] Need an API to set buffers into the stream...

                if (WFC_INVALID_HANDLE == CalDisplaySource)
                {
                    CAL_DD_ASSERT(0); // TODO: [m] remove this after IT done...need error handling...
                }
            }

            // Set Element source
            wfcMMSetElementAttribi(CalDisplayDevice, CalDisplayElement, WFC_ELEMENT_SOURCE, (WFCint) CalDisplaySource);

            // TODO: [m] If camera preview only uses double display frame buffer, DDv2 needs to sync to content provider...since camera cannot wait...

        #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
            // set Display blt and change buffer done callback for triple display buffer
            if (KAL_TRUE == triple_display_buffer_support)
            {
            #if defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__)
                if (KAL_TRUE == CalImageEffectEnable)
                {
                    WfcDisplayCB = (kal_uint32)DisplayBufferAcquireCallback;
                }
                else
            #endif
                {
                    IDP_CAL_QUERY_ARG_T MdpQueryPara;
                    MdpQueryPara.ePath = IDP_CAL_QUERY_ARG_DISPLAY_PATH;
            #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
                    if (CAL_SCENARIO_CAMERA_MAV_CAPTURE == CurrentScenarioId)
                    {
                      MdpFunc.pfnIdpCalQuery(CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey, IDP_CAL_QUERY_FRAME_DONE_CB_FUNC, &MdpQueryPara, &WfcDisplayCB);
                    }
                    else
            #endif
                    {
                      MdpFunc.pfnIdpCalQuery(CurrentScenarioId, IdpCalKey, IDP_CAL_QUERY_FRAME_DONE_CB_FUNC, &MdpQueryPara, &WfcDisplayCB);
                    }
                }
                if (NULL != WfcDisplayCB)
                {
                    WFCint array[4];

                    array[0] = (WFCint) WFC_CONTEXT_EVENT_REALSE_READ_BUFFER_DONE_CALLBACK_MTK;
                    array[1] = (WFCint) WfcDisplayCB;
                    array[2] = (WFCint) WFC_NONE;
                    array[3] = (WFCint) WFC_TRUE;
                    wfcMMSetContextAttribiv(CalDisplayDevice, CalDisplayContext, WFC_CONTEXT_CALLBACK_MTK, 4, &array[0]);
                }
            }
        #endif

            // Commmit
            wfcMMCommit(CalDisplayDevice, CalDisplayContext, CalDisplayElement, WFC_COMMIT_CONTEXT_AND_ELEMENT);
        }
    }
#endif
}   /* CameraImageDisplayConfig() */

#ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
kal_bool CalImageSwRotateDetect(P_CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_IN_STRUCT pCamSwRotPara)
{
    // for IDP capability query
    IDP_CAL_QUERY_ARG_T MdpCapQueryPara;
    kal_uint32 MdpCapQueryResult;
    MM_IMAGE_ROTATE_ENUM ImageRotAngle;

    if ((CAL_SCENARIO_VIDEO==pCamSwRotPara->ScenarioId)||
        (CAL_SCENARIO_VIDEO_TELEPHONY==pCamSwRotPara->ScenarioId))
    {
        switch (pCamSwRotPara->DisplayImageRotAngle)
        {
            case MM_IMAGE_ROTATE_180:
            case MM_IMAGE_ROTATE_270:
                ImageRotAngle=GetRestRotAngle(pCamSwRotPara->TargetImageRotAngle, MM_IMAGE_ROTATE_180);
            break;
            case MM_IMAGE_H_MIRROR_ROTATE_180:
                ImageRotAngle=GetRestRotAngle(pCamSwRotPara->TargetImageRotAngle, MM_IMAGE_H_MIRROR_ROTATE_180);
            break;
            case MM_IMAGE_H_MIRROR:
                ImageRotAngle=GetRestRotAngle(pCamSwRotPara->TargetImageRotAngle, MM_IMAGE_H_MIRROR);
            break;
            default :
                ImageRotAngle = pCamSwRotPara->TargetImageRotAngle;
            break;
        }

        MdpFunc.pfnIdpCalOpen( pCamSwRotPara->ScenarioId, &IdpCalKey, NULL, 0);

        // query whether the MDP support vidoe image rotation ?
        MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_POSTPROC_PATH;
        MdpCapQueryPara.eDesiredAngle=(img_rot_angle_enum_t) ImageRotAngle;
        // set a small video image width, this query is only to know MDP chip's rotation capability.
        MdpCapQueryPara.eRotateWidth=176;
        MdpFunc.pfnIdpCalQuery(pCamSwRotPara->ScenarioId, IdpCalKey, IDP_CAL_QUERY_ROT_CAP, &MdpCapQueryPara, &MdpCapQueryResult);

        MdpFunc.pfnIdpCalClose(pCamSwRotPara->ScenarioId, IdpCalKey);
        if (MdpCapQueryResult == ImageRotAngle)
            return KAL_FALSE;
        else
            return KAL_TRUE;
    }
    else return KAL_FALSE;
}   /* CalImageSwRotateDetect() */
#endif

#if (defined(__CAL_CAMERA_OVERLAY_SUPPORT__) && (defined(__LCM_SCANLINE_ROTATION_SUPPORT__)))
MM_IMAGE_ROTATE_ENUM RotateOverlayFrameBuffer(kal_uint32 *pSrcAddrPointer, kal_uint32 *pWorkingAddrPointer,
                                              kal_uint16 SrcWidth, kal_uint16 SrcHeight,
                                              MM_IMAGE_ROTATE_ENUM ImageRotAngle)
{
    MM_IMAGE_ROTATE_ENUM OverlayRotateAngle=ImageRotAngle;
    int i,j;
    kal_uint8 *pSrcAddr, *pWorkingAddr;

    if (ImageRotAngle < MM_IMAGE_H_MIRROR)
    {
        OverlayRotateAngle = (4-ImageRotAngle)&0x03;
    }

    CalExtMemSwitchCachableRegion(pSrcAddrPointer, SrcWidth*SrcHeight, PAGE_CACHEABLE);
    CalExtMemSwitchCachableRegion(pWorkingAddrPointer, SrcWidth*SrcHeight, PAGE_CACHEABLE);

    pSrcAddr=(kal_uint8 *) *pSrcAddrPointer;
    pWorkingAddr=(kal_uint8 *) *pWorkingAddrPointer;

    switch (OverlayRotateAngle)
    {
        case MM_IMAGE_ROTATE_90:
            for (i=0;i<SrcHeight;i++)
            {
                for (j=1;j<=SrcWidth;j++)
                    *(pWorkingAddr+j*SrcHeight-(i+1))=*(pSrcAddr+i*SrcWidth+(j-1));
            }
        break;
        case MM_IMAGE_ROTATE_180:
            for (i=0;i<SrcHeight;i++)
            {
                for (j=0;j<SrcWidth;j++)
                    *(pWorkingAddr+SrcWidth*SrcHeight-1-(i*SrcWidth+j))=*(pSrcAddr+i*SrcWidth+j);
            }
        break;
        case MM_IMAGE_ROTATE_270:
            for (i=0;i<SrcHeight;i++)
            {
                for (j=(SrcWidth-1);j>=0;j--)
                    *(pWorkingAddr+j*SrcHeight+i)=*(pSrcAddr+i*SrcWidth+(SrcWidth-1-j));
            }
        break;
        case MM_IMAGE_H_MIRROR:
            for (i=0;i<SrcHeight;i++)
            {
                for (j=0;j<SrcWidth;j++)
                    *(pWorkingAddr+i*SrcWidth+(SrcWidth-1-j))=*(pSrcAddr+i*SrcWidth+j);
            }
        break;
        case MM_IMAGE_H_MIRROR_ROTATE_90:
            for (i=0;i<SrcHeight;i++)
            {
                for (j=0;j<SrcWidth;j++)
                    *(pWorkingAddr+j*SrcHeight+i)=*(pSrcAddr+i*SrcWidth+j);
            }
        break;
        case MM_IMAGE_H_MIRROR_ROTATE_180:
            for (i=0;i<SrcHeight;i++)
            {
                for (j=0;j<SrcWidth;j++)
                    *(pWorkingAddr+(SrcHeight-i-1)*SrcWidth+j)=*(pSrcAddr+i*SrcWidth+j);
            }
        break;
        case MM_IMAGE_H_MIRROR_ROTATE_270:
            for (i=0;i<SrcHeight;i++)
            {
                for (j=0;j<SrcWidth;j++)
                    *(pWorkingAddr+(SrcWidth-j-1)*SrcHeight+(SrcHeight-i-1))=*(pSrcAddr+i*SrcWidth+j);
            }
        break;
    }
    kal_mem_cpy(pSrcAddr, pWorkingAddr, SrcWidth*SrcHeight);
    CalExtMemSwitchCachableRegion(pSrcAddrPointer, SrcWidth*SrcHeight, PAGE_NO_CACHE);
    CalExtMemSwitchCachableRegion(pWorkingAddrPointer, SrcWidth*SrcHeight, PAGE_NO_CACHE);

    return OverlayRotateAngle;
}   /* RotateOverlayFrameBuffer() */
#endif

MM_ERROR_CODE_ENUM CalPreviewCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_CAL_CAMERA_PREVIEW_STRUCT pCalPreviewPara = (P_CAL_CAMERA_PREVIEW_STRUCT) pCtrlPara;
    P_CAL_LCD_STRUCT pCalLcdPara=pCalPreviewPara->pLcdPara;
    P_CAL_ISP_PREVIEW_STRUCT pCalIspPreviewPara=pCalPreviewPara->pIspPara;
    P_CAL_MDP_PREVIEW_STRUCT pCalMdpPreviewPara=pCalPreviewPara->pMdpPara;
    ISP_CAMERA_PREVIEW_STRUCT IspPreviewPara;

    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT IspDigitalZoomResParaIn;
    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT IspDigitalZoomResParaOut;

    ISP_FEATURE_SET_TG_STRUCT IspTgSettingInfo;
    SENSOR_FRAMERATE_IN_STRUCT  SensorQueryFrameRateIn;
    SENSOR_FRAMERATE_OUT_STRUCT SensorQueryFrameRateOut;

    // for IDP capability query
    IDP_CAL_QUERY_ARG_T MdpCapQueryPara;
    kal_uint32 MdpCapQueryResult;
    kal_uint16 MdpResGetCount=0;
#if (defined(__CAL_CAMERA_OVERLAY_SUPPORT__) && (defined(__LCM_SCANLINE_ROTATION_SUPPORT__)||defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__)))
    MM_IMAGE_ROTATE_ENUM OverlayRotateAngle=MM_IMAGE_ROTATE_0;
    kal_uint16 Temp;
#endif

#if (defined(__POSTPROC_SUPPORT__))
    /* Post Process Parameters */
    P_CAL_POSTPROC_STRUCT pCalPostProcPreviewPara=pCalPreviewPara->pPostProcPara;
    PP_FEATURE_CTRL_STRUCT_UNION    PpFeaturePara;
    P_PP_FEATURE_CONFIG_INFO_STRUCT  pPpFeatureConfigPara=&PpFeatureConfigPara;
    kal_uint32  PpMaxImageWidth=0,PpMaxImageHeight=0;
    PP_LOG_INFO_STRUCT PpLogPara;
    kal_uint32 PpLogSize;
#endif /* defined(__POSTPROC_SUPPORT__) */

    kal_uint32 FeatureOutLen;
    kal_uint32 CtrlOutLen;
#if defined(__CAL_NEED_SW_ROTATE__) || defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__) || defined(__POSTPROC_SUPPORT__)
    kal_uint32 ExtMemAddr, ExtMemSize;
#endif

#ifdef __CAL_MINIMIZE_GLOBAL_VARIABLE__
    Camera_Preview_Idp_Cal_Struct MdpPreviewPara;
#endif

    DisplayPreviewFrameFlag=KAL_FALSE;
#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
    CalImageEffectEnable = KAL_FALSE;
#endif
    if (CAL_CTRL_CODE_STOP & CtrlCode)
    {
        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
        ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);

        MdpFunc.pfnIdpCalClose(ScenarioId, IdpCalKey);
        CalState = CAL_STANDBY_STATE;
#if (defined(__POSTPROC_SUPPORT__))
        /* Disable PP*/
        PostProcImageFromDisplayImage = KAL_FALSE;
        gMdpPostProcTrigger = KAL_FALSE;
        PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_STOP, 0, 0, 0);

    #if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
    if(CalAsdEnabled)
    {   // set asd log when stop preview before capture
        PpLogPara.ScenarioId = PP_SCENARIO_CAMERA_STILL_CAPTURE;
        PpFeaturePara.pLogInfo = &PpLogPara;
        PpFeatureCtrl(PP_FUNC_ASD, PP_FEATURE_SET_LOG_INFO,&PpFeaturePara, 0, 0);
    }
    #endif

#endif /* defined(__POSTPROC_SUPPORT__) */
#if (defined(__CAL_MATV_SUPPORT__))
        if (CAL_CAMERA_SOURCE_MATV == CurrentCameraId)  
        {
            CameraImageDisplayConfig(CtrlCode, (MM_IMAGE_FORMAT_ENUM) CalPreviewInfo.ImageDataFormat,
                                     (MM_IMAGE_ROTATE_ENUM) DisplayImageSrcRotAngle,
                                     CalPreviewInfo.DisplayImageWidth, CalPreviewInfo.DisplayImageHeight,
                                     CalPreviewInfo.FrameBuffAddr1, CalPreviewInfo.FrameBuffAddr2, CalPreviewInfo.FrameBuffAddr3);
        }
        else
#endif
        {
            CameraImageDisplayConfig(CtrlCode, (MM_IMAGE_FORMAT_ENUM) CalPreviewInfo.ImageDataFormat,
                                     (MM_IMAGE_ROTATE_ENUM) DisplayImageSrcRotAngle,
                                     CalPreviewInfo.DisplayImageWidth, CalPreviewInfo.DisplayImageHeight,
                                     CalPreviewInfo.CameraAppFrameBuffAddr, CalPreviewInfo.FrameBuffAddr2, CalPreviewInfo.FrameBuffAddr3);
        }

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_EXIT_CAMERA_PREVIEW);
    #endif
        return ErrorCode;
    }
    if (CAL_CTRL_CODE_START & CtrlCode)
    {
    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_ENTER_CAMERA_PREVIEW);
    #endif

    #if defined(__CAL_NEED_SW_ROTATE__) || defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__) || defined(__POSTPROC_SUPPORT__)
        ExtMemAddr = pCalPreviewPara->ExtmemStartAddress;
        ExtMemSize = pCalPreviewPara->ExtmemSize;
    #endif

        IspTgSettingInfo.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
        IspTgSettingInfo.pSensorInfo=(void *) &CurrentSensorInfo;
        pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_TG, &IspTgSettingInfo, NULL, 0,&FeatureOutLen);

        /* config sensor driver */
        GetSensorRotAngle(pCalMdpPreviewPara->ImageRotAngle, &MdpPreviewPara.display_rot_angle, &SensorScenarioParaIn.ImageMirror);

        IspPreviewPara.ImageMirror=SensorScenarioParaIn.ImageMirror;

#if !defined (MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
        // if CP triple buffer does not support, set FrameBuffAddr3 to NULL
        pCalMdpPreviewPara->FrameBuffAddr3 = NULL;
#endif
        kal_mem_cpy(&CalPreviewInfo, pCalMdpPreviewPara, sizeof(CAL_MDP_PREVIEW_STRUCT));

        while(MdpFunc.pfnIdpCalIsInUse(CAL_SCENARIO_CAMERA_PREVIEW))
        {
            kal_sleep_task(10);
            MdpResGetCount++;
            if (10<=MdpResGetCount)
                ASSERT(0);
        }

        ErrorCode = MdpFunc.pfnIdpCalOpen( ScenarioId, &IdpCalKey, NULL, 0);
    #if (defined(__POSTPROC_SUPPORT__))
        MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_POSTPROC_PATH;
        MdpFunc.pfnIdpCalQuery(ScenarioId, IdpCalKey, IDP_CAL_QUERY_PATH_SUPPORT, &MdpCapQueryPara, &MdpCapQueryResult);
        if ((KAL_TRUE == MdpCapQueryResult)||(0 == pCalPostProcPreviewPara->PostProcMode)
            #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
            ||(pCalPostProcPreviewPara->PostProcMode & PP_MODE_MAV)
            #endif
            )
        {   // for MT6236/68/76/55/56
            // HW support the post process output and rotate to suitable angle
            // or post process is disable
            PostProcImageFromDisplayImage = KAL_FALSE;
        }
        else
        {   // for MT6253/52/52H/35
            // HW can not support the post process output
            // SW will rotate display image for LCD when MDP callback(IDPCAL_CBID_CAM_PREVIEW_DISPLAY_FRM_DONE)
            // through CAL task if necessary
            // keep the information and re-calculate the SW rotate angle of display image
            PostProcImageFromDisplayImage = KAL_TRUE;
        }
    #endif

        // query the rotation angle that MDP can support.
        // Pass the rest rotation angle to Display driver.
        // if the rotation angle is depend on post image process, then CAL will rotate the image for display driver.
        MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_DISPLAY_PATH;
        MdpCapQueryPara.eClrFmt=(MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpPreviewPara->ImageDataFormat;
        MdpCapQueryPara.eDesiredAngle=MdpPreviewPara.display_rot_angle;
        MdpFunc.pfnIdpCalQuery(ScenarioId, IdpCalKey, IDP_CAL_QUERY_ROT_CAP, &MdpCapQueryPara, &MdpCapQueryResult);

        DisplayImageRotAngle=GetRestRotAngle((MM_IMAGE_ROTATE_ENUM)MdpPreviewPara.display_rot_angle, (MM_IMAGE_ROTATE_ENUM) MdpCapQueryResult);

        MdpPreviewPara.display_rot_angle = (img_rot_angle_enum_t) MdpCapQueryResult;
        MdpDisplayImageRotAngle = (MM_IMAGE_ROTATE_ENUM) MdpPreviewPara.display_rot_angle;
        DisplayImageSrcRotAngle = (MM_IMAGE_ROTATE_ENUM) MdpPreviewPara.display_rot_angle;

        MdpPreviewPara.frame_buffer_address1= pCalMdpPreviewPara->FrameBuffAddr1;
        MdpPreviewPara.frame_buffer_address2= pCalMdpPreviewPara->FrameBuffAddr2;
        MdpPreviewPara.frame_buffer_address3= pCalMdpPreviewPara->FrameBuffAddr3;
        #if defined(__CAL_NEED_SW_ROTATE__)
        ImageSwRotateAngleForDisplay = MM_IMAGE_ROTATE_0;
        if (KAL_TRUE==PostProcImageFromDisplayImage)
        {   // configure the rotation angle of Display driver as 0 degree
            // TBD when display driver is ready.
            ImageSwRotateAngleForDisplay = DisplayImageRotAngle;
            DisplayImageRotAngle = MM_IMAGE_ROTATE_0;
            MdpPreviewPara.frame_buffer_address1= ExtMemAddr;
            MdpPreviewPara.frame_buffer_address2= ExtMemAddr+pCalMdpPreviewPara->FrameBuffSize;
            ExtMemAddr += pCalMdpPreviewPara->FrameBuffSize*2;
            ExtMemSize -= pCalMdpPreviewPara->FrameBuffSize*2;

            // because we only need the rotation angle to detemine the width/height of display driver,
            // we do not need exactly rotation angle
            DisplayImageSrcRotAngle = ImageSwRotateAngleForDisplay + MdpPreviewPara.display_rot_angle;
            DisplayImageSrcRotAngle %= MM_NO_OF_IMAGE_ROTATE;
        }
        #endif
        MdpPreviewPara.dbuf_tearing_free_enable = KAL_TRUE;
        #if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
        if (((CAL_CAMERA_SOURCE_MATV != CurrentCameraId) &&
            (0 == pCalPreviewPara->pPostProcPara->PostProcMode) &&
            (CAL_SCENARIO_CAMERA_ZSD_PREVIEW != ScenarioId))
            #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
            ||(pCalPostProcPreviewPara->PostProcMode & PP_MODE_MAV)
            #endif
            )
        {
            MdpPreviewPara.frame_buffer_address1= ExtMemAddr;
            MdpPreviewPara.frame_buffer_address2= ExtMemAddr+pCalMdpPreviewPara->FrameBuffSize;
            MdpPreviewPara.frame_buffer_address3= 0;
            ExtMemAddr += pCalMdpPreviewPara->FrameBuffSize*2;
            ExtMemSize -= pCalMdpPreviewPara->FrameBuffSize*2;
            MdpPreviewPara.dbuf_tearing_free_enable = KAL_FALSE;
            CalImageEffectEnable = KAL_TRUE;
            DisplayImageEffectBufferAddr = 0;
            DisplayImageEffectIdx = 0;
        }
        #endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

        SaveDisplyHandle(pCalLcdPara);

        #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__) || defined(__3D_IMAGE_SUPPORT__))
        CalMavDisplayDevice = CalDisplayDevice;
        CalMavDisplayContext = CalDisplayContext;
        CalMavDisplayElement = CalDisplayElement;
        kal_mem_cpy(&CalMavIspPreviewPara,pCalIspPreviewPara,sizeof(CAL_ISP_PREVIEW_STRUCT));
        #endif

        CameraImageDisplayConfig(CtrlCode, pCalMdpPreviewPara->ImageDataFormat,
                                 DisplayImageSrcRotAngle,
                                 pCalMdpPreviewPara->DisplayImageWidth, pCalMdpPreviewPara->DisplayImageHeight,
                                 pCalMdpPreviewPara->FrameBuffAddr1, pCalMdpPreviewPara->FrameBuffAddr2, pCalMdpPreviewPara->FrameBuffAddr3);

    #if (defined(__POSTPROC_SUPPORT__))
        #if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
        CalAsdSceneType = pCalIspPreviewPara->SceneMode;
        if(pCalPostProcPreviewPara->PostProcMode & PP_MODE_ASD)
            CalAsdEnabled=KAL_TRUE;
        else
            CalAsdEnabled=KAL_FALSE;
        #endif // __AUTO_SCENE_DETECT_SUPPORT__

        /* config and start PostProc */
        if((pCalPostProcPreviewPara->PostProcMode !=0)
           #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
           &&(pCalPostProcPreviewPara->PostProcMode != PP_MODE_MAV)
           #endif
           )
        {
            /* set env info */
            #if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
            if(pCalPostProcPreviewPara->PostProcMode & PP_MODE_ASD)
            {
                ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_3A_REF, NULL, &IspAwbAfRefBuff, sizeof(ISP_CAMERA_AWB_AF_REF_STRUCT), &FeatureOutLen);
                pPpFeatureConfigPara->AaaInfoFromRaw = IspAwbAfRefBuff.AaaInfoFromRaw;
                pPpFeatureConfigPara->AwbRefD65Rgain = IspAwbAfRefBuff.AwbRefD65Rgain;
                pPpFeatureConfigPara->AwbRefD65Bgain = IspAwbAfRefBuff.AwbRefD65Bgain;
                pPpFeatureConfigPara->AwbRefCwfRgain = IspAwbAfRefBuff.AwbRefCwfRgain;
                pPpFeatureConfigPara->AwbRefCwfBgain = IspAwbAfRefBuff.AwbRefCwfBgain;
                pPpFeatureConfigPara->AfTblParam = IspAwbAfRefBuff.AfTblParam;
            }
            #endif // __AUTO_SCENE_DETECT_SUPPORT__
            pPpFeatureConfigPara->ExtmemStartAddress = ExtMemAddr;  /* external memroy start address for algorithm engine buffer */
            pPpFeatureConfigPara->ExtmemSize = ExtMemSize;          /* external memory size for algorithm engine buffer */
            pPpFeatureConfigPara->ImgWidth = pCalMdpPreviewPara->DisplayImageWidth;
            pPpFeatureConfigPara->ImgHeight = pCalMdpPreviewPara->DisplayImageHeight;
            pPpFeatureConfigPara->ImgFmtList = 1<<MM_IMAGE_FORMAT_RGB565;
            pPpFeatureConfigPara->ImgFmtCurr = MM_IMAGE_FORMAT_RGB565;
            pPpFeatureConfigPara->PostProcMode=pCalPostProcPreviewPara->PostProcMode;
            PpFeaturePara.pConfigInfo = pPpFeatureConfigPara;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_ENV_INFO,&PpFeaturePara, 0, 0);

            /* get env info */
            pPpFeatureConfigPara->MdpConfigFlag = KAL_FALSE;    /* initialized to false */
            pPpFeatureConfigPara->IspConfigFlag = KAL_FALSE;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_GET_ENV_INFO,0, &PpFeaturePara, sizeof(PP_FEATURE_CONFIG_INFO_STRUCT));

            //Assert if current format is not supported in format list
            ASSERT(pPpFeatureConfigPara->ImgFmtList & (1<<pPpFeatureConfigPara->ImgFmtCurr));

            PpMaxImageWidth = pPpFeatureConfigPara->MaxImgWidth;
            PpMaxImageHeight= pPpFeatureConfigPara->MaxImgHeight;
            ExtMemAddr += pPpFeatureConfigPara->ExtmemSize;
            ExtMemSize -= pPpFeatureConfigPara->ExtmemSize;

            /* set PostProc log buffer */
            PpLogPara.ExtmemStartAddress = ExtMemAddr;  /* external memroy start address for algorithm engine log buffer */
            PpLogPara.ExtmemSize = ExtMemSize;          /* external memory size for algorithm engine log buffer */
            PpLogPara.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
            PpFeaturePara.pLogInfo = &PpLogPara;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_LOG_INFO,&PpFeaturePara, &PpLogSize, sizeof(PpLogSize));
            ExtMemAddr += PpLogSize;
            ExtMemSize -= PpLogSize;
        }
        else
        {
            pPpFeatureConfigPara->MdpConfigFlag = KAL_FALSE;
            pPpFeatureConfigPara->IspConfigFlag = KAL_FALSE;
        }
        if (pPpFeatureConfigPara->MdpConfigFlag==KAL_TRUE)
        {
            gMdpPostProcTrigger = KAL_TRUE;
        }
    #endif  /* defined(__POSTPROC_SUPPORT__) */

    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        /* bypass ae & awb */
        if (pPpFeatureConfigPara->IspConfigFlag)
        {
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AE_BYPASS, (void*)&pPpFeatureConfigPara->FixAe, NULL, 0, 0);
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AWB_BYPASS, (void*)&pPpFeatureConfigPara->FixAwb, NULL, 0, 0);
            #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
            if(pCalPostProcPreviewPara->PostProcMode&PP_MODE_PANORAMA)
            {
                kal_bool Enable = KAL_TRUE; 
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AE_BYPASS, (void*)&Enable, NULL, 0, 0);
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AWB_BYPASS, (void*)&Enable, NULL, 0, 0); 
            }
            #endif /* defined(__AUTOCAP_PANORAMA_SUPPORT__) */
        }
        if (pCalPostProcPreviewPara->PostProcMode&PP_MODE_PANORAMA)
        {
            kal_bool BypassEnableFlag=KAL_TRUE;
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AF_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
        }
    #endif  //__PANORAMA_VIEW_SUPPORT__ ||__AUTOCAP_PANORAMA_SUPPORT__

        SensorScenarioParaIn.ImageTargetWidth=pCalMdpPreviewPara->DisplayImageWidth;
        SensorScenarioParaIn.ImageTargetHeight=pCalMdpPreviewPara->DisplayImageHeight;
        if (CAM_NIGHTSCENE==pCalIspPreviewPara->SceneMode)
            SensorScenarioParaIn.NightMode=KAL_TRUE;
        else
            SensorScenarioParaIn.NightMode=KAL_FALSE;

        #if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
        if( CalAsdEnabled && (!IspAwbAfRefBuff.AaaInfoFromRaw) )
        {   // when asd on, the yuv sensor should be set to NightMode
            SensorScenarioParaIn.NightMode=KAL_TRUE;
        }
        #endif
 
        SensorScenarioParaIn.MetaMode=CAMERA_SYSTEM_NORMAL_MODE;
        SensorScenarioParaIn.ContrastLevel=pCalIspPreviewPara->ContrastLevel;
        SensorScenarioParaIn.BrightnessLevel=pCalIspPreviewPara->BrightnessLevel;
        SensorScenarioParaIn.SaturationLevel=pCalIspPreviewPara->SaturationLevel;
        SensorScenarioParaIn.WbMode=pCalIspPreviewPara->WbMode;
        SensorScenarioParaIn.EvValue=pCalIspPreviewPara->EvValue;
        SensorScenarioParaIn.BandingFreq=pCalIspPreviewPara->BandingFreq;
        SensorScenarioParaIn.ImageEffect=pCalIspPreviewPara->ImageEffect;
        SensorScenarioParaIn.HueValue=pCalIspPreviewPara->HueValue;
        #if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
        CalImageEffect = pCalIspPreviewPara->ImageEffect;
        if (pCalIspPreviewPara->ImageEffect >= CAM_EFFECT_ENC_LOMO)
        {   /* reset image effect to normal for sensor */
            SensorScenarioParaIn.ImageEffect = CAM_EFFECT_ENC_NORMAL;
        }
        #endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

        SensorQueryFrameRateIn.Scenario= CAL_SCENARIO_CAMERA_PREVIEW;
        SensorQueryFrameRateIn.CameraIf=  CurrentSensorInfo.SensorIf;
        SensorQueryFrameRateIn.DataFormat= CurrentSensorInfo.PreviewNormalDataFormat;
        SensorQueryFrameRateIn.SourceWidth= CurrentSensorInfo.PreviewWidth;
        SensorQueryFrameRateIn.SourceHeight= CurrentSensorInfo.PreviewHeight;
        SensorQueryFrameRateIn.NighhtMode= SensorScenarioParaIn.NightMode;
        ErrorCode= SensorCommonGetFrameRate(&SensorQueryFrameRateIn, &SensorQueryFrameRateOut);
        if(ErrorCode == MM_ERROR_NONE)
            SensorScenarioParaIn.MaxVideoFrameRate = SensorQueryFrameRateOut.MaxSensorFrameRate;
        else
            SensorScenarioParaIn.MaxVideoFrameRate = 300;
#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
        if (pCalPostProcPreviewPara->PostProcMode & PP_MODE_MAV)
        {
            pfImageSensor->SensorCtrl(CAL_SCENARIO_VIDEO, &SensorScenarioParaIn, &SensorScenarioParaOut,
                                  sizeof(IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT),&CtrlOutLen);

        }
        else
#endif
        {

        pfImageSensor->SensorCtrl(ScenarioId, &SensorScenarioParaIn, &SensorScenarioParaOut,
                                  sizeof(IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT),&CtrlOutLen);
        }
        #if 0//(defined(__RF_DESENSE_TEST__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif

        /* calculate digital zoom step */
        CurrentZoomInfo.CurrentZoomStep=pCalIspPreviewPara->ZoomStep;

        pIspGetOutResParaIn->IspState=ISP_PREVIEW_STATE; 

        ErrorCode=ConfigIspGetResPara(pCalIspPreviewPara->ZoomStep, pCalMdpPreviewPara->DisplayImageWidth,
                                      pCalMdpPreviewPara->DisplayImageHeight, CurrentDzInfo.DzType);

        IspDigitalZoomResParaIn.DzType=CurrentDzInfo.DzType;
        IspDigitalZoomResParaIn.pZoomFactorListTable=CurrentDzInfo.pZoomFactorListTable;
        IspDigitalZoomResParaIn.ZoomStep=pCalIspPreviewPara->ZoomStep;
        ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION, &IspDigitalZoomResParaIn,
                                            &IspDigitalZoomResParaOut, sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT),
                                            &FeatureOutLen);
        MdpPreviewPara.mdp_crop_enable=IspDigitalZoomResParaOut.MdpCropEnable;
        MdpPreviewPara.cropped_width=IspDigitalZoomResParaOut.DigitalZoomWidth;
        MdpPreviewPara.cropped_height=IspDigitalZoomResParaOut.DigitalZoomHeight;
        /* config idp */
        MdpPreviewPara.source_width = pIspGetOutResParaOut->IspOutWidth;
        MdpPreviewPara.source_height = pIspGetOutResParaOut->IspOutHeight;
        MdpPreviewPara.display_width = pCalMdpPreviewPara->DisplayImageWidth;
        MdpPreviewPara.display_height = pCalMdpPreviewPara->DisplayImageHeight;
    #if (!defined(DRV_IDP_6252_SERIES))
        MdpPreviewPara.preview_pitch_enable=KAL_FALSE;
    #endif
        MdpPreviewPara.preview_image_color_format=(MM_IMAGE_COLOR_FORMAT_ENUM)pCalMdpPreviewPara->ImageDataFormat;
    #ifdef __CAL_CAMERA_OVERLAY_SUPPORT__
    #if (defined(__LCM_SCANLINE_ROTATION_SUPPORT__) || defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__))
        if (KAL_TRUE==pCalMdpPreviewPara->OverlayEnable)
        {
            if (IMAGE_SENSOR_MIRROR_HV==SensorScenarioParaIn.ImageMirror)
                pCalMdpPreviewPara->StillImageRotAngle=GetRestRotAngle(pCalMdpPreviewPara->StillImageRotAngle, MM_IMAGE_ROTATE_180);
            else if (IMAGE_SENSOR_MIRROR_H==SensorScenarioParaIn.ImageMirror)
                pCalMdpPreviewPara->StillImageRotAngle=GetRestRotAngle(pCalMdpPreviewPara->StillImageRotAngle, MM_IMAGE_H_MIRROR);
        #ifdef __CAL_DUAL_CAMERA_SUPPORT__  // only front camera need to do H mirror that will result in setting ImageMirror as V mirror
            else if (IMAGE_SENSOR_MIRROR_V==SensorScenarioParaIn.ImageMirror)
                pCalMdpPreviewPara->StillImageRotAngle=GetRestRotAngle(pCalMdpPreviewPara->StillImageRotAngle, MM_IMAGE_H_MIRROR_ROTATE_180);
        #endif

            if (MM_IMAGE_ROTATE_0 != pCalMdpPreviewPara->StillImageRotAngle)
            {
                OverlayRotateAngle= RotateOverlayFrameBuffer((kal_uint32 *) &(pCalMdpPreviewPara->OverlayFrameBuffAddr),
                                                             (kal_uint32 *) &(pCalMdpPreviewPara->FrameBuffAddr2),
                                                             pCalMdpPreviewPara->OverlayFrameWidth, pCalMdpPreviewPara->OverlayFrameHeight,
                                                             pCalMdpPreviewPara->StillImageRotAngle);
                if (OverlayRotateAngle & 0x01)
                {
                    Temp = pCalMdpPreviewPara->OverlayFrameWidth;
                    pCalMdpPreviewPara->OverlayFrameWidth = pCalMdpPreviewPara->OverlayFrameHeight;
                    pCalMdpPreviewPara->OverlayFrameHeight = Temp;
                }
            }
        }
    #endif
        MdpPreviewPara.enable_overlay=pCalMdpPreviewPara->OverlayEnable;
        MdpPreviewPara.overlay_palette_size=pCalMdpPreviewPara->OverlayPaletteSize;
        MdpPreviewPara.overlay_palette_addr=pCalMdpPreviewPara->OverlayPaletteAddr;
        MdpPreviewPara.overlay_color_depth=pCalMdpPreviewPara->OverlayColorDepth;
        MdpPreviewPara.overlay_frame_source_key=pCalMdpPreviewPara->OverlayFrameSourceKey;
        MdpPreviewPara.overlay_frame_width=pCalMdpPreviewPara->OverlayFrameWidth;
        MdpPreviewPara.overlay_frame_height=pCalMdpPreviewPara->OverlayFrameHeight;
        MdpPreviewPara.overlay_frame_buffer_address=pCalMdpPreviewPara->OverlayFrameBuffAddr;
    #else
    #if (!defined(DRV_IDP_6252_SERIES))
        MdpPreviewPara.enable_overlay=KAL_FALSE;
    #endif
    #endif
        MdpPreviewPara.digital_zoom_frame_start_hisr_cb_enable=KAL_FALSE;
        MdpPreviewPara.lcd_update_enable = KAL_TRUE;
    #ifdef __CAL_MATV_SUPPORT__
        if(CurrentCameraId == CAL_CAMERA_SOURCE_MATV)
            MdpPreviewPara.trigger_display_delay_to_frame_start_enable= KAL_TRUE;
       else
        MdpPreviewPara.trigger_display_delay_to_frame_start_enable= KAL_FALSE;
    #endif
    #if (defined(__POSTPROC_SUPPORT__))
        if ((pPpFeatureConfigPara->MdpConfigFlag==KAL_TRUE) &&
            (KAL_FALSE==PostProcImageFromDisplayImage)
            #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
            &&(pCalPostProcPreviewPara->PostProcMode != PP_MODE_MAV)
            #endif
            )
        {
            MdpPreviewPara.postproc_image_enable=KAL_TRUE;
            MdpPreviewPara.postproc_image_rot_angle= (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
            MdpPreviewPara.postproc_image_width=pPpFeatureConfigPara->ImgWidth;
            MdpPreviewPara.postproc_image_height=pPpFeatureConfigPara->ImgHeight;
            MdpPreviewPara.postproc_image_buffer_address_1= ExtMemAddr;
            MdpPreviewPara.postproc_image_buffer_address_2= ExtMemAddr + PpMaxImageWidth*PpMaxImageHeight*2;
            MdpPreviewPara.postproc_image_buffer_address_3= ExtMemAddr + PpMaxImageWidth*PpMaxImageHeight*2*2;
            MdpPreviewPara.postproc_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM) pPpFeatureConfigPara->ImgFmtCurr;
            MdpPreviewPara.postproc_image_done_hisr_cb_enable=KAL_TRUE;
            MdpPreviewPara.extmem_size = ExtMemSize - PpMaxImageWidth*PpMaxImageHeight*2*3;
            MdpPreviewPara.extmem_start_address = ExtMemAddr + PpMaxImageWidth*PpMaxImageHeight*2*3;
        }
        else
        {
            MdpPreviewPara.postproc_image_enable=KAL_FALSE;
            MdpPreviewPara.extmem_start_address = ExtMemAddr;
            MdpPreviewPara.extmem_size = ExtMemSize;
        }
    #endif

        ErrorCode = MdpFunc.pfnIdpCalSet( ScenarioId, IdpCalKey, IDP_CAL_SET_CONFIG, &MdpPreviewPara);
        ErrorCode = MdpFunc.pfnIdpCalStart( ScenarioId, IdpCalKey);
        ASSERT(ErrorCode == MM_ERROR_NONE);

    #if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
        CalSceneCompensationConfig(ScenarioId, CalAsdSceneType, &IspSceneCompensationParaIn);
        pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_SCENE_COMPENSATION, &IspSceneCompensationParaIn, NULL, 0, &FeatureOutLen);
    #endif // __AUTO_SCENE_DETECT_SUPPORT__

        /* config and start ISP */
        IspPreviewPara.ImageTargetWidth=pCalMdpPreviewPara->DisplayImageWidth;
        IspPreviewPara.ImageTargetHeight=pCalMdpPreviewPara->DisplayImageHeight;
        IspPreviewPara.pCalIspPreviewPara=pCalIspPreviewPara;

        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_START;
        pIspScenarioCtrl->pScenarioCtrlPara=&IspPreviewPara;
        pIspScenarioCtrl->ScenarioCtrlParaLen=sizeof(ISP_CAMERA_PREVIEW_STRUCT);
        ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);
        if(MM_ERROR_NONE != ErrorCode)
        { //MM_ERROR_ISP_NO_VSYNC
            MdpFunc.pfnIdpCalClose(ScenarioId, IdpCalKey);
            CalState = CAL_STANDBY_STATE;

            #if (defined(__POSTPROC_SUPPORT__))
            /* Disable PP*/
            PostProcImageFromDisplayImage = KAL_FALSE;
            PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_STOP, 0, 0, 0);
            #endif /* defined(__POSTPROC_SUPPORT__) */

            CameraImageDisplayConfig(CAL_CTRL_CODE_STOP, pCalMdpPreviewPara->ImageDataFormat,
                                 DisplayImageSrcRotAngle,
                                 pCalMdpPreviewPara->DisplayImageWidth, pCalMdpPreviewPara->DisplayImageHeight,
                                 pCalMdpPreviewPara->FrameBuffAddr1, pCalMdpPreviewPara->FrameBuffAddr2, pCalMdpPreviewPara->FrameBuffAddr3);
            return ErrorCode;
        }

        if (CalPreviewInfo.LcdUpdateEnable)
        {
            DisplayPreviewFrameFlag=KAL_TRUE;
        }
        CalState = CAL_CAMERA_PREVIEW_STATE;

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_CAMERA_PREVIEW_COMPLETE);
    #endif
        return ErrorCode;
    }
    return ErrorCode;
} /* CalPreviewCtrl() */

MM_ERROR_CODE_ENUM CalStillCaptureCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    P_CAL_CAMERA_STILL_CAPTURE_STRUCT pCalCapturePara = (P_CAL_CAMERA_STILL_CAPTURE_STRUCT) pCtrlPara;
    P_CAL_ISP_STILL_CAPTURE_STRUCT pCalIspCapturePara=pCalCapturePara->pIspPara;
    P_CAL_JPEG_ENC_STRUCT pCalJpegEncPara=pCalCapturePara->pJpegEncPara;
    P_CAL_MDP_STILL_CAPTURE_STRUCT pCalMdpCapturePara=pCalCapturePara->pMdpPara;
    ISP_CAMERA_STILL_CAPTURE_STRUCT IspCapturePara;
    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT IspDigitalZoomResParaIn;
    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT IspDigitalZoomResParaOut;

    ISP_FEATURE_SET_TG_STRUCT IspTgSettingInfo;
    SENSOR_FRAMERATE_IN_STRUCT  SensorQueryFrameRateIn;
    SENSOR_FRAMERATE_OUT_STRUCT SensorQueryFrameRateOut;
#if defined(__JPEG_SENSOR_SUPPORT__)
    CAL_BUFFER_CB_STRUCT JpegCbPara;
    CAL_BUFFER_CB_STRUCT QuickViewCbPara;
#endif

    kal_uint32 FeatureOutLen;
    kal_uint32 CtrlOutLen;
    kal_uint32 ExtMemAddr, ExtMemSize;
    kal_uint16 SensorOutputTargetWidth, SensorOutputTargetHeight;
    kal_uint32 Resolution = 0;
    #if ((defined(__CAL_CAMERA_OVERLAY_SUPPORT__) && defined(__LCM_SCANLINE_ROTATION_SUPPORT__))||(defined(__CAL_CAMERA_OVERLAY_SUPPORT__)))
    kal_uint16 Temp;
    #endif

  #if defined(__CAL_CAMERA_OVERLAY_SUPPORT__)
    #if (defined (__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__) || defined (__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__)
    MM_IMAGE_ROTATE_ENUM AddedFrameRotateAngle=MM_IMAGE_ROTATE_0;
    #endif
  #endif

#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
    P_CAL_POSTPROC_STRUCT pCalPostProcCapturePara = pCalCapturePara->pPostProcPara;
#endif
    ISP_FEATURE_CONFIG_3A_BEFORE_CAPTURE_STRUCT IspConfig3APara;
#if defined(__JPEG_SENSOR_SUPPORT__)
    kal_uint32 JpegSensorAllocBuffSize;
    kal_uint32 JpegSensorBestBuffSize;
    JPEG_SENSOR_SET_BUFF_IN_STRUCT tmpJpegSensorSetBuffSzie;
#endif
#if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
    ISP_CAMERA_UPDATE_EXIF_INFO_STRUCT tmpIspUpdateExifInfo;
#endif 

#if (defined (MT6255)&&defined(__JPEG_SENSOR_SUPPORT__))
    kal_uint32 YUVMaxWidth = 0,YUVMaxHeight = 0;
#endif

    CurrentStillCaptureStatus=0;

    if (CAL_CTRL_CODE_STOP & CtrlCode)
    {
        if ((CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM!=CurrentStillScenarioId)
            || ((KAL_FALSE == CalStillCaptureInfo.ThumbnailImageEnable) && (KAL_FALSE == CalStillCaptureInfo.QuickViewImageEnable))
        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
            || (CalPanoEnabled)
        #endif
        #if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
            || (CAM_STILL_CAPTURE_RAW_DATA == CalStillCaptureMode)
        #endif
            )
        {
            pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
            ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);
        }

#if defined(__JPEG_SENSOR_SUPPORT__)
        if((IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG==CaptureFormatInfo.DataType)&&(IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG == CurrentSensorInfo.CaptureDataFormat))
        {//no need to do MDP or jpeg driver close
        #ifdef __CAL_PROFILING_ENABLE__
            CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_CAMERA_CAPTURE_COMPLETE);
        #endif
            return ErrorCode;
        }
#endif
    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE==ScenarioId)
        {
            if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM!=CurrentStillScenarioId)
                MdpFunc.pfnIdpCalClose(ScenarioId, IdpCalKey);

            DisplayPreviewFrameFlag=KAL_FALSE;
            CameraImageDisplayConfig(CtrlCode, (MM_IMAGE_FORMAT_ENUM) MdpPreviewPara.preview_image_color_format,
                                 (MM_IMAGE_ROTATE_ENUM) MdpPreviewPara.display_rot_angle,
                                 MdpPreviewPara.display_width, MdpPreviewPara.display_height,
                                 CalPreviewInfo.CameraAppFrameBuffAddr, MdpPreviewPara.frame_buffer_address2, MdpPreviewPara.frame_buffer_address3);
        }
        else
    #endif //__ZERO_SHUTTER_DELAY_SUPPORT__
        {
            /* stop idp & lcd driver */
            if ((CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM!=CurrentStillScenarioId)
                || ((KAL_FALSE == CalStillCaptureInfo.ThumbnailImageEnable) && (KAL_FALSE == CalStillCaptureInfo.QuickViewImageEnable))
            #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                || (CalPanoEnabled)
            #endif
            #if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
                || (CAM_STILL_CAPTURE_RAW_DATA == CalStillCaptureMode)
            #endif
                )
                MdpFunc.pfnIdpCalClose(CurrentStillScenarioId, IdpCalKey);
              #if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
              #endif
        }

        /* stop jpeg driver */
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        if ((!CalPanoEnabled) ||
            ((CalPanoEnabled) && (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM!=CurrentStillScenarioId)))
                jpeg_wrapper_close(JpegWrapperHandle);
    #endif

        CalState = CAL_STANDBY_STATE;
        // reset the value for avoiding wrong operation when HDR second wrong encode
        CurrentStillScenarioId = CAL_SCENARIO_MAX;//0xFF;

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_CAMERA_CAPTURE_COMPLETE);
    #endif
        return ErrorCode;
    }
    if (CAL_CTRL_CODE_START & CtrlCode)
    {
    #if (defined(__ZERO_SHUTTER_DELAY_SUPPORT__)&&defined(__POSTPROC_SUPPORT__))
        if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE==ScenarioId)
        {
            /* Disable PP*/
            PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_STOP, 0, 0, 0);
            PostProcImageFromDisplayImage=KAL_FALSE;
        }
    #endif //(defined(__ZERO_SHUTTER_DELAY_SUPPORT__)&&defined(__POSTPROC_SUPPORT__))

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_ENTER_CAPTURE);
    #endif
        CurrentStillScenarioId = ScenarioId;
    #if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
        CalStillCaptureMode = pCalIspCapturePara->StillCaptureMode;
    #endif
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if (pCalPostProcCapturePara->PostProcMode & PP_MODE_PANORAMA)
            CalPanoEnabled=KAL_TRUE;
        else
            CalPanoEnabled=KAL_FALSE;
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__

    #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
        if (pCalPostProcCapturePara->PostProcMode & PP_MODE_HDR)
            CalHdrEnabled=KAL_TRUE;
        else
            CalHdrEnabled=KAL_FALSE;
    #endif  //__HIGH_DYNAMIC_RANGE_SUPPORT__

        ExtMemAddr = pCalCapturePara->ExtmemStartAddress;
        ExtMemSize = pCalCapturePara->ExtmemSize;

#if ((defined(__PANORAMA_VIEW_SUPPORT__)&&defined(PANORAMA_INPUT_IMAGE_FORMAT_YUV420))||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if (pCalPostProcCapturePara->PostProcMode & PP_MODE_PANORAMA)
        {
            pCalIspCapturePara->RawImageBuffAddr=pCalMdpCapturePara->MainImageWorkingBuffAddr;
            pCalIspCapturePara->RawImageBuffSize=pCalMdpCapturePara->MainImageWorkingBuffSize;
        }
        else
#endif 
        { 
            {
                pCalIspCapturePara->RawImageBuffAddr=pCalMdpCapturePara->MainImageWorkingBuffAddr+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET;
                pCalIspCapturePara->RawImageBuffSize=pCalMdpCapturePara->MainImageWorkingBuffSize-CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET-CAL_JAIA_MEMORY_OFFSET;

            #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
                if (pCalMdpCapturePara->MainImageYUVEnagle == KAL_TRUE)
                {
                    pCalIspCapturePara->RawImageBuffAddr = pCalMdpCapturePara->MainImageYBuffAddr + CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET + CAL_JAIA_MEMORY_OFFSET;
                    pCalIspCapturePara->RawImageBuffSize = pCalMdpCapturePara->MainImageYBuffSize - CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET - CAL_JAIA_MEMORY_OFFSET;
                }
            #endif

            #if defined(__YUVCAM_INTERPOLATION_SW__)
                #if defined(__IMAGE_SENSOR_01M__)
                if ((pCalMdpCapturePara->MainImageWidth > 352) && (pCalMdpCapturePara->MainImageHeight > 288))
                {
                    pCalIspCapturePara->RawImageBuffAddr=pCalMdpCapturePara->MainImageWorkingBuffAddr+pCalMdpCapturePara->MainImageWorkingBuffSize-ISP_IMAGE_BUF_SIZE-CAL_QVI_ROT_WORKING_BUFF_SIZE;
                    pCalIspCapturePara->RawImageBuffSize=0;
                }
                #elif defined(__IMAGE_SENSOR_03M__)
                if ((pCalMdpCapturePara->MainImageWidth > 640) && (pCalMdpCapturePara->MainImageHeight > 480))
                {
                    pCalIspCapturePara->RawImageBuffAddr=pCalMdpCapturePara->MainImageWorkingBuffAddr+pCalMdpCapturePara->MainImageWorkingBuffSize-ISP_IMAGE_BUF_SIZE-CAL_QVI_ROT_WORKING_BUFF_SIZE;
                    pCalIspCapturePara->RawImageBuffSize=0;
                }
                #elif defined(__IMAGE_SENSOR_1M__)
                if ((pCalMdpCapturePara->MainImageWidth > 1280) && (pCalMdpCapturePara->MainImageHeight > 1024))
                {
                    pCalIspCapturePara->RawImageBuffAddr=pCalMdpCapturePara->MainImageWorkingBuffAddr+pCalMdpCapturePara->MainImageWorkingBuffSize-ISP_IMAGE_BUF_SIZE-CAL_QVI_ROT_WORKING_BUFF_SIZE;
                    pCalIspCapturePara->RawImageBuffSize=0;
                }
                #elif defined(__IMAGE_SENSOR_2M__)
                if ((pCalMdpCapturePara->MainImageWidth > 1600) && (pCalMdpCapturePara->MainImageHeight > 1200))
                {
                    pCalIspCapturePara->RawImageBuffAddr=pCalMdpCapturePara->MainImageWorkingBuffAddr+pCalMdpCapturePara->MainImageWorkingBuffSize-ISP_IMAGE_BUF_SIZE-CAL_QVI_ROT_WORKING_BUFF_SIZE;
                    pCalIspCapturePara->RawImageBuffSize=0;
                }
                #else
                #error "No support sensor resolution!"
                #endif
            #endif

                // set final main image YUV buffer to 2nd(belowest) buffer
                if (pCalMdpCapturePara->ImageJaiaDisable == KAL_TRUE)
                {
                    kal_uint32 bottom_size;

                    bottom_size = (pCalMdpCapturePara->MainImageWidth * pCalMdpCapturePara->MainImageHeight * 3 / 2);
                    #if defined(MT6250)||defined(MT6260)
                    if (pCalMdpCapturePara->MainImageWidth > 800)
                    {
                        bottom_size = (IMAGE_SENSOR_SOURCE_MAX_WIDTH-6) * (IMAGE_SENSOR_SOURCE_MAX_HEIGHT-6) * 3 / 2;
                    }
                    #elif defined(MT6252)
                    if (pCalMdpCapturePara->MainImageWidth > 320)
                    {
                        bottom_size = (IMAGE_SENSOR_SOURCE_MAX_WIDTH-6) * (IMAGE_SENSOR_SOURCE_MAX_HEIGHT-6) * 3 / 2;
                    }
                    #endif

                    pCalIspCapturePara->RawImageBuffSize = pCalMdpCapturePara->MainImageWorkingBuffSize - bottom_size;
                    pCalIspCapturePara->RawImageBuffAddr = pCalMdpCapturePara->MainImageWorkingBuffAddr + pCalIspCapturePara->RawImageBuffSize;

                    #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
                    ASSERT(pCalMdpCapturePara->MainImageYUVEnagle == KAL_FALSE);
                    #endif
                }
            }
        }

    #if defined(EXIF_SUPPORT)
        if ((KAL_TRUE==pCalIspCapturePara->RawCaptureEnable)&&
            (JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE<pCalIspCapturePara->RawImageBuffSize))
        {
            JaiaMergePara.WorkingBuffAddr=pCalIspCapturePara->RawImageBuffAddr+pCalIspCapturePara->RawImageBuffSize-JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE;//-32;
            JaiaMergePara.WorkingBuffSize=JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE;
        }
        else
        {
            JaiaMergePara.WorkingBuffAddr=pCalMdpCapturePara->MainImageWorkingBuffAddr + pCalMdpCapturePara->MainImageWorkingBuffSize - JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE;// - 32;
            JaiaMergePara.WorkingBuffSize=JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE;
        }
        JaiaMergePara.WorkingBuffAddr -= CAL_QVI_ROT_WORKING_BUFF_SIZE;

        #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
        if (pCalMdpCapturePara->MainImageYUVEnagle == KAL_TRUE)
        {
            JaiaMergePara.WorkingBuffAddr = pCalMdpCapturePara->MainImageUBuffAddr;
        }
        #endif
    #endif

        // Cannot remove, yuv sensor need flashlight parameter
        IspConfig3APara.BinningMode=pCalIspCapturePara->BinningMode;
        IspConfig3APara.ExpoBracketLevel=pCalIspCapturePara->ExpoBracketLevel;
        IspConfig3APara.RawCaptureEnable=pCalIspCapturePara->RawCaptureEnable;
        IspConfig3APara.MultishotInfo= pCalIspCapturePara->MultishotInfo;
        IspConfig3APara.StillCaptureMode=pCalIspCapturePara->StillCaptureMode;

        CurrentStillCaptureMask=CAL_STILL_CAPTURE_MAIN_IMAGE_BIT;
        if (KAL_TRUE==pCalMdpCapturePara->QuickViewImageEnable)
            CurrentStillCaptureMask |= CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT;
        if (KAL_TRUE==pCalMdpCapturePara->ThumbnailImageEnable)
            CurrentStillCaptureMask |= CAL_STILL_CAPTURE_THUMBNAIL_IMAGE_BIT;

        kal_mem_cpy(&CalStillCaptureInfo, pCalMdpCapturePara, sizeof(CAL_MDP_STILL_CAPTURE_STRUCT));

        if (IMAGE_SENSOR_MIRROR_HV==SensorScenarioParaIn.ImageMirror)
        {
            CalStillCaptureInfo.MainImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.MainImageRotAngle, MM_IMAGE_ROTATE_180);
            CalStillCaptureInfo.QuickViewImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.QuickViewImageRotAngle, MM_IMAGE_ROTATE_180);
        }
    #ifdef __CAL_DUAL_CAMERA_SUPPORT__  // only front camera need to do H mirror that will result in setting ImageMirror as V mirror
        else if (IMAGE_SENSOR_MIRROR_V==SensorScenarioParaIn.ImageMirror)
        {
            CalStillCaptureInfo.MainImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.MainImageRotAngle, MM_IMAGE_H_MIRROR_ROTATE_180);
            CalStillCaptureInfo.QuickViewImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.QuickViewImageRotAngle, MM_IMAGE_H_MIRROR_ROTATE_180);
        }
    #endif
        else if (IMAGE_SENSOR_MIRROR_H==SensorScenarioParaIn.ImageMirror)
        {
            CalStillCaptureInfo.MainImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.MainImageRotAngle, MM_IMAGE_H_MIRROR);
            CalStillCaptureInfo.QuickViewImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.QuickViewImageRotAngle, MM_IMAGE_H_MIRROR);
        }

  #if defined(__CAL_CAMERA_OVERLAY_SUPPORT__)
    #if defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__)
        AddedFrameRotateAngle = CalStillCaptureInfo.MainImageRotAngle;
    #elif defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__)
        AddedFrameRotateAngle = pCalMdpCapturePara->MainImageRotAngle;
    #endif
  #endif

     #if (!defined(DRV_IDP_6252_SERIES))
        MdpStillCapturePara.fullsize_image_rot_angle = (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
        MdpStillCapturePara.quickview_image_rot_angle = (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
        MdpStillCapturePara.thumbnail_image_rot_angle = (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
    #endif

        if (((IMAGE_SENSOR_SOURCE_MAX_WIDTH==IMAGE_03M_MAX_WIDTH) && (CAM_IMAGE_SIZE_WALLPAPER==CurrentStillCaptureSize))||
            ((IMAGE_SENSOR_SOURCE_MAX_WIDTH!=IMAGE_03M_MAX_WIDTH) && (CurrentStillCaptureSize<=CAM_IMAGE_SIZE_VGA))||
            ((CAM_IMAGE_SIZE_OTHER==CurrentStillCaptureSize) && (pCalMdpCapturePara->MainImageWidth<=LCD_WIDTH) && (pCalMdpCapturePara->MainImageHeight<=LCD_HEIGHT))||
            ((CAM_IMAGE_SIZE_OTHER==CurrentStillCaptureSize) && (pCalMdpCapturePara->MainImageWidth<=LCD_HEIGHT) && (pCalMdpCapturePara->MainImageHeight<=LCD_WIDTH))||
            ((CAM_IMAGE_SIZE_OTHER==CurrentStillCaptureSize) && (pCalMdpCapturePara->MainImageWidth<=640) && (pCalMdpCapturePara->MainImageHeight<=480))||
            ((CAM_IMAGE_SIZE_OTHER==CurrentStillCaptureSize) && (pCalMdpCapturePara->MainImageWidth<=480) && (pCalMdpCapturePara->MainImageHeight<=640))
            #if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
            ||(CAM_STILL_CAPTURE_RAW_DATA==pCalIspCapturePara->StillCaptureMode)
            #endif
            )
        {   // use SW rotate
            CurrentStillScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM;
            IspCapturePara.StillImageExifOrientation = (MM_IMAGE_ROTATE_ENUM) ExifOrientationMapTable[MM_IMAGE_ROTATE_0];
            PpMainImageRotAngle=MM_IMAGE_ROTATE_0;

    #ifndef __CAL_STILL_CAPTURE_ROTATE_SUPPORT__
        #ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
            if (pCalMdpCapturePara->MainImageRotAngle & 0x01)
            {
                // swap widht/height of main image and thumbnail image because we will not rotate the image
                CalStillCaptureInfo.MainImageHeight = pCalMdpCapturePara->MainImageWidth;
                CalStillCaptureInfo.MainImageWidth=pCalMdpCapturePara->MainImageHeight;
                pCalMdpCapturePara->MainImageWidth = CalStillCaptureInfo.MainImageWidth;
                pCalMdpCapturePara->MainImageHeight = CalStillCaptureInfo.MainImageHeight;
                CalStillCaptureInfo.ThumbnailImageHeight = pCalMdpCapturePara->ThumbnailImageWidth;
                CalStillCaptureInfo.ThumbnailImageWidth=pCalMdpCapturePara->ThumbnailImageHeight;
                pCalMdpCapturePara->ThumbnailImageWidth = CalStillCaptureInfo.ThumbnailImageWidth;
                pCalMdpCapturePara->ThumbnailImageHeight = CalStillCaptureInfo.ThumbnailImageHeight;
                CalStillCaptureInfo.QuickViewImageHeight = pCalMdpCapturePara->QuickViewImageWidth;
                CalStillCaptureInfo.QuickViewImageWidth=pCalMdpCapturePara->QuickViewImageHeight;
                pCalMdpCapturePara->QuickViewImageWidth = CalStillCaptureInfo.QuickViewImageWidth;
                pCalMdpCapturePara->QuickViewImageHeight = CalStillCaptureInfo.QuickViewImageHeight;
            }
            IspCapturePara.StillImageExifOrientation = (MM_IMAGE_ROTATE_ENUM) ExifOrientationMapTable[CalStillCaptureInfo.MainImageRotAngle];
            PpMainImageRotAngle=CalStillCaptureInfo.MainImageRotAngle;
            CalStillCaptureInfo.MainImageRotAngle = MM_IMAGE_ROTATE_0;
        #else
            if (CAM_IMAGE_SIZE_WALLPAPER!=CurrentStillCaptureSize)
            {
                IspCapturePara.StillImageExifOrientation = (MM_IMAGE_ROTATE_ENUM) ExifOrientationMapTable[CalStillCaptureInfo.MainImageRotAngle];
                PpMainImageRotAngle=CalStillCaptureInfo.MainImageRotAngle;
                CalStillCaptureInfo.MainImageRotAngle = MM_IMAGE_ROTATE_0;
            }
        #endif
    #endif
        #if (defined(DRV_IDP_6252_SERIES))
            // do not apply capture to memory to avoid the requirement of rotation memory
            if (MM_IMAGE_ROTATE_0==CalStillCaptureInfo.MainImageRotAngle)
                CurrentStillScenarioId = ScenarioId;
        #endif
        }
        else
    #ifdef __CAL_STILL_CAPTURE_ROTATE_SUPPORT__
        {   // use HW rotate
            MdpStillCapturePara.fullsize_image_rot_angle = CalStillCaptureInfo.MainImageRotAngle;
            MdpStillCapturePara.quickview_image_rot_angle = CalStillCaptureInfo.MainImageRotAngle;
            MdpStillCapturePara.thumbnail_image_rot_angle = CalStillCaptureInfo.MainImageRotAngle;
            IspCapturePara.StillImageExifOrientation = ExifOrientationMapTable[MM_IMAGE_ROTATE_0];
            PpMainImageRotAngle=MM_IMAGE_ROTATE_0;
        }
    #else
        {   // do not rotate
        #ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
            if (pCalMdpCapturePara->MainImageRotAngle & 0x01)
            {   // swap widht/height of main image and thumbnail image because we will not rotate the image
                CalStillCaptureInfo.MainImageHeight = pCalMdpCapturePara->MainImageWidth;
                CalStillCaptureInfo.MainImageWidth=pCalMdpCapturePara->MainImageHeight;
                pCalMdpCapturePara->MainImageWidth = CalStillCaptureInfo.MainImageWidth;
                pCalMdpCapturePara->MainImageHeight = CalStillCaptureInfo.MainImageHeight;
                CalStillCaptureInfo.ThumbnailImageHeight = pCalMdpCapturePara->ThumbnailImageWidth;
                CalStillCaptureInfo.ThumbnailImageWidth=pCalMdpCapturePara->ThumbnailImageHeight;
                pCalMdpCapturePara->ThumbnailImageWidth = CalStillCaptureInfo.ThumbnailImageWidth;
                pCalMdpCapturePara->ThumbnailImageHeight = CalStillCaptureInfo.ThumbnailImageHeight;
                CalStillCaptureInfo.QuickViewImageHeight = pCalMdpCapturePara->QuickViewImageWidth;
                CalStillCaptureInfo.QuickViewImageWidth=pCalMdpCapturePara->QuickViewImageHeight;
                pCalMdpCapturePara->QuickViewImageWidth = CalStillCaptureInfo.QuickViewImageWidth;
                pCalMdpCapturePara->QuickViewImageHeight = CalStillCaptureInfo.QuickViewImageHeight;
            }
        #endif

            IspCapturePara.StillImageExifOrientation = (MM_IMAGE_ROTATE_ENUM) ExifOrientationMapTable[CalStillCaptureInfo.MainImageRotAngle];
            PpMainImageRotAngle=CalStillCaptureInfo.MainImageRotAngle;
            CalStillCaptureInfo.MainImageRotAngle = MM_IMAGE_ROTATE_0;
        }
    #endif

        CalStillCaptureInfo.QuickViewImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.QuickViewImageRotAngle, CalStillCaptureInfo.MainImageRotAngle);
        #if defined(DRV_IDP_6252_SERIES)
        if (MM_IMAGE_ROTATE_0_WITH_LCD_CONFIG == CalStillCaptureInfo.QuickViewImageLCDRotAngle)
        {
             if ((MM_IMAGE_ROTATE_0 !=(CalStillCaptureInfo.QuickViewImageRotAngle+ CalStillCaptureInfo.MainImageRotAngle)) &&
                  (MM_IMAGE_ROTATE_0 !=GetRestRotAngle(MdpDisplayImageRotAngle, (MM_IMAGE_ROTATE_ENUM)(CalStillCaptureInfo.QuickViewImageRotAngle+CalStillCaptureInfo.MainImageRotAngle))))
             {
                 CalStillCaptureInfo.QuickViewImageRotAngle=GetRestRotAngle(MdpDisplayImageRotAngle,CalStillCaptureInfo.MainImageRotAngle);
             }
        }
        #endif

#if ((defined(MT6255) || defined(MT6256)) && defined(__JPEG_SENSOR_SUPPORT__))
        if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM == CurrentStillScenarioId)
        {
            ExtMemAddr = pCalMdpCapturePara->MainImageWorkingBuffAddr + pCalMdpCapturePara->MainImageWorkingBuffSize - CAL_QVI_ROT_WORKING_BUFF_SIZE - JPEG_ENC_EXT_MIN_MEM_SIZE;
            ExtMemSize  = JPEG_ENC_EXT_MIN_MEM_SIZE;
        }
        else
        {
            ExtMemAddr = pCalMdpCapturePara->MainImageWorkingBuffAddr+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET+ISP_IMAGE_BUF_SIZE;
            ExtMemSize  = IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM;
        }
#endif

    #if (defined(__CAL_CAMERA_OVERLAY_SUPPORT__) && defined(__LCM_SCANLINE_ROTATION_SUPPORT__))
        if ((MM_IMAGE_ROTATE_0 !=CalStillCaptureInfo.MainImageRotAngle) && (KAL_TRUE==pCalMdpCapturePara->OverlayEnable))
        {   /* rotate the overlay frame buffer*/
            if ((CAM_STILL_CAPTURE_BURST_SHOT!=pCalIspCapturePara->StillCaptureMode) ||
                ((CAM_STILL_CAPTURE_BURST_SHOT==pCalIspCapturePara->StillCaptureMode)&& (MULTISHOT_FIRST==pCalIspCapturePara->MultishotInfo)))
            {
                StillImageOverlayRotateAngle= RotateOverlayFrameBuffer((kal_uint32 *) &(pCalMdpCapturePara->OverlayFrameBuffAddr),
                                                             (kal_uint32 *) &(pCalMdpCapturePara->MainImageWorkingBuffAddr),
                                                             pCalMdpCapturePara-> OverlayFrameWidth, pCalMdpCapturePara-> OverlayFrameHeight,
                                                             CalStillCaptureInfo.MainImageRotAngle);
            }

            if (StillImageOverlayRotateAngle & 0x01)
            {
                Temp = pCalMdpCapturePara-> OverlayFrameWidth;
                pCalMdpCapturePara-> OverlayFrameWidth = pCalMdpCapturePara-> OverlayFrameHeight;
                pCalMdpCapturePara-> OverlayFrameHeight = Temp;
            }
        }
    #elif (defined(__CAL_CAMERA_OVERLAY_SUPPORT__))
        if ((MM_IMAGE_ROTATE_0 !=AddedFrameRotateAngle) && (KAL_TRUE==pCalMdpCapturePara->OverlayEnable))
        {   /* rotate the overlay frame buffer*/
            // in BY_ENCODE and capture to memory case, the still image will be rotate by SW, such that
            // we have to rotate the added frame first then rotate it back by SW.
            // in BY_TAG case, the still image will not be rotated that we have to rotate the added
            // frame to fit the still image.
        #ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__
            if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
        #endif
            {
                StillImageOverlayRotateAngle= RotateOverlayFrameBuffer((kal_uint32 *) &(pCalMdpCapturePara->OverlayFrameBuffAddr),
                                                             (kal_uint32 *) &(pCalMdpCapturePara->MainImageWorkingBuffAddr),
                                                             pCalMdpCapturePara-> OverlayFrameWidth, pCalMdpCapturePara-> OverlayFrameHeight,
                                                             AddedFrameRotateAngle);
            }

            if (StillImageOverlayRotateAngle & 0x01)
            {
                Temp = pCalMdpCapturePara-> OverlayFrameWidth;
                pCalMdpCapturePara-> OverlayFrameWidth = pCalMdpCapturePara-> OverlayFrameHeight;
                pCalMdpCapturePara-> OverlayFrameHeight = Temp;
            }
        }
    #endif
 
    #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if (pCalPostProcCapturePara->PostProcMode & PP_MODE_PANORAMA)
        {
            CurrentStillScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM;
        }
    #endif

        if (CalStillCaptureInfo.MainImageRotAngle & 0x01)
        {
            SensorOutputTargetWidth = pCalMdpCapturePara->MainImageHeight;
            SensorOutputTargetHeight = pCalMdpCapturePara->MainImageWidth;
        }
        else
        {
            SensorOutputTargetWidth = pCalMdpCapturePara->MainImageWidth;
            SensorOutputTargetHeight = pCalMdpCapturePara->MainImageHeight;
        }

        #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
            if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
        #endif
        {   // SW JPEG encoder
            pCalJpegEncPara->JpegSamplingFormat = MM_IMAGE_FORMAT_YUV420;
        #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
            pCalMdpCapturePara->MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_RGB565;
            CalStillCaptureInfo.MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_RGB565;
        #elif defined(MT6235) || defined(MT6235B) || defined(MT6253)
            if (pCalMdpCapturePara->MainImageWidth & 15) // width is NOT 16 multiple
            {
                pCalMdpCapturePara->MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_RGB565;
                CalStillCaptureInfo.MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_RGB565;
            }
            else
            {
                pCalMdpCapturePara->MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_YUV420;
                CalStillCaptureInfo.MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_YUV420;
            }
        #else
            pCalMdpCapturePara->MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_YUV420;
            CalStillCaptureInfo.MainImageJpegYuvSampleFormat = MM_IMAGE_FORMAT_YUV420;
        #endif
        }

        IspTgSettingInfo.ScenarioId=CAL_SCENARIO_CAMERA_STILL_CAPTURE;
        IspTgSettingInfo.pSensorInfo=(void *) &CurrentSensorInfo;
        /// Bin: ISP_FEATURE_CONFIG_3A_BEFORE_SENSOR_SWITCH_CAPTURE
        ///       this is not just for RAW,  since YUV flashlight pre strobe for FLASE AE and AWB also execute here

    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE!=ScenarioId)
    #endif
        {
            // Cannot remove, yuv sensor need flashlight parameter
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_CONFIG_3A_BEFORE_SENSOR_SWITCH_CAPTURE, &IspConfig3APara, NULL, 0, &FeatureOutLen);
 
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_TG, &IspTgSettingInfo, NULL, 0, &FeatureOutLen);

            // get current zoom information for calculateing digital zoom size
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_CURRENT_ZOOM_INFO, NULL, (void *) &CurrentZoomInfo, 0, &FeatureOutLen);

            SensorScenarioParaIn.ImageTargetWidth=SensorOutputTargetWidth;
            SensorScenarioParaIn.ImageTargetHeight=SensorOutputTargetHeight;
        }

        #if defined(__JPEG_SENSOR_SUPPORT__)
        if((IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG==CaptureFormatInfo.DataType)&&(IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG == CurrentSensorInfo.CaptureDataFormat))
        {
            JpegSensorBestBuffSize=  CalJpegCaptureBufferSize[CurrentStillCaptureSize] ;

            JpegSensorAllocBuffSize =(pCalMdpCapturePara->MainImageBuffSize-CAL_JAIA_MEMORY_OFFSET);
            #if defined(MT6255)
            MdpStillCapturePara.extmem_start_address =ExtMemAddr+ExtMemSize-ISP_EXT_WORKING_BUF_SIZE;
            MdpStillCapturePara.extmem_size = ISP_EXT_WORKING_BUF_SIZE;
            #elif defined(MT6256)
            MdpStillCapturePara.extmem_start_address =ExtMemAddr+MAX_STILL_CAPTURE_JPEG_BUFF_SIZE;
            MdpStillCapturePara.extmem_size = ISP_EXT_WORKING_BUF_SIZE;
            #else
            MdpStillCapturePara.extmem_start_address =ExtMemAddr;
            MdpStillCapturePara.extmem_size = ExtMemSize;
            #endif

            JpegSensorParaIn.WorkingBuffAddress= (MdpStillCapturePara.extmem_start_address +15)&0xfffffff0;
            JpegSensorParaIn.WorkingBuffSize = ISP_JPEG_SENSOR_PARSE_BUF_SIZE;//ISP_EXT_WORKING_BUF_SIZE;

            JpegSensorParaIn.ImageBuffAddress = (pCalMdpCapturePara->MainImageBuffAddr+CAL_JAIA_MEMORY_OFFSET+15)&0xfffffff0;//ISP_EXT_WORKING_BUF_SIZE;
            #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
            if (pCalMdpCapturePara->MainImageYUVEnagle == KAL_TRUE)
            {
                JpegSensorParaIn.ImageBuffAddress = (pCalMdpCapturePara->MainImageYBuffAddr+CAL_JAIA_MEMORY_OFFSET+15)&0xfffffff0;//ISP_EXT_WORKING_BUF_SIZE;
            }
            #endif

            SensorScenarioParaIn.JpegSensorBufferSize = (CAL_MIN(JpegSensorBestBuffSize, JpegSensorAllocBuffSize)&0xfffffff0);
            JpegSensorParaIn.ImageBuffSize =SensorScenarioParaIn.JpegSensorBufferSize;
            #if defined(EXIF_SUPPORT)
            JaiaMergePara.ExifWholeInfoAttach = KAL_TRUE;
            #endif

            if (MM_IMAGE_ROTATE_0 != CalStillCaptureInfo.QuickViewImageRotAngle)
            {
                QuickViewImageDestBuffAddr = CalStillCaptureInfo.QuickViewImageBuffAddr;
                #if ((defined (MT6255) || defined (MT6256)) && defined(__JPEG_SENSOR_SUPPORT__))
                CalStillCaptureInfo.QuickViewImageBuffAddr = pCalMdpCapturePara->MainImageWorkingBuffAddr + pCalMdpCapturePara->MainImageWorkingBuffSize - CAL_QVI_ROT_WORKING_BUFF_SIZE;
                #else
                CalStillCaptureInfo.QuickViewImageBuffAddr = ExtMemAddr;
                #endif

                if (NULL !=CalExtraQVIBuffAddr)
                {
                    CalStillCaptureInfo.QuickViewImageBuffAddr = CalExtraQVIBuffAddr;
                    if (CalExtraQVIBuffSize != CalStillCaptureInfo.QuickViewImageBuffSize)
                         ASSERT(0);
                    CalExtraQVIBuffAddr = NULL;
                }
            }
        }
        else
        #endif
        #if defined(EXIF_SUPPORT)
        {
            JaiaMergePara.ExifWholeInfoAttach = KAL_FALSE;
        }
        #endif

        SensorScenarioParaIn.MetaMode=CAMERA_SYSTEM_NORMAL_MODE;
        if ((MULTISHOT_FALSE==pCalIspCapturePara->MultishotInfo)||
            (MULTISHOT_FIRST==pCalIspCapturePara->MultishotInfo)
        #ifdef __CAL_CAPTURE_MODE_EV_BRACKET_SUPPORT__
            ||(CAM_STILL_CAPTURE_EV_BRACKETING==pCalIspCapturePara->StillCaptureMode)
        #endif
           )
        {
        #ifdef __CAL_PROFILING_ENABLE__
            CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_BEFORE_CONFIG_SENSOR_DRIVER);
        #endif
            /* config sensor driver */
            SensorScenarioParaIn.EnableShutterTransfer=KAL_FALSE;
            SensorScenarioParaIn.ZoomFactor=CurrentZoomInfo.CurrentZoomFactor;
            SensorScenarioParaIn.JpegEncQuality=pCalJpegEncPara->JpegEncQuality;
            /* cct select to capture by sensor preview mode */ 
            {
            #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
                if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE!=ScenarioId)
            #endif
                {
                    SensorQueryFrameRateIn.Scenario= ScenarioId;
                    SensorQueryFrameRateIn.CameraIf=  CurrentSensorInfo.SensorIf;
                    SensorQueryFrameRateIn.DataFormat= CurrentSensorInfo.PreviewNormalDataFormat;
                    if((SensorScenarioParaIn.ImageTargetWidth<=CurrentSensorInfo.PreviewWidth)
                        &&(SensorScenarioParaIn.ImageTargetHeight<=CurrentSensorInfo.PreviewHeight))
                    {
                        SensorQueryFrameRateIn.SourceWidth= CurrentSensorInfo.PreviewWidth;
                        SensorQueryFrameRateIn.SourceHeight= CurrentSensorInfo.PreviewHeight;
                    }
                    else
                    {
                        SensorQueryFrameRateIn.SourceWidth= CurrentSensorInfo.FullWidth;
                        SensorQueryFrameRateIn.SourceHeight= CurrentSensorInfo.FullHeight;
                    }
                    SensorQueryFrameRateIn.NighhtMode= SensorScenarioParaIn.NightMode;
                    ErrorCode= SensorCommonGetFrameRate(&SensorQueryFrameRateIn, &SensorQueryFrameRateOut);
                    if(ErrorCode == MM_ERROR_NONE)
                        SensorScenarioParaIn.MaxVideoFrameRate = SensorQueryFrameRateOut.MaxSensorFrameRate;
                    else
                        SensorScenarioParaIn.MaxVideoFrameRate = 150;
                    pfImageSensor->SensorCtrl(ScenarioId, &SensorScenarioParaIn, &SensorScenarioParaOut,
                                          sizeof(IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT), &CtrlOutLen);
                }
            }
        #ifdef __CAL_PROFILING_ENABLE__
            CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_CONFIG_SENSOR_DRIVER_COMPLETE);
        #endif
        }

    #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if (pCalPostProcCapturePara->PostProcMode & PP_MODE_PANORAMA)
        {
            pIspGetOutResParaIn->RawCaptureEnable=KAL_FALSE;
        }
    #endif
        pIspGetOutResParaIn->IspState=ISP_CAPTURE_JPEG_STATE;

    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE!=ScenarioId)
    #endif
        {

            ErrorCode=ConfigIspGetResPara(CurrentZoomInfo.CurrentZoomStep, SensorOutputTargetWidth,
                                          SensorOutputTargetHeight,CurrentDzInfo.DzType);
        }

        IspDigitalZoomResParaIn.DzType=CurrentDzInfo.DzType;
        IspDigitalZoomResParaIn.pZoomFactorListTable=CurrentDzInfo.pZoomFactorListTable;
        IspDigitalZoomResParaIn.ZoomStep=CurrentZoomInfo.CurrentZoomStep;
        ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION, &IspDigitalZoomResParaIn,
                                            &IspDigitalZoomResParaOut, sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT),
                                            &FeatureOutLen);
        MdpStillCapturePara.mdp_crop_enable=IspDigitalZoomResParaOut.MdpCropEnable;
        MdpStillCapturePara.cropped_width=IspDigitalZoomResParaOut.DigitalZoomWidth;
        MdpStillCapturePara.cropped_height=IspDigitalZoomResParaOut.DigitalZoomHeight;

    #if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
        CalSceneCompensationConfig(ScenarioId, CalAsdSceneType, &IspSceneCompensationParaIn);
        pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_SCENE_COMPENSATION, &IspSceneCompensationParaIn, NULL, 0, &FeatureOutLen);
    #endif // __AUTO_SCENE_DETECT_SUPPORT__

        /* config ISP */
        IspCapturePara.ImageMirror=SensorScenarioParaIn.ImageMirror;
        IspCapturePara.ImageTargetWidth=CalStillCaptureInfo.MainImageWidth;
        IspCapturePara.ImageTargetHeight=CalStillCaptureInfo.MainImageHeight;
        IspCapturePara.pCalIspCapturePara=pCalIspCapturePara;

        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_START;
        pIspScenarioCtrl->pScenarioCtrlPara=&IspCapturePara;
        pIspScenarioCtrl->ScenarioCtrlParaLen=sizeof(ISP_CAMERA_STILL_CAPTURE_STRUCT);

        {
        #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
            if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE==ScenarioId)
            {
                tmpIspUpdateExifInfo.StillImageExifOrientation=IspCapturePara.StillImageExifOrientation;
                tmpIspUpdateExifInfo.ImageTargetWidth = pCalMdpCapturePara->MainImageWidth;
                tmpIspUpdateExifInfo.ImageTargetHeight = pCalMdpCapturePara->MainImageHeight;
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_UPDATE_EXIF_INFO, (void *) &tmpIspUpdateExifInfo, NULL, 0, &FeatureOutLen);

            #if (defined(__JPEG_SENSOR_SUPPORT__))
                CaptureFormatInfo.DataType=IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
                ErrorCode =pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_CAPTURE_FORMAT, &CaptureFormatInfo, NULL , 0, NULL);
            #endif
            }
            else
        #endif //__ZERO_SHUTTER_DELAY_SUPPORT__
            {
                /* make sure sensor capture mode stable before we start MDP */
                ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);
            }
        }

#if defined(__JPEG_SENSOR_SUPPORT__)
        if((IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG==CaptureFormatInfo.DataType)&&(IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG == CurrentSensorInfo.CaptureDataFormat))
        {   //jpeg sensor capture case
            /* start ISP */
            tmpJpegSensorSetBuffSzie.JpegSensorBufferSize = SensorScenarioParaIn.JpegSensorBufferSize;
            ErrorCode =  pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_JPEG_BUFF_SIZE, &tmpJpegSensorSetBuffSzie, NULL,  sizeof(JPEG_SENSOR_SET_BUFF_IN_STRUCT),&CtrlOutLen);

            MdpStillCapturePara.source_width = pIspGetOutResParaOut->IspOutWidth;
            MdpStillCapturePara.source_height = pIspGetOutResParaOut->IspOutHeight;
            MdpStillCapturePara.quickview_pitch_enable = KAL_FALSE;
            MdpStillCapturePara.quickview_pitch_width = 0;
        #ifdef __CAL_CAMERA_OVERLAY_SUPPORT__
            MdpStillCapturePara.enable_overlay = pCalMdpCapturePara->OverlayEnable;
            MdpStillCapturePara.overlay_palette_size = pCalMdpCapturePara->OverlayPaletteSize;
            MdpStillCapturePara.overlay_palette_addr = pCalMdpCapturePara->OverlayPaletteAddr;
            MdpStillCapturePara.overlay_color_depth = pCalMdpCapturePara->OverlayColorDepth;
            MdpStillCapturePara.overlay_frame_source_key = pCalMdpCapturePara->OverlayFrameSourceKey;
            MdpStillCapturePara.overlay_frame_width = pCalMdpCapturePara-> OverlayFrameWidth;
            MdpStillCapturePara.overlay_frame_height = pCalMdpCapturePara->OverlayFrameHeight;
            MdpStillCapturePara.overlay_frame_buffer_address = pCalMdpCapturePara->OverlayFrameBuffAddr;
        #else
            MdpStillCapturePara.enable_overlay=KAL_FALSE;
        #endif
            MdpStillCapturePara.fullsize_image_width = pCalMdpCapturePara->MainImageWidth;
            MdpStillCapturePara.fullsize_image_height = pCalMdpCapturePara->MainImageHeight;
            MdpStillCapturePara.fullsize_image_jpeg_yuv_mode = pCalMdpCapturePara->MainImageJpegYuvSampleFormat;
            MdpStillCapturePara.fullsize_image_format=pCalMdpCapturePara->MainImageDataFormat;
            #ifdef __CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__
            CalStillCaptureInfo.ThumbnailImageFormat=MM_IMAGE_FORMAT_YUV420;
            #else
            CalStillCaptureInfo.ThumbnailImageFormat=MM_IMAGE_FORMAT_RGB565;
            #endif

            CalJpegCaptureRetry = 0;
            ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);

            CalState = CAL_CAMERA_CAPTURE_STATE;

            if(ErrorCode == MM_ERROR_CAL_STILL_CAPTURE_TIMEOUT)
            {
                if(CalStillCaptureInfo.QuickViewImageEnable)
                {
                    // 4.callback to MED
                    QuickViewCbPara.ErrorStatus=MM_ERROR_CAL_STILL_CAPTURE_TIMEOUT;
                    pfCalCallback(CAL_CBID_QUICK_VIEW_IMAGE_READY, &QuickViewCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
                }
                JpegCbPara.ErrorStatus=MM_ERROR_CAL_STILL_CAPTURE_TIMEOUT;
                pfCalCallback(CAL_CBID_MAIN_IMAGE_READY, &JpegCbPara, sizeof(CAL_BUFFER_CB_STRUCT));
            }

            return ErrorCode;
        }
#endif

        /* start jpeg driver */
        JpegWrapper.srcWindow.x=0;  // reset srcWindow
        JpegWrapper.srcWindow.y=0;
        JpegWrapper.srcWindow.w=0;
        JpegWrapper.srcWindow.h=0;
        JpegWrapper.srcWidth=pCalMdpCapturePara->MainImageWidth;
        JpegWrapper.srcHeight=pCalMdpCapturePara->MainImageHeight;
        JpegWrapper.dstWidth=pCalMdpCapturePara->MainImageWidth;
        JpegWrapper.dstHeight=pCalMdpCapturePara->MainImageHeight;
        JpegWrapper.dstBufferAddr=(void *) (pCalMdpCapturePara->MainImageBuffAddr+CAL_JAIA_MEMORY_OFFSET);
        #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
        if (pCalMdpCapturePara->MainImageYUVEnagle == KAL_TRUE)
        {
            JpegWrapper.dstBufferAddr=(void *) (pCalMdpCapturePara->MainImageYBuffAddr+CAL_JAIA_MEMORY_OFFSET);
        }
        #endif

        JpegWrapper.dstBufferSize=MAX_STILL_CAPTURE_JPEG_BUFF_SIZE-CAL_JAIA_MEMORY_OFFSET;

        // if no jaia, dest buffer without jaia offset
        if (CalStillCaptureInfo.ImageJaiaDisable == KAL_TRUE)
        {
            JpegWrapper.dstBufferAddr = (void *) (pCalMdpCapturePara->MainImageBuffAddr);
            JpegWrapper.dstBufferSize = MAX_STILL_CAPTURE_JPEG_BUFF_SIZE;
        }

        if (CAM_EFFECT_ENC_NORMAL!=SensorScenarioParaIn.ImageEffect)
        {
            if (JPEG_ENCODE_QUALITY_LOW==pCalJpegEncPara->JpegEncQuality)
                JpegWrapper.dstQuality=JPEG_ENCODE_QUALITY_POOR;
            else if (JPEG_ENCODE_QUALITY_POOR==pCalJpegEncPara->JpegEncQuality)
                JpegWrapper.dstQuality=pCalJpegEncPara->JpegEncQuality;
            else
                JpegWrapper.dstQuality=(JPEG_ENCODE_QUALITTY_ENUM) (pCalJpegEncPara->JpegEncQuality-1);
        }
        else
            JpegWrapper.dstQuality=pCalJpegEncPara->JpegEncQuality;

        JpegWrapper.srcSamplingFormat=GetJpegWrapperFormat(pCalJpegEncPara->JpegSamplingFormat);
        JpegWrapper.dstSamplingFormat=GetJpegWrapperFormat(pCalJpegEncPara->JpegSamplingFormat);
        JpegWrapper.dstFileFormat=JPEG_FILE_FORMAT_EXIF;
        JpegWrapper.pDstFileHandle=pCalJpegEncPara->pDstFileHandle;

        #if (defined(MT6256) && defined(__JPEG_SENSOR_SUPPORT__))
        if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM != CurrentStillScenarioId)
        {
            JpegWrapper.extMemoryAddr=(void *)(ExtMemAddr+MAX_STILL_CAPTURE_JPEG_BUFF_SIZE);
            JpegWrapper.extMemorySize=ISP_EXT_WORKING_BUF_SIZE;
        }
        else
        #endif
        {
            JpegWrapper.extMemoryAddr=(void *)ExtMemAddr;
            JpegWrapper.extMemorySize=ExtMemSize;
        }
        #if !((defined(MT6255) || defined(MT6256))  && defined(__JPEG_SENSOR_SUPPORT__))
        ExtMemAddr += JPEG_ENC_EXT_MIN_MEM_SIZE;
        ExtMemSize -= JPEG_ENC_EXT_MIN_MEM_SIZE;
        #endif

        // thumbnail should be disable always. it will be added by JAIA
        JpegWrapper.enableThumbnail=KAL_FALSE;
        JpegWrapper.callback_function=JpegEncCallback;

    #if defined(__YUVCAM_INTERPOLATION_SW__)
        #if defined(__IMAGE_SENSOR_01M__)
        if ((JpegWrapper.dstWidth > 352) && (JpegWrapper.dstHeight > 288))
        {
            JpegWrapper.srcWidth = 352;
            JpegWrapper.srcHeight = 288;
        }
        #elif defined(__IMAGE_SENSOR_03M__)
        if ((JpegWrapper.dstWidth > 640) && (JpegWrapper.dstHeight > 480))
        {
            JpegWrapper.srcWidth = 640;
            JpegWrapper.srcHeight = 480;
        }
        #elif defined(__IMAGE_SENSOR_1M__)
        if ((JpegWrapper.dstWidth > 1280) && (JpegWrapper.dstHeight > 1024))
        {
            JpegWrapper.srcWidth = 1280;
            JpegWrapper.srcHeight = 1024;
        }
        #elif defined(__IMAGE_SENSOR_2M__)
        if ((JpegWrapper.dstWidth > 1600) && (JpegWrapper.dstHeight > 1200))
        {
            JpegWrapper.srcWidth = 1600;
            JpegWrapper.srcHeight = 1200;
        }
        #else
        #error "No support sensor resolution!"
        #endif
    #endif

        #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
            if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
        #endif
        {   // apply SW JPEG encoder, support YUV420 only.
        #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
            JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_RGB_BUFFER;
            JpegWrapper.srcRGBBuffer=(void *)pCalIspCapturePara->RawImageBuffAddr;
            JpegWrapper.srcBufferSize[0]=JpegWrapper.dstWidth * JpegWrapper.dstHeight * 2;
            JpegWrapper.srcRGBFormat=JPEG_RGB_FORMAT_RGB565;
        #elif defined(MT6235) || defined(MT6235B) || defined(MT6253)
            if (MM_IMAGE_FORMAT_YUV420==CalStillCaptureInfo.MainImageJpegYuvSampleFormat)
            {
                JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_YUV_BUFFER;
                Resolution=JpegWrapper.srcWidth * JpegWrapper.srcHeight;
                JpegWrapper.srcBufferSize[0]=Resolution;
                JpegWrapper.srcYUVBuffer[0]=(void *)pCalIspCapturePara->RawImageBuffAddr;
                JpegWrapper.srcYUVBuffer[1]=(void *)(pCalIspCapturePara->RawImageBuffAddr + Resolution);
                JpegWrapper.srcYUVBuffer[2]=(void *)(pCalIspCapturePara->RawImageBuffAddr + Resolution +(Resolution>>2));
                JpegWrapper.srcBufferSize[1]=Resolution>>2;
                JpegWrapper.srcBufferSize[2]=Resolution>>2;
            }
            else
            {
                JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_RGB_BUFFER;
                JpegWrapper.srcRGBBuffer=(void *)pCalIspCapturePara->RawImageBuffAddr;
                JpegWrapper.srcBufferSize[0]=JpegWrapper.dstWidth * JpegWrapper.dstHeight * 2;
                JpegWrapper.srcRGBFormat=JPEG_RGB_FORMAT_RGB565;
            }
        #else
            JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_YUV_BUFFER;
            Resolution=JpegWrapper.srcWidth * JpegWrapper.srcHeight;
            JpegWrapper.srcBufferSize[0]=Resolution;
            #if defined(MT6255)
            if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM!=CurrentStillScenarioId)
            {
                #if defined(__JPEG_SENSOR_SUPPORT__)
                if((IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG!=CaptureFormatInfo.DataType)&&(IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG == CurrentSensorInfo.CaptureDataFormat))
                {// YUV input in jpeg sensor
                    CAM_IMAGE_SIZE_ENUM MaxYUVSupportRes = CAM_IMAGE_SIZE_1M;
                    if (CAL_CAMERA_SOURCE_MAIN == CurrentCameraId)
                    {
                    #if defined(__IMAGE_SENSOR_5M__)
                        MaxYUVSupportRes = CAM_IMAGE_SIZE_1M;
                    #elif defined(__IMAGE_SENSOR_8M__)
                        MaxYUVSupportRes = CAM_IMAGE_SIZE_2M;
                    #endif
                    }
                    else if (CAL_CAMERA_SOURCE_SUB == CurrentCameraId)
                    {
                    #if defined(__IMAGE_SENSOR_SUB_5M__)
                        MaxYUVSupportRes = CAM_IMAGE_SIZE_1M;
                    #elif defined(__IMAGE_SENSOR_SUB_8M__)
                        MaxYUVSupportRes = CAM_IMAGE_SIZE_2M;
                    #endif
                    }

                    switch (MaxYUVSupportRes)
                    {
                        case CAM_IMAGE_SIZE_1M:
                            YUVMaxWidth = (IMAGE_1M_MAX_WIDTH-6);
                            YUVMaxHeight = (IMAGE_1M_MAX_HEIGHT-6);
                        break;
                        case CAM_IMAGE_SIZE_2M:
                            YUVMaxWidth = (IMAGE_2M_MAX_WIDTH-6);
                            YUVMaxHeight = (IMAGE_2M_MAX_HEIGHT-6);
                        break;
                        default:
                        ASSERT(0);
                        break;
                    }
                    Resolution = YUVMaxWidth*YUVMaxHeight;
                }
                else
                #endif
                {
                    if (CAL_CAMERA_SOURCE_MAIN == CurrentCameraId)
                    {
                        Resolution = (IMAGE_SENSOR_SOURCE_MAX_WIDTH-6)*(IMAGE_SENSOR_SOURCE_MAX_HEIGHT-6);
                    }
                    else if (CAL_CAMERA_SOURCE_SUB == CurrentCameraId)
                    {
                        Resolution = (IMAGE_SENSOR_SOURCE_SUB_MAX_WIDTH-6)*(IMAGE_SENSOR_SOURCE_SUB_MAX_HEIGHT-6);
                    }
                }
            }
            #elif defined(MT6250)||defined(MT6260)
            if (pCalMdpCapturePara->MainImageWidth > 800)
            {
                Resolution = (IMAGE_SENSOR_SOURCE_MAX_WIDTH-6)*(IMAGE_SENSOR_SOURCE_MAX_HEIGHT-6);
            }
            #elif defined(MT6252)
            if (pCalMdpCapturePara->MainImageWidth > 320)
            {
                Resolution = (IMAGE_SENSOR_SOURCE_MAX_WIDTH-6)*(IMAGE_SENSOR_SOURCE_MAX_HEIGHT-6);
            }
            #endif
            JpegWrapper.srcYUVBuffer[0]=(void *)pCalIspCapturePara->RawImageBuffAddr;
            JpegWrapper.srcYUVBuffer[1]=(void *)(pCalIspCapturePara->RawImageBuffAddr + Resolution);
            JpegWrapper.srcYUVBuffer[2]=(void *)(pCalIspCapturePara->RawImageBuffAddr + Resolution +(Resolution>>2));
            JpegWrapper.srcBufferSize[1]=Resolution>>2;
            JpegWrapper.srcBufferSize[2]=Resolution>>2;

            #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
            if (pCalMdpCapturePara->MainImageYUVEnagle == KAL_TRUE)
            {
                JpegWrapper.srcYUVBuffer[1] = (void *) pCalMdpCapturePara->MainImageUBuffAddr;
                JpegWrapper.srcYUVBuffer[2] = (void *) pCalMdpCapturePara->MainImageVBuffAddr;
            }
            #endif
        #endif
        }
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        else
        {   // Apply HW JPEG encoder.
            JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_ISP;
            jpeg_wrapper_open(&JpegWrapperHandle, JPEG_CODEC_TYPE_HW);
        }
    #endif
    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_CONFIG_JPEG_COMPLETE);
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_BEFORE_CONFIG_IDP_RESIZER);
    #endif
        /* config idp & lcd driver */
    #if (!defined(DRV_IDP_6252_SERIES))
        MdpStillCapturePara.extmem_start_address =ExtMemAddr;
        MdpStillCapturePara.extmem_size = ExtMemSize;
    #endif

        MdpStillCapturePara.source_width = pIspGetOutResParaOut->IspOutWidth;
        MdpStillCapturePara.source_height = pIspGetOutResParaOut->IspOutHeight;
    #if (!defined(DRV_IDP_6252_SERIES))
        MdpStillCapturePara.quickview_pitch_enable = KAL_FALSE;
        MdpStillCapturePara.quickview_pitch_width = 0;
    #endif
    #ifdef __CAL_CAMERA_OVERLAY_SUPPORT__
        MdpStillCapturePara.enable_overlay = pCalMdpCapturePara->OverlayEnable;
        MdpStillCapturePara.overlay_palette_size = pCalMdpCapturePara->OverlayPaletteSize;
        MdpStillCapturePara.overlay_palette_addr = pCalMdpCapturePara->OverlayPaletteAddr;
        MdpStillCapturePara.overlay_color_depth = pCalMdpCapturePara->OverlayColorDepth;
        MdpStillCapturePara.overlay_frame_source_key = pCalMdpCapturePara->OverlayFrameSourceKey;
        MdpStillCapturePara.overlay_frame_width = pCalMdpCapturePara-> OverlayFrameWidth;
        MdpStillCapturePara.overlay_frame_height = pCalMdpCapturePara->OverlayFrameHeight;
        MdpStillCapturePara.overlay_frame_buffer_address = pCalMdpCapturePara->OverlayFrameBuffAddr;
    #else
        #if (!defined(DRV_IDP_6252_SERIES))
        MdpStillCapturePara.enable_overlay=KAL_FALSE;
    #endif
    #endif

        if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
        {   // in capture to memory mode, MDP output does not need to rotate the image, and the MDP
            // output width/height should be the same as the sensor target output width/height
            MdpStillCapturePara.fullsize_image_width = SensorOutputTargetWidth;
            MdpStillCapturePara.fullsize_image_height = SensorOutputTargetHeight;
        }
        else
        {
            MdpStillCapturePara.fullsize_image_width = pCalMdpCapturePara->MainImageWidth;
            MdpStillCapturePara.fullsize_image_height = pCalMdpCapturePara->MainImageHeight;
        }
        MdpStillCapturePara.fullsize_image_jpeg_yuv_mode = pCalMdpCapturePara->MainImageJpegYuvSampleFormat;
        MdpStillCapturePara.fullsize_image_format=pCalMdpCapturePara->MainImageDataFormat;

    #if defined(__YUVCAM_INTERPOLATION_SW__)
        #if defined(__IMAGE_SENSOR_01M__)
        if ((JpegWrapper.dstWidth > 352) && (JpegWrapper.dstHeight > 288))
        {
            MdpStillCapturePara.fullsize_image_width = 352;
            MdpStillCapturePara.fullsize_image_height = 288;
            CalStillCaptureInfo.MainImageWidth = 352;
            CalStillCaptureInfo.MainImageHeight = 288;
        }
        #elif defined(__IMAGE_SENSOR_03M__)
        if ((JpegWrapper.dstWidth > 640) && (JpegWrapper.dstHeight > 480))
        {
            MdpStillCapturePara.fullsize_image_width = 640;
            MdpStillCapturePara.fullsize_image_height = 480;
            CalStillCaptureInfo.MainImageWidth = 640;
            CalStillCaptureInfo.MainImageHeight = 480;
        }
        #elif defined(__IMAGE_SENSOR_1M__)
        if ((JpegWrapper.dstWidth > 1280) && (JpegWrapper.dstHeight > 1024))
        {
            MdpStillCapturePara.fullsize_image_width = 1280;
            MdpStillCapturePara.fullsize_image_height = 1024;
            CalStillCaptureInfo.MainImageWidth = 1280;
            CalStillCaptureInfo.MainImageHeight = 1024;
        }
        #elif defined(__IMAGE_SENSOR_2M__)
        if ((JpegWrapper.dstWidth > 1600) && (JpegWrapper.dstHeight > 1200))
        {
            MdpStillCapturePara.fullsize_image_width = 1600;
            MdpStillCapturePara.fullsize_image_height = 1200;
            CalStillCaptureInfo.MainImageWidth = 1600;
            CalStillCaptureInfo.MainImageHeight = 1200;
        }
        #else
        #error "No support sensor resolution!"
        #endif
    #endif

        if (MM_IMAGE_FORMAT_JPEG==pCalMdpCapturePara->MainImageDataFormat)
        {
            #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
                if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
            #endif
            {   // SW JPEG case or Wallpaper capture with image rotation
                // in Wallpaper capture with image rotation, we will apply SW JPEG encoder no matter HW JPEG support or not
                // Support YUV420 only
                MdpStillCapturePara.fullsize_image_format=pCalMdpCapturePara->MainImageJpegYuvSampleFormat;
                Resolution = MdpStillCapturePara.fullsize_image_width * MdpStillCapturePara.fullsize_image_height;

                #if defined(MT6255)
                if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM!=CurrentStillScenarioId)
                {
                    #if defined(__JPEG_SENSOR_SUPPORT__)
                    if((IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG!=CaptureFormatInfo.DataType)&&(IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG == CurrentSensorInfo.CaptureDataFormat))
                    {
                        Resolution = YUVMaxWidth*YUVMaxHeight;
                    }
                    else
                    #endif
                    {
                        if (CAL_CAMERA_SOURCE_MAIN == CurrentCameraId)
                        {
                             Resolution = (IMAGE_SENSOR_SOURCE_MAX_WIDTH-6)*(IMAGE_SENSOR_SOURCE_MAX_HEIGHT-6);
                        }
                        else if (CAL_CAMERA_SOURCE_SUB == CurrentCameraId)
                        {
                             Resolution = (IMAGE_SENSOR_SOURCE_SUB_MAX_WIDTH-6)*(IMAGE_SENSOR_SOURCE_SUB_MAX_HEIGHT-6);
                        }
                    }
                }
                #elif defined(MT6250)||defined(MT6260)
                if (pCalMdpCapturePara->MainImageWidth > 800)
                {
                    Resolution = (IMAGE_SENSOR_SOURCE_MAX_WIDTH-6)*(IMAGE_SENSOR_SOURCE_MAX_HEIGHT-6);
                }
                #elif defined(MT6252)
                if (pCalMdpCapturePara->MainImageWidth > 320)
                {
                    Resolution = (IMAGE_SENSOR_SOURCE_MAX_WIDTH-6)*(IMAGE_SENSOR_SOURCE_MAX_HEIGHT-6);
                }
                #endif

            #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
                MdpStillCapturePara.fullsize_image_buffer_y_addr=pCalIspCapturePara->RawImageBuffAddr + Resolution * 2;
            #elif defined(MT6235) || defined(MT6235B) || defined(MT6253)
                if (MM_IMAGE_FORMAT_YUV420==CalStillCaptureInfo.MainImageJpegYuvSampleFormat)
                {
                    if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
                    {
                        MdpStillCapturePara.fullsize_image_buffer_y_addr=pCalIspCapturePara->RawImageBuffAddr + Resolution + (Resolution>>1);
                    }
                    else
                        MdpStillCapturePara.fullsize_image_buffer_y_addr=pCalIspCapturePara->RawImageBuffAddr;

                    MdpStillCapturePara.fullsize_image_buffer_u_addr=MdpStillCapturePara.fullsize_image_buffer_y_addr + Resolution;
                    MdpStillCapturePara.fullsize_image_buffer_v_addr=MdpStillCapturePara.fullsize_image_buffer_y_addr + Resolution + (Resolution>>2);
                }
                else
                {
                    if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
                        MdpStillCapturePara.fullsize_image_buffer_y_addr=pCalIspCapturePara->RawImageBuffAddr + Resolution * 2;
                    else
                        MdpStillCapturePara.fullsize_image_buffer_y_addr=pCalIspCapturePara->RawImageBuffAddr;
                }
            #else
                // if jaia disable pCalIspCapturePara->RawImageBuffAddr is 2nd buffer
                if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
                {
                    // shift one frame buffer for image rotation
                    if (CalStillCaptureInfo.ImageJaiaDisable == KAL_TRUE) // MDP output to 1st YUV buffer, and rotate to 2nd buffer
                    {
                        MdpStillCapturePara.fullsize_image_buffer_y_addr = pCalMdpCapturePara->MainImageWorkingBuffAddr;
                    }
                    else // MDP output to 2nd YUV buffer, and rotate to 1st buffer
                    {
                        MdpStillCapturePara.fullsize_image_buffer_y_addr = pCalIspCapturePara->RawImageBuffAddr + Resolution + (Resolution>>1);
                    }
                }
                else // no shift, because no rotation
                {
                    MdpStillCapturePara.fullsize_image_buffer_y_addr = pCalIspCapturePara->RawImageBuffAddr;
                }

                if (MM_IMAGE_FORMAT_YUV420==MdpStillCapturePara.fullsize_image_jpeg_yuv_mode)
                {
                    MdpStillCapturePara.fullsize_image_buffer_u_addr=MdpStillCapturePara.fullsize_image_buffer_y_addr + Resolution;
                    MdpStillCapturePara.fullsize_image_buffer_v_addr=MdpStillCapturePara.fullsize_image_buffer_y_addr + Resolution + (Resolution>>2);

                    #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
                    if (pCalMdpCapturePara->MainImageYUVEnagle == KAL_TRUE)
                    {
                        MdpStillCapturePara.fullsize_image_buffer_u_addr = pCalMdpCapturePara->MainImageUBuffAddr;
                        MdpStillCapturePara.fullsize_image_buffer_v_addr = pCalMdpCapturePara->MainImageVBuffAddr;
                    }
                    #endif
                }
                else
                    ASSERT(0);
            #endif
            #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
                if (pCalPostProcCapturePara->PostProcMode & PP_MODE_PANORAMA)
                {
                    MdpStillCapturePara.fullsize_image_buffer_y_addr=pCalMdpCapturePara->MainImageBuffAddr;
                    MdpStillCapturePara.fullsize_image_buffer_u_addr=MdpStillCapturePara.fullsize_image_buffer_y_addr +
                                                                     MdpStillCapturePara.fullsize_image_width * MdpStillCapturePara.fullsize_image_height;
                    MdpStillCapturePara.fullsize_image_buffer_v_addr=MdpStillCapturePara.fullsize_image_buffer_y_addr +
                                                                 MdpStillCapturePara.fullsize_image_width * MdpStillCapturePara.fullsize_image_height * 5/4;

                    #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
                    if (pCalMdpCapturePara->MainImageYUVEnagle == KAL_TRUE)
                    {
                        MdpStillCapturePara.fullsize_image_buffer_y_addr = pCalMdpCapturePara->MainImageYBuffAddr;
                        MdpStillCapturePara.fullsize_image_buffer_u_addr = pCalMdpCapturePara->MainImageUBuffAddr;
                        MdpStillCapturePara.fullsize_image_buffer_v_addr = pCalMdpCapturePara->MainImageVBuffAddr;
                    }
                    #endif
                }
            #endif
            }
        } // if (MM_IMAGE_FORMAT_JPEG==pCalMdpCapturePara->MainImageDataFormat)
        #if defined (__CAL_CAPTURE_RAW_DATA_SUPPORT__)
        else if (CAM_STILL_CAPTURE_RAW_DATA==pCalIspCapturePara->StillCaptureMode)
        {
            MdpStillCapturePara.fullsize_image_buffer_y_addr=pCalMdpCapturePara->MainImageBuffAddr;
            MdpStillCapturePara.fullsize_image_format=pCalMdpCapturePara->MainImageDataFormat;

            if (MM_IMAGE_FORMAT_YUV420==MdpStillCapturePara.fullsize_image_format)
            {
                Resolution = MdpStillCapturePara.fullsize_image_width * MdpStillCapturePara.fullsize_image_height;

                MdpStillCapturePara.fullsize_image_buffer_u_addr=MdpStillCapturePara.fullsize_image_buffer_y_addr + Resolution;
                MdpStillCapturePara.fullsize_image_buffer_v_addr=MdpStillCapturePara.fullsize_image_buffer_y_addr + Resolution + (Resolution>>2);
            }
            else if (MM_IMAGE_FORMAT_RGB565==MdpStillCapturePara.fullsize_image_format)
            {
            }
            else
            {
                ASSERT(0);
            }

            #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
            if (pCalMdpCapturePara->MainImageYUVEnagle == KAL_TRUE)
            {
                MdpStillCapturePara.fullsize_image_buffer_y_addr = pCalMdpCapturePara->MainImageYBuffAddr;
                MdpStillCapturePara.fullsize_image_buffer_u_addr = pCalMdpCapturePara->MainImageUBuffAddr;
                MdpStillCapturePara.fullsize_image_buffer_v_addr = pCalMdpCapturePara->MainImageVBuffAddr;
            }
            #endif
        }
        #endif
        else
        {
            MdpStillCapturePara.fullsize_image_buffer_y_addr=pCalMdpCapturePara->MainImageWorkingBuffAddr;

            #if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
            ASSERT(pCalMdpCapturePara->MainImageYUVEnagle == KAL_FALSE);
            #endif
        }

        if (MM_IMAGE_ROTATE_0 != CalStillCaptureInfo.QuickViewImageRotAngle)
        {   // output the quick view image to a temp buffer first then rotate it to QuickViewImageBuffAddr by SW
            // for 52/55, use the working memory of ISP
            MdpStillCapturePara.quickview_image_buffer_addr = pCalMdpCapturePara->MainImageWorkingBuffAddr + pCalMdpCapturePara->MainImageWorkingBuffSize - CAL_QVI_ROT_WORKING_BUFF_SIZE;

            if (NULL !=CalExtraQVIBuffAddr)
            {
                MdpStillCapturePara.quickview_image_buffer_addr = CalExtraQVIBuffAddr;
                if (CalExtraQVIBuffSize != CalStillCaptureInfo.QuickViewImageBuffSize)
                     ASSERT(0);
                CalExtraQVIBuffAddr = NULL;
            }
            CalStillCaptureInfo.QuickViewImageBuffAddr = MdpStillCapturePara.quickview_image_buffer_addr;
            QuickViewImageDestBuffAddr = pCalMdpCapturePara->QuickViewImageBuffAddr;

            // quick resize buffer use 1st buffer
            if (CalStillCaptureInfo.ImageJaiaDisable == KAL_TRUE)
            {
                CalStillCaptureInfo.QuickViewImageBuffAddr = pCalMdpCapturePara->MainImageBuffAddr;
            }
        }
        else
        {
            MdpStillCapturePara.quickview_image_buffer_addr = pCalMdpCapturePara->QuickViewImageBuffAddr;
        }

        #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
            if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
        #endif
        {   // SW JPEG case or Wallpaper with rotataion
            #ifdef __CAL_QUICKVIEW_THUMBNAIL_HW_SUPPORT_ON_SW_JPEG_ENCODE__
            if (CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM!=CurrentStillScenarioId)
            {
                MdpStillCapturePara.quickview_image_enable = pCalMdpCapturePara->QuickViewImageEnable;
                MdpStillCapturePara.thumbnail_image_enable = pCalMdpCapturePara->ThumbnailImageEnable;
                MdpStillCapturePara.thumbnail_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpCapturePara->ThumbnailImageFormat;
            }
            else
            {
                // SW JPEG case or Wallpaper with rotataion
                MdpStillCapturePara.quickview_image_enable = KAL_FALSE;
                MdpStillCapturePara.thumbnail_image_enable = KAL_FALSE;

                #ifdef __CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__
                CalStillCaptureInfo.ThumbnailImageFormat=MM_IMAGE_FORMAT_YUV420;
                #else
                CalStillCaptureInfo.ThumbnailImageFormat=MM_IMAGE_FORMAT_RGB565;
                #endif
            }
            #else
            // SW JPEG case or Wallpaper with rotataion
        #if (!defined(DRV_IDP_6252_SERIES))
            MdpStillCapturePara.quickview_image_enable = KAL_FALSE;
            MdpStillCapturePara.thumbnail_image_enable = KAL_FALSE;
        #endif
            #ifdef __CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__
            CalStillCaptureInfo.ThumbnailImageFormat=MM_IMAGE_FORMAT_YUV420;
            #else
            CalStillCaptureInfo.ThumbnailImageFormat=MM_IMAGE_FORMAT_RGB565;
            #endif
            #endif
        }
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        else
        {
            MdpStillCapturePara.quickview_image_enable = pCalMdpCapturePara->QuickViewImageEnable;
            MdpStillCapturePara.thumbnail_image_enable = pCalMdpCapturePara->ThumbnailImageEnable;
            MdpStillCapturePara.thumbnail_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpCapturePara->ThumbnailImageFormat;
            #ifdef __CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__
            MdpStillCapturePara.thumbnail_image_color_format=MM_IMAGE_COLOR_FORMAT_YUV420;
            #endif
        }
    #endif
        // no matter whether thumbnail image rotation is necessary or not. The output of hardware does not
        // need to rotate it.
    #ifdef __CAL_MDP_QV_THUMBNAIL_OUTPUT_SUPPORT__
        if (MdpStillCapturePara.quickview_image_rot_angle & 0x01)
        {
            MdpStillCapturePara.quickview_image_width = pCalMdpCapturePara->QuickViewImageHeight;
            MdpStillCapturePara.quickview_image_height = pCalMdpCapturePara->QuickViewImageWidth;
        }
        else
        {
            MdpStillCapturePara.quickview_image_width = pCalMdpCapturePara->QuickViewImageWidth;
            MdpStillCapturePara.quickview_image_height = pCalMdpCapturePara->QuickViewImageHeight;
        }
    #if (!defined(DRV_IDP_6252_SERIES)) // 52 series IDP does not support QVI & Thumbnail output
        MdpStillCapturePara.quickview_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpCapturePara->QuickViewImageFormat;
        if (MdpStillCapturePara.thumbnail_image_rot_angle & 0x01)
        {
            MdpStillCapturePara.thumbnail_image_width = pCalMdpCapturePara->ThumbnailImageHeight;
            MdpStillCapturePara.thumbnail_image_height = pCalMdpCapturePara->ThumbnailImageWidth;
        }
        else
        {
        MdpStillCapturePara.thumbnail_image_width = pCalMdpCapturePara->ThumbnailImageWidth;
        MdpStillCapturePara.thumbnail_image_height = pCalMdpCapturePara->ThumbnailImageHeight;
        }
        MdpStillCapturePara.thumbnail_image_buffer_addr = pCalMdpCapturePara->ThumbnailImageBuffAddr;
    #endif
    #endif

    #ifdef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
        if (MM_IMAGE_COLOR_FORMAT_RGB565==MdpStillCapturePara.quickview_image_color_format)
            MdpStillCapturePara.quickview_image_color_format = MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422;
    #endif

    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE!=ScenarioId)
    #endif
        {
            ErrorCode=MdpFunc.pfnIdpCalOpen( CurrentStillScenarioId, &IdpCalKey, NULL, 0);
            ErrorCode = MdpFunc.pfnIdpCalSet( CurrentStillScenarioId, IdpCalKey, IDP_CAL_SET_CONFIG, &MdpStillCapturePara);
        }
#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
        ErrorCode = MdpFunc.pfnIdpCalStart( CurrentStillScenarioId, IdpCalKey);
        ASSERT(ErrorCode == MM_ERROR_NONE);
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        if ((KAL_TRUE==IsHwJpegEncSupport)&&
            (CAL_SCENARIO_CAMERA_STILL_CAPTURE==CurrentStillScenarioId))
        {   // JPEG start after MDP config due to MT6268's HW requirement. The image widht/height
            // are come from MDP such that MDP should be configured before JPEG encoder is triggered.
            jpeg_wrapper_start(JpegWrapperHandle, &JpegWrapper);
        }
    #endif
#else
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        if ((KAL_TRUE==IsHwJpegEncSupport)&&
        ((CAL_SCENARIO_CAMERA_STILL_CAPTURE==CurrentStillScenarioId)||(CAL_SCENARIO_CAMERA_ZSD_CAPTURE==CurrentStillScenarioId)))
        {
            jpeg_wrapper_start(JpegWrapperHandle, &JpegWrapper);
        }
    #endif
    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE==ScenarioId)
        {
            if(CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM==CurrentStillScenarioId)
                ErrorCode = MdpFunc.pfnIdpCalSet(CAL_SCENARIO_CAMERA_ZSD_PREVIEW,  IdpCalKey, IDP_CAL_SET_ZSD_CAPTURE_TO_MEM_START, &MdpStillCapturePara);
            else
                ErrorCode = MdpFunc.pfnIdpCalSet(CAL_SCENARIO_CAMERA_ZSD_PREVIEW,  IdpCalKey, IDP_CAL_SET_ZSD_CAPTURE_TO_JPEG_START, &MdpStillCapturePara);
        }
        else
    #endif
            ErrorCode = MdpFunc.pfnIdpCalStart( CurrentStillScenarioId, IdpCalKey);

        ASSERT(ErrorCode == MM_ERROR_NONE);
#endif

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_CONFIG_IDP_RESIZER_COMPLETE);
    #endif

        /* start ISP */
        stack_start_timer(&CalTaskStackTimer, CAL_STACK_TIMER_INDEX_STILL_CAPTURE_TIMEOUT, 1100);
        CalState = CAL_CAMERA_CAPTURE_STATE;

    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        if(CAL_SCENARIO_CAMERA_ZSD_CAPTURE!=ScenarioId)
    #endif
        {
            ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);
        }
        return ErrorCode;
    }
    return ErrorCode;
} /* CalStillCaptureCtrl() */

MM_ERROR_CODE_ENUM CalVideoCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_CAL_CAMERA_VIDEO_RECORD_STRUCT pCalVideoPara = (P_CAL_CAMERA_VIDEO_RECORD_STRUCT) pCtrlPara;
    P_CAL_LCD_STRUCT pCalLcdPara=pCalVideoPara->pLcdPara;
    P_CAL_ISP_VIDEO_STRUCT pCalIspVideoPara=pCalVideoPara->pIspPara;
    P_CAL_MDP_VIDEO_STRUCT pCalMdpVideoPara=pCalVideoPara->pMdpPara;
    ISP_CAMERA_VIDEO_STRUCT IspVideoPara;

    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT IspDigitalZoomResParaIn;
    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT IspDigitalZoomResParaOut;

    ISP_FEATURE_SET_TG_STRUCT IspTgSettingInfo;

    // for IDP capability query
    IDP_CAL_QUERY_ARG_T MdpCapQueryPara;
    kal_uint32 MdpCapQueryResult;

    kal_uint32 FeatureOutLen;
    kal_uint32 CtrlOutLen;
#ifdef __CAL_MINIMIZE_GLOBAL_VARIABLE__
    Video_Encode_Idp_Cal_Struct MdpVideoPara;
  #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
    Mjpeg_Encode_Idp_Cal_Struct MdpMjpegVideoPara;
  #endif
#endif

    DisplayPreviewFrameFlag=KAL_FALSE;
    if (CAL_CTRL_CODE_STOP & CtrlCode)
    {
    #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
        if (KAL_TRUE==MjpegVideoEnable)
            CurrentScenarioId=CAL_SCENARIO_VIDEO_MJPEG;
    #endif

        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
        ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);

        MdpFunc.pfnIdpCalClose(CurrentScenarioId, IdpCalKey);

    #ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
        if (MM_IMAGE_ROTATE_0!=CalVideoInfo.VideoImageRotAngle)
        {
            MplBuffInfo.pu1Address=(kal_uint8*) VideoRotBuffAddr;
            CalVideoInfo.pfRetVideoBuff(MplBuffInfo);
        }
    #endif
    #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
        if (KAL_TRUE==MjpegVideoEnable)
            jpeg_wrapper_close(JpegWrapperHandle);
    #endif
        CameraImageDisplayConfig(CtrlCode, (MM_IMAGE_FORMAT_ENUM) CalVideoInfo.DisplayImageDataFormat,
                                 (MM_IMAGE_ROTATE_ENUM) MdpDisplayImageRotAngle,
                                 CalVideoInfo.DisplayImageWidth, CalVideoInfo.DisplayImageHeight,
                                 CalVideoInfo.FrameBuffAddr1, CalVideoInfo.FrameBuffAddr2, CalVideoInfo.FrameBuffAddr3);


        CalState=CAL_STANDBY_STATE;
        return ErrorCode;
    }
    if (CAL_CTRL_CODE_START & CtrlCode)
    {
#if !defined (MDP_SUPPORT_VR_TRIPLE_DISPLAY_BUFFER) && !defined (MDP_SUPPORT_VTR_TRIPLE_DISPLAY_BUFFER)
        //if VR and VTR triple buffer does not support, set FrameBuffAddr3 to NULL
        pCalMdpVideoPara->FrameBuffAddr3 = NULL;
#endif
        kal_mem_cpy(&CalVideoInfo, pCalMdpVideoPara, sizeof(CAL_MDP_VIDEO_STRUCT));

    #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
        if (MM_IMAGE_FORMAT_JPEG==pCalMdpVideoPara->VideoImageDataFormat)
        {
            MjpegVideoEnable=KAL_TRUE;
            CurrentScenarioId=CAL_SCENARIO_VIDEO_MJPEG;
        }
        else
            MjpegVideoEnable=KAL_FALSE;
    #else
        pCalMdpVideoPara->VideoImageDataFormat = MM_IMAGE_FORMAT_YUV420;
    #endif

        IspTgSettingInfo.ScenarioId=CAL_SCENARIO_VIDEO;
        IspTgSettingInfo.pSensorInfo=(void *) &CurrentSensorInfo;
        pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_TG, &IspTgSettingInfo, NULL, 0, &FeatureOutLen);

        /* config sensor driver */
        {
        #ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__
            // Not rotate video, only record video rotate tag
            MdpVideoPara.display_rot_angle = (img_rot_angle_enum_t) pCalMdpVideoPara->DisplayImageRotAngle;
            SensorScenarioParaIn.ImageMirror = IMAGE_SENSOR_MIRROR_NORMAL;
        #else
          // Rotate video, let video angle always 0
          #ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
            // MDP support rotate all angle
            MM_IMAGE_ROTATE_ENUM SensorRotate;
            SensorRotate = GetSensorRotAngle(pCalMdpVideoPara->DisplayImageRotAngle, &MdpVideoPara.display_rot_angle, &SensorScenarioParaIn.ImageMirror);

            CalVideoInfo.VideoImageRotAngle=GetRestRotAngle(CalVideoInfo.VideoImageRotAngle, SensorRotate);
          #else
            // MDP cannot support rotate all angle, only let display correct, record video maybe wrong.
            GetSensorRotAngle(pCalMdpVideoPara->DisplayImageRotAngle, &MdpVideoPara.display_rot_angle, &SensorScenarioParaIn.ImageMirror);
          #endif
        #endif
        }

        IspVideoPara.ImageMirror=SensorScenarioParaIn.ImageMirror;

        ErrorCode = MdpFunc.pfnIdpCalOpen(CurrentScenarioId, &IdpCalKey, NULL, 0);
        // query the rotation angle that MDP can support.
        // Pass the rest rotation angle to Display driver.
        // if the rotation angle is depend on post image process, then CAL will rotate the image for display driver.
        MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_DISPLAY_PATH;
        MdpCapQueryPara.eClrFmt=(MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpVideoPara->DisplayImageDataFormat;
        MdpCapQueryPara.eDesiredAngle=MdpVideoPara.display_rot_angle;
        MdpCapQueryPara.eRotateWidth=pCalMdpVideoPara->DisplayImageWidth;
        MdpFunc.pfnIdpCalQuery(CurrentScenarioId, IdpCalKey, IDP_CAL_QUERY_ROT_CAP, &MdpCapQueryPara, &MdpCapQueryResult);

        DisplayImageRotAngle=GetRestRotAngle((MM_IMAGE_ROTATE_ENUM) MdpVideoPara.display_rot_angle, (MM_IMAGE_ROTATE_ENUM) MdpCapQueryResult);

        MdpVideoPara.display_rot_angle = (img_rot_angle_enum_t) MdpCapQueryResult;
        MdpDisplayImageRotAngle = (MM_IMAGE_ROTATE_ENUM) MdpVideoPara.display_rot_angle;

        // configure the rotation angle of Display driver
        SaveDisplyHandle(pCalLcdPara);

        CameraImageDisplayConfig(CtrlCode, pCalMdpVideoPara->DisplayImageDataFormat,
                                 (MM_IMAGE_ROTATE_ENUM) MdpVideoPara.display_rot_angle,
                                 pCalMdpVideoPara->DisplayImageWidth, pCalMdpVideoPara->DisplayImageHeight,
                                 pCalMdpVideoPara->FrameBuffAddr1, pCalMdpVideoPara->FrameBuffAddr2, pCalMdpVideoPara->FrameBuffAddr3);

        // query whether the MDP support vidoe image rotation ?
    #ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
        SwVideoRotAngle = MM_NO_OF_IMAGE_ROTATE;

        MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_POSTPROC_PATH;
        MdpCapQueryPara.eDesiredAngle=(img_rot_angle_enum_t)CalVideoInfo.VideoImageRotAngle;
        MdpCapQueryPara.eRotateWidth=pCalMdpVideoPara->VideoImageWidth;
        MdpFunc.pfnIdpCalQuery(CurrentScenarioId, IdpCalKey, IDP_CAL_QUERY_ROT_CAP, &MdpCapQueryPara, &MdpCapQueryResult);

        if (MdpCapQueryResult == CalVideoInfo.VideoImageRotAngle)
        {
        #if (!defined(DRV_IDP_6252_SERIES))
            MdpVideoPara.video_encode_image_rot_angle= (img_rot_angle_enum_t) CalVideoInfo.VideoImageRotAngle;
        #endif
            CalVideoInfo.VideoImageRotAngle = MM_IMAGE_ROTATE_0;
        }
        else
        {
        #if (!defined(DRV_IDP_6252_SERIES))
            MdpVideoPara.video_encode_image_rot_angle= (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
        #endif
        }
    #else
    #if (!defined(DRV_IDP_6252_SERIES))
        MdpVideoPara.video_encode_image_rot_angle= (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
    #endif
    #endif

        SensorScenarioParaIn.ImageTargetWidth=pCalMdpVideoPara->VideoImageWidth;
        SensorScenarioParaIn.ImageTargetHeight=pCalMdpVideoPara->VideoImageHeight;
        if (CAM_VIDEO_NIGHT==pCalIspVideoPara->VideoSceneMode)
            SensorScenarioParaIn.NightMode=KAL_TRUE;
        else
            SensorScenarioParaIn.NightMode=KAL_FALSE;
        SensorScenarioParaIn.MetaMode=CAMERA_SYSTEM_NORMAL_MODE;
        SensorScenarioParaIn.ContrastLevel=pCalIspVideoPara->ContrastLevel;
        SensorScenarioParaIn.BrightnessLevel=pCalIspVideoPara->BrightnessLevel;
        SensorScenarioParaIn.SaturationLevel=pCalIspVideoPara->SaturationLevel;
        SensorScenarioParaIn.WbMode=pCalIspVideoPara->WbMode;
        SensorScenarioParaIn.EvValue=pCalIspVideoPara->EvValue;
        SensorScenarioParaIn.BandingFreq=pCalIspVideoPara->BandingFreq;
        SensorScenarioParaIn.ImageEffect=pCalIspVideoPara->ImageEffect;
        SensorScenarioParaIn.HueValue=pCalIspVideoPara->HueValue;
        ASSERT(pCalIspVideoPara->MaxVideoFrameRate>0);

        SensorScenarioParaIn.MaxVideoFrameRate=pCalIspVideoPara->MaxVideoFrameRate;// med look up video frame rate table already 10 base

        pfImageSensor->SensorCtrl(CAL_SCENARIO_VIDEO, &SensorScenarioParaIn, &SensorScenarioParaOut,
                                  sizeof(IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT), &CtrlOutLen);

        /* calculate digital zoom step */
        CurrentZoomInfo.CurrentZoomStep=pCalIspVideoPara->ZoomStep;

        pIspGetOutResParaIn->IspState=ISP_MPEG4_ENCODE_STATE;

        ErrorCode=ConfigIspGetResPara(pCalIspVideoPara->ZoomStep, pCalMdpVideoPara->VideoImageWidth,
                                      pCalMdpVideoPara->VideoImageHeight, CAM_DZ_TYPE_RANGE);


        IspDigitalZoomResParaIn.ZoomStep=pCalIspVideoPara->ZoomStep;
        IspDigitalZoomResParaIn.DzType=CAM_DZ_TYPE_RANGE;

        ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION, &IspDigitalZoomResParaIn,
                                            &IspDigitalZoomResParaOut, sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT),
                                            &FeatureOutLen);
     #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
        if (KAL_FALSE==MjpegVideoEnable)
     #endif
        {
            MdpVideoPara.mdp_crop_enable=IspDigitalZoomResParaOut.MdpCropEnable;
            MdpVideoPara.cropped_width=IspDigitalZoomResParaOut.DigitalZoomWidth;
            MdpVideoPara.cropped_height=IspDigitalZoomResParaOut.DigitalZoomHeight;

        #if (!defined(DRV_IDP_6252_SERIES))
            MdpVideoPara.preview_pitch_enable = KAL_FALSE;
            MdpVideoPara.enable_overlay = KAL_FALSE;
            MdpVideoPara.force_lcd_hw_trigger = KAL_FALSE;
            MdpVideoPara.extmem_start_address = pCalVideoPara->ExtmemStartAddress;
            MdpVideoPara.extmem_size = pCalVideoPara->ExtmemSize;
        #endif

            MdpVideoPara.source_width = pIspGetOutResParaOut->IspOutWidth;
            MdpVideoPara.source_height = pIspGetOutResParaOut->IspOutHeight;
            MdpVideoPara.display_width = pCalMdpVideoPara->DisplayImageWidth;
            MdpVideoPara.display_height = pCalMdpVideoPara->DisplayImageHeight;
            MdpVideoPara.frame_buffer_address1 = pCalMdpVideoPara->FrameBuffAddr1;
            MdpVideoPara.frame_buffer_address2 = pCalMdpVideoPara->FrameBuffAddr2;
            MdpVideoPara.frame_buffer_address3 = pCalMdpVideoPara->FrameBuffAddr3;

        #if (!defined(DRV_IDP_6252_SERIES))
            MdpVideoPara.preview_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpVideoPara->DisplayImageDataFormat;
        #endif

            MdpVideoPara.video_encode_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpVideoPara->VideoImageDataFormat;
            MdpVideoPara.video_encode_image_width = pCalMdpVideoPara->VideoImageWidth;
            MdpVideoPara.video_encode_image_height = pCalMdpVideoPara->VideoImageHeight;
            MdpVideoPara.quality_level = pCalMdpVideoPara->VideoImageQuality;
        #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
            if (CurrentScenarioId==CAL_SCENARIO_VIDEO_TELEPHONY)
            {
                MdpVideoPara.lcd_update_enable = pCalMdpVideoPara->LcdUpdateEnable;
            }
            else
            {
                MdpVideoPara.lcd_update_enable = KAL_TRUE;
            }
        #else
            MdpVideoPara.lcd_update_enable = KAL_TRUE;
        #endif
        MdpVideoPara.sensor_fps=pCalIspVideoPara->MaxVideoFrameRate*1;// med look up video frame rate table already 10 base
        MdpVideoPara.video_fps=pCalMdpVideoPara->VtEncodeFrameRate;

        #ifdef __CAL_MATV_SUPPORT__
            if(CurrentCameraId == CAL_CAMERA_SOURCE_MATV)
                MdpVideoPara.trigger_display_delay_to_frame_start_enable= KAL_TRUE;
            else
                MdpVideoPara.trigger_display_delay_to_frame_start_enable= KAL_FALSE;
        #endif
        }
    #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
        if (KAL_TRUE==MjpegVideoEnable)
        {
            CalVideoInfo.VideoImageRotAngle = MM_IMAGE_ROTATE_0;

            JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_ISP;
            jpeg_wrapper_open(&JpegWrapperHandle, JPEG_CODEC_TYPE_HW);

            JpegWrapper.srcWindow.x=0;
            JpegWrapper.srcWindow.y=0;
            JpegWrapper.srcWindow.w=0;
            JpegWrapper.srcWindow.h=0;
            JpegWrapper.srcWidth=pCalMdpVideoPara->VideoImageWidth;
            JpegWrapper.srcHeight=pCalMdpVideoPara->VideoImageHeight;
            JpegWrapper.dstWidth=pCalMdpVideoPara->VideoImageWidth;
            JpegWrapper.dstHeight=pCalMdpVideoPara->VideoImageHeight;

            JpegWrapper.extMemoryAddr=(void *) pCalVideoPara->ExtmemStartAddress;
            JpegWrapper.extMemorySize=pCalVideoPara->ExtmemSize;

            MplBuffInfo=CalVideoInfo.pfGetVideoBuff();
            JpegWrapper.dstBufferAddr=(void *) MplBuffInfo.pu1Address;
            JpegWrapper.dstBufferSize=MplBuffInfo.u4Size;
            JpegWrapper.dstQuality=JPEG_ENCODE_QUALITY_GOOD;

            JpegWrapper.srcSamplingFormat=JPEG_YUV_FORMAT_YUV422;
            JpegWrapper.dstSamplingFormat=JPEG_YUV_FORMAT_YUV422;
            JpegWrapper.dstFileFormat=JPEG_FILE_FORMAT_JPEG;
            JpegWrapper.pDstFileHandle=NULL;
            JpegWrapper.enableThumbnail=KAL_FALSE;
            JpegWrapper.callback_function=MjpegEncCallback;
            jpeg_wrapper_start(JpegWrapperHandle, &JpegWrapper);

            MdpMjpegVideoPara.source_width=pIspGetOutResParaOut->IspOutWidth;
            MdpMjpegVideoPara.source_height=pIspGetOutResParaOut->IspOutHeight;
            MdpMjpegVideoPara.display_width=pCalMdpVideoPara->DisplayImageWidth;
            MdpMjpegVideoPara.display_height=pCalMdpVideoPara->DisplayImageHeight;
            MdpMjpegVideoPara.frame_buffer_address1=pCalMdpVideoPara->FrameBuffAddr1;
            MdpMjpegVideoPara.frame_buffer_address2=pCalMdpVideoPara->FrameBuffAddr2;
            MdpMjpegVideoPara.display_rot_angle=MdpVideoPara.display_rot_angle;
            MdpMjpegVideoPara.preview_image_color_format=(MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpVideoPara->DisplayImageDataFormat;
            MdpMjpegVideoPara.preview_pitch_enable=KAL_FALSE;
            MdpMjpegVideoPara.enable_overlay=KAL_FALSE;
            MdpMjpegVideoPara.mjpeg_encode_image_width=pCalMdpVideoPara->VideoImageWidth;
            MdpMjpegVideoPara.mjpeg_encode_image_height=pCalMdpVideoPara->VideoImageHeight;
            MdpMjpegVideoPara.mjpeg_yuv_mode=MM_IMAGE_FORMAT_YUV422;

            MdpMjpegVideoPara.mdp_crop_enable=IspDigitalZoomResParaOut.MdpCropEnable;
            MdpMjpegVideoPara.cropped_width=IspDigitalZoomResParaOut.DigitalZoomWidth;
            MdpMjpegVideoPara.cropped_height=IspDigitalZoomResParaOut.DigitalZoomHeight;
            MdpMjpegVideoPara.lcd_update_enable = KAL_TRUE;

        #ifdef __CAL_MATV_SUPPORT__
            if(CurrentCameraId == CAL_CAMERA_SOURCE_MATV)
                MdpMjpegVideoPara.trigger_display_delay_to_frame_start_enable= KAL_TRUE;
            else
                MdpMjpegVideoPara.trigger_display_delay_to_frame_start_enable= KAL_FALSE;
        #endif
        }
    #endif

    #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
        if (KAL_TRUE==MjpegVideoEnable)
            ErrorCode = MdpFunc.pfnIdpCalSet(CurrentScenarioId, IdpCalKey, IDP_CAL_SET_CONFIG, &MdpMjpegVideoPara);
        else
    #endif
            ErrorCode = MdpFunc.pfnIdpCalSet(CurrentScenarioId, IdpCalKey, IDP_CAL_SET_CONFIG, &MdpVideoPara);

        ErrorCode = MdpFunc.pfnIdpCalStart(CurrentScenarioId, IdpCalKey);
        ASSERT(ErrorCode == MM_ERROR_NONE);

    #ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
        if (MM_IMAGE_ROTATE_0!=CalVideoInfo.VideoImageRotAngle)
        {
            MplBuffInfo=CalVideoInfo.pfGetVideoBuff();
            VideoRotBuffAddr = (kal_uint32) MplBuffInfo.pu1Address;
        }
    #endif

        /* config and start ISP */
        IspVideoPara.ImageTargetWidth=pCalMdpVideoPara->DisplayImageWidth;
        IspVideoPara.ImageTargetHeight=pCalMdpVideoPara->DisplayImageHeight;
        IspVideoPara.pCalIspVideoPara=pCalIspVideoPara;

        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_START;
        pIspScenarioCtrl->pScenarioCtrlPara=&IspVideoPara;
        pIspScenarioCtrl->ScenarioCtrlParaLen=sizeof(ISP_CAMERA_PREVIEW_STRUCT);

    #ifdef __CAL_TRACE_ENABLE__
        kal_trace(TRACE_INFO,CAL_VIDEO_INFO,SensorScenarioParaOut.ExposureWindowWidth, SensorScenarioParaOut.ExposureWindowWidth,
            pCalMdpVideoPara->VideoImageWidth , pCalMdpVideoPara->VideoImageHeight,  pCalIspVideoPara->MaxVideoFrameRate);
    #endif

        ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);
        if (CalVideoInfo.LcdUpdateEnable)
        {
            DisplayPreviewFrameFlag=KAL_TRUE;
        }
    #ifdef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
        if (CAL_SCENARIO_VIDEO_MJPEG==CurrentScenarioId)
            CalState=CAL_VIDEO_MJPEG_STASTE;
        else
    #else
        CalState=CAL_VIDEO_PREVIEW_STATE;
    #endif
        return ErrorCode;
    }
    return ErrorCode;
} /* CalVideoCtrl() */

#ifdef __POSTPROC_SUPPORT__
#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
static void CalMavMotionTransform(MM_IMAGE_ROTATE_ENUM RotateAngle)
{
    kal_uint32 Count;
    kal_int32 x,y;
    switch (RotateAngle)
    {
    case MM_IMAGE_ROTATE_0:
        for (Count = 0; Count < CalMavPostProcPara.ImageNumber; Count++)
        {
            x = CalMavPostProcPara.ImageMV[Count][0];
            y = CalMavPostProcPara.ImageMV[Count][1];
            CalMavPostProcPara.ImageMV[Count][0] = x*(kal_int32)CalMavSrcImageWidth/(kal_int32)CalMavResizeImageWidth;
            CalMavPostProcPara.ImageMV[Count][1] = y*(kal_int32)CalMavSrcImageHeight/(kal_int32)CalMavResizeImageHeight;
        }
    break;
    case MM_IMAGE_ROTATE_90:
        for (Count = 0; Count < CalMavPostProcPara.ImageNumber; Count++)
        {
            x = CalMavPostProcPara.ImageMV[Count][0];
            y = CalMavPostProcPara.ImageMV[Count][1];
            CalMavPostProcPara.ImageMV[Count][0] = ((kal_int32)-y)*(kal_int32)CalMavSrcImageHeight/(kal_int32)CalMavResizeImageHeight;
            CalMavPostProcPara.ImageMV[Count][1] = x*(kal_int32)CalMavSrcImageWidth/(kal_int32)CalMavResizeImageWidth;
        }
    break;
    case MM_IMAGE_ROTATE_180:
        for (Count = 0; Count < CalMavPostProcPara.ImageNumber; Count++)
        {
            x = CalMavPostProcPara.ImageMV[Count][0];
            y = CalMavPostProcPara.ImageMV[Count][1];
            CalMavPostProcPara.ImageMV[Count][0] = ((kal_int32)-x)*(kal_int32)CalMavSrcImageWidth/(kal_int32)CalMavResizeImageWidth;
            CalMavPostProcPara.ImageMV[Count][1] = ((kal_int32)-y)*(kal_int32)CalMavSrcImageHeight/(kal_int32)CalMavResizeImageHeight;
        }
    break;
    case MM_IMAGE_ROTATE_270:
        for (Count = 0; Count < CalMavPostProcPara.ImageNumber; Count++)
        {
            x = CalMavPostProcPara.ImageMV[Count][0];
            y = CalMavPostProcPara.ImageMV[Count][1];
            CalMavPostProcPara.ImageMV[Count][0] = y*(kal_int32)CalMavSrcImageHeight/(kal_int32)CalMavResizeImageHeight;
            CalMavPostProcPara.ImageMV[Count][1] = ((kal_int32)-x)*(kal_int32)CalMavSrcImageWidth/(kal_int32)CalMavResizeImageWidth;
        }
    break;
    case MM_IMAGE_H_MIRROR:
        for (Count = 0; Count < CalMavPostProcPara.ImageNumber; Count++)
        {
            x = CalMavPostProcPara.ImageMV[Count][0];
            y = CalMavPostProcPara.ImageMV[Count][1];
            CalMavPostProcPara.ImageMV[Count][0] = ((kal_int32)-x)*(kal_int32)CalMavSrcImageWidth/(kal_int32)CalMavResizeImageWidth;
            CalMavPostProcPara.ImageMV[Count][1] = y*(kal_int32)CalMavSrcImageHeight/(kal_int32)CalMavResizeImageHeight;
        }
    break;
    case MM_IMAGE_H_MIRROR_ROTATE_90:
        for (Count = 0; Count < CalMavPostProcPara.ImageNumber; Count++)
        {
            x = CalMavPostProcPara.ImageMV[Count][0];
            y = CalMavPostProcPara.ImageMV[Count][1];
            CalMavPostProcPara.ImageMV[Count][0] = y*(kal_int32)CalMavSrcImageHeight/(kal_int32)CalMavResizeImageHeight;
            CalMavPostProcPara.ImageMV[Count][1] = x*(kal_int32)CalMavSrcImageWidth/(kal_int32)CalMavResizeImageWidth;
        }
    break;
    case MM_IMAGE_H_MIRROR_ROTATE_180:
        for (Count = 0; Count < CalMavPostProcPara.ImageNumber; Count++)
        {
            x = CalMavPostProcPara.ImageMV[Count][0];
            y = CalMavPostProcPara.ImageMV[Count][1];
            CalMavPostProcPara.ImageMV[Count][0] = x*(kal_int32)CalMavSrcImageWidth/(kal_int32)CalMavResizeImageWidth;
            CalMavPostProcPara.ImageMV[Count][1] = ((kal_int32)-y)*(kal_int32)CalMavSrcImageHeight/(kal_int32)CalMavResizeImageHeight;
        }
    break;
    case MM_IMAGE_H_MIRROR_ROTATE_270:
        for (Count = 0; Count < CalMavPostProcPara.ImageNumber; Count++)
        {
            x = CalMavPostProcPara.ImageMV[Count][0];
            y = CalMavPostProcPara.ImageMV[Count][1];
            CalMavPostProcPara.ImageMV[Count][0] = ((kal_int32)-y)*(kal_int32)CalMavSrcImageHeight/(kal_int32)CalMavResizeImageHeight;
            CalMavPostProcPara.ImageMV[Count][1] = ((kal_int32)-x)*(kal_int32)CalMavSrcImageWidth/(kal_int32)CalMavResizeImageWidth;
        }
    break;
    default:
        ASSERT(0);  // should not reach here
    }
}
#endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */
MM_ERROR_CODE_ENUM CalPostProcCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__)||defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)||defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
    PP_SCENARIO_CONF_IN_STRUCT_UNION    PpConfInPara;
    PP_PROC_INFO_STRUCT                 PpProcInfoPara;
    P_CAL_CAMERA_POSTPROC_STRUCT pCalPostProcPara=(P_CAL_CAMERA_POSTPROC_STRUCT)pCtrlPara;
    kal_uint32 ExtmemStartAddress, ExtmemSize;
    PP_FEATURE_CTRL_STRUCT_UNION PpFeaturePara;
    #endif
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
    kal_bool BypassEnableFlag;
    CAL_PANO_RESULT_STRUCT CalPanoResult;
    CAL_BUFFER_CB_STRUCT CbBuff;
    PP_LOG_INFO_STRUCT PpLogPara;
    kal_uint32 PpLogSize;
    JPEG_CODEC_STATE_ENUM JpegState;
    #endif

    #if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)||defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
    P_PP_FEATURE_CONFIG_INFO_STRUCT pPpFeatureConfigPara=&PpFeatureConfigPara;
    #endif

    #ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
    kal_uint16 TempWidthHeight;
    #endif

    if (CAL_CTRL_CODE_STOP & CtrlCode)
    {
    #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
        if(pCalPostProcPara->pPostProcPara->PostProcMode & PP_MODE_HDR)
        {
            // close jpeg wrapper (HW need to be closed by Task, not HISR[jpeg callback]
            switch(CalHdrState)
            {
                case CAL_HDR_ENCODING_STATE:
                case CAL_HDR_ENCODED_STATE:
                    jpeg_wrapper_close(JpegWrapperHandle);
                    break;
                default:
                    break;
            }

            ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_STOP, 0, 0, 0);

            CalHdrState = CAL_HDR_IDLE_STATE;

            if(CAL_IDLE_STATE!=CalState)
                CalState = CAL_STANDBY_STATE;
        }
    #endif  //__HIGH_DYNAMIC_RANGE_SUPPORT__

    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if(pCalPostProcPara->pPostProcPara->PostProcMode & PP_MODE_PANORAMA)
        {
            BypassEnableFlag = KAL_FALSE;

            switch(CalPanoState)
            {
                case CAL_PANO_STITCHING_STATE:
                case CAL_PANO_STITCHED_STATE:
                    break;
                case CAL_PANO_ENCODING_STATE:
                    while(1)
                    {
                        if(JPEG_STATUS_OK==jpeg_wrapper_get_encoder_state(JpegWrapperHandle, &JpegState))
                        {
                            if((JPEG_CODEC_STATE_COMPLETE==JpegState)||(JPEG_CODEC_STATE_ERROR==JpegState))
                            {
                                jpeg_wrapper_close(JpegWrapperHandle);
                                break;
                            }
                            else
                                kal_sleep_task(5);
                        }
                        else
                            ASSERT(0);
                    }
                    break;
                case CAL_PANO_ENCODED_STATE:
                    jpeg_wrapper_close(JpegWrapperHandle);
                    break;
                default:
                    ASSERT(0);
                    break;
            }
            CalPanoState=CAL_PANO_STOPPING_STATE;

            // stop stitch
            ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_STOP, 0, 0, 0);

            //Bypass state change and ISP control when IDLE state due to STOP after CalClose in MED special case
            if(CAL_IDLE_STATE!=CalState)
            {
                /* reset ae & awb */
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AE_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AWB_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AF_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_RESET_AF, NULL, NULL, 0, 0);
            #if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
                {
                    kal_bool Enable = KAL_FALSE;
                    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AE_LIMIT_ENABLE, &Enable, NULL, 0, 0);
                }
            #endif
                CalState = CAL_STANDBY_STATE;
            }

            IsPanoPaused=KAL_FALSE;
            CalPanoState = CAL_PANO_STANDBY_STATE;
        }
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__

    #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
        if(pCalPostProcPara->pPostProcPara->PostProcMode & PP_MODE_MAV)
        {
            switch(CalMavState)
            {
                case CAL_MAV_POSTPROC_STATE:
                    break;
                case CAL_MAV_ENCODE_STATE:
                    while(1)
                    {
                        if(CAL_MAV_COMPLETE_STATE==CalMavState)
                        {
                            break;
                        }
                        else
                        {
                            kal_sleep_task(5);
                        }
                    }
                    break;
                default:
                    ASSERT(0);
            }
            // stop pp
            ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_STOP, 0, 0, 0);

            CalMavState = CAL_MAV_STANDBY_STATE;
            CalMavEnabled =KAL_FALSE;
            CalState = CAL_STANDBY_STATE;
        }
    #endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */
    }

    if (CAL_CTRL_CODE_START & CtrlCode)
    {
    #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
        if(pCalPostProcPara->pPostProcPara->PostProcMode & PP_MODE_HDR)
        {
            CAL_JPEG_DECODE_REQ_STRUCT LocalPara;
            kal_uint32 HdrYuv420BuffAddr, HdrYuv420BuffSize;
            kal_uint32 HdrWorkingBuffAddr, HdrWorkingBuffSize;
            kal_uint32 JpegWorkingBuffAddr;//, JpegWorkingBuffSize;
            kal_uint32 JpegDstBuffAddr, JpegDstBuffSize;
            kal_uint32 HdrImageWidth, HdrImageHeight;

            /* phase 0: setup information */
            IsHdrAborted = KAL_FALSE;
            ASSERT(CAL_HDR_IDLE_STATE==CalHdrState);
            CalHdrState = CAL_HDR_STANDBY_STATE;

            CalHdrUseSwEncoder = (kal_bool) !IsHwJpegEncSupport;
        #ifdef __JPEG_DEC_HW_SUPPORTED__
            CalHdrUseSwDecoder=KAL_FALSE;
        #else
            CalHdrUseSwDecoder=KAL_TRUE;
        #endif

            // 6268 limit to use sw encoder from buffer in case
            // 6268 use SW jpeg encode/decode since the MDP RDMA not support YUV420 buffer
            #if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
            CalHdrUseSwEncoder = KAL_TRUE;
            CalHdrUseSwDecoder = KAL_TRUE;
            #endif

        #ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
            if (PpMainImageRotAngle & 0x01)
            {
                TempWidthHeight = pCalPostProcPara->pMdpPara->MainImageWidth;
                pCalPostProcPara->pMdpPara->MainImageWidth = pCalPostProcPara->pMdpPara->MainImageHeight;
                pCalPostProcPara->pMdpPara->MainImageHeight = TempWidthHeight;
                TempWidthHeight = pCalPostProcPara->pMdpPara->ThumbnailImageWidth;
                pCalPostProcPara->pMdpPara->ThumbnailImageWidth=pCalPostProcPara->pMdpPara->ThumbnailImageHeight;
                pCalPostProcPara->pMdpPara->ThumbnailImageHeight=TempWidthHeight;
                TempWidthHeight = pCalPostProcPara->pMdpPara->QuickViewImageWidth;
                pCalPostProcPara->pMdpPara->QuickViewImageWidth=pCalPostProcPara->pMdpPara->QuickViewImageHeight;
                pCalPostProcPara->pMdpPara->QuickViewImageHeight=TempWidthHeight;
            }
        #endif
            // get hdr qvi dithering on or not from pp tuning paras
            CalHdrQviDitheringOn = PpTuningOperPara.hdr_qvi_dithering_flag;

            // get info from MED
            ExtmemStartAddress = pCalPostProcPara->ExtmemStartAddress;
            ExtmemSize = pCalPostProcPara->ExtmemSize;
            HdrImageWidth = pCalPostProcPara->pMdpPara->MainImageWidth;
            HdrImageHeight = pCalPostProcPara->pMdpPara->MainImageHeight;

            // set env info and enable hdr
            pPpFeatureConfigPara->PostProcMode = pCalPostProcPara->pPostProcPara->PostProcMode;
            pPpFeatureConfigPara->ImgFmtCurr = MM_IMAGE_FORMAT_YUV420;
            pPpFeatureConfigPara->ImgWidth = HdrImageWidth;
            pPpFeatureConfigPara->ImgHeight = HdrImageHeight;
            pPpFeatureConfigPara->ExtmemSize = ExtmemSize;
            PpFeaturePara.pConfigInfo = pPpFeatureConfigPara;
            PpFeatureCtrl(PP_FUNC_HDR, PP_FEATURE_SET_ENV_INFO,&PpFeaturePara, 0, 0);

            // get ext mem usage from HDR
            PpFeaturePara.pConfigInfo = pPpFeatureConfigPara;
            PpFeatureCtrl(PP_FUNC_HDR, PP_FEATURE_GET_ENV_INFO, 0, &PpFeaturePara, sizeof(PP_FEATURE_CONFIG_INFO_STRUCT));

            // dispatch ext mem for usage
            JpegDstBuffAddr = ExtmemStartAddress + CAL_JAIA_MEMORY_OFFSET;
            JpegDstBuffSize = MAX_STILL_CAPTURE_JPEG_BUFF_SIZE - CAL_JAIA_MEMORY_OFFSET;
            HdrYuv420BuffAddr = JpegDstBuffAddr + CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET;
            HdrYuv420BuffSize = HdrImageWidth*HdrImageHeight*3/2;

            // Set QVI/Thumbnail info
            kal_mem_cpy(&CalMdpPostProcPara, pCalPostProcPara->pMdpPara, sizeof(CAL_MDP_POSTPROC_STRUCT));

            HdrWorkingBuffAddr = ExtmemStartAddress + CAL_JAIA_MEMORY_OFFSET + CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET + HdrYuv420BuffSize;
            HdrWorkingBuffSize = ExtmemSize - (CAL_JAIA_MEMORY_OFFSET + CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET + HdrYuv420BuffSize);
            JpegWorkingBuffAddr = HdrWorkingBuffAddr;

            if (MM_IMAGE_ROTATE_0 != CalStillCaptureInfo.QuickViewImageRotAngle)
            {   // need to rotate quick view image after it is resized
                QuickViewImageDestBuffAddr = pCalPostProcPara->pMdpPara->QuickViewImageBuffAddr;
                CalStillCaptureInfo.QuickViewImageBuffAddr = ExtmemStartAddress + ExtmemSize - CalStillCaptureInfo.QuickViewImageWidth * CalStillCaptureInfo.QuickViewImageHeight*2;
                CalMdpPostProcPara.QuickViewImageBuffAddr = CalStillCaptureInfo.QuickViewImageBuffAddr;
            }

            CalMdpPostProcPara.QuickViewImageRotAngle=CalStillCaptureInfo.QuickViewImageRotAngle;

            #if defined(EXIF_SUPPORT)
            if(pCalPostProcPara->pMdpPara->QuickViewImageEnable || pCalPostProcPara->pMdpPara->ThumbnailImageEnable)
            {
                JaiaMergePara.WorkingBuffAddr=HdrWorkingBuffAddr;
                JaiaMergePara.WorkingBuffSize=JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE;
            }
            #endif

            // pre-config JPEG encode wrapper & jaia
            JpegWrapper.extMemoryAddr= (void *)JpegWorkingBuffAddr;
            JpegWrapper.extMemorySize= JPEG_ENC_EXT_MIN_MEM_SIZE;//JpegWorkingBuffSize;
            JpegWrapper.dstBufferAddr=(void *)JpegDstBuffAddr;
            JpegWrapper.dstBufferSize=JpegDstBuffSize;

            /* phase 1: call decode jpeg to yuv420 as hdr src */
            CalExtMemSwitchCachableRegion(&HdrYuv420BuffAddr, HdrYuv420BuffSize , CalHdrUseSwDecoder);
            CalExtMemSwitchCachableRegion(&pCalPostProcPara->SrcImageAddr, pCalPostProcPara->SrcImageSize , CalHdrUseSwDecoder);

            CalHdrJpegDecodePara.ImageSrcFormat = MM_IMAGE_FORMAT_JPEG;
            CalHdrJpegDecodePara.ImageSrcBuffer = (kal_uint8*)pCalPostProcPara->SrcImageAddr;
            CalHdrJpegDecodePara.ImageSrcBufferSize = pCalPostProcPara->SrcImageSize;
            CalHdrJpegDecodePara.SrcWidth = HdrImageWidth;
            CalHdrJpegDecodePara.SrcHeight = HdrImageHeight;
            CalHdrJpegDecodePara.SrcRoiX = 0;
            CalHdrJpegDecodePara.SrcRoiY = 0;
            CalHdrJpegDecodePara.RoiWidth = HdrImageWidth;
            CalHdrJpegDecodePara.RoiHeight = HdrImageHeight;

            CalHdrJpegDecodePara.ImageDstFormat = MM_IMAGE_FORMAT_YUV420;
            CalHdrJpegDecodePara.ImageDstBuffer = (kal_uint8*)HdrYuv420BuffAddr;
            CalHdrJpegDecodePara.DstWidth = HdrImageWidth;
            CalHdrJpegDecodePara.DstHeight = HdrImageHeight;
            CalHdrJpegDecodePara.DstRoiX = 0;
            CalHdrJpegDecodePara.DstRoiY = 0;
            CalHdrJpegDecodePara.IsSwitchCachable = KAL_TRUE;

            CalHdrJpegDecodePara.ExtMemAddr = JpegWorkingBuffAddr;
            CalHdrJpegDecodePara.ExtMemSize = JPEG_DEC_EXT_MIN_MEM_SIZE;//JpegWorkingBuffSize;

            // send msg to low task to decode
            LocalPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
            LocalPara.pJpegDecoderPara = &CalHdrJpegDecodePara;
            SendMsgToCal(MSG_ID_CAL_LOW_JPEG_DECODE_REQ, &LocalPara);

            CalHdrState = CAL_HDR_DECODING_STATE;


            /* phase 2: call hdr process */
            // config HDR process
            PpProcInfoPara.PpProcBufAddr = HdrWorkingBuffAddr;
            PpProcInfoPara.PpProcBufSize = HdrWorkingBuffSize;
            PpProcInfoPara.PpSrcBufAddr = HdrYuv420BuffAddr;
            PpProcInfoPara.PpSrcBufSize= HdrYuv420BuffSize;
            PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
            ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_START, &PpConfInPara, 0, 0);

            CalState = CAL_POSTPROC_STATE;
        }
    #endif  //__HIGH_DYNAMIC_RANGE_SUPPORT__

    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if(pCalPostProcPara->pPostProcPara->PostProcMode & PP_MODE_PANORAMA)
        {   // For panorama stitch start
            ExtmemStartAddress = pCalPostProcPara->ExtmemStartAddress;
            ExtmemSize = pCalPostProcPara->ExtmemSize;

            /* set PostProc log buffer */
            PpLogPara.ExtmemStartAddress = ExtmemStartAddress;  /* external memroy start address for algorithm engine log buffer */
            PpLogPara.ExtmemSize = ExtmemSize;          /* external memory size for algorithm engine log buffer */
            PpLogPara.ScenarioId = PP_SCENARIO_POSTPROC;
            PpFeaturePara.pLogInfo = &PpLogPara;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_LOG_INFO,&PpFeaturePara, &PpLogSize, sizeof(PpLogSize));
            ExtmemStartAddress += PpLogSize;
            ExtmemSize -= PpLogSize;

            //Store CalPanoPostProcPara in global struct
            kal_mem_cpy(&CalPanoPostProcPara.CalMdpPostProcPara, pCalPostProcPara->pMdpPara, sizeof(CAL_MDP_POSTPROC_STRUCT));
            JpegWrapper.extMemoryAddr=(void *)ExtmemStartAddress;
            JpegWrapper.extMemorySize=ExtmemSize;
            JpegWrapper.dstBufferAddr=(void *)pCalPostProcPara->JpegBuffAddr;
            JpegWrapper.dstBufferSize=pCalPostProcPara->JpegBuffSize;

            if(pCalPostProcPara->pMdpPara->QuickViewImageEnable)
            {   //Jaia
                JpegWrapper.dstBufferAddr=(void *) ((kal_uint32)JpegWrapper.dstBufferAddr+CAL_JAIA_MEMORY_OFFSET);
                JpegWrapper.dstBufferSize=JpegWrapper.dstBufferSize-CAL_JAIA_MEMORY_OFFSET;
              #if defined(EXIF_SUPPORT)
                JaiaMergePara.WorkingBuffAddr=pCalPostProcPara->ExtmemStartAddress;
                #if defined(__PANORAMA_VIEW_SUPPORT__)
                JaiaMergePara.WorkingBuffSize=JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE;
                #else /* else if defined(__AUTOCAP_PANORAMA_SUPPORT__) */
                JaiaMergePara.WorkingBuffSize=JAIA_WORKING_BUF_QVI_SIZE;
                #endif /* defined(__PANORAMA_VIEW_SUPPORT__) */
              #endif
            }

            //Initiate quick view buffer
            kal_mem_set((void *)CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr, 0, CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight*2);

            PpProcInfoPara.PpProcBufAddr = ExtmemStartAddress;
            PpProcInfoPara.PpProcBufSize = ExtmemSize;
            PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
            // start stitch
            ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_START, &PpConfInPara, 0, 0);

            CalState = CAL_POSTPROC_STATE;
            CalPanoState = CAL_PANO_STITCHING_STATE;
        }
    #endif  //__PANORAMA_VIEW_SUPPORT__||__AUTOCAP_PANORAMA_SUPPORT__
    #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
        if(pCalPostProcPara->pPostProcPara->PostProcMode & PP_MODE_MAV)
        {
            CAL_ROTATE_IMAGE_LIST_REQ_STRUCT RotateReq;
            #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__))
            kal_uint32 Cnt;
            #endif
            MAV_PROC_PARA ProcPara;

            ExtmemStartAddress = pCalPostProcPara->ExtmemStartAddress;
            ExtmemSize = pCalPostProcPara->ExtmemSize;
            /* memory arrangement:*********************************************
            * 1. start address are 1 rotate temp buffer + previously 9 captured image buffer (cap_size x10)
            * 2. following, rotate working memory in rotate stage
            * 3. after rotate, start address are 9 rotated captured image buffer
            * 4. following, postproc working memory & log memory in mav stage
            * 5. or mpo encode working memory + mpo file buffer in encode stage
            *******************************************************************/
            CalMavEnabled =KAL_TRUE;
            // rotate image list by CAL_LOW task
            RotateReq.ImageCount = CalMavPostProcPara.ImageNumber;
            RotateReq.ImageDataFormat = MM_IMAGE_FORMAT_YUV420;
            RotateReq.ImageRotAngle = CalStillCaptureInfo.MainImageRotAngle;
            RotateReq.ImageRotCbId = CAL_CBID_BEGIN;
            RotateReq.SrcImageYBuffAddr = CalMavPostProcPara.ImageBufferAddr;
            RotateReq.SrcImageUBuffAddr = CalMavPostProcPara.ImageBufferAddr
                +CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight;
            RotateReq.SrcImageVBuffAddr = CalMavPostProcPara.ImageBufferAddr
                +(CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight*5)/4;
            // dest rotate image address is shift one image size forward
            RotateReq.DestImageYBuffAddr = CalMavPostProcPara.ImageBufferAddr
                -(CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight*3)/2;
            RotateReq.DestImageUBuffAddr = CalMavPostProcPara.ImageBufferAddr
                -(CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight)/2;
            RotateReq.DestImageVBuffAddr = CalMavPostProcPara.ImageBufferAddr
                -(CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight)/4;
            // extmem start addr should be first rotated image buffer address
            ASSERT(ExtmemStartAddress == RotateReq.DestImageYBuffAddr);
            RotateReq.SrcImageWidth = CalMavSrcImageWidth;
            RotateReq.SrcImageHeight = CalMavSrcImageHeight;
            RotateReq.ImageYBuffSize = CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight;
            RotateReq.ImageUBuffSize = (CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight)/4;
            RotateReq.ImageVBuffSize = (CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight)/4;
            RotateReq.WorkingBuffAddr = ExtmemStartAddress+(CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight*3*10)/2;
            RotateReq.WorkingBuffSize = ExtmemSize-(CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight*3*10)/2;
            #define SW_ROTATE_WORKING_MEM_SIZE 32
            ASSERT(ExtmemSize>=(CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight*3*10)/2+SW_ROTATE_WORKING_MEM_SIZE);
            SendMsgToCal(MSG_ID_CAL_LOW_ROTATE_IMAGE_LIST_REQ, &RotateReq);

            //rotate and scale motion vector according to sw rotate angle
            CalMavMotionTransform(CalStillCaptureInfo.MainImageRotAngle);

            // after rotate, image buffer are put at the beginning of extmem, following is working memory
            ExtmemStartAddress += CalMavPostProcPara.ImageBufferSize;
            ExtmemSize -= CalMavPostProcPara.ImageBufferSize;
            CalMavPostProcPara.ImageBufferAddr-=(CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight*3)/2;
            CalMavPostProcPara.WorkingBuffAddr = ExtmemStartAddress;
            CalMavPostProcPara.WorkingBuffSize = ExtmemSize;

            // set env info and enable MAV
            pPpFeatureConfigPara->PostProcMode = pCalPostProcPara->pPostProcPara->PostProcMode;
            pPpFeatureConfigPara->ImgFmtCurr = MM_IMAGE_FORMAT_YUV420;
            pPpFeatureConfigPara->ImgWidth = CalMavPostProcPara.ImageWidth;
            pPpFeatureConfigPara->ImgHeight = CalMavPostProcPara.ImageHeight;
            pPpFeatureConfigPara->ExtmemStartAddress = ExtmemStartAddress;
            pPpFeatureConfigPara->ExtmemSize = ExtmemSize;
            PpFeaturePara.pConfigInfo = pPpFeatureConfigPara;
            PpFeatureCtrl(PP_FUNC_MAV, PP_FEATURE_SET_ENV_INFO,&PpFeaturePara, 0, 0);
            // get ext mem usage from MAV
            PpFeaturePara.pConfigInfo = pPpFeatureConfigPara;
            PpFeatureCtrl(PP_FUNC_MAV, PP_FEATURE_GET_ENV_INFO, 0, &PpFeaturePara, sizeof(PP_FEATURE_CONFIG_INFO_STRUCT));
            ASSERT(ExtmemSize>=pPpFeatureConfigPara->ExtmemSize);

            if (KAL_TRUE==CalMav3DImageMode)
            {
                #if (defined(__3D_IMAGE_SUPPORT__))
                // config JpegWrapper
                JpegWrapper.srcSamplingFormat=JPEG_YUV_FORMAT_PACKED_UYVY422;
                JpegWrapper.dstSamplingFormat=JPEG_YUV_FORMAT_YUV422;
                #if defined(EXIF_SUPPORT)
                JpegWrapper.dstFileFormat=JPEG_FILE_FORMAT_EXIF;
                #else
                JpegWrapper.dstFileFormat=JPEG_FILE_FORMAT_JPEG;
                #endif
                JpegWrapper.enableThumbnail=KAL_FALSE;
                JpegWrapper.thumbnailWidth=0;
                JpegWrapper.thumbnailHeight=0;
                JpegWrapper.qviImageBufferAddr=NULL;
                JpegWrapper.qviImageWidth=0;
                JpegWrapper.qviImageHeight=0;
                JpegWrapper.qviImageColorFormat=0;
                JpegWrapper.qviImageRotAngle=0;
                JpegWrapper.callback_function=NULL;
                JpegWrapper.srcMode=JPEG_ENCODE_SOURCE_YUV_BUFFER;
                // set dest buffer and working memory (shared with MAV working memory)
                JpegWrapper.extMemoryAddr = (unsigned char*)ExtmemStartAddress;
                JpegWrapper.extMemorySize = MAV_ENC_MAX_WORKING_BUF_SIZE;
                JpegWrapper.dstBufferAddr = (unsigned char*)(ExtmemStartAddress+MAV_ENC_MAX_WORKING_BUF_SIZE);
                JpegWrapper.dstBufferSize = ExtmemSize-MAV_ENC_MAX_WORKING_BUF_SIZE;
                ASSERT(ExtmemSize>=MAV_ENC_MAX_WORKING_BUF_SIZE+MAV_ENC_MAX_DESTINATION_BUF_SIZE);
                JpegWrapper.dstQuality = JPEG_ENCODE_QUALITY_GOOD;
                #endif
            }
            else
            {
                #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__))
                // config encode parameter
                MavEncWrapper.srcMode = JPEG_ENCODE_SOURCE_YUV_BUFFER;
                MavEncWrapper.srcWidth = CalMavPostProcPara.ImageWidth;
                MavEncWrapper.srcHeight = CalMavPostProcPara.ImageHeight;
                MavEncWrapper.dstSamplingFormat = JPEG_YUV_FORMAT_YUV420;
                MavEncWrapper.srcSamplingFormat = JPEG_YUV_FORMAT_YUV420;
                MavEncWrapper._alloc_func = NULL;
                MavEncWrapper._free_func = NULL;
                MavEncWrapper.frame_cnt = CalMavPostProcPara.ImageNumber;
                // set dest buffer and working memory (shared with MAV working memory)
                MavEncWrapper.working_buf = (unsigned char*)ExtmemStartAddress;
                MavEncWrapper.working_buf_size = MAV_ENC_MAX_WORKING_BUF_SIZE;
                MavEncWrapper.dst_buf = (unsigned char*)(ExtmemStartAddress+MAV_ENC_MAX_WORKING_BUF_SIZE);
                MavEncWrapper.dst_buf_size = ExtmemSize-MAV_ENC_MAX_WORKING_BUF_SIZE;
                ASSERT(ExtmemSize>=MAV_ENC_MAX_WORKING_BUF_SIZE+MAV_ENC_MAX_DESTINATION_BUF_SIZE);
                // set source buffer
                for (Cnt = 0; Cnt < MavEncWrapper.frame_cnt; Cnt++)
                {
                    kal_uint32 FrameSize = CalMavPostProcPara.ImageWidth*CalMavPostProcPara.ImageHeight*3/2;
                    MavEncWrapper.in_buf[Cnt] = (kal_uint8*)CalMavPostProcPara.ImageBufferAddr+Cnt*FrameSize;
                    MavEncWrapper.in_buf_size[Cnt] = FrameSize;
                }
                #endif
            }

            ProcPara.GlobalMotion = CalMavPostProcPara.ImageMV;
            ProcPara.ProcImageNum = CalMavPostProcPara.ImageNumber;
            PpProcInfoPara.PpSrcBufAddr = CalMavPostProcPara.ImageBufferAddr;
            PpProcInfoPara.PpSrcBufSize = CalMavPostProcPara.ImageBufferSize;
            PpProcInfoPara.PpProcBufAddr = CalMavPostProcPara.WorkingBuffAddr;
            PpProcInfoPara.PpProcBufSize = CalMavPostProcPara.WorkingBuffSize;
            PpProcInfoPara.PpProcFmt = MM_IMAGE_FORMAT_YUV420;
            PpProcInfoPara.PpProcPara = &ProcPara;
            PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
            // start mav stitch
            ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_START, &PpConfInPara, 0, 0);

            CalState = CAL_POSTPROC_STATE;
            CalMavState = CAL_MAV_POSTPROC_STATE;

        }
    #endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */
    }

    if (CAL_CTRL_CODE_PAUSE & CtrlCode)
    {
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if(pCalPostProcPara->pPostProcPara->PostProcMode & PP_MODE_PANORAMA)
        {
            //Can't call Pause before final stitch

            switch(CalPanoState)
            {
                case CAL_PANO_STANDBY_STATE:
                case CAL_PANO_ADDIMAGE_STATE:
                    ASSERT(0);
                break;
                case CAL_PANO_STITCHING_STATE:
                    //Re-stitch later after resuming
                    PauseAfterStitchFinished=KAL_FALSE;
                break;
                case CAL_PANO_STITCHED_STATE:
                case CAL_PANO_ENCODED_STATE:
                    PauseAfterStitchFinished=KAL_TRUE;
                break;
                default:
                break;
            }

            IsPanoPaused=KAL_TRUE;

            ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_PAUSE, 0, 0, 0);

            if(PauseAfterStitchFinished)
            {   //Will wait for JPEG encode done
                while(1)
                {
                    if(CAL_PANO_ENCODED_STATE==CalPanoState)
                        break;
                }
            }
        }
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
    }

    if (CAL_CTRL_CODE_RESUME & CtrlCode)
    {
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        if(pCalPostProcPara->pPostProcPara->PostProcMode & PP_MODE_PANORAMA)
        {
            IsPanoPaused=KAL_FALSE;

            //Due to MMI will call CalClose() & CalOpen() after Pause, need to restore CalState from CAL_STANDBY_STATE;
            CalState=CAL_POSTPROC_STATE;

            if(!PauseAfterStitchFinished)
            {
                ExtmemStartAddress = pCalPostProcPara->ExtmemStartAddress;
                ExtmemSize = pCalPostProcPara->ExtmemSize;

                /* set PostProc log buffer */
                PpLogPara.ExtmemStartAddress = ExtmemStartAddress;  /* external memroy start address for algorithm engine log buffer */
                PpLogPara.ExtmemSize = ExtmemSize;          /* external memory size for algorithm engine log buffer */
                PpLogPara.ScenarioId = PP_SCENARIO_POSTPROC;
                PpFeaturePara.pLogInfo = &PpLogPara;
                PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_LOG_INFO,&PpFeaturePara, &PpLogSize, sizeof(PpLogSize));
                ExtmemStartAddress += PpLogSize;
                ExtmemSize -= PpLogSize;
                //Need to re-stitch if PpCallback() not called before PAUSE

                //Re-assign working buffer due to memory may free & allocate again by MED
                JpegWrapper.extMemoryAddr=(void *)ExtmemStartAddress;
                JpegWrapper.extMemorySize=ExtmemSize;

                PpProcInfoPara.PpProcBufAddr = ExtmemStartAddress;
                PpProcInfoPara.PpProcBufSize = ExtmemSize;
                PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
                ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_RESUME, &PpConfInPara, 0, 0);
                CalPanoState=CAL_PANO_STITCHING_STATE;
            }
            else
            {
                //Restore Quick view and JPEG data and call back to MED

                CalPanoState=CAL_PANO_ENCODED_STATE;

                if(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageEnable)
                {
                    CbBuff.ImageBuffAddr = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageBuffAddr;
                    CbBuff.ImageBuffSize = CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth * CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight * 2;
                    pfCalCallback(CAL_CBID_PANO_QUICK_VIEW_IMAGE_READY, &CbBuff, sizeof(CAL_BUFFER_CB_STRUCT));

                    #if defined(EXIF_SUPPORT)
                    //Jaia
                    JaiaMergePara.MainImageStartAddr=(kal_uint32)pJpegEncodedDataAddr;
                    JaiaMergePara.MainImageSize=JpegEncodedDataSize;
                    JaiaMergePara.JaiaCbId=CAL_CBID_PANO_RESULT;
                    //JaiaMergePara.pCalStillCapPara=MainImageResizePara.pCalStillCapPara;
                    JaiaMergePara.pCalStillCapPara=&CalStillCaptureInfo;

                    // send a meesage to CAL task to start JAIA merge
                    SendMsgToCal(MSG_ID_CAL_JAIA_MERGE_REQ, &JaiaMergePara);
                    #endif
                }
                else
                {
                    CalPanoResult.ErrorStatus=MM_ERROR_NONE;
                    CalPanoResult.ImageBuffAddr=(kal_uint32)pJpegEncodedDataAddr;
                    CalPanoResult.ImageBuffSize=JpegEncodedDataSize;
                    CalPanoResult.ImgWidth=CalPanoPostProcPara.MainImageWidth;
                    CalPanoResult.ImgHeight=CalPanoPostProcPara.MainImageHeight;
                    pfCalCallback(CAL_CBID_PANO_RESULT, &CalPanoResult, sizeof(CAL_PANO_RESULT_STRUCT));
                }
            }
        }
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
    }
    return ErrorCode;
}
#endif

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__) || defined(__3D_IMAGE_SUPPORT__))
MM_ERROR_CODE_ENUM CalMavCaptureCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_CAL_CAMERA_STILL_CAPTURE_STRUCT pCalCapturePara = (P_CAL_CAMERA_STILL_CAPTURE_STRUCT) pCtrlPara;
    P_CAL_MDP_STILL_CAPTURE_STRUCT pCalMdpCapturePara=pCalCapturePara->pMdpPara;

    ISP_CAMERA_PREVIEW_STRUCT IspPreviewPara;

    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT IspDigitalZoomResParaIn;
    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT IspDigitalZoomResParaOut;

    ISP_FEATURE_SET_TG_STRUCT IspTgSettingInfo;
    SENSOR_FRAMERATE_IN_STRUCT  SensorQueryFrameRateIn;
    SENSOR_FRAMERATE_OUT_STRUCT SensorQueryFrameRateOut;

    // for IDP capability query
    IDP_CAL_QUERY_ARG_T MdpCapQueryPara;
    kal_uint32 MdpCapQueryResult;
    //kal_uint16 MdpResGetTimeOutNo=10;
    kal_uint16 MdpResGetCount=0;

    /* Post Process Parameters */
    P_CAL_POSTPROC_STRUCT pCalPostProcPreviewPara=pCalCapturePara->pPostProcPara;
    PP_FEATURE_CTRL_STRUCT_UNION    PpFeaturePara;
    P_PP_FEATURE_CONFIG_INFO_STRUCT  pPpFeatureConfigPara=&PpFeatureConfigPara;
    PP_LOG_INFO_STRUCT PpLogPara;
    kal_uint32 PpLogSize;

    kal_uint32 FeatureOutLen;
    kal_uint32 CtrlOutLen;
    kal_uint32 ExtMemAddr, ExtMemSize;

    kal_uint32 MaxImageNumber = MAV_IMAGE_NUM;

#ifdef __CAL_MINIMIZE_GLOBAL_VARIABLE__
    Camera_Preview_Idp_Cal_Struct MdpPreviewPara;
#endif

    DisplayPreviewFrameFlag=KAL_FALSE;
#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
    CalImageEffectEnable = KAL_FALSE;
#endif
    if (CAL_CTRL_CODE_STOP & CtrlCode)
    {
        gMdpPostProcTrigger = KAL_FALSE;
        CalMavEnabled = KAL_FALSE;
        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;

        ErrorCode=pfIspFunc->IspCtrl(CAL_SCENARIO_CAMERA_PREVIEW, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);

        MdpFunc.pfnIdpCalClose(CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey);
        CalState = CAL_STANDBY_STATE;
        CalMavState = CAL_MAV_STANDBY_STATE;
        IsMavReadyToShot = KAL_FALSE;

        /* Disable PP*/
        PostProcImageFromDisplayImage = KAL_FALSE;
        PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_STOP, 0, 0, 0);

        CameraImageDisplayConfig(CtrlCode, (MM_IMAGE_FORMAT_ENUM) CalPreviewInfo.ImageDataFormat,
                                     (MM_IMAGE_ROTATE_ENUM) DisplayImageSrcRotAngle,
                                     CalPreviewInfo.DisplayImageWidth, CalPreviewInfo.DisplayImageHeight,
                                     CalPreviewInfo.FrameBuffAddr1, CalPreviewInfo.FrameBuffAddr2, CalPreviewInfo.FrameBuffAddr3);

        /* disable bypass 3a */
        {
            kal_bool BypassEnableFlag=KAL_FALSE;
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AE_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AWB_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AF_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_RESET_AF, NULL, NULL, 0, 0);
        }

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_EXIT_CAMERA_PREVIEW);
    #endif
        return ErrorCode;
    }
    if (CAL_CTRL_CODE_START & CtrlCode)
    {
    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_ENTER_CAMERA_PREVIEW);
    #endif

        CalMavEnabled = KAL_TRUE;
        IsMavReadyToShot = KAL_FALSE;
        CalMavState = CAL_MAV_STANDBY_STATE;
        CalMavCaptureTimeoutFrameCount = 0;
        CalMav3DImageMode = KAL_FALSE;

        #if defined(__3D_IMAGE_SUPPORT__)
        if (pCalPostProcPreviewPara->PostProcMode == PP_MODE_MAVCAP_3D)
        {
            IsMavReadyToShot = KAL_TRUE; // capture first frame when press shutter key
            CalMav3DImageMode = KAL_TRUE;
        }
        #endif

        ExtMemAddr = pCalCapturePara->ExtmemStartAddress;
        ExtMemSize = pCalCapturePara->ExtmemSize;
        /* memory arrangement:*********************************************
        * 1. set start address as 1 rotate temp buffer + 9 captured image buffer (cap_size x10)
        * 2. following, display double (or triple) buffer (disp_size x2~3)
        * 3. following, postproc working memory & log memory
        * 4. following, mdp postproc triple buffer & mdp extmem (cap_size x3)
        *******************************************************************/
        /* config mav postproc param */
        #if defined(__3D_IMAGE_SUPPORT__)
        if (KAL_TRUE == CalMav3DImageMode)
        {
            MaxImageNumber = 2;
        }
        #endif
        CalMavPostProcPara.ImageBufferAddr = ExtMemAddr
            +(pCalMdpCapturePara->MainImageWidth*pCalMdpCapturePara->MainImageHeight*3)/2;
        CalMavPostProcPara.ImageBufferSize = (pCalMdpCapturePara->MainImageWidth*pCalMdpCapturePara->MainImageHeight*3*MaxImageNumber)/2;
        CalMavPostProcPara.ImageWidth = pCalMdpCapturePara->MainImageWidth;
        CalMavPostProcPara.ImageHeight = pCalMdpCapturePara->MainImageHeight;
        CalMavPostProcPara.ImageNumber = 0;
        ExtMemAddr+=(pCalMdpCapturePara->MainImageWidth*pCalMdpCapturePara->MainImageHeight*3*(MaxImageNumber+1))/2;
        ASSERT(ExtMemSize>=(pCalMdpCapturePara->MainImageWidth*pCalMdpCapturePara->MainImageHeight*3*(MaxImageNumber+1))/2);
        ExtMemSize-=(pCalMdpCapturePara->MainImageWidth*pCalMdpCapturePara->MainImageHeight*3*(MaxImageNumber+1))/2;

        IspTgSettingInfo.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
        IspTgSettingInfo.pSensorInfo=(void *) &CurrentSensorInfo;
        pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_TG, &IspTgSettingInfo, NULL, 0,&FeatureOutLen);

        /* config sensor driver */
        GetSensorRotAngle(CalPreviewInfo.ImageRotAngle, &MdpPreviewPara.display_rot_angle, &SensorScenarioParaIn.ImageMirror);

        IspPreviewPara.ImageMirror=SensorScenarioParaIn.ImageMirror;

        while(MdpFunc.pfnIdpCalIsInUse(CAL_SCENARIO_CAMERA_PREVIEW))
        {
            kal_sleep_task(10);
            MdpResGetCount++;
            if (10<=MdpResGetCount)
                ASSERT(0);
        }

        ErrorCode = MdpFunc.pfnIdpCalOpen( CAL_SCENARIO_CAMERA_PREVIEW, &IdpCalKey, NULL, 0);

        MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_POSTPROC_PATH;
        MdpFunc.pfnIdpCalQuery(CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey, IDP_CAL_QUERY_PATH_SUPPORT, &MdpCapQueryPara, &MdpCapQueryResult);
        if ((KAL_TRUE == MdpCapQueryResult)||(0 == pCalPostProcPreviewPara->PostProcMode))
        {   // for MT6236/68/76/55/56
            // HW support the post process output and rotate to suitable angle
            // or post process is disable
            PostProcImageFromDisplayImage = KAL_FALSE;
        }
        else
        {   // for MT6253/52/52H/35
            // HW can not support the post process output
            // SW will rotate display image for LCD when MDP callback(IDPCAL_CBID_CAM_PREVIEW_DISPLAY_FRM_DONE)
            // through CAL task if necessary
            // keep the information and re-calculate the SW rotate angle of display image
            PostProcImageFromDisplayImage = KAL_TRUE;
            ASSERT(0); // not support
        }

        // query the rotation angle that MDP can support.
        // Pass the rest rotation angle to Display driver.
        // if the rotation angle is depend on post image process, then CAL will rotate the image for display driver.
        MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_DISPLAY_PATH;
        MdpCapQueryPara.eClrFmt=(MM_IMAGE_COLOR_FORMAT_ENUM) CalPreviewInfo.ImageDataFormat;
        MdpCapQueryPara.eDesiredAngle=MdpPreviewPara.display_rot_angle;
        MdpFunc.pfnIdpCalQuery(CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey, IDP_CAL_QUERY_ROT_CAP, &MdpCapQueryPara, &MdpCapQueryResult);

        DisplayImageRotAngle=GetRestRotAngle((MM_IMAGE_ROTATE_ENUM)MdpPreviewPara.display_rot_angle, (MM_IMAGE_ROTATE_ENUM) MdpCapQueryResult);

        MdpPreviewPara.display_rot_angle = (img_rot_angle_enum_t) MdpCapQueryResult;
        MdpDisplayImageRotAngle = (MM_IMAGE_ROTATE_ENUM) MdpPreviewPara.display_rot_angle;
        DisplayImageSrcRotAngle = (MM_IMAGE_ROTATE_ENUM) MdpPreviewPara.display_rot_angle;

        MdpPreviewPara.frame_buffer_address1= ExtMemAddr;
        MdpPreviewPara.frame_buffer_address2= ExtMemAddr+CalPreviewInfo.FrameBuffSize;
        if (CalPreviewInfo.FrameBuffAddr3)
        {
            MdpPreviewPara.frame_buffer_address3= ExtMemAddr+CalPreviewInfo.FrameBuffSize*2;
            ExtMemAddr+=CalPreviewInfo.FrameBuffSize*3;
            ASSERT(ExtMemSize>=CalPreviewInfo.FrameBuffSize*3);
            ExtMemSize-=CalPreviewInfo.FrameBuffSize*3;
        }
        else
        {
            MdpPreviewPara.frame_buffer_address3= NULL;
            ExtMemAddr+=CalPreviewInfo.FrameBuffSize*2;
            ASSERT(ExtMemSize>=CalPreviewInfo.FrameBuffSize*2);
            ExtMemSize-=CalPreviewInfo.FrameBuffSize*2;
        }
        CalPreviewInfo.FrameBuffAddr1 = MdpPreviewPara.frame_buffer_address1;
        CalPreviewInfo.FrameBuffAddr2 = MdpPreviewPara.frame_buffer_address2;
        CalPreviewInfo.FrameBuffAddr3 = MdpPreviewPara.frame_buffer_address3;

        MdpPreviewPara.dbuf_tearing_free_enable = KAL_TRUE;

        /* config sw rotate angle */
        kal_mem_cpy(&CalStillCaptureInfo, pCalMdpCapturePara, sizeof(CAL_MDP_STILL_CAPTURE_STRUCT));

        if (IMAGE_SENSOR_MIRROR_HV==SensorScenarioParaIn.ImageMirror)
        {
            CalStillCaptureInfo.MainImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.MainImageRotAngle, MM_IMAGE_ROTATE_180);
        }
        else if (IMAGE_SENSOR_MIRROR_V==SensorScenarioParaIn.ImageMirror)
        {
            CalStillCaptureInfo.MainImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.MainImageRotAngle, MM_IMAGE_H_MIRROR_ROTATE_180);
        }
        else if (IMAGE_SENSOR_MIRROR_H==SensorScenarioParaIn.ImageMirror)
        {
            CalStillCaptureInfo.MainImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.MainImageRotAngle, MM_IMAGE_H_MIRROR);
        }

        #if defined(MT6250)||defined(MT6260)
        CalStillCaptureInfo.MainImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.MainImageRotAngle, MM_IMAGE_ROTATE_0);
        #else
        CalStillCaptureInfo.MainImageRotAngle=GetRestRotAngle(CalStillCaptureInfo.MainImageRotAngle, MdpDisplayImageRotAngle);
        #endif

        CalStillCaptureInfo.QuickViewImageRotAngle=GetRestRotAngle(pCalMdpCapturePara->QuickViewImageRotAngle, pCalMdpCapturePara->MainImageRotAngle);

        /* to exchange width/height because mdp postproc output is as display angle */
        if (CalStillCaptureInfo.MainImageRotAngle & 0x01)
        {
            CalMavSrcImageWidth = CalStillCaptureInfo.MainImageHeight;
            CalMavSrcImageHeight = CalStillCaptureInfo.MainImageWidth;
        }
        else
        {
            CalMavSrcImageWidth = CalStillCaptureInfo.MainImageWidth;
            CalMavSrcImageHeight = CalStillCaptureInfo.MainImageHeight;
        }


        CalDisplayDevice = CalMavDisplayDevice;
        CalDisplayContext = CalMavDisplayContext;
        CalDisplayElement = CalMavDisplayElement;

        CameraImageDisplayConfig(CtrlCode, CalPreviewInfo.ImageDataFormat,
                                 DisplayImageSrcRotAngle,
                                 CalPreviewInfo.DisplayImageWidth, CalPreviewInfo.DisplayImageHeight,
                                 CalPreviewInfo.FrameBuffAddr1, CalPreviewInfo.FrameBuffAddr2, CalPreviewInfo.FrameBuffAddr3);

        #if (defined(__AUTO_SCENE_DETECT_SUPPORT__ ))
        CalAsdEnabled=KAL_FALSE;
        #endif /* __AUTO_SCENE_DETECT_SUPPORT__ */
        #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
        CalPanoEnabled=KAL_FALSE;
        #endif  /*__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__ */
        #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
        CalHdrEnabled=KAL_FALSE;
        #endif  /*__HIGH_DYNAMIC_RANGE_SUPPORT__ */

        /* config and start PostProc */
        if(pCalPostProcPreviewPara->PostProcMode !=0)
        {
            /* set env info */
            pPpFeatureConfigPara->ExtmemStartAddress = ExtMemAddr;  /* external memroy start address for algorithm engine buffer */
            pPpFeatureConfigPara->ExtmemSize = ExtMemSize;          /* external memory size for algorithm engine buffer */
            pPpFeatureConfigPara->ImgWidth = CalMavSrcImageWidth;
            pPpFeatureConfigPara->ImgHeight = CalMavSrcImageHeight;
            pPpFeatureConfigPara->ImgFmtList = 1<<MM_IMAGE_FORMAT_YUV420;
            pPpFeatureConfigPara->ImgFmtCurr = MM_IMAGE_FORMAT_YUV420;
            pPpFeatureConfigPara->PostProcMode=pCalPostProcPreviewPara->PostProcMode;
            PpFeaturePara.pConfigInfo = pPpFeatureConfigPara;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_ENV_INFO,&PpFeaturePara, 0, 0);

            /* get env info */
            pPpFeatureConfigPara->MdpConfigFlag = KAL_FALSE;    /* initialized to false */
            pPpFeatureConfigPara->IspConfigFlag = KAL_FALSE;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_GET_ENV_INFO,0, &PpFeaturePara, sizeof(PP_FEATURE_CONFIG_INFO_STRUCT));

            //Assert if current format is not supported in format list
            ASSERT(pPpFeatureConfigPara->ImgFmtList & (1<<pPpFeatureConfigPara->ImgFmtCurr));

            CalMavResizeImageBufferAddr = pPpFeatureConfigPara->ExtmemStartAddress;
            CalMavResizeImageWidth = pPpFeatureConfigPara->ImgWidth;
            CalMavResizeImageHeight = pPpFeatureConfigPara->ImgHeight;
            ExtMemAddr += pPpFeatureConfigPara->ExtmemSize;
            ASSERT(ExtMemSize>=pPpFeatureConfigPara->ExtmemSize);
            ExtMemSize -= pPpFeatureConfigPara->ExtmemSize;

            /* set PostProc log buffer */
            PpLogPara.ExtmemStartAddress = ExtMemAddr;  /* external memroy start address for algorithm engine log buffer */
            PpLogPara.ExtmemSize = ExtMemSize;          /* external memory size for algorithm engine log buffer */
            PpLogPara.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
            PpFeaturePara.pLogInfo = &PpLogPara;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_LOG_INFO,&PpFeaturePara, &PpLogSize, sizeof(PpLogSize));
            ExtMemAddr += PpLogSize;
            ASSERT(ExtMemSize>=PpLogSize);
            ExtMemSize -= PpLogSize;
        }
        else
        {
            pPpFeatureConfigPara->MdpConfigFlag = KAL_FALSE;
            pPpFeatureConfigPara->IspConfigFlag = KAL_FALSE;
        }
        if (pPpFeatureConfigPara->MdpConfigFlag==KAL_TRUE)
        {
            gMdpPostProcTrigger = KAL_TRUE;
        }

        /* bypass ae,awb */
        if (pPpFeatureConfigPara->IspConfigFlag==KAL_TRUE)
        {
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AE_BYPASS, (void*)&pPpFeatureConfigPara->FixAe, NULL, 0, 0);
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AWB_BYPASS, (void*)&pPpFeatureConfigPara->FixAwb, NULL, 0, 0);
        }
        /* bypass af */
        {
            kal_bool BypassEnableFlag=KAL_TRUE;
            pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AF_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
        }

        SensorScenarioParaIn.ImageTargetWidth=CalPreviewInfo.DisplayImageWidth;
        SensorScenarioParaIn.ImageTargetHeight=CalPreviewInfo.DisplayImageHeight;
        if (CAM_NIGHTSCENE==CalMavIspPreviewPara.SceneMode)
            SensorScenarioParaIn.NightMode=KAL_TRUE;
        else
            SensorScenarioParaIn.NightMode=KAL_FALSE;

        SensorScenarioParaIn.MetaMode=CAMERA_SYSTEM_NORMAL_MODE;
        SensorScenarioParaIn.ContrastLevel=CalMavIspPreviewPara.ContrastLevel;
        SensorScenarioParaIn.BrightnessLevel=CalMavIspPreviewPara.BrightnessLevel;
        SensorScenarioParaIn.SaturationLevel=CalMavIspPreviewPara.SaturationLevel;
        SensorScenarioParaIn.WbMode=CalMavIspPreviewPara.WbMode;
        SensorScenarioParaIn.EvValue=CalMavIspPreviewPara.EvValue;
        SensorScenarioParaIn.BandingFreq=CalMavIspPreviewPara.BandingFreq;
        SensorScenarioParaIn.ImageEffect=CalMavIspPreviewPara.ImageEffect;
        SensorScenarioParaIn.HueValue=CalMavIspPreviewPara.HueValue;
        SensorScenarioParaIn.ZoomFactor=CurrentZoomInfo.CurrentZoomFactor;

        #if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
        CalImageEffect = CalMavIspPreviewPara.ImageEffect;
        if (CalMavIspPreviewPara.ImageEffect >= CAM_EFFECT_ENC_LOMO)
        {   /* reset image effect to normal for sensor */
            SensorScenarioParaIn.ImageEffect = CAM_EFFECT_ENC_NORMAL;
        }
        #endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

        SensorQueryFrameRateIn.Scenario= CAL_SCENARIO_CAMERA_PREVIEW;
        SensorQueryFrameRateIn.CameraIf=  CurrentSensorInfo.SensorIf;
        SensorQueryFrameRateIn.DataFormat= CurrentSensorInfo.PreviewNormalDataFormat;
        SensorQueryFrameRateIn.SourceWidth= CurrentSensorInfo.PreviewWidth;
        SensorQueryFrameRateIn.SourceHeight= CurrentSensorInfo.PreviewHeight;
        SensorQueryFrameRateIn.NighhtMode= SensorScenarioParaIn.NightMode;
        ErrorCode= SensorCommonGetFrameRate(&SensorQueryFrameRateIn, &SensorQueryFrameRateOut);
        if(ErrorCode == MM_ERROR_NONE)
            SensorScenarioParaIn.MaxVideoFrameRate = SensorQueryFrameRateOut.MaxSensorFrameRate;
        else
            SensorScenarioParaIn.MaxVideoFrameRate = 300;
        /* use sensor video mode to keep fixed sensor frame rate */
        pfImageSensor->SensorCtrl(CAL_SCENARIO_VIDEO, &SensorScenarioParaIn, &SensorScenarioParaOut,
                                  sizeof(IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT),&CtrlOutLen);

        #if 0//(defined(__RF_DESENSE_TEST__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif

        // get current zoom information for calculateing digital zoom size
        pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_CURRENT_ZOOM_INFO, NULL, (void *) &CurrentZoomInfo, 0, &FeatureOutLen);

        pIspGetOutResParaIn->IspState=ISP_PREVIEW_STATE;
        pIspGetOutResParaIn->MetaModeFlag=CctScenarioParaSet.CctMetaMode;
        pIspGetOutResParaIn->ZoomStep=CurrentZoomInfo.CurrentZoomStep;
        pIspGetOutResParaIn->SensorImageGrabStartX=SensorScenarioParaOut.GrabStartX;
        pIspGetOutResParaIn->SensorImageGrabStartY=SensorScenarioParaOut.GrabStartY;
        pIspGetOutResParaIn->SensorImageWidth=SensorScenarioParaOut.ExposureWindowWidth;
        pIspGetOutResParaIn->SensorImageHeight=SensorScenarioParaOut.ExposureWindowHeight;
        pIspGetOutResParaIn->WaitStableFrameNum=SensorScenarioParaOut.WaitStableFrameNum;
        pIspGetOutResParaIn->TargetWidth=CalPreviewInfo.DisplayImageWidth;
        pIspGetOutResParaIn->TargetHeight=CalPreviewInfo.DisplayImageHeight;

        pIspGetOutResParaIn->DzType=CurrentDzInfo.DzType;
        pIspGetOutResParaIn->pZoomFactorListTable=CurrentDzInfo.pZoomFactorListTable;

        ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_OUTPUT_RESOLUTION, pIspGetOutResParaIn,
                                            pIspGetOutResParaOut, sizeof(ISP_FEATURE_GET_OUTPUT_RESOLUTION_OUT_STRUCT),
                                            &FeatureOutLen);

        IspDigitalZoomResParaIn.DzType=CurrentDzInfo.DzType;
        IspDigitalZoomResParaIn.pZoomFactorListTable=CurrentDzInfo.pZoomFactorListTable;
        IspDigitalZoomResParaIn.ZoomStep=CurrentZoomInfo.CurrentZoomStep;

        ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION, &IspDigitalZoomResParaIn,
                                            &IspDigitalZoomResParaOut, sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT),
                                            &FeatureOutLen);
        MdpPreviewPara.mdp_crop_enable=IspDigitalZoomResParaOut.MdpCropEnable;
        MdpPreviewPara.cropped_width=IspDigitalZoomResParaOut.DigitalZoomWidth;
        MdpPreviewPara.cropped_height=IspDigitalZoomResParaOut.DigitalZoomHeight;
        /* config idp */
        MdpPreviewPara.source_width = pIspGetOutResParaOut->IspOutWidth;
        MdpPreviewPara.source_height = pIspGetOutResParaOut->IspOutHeight;
        MdpPreviewPara.display_width = CalPreviewInfo.DisplayImageWidth;
        MdpPreviewPara.display_height = CalPreviewInfo.DisplayImageHeight;
        MdpPreviewPara.preview_pitch_enable=KAL_FALSE;
        MdpPreviewPara.preview_image_color_format=(MM_IMAGE_COLOR_FORMAT_ENUM)CalPreviewInfo.ImageDataFormat;
        MdpPreviewPara.enable_overlay=KAL_FALSE;
        MdpPreviewPara.digital_zoom_frame_start_hisr_cb_enable=KAL_FALSE;
        MdpPreviewPara.lcd_update_enable=KAL_TRUE;
        MdpPreviewPara.trigger_display_delay_to_frame_start_enable= KAL_FALSE;


        if ((pPpFeatureConfigPara->MdpConfigFlag==KAL_TRUE) &&
            (KAL_FALSE==PostProcImageFromDisplayImage))
        {
            MdpPreviewPara.postproc_image_enable=KAL_TRUE;
            MdpPreviewPara.postproc_image_rot_angle= (img_rot_angle_enum_t) MM_IMAGE_ROTATE_0;
            MdpPreviewPara.postproc_image_width=CalMavSrcImageWidth;
            MdpPreviewPara.postproc_image_height=CalMavSrcImageHeight;
            MdpPreviewPara.postproc_image_buffer_address_1= ExtMemAddr;
            MdpPreviewPara.postproc_image_buffer_address_2= ExtMemAddr + (CalMavSrcImageWidth*CalMavSrcImageHeight*3)/2;
            MdpPreviewPara.postproc_image_buffer_address_3= ExtMemAddr + (CalMavSrcImageWidth*CalMavSrcImageHeight*3);
            MdpPreviewPara.postproc_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM) pPpFeatureConfigPara->ImgFmtCurr;
            MdpPreviewPara.postproc_image_done_hisr_cb_enable=KAL_TRUE;
            MdpPreviewPara.extmem_size = ExtMemSize - (CalMavSrcImageWidth*CalMavSrcImageHeight*MaxImageNumber)/2;
            MdpPreviewPara.extmem_start_address = ExtMemAddr + (CalMavSrcImageWidth*CalMavSrcImageHeight*MaxImageNumber)/2;
            ASSERT(ExtMemSize>=(CalMavSrcImageWidth*CalMavSrcImageHeight*MaxImageNumber)/2);
        }
        /* enable mdp mav capture */
        {
            kal_bool MdpMavEnable=KAL_TRUE;
            ErrorCode = MdpFunc.pfnIdpCalSet( CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey, IDP_CAL_SET_MAV_CAPTURE_ENABLE, &MdpMavEnable);
        }
        ErrorCode = MdpFunc.pfnIdpCalSet( CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey, IDP_CAL_SET_CONFIG, &MdpPreviewPara);
        ErrorCode = MdpFunc.pfnIdpCalStart( CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey);
        ASSERT(ErrorCode == MM_ERROR_NONE);

        /* config and start ISP */
        IspPreviewPara.ImageTargetWidth=CalPreviewInfo.DisplayImageWidth;
        IspPreviewPara.ImageTargetHeight=CalPreviewInfo.DisplayImageHeight;
        IspPreviewPara.pCalIspPreviewPara=&CalMavIspPreviewPara;

        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_START;
        pIspScenarioCtrl->pScenarioCtrlPara=&IspPreviewPara;
        pIspScenarioCtrl->ScenarioCtrlParaLen=sizeof(ISP_CAMERA_PREVIEW_STRUCT);
        ErrorCode=pfIspFunc->IspCtrl(CAL_SCENARIO_CAMERA_PREVIEW, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);
        if(MM_ERROR_NONE != ErrorCode)
        {   //MM_ERROR_ISP_NO_VSYNC
            MdpFunc.pfnIdpCalClose(CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey);
            CalState = CAL_STANDBY_STATE;
            //DisplayPreviewFrameFlag=KAL_FALSE;

            /* Disable PP*/
            PostProcImageFromDisplayImage = KAL_FALSE;
            PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_STOP, 0, 0, 0);

            CameraImageDisplayConfig(CAL_CTRL_CODE_STOP, CalPreviewInfo.ImageDataFormat,
                                 DisplayImageSrcRotAngle,
                                 CalPreviewInfo.DisplayImageWidth, CalPreviewInfo.DisplayImageHeight,
                                 CalPreviewInfo.FrameBuffAddr1, CalPreviewInfo.FrameBuffAddr2, CalPreviewInfo.FrameBuffAddr3);
            return ErrorCode;
        }

        CalState = CAL_CAMERA_PREVIEW_STATE;
        CalMavState = CAL_MAV_CAPTURE_STATE;
        DisplayPreviewFrameFlag=KAL_TRUE;

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_CAMERA_PREVIEW_COMPLETE);
    #endif
        return ErrorCode;
    }
    return ErrorCode;
}
#endif

#if defined(__CAMERA_GYRO_SUPPORT__)
MM_ERROR_CODE_ENUM CalCamGyroPreviewCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_CAL_CAMERA_PREVIEW_STRUCT pCalPreviewPara = (P_CAL_CAMERA_PREVIEW_STRUCT) pCtrlPara;
    P_CAL_LCD_STRUCT pCalLcdPara=pCalPreviewPara->pLcdPara;
    P_CAL_ISP_PREVIEW_STRUCT pCalIspPreviewPara=pCalPreviewPara->pIspPara;
    P_CAL_MDP_PREVIEW_STRUCT pCalMdpPreviewPara=pCalPreviewPara->pMdpPara;
    ISP_CAMERA_PREVIEW_STRUCT IspPreviewPara;

    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT IspDigitalZoomResParaIn;
    ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT IspDigitalZoomResParaOut;

    ISP_FEATURE_SET_TG_STRUCT IspTgSettingInfo;
    SENSOR_FRAMERATE_IN_STRUCT  SensorQueryFrameRateIn;
    SENSOR_FRAMERATE_OUT_STRUCT SensorQueryFrameRateOut;

    // for IDP capability query
    IDP_CAL_QUERY_ARG_T MdpCapQueryPara;
    kal_uint32 MdpCapQueryResult;
    kal_uint16 MdpResGetCount=0;

    /* Post Process Parameters */
    P_CAL_POSTPROC_STRUCT pCalPostProcPreviewPara=pCalPreviewPara->pPostProcPara;
    PP_FEATURE_CTRL_STRUCT_UNION    PpFeaturePara;
    P_PP_FEATURE_CONFIG_INFO_STRUCT  pPpFeatureConfigPara=&PpFeatureConfigPara;
    kal_uint32  PpMaxImageWidth=0,PpMaxImageHeight=0;
    PP_LOG_INFO_STRUCT PpLogPara;
    kal_uint32 PpLogSize;

    kal_uint32 FeatureOutLen;
    kal_uint32 CtrlOutLen;
    kal_uint32 ExtMemAddr, ExtMemSize;

#ifdef __CAL_MINIMIZE_GLOBAL_VARIABLE__
    Camera_Preview_Idp_Cal_Struct MdpPreviewPara;
#endif

    DisplayPreviewFrameFlag=KAL_FALSE;

    if (CAL_CTRL_CODE_STOP & CtrlCode)
    {
        CalCamGyroEnabled = KAL_FALSE;

        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
        ErrorCode=pfIspFunc->IspCtrl(CAL_SCENARIO_CAMERA_PREVIEW, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);

        MdpFunc.pfnIdpCalClose(CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey);
        CalState = CAL_STANDBY_STATE;

        /* Disable PP*/
        PostProcImageFromDisplayImage = KAL_FALSE;
        gMdpPostProcTrigger = KAL_FALSE;
        PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_STOP, 0, 0, 0);

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_EXIT_CAMERA_PREVIEW);
    #endif
        return ErrorCode;
    }
    if (CAL_CTRL_CODE_START & CtrlCode)
    {
    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_ENTER_CAMERA_PREVIEW);
    #endif

        CalCamGyroEnabled = KAL_TRUE;

        ExtMemAddr = pCalPreviewPara->ExtmemStartAddress;
        ExtMemSize = pCalPreviewPara->ExtmemSize;

        IspTgSettingInfo.ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
        IspTgSettingInfo.pSensorInfo=(void *) &CurrentSensorInfo;
        pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_TG, &IspTgSettingInfo, NULL, 0,&FeatureOutLen);

        /* config sensor driver */
        GetSensorRotAngle(pCalMdpPreviewPara->ImageRotAngle, &MdpPreviewPara.display_rot_angle, &SensorScenarioParaIn.ImageMirror);

        IspPreviewPara.ImageMirror=SensorScenarioParaIn.ImageMirror;

        pCalMdpPreviewPara->FrameBuffAddr3 = NULL;

        kal_mem_cpy(&CalPreviewInfo, pCalMdpPreviewPara, sizeof(CAL_MDP_PREVIEW_STRUCT));

        while(MdpFunc.pfnIdpCalIsInUse(CAL_SCENARIO_CAMERA_PREVIEW))
        {
            kal_sleep_task(10);
            MdpResGetCount++;
            if (10<=MdpResGetCount)
                ASSERT(0);
        }

        ErrorCode = MdpFunc.pfnIdpCalOpen( CAL_SCENARIO_CAMERA_PREVIEW, &IdpCalKey, NULL, 0);

        PostProcImageFromDisplayImage = KAL_TRUE;

        // query the rotation angle that MDP can support.
        // Pass the rest rotation angle to Display driver.
        // if the rotation angle is depend on post image process, then CAL will rotate the image for display driver.
        MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_DISPLAY_PATH;
        MdpCapQueryPara.eClrFmt=(MM_IMAGE_COLOR_FORMAT_ENUM) pCalMdpPreviewPara->ImageDataFormat;
        MdpCapQueryPara.eDesiredAngle=MdpPreviewPara.display_rot_angle;
        MdpFunc.pfnIdpCalQuery(CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey, IDP_CAL_QUERY_ROT_CAP, &MdpCapQueryPara, &MdpCapQueryResult);

        DisplayImageRotAngle=GetRestRotAngle((MM_IMAGE_ROTATE_ENUM)MdpPreviewPara.display_rot_angle, (MM_IMAGE_ROTATE_ENUM) MdpCapQueryResult);

        MdpPreviewPara.display_rot_angle = (img_rot_angle_enum_t) MdpCapQueryResult;
        MdpDisplayImageRotAngle = (MM_IMAGE_ROTATE_ENUM) MdpPreviewPara.display_rot_angle;
        DisplayImageSrcRotAngle = (MM_IMAGE_ROTATE_ENUM) MdpPreviewPara.display_rot_angle;

        MdpPreviewPara.frame_buffer_address1= pCalMdpPreviewPara->FrameBuffAddr1;
        MdpPreviewPara.frame_buffer_address2= pCalMdpPreviewPara->FrameBuffAddr2;
        MdpPreviewPara.frame_buffer_address3= pCalMdpPreviewPara->FrameBuffAddr3;

        MdpPreviewPara.dbuf_tearing_free_enable = KAL_TRUE;

        SaveDisplyHandle(pCalLcdPara);

        /* config and start PostProc */
        if(pCalPostProcPreviewPara->PostProcMode !=0)
        {
            CalCamGyroCopyBuffAddr = ExtMemAddr;
            /* set env info */
            pPpFeatureConfigPara->ExtmemStartAddress = ExtMemAddr;  /* external memroy start address for algorithm engine buffer */
            pPpFeatureConfigPara->ExtmemSize = ExtMemSize;          /* external memory size for algorithm engine buffer */
            pPpFeatureConfigPara->ImgWidth = pCalMdpPreviewPara->DisplayImageWidth;
            pPpFeatureConfigPara->ImgHeight = pCalMdpPreviewPara->DisplayImageHeight;
            pPpFeatureConfigPara->ImgFmtList = 1<<MM_IMAGE_FORMAT_YUV420;
            pPpFeatureConfigPara->ImgFmtCurr = MM_IMAGE_FORMAT_YUV420;
            pPpFeatureConfigPara->PostProcMode=pCalPostProcPreviewPara->PostProcMode;
            PpFeaturePara.pConfigInfo = pPpFeatureConfigPara;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_ENV_INFO,&PpFeaturePara, 0, 0);

            /* get env info */
            pPpFeatureConfigPara->MdpConfigFlag = KAL_FALSE;    /* initialized to false */
            pPpFeatureConfigPara->IspConfigFlag = KAL_FALSE;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_GET_ENV_INFO,0, &PpFeaturePara, sizeof(PP_FEATURE_CONFIG_INFO_STRUCT));

            //Assert if current format is not supported in format list
            ASSERT(pPpFeatureConfigPara->ImgFmtList & (1<<pPpFeatureConfigPara->ImgFmtCurr));

            PpMaxImageWidth = pPpFeatureConfigPara->MaxImgWidth;
            PpMaxImageHeight= pPpFeatureConfigPara->MaxImgHeight;
            ExtMemAddr += pPpFeatureConfigPara->ExtmemSize;
            ExtMemSize -= pPpFeatureConfigPara->ExtmemSize;

            /* set PostProc log buffer */
            PpLogPara.ExtmemStartAddress = ExtMemAddr;  /* external memroy start address for algorithm engine log buffer */
            PpLogPara.ExtmemSize = ExtMemSize;          /* external memory size for algorithm engine log buffer */
            PpLogPara.ScenarioId = PP_SCENARIO_CAMERA_PREVIEW;
            PpFeaturePara.pLogInfo = &PpLogPara;
            PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_LOG_INFO,&PpFeaturePara, &PpLogSize, sizeof(PpLogSize));
            ExtMemAddr += PpLogSize;
            ExtMemSize -= PpLogSize;
        }
        else
        {
            pPpFeatureConfigPara->MdpConfigFlag = KAL_FALSE;
            pPpFeatureConfigPara->IspConfigFlag = KAL_FALSE;
        }
        if (pPpFeatureConfigPara->MdpConfigFlag==KAL_TRUE)
        {
            gMdpPostProcTrigger = KAL_TRUE;
        }

        SensorScenarioParaIn.ImageTargetWidth=pCalMdpPreviewPara->DisplayImageWidth;
        SensorScenarioParaIn.ImageTargetHeight=pCalMdpPreviewPara->DisplayImageHeight;
        if (CAM_NIGHTSCENE==pCalIspPreviewPara->SceneMode)
            SensorScenarioParaIn.NightMode=KAL_TRUE;
        else
            SensorScenarioParaIn.NightMode=KAL_FALSE;

        SensorScenarioParaIn.MetaMode=CAMERA_SYSTEM_NORMAL_MODE;
        SensorScenarioParaIn.ContrastLevel=pCalIspPreviewPara->ContrastLevel;
        SensorScenarioParaIn.BrightnessLevel=pCalIspPreviewPara->BrightnessLevel;
        SensorScenarioParaIn.SaturationLevel=pCalIspPreviewPara->SaturationLevel;
        SensorScenarioParaIn.WbMode=pCalIspPreviewPara->WbMode;
        SensorScenarioParaIn.EvValue=pCalIspPreviewPara->EvValue;
        SensorScenarioParaIn.BandingFreq=pCalIspPreviewPara->BandingFreq;
        SensorScenarioParaIn.ImageEffect=pCalIspPreviewPara->ImageEffect;
        SensorScenarioParaIn.HueValue=pCalIspPreviewPara->HueValue;

        SensorQueryFrameRateIn.Scenario= CAL_SCENARIO_CAMERA_PREVIEW;
        SensorQueryFrameRateIn.CameraIf=  CurrentSensorInfo.SensorIf;
        SensorQueryFrameRateIn.DataFormat= CurrentSensorInfo.PreviewNormalDataFormat;
        SensorQueryFrameRateIn.SourceWidth= CurrentSensorInfo.PreviewWidth;
        SensorQueryFrameRateIn.SourceHeight= CurrentSensorInfo.PreviewHeight;
        SensorQueryFrameRateIn.NighhtMode= SensorScenarioParaIn.NightMode;
        ErrorCode= SensorCommonGetFrameRate(&SensorQueryFrameRateIn, &SensorQueryFrameRateOut);
        if(ErrorCode == MM_ERROR_NONE)
            SensorScenarioParaIn.MaxVideoFrameRate = SensorQueryFrameRateOut.MaxSensorFrameRate;
        else
            SensorScenarioParaIn.MaxVideoFrameRate = 300;

        pfImageSensor->SensorCtrl(CAL_SCENARIO_VIDEO, &SensorScenarioParaIn, &SensorScenarioParaOut,
                                  sizeof(IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT),&CtrlOutLen);

        #if 0//(defined(__RF_DESENSE_TEST__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif

        /* calculate digital zoom step */
        CurrentZoomInfo.CurrentZoomStep=pCalIspPreviewPara->ZoomStep;

        pIspGetOutResParaIn->IspState=ISP_PREVIEW_STATE;


        ErrorCode=ConfigIspGetResPara(pCalIspPreviewPara->ZoomStep, pCalMdpPreviewPara->DisplayImageWidth,
                                      pCalMdpPreviewPara->DisplayImageHeight, CurrentDzInfo.DzType);

        IspDigitalZoomResParaIn.DzType=CurrentDzInfo.DzType;
        IspDigitalZoomResParaIn.pZoomFactorListTable=CurrentDzInfo.pZoomFactorListTable;
        IspDigitalZoomResParaIn.ZoomStep=pCalIspPreviewPara->ZoomStep;
        ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION, &IspDigitalZoomResParaIn,
                                            &IspDigitalZoomResParaOut, sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT),
                                            &FeatureOutLen);
        MdpPreviewPara.mdp_crop_enable=IspDigitalZoomResParaOut.MdpCropEnable;
        MdpPreviewPara.cropped_width=IspDigitalZoomResParaOut.DigitalZoomWidth;
        MdpPreviewPara.cropped_height=IspDigitalZoomResParaOut.DigitalZoomHeight;
        /* config idp */
        MdpPreviewPara.source_width = pIspGetOutResParaOut->IspOutWidth;
        MdpPreviewPara.source_height = pIspGetOutResParaOut->IspOutHeight;
        MdpPreviewPara.display_width = pCalMdpPreviewPara->DisplayImageWidth;
        MdpPreviewPara.display_height = pCalMdpPreviewPara->DisplayImageHeight;

        MdpPreviewPara.preview_pitch_enable=KAL_FALSE;
        MdpPreviewPara.preview_image_color_format=(MM_IMAGE_COLOR_FORMAT_ENUM)pCalMdpPreviewPara->ImageDataFormat;

        MdpPreviewPara.enable_overlay=KAL_FALSE;

        MdpPreviewPara.digital_zoom_frame_start_hisr_cb_enable=KAL_FALSE;
        MdpPreviewPara.lcd_update_enable = KAL_TRUE;
    #ifdef __CAL_MATV_SUPPORT__
        MdpPreviewPara.trigger_display_delay_to_frame_start_enable= KAL_FALSE;
    #endif
        MdpPreviewPara.display_rot_angle = (img_rot_angle_enum_t)MM_IMAGE_ROTATE_0;

        MdpPreviewPara.postproc_image_enable=KAL_FALSE;

        ErrorCode = MdpFunc.pfnIdpCalSet( CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey, IDP_CAL_SET_CONFIG, &MdpPreviewPara);
        ErrorCode = MdpFunc.pfnIdpCalStart( CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey);
        ASSERT(ErrorCode == MM_ERROR_NONE);

        /* config and start ISP */
        IspPreviewPara.ImageTargetWidth=pCalMdpPreviewPara->DisplayImageWidth;
        IspPreviewPara.ImageTargetHeight=pCalMdpPreviewPara->DisplayImageHeight;
        IspPreviewPara.pCalIspPreviewPara=pCalIspPreviewPara;

        pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_START;
        pIspScenarioCtrl->pScenarioCtrlPara=&IspPreviewPara;
        pIspScenarioCtrl->ScenarioCtrlParaLen=sizeof(ISP_CAMERA_PREVIEW_STRUCT);
        ErrorCode=pfIspFunc->IspCtrl(CAL_SCENARIO_CAMERA_PREVIEW, pIspScenarioCtrl,  NULL, 0, &CtrlOutLen);
        if(MM_ERROR_NONE != ErrorCode)
        {   //MM_ERROR_ISP_NO_VSYNC
            MdpFunc.pfnIdpCalClose(CAL_SCENARIO_CAMERA_PREVIEW, IdpCalKey);
            CalState = CAL_STANDBY_STATE;

            /* Disable PP*/
            PostProcImageFromDisplayImage = KAL_FALSE;
            PpCtrl(PP_SCENARIO_CAMERA_PREVIEW, PP_CTRL_CODE_STOP, 0, 0, 0);


            CameraImageDisplayConfig(CAL_CTRL_CODE_STOP, pCalMdpPreviewPara->ImageDataFormat,
                                 DisplayImageSrcRotAngle,
                                 pCalMdpPreviewPara->DisplayImageWidth, pCalMdpPreviewPara->DisplayImageHeight,
                                 pCalMdpPreviewPara->FrameBuffAddr1, pCalMdpPreviewPara->FrameBuffAddr2, pCalMdpPreviewPara->FrameBuffAddr3);
            return ErrorCode;
        }

        if (CalPreviewInfo.LcdUpdateEnable)
        {
            DisplayPreviewFrameFlag=KAL_TRUE;
        }
        CalState = CAL_CAMERA_PREVIEW_STATE;

    #ifdef __CAL_PROFILING_ENABLE__
        CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_CAMERA_PREVIEW_COMPLETE);
    #endif
        return ErrorCode;
    }
    return ErrorCode;
}
#endif


/* To Start/Stop/Pause Camera preview, Camera Capture and Video Capture */
MM_ERROR_CODE_ENUM CalScenarioCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode,
                                   void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    CalTrace(CAL_TRACE_FLOW,CAL_FLOW_SCENARIO_CTRL,CAL_SCENARIO_CTRL,ScenarioId,CtrlCode);
    switch (ScenarioId)
    {
    #ifdef __CAL_MATV_SUPPORT__
        case CAL_SCENARIO_MATV:
    #endif
        case CAL_SCENARIO_CAMERA_PREVIEW:
            ErrorCode=CalPreviewCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
        #ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
            IsZsdScenario=KAL_FALSE;
        #endif
            ErrorCode=CalStillCaptureCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
        case CAL_SCENARIO_VIDEO:
    #ifdef __MEDIA_VT__
/* under construction !*/
    #endif
            ErrorCode=CalVideoCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
    #ifdef WEBCAM_SUPPORT
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            ErrorCode=CalWebcamCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
    #endif
    #ifdef __POSTPROC_SUPPORT__
        case CAL_SCENARIO_POST_PROCESSING:
            ErrorCode=CalPostProcCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
    #endif
    #ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
        case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
            ErrorCode=CalPreviewCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
        case CAL_SCENARIO_CAMERA_ZSD_CAPTURE:
            IsZsdScenario=KAL_TRUE;
            ErrorCode=CalStillCaptureCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
    #endif
    #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__) || defined(__3D_IMAGE_SUPPORT__))
        case CAL_SCENARIO_CAMERA_MAV_CAPTURE:
            ErrorCode=CalMavCaptureCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
    #endif
    #if defined(__CAMERA_GYRO_SUPPORT__)
        case CAL_SCENARIO_CAMERA_GYRO_PREVIEW:
            ErrorCode=CalCamGyroPreviewCtrl(ScenarioId, CtrlCode, pCtrlPara, CtrlParaLen);
        break;
    #endif
        default :
        break;
    }

    return ErrorCode;
}   /* CalScenarioCtrl() */

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

