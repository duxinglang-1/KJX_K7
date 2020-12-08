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
 *   WlanCui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Data account Common UI source file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
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
 *==============================================================================
 *******************************************************************************/

#if defined(__TCPIP__)
/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_WLAN_FEATURES__
#include "wlancui.h"
#include "wlancuigprot.h"
#include "DtcntSrvIprot.h"
#include "MMIDataType.h"
#include "DataAccountStruct.h"
#include "DataAccountDef.h"
#include "DtcntSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "supc_abm_msgs.h"
#include "string.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreens.h"
#include "DataAccountProt.h"
#include "GlobalResDef.h"
#include "mmi_frm_nvram_gprot.h"
#include "DataAccountEnum.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "wndrv_cnst.h"
#include "mmi_cb_mgr_gprot.h"
#include "GlobalConstants.h"
#include "wndrv_supc_types.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_list.h"
#include "gui_fixed_menuitems.h"
#include "wgui_categories_popup.h"
#include "CommonScreensResDef.h"
#include "ModeSwitchSrvGProt.h"
/*------------------------------ suggest Add ------------------------------*/
#include "l4c_nw_cmd.h"
#include "mmi_conn_app_trc.h"
#ifndef __OPTR_NONE__
#include "mmi_rp_app_connectivity_mainmenu_def.h"
#endif
#include "SimCtrlSrvGprot.h"
#include "DataAccountCore.h"

/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* Global Variable Declaration
*******************************************************************************/
mmi_id g_cui_wlan_gid;
U8 g_wlan_ap_list_hilt_idx;
cui_wlan_list_struct  g_cui_wlan_cntx;
cui_wlan_ap_list_action_cb_func_ptr g_wlan_ap_list_action_cb;

extern mmi_wlan_display_struct g_wlan_display_context;
extern mmi_wlan_profile_struct *g_wlan_profile[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_profile_struct g_profile_saved_temp;
extern U8 g_dtcnt_is_WEP_key;
extern supc_abm_bss_info_struct g_cui_hilt_profile;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
extern MMI_BOOL g_wapi_test_mode;
#endif /* __MMI_HIDE_WAPI__ */
#endif

/*******************************************************************************
* Function Declaration
*******************************************************************************/
void cui_wlan_scan_network_start(void);
void cui_wlan_scan_network_cb(U32 job_id, void *user_data,srv_dtcnt_wlan_scan_result_struct *scan_res);
void cui_wlan_entry_scan_network_srcn(void);
void cui_wlan_cancel_scan_job(void);
void cui_wlan_prepare_wizard_list(U8 *se_num, U8 *sa_num, U8 *se_sa_num);
void cui_wlan_entry_new_wizard_list(void);
void cui_wlan_wizard_list_highlight_hdlr(S32 nIndex);
void cui_wlan_refresh_ap_list_scrn(void);
void cui_wlan_connect_ap(void);
void cui_wlan_cancel(void);
void cui_wlan_pre_connect_ap(const char* passphrase, U32 keylen);
srv_dtcnt_result_enum cui_wlan_connect_app_prof(mmi_wlan_profile_struct *app_prof);
void cui_wlan_connect_search_ap(void);
void cui_wlan_connect_ap_with_passphrase(void);
void cui_wlan_invalid_passphrase_popup(U16 prompt);
MMI_BOOL cui_wlan_verify_wapi_pre_shared_key(void);
void cui_wlan_entry_edit_passphrase_scrn(void);
void cui_wlan_entry_edit_identity_scrn(void);

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
void cui_wlan_entry_wapi_psk_scrn(void);
void cui_wlan_entry_wapi_cert_scrn(void);
void cui_wlan_connect_ap_with_wapi(void);
extern void mmi_wlan_wapi_entry_ASE_cert_list(void);
extern void mmi_wlan_wapi_entry_user_cert_list(void);
#endif /* __MMI_HIDE_WAPI__ */
#endif

static mmi_ret cui_wlan_leave_callback(mmi_event_struct* evt);
static mmi_ret cui_wlan_list_group_proc(mmi_event_struct *evt);
static mmi_ret cui_wlan_turn_off_hotspot_confirm(mmi_alert_result_evt_struct *evt);
static void cui_wlan_turn_off_hotspot_callback(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data);
static void cui_wlan_display_waiting_screen(void);

#ifdef __MMI_OP01_WIFI__
static void cui_wlan_cmcc_entry_wizard_list(void);
static void cui_wlan_cmcc_prepare_wizard_list(U8 *se_num, U8 *sa_num, U8 *se_sa_num);
extern MMI_BOOL mmi_wlan_is_default_trust_ap(const mmi_wlan_profile_struct *profile);
extern MMI_BOOL mmi_wlan_is_same_ap(const mmi_wlan_profile_struct *fst, const mmi_wlan_profile_struct *snd);
extern MMI_BOOL mmi_wlan_is_black_list_ap(const mmi_wlan_profile_struct *profile);
extern U8 g_index_main_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_id g_wlan_ap_list_cui_id;
#endif

void cui_wlan_always_ask_action_cb(cui_wlan_ap_list_action action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_wlan_list_event_struct ap_list_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(action)
    {
    case CUI_WLAN_AP_LIST_ACTION_CONNECT:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_CMCC_CONNECT_SUCCESS, g_cui_wlan_gid);
        MMI_FRM_INIT_GROUP_EVENT(
            (mmi_group_event_struct*)&ap_list_evt, 
            CUI_WLAN_LIST_EVENT_RESULT_OK, 
            g_cui_wlan_gid);
        break;
    case CUI_WLAN_AP_LIST_ACTION_CANCEL:
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_CMCC_CANCEL, g_cui_wlan_gid);
        MMI_FRM_INIT_GROUP_EVENT(
            (mmi_group_event_struct*)&ap_list_evt, 
            CUI_WLAN_LIST_EVENT_RESULT_CANCEL, 
            g_cui_wlan_gid);
        break;
    case CUI_WLAN_AP_LIST_ACTION_FAILED:    /* send the failed event */
    case CUI_WLAN_AP_LIST_ACTION_CLOSE:
        break;
    default:
        MMI_ASSERT(0);
    }

    mmi_frm_group_send_to_parent (g_cui_wlan_gid, (mmi_group_event_struct*)&ap_list_evt);
}

void cui_wlan_inform_caller_action(cui_wlan_ap_list_action action)
{
    if(g_wlan_ap_list_action_cb)
    {
        g_wlan_ap_list_action_cb(action);
        g_wlan_ap_list_action_cb = NULL;
    }
}

mmi_id cui_wlan_list_group_init(mmi_id parent_gid, void* parent_data, const cui_wlan_ap_list_action_cb_func_ptr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_OP01_WIFI__)
    if (!srv_mode_switch_is_network_service_available())
    {
        mmi_popup_display(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), 
            MMI_EVENT_FAILURE, 
            NULL);
        return GRP_ID_INVALID;
    }
#endif
    if((GRP_ID_INVALID != g_cui_wlan_gid) &&
        mmi_frm_group_is_present (g_cui_wlan_gid))
    {
        cui_wlan_list_close (g_cui_wlan_gid);
    }
    
    /* Create a new group */    
    g_cui_wlan_gid = mmi_frm_group_create(parent_gid, 
                                        GRP_ID_AUTO_GEN, 
                                        cui_wlan_list_group_proc, 
                                        parent_data);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_LIST_CREATE, g_cui_wlan_gid);

    g_wlan_ap_list_action_cb = cb;
    
    return g_cui_wlan_gid;
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_list_create
 * DESCRIPTION
 *  API for other application to create WLAN cui 
 * PARAMETERS
 *  parent_gid     [IN]        
 * RETURNS
 *  mmi_id  WLAN cui's group id
 *****************************************************************************/
mmi_id cui_wlan_list_create(mmi_id parent_gid, void* parent_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cui_wlan_list_group_init (parent_gid, parent_data, cui_wlan_always_ask_action_cb);
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_list_run
 * DESCRIPTION
 *  API for executing WLAN cui
 * PARAMETERS
 *  cui_gid     [IN]        
 * RETURNS
 *  void  
 *****************************************************************************/
void cui_wlan_list_run(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_tethering_stop;
    mmi_confirm_property_struct popup_property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_LIST_RUN, cui_gid);
    if(cui_gid == GRP_ID_INVALID)
    {
        // cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_FAILED);
        MMI_ASSERT(0);
    }
    else
    {
        is_tethering_stop = srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_STOP_TETHERING_CNF, is_tethering_stop);
        if(MMI_FALSE == is_tethering_stop)
        {
            mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_NONE_FLAG);
            
            mmi_confirm_property_init(&popup_property, CNFM_TYPE_YESNO);
            popup_property.callback = (mmi_proc_func)cui_wlan_turn_off_hotspot_confirm;
            popup_property.parent_id = cui_gid;
            mmi_confirm_display(
                (WCHAR *)((UI_string_type)GetString(STR_ID_DTCNT_WLAN_TURN_OFF_HOTSPOT_CFM)),
                MMI_EVENT_QUERY, 
                &popup_property);
        }
        else
        {
            mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_NONE_FLAG);
            // scan for networks
            cui_wlan_scan_network_start();
            // control the flow of showing ap list by nmgr
            /*
            mmi_frm_nmgr_notify_by_app (
                MMI_SCENARIO_ID_SHOW_WLAN_AP_LIST, 
                MMI_EVENT_NON_TONE,
                cui_wlan_list_nmgr_cb, 
                NULL);
            */
        }
    }
}

MMI_BOOL cui_wlan_list_nmgr_cb(mmi_scenario_id scen_id, void *arg)
{
    // start scenario for showing ap list
    mmi_frm_start_scenario (MMI_SCENARIO_ID_SHOW_WLAN_AP_LIST);
    // scan for networks
    cui_wlan_scan_network_start();

    return MMI_TRUE;
}

void cui_wlan_list_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_LIST_CLOSE, cui_gid);

    if(GRP_ID_INVALID != cui_gid)
    {
        mmi_frm_group_close(cui_gid);
        cui_gid = GRP_ID_INVALID;
    }
    memset(&g_cui_wlan_cntx, 0, sizeof(cui_wlan_list_struct));
}

mmi_ret cui_wlan_turn_off_hotspot_confirm(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            cui_wlan_display_waiting_screen();
            srv_tethering_stop (SRV_TETHERING_TYPE_WIFI_HS, cui_wlan_turn_off_hotspot_callback, NULL);
            break;
        case MMI_ALERT_CNFM_NO:
            cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_CANCEL);
            break;
        }
    }
    return MMI_RET_OK;
}

void cui_wlan_turn_off_hotspot_callback(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_AFTER_STOP_TETHERING_CB, result);
    if(MMI_TRUE == result)
    {
        mmi_alert_dismiss(g_wlan_display_context.waiting_screen_id);

        // scan for networks
        cui_wlan_scan_network_start();
        /*
        mmi_frm_nmgr_notify_by_app (
            MMI_SCENARIO_ID_SHOW_WLAN_AP_LIST, 
            MMI_EVENT_NON_TONE,
            cui_wlan_list_nmgr_cb, 
            NULL);
        */
    }
    else
    {
        cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_CANCEL);
    }
}

void cui_wlan_display_waiting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = g_cui_wlan_gid;
    arg.callback = NULL;
    arg.f_enter_history = MMI_TRUE;
    arg.softkey[0].str = 0;
    arg.softkey[1].str = 0;
    arg.softkey[2].str = 0;
    g_wlan_display_context.waiting_screen_id = mmi_confirm_display(
                                        (WCHAR*)GetString(STR_GLOBAL_PLEASE_WAIT),
                                        MMI_EVENT_PROGRESS,
                                        &arg);
}

void cui_wlan_scan_network_start(void)
{
    g_cui_wlan_cntx.list_sa_num = 0;
    g_cui_wlan_cntx.list_se_num = 0;
    g_cui_wlan_cntx.list_se_sa_num = 0;
    memset(g_cui_wlan_cntx.prof_list, 0, sizeof(mmi_wlan_wizard_list_struct) * (WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM));
    
    // Scan for network
    g_wlan_display_context.scan_job_id = srv_dtcnt_wlan_scan(cui_wlan_scan_network_cb, NULL);

    // Update status bar icon
    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, TRUE);
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_SCAN_JOB, g_wlan_display_context.scan_job_id);
    
    // Entry scan waiting screen
    cui_wlan_entry_scan_network_srcn();
}

void cui_wlan_scan_network_cb(
                            U32 job_id,
                            void *user_data,
                            srv_dtcnt_wlan_scan_result_struct *scan_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct new_node_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_SCAN_EVENT_HDR, scan_res->result);
    mmi_wlan_set_status_bar_icon ();
    
    /* Response caller result as cancel if scan failed or */
    if ((SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS != scan_res->result) ||
    /* There is no available AP existed */
        ((SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS == scan_res->result) && (0 == scan_res->ap_list_num))
        )
    {    
        mmi_popup_display(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_NO_AVAILABLE_AP)),
            MMI_EVENT_FAILURE, 
            NULL);
        mmi_frm_scrn_close (g_cui_wlan_gid, SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS);
        cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_CANCEL);
        return;
    }

    // Update scan result in the wlan app's context
    mmi_wlan_update_ap_list_after_scan(scan_res);
    
    if (mmi_frm_scrn_is_present(g_cui_wlan_gid, 
                                SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS,
                                MMI_FRM_NODE_ALL_FLAG))
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_CMCC_SHOW_AP_LIST_AFTER_SCAN, g_cui_wlan_gid);

        if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS)
        {
#ifdef __MMI_OP01_WIFI__            
            cui_wlan_cmcc_entry_wizard_list ();
#else
            cui_wlan_entry_new_wizard_list();
#endif
            mmi_frm_scrn_close (g_cui_wlan_gid, SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS);
        }
        else
        {
            new_node_info.id = SCR_ID_DTCNT_CUI_WLAN_LIST;
#ifdef __MMI_OP01_WIFI__            
            new_node_info.entry_proc = (mmi_proc_func)cui_wlan_cmcc_entry_wizard_list;
#else
            new_node_info.entry_proc = (mmi_proc_func)cui_wlan_entry_new_wizard_list;
#endif
            mmi_frm_scrn_replace (g_cui_wlan_gid, SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS, &new_node_info);
        }
    }
}

void cui_wlan_entry_scan_network_srcn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == mmi_frm_scrn_enter(
                        g_cui_wlan_gid, 
                        SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS,
                        NULL, 
                        cui_wlan_entry_scan_network_srcn, 
                        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    mmi_frm_scrn_set_leave_proc (
        g_cui_wlan_gid, 
        SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS, 
        cui_wlan_leave_callback);
    
    ShowCategory66Screen(
        STR_ID_DTCNT_WLAN_FIND_NETWORK,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_GLOBAL_SEARCHING),
        IMG_ID_DTCNT_WLAN_POPUP_SEARCH,
        NULL);
    
    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(cui_wlan_cancel_scan_job, KEY_EVENT_UP);
}

void cui_wlan_cancel_scan_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.scan_job_id > 0)
    {
        srv_dtcnt_wlan_scan_abort(g_wlan_display_context.scan_job_id);
        g_wlan_display_context.scan_job_id = 0;
        // Cancel the proc of create WLAN cui
        cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_CANCEL);
    }

    /* Refresh wifi icon on the top bar */
    mmi_wlan_set_status_bar_icon ();
    
    cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_CANCEL);
}

void cui_wlan_prepare_wizard_list(U8 *se_num, U8 *sa_num, U8 *se_sa_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i, j;
    MMI_BOOL is_matched;
    srv_dtcnt_wlan_status_enum wlan_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_status = srv_dtcnt_wlan_status();
    *se_num = 0;
    *sa_num = 0;
    *se_sa_num = 0;
    for (i = 0; i < g_wlan_display_context.ap_list_num; i++)
    {
        is_matched = MMI_FALSE;
        bssinfo_to_profile(&g_profile_saved_temp, &g_wlan_display_context.ap_list[i], NULL, 0);
        for (j = 0; j < g_wlan_display_context.prof_num; j++)
        {
            if ((g_wlan_profile[j]->ssid_len == g_profile_saved_temp.ssid_len) &&
                (strncmp((const char*)g_wlan_profile[j]->ssid, (const char*)g_profile_saved_temp.ssid, g_profile_saved_temp.ssid_len) == 0) &&
                (g_wlan_profile[j]->network_type == g_profile_saved_temp.network_type) &&
                (g_wlan_profile[j]->auth_mode == g_profile_saved_temp.auth_mode) &&
                (g_wlan_profile[j]->encrypt_mode == g_profile_saved_temp.encrypt_mode))
            {
                g_cui_wlan_cntx.prof_list[*se_sa_num].p_sa = g_wlan_profile[j];
                g_cui_wlan_cntx.prof_list[*se_sa_num].p_se = &g_wlan_display_context.ap_list[i];
                g_cui_wlan_cntx.prof_list[*se_sa_num].type = WLAN_MATCH_SE_SA;
                g_cui_wlan_cntx.prof_list[*se_sa_num].priority = j;
                g_wlan_profile[j]->is_search_matched = MMI_TRUE;
                is_matched = MMI_TRUE;
                wlan_status = srv_dtcnt_wlan_status();

                if (wlan_status == SRV_DTCNT_WLAN_STATUS_CONNECTED &&
                	g_wlan_display_context.connected_wlan_profile == g_wlan_profile[j])
                {
                	g_cui_wlan_cntx.prof_list[*se_sa_num].type = WLAN_MATCH_SE_SA_C;
                }
                (*se_sa_num)++;
            }
        }
        if (is_matched == MMI_FALSE)
        {
            g_cui_wlan_cntx.se_temp_list[*se_num].p_se = &g_wlan_display_context.ap_list[i];
            g_cui_wlan_cntx.se_temp_list[*se_num].p_sa = NULL;
            g_cui_wlan_cntx.se_temp_list[*se_num].type = WLAN_MATCH_SE;
            g_cui_wlan_cntx.se_temp_list[*se_num].priority = MAX_WLAN_DATA_ACCOUNT_NUM + 1;
            (*se_num)++;
        }
    }
    memcpy(&g_cui_wlan_cntx.prof_list[*se_sa_num], g_cui_wlan_cntx.se_temp_list, (*se_num) * sizeof(mmi_wlan_wizard_list_struct));
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if (!g_wlan_profile[i]->is_search_matched)
        {
           g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].p_se = NULL;
           g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].p_sa = g_wlan_profile[i];
           g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].type = WLAN_MATCH_SA;
           g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].priority = i;

           if (wlan_status == SRV_DTCNT_WLAN_STATUS_CONNECTED &&
               g_wlan_display_context.connected_wlan_profile == g_wlan_profile[i])
           {
               g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].type = WLAN_MATCH_SA_C;
           }
           (*sa_num)++;
        }
        else
        {
            g_wlan_profile[i]->is_search_matched = MMI_FALSE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_entry_new_wizard_list
 * DESCRIPTION
 *  Just test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_entry_new_wizard_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, ap_list_num, se_sa_num = 0, se_num = 0, sa_num = 0;
    U8 *guiBuffer = NULL;
    U16 icon_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 iconStates[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 left_key;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_wlan_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    g_cui_wlan_cntx.list_sa_num = sa_num;
    g_cui_wlan_cntx.list_se_num = se_num;
    g_cui_wlan_cntx.list_se_sa_num = se_sa_num;
    ap_list_num = se_num + sa_num + se_sa_num;
    for (i = 0; i < ap_list_num; i++)
    {
        memset(subMenuData[i], 0, MAX_SUB_MENU_SIZE);
        switch (g_cui_wlan_cntx.prof_list[i].type)
        {
            case WLAN_MATCH_SE_SA_C:
            case WLAN_MATCH_SE_SA:
            {
                mmi_ucs2cpy(
                    (CHAR*)subMenuData[i],
                    (const CHAR*)g_cui_wlan_cntx.prof_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                switch (g_cui_wlan_cntx.prof_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    default:
                        if (g_cui_wlan_cntx.prof_list[i].p_se->privacy > 0 ||
                            g_cui_wlan_cntx.prof_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_cui_wlan_cntx.prof_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        else
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        break;
                }
                if (g_cui_wlan_cntx.prof_list[i].type == WLAN_MATCH_SE_SA)
                {
                    if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -60)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -70)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -80)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL1;
                    }
                    else
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL0;
                    }
                }
                else 
                {
                    if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -60)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -70)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL2_CONNECTED;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -80)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL1_CONNECTED;
                    }
                    else
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL0_CONNECTED;
                    }                    
                }
                break;
            }
            case WLAN_MATCH_SE:
            {
               custom_wlan_ssid_convert(
                        (const char*) g_cui_wlan_cntx.prof_list[i].p_se->ssid, 
                        (char*) subMenuData[i], 
                        g_cui_wlan_cntx.prof_list[i].p_se->ssid_len);
               subMenuDataPtrs[i] = subMenuData[i];
               
                switch (g_cui_wlan_cntx.prof_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    default:
                        if (g_cui_wlan_cntx.prof_list[i].p_se->privacy > 0 ||
                            g_cui_wlan_cntx.prof_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_cui_wlan_cntx.prof_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        else
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        break;
                }
                if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -60)
                {
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                }
                else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -70)
                {
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                }
                else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -80)
                {
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL1;
                }
                else
                {
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL0;
                }
                break;
            }
            case WLAN_MATCH_SA:
            {
                mmi_ucs2cpy(
                    (CHAR*)subMenuData[i],
                    (const CHAR*)g_cui_wlan_cntx.prof_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                switch (g_cui_wlan_cntx.prof_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_cui_wlan_cntx.prof_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_cui_wlan_cntx.prof_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        else
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        break;
                }
                iconStates[i] = 0;
                break;
            }
            case WLAN_MATCH_SA_C:
                {
                mmi_ucs2cpy(
                    (CHAR*)subMenuData[i],
                    (const CHAR*)g_cui_wlan_cntx.prof_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                switch (g_cui_wlan_cntx.prof_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_cui_wlan_cntx.prof_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_cui_wlan_cntx.prof_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        else 
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        break;
                    }
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    break;
            } 
        }
 
    }

    if(!mmi_frm_scrn_enter(
        g_cui_wlan_gid, 
        SCR_ID_DTCNT_CUI_WLAN_LIST, 
        NULL, 
        cui_wlan_entry_new_wizard_list, 
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    RegisterHighlightHandler(cui_wlan_wizard_list_highlight_hdlr);
    
    g_wlan_ap_list_hilt_idx = 0;
    
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if (ap_list_num)
    {
        left_key = STR_GLOBAL_CONNECT;
    }
    else
    {
        left_key = 0;
    }

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_SCAN_RESULT,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        left_key,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ap_list_num,
        subMenuDataPtrs,
        (U16*) icon_list,
        iconStates,
        g_wlan_ap_list_hilt_idx,
        guiBuffer,
        ICON_TEXT_ICON);

    if (ap_list_num)
    {
        SetLeftSoftkeyFunction(cui_wlan_connect_ap, KEY_EVENT_UP);
        #ifndef __MMI_WGUI_DISABLE_CSK__
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(cui_wlan_connect_ap, KEY_EVENT_UP);
        #endif
    }
    
    SetRightSoftkeyFunction(cui_wlan_cancel, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_wizard_list_highlight_hdlr
 * DESCRIPTION
 *  Wizard profile list highlight handler
 * PARAMETERS
 *  nIndex
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_wizard_list_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cui_wlan_cntx.current_item_selected = nIndex;
    g_cui_wlan_cntx.list_option = g_cui_wlan_cntx.prof_list[nIndex].type;
    g_wlan_ap_list_hilt_idx = nIndex;
    
    if (g_cui_wlan_cntx.list_option == WLAN_MATCH_SA || 
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SE_SA ||
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SE_SA_C ||
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SA_C)
    {
        g_wlan_display_context.cui_saved_hilt_ap = g_cui_wlan_cntx.prof_list[nIndex].p_sa;
        g_wlan_display_context.search_connect_need_save = MMI_FALSE;
    }
    else if (g_cui_wlan_cntx.list_option == WLAN_MATCH_SE)
    {
        g_wlan_display_context.cui_search_hilt_ap= g_cui_wlan_cntx.prof_list[nIndex].p_se;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_refresh_ap_list_scrn
 * DESCRIPTION
 *  Account bearer list leave function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_refresh_ap_list_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8  i, ap_list_num, se_sa_num = 0, se_num = 0, sa_num = 0;
    U16 icon;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_wlan_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    ap_list_num = se_num + sa_num + se_sa_num;
    for (i = 0; i < ap_list_num; i++)
    {
        switch (g_cui_wlan_cntx.prof_list[i].type)
        {
            case WLAN_MATCH_SE_SA_C:
            case WLAN_MATCH_SE_SA:
            case WLAN_MATCH_SE:
            {
                if (g_cui_wlan_cntx.prof_list[i].type == WLAN_MATCH_SE_SA_C)
                {
                    if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -60)
                    {
                        icon = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -70)
                    {
                        icon = IMG_ID_DTCNT_WLAN_SIGNAL2_CONNECTED;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -80)
                    {
                        icon = IMG_ID_DTCNT_WLAN_SIGNAL1_CONNECTED;
                    }
                    else
                    {
                        icon = IMG_ID_DTCNT_WLAN_SIGNAL0_CONNECTED;
                    }                    
                    
                }
                else 
                {
                    if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -60)
                    {
                        icon = IMG_ID_DTCNT_WLAN_SIGNAL3;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -70)
                    {
                        icon = IMG_ID_DTCNT_WLAN_SIGNAL2;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -80)
                    {
                        icon = IMG_ID_DTCNT_WLAN_SIGNAL1;
                    }
                    else
                    {
                        icon = IMG_ID_DTCNT_WLAN_SIGNAL0;
                    }
                }
                break;
                }
            case WLAN_MATCH_SA_C:
            {
                icon = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                break;
            } 
            default:
                icon = 0;
                break;
        }
    
        Category73ChangeItemIcon(i, 1, get_image(icon));
    }

    Category73RedrawScreen();
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_connect_ap
 * DESCRIPTION
 *  Connect to one access point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_connect_ap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // srv_dtcnt_wlan_status_enum wlan_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.pre_connect_by_always_ask = MMI_FALSE;
    
    if (g_cui_wlan_cntx.list_option == WLAN_MATCH_SA || 
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SE_SA ||
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SE_SA_C ||
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SA_C)

    {
        MMI_TRACE(TRACE_GROUP_6, CUI_WLAN_CMCC_AP_LIST_BEFORE_CONNECT, 
            g_cui_wlan_cntx.list_option,
            g_wlan_display_context.cui_saved_hilt_ap->ssid_len,
            g_wlan_display_context.cui_saved_hilt_ap->profile_id);
        /* always_ask_connect_flag mark this connection is triggered by always ask */
        g_wlan_display_context.cui_saved_hilt_ap->always_ask_connect_flag = MMI_TRUE;
        g_wlan_display_context.search_connect_need_save = MMI_FALSE;
        cui_wlan_connect_app_prof(g_wlan_display_context.cui_saved_hilt_ap);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_CONNECT_SAVED);
    }
    else if (g_cui_wlan_cntx.list_option == WLAN_MATCH_SE)
    {
        MMI_TRACE(TRACE_GROUP_6, CUI_WLAN_CMCC_AP_LIST_BEFORE_CONNECT, 
            g_cui_wlan_cntx.list_option,
            g_wlan_display_context.cui_search_hilt_ap->ssid_len,
            0);
        cui_wlan_connect_search_ap();
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_CONNECT_SEARCH);
    }
}

void cui_wlan_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_CANCEL);
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_connect_app_prof
 * DESCRIPTION
 *  To connect one access point
 * PARAMETERS
 *  app_prof
 * RETURNS
 *  srv_dtcnt_result_enum
 *****************************************************************************/
void cui_wlan_pre_connect_ap(const char* passphrase, U32 keylen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    mmi_wlan_profile_struct *profile;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    profile = &g_wlan_display_context.temp_profile;
    memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
    
    bssinfo_to_profile(profile, &g_cui_hilt_profile, passphrase, keylen);
    mmi_wlan_save_default_eap_to_profile(profile);

    profile->always_ask_connect_flag = MMI_TRUE;
    cui_wlan_connect_app_prof(profile);
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_connect_app_prof
 * DESCRIPTION
 *  To connect one access point
 * PARAMETERS
 *  app_prof
 * RETURNS
 *  srv_dtcnt_result_enum
 *****************************************************************************/
srv_dtcnt_result_enum cui_wlan_connect_app_prof(mmi_wlan_profile_struct *app_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum retn;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_CONNECT_BY_CUI);
    
    retn = mmi_wlan_send_connect_request(app_prof);

    cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_CONNECT);
    
    return retn;
}

void cui_wlan_connect_search_ap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // srv_dtcnt_wlan_status_enum  wlan_status;
    mmi_wlan_profile_struct*    prof;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_wlan_display_context.cui_search_hilt_ap)
    {
        // Save the highlight search ap into temp structure
        // Avoid cui_search_hilt_ap been modified unexpectedly
        memcpy(&g_cui_hilt_profile, g_wlan_display_context.cui_search_hilt_ap, sizeof(supc_abm_bss_info_struct));
        if (g_cui_hilt_profile.network_type == WNDRV_SUPC_NETWORK_IBSS 
			&& g_cui_hilt_profile.privacy > 0 &&
			(g_cui_hilt_profile.rsn_ie_info_p == TRUE ||
			g_cui_hilt_profile.wpa_ie_info_p == TRUE) &&
			g_wlan_display_context.active_ap->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
        {
            mmi_popup_display_simple(
                    (WCHAR*)GetString(STR_GLOBAL_NOT_SUPPORTED),
                    MMI_EVENT_FAILURE,
                    g_cui_wlan_gid,
                    NULL);
			return;
        }
        g_wlan_display_context.search_connect_need_save = MMI_TRUE;
        if (g_cui_hilt_profile.rsn_ie_info_p == TRUE)
        {
            if (g_cui_hilt_profile.rsn_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 1);
                g_dtcnt_is_WEP_key = 0;
                g_wlan_display_context.pass_len = SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN;
                cui_wlan_entry_edit_passphrase_scrn();
                return;
            }
            /* default eap type is EAP-PEAP + EAP-MSCHAPV2 */
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 2);
                cui_wlan_entry_edit_identity_scrn();
            }
        }
        else if (g_cui_hilt_profile.wpa_ie_info_p == TRUE)
        {
            if (g_cui_hilt_profile.wpa_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 3);
                g_dtcnt_is_WEP_key = 0;
                g_wlan_display_context.pass_len = SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN;
                cui_wlan_entry_edit_passphrase_scrn();
                return;
            }
            /* default eap type is EAP-PEAP + EAP-MSCHAPV2 */
            else if (g_cui_hilt_profile.wpa_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_WPA_NONE)
            {
                /*mmi_popup_display_simple(
                    (WCHAR*)GetString(STR_ID_DTCNT_WLAN_ERROR_DEFINE_NETWORK_FIRST),
                    MMI_EVENT_FAILURE,
                    g_cui_wlan_gid,
                    NULL);*/
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 5);
                g_dtcnt_is_WEP_key = 0;
                g_wlan_display_context.pass_len = SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN;
                cui_wlan_entry_edit_passphrase_scrn();
                return;
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 4);
                cui_wlan_entry_edit_identity_scrn();
            }    
        }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        else if (TRUE == g_cui_hilt_profile.wapi_ie_info_p)
        {
            if (g_cui_hilt_profile.wapi_ie_info.key_mgmt == WAPI_KEY_MGMT_PSK)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 5);
                g_dtcnt_is_WEP_key = 0; 
                cui_wlan_entry_wapi_psk_scrn();
                return;
            }
            else if (g_cui_hilt_profile.wapi_ie_info.key_mgmt == MMI_WLAN_WAPI_KEY_MGMT_WAI)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 6);
                g_dtcnt_is_WEP_key = 0; 
                cui_wlan_entry_wapi_cert_scrn();
                return;
            }
        }
#endif /* __MMI_HIDE_WAPI__ */
#endif
        else if (g_cui_hilt_profile.privacy > 0)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 7);
            g_dtcnt_is_WEP_key = 1;
            g_wlan_display_context.pass_len = 26;
            cui_wlan_entry_edit_passphrase_scrn();
            return;
        }
        else /* No security method is applied */
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PRE_CONNECT, 8);
            prof = &g_wlan_display_context.temp_profile;
            memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
            bssinfo_to_profile(prof, &g_cui_hilt_profile, NULL, 0);
            prof->always_ask_connect_flag = MMI_TRUE;
            cui_wlan_connect_app_prof(prof);
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_connect_ap_with_passphrase
 * DESCRIPTION
 *  Connect to AP with auth. mode is WPA/WPA2-Enterprise or WEP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_connect_ap_with_passphrase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buf[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1] = "";
    char passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1] = "";
    U32  keylen = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_INPUT_DONE_CONN, 200);

    mmi_ucs2_to_asc((CHAR *)buf, (CHAR *)g_wlan_display_context.cui_passphrase_str);
    
    if ((g_cui_hilt_profile.rsn_ie_info_p == KAL_TRUE && 
         g_cui_hilt_profile.rsn_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK) ||
        (g_cui_hilt_profile.wpa_ie_info_p == KAL_TRUE && 
         g_cui_hilt_profile.wpa_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK))
    {
        if (strlen(buf) < 8)
        {
            cui_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE);
            return;
        }
        keylen = strlen(buf);
        strcpy(passphrase, buf);
    }
    else if (g_cui_hilt_profile.privacy > 0 && 
             g_cui_hilt_profile.rsn_ie_info_p == KAL_FALSE &&
             g_cui_hilt_profile.wpa_ie_info_p == KAL_FALSE)
    {
        keylen = strlen(buf);
        // Verify whether it is a valid wep key
        if(FALSE == is_valid_ascii_string((U8*)buf, keylen))
        {   
            cui_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY);
            return;
        }
        
        switch (strlen(buf))
        {
            case 5:
            case 13:
                strcpy(passphrase, buf);
                break;
            case 10:
            {
                if (mmi_wlan_hex_to_string((U8 *)passphrase, (U8 *)buf, 10) == FALSE)
                {
                    cui_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY);
                    return;
                }
                keylen = 5;
                break;
            }
            case 26:
            {
                if (mmi_wlan_hex_to_string((U8 *)passphrase, (U8 *)buf, 26) == FALSE)
                {
                    cui_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY);
                    return;
                }
                keylen = 13;
                break;
            }
            default:
            {
                cui_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY);
                return;
            }
        }
    }
    // Save wep key into cntx in order to show it in edit screen
    // It should be the same as user input
    strcpy((char*)g_wlan_display_context.psk, buf);
    g_wlan_display_context.keylen = strlen(buf);
    
    cui_fseditor_close (g_cui_wlan_cntx.passphrase_editor_id);
    cui_wlan_pre_connect_ap (passphrase, keylen);
}

void cui_wlan_invalid_passphrase_popup(U16 prompt)
{
    mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(prompt)), 
            MMI_EVENT_FAILURE, 
            g_cui_wlan_gid,
            NULL);
    // mmi_ime_delete_editor_common_scr(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);
    g_wlan_display_context.is_key_input_invalid = 1;
    mmi_frm_scrn_close(g_cui_wlan_gid, SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);
    mmi_frm_scrn_close(g_cui_wlan_gid, SCR_ID_DTCNT_WLAN_WIZARD_EAP_INPUT);
    
    memset(g_wlan_display_context.cui_passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
    cui_fseditor_set_text(
        g_cui_wlan_cntx.passphrase_editor_id, 
        (WCHAR*) g_wlan_display_context.cui_passphrase_str, 
        (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH, 
        g_wlan_display_context.pass_len);
}

MMI_BOOL cui_wlan_verify_wapi_pre_shared_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_valid = MMI_FALSE;
    S32 length;
    U8  wapi_wep_key[MAX_WAPI_PSK_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen((const CHAR *)g_wlan_display_context.wapi_psk_str);
    memset (wapi_wep_key, 0, MAX_WAPI_PSK_LEN + 1);
    mmi_ucs2_n_to_asc((CHAR*)wapi_wep_key, (CHAR*)g_wlan_display_context.wapi_psk_str, length * ENCODING_LENGTH);
    
    if (g_wlan_display_context.wapi_psk_format == 0)
    {
        if (is_valid_hexstring(wapi_wep_key, length))
        {
            is_valid = MMI_TRUE;
        }
    }
    else if(g_wlan_display_context.wapi_psk_format == 1)
    {
        if (is_valid_ascii_string(wapi_wep_key, length))
        {
            is_valid = MMI_TRUE;
        }
    }

    return is_valid;
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_entry_edit_passphrase_scrn
 * DESCRIPTION
 *  Entry screen for user to input psk or wep key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_entry_edit_passphrase_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_PASSPHRASE_INPUT);
    g_cui_wlan_cntx.passphrase_editor_id = cui_fseditor_create(g_cui_wlan_gid);

    if (g_cui_wlan_cntx.passphrase_editor_id != 0)
    {
        if (g_dtcnt_is_WEP_key)
        {
            cui_fseditor_set_title(
                g_cui_wlan_cntx.passphrase_editor_id, 
                STR_ID_DTCNT_WLAN_WEP_KEY, 
                GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
        }
        else
        {
            cui_fseditor_set_title(
                g_cui_wlan_cntx.passphrase_editor_id, 
                STR_ID_DTCNT_WLAN_WPA_PASSPHRASE, 
                GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
        }

        memset(g_wlan_display_context.cui_passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
        cui_fseditor_set_text(
            g_cui_wlan_cntx.passphrase_editor_id, 
            (WCHAR*) g_wlan_display_context.cui_passphrase_str, 
            (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH, 
            g_wlan_display_context.pass_len);
        cui_fseditor_set_input_method(
            g_cui_wlan_cntx.passphrase_editor_id, 
            IMM_INPUT_TYPE_ASCII_PASSWORD, 
            NULL, 
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        
        cui_fseditor_run(g_cui_wlan_cntx.passphrase_editor_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_entry_edit_identity_scrn
 * DESCRIPTION
 *  To ask user to input user name & password
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_entry_edit_identity_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U16 inline_icon_list[CUI_WLAN_USER_INFO_INLINE_TOTAL] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0};
    U16 title_id;
    cui_inline_item_caption_struct user_info_user_name_caption;
    cui_inline_item_fullscreen_edit_struct user_info_user_name_full_editor;
    cui_inline_item_caption_struct user_info_password_caption;
    cui_inline_item_fullscreen_edit_struct user_info_password_full_editor;
    cui_inline_set_item_struct user_info_inline_items[CUI_WLAN_USER_INFO_INLINE_TOTAL];
    cui_inline_struct user_info_inline_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_DEFAULT_EAP_INPUT);

    title_id = STR_ID_DTCNT_WLAN_USER_INFO;
    
    user_info_user_name_caption.string_id = STR_GLOBAL_USERNAME;
    
    user_info_user_name_full_editor.string_id = 0;
    user_info_user_name_full_editor.default_text_id = 0;
    user_info_user_name_full_editor.title = STR_GLOBAL_USERNAME;
    user_info_user_name_full_editor.title_icon = GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID);   
    user_info_user_name_full_editor.input_type = IMM_INPUT_TYPE_ASCII_CHAR;
    user_info_user_name_full_editor.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    user_info_user_name_full_editor.buffer_size = MAX_USERNAME_LEN;  
    user_info_user_name_full_editor.required_input_mode_set = NULL;
    
    user_info_password_caption.string_id = STR_GLOBAL_PASSWORD;
    
    user_info_password_full_editor.string_id = 0;
    user_info_password_full_editor.default_text_id = 0;
    user_info_password_full_editor.title = STR_GLOBAL_PASSWORD;
    user_info_password_full_editor.title_icon = GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID);   
    user_info_password_full_editor.input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    user_info_password_full_editor.buffer_size = MAX_PASSWORD_LEN;  
    user_info_password_full_editor.required_input_mode_set = NULL;
    
    user_info_inline_items[CUI_WLAN_USER_INFO_USERNAME_STR].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_USER_INFO_USERNAME_STR;
    user_info_inline_items[CUI_WLAN_USER_INFO_USERNAME_STR].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    user_info_inline_items[CUI_WLAN_USER_INFO_USERNAME_STR].image_id = inline_icon_list[CUI_WLAN_USER_INFO_USERNAME_STR];
    user_info_inline_items[CUI_WLAN_USER_INFO_USERNAME_STR].item_data = &user_info_user_name_caption;
    
    user_info_inline_items[CUI_WLAN_USER_INFO_USERNAME].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_USER_INFO_USERNAME;
    user_info_inline_items[CUI_WLAN_USER_INFO_USERNAME].item_flag = CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT;
    user_info_inline_items[CUI_WLAN_USER_INFO_USERNAME].image_id = inline_icon_list[CUI_WLAN_USER_INFO_USERNAME];
    user_info_inline_items[CUI_WLAN_USER_INFO_USERNAME].item_data = &user_info_user_name_full_editor;
    
    user_info_inline_items[CUI_WLAN_USER_INFO_PASSWORD_STR].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_USER_INFO_PASSWORD_STR;
    user_info_inline_items[CUI_WLAN_USER_INFO_PASSWORD_STR].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    user_info_inline_items[CUI_WLAN_USER_INFO_PASSWORD_STR].image_id = inline_icon_list[CUI_WLAN_USER_INFO_PASSWORD_STR];
    user_info_inline_items[CUI_WLAN_USER_INFO_PASSWORD_STR].item_data = &user_info_password_caption;
    	
    user_info_inline_items[CUI_WLAN_USER_INFO_PASSWORD].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_USER_INFO_PASSWORD;
    user_info_inline_items[CUI_WLAN_USER_INFO_PASSWORD].item_flag = CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT;
    user_info_inline_items[CUI_WLAN_USER_INFO_PASSWORD].image_id = inline_icon_list[CUI_WLAN_USER_INFO_PASSWORD];
    user_info_inline_items[CUI_WLAN_USER_INFO_PASSWORD].item_data = &user_info_password_full_editor;

    user_info_inline_struct.items_count = CUI_WLAN_USER_INFO_INLINE_TOTAL;
    user_info_inline_struct.title = title_id;
    user_info_inline_struct.title_icon = GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID);
    user_info_inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    user_info_inline_struct.softkey = NULL;
    user_info_inline_struct.items = user_info_inline_items;
    
    g_cui_wlan_cntx.eap_inline_cui_id = cui_inline_create(
                                 g_cui_wlan_gid,
                                 &user_info_inline_struct);

    memset(g_wlan_display_context.username_str, 0, MAX_USERNAME_LEN * ENCODING_LENGTH);
    memset(g_wlan_display_context.password_str, 0, MAX_PASSWORD_LEN * ENCODING_LENGTH);
    
    cui_inline_set_value(g_cui_wlan_cntx.eap_inline_cui_id, 
                        CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_USER_INFO_USERNAME, 
                        g_wlan_display_context.username_str); 

    cui_inline_set_value(g_cui_wlan_cntx.eap_inline_cui_id, 
                    CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_USER_INFO_PASSWORD, 
                    g_wlan_display_context.password_str); 

    cui_inline_run(g_cui_wlan_cntx.eap_inline_cui_id);
}

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
/*****************************************************************************
 * FUNCTION
 *  cui_wlan_entry_wapi_psk_scrn
 * DESCRIPTION
 *  To enter WAPI psk settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_entry_wapi_psk_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inline_icon_list[CUI_WLAN_WAPI_PSK_EDIT_INLINE_TOTAL] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0};
    U16 title_id;
    cui_inline_item_caption_struct wapi_psk_key_format_caption;
    cui_inline_item_select_struct wapi_psk_key_format_selection;
    cui_inline_item_caption_struct wapi_psk_key_caption;
    cui_inline_item_fullscreen_edit_struct wapi_psk_key_full_editor;
    cui_inline_set_item_struct wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_INLINE_TOTAL];
    cui_inline_struct wapi_psk_inline_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.wapi_psk_format = 0;
    memset(g_wlan_display_context.wapi_psk_str, 0, (31 + 1) * ENCODING_LENGTH);
    
    title_id = STR_ID_DTCNT_WLAN_WAPI_PSK_SETTINGS;
    g_wlan_display_context.wapi_psk_format_opt[0] = STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_HEX;
    g_wlan_display_context.wapi_psk_format_opt[1] = STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII;

    wapi_psk_key_format_caption.string_id = STR_ID_DTCNT_WLAN_WAPI_PSK_FORMAT;

    wapi_psk_key_format_selection.highlighted_item = g_wlan_display_context.wapi_psk_format;
    wapi_psk_key_format_selection.list_of_item_id = (U16 *)g_wlan_display_context.wapi_psk_format_opt;
    wapi_psk_key_format_selection.n_items = WLAN_WEP_KEY_FORMAT_TOTAL;

    wapi_psk_key_caption.string_id = STR_ID_DTCNT_WLAN_WAPI_PSK;

    wapi_psk_key_full_editor.string_id = 0;
    wapi_psk_key_full_editor.default_text_id = 0;
    wapi_psk_key_full_editor.title = STR_ID_DTCNT_WLAN_WAPI_PSK;
    wapi_psk_key_full_editor.title_icon = GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID);   
    wapi_psk_key_full_editor.input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    wapi_psk_key_full_editor.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    wapi_psk_key_full_editor.buffer_size = MAX_WAPI_PSK_LEN + 1;  
    wapi_psk_key_full_editor.required_input_mode_set = NULL;

    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT_STR].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT_STR;
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT_STR].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT_STR].image_id = inline_icon_list[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT_STR];
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT_STR].item_data = &wapi_psk_key_format_caption;

    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT;
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT].image_id = inline_icon_list[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT];
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT].item_data = &wapi_psk_key_format_selection;
    
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_STR].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_PSK_EDIT_KEY_STR;
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_STR].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_STR].image_id = inline_icon_list[CUI_WLAN_WAPI_PSK_EDIT_KEY_STR];
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY_STR].item_data = &wapi_psk_key_caption;

    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_PSK_EDIT_KEY;
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY].item_flag = CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT;
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY].image_id = inline_icon_list[CUI_WLAN_WAPI_PSK_EDIT_KEY];
    wapi_psk_inline_items[CUI_WLAN_WAPI_PSK_EDIT_KEY].item_data = &wapi_psk_key_full_editor;

    wapi_psk_inline_struct.items_count = CUI_WLAN_WAPI_PSK_EDIT_INLINE_TOTAL;
    wapi_psk_inline_struct.title = title_id;
    wapi_psk_inline_struct.title_icon = GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID);
    wapi_psk_inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    wapi_psk_inline_struct.softkey = NULL;
    wapi_psk_inline_struct.items = wapi_psk_inline_items;
    
    g_cui_wlan_cntx.wapi_psk_inline_cui_id = cui_inline_create(
                                 g_cui_wlan_gid,
                                 &wapi_psk_inline_struct);
    
    cui_inline_set_value(
        g_cui_wlan_cntx.wapi_psk_inline_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_PSK_EDIT_KEY, 
        g_wlan_display_context.wapi_psk_str);
    
    cui_inline_run(g_cui_wlan_cntx.wapi_psk_inline_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_wlan_entry_wapi_cert_scrn
 * DESCRIPTION
 *  To enter WAPI cert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_entry_wapi_cert_scrn(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inline_icon_list[CUI_WLAN_WAPI_EDIT_INLINE_TOTAL] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0, IMG_GLOBAL_L3, 0};
    U16 title_id;
    cui_inline_item_caption_struct wapi_cert_ase_caption;
    cui_inline_item_display_only_struct wapi_cert_ase_disp;
    cui_inline_item_caption_struct wapi_cert_user_caption;
    cui_inline_item_display_only_struct wapi_cert_user_disp;
    cui_inline_item_caption_struct wapi_cert_key_caption;
    cui_inline_item_fullscreen_edit_struct wapi_cert_key_full_editor;
    cui_inline_set_item_struct wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_INLINE_TOTAL];
    cui_inline_struct wapi_cert_inline_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.wapi_ase_id = 0;
    g_wlan_display_context.wapi_client_id = 0;
    memset(g_wlan_display_context.wapi_ase_name, 0, (MAX_USERNAME_LEN + 1) * ENCODING_LENGTH);
    memset(g_wlan_display_context.wapi_client_name, 0, (MAX_USERNAME_LEN + 1) * ENCODING_LENGTH);
    memset(g_wlan_display_context.wapi_private_key_passwd_str, 0, (MAX_PASSWORD_LEN + 1) * ENCODING_LENGTH);
    
    title_id = STR_ID_DTCNT_WLAN_WAPI_CERT_SETTINGS; 
    wapi_cert_ase_caption.string_id = STR_ID_DTCNT_WLAN_WAPI_ASE_CERT;

    wapi_cert_ase_disp.string_id = 0;

    wapi_cert_user_caption.string_id = STR_ID_DTCNT_WLAN_WAPI_USER_CERT;
    wapi_cert_user_disp.string_id = 0;

    wapi_cert_key_caption.string_id = STR_ID_DTCNT_WLAN_WAPI_PRIV_KEY_PASSWD;
    wapi_cert_key_full_editor.default_text_id = 0;
    wapi_cert_key_full_editor.title = STR_ID_DTCNT_WLAN_WAPI_PRIV_KEY_PASSWD;
    wapi_cert_key_full_editor.title_icon = GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID);   
    wapi_cert_key_full_editor.input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    wapi_cert_key_full_editor.buffer_size = MAX_PASSWORD_LEN;  
    wapi_cert_key_full_editor.required_input_mode_set = NULL;

    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_ASE_CERT_STR].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_ASE_CERT_STR;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_ASE_CERT_STR].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_ASE_CERT_STR].image_id = inline_icon_list[CUI_WLAN_WAPI_EDIT_ASE_CERT_STR];
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_ASE_CERT_STR].item_data = &wapi_cert_ase_caption;

    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_ASE_CERT].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_ASE_CERT;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_ASE_CERT].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_ASE_CERT].image_id = inline_icon_list[CUI_WLAN_WAPI_EDIT_ASE_CERT];
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_ASE_CERT].item_data = &wapi_cert_ase_disp;
	
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_USER_CERT_STR].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_USER_CERT_STR;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_USER_CERT_STR].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_USER_CERT_STR].image_id = inline_icon_list[CUI_WLAN_WAPI_EDIT_USER_CERT_STR];
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_USER_CERT_STR].item_data = &wapi_cert_user_caption;
    	
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_USER_CERT].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_USER_CERT;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_USER_CERT].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_USER_CERT].image_id = inline_icon_list[CUI_WLAN_WAPI_EDIT_USER_CERT];
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_USER_CERT].item_data = &wapi_cert_user_disp;

    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD_STR].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD_STR;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD_STR].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD_STR].image_id = inline_icon_list[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD_STR];
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD_STR].item_data = &wapi_cert_key_caption;
    	
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD].item_id = CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD].item_flag = CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT;
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD].image_id = inline_icon_list[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD];
    wapi_cert_inline_items[CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD].item_data = &wapi_cert_key_full_editor;

    wapi_cert_inline_struct.items_count = CUI_WLAN_WAPI_EDIT_INLINE_TOTAL;
    wapi_cert_inline_struct.title = title_id;
    wapi_cert_inline_struct.title_icon = GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID);
    wapi_cert_inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    wapi_cert_inline_struct.softkey = NULL;
    wapi_cert_inline_struct.items = wapi_cert_inline_items;

    g_cui_wlan_cntx.wapi_cert_inline_cui_id = cui_inline_create(
                                 g_cui_wlan_gid,
                                 &wapi_cert_inline_struct);

#ifdef __CERTMAN_SUPPORT__
    if (mmi_ucs2strlen(g_wlan_display_context.wapi_ase_name) > 0)
    {
        cui_inline_set_value(g_cui_wlan_cntx.wapi_cert_inline_cui_id, CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_ASE_CERT, g_wlan_display_context.wapi_ase_name); 
    }
    else
    {
        cui_inline_set_value(g_cui_wlan_cntx.wapi_cert_inline_cui_id, CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_ASE_CERT, GetString(STR_GLOBAL_NONE)); 
    }
    
    if (mmi_ucs2strlen(g_wlan_display_context.wapi_client_name) > 0)
    {
        cui_inline_set_value(g_cui_wlan_cntx.wapi_cert_inline_cui_id, CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_USER_CERT, g_wlan_display_context.wapi_client_name); 
    }
    else
    {
        cui_inline_set_value(g_cui_wlan_cntx.wapi_cert_inline_cui_id, CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_USER_CERT, GetString(STR_GLOBAL_NONE)); 
    }
#endif /* __CERTMAN_SUPPORT__ */

    cui_inline_set_value(
        g_cui_wlan_cntx.wapi_cert_inline_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD, 
        g_wlan_display_context.wapi_private_key_passwd_str);

    cui_inline_run(g_cui_wlan_cntx.wapi_cert_inline_cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_connect_ap_with_wapi
 * DESCRIPTION
 *  Connect to ap with WAPI auth. mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_connect_ap_with_wapi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    mmi_wlan_profile_struct *profile;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    profile = &g_wlan_display_context.temp_profile;
    memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
    bssinfo_to_profile(profile, &g_cui_hilt_profile, NULL, 0);
    
#ifdef __CERTMAN_SUPPORT__
    if (profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT)
    {
        profile->wapi_ase_id = g_wlan_display_context.wapi_ase_id;
        profile->wapi_client_id = g_wlan_display_context.wapi_client_id;
        mmi_ucs2_to_asc((CHAR *)profile->wapi_private_key_passwd_str, (CHAR *)g_wlan_display_context.wapi_private_key_passwd_str);
    }
#endif

    if (profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK)
    {
        mmi_ucs2_to_asc((CHAR *)profile->wapi_psk_str, (CHAR *)g_wlan_display_context.wapi_psk_str);
        profile->wapi_psk_format = g_wlan_display_context.wapi_psk_format;
    }
    
    profile->always_ask_connect_flag = MMI_TRUE;
    cui_wlan_connect_app_prof(profile);
}
#endif /* __MMI_HIDE_WAPI__ */
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_connect_event_hdlr
 * DESCRIPTION
 *  function to handle the scan confirm.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_connect_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_disconnect_event_hdlr
 * DESCRIPTION
 *  function to handle the scan confirm.
 * PARAMETERS
 *  param :      [IN]  event parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void cui_wlan_disconnect_event_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Receive disc event when invoking wlan cui, refresh ap list */
    cui_wlan_refresh_ap_list_scrn();
}

void cui_wlan_fseditor_submit_evt_hdlr(mmi_event_struct *evt)
{
    /* Handler when user confirm input */
    cui_fseditor_get_text(
        g_cui_wlan_cntx.passphrase_editor_id, 
        (WCHAR*) g_wlan_display_context.cui_passphrase_str, 
        (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
    cui_wlan_connect_ap_with_passphrase();
}

void cui_wlan_fseditor_abort_evt_hdlr(mmi_event_struct *evt)
{
    cui_fseditor_evt_struct *fs_editor_event;
    
    /* Handler when user Cancel input */
    fs_editor_event = (cui_fseditor_evt_struct*)evt;
    cui_fseditor_close(fs_editor_event->sender_id);
}

void cui_wlan_inline_set_key_evt_hdlr(mmi_event_struct *evt)
{
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    cui_event_inline_set_key_struct *inline_setkey_event;
    
    inline_setkey_event = (cui_event_inline_set_key_struct*)evt;
    if(inline_setkey_event->sender_id == g_cui_wlan_cntx.wapi_cert_inline_cui_id)
    {
        if(CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_ASE_CERT == inline_setkey_event->item_id)
        {
            cui_inline_set_softkey_text(g_cui_wlan_cntx.wapi_cert_inline_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_ASE_CERT), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_wapi_entry_ASE_cert_list);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_wapi_entry_ASE_cert_list, KEY_EVENT_UP);
        }
        else if(CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_USER_CERT == inline_setkey_event->item_id)
        {
            cui_inline_set_softkey_text(g_cui_wlan_cntx.wapi_cert_inline_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_USER_CERT), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_wapi_entry_user_cert_list);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_wapi_entry_user_cert_list, KEY_EVENT_UP);
        }
    }
#endif /* __MMI_HIDE_WAPI__ */
#endif
}

void cui_wlan_inline_submit_evt_hdlr(mmi_event_struct *evt)
{
    cui_event_inline_submit_struct *inline_submit_event;
    
    inline_submit_event = (cui_event_inline_submit_struct*)evt;

    if (inline_submit_event->sender_id == g_cui_wlan_cntx.eap_inline_cui_id)
    {
        cui_inline_get_value(
            inline_submit_event->sender_id, 
            CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_USER_INFO_USERNAME, 
            g_wlan_display_context.username_str);
        cui_inline_get_value(
            inline_submit_event->sender_id, 
            CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_USER_INFO_PASSWORD, 
            g_wlan_display_context.password_str);
        
		mmi_wlan_close_inline_cui(&inline_submit_event->sender_id);
        mmi_wlan_save_default_eap_to_display_cntx();
        cui_wlan_pre_connect_ap (NULL, 0);
    }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    else if (inline_submit_event->sender_id == g_cui_wlan_cntx.wapi_psk_inline_cui_id)
    {
        cui_inline_get_value(
            inline_submit_event->sender_id, 
            CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_PSK_EDIT_KEY, 
            g_wlan_display_context.wapi_psk_str);
        
        if(MMI_FALSE == cui_wlan_verify_wapi_pre_shared_key())
        {
            mmi_popup_display_simple(
                (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE)), 
                MMI_EVENT_FAILURE, 
                g_cui_wlan_gid, 
                NULL);
            
            memset(g_wlan_display_context.wapi_psk_str, 0, (31 + 1) * ENCODING_LENGTH);
            cui_inline_set_value(
                g_cui_wlan_cntx.wapi_psk_inline_cui_id,
                CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_PSK_EDIT_KEY, 
                g_wlan_display_context.wapi_psk_str);

            cui_inline_set_screen_attributes(
                g_cui_wlan_cntx.wapi_psk_inline_cui_id, 
                CUI_INLINE_RESET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);

        }
        else
        {
            mmi_wlan_close_inline_cui(&inline_submit_event->sender_id);
            cui_wlan_connect_ap_with_wapi();
        }
    }

    else if (inline_submit_event->sender_id == g_cui_wlan_cntx.wapi_cert_inline_cui_id)
    {
        cui_inline_get_value(
                inline_submit_event->sender_id, 
                CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD, 
                g_wlan_display_context.wapi_private_key_passwd_str);

		mmi_wlan_close_inline_cui(&inline_submit_event->sender_id);
        cui_wlan_connect_ap_with_wapi();
    }
#endif /* __MMI_HIDE_WAPI__ */
#endif    
}

void cui_wlan_inline_screen_active_evt_hdlr(mmi_event_struct *evt)
{
    cui_event_inline_common_struct *inline_common_event;
    
    inline_common_event = (cui_event_inline_common_struct*)evt;
    if (inline_common_event->sender_id == g_cui_wlan_cntx.wapi_cert_inline_cui_id)
    {
        /* refresh */
        if (0 != g_wlan_display_context.wapi_ase_id &&
            mmi_ucs2strlen(g_wlan_display_context.wapi_ase_name) > 0)
        {
            cui_inline_set_value(
                inline_common_event->sender_id, 
                CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_ASE_CERT, 
                (PU8)g_wlan_display_context.wapi_ase_name); 
        }
        else
        {
            cui_inline_set_value(
                inline_common_event->sender_id, 
                CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_ASE_CERT, 
                (PU8)GetString(STR_GLOBAL_NONE)); 
        }

        if (0 != g_wlan_display_context.wapi_client_id &&
            mmi_ucs2strlen(g_wlan_display_context.wapi_client_name) > 0)
        {
            cui_inline_set_value(
                inline_common_event->sender_id, 
                CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_USER_CERT, 
                (PU8)g_wlan_display_context.wapi_client_name); 
        }
        else
        {
            cui_inline_set_value(
                inline_common_event->sender_id, 
                CUI_INLINE_ITEM_ID_BASE + CUI_WLAN_WAPI_EDIT_USER_CERT, 
                (PU8)GetString(STR_GLOBAL_NONE)); 
        }

        if (g_wlan_display_context.wapi_is_cert_changed)
        {
            g_wlan_display_context.wapi_is_cert_changed = MMI_FALSE;
            cui_inline_set_screen_attributes(inline_common_event->sender_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
        }    
    }    
}

void cui_wlan_inline_notify_evt_hdlr(mmi_event_struct *evt)
{
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    cui_event_inline_notify_struct *inline_notify_event;

    inline_notify_event = (cui_event_inline_notify_struct*)evt;
    if (inline_notify_event->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM 
        && (inline_notify_event->item_id == CUI_WLAN_WAPI_EDIT_ASE_CERT || inline_notify_event->item_id == CUI_WLAN_WAPI_EDIT_USER_CERT))
    {
        cui_inline_set_item_attributes(inline_notify_event->sender_id, CUI_WLAN_WAPI_EDIT_ASE_CERT, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_DISABLE_DONE);
        cui_inline_set_item_attributes(inline_notify_event->sender_id, CUI_WLAN_WAPI_EDIT_USER_CERT, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_DISABLE_DONE);
    }
    else if(inline_notify_event->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED
        && inline_notify_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_FORMAT)
    {
        g_wlan_display_context.wapi_psk_format = inline_notify_event->param;                
    }
#endif /* __MMI_HIDE_WAPI__ */
#endif
}

void cui_wlan_inline_abort_evt_hdlr(mmi_event_struct *evt)
{
    cui_event_inline_abort_struct *inline_abort_event;
    
    inline_abort_event = (cui_event_inline_abort_struct*)evt;
	mmi_wlan_close_inline_cui(&inline_abort_event->sender_id);
}

/*****************************************************************************
 * FUNCTION
 *  cui_wlan_leave_callback
 * DESCRIPTION
 *  Account bearer list leave function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_wlan_leave_callback(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_INPUT_DONE_CONN, evt->evt_id);
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AP_SELECTION_LIST_SCAN_SCREEN_DELETE);
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AP_SELECTION_LIST_SCAN_SCREEN_GOBACK);
            cui_wlan_cancel_scan_job();
            break;
    }
    return MMI_RET_OK;

}

/*****************************************************************************
  * FUNCTION
  *  cui_wlan_list_group_proc
  * DESCRIPTION
  *  Proc function of WLAN cui
  * PARAMETERS
  *  evt    [IN]
  * RETURNS
  *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_wlan_list_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
#ifdef __MMI_OP01_WIFI__
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AP_SELECTION_LIST_CANCEL_IN_END_KEY, g_wlan_display_context.ui_flow);
#endif
        cui_wlan_inform_caller_action (CUI_WLAN_AP_LIST_ACTION_CANCEL);
        break;
    case EVT_ID_GROUP_DEINIT:    /* deinint group */
        // reset the proc_flag when quit the wlan cui's group
        // mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
        // end scenario after deinit ap list
        // mmi_frm_end_scenario (MMI_SCENARIO_ID_SHOW_WLAN_AP_LIST);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AP_SELECTION_LIST_DEINIT);
		#ifdef __CERTMAN_SUPPORT__
		mmi_certman_close_select_certificate();
		#endif
        break;

    /* editor cui */
    case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        cui_wlan_fseditor_submit_evt_hdlr(evt);
        break;
    case EVT_ID_CUI_FSEDITOR_ABORT:
        cui_wlan_fseditor_abort_evt_hdlr(evt);
        break;

    /* inline cui */
    case EVT_ID_CUI_INLINE_SET_KEY:
        cui_wlan_inline_set_key_evt_hdlr(evt);
        break;
    case EVT_ID_CUI_INLINE_SUBMIT:
        cui_wlan_inline_submit_evt_hdlr (evt);
        break;
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        cui_wlan_inline_screen_active_evt_hdlr (evt);
        break;
    case EVT_ID_CUI_INLINE_NOTIFY:
        cui_wlan_inline_notify_evt_hdlr (evt);
        break;
    case EVT_ID_CUI_INLINE_ABORT:
        cui_wlan_inline_abort_evt_hdlr (evt);
        break;
    }
    return MMI_RET_OK;
}

#ifdef __MMI_OP01_WIFI__

static void cui_wlan_cmcc_entry_wizard_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8  i, ap_list_num, visual_num = 0, se_sa_num = 0, se_num = 0, sa_num = 0;
    U8  *guiBuffer = NULL;
    U16 left_key;
    U16 icon_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 iconStates[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_wlan_cmcc_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST);
    // system_print("---->Start to show the ap list!!\n");
    
    ap_list_num = se_num + sa_num + se_sa_num;
    for (i = 0; i < ap_list_num; i++)
    {
        if(g_cui_wlan_cntx.prof_list[i].ap_mgr_type == WLAN_AP_MGR_TYPE_BLACK_LIST)
            continue;
        // Record index of ap in g_wizard_profile_list
        g_index_main_list[visual_num] = i;
        memset(subMenuData[visual_num], 0, MAX_SUB_MENU_SIZE);
        switch (g_cui_wlan_cntx.prof_list[i].type)
        {
            case WLAN_MATCH_SE_SA_C:
            case WLAN_MATCH_SE_SA:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SE_SA, 
                    g_cui_wlan_cntx.prof_list[i].p_sa->ssid_len, g_cui_wlan_cntx.prof_list[i].p_sa->profile_id);
                /* system_print("----> SE_SA|SE_SA_C: ssid's length: %d profile_id: %d\n",
                    g_cui_wlan_cntx.prof_list[i].p_sa->ssid_len, g_cui_wlan_cntx.prof_list[i].p_sa->profile_id);*/
                mmi_ucs2cpy(
                    (CHAR*)subMenuData[visual_num],
                    (const CHAR*)g_cui_wlan_cntx.prof_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_cui_wlan_cntx.prof_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        icon_list[visual_num] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    default:
                        if (g_cui_wlan_cntx.prof_list[i].p_se->privacy > 0 ||
                            g_cui_wlan_cntx.prof_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_cui_wlan_cntx.prof_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        else
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        break;
                }
                if (g_cui_wlan_cntx.prof_list[i].type == WLAN_MATCH_SE_SA)
                {
                    if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -60)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -70)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -80)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL1;
                    }
                    else
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL0;
                    }
                }
                else 
                {
                    if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -60)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -70)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL2_CONNECTED;
                    }
                    else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -80)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL1_CONNECTED;
                    }
                    else
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL0_CONNECTED;
                    }                    
                }
                break;
            }
            case WLAN_MATCH_SE:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SE, g_cui_wlan_cntx.prof_list[i].p_se->ssid_len);
                // system_print("----> SE: ssid's length: %d \n",g_cui_wlan_cntx.prof_list[i].p_se->ssid_len);
                custom_wlan_ssid_convert(
                        (const char*) g_cui_wlan_cntx.prof_list[i].p_se->ssid, 
                        (char*) subMenuData[visual_num], 
                        g_cui_wlan_cntx.prof_list[i].p_se->ssid_len);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_cui_wlan_cntx.prof_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        icon_list[visual_num] = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    default:
                        if (g_cui_wlan_cntx.prof_list[i].p_se->privacy > 0 ||
                            g_cui_wlan_cntx.prof_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_cui_wlan_cntx.prof_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        else
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        break;
                }
                if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -60)
                {
                    iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                }
                else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -70)
                {
                    iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                }
                else if (g_cui_wlan_cntx.prof_list[i].p_se->rssi > -80)
                {
                    iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL1;
                }
                else
                {
                    iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL0;
                }
                break;
            }
            case WLAN_MATCH_SA:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SA, 
                    g_cui_wlan_cntx.prof_list[i].p_sa->ssid_len, g_cui_wlan_cntx.prof_list[i].p_sa->profile_id);    
                /* system_print("----> SA: ssid's length: %d profile_id: %d\n",
                    g_cui_wlan_cntx.prof_list[i].p_sa->ssid_len, g_cui_wlan_cntx.prof_list[i].p_sa->profile_id); */
                mmi_ucs2cpy(
                    (CHAR*)subMenuData[visual_num],
                    (const CHAR*)g_cui_wlan_cntx.prof_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_cui_wlan_cntx.prof_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        icon_list[visual_num] = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_cui_wlan_cntx.prof_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_cui_wlan_cntx.prof_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        else
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        break;
                }
                iconStates[visual_num] = 0;
                break;
            }
            case WLAN_MATCH_SA_C:
            {
                mmi_ucs2cpy(
                    (CHAR*)subMenuData[visual_num],
                    (const CHAR*)g_cui_wlan_cntx.prof_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_cui_wlan_cntx.prof_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        icon_list[visual_num] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_cui_wlan_cntx.prof_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_cui_wlan_cntx.prof_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        else 
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        break;
                }
                iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                break;
            } 
        } /* end of switch */
        visual_num++; 
    } /* end of for */

    if (!mmi_frm_scrn_enter(
            g_cui_wlan_gid,
            SCR_ID_DTCNT_CUI_WLAN_LIST,
            NULL,
            cui_wlan_cmcc_entry_wizard_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    RegisterHighlightHandler(cui_wlan_wizard_list_highlight_hdlr);
    
    if (g_wlan_display_context.wizard_profile_changed)
    {
        guiBuffer = NULL;
        g_wlan_ap_list_hilt_idx = 0;
        g_wlan_display_context.wizard_profile_changed = MMI_FALSE;
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_CUI_WLAN_LIST);
    }

    if (visual_num)
    {
        left_key = STR_GLOBAL_CONNECT;
    }
    else
    {
        left_key = 0;
    }

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_SCAN_RESULT,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        left_key,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        visual_num,
        subMenuDataPtrs,
        (U16*) icon_list,
        iconStates,
        g_wlan_ap_list_hilt_idx,
        guiBuffer,
        ICON_TEXT_ICON);

    if (visual_num)
    {
        SetLeftSoftkeyFunction(cui_wlan_connect_ap, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(cui_wlan_connect_ap, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(cui_wlan_cancel, KEY_EVENT_UP);
}

static void cui_wlan_cmcc_prepare_wizard_list(U8 *se_num, U8 *sa_num, U8 *se_sa_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */          
    /*----------------------------------------------------------------*/
    U8 i, j, pos = 0, total_ap_num = 0;
    int default_se_sa_num = 0;
    MMI_BOOL is_matched;
    srv_dtcnt_wlan_status_enum wlan_status;
    mmi_wlan_wizard_list_struct wlan_profile_temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *se_num = 0;
    *sa_num = 0;
    *se_sa_num = 0;

    wlan_status = srv_dtcnt_wlan_status();
    for (i = 0; i < g_wlan_display_context.ap_list_num; i++)
    {
        is_matched = MMI_FALSE;
        bssinfo_to_profile(&g_profile_saved_temp, &g_wlan_display_context.ap_list[i], NULL, 0);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP, g_profile_saved_temp.ssid_len);
        // system_print("---->Search -- SSID's Length: %d \n", g_profile_saved_temp.ssid_len);
        for (j = 0; j < g_wlan_display_context.prof_num; j++)
        {
            if (mmi_wlan_is_same_ap (g_wlan_profile[j], &g_profile_saved_temp))
            
            {
                if (g_wlan_profile[j]->ap_type == SRV_DTCNT_WLAN_AP_BLACK_LIST)
            {
                    g_wlan_profile[j]->is_search_matched = MMI_TRUE;
					is_matched = MMI_TRUE;
					continue;
                }
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_FOUND, g_wlan_profile[j]->ssid_len, g_wlan_profile[j]->profile_id);
                // system_print("---->Found! SSID's Length: %d Profile ID: %d \n", g_wlan_profile[j]->ssid_len, g_wlan_profile[j]->profile_id);
                g_cui_wlan_cntx.prof_list[*se_sa_num].p_sa = g_wlan_profile[j];
                g_cui_wlan_cntx.prof_list[*se_sa_num].p_se = &g_wlan_display_context.ap_list[i];
                g_cui_wlan_cntx.prof_list[*se_sa_num].type = WLAN_MATCH_SE_SA;
                g_cui_wlan_cntx.prof_list[*se_sa_num].priority = j;
                g_wlan_profile[j]->is_search_matched = MMI_TRUE;
                is_matched = MMI_TRUE;
                if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
                    g_wlan_profile[j] == g_wlan_display_context.connected_wlan_profile)
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_ACTIVATE);
                    //system_print("---->And it's activated!!\n");
                    g_cui_wlan_cntx.prof_list[*se_sa_num].type = WLAN_MATCH_SE_SA_C;
                }
                (*se_sa_num)++;

		}
        }
        if (is_matched == MMI_FALSE)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_NOT_FOUND);
            // system_print("---->Not found!!!\n");
            g_cui_wlan_cntx.se_temp_list[*se_num].p_se = &g_wlan_display_context.ap_list[i];
            g_cui_wlan_cntx.se_temp_list[*se_num].p_sa = NULL;
            g_cui_wlan_cntx.se_temp_list[*se_num].type = WLAN_MATCH_SE;
            g_cui_wlan_cntx.se_temp_list[*se_num].priority = MAX_WLAN_DATA_ACCOUNT_NUM + 1;
            (*se_num)++;
        }
    }
    
    memcpy(&g_cui_wlan_cntx.prof_list[*se_sa_num], g_cui_wlan_cntx.se_temp_list, (*se_num) * sizeof(mmi_wlan_wizard_list_struct));

    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        
        if (!g_wlan_profile[i]->is_search_matched)
        
        {
           MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SAVE_AP, g_wlan_profile[i]->ssid_len, g_wlan_profile[i]->profile_id);
           // system_print("---->Save(Not in scan result.) -- SSID's Length: %d Profile ID: %d \n", g_wlan_profile[i]->ssid_len, g_wlan_profile[i]->profile_id);
           g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].p_se = NULL;
           g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].p_sa = g_wlan_profile[i];
           g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].type = WLAN_MATCH_SA;
           g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].priority = i;

           if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
               g_wlan_profile[i] == g_wlan_display_context.connected_wlan_profile)
           {
               g_cui_wlan_cntx.prof_list[*se_sa_num + *se_num + *sa_num].type = WLAN_MATCH_SA_C;
           }
           (*sa_num)++;
        }
        else
        {
            g_wlan_profile[i]->is_search_matched = MMI_FALSE;
        }
    }

    total_ap_num = *se_sa_num + *se_num + *sa_num;
    /* Mark ap's manage type */
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SPERATOR);
    // system_print("=========================================================\n");
    for(i = 0; i< total_ap_num; i++)
    {
        if(WLAN_MATCH_SE == g_cui_wlan_cntx.prof_list[i].type)
        {
            bssinfo_to_profile(&g_profile_saved_temp, g_cui_wlan_cntx.prof_list[i].p_se, NULL, 0);
            if(mmi_wlan_is_default_trust_ap(&g_profile_saved_temp))
            {
                g_cui_wlan_cntx.prof_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_DEFAULT;
            }
            else
            {
                if(mmi_wlan_is_black_list_ap(&g_profile_saved_temp))
                {
                    g_cui_wlan_cntx.prof_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_BLACK_LIST;
                }
                else
                {
                    g_cui_wlan_cntx.prof_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_UNKNOWN;
                }
            }
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_AP_MATCH_TYPE, 
                            g_profile_saved_temp.ssid_len, 
                            g_cui_wlan_cntx.prof_list[i].ap_mgr_type,
                            g_cui_wlan_cntx.prof_list[i].type);
            /*
            system_print("SSID: %s \t MGR: %d Network: %d Match: %d Profile Id: %d\n",
                            g_profile_saved_temp.ssid, 
                            g_cui_wlan_cntx.prof_list[i].ap_mgr_type,
                            g_profile_saved_temp.network_type,
                            g_cui_wlan_cntx.prof_list[i].type,
                            g_profile_saved_temp.profile_id);
            */                            
        }
        else
        {
            if(mmi_wlan_is_default_trust_ap(g_cui_wlan_cntx.prof_list[i].p_sa))
            {
                g_cui_wlan_cntx.prof_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_DEFAULT;
            }
            else
            {
                if(mmi_wlan_is_black_list_ap(g_cui_wlan_cntx.prof_list[i].p_sa))
                {
                    g_cui_wlan_cntx.prof_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_BLACK_LIST;
                }
                else
                {
                    g_cui_wlan_cntx.prof_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_USER_DEFINE;
                }
            }
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_AP_MATCH_TYPE, 
                            g_profile_saved_temp.ssid_len, 
                            g_cui_wlan_cntx.prof_list[i].ap_mgr_type,
                            g_cui_wlan_cntx.prof_list[i].type);
            
            /*
            system_print("SSID: %s \t MGR: %d Network: %d Match: %d Profile Id: %d\n",
                        g_cui_wlan_cntx.prof_list[i].p_sa->ssid, 
                        g_cui_wlan_cntx.prof_list[i].ap_mgr_type,
                        g_cui_wlan_cntx.prof_list[i].p_sa->network_type,
                        g_cui_wlan_cntx.prof_list[i].type,
                        g_cui_wlan_cntx.prof_list[i].p_sa->profile_id);
            */
        }
    }
    for(i = 0; i < total_ap_num; i++)
    {
        if(WLAN_AP_MGR_TYPE_DEFAULT == g_cui_wlan_cntx.prof_list[i].ap_mgr_type)
        {
            if(g_cui_wlan_cntx.prof_list[i].type == WLAN_MATCH_SE_SA || 
                g_cui_wlan_cntx.prof_list[i].type == WLAN_MATCH_SE_SA_C)
            {
                default_se_sa_num++;
            }
            
            memcpy(&wlan_profile_temp, &g_cui_wlan_cntx.prof_list[i], sizeof(mmi_wlan_wizard_list_struct));
            
            for(j = i; j > pos; j--)
            {
               memcpy(&g_cui_wlan_cntx.prof_list[j], 
                      &g_cui_wlan_cntx.prof_list[j-1], 
                      sizeof(mmi_wlan_wizard_list_struct)); 
            }
            
            memcpy(&g_cui_wlan_cntx.prof_list[pos], 
                   &wlan_profile_temp, 
                   sizeof(mmi_wlan_wizard_list_struct));
            ++pos;
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SPERATOR);
    // system_print("=========================================================\n");
}

void cui_wlan_cmcc_ap_list_highlight_hdlr(S32 nIndex)
{
    U8 pos;
    pos = g_index_main_list[nIndex];

    g_cui_wlan_cntx.current_item_selected = pos;

    g_cui_wlan_cntx.list_option = g_cui_wlan_cntx.prof_list[pos].type;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_WLAN_CMCC_AP_LIST_HIGHLIGHT_INDEX, 
        0, nIndex, pos, g_cui_wlan_cntx.list_option);
    
    if (g_cui_wlan_cntx.list_option == WLAN_MATCH_SA || 
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SE_SA ||
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SE_SA_C ||
        g_cui_wlan_cntx.list_option == WLAN_MATCH_SA_C)
    {
        g_wlan_display_context.cui_saved_hilt_ap = g_cui_wlan_cntx.prof_list[pos].p_sa;
        /* need not save AP */
        g_wlan_display_context.search_connect_need_save = MMI_FALSE;
    }
    else if (g_cui_wlan_cntx.list_option == WLAN_MATCH_SE)
    {
        g_wlan_display_context.cui_search_hilt_ap= g_cui_wlan_cntx.prof_list[pos].p_se;
    }
}


#endif /* __MMI_OP01_WIFI__ */

#endif /* __MMI_WLAN_FEATURES__ */

#endif /* __TCPIP__ */ 

