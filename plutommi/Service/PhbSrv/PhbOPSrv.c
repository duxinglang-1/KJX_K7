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
 *  PhbOPSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbOPSrv.h"
#include "PhbSrv.h"
#ifdef __MMI_MULTI_VCARD__
#include "vcard_lib.h"
#include "FileMgrSrvGprot.h"
#include "Fs_gprot.h"
#endif


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
typedef struct
{
    MMI_BOOL stop_op_flag;
    MMI_BOOL multi_op_flag;
} srv_phb_op_global_cntx_struct;


typedef struct
{
    U32 max_pid;
    U32 queue[SRV_PHB_QUERY_PID_COUTN];
    U32 front;
    U32 rear;
} srv_phb_query_async_op_cntx_struct;


/* Define your local variable here */
static srv_phb_op_global_cntx_struct g_srv_phb_op_cntx;

srv_phb_query_async_op_cntx_struct g_srv_phb_query_async_cntx, *g_srv_phb_query_async_cntx_p;

/* Declare your local function here */

static void srv_phb_move_all_add_cb(S32 result, U16 store_index, void* user_data);
static void srv_phb_multi_move_add_cb(S32 result, mmi_phb_contact_id id, void* user_data);
#ifdef __MMI_MULTI_VCARD__
static void srv_phb_restore_parse_cb(kal_int32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data);
#endif


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_multi_op_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_update_multi_op_status(srv_phb_multi_op_handle_struct* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_status_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_MULTI_OP_STATUS);
    evt.finish_count= handle->finish_count;
    evt.fail_count = handle->fail_count;
    evt.total_count = handle->total_count;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    if (!handle->is_canceled)
    {
        srv_phb_multi_op_status_cb_struct cb_cntx;
        cb_cntx.type = SRV_PHB_OP_CB_TYPE_UPDATE_STATUS;
        cb_cntx.handle = handle;
        cb_cntx.user_data = handle->user_data;
        cb_cntx.finish_count = handle->finish_count;
        cb_cntx.fail_count = handle->fail_count;
        cb_cntx.total_count = handle->total_count;
        handle->cb((srv_phb_async_op_cb_struct*)&cb_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_update_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_phb_update_status_res_req_struct *my_msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_l4c_phb_update_status_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_phb_update_status_res_req_struct));

    my_msg_ptr->type = PHB_PHONEBOOK;
    my_msg_ptr->storage = PHB_STORAGE_NVRAM;
    my_msg_ptr->total = srv_phb_datamgr_total_contacts(PHB_STORAGE_NVRAM);
    my_msg_ptr->used = srv_phb_datamgr_used_contacts(PHB_STORAGE_NVRAM);
    my_msg_ptr->free = my_msg_ptr->total - my_msg_ptr->used;
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_L4C_PHB_UPDATE_STATUS_RES_REQ, (oslParaType*) my_msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_op_hanlde
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_init_op_hanlde(
                    srv_phb_op_handle_struct* handle,
                    srv_phb_op_cb_type_enum type,
                    srv_phb_async_op_callback_type cb,
                    void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle);
    handle->result = SRV_PHB_NO_ERROR;
    handle->type = type;
    handle->is_canceled = MMI_FALSE;
    handle->is_stoped = MMI_FALSE;
    handle->cb = cb;
    handle->user_data = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_multi_op_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_set_multi_op_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_op_cntx.multi_op_flag = MMI_TRUE;
    g_srv_phb_op_cntx.stop_op_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_clear_multi_op_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_clear_multi_op_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_op_cntx.multi_op_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_creat_single_hanlde
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_phb_single_op_handle_struct* srv_phb_create_single_handle(
                                                srv_phb_op_cb_type_enum type,
                                                void* user_data,
                                                srv_phb_async_op_callback_type cb,
                                                mmi_phb_contact_id id,
                                                srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CREATE_SINGLE_HANDLE, type);
    handle = srv_phb_mem_malloc(sizeof(srv_phb_single_op_handle_struct), SRV_PHB_MEMORY_TYPE_ADM);
    srv_phb_init_op_hanlde((srv_phb_op_handle_struct*)handle, type, cb, user_data);
    
    handle->id = id;
    if (contact)
    {
        handle->contact = srv_phb_create_contact(contact);
    }
    else
    {
        handle->contact = NULL;
    }
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_creat_single_hanlde
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_phb_multi_op_handle_struct* srv_phb_create_multi_handle(
                                                srv_phb_op_cb_type_enum type,
                                                srv_phb_async_op_callback_type cb,
                                                void* user_data,
                                                mmi_phb_contact_id* id_array,
                                                U8 src_storage,
                                                U8 dest_storage,
                                                U16 total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CREATE_MULTI_HANDLE, type, src_storage, dest_storage, total_count);
    handle = srv_phb_mem_malloc(sizeof(srv_phb_multi_op_handle_struct), SRV_PHB_MEMORY_TYPE_ADM);
    srv_phb_init_op_hanlde((srv_phb_op_handle_struct*)handle, type, cb, user_data);
    
    handle->contact = NULL;
    if (id_array)
    {
        handle->id_array = srv_phb_mem_malloc(sizeof(mmi_phb_contact_id) * total_count, SRV_PHB_MEMORY_TYPE_ADM);
        memcpy(handle->id_array, id_array, sizeof(mmi_phb_contact_id) * total_count);
    }
    else
    {
        handle->id_array = NULL;
    }

    handle->src_storage = src_storage;
    handle->dest_storage = dest_storage;
    if (dest_storage != PHB_STORAGE_NVRAM &&
        (type != SRV_PHB_OP_CB_TYPE_DELETE_ALL) &&
        (type != SRV_PHB_OP_CB_TYPE_MULTI_DELETE))
    {
        handle->filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_SIM);
    }
    else
    {
        handle->filter = NULL;
    }
    handle->active_index = 0;
    handle->total_count = total_count;
    handle->finish_count = 0;
    handle->fail_count = 0;
    handle->id = 0;
#ifdef __MMI_MULTI_VCARD__
    handle->b_handle = NULL;
    handle->p_handle = NULL;
    handle->vcard_object = NULL;
#endif
    //handle->cloud_handle = -1;
    return handle;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_free_single_op_handle
* DESCRIPTION
*  
* PARAMETERS
*         
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_free_single_op_handle(srv_phb_single_op_handle_struct* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->contact)
    {
        srv_phb_free_contact(handle->contact);
        handle->contact = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_free_multi_op_handle
* DESCRIPTION
*  
* PARAMETERS
*         
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_free_multi_op_handle(srv_phb_multi_op_handle_struct* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->contact)
    {
        srv_phb_free_contact(handle->contact);
        handle->contact = NULL;
    }
    if (handle->filter)
    {
        srv_phb_free_field_filter(handle->filter);
        handle->filter= NULL;
    }
    if (handle->id_array)
    {
        srv_phb_mem_free(handle->id_array);
        handle->id_array = NULL;
    }
#ifdef __MMI_MULTI_VCARD__
    if (handle->vcard_object)
    {
        srv_phb_mem_free(handle->vcard_object);
        handle->vcard_object = NULL;
    }
    if (handle->b_handle)
    {
        vcard_close_builder(handle->b_handle);
        handle->b_handle = NULL;
    }
    if (handle->p_handle)
    {
        vcard_close_parser(handle->p_handle);
        handle->p_handle = NULL;
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  srv_phb_single_op_fail
* DESCRIPTION
*  
* PARAMETERS
*         
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_single_op_fail(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle = (srv_phb_single_op_handle_struct*)info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_free_single_op_handle(handle);
    if (handle->is_canceled)
    {
        srv_phb_mem_free(handle);
    }
    else
    {
        if (handle->cb)
        {
            srv_phb_add_cb_struct cb_cntx;
            cb_cntx.type = handle->type;
            cb_cntx.handle = handle;
            cb_cntx.user_data = handle->user_data;
            cb_cntx.result = handle->result;
            cb_cntx.id = handle->id;
            handle->cb((srv_phb_async_op_cb_struct*)&cb_cntx);
        }
        handle->is_canceled = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_single_op_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_single_op_done(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SINGLE_OP_DONE, result, id);
    srv_phb_free_single_op_handle(handle);
    if (result >= 0 && id < MMI_PHB_PHONE_ENTRIES)
    {
        srv_phb_update_status_req();
    }

    if (handle->is_canceled)
    {
        srv_phb_mem_free(handle);
    }
    else
    {
        handle->is_canceled = MMI_TRUE;
        if (handle->cb)
        {
            srv_phb_add_cb_struct cb_cntx;
            cb_cntx.type = handle->type;
            cb_cntx.handle = handle;
            cb_cntx.user_data = handle->user_data;
            if (result != SRV_PHB_NO_ERROR)
            {
                cb_cntx.result = result;
            }
            else
            {
                cb_cntx.result = handle->result;
            }
            if (handle->type == SRV_PHB_OP_CB_TYPE_MOVE || result < 0)
            {
                cb_cntx.id = handle->id;
            }
            else
            {
                cb_cntx.id = id;
            }
            handle->cb((srv_phb_async_op_cb_struct*)&cb_cntx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_move_op_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_move_op_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_op_cntx.stop_op_flag || result < 0)
    {
        srv_phb_single_op_done(result, id, user_data);
    }
    else
    {
        srv_phb_datamgr_delete_req_struct delete_req;
        delete_req.id = handle->id;
        delete_req.cb = srv_phb_single_op_done;
        delete_req.user_data = handle;
        handle->result = result;
        srv_phb_datamgr_delete_contact(&delete_req);
        handle->id = id;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_op_get_index_by_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_op_get_index_by_storage(U16 active_index, U8 storage, mmi_phb_contact_id* id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (active_index < srv_phb_datamgr_used_contacts(PHB_STORAGE_MAX))
    {
        index = srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX, active_index++);
        if (srv_phb_get_storage(index) == storage)
        {
            *id = index;
            return active_index;
        }
    }
    *id = MMI_PHB_INVALID_CONTACT_ID;
    return active_index;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_multi_op_done
* DESCRIPTION
*  
* PARAMETERS
*         
* RETURNS
*  void
*****************************************************************************/
void srv_phb_multi_op_done(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = (srv_phb_multi_op_handle_struct*)info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_MULTI_OP_DONE, handle->result);
    srv_phb_clear_multi_op_flag();
    if (handle->id_array && handle->finish_count)
    {
        while (handle->active_index < handle->total_count)
        {
            handle->id = handle->id_array[handle->active_index];
            handle->id_array[handle->active_index++] = handle->id_array[handle->fail_count];
            handle->id_array[handle->fail_count++] = handle->id;
        }
    }
    srv_phb_update_status_req();
    if (!handle->is_canceled)
    {
        if (handle->cb)
        {
            srv_phb_multi_copy_cb_struct cb_cntx;
            cb_cntx.result = handle->result;
            cb_cntx.fail_count = handle->fail_count;
            cb_cntx.type = handle->type;
            cb_cntx.handle = handle;
            cb_cntx.user_data = handle->user_data;
            cb_cntx.finish_count = handle->finish_count;
            cb_cntx.total_count = handle->total_count;
            cb_cntx.id_array = handle->id_array;
            handle->cb((srv_phb_async_op_cb_struct*)&cb_cntx);
        }
    }
    srv_phb_free_multi_op_handle(handle);
    if (handle->is_canceled)
    {
    #ifdef __DM_LAWMO_SUPPORT__
        srv_phb_multi_op_done_evt_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_MULTI_OP_DONE);
        evt.finish_count= handle->finish_count;
        evt.fail_count = handle->fail_count;
        evt.total_count = handle->total_count;
        evt.type = handle->type;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    #endif /* __DM_LAWMO_SUPPORT__ */
        srv_phb_mem_free(handle);
    }
    else
    {
        handle->is_canceled = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_all_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_copy_all_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;
    U16 sort_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        handle->finish_count++;
    }
    else
    {
        handle->fail_count++;
    }
    srv_phb_update_multi_op_status(handle);
    
    if (!g_srv_phb_op_cntx.stop_op_flag &&
        !(handle->is_stoped) &&
        !(handle->is_canceled) &&
        srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage))
    {
        /* get next contact id to copy */
        sort_index = srv_phb_sse_store_index_to_sort_index(PHB_STORAGE_MAX, handle->id);
        if (sort_index - 1 >= handle->active_index)
        {
            handle->active_index = sort_index;
        }
        handle->active_index = 
            srv_phb_op_get_index_by_storage(handle->active_index, handle->src_storage, &handle->id);
        if (handle->id != SRV_PHB_INVALID_INDEX)
        {
            srv_phb_datamgr_copy_req_struct copy_req;
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            if (handle->dest_storage != PHB_STORAGE_TCARD || srv_phb_tcard_is_ready() == MMI_TRUE)
            #endif
            {
                copy_req.id = handle->id;
                copy_req.storage = handle->dest_storage;
                copy_req.cb = srv_phb_copy_all_cb;
                copy_req.user_data = handle;
                srv_phb_datamgr_copy_contact(&copy_req);
                return;
            }
        }
    }
    handle->result = result;
    srv_phb_multi_op_done(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_move_all_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_move_all_delete_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        handle->finish_count++;
        handle->active_index--;
    }
    else
    {
        handle->fail_count++;
    }
    srv_phb_update_multi_op_status(handle);
    
    if (!g_srv_phb_op_cntx.stop_op_flag &&
        !(handle->is_stoped) &&
        !(handle->is_canceled) &&
        srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage))
    {
        /* jump to next index if this contact has been copied */
        if (srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX, handle->active_index) == handle->id)
        {
            handle->active_index++;
        }
        handle->active_index = 
            srv_phb_op_get_index_by_storage(handle->active_index, handle->src_storage, &(handle->id));

        if (handle->id != SRV_PHB_INVALID_INDEX)
        {
            srv_phb_datamgr_copy_req_struct copy_req;
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            if (handle->dest_storage != PHB_STORAGE_TCARD || srv_phb_tcard_is_ready() == MMI_TRUE)
            #endif
            {
                copy_req.id = handle->id;
                copy_req.storage = handle->dest_storage;
                copy_req.cb = srv_phb_move_all_add_cb;
                copy_req.user_data = handle;
                srv_phb_datamgr_copy_contact(&copy_req);
                return;
            }
        }
    }
    srv_phb_multi_op_done(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_move_all_add_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_move_all_add_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        srv_phb_datamgr_delete_req_struct delete_req;
        /* jump to next index if this contact has been copied */
        if (srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX, handle->active_index) == handle->id)
        {
            handle->active_index++;
        }

        delete_req.id = handle->id;
        delete_req.cb = srv_phb_move_all_delete_cb;
        delete_req.user_data = handle;
        srv_phb_datamgr_delete_contact(&delete_req);
        return;
    }
    srv_phb_move_all_delete_cb(result, id, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_all_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_delete_all_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        handle->finish_count++;
        handle->active_index--;
    }
    else
    {
        handle->fail_count++;
    }
    srv_phb_update_multi_op_status(handle);
    
    if (!g_srv_phb_op_cntx.stop_op_flag &&
        !(handle->is_stoped) &&
        !(handle->is_canceled) &&
        srv_phb_datamgr_used_contacts(handle->src_storage))
    {
        /* jump to next index if this contact has been copied */
        if (srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX, handle->active_index) == handle->id)
        {
            handle->active_index++;
        }
        handle->active_index = 
            srv_phb_op_get_index_by_storage(handle->active_index, handle->src_storage, &(handle->id));

        if (handle->id != SRV_PHB_INVALID_INDEX)
        {
            srv_phb_datamgr_delete_req_struct delete_req;
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            if (handle->src_storage != PHB_STORAGE_TCARD || srv_phb_tcard_is_ready() == MMI_TRUE)
            #endif
            {
                delete_req.id = handle->id;
                delete_req.cb = srv_phb_delete_all_cb;
                delete_req.user_data = handle;
                srv_phb_datamgr_delete_contact(&delete_req);
                return;
            }
        }
    }

    srv_phb_multi_op_done(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_multi_copy_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_multi_copy_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        handle->finish_count++;
    }
    else
    {
        handle->id_array[handle->active_index - 1] = handle->id_array[handle->fail_count];
        handle->id_array[handle->fail_count++] = handle->id;
    }
    srv_phb_update_multi_op_status(handle);
    
    if (!g_srv_phb_op_cntx.stop_op_flag &&
        !(handle->is_stoped) &&
        !(handle->is_canceled) &&
        (handle->active_index < handle->total_count) &&
        srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage))
    {
        handle->id = handle->id_array[handle->active_index++];

        if (srv_phb_datamgr_check_store_index(handle->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            srv_phb_datamgr_copy_req_struct copy_req;
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            if ((handle->dest_storage != PHB_STORAGE_TCARD && srv_phb_get_storage(handle->id)!= PHB_STORAGE_TCARD) 
                || FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_DEVICE_PRESENCE_ENUM) >= 0 
                || (handle->dest_storage == PHB_STORAGE_TCARD && result != SRV_PHB_TCARD_ERROR))
            #endif
            {
                copy_req.id = handle->id;
                copy_req.storage = handle->dest_storage;
                copy_req.cb = srv_phb_multi_copy_cb;
                copy_req.user_data = handle;
                srv_phb_datamgr_copy_contact(&copy_req);
                return;
            }
        }
    }
    srv_phb_multi_op_done(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_multi_move_delete_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_multi_move_delete_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        handle->finish_count++;
    }
    else
    {
        handle->id_array[handle->active_index - 1] = handle->id_array[handle->fail_count];
        handle->id_array[handle->fail_count++] = handle->id;
    }
    srv_phb_update_multi_op_status(handle);
    
    if (!g_srv_phb_op_cntx.stop_op_flag &&
        !(handle->is_stoped) &&
        !(handle->is_canceled) &&
        (handle->active_index < handle->total_count) &&
        srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage))
    {
        handle->id = handle->id_array[handle->active_index++];

        if (srv_phb_datamgr_check_store_index(handle->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            srv_phb_datamgr_copy_req_struct copy_req;
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            if (handle->dest_storage != PHB_STORAGE_TCARD || srv_phb_tcard_is_ready() == MMI_TRUE)
            #endif
            {
                copy_req.id = handle->id;
                copy_req.storage = handle->dest_storage;
                copy_req.cb = srv_phb_multi_move_add_cb;
                copy_req.user_data = handle;
                srv_phb_datamgr_copy_contact(&copy_req);
                return;
            }
        }
    }
    srv_phb_multi_op_done(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_multi_move_add_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_multi_move_add_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        srv_phb_datamgr_delete_req_struct delete_req;

        delete_req.id = handle->id;
        delete_req.cb = srv_phb_multi_move_delete_cb;
        delete_req.user_data = handle;
        srv_phb_datamgr_delete_contact(&delete_req);
        return;
    }
    srv_phb_move_all_delete_cb(result, id, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_multi_delete_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_multi_delete_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        handle->finish_count++;
    }
    else
    {
        handle->id_array[handle->active_index - 1] = handle->id_array[handle->fail_count];
        handle->id_array[handle->fail_count++] = handle->id;
    }
    srv_phb_update_multi_op_status(handle);
    
    if (!g_srv_phb_op_cntx.stop_op_flag &&
        !(handle->is_stoped) &&
        !(handle->is_canceled) &&
        (handle->active_index < handle->total_count))
    {
        handle->id = handle->id_array[handle->active_index++];

        if (srv_phb_datamgr_check_store_index(handle->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            srv_phb_datamgr_delete_req_struct delete_req;
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            if (handle->dest_storage != PHB_STORAGE_TCARD || srv_phb_tcard_is_ready() == MMI_TRUE)
            #endif
            {
                delete_req.id = handle->id;
                delete_req.cb = srv_phb_multi_delete_cb;
                delete_req.user_data = handle;
                srv_phb_datamgr_delete_contact(&delete_req);
                return;
            }
        }
    }
    srv_phb_multi_op_done(handle);
}


#ifdef __MMI_MULTI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_backup_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_backup_cb(kal_int32 error_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_code  == VCARD_NO_ERROR)
    {
        handle->finish_count++;
    }
    else if (error_code == FS_DISK_FULL)
    {
        handle->is_stoped = MMI_TRUE;
    }
    else
    {
        handle->fail_count++;
    }
    srv_phb_update_multi_op_status(handle);
    
    if (!g_srv_phb_op_cntx.stop_op_flag &&
        !(handle->is_stoped) &&
        !(handle->is_canceled) && 
        srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        /* jump to next index if this contact has been copied */
        if (srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX, handle->active_index) == handle->id)
        {
            handle->active_index++;
        }
        handle->active_index = 
            srv_phb_op_get_index_by_storage(handle->active_index, handle->src_storage, &(handle->id));

        if (handle->id != SRV_PHB_INVALID_INDEX)
        {
            srv_phb_read_contact(handle->id, NULL, handle->contact);
            srv_phb_contact_to_vcard_object(handle->contact, handle->vcard_object);
            vcard_multi_build(handle->b_handle, handle->vcard_object, srv_phb_backup_cb, handle);
            return;
        }
    }
    handle->result = error_code;
    srv_phb_multi_op_done(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_all_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_restore_add_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        handle->finish_count++;
    }
    else
    {
        handle->fail_count++;
    }
    srv_phb_update_multi_op_status(handle);
    
    if (!g_srv_phb_op_cntx.stop_op_flag &&
        !(handle->is_stoped) &&
        !(handle->is_canceled) &&
        srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage))
    {
        vcard_multi_parse(handle->p_handle, srv_phb_restore_parse_cb, handle);
        return;
    }
    srv_phb_multi_op_done(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_backup_cb
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_restore_parse_cb(kal_int32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle = user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (percentage <= 100 && error_code == VCARD_NO_ERROR)
    {
        if (!g_srv_phb_op_cntx.stop_op_flag &&
            !(handle->is_stoped) &&
            !(handle->is_canceled) &&
            (srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage)))
        {
            srv_phb_datamgr_add_req_struct add_req;

            if (srv_phb_vcard_is_valid_contact(object))
            {
                handle->contact = srv_phb_vcard_object_to_contact(handle->contact, object);
                add_req.storage = handle->dest_storage;
                add_req.record_index = SRV_PHB_INVALID_INDEX;
                add_req.contact = handle->contact;
                add_req.cb = srv_phb_restore_add_cb;
                add_req.user_data = handle;
                add_req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
                srv_phb_datamgr_add_contact(&add_req);
    
                if (percentage == 100)
                {
                    handle->is_stoped = MMI_TRUE;
                }
            }
            else
            {
                handle->fail_count++;
                srv_phb_update_multi_op_status(handle);
                
                if (percentage == 100)
                {
                    handle->is_stoped = MMI_TRUE;
                    if (handle->finish_count == 0)
                    {
                        error_code = SRV_PHB_VCARD_INVALID;
                    }
                    srv_phb_restore_parse_cb(error_code, percentage, NULL, user_data);
                }
                else
                {
                    vcard_multi_parse(handle->p_handle, srv_phb_restore_parse_cb, handle);
                }
            }
            return;
        }
    }
    handle->result = error_code;
    srv_phb_multi_op_done(handle);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_next_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_phb_query_item_struct* srv_phb_query_get_item(srv_phb_query_struct* handle, U16 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_node_struct* temp;
    U16 i = item_index / SRV_PHB_QUERY_ITEM_COUNT;
    U16 index = item_index % SRV_PHB_QUERY_ITEM_COUNT;
    srv_phb_query_mem_entry_struct *mem_entry_p = &(handle->mem_entry);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_GET_ITEM, handle, item_index, handle->malloc_count, handle->total_item);
    if (i == handle->malloc_count)
    {
        if (mem_entry_p && mem_entry_p->mem_alloc_func && mem_entry_p->mem_free_func)
        {
            // asm memory
            temp = mem_entry_p->mem_alloc_func(sizeof(srv_phb_query_node_struct), mem_entry_p->user_data);
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_ASM_ALLOC, temp, sizeof(srv_phb_query_node_struct), mem_entry_p->user_data, mem_entry_p->mem_alloc_func);
        }
        else
        {
            temp = srv_phb_mem_malloc(sizeof(srv_phb_query_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_ADM_ALLOC, temp, sizeof(srv_phb_query_node_struct));

        }
        temp->next = NULL;
        if (handle->head)
        {
            handle->tail->next = temp;
            handle->tail = temp;
        }
        else
        {
            handle->head = temp;
            handle->tail = temp;
            handle->tail->next = NULL;
        }
        handle->malloc_count++;
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_ALLOC_NUMBER, handle->malloc_count);
    }
    else if (i < handle->malloc_count)
    {
        temp = handle->head;
        while (i--)
        {
            temp = temp->next;
            ASSERT(temp);
        }
    }
    else
    {
        return NULL;
    }
    return &(temp->item[index]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_next_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_phb_query_num_item_struct* srv_phb_query_get_num_item(srv_phb_query_struct* handle, U16 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_num_node_struct* temp;
    U16 i = item_index / SRV_PHB_QUERY_ITEM_COUNT;
    U16 index = item_index % SRV_PHB_QUERY_ITEM_COUNT;
    srv_phb_query_mem_entry_struct *mem_entry_p = &(handle->mem_entry);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i == handle->number_malloc)
    {
        if (mem_entry_p && mem_entry_p->mem_alloc_func && mem_entry_p->mem_free_func)
        {
            // asm memory
            temp = mem_entry_p->mem_alloc_func(sizeof(srv_phb_query_num_node_struct), mem_entry_p->user_data);
        }
        else
        {
            temp = srv_phb_mem_malloc(sizeof(srv_phb_query_num_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        temp->next = NULL;
        if (handle->num_head)
        {
            handle->num_tail->next = temp;
            handle->num_tail = temp;
        }
        else
        {
            handle->num_head = temp;
            handle->num_tail = temp;
            handle->num_tail->next = NULL;
        }
        handle->number_malloc++;
    }
    else if (i < handle->number_malloc)
    {
        temp = handle->num_head;
        while (i--)
        {
            temp = temp->next;
            ASSERT(temp);
        }
    }
    else
    {
        return NULL;
    }
    return &(temp->item[index]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_query_get_pid()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ++g_srv_phb_query_async_cntx_p->max_pid;

    if (g_srv_phb_query_async_cntx_p->max_pid >= SRV_PHB_QUERY_MAX_PID)
    {
        g_srv_phb_query_async_cntx_p->max_pid = 1; // reset pid
    }
    return g_srv_phb_query_async_cntx_p->max_pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_insert_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_query_insert_pid(U32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_query_async_cntx_p->queue[g_srv_phb_query_async_cntx_p->rear++] = pid;

    return g_srv_phb_query_async_cntx_p->rear;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_remove_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_query_remove_pid(U32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    U32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(srv_phb_query_search_pid(pid));

    for (i = g_srv_phb_query_async_cntx_p->front; i < g_srv_phb_query_async_cntx_p->rear; i++)
    {
        if (g_srv_phb_query_async_cntx_p->queue[i] == pid)
        {
            break;
        }
    }

    for (j = i; j < (g_srv_phb_query_async_cntx_p->rear - 1); j++)
    {
        g_srv_phb_query_async_cntx_p->queue[j] = g_srv_phb_query_async_cntx_p->queue[j + 1];
    }

    g_srv_phb_query_async_cntx_p->rear--;

    if (0 == g_srv_phb_query_async_cntx_p->rear)
    {
      //  srv_phb_query_async_init(); // reset pid
    }
 
    return g_srv_phb_query_async_cntx_p->rear;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_search_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_query_search_pid(U32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    U32 i = 0;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = g_srv_phb_query_async_cntx_p->front; i < g_srv_phb_query_async_cntx_p->rear; i++)
    {
        if (g_srv_phb_query_async_cntx_p->queue[i] == pid)
        {
            ret = MMI_TRUE;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_async_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_query_async_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_query_async_cntx_p = &g_srv_phb_query_async_cntx;
    memset(g_srv_phb_query_async_cntx_p, 0x0, sizeof(srv_phb_query_async_op_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_phb_query_handle srv_phb_query_init(srv_phb_query_req_struct* req, srv_phb_query_struct* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_contact_filter_struct *filter = (srv_phb_contact_filter_struct *) req->filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!handle)
    {
        handle = srv_phb_mem_malloc(sizeof(srv_phb_query_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(handle, 0, sizeof(srv_phb_query_struct));

        // query async
        if (filter && filter->query_async_cntx.callback_func)
        {
            handle->pid = srv_phb_query_get_pid();
            ret = srv_phb_query_insert_pid(handle->pid);
        }
        memcpy(&(handle->mem_entry), &(filter->mem_entry), sizeof(srv_phb_query_mem_entry_struct));
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_QUERY_INIT, handle->pid, ret);
    }
    else
    {
        handle->contact_item = 0;
        handle->total_item = 0;
        handle->number_item = 0;
    #ifdef __MMI_DIALER_SEARCH__
        handle->clog_item = 0;
    #endif
        handle->gen_table = MMI_FALSE;
        // asm
        //memset(&(handle->mem_entry), 0x0, sizeof(srv_phb_query_mem_entry_struct));
        memcpy(&(handle->mem_entry), &(filter->mem_entry), sizeof(srv_phb_query_mem_entry_struct));
        // query async
        handle->match_field = 0; // begin with name(0)
        if (filter && filter->query_async_cntx.callback_func)
        {
            if (srv_phb_query_search_pid(handle->pid))
            {
                ret = srv_phb_query_remove_pid(handle->pid);
            }
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_QUERY_RESET, handle->pid, ret, filter->query_async_cntx.query_index, filter->query_async_cntx.start_index);
            ret = -1;
            filter->query_async_cntx.query_index = filter->query_async_cntx.start_index;  // reset query index
            handle->pid = srv_phb_query_get_pid();
            ret = srv_phb_query_insert_pid(handle->pid);
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_QUERY_RESET_EX, handle->pid, ret);
        }
    }
    srv_phb_init_contact_filter_cache(req->filter);

    return handle;
}


/***************************************************************************** 
* Global Function
*****************************************************************************/
    
#define SRV_PHB_ASYNC_OP

/*****************************************************************************
 * FUNCTION
 *  srv_phb_stop_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void srv_phb_stop_op(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_op_cntx.stop_op_flag = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_op_flag
 * DESCRIPTION
 *  get stop op flag
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
MMI_BOOL srv_phb_get_op_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_op_cntx.stop_op_flag;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_stop_async_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_stop_async_op(srv_phb_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_handle_struct* cntx = (srv_phb_op_handle_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx)
    {
        cntx->is_stoped = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_free_handle
 * DESCRIPTION
 *  free op handle. Notice: AP need free each handle once and only once
 * PARAMETERS
 *  handle    : [IN]  op handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_free_handle(srv_phb_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_handle_struct* cntx = (srv_phb_op_handle_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx)
    {
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_FREE_HANDLE, cntx->is_canceled);
        if (cntx->is_canceled)
        {
            srv_phb_mem_free(cntx);
        }
        else
        {
            cntx->is_canceled = MMI_TRUE;
            #ifdef __VCARD_CLOUD_SUPPORT__
            srv_phb_cloud_op_done();
            #endif
        }
    }
}


/* add op */

/*****************************************************************************
 * FUNCTION
 *  srv_phb_add_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_handle srv_phb_add_contact(srv_phb_add_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_single_handle(
                        SRV_PHB_OP_CB_TYPE_ADD,
                        req->user_data,
                        req->cb,
                        req->record_index,
                        req->contact);
    
    if (!srv_phb_startup_is_phb_ready())
    {
        handle->result = SRV_PHB_NOT_READY;
    }
    else if (g_srv_phb_op_cntx.multi_op_flag)
    {
        handle->result = SRV_PHB_DATAMGR_BUSY;
    }
    else
    {
        handle->result = srv_phb_check_stoage_accessible(req->storage);
        if (handle->result == SRV_PHB_NO_ERROR)
        {
            handle->result = srv_phb_check_storage_condition(req->storage, SRV_PHB_CHECK_STORAGE_FULL);
        }
        if (handle->result == SRV_PHB_NO_ERROR &&
            (req->record_index != MMI_PHB_INVALID_CONTACT_ID) &&
            (req->record_index > srv_phb_datamgr_total_contacts(req->storage)))
        {
            handle->result = SRV_PHB_OUT_OF_INDEX;
        }
    }
    if (handle->result == SRV_PHB_NO_ERROR)
    {
        srv_phb_datamgr_add_req_struct add_req;
        add_req.mode = req->mode;
        add_req.storage = req->storage;
        add_req.record_index = req->record_index;
        add_req.contact = handle->contact;
        add_req.cb = srv_phb_single_op_done;
        add_req.user_data = handle;
        srv_phb_datamgr_add_contact(&add_req);
    }
    else
    {
        srv_phb_async_event_interface(srv_phb_single_op_fail, handle);
    }
    return handle;
}


/* update op */
/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_handle srv_phb_update_contact(srv_phb_update_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_single_handle(
                        SRV_PHB_OP_CB_TYPE_UPD,
                        req->user_data,
                        req->cb,
                        req->id,
                        req->contact);
    
    if (!srv_phb_startup_is_phb_ready())
    {
        handle->result = SRV_PHB_NOT_READY;
    }
    else if (g_srv_phb_op_cntx.multi_op_flag)
    {
        handle->result = SRV_PHB_DATAMGR_BUSY;
    }
    else
    {
        if (srv_phb_datamgr_check_store_index(req->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            handle->result = srv_phb_check_stoage_accessible(srv_phb_get_storage(req->id));
        }
        else
        {
            handle->result = SRV_PHB_NOT_FOUND;
        }
    }
    if (handle->result == SRV_PHB_NO_ERROR)
    {
        srv_phb_datamgr_update_req_struct update_req;
        update_req.id = req->id;
        update_req.mode = req->mode;
        update_req.update_field = req->update_field;
        update_req.contact = handle->contact;
        update_req.cb = srv_phb_single_op_done;
        update_req.user_data = handle;
        srv_phb_datamgr_update_contact(&update_req);
    }
    else
    {
        srv_phb_async_event_interface(srv_phb_single_op_fail, handle);
    }
    return handle;
}


/* delete op */
/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_handle srv_phb_delete_contact(srv_phb_delete_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_single_handle(
                        SRV_PHB_OP_CB_TYPE_DEL,
                        req->user_data,
                        req->cb,
                        req->id,
                        NULL);
    
    if (!srv_phb_startup_is_phb_ready())
    {
        handle->result = SRV_PHB_NOT_READY;
    }
    else if (g_srv_phb_op_cntx.multi_op_flag)
    {
        handle->result = SRV_PHB_DATAMGR_BUSY;
    }
    else
    {
        if (srv_phb_datamgr_check_store_index(req->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            handle->result = srv_phb_check_stoage_accessible(srv_phb_get_storage(req->id));
        }
        else
        {
            handle->result = SRV_PHB_NOT_FOUND;
        }
    }
    if (handle->result == SRV_PHB_NO_ERROR)
    {
        srv_phb_datamgr_delete_req_struct delete_req;
        delete_req.id = req->id;
        delete_req.cb = srv_phb_single_op_done;
        delete_req.user_data = handle;
        srv_phb_datamgr_delete_contact(&delete_req);
    }
    else
    {
        srv_phb_async_event_interface(srv_phb_single_op_fail, handle);
    }
    return handle;
}


/* copy op */
/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_handle srv_phb_copy_contact(srv_phb_copy_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_single_handle(
                        SRV_PHB_OP_CB_TYPE_COPY,
                        req->user_data,
                        req->cb,
                        req->id,
                        NULL);
    
    if (!srv_phb_startup_is_phb_ready())
    {
        handle->result = SRV_PHB_NOT_READY;
    }
    else if (g_srv_phb_op_cntx.multi_op_flag)
    {
        handle->result = SRV_PHB_DATAMGR_BUSY;
    }
    else
    {
        if (srv_phb_datamgr_check_store_index(req->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            handle->result = srv_phb_check_stoage_accessible(req->dest_storage);
            if (handle->result == SRV_PHB_NO_ERROR)
            {
                handle->result = srv_phb_check_storage_condition(req->dest_storage, SRV_PHB_CHECK_STORAGE_FULL);
            }
        }
        else
        {
            handle->result = SRV_PHB_NOT_FOUND;
        }
    }
    if (handle->result == SRV_PHB_NO_ERROR)
    {
        srv_phb_datamgr_copy_req_struct copy_req;
        copy_req.id = req->id;
        copy_req.storage = req->dest_storage;
        copy_req.cb = srv_phb_single_op_done;
        copy_req.user_data = handle;
        srv_phb_datamgr_copy_contact(&copy_req);
    }
    else
    {
        srv_phb_async_event_interface(srv_phb_single_op_fail, handle);
    }
    return handle;
}


/* move op */
/*****************************************************************************
 * FUNCTION
 *  srv_phb_move_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_handle srv_phb_move_contact(srv_phb_move_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_single_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_single_handle(
                        SRV_PHB_OP_CB_TYPE_MOVE,
                        req->user_data,
                        req->cb,
                        req->id,
                        NULL);
    
    if (!srv_phb_startup_is_phb_ready())
    {
        handle->result = SRV_PHB_NOT_READY;
    }
    else if (g_srv_phb_op_cntx.multi_op_flag)
    {
        handle->result = SRV_PHB_DATAMGR_BUSY;
    }
    else
    {
        if (srv_phb_datamgr_check_store_index(req->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            handle->result = srv_phb_check_stoage_accessible(req->dest_storage);
            if (handle->result == SRV_PHB_NO_ERROR)
            {
                handle->result = srv_phb_check_storage_condition(req->dest_storage, SRV_PHB_CHECK_STORAGE_FULL);
            }
        }
        else
        {
            handle->result = SRV_PHB_NOT_FOUND;
        }
    }
    if (handle->result == SRV_PHB_NO_ERROR)
    {
        srv_phb_datamgr_copy_req_struct copy_req;
        g_srv_phb_op_cntx.stop_op_flag = MMI_FALSE;
        copy_req.id = req->id;
        copy_req.storage = req->dest_storage;
        copy_req.cb = srv_phb_move_op_cb;
        copy_req.user_data = handle;
        srv_phb_datamgr_copy_contact(&copy_req);
    }
    else
    {
        srv_phb_async_event_interface(srv_phb_single_op_fail, handle);
    }
    return handle;
}


/* copy all op */
/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_all_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_handle srv_phb_copy_all_contact(srv_phb_copy_all_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_multi_handle(
                        SRV_PHB_OP_CB_TYPE_COPY_ALL,
                        req->cb,
                        req->user_data,
                        NULL,
                        req->src_storage,
                        req->dest_storage,
                        srv_phb_datamgr_used_contacts(req->src_storage));
    
    if (!g_srv_phb_op_cntx.multi_op_flag &&
        srv_phb_startup_is_phb_ready() &&
        (srv_phb_check_stoage_accessible(req->dest_storage) == SRV_PHB_NO_ERROR) &&
        (srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage)) &&
        handle->total_count)
    {
        handle->active_index = 
            srv_phb_op_get_index_by_storage(handle->active_index, handle->src_storage, &(handle->id));
        if (handle->id != MMI_PHB_INVALID_CONTACT_ID)
        {
            srv_phb_datamgr_copy_req_struct copy_req;
            srv_phb_set_multi_op_flag();
            copy_req.id = handle->id;
            copy_req.storage = req->dest_storage;
            copy_req.cb = srv_phb_copy_all_cb;
            copy_req.user_data = handle;
            srv_phb_datamgr_copy_contact(&copy_req);
            return handle;
        }
    }
    srv_phb_async_event_interface(srv_phb_multi_op_done, handle);
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_move_all_contact
 * DESCRIPTION
 *  move contacts by storage
 * PARAMETERS
 *  req    : [IN]  move all req
 * RETURNS
 *  srv_phb_handle
 *****************************************************************************/
srv_phb_handle srv_phb_move_all_contact(srv_phb_move_all_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_multi_handle(
                        SRV_PHB_OP_CB_TYPE_MOVE_ALL,
                        req->cb,
                        req->user_data,
                        NULL,
                        req->src_storage,
                        req->dest_storage,
                        srv_phb_datamgr_used_contacts(req->src_storage));
    
    if (!g_srv_phb_op_cntx.multi_op_flag &&
        srv_phb_startup_is_phb_ready() &&
        (srv_phb_check_stoage_accessible(req->dest_storage) == SRV_PHB_NO_ERROR) &&
        (srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage)) &&
        handle->total_count)
    {
        handle->active_index = 
            srv_phb_op_get_index_by_storage(handle->active_index, handle->src_storage, &(handle->id));
        if (handle->id != MMI_PHB_INVALID_CONTACT_ID)
        {
            srv_phb_datamgr_copy_req_struct copy_req;
            srv_phb_set_multi_op_flag();
            copy_req.id = handle->id;
            copy_req.storage = req->dest_storage;
            copy_req.cb = srv_phb_move_all_add_cb;
            copy_req.user_data = handle;
            srv_phb_datamgr_copy_contact(&copy_req);
            return handle;
        }
    }
    srv_phb_async_event_interface(srv_phb_multi_op_done, handle);
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_all_contact
 * DESCRIPTION
 *  delete contacts by storage
 * PARAMETERS
 *  req    : [IN]  delete all req
 * RETURNS
 *  srv_phb_handle
 *****************************************************************************/
srv_phb_handle srv_phb_delete_all_contact(srv_phb_delete_all_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_multi_handle(
                        SRV_PHB_OP_CB_TYPE_DELETE_ALL,
                        req->cb,
                        req->user_data,
                        NULL,
                        req->storage,
                        0,
                        srv_phb_datamgr_used_contacts(req->storage));
    
    if (!g_srv_phb_op_cntx.multi_op_flag &&
        srv_phb_startup_is_phb_ready() &&
        (srv_phb_check_stoage_accessible(req->storage) == SRV_PHB_NO_ERROR) &&
        handle->total_count)
    {
        handle->active_index = 
            srv_phb_op_get_index_by_storage(handle->active_index, handle->src_storage, &(handle->id));
        if (handle->id != MMI_PHB_INVALID_CONTACT_ID)
        {
            srv_phb_datamgr_delete_req_struct delete_req;
            srv_phb_set_multi_op_flag();
            delete_req.id = handle->id;
            delete_req.cb = srv_phb_delete_all_cb;
            delete_req.user_data = handle;
            srv_phb_datamgr_delete_contact(&delete_req);
            return handle;
        }
    }
    srv_phb_async_event_interface(srv_phb_multi_op_done, handle);
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_multi_copy_contact
 * DESCRIPTION
 *  copy several contact
 * PARAMETERS
 *  req    : [IN]  multi copy req
 * RETURNS
 *  srv_phb_handle
 *****************************************************************************/
srv_phb_handle srv_phb_multi_copy_contact(srv_phb_multi_copy_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_multi_handle(
                        SRV_PHB_OP_CB_TYPE_MULTI_COPY,
                        req->cb,
                        req->user_data,
                        req->id_array,
                        0,
                        req->dest_storage,
                        req->contact_count);
    
    if (!g_srv_phb_op_cntx.multi_op_flag &&
        srv_phb_startup_is_phb_ready() &&
        (srv_phb_check_stoage_accessible(req->dest_storage) == SRV_PHB_NO_ERROR) &&
        (srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage)) &&
        handle->total_count)
    {
        handle->id = handle->id_array[handle->active_index++];
        if (srv_phb_datamgr_check_store_index(handle->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            srv_phb_datamgr_copy_req_struct copy_req;
            srv_phb_set_multi_op_flag();
            copy_req.id = handle->id;
            copy_req.storage = req->dest_storage;
            copy_req.cb = srv_phb_multi_copy_cb;
            copy_req.user_data = handle;
            srv_phb_datamgr_copy_contact(&copy_req);
            return handle;
        }
    }
    srv_phb_async_event_interface(srv_phb_multi_op_done, handle);
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_multi_move_contact
 * DESCRIPTION
 *  move several contact
 * PARAMETERS
 *  req    : [IN]  multi move req
 * RETURNS
 *  srv_phb_handle
 *****************************************************************************/
srv_phb_handle srv_phb_multi_move_contact(srv_phb_multi_move_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_multi_handle(
                        SRV_PHB_OP_CB_TYPE_MULTI_MOVE,
                        req->cb,
                        req->user_data,
                        req->id_array,
                        0,
                        req->dest_storage,
                        req->contact_count);
    
    if (!g_srv_phb_op_cntx.multi_op_flag &&
        srv_phb_startup_is_phb_ready() &&
        (srv_phb_check_stoage_accessible(req->dest_storage) == SRV_PHB_NO_ERROR) &&
        (srv_phb_datamgr_used_contacts(handle->dest_storage) != srv_phb_datamgr_total_contacts(handle->dest_storage)) &&
        handle->total_count)
    {
        handle->id = handle->id_array[handle->active_index++];
        if (srv_phb_datamgr_check_store_index(handle->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            srv_phb_datamgr_copy_req_struct copy_req;
            srv_phb_set_multi_op_flag();
            copy_req.id = handle->id;
            copy_req.storage = req->dest_storage;
            copy_req.cb = srv_phb_multi_move_add_cb;
            copy_req.user_data = handle;
            srv_phb_datamgr_copy_contact(&copy_req);
            return handle;
        }
    }
    srv_phb_async_event_interface(srv_phb_multi_op_done, handle);
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_multi_delete_contact
 * DESCRIPTION
 *  delete several contact
 * PARAMETERS
 *  req    : [IN]  multi delete req
 * RETURNS
 *  srv_phb_handle
 *****************************************************************************/
srv_phb_handle srv_phb_multi_delete_contact(srv_phb_multi_delete_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_multi_handle(
                        SRV_PHB_OP_CB_TYPE_MULTI_DELETE,
                        req->cb,
                        req->user_data,
                        req->id_array,
                        0,
                        0,
                        req->contact_count);
    
    if (!g_srv_phb_op_cntx.multi_op_flag && srv_phb_startup_is_phb_ready() && handle->total_count)
    {
        handle->id = handle->id_array[handle->active_index++];
        if (srv_phb_datamgr_check_store_index(handle->id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            srv_phb_datamgr_delete_req_struct delete_req;
            srv_phb_set_multi_op_flag();
            delete_req.id = handle->id;
            delete_req.cb = srv_phb_multi_delete_cb;
            delete_req.user_data = handle;
            srv_phb_datamgr_delete_contact(&delete_req);
            return handle;
        }
    }
    srv_phb_async_event_interface(srv_phb_multi_op_done, handle);
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_contact srv_phb_read_contact(mmi_phb_contact_id id, srv_phb_field_filter filter, srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_startup_is_phb_ready())
    {
        if (srv_phb_datamgr_check_store_index(id, MMI_PHB_CONTACT_FIELD_ALL))
        {
            if (contact)
            {
                srv_phb_reset_contact(contact, MMI_PHB_CONTACT_FIELD_ALL);
            }
            else
            {
                contact = srv_phb_create_contact(NULL);
            }
            srv_phb_datamgr_read_contact(id, contact, filter);
        }
    }
    return contact;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_backup_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_handle srv_phb_backup_contact(srv_phb_backup_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_multi_handle(
                        SRV_PHB_OP_CB_TYPE_BACKUP,
                        req->cb,
                        req->user_data,
                        NULL,
                        req->storage,
                        0,
                        srv_phb_datamgr_used_contacts(req->storage));
    
#ifdef __MMI_MULTI_VCARD__
    if (!g_srv_phb_op_cntx.multi_op_flag && handle->total_count)
    {
        handle->active_index = 
            srv_phb_op_get_index_by_storage(handle->active_index, handle->src_storage, &(handle->id));
        if (handle->id != MMI_PHB_INVALID_CONTACT_ID)
        {
            S32 error_code;
            srv_phb_set_multi_op_flag();
        #ifdef __VCARD_CLOUD_SUPPORT__
            if (req->mode == SRV_PHB_BACKUP_RESTORE_MODE_CLOUD)
            {
                if (srv_phb_cloud_backup(handle, req->provider,req->account, req->malloc_func, req->free_func) >= 0)
                {
                    return handle;
                }
            }
            else
        #endif /* __VCARD_CLOUD_SUPPORT__ */
            {
                handle->b_handle = vcard_open_builder(req->path, VCARD_OPEN_MODE_HIDDEN, &error_code);
                if (handle->b_handle)
                {
                    handle->contact = srv_phb_read_contact(handle->id, NULL, NULL);
                    handle->vcard_object = srv_phb_mem_malloc(sizeof(vcard_object_struct), SRV_PHB_MEMORY_TYPE_ADM);
                    srv_phb_contact_to_vcard_object(handle->contact, handle->vcard_object);
                    vcard_multi_build(handle->b_handle, handle->vcard_object, srv_phb_backup_cb, handle);
                    return handle;
                }
            }
        }
    }
#ifdef __VCARD_CLOUD_SUPPORT__
    if (handle->total_count == 0)
    {
        handle->result = SRV_PHB_CLOUD_NO_NEED_SYNC;
    }
#endif /* __VCARD_CLOUD_SUPPORT__ */
#endif /* __MMI_MULTI_VCARD__ */

    srv_phb_async_event_interface(srv_phb_multi_op_done, handle);
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_restore_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_handle srv_phb_restore_contact(srv_phb_restore_req_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct* handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    
    handle = srv_phb_create_multi_handle(
                        SRV_PHB_OP_CB_TYPE_RESTORE,
                        req->cb,
                        req->user_data,
                        NULL,
                        0,
                        PHB_STORAGE_NVRAM,
                        0);
    
#ifdef __MMI_MULTI_VCARD__
    if (!g_srv_phb_op_cntx.multi_op_flag &&
        (srv_phb_check_storage_status(handle->dest_storage) != SRV_PHB_STORAGE_STATUS_FULL)
        )
    {
        S32 error_code;
        srv_phb_set_multi_op_flag();
    #ifdef __VCARD_CLOUD_SUPPORT__
        if (req->mode == SRV_PHB_BACKUP_RESTORE_MODE_CLOUD)
        {
            if (srv_phb_cloud_restore(handle, req->provider, req->account, req->malloc_func, req->free_func) >= 0)
            {
                return handle;
            }
        }
        else
    #endif /* __VCARD_CLOUD_SUPPORT__ */
        {
            handle->p_handle = vcard_open_parser(req->path, VCARD_PROPERTY_ALL, &error_code);
            if (handle->p_handle)
            {
                vcard_multi_parse(handle->p_handle, srv_phb_restore_parse_cb, handle);
                return handle;
            }
        }
    }
#endif /* __MMI_MULTI_VCARD__ */
    srv_phb_async_event_interface(srv_phb_multi_op_done, handle);
    return handle;
}


#define SRV_PHB_QUERY_HANDLE

/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_add_match_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_query_add_match_item(
                    srv_phb_query_handle handle,
                    mmi_phb_contact_id id,
                    mmi_phb_contact_field_id_enum align_field,
                    U8 save_index,
                    srv_phb_query_match_info_struct* match_info,
                    MMI_BOOL item_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle)
    {
        srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;
        if (item_order && match_info && match_info->matched_field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
        {
            srv_phb_query_num_item_struct* item = srv_phb_query_get_num_item(query_handle, query_handle->number_item++);
            item->id = id;
            item->save_index = save_index;
            if (match_info)
            {
                memcpy(&(query_handle->match_info), match_info, sizeof(srv_phb_query_match_info_struct));
            }
        }
        else
        {
            srv_phb_query_item_struct* item = srv_phb_query_get_item(query_handle, query_handle->contact_item++);
            item->id = id;
            item->align_field = align_field;
            item->save_index = save_index;
            if (match_info)
            {
                memcpy(&(item->match_info), match_info, sizeof(srv_phb_query_match_info_struct));
            }
            else
            {
                memset(&(item->match_info), 0, sizeof(srv_phb_query_match_info_struct));
            }
        }
        query_handle->total_item++;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


#ifdef __MMI_DIALER_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_add_match_clg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_query_add_match_clg(srv_phb_query_handle handle, SRV_CLOG_ID clog_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle)
    {
        srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;
        if (!(query_handle->clog_id))
        {
            query_handle->clog_id = srv_phb_mem_malloc(SRV_CLOG_LOG_MAX_NUM * sizeof(SRV_CLOG_ID), SRV_PHB_MEMORY_TYPE_ADM);
        }
        query_handle->clog_id[query_handle->clog_item++] = clog_id;
        query_handle->total_item++;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_query_get_clog_count(srv_phb_query_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_QUERY_GET_CLOG_COUNT, query_handle->clog_item);
        return query_handle->clog_item;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_clog_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
SRV_CLOG_ID srv_phb_query_get_clog_id(srv_phb_query_handle handle, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
        if (index < query_handle->clog_item)
        {
            return query_handle->clog_id[index];
        }
    }
    return 0;
}
#endif /* __MMI_DIALER_SEARCH__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_query_handle srv_phb_query(srv_phb_query_req_struct* req, srv_phb_query_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct *filter = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_QUERY_START, handle);
    if (req && srv_phb_startup_is_phb_ready())
    {
        handle = srv_phb_query_init(req, (srv_phb_query_struct*)handle);
        filter = (srv_phb_contact_filter_struct *) req->filter;
        if (filter && filter->query_async_cntx.callback_func)
        {
            srv_phb_sse_start_async_query(req, handle);
        }
        else
        {
            srv_phb_sse_query(req, handle);
        }
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_QUERY_REQ, req->alpha_table, req->item_order, req->align_field, req->filter, handle);
        return handle;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_contact srv_phb_query_get_contact(srv_phb_query_handle handle, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
        mmi_phb_contact_id id = srv_phb_query_get_contact_id(handle, index);
        if (id != MMI_PHB_INVALID_CONTACT_ID)
        {
            query_handle->contact = srv_phb_read_contact(id, NULL, query_handle->contact);
            return query_handle->contact;
        }
    }
    return NULL;
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_query_get_count(srv_phb_query_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_QUERY_GET_COUNT, query_handle->total_item, query_handle->contact_item, query_handle->number_item);
        return query_handle->total_item;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_phb_contact_id srv_phb_query_get_contact_id(srv_phb_query_handle handle, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
    #ifdef __MMI_DIALER_SEARCH__
        if (index < query_handle->clog_item)
        {
            return MMI_PHB_INVALID_CONTACT_ID;
        }
        index -= query_handle->clog_item;
    #endif /* __MMI_DIALER_SEARCH__ */

        if (index < query_handle->contact_item)
        {
            srv_phb_query_item_struct* item = srv_phb_query_get_item(query_handle, index);
            return item->id;
        }
        else
        {
            index -= query_handle->contact_item;
        }
        if (index < query_handle->number_item)
        {
            srv_phb_query_num_item_struct* item = srv_phb_query_get_num_item(query_handle, index);
            return item->id;
        }
    }
    return MMI_PHB_INVALID_CONTACT_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_align_field_type
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
mmi_phb_contact_field_id_enum srv_phb_query_get_align_field_type(srv_phb_query_handle handle, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
    #ifdef __MMI_DIALER_SEARCH__
        if (index < query_handle->clog_item)
        {
            return MMI_PHB_CONTACT_FIELD_ID_NUMBER;
        }
        index -= query_handle->clog_item;
    #endif /* __MMI_DIALER_SEARCH__ */
        if (index < query_handle->contact_item)
        {
            srv_phb_query_item_struct* item = srv_phb_query_get_item(query_handle, index);
            return item->align_field;
        }
        else
        {
            index -= query_handle->contact_item;
        }
        if (index < query_handle->number_item)
        {
            return MMI_PHB_CONTACT_FIELD_ID_NUMBER;
        }
    }
    return MMI_PHB_CONTACT_FIELD_ID_NAME;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_align_field
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void* srv_phb_query_get_align_field(srv_phb_query_handle handle, U32 index, mmi_phb_contact_field_id_enum* field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
        srv_phb_field_filter filter;
        mmi_phb_contact_id id = MMI_PHB_INVALID_CONTACT_ID;
        U8 save_index = 0;
    #ifdef __MMI_DIALER_SEARCH__
        if (index < query_handle->clog_item)
        {
            srv_clog_log_struct log;
            srv_phb_number_struct* number;
            *field_type = MMI_PHB_CONTACT_FIELD_ID_NUMBER;
            srv_clog_get_log_by_id(
                0,
                query_handle->clog_id[index],
                SRV_CLOG_LOG_FIELD_CID,
                &log);
            number = srv_phb_contact_add_number(query_handle->contact, NULL);
            mmi_wcsncpy(number->number, log.data.call_log.cid, MMI_PHB_NUMBER_PLUS_LENGTH);
            return number;
        }
        index -= query_handle->clog_item;
    #endif /* __MMI_DIALER_SEARCH__ */
        if (index < query_handle->contact_item)
        {
            srv_phb_query_item_struct* item = srv_phb_query_get_item(query_handle, index);
            *field_type = item->align_field;
            id = item->id;
            save_index = item->save_index;
        }
        else
        {
            index -= query_handle->contact_item;
        }
        if (index < query_handle->number_item)
        {
            srv_phb_query_num_item_struct* item = srv_phb_query_get_num_item(query_handle, index);
            *field_type = MMI_PHB_CONTACT_FIELD_ID_NUMBER;
            id = item->id;
            save_index = item->save_index;
        }
        filter = srv_phb_create_field_filter_ext((1 << (*field_type + 1)));
        query_handle->contact = srv_phb_read_contact(id, filter, query_handle->contact);
        srv_phb_free_field_filter(filter);
        if (*field_type == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
        {
            return srv_phb_contact_get_number_by_save_index(query_handle->contact, save_index);
        }
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        else
        {
            return srv_phb_contact_get_email_by_save_index(query_handle->contact, save_index);
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_matched_info
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_query_match_info_struct* srv_phb_query_get_matched_info(srv_phb_query_handle handle, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
    #ifdef __MMI_DIALER_SEARCH__
        if (index < query_handle->clog_item)
        {
            return &(query_handle->match_info);
        }
        index -= query_handle->clog_item;
    #endif /* __MMI_DIALER_SEARCH__ */
        if (index < query_handle->contact_item)
        {
            srv_phb_query_item_struct* item = srv_phb_query_get_item(query_handle, index);
            return &(item->match_info);
        }
        else
        {
            index -= query_handle->contact_item;
        }
        if (index < query_handle->number_item)
        {
            return &(query_handle->match_info);
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_alpha_count
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_alpha_info_struct* srv_phb_query_get_alpha_count(srv_phb_query_handle handle, U16 alpha_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
       // if (!(query_handle->gen_table))
        {
            U32 i;
            U8 index = 0;
            U32 current_count = 0;
            mmi_phb_contact_id id;
            mmi_phb_contact_id last_id = MMI_PHB_INVALID_CONTACT_ID;
            memset(query_handle->alpha_table, 0, sizeof(query_handle->alpha_table));
            for (i = 0; i < query_handle->contact_item; i++)
            {
                id = srv_phb_query_get_contact_id(query_handle, i);
                if (id != MMI_PHB_INVALID_CONTACT_ID)
                {
                    if (id != last_id)
                    {
                        index = srv_phb_sse_gen_alpha_index(id);
                        last_id = id;
                    }
                    if (!index && (query_handle->alpha_table[index].count != current_count))
                    {
                        index = SRV_PHB_ALPHA_LIST_COUNT + 1;
                    }
                    if (!(query_handle->alpha_table[index].count))
                    {
                        query_handle->alpha_table[index].start_index = current_count;
                    }
                    query_handle->alpha_table[index].count++;
                    current_count++;
                }
            }
            query_handle->gen_table = MMI_TRUE;
        }
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_QUERY_GET_ALPHA_COUNT, alpha_index, query_handle->alpha_table[alpha_index].start_index, query_handle->alpha_table[alpha_index].count);
        return &(query_handle->alpha_table[alpha_index]);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_name
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_query_get_name(srv_phb_query_handle handle, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
    #ifdef __MMI_DIALER_SEARCH__
        if (index < query_handle->clog_item)
        {
            srv_clog_log_struct log;
            srv_clog_get_log_by_id(
                0,
                query_handle->clog_id[index],
                SRV_CLOG_LOG_FIELD_NAME,
                &log);
            if (!query_handle->contact)
            {
                query_handle->contact = srv_phb_create_contact(NULL);
            }
            return srv_phb_contact_set_name(query_handle->contact, log.data.call_log.name);
        }
        else
    #endif /* __MMI_DIALER_SEARCH__ */
        {
            mmi_phb_contact_id id = srv_phb_query_get_contact_id(handle, index);
            if (id != MMI_PHB_INVALID_CONTACT_ID)
            {
                srv_phb_field_filter filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_NAME);
                query_handle->contact = srv_phb_read_contact(id, filter, query_handle->contact);
                srv_phb_free_field_filter(filter);
                return srv_phb_contact_get_name(query_handle->contact);
            }
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_imgae
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_res_struct* srv_phb_query_get_imgae(srv_phb_query_handle handle, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
        mmi_phb_contact_id id = srv_phb_query_get_contact_id(handle, index);
        if (id != MMI_PHB_INVALID_CONTACT_ID)
        {
            srv_phb_field_filter filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_IMAGE);
            query_handle->contact = srv_phb_read_contact(id, filter, query_handle->contact);
            srv_phb_free_field_filter(filter);
            return srv_phb_contact_get_image(query_handle->contact);
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_number_struct* srv_phb_query_get_number(srv_phb_query_handle handle, U32 index, WCHAR *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
        srv_phb_field_filter filter;
        mmi_phb_contact_id id = MMI_PHB_INVALID_CONTACT_ID;
        U8 save_index = 0;
        if (!query_handle->contact)
        {
            query_handle->contact = srv_phb_create_contact(NULL);
        }
    #ifdef __MMI_DIALER_SEARCH__
        if (index < query_handle->clog_item)
        {
            srv_clog_log_struct log;
            srv_clog_get_log_by_id(
                0,
                query_handle->clog_id[index],
                SRV_CLOG_LOG_FIELD_CID,
                &log);
            mmi_wcsncpy(buf, log.data.call_log.cid, MMI_PHB_NUMBER_PLUS_LENGTH);
            return NULL;
        }
        index -= query_handle->clog_item;
    #endif /* __MMI_DIALER_SEARCH__ */

        if (index < query_handle->contact_item)
        {
            srv_phb_query_item_struct* item = srv_phb_query_get_item(query_handle, index);
            if (item->align_field != MMI_PHB_CONTACT_FIELD_ID_NUMBER)
            {
                return NULL;
            }
            id = item->id;
            save_index = item->save_index;
        }
        else
        {
            index -= query_handle->contact_item;
            if (index < query_handle->number_item)
            {
                srv_phb_query_num_item_struct* item = srv_phb_query_get_num_item(query_handle, index);
                id = item->id;
                save_index = item->save_index;
            }
        }
        if (id != MMI_PHB_INVALID_CONTACT_ID)
        {
        filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_NUMBER);
        query_handle->contact = srv_phb_read_contact(id, filter, query_handle->contact);
        srv_phb_free_field_filter(filter);
        return srv_phb_contact_get_number_by_save_index(query_handle->contact, save_index);
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_get_email
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_email_struct* srv_phb_query_get_email(srv_phb_query_handle handle, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
    #ifdef __MMI_DIALER_SEARCH__
        if (index < query_handle->clog_item)
        {
            return NULL;
        }
        index -= query_handle->clog_item;
    #endif /* __MMI_DIALER_SEARCH__ */
        if (index < query_handle->contact_item)
        {
            srv_phb_query_item_struct* item = srv_phb_query_get_item(query_handle, index);
            if (item->align_field != MMI_PHB_CONTACT_FIELD_ID_EMAIL)
            {
                srv_phb_field_filter filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_EMAIL);
                query_handle->contact = srv_phb_read_contact(item->id, filter, query_handle->contact);
                srv_phb_free_field_filter(filter);
                return srv_phb_contact_get_email_by_save_index(query_handle->contact, item->save_index);
            }
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_free_query_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_free_query_handle(srv_phb_query_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;
    srv_phb_query_mem_entry_struct *mem_entry_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (query_handle)
    {
        if (srv_phb_query_search_pid(query_handle->pid))
        {
            srv_phb_query_remove_pid(query_handle->pid);
        }
        mem_entry_p = &(query_handle->mem_entry);
        if (mem_entry_p && mem_entry_p->mem_alloc_func && mem_entry_p->mem_free_func)
        {
            srv_phb_free_link_ex((srv_phb_node_struct*)query_handle->head, (srv_phb_node_struct*)query_handle->tail, mem_entry_p);
            srv_phb_free_link_ex((srv_phb_node_struct*)query_handle->num_head, (srv_phb_node_struct*)query_handle->num_tail, mem_entry_p);
        }
        else
        {
            srv_phb_free_link((srv_phb_node_struct*)query_handle->head, (srv_phb_node_struct*)query_handle->tail);
            srv_phb_free_link((srv_phb_node_struct*)query_handle->num_head, (srv_phb_node_struct*)query_handle->num_tail);
        }
        if (query_handle->contact)
        {
            srv_phb_free_contact(query_handle->contact);
        }
    #ifdef __MMI_DIALER_SEARCH__
        if (query_handle->clog_id)
        {
            srv_phb_mem_free(query_handle->clog_id);
        }
    #endif /* __MMI_DIALER_SEARCH__ */
        srv_phb_mem_free(query_handle);
    }
}


#define PHB_OTHER_OP_SRV
#if defined(__MMI_VIDEO_TELEPHONY__)
/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_vt_call
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_set_vt_call(mmi_phb_contact_id id, MMI_BOOL is_vt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id < MMI_PHB_PHONE_ENTRIES)
    {
        srv_phb_set_phone_field_mask(id, MMI_PHB_CONTACT_FIELD_VT, is_vt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_vt_call
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_is_vt_call(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_datamgr_check_store_index(id, MMI_PHB_CONTACT_FIELD_VT);
}
#endif /* defined(__MMI_VIDEO_TELEPHONY__) */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_add_field_type
 * DESCRIPTION
 *  add a new field type
 * PARAMETERS
 *  type_info          :   [IN]    type info
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                 :           type id
 *  -1                  :           error
 *****************************************************************************/
S32 srv_phb_add_field_type(WCHAR* type_label, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_phone_add_type(type_label, field);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_field_type
 * DESCRIPTION
 *  delete a field type
 * PARAMETERS
 *  type_id            :   [IN]    type id
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_delete_field_type(U8 type_id, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    srv_phb_field_type_changed_ind_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_phone_delete_type(type_id, field);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_FIELD_TYPE_CHNAGED_IND);
    evt.field_type = field;
    evt.field_sub_type = type_id;
    evt.is_delete = MMI_TRUE;
    evt.result = result;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_type_list
 * DESCRIPTION
 *  get field type id list
 * PARAMETERS
 *  type_array         :   [OUT]   type id array
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           type count
 ****************************************************************************/
U8 srv_phb_get_field_type_list(U8* type_array, mmi_phb_contact_field_id_enum field, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == PHB_STORAGE_NVRAM
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        || storage == PHB_STORAGE_TCARD
        #endif
        )
    {
        return srv_phb_phone_get_type_list(type_array, field);
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        return srv_phb_sim_get_type_list(type_array, storage);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_field_type_label
 * DESCRIPTION
 *  get a field type label by id
 * PARAMETERS
 *  type_id            :   [IN]    type id
 *  field              :   [IN]    field
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
WCHAR* srv_phb_get_field_type_label(U8 type_id, mmi_phb_contact_field_id_enum field, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == PHB_STORAGE_NVRAM
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        || storage == PHB_STORAGE_TCARD
        #endif
        )
    {
        return srv_phb_phone_get_type_label(type_id, field);
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        return srv_phb_sim_get_type_label(type_id, storage);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_field_type
 * DESCRIPTION
 *  update a field type
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_update_field_type(U8 type_id, WCHAR* type_label, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_phone_update_type(type_id, type_label, field);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_max_field_type
 * DESCRIPTION
 *  get max field type
 * PARAMETERS
 *  type_id            :   [IN]    type id
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_phb_get_max_field_type(phb_storage_enum storage, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == PHB_STORAGE_NVRAM
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        || storage == PHB_STORAGE_TCARD
        #endif
        )
    {
        return srv_phb_phone_get_type_max(field);
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        return srv_phb_sim_get_type_max(storage);
    }
    return 0;
}

