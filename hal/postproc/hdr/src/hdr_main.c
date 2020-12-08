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
 *   Hdr_main.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   HDR control driver
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// SwHdr_Proc.cpp : Defines the entry point for the console application.
//
#include "hdr_comm_def.h"
#include "hdr_if.h"
#if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
#include "pp_if.h"
#include "hdr_core.h"
#include "utility_comm_def.h"

extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);


//#if defined(__HDR_SUPPORT__)

#define VERSION	20100209

#define HDR_PROCESS_MAX_COUNT   100
#define HDR_PROCESS_MAX_TIME		(250)

MM_ERROR_CODE_ENUM (* pfPpHdrCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);
HDR_STATE_ENUM HdrState;
HDR_SET_PROC_INFO_STRUCT gHdrProcPara;
HDR_RESULT_STRUCT gHdrProcResult;

MM_ERROR_CODE_ENUM HdrOpen(void)
{
    SwHdrCoreOpen();
	return MM_ERROR_NONE;
}	/* SwHdrOpen() */

MM_ERROR_CODE_ENUM HdrClose(void)
{
    SwHdrCoreClose();
	return MM_ERROR_NONE;
}	/* SwHdrClose() */

MM_ERROR_CODE_ENUM HdrFeatureCtrl(HDR_FEATURE_ENUM FeatureId,
									void* pParaIn, void* pParaOut,kal_uint16 pParaOutLen)
{
    HDR_STRENGTH_PARA_STRUCT HdrPara;
    P_HDR_SET_INFO_STRUCT pSwHdrSetInfo = (P_HDR_SET_INFO_STRUCT) pParaIn;
	P_HDR_GET_INFO_STRUCT pSwHdrGetInfo=(P_HDR_GET_INFO_STRUCT) pParaOut;
    P_HDR_SET_PROC_INFO_STRUCT pHdrSetProcInfo = (P_HDR_SET_PROC_INFO_STRUCT)pParaIn;
#ifdef SWHDR_SIM_MODE
    P_HDR_SET_RAW_INFO_STRUCT pSwHdrSetRAWInfo = (P_HDR_SET_RAW_INFO_STRUCT) pParaIn;
#endif
    P_HDR_TUNING_PARA_STRUCT pSwHdrTuningPara =  (P_HDR_TUNING_PARA_STRUCT) pParaIn;
    P_HDR_RESULT_STRUCT pHdrGetResult = (P_HDR_RESULT_STRUCT) pParaOut;
    PP_STATE_ENUM* pHdrCheckState = (PP_STATE_ENUM*) pParaOut;
    MM_ERROR_CODE_ENUM ErrorCode = MM_ERROR_NONE;

	switch (FeatureId)
	{
	    case HDR_FEATURE_GET_ENV_INFO:
            SwHdrCoreGetInfo(pSwHdrGetInfo);
	        break;
	    case HDR_FEATURE_SET_ENV_INFO:
                SwHdrCoreSetInfo(pSwHdrSetInfo);
	        break;
	    case HDR_FEATURE_SET_PROC_INFO:
	        kal_mem_cpy(&gHdrProcPara, pHdrSetProcInfo, sizeof(HDR_SET_PROC_INFO_STRUCT));
	    	break;
        case HDR_FEATURE_UPDATE_TUNING:
            HdrPara.Hdr_Sw_O2_0 = 2700;
            HdrPara.Hdr_Sw_O2_1 = 2400;
            HdrPara.Hdr_Sw_O2_2 = 2100;
            HdrPara.Hdr_Sw_O2_3 = 1800;
            HdrPara.Hdr_Sw_O2_4 = 1600;
            HdrPara.Hdr_Sw_O2_5 = 1400;
            HdrPara.Hdr_Sw_O2_6 = 1200;
            HdrPara.Hdr_Sw_O2_7 = 1000;
            HdrPara.Hdr_Sw_O2_8 = 800;
            HdrPara.Hdr_Sw_O2_9 = 600;
            HdrPara.Hdr_Sw_O2_10 = 400;
            HdrPara.Hdr_Sw_Ba_0 = 0;
            HdrPara.Hdr_Sw_Ba_1 = 4;
            HdrPara.Hdr_Sw_Ba_2 = 8;
            HdrPara.Hdr_Sw_Ba_3 = 16;
            HdrPara.Hdr_Sw_Ba_4 = 24;
            HdrPara.Hdr_Sw_Ba_5 = 48;
            HdrPara.Hdr_Sw_Ba_6 = 64;
            SwHdrCoreUpdateStrengthPara(&HdrPara);
            SwHdrCoreUpdateTuning(pSwHdrTuningPara);
        break;
#ifdef SWHDR_SIM_MODE
        case HDR_FEATURE_SET_RAW_INFO:
            SwHdrCoreSetRAWInfo(pSwHdrSetRAWInfo);
        break;
#endif
	    case HDR_FEATURE_GET_STATE:
	    	if((HDR_STATE_READY == gHdrProcResult.HdrState)/*|| (HDR_STATE_IDLE == gHdrProcResult.HdrState)*/)
	    	{
	    		*pHdrCheckState=PP_STATE_READY;
	    	}
	    	else
	    	{
	    		*pHdrCheckState=PP_STATE_BUSY;
	    	}
	    break;
//        case HDR_FEATURE_SAVE_LOG:
//        break;
	    case HDR_FEATURE_GET_RESULT:
	        kal_mem_cpy(pHdrGetResult, &gHdrProcResult, sizeof(HDR_RESULT_STRUCT));
	        break;
        default:
        break;
	}

    return ErrorCode;
}	/* SwHdrFeatureControl() */

MM_ERROR_CODE_ENUM HdrCtrl (PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,
                            void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen)
{
	kal_uint32	i, StartTime, TotalTime=0;
    UTL_SWITCH_CACHE_STRUCT MemSwitch;

    
    	if(PP_CTRL_CODE_STOP == CtrlCode)
        {          
           PP_SET_EVENT(PP_EVENT_HDR_STOP_CNF);   
        }
	else if(PP_CTRL_CODE_START == CtrlCode)
	{
		StartTime = drv_get_current_time();
	    gHdrProcPara.MaxProcTime = HDR_PROCESS_MAX_TIME;

        MemSwitch.pMemAddr= (kal_uint32*)&(gHdrProcPara.SrcImgAddr);
        MemSwitch.Size = gHdrProcPara.SrcImgSize;
        MemSwitch.CacheableFlag=KAL_TRUE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

        MemSwitch.pMemAddr= (kal_uint32*)&(gHdrProcPara.WorkingBufAddr);
        MemSwitch.Size = SwHdrGetUseWorkingBufferSize();
        MemSwitch.CacheableFlag=KAL_TRUE;
        UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

		for(i=0;i<HDR_PROCESS_MAX_COUNT;i++)
        {
            /* HDR process */
			SwHdrCoreProc(&gHdrProcPara, &gHdrProcResult, ParaOutLen);
			/* Evaluated process time */
			TotalTime = drv_get_duration_ms(StartTime);
            if((HDR_PROCESS_MAX_TIME<=TotalTime)||(HDR_STATE_READY==gHdrProcResult.HdrState))
			{
				break;
			}
            else
            {
                gHdrProcPara.MaxProcTime = HDR_PROCESS_MAX_TIME - TotalTime;
            }
		}

        if(gHdrProcResult.HdrState == HDR_STATE_READY)
        {
            MemSwitch.pMemAddr= (kal_uint32*)&gHdrProcResult.ImgBufferAddr;
            MemSwitch.Size = (gHdrProcResult.ImgWidth*gHdrProcResult.ImgHeight*3)/2;//gHdrProcPara.SrcImgSize;
            MemSwitch.CacheableFlag=KAL_FALSE;
            UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

            MemSwitch.pMemAddr= (kal_uint32*)&(gHdrProcPara.WorkingBufAddr);
            MemSwitch.Size = SwHdrGetUseWorkingBufferSize();
            MemSwitch.CacheableFlag=KAL_FALSE;
            UtlFeatureCtrl(UTL_FEATURE_EXT_MEM_SWITCH_CACHE,&MemSwitch,NULL,NULL);

            pfPpHdrCb(PP_CBID_HDR_RESULT, &gHdrProcResult, sizeof(HDR_RESULT_STRUCT));
        }
    }

	return MM_ERROR_NONE;
}	/* SwHdrControl() */

HDR_FUNCTION_STRUCT HdrFuncMap=
{
    HdrOpen,
    HdrFeatureCtrl,
    HdrCtrl,
    HdrClose
};

MM_ERROR_CODE_ENUM HdrInit(MM_ERROR_CODE_ENUM (* pfHdrCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_HDR_FUNCTION_STRUCT *pfHdrFunc)
{
    pfPpHdrCb = pfHdrCallback;
    *pfHdrFunc=&HdrFuncMap;
    return MM_ERROR_NONE;
} /* HdrInit() */
#else /*#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)*/

MM_ERROR_CODE_ENUM HdrInit(MM_ERROR_CODE_ENUM (* pfHdrCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_HDR_FUNCTION_STRUCT *pfHdrFunc)
{
    return MM_ERROR_NONE;
}

//#endif	// #if defined(__HDR_SUPPORT__)
#endif
