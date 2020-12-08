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
 *   gs_srv_ucm_interface_def.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IUcm interface
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
#include "gs_idef.h"
#include "gs_memory.h"

#include "gs_srv_ucm_type.h"

/***************************************************************************** 
* IUcm
*****************************************************************************/
    
    
DEF_INTERFACE(IUcm, GS_IBase)
    DEF_METHODS_GS_IBase(IUcm)
    DEF_METHOD4(IUcm, void, act_request, gs_srv_ucm_act_opcode_enum, act_op, void *, act_data, void *, user_data, gs_srv_callback_func, result_callback)
    DEF_METHOD2(IUcm, gs_srv_ucm_result_enum, query_act_permit, gs_srv_ucm_act_opcode_enum, act_op, void *, ptr)
    DEF_METHOD3(IUcm, S32,query_call_count, gs_srv_ucm_call_state_enum, call_state, gs_srv_ucm_call_type_enum, call_type, gs_srv_ucm_index_info_struct*, index_list)
    DEF_METHOD3(IUcm, S32,query_disconnecting_call_count, gs_srv_ucm_call_state_enum,call_state, gs_srv_ucm_call_type_enum, call_type,gs_srv_ucm_index_info_struct *, index_list)
    DEF_METHOD2(IUcm, MMI_BOOL, query_call_data, gs_srv_ucm_index_info_struct, index, gs_srv_ucm_call_info_struct *, call_info)
    DEF_METHOD4(IUcm, S32, query_group_count, gs_srv_ucm_call_state_enum, call_state, gs_srv_ucm_call_type_enum, call_type, MMI_BOOL, single_only, S32 *, index_list)
    DEF_METHOD2(IUcm, S32, query_group_data, S32, group_index, gs_srv_ucm_group_info_struct *, group_info)
    DEF_METHOD2(IUcm, MMI_BOOL, query_call_exist, gs_srv_ucm_id_info_struct*, uid_info, gs_srv_ucm_call_state_enum, call_state)
    DEF_METHOD3(IUcm, MMI_BOOL, query_group_exist, S32, group_id, gs_srv_ucm_call_type_enum, call_type, gs_srv_ucm_call_state_enum, call_state)
    DEF_METHOD2(IUcm, MMI_BOOL, query_index_by_id, gs_srv_ucm_id_info_struct*, uid_info, gs_srv_ucm_index_info_struct*,index)
    DEF_METHOD3(IUcm, MMI_BOOL, query_group_index_by_group_id, S16, group_id, gs_srv_ucm_call_type_enum, call_type, S32*, group_index)
    DEF_METHOD0(IUcm, gs_srv_ucm_act_opcode_enum, query_curr_action)
    DEF_METHOD1(IUcm, MMI_BOOL, query_reject_by_sms_permit, gs_srv_ucm_single_call_act_req_struct, mt_call_uid)
    DEF_METHOD3(IUcm, MMI_BOOL, reject_by_sms, gs_srv_ucm_single_call_act_req_struct, mt_call_uid, S8*, ucs2_content, gs_srv_ucm_sim_enum, sim_id)
    DEF_METHOD3(IUcm, MMI_BOOL, intercept, gs_srv_ucm_call_type_enum, call_type, U16 *, number, gs_srv_ucm_module_origin_enum, module_id)
    DEF_METHOD0(IUcm, MMI_BOOL, is_incoming_call)
    DEF_METHOD0(IUcm, MMI_BOOL, is_outgoing_call)
    DEF_METHOD0(IUcm, MMI_BOOL, is_any_call)
    DEF_METHOD0(IUcm, MMI_BOOL, is_emergency_call)
    DEF_METHOD1(IUcm, MMI_BOOL, is_call_srv_available, gs_srv_ucm_call_type_enum, call_type)
    DEF_METHOD1(IUcm, MMI_BOOL, is_call_srv_tmp_unavailable, gs_srv_ucm_call_type_enum, call_type)
    DEF_METHOD0(IUcm, MMI_BOOL, is_pending_action)
    DEF_METHOD0(IUcm, MMI_BOOL, is_busy)
    DEF_METHOD2(IUcm, MMI_BOOL, is_valid_number, gs_srv_ucm_call_type_enum, call_type, U8 *, number)
    DEF_METHOD2(IUcm, MMI_BOOL, is_emergency_number, gs_srv_ucm_call_type_enum, call_type, U8 *, number)
    DEF_METHOD2(IUcm, MMI_BOOL, is_valid_dtmf_digit, gs_srv_ucm_call_type_enum, call_type, U16, digit)
    DEF_METHOD2(IUcm, MMI_BOOL, get_caller_res_info, gs_srv_ucm_id_info_struct, call_id, gs_srv_ucm_caller_res_struct *, res_info)
    DEF_METHOD1(IUcm, U16, query_error_message, gs_srv_ucm_result_enum, error_cause)
    DEF_METHOD1(IUcm, MMI_BOOL, query_mute_permit, gs_srv_ucm_id_info_struct, call_id)
    DEF_METHOD1(IUcm, MMI_BOOL, query_loudspeaker_permit, gs_srv_ucm_id_info_struct, call_id)
    DEF_METHOD1(IUcm, MMI_BOOL, query_sndrec_permit, gs_srv_ucm_id_info_struct, call_id)
    DEF_METHOD1(IUcm, MMI_BOOL, query_bgs_in_call_permit, gs_srv_ucm_id_info_struct, call_id)
    DEF_METHOD1(IUcm, MMI_BOOL, query_bgs_incoming_call_permit, gs_srv_ucm_id_info_struct, call_id)
    DEF_METHOD1(IUcm, MMI_BOOL, query_bgs_outgoing_call_permit, gs_srv_ucm_call_type_enum, call_type)
    DEF_METHOD1(IUcm, MMI_BOOL, query_switch_bt_audio_path_permit, gs_srv_ucm_id_info_struct, call_id)
    DEF_METHOD1(IUcm, MMI_BOOL, query_connect_last_bt_device_permit, gs_srv_ucm_id_info_struct, call_id)
    DEF_METHOD1(IUcm, MMI_BOOL, query_connect_ctm_permit, gs_srv_ucm_id_info_struct, call_id)
    DEF_METHOD0(IUcm, MMI_BOOL, query_app_exit)
    DEF_METHOD0(IUcm, MMI_BOOL, is_background_call)
DEF_INTERFACE_END(IUcm)


