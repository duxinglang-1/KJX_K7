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
 *   cal_profiling.c
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
 ****************************************************************************/
#include "kal_release.h"
#include "cal_comm_def.h"
#include "cal_api.h"
#include "cal_if.h"
#include "cal_drv_features.h"
#include "drv_trc.h"
#include "pp_api.h"

#ifdef __CAL_PROFILING_ENABLE__    

typedef enum
{
    CAL_CP_LOGGING_ENABLE_STATE,
    CAL_CP_LOGGING_DISABLE_STATE,
    CAL_CP_LOGGING_BUSY_STATE,
} CAL_CP_STATE_ENUM;

static CAL_CP_STATE_ENUM CpState = CAL_CP_LOGGING_ENABLE_STATE;     ///not used at present

#define MAX_CAMERA_PROFILING_LOG_NO 100
#define MAX_CAMERA_PROFILING_WORKING_MEM_SIZE 40

kal_uint32 CpTickBuffer[MAX_CAMERA_PROFILING_LOG_NO];
CAL_CAMERA_PROFILING_LOG_ENUM CpLogIdBuffer[MAX_CAMERA_PROFILING_LOG_NO];
kal_uint32 CpLogIndex = 0;

kal_bool CpFirstPreviewFlag=KAL_FALSE;
kal_uint8 CpCaptureCount = 0;
kal_uint32 CpPreviewFramerate = 0;
kal_uint32 CpCaptureFramerate = 0;
extern IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT SensorScenarioParaIn;

///For ISP feature control
CAL_FEATURE_CTRL_STRUCT CpFeatureInStruct;
CAL_FEATURE_CTRL_STRUCT CpFeatureOutStruct;


static kal_uint32 CalProfilingGetDurationMs(kal_uint32 index)
{
	kal_uint32 result;
    kal_uint64 temp_value;

    if(index == 0)
        return 0;

	result = drv_get_duration_tick(CpTickBuffer[index-1], CpTickBuffer[index]);
	/* X ms = result x 1000/32K = (result x 125)>>12 */
	temp_value = (kal_uint64)(((kal_uint64) result)*125);
	result = (kal_uint32)(temp_value>>12);
	return result;
}


MM_ERROR_CODE_ENUM CalProfilingFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                     P_CAL_FEATURE_CTRL_STRUCT pFeatureOut,
                                     kal_uint32 FeatureOutLen, kal_uint32 *pRealFeatureOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (pFeatureIn->FeatureId)
    {
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
#endif
        case CAL_FEATURE_CAMERA_PROFILING_GET_APPEND_INFO:
            if (CAL_CP_LOGGING_ENABLE_STATE == CpState)
            {
                P_CAL_FEATURE_CAMERA_PROFILING_GET_APPEND_INFO_STRUCT pAppendInfoStruct = pFeatureOut->FeatureInfo.FeatureStructured.pCamProfilingGetAppendInfoStruct;

                ASSERT(pAppendInfoStruct != NULL);
                /// fill the info for file naming
                pAppendInfoStruct->SceneMode = SensorScenarioParaIn.NightMode;
                pAppendInfoStruct->ZoomStep = CurrentZoomInfo.CurrentZoomFactor;
                pAppendInfoStruct->ShotNumber= CpCaptureCount;
            }
            break;


        case CAL_FEATURE_CAMERA_PROFILING_GET_RESULT:
            if (CAL_CP_LOGGING_ENABLE_STATE == CpState)
            {
                P_CAL_FEATURE_CAMERA_PROFILING_GET_RESULT_STRUCT pResultStruct = pFeatureOut->FeatureInfo.FeatureStructured.pCamProfilingGetResultStruct;
                char *pResultBufferAddr = (char *)pResultStruct->ResultBufferAddr;
                kal_uint32 ResultBufferSize = pResultStruct->ResultBufferSize;
                CAL_CAMERA_PROFILING_LOG_ENUM *pLogIdBuffer = CpLogIdBuffer;
                kal_uint32 *pProfilingTickBuffer = CpTickBuffer;
                char *WorkingBuffer = pResultBufferAddr + ResultBufferSize -MAX_CAMERA_PROFILING_WORKING_MEM_SIZE;
                kal_uint8   i = CpLogIndex;
                kal_uint8 CpLogIndexBak;


                //logging CAL_CAMERA_PROFILING_BEFORE_SAVE_FILE
                CpLogIdBuffer[CpLogIndex] = CAL_CAMERA_PROFILING_BEFORE_SAVE_FILE;
                CpTickBuffer[CpLogIndex] = drv_get_current_time();
                CpLogIndex++;
                
                /* check length */
                if (MAX_CAMERA_PROFILING_WORKING_MEM_SIZE >=  ResultBufferSize)
                {
                    ASSERT(0);
                }
                
                memset(pResultBufferAddr, 0, ResultBufferSize);
                
                /* guard pattern */
                *(pResultBufferAddr + ResultBufferSize - 4) = '5';
                *(pResultBufferAddr + ResultBufferSize - 3) = 'a';
                *(pResultBufferAddr + ResultBufferSize - 2) = '5';
                *(pResultBufferAddr + ResultBufferSize - 1) = 'a';

                #if defined(DRV_ISP_6235_SERIES)		
                sprintf(pResultBufferAddr, "MT6235\n");  ///TODO  Is there a better way to get this string ?
                #elif  defined(DRV_ISP_6238_SERIES)		
                sprintf(pResultBufferAddr, "MT6238\n");  ///TODO 
                #elif  defined(DRV_ISP_6276_SERIES)     
                sprintf(pResultBufferAddr, "MT6276\n");  ///TODO 
                #else
                sprintf(pResultBufferAddr, "MTxxxx\n");  ///TODO 
                #endif
                sprintf(WorkingBuffer, "Zoom,%d\n", CurrentZoomInfo.CurrentZoomFactor);      //TODO  temp solution
                strcat(pResultBufferAddr, WorkingBuffer);
                sprintf(WorkingBuffer, "Night,%d\n", SensorScenarioParaIn.NightMode);        //TODO
                strcat(pResultBufferAddr, WorkingBuffer);

                sprintf(WorkingBuffer, "Shot no,%d\n", CpCaptureCount);        
                strcat(pResultBufferAddr, WorkingBuffer);
                sprintf(WorkingBuffer, "%d,%d\n",
                    0,                                         ///Bin: different with current design!!!
                    CpPreviewFramerate);     
                strcat(pResultBufferAddr, WorkingBuffer);
                sprintf(WorkingBuffer, "%d,%d\n",
                    0,
                    CpCaptureFramerate);     
                strcat(pResultBufferAddr, WorkingBuffer);
                
                while (i >= 1)
                {
                    sprintf(WorkingBuffer, "%d,%d\n", *pLogIdBuffer, *pProfilingTickBuffer);      
                    strcat(pResultBufferAddr, WorkingBuffer);
                    pLogIdBuffer++;
                    pProfilingTickBuffer++;
                    i--;
                }
            
                strcat(pResultBufferAddr, "\0");

                pResultStruct->ResultBufferOutputSize = strlen(pResultBufferAddr) + 1;
                
                /* check pattern */
                if ((*(pResultBufferAddr + ResultBufferSize - 4) != '5')||
                    (*(pResultBufferAddr + ResultBufferSize - 3) != 'a') ||
                    (*(pResultBufferAddr + ResultBufferSize - 2) != '5')||
                    (*(pResultBufferAddr + ResultBufferSize - 1) != 'a'))
                {
                    ASSERT(0);
                }   
            
                memset(WorkingBuffer, 0, MAX_CAMERA_PROFILING_WORKING_MEM_SIZE);       

                //logging CAL_CAMERA_PROFILING_SAVE_FILE_DONE
                CpLogIndexBak = CpLogIndex - 1;
                CpLogIdBuffer[0]= CpLogIdBuffer[CpLogIndex-1];
                CpTickBuffer[0] = CpTickBuffer[CpLogIndex-1];
                CpLogIdBuffer[CpLogIndex-1] = CAL_CAMERA_PROFILING_NULL;    ///clear the unused info
                CpTickBuffer[CpLogIndex-1] = 0;
                CpLogIdBuffer[1] = CAL_CAMERA_PROFILING_SAVE_FILE_DONE;
                CpTickBuffer[1] = drv_get_current_time();
                CpLogIndex = 2;
                {
                    kal_trace(TRACE_INFO,CAL_PROFILING_ZOOM_FACTOR,CurrentZoomInfo.CurrentZoomFactor);
                    kal_trace(TRACE_INFO,CAL_PROFILING_NIGHT_MODE,SensorScenarioParaIn.NightMode);
                    kal_trace(TRACE_INFO,CAL_PROFILING_CAPTURE_COUNT,CpCaptureCount);
                    kal_trace(TRACE_INFO,CAL_PROFILING_PREVIEW_FPS,CpPreviewFramerate);
                    kal_trace(TRACE_INFO,CAL_PROFILING_CAPTURE_FPS,CpCaptureFramerate);

                    kal_trace(TRACE_INFO,CAL_PROFILING_LOG, 0, CpLogIdBuffer[0]);                                /// CAL_CAMERA_PROFILING_BEFORE_SAVE_FILE
                    kal_trace(TRACE_INFO,CAL_PROFILING_LOG, CalProfilingGetDurationMs(1), CpLogIdBuffer[1]);     /// CAL_CAMERA_PROFILING_SAVE_FILE_DONE
                    kal_trace(TRACE_INFO,CAL_PROFILING_LOG, 0, CpLogIdBuffer[2]);                                /// CAL_CAMERA_PROFILING_ENTER_CAMERA_PREVIEW

                    for(i=3;i<CpLogIndexBak;i++)
                    {
                        kal_trace(TRACE_INFO,CAL_PROFILING_LOG, CalProfilingGetDurationMs(i), CpLogIdBuffer[i]);
                    }
                }
            }
            else
            {
                EXT_ASSERT(0, CpState, 0, 0);
            }
            break;
            
        case CAL_FEATURE_CAMERA_PROFILING_LOG_EVENT:
            if (CAL_CP_LOGGING_ENABLE_STATE == CpState)
            {
                P_CAL_FEATURE_CAMERA_PROFILING_LOG_EVENT_STRUCT pLogPara = pFeatureIn->FeatureInfo.FeatureStructured.pCamPrrofilingLogPara;
                kal_uint32 CurrTime = drv_get_current_time();
                
                #if defined(ISP_SUPPORT)
                if (CAL_CAMERA_PROFILING_EXIT_CAMERA_PREVIEW == pLogPara->LogId)
                {
                    CpFeatureInStruct.FeatureId = CAL_FEATURE_CAMERA_GET_FRAME_RATE;
                    CpFeatureInStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    ErrorCode = pfIspFunc->IspFeatureCtrl(CAL_FEATURE_CAMERA_GET_FRAME_RATE, &CpFeatureInStruct, &CpFeatureOutStruct, sizeof(CpFeatureOutStruct), NULL);
                    ASSERT(ErrorCode == MM_ERROR_NONE);
                    CpPreviewFramerate = CpFeatureOutStruct.FeatureCurrentValue;
                }
                else if(CAL_CAMERA_PROFILING_CONFIG_WAIT_STABLE_COMPLETE == pLogPara->LogId)
                {
                    CpFeatureInStruct.FeatureId = CAL_FEATURE_CAMERA_GET_FRAME_RATE;
                    CpFeatureInStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
                    ErrorCode = pfIspFunc->IspFeatureCtrl(CAL_FEATURE_CAMERA_GET_FRAME_RATE, &CpFeatureInStruct, &CpFeatureOutStruct, sizeof(CpFeatureOutStruct), NULL);
                    ASSERT(ErrorCode == MM_ERROR_NONE);
                    CpCaptureFramerate = CpFeatureOutStruct.FeatureCurrentValue;
                }
                #endif
                
                /* key press */
                if (KAL_TRUE == CpFirstPreviewFlag)     
                {
                    /* reset record when save done */
                    if (CAL_CAMERA_PROFILING_SAVE_FILE_DONE == pLogPara->LogId)
                    {
                        CpLogIdBuffer[0]= CpLogIdBuffer[CpLogIndex-1];
                        CpTickBuffer[0] = CpTickBuffer[CpLogIndex-1];
                        CpLogIdBuffer[CpLogIndex-1] = CAL_CAMERA_PROFILING_NULL;    ///clear the unused info
                        CpTickBuffer[CpLogIndex-1] = 0;
                        CpLogIdBuffer[1] = pLogPara->LogId;
                        CpTickBuffer[1] = CurrTime;
                        CpLogIndex = 2;
                    }
                    else
                    {
                        if (CpLogIndex >= MAX_CAMERA_PROFILING_LOG_NO)
                        {
                            CpLogIndex = 0;  
                        }
                        CpLogIdBuffer[CpLogIndex] = pLogPara->LogId;
                        CpTickBuffer[CpLogIndex] = CurrTime;
                        CpLogIndex++;
                        
                        /* set flag */
                        if (CAL_CAMERA_PROFILING_CAMERA_PREVIEW_COMPLETE == pLogPara->LogId)
                        {
                            CpFirstPreviewFlag = KAL_FALSE;      
                        }
                        else if(CAL_CAMERA_PROFILING_CAMERA_CAPTURE_COMPLETE == pLogPara->LogId)
                        {
                            CpCaptureCount++;/* count of capture no */                            
                        }
                    }
                }
                else
                {
                    if (CAL_CAMERA_PROFILING_ENTER_CAMERA_PREVIEW == pLogPara->LogId)
                    {
                        CpLogIdBuffer[2] = CAL_CAMERA_PROFILING_ENTER_CAMERA_PREVIEW;
                        CpTickBuffer[2] = CurrTime;
                        CpLogIndex = 3;          
                    }
                    else
                    {
                        if (CAL_CAMERA_PROFILING_CAPTURE_KEY_PRESS == pLogPara->LogId) 
                        {
                            CpFirstPreviewFlag = KAL_TRUE;
                            CpCaptureCount = 0;               
                        }
                        else if (CAL_CAMERA_PROFILING_ENTER_CAPTURE == pLogPara->LogId)
                        {
                            CpFirstPreviewFlag = KAL_TRUE;
                        }
                        if (CpLogIndex >= MAX_CAMERA_PROFILING_LOG_NO)
                        {
                            CpLogIndex = 0;  
                        }
                        CpLogIdBuffer[CpLogIndex] = pLogPara->LogId;
                        CpTickBuffer[CpLogIndex] = CurrTime;
                        CpLogIndex++;
                    }
                }   
            }else if(CAL_CP_LOGGING_BUSY_STATE == CpState)
            {
                ASSERT(0);
            }
        break;
        default:
        break;
    }
    return ErrorCode;
}   /* CalProfilingFeatureCtrl() */



//////////////Internal used only///////////////////
void CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_LOG_ENUM LogId)
{
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    CAL_FEATURE_CAMERA_PROFILING_LOG_EVENT_STRUCT CalProfileLog;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalInPara.FeatureId = CAL_FEATURE_CAMERA_PROFILING_LOG_EVENT;   
    CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    CalInPara.FeatureType = CAL_FEATURE_TYPE_STRUCTURED;
    CalProfileLog.LogId = LogId;
    CalInPara.FeatureInfo.FeatureStructured.pCamPrrofilingLogPara = &CalProfileLog;
    CalProfilingFeatureCtrl((void*)&CalInPara, NULL, NULL, NULL);
}

#else       //__CAL_PROFILING_ENABLE__
MM_ERROR_CODE_ENUM CalProfilingFeatureCtrl(P_CAL_FEATURE_CTRL_STRUCT pFeatureIn,
                                     P_CAL_FEATURE_CTRL_STRUCT pFeatureOut,
                                     kal_uint32 FeatureOutLen, kal_uint32 *pRealFeatureOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (pFeatureIn->FeatureId)
    {
        /// implement this, because MED need this info to determine file name
        case CAL_FEATURE_CAMERA_PROFILING_GET_APPEND_INFO:
            {
                P_CAL_FEATURE_CAMERA_PROFILING_GET_APPEND_INFO_STRUCT pAppendInfoStruct = pFeatureOut->FeatureInfo.FeatureStructured.pCamProfilingGetAppendInfoStruct;
        
                ASSERT(pAppendInfoStruct != NULL);
                pAppendInfoStruct->SceneMode = 0;
                pAppendInfoStruct->ZoomStep = 0;
                pAppendInfoStruct->ShotNumber= 0;
            }
            break;

        default:
            break;
    }
    
    return ErrorCode;
}

void CameraCaptureProfilingWrapper(CAL_CAMERA_PROFILING_LOG_ENUM LogId)
{
}

#endif       //__CAL_PROFILING_ENABLE__
