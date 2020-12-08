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
 *  UcmSrvIntProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM 3.0 internal interface 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SRV_UCM_INT_PROT_H
#define SRV_UCM_INT_PROT_H

#ifndef SRV_UCM_GPROT_H
#error "Please include UcmSrvGprot.h first"
#endif /* SRV_UCM_GPROT_H */

#include "UcmSrvGprot.h"
#include "MMIDataType.h"
#include "ps_public_struct.h"
#include "kal_general_types.h"
//#include "wgui_categories_list.h"
//#include "MessagesMiscell.h"
#include "FileMgrSrvGProt.h"

/* Maximum call number in each call service */
#define SRV_UCM_MAX_CALL_IN_CALL_SRV (7)

/* Action opcode enum, call srv needs to implement all action functions */
typedef enum
{
    SRV_UCM_INT_NO_ACT = 0, /* No action */
    SRV_UCM_INT_DIAL_ACT, /* Dial action, srv_ucm_int_dial_act_req_struct, srv_ucm_int_dial_act_rsp_struct*/
    SRV_UCM_INT_ACCEPT_ACT, /* Accept action, srv_ucm_int_single_call_act_req_struct, srv_ucm_int_act_rsp_struct*/
    SRV_UCM_INT_HOLD_ACT, /* Hold action, srv_ucm_int_single_group_act_req_struct, srv_ucm_int_act_rsp_struct*/
    SRV_UCM_INT_RETRIEVE_ACT, /* Retrieve action, srv_ucm_int_single_group_act_req_struct, srv_ucm_int_act_rsp_struct */
    SRV_UCM_INT_SWAP_ACT,  /* Swap action, srv_ucm_int_multiple_group_act_req_struct, srv_ucm_int_act_rsp_struct */
    SRV_UCM_INT_CONFERENCE_ACT, /* Conference action, srv_ucm_int_multiple_group_act_req_struct, srv_ucm_int_act_rsp_struct */
    SRV_UCM_INT_SPLIT_ACT, /* Split action, srv_ucm_int_single_call_act_req_struct, srv_ucm_int_act_rsp_struct */
#ifdef __MMI_UCM_DEFLECT__
    SRV_UCM_INT_DEFLECT_ACT, /* Deflect action, srv_ucm_int_cd_or_ct_act_req_struct, srv_ucm_int_act_rsp_struct */
#endif /* __MMI_UCM_DEFLECT__ */
#ifdef __MMI_UCM_TRANSFER__
    SRV_UCM_INT_TRANSFER_ACT, /* Transfer action, srv_ucm_int_cd_or_ct_act_req_struct, srv_ucm_int_act_rsp_struct */
#endif /* __MMI_UCM_TRANSFER__ */
    SRV_UCM_INT_END_SINGLE_ACT, /* End single action, srv_ucm_int_single_call_act_req_struct, srv_ucm_int_act_rsp_struct */
    SRV_UCM_INT_END_CONFERENCE_ACT, /* End conference action, srv_ucm_int_single_group_act_req_struct, srv_ucm_int_act_rsp_struct */
    SRV_UCM_INT_END_ALL_ACT, /* End all action, srv_ucm_int_end_all_act_req_struct, srv_ucm_int_act_rsp_struct */
    SRV_UCM_INT_FORCE_RELEASE_ACT, /* Force release action, srv_ucm_int_single_call_act_req_struct, no response*/
    SRV_UCM_INT_AUTO_REJECT_ACT, /* Auto reject action, srv_ucm_int_single_call_act_req_struct, no response */
#ifdef __MMI_UCM_ECT__
    SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT, /* ECT action, srv_ucm_int_ect_act_req_struct, srv_ucm_int_act_rsp_struct */
#endif /* __MMI_UCM_ECT__ */
    SRV_UCM_INT_START_DTMF_ACT, /* Start DTMF action, srv_ucm_dtmf_struct, no response */
    SRV_UCM_INT_STOP_DTMF_ACT, /* Stop DTMF action, null, no response */
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    SRV_UCM_INT_VT_FALLTO_VOICE_ACT, /* srv_ucm_int_single_call_act_req_struct, srv_ucm_int_act_rsp_struct*/
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
    SRV_UCM_INT_ACT_OPCODE_TOTAL /* Total enum number */
} srv_ucm_int_act_opcode_enum;

/* Action permit opcode enum, call srv needs to implement permit query functions, include compund actions */
typedef enum
{
    SRV_UCM_INT_DIAL_PRMT = SRV_UCM_INT_DIAL_ACT, /* srv_ucm_int_dial_act_prmt_struct, srv_ucm_result_enum*/
    SRV_UCM_INT_ACCEPT_PRMT = SRV_UCM_INT_ACCEPT_ACT, /* srv_ucm_int_single_call_act_prmt_struct, srv_ucm_result_enum*/
    SRV_UCM_INT_HOLD_PRMT = SRV_UCM_INT_HOLD_ACT, /* srv_ucm_int_single_group_act_prmt_struct, srv_ucm_result_enum*/
    SRV_UCM_INT_RETRIEVE_PRMT = SRV_UCM_INT_RETRIEVE_ACT, /* srv_ucm_int_single_group_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_SWAP_PRMT = SRV_UCM_INT_SWAP_ACT,  /* srv_ucm_int_multiple_call_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_CONFERENCE_PRMT = SRV_UCM_INT_CONFERENCE_ACT, /* srv_ucm_int_multiple_call_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_SPLIT_PRMT = SRV_UCM_INT_SPLIT_ACT, /* srv_ucm_int_single_call_act_prmt_struct, srv_ucm_result_enum */
#ifdef __MMI_UCM_DEFLECT__
    SRV_UCM_INT_DEFLECT_PRMT = SRV_UCM_INT_DEFLECT_ACT, /* srv_ucm_int_cd_or_ct_act_prmt_struct, srv_ucm_result_enum */
#endif /* __MMI_UCM_DEFLECT__ */
#ifdef __MMI_UCM_TRANSFER__
    SRV_UCM_INT_TRANSFER_PRMT = SRV_UCM_INT_TRANSFER_ACT, /* srv_ucm_int_cd_or_ct_act_prmt_struct, srv_ucm_result_enum */
#endif /* __MMI_UCM_TRANSFER__ */
    SRV_UCM_INT_END_SINGLE_PRMT = SRV_UCM_INT_END_SINGLE_ACT, /* srv_ucm_int_single_call_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_END_CONFERENCE_PRMT = SRV_UCM_INT_END_CONFERENCE_ACT, /* srv_ucm_int_single_group_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_END_ALL_PRMT = SRV_UCM_INT_END_ALL_ACT, /* srv_ucm_int_end_all_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_FORCE_RELEASE_PRMT = SRV_UCM_INT_FORCE_RELEASE_ACT, /* srv_ucm_int_single_call_act_prmt_struct, srv_ucm_result_enum*/
    SRV_UCM_INT_AUTO_REJECT_PRMT = SRV_UCM_INT_AUTO_REJECT_ACT, /* srv_ucm_int_single_call_act_prmt_struct, no srv_ucm_result_enum */
#ifdef __MMI_UCM_ECT__
    SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_PRMT = SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT, /* srv_ucm_int_ect_act_prmt_struct, srv_ucm_result_enum */
#endif /* __MMI_UCM_ECT__ */
    SRV_UCM_INT_START_DTMF_PRMT = SRV_UCM_INT_START_DTMF_ACT, /* srv_ucm_dtmf_struct, srv_ucm_result_enum */
    SRV_UCM_INT_STOP_DTMF_PRMT = SRV_UCM_INT_STOP_DTMF_ACT, /* null, srv_ucm_result_enum */
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    SRV_UCM_INT_VT_FALLTO_VOICE_PRMT = SRV_UCM_INT_VT_FALLTO_VOICE_ACT, /* srv_ucm_int_single_call_act_prmt_struct, srv_ucm_result_enum*/
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
    SRV_UCM_INT_END_ALL_AND_DIAL_PRMT = SRV_UCM_INT_ACT_OPCODE_TOTAL + 1, /* srv_ucm_int_dial_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_END_ALL_AND_ACCEPT_PRMT, /* srv_ucm_int_single_call_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_END_ALL_ACTIVE_AND_RETRIEVE_PRMT, /* srv_ucm_int_single_group_act_prmt_struct, srv_ucm_result_enum, UCM could use END_SINGLE or END_CONFERENCE to end all active */
    SRV_UCM_INT_END_ALL_ACTIVE_AND_ACCEPT_PRMT, /* srv_ucm_int_single_call_act_prmt_struct, srv_ucm_result_enum, UCM could use END_SINGLE or END_CONFERENCE to end all active */
    SRV_UCM_INT_HOLD_AND_DIAL_PRMT, /* srv_ucm_int_hold_and_dial_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_HOLD_AND_ACCEPT_PRMT, /* srv_ucm_int_hold_and_accept_act_prmt_struct, srv_ucm_result_enum */
    SRV_UCM_INT_ACT_PRMT_TOTAL /* Total enum number */
} srv_ucm_int_prmt_opcode_enum;

/* Indication opcode enum */
typedef enum
{
    SRV_UCM_INT_SYNC_CALL_LIST_IND = 0, /* srv_ucm_int_sync_call_list_ind_struct */
    SRV_UCM_INT_ALERT_IND, /* srv_ucm_int_alert_ind_struct */
    SRV_UCM_INT_CONNECT_IND, /* srv_ucm_int_connect_ind_struct */
    SRV_UCM_INT_NOTIFY_IND, /* srv_ucm_int_notify_ind_struct */
    SRV_UCM_INT_SESSION_IND, /* srv_ucm_int_session_ind_struct */
    SRV_UCM_INT_SPEECH_IND, /* srv_ucm_int_speech_ind_struct */
    SRV_UCM_INT_RING_IND, /* srv_ucm_int_ring_ind_struct */
    SRV_UCM_INT_DISCONNECTING_IND, /* srv_ucm_int_disconnecting_ind_struct */
    SRV_UCM_INT_RELEASE_IND, /* srv_ucm_int_release_ind_struct */
    SRV_UCM_INT_CALL_COST_IND, /* srv_ucm_int_call_cost_ind_struct */
    SRV_UCM_INT_AUTO_REDIAL_IND, /* srv_ucm_int_auto_redial_ind_struct */
    SRV_UCM_INT_START_PROCESSING_IND, /* srv_ucm_int_start_processing_ind_struct */
    SRV_UCM_INT_STOP_PROCESSING_IND, /* srv_ucm_int_stop_processing_ind_struct */
    SRV_UCM_INT_REPLACE_IND, /* srv_ucm_int_replace_ind_struct */
    SRV_UCM_INT_CANCEL_QUERY_IND, /* null */
    SRV_UCM_INT_DIAL_IND, /* Only follow after SRV_UCM_INT_DIAL_CNF ok, srv_ucm_int_dial_ind_struct */
    SRV_UCM_INT_START_COUNT_IND, /* null */
    SRV_UCM_INT_IND_OPCODE_TOTAL /* Total enum number */
} srv_ucm_int_ind_opcode_enum;

/* Confirm indication opcode enum */
typedef enum
{
    SRV_UCM_INT_DIAL_CNF_IND = 0, /* srv_ucm_int_dial_cnf_ind_struct */
    SRV_UCM_INT_CALL_PRESENT_CNF_IND, /* srv_ucm_int_call_present_cnf_ind_struct */
    SRV_UCM_INT_QUERY_CNF_IND, /* srv_ucm_int_query_cnf_ind_struct */
    SRV_UCM_INT_CNFIND_OPCODE_TOTAL /* Total enum number */
} srv_ucm_int_cnf_ind_opcode_enum;

/* Confirm opcode enum */
typedef enum
{
    SRV_UCM_INT_QUERY_CNF = 0, /* srv_ucm_int_query_cnf_struct */
    SRV_UCM_INT_DIAL_CNF, /* srv_ucm_int_dial_cnf_struct */
    SRV_UCM_INT_CALL_PRESENT_CNF, /* srv_ucm_int_call_present_cnf_struct */
    SRV_UCM_INT_CNF_OPCODE_TOTAL /* Total enum number */
} srv_ucm_int_cnf_opcode_enum;

/* Call origin enum, MO or MT */
typedef enum
{
    SRV_UCM_INT_NONE_ORIGIN = 0, /* None */
    SRV_UCM_INT_MO_ORIGIN, /* MO call */
    SRV_UCM_INT_MT_ORIGIN, /* MT call */
    SRV_UCM_INT_CALL_ORIGIN_TOTAL /* Total enum number */
} srv_ucm_int_call_origin_enum;

/* Query enum */
typedef enum
{
    SRV_UCM_INT_NUMBER = 0, /* Number validation, [IN]srv_ucm_int_query_number_struct */
    SRV_UCM_INT_ECC_NUMBER, /* Emergency number validation, [IN]srv_ucm_int_query_number_struct */
    SRV_UCM_INT_DTMF_DIGIT, /* DTMF digit number validdation, [IN]srv_ucm_dtmf_struct */
    SRV_UCM_INT_CALL_SRV_AVAILABLE, /* Call service availble or not, null */
    SRV_UCM_INT_CALL_SRV_TMP_UNAVAILABLE, /* Call service temporarily unavailable or not, null */
    SRV_UCM_INT_CALLER_RES, /* Caller resource, [IN/OUT]srv_ucm_int_query_caller_res_struct */
    SRV_UCM_INT_QUERY_TOTAL /* Total enum number */
} srv_ucm_int_query_enum;

/* Query confirm indication condition enum */
typedef enum
{
    SRV_UCM_DISP_OUTGOING = 0x01, /* Allowed to query during outgoing call state */
    SRV_UCM_DISP_INCOMING = 0x02, /* Allowed to query during incoming call state */
    SRV_UCM_DISP_ECC = 0x04, /* Allowed to query during emergency call */
    SRV_UCM_DISP_CONDITION_TOTAL /* Total enum number */
} srv_ucm_int_disp_condition_enum;


/* AT commanda related information */
typedef struct
{
    U8 l4c_source; /* l4c_source_id_enum. Source who triggers AT command, L4C needs this information */
    U8 l4c_type; /* Call type in L4C definition */
    l4c_number_struct l4c_number; /* Call number */
} srv_ucm_int_at_info_struct;

/* The structure of each entry in call list, how UCM sv and Call srv keep synchronization*/
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    srv_ucm_call_state_enum call_state; /* Call state */
} srv_ucm_int_call_list_entry_info_struct;

/* Single call action struct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    srv_ucm_id_info_struct action_uid; /* Call id */
} srv_ucm_int_single_call_act_req_struct;

/* Single group action struct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    S16 action_group; /* Group id */
} srv_ucm_int_single_group_act_req_struct;

/* Multiple group action struct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    S16 active_group; /* Active group id */
    S16 other_group; /* Other group id */
} srv_ucm_int_multiple_group_act_req_struct;

/* ECT action struct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    S16 first_group; /* First group id*/
    S16 second_group; /* Second group id */
} srv_ucm_int_ect_act_req_struct;

/* Dial action struct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number */
    MMI_BOOL is_ip_dial; /* IP dial, currently only for GSM&3G */
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} srv_ucm_int_dial_act_req_struct;

/* Call deflect or call transfer action struct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    srv_ucm_id_info_struct action_uid; /* Call id */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number */
} srv_ucm_int_cd_or_ct_act_req_struct;

/* End all struct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
} srv_ucm_int_end_all_act_req_struct;

/* Call list structure */
typedef struct
{
    srv_ucm_int_call_list_entry_info_struct call_info[SRV_UCM_MAX_CALL_IN_CALL_SRV]; /* Call list entry struct */
    srv_ucm_call_type_enum call_type; /* Call type */
    U8 total_num; /* Total number of entry in the call list */
} srv_ucm_int_call_list_struct;

/* Dial action response struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_result_info_struct result_info; /* Result */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    srv_ucm_display_info_struct display_info; /* Display info */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_dial_act_rsp_struct;

/* Action response struct */
typedef struct
{
    srv_ucm_result_info_struct result_info; /* Result */
    MMI_BOOL no_counter; /* Start to count duration or not, only for accept action */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_act_rsp_struct;

/* Dial action permit struct */
typedef srv_ucm_int_dial_act_req_struct srv_ucm_int_dial_act_prmt_struct;

/* Single call action permit struct */
typedef srv_ucm_int_single_call_act_req_struct srv_ucm_int_single_call_act_prmt_struct;

/* Single group action permit struct */
typedef srv_ucm_int_single_group_act_req_struct srv_ucm_int_single_group_act_prmt_struct;

/* Multiple group action permit struct */
typedef srv_ucm_int_multiple_group_act_req_struct srv_ucm_int_multiple_group_act_prmt_struct;

/* End all action permit struct */
typedef srv_ucm_int_end_all_act_req_struct srv_ucm_int_end_all_act_prmt_struct;

/* ECT action permit struct */
typedef srv_ucm_int_ect_act_req_struct srv_ucm_int_ect_act_prmt_struct;

/* Call deflect or call transfer action permit struct */
typedef srv_ucm_int_cd_or_ct_act_req_struct srv_ucm_int_cd_or_ct_act_prmt_struct;

/* Hold and dial action permit struct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    S16 active_group; /* Active group */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
    srv_ucm_call_type_enum dial_type; /* Dial call type */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number */
    MMI_BOOL is_ip_dial; /* IP dial, currently only for GSM&3G */
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} srv_ucm_int_hold_and_dial_act_prmt_struct;

/* Hold and accept permit sctuct */
typedef struct
{
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    S16 action_group; /* Active call group */
    srv_ucm_id_info_struct mt_call_uid; /* MT call id */
} srv_ucm_int_hold_and_accept_act_prmt_struct;

/* Sync call list indication struct */
typedef struct
{
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_sync_call_list_ind_struct;

/* Call alert indication struct*/
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    U8 local_gen; /* Generate calling tone locally or by network */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_alert_ind_struct;

/* Call connect indication struct*/
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    MMI_BOOL no_counter; /* Start to count duration or not */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_connect_ind_struct;

/* Notify indication stuct */
typedef struct
{
    srv_ucm_call_type_enum call_type; /* Call type */
    U16 disp_msg[SRV_UCM_MAX_DISP_MSG_LEN + 1]; /* Message to user, ucs2 */
    U16 image_id; /* Image to display */
    U16 tone_id; /* Tone to display */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_notify_ind_struct;

/* Session indication */
typedef struct
{
    U8 session_type; /* Session type */
    U8 session_switch; /* On or off */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_session_ind_struct;

/* Speech indication */
typedef struct
{
    srv_ucm_call_type_enum call_type; /* Call type */
    U8 session_type; /* Session type */
    U8 rtp_handle; /* Only for VoIP */
    U8 local_switch; /* Local on or off*/
    U8 remote_switch; /* Remote on or off */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_speech_ind_struct;

/* Incoming call indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    srv_ucm_display_info_struct display_info; /* Display info */
    srv_ucm_int_at_info_struct at_info; /* AT commanda related information */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_ring_ind_struct;

/* Disconnecting indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_disconnecting_ind_struct;

/* Release indication indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    U16 disp_msg[SRV_UCM_MAX_ERR_MSG_LEN + 1]; /* Call release recommand message according to error cause, ucs2 */
    U16 image_id; /* Call release image */
    U16 tone_id; /* Call release tone */
    srv_ucm_result_enum error_cause; /* Call release error cause */
    srv_ucm_post_action_struct post_action; /* Need to do post action or not */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_release_ind_struct;

/* Call cost indication struct*/
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    PU8 currency_symbol; /*  Currency symbol, ex: TWD, USD*/
    U32 cost_unit; /* How many unit spent */
    U32 total_cost_unit; /* Total unit spent */
    U32 price_per_unit; /* How much for each unit */
    MMI_BOOL warning; /* Almost no money left */
} srv_ucm_int_call_cost_ind_struct;

/* Auto redial indication struct */
typedef struct
{
    srv_ucm_call_type_enum call_type; /* Call type */
    U16 display_msg[SRV_UCM_MAX_AUTO_REDIAL_MSG_LEN + 1]; /* UCS2 */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Redial number */
    MMI_BOOL is_ip_dial; /* IP dial, currently only for GSM&3G */
    U8 attempt; /* Redial attempt */
    U8 time; /* Redial after how many seconds */
    FuncPtr abort_hdlr; /* Redial abort handler */
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} srv_ucm_int_auto_redial_ind_struct;

/* Start processing indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    U16 content[SRV_UCM_MAX_DISP_MSG_LEN + 1]; /* Message display to user, ucs2 */
} srv_ucm_int_start_processing_ind_struct;

/* Stop processing indication struct */
typedef struct
{
    U16 disp_msg[SRV_UCM_MAX_DISP_MSG_LEN + 1]; /* Message display to user, ucs2 */
    U16 image_id; /* Image display to user */
    U16 tone_id; /* Tone display to user */
} srv_ucm_int_stop_processing_ind_struct;

/* Replace indication struct */
typedef struct
{
    srv_ucm_id_info_struct old_uid_info; /* Old call id */
    srv_ucm_id_info_struct new_uid_info; /* New call id */
    srv_ucm_int_call_origin_enum call_origin; /* Call origin, only for active/hold call */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    MMI_BOOL reset_duration; /* Reset call duration or not, only for active/hold call */
    MMI_BOOL log_call_now; /* Log the old call or not */
} srv_ucm_int_replace_ind_struct;

/* Dial indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_result_info_struct result_info; /* Result */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    srv_ucm_display_info_struct display_info; /* Display info */
    srv_ucm_int_call_list_struct *call_list; /* Call list */
} srv_ucm_int_dial_ind_struct;

/* Dial confirm indication struct */
typedef struct
{
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number */
} srv_ucm_int_dial_cnf_ind_struct;

/* Incoming call confirm indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number */
} srv_ucm_int_call_present_cnf_ind_struct;

/* Query confirm indication struct */
typedef struct
{
    srv_ucm_int_disp_condition_enum disp_condition; /* Query confirm priority, condition */
    U16 content[SRV_UCM_MAX_DISP_MSG_LEN + 1]; /* The question for user, ucs2 */
} srv_ucm_int_query_cnf_ind_struct;

/* Query confirm struct */
typedef struct
{
    srv_ucm_query_cnf_result_enum result; /* Result */
} srv_ucm_int_query_cnf_struct;

/* Dial confirm struct */
typedef struct
{
    MMI_BOOL result; /* Result */
} srv_ucm_int_dial_cnf_struct;

/* Incoming call confirm struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    MMI_BOOL result; /* Result */
} srv_ucm_int_call_present_cnf_struct;

/* Number check query struct */
typedef struct
{
    srv_ucm_module_origin_enum module; /* Initiate module id */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number */
} srv_ucm_int_query_number_struct;


/* Caller resource struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id, input */
    srv_ucm_res_type_enum res_type; /* Resource type, output */
    U16 pic_id; /* Image id, output */
    U16 pic_path[SRV_FMGR_PATH_MAX_LEN + 1]; /* Image path, output */
    U16 video_id; /* Video id, output */
    U16 video_path[SRV_FMGR_PATH_MAX_LEN + 1]; /* Video path, output */
    U16 tone_id; /* Tone id, output */ 
    U16 tone_path[SRV_FMGR_PATH_MAX_LEN + 1]; /* Tone path, output */
    MMI_BOOL is_video_sound; /* Video sound on or off, output */
} srv_ucm_int_query_caller_res_struct;


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_ucm_int_act_rsp_callback_func_ptr
 * DESCRIPTION
 *  Action response callback function provided by UCM
 * PARAMETERS
 *  call_type:       [IN]        Call type type
 *  act_op:          [IN]        Action op-code
 *  rsp_data:        [IN]        Response data
 *  user_data:       [IN]        User data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_ucm_int_act_rsp_callback_func_ptr) (srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum act_op, void *rsp_data, void *user_data);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_ucm_int_act_callback_func_ptr
 * DESCRIPTION
 *  The action function provided by call srv
 * PARAMETERS
 *  call_type:       [IN]        Call type type
 *  act_op:          [IN]        Action op-code
 *  act_data:        [IN]        Action data
 *  user_data:       [IN]        User data
 *  rsp_callback:    [IN]        Response callback
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_ucm_int_act_callback_func_ptr) (srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum act_op, void *act_data, void *user_data, srv_ucm_int_act_rsp_callback_func_ptr rsp_callback);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_ucm_int_permit_callback_func_ptr
 * DESCRIPTION
 *  The action permit query function provided by call srv
 * PARAMETERS
 *  call_type:       [IN]        Call type type
 *  prmt_type:       [IN]        Action type
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  Result
 *****************************************************************************/
typedef srv_ucm_result_enum (*srv_ucm_int_permit_callback_func_ptr) (srv_ucm_call_type_enum call_type, srv_ucm_int_prmt_opcode_enum prmt_type, void *ptr);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_ucm_int_cnf_callback_func_ptr
 * DESCRIPTION
 *  The confirm callback function provided by call srv
 * PARAMETERS
 *  call_type:       [IN]        Call type type
 *  cnf_type:        [IN]        Confirm type
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_ucm_int_cnf_callback_func_ptr) (srv_ucm_call_type_enum call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_query_callback_func_ptr
 * DESCRIPTION
 *  The query callback function provided by call srv
 * PARAMETERS
 *  call_type:       [IN]        Call type type
 *  query_type:      [IN]        Query type
 *  ptr:             [IN][OUT][IN/OUT]   Data pointer; IN or OUT depends on query_type
 * RETURNS
 *  void
 *****************************************************************************/
typedef MMI_BOOL (*srv_ucm_int_query_callback_func_ptr) (srv_ucm_call_type_enum call_type, srv_ucm_int_query_enum query_type, void *ptr);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_register_call_srv_act_callback
 * DESCRIPTION
 * Call srv can register the action callback to UCM service
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 *  callback:        [IN]        Callback function
 * RETURNS
 *  MMI_TRUE means the callback registration succeeds.
 *  MMI_FALSE means the callback registration fails.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_int_register_call_srv_act_callback(srv_ucm_call_type_enum call_type, srv_ucm_int_act_callback_func_ptr callback);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_unregister_call_srv_act_callback
 * DESCRIPTION
 *  Call srv can unregister action function
 * PARAMETERS
 *  call_type:       [IN]        Call type type
 * RETURNS
 *  MMI_TRUE means the callback unregistration succeeds.
 *  MMI_FALSE means the callback unregistration fails.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_int_unregister_call_srv_act_callback(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_query_call_srv_act_callback
 * DESCRIPTION
 *  Call srv can query if the action function is registered
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 * RETURNS
 *  srv_ucm_int_act_callback_func_ptr
  *  NULL means no callback is registered
 *****************************************************************************/
extern srv_ucm_int_act_callback_func_ptr srv_ucm_int_query_call_srv_act_callback(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_register_call_srv_permit_callback
 * DESCRIPTION
 * Call srv can register the permit callback to UCM service
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, can be bitwise
 *  callback:        [IN]        Callback function
 * RETURNS
 *  MMI_TRUE means the callback registration succeeds.
 *  MMI_FALSE means the callback registration fails.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_int_register_call_srv_permit_callback(srv_ucm_call_type_enum call_type, srv_ucm_int_permit_callback_func_ptr callback);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_unregister_call_srv_permit_callback
 * DESCRIPTION
 *  Call srv can unregister action permit function
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, can be bitwise
 * RETURNS
 *  MMI_TRUE means the callback unregistration succeeds.
 *  MMI_FALSE means the callback unregistration fails.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_int_unregister_call_srv_permit_callback(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_query_call_srv_permit_callback
 * DESCRIPTION
 *  Call srv can query if the action permit function is registered
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, can be bitwise
 * RETURNS
 *  srv_ucm_int_permit_callback_func_ptr
 *  NULL means no callback is registered
 *****************************************************************************/
extern srv_ucm_int_permit_callback_func_ptr srv_ucm_int_query_call_srv_permit_callback(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_indication
 * DESCRIPTION
 *  The function provided by UCM for call srv to send inication
 * PARAMETERS
 *  call_type:       [IN]        Call type type
 *  op_code:         [IN]        Indication op code
 *  ind_data:        [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ucm_int_indication(srv_ucm_call_type_enum call_type, srv_ucm_int_ind_opcode_enum op_code, void *ind_data);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_cnf_indication
 * DESCRIPTION
 *  The function provided by UCM for call srv to send confirm inication
 * PARAMETERS
 *  call_type:       [IN]        Call type type
 *  op_code:         [IN]        Indication op code
 *  ind_data:        [IN]        Data pointer
 *  callback:        [IN]        Confirm callback function provided by call srv
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ucm_int_cnf_indication(srv_ucm_call_type_enum call_type, srv_ucm_int_cnf_ind_opcode_enum op_code, void *ind_data, srv_ucm_int_cnf_callback_func_ptr callback);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_register_call_srv_query_callback
 * DESCRIPTION
 * Call srv can register the query callback to UCM service
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 *  callback:        [IN]        Callback function
 * RETURNS
 *  MMI_TRUE means the callback registration succeeds.
 *  MMI_FALSE means the callback registration fails.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_int_register_call_srv_query_callback(srv_ucm_call_type_enum call_type, srv_ucm_int_query_callback_func_ptr callback);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_unregister_call_srv_query_callback
 * DESCRIPTION
 *  Call srv can unregister query function
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 * RETURNS
 *  MMI_TRUE means the callback unregistration succeeds.
 *  MMI_FALSE means the callback unregistration fails.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_int_unregister_call_srv_query_callback(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_query_callback_func_ptr
 * DESCRIPTION
 *  Call srv can query if the query function is registered
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 * RETURNS
 *  srv_ucm_int_query_callback_func_ptr
 *  NULL means no callback is registered
 *****************************************************************************/
extern srv_ucm_int_query_callback_func_ptr srv_ucm_int_query_call_srv_query_callback(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_malloc
 * DESCRIPTION
 *  Call list is too large, UCM provides memory allocation function for call srv
 * PARAMETERS
 *  size:            [IN]        size
 * RETURNS
 *  pointer
 *****************************************************************************/
extern void* srv_ucm_int_malloc(U32 size);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_mfree
 * DESCRIPTION
 *  Memory free function provided by UCM
 * PARAMETERS
 *  p:               [IN]        pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ucm_int_mfree(void* p);

#endif /* SRV_UCM_INT_PROT_H */

