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
 *	.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
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
#ifndef __PP_IF_H__
#define __PP_IF_H__

#include "kal_release.h"
#include "pp_comm_def.h"
#include "pp_api.h"

/** PP State Control */
extern PP_STATE_ENUM 	gPpState;
extern PP_STATE_ENUM	gPpStateList[PP_FUNC_MAX];
extern kal_uint32		gPpEnableList;
#define	PP_SET_FEATURE_ENABLE(n)		{gPpEnableList |= (1<<n);}
#define	PP_SET_FEATURE_DISABLE(n)		{gPpEnableList &= ~(1<<n);}
#define	PP_IS_FEATURE_ENABLE(n)			((gPpEnableList&(1<<n))>0)
#define	PP_SET_FEATURE_STATE(n, s)		{gPpStateList[n] = s;}
#define	PP_GET_FEATURE_STATE(n)			(gPpStateList[n])
#define	PP_CHECK_FEATURE_STATE(n, s)	(gPpStateList[n] == s)

/* Function Pointer Define */
typedef MM_ERROR_CODE_ENUM (*PpFuncFeatureCtrl)(PP_FEATURE_ENUM CtrlId, void *pInPara,
                           					void *pOutPara, kal_uint32 OutParaLen);
typedef MM_ERROR_CODE_ENUM (*PpFuncCallbackProc)(PP_CALLBACK_ID_ENUM CbId, 
											void *pCallbackPara, kal_uint16 CallbackParaLen);                           					                          					
typedef struct 
{
	PP_FUNC_ENUM		FuncID;
	PpFuncFeatureCtrl	fPFuncFeatureCtrl;	
}PpFunc;

/* Scenario Control Functions */
extern MM_ERROR_CODE_ENUM PpPreviewCtrl(PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen);
extern MM_ERROR_CODE_ENUM PpCaptureCtrl(PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen);
extern MM_ERROR_CODE_ENUM PpBgPostProcCtrl(PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen);
extern MM_ERROR_CODE_ENUM PpPostProcCtrl(PP_SCENARIO_CTRL_ENUM CtrlId, void *pInPara,
                           void *pOutPara, kal_uint32 OutParaLen);

/* Feacure Control Functions */
extern MM_ERROR_CODE_ENUM PpFdFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara, void *pOutPara, kal_uint32 OutParaLen);
extern MM_ERROR_CODE_ENUM PpSdFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara, void *pOutPara, kal_uint32 OutParaLen);
extern MM_ERROR_CODE_ENUM PpPanoFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara, void *pOutPara, kal_uint32 OutParaLen);
extern MM_ERROR_CODE_ENUM PpHdrFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara, void *pOutPara, kal_uint32 OutParaLen);
extern MM_ERROR_CODE_ENUM PpAutoCapFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara, void *pOutPara, kal_uint32 OutParaLen);
extern MM_ERROR_CODE_ENUM PpAsdFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara, void *pOutPara, kal_uint32 OutParaLen);    
extern MM_ERROR_CODE_ENUM PpMavCapFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara, void *pOutPara, kal_uint32 OutParaLen);    
extern MM_ERROR_CODE_ENUM PpMavFeatureCtrl(PP_FEATURE_ENUM CtrlId, void *pInPara, void *pOutPara, kal_uint32 OutParaLen);    

extern MM_ERROR_CODE_ENUM (* pfPpCb) (PP_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen);

/* extern tuning parameter */
extern CAMERA_POST_PROCESS_PARA_STRUCT PpTuningOperPara;

/* extern proc info parameter */
extern PP_PROC_INFO_STRUCT	gPpProcInfoPara;

/* extern PP Events related definition */
extern kal_eventgrpid gPpEvent;

#define PP_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         kal_retrieve_eg_events(gPpEvent, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define PP_SET_EVENT(evt_) do{                                                          \
                              kal_set_eg_events(gPpEvent, (evt_),KAL_OR);\
                              } while(0)
/* PP Event Define */
typedef enum
{
    PP_EVENT_PANO_STOP_CNF = 0x00000001,
    PP_EVENT_PANO_PAUSE_CNF = 0x00000002,
    PP_EVENT_ASD_STOP_CNF = 0x00000003,    
    PP_EVENT_HDR_STOP_CNF = 0x00000004,
    PP_EVENT_MAV_STOP_CNF = 0x00000005,
} PP_EVENT_ENUM;

/* PP Process memory operation define */
typedef enum
{
    PP_MEM_OP_NONE,	
    PP_MEM_OP_COPY_TO_PROC_BUF,	
    PP_MEM_OP_RESIZE_TO_PROC_BUF,	    
    PP_MEM_OP_MAX,	
} PP_MEM_OP_TYPE_ENUM;

#endif /* __PP_IF_H__ */
