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
 *   srv_ucm_interface.h
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
#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_ucm_interface_def.h"

#include "gs_srv_ucm_type.h"

/*****************************************************************************
 * IUcm methods
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  ITodolist_addRef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IUcm_addRef(IUcm *obj)
{
    return obj->vt->addRef(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IUcm_release(IUcm *obj)
{
    return obj->vt->release(obj);
}

/*****************************************************************************
 * FUNCTION
 *  ITodolist_queryInterface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  iid : [IN]        
 *  pptr : [IN]        
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IUcm_queryInterface(IUcm *obj, S32 iid, IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_act_request
 * DESCRIPTION
 *  The function to perform actions in gs_srv_ucm_act_opcode_enum
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  act_op:          [IN]        Action op-code
 *  act_data:        [IN]        Action data
 *  user_data:       [IN]        User data
 *  result_callback: [IN]        Result callback function
 * RETURNS
 *  void
 *****************************************************************************/ 
void __inline IUcm_act_request(IUcm *obj, gs_srv_ucm_act_opcode_enum act_op, void * act_data, void * user_data, gs_srv_callback_func result_callback)
{
    obj->vt->act_request(obj, act_op, act_data,user_data,result_callback);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_act_permit
 * DESCRIPTION
 *  The function to query if the action is permitted
 *  For GS_SRV_UCM_DIAL_ACT, GS_SRV_UCM_DEFLECT_ACT and GS_SRV_UCM_TRANSFER_ACT,
 *  number won't be considered because number is dynamically input by user
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  act_op:          [IN]        Action op-code
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  srv_ucm_result_enum
 *****************************************************************************/
gs_srv_ucm_result_enum __inline IUcm_query_act_permit(IUcm *obj, gs_srv_ucm_act_opcode_enum act_op, void * ptr)
{
    return obj->vt->query_act_permit(obj, act_op, ptr);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_call_count
 * DESCRIPTION
 *  The function to query call information, you can specify call state, call type,
 *  and get call count and index list as return
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  indexs_list:     [OUT]       Index list, array size is SRV_UCM_MAX_CALL, include group index and call index
 * RETURNS
 *  Call count
 *****************************************************************************/
S32 __inline IUcm_query_call_count(IUcm *obj, gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type, gs_srv_ucm_index_info_struct* index_list)
{
    return obj->vt->query_call_count(obj, call_state, call_type, index_list);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_disconnecting_call_count
 * DESCRIPTION
 *  The function to query disconnecting call information, you can specify call state, call type,
 *  and get call count and index list as return
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  indexs_list:     [OUT]       Index list, array size is SRV_UCM_MAX_CALL, include group index and call index
 * RETURNS
 *  Call count
 *****************************************************************************/
S32 __inline IUcm_query_disconnecting_call_count(IUcm *obj, gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type,gs_srv_ucm_index_info_struct * index_list)        
{
    return obj->vt->query_disconnecting_call_count(obj, call_state, call_type, index_list);
}        

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_call_data
 * DESCRIPTION
 *  From IUcm_query_group_count, you have group index and call index,
 *  this function is for you to get more detail information
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  index:           [IN]        Call index and group index
 *  call_info:       [OUT]       Detail information for the specified call 
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_call_data(IUcm *obj, gs_srv_ucm_index_info_struct index, gs_srv_ucm_call_info_struct * call_info)
{
    return obj->vt->query_call_data(obj, index, call_info);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_group_count
 * DESCRIPTION
 *  The function to query group information, you can specify call state, call type,
 *  and get group count and group index list as return
 *  Group index will be initialized as -1 which means invalid index
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  single_only:     [IN]        Only care the groups with single call in it
 *  index_list:      [OUT]       Group index list, array size is SRV_UCM_MAX_GROUP
 * RETURNS
 *  Group count
 *****************************************************************************/
S32 __inline IUcm_query_group_count(IUcm *obj, gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type, MMI_BOOL single_only, S32 * index_list)        
{
    return obj->vt->query_group_count(obj, call_state, call_type, single_only,index_list);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_group_data
 * DESCRIPTION
 *  From IUcm_query_group_count, you have group index,
 *  this function is for you to get more detail information
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  group_index:     [IN]        Group index
 *  group_info:      [OUT]       Group information
 * RETURNS
 *  Call count in the group
 *****************************************************************************/
S32 __inline IUcm_query_group_data(IUcm *obj, S32 group_index, gs_srv_ucm_group_info_struct * group_info)
{
    return obj->vt->query_group_data(obj, group_index, group_info);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_call_exist
 * DESCRIPTION
 *  Query if the call exists
 * PARAMETERS 
 *  obj :   [IN] Pointer to object.
 *  uid_info:        [IN]        UID
 *  call_state:      [IN]        call state, can be bitwise
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_call_exist(IUcm *obj, gs_srv_ucm_id_info_struct* uid_info, gs_srv_ucm_call_state_enum call_state)
{
    return obj->vt->query_call_exist(obj, uid_info, call_state);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_group_exist
 * DESCRIPTION
 *  Query if the group exists
 * PARAMETERS 
 *  obj :   [IN] Pointer to object.
 *  group_id:        [IN]        group id
 *  call_type:       [IN]        call type
 *  call_state:      [IN]        call state, can be bitwise
 * RETURNS
 *  MMI_TRUE means the group is found. Otherwise return MMI_FALSE.
 *****************************************************************************/        
MMI_BOOL __inline IUcm_query_group_exist(IUcm *obj, S32 group_id, gs_srv_ucm_call_type_enum call_type, gs_srv_ucm_call_state_enum call_state)        
{
    return obj->vt->query_group_exist(obj, group_id, call_type, call_state); 
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_index_by_id
 * DESCRIPTION
 *  Get group index and call index from uid
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS 
 *  obj :   [IN] Pointer to object.
 *  uid_info         [IN]        UID
 *  index:           [OUT]       Index contains group index and call index
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_index_by_id(IUcm *obj, gs_srv_ucm_id_info_struct* uid_info, gs_srv_ucm_index_info_struct* index)
{
    return obj->vt->query_index_by_id(obj, uid_info, index);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_group_index_by_group_id
 * DESCRIPTION
 *  Get group index from group id
 *  Group index will be initialized as -1, which means invalid index
 * PARAMETERS 
 *  obj :   [IN] Pointer to object.
 *  group_id         [IN]        group id
 *  call_type        [IN]        call type, can't be bitwise, should be unique
 *  group_index:     [OUT]       group index
 * RETURNS
 *  MMI_TRUE means the group is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_group_index_by_group_id(IUcm *obj, S16 group_id, gs_srv_ucm_call_type_enum call_type, S32* group_index)
{
    return obj->vt->query_group_index_by_group_id(obj, group_id, call_type, group_index);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_curr_action
 * DESCRIPTION
 *  Query current ongoing action
 * PARAMETERS 
 *  obj :   [IN] Pointer to object.
 * 
 * RETURNS
 *  gs_srv_ucm_act_opcode_enum: current action
 *****************************************************************************/
gs_srv_ucm_act_opcode_enum __inline IUcm_query_curr_action(IUcm *obj)
{
    return obj->vt->query_curr_action(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_reject_by_sms_permit
 * DESCRIPTION
 *  The function to query if reject by SMS is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  mt_call_uid:     [IN]        MT call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_reject_by_sms_permit(IUcm *obj, gs_srv_ucm_single_call_act_req_struct mt_call_uid)
{
    return obj->vt->query_reject_by_sms_permit(obj,mt_call_uid);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_reject_by_sms
 * DESCRIPTION
 *  The function to reject the MT call and send SMS
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  mt_call_uid:     [IN]        MT call id
 *  ucs2_content:    [IN]        SMS content
 *  sim_id:          [IN]        Send by which SIM
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/       
MMI_BOOL __inline IUcm_reject_by_sms(IUcm *obj, gs_srv_ucm_single_call_act_req_struct mt_call_uid, S8* ucs2_content, gs_srv_ucm_sim_enum sim_id)
{
    return obj->vt->reject_by_sms(obj,mt_call_uid,ucs2_content,sim_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_intercept
 * DESCRIPTION
 *  The function to intercept the outgoing call
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_type:          [IN]        Call type, can be bitwise
 *  number:          [IN]        Number, SRV_UCM_MAX_NUM_URI_LEN
 *  module_id:        [IN]        Module id, who initiates the outoging call
 * RETURNS
 *  MMI_TRUE means the outgoing call is intercepted, MMI_FALSE means not
 *****************************************************************************/
MMI_BOOL __inline IUcm_intercept(IUcm *obj, gs_srv_ucm_call_type_enum call_type, U16 * number, gs_srv_ucm_module_origin_enum module_id)
{
    return obj->vt->intercept(obj,call_type,number,module_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_incoming_call
 * DESCRIPTION
 *  check if there is incoming call
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  void
 * RETURNS
 *  MMI_TRUE means there is incoming call.
 *  MMI_FALSE means there is no incoming call.
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_incoming_call(IUcm *obj)        
{
    return obj->vt->is_incoming_call(obj);
}       

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_outgoing_call
 * DESCRIPTION
 *  check if there is outgoing call
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  void
 * RETURNS
 *  MMI_TRUE means there is outgoing call.
 *  MMI_FALSE means there is no outgoing call.
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_outgoing_call(IUcm *obj)        
{
    return obj->vt->is_outgoing_call(obj);
} 

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_any_call
 * DESCRIPTION
 *  check if there is any call
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  void
 * RETURNS
 *  MMI_TRUE means there is any call.
 *  MMI_FALSE means there is no call.
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_any_call(IUcm *obj)        
{
    return obj->vt->is_any_call(obj);
}       

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_emergency_call
 * DESCRIPTION
 *  check if there is emergency call exists
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  void
 * RETURNS
 *  MMI_TRUE means there is emergency call.
 *  MMI_FALSE means there is no emergency call.
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_emergency_call(IUcm *obj)        
{
    return obj->vt->is_emergency_call(obj);
} 

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_call_srv_available
 * DESCRIPTION
 *  The function to query if the call type service is available now
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_type:       [IN]        Call type
 * RETURNS
 *  MMI_TRUE means any of input cal types is available
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_call_srv_available(IUcm *obj, gs_srv_ucm_call_type_enum call_type)
{
    return obj->vt->is_call_srv_available(obj, call_type);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_call_srv_tmp_unavailable
 * DESCRIPTION
 *  The function to query if the call type service is temporarily unavailable now
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_type:       [IN]        Call type
 * RETURNS
 *  MMI_TRUE means any of input cal types is temporarily unavailable now
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_call_srv_tmp_unavailable(IUcm *obj, gs_srv_ucm_call_type_enum call_type)    
{
    return obj->vt->is_call_srv_tmp_unavailable(obj, call_type);
}       

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_pending_action
 * DESCRIPTION
 *  The function to query if there is any pending action
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  void
 * RETURNS
 *  MMI_TRUE means there is pending action; MMI_FALSE means there is not.
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_pending_action(IUcm *obj)        
{
    return obj->vt->is_pending_action(obj);
} 

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_busy
 * DESCRIPTION
 *  The function to query if UCM service is busy
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  void
 * RETURNS
 *  MMI_TRUE means UCM service is busy; MMI_FALSE means UCM service is not busy.
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_busy(IUcm *obj)        
{
    return obj->vt->is_busy(obj);
}         

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_valid_number
 * DESCRIPTION
 *  The function to check if the number is valid or not
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_type:      [IN]        Call type, can use bitwise value to query multiple call types
 *  number:         [IN]        Number, ascii
 * RETURNS
 *  MMI_TRUE means it is valid number for any of input cal types
 *  MMI_FALSE means it is not valid number for any of input cal types
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_valid_number(IUcm *obj, gs_srv_ucm_call_type_enum call_type, U8 * number)
{
    return obj->vt->is_valid_number(obj, call_type, number);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_emergency_number
 * DESCRIPTION
 *  The function to check if the number is emergency number or not
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_type:      [IN]        Call type, can use bitwise value to query multiple call types 
 *  number:         [IN]        Number, ascii
 * RETURNS
 *  MMI_TRUE means it is emergency number for any of input cal types
 *  MMI_FALSE means it is not emergency number for any of input cal types
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_emergency_number(IUcm *obj, gs_srv_ucm_call_type_enum call_type, U8 * number)
{
    return obj->vt->is_emergency_number(obj, call_type, number);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_valid_dtmf_digit
 * DESCRIPTION
 *  The function to check if the digit is valid DTMF digit or not
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_type:       [IN]        Call type, can use bitwise value to query multiple call types 
 *  digit:           [IN]        Digit
 * RETURNS
 *  MMI_TRUE means it is valid DTMF digit for any of input cal types
 *  MMI_FALSE means it is not valid DTMF digit for any of input cal types
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_valid_dtmf_digit(IUcm *obj, gs_srv_ucm_call_type_enum call_type, U16 digit)
{
    return obj->vt->is_valid_dtmf_digit(obj, call_type, digit);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_get_caller_res_info
 * DESCRIPTION
 *  get caller resource information
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:         [IN]         call id
 *  res_info:        [OUT]        resource information
 * RETURNS
 *  MMI_TRUE means res_info is valid
 *  MMI_FALSE means res_info is invalid (get caller res info fails)
 *****************************************************************************/
MMI_BOOL __inline IUcm_get_caller_res_info(IUcm *obj, gs_srv_ucm_id_info_struct call_id, gs_srv_ucm_caller_res_struct * res_info)
{
    return obj->vt->get_caller_res_info(obj, call_id, res_info);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_error_message
 * DESCRIPTION
 *  Default error message for srv_ucm_result_enum
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  error_cause:     [IN]        Error cause
 * RETURNS
 *  String ID for error message
 *****************************************************************************/
U16 __inline IUcm_query_error_message(IUcm *obj, gs_srv_ucm_result_enum error_cause)
{
    return obj->vt->query_error_message(obj, error_cause);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_mute_permit
 * DESCRIPTION
 *  The function to query if Mute function is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_mute_permit(IUcm *obj, gs_srv_ucm_id_info_struct call_id)
{
    return obj->vt->query_mute_permit(obj, call_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_loudspeaker_permit
 * DESCRIPTION
 *  The function to query if Loud Speaker is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_loudspeaker_permit(IUcm *obj, gs_srv_ucm_id_info_struct call_id)
{
    return obj->vt->query_loudspeaker_permit(obj, call_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_sndrec_permit
 * DESCRIPTION
 *  The function to query if Sound Recorder is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_sndrec_permit(IUcm *obj, gs_srv_ucm_id_info_struct call_id)
{
    return obj->vt->query_sndrec_permit(obj, call_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_bgs_in_call_permit
 * DESCRIPTION
 *  The function to query if Background Sound during in call is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_TRUE means user is permitted to choose Background Sound during active/held call
 *  MMI_FALSE means user is not permitted to choose Background Sound during active/held call
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_bgs_in_call_permit(IUcm *obj, gs_srv_ucm_id_info_struct call_id)
{
    return obj->vt->query_bgs_in_call_permit(obj, call_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_bgs_incoming_call_permit
 * DESCRIPTION
 *  The function to query if Background Sound during incoming call is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_TRUE means user is permitted to choose Background Sound during incoming call
 *  MMI_FALSE means user is not permitted to choose Background Sound during incoming call
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_bgs_incoming_call_permit(IUcm *obj, gs_srv_ucm_id_info_struct call_id)
{
    return obj->vt->query_bgs_incoming_call_permit(obj, call_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_bgs_outgoing_call_permit
 * DESCRIPTION
 *  The function to query if Background Sound before outgoing call is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_type:       [IN]        Outgoing call type
 * RETURNS
 *  MMI_TRUE means user is permitted to choose Background Sound before making outgoing call
 *  MMI_FALSE means user is not permitted to choose Background Sound before making outgoing call
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_bgs_outgoing_call_permit(IUcm *obj, gs_srv_ucm_call_type_enum call_type)
{
    return obj->vt->query_bgs_outgoing_call_permit(obj, call_type);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_switch_bt_audio_path_permit
 * DESCRIPTION
 *  The function to query if BT audio path switch function is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_switch_bt_audio_path_permit(IUcm *obj, gs_srv_ucm_id_info_struct call_id)
{
    return obj->vt->query_switch_bt_audio_path_permit(obj, call_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_connect_last_bt_device_permit
 * DESCRIPTION
 *  The function to query if Connect Last BT Device is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_connect_last_bt_device_permit(IUcm *obj, gs_srv_ucm_id_info_struct call_id)
{
    return obj->vt->query_connect_last_bt_device_permit(obj, call_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_connect_ctm_permit
 * DESCRIPTION
 *  The function to query if Connect CTM is permitted
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_connect_ctm_permit(IUcm *obj, gs_srv_ucm_id_info_struct call_id)
{
    return obj->vt->query_connect_ctm_permit(obj, call_id);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_query_app_exit
 * DESCRIPTION
 *  Query function for if there is any app who doesn't want to exit,
 *  when the background outgoing call is connected
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  void
 * RETURNS
 *  MMI_TRUE means all apps can exit
 *  MMI_FALSE means any of apps can't exit
 *****************************************************************************/
MMI_BOOL __inline IUcm_query_app_exit(IUcm *obj)
{
    return obj->vt->query_app_exit(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IUcm_is_background_call
 * DESCRIPTION
 *  Function to query if it is in background call
 * PARAMETERS
 *  obj :   [IN] Pointer to object.
 *  void
 * RETURNS
 *  MMI_TRUE means there is background call. The background call may be outgoing, incoming, active, and held calls.
 *  MMI_FALSE means there is no call, there is foreground call, or there is CSD call.
 *****************************************************************************/
MMI_BOOL __inline IUcm_is_background_call(IUcm *obj)
{
    return obj->vt->is_background_call(obj);
}


