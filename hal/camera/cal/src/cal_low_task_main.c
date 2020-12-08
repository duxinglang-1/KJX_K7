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
 *   cal_low_task_main.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   CAL LOW task interface
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "kal_public_api.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */

#include "cal_api.h"
#include "cal_comm_def.h"
#include "cal_if.h"
#include "cal_drv_features.h"
#include "cal_task_msg_if.h"

#include "pp_api.h"
#include "pp_comm_def.h"
#include "isp_if.h"
#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */

// rotator
#include "rotator_enum.h"
#include "yuv_rotator_api.h"
#include "rgb_rotator_api.h"

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif

#if (defined(__POSTPROC_SUPPORT__))
/* Cal Low Task Context Struct */
typedef struct
{
    kal_uint16 MyModId;

    event_scheduler *pEventScheduler;
} CAL_LOW_CONTEXT_STRUCT, *P_CAL_LOW_CONTEXT_STRUCT;

#define CAL_LOW_BASE_TIMER_ID 0x0000

#define MAX_NUM_OF_CAL_LOW_TIMER 4

typedef struct
{
    eventid EventId;
    kal_timer_func_ptr CallbackFunc;
    void *Arg;
} CAL_LOW_TIMER_TABLE_STRUCT, *P_CAL_LOW_TIMER_TABLE_STRUCT;

/* global variables */
CAL_LOW_CONTEXT_STRUCT CalLowContext;
CAL_LOW_TIMER_TABLE_STRUCT CalLowTimerTable[MAX_NUM_OF_CAL_LOW_TIMER];

/*==== Timer Control Interface ============*/
void CalLowTimerExpiryCallback(void *Arg);
void CalLowStartTimer(kal_uint8 TimerId, kal_uint32 Period, kal_timer_func_ptr TimerExpiry, void *Arg);
void CalLowStopTimer(kal_uint8 TimerId);
kal_uint8 CalLowGetValidTimer(void);
#endif  /* defined(__POSTPROC_SUPPORT__) */
#if defined(__JPEG_SENSOR_SUPPORT__)
extern void CalJpegSensorParseHandle(ilm_struct *pIlmPtr);
#endif

/*****************************************************************************
 * FUNCTION
 *  CalLowJpegDecHandle
 * DESCRIPTION
 *
 * PARAMETERS
 *  pEncodeReqStruct       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 #if defined(__POSTPROC_SUPPORT__)
 extern void CalJpegDecode(P_CAL_JPEG_DECODE_STRUCT pClipInfo);
void CalJpegDecHandle(P_CAL_JPEG_DECODE_REQ_STRUCT pDecodeReqStruct)
{
#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
    if((CAL_POSTPROC_STATE==CalState) && (KAL_TRUE==CalHdrEnabled))
    {
        // abort handling
        if (IsHdrAborted && (CalEventId!=NULL))
        {
            kal_set_eg_events(CalEventId,CAL_PP_ABORT_DONE_EVENT,KAL_OR);
            return;
        }
    }
#endif // __HIGH_DYNAMIC_RANGE_SUPPORT__

    // funtion body at cal_task_main.c
    CalJpegDecode(pDecodeReqStruct->pJpegDecoderPara);

#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
    if((CAL_POSTPROC_STATE==CalState) && (KAL_TRUE==CalHdrEnabled))
    {
        // abort handling
        CalHdrState = CAL_HDR_DECODED_STATE;
        if (IsHdrAborted && (CalEventId!=NULL))
        {
            kal_set_eg_events(CalEventId,CAL_PP_ABORT_DONE_EVENT,KAL_OR);
            return;
        }
    }
#endif // __HIGH_DYNAMIC_RANGE_SUPPORT__

    return;
}
#endif // __POSTPROC_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  CalJpegEncHandle
 * DESCRIPTION
 *
 * PARAMETERS
 *  pEncodeReqStruct       [IN]
 *  JpegCodeType           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void CalJpegEncHandle(P_CAL_SW_JPEG_ENCODE_REQ_STRUCT pEncodeReqStruct, JPEG_CODEC_TYPE_ENUM JpegCodeType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_JPEG_ENCODE_CB_STRUCT JpegCbStruct = {(JPEG_STATUS_ENUM) 0, NULL, 0};
    JPEG_STATUS_ENUM JpegStatus;
    JPEG_ENCODER_HANDLE JpegHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (defined(__PANORAMA_VIEW_SUPPORT__)||defined(__AUTOCAP_PANORAMA_SUPPORT__))
    if((CAL_POSTPROC_STATE==CalState)&&(CAL_PANO_STOPPING_STATE==CalPanoState))
        return;
#endif  //__PANORAMA_VIEW_SUPPORT__ || __AUTOCAP_PANORAMA_SUPPORT__


    // calling jpeg wrapper
    JpegStatus = jpeg_wrapper_open(&JpegHandle, JpegCodeType);
    JpegWrapperHandle=JpegHandle;   // to sync with HW JPEG encode flow

    if(JpegStatus == JPEG_STATUS_OK)
    {
        // switch to cacheable
        if(JPEG_CODEC_TYPE_SW==JpegCodeType)
        {
            if(CAL_SCENARIO_POST_PROCESSING==pEncodeReqStruct->ScenarioId)
                JpegWrapper.callback_function=NULL;
        }

        JpegStatus = jpeg_wrapper_start(JpegHandle, pEncodeReqStruct->pJpegWrapperPara);
        ASSERT(JpegStatus == JPEG_STATUS_OK);

    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        if(JPEG_CODEC_TYPE_HW==JpegCodeType)
        {
            return;
        }
        else if(JPEG_CODEC_TYPE_SW==JpegCodeType)
    #endif
        {
            // Pp-scenario get jpeg result at jpegcallback, and close it at scenario stop
            if(CAL_SCENARIO_POST_PROCESSING==pEncodeReqStruct->ScenarioId)
            {
                JpegEncCallback(JPEG_CODEC_STATE_COMPLETE);
                return;
            }
            else
            {
                JpegStatus = jpeg_wrapper_get_encoded_data(JpegHandle,&(JpegCbStruct.pJpegDataAddr),&(JpegCbStruct.JpegDataSize));
                jpeg_wrapper_close(JpegHandle);
            }
        }
    }
    else
    {
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        if(JPEG_CODEC_TYPE_HW==JpegCodeType)
            return;
    #endif
    }

    // callback
    // Pp-scenario is already return and not callback here; it callback by jpeg wrapper
    JpegCbStruct.JpegStatus = JpegStatus;
    if (CAL_SCENARIO_CAMERA_STILL_CAPTURE==pEncodeReqStruct->ScenarioId)
    {
        JpegCallback(CAL_CBID_MAIN_IMAGE_READY, &JpegCbStruct, sizeof(CAL_JPEG_ENCODE_CB_STRUCT));
    }
}

#if (defined(__POSTPROC_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  CalLowTimerExpiryCallback
 * DESCRIPTION
 *
 * PARAMETERS
 *  Arg     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CalLowTimerExpiryCallback(void *Arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *TimerId = (kal_uint8*) Arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32) TimerId < (kal_uint32) MAX_NUM_OF_CAL_LOW_TIMER)
    {
        CalLowTimerTable[(kal_uint32) (TimerId)].EventId = NULL;
        (CalLowTimerTable[(kal_uint32) (TimerId)].CallbackFunc) (CalLowTimerTable[(kal_uint32) (TimerId)].Arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CalLowStartTimer
 * DESCRIPTION
 *
 * PARAMETERS
 *  TimerId            [IN]
 *  Period              [IN]
 *  TimerExpiry        [IN]
 *  Arg                 [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CalLowStartTimer(kal_uint8 TimerId, kal_uint32 Period, kal_timer_func_ptr TimerExpiry, void *Arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 temp = (Period * 7) >> 5;    /* ~= x 1/4.615 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (temp == 0)
    {
        temp = 1;
    }
    CalLowTimerTable[TimerId].CallbackFunc = TimerExpiry;
    CalLowTimerTable[TimerId].Arg = Arg;
    CalLowTimerTable[TimerId].EventId = evshed_set_event(
                                            CalLowContext.pEventScheduler,
                                            (kal_timer_func_ptr) CalLowTimerExpiryCallback,
                                            (void*)TimerId,
                                            temp /** KAL_TICKS_10_MSEC */ );
}


/*****************************************************************************
 * FUNCTION
 *  CalLowStopTimer
 * DESCRIPTION
 *
 * PARAMETERS
 *  TimerId        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void CalLowStopTimer(kal_uint8 TimerId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (CalLowTimerTable[TimerId].EventId != NULL)
    {
        evshed_cancel_event(CalLowContext.pEventScheduler, &(CalLowTimerTable[TimerId].EventId));
        CalLowTimerTable[TimerId].EventId = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  CalLowGetValidTimer
 * DESCRIPTION
 *
 * PARAMETERS
 *  void        [IN]
 * RETURNS
 *  TimerId
 *****************************************************************************/
kal_uint8 CalLowGetValidTimer(void)
{
    kal_uint8 TimerId;

    for (TimerId = 1; TimerId < MAX_NUM_OF_CAL_LOW_TIMER; TimerId++)
    {
        if (NULL == CalLowTimerTable[(kal_uint32) (TimerId)].EventId)
        {
            return TimerId;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  CalLowTimerInit
 * DESCRIPTION
 *
 * PARAMETERS
 *  void        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void CalLowTimerInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* start base timer */

    CalLowContext.pEventScheduler = evshed_create("Cal Low Base Timer", MOD_CAL_LOW, 0, 0 );

    for (i = 0; i < MAX_NUM_OF_CAL_LOW_TIMER; i++)
    {
        CalLowTimerTable[i].EventId = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CalLowTimerExpiryHdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  pIlmPtr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void CalLowTimerExpiryHdlr(ilm_struct *pIlmPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) pIlmPtr->local_para_ptr;

    if (stack_timer_ptr->timer_indx == CAL_LOW_BASE_TIMER_ID)
    {
        /* Check if the base timer is stopped or not */
        /* Execute event's timeout handler */
        evshed_timer_handler(CalLowContext.pEventScheduler);
    }
}

void CalLowPpTimerReqHdlr(PP_TIMER_PROC_INFO_STRUCT *pTimerProcInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PP_FEATURE_CTRL_STRUCT_UNION    FeaturePara;
    PP_STATE_ENUM   PpState;

    pTimerProcInfo->Func(pTimerProcInfo->ScenarioId, pTimerProcInfo->CtrlCode,
        pTimerProcInfo->pParaIn, pTimerProcInfo->pParaOut, pTimerProcInfo->ParaOutLen);

    // Check State
    FeaturePara.pFuncState = &PpState;
    PpFeatureCtrl((PP_FUNC_ENUM)pTimerProcInfo->FuncId, PP_FEATURE_GET_STATE, 0, &FeaturePara, 0);

    if(*(FeaturePara.pFuncState) == PP_STATE_BUSY)
    {
        CalLowStartTimer(pTimerProcInfo->TimerId, pTimerProcInfo->TimerSuspPeriod, (kal_timer_func_ptr)CalLowPpTimerReqHdlr, pTimerProcInfo);
    }
}
// callback timer
void CalLowPpStartTimerReqHdlr(ilm_struct *pIlmPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_PP_TIMER_PROC_INFO_STRUCT pTimerProcInfo;
    PP_FEATURE_CTRL_STRUCT_UNION FeatureOut;
    PP_FEATURE_GET_OPMODE_STRUCT    FuncOpMode;
    P_PP_PROC_REQ_STRUCT pMsg = (P_PP_PROC_REQ_STRUCT) pIlmPtr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(pMsg->Func != NULL);

#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
    if((CAL_POSTPROC_STATE==CalState) && (KAL_TRUE==CalHdrEnabled))
    {
        // abort handling
        CalHdrState = CAL_HDR_CORE_STATE;
        if (IsHdrAborted && (CalEventId!=NULL))
        {
           kal_set_eg_events(CalEventId,CAL_PP_ABORT_DONE_EVENT,KAL_OR);
           return;
        }
    }
#endif // __HIGH_DYNAMIC_RANGE_SUPPORT__


    FeatureOut.pFuncOpMode = &FuncOpMode;
    PpFeatureCtrl((PP_FUNC_ENUM)pMsg->FuncId, PP_FEATURE_GET_OPMODE, 0, &FeatureOut, 0);

    pTimerProcInfo = FuncOpMode.pTimerProcInfo;

    ASSERT(pTimerProcInfo != NULL);

    if (0 == pTimerProcInfo->TimerId)
    {
            pTimerProcInfo->TimerId = CalLowGetValidTimer();
            ASSERT(pTimerProcInfo->TimerId != 0);
    }
    else
    {
        CalLowStopTimer(pTimerProcInfo->TimerId);
    }
    pTimerProcInfo->Func = pMsg->Func;
    pTimerProcInfo->FuncId = pMsg->FuncId;
    pTimerProcInfo->ScenarioId = pMsg->ScenarioId;
    pTimerProcInfo->CtrlCode = pMsg->CtrlCode;
    pTimerProcInfo->pParaIn = pMsg->pParaIn;
    pTimerProcInfo->pParaOut = pMsg->pParaOut;
    pTimerProcInfo->ParaOutLen = pMsg->ParaOutLen;

    CalLowPpTimerReqHdlr(pTimerProcInfo);
}

void CalLowPpStartReqHdlr(ilm_struct *pIlmPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_PP_PROC_REQ_STRUCT pMsg = (P_PP_PROC_REQ_STRUCT) pIlmPtr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(pMsg->Func != NULL);

    pMsg->Func(pMsg->ScenarioId, pMsg->CtrlCode, pMsg->pParaIn, pMsg->pParaOut, pMsg->ParaOutLen);
}

void CalLowPpStopReqHdlr(ilm_struct *pIlmPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_PP_TIMER_PROC_INFO_STRUCT pTimerProcInfo;
    PP_FEATURE_CTRL_STRUCT_UNION FeatureOut;
    PP_FEATURE_GET_OPMODE_STRUCT    FuncOpMode;
    P_PP_PROC_REQ_STRUCT pMsg = (P_PP_PROC_REQ_STRUCT) pIlmPtr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   ASSERT(pMsg->Func != NULL);

    FeatureOut.pFuncOpMode = &FuncOpMode;
    PpFeatureCtrl((PP_FUNC_ENUM)pMsg->FuncId, PP_FEATURE_GET_OPMODE, 0, &FeatureOut, 0);

    if(PP_PROC_TYPE_TIMER == FeatureOut.pFuncOpMode->Type)
    {
        pTimerProcInfo = FuncOpMode.pTimerProcInfo;
        if (pTimerProcInfo && pTimerProcInfo->TimerId != 0)
        {
            ASSERT(pTimerProcInfo->TimerId < MAX_NUM_OF_CAL_LOW_TIMER);
            CalLowStopTimer(pTimerProcInfo->TimerId);
            pTimerProcInfo->TimerId = 0;
        }
    }

    pMsg->Func(pMsg->ScenarioId, pMsg->CtrlCode, pMsg->pParaIn, pMsg->pParaOut, pMsg->ParaOutLen);
}
#endif /* defined(__POSTPROC_SUPPORT__) */

#if defined(__CAL_CAMERA_AF_SUPPORT__)
void CalGetAFResultHandlr(ilm_struct *pIlmPtr)
{
    CAL_CAMERA_AF_RESULT_STRUCT   AfResult;
    CAL_FEATURE_CTRL_STRUCT CameraFeatureIn;
    extern kal_bool   IspWaitAFResult;

    AfResult.AfSearchResult = AF_SEARCH_STATUS_BUSY;
    AfResult.AfSuccessZone  = 0;
    CameraFeatureIn.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
    if (KAL_FALSE == IspWaitAFResult)    //Have Got Result(Success or Fail)
    {
        return;
    }
    pfImageSensor->SensorFeatureCtrl(CAL_FEATURE_CAMERA_AF_RESULT, &CameraFeatureIn, &AfResult, 0, NULL);
    if ((AF_SEARCH_STATUS_FOUND_SUCCESS == AfResult.AfSearchResult)
     || (AF_SEARCH_STATUS_FOUND_FAIL == AfResult.AfSearchResult)
     || (AF_SEARCH_STATUS_IDLE == AfResult.AfSearchResult))          //Got AF Result
    {
         IspWaitAFResult = KAL_FALSE;
         pfCalIspCb(CAL_CBID_AF_RESULT, &AfResult, sizeof(CAL_CAMERA_AF_RESULT_STRUCT));
    }
}
#endif

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
void ImageListRotHandle(ilm_struct *pIlmPtr)
{
    P_CAL_ROTATE_IMAGE_LIST_REQ_STRUCT pImageRotateInfo;
    CAL_BUFFER_CB_STRUCT ImageRotPara;

    ROTATOR_STATUS_ENUM RotatorStatus;
    ROTATOR_COLOR_FORMAT_ENUM RotatorColorFormat;
    YUV_ROTATOR_HANDLE_STRUCT *pYuvRotHandle;
    kal_uint32 DestImageWidth, DestImageHeight;
    kal_uint32 ExtMemMin, ExtMemBest, IntMemMin, IntMemBest;
    kal_int32 i;

    pImageRotateInfo = (P_CAL_ROTATE_IMAGE_LIST_REQ_STRUCT) pIlmPtr->local_para_ptr;

    if (pImageRotateInfo->ImageRotAngle & 0x1)
    {
        DestImageWidth=pImageRotateInfo->SrcImageHeight;
        DestImageHeight=pImageRotateInfo->SrcImageWidth;
    }
    else
    {
        DestImageWidth=pImageRotateInfo->SrcImageWidth;
        DestImageHeight=pImageRotateInfo->SrcImageHeight;
    }

    ImageRotPara.ImageBuffSize=DestImageWidth*DestImageHeight*3/2;
    ImageRotPara.ImageBuffFormat=pImageRotateInfo->ImageDataFormat;
    ImageRotPara.ErrorStatus=MM_ERROR_NONE;
    RotatorColorFormat=ROTATOR_COLOR_FORMAT_ENUM_YUV420_P;

    if (MM_IMAGE_FORMAT_YUV420==pImageRotateInfo->ImageDataFormat)
    {
        // dest image address is shift one source image size forward
        // so rotate from first image
        for (i = 0; i < pImageRotateInfo->ImageCount; i++)
        {
            RotatorStatus=yuvRotatorGetHandle(&pYuvRotHandle, ROTATOR_MODE_AUTO);
            ASSERT(RotatorStatus==ROTATOR_STATUS_OK);

            yuvRotatorSetCallbackFunction(pYuvRotHandle, NULL);     // use polling mode instead of interrupt mode

            yuvRotatorSetSrcBufferInfo(pYuvRotHandle, RotatorColorFormat,
                                           (void *) (pImageRotateInfo->SrcImageYBuffAddr+i*ImageRotPara.ImageBuffSize),
                                           (void *) (pImageRotateInfo->SrcImageUBuffAddr+i*ImageRotPara.ImageBuffSize),
                                           (void *) (pImageRotateInfo->SrcImageVBuffAddr+i*ImageRotPara.ImageBuffSize),
                                           pImageRotateInfo->ImageYBuffSize, pImageRotateInfo->ImageUBuffSize,
                                           pImageRotateInfo->ImageVBuffSize,
                                           pImageRotateInfo->SrcImageWidth, pImageRotateInfo->SrcImageHeight);

            yuvRotatorSetDstBufferInfo(pYuvRotHandle, RotatorColorFormat,
                                           (void *) (pImageRotateInfo->DestImageYBuffAddr+i*ImageRotPara.ImageBuffSize),
                                           (void *) (pImageRotateInfo->DestImageUBuffAddr+i*ImageRotPara.ImageBuffSize),
                                           (void *) (pImageRotateInfo->DestImageVBuffAddr+i*ImageRotPara.ImageBuffSize),
                                           pImageRotateInfo->ImageYBuffSize, pImageRotateInfo->ImageUBuffSize,
                                           pImageRotateInfo->ImageVBuffSize,
                                           DestImageWidth, DestImageHeight);

            yuvRotatorSetSrcWindow(pYuvRotHandle, 0, 0, pImageRotateInfo->SrcImageWidth, pImageRotateInfo->SrcImageHeight);

            yuvRotatorSetDstWindow(pYuvRotHandle, 0, 0, DestImageWidth, DestImageHeight);

            yuvRotatorSetRotation(pYuvRotHandle, (ROTATOR_CW_ROTATE_ANGLE_ENUM) pImageRotateInfo->ImageRotAngle);

            yuvRotatorCheckAbortFunction(pYuvRotHandle, NULL);

            yuvRotatorQueryWorkingMemory(pYuvRotHandle, &IntMemBest, &IntMemMin, &ExtMemBest, &ExtMemMin);

            ASSERT(0==IntMemMin);
            ASSERT(ExtMemMin<=pImageRotateInfo->WorkingBuffSize);

            yuvRotatorSetWorkingMemory(pYuvRotHandle, NULL, 0, (kal_uint32 *) pImageRotateInfo->WorkingBuffAddr,
                                       pImageRotateInfo->WorkingBuffSize);

            yuvRotatorStart(&pYuvRotHandle);

            while ((yuvRotatorGetStatus(pYuvRotHandle)!=ROTATOR_STATUS_OK)&&
                   (yuvRotatorGetStatus(pYuvRotHandle)!=ROTATOR_STATUS_COMPLETE));

            yuvRotatorReleaseHandle(pYuvRotHandle);
        }
    }
    else
    {
        ASSERT(0);
    }
}   /* ImageListRotHandle() */
#endif /* __MULTIPLE_ANGLE_VIEW_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  CalLowMsgHandle
 * DESCRIPTION
 *  This function is main message dispatching function of CAL LOW task.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CalLowMsgHandle(ilm_struct *pIlmPtr)
{
    switch (pIlmPtr->msg_id)
    {
    #ifdef __CAL_HW_JPEG_ENCODE_SUPPORT__
        case MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ:
            CalJpegEncHandle((P_CAL_SW_JPEG_ENCODE_REQ_STRUCT)pIlmPtr->local_para_ptr, JPEG_CODEC_TYPE_HW);
        break;
    #endif
        case MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ:
            CalJpegEncHandle((P_CAL_SW_JPEG_ENCODE_REQ_STRUCT)pIlmPtr->local_para_ptr, JPEG_CODEC_TYPE_SW);
        break;
    #if (defined(__POSTPROC_SUPPORT__))
        case MSG_ID_CAL_LOW_JPEG_DECODE_REQ:
            CalJpegDecHandle((P_CAL_JPEG_DECODE_REQ_STRUCT)pIlmPtr->local_para_ptr);
            break;
        case MSG_ID_CAL_LOW_PP_START_REQ:
            CalLowPpStartReqHdlr(pIlmPtr);
            break;
        case MSG_ID_CAL_LOW_PP_STOP_REQ:
            CalLowPpStopReqHdlr(pIlmPtr);
            break;
        case MSG_ID_CAL_LOW_PP_START_TIMER_REQ:
            CalLowPpStartTimerReqHdlr(pIlmPtr);
            break;
        case MSG_ID_TIMER_EXPIRY:
            CalLowTimerExpiryHdlr(pIlmPtr);
            break;
#endif /* defined(__POSTPROC_SUPPORT__) */
    #if defined(__JPEG_SENSOR_SUPPORT__)
        case MSG_ID_CAL_JPEG_SENSOR_PARSE_REQ:
           CalJpegSensorParseHandle(pIlmPtr);
        break;
    #endif


    #if defined(__CAL_CAMERA_AF_SUPPORT__)
        case MSG_ID_CAL_LOW_GET_AF_RESULT:
            CalGetAFResultHandlr(pIlmPtr);
        break;
    #endif
    #if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
        case MSG_ID_CAL_LOW_ROTATE_IMAGE_LIST_REQ:
            ImageListRotHandle(pIlmPtr);
        break;
    #endif
        default:
            ASSERT(0);
    }
} /* CalLowMsgHandle() */

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

/*****************************************************************************
 * FUNCTION
 *  CalLowTaskMain
 * DESCRIPTION
 *  This function is main function of CAL LOW task.
 * PARAMETERS
 *  task_entry_ptr      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CalLowTaskMain(task_entry_struct *pTaskEntry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct CurrentIlm;
    kal_uint32 CalLowTaskIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&CalLowTaskIndex);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[CalLowTaskIndex].task_ext_qid, &CurrentIlm);
        stack_set_active_module_id(CalLowTaskIndex, CurrentIlm.dest_mod_id);

        CalLowMsgHandle(&CurrentIlm);

        free_ilm(&CurrentIlm);
    }
} /* CalLowTaskMain() */

/*****************************************************************************
 * FUNCTION
 *  CalLowTaskInit
 * DESCRIPTION
 *  This function is used to init CAL_LOW task.
 * PARAMETERS
 *  task_indx       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalLowTaskInit(task_indx_type task_indx)
{
#if (defined(__POSTPROC_SUPPORT__))
    /* init stack timer */
    CalLowTimerInit();
#endif /* defined(__POSTPROC_SUPPORT__) */
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  CalLowTaskReset
 * DESCRIPTION
 *  This function is used to reset CAL_LOW task.
 * PARAMETERS
 *  task_indx       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalLowTaskReset(task_indx_type task_indx)
{
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  CalLowTaskCreate
 * DESCRIPTION
 *  This function is used to create media task configuration info.
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalLowTaskCreate(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct CalLowHandlerInfo =
    {
        CalLowTaskMain,    /* task entry function */
        CalLowTaskInit,    /* task initialization function */
        NULL,           /* task configuration function */
        CalLowTaskReset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & CalLowHandlerInfo;

    return KAL_TRUE;
}   /* CalLowTaskReset() */
