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
 *   asd_main.c
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   auto scene detection process source file
 *
 * Author:
 * -------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "asd_if.h"
#include "mm_comm_def.h"
#include "pp_comm_def.h"
#if defined(__AUTO_SCENE_DETECT_SUPPORT__)
#include "asd_comm_def.h"
#include "utility_comm_def.h"
#include "asd_core.h"
#include "decider_core.h"
#include "fsal.h"
#include "pp_if.h"
/****************************************************************************
 *                       Read-Only Data.                        								      *
 ****************************************************************************/
#include "asd_data_1.h"
#include "asd_data_2.h"

/*******************************************************************************
* Global data
********************************************************************************/
DECIDER_RESULT_STRUCT gDeciderResult;
ASD_STATE_ENUM gAsdState = ASD_STATE_IDLE;
kal_uint32 gScdImageStartAddr;
kal_uint32 gAsdLogBuffer;
kal_uint32 gAsdLogImageBuffer;
#ifdef ASD_LOG_DEBUG_INFO
kal_uint32 written;
int file_handle;
//kal_char decider_filename[200];
kal_wchar gAsdLogFileName[20] = {'x', ':', '\\', '\\', 'A', 'S', 'D', '_', 'L', 'O', 'G', '_', '0', '0', '0', '.', 'b', 'i', 'n' , '\0'};
kal_uint32 gAsdLogCounter = 0;
#endif
MM_ERROR_CODE_ENUM (* pfPpAsdCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);

/*******************************************************************************
*
********************************************************************************/
MM_ERROR_CODE_ENUM AsdOpen(void)
{
	if(DeciderCoreOpen() == KAL_FALSE)
	{
	    return MM_ERROR_PPI_INVALID_PARAMETER;
	}
	gAsdState=ASD_STATE_STANDBY;
	return MM_ERROR_NONE;
}

MM_ERROR_CODE_ENUM AsdClose(void)
{
//	UTL_SWITCH_CACHE_STRUCT MemSwitch;
	DeciderCoreReset();
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	gAsdState=ASD_STATE_IDLE;
	return MM_ERROR_NONE;
}

MM_ERROR_CODE_ENUM AsdFeatureCtrl(ASD_FEATURE_ENUM FeatureId,
									void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
	ASD_SET_INFO_STRUCT AsdScdSetInfo;	
	PP_STATE_ENUM* pAsdCheckState = (PP_STATE_ENUM*) pParaOut;
       ASD_DECIDER_UI_SCENE_TYPE_ENUM* pAsdDeciderResult = (ASD_DECIDER_UI_SCENE_TYPE_ENUM*) pParaOut; //jason add
	P_ASD_GET_ENV_INFO_STRUCT pAsdGetEnvInfo = (P_ASD_GET_ENV_INFO_STRUCT) pParaOut;
//	char* buf_filename=(char *)pParaIn;
	UTL_SWITCH_CACHE_STRUCT MemSwitch;
//	MM_ERROR_CODE_ENUM err_code = MM_ERROR_NONE;

	switch (FeatureId)
	{
		case ASD_FEATURE_SET_DECIDER_ENV_INFO: // 2nd call
			if(gAsdState!=ASD_STATE_SCD_INIT)
				return MM_ERROR_PPI_INVALID_STATE;
		    if(KAL_FALSE == DeciderCoreInit(pParaIn, pParaOut))
		    {
		        return MM_ERROR_PPI_INVALID_PARAMETER;
		    }
			gAsdState=ASD_STATE_READY;
		break;

		case ASD_FEATURE_GET_ASD_RESULT:
			*pAsdDeciderResult=gDeciderResult.DeciderUiScene;
//			DeciderCoreGetResult(pParaIn, pParaOut);
		break;

		case ASD_FEATURE_SET_SCD_ENV_INFO: // 1st call
			AsdScdSetInfo.pAsdEnvInfo = (P_ASD_SET_ENV_INFO_STRUCT)pParaIn;
			if (AsdScdSetInfo.pAsdEnvInfo->ext_mem_size<ASD_BUFFER_SIZE)
				return MM_ERROR_PPI_BUFFER_NO_SYNC;

		       //working buffer address = external buffer address+ ASD_IMAGE_SIZE (offset)
			gScdImageStartAddr=AsdScdSetInfo.pAsdEnvInfo->ext_mem_start_addr;

			//Non-cached memory -> cachecd memory
			MemSwitch.pMemAddr=&gScdImageStartAddr;
			MemSwitch.Size=(kal_uint32) (ASD_WORKING_BUFFER_SIZE+ASD_IMAGE_SIZE);
			MemSwitch.CacheableFlag=KAL_TRUE;
			UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);


			AsdScdSetInfo.pAsdEnvInfo->ext_mem_start_addr= gScdImageStartAddr+ASD_IMAGE_SIZE;

			AsdScdSetInfo.asd_sdata_L=(void*)&g_asd_sdata_L;
			AsdScdSetInfo.asd_cdata_L=(void*)&g_asd_cdata_L;
			AsdScdSetInfo.asd_sdata_B=(void*)&g_asd_sdata_B;
			AsdScdSetInfo.asd_cdata_B=(void*)&g_asd_cdata_B;
			AsdCoreSetInfo(&AsdScdSetInfo);

			//ext_mem_start_addr is the working buffer start address, PPI already shift the source image size.
			gAsdLogBuffer=AsdScdSetInfo.pAsdEnvInfo->ext_mem_start_addr+ASD_WORKING_BUFFER_SIZE;
			gAsdLogImageBuffer=gAsdLogBuffer+ASD_DECIDER_LOG_BYTE_PER_CYCLE*ASD_DECIDER_LOG_MAX_CYCLE+ASD_DECIDER_LOG_HEADER;
			
			DeciderCoreSetLogger((void *)gAsdLogBuffer, pParaOut);
			gAsdState=ASD_STATE_SCD_INIT;
		break;

		case ASD_FEATURE_GET_ASD_ENV_INFO:
			pAsdGetEnvInfo->WorkingBufSize=(kal_uint32) (ASD_BUFFER_SIZE);
		break;

		case ASD_FEATURE_GET_SCD_STATUS:
			if(gAsdState == ASD_STATE_READY)
			{
				*pAsdCheckState=PP_STATE_READY;                            
			}
			else
			{
				*pAsdCheckState=PP_STATE_BUSY;
			}
		break;
		case ASD_FEATURE_SET_SCD_STATUS:
			gAsdState = ASD_STATE_WAIT_PROC;
		break;
		case ASD_FEATURE_GET_SCD_RESULT:
			AsdCoreGetResult(pParaOut);
		break;

		case ASD_FEATURE_SET_SCD_ABORT:
			AsdCoreSetAbortFlag(*(kal_bool*)pParaIn);
		break;

		case ASD_FEATURE_GET_ASD_STATE:
		break;

		case ASD_FEATURE_SAVE_DECIDER_LOG_INFO:
		#ifdef ASD_LOG_DEBUG_INFO
//			app_ucs2_strcpy((kal_int8*)decider_filename, (kal_int8*)buf_filename);
			//app_ucs2_strcat((kal_int8*)decider_filename, (kal_int8*) L".bin");
			//file_handle = FS_Open((unsigned short int*) decider_filename, FS_CREATE | FS_READ_WRITE);
                        gAsdLogCounter++;
                        gAsdLogFileName[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);    //FS_DRIVE_V_NORMAL
                        gAsdLogFileName[14] = (gAsdLogCounter%10)+'0';
                        gAsdLogFileName[13] = ((gAsdLogCounter/10)%10)+'0';
                        gAsdLogFileName[12] = ((gAsdLogCounter/10/10)%10)+'0';                          
			file_handle = FS_Open((unsigned short int*) &gAsdLogFileName[0], FS_CREATE | FS_READ_WRITE);
			if (file_handle <= 0)
			{
				return MM_ERROR_PPI_INVALID_PARAMETER;
			}
			kal_mem_cpy((void*)(gAsdLogImageBuffer), (void*)(gScdImageStartAddr), ASD_IMAGE_SIZE);

			FS_Write(file_handle, (void*)gAsdLogBuffer, ASD_DECIDER_BUFFER_SIZE, (kal_uint32 *) & written);
			FS_Close(file_handle);
		#endif

//			DeciderCoreSaveLog((char *)pParaIn);
		break;

		case ASD_FEATURE_SET_SCD_LOG_INFO:

		break;

		default:
		break;
	}
	return MM_ERROR_NONE;
}

MM_ERROR_CODE_ENUM AsdCtrl(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,
							void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
	P_ASD_PROCESS_STRUCT pProcIn =(P_ASD_PROCESS_STRUCT) pParaIn;
	P_ASD_FINAL_RESULT_STRUCT pAsdParaOut;
	UTL_SWITCH_CACHE_STRUCT MemSwitch;
//	MM_ERROR_CODE_ENUM err_code = MM_ERROR_NONE;

	if (PP_CTRL_CODE_START == CtrlCode)
	{
	if(ASD_PROC_DECIDER==pProcIn->ProcId)
	{	    
            if(pProcIn->src_buffer_addr!=NULL)
	    {
                kal_mem_cpy((kal_uint8*)gScdImageStartAddr, (kal_uint8*)pProcIn->src_buffer_addr, ASD_IMAGE_SIZE);
	    }
            if(pProcIn->pDeciderInfo!=NULL) 
            {            
                if(KAL_FALSE == DeciderCoreMain(pProcIn->pDeciderInfo, &gDeciderResult))
	    {
		return MM_ERROR_PPI_INVALID_PARAMETER;
	    }
                                
		pAsdParaOut=(P_ASD_FINAL_RESULT_STRUCT)&gDeciderResult.DeciderUiScene;

		// cb to cal
		pfPpAsdCb(PP_CBID_ASD_RESULT, pAsdParaOut, sizeof(ASD_FINAL_RESULT_STRUCT));
	}
        }
	else if(ASD_PROC_MAIN==pProcIn->ProcId)
	{
            if(gAsdState!=ASD_STATE_WAIT_PROC)
                return MM_ERROR_PPI_INVALID_STATE;

            gAsdState = ASD_STATE_PROC;
            AsdCoreMain(gScdImageStartAddr);
 		gAsdState=ASD_STATE_READY;            
	}
	else
	{
		return MM_ERROR_PPI_INVALID_PARAMETER;
	}
	}
	else if (PP_CTRL_CODE_STOP == CtrlCode)
	{
		//cached memory -> non-cachecd memory
		MemSwitch.pMemAddr=&gScdImageStartAddr;
		MemSwitch.Size=(kal_uint32) (ASD_WORKING_BUFFER_SIZE+ASD_IMAGE_SIZE);
		MemSwitch.CacheableFlag=KAL_FALSE;
		UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);
		gAsdState = ASD_STATE_STANDBY;
		PP_SET_EVENT(PP_EVENT_ASD_STOP_CNF);
  }
    
	/* call back freqency can be customized here by align with ScD or align with 3A cycle */
	return MM_ERROR_NONE;
}

ASD_FUNCTION_STRUCT AsdFuncMap=
{
	AsdOpen,
	AsdFeatureCtrl,
	AsdCtrl,
	AsdClose
};

MM_ERROR_CODE_ENUM AsdInit(MM_ERROR_CODE_ENUM (* pfAsdCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_ASD_FUNCTION_STRUCT *pfAsdFunc)
{
	pfPpAsdCb = pfAsdCallback;
	*pfAsdFunc=&AsdFuncMap;
	return MM_ERROR_NONE;
}	/* AsdInit() */

#else   /*#if defined(__AUTO_SCENE_DETECT_SUPPORT__)*/

MM_ERROR_CODE_ENUM AsdInit(MM_ERROR_CODE_ENUM (* pfFdCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_ASD_FUNCTION_STRUCT *pfAsdFunc)
{
	return MM_ERROR_NONE;
} /* AsdInit() */
#endif


