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
 *  PwdCuiGuard.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CUI of password, it combines a guard password & a checked password input
 *  scenario.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "PwdCui.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "PwdCuiGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "app_buff_alloc.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "mmi_rp_cui_password_def.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

#define CUI_PWD_GUARD_VALID_MAGIC 0x11223344

typedef struct
{
    U32 valid_magic;
    mmi_id parent_grp_id;
    mmi_id this_grp_id;
    mmi_id guard_pwd_cui;
    mmi_id input_pwd_cui;
    mmi_id confirm_pwd_cui;
    MMI_STR_ID confirm_prompt_str_id;
    MMI_STR_ID diff_input_str_id;
    MMI_STR_ID done_str_id;
    MMI_STR_ID cancel_str_id;
    MMI_STR_ID aux_str_id;
    MMI_BOOL is_cancel_enabled;
    S8 guard_min_pwd_len;
    S8 guard_max_pwd_len;
    S8 input_min_pwd_len;
    S8 input_max_pwd_len;
    WCHAR guard_extra_msg_str[CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 1];
    const WCHAR *guard_prompt_str;
    const WCHAR *input_prompt_str;
    const WCHAR *confirm_prompt_str;
    mmi_proc_func proc;
    void *user_data;
} cui_pwd_guard_cntx_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/


static mmi_ret cui_pwd_guard_input_proc(mmi_event_struct *evt);
static mmi_ret cui_pwd_guard_confirm_proc(mmi_event_struct *evt);
static mmi_ret cui_pwd_guard_handle_basic_key(
                    cui_pwd_guard_cntx_struct *cntx,
                    mmi_event_struct *evt);


static cui_pwd_guard_cntx_struct *cui_pwd_guard_get_cntx(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_guard_cntx_struct*)mmi_frm_group_get_user_data(instance_id);
    
    MMI_ASSERT(cntx != NULL);
    MMI_ASSERT(cntx->valid_magic == CUI_PWD_GUARD_VALID_MAGIC);

    return cntx;
}


static mmi_ret cui_pwd_guard_send_to_parent(
                cui_pwd_guard_cntx_struct *cntx,
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


static mmi_ret cui_pwd_guard_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {
        /* Free the context */
        cntx = (cui_pwd_guard_cntx_struct*)evt->user_data;

        MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_GUARD_GROUP_DEINIT, cntx->this_grp_id, (U32)cntx);
        
        cntx->valid_magic = 0;
		mmi_mfree((void*)cntx->guard_prompt_str);
        mmi_mfree(cntx);
    }

    return MMI_RET_OK;
}


static mmi_ret cui_pwd_guard_proc_for_guard_pwd(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_guard_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
            cntx->input_pwd_cui = cui_pwd_basic_create_dynamic_str(
                cntx->this_grp_id,
                cntx->input_prompt_str,
                cntx->input_min_pwd_len,
                cntx->input_max_pwd_len);
            cui_pwd_basic_set_action_str(cntx->input_pwd_cui, 0, STR_GLOBAL_BACK);
            cui_pwd_basic_set_proc(cntx->input_pwd_cui, cui_pwd_guard_input_proc, cntx);
            cui_pwd_basic_run(cntx->input_pwd_cui);
            break;

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
        {
            cui_pwd_guard_cancel_evt_struct cancel_evt;

            MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_GUARD_CANCEL, cntx->this_grp_id);
        
            MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_CUI_PWD_GUARD_CANCEL);
            return cui_pwd_guard_send_to_parent(cntx, &cancel_evt);
        }

        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
        {
            cui_pwd_guard_passive_closing_evt_struct closing_evt;
            mmi_ret ret;

            MMI_FRM_INIT_EVENT(&closing_evt, EVT_ID_CUI_PWD_GUARD_PASSIVE_CLOSING);
            ret = cui_pwd_guard_send_to_parent(cntx, &closing_evt);

            MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_GUARD_PASSIVE_CLOSING, cntx->this_grp_id, ret);
            
            return ret;
        }

        case EVT_ID_CUI_PWD_BASIC_KEY:
            return cui_pwd_guard_handle_basic_key(cntx, evt);
        
        case EVT_ID_CUI_PWD_BASIC_AUX:
        {
            cui_pwd_guard_aux_evt_struct aux_evt;
            cui_pwd_basic_aux_evt_struct *src_aux_evt;

            src_aux_evt = (cui_pwd_basic_aux_evt_struct*)evt;
            if (src_aux_evt->type == CUI_PWD_AUXILIARY_BASIC_DEFAULT)
            {
                MMI_FRM_INIT_EVENT(&aux_evt, EVT_ID_CUI_PWD_GUARD_AUX);
                aux_evt.type = CUI_PWD_AUXILIARY_GUARD_DEFAULT;
                return cui_pwd_guard_send_to_parent(cntx, &aux_evt);
            }
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret cui_pwd_guard_input_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_guard_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            cntx->confirm_pwd_cui = cui_pwd_basic_create_dynamic_str(
                cntx->this_grp_id,
                cntx->confirm_prompt_str,
                cntx->input_min_pwd_len,
                cntx->input_max_pwd_len);
            cui_pwd_basic_set_action_str(cntx->confirm_pwd_cui, cntx->done_str_id, STR_GLOBAL_BACK);
            cui_pwd_basic_set_proc(cntx->confirm_pwd_cui, cui_pwd_guard_confirm_proc, cntx);
            cui_pwd_basic_run(cntx->confirm_pwd_cui);
            break;
        }

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
            cui_pwd_basic_close(cntx->input_pwd_cui);
            cntx->input_pwd_cui = 0;
            break;

        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
            /* Allow to close */
            cntx->input_pwd_cui = 0;
            break;
    
        case EVT_ID_CUI_PWD_BASIC_KEY:
            return cui_pwd_guard_handle_basic_key(cntx, evt);

        default:
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret cui_pwd_guard_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_guard_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            const WCHAR *first_input;
            cui_pwd_basic_done_evt_struct *done_evt;

            done_evt = (cui_pwd_basic_done_evt_struct*)evt;
            first_input = cui_pwd_basic_get_input(cntx->input_pwd_cui);

            if (mmi_wcscmp(first_input, done_evt->input) == 0)
            {
                cui_pwd_guard_done_evt_struct my_done_evt;

                MMI_FRM_INIT_EVENT(&my_done_evt, EVT_ID_CUI_PWD_GUARD_DONE);
                my_done_evt.guard = cui_pwd_basic_get_input(cntx->guard_pwd_cui);
                my_done_evt.input = first_input;
                return cui_pwd_guard_send_to_parent(cntx, &my_done_evt);
            }
            else
            {
                mmi_popup_display_simple(
                    get_string(cntx->diff_input_str_id),
                    MMI_EVENT_FAILURE,
                    cntx->this_grp_id,
                    cntx);

                cui_pwd_basic_clear_input(cntx->input_pwd_cui);
                cui_pwd_basic_close(cntx->confirm_pwd_cui);
                cntx->confirm_pwd_cui = 0;
            }
            break;
        }

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
            cui_pwd_basic_close(cntx->confirm_pwd_cui);
            cntx->confirm_pwd_cui = 0;
            break;

        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
            /* Allow to close */
            cntx->confirm_pwd_cui = 0;
            break;

        case EVT_ID_CUI_PWD_BASIC_KEY:
            return cui_pwd_guard_handle_basic_key(cntx, evt);

        default:
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret cui_pwd_guard_handle_basic_key(
                    cui_pwd_guard_cntx_struct *cntx,
                    mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_key_evt_struct *src_key_evt;
    cui_pwd_guard_key_evt_struct key_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_CUI_PWD_BASIC_KEY);

    src_key_evt = (cui_pwd_basic_key_evt_struct*)evt;
    MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_CUI_PWD_GUARD_KEY);
    key_evt.key_evt_id = src_key_evt->key_evt_id;
    key_evt.key_code = src_key_evt->key_code;
    key_evt.key_type = src_key_evt->key_type;
    
    return cui_pwd_guard_send_to_parent(cntx, &key_evt);
}


static void cui_pwd_guard_set_prompt_strings_internal(
    cui_pwd_guard_cntx_struct *cntx,
    const WCHAR* guard_prompt_str,
    const WCHAR* input_prompt_str,
    const WCHAR* confirm_prompt_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 guard_prompt_str_len, input_prompt_str_len, confirm_prompt_str_len;
    WCHAR *guard_prompt_buffer, *input_prompt_buffer, *confirm_prompt_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->guard_prompt_str != NULL)
    {
        mmi_mfree((void*)cntx->guard_prompt_str);
    }

    /* Prepare space for dynamic string */
    guard_prompt_str_len = mmi_wcslen(guard_prompt_str);
    input_prompt_str_len = mmi_wcslen(input_prompt_str);
    confirm_prompt_str_len = mmi_wcslen(confirm_prompt_str);
    guard_prompt_buffer = mmi_malloc(
        (guard_prompt_str_len + input_prompt_str_len + confirm_prompt_str_len + 3) * sizeof(WCHAR));
    input_prompt_buffer = guard_prompt_buffer + guard_prompt_str_len + 1;
    confirm_prompt_buffer = input_prompt_buffer + input_prompt_str_len + 1;
    mmi_wcscpy(guard_prompt_buffer, guard_prompt_str);
    mmi_wcscpy(input_prompt_buffer, input_prompt_str);
    mmi_wcscpy(confirm_prompt_buffer, confirm_prompt_str);
    cntx->guard_prompt_str = guard_prompt_buffer;
    cntx->input_prompt_str = input_prompt_buffer;
    cntx->confirm_prompt_str = confirm_prompt_buffer;
}


mmi_id cui_pwd_guard_create(
        mmi_id parent_grp_id,
        MMI_STR_ID guard_prompt_str_id,
        MMI_STR_ID input_prompt_str_id,
        MMI_STR_ID confirm_prompt_str_id,
        S32 guard_min_pwd_len,
        S32 guard_max_pwd_len,
        S32 input_min_pwd_len,
        S32 input_max_pwd_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cui_pwd_guard_create_dynamic_str(
                parent_grp_id,
                get_string(guard_prompt_str_id),
                get_string(input_prompt_str_id),
                get_string(confirm_prompt_str_id),
                guard_min_pwd_len,
                guard_max_pwd_len,
                input_min_pwd_len,
                input_max_pwd_len);
}


mmi_id cui_pwd_guard_create_dynamic_str(
        mmi_id parent_grp_id,
        const WCHAR* guard_prompt_str,
        const WCHAR* input_prompt_str,
        const WCHAR* confirm_prompt_str,
        S32 guard_min_pwd_len,
        S32 guard_max_pwd_len,
        S32 input_min_pwd_len,
        S32 input_max_pwd_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(0 < guard_min_pwd_len && guard_min_pwd_len <= guard_max_pwd_len);
    MMI_ASSERT(0 < input_min_pwd_len && input_min_pwd_len <= input_max_pwd_len);

    cntx = (cui_pwd_guard_cntx_struct*)mmi_malloc(sizeof(cui_pwd_guard_cntx_struct));
    
    cntx->valid_magic = CUI_PWD_GUARD_VALID_MAGIC;
    cntx->guard_pwd_cui = 0;
    cntx->input_pwd_cui = 0;
    cntx->confirm_pwd_cui = 0;
    cntx->parent_grp_id = parent_grp_id;
    cntx->diff_input_str_id = STR_ID_CUI_PWD_DIFFERENT_INPUT;
    cntx->done_str_id = STR_GLOBAL_OK;
    cntx->cancel_str_id = STR_GLOBAL_BACK;
    cntx->aux_str_id = 0;
    cntx->guard_min_pwd_len = guard_min_pwd_len;
    cntx->guard_max_pwd_len = guard_max_pwd_len;
    cntx->input_min_pwd_len = input_min_pwd_len;
    cntx->input_max_pwd_len = input_max_pwd_len;
    cntx->is_cancel_enabled = MMI_TRUE;
    
    cntx->guard_prompt_str = NULL;
    cui_pwd_guard_set_prompt_strings_internal(
        cntx,
        guard_prompt_str,
        input_prompt_str,
        confirm_prompt_str);

    cntx->guard_extra_msg_str[0] = L'\0';
    cntx->proc = NULL;
    cntx->user_data = NULL;

    cntx->this_grp_id = mmi_frm_group_create(
        parent_grp_id,
        GRP_ID_AUTO_GEN,
        cui_pwd_guard_grp_proc,
        cntx);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_GUARD_CREATE,
        parent_grp_id, cntx->this_grp_id, (U32)cntx);

    return cntx->this_grp_id;
}


void cui_pwd_guard_set_action_str(mmi_id instance_id, MMI_STR_ID done_str_id, MMI_STR_ID cancel_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    if (done_str_id != 0)
    {
        cntx->done_str_id = done_str_id;
    }
    if (cancel_str_id != 0)
    {
        cntx->cancel_str_id = cancel_str_id;
    }
}


void cui_pwd_guard_set_cancel_enabled(mmi_id instance_id, MMI_BOOL enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    cntx->is_cancel_enabled = enabled;
}


void cui_pwd_guard_set_proc(mmi_id instance_id, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    cntx->proc = proc;
    cntx->user_data = user_data;
}


void cui_pwd_guard_set_diff_input_prompt(mmi_id instance_id, MMI_STR_ID prompt_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    cntx->diff_input_str_id = prompt_str_id;
}


void cui_pwd_guard_set_guard_extra_msg(mmi_id instance_id, const WCHAR *extra_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    if (extra_msg == NULL)
    {
        cntx->guard_extra_msg_str[0] = L'\0';
    }
    else
    {
        mmi_wcsncpy(cntx->guard_extra_msg_str, extra_msg, CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
    }

    if (cntx->guard_pwd_cui != 0)
    {
        cui_pwd_basic_set_extra_msg(cntx->guard_pwd_cui, extra_msg);
    }
}


void cui_pwd_guard_set_auxiliary(
    mmi_id instance_id,
    cui_pwd_auxiliary_type_enum type,
    MMI_BOOL enabled,
    MMI_STR_ID str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    if (enabled && str_id != 0)
    {
        cntx->aux_str_id = str_id;
    }
    else
    {
        cntx->aux_str_id = 0;
    }
}


void cui_pwd_guard_set_prompt_strings(
    mmi_id instance_id,
    const WCHAR* guard_prompt_str,
    const WCHAR* input_prompt_str,
    const WCHAR* confirm_prompt_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);
    
    cui_pwd_guard_set_prompt_strings_internal(
        cntx,
        guard_prompt_str,
        input_prompt_str,
        confirm_prompt_str);

    if (cntx->guard_pwd_cui != 0)
    {
        cui_pwd_basic_set_input_prompt(cntx->guard_pwd_cui, guard_prompt_str);
    }
    if (cntx->input_pwd_cui != 0)
    {
        cui_pwd_basic_set_input_prompt(cntx->input_pwd_cui, input_prompt_str);
    }
    if (cntx->confirm_pwd_cui != 0)
    {
        cui_pwd_basic_set_input_prompt(cntx->confirm_pwd_cui, confirm_prompt_str);
    }
}


void cui_pwd_guard_run(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_GUARD_RUN, instance_id,
        cntx->is_cancel_enabled, (U32)cntx->proc);

    mmi_frm_group_enter(cntx->this_grp_id, MMI_FRM_NODE_NONE_FLAG);

    cntx->guard_pwd_cui = cui_pwd_basic_create_dynamic_str(
        cntx->this_grp_id,
        cntx->guard_prompt_str,
        cntx->guard_min_pwd_len,
        cntx->guard_max_pwd_len);

    cui_pwd_basic_set_action_str(cntx->guard_pwd_cui, 0, cntx->cancel_str_id);
    cui_pwd_basic_set_cancel_enabled(cntx->guard_pwd_cui, cntx->is_cancel_enabled);
    cui_pwd_basic_set_extra_msg(cntx->guard_pwd_cui, cntx->guard_extra_msg_str);
    cui_pwd_basic_set_proc(cntx->guard_pwd_cui, cui_pwd_guard_proc_for_guard_pwd, cntx);

    if (cntx->aux_str_id != 0)
    {
        cui_pwd_basic_set_auxiliary(
            cntx->guard_pwd_cui,
            CUI_PWD_AUXILIARY_BASIC_DEFAULT,
            MMI_TRUE,
            cntx->aux_str_id);
    }

    cui_pwd_basic_run(cntx->guard_pwd_cui);
}


static mmi_id cui_pwd_guard_get_active_cui(cui_pwd_guard_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id active_cui;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_cui = 0;
    
    if (cntx->confirm_pwd_cui != 0)
    {
        active_cui = cntx->confirm_pwd_cui;
    }
    else if (cntx->input_pwd_cui != 0)
    {
        active_cui = cntx->input_pwd_cui;
    }
    else if (cntx->guard_pwd_cui != 0)
    {
        active_cui = cntx->guard_pwd_cui;
    }

    return active_cui;
}


const WCHAR* cui_pwd_guard_get_input_of_active(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    mmi_id active_cui;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    active_cui = cui_pwd_guard_get_active_cui(cntx);

    if (active_cui != 0)
    {
        return cui_pwd_basic_get_input(active_cui);
    }

    return NULL;
}


void cui_pwd_guard_clear_input_of_active(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    mmi_id active_cui;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    active_cui = cui_pwd_guard_get_active_cui(cntx);

    if (active_cui != 0)
    {
        cui_pwd_basic_clear_input(active_cui);
    }
}


void cui_pwd_guard_reset(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_GUARD_RESET, instance_id,
        cntx->input_pwd_cui, cntx->guard_pwd_cui);

    if (cntx->guard_pwd_cui != 0)
    {
        cui_pwd_basic_reset(cntx->guard_pwd_cui);
    }
    if (cntx->input_pwd_cui != 0)
    {
        cui_pwd_basic_close(cntx->input_pwd_cui);
        cntx->input_pwd_cui = 0;
    }
    if (cntx->confirm_pwd_cui != 0)
    {
        cui_pwd_basic_close(cntx->confirm_pwd_cui);
        cntx->confirm_pwd_cui = 0;
    }
}


MMI_BOOL cui_pwd_guard_is_on_guard_input_box(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL retValue = MMI_FALSE;
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_guard_get_cntx(instance_id);

    /* input_pwd_cui == 0 implies confirm_pwd_cui == 0 */
    if(cntx->guard_pwd_cui != 0 && cntx->input_pwd_cui == 0)
	{
		retValue = MMI_TRUE;
	}

	return retValue;
}


void cui_pwd_guard_close(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_guard_cntx_struct*)mmi_frm_group_get_user_data(instance_id);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_GUARD_CLOSE, instance_id, (U32)cntx);

    if (cntx == NULL ||
        cntx->valid_magic != CUI_PWD_GUARD_VALID_MAGIC)
    {
        return;
    }

    if (cntx->guard_pwd_cui != 0)
    {
        cui_pwd_basic_close(cntx->guard_pwd_cui);
        cntx->guard_pwd_cui = 0;
    }
    if (cntx->input_pwd_cui != 0)
    {
        cui_pwd_basic_close(cntx->input_pwd_cui);
        cntx->input_pwd_cui = 0;
    }
    if (cntx->confirm_pwd_cui != 0)
    {
        cui_pwd_basic_close(cntx->confirm_pwd_cui);
        cntx->confirm_pwd_cui = 0;
    }

    /*
     * cntx->guard_prompt_str stores the begin address of all dynamic strings
     * See the implementation in cui_pwd_guard_create_dynamic_str()
     */
     
    mmi_frm_group_close(cntx->this_grp_id);
}

