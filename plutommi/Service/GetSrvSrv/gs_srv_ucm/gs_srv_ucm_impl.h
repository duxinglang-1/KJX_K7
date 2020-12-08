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
 *   gs_srv_ucm_impl.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Class header file
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
#ifndef _TODOLIST_INTERFACE_
#define _TODOLIST_INTERFACE_

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_ucm_interface_def.h"


class UcmService : public GS_CBase, public IUcm
{

public:
    UcmService(U32 handle):GS_CBase(handle){}

    /* Common API */
    virtual S32 CALLCC addRef()
    {
        return GS_CBase::addRef();
    }
    virtual S32 CALLCC release()
    {
        return GS_CBase::release();
    }
    virtual S32 CALLCC queryInterface(S32 iid, GS_IBase **pptr);

    /* Functional API */
//    virtual void CALLCC init();
    virtual void CALLCC act_request(gs_srv_ucm_act_opcode_enum act_op, void *act_data, void *user_data, gs_srv_callback_func result_callback);
    virtual gs_srv_ucm_result_enum CALLCC query_act_permit(gs_srv_ucm_act_opcode_enum act_op, void *ptr);
    virtual S32 CALLCC query_call_count(gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type, 
                                                        gs_srv_ucm_index_info_struct *index_list);
    virtual S32 CALLCC query_disconnecting_call_count(gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type, 
                                                                gs_srv_ucm_index_info_struct *index_list);
    virtual MMI_BOOL CALLCC query_call_data(gs_srv_ucm_index_info_struct index, gs_srv_ucm_call_info_struct *call_info);
    virtual S32 CALLCC query_group_count(gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type, MMI_BOOL single_only,
                                                    S32 *index_list);
    virtual S32 CALLCC query_group_data(S32 group_index, gs_srv_ucm_group_info_struct *group_info);
    virtual MMI_BOOL CALLCC query_call_exist(gs_srv_ucm_id_info_struct* uid_info, gs_srv_ucm_call_state_enum call_state);
    virtual MMI_BOOL CALLCC query_group_exist(S32 group_id, gs_srv_ucm_call_type_enum call_type, gs_srv_ucm_call_state_enum call_state);
    virtual MMI_BOOL CALLCC query_index_by_id(gs_srv_ucm_id_info_struct* uid_info, gs_srv_ucm_index_info_struct* index);
    virtual MMI_BOOL CALLCC query_group_index_by_group_id(S16 group_id, gs_srv_ucm_call_type_enum call_type, S32* group_index);
    virtual gs_srv_ucm_act_opcode_enum CALLCC query_curr_action(void);
    virtual MMI_BOOL CALLCC query_reject_by_sms_permit(gs_srv_ucm_single_call_act_req_struct mt_call_uid);
    virtual MMI_BOOL CALLCC reject_by_sms(gs_srv_ucm_single_call_act_req_struct mt_call_uid, S8* ucs2_content, gs_srv_ucm_sim_enum sim_id);
    virtual MMI_BOOL CALLCC intercept(gs_srv_ucm_call_type_enum call_type, U16 *number, gs_srv_ucm_module_origin_enum module_id);
    virtual MMI_BOOL CALLCC is_incoming_call(void);
    virtual MMI_BOOL CALLCC is_outgoing_call(void);
    virtual MMI_BOOL CALLCC is_any_call(void);
    virtual MMI_BOOL CALLCC is_emergency_call(void);
    virtual MMI_BOOL CALLCC is_call_srv_available(gs_srv_ucm_call_type_enum call_type);
    virtual MMI_BOOL CALLCC is_call_srv_tmp_unavailable(gs_srv_ucm_call_type_enum call_type);
    virtual MMI_BOOL CALLCC is_pending_action(void);
    virtual MMI_BOOL CALLCC is_busy(void);
    virtual MMI_BOOL CALLCC is_valid_number(gs_srv_ucm_call_type_enum call_type, U8 *number);
    virtual MMI_BOOL CALLCC is_emergency_number(gs_srv_ucm_call_type_enum call_type, U8 *number);
    virtual MMI_BOOL CALLCC is_valid_dtmf_digit(gs_srv_ucm_call_type_enum call_type, U16 digit);
    virtual MMI_BOOL CALLCC get_caller_res_info(gs_srv_ucm_id_info_struct call_id, gs_srv_ucm_caller_res_struct *res_info);
    virtual U16 CALLCC query_error_message(gs_srv_ucm_result_enum error_cause);
    virtual MMI_BOOL CALLCC query_mute_permit(gs_srv_ucm_id_info_struct call_id);
    virtual MMI_BOOL CALLCC query_loudspeaker_permit(gs_srv_ucm_id_info_struct call_id);
    virtual MMI_BOOL CALLCC query_sndrec_permit(gs_srv_ucm_id_info_struct call_id);
    virtual MMI_BOOL CALLCC query_bgs_in_call_permit(gs_srv_ucm_id_info_struct call_id);
    virtual MMI_BOOL CALLCC query_bgs_incoming_call_permit(gs_srv_ucm_id_info_struct call_id);
    virtual MMI_BOOL CALLCC query_bgs_outgoing_call_permit(gs_srv_ucm_call_type_enum call_type);
    virtual MMI_BOOL CALLCC query_switch_bt_audio_path_permit(gs_srv_ucm_id_info_struct call_id);
    virtual MMI_BOOL CALLCC query_connect_last_bt_device_permit(gs_srv_ucm_id_info_struct call_id);
    virtual MMI_BOOL CALLCC query_connect_ctm_permit(gs_srv_ucm_id_info_struct call_id);
    virtual MMI_BOOL CALLCC query_app_exit(void);
    virtual MMI_BOOL CALLCC is_background_call(void);
private:
    static S32 callback(mmi_event_struct *param);
};


#endif /* _TODOLIST_INTERFACE_ */ 

