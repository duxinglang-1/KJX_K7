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
 *  UcmCoreProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM app core internal header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_CORE_PROT_H
#define UCM_CORE_PROT_H


/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "customer_ps_inc.h"  /* for MMI_EMAIL_MAX_ADDR_LEN */
#include "mmi_res_range_def.h"

#include "UcmSrvGprot.h"
#include "ProfilesSrvGprot.h"


/****************************************************************************
 * Define
 ****************************************************************************/
#define MMI_UCM_VIB_WHEN_CONNECT_DURATION 500

/* VT can not co-exist with other call types */
#define MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE    (srv_ucm_call_type_enum)(SRV_UCM_VIDEO_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE_SIM2)
/* CSD priority < other call types */
#define MMI_UCM_EXIST_CALL_TYPE_FOR_CHECK_END_ALL    (SRV_UCM_CALL_TYPE_DATA_CSD_ALL)

/*------------------------ UHA related------------------------*/
#define MMI_UCM_UHA_EXT_NUM_STRING  "ext"
#ifdef __MMI_3G_SWITCH__
#define MMI_UCM_UHA_SUPPORT_CALL_TYPE (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL)
#else /* __MMI_3G_SWITCH__ */
#define MMI_UCM_UHA_SUPPORT_CALL_TYPE (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE)
#endif /* __MMI_3G_SWITCH__ */


/****************************************************************************
 * Typedef
 ****************************************************************************/
#ifdef __MMI_FTE_SUPPORT__
typedef enum
{
    MMI_UCM_UNLOCK_STATE,
    MMI_UCM_WTL_STATE, /* wait to lock */
    MMI_UCM_LOCK_STATE,
    MMI_UCM_AUTO_LOCK_STATE_TOTAL
}mmi_ucm_auto_lock_state_enum;


typedef enum
{
    MMI_UCM_AL_OUTGOING_EVENT,
    MMI_UCM_AL_INCOMING_EVENT,
    MMI_UCM_AL_RELEASE_EVENT,
    MMI_UCM_AL_ACCEPT_EVENT,
    MMI_UCM_AL_CONNECT_EVENT,
    MMI_UCM_AL_UNLOCK_EVENT,
    MMI_UCM_AL_WTL_TIMEOUT_EVENT, /* Wait to lock timeout*/
    MMI_UCM_AL_FORCE_LOCK_EVENT,  /* Force to lock */
    MMI_UCM_AL_EVENT_TOTAL
} mmi_ucm_auto_lock_trigger_event_enum;
#endif /* __MMI_FTE_SUPPORT__ */


typedef enum
{
    MMI_UCM_PERMIT_ONLY = 0,
    MMI_UCM_EXEC_IF_PERMIT_PASS,
    MMI_UCM_CHECK_TYPE_TOTAL
}mmi_ucm_check_type_enum;


typedef enum
{
    MMI_UCM_ECC_HDLR_PASS_AND_DIALED = 0,
    MMI_UCM_ECC_HDLR_ALL_PASS, /* the number is ECC for all given types, but can not allow to dial */
    MMI_UCM_ECC_HDLR_NOT_PASS, /* the number is not ECC for all given types */
    MMI_UCM_ECC_HDLR_TOTAL
}mmi_ucm_ecc_hdlr_enum;


typedef enum
{
    MMI_UCM_TTS_REPLAY_QUERY_YES,
    MMI_UCM_TTS_REPLAY_QUERY_NO,
    MMI_UCM_TTS_REPLAY_QUERY_TOTAL
}mmi_ucm_tts_replay_query_result_enum;


typedef struct
{
    srv_ucm_call_type_enum call_type_all;
    srv_ucm_call_type_enum call_type_voice;
    srv_ucm_call_type_enum call_type_video;
}mmi_ucm_call_type_single_sim_struct;


typedef struct
{
    srv_ucm_index_info_struct index_list[SRV_UCM_MAX_CALL]; /* Only used by ucm app */
    S32 hilite_group_index;
    S32 hilite_call_index;
#ifdef __DRM_SUPPORT__
    S32 drm_consume_id;
#endif /* __DRM_SUPPORT__ */
#ifdef __GENERAL_TTS__
    U8 *speechText;
#endif /* __GENERAL_TTS__ */
    MMI_BOOL no_counter;
#ifdef __MMI_DUAL_MIC_SUPPORT__
    MMI_BOOL is_noice_reduction;
#endif /* __MMI_DUAL_MIC_SUPPORT__ */
}mmi_core_ucm_call_misc_struct;


typedef struct
{
    U16 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1];
}mmi_ucm_num_info_struct;


typedef struct
{
    void *dial_user_data;
    mmi_proc_func act_req_callback;
}mmi_ucm_act_req_struct;


typedef mmi_ucm_tts_replay_query_result_enum (*mmi_ucm_core_tts_replay_query_callback) (void);


typedef struct
{
    mmi_ucm_core_tts_replay_query_callback query_callback;
}mmi_ucm_tts_replay_query_struct;


typedef struct
{
    MMI_BOOL is_voice_vt_switch_act;
    srv_ucm_call_type_enum switch_to_call_type;
}mmi_ucm_vt_switch_info_struct;


typedef struct
{
    mmi_core_ucm_call_misc_struct call_misc;
    mmi_ucm_num_info_struct num_info;
    mmi_ucm_act_req_struct act_request;
#ifdef __GENERAL_TTS__
    mmi_ucm_tts_replay_query_struct replay_query;
#endif /* __GENERAL_TTS__ */
#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_ucm_vt_switch_info_struct vt_switch;
#endif /* __MMI_VIDEO_TELEPHONY__ */
#ifdef  __MMI_FTE_SUPPORT__
    mmi_ucm_auto_lock_state_enum auto_lock_state;
#endif /* __MMI_FTE_SUPPORT__ */
} mmi_core_ucm_cntx_struct;

extern mmi_core_ucm_cntx_struct *mmi_core_ucm_p;


/***************************************************************************** 
 * Internal Function
 *****************************************************************************/

/* ==================================================================================== */
/* =============Kernel init related===================================================== */
/* ==================================================================================== */
extern void mmi_core_ucm_init_context(void);
extern void mmi_core_ucm_reset_index_list(void);

/* ==================================================================================== */
/* =============Kernel tone related==================================================== */
/* ==================================================================================== */
extern void mmi_ucm_play_inband_tone(void);
extern void mmi_ucm_stop_inband_tone(void);
extern void mmi_ucm_play_waitingtone(void);
extern void mmi_ucm_stop_waitingtone(void);
extern void mmi_ucm_call_time_reminder(void);
extern void mmi_ucm_call_time_reminder_hdlr(void);
#ifdef __MMI_CONNECT_NOTICE__
extern void mmi_ucm_play_connect_notice_with_vib(void);
extern void mmi_ucm_play_connect_notice(void);
extern void mmi_ucm_stop_connect_vibration(void);
#endif /* __MMI_CONNECT_NOTICE__ */
extern void mmi_ucm_play_tone_with_text(void);
#ifdef __GENERAL_TTS__
extern srv_prof_ret mmi_ucm_play_tone_with_text_callback(srv_prof_ret result);
extern void mmi_ucm_set_tts_replay_query_callback(mmi_ucm_core_tts_replay_query_callback func);
extern void mmi_ucm_free_speechText(void);
#endif /* __GENERAL_TTS__ */

/* ==================================================================================== */
/* =============Kernel Permit related================================================== */
/* ==================================================================================== */
extern MMI_BOOL mmi_ucm_pass_answer_permit(srv_ucm_single_call_act_req_struct *check_act_req, srv_ucm_act_opcode_enum *first_pass_act_op, srv_ucm_result_enum *first_result);
extern MMI_BOOL mmi_ucm_pass_dial_permit(srv_ucm_dial_act_req_struct *check_act_req, srv_ucm_act_opcode_enum *first_pass_act_op, srv_ucm_result_enum *first_result);
extern srv_ucm_result_enum mmi_ucm_query_sndrec_permit(void);

/* ==================================================================================== */
/* =============Kernel Option related================================================== */
/* ==================================================================================== */
extern void mmi_ucm_set_act_request_callback(mmi_proc_func func);
extern void mmi_ucm_set_act_request_dial_user_data(void *user_data);
extern void mmi_ucm_set_number_info(U16 *num_uri);

extern srv_ucm_result_enum mmi_ucm_dial_option(srv_ucm_dial_act_req_struct *check_act_req, mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_outgoing_dialer_option(void);
extern srv_ucm_result_enum mmi_ucm_answer_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_incoming_dialer_option(void);

extern srv_ucm_result_enum mmi_ucm_multiple_group_option(srv_ucm_act_opcode_enum opcode, mmi_ucm_check_type_enum exec_act_flag, MMI_BOOL *is_act_executed);
extern srv_ucm_result_enum mmi_ucm_single_group_option(srv_ucm_act_opcode_enum opcode, mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_single_call_option(srv_ucm_act_opcode_enum opcode, srv_ucm_call_state_enum call_state, mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_simple_option(srv_ucm_act_opcode_enum opcode, mmi_ucm_check_type_enum exec_act_flag);

extern srv_ucm_result_enum mmi_ucm_replace_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_end_conference_option(mmi_ucm_check_type_enum exec_act_flag);

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
extern srv_ucm_result_enum mmi_ucm_answer_by_voice_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
#ifdef __MMI_UCM_DEFLECT__
extern srv_ucm_result_enum mmi_ucm_deflect_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* __MMI_UCM_DEFLECT__ */
#ifdef __MMI_BG_SOUND_EFFECT__
extern srv_ucm_result_enum mmi_ucm_bk_sound_incoming_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* __MMI_BG_SOUND_EFFECT__ */
#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__   
extern srv_ucm_result_enum mmi_ucm_redial_from_other_sim_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */
#if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
extern srv_ucm_result_enum mmi_ucm_transfer_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */

extern srv_ucm_result_enum mmi_ucm_new_call_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_end_all_active_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_end_all_held_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_hold_single_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_hold_conference_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_retrieve_single_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_retrieve_conference_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_swap_option(mmi_ucm_check_type_enum exec_act_flag, MMI_BOOL *is_act_executed);
extern srv_ucm_result_enum mmi_ucm_conference_option(mmi_ucm_check_type_enum exec_act_flag, MMI_BOOL *is_act_executed);
extern srv_ucm_result_enum mmi_ucm_split_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_end_single_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_end_all_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_main_menu_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_phonebook_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_calllog_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_message_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_enter_general_app_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_browser_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_sound_recorder_option(mmi_ucm_check_type_enum exec_act_flag);
#ifdef __MMI_BG_SOUND_EFFECT__   
extern srv_ucm_result_enum mmi_ucm_bk_sound_in_call_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* __MMI_BG_SOUND_EFFECT__ */
extern srv_ucm_result_enum mmi_ucm_loud_option(srv_ucm_call_state_enum check_call_state);
extern srv_ucm_result_enum mmi_ucm_mute_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_dtmf_option(mmi_ucm_check_type_enum exec_act_flag);
#ifdef __MMI_BT_SUPPORT__
extern srv_ucm_result_enum mmi_ucm_swap_bt_audio_path_option(mmi_ucm_check_type_enum exec_act_flag, srv_ucm_call_state_enum check_call_state);
#endif /* __MMI_BT_SUPPORT__ */
#ifdef __CTM_SUPPORT__
extern srv_ucm_result_enum mmi_ucm_ctm_option(mmi_ucm_check_type_enum exec_act_flag);
extern srv_ucm_result_enum mmi_ucm_ctm_setting_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* __CTM_SUPPORT__ */
extern srv_ucm_result_enum mmi_ucm_switch_to_video_call_option(mmi_ucm_check_type_enum exec_act_flag);
#ifdef __MMI_UCM_REJECT_BY_SMS__
extern srv_ucm_result_enum mmi_ucm_rej_by_sms_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* __MMI_UCM_REJECT_BY_SMS__*/
#ifdef __MMI_DUAL_MIC_SUPPORT__
extern MMI_BOOL mmi_ucm_get_dual_mic_nr_status(void);
extern void mmi_ucm_set_dual_mic_nr_status(MMI_BOOL status);
extern srv_ucm_result_enum mmi_ucm_noice_reduction_option(mmi_ucm_check_type_enum exec_act_flag);
#endif /* __MMI_DUAL_MIC_SUPPORT__ */

/* ===================================================================================== */
/* =============Kernel Misc============================================================= */
/* ===================================================================================== */
extern void mmi_ucm_set_hilight_index(S32 hilite_group_index, S32 hilite_call_index);
extern void mmi_ucm_end_all_processing_action(void);
extern srv_ucm_call_type_enum mmi_ucm_convert_voice_to_video(srv_ucm_call_type_enum call_type_voice);
extern srv_ucm_call_type_enum mmi_ucm_convert_video_to_voice(srv_ucm_call_type_enum call_type_video);
extern srv_ucm_call_type_enum mmi_ucm_convert_to_valid_ecc_call_type(srv_ucm_call_type_enum call_type, U8 *call_number);
extern mmi_sim_enum mmi_ucm_convert_call_type_to_sim(srv_ucm_call_type_enum call_type);
extern srv_ucm_call_type_enum mmi_ucm_convert_index_to_voice_type(U8 index);
extern MMI_BOOL mmi_ucm_check_post_action_about_sim(srv_ucm_call_type_enum call_type, U8 *num_uri);

extern MMI_BOOL mmi_ucm_is_emergency_number(srv_ucm_call_type_enum call_type, U16 *ucs2_number);
extern mmi_ucm_ecc_hdlr_enum mmi_ucm_ecc_check_handler(srv_ucm_call_type_enum dial_type, srv_ucm_dial_act_req_struct *check_act_req, MMI_BOOL consider_temp_status);
extern MMI_BOOL mmi_ucm_is_ss_string(srv_ucm_call_type_enum call_type, U8 *num_uri);

extern S32 mmi_ucm_get_group_index_by_call_state(srv_ucm_call_state_enum call_state);
extern S32 mmi_ucm_get_group_index_by_call_state_and_type(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type);
extern MMI_BOOL mmi_ucm_get_call_id_by_call_state_and_type(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, srv_ucm_id_info_struct *call_uid);
extern MMI_BOOL mmi_ucm_get_incoming_call_info(srv_ucm_single_call_act_req_struct *check_act_req);
extern S32 mmi_ucm_get_call_index_list_by_group_index(S32 group_index, S32 *call_index_list);

extern void mmi_ucm_set_no_counter_status(MMI_BOOL no_counter);
extern MMI_BOOL mmi_ucm_get_no_counter_status(void);
extern MMI_BOOL mmi_ucm_is_file_valid(U16* file_path, U32 type);

#ifdef __DRM_SUPPORT__
extern void mmi_ucm_drm_stop_consume(void);
extern void mmi_ucm_drm_callback(S32 res, S32 id);
extern S32 mmi_ucm_drm_start_consume(U16* file_path, U32 type);
#endif /* __DRM_SUPPORT__ */

extern MMI_BOOL mmi_ucm_is_caller_video_sound(void);
extern MMI_BOOL mmi_ucm_decide_visual_type(srv_ucm_res_type_enum res_type, srv_ucm_res_type_enum* filtered_res_type);

#if defined(__MMI_FTE_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__) && !defined(__PXS_APP_ENABLE__)
extern mmi_ucm_auto_lock_state_enum mmi_ucm_get_auto_lock_state(void);
extern void mmi_ucm_auto_lock_fsm_hdlr(mmi_ucm_auto_lock_trigger_event_enum event);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__) && !defined(__PXS_APP_ENABLE__) */

#ifdef __PXS_APP_ENABLE__
extern MMI_BOOL mmi_ucm_pxs_need_to_process(void);
#endif /* __PXS_APP_ENABLE__ */

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
MMI_BOOL mmi_ucm_one_sim_behavior_is_needed(void);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

/* ==================================================================================== */
/* ============= Kernel VT related ==================================================== */
/* ==================================================================================== */
#ifdef __MMI_VIDEO_TELEPHONY__
extern void mmi_ucm_vt_set_is_switch_action(MMI_BOOL is_switch_action);
extern MMI_BOOL mmi_ucm_vt_get_is_switch_action(void);
extern void mmi_ucm_vt_set_switch_call_type(srv_ucm_call_type_enum call_type);
extern srv_ucm_call_type_enum mmi_ucm_vt_get_switch_call_type(void);
extern MMI_BOOL mmi_ucm_vt_check_protocol_usable(void);
extern MMI_BOOL mmi_ucm_vt_check_nw_usable(void);
extern srv_ucm_call_type_enum mmi_ucm_vt_get_valid_video_call_type(void);
#endif /* __MMI_VIDEO_TELEPHONY__ */


/* ==================================================================================== */
/* ============= Uha core related ===================================================== */
/* ==================================================================================== */
extern MMI_BOOL mmi_ucm_uha_check_gsm_dtmf(CHAR *strNumber);
extern srv_ucm_result_enum mmi_ucm_uha_send_dtmf_check_hdlr(U8* num, mmi_proc_func result_callback);
extern srv_ucm_result_enum mmi_ucm_uha_parse_uri(U8 *param, U8 **result_num);
extern void mmi_ucm_uha_stop_sending_dtmf(void);
extern void mmi_ucm_uha_to_lower_case(U8 *str);
extern S32 mmi_ucm_uha_convert_dtmf_ascii_to_keycode(U8 dtmf_ascii);
extern MMI_BOOL mmi_ucm_uha_remove_separator_in_phone_number(U8* output, U8* input_number, U32 output_len, U32 input_number_len);
extern srv_prof_tone_enum mmi_ucm_uha_get_warning_tone(void);


#endif /* UCM_CORE_PROT_H */
