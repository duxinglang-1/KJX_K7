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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_bootup_sim_str.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  String configuration for SIM.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_bootup.h"
#include "vapp_bootup_app.h"
#include "GlobalResDef.h"
extern "C"
{
#include "SimCtrlSrvGprot.h"
}
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"

#define VAPP_BOOTUP_MAX_STR_LEN 128


typedef struct
{
    srv_bootup_verification_type_enum type;
    VfxU16 sim_input_prompt;
#if (MMI_MAX_SIM_NUM >= 2)
    VfxU16 simx_input_prompt;
#endif
    VfxU16 wrong_msg;
} vapp_bootup_sim_prompt_string_struct;

typedef struct
{
    srv_sim_ctrl_ua_cause_enum cause;
#if (MMI_MAX_SIM_NUM >= 2)
    VfxU16 simx_error_str;
#endif
    VfxU16 sim_error_str;
} vapp_bootup_sim_error_string_struct;


#if (MMI_MAX_SIM_NUM >= 2)
static const VfxU16 g_vapp_bootup_sim_str[] =
{
    STR_GLOBAL_SIM_1,
    STR_GLOBAL_SIM_2,
#if (MMI_MAX_SIM_NUM >= 3)
    STR_GLOBAL_SIM_3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    STR_GLOBAL_SIM_4,
#endif
};
#endif


static const vapp_bootup_sim_prompt_string_struct g_vapp_bootup_sec_sim_prompts[] =
{
    { SRV_BOOTUP_VERI_CHV1,
        STR_ID_VAPP_BOOTUP_INPUT_CHV1,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_CHV1,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_CHV1 },
    { SRV_BOOTUP_VERI_UBCHV1,
        STR_ID_VAPP_BOOTUP_INPUT_UBCHV1,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_UBCHV1,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_UBCHV1 },
    { SRV_BOOTUP_VERI_NP,
        STR_ID_VAPP_BOOTUP_INPUT_NP,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_NP,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_NP },
    { SRV_BOOTUP_VERI_NSP,
        STR_ID_VAPP_BOOTUP_INPUT_NSP,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_NSP,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_NSP },
    { SRV_BOOTUP_VERI_SP,
        STR_ID_VAPP_BOOTUP_INPUT_SP,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_SP,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_SP },
    { SRV_BOOTUP_VERI_CP,
        STR_ID_VAPP_BOOTUP_INPUT_CP,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_CP,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_CP },
    { SRV_BOOTUP_VERI_SIMP,
        STR_ID_VAPP_BOOTUP_INPUT_SIMP,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_SIMP,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_SIMP },
#ifdef __MMI_SML_MENU__
    { SRV_BOOTUP_VERI_NSSP,
        STR_ID_VAPP_BOOTUP_INPUT_NSSP,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_NSSP,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_NSSP },
    { SRV_BOOTUP_VERI_SIMCP,
        STR_ID_VAPP_BOOTUP_INPUT_SIMCP,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_INPUT_SIMCP,
    #endif
        STR_ID_VAPP_BOOTUP_WRONG_SIMCP },
#endif /* __MMI_SML_MENU__ */
    /* ------------------------------------------ */
    { SRV_BOOTUP_VERI_END_OF_ENUM,
        0,
    #if (MMI_MAX_SIM_NUM >= 2)
        0,
    #endif
        0 }
};


/* If SIM error detected, the string we want to prompt user */
static const vapp_bootup_sim_error_string_struct g_vapp_bootup_sec_sim_errors[] =
{
    { SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_REMOVED,
    #endif
        STR_ID_VAPP_BOOTUP_SIM_REMOVED },
    { SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_ACCESS_ERROR,
    #endif
        STR_ID_VAPP_BOOTUP_SIM_ACCESS_ERROR },
    { SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_CHV1_BLOCKED,
    #endif
        STR_ID_VAPP_BOOTUP_SIM_CHV1_BLOCKED },
    { SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_BLOCKED,
    #endif
        STR_ID_VAPP_BOOTUP_SIM_BLOCKED },
    { SRV_SIM_CTRL_UA_CAUSE_PERSON_BLOCKED,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_BOOTUP_SIMX_BLOCKED,
    #endif
        STR_ID_VAPP_BOOTUP_SIM_BLOCKED },
    /* ----------------------------------------- */
    { SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM,
    #if (MMI_MAX_SIM_NUM >= 2)
        0,
    #endif
      0 }
};



VfxResId VappBootupSimStr::getSimStrByIndex(VfxS32 sim_index)
{
#if (MMI_MAX_SIM_NUM >= 2)
    return g_vapp_bootup_sim_str[sim_index];
#else
    return STR_GLOBAL_SIM;
#endif
}


VfxWString VappBootupSimStr::composeSimStr(
    VfxResId str_template_id,
    mmi_sim_enum sim)
{
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        VfxS32 simIndex = mmi_frm_sim_to_index(sim);
        
        VfxWChar *buffer = (VfxWChar *)OslMalloc((VAPP_BOOTUP_MAX_STR_LEN + 1) * sizeof(VfxWChar));        
        mmi_wsprintf(
            buffer,
            (VAPP_BOOTUP_MAX_STR_LEN + 1) * sizeof(VfxWChar),
            str_template_id,
            VappBootupSimStr::getSimStrByIndex(simIndex));
            
        VfxWString str = VFX_WSTR_MEM(buffer);
		
        OslMfree(buffer);

        return str;
    }
#endif

    return VFX_WSTR_RES(str_template_id);
}


/*****************************************************************************
 * FUNCTION
 *  VappBootupSimStr::getInputPrompt
 * DESCRIPTION
 *  Get the input prompt of the verification type.
 * PARAMETERS
 *  sim         [IN] Which SIM
 *  veri_type   [IN] Verification type
 * RETURNS
 *  String ID of the prompt
 *****************************************************************************/
VfxWString VappBootupSimStr::getInputPrompt(
    mmi_sim_enum sim,
    srv_bootup_verification_type_enum veri_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxResId msg_id;
    const vapp_bootup_sim_prompt_string_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = STR_GLOBAL_PASSWORD;

    for (entry = g_vapp_bootup_sec_sim_prompts;
         entry->type != SRV_BOOTUP_VERI_END_OF_ENUM;
         entry++)
    {
        if (entry->type == veri_type)
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            if (srv_sim_ctrl_get_num_of_inserted() >= 2)
            {
                msg_id = entry->simx_input_prompt;
            }
            else
        #endif
            {
                msg_id = entry->sim_input_prompt;
            }
            break;
        }
    }

#if (MMI_MAX_SIM_NUM >= 2)
    return composeSimStr(msg_id, sim);
#else
    return VFX_WSTR_RES(msg_id);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  VappBootupSimStr::getMessageOfResult
 * DESCRIPTION
 *  Get the prompt string of verification result.
 * PARAMETERS
 *  result   [IN] Result
 * RETURNS
 *  String ID of the prompt
 *****************************************************************************/
VfxWString VappBootupSimStr::getMessageOfResult(
    const srv_bootup_verify_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxResId msg_id;
    const vapp_bootup_sim_prompt_string_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result->success)
    {
        return VFX_WSTR_RES(STR_GLOBAL_DONE);
    }

    if (result->type == SRV_BOOTUP_VERI_PHONE_LOCK)
    {
        return VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_WRONG_PHONE_PASSWORD);
    }

    msg_id = STR_GLOBAL_ERROR;
    
    for (entry = g_vapp_bootup_sec_sim_prompts;
         entry->type != SRV_BOOTUP_VERI_END_OF_ENUM;
         entry++)
    {
        if (entry->type == result->type)
        {
            msg_id = entry->wrong_msg;
            break;
        }
    }

    return VFX_WSTR_RES(msg_id);
}


VfxWString VappBootupSimStr::getSimErrorMsg(mmi_sim_enum sim, srv_sim_ctrl_ua_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxResId msg_id;
    const vapp_bootup_sim_error_string_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = STR_GLOBAL_ERROR;
    
    for (entry = g_vapp_bootup_sec_sim_errors;
         entry->cause != SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM;
         entry++)
    {
        if (entry->cause == cause)
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            if (srv_sim_ctrl_get_num_of_inserted() >= 2)
            {
                msg_id = entry->simx_error_str;
            }
            else
        #endif
            {
                msg_id = entry->sim_error_str;
            }
            break;
        }
    }
    
#if (MMI_MAX_SIM_NUM >= 2)
    return composeSimStr(msg_id, sim);
#else
    return VFX_WSTR_RES(msg_id);
#endif
}


VfxWString VappBootupSimStr::getRemainingPromptStr(
    S32 nRemainingAttempts,
    VfxObject *tempBufferSrc)
{
    VfxWChar *buffer;
    VFX_ALLOC_MEM(buffer, (VAPP_BOOTUP_MAX_STR_LEN + 1) * sizeof(VfxWChar), tempBufferSrc);
    
    mmi_wsprintf(
        buffer,
        (VAPP_BOOTUP_MAX_STR_LEN + 1) * sizeof(VfxWChar),
        STR_ID_VAPP_BOOTUP_REMAINING_TRIALS_PROMPT,
        nRemainingAttempts);

    VfxWString str = VFX_WSTR_MEM(buffer);
    VFX_FREE_MEM(buffer);
    
    return str;
}


VfxWString VappBootupSimStr::getFailureMsgWithRemaining(
    const VfxWString &prompt,
    S32 nRemainingAttempts,
    VfxObject *tempBufferSrc)
{
    VfxWChar *buffer;
    VFX_ALLOC_MEM(buffer, (VAPP_BOOTUP_MAX_STR_LEN + 1) * sizeof(VfxWChar), tempBufferSrc);
    
    mmi_wsprintf_ex(
        buffer,
        (VAPP_BOOTUP_MAX_STR_LEN + 1) * sizeof(VfxWChar),
        (WCHAR*)L"%w\n%w",
        prompt.getBuf(),
        getRemainingPromptStr(nRemainingAttempts, tempBufferSrc).getBuf());
        
    VfxWString str = VFX_WSTR_MEM(buffer);
    VFX_FREE_MEM(buffer);
    
    return str;
}
#pragma arm section code, rodata
