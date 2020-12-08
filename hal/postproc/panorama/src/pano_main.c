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
 *  pano_main.c
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   This file is intends for Panorama Control Interface.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "pp_comm_def.h"
#include "mm_comm_def.h"
#include "pano_if.h"
#if defined(__PANORAMA_VIEW_SUPPORT__)
#include "pp_if.h"
#include "pano_core.h"
#include "pano_comm_def.h"
#include "utility_comm_def.h"
#include "jaia_mem.h"
#include "feature_comm_def.h"
#include "pp_mem_def.h"
#include "fsal.h"

#define PANO_PROCESS_MAX_COUNT      (32)  /* process times */
#define PANO_PROCESS_MAX_TIME		(250)
PANO_RESULT_STRUCT PanoResult = {0};
PANO_STATUS_ENUM PanoState = PANO_STATE_IDLE;
PANO_STATE_ENUM pano_operation_state=PANO_IDLE_STATE;
PANO_STATE_ENUM pano_operation_backup_state=PANO_RESET_STATE;
kal_uint32 pano_operation_number=0;
panoinfo_struct pano_info_data = {0};
kal_bool gPanoStitchFlag = KAL_FALSE;
kal_uint32	gSnapShotNumber = 0;
kal_bool gSwitchCacheableFlag = KAL_FALSE;

//#define PANO_TIME_LOG_ENABLE
#ifdef PANO_TIME_LOG_ENABLE
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);
#define CAMERA_PANO_TIME_MAX  (40)
kal_uint32  camera_pano_time_log[CAMERA_PANO_TIME_MAX][3], camera_pano_time_idx=0;
#endif

#ifdef PANO_LOG_DEBUG_INFO
kal_uint32 gPanoLogBuffer = 0;
#endif

MM_ERROR_CODE_ENUM (* pfPpPanoCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);

/* panorama config */
void PanoConfig(PANO_SET_PROC_INFO_STRUCT *pPanoData)
{
    PANO_GET_INFO_STRUCT PanoGetInfo;
    UTL_SWITCH_CACHE_STRUCT CacheSwitch;
    UTL_SWITCH_CACHE_RESULT_STRUCT CacheSwitchResult;
    PanoCoreGetInfo(&PanoGetInfo);
    
    if (pPanoData->PanoCtrl == PANO_CTRL_ADD_IMAGE)
    {
        CacheSwitch.pMemAddr = &pPanoData->WorkingBufAddr;
        CacheSwitch.Size = PanoGetInfo.AddImageWorkingBufSize+JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE;
        CacheSwitch.CacheableFlag = KAL_TRUE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE, &CacheSwitch, &CacheSwitchResult, sizeof(UTL_SWITCH_CACHE_RESULT_STRUCT));
        gSwitchCacheableFlag = CacheSwitchResult.Ret;

        pano_info_data.work_mem_addr = pPanoData->WorkingBufAddr;
        pano_info_data.work_mem_size = PanoGetInfo.AddImageWorkingBufSize;
        pano_info_data.jpeg_dec_ext_mem_addr = pPanoData->WorkingBufAddr+PanoGetInfo.AddImageWorkingBufSize;
        pano_info_data.jpeg_dec_ext_mem_size = JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE;
        ASSERT(pPanoData->WorkingBufSize>=PanoGetInfo.AddImageWorkingBufSize+JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE);
        
		if (PANO_RESET_STATE != pano_operation_state)
        {
			/* fill panoinfo struct */
			gSnapShotNumber++;
			if (pano_info_data.snapshot_number < PANO_MAX_IMG_NUM)
			{
				pano_info_data.image_src_buffer_addr[gSnapShotNumber-1] = (kal_uint8*)pPanoData->SrcImgAddr; 
				pano_info_data.image_src_buffer_size[gSnapShotNumber-1] = pPanoData->SrcImgSize; 
			}
			else
			{
				ASSERT(0);
			}
		}
    }
    else if (pPanoData->PanoCtrl == PANO_CTRL_STITCH)
    {
        CacheSwitch.pMemAddr = &pPanoData->WorkingBufAddr;
        CacheSwitch.Size = PanoGetInfo.StitchWorkingBufSize+JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE;
        CacheSwitch.CacheableFlag = KAL_TRUE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE, &CacheSwitch, &CacheSwitchResult, sizeof(UTL_SWITCH_CACHE_RESULT_STRUCT));
        gSwitchCacheableFlag = CacheSwitchResult.Ret;
        
        pano_info_data.work_mem_addr = pPanoData->WorkingBufAddr;
        pano_info_data.work_mem_size = PanoGetInfo.StitchWorkingBufSize;

        pano_info_data.jpeg_dec_ext_mem_addr = pPanoData->WorkingBufAddr+PanoGetInfo.StitchWorkingBufSize;
        pano_info_data.jpeg_dec_ext_mem_size = JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE;  
        ASSERT(pPanoData->WorkingBufSize>=PanoGetInfo.StitchWorkingBufSize+JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE);
        
        gPanoStitchFlag = KAL_TRUE;

    }
    else
    {
        ASSERT(0);
    }
}

PANO_STATE_ENUM PanoProcess(void)
{
    kal_uint32  i, next_proc_time, total_time=0;
    kal_uint32  start_time = drv_get_current_time();
    PANO_STATE_ENUM ret_state;


    for(i=0;i<PANO_PROCESS_MAX_COUNT;i++)
    {   /* pano process, and get next evaluated process time */
        next_proc_time = PanoCoreProcess();
        total_time = drv_get_duration_ms(start_time) + next_proc_time;
        if(0==next_proc_time)
        {
            if( pano_operation_number < gSnapShotNumber )
            {   /* add pano frames for algorithm */
                pano_operation_number++;
                pano_info_data.snapshot_number = pano_operation_number;
                PanoCoreAddImage(&pano_info_data);
                pano_operation_state = PANO_ADD_IMAGE_STATE;
            }
            else if(PANO_ADD_IMAGE_STATE == pano_operation_state)
            {
                pano_operation_state = PANO_ADD_IMAGE_READY_STATE;
            }
            else if(PANO_STITCH_STATE == pano_operation_state)
            {
                pano_operation_state = PANO_STITCH_READY_STATE;
            }
            else if( KAL_TRUE == gPanoStitchFlag )
            {   /* pano init */
                PanoCoreStitch(&pano_info_data);
                pano_operation_state = PANO_STITCH_STATE;
            }
            else
            {
                // not reach here
                ASSERT(0);
            }
            break;
        }
        else if(total_time>=PANO_PROCESS_MAX_TIME)
        {
            break;
        }
    }
	ret_state = pano_operation_state;
#ifdef PANO_TIME_LOG_ENABLE   
    if(camera_pano_time_idx<CAMERA_PANO_TIME_MAX)
    {
        camera_pano_time_log[camera_pano_time_idx][0] = start_time;
        camera_pano_time_log[camera_pano_time_idx][1] = (drv_get_current_time()-start_time)*1000/32768;
        camera_pano_time_log[camera_pano_time_idx][2] = pano_operation_state;
        camera_pano_time_idx++;
    }
#endif
    return ret_state;
}

/* get result */
P_PANO_RESULT_STRUCT PanoGetResult(void)
{
    kal_uint32  start_time = drv_get_current_time();
    PANO_GET_INFO_STRUCT PanoGetInfo;
    UTL_SWITCH_CACHE_STRUCT CacheSwitch;
    UTL_SWITCH_CACHE_RESULT_STRUCT CacheSwitchResult;
    PanoCoreGetInfo(&PanoGetInfo);


    if (PANO_STITCH_READY_STATE!=pano_operation_state)
    {
        ASSERT(0);
    }
    PanoCoreGetResult(&PanoResult);
    
    /* restore resion to non-cachable for jpeg encode */
    if(KAL_TRUE == gSwitchCacheableFlag)
    {
        CacheSwitch.pMemAddr = &pano_info_data.work_mem_addr;
        CacheSwitch.Size = PanoGetInfo.StitchWorkingBufSize+JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE;
        CacheSwitch.CacheableFlag = KAL_FALSE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE, &CacheSwitch, &CacheSwitchResult, sizeof(UTL_SWITCH_CACHE_RESULT_STRUCT));
        ASSERT(KAL_TRUE == CacheSwitchResult.Ret);
    }
    PanoResult.ImgBufferAddr = pano_info_data.work_mem_addr;
#ifdef PANO_TIME_LOG_ENABLE    
    if(camera_pano_time_idx<CAMERA_PANO_TIME_MAX)
    {
        camera_pano_time_log[camera_pano_time_idx][0] = start_time;
        camera_pano_time_log[camera_pano_time_idx][1] = (drv_get_current_time()-start_time)*1000/32768;
        camera_pano_time_log[camera_pano_time_idx][2] = pano_operation_state;
        camera_pano_time_idx++;
    }
#endif  
    return &PanoResult;
}

void PanoPause(void)
{
    pano_operation_backup_state = pano_operation_state;
    pano_operation_state = PANO_RESET_STATE;
    PanoCorePause();
}

void PanoResume(void)
{
    PANO_RESUME_STATE_ENUM State;
    State = PanoCoreResume(&pano_info_data);
    if (PANO_RESUME_ADD_IMAGE_STATE == State)
    {
        pano_operation_state = PANO_ADD_IMAGE_STATE;
    }
    else if (PANO_RESUME_STITCH_STATE == State)
    {
        pano_operation_state = PANO_STITCH_STATE;
    }
    else
    {
        ASSERT(0);
    }
}

void PanoExit(void)
{
    /* exit pano algorithm */
    PanoCoreExit();

    /* back to IDLE state */
    pano_operation_state = PANO_IDLE_STATE;
    gPanoStitchFlag = KAL_FALSE;
    pano_operation_number = 0;
    gSnapShotNumber = 0;
    pano_info_data.snapshot_number = 0;
    /* reset parameters */
#ifdef PANO_TIME_LOG_ENABLE
    camera_pano_time_idx = 0;
#endif
}

/* pano save log process */
void PanoSaveLog(void)
{
#ifdef PANO_LOG_DEBUG_INFO
    kal_wchar PanoFilename[100];			
    STFSAL FileHandle;
    kal_int32 driver;
    char *log_buff = (char*)gPanoLogBuffer;
    if (gPanoStitchFlag && (gPanoLogBuffer!=0))
    {
        kal_wsprintf(PanoFilename, "C:\\Photos\\pano_%d.csv", drv_get_current_time());
        /* save to mem card if avaliable */
        driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE); 
        if ((FS_PARAM_ERROR == driver) || (FS_DRIVE_NOT_FOUND == driver))
        {   /* save to phone if mem card is not found */
            driver = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
            if ((FS_PARAM_ERROR == driver) || (FS_DRIVE_NOT_FOUND == driver))
            {   /* phone driver must be found */
                ASSERT(0);
            }
        }
        PanoFilename[0] = driver;
        
        if (FSAL_OK != FSAL_Open(&FileHandle, PanoFilename, FSAL_WRITE))
        {  
            return;
        }
        
        /* guard pattern */
        *(log_buff + PANO_LOG_BUFFER_SIZE - 4) = '5';
        *(log_buff + PANO_LOG_BUFFER_SIZE - 3) = 'a';
        *(log_buff + PANO_LOG_BUFFER_SIZE - 2) = '5';
        *(log_buff + PANO_LOG_BUFFER_SIZE - 1) = 'a';
        
        PanoCoreSaveLog(log_buff);
        
        /* check pattern */
        if ((*(log_buff + PANO_LOG_BUFFER_SIZE - 4) != '5')||
            (*(log_buff + PANO_LOG_BUFFER_SIZE - 3) != 'a') ||
            (*(log_buff + PANO_LOG_BUFFER_SIZE - 2) != '5')||
            (*(log_buff + PANO_LOG_BUFFER_SIZE - 1) != 'a'))
        {
            ASSERT(0);
        } 

        FSAL_Write(&FileHandle, (kal_uint8*)log_buff, strlen(log_buff) + 1);
        FSAL_Close(&FileHandle);
    }
#endif
}


MM_ERROR_CODE_ENUM PanoOpen(void)
{
    PanoState = PANO_STATE_STANDBY;
    return MM_ERROR_NONE;
} /* PanoOpen() */

MM_ERROR_CODE_ENUM PanoClose(void)
{
    PanoState = PANO_STATE_IDLE;
    return MM_ERROR_NONE;
} /* PanoClose() */

MM_ERROR_CODE_ENUM PanoFeatureCtrl(PANO_FEATURE_ENUM FeatureId,
                                                        void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
    P_PANO_ENV_INFO_STRUCT pPanoEnvInfo = (P_PANO_ENV_INFO_STRUCT) pParaIn;
    P_PANO_SET_PROC_INFO_STRUCT pPanoSetProcInfo = (P_PANO_SET_PROC_INFO_STRUCT)pParaIn;
    P_PANO_GET_INFO_STRUCT pPanoGetInfo = (P_PANO_GET_INFO_STRUCT) pParaOut;
    P_PANO_RESULT_STRUCT pPanoGetResult = (P_PANO_RESULT_STRUCT) pParaOut;
    PP_STATE_ENUM* pPanoCheckState = (PP_STATE_ENUM*) pParaOut;
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

    switch (FeatureId)
    {
    case PANO_FEATURE_GET_ENV_INFO:
        PanoCoreGetInfo(pPanoGetInfo);
        break;
    case PANO_FEATURE_SET_ENV_INFO:
        PanoCoreSetInfo(pPanoEnvInfo);
        break;
    case PANO_FEATURE_SET_PROC_INFO:
    	PanoConfig(pPanoSetProcInfo);
    	break;
    case PANO_FEATURE_GET_STATE:
    	if((PANO_STATE_STITCH_DONE == PanoState) || (PANO_STATE_READY == PanoState)
    	    || (PANO_STATE_IDLE == PanoState))
    	{
    		*pPanoCheckState=PP_STATE_READY;
    	}
    	else
    	{
    		*pPanoCheckState=PP_STATE_BUSY;
    	}
    break;
    case PANO_FEATURE_SET_LOG_INFO:
#ifdef PANO_LOG_DEBUG_INFO
        gPanoLogBuffer = *(kal_uint32*)pParaIn;
#endif
        if (pParaOut) *(kal_uint32*)pParaOut = PANO_LOG_BUFFER_SIZE;
        break;
    case PANO_FEATURE_GET_RESULT:
        kal_mem_cpy(pPanoGetResult, &PanoResult, sizeof(PANO_RESULT_STRUCT));
        break;
    default:
        break;
    }
    return ErrorCode;
} /* PanoFeatureControl() */

MM_ERROR_CODE_ENUM PanoCtrl(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,
							void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
    PANO_STATE_ENUM PanoAlgoState;
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

    if((PP_CTRL_CODE_START == CtrlCode) || (PP_CTRL_CODE_RESUME == CtrlCode))
    {
            if (PanoState == PANO_STATE_PAUSE)
            {
                PanoResume();
            }
		PanoAlgoState = PanoProcess();
		/* background stitch process for current frame is finished */
		if (PANO_ADD_IMAGE_READY_STATE == PanoAlgoState)
		{
			PanoState = PANO_STATE_READY;
			// cb to cal
			pfPpPanoCb(PP_CBID_PANO_BG_STITCH_READY, (void*)pano_operation_number, sizeof(pano_operation_number));
		}
		else if (PANO_STITCH_READY_STATE == PanoAlgoState)
		{
			PanoState = PANO_STATE_STITCH_DONE;
			PanoGetResult();
			// cb to cal
			pfPpPanoCb(PP_CBID_PANO_RESULT, &PanoResult, sizeof(PANO_RESULT_STRUCT));
#ifdef PANO_LOG_DEBUG_INFO
			PanoSaveLog();
#endif
		}
		else if (PANO_ADD_IMAGE_STATE == PanoAlgoState)
		{
			PanoState = PANO_STATE_BGSTITCH;
		}
		else if (PANO_STITCH_STATE == PanoAlgoState)
		{
			PanoState = PANO_STATE_PROCESSING;
		}
		else
		{
			/* should not reach here */
			ASSERT(0);  
			ErrorCode = MM_ERROR_INVALID_PARAMETER;
		}
    }
    else if (PP_CTRL_CODE_STOP == CtrlCode)
    {
        PanoExit();
        PanoState = PANO_STATE_STANDBY;
        PP_SET_EVENT(PP_EVENT_PANO_STOP_CNF);
    }
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
/* under construction !*/
/* under construction !*/
    #endif
    else if (PP_CTRL_CODE_PAUSE == CtrlCode)
    {
        if (PanoState != PANO_STATE_PAUSE)
        {
            PanoPause();
            PanoState = PANO_STATE_PAUSE;
            PP_SET_EVENT(PP_EVENT_PANO_PAUSE_CNF);
        }
        else
        {
            /* should not reach here */
            ASSERT(0);
            ErrorCode = MM_ERROR_INVALID_PARAMETER;
        }
    }
    else
    {
        ASSERT(0);
        ErrorCode = MM_ERROR_INVALID_PARAMETER;
    }

    return ErrorCode;
} /* PanoControl() */

PANO_FUNCTION_STRUCT PanoFuncMap=
{
    PanoOpen,
    PanoFeatureCtrl,
    PanoCtrl,
    PanoClose
};

MM_ERROR_CODE_ENUM PanoInit(MM_ERROR_CODE_ENUM (* pfPanoCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_PANO_FUNCTION_STRUCT *pfPanoFunc)
{
    pfPpPanoCb = pfPanoCallback;	
    *pfPanoFunc=&PanoFuncMap;
    return MM_ERROR_NONE;
} /* PanoInit() */

#else   /*#if defined(__PANORAMA_VIEW_SUPPORT__)*/

MM_ERROR_CODE_ENUM PanoInit(MM_ERROR_CODE_ENUM (* pfPanoCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_PANO_FUNCTION_STRUCT *pfPanoFunc)
{
    return MM_ERROR_NONE;
} /* PanoInit() */
#endif

