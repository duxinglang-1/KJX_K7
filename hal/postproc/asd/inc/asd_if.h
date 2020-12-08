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
 *   Asd_if.h
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   ASD interface header
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
-----------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _ASD_IF_H_
#define _ASD_IF_H_

#include "kal_release.h"
//#include "asd_comm_def.h"
//#include "asd_core.h"
#include "decider_core.h"
#include "mm_comm_def.h"
#include "pp_comm_def.h"

typedef enum
{
	ASD_PROC_DECIDER = 0,
	ASD_PROC_MAIN,
	ASD_PROC_UNKNOWN
} ASD_PROC_ENUM;

typedef enum
{
	ASD_STATE_IDLE=0,
	ASD_STATE_STANDBY,
	ASD_STATE_SCD_INIT,
	ASD_STATE_READY,
	ASD_STATE_WAIT_PROC,
	ASD_STATE_PROC,
} ASD_STATE_ENUM;


/*****************************************************************************
	A.S.D.
******************************************************************************/
/* feature control enum */
typedef enum
{
	ASD_FEATURE_BEGIN,
        ASD_FEATURE_SET_DECIDER_ENV_INFO,
	ASD_FEATURE_SET_SCD_ENV_INFO,
	ASD_FEATURE_GET_ASD_ENV_INFO,
	ASD_FEATURE_GET_ASD_STATE,
	ASD_FEATURE_GET_ASD_RESULT,
	ASD_FEATURE_GET_SCD_RESULT,
	ASD_FEATURE_GET_SCD_STATUS,
	ASD_FEATURE_SET_SCD_STATUS,
	ASD_FEATURE_SET_SCD_LOG_INFO,
	ASD_FEATURE_SET_SCD_ABORT,		
	ASD_FEATURE_SAVE_DECIDER_LOG_INFO,		
	ASD_FEATURE_MAX
}	ASD_FEATURE_ENUM;

typedef struct
{
	DECIDER_INFO_STRUCT* pDeciderInfo;
	ASD_PROC_ENUM ProcId;
	kal_uint32 src_buffer_addr;
} ASD_PROCESS_STRUCT, *P_ASD_PROCESS_STRUCT;

typedef struct
{
    MM_ERROR_CODE_ENUM (* AsdOpen)(void);
    MM_ERROR_CODE_ENUM (* AsdFeatureCtrl) (ASD_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut, kal_uint16 FeatureParaOutLen);
    MM_ERROR_CODE_ENUM (* AsdCtrl) (PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode, void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);
    MM_ERROR_CODE_ENUM (* AsdClose)(void);
} ASD_FUNCTION_STRUCT, *P_ASD_FUNCTION_STRUCT;


extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);

MM_ERROR_CODE_ENUM AsdInit(MM_ERROR_CODE_ENUM (* pfAsdCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_ASD_FUNCTION_STRUCT *pfAsdFunc);

#endif	// _ASD_IF_H_
