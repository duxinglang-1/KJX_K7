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
 *   Hdr_if.h
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   HDR interface header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _HDR_IF_H_
#define _HDR_IF_H_

#include "mm_comm_def.h"
#include "Pp_comm_def.h"


typedef enum
{
    HDR_FEATURE_BEGIN,	// = PP_HDR_FEATURE_BEGIN,
    HDR_FEATURE_UPDATE_TUNING,
    HDR_FEATURE_SET_RAW_INFO,
    
    HDR_FEATURE_GET_ENV_INFO,
    HDR_FEATURE_SET_ENV_INFO,
    HDR_FEATURE_SET_PROC_INFO,
    HDR_FEATURE_GET_STATE,
    HDR_FEATURE_GET_RESULT,
    HDR_FEATURE_SAVE_LOG,
    HDR_FEATURE_MAX
}   HDR_FEATURE_ENUM;

typedef struct
{
    MM_ERROR_CODE_ENUM (* HdrOpen)(void);
    MM_ERROR_CODE_ENUM (* HdrFeatureCtrl) (HDR_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut, kal_uint16 FeatureParaOutLen);
    MM_ERROR_CODE_ENUM (* HdrCtrl) (PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode, void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);
    MM_ERROR_CODE_ENUM (* HdrClose)(void);
} HDR_FUNCTION_STRUCT, *P_HDR_FUNCTION_STRUCT;


MM_ERROR_CODE_ENUM HdrInit(MM_ERROR_CODE_ENUM (* pfHdrCallback) (PP_CALLBACK_ID_ENUM CbId,
                           void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_HDR_FUNCTION_STRUCT *pfHdrFunc);

#endif	// _HDR_IF_H_
