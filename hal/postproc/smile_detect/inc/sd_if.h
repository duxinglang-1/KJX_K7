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
 *   sd_if.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   smile detection process header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _SD_IF_H_
#define _SD_IF_H_

#include "pp_comm_def.h"
#include "mm_comm_def.h"
#include "pp_if.h"

#define SD_VERSION		201101

typedef enum
{
	SD_IDLE_STATE=0,
	SD_READY_STATE,
	SD_MEM_PROCESS_STATE,
	SD_FD_PROCESS_STATE,
	SD_PROCESS_STATE
} SD_STATE_ENUM;

typedef enum
{
	SD_FEATURE_BEGIN,
	SD_FEATURE_GET_ENV_INFO,
	SD_FEATURE_SET_ENV_INFO,
	SD_FEATURE_SET_PROC_INFO,
	SD_FEATURE_GET_STATE,
	SD_FEATURE_GET_RESULT,
	SD_FEATURE_SET_LOG_INFO,
	SD_FEATURE_MAX
}	SD_FEATURE_ENUM;

typedef struct
{
	kal_uint32			PpSrcBufAddr;
	kal_uint32 			PpSrcBufSize;	
	PP_MEM_OP_TYPE_ENUM	PpMemOpType;					
	kal_uint32			PpProcBufAddr;
	kal_uint32 			PpProcBufSize;
	MM_IMAGE_FORMAT_ENUM	PpProcFmt;				
} SD_SET_MEM_INFO_STRUCT, *P_SD_SET_MEM_INFO_STRUCT;


typedef struct
{	
	kal_bool sd_enable;
} SD_PROC_PARA_IN_STRUCT, *P_SD_PROC_PARA_IN_STRUCT;

typedef struct
{
   MM_ERROR_CODE_ENUM (* SdOpen)(void);
   MM_ERROR_CODE_ENUM (* SdFeatureCtrl) (SD_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut, kal_uint16 FeatureParaOutLen);
   MM_ERROR_CODE_ENUM (*SdCtrl)(PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode,void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen);
//   MM_ERROR_CODE_ENUM (* SdCtrl) (PP_SCENARIO_ENUM ScenarioId, void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);
   MM_ERROR_CODE_ENUM (* SdClose)(void);
} SD_FUNCTION_STRUCT, *P_SD_FUNCTION_STRUCT;

/****************************************************************************
 *          Extern Time Log Interface
 ****************************************************************************/ 
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);

MM_ERROR_CODE_ENUM SdInit(MM_ERROR_CODE_ENUM (* pfSdCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_SD_FUNCTION_STRUCT *pfSdFunc);

#endif	// _SD_IF_H_
