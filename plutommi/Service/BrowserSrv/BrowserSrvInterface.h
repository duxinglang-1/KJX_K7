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
 * BrowserSrvProts.h
 *
 * Project:
 * --------
 *   MAUI
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
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVINTERFACE_H
#define MMI_BROWSERSRVINTERFACE_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserSrvProts.h"
#include "BrowserSrvGprot.h"
#include "WapPushSrvTypes.h" //for push sim id enum
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "WAPProfileSrvType.h"
#include "browser_api.h"
#include "DLAgentSrvDef.h"
#include "mmi_frm_input_gprot.h"
#include "DtcntSrvGprot.h"

extern void srv_brw_update_settings_data(srv_brw_nvram_item_enum item_type);
extern void srv_brw_get_profile_content (void **profile_content_p);
extern void srv_brw_free(void *pMemory);
extern mmi_ret srv_brw_post_event_callback(mmi_post_result_event_struct *result_evt);
extern MMI_BOOL srv_brw_is_dtcnt_valid(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id);
extern srv_wap_prof_sim_id_enum srv_brw_convert_sim_setting_to_profile_sim_id(srv_brw_active_sim_setting_enum sim_setting);
extern srv_brw_active_sim_setting_enum srv_brw_convert_profile_sim_id_to_sim_setting(srv_wap_prof_sim_id_enum sim_id);
extern mmi_brw_sim_id_enum srv_brw_convert_sim_setting_to_browser_sim_id(srv_brw_active_sim_setting_enum sim_setting);
extern srv_brw_active_sim_setting_enum srv_brw_convert_push_sim_id_to_sim_setting(srv_wap_push_active_sim_enum sim_id);
extern void srv_brw_add_bookmark_provisioning(U8 *title_p, U8 *url_p, srv_wap_prof_response_funcptr_type callback);
#if (MMI_MAX_SIM_NUM >= 2)
extern void srv_brw_get_active_sim_setting (U32 *active_sim, U16 *is_asked);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
extern mmi_brw_sim_id_enum srv_brw_get_active_sim_id(void);
#ifdef __MMI_VBOOKMARK__
extern kal_bool srv_brw_get_default_bookmark_by_index (int index, 
									kal_uint8 *title_buf, kal_uint16 title_buf_len, 
									kal_uint8 *url_buf, kal_uint16 url_buf_len);
extern S32 srv_brw_get_num_of_default_bookmarks (void);
extern S32 srv_brw_get_num_of_user_defined_bookmarks (void);
#endif /* __MMI_VBOOKMARK__ */
extern srv_brw_error_enum srv_brw_set_as_homepage (U8 *url_p);
extern srv_brw_error_enum srv_brw_get_homepage (U8 *url_p);
extern S16 srv_brw_read_address_list_data(void);
extern U8 srv_brw_address_list_get_number_of_items (void);
extern srv_brw_error_enum srv_brw_address_list_add_item (S8* url_p);
extern srv_brw_error_enum srv_brw_address_list_delete_item (S32 item_index);
extern srv_brw_error_enum srv_brw_address_list_set_item_at_top(U32 selected_item_index);
extern srv_brw_error_enum srv_brw_address_list_delete_all_items(void);
extern S8 *srv_brw_address_list_get_url (U8 index);
extern S8 *srv_brw_address_list_get_title (U8 index, U8* is_ascii);
#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
extern S32 srv_brw_address_list_find_entry(U8 *input_str);
extern S32 srv_brw_address_list_get_matched_item_count(void);
extern S8* srv_brw_address_list_get_matched_item(S32 item_index);
extern S8* srv_brw_address_list_get_matched_item_title(S32 item_index, MMI_BOOL *is_ascii);
#endif /* __MMI_BRW_URL_AUTO_COMPLETION__ */
#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
extern S16 srv_brw_read_last_web_address(U8* last_web_address);
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
extern srv_brw_error_enum srv_brw_navigation_change_req (U16 selectable_items);
extern srv_brw_error_enum srv_brw_navigate_req (U8 direction);
extern srv_brw_error_enum srv_brw_reload_req(void);
extern srv_brw_error_enum srv_brw_activate_do_element_req (S32 item_index);
extern srv_brw_error_enum srv_brw_stop_page_fetching_req (void);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern srv_brw_error_enum srv_brw_background_downloads_req (mmi_da_wap_notify_enum notify);
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */
extern srv_brw_error_enum srv_brw_get_stored_pages_list_start_req(srv_brw_act_req_struct *req_data);
extern srv_brw_error_enum srv_brw_get_stored_page_req(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_save_as_stored_page_req(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_load_stored_page_req(U32 index);
extern srv_brw_error_enum srv_brw_rename_stored_page_req(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_delete_stored_page_req(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_delete_all_stored_pages_req(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_stored_pages_list_end_req(void);
extern srv_brw_error_enum srv_brw_create_instance_req(srv_brw_act_req_struct *app_data, void* memptr);
extern srv_brw_error_enum srv_brw_delete_instance_req(srv_brw_act_req_struct *req_data);
#ifdef OBIGO_Q05A
extern srv_brw_error_enum srv_brw_resize_screen_req(srv_brw_screen_info_struct *scr_info);
#endif /* OBIGO_Q05A */
extern srv_brw_error_enum srv_brw_load_url_req(U8 *url, U32 charset);
extern srv_brw_error_enum srv_brw_load_data_req(U8 *file_path);
extern srv_brw_error_enum srv_brw_get_resource_list_start_req(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_get_resource_list_end_req(void);
extern srv_brw_error_enum srv_brw_get_resource_req(srv_brw_act_req_struct *app_data);
extern U32 srv_brw_page_objects_get_actual_index(U16 hilited_index);
extern srv_brw_error_enum srv_brw_activate_resource_req(U32 res_index);
//#ifdef OBIGO_Q05A
extern srv_brw_error_enum srv_brw_change_setting_value_req(U8 data_type, U32 setting_id, U32 value_i, U8 *value_bv);
//#endif /* OBIGO_Q05A */
extern srv_brw_error_enum srv_brw_set_profile_req_by_data(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_set_profile_req(srv_brw_set_profile_req_struct *ptr);
extern srv_brw_error_enum srv_brw_get_recent_pages_list_start_req(srv_brw_act_req_struct *req_data);
extern srv_brw_error_enum srv_brw_recent_pages_list_end_req(void);
extern srv_brw_error_enum srv_brw_get_recent_page_req(srv_brw_act_req_struct *app_data);
extern void srv_brw_load_recent_page_req(U32 index);
extern srv_brw_error_enum srv_brw_delete_recent_host_req(U8 selected_host_index, srv_brw_rsp_funcptr_type rsp_callback);
extern srv_brw_error_enum srv_brw_delete_recent_page_req(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_delete_all_recent_pages_req(srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_handle_pen_event_req(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
extern srv_brw_error_enum srv_brw_ren_page_object_action_req(U16 sel_obj_type);
extern srv_brw_error_enum srv_brw_select_file_rsp(U16 select_file_result, U8 *file_path);
extern U8* srv_brw_recent_pages_list_get_item(S32 item_index);

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
extern void srv_brw_create_recent_page_list(void);
#endif
#ifdef OBIGO_Q05A
extern void srv_brw_create_recent_page_list_for_selected_host(U16 selected_host);
extern void srv_brw_create_recent_page_host_list(void);
extern U8* srv_brw_recent_pages_host_list_get_item(S32 item_index);
#endif /* OBIGO_Q05A */
extern U8* srv_brw_stored_pages_list_get_item(S32 item_index);
extern U8* srv_brw_trusted_certificate_list_get_item(S32 item_index);

extern void srv_brw_settings_clear_data_req(srv_brw_act_req_struct *app_data);
extern void srv_brw_trusted_certificates_delete_req(srv_brw_act_req_struct *app_data);
extern mmi_ret srv_brw_post_event_callback(mmi_post_result_event_struct *result_evt);
extern void srv_brw_get_trusted_certificate_ids_req(srv_brw_act_req_struct *app_data);
extern void srv_brw_get_trusted_certificate_req(srv_brw_act_req_struct *app_data);
#ifdef OBIGO_Q05A
extern void srv_brw_get_session_info_req(srv_brw_act_req_struct *app_data);
extern void srv_brw_get_current_certificate_req(srv_brw_act_req_struct *app_data);
#endif /* OBIGO_Q05A */
extern srv_wap_prof_sim_id_enum srv_brw_convert_sim_setting_to_profile_sim_id(srv_brw_active_sim_setting_enum sim_setting);
extern srv_brw_active_sim_setting_enum srv_brw_convert_profile_sim_id_to_sim_setting(srv_wap_prof_sim_id_enum sim_id);
extern U32 srv_brw_recent_page_get_actual_index(U32 highlighted_item);
extern MMI_BOOL srv_brw_is_backward_navigation(void);
extern MMI_BOOL srv_brw_is_forward_navigation(void);
extern void srv_brw_clear_focused_element(void);
extern U32 srv_brw_trusted_certificate_get_actual_id(U32 highlighted_item);

extern void srv_brw_active_profile_changed_hdlr(
        srv_wap_prof_profile_content_struct *profile_content_p,
        srv_wap_prof_sim_id_enum sim_id,
        srv_wap_prof_response_funcptr_type callback);

extern MMI_BOOL srv_brw_is_in_transaction(void);
extern S8 srv_brw_stricmp(S8 *string1, S8 *string2);
extern srv_brw_error_enum srv_brw_create_dynamic_service(void);
extern srv_brw_error_enum srv_brw_destroy_dynamic_service(void);
extern void srv_brw_convert_int_to_unicode_string(U8 *StringVal, U32 value);
extern srv_brw_error_enum srv_brw_get_user_defined_homepage (U8 *url_p);
/* VENUS MMI*/
extern U32 srv_brw_get_recent_page_list_count(void);
extern U32 srv_brw_get_stored_page_list_count(void);
extern U32 srv_brw_get_trusted_certificate_list_count(void);
extern U8* srv_brw_get_stored_page_label(void);
extern U8* srv_brw_get_stored_page_URL(void);
extern MMI_BOOL srv_brw_is_wap_ready(void);
extern MMI_BOOL srv_brw_get_screen_size_status(void);
extern void srv_brw_init(void);
extern void srv_brw_set_address_list_entry_flag(MMI_BOOL is_set);
extern U8* srv_brw_get_authentication_username(void);
extern U8* srv_brw_get_authentication_password(void);
extern MMI_BOOL srv_brw_is_page_valid_for_saving(void);
extern MMI_BOOL srv_brw_is_page_valid_for_add(void);
extern MMI_BOOL srv_brw_is_page_url_valid(void);
extern const U8* srv_brw_get_default_accept_header(void);
extern srv_brw_active_sim_setting_enum srv_brw_convert_dtcnt_sim_id_to_sim_setting(srv_dtcnt_sim_type_enum sim_id);


#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
extern S16 srv_brw_read_search_item_list_data(void);
extern srv_brw_error_enum srv_brw_search_item_list_add_item (S8* search_string, srv_brw_search_engines_enum search_engine);
extern srv_brw_error_enum srv_brw_launch_search_string(U8* saerch_string, srv_brw_search_engines_enum search_engine);
extern srv_brw_error_enum srv_brw_launch_search_item(U8 search_item_index);
extern srv_brw_error_enum srv_brw_search_list_set_item_at_top(U32 selected_item_index);
extern srv_brw_error_enum srv_brw_search_list_delete_all_items(void);
extern srv_brw_error_enum srv_brw_search_list_get_item (U8 index, nvram_brw_search_item_struct *search_item);
extern U8 srv_brw_search_list_get_number_of_items (void);
extern S32 srv_brw_search_list_find_entry(U8 *input_str);
extern S32 srv_brw_search_list_get_matched_item_count(void);
extern S8* srv_brw_search_list_get_matched_item(S32 item_index);
extern srv_brw_search_engines_enum srv_brw_search_list_get_matched_item_search_engine(S32 item_index);
#endif

#ifdef __COSMOS_MMI_PACKAGE__
extern void srv_brw_asm_success_callback(void);
extern void srv_brw_asm_cancel_callback(mmi_frm_appmem_evt_struct *cancel_event);
extern srv_brw_error_enum srv_brw_initialize_asm_pool(srv_brw_act_req_struct *req_data);
extern U32 srv_brw_get_recent_page_count_by_time(U32 upper_utc_time , U32 lower_utc_time);
extern U32 srv_brw_get_recent_pages_count_by_day(srv_brw_recent_pages_day_enum day);
extern srv_brw_error_enum srv_brw_delete_recent_page_by_day_req(U8 day_type, srv_brw_act_req_struct *app_data);
extern srv_brw_error_enum srv_brw_delete_multiple_stored_page_req(srv_brw_act_req_struct *app_data, U8* selected_indexes);
extern void srv_brw_update_search_engine(srv_brw_search_engines_enum search_engine);
extern U32 srv_brw_get_current_utc_time (void);

extern S16 srv_brw_read_global_list_data(void);
extern S16 srv_brw_read_local_list_data(void);
extern void srv_brw_read_shortcuts_data(void);
extern U8 srv_brw_global_shortcuts_list_get_number_of_items (void);
extern U8 srv_brw_local_shortcuts_list_get_number_of_items (void);
extern void srv_brw_global_shortcuts_list_update_data (void);
extern void srv_brw_local_shortcuts_list_update_data (void);
extern MMI_BOOL srv_brw_is_shortcut_index_empty (U8 index);
extern srv_brw_error_enum srv_brw_global_shortcuts_list_add_item_at (nvram_brw_global_shortcuts_item_struct *item, U8 index);
extern srv_brw_error_enum srv_brw_global_shortcuts_set_item_lock (U8 index, MMI_BOOL is_locked);
extern MMI_BOOL srv_brw_is_global_shortcut_locked (U8 index);
extern nvram_brw_global_shortcuts_item_struct* srv_brw_get_global_shortcut(U8 index);
extern srv_brw_error_enum srv_brw_launch_global_shortcut(U8 index);
extern srv_brw_error_enum srv_brw_delete_global_shortcut(U8 index);

#ifndef __MMI_BRW_SLIM__
extern srv_brw_error_enum srv_brw_local_shortcuts_list_add_item (nvram_brw_local_shortcuts_item_struct *item);
extern srv_brw_error_enum srv_brw_increment_local_shortcut_points (U8 shortcut_index);
extern srv_brw_error_enum srv_brw_local_shortcuts_add_entry (nvram_brw_local_shortcuts_item_struct *item);
#endif
extern void srv_brw_rearrange_global_shortcuts(void);
extern void srv_brw_reposition_global_shortcuts(void);
extern void srv_brw_update_global_shortcut_points(void);
extern void srv_brw_rearrange_local_shortcuts(void);
extern void srv_brw_update_local_shortcut_points(void);
extern void srv_brw_update_shortcut_points(void);
extern MMI_BOOL srv_brw_is_shortcut_one_week_old(U32 shortcut_time);
extern MMI_BOOL srv_brw_is_shortcut_one_day_old(U32 shortcut_time);

extern srv_brw_error_enum srv_brw_wmls_dialog_rsp(U32 result, U8 dialog_type, U8* message);
extern U8 srv_brw_find_available_shortcut_id (void);

#endif
extern srv_brw_error_enum srv_brw_relaunch_last_browser_req (void);
extern srv_brw_error_enum srv_brw_release_sockets_req(srv_brw_act_req_struct *app_data);
extern void srv_brw_encode_url(CHAR *dest, U32 max_dest_len, const CHAR* raw_data, U32 raw_data_size, MMI_BOOL *truncated);

extern S16 srv_brw_read_shortcut_list_data(void);
extern MMI_BOOL srv_brw_shortcut_list_is_item_empty(U8 index);
extern U8* srv_brw_shortcuts_list_get_title(U8 index);
extern U8* srv_brw_shortcuts_list_get_url(U8 index);
extern void srv_brw_update_shortcut_info(U8 index, U8* title, U8* url);
extern void srv_brw_open_bearer_rsp(U8 error_code);

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVINTERFACE_H */
