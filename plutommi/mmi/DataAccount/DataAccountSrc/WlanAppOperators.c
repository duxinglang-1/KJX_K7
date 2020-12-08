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
 *   WlanAppOperators.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Wlan application's customization part for operators
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
/*******************************************************************************
 * Include Header File
 *******************************************************************************/
#ifdef __TCPIP__
#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_WLAN_FEATURES__
#ifdef __MMI_OP01_WIFI__
#include "cbm_api.h"
#include "UcmSrvGprot.h"
#ifdef __MMI_WEBCAM__
#include "USBDeviceGprot.h"
#endif  /* __MMI_WEBCAM__ */
#ifdef  __DM_SCOMO_SUPPORT__
#include "dmuigprot.h"
#endif  /* __DM_SCOMO_SUPPORT__*/
#include "AlarmFrameworkProt.h"         /* AlmIsTonePlaying()*/
#ifdef __MMI_UCM__
#include "UCMGprot.h"
#endif  /* __MMI_UCM__ */
#include "UcmSrvGprot.h"
#include "ScrLockerGprot.h"
#include "CommonScreens.h"
#include "AlertScreen.h"
#include "GlobalResDef.h"
#include "TimerEvents.h"
#include "gui_fixed_menuitems.h"
#include "Wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "nvram_common_defs.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "DataAccountStruct.h"
#include "DataAccountCore.h"
#ifndef __OPTR_NONE__
#include "mmi_rp_app_connectivity_mainmenu_def.h"
#endif
#include "DataAccountProt.h"

/***************************************************************************** 
 * Global variable
 *****************************************************************************/
extern mmi_id wlan_parent_group_id;
extern mmi_wlan_display_struct g_wlan_display_context;
extern mmi_wlan_profile_struct  g_profile_saved_temp;
extern mmi_wlan_wizard_list_struct g_wizard_prfile_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_profile_struct *g_wlan_profile[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_wizard_list_struct g_wizard_se_temp_list[WNDRV_MAX_SCAN_RESULTS_NUM];
extern mmi_wlan_profile_struct g_wlan_prof_list[MAX_WLAN_DATA_ACCOUNT_NUM];
extern srv_dtcnt_prof_wlan_struct g_srv_wlan_prof;
extern MMI_BOOL g_wapi_test_mode;
extern supc_abm_bss_info_struct g_wlan_hilt_profile;
/* For AP management */
const char default_ap_str[5] = {'C','M','C','C'};
const char default_ap_edu_str[9] = {'C','M','C','C','-','E','D','U'};
U8 g_index_main_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
static U8 g_index_trust_list[MAX_WLAN_DATA_ACCOUNT_NUM];
static U8 g_index_result_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
/* For AP selection list */
mmi_id g_wlan_ap_list_group_id;     
mmi_id g_wlan_ap_list_cui_id;
/* For auto conn. */
U8 g_auto_conn_ap_total = 0;
U8 g_auto_conn_ap_idx = 0;
U8 g_auto_conn_saved_ap_total = 0;
U8 g_auto_conn_search_ap_total = 0;
static mmi_wlan_profile_struct* g_auto_conn_saved_list[MAX_WLAN_DATA_ACCOUNT_NUM];
static supc_abm_bss_info_struct g_auto_conn_search_list[5];
static mmi_wlan_auto_conn_list_struct g_auto_conn_list[MAX_WLAN_DATA_ACCOUNT_NUM];
/* For transferring cellular to wlan */
static mmi_id g_transfer_network_confirm_id;
/* For proxy exclusion list */
static S32 g_wlan_exclusive_ip_addr_hilight_id;
static srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct g_wlan_exclusive_ip_addr_data;
static MMI_ID g_exclusive_ip_address_gid;
static U8 g_exclusive_url[(SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH];
/* For portal cert. client */
static srv_dtcnt_wlan_cb_func_ptr g_deinit_cb_func;
static void* g_deinit_user_data;
static srv_dtcnt_wlan_logout_cb_func_ptr g_logout_ind_cb;
static U8 g_portal_result;
static mmi_wlan_action_after_logout_func_ptr g_to_do_action;
/* For power saving mode */
static U8 g_power_saving_mode_idx;
// Settings Inline CUI
static const cui_inline_item_caption_struct auto_search_switch_caption = {STR_ID_DTCNT_WLAN_AUTO_SEARCH};
static const MMI_STR_ID auto_search_optional[2] = {STR_GLOBAL_NO, STR_GLOBAL_YES};
static const cui_inline_item_select_struct auto_search_switch_selector = {DATA_ACCOUNT_INLINE_USE_PROXY_OPTION, 0, auto_search_optional};

static const cui_inline_item_caption_struct auto_search_interval_caption = {STR_ID_DTCNT_WLAN_INTERVALS};
static const MMI_STR_ID interval_option[3] = {STR_ID_DTCNT_WLAN_INTERVALS_TEN_SECS, STR_ID_DTCNT_WLAN_INTERVALS_HALF_MIN, STR_ID_DTCNT_WLAN_INTERVALS_ONE_MIN};
static const cui_inline_item_select_struct auto_search_interval_selector = {DATA_ACCOUNT_INLINE_INTERVAL_OPTION, 0, interval_option};

static const cui_inline_item_caption_struct auto_conn_switch_caption = {STR_ID_DTCNT_WLAN_AUTO_CONN};
static const MMI_STR_ID auto_conn_optional[2] = {STR_GLOBAL_NO, STR_GLOBAL_YES};
static const cui_inline_item_select_struct auto_conn_switch_selector = {2, 0, auto_conn_optional};

static const cui_inline_item_caption_struct network_switch_caption = {STR_ID_DTCNT_WLAN_CELLULAR_TO_WLAN};
static const MMI_STR_ID network_switch_optional[3] = {STR_ID_DTCNT_WLAN_ALWAYS_ASK, STR_ID_DTCNT_WLAN_AUTO_SELECT, STR_ID_DTCNT_WLAN_MANUALLY_SELECT};
static const cui_inline_item_select_struct network_switch_selector = {3, 0, network_switch_optional};

static const cui_inline_item_caption_struct ssid_switch_caption = {STR_ID_DTCNT_WLAN_AUTO_RESELECT_AMONG_SSID};
static const MMI_STR_ID ssid_switch_optional[2] = {STR_ID_DTCNT_WLAN_MANUALLY_SELECT, STR_ID_DTCNT_WLAN_AUTO_SELECT};
static const cui_inline_item_select_struct ssid_switch_selector = {2, 0, ssid_switch_optional};

static const cui_inline_item_caption_struct cellular_switch_caption = {STR_ID_DTCNT_WLAN_NO_WLAN_TO_CELLULAR};
static const MMI_STR_ID cellular_switch_optional[2] = {STR_ID_DTCNT_WLAN_ALWAYS_ASK, STR_ID_DTCNT_WLAN_NO_MORE_ASK};
static const cui_inline_item_select_struct cellular_switch_selector = {2, 0, cellular_switch_optional};

static const cui_inline_item_caption_struct auto_portal_switch_caption = {STR_ID_DTCNT_WLAN_PORTAL_CERT_SETTING};
static const MMI_STR_ID auto_portal_switch_optional[2] = {STR_GLOBAL_YES, STR_GLOBAL_NO};
static const cui_inline_item_select_struct auto_portal_switch_selector = {2, 0, auto_portal_switch_optional};

static const cui_inline_set_item_struct auto_search_inline_items[WLAN_AUTO_SEARCH_TOTAL] = 
{
    {WLAN_AUTO_SEARCH_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&auto_search_switch_caption},
    {WLAN_AUTO_SEARCH_SELECT_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&auto_search_switch_selector},
    {WLAN_AUTO_SEARCH_INTERVAL_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&auto_search_interval_caption},
    {WLAN_AUTO_SEARCH_INTERVAL_SELECT_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&auto_search_interval_selector},
    {WLAN_AUTO_CONN_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&auto_conn_switch_caption},
    {WLAN_AUTO_CONN_SELECT_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&auto_conn_switch_selector},
    {WLAN_NETWORK_SWITCH_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&network_switch_caption},
    {WLAN_NETWORK_SWITCH_SELECT_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&network_switch_selector},
    {WLAN_SSID_SWITCH_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&ssid_switch_caption},
    {WLAN_SSID_SWITCH_SELECT_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&ssid_switch_selector},
    {WLAN_CELLULAR_SWITCH_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&cellular_switch_caption},
    {WLAN_CELLULAR_SWITCH_SELECT_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&cellular_switch_selector},
    {WLAN_AUTO_PORTAL_SWITCH_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&auto_portal_switch_caption},
    {WLAN_AUTO_PORTAL_SWITCH_SELECT_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&auto_portal_switch_selector}
};
static const cui_inline_struct g_cmcc_wlan_settings_struct =
{
    WLAN_AUTO_SEARCH_TOTAL,
    STR_GLOBAL_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    auto_search_inline_items
};
// Find AP Inline CUI
static const cui_inline_item_caption_struct find_ap_caption = {STR_ID_DTCNT_WLAN_SSID};
static const cui_inline_item_fullscreen_edit_struct ap_name_editor = 
{
    0,
    0,
    STR_ID_DTCNT_WLAN_SSID,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_CHAR,
    SRV_DTCNT_PROF_MAX_SSID_LEN + 1,
    NULL
};
static const cui_inline_set_item_struct find_ap_inline_items[WLAN_FIND_AP_TOTAL] = 
{
    {WLAN_FIND_AP_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&find_ap_caption},
    {WLAN_FIND_AP_EDITOR_ID, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&ap_name_editor}
};
static const cui_inline_struct g_find_ap_inline_struct = 
{
    WLAN_FIND_AP_TOTAL,
    STR_ID_DTCNT_WLAN_FIND_AP,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    find_ap_inline_items
};
// Exlusive URL inline CUI
static const cui_inline_item_caption_struct url_caption = {STR_GLOBAL_URL};
static const cui_inline_item_fullscreen_edit_struct url_editor =
{
    0,
    0,
    STR_GLOBAL_URL,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL | INPUT_TYPE_EXT_ASCII_ENCODING_BASE_LENGTH,
    IMM_INPUT_TYPE_URL,
    SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN,
    NULL
};
static const cui_inline_set_item_struct inline_items[WLAN_ADVANCED_TOTAL] = 
{
    {WLAN_EXCLUSIVE_URL_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&url_caption},
    {WLAN_EXCLUSIVE_URL_EDITOR_ID, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&url_editor}
};
static const cui_inline_struct g_exlusive_url_inline_struct = 
{
    WLAN_EXCLUSIVE_URL_TOTAL,
    STR_GLOBAL_TEXT,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    inline_items
};

/******************************************************************************/
/**         CMCC WiFi Auto Search                                            **/
/**         Author: Yunpeng Li                                               **/
/**         Date: 2010-8-18                                                  **/
/******************************************************************************/
void mmi_wlan_entry_auto_search_settings(void)
{
    g_wlan_display_context.wlan_auto_search_setting_cui_id = cui_inline_create(
                            wlan_parent_group_id,
                            &g_cmcc_wlan_settings_struct);

    cui_inline_set_value (g_wlan_display_context.wlan_auto_search_setting_cui_id, WLAN_AUTO_SEARCH_SELECT_ID, (void *)g_wlan_display_context.is_auto_search);
    cui_inline_set_value (g_wlan_display_context.wlan_auto_search_setting_cui_id, WLAN_AUTO_SEARCH_INTERVAL_SELECT_ID, (void *)g_wlan_display_context.auto_search_interval_idx);
    cui_inline_set_value (g_wlan_display_context.wlan_auto_search_setting_cui_id, WLAN_AUTO_CONN_SELECT_ID, (void *)g_wlan_display_context.is_auto_conn);
    cui_inline_set_value (g_wlan_display_context.wlan_auto_search_setting_cui_id, WLAN_NETWORK_SWITCH_SELECT_ID, (void *)g_wlan_display_context.network_switch_idx);
    cui_inline_set_value (g_wlan_display_context.wlan_auto_search_setting_cui_id, WLAN_SSID_SWITCH_SELECT_ID, (void *)g_wlan_display_context.is_ssid_switch);
    cui_inline_set_value (g_wlan_display_context.wlan_auto_search_setting_cui_id, WLAN_CELLULAR_SWITCH_SELECT_ID, (void *)g_wlan_display_context.cellular_switch_idx);
    cui_inline_set_value (g_wlan_display_context.wlan_auto_search_setting_cui_id, WLAN_AUTO_PORTAL_SWITCH_SELECT_ID, (void *)g_wlan_display_context.auto_portal_switch_idx);
    
    cui_inline_run (g_wlan_display_context.wlan_auto_search_setting_cui_id);

}

void mmi_wlan_start_auto_search_timer(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_SEARCH_SETTINGS, g_wlan_display_context.is_auto_search);
    if((SRV_DTCNT_WLAN_STATUS_INACTIVE != srv_dtcnt_wlan_status ()) &&       /* wlan is turned on */
        g_wlan_display_context.is_auto_search)  /* manually activate auto search  */
    {
        StartTimer(WIFI_AUTO_SEARCH_TIMER, 
            g_wlan_display_context.auto_search_interval, 
            mmi_wlan_auto_search_timeout_cb);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_SEARCH_START_TIMER, WIFI_AUTO_SEARCH_TIMER);
    }
}

void mmi_wlan_stop_auto_search_timer(void)
{
    StopTimer (WIFI_AUTO_SEARCH_TIMER);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_SEARCH_STOP_TIMER);
}


void mmi_wlan_auto_search_timeout_cb(void)
{
    if((SRV_DTCNT_WLAN_STATUS_INACTIVE != srv_dtcnt_wlan_status ()) &&       /* wlan is turned on */
        g_wlan_display_context.is_auto_search)  /* manually activate auto search  */
    {
        mmi_wlan_enable_entry_main();
    }
}

void mmi_wlan_get_auto_search_settings(void)
{
    /* Get auto searching switch status and interval */
    cui_inline_get_value(
        g_wlan_display_context.wlan_auto_search_setting_cui_id,
        WLAN_AUTO_SEARCH_SELECT_ID,
        &g_wlan_display_context.is_auto_search);
    cui_inline_get_value(
        g_wlan_display_context.wlan_auto_search_setting_cui_id,
        WLAN_AUTO_SEARCH_INTERVAL_SELECT_ID,
        &g_wlan_display_context.auto_search_interval_idx);
    cui_inline_get_value(
        g_wlan_display_context.wlan_auto_search_setting_cui_id,
        WLAN_AUTO_CONN_SELECT_ID,
        &g_wlan_display_context.is_auto_conn);
    cui_inline_get_value(
        g_wlan_display_context.wlan_auto_search_setting_cui_id,
        WLAN_SSID_SWITCH_SELECT_ID,
        &g_wlan_display_context.is_ssid_switch);
    cui_inline_get_value(
        g_wlan_display_context.wlan_auto_search_setting_cui_id,
        WLAN_NETWORK_SWITCH_SELECT_ID,
        &g_wlan_display_context.network_switch_idx);
    cui_inline_get_value(
        g_wlan_display_context.wlan_auto_search_setting_cui_id,
        WLAN_CELLULAR_SWITCH_SELECT_ID,
        &g_wlan_display_context.cellular_switch_idx);
    cui_inline_get_value(
        g_wlan_display_context.wlan_auto_search_setting_cui_id,
        WLAN_AUTO_PORTAL_SWITCH_SELECT_ID,
        &g_wlan_display_context.auto_portal_switch_idx);

    if(MMI_TRUE == g_wlan_display_context.is_auto_search)
    {
        switch(g_wlan_display_context.auto_search_interval_idx)
        {
            case 0:
                g_wlan_display_context.auto_search_interval = AUTO_SEARCH_DELAY_TEN_SECS;
                break;
            case 1:
                g_wlan_display_context.auto_search_interval = AUTO_SEARCH_DELAY_HALF_MIN;
                break;
            case 2:
                g_wlan_display_context.auto_search_interval = AUTO_SEARCH_DELAY_ONE_MIN;
                break;
            default:
                break;
        }
    }

    mmi_wlan_update_settings_in_db ();
}

/******************************************************************************/
/**         CMCC WiFi Access Point Classification                            **/
/**         Author: Yunpeng Li                                               **/
/**         Date: 2010-8-18                                                  **/
/******************************************************************************/
MMI_BOOL mmi_wlan_is_default_trust_ap(const mmi_wlan_profile_struct *profile)
{
    if((profile->auth_mode == ((U8)SRV_DTCNT_WLAN_AUTH_MODE_OPEN)) &&
       ((profile->ssid_len == 4 && 
         strncmp((const char*)profile->ssid, (const char*)default_ap_str, 4) == 0) 
         ||
        (profile->ssid_len == 8 && 
         strncmp((const char*)profile->ssid, (const char*)default_ap_edu_str, 8) == 0)))
        return MMI_TRUE;
    else
        return MMI_FALSE;
}

MMI_BOOL mmi_wlan_is_black_list_ap(const mmi_wlan_profile_struct *profile)
{
    U8 index;

    for(index = 0; index < g_wlan_display_context.prof_num; index++)
    {
	if(g_wlan_prof_list[index].ap_type == SRV_DTCNT_WLAN_AP_BLACK_LIST &&
          (profile->ssid_len == g_wlan_prof_list[index].ssid_len) &&
          (strncmp((const char*)profile->ssid, (const char*)g_wlan_prof_list[index].ssid, g_wlan_prof_list[index].ssid_len) == 0) &&
          (profile->network_type == g_wlan_prof_list[index].network_type) &&
          (profile->auth_mode == g_wlan_prof_list[index].auth_mode) &&
          (profile->encrypt_mode == g_wlan_prof_list[index].encrypt_mode))
           return MMI_TRUE;
    }

    return MMI_FALSE;
}

void mmi_wlan_cmcc_entry_wizard_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8  i, ap_list_num, visual_num = 0, se_sa_num = 0, se_num = 0, sa_num = 0;
    U8  *guiBuffer = NULL;
    U16 icon_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 iconStates[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // mmi_wlan_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    mmi_wlan_cmcc_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST);
    // system_print("---->Start to show the ap list!!\n");
    
    ap_list_num = se_num + sa_num + se_sa_num;
    for (i = 0; i < ap_list_num; i++)
    {
        if(g_wizard_prfile_list[i].ap_mgr_type == WLAN_AP_MGR_TYPE_BLACK_LIST)
            continue;
        // Record index of ap in g_wizard_profile_list
        g_index_main_list[visual_num] = i;
        memset(subMenuData[visual_num], 0, MAX_SUB_MENU_SIZE);
        switch (g_wizard_prfile_list[i].type)
        {
            case WLAN_MATCH_SE_SA_C:
            case WLAN_MATCH_SE_SA:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SE_SA, g_wizard_prfile_list[i].p_sa->ssid_len, g_wizard_prfile_list[i].p_sa->profile_id);
                /* system_print("----> SE_SA|SE_SA_C: ssid's length: %d profile_id: %d\n",
                    g_wizard_prfile_list[i].p_sa->ssid_len, g_wizard_prfile_list[i].p_sa->profile_id); */
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[visual_num],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_wizard_prfile_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        icon_list[visual_num] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    default:
                        if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                            g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        else
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        break;
                }
                if (g_wizard_prfile_list[i].type == WLAN_MATCH_SE_SA)
                {
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
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
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL2_CONNECTED;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
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
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SE, g_wizard_prfile_list[i].p_se->ssid_len);
                // system_print("----> SE: ssid's length: %d \n",g_wizard_prfile_list[i].p_se->ssid_len);
                custom_wlan_ssid_convert(
                        (const char*) g_wizard_prfile_list[i].p_se->ssid, 
                        (char*) subMenuData[visual_num], 
                        g_wizard_prfile_list[i].p_se->ssid_len);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_wizard_prfile_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        icon_list[visual_num] = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    default:
                        if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                            g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        else
                        {
                            icon_list[visual_num] = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        break;
                }
                if (g_wizard_prfile_list[i].p_se->rssi > -60)
                {
                    iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                }
                else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                {
                    iconStates[visual_num] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                }
                else if (g_wizard_prfile_list[i].p_se->rssi > -80)
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
                    g_wizard_prfile_list[i].p_sa->ssid_len, g_wizard_prfile_list[i].p_sa->profile_id);    
                /* system_print("----> SA: ssid's length: %d profile_id: %d\n",
                    g_wizard_prfile_list[i].p_sa->ssid_len, g_wizard_prfile_list[i].p_sa->profile_id); */
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[visual_num],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_wizard_prfile_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        icon_list[visual_num] = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
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
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_wizard_prfile_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        icon_list[visual_num] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
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
    g_wlan_display_context.display_ap_num = visual_num;
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST,
            mmi_wlan_exit_new_wizard_list,
            mmi_wlan_cmcc_entry_wizard_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    } 

    RegisterHighlightHandler(mmi_wlan_wizard_list_highlight_hdlr);
    if (g_wlan_display_context.wizard_profile_changed)
    {
        guiBuffer = NULL;
        g_wlan_display_context.wizard_cur_profile_list_index = 0;
        g_wlan_display_context.wizard_profile_changed = MMI_FALSE;
    }
    else
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST);
    }

    if (visual_num)
    {
        ShowCategory73Screen(
            STR_ID_DTCNT_WLAN_SCAN_RESULT,
            GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            visual_num,
            subMenuDataPtrs,
            (U16*) icon_list,
            iconStates,
            g_wlan_display_context.wizard_cur_profile_list_index,
            guiBuffer,
            ICON_TEXT_ICON);
        if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
            g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_network_disconnect, KEY_EVENT_UP);
        }
        else
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_wizard_connect, KEY_EVENT_UP);
        }
    }
    else
    {
        ShowCategory73Screen(
            STR_ID_DTCNT_WLAN_SCAN_RESULT,
            GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            visual_num,
            subMenuDataPtrs,
            (U16*) icon_list,
            iconStates,
            g_wlan_display_context.wizard_cur_profile_list_index,
            guiBuffer,
            ICON_TEXT_ICON);
    }
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    if(g_wlan_display_context.send_conn_req_ing == MMI_FALSE)
    {
        EnableLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_wizard_list_opt, KEY_EVENT_UP);
    }
    else
    {
	DisableLeftSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);		
	ChangeCenterSoftkey(0, 0);
    }

    /* Start auto search timer */
    mmi_wlan_start_auto_search_timer();

    /* Regeister gpio event handler */
    mmi_frm_cb_reg_event (EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, mmi_wlan_callback_handler, NULL);
    mmi_frm_cb_reg_event (EVT_ID_GPIO_LCD_SLEEP_IN, mmi_wlan_callback_handler, NULL);
    mmi_frm_cb_reg_event (EVT_ID_GPIO_LCD_SLEEP_OUT, mmi_wlan_callback_handler, NULL);
    mmi_frm_cb_reg_event (EVT_ID_GPIO_AFTER_LCD_SLEEP_IN, mmi_wlan_callback_handler, NULL);
}

void mmi_wlan_cmcc_refresh_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8  i, ap_list_num, visual_num = 0, se_sa_num = 0, se_num = 0, sa_num = 0;
    U16 signal_icon = 0, type_icon = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // mmi_wlan_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    mmi_wlan_cmcc_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST);
    // system_print("---->Start to show the ap list!!\n");
    
    ap_list_num = se_num + sa_num + se_sa_num;
    for (i = 0; i < ap_list_num; i++)
    {
        if(g_wizard_prfile_list[i].ap_mgr_type == WLAN_AP_MGR_TYPE_BLACK_LIST)
            continue;
        // Record index of ap in g_wizard_profile_list
        g_index_main_list[visual_num] = i;
        memset(subMenuData[visual_num], 0, MAX_SUB_MENU_SIZE);
        switch (g_wizard_prfile_list[i].type)
        {
            case WLAN_MATCH_SE_SA_C:
            case WLAN_MATCH_SE_SA:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SE_SA, g_wizard_prfile_list[i].p_sa->ssid_len, g_wizard_prfile_list[i].p_sa->profile_id);
                /* system_print("----> SE_SA|SE_SA_C: ssid's length: %d profile_id: %d\n",
                    g_wizard_prfile_list[i].p_sa->ssid_len, g_wizard_prfile_list[i].p_sa->profile_id); */
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[visual_num],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_wizard_prfile_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        type_icon = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    default:
                        if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                            g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        else
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        break;
                }
                if (g_wizard_prfile_list[i].type == WLAN_MATCH_SE_SA)
                {
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL3;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL2;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL1;
                    }
                    else
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL0;
                    }
                }
                else 
                {
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL2_CONNECTED;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL1_CONNECTED;
                    }
                    else
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL0_CONNECTED;
                    }                    
                }
                break;
            }
            case WLAN_MATCH_SE:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SE, g_wizard_prfile_list[i].p_se->ssid_len);
                // system_print("----> SE: ssid's length: %d \n",g_wizard_prfile_list[i].p_se->ssid_len);
                custom_wlan_ssid_convert(
                        (const char*) g_wizard_prfile_list[i].p_se->ssid, 
                        (char*) subMenuData[visual_num], 
                        g_wizard_prfile_list[i].p_se->ssid_len);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_wizard_prfile_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        type_icon = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    default:
                        if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                            g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        else
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        break;
                }
                if (g_wizard_prfile_list[i].p_se->rssi > -60)
                {
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL3;
                }
                else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                {
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL2;
                }
                else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                {
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL1;
                }
                else
                {
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL0;
                }
                break;
            }
            case WLAN_MATCH_SA:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SA, 
                    g_wizard_prfile_list[i].p_sa->ssid_len, g_wizard_prfile_list[i].p_sa->profile_id);    
                /* system_print("----> SA: ssid's length: %d profile_id: %d\n",
                    g_wizard_prfile_list[i].p_sa->ssid_len, g_wizard_prfile_list[i].p_sa->profile_id); */
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[visual_num],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_wizard_prfile_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        type_icon = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        else
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        break;
                }
                signal_icon = 0;
                break;
            }
            case WLAN_MATCH_SA_C:
            {
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[visual_num],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[visual_num] = subMenuData[visual_num];
                switch (g_wizard_prfile_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        type_icon = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        else 
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        break;
                }
                signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                break;
            } 
        } /* end of switch */
        Category73ChangeItemIcon(visual_num, 0, get_image(type_icon));
        Category73ChangeItemIcon(visual_num, 1, get_image(signal_icon));
        visual_num++;
    } /* end of for */
    
    g_wlan_display_context.display_ap_num = visual_num;
    Category73RedrawScreen();
    if(g_wlan_display_context.send_conn_req_ing == MMI_FALSE)
    {
	EnableLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
	SetLeftSoftkeyFunction(mmi_wlan_entry_wizard_list_opt, KEY_EVENT_UP);
    }
    else
    {
	DisableLeftSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);		
	ChangeCenterSoftkey(0, 0);
    }
    // Refresh the type of highlighted profile
    mmi_wlan_wizard_list_highlight_hdlr(g_wlan_display_context.wizard_cur_profile_list_index);
}

void mmi_wlan_exit_new_wizard_list(void)
{
    /* Stop auto search timer */
    mmi_wlan_stop_auto_search_timer();

    /* Deregister gpio event handler */
    mmi_frm_cb_dereg_event (EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, mmi_wlan_callback_handler, NULL);
    mmi_frm_cb_dereg_event (EVT_ID_GPIO_LCD_SLEEP_IN, mmi_wlan_callback_handler, NULL);
    mmi_frm_cb_dereg_event (EVT_ID_GPIO_LCD_SLEEP_OUT, mmi_wlan_callback_handler, NULL);
    mmi_frm_cb_dereg_event (EVT_ID_GPIO_AFTER_LCD_SLEEP_IN, mmi_wlan_callback_handler, NULL);
}

void mmi_wlan_cmcc_entry_saved_ap_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  i, count = 0;
    U8  *guiBuffer = NULL;
    U8  *name[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_list[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_state[MAX_WLAN_DATA_ACCOUNT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if(mmi_wlan_is_black_list_ap(g_wlan_profile[i]))
            continue;
        
        // Record index of ap in g_wlan_profile
        g_index_main_list[count] = i;
	if(g_wlan_profile[i]->ap_type == SRV_DTCNT_WLAN_AP_USER_DEFINE)
	{
            name[count] = g_wlan_profile[i]->name;
	}
        else
        {
            continue;
        }

        if(g_wlan_profile[i]->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
        {
            icon_list[count] = IMG_ID_DTCNT_WLAN_ADHOC;
        }
        else
        {
            if(g_wlan_profile[i]->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                g_wlan_profile[i]->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
            {              
                icon_list[count] = IMG_ID_DTCNT_WLAN_STATION;            
            }
            else
            {
                icon_list[count] = IMG_ID_DTCNT_WLAN_SECURED_STATION;            
            }
        }
        
        icon_state[count] = 0;
        // increase
        ++count;
    }

    /* Reset insert mode here */
    g_wlan_display_context.insert_mode = FALSE;
    /* Refresh wifi icon in the top bar */
    mmi_wlan_update_status_icon(0, FALSE);
    
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST,
            NULL,
            mmi_wlan_cmcc_entry_saved_ap_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    /* if (g_wlan_display_context.wizard_profile_changed)
    {
        guiBuffer = NULL;
        g_wlan_display_context.active_wlan_profile_index = 0;
        g_wlan_display_context.wizard_profile_changed = MMI_FALSE;
    }
    else
    { */
    guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST);
    // }
    RegisterHighlightHandler(mmi_wlan_cmcc_saved_ap_list_highlight_hdlr);

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_NETWORK_SETTINGS,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        (U8 **) name,
        icon_state,
        icon_list,
        g_wlan_display_context.active_wlan_profile_index,
        guiBuffer,
        ICON_ICON_TEXT);
    if(0 == count)
    {
        SetLeftSoftkeyFunction(mmi_wlan_cmcc_empty_saved_as_list_options, KEY_EVENT_UP);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		SetCenterSoftkeyFunction(mmi_wlan_cmcc_empty_saved_as_list_options, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_wlan_cmcc_saved_ap_list_options, KEY_EVENT_UP);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		SetCenterSoftkeyFunction(mmi_wlan_cmcc_saved_ap_list_options, KEY_EVENT_UP);
    }
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

void mmi_wlan_cmcc_saved_ap_list_highlight_hdlr(S32 nIndex)
{
    /* set all ap's match type as WLAN_MATCH_SA*/
    g_wlan_display_context.wizard_list_option = WLAN_MATCH_SA;
    g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[g_index_main_list[nIndex]];
    g_wlan_display_context.active_wlan_profile_index = nIndex;
}

void mmi_wlan_cmcc_saved_ap_list_options(void)
{
    g_wlan_display_context.option_menu_cui_id = 
                            cui_menu_create(
                                wlan_parent_group_id, 
                                CUI_MENU_SRC_TYPE_RESOURCE, 
                                CUI_MENU_TYPE_OPTION, 
                                MENU_ID_WLAN_WIZARD_SAVE_LIST_OPT_1, 
                                MMI_TRUE, 
                                NULL);
    cui_menu_run (g_wlan_display_context.option_menu_cui_id);
}

void mmi_wlan_cmcc_empty_saved_as_list_options(void)
{
    g_wlan_display_context.option_menu_cui_id = 
                            cui_menu_create(
                                wlan_parent_group_id, 
                                CUI_MENU_SRC_TYPE_RESOURCE, 
                                CUI_MENU_TYPE_OPTION, 
                                MENU_ID_WLAN_WIZARD_SAVE_LIST_OPT_2, 
                                MMI_TRUE, 
                                NULL);
    cui_menu_run (g_wlan_display_context.option_menu_cui_id);
}   

void mmi_wlan_cmcc_prepare_wizard_list(U8 *se_num, U8 *sa_num, U8 *se_sa_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */          
    /*----------------------------------------------------------------*/
    U8 i, j, index = 0;
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
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_FOUND, g_wlan_profile[j]->ssid_len, g_wlan_profile[j]->profile_id);
                //system_print("---->Found! SSID's Length: %d Profile ID: %d \n", g_wlan_profile[j]->ssid_len, g_wlan_profile[j]->profile_id);
                g_wizard_prfile_list[*se_sa_num].p_sa = g_wlan_profile[j];
                g_wizard_prfile_list[*se_sa_num].p_se = &g_wlan_display_context.ap_list[i];
                g_wizard_prfile_list[*se_sa_num].type = WLAN_MATCH_SE_SA;
                g_wizard_prfile_list[*se_sa_num].priority = j;
                g_wlan_profile[j]->is_search_matched = MMI_TRUE;
                is_matched = MMI_TRUE;
                if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
                    g_wlan_profile[j] == g_wlan_display_context.connected_wlan_profile)
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_ACTIVATE);
                    //system_print("---->And it's activated!!\n");
                    g_wizard_prfile_list[*se_sa_num].type = WLAN_MATCH_SE_SA_C;
                }
                (*se_sa_num)++;
            }
        }
        if (is_matched == MMI_FALSE)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_NOT_FOUND);
            // system_print("---->Not found!!!\n");
            g_wizard_se_temp_list[*se_num].p_se = &g_wlan_display_context.ap_list[i];
            g_wizard_se_temp_list[*se_num].p_sa = NULL;
            g_wizard_se_temp_list[*se_num].type = WLAN_MATCH_SE;
            g_wizard_se_temp_list[*se_num].priority = MAX_WLAN_DATA_ACCOUNT_NUM + 1;
            (*se_num)++;
        }
    }
    memcpy(&g_wizard_prfile_list[*se_sa_num], g_wizard_se_temp_list, (*se_num) * sizeof(mmi_wlan_wizard_list_struct));
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if (!g_wlan_profile[i]->is_search_matched)
        {
           MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SAVE_AP, g_wlan_profile[i]->ssid_len, g_wlan_profile[i]->profile_id);
           // system_print("---->Save(Not in scan result.) -- SSID's Length: %d Profile ID: %d \n", g_wlan_profile[i]->ssid_len, g_wlan_profile[i]->profile_id);
           g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].p_se = NULL;
           g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].p_sa = g_wlan_profile[i];
           g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].type = WLAN_MATCH_SA;
           g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].priority = i;

           if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
               g_wlan_profile[i] == g_wlan_display_context.connected_wlan_profile)
           {
               g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].type = WLAN_MATCH_SA_C;
           }
           (*sa_num)++;
        }
        else
        {
            g_wlan_profile[i]->is_search_matched = MMI_FALSE;
        }
    }

    g_wlan_display_context.total_ap_num = *se_sa_num + *se_num + *sa_num;
    /* Mark ap's manage type */
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SPERATOR);
    // system_print("=========================================================\n");
    for(i = 0; i< g_wlan_display_context.total_ap_num; i++)
    {
        if(WLAN_MATCH_SE == g_wizard_prfile_list[i].type)
        {
            bssinfo_to_profile(&g_profile_saved_temp, g_wizard_prfile_list[i].p_se, NULL, 0);
            if(mmi_wlan_is_default_trust_ap(&g_profile_saved_temp))
            {
                g_wizard_prfile_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_DEFAULT;
            }
            else
            {
                if(mmi_wlan_is_black_list_ap(&g_profile_saved_temp))
                {
                    g_wizard_prfile_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_BLACK_LIST;
                }
                else
                {
                    g_wizard_prfile_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_UNKNOWN;
                }
            }
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_AP_MATCH_TYPE, 
                            g_profile_saved_temp.ssid_len, 
                            g_wizard_prfile_list[i].ap_mgr_type,
                            g_wizard_prfile_list[i].type);
            
            /* system_print("SSID: %s \t MGR: %d Network: %d Match: %d Profile Id: %d\n",
                            g_profile_saved_temp.ssid, 
                            g_wizard_prfile_list[i].ap_mgr_type,
                            g_profile_saved_temp.network_type,
                            g_wizard_prfile_list[i].type,
                            g_profile_saved_temp.profile_id); */
        }
        else
        {
            if(mmi_wlan_is_default_trust_ap(g_wizard_prfile_list[i].p_sa))
            {
                g_wizard_prfile_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_DEFAULT;
            }
            else
            {
                if(g_wizard_prfile_list[i].p_sa->ap_type == SRV_DTCNT_WLAN_AP_BLACK_LIST)
                {
                    g_wizard_prfile_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_BLACK_LIST;
                }
                else
                {
                    g_wizard_prfile_list[i].ap_mgr_type = WLAN_AP_MGR_TYPE_USER_DEFINE;
                }
            }
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_AP_MATCH_TYPE, 
                            g_profile_saved_temp.ssid_len, 
                            g_wizard_prfile_list[i].ap_mgr_type,
                            g_wizard_prfile_list[i].type);
            
            /* system_print("SSID: %s \t MGR: %d Network: %d Match: %d Profile Id: %d\n",
                        g_wizard_prfile_list[i].p_sa->ssid, 
                        g_wizard_prfile_list[i].ap_mgr_type,
                        g_wizard_prfile_list[i].p_sa->network_type,
                        g_wizard_prfile_list[i].type,
                        g_wizard_prfile_list[i].p_sa->profile_id); */
        }
    }
    for(i = 0; i < g_wlan_display_context.total_ap_num; i++)
    {
        if(WLAN_AP_MGR_TYPE_DEFAULT == g_wizard_prfile_list[i].ap_mgr_type)
        {
            if(g_wizard_prfile_list[i].type == WLAN_MATCH_SE_SA || g_wizard_prfile_list[i].type == WLAN_MATCH_SE_SA_C)
            {
                default_se_sa_num++;
            }
            memcpy(&wlan_profile_temp, &g_wizard_prfile_list[i], sizeof(mmi_wlan_wizard_list_struct));
            for(j = i; j > index; j--)
            {
               memcpy(&g_wizard_prfile_list[j], &g_wizard_prfile_list[j-1], sizeof(mmi_wlan_wizard_list_struct)); 
            }
            memcpy(&g_wizard_prfile_list[index], &wlan_profile_temp, sizeof(mmi_wlan_wizard_list_struct));
            ++index;
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SPERATOR);
    // system_print("=========================================================\n");
}

void mmi_wlan_entry_trust_list(void)
{
    U8 pos, trust_ap_num, se_sa_num = 0, se_num = 0, sa_num = 0;
    U8 *guiBuffer = NULL;
    U16 icon_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_state[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];

    mmi_wlan_cmcc_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    for (pos = 0, trust_ap_num = 0; pos < g_wlan_display_context.total_ap_num; pos++)
    {
        // system_print("=================>MGR TYPE: %d<====================\n", g_wizard_prfile_list[pos].ap_mgr_type);
        if(g_wizard_prfile_list[pos].ap_mgr_type != WLAN_AP_MGR_TYPE_USER_DEFINE)
            continue;

        // system_print("=================>AP SSID: %s<====================\n", g_wizard_prfile_list[pos].p_sa->ssid);
        memset(subMenuData[trust_ap_num], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2cpy(
              (CHAR*)subMenuData[trust_ap_num],
              (const CHAR*)g_wizard_prfile_list[pos].p_sa->name);
        subMenuDataPtrs[trust_ap_num] = subMenuData[trust_ap_num];
        switch (g_wizard_prfile_list[pos].p_sa->network_type)
        {
            case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                icon_list[trust_ap_num] = IMG_ID_DTCNT_WLAN_ADHOC;
                break;
            case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                if(g_wizard_prfile_list[pos].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                   g_wizard_prfile_list[pos].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                {
                    icon_list[trust_ap_num] = IMG_ID_DTCNT_WLAN_STATION;
                }
                else
                {
                    icon_list[trust_ap_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                }
                break;
        }

        if(g_wlan_display_context.connected_wlan_profile &&
           g_wizard_prfile_list[pos].p_sa == g_wlan_display_context.connected_wlan_profile)
        {
            if (g_wlan_display_context.rssi > -60)
            {
                icon_state[trust_ap_num] = IMG_ID_DTCNT_WLAN_SIGNAL3;
            }
            else if (g_wlan_display_context.rssi > -70)
            {
                icon_state[trust_ap_num] = IMG_ID_DTCNT_WLAN_SIGNAL2;
            }
            else if (g_wlan_display_context.rssi > -80)
            {
                icon_state[trust_ap_num] = IMG_ID_DTCNT_WLAN_SIGNAL1;
            }
            else
            {
                icon_state[trust_ap_num] = IMG_ID_DTCNT_WLAN_SIGNAL0;
            }
        }
        else 
        {
            icon_state[trust_ap_num] = 0;
        }
        /* set index as position of ap in wizard display list */
        g_index_trust_list[trust_ap_num] = pos;
        ++trust_ap_num;
    }

    g_wlan_display_context.trust_list_num = trust_ap_num;
    /*if (!mmi_frm_is_in_backward_scenario())
    {
        mmi_wlan_delete_related_screen();
    }*/
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_TRUST_LIST,
            NULL,
            mmi_wlan_entry_trust_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    } 

    RegisterHighlightHandler(mmi_wlan_trust_list_highlight_hdlr);
    //if (g_wlan_display_context.wizard_profile_changed)
    //{
    //    guiBuffer = NULL;
    //    g_wlan_display_context.wizard_cur_profile_list_index = 0;
    //    g_wlan_display_context.wizard_profile_changed = MMI_FALSE;
    //}
    //else
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_TRUST_LIST);
    }
    
    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_TRUST_LIST,
        0,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        trust_ap_num,
        subMenuDataPtrs,
        (U16*) icon_list,
        icon_state,
        0, //g_wlan_display_context.wizard_cur_profile_list_index,
        guiBuffer,
        ICON_TEXT_ICON);        

    if(g_wlan_display_context.send_conn_req_ing == MMI_FALSE)
    {
	EnableLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        if(trust_ap_num > 0)
        {
            SetLeftSoftkeyFunction(mmi_wlan_entry_trust_list_option_full, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_wlan_entry_trust_list_option_empty, KEY_EVENT_UP);    
        }
    }
    else
    {
	DisableLeftSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);		
	ChangeCenterSoftkey(0, 0);
    }
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_wlan_entry_network_add, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

void mmi_wlan_trust_list_highlight_hdlr(S32 nIndex)
{
    g_wlan_display_context.trust_list_hilt_index = nIndex;
    g_wlan_display_context.trust_list_hilt_profile_p = 
        g_wizard_prfile_list[g_index_trust_list[nIndex]].p_sa;
}

void mmi_wlan_entry_trust_list_option_full(void)
{
    mmi_id trust_list_opt_cui_id;
    trust_list_opt_cui_id = cui_menu_create(
                                wlan_parent_group_id,
                                CUI_MENU_SRC_TYPE_RESOURCE, 
                                CUI_MENU_TYPE_OPTION, 
                                MENU_ID_WLAN_WIZARD_TRUST_LIST_OPT_1, 
                                MMI_TRUE, 
                                NULL);
    cui_menu_run(trust_list_opt_cui_id);        
    g_wlan_display_context.inline_trust_list_cui_id = trust_list_opt_cui_id;
}

void mmi_wlan_entry_trust_list_option_empty(void)
{
    mmi_id trust_list_opt_cui_id;
    trust_list_opt_cui_id = cui_menu_create(
                                wlan_parent_group_id,
                                CUI_MENU_SRC_TYPE_RESOURCE, 
                                CUI_MENU_TYPE_OPTION, 
                                MENU_ID_WLAN_WIZARD_TRUST_LIST_OPT_2,
                                MMI_TRUE, 
                                NULL);
    cui_menu_run(trust_list_opt_cui_id);        
    g_wlan_display_context.inline_trust_list_cui_id = trust_list_opt_cui_id;
}

void mmi_wlan_add_into_black_list_hdlr(void)
{
    U32 field;
	
    // If it's default trust ap, then cannot add it into black list
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA || 
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
        memcpy(&g_profile_saved_temp, g_wlan_display_context.active_wlan_profile_p, sizeof(mmi_wlan_profile_struct));
    }
    else if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE)
    {
        bssinfo_to_profile(&g_profile_saved_temp, g_wlan_display_context.active_ap, NULL, 0);
    }   

    // If it's default trust ap, then cannot add it into black list
    if(MMI_TRUE == mmi_wlan_is_default_trust_ap (&g_profile_saved_temp))
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERR_ADD_DEFAULT_AP_TO_BK)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
        return;
    }
    // If the count of black list ap reach maximum, quit
    if(NVRAM_MAX_CMCC_WIFI_BLACK_LIST_TOTAL == g_wlan_display_context.black_list_num)
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
    }
    /* Get highlighted item */
    memset(&g_profile_saved_temp, 0, sizeof(mmi_wlan_profile_struct));    
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA || 
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
        /* connected ap could not be added into black list */
        if(g_wlan_display_context.active_wlan_profile_p == g_wlan_display_context.connected_wlan_profile)
        {   
            mmi_popup_display_simple(
                (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CONNECTING_NO_DEL)), 
                MMI_EVENT_FAILURE, 
                wlan_parent_group_id, 
                NULL);
            return;
        }
	    g_wlan_display_context.active_wlan_profile_p->ap_type = SRV_DTCNT_WLAN_AP_BLACK_LIST;
	    field = SRV_DTCNT_WLAN_PROF_FIELD_AP_TYPE;
	    //field = SRV_DTCNT_WLAN_PROF_FIELD_ALL;
	    mmi_wlan_dtcnt_store_profile(g_wlan_display_context.active_wlan_profile_p,
				                     0, 
				                     field);  
    }
    else if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE)
    {
	g_wlan_display_context.keylen = 0;
	g_wlan_display_context.wapi_psk_format = 0;
		mmi_wlan_save_blacklist_ap(g_wlan_display_context.active_ap);
    }  
	g_wlan_display_context.black_list_num++;
}

void mmi_wlan_entry_black_list(void)
{
    U8  *guiBuffer = NULL;
    U8  index = 0;
    U8  i = 0;
    U16 icon_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_state[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];

    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_BLACK_LIST,
            NULL,
            mmi_wlan_entry_black_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(
        wlan_parent_group_id,
        SCR_ID_DTCNT_WLAN_BLACK_LIST);
    
    for(index = 0; index < g_wlan_display_context.prof_num; index++)
    {
        memset(&subMenuData[index], 0, MAX_SUB_MENU_SIZE);
        if(g_wlan_profile[index]->ap_type == SRV_DTCNT_WLAN_AP_BLACK_LIST)
        {
        mmi_ucs2cpy(
                  (CHAR*)subMenuData[index],
                  (CHAR*) g_wlan_profile[index]->name);
		  subMenuDataPtrs[i] = subMenuData[index];
        
	switch (g_wlan_profile[index]->network_type)
        {
            case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
                break;
            case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
	         if(g_wlan_profile[index]->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
	            g_wlan_profile[index]->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                {
	            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;
                }
                else
                {
	            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                }
                break;
        }
        icon_state[i++] = 0;
        }
    }
    
    RegisterHighlightHandler(mmi_wlan_black_list_highlight_hdlr);

    if(g_wlan_display_context.black_list_num > 0)
    {
        ShowCategory73Screen(
            STR_ID_DTCNT_WLAN_BLACK_LIST,
            0,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_wlan_display_context.black_list_num,
            (U8 **)subMenuDataPtrs,
            (U16*) icon_list,
            icon_state,
            0,
            guiBuffer,
            ICON_TEXT_ICON);

        SetLeftSoftkeyFunction(mmi_wlan_entry_black_list_option, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_wlan_remove_cur_ap_from_bk_list, KEY_EVENT_UP);
        SetKeyHandler(mmi_wlan_entry_black_list_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ShowCategory73Screen(
            STR_ID_DTCNT_WLAN_BLACK_LIST,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            (U8 **)subMenuDataPtrs,
            (U16*) icon_list,
            icon_state,
            0,
            guiBuffer,
            ICON_TEXT_ICON);
    }
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void mmi_wlan_black_list_highlight_hdlr(S32 nIndex)    
{
    g_wlan_display_context.black_list_hilt_index = nIndex;
}

void mmi_wlan_entry_black_list_option(void)
{
    mmi_id bk_opt_menu_id;

    bk_opt_menu_id = cui_menu_create(
                            wlan_parent_group_id,
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_WLAN_WIZARD_BLACK_LIST_OPT, 
                            MMI_TRUE, 
                            NULL);
    cui_menu_run(bk_opt_menu_id);    
                        
}

void mmi_wlan_remove_cur_ap_from_bk_list(void)
{
    U8 index = 0, i = 0;
    for(index = 0; index < g_wlan_display_context.prof_num; index++)
    {
        if(g_wlan_profile[index]->ap_type == SRV_DTCNT_WLAN_AP_BLACK_LIST)
        {
            if(i == g_wlan_display_context.black_list_hilt_index)
            {
	        break;
            }
	    i++;
        }
    }
    mmi_wlan_delete_profile (g_wlan_profile[index]);
    g_wlan_display_context.black_list_num--;
    mmi_popup_display_simple(
			(WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DELETED)), 
			MMI_EVENT_SUCCESS, 
			wlan_parent_group_id, 
			NULL);

}

void mmi_wlan_remove_all_ap_from_bk_list(void)
{
    U8 index = 0;
    for(index = 0; index < g_wlan_display_context.prof_num; )
    {

        if(g_wlan_profile[index]->ap_type == SRV_DTCNT_WLAN_AP_BLACK_LIST)
        {
            mmi_wlan_delete_profile (g_wlan_profile[index]);
        }
		else
		{
			index ++;
		}
    }
    g_wlan_display_context.black_list_num = 0;
}

/******************************************************************************/
/**         CMCC WiFi Find Specific AP                                       **/
/**         Author: Yunpeng Li                                               **/
/**         Date: 2010-9-08                                                  **/
/******************************************************************************/
void mmi_wlan_entry_find_specific_ap_scr(void)
{
    g_wlan_display_context.wlan_find_ap_setting_cui_id = cui_inline_create(
                            wlan_parent_group_id,
                            &g_find_ap_inline_struct);

    cui_inline_run (g_wlan_display_context.wlan_find_ap_setting_cui_id);
}

void mmi_wlan_entry_find_result_list(void)
{
    U8 ssid[SRV_DTCNT_PROF_MAX_SSID_LEN + 1];
    U8 i, ap_list_num, found_num = 0,  se_sa_num = 0, se_num = 0, sa_num = 0;
    U8 *guiBuffer = NULL;
    U16 icon_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 iconStates[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_convert_ucs_to_utf8 (
        (const char *) g_wlan_display_context.find_ap_ssid, 
        (char *) ssid, 
        SRV_DTCNT_PROF_MAX_SSID_LEN + 1);
    // Todo: verify that ssid is not empty string
    
    mmi_wlan_cmcc_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    
    ap_list_num = se_num + sa_num + se_sa_num;
    for (i = 0; i < ap_list_num; i++)
    {
        if(g_wizard_prfile_list[i].ap_mgr_type == WLAN_AP_MGR_TYPE_BLACK_LIST)
            continue;

        // Record index of ap in g_wizard_profile_list
        memset(subMenuData[found_num], 0, MAX_SUB_MENU_SIZE);
        switch (g_wizard_prfile_list[i].type)
        {
            case WLAN_MATCH_SE_SA_C:
            case WLAN_MATCH_SE_SA:
            {
                if(strstr((const char*)g_wizard_prfile_list[i].p_sa->ssid, 
                            (const char*)ssid) != NULL)
                {
                    g_index_result_list[found_num] = i;
                    mmi_ucs2cpy(
                          (CHAR*)subMenuData[found_num],
                          (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                    subMenuDataPtrs[found_num] = subMenuData[found_num];
                    switch (g_wizard_prfile_list[i].p_se->network_type)
                    {
                        case WNDRV_SUPC_NETWORK_IBSS:
                            icon_list[found_num] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                            break;
                        default:
                            if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                                g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                                g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                            {
                                icon_list[found_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                            }
                            else
                            {
                                icon_list[found_num] = IMG_ID_DTCNT_WLAN_STATION_S;
                            }
                            break;
                    }
                    if (g_wizard_prfile_list[i].type == WLAN_MATCH_SE_SA)
                    {
                        if (g_wizard_prfile_list[i].p_se->rssi > -60)
                        {
                            iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                        }
                        else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                        {
                            iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                        }
                        else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                        {
                            iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL1;
                        }
                        else
                        {
                            iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL0;
                        }
                    }
                    else 
                    {
                        if (g_wizard_prfile_list[i].p_se->rssi > -60)
                        {
                            iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                        }
                        else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                        {
                            iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL2_CONNECTED;
                        }
                        else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                        {
                            iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL1_CONNECTED;
                        }
                        else
                        {
                            iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL0_CONNECTED;
                        }                    
                    }
                    found_num++;
                }
                break;
            }
            case WLAN_MATCH_SE:
            {
                if(strstr((const char*)g_wizard_prfile_list[i].p_se->ssid, 
                        (const char*)ssid) != NULL)
                {
                    g_index_result_list[found_num] = i;
                    custom_wlan_ssid_convert(
                            (const char*) g_wizard_prfile_list[i].p_se->ssid, 
                            (char*) subMenuData[found_num], 
                            g_wizard_prfile_list[i].p_se->ssid_len);
                    subMenuDataPtrs[found_num] = subMenuData[found_num];
                    switch (g_wizard_prfile_list[i].p_se->network_type)
                    {
                        case WNDRV_SUPC_NETWORK_IBSS:
                            icon_list[found_num] = IMG_ID_DTCNT_WLAN_ADHOC;
                            break;
                        default:
                            if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                                g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                                g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                            {
                                icon_list[found_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                            }
                            else
                            {
                                icon_list[found_num] = IMG_ID_DTCNT_WLAN_STATION;
                            }
                            break;
                    }
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                    {
                        iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL1;
                    }
                    else
                    {
                        iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL0;
                    }
                    found_num++;
                }
                break;
            }
            case WLAN_MATCH_SA:
            {
                if(strstr((const char*)g_wizard_prfile_list[i].p_sa->ssid, 
                            (const char*)ssid) != NULL)
                {
                    g_index_result_list[found_num] = i;
                    mmi_ucs2cpy(
                          (CHAR*)subMenuData[found_num],
                          (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                    subMenuDataPtrs[found_num] = subMenuData[found_num];
                    switch (g_wizard_prfile_list[i].p_sa->network_type)
                    {
                        case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                            icon_list[found_num] = IMG_ID_DTCNT_WLAN_ADHOC;
                            break;
                        case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                            if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                               g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                            {
                                icon_list[found_num] = IMG_ID_DTCNT_WLAN_STATION;
                            }
                            else
                            {
                                icon_list[found_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                            }
                            break;
                    }
                    iconStates[found_num] = 0;
                    found_num++;
                }
                break;
            }
            case WLAN_MATCH_SA_C:
            {
                if(strstr((const char*)g_wizard_prfile_list[i].p_sa->ssid, 
                            (const char*)ssid) != NULL)
                {
                    g_index_result_list[found_num] = i;
                    mmi_ucs2cpy(
                          (CHAR*)subMenuData[found_num],
                          (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                    subMenuDataPtrs[found_num] = subMenuData[found_num];
                    switch (g_wizard_prfile_list[i].p_sa->network_type)
                    {
                        case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                            icon_list[found_num] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                            break;
                        case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                            if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                               g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                            {
                                icon_list[found_num] = IMG_ID_DTCNT_WLAN_STATION_S;
                            }
                            else 
                            {
                                icon_list[found_num] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                            }
                            break;
                    }
                    iconStates[found_num] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    found_num++;
                }
                break;
            } 
        } /* end of switch */
    } /* end of for */
    // g_wlan_display_context.display_ap_num = visual_num;
    
    /*if (!mmi_frm_is_in_backward_scenario())
    {
        mmi_wlan_delete_related_screen();
    }*/
    
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_EMPTY,
            NULL, //mmi_wlan_exit_new_wizard_list,
            mmi_wlan_entry_find_result_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    } 

    RegisterHighlightHandler(mmi_wlan_find_result_list_highlight_hdlr);
    /*if (g_wlan_display_context.wizard_profile_changed)
    {
        guiBuffer = NULL;
        g_wlan_display_context.wizard_cur_profile_list_index = 0;
        g_wlan_display_context.wizard_profile_changed = MMI_FALSE;
    }
    else
    {*/
        guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_EMPTY);
    //}

    
    if (found_num)
    {
        ShowCategory73Screen(
            STR_ID_DTCNT_WLAN_FIND_AP,
            0,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            found_num,
            subMenuDataPtrs,
            (U16*) icon_list,
            iconStates,
            0,
            guiBuffer,
            ICON_TEXT_ICON);
        SetLeftSoftkeyFunction(mmi_wlan_entry_find_result_list_opt, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory73Screen(
            STR_ID_DTCNT_WLAN_FIND_AP,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            found_num,
            subMenuDataPtrs,
            (U16*) icon_list,
            iconStates,
            g_wlan_display_context.find_res_list_hilt_index,
            guiBuffer,
            ICON_TEXT_ICON);
    }
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
	g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_wlan_entry_network_disconnect, KEY_EVENT_UP);
    }
    else
    {
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_wlan_entry_wizard_connect, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

void mmi_wlan_find_result_list_highlight_hdlr(S32 nIndex)
{
    U8 pos;
    
    g_wlan_display_context.find_res_list_hilt_index = nIndex;
    pos = g_index_result_list[(U8)g_wlan_display_context.find_res_list_hilt_index];

    g_wlan_display_context.wizard_list_option = g_wizard_prfile_list[pos].type;
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA || 
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
        g_wlan_display_context.active_wlan_profile_p = g_wizard_prfile_list[pos].p_sa;
        g_wlan_display_context.active_wlan_profile_index = g_wizard_prfile_list[pos].priority;
    }
    else if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE)
    {
        g_wlan_display_context.active_ap = g_wizard_prfile_list[pos].p_se;
    }
}

void mmi_wlan_entry_find_result_list_opt(void)
{
    mmi_id res_opt_cui_id;

    res_opt_cui_id = cui_menu_create(
                        wlan_parent_group_id, 
                        CUI_MENU_SRC_TYPE_APPCREATE, 
                        CUI_MENU_TYPE_OPTION, 
                        MENU_ID_WLAN_FIND_RESULT_LIST_OPT, 
                        MMI_FALSE, 
                        NULL);

    cui_menu_run(res_opt_cui_id);
    g_wlan_display_context.inline_find_ap = res_opt_cui_id;
}

void mmi_wlan_build_find_result_list_opt(cui_menu_event_struct *menu_evt)
{
    mmi_menu_id find_res_list_menu_ids[2];
    
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
        find_res_list_menu_ids[0] = MENU_ID_WLAN_WIZARD_LIST_OPT_DISCONNECT;
        find_res_list_menu_ids[1] = MENU_ID_WLAN_WIZARD_LIST_OPT_DETAILS;
    }
    else
    {
        find_res_list_menu_ids[0] = MENU_ID_WLAN_WIZARD_LIST_OPT_CONNECT;
        find_res_list_menu_ids[1] = MENU_ID_WLAN_WIZARD_LIST_OPT_DETAILS;
    }
    cui_menu_set_currlist (menu_evt->sender_id, 2, find_res_list_menu_ids);
    cui_menu_set_item_string (menu_evt->sender_id, MENU_ID_WLAN_WIZARD_LIST_OPT_CONNECT, (WCHAR *)GetString(STR_GLOBAL_CONNECT));
    cui_menu_set_item_string (menu_evt->sender_id, MENU_ID_WLAN_WIZARD_LIST_OPT_DISCONNECT, (WCHAR *)GetString(STR_GLOBAL_DISCONNECT));
    cui_menu_set_item_string (menu_evt->sender_id, MENU_ID_WLAN_WIZARD_LIST_OPT_DETAILS, (WCHAR *)GetString(STR_GLOBAL_DETAILS));
}

// New version of details info for each ap
void mmi_wlan_entry_ap_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_CONN_STATUS,
            NULL,
            mmi_wlan_entry_ap_details,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    // update current ap's details information
    mmi_wlan_update_ap_details_info();

    guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_CONN_STATUS);
    ShowCategory74Screen(
        STR_ID_DTCNT_WLAN_CONN_STATUS,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

void mmi_wlan_update_ap_details_info(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_UPDATE_AP_DETAILS_INFO, g_wlan_display_context.wizard_list_option);
    if(g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE)
    {
        memset(&g_profile_saved_temp, 0, sizeof(mmi_wlan_profile_struct));
        bssinfo_to_profile(&g_profile_saved_temp, g_wlan_display_context.active_ap, NULL, 0);
        mmi_wlan_get_ap_details_info(&g_profile_saved_temp);
    }
    else
    {
        mmi_wlan_get_ap_details_info(g_wlan_display_context.active_wlan_profile_p);
    }
}

void mmi_wlan_get_ap_details_info(mmi_wlan_profile_struct* profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    U8 *info;
    srv_dtcnt_wlan_status_enum wlan_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_status = srv_dtcnt_wlan_status();
    info = (PU8) subMenuData;

    /* MAC ADDRESS */
    mmi_ucs2cpy((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_PHONE_MAC));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
    if (wlan_status != SRV_DTCNT_WLAN_STATUS_INACTIVE)
    {
        sprintf(
            tempBuf,
            "%02x:%02x:%02x:%02x:%02x:%02x\n\n",
            g_wlan_display_context.mac_addr[0],
            g_wlan_display_context.mac_addr[1],
            g_wlan_display_context.mac_addr[2],
            g_wlan_display_context.mac_addr[3],
            g_wlan_display_context.mac_addr[4],
            g_wlan_display_context.mac_addr[5]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
    }
    else
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
    }

    /* SSID */
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SSID));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*) L"\n");
    memset(tempBufUnicode, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
    custom_wlan_ssid_convert(
        (const char*) profile->ssid, 
        (char*) tempBufUnicode, 
        profile->ssid_len);
    mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");

    /* NETWORK TYPE */
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
    switch(profile->network_type)
    {
        case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA));
            break;
        case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC));
            break;
    }
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
    
    /* SECURITY MODE */
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");

    switch(profile->auth_mode)
    {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN));
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_SHARED));
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_IEEE8021X));
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_ONLY));
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY));
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
            if(profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
            {
                mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPANONE));
            }
            else 
            {
                mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK));
            }
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK));
            break;
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
#endif            
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
         case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPICERT));
            break;
         case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPIPSK));
            break;
#endif 
#endif
    }
    mmi_ucs2cat((CHAR*)info,   (const CHAR*)L"\n\n");

    /* ENCRYPTION MODE */
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");

    switch(profile->encrypt_mode)
    {
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_NONE));
            break;
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_WEP));
            break;
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_TKIP));
            break;
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_AES:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_AES));
            break;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_WPI));
            break;
#endif 
#endif      
    }
    mmi_ucs2cat((CHAR*)info,   (const CHAR*)L"\n\n");

    /* NETWORK STAUTS FOR CONNECTED ACCESS PIONT */
    if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
        profile == g_wlan_display_context.connected_wlan_profile)
    {
        /* SSID */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"BSSID");
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        sprintf(tempBuf, "%02x:%02x:%02x:%02x:%02x:%02x\n\n", 
            g_wlan_display_context.bssid[0], 
            g_wlan_display_context.bssid[1],
            g_wlan_display_context.bssid[2], 
            g_wlan_display_context.bssid[3], 
            g_wlan_display_context.bssid[4],
            g_wlan_display_context.bssid[5]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, tempBufUnicode);
        /* CHANNEL */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_CHANNEL));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)  L"\n");
        sprintf(tempBuf, "%d\n\n", g_wlan_display_context.curr_channel_number);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        /* SIGNAL STRENGTH */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_STRENGTH));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        if (g_wlan_display_context.rssi > -40)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL0));
        }
        else if (g_wlan_display_context.rssi > -60)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL1));
        }
        else if (g_wlan_display_context.rssi > -70)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL2));
        }
        else if (g_wlan_display_context.rssi > -80)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL3));
        }
        else
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL4));
        }
        mmi_ucs2cat((CHAR*)info,   (const CHAR*)L"\n\n");
        /* LINK SPEED */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_LINK_SPEED));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        sprintf(tempBuf, "%d Mbit/s\n\n", g_wlan_display_context.current_data_rate / 2);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        /* IP ADDR */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_IPADDR));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n\n",
            g_wlan_display_context.curr_ip_addr[0],
            g_wlan_display_context.curr_ip_addr[1],
            g_wlan_display_context.curr_ip_addr[2],
            g_wlan_display_context.curr_ip_addr[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        /* NETMASK */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETMASK));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info,   (const CHAR*)L"\n");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n\n",
            g_wlan_display_context.curr_netmask[0],
            g_wlan_display_context.curr_netmask[1],
            g_wlan_display_context.curr_netmask[2],
            g_wlan_display_context.curr_netmask[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        /* GATEWAY */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_GATEWAY));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n\n",
            g_wlan_display_context.curr_gateway[0],
            g_wlan_display_context.curr_gateway[1],
            g_wlan_display_context.curr_gateway[2],
            g_wlan_display_context.curr_gateway[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        /* Primary DNS */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_DNS1));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n\n",
            g_wlan_display_context.curr_dns1[0],
            g_wlan_display_context.curr_dns1[1],
            g_wlan_display_context.curr_dns1[2],
            g_wlan_display_context.curr_dns1[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        /* Secondary DNS */
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_DNS2));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
        sprintf(
            tempBuf,
            "%d.%d.%d.%d\n",
            g_wlan_display_context.curr_dns2[0],
            g_wlan_display_context.curr_dns2[1],
            g_wlan_display_context.curr_dns2[2],
            g_wlan_display_context.curr_dns2[3]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
    }
}

/* after connect to one default ap successfully, then adjust its priority to the highest */
void mmi_wlan_adjust_default_ap_priority(void)
{
    U8 index;
    U8 totalDefaultAp = 0;
    U8 originalPriority = 0;
    U8 newPriority = 0;
    
    for(index = 0; index < g_wlan_display_context.prof_num; index++)
    {
        // count the total of default ap
        if(mmi_wlan_is_default_trust_ap (&g_wlan_prof_list[index]))
        {
            originalPriority = g_wlan_prof_list[index].priority;
            newPriority = ++totalDefaultAp;
            mmi_wlan_cmcc_change_priority(originalPriority, newPriority);
        }
    }
}

void mmi_wlan_cmcc_change_priority(U8 old_priority, U8 new_priority)
{
    U8 index = 0;

    if(old_priority == new_priority)
    {
        return;
    }
    
    for (index = 0; index < MAX_WLAN_DATA_ACCOUNT_NUM; index++)
    {
        if (g_wlan_prof_list[index].priority == 0)
        {
            continue;
        }

        if (g_wlan_prof_list[index].priority >= new_priority && g_wlan_prof_list[index].priority < old_priority)
        {
            g_wlan_prof_list[index].priority++;
            mmi_wlan_update_profile_in_db(&(g_wlan_prof_list[index]));

        }
        else if (g_wlan_prof_list[index].priority <= new_priority && g_wlan_prof_list[index].priority > old_priority)
        {
            g_wlan_prof_list[index].priority--;

            ASSERT(g_wlan_prof_list[index].priority > 0);
            mmi_wlan_update_profile_in_db(&(g_wlan_prof_list[index]));
        }
        else if (g_wlan_prof_list[index].priority == old_priority)
        {
            g_wlan_prof_list[index].priority = new_priority;
            mmi_wlan_update_profile_in_db(&(g_wlan_prof_list[index]));
        }
        g_wlan_profile[g_wlan_prof_list[index].priority - 1] = &g_wlan_prof_list[index];
    }
}

void mmi_wlan_update_profile_in_db(mmi_wlan_profile_struct* app_prof)
{
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_data_struct wlan_prof_data;

    memset(&g_srv_wlan_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));
    mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, app_prof, 0);
    wlan_prof_data.prof_data = &g_srv_wlan_prof;
    wlan_prof_data.prof_fields = SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY;
    wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

    result =  srv_dtcnt_store_update_prof(g_srv_wlan_prof.profile_id, &wlan_prof_data);

    if (result != SRV_DTCNT_RESULT_SUCCESS) 
    {
        ASSERT(0);
    }
}

void mmi_wlan_update_settings_in_db(void)
{
    mmi_wlan_auto_search_struct* setting;
    
    setting = OslMalloc(sizeof(mmi_wlan_auto_search_struct));
    memset(setting, 0, sizeof(mmi_wlan_auto_search_struct));
    
    setting->auto_search_interval = g_wlan_display_context.auto_search_interval;
    setting->is_auto_search = g_wlan_display_context.is_auto_search;
    setting->is_auto_conn = g_wlan_display_context.is_auto_conn;
    setting->network_switch = g_wlan_display_context.network_switch_idx;
    setting->is_ssid_switch = g_wlan_display_context.is_ssid_switch;
    setting->cellular_switch = g_wlan_display_context.cellular_switch_idx;
    setting->auto_portal_switch = g_wlan_display_context.auto_portal_switch_idx;
    setting->power_saving_mode = g_wlan_display_context.power_saving_mode;
    
    mmi_wlan_storage_save_auto_searching_setting(
        1, 
        setting);
    
    OslMfree(setting);
    setting = NULL;

}

void mmi_wlan_storage_save_black_list(U16 recordId, void* data)
{
    S16 error = 0;
    S32 size;
    mmi_wlan_black_list_struct* profile = (mmi_wlan_black_list_struct*)data;

    size = WriteRecord(
                NVRAM_EF_CMCC_WIFI_BLACK_LIST_LID, 
                recordId, 
                (void*)data, 
                NVRAM_MAX_CMCC_WIFI_BLACK_LIST_SIZE, 
                (S16 *)&error);

    if(size < NVRAM_MAX_CMCC_WIFI_BLACK_LIST_SIZE)
    {
        MMI_ASSERT(0);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_STORAGE_SAVE_BLACK_LIST, 
            recordId, profile->ssid_len, profile->is_in_black_list);
    }
}

void mmi_wlan_storage_save_auto_searching_setting(U16 recordId, mmi_wlan_auto_search_struct* setting)
{
    S16 error = 0;
    S32 size;
    
    size = WriteRecord(
                NVRAM_EF_CMCC_WIFI_SETTING_LID, 
                recordId, 
                (void*)setting, 
                NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, 
                (S16 *)&error);

    if(size < NVRAM_MAX_CMCC_WIFI_SETTING_SIZE)
    {
        MMI_ASSERT(0);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_STORAGE_SAVE_AUTO_SEARCH, 
            setting->is_auto_search, setting->auto_search_interval,
            setting->is_auto_conn, setting->network_switch,
            setting->is_ssid_switch, setting->cellular_switch, setting->auto_portal_switch,
            setting->power_saving_mode);
    }
    
}


void mmi_wlan_storage_read_auto_searching_setting(U16 recordId)
{
    S16     error = 0;
    mmi_wlan_auto_search_struct* setting;

    setting = OslMalloc(sizeof(mmi_wlan_auto_search_struct));
    memset(setting, 0, sizeof(mmi_wlan_auto_search_struct));    

    ReadRecord (
                NVRAM_EF_CMCC_WIFI_SETTING_LID, 
                recordId, 
                setting, 
                NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, 
                (S16*)&error);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_STORAGE_READ_AUTO_SEARCH, 
            setting->is_auto_search, setting->auto_search_interval,
            setting->is_auto_conn, setting->network_switch,
            setting->is_ssid_switch, setting->cellular_switch, setting->auto_portal_switch,
            setting->power_saving_mode);
    
    g_wlan_display_context.is_auto_search = setting->is_auto_search;
    g_wlan_display_context.auto_search_interval = setting->auto_search_interval;
    g_wlan_display_context.is_auto_conn = setting->is_auto_conn;
    g_wlan_display_context.network_switch_idx = setting->network_switch;
    g_wlan_display_context.is_ssid_switch = setting->is_ssid_switch;
    g_wlan_display_context.cellular_switch_idx = setting->cellular_switch;
    g_wlan_display_context.auto_portal_switch_idx = setting->auto_portal_switch;
    g_wlan_display_context.power_saving_mode = (mmi_wlan_power_saving_mode_enum)setting->power_saving_mode;

    switch(g_wlan_display_context.auto_search_interval)
    {
    case AUTO_SEARCH_DELAY_TEN_SECS:
        g_wlan_display_context.auto_search_interval_idx = 0;
        break;
    case AUTO_SEARCH_DELAY_HALF_MIN:
        g_wlan_display_context.auto_search_interval_idx = 1;
        break;
    case AUTO_SEARCH_DELAY_ONE_MIN:
        g_wlan_display_context.auto_search_interval_idx = 2;
        break;
    default:
        // For the first time, the interval value is incorrect, ajust the value and save them into NVRAM
        g_wlan_display_context.is_auto_search = MMI_FALSE;
        g_wlan_display_context.auto_search_interval = AUTO_SEARCH_DELAY_HALF_MIN;
        g_wlan_display_context.auto_search_interval_idx = 0;
        g_wlan_display_context.is_auto_conn = MMI_FALSE;
        g_wlan_display_context.is_ssid_switch = MMI_FALSE;
        g_wlan_display_context.network_switch_idx = 0;
        g_wlan_display_context.cellular_switch_idx = 0;
        g_wlan_display_context.auto_portal_switch_idx = 0;

        mmi_wlan_update_settings_in_db ();
        break;
    }

    OslMfree(setting);
    setting = NULL;
}

/******************************************************************************/
/**         CMCC WiFi Auto Connect                                           **/
/**         Author: Yunpeng Li                                               **/
/**         Date: 2011-2-26                                                  **/
/******************************************************************************/
void mmi_wlan_auto_conn_trigger_by_init (void)
{
    U32 scan_job_id = 0;
    srv_dtcnt_wlan_status_enum wlan_status;
        
    wlan_status = srv_dtcnt_wlan_status();
    if(wlan_status != SRV_DTCNT_WLAN_STATUS_ACTIVE)
    {
        return;
    }

    // send scan request to data account service
    scan_job_id = srv_dtcnt_wlan_scan(mmi_wlan_auto_conn_scan_result_cb, NULL);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_RESELECT_SCAN_JOB, scan_job_id);
}

void mmi_wlan_auto_conn_scan_result_cb(U32 job_id, void *user_data, srv_dtcnt_wlan_scan_result_struct *scan_res)
{
    MMI_BOOL is_found = MMI_FALSE;
    U8 index = 0, pos = 0;
    supc_abm_bss_info_struct* bss_info_p;
    
    // reset index and total
    g_auto_conn_ap_idx = 0;
    g_auto_conn_ap_total = 0;
    g_auto_conn_saved_ap_total = 0;
    g_auto_conn_search_ap_total = 0;
    
    for (index = 0; index < scan_res->ap_list_num && index < WNDRV_MAX_SCAN_RESULTS_NUM; index++)
    {
        if (scan_res->ap_list[index]->ssid_len == 0 || scan_res->ap_list[index]->ssid[0] == 0)
        {
            continue;   /* Discard hidden AP */
        }
        
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        if (MMI_TRUE == g_wapi_test_mode && 
            (TRUE == scan_res->ap_list[index]->rsn_ie_info_p ||
             TRUE == scan_res->ap_list[index]->wpa_ie_info_p ||
             (scan_res->ap_list[index]->privacy > 0 && FALSE == scan_res->ap_list[index]->wapi_ie_info_p)))
        {
            continue;   /* Discard hidden AP */
        }                
#endif /* __MMI_HIDE_WAPI__ */
#endif
        // 1. SE_SA
        // 2. RSSI > -85dbm
        // 3. Not in the black list
        if(scan_res->ap_list[index]->rssi > -85)
        {
            is_found = MMI_FALSE;
            bss_info_p = (supc_abm_bss_info_struct*)scan_res->ap_list[index];
            memset(&g_profile_saved_temp, 0, sizeof(mmi_wlan_profile_struct));
            bssinfo_to_profile(&g_profile_saved_temp, bss_info_p, NULL, 0);
            for(pos = 0; pos < g_wlan_display_context.prof_num; pos++)
            {
                if (mmi_wlan_is_same_ap (g_wlan_profile[pos], &g_profile_saved_temp))
                {
                    // found in the profile list, check whether it existed in the black list or not
                    if(MMI_FALSE == mmi_wlan_is_black_list_ap(g_wlan_profile[pos]))
                    {
                        // add it into auto connect list
                        g_auto_conn_saved_list[g_auto_conn_saved_ap_total++] = g_wlan_profile[pos];
                        is_found = MMI_TRUE;
                        break;
                    }
                }
            }/* end of for */
    
            /* not in saved ap list, then judge whether it's default trust ap */
            if((MMI_FALSE == is_found) && 
               mmi_wlan_is_default_trust_ap (&g_profile_saved_temp))
            {
                memset(&g_auto_conn_search_list[g_auto_conn_search_ap_total], 0, sizeof(supc_abm_bss_info_struct));
                memcpy(
                    &(g_auto_conn_search_list[g_auto_conn_search_ap_total]),
                    bss_info_p,
                    sizeof(supc_abm_bss_info_struct));
                ++g_auto_conn_search_ap_total;
            }
        }
        
    }/* end of for */

    mmi_wlan_auto_conn_prepare ();
}

void mmi_wlan_auto_conn_trigger_by_scan (void)
{
    MMI_BOOL is_found = MMI_FALSE;
    U8 index = 0, pos = 0;
    supc_abm_bss_info_struct* bss_info_p;
    
    // reset index and total
    g_auto_conn_ap_idx = 0;
    g_auto_conn_ap_total = 0;
    g_auto_conn_saved_ap_total = 0;
    g_auto_conn_search_ap_total = 0;
    
    for (index = 0; index < g_wlan_display_context.ap_list_num; index++)
    {
        // 1. SE_SA
        // 2. RSSI > -85dbm
        // 3. Not in the black list
        if(g_wlan_display_context.ap_list[index].rssi > -85)
        {
            is_found = MMI_FALSE;
            bss_info_p = &g_wlan_display_context.ap_list[index];
            memset(&g_profile_saved_temp, 0, sizeof(mmi_wlan_profile_struct));
            bssinfo_to_profile(&g_profile_saved_temp, bss_info_p, NULL, 0);
            for(pos = 0; pos < g_wlan_display_context.prof_num; pos++)
            {
                if (mmi_wlan_is_same_ap (g_wlan_profile[pos], &g_profile_saved_temp))
                {
                    // found in the profile list, check whether it existed in the black list or not
                    if(MMI_FALSE == mmi_wlan_is_black_list_ap(g_wlan_profile[pos]))
                    {
                        // add it into auto connect list
                        g_auto_conn_saved_list[g_auto_conn_saved_ap_total++] = g_wlan_profile[pos];
                        is_found = MMI_TRUE;
                        break;
                    }
                }
            }/* end of for */

            /* not in saved ap list, then judge whether it's default trust ap */
            if((MMI_FALSE == is_found) && 
               mmi_wlan_is_default_trust_ap (&g_profile_saved_temp))
            {
                memset(&g_auto_conn_search_list[g_auto_conn_search_ap_total], 0, sizeof(supc_abm_bss_info_struct));
                memcpy(
                    &(g_auto_conn_search_list[g_auto_conn_search_ap_total]),
                    bss_info_p,
                    sizeof(supc_abm_bss_info_struct));
                ++g_auto_conn_search_ap_total;
            }
        }
        
    }/* end of for */

    mmi_wlan_auto_conn_prepare ();
}

void mmi_wlan_auto_conn_prepare (void)
{
    MMI_BOOL is_modified = MMI_FALSE;
    U8 index = 0, pos = 0;
    mmi_wlan_profile_struct* temp;
    
    // arrange the selection list according to priority
    for(index = g_auto_conn_saved_ap_total; index > 0; index--)
    {
        for(pos = 1; pos < index; pos++)
        {
            if(g_auto_conn_saved_list[pos]->priority < g_auto_conn_saved_list[pos - 1]->priority)
            {
                temp = g_auto_conn_saved_list[pos];
                g_auto_conn_saved_list[pos] = g_auto_conn_saved_list[pos - 1];
                g_auto_conn_saved_list[pos - 1] = temp;

                is_modified = MMI_TRUE;
            }   
        }

        if(MMI_FALSE == is_modified)
        {
            break;
        }
        else
        {
            is_modified = MMI_FALSE;
        }
    }

    // Copy them into auto connect list
    for(index = 0; index < g_auto_conn_search_ap_total; index++)
    {
        if((g_auto_conn_search_list[index].ssid_len == 4) &&
           (strncmp((const char*)g_auto_conn_search_list[index].ssid, (const char*)default_ap_str, 4) == 0) )
        {
            memset(&g_auto_conn_list[g_auto_conn_ap_total], 0, sizeof(mmi_wlan_auto_conn_list_struct));
            memcpy(
                &(g_auto_conn_list[g_auto_conn_ap_total].search_ap_p),
                &g_auto_conn_search_list[index],
                sizeof(supc_abm_bss_info_struct));
            g_auto_conn_list[g_auto_conn_ap_total].is_saved = MMI_FALSE;
            ++g_auto_conn_ap_total;
        }   
    }

    for(index = 0; index < g_auto_conn_search_ap_total; index++)
    {
        if((g_auto_conn_search_list[index].ssid_len == 8) &&
           (strncmp((const char*)g_auto_conn_search_list[index].ssid, (const char*)default_ap_edu_str, 8) == 0) )
        {
            memset(&g_auto_conn_list[g_auto_conn_ap_total], 0, sizeof(mmi_wlan_auto_conn_list_struct));
            memcpy(
                &(g_auto_conn_list[g_auto_conn_ap_total].search_ap_p),
                &g_auto_conn_search_list[index],
                sizeof(supc_abm_bss_info_struct));
            g_auto_conn_list[g_auto_conn_ap_total].is_saved = MMI_FALSE;
            ++g_auto_conn_ap_total;
        }   
    }

    for(index = 0; index < g_auto_conn_saved_ap_total; index++)
    {
        memset(&g_auto_conn_list[g_auto_conn_ap_total], 0, sizeof(mmi_wlan_auto_conn_list_struct));
        g_auto_conn_list[g_auto_conn_ap_total].saved_ap_p = g_auto_conn_saved_list[index];
        g_auto_conn_list[g_auto_conn_ap_total].is_saved = MMI_TRUE;
        ++g_auto_conn_ap_total;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_CONN_START, 
                        g_wlan_display_context.ap_list_num, g_auto_conn_ap_total);
    
    if(g_auto_conn_ap_total > 0)
    {
        mmi_wlan_auto_conn_run();
    }
    else
    {
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    }
}

void mmi_wlan_auto_conn_run (void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_CONN_RUN, g_auto_conn_ap_idx, g_auto_conn_ap_total);
    if(g_auto_conn_ap_idx < g_auto_conn_ap_total)
    {
        mmi_wlan_auto_conn_proc(g_auto_conn_ap_idx);
        ++g_auto_conn_ap_idx;
    }
}

void mmi_wlan_auto_conn_proc(U16 index)
{
    mmi_wlan_profile_struct *prof = NULL;

    if(g_auto_conn_list[index].is_saved)
    {
        g_wlan_display_context.search_connect_need_save = MMI_FALSE;
        g_wlan_display_context.active_wlan_profile_p = g_auto_conn_list[index].saved_ap_p;
        prof = g_wlan_display_context.active_wlan_profile_p;
    }
    else
    {
        g_wlan_display_context.search_connect_need_save = MMI_TRUE;
        memcpy(&g_wlan_hilt_profile, &(g_auto_conn_list[index].search_ap_p), sizeof(supc_abm_bss_info_struct));
        memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
        prof = &g_wlan_display_context.temp_profile;
        bssinfo_to_profile(prof, &g_wlan_hilt_profile, NULL, 0);
    }
    prof->always_ask_connect_flag = MMI_FALSE;
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_CONN_PROC, prof->profile_id, prof->ssid_len, prof->priority);
    mmi_wlan_send_connect_request(prof);
    
    if(!prof->use_dhcp)
    {        
        memcpy(g_wlan_display_context.curr_ip_addr, prof->ip_addr, 4);
        memcpy(g_wlan_display_context.curr_netmask, prof->netmask, 4);
        memcpy(g_wlan_display_context.curr_gateway, prof->gateway, 4);
        memcpy(g_wlan_display_context.curr_dns1, prof->dns1, 4);
        memcpy(g_wlan_display_context.curr_dns2, prof->dns2, 4);
    }
}


MMI_BOOL mmi_wlan_is_allow_to_show_scrn(void)
{
    if (srv_ucm_is_any_call())
    {
        return MMI_FALSE;
    }
#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_is_phone_lock())
    {
        return MMI_FALSE;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef __MMI_WEBCAM__
    if(mmi_usb_webcam_is_active())
    {
        return MMI_FALSE;
    }
#endif
    if(mmi_scr_locker_is_locked ())
    {
        return MMI_FALSE;
    }

    if (AlmIsTonePlaying())
    {
        return MMI_FALSE;
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /*
        outgoing/incoming => true
        wap call connecting  => true
        wap call connected => false
        backgroun call => false
        other call connecting/connected => true
        */

        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        {
            return MMI_FALSE;
        }
    }
    else
    {
        if (GetActiveScreenId()==mmi_ucm_get_marker_scrn_id() ||
            IsScreenPresent(mmi_ucm_get_marker_scrn_id()))
        {
            /* special case here, sometimes CM change state too early
            but still have call marker in the history */
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}

/******************************************************************************/
/**         CMCC WiFi Proxy Exclusion list                                   **/
/**         Author: Cong Zhou                                                **/
/**         Date: 2011-3-9                                                   **/
/******************************************************************************/
void mmi_wlan_entry_proxy_exclusive_list(void)
{
    mmi_wlan_pre_entry_exclusive_ip_address_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exclusive_ip_addr_highlight_hdlr
 * DESCRIPTION
 *  High light handler for exclusive IP address screen 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exclusive_ip_addr_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_exclusive_ip_addr_hilight_id = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_get_exclusive_ip_addr_item
 * DESCRIPTION
 *  Entry option menu of exclusive ip address screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
pBOOL mmi_wlan_get_exclusive_ip_addr_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // U8 display_string[(SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH] = {0};
    CHAR url_string[MAX_SUBMENU_CHARACTERS + 1] = {0};
    CHAR display_string[(MAX_SUBMENU_CHARACTERS + 1) * ENCODING_LENGTH] = {0};
    U16  str_length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_length = strlen ((const char *)g_wlan_exclusive_ip_addr_data.ips[item_index].ip_addr);
    if(str_length > MAX_SUBMENU_CHARACTERS)
    {
        memcpy(url_string, g_wlan_exclusive_ip_addr_data.ips[item_index].ip_addr, MAX_SUBMENU_CHARACTERS - 3);
        url_string[MAX_SUBMENU_CHARACTERS - 3] = '.';
        url_string[MAX_SUBMENU_CHARACTERS - 2] = '.';
        url_string[MAX_SUBMENU_CHARACTERS - 1] = '.';
    }
    else
    {
        memcpy(url_string, g_wlan_exclusive_ip_addr_data.ips[item_index].ip_addr, str_length);
    }
    
    mmi_asc_to_ucs2((CHAR*)display_string, (CHAR *)url_string);
    mmi_ucs2cpy((CHAR*)str_buff, (const CHAR*)display_string);
    
    *img_buff_p = 0;
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_exclusive_ip_address_screen
 * DESCRIPTION
 *  Create the screen group and entry screen 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_exclusive_ip_address_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_exclusive_ip_address_gid = mmi_frm_group_create(
        wlan_parent_group_id, 
        GRP_ID_AUTO_GEN,
        mmi_wlan_exclusive_ip_addr_group_proc,
        NULL);

    mmi_frm_group_enter(g_exclusive_ip_address_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(
        g_exclusive_ip_address_gid,
        SCR_ID_DTCNT_WLAN_PROXY_EXCLUSIVE_LIST, // TODO: fix screen ID
        mmi_wlan_entry_exclusive_ip_address_screen,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_exclusive_ip_screen
 * DESCRIPTION
 *  Entry the exclusive IP setting screen. 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_exclusive_ip_address_screen(mmi_scrn_essential_struct *scrn_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_frm_scrn_enter(
		scrn_node->group_id, 
		scrn_node->scrn_id, 
		NULL, 
		mmi_wlan_entry_exclusive_ip_address_screen, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

	gui_buffer = mmi_frm_scrn_get_gui_buf(scrn_node->group_id, scrn_node->scrn_id);

    RegisterHighlightHandler(mmi_wlan_exclusive_ip_addr_highlight_hdlr);
    // g_wlan_exclusive_ip_addr_data = (srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct*)OslMalloc(sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct));
    memset(&g_wlan_exclusive_ip_addr_data, 0, sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct));
    
    // invoke data account service api to get ip address
    if(SRV_DTCNT_RESULT_SUCCESS != srv_dtcnt_wlan_qry_proxy_exclusive_ip_addr(&g_wlan_exclusive_ip_addr_data))
    {
        return;    
    }
    
    if (!g_wlan_exclusive_ip_addr_data.num_ips)
    {
        U8 *empty_string = (U8*)GetString(STR_GLOBAL_EMPTY_LIST);

        ShowCategory6Screen(
            STR_ID_DTCNT_WLAN_PROXY_EXCLUSIVE_LIST,
            0,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            &empty_string,
            NULL,
            0,
            gui_buffer);
    }
    else
    {
        ShowCategory284Screen(
            STR_ID_DTCNT_WLAN_PROXY_EXCLUSIVE_LIST,
            0,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_wlan_exclusive_ip_addr_data.num_ips,
            mmi_wlan_get_exclusive_ip_addr_item,
            NULL,
            0,
            gui_buffer);    
    }

    SetLeftSoftkeyFunction(mmi_wlan_entry_exclusive_ip_addr_option_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	
	ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
	SetCenterSoftkeyFunction(mmi_wlan_entry_exclusive_ip_addr_option_menu, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_exclusive_ip_addr_option_menu
 * DESCRIPTION
 *  Entry option menu of exclusive ip address screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
void mmi_wlan_entry_exclusive_ip_addr_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	menu_cui_id = cui_menu_create(
		g_exclusive_ip_address_gid, 
		CUI_MENU_SRC_TYPE_RESOURCE, 
		CUI_MENU_TYPE_OPTION, 
		0, 
		MMI_FALSE, 
		NULL);

    cui_menu_run(menu_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_init_exclusive_ip_addr_option_menu
 * DESCRIPTION
 *  Init the exclusive IP address screen option menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
void mmi_wlan_init_exclusive_ip_addr_option_menu(MMI_ID group_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id_array[MMI_WLAN_EXCLUSIVE_IP_OPTION_TOTAL] = {STR_GLOBAL_ADD, STR_GLOBAL_DELETE};
    U16 num_of_item = MMI_WLAN_EXCLUSIVE_IP_OPTION_TOTAL; 
    mmi_menu_id *menu_id;
    U8 i;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dynamically create a menu id list */
    menu_id = (mmi_menu_id*)OslMalloc(num_of_item * sizeof(mmi_menu_id));
    for(i = 0; i < num_of_item; i++)
    {
        menu_id[i]=(mmi_menu_id)i;
    }
    
    cui_menu_set_currlist_title(group_gid, (WCHAR*) GetString(STR_GLOBAL_TEXT), 0);
    
    cui_menu_set_currlist(group_gid, num_of_item, menu_id);
    
    cui_menu_set_currlist_flags(group_gid, CUI_MENU_NORMAL_LIST);

    if (!mmi_frm_is_in_backward_scenario())
	{
        cui_menu_set_currlist_highlighted_id(group_gid, 0);
	}
        
    for(i = 0; i < num_of_item; i++)
    {
        cui_menu_set_item_string(group_gid, menu_id[i], (WCHAR*)GetString(string_id_array[i]));
    }
    /* Free the menu id list */
    OslMfree(menu_id);    

    cui_menu_set_item_hidden(
        group_gid, 
        MMI_WLAN_EXCLUSIVE_IP_OPTION_DELETE, 
        (g_wlan_exclusive_ip_addr_data.num_ips == 0 ? MMI_TRUE : MMI_FALSE));

    cui_menu_set_item_hidden(
        group_gid, 
        MMI_WLAN_EXCLUSIVE_IP_OPTION_ADD, 
        (g_wlan_exclusive_ip_addr_data.num_ips >= SRV_DTCNT_MAX_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM ? MMI_TRUE : MMI_FALSE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exclusive_ip_addr_entry_add
 * DESCRIPTION
 *  Entry add screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
void mmi_wlan_exclusive_ip_addr_entry_add(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id                                  exclusive_url_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    exclusive_url_gid = cui_inline_create(
                            group_id,
                            &g_exlusive_url_inline_struct);
    
    memset(g_exclusive_url, 0, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1)*ENCODING_LENGTH);
    cui_inline_set_value(
        exclusive_url_gid, 
        WLAN_EXCLUSIVE_URL_EDITOR_ID, 
        g_exclusive_url);

    cui_inline_run(exclusive_url_gid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exclusive_ip_add_ip
 * DESCRIPTION
 *  Save the IP address to exclusive IP list 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exclusive_ip_add_ip(mmi_id inline_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct* ip_addr;
    U8 url_ascii[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(
        inline_cui_gid, 
        WLAN_EXCLUSIVE_URL_EDITOR_ID, 
        g_exclusive_url);
  
    // transfer unicode into ascii
    memset(url_ascii, 0, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
    mmi_ucs2_to_asc ((CHAR *) url_ascii, (CHAR *) g_exclusive_url);

    if(0 == strlen ((const char *)url_ascii))
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_ID_DTCNT_WLAN_EXCLUSIVE_URL_EMPTY),
            MMI_EVENT_FAILURE,
            g_exclusive_ip_address_gid,
            NULL);

        cui_inline_set_screen_attributes(
            inline_cui_gid, 
            CUI_INLINE_RESET_ATTRIBUTE, 
            CUI_INLINE_SCREEN_CHANGED);
    }
    else
    {
        ip_addr = (srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct*)OslMalloc(sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct));
        memset(ip_addr, 0, sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct));
        memcpy(ip_addr->ip_addr, url_ascii, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
        
        srv_dtcnt_wlan_add_proxy_exclusive_ip_addr(ip_addr);

        if(ip_addr)
        {
            OslMfree(ip_addr);
            ip_addr = NULL;
        }
        
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS,
            g_exclusive_ip_address_gid,
            NULL);

        cui_inline_close(inline_cui_gid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exclusive_ip_delete_ip
 * DESCRIPTION
 *  Delete IP address from exclusive IP list 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
void mmi_wlan_exclusive_ip_delete_ip(mmi_id inline_cui_gid, U32 ip_addr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    srv_dtcnt_wlan_delete_proxy_exclusive_ip_addr(&(g_wlan_exclusive_ip_addr_data.ips[ip_addr_id]));
    
    mmi_popup_display_simple(
        (WCHAR*)GetString(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS,
        g_exclusive_ip_address_gid,
        NULL);
    cui_inline_close(inline_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exclusive_ip_addr_group_proc
 * DESCRIPTION
 *  Proc function for exclusive ip address setting 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
mmi_ret mmi_wlan_exclusive_ip_addr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
	{
	case EVT_ID_CUI_MENU_LIST_ENTRY:
		mmi_wlan_init_exclusive_ip_addr_option_menu(menu_evt->sender_id);
        return MMI_RET_OK;

	case EVT_ID_CUI_MENU_ITEM_SELECT:
		switch (menu_evt->highlighted_menu_id)
		{
		case MMI_WLAN_EXCLUSIVE_IP_OPTION_ADD:
		    mmi_wlan_exclusive_ip_addr_entry_add(g_exclusive_ip_address_gid);
            return MMI_RET_OK;
            
        case MMI_WLAN_EXCLUSIVE_IP_OPTION_DELETE:
        {
            mmi_confirm_property_struct confirm_arg;

            mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
            confirm_arg.callback = NULL;
            confirm_arg.parent_id = g_exclusive_ip_address_gid;
            mmi_confirm_display(
                (WCHAR*)GetString(STR_ID_DTCNT_WLAN_CONFIRM),
                MMI_EVENT_QUERY,
                &confirm_arg); 
        	
        	ChangeCenterSoftkey(0, 0);
            return MMI_RET_OK;
        }
            
		default:
		    break;
		}
		break;

    case EVT_ID_ALERT_QUIT:
    {
        mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)evt;
        switch (confirm_evt->result)
    	{
    	case MMI_ALERT_CNFM_YES:
            mmi_wlan_exclusive_ip_delete_ip(g_exclusive_ip_address_gid, g_wlan_exclusive_ip_addr_hilight_id);
            break;
            
        case MMI_ALERT_CNFM_NO:    		
            mmi_frm_scrn_close_active_id();
    		break;
            
    	default:
    		break;
    	}
        return MMI_RET_OK;	        
    }

    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        mmi_wlan_exclusive_ip_add_ip(((cui_event_inline_common_struct*)evt)->sender_id);
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
    {
        cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct*)evt;
        cui_inline_close(inline_evt->sender_id);
        break;
    }


	case EVT_ID_CUI_MENU_CLOSE_REQUEST:
		cui_menu_close(menu_evt->sender_id);
		return MMI_RET_OK;

    case EVT_ID_GROUP_DEINIT:
    case EVT_ID_GROUP_DELETE_REQ:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
    default:
        break;
    }

    if (cui_menu_is_menu_event(evt->evt_id))
	{
	    return MMI_RET_DONT_CARE;
	}
    return MMI_RET_OK;
}

/******************************************************************************/
/**         CMCC WiFi Portal Certification Client                            **/
/**         Author: Yunpeng Li                                               **/
/**         Date: 2011-3-13                                                   **/
/******************************************************************************/
void mmi_wlan_portal_cert_client_setting_entry(void)
{
    if(GRP_ID_INVALID != wlan_parent_group_id)
    {
        g_wlan_display_context.portal_cert_setting_gid = 
            cmcc_wlan_auth_setting_show(wlan_parent_group_id);
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_SHOW_SETTINGS, 
        g_wlan_display_context.portal_cert_setting_gid, wlan_parent_group_id);
}

void mmi_wlan_portal_cert_run(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_CNF_RES, 
            g_wlan_display_context.ui_flow, g_wlan_display_context.auto_portal_switch_idx);
    if((MMI_WLAN_UI_PORTAL_LOGIN != mmi_wlan_get_ui_flow ()) &&
       (g_wlan_display_context.auto_portal_switch_idx == 0))
    {
        if (g_wlan_display_context.connected_wlan_profile &&
            mmi_wlan_is_default_trust_ap (g_wlan_display_context.connected_wlan_profile))
        {
            mmi_wlan_portal_cert_login_start ();
        }
    }
}

void mmi_wlan_portal_cert_callback(cmcc_wlan_auth_ret_enum ret)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGIN_CB, ret);
    // Reset the proc flag
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    // Show popup
    switch(ret)
    {
    case CMCC_WLAN_AUTH_OK:                 /* Login successfully */
    case CMCC_WLAN_AUTH_NO_NEED_LOGIN:      /* Server response OK directly, could take it as CMCC_WLAN_AUTH_OK */
        g_portal_result = 1;
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT,
                                   MMI_EVENT_QUERY,
                                   mmi_wlan_cmcc_show_portal_result,
                                   &g_portal_result);        
        break;
    case CMCC_WLAN_AUTH_NO_ACCOUNT:         /* User press NO in the setting screen */
        // break;
    case CMCC_WLAN_AUTH_ABORTED:            /* Action aborted by user */
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_LOGIN_SEND_DISC_REQ_AFTER_ABORTED, g_wlan_display_context.ui_flow);
        mmi_wlan_cmcc_send_disc_req_after_login_failed ();
        break;      
    case CMCC_WLAN_AUTH_WBLOCK:             /* Would block, callback will be called later */
    case CMCC_WLAN_AUTH_PARA_ERROR:         /* Parameter error */
    case CMCC_WLAN_AUTH_BUSY:               /* Previous login / logout activity not finished */
    case CMCC_WLAN_AUTH_WPS_ERROR:          /* HTTP layer error  */
    case CMCC_WLAN_AUTH_BEARER_ERROR:       /* WiFi AP is unreachable */
    case CMCC_WLAN_AUTH_LOGIN_FAIL:         /* CMCC server response fail, maybe wrong user name or password */
        g_portal_result = 0;
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT,
                                   MMI_EVENT_QUERY,
                                   mmi_wlan_cmcc_show_portal_result,
                                   &g_portal_result);        
        // Send disconnect request
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_LOGIN_SEND_DISC_REQ_AFTER_FAILED, g_wlan_display_context.ui_flow);
        mmi_wlan_cmcc_send_disc_req_after_login_failed ();
        break;
    default:
        break;
    }
}

void mmi_wlan_portal_cert_login_start(void)
{
    cmcc_wlan_auth_ret_enum login_status;
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGIN_START);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_IS_IN_LOGOUT_PROC, g_wlan_display_context.ui_flow);
    if(MMI_WLAN_UI_PORTAL_LOGOUT == mmi_wlan_get_ui_flow ())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_CANCEL);
        cmcc_wlan_auth_abort ();
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    }
    
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_PORTAL_LOGIN);
    // start to do portal certification
    // Only return CMCC_WLAN_AUTH_WBLOCK, portal application will invoke callback
    login_status = cmcc_wlan_auth_login (mmi_wlan_portal_cert_callback);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGIN_PROC, login_status);
    if(CMCC_WLAN_AUTH_WBLOCK != login_status)
    {
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    }
}

void mmi_wlan_portal_cert_logout_start(mmi_wlan_action_after_logout_func_ptr to_do)
{
    mmi_confirm_property_struct arg;
    cmcc_wlan_auth_ret_enum logout_status;

    if(MMI_WLAN_UI_PORTAL_LOGIN == mmi_wlan_get_ui_flow ())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_ABORT_LOGIN_BEFORE_LOGOUT, g_wlan_display_context.ui_flow);
        cmcc_wlan_auth_abort ();
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
        to_do();
    }
    else
    {
        // Start to logout
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_START);
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_PORTAL_LOGOUT);
        g_to_do_action = to_do;
        logout_status = cmcc_wlan_auth_logout(mmi_wlan_portal_cert_logout_cb);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_PROC, logout_status);
        if(CMCC_WLAN_AUTH_WBLOCK == logout_status)
        {
            // Show popup
            mmi_confirm_property_init(&arg, CNFM_TYPE_CANCEL);
            arg.callback = (mmi_proc_func)mmi_wlan_portal_cert_logout_cancel;
            arg.parent_id = GRP_ID_ROOT;
            g_wlan_display_context.portal_cert_logout_gid = mmi_confirm_display(
                                                (WCHAR*)GetString(STR_GLOBAL_PLEASE_WAIT),
                                                MMI_EVENT_PROGRESS,
                                                &arg);
        }
        else
        {
            to_do();
        }
    }
}

void mmi_wlan_portal_cert_logout_cb(cmcc_wlan_auth_ret_enum ret)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_CB, ret);
    // Reset flag
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    // Close popup
    mmi_alert_dismiss(g_wlan_display_context.portal_cert_logout_gid);
    g_wlan_display_context.portal_cert_logout_gid = GRP_ID_INVALID;
    // To do action after logout successfully
    g_to_do_action();
}

mmi_ret mmi_wlan_portal_cert_logout_cancel(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_CANCEL:
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_CANCEL);
            // Reset flag
            mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
            // Close popup
            mmi_alert_dismiss(g_wlan_display_context.portal_cert_logout_gid);
            g_wlan_display_context.portal_cert_logout_gid = GRP_ID_INVALID;
            // Send abort request
            cmcc_wlan_auth_abort ();
            break;
        default:
            break;
        }
    }
    
    return MMI_RET_OK;
}

void mmi_wlan_cmcc_connect_proc(void)
{
    mmi_wlan_ui_flow_enum ui_flow_type = mmi_wlan_get_ui_flow ();
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SEND_CONNECT_REQ, ui_flow_type);
    if((MMI_WLAN_UI_AUTO_CONN == ui_flow_type) || 
       ((MMI_WLAN_UI_WAIT_FOR_IP_UPDATE == ui_flow_type) && g_wlan_display_context.auto_portal_switch_idx == 0))
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_BUSY_TRY_LATER)), 
            MMI_EVENT_WARNING, 
            wlan_parent_group_id, 
            NULL);
        return;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_IS_IN_LOGOUT_PROC, g_wlan_display_context.ui_flow);
    if((MMI_WLAN_UI_PORTAL_LOGOUT != mmi_wlan_get_ui_flow ()) &&  /* not in the logout proc */
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
       g_wlan_display_context.connected_wlan_profile &&
       mmi_wlan_is_default_trust_ap (g_wlan_display_context.connected_wlan_profile))
    {
        mmi_wlan_portal_cert_logout_start(mmi_wlan_entry_wizard_connect);
    }
    else
    {
        mmi_wlan_entry_wizard_connect ();
    }
    
}

void mmi_wlan_cmcc_disconnect_proc(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SEND_DISCONNECT_REQ, g_wlan_display_context.ui_flow);
    if((MMI_WLAN_UI_DISC_AFTER_LOGIN_FAILED == mmi_wlan_get_ui_flow ()) ||
	  ((MMI_WLAN_UI_WAIT_FOR_IP_UPDATE == mmi_wlan_get_ui_flow ()) &&
	   g_wlan_display_context.auto_portal_switch_idx == 0))
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_BUSY_TRY_LATER)), 
            MMI_EVENT_WARNING, 
            wlan_parent_group_id, 
            NULL);
        return;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_IS_IN_LOGOUT_PROC, g_wlan_display_context.ui_flow);
    if((MMI_WLAN_UI_PORTAL_LOGOUT != mmi_wlan_get_ui_flow ()) &&  /* not in the logout proc */
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
       g_wlan_display_context.connected_wlan_profile &&
       mmi_wlan_is_default_trust_ap (g_wlan_display_context.connected_wlan_profile))
    {
        mmi_wlan_portal_cert_logout_start (mmi_wlan_entry_network_disconnect);
    }
    else
    {
        mmi_wlan_entry_network_disconnect ();
    }
}

void mmi_wlan_cmcc_deinit_proc(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_IS_IN_LOGOUT_PROC, g_wlan_display_context.ui_flow);
    if((MMI_WLAN_UI_PORTAL_LOGOUT != mmi_wlan_get_ui_flow ()) &&  /* not in the logout proc */
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
       g_wlan_display_context.connected_wlan_profile &&
       mmi_wlan_is_default_trust_ap (g_wlan_display_context.connected_wlan_profile))
    {
        mmi_wlan_portal_cert_logout_start (mmi_wlan_wizard_option_off);
    }
    else
    {
        mmi_wlan_wizard_option_off ();
    }
}

srv_dtcnt_result_enum mmi_wlan_cmcc_entry_deinit(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data)
{
    srv_dtcnt_wlan_status_enum wlan_status;

    wlan_status = srv_dtcnt_wlan_status ();
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_LOGOUT_FOR_DEINIT_IN_IDLE, 
        g_wlan_display_context.ui_flow, g_wlan_display_context.ui_flow, wlan_status);
    if((MMI_WLAN_UI_PORTAL_LOGOUT != mmi_wlan_get_ui_flow ()) &&  /* not in the logout proc */
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status) &&
       g_wlan_display_context.connected_wlan_profile &&
       mmi_wlan_is_default_trust_ap (g_wlan_display_context.connected_wlan_profile))
    {
        g_deinit_cb_func = callback;
        g_deinit_user_data = user_data;
        mmi_wlan_cmcc_portal_logout_by_deinit (callback, user_data);
        return SRV_DTCNT_RESULT_PROCESSING;
    }
    else
    {
        return srv_dtcnt_wlan_deinit(callback, user_data);
    }
}

void mmi_wlan_cmcc_portal_logout_by_deinit(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data)
{
    cmcc_wlan_auth_ret_enum logout_status;

    // In login procedure, abort, then send deinit request directly
    if(MMI_WLAN_UI_PORTAL_LOGIN == mmi_wlan_get_ui_flow ())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_ABORT_LOGIN_BEFORE_LOGOUT, g_wlan_display_context.ui_flow);
        cmcc_wlan_auth_abort ();
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
        srv_dtcnt_wlan_deinit(callback, user_data);
    }
    else
    {
    // Logout, then send deinit request
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_START);
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_PORTAL_LOGOUT);
        logout_status = cmcc_wlan_auth_logout(mmi_wlan_cmcc_portal_logout_by_deinit_cb);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_PROC, logout_status);
        if(CMCC_WLAN_AUTH_WBLOCK != logout_status)
        {
            srv_dtcnt_wlan_deinit(callback, user_data);
        }
    }
}

void mmi_wlan_cmcc_portal_logout_by_deinit_cb(cmcc_wlan_auth_ret_enum ret)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_CB, ret);
    // Reset flag
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    // Enter deinit procedure
    srv_dtcnt_wlan_deinit(g_deinit_cb_func, g_deinit_user_data);
}

void mmi_wlan_cmcc_logout_ind_handler(mmi_event_struct* param)
{
    cmcc_wlan_auth_ret_enum logout_status;
    srv_dtcnt_wlan_logout_evt_struct* logout_ind_evt
                                = (srv_dtcnt_wlan_logout_evt_struct*)param;
    if(logout_ind_evt)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_IND_SET_CB);
        g_logout_ind_cb = logout_ind_evt->rsp_callback;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_IS_IN_LOGOUT_PROC, g_wlan_display_context.ui_flow);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_IS_IN_WAIT_FOR_IP_ADDR_PROC, g_wlan_display_context.ui_flow);
    if((MMI_WLAN_UI_PORTAL_LOGOUT != mmi_wlan_get_ui_flow ()) &&
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
       g_wlan_display_context.connected_wlan_profile &&
       mmi_wlan_is_default_trust_ap (g_wlan_display_context.connected_wlan_profile) &&
       (MMI_WLAN_UI_WAIT_FOR_IP_UPDATE != mmi_wlan_get_ui_flow ()))
    {
        // abort login if in progress
        mmi_wlan_cmcc_abort_cert_portal ();
        // start to logout
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_PORTAL_LOGOUT);
        logout_status = cmcc_wlan_auth_logout(mmi_wlan_cmcc_logout_ind_cb);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_IND_STATUS, logout_status);   
        if(CMCC_WLAN_AUTH_WBLOCK != logout_status)
        {
            mmi_wlan_cmcc_logout_ind_inform_dtcnt_srv(SRV_DTCNT_WLAN_LOGOUT_SUCC);
        }
    }
    else
    {
        mmi_wlan_cmcc_logout_ind_inform_dtcnt_srv(SRV_DTCNT_WLAN_LOGOUT_SUCC);
    }
}

void mmi_wlan_cmcc_logout_ind_cb(cmcc_wlan_auth_ret_enum ret)
{
    // Reset flag
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    // Invoke callback
    if(CMCC_WLAN_AUTH_OK == ret)
    {
        mmi_wlan_cmcc_logout_ind_inform_dtcnt_srv(SRV_DTCNT_WLAN_LOGOUT_SUCC);
    }
    else
    {
        mmi_wlan_cmcc_logout_ind_inform_dtcnt_srv(SRV_DTCNT_WLAN_LOGOUT_FAIL);
    }
}

void mmi_wlan_cmcc_logout_ind_inform_dtcnt_srv(srv_dtcnt_wlan_logout_rsp_enum rsp)
{
    if(g_logout_ind_cb)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_IND_INFORM_DTCNT_SRV, rsp);
        g_logout_ind_cb(rsp);
    }
}

void mmi_wlan_cmcc_abort_cert_portal(void)
{
    if((MMI_WLAN_UI_PORTAL_LOGIN == mmi_wlan_get_ui_flow ()) ||
       (MMI_WLAN_UI_PORTAL_LOGOUT == mmi_wlan_get_ui_flow ()))
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_ABORT_AFTER_DISC, g_wlan_display_context.ui_flow);
        if(g_wlan_display_context.portal_cert_logout_gid != GRP_ID_INVALID)
        {
            // close popup
            mmi_alert_dismiss(g_wlan_display_context.portal_cert_logout_gid);
            g_wlan_display_context.portal_cert_logout_gid = GRP_ID_INVALID;
        }
        cmcc_wlan_auth_abort ();    // send abort request
        mmi_wlan_set_ui_flow (MMI_WLAN_UI_NONE);
    }
}

MMI_BOOL mmi_wlan_cmcc_show_portal_result(mmi_scenario_id scen_id, void *arg)
{
    U8* result = (U8*)arg;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_PORTAL_RESULT, *result);
    if(1 == *result)
    {
        mmi_popup_display(
            (WCHAR*) GetString(STR_ID_DTCNT_WLAN_LOGIN_SUCCESS), 
            MMI_EVENT_SUCCESS, 
            NULL);
    }
    else if(0 == *result)
    {
        mmi_popup_display(
            (WCHAR*) GetString(STR_ID_DTCNT_WLAN_LOGIN_FAILED), 
            MMI_EVENT_FAILURE, 
            NULL);
    }
   
    return MMI_TRUE;
}

void mmi_wlan_cmcc_entry_portal_proc(void)
{
    if(mmi_wlan_is_allow_to_show_scrn())
    {
        // start login procedure directly
        mmi_wlan_portal_cert_run();
    }
    else
    {
        if (g_wlan_display_context.connected_wlan_profile &&
            mmi_wlan_is_default_trust_ap (g_wlan_display_context.connected_wlan_profile))
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_DISC_DEFAULT_AP_IN_WEBCAM);
            srv_dtcnt_wlan_disconnect ();
        }
    }
}

void mmi_wlan_cmcc_send_disc_req_after_login_failed(void)
{
    mmi_wlan_set_ui_flow (MMI_WLAN_UI_DISC_AFTER_LOGIN_FAILED);
    srv_dtcnt_wlan_auth_cancel ();
}

/******************************************************************************/
/**         CMCC WiFi Power Saving Mode                                      **/
/**         Author: Yunpeng Li                                               **/
/**         Date: 2011-6-2                                                   **/
/******************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_cmcc_entry_power_saving_mode
 * DESCRIPTION
 *  entry function for Power Save Mode
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_cmcc_entry_power_saving_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer = NULL;
    U16 itemList[] = 
    {
        STR_GLOBAL_NORMAL,
        STR_ID_DTCNT_WLAN_POWER_MODE_CTIA
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE, 
        NULL, 
        mmi_wlan_cmcc_entry_power_saving_mode, 
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE);
    RegisterHighlightHandler(mmi_wlan_cmcc_entry_power_saving_mode_hilt_hdlr);

    // Get power saving mode from NVRAM
    g_power_saving_mode_idx = g_wlan_display_context.power_saving_mode;

    ShowCategory11Screen(
        STR_ID_DTCNT_WLAN_POWER_SAVE,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        MMI_WLAN_POWER_SAVING_MODE_TOTAL,
        itemList,
        (U16)g_power_saving_mode_idx,
        guiBuffer);
    
    SetLeftSoftkeyFunction(mmi_wlan_cmcc_power_saving_mode_ok, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void mmi_wlan_cmcc_entry_power_saving_mode_hilt_hdlr(S32 nIndex)
{
    g_power_saving_mode_idx = (U8)nIndex;
}

void mmi_wlan_cmcc_power_saving_mode_ok(void)
{
    g_wlan_display_context.power_saving_mode = 
        (mmi_wlan_power_saving_mode_enum)g_power_saving_mode_idx;
    // Call WNDRV API to set mode 
    switch(g_wlan_display_context.power_saving_mode)
    {
    case MMI_WLAN_POWER_SAVING_MODE_NORMAL:
        break;
    case MMI_WLAN_POWER_SAVING_MODE_CTIA:
        mmi_wlan_cmcc_set_power_saving_mode (WNDRV_POWER_MODE_CONTINUOUS_ACTIVE);
        break;
    default:
        break;
    }
    // Save power saving mode into NVRAM
    mmi_wlan_update_settings_in_db ();
    // Display 'Done' popup
    DisplayPopup((PU8)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_SUCCESS, 0, 1000, 0);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE);
}

void mmi_wlan_cmcc_set_power_saving_mode(wndrv_test_pwr_mgt_enum pwr_mode)
{
    // MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SET_POWER_SAVING_MODE, pwr_mode);
    RFTool_WiFi_PwrMgt (pwr_mode);
}

void mmi_wlan_cmcc_opt_menu_load_cert(void)
{
    mmi_id file_mgr_id;
    FMGR_FILTER filter;
    
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_CER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PFX);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_DER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PEM);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_P7B);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_CRT);
    
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    file_mgr_id = cui_file_selector_create(
                                wlan_parent_group_id, 
                                (WCHAR*) L"root", 
                                &filter, 
                                CUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
                                CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);
    
    cui_file_selector_set_ui_style(file_mgr_id, CUI_FMGR_UI_STYLE_BANNER_LIST);
    
    if (file_mgr_id != GRP_ID_INVALID)
    {  
        cui_file_selector_run(file_mgr_id);
    }
}

void mmi_wlan_cmcc_opt_menu_unload_cert(void)
{
    mmi_certman_launch_certificates_ind(
        MOD_MMI, 
        (kal_bool)MMI_CERTMAN_OPEN, 
        1);
}

void mmi_wlan_cui_file_mgr_select_evt_proc(mmi_event_struct *evt)
{
    U16 cert_file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    S32 result;
    cui_file_selector_result_event_struct *param = 
                                    (cui_file_selector_result_event_struct*)evt;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_FILE_MGR_USER_ACTION, param->result);
    if(param->result > 0)
    {
        /* get selected path */
        memset(cert_file_path, 0, SRV_FMGR_PATH_MAX_LEN + 1); 
        
        result = cui_file_selector_get_selected_filepath(
                                                param->sender_id,
                                                NULL,
                                                (WCHAR *) cert_file_path,
                                                SRV_FMGR_PATH_MAX_LEN);
        
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SELECT_CERT_FILE, result);
        if(result == 0)
        {
#ifdef __CERTMAN_SUPPORT__
            mmi_certman_install_certificates_ind(
                                                MOD_MMI, 
                                                (kal_bool)MMI_CERTMAN_OPEN, 
                                                1, 
                                                (kal_wchar*) cert_file_path);
#endif /* __CERTMAN_SUPPORT__ */
        }
        else
        {
            cui_file_selector_close(param->sender_id);
        }
    }
    else
    {
        cui_file_selector_close(param->sender_id);
    }
}

#endif /* __MMI_OP01_WIFI__ */
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __TCPIP__ */ 

