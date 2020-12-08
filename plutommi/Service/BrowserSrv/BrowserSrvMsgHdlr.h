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
 * BrowserSrvMsgHdlr.h
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVMSGHDLR_H
#define MMI_BROWSERSRVMSGHDLR_H

/*  Include: MMI header file */
#ifdef __MMI_BROWSER_2__
#include "kal_general_types.h"
#include "BrowserSrvConfig.h"
#include "MMIDataType.h"

extern void srv_brw_register_all_ilm_handlers(void);
extern void srv_brw_event_hdlr_send_ilm(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void srv_brw_event_hdlr_send_ilm_to_wps(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void srv_brw_event_hdlr_send_ilm_to_mmi(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void srv_brw_notify_app_ind(void *msg);
extern void srv_brw_ren_page_show_auth_dialog_ind(void *msg);
extern void srv_brw_create_instance_cnf(void *msg);
extern void srv_brw_delete_instance_cnf(void *msg);
extern void srv_brw_ren_page_do_element_ind(void *msg, int mod_src, void *ilm_p);
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
extern void srv_brw_save_as_stored_page_cnf(void *msg, int mod_src, void *ilm_p);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
extern void srv_brw_status_ind(void *msg);
extern void srv_brw_settings_set_profile_cnf(void *msg);
extern void srv_brw_bam_ready_ind_handler(S32 user_data, U32 result, void *obj);
extern void srv_brw_active_profile_change_handler(S32 user_data, U32 result, void *obj);
extern void srv_brw_get_stored_pages_list_start_cnf(void *msg);
extern void srv_brw_get_stored_pages_list_continue_cnf(void *msg, int mod_src, void *ilm_p);
extern void srv_brw_get_resource_list_start_cnf(void *msg);
extern void srv_brw_get_resource_list_continue_cnf(void *msg, int mod_src, void *ilm_p);
#ifdef OBIGO_Q05A
extern void srv_brw_get_resource_cnf(void *msg, int mod_src, void *ilm_p);
#endif /* OBIGO_Q05A */
extern void srv_brw_document_info_ind(void *msg);
extern void srv_brw_page_element_focused_ind(void *msg);
extern void srv_brw_get_recent_pages_list_start_cnf(void *msg);
extern void srv_brw_get_recent_pages_list_continue_cnf(void *msg, int mod_src, void *ilm_p);
extern void srv_brw_get_recent_page_cnf(void *msg, int mod_src, void *ilm_p);
#ifdef OBIGO_Q05A
extern void srv_brw_wtai_tel_ind(void *msg);
extern void srv_brw_wtai_pb_ind(void *msg);
#ifdef WAP_SEC_SUPPORT
extern void srv_brw_get_session_info_rsp(void *msg);
extern void srv_brw_get_current_certificate_rsp(void *msg);
#endif /* WAP_SEC_SUPPORT */
extern void srv_brw_wtai_tel_rsp(U16 error_code);
extern void srv_brw_wtai_pb_rsp(U16 error_code);
#endif /* OBIGO_Q05A */
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
extern void srv_brw_select_file_ind(void *msg);
#endif /* OBIGO_Q05A */
#ifdef OBIGO_Q03C
extern void srv_brw_uri_req_rsp(U16 error_code);
#endif /* OBIGO_Q03C */
extern void srv_brw_uri_request_ind(void *msg);
extern void srv_brw_settings_clear_data_rsp(void *msg);
extern void srv_brw_wait_user_action_ind(void *msg);
extern void srv_brw_bam_ready_ind(void *msg);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern void srv_brw_bkgrd_downloads_ind(void *msg);
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */ 
#ifdef WAP_SEC_SUPPORT
extern void srv_brw_get_trusted_certificate_ids_rsp(void *msg);
extern void srv_brw_get_trusted_certificate_rsp(void *msg);
extern void srv_brw_trusted_certificates_delete_rsp(void *msg);
extern void srv_brw_view_trusted_certificate_handler(void *msg);
extern void srv_brw_sec_confirm_dialog_ind(void *msg);
#endif /* WAP_SEC_SUPPORT */
extern void srv_brw_wap_browser_startup_req(void *msg);
extern void srv_brw_error_ind(void *msg);
extern void srv_brw_wait_user_action_rsp(MMI_BOOL positive_key_state);
extern void srv_brw_get_recent_pages_list_continue_req(U32 start_index);
extern void srv_brw_set_profile_content(void);
extern void srv_brw_ren_page_show_auth_dialog_res(U16 options, U8* username, U8* pswd);
extern void srv_brw_get_resource_list_continue_req(U32 start_index);
#ifdef WAP_SEC_SUPPORT
extern void srv_brw_ren_page_sec_confirm_dialog_res(U8 request_id, S8 result);
#endif /* WAP_SEC_SUPPORT */
extern void srv_brw_error_ind(void *msg);
extern void srv_brw_wap_browser_startup_req(void *msg);
extern void srv_brw_jam_get_user_agent_req(void *msg, int mod_id, void *ilm);
extern void srv_brw_get_stored_pages_list_continue_req(U32 start_index);
extern void srv_brw_recent_page_host_delete_callback(S32 user_data, U32 result, void *obj);
#ifdef __SAT__
extern void srv_brw_sat_launch_browser_res(U8 res, U8 sim_id);
extern void srv_brw_sat_send_termination_ind(U8 cause);
extern void srv_brw_sat_launch_browser_req(void *msg);
#endif /* __SAT__ */
extern void srv_brw_handle_sim_status(void);
#ifdef __COSMOS_MMI_PACKAGE__
extern void srv_brw_wmls_dialog_req(void *msg);
#endif
extern void srv_brw_release_sockets_rsp(void *msg);
extern void srv_brw_open_bearer_ind_hdlr(void *msg);
#endif /* __MMI_BROWSER_2__ */
#endif /* MMI_BROWSERSRVMSGHDLR_H */
