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
 *  PwdCuiBasic.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CUI of single password screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "PwdCuiGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "wgui_inputs.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "mmi_rp_cui_password_def.h"
#include "PwdCui.h"
#include "MMI_trc_Int.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

#define CUI_PWD_BASIC_VALID_MAGIC 0x10BA51C0

typedef struct
{
    U32 valid_magic;
    mmi_id parent_grp_id;
    mmi_id this_grp_id;
    MMI_BOOL is_small_screen_enabled;
    MMI_BOOL is_active_closing;
    MMI_BOOL is_cancel_enabled;
    S8 min_pwd_len;
    S8 max_pwd_len;
    MMI_STR_ID done_str_id;
    MMI_STR_ID cancel_str_id;
    MMI_STR_ID aux_str_id;
    mmi_proc_func proc;
    void *user_data;
    const WCHAR *input_prompt_str;
    WCHAR extra_msg_str[CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 1];
    WCHAR input_buffer[1];
} cui_pwd_basic_cntx_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_get_cntx
 * DESCRIPTION
 *  Get context from group ID
 *  Assert for the valid context
 * PARAMETERS
 *  instance_id     [IN] Group ID
 * RETURNS
 *  Context
 *****************************************************************************/
static cui_pwd_basic_cntx_struct *cui_pwd_basic_get_cntx(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_basic_cntx_struct*)mmi_frm_group_get_user_data(instance_id);
    
    MMI_ASSERT(cntx != NULL);
    MMI_ASSERT(cntx->valid_magic == CUI_PWD_BASIC_VALID_MAGIC);

    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_send_to_parent
 * DESCRIPTION
 *  Send event to parent. The sender_id of event will be filled with
 *  cntx->this_grp_id.
 *  If cntx->proc is given, the event will be sent to the proc.
 * PARAMETERS
 *  cntx        [IN] Context
 *  evt         [IN] Group event
 * RETURNS
 *  Return value from parent
 *****************************************************************************/
static mmi_ret cui_pwd_basic_send_to_parent(
                cui_pwd_basic_cntx_struct *cntx,
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


static mmi_ret cui_pwd_basic_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_basic_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_GROUP_DEINIT, cntx->this_grp_id, cntx);
        
            memset(cntx->input_buffer, 0, sizeof(WCHAR) * cntx->max_pwd_len);
            cntx->valid_magic = 0;
            mmi_mfree((void*)cntx->input_prompt_str);
            mmi_mfree(cntx);
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret cui_pwd_basic_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_basic_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            mmi_frm_key_evt_struct *input_key_evt;

            input_key_evt = (mmi_frm_key_evt_struct*)evt;

            /*
             * We can not receive POUND key down on ON_KEY event,
             * so we should process here.
             */
            if (input_key_evt->key_code == KEY_POUND &&
                input_key_evt->key_type == KEY_EVENT_DOWN &&
                mmi_wcslen(cntx->input_buffer) >= cntx->min_pwd_len)
            {
                cui_pwd_basic_done_evt_struct done_evt;
                
                MMI_FRM_INIT_EVENT(&done_evt, EVT_ID_CUI_PWD_BASIC_DONE);
                done_evt.input = cntx->input_buffer;
                cui_pwd_basic_send_to_parent(cntx, &done_evt);
            }
        
            break;
        }
    
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct *input_key_evt;
            cui_pwd_basic_key_evt_struct my_key_evt;
            mmi_ret ret;

            input_key_evt = (mmi_frm_key_evt_struct*)evt;

            MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_ON_KEY,
                cntx->this_grp_id, input_key_evt->key_code, input_key_evt->key_type);
            
            MMI_FRM_INIT_EVENT(&my_key_evt, EVT_ID_CUI_PWD_BASIC_KEY);
            my_key_evt.key_evt_id = evt->evt_id;
            my_key_evt.key_code = (mmi_keypads_enum)input_key_evt->key_code;
            my_key_evt.key_type = (mmi_key_types_enum)input_key_evt->key_type;
            ret = cui_pwd_basic_send_to_parent(cntx, &my_key_evt);
            
            return ret;
        }
    
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            if (!cntx->is_active_closing)
            {
                cui_pwd_basic_passive_closing_evt_struct closing_evt;
                mmi_ret ret;

                MMI_FRM_INIT_EVENT(&closing_evt, EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING);
                ret = cui_pwd_basic_send_to_parent(cntx, &closing_evt);
                
                MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_PASSIVE_CLOSING,
                    evt->evt_id, cntx->this_grp_id, ret);
                
                return ret;
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


static void cui_pwd_basic_on_user_confirmed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    cui_pwd_basic_done_evt_struct done_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_basic_cntx_struct*)mmi_frm_scrn_get_user_data(
                mmi_frm_group_get_active_id(),
                mmi_frm_scrn_get_active_id());

    if (cntx->this_grp_id != mmi_frm_group_get_active_id())
    {
        return;
    }

    MMI_FRM_INIT_EVENT(&done_evt, EVT_ID_CUI_PWD_BASIC_DONE);
    done_evt.input = cntx->input_buffer;
    cui_pwd_basic_send_to_parent(cntx, &done_evt);
}


static void cui_pwd_basic_on_rsk_pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_basic_cntx_struct*)mmi_frm_scrn_get_user_data(
                mmi_frm_group_get_active_id(),
                mmi_frm_scrn_get_active_id());

    if (cntx->this_grp_id != mmi_frm_group_get_active_id())
    {
        return;
    }

    if (cntx->aux_str_id != 0)
    {
        cui_pwd_basic_aux_evt_struct aux_evt;

        MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_RSK_PRESSED, cntx->this_grp_id, 1);
    
        MMI_FRM_INIT_EVENT(&aux_evt, EVT_ID_CUI_PWD_BASIC_AUX);
        aux_evt.type = CUI_PWD_AUXILIARY_BASIC_DEFAULT;
        cui_pwd_basic_send_to_parent(cntx, &aux_evt);
    }
    else if (cntx->is_cancel_enabled)
    {
        cui_pwd_basic_cancel_evt_struct cancel_evt;

        MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_RSK_PRESSED, cntx->this_grp_id, 2);
        
        MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_CUI_PWD_BASIC_CANCEL);
        cui_pwd_basic_send_to_parent(cntx, &cancel_evt);
    }
}


static void cui_pwd_basic_input_box_callback(
                U8 *text,
                U8 *cursor,
                S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_basic_cntx_struct*)mmi_frm_scrn_get_user_data(
                mmi_frm_group_get_active_id(),
                mmi_frm_scrn_get_active_id());

    if (cntx->this_grp_id != mmi_frm_group_get_active_id())
    {
        return;
    }

    if (mmi_wcslen(cntx->input_buffer) >= cntx->min_pwd_len)
    {
        ChangeLeftSoftkey(cntx->done_str_id, 0);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetLeftSoftkeyFunction(cui_pwd_basic_on_user_confirmed, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(cui_pwd_basic_on_user_confirmed, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
    }
}


static void cui_pwd_basic_entry(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    mmi_frm_scrn_type_enum scrn_type;
    MMI_BOOL enable_done;
    U8 *gui_buffer;
    MMI_STR_ID rsk_str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_basic_cntx_struct*)es_data->user_data;

    scrn_type = (cntx->is_small_screen_enabled ? MMI_FRM_SMALL_SCRN : MMI_FRM_FULL_SCRN);

    if (!mmi_frm_scrn_enter(
            es_data->group_id,
            es_data->scrn_id,
            NULL,
            (FuncPtr)cui_pwd_basic_entry,
            scrn_type))
    {
        MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_ENTRY,
            cntx->this_grp_id, es_data->scrn_id, cntx->is_small_screen_enabled, 0);
        return;
    }

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_ENTRY,
        cntx->this_grp_id, es_data->scrn_id, cntx->is_small_screen_enabled, 1);

    /* If the length of input >= required length, enable the Done softkey */
    enable_done = MMI_TRUE;
    if (mmi_wcslen(cntx->input_buffer) >= cntx->min_pwd_len)
    {
        enable_done = MMI_TRUE;
    }
    else
    {
        enable_done = MMI_FALSE;
    }

    RegisterInputBoxValidationFunction(cui_pwd_basic_input_box_callback);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    if (cntx->input_buffer[0] == L'\0') /* Input has been reset */
    {
        gui_buffer = NULL;
    }

    if (enable_done)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

    if (cntx->is_small_screen_enabled)
    {
        enable_resized_small_screen();
    }

    rsk_str_id = 0;
    if (cntx->aux_str_id != 0)
    {
        rsk_str_id = cntx->aux_str_id;
    }
    else if (cntx->is_cancel_enabled && cntx->cancel_str_id != 0)
    {
        rsk_str_id = cntx->cancel_str_id;
    }

    ShowCategory111Screen_ext(
        (U16)(enable_done ? cntx->done_str_id : 0),
        0,
        rsk_str_id,
        0,
        (U8*)cntx->input_prompt_str,
        IMM_INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*)cntx->input_buffer,
        (cntx->max_pwd_len + 1), /* Buffer length in WCHAR */
        (U8*)cntx->extra_msg_str,
        0,
        gui_buffer);

    if (enable_done)
    {
        SetLeftSoftkeyFunction(cui_pwd_basic_on_user_confirmed, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(cui_pwd_basic_on_user_confirmed, KEY_EVENT_UP);
    }

    if (rsk_str_id != 0)
    {
        SetCategory111RightSoftkeyFunction(cui_pwd_basic_on_rsk_pressed, KEY_EVENT_UP);
    }
    
    mmi_frm_scrn_set_key_proc(es_data->group_id, es_data->scrn_id, cui_pwd_basic_scrn_proc);
}


mmi_id cui_pwd_basic_create(
        mmi_id parent_grp_id,
        MMI_STR_ID prompt_str_id,
        S32 min_pwd_len,
        S32 max_pwd_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cui_pwd_basic_create_dynamic_str(
                parent_grp_id,
                get_string(prompt_str_id),
                min_pwd_len,
                max_pwd_len);
}


mmi_id cui_pwd_basic_create_dynamic_str(
        mmi_id parent_grp_id,
        const WCHAR* prompt_str,
        S32 min_pwd_len,
        S32 max_pwd_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    S32 prompt_str_len;
    WCHAR *input_prompt_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(0 < min_pwd_len && min_pwd_len <= max_pwd_len);
    
    cntx = (cui_pwd_basic_cntx_struct*)mmi_malloc(
        sizeof(cui_pwd_basic_cntx_struct) + sizeof(WCHAR) * max_pwd_len);

    cntx->valid_magic = CUI_PWD_BASIC_VALID_MAGIC;
    cntx->parent_grp_id = parent_grp_id;
    cntx->is_small_screen_enabled = MMI_FALSE;
    cntx->is_active_closing = MMI_FALSE;
    cntx->done_str_id = STR_GLOBAL_OK;
    cntx->cancel_str_id = STR_GLOBAL_BACK;
    cntx->aux_str_id = 0;
    cntx->proc = NULL;
    cntx->user_data = NULL;
    cntx->is_cancel_enabled = MMI_TRUE;
    cntx->min_pwd_len = (S8)min_pwd_len;
    cntx->max_pwd_len = (S8)max_pwd_len;

    prompt_str_len = mmi_wcslen(prompt_str);
    input_prompt_buffer = mmi_malloc((prompt_str_len + 1) * sizeof(WCHAR));
    mmi_wcscpy(input_prompt_buffer, prompt_str);
    cntx->input_prompt_str = input_prompt_buffer;
    
    cntx->extra_msg_str[0] = L'\0';
    cntx->input_buffer[0] = L'\0';

    cntx->this_grp_id = mmi_frm_group_create(
        cntx->parent_grp_id,
        GRP_ID_AUTO_GEN,
        cui_pwd_basic_grp_proc,
        cntx);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_CREATE, parent_grp_id, cntx->this_grp_id, (U32)cntx);

    return cntx->this_grp_id;
}


void cui_pwd_basic_set_action_str(mmi_id instance_id, MMI_STR_ID done_str_id, MMI_STR_ID cancel_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    if (done_str_id != 0)
    {
        cntx->done_str_id = done_str_id;
    }
    if (cancel_str_id != 0)
    {
        cntx->cancel_str_id = cancel_str_id;
    }
}


void cui_pwd_basic_set_proc(mmi_id instance_id, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    cntx->proc = proc;
    cntx->user_data = user_data;
}


void cui_pwd_basic_set_small_screen_enabled(mmi_id instance_id, MMI_BOOL enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    cntx->is_small_screen_enabled = enabled;
}


void cui_pwd_basic_set_input_prompt(mmi_id instance_id, const WCHAR *prompt_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    S32 prompt_str_len;
    WCHAR *input_prompt_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    if (cntx->input_prompt_str != NULL)
    {
        mmi_mfree((void*)cntx->input_prompt_str);
    }

    prompt_str_len = mmi_wcslen(prompt_str);
    input_prompt_buffer = mmi_malloc((prompt_str_len + 1) * sizeof(WCHAR));
    mmi_wcscpy(input_prompt_buffer, prompt_str);
    cntx->input_prompt_str = input_prompt_buffer;
}


void cui_pwd_basic_set_extra_msg(mmi_id instance_id, const WCHAR *extra_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    if (extra_msg == NULL)
    {
        cntx->extra_msg_str[0] = L'\0';
    }
    else
    {
        mmi_wcsncpy(cntx->extra_msg_str, extra_msg, CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
    }
}


void cui_pwd_basic_set_cancel_enabled(mmi_id instance_id, MMI_BOOL enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    cntx->is_cancel_enabled = enabled;
}


void cui_pwd_basic_set_auxiliary(
    mmi_id instance_id,
    cui_pwd_auxiliary_type_enum type,
    MMI_BOOL enabled,
    MMI_STR_ID str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    if (enabled && str_id != 0)
    {
        cntx->aux_str_id = str_id;
    }
    else
    {
        cntx->aux_str_id = 0;
    }
}


void cui_pwd_basic_run(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_RUN, instance_id,
        cntx->proc, cntx->is_small_screen_enabled, cntx->is_cancel_enabled);

    mmi_frm_group_enter(cntx->this_grp_id, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_scrn_first_enter(
        cntx->this_grp_id,
        SCR_ID_CUI_PWD_BASIC,
        (FuncPtr)cui_pwd_basic_entry,
        cntx);

    mmi_frm_scrn_set_leave_proc(
        cntx->this_grp_id,
        SCR_ID_CUI_PWD_BASIC,
        cui_pwd_basic_scrn_proc);
}


void cui_pwd_basic_set_input(mmi_id instance_id, const WCHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_SET_INPUT, instance_id, (U32)str);

    if (str == NULL)
    {
        cntx->input_buffer[0] = L'\0';
    }
    else
    {
        mmi_wcsncpy(cntx->input_buffer, str, cntx->max_pwd_len);
    }
}


void cui_pwd_basic_clear_input(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_set_input(instance_id, L"");
}


const WCHAR* cui_pwd_basic_get_input(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_pwd_basic_get_cntx(instance_id);

    return cntx->input_buffer;
}


void cui_pwd_basic_reset(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_clear_input(instance_id);
}


void cui_pwd_basic_close(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_pwd_basic_cntx_struct*)mmi_frm_group_get_user_data(instance_id);

    MMI_TRACE(CUI_PWD_TRC_GROUP, TRC_CUI_PWD_BASIC_CLOSE, instance_id, (U32)cntx);

    if (cntx == NULL ||
        cntx->valid_magic != CUI_PWD_BASIC_VALID_MAGIC)
    {
        return;
    }

    cntx->is_active_closing = MMI_TRUE;
    mmi_frm_group_close(instance_id);
}

