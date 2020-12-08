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
 * EmailSrvFolder.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email folder function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "EmailSrvFolder.h"
#include "MMIDataType.h"
#include "emailsrvgprot.h"
#include "kal_general_types.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorFs.h"
#include "EmailSrvStorage.h"
#include "DebugInitDef_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "Conversions.h"
#include "string.h"
#include "kal_public_api.h"
#include "customer_ps_inc.h"
#include "Unicodexdcl.h"

typedef struct
{
    U16 valid_number;
    srv_email_fldr_info_struct folder_array[SRV_EMAIL_FOLDER_HANDLE_MAX_NUMBER];
} srv_email_fldr_cntx_struct;

srv_email_fldr_cntx_struct g_srv_email_fldr_cntx;
srv_email_fldr_cntx_struct *srv_email_fldr_cntx_p;
U32 fldr_req_id = 1;

static srv_email_result_struct srv_email_fldr_result;

static srv_email_fldr_info_struct* srv_email_fldr_handle_to_addr(EMAIL_FLDR_HANDLE handle);
static srv_email_fldr_msg_info_node_struct* srv_email_fldr_msg_id_to_node(
                                                srv_email_fldr_info_struct *folder_object,
                                                EMAIL_MSG_ID msg_id);
static void srv_email_fldr_list_msg_job(void *user_data);
static void srv_email_fldr_list_msg_job_ext(void *user_data);
static void srv_email_fldr_set_msg_flag_job(void *user_data);
static void srv_email_fldr_delete_msg_job(void *user_data);
static void srv_email_fldr_insert_msg(
                srv_email_fldr_info_struct *folder_object,
                srv_email_fldr_msg_info_node_struct *position_node,
                MMI_BOOL insert_pre,
                srv_email_fldr_msg_info_node_struct *insert_node);
static void srv_email_fldr_insert_msg_in_order(
                srv_email_fldr_info_struct *folder_object,
                srv_email_fldr_msg_info_node_struct *insert_node);
static S32 srv_email_fldr_msg_node_compare(
            srv_email_fldr_info_struct *folder_object,
            srv_email_fldr_msg_info_node_struct *first,
            srv_email_fldr_msg_info_node_struct *second);
static srv_email_fldr_msg_info_node_struct *srv_email_fldr_delete_msg_node(
                                                srv_email_fldr_info_struct *folder_object,
                                                srv_email_fldr_msg_info_node_struct *delete_node,
                                                srv_email_mfree_funcptr_type mem_free);
static void srv_email_fldr_free_all_msg_node(srv_email_fldr_info_struct *folder_object);
static void srv_email_fldr_nwk_finish_callback(srv_email_nwk_finish_struct *data);
static MMI_BOOL srv_email_fldr_get_req_id(
                    srv_email_fldr_info_struct *folder_object,
                    S32 action,
                    void *operation_info,
                    EMAIL_REQ_ID *req_id_1,
                    EMAIL_REQ_ID *req_id_2);
static void srv_email_fldr_clear_req_id(srv_email_fldr_info_struct *folder_object, EMAIL_REQ_ID req_id);
static void srv_email_fldr_om_notify_callback(const srv_email_om_notify_struct *data);
static void srv_email_fldr_nwk_proc_func(srv_email_nwk_proc_struct *data);
static void srv_email_fldr_stack_qsort(
                srv_email_fldr_msg_info_node_struct *left_node,
                srv_email_fldr_msg_info_node_struct *right_node,
                srv_email_fldr_sort_msg_struct *sort_msg_p);
static void srv_email_fldr_qsort_msg(
                srv_email_fldr_info_struct *folder_object,
                srv_email_fldr_sort_msg_struct *sort_msg_p);
static srv_email_result_enum srv_email_fldr_qsort_msg_async(
                srv_email_fldr_info_struct *folder_object,
                srv_email_fldr_sort_msg_async_struct *sort_msg_async_p);
static srv_email_result_enum srv_email_fldr_stack_qsort_async(
                srv_email_fldr_sort_msg_async_struct *sort_msg_async_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 notify_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_fldr_cntx_p = &g_srv_email_fldr_cntx;
    srv_email_om_set_notify(SRV_EMAIL_OM_NOTIFY_OBJ_FLDR, srv_email_fldr_om_notify_callback, &notify_id);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_create
 * DESCRIPTION
 *  This function is used to create a folder instance for the following operations.
 * PARAMETERS
 *  srv_handle          : [IN]  The service handle
 *  fldr_create_p       : [IN]  Information used for create folder handle
 *  fldr_handle         : [OUT] Used to store the folder instance handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_create(
                                EMAIL_SRV_HANDLE srv_handle,
                                srv_email_fldr_create_info_struct *fldr_create_p,
                                EMAIL_FLDR_HANDLE *fldr_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_stor_fldr_struct stor_fldr_info;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fldr_create_p == NULL ||
        fldr_handle == NULL ||
        fldr_create_p->acct_id == EMAIL_ACCT_INVALID_ID ||
        fldr_create_p->fldr_id == EMAIL_FLDR_INVALID_ID)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    for (i = 0; i < SRV_EMAIL_FOLDER_HANDLE_MAX_NUMBER; i++)
    {
        if (!srv_email_fldr_cntx_p->folder_array[i].in_use)
        {
            break;
        }
    }
    if (i == SRV_EMAIL_FOLDER_HANDLE_MAX_NUMBER)
    {
        return SRV_EMAIL_RESULT_CREATE_INSTANCE_FAIL;
    }

    folder_object = &srv_email_fldr_cntx_p->folder_array[i];

    folder_object->srv_handle = srv_handle;
    folder_object->acct_id = fldr_create_p->acct_id;
    folder_object->fldr_id= fldr_create_p->fldr_id;
    folder_object->sort_mode = fldr_create_p->sort_mode;
    folder_object->sort_order = fldr_create_p->sort_order;
    folder_object->list_field = fldr_create_p->list_field;

    srv_email_stor_fldr_get_by_id(fldr_create_p->acct_id, fldr_create_p->fldr_id, &stor_fldr_info);
    folder_object->fldr_type = stor_fldr_info.fldr_type;
    folder_object->msg_num = stor_fldr_info.total_count;
    folder_object->unread_msg_num = stor_fldr_info.unread_count;
    mmi_chset_convert(
        CHSET_UTF8,
        MMI_CHSET_UCS2,
        stor_fldr_info.fldr_name,
        (CHAR*)folder_object->name,
        (SRV_EMAIL_MAX_FOLDER_NAME_LEN + 1) * 2);
    folder_object->fldr_name_separator = stor_fldr_info.fldr_name_separator;
    folder_object->msg_list_header = NULL;
    folder_object->msg_list_tail = NULL;
    folder_object->callback = NULL;
    folder_object->user_data = NULL;
    folder_object->proc_callback = NULL;
    folder_object->proc_user_data = NULL;
    folder_object->in_use = MMI_TRUE;
    *fldr_handle = (EMAIL_FLDR_HANDLE)folder_object;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_CREATE,
        folder_object->acct_id,
        folder_object->fldr_id,
        folder_object->fldr_type,
        folder_object->msg_num,
        folder_object->unread_msg_num);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_create_by_type_info_struct
 * DESCRIPTION
 *  This function is used to create a folder instance by type for the following operations.
 * PARAMETERS
 *  srv_handle          : [IN]  The service handle
 *  fldr_create_p       : [IN]  Information used for create folder handle
 *  fldr_handle         : [OUT] Used to store the folder instance handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_create_by_type(
                                EMAIL_SRV_HANDLE srv_handle,
                                srv_email_fldr_create_by_type_info_struct *fldr_create_p,
                                EMAIL_FLDR_HANDLE *fldr_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_stor_fldr_struct stor_fldr_info;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fldr_handle == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    for (i = 0; i < SRV_EMAIL_FOLDER_HANDLE_MAX_NUMBER; i++)
    {
        if (!srv_email_fldr_cntx_p->folder_array[i].in_use)
        {
            break;
        }
    }
    if (i == SRV_EMAIL_FOLDER_HANDLE_MAX_NUMBER)
    {
        return SRV_EMAIL_RESULT_CREATE_INSTANCE_FAIL;
    }

    folder_object = &srv_email_fldr_cntx_p->folder_array[i];

    folder_object->srv_handle = srv_handle;
    folder_object->sort_mode = fldr_create_p->sort_mode;
    folder_object->sort_order = fldr_create_p->sort_order;
    folder_object->list_field = fldr_create_p->list_field;

    srv_email_stor_fldr_get_by_type(fldr_create_p->fldr_type, &stor_fldr_info);
    folder_object->acct_id = EMAIL_ACCT_INVALID_ID;
    folder_object->fldr_id = EMAIL_FLDR_INVALID_ID;
    folder_object->fldr_type = stor_fldr_info.fldr_type;
    folder_object->msg_num = stor_fldr_info.total_count;
    folder_object->unread_msg_num = stor_fldr_info.unread_count;
    mmi_chset_convert(
        CHSET_UTF8,
        MMI_CHSET_UCS2,
        stor_fldr_info.fldr_name,
        (CHAR*)folder_object->name,
        (SRV_EMAIL_MAX_FOLDER_NAME_LEN + 1) * 2);
    folder_object->fldr_name_separator = stor_fldr_info.fldr_name_separator;
    folder_object->msg_list_header = NULL;
    folder_object->msg_list_tail = NULL;
    folder_object->callback = NULL;
    folder_object->user_data = NULL;
    folder_object->proc_callback = NULL;
    folder_object->proc_user_data = NULL;
    folder_object->in_use = MMI_TRUE;
    *fldr_handle = (EMAIL_FLDR_HANDLE)folder_object;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_CREATE_BY_TYPE,
        folder_object->fldr_type,
        folder_object->msg_num,
        folder_object->unread_msg_num);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified folder instance.
 * PARAMETERS
 *  fldr_handle         : [IN] The folder handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_destroy(EMAIL_FLDR_HANDLE fldr_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_DESTROY,
        folder_object->acct_id,
        folder_object->fldr_id,
        folder_object->fldr_type,
        srv_email_fldr_cntx_p->valid_number);
    for (i = 0; i < SRV_EMAIL_FOLDER_REQ_MAX_NUMBER; i++)
    {
        if (folder_object->req_id_action_map_list[i].req_id != 0)
        {
            srv_email_fldr_abort(fldr_handle, folder_object->req_id_action_map_list[i].req_id);
        }
    }
    if (folder_object->nwk_handle != EMAIL_NWK_INVALID_HANDLE)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
    }
    srv_email_fldr_free_all_msg_node(folder_object);
    memset(folder_object, 0, sizeof(srv_email_fldr_info_struct));
    srv_email_fldr_cntx_p->valid_number--;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_regist_callback
 * DESCRIPTION
 *  This function is used to regist callback function for async operation.
 * PARAMETERS
 *  fldr_handle         : [IN] This callback is for witch folder object
 *  callback            : [IN] Callback function for async operation
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_regist_callback(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_funcptr_type callback,
                                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_REGITER_CALLBACK,
        folder_object->fldr_id,
        folder_object->fldr_type,
        MMI_FALSE);
    folder_object->callback = callback;
    folder_object->user_data = user_data;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_clear_callback
 * DESCRIPTION
 *  This function is used to clear callback function for async operation.
 * PARAMETERS
 *  fldr_handle         : [IN] Clear witch folder object's callback
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_clear_callback(EMAIL_FLDR_HANDLE fldr_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_CLEAR_CALLBACK,
        folder_object->fldr_id,
        folder_object->fldr_type,
        MMI_FALSE);
    folder_object->callback = NULL;
    folder_object->user_data = NULL;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_regist_proc_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_regist_proc_callback(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_nwk_proc_funcptr_type proc_callback,
                                void *proc_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_REGITER_CALLBACK,
        folder_object->fldr_id,
        folder_object->fldr_type,
        MMI_TRUE);
    folder_object->proc_callback = proc_callback;
    folder_object->proc_user_data = proc_user_data;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_clear_proc_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_clear_proc_callback(EMAIL_FLDR_HANDLE fldr_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_CLEAR_CALLBACK,
        folder_object->fldr_id,
        folder_object->fldr_type,
        MMI_TRUE);
    folder_object->proc_callback = NULL;
    folder_object->proc_user_data = NULL;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_regist_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_regist_notify(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_notify_func notify_func,
                                void *notify_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_REGITER_OM_NOTIFY,
        folder_object->fldr_id,
        folder_object->fldr_type);
    folder_object->notify_func = notify_func;
    folder_object->notify_user_data = notify_user_data;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_clear_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_clear_notify(EMAIL_FLDR_HANDLE fldr_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_CLEAR_OM_NOTIFY,
        folder_object->fldr_id,
        folder_object->fldr_type);
    folder_object->notify_func = NULL;
    folder_object->notify_user_data = NULL;
    return SRV_EMAIL_RESULT_SUCC;
}

// utility function, copy MSG to note
static void srv_email_fldr_copy_msg_from_stor_to_note(
    srv_email_fldr_msg_info_node_struct *msg_node,
    srv_email_stor_msg_list_header_struct *stor_msg_list_info)
{
    // succeed to get a new MSG from Storage
    msg_node->msg_id = stor_msg_list_info->msg_id;
    msg_node->server_size = stor_msg_list_info->server_size;
    msg_node->local_size = stor_msg_list_info->local_size;
    msg_node->has_attach = stor_msg_list_info->has_attach;
    msg_node->time = stor_msg_list_info->time;
    msg_node->flag = stor_msg_list_info->flag;
    msg_node->state = stor_msg_list_info->state;
    msg_node->priority = stor_msg_list_info->priority;
    memcpy(msg_node->buff, stor_msg_list_info->list_subj, (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2);
    msg_node->addr.disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
    // decode display name
    srv_email_string_decode(
        (WCHAR*)stor_msg_list_info->disp_name,
        msg_node->addr.disp_name,
        &msg_node->addr.disp_name_len,
        &msg_node->addr.disp_charset);
    // convert email address from ASCII to UCS2
    mmi_chset_convert(
        CHSET_UTF8,
        CHSET_UCS2,
        (CHAR*)stor_msg_list_info->email_addr,
        (CHAR*)msg_node->addr.email_addr,
        (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
}
    

/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_list_msg
 * DESCRIPTION
 *  This function is used to list the messages in this instance from storage.
 *  If sorting when listing message, it will take more time than just in order of storage.
 * PARAMETERS
 *  fldr_handle         : [IN]  The folder handle
 *  req_id              : [OUT] Used to store the async request id
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_list_msg(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_eamil_msg_text_type_enum text_type,
                                srv_email_msg_date_type_enum date_type,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *msg_node;
    srv_email_fldr_list_msg_job_struct *list_msg_job;
    srv_email_malloc_funcptr_type mem_alloc;
    srv_email_mfree_funcptr_type mem_free;
    srv_email_stor_msg_list_header_struct *stor_msg_list_info;
    srv_email_result_enum result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (folder_object->operation != SRV_EMAIL_FLDR_OPERATION_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    folder_object->text_type = text_type;
    folder_object->date_type = date_type;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG, folder_object->fldr_id, folder_object->fldr_type, folder_object->msg_num, text_type, date_type);

    if (folder_object->msg_num <= SRV_EMAIL_FOLDER_MAX_OPERATION_PER_JOB)
    {
        // since MSG number is not too large, do it in a loop synchronously
    result = srv_email_stor_fldr_list_msg_open(
                folder_object->fldr_type,
                folder_object->acct_id,
                folder_object->fldr_id,
                text_type, date_type, 0,
                &folder_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }

        mem_alloc = srv_email_get_malloc_funcptr(folder_object->srv_handle);
        mem_free = srv_email_get_mfree_funcptr(folder_object->srv_handle);
        stor_msg_list_info = (srv_email_stor_msg_list_header_struct*)get_ctrl_buffer(sizeof(srv_email_stor_msg_list_header_struct));
        memset(stor_msg_list_info, 0, sizeof(srv_email_stor_msg_list_header_struct));
        for (i = 0; i < folder_object->msg_num; i++)
        {
            msg_node = (srv_email_fldr_msg_info_node_struct*)(*mem_alloc)(sizeof(srv_email_fldr_msg_info_node_struct));
            if (msg_node == NULL)
            {
                // cannot allocate memory
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_MEMORY_FAIL, __LINE__);
                free_ctrl_buffer(stor_msg_list_info);
                srv_email_fldr_free_all_msg_node(folder_object);
                srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }
            memset(msg_node, 0, sizeof(srv_email_fldr_msg_info_node_struct));
            result = srv_email_stor_fldr_list_msg_next(folder_object->stor_handle, stor_msg_list_info);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                // fail to get a new MSG from storage
                srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                free_ctrl_buffer(stor_msg_list_info);
                mem_free(msg_node);
                if (result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
                {
                    folder_object->msg_num = i;
                    return SRV_EMAIL_RESULT_SUCC;
                }
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_STOR_FAIL, result, __LINE__);
                // for error case, free all notes
                srv_email_fldr_free_all_msg_node(folder_object);
                return result;
            }
            else
            {
                srv_email_fldr_copy_msg_from_stor_to_note(msg_node, stor_msg_list_info);
                srv_email_fldr_insert_msg_in_order(folder_object, msg_node);
            }
        }/* end of {for} loop */

        free_ctrl_buffer(stor_msg_list_info);
        srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
        folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_SUCC;
    }

    list_msg_job = (srv_email_fldr_list_msg_job_struct*)srv_email_mem_alloc(sizeof(srv_email_fldr_list_msg_job_struct));
    if (list_msg_job == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_MEMORY_FAIL, __LINE__);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if (!srv_email_fldr_get_req_id(
            folder_object,
            SRV_EMAIL_FLDR_OPERATION_LIST_MSG,
            list_msg_job,
            req_id,
            &list_msg_job->req_id))
    {
        srv_email_mem_free(list_msg_job);
        return SRV_EMAIL_RESULT_FAIL;
    }

    list_msg_job->canceled = MMI_FALSE;
    list_msg_job->folder_object = folder_object;
    list_msg_job->start_index = 0;
    srv_email_schdl_start_job(srv_email_fldr_list_msg_job, list_msg_job);
    folder_object->operation = SRV_EMAIL_FLDR_OPERATION_LIST_MSG;
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

// for Comsos, get all msg id in this folder, then get msg header by id
extern srv_email_result_enum srv_email_fldr_list_msg_ext(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_eamil_msg_text_type_enum text_type,
                                srv_email_msg_date_type_enum date_type,
                                EMAIL_REQ_ID *req_id)
{
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *msg_node = NULL;
    srv_email_fldr_msg_info_node_struct *curr_msg_node;
    srv_email_fldr_list_msg_job_struct_ext *list_msg_job;
    srv_email_malloc_funcptr_type mem_alloc;
    srv_email_stor_msg_list_header_struct *stor_msg_list_info;
    srv_email_result_enum result;
    EMAIL_MSG_ID *msg_id_list;
    U32 get_msg_id_count;
    U16 i;
    srv_email_fldr_sort_msg_struct *sort_msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (folder_object->operation != SRV_EMAIL_FLDR_OPERATION_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    if (folder_object->msg_num == 0)
    {
        folder_object->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
        return SRV_EMAIL_RESULT_SUCC;
    }
    msg_id_list = (EMAIL_MSG_ID*)srv_email_mem_alloc(folder_object->msg_num * sizeof(EMAIL_MSG_ID));
    if (msg_id_list == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    get_msg_id_count = folder_object->msg_num;

    // get all MSG id(s)
    result = srv_email_fldr_get_all_msg_id(
                folder_object->acct_id, folder_object->fldr_id,
                0, 0, &get_msg_id_count, msg_id_list);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_mem_free(msg_id_list);
        return result;
    }

    mem_alloc = srv_email_get_malloc_funcptr(folder_object->srv_handle);
    for (i = 0; i < folder_object->msg_num; i++)
    {
        msg_node = (srv_email_fldr_msg_info_node_struct*)
            mem_alloc(sizeof(srv_email_fldr_msg_info_node_struct));
        if (msg_node == NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_MEMORY_FAIL, __LINE__);
            srv_email_fldr_free_all_msg_node(folder_object);
            srv_email_mem_free(msg_id_list);
            return SRV_EMAIL_RESULT_NO_MEMORY;
        }
        memset(msg_node, 0, sizeof(srv_email_fldr_msg_info_node_struct));
        msg_node->msg_id = msg_id_list[i];
        msg_node->time = msg_id_list[i]; /* sort these ID(s) by id value */
        folder_object->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
        folder_object->sort_order = MMI_TRUE;
        srv_email_fldr_insert_msg_in_order(folder_object, msg_node);
    }
    srv_email_mem_free(msg_id_list);

    curr_msg_node = folder_object->msg_list_header;
    if (folder_object->msg_num <= SRV_EMAIL_FOLDER_MAX_OPERATION_PER_JOB)
    {
        result = srv_email_stor_fldr_list_msg_open(
                    folder_object->fldr_type,
                    folder_object->acct_id,
                    folder_object->fldr_id,
                    text_type, date_type, -1,
                    &folder_object->stor_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_fldr_free_all_msg_node(folder_object);
            return result;
        }
        folder_object->text_type = text_type;
        folder_object->date_type = date_type;

        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG, folder_object->fldr_id, folder_object->fldr_type, folder_object->msg_num, text_type, date_type);

        stor_msg_list_info = (srv_email_stor_msg_list_header_struct*)get_ctrl_buffer(sizeof(srv_email_stor_msg_list_header_struct));
        memset(stor_msg_list_info, 0, sizeof(srv_email_stor_msg_list_header_struct));
        for (i = 0; i < folder_object->msg_num; ++i)
        {
            stor_msg_list_info->msg_id = curr_msg_node->msg_id;
            result = srv_email_stor_fldr_list_msg_next(folder_object->stor_handle, stor_msg_list_info);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                free_ctrl_buffer(stor_msg_list_info);
                if (result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
                {
                    srv_email_fldr_sort_msg_struct *sort_msg_p;
                    sort_msg_p = (srv_email_fldr_sort_msg_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_sort_msg_struct));
                    sort_msg_p->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
                    sort_msg_p->sort_order = (MMI_BOOL)(folder_object->fldr_type == SRV_EMAIL_FLDR_TYPE_OUTBOX);
                    srv_email_fldr_qsort_msg(folder_object, sort_msg_p);
                    free_ctrl_buffer(sort_msg_p);
                    folder_object->msg_num = i;
                    folder_object->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
                    folder_object->sort_order = (MMI_BOOL)(folder_object->fldr_type == SRV_EMAIL_FLDR_TYPE_OUTBOX);
                    return SRV_EMAIL_RESULT_SUCC;
                }
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_STOR_FAIL, result, __LINE__);
                srv_email_fldr_free_all_msg_node(folder_object);
                return result;
            }

            srv_email_fldr_copy_msg_from_stor_to_note(curr_msg_node, stor_msg_list_info);
            curr_msg_node = curr_msg_node->next;
        }

        free_ctrl_buffer(stor_msg_list_info);

        sort_msg_p = (srv_email_fldr_sort_msg_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_sort_msg_struct));
        sort_msg_p->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
        sort_msg_p->sort_order = (MMI_BOOL)(folder_object->fldr_type == SRV_EMAIL_FLDR_TYPE_OUTBOX);;
        srv_email_fldr_qsort_msg(folder_object, sort_msg_p);
        free_ctrl_buffer(sort_msg_p);

        srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
        folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        folder_object->sort_order = (MMI_BOOL)(folder_object->fldr_type == SRV_EMAIL_FLDR_TYPE_OUTBOX);
        folder_object->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
        return SRV_EMAIL_RESULT_SUCC;
    }

    list_msg_job = (srv_email_fldr_list_msg_job_struct_ext*)srv_email_mem_alloc(sizeof(srv_email_fldr_list_msg_job_struct_ext));
    if (list_msg_job == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_MEMORY_FAIL, __LINE__);
        srv_email_fldr_free_all_msg_node(folder_object);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    if (!srv_email_fldr_get_req_id(
            folder_object,
            SRV_EMAIL_FLDR_OPERATION_LIST_MSG,
            list_msg_job,
            req_id,
            &list_msg_job->req_id))
    {
        srv_email_mem_free(list_msg_job);
        srv_email_fldr_free_all_msg_node(folder_object);
        return SRV_EMAIL_RESULT_FAIL;
    }
    list_msg_job->canceled = MMI_FALSE;
    list_msg_job->folder_object = folder_object;
    list_msg_job->curr_node = folder_object->msg_list_header;
    srv_email_schdl_start_job(srv_email_fldr_list_msg_job_ext, list_msg_job);
    folder_object->operation = SRV_EMAIL_FLDR_OPERATION_LIST_MSG;
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_msg_list
 * DESCRIPTION
 *  This function is used to get the message list from this instance.
 * PARAMETERS
 *  fldr_handle     : [IN] The folder handle
 *  get_msg_p       : [IN] The pointer point to the parameter structure
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_get_msg_list(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                U32 start_index,
                                U32 *msg_count,
                                srv_email_fldr_msg_info_struct *msg_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *msg_node;
    S32 count;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_count == NULL || msg_info_p == NULL || folder_object->msg_num <= start_index)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_GET_MSG_LIST, folder_object->msg_num, start_index, *msg_count);
    msg_node = folder_object->msg_list_header;
    for (i = 0; i < start_index; i++)
    {
        msg_node = msg_node->next;
    }

    MMI_ASSERT (msg_node != NULL);
        
    count = *msg_count;
    for (i = 0; i < count; i++)
    {
        msg_info_p[i].msg_id = msg_node->msg_id;

        MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(srv_email_msg_id_to_acct_id(msg_node->msg_id)));
        
        msg_info_p[i].server_size = msg_node->server_size;
        msg_info_p[i].local_size = msg_node->local_size;
        msg_info_p[i].has_attach = msg_node->has_attach;
        msg_info_p[i].time = msg_node->time;
        msg_info_p[i].state = msg_node->state;
        msg_info_p[i].priority = msg_node->priority;
        msg_info_p[i].flag = msg_node->flag;
        msg_info_p[i].marked = msg_node->marked;
        memcpy(&msg_info_p[i].addr, &msg_node->addr, sizeof(srv_email_addr_struct));
        memcpy(msg_info_p[i].buff, msg_node->buff, (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2);
        *msg_count = i + 1;
        if (msg_node->next == NULL)
        {
            break;
        }
        msg_node = msg_node->next;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_basic_info
 * DESCRIPTION
 *  This function is used to get the basic information of this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  basic_info_p    : [OUT] Used to store basic information of folder
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_get_basic_info(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_basic_info_struct *basic_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (basic_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    basic_info_p->acct_id = folder_object->acct_id;
    basic_info_p->fldr_id = folder_object->fldr_id;
    basic_info_p->sort_mode = folder_object->sort_mode;
    basic_info_p->sort_order = folder_object->sort_order;
    basic_info_p->list_field = folder_object->list_field;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_GET_BASIC_INFO,
        folder_object->acct_id,
        folder_object->fldr_id,
        folder_object->sort_mode,
        folder_object->sort_order,
        folder_object->list_field);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_name
 * DESCRIPTION
 *  This function is used to get name of this folder
 *  It is used for only IMAP4 remote folder or user define folder
 * PARAMETERS
 *  fldr_handle     : [IN] The folder handle
 *  buff_len        : [IN/OUT] Length of buffer for name
 *  name            : [OUT] Buffer for name
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_get_name(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                WCHAR *name,
                                U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (len >= SRV_EMAIL_MAX_FOLDER_NAME_LEN + 1)
    {
        mmi_wcsncpy(name, folder_object->name, SRV_EMAIL_MAX_FOLDER_NAME_LEN);
    }
    else
    {
        mmi_wcscpy(name, folder_object->name);
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_msg_num
 * DESCRIPTION
 *  This function is used to get the message number in this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  msg_num_type    : [IN]  All message, unread message or marked message.
 *  number          : [OUT] Used to store the number
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_get_msg_num(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_get_msg_num_type_enum msg_num_type,
                                S32 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *msg_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    switch (msg_num_type)
    {
    case SRV_EMAIL_FLDR_MSG:
        *number = folder_object->msg_num;
        break;
    case SRV_EMAIL_FLDR_MSG_UNREAD:
        *number = folder_object->unread_msg_num;
        break;
    case SRV_EMAIL_FLDR_MSG_MARKED:
        *number = folder_object->marked_msg_num;
        break;
    case SRV_EMAIL_FLDR_MSG_UNREAD_FROM_MARKED:
        *number = 0;
        for (msg_node = folder_object->msg_list_header; msg_node != NULL; msg_node = msg_node->next)
        {
            if (msg_node->marked && !(msg_node->flag & EMAIL_MSG_FLAG_SEEN))
            {
                *number += 1;
            }
        }
        break;
    default:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    //MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_GET_MSG_NUM, msg_num_type, *number);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_sort_msg
 * DESCRIPTION
 *  This function is used to sort the message in this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  sort_msg_p      : [IN]  The pointer point to the parameter structure
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_sort_msg(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_sort_msg_struct *sort_msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *temp_msg_node;
    srv_email_fldr_msg_info_node_struct *temp, *temp_next;
    srv_email_fldr_msg_info_node_struct **unread;
    srv_email_fldr_msg_info_node_struct **readed;
    U32 unread_stack;
    U32 read_stack;
    S32 index = 0;
    U32 flag=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sort_msg_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_SORT_MSG,
        folder_object->sort_mode,
        folder_object->sort_order,
        sort_msg_p->sort_mode,
        sort_msg_p->sort_order);
    if (folder_object->msg_num <= 1 ||
        (folder_object->sort_mode == sort_msg_p->sort_mode &&
         folder_object->sort_mode != SRV_EMAIL_FLDR_SORT_MSG_MODE_FLAG))
    {
        if (folder_object->sort_order != sort_msg_p->sort_order)
        {
            folder_object->sort_order = sort_msg_p->sort_order;
            folder_object->msg_list_tail = folder_object->msg_list_header;
            temp = folder_object->msg_list_header->next;
            folder_object->msg_list_header->next = NULL;
            while(temp != NULL)
            {
                temp_next = temp->next;
                folder_object->msg_list_header->pre = temp;
                temp->pre = NULL;
                temp->next = folder_object->msg_list_header;
                folder_object->msg_list_header = temp;
                temp = temp_next;
            }
            temp_msg_node = folder_object->msg_list_header;
            while (temp_msg_node != NULL)
            {
                if (temp_msg_node->msg_id == sort_msg_p->msg_id)
                {
                    sort_msg_p->msg_index = index;
                    return SRV_EMAIL_RESULT_SUCC;
                }
                index++;
                temp_msg_node = temp_msg_node->next;
            }
        }
        return SRV_EMAIL_RESULT_SUCC;
    }

    /* sort by flag */
    if (sort_msg_p->sort_mode == SRV_EMAIL_FLDR_SORT_MSG_MODE_FLAG)
    {
        if (folder_object->unread_msg_num == 0 || folder_object->unread_msg_num == folder_object->msg_num)
        {
            folder_object->sort_mode = sort_msg_p->sort_mode;
            folder_object->sort_order = sort_msg_p->sort_order;
            return SRV_EMAIL_RESULT_SUCC;
        }
        else
        {
            unread_stack = 0;
            read_stack = 0;
            unread = (srv_email_fldr_msg_info_node_struct**)srv_email_mem_alloc(sizeof(srv_email_fldr_msg_info_node_struct*) * folder_object->unread_msg_num);
            memset(unread, 0, sizeof(srv_email_fldr_msg_info_node_struct*) * folder_object->unread_msg_num);
            readed = (srv_email_fldr_msg_info_node_struct**)srv_email_mem_alloc(sizeof(srv_email_fldr_msg_info_node_struct*) * (folder_object->msg_num - folder_object->unread_msg_num));
            memset(readed, 0, sizeof(srv_email_fldr_msg_info_node_struct*) * (folder_object->msg_num - folder_object->unread_msg_num));
            temp_msg_node = folder_object->msg_list_header;
            while (temp_msg_node != NULL)
            {
                if (temp_msg_node->flag & EMAIL_MSG_FLAG_SEEN)
                {
                    readed[read_stack] = temp_msg_node;
                    read_stack++;
                    temp_msg_node = temp_msg_node->next;
                }
                else
                {
                    unread[unread_stack] = temp_msg_node;
                    unread_stack++;
                    temp_msg_node = temp_msg_node->next;
                }
            }
            read_stack = 0;
            unread_stack = 0;

            if (folder_object->sort_mode == SRV_EMAIL_FLDR_SORT_MSG_MODE_FLAG)
            {
                /* current sort mode is flag, just reserve the list */
                for (; read_stack < folder_object->msg_num - folder_object->unread_msg_num - 1; read_stack++)
                {
                    readed[read_stack]->pre = readed[read_stack + 1];
                    readed[read_stack + 1]->next = readed[read_stack];
                }
                for (; unread_stack < folder_object->unread_msg_num - 1; unread_stack++)
                {
                    unread[unread_stack]->pre = unread[unread_stack + 1];
                    unread[unread_stack + 1]->next = unread[unread_stack];
                }
                if (folder_object->sort_order == MMI_FALSE)
                {
                    unread[folder_object->unread_msg_num - 1]->pre = readed[0];
                    readed[0]->next = unread[folder_object->unread_msg_num - 1];

                    folder_object->msg_list_header =
                        readed[folder_object->msg_num - folder_object->unread_msg_num - 1];
                    folder_object->msg_list_header->pre = NULL;
                    folder_object->msg_list_tail = unread[0];
                    folder_object->msg_list_tail->next=NULL;
                }
                else
                {
                    readed[folder_object->msg_num - folder_object->unread_msg_num - 1]->pre = unread[0];
                    unread[0]->next = readed[folder_object->msg_num - folder_object->unread_msg_num - 1];

                    folder_object->msg_list_header = unread[folder_object->unread_msg_num - 1];
                    folder_object->msg_list_header->pre = NULL;
                    folder_object->msg_list_tail = readed[0];
                    folder_object->msg_list_tail->next=NULL;
                }
            }
            else
            {
                while (read_stack < (folder_object->msg_num - folder_object->unread_msg_num-1) ||
                       unread_stack < (folder_object->unread_msg_num-1) ||
                       flag == 0)
                {
                    if(unread_stack < (folder_object->unread_msg_num-1))
                    {
                        unread[unread_stack]->next = unread[unread_stack+1];
                        unread[unread_stack+1]->pre = unread[unread_stack];
                        unread_stack++;
                        continue;
                    }
                    if(unread_stack == (folder_object->unread_msg_num-1) && read_stack ==0 && flag == 0)
                    {
                        unread[unread_stack]->next = readed[read_stack];
                        readed[read_stack]->pre = unread[unread_stack];
                        flag = 1;
                        continue;
                    }
                    if(read_stack < (folder_object->msg_num - folder_object->unread_msg_num-1))
                    {
                        readed[read_stack]->next = readed[read_stack+1];
                        readed[read_stack+1]->pre = readed[read_stack];
                        read_stack++;
                        continue;
                    }
                }
                folder_object->msg_list_header = unread[0];
                folder_object->msg_list_header->pre = NULL;
                folder_object->msg_list_tail = readed[folder_object->msg_num - folder_object->unread_msg_num-1];
                folder_object->msg_list_tail->next=NULL;
            }
            folder_object->sort_mode = sort_msg_p->sort_mode;
            folder_object->sort_order = sort_msg_p->sort_order;
        }
        temp_msg_node = folder_object->msg_list_header;
        while (temp_msg_node != NULL)
        {
            if (temp_msg_node->msg_id == sort_msg_p->msg_id)
            {
                sort_msg_p->msg_index = index;
                srv_email_mem_free(unread);
                srv_email_mem_free(readed);
                return SRV_EMAIL_RESULT_SUCC;
            }
            index++;
            temp_msg_node = temp_msg_node->next;
        }
        sort_msg_p->msg_index = 0;
        srv_email_mem_free(unread);
        srv_email_mem_free(readed);
        return SRV_EMAIL_RESULT_SUCC;
    }
    
    folder_object->sort_mode = sort_msg_p->sort_mode;
    folder_object->sort_order = sort_msg_p->sort_order;

    // if sort_msg_p->sort_mode != SRV_EMAIL_FLDR_SORT_MSG_MODE_FLAG 
    srv_email_fldr_qsort_msg(folder_object, sort_msg_p);
    temp_msg_node = folder_object->msg_list_header;
    while (temp_msg_node != NULL)
    {
        if (temp_msg_node->msg_id == sort_msg_p->msg_id)
        {
            sort_msg_p->msg_index = index;
            return SRV_EMAIL_RESULT_SUCC;
        }
        index++;
        temp_msg_node = temp_msg_node->next;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_sort_msg_async
 * DESCRIPTION
 *  This function is used to sort the message in this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  sort_msg_async_p      : [IN]  The pointer point to the parameter structure
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_sort_msg_async(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_sort_msg_struct *sort_msg_p,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *temp_msg_node = NULL;
    srv_email_fldr_msg_info_node_struct *temp, *temp_next;
    srv_email_fldr_sort_msg_async_struct *sort_msg_async_p;
    S32 msg_num;
    S32 index = 0;
    U32 time_count=0;
    U32 mem_size_for_stack = 0;
    srv_email_result_enum ret=SRV_EMAIL_RESULT_SUCC;
    srv_email_fldr_msg_info_node_struct **unread;
    srv_email_fldr_msg_info_node_struct **readed;
    U32 unread_stack;
    U32 read_stack;
    U32 flag=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&time_count);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_SORT_MSG,
        folder_object->sort_mode,
        folder_object->sort_order,
        sort_msg_p->sort_mode,
        sort_msg_p->sort_order);
    if (folder_object->msg_num <= 1 ||
        folder_object->sort_mode == sort_msg_p->sort_mode)
    {
        if (folder_object->sort_order == sort_msg_p->sort_order)
        {    
            kal_get_time(&time_count);
            return SRV_EMAIL_RESULT_SUCC;
        }
        else
        {
            folder_object->sort_order = sort_msg_p->sort_order;
            folder_object->msg_list_tail = folder_object->msg_list_header;
            temp = folder_object->msg_list_header->next;
            folder_object->msg_list_header->next = NULL;
            while(temp != NULL)
            {
                temp_next = temp->next;
                folder_object->msg_list_header->pre = temp;
                temp->pre = NULL;
                temp->next = folder_object->msg_list_header;
                folder_object->msg_list_header = temp;
                temp = temp_next;
            }
            temp_msg_node = folder_object->msg_list_header;
            while (temp_msg_node != NULL)
            {
                if (temp_msg_node->msg_id == sort_msg_p->msg_id)
                {
                    sort_msg_p->msg_index = index;
                    break ;
                }
                index++;
                temp_msg_node = temp_msg_node->next;
            }
            return SRV_EMAIL_RESULT_SUCC;
        }
    }

    /* sort by flag */
    if (sort_msg_p->sort_mode == SRV_EMAIL_FLDR_SORT_MSG_MODE_FLAG)
    {
        folder_object->sort_mode = sort_msg_p->sort_mode;
        folder_object->sort_order = sort_msg_p->sort_order;
        if (folder_object->unread_msg_num == 0 || folder_object->unread_msg_num == folder_object->msg_num)
        {
            return SRV_EMAIL_RESULT_SUCC;
        }
        else
        {
            unread_stack = 0;
            read_stack = 0;
            unread = (srv_email_fldr_msg_info_node_struct**)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_node_struct*) * folder_object->unread_msg_num);
            memset(unread, 0, sizeof(srv_email_fldr_msg_info_node_struct*) * folder_object->unread_msg_num);
            readed = (srv_email_fldr_msg_info_node_struct**)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_node_struct*) * (folder_object->msg_num - folder_object->unread_msg_num));
            memset(readed, 0, sizeof(srv_email_fldr_msg_info_node_struct*) * (folder_object->msg_num - folder_object->unread_msg_num));
            temp_msg_node = folder_object->msg_list_header;
            while (temp_msg_node != NULL)
            {
                if (temp_msg_node->flag & EMAIL_MSG_FLAG_SEEN)
                {
                    readed[read_stack] = temp_msg_node;
                    read_stack++;
                    temp_msg_node = temp_msg_node->next;
                }
                else
                {
                    unread[unread_stack] = temp_msg_node;
                    unread_stack++;
                    temp_msg_node = temp_msg_node->next;
                }
            }
            temp_msg_node = folder_object->msg_list_header;
            read_stack = 0;
            unread_stack = 0;
            while (read_stack < (folder_object->msg_num - folder_object->unread_msg_num-1) 
                || unread_stack < (folder_object->unread_msg_num-1))
            {
                 if(unread_stack < (folder_object->unread_msg_num-1))
                 {
                     unread[unread_stack]->next = unread[unread_stack+1];
                     unread_stack++;
                     continue;
                 }
                 if(unread_stack == (folder_object->unread_msg_num-1) && read_stack ==0 && flag == 0)
                 {
                     unread[unread_stack]->next = readed[read_stack];
                     flag = 1;
                     continue;
                 }
                 if(read_stack < (folder_object->msg_num - folder_object->unread_msg_num-1))
                 {
                     readed[read_stack]->next = readed[read_stack+1];
                     read_stack++;
                     continue;
                 }
            }
            folder_object->msg_list_header = unread[0];            
        }
        temp_msg_node = folder_object->msg_list_header;
        while (temp_msg_node != NULL)
        {
            if (temp_msg_node->msg_id == sort_msg_p->msg_id)
            {
                sort_msg_p->msg_index = index;
                free_ctrl_buffer(unread);
                free_ctrl_buffer(readed);
                return SRV_EMAIL_RESULT_SUCC;
            }
            index++;
            temp_msg_node = temp_msg_node->next;
        }

    }

    
    folder_object->sort_mode = sort_msg_p->sort_mode;
    folder_object->sort_order = sort_msg_p->sort_order;

    sort_msg_async_p=(srv_email_fldr_sort_msg_async_struct*)srv_email_mem_alloc(sizeof(srv_email_fldr_sort_msg_async_struct));
    if (sort_msg_async_p == NULL)
    {
        //MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    memset(sort_msg_async_p, 0, sizeof(srv_email_fldr_sort_msg_async_struct));
    msg_num=folder_object->msg_num;
    //kal_prompt_trace(MOD_MMI, "stack_qsort_async in sync and %d need to sort",msg_num);
    mem_size_for_stack = sizeof(srv_email_fldr_msg_info_node_struct *)*msg_num ;
    sort_msg_async_p->mem_ptr=(srv_email_fldr_msg_info_node_struct **)srv_email_mem_alloc(mem_size_for_stack);
    if(sort_msg_async_p->mem_ptr==NULL)
    {
        //error notify
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memset(sort_msg_async_p->mem_ptr, 0, mem_size_for_stack);
    {
        sort_msg_async_p->sort_mode=sort_msg_p->sort_mode;
        sort_msg_async_p->sort_order=sort_msg_p->sort_order;
        sort_msg_async_p->msg_id=sort_msg_p->msg_id;
        sort_msg_async_p->msg_index=&sort_msg_p->msg_index;
        sort_msg_async_p->abort=MMI_FALSE;
        sort_msg_async_p->finished=MMI_TRUE;
        sort_msg_async_p->header_node=folder_object->msg_list_header;
        sort_msg_async_p->tail_node=folder_object->msg_list_tail;
        sort_msg_async_p->sub_sort_header_node=NULL;
        sort_msg_async_p->sub_sort_tail_node=NULL;
        sort_msg_async_p->pivot=folder_object->msg_list_header;
        sort_msg_async_p->stack_size = 0;
        sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++]=folder_object->msg_list_tail;
        sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++]=folder_object->msg_list_header;
        //sort_msg_async_p->stack_size=2;
        sort_msg_async_p->director=MMI_FALSE;
        sort_msg_async_p->folder_object=folder_object;
    }
    //get req_id
    if (!srv_email_fldr_get_req_id(
        folder_object,
        SRV_EMAIL_FLDR_OPERATION_SORT_MSG,
        sort_msg_async_p,
        req_id,
        &sort_msg_async_p->req_id))
    {
        srv_email_mem_free(sort_msg_async_p->mem_ptr);
        srv_email_mem_free(sort_msg_async_p);
        return SRV_EMAIL_RESULT_FAIL;
    }
    ret=srv_email_fldr_qsort_msg_async(folder_object,sort_msg_async_p);
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_mark_msg
 * DESCRIPTION
 *  This function is used to mark or unmark one message in this instance.
 *  The mark here is used for multiple selection.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  msg_id          : [IN]  The message id
 *  msrk_msg        : [IN]  mark or unmark
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_mark_msg(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                MMI_BOOL mark_all,
                                EMAIL_MSG_ID msg_id,
                                MMI_BOOL mark_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct *msg_info_p;
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_MARK_MSG,
        mark_all,
        msg_id,
        mark_msg,
        folder_object->marked_msg_num);
    if (mark_all)
    {
        msg_info_p = folder_object->msg_list_header;
        while (msg_info_p != NULL)
        {
            msg_info_p->marked = mark_msg;
            msg_info_p = msg_info_p->next;
        }
        if (mark_msg)
        {
            folder_object->marked_msg_num = folder_object->msg_num;
        }
        else
        {
            folder_object->marked_msg_num = 0;
        }
    }
    else
    {
        if (msg_id == EMAIL_MSG_INVALID_ID)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
            return SRV_EMAIL_RESULT_INVALID_PARAMETER;
        }
        msg_info_p  = srv_email_fldr_msg_id_to_node(folder_object, msg_id);
        if (msg_info_p == NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
            return SRV_EMAIL_RESULT_INVALID_PARAMETER;
        }
        msg_info_p->marked = mark_msg;
        if (mark_msg)
        {
            folder_object->marked_msg_num++;
        }
        else
        {
            folder_object->marked_msg_num--;
        }
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_set_msg_flag
 * DESCRIPTION
 *  This function is used to set the flag of the specified emails.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  set_state_p     : [IN]  The pointer point to the parameter structure
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_set_msg_flag(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_set_msg_flag_struct *set_flag_p,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct *msg_node;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_set_msg_flag_job_struct *set_msg_flag_info;
    srv_email_stor_fldr_struct stor_fldr_info;
    srv_email_result_enum result;
    S32 number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set_flag_p == NULL ||
        (!set_flag_p->set_all && !set_flag_p->set_all_marked && set_flag_p->msg_id == EMAIL_MSG_INVALID_ID))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_SET_MSG_FLAG,
        set_flag_p->set_all,
        set_flag_p->set_all_marked,
        set_flag_p->msg_id,
        set_flag_p->msg_flag,
        set_flag_p->flag_mask);
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (folder_object->operation != SRV_EMAIL_FLDR_OPERATION_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    result = srv_email_stor_fldr_set_msg_flag_open(
                folder_object->fldr_type,
                folder_object->acct_id,
                folder_object->fldr_id,
                set_flag_p->flag_mask,
                set_flag_p->msg_flag,
                &folder_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    if (set_flag_p->set_all || set_flag_p->set_all_marked)
    {
        if (set_flag_p->set_all)
        {
            number = folder_object->msg_num;
        }
        else
        {
            number = folder_object->marked_msg_num;
        }
        if (number > SRV_EMAIL_FOLDER_MAX_OPERATION_PER_JOB)
        {
            set_msg_flag_info = (srv_email_fldr_set_msg_flag_job_struct*)srv_email_mem_alloc(sizeof(srv_email_fldr_set_msg_flag_job_struct));
            if (set_msg_flag_info == NULL)
            {
                srv_email_stor_fldr_set_msg_flag_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }
            if (!srv_email_fldr_get_req_id(
                    folder_object,
                    SRV_EMAIL_FLDR_OPERATION_SET_MSG_FLAG,
                    set_msg_flag_info,
                    req_id,
                    &set_msg_flag_info->req_id))
            {
                srv_email_mem_free(set_msg_flag_info);
                srv_email_stor_fldr_set_msg_flag_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_FAIL;
            }
            set_msg_flag_info->canceled = MMI_FALSE;
            set_msg_flag_info->folder_object = folder_object;
            set_msg_flag_info->curr_node = folder_object->msg_list_header;
            set_msg_flag_info->marked = set_flag_p->set_all_marked;
            set_msg_flag_info->msg_flag = set_flag_p->msg_flag;
            set_msg_flag_info->flag_mask = set_flag_p->flag_mask;
            srv_email_schdl_start_job(srv_email_fldr_set_msg_flag_job, set_msg_flag_info);
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_SET_MSG_FLAG;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        msg_node = folder_object->msg_list_header;
        while (msg_node != NULL)
        {
            if (set_flag_p->set_all || msg_node->marked)
            {
                result = srv_email_stor_fldr_set_msg_flag_next(
                            folder_object->stor_handle,
                            msg_node->msg_id);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SET_MSG_FLAG_STOR_FAIL, result, __LINE__);
                    srv_email_stor_fldr_set_msg_flag_close(folder_object->stor_handle);
                    folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                    srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
                    folder_object->unread_msg_num = stor_fldr_info.unread_count;
                    return result;
                }
                if (msg_node->marked)
                {
                    folder_object->marked_msg_num--;
                    msg_node->marked = MMI_FALSE;
                }
            }
            msg_node = msg_node->next;
        }
        srv_email_stor_fldr_set_msg_flag_close(folder_object->stor_handle);
        folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
        folder_object->unread_msg_num = stor_fldr_info.unread_count;
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        if (set_flag_p->msg_id == EMAIL_MSG_INVALID_ID)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
            return SRV_EMAIL_RESULT_INVALID_PARAMETER;
        }
        msg_node = srv_email_fldr_msg_id_to_node(folder_object, set_flag_p->msg_id);
        if (msg_node == NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
            return SRV_EMAIL_RESULT_INVALID_PARAMETER;
        }
        else
        {
            result = srv_email_stor_fldr_set_msg_flag_next(
                        folder_object->stor_handle,
                        msg_node->msg_id);
            srv_email_stor_fldr_set_msg_flag_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                return result;
            }
            srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
            folder_object->unread_msg_num = stor_fldr_info.unread_count;
            return SRV_EMAIL_RESULT_SUCC;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_delete_msg
 * DESCRIPTION
 *  This function is used to delete the specified emails.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  set_state_p     : [IN]  The pointer point to the parameter structure
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_delete_msg(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_delete_msg_struct *delete_msg_p,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct *msg_node;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_delete_msg_job_struct *delete_msg_info;
    srv_email_stor_fldr_struct stor_fldr_info;
    srv_email_result_enum result;
    srv_email_result_enum close_result;
    srv_email_result_enum get_fldr_info_result = SRV_EMAIL_RESULT_SUCC;
    S32 number;
    S32 sort_index = 0;
    MMI_BOOL swap_node = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (delete_msg_p == NULL ||
        (delete_msg_p->delete_all && delete_msg_p->delete_all_marked) ||
        (!delete_msg_p->delete_all && ! delete_msg_p->delete_all_marked && delete_msg_p->msg_id == EMAIL_MSG_INVALID_ID))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (folder_object->operation != SRV_EMAIL_FLDR_OPERATION_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_DELETE_MSG,
        delete_msg_p->delete_all,
        delete_msg_p->delete_all_marked,
        delete_msg_p->msg_id,
        delete_msg_p->delete_header,
        delete_msg_p->delete_server);
    result = srv_email_stor_fldr_del_msg_open(
                SRV_EMAIL_FLDR_TYPE_INVALID,
                folder_object->acct_id,
                folder_object->fldr_id,
                delete_msg_p->delete_header,
                delete_msg_p->delete_server,
                &folder_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    if (delete_msg_p->delete_all || delete_msg_p->delete_all_marked)
    {
        if (delete_msg_p->delete_all)
        {
            number = folder_object->msg_num;
        }
        else
        {
            number = folder_object->marked_msg_num;
        }
        if (number > 1)
        {
            delete_msg_info = (srv_email_fldr_delete_msg_job_struct*)srv_email_mem_alloc(sizeof(srv_email_fldr_delete_msg_job_struct));
            if (delete_msg_info == NULL)
            {
                srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }
            delete_msg_info->delete_sort_list = (EMAIL_MSG_ID*)srv_email_mem_alloc(sizeof(EMAIL_MSG_ID) * number);
            if (delete_msg_info->delete_sort_list == NULL)
            {
                srv_email_mem_free(delete_msg_info);
                srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }
            if (!srv_email_fldr_get_req_id(folder_object, SRV_EMAIL_FLDR_OPERATION_DELETE_MSG, delete_msg_info, req_id, &delete_msg_info->req_id))
            {
                srv_email_mem_free(delete_msg_info->delete_sort_list);
                srv_email_mem_free(delete_msg_info);
                srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_FAIL;
            }
            /* sort message id */
            msg_node = folder_object->msg_list_header;
            while (msg_node != NULL)
            {
                if (delete_msg_p->delete_all)
                {
                    delete_msg_info->delete_sort_list[sort_index++] = msg_node->msg_id;
                }
                else
                {
                    if (msg_node->marked)
                    {
                        delete_msg_info->delete_sort_list[sort_index++] = msg_node->msg_id;
                    }
                }
                msg_node = msg_node->next;
            }
            while (swap_node == MMI_TRUE)
            {
                swap_node = MMI_FALSE;
                for (sort_index = 0; sort_index < number - 1; sort_index++)
                {
                    if (delete_msg_info->delete_sort_list[sort_index] > delete_msg_info->delete_sort_list[sort_index + 1])
                    {
                        EMAIL_MSG_ID temp_id = delete_msg_info->delete_sort_list[sort_index];
                        delete_msg_info->delete_sort_list[sort_index] = delete_msg_info->delete_sort_list[sort_index + 1];
                        delete_msg_info->delete_sort_list[sort_index + 1] = temp_id;
                        swap_node = MMI_TRUE;
                    }
                }
            }
            delete_msg_info->canceled = MMI_FALSE;
            delete_msg_info->curr_delete_ind = 0;
            delete_msg_info->total_msg_delete = number;
            delete_msg_info->curr_node = folder_object->msg_list_header;
            delete_msg_info->delete_server = delete_msg_p->delete_server;
            delete_msg_info->folder_object = folder_object;
            delete_msg_info->marked = delete_msg_p->delete_all_marked;
            srv_email_schdl_start_job(srv_email_fldr_delete_msg_job, delete_msg_info);
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_DELETE_MSG;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            msg_node = folder_object->msg_list_header;
            while (msg_node != NULL)
            {
                if (delete_msg_p->delete_all || msg_node->marked)
                {
                    result = srv_email_stor_fldr_del_msg_next(
                                folder_object->stor_handle,
                                msg_node->msg_id);
                    if (result != SRV_EMAIL_RESULT_SUCC)
                    {
                        srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
                        folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                        get_fldr_info_result = srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
                        if (get_fldr_info_result == SRV_EMAIL_RESULT_SUCC)
                        {
                            folder_object->unread_msg_num = stor_fldr_info.unread_count;
                            folder_object->msg_num = stor_fldr_info.total_count;
                        }
                        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                            SRV_EMAIL_FLDR_DEL_MSG_STOR_FAIL,
                            result,
                            __LINE__,
                            folder_object->msg_num,
                            folder_object->unread_msg_num);
                        if (result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
                        {
                            return SRV_EMAIL_RESULT_SUCC;
                        }
                        return result;
                    }
                }
                msg_node = msg_node->next;
            }
            close_result = srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
            folder_object->unread_msg_num = stor_fldr_info.unread_count;
            folder_object->msg_num = stor_fldr_info.total_count;
            return close_result;
        }
    }
    else
    {
        if (delete_msg_p->msg_id == EMAIL_MSG_INVALID_ID)
        {
            return SRV_EMAIL_RESULT_FAIL;
        }
        result = srv_email_stor_fldr_del_msg_next(
                    folder_object->stor_handle,
                    delete_msg_p->msg_id);
        close_result = srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
        folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            return result;
        }
        else if (close_result != SRV_EMAIL_RESULT_SUCC)
        {
            return close_result;
        }
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_send
 * DESCRIPTION
 *  This function is used to send the emails in this instance.
 *  It is used for outbox instance only, and will send all message in outbox.
 *  No such function like mark some message and send them and if send one message in message list screen,
 *  app have to create handle of that message and use message handle send function
 * PARAMETERS
 *  fldr_handle      : [IN]  The folder handle
 *  move_to_sent     : [IN]  Move to sent box or not after send successfully
 *  req_id           : [OUT] Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_send(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                MMI_BOOL move_to_sent,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_nwk_finish_notify_struct *finish_notify_data;
    srv_email_nwk_send_struct send_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (folder_object->operation != SRV_EMAIL_FLDR_OPERATION_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SEND, move_to_sent, folder_object->fldr_id, folder_object->fldr_type);
    result = srv_email_nwk_create(
                folder_object->acct_id,
                MMI_FALSE,
                &folder_object->nwk_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    result = srv_email_nwk_set_process_notify(
                folder_object->nwk_handle,
                srv_email_fldr_nwk_proc_func,
                folder_object);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        return result;
    }
    finish_notify_data = (srv_email_fldr_nwk_finish_notify_struct*)srv_email_mem_alloc(sizeof(srv_email_fldr_nwk_finish_notify_struct));
    if (finish_notify_data == NULL)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    finish_notify_data->folder_object = folder_object;
    result =  srv_email_nwk_set_finish_notify(
                folder_object->nwk_handle,
                srv_email_fldr_nwk_finish_callback,
                finish_notify_data);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        srv_email_mem_free(finish_notify_data);
        return result;
    }
    send_info.move_to_sent = move_to_sent;
    send_info.send_outbox = MMI_TRUE;
    send_info.msg_id = EMAIL_MSG_INVALID_ID;
    send_info.msg_handle = EMAIL_MSG_INVALID_HANDLE;
    result = srv_email_nwk_send(folder_object->nwk_handle, &send_info);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SEND_RESULT, result);
    if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        if (srv_email_fldr_get_req_id(folder_object, SRV_EMAIL_FLDR_OPERATION_SEND, finish_notify_data, req_id, &finish_notify_data->req_id))
        {
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_SEND;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            srv_email_nwk_destroy(folder_object->nwk_handle);
            folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
            srv_email_mem_free(finish_notify_data);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SEND_RESULT, SRV_EMAIL_RESULT_FAIL);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    srv_email_mem_free(finish_notify_data);
    srv_email_nwk_destroy(folder_object->nwk_handle);
    folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_receive
 * DESCRIPTION
 *  This function is used to receive the emails for this instance.
 *  It is used for inbox and IMAP4 remote folder instance only.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  recv_opt        : [IN]  The receive option
 *  req_id          : [OUT] Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_receive(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_receive_option_enum recv_opt,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_nwk_finish_notify_struct *finish_notify_data;
    srv_email_nwk_recv_struct nwk_recv_opt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (folder_object->operation != SRV_EMAIL_FLDR_OPERATION_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_RECEIVE, recv_opt, folder_object->fldr_id, folder_object->fldr_type);
    result = srv_email_nwk_create(
                folder_object->acct_id,
                MMI_TRUE,
                &folder_object->nwk_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    result = srv_email_nwk_set_process_notify(
                folder_object->nwk_handle,
                srv_email_fldr_nwk_proc_func,
                folder_object);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        return result;
    }
    finish_notify_data = (srv_email_fldr_nwk_finish_notify_struct*)srv_email_mem_alloc(sizeof(srv_email_fldr_nwk_finish_notify_struct));
    if (finish_notify_data == NULL)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    finish_notify_data->folder_object = folder_object;
    result =  srv_email_nwk_set_finish_notify(
                folder_object->nwk_handle,
                srv_email_fldr_nwk_finish_callback,
                finish_notify_data);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        srv_email_mem_free(finish_notify_data);
        return result;
    }
    nwk_recv_opt.all_fldr = MMI_FALSE;
    nwk_recv_opt.fldr_id = folder_object->fldr_id;
    nwk_recv_opt.recv_opt = recv_opt;
    result = srv_email_nwk_receive(folder_object->nwk_handle, &nwk_recv_opt);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_RECEIVE_RESULT, result);
    if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        if (srv_email_fldr_get_req_id(folder_object, SRV_EMAIL_FLDR_OPERATION_RECEIVE, finish_notify_data, req_id, &finish_notify_data->req_id))
        {
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_RECEIVE;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            srv_email_nwk_destroy(folder_object->nwk_handle);
            folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
            srv_email_mem_free(finish_notify_data);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_RECEIVE_RESULT, SRV_EMAIL_RESULT_FAIL);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    srv_email_mem_free(finish_notify_data);
    srv_email_nwk_destroy(folder_object->nwk_handle);
    folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_sync
 * DESCRIPTION
 *  This function is used to sync the emails in this instance with server.
 *  It is used for inbox and IMAP4 remote folder instance only.
 * PARAMETERS
 *  fldr_handle     : [IN]  The account handle
 *  sync_opt        : [IN]  The sync option
 *  req_id          : [OUT] Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_sync(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_nwk_finish_notify_struct *finish_notify_data;
    srv_email_nwk_sync_struct nwk_sync_opt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (folder_object->operation != SRV_EMAIL_FLDR_OPERATION_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SYNC, folder_object->fldr_id, folder_object->fldr_type);
    result = srv_email_nwk_create(
                folder_object->acct_id,
                MMI_TRUE,
                &folder_object->nwk_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    result = srv_email_nwk_set_process_notify(
                folder_object->nwk_handle,
                srv_email_fldr_nwk_proc_func,
                folder_object);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        return result;
    }
    finish_notify_data = (srv_email_fldr_nwk_finish_notify_struct*)srv_email_mem_alloc(sizeof(srv_email_fldr_nwk_finish_notify_struct));
    if (finish_notify_data == NULL)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    finish_notify_data->folder_object = folder_object;
    result =  srv_email_nwk_set_finish_notify(
                folder_object->nwk_handle,
                srv_email_fldr_nwk_finish_callback,
                finish_notify_data);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        srv_email_mem_free(finish_notify_data);
        return result;
    }
    nwk_sync_opt.all_fldr = MMI_FALSE;
    nwk_sync_opt.fldr_id = folder_object->fldr_id;
    nwk_sync_opt.all_msg = MMI_TRUE;
    nwk_sync_opt.msg_id = EMAIL_MSG_INVALID_ID;
    result = srv_email_nwk_sync(folder_object->nwk_handle, &nwk_sync_opt);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SYNC_RESULT, result);
    if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        if (srv_email_fldr_get_req_id(folder_object, SRV_EMAIL_FLDR_OPERATION_SYNC, finish_notify_data, req_id, &finish_notify_data->req_id))
        {
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_SYNC;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            srv_email_nwk_destroy(folder_object->nwk_handle);
            folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
            srv_email_mem_free(finish_notify_data);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SYNC_RESULT, SRV_EMAIL_RESULT_FAIL);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    srv_email_nwk_destroy(folder_object->nwk_handle);
    folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
    srv_email_mem_free(finish_notify_data);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_abort
 * DESCRIPTION
 *  This function is used to abort async request for the specified folder instance.
 * PARAMETERS
 *  fldr_handle     : [IN]  The folder handle
 *  req_id          : [IN]  The async request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_abort(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                EMAIL_REQ_ID req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_list_msg_job_struct *list_msg_info_p;
    srv_email_fldr_set_msg_flag_job_struct *set_msg_flag_info_p;
    srv_email_fldr_delete_msg_job_struct *delete_msg_info_p;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = srv_email_fldr_handle_to_addr(fldr_handle);
    if (folder_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    for (i = 0; i < SRV_EMAIL_FOLDER_REQ_MAX_NUMBER; i++)
    {
        if (req_id == folder_object->req_id_action_map_list[i].req_id)
        {
            break;
        }
    }
    if (i == SRV_EMAIL_FOLDER_REQ_MAX_NUMBER)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_ABORT, req_id, folder_object->req_id_action_map_list[i].action);
    if (folder_object->req_id_action_map_list[i].action == SRV_EMAIL_FLDR_OPERATION_SEND ||
        folder_object->req_id_action_map_list[i].action == SRV_EMAIL_FLDR_OPERATION_RECEIVE ||
        folder_object->req_id_action_map_list[i].action == SRV_EMAIL_FLDR_OPERATION_SYNC)
    {
        srv_email_nwk_abort(folder_object->nwk_handle);
        srv_email_nwk_destroy(folder_object->nwk_handle);
        folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
    }
    else if (folder_object->req_id_action_map_list[i].action == SRV_EMAIL_FLDR_OPERATION_LIST_MSG)
    {
        if (folder_object->stor_handle != EMAIL_STOR_INVALID_HANDLE)
        {
            srv_email_fldr_free_all_msg_node(folder_object);
            srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        }
        list_msg_info_p = (srv_email_fldr_list_msg_job_struct*)folder_object->req_id_action_map_list[i].operation_info;
        list_msg_info_p->canceled = MMI_TRUE;
    }
    else if (folder_object->req_id_action_map_list[i].action == SRV_EMAIL_FLDR_OPERATION_SET_MSG_FLAG)
    {
        if (folder_object->stor_handle != EMAIL_STOR_INVALID_HANDLE)
        {
            srv_email_stor_fldr_set_msg_flag_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        }
        set_msg_flag_info_p = (srv_email_fldr_set_msg_flag_job_struct*)folder_object->req_id_action_map_list[i].operation_info;
        set_msg_flag_info_p->canceled = MMI_TRUE;
    }
    else if (folder_object->req_id_action_map_list[i].action == SRV_EMAIL_FLDR_OPERATION_DELETE_MSG)
    {
        if (folder_object->stor_handle != EMAIL_STOR_INVALID_HANDLE)
        {
            srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        }
        delete_msg_info_p = (srv_email_fldr_delete_msg_job_struct*)folder_object->req_id_action_map_list[i].operation_info;
        delete_msg_info_p->canceled = MMI_TRUE;
    }
    folder_object->req_id_action_map_list[i].req_id = 0;
    folder_object->req_id_action_map_list[i].action = SRV_EMAIL_FLDR_OPERATION_NONE;
    folder_object->req_id_action_map_list[i].operation_info = NULL;
    folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_handle_to_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static srv_email_fldr_info_struct *srv_email_fldr_handle_to_addr(EMAIL_FLDR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = (srv_email_fldr_info_struct*)handle;
    for (i = 0; i < SRV_EMAIL_FOLDER_HANDLE_MAX_NUMBER; i++)
    {
        if (folder_object == &srv_email_fldr_cntx_p->folder_array[i] &&
            srv_email_fldr_cntx_p->folder_array[i].in_use)
        {
            return folder_object;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_msg_id_to_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static srv_email_fldr_msg_info_node_struct* srv_email_fldr_msg_id_to_node(
                                                srv_email_fldr_info_struct *folder_object,
                                                EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct *msg_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info_p = folder_object->msg_list_header;
    while(msg_info_p != NULL)
    {
        if (msg_info_p->msg_id == msg_id)
        {
            return msg_info_p;
        }
        msg_info_p = msg_info_p->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_list_msg_job_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static void srv_email_fldr_list_msg_job_ext(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_list_msg_job_struct_ext *list_msg_job;
    srv_email_fldr_info_struct *folder_object;
    srv_email_stor_msg_list_header_struct *stor_msg_list_info;
    EMAIL_REQ_ID req_id;
    srv_email_fldr_msg_info_node_struct *curr_node;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_msg_job = (srv_email_fldr_list_msg_job_struct_ext*)user_data;
    folder_object = list_msg_job->folder_object;
    req_id = list_msg_job->req_id;
    curr_node = list_msg_job->curr_node;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_JOB, list_msg_job->canceled);
    if (list_msg_job->canceled)
    {
        folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
        srv_email_fldr_clear_req_id(folder_object, req_id);
        srv_email_mem_free(list_msg_job);
        return;
    }
    result = srv_email_stor_fldr_list_msg_open(
                folder_object->fldr_type,
                folder_object->acct_id,
                folder_object->fldr_id,
                folder_object->text_type,
                folder_object->date_type,
                -1,
                &folder_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
        srv_email_fldr_clear_req_id(folder_object, req_id);
        srv_email_mem_free(list_msg_job);
        srv_email_fldr_free_all_msg_node(folder_object);
        if (folder_object->callback != NULL)
        {
            srv_email_fldr_result.result = MMI_FALSE;
            srv_email_fldr_result.major = SRV_EMAIL_MAIL_ERROR;
            srv_email_fldr_result.minor = result;
            (*folder_object->callback)(
                &srv_email_fldr_result,
                req_id,
                folder_object->user_data);
        }
        return;
    }
    stor_msg_list_info = (srv_email_stor_msg_list_header_struct*)get_ctrl_buffer(sizeof(srv_email_stor_msg_list_header_struct));
    memset(stor_msg_list_info, 0, sizeof(srv_email_stor_msg_list_header_struct));
    for (i = 0; i < SRV_EMAIL_FOLDER_MAX_OPERATION_PER_JOB; i++)
    {
        if (curr_node == NULL)
        {
            srv_email_fldr_sort_msg_struct *sort_msg_p;
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
            free_ctrl_buffer(stor_msg_list_info);
            srv_email_mem_free(list_msg_job);
            srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;

            sort_msg_p = (srv_email_fldr_sort_msg_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_sort_msg_struct));
            sort_msg_p->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
            if (folder_object->fldr_type == SRV_EMAIL_FLDR_TYPE_OUTBOX)
            {
                sort_msg_p->sort_order = MMI_TRUE;
            }
            else
            {
                sort_msg_p->sort_order = MMI_FALSE;
            }
            srv_email_fldr_qsort_msg(folder_object, sort_msg_p);
            free_ctrl_buffer(sort_msg_p);
            if (folder_object->fldr_type == SRV_EMAIL_FLDR_TYPE_OUTBOX)
            {
                folder_object->sort_order = MMI_TRUE;
            }
            else
            {
                folder_object->sort_order = MMI_FALSE;
            }
            if (folder_object->callback != NULL)
            {
                srv_email_fldr_result.result = MMI_TRUE;
                (*folder_object->callback)(
                    &srv_email_fldr_result,
                    req_id,
                    folder_object->user_data);
            }
            srv_email_fldr_clear_req_id(folder_object, req_id);
            return;
        }
        stor_msg_list_info->msg_id = curr_node->msg_id;
        result = srv_email_stor_fldr_list_msg_next(
                            folder_object->stor_handle,
                            stor_msg_list_info);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
            free_ctrl_buffer(stor_msg_list_info);
            srv_email_mem_free(list_msg_job);
            srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_STOR_FAIL, result, __LINE__);
            if (result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
            {
                srv_email_fldr_sort_msg_struct *sort_msg_p;
                sort_msg_p = (srv_email_fldr_sort_msg_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_sort_msg_struct));
                sort_msg_p->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
                if (folder_object->fldr_type == SRV_EMAIL_FLDR_TYPE_OUTBOX)
                {
                    sort_msg_p->sort_order = MMI_TRUE;
                }
                else
                {
                sort_msg_p->sort_order = MMI_FALSE;
                }
                srv_email_fldr_qsort_msg(folder_object, sort_msg_p);
                if (folder_object->fldr_type == SRV_EMAIL_FLDR_TYPE_OUTBOX)
                {
                    folder_object->sort_order = MMI_TRUE;
                }
                else
                {
                folder_object->sort_order = MMI_FALSE;
                }
                folder_object->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
                free_ctrl_buffer(sort_msg_p);
                if (folder_object->callback != NULL)
                {
                    srv_email_fldr_result.result = MMI_TRUE;
                    (*folder_object->callback)(
                        &srv_email_fldr_result,
                        req_id,
                        folder_object->user_data);
                }
                srv_email_fldr_clear_req_id(folder_object, req_id);
                return;
            }
            srv_email_fldr_free_all_msg_node(folder_object);
            if (folder_object->callback != NULL)
            {
                srv_email_fldr_result.result = MMI_FALSE;
                if (result == SRV_EMAIL_RESULT_FS_ERROR)
                {
                    srv_email_fldr_result.major = SRV_EMAIL_FS_ERROR;
                    srv_email_fldr_result.minor = srv_email_errno_get();
                }
                else
                {
                    srv_email_fldr_result.major = SRV_EMAIL_MAIL_ERROR;
                    srv_email_fldr_result.minor = result;
                }
                (*folder_object->callback)(
                    &srv_email_fldr_result,
                    req_id,
                    folder_object->user_data);
            }
            srv_email_fldr_clear_req_id(folder_object, req_id);
            return;
        }
        else
        {
            curr_node->server_size = stor_msg_list_info->server_size;
            curr_node->local_size = stor_msg_list_info->local_size;
            curr_node->has_attach = stor_msg_list_info->has_attach;
            curr_node->time = stor_msg_list_info->time;
            curr_node->flag = stor_msg_list_info->flag;
            curr_node->state = stor_msg_list_info->state;
            curr_node->priority = stor_msg_list_info->priority;
            memcpy(curr_node->buff, stor_msg_list_info->list_subj, (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2);
            curr_node->addr.disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
            srv_email_string_decode(
                (WCHAR*)stor_msg_list_info->disp_name,
                curr_node->addr.disp_name,
                &curr_node->addr.disp_name_len,
                &curr_node->addr.disp_charset);
            mmi_chset_convert(
                CHSET_UTF8,
                CHSET_UCS2,
                (CHAR*)stor_msg_list_info->email_addr,
                (CHAR*)curr_node->addr.email_addr,
                (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
            curr_node = curr_node->next;
        }
    }
    srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
    folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    free_ctrl_buffer(stor_msg_list_info);
    list_msg_job->curr_node = curr_node;
    srv_email_schdl_start_job(srv_email_fldr_list_msg_job_ext, list_msg_job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_list_msg_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static void srv_email_fldr_list_msg_job(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_list_msg_job_struct *list_msg_job;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *msg_node;
    srv_email_mfree_funcptr_type mem_free;
    srv_email_malloc_funcptr_type mem_alloc;
    srv_email_result_enum result;
    srv_email_stor_msg_list_header_struct *stor_msg_list_info;
    EMAIL_REQ_ID req_id;
    S32 start_index;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_msg_job = (srv_email_fldr_list_msg_job_struct*)user_data;
    folder_object = list_msg_job->folder_object;
    req_id = list_msg_job->req_id;
    start_index = list_msg_job->start_index;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_JOB, list_msg_job->canceled);
    if (list_msg_job->canceled)
    {
        folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
        srv_email_fldr_clear_req_id(folder_object, req_id);
        srv_email_mem_free(list_msg_job);
        return;
    }
    result = srv_email_stor_fldr_list_msg_open(
                folder_object->fldr_type,
                folder_object->acct_id,
                folder_object->fldr_id,
                folder_object->text_type,
                folder_object->date_type,
                start_index,
                &folder_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
        srv_email_fldr_clear_req_id(folder_object, req_id);
        srv_email_mem_free(list_msg_job);
        srv_email_fldr_free_all_msg_node(folder_object);
        if (folder_object->callback != NULL)
        {
            srv_email_fldr_result.result = MMI_FALSE;
            srv_email_fldr_result.major = SRV_EMAIL_MAIL_ERROR;
            srv_email_fldr_result.minor = result;
            folder_object->callback(&srv_email_fldr_result, req_id, folder_object->user_data);
        }
        return;
    }
    mem_alloc = srv_email_get_malloc_funcptr(folder_object->srv_handle);
    mem_free = srv_email_get_mfree_funcptr(folder_object->srv_handle);
    stor_msg_list_info = (srv_email_stor_msg_list_header_struct*)get_ctrl_buffer(sizeof(srv_email_stor_msg_list_header_struct));
    memset(stor_msg_list_info, 0, sizeof(srv_email_stor_msg_list_header_struct));
    for (i = 0; i < SRV_EMAIL_FOLDER_MAX_OPERATION_PER_JOB; i++)
    {
        msg_node = (*mem_alloc)(sizeof(srv_email_fldr_msg_info_node_struct));
        if (msg_node == NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_MEMORY_FAIL, __LINE__);
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
            free_ctrl_buffer(stor_msg_list_info);
            srv_email_mem_free(list_msg_job);
            srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            srv_email_fldr_free_all_msg_node(folder_object);

            if (folder_object->callback != NULL)
            {
                srv_email_fldr_result.result = MMI_FALSE;
                srv_email_fldr_result.major = SRV_EMAIL_MAIL_ERROR;
                srv_email_fldr_result.minor = SRV_EMAIL_RESULT_NO_MEMORY;
                folder_object->callback(&srv_email_fldr_result, req_id, folder_object->user_data);
            }
            srv_email_fldr_clear_req_id(folder_object, req_id);
            return;
        }
        memset(msg_node, 0, sizeof(srv_email_fldr_msg_info_node_struct));
        result = srv_email_stor_fldr_list_msg_next(
                            folder_object->stor_handle,
                            stor_msg_list_info);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
            free_ctrl_buffer(stor_msg_list_info);
            srv_email_mem_free(list_msg_job);
            (*mem_free)(msg_node);
            srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
            folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_LIST_MSG_STOR_FAIL, result, __LINE__);
            if (result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
            {
                srv_email_fldr_sort_msg_struct *sort_msg_p;
                sort_msg_p = (srv_email_fldr_sort_msg_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_sort_msg_struct));
                sort_msg_p->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME;
                sort_msg_p->sort_order = MMI_FALSE;
                srv_email_fldr_qsort_msg(folder_object, sort_msg_p);
                free_ctrl_buffer(sort_msg_p);
                if (folder_object->callback != NULL)
                {
                    srv_email_fldr_result.result = MMI_TRUE;
                    folder_object->callback(&srv_email_fldr_result, req_id, folder_object->user_data);
                }
                srv_email_fldr_clear_req_id(folder_object, req_id);
                return;
            }
            srv_email_fldr_free_all_msg_node(folder_object);
            if (folder_object->callback != NULL)
            {
                srv_email_fldr_result.result = MMI_FALSE;
                if (result == SRV_EMAIL_RESULT_FS_ERROR)
                {
                    srv_email_fldr_result.major = SRV_EMAIL_FS_ERROR;
                    srv_email_fldr_result.minor = srv_email_errno_get();
                }
                else
                {
                    srv_email_fldr_result.major = SRV_EMAIL_MAIL_ERROR;
                    srv_email_fldr_result.minor = result;
                }
                (*folder_object->callback)(
                    &srv_email_fldr_result,
                    req_id,
                    folder_object->user_data);
            }
            srv_email_fldr_clear_req_id(folder_object, req_id);
            return;
        }
        else
        {
            list_msg_job->start_index++;
            srv_email_fldr_copy_msg_from_stor_to_note(msg_node, stor_msg_list_info);
            if (folder_object->msg_list_header == NULL)
            {
                folder_object->msg_list_header = msg_node;
                folder_object->msg_list_tail = msg_node;
            }
            else
            {
                msg_node->next = folder_object->msg_list_header;
                folder_object->msg_list_header->pre = msg_node;
                folder_object->msg_list_header = msg_node;
            }
        }
    }
    srv_email_stor_fldr_list_msg_close(folder_object->stor_handle);
    folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    free_ctrl_buffer(stor_msg_list_info);
    srv_email_schdl_start_job(srv_email_fldr_list_msg_job, list_msg_job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_set_msg_flag_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static void srv_email_fldr_set_msg_flag_job(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_set_msg_flag_job_struct *set_msg_flag_info;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *curr_node;
    srv_email_stor_fldr_struct stor_fldr_info;
    srv_email_result_enum result;
    EMAIL_REQ_ID req_id;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_msg_flag_info = (srv_email_fldr_set_msg_flag_job_struct*)user_data;
    folder_object = set_msg_flag_info->folder_object;
    curr_node = set_msg_flag_info->curr_node;
    req_id = set_msg_flag_info->req_id;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SET_MGS_FLAG_JOB, set_msg_flag_info->canceled);
    if (set_msg_flag_info->canceled)
    {
        srv_email_mem_free(set_msg_flag_info);
        srv_email_fldr_clear_req_id(folder_object, req_id);
        srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
        folder_object->unread_msg_num = stor_fldr_info.unread_count;
        folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
        return;
    }
    while (curr_node != NULL)
    {
        if (!set_msg_flag_info->marked || curr_node->marked)
        {
            result = srv_email_stor_fldr_set_msg_flag_next(
                        folder_object->stor_handle,
                        curr_node->msg_id);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
                srv_email_stor_fldr_set_msg_flag_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
                folder_object->unread_msg_num = stor_fldr_info.unread_count;
                srv_email_mem_free(set_msg_flag_info);
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_SET_MSG_FLAG_STOR_FAIL, result, __LINE__);
                if (folder_object->callback != NULL)
                {
                    if (result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
                    {
                        srv_email_fldr_result.result = MMI_TRUE;
                    }
                    else
                    {
                        srv_email_fldr_result.result = MMI_FALSE;
                        if (result == SRV_EMAIL_RESULT_FS_ERROR)
                        {
                            srv_email_fldr_result.major = SRV_EMAIL_FS_ERROR;
                            srv_email_fldr_result.minor = srv_email_errno_get();
                        }
                        else
                        {
                            srv_email_fldr_result.major = SRV_EMAIL_MAIL_ERROR;
                            srv_email_fldr_result.minor = result;
                        }
                    }
                    (*folder_object->callback)(
                        &srv_email_fldr_result,
                        req_id,
                        folder_object->user_data);
                }
                srv_email_fldr_clear_req_id(folder_object, req_id);
                return;
            }
            if (set_msg_flag_info->marked)
            {
                curr_node->marked = MMI_FALSE;
                folder_object->marked_msg_num--;
            }
            count++;
        }
        curr_node = curr_node->next;
        if (count == SRV_EMAIL_FOLDER_MAX_OPERATION_PER_JOB)
        {
            set_msg_flag_info->curr_node = curr_node;
            srv_email_schdl_start_job(
                srv_email_fldr_set_msg_flag_job,
                set_msg_flag_info);
            return;
        }
    }
    folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
    srv_email_stor_fldr_set_msg_flag_close(folder_object->stor_handle);
    folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
    folder_object->unread_msg_num = stor_fldr_info.unread_count;
    srv_email_mem_free(set_msg_flag_info);
    if (folder_object->callback != NULL)
    {
        srv_email_fldr_result.result = MMI_TRUE;
        (*folder_object->callback)(
            &srv_email_fldr_result,
            req_id,
            folder_object->user_data);
    }
    srv_email_fldr_clear_req_id(folder_object, req_id);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_delete_msg_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static void srv_email_fldr_delete_msg_job(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_delete_msg_job_struct *delete_msg_info;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *curr_node;
    srv_email_result_enum result;
    srv_email_result_enum close_result;
    srv_email_result_enum get_fldr_info_result = SRV_EMAIL_RESULT_SUCC;
    srv_email_stor_fldr_struct stor_fldr_info;
    EMAIL_REQ_ID req_id;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_msg_info = (srv_email_fldr_delete_msg_job_struct*)user_data;
    folder_object = delete_msg_info->folder_object;
    curr_node = delete_msg_info->curr_node;
    req_id = delete_msg_info->req_id;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_DLE_MGS_JOB, delete_msg_info->canceled);
    if (delete_msg_info->canceled)
    {
        srv_email_fldr_clear_req_id(folder_object, req_id);
        srv_email_mem_free(delete_msg_info->delete_sort_list);
        srv_email_mem_free(delete_msg_info);
        srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
        folder_object->unread_msg_num = stor_fldr_info.unread_count;
        folder_object->msg_num = stor_fldr_info.total_count;
        folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
        return;
    }
    while (curr_node != NULL && delete_msg_info->curr_delete_ind < delete_msg_info->total_msg_delete)
    {
        if (!delete_msg_info->marked || curr_node->marked)
        {
            result = srv_email_stor_fldr_del_msg_next(
                        folder_object->stor_handle,
                        delete_msg_info->delete_sort_list[delete_msg_info->curr_delete_ind]);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
                close_result = srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
                folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                get_fldr_info_result = srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
                if (get_fldr_info_result == SRV_EMAIL_RESULT_SUCC)
                {
                    folder_object->unread_msg_num = stor_fldr_info.unread_count;
                    folder_object->msg_num = stor_fldr_info.total_count;
                }
                srv_email_mem_free(delete_msg_info);
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_FLDR_DEL_MSG_STOR_FAIL,
                    result,
                    __LINE__,
                    folder_object->msg_num,
                    folder_object->unread_msg_num);
                srv_email_fldr_clear_req_id(folder_object, req_id);
                if (folder_object->callback != NULL)
                {
                    if (result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
                    {
                        if (close_result == SRV_EMAIL_RESULT_SUCC)
                        {
                            srv_email_fldr_result.result = MMI_TRUE;
                        }
                        else
                        {
                            srv_email_fldr_result.result = MMI_FALSE;
                        }
                    }
                    else
                    {
                        srv_email_fldr_result.result = MMI_FALSE;
                        if (result == SRV_EMAIL_RESULT_FS_ERROR)
                        {
                            srv_email_fldr_result.major = SRV_EMAIL_FS_ERROR;
                            srv_email_fldr_result.minor = srv_email_errno_get();
                        }
                        else
                        {
                            srv_email_fldr_result.major = SRV_EMAIL_MAIL_ERROR;
                            srv_email_fldr_result.minor = result;
                        }
                    }
                    (*folder_object->callback)(
                        &srv_email_fldr_result,
                        req_id,
                        folder_object->user_data);
                }
                return;
            }
            count++;
        }
        curr_node = NULL;
        /* not delete all msg needs to be deleted */
        if (delete_msg_info->curr_delete_ind < delete_msg_info->total_msg_delete - 1)
        {
            for (curr_node = folder_object->msg_list_header; curr_node != NULL; curr_node = curr_node->next)
            {
                if (curr_node->msg_id == delete_msg_info->delete_sort_list[delete_msg_info->curr_delete_ind + 1])
                {
                    break;
                }
            }
        }
        if (count == 1)
        {
            delete_msg_info->curr_delete_ind++;
            delete_msg_info->curr_node = curr_node;
            srv_email_schdl_start_job(
                srv_email_fldr_delete_msg_job,
                delete_msg_info);
            return;
        }
    }
    folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
    close_result = srv_email_stor_fldr_del_msg_close(folder_object->stor_handle);
    folder_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
    folder_object->unread_msg_num = stor_fldr_info.unread_count;
    folder_object->msg_num = stor_fldr_info.total_count;
    srv_email_mem_free(delete_msg_info->delete_sort_list);
    srv_email_mem_free(delete_msg_info);
    srv_email_fldr_clear_req_id(folder_object, req_id);
    if (folder_object->callback != NULL)
    {
        if (close_result == SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_fldr_result.result = MMI_TRUE;
        }
        else
        {
            srv_email_fldr_result.result = MMI_FALSE;
        }
        (*folder_object->callback)(
            &srv_email_fldr_result,
            req_id,
            folder_object->user_data);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_msg_node_compare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static S32 srv_email_fldr_msg_node_compare(
            srv_email_fldr_info_struct *folder_object,
            srv_email_fldr_msg_info_node_struct *first,
            srv_email_fldr_msg_info_node_struct *second)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder_object->sort_mode)
    {
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME:
        if (first->time > second->time)
        {
            return 1;
        }
        else if (first->time == second->time)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_SERVER_SIZE:
        if (first->server_size > second->server_size)
        {
            return 1;
        }
        else if (first->server_size == second->server_size)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_LOCAL_SIZE:
        if (first->local_size > second->local_size)
        {
            return 1;
        }
        else if (first->local_size == second->local_size)
        {
            return 0;
        }
        else
        {
            return -1;
        }

    case SRV_EMAIL_FLDR_SORT_MSG_MODE_BUFFER:
        return mmi_wcscmp((const WCHAR*)&first->buff, (const WCHAR*)&second->buff);

    case SRV_EMAIL_FLDR_SORT_MSG_MODE_ADDR:
        return mmi_wcscmp((const WCHAR*)&first->addr.email_addr, (const WCHAR*)&second->addr.email_addr);

    default:
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_msg_node_compare_qsort
 * DESCRIPTION
 *  is the first node shoud be in front of second node
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static S32 srv_email_fldr_msg_node_compare_qsort(
            srv_email_fldr_msg_info_node_struct *first,
            srv_email_fldr_msg_info_node_struct *second,
            srv_email_fldr_sort_msg_struct *sort_msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sort_msg_p->sort_mode)
    {
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME:
        if (first->time > second->time)
        {
            if (!sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (first->time == second->time)
        {
            return 0;
        }
        else
        {
            if (sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_SERVER_SIZE:
        if (first->server_size > second->server_size)
        {
            if (!sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (first->server_size == second->server_size)
        {
            return 0;
        }
        else
        {
            if (sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_LOCAL_SIZE:
        if (first->local_size > second->local_size)
        {
            if (!sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (first->local_size == second->local_size)
        {
            return 0;
        }
        else
        {
            if (sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_BUFFER:
        result = mmi_ucs2cmp((CHAR*)&first->buff, (CHAR*)&second->buff);
        if (result > 0)
        {
            if (!sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (result == 0)
        {
            return 0;
        }
        else
        {
            if (sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        //break;
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_ADDR:
        result = mmi_ucs2cmp((CHAR*)&first->addr.email_addr, (CHAR*)&second->addr.email_addr);
        if (result > 0)
        {
            if (!sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (result == 0)
        {
            return 0;
        }
        else
        {
            if (sort_msg_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        //break;    
    default:
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_msg_node_compare_qsort_async
 * DESCRIPTION
 *  is the first node shoud be in front of second node
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static S32 srv_email_fldr_msg_node_compare_qsort_async(
            srv_email_fldr_msg_info_node_struct *first,
            srv_email_fldr_msg_info_node_struct *second,
            srv_email_fldr_sort_msg_async_struct *sort_msg_async_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sort_msg_async_p->sort_mode)
    {
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME:
        if (first->time > second->time)
        {
            if (!sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (first->time == second->time)
        {
            return 0;
        }
        else
        {
            if (sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_SERVER_SIZE:
        if (first->server_size > second->server_size)
        {
            if (!sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (first->server_size == second->server_size)
        {
            return 0;
        }
        else
        {
            if (sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_LOCAL_SIZE:
        if (first->local_size > second->local_size)
        {
            if (!sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (first->local_size == second->local_size)
        {
            return 0;
        }
        else
        {
            if (sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_BUFFER:
        result = mmi_ucs2cmp((CHAR*)&first->buff, (CHAR*)&second->buff);
        if (result > 0)
        {
            if (!sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (result == 0)
        {
            return 0;
        }
        else
        {
            if (sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        //break;
    case SRV_EMAIL_FLDR_SORT_MSG_MODE_ADDR:
        result = mmi_ucs2cmp((CHAR*)&first->addr.email_addr, (CHAR*)&second->addr.email_addr);
        if (result > 0)
        {
            if (!sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (result == 0)
        {
            return 0;
        }
        else
        {
            if (sort_msg_async_p->sort_order)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        //break;    
    default:
        return 0;
    }
}

static void srv_email_fldr_msg_node_swap(
                srv_email_fldr_msg_info_node_struct *first,
                srv_email_fldr_msg_info_node_struct *second)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first == second)
    {
        return;
    }
    temp = (srv_email_fldr_msg_info_node_struct*)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_node_struct));
    memcpy(temp, first, sizeof(srv_email_fldr_msg_info_node_struct));

    first->msg_id = second->msg_id;
    first->server_size = second->server_size;
    first->local_size = second->local_size;
    first->has_attach = second->has_attach;
    first->time = second->time;
    first->state = second->state;
    first->priority = second->priority;
    first->flag = second->flag;
    first->marked = second->marked;
    memcpy(&(first->addr), &(second->addr), sizeof(srv_email_addr_struct));
    memcpy(first->buff, second->buff, (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2);

    second->msg_id = temp->msg_id;
    second->server_size = temp->server_size;
    second->local_size = temp->local_size;
    second->has_attach = temp->has_attach;
    second->time = temp->time;
    second->state = temp->state;
    second->priority = temp->priority;
    second->flag = temp->flag;
    second->marked = temp->marked;
    memcpy(&(second->addr), &(temp->addr), sizeof(srv_email_addr_struct));
    memcpy(second->buff, temp->buff, (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2);

    free_ctrl_buffer(temp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_msg_node_compare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static void srv_email_fldr_qsort_msg(
                srv_email_fldr_info_struct *folder_object,
                srv_email_fldr_sort_msg_struct *sort_msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_fldr_stack_qsort(folder_object->msg_list_header, folder_object->msg_list_tail, sort_msg_p);
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_msg_node_compare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static srv_email_result_enum srv_email_fldr_qsort_msg_async(
               srv_email_fldr_info_struct *folder_object,
               srv_email_fldr_sort_msg_async_struct *sort_msg_async_p)
{
    srv_email_result_enum ret=SRV_EMAIL_RESULT_SUCC;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret=srv_email_fldr_stack_qsort_async(sort_msg_async_p);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_stack_qsort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static void srv_email_fldr_stack_qsort(
                srv_email_fldr_msg_info_node_struct *left_node,
                srv_email_fldr_msg_info_node_struct *right_node,
                srv_email_fldr_sort_msg_struct *sort_msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct **node_stack;
    U32 stack_size = 0;
    srv_email_fldr_msg_info_node_struct *pivot;
    srv_email_fldr_msg_info_node_struct *l = left_node;
    srv_email_fldr_msg_info_node_struct *r = right_node;
    srv_email_fldr_msg_info_node_struct *temp_right_node;
    U32 stack_max_depth = 0;
    U32 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (left_node == right_node)
    {
        return;
    }
    if (left_node->next == right_node)
    {
        if (srv_email_fldr_msg_node_compare_qsort(left_node, right_node, sort_msg_p) < 0)
        {
            srv_email_fldr_msg_node_swap(left_node, right_node);
        }
        return;
    }

    // init stack
    node_stack = (srv_email_fldr_msg_info_node_struct**)get_ctrl_buffer(sizeof(srv_email_fldr_msg_info_node_struct*) * 500);
    memset(node_stack, 0, sizeof(srv_email_fldr_msg_info_node_struct*) * 500);

    node_stack[stack_size++] = right_node;
    node_stack[stack_size++] = left_node;
    stack_max_depth = stack_size;

    while (stack_size > 0)
    {
        loop_count++;
        // push in right first so pop out left first
        l = node_stack[--stack_size];
        node_stack[stack_size] = NULL;
        r = node_stack[--stack_size];
        node_stack[stack_size] = NULL;

        if (l != r)
        {
            if (l->next == r)
            {
                if (srv_email_fldr_msg_node_compare_qsort(l, r, sort_msg_p) < 0)
                {
                    srv_email_fldr_msg_node_swap(l, r);
                }
            }
            else
            {

                pivot = l;
                temp_right_node = r;
                while(l != r)
                {
                    while (l != r && srv_email_fldr_msg_node_compare_qsort(pivot, r, sort_msg_p) >= 0)
                    {
                        r = r->pre;
                    }
                    while (l != r && srv_email_fldr_msg_node_compare_qsort(l, pivot, sort_msg_p) >= 0)
                    {
                        l = l->next;
                    }
                    if (l != r)
                    {
                        srv_email_fldr_msg_node_swap(l, r);
                    }
                }
                if (l != pivot)
                {
                    srv_email_fldr_msg_node_swap(l, pivot);
                }
                if (pivot != l)
                {
                    // push in right first
                    node_stack[stack_size++] = l->pre;
                    node_stack[stack_size++] = pivot;
                }
                if (l != temp_right_node)
                {
                    // push in right first
                    node_stack[stack_size++] = temp_right_node;
                    node_stack[stack_size++] = l->next;
                }
            }
        }
        if (stack_max_depth < stack_size)
        {
            stack_max_depth = stack_size;
        }
    }
    free_ctrl_buffer(node_stack);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_stack_qsort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static srv_email_result_enum srv_email_fldr_stack_qsort_async(srv_email_fldr_sort_msg_async_struct *sort_msg_async_p) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_email_fldr_msg_info_node_struct **node_stack;
    //U32 stack_size = 0;
    srv_email_fldr_msg_info_node_struct *pivot;
    //srv_email_fldr_msg_info_node_struct *left_node;
    //srv_email_fldr_msg_info_node_struct *right_node;
    srv_email_fldr_msg_info_node_struct *l;
    srv_email_fldr_msg_info_node_struct *r;
    srv_email_fldr_msg_info_node_struct *temp_right_node;
    srv_email_fldr_msg_info_node_struct *temp_msg_node;
    srv_email_fldr_info_struct *folder_object;
    EMAIL_REQ_ID req_id = 0;
    U32 stack_max_depth = 0;
    U32 loop_count = 0;
    U32 begin_count=0;
    U32 end_count=0;
    S32 index = 0;
    static U32 is_async = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //the sort job has been abort by red key
    folder_object=sort_msg_async_p->folder_object;
    if(sort_msg_async_p->folder_object==NULL)
    {
        if(sort_msg_async_p->folder_object->callback!=NULL && is_async == 1)
        {    
            srv_email_fldr_result.result = MMI_FALSE;
            (*sort_msg_async_p->folder_object->callback)(
                &srv_email_fldr_result,
                req_id, // check it again
                sort_msg_async_p->folder_object->user_data);
            is_async = 0;
            //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and redkey");
        }
        temp_msg_node = folder_object->msg_list_header;
        while (temp_msg_node != NULL)
        {
            if (temp_msg_node->msg_id == sort_msg_async_p->msg_id)
            {
                *sort_msg_async_p->msg_index = index;
                break;
            }
            index++;
            temp_msg_node = temp_msg_node->next;
        }
        //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and redkey it should highlight at %d",index);
        srv_email_mem_free(sort_msg_async_p->mem_ptr);
        srv_email_mem_free(sort_msg_async_p);
        return SRV_EMAIL_RESULT_SUCC;
    }
    req_id=sort_msg_async_p->req_id;
    //get the sort begin time
    kal_get_time(&begin_count);
    //if the pre sort NOT completed,it dose not need to pop up the header and the tail node to been sort and 
    //just continue to finish it
    stack_max_depth = sort_msg_async_p->stack_size;
    if(!sort_msg_async_p->finished)
    {
        l=sort_msg_async_p->sub_sort_header_node;
        r=sort_msg_async_p->sub_sort_tail_node;
        temp_right_node=r;
        pivot=sort_msg_async_p->pivot;
        while(l!=r)
        {
            //if the pre sort not finished,and the comp director is from r to l
            if(!sort_msg_async_p->director)
            {
                while ((l != r) && (srv_email_fldr_msg_node_compare_qsort_async(pivot, r, sort_msg_async_p) >= 0))
                {
                    r = r->pre;
                    kal_get_time(&end_count);
                    if(((end_count)-(begin_count))>=SRV_EMAIL_MAX_TIME_TO_SORT_PER_TIME)
                    {
                        //something more
                        sort_msg_async_p->finished=MMI_FALSE;
                        sort_msg_async_p->sub_sort_header_node=l;
                        sort_msg_async_p->sub_sort_tail_node=r;
                        sort_msg_async_p->director=MMI_FALSE;
                        srv_email_schdl_start_job((srv_email_schdl_funcptr_type)srv_email_fldr_stack_qsort_async, sort_msg_async_p);
                        is_async = 1;
                        //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and return SRV_EMAIL_RESULT_WOULDBLOCK_1");
                        return SRV_EMAIL_RESULT_WOULDBLOCK;
                    }
                }
                while ((l != r) && (srv_email_fldr_msg_node_compare_qsort_async(l, pivot, sort_msg_async_p) >= 0))
                {
                    l = l->next;
                    kal_get_time(&end_count);
                    if(((end_count)-(begin_count))>=SRV_EMAIL_MAX_TIME_TO_SORT_PER_TIME)
                    {
                        //something more
                        sort_msg_async_p->finished=MMI_FALSE;
                        sort_msg_async_p->sub_sort_header_node=l;
                        sort_msg_async_p->sub_sort_tail_node=r;
                        sort_msg_async_p->director=MMI_TRUE;
                        srv_email_schdl_start_job((srv_email_schdl_funcptr_type)srv_email_fldr_stack_qsort_async, sort_msg_async_p);
                        is_async = 1;
                        //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and return SRV_EMAIL_RESULT_WOULDBLOCK_2");
                        return SRV_EMAIL_RESULT_WOULDBLOCK;
                    }
                }
                if (l != r)
                {
                    srv_email_fldr_msg_node_swap(l, r);
                }
                sort_msg_async_p->finished=MMI_TRUE;
                sort_msg_async_p->director=MMI_FALSE;

            }
            //if the pre sort not finished,and the comp director is from l to r
            else
            {
                while ((l != r) && (srv_email_fldr_msg_node_compare_qsort_async(l, pivot, sort_msg_async_p) >= 0))
                {
                    l = l->next;
                    kal_get_time(&end_count);
                    if(((end_count)-(begin_count))>=SRV_EMAIL_MAX_TIME_TO_SORT_PER_TIME)
                    {
                        //something more
                        sort_msg_async_p->finished=MMI_FALSE;
                        sort_msg_async_p->sub_sort_header_node=l;
                        sort_msg_async_p->sub_sort_tail_node=r;
                        sort_msg_async_p->director=MMI_TRUE;
                        srv_email_schdl_start_job((srv_email_schdl_funcptr_type)srv_email_fldr_stack_qsort_async, sort_msg_async_p);
                        is_async = 1;
                        //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and return SRV_EMAIL_RESULT_WOULDBLOCK_3");
                        return SRV_EMAIL_RESULT_WOULDBLOCK;
                    }
                }
                if (l != r)
                {
                    srv_email_fldr_msg_node_swap(l, r);
                }
                sort_msg_async_p->finished=MMI_TRUE;
                sort_msg_async_p->director=MMI_FALSE;
            }
        }
        if (l != pivot)
        {
            srv_email_fldr_msg_node_swap(l, pivot);
        }
        if (pivot != l && l->pre != pivot)
        {
            // push in right first
            sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++] = l->pre;
            sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++] = pivot;
            ASSERT(sort_msg_async_p->stack_size <= sort_msg_async_p->folder_object->msg_num);
            //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and IN stack_num=%d",sort_msg_async_p->stack_size);
        }
        if (l != temp_right_node && temp_right_node != l->next)
        {
            // push in right first
            sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++] = temp_right_node;
            sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++] = l->next;
            ASSERT(sort_msg_async_p->stack_size <= sort_msg_async_p->folder_object->msg_num);
            //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and IN stack_num=%d",sort_msg_async_p->stack_size);
        }
        goto RET;    
    }

    //if the pre sort has been complete,it need to pop up the header and the tail node to been sor


RET:
    while ((sort_msg_async_p->stack_size) > 0)
    {

        loop_count++;
        // push in right first so pop out left first
        l = sort_msg_async_p->mem_ptr[--(sort_msg_async_p->stack_size)];
        sort_msg_async_p->mem_ptr[(sort_msg_async_p->stack_size)] = NULL;
        r = sort_msg_async_p->mem_ptr[--(sort_msg_async_p->stack_size)];
        sort_msg_async_p->mem_ptr[(sort_msg_async_p->stack_size)] = NULL;
        //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and OUT stack_num=%d",sort_msg_async_p->stack_size);
        if (l != r)
        {
            if (l->next == r)
            {
                if (srv_email_fldr_msg_node_compare_qsort_async(l, r, sort_msg_async_p) < 0)
                {
                    srv_email_fldr_msg_node_swap(l, r);
                }
            }
            else
            {

                pivot = l;
                temp_right_node = r;
                while(l != r)
                {
                    while ((l != r) && (srv_email_fldr_msg_node_compare_qsort_async(pivot, r, sort_msg_async_p) >= 0))
                    {
                        r = r->pre;
                        kal_get_time(&end_count);
                        if((end_count-begin_count)>=SRV_EMAIL_MAX_TIME_TO_SORT_PER_TIME)
                        {
                            //something more
                            sort_msg_async_p->finished=MMI_FALSE;
                            sort_msg_async_p->sub_sort_header_node=l;
                            sort_msg_async_p->sub_sort_tail_node=r;
                            sort_msg_async_p->director=MMI_FALSE;
                            sort_msg_async_p->pivot=pivot;
                            is_async = 1;
                            srv_email_schdl_start_job((srv_email_schdl_funcptr_type)srv_email_fldr_stack_qsort_async, sort_msg_async_p);
                            //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and return SRV_EMAIL_RESULT_WOULDBLOCK_4");
                            return SRV_EMAIL_RESULT_WOULDBLOCK;
                        }
                    }
                    while ((l != r) && (srv_email_fldr_msg_node_compare_qsort_async(l, pivot, sort_msg_async_p) >= 0))
                    {
                        l = l->next;
                        kal_get_time(&end_count);
                        if(((end_count)-(begin_count))>=SRV_EMAIL_MAX_TIME_TO_SORT_PER_TIME)
                        {
                            //something more
                            sort_msg_async_p->finished=MMI_FALSE;
                            sort_msg_async_p->sub_sort_header_node=l;
                            sort_msg_async_p->sub_sort_tail_node=r;
                            sort_msg_async_p->director=MMI_TRUE;
                            sort_msg_async_p->pivot=pivot;
                            is_async = 1;
                            srv_email_schdl_start_job((srv_email_schdl_funcptr_type)srv_email_fldr_stack_qsort_async, sort_msg_async_p);
                            //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and return SRV_EMAIL_RESULT_WOULDBLOCK_5");
                            return SRV_EMAIL_RESULT_WOULDBLOCK;
                        }
                    }
                    if (l != r)
                    {
                        srv_email_fldr_msg_node_swap(l, r);
                    }
                    sort_msg_async_p->finished=MMI_TRUE;
                    sort_msg_async_p->director=MMI_FALSE;
                }
                if (l != pivot)
                {
                    srv_email_fldr_msg_node_swap(l, pivot);
                }
                if (pivot != l && l->pre != pivot)
                {
                    // push in right first
                    sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++] = l->pre;
                    sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++] = pivot;
                    ASSERT(sort_msg_async_p->stack_size <= sort_msg_async_p->folder_object->msg_num);
                    //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and IN stack_num=%d",sort_msg_async_p->stack_size);
                }
                if (l != temp_right_node && temp_right_node != l->next)
                {
                    // push in right first
                    sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++] = temp_right_node;
                    sort_msg_async_p->mem_ptr[sort_msg_async_p->stack_size++] = l->next;
                    ASSERT(sort_msg_async_p->stack_size <= sort_msg_async_p->folder_object->msg_num);
                    //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and IN stack_num=%d",sort_msg_async_p->stack_size);
                }
            }
        }
        if (stack_max_depth < sort_msg_async_p->stack_size)
        {
            stack_max_depth = sort_msg_async_p->stack_size;
        }
    }
    //when sort finish,it will call the callback to notify 
    temp_msg_node = folder_object->msg_list_header;
    while (temp_msg_node != NULL)
    {
        if (temp_msg_node->msg_id == sort_msg_async_p->msg_id)
        {
            *sort_msg_async_p->msg_index = index;
            break;
        }
        index++;
        temp_msg_node = temp_msg_node->next;
    }
    //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and when finish it should highlight at %d",index);
    if(sort_msg_async_p->folder_object->callback!=NULL && is_async == 1)
    {    
        srv_email_fldr_result.result = MMI_TRUE;
        //srv_email_fldr_result.major = SRV_EMAIL_MAIL_ERROR;
        //srv_email_fldr_result.minor = SRV_EMAIL_RESULT_NO_MEMORY;
        (*sort_msg_async_p->folder_object->callback)(
            &srv_email_fldr_result,
            req_id, // check it again
            sort_msg_async_p->folder_object->user_data);
        is_async = 0;
        //kal_prompt_trace(MOD_MMI, "stack_qsort_async in async and callback to notify finish");
    } 
    srv_email_fldr_clear_req_id(sort_msg_async_p->folder_object, req_id);
    srv_email_mem_free(sort_msg_async_p->mem_ptr);
    srv_email_mem_free(sort_msg_async_p);
    return SRV_EMAIL_RESULT_SUCC;

}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_insert_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_fldr_insert_msg(
                srv_email_fldr_info_struct *folder_object,
                srv_email_fldr_msg_info_node_struct *position_node,
                MMI_BOOL insert_pre,
                srv_email_fldr_msg_info_node_struct *insert_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folder_object == NULL ||
        position_node == NULL ||
        insert_node == NULL)
    {
        return;
    }
    if (insert_pre)
    {
        insert_node->next = position_node;
        insert_node->pre = position_node->pre;
        if (position_node != folder_object->msg_list_header)
        {
            position_node->pre->next = insert_node;
        }
        else
        {
            folder_object->msg_list_header = insert_node;
        }
        position_node->pre = insert_node;
    }
    else
    {
        insert_node->next = position_node->next;
        insert_node->pre = position_node;
        if (position_node != folder_object->msg_list_tail)
        {
            position_node->next->pre = insert_node;
        }
        else
        {
            folder_object->msg_list_tail = insert_node;
        }
        position_node->next = insert_node;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_insert_msg_in_order
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_fldr_insert_msg_in_order(
                srv_email_fldr_info_struct *folder_object,
                srv_email_fldr_msg_info_node_struct *insert_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct *msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (insert_node == NULL)
    {
        return;
    }
    msg_node = folder_object->msg_list_header;
    if (msg_node == NULL)
    {
        insert_node->pre = NULL;
        insert_node->next = NULL;
        folder_object->msg_list_header = insert_node;
        folder_object->msg_list_tail = insert_node;
        return;
    }
    while(msg_node != NULL)
    {
        if (srv_email_fldr_msg_node_compare(folder_object, msg_node, insert_node) >= 0 && folder_object->sort_order)
        {
            srv_email_fldr_insert_msg(folder_object, msg_node, MMI_TRUE, insert_node);
            return;
        }
        else if (srv_email_fldr_msg_node_compare(folder_object, msg_node, insert_node) <= 0 && !folder_object->sort_order)
        {
            srv_email_fldr_insert_msg(folder_object, msg_node, MMI_TRUE, insert_node);
            return;
        }
        msg_node = msg_node->next;
    }
    folder_object->msg_list_tail->next = insert_node;
    insert_node->pre = folder_object->msg_list_tail;
    insert_node->next = NULL;
    folder_object->msg_list_tail = insert_node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_delete_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static srv_email_fldr_msg_info_node_struct *srv_email_fldr_delete_msg_node(
                                                srv_email_fldr_info_struct *folder_object,
                                                srv_email_fldr_msg_info_node_struct *delete_node,
                                                srv_email_mfree_funcptr_type mem_free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct *temp_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TRACE */
    if (folder_object == NULL ||
        delete_node == NULL)
    {
        return NULL;
    }
    folder_object->msg_num--;
    if (delete_node->marked)
    {
        folder_object->marked_msg_num--;
    }
    if (!(delete_node->flag & EMAIL_MSG_FLAG_SEEN))
    {
        folder_object->unread_msg_num--;
    }
    temp_node = delete_node->next;
    if (delete_node == folder_object->msg_list_header)
    {
        folder_object->msg_list_header = delete_node->next;
        if (folder_object->msg_list_header != NULL)
        {
            folder_object->msg_list_header->pre = NULL;
        }
    }
    else if (delete_node == folder_object->msg_list_tail)
    {
        folder_object->msg_list_tail = delete_node->pre;
        if (folder_object->msg_list_tail != NULL)
        {
            folder_object->msg_list_tail->next = NULL;
        }
    }
    else
    {
        delete_node->pre->next = delete_node->next;
        delete_node->next->pre = delete_node->pre;
    }
    (*mem_free)(delete_node);
    return temp_node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_free_all_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static void srv_email_fldr_free_all_msg_node(srv_email_fldr_info_struct *folder_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_msg_info_node_struct *msg_node;
    srv_email_mfree_funcptr_type mem_free;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TRACE */
    msg_node = folder_object->msg_list_header;
    mem_free = srv_email_get_mfree_funcptr(folder_object->srv_handle);
    while (msg_node != NULL)
    {
        folder_object->msg_list_header = msg_node->next;
        (*mem_free)(msg_node);
        msg_node = folder_object->msg_list_header;
    }
    folder_object->msg_list_tail = NULL;
    /* TRACE all message nodes are freed */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_nwk_finish_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_fldr_nwk_finish_callback(srv_email_nwk_finish_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_nwk_finish_notify_struct *finish_data;
    srv_email_fldr_info_struct *folder_object;
    srv_email_stor_fldr_struct stor_fldr_info;
    EMAIL_REQ_ID req_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    finish_data = (srv_email_fldr_nwk_finish_notify_struct*)data->user_data;
    folder_object = (srv_email_fldr_info_struct*)finish_data->folder_object;
    req_id = finish_data->req_id;
    srv_email_mem_free(finish_data);
    srv_email_nwk_destroy(folder_object->nwk_handle);
    folder_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
    srv_email_stor_fldr_get_by_id(folder_object->acct_id, folder_object->fldr_id, &stor_fldr_info);
    folder_object->unread_msg_num = stor_fldr_info.unread_count;
    folder_object->msg_num = stor_fldr_info.total_count;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FLDR_NWK_FINISH,
        req_id,
        folder_object->operation,
        folder_object->msg_num,
        folder_object->unread_msg_num);
    folder_object->operation = SRV_EMAIL_FLDR_OPERATION_NONE;
    srv_email_fldr_clear_req_id(folder_object, req_id);
    if (folder_object->callback != NULL)
    {
        (*folder_object->callback)(
            &data->result,
            req_id,
            folder_object->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static MMI_BOOL srv_email_fldr_get_req_id(
                    srv_email_fldr_info_struct *folder_object,
                    S32 action,
                    void *operation_info,
                    EMAIL_REQ_ID *req_id_1,
                    EMAIL_REQ_ID *req_id_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_FOLDER_REQ_MAX_NUMBER; i++)
    {
        if (folder_object->req_id_action_map_list[i].action == SRV_EMAIL_FLDR_OPERATION_NONE)
        {
            folder_object->req_id_action_map_list[i].req_id = fldr_req_id++;
            folder_object->req_id_action_map_list[i].action = action;
            folder_object->req_id_action_map_list[i].operation_info = operation_info;
            if (req_id_1 != NULL)
            {
                *req_id_1 = folder_object->req_id_action_map_list[i].req_id;
            }
            if (req_id_2 != NULL)
            {
                *req_id_2 = folder_object->req_id_action_map_list[i].req_id;
            }
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_clear_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_fldr_clear_req_id(srv_email_fldr_info_struct *folder_object, EMAIL_REQ_ID req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_FOLDER_REQ_MAX_NUMBER; i++)
    {
        if (folder_object->req_id_action_map_list[i].req_id == req_id)
        {
            folder_object->req_id_action_map_list[i].req_id = 0;
            folder_object->req_id_action_map_list[i].operation_info = NULL;
            folder_object->req_id_action_map_list[i].action = SRV_EMAIL_FLDR_OPERATION_NONE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_able_to_get_permission
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_email_fldr_able_to_get_permission(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, srv_email_om_permission_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_able_to_get_permission
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fldr_om_notify_callback(const srv_email_om_notify_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *msg_node = NULL;
    srv_email_malloc_funcptr_type mem_alloc;
    srv_email_mfree_funcptr_type mem_free;
    srv_email_stor_msg_get_header_struct header;
    srv_email_om_notify_fldr_struct *fldr_notify_info;
    srv_email_om_notify_msg_struct *msg_notify_info;
    srv_email_result_enum result;
    EMAIL_MSG_ID msg_id;
    CHAR *subject;
    U32 size;
    S32 ret;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FLDR_OM_NOTIFY, data->notify_type);
    for (i = 0; i < SRV_EMAIL_FOLDER_HANDLE_MAX_NUMBER; i++)
    {
        if (srv_email_fldr_cntx_p->folder_array[i].in_use)
        {
            /* TRACE data->notify_type */
            folder_object = &srv_email_fldr_cntx_p->folder_array[i];
            mem_alloc = srv_email_get_malloc_funcptr(folder_object->srv_handle);
            mem_free = srv_email_get_mfree_funcptr(folder_object->srv_handle);
            switch (data->notify_type)
            {
            case SRV_EMAIL_OM_NOTIFY_MSG_ADD:
                msg_id = ((srv_email_om_notify_msg_struct*)(data->data))->msg_id;
                if (folder_object->acct_id == srv_email_stor_msg_id_to_acct_id(msg_id) &&
                    folder_object->fldr_id == srv_email_stor_msg_id_to_fldr_id(msg_id))
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                        SRV_EMAIL_FLDR_OM_NOTIFY_ADD_MSG,
                        msg_id,
                        folder_object->fldr_id,
                        folder_object->acct_id,
                        i);

                    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(srv_email_msg_id_to_acct_id(msg_id)));

                    if (srv_email_fldr_msg_id_to_node(folder_object, msg_id) != NULL)
                    {
                        continue;
                    }
                    result = srv_email_stor_msg_get_header(msg_id, &header);
                    if (result != SRV_EMAIL_RESULT_SUCC)
                    {
                        return;
                    }
                    msg_node = (srv_email_fldr_msg_info_node_struct*)(*mem_alloc)(sizeof(srv_email_fldr_msg_info_node_struct));
                    if (msg_node == NULL)
                    {
                        return;
                    }
                    memset(msg_node, 0, sizeof(srv_email_fldr_msg_info_node_struct));
                    msg_node->flag = header.flag;
                    msg_node->has_attach = header.attch_num;
                    msg_node->local_size = header.local_size;
                    msg_node->server_size = header.server_size;
                    msg_node->state = header.state;
                    msg_node->marked = MMI_FALSE;
                    msg_node->msg_id = msg_id;
                    msg_node->priority = header.priority;
                    msg_node->time = header.created_date;
                    msg_node->addr.disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
                    srv_email_string_decode(
                        (WCHAR*)header.disp_name,
                        msg_node->addr.disp_name,
                        &msg_node->addr.disp_name_len,
                        &msg_node->addr.disp_charset);
                    mmi_chset_convert(
                        CHSET_UTF8,
                        CHSET_UCS2,
                        (CHAR*)header.email_addr,
                        (CHAR*)msg_node->addr.email_addr,
                        (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
                    ret = srv_email_stor_msg_get_subj_len(msg_id, &size);
                    if (ret != SRV_EMAIL_RESULT_SUCC)
                    {
                        (*mem_free)(msg_node);
                        return;
                    }
                    if (size != 0)
                    {
                        subject = (CHAR*)get_ctrl_buffer(size + 1);
                        size += 1;
                        result = srv_email_stor_msg_get_subj(msg_id, subject, &size);
                        if (result != SRV_EMAIL_RESULT_SUCC)
                        {
                            free_ctrl_buffer(subject);
                            (*mem_free)(msg_node);
                            return;
                        }
                        size = (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2;
                        srv_email_string_decode((WCHAR*)subject, msg_node->buff, (S32*)&size, NULL);
                        free_ctrl_buffer(subject);
                    }
                    srv_email_fldr_insert_msg_in_order(folder_object, msg_node);
                }
                break;
            case SRV_EMAIL_OM_NOTIFY_MSG_DEL:
                msg_id = ((srv_email_om_notify_msg_struct*)(data->data))->msg_id;

                MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(srv_email_msg_id_to_acct_id(msg_id)));

                if (folder_object->acct_id == srv_email_stor_msg_id_to_acct_id(msg_id) &&
                    folder_object->fldr_id == srv_email_stor_msg_id_to_fldr_id(msg_id))
                {
                    for (msg_node = folder_object->msg_list_header;
                         msg_node != NULL;
                         msg_node = msg_node->next)
                    {
                        if (msg_node->msg_id == msg_id)
                        {
                            srv_email_fldr_delete_msg_node(folder_object, msg_node, mem_free);
                            break;
                        }
                    }
                }
                break;
            case SRV_EMAIL_OM_NOTIFY_MSG_UPDATE:
                msg_notify_info = (srv_email_om_notify_msg_struct*)(data->data);
                msg_id = msg_notify_info->msg_id;

                MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(srv_email_msg_id_to_acct_id(msg_id)));

                if (folder_object->acct_id == srv_email_stor_msg_id_to_acct_id(msg_id) &&
                    folder_object->fldr_id == srv_email_stor_msg_id_to_fldr_id(msg_id))
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                        SRV_EMAIL_FLDR_OM_NOTIFY_UPDATE_MSG,
                        msg_id,
                        folder_object->fldr_id,
                        folder_object->acct_id,
                        i);
                    for (msg_node = folder_object->msg_list_header;
                         msg_node != NULL;
                         msg_node = msg_node->next)
                    {
                        if (msg_node->msg_id == msg_id)
                        {
                            if (msg_notify_info->chg_mask & SRV_EMAIL_OM_NOTIFY_MSG_CHG_SIZE)
                            {
                                msg_node->local_size = msg_notify_info->local_size;
                                msg_node->server_size = msg_notify_info->server_size;
                                folder_object->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_NONE;
                            }
                            if (msg_notify_info->chg_mask & SRV_EMAIL_OM_NOTIFY_MSG_CHG_FLAG)
                            {
                                msg_node->flag = msg_notify_info->flag;
                            }
                            if (msg_notify_info->chg_mask & SRV_EMAIL_OM_NOTIFY_MSG_CHG_STATE)
                            {
                                msg_node->state = msg_notify_info->state;
                                if (msg_notify_info->state & SRV_EMAIL_MSG_STATE_DEL_SERVER)
                                {
                                    srv_email_fldr_delete_msg_node(folder_object, msg_node, mem_free);
                                    /* msg_node == NULL ??? */
                                }
                            }
                            if (msg_notify_info->chg_mask & SRV_EMAIL_OM_NOTIFY_MSG_CHG_ATTCH)
                            {
                                folder_object->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_NONE;
                                msg_node->has_attach = msg_notify_info->attch_num;
                            }
                            if (msg_notify_info->chg_mask & SRV_EMAIL_OM_NOTIFY_MSG_CHG_PRIO)
                            {
                                msg_node->priority = msg_notify_info->priority;
                            }
                            /* msg_node == NULL ???*/
                            MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                                SRV_EMAIL_FLDR_OM_NOTIFY_UPDATE_MSG_INFO,
                                msg_notify_info->chg_mask,
                                msg_node->flag,
                                msg_node->state,
                                msg_node->has_attach,
                                msg_node->priority);
                            if (msg_notify_info->chg_mask & SRV_EMAIL_OM_NOTIFY_MSG_CHG_CONT)
                            {
                                folder_object->sort_mode = SRV_EMAIL_FLDR_SORT_MSG_MODE_NONE;
                                result = srv_email_stor_msg_get_header(msg_id, &header);
                                if (result != SRV_EMAIL_RESULT_SUCC)
                                {
                                    return;
                                }
                                msg_node->addr.disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
                                srv_email_string_decode(
                                    (WCHAR*)header.disp_name,
                                    msg_node->addr.disp_name,
                                    &msg_node->addr.disp_name_len,
                                    &msg_node->addr.disp_charset);
                                mmi_chset_convert(
                                    CHSET_UTF8,
                                    CHSET_UCS2,
                                    (CHAR*)header.email_addr,
                                    (CHAR*)msg_node->addr.email_addr,
                                    (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
                                ret = srv_email_stor_msg_get_subj_len(msg_id, &size);
                                if (ret != SRV_EMAIL_RESULT_SUCC)
                                {
                                    break;
                                }
                                if (size != 0)
                                {
                                    subject = (CHAR*)get_ctrl_buffer(size + 1);
                                    size += 1;
                                    result = srv_email_stor_msg_get_subj(msg_id, subject, (U32*)&size);
                                    if (result != SRV_EMAIL_RESULT_SUCC)
                                    {
                                        free_ctrl_buffer(subject);
                                        return;
                                    }
                                    size = (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2;
                                    srv_email_string_decode((WCHAR*)subject, msg_node->buff, (S32*)&size, NULL);
                                    free_ctrl_buffer(subject);
                                }
                                else
                                {
                                    msg_node->buff[0] = 0;
                                }
                            }
                            break;
                        }
                    }
                }
                break;
            case SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG:
                fldr_notify_info = (srv_email_om_notify_fldr_struct*)(data->data);
                if (folder_object->fldr_id == fldr_notify_info->fldr_id &&
                    folder_object->acct_id == fldr_notify_info->acct_id)
                {
                    U32 cnt = 0;
                    srv_email_fldr_msg_info_node_struct *tmp = folder_object->msg_list_header;
                    while (tmp != NULL)
                    {
                        ++cnt;
                        tmp = tmp->next;
                    }
                    MMI_ASSERT(cnt == fldr_notify_info->msg_total_num);
                    
                    folder_object->msg_num = fldr_notify_info->msg_total_num;
                    folder_object->unread_msg_num = fldr_notify_info->msg_unread_num;
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                        SRV_EMAIL_FLDR_OM_NOTIFY_MSG_NUM_CHG,
                        folder_object->fldr_id,
                        folder_object->acct_id,
                        folder_object->msg_num,
                        folder_object->unread_msg_num);
                }
                break;
            //case SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG:
            //    break;
            default:
                return;
            }
            if (folder_object->notify_func != NULL)
            {
                (*folder_object->notify_func)((srv_email_om_notify_struct*)data, folder_object->notify_user_data);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_nwk_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_fldr_nwk_proc_func(srv_email_nwk_proc_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fldr_info_struct *folder_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_object = (srv_email_fldr_info_struct*)data->user_data;
    if (folder_object->proc_callback != NULL)
    {
        data->user_data = folder_object->proc_user_data;
        (*folder_object->proc_callback)(data);
    }
}


extern srv_email_result_enum srv_email_fldr_inbox_get_recent_list(
                                EMAIL_ACCT_ID acct_id,
                                S32 start_index, 
                                U32 *count,
                                U8 flag_mask, 
                                EMAIL_MSG_FLAG matched_flag,
                                srv_email_inbox_index_msg_struct *msg_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_email_stor_inbox_get_recent_list(acct_id, start_index, count, flag_mask, matched_flag, msg_array);
}


extern srv_email_result_enum srv_email_fldr_get_all_msg_id(
                                EMAIL_ACCT_ID acct_id,
                                EMAIL_FLDR_ID fldr_id,
                                U8 flag_mask, 
                                EMAIL_MSG_FLAG matched_flag,
                                U32 *count,
                                EMAIL_MSG_ID *msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_email_stor_get_all_msg_id(
        acct_id, fldr_id, flag_mask, matched_flag, count, msg_id);
}

