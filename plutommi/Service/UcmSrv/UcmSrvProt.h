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
 *  UcmSrvProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
#ifndef SRV_UCM_PROT_H
#define SRV_UCM_PROT_H

#include "MMI_features.h"
#include "UcmSrvGprot.h"
#include "MMIDataType.h"
#include "UcmSrvIntProt.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "stack_config.h"
#include "PhbSrvGprot.h" /* for  srv_phb_caller_res_id_struct */
#ifdef __MMI_UCM_REJECT_BY_SMS__
#include "SmsSrvGProt.h" /* SRV_SMS_MAX_ADDR_LEN */
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#include "CallLogSrvGprot.h" /* SRV_CLOG_ID */

#ifdef __MMI_CM_BLACK_LIST_EXT__
#include "CallSetSrvGprot.h" /* srv_callset_call_type_enum */
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

#ifdef __MMI_AUTO_ANSWER_MACHINE__
#define SRV_UCM_AUTO_ANSWER_MACHINE_CALL_TYPE (SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE)

typedef enum
{
    SRV_UCM_AUTOAM_STATE_IDLE = 0,
    SRV_UCM_AUTOAM_STATE_READY,
    SRV_UCM_AUTOAM_STATE_START,
    SRV_UCM_AUTOAM_STATE_TOTAL
} srv_ucm_autoam_state;
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */

typedef struct
{
    S16 call_id;
    srv_ucm_remote_info_struct remote_info;
    srv_ucm_int_call_origin_enum call_origin;
    srv_ucm_module_origin_enum module_id;
    srv_ucm_int_at_info_struct at_info;
    srv_ucm_process_state_enum proc_state;
    MMI_BOOL is_disconnecting;
    srv_ucm_act_opcode_enum act_type;
    srv_phb_caller_res_id_struct display_info;
    MYTIME start_time;
    U32 start_tick_time;
    U32 end_tick_time;
    SRV_CLOG_ID clog_id;
} srv_ucm_call_entry_struct;

typedef struct
{
    S16 group_id;
    srv_ucm_call_type_enum call_type;
    srv_ucm_call_state_enum call_state;
    srv_ucm_call_entry_struct call_info[SRV_UCM_MAX_CALL_IN_GROUP];
    U8 num_call;
} srv_ucm_group_entry_struct;

typedef struct
{
    srv_ucm_group_entry_struct group_info[SRV_UCM_MAX_GROUP];
    U8 num_group;
} srv_ucm_call_list_struct;

typedef struct
{
    srv_ucm_module_origin_enum module_id;
    srv_ucm_call_type_enum dial_type;
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1];
    MMI_BOOL is_wait_dial;
    MMI_BOOL is_ip_dial;
    void *phb_data;
} srv_ucm_dial_info_struct;

typedef struct
{
    S32 no_rcode_count; /* Avoid to send duplicate rcode notify */
    S32 end_processing_count;
    srv_ucm_act_opcode_enum curr_action;
    srv_ucm_index_info_struct index_list[SRV_UCM_MAX_CALL];
    srv_ucm_module_origin_enum curr_module;
    srv_ucm_int_at_info_struct at_info;
    MMI_BOOL is_pending_end_act; /* Avoid to send duplicate end action notify */
    MMI_BOOL is_speech;
    MMI_BOOL is_mute;
    MMI_BOOL is_delay_ciev;
    MMI_BOOL is_delay_ring;
    MMI_BOOL is_dtmf_start;
    MMI_BOOL is_count_stopped;
    void *user_data;
    U8 mem_occupied;
    U8 call_cost_symbol[4 * ENCODING_LENGTH];
    srv_ucm_dtmf_digits_struct dtmf_digits;
    U8 dtmf_digits_index;
} srv_ucm_call_misc_struct;

typedef struct
{
    U32 call_duration;
    U16 disp_msg[SRV_UCM_MAX_ERR_MSG_LEN + 1];
    U16 image_id;
    U16 tone_id;
} srv_ucm_call_end_struct;

#ifdef __MMI_AUTO_ANSWER_MACHINE__
typedef struct
{
    srv_ucm_id_info_struct uid_info;
    srv_ucm_autoam_state state;
} srv_ucm_autoam_struct;
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */

#ifdef __MMI_UCM_REJECT_BY_SMS__
typedef struct
{
    U8 dest_num[SRV_SMS_MAX_ADDR_LEN + 1];
    U8 *message;
    srv_ucm_id_info_struct uid_info;
    mmi_sim_enum sim_id;
} srv_ucm_rej_by_sms_struct;
#endif /* __MMI_UCM_REJECT_BY_SMS__ */

typedef struct
{
    srv_ucm_call_type_enum call_type;
    srv_ucm_int_act_callback_func_ptr act_callback;
} srv_ucm_int_call_srv_act_callback_struct;

typedef struct
{
    srv_ucm_call_type_enum call_type;
    srv_ucm_int_query_callback_func_ptr query_callback;
} srv_ucm_int_call_srv_query_callback_struct;

typedef struct
{
    srv_ucm_call_type_enum call_type;
    srv_ucm_int_permit_callback_func_ptr prmt_callback;
} srv_ucm_int_call_srv_prmt_callback_struct;

typedef struct
{
    srv_ucm_call_type_enum call_type;
    srv_ucm_int_cnf_callback_func_ptr cnf_callback;
} srv_ucm_int_cnf_struct;

typedef struct
{
    srv_ucm_call_list_struct call_list;
    srv_ucm_call_misc_struct call_misc;
    srv_ucm_dial_info_struct dial_info;
    srv_ucm_display_info_struct mo_mt_display; /* Information for MO and MT call screen */
    srv_ucm_int_cnf_struct int_cnf;
    srv_ucm_call_end_struct call_end;
    srv_ucm_int_auto_redial_ind_struct auto_redial;
#ifdef __MMI_AUTO_ANSWER_MACHINE__
    srv_ucm_autoam_struct autoam;
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */
#ifdef __MMI_UCM_REJECT_BY_SMS__
    srv_ucm_rej_by_sms_struct rej_by_sms;
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
    mmi_proc_func act_result_callback;
    srv_ucm_int_call_srv_act_callback_struct call_srv_act_cb[SRV_UCM_TOTAL_CALL_TYPE];
    srv_ucm_int_call_srv_query_callback_struct call_srv_query_cb[SRV_UCM_TOTAL_CALL_TYPE];
    srv_ucm_int_call_srv_prmt_callback_struct call_srv_prmt_cb[SRV_UCM_TOTAL_CALL_TYPE];
    srv_ucm_int_cnf_callback_func_ptr call_srv_cnf_callback;
} srv_ucm_cntx_struct;

extern srv_ucm_cntx_struct *g_ucm_srv_p;

/* event structure for short string CRSS action */
typedef struct {
    MMI_EVT_PARAM_HEADER
    srv_ucm_act_opcode_enum act_op; /* Action op-code */
    void *act_data; /* Action structure */
} srv_ucm_short_string_crss_evt_struct;

/* UcmSrvMain.c */
extern void srv_ucm_init_context(void);
extern void srv_ucm_init_protocol_handler(void);
extern void srv_ucm_log_call_history(S32 group_index, S32 call_index, MMI_BOOL is_connect);
extern void srv_ucm_log_call_duration(S32 group_index, S32 call_index);
extern void srv_ucm_call_scenario_control(void);
extern void srv_ucm_dial_action(void);
extern void srv_ucm_dial_act_rsp(void *rsp_struct);
extern void srv_ucm_accept_action(void);
extern void srv_ucm_accept_act_rsp(void *rsp_struct);
extern void srv_ucm_hold_action(S32 group_index);
extern void srv_ucm_retrieve_action(S32 group_index);
extern void srv_ucm_conference_action(S32 active_group_index, S32 held_group_index);
extern void srv_ucm_split_action(S32 group_index, S32 call_index);
#ifdef __MMI_UCM_DEFLECT__
extern void srv_ucm_deflect_action(void);
#endif /* __MMI_UCM_DEFLECT__ */
extern void srv_ucm_transfer_action(S32 group_index, S32 call_index);
#ifdef __MMI_UCM_ECT__
extern void srv_ucm_ect_action(S32 first_group_index, S32 second_group_index);
#endif /* __MMI_UCM_ECT__ */
extern void srv_ucm_act_rsp(srv_ucm_int_act_opcode_enum int_op_code, void *rsp_struct);
extern void srv_ucm_swap_action(S32 active_group_index, S32 held_group_index);
extern void srv_ucm_swap_act_rsp(void *rsp_struct);
extern void srv_ucm_end_single_action(S32 group_index, S32 call_index);
extern void srv_ucm_end_conference_action(S32 group_index);
extern void srv_ucm_end_all_action(void);
extern void srv_ucm_end_all_active_action(void);
extern void srv_ucm_end_all_held_action(void);
extern void srv_ucm_end_all_processing_action(void);
extern void srv_ucm_end_all_and_accept_action(void);
extern void srv_ucm_end_all_active_and_retrieve_action(S32 held_group_index);
extern void srv_ucm_end_all_active_and_accept_action(void);
extern void srv_ucm_hold_and_accept_action(S32 group_index);
extern void srv_ucm_end_all_action_with_call_type(srv_ucm_call_type_enum call_type);
extern void srv_ucm_end_act_rsp(srv_ucm_int_act_opcode_enum int_op_code, void *rsp_struct);
extern void srv_ucm_start_dtmf_action(U16 digit);
extern void srv_ucm_stop_dtmf_action(void);
extern void srv_ucm_send_dtmf_digits_action(srv_ucm_dtmf_digits_struct *dtmf_digits);
extern void srv_ucm_send_dtmf_digits(void);
extern void srv_ucm_stop_dtmf_digits(void);
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
extern void srv_ucm_vt_fallto_voice_action(void);
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
extern void srv_ucm_sync_call_list(void *call_list);
extern void srv_ucm_validate_start_time(void);
extern void srv_ucm_alert_ind(void *ind_struct);
extern void srv_ucm_connect_ind(void *ind_struct);
extern void srv_ucm_notify_ind(void *ind_struct);
extern void srv_ucm_session_ind(void *ind_struct);
extern void srv_ucm_speech_ind(void *ind_struct);
extern void srv_ucm_ring_ind(void *ind_struct);
extern void srv_ucm_disconnecting_ind(void *ind_struct);
extern void srv_ucm_release_ind(void *ind_struct);
extern void srv_ucm_release_ind_post_callback(srv_ucm_ind_evt_struct *ind);
extern void srv_ucm_auto_redial_ind(void *ind_struct);
extern void srv_ucm_auto_redial_abort(void);
extern void srv_ucm_auto_redial_timeout_handler(void);
extern void srv_ucm_call_cost_ind(void *ind_struct);
extern void srv_ucm_start_processing_ind(void *ind_struct);
extern void srv_ucm_stop_processing_ind(void *ind_struct);
extern void srv_ucm_replace_ind(void *ind_struct);
extern void srv_ucm_cancel_query_ind(srv_ucm_call_type_enum call_type);
extern void srv_ucm_dial_ind(void *ind_struct);
#ifdef __MMI_VIDEO_TELEPHONY__
extern void srv_ucm_start_count_ind(void *ind_struct);
#endif
extern void srv_ucm_query_cnf_ind(srv_ucm_call_type_enum call_type, void *ind_struct, srv_ucm_int_cnf_callback_func_ptr callback);
extern void srv_ucm_query_cnf(srv_ucm_cnf_opcode_enum cnf_op_code, void *cnf_data);
extern void srv_ucm_dial_cnf_ind(srv_ucm_call_type_enum call_type, void *ind_struct, srv_ucm_int_cnf_callback_func_ptr callback);
extern void srv_ucm_call_present_cnf_ind(srv_ucm_call_type_enum call_type, void *ind_struct, srv_ucm_int_cnf_callback_func_ptr callback);
extern void srv_ucm_call_status_change_callback(void);
extern mmi_ret srv_ucm_short_string_crss(mmi_event_struct* para);
#ifdef __MMI_UCM_SHORT_STIRNG_CRSS__
extern mmi_ret srv_ucm_short_string_crss_act_req(mmi_event_struct* para);
#endif /* __MMI_UCM_SHORT_STIRNG_CRSS__ */
extern mmi_ret srv_ucm_shutdown_proc(mmi_event_struct* para);
#ifdef __MMI_AUTO_ANSWER_MACHINE__
extern void srv_ucm_autoam_set_state(srv_ucm_autoam_state state);
extern srv_ucm_autoam_state srv_ucm_autoam_get_state(void);
extern void srv_ucm_autoam_set_call_id(srv_ucm_id_info_struct* uid_info);
extern void srv_ucm_autoam_reset_call_id(void);
extern void srv_ucm_autoam_reset_cntx(void);
extern void srv_ucm_autoam_start(void);
extern void srv_ucm_autoam_timeout_hdlr(void);
extern void srv_ucm_autoam_callback(U32 res);
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */

/* UcmSrvPrmt.c */
extern srv_ucm_result_enum srv_ucm_dial_act_permit(srv_ucm_dial_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_accept_act_permit(srv_ucm_single_call_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_hold_act_permit(srv_ucm_single_group_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_retrieve_act_permit(srv_ucm_single_group_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_swap_act_permit(srv_ucm_multiple_group_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_conference_act_permit(srv_ucm_multiple_group_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_split_act_permit(srv_ucm_single_call_act_req_struct* ptr);
#ifdef __MMI_UCM_DEFLECT__
extern srv_ucm_result_enum srv_ucm_deflect_act_permit(srv_ucm_cd_or_ct_act_req_struct* ptr);
#endif /* __MMI_UCM_DEFLECT__ */
extern srv_ucm_result_enum srv_ucm_transfer_act_permit(srv_ucm_cd_or_ct_act_req_struct* ptr);
#ifdef __MMI_UCM_ECT__
extern srv_ucm_result_enum srv_ucm_ect_act_permit(srv_ucm_ect_act_req_struct* ptr);
#endif /* __MMI_UCM_ECT__ */
extern srv_ucm_result_enum srv_ucm_end_single_act_permit(srv_ucm_single_call_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_end_conference_act_permit(srv_ucm_single_group_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_end_all_act_permit(void);
extern srv_ucm_result_enum srv_ucm_end_all_active_act_permit(void);
extern srv_ucm_result_enum srv_ucm_end_all_held_act_permit(void);
extern srv_ucm_result_enum srv_ucm_end_all_processing_act_permit(void);
extern srv_ucm_result_enum srv_ucm_end_all_and_dial_act_permit(srv_ucm_dial_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_end_all_and_accept_act_permit(srv_ucm_single_call_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_end_all_active_and_retrieve_act_permit(srv_ucm_single_group_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_end_all_active_and_accept_act_permit(srv_ucm_single_call_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_hold_and_dial_act_permit(srv_ucm_hold_and_dial_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_hold_and_accept_act_permit(srv_ucm_hold_and_accept_act_req_struct* ptr);
extern srv_ucm_result_enum srv_ucm_start_dtmf_act_permit(srv_ucm_dtmf_struct* ptr);
extern srv_ucm_result_enum srv_ucm_stop_dtmf_act_permit(void);
extern srv_ucm_result_enum srv_ucm_send_dtmf_digits_act_permit(srv_ucm_dtmf_digits_struct* ptr);
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
extern srv_ucm_result_enum srv_ucm_vt_fallto_voice_act_permit(srv_ucm_single_call_act_req_struct* ptr);
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */

/* UcmSrvUtil.c */
extern S32 srv_ucm_get_process_state(srv_ucm_process_state_enum proc_state, srv_ucm_index_info_struct *index_list);
extern S32 srv_ucm_set_process_state(S32 group_index, S32 call_index, srv_ucm_process_state_enum old_state, srv_ucm_process_state_enum new_state);
extern srv_ucm_act_opcode_enum srv_ucm_query_first_end_act_op(srv_ucm_act_opcode_enum comp_op, srv_ucm_act_opcode_enum act_op);
extern srv_ucm_act_type_enum srv_ucm_query_act_type(srv_ucm_act_opcode_enum first_op, srv_ucm_act_opcode_enum second_op);
extern srv_ucm_act_opcode_enum srv_ucm_query_end_act_op(srv_ucm_act_opcode_enum act_op);
extern srv_ucm_int_act_opcode_enum srv_ucm_query_int_act_op(srv_ucm_act_opcode_enum act_op);
extern srv_ucm_act_opcode_enum srv_ucm_query_act_op(srv_ucm_int_act_opcode_enum int_act_op);
extern void srv_ucm_reset_group_entry(S32 group_index);
extern void srv_ucm_reset_call_entry(S32 group_index, S32 call_index);
extern void srv_ucm_reset_index_list(void);
extern void srv_ucm_search_call_list(srv_ucm_int_call_list_entry_info_struct call_list, srv_ucm_index_info_struct *index_list);
extern S32 srv_ucm_query_call_index_by_call_id(srv_ucm_call_entry_struct *call_list, U8 call_list_size, S16 call_id);
extern S32 srv_ucm_query_group_index_by_call_state(srv_ucm_call_state_enum call_state);
#ifdef __MMI_CM_BLACK_LIST_EXT__
srv_callset_call_type_enum srv_ucm_query_blacklist_call_type(srv_ucm_call_type_enum ucm_call_type);
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

/* UcmSrvAtHdlr.c */
extern void srv_ucm_at_res_req_success(srv_ucm_module_origin_enum module_id, U8 source_id);
extern void srv_ucm_at_res_req_fail(srv_ucm_module_origin_enum module_id, U8 source_id, U8 cause);
extern void srv_ucm_at_req_prepare_single_call_data(
                    srv_ucm_single_call_act_req_struct *single_call_req, 
                    srv_ucm_call_type_enum call_type, 
                    S16 group_id, 
                    S16 call_id);
extern void srv_ucm_at_req_prepare_single_group_data(
                    srv_ucm_single_group_act_req_struct *single_group_req, 
                    srv_ucm_call_type_enum call_type, 
                    S16 group_id);
extern void srv_ucm_at_req_ind(void *msg, int mod_src);
extern void srv_ucm_at_res_req(srv_ucm_module_origin_enum module_id, U8 source, U8 result, U8 cause);
extern void srv_ucm_at_general_req(srv_ucm_module_origin_enum module_id, U8 rcode_type, U8 call_id, srv_ucm_int_at_info_struct *at_info);
#ifdef __BT_SUPPORT__
extern void srv_ucm_sync_call_state_to_headset(void);
extern void srv_ucm_bt_handfree_ciev_req(mmi_sim_enum sim_id, U8 type, U8 event);
extern void srv_ucm_bt_send_multiple_sim_ciev_req(U8 type, U8 event);
#endif /* __BT_SUPPORT__ */
extern srv_ucm_call_type_enum srv_ucm_at_query_voice_call_type(srv_ucm_module_origin_enum at_origin);
extern srv_ucm_call_type_enum srv_ucm_at_query_data_call_type(srv_ucm_module_origin_enum at_origin);
extern MMI_BOOL srv_ucm_at_check(void);

/* UcmSrvInterface.c */
extern void srv_ucm_act_permit_fail_action_notify(
                    srv_ucm_act_opcode_enum act_op, 
                    void *act_req_data, 
                    srv_ucm_result_enum permit_result, 
                    MMI_BOOL is_notify_start, 
                    MMI_BOOL is_intercept);
extern void srv_ucm_send_act_response(srv_ucm_act_opcode_enum act_op, void *ptr);
extern void srv_ucm_send_act_notify(srv_ucm_act_opcode_enum comp_op, srv_ucm_act_opcode_enum curr_act_op, srv_ucm_act_notify_type_enum notify_type , void *ptr);
extern void srv_ucm_send_indication(srv_ucm_ind_opcode_enum ind_op, void *ptr);
extern void srv_ucm_send_cnf_indication(srv_ucm_cnf_ind_opcode_enum cnf_ind_op, void *ptr, srv_ucm_cnf_callback_func_ptr cnf_callback);
extern mmi_ret srv_ucm_post_event_callback(mmi_post_result_event_struct *result_evt);
extern mmi_ret srv_ucm_ind_post_evt_callback(mmi_post_result_event_struct *result_evt);

/* UcmSrvIntInterface.c */
extern void srv_ucm_int_act_request(srv_ucm_int_act_opcode_enum op_code, srv_ucm_id_info_struct *first, srv_ucm_id_info_struct *other, srv_ucm_dial_info_struct *dial_ptr);
extern void srv_ucm_int_act_rsp_hdlr(srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum int_op_code, void *rsp_struct, void *user_data);
extern srv_ucm_result_enum srv_ucm_int_permit(srv_ucm_int_prmt_opcode_enum prmt_code, srv_ucm_id_info_struct *first, srv_ucm_id_info_struct *other, srv_ucm_dial_info_struct *dial_ptr);
extern MMI_BOOL srv_ucm_int_query(srv_ucm_call_type_enum call_type, srv_ucm_int_query_enum query_type, void *ptr);

#endif /* SRV_UCM_PROT_H */ 

