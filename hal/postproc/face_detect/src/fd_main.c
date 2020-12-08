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
 *   fd_main.c
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   Face detection & visual tracking process source file
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "fd_if.h"
#include "mm_comm_def.h"
#include "pp_comm_def.h"
#if defined(__FACE_DETECTION_SUPPORT__)
#include "fd_comm_def.h"
#include "pp_if.h"
#include "utility_comm_def.h"
#include "fd_core.h"
#include "fsal.h"

/****************************************************************************
 *                       Read-Only Data.                        								      *
 ****************************************************************************/
#include "fd_data_1.h"
#include "fd_data_2.h"

/****************************************************************************
 *          FDVT Global data
 ****************************************************************************/
FD_STATE_ENUM gFdState = FD_IDLE_STATE;
FD_RESULT_STRUCT	gFdResult;
FD_SET_MEM_INFO_STRUCT gFdSetMemInfo;

kal_uint32 gSrcImageWidth;
kal_uint32 gSrcImageHeight; 
kal_uint32 gDstImageWidth;
kal_uint32 gDstImageHeight; 

kal_uint8 gFdLevelOption;
kal_uint8 gFdProcessCounter = 0;
kal_uint32 gFdStartTime=0;

#ifdef FD_LOG_DEBUG_INFO
kal_uint32 gFdLogSize;
kal_wchar   gFdLogFilename[30] = {'F', ':', '\\', '\\', 'L', 'O', 'G', '0', '0','\\', 'F', 'D', '0', '0', '0', '.', 'f', 'd', '\0'};
kal_wchar   gFdfoldername[10] = {'F', ':', '\\', '\\', 'L', 'O', 'G', '0', '0','\0'};
kal_uint16  gFdFileCount = 0;
kal_uint16  gFdFileCountMax = 500;
kal_uint16  gFdFolderCount;
P_FD_LOG_STRUCT gFdLogBuff;
const WCHAR *gFdDirName;
kal_uint8 *gFdPrzBuff;   
#endif

MM_ERROR_CODE_ENUM (* pfPpFdCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
/****************************************************************************
 *          FDVT Process Interface
 ****************************************************************************/ 
 
void FdSaveLog(kal_uint16 filecount)
{
#ifdef FD_LOG_DEBUG_INFO
	STFSAL rRecordFile;

	gFdLogFilename[14] = (filecount%10)+'0';
	gFdLogFilename[13] = ((filecount/10)%10)+'0';
	gFdLogFilename[12] = ((filecount/10/10)%10)+'0';

	FSAL_Open(&rRecordFile, gFdLogFilename, FSAL_WRITE);
	kal_mem_cpy((void*)(gFdPrzBuff), (void*)(gFdSetMemInfo.PpSrcBufAddr), FD_IMAGE_XS*FD_IMAGE_YS*CAMERA_FD_IMAGE_BYTES);
	FSAL_Write(&rRecordFile, (kal_uint8*)(gFdLogBuff), gFdLogSize);
	FSAL_Close(&rRecordFile);
#endif
}

MM_ERROR_CODE_ENUM FdOpen(void)
{
	gFdProcessCounter = 0;
	gFdState=FD_IDLE_STATE;
	return MM_ERROR_NONE;
}	/* FdOpen() */

MM_ERROR_CODE_ENUM FdClose(void)
{
	gFdProcessCounter = 0;
	gFdState = FD_IDLE_STATE;
	return MM_ERROR_NONE;
}	/* FdClose() */

MM_ERROR_CODE_ENUM FdFeatureCtrl(FD_FEATURE_ENUM FeatureId,
									void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{    
	P_FD_SET_ENV_INFO_STRUCT pFdSetEnvInfo = (P_FD_SET_ENV_INFO_STRUCT) pParaIn;
	FD_SET_INFO_STRUCT FdSetInfo; 
	P_FD_SET_MEM_INFO_STRUCT pFdSetMemInfo = (P_FD_SET_MEM_INFO_STRUCT) pParaIn; 
	FD_SET_PROC_INFO_STRUCT FdSetProcInfo; 

	P_FD_GET_ENV_INFO_STRUCT pFdGetEnvInfo = (P_FD_GET_ENV_INFO_STRUCT) pParaOut;
	P_FD_RESULT_STRUCT pFdResult = (P_FD_RESULT_STRUCT) pParaOut;
   	PP_STATE_ENUM* pFdCheckState = (PP_STATE_ENUM*) pParaOut;	
	UTL_SWITCH_CACHE_STRUCT MemSwitch;

	switch (FeatureId)
	{
		case FD_FEATURE_GET_ENV_INFO:
			FdCoreGetInfo(pFdGetEnvInfo);
			pFdGetEnvInfo->WorkingBufSize=(kal_uint32) (FD_BUFFER_SIZE);
			//pFdGetEnvInfo->SrcImgFormat= pFdGetEnvInfo->SrcImgFormat;			
			gDstImageWidth=pFdGetEnvInfo->ImageWidth;
			gDstImageHeight=pFdGetEnvInfo->ImageHeight;
		break;
		
		case FD_FEATURE_SET_ENV_INFO:	
			FdSetInfo.pFdEnvInfo = pFdSetEnvInfo;
			FdSetInfo.fd_data1 = (void*)&g_fd_data_1;
			FdSetInfo.fd_data2 = (void*)&g_fd_data_2;
			FdSetInfo.FdLevelOption=gFdLevelOption;
			FdCoreSetInfo(&FdSetInfo);
			gSrcImageWidth=pFdSetEnvInfo->target_width;
			gSrcImageHeight=pFdSetEnvInfo->target_height;
			//gFdFrameIdx = 0;
			gFdStartTime = 0;
			kal_mem_set(&gFdResult, 0, sizeof(FD_RESULT_STRUCT));
			gFdState = FD_CONFIG_STATE;			
		break;

		case FD_FEATURE_SET_PROC_INFO:	
			gFdSetMemInfo.PpSrcBufAddr = pFdSetMemInfo->PpSrcBufAddr; 
			gFdSetMemInfo.PpSrcBufSize = pFdSetMemInfo->PpSrcBufSize; 
			gFdSetMemInfo.PpMemOpType = pFdSetMemInfo->PpMemOpType; 
			gFdSetMemInfo.PpProcBufAddr = pFdSetMemInfo->PpProcBufAddr; 
			gFdSetMemInfo.PpProcBufSize = pFdSetMemInfo->PpProcBufSize; 
			gFdSetMemInfo.PpProcFmt = pFdSetMemInfo->PpProcFmt;
			ASSERT(gFdSetMemInfo.PpProcBufSize>=FD_BUFFER_SIZE);

			//Non-cached memory -> cachecd memory
			MemSwitch.pMemAddr=&gFdSetMemInfo.PpProcBufAddr;
			MemSwitch.Size=(kal_uint32) (FD_BUFFER_SIZE);
			MemSwitch.CacheableFlag=KAL_TRUE;
			UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

			FdSetProcInfo.ext_mem_start_addr =gFdSetMemInfo.PpProcBufAddr;
			FdSetProcInfo.ext_mem_size = (kal_uint32)FD_BUFFER_SIZE;
			FdSetProcInfo.SrcImgFormat =gFdSetMemInfo.PpProcFmt; 
			FdCoreSetProcInfo(&FdSetProcInfo);
			
			gFdState = FD_READY_STATE;
		break;
		
		case FD_FEATURE_GET_STATE:
			if((gFdState == FD_READY_STATE)||(gFdState == FD_CONFIG_STATE))
			{
				*pFdCheckState=PP_STATE_READY;
			}
			else
			{
				*pFdCheckState=PP_STATE_BUSY;
			}
		break;
		
		case FD_FEATURE_GET_RESULT:
			kal_mem_cpy(pFdResult, &gFdResult, sizeof(FD_RESULT_STRUCT));
		break;

		case FD_FEATURE_SET_LOG_INFO:			
			if (pParaOut) *(kal_uint32*)pParaOut = FD_LOG_BUFFER_SIZE;
#if (defined(FD_LOG_DEBUG_INFO))		       
			gFdFolderCount++;
			gFdfoldername[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE); 
			gFdfoldername[7] = gFdFolderCount/10 +'0'; 
			gFdfoldername[8] = gFdFolderCount%10 +'0';
			gFdDirName = gFdfoldername;
			FS_CreateDir(gFdDirName); 
			kal_mem_cpy((void*)(gFdLogFilename), (void*)(gFdfoldername), sizeof(gFdfoldername)-2);
			gFdFileCount= 0;
			gFdLogSize = (kal_uint32)FD_LOG_BUFFER_SIZE; 
			gFdLogBuff = (P_FD_LOG_STRUCT) (*(kal_uint32*)pParaIn);
			gFdPrzBuff = (kal_uint8*)((int)(gFdLogBuff)+768);
#endif
		break;
		default:
		break;
	}
	return MM_ERROR_NONE;
}	/* FdFeatureControl() */

MM_ERROR_CODE_ENUM FdCtrl(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,
							void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
#ifdef FD_LOG_DEBUG_INFO
	kal_uint32 t1,mem_time, total_fdvt_time, period_time;
#endif
	kal_uint32 t0;
	FD_PROCESS_IN_STRUCT FdProcIn ;
//	P_FD_PROC_PARA_IN_STRUCT pFdParaIn = (P_FD_PROC_PARA_IN_STRUCT )pParaIn;
	P_FD_RESULT_STRUCT pFdParaOut = &gFdResult;
	UTL_SWITCH_CACHE_STRUCT MemSwitch;
	UTL_BILINEAR_RESIZER_STRUCT UtlRisizerInfo;

	ASSERT(gFdState!=FD_IDLE_STATE);
		
	if(PP_CTRL_CODE_START == CtrlCode)
	{		
                t0 = drv_get_current_time();

#ifdef FD_LOG_DEBUG_INFO	
		period_time = drv_get_duration_ms(gFdStartTime);
		gFdStartTime = drv_get_current_time();
		t1 = gFdStartTime;
#endif

		/*-------------- MEM--------------*/

		gFdState = FD_MEM_PROCESS_STATE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		// copy source image form MDP to FD working memory
		if(PP_MEM_OP_COPY_TO_PROC_BUF == gFdSetMemInfo.PpMemOpType)
		{
			kal_mem_cpy((kal_uint8*)(gFdSetMemInfo.PpProcBufAddr), (kal_uint8*)gFdSetMemInfo.PpSrcBufAddr, gFdSetMemInfo.PpSrcBufSize); 
		}	
		else if(PP_MEM_OP_RESIZE_TO_PROC_BUF== gFdSetMemInfo.PpMemOpType)
		{
			UtlRisizerInfo.srcAddr = (kal_uint16*) gFdSetMemInfo.PpSrcBufAddr;
			UtlRisizerInfo.srcWidth= gSrcImageWidth;
			UtlRisizerInfo.srcHeight= gSrcImageHeight;
			UtlRisizerInfo.dstAddr = (kal_uint16*) gFdSetMemInfo.PpProcBufAddr;
			UtlRisizerInfo.dstWidth = gDstImageWidth;
			UtlRisizerInfo.dstHeight = gDstImageHeight;
			UtlBilinearResizer(&UtlRisizerInfo);
		}
		else
		{
			return MM_ERROR_INVALID_PARAMETER;
		}

#ifdef FD_LOG_DEBUG_INFO
		mem_time = drv_get_duration_ms(t1);		
		t1 = drv_get_current_time();
#endif		

		/*-------------- FD --------------*/

		gFdState = FD_PROCESS_STATE;

		kal_mem_set(pFdParaOut, 0, sizeof(FD_RESULT_STRUCT));

		FdProcIn.OperationMode= FD_FDVT_MODE;
		
		FdCoreMain(&FdProcIn,pFdParaOut);
		
		/* add fd processing counter for facial AF usage */
		gFdProcessCounter++;
		if(gFdProcessCounter>=255) 
		{
			gFdProcessCounter=0;
		}
		pFdParaOut->result_counter = gFdProcessCounter;

		pFdParaOut->fd_start_time= t0;
		pFdParaOut->fd_end_time= drv_get_current_time();

		//cached memory -> non-cachecd memory
		MemSwitch.pMemAddr=&gFdSetMemInfo.PpProcBufAddr; 
		MemSwitch.Size=(kal_uint32) (FD_BUFFER_SIZE);
		MemSwitch.CacheableFlag=KAL_FALSE;
		UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);
					
		// cb to cal	
		pfPpFdCb(PP_CBID_FD_RESULT, pFdParaOut, sizeof(FD_RESULT_STRUCT));
		
		/*-------------- Save Log --------------*/	
		
#if (defined(FD_LOG_DEBUG_INFO))		
		total_fdvt_time = drv_get_duration_ms(t1);		
		gFdFileCount++;
		FdCoreSaveLog(gFdLogBuff);
		gFdLogBuff->version = FDVT_VERSION;
		gFdLogBuff->frame_idx = gFdFileCount;
		gFdLogBuff->mem_time = mem_time;  
		gFdLogBuff->total_fdvt_time = total_fdvt_time;    
		gFdLogBuff->fdvt_period_time = period_time;
		
		if (gFdFileCount>gFdFileCountMax)
		{
			gFdFileCount = 0;
		}
		FdSaveLog(gFdFileCount);
#endif

		gFdState = FD_READY_STATE;

	}
	else if (PP_CTRL_CODE_RESET == CtrlCode)
	{
		FdCoreReset();
	}

	return MM_ERROR_NONE;
}	/* FdControl() */

FD_FUNCTION_STRUCT FdFuncMap=
{
	FdOpen,
	FdFeatureCtrl,
	FdCtrl,
	FdClose
};

MM_ERROR_CODE_ENUM FdInit(MM_ERROR_CODE_ENUM (* pfFdCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_FD_FUNCTION_STRUCT *pfFdFunc)
{
	pfPpFdCb = pfFdCallback;	
	*pfFdFunc=&FdFuncMap;
	return MM_ERROR_NONE;
}	/* FdInit() */

#else   /*#if defined(__FACE_DETECTION_SUPPORT__)*/

MM_ERROR_CODE_ENUM FdInit(MM_ERROR_CODE_ENUM (* pfFdCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_FD_FUNCTION_STRUCT *pfFdFunc)
{
	return MM_ERROR_NONE;
} /* FdInit() */
#endif

