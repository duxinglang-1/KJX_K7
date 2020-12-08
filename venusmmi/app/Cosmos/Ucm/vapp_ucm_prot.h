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
 *  vapp_ucm_prot.h
 *
 * Project:
 * -------- 
 *  COSMOS
 *
 * Description:
 * ------------
 *  UCM internal include header
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_UCM_PROT_H__
#define __VAPP_UCM_PROT_H__

extern mmi_id vapp_ucm_get_app_id();
extern void vapp_ucm_launch(void);
extern void vapp_ucm_terminate(void);
extern void vapp_ucm_refresh_screen(VappUcmCallCellRefreshTypeEnum refresh_type, void* data);
extern void vapp_ucm_mdi_callback(mdi_result result, void *user_data);
extern void vapp_ucm_accept_act_rsp(srv_ucm_act_rsp_struct *rsp, srv_ucm_act_type_enum act_type);
extern void vapp_ucm_incoming_call_sendkey(void);
extern void vapp_ucm_incoming_call_endkey(void);
extern void vapp_ucm_outgoing_call_endkey(void);
extern void vapp_ucm_in_call_endkey(void);
extern void vapp_ucm_endkey_hdlr(void);
extern void vapp_ucm_end_single_action(void);
extern void vapp_ucm_end_conference_action(void);
extern void vapp_ucm_end_all_action(void);
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
extern void vapp_ucm_end_all_held_action(void);
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__ */
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
extern void vapp_ucm_end_all_active_action(void);
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__ */
extern void vapp_ucm_hold_single_action(void);
extern void vapp_ucm_retrieve_single_action(void);
extern void vapp_ucm_split_action(void);
extern void vapp_ucm_retrieve_conference_action(void);
extern void vapp_ucm_hold_conf_action(void);
extern void vapp_ucm_swap_action(void);
extern void vapp_ucm_split_action(void);
extern void vapp_ucm_conference_action(void);
extern mmi_ret vapp_ucm_act_callback(mmi_event_struct *event);
extern void vapp_ucm_dtmf_key_down(VfxU8 keyCode);
extern void vapp_ucm_dtmf_key_up(VfxU8 keyCode);
extern void vapp_ucm_replace(void);
extern void vapp_ucm_deflect(void);
extern void vapp_ucm_transfer(void);
extern void vapp_ucm_auto_redial_abort(void);
extern void vapp_ucm_play_ringtone(void);
extern void vapp_ucm_stop_ringtone(void);
extern void vapp_ucm_play_tone_after_vibration(void);
#ifndef __MMI_UCM_SLIM__
extern void vapp_ucm_bt_notify(U32 event, U32 arg, void *userData);
extern void vapp_ucm_bt_init(void);
extern void vapp_ucm_bt_deinit(void);
extern void vapp_ucm_incall_bt_set_audio_path_action(void);
extern void vapp_ucm_incoming_bt_set_audio_path_action(void);
extern void vapp_ucm_bt_set_audio_path(void);
#endif // __MMI_UCM_SLIM__
extern void vapp_ucm_enter_confirm();
extern void vapp_ucm_cancel_confirm();
extern mmi_ret vapp_ucm_proc(mmi_event_struct *evt);
extern void vapp_ucmapp_set_active_call_info(srv_ucm_index_info_struct *index_info);
extern void vapp_ucm_check_redial_fail(void);
extern void vapp_ucm_set_preferred_sim(void);

extern void vapp_ucm_auto_answer_action(void);
extern void vapp_ucm_stop_incoming_tone(void);
extern void vapp_ucm_play_incoming_tone(void);
extern MMI_BOOL vapp_ucm_volume_control_callback(U8 volume, MMI_BOOL is_mute);
extern void vapp_ucm_display_popup(srv_ucm_result_enum result);
extern void vapp_ucm_display_info(WCHAR* string);
extern VfxS32 vapp_ucm_show_confirm(U16* str, mmi_bool_funcptr_type cb);
extern void vapp_ucm_close_confirm(VfxS32 id);
extern void vapp_ucm_show_info_ballon(VfxU16 *str);
extern void vapp_ucm_hdlr_make_call_cb(mmi_ucm_after_make_call_cb_struct* p);
extern void vapp_ucm_headset_key(void);

#endif /* __VAPP_UCM_PROT_H__ */

