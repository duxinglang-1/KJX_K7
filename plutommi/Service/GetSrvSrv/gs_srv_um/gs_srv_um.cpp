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
 *   gs_srv_um.cpp
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IUm implement file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
#include "mmi_include.h"
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "UmSrvGprot.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_um_impl.h"
#include "vmpromng.h"

typedef S32 (*common_cb)(S32 pid, void* rsp, S32 user_data);

typedef struct
{
    VM_P_HANDLE handle;
    common_cb cb;
    S32 user_data;
}callback_data;

typedef void* (*UM_malloc)(int size);

static UM_malloc g_um_malloc;

#define UM_COMMON_CALLBACK_BEGIN(p_new_data,call_back,user_data) \
    addRef();\
    release();\
    if (gs_is_MRE_free() && call_back)\
    {\
        callback_data* pdata;\
        pdata = (callback_data*)(*g_um_malloc)(sizeof(callback_data));\
        if (!pdata)\
        {\
            return GS_SRV_UM_RESULT_NO_MEMORY;\
        }\
        pdata->cb = (common_cb)call_back;\
        pdata->handle = vm_pmng_get_current_handle();\
        pdata->user_data = user_data;\
        *p_new_data = (S32)pdata;\
    }\
    else\
    {\
        *p_new_data = user_data;\
    }
    
#define TRANS_UM_MSG_BOX_ENUM(enum) \
    enum == GS_SRV_UM_MSG_BOX_ALL? SRV_UM_MSG_BOX_ALL : enum;

static void tans_box_id_struct(srv_um_box_identity_struct* pDes,gs_srv_um_box_identity_struct Src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pDes->msg_type = (srv_um_msg_enum)Src.msg_type;
    pDes->msg_box_type = (srv_um_msg_box_enum)(Src.msg_box_type == GS_SRV_UM_MSG_BOX_ALL? SRV_UM_MSG_BOX_ALL : Src.msg_box_type);
    pDes->sim_id = (srv_um_sim_enum)Src.sim_id;
}

static void tans_msg_info_struct(gs_srv_um_msg_info_struct* pDes, const srv_um_msg_info_struct* pSrc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pDes->msg_id = pSrc->msg_id;
    pDes->timestamp = pSrc->timestamp;
    pDes->address_type = (gs_srv_um_addr_enum)pSrc->address_type;
    
    pDes->address_length = pSrc->address_length;
    memcpy(pDes->address,pSrc->address,SRV_UM_MAX_ADDR_LEN+1);

    pDes->subject_length = pSrc->subject_length;
    memcpy(pDes->subject,pSrc->subject,GS_SRV_UM_MAX_SUBJECT_LEN+1);
    
    pDes->icon_id = pSrc->icon_id;
#ifdef __MMI_DUAL_SIM_MASTER__
    pDes->sim_id = (gs_srv_um_sim_enum)pSrc->sim_id;
#endif
    pDes->csk_icon_id = pSrc->csk_icon_id;
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    memcpy((void *)&pDes->thread_id,(void *)&pSrc->thread_id,sizeof(gs_srv_um_thread_id_struct));   
#endif    
}
    

S32 common_callback(S32 pid, void* rsp, S32 user_data)
{
    S32 res = 0;
    callback_data* data = (callback_data*)user_data;

    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] common_callback");
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->handle))
    {
        if (data->cb)
        {
            res = (*data->cb)(pid,rsp,data->user_data);      
        }
		gs_free(data);
        vm_pmng_reset_ctx();
    }  
    return res;
}

void notify_cb(S32 event, S32 list_cid, S32 user_data)
{
    callback_data* data = (callback_data*)user_data;

    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] notify_cb");
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->handle))
    {
        if (data->cb)
        {
            (*(gs_srv_um_notify_list_handler)data->cb)(event,list_cid,data->user_data);      
        }
		gs_free(data);
        vm_pmng_reset_ctx();
    }  
    
}


GS_IBase *CreateUmService(U32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmService* service = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    //temp use vm_malloc   
    g_um_malloc = vm_malloc;   
    GS_NEW_EX(service, UmService,(hd));
    return (GS_IBase*)(GS_CBase*)service;
}


S32 UmService::queryInterface(S32 iid, GS_IBase **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Please notes: pptr may be a proxy, your call should not use it directly. */
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::queryInterface");
    
    if (pptr == NULL)
        return 0;
    if (iid == IID_IUM)
    {
        addRef();
        *pptr = BIND_PROXY(IUm, this);
        return 1;
    }
    return GS_CBase::queryInterface(iid, pptr);
}


MMI_BOOL UmService::check_support_type(gs_srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::check_support_type");
    
    return srv_um_check_support_type((srv_um_msg_enum)msg_type);
}

MMI_BOOL UmService::check_ready_type(gs_srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::check_ready_type");
    
    return srv_um_check_ready_type((srv_um_msg_enum)msg_type);
}

S32 UmService::clear_msg_info_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::clear_msg_info_cache");
    
    return srv_um_clear_msg_info_cache();
}

S32 UmService::cancel_request(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::cancel_request");
    
    return srv_um_cancel_request(pid);
}

S32 UmService::get_request_progress(S32 pid, S32 *finish_number, S32 *total_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::get_request_progress");
    
    return srv_um_get_request_progress(pid, finish_number, total_number);
}

S32 UmService::check_list(
    gs_srv_um_list_type_enum list_type,
    gs_srv_um_box_identity_struct msg_box,
    gs_srv_um_list_filter_struct *filter,
    gs_srv_um_notify_list_handler cb_func,
    S32 user_data,
    gs_srv_um_list_cntx_struct **list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 new_data;
    srv_um_box_identity_struct box_id_struct;
    srv_um_list_cntx_struct* list_cntx_tmp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::check_list");
    
    if(NULL == list_cntx)
    {
        return GS_SRV_UM_RESULT_INVALID_PARA;
    }
#ifndef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    if (GS_SRV_UM_LIST_TYPE_THREAD == list_type)
    {
        return GS_SRV_UM_RESULT_NOT_SUPPORT;
    }
#endif 
    UM_COMMON_CALLBACK_BEGIN(&new_data,cb_func,user_data)
    
    tans_box_id_struct(&box_id_struct,msg_box);
    
    ret = srv_um_check_list((srv_um_list_type_enum)list_type,
                      box_id_struct,
                      (srv_um_list_filter_struct*)filter,
                      (srv_um_notify_list_handler)notify_cb,
                      new_data,
                      &list_cntx_tmp);
    if (ret < 0)
    {
        gs_free((void*)new_data);
        return ret;
    }
    
    *list_cntx = (gs_srv_um_list_cntx_struct*)(&list_cntx_tmp->list);  
    return ret;
}    

S32 UmService::check_msg_info(
    gs_srv_um_box_identity_struct msg_box,
    gs_srv_um_msg_node_struct msg_list[],
    U16 list_info_size,
    U16 start_entry,
    U16 msg_number,
    gs_srv_um_msg_info_struct msg_info[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret,i;
    srv_um_box_identity_struct box_id_struct;
    srv_um_msg_info_struct* msg_info_tmp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::check_msg_info");
    
    tans_box_id_struct(&box_id_struct,msg_box);
    
    //tmp use vm_malloc
    msg_info_tmp = (srv_um_msg_info_struct*)(*g_um_malloc)(sizeof(srv_um_msg_info_struct)*msg_number);
    if (!msg_info_tmp)
    {
        return GS_SRV_UM_RESULT_NO_MEMORY;
    }
    
    ret = srv_um_check_msg_info(box_id_struct,(srv_um_msg_node_struct*)msg_list,list_info_size,start_entry,msg_number,msg_info_tmp);
    if (ret)
    {
        return ret;
    }
    for (i = 0; i < msg_number; i++)
    {
        tans_msg_info_struct(&msg_info[i],&msg_info_tmp[i]);
    }
    vm_free(msg_info_tmp);
    return ret;
}    

S32 UmService::get_msg_num(
    gs_srv_um_msg_enum msg_type,
    gs_srv_um_sim_enum sim_id,
    gs_srv_um_get_msg_num_cb cb_func,
    S32 user_data)  
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_data;
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::get_msg_num");
    
    UM_COMMON_CALLBACK_BEGIN(&new_data,cb_func,user_data);
    result = srv_um_get_msg_num((srv_um_msg_enum)msg_type,(srv_um_sim_enum)sim_id,(srv_um_get_msg_num_cb)common_callback,new_data);
    if (result < 0)
    {
        gs_free((void*)new_data);
    }
    return result;
}
S32 UmService::get_list(
    gs_srv_um_list_type_enum list_type,
    gs_srv_um_box_identity_struct msg_box,
    gs_srv_um_list_filter_struct *filter,
    gs_srv_um_get_msg_list_cb cb_func,
    S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 new_data;
    srv_um_box_identity_struct box_id_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::get_list");
    
#ifndef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    if (GS_SRV_UM_LIST_TYPE_THREAD == list_type)
    {
        return GS_SRV_UM_RESULT_NOT_SUPPORT;
    }
#endif   
    tans_box_id_struct(&box_id_struct,msg_box);
    UM_COMMON_CALLBACK_BEGIN(&new_data,cb_func,user_data);
    
    result =  srv_um_get_list((srv_um_list_type_enum)list_type,box_id_struct,(srv_um_list_filter_struct*)filter,(srv_um_get_msg_list_cb)common_callback,new_data);
    if (result < 0)
    {
        gs_free((void*)new_data);
    }
    return result;
}    

S32 UmService::release_list(S32 list_cid, MMI_BOOL out_of_date)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::release_list");
    
    return srv_um_release_list(list_cid, out_of_date);
}

S32 UmService::get_msg_info (
    gs_srv_um_box_identity_struct msg_box,
    gs_srv_um_msg_node_struct msg_list[],
    U16 msg_number,
    gs_srv_um_get_msg_info_cb cb_func,
    S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 new_data;
    srv_um_box_identity_struct box_id_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::get_msg_info");
    
    tans_box_id_struct(&box_id_struct,msg_box);
    UM_COMMON_CALLBACK_BEGIN(&new_data,cb_func,user_data);
    
    result = srv_um_get_msg_info(box_id_struct,(srv_um_msg_node_struct*)msg_list,msg_number,(srv_um_get_msg_info_cb)common_callback,new_data);
    if (result < 0)
    {
        gs_free((void*)new_data);
    }
    return result;
}    

S32 UmService::delete_folder(
    gs_srv_um_box_identity_struct msg_box,
    gs_srv_um_delete_folder_cb cb_func,
    S32 user_data)                                                  
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 new_data;
    srv_um_box_identity_struct box_id_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::delete_folder");
    
    tans_box_id_struct(&box_id_struct,msg_box);
    UM_COMMON_CALLBACK_BEGIN(&new_data,cb_func,user_data);
    
    result = srv_um_delete_folder(box_id_struct, (srv_um_delete_folder_cb)common_callback, new_data); 
    if (result < 0)
    {
        gs_free((void*)new_data);
    }
    return result;
}
S32 UmService::check_thread_info(
    gs_srv_um_box_identity_struct msg_box,
    gs_srv_um_thread_id_struct thread_list[],
    U16 list_info_size,
    U16 start_entry,
    U16 thread_number,
    gs_srv_um_thread_info_struct *thread_info[],
    gs_srv_um_msg_info_struct msg_info[])
{
#ifndef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    return GS_SRV_UM_RESULT_NOT_SUPPORT;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret,i;
    srv_um_box_identity_struct box_id_struct;
    srv_um_msg_info_struct** msg_info_tmp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::check_thread_info");
    
    tans_box_id_struct(&box_id_struct,msg_box);
    
    //tmp use vm_malloc
    msg_info_tmp = (srv_um_msg_info_struct**)(*g_um_malloc)(sizeof(srv_um_msg_info_struct*)*thread_number);
    if (!msg_info_tmp)
    {
        return GS_SRV_UM_RESULT_NO_MEMORY;
    }
    
    ret = srv_um_check_thread_info(box_id_struct,(srv_um_thread_id_struct*)thread_list,
                                list_info_size,start_entry,thread_number,(srv_um_thread_info_struct**)thread_info,
                                msg_info_tmp);
    if (ret < 0)
    {
        return ret;
    }
    
    for (i = 0; i < thread_number; i++)
    {
        tans_msg_info_struct(&msg_info[i],msg_info_tmp[i]);
    }
    vm_free(msg_info_tmp);
    return ret;
#endif    
}    

S32 UmService::get_thread_info (
    gs_srv_um_box_identity_struct msg_box,
    gs_srv_um_thread_id_struct thread_list[],
    U16 thread_number,
    gs_srv_um_get_thread_info_cb cb_func,
    S32 user_data)
{
#ifndef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    return GS_SRV_UM_RESULT_NOT_SUPPORT;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 new_data;
    srv_um_box_identity_struct box_id_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::get_thread_info");
    
    tans_box_id_struct(&box_id_struct,msg_box);
    UM_COMMON_CALLBACK_BEGIN(&new_data,cb_func,user_data);
    
    result = srv_um_get_thread_info(box_id_struct, (srv_um_thread_id_struct*)thread_list, thread_number, 
                                    (srv_um_get_thread_info_cb)common_callback, new_data);
    if (result < 0)
    {
        gs_free((void*)new_data);
    }
    return result;                                    
#endif    
}    
    
S32 UmService::mark_several_thread_op(
    gs_srv_um_box_identity_struct msg_box,
    gs_srv_um_thread_id_struct thread_list[],
    U16 thread_list_size,
    U32 mark_status[],
    gs_srv_um_mark_several_op_action_enum action_type,
    gs_srv_um_mark_several_thread_op_cb cb_func,
    S32 user_data)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::mark_several_thread_op");
    
#ifndef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    return GS_SRV_UM_RESULT_NOT_SUPPORT;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 new_data;
    srv_um_box_identity_struct box_id_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tans_box_id_struct(&box_id_struct,msg_box);
    UM_COMMON_CALLBACK_BEGIN(&new_data,cb_func,user_data);
    
    result = srv_um_mark_several_thread_op(box_id_struct, (srv_um_thread_id_struct*)thread_list,
                                        thread_list_size,mark_status, 
                                        (srv_um_mark_several_op_action_enum)action_type,
                                        (srv_um_mark_several_thread_op_cb)common_callback, new_data);
    if (result < 0)
    {
        gs_free((void*)new_data);
    }
    return result;                                        
#endif    
}    

S32 UmService::tsfr_address_to_thread_id(gs_srv_um_addr_enum type, U16* ucs2_str, gs_srv_um_thread_id_struct *thread_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::tsfr_address_to_thread_id");
    
#ifndef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    return GS_SRV_UM_RESULT_NOT_SUPPORT;
#else
    return srv_um_tsfr_address_to_thread_id((srv_um_addr_enum)type, ucs2_str, SRV_UM_SIM_UNCLASSIFIED,(srv_um_thread_id_struct*)thread_id);
#endif    
}

S32 UmService::update_thread_id(gs_srv_um_thread_id_struct *thread_id)
{
    //MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] UmService::update_thread_id");
#ifndef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        return GS_SRV_UM_RESULT_NOT_SUPPORT;
#else
    return srv_um_update_thread_id((srv_um_thread_id_struct*)thread_id);
#endif    
}

