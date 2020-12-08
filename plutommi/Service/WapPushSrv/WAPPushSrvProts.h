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
 * WAPPushSrvProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file have the declaration of internally used function.
 *
 * Author:
 * -------
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
#ifndef __PUSH_MSG_SRV_PROT__
#define __PUSH_MSG_SRV_PROT__
#include "WAPPushSrvTypes.h"
//#include "UcmSrvGprot.h"
//#include "WapPushResDef.h"
//#include "WapPushUIProts.h"
//#include "WapPushSrvGprots.h"
    #include "mmiapi_dm_struct.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "pmg_struct.h"
    #include "MMI_features.h"
//#ifdef __DM_LAWMO_SUPPORT__
//#include "dmuigprot.h"
//#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef WAP_SUPPORT
#include "WAPPushSrvTypes.h"
#include "UcmSrvGprot.h"
//#include "WapPushResDef.h"
//#include "WapPushUIProts.h"
#include "WapPushSrvGprots.h"

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__

#include "CcaSrvGProt.h"

#endif /*__MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__*/


#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif /* __DM_LAWMO_SUPPORT__ */

/* From Main.c */
#ifdef __DM_LAWMO_SUPPORT__
//extern void srv_wap_push_handle_lawmo_request (mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd);
extern mmi_ret  srv_wap_push_handle_lawmo_request (mmi_event_struct *evt);
extern void srv_wap_push_handle_del_all_rsp_for_lawmo (MMI_BOOL result);
#endif /* __DM_LAWMO_SUPPORT__ */
extern void srv_wap_push_init_profile_content (void);
extern MMI_BOOL srv_wap_push_send_new_msg_um_refresh_ind(pmg_detailed_msg_struct *msg_data);
extern MMI_BOOL srv_wap_push_msg_read_status (U32 msg_id);
//extern U8 srv_wap_push_is_keypad_locked_state (void);
extern void srv_wap_push_send_msg (U16 message_id, void *msg_data, U16 destination, U16 sap_id);
extern void srv_wap_push_send_msg_to_mmi (U16 message_id, void *msg_data);
extern S32 srv_wap_push_check_ip(S8 *ip);
extern srv_wap_push_ret_code_enum srv_wap_push_convert_proxy_ipstring_to_array(U8 *parm_element_p, U8 *proxy_ip_p);
extern void *srv_wap_push_malloc(U32 size);
extern void srv_wap_push_mfree(void *ptr);
extern U32 srv_wap_push_get_current_utc_time(void);
extern MMI_BOOL srv_wap_push_enque_msg (U32 message_id, U16 type);
extern MMI_BOOL srv_wap_push_enque_dialogue (U32 trans_id, U16 dlg_type);
extern MMI_BOOL srv_wap_push_enque_dialogue_ex (U32 trans_id, U16 dlg_type, S8 *info_char);
extern void srv_wap_push_delete_from_dlg_queue (U32 trans_id);
extern MMI_BOOL srv_wap_push_enque_msg_ex (U32 message_id, U16 type, S8 *info_char);
extern srv_wap_push_dlg_queue_struct* srv_wap_push_get_dialogue_date (void);
extern srv_wap_push_idle_messge_queue_struct* srv_wap_push_get_first_msg (void);
extern void srv_wap_push_delete_from_msg_queue (U32 message_id);
extern void srv_wap_push_delete_all_queue_entry (void);
extern MMI_BOOL srv_wap_push_is_active_call (void);
extern void srv_wap_push_event_based_display_popup(srv_wap_push_event_notify_enum evt_notify, U16 str_id);
extern MMI_BOOL srv_wap_push_draw_unknown_scren (mmi_scenario_id scen_id, void *arg);
extern void srv_wap_push_add_unknwn_addr_to_list(U16 list_type);
extern void srv_wap_push_delete_message_generic (U32 msg_id);
extern void srv_wap_push_nmgr_get_unread_msg(void);
extern void srv_wap_push_nmgr_cancel_unread_msg(void);
extern void srv_wap_new_push_handle_notification(void *user_data);
extern void srv_wap_push_handle_msg_deleted_by_server_ind (wps_pmg_delete_ind_struct* msg, MMI_BOOL replaced);
extern void srv_wap_push_handle_new_service_msg (pmg_detailed_msg_struct *new_msg, S8 *url);
#if (MMI_MAX_SIM_NUM == 2)
extern void srv_wap_push_update_status_icon_sim2 (U32 show_icon);
#endif /* __MMI_WAP_DUAL_SIM__ */
extern void srv_wap_push_update_status_icon_default_sim (U32 show_icon);
extern void srv_wap_push_handle_msg_on_idle (pmg_detailed_msg_struct *new_msg, S8 *url);
extern U16 srv_wap_push_get_push_app_sim_id_from_pmg_sim_id (U16 pmg_sim_id);
extern void srv_wap_push_delete_all_messages (void);
extern void srv_wap_push_set_as_homepage (void);
extern void srv_wap_push_add_to_validation_list (void);
extern void srv_wap_push_copy_data_to_selected_message (pmg_detailed_msg_struct *new_msg, S8 *url);

#ifdef __MMI_OP12_TOOLBAR__
extern void srv_wap_push_tb_evnt_query_push(S32 num);
#endif /* __MMI_OP12_TOOLBAR__ */
extern void srv_wap_push_send_by_mms (void);
extern void srv_wap_push_send_by_sms (void);
extern void srv_wap_push_send_by_email (void);
extern void srv_wap_push_delete_all_messages (void);
extern void srv_wap_push_add_to_validation_list (void);
extern void srv_wap_push_get_display_ansii_number_format(S8 *out_string, S8 *in_string, U16 len);
extern void srv_wap_push_display_msg (pmg_detailed_msg_struct *msg, S8 *url, U16 grp_id);




/* From UM.c Now it is moved to main.c*/
extern void srv_wap_push_send_um_new_msg_ind (U32 msg_id, U32 timestamp, U16 sim_id);
extern void srv_wap_push_send_um_refresh_ind (kal_int32 msg_id, kal_uint16 refresh_type, pmg_addr_struct *address);
extern void srv_wap_push_send_um_delete_all_ind(void);

/* From PMG interface */
extern void srv_wap_push_get_dlg_data_req(U32 trans_id);
extern void srv_wap_push_get_full_message (U32 msg_id, U16 trans_id);
extern void srv_wap_push_get_msg_count(U16 read, U16 trans_id);
extern void srv_wap_push_send_del_req_to_pmg (U32 msg_id, U16 trans_id);
extern void srv_wap_push_update_service_msg_req(U32 msg_id);
extern void srv_wap_push_get_list_from_service_layer(S32 start_index, S32 num_item, U16 trans_id, U8 is_read);
extern void srv_wap_push_delete_all_msg_req (U16 trans_id);
extern void srv_wap_push_init_service_interface(void );


extern void srv_wap_push_setting_init(void);
extern void srv_wap_send_white_list_to_service_layer(void);
extern void srv_wap_send_black_list_to_service_layer(void);

extern void srv_wap_push_set_enable_push(kal_uint8 enable_push);
extern void srv_wap_push_set_sl_setting(kal_uint8 sl_setting);
extern void srv_wap_push_set_wl_setting(kal_uint8 wl_setting);
extern void srv_wap_push_set_bl_setting(kal_uint8 bl_setting);



extern void srv_wap_push_delete_list_entry(void);
extern void srv_wap_push_setting_delete_all_list_entry(void);
extern void srv_wap_push_cancel_ota_replace(void);
extern void srv_wap_push_ota_install_trustlist(void);
extern void srv_wap_push_ota_skip_whitelist_hdlr(void);
extern void srv_wap_push_ota_mem_free_trustlist(void);
extern void srv_wap_push_ota_add_trustlist_result_callback(srv_wap_push_add_list_error_enum result);
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
extern void srv_wap_push_ota_send_cca_response(cca_status_enum status);
#endif

extern void srv_wap_push_send_unknwn_addr_cnf(pBOOL result, U32 trans_id);
extern void srv_wap_push_send_sia_cnf(pBOOL result, U32 trans_id);
extern pBOOL srv_wap_push_check_duplicate_entry(U16 list_type, U16 addr_type, S8 *addr);
extern void srv_wap_push_get_record_and_index(U16 *record, U16 *index, S32 for_item_num);
extern void srv_wap_push_parse_ph_num(S8 *ascii_sender, S8 *ascii_smsc, S8 *ascii_number);
extern U16 srv_wap_push_get_setting_index(U16 set_type);
extern void srv_wap_push_commit_push_genearl_settings_to_nvram(void);
extern void srv_wap_push_send_config_ind(void);
extern S8* srv_wap_push_construct_data (void);
extern void srv_wap_push_get_record_and_index(U16 *record, U16 *index, S32 for_item_num);
extern pBOOL srv_wap_push_check_valid_number(S8 *number);
extern srv_wap_push_add_list_error_enum srv_wap_push_setting_modify_or_add_list(void);
extern srv_wap_push_add_list_error_enum srv_wap_push_setting_modify_or_add_ip_addr(void);
extern void srv_wap_push_replace_selected_wl_addr(void);
extern srv_wap_push_add_list_error_enum srv_wap_push_add_wl_ota_addr(srv_wap_push_sender_addr_type_enum add_type, S8 *addr);
extern srv_wap_push_add_list_error_enum srv_wap_push_add_modify_list(S8 *ascii_addr, U16 addr_type, U16 list_type, U16 array_index);
extern void srv_wap_push_set_nmgr_answer_flag(S16 sim_id, MMI_BOOL is_high);


extern srv_wap_push_msg_inbox_struct  *g_push_inbox_ctxt;
extern srv_wap_push_setting_cntxt_struct *g_push_set_p;

extern srv_wap_push_cntxt_struct *g_srv_wap_push_cntxt;
extern MMI_BOOL srv_wap_push_is_service_ready();
extern srv_wap_push_notify_nmgr_sim_enum srv_wap_push_get_notify_nmgr_flag();
extern void srv_wap_push_set_notify_nmgr_flag(srv_wap_push_notify_nmgr_sim_enum nmgr_flag);

extern void srv_wap_push_ui_init (void);
extern void srv_wap_push_set_setting_index(U16 set_type, U16 index);
extern void srv_wap_push_get_trustlist_item(S32 itemIndex, WCHAR *strBuff);
extern U16 srv_wap_push_add_modify_ip_address(void);
extern U16 srv_wap_push_modify_add_sender_smsc_address(void);
extern U16 srv_wap_push_get_number_of_black_list (void);
extern U16 srv_wap_push_get_number_of_white_list (void);
extern U16 srv_wap_push_prepare_trustlist_modify_data(WCHAR **sender_addr,WCHAR **SMSC_addr,WCHAR **IP_addr, U16 selected_index);
extern void srv_wap_push_delete_list_entry_ex(U8 *index_array, U8 count);
extern void srv_wap_push_handle_sl_on_idle (U32 message_id, U32 timestamp, S8 *url, U32 sim_id);
extern void srv_wap_push_handle_sl_on_non_idle (U32 message_id, U32 timestamp, U32 sim_id);
extern void srv_wap_push_launch_sl (U32 message_id, S8 *message_url, U32 sim_id);
extern void srv_wap_push_create_ucs2_time_format_string(U32 time_value, S8 *ucs2_time_string);
extern U16 srv_wap_push_get_max_white_list(void);
extern U16 srv_wap_push_get_max_black_list(void);
extern void srv_wap_push_initialize_curr_dlg_data (void *dlg, wps_pmg_dlg_type_enum dlg_type);
extern void srv_wap_push_delete_curr_dlg_data (void);

extern void srv_wap_push_display_error_dlg(void *msg);
extern void srv_wap_push_process_delete_msg_rsp(void *msg);
extern void srv_wap_push_process_delete_all_msg_rsp(void *msg);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__ 
extern MMI_BOOL srv_wap_push_check_trustlist_full();
#endif /*__MMI_WAP_PUSH_WHITE_LIST__ */
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
extern MMI_BOOL srv_wap_push_check_blacklist_full();
#endif /*__MMI_WAP_PUSH_BLACK_LIST__ */
#ifdef __MMI_PUSH_IN_UM__
extern void srv_wap_push_handle_delete_all_rsp(void *msg);
#if 0
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* 0*/
#endif /* __MMI_PUSH_IN_UM__ */
#ifndef __MMI_PUSH_IN_UM__
extern void srv_wap_push_set_nmgr_unread_handler(U32 handler);
extern U32 srv_wap_push_get_nmgr_unread_handler();
#endif
#endif /* WAP_SUPPORT */
#endif /* __PUSH_MSG_SRV_PROT__ */
