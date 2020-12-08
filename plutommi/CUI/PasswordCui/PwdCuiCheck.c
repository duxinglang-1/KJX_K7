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
 *  PwdCuiCheck.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CUI of password, it requires 2 inputs, and will check whether they are
 *  the same. Usually used for new password scenario.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "PwdCui.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_mem_gprot.h"
#include "PwdCuiGprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_rp_cui_password_def.h"
#include "MMI_trc_Int.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

#define CUI_PWD_CHECK_VALID_MAGIC 0x10C0ECC0

typedef struct
{
    U32 valid_magic;
    mmi_id parent_grp_id;
    mmi_id this_grp_id;
    mmi_id first_pwd_cui;
    mmi_id second_pwd_cui;
    MMI_STR_ID input_prompt_str_id;
    MMI_STR_ID confirm_prompt_str_id;
    MMI_STR_ID diff_input_str_id;
    MMI_STR_ID done_str_id;
    MMI_STR_ID cancel_str_id;
    mmi_proc_func proc;
    void *user_data;
    S8 min_pwd_len;
    S8 max_pwd_len;
} cui_pwd_check_cntx_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/

static mmi_ret cui_pwd_check_second_pwd_proc(mmi_event_struct *evt);


static cui_pwd_check_cntx_struct *cui_pwd_check_get_cntx(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_check_cntx_struct*)mmi_frm_group_get_user_data(instance_id);
    
    MMI_ASSERT(cntx != NULL);
    MMI_ASSERT(cntx->valid_magic == CUI_PWD_CHECK_VALID_MAGIC);

    return cntx;
}


static mmi_ret cui_pwd_check_send_to_parent(
                cui_pwd_check_cntx_struct *cntx,
                void *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    mmi_group_event_struct *grp_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_evt = (mmi_group_event_struct*)evt;
    grp_evt->sender_id = cntx->this_grp_id;
    
    if (cntx->proc != NULL)
    {
        ret = MMI_FRM_SEND_EVENT(grp_evt, cntx->proc, cntx->user_data);
    }
    else
    {
        ret = mmi_frm_group_send_to_parent(
                cntx->this_grp_id,
                grp_evt);
    }

    return ret;
}


static mmi_ret cui_pwd_check_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {
        /* Free the context */
        cntx = (cui_pwd_check_cntx_struct*)evt->user_data;

        MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_CHECK_GROUP_DEINIT, cntx->this_grp_id, (U32)cntx);
        
        cntx->valid_magic = 0;
        mmi_mfree(cntx);
    }

    return MMI_RET_OK;
}


static mmi_ret cui_pwd_check_first_pwd_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_check_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
            cntx->second_pwd_cui = cui_pwd_basic_create(
                cntx->this_grp_id,
                cntx->confirm_prompt_str_id,
                cntx->min_pwd_len,
                cntx->max_pwd_len);
            cui_pwd_basic_set_action_str(cntx->second_pwd_cui, cntx->done_str_id, STR_GLOBAL_BACK);
            cui_pwd_basic_set_proc(cntx->second_pwd_cui, cui_pwd_check_second_pwd_proc, cntx);
            cui_pwd_basic_run(cntx->second_pwd_cui);
            break;

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
        {
            cui_pwd_check_cancel_evt_struct cancel_evt;
            
            MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_CUI_PWD_CHECK_CANCEL);
            return cui_pwd_check_send_to_parent(cntx, &cancel_evt);
        }

        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
        {
            cui_pwd_check_passive_closing_evt_struct closing_evt;
            
            MMI_FRM_INIT_EVENT(&closing_evt, EVT_ID_CUI_PWD_CHECK_PASSIVE_CLOSING);
            return cui_pwd_check_send_to_parent(cntx, &closing_evt);            
        }

        case EVT_ID_CUI_PWD_BASIC_KEY:
        {
            cui_pwd_check_key_evt_struct key_evt;
            cui_pwd_basic_key_evt_struct *src_key_evt;

            src_key_evt = (cui_pwd_basic_key_evt_struct*)evt;
            MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_CUI_PWD_CHECK_KEY);
            key_evt.key_evt_id = src_key_evt->key_evt_id;
            key_evt.key_code = src_key_evt->key_code;
            key_evt.key_type = src_key_evt->key_type;
            return cui_pwd_check_send_to_parent(cntx, &key_evt);
        }

        case EVT_ID_CUI_PWD_BASIC_AUX:
        {
            cui_pwd_check_aux_evt_struct aux_evt;
            cui_pwd_basic_aux_evt_struct *src_aux_evt;

            src_aux_evt = (cui_pwd_basic_aux_evt_struct*)evt;
            if (src_aux_evt->type == CUI_PWD_AUXILIARY_BASIC_DEFAULT)
            {
                MMI_FRM_INIT_EVENT(&aux_evt, EVT_ID_CUI_PWD_CHECK_AUX);
                aux_evt.type = CUI_PWD_AUXILIARY_CHECK_DEFAULT;
                return cui_pwd_check_send_to_parent(cntx, &aux_evt);
            }

            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret cui_pwd_check_second_pwd_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_check_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            const WCHAR *first_input;
            cui_pwd_basic_done_evt_struct *done_evt;

            done_evt = (cui_pwd_basic_done_evt_struct*)evt;
            first_input = cui_pwd_basic_get_input(cntx->first_pwd_cui);

            if (mmi_wcscmp(first_input, done_evt->input) == 0)
            {
                cui_pwd_check_done_evt_struct my_done_evt;

                MMI_FRM_INIT_EVENT(&my_done_evt, EVT_ID_CUI_PWD_CHECK_DONE);
                my_done_evt.input = done_evt->input;
                return cui_pwd_check_send_to_parent(cntx, &my_done_evt);
            }
            else
            {
                mmi_popup_display_simple(
                    get_string(cntx->diff_input_str_id),
                    MMI_EVENT_FAILURE,
                    cntx->this_grp_id,
                    cntx);

                cui_pwd_basic_clear_input(cntx->first_pwd_cui);
                cui_pwd_basic_close(cntx->second_pwd_cui);
                cntx->second_pwd_cui = 0;
            }
            break;
        }

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
            cui_pwd_basic_close(cntx->second_pwd_cui);
            cntx->second_pwd_cui = 0;
            break;

        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
            /* OK, allow to close */
            cntx->second_pwd_cui = 0;
            break;

        case EVT_ID_CUI_PWD_BASIC_KEY:
        {
            cui_pwd_check_key_evt_struct key_evt;
            cui_pwd_basic_key_evt_struct *src_key_evt;

            src_key_evt = (cui_pwd_basic_key_evt_struct*)evt;
            MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_CUI_PWD_CHECK_KEY);
            key_evt.key_evt_id = src_key_evt->key_evt_id;
            key_evt.key_code = src_key_evt->key_code;
            key_evt.key_type = src_key_evt->key_type;
            return cui_pwd_check_send_to_parent(cntx, &key_evt);
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


mmi_id cui_pwd_check_create(
    mmi_id parent_grp_id,
    MMI_STR_ID input_prompt_str_id,
    MMI_STR_ID confirm_prompt_str_id,
    S32 min_pwd_len,
    S32 max_pwd_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(0 < min_pwd_len && min_pwd_len <= max_pwd_len);

    cntx = (cui_pwd_check_cntx_struct*)mmi_malloc(sizeof(cui_pwd_check_cntx_struct));

    cntx->valid_magic = CUI_PWD_CHECK_VALID_MAGIC;
    cntx->parent_grp_id = parent_grp_id;
    cntx->first_pwd_cui = 0;
    cntx->second_pwd_cui = 0;
    cntx->input_prompt_str_id = input_prompt_str_id;
    cntx->confirm_prompt_str_id = confirm_prompt_str_id;
    cntx->diff_input_str_id = STR_ID_CUI_PWD_DIFFERENT_INPUT;
    cntx->done_str_id = STR_GLOBAL_OK;
    cntx->cancel_str_id = STR_GLOBAL_BACK;
    cntx->proc = NULL;
    cntx->user_data = NULL;
    cntx->min_pwd_len = (S8)min_pwd_len;
    cntx->max_pwd_len = (S8)max_pwd_len;

    cntx->this_grp_id = mmi_frm_group_create(
        parent_grp_id,
        GRP_ID_AUTO_GEN,
        cui_pwd_check_grp_proc,
        cntx);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_CHECK_CREATE,
        parent_grp_id, cntx->this_grp_id, (U32)cntx);

    return cntx->this_grp_id;
}


void cui_pwd_check_set_action_str(mmi_id instance_id, MMI_STR_ID done_str_id, MMI_STR_ID cancel_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_check_get_cntx(instance_id);

    if (done_str_id != 0)
    {
        cntx->done_str_id = done_str_id;
    }
    if (cancel_str_id != 0)
    {
        cntx->cancel_str_id = cancel_str_id;
    }
}


void cui_pwd_check_set_diff_input_prompt(mmi_id instance_id, MMI_STR_ID prompt_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_check_get_cntx(instance_id);

    cntx->diff_input_str_id = prompt_str_id;
}


void cui_pwd_check_set_proc(mmi_id instance_id, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_check_get_cntx(instance_id);

    cntx->proc = proc;
    cntx->user_data = user_data;
}


void cui_pwd_check_run(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_check_get_cntx(instance_id);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_CHECK_RUN, instance_id, (U32)cntx->proc);

    mmi_frm_group_enter(cntx->this_grp_id, MMI_FRM_NODE_NONE_FLAG);

    MMI_ASSERT(cntx->first_pwd_cui == GRP_ID_INVALID);
    cntx->first_pwd_cui = cui_pwd_basic_create(
        cntx->this_grp_id,
        cntx->input_prompt_str_id,
        cntx->min_pwd_len,
        cntx->max_pwd_len);

    cui_pwd_basic_set_action_str(cntx->first_pwd_cui, 0, cntx->cancel_str_id);
    cui_pwd_basic_set_proc(cntx->first_pwd_cui, cui_pwd_check_first_pwd_proc, cntx);

    cui_pwd_basic_run(cntx->first_pwd_cui);
}


const WCHAR* cui_pwd_check_get_input_of_active(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_check_get_cntx(instance_id);

    if (cntx->second_pwd_cui != 0)
    {
        return cui_pwd_basic_get_input(cntx->second_pwd_cui);
    }
    else if (cntx->first_pwd_cui != 0)
    {
        return cui_pwd_basic_get_input(cntx->first_pwd_cui);
    }

    return NULL;
}


void cui_pwd_check_clear_input_of_active(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_check_get_cntx(instance_id);

    if (cntx->second_pwd_cui != 0)
    {
        cui_pwd_basic_clear_input(cntx->second_pwd_cui);
    }
    else if (cntx->first_pwd_cui != 0)
    {
        cui_pwd_basic_clear_input(cntx->first_pwd_cui);
    }
}


void cui_pwd_check_reset(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_check_get_cntx(instance_id);

    if (cntx->first_pwd_cui != 0)
    {
        cui_pwd_basic_reset(cntx->first_pwd_cui);
    }
    if (cntx->second_pwd_cui != 0)
    {
        cui_pwd_basic_close(cntx->second_pwd_cui);
        cntx->second_pwd_cui = 0;
    }
}


void cui_pwd_check_close(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_check_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_check_cntx_struct*)mmi_frm_group_get_user_data(instance_id);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_CHECK_CLOSE, instance_id, (U32)cntx);

    if (cntx == NULL ||
        cntx->valid_magic != CUI_PWD_CHECK_VALID_MAGIC)
    {
        return;
    }

    if (cntx->first_pwd_cui != 0)
    {
        cui_pwd_basic_close(cntx->first_pwd_cui);
        cntx->first_pwd_cui = 0;
    }
    if (cntx->second_pwd_cui != 0)
    {
        cui_pwd_basic_close(cntx->second_pwd_cui);
        cntx->second_pwd_cui = 0;
    }
    mmi_frm_group_close(cntx->this_grp_id);
}

