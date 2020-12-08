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
 *   gs_srv_ucm.cpp
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IUcm implement file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
#include "custom_mmi_default_value.h"
#include "UcmSrvGprot.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_ucm_impl.h"
#include "vmpromng.h"
/*
typedef struct
{
    void*           user_data;
    VM_P_HANDLE     phandle;
    mmi_proc_func   call_back;
}gs_srv_ucm_cb_param;

mmi_ret ucmservice_callback (mmi_event_struct *param)
{
    gs_srv_ucm_cb_param* pdata = param->user_data;
    
}
*/

typedef struct
{
    VM_P_HANDLE p_handle;
    void*       callback;
    void*       user_data;
}callback_data;


GS_IBase *CreateUcmService(U32 hd)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::CreateUcmService");

    UcmService* service = NULL;
    GS_NEW_EX(service, UcmService,(hd));
    return (GS_IBase*)(GS_CBase*)service;
}


S32 CALLCC UcmService::queryInterface(S32 iid, GS_IBase **pptr)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::queryInterface");

    /* Please notes: pptr may be a proxy, your call should not use it directly. */
    if (pptr == NULL)
        return 0;
    if (iid == IID_IUCM)
    {
        addRef();
        *pptr = BIND_PROXY(IUcm, this);
        return 1;
    }
    return GS_CBase::queryInterface(iid, pptr);
}



S32 UcmService::callback(mmi_event_struct *param)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::callback");
    
    callback_data* pdata = (callback_data*)param->user_data;
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(pdata->p_handle))
    {
        (*(gs_srv_callback_func)pdata->callback)((gs_srv_event_struct*)pdata->user_data);
        vm_free(pdata);
        vm_pmng_reset_ctx();
    }      
    return 0;
}


void CALLCC UcmService::act_request(gs_srv_ucm_act_opcode_enum act_op, void *act_data, void *user_data, gs_srv_callback_func result_callback)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::act_request");

    addRef();
    release();
    if (gs_is_MRE_free() && result_callback)
    {
        callback_data* pCbData = (callback_data*)vm_malloc(sizeof(callback_data));
        pCbData->p_handle = vm_pmng_get_current_handle();
        pCbData->callback = (void*)result_callback;
        pCbData->user_data = user_data;
        srv_ucm_act_request((srv_ucm_act_opcode_enum)act_op,act_data,pCbData,(mmi_proc_func)&UcmService::callback);
    }   
    srv_ucm_act_request((srv_ucm_act_opcode_enum)act_op,act_data,user_data,(mmi_proc_func)result_callback);
}

gs_srv_ucm_result_enum CALLCC UcmService::query_act_permit(gs_srv_ucm_act_opcode_enum act_op, void *ptr)
{    
    U32 ret = (U32)srv_ucm_query_act_permit((srv_ucm_act_opcode_enum)act_op,ptr);
    
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_act_permit ret = %d",ret);
    
    return (gs_srv_ucm_result_enum)ret;
}

S32 CALLCC UcmService::query_call_count(gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type, 
                                                    gs_srv_ucm_index_info_struct *index_list)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_call_count");
    return srv_ucm_query_call_count((srv_ucm_call_state_enum)call_state,(srv_ucm_call_type_enum)call_type,
                                     (srv_ucm_index_info_struct*)index_list);
}

S32 CALLCC UcmService::query_disconnecting_call_count(gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type, 
                                                            gs_srv_ucm_index_info_struct *index_list)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_disconnecting_call_count");
    return srv_ucm_query_disconnecting_call_count((srv_ucm_call_state_enum)call_state, (srv_ucm_call_type_enum)call_type,
                                                     (srv_ucm_index_info_struct*)index_list);   
}

MMI_BOOL CALLCC UcmService::query_call_data(gs_srv_ucm_index_info_struct index, gs_srv_ucm_call_info_struct *call_info)
{  
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_call_data");
    if(!call_info)
        return MMI_FALSE;
        
    MMI_BOOL bRet;
    srv_ucm_call_info_struct tmp_info;
    
    bRet =  srv_ucm_query_call_data(*(srv_ucm_index_info_struct*)&index, &tmp_info);
    if (!bRet)
        return bRet;
        
    //gs_srv_ucm_id_info_struct
    call_info->uid_info.call_id = tmp_info.uid_info.call_id;
    call_info->uid_info.group_id = tmp_info.uid_info.group_id;
    call_info->uid_info.call_type = (gs_srv_ucm_call_type_enum)tmp_info.uid_info.call_type;
    //gs_srv_ucm_call_state_enum
    call_info->call_state = (gs_srv_ucm_call_state_enum)tmp_info.call_state;
    //gs_srv_ucm_remote_info_struct
    mmi_wcsncpy(call_info->remote_info.log_name, tmp_info.remote_info.log_name,GS_SRV_COMMON_MAX_LENGTH);
    mmi_wcsncpy(call_info->remote_info.disp_name, tmp_info.remote_info.disp_name,GS_SRV_COMMON_MAX_LENGTH);
    strncpy((char*)call_info->remote_info.num_uri,(const char*)tmp_info.remote_info.num_uri,SRV_UCM_MAX_NUM_URI_LEN);
    call_info->remote_info.line_icon = tmp_info.remote_info.line_icon;
#ifdef __MMI_UCM_NUMBER_TYPE__
    call_info->remote_info.num_type_icon = tmp_info.remote_info.num_type_icon;
#else
    call_info->remote_info.num_type_icon = 0;
#endif
    //GS_SRV_PHB_ID
    call_info->remote_info.phb_id.storage_type= tmp_info.remote_info.phb_id.storage_type;
    call_info->remote_info.phb_id.number_index= tmp_info.remote_info.phb_id.number_index;
    call_info->remote_info.phb_id.contact_index= tmp_info.remote_info.phb_id.contact_index;
    //gs_srv_ucm_module_origin_enum
    call_info->module_id = (gs_srv_ucm_module_origin_enum)tmp_info.module_id;
    //srv_ucm_process_state_enum
    call_info->proc_state = (gs_srv_ucm_process_state_enum)tmp_info.proc_state;
    //gs_srv_ucm_act_opcode_enum
    call_info->act_op = (gs_srv_ucm_act_opcode_enum)tmp_info.act_op;
    //gs_srv_ucm_time_struct
    memcpy(&(call_info->start_time),&(tmp_info.start_time),sizeof(gs_srv_ucm_time_struct));
    
    call_info->is_disconnecting = tmp_info.is_disconnecting;

    return bRet;  
}

S32 CALLCC UcmService::query_group_count(gs_srv_ucm_call_state_enum call_state, gs_srv_ucm_call_type_enum call_type, MMI_BOOL single_only,
                                                S32 *index_list)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_group_count");
    return srv_ucm_query_group_count((srv_ucm_call_state_enum)call_state,(srv_ucm_call_type_enum)call_type,single_only,index_list);
} 

S32 CALLCC UcmService::query_group_data(S32 group_index, gs_srv_ucm_group_info_struct *group_info)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_group_data");
    return srv_ucm_query_group_data(group_index,(srv_ucm_group_info_struct*)group_info);
}

MMI_BOOL CALLCC UcmService::query_call_exist(gs_srv_ucm_id_info_struct* uid_info, gs_srv_ucm_call_state_enum call_state)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_call_exist");
    if(!uid_info)
        return MMI_FALSE;
        
    return srv_ucm_query_call_exist((srv_ucm_id_info_struct*)uid_info,(srv_ucm_call_state_enum)call_state);
}

MMI_BOOL CALLCC UcmService::query_group_exist(S32 group_id, gs_srv_ucm_call_type_enum call_type, gs_srv_ucm_call_state_enum call_state)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_group_exist");
    return srv_ucm_query_group_exist(group_id,(srv_ucm_call_type_enum)call_type,(srv_ucm_call_state_enum)call_state);
}

MMI_BOOL CALLCC UcmService::query_index_by_id(gs_srv_ucm_id_info_struct* uid_info, gs_srv_ucm_index_info_struct* index)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_index_by_id");
    if(!uid_info || !index)
        return MMI_FALSE;
        
    return srv_ucm_query_index_by_id((srv_ucm_id_info_struct*)uid_info,(srv_ucm_index_info_struct*)index);    
}

MMI_BOOL CALLCC UcmService::query_group_index_by_group_id(S16 group_id, gs_srv_ucm_call_type_enum call_type, S32* group_index)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_group_index_by_group_id");
    if(!group_index)
        return MMI_FALSE;
        
    return srv_ucm_query_group_index_by_group_id(group_id,(srv_ucm_call_type_enum)call_type,group_index);
}

gs_srv_ucm_act_opcode_enum CALLCC UcmService::query_curr_action(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_curr_action");
    return (gs_srv_ucm_act_opcode_enum)srv_ucm_query_curr_action();
}

MMI_BOOL CALLCC UcmService::query_reject_by_sms_permit(gs_srv_ucm_single_call_act_req_struct mt_call_uid)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_reject_by_sms_permit");
    return srv_ucm_query_reject_by_sms_permit(*(srv_ucm_single_call_act_req_struct*)&mt_call_uid);
}

MMI_BOOL CALLCC UcmService::reject_by_sms(gs_srv_ucm_single_call_act_req_struct mt_call_uid, S8* ucs2_content, gs_srv_ucm_sim_enum sim_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::reject_by_sms");
    return srv_ucm_reject_by_sms(*(srv_ucm_single_call_act_req_struct*)&mt_call_uid,ucs2_content,(mmi_sim_enum)sim_id);
}

MMI_BOOL CALLCC UcmService::intercept(gs_srv_ucm_call_type_enum call_type, U16 *number, gs_srv_ucm_module_origin_enum module_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::intercept");
    return srv_ucm_intercept((srv_ucm_call_type_enum)call_type,number,(srv_ucm_module_origin_enum)module_id);    
}

MMI_BOOL CALLCC UcmService::query_app_exit(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_app_exit");

#ifdef __MMI_BACKGROUND_CALL__
    return srv_ucm_query_app_exit();
#else
    return MMI_FALSE;
#endif    
}

MMI_BOOL CALLCC UcmService::is_background_call(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_background_call");
#ifdef __MMI_BACKGROUND_CALL__
    return srv_ucm_is_background_call();
#else
    return MMI_FALSE;
#endif      
}

MMI_BOOL CALLCC UcmService::is_incoming_call(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_incoming_call");
    return srv_ucm_is_incoming_call();
}

MMI_BOOL CALLCC UcmService::is_outgoing_call(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_outgoing_call");
    return srv_ucm_is_outgoing_call();
}

MMI_BOOL CALLCC UcmService::is_any_call(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_any_call");
    return srv_ucm_is_any_call();
}

MMI_BOOL CALLCC UcmService::is_emergency_call(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_emergency_call");
    return srv_ucm_is_emergency_call();
}

MMI_BOOL CALLCC UcmService::is_call_srv_available(gs_srv_ucm_call_type_enum call_type)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_call_srv_available");
    return srv_ucm_is_call_srv_available((srv_ucm_call_type_enum)call_type);
}

MMI_BOOL CALLCC UcmService::is_call_srv_tmp_unavailable(gs_srv_ucm_call_type_enum call_type)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_call_srv_tmp_unavailable");
    return srv_ucm_is_call_srv_tmp_unavailable((srv_ucm_call_type_enum)call_type);
}

MMI_BOOL CALLCC UcmService::is_pending_action(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_pending_action");
    return srv_ucm_is_pending_action();
}

MMI_BOOL CALLCC UcmService::is_busy(void)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_busy");
    return srv_ucm_is_busy();    
}

MMI_BOOL CALLCC UcmService::is_valid_number(gs_srv_ucm_call_type_enum call_type, U8 *number)
{
    if(!number)
        return MMI_FALSE;

    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_valid_number");
    
    return srv_ucm_is_valid_number((srv_ucm_call_type_enum)call_type,number);
}

MMI_BOOL CALLCC UcmService::is_emergency_number(gs_srv_ucm_call_type_enum call_type, U8 *number)
{
    if(!number)
        return MMI_FALSE;
        
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_emergency_number");

    return srv_ucm_is_emergency_number((srv_ucm_call_type_enum)call_type,number);
}

MMI_BOOL CALLCC UcmService::is_valid_dtmf_digit(gs_srv_ucm_call_type_enum call_type, U16 digit)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::is_valid_dtmf_digit");
    return srv_ucm_is_valid_dtmf_digit((srv_ucm_call_type_enum)call_type,digit);
}

MMI_BOOL CALLCC UcmService::get_caller_res_info(gs_srv_ucm_id_info_struct call_id, gs_srv_ucm_caller_res_struct *res_info)
{
    MMI_BOOL bRet;
    srv_ucm_caller_res_struct tmp_res_info;

    if(!res_info)
        return MMI_FALSE;

    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::get_caller_res_info");
    
    bRet =  srv_ucm_get_caller_res_info(*(srv_ucm_id_info_struct*)&call_id,&tmp_res_info);
    if (!bRet)
        return bRet;
 
    res_info->res_type = (gs_srv_ucm_res_type_enum)tmp_res_info.res_type;
    res_info->pic_id = tmp_res_info.pic_id;
    mmi_wcsncpy(res_info->pic_path,tmp_res_info.pic_path,GS_SRV_FMGR_PATH_MAX_LEN);
    res_info->video_id = tmp_res_info.video_id;
    mmi_wcsncpy(res_info->video_path,tmp_res_info.video_path,GS_SRV_FMGR_PATH_MAX_LEN);
    res_info->tone_id = tmp_res_info.tone_id;
    mmi_wcsncpy(res_info->tone_path,tmp_res_info.tone_path,GS_SRV_FMGR_PATH_MAX_LEN);
    res_info->is_video_sound = tmp_res_info.is_video_sound;

    return bRet;
}

U16 CALLCC UcmService::query_error_message(gs_srv_ucm_result_enum error_cause)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_error_message");
    return srv_ucm_query_error_message((srv_ucm_result_enum)error_cause);
}

MMI_BOOL CALLCC UcmService::query_mute_permit(gs_srv_ucm_id_info_struct call_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_mute_permit");
    return srv_ucm_query_mute_permit(*(srv_ucm_id_info_struct*)&call_id);
}

MMI_BOOL CALLCC UcmService::query_loudspeaker_permit(gs_srv_ucm_id_info_struct call_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_loudspeaker_permit");
    return srv_ucm_query_loudspeaker_permit(*(srv_ucm_id_info_struct*)&call_id);
}

MMI_BOOL CALLCC UcmService::query_sndrec_permit(gs_srv_ucm_id_info_struct call_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_sndrec_permit");
    return srv_ucm_query_sndrec_permit(*(srv_ucm_id_info_struct*)&call_id);
}

MMI_BOOL CALLCC UcmService::query_bgs_in_call_permit(gs_srv_ucm_id_info_struct call_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_bgs_in_call_permit");
    return srv_ucm_query_bgs_in_call_permit(*(srv_ucm_id_info_struct*)&call_id);
}

MMI_BOOL CALLCC UcmService::query_bgs_incoming_call_permit(gs_srv_ucm_id_info_struct call_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_bgs_incoming_call_permit");
    return srv_ucm_query_bgs_incoming_call_permit(*(srv_ucm_id_info_struct*)&call_id);
}

MMI_BOOL CALLCC UcmService::query_bgs_outgoing_call_permit(gs_srv_ucm_call_type_enum call_type)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_bgs_outgoing_call_permit");
    return srv_ucm_query_bgs_outgoing_call_permit((srv_ucm_call_type_enum)call_type);
}

MMI_BOOL CALLCC UcmService::query_switch_bt_audio_path_permit(gs_srv_ucm_id_info_struct call_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_switch_bt_audio_path_permit");
    return srv_ucm_query_switch_bt_audio_path_permit(*(srv_ucm_id_info_struct*)&call_id);
}

MMI_BOOL CALLCC UcmService::query_connect_last_bt_device_permit(gs_srv_ucm_id_info_struct call_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_connect_last_bt_device_permit");
    return srv_ucm_query_connect_last_bt_device_permit(*(srv_ucm_id_info_struct*)&call_id);
}

MMI_BOOL CALLCC UcmService::query_connect_ctm_permit(gs_srv_ucm_id_info_struct call_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UcmService::query_connect_ctm_permit");
    return srv_ucm_query_connect_ctm_permit(*(srv_ucm_id_info_struct*)&call_id);
}


