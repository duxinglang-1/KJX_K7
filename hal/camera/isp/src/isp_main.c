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
 *   isp_main.c
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
 ****************************************************************************
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "cal_api.h"
#include "cal_if.h"

#include "mm_power_ctrl.h"
#include "isp_comm_def.h"

#include "isp_hw_feature_def.h"
#include "isp_if.h"
#include "isp_comm_if.h"
#include "sensor_comm_def.h"

#include "IntrCtrl.h"
#include "visualhisr.h"

#include "emi_sw.h" // for EMI_SetGMCBW();

#if (defined(__ATV_SUPPORT__)&& defined(__MTK_TARGET__))
#include "matv_process.h"
extern void MatvInitOperationPara(void);
#endif

extern IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT CurrentSensorInfo;

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif


kal_uint32 IspBakTgPhaseCountReg = 0x5a5a5a5a;
kal_uint32 IspBakSensorModeConfigReg = 0x5a5a5a5a;
kal_uint32 IspBakCameraModulePathConfigReg = 0x5a5a5a5a;
kal_uint32 IspBakProcessCtrlReg1= 0x5a5a5a5a;



MM_ERROR_CODE_ENUM (* pfCalIspCb) (CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);

ISP_OPERATION_STATE_ENUM IspOperationState=ISP_IDLE_STATE;
kal_uint32 SensorFeatureParaOutLen;
kal_bool IspFirstPreviewFlag = KAL_FALSE;
kal_bool IspIsDscSupportInfoQueried = KAL_FALSE;

extern void L1SM_SleepEnable( kal_uint8 handle );

MM_ERROR_CODE_ENUM IspCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pCtrlParaIn,
                            void *pCtrlParaOut, kal_uint32 CtrlParaOutLen,
                            kal_uint32 *pRealCtrlParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_ISP_SCENARIO_CTRL_STRUCT pIspScenarioCtrl=(P_ISP_SCENARIO_CTRL_STRUCT)pCtrlParaIn;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
    #endif
        {
            ErrorCode = IspYuvPreview(ScenarioId, pIspScenarioCtrl->ScenarioCtrlCode,
                            pIspScenarioCtrl->pScenarioCtrlPara, pIspScenarioCtrl->ScenarioCtrlParaLen);
        }
        break;
        
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    #if defined(__ZERO_SHUTTER_DELAY_SUPPORT__)
        case CAL_SCENARIO_CAMERA_ZSD_CAPTURE:
    #endif
        {
            ErrorCode = IspYuvStillCapture(ScenarioId, pIspScenarioCtrl->ScenarioCtrlCode,
                            pIspScenarioCtrl->pScenarioCtrlPara, pIspScenarioCtrl->ScenarioCtrlParaLen);
        }
        break;
        
        case CAL_SCENARIO_VIDEO:
    #ifdef __MEDIA_VT__
/* under construction !*/
    #endif
        {
            ErrorCode = IspYuvVideo(ScenarioId, pIspScenarioCtrl->ScenarioCtrlCode,
                            pIspScenarioCtrl->pScenarioCtrlPara, pIspScenarioCtrl->ScenarioCtrlParaLen);
        }
        break;
        
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:    
        {
    #ifdef WEBCAM_SUPPORT
            ErrorCode = IspWebcam(ScenarioId, pIspScenarioCtrl->ScenarioCtrlCode,
                            pIspScenarioCtrl->pScenarioCtrlPara, pIspScenarioCtrl->ScenarioCtrlParaLen);
    #endif
        }
        break;

    }
    return ErrorCode;
} /* IspCtrl() */

MM_ERROR_CODE_ENUM IspOpen(void)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;


    if(IspBakTgPhaseCountReg == 0x5a5a5a5a)
    {
        IspBakTgPhaseCountReg = REG_ISP_TG_PHASE_COUNTER;
    }
    if(IspBakSensorModeConfigReg == 0x5a5a5a5a)
    {
        IspBakSensorModeConfigReg = REG_ISP_CMOS_SENSOR_MODE_CONFIG;
    }
    if(IspBakCameraModulePathConfigReg == 0x5a5a5a5a)
    {
        IspBakCameraModulePathConfigReg = REG_ISP_PATH_CONFIG;
    }
    if(IspBakProcessCtrlReg1 == 0x5a5a5a5a)
    {
        IspBakProcessCtrlReg1= REG_ISP_PREPROCESS_CTRL1;
    }

    IspOperationState=ISP_STANDBY_STATE;

#ifdef __ATV_SUPPORT__
    if(CurrentCameraId != CAL_CAMERA_SOURCE_MATV)
#endif
        IspFirstPreviewFlag = KAL_TRUE;

#if (defined(DUAL_CAMERA_SUPPORT))
    if(CAL_CAMERA_SOURCE_MAIN==CustomDriverFunc.CameraId || CAL_CAMERA_SOURCE_SUB==CustomDriverFunc.CameraId)
#else
    if(CAL_CAMERA_SOURCE_MAIN==CustomDriverFunc.CameraId )
#endif
    {
        CameraInitOperationPara();
   
        InitIsp();
        IspCheckFirstVsync = KAL_TRUE;

    #if defined (YUV_MAIN_CAMERA) && defined (__AUTO_SCENE_DETECT_SUPPORT__)        
        if((ISP_YUV_SUPPORT == IspInputDataFormat) && (CAL_CAMERA_SOURCE_MAIN==CustomDriverFunc.CameraId))
        {
            SENSOR_AE_AWB_REF_STRUCT Sensor_Ae_Awb_Ref;
            ErrorCode = pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_GET_EV_AWB_REF, NULL, &Sensor_Ae_Awb_Ref, sizeof(SENSOR_AE_AWB_REF_STRUCT), &SensorFeatureParaOutLen);
            if (MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT != ErrorCode)
            {
                ErrorCode = IspFeatureCtrl(ISP_FEATURE_SET_3A_REF,&Sensor_Ae_Awb_Ref, NULL , 0, NULL);
            }                  
        }
    #endif
    }
#if (defined(__ATV_SUPPORT__)&& defined(__MTK_TARGET__))
    else if ( CAL_CAMERA_SOURCE_MATV==CustomDriverFunc.CameraId)
    {
        MatvInitOperationPara();
        InitIspMatv();
    }
#endif
 
    IspInitEvent();
    /*Init ISP interrupt service runtine */
    IspInitISR();
    ENABLE_CMOS_SENSOR;

    IRQSensitivity(IRQ_CAMERA_CODE,LEVEL_SENSITIVE);
    IRQUnmask(IRQ_CAMERA_CODE);            

    return ErrorCode;
} /* IspOpen() */

MM_ERROR_CODE_ENUM IspClose(void)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

#if defined( __RF_DESENSE_TEST__)

    kal_uint32 temp;

    if (IspOperationState!=ISP_STANDBY_STATE)
    {
        ASSERT(0);
    }

    IRQMask(IRQ_CAMERA_CODE);

    IspOperationState=ISP_IDLE_STATE;

    //isp_first_preview_frame=KAL_TRUE;

    L1SM_SleepEnable(IspSleepModeHandler);

    IspProcessStage|=LEAVE_POWER_OFF_ISP;

    kal_sleep_task(50);
    ENABLE_CMOS_SENSOR;
    ENABLE_REZ_DISCONN;
    ENABLE_VIEW_FINDER_MODE;

#if defined(__CAL_TRACE_ENABLE__)
    {
        kal_trace(TRACE_INFO,ISP_RFDESENSE_MCLK_PLK_BG_ON_YUV);		    	
        kal_trace(TRACE_INFO,ISP_RFDESENSE_CAM_REG0018_READ, temp);		    	
    }
#endif
    temp = REG_ISP_VIEW_FINDER_MODE_CTRL;

    return ErrorCode;
#endif

    if (IspOperationState!=ISP_STANDBY_STATE)
    {
        ASSERT(0);
    }

    POWER_OFF_CMOS_SENSOR;
    DISABLE_CMOS_SENSOR;
    REG_ISP_VIEW_FINDER_MODE_CTRL=0;	/* Clear ISP Pre/Cap Mode and disable view finder mode */
    IRQMask(IRQ_CAMERA_CODE);
    IspOperationState=ISP_IDLE_STATE;
    IspIsDscSupportInfoQueried=KAL_FALSE;

    /* Set Low to MCLK */
    if (CurrentSensorInfo.IsSensorDriverCtrlMclk == KAL_FALSE)
    {
        SET_CMOS_FALLING_EDGE(0);
        DISABLE_CAMERA_TG_PHASE_COUNTER;
        DISABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;
    }

    L1SM_SleepEnable(IspSleepModeHandler);

    IspProcessStage|=LEAVE_POWER_OFF_ISP;

    return ErrorCode;
} /* IspClose() */


ISP_FUNCTION_STRUCT IspFunc=
{
    IspOpen,
    IspFeatureCtrl,
    IspCtrl,
    IspClose,
};
   

MM_ERROR_CODE_ENUM IspInit(MM_ERROR_CODE_ENUM (* pfIspCallback) (CAL_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_ISP_FUNCTION_STRUCT *pfIspFunc)
{
    pfCalIspCb = pfIspCallback;
    *pfIspFunc=&IspFunc;

    IspOperationState = ISP_IDLE_STATE;

    IspPreviewConfigData.pCalIspPreviewPara = &CalIspPreviewData;
    
#if (defined(__ISP_MIPI_SENSOR_SUPPORT__))
    MipiInterfaceInit();
#endif

    return MM_ERROR_NONE;
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif


