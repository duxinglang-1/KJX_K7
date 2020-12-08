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
 *   sd_main.c
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   smile detection process source file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "sd_if.h"
#include "pp_comm_def.h"
#include "mm_comm_def.h"
#if defined(__SMILE_SHUTTER_SUPPORT__)
#include "pp_if.h"
#include "sd_comm_def.h"
#include "utility_comm_def.h"
#include "sd_core.h"
#include "fd_core.h"
#include "fsal.h"
/****************************************************************************
 *                       Read-Only Data.                        								      *
 ****************************************************************************/
#include "sd_data_1.h"
#include "sd_data_2.h"
/****************************************************************************
 *          SD Global data
 ****************************************************************************/
SD_STATE_ENUM gSdState = SD_IDLE_STATE;
SD_RESULT_STRUCT gSdResult;
SD_SET_MEM_INFO_STRUCT gSdSetMemInfo;
FD_RESULT_STRUCT gSdFdResult;
kal_uint32 gSdSrcImageWidth;
kal_uint32 gSdSrcImageHeight; 
kal_uint32 gSdDstImageWidth;
kal_uint32 gSdDstImageHeight; 

kal_uint8 gSdLevelOption;
kal_uint32 gSdStartTime=0;
kal_uint32 gSdFrameIdx=0;

#ifdef SD_LOG_DEBUG_INFO
kal_uint32 gSdLogSize;
kal_wchar   gSdLogFileName[30] = {'F', ':', '\\', '\\', 'L', 'O', 'G', '0', '0','\\', 'S', 'D', '0', '0', '0', '.', 's', 'd', '\0'};
kal_wchar   gSdfoldername[10] = {'F', ':', '\\', '\\', 'L', 'O', 'G', '0', '0','\0'};
kal_uint16  gSdFileCount;
kal_uint16  gSdFileCountMax = 500;
kal_uint16  gSdFolderCount;
P_SD_LOG_STRUCT gSdLogBuff;
const WCHAR *gSdDirName;
kal_uint8 *gSdYBuffer;
#endif


MM_ERROR_CODE_ENUM (* pfPpSdCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);

/****************************************************************************
 *          SD Process Interface
 ****************************************************************************/ 
 
void SdSaveLog(kal_uint16 filecount)
{
#if (defined(SD_LOG_DEBUG_INFO))
	STFSAL SdrRecordFile;

	gSdLogFileName[14] = (filecount%10)+'0';
	gSdLogFileName[13] = ((filecount/10)%10)+'0';
	gSdLogFileName[12] = ((filecount/10/10)%10)+'0';

	FSAL_Open(&SdrRecordFile, gSdLogFileName, FSAL_WRITE);
	kal_mem_cpy((void*)(gSdYBuffer), (void*)(gSdSetMemInfo.PpSrcBufAddr), SD_IMAGE_XS*SD_IMAGE_YS*2);
	FSAL_Write(&SdrRecordFile, (kal_uint8*)(gSdLogBuff), gSdLogSize);
	FSAL_Close(&SdrRecordFile);	
#endif
}

MM_ERROR_CODE_ENUM SdOpen(void)
{
	gSdState=SD_IDLE_STATE;
	return MM_ERROR_NONE;
}	/* SdOpen() */

MM_ERROR_CODE_ENUM SdClose(void)
{
	gSdState = SD_IDLE_STATE;
	return MM_ERROR_NONE;
}	/* SdClose() */

MM_ERROR_CODE_ENUM SdFeatureCtrl(SD_FEATURE_ENUM FeatureId,
									void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{    
   	P_SD_SET_ENV_INFO_STRUCT pSdSetEnvInfo = (P_SD_SET_ENV_INFO_STRUCT) pParaIn;
   	SD_SET_INFO_STRUCT SdSetInfo; 
	P_SD_SET_MEM_INFO_STRUCT pSdSetMemInfo = (P_SD_SET_MEM_INFO_STRUCT) pParaIn; 
	SD_SET_PROC_INFO_STRUCT SdSetProcInfo; 
	
	P_SD_GET_ENV_INFO_STRUCT pSdGetEnvInfo = (P_SD_GET_ENV_INFO_STRUCT) pParaOut;
   	P_SD_RESULT_STRUCT pSdResult = (P_SD_RESULT_STRUCT) pParaOut;
   	PP_STATE_ENUM *pSdCheckState=(PP_STATE_ENUM *) pParaOut;

   	SD_GET_ENV_INFO_STRUCT SdGetEnvInfo;
	UTL_SWITCH_CACHE_STRUCT MemSwitch;
	
	switch (FeatureId)	
	{
		case SD_FEATURE_GET_ENV_INFO:
			SdCoreGetInfo(pSdGetEnvInfo);
			pSdGetEnvInfo->WorkingBufSize=(kal_uint32)(SD_BUFFER_SIZE);
			//pSdGetEnvInfo->SrcImgFormat= MM_IMAGE_FORMAT_RGB565;
			//pSdGetEnvInfo->SrcImgFormat= pSdGetEnvInfo->SrcImgFormat;
			//gSdDstImageWidth=pSdGetEnvInfo->ImageWidth;
			//gSdDstImageHeight=pSdGetEnvInfo->ImageHeight;
		break;
		
		case SD_FEATURE_SET_ENV_INFO:	
			SdSetInfo.pSdEnvInfo = pSdSetEnvInfo;
			SdSetInfo.sd_data1 = (void*)&g_sd_data_1;
			SdSetInfo.sd_data2 = (void*)&g_sd_data_2;
			SdSetInfo.SdLevelOption=gSdLevelOption;
			SdCoreSetInfo(&SdSetInfo);
			gSdSrcImageWidth=pSdSetEnvInfo->target_width;
			gSdSrcImageHeight=pSdSetEnvInfo->target_height;
			gSdFrameIdx = 0;
			kal_mem_set(&gSdResult, 0, sizeof(SD_RESULT_STRUCT));
			SdCoreGetInfo(&SdGetEnvInfo);
			gSdDstImageWidth=SdGetEnvInfo.ImageWidth;
			gSdDstImageHeight=SdGetEnvInfo.ImageHeight;
		break;

		case SD_FEATURE_SET_PROC_INFO:	
			gSdSetMemInfo.PpSrcBufAddr = pSdSetMemInfo->PpSrcBufAddr; 
			gSdSetMemInfo.PpSrcBufSize = pSdSetMemInfo->PpSrcBufSize; 
			gSdSetMemInfo.PpMemOpType = pSdSetMemInfo->PpMemOpType; 
			gSdSetMemInfo.PpProcBufAddr = pSdSetMemInfo->PpProcBufAddr; 
			gSdSetMemInfo.PpProcBufSize = pSdSetMemInfo->PpProcBufSize; 
			gSdSetMemInfo.PpProcFmt = pSdSetMemInfo->PpProcFmt;
			ASSERT(gSdSetMemInfo.PpProcBufSize>=SD_BUFFER_SIZE);

			//Non-cached memory -> cachecd memory
			MemSwitch.pMemAddr=&gSdSetMemInfo.PpProcBufAddr;
			MemSwitch.Size=(kal_uint32) (SD_BUFFER_SIZE);
			MemSwitch.CacheableFlag=KAL_TRUE;
			UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);


			SdSetProcInfo.ext_mem_start_addr = gSdSetMemInfo.PpProcBufAddr;
			SdSetProcInfo.ext_mem_size =(kal_uint32)SD_BUFFER_SIZE;
			SdSetProcInfo.SrcImgFormat =gSdSetMemInfo.PpProcFmt; 
			SdCoreSetProcInfo(&SdSetProcInfo);
			gSdState = SD_READY_STATE;
		break;
		
		case SD_FEATURE_GET_STATE:
			if((gSdState == SD_READY_STATE)||(gSdState == SD_IDLE_STATE))
			{
				 *pSdCheckState=PP_STATE_READY;
			}
			else
			{
				 *pSdCheckState=PP_STATE_BUSY;
			}
		break;
				
		case SD_FEATURE_GET_RESULT:
			kal_mem_cpy(pSdResult, &gSdResult, sizeof(SD_RESULT_STRUCT));
		break;
		
		case SD_FEATURE_SET_LOG_INFO:		
			if (pParaOut) *(kal_uint32*)pParaOut = SD_LOG_BUFFER_SIZE;
#if (defined(SD_LOG_DEBUG_INFO))
			gSdFolderCount++;
			gSdfoldername[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE); 
			gSdfoldername[7] = gSdFolderCount/10 +'0'; 
			gSdfoldername[8] = gSdFolderCount%10 +'0';
			gSdDirName = gSdfoldername;
			FS_CreateDir(gSdDirName); 
			kal_mem_cpy((void*)(gSdLogFileName), (void*)(gSdfoldername), sizeof(gSdfoldername)-2);
			gSdFileCount= 0;
			gSdLogSize = (kal_uint32) SD_LOG_BUFFER_SIZE;
			gSdLogBuff = (P_SD_LOG_STRUCT) (*(kal_uint32*)pParaIn);        
			gSdYBuffer = (kal_uint8*) ((int)gSdLogBuff+256);
#endif			
		break;
		default:
		break;
	}
	return MM_ERROR_NONE;

}	/* SdFeatureControl() */

MM_ERROR_CODE_ENUM SdCtrl(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,
							void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
	kal_uint32 i;
	kal_uint32 num;
#if (defined(SD_LOG_DEBUG_INFO))	
	kal_uint32 t1, mem_time,fd_time,sd_time,total_time, sd_period_time;
#endif
	FD_PROCESS_IN_STRUCT FdProcIn ;
	P_FD_RESULT_STRUCT pFdProcOut = &gSdFdResult;
//	P_SD_PROC_PARA_IN_STRUCT pSdParaIn = (P_SD_PROC_PARA_IN_STRUCT )pParaIn;
	P_SD_RESULT_STRUCT pSdParaOut = &gSdResult;
	UTL_SWITCH_CACHE_STRUCT MemSwitch;
	UTL_BILINEAR_RESIZER_STRUCT UtlRisizerInfo;
	
	if(PP_CTRL_CODE_START == CtrlCode)
	{

		ASSERT(gSdState!=SD_IDLE_STATE);	
       	
#if (defined(SD_LOG_DEBUG_INFO))	
		sd_period_time = drv_get_duration_ms(gSdStartTime);
		gSdStartTime = drv_get_current_time();
		t1 = gSdStartTime;
#endif			

		/*-------------- MEM --------------*/

		gSdState = SD_MEM_PROCESS_STATE;			
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
		// copy source image form MDP to FD working memory
		if(PP_MEM_OP_COPY_TO_PROC_BUF == gSdSetMemInfo.PpMemOpType)
		{
			kal_mem_cpy((kal_uint8*)(gSdSetMemInfo.PpProcBufAddr), (kal_uint8*)gSdSetMemInfo.PpSrcBufAddr, gSdSetMemInfo.PpSrcBufSize); 
		}			
		else if(PP_MEM_OP_RESIZE_TO_PROC_BUF== gSdSetMemInfo.PpMemOpType)
		{
			UtlRisizerInfo.srcAddr = (kal_uint16*) gSdSetMemInfo.PpSrcBufAddr;
			UtlRisizerInfo.srcWidth= gSdSrcImageWidth;
			UtlRisizerInfo.srcHeight= gSdSrcImageHeight;
			UtlRisizerInfo.dstAddr = (kal_uint16*) gSdSetMemInfo.PpProcBufAddr;
			UtlRisizerInfo.dstWidth = gSdDstImageWidth;
			UtlRisizerInfo.dstHeight = gSdDstImageHeight;
			UtlBilinearResizer(&UtlRisizerInfo);
		}
		else
		{
			return MM_ERROR_INVALID_PARAMETER;
		}
		
#if (defined(SD_LOG_DEBUG_INFO))	
		mem_time = drv_get_duration_ms(t1);			
		t1 = drv_get_current_time();
#endif		

		/*-------------- FD --------------*/		
		
		gSdState = SD_FD_PROCESS_STATE;				
	
		FdProcIn.OperationMode=FD_FDVT_MODE;
				
		FdCoreMain(&FdProcIn,pFdProcOut);

#if (defined(SD_LOG_DEBUG_INFO))	
		fd_time = drv_get_duration_ms(t1);	
		t1 = drv_get_current_time();
#endif		

		/*-------------- SD --------------*/
		
		gSdState = SD_PROCESS_STATE;				

		kal_mem_set(pSdParaOut, 0, sizeof(SD_RESULT_STRUCT));					
			
		SdCoreMain(pFdProcOut,pSdParaOut);

#if (defined(SD_LOG_DEBUG_INFO))	
		sd_time = drv_get_duration_ms(t1);
#endif		

		num= pSdParaOut->face_no;

		for ( i = 0 ; i < num ; i ++ )
	  	{
			pSdParaOut->rect_lum[i] =pFdProcOut->rect_lum[i];
		}

		//cached memory -> non-cachecd memory
		MemSwitch.pMemAddr=&gSdSetMemInfo.PpProcBufAddr;
		MemSwitch.Size=(kal_uint32)(SD_BUFFER_SIZE);
		MemSwitch.CacheableFlag=KAL_FALSE;
		UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);
	
		// cb to cal	
		pfPpSdCb(PP_CBID_SD_RESULT, pSdParaOut, sizeof(SD_RESULT_STRUCT));

		/*-------------- Save Log --------------*/	
		
#if (defined(SD_LOG_DEBUG_INFO))	
		total_time = drv_get_duration_ms(gSdStartTime);              
		SdCoreSaveLog(gSdLogBuff);
		gSdLogBuff->version = SD_VERSION;
		gSdLogBuff->frame_idx = gSdFileCount;
		gSdLogBuff->mem_time = mem_time;
		gSdLogBuff->fd_time = fd_time;
		gSdLogBuff->sd_time = sd_time;		
		gSdLogBuff->sd_period_time = sd_period_time;
		gSdLogBuff->total_time = total_time;
		gSdLogBuff->sd_end_flag = pSdParaOut ->sd_end_flag;		
		gSdFileCount++;
		if (gSdFileCount>gSdFileCountMax)
		{
			gSdFileCount = 0;
		}
		SdSaveLog(gSdFileCount);
#endif

		gSdState = SD_READY_STATE;
	}
	return MM_ERROR_NONE;
}	/* SdControl() */


SD_FUNCTION_STRUCT SdFuncMap=
{
	SdOpen,
	SdFeatureCtrl,
	SdCtrl,
	SdClose
};

MM_ERROR_CODE_ENUM SdInit(MM_ERROR_CODE_ENUM (* pfSdCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_SD_FUNCTION_STRUCT *pfSdFunc)
{
	pfPpSdCb = pfSdCallback;	
	*pfSdFunc=&SdFuncMap;
	return MM_ERROR_NONE;
}	/* SdInit() */

#else   /*#if defined(__SMILE_SHUTTER_SUPPORT__)*/

MM_ERROR_CODE_ENUM SdInit(MM_ERROR_CODE_ENUM (* pfSdCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_SD_FUNCTION_STRUCT *pfSdFunc)
{
	return MM_ERROR_NONE;
} /* SdInit() */
#endif


