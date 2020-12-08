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
 *  vapp_phb_app.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 * removed!
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
#include "MMI_features.h"

#include "vapp_phb_app.h"
#include "vapp_contact_task.h"
#include "vapp_phb_launch.h"
#include "vapp_phb_setting.h"
#include "vapp_phb_gprot.h"
#include "vcui_phb_gprot.h"
#include "vapp_phb_vcard.h"
#include "AppMgrSrvGprot.h"
#include "vapp_usb_gprot.h"
#ifdef __MMI_SMS_COMPOSER__
#include "vcui_sms_composer_gprot.h"
#endif
#include "vapp_phb_editor.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "UcSrvGprot.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h"
#endif

#include "UcmGprot.h"
#include "FileMgrSrvGprot.h"

#ifdef __MMI_URI_AGENT__
#include "UriAgentSrvGprot.h"
#include "Conversions.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */
#include "GpioSrvGprot.h"

#ifdef __MMI_CM_BLACK_LIST__
#include "CallSetSrvGprot.h"
#endif

#include "GeneralSettingSrvGprot.h"
#include "UsbSrvGprot.h"
#include "SimCtrlSrvGProt.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif

#ifdef __DM_LAWMO_SUPPORT__
srv_dm_lawmo_wipe_report_cb_func_type g_dm_lawmo_wipe_report_cb = NULL;
#endif

extern "C"
{

MMI_ID vapp_phb_launch(void* args, U32 argSize)
{
    VFX_ASSERT(argSize == sizeof(vapp_phb_sub_app_launch_struct));
    vapp_phb_sub_app_launch_struct *param = (vapp_phb_sub_app_launch_struct *)args;

    // emit launch request
    vapp_phb_app_enter_req_struct req;

    MMI_FRM_INIT_EVENT(&req, EVT_ID_VAPP_PHB_APP_ENTER);
    req.sub_app_id = param->sub_app;
    req.sub_app_data = param->user_data;
    mmi_ret result = MMI_FRM_CB_EMIT_EVENT(&req);

    if (result != VAPP_PHB_ENTER_REQ_NO)
    {
        VfxApp *app = VfxAppLauncher::findApp(
                            VAPP_CONTACT,
                            VFX_OBJ_CLASS_INFO(VappPhbApp),
                            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
        if (app)
        {
            VfxAppLauncher::terminate(app->getGroupId());
        }

        return VfxAppLauncher::launch(
                    VAPP_CONTACT,
                    VFX_OBJ_CLASS_INFO(VappPhbApp),
                    GRP_ID_ROOT,
                    args,
                    argSize);
    }
    else
    {
        return result;
    }
}


MMI_ID vapp_contact_launch(void* args, U32 argSize)
{
    mmi_app_launch_param_struct *param = (mmi_app_launch_param_struct*) args;

    if (param == NULL || (param && (param->cat == MMI_LAUNCH_APP_IN_OPEN_CATEGORY)))
    {
        vapp_phb_sub_app_launch_struct launch;
        launch.sub_app = VAPP_PHB_SUB_APP_CONTACT;
        launch.user_data = NULL;

        return vapp_phb_launch(&launch, sizeof(vapp_phb_sub_app_launch_struct));
    }

    return GRP_ID_INVALID;
}


void vapp_phb_init(void)
{
    CONTACT_TASK_INIT();

#if defined( __MMI_MULTI_VCARD__ )
#ifdef __MMI_SMS_PORT_MSG__
    vapp_phb_vcard_sms_register();
#endif
#endif

#ifdef __MMI_URI_AGENT__
    vapp_phb_init_uri_agent_registration();
#endif

#ifdef __DM_LAWMO_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_PHB_MULTI_OP_DONE, vapp_phb_multi_op_done, NULL);
#endif
}


MMI_BOOL vapp_phb_check_ready(void)
{
    ContactTask *task = GET_CONTACT_TASK();

    return (task->checkReady() ? MMI_TRUE : MMI_FALSE);
}


MMI_BOOL vapp_phb_check_processing(void)
{
    ContactTask *task = GET_CONTACT_TASK();

    CONTACT_TASK action = task->checkTask();

    if (action != CONTACT_NONE && action != CONTACT_START)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void vapp_phb_unsaved_number_to_phb(WCHAR* number)
{
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
    // check number valid & number unsaved
    if (srv_phb_check_valid_number(number) && !srv_phb_check_number_exist(number))
    {
        vapp_phb_cui_adpter_struct param;
        memset(&param, 0, sizeof(vapp_phb_cui_adpter_struct));

        param.m_type = VAPP_PHB_CUI_ADPTER_NOTIFIER;
        mmi_wcscpy((WCHAR*) param.m_number, (WCHAR*) number);

        // create cui adapter
        vapp_phb_cui_adpter_launch(&param);
    }
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */
}


VfxBool vapp_phb_usb_app_is_available(void)
{
#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            VcpPopupTypeEnum type;
            vapp_usb_unavailable_popup(vapp_usb_get_error_info(0, &type));
            return VFX_FALSE;
        }
    }
#endif /* __MMI_USB_SUPPORT__ */

    return VFX_TRUE;
}


VfxBool vapp_phb_ready_balloon(void)
{
    ContactTask *task = GET_CONTACT_TASK();

    if (task->checkTask() != CONTACT_NONE)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


mmi_ret vapp_phb_processing_hdlr(mmi_event_struct* para)
{
    switch (para->evt_id)
    {
        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
        case EVT_ID_GPIO_AFTER_LCD_SLEEP_IN:
            if (vapp_phb_check_processing())
            {
                return 1;
            }
            break;

    #ifdef __DM_LAWMO_SUPPORT__
        case EVT_ID_SRV_DM_LAWMO_LOCK_IND:
        {
            srv_dm_lawmo_lock_ind_evt_struct* lawmo_evt = (srv_dm_lawmo_lock_ind_evt_struct *)para;
            MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_DM_EVT_LOCK, para->evt_id, lawmo_evt->cmd, lawmo_evt->cb);
            break;
        }

        case EVT_ID_SRV_DM_LAWMO_WIPE_IND:
        {
            srv_dm_lawmo_wipe_ind_evt_struct* lawmo_evt = (srv_dm_lawmo_wipe_ind_evt_struct*)para;

            MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_DM_EVT_WIPE, para->evt_id, lawmo_evt->cmd, lawmo_evt->cb);

            if (lawmo_evt->cmd == SRV_DM_LAWMO_WIPE_CMD_APP_WIPE)
            {
                g_dm_lawmo_wipe_report_cb = lawmo_evt->cb;

                if (vapp_phb_check_ready())
                {
                    CONTACT_TASK oriTask;
                    CONTACT_STATE retState;
                    ContactTask *task;

                    task = GET_CONTACT_TASK();
                    oriTask = task->checkTask();

                    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_OP_TASK_WIPE, oriTask + 100);

                    if (vapp_phb_check_processing())
                    {
                        retState = task->task(CONTACT_DM_WIPE, CONTACT_WANT, NULL);
                        if (retState != CONTACT_RUN)
                        {
                            VFX_ASSERT(0);
                        }
                    }
                    else
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_OP_TASK_WIPE, (task->checkTask() + 100));
                        vapp_phb_dm_wipe_do_format();
                    }
                }
                else
                {
                    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_OP_TASK_WIPE, CONTACT_START + 100);
                }
            }
            break;
        }
    #endif /* __DM_LAWMO_SUPPORT__ */

    #if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
        case EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED:
        {
            srv_sim_ctrl_event_detected_evt_struct *sim_ctrl_evt = (srv_sim_ctrl_event_detected_evt_struct*)para;

            if (SRV_SIM_CTRL_EVENT_DET_REMOVED == sim_ctrl_evt->type ||
                SRV_SIM_CTRL_EVENT_DET_INSERTED == sim_ctrl_evt->type ||
                SRV_SIM_CTRL_EVENT_DET_RECOVERY_START == sim_ctrl_evt->type ||
                SRV_SIM_CTRL_EVENT_DET_RECOVERY_END == sim_ctrl_evt->type)
            {
                VfxApp *app = VfxAppLauncher::findApp(
                                    VAPP_CONTACT,
                                    VFX_OBJ_CLASS_INFO(VappPhbApp),
                                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
                if (app)
                {
                    VfxAppLauncher::terminate(app->getGroupId());
                }

                VfxApp *app2 = VfxAppLauncher::findApp(
                                    VCUI_CONTACT_SETTING,
                                    VFX_OBJ_CLASS_INFO(VappContactSettingCUI),
                                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
                if (app2)
                {
                    VfxAppLauncher::terminate(app2->getGroupId());
                }
            }
            break;
        }
    #endif /* defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__) */
    }

    return MMI_RET_OK;
}


void vapp_phb_op_error_balloon(S32 result)
{
    if (result == SRV_PHB_NAME_MODIFIED)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_PHB_NAME_MODIFIED).getBuf());
    }
    else if (result == SRV_PHB_SIM_PARTIAL_ERROR)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_PHB_INFO_MISSED).getBuf());
    }
    else if (result > 0)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY).getBuf());
    }
    else if (result == SRV_PHB_ADN_FORBID)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_PHB_ADN_FORBID).getBuf());
    }
    else if (result == SRV_PHB_NUMBER_TOO_LONG)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_PHB_NUMBER_TOO_LONG).getBuf());
    }
    else if (result < 0)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(STR_GLOBAL_UNFINISHED).getBuf());
    }
}


static void vapp_phb_cui_adapter_copy_param(vapp_phb_cui_adpter_struct *dst, vapp_phb_cui_adpter_struct *src)
{
    MMI_ASSERT(dst != NULL && src != NULL);

    memset(dst, 0, sizeof(vapp_phb_cui_adpter_struct));

    dst->m_type = src->m_type;
    mmi_wcsncpy(dst->m_name, src->m_name, MMI_PHB_NAME_LENGTH + 1);
    mmi_wcsncpy(dst->m_number, src->m_number, MMI_PHB_NUMBER_LENGTH + 1 + 1);
    dst->m_userData = src->m_userData;
}


static MMI_BOOL vapp_phb_cui_adapter_notify_app_launch(mmi_scenario_id scen_id, void *arg)
{
    vapp_phb_cui_adpter_struct *param = (vapp_phb_cui_adpter_struct *)arg;
    mmi_id adapter_app_id = GRP_ID_INVALID;

    // get app id
    mmi_id app_id = VCUI_CONTACT_ADPTER;

    if (param->m_type == VAPP_PHB_CUI_ADPTER_NOTIFIER)
    {
        app_id = VCUI_CONTACT_ADPTER_NOTIFY;
    }

    // check re-entry, if exist just close it
    VfxApp *app = VfxAppLauncher::findApp(
                        app_id,
                        VFX_OBJ_CLASS_INFO(VappPhbCuiAdpter),
                        VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }

    // launch new instance
   adapter_app_id = VfxAppLauncher::launch(app_id, VFX_OBJ_CLASS_INFO(VappPhbCuiAdpter), GRP_ID_ROOT, param, sizeof(vapp_phb_cui_adpter_struct));
   MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_CUI_ADAPTER_FREE]--arg: 0x%0x, adapter_app_id: %d, app_id: %d, m_type: %d\n", arg, adapter_app_id, app_id, param->m_type);

   srv_phb_mem_free(arg);

   return adapter_app_id == GRP_ID_INVALID ? MMI_FALSE : MMI_TRUE;
}


mmi_id vapp_phb_cui_adpter_launch(vapp_phb_cui_adpter_struct *param)
{
    vapp_phb_cui_adpter_struct *arg = (vapp_phb_cui_adpter_struct *)srv_phb_mem_malloc(sizeof(vapp_phb_cui_adpter_struct), SRV_PHB_MEMORY_TYPE_CTR);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_CUI_ADAPTER_ALLOCATOR]--arg: 0x%0x, size: %d\n", arg, sizeof(vapp_phb_cui_adpter_struct));
    vapp_phb_cui_adapter_copy_param(arg, param);
    // call nmgr
    MMI_BOOL ret = mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_DEFAULT, vapp_phb_cui_adapter_notify_app_launch, (void *)arg);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_CUI_ADAPTER_NMGR]--ret: %d\n", ret);

    return GRP_ID_INVALID;
}


#ifdef __MMI_URI_AGENT__
typedef struct
{
    srv_uriagent_appid_enum appid;
    srv_uriagent_uri_request_hdlr_cb cb;
} vapp_phb_uriagent_info_struct;


void vapp_phb_uriagent_exec_callback(
           srv_uriagent_uri_request_hdlr_cb cb,
           srv_uriagent_appid_enum ura_appid,
           srv_uriagent_appid_enum uha_appid,
           U32 result)
{
    if (cb != NULL)
    {
        cb(ura_appid, uha_appid, (unsigned int)result);
    }
}


void vapp_phb_uriagent_parse_uri(U8* uri, VfxWChar* ucs2_name, VfxWChar* ucs2_num)
{
    CHAR* cur_pos = (CHAR*)uri;
    CHAR* num_start_pos = NULL;
    CHAR* name_start_pos = NULL;
    U16 num_len;
    CHAR* temp_num_buff = NULL;

    cur_pos = strstr((CHAR*)uri, ";");

    /* number */
    if (cur_pos == NULL)
    {
        // number field is necessary
        return;
    }
    else
    {
        num_start_pos = cur_pos + 1;
    }

    cur_pos = strstr(num_start_pos, ";");

    // no name field, parse number
    if (cur_pos == NULL)
    {
        mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char*)num_start_pos,
            (char*)ucs2_num,
            (MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);

        return;
    }
    // with name field
    else
    {
        name_start_pos = cur_pos + 1;

        num_len = name_start_pos - num_start_pos - 1;
        temp_num_buff = (CHAR*)srv_phb_mem_malloc(num_len + 1, SRV_PHB_MEMORY_TYPE_CTR);
        memset(temp_num_buff, 0x00, (num_len + 1));
        memcpy(temp_num_buff, num_start_pos, num_len);

        mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char*)temp_num_buff,
            (char*)ucs2_num,
            (MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);

        mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char*)name_start_pos,
            (char*)ucs2_name,
            (MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH);

        srv_phb_mem_free(temp_num_buff);
    }
}

static VfxBool vapp_phb_uriagent_exit;
static vapp_phb_uriagent_info_struct vapp_phb_uriagent_info;


void vapp_phb_uriagent_wtai_save_entry(
        srv_uriagent_appid_enum appid,
        char *url,
        char *param1,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    vapp_phb_cui_adpter_struct param;
    memset(&param, 0, sizeof(vapp_phb_cui_adpter_struct));
    param.m_type = VAPP_PHB_CUI_ADPTER_URIAGENT;

    vapp_phb_uriagent_exit = VFX_FALSE;
    vapp_phb_uriagent_parse_uri((U8*)url, param.m_name, param.m_number);

    vapp_phb_uriagent_info.cb = cb;
    vapp_phb_uriagent_info.appid = appid;

    vapp_phb_cui_adpter_launch(&param);
}


void vapp_phb_init_uri_agent_registration(void)
{
    srv_uriagent_err_enum err_code = SRV_URIAGENT_ERR_UNSUPPORTED;
    
    err_code = srv_uriagent_register_hdlr_by_prefix("wtai://wp/ap", vapp_phb_uriagent_wtai_save_entry, MMI_FALSE);

    if (err_code != SRV_URIAGENT_ERR_OK)
    {
        VFX_ASSERT(0);
    }
}
#endif /* __MMI_URI_AGENT__ */


#ifdef __MMI_CM_BLACK_LIST__
srv_callset_result_enum vapp_phb_add_to_blacklist(mmi_phb_contact_id id, VappContactNumber& number)
{
    return srv_callset_blacklist_add_number(
                (U8)mmi_ucs2strlen((CHAR*) number.getBuf()),
                (WCHAR*) number.getBuf(),
                NULL,
                NULL);
}


VfxBool vapp_phb_is_blocked_number(mmi_phb_contact_id id, VappContactNumber& number)
{
    srv_callset_blacklist_mode_enum mode;
    VfxBool result;

    mode = srv_callset_blacklist_get_mode(NULL);

    srv_callset_blacklist_set_mode(SRV_CALLSET_BLACKLIST_FROM_LIST, NULL);

    result = srv_callset_blacklist_is_blocked_number(
                (U8)mmi_ucs2strlen((CHAR*) number.getBuf()),
                (WCHAR*) number.getBuf(),
                NULL) ? VFX_TRUE : VFX_FALSE;

    srv_callset_blacklist_set_mode(mode, NULL);

    return result;
}


srv_callset_result_enum vapp_phb_delete_from_blacklist(mmi_phb_contact_id id, VappContactNumber& number)
{
    return srv_callset_blacklist_delete_number(
                (U8)mmi_ucs2strlen((CHAR*) number.getBuf()),
                (WCHAR*) number.getBuf(),
                NULL,
                NULL);
}
#endif /* __MMI_CM_BLACK_LIST__ */


#ifdef __DM_LAWMO_SUPPORT__
void vapp_phb_dm_wipe_format_result_proc(srv_phb_async_op_cb_struct *param)
{
    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_WIPE_PROC, param->type);

    switch (param->type)
    {
        case SRV_PHB_OP_CB_TYPE_DELETE_ALL:
        {
            srv_phb_delete_all_cb_struct *delFinish = (srv_phb_delete_all_cb_struct *)param;
            srv_dm_lawmo_wipe_report_cb_func_type dm_lawmo_wipe_report_cb = (srv_dm_lawmo_wipe_report_cb_func_type)delFinish->user_data;
            srv_phb_handle del_handle = delFinish->handle;

            MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_WIPE_PROC_DELETE_ALL, param->type, delFinish->finish_count, delFinish->total_count);

            if (dm_lawmo_wipe_report_cb)
            {
                (*dm_lawmo_wipe_report_cb)((delFinish->finish_count == delFinish->total_count) ? KAL_TRUE : KAL_FALSE, "PHB");
            }

            ContactTask *task = GET_CONTACT_TASK();
            CONTACT_STATE ret_state = task->task(CONTACT_DM_WIPE, CONTACT_FINISH, NULL);

            if (del_handle)
            {
                srv_phb_free_handle(del_handle);
                del_handle = NULL;
            }
            break;
        }

        case SRV_PHB_OP_CB_TYPE_UPDATE_STATUS:
        {
            srv_phb_multi_op_status_cb_struct *delUpdate = (srv_phb_multi_op_status_cb_struct *)param;
            MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_WIPE_PROC_UPDATE_STATUS, param->type, delUpdate->finish_count, delUpdate->fail_count);
            break;
        }
    }
}


VfxS32 vapp_phb_dm_wipe_do_format()
{
    VfxS32 ret = -1;
    phb_storage_enum storage = PHB_STORAGE_NVRAM;
    CONTACT_TASK task = CONTACT_DM_WIPE;
    CONTACT_STATE state = CONTACT_WANT;
    CONTACT_STATE ret_state;
    srv_phb_handle del_handle;
    ContactTask *contactTask = GET_CONTACT_TASK();

    ret_state = contactTask->task(task, state, NULL);

    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_OP_TASK, ret_state + 10);

    if (ret_state == CONTACT_RUN)
    {
        srv_phb_delete_all_req_struct req;
        req.storage = storage;
        req.cb = vapp_phb_dm_wipe_format_result_proc;
        req.user_data = (void*)g_dm_lawmo_wipe_report_cb;

        del_handle = srv_phb_delete_all_contact(&req); 
    }
    else
    {
        if (g_dm_lawmo_wipe_report_cb)
        {
            (*g_dm_lawmo_wipe_report_cb)(KAL_FALSE, "PHB");
        }
    }

    g_dm_lawmo_wipe_report_cb = NULL;

    return ret;
}


mmi_ret vapp_phb_multi_op_done(mmi_event_struct* evt)
{
    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_MULTI_OP_DONE, g_dm_lawmo_wipe_report_cb, evt->evt_id);

    if (g_dm_lawmo_wipe_report_cb)
    {
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_MULTI_OP_DONE, g_dm_lawmo_wipe_report_cb, evt->evt_id);

        CONTACT_TASK oriTask;
        CONTACT_STATE retState;
        ContactTask *task;

        task = GET_CONTACT_TASK();
        oriTask = task->checkTask();

        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_OP_TASK, oriTask + 100);

        if (oriTask != CONTACT_DM_WIPE)
        {
            VFX_ASSERT(0);
        }

        retState = task->task(CONTACT_DM_WIPE, CONTACT_FINISH, NULL);

        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_OP_TASK, retState);
        vapp_phb_dm_wipe_do_format();
    }

    return MMI_RET_OK;
}

#endif /* __DM_LAWMO_SUPPORT__ */


void vapp_phb_get_head_portrait_filter(FMGR_FILTER *filter)
{
    ASSERT(filter);
    
    FMGR_FILTER_INIT(filter);
#if defined(__GDI_MEMORY_PROFILE_2__)   /* Able to select jpeg file if supported */
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif 
    FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
#if defined(GDI_USING_PNG)
    FMGR_FILTER_SET(filter, FMGR_TYPE_PNG);
#endif 
#if defined(GDI_USING_M3D)
    FMGR_FILTER_SET(filter, FMGR_TYPE_M3D);
#endif
/* .SVG file is now not supported due to stack overflow */
#ifdef SVG12_SUPPORT
    FMGR_FILTER_SET(filter, FMGR_TYPE_SVG);
#endif
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
/* .mav is now not supported due to the vcard
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    FMGR_FILTER_SET(filter, FMGR_TYPE_MAV);
#endif
*/
}


MMI_BOOL vapp_phb_query_head_portrait_type(mmi_fmgr_filetype_enum type)
{
    FMGR_FILTER filter;

    vapp_phb_get_head_portrait_filter(&filter);

    if (FMGR_FILTER_IS_SET(&filter, type))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

}


MMI_BOOL vapp_phb_query_head_portrait_need_thumbnail(S8* filePath)
{
    //kal_prompt_trace(MOD_MMI, "vapp_phb_query_head_portrait_need_thumbnail");
    S32 image_width;
    S32 image_height;
    S32 result;
    result = gdi_image_get_dimension_file(filePath,
                                         &image_width,
                                         &image_height);
    if (result >= 0 )
    {
        if(image_width <= ICON_SIZE && image_height <= ICON_SIZE)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }        
    }
}


/***************************************************************************** 
 * class VappPhbActionObj
 *****************************************************************************/
VappPhbActionObj::VappPhbActionObj():
    m_data(NULL),
    m_count(0)
{
}


void VappPhbActionObj::setType(vapp_phb_action_type_enum type)
{
    m_type = type;
}


void VappPhbActionObj::setData(vapp_phb_action_data_struct& data)
{
}


void VappPhbActionObj::makeCallCb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para)
{
    srv_phb_destory_cm_user_data(make_call_cb_para->user_data);
}


void VappPhbActionObj::makeCall(mmi_phb_contact_id id, VappContactNumber& number, mmi_sim_enum sim, MMI_BOOL m_isIpDial)
{
    mmi_ucm_make_call_para_struct make_call_para;
    void *cm_user_data;

    mmi_ucm_init_call_para(&make_call_para);

    cm_user_data = srv_phb_create_cm_user_data_by_sub_id(NULL, number.getSubId(), id);

    if(sim == MMI_SIM1 || sim == MMI_SIM2 || sim == MMI_SIM3 || sim ==MMI_SIM4)
    {
        make_call_para.dial_type = srv_ucm_query_voice_type_by_sim(sim);
    }
    else
    {
        make_call_para.dial_type = (srv_ucm_call_type_enum)(make_call_para.dial_type & (~SRV_UCM_VOIP_CALL_TYPE));
    }

    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;
    make_call_para.adv_para.after_make_call_callback = VappPhbActionObj::makeCallCb;
    make_call_para.ucs2_num_uri = (U16*) number.getBuf(); 
#ifdef __IP_NUMBER__
    if (m_isIpDial == MMI_TRUE)
	{
		make_call_para.adv_para.is_ip_dial = MMI_TRUE;
	}
#endif /* __IP_NUMBER__ */
    mmi_ucm_call_launch(0, &make_call_para);
}


void VappPhbActionObj::videoCall(mmi_phb_contact_id id, VappContactNumber& number)
{
    mmi_ucm_make_call_para_struct make_call_para; 
    void *cm_user_data;

    mmi_ucm_init_call_para(&make_call_para);

    cm_user_data = srv_phb_create_cm_user_data_by_sub_id(NULL, number.getSubId(), id);

    make_call_para.dial_type = SRV_UCM_VIDEO_CALL_TYPE;

    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;
    make_call_para.adv_para.after_make_call_callback = VappPhbActionObj::makeCallCb;
    make_call_para.ucs2_num_uri = (U16*) number.getBuf();

    mmi_ucm_call_launch(0, &make_call_para);
}


void VappPhbActionObj::sendMessage(mmi_phb_contact_id id, VappContactNumber& number, mmi_sim_enum sim)
{
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
    VappUcEntryStruct *ucEntry;
    ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));

    // set uc type
    memset(ucEntry, 0, sizeof(VappUcEntryStruct));
#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE, NULL))
    {
        ucEntry->msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
    }
#else /* defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__) */
    {
        ucEntry->msg_type = SRV_UC_MSG_TYPE_DEFAULT;
    }
#endif /* defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__) */
    ucEntry->type = SRV_UC_STATE_WRITE_NEW_MSG;
    ucEntry->launch_mode = UC_LAUNCH_MODE_NORMAL;

    // set address
    srv_uc_addr_struct addr;
    addr.next = NULL;
    addr.previous = NULL;
    addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
    addr.addr = (U8*)(number.getBuf());
    addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
    ucEntry->addr_num = 1;
    ucEntry->addr = &addr;

    if (sim == MMI_SIM1)
    {
        ucEntry->sim_id = SRV_UC_SIM_ID_GSM_SIM1;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (sim == MMI_SIM2)
    {
        ucEntry->sim_id = SRV_UC_SIM_ID_GSM_SIM2;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim == MMI_SIM3)
    {
        ucEntry->sim_id = SRV_UC_SIM_ID_GSM_SIM3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim == MMI_SIM4)
    {
        ucEntry->sim_id = SRV_UC_SIM_ID_GSM_SIM4;
    }
#endif
    else
    {
        ucEntry->sim_id = (srv_uc_sim_id)sim;
    }

    vappUcAppLauncher(ucEntry);

    mmi_frm_temp_free(ucEntry);
#endif
}


void VappPhbActionObj::sendEmail(mmi_phb_contact_id id, VappContactEmail& email)
{
#ifdef __MMI_EMAIL__
    VfxU16 name[MMI_PHB_NAME_LENGTH + 1];
    srv_phb_get_name(id, name, MMI_PHB_NAME_LENGTH);
    mmi_email_app_send_to_ext((CHAR*) email.getBuf(), (CHAR*) name);
#endif /* __MMI_EMAIL__ */
}


/***************************************************************************** 
 * Class VappPhbCuiAdpter
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbCuiAdpter", VappPhbCuiAdpter, VfxApp);

void VappPhbCuiAdpter::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    vapp_phb_cui_adpter_struct *param = (vapp_phb_cui_adpter_struct*) args;
    m_type = param->m_type;

    mmi_id cui_id = vcui_phb_contact_saver_create2(getGroupId());

    if (param->m_type == VAPP_PHB_CUI_ADPTER_URIAGENT)
    {
        vcui_phb_contact_saver_set_type(cui_id, VAPP_PHB_SAVE_CONTACT_NEW);
        vcui_phb_contact_saver_set_name(cui_id, (WCHAR*)param->m_name, mmi_wcslen((WCHAR*)(param->m_name)));
        vcui_phb_contact_saver_set_number(cui_id, (WCHAR*)param->m_number, mmi_wcslen((WCHAR*)(param->m_number)));
        vcui_phb_contact_saver_set_user_data(cui_id, param->m_userData);
        vcui_phb_contact_saver_run(cui_id);
    }
    else if (param->m_type == VAPP_PHB_CUI_ADPTER_NOTIFIER)
    {
        vcui_phb_contact_saver_set_number(cui_id, param->m_number, mmi_wcslen(param->m_number));
        vcui_phb_contact_saver_run(cui_id);
    }
    else
    {
        VFX_ASSERT(0);
    }
}


mmi_ret VappPhbCuiAdpter::onProc(mmi_event_struct *evt)
{
#ifdef __MMI_URI_AGENT__
    if (m_type == VAPP_PHB_CUI_ADPTER_URIAGENT)
    {
        switch (evt->evt_id)
        {
            case EVT_ID_CUI_PHB_SAVE_RESULT:
            {
                vcui_phb_contact_save_result_event_struct* result = (vcui_phb_contact_save_result_event_struct*)evt;
                
                vapp_phb_uriagent_exec_callback(vapp_phb_uriagent_info.cb, vapp_phb_uriagent_info.appid, SRV_URIAGENT_APPID_PHONEBOOK, result->result);
                vapp_phb_uriagent_exit = VFX_TRUE;

                vcui_phb_contact_saver_close(((mmi_group_event_struct*)evt)->sender_id);
                exit();
                break;
            }

            case EVT_ID_GROUP_EXIT:
            {
                if (vapp_phb_uriagent_exit)
                {
                    break;
                }

                vapp_phb_uriagent_exec_callback(vapp_phb_uriagent_info.cb, vapp_phb_uriagent_info.appid, SRV_URIAGENT_APPID_PHONEBOOK, VFX_FALSE);
                vapp_phb_uriagent_exit = VFX_TRUE;
                break;
            }
        }
    }
#endif /* __MMI_URI_AGENT__ */

    return VfxApp::onProc(evt);
}


