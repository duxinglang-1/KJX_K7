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
 *   cal_feature_ctrl.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "cal_api.h"
#include "cal_if.h"

#include "image_sensor.h"
#include "isp_if.h"
#include "cal_if.h"
#include "cal_drv_features.h"
#include "cct_comm_def.h"
#include "sensor_comm_def.h"
#include "pp_comm_def.h"
#include "pp_api.h"
#include "feature_comm_def.h"
#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */
#include "cal_task_msg_if.h"
#include "sensor_capability.h"

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif

#define CAL_FEATURE_CTRL_BUFF1_SIZE     (CAL_MAX(CAL_MAX(CAL_MAX(sizeof(ISP_FEATURE_CUSTOM_DRIVER_FEATURE_CTRL_FUN_STRUCT), sizeof(IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)),CAL_MAX(sizeof(ISP_SCENARIO_CTRL_STRUCT),sizeof(ISP_FEATURE_GET_OUTPUT_RESOLUTION_IN_STRUCT))),sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT)) + 8)>>2
#define CAL_FEATURE_CTRL_BUFF2_SIZE     (sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT) + 8)>>2

kal_uint32 CalFeatureCtrlBuff1[CAL_FEATURE_CTRL_BUFF1_SIZE];
kal_uint32 CalFeatureCtrlBuff2[CAL_FEATURE_CTRL_BUFF2_SIZE];

IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT CurrentSensorInfo;
kal_uint8 NextDigitalZoomStep=0;
CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT CurrentDzInfo = {CAM_DZ_TYPE_RANGE, 1 , 100 , NULL};
CAM_IMAGE_SIZE_ENUM CurrentStillCaptureSize=CAM_IMAGE_SIZE_OTHER;

#ifdef __CAL_FAST_DIGITAL_ZOOM_SUPPORT__
CAL_CAMERA_FAST_ZOOM_STRUCT FastDigitalZoomPara;
#endif
#ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT CamPreviewImageInfo;
kal_bool GetPreviewImageEnable=KAL_FALSE;
#endif
#if (defined(__JPEG_SENSOR_SUPPORT__))
IMAGE_SENSOR_CAPTURE_FORMAT_STRUCT CaptureFormatInfo;
#endif

extern kal_uint32 CalExtraQVIBuffAddr;
extern kal_uint32 CalExtraQVIBuffSize;

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
extern CAL_ISP_PREVIEW_STRUCT CalMavIspPreviewPara;
void CalMavImageSetting(kal_uint32 FeatureId, kal_uint32 FeatureSetValue)
{
    switch (FeatureId)
    {
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
        CalMavIspPreviewPara.ImageEffect = (CAL_CAMERA_IMAGE_EFFECT_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_CONTRAST:
        CalMavIspPreviewPara.ContrastLevel = (CAL_CAMERA_CONTRAST_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_SATURATION:
        CalMavIspPreviewPara.SaturationLevel = (CAL_CAMERA_SATURATION_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_SHARPNESS:
        CalMavIspPreviewPara.SharpnessLevel = (CAL_CAMERA_SHARPNESS_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_WB:
        CalMavIspPreviewPara.WbMode = (CAL_CAMERA_WB_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_EV_VALUE:
        CalMavIspPreviewPara.EvValue = (CAL_CAMERA_EV_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ:
        CalMavIspPreviewPara.BandingFreq = (CAL_CAMERA_BANDING_FREQ_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_AE_METERING_MODE:
        CalMavIspPreviewPara.AeMeteringMode = (CAL_CAMERA_AE_METERING_MODE_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_SCENE_MODE:
        CalMavIspPreviewPara.SceneMode = (CAL_CAMERA_SCENE_MODE_ENUM)FeatureSetValue;
    break;
    #if(defined(__CAL_CAMERA_AF_SUPPORT__))
    case CAL_FEATURE_CAMERA_AF_OPERATION_MODE:
        CalMavIspPreviewPara.AfOperationMode = (CAL_CAMERA_AF_OPERATION_MODE_ENUM)FeatureSetValue;
    break;
    case CAL_FEATURE_CAMERA_AF_RANGE_CONTROL:
        CalMavIspPreviewPara.AfRange = (CAL_CAMERA_AF_RANGE_ENUM)FeatureSetValue;
    break;
    #endif /* __CAL_CAMERA_AF_SUPPORT__ */
    default:
    break;
    }
}
#endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */

#if ((defined(MT6255)||defined(MT6250)||defined(MT6260))&&defined(__AUTOCAP_PANORAMA_SUPPORT__))
MM_ERROR_CODE_ENUM CalJpegCropWindow(kal_bool IsPartialEncode)
{
    kal_uint16 i, tempW, tempH;
    kal_uint32 DstOffset=0, SrcOffset, StartOffset;
    void *dstUBufferTemp;
    void *dstVBufferTemp;

    if(IsPartialEncode)
    {
        tempW=JpegWrapper.srcWindow.w-JpegWrapper.srcWindow.w%16;
        tempH=JpegWrapper.srcWindow.h-JpegWrapper.srcWindow.h%16;
    }
    else
    {
        tempW=JpegWrapper.dstWidth-JpegWrapper.dstWidth%16;
        tempH=JpegWrapper.dstHeight-JpegWrapper.dstHeight%16;
    }

    StartOffset= JpegWrapper.srcWindow.x + JpegWrapper.srcWindow.y*JpegWrapper.dstWidth;
    for(i=0; i<tempH; i++)
    {
        DstOffset=tempW*i;
        SrcOffset=JpegWrapper.dstWidth*i + StartOffset;
        kal_mem_cpy((kal_uint8 *)JpegWrapper.srcYUVBuffer[0]+DstOffset,
                    (kal_uint8 *)JpegWrapper.srcYUVBuffer[0]+SrcOffset,
                    tempW);
    }
    dstUBufferTemp=(kal_uint8 *)JpegWrapper.srcYUVBuffer[0]+DstOffset+tempW;
    tempW=tempW/2;
    tempH=tempH/2;
    StartOffset= JpegWrapper.srcWindow.x/2 + JpegWrapper.srcWindow.y*JpegWrapper.dstWidth/4;
    for(i=0; i<tempH; i++)
    {
        DstOffset=tempW*i;
        SrcOffset=JpegWrapper.dstWidth*i/2 + StartOffset;
        kal_mem_cpy((kal_uint8 *)dstUBufferTemp+DstOffset,
                    (kal_uint8 *)JpegWrapper.srcYUVBuffer[1]+SrcOffset,
                    tempW);
    }
    dstVBufferTemp=(kal_uint8 *)dstUBufferTemp+DstOffset+tempW;
    for(i=0; i<tempH; i++)
    {
        DstOffset=tempW*i;
        SrcOffset=JpegWrapper.dstWidth*i/2+StartOffset;
        kal_mem_cpy((kal_uint8 *)dstVBufferTemp+DstOffset,
                    (kal_uint8 *)JpegWrapper.srcYUVBuffer[2]+SrcOffset,
                    tempW);
    }
    JpegWrapper.srcWidth=tempW*2;
    JpegWrapper.srcHeight=tempH*2;
    JpegWrapper.dstWidth=JpegWrapper.srcWidth;
    JpegWrapper.dstHeight=JpegWrapper.srcHeight;
    JpegWrapper.srcYUVBuffer[1] = dstUBufferTemp;
    JpegWrapper.srcYUVBuffer[2] = dstVBufferTemp;
    JpegWrapper.srcBufferSize[0]=JpegWrapper.dstWidth*JpegWrapper.dstHeight;
    JpegWrapper.srcBufferSize[1]=JpegWrapper.srcBufferSize[0]/4;
    JpegWrapper.srcBufferSize[2]=JpegWrapper.srcBufferSize[0]/4;

    return MM_ERROR_NONE;
}
#endif /*(defined(MT6255)&&defined(__AUTOCAP_PANORAMA_SUPPORT__))*/

#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
MM_ERROR_CODE_ENUM CalBgPanoAddImageStart(kal_uint32 FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    P_CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT pCalPanoAddImagePara=(P_CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT)pFeatureParaIn;
    PP_FEATURE_CTRL_STRUCT_UNION PpFeaturePara;
    PANO_SET_INFO_STRUCT PanoSetEnvInfo;
    PP_SCENARIO_CONF_IN_STRUCT_UNION    PpConfInPara;
    PP_PROC_INFO_STRUCT                 PpProcInfoPara;
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    kal_uint32 CapIdx = 0;
#endif

    if ((1==pCalPanoAddImagePara->CurrentShotNumber)
        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
        || (2==pCalPanoAddImagePara->CurrentShotNumber)
        #endif
        )
    {
        /* set env info */
        PanoSetEnvInfo.SrcImgFormat    = pCalPanoAddImagePara->SrcImgFormat;
        PanoSetEnvInfo.StitchDirection = (PANO_DIRECTION_ENUM) pCalPanoAddImagePara->StitchDirection;
        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
        if (1==pCalPanoAddImagePara->CurrentShotNumber)
        {   /* the stitch dir is undecided when adding first image */
            PanoSetEnvInfo.StitchDirection = PANO_DIR_NO;
        }
        #endif
        PanoSetEnvInfo.SrcImgWidth     = pCalPanoAddImagePara->ImageWidth;
        PanoSetEnvInfo.SrcImgHeight    = pCalPanoAddImagePara->ImageHeight;
        PpFeaturePara.pPanoSetEnvInfo = &PanoSetEnvInfo;
        PpFeatureCtrl(PP_FUNC_PANORAMA, PP_FEATURE_SET_ENV_INFO,&PpFeaturePara, 0, 0);
    }
    PpProcInfoPara.PpSrcBufAddr = pCalPanoAddImagePara->ImageBufferAddr;
    PpProcInfoPara.PpSrcBufSize = pCalPanoAddImagePara->ImageBufferSize;
    PpProcInfoPara.PpProcBufAddr = pCalPanoAddImagePara->ExtmemStartAddr;
    PpProcInfoPara.PpProcBufSize = pCalPanoAddImagePara->ExtmemSize;
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_CAPTURE_EV_IDX, 0, &CapIdx, 0, 0);
    PpProcInfoPara.PpProcPara = (void*)CapIdx;
#endif
    PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
    // start background stitch
    PpCtrl(PP_SCENARIO_BG_POSTPROC, PP_CTRL_CODE_START, &PpConfInPara, 0, 0);

    CalPanoState = CAL_PANO_ADDIMAGE_STATE;

    return ErrorCode;
}

MM_ERROR_CODE_ENUM CalBgPanoAddImageResume(kal_uint32 FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    P_CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT pCalPanoAddImagePara=(P_CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT)pFeatureParaIn;
    PP_SCENARIO_CONF_IN_STRUCT_UNION    PpConfInPara;
    PP_PROC_INFO_STRUCT                 PpProcInfoPara;

    PpProcInfoPara.PpProcBufAddr = pCalPanoAddImagePara->ExtmemStartAddr;
    PpProcInfoPara.PpProcBufSize = pCalPanoAddImagePara->ExtmemSize;
    PpConfInPara.pFuncProcParaIn = &PpProcInfoPara;
    // start background stitch
    PpCtrl(PP_SCENARIO_BG_POSTPROC, PP_CTRL_CODE_RESUME, &PpConfInPara, 0, 0);

    CalPanoState = CAL_PANO_ADDIMAGE_STATE;

    return ErrorCode;
}
#endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__

MM_ERROR_CODE_ENUM CalPassSensorInfoToIsp(CAL_CAMERA_SOURCE_ENUM CameraId)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    kal_uint32 OutParaLen;
    P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT pCameraSource;
    P_ISP_FEATURE_CUSTOM_DRIVER_FEATURE_CTRL_FUN_STRUCT pfIspCustomFunc;


    if ((CAL_IDLE_STATE!=CalState)&&(CAL_CAMERA_SOURCE_MATV==CurrentCameraId)&&
     (CameraId<CAL_CAMERA_SOURCE_MATV))
    {
        return MM_ERROR_CAL_INVALID_STATE;
    }

    // inform ISP new customized function pointers.
    if (CAL_CAMERA_SOURCE_MAIN==CameraId)
    {
        CurrentSensorListIdx=MainSensorListIdx;
    }
#ifdef __CAL_DUAL_CAMERA_SUPPORT__
    else if (CAL_CAMERA_SOURCE_SUB==CameraId)
    {
        CurrentSensorListIdx=SubSensorListIdx;
    }
#endif
#ifdef __CAL_MATV_SUPPORT__
    else if (CAL_CAMERA_SOURCE_MATV==CameraId)
    {
        MatvSensorListIdx=GetSensorListIdx(KAL_FALSE,0,IMAGE_SENSOR_MATV);
        CurrentSensorListIdx=MatvSensorListIdx;
    }
#endif
    else
    {
        ASSERT(0);
        return MM_ERROR_CAL_INVALID_CAMERA_SOURCE_SELECT;
    }

    (pImageSensorList+CurrentSensorListIdx)->SensorFunc(&pfImageSensor);
    CurrentCameraId = CameraId;

#ifdef __CAL_CAMERA_LENS_SUPPORT__
    (pLensList + CurrentLensListIdx)->LensFunc(&pfLens);
#endif

    // notify ISP driver to change the function pointer of sensor feature control
    memset(&CurrentSensorInfo, 0, sizeof(CurrentSensorInfo));
    pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO, NULL,
                                     (void *) &CurrentSensorInfo, sizeof(IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT), &OutParaLen);
    pCameraSource = (P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) &CalFeatureCtrlBuff1[0];
    pCameraSource->ImageSensorIdx = (pImageSensorList+CurrentSensorListIdx)->SensorIdx;
    pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE, pCameraSource, NULL, 0, NULL);

    pfIspCustomFunc=(P_ISP_FEATURE_CUSTOM_DRIVER_FEATURE_CTRL_FUN_STRUCT) &CalFeatureCtrlBuff1[0];
    pfIspCustomFunc->CameraId=CameraId;
    pfIspCustomFunc->SensorIdx=(pImageSensorList+CurrentSensorListIdx)->SensorIdx;
    pfIspCustomFunc->pSensorInfo=(void *) &CurrentSensorInfo;
    pfIspCustomFunc->SensorFeatureCtrl=pfImageSensor->SensorFeatureCtrl;
#ifdef __CAL_CAMERA_LENS_SUPPORT__
    pfIspCustomFunc->LensFeatureControl=pfLens->LensFeatureCtrl;
#endif
    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_CUSTOM_DRIVER_FEATURE_CTRL_FUNC, pfIspCustomFunc, NULL, 0, &OutParaLen);

    #ifdef WEBCAM_SUPPORT
    if ((CAL_CAMERA_SOURCE_MAIN == CameraId) || (CAL_CAMERA_SOURCE_SUB == CameraId))
    {
        ErrorCode = pfImageSensor->SensorFeatureCtrl(CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE, NULL, &CalWebcamVideoSize, sizeof(CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT), &OutParaLen);
        ErrorCode = pfImageSensor->SensorFeatureCtrl(CAL_FEATURE_WEBCAM_GET_STILL_SIZE, NULL, &CalWebcamStillSize, sizeof(CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT), &OutParaLen);
        ErrorCode = pfImageSensor->SensorFeatureCtrl(CAL_FEATURE_WEBCAM_GET_COMPRESSION, NULL, &CalWebcamCompression, sizeof(CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT), &OutParaLen);
    }
    #endif
#if (defined(__POSTPROC_SUPPORT__))
    {   // set sensor idx for pp custom parameters upload
        PP_FEATURE_CTRL_STRUCT_UNION PpFeaturePara;
        PpFeaturePara.SensorIdx = pfIspCustomFunc->SensorIdx;
        PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_SENSOR_IDX, &PpFeaturePara, 0, 0);
    }
#endif /* defined(__POSTPROC_SUPPORT__) */
    return ErrorCode;
}   /* CalPassSensorInfoToIsp() */


MM_ERROR_CODE_ENUM CalFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                  P_CAL_FEATURE_CTRL_STRUCT pFeatureOut,
                                  kal_uint32 FeatureOutLen, kal_uint32 *pRealFeatureOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    kal_bool EnableCrzCb=KAL_FALSE;
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pFeatureOut->FeatureInfo.FeatureEnum);
    P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT pCameraDzOut=((P_CAL_FEATURE_CTRL_STRUCT)pFeatureOut)->FeatureInfo.FeatureStructured.pCamDzOutPara;
    P_CAL_CAMERA_GET_JPEG_SIZE_ESTIMATION_STRUCT pGetJpegSize=((P_CAL_FEATURE_CTRL_STRUCT)pFeatureIn)->FeatureInfo.FeatureStructured.pGetJpegSizeEstimationPara;
    #ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
    IDP_CAL_QUERY_ARG_T MdpCapQueryPara;
    kal_uint32 MdpCapQueryResult;
    #endif

#if (defined(__JPEG_SENSOR_SUPPORT__))
    P_CAL_CAMERA_DIGITAL_ZOOM_IN_STRUCT pCameraDzIn= ((P_CAL_FEATURE_CTRL_STRUCT)pFeatureIn)->FeatureInfo.FeatureStructured.pCamDzInPara;
    CAL_CAMERA_DIGITAL_ZOOM_IN_STRUCT tmpCameraDzIn;
#endif
#if defined(__SMILE_SHUTTER_SUPPORT__) || defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
    PP_FEATURE_CTRL_STRUCT_UNION    PpFeaturePara;
    P_PP_FEATURE_CONFIG_INFO_STRUCT  pPpFeatureMemPara =&PpFeatureConfigPara;
#endif
#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
    kal_bool BypassEnableFlag;
    ISP_CAMERA_UPDATE_EXIF_INFO_STRUCT tmpIspUpdateExifInfo;
#endif
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    kal_bool Enable = KAL_FALSE;
    CAL_SW_JPEG_ENCODE_REQ_STRUCT LocalPara;
    P_CAL_FEATURE_CAMERA_PANO_ENCODE_STRUCT pCalPanoEncodePara;
#endif
#ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
    kal_uint32 EventGroup;
#endif
#if (defined(__POSTPROC_SUPPORT__))
    AAA_FACE_INFO_STRUCT FaceInfo;
#endif
#if (defined(__COMPOSITE_WEBCAM__))
    char*  at_string;
    kal_uint32 at_data[4]={0};
    kal_uint32 at_data_index=0;
    char buffer[64];
    IMAGE_SENSOR_REG_IN_STRUCT SensorReg;
    SENSOR_REG_WIDTH_STRUCT SensorRegWidth;
    kal_uint32 RegData=0;
    extern CAL_STATE_ENUM CalState;
#endif
    kal_bool FeatureEnumIsSupport;
    if ((pFeatureIn->FeatureId>CAL_FEATURE_CAMERA_BEGIN)&&
             (pFeatureIn->FeatureId<CAL_FEATURE_CAMERA_END))
    {
        CalTrace(CAL_TRACE_FLOW,CAL_FLOW_CAMERA_FEATURE_CTRL,CAL_FEATURE_CTRL,pFeatureIn->FeatureId,pFeatureIn->FeatureCtrlCode);
        switch (pFeatureIn->FeatureId)
        {
            case CAL_FEATURE_CAMERA_SOURCE_SELECT:
                if (pFeatureIn->FeatureSetValue != CurrentCameraId)
                    ErrorCode =CalPassSensorInfoToIsp((CAL_CAMERA_SOURCE_ENUM) pFeatureIn->FeatureSetValue);
            break;
            case CAL_FEATURE_CAMERA_DIGITAL_ZOOM:
#if (defined(__AUTOCAP_PANORAMA_SUPPORT__))
                if (CAL_CAMERA_MODE_AUTORAMA==pFeatureIn->CameraMode&&(CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode))
                {   /* to limit max autorama zoom = 3x due to bandwidth limitation of 1024x768 cap size */
                    pFeatureOut->FeatureType = CAL_FEATURE_TYPE_STRUCTURED;
                    pCameraDzOut->DzType=CAM_DZ_TYPE_RANGE;
                    pCameraDzOut->MaxZoomFactor = 300;
                    pCameraDzOut->TotalZoomSteps = 30;
                    memcpy(&CurrentDzInfo, pCameraDzOut, sizeof(CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT));
                    break;
                }
#endif
#if (defined(__JPEG_SENSOR_SUPPORT__))
//                if ((IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG==CurrentSensorInfo.CaptureDataFormat)&&(CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode))
                if((CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode)&&(IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG == CurrentSensorInfo.CaptureDataFormat)&&(CAL_CAMERA_MODE_CAMERA==pFeatureIn->CameraMode))
                {   // query from sensor, the type would be structured

                    pCameraDzIn->ScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;

                    pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, pCameraDzIn, pCameraDzOut, FeatureOutLen, pRealFeatureOutLen);
                }
                else
#endif
                {   // query from ISP driver. the type would be range
                    if (CAL_FEATURE_SET_OPERATION==pFeatureIn->FeatureCtrlCode)
                    {   // 1. Notify MDP to callback when CRZ interrupt
                        // 2. Notify ISP to set the result window, execute in MdpCallback()
                        // 3. Notify MDP to configure CRZ, execute in MdpCallback()
                    #ifdef __CAL_FAST_DIGITAL_ZOOM_SUPPORT__
                        FastDigitalZoomPara.ZoomStart=KAL_FALSE;
                    #endif
                        NextDigitalZoomStep=pFeatureIn->FeatureSetValue;
                        EnableCrzCb=KAL_TRUE;
                        ErrorCode = MdpFunc.pfnIdpCalSet(CurrentScenarioId, IdpCalKey,  IDP_CAL_SET_CRZ_FRAMESTART_CB_ENABLE, &EnableCrzCb);
                    }
                    else
                    {   // query/get from ISP driver directly
                        ErrorCode =pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
                        if(CAL_CAMERA_MODE_CAMERA==pFeatureIn->CameraMode)
                            memcpy(&CurrentDzInfo, pCameraDzOut, sizeof(CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT));

                    }
                }
            break;
            case CAL_FEATURE_CAMERA_CURRENT_ZOOM_FACTOR:
            case CAL_FEATURE_CAMERA_CURRENT_ZOOM_STEP:
                if (CAL_FEATURE_GET_OPERATION==pFeatureIn->FeatureCtrlCode)
                {
                    ErrorCode =pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_CURRENT_ZOOM_INFO, NULL, (void *) &CurrentZoomInfo, 0, &FeatureOutLen);
                    if (CAL_FEATURE_CAMERA_CURRENT_ZOOM_FACTOR==pFeatureIn->FeatureId)
                        pFeatureOut->FeatureCurrentValue=CurrentZoomInfo.CurrentZoomFactor;
                    else
                        pFeatureOut->FeatureCurrentValue=CurrentZoomInfo.CurrentZoomStep;
                }
            break;
        #ifdef __CAL_FAST_DIGITAL_ZOOM_SUPPORT__
            case CAL_FEATURE_CAMERA_FAST_ZOOM:
                if (CAL_FEATURE_SET_OPERATION==pFeatureIn->FeatureCtrlCode)
                {   // enable CRZ callback
                    kal_mem_cpy(&FastDigitalZoomPara, pFeatureIn->FeatureInfo.FeatureStructured.pCamFastZoom, sizeof(CAL_CAMERA_FAST_ZOOM_STRUCT));
                    EnableCrzCb=FastDigitalZoomPara.ZoomStart;
                    ErrorCode = MdpFunc.pfnIdpCalSet(CurrentScenarioId, IdpCalKey,  IDP_CAL_SET_CRZ_FRAMESTART_CB_ENABLE, &EnableCrzCb);
                }
            break;
        #endif
            case CAL_FEATURE_CAMERA_BINNING_INFO:
                {
                    P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo=pFeatureOut->FeatureInfo.FeatureStructured.pBinningInfo;
                    kal_uint8 i;
                    for (i=CAM_ISO_AUTO;i<CAM_NO_OF_ISO;i++)
                    {
                        pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_1M;
                        pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_FALSE;
                        pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_FALSE;
                    }
                }
            break;
            case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
                // call to camera_common for customization
                ErrorCode=pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
                if (CAL_FEATURE_SET_OPERATION==pFeatureIn->FeatureCtrlCode)
                    CurrentStillCaptureSize= (CAM_IMAGE_SIZE_ENUM) pFeatureIn->FeatureSetValue;

                #if (defined(__JPEG_SENSOR_SUPPORT__))
                if(IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG == CurrentSensorInfo.CaptureDataFormat)
                {
                    CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT CameraDzOut;

                    tmpCameraDzIn.ScenarioId = CAL_SCENARIO_CAMERA_PREVIEW;
                    tmpCameraDzIn.CameraImageSize = CurrentStillCaptureSize;

                    pfImageSensor->SensorFeatureCtrl(CAL_FEATURE_CAMERA_DIGITAL_ZOOM, &tmpCameraDzIn, &CameraDzOut, 0, NULL);
                    memcpy(&CurrentDzInfo, &CameraDzOut, sizeof(CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT));

                    ErrorCode =pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_CAPTURE_FORMAT, &tmpCameraDzIn, &CaptureFormatInfo, FeatureOutLen, pRealFeatureOutLen);
                    ErrorCode =pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_CAPTURE_FORMAT, &CaptureFormatInfo, NULL , 0, NULL);
                }
                #endif
            break;
            case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE_WITH_DIMENSION:
                //if ((CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode) && (NULL!=pFeatureIn->FeatureInfo.FeatureEnum.SupportItemInfo))
                {
                   memset(pFeatureIn->FeatureInfo.FeatureEnum.SupportItemInfo,0x0,sizeof(CAL_CAMERA_IMAGE_SIZE_STRUCT)*MAX_CAMERA_SUPPORT_ITEM_COUNT);
                }

                ErrorCode=pfImageSensor->SensorFeatureCtrl(CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
                FeatureEnumIsSupport = pFeatureOut->FeatureInfo.FeatureEnum.IsSupport;
                pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);

                //if ((CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode) && (NULL!=pFeatureIn->FeatureInfo.FeatureEnum.SupportItemInfo))
                {
                     if (FeatureEnumIsSupport)
                     {
                         kal_uint8 i;
                         P_CAL_CAMERA_IMAGE_SIZE_STRUCT pCalImageSize;

                         pCalImageSize = (CAL_CAMERA_IMAGE_SIZE_STRUCT *) pFeatureOut->FeatureInfo.FeatureEnum.SupportItemInfo;
                         pFeatureOut->FeatureInfo.FeatureEnum.IsSupport = FeatureEnumIsSupport;

                         for (i=0;i<pFeatureOut->FeatureInfo.FeatureEnum.ItemCount;i++)
                         {
                               //if ((0 ==pCalImageSize[i].ImageSizeWidth) && (0 ==pCalImageSize[i].ImageSizeHeight)) // It doesn't update in sensor driver
                               if (0 ==pCalImageSize[i].ImageSizeWidth) // It doesn't update in sensor driver
                               {
                                    switch (pFeatureOut->FeatureInfo.FeatureEnum.SupportItem[i])
                                    {
                                        case CAM_IMAGE_SIZE_QVGA:
                                                 pCalImageSize[i].ImageSizeWidth = 320;
                                                 pCalImageSize[i].ImageSizeHeight = 240;
                                                 break;
                                    #if (IMAGE_SENSOR_TARGET_MAX_WIDTH>=IMAGE_03M_MAX_WIDTH)
                                        case CAM_IMAGE_SIZE_VGA:
                                                 pCalImageSize[i].ImageSizeWidth = 640;
                                                 pCalImageSize[i].ImageSizeHeight = 480;
                                                 break;
                                    #endif
                                    #if (IMAGE_SENSOR_TARGET_MAX_WIDTH>=IMAGE_1M_MAX_WIDTH)
                                        case CAM_IMAGE_SIZE_1M:
                                                 pCalImageSize[i].ImageSizeWidth = 1280;
                                                 pCalImageSize[i].ImageSizeHeight = 960;//1024 or 960 ?
                                                 break;
                                    #endif
                                    #if (IMAGE_SENSOR_TARGET_MAX_WIDTH>=IMAGE_2M_MAX_WIDTH)
                                        case CAM_IMAGE_SIZE_2M:
                                                 pCalImageSize[i].ImageSizeWidth = 1600;
                                                 pCalImageSize[i].ImageSizeHeight = 1200;
                                                 break;
                                    #endif
                                    #if (IMAGE_SENSOR_TARGET_MAX_WIDTH>=IMAGE_3M_MAX_WIDTH)
                                        case CAM_IMAGE_SIZE_3M:
                                                 pCalImageSize[i].ImageSizeWidth = 2048;
                                                 pCalImageSize[i].ImageSizeHeight = 1536;
                                                 break;
                                    #endif
                                    #if (IMAGE_SENSOR_TARGET_MAX_WIDTH>=IMAGE_5M_MAX_WIDTH)
                                        case CAM_IMAGE_SIZE_5M:
                                                 pCalImageSize[i].ImageSizeWidth = 2592;
                                                 pCalImageSize[i].ImageSizeHeight = 1944;
                                                 break;
                                    #endif
                                    #if (IMAGE_SENSOR_TARGET_MAX_WIDTH>=IMAGE_8M_MAX_WIDTH)
                                        case CAM_IMAGE_SIZE_8M:
                                                 pCalImageSize[i].ImageSizeWidth = 3264;
                                                 pCalImageSize[i].ImageSizeHeight = 2448;
                                                 break;
                                    #endif
                         default:
                            break;
                                    }
                               }
                         }
                     }
                }
            break;
        #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
            case CAL_FEATURE_CAMERA_ZSD_CAPTURE_SIZE:
                if(IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG!=CurrentSensorInfo.CaptureDataFormat)
                    pFeatureIn->FeatureId = CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE;

                ErrorCode=pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
            break;
        #endif
            case CAL_FEATURE_CAMERA_STILL_CAPTURE_MODE:
                ErrorCode=pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
            break;
        #ifdef __CAL_CAPTURE_MODE_BSS_SUPPORT__
            case CAL_FEATURE_CAMERA_GET_BSS_RESULT:
                ErrorCode=pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
            break;
        #endif
    #if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
            case CAL_FEATURE_CAMERA_PANO_DIRECTION:
            break;
            case CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_START:
                ErrorCode=CalBgPanoAddImageStart(pFeatureIn->FeatureId, (void*)pFeatureIn->FeatureInfo.FeatureStructured.pPanoAddImgPara, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
            break;
            case CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_STOP:
                // Abort Panorama
                BypassEnableFlag=KAL_FALSE;

                ErrorCode=PpCtrl(PP_SCENARIO_BG_POSTPROC, PP_CTRL_CODE_STOP, 0, 0, 0);
                //Bypass ISP control when IDLE state due to STOP after CalClose in MED special case
                if(CAL_IDLE_STATE!=CalState)
                {
                    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AE_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
                    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AWB_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
                    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AF_BYPASS, (void*)&BypassEnableFlag, NULL, 0, 0);
                    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_RESET_AF, NULL, NULL, 0, 0);
                    #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
                    Enable = KAL_FALSE;
                    pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_AE_LIMIT_ENABLE, &Enable, NULL, 0, 0);
                    #endif
                }
                IsPanoPaused=KAL_FALSE;
                CalPanoState = CAL_PANO_STANDBY_STATE;
            break;
           case CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_PAUSE:
                IsPanoPaused=KAL_TRUE;
                ErrorCode = PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_PAUSE, 0, 0, 0);
            break;
            case CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_RESUME:
                IsPanoPaused=KAL_FALSE;
                ErrorCode=CalBgPanoAddImageResume(pFeatureIn->FeatureId, (void*)pFeatureIn->FeatureInfo.FeatureStructured.pPanoAddImgPara, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
            break;
        #if defined(__AUTOCAP_PANORAMA_SUPPORT__)
            case CAL_FEATURE_CAMERA_ENCODE_PANORAMA:

                LocalPara.ScenarioId = CAL_SCENARIO_POST_PROCESSING;
                pCalPanoEncodePara=(P_CAL_FEATURE_CAMERA_PANO_ENCODE_STRUCT)pFeatureIn->FeatureInfo.FeatureStructured.pPanoEncodePara;

                //Check if need to do Jpeg partial encode
                if((pCalPanoEncodePara->QuickviewRoiWidth<CalPanoPostProcPara.QuickViewPanoImageWidth)||
                    (pCalPanoEncodePara->QuickviewRoiHeight<CalPanoPostProcPara.QuickViewPanoImageHeight))
                {
                    JpegWrapper.srcWindow.x = (pCalPanoEncodePara->QuickviewRoiX*JpegWrapper.srcWidth)/CalPanoPostProcPara.QuickViewPanoImageWidth;
                    JpegWrapper.srcWindow.y = (pCalPanoEncodePara->QuickviewRoiY*JpegWrapper.srcHeight)/CalPanoPostProcPara.QuickViewPanoImageHeight;
                    JpegWrapper.srcWindow.w = (pCalPanoEncodePara->QuickviewRoiWidth*JpegWrapper.srcWidth)/CalPanoPostProcPara.QuickViewPanoImageWidth;
                    JpegWrapper.srcWindow.h = (pCalPanoEncodePara->QuickviewRoiHeight*JpegWrapper.srcHeight)/CalPanoPostProcPara.QuickViewPanoImageHeight;
                    //Force width & height as an even number
                    JpegWrapper.srcWindow.x &= ~0x00000001;
                    JpegWrapper.srcWindow.y &= ~0x00000001;
                    JpegWrapper.srcWindow.w &= ~0x00000001;
                    JpegWrapper.srcWindow.h &= ~0x00000001;

                #if defined(MT6255)||defined(MT6250)||defined(MT6260)
                    //Force width & height as 16x number (Hybrid JPEG encoder limitation)
                    CalJpegCropWindow(KAL_TRUE);
                    JpegWrapper.srcWindow.x = 0;
                    JpegWrapper.srcWindow.y = 0;
                    JpegWrapper.srcWindow.w=JpegWrapper.dstWidth;
                    JpegWrapper.srcWindow.h=JpegWrapper.dstHeight;
                #endif

                    JpegWrapper.dstWidth=JpegWrapper.srcWindow.w;
                    JpegWrapper.dstHeight=JpegWrapper.srcWindow.h;

                    if(JpegWrapper.srcWindow.w*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight>=
                            JpegWrapper.srcWindow.h*CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth)
                    {
                        CalPanoPostProcPara.ImageAlignmentHandle=KAL_FALSE;
                    }
                    else
                    {
                        CalPanoPostProcPara.ImageAlignmentHandle=KAL_TRUE;
                    }

                    if(CalPanoPostProcPara.ImageAlignmentHandle)    //Vertical stitch
                    {
                        if(JpegWrapper.srcWindow.h>CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight)
                        {
                            CalPanoPostProcPara.QuickViewPanoImageHeight=CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight;
                            CalPanoPostProcPara.QuickViewPanoImageWidth=(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight*JpegWrapper.srcWindow.w)/JpegWrapper.srcWindow.h;
                        }
                        else
                        {
                            CalPanoPostProcPara.QuickViewPanoImageHeight=JpegWrapper.srcWindow.h;
                            CalPanoPostProcPara.QuickViewPanoImageWidth=JpegWrapper.srcWindow.w;
                        }
                    }
                    else    //Horizontal stitch
                    {
                        if(JpegWrapper.srcWindow.w>CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth)
                        {
                            CalPanoPostProcPara.QuickViewPanoImageWidth=CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth;
                            CalPanoPostProcPara.QuickViewPanoImageHeight=(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*JpegWrapper.srcWindow.h)/JpegWrapper.srcWindow.w;
                        }
                        else
                        {
                            CalPanoPostProcPara.QuickViewPanoImageWidth=JpegWrapper.srcWindow.w;
                            CalPanoPostProcPara.QuickViewPanoImageHeight=JpegWrapper.srcWindow.h;
                        }
                    }
                }
                else
                {
                    if(CalPanoPostProcPara.ImageAlignmentHandle)    //Vertical stitch
                    {
                        CalPanoPostProcPara.QuickViewPanoImageHeight=CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight;
                        CalPanoPostProcPara.QuickViewPanoImageWidth=(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageHeight*JpegWrapper.dstWidth)/JpegWrapper.dstHeight;
                    }
                    else    //Horizontal stitch
                    {
                        CalPanoPostProcPara.QuickViewPanoImageWidth=CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth;
                        CalPanoPostProcPara.QuickViewPanoImageHeight=(CalPanoPostProcPara.CalMdpPostProcPara.QuickViewImageWidth*JpegWrapper.dstHeight)/JpegWrapper.dstWidth;
                    }
                    JpegWrapper.srcWindow.x=0;
                    JpegWrapper.srcWindow.y=0;
                #if defined(MT6255)||defined(MT6250)||defined(MT6260)
                    CalJpegCropWindow(KAL_FALSE);
                #endif
                    JpegWrapper.srcWindow.w=JpegWrapper.dstWidth;
                    JpegWrapper.srcWindow.h=JpegWrapper.dstHeight;
                }
                tmpIspUpdateExifInfo.ImageTargetWidth = JpegWrapper.dstWidth;
                tmpIspUpdateExifInfo.ImageTargetHeight = JpegWrapper.dstHeight;
                tmpIspUpdateExifInfo.StillImageExifOrientation=1;
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_UPDATE_EXIF_INFO, (void *) &tmpIspUpdateExifInfo, NULL, 0, &FeatureOutLen);

                CalPanoPostProcPara.JaiaQviBufAligned=pCalPanoEncodePara->IsJaiaQviBufAligned;

                LocalPara.pJpegWrapperPara = &JpegWrapper;
            #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
                if (KAL_TRUE==IsHwJpegEncSupport)
                    SendMsgToCal(MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ, &LocalPara);
                else
            #endif
                    SendMsgToCal(MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ, &LocalPara);

                CalPanoState=CAL_PANO_ENCODING_STATE;
            break;
        #endif /* defined(__AUTOCAP_PANORAMA_SUPPORT__) */
    #endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__
        #if defined(__SMILE_SHUTTER_SUPPORT__)
            case CAL_FEATURE_CAMERA_SMILE_DETECT_START:
                    if (KAL_TRUE == pFeatureIn->FeatureSetValue)
                    {
                /* set env info */
                pPpFeatureMemPara->PostProcMode = PP_MODE_SMILE_DETECT;
                pPpFeatureMemPara->ImgWidth = CalPreviewInfo.DisplayImageWidth;
                pPpFeatureMemPara->ImgHeight = CalPreviewInfo.DisplayImageHeight;
                PpFeaturePara.pConfigInfo = pPpFeatureMemPara;
                PpFeatureCtrl(PP_FUNC_ALL, PP_FEATURE_SET_ENV_INFO,&PpFeaturePara, 0, 0);
                }
                else
                {
                    PpFeatureCtrl(PP_FUNC_SMILE_DETECT, PP_FEATURE_SET_DISABLE, 0, 0, 0);
                }
            break;
        #endif /* defined(__SMILE_SHUTTER_SUPPORT__) */

    #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
            case CAL_FEATURE_CAMERA_HDR_CAPTURE_ABORT:
                IsHdrAborted=KAL_TRUE;
                if (CAL_HDR_CORE_STATE == CalHdrState)
                {
                    PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_STOP, 0, 0, 0);
                    kal_sleep_task(5);
                }
                else if (CAL_HDR_ENCODED_STATE != CalHdrState)
                {
                    kal_set_eg_events(CalEventId,0,KAL_AND);
                    kal_retrieve_eg_events(CalEventId,CAL_PP_ABORT_DONE_EVENT, KAL_OR_CONSUME,&EventGroup,KAL_SUSPEND);
                    PpCtrl(PP_SCENARIO_POSTPROC, PP_CTRL_CODE_STOP, 0, 0, 0);
                }
            break;
    #endif //__HIGH_DYNAMIC_RANGE_SUPPORT__

        #ifdef __CAL_CAMERA_AF_SUPPORT__
            case CAL_FEATURE_CAMERA_GET_AF_ZONE:
                ErrorCode=pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
            break;
        #endif
        #if defined(__COMPOSITE_WEBCAM__)
            case CAL_FEATURE_CAMERA_TUNING_SENSOR:
                at_string = (char *)(pFeatureIn->FeatureSetValue);
                //Parse the AT Command
                while ((at_string[at_data_index] != '=' ) &&  //AT+SENSOR=XXXXXXXX
                       at_data_index < strlen(at_string))
                {
                    at_data_index++;
                }
                at_string = at_string + at_data_index+1;
                at_data_index=0;
                while (at_string)
                  {
                    at_data[at_data_index] = strtoul(at_string,&at_string,0);
                      if (','== *at_string)
                      {
                        at_string++;
                        at_data_index++;
                      }
                      else
                    {
                       break;
                    }
                  }
                  if (pfImageSensor && ((CalState == CAL_CAMERA_PREVIEW_STATE)||(CalState == CAL_WEBCAM_PREVIEW_STATE)))// && at_data_index>0)
                  {
                    switch (at_data[0])
                    {
                        //Get Sensor info
                        case 0:
                            ErrorCode=pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_DATA_INFO,NULL,&SensorRegWidth,FeatureOutLen,NULL);
                            sprintf(buffer, "+SENSOR: %d, %d",SensorRegWidth.AddrWidth,SensorRegWidth.ParaWidth);
                            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
                        break;
                        //Read sensor register
                        case 1:
                            SensorReg.RegNum = 1;
                            SensorReg.pRegAddr = &at_data[1];                                           //Register Address
                            SensorReg.pRegData = &RegData;                        //Register Value
                            ErrorCode=pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_REGISTER,&SensorReg,&SensorReg,FeatureOutLen,NULL);
                            sprintf(buffer, "+SENSOR: 0x%X",RegData);
                            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
                        break;
                        //Write sensor register
                        case 2:
                            SensorReg.RegNum = 1;
                            SensorReg.pRegAddr = &at_data[1];                                           //Register Address
                            SensorReg.pRegData = &at_data[2];                                           //Register Value
                            ErrorCode=pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_REGISTER,&SensorReg,&SensorReg,FeatureOutLen,NULL);
                            sprintf(buffer, "+SENSOR: 0x%X",at_data[2]);
                            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
                        break;
                        defult:
                        break;
                    }
                    sprintf(buffer, "OK");
                    rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
                }
                break;
        #endif
        #ifdef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
            case CAL_FEATURE_CAMERA_GET_PREVIEW_IMAGE:
                kal_mem_cpy(&CamPreviewImageInfo, pFeatureIn->FeatureInfo.FeatureStructured.pCamGetPreviewImageInPara, sizeof(CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT));
                if (pFeatureIn->FeatureInfo.FeatureStructured.pCamGetPreviewImageInPara->ImageRotAngle & 0x01)
                {
                    CamPreviewImageInfo.ImageWidth=pFeatureIn->FeatureInfo.FeatureStructured.pCamGetPreviewImageInPara->ImageHeight;
                    CamPreviewImageInfo.ImageHeight=pFeatureIn->FeatureInfo.FeatureStructured.pCamGetPreviewImageInPara->ImageWidth;
                }
                kal_set_eg_events(CalEventId,0,KAL_AND);
                GetPreviewImageEnable=KAL_TRUE;
                kal_retrieve_eg_events(CalEventId,CAL_GET_PREVIEW_IMAGE_EVENT, KAL_OR_CONSUME,&EventGroup,KAL_SUSPEND);
            break;
        #endif
            case CAL_FEATURE_CAMERA_GET_JPEG_SIZE_ESTIMATION:
                if (CAL_FEATURE_GET_OPERATION==pFeatureIn->FeatureCtrlCode)
                {
//                    jpeg_wrapper_query_dst_buffer_size((kal_uint32 *) &(pFeatureOut->FeatureCurrentValue),
//                                                       pFeatureIn->FeatureInfo.FeatureStructured.pGetJpegSizeEstimationPara->JpegEncQuality,
//                                                       GetJpegWrapperFormat(pFeatureIn->FeatureInfo.FeatureStructured.pGetJpegSizeEstimationPara->JpegSamplingFormat),
//                                                       pFeatureIn->FeatureInfo.FeatureStructured.pGetJpegSizeEstimationPara->ImageWidth,
//                                                       pFeatureIn->FeatureInfo.FeatureStructured.pGetJpegSizeEstimationPara->ImageHeight);
                    jpeg_wrapper_query_dst_buffer_size((kal_uint32 *) &(pFeatureOut->FeatureCurrentValue),
                                                       pGetJpegSize->JpegEncQuality,
                                                       GetJpegWrapperFormat(pGetJpegSize->JpegSamplingFormat),
                                                       pGetJpegSize->ImageWidth, pGetJpegSize->ImageHeight);

                }
            break;
            case CAL_FEATUER_CAMERA_CAPTURE_OVERLAY_CAPABILITY:
                if (CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode)
                {
                #ifdef __CAL_CAMERA_OVERLAY_SUPPORT__
                    if (IMAGE_SENSOR_DATA_OUT_FORMAT_JPEG==CurrentSensorInfo.CaptureDataFormat)
                        pFeatureOut->FeatureInfo.FeatureStructured.pCamOverlayCap->CaptureOverlaySupport=KAL_FALSE;
                    else
                        pFeatureOut->FeatureInfo.FeatureStructured.pCamOverlayCap->CaptureOverlaySupport=KAL_TRUE;
                #else
                    pFeatureOut->FeatureInfo.FeatureStructured.pCamOverlayCap->CaptureOverlaySupport=KAL_FALSE;
                #endif
                }
            break;
            case CAL_FEATURE_CAMERA_QUERY_SW_ROTATE:
            #ifdef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
                if (CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode)
                    pFeatureOut->FeatureInfo.FeatureStructured.pCamSwRotOutPara->RequireSwRotate=CalImageSwRotateDetect(pFeatureIn->FeatureInfo.FeatureStructured.pCamSwRotInPara);
            #else
                if (CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode)
                    pFeatureOut->FeatureInfo.FeatureStructured.pCamSwRotOutPara->RequireSwRotate=KAL_FALSE;
            #endif
            break;
            case CAL_FEATURE_CAMERA_PREVIEW_POSTPROC_PAUSE:
            #if (defined(__POSTPROC_SUPPORT__))
                gCalPreviewPostProcPaused = KAL_TRUE;
                FaceInfo.FaceNo = 0;
                FaceInfo.FaceLum = 0;
                FaceInfo.FdEnable = KAL_TRUE;
                FaceInfo.SdEnable = KAL_FALSE;
                FaceInfo.ImgSrcWidth = 160; /* to avoid divide by zero */
                FaceInfo.ImgSrcHeight = 120;
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_FACE_INFO, (void *) &FaceInfo, NULL, 0, &FeatureOutLen);
            #endif  /* defined(__POSTPROC_SUPPORT__) */
            break;
            case CAL_FEATURE_CAMERA_PREVIEW_POSTPROC_RESUME:
            #if (defined(__POSTPROC_SUPPORT__))
                gCalPreviewPostProcPaused = KAL_FALSE;
            #endif  /* defined(__POSTPROC_SUPPORT__) */
            break;
        #ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
            case CAL_FEATURE_CAMERA_SET_VIDEO_ROT_ANGLE:
                if (CAL_SCENARIO_VIDEO_MJPEG!=CurrentScenarioId)
                {
                    switch (SensorScenarioParaIn.ImageMirror)
                    {
                        case IMAGE_SENSOR_MIRROR_NORMAL:
                            CalVideoInfo.VideoImageRotAngle=(MM_IMAGE_ROTATE_ENUM) pFeatureIn->FeatureSetValue;
                        break;
                        case IMAGE_SENSOR_MIRROR_HV:
                            CalVideoInfo.VideoImageRotAngle=GetRestRotAngle((MM_IMAGE_ROTATE_ENUM) pFeatureIn->FeatureSetValue, MM_IMAGE_ROTATE_180);
                        break;
                        case IMAGE_SENSOR_MIRROR_H:
                            CalVideoInfo.VideoImageRotAngle=GetRestRotAngle((MM_IMAGE_ROTATE_ENUM) pFeatureIn->FeatureSetValue, MM_IMAGE_H_MIRROR);
                        break;
                        case IMAGE_SENSOR_MIRROR_V:
                            CalVideoInfo.VideoImageRotAngle=GetRestRotAngle((MM_IMAGE_ROTATE_ENUM) pFeatureIn->FeatureSetValue, MM_IMAGE_H_MIRROR_ROTATE_180);
                        break;
                    }

                    MdpCapQueryPara.ePath=IDP_CAL_QUERY_ARG_POSTPROC_PATH;
                    MdpCapQueryPara.eDesiredAngle=(img_rot_angle_enum_t)CalVideoInfo.VideoImageRotAngle;
                    MdpCapQueryPara.eRotateWidth=CalVideoInfo.VideoImageWidth;
                    MdpFunc.pfnIdpCalQuery(CurrentScenarioId, IdpCalKey, IDP_CAL_QUERY_ROT_CAP, &MdpCapQueryPara, &MdpCapQueryResult);

                    if (MdpCapQueryResult == CalVideoInfo.VideoImageRotAngle)
                    {   // notify MDP new video rotate angle
                        CalVideoInfo.VideoImageRotAngle = MM_IMAGE_ROTATE_0;
                    }
                    else
                    {   // notify MDP do not roate video image, SW will roate the video image
                        SwVideoRotAngle = CalVideoInfo.VideoImageRotAngle;
                        MdpCapQueryResult=MM_IMAGE_ROTATE_0;
                    }
                    MdpFunc.pfnIdpCalSet(CurrentScenarioId, IdpCalKey, IDP_CAL_SET_ENCODE_ROTATION, &MdpCapQueryResult);

                    if (MM_IMAGE_ROTATE_0!=CalVideoInfo.VideoImageRotAngle)
                    {
                        VideoRotBuffAddr = (kal_uint32) CalVideoInfo.pfGetVideoBuff().pu1Address;
                    }
                }
            break;
        #endif
            case CAL_FEATURE_CAMERA_EXTRA_QVI_BUF_ADDR:
                CalExtraQVIBuffAddr = pFeatureIn->FeatureSetValue;
            break;
            case CAL_FEATURE_CAMERA_EXTRA_QVI_BUF_SIZE:
                CalExtraQVIBuffSize = pFeatureIn->FeatureSetValue;
            break;
            case CAL_FEATURE_CAMERA_JAIA_DISABLE:
                CalStillCaptureInfo.ImageJaiaDisable = (kal_bool) pFeatureIn->FeatureSetValue;
            break;
        #if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
            case CAL_FEATURE_CAMERA_SENOSR_OUTPUT_TEST_PATTERN:
            {
                IMAGE_SENSOR_COMM_DATA_STRUCT SensorCommData;
                
                SensorCommData.FeatureValue = pFeatureIn->FeatureSetValue;
                ErrorCode = pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, &SensorCommData, NULL, 0, NULL);                        
                break;
            }

            case CAL_FEATURE_CAMERA_GET_TEST_PATTERN:
            {
                IMAGE_SENSOR_COMM_DATA_STRUCT SensorCommData;

                ErrorCode = pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, NULL, &SensorCommData, 0, NULL);
                pFeatureOut->FeatureCurrentValue = SensorCommData.FeatureValue;
                break;
            }
        #endif
            default:
                {   // YUV sensor, pass the features to sensor driver.
                    if((pFeatureOut!=NULL) && (CAL_FEATURE_QUERY_OPERATION == pFeatureIn->FeatureCtrlCode))
                    {
                        pCamFeatureEnum->IsSupport = KAL_FALSE;//default value
                    }

                    switch (pFeatureIn->FeatureId)
                    {
                        case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
                            if(CAL_FEATURE_QUERY_OPERATION == pFeatureIn->FeatureCtrlCode)
                            {
                                ErrorCode= pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
                                #if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
                                /* only support in camera mode */
                                if (CAL_CAMERA_MODE_CAMERA == pFeatureIn->CameraMode)
                                {
                                    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Effect = &pFeatureOut->FeatureInfo.FeatureEnum;
                                    pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
                                    Effect->IsSupport = KAL_TRUE;
                                    Effect->SupportItem[Effect->ItemCount] = CAM_EFFECT_ENC_LOMO;
                                    Effect->SupportItem[Effect->ItemCount+1] = CAM_EFFECT_ENC_COLOR_RED;
                                    Effect->SupportItem[Effect->ItemCount+2] = CAM_EFFECT_ENC_COLOR_YELLOW;
                                    Effect->SupportItem[Effect->ItemCount+3] = CAM_EFFECT_ENC_COLOR_GREEN;
                                    Effect->SupportItem[Effect->ItemCount+4] = CAM_EFFECT_ENC_COLOR_BLUE;
                                    Effect->ItemCount += 5;
                                }
                                #endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */
                            }
                            else
                            {
                                #if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
                                CalImageEffect = pFeatureIn->FeatureSetValue;
                                if (pFeatureIn->FeatureSetValue >= CAM_EFFECT_ENC_LOMO)
                                {   /* reset image effect to normal for sensor */
                                    pFeatureIn->FeatureSetValue = CAM_EFFECT_ENC_NORMAL;
                                }
                                #endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */
                                ErrorCode=pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
                            }
                            break;
                        case CAL_FEATURE_CAMERA_CONTRAST:
                        case CAL_FEATURE_CAMERA_SATURATION:
                        case CAL_FEATURE_CAMERA_SHARPNESS:
                        case CAL_FEATURE_CAMERA_WB:
                        case CAL_FEATURE_CAMERA_EV_VALUE:
                        case CAL_FEATURE_CAMERA_FLASH_MODE:
                        case CAL_FEATURE_CAMERA_BANDING_FREQ:
                        case CAL_FEATURE_CAMERA_AE_METERING_MODE:
                        case CAL_FEATURE_CAMERA_SCENE_MODE:
                        case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
                            if(CAL_FEATURE_QUERY_OPERATION == pFeatureIn->FeatureCtrlCode)
                                ErrorCode= pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
                            else
                                ErrorCode=pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
                        break;
                    #if(defined(__CAL_CAMERA_AF_SUPPORT__))
                        //pass the AF features to sensor driver via ISP
                        case CAL_FEATURE_CAMERA_AF_KEY:
                        case CAL_FEATURE_CAMERA_AF_OPERATION_MODE:
                        case CAL_FEATURE_CAMERA_AF_RANGE_CONTROL:
                            ErrorCode= pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
                        break;
                    #endif
                        default:
                            ErrorCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
                        break;
                    }
                    #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
                    if (CAL_FEATURE_SET_OPERATION == pFeatureIn->FeatureCtrlCode)
                        CalMavImageSetting(pFeatureIn->FeatureId, pFeatureIn->FeatureSetValue);
                    #endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */
                }
            break;
        }
    }

#ifdef WEBCAM_SUPPORT
    else if ((pFeatureIn->FeatureId>CAL_FEATURE_WEBCAM_BEGIN)&&
             (pFeatureIn->FeatureId<CAL_FEATURE_WEBCAM_END))
    {
        CalTrace(CAL_TRACE_FLOW,CAL_FLOW_WEBCAM_FEATURE_CTRL,CAL_FEATURE_CTRL,pFeatureIn->FeatureId,pFeatureIn->FeatureCtrlCode);
        ErrorCode=CalWebcamFeatureCtrl(pFeatureIn, pFeatureOut, FeatureOutLen);
    }
#endif
#ifdef __CAL_PROFILING_ENABLE__
    else if ((pFeatureIn->FeatureId>CAL_FEATURE_CAMERA_PROFILING_BEGIN)&&
             (pFeatureIn->FeatureId<CAL_FEATURE_CAMERA_PROFILING_END))
    {
        CalTrace(CAL_TRACE_FLOW,CAL_FLOW_PROFILING_FEATURE_CTRL,CAL_FEATURE_CTRL,pFeatureIn->FeatureId,pFeatureIn->FeatureCtrlCode);
        ErrorCode=CalProfilingFeatureCtrl(pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
    }
#endif
    return ErrorCode;
} /* CalFeatureCtrl() */

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif


