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
 *  SecSetCuiVerify.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Password verification CUI
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

#include "MMI_features.h"
#include "SecSetProt.h"
#include "SecSetSrvGprot.h"
#include "SecSetCuiGprot.h"
#include "PwdCuiGprot.h"
#include "SimCtrlSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "AlertScreen.h"
#include "mmi_rp_app_security_setting_def.h"
#include "wgui_categories_util.h"
#include "string.h"
#include "CommonScreensResDef.h"


/****************************************************************************
 * Configurations
 ****************************************************************************/

#define CUI_VERIFY_TRC_GROUP MMI_COMMON_TRC_G7_SETTING

#define CUI_VERIFY_MAX_INSTANCES_NUM 4


/****************************************************************************
 * Structures
 ****************************************************************************/

struct cui_verify_cntx_struct_s;

typedef void (*cui_verify_post_callback)(struct cui_verify_cntx_struct_s *cntx);

typedef struct
{
    cui_verify_type_enum type;
    MMI_BOOL is_sim_related;
    S32 min_pwd_len;
    S32 max_pwd_len;
    MMI_BOOL (*pre_check)(struct cui_verify_cntx_struct_s *cntx);
    WCHAR* (*get_input_prompt_str)(struct cui_verify_cntx_struct_s *cntx, WCHAR *out_buffer, S32 max_str_len);
    WCHAR* (*get_extra_msg)(struct cui_verify_cntx_struct_s *cntx, WCHAR *out_msg, S32 max_str_len);
    MMI_BOOL (*verify)(struct cui_verify_cntx_struct_s *cntx, const WCHAR *input, cui_verify_post_callback post_cb);
} cui_verify_type_config_struct;


#define CUI_VERIFY_VALID_MAGIC 0x09998877

typedef struct cui_verify_cntx_struct_s
{
    U32 valid_magic; /* CUI_VERIFY_VALID_MAGIC */
    const cui_verify_type_config_struct *type_config;
    mmi_id parent_grp_id;
    mmi_id this_grp_id;
    mmi_sim_enum sim;
    mmi_id input_cui;    /* cui_pwd_basic */
    mmi_secset_ubchv_handle ubchv_handle;
    cui_verify_post_callback verify_post_cb;
    mmi_proc_func proc;
    void *user_data;

    struct cui_verify_cntx_struct_s *next;
} cui_verify_cntx_struct;


/****************************************************************************
 * Configurations
 ****************************************************************************/

static MMI_BOOL cui_verify_no_pre_check(cui_verify_cntx_struct *cntx);
static WCHAR* cui_verify_phone_get_prompt_str(cui_verify_cntx_struct *cntx, WCHAR *out_buffer, S32 max_str_len);
static WCHAR* cui_verify_get_empty_extra_msg(cui_verify_cntx_struct *cntx, WCHAR *out_msg, S32 max_str_len);
static MMI_BOOL cui_verify_phone_verify(
    cui_verify_cntx_struct *cntx,
    const WCHAR *input,
    cui_verify_post_callback post_cb);

static MMI_BOOL cui_verify_sim_pre_check(cui_verify_cntx_struct *cntx);
static WCHAR* cui_verify_sim_get_prompt_str(cui_verify_cntx_struct *cntx, WCHAR *out_buffer, S32 max_str_len);
static WCHAR* cui_verify_sim_get_extra_msg(cui_verify_cntx_struct *cntx, WCHAR *out_msg, S32 max_str_len);
static MMI_BOOL cui_verify_sim_verify(
    cui_verify_cntx_struct *cntx,
    const WCHAR *input,
    cui_verify_post_callback post_cb);


static const cui_verify_type_config_struct cui_verify_type_config[] =
{
    {
        CUI_VERIFY_TYPE_PHONE_PASSWORD,
        MMI_FALSE,
        MMI_SECSET_MIN_PHONE_PASSWORD_LEN,
        MMI_SECSET_MAX_PHONE_PASSWORD_LEN,
        cui_verify_no_pre_check,
        cui_verify_phone_get_prompt_str,
        cui_verify_get_empty_extra_msg,
        cui_verify_phone_verify
    },
#if !defined(__MMI_SECSET_SLIM__)
    {
        CUI_VERIFY_TYPE_CHV1,
        MMI_TRUE,
        MMI_SECSET_MIN_CHV_LEN,
        MMI_SECSET_MAX_CHV_LEN,
        cui_verify_sim_pre_check,
        cui_verify_sim_get_prompt_str,
        cui_verify_sim_get_extra_msg,
        cui_verify_sim_verify
    },
#endif
    {
        CUI_VERIFY_TYPE_CHV2,
        MMI_TRUE,
        MMI_SECSET_MIN_CHV_LEN,
        MMI_SECSET_MAX_CHV_LEN,
        cui_verify_sim_pre_check,
        cui_verify_sim_get_prompt_str,
        cui_verify_sim_get_extra_msg,
        cui_verify_sim_verify
    }
};

static const S32 cui_verify_max_type_config_num =
    sizeof(cui_verify_type_config) / sizeof(cui_verify_type_config[0]);


/****************************************************************************
 * Global variables
 ****************************************************************************/

typedef struct
{
    S32 n_instances;
    cui_verify_cntx_struct *list;
} cui_verify_cntx_global;

static cui_verify_cntx_global g_cui_verify_cntx_global =
{
    0,
    NULL
};


/****************************************************************************
 * Functions
 ****************************************************************************/

static void cui_verify_post_verification(cui_verify_cntx_struct *cntx);

static const cui_verify_type_config_struct* cui_verify_get_type_config(
    cui_verify_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cui_verify_max_type_config_num; i++)
    {
        if (cui_verify_type_config[i].type == type)
        {
            return &(cui_verify_type_config[i]);
        }
    }

    MMI_ASSERT(0);

    return NULL;
}


static cui_verify_cntx_struct* cui_verify_get_cntx(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_verify_cntx_struct*)mmi_frm_group_get_user_data(instance_id);
    MMI_ASSERT(cntx != NULL);
    MMI_ASSERT(cntx->valid_magic == CUI_VERIFY_VALID_MAGIC);

    return cntx;
}


static MMI_BOOL cui_verify_is_valid_cntx(cui_verify_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *curr_in_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->valid_magic != CUI_VERIFY_VALID_MAGIC)
    {
        return MMI_FALSE;
    }

    if (!mmi_frm_group_is_present(cntx->this_grp_id))
    {
        return MMI_FALSE;
    }
    
    for (curr_in_list = g_cui_verify_cntx_global.list;
         curr_in_list != NULL;
         curr_in_list = curr_in_list->next)
    {
        if (cntx == curr_in_list)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


static mmi_ret cui_verify_send_to_parent(cui_verify_cntx_struct *cntx, void *evt)
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


static void cui_verify_post_to_parent(cui_verify_cntx_struct *cntx, void *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *grp_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_evt = (mmi_group_event_struct*)evt;
    grp_evt->sender_id = cntx->this_grp_id;
    
    if (cntx->proc != NULL)
    {
        MMI_FRM_POST_EVENT(grp_evt, cntx->proc, cntx->user_data);
    }
    else
    {
        mmi_frm_group_post_to_parent(
            cntx->this_grp_id,
            grp_evt);
    }
}


static mmi_ret cui_verify_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;
    cui_verify_cntx_struct *pre_in_list, *curr_in_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_verify_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            /* Remove cntx from list */
            pre_in_list = NULL;
            curr_in_list = g_cui_verify_cntx_global.list;
            while (curr_in_list != NULL)
            {
                if (curr_in_list == cntx)
                {
                    break;
                }
                pre_in_list = curr_in_list;
                curr_in_list = curr_in_list->next;
            }
            MMI_ASSERT(curr_in_list != NULL);
            
            if (pre_in_list == NULL) /* First element */
            {
                g_cui_verify_cntx_global.list = curr_in_list->next;
            }
            else
            {
                pre_in_list->next = curr_in_list->next;
            }
            g_cui_verify_cntx_global.n_instances--;

            /* Empty list if and only if n_instances == 0 */
            MMI_ASSERT((g_cui_verify_cntx_global.list == NULL) == (g_cui_verify_cntx_global.n_instances == 0));
            
            MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_GROUP_DEINIT,
                cntx->this_grp_id, (U32)cntx, g_cui_verify_cntx_global.n_instances);
        
            cntx->valid_magic = 0;
            mmi_mfree(cntx);
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret cui_verify_input_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_verify_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            cui_pwd_basic_done_evt_struct *done_evt;

            MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_INPUT_DONE, cntx->this_grp_id, cntx->input_cui);

            done_evt = (cui_pwd_basic_done_evt_struct*)evt;
            cntx->verify_post_cb = cui_verify_post_verification;
            if (cntx->type_config->verify(cntx, done_evt->input, cui_verify_post_verification))
            {
                mmi_secset_show_waiting(cntx->this_grp_id);
            }
            else
            {
                cui_verify_result_evt_struct result_evt;
            
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_TEMP_FAIL),
                    MMI_EVENT_FAILURE,
                    cntx->parent_grp_id,
                    cntx);
                    
                MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
                result_evt.success = MMI_FALSE;
                result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_TEMP_FAIL;
                cui_verify_send_to_parent(cntx, &result_evt);
            }
            
            break;
        }

        case EVT_ID_CUI_PWD_BASIC_CANCEL:
        {
            cui_verify_cancel_evt_struct cancel_evt;

            MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_CANCEL, cntx->this_grp_id, cntx->input_cui);

            MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_CUI_VERIFY_CANCEL);
            cancel_evt.cause = CUI_VERIFY_CANCEL_CAUSE_USER_CANCEL;
            cui_verify_send_to_parent(cntx, &cancel_evt);
            break;
        }

        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
        {
            cui_verify_passive_closing_evt_struct closing_evt;
            mmi_ret ret;

            MMI_FRM_INIT_EVENT(&closing_evt, EVT_ID_CUI_VERIFY_PASSIVE_CLOSING);
            ret = cui_verify_send_to_parent(cntx, &closing_evt);

            MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_PASSIVE_CLOSING,
                cntx->this_grp_id, cntx->input_cui, ret);
                
            return ret;
        }
    }

    return MMI_RET_OK;
}


static void cui_verify_post_verification(cui_verify_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_secset_close_waiting(cntx->this_grp_id);
}


mmi_id cui_verify_create(mmi_id grp_id, cui_verify_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cui_verify_cntx_global.n_instances >= CUI_VERIFY_MAX_INSTANCES_NUM)
    {
        /* Too many instances was created and exceeds the maximum */
        return 0;
    }
    
    cntx = (cui_verify_cntx_struct*)mmi_malloc(sizeof(cui_verify_cntx_struct));
    cntx->valid_magic = CUI_VERIFY_VALID_MAGIC;
    cntx->parent_grp_id = grp_id;
#if (MMI_MAX_SIM_NUM >= 2)
    cntx->sim = MMI_SIM_NONE;
#else
    cntx->sim = MMI_SIM1;
#endif
    cntx->type_config = cui_verify_get_type_config(type);
    cntx->input_cui = 0;
    cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
    cntx->verify_post_cb = NULL;
    cntx->proc = NULL;
    cntx->user_data = NULL;

    cntx->this_grp_id = mmi_frm_group_create(
        grp_id,
        GRP_ID_AUTO_GEN,
        cui_verify_grp_proc,
        cntx);

    cntx->next = g_cui_verify_cntx_global.list;
    g_cui_verify_cntx_global.list = cntx;
    g_cui_verify_cntx_global.n_instances++;

    MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_CREATE,
        grp_id, type, cntx->this_grp_id, (U32)cntx, g_cui_verify_cntx_global.n_instances);

    return cntx->this_grp_id;
}


void cui_verify_set_proc(mmi_id instance_id, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_verify_get_cntx(instance_id);

    cntx->proc = proc;
    cntx->user_data = user_data;
}


void cui_verify_set_sim(mmi_id instance_id, mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_verify_get_cntx(instance_id);

    cntx->sim = sim;
}


void cui_verify_run(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;
    WCHAR *input_prompt;
    WCHAR *extra_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = cui_verify_get_cntx(instance_id);

    MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_RUN,
        instance_id, cntx->sim, (U32)cntx->proc);

    mmi_frm_group_enter(cntx->this_grp_id, MMI_FRM_NODE_NONE_FLAG);

    if (!cntx->type_config->pre_check(cntx))
    {
        /* The pre-check function will all following processes */
        MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_RUN_PRECHECK, 0);
        return;
    }

    input_prompt = (WCHAR*)mmi_malloc((MMI_SECSET_SIM_MAX_STR_LEN + 1) * sizeof(WCHAR));

    cntx->input_cui = cui_pwd_basic_create_dynamic_str(
        cntx->this_grp_id,
        cntx->type_config->get_input_prompt_str(cntx, input_prompt, MMI_SECSET_SIM_MAX_STR_LEN),
        cntx->type_config->min_pwd_len,
        cntx->type_config->max_pwd_len);
    cui_pwd_basic_set_proc(cntx->input_cui, cui_verify_input_proc, cntx);
#if defined(UI_SMALL_PIN_EDITOR_SCREEN) && !defined(__MMI_FTE_SUPPORT__)
    cui_pwd_basic_set_small_screen_enabled(cntx->input_cui, MMI_TRUE);
#endif
    
    extra_msg = (WCHAR*)mmi_malloc((CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 30) * sizeof(WCHAR));
    cntx->type_config->get_extra_msg(cntx, extra_msg, CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
    cui_pwd_basic_set_extra_msg(cntx->input_cui, extra_msg);
    mmi_mfree(extra_msg);

    cui_pwd_basic_run(cntx->input_cui);

    mmi_mfree(input_prompt);
}


void cui_verify_close(mmi_id instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_verify_cntx_struct*)mmi_frm_group_get_user_data(instance_id);

    if (cntx == NULL ||
        cntx->valid_magic != CUI_VERIFY_VALID_MAGIC)
    {
        MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_CLOSE, instance_id, 0, 0, 0);
        return;
    }

    MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_CLOSE,
        instance_id, cntx, cntx->input_cui, (U32)cntx->ubchv_handle);

    if (cntx->input_cui != 0)
    {
        cui_pwd_basic_close(cntx->input_cui);
        cntx->input_cui = 0;
    }
    if (cntx->ubchv_handle != MMI_SECSET_UBCHV_INVALID_HANDLE)
    {
        mmi_secset_ubchv_close(cntx->ubchv_handle);
        cntx->ubchv_handle = MMI_SECSET_UBCHV_INVALID_HANDLE;
    }

    mmi_frm_group_close(instance_id);
}



/****************************************************************************
 * Type configurations
 ****************************************************************************/

#define CUI_VERIFY_TYPE_CONFIGURATIONS

static mmi_ret cui_verify_phone_verify_result_proc(mmi_event_struct *evt);
static mmi_ret cui_verify_sim_verify_result_proc(mmi_event_struct *evt);
static mmi_ret cui_verify_sim_enter_ubchv_after_popup(mmi_event_struct *evt);
static void cui_verify_sim_popup_chv_blocked(cui_verify_cntx_struct *cntx);
static void cui_verify_sim_show_ubchv(cui_verify_cntx_struct *cntx);
static mmi_ret cui_verify_sim_ubchv_proc(mmi_event_struct *evt);


static WCHAR* cui_verify_get_empty_extra_msg(cui_verify_cntx_struct *cntx, WCHAR *out_msg, S32 max_str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_msg[0] = L'\0';

    return out_msg;
}


static MMI_BOOL cui_verify_no_pre_check(cui_verify_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


static WCHAR* cui_verify_phone_get_prompt_str(
    cui_verify_cntx_struct *cntx,
    WCHAR *out_buffer,
    S32 max_str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SECSET_APP_WITH_BWUI__
    mmi_wcsncpy(out_buffer, get_string(STR_ID_SECSET_INPUT_PHONE_PASSWORD_BWUI), max_str_len);
#else
    mmi_wcsncpy(out_buffer, get_string(STR_ID_SECSET_INPUT_PHONE_PASSWORD), max_str_len);
#endif
    return out_buffer;
}


static MMI_BOOL cui_verify_phone_verify(
    cui_verify_cntx_struct *cntx,
    const WCHAR *input,
    cui_verify_post_callback post_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_secset_verify_phone_password(
            input,
            cui_verify_phone_verify_result_proc,
            cntx) > 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


static mmi_ret cui_verify_phone_verify_result_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;
    srv_secset_verify_phone_password_result_evt_struct *verify_result_evt;
    cui_verify_result_evt_struct result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_SECSET_VERIFY_PHONE_PASSWORD_RESULT)
    {
        cntx = (cui_verify_cntx_struct*)evt->user_data;
        verify_result_evt = (srv_secset_verify_phone_password_result_evt_struct*)evt;

        if (!cui_verify_is_valid_cntx(cntx))
        {
            MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_INVALID_CNTX, (U32)cntx);
            return MMI_RET_OK;
        }

        cntx->verify_post_cb(cntx);

        if (verify_result_evt->success)
        {
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
            result_evt.success = MMI_TRUE;
            result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_NONE;
            cui_verify_send_to_parent(cntx, &result_evt);
        }
        else
        {
            mmi_popup_display_simple(
                get_string(STR_ID_SECSET_WRONG_PHONE_PASSWORD),
                MMI_EVENT_FAILURE,
                cntx->this_grp_id,
                cntx);

            cui_pwd_basic_clear_input(cntx->input_cui);
        }
    }

    return MMI_RET_OK;
}


#if defined(__MMI_SECSET_SLIM__)

#define cui_verify_sim_to_sim_pwd_type(type) SRV_SIM_CTRL_PWD_TYPE_CHV2

#else /* defined(__MMI_SECSET_SLIM__) */

static srv_sim_ctrl_pwd_type_enum cui_verify_sim_to_sim_pwd_type(cui_verify_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_pwd_type_enum pwd_type = SRV_SIM_CTRL_PWD_TYPE_CHV2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == CUI_VERIFY_TYPE_CHV1)
    {
        pwd_type = SRV_SIM_CTRL_PWD_TYPE_CHV1;
    }
    else if (type == CUI_VERIFY_TYPE_CHV2)
    {
        pwd_type = SRV_SIM_CTRL_PWD_TYPE_CHV2;
    }
    else
    {
        MMI_ASSERT(0);
    }

    return pwd_type;
}
#endif /* defined(__MMI_SECSET_SLIM__) */


void cui_verify_sim_close_same_instances(cui_verify_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *list_cntx, *next_cntx;
    cui_verify_cancel_evt_struct cancel_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (list_cntx = g_cui_verify_cntx_global.list; list_cntx != NULL; )
    {
        /* cntx may be released on the callback */
        next_cntx = list_cntx->next;
    
        if (list_cntx != cntx &&
            list_cntx->type_config->is_sim_related &&
            list_cntx->sim == cntx->sim &&
            list_cntx->type_config->type == cntx->type_config->type)
        {
            if (mmi_frm_group_is_present(list_cntx->parent_grp_id))
            {
                MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_CUI_VERIFY_CANCEL);
                cancel_evt.cause = CUI_VERIFY_CANCEL_CAUSE_ANOTHER_INST_RUN;
                cui_verify_post_to_parent(list_cntx, &cancel_evt);
            }
        }

        list_cntx = next_cntx;
    }

    mmi_secset_sim_close_screens_of_type(
        cntx->sim,
        cui_verify_sim_to_sim_pwd_type(cntx->type_config->type));
}


static MMI_BOOL cui_verify_sim_pre_check(cui_verify_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_pwd_type_enum pwd_type;
    cui_verify_result_evt_struct result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Please use cui_verify_set_sim() to specify SIM first */
    MMI_ASSERT(cntx->sim != MMI_SIM_NONE);

    cui_verify_sim_close_same_instances(cntx);

    pwd_type = cui_verify_sim_to_sim_pwd_type(cntx->type_config->type);
    if (!srv_sim_ctrl_is_available(cntx->sim))
    {
        cui_verify_cancel_evt_struct cancel_evt;
    
        MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_PRECHECK, cntx->this_grp_id, 1);

        mmi_popup_display_simple(
            get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            cntx->parent_grp_id,
            NULL);

        MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_CUI_VERIFY_CANCEL);
        cancel_evt.cause = CUI_VERIFY_CANCEL_CAUSE_UNAVAILABLE;
        cui_verify_post_to_parent(cntx, &cancel_evt);
    
        return MMI_FALSE;
    }
    else if (srv_sim_ctrl_pwd_is_blocked(cntx->sim, pwd_type))
    {
        if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV2 &&
            !srv_sim_ctrl_pwd_is_blocked(cntx->sim, SRV_SIM_CTRL_PWD_TYPE_UBCHV2))
        {
            MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_PRECHECK, cntx->this_grp_id, 2);
            
            cui_verify_sim_popup_chv_blocked(cntx);
        }
        else
        {
            MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_PRECHECK, cntx->this_grp_id, 3);

            mmi_secset_sim_display_popup(
                cntx->sim,
                pwd_type,
                MMI_SECSET_STR_CHV_BLOCKED,
                MMI_EVENT_FAILURE,
                cntx->parent_grp_id,
                NULL);
        
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_OPERATION_BLOCKED;
            cui_verify_post_to_parent(cntx, &result_evt);
        }

        return MMI_FALSE;
    }
    else if (!srv_sim_ctrl_pwd_is_enabled(cntx->sim, pwd_type))
    {
        MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_PRECHECK, cntx->this_grp_id, 4);
        
        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
        result_evt.success = MMI_TRUE;
        result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_DISABLED;
        cui_verify_post_to_parent(cntx, &result_evt);
        return MMI_FALSE;
    }

    MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_PRECHECK, cntx->this_grp_id, 5);

    return MMI_TRUE;
}


static WCHAR* cui_verify_sim_get_prompt_str(
    cui_verify_cntx_struct *cntx,
    WCHAR *out_buffer,
    S32 max_str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_secset_sim_get_string(
        cntx->sim,
        cui_verify_sim_to_sim_pwd_type(cntx->type_config->type),
        MMI_SECSET_STR_INPUT_CHV,
        out_buffer,
        max_str_len);

    return out_buffer;
}


static WCHAR* cui_verify_sim_get_extra_msg(cui_verify_cntx_struct *cntx, WCHAR *out_msg, S32 max_str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_remaining_attempts;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_remaining_attempts = srv_sim_ctrl_get_n_remaining_attempts(
        cntx->sim,
        cui_verify_sim_to_sim_pwd_type(cntx->type_config->type));

    mmi_secset_n_attempts_to_str(
        n_remaining_attempts,
        out_msg,
        max_str_len);

    return out_msg;
}


static MMI_BOOL cui_verify_sim_verify(
    cui_verify_cntx_struct *cntx,
    const WCHAR *input,
    cui_verify_post_callback post_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sim_ctrl_verify(
            cntx->sim,
            cui_verify_sim_to_sim_pwd_type(cntx->type_config->type),
            input,
            cui_verify_sim_verify_result_proc,
            cntx) > 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


static mmi_ret cui_verify_sim_verify_result_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;
    srv_sim_ctrl_verify_result_evt_struct *verify_result_evt;
    cui_verify_result_evt_struct result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id != EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT)
    {
        return MMI_RET_OK;
    }

    verify_result_evt = (srv_sim_ctrl_verify_result_evt_struct*)evt;
    cntx = (cui_verify_cntx_struct*)evt->user_data;

    if (!cui_verify_is_valid_cntx(cntx))
    {
        MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_INVALID_CNTX, (U32)cntx);
        /* Session has been cancelled during verifying */
        return MMI_RET_OK;
    }

    cntx->verify_post_cb(cntx);

    MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_RESULT,
        cntx->this_grp_id, verify_result_evt->success, verify_result_evt->fail_cause);

    if (verify_result_evt->success)
    {
        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
        result_evt.success = MMI_TRUE;
        result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_NONE;
        cui_verify_send_to_parent(cntx, &result_evt);
    }
    else
    {
        if (verify_result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
        {
            if (!srv_sim_ctrl_pwd_is_blocked(verify_result_evt->sim, verify_result_evt->type))
            {
                WCHAR *extra_msg;

                mmi_secset_sim_display_popup(
                    verify_result_evt->sim,
                    verify_result_evt->type,
                    MMI_SECSET_STR_WRONG_CHV,
                    MMI_EVENT_FAILURE,
                    cntx->this_grp_id,
                    cntx);
                    
                extra_msg = (WCHAR*)mmi_malloc((CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 1) * sizeof(WCHAR));
                cui_verify_sim_get_extra_msg(cntx, extra_msg, CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
                cui_pwd_basic_set_extra_msg(cntx->input_cui, extra_msg);
                mmi_mfree(extra_msg);
                    
                cui_pwd_basic_clear_input(cntx->input_cui);
            }
            else /* CHV blocked */
            {
                cui_verify_sim_popup_chv_blocked(cntx);

                cui_pwd_basic_close(cntx->input_cui);
                cntx->input_cui = 0;
            }
        }
        else
        {
            mmi_secset_sim_display_error_popup(
                verify_result_evt->sim,
                verify_result_evt->type,
                verify_result_evt->fail_cause,
                cntx->parent_grp_id,
                NULL);
        
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_NONE;
            switch (verify_result_evt->fail_cause)
            {
                case SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED:
                    result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_OPERATION_BLOCKED;
                    break;

                case SRV_SIM_CTRL_FAIL_CAUSE_TEMP_FAIL:
                    result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_TEMP_FAIL;
                    break;

                case SRV_SIM_CTRL_FAIL_CAUSE_SIM_ERROR:
                    result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_SIM_ERROR;
                    break;
            }
            
            cui_verify_send_to_parent(cntx, &result_evt);
        }
    }

    return MMI_RET_OK;
}


static void cui_verify_sim_popup_chv_blocked(cui_verify_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_result_evt_struct result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_POPUP_CHV_BLOCKED,
        cntx->this_grp_id, cntx->type_config->type);

#if !defined(__MMI_SECSET_SLIM__)
    if (cntx->type_config->type == CUI_VERIFY_TYPE_CHV1)
    {
        mmi_secset_hpveri_display_ubchv1(cntx->this_grp_id, cntx->sim);
    
        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
        result_evt.success = MMI_FALSE;
        result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_OPERATION_BLOCKED;
        cui_verify_post_to_parent(cntx, &result_evt);
    }
    else
#endif
    if (cntx->type_config->type == CUI_VERIFY_TYPE_CHV2)
    {
        WCHAR *message;

        /*
         * May be called from cui_verify_run(), which is called by app.
         * So we don't get the space from stack to avoid potential overflow.
         */
        message = (WCHAR*)mmi_malloc((MMI_SECSET_SIM_MAX_STR_LEN + 1) * sizeof(WCHAR));
    
        mmi_secset_sim_get_string(
            cntx->sim,
            SRV_SIM_CTRL_PWD_TYPE_CHV2,
            MMI_SECSET_STR_CHV_BLOCKED,
            message,
            MMI_SECSET_SIM_MAX_STR_LEN);

        if (srv_sim_ctrl_pwd_is_blocked(cntx->sim, SRV_SIM_CTRL_PWD_TYPE_UBCHV2))
        {
            mmi_popup_display_simple(
                message,
                MMI_EVENT_FAILURE,
                cntx->parent_grp_id,
                NULL);

            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_OPERATION_BLOCKED;
            cui_verify_post_to_parent(cntx, &result_evt);
        }
        else
        {
            mmi_popup_property_struct popup_arg;

            mmi_popup_property_init(&popup_arg);
            popup_arg.parent_id = cntx->this_grp_id;
            popup_arg.callback = cui_verify_sim_enter_ubchv_after_popup;
            popup_arg.user_tag = cntx;
        
            if (!mmi_popup_display(
                    message,
                    MMI_EVENT_FAILURE,
                    &popup_arg))
            {
                cui_verify_sim_show_ubchv(cntx);
            }
        }

        mmi_mfree(message);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


static mmi_ret cui_verify_sim_enter_ubchv_after_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;
    mmi_alert_result_evt_struct *quit_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_POPUP_QUIT)
    {
        quit_evt = (mmi_alert_result_evt_struct*)evt;
        cntx = (cui_verify_cntx_struct*)quit_evt->user_tag;

        /* POPUP_QUIT may come after GROUP_DEINIT */
        if (cui_verify_is_valid_cntx(cntx))
        {
            cui_verify_sim_show_ubchv(cntx);
        }
        else
        {
            MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_INVALID_CNTX, (U32)cntx);
        }
    }

    return MMI_RET_OK;
}


static void cui_verify_sim_show_ubchv(cui_verify_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx->type_config->type == CUI_VERIFY_TYPE_CHV2);

    MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_SHOW_UBCHV,
        cntx->this_grp_id, cntx->type_config->type);

    cntx->ubchv_handle = mmi_secset_ubchv_create(
        cntx->this_grp_id,
        cntx->sim,
        SRV_SIM_CTRL_PWD_TYPE_UBCHV2,
        cui_verify_sim_ubchv_proc,
        cntx);

    mmi_secset_ubchv_run(cntx->ubchv_handle);

    if (cntx->input_cui != 0)
    {
        cui_pwd_guard_close(cntx->input_cui);
        cntx->input_cui = 0;
    }
}


static mmi_ret cui_verify_sim_ubchv_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (cui_verify_cntx_struct*)evt->user_data;

    MMI_ASSERT(cui_verify_is_valid_cntx(cntx));

    switch (evt->evt_id)
    {
        case EVT_ID_SECSET_UBCHV_UNBLOCKED:
        {
            cui_verify_result_evt_struct result_evt;

            /*
             * UE choise:
             * We take unblocked CHV as successfully verified.
             */
            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
            result_evt.success = MMI_TRUE;
            result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_NONE;
            cui_verify_send_to_parent(cntx, &result_evt);
            break;
        }
        
        case EVT_ID_SECSET_UBCHV_CANCEL:
        {
            cui_verify_cancel_evt_struct cancel_evt;

            /*
             * UE choise:
             * If we take unblocked CHV as successfully verified, cancel
             * UBCHV input is a cancel operation. Otherwise we should
             * consider unblocked, blocked or cancel are the same concept
             * to the client: WRONG_PASSWORD.
             */
            MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_CUI_VERIFY_CANCEL);
            cancel_evt.cause = CUI_VERIFY_CANCEL_CAUSE_USER_CANCEL;
            cui_verify_send_to_parent(cntx, &cancel_evt);
            break;
        }

        case EVT_ID_SECSET_UBCHV_PASSIVE_CLOSING:
        {
            cui_verify_passive_closing_evt_struct closing_evt;

            MMI_FRM_INIT_EVENT(&closing_evt, EVT_ID_CUI_VERIFY_PASSIVE_CLOSING);
            if (cui_verify_send_to_parent(cntx, &closing_evt) == CUI_SECSET_DONT_CLOSE)
            {
                return MMI_SECSET_DONT_CLOSE;
            }
            break;
        }

        case EVT_ID_SECSET_UBCHV_BLOCKED:
        {
            cui_verify_result_evt_struct result_evt;

            mmi_secset_sim_display_popup(
                cntx->sim,
                SRV_SIM_CTRL_PWD_TYPE_UBCHV2,
                MMI_SECSET_STR_UBCHV_BLOCKED,
                MMI_EVENT_FAILURE,
                cntx->parent_grp_id,
                NULL);

            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_OPERATION_BLOCKED;
            cui_verify_send_to_parent(cntx, &result_evt);
            break;
        }
        
        case EVT_ID_SECSET_UBCHV_SIM_ERROR:
        {
            cui_verify_result_evt_struct result_evt;

            mmi_secset_sim_display_popup(
                cntx->sim,
                SRV_SIM_CTRL_PWD_TYPE_CHV2,
                MMI_SECSET_STR_SIM_ERROR,
                MMI_EVENT_FAILURE,
                cntx->parent_grp_id,
                NULL);

            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_CUI_VERIFY_RESULT);
            result_evt.success = MMI_FALSE;
            result_evt.fail_cause = CUI_VERIFY_FAIL_CAUSE_SIM_ERROR;
            cui_verify_send_to_parent(cntx, &result_evt);
            break;
        }
    }

    return MMI_RET_OK;
}


mmi_ret cui_verify_sim_on_sim_unavailable(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_verify_cntx_struct *cntx, *next_cntx;
    srv_sim_ctrl_unavailable_evt_struct *unavailable_evt;
    cui_verify_cancel_evt_struct cancel_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unavailable_evt = (srv_sim_ctrl_unavailable_evt_struct*)evt;
    
    for (cntx = g_cui_verify_cntx_global.list; cntx != NULL; )
    {
        /* cntx may be released on the callback */
        next_cntx = cntx->next;
    
        if (cntx->type_config->is_sim_related &&
            cntx->sim == unavailable_evt->sim)
        {
            if (mmi_frm_group_is_present(cntx->parent_grp_id))
            {
                MMI_TRACE(CUI_VERIFY_TRC_GROUP, TRC_CUI_VERIFY_SIM_UNAVAILABLE,
                    unavailable_evt->sim, cntx->this_grp_id, (U32)cntx, cntx->type_config->type);
            
                MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_CUI_VERIFY_CANCEL);
                cancel_evt.cause = CUI_VERIFY_CANCEL_CAUSE_UNAVAILABLE;
                cui_verify_send_to_parent(cntx, &cancel_evt);
            }
        }

        cntx = next_cntx;
    }

    return MMI_RET_OK;
}

