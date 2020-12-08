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
 *  CallSetSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting service internal prototypes
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef SRV_CALLSET_PROT_H
#define SRV_CALLSET_PROT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "CallSetSrvGprot.h"
#include "UcmSrvGprot.h" /* SRV_UCM_MAX_NUM_URI_LEN */
#ifdef __MMI_VIDEO_TELEPHONY__
#include "FileMgrGProt.h" /* SRV_FMGR_PATH_MAX_LEN */
#endif /* __MMI_VIDEO_TELEPHONY__ */


#include "MMIDataType.h"
#include "MMI_features.h"
#include "kal_non_specific_general_types.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    SRV_CALLSET_OP_IDLE = 0,
    SRV_CALLSET_OP_CID,
    SRV_CALLSET_OP_LINE_SWITCH,
    SRV_CALLSET_OP_CUG_ACTIVATE,
    SRV_CALLSET_OP_CUG_DEACTIVATE,

    SRV_CALLSET_OP_TOTAL
} srv_callset_op_enum;


#ifdef __BUILD_DOM__
typedef enum
{
    EVT_ID_SRV_CALLSET_INT_ACT = EVT_ID_SRV_CALLSET_TOTAL + 1,
    EVT_ID_SRV_CALLSET_INT_TOTAL
} srv_callset_int_evt_enum;
#endif /* __BUILD_DOM__ */


typedef struct
{
    srv_callset_op_enum op;
    mmi_proc_func rsp_cb;
    void *rsp_user_data;
} srv_callset_act_info_struct;


#ifdef __MMI_CALLSET_CUG__
typedef struct
{
    WCHAR name[SRV_CALLSET_CUG_MAX_NAME_LENGTH + 1];
} srv_callset_cug_item_struct;
#endif /* __MMI_CALLSET_CUG__ */


typedef struct
{
    mmi_sim_enum sim;
#ifdef __MMI_CALLSET_CALLER_ID__
    MMI_BOOL caller_id_initiated;
    srv_callset_caller_id_mode_enum caller_id_tmp;
    srv_callset_caller_id_mode_enum caller_id;
#endif /* __MMI_CALLSET_CALLER_ID__ */
    srv_callset_line_id_enum line_id_tmp;
    srv_callset_line_id_enum line_id;
#ifdef __MMI_CALLSET_CUG__
    MMI_BOOL cug_initiated;
    U8 cug_temp_id;
    U8 cug_activated_id;
    srv_callset_cug_item_struct cug_list[SRV_CALLSET_CUG_MAX_GROUP_NUM];
#endif /* __MMI_CALLSET_CUG__ */
    srv_callset_cfu_status_enum cfu_status;
} srv_callset_sim_cntx_struct;


#ifdef __MMI_VIDEO_TELEPHONY__
typedef struct
{
    MMI_BOOL initiated;
    MMI_BOOL mic;
    MMI_BOOL speaker;
    MMI_BOOL night_mode_front;
    srv_callset_vt_ev_enum ev_front;
    U8 zoom_front;
    MMI_BOOL night_mode_back;
    srv_callset_vt_ev_enum ev_back;
    U8 zoom_back;
    srv_callset_vt_answer_mode_enum answer_mode;
    srv_callset_vt_dial_mode_enum dial_mode;
    srv_callset_vt_camera_mode_enum camera_mode;
    U16  incall_image_file_path[SRV_FMGR_PATH_MAX_LEN + 1]; /* UCS2 with NULL terminator */
} srv_callset_vt_setting_struct;
#endif /* __MMI_VIDEO_TELEPHONY__ */

typedef struct
{
    srv_callset_act_info_struct act_info;

    srv_callset_sim_cntx_struct sim_cntx[MMI_MAX_SIM_NUM];

    MMI_BOOL ctr_initiated;
    srv_callset_ctr_struct ctr;
    MMI_BOOL ctd_initiated;
    srv_callset_answer_mode_enum answer_mode;
    MMI_BOOL answer_mode_initiated;
    MMI_BOOL ctd_mode;
    MMI_BOOL redial_initiated;
    srv_callset_redial_mode_enum redial_mode;
#ifdef __MMI_UCM_REJECT_BY_SMS__
    MMI_BOOL rej_by_sms_initiated;
    MMI_BOOL rej_by_sms_mode;
    srv_callset_rej_by_sms_setting_enum rej_by_sms_setting;
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#ifdef __MMI_CONNECT_NOTICE__
    MMI_BOOL connect_notice_initiated;
    MMI_BOOL connect_notice_mode;
#endif /* __MMI_CONNECT_NOTICE__ */
#ifdef __IP_NUMBER__
    MMI_BOOL ip_initiated;
    U8 ip_setting[MMI_MAX_SIM_NUM];
    WCHAR ip_number[SRV_CALLSET_MAX_IP_NUMBER][SRV_CALLSET_MAX_IP_NUMBER_LEN + 1];
#endif /* __IP_NUMBER__ */
#ifdef __MMI_CM_BLACK_LIST__
    MMI_BOOL blacklist_initiated;
    srv_callset_blacklist_mode_enum blacklist_mode;
    WCHAR blacklist_num[SRV_CALLSET_BLACKLIST_MAX_ITEM][SRV_UCM_MAX_NUM_URI_LEN + 1];
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_mode_enum blacklist_mode_video; /* video call blacklist mode */
    WCHAR blacklist_num_video[SRV_CALLSET_BLACKLIST_MAX_ITEM][SRV_UCM_MAX_NUM_URI_LEN + 1]; /* video call blacklist mode */
#endif /* __MMI_CM_BLACK_LIST_EXT__ */
#endif /* __MMI_CM_BLACK_LIST__ */
#ifdef __MMI_CM_WHITE_LIST__
    MMI_BOOL whitelist_initiated;
    srv_callset_whitelist_mode_enum whitelist_mode;
    WCHAR whitelist_num[SRV_CALLSET_WHITELIST_MAX_ITEM][SRV_UCM_MAX_NUM_URI_LEN + 1];
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_whitelist_mode_enum whitelist_mode_video; /* video call whitelist mode */
    WCHAR whitelist_num_video[SRV_CALLSET_WHITELIST_MAX_ITEM][SRV_UCM_MAX_NUM_URI_LEN + 1]; /* video call whitelist mode */
#endif /* __MMI_CM_WHITE_LIST_EXT__ */
#endif /* __MMI_CM_WHITE_LIST__ */
#ifdef __MMI_CH_QUICK_END__
    MMI_BOOL quick_end_initiated;
    MMI_BOOL quick_end_mode;
    U16 quick_end_time;
#endif /* __MMI_CH_QUICK_END__ */
#ifdef __CTM_SUPPORT__
    MMI_BOOL ctm_mode;
    srv_callset_ctm_setting_enum ctm_setting;
#endif /* __CTM_SUPPORT__ */
#ifdef __MMI_VIDEO_TELEPHONY__
    srv_callset_vt_setting_struct vt_setting;
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __OP01_FWPBW__
    MMI_BOOL delay_dial_initiated;
    U8 delay_dial_time;
    MMI_BOOL fwp_initiated;
    U8 offhook_reminder_timeout;
    U8 offhook_reminder_duration;
#endif /* __OP01_FWPBW__ */

#ifdef MOTION_SENSOR_SUPPORT
MMI_BOOL flip_to_mute_call_initiated;
MMI_BOOL flip_to_mute_call_mode;

MMI_BOOL tap_tap_to_record_in_call_initiated;
MMI_BOOL tap_tap_to_record_in_call_mode;
#endif


} srv_callset_context_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_callset_op_enum op;
    void *info;
    mmi_proc_func rsp_cb;
    void *rsp_user_data;
} srv_callset_act_evt_struct;


extern srv_callset_context_struct *srv_callset_p;
extern srv_callset_sim_cntx_struct *srv_callset_sim_p;

/***************************************************************************** 
 * Internal Function
 *****************************************************************************/
/* CallSetSrvInterface.c */
extern void srv_callset_set_ps_event_handler(PsExtFuncPtr func, U16 event);
extern void srv_callset_reset_ps_event_handler(U16 event);
#ifdef __MMI_CALLSET_CALLER_ID__
extern void srv_callset_l4c_set_clir_flag_req(srv_callset_caller_id_mode_enum mode);
extern void srv_callset_phdlr_set_clir_flag_rsp(void *info, int mod_src);
#endif /* __MMI_CALLSET_CALLER_ID__ */
extern void srv_callset_l4c_update_als_req(srv_callset_line_id_enum line_id);
extern void srv_callset_phdlr_update_als_rsp(void *info, int mod_src);
extern void srv_callset_phdlr_display_als_ind(void *info, int mod_src);
extern void srv_callset_phdlr_display_cfu_ind(void *info, int mod_src);
#ifdef __MMI_CALLSET_CUG__
extern void srv_callset_l4c_set_cug_req(U8 cug_id, MMI_BOOL activate);
extern void srv_callset_phdlr_set_cug_rsp(void *info, int mod_src);
#endif /* __MMI_CALLSET_CUG__ */
#ifdef __CTM_SUPPORT__
extern void srv_callset_post_ctm_setting_changed_ind_evt(void);
#endif /* __CTM_SUPPORT__ */
extern mmi_sim_enum srv_callset_get_target_sim(int src_mod);
extern int srv_callset_get_l4c_mod(mmi_sim_enum sim);
extern void srv_callset_post_rsp_evt(srv_callset_op_enum op, void *info);
extern mmi_ret srv_callset_post_rsp_evt_cb(mmi_post_result_event_struct *result_evt);
extern void srv_callset_post_act_evt(srv_callset_op_enum op, void *info, mmi_proc_func rsp_cb, void *rsp_user_data);
extern mmi_ret srv_callset_post_act_evt_hdlr(mmi_event_struct* para);
extern void srv_callset_post_lsw_ind_evt(mmi_sim_enum sim, srv_callset_line_id_enum line_id);
extern void srv_callset_post_cfu_status_evt(mmi_sim_enum sim, srv_callset_cfu_status_enum status);

/* CallSetSrvStructMgmt.c */
extern void srv_callset_early_init(void);
extern void srv_callset_init(void);
extern void srv_callset_init_nvram(void);
extern MMI_BOOL srv_callset_is_busy(void);
extern void srv_callset_init_sim(mmi_sim_enum sim);
extern void srv_callset_init_ctr(void);
extern void srv_callset_init_answer_mode(void);
extern void srv_callset_init_ctd(void);
extern void srv_callset_init_redial(void);
#ifdef __MMI_CALLSET_CALLER_ID__
extern void srv_callset_init_caller_id(mmi_sim_enum sim);
#endif /* __MMI_CALLSET_CALLER_ID__ */
#ifdef __MMI_CALLSET_CUG__
extern void srv_callset_init_cug(mmi_sim_enum sim);
#endif /* __MMI_CALLSET_CUG__ */
#ifdef __MMI_UCM_REJECT_BY_SMS__
extern void srv_callset_init_rej_by_sms(void);
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#ifdef __MMI_CONNECT_NOTICE__
extern void srv_callset_init_connect_notice(void);
#endif /* __MMI_CONNECT_NOTICE__ */
#ifdef __IP_NUMBER__
extern void srv_callset_init_ip_number(void);
#endif /* __IP_NUMBER__ */
#ifdef __MMI_CM_BLACK_LIST__
extern void srv_callset_init_blacklist(void);
#endif /* __MMI_CM_BLACK_LIST__ */
#ifdef __MMI_CM_WHITE_LIST__
extern void srv_callset_init_whitelist(void);
#endif /* __MMI_CM_WHITE_LIST__ */
#ifdef __MMI_CH_QUICK_END__
extern void srv_callset_init_auto_quick_end(void);
#endif /* __MMI_CH_QUICK_END__ */
#ifdef __CTM_SUPPORT__
extern void srv_callset_init_ctm(void);
#endif /* __CTM_SUPPORT__ */
extern void srv_callset_sim_cntx_set_ptr(mmi_sim_enum sim);
extern void srv_callset_sim_cntx_reset_ptr(void);
extern MMI_BOOL srv_callset_sim_cntx_is_locked(void);








#endif /* SRV_CALLSET_PROT_H */
