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
*   autocap_main.c
*
* Project:
* --------
*   MT6236
*
* Description:
* ------------
*   Autocap process source file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "autocap_if.h"
#include "mm_comm_def.h"
#include "pp_comm_def.h"
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
#include "autocap_comm_def.h"
#include "pp_if.h"
#include "utility_comm_def.h"
#include "autocap_core.h"
#include "utility_core.h"

//#define AUTOCAP_LOG_DEBUG_INFO
#ifdef AUTOCAP_LOG_DEBUG_INFO
#include "fsal.h"
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);
static kal_wchar gAutocapLogFileName[30] = {'x', ':', '\\', '\\','A','U','T','O','C','A','P','L', 'O', 'G', '.', 't', 'x', 't', '\0'};
static char gAutocapLogBuffer[100000] = {'\0'};
static char gAutocapLogTempBuffer[100] = {'\0'};
static STFSAL gAutocapWriteLog;
typedef struct
{
    kal_uint32 captured_images;
    kal_uint32 processed_images;
    kal_uint32 memcpy_times;
    kal_uint32 accumulate_times;
    AUTOCAP_HINT_DIRECTION_ENUM hint_dir;

}AUTOCAP_TIME_MEASUREMENT_STRUCT, P_AUTOCAP_TIME_MEASUREMENT_STRUCT; 
static AUTOCAP_TIME_MEASUREMENT_STRUCT gAutoCapTimeMeasurement = {0,0,0,0};
static kal_uint32 gAutoCapTimeLog;
#define GET_TICK_COUNT(time_log) {*time_log = drv_get_current_time();}
#define GET_TICK_INTERVAL(time_log, interval) { (*interval) = (drv_get_current_time() - time_log); }
#define GET_ACCUM_TICK_INTERVAL(time_log, interval) { (*interval) += (drv_get_current_time() - time_log); }
static unsigned int gAutoCapFrameCount=0;
#endif

AUTOCAP_STATE_ENUM gAutoCapState = AUTOCAP_IDLE_STATE;
AUTOCAP_SET_MEM_INFO_STRUCT gAutoCapSetMemInfo;
AUTOCAP_SET_ENV_INFO_STRUCT gAutoCapSetEnvInfo;
AUTOCAP_GET_ENV_INFO_STRUCT gAutoCapGetEnvInfo;
AUTOCAP_RESULT_STRUCT gAutoCapResult;

kal_uint32 gAutoCapSrcImageWidth;
kal_uint32 gAutoCapSrcImageHeight;

MM_ERROR_CODE_ENUM (* pfPpAutoCapCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);

//enter preview called
MM_ERROR_CODE_ENUM AutoCapOpen(void)
{
    gAutoCapState=AUTOCAP_IDLE_STATE;
    return MM_ERROR_NONE;
}	/* AutoCapOpen() */


//leave preview called
MM_ERROR_CODE_ENUM AutoCapClose(void)
{
    gAutoCapState = AUTOCAP_IDLE_STATE;
    AutoCapCoreExit();
    return MM_ERROR_NONE;
}	/* AutoCapClose() */

MM_ERROR_CODE_ENUM AutoCapFeatureCtrl(AUTOCAP_FEATURE_ENUM FeatureId,
                                      void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{    

    P_AUTOCAP_SET_ENV_INFO_STRUCT pAutoCapSetEnvInfo = (P_AUTOCAP_SET_ENV_INFO_STRUCT)pParaIn;
    P_AUTOCAP_SET_MEM_INFO_STRUCT pAutCapSetMemInfo = (P_AUTOCAP_SET_MEM_INFO_STRUCT) pParaIn; 
    P_AUTOCAP_GET_ENV_INFO_STRUCT pAutoCapGetEnvInfo = (P_AUTOCAP_GET_ENV_INFO_STRUCT)pParaOut;

    P_AUTOCAP_RESULT_STRUCT pAutoCapResult = (P_AUTOCAP_RESULT_STRUCT) pParaOut;
    PP_STATE_ENUM* pAutoCapCheckState = (PP_STATE_ENUM*) pParaOut;	
    //UTL_SWITCH_CACHE_STRUCT MemSwitch;

    camera_autocap_init_struct autocap_init_struct;
    //camera_autocap_set_mem_struct autocap_set_mem_struct;

    switch (FeatureId)
    {
    case AUTOCAP_FEATURE_GET_ENV_INFO:

        pAutoCapGetEnvInfo->ImageWidth = AUTOCAP_IMAGE_XS;
        pAutoCapGetEnvInfo->ImageHeight = AUTOCAP_IMAGE_YS;
        pAutoCapGetEnvInfo->WorkingBufSize=(kal_uint32) (AUTOCAP_BUFFER_SIZE);
        pAutoCapGetEnvInfo->SrcImgFormat= gAutoCapSetEnvInfo.image_format;			

        break;

    case AUTOCAP_FEATURE_SET_ENV_INFO:	

        kal_mem_cpy(&gAutoCapSetEnvInfo, pAutoCapSetEnvInfo, sizeof(AUTOCAP_SET_ENV_INFO_STRUCT) );

        autocap_init_struct.image_width = AUTOCAP_IMAGE_XS;
        autocap_init_struct.image_height = AUTOCAP_IMAGE_YS;
        autocap_init_struct.lcd_width = pAutoCapSetEnvInfo->target_width;
        autocap_init_struct.lcd_height = pAutoCapSetEnvInfo->target_height;
        autocap_init_struct.log_enable = KAL_FALSE;
        autocap_init_struct.tolerance_x = pAutoCapSetEnvInfo->autocap_tuning_data.tolerance_x;
        autocap_init_struct.tolerance_y = pAutoCapSetEnvInfo->autocap_tuning_data.tolerance_y;
        if (MM_IMAGE_FORMAT_RGB565 == pAutoCapSetEnvInfo->image_format)
        {
            autocap_init_struct.image_format = AUTOCAP_IMAGE_FORMAT_RGB565;
        }
        else if (MM_IMAGE_FORMAT_YUV420 == pAutoCapSetEnvInfo->image_format)
        {
            autocap_init_struct.image_format = AUTOCAP_IMAGE_FORMAT_YUV420;
        }
        else
        {
            ASSERT(0);  // not support format
        }
        if(pAutoCapSetEnvInfo->dir_decided == KAL_FALSE)
        {
            AutoCapCoreSetInfo(&autocap_init_struct);
            
#ifdef AUTOCAP_LOG_DEBUG_INFO            
            sprintf(gAutocapLogBuffer, "");
#endif        
        }
        else
        {
            AutoCapCoreResetMV();
        }


        gAutoCapSrcImageWidth=pAutoCapSetEnvInfo->target_width;
        gAutoCapSrcImageHeight=pAutoCapSetEnvInfo->target_height;

        gAutoCapState = AUTOCAP_CONFIG_STATE;			

        break;

    case AUTOCAP_FEATURE_SET_PROC_INFO:	

        gAutoCapState = AUTOCAP_MEM_PROCESS_STATE;//AUTOCAP_READY_STATE;

       /* MemSwitch.pMemAddr=&(pAutCapSetMemInfo->PpProcBufAddr); 
        MemSwitch.Size=(kal_uint32)pAutCapSetMemInfo->PpProcBufSize;
        MemSwitch.CacheableFlag=KAL_TRUE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);
*/
        kal_mem_cpy(&gAutoCapSetMemInfo, pAutCapSetMemInfo, sizeof(AUTOCAP_SET_MEM_INFO_STRUCT) );
/*
        autocap_set_mem_struct.ext_mem_start_addr = (kal_uint32)gAutoCapSetMemInfo.PpProcBufAddr;
        autocap_set_mem_struct.ext_mem_size = (kal_uint32)gAutoCapSetMemInfo.PpProcBufSize;
        AutoCapCoreSetProcInfo(&autocap_set_mem_struct);
*/
        //gAutoCapState = AUTOCAP_PROCESS_STATE;//AUTOCAP_READY_STATE;
        break;

    case AUTOCAP_FEATURE_GET_STATE:

        if((gAutoCapState == AUTOCAP_READY_STATE)||(gAutoCapState == AUTOCAP_CONFIG_STATE))
        {
            *pAutoCapCheckState=PP_STATE_READY;
        }
        else
        {
            *pAutoCapCheckState=PP_STATE_BUSY;
        }

        break;

    case AUTOCAP_FEATURE_GET_RESULT:

        kal_mem_cpy(pAutoCapResult, &gAutoCapResult, sizeof(AUTOCAP_RESULT_STRUCT));

        break;

    case AUTOCAP_FEATURE_SET_LOG_INFO:		

        break;
    default:
        break;
    }
    return MM_ERROR_NONE;
}	/* AutoCapFeatureCtrl() */



MM_ERROR_CODE_ENUM AutoCapCtrl(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,
                               void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{


    P_AUTOCAP_RESULT_STRUCT pAutoCapResult = &gAutoCapResult;

    camera_autocap_result_struct AutoCapResultStruct;

    UTL_SWITCH_CACHE_STRUCT MemSwitch;

    UTL_BILINEAR_RESIZER_STRUCT UtlRisizerInfo;

    camera_autocap_set_mem_struct autocap_set_mem_struct;
    
    ASSERT(gAutoCapState!=AUTOCAP_IDLE_STATE);

    if(PP_CTRL_CODE_START == CtrlCode)
    {		
        /*-------------- MEM--------------*/

        gAutoCapState = AUTOCAP_MEM_PROCESS_STATE;

        MemSwitch.pMemAddr=&(gAutoCapSetMemInfo.PpProcBufAddr); 
        MemSwitch.Size=(kal_uint32)gAutoCapSetMemInfo.PpProcBufSize;
        MemSwitch.CacheableFlag=KAL_TRUE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

        autocap_set_mem_struct.ext_mem_start_addr = (kal_uint32)gAutoCapSetMemInfo.PpProcBufAddr;
        autocap_set_mem_struct.ext_mem_size = (kal_uint32)gAutoCapSetMemInfo.PpProcBufSize;
        AutoCapCoreSetProcInfo(&autocap_set_mem_struct);
        
#ifdef AUTOCAP_LOG_DEBUG_INFO    
    GET_TICK_COUNT(&gAutoCapTimeLog);
#endif
        // copy source image form MDP to AutoCap working memory
        if(PP_MEM_OP_COPY_TO_PROC_BUF == gAutoCapSetMemInfo.PpMemOpType)
        //if(KAL_TRUE)
        {
            kal_mem_cpy((kal_uint8*)(gAutoCapSetMemInfo.PpProcBufAddr), (kal_uint8*)gAutoCapSetMemInfo.PpSrcBufAddr, gAutoCapSetMemInfo.PpSrcBufSize); 
        }	
        else if(PP_MEM_OP_RESIZE_TO_PROC_BUF== gAutoCapSetMemInfo.PpMemOpType)
        //else if(KAL_FALSE)
        {
            MemSwitch.pMemAddr=&(gAutoCapSetMemInfo.PpSrcBufAddr); 
            MemSwitch.Size=(kal_uint32)gAutoCapSetMemInfo.PpSrcBufSize;
            MemSwitch.CacheableFlag=KAL_TRUE;
            UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

            UtlRisizerInfo.srcAddr = (kal_uint16*) gAutoCapSetMemInfo.PpSrcBufAddr;
            UtlRisizerInfo.srcWidth= gAutoCapSrcImageWidth;
            UtlRisizerInfo.srcHeight= gAutoCapSrcImageHeight;
            UtlRisizerInfo.dstAddr = (kal_uint16*) gAutoCapSetMemInfo.PpProcBufAddr;
            UtlRisizerInfo.dstWidth = AUTOCAP_IMAGE_XS;
            UtlRisizerInfo.dstHeight = AUTOCAP_IMAGE_YS;
            UtlBilinearResizer(&UtlRisizerInfo);

            MemSwitch.pMemAddr=&(gAutoCapSetMemInfo.PpSrcBufAddr); 
            MemSwitch.Size=(kal_uint32)gAutoCapSetMemInfo.PpSrcBufSize;
            MemSwitch.CacheableFlag=KAL_FALSE;
            UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);
        }
        else
        {
            return MM_ERROR_INVALID_PARAMETER;
        }

        gAutoCapState = AUTOCAP_PROCESS_STATE;
        
#ifdef AUTOCAP_LOG_DEBUG_INFO    
GET_ACCUM_TICK_INTERVAL(gAutoCapTimeLog, &gAutoCapTimeMeasurement.memcpy_times);
GET_TICK_COUNT(&gAutoCapTimeLog); 
#endif        
        AutoCapCoreProcess(gAutoCapSetMemInfo.PpProcBufAddr, &AutoCapResultStruct);	
        

#ifdef AUTOCAP_LOG_DEBUG_INFO    
GET_ACCUM_TICK_INTERVAL(gAutoCapTimeLog, &gAutoCapTimeMeasurement.accumulate_times);
#endif      


#ifdef AUTOCAP_LOG_DEBUG_INFO
        gAutoCapFrameCount++;
        sprintf(gAutocapLogTempBuffer, "mv_x %d, mv_y %d, shot %d\n", AutoCapResultStruct.mv_x, AutoCapResultStruct.mv_y, AutoCapResultStruct.ready_to_shot);
        strcat(gAutocapLogBuffer, gAutocapLogTempBuffer);            

        if(AutoCapResultStruct.ready_to_shot == KAL_TRUE)
        {     	
            sprintf(gAutocapLogTempBuffer, "total frames count: %d\n", gAutoCapFrameCount);
            strcat(gAutocapLogBuffer, gAutocapLogTempBuffer);

            sprintf(gAutocapLogTempBuffer, "memory copy: %d ms \n", gAutoCapTimeMeasurement.memcpy_times*1000/32768);
            strcat(gAutocapLogBuffer, gAutocapLogTempBuffer);

            sprintf(gAutocapLogTempBuffer, "accumulate_times: %d ms\n", gAutoCapTimeMeasurement.accumulate_times*1000/32768);
            strcat(gAutocapLogBuffer, gAutocapLogTempBuffer);
          
            gAutocapLogFileName[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

            if ( FSAL_OPEN_ERROR ==FSAL_Open(&gAutocapWriteLog, gAutocapLogFileName, FSAL_WRITE)) 
            {
                //return KAL_FALSE;
            }
            FSAL_Write(&gAutocapWriteLog, (kal_uint8*)gAutocapLogBuffer, sizeof(gAutocapLogBuffer));

            FSAL_Close(&gAutocapWriteLog);
        }            
#endif      
        
        pAutoCapResult->MV_X = AutoCapResultStruct.mv_x;
        pAutoCapResult->MV_Y = AutoCapResultStruct.mv_y;
        pAutoCapResult->ImageWidth = AUTOCAP_IMAGE_XS;
        pAutoCapResult->ImageHeight = AUTOCAP_IMAGE_YS;
        pAutoCapResult->OverlapRatio = OVERLAP_RATIO;
        pAutoCapResult->Direction = AutoCapResultStruct.direction;
        pAutoCapResult->HintDirection = AutoCapResultStruct.hint_direction;
        pAutoCapResult->ReadyToShot = AutoCapResultStruct.ready_to_shot;

        // cb to cal	
        pfPpAutoCapCb(PP_CBID_AUTOCAP_RESULT, pAutoCapResult, sizeof(AUTOCAP_RESULT_STRUCT));

        MemSwitch.pMemAddr=&(gAutoCapSetMemInfo.PpProcBufAddr); 
        MemSwitch.Size=(kal_uint32)gAutoCapSetMemInfo.PpProcBufSize;
        MemSwitch.CacheableFlag=KAL_FALSE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

        gAutoCapState = AUTOCAP_READY_STATE;

    }
    else if (PP_CTRL_CODE_RESET == CtrlCode)
    {
        AutoCapCoreExit();
    }

    return MM_ERROR_NONE;
}	/* AutoCapCtrl() */



AUTOCAP_FUNCTION_STRUCT AutoCapFuncMap=
{
    AutoCapOpen,
    AutoCapFeatureCtrl,
    AutoCapCtrl,
    AutoCapClose
};



MM_ERROR_CODE_ENUM AutoCapInit(MM_ERROR_CODE_ENUM (* pfAutoCapCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
                               P_AUTOCAP_FUNCTION_STRUCT *pfAutoCapFunc)
{
    pfPpAutoCapCb = pfAutoCapCallback;	
    *pfAutoCapFunc=&AutoCapFuncMap;
    return MM_ERROR_NONE;
}	/* AutoCapInit() */

#else   /*#if defined(__AUTOCAP_PANORAMA_SUPPORT__)*/

MM_ERROR_CODE_ENUM AutoCapInit(MM_ERROR_CODE_ENUM (* pfAutoCapCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
                               P_AUTOCAP_FUNCTION_STRUCT *pfAutoCapFunc)
{
    return MM_ERROR_NONE;
} /* AutoCapInit() */




#endif
