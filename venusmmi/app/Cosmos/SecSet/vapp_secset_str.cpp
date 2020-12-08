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
 *  vapp_secset_str.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Security setting
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

#include "vapp_secset_str.h"
#include "mmi_rp_vapp_secset_def.h"
#include "mmi_rp_vapp_secset_hpveri_def.h"

extern "C"
{
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "SimCtrlSrvGprot.h"
}

#define VAPP_SECSET_MAX_STR_LEN 128


#if (MMI_MAX_SIM_NUM >= 2)
static const MMI_STR_ID vapp_secset_sim_id_name[] =
{
    STR_GLOBAL_SIM_1,
    STR_GLOBAL_SIM_2,
#if (MMI_MAX_SIM_NUM >= 3)
    STR_GLOBAL_SIM_3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    STR_GLOBAL_SIM_4
#endif
};
#endif


typedef struct
{
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_STR_ID simx_str[VappSecSetStr::SIM_STR_TOTAL];
#endif
    MMI_STR_ID sim_str[VappSecSetStr::SIM_STR_TOTAL];
} vapp_secset_sim_str_struct;

static const vapp_secset_sim_str_struct vapp_secset_sim_str =
{
#if (MMI_MAX_SIM_NUM >= 2)
    { STR_ID_VAPP_SECSET_SIMX_BLOCKED },
#endif
    { STR_ID_VAPP_SECSET_SIM_BLOCKED }
};


typedef enum
{
    VAPP_SECSET_CHV1_INDEX = 0,
    VAPP_SECSET_CHV2_INDEX,

    VAPP_SECSET_CHV_INDEX_TOTAL
} vapp_secset_chv_index_enum;

typedef struct
{
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_STR_ID simx_chv[VAPP_SECSET_CHV_INDEX_TOTAL][VappSecSetStr::CHV_STR_TOTAL];
#endif
    MMI_STR_ID sim_chv[VAPP_SECSET_CHV_INDEX_TOTAL][VappSecSetStr::CHV_STR_TOTAL];
} vapp_secset_chv_string_struct;


static const vapp_secset_chv_string_struct vapp_secset_chv_string =
{
#if (MMI_MAX_SIM_NUM >= 2)
    { { /* CHV1 */
        STR_ID_VAPP_SECSET_SIMX_INPUT_CHV1,
        STR_ID_VAPP_SECSET_WRONG_CHV1,
        STR_ID_VAPP_SECSET_SIMX_OLD_CHV1,
        STR_ID_VAPP_SECSET_SIMX_NEW_CHV1,
        STR_ID_VAPP_SECSET_CONFIRM_NEW_CHV1,
        STR_ID_VAPP_SECSET_CHV1_NOT_MATCH,
        STR_ID_VAPP_SECSET_ENABLE_CHV1_PROMPT,
        STR_ID_VAPP_SECSET_SIMX_CHV1_CHANGED,
        
        STR_ID_VAPP_SECSET_SIMX_CHV1_BLOCKED,
        STR_ID_VAPP_SECSET_SIMX_CHV1_BLOCKED_REQ_UBCHV,
        STR_ID_VAPP_SECSET_SIMX_INPUT_UBCHV1,
        STR_ID_VAPP_SECSET_WRONG_UBCHV1,
        STR_ID_VAPP_SECSET_SIMX_UBCHV1_BLOCKED,
        STR_ID_VAPP_SECSET_SIMX_CHV1_UNBLOCKED
    },
    { /* CHV2 */
        STR_ID_VAPP_SECSET_SIMX_INPUT_CHV2,
        STR_ID_VAPP_SECSET_WRONG_CHV2,
        STR_ID_VAPP_SECSET_SIMX_OLD_CHV2,
        STR_ID_VAPP_SECSET_SIMX_NEW_CHV2,
        STR_ID_VAPP_SECSET_CONFIRM_NEW_CHV2,
        STR_ID_VAPP_SECSET_CHV2_NOT_MATCH,
        STR_ID_VAPP_SECSET_CHV2_DISABLED,
        STR_ID_VAPP_SECSET_SIMX_CHV2_CHANGED,
        
        STR_ID_VAPP_SECSET_SIMX_CHV2_BLOCKED,
        STR_ID_VAPP_SECSET_SIMX_CHV2_BLOCKED_REQ_UBCHV,
        STR_ID_VAPP_SECSET_SIMX_INPUT_UBCHV2,
        STR_ID_VAPP_SECSET_WRONG_UBCHV2,
        STR_ID_VAPP_SECSET_SIMX_UBCHV2_BLOCKED,
        STR_ID_VAPP_SECSET_SIMX_CHV2_UNBLOCKED
    } },
#endif // (MMI_MAX_SIM_NUM >= 2)
    // Single SIM
    { { /* CHV1 */
        STR_ID_VAPP_SECSET_INPUT_CHV1,
        STR_ID_VAPP_SECSET_WRONG_CHV1,
        STR_ID_VAPP_SECSET_OLD_CHV1,
        STR_ID_VAPP_SECSET_NEW_CHV1,
        STR_ID_VAPP_SECSET_CONFIRM_NEW_CHV1,
        STR_ID_VAPP_SECSET_CHV1_NOT_MATCH,
        STR_ID_VAPP_SECSET_ENABLE_CHV1_PROMPT,
        STR_ID_VAPP_SECSET_CHV1_CHANGED,
        
        STR_ID_VAPP_SECSET_CHV1_BLOCKED,
        STR_ID_VAPP_SECSET_CHV1_BLOCKED_REQ_UBCHV,
        STR_ID_VAPP_SECSET_INPUT_UBCHV1,
        STR_ID_VAPP_SECSET_WRONG_UBCHV1,
        STR_ID_VAPP_SECSET_UBCHV1_BLOCKED,
        STR_ID_VAPP_SECSET_CHV1_UNBLOCKED
    },
    { /* CHV2 */
        STR_ID_VAPP_SECSET_INPUT_CHV2,
        STR_ID_VAPP_SECSET_WRONG_CHV2,
        STR_ID_VAPP_SECSET_OLD_CHV2,
        STR_ID_VAPP_SECSET_NEW_CHV2,
        STR_ID_VAPP_SECSET_CONFIRM_NEW_CHV2,
        STR_ID_VAPP_SECSET_CHV2_NOT_MATCH,
        STR_ID_VAPP_SECSET_CHV2_DISABLED,
        STR_ID_VAPP_SECSET_CHV2_CHANGED,
        
        STR_ID_VAPP_SECSET_CHV2_BLOCKED,
        STR_ID_VAPP_SECSET_CHV2_BLOCKED_REQ_UBCHV,
        STR_ID_VAPP_SECSET_INPUT_UBCHV2,
        STR_ID_VAPP_SECSET_WRONG_UBCHV2,
        STR_ID_VAPP_SECSET_UBCHV2_BLOCKED,
        STR_ID_VAPP_SECSET_CHV2_UNBLOCKED
    } }
};


/****************************************************************************
 * Functions
 ****************************************************************************/


VfxResId VappSecSetStr::getSimIDNameByIndex(VfxS32 simIndex)
{
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        return vapp_secset_sim_id_name[simIndex];
    }
#endif

    return STR_GLOBAL_SIM;
}


VfxWString VappSecSetStr::composeSimStr(
    VfxResId str_template_id,
    mmi_sim_enum sim)
{
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        VfxS32 simIndex = mmi_frm_sim_to_index(sim);
        VfxWChar *buffer = (VfxWChar *)OslMalloc((VAPP_SECSET_MAX_STR_LEN + 1) * sizeof(VfxWChar));
        
        mmi_wsprintf(
            buffer,
            (VAPP_SECSET_MAX_STR_LEN + 1) * sizeof(VfxWChar),
            str_template_id,
            getSimIDNameByIndex(simIndex));
            
        VfxWString str(buffer);
        OslMfree(buffer);

        return str;
    }
#endif

    return VFX_WSTR_RES(STR_ID_VAPP_SECSET_SIM_READY);
}


VfxWString VappSecSetStr::getSimStr(
    mmi_sim_enum sim,
    VappSecSetStr::SimStrEnum type)
{
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        return composeSimStr(vapp_secset_sim_str.simx_str[type], sim);
    }
#endif

    return VFX_WSTR_RES(vapp_secset_sim_str.sim_str[type]);
}


VfxWString VappSecSetStr::getChvStr(
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum chv_type,
    VappSecSetStr::ChvStrEnum str_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 chv_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chv_index = 0;
    if (chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ||
        chv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
    {
        chv_index = VAPP_SECSET_CHV1_INDEX;
    }
    else
    {
        chv_index = VAPP_SECSET_CHV2_INDEX;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        return composeSimStr(vapp_secset_chv_string.simx_chv[chv_index][str_type], sim);
    }
#endif

    return VFX_WSTR_RES(vapp_secset_chv_string.sim_chv[chv_index][str_type]);
}


VfxWString VappSecSetStr::getSimFailureMessage(
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum chv_type,
    srv_sim_ctrl_fail_cause_enum cause)
{
    switch (cause)
    {
        case SRV_SIM_CTRL_FAIL_CAUSE_NONE:
            return VFX_WSTR_RES(STR_GLOBAL_DONE);

        case SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD:
            if (chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ||
                chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV2)
            {
                return getChvStr(sim, chv_type, STR_WRONG_CHV);
            }
            else
            {
                return getChvStr(sim, chv_type, STR_WRONG_UBCHV);
            }

        case SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED:
            if (chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ||
                chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV2)
            {
                return getChvStr(sim, chv_type, STR_CHV_BLOCKED);
            }
            else
            {
                return getChvStr(sim, chv_type, STR_UBCHV_BLOCKED);
            }

        case SRV_SIM_CTRL_FAIL_CAUSE_TEMP_FAIL:
            return VFX_WSTR_RES(STR_ID_VAPP_SECSET_TEMP_FAIL);

        case SRV_SIM_CTRL_FAIL_CAUSE_SIM_ERROR:
            return VFX_WSTR_RES(STR_ID_VAPP_SECSET_SIM_ERROR);

        default:
            break;
    }

    return VFX_WSTR_RES(STR_GLOBAL_ERROR);
}


VfxWString VappSecSetStr::getRemainingPromptStr(
    S32 nRemainingAttempts,
    VfxObject *tempBufferSrc)
{
    static const VfxS32 MAX_BUFFER_LEN = VAPP_SECSET_MAX_STR_LEN;
    VfxWChar *buffer;
    VFX_ALLOC_MEM(buffer, (MAX_BUFFER_LEN + 1) * 2, tempBufferSrc);

    mmi_wsprintf(
        buffer,
        (MAX_BUFFER_LEN + 1) * 2,
        STR_ID_VAPP_SECSET_REMAINING_TRIALS_PROMPT,
        nRemainingAttempts);

    VfxWString str(buffer);
    VFX_FREE_MEM(buffer);
    
    return str;
}


VfxWString VappSecSetStr::getFailureMsgWithRemaining(
    const VfxWString &prompt,
    S32 nRemainingAttempts,
    VfxObject *tempBufferSrc)
{
    static const VfxS32 MAX_BUFFER_LEN = VAPP_SECSET_MAX_STR_LEN;
    VfxWChar *buffer;
    VFX_ALLOC_MEM(buffer, (MAX_BUFFER_LEN + 1) * 2, tempBufferSrc);

    mmi_wsprintf_ex(
        buffer,
        (MAX_BUFFER_LEN + 1) * 2,
        (WCHAR*)L"%w\n%w",
        prompt.getBuf(),
        getRemainingPromptStr(nRemainingAttempts, tempBufferSrc).getBuf());

    VfxWString str(buffer);
    VFX_FREE_MEM(buffer);
    
    return str;
}
