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
 *  GCallSrvProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  GSM /3G call service internal prototypes
 *
 * Author:
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef SRV_GCALL_PROT_H
#define SRV_GCALL_PROT_H

#include "PhbSrvGprot.h" /* srv_phb_caller_info_struct */

#include "UcmSrvGprot.h"
#include "..\UcmSrv\UCMSrvIntProt.h"

#include "GCallSrvDef.h"

#include "MMIDataType.h"
#include "csmcc_common_enums.h"
#include "MMI_features.h"
#include "Custom_ecc.h" /* ecc_call_type_enum */
#include "custom_phb_config.h"
#include "l4c2abm_struct.h"
#include "l4c_aux_struct.h"
#include "kal_non_specific_general_types.h"
#include "mmi_msg_struct.h"
#include "stack_config.h"


typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_ucm_call_type_enum call_type;
    srv_ucm_int_act_opcode_enum act_op;
    void *ptr;
    void *int_user_data;
    srv_ucm_int_act_rsp_callback_func_ptr rsp_callback;
} srv_gcall_act_evt_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_ucm_int_cnf_callback_func_ptr cb;
    srv_ucm_call_type_enum call_type;
    srv_ucm_int_cnf_opcode_enum cnf_type;
    void *ptr;
} srv_gcall_cnf_evt_struct;


typedef struct
{
    U8 call_id;
    U8 group_id;
    srv_gcall_type_enum call_type;
    U8 status_flag;
    srv_gcall_dir_enum dir;
    srv_gcall_state_enum curr_state;
#ifdef __MMI_UCM_NUMBER_TYPE__
    mmi_phb_num_type_enum number_type;
#endif /* __MMI_UCM_NUMBER_TYPE__ */
    U8 num[SRV_GCALL_MAX_NUMBER]; /* ascii; original number */
    U8 num2[SRV_GCALL_MAX_NUMBER]; /* ascii; modified number */
    U8 name[SRV_GCALL_MAX_NAME]; /* ucs2; SATname > logname = phbname */
#ifdef __MMI_CM_CNAP_SUPPORT__
    U8 cnap_name[SRV_GCALL_MAX_NAME]; /* ucs2; length is set according to mmi_cc_notify_ss_cnap_ind_struct */
#endif /* __MMI_CM_CNAP_SUPPORT__ */
    srv_phb_caller_res_id_struct phb_res_id;
    U16 disc_cause; /* disconnect cause */
    U32 total_cost_unit;
#ifdef __MMI_VIDEO_TELEPHONY__
    MMI_BOOL start_count; /* MMI_TRUE when start_count is handled (may be set before MO/MT is connected due to primitive out of order */
#endif /* __MMI_VIDEO_TELEPHONY__ */
} srv_gcall_call_info_struct;


typedef struct
{
#ifdef __AUTO_CALL_REJECTION__
    U8 call_present_id; /* 0 for invalid */
    U8 seq_num; /* sequence number for presented-call */
#endif /* __AUTO_CALL_REJECTION__ */
    l4c_number_struct l4c_number;
    U8 presentation_ind; /* cc_presentation_ind_enum */
    U16 backlight_pattern_id;
    U8 alert_type;
#ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
    U8 no_cli_cuase; /* csmcc_no_cli_cause_enum */
#endif
} srv_gcall_mt_info_struct;


typedef struct
{
    U8 num[SRV_GCALL_MAX_NUMBER];
#ifdef __IP_NUMBER__
    MMI_BOOL is_ip_dial;
#endif /* __IP_NUMBER__ */
    srv_ucm_module_origin_enum module_id;
} srv_gcall_mo_info_struct;


typedef struct
{
    void *phb_data; /* keep phb parameter for redial and post action */
    U8 max_attempt;
    U8 curr_attempt;
    U8 timer; /* seconds to the next attempt */
    U8 msg[150];
} srv_gcall_redial_struct;


typedef struct
{
    U8 call_id;
    U8 group_id;
    srv_gcall_type_enum call_type;
    srv_gcall_state_enum state;
    U16 cause;
    MMI_BOOL post_action;
    MMI_BOOL is_abort;
    srv_gcall_dir_enum dir;
} srv_gcall_release_call_struct;


typedef struct
{
    srv_ucm_int_act_opcode_enum op; /* ucm operation code, only can be used when ucm rsp is needed */
    srv_ucm_int_act_opcode_enum bg_op; /* ucm background operation code */
    srv_ucm_call_type_enum call_type; /* only can be used when ucm rsp is needed */
    U8 l4c_source; /* l4c_source_id_enum */
    srv_ucm_int_act_rsp_callback_func_ptr rsp_cb; /* only can be used when ucm rsp is needed */
    void *user_data; /* only can be used when ucm rsp is needed */
} srv_gcall_ucm_info_struct; /* info got from ucm */


typedef struct
{
    l4c_number_struct *num_p;
    l4c_sub_addr_struct *sub_addr_p;
    U8 call_type; /* csmcc_call_type_enum */
    U8 call_id;
    U8 addr_ind_present;    
    U8 addr_ind;
    U8 no_cli_cause_present;
    U8 no_cli_cause;
    U8 name_present;
    U8 *name;
    U8 dcs;
    U8 length;
} srv_gcall_mt_alert_struct; /* derive info from call_ring_ind / call_wait_ind */


#ifdef __CCBS_SUPPORT__
typedef struct
{
    U8 call_id;
    U8 number[SRV_GCALL_MAX_NUMBER];
    srv_gcall_ccbs_state_enum state;
} srv_gcall_ccbs_struct;
#endif /* __CCBS_SUPPORT__ */


#ifdef __CPI_SUPPORT__
typedef struct
{
    U8 call_id;
    srv_gcall_state_enum state;
} srv_gcall_change_call_state_struct;


typedef struct
{
    U8 call_id;
    srv_gcall_type_enum call_type;
} srv_gcall_mo_id_assign_struct;
#endif /* __CPI_SUPPORT__ */


typedef struct
{
    kal_bool    number_present;
    l4c_number_struct   addr;
    kal_bool    sub_addr_present;
    l4c_sub_addr_struct sub_addr;
} srv_gcall_l4c_addr_struct;


typedef struct
{
    U8 chld_type; /* csmcc_crss_req_enum */
    U16 rsp_event; /* msg id */
} srv_gcall_ps_info_struct;


typedef struct
{
    U8 call_id;
    U8 buf[SRV_GCALL_MAX_DTMF_DIGITS];
} srv_gcall_auto_dtmf_struct;


typedef struct
{
    U16 event;
    MMI_BOOL notify_present;
    U16 notify;
} srv_gcall_ss_notify_struct;


typedef struct
{
    mmi_sim_enum interface;
    srv_gcall_ucm_info_struct ucm_info; /* life cycle: ucm_req~ ucm_rsp */
    srv_gcall_ps_info_struct ps_info;
    srv_gcall_call_info_struct call_list[SRV_GCALL_MAX_CALL];
    srv_gcall_mt_info_struct mt; /* life cycle: same as the incoming call's life cycle (reset when incoming call becomes idle or active call) */
    srv_gcall_mo_info_struct mo; /* life cycle: same as the outgoing call's life cycle */
    srv_phb_caller_info_struct phb_data; /* life cycle: same as the incoming/outgoing call's life cycle */
    srv_gcall_redial_struct redial_info;
    srv_gcall_auto_dtmf_struct auto_dtmf_info;
    U8 auto_reject_call_id;
    srv_gcall_release_call_struct release_call_info; /* keep the info in the release procedures; life cycle: release_ind phdlr */
    mmi_data_call_req_ind_struct *data_call_info_p;
#ifdef __CCBS_SUPPORT__
    srv_gcall_ccbs_struct ccbs_info; /* life cycle: ccbs activation ~ chld_rsp (accept ccbs) */
#endif /* __CCBS_SUPPORT__ */
    MMI_BOOL dtmf_started;
    srv_gcall_ss_notify_struct ss_notify_info;
    MMI_BOOL nw_available;
} srv_gcall_cntxt_struct;




extern srv_gcall_cntxt_struct *cm_p;

/* GCallSrvCmInterface.c */
extern void srv_gcall_cmhdlr_act_req(srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum act_op, void *ptr, void *user_data, srv_ucm_int_act_rsp_callback_func_ptr rsp_callback);
extern srv_ucm_result_enum srv_gcall_cmhdlr_prmt(srv_ucm_call_type_enum call_type, srv_ucm_int_prmt_opcode_enum prmt_type, void *ptr);
extern MMI_BOOL srv_gcall_cmhdlr_query(srv_ucm_call_type_enum call_type, srv_ucm_int_query_enum query_type, void *ptr);
extern void srv_gcall_cmhdlr_cnf(srv_ucm_call_type_enum call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr);
extern void srv_gcall_cmhdlr_cnf_auto_dtmf(srv_ucm_call_type_enum ucm_call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr);
extern void srv_gcall_cmhdlr_abort_redial_sim1(void);
#if (MMI_MAX_SIM_NUM >= 2)
extern void srv_gcall_cmhdlr_abort_redial_sim2(void);
#if (MMI_MAX_SIM_NUM >= 3)
extern void srv_gcall_cmhdlr_abort_redial_sim3(void);
#if (MMI_MAX_SIM_NUM == 4)
extern void srv_gcall_cmhdlr_abort_redial_sim4(void);
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
extern void srv_gcall_cmhdlr_abort_auto_redial(mmi_sim_enum sim);
#ifdef __CCBS_SUPPORT__
extern void srv_gcall_cmhdlr_cnf_ccbs_recall(srv_ucm_call_type_enum ucm_call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr);
extern void srv_gcall_cmhdlr_cnf_ccbs_activate(srv_ucm_call_type_enum ucm_call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr);
#endif /* __CCBS_SUPPORT__ */
extern void srv_gcall_ucm_error(srv_ucm_call_type_enum ucm_call_type, U16 result);
extern void srv_gcall_ucm_dial_rsp(U16 result, U8 *error_msg);
extern void srv_gcall_ucm_act_rsp(U16 result, U8 *error_msg);
extern void srv_gcall_ucm_call_present_cnf_ind(void *info);
extern void srv_gcall_ucm_ring_ind(void);
extern void srv_gcall_ucm_dial_cnf_ind(srv_gcall_type_enum call_type, U8* number);
extern void srv_gcall_ucm_dial_ind(U16 result, U8 *error_msg);
extern void srv_gcall_ucm_notify_ind(srv_gcall_type_enum call_type, PU8 error_msg, U16 image_id, U16 tone_id);
extern void srv_gcall_ucm_connect_ind(srv_gcall_call_info_struct *call_info);
extern void srv_gcall_ucm_speech_ind(MMI_BOOL turn_on, U8 rat, srv_gcall_type_enum call_type);
extern void srv_gcall_ucm_cancel_query_cnf_ind(srv_gcall_type_enum call_type);
extern void srv_gcall_ucm_cancel_query_ind_by_call_id(U8 call_id, srv_gcall_type_enum call_type);
extern void srv_gcall_ucm_release_ind(void);
extern void srv_gcall_ucm_auto_redial_ind(void);
extern void srv_gcall_ucm_disconnecting_ind(srv_gcall_call_info_struct *call_info);
extern void srv_gcall_ucm_sync_call_list_ind(void);
extern void srv_gcall_ucm_alert_ind(srv_gcall_call_info_struct *call_info, U8 gen_tone);
extern void srv_gcall_ucm_auto_dtmf_cnf_ind(void);
#ifdef __AOC_SUPPORT__
extern void srv_gcall_ucm_call_cost_ind(void *info);
#endif /* __AOC_SUPPORT__ */
extern U16 srv_gcall_ucm_make_voice_call(CHAR *number, U8 module_id);
extern void srv_gcall_ucm_replace_ind(srv_gcall_call_info_struct *call_info);
#ifdef __CCBS_SUPPORT__
extern void srv_gcall_ucm_ccbs_recall_cnf_ind(void);
extern void srv_gcall_ucm_ccbs_activation_cnf_ind(void);
#endif /* __CCBS_SUPPORT__ */
#ifdef __MMI_VIDEO_TELEPHONY__
extern void srv_gcall_ucm_start_count_ind(srv_gcall_call_info_struct *call_info);
#endif /* __MMI_VIDEO_TELEPHONY__ */
extern MMI_BOOL srv_gcall_post_act_evt(srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum act_op, void *ptr, void *user_data, srv_ucm_int_act_rsp_callback_func_ptr rsp_callback);
extern MMI_BOOL srv_gcall_post_cnf_evt(srv_ucm_call_type_enum call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr, srv_ucm_int_cnf_callback_func_ptr cb);
extern void* srv_gcall_post_copy_act_data(srv_ucm_int_act_opcode_enum act_op, void *from);
extern void* srv_gcall_post_copy_cnf_data(srv_ucm_int_cnf_opcode_enum cnf_type, void *from);
extern mmi_sim_enum srv_gcall_get_interface_with_ucm_call_type(srv_ucm_call_type_enum call_type);
extern void srv_gcall_get_ucm_call_list(srv_ucm_int_call_list_struct *call_list);
extern srv_ucm_call_type_enum srv_gcall_get_ucm_call_type(srv_gcall_type_enum call_type);
extern void srv_gcall_set_remote_line_icon(srv_gcall_call_info_struct *from, srv_ucm_remote_info_struct *remote_info);
extern void srv_gcall_set_uid_info(srv_ucm_id_info_struct *uid_info, U8 call_id, U8 group_id, srv_gcall_type_enum call_type);


/* GCallSrvCmEvent.c */
extern void srv_gcall_proc_cm_event(srv_gcall_cm_event_enum event, void *info);
extern U16 srv_gcall_cm_accept(void* info);
extern U16 srv_gcall_cm_dial_cnf(void *info);
extern U16 srv_gcall_cm_dial_normal(void *info);
#ifdef __SAT__
extern U16 srv_gcall_cm_dial_sat(void *info);
#endif /* __SAT__ */
extern U16 srv_gcall_cm_dial(void *info);
extern U16 srv_gcall_cm_end_single(void *info);
extern U16 srv_gcall_cm_end_conf(void *info);
extern U16 srv_gcall_cm_end_all(void *info);
extern U16 srv_gcall_cm_end_all_ext(MMI_BOOL excpt_wait, void *info);
extern U16 srv_gcall_cm_auto_reject(void *info);
extern U16 srv_gcall_cm_force_release(void *info);
extern U16 srv_gcall_cm_swap(void* info);
extern U16 srv_gcall_cm_conf(void* info);
extern U16 srv_gcall_cm_split(void* info);
#ifdef __MMI_UCM_ECT__
extern U16 srv_gcall_cm_ect(void* info);
#endif /* __MMI_UCM_ECT__ */
#ifdef __MMI_UCM_DEFLECT__
extern U16 srv_gcall_cm_deflect(void *info);
#endif /* __MMI_UCM_DEFLECT__ */
extern U16 srv_gcall_cm_start_dtmf(void *info);
extern U16 srv_gcall_cm_stop_dtmf(void);
extern U16 srv_gcall_cm_auto_dtmf(void);
#ifdef __AUTO_CALL_REJECTION__
extern U16 srv_gcall_cm_mt_present_init(void);
extern U16 srv_gcall_cm_mt_present_cnf(void *info);
#endif /* __AUTO_CALL_REJECTION__ */
#ifdef __CPI_SUPPORT__
extern U16 srv_gcall_cm_cpi_init(void);
#endif /* __CPI_SUPPORT__ */
#ifdef __CCBS_SUPPORT__
extern U16 srv_gcall_cm_dial_ccbs(void *info);
extern U16 srv_gcall_cm_ccbs_accept(void);
extern U16 srv_gcall_cm_ccbs_reject(void);
extern U16 srv_gcall_cm_ccbs_ignore(void);
extern U16 srv_gcall_cm_ccbs_activate(void);
#endif /* __CCBS_SUPPORT__ */
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
extern U16 srv_gcall_cm_vt_fallto_voice(void *info);
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */


/* GCallSrvPsEvent.c */
extern void srv_gcall_proc_ps_event(srv_gcall_ps_event_enum event, void *info);
#ifdef __AUTO_CALL_REJECTION__
extern U16 srv_gcall_ps_mt_present(void *info);
extern U16 srv_gcall_ps_rel_present_call(void);
#endif /* __AUTO_CALL_REJECTION__ */
extern U16 srv_gcall_ps_mt_alert(srv_gcall_mt_alert_struct *info);
extern U16 srv_gcall_ps_dial_cnf_ind(void *info);
extern U16 srv_gcall_ps_mt_connected(void);
#ifdef __CPI_SUPPORT__
extern U16 srv_gcall_ps_mo_id_assigned(void *info);
extern U16 srv_gcall_ps_change_call_state(void *info);
#endif /* __CPI_SUPPORT__ */
extern U16 srv_gcall_ps_mo_connected(void *info);
extern U16 srv_gcall_ps_rel_outgoing(srv_gcall_call_info_struct *call_info);
extern U16 srv_gcall_ps_rel_incoming(srv_gcall_call_info_struct *call_info);
extern U16 srv_gcall_ps_rel_others(srv_gcall_call_info_struct *call_info);
extern U16 srv_gcall_ps_release(srv_gcall_call_info_struct *call_info);
extern U16 srv_gcall_ps_swap_suc(void);
extern U16 srv_gcall_ps_swap_fail(U16 result);
extern U16 srv_gcall_ps_sync_call_list(void* info);
extern U16 srv_gcall_ps_conf_suc(void);
extern U16 srv_gcall_ps_split_suc(void);
extern U16 srv_gcall_ps_split_fail(U16 result);
extern U16 srv_gcall_ps_disconnecting(srv_gcall_call_info_struct *call_info);
extern U16 srv_gcall_ps_speech(void *info);
extern U16 srv_gcall_ps_mo_alert(void *info);
extern U16 srv_gcall_ps_auto_dtmf(void *info);
#ifdef __AOC_SUPPORT__
extern U16 srv_gcall_ps_update_call_cost(void *info);
#endif /* __AOC_SUPPORT__ */
extern U16 srv_gcall_ps_ss_notify(srv_gcall_call_info_struct *call_info);
extern U16 srv_gcall_ps_make_call_req_ind(void *info);
extern U16 srv_gcall_ps_call_sync_req_ind(void);
extern U16 srv_gcall_ps_change_nw_status(void *info);
#ifdef __MMI_CM_CNAP_SUPPORT__
extern U16 srv_gcall_ps_mt_update_name(void *info);
#endif /* __MMI_CM_CNAP_SUPPORT__ */
#ifdef __CCBS_SUPPORT__
extern U16 srv_gcall_ps_ccbs_recall(void *info);
extern U16 srv_gcall_ps_ccbs_recall_cancel(void);
extern U16 srv_gcall_ps_ccbs_accept_res(void* info);
extern U16 srv_gcall_ps_ccbs_activate_cnf_ind(srv_gcall_call_info_struct *call_info);
extern U16 srv_gcall_ps_ccbs_activate_suc(void);
#endif /* __CCBS_SUPPORT__ */
extern void srv_gcall_update_number(srv_gcall_call_info_struct *call_info, void *info);
extern void srv_gcall_redial(void);
extern MMI_BOOL srv_gcall_redial_is_set(void);
extern MMI_BOOL srv_gcall_redial_set_max_attempt(U16 cause);
extern MMI_BOOL srv_gcall_redial_set_backoff(U16 cause);


/* GCallSrvPsInterface.c */
#ifdef __AUTO_CALL_REJECTION__
extern void srv_gcall_l4c_call_present_res_req(U8 approval, U8 call_id, U8 seq_num);
#endif /* __AUTO_CALL_REJECTION__ */
#ifdef __CPI_SUPPORT__
extern void srv_gcall_l4c_cpi_req(void); 
#endif /* __CPI_SUPPORT__ */
extern void srv_gcall_l4c_ata_req(void);
extern void srv_gcall_l4c_data_call_res_req(U8 op, MMI_BOOL result);
extern void srv_gcall_l4c_ss_parsing_string_req(void);
extern void srv_gcall_l4c_chld_req(U8 op_code, U8 call_id);
extern void srv_gcall_l4c_rel_comp_req(U8 call_id);
#ifdef __MMI_UCM_DEFLECT__
extern void srv_gcall_l4c_call_deflect_req(U8 *number);
#endif /* __MMI_UCM_DEFLECT__ */
extern void srv_gcall_l4c_get_call_list_req(void);
extern void srv_gcall_l4c_start_dtmf_req(U16 *MsgStruct);
extern void srv_gcall_l4c_stop_dtmf_req(void);
extern void srv_gcall_l4c_start_auto_dtmf_req(void);
#ifdef __MMI_VIDEO_TELEPHONY__
extern void srv_gcall_vt_uii(U16 *MsgStruct);
#endif /* __MMI_VIDEO_TELEPHONY__ */
extern void srv_gcall_phdlr_call_ring_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_call_wait_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_data_call_req_ind(void *info, int mod_src);
#ifdef __CPI_SUPPORT__
extern void srv_gcall_phdlr_cpi_ind(void *info, int mod_src);
#endif /* __CPI_SUPPORT__ */
extern void srv_gcall_phdlr_dial_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_call_connect_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_call_release_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_call_disconnect_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_speech_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_internal_alert_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_start_auto_dtmf_ind(void *info, int mod_src);
#ifdef __AOC_SUPPORT__
extern void srv_gcall_phdlr_ccm_ind(void *info, int mod_src);
#endif /* __AOC_SUPPORT__ */
extern void srv_gcall_phdlr_notify_ss_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_make_call_req_ind(void *info, int mod_src);
extern void srv_gcall_phdlr_call_sync_req_ind(void *info, int mod_src);
#if (MMI_MAX_SIM_NUM >= 2)
extern void srv_gcall_phdlr_nw_mmrr_service_status_ind(void *info, int mod_src);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#ifdef __MMI_CM_CNAP_SUPPORT__
extern void srv_gcall_phdlr_notify_ss_cnap_ind(void *info, int mod_src);
#endif /* __MMI_CM_CNAP_SUPPORT__ */
#ifdef __AUTO_CALL_REJECTION__
extern void srv_gcall_phdlr_call_present_ind(void *info, int mod_src);
#endif /* __AUTO_CALL_REJECTION__ */
#ifdef __CCBS_SUPPORT__
extern void srv_gcall_phdlr_notify_ss_ccbs_ind(void *info, int mod_src);
#endif /* __CCBS_SUPPORT__ */
extern void srv_gcall_phdlr_ata_rsp(void *info, int mod_src);
extern void srv_gcall_phdlr_ss_parsing_string_rsp(void *info, int mod_src);
#ifdef __MMI_UCM_DEFLECT__
extern void srv_gcall_phdlr_call_deflect_rsp(void *info, int mod_src);
#endif /* __MMI_UCM_DEFLECT__ */
extern void srv_gcall_phdlr_chld_rsp(void *info, int mod_src);
extern void srv_gcall_phdlr_get_call_list_rsp(void *info, int mod_src);
#ifdef __MMI_VIDEO_TELEPHONY__
extern void srv_gcall_phdlr_start_counter_ind(void *info, int mod_src);
#endif /* __MMI_VIDEO_TELEPHONY__ */
extern mmi_sim_enum srv_gcall_get_interface_with_src_mod(int src_mod);
extern module_type srv_gcall_get_l4c_mod_id(void);
extern void srv_gcall_set_ps_event_handler(PsExtFuncPtr func, U16 event);
extern void srv_gcall_reset_ps_event_handler(U16 event);
extern void srv_gcall_phdlr_set_release_call_info(srv_gcall_call_info_struct *call_info, U16 cause);


/* GCallSrvStructMgmt.c */ 
extern void srv_gcall_init_cntxt(mmi_sim_enum interface);
extern void srv_gcall_init_phdlr(void);
extern void srv_gcall_init_cmhdlr(void);
extern void srv_gcall_cntxt_set_ptr(mmi_sim_enum interface);
extern void srv_gcall_cntxt_reset_ptr(void);
extern MMI_BOOL srv_gcall_cntxt_is_locked(void);
extern U16 srv_gcall_prmt(srv_ucm_int_prmt_opcode_enum prmt_type, void *ptr);
extern U16 srv_gcall_prmt_accept(void *ptr);
extern U16 srv_gcall_prmt_accept_ext(MMI_BOOL is_compound_op, void *ptr);
extern U16 srv_gcall_prmt_dial(void *info);
extern U16 srv_gcall_prmt_dial_ext(srv_ucm_int_prmt_opcode_enum op, srv_ucm_call_type_enum ucm_call_type, PU8 number, srv_gcall_dir_enum dir);
extern U16 srv_gcall_prmt_hold_and_dial(void *ptr);
extern U16 srv_gcall_prmt_hold_and_accept(void *ptr);
extern U16 srv_gcall_prmt_end_all_and_dial(void *ptr);
extern U16 srv_gcall_prmt_end_all_and_accept(void* ptr);
extern U16 srv_gcall_prmt_end_all_active_and_accept(void* ptr);
extern U16 srv_gcall_prmt_end_all_active_and_retrieve(void* ptr);
extern U16 srv_gcall_prmt_end_single(void *ptr);
extern U16 srv_gcall_prmt_end_conf(void *ptr);
extern U16 srv_gcall_prmt_end_all(void);
extern U16 srv_gcall_prmt_end_all_active(void);
extern U16 srv_gcall_prmt_auto_reject(void* ptr);
extern U16 srv_gcall_prmt_force_release(void* ptr);
extern U16 srv_gcall_prmt_hold(void* info);
extern U16 srv_gcall_prmt_retrieve(void* info);
extern U16 srv_gcall_prmt_retrieve_ext(MMI_BOOL is_compond_op, void* info);
extern U16 srv_gcall_prmt_swap(void* info);
extern U16 srv_gcall_prmt_conf(void* info);
extern U16 srv_gcall_prmt_split(void* info);
#ifdef __MMI_UCM_ECT__
extern U16 srv_gcall_prmt_ect(void* info);
#endif
#ifdef __MMI_UCM_DEFLECT__
extern U16 srv_gcall_prmt_deflect(void* info);
#endif
extern U16 srv_gcall_prmt_start_dtmf(void* info);
extern U16 srv_gcall_prmt_stop_dtmf(void);
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
extern U16 srv_gcall_prmt_vt_fallto_voice(void* ptr);
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */
extern void srv_gcall_add_new_call_info(
        PU8 number,
        srv_gcall_state_enum curr_state,
        srv_gcall_dir_enum dir,
        U8 call_id,
        srv_gcall_type_enum call_type);
extern srv_gcall_call_info_struct *srv_gcall_get_call_info(srv_gcall_call_info_op_enum op, U8 info);
extern U8 srv_gcall_get_call_count(MMI_BOOL with_state, srv_gcall_state_enum state, srv_gcall_type_enum call_type);
extern U8 srv_gcall_get_sim_interface(mmi_sim_enum interface);
extern U16 srv_gcall_get_sms_sim_interface(mmi_sim_enum interface);
extern void srv_gcall_set_alert_info(srv_gcall_call_info_struct *call_info);
extern void srv_gcall_set_l4c_source(U8 src);
extern U8 srv_gcall_get_free_index(void);
extern U8 srv_gcall_get_free_group_id(void);
#ifdef __MMI_CM_CNAP_SUPPORT__
extern void srv_gcall_set_cnap_name(U8 call_id, U8 dcs, U8 length, U8 *cnap_name);
#endif /* __MMI_CM_CNAP_SUPPORT__ */
extern void srv_gcall_derive_display_name(srv_gcall_call_info_struct *call_info, PU8 out_str, U16 max_len);
#ifdef __MMI_UCM_NUMBER_TYPE__
extern U16 srv_gcall_derive_number_type_icon(mmi_phb_num_type_enum number_type);
#endif /* __MMI_UCM_NUMBER_TYPE__ */
extern PU8 srv_gcall_get_call_log_name(srv_gcall_call_info_struct *call_info);
extern PU8 srv_gcall_get_call_log_number(srv_gcall_call_info_struct *call_info);
extern MMI_BOOL srv_gcall_get_caller_res_info(void *info);
extern MMI_BOOL srv_gcall_op_is_busy(srv_ucm_int_prmt_opcode_enum act_op);
extern MMI_BOOL srv_gcall_is_any_disconnecting(U8 group_id);
extern MMI_BOOL srv_gcall_is_tmp_not_available(void);
extern void srv_gcall_reset_redial_info(void);
extern void srv_gcall_reset_call_info(srv_gcall_call_info_struct *call_info);
extern void srv_gcall_reset_release_call_info(void);
extern void srv_gcall_reset_mo_info(void);
extern void srv_gcall_reset_ucm_info_except_bg_op(void);
extern void srv_gcall_reset_auto_dtmf_info(void);
#ifdef __CCBS_SUPPORT__
extern void srv_gcall_reset_ccbs_info(void);
#endif /* __CCBS_SUPPORT__ */


/* GCallSrvUtil.c */
#ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
extern void srv_gcall_util_get_no_cli_display_text(U8 cause, PU8 no_cli_display_text);  
#endif /* __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__ */
extern MMI_BOOL srv_gcall_util_type_available(srv_ucm_call_type_enum call_type, MMI_BOOL is_ecc);
extern MMI_BOOL srv_gcall_util_op_need_rsp(srv_ucm_int_act_opcode_enum act_op);
extern MMI_BOOL srv_gcall_util_op_is_exclusive(srv_ucm_int_act_opcode_enum op);
extern MMI_BOOL srv_gcall_util_is_valid_number(mmi_sim_enum interface, PU8 number, srv_gcall_dir_enum dir);
extern ecc_call_type_enum srv_gcall_util_get_ecc_type(mmi_sim_enum interface, srv_gcall_dir_enum dir);
extern MMI_BOOL srv_gcall_util_is_valid_ecc(mmi_sim_enum interface, PU8 number, srv_gcall_dir_enum dir);
extern MMI_BOOL srv_gcall_util_is_valid_dtmf(U16 digit);
extern MMI_BOOL srv_gcall_util_is_data_csd(srv_gcall_type_enum call_type);
extern U8 srv_gcall_util_convert_dtmf_to_ascii(U16 *digit);
extern U16 srv_gcall_util_get_ss_notify_str_id(U16 event);
extern srv_gcall_type_enum srv_gcall_util_get_internal_call_type(srv_ucm_call_type_enum ucm_call_type);
extern srv_ucm_result_enum srv_gcall_util_get_ucm_result(U16 result);
extern srv_ucm_call_state_enum srv_gcall_util_get_ucm_call_state(srv_gcall_state_enum state);
extern srv_ucm_int_call_origin_enum srv_gcall_util_get_ucm_origin(srv_gcall_dir_enum dir);
extern U8 srv_gcall_util_is_reset_csp_group_service(mmi_sim_enum sim, U8 group, U8 srv);
#ifdef __IP_NUMBER__
extern void srv_gcall_util_get_curr_ip_number_ucs2(mmi_sim_enum sim, WCHAR *buf);
#endif /* __IP_NUMBER__ */
extern srv_ucm_call_type_enum srv_gcall_util_get_ucm_single_call_type(srv_ucm_call_type_enum call_type);
extern MMI_BOOL srv_gcall_util_mgmt_phb_info(MMI_BOOL is_hold, void *user_data);
 
#endif /* SRV_GCALL_PROT_H */ 

