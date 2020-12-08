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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "camera_nvram_def.h"

#include "sensor_comm_def.h"
#include "image_sensor.h"
#include "isp_if.h"
#include "idp_cam_if.h"
#include "lens_comm_def.h"
#include "lens_module.h"

#include "pp_api.h"
#include "pp_comm_def.h"
#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */

#include "visualhisr.h"

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif

kal_eventgrpid CalEventId=NULL;
kal_bool IsHwJpegEncSupport=KAL_FALSE;
//kal_bool IsHwJpegDecSupport=KAL_FALSE;

CAL_STATE_ENUM CalState;
CAL_CAMERA_SOURCE_ENUM CurrentCameraId=CAL_CAMERA_SOURCE_MAX;
CAL_SCENARIO_ENUM CurrentScenarioId=CAL_SCENARIO_CAMERA_PREVIEW;
P_IMAGE_SENSOR_LIST_STRUCT pImageSensorList=NULL;
P_IMAGE_SENSOR_FUNCTION_STRUCT pfImageSensor=NULL;
P_ISP_FUNCTION_STRUCT pfIspFunc=NULL;
IDP_CAL_INTF_FUNC_T MdpFunc;
MM_ERROR_CODE_ENUM (*pfCalCallback) (CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
//P_CAL_FEATURE_CTRL_STRUCT pCalFeatureInPara, pCalFeatureOutPara;
kal_bool MainSensorSupport=KAL_FALSE;
kal_uint32 MainSensorId;
CAL_SENSOR_SUPPORT_STRUCT MainSubCameraStatus={{KAL_FALSE, KAL_FALSE, KAL_FALSE, KAL_FALSE}};
#ifdef __CAL_CAMERA_LENS_SUPPORT__
P_LENS_LIST_STRUCT pLensList=NULL;
P_LENS_FUNCTION_STRUCT pfLens=NULL;
kal_uint32 CurrentLensListIdx;
#endif
#ifdef __CAL_DUAL_CAMERA_SUPPORT__
kal_bool SubSensorSupport=KAL_FALSE;
kal_uint32 SubSensorId;
#endif

#if (defined(__MTK_TARGET__))
MM_ERROR_CODE_ENUM CalSearchSensor(void)
{
    kal_uint32 i;
    IMAGE_SENSOR_COMM_DATA_STRUCT SensorIdPara;
    kal_uint32 EventGroup;
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    kal_uint32 FeatureOutLen;
    P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT pCameraSource;
#ifdef __CAL_NVRAM_NEED_READ__
    kal_bool FirstDetectSensorId=KAL_FALSE;
#endif

    // if the sensor ID is not detect correct, detect it first
    //if (((KAL_TRUE==MainSensorSupport)&&(CurrentCameraId != CAL_CAMERA_SOURCE_MATV)) && ((NULL_SENSOR_ID==MainSensorId)||(0==MainSensorId)))
    if (((CurrentCameraId != CAL_CAMERA_SOURCE_MATV)) && ((NULL_SENSOR_ID==MainSensorId)||(0==MainSensorId)))
    {   // detect main sensor and find its index
        for (i=0;i<MAX_SENSOR_SUPPORT_NUMBER;i++)
        {
            if (((IMAGE_SENSOR_MAIN==(pImageSensorList+i)->SensorIdx)||
                 (IMAGE_SENSOR_BAK1==(pImageSensorList+i)->SensorIdx))&&
                 (NULL != (pImageSensorList+i)->SensorFunc))
            {
                (pImageSensorList+i)->SensorFunc(&pfImageSensor);

                pCameraSource = (P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) &CalFeatureCtrlBuff1[0];
                pCameraSource->ImageSensorIdx = (pImageSensorList+i)->SensorIdx;
                pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE, pCameraSource, NULL, 0, NULL);

                memset(&CurrentSensorInfo, 0, sizeof(CurrentSensorInfo));
                pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO, NULL,
                                                 (void *) &CurrentSensorInfo, sizeof(IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT),
                                                 &FeatureOutLen);
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_INIT_HW, (void *) &CurrentSensorInfo, NULL, 0, &FeatureOutLen);
                pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_SENSOR_ID, NULL, &SensorIdPara, 0, &FeatureOutLen);
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_DEINIT_HW, (void *) &CurrentSensorInfo, NULL, 0, &FeatureOutLen);

                if (MM_ERROR_SENSOR_READ_ID_FAIL!=SensorIdPara.FeatureValue)
                {
                    MainSensorId= SensorIdPara.FeatureValue;
                    MainSensorListIdx= i;
                    break;
                }
            }
        }
    #ifdef __CAL_NVRAM_NEED_READ__
        FirstDetectSensorId=KAL_TRUE;
    #endif
        kal_set_eg_events(CalEventId,0,KAL_AND);
        CalSendMsgToNvram(MSG_ID_NVRAM_WRITE_REQ, NVRAM_EF_CAMERA_MAIN_SENSOR_ID_LID, &MainSensorId, 4);
        kal_retrieve_eg_events(CalEventId,CAL_NVRAM_READ_EVENT, KAL_OR_CONSUME,&EventGroup,KAL_SUSPEND);
    }

#if 0 /* main sensor will be exist always, do not need to check */
/* under construction !*/
#endif
    {
        (pImageSensorList+MainSensorListIdx)->SensorFunc(&pfImageSensor);
        pCameraSource = (P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) &CalFeatureCtrlBuff1[0];
        pCameraSource->ImageSensorIdx = (pImageSensorList+MainSensorListIdx)->SensorIdx;
        pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE, pCameraSource, NULL, 0, NULL);
        pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN, NULL, NULL, 0, NULL);
    }
	
#ifdef __CAL_DUAL_CAMERA_SUPPORT__
    if (((KAL_TRUE==SubSensorSupport) && (CurrentCameraId != CAL_CAMERA_SOURCE_MATV)) && ((NULL_SENSOR_ID==SubSensorId)||(0==SubSensorId)))
    {   // detect main sensor and find its index
        for (i=0;i<MAX_SENSOR_SUPPORT_NUMBER;i++)
        {
            if (((IMAGE_SENSOR_SUB==(pImageSensorList+i)->SensorIdx)||
                 (IMAGE_SENSOR_SUB_BAK1==(pImageSensorList+i)->SensorIdx))&&
                 (NULL != (pImageSensorList+i)->SensorFunc))
            {
                (pImageSensorList+i)->SensorFunc(&pfImageSensor);

                pCameraSource = (P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) &CalFeatureCtrlBuff1[0];
                pCameraSource->ImageSensorIdx = (pImageSensorList+i)->SensorIdx;
                pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE, pCameraSource, NULL, 0, NULL);

                memset(&CurrentSensorInfo, 0, sizeof(CurrentSensorInfo));
                pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO, NULL,
                                                 (void *) &CurrentSensorInfo, sizeof(IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT),
                                                 &FeatureOutLen);
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_INIT_HW, (void *) &CurrentSensorInfo, NULL, 0, &FeatureOutLen);
                pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_SENSOR_ID, NULL, &SensorIdPara, 0, &FeatureOutLen);
                pfIspFunc->IspFeatureCtrl(ISP_FEATURE_DEINIT_HW, (void *) &CurrentSensorInfo, NULL, 0, &FeatureOutLen);

                if (MM_ERROR_SENSOR_READ_ID_FAIL!=SensorIdPara.FeatureValue)
                {
                    SubSensorId=SensorIdPara.FeatureValue;
                    SubSensorListIdx=i;
                    break;
                }
            }
        }
    #ifdef __CAL_NVRAM_NEED_READ__
        FirstDetectSensorId=KAL_TRUE;
    #endif
        kal_set_eg_events(CalEventId,0,KAL_AND);
        CalSendMsgToNvram(MSG_ID_NVRAM_WRITE_REQ, NVRAM_EF_CAMERA_SUB_SENSOR_ID_LID, &SubSensorId, 4);
	    kal_retrieve_eg_events(CalEventId,CAL_NVRAM_READ_EVENT, KAL_OR_CONSUME,&EventGroup,KAL_SUSPEND);
    }

    if(KAL_TRUE==SubSensorSupport)
    {
        (pImageSensorList+SubSensorListIdx)->SensorFunc(&pfImageSensor);
        pCameraSource = (P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) &CalFeatureCtrlBuff1[0];
        pCameraSource->ImageSensorIdx = (pImageSensorList+SubSensorListIdx)->SensorIdx;
        pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE, pCameraSource, NULL, 0, NULL);
        pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN, NULL, NULL, 0, NULL);
    }
#endif
    // start to read NVRAM data if necessary and wait an event to exit the function.
#ifdef __CAL_NVRAM_NEED_READ__
#ifdef __CAL_DUAL_CAMERA_SUPPORT__
    if ((KAL_TRUE==FirstDetectSensorId) && (CurrentCameraId != CAL_CAMERA_SOURCE_MATV) &&
        ((IMAGE_SENSOR_BAK1==(pImageSensorList+MainSensorListIdx)->SensorIdx)||
         (IMAGE_SENSOR_SUB_BAK1==(pImageSensorList+SubSensorListIdx)->SensorIdx)))
#else
    if ((KAL_TRUE==FirstDetectSensorId) &&
        (IMAGE_SENSOR_BAK1==(pImageSensorList+MainSensorListIdx)->SensorIdx))
#endif
    {
        CurrentSensorListIdx = MainSensorListIdx;   // default set as Main sensor
        CurrentNvramFileLid = CameraNvramInfo.CameraNvramStartFileLid[(pImageSensorList+CurrentSensorListIdx)->SensorIdx];
        LastNvramFileLid = CameraNvramInfo.CameraNvramEndFileLid[(pImageSensorList+CurrentSensorListIdx)->SensorIdx];
        CalSendMsgToNvram(MSG_ID_NVRAM_READ_REQ, CurrentNvramFileLid, 0, 0);
        kal_set_eg_events(CalEventId,0,KAL_AND);
	    kal_retrieve_eg_events(CalEventId,CAL_NVRAM_READ_EVENT, KAL_OR_CONSUME,&EventGroup,KAL_SUSPEND);
    }
#endif  /* __CAL_NVRAM_NEED_READ__ */
    return ErrorCode;
} /* CalSearchSensor() */

#ifdef __CAL_CAMERA_LENS_SUPPORT__
MM_ERROR_CODE_ENUM CalSearchLens(kal_uint32 CurrentSensorId, IMAGE_SENSOR_INDEX_ENUM CurrentSensorIdx )
{
    kal_uint32 i;
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    CurrentLensListIdx = 0;
    for (i=0; i<MAX_LENS_NUMBER+1; i++)
    {
        if( (CurrentSensorId ==(pLensList+i)->SensorId) && (CurrentSensorIdx == (pLensList+i)->SensorIdx))
        {
            CurrentLensListIdx = i;
            break;
        }
    }
    return ErrorCode;
}
#endif  // __CAL_CAMERA_LENS_SUPPORT__
#endif  // __MTK_TARGET__

MM_ERROR_CODE_ENUM CalCtrl(CAL_CTRL_ENUM CalCtrl, void *pCalParaIn,
                           void *pCalParaOut, kal_uint32 CalParaOutLen, kal_uint32 *pRealCalParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;
    P_CAL_SCENARIO_CTRL_STRUCT pCalScenario=(P_CAL_SCENARIO_CTRL_STRUCT) pCalParaIn;

#if (defined(__MTK_TARGET__))
    switch (CalCtrl)
    {
        case CAL_SCENARIO_CTRL:
            CurrentScenarioId=pCalScenario->ScenarioId;
            ErrorCode = CalScenarioCtrl(pCalScenario->ScenarioId, pCalScenario->ScenarioCtrlCode,
                            pCalScenario->pScenarioCtrlPara, pCalScenario->ScenarioCtrlParaLen);
        break;
        case CAL_FEATURE_CTRL:
            ErrorCode = CalFeatureCtrl((P_CAL_FEATURE_CTRL_STRUCT) pCalParaIn, (P_CAL_FEATURE_CTRL_STRUCT) pCalParaOut,
                           CalParaOutLen, pRealCalParaOutLen);
        break;
        default:
            ErrorCode = MM_ERROR_CAL_INVALID_CTRL_TYPE;
        break;
    }
		if (MM_ERROR_NONE != ErrorCode)
    	CalTrace(CAL_TRACE_ERROR,CAL_ERROR,ErrorCode);
    return ErrorCode;
#else
    switch (CalCtrl)
    {
        case CAL_SCENARIO_CTRL:
            ErrorCode = CalModisScenarioCtrl(pCalScenario->ScenarioId, pCalScenario->ScenarioCtrlCode,
                                 pCalScenario->pScenarioCtrlPara, pCalScenario->ScenarioCtrlParaLen);
        break;
        case CAL_FEATURE_CTRL:
            ErrorCode = CalModisFeatureCtrl((P_CAL_FEATURE_CTRL_STRUCT) pCalParaIn, (P_CAL_FEATURE_CTRL_STRUCT) pCalParaOut,
                                CalParaOutLen, pRealCalParaOutLen);
        break;
        default:
            ErrorCode = MM_ERROR_CAL_INVALID_CTRL_TYPE;
        break;
    }
    return ErrorCode;
#endif

} /* CalCtrl() */

void CalInit(void)
{
#if (defined(__MTK_TARGET__))
    kal_uint32 i;
	MM_ERROR_CODE_ENUM ErrorCode;
    CalState = CAL_IDLE_STATE;

    ErrorCode = GetSensorInitFunc(&pImageSensorList);
    pImageSensorList->SensorFunc(&pfImageSensor);   /* default select the first sensor */
    CalErrorTrace(ErrorCode);

    for (i=0;i<MAX_SENSOR_SUPPORT_NUMBER;i++)
    {
        if ((0 != (pImageSensorList+i)->SensorId) && (NULL !=(pImageSensorList+i)->SensorFunc))
        {   // the (i+1) th sensor is exist
            if ((pImageSensorList+i)->SensorIdx<IMAGE_SENSOR_MATV)
            MainSubCameraStatus.SensorSupport[(pImageSensorList+i)->SensorIdx]=KAL_TRUE;
            switch ((pImageSensorList+i)->SensorIdx)
            {
            #if 0 /* main sensor will be exist always, do not need to check */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #ifdef __CAL_DUAL_CAMERA_SUPPORT__
                case IMAGE_SENSOR_SUB:
                case IMAGE_SENSOR_SUB_BAK1:
                    SubSensorSupport=KAL_TRUE;
                break;
            #endif
            //    case IMAGE_SENSOR_MATV:
            //    break;
                default:
                //    ASSERT(0);
                break;
            }
        }
    }
#ifdef __CAL_CAMERA_LENS_SUPPORT__
    ErrorCode = GetAfLensInitFunc(&pLensList);
 		CalErrorTrace(ErrorCode);
    ErrorCode = pLensList->LensFunc(&pfLens);
		CalErrorTrace(ErrorCode);
#endif
    ErrorCode = IspInit(&IspCallback, &pfIspFunc);
    CalErrorTrace(ErrorCode);
    ErrorCode = Idp_Cal_If_Init(&MdpCallback, &MdpFunc);
    if (MM_ERROR_NONE != ErrorCode)
    {	
    CalErrorTrace(ErrorCode);
    }
#endif
} /* CalInit() */

MM_ERROR_CODE_ENUM CalOpen(MM_ERROR_CODE_ENUM (* pCallback) (CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen))
{
#if (defined(__MTK_TARGET__))
    MM_ERROR_CODE_ENUM ErrorCode;
    kal_uint32 FeatureOutLen;

	CalTrace(CAL_TRACE_FLOW,CAL_FLOW_OPEN,CAL_TRACE_FLOW_OPEN);
    if (CalState!=CAL_IDLE_STATE)
        return MM_ERROR_CAL_INVALID_STATE;
        //ASSERT(0);

    if (CalEventId==NULL)
        CalEventId=kal_create_event_group("CAL_EVT");

    pfCalCallback = pCallback;

    ErrorCode = CalSearchSensor();
    CalErrorTrace(ErrorCode);
#ifdef __CAL_CAMERA_LENS_SUPPORT__
    ErrorCode = CalSearchLens((pImageSensorList+CurrentSensorListIdx)->SensorId,(pImageSensorList+CurrentSensorListIdx)->SensorIdx);//JH for HAL ISP
		CalErrorTrace(ErrorCode);
#endif
    ErrorCode=CalPassSensorInfoToIsp(CurrentCameraId);    // default camera
		CalErrorTrace(ErrorCode);

    ErrorCode = pfIspFunc->IspFeatureCtrl(ISP_FEATURE_INIT_HW, (void *) &CurrentSensorInfo, NULL, 0, &FeatureOutLen);
    CalErrorTrace(ErrorCode);
    ErrorCode=pfImageSensor->SensorOpen();
    if (MM_ERROR_NONE != ErrorCode)
    {
        CalErrorTrace(ErrorCode);
        
        // Close Sensor
        pfImageSensor->SensorClose();

        ///Deinit ISP HW
        pfIspFunc->IspFeatureCtrl(ISP_FEATURE_DEINIT_HW, (void *) &CurrentSensorInfo, NULL, 0, &FeatureOutLen);
        return ErrorCode;
    }
    
#ifdef __CAL_CAMERA_LENS_SUPPORT__
    ErrorCode=pfLens->LensOpen();
    CalErrorTrace(ErrorCode);
#endif
    ErrorCode=pfIspFunc->IspOpen();
    CalErrorTrace(ErrorCode);
#if (defined(__POSTPROC_SUPPORT__))
    ErrorCode=PpOpen(&PpCallback);
    CalErrorTrace(ErrorCode);
#endif /* defined(__POSTPROC_SUPPORT__) */

    #ifdef WEBCAM_SUPPORT
    CalWebcamInit();
    #endif

    #if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
    VISUAL_Register_HISR(VISUAL_CAL_HISR_ID,CalHISR);
    #endif /* __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__ */
    
    CalState = CAL_STANDBY_STATE;

    return ErrorCode;
#else
    return MM_ERROR_NONE;	   
#endif
} /* CalOpen() */

MM_ERROR_CODE_ENUM CalClose(void)
{
#if (defined(__MTK_TARGET__))
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    kal_uint32 FeatureOutLen;

	CalTrace(CAL_TRACE_FLOW,CAL_FLOW_CLOSE,CAL_TRACE_FLOW_CLOSE);
    CalState = CAL_IDLE_STATE;
#if (defined(__POSTPROC_SUPPORT__))
    ErrorCode=PpClose();
    CalErrorTrace(ErrorCode);
#endif /* defined(__POSTPROC_SUPPORT__) */
#ifdef __CAL_CAMERA_LENS_SUPPORT__
    ErrorCode=pfLens->LensClose();
    CalErrorTrace(ErrorCode);
#endif
    ErrorCode=pfImageSensor->SensorClose();
    CalErrorTrace(ErrorCode);

    ErrorCode=pfIspFunc->IspClose();
    CalErrorTrace(ErrorCode);

    ErrorCode = pfIspFunc->IspFeatureCtrl(ISP_FEATURE_DEINIT_HW, (void *) &CurrentSensorInfo, NULL, 0, &FeatureOutLen);
		CalErrorTrace(ErrorCode);
    return ErrorCode;
#else
    return MM_ERROR_NONE;    
#endif
} /* CalClose() */

MM_ERROR_CODE_ENUM CalDeinit(void)
{
#if (defined(__MTK_TARGET__))
    CalTrace(CAL_TRACE_FLOW,CAL_FLOW_DEINIT,CAL_TRACE_FLOW_DEINIT);
#endif    
    return MM_ERROR_NONE;
} /* CalDeinit() */

#if (!defined(__MTK_TARGET__))
MM_ERROR_CODE_ENUM CalModisScenarioCtrl(CAL_SCENARIO_ENUM ScenarioId, kal_uint32 CtrlCode,
						                void *pCtrlPara, kal_uint16 CtrlParaLen)
{
	MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
	CalTrace(CAL_TRACE_FLOW,CAL_FLOW_SCENARIO_CTRL,CAL_SCENARIO_CTRL,ScenarioId,CtrlCode);
    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            ErrorCode = MM_ERROR_MODIS_FAIL;
        break;
    }

	return ErrorCode;
}	/* CalModisScenarioCtrl() */

MM_ERROR_CODE_ENUM CalModisFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                       P_CAL_FEATURE_CTRL_STRUCT pFeatureOut,
                                       kal_uint32 FeatureOutLen, kal_uint32 *pRealFeatureOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    kal_uint32 i;
    P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT pCameraDzOut;

    //cam_zoom_info *pCamZoomInfo=(cam_zoom_info *)pFeatureIn->FeatureInfo.FeatureStructured.pCapBuff;
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum;
    P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo;

    kal_bool FeatureEnumIsSupport;
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &pFeatureOut->FeatureInfo.FeatureEnum;

    if (NULL!=pFeatureOut)
    {
        pCameraDzOut=pFeatureOut->FeatureInfo.FeatureStructured.pCamDzOutPara;
        pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pFeatureOut->FeatureInfo.FeatureEnum);
        pBinningInfo=pFeatureOut->FeatureInfo.FeatureStructured.pBinningInfo;
    }

    if (CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode)
    {
        switch (pFeatureIn->FeatureId)
        {
		case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE_WITH_DIMENSION:
		//if ((CAL_FEATURE_QUERY_OPERATION==pFeatureIn->FeatureCtrlCode) && (NULL!=pFeatureIn->FeatureInfo.FeatureEnum.SupportItemInfo))
                {
                   memset(pFeatureIn->FeatureInfo.FeatureEnum.SupportItemInfo,0x0,sizeof(CAL_CAMERA_IMAGE_SIZE_STRUCT)*MAX_CAMERA_SUPPORT_ITEM_COUNT);
                }
				
//                ErrorCode=pfImageSensor->SensorFeatureCtrl(CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);		
		pFeatureOut->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
		pFeatureOut->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
		pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
		CapSize->IsSupport = KAL_TRUE;
		CapSize->ItemCount = 6;
		CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
		CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
		CapSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
		CapSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
		CapSize->SupportItem[4] = CAM_IMAGE_SIZE_3M;
		CapSize->SupportItem[5] = CAM_IMAGE_SIZE_5M;		
//	

                FeatureEnumIsSupport = pFeatureOut->FeatureInfo.FeatureEnum.IsSupport;

//                pfImageSensor->SensorFeatureCtrl(pFeatureIn->FeatureId, pFeatureIn, pFeatureOut, FeatureOutLen, pRealFeatureOutLen);
		pFeatureOut->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
		pFeatureOut->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
		pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
		CapSize->IsSupport = KAL_TRUE;
		CapSize->ItemCount = 6;
		CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
		CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
		CapSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
		CapSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
		CapSize->SupportItem[4] = CAM_IMAGE_SIZE_3M;
		CapSize->SupportItem[5] = CAM_IMAGE_SIZE_5M;		
		if (NULL != CapSize->SupportItemInfo)
		{
                  P_CAL_CAMERA_IMAGE_SIZE_STRUCT pCalImageSize;
                  pCalImageSize = (CAL_CAMERA_IMAGE_SIZE_STRUCT *) CapSize->SupportItemInfo;

                 pCalImageSize[5].ImageSizeWidth = 2560;
                 pCalImageSize[5].ImageSizeHeight= 1920;
		}
//

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
        
            case CAL_FEATURE_CAMERA_DIGITAL_ZOOM:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_STRUCTURED;
                pCameraDzOut->DzType=CAM_DZ_TYPE_RANGE;
                pCameraDzOut->TotalZoomSteps=40;
                pCameraDzOut->MaxZoomFactor=800;    // depend on chips
                //pCamZoomInfo->is_support=KAL_TRUE;
                //pCamZoomInfo->zoom_steps=40;
                //pCamZoomInfo->max_zoom_factor=800;
            break;

            case CAL_FEATURE_CAMERA_CONTRAST:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 3;
                pCamFeatureEnum->SupportItem[0] = CAM_CONTRAST_HIGH;
                pCamFeatureEnum->SupportItem[1] = CAM_CONTRAST_MEDIUM;
                pCamFeatureEnum->SupportItem[2] = CAM_CONTRAST_MEDIUM;
            break;

            case CAL_FEATURE_CAMERA_SATURATION:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 3;
                pCamFeatureEnum->SupportItem[0] = CAM_SATURATION_HIGH;
                pCamFeatureEnum->SupportItem[1] = CAM_SATURATION_MEDIUM;
                pCamFeatureEnum->SupportItem[2] = CAM_SATURATION_LOW;
            break;

            case CAL_FEATURE_CAMERA_SHARPNESS:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 3;
                pCamFeatureEnum->SupportItem[0] = CAM_SHARPNESS_HIGH;
                pCamFeatureEnum->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
                pCamFeatureEnum->SupportItem[2] = CAM_SHARPNESS_LOW;

            break;

            case CAL_FEATURE_CAMERA_WB:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 7;
                pCamFeatureEnum->SupportItem[0] = CAM_WB_AUTO;
                pCamFeatureEnum->SupportItem[1] = CAM_WB_CLOUD;
                pCamFeatureEnum->SupportItem[2] = CAM_WB_DAYLIGHT;
                pCamFeatureEnum->SupportItem[3] = CAM_WB_INCANDESCENCE;
                pCamFeatureEnum->SupportItem[4] = CAM_WB_FLUORESCENT;
                pCamFeatureEnum->SupportItem[5] = CAM_WB_TUNGSTEN;
                pCamFeatureEnum->SupportItem[6] = CAM_WB_MANUAL;

            break;

           case CAL_FEATURE_CAMERA_EV_VALUE:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 10;
                pCamFeatureEnum->SupportItem[0] = CAM_EV_NEG_4_3;
                pCamFeatureEnum->SupportItem[1] = CAM_EV_NEG_3_3;
                pCamFeatureEnum->SupportItem[2] = CAM_EV_NEG_2_3;
                pCamFeatureEnum->SupportItem[3] = CAM_EV_NEG_1_3;
                pCamFeatureEnum->SupportItem[4] = CAM_EV_ZERO;
                pCamFeatureEnum->SupportItem[5] = CAM_EV_POS_1_3;
                pCamFeatureEnum->SupportItem[6] = CAM_EV_POS_2_3;
                pCamFeatureEnum->SupportItem[7] = CAM_EV_POS_3_3;
                pCamFeatureEnum->SupportItem[8] = CAM_EV_POS_4_3;
                pCamFeatureEnum->SupportItem[9] = CAM_EV_NIGHT_SHOT;
            break;

            case CAL_FEATURE_CAMERA_FLASH_MODE:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 4;
                pCamFeatureEnum->SupportItem[0] = CAM_FLASH_OFF;
                pCamFeatureEnum->SupportItem[1] = CAM_FLASH_ON;
                pCamFeatureEnum->SupportItem[2] = CAM_FLASH_AUTO;
                pCamFeatureEnum->SupportItem[3] = CAM_FLASH_REDEYE;
            break;

            case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 15;
                pCamFeatureEnum->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
                pCamFeatureEnum->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
                pCamFeatureEnum->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
                pCamFeatureEnum->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
                pCamFeatureEnum->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
                pCamFeatureEnum->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
                pCamFeatureEnum->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
                pCamFeatureEnum->SupportItem[7] = CAM_EFFECT_ENC_BLACKBOARD;
                pCamFeatureEnum->SupportItem[8] = CAM_EFFECT_ENC_WHITEBOARD;
                pCamFeatureEnum->SupportItem[9] = CAM_EFFECT_ENC_COPPERCARVING;
                pCamFeatureEnum->SupportItem[10] = CAM_EFFECT_ENC_EMBOSSMENT;
                pCamFeatureEnum->SupportItem[11] = CAM_EFFECT_ENC_BLUECARVING;
                pCamFeatureEnum->SupportItem[12] = CAM_EFFECT_ENC_JEAN;
                pCamFeatureEnum->SupportItem[13] = CAM_EFFECT_ENC_SKETCH;
                pCamFeatureEnum->SupportItem[14] = CAM_EFFECT_ENC_OIL;

            break;

            case CAL_FEATURE_CAMERA_BANDING_FREQ:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 2;
                pCamFeatureEnum->SupportItem[0] = CAM_BANDING_50HZ;
                pCamFeatureEnum->SupportItem[1] = CAM_BANDING_60HZ;
            break;

            case CAL_FEATURE_CAMERA_SCENE_MODE:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 7;
                pCamFeatureEnum->SupportItem[0] = CAM_AUTO_DSC;
                pCamFeatureEnum->SupportItem[1] = CAM_PORTRAIT;
                pCamFeatureEnum->SupportItem[2] = CAM_LANDSCAPE;
                pCamFeatureEnum->SupportItem[3] = CAM_SPORT;
                pCamFeatureEnum->SupportItem[4] = CAM_ISO_ANTI_HAND_SHAKE;
                pCamFeatureEnum->SupportItem[5] = CAM_NIGHTSCENE;
                pCamFeatureEnum->SupportItem[6] = CAM_DOCUMENT;

            break;

            case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 2;
                pCamFeatureEnum->SupportItem[0] = CAM_VIDEO_AUTO;
                pCamFeatureEnum->SupportItem[1] = CAM_VIDEO_NIGHT;
            break;

            case CAL_FEATURE_CAMERA_AE_METERING_MODE:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 4;
                pCamFeatureEnum->SupportItem[0] = CAM_AE_METER_AUTO;
                pCamFeatureEnum->SupportItem[1] = CAM_AE_METER_SPOT;
                pCamFeatureEnum->SupportItem[2] = CAM_AE_METER_CENTRAL;
                pCamFeatureEnum->SupportItem[3] = CAM_AE_METER_AVERAGE;

            break;

            case CAL_FEATURE_CAMERA_AF_RANGE_CONTROL:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 3;
                pCamFeatureEnum->SupportItem[0] = CAM_AF_RANGE_AUTO;
                pCamFeatureEnum->SupportItem[1] = CAM_AF_RANGE_MACRO;
                pCamFeatureEnum->SupportItem[2] = CAM_AF_RANGE_LANDSCAPE;
            break;

            case CAL_FEATURE_CAMERA_AF_OPERATION_MODE:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 5;
                pCamFeatureEnum->SupportItem[0] = CAM_AF_OFF;
                pCamFeatureEnum->SupportItem[1] = CAM_AF_SINGLE_ZONE;
                pCamFeatureEnum->SupportItem[2] = CAM_AF_MULTI5_ZONE;
                pCamFeatureEnum->SupportItem[3] = CAM_AF_CONTINUOUS;
                pCamFeatureEnum->SupportItem[4] = CAM_AF_MANUAL_MODE;
            break;

            case CAL_FEATURE_CAMERA_STILL_CAPTURE_MODE:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 6;
                pCamFeatureEnum->SupportItem[0] = CAM_STILL_CAPTURE_NORMAL;
                pCamFeatureEnum->SupportItem[1] = CAM_STILL_CAPTURE_BEST_SHOT;
                pCamFeatureEnum->SupportItem[2] = CAM_STILL_CAPTURE_CONT_SHOT;
                pCamFeatureEnum->SupportItem[3] = CAM_STILL_CAPTURE_BURST_SHOT;
                pCamFeatureEnum->SupportItem[4] = CAM_STILL_CAPTURE_EV_BRACKETING;
                pCamFeatureEnum->SupportItem[5] = CAM_STILL_CAPTURE_ADD_FRAME;

            break;

            case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;

                pCamFeatureEnum->IsSupport = KAL_TRUE;
                pCamFeatureEnum->ItemCount = 7;
                pCamFeatureEnum->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
                pCamFeatureEnum->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
                pCamFeatureEnum->SupportItem[2] = CAM_IMAGE_SIZE_1M;
                pCamFeatureEnum->SupportItem[3] = CAM_IMAGE_SIZE_2M;
                pCamFeatureEnum->SupportItem[4] = CAM_IMAGE_SIZE_3M;
                pCamFeatureEnum->SupportItem[5] = CAM_IMAGE_SIZE_4M;
                pCamFeatureEnum->SupportItem[6] = CAM_IMAGE_SIZE_5M;
            break;

            case CAL_FEATURE_CAMERA_BINNING_INFO:
                pFeatureOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
                pFeatureOut->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                                      CAL_FEATURE_GET_OPERATION|
                                                      CAL_FEATURE_QUERY_OPERATION;
                pFeatureOut->FeatureModeSupport = CAL_FEATURE_VIDEO_SUPPORT;

                for (i=CAM_ISO_AUTO;i<=CAM_ISO_400;i++)
                {
                    pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_5M;
                    pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_TRUE;
                    pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_FALSE;
                }
                for (;i<=CAM_ISO_1600;i++)
                {
                    pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_1M;
                    pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_TRUE;
                    pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_TRUE;
                }
            break;
            case CAL_FEATUER_CAMERA_CAPTURE_OVERLAY_CAPABILITY:
                pFeatureOut->FeatureInfo.FeatureStructured.pCamOverlayCap->CaptureOverlaySupport=KAL_FALSE;
            break;
            case CAL_FEATURE_CAMERA_QUERY_SW_ROTATE:
                pFeatureOut->FeatureInfo.FeatureStructured.pCamSwRotOutPara->RequireSwRotate=KAL_FALSE;
            break;
            default:
                pCamFeatureEnum->IsSupport = KAL_FALSE;
            break;
        }
    }
    else if (CAL_FEATURE_GET_OPERATION==pFeatureIn->FeatureCtrlCode)
    {
        switch (pFeatureIn->FeatureId)
        {
            case CAL_FEATURE_CAMERA_GET_JPEG_SIZE_ESTIMATION:
                pFeatureOut->FeatureCurrentValue=0x100000;
            break;
            default:
                pFeatureOut->FeatureCurrentValue=0;
            break;
        }
    }

    return ErrorCode;
} /* CalModisFeatureCtrl() */

// for config.lib in MODIS
kal_bool CalTaskCreate(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct CalHandlerInfo =
    {
        NULL,    /* task entry function */
        NULL,    /* task initialization function */
        NULL,           /* task configuration function */
        NULL,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & CalHandlerInfo;

    return KAL_TRUE;
}

// for config.lib in MODIS
kal_bool CalLowTaskCreate(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct CalLowHandlerInfo =
    {
        NULL,    /* task entry function */
        NULL,    /* task initialization function */
        NULL,           /* task configuration function */
        NULL,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & CalLowHandlerInfo;

    return KAL_TRUE;
}   /* CalLowTaskReset() */

// for config.lib in MODIS
kal_bool CalHighTaskCreate(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct CalHighHandlerInfo =
    {
        NULL,    /* task entry function */
        NULL,    /* task initialization function */
        NULL,           /* task configuration function */
        NULL,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & CalHighHandlerInfo;

    return KAL_TRUE;
}   /* CalHighTaskReset() */

// for gfx_drv.lib in MODIS
void exif_update_MTK_para_struct(void *para)
{

}
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

