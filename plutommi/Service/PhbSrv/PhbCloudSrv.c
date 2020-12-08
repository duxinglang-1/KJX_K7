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
 *  PhbCloudSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  for cloud backup & restore
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#ifdef __VCARD_CLOUD_SUPPORT__
#include "CloudSrvGprot.h"
#include "phbopsrv.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_srv_backup_restore_def.h"

/***************************************************************************** 
 * local defination 
 *****************************************************************************/

typedef struct
{
    srv_phb_multi_op_handle_struct *handle;
    U16 *entry_array;
    S32 cloud_handle;
    U32 provider;
    WCHAR path[30];
    U8  account_id;
    srv_cloud_op_enum op_type;
    MMI_BOOL cloud_operation;
    MMI_BOOL is_add;
} srv_phb_cloud_op_struct;

static srv_phb_cloud_op_struct g_srv_phb_cloud_op_cntx;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_set_option_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_cloud_set_option_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[SrvPhb] srv_phb_cloud_set_option_done--result: %d\n", result);

    if (result == SRV_CLD_SUCCESS)
    {
        U16 *entry_array = srv_phb_mem_malloc(MMI_PHB_PHONE_ENTRIES * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        S32 count;
        srv_phb_filter_struct filter;
        filter.storage = PHB_STORAGE_NVRAM;
        filter.field_filter = MMI_PHB_CONTACT_FIELD_ALL;
        filter.group_filter = NULL;
        filter.name_filter = NULL;
        filter.qsearch_filter = NULL;
        count = srv_phb_sse_build_contact_list(&filter, entry_array, MMI_PHB_PHONE_ENTRIES);
        srv_cloud_async_set_store_uid(entry_array, count, SRV_CLD_TYPE_VCARD, SRV_CLD_ACTION_ADD);
        g_srv_phb_cloud_op_cntx.entry_array = entry_array;
    }
    else
    {
        g_srv_phb_cloud_op_cntx.handle->result = SRV_PHB_CLOUD_ERROR;
        srv_phb_cloud_op_done();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_set_uid_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret srv_phb_cloud_set_uid_done(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_SET_UID_DONE, evt->evt_id, EVT_ID_SRV_CLD_CLOSE_DONE_IND);
    if (evt->evt_id == EVT_ID_SRV_CLD_ASYNC_UID_DONE_IND)
    {
        srv_cloud_post_async_done_evt_struct *event = (srv_cloud_post_async_done_evt_struct *)evt;
        if (event->type == SRV_CLD_TYPE_VCARD)
        {
            srv_cloud_op_struct op;
            if (g_srv_phb_cloud_op_cntx.entry_array != NULL)
            {
                srv_phb_mem_free(g_srv_phb_cloud_op_cntx.entry_array);
            }
            op.op_type = g_srv_phb_cloud_op_cntx.op_type;
            srv_cloud_operate(g_srv_phb_cloud_op_cntx.cloud_handle, &op);
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_vcard_build_uid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_cloud_vcard_build_uid(vcard_object_struct* vcard_object, CHAR *uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_wcs(vcard_object->uid.uid, uid);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_error_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret srv_phb_cloud_error_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_ERROR_HANDLER, evt->evt_id, EVT_ID_SRV_CLD_CLOSE_DONE_IND);
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CLD_ERROR_IND:
            {
                srv_cloud_error_evt_struct* result = (srv_cloud_error_evt_struct*)evt;
                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_ERROR_IND, result->type, result->error_type);
                if (result->type == SRV_CLD_TYPE_VCARD)
                {
                    S32 error;
                    srv_phb_cloud_op_done();
                    switch (result->error_type)
                    {
                        case SRV_CLD_NO_NEED_SYNC:
                            error = SRV_PHB_CLOUD_NO_NEED_SYNC;
                            break;
                        case SRV_CLD_NWK_ERROR:
                            error = SRV_PHB_CLOUD_NETWORK_ERROR;
                            break;
                        case SRV_CLD_DISK_FULL:
                            error = SRV_PHB_CLOUD_DISK_FULL;
                            break;
                        case SRV_CLD_NODATA:
                            error = SRV_PHB_CLOUD_NO_DATA;
                            break;
                        case SRV_CLD_FS_ERROR:
                            error = SRV_PHB_CLOUD_FS_ERROR;
                            break;
                        case SRV_CLD_GET_UID_ERROR:
                            error = SRV_PHB_CLOUD_UID_ERROR;
                            break;
                        case SRV_CLD_BUSY:
                            error = SRV_PHB_CLOUD_BUSY;
                            break;
                        case SRV_CLD_LOGOUT:
                            error = SRV_PHB_CLOUD_LOGOUT;
                            break;
                        case SRV_CLD_ACCT_ERROR:
                            error = SRV_PHB_CLOUD_ACCOUNT_ERROR;
                            break;
                        default:
                            error = SRV_PHB_CLOUD_ERROR;
                    }
                    g_srv_phb_cloud_op_cntx.handle->result = error;
                }
            }
            break;
        case EVT_ID_SRV_CLD_CLOSE_DONE_IND:
            {
                srv_cloud_post_close_done_struct* result = (srv_cloud_post_close_done_struct *)evt;

                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_CLOSE_DONE_IND, result->type, g_srv_phb_cloud_op_cntx.handle->result);
                if (result->type == SRV_CLD_TYPE_VCARD)
                {
                    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLD_CLOSE_DONE_IND, srv_phb_cloud_error_handler, NULL);
                    if (g_srv_phb_cloud_op_cntx.handle)
                    {
                        srv_phb_multi_op_done(g_srv_phb_cloud_op_cntx.handle);
                        g_srv_phb_cloud_op_cntx.handle = NULL;
                    }
                }
            }
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_contact_changed_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret srv_phb_cloud_contact_changed_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cloud_set_store_enum action = SRV_CLD_ACTION_TOTAL;
    srv_phb_op_evt_struct *event = (srv_phb_op_evt_struct *)evt;
    S32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[SrvPhb] srv_phb_cloud_contact_changed_handler(evt)--evt_id: %d, ADD_CONTACT: %d\n",
                    evt->evt_id, EVT_ID_PHB_ADD_CONTACT);

    switch (evt->evt_id)
    {
        case EVT_ID_PHB_ADD_CONTACT:
            action = SRV_CLD_ACTION_ADD;
            if (srv_cloud_add_real_time(SRV_CLD_TYPE_VCARD) == MMI_FALSE)
            {
                return MMI_RET_OK;
            }
            break;
        case EVT_ID_PHB_UPD_CONTACT:
            action = SRV_CLD_ACTION_UPDATE;
            break;
        case EVT_ID_PHB_DEL_CONTACT:
            action = SRV_CLD_ACTION_DEL;
            break;
    }
    ret = srv_cloud_sync_set_store_uid(
        event->id,
        NULL,
        SRV_CLD_TYPE_VCARD,
        action);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[SrvPhb] srv_phb_cloud_contact_changed_handler(ret)--ret: %d\n",
                    ret);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_add_contact_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_cloud_add_contact_cb(S32 result, mmi_phb_contact_id id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct *handle = (srv_phb_multi_op_handle_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        handle->finish_count ++;
    }
    else
    {
        handle->fail_count ++;
    }
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_ADD_CONTACT_CB, id, srv_phb_datamgr_get_field_mask(id),
                result, handle->finish_count, handle->fail_count);
    if (handle->p_handle)
    {
        vcard_close_parser(handle->p_handle);
    }
    srv_phb_update_multi_op_status(handle);
    
    if (srv_phb_get_op_flag()  == MMI_TRUE ||
        handle->is_stoped == MMI_TRUE ||
        handle->is_canceled == MMI_TRUE ||
        srv_phb_check_storage_status(handle->dest_storage) == SRV_PHB_STORAGE_STATUS_FULL)
    {
        srv_phb_cloud_op_done();
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_build_vcard_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_cloud_build_vcard_cb(S32 error_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct *handle = (srv_phb_multi_op_handle_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_op_flag() == MMI_FALSE &&
        handle->is_stoped == MMI_FALSE &&
        handle->is_canceled == MMI_FALSE)
    {
        if (handle->b_handle)
        {
            vcard_close_builder(handle->b_handle);
            handle->b_handle = NULL;
        }
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_BUILD_VCARD_CB, handle->id, srv_phb_datamgr_get_field_mask(handle->id),
                    g_srv_phb_cloud_op_cntx.cloud_handle);
        srv_cloud_put_data(
            g_srv_phb_cloud_op_cntx.cloud_handle,
            g_srv_phb_cloud_op_cntx.path,
            handle->id,
            sizeof(g_srv_phb_cloud_op_cntx.path));
        return;
    }
    srv_phb_cloud_op_done();
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_parse_vcard_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_cloud_parse_vcard_cb(kal_int32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_multi_op_handle_struct *handle = (srv_phb_multi_op_handle_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_op_flag() == MMI_FALSE &&
        handle->is_stoped == MMI_FALSE &&
        handle->is_canceled == MMI_FALSE)
    {
        if (srv_phb_vcard_is_valid_contact(object))
        {
            handle->contact = srv_phb_vcard_object_to_contact(handle->contact, object);
            if (handle->p_handle)
            {
                vcard_close_parser(handle->p_handle);
                handle->p_handle = NULL;
            }
            if (handle->id == SRV_PHB_INVALID_INDEX)
            {
                srv_phb_datamgr_add_req_struct add_req;
                add_req.storage = handle->dest_storage;
                add_req.record_index = SRV_PHB_INVALID_INDEX;
                add_req.contact = handle->contact;
                add_req.cb = srv_phb_cloud_add_contact_cb;
                add_req.user_data = handle;
                add_req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
                srv_phb_datamgr_add_contact(&add_req);
            }
            else
            {
                srv_phb_datamgr_update_req_struct upd_req;
                upd_req.id = handle->id;
                upd_req.contact = handle->contact;
                upd_req.update_field = MMI_PHB_CONTACT_FIELD_ALL;
                upd_req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
                upd_req.cb = srv_phb_cloud_add_contact_cb;
                upd_req.user_data = handle;
                srv_phb_datamgr_update_contact(&upd_req);
            }
        }
        else
        {
            if (handle->p_handle)
            {
                vcard_close_parser(handle->p_handle);
                handle->p_handle = NULL;
            }
            srv_cloud_sync_set_store_uid(
                SRV_CLOUD_INVALID_INDEX,
                NULL,
                SRV_CLD_TYPE_VCARD,
                SRV_CLD_ACTION_ADD
                );
        }
        return;
    }
    srv_phb_cloud_op_done();
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_build_vcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_cloud_build_vcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_phb_multi_op_handle_struct *handle = g_srv_phb_cloud_op_cntx.handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_op_flag() == MMI_FALSE &&
        handle->is_stoped == MMI_FALSE &&
        handle->is_canceled == MMI_FALSE)
    {
        do{
            if (srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX, handle->active_index) == handle->id)
            {
                handle->active_index++;
            }
            handle->active_index = srv_phb_op_get_index_by_storage(
                                       handle->active_index,
                                       handle->src_storage,
                                       &(handle->id));
        } while (handle->id != SRV_PHB_INVALID_INDEX && srv_cloud_backup_uid_check(handle->id,SRV_CLD_TYPE_VCARD) == MMI_FALSE);
        if (handle->id != SRV_PHB_INVALID_INDEX)
        {
            FS_Delete(g_srv_phb_cloud_op_cntx.path);
            handle->b_handle = vcard_open_builder(g_srv_phb_cloud_op_cntx.path, VCARD_OPEN_MODE_HIDDEN, &error_code);
            if (handle->b_handle)
            {
                srv_cloud_uid_struct uid;
                vcard_set_build_version(handle->b_handle, VCARD_VERSION_3_0);
                handle->contact = srv_phb_read_contact(handle->id, NULL, handle->contact);
                srv_phb_contact_to_vcard_object(handle->contact, handle->vcard_object);
                srv_cloud_sync_get_store_uid(handle->id, &uid, SRV_CLD_TYPE_VCARD);
                srv_phb_cloud_vcard_build_uid(handle->vcard_object, uid.id);
                vcard_multi_build(handle->b_handle, handle->vcard_object, srv_phb_cloud_build_vcard_cb, handle);
                return;
            }
        }
        srv_cloud_put_data_commit(g_srv_phb_cloud_op_cntx.cloud_handle);
    }
    srv_phb_cloud_op_done();
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_parse_vcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_cloud_parse_vcard(WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_phb_multi_op_handle_struct *handle = g_srv_phb_cloud_op_cntx.handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_op_flag() == MMI_FALSE &&
        handle->is_stoped == MMI_FALSE &&
        handle->is_canceled == MMI_FALSE)
    {
        handle->p_handle = vcard_open_parser(path, VCARD_PROPERTY_ALL, &error_code);
        if (handle->p_handle)
        {
            vcard_multi_parse(handle->p_handle, srv_phb_cloud_parse_vcard_cb, handle);
            return;
        }
    }
    srv_phb_cloud_op_done();
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_data_op_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret srv_phb_cloud_data_op_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_OP_HANDLER, evt->evt_id, EVT_ID_SRV_CLD_CLOSE_DONE_IND);
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CLD_BACKUP_BEGIN_IND:
            {
                srv_cloud_post_backup_begin_evt_struct *event = (srv_cloud_post_backup_begin_evt_struct *)evt;
                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_BACKUP_BEGIN_IND, event->type);
                if (event->type == SRV_CLD_TYPE_VCARD)
                {
                    srv_phb_cloud_build_vcard();
                }
            }
            break;
        case EVT_ID_SRV_CLD_PUT_DATA_RES_IND:
            {
                srv_phb_multi_op_handle_struct *handle = g_srv_phb_cloud_op_cntx.handle;
                srv_cloud_put_data_result_evt_struct *event = (srv_cloud_put_data_result_evt_struct *)evt;
                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_PUT_DATA_RES_IND, event->type, event->result);
                if (event->result == SRV_CLD_SUCCESS)
                {                    
                    handle->finish_count ++;
                    srv_phb_update_multi_op_status(handle);
                    srv_phb_cloud_build_vcard();
                }
                else
                {
                    handle->fail_count ++;
                    srv_phb_cloud_build_vcard();
                }
            }
            break;
        case EVT_ID_SRV_CLD_GET_DATA_IND:
            {
                srv_cloud_get_data_ind_evt_struct *event = (srv_cloud_get_data_ind_evt_struct *)evt;
                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_CLOUD_GET_DATA_IND, event->index, event->over_flag, event->type, event->is_add);
                if (event->over_flag == MMI_FALSE)
                {
                    U32 num, len;
                    WCHAR path[SRV_FMGR_PATH_MAX_LEN];
                    srv_cloud_get_data(
                        g_srv_phb_cloud_op_cntx.cloud_handle,
                        (U8*)path,
                        &num,
                        &len);
                    if (event->is_add)
                    {
                        g_srv_phb_cloud_op_cntx.handle->id = SRV_PHB_INVALID_INDEX;
                    }
                    else
                    {
                        g_srv_phb_cloud_op_cntx.handle->id = event->index;
                    }
                    srv_phb_cloud_parse_vcard(path);
                }
                else
                {
                    srv_phb_cloud_op_done();
                }
            }
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_cloud_prepare(U32 provider, U8 account_id, srv_cloud_mem_alloc malloc_func, srv_cloud_mem_free free_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = -1;
    S32 cloud_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_cloud_op_cntx.cloud_operation = MMI_TRUE;
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLD_ASYNC_UID_DONE_IND, srv_phb_cloud_set_uid_done, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLD_ERROR_IND, srv_phb_cloud_error_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLD_CLOSE_DONE_IND, srv_phb_cloud_error_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLD_BACKUP_BEGIN_IND, srv_phb_cloud_data_op_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLD_PUT_DATA_RES_IND, srv_phb_cloud_data_op_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLD_GET_DATA_IND, srv_phb_cloud_data_op_handler, NULL);
    cloud_handle = srv_cloud_create(SRV_CLD_TYPE_VCARD);
    if (cloud_handle >= 0)
    {
        srv_cloud_opt_struct opt;
        opt.acct.account_id = account_id;
        opt.acct.provider = provider;
        opt.data_type = SRV_CLD_DT_URI;
        opt.mem_alloc = malloc_func;
        opt.mem_free = free_func;
        opt.cb_func = srv_phb_cloud_set_option_done;
        result = srv_cloud_setopt(cloud_handle, &opt);
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[SrvPhb] srv_phb_cloud_prepare(setopt) result: %d\n", result);
        if (result == SRV_CLD_SUCCESS)
        {
            U16 *entry_array = srv_phb_mem_malloc(MMI_PHB_PHONE_ENTRIES * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
            S32 count;
            srv_phb_filter_struct filter;
            filter.storage = PHB_STORAGE_NVRAM;
            filter.field_filter = MMI_PHB_CONTACT_FIELD_ALL;
            filter.group_filter = NULL;
            filter.name_filter = NULL;
            filter.qsearch_filter = NULL;
            count = srv_phb_sse_build_contact_list(&filter, entry_array, MMI_PHB_PHONE_ENTRIES);
            srv_cloud_async_set_store_uid(entry_array, count, SRV_CLD_TYPE_VCARD, SRV_CLD_ACTION_ADD);
            g_srv_phb_cloud_op_cntx.entry_array = entry_array;
            return cloud_handle;
        }
        else if (result == SRV_CLD_WOULDBLOCK)
        {
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[SrvPhb] srv_phb_cloud_prepare(WOULDBLOCK) cloud_handle: %d\n", cloud_handle);

            return cloud_handle;
        }
        else
        {
            g_srv_phb_cloud_op_cntx.cloud_handle = cloud_handle;
            srv_phb_cloud_op_done();
        }
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_backup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_cloud_backup(srv_phb_multi_op_handle_struct* handle, U32 provider, U8 account_id, srv_cloud_mem_alloc malloc_func, srv_cloud_mem_free free_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_cloud_op_cntx.op_type = SRV_CLD_OP_BACKUP;
    result = srv_phb_cloud_prepare(provider, account_id, malloc_func, free_func);
    if (result > 0)
    {
        handle->id = MMI_PHB_INVALID_CONTACT_ID;
        handle->active_index = 0;
        g_srv_phb_cloud_op_cntx.cloud_handle = result;
        g_srv_phb_cloud_op_cntx.handle = handle;
        kal_wsprintf(g_srv_phb_cloud_op_cntx.path, "%c:\\~phb_cloud_backup.vcf", SRV_FMGR_PUBLIC_DRV);
        handle->vcard_object = srv_phb_mem_malloc(sizeof(vcard_object_struct), SRV_PHB_MEMORY_TYPE_ADM);
    }
    else
    {
        if (result == SRV_CLD_NO_STORAGE)
        {
            result = SRV_PHB_CLOUD_NO_STORAGE;
        }
        else
        {
            result = SRV_PHB_CLOUD_ERROR;
        }
        handle->result = result;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_restore
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_cloud_restore(srv_phb_multi_op_handle_struct* handle, U32 provider, U8 account_id, srv_cloud_mem_alloc malloc_func, srv_cloud_mem_free free_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_cloud_op_cntx.op_type = SRV_CLD_OP_RESTORE;
    result = srv_phb_cloud_prepare(provider, account_id, malloc_func, free_func);
    if (result > 0)
    {
        g_srv_phb_cloud_op_cntx.cloud_handle = result;
        g_srv_phb_cloud_op_cntx.handle = handle;
    }
    else
    {
        if (result == SRV_CLD_NO_STORAGE)
        {
            result = SRV_PHB_CLOUD_NO_STORAGE;
        }
        else
        {
            result = SRV_PHB_CLOUD_ERROR;
        }
        handle->result = result;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_op_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_cloud_op_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_cloud_op_cntx.cloud_operation == MMI_TRUE)
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_CLD_ASYNC_UID_DONE_IND, srv_phb_cloud_set_uid_done, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_CLD_ERROR_IND, srv_phb_cloud_error_handler, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_CLD_BACKUP_BEGIN_IND, srv_phb_cloud_data_op_handler, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_CLD_PUT_DATA_RES_IND, srv_phb_cloud_data_op_handler, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_CLD_GET_DATA_IND, srv_phb_cloud_data_op_handler, NULL);
        g_srv_phb_cloud_op_cntx.cloud_operation = MMI_FALSE;
        if (g_srv_phb_cloud_op_cntx.cloud_handle != 0)
        {
            srv_cloud_close(g_srv_phb_cloud_op_cntx.cloud_handle);
            g_srv_phb_cloud_op_cntx.cloud_handle = 0;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_cloud_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_cb_reg_event(EVT_ID_PHB_ADD_CONTACT, srv_phb_cloud_contact_changed_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, srv_phb_cloud_contact_changed_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_DEL_CONTACT, srv_phb_cloud_contact_changed_handler, NULL);
}

#endif
