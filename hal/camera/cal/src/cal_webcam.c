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
*   cal_webcam.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "cal_drv_features.h"
#include "cal_task_msg_if.h"

#include "sensor_comm_def.h"
#include "isp_if.h"

#include "isp_comm_if.h"
#include "cal_mem_def.h"

#ifdef WEBCAM_SUPPORT

CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT CalWebcamVideoSize;    ///will init in CalFeatureContrl   CAMERA_SELECT
CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT CalWebcamStillSize;
CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT CalWebcamCompression;

CAL_CAMERA_WEBCAM_PROCESS_STRUCT CalWebcamProcessStruct;
ISP_CAMERA_STILL_CAPTURE_STRUCT CalWebcamIspCapturePara;
CAL_WEBCAM_CB_STRUCT CalWebcamCbStruct;

CAL_ISP_STILL_CAPTURE_STRUCT CalWebcamStillCapturePara;

extern CAL_STATE_ENUM CalState;
extern P_ISP_SCENARIO_CTRL_STRUCT pIspScenarioCtrl;
extern P_ISP_FEATURE_GET_OUTPUT_RESOLUTION_IN_STRUCT pIspGetOutResParaIn;
extern P_ISP_FEATURE_GET_OUTPUT_RESOLUTION_OUT_STRUCT pIspGetOutResParaOut;
extern IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT SensorScenarioParaIn;
extern IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT SensorScenarioParaOut;
extern ISP_FEATURE_CURRENT_ZOOM_INFO_STRUCT CurrentZoomInfo;
//extern ISP_FEATURE_SET_TG_STRUCT IspTgSettingInfo;

// JPEG Encoder
extern JPEG_ENCODER_HANDLE JpegWrapperHandle;
extern JPEG_WRAPPER JpegWrapper;
extern kal_uint8 *pJpegEncodedDataAddr;
extern kal_uint32 JpegEncodedDataSize;

// MDP
extern kal_uint32 IdpCalKey;
extern Camera_Capture_Idp_Cal_Struct MdpStillCapturePara;

static kal_uint32 CalWebcamTargetWidthBackup = 0;
static kal_uint32 CalWebcamTargetHeightBackup = 0;
static kal_bool CalWebcamRecaptureFlag=KAL_FALSE;
static kal_mutexid CalWebcamMutex = NULL;           


IMAGE_SENSOR_MIRROR_ENUM CalWebcamRotateMap[8] =
{
    IMAGE_SENSOR_MIRROR_NORMAL,       //MM_IMAGE_ROTATE_0,
    IMAGE_SENSOR_MIRROR_NORMAL,       //MM_IMAGE_ROTATE_90,
    IMAGE_SENSOR_MIRROR_HV,           //MM_IMAGE_ROTATE_180,
    IMAGE_SENSOR_MIRROR_NORMAL,       //MM_IMAGE_ROTATE_270,
    IMAGE_SENSOR_MIRROR_H,            //MM_IMAGE_H_MIRROR,
    IMAGE_SENSOR_MIRROR_NORMAL,       //MM_IMAGE_H_MIRROR_ROTATE_90,
    IMAGE_SENSOR_MIRROR_V,            //MM_IMAGE_H_MIRROR_ROTATE_180,
    IMAGE_SENSOR_MIRROR_NORMAL        //MM_IMAGE_H_MIRROR_ROTATE_270
};
void CalWebcamInit(void)
{
    if(CalWebcamMutex == NULL)
    {
        CalWebcamMutex = kal_create_mutex("WEBCAM_MUTEX");   
        ASSERT(CalWebcamMutex != NULL);
    }

    CalWebcamTargetWidthBackup = 0;
    CalWebcamTargetHeightBackup = 0;
    CalWebcamRecaptureFlag = KAL_FALSE;
}


/////////////////////////
MM_ERROR_CODE_ENUM CalWebcamCaptureNextFrame()
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    CAL_SCENARIO_ENUM ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;

    if(CalState == CAL_WEBCAM_PREVIEW_STATE)
    {
        ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
    }
    else if(CalState == CAL_WEBCAM_CAPTURE_STATE)
    {
        ScenarioId = CAL_SCENARIO_WEBCAM_CAPTURE;
    }
    else
    {
        EXT_ASSERT(0, CalState, 0, 0);
    }
    CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_CAPTURENEXT,ScenarioId);
    /* stop isp engine */
    pIspScenarioCtrl=(P_ISP_SCENARIO_CTRL_STRUCT) CalFeatureCtrlBuff1;
    pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
    ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, NULL);

    /* stop idp */
    MdpFunc.pfnIdpCalStop(CAL_SCENARIO_CAMERA_STILL_CAPTURE, IdpCalKey);

    /* update dst buffer address */
    JpegWrapper.dstBufferAddr = (void *) CalWebcamCbStruct.BuffAddr;

#ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
    /* start jpeg driver */
    if(IsHwJpegEncSupport)       /// for HW JPEG Encoder platform
    {
        jpegEncReset(JpegWrapperHandle);  
        jpeg_wrapper_start(JpegWrapperHandle, &JpegWrapper);
    }
#endif

    /* start idp driver */
    /// Bin: for MDP upscale case, maybe MDP uses two path case, which need to close and reopen MDP
    ErrorCode = MdpFunc.pfnIdpCalClose(CAL_SCENARIO_CAMERA_STILL_CAPTURE, IdpCalKey);
    ErrorCode = MdpFunc.pfnIdpCalOpen( CAL_SCENARIO_CAMERA_STILL_CAPTURE, &IdpCalKey, NULL, 0);
    ErrorCode = MdpFunc.pfnIdpCalSet( CAL_SCENARIO_CAMERA_STILL_CAPTURE, IdpCalKey, IDP_CAL_SET_CONFIG, &MdpStillCapturePara);
    MdpFunc.pfnIdpCalStart(CAL_SCENARIO_CAMERA_STILL_CAPTURE, IdpCalKey);

    /* update attribute */
    // IspWebcamUpdateAttrSetting();       ///Bin: not necessary for each frame to update

    /* start isp engine */
    pIspScenarioCtrl=(P_ISP_SCENARIO_CTRL_STRUCT) CalFeatureCtrlBuff1;
    pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_START;
    pIspScenarioCtrl->pScenarioCtrlPara=&CalWebcamIspCapturePara;
    CalWebcamIspCapturePara.pCalIspCapturePara=&CalWebcamStillCapturePara;
    ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, NULL);

    return ErrorCode;
}

kal_int32 CalWebcamCallback(kal_uint32 return_code)  
{
    JPEG_STATUS_ENUM status = (JPEG_STATUS_ENUM)return_code;

    CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_CBF,drv_get_current_time());
    if( (CalState == CAL_IDLE_STATE) || (CalState == CAL_STANDBY_STATE))    ///state maybe changed in STOP control code
    {
        CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_ERROR,MM_ERROR_CAL_INVALID_STATE);
        return 0;  
    }

    kal_take_mutex(CalWebcamMutex); ///enter critical section

    if(!IsHwJpegEncSupport)      ///For SW JPEG Encode platform
    {
        status = jpeg_wrapper_start(JpegWrapperHandle, &JpegWrapper);
    }

    status = jpeg_wrapper_get_encoded_data(JpegWrapperHandle, &pJpegEncodedDataAddr, &JpegEncodedDataSize);

    /// Bin: MAUI_02865674, cover HW JPEG Encoder 8-byte align limitation
    if(status == JPEG_STATUS_OK)
    {
        if(((kal_uint32)(pJpegEncodedDataAddr)) != (CalWebcamCbStruct.BuffAddr))
        {
            kal_uint32 offset = (kal_uint32)(pJpegEncodedDataAddr) - (kal_uint32)(CalWebcamCbStruct.BuffAddr);
            kal_uint8  *pAddr = (kal_uint8 *)(CalWebcamCbStruct.BuffAddr);
            
            ASSERT(((kal_uint32)(pJpegEncodedDataAddr)) > (CalWebcamCbStruct.BuffAddr));

            JpegEncodedDataSize += offset;

            *pAddr = 0xFF;                  ///fill header
            *(pAddr+1) = 0xD8;

            while(offset>0)
            {
                *(pAddr+1+offset) = 0xFF;   ///dummy data
                offset--;
            }
        }
    }
    //////////////////////////////////////////////////////////////
    CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_CBF_BUF,JpegEncodedDataSize);

    /* IDP busy checking */
    #if 0   
/* under construction !*/
    #endif

    CalWebcamCbStruct.BuffSize = JpegEncodedDataSize;
    CalWebcamCbStruct.VideoTime = 0;  //TODO: HAL GPT_return_current_count();
    CalWebcamCbStruct.VideoType = CalWebcamProcessStruct.TargetSize;

    if(JPEG_STATUS_OK == status)
    {
        if(CalState == CAL_WEBCAM_PREVIEW_STATE)
        {
            pfCalCallback(CAL_CBID_WEBCAM_COMPLETE_VIDEO_BUFF, &CalWebcamCbStruct, sizeof(CAL_WEBCAM_CB_STRUCT));
        }
        else if(CalState == CAL_WEBCAM_CAPTURE_STATE)
        {
            pfCalCallback(CAL_CBID_WEBCAM_COMPLETE_STILL_BUFF, &CalWebcamCbStruct, sizeof(CAL_WEBCAM_CB_STRUCT));
        }
        CalWebcamRecaptureFlag = KAL_FALSE;
    } 
    else if(JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY == status)    ///bitstream buffer is not enough
    {
        CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_ERROR,MM_ERROR_OUT_OF_MEMORY);
        JpegWrapper.dstQuality = JPEG_ENCODE_QUALITY_POOR;      /// Force to use the poor encode quality
        CalWebcamRecaptureFlag = KAL_TRUE;                      ///need recapture
    }
    else
    {
        EXT_ASSERT(0, status, 0, 0);        /// error handling for JPEG encode fail ??
    }

    /* GetNext */
    if(CalState == CAL_WEBCAM_PREVIEW_STATE)
    {
        /* Get Next USB Video Buffer */
        if(CalWebcamRecaptureFlag == KAL_FALSE)
        {
            pfCalCallback(CAL_CBID_WEBCAM_GET_VIDEO_BUFF, &CalWebcamCbStruct, sizeof(CAL_WEBCAM_CB_STRUCT));
        }

        if(CalWebcamCbStruct.BuffAddr != NULL)  /// may get NULL from USB, because USB may stop before camera, therefore just do nothing to wait for MED stop 
        {   
            CalWebcamCaptureNextFrame();
        }   
        else
        {
            CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_ERROR,MM_ERROR_CAL_STILL_CATPURE_OUT_OF_MEMORY);
        }
    }
    else if(CalState == CAL_WEBCAM_CAPTURE_STATE && CalWebcamRecaptureFlag == KAL_TRUE)
    {
        CalWebcamCaptureNextFrame();
    }

    kal_give_mutex(CalWebcamMutex);             /// release mutex to exit critical section

    return 0;
}


//////////callback for CRZ HISR ////////////////
kal_int32 CalWebcamSendFrameReadyRequest(JPEG_CODEC_STATE_ENUM return_code)
{
    CAL_WEBCAM_FRAME_READY_REQ_STRUCT LocalPara;

    if( (CalState == CAL_IDLE_STATE) || (CalState == CAL_STANDBY_STATE)) 
    {
        CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_ERROR,MM_ERROR_CAL_INVALID_STATE);
        return 0;  
    }

    /// send message to CAL task
    LocalPara.Param = return_code;
    SendMsgToCal(MSG_ID_CAL_WEBCAM_FRAME_READY_REQ, &LocalPara);

    CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_ENCODEREQ,return_code);
    return 0;
}



/////////////////CAL Feature Control For Webcam///////////////////
MM_ERROR_CODE_ENUM CalWebcamFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureOut, kal_uint32 FeatureOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    kal_uint32 OutParaLen;

    CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_FEATURE_CTL,pFeatureIn->FeatureId);
    switch (pFeatureIn->FeatureId)
    {
        case CAL_FEATURE_WEBCAM_GET_ATTR:  
            ErrorCode = pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, NULL, (pFeatureIn->FeatureInfo).FeatureStructured.pWebCamAttr, sizeof(USBVideo_Attr_Value), &OutParaLen);
            break;

        case CAL_FEATURE_WEBCAM_SET_ATTR: 
            ErrorCode = pfIspFunc->IspFeatureCtrl(pFeatureIn->FeatureId, (pFeatureIn->FeatureInfo).FeatureStructured.pWebCamAttr, NULL, 0, NULL);
            break;

        case CAL_FEATURE_WEBCAM_GET_ATTR_INFO:
            ErrorCode = pfImageSensor->SensorFeatureCtrl((IMAGE_SENSOR_FEATURE_ENUM)(pFeatureIn->FeatureId), NULL,(pFeatureIn->FeatureInfo).FeatureStructured.pWebCamAttrInfo, sizeof(CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT), &OutParaLen);
            break;

        case CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE:
            ErrorCode = pfImageSensor->SensorFeatureCtrl((IMAGE_SENSOR_FEATURE_ENUM)(pFeatureIn->FeatureId), NULL, (pFeatureIn->FeatureInfo).FeatureStructured.pWebCamVideoSize, sizeof(CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT), &OutParaLen);
            break;

        case CAL_FEATURE_WEBCAM_GET_STILL_SIZE:
            ErrorCode = pfImageSensor->SensorFeatureCtrl((IMAGE_SENSOR_FEATURE_ENUM)(pFeatureIn->FeatureId), NULL, (pFeatureIn->FeatureInfo).FeatureStructured.pWebCamStillSize, sizeof(CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT), &OutParaLen);
            break;

        case CAL_FEATURE_WEBCAM_GET_COMPRESSION:
            ErrorCode = pfImageSensor->SensorFeatureCtrl((IMAGE_SENSOR_FEATURE_ENUM)(pFeatureIn->FeatureId), NULL, (pFeatureIn->FeatureInfo).FeatureStructured.pWebCamCompression, sizeof(CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT), &OutParaLen);
            break;

        case CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX:
            ErrorCode = pfImageSensor->SensorFeatureCtrl((IMAGE_SENSOR_FEATURE_ENUM)(pFeatureIn->FeatureId), NULL, (pFeatureIn->FeatureInfo).FeatureStructured.pWebCamDeafultIdx, sizeof(CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT), &OutParaLen);
            break;

        default:
            ASSERT(0);
            break;
    }
    return ErrorCode;

}


MM_ERROR_CODE_ENUM CalWebcamCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_CAL_CAMERA_WEBCAM_PROCESS_STRUCT pCalWebcamPara = (P_CAL_CAMERA_WEBCAM_PROCESS_STRUCT) pCtrlPara;
    kal_uint32 OutParaLen;
    ISP_FEATURE_SET_TG_STRUCT IspTgSettingInfo;

    CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_CTL,ScenarioId,CtrlCode);
    if (CAL_CTRL_CODE_STOP & CtrlCode)
    {
        kal_bool    RunningFlag = KAL_FALSE;
        kal_uint32  SavedIrqMask;   


        /* state change */  
        SavedIrqMask=SaveAndSetIRQMask();  
        if (CalState == CAL_WEBCAM_PREVIEW_STATE || CalState == CAL_WEBCAM_CAPTURE_STATE)
        { 
            CalState = CAL_STANDBY_STATE;
            RunningFlag = KAL_TRUE;
        }
        RestoreIRQMask(SavedIrqMask);

        if(RunningFlag == KAL_TRUE)   
        {
            kal_take_mutex(CalWebcamMutex); ///enter critical section

            /* IDP error check */
            #if 0   
/* under construction !*/
            #endif

            /* stop isp engine */
            pIspScenarioCtrl=(P_ISP_SCENARIO_CTRL_STRUCT) CalFeatureCtrlBuff1;
            pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
            ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, NULL);
            pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_DEINIT;
            ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, NULL);

            /* stop idp */
            MdpFunc.pfnIdpCalStop(CAL_SCENARIO_CAMERA_STILL_CAPTURE, IdpCalKey);
            MdpFunc.pfnIdpCalClose(CAL_SCENARIO_CAMERA_STILL_CAPTURE, IdpCalKey);

            /* stop jpeg driver */
        #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
            if(IsHwJpegEncSupport)       /// for HW JPEG Encoder platform
            {
                jpeg_wrapper_get_encoded_data(JpegWrapperHandle, &pJpegEncodedDataAddr, &JpegEncodedDataSize);
            }
        #endif
            jpeg_wrapper_close(JpegWrapperHandle);  

            kal_give_mutex(CalWebcamMutex); ///leave critical section
        }

        CalWebcamRecaptureFlag = KAL_FALSE;


    }

    if (CAL_CTRL_CODE_START & CtrlCode)
    {
        ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_IN_STRUCT IspDigitalZoomResParaIn;
        ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT IspDigitalZoomResParaOut;

        kal_uint32 WebcamRealWidth=1;
        kal_uint32 WebcamRealHeight=1;

        ASSERT(CalState == CAL_STANDBY_STATE);

        kal_mem_cpy(&CalWebcamProcessStruct, pCalWebcamPara, sizeof(CAL_CAMERA_WEBCAM_PROCESS_STRUCT));
        if((CalWebcamProcessStruct.TargetSize)<USBVIDEO_VIDEO_SIZE_1)
            CalWebcamProcessStruct.TargetSize = USBVIDEO_VIDEO_SIZE_1;
        if((CalWebcamProcessStruct.TargetCompression)<USBVIDEO_COMPRESSION_1)
            CalWebcamProcessStruct.TargetCompression = USBVIDEO_COMPRESSION_1;  

        if ( ScenarioId == CAL_SCENARIO_WEBCAM_CAPTURE)
        {    
            WebcamRealWidth = (CalWebcamStillSize.pWebCamStillSizeInfo)[CalWebcamProcessStruct.TargetSize-1].width;
            WebcamRealHeight = (CalWebcamStillSize.pWebCamStillSizeInfo)[CalWebcamProcessStruct.TargetSize-1].height;
            ErrorCode = pfCalCallback(CAL_CBID_WEBCAM_GET_STILL_BUFF, &CalWebcamCbStruct, sizeof(CAL_WEBCAM_CB_STRUCT));
        }
        else if ( ScenarioId == CAL_SCENARIO_WEBCAM_PREVIEW)
        {
            WebcamRealWidth = (CalWebcamVideoSize.pWebCamVideoSizeInfo)[CalWebcamProcessStruct.TargetSize-1].width;
            WebcamRealHeight = (CalWebcamVideoSize.pWebCamVideoSizeInfo)[CalWebcamProcessStruct.TargetSize-1].height;
            ErrorCode = pfCalCallback(CAL_CBID_WEBCAM_GET_VIDEO_BUFF, &CalWebcamCbStruct, sizeof(CAL_WEBCAM_CB_STRUCT));
        }   

        if(CalWebcamCbStruct.BuffAddr != NULL)
        {  
            if ((WebcamRealWidth != CalWebcamTargetWidthBackup) || (WebcamRealHeight != CalWebcamTargetHeightBackup))
            {
                /// TG setting
                IspTgSettingInfo.ScenarioId = CAL_SCENARIO_CAMERA_PREVIEW;    
                IspTgSettingInfo.pSensorInfo=(void *) &CurrentSensorInfo;
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_SET_TG, &IspTgSettingInfo, NULL, 0, NULL);

                /// Sensor setting
                SensorScenarioParaIn.ImageMirror= CalWebcamRotateMap[CalWebcamProcessStruct.ImageRotate];
                SensorScenarioParaIn.ImageTargetWidth = WebcamRealWidth;
                SensorScenarioParaIn.ImageTargetHeight = WebcamRealHeight;
                SensorScenarioParaIn.NightMode=KAL_FALSE;
                SensorScenarioParaIn.MetaMode=CAMERA_SYSTEM_NORMAL_MODE;
                SensorScenarioParaIn.EnableShutterTransfer=KAL_FALSE;
                SensorScenarioParaIn.ZoomFactor=100;  ///Bin ??? 
                SensorScenarioParaIn.ContrastLevel=1;
                SensorScenarioParaIn.BrightnessLevel=1;
                SensorScenarioParaIn.SaturationLevel=1;
                SensorScenarioParaIn.WbMode=CAM_WB_AUTO;
                SensorScenarioParaIn.EvValue=CAM_EV_ZERO;
                SensorScenarioParaIn.BandingFreq=CAM_BANDING_50HZ;
                SensorScenarioParaIn.ImageEffect=CAM_EFFECT_ENC_NORMAL;
                SensorScenarioParaIn.HueValue=1;        	
                ErrorCode=pfImageSensor->SensorCtrl(ScenarioId, &SensorScenarioParaIn, &SensorScenarioParaOut,
                    sizeof(IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT), &OutParaLen);

                /// Grab window setting
                pIspGetOutResParaIn=(P_ISP_FEATURE_GET_OUTPUT_RESOLUTION_IN_STRUCT) CalFeatureCtrlBuff1;
                pIspGetOutResParaOut=(P_ISP_FEATURE_GET_OUTPUT_RESOLUTION_OUT_STRUCT) CalFeatureCtrlBuff2;
                pIspGetOutResParaIn->IspState=ISP_CAPTURE_WEBCAM_STATE;
                pIspGetOutResParaIn->BinningMode=KAL_FALSE;
                pIspGetOutResParaIn->RawCaptureEnable=KAL_FALSE;
                pIspGetOutResParaIn->ZoomStep=0;        
                pIspGetOutResParaIn->TotalZoomStep=1;       
                pIspGetOutResParaIn->MaxZoomFactor=100;   ///Bin ??
                pIspGetOutResParaIn->SensorImageGrabStartX=SensorScenarioParaOut.GrabStartX;
                pIspGetOutResParaIn->SensorImageGrabStartY=SensorScenarioParaOut.GrabStartY;
                pIspGetOutResParaIn->SensorImageWidth=SensorScenarioParaOut.ExposureWindowWidth;
                pIspGetOutResParaIn->SensorImageHeight=SensorScenarioParaOut.ExposureWindowHeight;
                pIspGetOutResParaIn->TargetWidth=WebcamRealWidth;
                pIspGetOutResParaIn->TargetHeight=WebcamRealHeight;
                ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_OUTPUT_RESOLUTION, pIspGetOutResParaIn,
                    pIspGetOutResParaOut, sizeof(ISP_FEATURE_GET_OUTPUT_RESOLUTION_OUT_STRUCT),
                    &OutParaLen);

                IspDigitalZoomResParaIn.ZoomStep=0;
                ErrorCode=pfIspFunc->IspFeatureCtrl(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION, &IspDigitalZoomResParaIn,
                                                    &IspDigitalZoomResParaOut, sizeof(ISP_FEATURE_GET_DIGITAL_ZOOM_RESOLUTION_OUT_STRUCT),
                                                    &OutParaLen);
                MdpStillCapturePara.mdp_crop_enable=IspDigitalZoomResParaOut.MdpCropEnable;
                MdpStillCapturePara.cropped_width=IspDigitalZoomResParaOut.DigitalZoomWidth;
                MdpStillCapturePara.cropped_height=IspDigitalZoomResParaOut.DigitalZoomHeight;

            }

            if ( ScenarioId == CAL_SCENARIO_WEBCAM_CAPTURE)
            {    
                CalWebcamCbStruct.BuffSize = (CalWebcamStillSize.pWebCamStillSizeInfo)[CalWebcamProcessStruct.TargetSize-1].max_frame_size;
            }
            else if ( ScenarioId == CAL_SCENARIO_WEBCAM_PREVIEW)
            {
                CalWebcamCbStruct.BuffSize = (CalWebcamVideoSize.pWebCamVideoSizeInfo)[CalWebcamProcessStruct.TargetSize-1].max_frame_size;
            }

            /* config idp */
            if(!IsHwJpegEncSupport)       /// for SW JPEG Encoder platform
            {
                //MdpStillCapturePara.fullsize_image_rot_angle;
                MdpStillCapturePara.fullsize_image_format = (MM_IMAGE_FORMAT_ENUM)IMG_COLOR_FMT_YUV420;
                MdpStillCapturePara.fullsize_image_buffer_y_addr = CalWebcamProcessStruct.ExtmemStartAddress ;
                MdpStillCapturePara.fullsize_image_buffer_u_addr = CalWebcamProcessStruct.ExtmemStartAddress + WEBCAM_YUV_IMAGE_BUFFER_SIZE * 2/3;
                MdpStillCapturePara.fullsize_image_buffer_v_addr = CalWebcamProcessStruct.ExtmemStartAddress + WEBCAM_YUV_IMAGE_BUFFER_SIZE * 5/6;
            }
			
            MdpStillCapturePara.extmem_start_address = CalWebcamProcessStruct.ExtmemStartAddress + WEBCAM_YUV_IMAGE_BUFFER_SIZE;
            MdpStillCapturePara.extmem_size = IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM;
            MdpStillCapturePara.source_width = pIspGetOutResParaOut->IspOutWidth;
            MdpStillCapturePara.source_height = pIspGetOutResParaOut->IspOutHeight;
            MdpStillCapturePara.fullsize_image_width = WebcamRealWidth;
            MdpStillCapturePara.fullsize_image_height = WebcamRealHeight;
            MdpStillCapturePara.fullsize_image_jpeg_yuv_mode = (MM_IMAGE_COLOR_FORMAT_ENUM)IMG_COLOR_FMT_YUV420;    ///Bin ????
            MdpStillCapturePara.fullsize_image_format = (MM_IMAGE_FORMAT_ENUM)IMG_COLOR_FMT_YUV420;
            MdpStillCapturePara.quickview_image_enable = KAL_FALSE;
            MdpStillCapturePara.thumbnail_image_enable = KAL_FALSE;
            MdpStillCapturePara.quickview_pitch_enable = KAL_FALSE;
            #ifdef MT6268
            MdpStillCapturePara.quickview_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM)IMG_COLOR_FMT_RGB565;  //Bin:  to fix color format check error in MDP
            #else
            MdpStillCapturePara.quickview_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM)IMG_COLOR_FMT_PACKET_YUYV422;  //Bin:  to fix color format check error in MDP
            #endif
            MdpStillCapturePara.thumbnail_image_color_format = (MM_IMAGE_COLOR_FORMAT_ENUM)IMG_COLOR_FMT_RGB888;
            MdpStillCapturePara.enable_overlay = KAL_FALSE;

            /* config ISP */
            CalWebcamIspCapturePara.ImageMirror = CalWebcamRotateMap[CalWebcamProcessStruct.ImageRotate];
            CalWebcamIspCapturePara.ImageTargetWidth=WebcamRealWidth;
            CalWebcamIspCapturePara.ImageTargetHeight=WebcamRealHeight;
            CalWebcamIspCapturePara.pCalIspCapturePara=&CalWebcamStillCapturePara;

            CalWebcamStillCapturePara.BinningMode = KAL_FALSE;
            CalWebcamStillCapturePara.ExpoBracketLevel = 0;  
            CalWebcamStillCapturePara.RawCaptureEnable = KAL_FALSE;
            CalWebcamStillCapturePara.RawImageBuffAddr = CalWebcamCbStruct.BuffAddr;
            CalWebcamStillCapturePara.StillCaptureMode = CAM_STILL_CAPTURE_NORMAL;

            pIspScenarioCtrl=(P_ISP_SCENARIO_CTRL_STRUCT) CalFeatureCtrlBuff1;
            pIspScenarioCtrl->pScenarioCtrlPara=&CalWebcamIspCapturePara;
            pIspScenarioCtrl->ScenarioCtrlParaLen=sizeof(ISP_CAMERA_STILL_CAPTURE_STRUCT);
            if ((WebcamRealWidth != CalWebcamTargetWidthBackup) || (WebcamRealHeight != CalWebcamTargetHeightBackup))
            {
                pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_INIT;       ///Config and  wait delay frame and wait 3A stable
                ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, NULL);  
                if(ErrorCode != MM_ERROR_NONE)
                {
                    ///TODO: ERROR handling
                    ASSERT(0);
                }
            }
            /* start jpeg driver */
            JpegWrapper.srcWindow.x=0;
            JpegWrapper.srcWindow.y=0;
            JpegWrapper.srcWindow.w=0;
            JpegWrapper.srcWindow.h=0;
            JpegWrapper.srcWidth=WebcamRealWidth;
            JpegWrapper.srcHeight=WebcamRealHeight;
            JpegWrapper.dstWidth=WebcamRealWidth;
            JpegWrapper.dstHeight=WebcamRealHeight;
            JpegWrapper.dstBufferAddr=(void *) CalWebcamCbStruct.BuffAddr;
            JpegWrapper.dstBufferSize=CalWebcamCbStruct.BuffSize;
            JpegWrapper.dstQuality=(JPEG_ENCODE_QUALITTY_ENUM)((CalWebcamCompression.pWebCamCompressionInfo)[CalWebcamProcessStruct.TargetCompression-1].compression);
            JpegWrapper.dstSamplingFormat=JPEG_YUV_FORMAT_YUV420;     ///Bin ????
            JpegWrapper.dstFileFormat=JPEG_FILE_FORMAT_JPEG;
            JpegWrapper.extMemoryAddr=(void *)(((CalWebcamProcessStruct.ExtmemStartAddress + WEBCAM_YUV_IMAGE_BUFFER_SIZE + IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM)+3)&0xFFFFFFFC);//JPEG 4 byte align
            JpegWrapper.extMemorySize=JPEG_ENC_EXT_MAX_MEM_SIZE;
            JpegWrapper.enableThumbnail=KAL_FALSE;
            JpegWrapper.thumbnailWidth=0;
            JpegWrapper.thumbnailHeight=0;
            JpegWrapper.qviImageBufferAddr=NULL;
            JpegWrapper.qviImageWidth=0;
            JpegWrapper.qviImageHeight=0;
            JpegWrapper.qviImageColorFormat=0;
            JpegWrapper.qviImageRotAngle=0;

        #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
            if(IsHwJpegEncSupport)       /// for HW JPEG Encoder platform
            {
                JpegWrapper.srcMode = JPEG_ENCODE_SOURCE_ISP;
                JpegWrapper.callback_function=CalWebcamSendFrameReadyRequest;
                jpeg_wrapper_open(&JpegWrapperHandle, JPEG_CODEC_TYPE_HW);
                jpeg_wrapper_start(JpegWrapperHandle, &JpegWrapper);
            }
        #else
            {
                JpegWrapper.srcMode = JPEG_ENCODE_SOURCE_YUV_BUFFER;
                JpegWrapper.srcSamplingFormat = GetJpegWrapperFormat((MM_IMAGE_FORMAT_ENUM)(MdpStillCapturePara.fullsize_image_jpeg_yuv_mode));
                JpegWrapper.srcYUVBuffer[0] =(kal_uint8 *)MdpStillCapturePara.fullsize_image_buffer_y_addr;
                JpegWrapper.srcYUVBuffer[1] =(kal_uint8 *)MdpStillCapturePara.fullsize_image_buffer_u_addr;
                JpegWrapper.srcYUVBuffer[2] =(kal_uint8 *)MdpStillCapturePara.fullsize_image_buffer_v_addr;
                JpegWrapper.srcBufferSize[0] = WEBCAM_YUV_IMAGE_BUFFER_SIZE * 2/3;
                JpegWrapper.srcBufferSize[1] = WEBCAM_YUV_IMAGE_BUFFER_SIZE * 1/6;   
                JpegWrapper.srcBufferSize[2] = WEBCAM_YUV_IMAGE_BUFFER_SIZE * 1/6; 
                JpegWrapper.callback_function = NULL;
                jpeg_wrapper_open(&JpegWrapperHandle, JPEG_CODEC_TYPE_SW);
            }
        #endif

            /* start idp driver */
            ErrorCode=MdpFunc.pfnIdpCalOpen( CAL_SCENARIO_CAMERA_STILL_CAPTURE, &IdpCalKey, NULL, 0);
            ASSERT(ErrorCode == MM_ERROR_NONE);
            ErrorCode = MdpFunc.pfnIdpCalSet( CAL_SCENARIO_CAMERA_STILL_CAPTURE, IdpCalKey, IDP_CAL_SET_CONFIG, &MdpStillCapturePara);
            ASSERT(ErrorCode == MM_ERROR_NONE);
            ErrorCode = MdpFunc.pfnIdpCalStart( CAL_SCENARIO_CAMERA_STILL_CAPTURE, IdpCalKey);
            ASSERT(ErrorCode == MM_ERROR_NONE);

            if ( ScenarioId == CAL_SCENARIO_WEBCAM_PREVIEW)
            {
                CalState = CAL_WEBCAM_PREVIEW_STATE;
            }
            else if ( ScenarioId == CAL_SCENARIO_WEBCAM_CAPTURE)
            {
                CalState = CAL_WEBCAM_CAPTURE_STATE;
            }

            CalWebcamTargetWidthBackup = WebcamRealWidth;
            CalWebcamTargetHeightBackup = WebcamRealHeight;

            /* start isp engine */
            pIspScenarioCtrl->ScenarioCtrlCode=CAL_CTRL_CODE_START; ///start
            ErrorCode=pfIspFunc->IspCtrl(ScenarioId, pIspScenarioCtrl,  NULL, 0, NULL);
            if(ErrorCode != MM_ERROR_NONE)
            {
                ///TODO: ERROR handling
                CalTrace(CAL_TRACE_WEBCAM,CAL_WEBCAM_ERROR,ErrorCode);
                ASSERT(0);
            }
        }

    }

    return ErrorCode;
} /* CalWebcamCtrl() */

#else

void CalWebcamInit(void)
{
    return;
}

kal_int32 CalWebcamCallback(kal_uint32 return_code)
{
    return 0;  
}

kal_int32 CalWebcamSendFrameReadyRequest(JPEG_CODEC_STATE_ENUM return_code)
{
    return 0;
}

MM_ERROR_CODE_ENUM CalWebcamFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,P_CAL_FEATURE_CTRL_STRUCT pFeatureOut, kal_uint32 FeatureOutLen)
{
	return MM_ERROR_NONE;
}

MM_ERROR_CODE_ENUM CalWebcamCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode, void *pCtrlPara, kal_uint16 CtrlParaLen)
{
    return MM_ERROR_NONE;
}
#endif  ///#ifdef WEBCAM_SUPPORT

