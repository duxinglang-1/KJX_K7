/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  .h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
 *
 * Author:
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __CAL_IF_H__
#define __CAL_IF_H__

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "usbvideo_custom.h"
#include "jpeg_enum.h"
#include "jpeg_encode_wrapper.h"
#include "cal_api.h"
#include "isp_comm_def.h"
#include "sensor_comm_def.h"
#include "lens_comm_def.h"
#include "lens_module.h"
#include "cal_trace.h"
#include "pp_comm_def.h"
#include "pp_api.h"
#include "cal_comm_def.h"
#include "mpl_recorder.h"
#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__))
#include "mav_encoder.h"
#endif


#define CAL_NVRAM_READ_EVENT            0x00000001
#define CAL_GET_PREVIEW_IMAGE_EVENT     0x00000002
#define CAL_PP_ABORT_DONE_EVENT     0x00000003

#define CAL_STILL_CAPTURE_MAIN_IMAGE_BIT            0x00000001
#define CAL_STILL_CAPTURE_QUICK_VIEW_IMAGE_BIT      0x00000002
#define CAL_STILL_CAPTURE_THUMBNAIL_IMAGE_BIT       0x00000004
#define CAL_STILL_CAPTURE_IMAGE_MASK                0x00000007

#define CAL_MAX(A,B)         ( ((A)>(B)) ? A : B)
#define CAL_MIN(A,B)         ( ((A)<(B)) ? A : B)

typedef enum
{
    CAL_IDLE_STATE,
    CAL_STANDBY_STATE,
    CAL_CAMERA_PREVIEW_STATE,
    CAL_CAMERA_CAPTURE_STATE,
    CAL_VIDEO_PREVIEW_STATE,
    CAL_VIDEO_RECORD_STATE,
    CAL_VIDEO_MJPEG_STASTE,
    CAL_JPEG_ENCODE_STATE,
    CAL_WEBCAM_PREVIEW_STATE,
    CAL_WEBCAM_CAPTURE_STATE,
    CAL_POSTPROC_STATE
} CAL_STATE_ENUM;

typedef enum
{
    CAL_PANO_STANDBY_STATE,
    CAL_PANO_ADDIMAGE_STATE,
    CAL_PANO_STITCHING_STATE,
    CAL_PANO_STITCHED_STATE,
    CAL_PANO_ENCODING_STATE,
    CAL_PANO_ENCODED_STATE,
    CAL_PANO_STOPPING_STATE
} CAL_PANO_STATE_ENUM;

typedef enum
{
    CAL_HDR_STANDBY_STATE,
    CAL_HDR_DECODING_STATE,
    CAL_HDR_DECODED_STATE,
    CAL_HDR_CORE_STATE,
    CAL_HDR_QVI_STATE,
    CAL_HDR_ENCODING_STATE,
    CAL_HDR_ENCODED_STATE,
    CAL_HDR_JAIA_STATE,
    CAL_HDR_IDLE_STATE,
} CAL_HDR_STATE_ENUM;

typedef struct
{
    kal_uint32  ImgBufferAddr;
    kal_uint16  ImgWidth;
    kal_uint16  ImgHeight;
    MM_IMAGE_FORMAT_ENUM  ImgFormat;
    kal_bool ThumbnailEnable;
}CAL_PP_CB_JPG_INFO_CONFIG, *P_CAL_PP_CB_JPG_INFO_CONFIG;

typedef struct
{
    kal_uint16 MainImageWidth;
    kal_uint16 MainImageHeight;
    kal_uint16 QuickViewPanoImageWidth;
    kal_uint16 QuickViewPanoImageHeight;
    CAL_MDP_POSTPROC_STRUCT CalMdpPostProcPara;
    kal_bool ImageAlignmentHandle;
    kal_bool JaiaQviBufAligned;
} CAL_PANO_POSTPROC_STRUCT, *P_CAL_PANO_POSTPROC_STRUCT;

typedef enum
{
    CAL_MAV_STANDBY_STATE,
    CAL_MAV_CAPTURE_STATE,
    CAL_MAV_POSTPROC_STATE,
    CAL_MAV_ENCODE_STATE,
    CAL_MAV_COMPLETE_STATE
} CAL_MAV_STATE_ENUM;

typedef struct
{
    kal_uint32 ImageBufferAddr; // start addr for continuous 9 images
    kal_uint32 ImageBufferSize;
    kal_uint16 ImageWidth;    // each image size
    kal_uint16 ImageHeight;
    kal_int16 ImageMV[MAV_IMAGE_NUM][2];
    kal_uint8 ImageNumber;
    kal_uint32 WorkingBuffAddr;
    kal_uint32 WorkingBuffSize;
} CAL_MAV_POSTPROC_STRUCT, *P_CAL_MAV_POSTPROC_STRUCT;

extern CAL_STATE_ENUM CalState;
extern kal_eventgrpid CalEventId;
extern kal_bool IsHwJpegEncSupport;
//extern kal_bool IsHwJpegDecSupport;

extern CAL_CAMERA_SOURCE_ENUM CurrentCameraId;
extern CAL_SCENARIO_ENUM CurrentScenarioId;
extern P_ISP_FUNCTION_STRUCT pfIspFunc;
extern IDP_CAL_INTF_FUNC_T MdpFunc;
extern P_IMAGE_SENSOR_FUNCTION_STRUCT pfImageSensor;
extern MM_ERROR_CODE_ENUM (* pfCalCallback) (CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
extern kal_bool MainSensorSupport, SubSensorSupport;
extern kal_uint32 MainSensorId, SubSensorId;
//extern P_CAL_FEATURE_CTRL_STRUCT pCalFeatureInPara, pCalFeatureOutPara;
extern CAL_SENSOR_SUPPORT_STRUCT MainSubCameraStatus;
extern P_IMAGE_SENSOR_LIST_STRUCT pImageSensorList;
extern CAL_SCENARIO_ENUM CurrentStillScenarioId;

extern P_ISP_SCENARIO_CTRL_STRUCT pIspScenarioCtrl;
extern IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT SensorScenarioParaIn;
extern CAL_MDP_PREVIEW_STRUCT CalPreviewInfo;
extern CAL_MDP_STILL_CAPTURE_STRUCT CalStillCaptureInfo;
extern CAL_MDP_VIDEO_STRUCT CalVideoInfo;
extern ISP_FEATURE_CURRENT_ZOOM_INFO_STRUCT CurrentZoomInfo;

extern PP_FEATURE_CONFIG_INFO_STRUCT        PpFeatureConfigPara;

extern JPEG_ENCODER_HANDLE JpegWrapperHandle;
extern JPEG_WRAPPER JpegWrapper;
extern kal_uint8 *pJpegEncodedDataAddr;
extern kal_uint32 JpegEncodedDataSize;

extern kal_uint32 CurrentStillCaptureStatus;     // to keep how many images (main/quick view/thumbnail) are ready for still capture
extern kal_uint32 CurrentStillCaptureMask;       // to keep how many images (main/quick view/thumbnail) has to be captured

extern kal_bool DisplayPreviewFrameFlag;
extern kal_uint32 IdpCalKey;
extern Camera_Preview_Idp_Cal_Struct MdpPreviewPara;
extern Video_Encode_Idp_Cal_Struct MdpVideoPara;
extern Camera_Capture_Idp_Cal_Struct MdpStillCapturePara;
extern MM_IMAGE_ROTATE_ENUM MdpDisplayImageRotAngle;

extern P_LENS_LIST_STRUCT pLensList;
extern P_LENS_FUNCTION_STRUCT pfLens;
extern kal_uint32 CurrentLensListIdx;

extern kal_bool gCalPreviewPostProcPaused;  /* to avoid CPU resource conflict between CAL & VRT task */
extern kal_bool PostProcImageFromDisplayImage;
extern kal_bool gMdpPostProcTrigger; /* reduce dummy PpCtrl() calls in MdpCallback to optimize SD capture performance */
extern MM_IMAGE_ROTATE_ENUM DisplayImageRotateAngle;
// for MT6235 only, we need to use software rotation to avoid tearing by HW LCD rotate
extern MM_IMAGE_ROTATE_ENUM ImageSwRotateAngleForDisplay;

extern kal_uint32 VideoRotBuffAddr;
extern MPL_BUFFER_INFO_T MplBuffInfo;

#ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
extern MM_IMAGE_ROTATE_ENUM SwVideoRotAngle;
#endif

extern kal_uint32 QuickViewImageDestBuffAddr;

extern kal_bool IsZsdScenario;

JPEG_YUV_FORMAT_ENUM GetJpegWrapperFormat(MM_IMAGE_FORMAT_ENUM ImageFormat);
MM_ERROR_CODE_ENUM CalScenarioCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode,
                                   void *pCtrlPara, kal_uint16 CtrlParaLen);
kal_bool CalImageSwRotateDetect(P_CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_IN_STRUCT pCamSwRotPara);

///webcam related
extern CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT CalWebcamVideoSize;
extern CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT CalWebcamStillSize;
extern CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT CalWebcamCompression;
MM_ERROR_CODE_ENUM CalWebcamCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen);
MM_ERROR_CODE_ENUM CalWebcamFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureOut, kal_uint32 FeatureOutLen);
void CalWebcamInit(void);

extern kal_bool CalPanoEnabled;
#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
//Panorama
extern CAL_PANO_POSTPROC_STRUCT CalPanoPostProcPara;
extern CAL_PANO_STATE_ENUM CalPanoState;
extern kal_bool IsPanoPaused;
#endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__

#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
//Hdr
extern kal_bool CalHdrEnabled;
extern kal_bool CalHdrUseSwEncoder;
extern kal_bool CalHdrUseSwDecoder;
extern kal_bool IsHdrAborted;
extern kal_bool CalHdrQviDitheringOn;
extern CAL_MDP_POSTPROC_STRUCT CalMdpPostProcPara;
extern CAL_HDR_STATE_ENUM CalHdrState;
#endif  //__HIGH_DYNAMIC_RANGE_SUPPORT__

#if defined(__AUTO_SCENE_DETECT_SUPPORT__)
//Asd
extern kal_bool CalAsdEnabled;
extern CAL_CAMERA_SCENE_MODE_ENUM CalAsdSceneType;
extern CAL_CAMERA_SCENE_MODE_ENUM CalAsdBackupSceneType;
extern ISP_CAMERA_AWB_AF_REF_STRUCT IspAwbAfRefBuff;
extern ISP_CAMERA_INFO_3A_STRUCT IspInfoAaaBuff;
extern ISP_CAMERA_SCENE_COMPENSATION_STRUCT IspSceneCompensationParaIn;
//extern kal_uint8 CalAsdFaceLuminance;
#endif  //__AUTO_SCENE_DETECT_SUPPORT__

MM_IMAGE_ROTATE_ENUM GetRestRotAngle(MM_IMAGE_ROTATE_ENUM DesiredRotAngle,
                                     MM_IMAGE_ROTATE_ENUM AlreadyRotAngle);

MM_ERROR_CODE_ENUM CalFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                  P_CAL_FEATURE_CTRL_STRUCT pFeatureOut,
                                  kal_uint32 FeatureOutLen, kal_uint32 *pRealFeaureOutLen);

/* For MODIS */
MM_ERROR_CODE_ENUM CalModisScenarioCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode,
                                        void *pCtrlPara, kal_uint16 CtrlParaLen);

MM_ERROR_CODE_ENUM CalModisFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                       P_CAL_FEATURE_CTRL_STRUCT pFeatureOut,
                                       kal_uint32 FeatureOutLen, kal_uint32 *pRealFeatureOutLen);
/* For MODIS */

// cal_task_main.c
extern kal_bool WaitStartupCnfFlag;

void CalSendIlm(module_type SrcModId, module_type DestModId, kal_uint16 MsgId,
                void *pLocalPara, void *pPeerBuff, kal_bool FixSrcModId);

// cal_camera_nvram.c
extern ISP_FEATURE_NVRAM_INFO_STRUCT CameraNvramInfo;
extern kal_uint32 MainSensorListIdx, SubSensorListIdx, MatvSensorListIdx, CurrentSensorListIdx;
extern kal_uint32 CurrentNvramFileLid, LastNvramFileLid;

void CalSendMsgToNvram(msg_type MsgId, kal_uint16 ef_id, void *data_ptr, kal_uint16 Length);
void CalNvramReadCnfHandle(ilm_struct *pIlmPtr);
void CalNvramWriteCnfHandle(ilm_struct *pIlmPtr);
kal_uint32 GetSensorListIdx(kal_bool BySensorId, kal_uint32 SensorId, IMAGE_SENSOR_INDEX_ENUM SensorIdx);

void CctLoadNvram(void);
void CctSaveNvram(void);

// cal_feature_ctrl.c
extern kal_uint32 CalFeatureCtrlBuff1[];
extern kal_uint32 CalFeatureCtrlBuff2[];
extern IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT CurrentSensorInfo;
extern kal_uint8 NextDigitalZoomStep;
extern CAL_CAMERA_FAST_ZOOM_STRUCT FastDigitalZoomPara;
extern CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT CurrentDzInfo;
extern CAM_IMAGE_SIZE_ENUM CurrentStillCaptureSize;
extern CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT CamPreviewImageInfo;
extern kal_bool GetPreviewImageEnable;


MM_ERROR_CODE_ENUM CalPassSensorInfoToIsp(CAL_CAMERA_SOURCE_ENUM CameraId);
MM_ERROR_CODE_ENUM CalSearchSensor(void);

// cal_cb.c
MM_ERROR_CODE_ENUM IspCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
MM_ERROR_CODE_ENUM MdpCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
kal_int32 JpegEncCallback(JPEG_CODEC_STATE_ENUM State);
kal_int32 MjpegEncCallback(JPEG_CODEC_STATE_ENUM State);
MM_ERROR_CODE_ENUM PpCallback(PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
MM_ERROR_CODE_ENUM JaiaCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
MM_ERROR_CODE_ENUM ImageRotCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
MM_ERROR_CODE_ENUM ImageResizeCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
MM_ERROR_CODE_ENUM PreviewImageCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
MM_ERROR_CODE_ENUM Y2RDitheringCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
MM_ERROR_CODE_ENUM StackTimeOutCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
kal_int32 CalWebcamCallback(kal_uint32 return_code);
MM_ERROR_CODE_ENUM ImageEffectCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
void SendMsgToCal(msg_type MsgId, void *pLocalData);
void QuickViewImageRotate(kal_uint16 SrcWidth, kal_uint16 SrcHeight, kal_uint32 SrcBuffAddr,
                          kal_uint32 DestBuffAddr, MM_IMAGE_ROTATE_ENUM RotAngle);
#if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
#endif
void CalHISR(void);
void DisplayBufferAcquireCallback(void);

#if defined(__AUTO_SCENE_DETECT_SUPPORT__)
void CalSceneCompensationConfig(CAL_SCENARIO_ENUM ScenarioId, CAL_CAMERA_SCENE_MODE_ENUM SceneType, P_ISP_CAMERA_SCENE_COMPENSATION_STRUCT pPara);
#endif

// cal_scenario_ctrl.c
kal_bool CalExtMemSwitchCachableRegion(kal_uint32 *pMemAddr, kal_uint32 BufferSize, kal_bool CacheableFlag);

// cal_cct_feature_ctrl.c
MM_ERROR_CODE_ENUM CalCctFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                     P_CAL_FEATURE_CTRL_STRUCT pFeatureOut,
                                     kal_uint32 FeatureOutLen, kal_uint32 *pRealFeatureOutLen);

//cal_profiling.c
void CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_LOG_ENUM LogId);
MM_ERROR_CODE_ENUM CalProfilingFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                     P_CAL_FEATURE_CTRL_STRUCT pFeatureOut,
                                     kal_uint32 FeatureOutLen, kal_uint32 *pRealFeatureOutLen);
//cal_webcam.c
void CalWebcamInit(void);
kal_int32 CalWebcamCallback(kal_uint32 return_code);
MM_ERROR_CODE_ENUM CalWebcamCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen);
kal_int32 CalWebcamSendFrameReadyRequest(JPEG_CODEC_STATE_ENUM return_code);

// image postproc effect
#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
extern CAL_CAMERA_IMAGE_EFFECT_ENUM CalImageEffect;
extern kal_bool CalImageEffectEnable;
extern kal_uint32 DisplayImageEffectBufferAddr;
extern kal_uint8 DisplayImageEffectIdx;
#endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
extern kal_bool CalMavEnabled;
extern CAL_MAV_STATE_ENUM CalMavState;
extern CAL_MAV_POSTPROC_STRUCT CalMavPostProcPara;
extern kal_bool IsMavReadyToShot;
extern kal_bool CalMav3DImageMode;
extern kal_int16 CalMavMV[2];
extern kal_uint16 CalMavSrcImageWidth;
extern kal_uint16 CalMavSrcImageHeight;
extern kal_uint16 CalMavResizeImageWidth;
extern kal_uint16 CalMavResizeImageHeight;
extern kal_uint32 CalMavResizeImageBufferAddr;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
extern MAV_ENCODER_HANDLE MavEncWrapperHandle;
extern MAV_ENC_WRAPPER MavEncWrapper;
#endif
extern kal_uint8 CalMavCaptureTimeoutFrameCount;
#endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */

#if defined(__CAMERA_GYRO_SUPPORT__)
extern kal_bool CalCamGyroEnabled;
extern kal_uint32 CalCamGyroCopyBuffAddr;
#endif

#endif /* __CAL_IF_H__ */
