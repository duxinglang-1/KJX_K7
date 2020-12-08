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
 * EmailSrvMessage.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email message function.
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
#include "app_mine.h"
#include "emlst_miscell.h"
#include "EmailSrvMessage.h"
#include "MMIDataType.h"
#include "emailsrvgprot.h"
#include "EmailSrvIprot.h"
#include "EmailSrvProt.h"
#include "kal_general_types.h"
#include "EmailSrvStorage.h"
#include "EmailSrvNetwork.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "kal_public_api.h"
#include "fs_gprot.h"
#include "DebugInitDef_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "stdio.h"
#include "string.h"
#include "customer_ps_inc.h"
#include "Unicodexdcl.h"
#include "Conversions.h"
#include "app_datetime.h"
#include "FileMgrSrvGProt.h"

U32 msg_req_id = 1;

static char message_path[] = "Message\\";
static CHAR g_file_name[9][12] =
{
    "to",
    "cc",
    "bcc",
    "subject",
    "content",
    "attach_info",
    "html",
    "_env",
    "_cont"
};
typedef struct
{
    U16 valid_number;
    srv_email_msg_info_struct msg_array[SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER];
    srv_email_notify_func notify_func;
    void *notify_user_data;
    srv_email_msg_init_callback init_callback;
    void *init_user_data;
} srv_email_msg_cntx_struct;

srv_email_msg_cntx_struct g_srv_email_msg_cntx;
srv_email_msg_cntx_struct *srv_email_msg_cntx_p;

extern float GetTimeZone(kal_uint8 cityIndex);
extern kal_uint8 PhnsetGetHomeCity(void);

static srv_email_result_struct srv_email_msg_result;

static void srv_email_msg_init_job(void* user_data);
static FS_HANDLE srv_email_msg_get_file_handle(
                    srv_email_msg_info_struct *msg_object,
                    srv_email_msg_save_part_enum part,
                    MMI_BOOL create_always);
static void srv_email_msg_query_text_func(
                srv_eamil_msg_text_type_enum type,
                srv_email_stor_cont_header_struct *cont_header,
                void *buff,
                U32 buff_size,
                S32 *keep_src,
                void *user_data);
static void srv_email_msg_query_addr_func(
                srv_email_addr_type_enum type,
                U16 index,
                srv_email_stor_addr_struct *data,
                void *user_data);
static void srv_email_msg_query_attach_func(
                U16 index,
                void *buff,
                U32 buff_size,
                S32 *keep_src,
                srv_email_stor_attch_query_type_enum type,
                void *user_data);
static void srv_email_msg_save_new_callback(srv_email_result_enum res, EMAIL_MSG_ID msg_id, void *user_data);
static void srv_email_msg_save_callback(srv_email_result_enum res, EMAIL_MSG_ID msg_id, void *user_data);
static void srv_email_msg_nwk_finish_callback(srv_email_nwk_finish_struct *data);
static void srv_email_msg_copy_callback(
                srv_email_result_enum res,
                EMAIL_MSG_ID to_msg_id,
                void *user_data);
static MMI_BOOL srv_email_msg_get_req_id(
                    srv_email_msg_info_struct *msg_object,
                    S32 action,
                    void *operation_info,
                    EMAIL_REQ_ID *req_id_1,
                    EMAIL_REQ_ID *req_id_2);
static void srv_email_msg_clear_req_id(srv_email_msg_info_struct *msg_object, EMAIL_REQ_ID req_id);
static void srv_email_msg_mime_parser_callback(void *inMsg);
static srv_email_result_enum srv_email_msg_save_int(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 *uidl,
                                U8 *acct_digest,
                                srv_email_msg_save_part_enum save_part,
                                EMAIL_REQ_ID *req_id);
static srv_email_result_enum srv_email_msg_save_new_int(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 *uidl,
                                U8 *acct_digest,
                                EMAIL_ACCT_ID dest_acct_id,
                                EMAIL_FLDR_ID dest_fldr_id,
                                EMAIL_MSG_ID *msg_id,
                                EMAIL_REQ_ID *req_id);
static void srv_email_msg_nwk_proc_func(srv_email_nwk_proc_struct *data);
static void srv_email_msg_om_notify_callback(const srv_email_om_notify_struct *data);
static srv_email_result_enum srv_email_msg_get_retrieve_size(
                                srv_email_msg_info_struct *msg_object,
                                S32 *retrieved_size,
                                S32 *not_retrieved_size);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_init(srv_email_msg_init_callback init_callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 notify_id;
    static U16 index_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_msg_cntx_p = &g_srv_email_msg_cntx;
    srv_email_msg_cntx_p->init_callback = init_callback;
    srv_email_msg_cntx_p->init_user_data = user_data;
    srv_email_msg_cntx_p->notify_func = NULL;
    
    SetProtocolEventHandler(srv_email_msg_mime_parser_callback, MSG_ID_EMAIL_MIME_PARSER_RSP);
    srv_email_om_set_notify(SRV_EMAIL_OM_NOTIFY_OBJ_MSG, srv_email_msg_om_notify_callback, &notify_id);

    index_ptr = 0;
    srv_email_schdl_start_job(srv_email_msg_init_job, &index_ptr);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_msg_init_job(void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *msg_work_path;
    U16 index;
    S32 res;
    S32 dir_exist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = *((U16*)user_data);
    msg_work_path = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);

    if (index == 0)
    {
    kal_wsprintf(msg_work_path, "%s%s", srv_email_get_root_path(), message_path);
    }
    else
    {
        kal_wsprintf(msg_work_path, "%s%s%d\\", srv_email_get_root_path(), message_path, index);
    }
    
    dir_exist = srv_email_util_dir_exist(msg_work_path);
    if (dir_exist < 0)
    {
        res = dir_exist;
        goto EXIT_HANDLE;
    }

    if (dir_exist > 0)
    {
        if (index == 0)
        {
            res = FS_XDelete(msg_work_path, FS_FILE_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
            if (res < FS_NO_ERROR)
            {
                goto EXIT_HANDLE;
        }
    }
}
    else
    {
        res = FS_CreateDir(msg_work_path);
        if (res != FS_NO_ERROR)
        {
            goto EXIT_HANDLE;
        }
    }
    index++;
    
    if (index > SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER)
    {
        free_ctrl_buffer(msg_work_path);
        if (srv_email_msg_cntx_p->init_callback != NULL)
        {
            srv_email_msg_cntx_p->init_callback(SRV_EMAIL_RESULT_SUCC, srv_email_msg_cntx_p->init_user_data);
        }
        return;
    }
    *((U16*)user_data) = index;
    free_ctrl_buffer(msg_work_path);
    srv_email_schdl_start_job(srv_email_msg_init_job, user_data);
    return;

EXIT_HANDLE:
    srv_email_init_errno_set(res);
    srv_email_errno_set(res);
    free_ctrl_buffer(msg_work_path);
    if (srv_email_msg_cntx_p->init_callback != NULL)
    {
        srv_email_msg_cntx_p->init_callback(SRV_EMAIL_RESULT_FS_ERROR, srv_email_msg_cntx_p->init_user_data);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_check_valid
 * DESCRIPTION
 *  This function is used to check if the message id is valid or not.
 * PARAMETERS
 *  msg_id          : [IN]  The message id
 *  is_valid        : [OUT] The validity of the message id
 *                          MMI_TRUE: valid; MMI_FALSE: invalid
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_check_valid(EMAIL_MSG_ID msg_id, MMI_BOOL *is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_valid == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    ret = srv_email_stor_msg_id_valid(msg_id, is_valid);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        return ret;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_ID_CHECK, msg_id, *is_valid);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_create
 * DESCRIPTION
 *  This function is used to create a new message.
 * PARAMETERS
 *  srv_handle       : [IN]  The service handle
 *  msg_handle       : [OUT] Message handle
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_create(
                                EMAIL_SRV_HANDLE srv_handle,
                                EMAIL_MSG_HANDLE *msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_handle == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    if (srv_email_msg_cntx_p->valid_number == SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
    {
        if (srv_email_msg_cntx_p->msg_array[i].in_use == MMI_FALSE)
        {
            break;
        }
    }
    if (i == SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    srv_email_msg_cntx_p->msg_array[i].in_use = MMI_TRUE;
    srv_email_msg_cntx_p->msg_array[i].srv_handle = srv_handle;
    srv_email_msg_cntx_p->msg_array[i].access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
#ifdef __SMS_CLOUD_SUPPORT__
    srv_email_msg_cntx_p->msg_array[i].sms_uid.buff = NULL;
    srv_email_msg_cntx_p->msg_array[i].sms_addr.buff = NULL;
    srv_email_msg_cntx_p->msg_array[i].sms_data.buff = NULL;
#endif /* __SMS_CLOUD_SUPPORT__ */
    srv_email_msg_cntx_p->valid_number++;
    *msg_handle = (EMAIL_MSG_HANDLE)&srv_email_msg_cntx_p->msg_array[i];
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_CREATE, *msg_handle, srv_email_msg_cntx_p->valid_number);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_create_new
 * DESCRIPTION
 *  This function is used to create a new message.
 * PARAMETERS
 *  msg_handle       : [IN] Message handle
 *  set_new_p        : [IN] Struct to store set new info
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_set_new(EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_INIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
    msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_EDIT;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SET_NEW, msg_handle);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_parse_file_int
 * DESCRIPTION
 *  This function is used to parse the specified email file.
 * PARAMETERS
 *  msg_handle       : [IN]  Message handle
 *  file_path        : [IN]  The pointer point to the parameter struct
 * RETURNS
 *  The result code.
 ****************************************************************************/

srv_email_result_enum srv_email_msg_parse_file_int(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *file_path,
                                MMI_BOOL get_attach_info,
                                MMI_BOOL save_attach,
                                EMAIL_REQ_ID *req_id,
                                MMI_BOOL complete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_mime_parser_info_struct *parser_info;
    srv_email_result_enum result;
    srv_email_msg_info_struct *msg_object;
    CHAR *dst_file_path = NULL;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_path == NULL || (!get_attach_info && save_attach))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_INIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_PARSE_FILE, msg_handle, get_attach_info, save_attach);
    parser_info = (srv_email_msg_mime_parser_info_struct*)srv_email_mem_alloc(sizeof(srv_email_msg_mime_parser_info_struct));
    if (parser_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    if (!srv_email_msg_get_req_id(msg_object, SRV_EMAIL_MSG_OPERATION_PARSE, parser_info, req_id, &parser_info->req_id))
    {
        srv_email_mem_free(parser_info);
        return SRV_EMAIL_RESULT_FAIL;
    }
    msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_PARSING;
    dst_file_path = (CHAR*)srv_email_mem_alloc(SRV_EMAIL_MAX_FILE_NAME_LEN + 1);
    if (dst_file_path == NULL)
    {
        srv_email_mem_free(parser_info);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
    {
        if (msg_object == &srv_email_msg_cntx_p->msg_array[i])
        {
            break;
        }
    }
    parser_info->get_attach_info = get_attach_info;
    parser_info->save_attach = save_attach;
    parser_info->msg_object = msg_object;
    parser_info->canceled = MMI_FALSE;
    parser_info->complete= complete;
    kal_sprintf(dst_file_path, "%s%s%d\\", srv_email_get_root_path(), message_path, i + 1);
    result = (srv_email_result_enum)email_parse_file(
                get_attach_info,
                save_attach,
                (kal_bool)!complete,
                file_path,
                dst_file_path,
                SRV_EMAIL_MAX_FILE_NAME_LEN + 1,
                parser_info);
    srv_email_mem_free(dst_file_path);
    msg_object->operation = SRV_EMAIL_MSG_OPERATION_PARSE;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_parse_file
 * DESCRIPTION
 *  This function is used to parse the specified email file.
 * PARAMETERS
 *  msg_handle       : [IN]  Message handle
 *  file_path        : [IN]  The pointer point to the parameter struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_parse_file(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *file_path,
                                MMI_BOOL get_attach_info,
                                MMI_BOOL save_attach,
                                EMAIL_REQ_ID *req_id)
                          
{
    srv_email_result_enum result;
    result = srv_email_msg_parse_file_int(msg_handle,file_path,get_attach_info,save_attach,req_id,MMI_TRUE);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_parse_file
 * DESCRIPTION
 *  This function is used to parse the specified email file.
 * PARAMETERS
 *  msg_handle       : [IN]  Message handle
 *  file_path        : [IN]  The pointer point to the parameter struct
 * RETURNS
 *  The result code.
 ****************************************************************************/


extern srv_email_result_enum srv_email_msg_parse_partial_file(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *file_path,
                                MMI_BOOL get_attach_info,
                                MMI_BOOL save_attach,
                                EMAIL_REQ_ID *req_id)
{
    srv_email_result_enum result;
    result = srv_email_msg_parse_file_int(msg_handle,file_path,get_attach_info,save_attach,req_id,MMI_FALSE);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_create
 * DESCRIPTION
 *  This function is used to create a new message instance according to msg_id.
 *  All memory needed will be allocated
 * PARAMETERS
 *  msg_handle       : [IN] Used to store the message instance handle
 *  acct_id          : [IN]  Whitch account is the message belongs to
 *  fldr_id          : [IN]  Whitch folder is the message belongs to
 *  msg_id           : [IN]  The message id
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_open(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_ACCT_ID acct_id,
                                EMAIL_FLDR_ID fldr_id,
                                EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_stor_msg_get_header_struct header;
    srv_email_result_enum result;
    CHAR *disp_name_p;
    CHAR *addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_id == EMAIL_ACCT_INVALID_ID ||
        fldr_id == EMAIL_FLDR_INVALID_ID ||
        msg_id == EMAIL_MSG_INVALID_ID)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_INIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
//     if (!srv_email_msg_able_to_get_permission(msg_id, SRV_EMAIL_OM_PERMISSION_READ))
//     {
//         return SRV_EMAIL_RESULT_FAIL;
//     }

    msg_object->acct_id = acct_id;
    msg_object->fldr_id = fldr_id;
    msg_object->msg_id = msg_id;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_OPEN, msg_handle, msg_id, fldr_id, acct_id);

    result = srv_email_stor_msg_get_header(msg_id, &header);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    if (header.msg_id != msg_id)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    msg_object->to_addr_num = header.addr_to_num;
    msg_object->cc_addr_num = header.addr_cc_num;
    msg_object->bcc_addr_num = header.addr_bcc_num;
    msg_object->attach_num = header.attch_num;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_OPEN_NUM,
        msg_object->to_addr_num,
        msg_object->cc_addr_num,
        msg_object->bcc_addr_num,
        msg_object->attach_num);
    msg_object->priority = header.priority;
    msg_object->server_size = header.server_size;
    msg_object->local_size = header.local_size;
    msg_object->mail_date = header.created_date;
    msg_object->recv_date = header.received_date;
    msg_object->state = header.state;
    msg_object->flag= header.flag;

    disp_name_p = (CHAR*)get_ctrl_buffer(EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1);
    memset(disp_name_p, 0, EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1);
    addr = (CHAR*)get_ctrl_buffer(SRV_EMAIL_MAX_ADDR_LEN + 1);
    memset(addr, 0, SRV_EMAIL_MAX_ADDR_LEN + 1);
    /* get sender */
    result = srv_email_stor_msg_get_addr_open(
                msg_object->msg_id,
                0,
                SRV_EMAIL_ADDR_TYPE_FROM,
                &msg_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(addr);
        free_ctrl_buffer(disp_name_p);
        return result;
    }
    result = srv_email_stor_msg_get_addr_next(
                msg_object->stor_handle,
                EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1,
                SRV_EMAIL_MAX_ADDR_LEN + 1,
                disp_name_p,
                addr);
    srv_email_stor_msg_get_addr_close(msg_object->stor_handle);
    msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(addr);
        free_ctrl_buffer(disp_name_p);
        return result;
    }
    if (strlen(disp_name_p) >= EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1)
    {
        if (disp_name_p[0] == '=' && disp_name_p[1] == '?')
        {
            disp_name_p[(SRV_EMAIL_MAX_DISP_NAME_LEN * 2) * 2 - 2] = '?';
            disp_name_p[(SRV_EMAIL_MAX_DISP_NAME_LEN * 2) * 2 - 1] = '=';
        }
    }
    msg_object->sender_addr.disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
    srv_email_string_decode(
        (WCHAR*)disp_name_p,
        msg_object->sender_addr.disp_name,
        &msg_object->sender_addr.disp_name_len,
        &msg_object->sender_addr.disp_charset);
    mmi_asc_to_ucs2((CHAR*)msg_object->sender_addr.email_addr, (CHAR*)addr);

    /* get reply to */
    memset(disp_name_p, 0, (SRV_EMAIL_MAX_DISP_NAME_LEN * 2) * 2 + 1);
    memset(addr, 0, SRV_EMAIL_MAX_ADDR_LEN + 1);
    result = srv_email_stor_msg_get_addr_open(
                msg_object->msg_id,
                0,
                SRV_EMAIL_ADDR_TYPE_REPLY_TO,
                &msg_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(addr);
        free_ctrl_buffer(disp_name_p);
        return result;
    }
    result = srv_email_stor_msg_get_addr_next(
                msg_object->stor_handle,
                EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1,
                SRV_EMAIL_MAX_ADDR_LEN + 1,
                (CHAR*)disp_name_p,
                (CHAR*)addr);
    srv_email_stor_msg_get_addr_close(msg_object->stor_handle);
    msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(addr);
        free_ctrl_buffer(disp_name_p);
        return result;
    }
    if (strlen(disp_name_p) >= EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1)
    {
        if (disp_name_p[0] == '==' && disp_name_p[1] == '?')
        {
            disp_name_p[(SRV_EMAIL_MAX_DISP_NAME_LEN * 2) * 2 - 2] = '?';
            disp_name_p[(SRV_EMAIL_MAX_DISP_NAME_LEN * 2) * 2 - 1] = '=';
        }
    }
    msg_object->reply_to_addr.disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
    srv_email_string_decode(
        (WCHAR*)disp_name_p,
        msg_object->reply_to_addr.disp_name,
        &msg_object->reply_to_addr.disp_name_len,
        &msg_object->reply_to_addr.disp_charset);
    mmi_asc_to_ucs2((CHAR*)msg_object->reply_to_addr.email_addr, (CHAR*)addr);
    free_ctrl_buffer(addr);
    free_ctrl_buffer(disp_name_p);
    msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_READ;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified message instance.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_destroy(EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_DESTROY, msg_handle);
    for (i = SRV_EMAIL_MSG_SAVE_ADDR_TO; i < SRV_EMAIL_MSG_SAVE_TOTAL; i++)
    {
        srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, (srv_email_msg_save_part_enum)i);
        FS_Delete(file_path);
    }
    for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
    {
        if (&srv_email_msg_cntx_p->msg_array[i] == msg_object)
        {
            break;
        }
    }
    kal_wsprintf(file_path, "%s%s%d\\%s", srv_email_get_root_path(), message_path, i + 1, "header_info");
    FS_Delete(file_path);
    kal_wsprintf(file_path, "%s%s%d\\%s", srv_email_get_root_path(), message_path, i + 1, "subject");
    FS_Delete(file_path);
    kal_wsprintf(file_path, "%s%s%d\\%s", srv_email_get_root_path(), message_path, i + 1, "content");
    FS_Delete(file_path);
    kal_wsprintf(file_path, "%s%s%d\\%s", srv_email_get_root_path(), message_path, i + 1, "to_t");
    FS_Delete(file_path);
    kal_wsprintf(file_path, "%s%s%d\\%s", srv_email_get_root_path(), message_path, i + 1, "cc_t");
    FS_Delete(file_path);
    kal_wsprintf(file_path, "%s%s%d\\%s", srv_email_get_root_path(), message_path, i + 1, "bcc_t");
    FS_Delete(file_path);
    kal_wsprintf(file_path, "%s%s%d\\%s", srv_email_get_root_path(), message_path, i + 1, "attach_info_t");
    FS_Delete(file_path);
    if (msg_object->nwk_handle != EMAIL_NWK_INVALID_HANDLE)
    {
        srv_email_nwk_destroy(msg_object->nwk_handle);
    }

#ifdef __SMS_CLOUD_SUPPORT__
    if (msg_object->sms_uid.buff)
    {
        srv_email_mem_free(msg_object->sms_uid.buff);
    }

    if (msg_object->sms_addr.buff)
    {
        srv_email_mem_free(msg_object->sms_addr.buff);
    }

    if (msg_object->sms_data.buff)
    {
        srv_email_mem_free(msg_object->sms_data.buff);
    }
#endif /* __SMS_CLOUD_SUPPORT__ */

    /* storage handle will released in the same function witch has get that handle */
    memset(msg_object, 0, sizeof(srv_email_msg_info_struct));
    srv_email_msg_cntx_p->valid_number--;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_regist_callback
 * DESCRIPTION
 *  This function is used to regist callback function for async operation
 * PARAMETERS
 *  msg_handle      : [IN]  On witch message object is this callback on
 *  callback        : [OUT] Callback function for async operation
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_regist_callback(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_funcptr_type callback,
                                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_REGISTER_CALLBACK, MMI_FALSE, msg_handle);
    msg_object->callback = callback;
    msg_object->user_data = user_data;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_clear_callback
 * DESCRIPTION
 *  This function is used to clear callback function for async operation
 * PARAMETERS
 *  msg_handle      : [IN]  On witch message object is this callback on
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_clear_callback(EMAIL_MSG_HANDLE msg_handle)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     srv_email_msg_info_struct *msg_object;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     msg_object = srv_email_msg_handle_to_addr(msg_handle);
     if (msg_object == NULL)
     {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
         return SRV_EMAIL_RESULT_INVALID_HANDLE;
     }
     MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_CLEAR_CALLBACK, MMI_FALSE, msg_handle);
     msg_object->callback = NULL;
     msg_object->user_data = NULL;
     return SRV_EMAIL_RESULT_SUCC;
 }


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_regist_proc_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_regist_proc_callback(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_nwk_proc_funcptr_type proc_callback,
                                void *proc_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_REGISTER_CALLBACK, MMI_TRUE, msg_handle);
    msg_object->proc_callback = proc_callback;
    msg_object->proc_user_data = proc_user_data;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_clear_proc_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_clear_proc_callback(EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_CLEAR_CALLBACK, MMI_TRUE, msg_handle);
    msg_object->proc_callback = NULL;
    msg_object->proc_user_data = NULL;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_regist_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_msg_regist_notify(srv_email_notify_func notify_func, void *notify_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_msg_cntx_p->notify_func = notify_func;
    srv_email_msg_cntx_p->notify_user_data = notify_user_data;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_clear_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_msg_clear_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_msg_cntx_p->notify_func = NULL;
    srv_email_msg_cntx_p->notify_user_data = NULL;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_sender
 * DESCRIPTION
 *  This function is used for app to get the address of the sender.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  addr_info_p     : [OUT] The pointer point to the sender's address struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_basic_info(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_get_basic_info_struct *basic_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum result;
    srv_email_stor_msg_get_header_struct header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (basic_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_INIT ||
        msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_PARSING)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_BASIC_INFO, msg_handle, msg_object->access_state);
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_READ)
    {
        result = srv_email_stor_msg_get_header(msg_object->msg_id, &header);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            return result;
        }
        basic_info_p->acct_id = msg_object->acct_id;
        basic_info_p->fldr_id = msg_object->fldr_id;
        basic_info_p->msg_id = msg_object->msg_id;
        basic_info_p->to_addr_num = header.addr_to_num;
        basic_info_p->cc_addr_num = header.addr_cc_num;
        basic_info_p->bcc_addr_num = header.addr_bcc_num;
        basic_info_p->attach_num = header.attch_num;
        basic_info_p->remain_to_addr_num = header.remain_addr_to_num;
        basic_info_p->remain_cc_addr_num = header.remain_addr_cc_num;
        basic_info_p->remain_bcc_addr_num = header.remain_addr_bcc_num;
        basic_info_p->remain_attach_num = header.remain_attach_num;
        basic_info_p->priority = header.priority;
        basic_info_p->server_size = header.server_size;
        basic_info_p->local_size = header.local_size;
        basic_info_p->mail_date = header.created_date;
        basic_info_p->recv_date = header.received_date;
        basic_info_p->state = header.state;
        basic_info_p->flag = header.flag;
    }
    else
    {
        basic_info_p->acct_id = msg_object->acct_id;
        basic_info_p->fldr_id = msg_object->fldr_id;
        basic_info_p->msg_id = msg_object->msg_id;
        basic_info_p->to_addr_num = msg_object->to_addr_num;
        basic_info_p->cc_addr_num = msg_object->cc_addr_num;
        basic_info_p->bcc_addr_num = msg_object->bcc_addr_num;
        basic_info_p->remain_to_addr_num = msg_object->remain_to_addr_num;
        basic_info_p->remain_cc_addr_num = msg_object->remain_cc_addr_num;
        basic_info_p->remain_bcc_addr_num = msg_object->remain_bcc_addr_num;
        basic_info_p->attach_num = msg_object->attach_num;
        basic_info_p->remain_attach_num = msg_object->remain_attach_num;
        basic_info_p->priority = msg_object->priority;
        basic_info_p->server_size = msg_object->server_size;
        basic_info_p->local_size = msg_object->local_size;
        basic_info_p->mail_date = msg_object->mail_date;
        basic_info_p->recv_date = msg_object->recv_date;
        basic_info_p->state = msg_object->state;
        basic_info_p->flag = msg_object->flag;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_sender
 * DESCRIPTION
 *  This function is used for app to get the address of the sender.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  addr_info_p     : [OUT] The pointer point to the sender's address struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_sender(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_struct *addr_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    memcpy(addr_info_p, &msg_object->sender_addr, sizeof(srv_email_addr_struct));
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_reply_to
 * DESCRIPTION
 *  This function is used to get the address of the sender.
 * PARAMETERS
 *  msg_handle       : [IN]  The message handle
 *  addr_info_p      : [OUT] The pointer point to the reply to's address struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_reply_to(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_struct *addr_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    memcpy(addr_info_p, &msg_object->reply_to_addr, sizeof(srv_email_addr_struct));
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_recipient
 * DESCRIPTION
 *  This function is used to get the address of the recipient.
 * PARAMETERS
 *  msg_handle        : [IN]  The message handle
 *  get_recipient_p   : [OUT] The pointer point to the get recipient struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_recipient(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_get_recipient_struct *get_recipient_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum stor_result;
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE file_handle;
    U32 file_size;
    U32 file_addr_num;
    U32 read;
    S32 result;
    CHAR *disp_name_p;
    WCHAR *addr;
    S32 number;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_recipient_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_GET_RECIPIENT,
        msg_handle,
        msg_object->access_state,
        get_recipient_p->start_index,
        get_recipient_p->number);
    /* EDIT state return info stored by handle */
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        srv_email_msg_save_part_enum save_part = SRV_EMAIL_MSG_SAVE_ADDR_TO;
        switch (get_recipient_p->type)
        {
        case SRV_EMAIL_ADDR_TYPE_TO:
            save_part = SRV_EMAIL_MSG_SAVE_ADDR_TO;
            break;

        case SRV_EMAIL_ADDR_TYPE_CC:
            save_part = SRV_EMAIL_MSG_SAVE_ADDR_CC;
            break;

        case SRV_EMAIL_ADDR_TYPE_BCC:
            save_part = SRV_EMAIL_MSG_SAVE_ADDR_BCC;
            break;

        default:
            MMI_ASSERT(0);
            break;
        }

        srv_email_msg_get_file_path(
            file_path,
            SRV_EMAIL_MAX_FILE_NAME_LEN + 1,
            msg_object,
            save_part);
        file_handle = FS_Open(file_path, FS_READ_ONLY);
        if (file_handle < 0)
        {
            if (file_handle == FS_FILE_NOT_FOUND)
            {
                get_recipient_p->number = 0;
                return SRV_EMAIL_RESULT_SUCC;
            }
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_GetFileSize(file_handle, &file_size);
        file_addr_num = file_size / sizeof(srv_email_addr_struct);
        if (result != FS_NO_ERROR || file_addr_num <= get_recipient_p->start_index)
        {
            FS_Close(file_handle);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
            return SRV_EMAIL_RESULT_INVALID_PARAMETER;
        }
        result = FS_Seek(file_handle, get_recipient_p->start_index * sizeof(srv_email_addr_struct), FS_FILE_BEGIN);
        if (result < 0)
        {
            FS_Close(file_handle);
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        if (file_addr_num > get_recipient_p->start_index + get_recipient_p->number)
        {
            file_addr_num = get_recipient_p->number;
        }
        else
        {
            file_addr_num -= get_recipient_p->start_index;
        }
        for (i = 0; i < file_addr_num; i++)
        {
            result = FS_Read(file_handle, &get_recipient_p->addr_list[i], sizeof(srv_email_addr_struct), &read);
            if (result != FS_NO_ERROR)
            {
                FS_Close(file_handle);
                srv_email_errno_set(result);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            get_recipient_p->number = i + 1;
        }
        FS_Close(file_handle);
        return SRV_EMAIL_RESULT_SUCC;
    }
    /* READ state return info get from storage */
    number = get_recipient_p->number;
    stor_result = srv_email_stor_msg_get_addr_open(
                    msg_object->msg_id,
                    get_recipient_p->start_index,
                    get_recipient_p->type,
                    &msg_object->stor_handle);
    if (stor_result != SRV_EMAIL_RESULT_SUCC)
    {
        return stor_result;
    }
    disp_name_p = (CHAR*)get_ctrl_buffer(EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1);
    memset(disp_name_p, 0, SRV_EMAIL_MAX_DISP_NAME_LEN + 1);
    addr = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
    memset(addr, 0, (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
    for (i = 0; i < number; i++)
    {
        stor_result = srv_email_stor_msg_get_addr_next(
                        msg_object->stor_handle,
                        EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1,
                        (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2,
                        disp_name_p,
                        (CHAR*)addr);
        if (stor_result != SRV_EMAIL_RESULT_SUCC)
        {
            free_ctrl_buffer(addr);
            free_ctrl_buffer(disp_name_p);
            srv_email_stor_msg_get_addr_close(msg_object->stor_handle);
            msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            if (stor_result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
            {
                return SRV_EMAIL_RESULT_SUCC;
            }
            else
            {
                return stor_result;
            }
        }
        if (strlen(disp_name_p) >= EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1)
        {
            if (disp_name_p[0] == '=' && disp_name_p[1] == '?')
            {
                disp_name_p[(SRV_EMAIL_MAX_DISP_NAME_LEN * 2) * 2 - 2] = '?';
                disp_name_p[(SRV_EMAIL_MAX_DISP_NAME_LEN * 2) * 2 - 1] = '=';
            }
        }

        get_recipient_p->number = i + 1;
        mmi_asc_to_ucs2((CHAR*)get_recipient_p->addr_list[i].email_addr, (CHAR*)addr);
        get_recipient_p->addr_list[i].disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
        srv_email_string_decode(
            (WCHAR*)disp_name_p,
            get_recipient_p->addr_list[i].disp_name,
            &get_recipient_p->addr_list[i].disp_name_len,
            &get_recipient_p->addr_list[i].disp_charset);
    }
    free_ctrl_buffer(addr);
    free_ctrl_buffer(disp_name_p);
    srv_email_stor_msg_get_addr_close(msg_object->stor_handle);
    msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_subject_len
 * DESCRIPTION
 *  This function is used to get length of subject
 * PARAMETERS
 *  msg_handle       : [IN]  The message handle
 *  len              : [OUT] Store the length of subject in bytes
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_subject_len(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 *len,
                                S32 *charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum stor_result;
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE file_handle;
    S32 result;
    WCHAR *subject;
    CHAR *subject_temp;
    U32 temp_len;
    S32 dst_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len == NULL || charset == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_GET_SUBJECT_LEN,
        msg_handle,
        msg_object->access_state);
    /* EDIT state */
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, SRV_EMAIL_MSG_SAVE_SUBJECT);
        file_handle = FS_Open(file_path, FS_READ_ONLY);
        if (file_handle < 0)
        {
            if (file_handle == FS_FILE_NOT_FOUND)
            {
                *len = 0;
                *charset = 0;
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_MSG_GET_SUBJECT_LEN_RESULT,
                    *len,
                    *charset);
                return SRV_EMAIL_RESULT_SUCC;
            }
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_GetFileSize(file_handle, len);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        *len = *len / sizeof(WCHAR);
        *charset = msg_object->subject_charset;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_MSG_GET_SUBJECT_LEN_RESULT,
            *len,
            *charset);
        return SRV_EMAIL_RESULT_SUCC;
    }
    /* Other state */
    /* byte */
    result = srv_email_stor_msg_get_subj_len(msg_object->msg_id, &temp_len);
    /* TRACE temp_len (len from storage) */
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return (srv_email_result_enum)result;
    }
    if (temp_len == 0)
    {
        *len = 0;
        *charset = 0;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_MSG_GET_SUBJECT_LEN_RESULT,
            *len,
            *charset);
        return SRV_EMAIL_RESULT_SUCC;
    }
    subject_temp = (CHAR*)srv_email_mem_alloc(temp_len + 1);
    if (subject_temp == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memset(subject_temp, 0, temp_len + 1);
    subject = (WCHAR*)srv_email_mem_alloc(temp_len * 2 + 2);
    if (subject == NULL)
    {
        srv_email_mem_free(subject_temp);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memset(subject, 0, temp_len * 2 + 2);
    temp_len += 1;
    dst_len= temp_len * 2;
    stor_result = srv_email_stor_msg_get_subj(msg_object->msg_id, (CHAR*)subject_temp, (U32*)&temp_len);
    subject_temp[temp_len] = 0;
    if (stor_result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_mem_free(subject_temp);
        srv_email_mem_free(subject);
        return stor_result;
    }
    srv_email_string_decode((WCHAR*)subject_temp, subject, &dst_len, charset);
    *len = mmi_wcslen(subject);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_SUBJECT_LEN_RESULT, *len, *charset);
    srv_email_mem_free(subject_temp);
    srv_email_mem_free(subject);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_subject
 * DESCRIPTION
 *  This function is used to get the partial subject string.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  buff            : [IN]  Buffer to store subject or file path
 *  len             : [IN/OUT] Leng of app want and service given
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_subject(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *subject,
                                U32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum stor_result;
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE file_handle;
    U32 read;
    S32 result;
    CHAR *temp_subject;
    U32 temp_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (subject == NULL || len == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    memset(subject, 0, *len * 2);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_SUBJECT, msg_handle, msg_object->access_state);
    /* EDIT state */
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, SRV_EMAIL_MSG_SAVE_SUBJECT);
        file_handle = FS_Open(file_path, FS_READ_ONLY);
        if (file_handle < 0)
        {
            if (file_handle == FS_FILE_NOT_FOUND)
            {
                *subject = 0;
                *len = 0;
                return SRV_EMAIL_RESULT_SUCC;
            }
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_Read(file_handle, subject, *len * 2, &read);
        *len = read / 2;
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        return SRV_EMAIL_RESULT_SUCC;
    }
    /* Other state */
    result = srv_email_stor_msg_get_subj_len(msg_object->msg_id, &temp_len);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return (srv_email_result_enum)result;
    }
    temp_len += 1;
    temp_subject = (CHAR*)get_ctrl_buffer(temp_len);
    memset(temp_subject, 0, temp_len);
    stor_result = srv_email_stor_msg_get_subj(msg_object->msg_id, (CHAR*)temp_subject, &temp_len);
    if (stor_result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(temp_subject);
        return stor_result;
    }
    else
    {
        temp_len = *len * 2;
        srv_email_string_decode((WCHAR*)temp_subject, subject, (S32*)&temp_len, NULL);
        *len = temp_len;
        free_ctrl_buffer(temp_subject);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_content_len
 * DESCRIPTION
 *  This function is used to get the length of content
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  len             : [OUT] Store the length of content in bytes
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_content_len(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 *len,
                                S32 *charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum stor_result;
    FS_HANDLE file_handle;
    S32 result;
    S8 tmp_text_exist = 0;
    S8 tmp_html_exist = 0;
    MMI_BOOL text_exist = MMI_FALSE;
    WCHAR *temp_file_1;
    U32 size = (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2;
    srv_email_stor_cont_header_struct cont_header;
    S32 chset;
    CHAR *temp_buff;
    WCHAR *temp_buff_2;
    U32 read;
    U32 decode_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len == NULL || charset == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_GET_CONTENT_LEN,
        msg_handle,
        msg_object->access_state);
    /* EDIT state */
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        file_handle = srv_email_msg_get_file_handle(msg_object, SRV_EMAIL_MSG_SAVE_CONTENT, MMI_FALSE);
        if (file_handle < 0)
        {
            if (file_handle == FS_FILE_NOT_FOUND)
            {
                *len = 0;
                *charset = 0;
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_MSG_GET_CONTENT_LEN_RESULT,
                    *len,
                    *charset);
                return SRV_EMAIL_RESULT_SUCC;
            }
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_GetFileSize(file_handle, len);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        *len = *len / sizeof(WCHAR);
        *charset = msg_object->content_charset;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_MSG_GET_CONTENT_LEN_RESULT,
            *len,
            *charset);
        return SRV_EMAIL_RESULT_SUCC;
    }
    /* TRACE text html */
    /* Other state */
    srv_email_stor_msg_cont_exist(msg_object->msg_id, &tmp_text_exist, &tmp_html_exist);
    if ((tmp_text_exist & SRV_EMAIL_MSG_CONT_PART_EXIST) && (tmp_text_exist & SRV_EMAIL_MSG_CONT_DOWNLOADED))
    {
        text_exist = MMI_TRUE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_CONTENT_STATUS, tmp_text_exist, tmp_html_exist);

    if (!text_exist)
    {
        *len = 0;
        *charset = 0;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_MSG_GET_CONTENT_LEN_RESULT,
            *len,
            *charset);
        return SRV_EMAIL_RESULT_SUCC;
    }
    temp_file_1 = get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    memset(temp_file_1, 0, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    stor_result = srv_email_stor_msg_get_cont(
        msg_object->msg_id,
        SRV_EMAIL_STOR_MSG_CONT_TEXT,
        &cont_header,
        temp_file_1,
        &size);
    if (stor_result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(temp_file_1);
        return stor_result;
    }
    chset = email_get_charset_enum((kal_int8*)cont_header.charset);
    file_handle = FS_Open(temp_file_1, FS_READ_ONLY);
    free_ctrl_buffer(temp_file_1);
    if (file_handle < 0)
    {
        srv_email_errno_set(file_handle);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    result = FS_GetFileSize(file_handle, &size);
    if (result != FS_NO_ERROR)
    {
        FS_Close(file_handle);
        srv_email_errno_set(result);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (size <= 1024 - 2) // macro
    {
        temp_buff = (CHAR*)get_ctrl_buffer(size + 2);
        memset(temp_buff, 0, size + 2);
        result = FS_Read(file_handle, temp_buff, size + 2, &read);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            free_ctrl_buffer(temp_buff);
            FS_Close(file_handle);
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        temp_buff_2 = (WCHAR*)get_ctrl_buffer((size + 2) * 2);
        memset(temp_buff_2, 0, (size + 2) * 2);
        if (chset == CHSET_UCS2)
        {
            mmi_wcscpy(temp_buff_2, (WCHAR*)temp_buff);
        }
        else
        {
            mmi_chset_convert((mmi_chset_enum)chset, CHSET_UCS2, temp_buff, (CHAR*)temp_buff_2, (size + 1) * 2);
        }
        *len = mmi_wcslen(temp_buff_2);
        *charset = CHSET_UCS2;
        free_ctrl_buffer(temp_buff);
        free_ctrl_buffer(temp_buff_2);
        FS_Close(file_handle);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_MSG_GET_CONTENT_LEN_RESULT,
            *len,
            *charset);
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        temp_buff = (CHAR*)get_ctrl_buffer(1024);
        temp_buff_2 = (WCHAR*)get_ctrl_buffer(1024 * 2);
        *len = 0;
        while (decode_size < size)
        {
            memset(temp_buff, 0, 1024);
            memset(temp_buff_2, 0, 1024 * 2);
            result = FS_Read(file_handle, temp_buff, 1024 - 2, &read);
            if (result != FS_NO_ERROR)
            {
                FS_Close(file_handle);
                free_ctrl_buffer(temp_buff);
                free_ctrl_buffer(temp_buff_2);
                srv_email_errno_set(result);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            if (chset == CHSET_UCS2)
            {
                mmi_wcscpy(temp_buff_2, (WCHAR*)temp_buff);
            }
            else
            {
                mmi_chset_convert((mmi_chset_enum)chset, CHSET_UCS2, temp_buff, (CHAR*)temp_buff_2, 1024 * 2);
            }
            *len += mmi_wcslen(temp_buff_2);
            decode_size += read;
        }
        *charset = CHSET_UCS2;
        FS_Close(file_handle);
        free_ctrl_buffer(temp_buff);
        free_ctrl_buffer(temp_buff_2);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_MSG_GET_CONTENT_LEN_RESULT,
            *len,
            *charset);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_content
 * DESCRIPTION
 *  This function is used to get the partial content string.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  buff_type       : [IN]  Real buffer for content or file path
 *  len             : [IN/OUT] Leng of app want and service given
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_content(
                                EMAIL_MSG_HANDLE msg_handle,
                                MMI_BOOL buff_type,
                                WCHAR *buff,
                                U32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum stor_result;
    FS_HANDLE file_handle;
    WCHAR *file_path;
    U32 read;
    U32 write;
    S32 result;
    S8 tmp_text_exist = 0;
    S8 tmp_html_exist = 0;
    MMI_BOOL text_exist = MMI_FALSE;
    WCHAR *temp_file_1;
    U32 size = (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2;
    srv_email_stor_cont_header_struct cont_header;
    S32 chset;
    CHAR *temp_buff;
    WCHAR *temp_buff_2;
    U32 decode_size = 0;
    U32 write_len = 0;
    FS_HANDLE write_file_handle = -1;
    U32 write_index = 0;
    U32 str_len = 0;
    MMI_BOOL file_end = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buff == NULL || len == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_CONTENT, msg_handle, msg_object->access_state);
    /* EDIT state */
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        if (buff_type)
        {
            file_handle = srv_email_msg_get_file_handle(msg_object, SRV_EMAIL_MSG_SAVE_CONTENT, MMI_FALSE);
            if (file_handle < 0)
            {
                if (file_handle == FS_FILE_NOT_FOUND)
                {
                    return SRV_EMAIL_RESULT_SUCC;
                }
                srv_email_errno_set(file_handle);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            result = FS_Read(file_handle, buff, *len * sizeof(WCHAR), &read);
            FS_Close(file_handle);
            if (result != FS_NO_ERROR)
            {
                srv_email_errno_set(result);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            return SRV_EMAIL_RESULT_SUCC;
        }
        else
        {
            file_path = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
            memset(file_path, 0, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
            srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, SRV_EMAIL_MSG_SAVE_SUBJECT);
            result = FS_Move(file_path, buff, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
            free_ctrl_buffer(file_path);
            if (result != FS_NO_ERROR)
            {
                srv_email_errno_set(result);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            return SRV_EMAIL_RESULT_SUCC;
        }
    }
    /* Other state */
    srv_email_stor_msg_cont_exist(msg_object->msg_id, &tmp_text_exist, &tmp_html_exist);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_CONTENT_STATUS, tmp_text_exist, tmp_html_exist);
    if ((tmp_text_exist & SRV_EMAIL_MSG_CONT_PART_EXIST) && (tmp_text_exist & SRV_EMAIL_MSG_CONT_DOWNLOADED))
    {
        text_exist = MMI_TRUE;
    }
    /* app should get html file when there is no text content but html content */
    if (!text_exist)
    {
        if (buff_type)
        {
            buff[0] = 0;
        }
        *len = 0;
        return SRV_EMAIL_RESULT_SUCC;
    }
    temp_file_1 = get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    memset(temp_file_1, 0, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    stor_result = srv_email_stor_msg_get_cont(
        msg_object->msg_id,
        SRV_EMAIL_STOR_MSG_CONT_TEXT,
        &cont_header,
        temp_file_1,
        &size);
    if (stor_result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(temp_file_1);
        return stor_result;
    }
    chset = email_get_charset_enum((kal_int8*)cont_header.charset);
    file_handle = FS_Open(temp_file_1, FS_READ_ONLY);
    free_ctrl_buffer(temp_file_1);
    if (file_handle < 0)
    {
        srv_email_errno_set(file_handle);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    result = FS_GetFileSize(file_handle, &size);
    if (result != FS_NO_ERROR)
    {
        FS_Close(file_handle);
        srv_email_errno_set(result);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (size <= 1024 - 2)
    {
        temp_buff = (CHAR*)get_ctrl_buffer(size + 2);
        memset(temp_buff, 0, size + 2);
        result = FS_Read(file_handle, temp_buff, size, &read);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            free_ctrl_buffer(temp_buff);
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        if (buff_type)
        {
            if (chset > MMI_CHSET_BASE && chset < MMI_CHSET_TOTAL)
            {
                mmi_chset_convert((mmi_chset_enum)chset, CHSET_UCS2, temp_buff, (CHAR*)buff, (*len) * sizeof(WCHAR));
                *len = mmi_wcslen(buff);
            }
            else
            {
                *len = strlen(temp_buff);
                memcpy(buff, temp_buff, *len);
                *len /= 2;
                buff[*len] = 0;
            }
        }
        else
        {
            temp_buff_2 = (WCHAR*)get_ctrl_buffer((size + 2) * 2);
            memset(temp_buff_2, 0, (size + 2) * 2);
            if (chset > MMI_CHSET_BASE && chset < MMI_CHSET_TOTAL)
            {
                mmi_chset_convert((mmi_chset_enum)chset, CHSET_UCS2, temp_buff, (CHAR*)temp_buff_2, (*len) * sizeof(WCHAR));
            }
            else
            {
                memcpy(temp_buff_2, temp_buff, strlen(temp_buff));
            }
            file_handle = FS_Open(buff, FS_READ_WRITE | FS_CREATE_ALWAYS);
            if (file_handle < 0)
            {
                free_ctrl_buffer(temp_buff);
                free_ctrl_buffer(temp_buff_2);
                srv_email_errno_set(file_handle);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            result = FS_Write(file_handle, temp_buff_2, mmi_wcslen(temp_buff_2) * 2, &write);
            FS_Close(file_handle);
            if (result != FS_NO_ERROR || write != (U32)mmi_wcslen(temp_buff_2) * 2)
            {
                free_ctrl_buffer(temp_buff);
                free_ctrl_buffer(temp_buff_2);
                FS_Delete(buff);
                srv_email_errno_set(result);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            *len = write / sizeof(WCHAR);
            free_ctrl_buffer(temp_buff_2);
        }
        free_ctrl_buffer(temp_buff);
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        U32 convert_left_size = 0;
        U32 convert_left_addr = 0;
        temp_buff = (CHAR*)get_ctrl_buffer(1024);
        temp_buff_2 = (WCHAR*)get_ctrl_buffer(1024 * 2);
        while (decode_size < size && write_len < *len + 1)
        {
            if (convert_left_size != 0)
            {
                memmove(temp_buff, (CHAR*)convert_left_addr, convert_left_size);
                memset(temp_buff + convert_left_size, 0, 1024 - convert_left_size);
            }
            else
            {
                memset(temp_buff, 0, 1024);
            }
            memset(temp_buff_2, 0, 1024 * 2);

            result = FS_Read(file_handle, temp_buff + convert_left_size, 1024 - 2 - convert_left_size, &read);
            if (result != FS_NO_ERROR)
            {
                FS_Close(file_handle);
                free_ctrl_buffer(temp_buff);
                free_ctrl_buffer(temp_buff_2);
                srv_email_errno_set(result);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            if (read < 1024 - 2 - convert_left_size || read == 0)
            {
                file_end = MMI_TRUE;
            }

            read += convert_left_size; // add the left size in last loop

            if (chset > MMI_CHSET_BASE && chset < MMI_CHSET_TOTAL)
            {
                mmi_chset_convert_ex(
                    (mmi_chset_enum)chset,
                    CHSET_UCS2,
                    temp_buff,
                    (CHAR*)temp_buff_2,
                    1024*2,
                    &convert_left_addr);
                convert_left_size = read - (convert_left_addr - (U32)temp_buff);
                str_len = mmi_wcslen(temp_buff_2);
            }
            else
            {
                str_len = strlen(temp_buff);
                memcpy(temp_buff_2, temp_buff, str_len);
                str_len /= 2;
            }
            write_len += str_len;
            decode_size += (read - convert_left_size);

            if (buff_type)
            {
                if (write_len < *len)
                {
                    memcpy((CHAR*)buff + write_index, temp_buff_2, str_len * 2);
                    write_index += str_len * 2;
                    buff[write_len] = 0;
                }
                else
                {
                    memcpy(
                        (CHAR*)buff + (write_len - mmi_wcslen(temp_buff_2)) * sizeof(WCHAR),
                        temp_buff_2,
                        (*len - write_len + mmi_wcslen(temp_buff_2)) * sizeof(WCHAR));
                    buff[*len - 1] = 0;
                }
            }
            else
            {
                if (write_file_handle < 0)
                {
                    write_file_handle = FS_Open(buff, FS_READ_WRITE | FS_CREATE_ALWAYS);
                    if (write_file_handle < 0)
                    {
                        FS_Close(file_handle);
                        free_ctrl_buffer(temp_buff);
                        free_ctrl_buffer(temp_buff_2);
                        srv_email_errno_set(write_file_handle);
                        return SRV_EMAIL_RESULT_FS_ERROR;
                    }
                }
                result = FS_Write(write_file_handle, temp_buff_2, mmi_wcslen(temp_buff_2) * 2, &read);
                if (result != FS_NO_ERROR)
                {
                    FS_Close(file_handle);
                    FS_Close(write_file_handle);
                    FS_Delete(buff);
                    free_ctrl_buffer(temp_buff);
                    free_ctrl_buffer(temp_buff_2);
                    srv_email_errno_set(result);
                    return SRV_EMAIL_RESULT_FS_ERROR;
                }
            }

            if (file_end)
            {
                break;
            }
        }
        if (write_file_handle >= 0)
        {
            FS_Close(write_file_handle);
        }
        free_ctrl_buffer(temp_buff);
        free_ctrl_buffer(temp_buff_2);
        FS_Close(file_handle);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_cont_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_cont_status(
                                EMAIL_MSG_HANDLE msg_handle,
                                S8 *text_status,
                                S8 *html_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    srv_email_stor_msg_cont_exist(msg_object->msg_id, text_status, html_status);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_CONTENT_STATUS, *text_status, *html_status);
    return SRV_EMAIL_RESULT_SUCC;
}



/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_cont_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_cont_size(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 *text_size,
                                U32 *html_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    srv_email_stor_msg_cont_size(msg_object->msg_id, text_size, html_size);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_CONTENT_STATUS, *text_size, *html_size);
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_html_file
 * DESCRIPTION
 *  This function is used to get the partial content string.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  path            : [IN]  Path of html file
 *  len             : [IN/OUT] Leng of buffer to store path
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_html_file(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *path,
                                U32 *len,
                                CHAR *charset,
                                MMI_BOOL get_src_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    WCHAR *stor_html_path = NULL;
    WCHAR *html_path = NULL;
    U32 size;
    srv_email_result_enum result;
    srv_email_stor_cont_header_struct cont_header;
    S32 fs_result = FS_NO_ERROR;
    S32 chset;
	S32 minor_errno;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    stor_html_path = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    size = (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2;
    result =  srv_email_stor_msg_get_cont(
                msg_object->msg_id,
                SRV_EMAIL_STOR_MSG_CONT_HTML,
                &cont_header,
                stor_html_path,
                &size);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(stor_html_path);
        return result;
    }
    if (get_src_file)
    {
        if (path != NULL)
        {
            if (*len >= SRV_EMAIL_MAX_FILE_NAME_LEN + 1)
            {
                memcpy(path, stor_html_path, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
            }
            else
            {
                memcpy(path, stor_html_path, *len * 2);
            }
        }
        memcpy(charset, cont_header.charset, EMAIL_STOR_CONT_CHARSET_STR_LEN + 1);
        free_ctrl_buffer(stor_html_path);
        return result;
    }
    html_path = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    srv_email_msg_get_file_path(html_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, SRV_EMAIL_MSG_SAVE_HTML);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(stor_html_path);
        free_ctrl_buffer(html_path);
        return SRV_EMAIL_RESULT_FAIL;
    }
    chset = email_get_charset_enum((kal_int8*)cont_header.charset);
    if (chset == CHSET_UTF8 || chset <= CHSET_BASE || chset >= CHSET_TOTAL || chset == CHSET_ASCII)
    {
        fs_result = FS_Move(
            stor_html_path,
            html_path,
            FS_MOVE_COPY | FS_MOVE_OVERWRITE,
            NULL,
            NULL,
            0);
        if (chset <= CHSET_BASE || chset >= CHSET_TOTAL)
        {
            memcpy(charset, cont_header.charset, EMAIL_STOR_CONT_CHARSET_STR_LEN + 1);
        }
        else
        {
            kal_sprintf(charset, "%s", chset_get_preferred_mime_name(CHSET_UTF8)); /* UTF8 */
        }
    }
    else
    {
        result = srv_email_file_chset_convert(
            stor_html_path, cont_header.charset,
            html_path, (CHAR *)chset_get_preferred_mime_name(CHSET_UTF8), &minor_errno);
        kal_sprintf(charset, "%s", chset_get_preferred_mime_name((chset_enum)chset));
    }
    free_ctrl_buffer(stor_html_path);
    if (fs_result != FS_NO_ERROR)
    {
        free_ctrl_buffer(html_path);
        srv_email_errno_set(fs_result);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(html_path);
        srv_email_errno_set(minor_errno);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (path != NULL)
    {
        if (*len >= (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2)
        {
            memcpy(path, html_path, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
        }
        else
        {
            memcpy(path, html_path, (*len) * 2);
        }
    }
    free_ctrl_buffer(html_path);
    if (len != NULL)
    {
        *len = mmi_wcslen(path);
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_HTML_FILE, *len, *charset);
    return SRV_EMAIL_RESULT_SUCC;
}

static mmi_ret srv_email_msg_get_html_path_async_cb(mmi_event_struct *param)
{
    srv_fmgr_async_done_event_struct *fmgrEvt;
    srv_email_file_chset_cvt_async_event_struct *cvtEvt;
    srv_email_msg_get_html_path_struct *get_html_cnxt;

    get_html_cnxt = (srv_email_msg_get_html_path_struct *)(param->user_data);

    switch (param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            srv_email_result_struct result;

            fmgrEvt = (srv_fmgr_async_done_event_struct*)param;
            if (fmgrEvt->result >= 0)
            {
                result.result = MMI_TRUE;
            }
            else
            {
                result.result = MMI_FALSE;
                result.major = SRV_EMAIL_RESULT_FS_ERROR;
                result.minor = fmgrEvt->result;
            }

            srv_email_msg_clear_req_id(get_html_cnxt->msg_object,
                                       get_html_cnxt->req_id);

            if (get_html_cnxt->path_buff != NULL)
            {
                if (get_html_cnxt->buff_len >= (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2)
                {
                    get_html_cnxt->buff_len = (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2;
                }
                mmi_wcsncpy(get_html_cnxt->path_buff,
                           get_html_cnxt->html_path,
                           get_html_cnxt->buff_len / 2 - 1);
            }

            if (get_html_cnxt->msg_object->callback != NULL)
            {
                get_html_cnxt->msg_object->callback(
                    &result,
                    get_html_cnxt->req_id,
                    get_html_cnxt->msg_object->user_data);
            }
            srv_email_mem_free(get_html_cnxt);
        }
        break;

    case EVT_ID_SRV_EMAIL_FILE_CONVERT_DONE:
        {
            srv_email_result_struct result;

            cvtEvt = (srv_email_file_chset_cvt_async_event_struct*)param;
            if (cvtEvt->result == SRV_EMAIL_RESULT_SUCC)
            {
                result.result = MMI_TRUE;
            }
            else
            {
                result.result = MMI_FALSE;
                result.major = cvtEvt->result;
                result.minor = cvtEvt->error_code;
            }

            srv_email_msg_clear_req_id(get_html_cnxt->msg_object,
                                       get_html_cnxt->req_id);

            if (get_html_cnxt->path_buff != NULL)
            {
                if (get_html_cnxt->buff_len >= (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2)
                {
                    get_html_cnxt->buff_len = (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2;
                }
                mmi_wcsncpy(get_html_cnxt->path_buff,
                           get_html_cnxt->html_path,
                           get_html_cnxt->buff_len / 2 - 1);
            }

            if (get_html_cnxt->msg_object->callback != NULL)
            {
                get_html_cnxt->msg_object->callback(
                    &result,
                    get_html_cnxt->req_id,
                    get_html_cnxt->msg_object->user_data);
            }
            srv_email_mem_free(get_html_cnxt);
        }
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_html_file_async
 * DESCRIPTION
 *  This function is used to get the content path asynchronily, please register
 *  callback before call this function.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  path            : [IN]  Path of html file
 *  len             : [IN]  Length of buffer to store path
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_html_path_async(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *path,
                                U32 len,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    U32 size;
    srv_email_result_enum result;
    srv_email_stor_cont_header_struct cont_header;
    srv_email_msg_get_html_path_struct *get_html_cnxt;
    S32 chset;
    S32 minor_errno;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(path != NULL);

    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    get_html_cnxt = (srv_email_msg_get_html_path_struct*)srv_email_mem_alloc(sizeof(*get_html_cnxt));
    if (get_html_cnxt == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    
    size = (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2;

    result =  srv_email_stor_msg_get_cont(
                msg_object->msg_id,
                SRV_EMAIL_STOR_MSG_CONT_HTML,
                &cont_header,
                get_html_cnxt->stor_html_path,
                &size);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_mem_free(get_html_cnxt);
        return result;
    }

    srv_email_msg_get_file_path(get_html_cnxt->html_path,
        SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, SRV_EMAIL_MSG_SAVE_HTML);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_mem_free(get_html_cnxt);
        return SRV_EMAIL_RESULT_FAIL;
    }

    chset = email_get_charset_enum((kal_int8*)cont_header.charset);

    get_html_cnxt->msg_object = msg_object;
    get_html_cnxt->path_buff = path;
    get_html_cnxt->buff_len = len;

    if (chset == CHSET_UTF8 || chset <= CHSET_BASE ||
        chset >= CHSET_TOTAL || chset == CHSET_ASCII)
    {
        FS_Delete(get_html_cnxt->html_path);

        get_html_cnxt->copy_only = MMI_TRUE;
        get_html_cnxt->fs_job_id = srv_fmgr_async_copy(
                                    get_html_cnxt->stor_html_path,
                                    get_html_cnxt->html_path,
                                    FS_MOVE_COPY | FS_MOVE_OVERWRITE,
                                    srv_email_msg_get_html_path_async_cb,
                                    (void*)get_html_cnxt);
    }
    else
    {
        get_html_cnxt->copy_only = MMI_FALSE;
        result = srv_email_file_chset_convert_async(
                    get_html_cnxt->stor_html_path,
                    cont_header.charset,
                    get_html_cnxt->html_path,
                    srv_email_msg_get_html_path_async_cb,
                    (void*)get_html_cnxt,
                    &get_html_cnxt->convert_handle,
                    &minor_errno);
    }

    if (get_html_cnxt->copy_only)
    {
        if (get_html_cnxt->fs_job_id < 0)
        {
            srv_email_mem_free(get_html_cnxt);
            srv_email_errno_set(get_html_cnxt->fs_job_id);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }
    else
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            srv_email_mem_free(get_html_cnxt);
            srv_email_errno_set(minor_errno);
            return result;
        }
    }

    if (!srv_email_msg_get_req_id(
                    msg_object,
                    SRV_EMAIL_MSG_OPERATION_GET_HTML,
                    get_html_cnxt,
                    req_id,
                    &get_html_cnxt->req_id))
    {
        srv_email_mem_free(get_html_cnxt);
        return SRV_EMAIL_RESULT_FAIL;
    }

    //MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_HTML_FILE, *len, 0);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_attachment_info
 * DESCRIPTION
 *  This function is used to get path of certian attachment.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  start_index     : [IN]  Index of attachment app want to get
 *  number          : [IN/OUT] How much app want and how mucn service given
 *  attach_info_p   : [OUT] Array to store the attachment information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_attachment_info(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 start_index,
                                S32 *number,
                                srv_email_attach_struct *attach_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_stor_attch_struct stor_attach_info;
    srv_email_result_enum stor_result;
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE file_handle;
    U32 file_size;
    U32 file_attach_num;
    U32 read;
    S32 result;
    S32 count;
    S32 size;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number == NULL || attach_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_GET_ATTACH_INFO,
        msg_handle,
        msg_object->access_state,
        start_index,
        *number,
        msg_object->attach_num);
    /* EDIT state return info stored by handle */
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, SRV_EMAIL_MSG_SAVE_ATTACHMENT_INFO);
        file_handle = FS_Open(file_path, FS_READ_ONLY);
        if (file_handle < 0)
        {
            if (file_handle == FS_FILE_NOT_FOUND)
            {
                *number = 0;
                return SRV_EMAIL_RESULT_SUCC;
            }
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_GetFileSize(file_handle, &file_size);
        file_attach_num = file_size / sizeof(srv_email_attach_struct);
        if (result != FS_NO_ERROR || file_attach_num <= start_index)
        {
            FS_Close(file_handle);
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_Seek(file_handle, start_index * sizeof(srv_email_attach_struct), FS_FILE_BEGIN);
        if (result < 0)
        {
            FS_Close(file_handle);
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        if (file_attach_num > start_index + *number)
        {
            file_attach_num = *number;
        }
        else
        {
            file_attach_num -= start_index;
        }
        for (i = 0; i < file_attach_num; i++)
        {
            result = FS_Read(file_handle, &attach_info_p[i], sizeof(srv_email_attach_struct), &read);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_MSG_GET_ATTACH_INFO_DETAIL,
                i,
                attach_info_p[i].size,
                attach_info_p[i].mime_type,
                attach_info_p[i].mime_subtype);
            if (result != FS_NO_ERROR)
            {
                FS_Close(file_handle);
                srv_email_errno_set(result);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            *number = i + 1;
        }
        FS_Close(file_handle);
        return SRV_EMAIL_RESULT_SUCC;
    }
    /* READ state return info get from storage */
    stor_result = srv_email_stor_msg_get_attch_open(
                    msg_object->msg_id,
                    start_index,
                    &msg_object->stor_handle);
    if (stor_result != SRV_EMAIL_RESULT_SUCC)
    {
        return stor_result;
    }
    count = *number;
    for (i = 0; i < count; i++)
    {
        stor_result = srv_email_stor_msg_get_attch_next(
                        msg_object->stor_handle,
                        &stor_attach_info);
        /* get information */
        if (stor_result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_stor_msg_get_attch_close(msg_object->stor_handle);
            msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            if (stor_result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
            {
                return SRV_EMAIL_RESULT_SUCC;
            }
            else
            {
                return stor_result;
            }
        }
        attach_info_p[i].attach_id = stor_attach_info.attch_id;
        attach_info_p[i].size = stor_attach_info.server_size;
        attach_info_p[i].downloaded = stor_attach_info.download_flag;
        /* get mime_type and mime_subtype from content_type
        attach_info_p[i].mime_type = stor_attach_info.mime_type;
        attach_info_p[i].mime_subtype = stor_attach_info.mime_subtype;*/
        attach_info_p[i].drm_object = stor_attach_info.drm;
        /* get drm_mime_type and drm_mime_subtype from drm_content_type
        attach_info_p[i].drm_type = stor_attach_info.drm_mime_type;
        attach_info_p[i].drm_subtype = stor_attach_info.drm_mime_subtype;*/
        memcpy(attach_info_p[i].cid, stor_attach_info.cid, SRV_EMAIL_CID_MAX_LEN + 1);
        size = strlen(stor_attach_info.file_name);
        if (size >= EMAIL_STOR_ENCOD_FILE_NAME_LEN)
        {
            if (stor_attach_info.file_name[0] == '=' && stor_attach_info.file_name[1] == '?')
            {
                stor_attach_info.file_name[EMAIL_STOR_ENCOD_FILE_NAME_LEN - 2] = '?';
                stor_attach_info.file_name[EMAIL_STOR_ENCOD_FILE_NAME_LEN - 1] = '=';
            }
        }
        attach_info_p[i].name_len = (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2;
        srv_email_string_decode(
            (WCHAR*)stor_attach_info.file_name,
            attach_info_p[i].name,
            &attach_info_p[i].name_len,
            &attach_info_p[i].charset);
        stor_result = srv_email_stor_msg_get_attch_path(
                        stor_attach_info.attch_id,
                        attach_info_p[i].path,
                        SRV_EMAIL_MAX_FILE_NAME_LEN + 1);
        if (stor_result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_stor_msg_get_attch_close(msg_object->stor_handle);
            msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            return stor_result;
        }
        *number = i + 1;

        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_MSG_GET_ATTACH_INFO_DETAIL,
            i,
            attach_info_p[i].size,
            attach_info_p[i].mime_type,
            attach_info_p[i].mime_subtype);
    }
    srv_email_stor_msg_get_attch_close(msg_object->stor_handle);
    msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_attachment_path
 * DESCRIPTION
 *  This function is used to get path of certian attachment.
 * PARAMETERS
 *  msg_handle        : [IN]  The message handle
 *  get_attach_path_p : [IN/OUT]  Buffer to set parameter and get attachment path
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_attachment_path(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_ATTCH_ID attach_id,
                                WCHAR *attach_path_p,
                                U32 path_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (attach_path_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    return srv_email_stor_msg_get_attch_path(attach_id, attach_path_p, path_len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_permission
 * DESCRIPTION
 *  This function is used to get the editable permission.
 *  The instance can get the permission only when the email is opened by this instance only.
 *  After getting successfully, the permission can not be released until the handle is destroyed.
 *  The operations need to get permission are as follow:
 *  srv_email_msg_edi();
 * PARAMETERS
 *  msg_handle        : [IN]  The message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_permission(EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_PERMISSION, msg_handle, msg_object->access_state);
    if (msg_object->access_state == SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_READ)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    if (srv_email_om_get_msg_permission(msg_object->msg_id, SRV_EMAIL_OM_PERMISSION_WRITE))
    {
        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_EDIT;
        return SRV_EMAIL_RESULT_SUCC;
    }
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_able_to_get_permission
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_email_msg_able_to_get_permission(
                    EMAIL_MSG_ID msg_id,
                    srv_email_om_permission_type_enum permision_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flag = MMI_TRUE;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_ABLE_TO_GET_PERMISSION, msg_id, permision_type);
    if (permision_type == SRV_EMAIL_OM_PERMISSION_WRITE)
    {
        for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
        {
            if (srv_email_msg_cntx_p->msg_array[i].in_use &&
                srv_email_msg_cntx_p->msg_array[i].msg_id == msg_id)
            {
                if (flag)
                {
                    flag = MMI_FALSE;
                }
                else
                {
                    return MMI_FALSE;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
        {
            if (srv_email_msg_cntx_p->msg_array[i].in_use &&
                srv_email_msg_cntx_p->msg_array[i].msg_id == msg_id &&
                srv_email_msg_cntx_p->msg_array[i].state != SRV_EMAIL_MSG_ACCESS_STATE_READ)
            {
                return MMI_FALSE;
            }
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_basic_info
 * DESCRIPTION
 *  This function is used to update app data to message handle
 * PARAMETERS
 *  msg_handle        : [IN]  The message handle
 *  basic_info_p      : [IN]  The pointer point to the parameter struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_basic_info(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_update_basic_info_struct *basic_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (basic_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    msg_object->acct_id = basic_info_p->acct_id;
    msg_object->fldr_id = basic_info_p->fldr_id;
    msg_object->priority = basic_info_p->priority;
    msg_object->flag = basic_info_p->flag;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_UPDATE_BASIC_INFO,
        msg_handle,
        msg_object->acct_id,
        msg_object->fldr_id,
        msg_object->priority,
        msg_object->flag);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_reply_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_reply_to(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_struct *addr_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    memcpy(&(msg_object->reply_to_addr), addr_info_p, sizeof(srv_email_addr_struct));
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_sender
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_sender(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_struct *addr_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    memcpy(&(msg_object->sender_addr), addr_info_p, sizeof(srv_email_addr_struct));
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_recipient
 * DESCRIPTION
 *  This function is used to update app data to message handle
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  msg_update_p    : [IN]  The pointer point to the parameter struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_recipient(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_type_enum addr_type,
                                U32 addr_num,
                                srv_email_addr_struct *addr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    FS_HANDLE file_handle;
    S32 result;
    U32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_list == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_UPDATE_RECIPIENT,
        msg_handle,
        addr_type,
        addr_num);
    switch (addr_type)
    {
    case SRV_EMAIL_ADDR_TYPE_TO:
        file_handle = srv_email_msg_get_file_handle(
                        msg_object,
                        SRV_EMAIL_MSG_SAVE_ADDR_TO,
                        MMI_TRUE);
        if (file_handle < 0)
        {
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_Write(file_handle, addr_list, addr_num * sizeof(srv_email_addr_struct), &written);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        msg_object->to_addr_num = addr_num;
        break;
    case SRV_EMAIL_ADDR_TYPE_CC:
        file_handle = srv_email_msg_get_file_handle(
                        msg_object,
                        SRV_EMAIL_MSG_SAVE_ADDR_CC,
                        MMI_TRUE);
        if (file_handle < 0)
        {
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_Write(file_handle, addr_list, addr_num * sizeof(srv_email_addr_struct), &written);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        msg_object->cc_addr_num = addr_num;
        break;
    case SRV_EMAIL_ADDR_TYPE_BCC:
        file_handle = srv_email_msg_get_file_handle(
                        msg_object,
                        SRV_EMAIL_MSG_SAVE_ADDR_BCC,
                        MMI_TRUE);
        if (file_handle < 0)
        {
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_Write(file_handle, addr_list, addr_num * sizeof(srv_email_addr_struct), &written);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        msg_object->bcc_addr_num = addr_num;
        break;
    default:
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_attach
 * DESCRIPTION
 *  This function is used to update app data to message handle
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  attach_num      : [IN]  Number of attachment
 *  attach_info_p   : [IN]
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_attach(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 attach_num,
                                srv_email_attach_struct *attach_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    FS_HANDLE file_handle;
    WCHAR *file_path;
    S32 result;
    U32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (attach_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_UPDATE_ATTACH,
        msg_handle,
        attach_num);
    if (attach_num == 0)
    {
        file_path = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
        msg_object->attach_num = 0;
        srv_email_msg_get_file_path(
            file_path,
            SRV_EMAIL_MAX_FILE_NAME_LEN + 1,
            msg_object,
            SRV_EMAIL_MSG_SAVE_ATTACHMENT_INFO);
        result = FS_Delete(file_path);
        free_ctrl_buffer(file_path);
        msg_object->attach_num = attach_num;
        return SRV_EMAIL_RESULT_SUCC;
    }
    file_handle = srv_email_msg_get_file_handle(
                    msg_object,
                    SRV_EMAIL_MSG_SAVE_ATTACHMENT_INFO,
                    MMI_TRUE);
    if (file_handle < 0)
    {
        srv_email_errno_set(file_handle);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    result = FS_Write(
                file_handle,
                attach_info_p,
                attach_num * sizeof(srv_email_attach_struct),
                &written);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR)
    {
        srv_email_errno_set(result);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    msg_object->attach_num = attach_num;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_subject
 * DESCRIPTION
 *  This function is used to update app data to message handle
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  subject         : [IN]  Buffer to store subject
 *  charset         : [IN]  charset of subject
 *  len             : [IN]  The length of subject
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_subject(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *subject,
                                S32 charset,
                                U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    FS_HANDLE file_handle;
    S32 result;
    U32 written;
    WCHAR *file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (subject == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT &&
        msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_PARSING)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_UPDATE_SUBJECT,
        msg_handle,
        len,
        charset);
    if (len == 0)
    {
        file_name = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
        srv_email_msg_get_file_path(file_name, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, SRV_EMAIL_MSG_SAVE_SUBJECT);
        result = FS_Delete(file_name);
        free_ctrl_buffer(file_name);
        msg_object->subject_charset = charset;
        return SRV_EMAIL_RESULT_SUCC;
    }
    file_handle = srv_email_msg_get_file_handle(
                    msg_object,
                    SRV_EMAIL_MSG_SAVE_SUBJECT,
                    MMI_TRUE);
    if (file_handle < 0)
    {
        srv_email_errno_set(file_handle);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    result = FS_Write(file_handle, subject, len * sizeof(WCHAR), &written);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR)
    {
        srv_email_errno_set(result);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    msg_object->subject_charset = charset;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_content
 * DESCRIPTION
 *  This function is used to update app data to message handle
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  content_info_p  : [IN]  Point to the content info
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_content(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_update_content_struct *content_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE file_handle;
    S32 result;
    U32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (content_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_UPDATE_CONTENT,
        msg_handle,
        content_info_p->buff_type,
        content_info_p->buff_len,
        content_info_p->charset);
    if (content_info_p->buff_type)
    {
        file_handle = srv_email_msg_get_file_handle(
                        msg_object,
                        SRV_EMAIL_MSG_SAVE_CONTENT,
                        MMI_TRUE);
        if (file_handle < 0)
        {
            srv_email_errno_set(file_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        result = FS_Write(
                    file_handle,
                    content_info_p->buff,
                    content_info_p->buff_len * sizeof(WCHAR),
                    &written);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        msg_object->content_charset = content_info_p->charset;
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, SRV_EMAIL_MSG_SAVE_CONTENT);
        FS_Delete(file_path);
        result = FS_Move(
                    content_info_p->buff,
                    file_path,
                    FS_MOVE_COPY | FS_MOVE_OVERWRITE,
                    NULL,
                    NULL,
                    0);
        if (result != FS_NO_ERROR)
        {
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        msg_object->content_charset = content_info_p->charset;
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_set_flag(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 flag_mask,
                                EMAIL_MSG_FLAG flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum result;
    EMAIL_MSG_FLAG temp_flag;
    EMAIL_MSG_FLAG dest_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_SET_FLAG,
        msg_handle,
        flag_mask,
        flag);
    result = srv_email_stor_fldr_set_msg_flag_open(
                SRV_EMAIL_FLDR_TYPE_INBOX,
                msg_object->acct_id,
                msg_object->fldr_id,
                flag_mask,
                flag,
                &msg_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    result = srv_email_stor_fldr_set_msg_flag_next(msg_object->stor_handle, msg_object->msg_id);
    srv_email_stor_fldr_set_msg_flag_close(msg_object->stor_handle);
    msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    /* should get flag from om notify function */
    temp_flag = flag;
    temp_flag &= flag_mask;
    dest_flag = msg_object->flag;
    dest_flag &= ~flag_mask;
    dest_flag |= temp_flag;
    msg_object->flag = dest_flag;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_save
 * DESCRIPTION
 *  This function is used to update the email information of handle into storage.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  save_part       : [IN]  Indicate which part app want to save to storage
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_save(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_save_part_enum save_part,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE, msg_handle);
    return srv_email_msg_save_int(msg_handle, NULL, NULL, save_part, req_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_save_new
 * DESCRIPTION
 *  This function is used to create a new message with the information of current msg object
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  dest_acct_id     : [IN]  The destination account id
 *  dest_fldr_id      : [IN]  The destination folder id
 *  new_msg_id     : [OUT] The message id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_save_new(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_ACCT_ID dest_acct_id,
                                EMAIL_FLDR_ID dest_fldr_id,
                                EMAIL_MSG_ID *msg_id,
                                EMAIL_REQ_ID *req_id)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE_NEW, msg_handle);
    return srv_email_msg_save_new_int(msg_handle, NULL, NULL, dest_acct_id, dest_fldr_id, msg_id, req_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_send
 * DESCRIPTION
 *  This function is used to send the specified email.
 *  The email in outbox can be sent only.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_send(
                                EMAIL_MSG_HANDLE msg_handle,
                                MMI_BOOL move_to_sent,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    srv_email_msg_info_struct *msg_object;
    srv_email_msg_nwk_notify_struct *notify_data;
    srv_email_nwk_send_struct send_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_READ &&
        msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SEND, msg_handle, move_to_sent);
    result = srv_email_nwk_create(
                msg_object->acct_id,
                MMI_FALSE,
                &msg_object->nwk_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    notify_data = (srv_email_msg_nwk_notify_struct*)srv_email_mem_alloc(sizeof(srv_email_msg_nwk_notify_struct));
    if (notify_data == NULL)
    {
        srv_email_nwk_destroy(msg_object->nwk_handle);
        msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    notify_data->msg_object = msg_object;
    notify_data->org_access_state = msg_object->access_state;
    notify_data->move_to_sent = move_to_sent;
    result = srv_email_nwk_set_process_notify(
                msg_object->nwk_handle,
                srv_email_msg_nwk_proc_func,
                msg_object);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(msg_object->nwk_handle);
        msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        srv_email_mem_free(notify_data);
        return result;
    }
    result =  srv_email_nwk_set_finish_notify(
                msg_object->nwk_handle,
                srv_email_msg_nwk_finish_callback,
                notify_data);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(msg_object->nwk_handle);
        msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        srv_email_mem_free(notify_data);
        return result;
    }
    send_info.send_outbox = MMI_FALSE;
    send_info.msg_handle = msg_handle;
    send_info.msg_id = msg_object->msg_id;
    result =  srv_email_nwk_send(msg_object->nwk_handle, &send_info);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SEND_RESULT, result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (!srv_email_msg_get_req_id(
                    msg_object,
                    SRV_EMAIL_NWK_SEND,
                    notify_data,
                    req_id,
                    &notify_data->req_id))
            {
                srv_email_mem_free(notify_data);
                srv_email_nwk_destroy(msg_object->nwk_handle);
                msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_FAIL;
            }
            msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_NET_OPERATING;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            srv_email_nwk_destroy(msg_object->nwk_handle);
            msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
            srv_email_mem_free(notify_data);
            return result;
        }
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_retrieve
 * DESCRIPTION
 *  This function is used to retrieve the specified email.
 *  The instance with the permission can retrieve the email only.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_retrieve(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_retrieve_option_enum retrieve_opt,
                                EMAIL_ATTCH_ID attach_id,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    srv_email_msg_info_struct *msg_object;
    srv_email_msg_nwk_notify_struct *notify_data;
    srv_email_nwk_retr_struct nwk_retr_opt;
    srv_email_acct_info_struct *account_info;
    srv_email_stor_cont_header_struct *content_header;
    srv_email_stor_attch_struct *stor_attach_info;
    S32 retrieved_size = 0;
    S32 not_retrieved_size = 0;
    S32 download_size = 0;
    S32 dst_size = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_READ &&
        msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_RETRIEVE, msg_handle, msg_object->msg_id, retrieve_opt, attach_id);
    account_info = (srv_email_acct_info_struct*)get_ctrl_buffer(sizeof(srv_email_acct_info_struct));
    account_info->acct_id = msg_object->acct_id;
    result = srv_email_stor_acct_info_read(account_info);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(account_info);
        return result;
    }
    download_size = account_info->download_size;
    free_ctrl_buffer(account_info);
    result = srv_email_msg_get_retrieve_size(msg_object, &retrieved_size, &not_retrieved_size);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    dst_size = retrieved_size;
    switch (retrieve_opt)
    {
    case SRV_EMAIL_RETRIEVE_ALL_PARTS:
        dst_size += not_retrieved_size;
        break;
    case SRV_EMAIL_RETRIEVE_TEXT_CONTENT:
    case SRV_EMAIL_RETRIEVE_HTML_CONTENT:
        content_header = (srv_email_stor_cont_header_struct*)get_ctrl_buffer(sizeof(srv_email_stor_cont_header_struct));
        if (retrieve_opt == SRV_EMAIL_RETRIEVE_TEXT_CONTENT)
        {
            result = srv_email_stor_msg_get_cont(
                        msg_object->msg_id,
                        SRV_EMAIL_STOR_MSG_CONT_TEXT,
                        content_header,
                        NULL,
                        NULL);
        }
        else
        {
            result = srv_email_stor_msg_get_cont(
                        msg_object->msg_id,
                        SRV_EMAIL_STOR_MSG_CONT_HTML,
                        content_header,
                        NULL,
                        NULL);
        }
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            free_ctrl_buffer(content_header);
            return result;
        }
        if (content_header->download_flag == MMI_TRUE)
        {
            free_ctrl_buffer(content_header);
            return SRV_EMAIL_RESULT_SUCC;
        }
        else
        {
            dst_size += content_header->server_size;
            free_ctrl_buffer(content_header);
        }
        break;
    case SRV_EMAIL_RETRIEVE_ALL_CONTENT:
        content_header = (srv_email_stor_cont_header_struct*)get_ctrl_buffer(sizeof(srv_email_stor_cont_header_struct));
        result = srv_email_stor_msg_get_cont(
                    msg_object->msg_id,
                    SRV_EMAIL_STOR_MSG_CONT_TEXT,
                    content_header,
                    NULL,
                    NULL);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            free_ctrl_buffer(content_header);
            return result;
        }
        if (content_header->download_flag == MMI_TRUE)
        {
            dst_size += 0;
        }
        else
        {
            dst_size += content_header->server_size;
        }
        result = srv_email_stor_msg_get_cont(
                    msg_object->msg_id,
                    SRV_EMAIL_STOR_MSG_CONT_HTML,
                    content_header,
                    NULL,
                    NULL);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            free_ctrl_buffer(content_header);
            return result;
        }
        if (content_header->download_flag == MMI_TRUE)
        {
            dst_size += 0;
        }
        else
        {
            dst_size += content_header->server_size;
        }
        free_ctrl_buffer(content_header);
        break;
    case SRV_EMAIL_RETRIEVE_SINGLE_ATTACHMENT:
    case SRV_EMAIL_RETRIEVE_ALL_ATTACHMENT:
        stor_attach_info = (srv_email_stor_attch_struct*)get_ctrl_buffer(sizeof(srv_email_stor_attch_struct));
        result = srv_email_stor_msg_get_attch_open(
                    msg_object->msg_id,
                    0,
                    &msg_object->stor_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            free_ctrl_buffer(stor_attach_info);
            return result;
        }
        for (i = 0; i < msg_object->attach_num; i++)
        {
            result = srv_email_stor_msg_get_attch_next(msg_object->stor_handle, stor_attach_info);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_stor_msg_get_attch_close(msg_object->stor_handle);
                msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                free_ctrl_buffer(stor_attach_info);
                return result;
            }
            if (retrieve_opt == SRV_EMAIL_RETRIEVE_SINGLE_ATTACHMENT)
            {
                if (stor_attach_info->attch_id == attach_id)
                {
                    srv_email_stor_msg_get_attch_close(msg_object->stor_handle);
                    msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                    if (stor_attach_info->download_flag == MMI_TRUE)
                    {
                        free_ctrl_buffer(stor_attach_info);
                        return SRV_EMAIL_RESULT_SUCC;
                    }
                    else
                    {
                        dst_size += stor_attach_info->server_size;
                        break;
                    }
                }
            }
            else
            {
                if (stor_attach_info->download_flag == MMI_TRUE)
                {
                    dst_size += 0;
                }
                else
                {
                    dst_size += stor_attach_info->server_size;
                }
            }
        }
        srv_email_stor_msg_get_attch_close(msg_object->stor_handle);
        msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        free_ctrl_buffer(stor_attach_info);
        break;
    default:
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    if (dst_size > download_size)
    {
        return SRV_EMAIL_RESULT_MSG_EXCEED_DOWNLOAD_SIZE;
    }
    result = srv_email_nwk_create(
                msg_object->acct_id,
                MMI_TRUE,
                &msg_object->nwk_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    notify_data = (srv_email_msg_nwk_notify_struct*)srv_email_mem_alloc(sizeof(srv_email_msg_nwk_notify_struct));
    if (notify_data == NULL)
    {
        srv_email_nwk_destroy(msg_object->nwk_handle);
        msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        srv_email_mem_free(notify_data);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    notify_data->msg_object = msg_object;
    notify_data->org_access_state = msg_object->access_state;
    notify_data->move_to_sent = MMI_FALSE;
    result = srv_email_nwk_set_process_notify(
                msg_object->nwk_handle,
                srv_email_msg_nwk_proc_func,
                msg_object);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(msg_object->nwk_handle);
        msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        srv_email_mem_free(notify_data);
        return result;
    }
    result =  srv_email_nwk_set_finish_notify(
                msg_object->nwk_handle,
                srv_email_msg_nwk_finish_callback,
                notify_data);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_nwk_destroy(msg_object->nwk_handle);
        msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
        srv_email_mem_free(notify_data);
        return result;
    }
    nwk_retr_opt.fldr_id = msg_object->fldr_id;
    nwk_retr_opt.msg_id = msg_object->msg_id;
    nwk_retr_opt.retr_opt = retrieve_opt;
    nwk_retr_opt.attach_id = attach_id;
    result =  srv_email_nwk_retrieve(msg_object->nwk_handle, &nwk_retr_opt);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_RETRIEVE_RESULT, result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (!srv_email_msg_get_req_id(
                    msg_object,
                    SRV_EMAIL_NWK_RETRIEVE,
                    notify_data,
                    req_id,
                    &notify_data->req_id))
            {
                srv_email_mem_free(notify_data);
                srv_email_nwk_destroy(msg_object->nwk_handle);
                msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_FAIL;
            }
            msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_NET_OPERATING;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            srv_email_nwk_destroy(msg_object->nwk_handle);
            msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
            srv_email_mem_free(notify_data);
            return result;
        }
    }
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_retrieve_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
static srv_email_result_enum srv_email_msg_get_retrieve_size(
                                srv_email_msg_info_struct *msg_object,
                                S32 *retrieved_size,
                                S32 *not_retrieved_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    srv_email_stor_cont_header_struct *content_header;
    srv_email_stor_attch_struct *stor_attach_info;
    S32 download_size = 0;
    S32 not_download_size = 0;
    S32 i;
    srv_email_acct_info_cache_struct *cache_data = NULL;
    srv_email_prot_type_enum protocol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cache_data = (srv_email_acct_info_cache_struct*)get_ctrl_buffer(sizeof(srv_email_acct_info_cache_struct));
    srv_email_acct_cache_get(msg_object->acct_id, cache_data);
    protocol = cache_data->protocol;
    free_ctrl_buffer(cache_data);

    if (protocol == SRV_EMAIL_PROT_POP3)
    {
        if (msg_object->state & SRV_EMAIL_MSG_STATE_DOWN_ALL)
        {
            *not_retrieved_size = 0;
        }
        else
        {
            *not_retrieved_size = msg_object->server_size - msg_object->local_size;
        }
        *retrieved_size = msg_object->local_size;
        return SRV_EMAIL_RESULT_SUCC;
    }

    /* content parts */
    content_header = (srv_email_stor_cont_header_struct*)get_ctrl_buffer(sizeof(srv_email_stor_cont_header_struct));
    result = srv_email_stor_msg_get_cont(
                msg_object->msg_id,
                SRV_EMAIL_STOR_MSG_CONT_TEXT,
                content_header,
                NULL,
                NULL);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(content_header);
        return result;
    }
    if (content_header->download_flag == MMI_TRUE)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        download_size += content_header->local_size;
    #else
        download_size += content_header->server_size;
    #endif /* __COSMOS_MMI_PACKAGE__ */
    }
    else
    {
        not_download_size += content_header->server_size;
    }
    result = srv_email_stor_msg_get_cont(
        msg_object->msg_id,
        SRV_EMAIL_STOR_MSG_CONT_HTML,
        content_header,
        NULL,
        NULL);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(content_header);
        return result;
    }
    if (content_header->download_flag == MMI_TRUE)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        download_size += content_header->local_size;
    #else
        download_size += content_header->server_size;
    #endif /* __COSMOS_MMI_PACKAGE__ */
    }
    else
    {
        not_download_size += content_header->server_size;
    }
    free_ctrl_buffer(content_header);

    /* attachment part */
    stor_attach_info = (srv_email_stor_attch_struct*)get_ctrl_buffer(sizeof(srv_email_stor_attch_struct));
    result = srv_email_stor_msg_get_attch_open(
                msg_object->msg_id,
                0,
                &msg_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        free_ctrl_buffer(stor_attach_info);
        return result;
    }
    for (i = 0; i < msg_object->attach_num; i++)
    {
        result = srv_email_stor_msg_get_attch_next(msg_object->stor_handle, stor_attach_info);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_stor_msg_get_attch_close(msg_object->stor_handle);
            msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
            free_ctrl_buffer(stor_attach_info);
            return result;
        }
        if (stor_attach_info->download_flag == MMI_TRUE)
        {
            download_size += stor_attach_info->server_size;
        }
        else
        {
            not_download_size += stor_attach_info->server_size;
        }
    }
    srv_email_stor_msg_get_attch_close(msg_object->stor_handle);
    msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    free_ctrl_buffer(stor_attach_info);
    if (retrieved_size != NULL)
    {
        *retrieved_size = download_size;
    }
    if (not_retrieved_size != NULL)
    {
        *not_retrieved_size = not_download_size;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_delete
 * DESCRIPTION
 *  This function is used to delete the specified email.
 *  The email only used by this instance can be deleted.
 *  After operation, msg handle will be invalid
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  delete_server   : [IN]  Delete the email from local and server together or not
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_delete(
                                EMAIL_MSG_HANDLE msg_handle,
                                MMI_BOOL delete_header,
                                MMI_BOOL delete_server)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum result;
    srv_email_result_enum close_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_DELETE, msg_handle, msg_object->msg_id, delete_header, delete_server);
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_READ &&
        msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT &&
        msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_INIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    result = srv_email_stor_fldr_del_msg_open(
        SRV_EMAIL_FLDR_TYPE_INVALID,
        msg_object->acct_id,
        msg_object->fldr_id,
        delete_header,
        delete_server,
        &msg_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    result = srv_email_stor_fldr_del_msg_next(
                msg_object->stor_handle,
                msg_object->msg_id);
    close_result = srv_email_stor_fldr_del_msg_close(msg_object->stor_handle);
    msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_DELETE_RESULT, result);
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


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_move
 * DESCRIPTION
 *  This function is used to move the specified email into the specified account and folder.
 *  The email only used by this instance can be moved.
 *  If operation success, msg handle will be invalid
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_move(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_ACCT_ID dst_acct_id,
                                EMAIL_FLDR_ID dst_fldr_id,
                                EMAIL_MSG_ID *new_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_MOVE, msg_handle, msg_object->msg_id, dst_acct_id, dst_fldr_id);
    result =  srv_email_stor_msg_move(msg_object->msg_id, dst_acct_id, dst_fldr_id, new_msg_id);
    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        msg_object->acct_id = dst_acct_id;
        msg_object->fldr_id = dst_fldr_id;
        msg_object->msg_id = *new_msg_id;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_MOVE_RESULT, result, *new_msg_id);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_copy
 * DESCRIPTION
 *  This function is used to copy the specified email into the specified account and folder.
 *  The email's information in this instance will be stored as a new email.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  msg_copy_p      : [IN]  The pointer point to the parameter struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_copy(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_copy_struct *msg_copy_p,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum result;
    srv_email_msg_copy_notify_struct *notify_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_copy_p == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    /* TRACE access_state */
    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_READ &&
        msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_COPY,
        msg_handle,
        msg_object->msg_id,
        msg_copy_p->dst_acct_id,
        msg_copy_p->dst_fldr_id);
    notify_data = (srv_email_msg_copy_notify_struct*)srv_email_mem_alloc(sizeof(srv_email_msg_copy_notify_struct));
    notify_data->msg_object = msg_object;
    result = srv_email_stor_msg_copy(
                msg_object->msg_id,
                msg_copy_p->dst_acct_id,
                msg_copy_p->dst_fldr_id,
                &msg_copy_p->dst_msg_id,
                req_id,
                srv_email_msg_copy_callback,
                notify_data);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_COPY_RESULT, result, msg_copy_p->dst_msg_id);
    if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        if (!srv_email_msg_get_req_id(
                msg_object,
                SRV_EMAIL_MSG_OPERATION_COPY,
                notify_data,
                req_id,
                &notify_data->req_id))
        {
            srv_email_mem_free(notify_data);
            return SRV_EMAIL_RESULT_FAIL;
        }
        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_LOCAL_OPERATING;
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    srv_email_mem_free(notify_data);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_abort
 * DESCRIPTION
 *  This function is used to abort the async request for the specified message instance.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  req_id          : [IN]  The async request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_abort(EMAIL_MSG_HANDLE msg_handle, EMAIL_REQ_ID req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_msg_mime_parser_info_struct *parser_info;
    srv_email_msg_get_html_path_struct *get_html_op;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    for (i = 0; i < SRV_EMAIL_MESSAGE_REQ_MAX_NUMBER; i++)
    {
        if (msg_object->req_id_action_map_list[i].req_id == req_id)
        {
            break;
        }
    }
    if (i == SRV_EMAIL_MESSAGE_REQ_MAX_NUMBER)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_ABORT, msg_handle, req_id, msg_object->req_id_action_map_list[i].action);

    if (msg_object->req_id_action_map_list[i].action == SRV_EMAIL_NWK_SEND ||
        msg_object->req_id_action_map_list[i].action == SRV_EMAIL_NWK_RETRIEVE)
    {
        srv_email_nwk_abort(msg_object->nwk_handle);
    }
    else if (msg_object->req_id_action_map_list[i].action == SRV_EMAIL_MSG_OPERATION_COPY)
    {
        srv_email_stor_msg_copy_abort(msg_object->req_id_action_map_list[i].req_id);
    }
    else if (msg_object->req_id_action_map_list[i].action == SRV_EMAIL_MSG_OPERATION_SAVE)
    {
        srv_email_stor_msg_update_abort(msg_object->stor_handle);
        msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    }
    else if (msg_object->req_id_action_map_list[i].action == SRV_EMAIL_MSG_OPERATION_SAVE_NEW)
    {
        srv_email_stor_msg_create_abort(msg_object->stor_handle);
        msg_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    }
    else if(msg_object->req_id_action_map_list[i].action == SRV_EMAIL_MSG_OPERATION_PARSE)
    {
        parser_info = msg_object->req_id_action_map_list[i].operation_info;
        parser_info->canceled = MMI_TRUE;
    }
    else if (msg_object->req_id_action_map_list[i].action == SRV_EMAIL_MSG_OPERATION_GET_HTML)
    {
        get_html_op = msg_object->req_id_action_map_list[i].operation_info;
        if (get_html_op->copy_only)
        {
            srv_fmgr_async_abort(get_html_op->fs_job_id, MMI_TRUE);
        }
        else
        {
            srv_email_file_convert_abort(get_html_op->convert_handle);
        }
        srv_email_mem_free(get_html_op);
        msg_object->req_id_action_map_list[i].operation_info = NULL;
    }

    if (msg_object->req_id_action_map_list[i].operation_info != NULL &&
        msg_object->req_id_action_map_list[i].action != SRV_EMAIL_MSG_OPERATION_PARSE &&
        msg_object->req_id_action_map_list[i].action != SRV_EMAIL_MSG_OPERATION_GET_HTML)
    {
        srv_email_mem_free(msg_object->req_id_action_map_list[i].operation_info);
        msg_object->req_id_action_map_list[i].operation_info = NULL;
    }
    msg_object->req_id_action_map_list[i].action = SRV_EMAIL_NWK_NONE;
    msg_object->req_id_action_map_list[i].req_id = 0;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_handle_to_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
srv_email_msg_info_struct *srv_email_msg_handle_to_addr(EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = (srv_email_msg_info_struct*)msg_handle;
    for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
    {
        if (msg_object == &srv_email_msg_cntx_p->msg_array[i] &&
            srv_email_msg_cntx_p->msg_array[i].in_use)
        {
            return msg_object;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_file_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static FS_HANDLE srv_email_msg_get_file_handle(
                    srv_email_msg_info_struct *msg_object,
                    srv_email_msg_save_part_enum part,
                    MMI_BOOL create_always)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_path == NULL)
    {
        return -1;
    }
    memset(file_path, 0, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, part);
    if (create_always)
    {
        FS_Delete(file_path);
        file_handle = FS_Open(file_path, FS_CREATE_ALWAYS);
    }
    else
    {
        file_handle = FS_Open(file_path, FS_READ_ONLY);
    }
    return file_handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
void srv_email_msg_get_file_path(
                    WCHAR *buff,
                    U16 len,
                    srv_email_msg_info_struct *msg_object,
                    srv_email_msg_save_part_enum part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (part >= SRV_EMAIL_MSG_SAVE_TOTAL)
    {
        return;
    }
    for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
    {
        if (msg_object == &srv_email_msg_cntx_p->msg_array[i])
        {
            break;
        }
    }
    if (i == SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER)
    {
        return;
    }
    kal_wsprintf(buff, "%s%s%d\\%s", srv_email_get_root_path(), message_path, i + 1, g_file_name[part]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_file_path_comp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern void srv_email_msg_get_file_path_comp(
                EMAIL_MSG_HANDLE msg_handle,
                srv_email_msg_save_part_enum part,
                WCHAR *buff,
                U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    srv_email_msg_info_struct *msg_object;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_FILE_PATH_COMP, msg_handle);
    srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, part);
    if (len <= (U32)mmi_wcslen(file_path))
    {
        return;
    }
    mmi_wcscpy(buff, file_path);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_query_text_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_msg_query_text_func(
                srv_eamil_msg_text_type_enum type,
                srv_email_stor_cont_header_struct *cont_header,
                void *buff,
                U32 buff_size,
                S32 *keep_src,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    srv_email_msg_save_info_struct *save_info;
    srv_email_msg_info_struct *msg_object;
    srv_email_msg_save_part_enum save_part;
    CHAR *temp_text;
    CHAR *temp_text_2;
    WCHAR *file_name;
    S32 result;
    U32 size;
    U32 read;
    S32 temp;
    MMI_BOOL local_mail = MMI_TRUE;
    srv_email_fldr_type_enum fldr_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buff == NULL)
    {
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_QUERY_TEXT, type, buff_size);
    save_info = (srv_email_msg_save_info_struct*)user_data;
    msg_object = save_info->msg_object;

    if (type == SRV_EMAIL_MSG_TEXT_SUBJ)
    {
        file_handle = srv_email_msg_get_file_handle(
                        msg_object,
                        SRV_EMAIL_MSG_SAVE_SUBJECT,
                        MMI_FALSE);
        if (file_handle < 0)
        {
            return;
        }
        result = FS_GetFileSize(file_handle, &size);
        if (result != FS_NO_ERROR)
        {
            FS_Close(file_handle);
            return;
        }
        temp_text = (CHAR*)get_ctrl_buffer(size + 2);
        memset(temp_text, 0, size + 2);
        temp_text_2 = (CHAR*)get_ctrl_buffer((size + 2) * 2);
        memset(temp_text_2, 0, (size + 2) * 2);
        result = FS_Read(file_handle, temp_text, size + 2, &read);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            free_ctrl_buffer(temp_text);
            free_ctrl_buffer(temp_text_2);
            return;
        }
        temp = buff_size;
        if (msg_object->subject_charset > MMI_CHSET_BASE && msg_object->subject_charset < MMI_CHSET_TOTAL)
        {
            if (msg_object->subject_charset != CHSET_UTF8 && msg_object->subject_charset != CHSET_ASCII)
            {
                mmi_chset_convert((mmi_chset_enum)msg_object->subject_charset, CHSET_UTF8, (CHAR*)temp_text, (CHAR*)temp_text_2, (size + 2) * 2);
                msg_object->subject_charset = CHSET_UTF8;
            }
            else
            {
                memcpy(temp_text_2, temp_text, strlen(temp_text));
            }
            rfc2047_encode_string((kal_int8*)temp_text_2, strlen(temp_text_2), buff, &temp, 0, msg_object->subject_charset);
        }
        else
        {
            rfc2047_encode_string((kal_int8*)temp_text, strlen(temp_text), buff, &temp, 0, 0);
        }
        free_ctrl_buffer(temp_text);
        free_ctrl_buffer(temp_text_2);
    }
    else
    {
        cont_header->server_size = msg_object->server_size;
        if (type == SRV_EMAIL_MSG_TEXT_CONT_TEXT)
        {
            save_part = SRV_EMAIL_MSG_SAVE_CONTENT;
        }
        else
        {
            save_part = SRV_EMAIL_MSG_SAVE_HTML;
        }
        file_handle = srv_email_msg_get_file_handle(
                        msg_object,
                        save_part,
                        MMI_FALSE);
        if (file_handle < 0)
        {
            cont_header->this_part_exist = MMI_FALSE;
            cont_header->download_flag = MMI_FALSE;
            if (save_part == SRV_EMAIL_MSG_SAVE_CONTENT)
            {
                kal_sprintf(cont_header->charset, "ISO-10646-UCS-2"); /* UCS2 */
                kal_sprintf(cont_header->content_type, "PLAIN"); /* TBD */
            }
            else
            {
                kal_sprintf(cont_header->charset, "ISO-10646-UCS-2"); /* UCS2 */
                kal_sprintf(cont_header->content_type, "HTML"); /* TBD */
            }
            return;
        }
        FS_Close(file_handle);

        /* when create a local mail, the {acct_id} and {fldr_id} is 0 */
        if (msg_object->acct_id != EMAIL_ACCT_INVALID_ID &&
            msg_object->fldr_id != EMAIL_FLDR_INVALID_ID)
        {
            fldr_type = srv_email_fldr_id_to_fldr_type(msg_object->acct_id,
                                                       msg_object->fldr_id);
            if (fldr_type == SRV_EMAIL_FLDR_TYPE_INBOX ||
                fldr_type == SRV_EMAIL_FLDR_TYPE_REMOTE)
            {
                local_mail = MMI_FALSE;
            }
        }
    
        // for local mails, set it as non-HTML mail
        if (local_mail && save_part == SRV_EMAIL_MSG_SAVE_HTML)
        {
            cont_header->this_part_exist = MMI_FALSE;
            cont_header->download_flag = MMI_FALSE;
        }
        else
        {
            cont_header->this_part_exist = MMI_TRUE;
            cont_header->download_flag = MMI_TRUE;
        }
        if (save_part == SRV_EMAIL_MSG_SAVE_CONTENT)
        {
            kal_sprintf(cont_header->charset, "%s", chset_get_preferred_mime_name((chset_enum)msg_object->content_charset));
            kal_sprintf(cont_header->content_type, "PLAIN"); /* TBD */
        }
        else
        {
            kal_sprintf(cont_header->charset, "%s", chset_get_preferred_mime_name((chset_enum)msg_object->html_charset));
            kal_sprintf(cont_header->content_type, "HTML"); /* TBD */
        }
        file_name = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
        memset(file_name, 0, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
        srv_email_msg_get_file_path(
            file_name,
            SRV_EMAIL_MAX_FILE_NAME_LEN + 1,
            msg_object,
            save_part);
        if (buff_size > (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2)
        {
            memcpy(buff, file_name, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
        }
        else
        {
            memcpy(buff, file_name, buff_size);
        }
        *keep_src = 0;
        free_ctrl_buffer(file_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_file_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_msg_query_addr_func(
                srv_email_addr_type_enum type,
                U16 index,
                srv_email_stor_addr_struct *data,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = -1;
    srv_email_msg_save_info_struct *save_info;
    srv_email_addr_struct *addr;
    S32 result;
    U32 read;
    CHAR *temp_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return;
    }
    addr = (srv_email_addr_struct*)get_ctrl_buffer(sizeof(srv_email_addr_struct));
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_QUERY_ADDR, type, index);
    memset(addr, 0, sizeof(srv_email_addr_struct));
    save_info = (srv_email_msg_save_info_struct*)user_data;
    if (type == SRV_EMAIL_ADDR_TYPE_FROM)
    {
        memcpy(addr, &save_info->msg_object->sender_addr, sizeof(srv_email_addr_struct));
    }
    else if (type == SRV_EMAIL_ADDR_TYPE_REPLY_TO)
    {
        memcpy(addr, &save_info->msg_object->reply_to_addr, sizeof(srv_email_addr_struct));
    }
    else
    {
        switch (type)
        {
        case SRV_EMAIL_ADDR_TYPE_TO:
            file_handle = srv_email_msg_get_file_handle(save_info->msg_object,SRV_EMAIL_MSG_SAVE_ADDR_TO, MMI_FALSE);
            break;
        case SRV_EMAIL_ADDR_TYPE_CC:
            file_handle = srv_email_msg_get_file_handle(save_info->msg_object,SRV_EMAIL_MSG_SAVE_ADDR_CC, MMI_FALSE);
            break;
        case SRV_EMAIL_ADDR_TYPE_BCC:
            file_handle = srv_email_msg_get_file_handle(save_info->msg_object,SRV_EMAIL_MSG_SAVE_ADDR_BCC, MMI_FALSE);
            break;
        }
        if (file_handle < 0)
        {
            free_ctrl_buffer(addr);
            return;
        }
        result = FS_Seek(
                    file_handle,
                    sizeof(srv_email_addr_struct) * index,
                    FS_FILE_BEGIN);
        if (result < 0)
        {
            FS_Close(file_handle);
            free_ctrl_buffer(addr);
            return;
        }
        result = FS_Read(file_handle, addr, sizeof(srv_email_addr_struct), &read);
        FS_Close(file_handle);
        if (result != FS_NO_ERROR)
        {
            free_ctrl_buffer(addr);
            return;
        }
    }
    addr->disp_name_len = EMAIL_MAX_ENCODED_DISP_NAME_LEN;
    if (mmi_wcslen(addr->disp_name) != 0)
    {
        temp_name = (CHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 3);
        memset(temp_name, 0, (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 3);
        mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (CHAR*)addr->disp_name, temp_name, (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 3);
        rfc2047_encode_string((kal_int8*)temp_name, strlen(temp_name), (kal_int8*)data->disp_name, &addr->disp_name_len, 0, CHSET_UTF8);
        free_ctrl_buffer(temp_name);
    }
    else
    {
        data->disp_name[0] = 0;
    }
    mmi_ucs2_to_asc(data->email_addr, (CHAR*)addr->email_addr);
    free_ctrl_buffer(addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_query_attach_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_msg_query_attach_func(
                U16 index,
                void *buff,
                U32 buff_size,
                S32 *keep_src,
                srv_email_stor_attch_query_type_enum type,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    srv_email_msg_save_info_struct *save_info;
    srv_email_attach_struct *attach_info;
    srv_email_stor_attch_struct *stor_attach_info;
    S32 result;
    U32 read;
    CHAR *temp_name;
    CHAR *stor_temp_name;
    applib_mime_type_struct *mime_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buff == NULL)
    {
        return;
    }
    if (keep_src != NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_QUERY_ATTACH, type, index, *keep_src);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_QUERY_ATTACH, type, index, 0);
    }
    save_info = (srv_email_msg_save_info_struct*)user_data;
    file_handle = srv_email_msg_get_file_handle(save_info->msg_object, SRV_EMAIL_MSG_SAVE_ATTACHMENT_INFO, MMI_FALSE);
    if (file_handle < 0)
    {
        return;
    }
    attach_info = (srv_email_attach_struct*)get_ctrl_buffer(sizeof(srv_email_attach_struct));
    result = FS_Seek(
                file_handle,
                sizeof(srv_email_attach_struct) * index,
                FS_FILE_BEGIN);
    if (result < 0)
    {
        free_ctrl_buffer(attach_info);
        return;
    }
    result = FS_Read(file_handle, attach_info, sizeof(srv_email_attach_struct), &read);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR)
    {
        free_ctrl_buffer(attach_info);
        return;
    }
    if (type == SRV_EMAIL_STOR_ATTCH_QUERY_PATH)
    {
        *keep_src = MMI_FALSE;
        if (buff_size > (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2)
        {
            memcpy(buff, attach_info->path, (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
        }
        else
        {
            memcpy(buff, attach_info->path, buff_size);
        }
    }
    else
    {
        stor_attach_info = (srv_email_stor_attch_struct*)buff;
        stor_attach_info->attch_id = attach_info->attach_id;
        stor_attach_info->local_size = attach_info->size;
        stor_attach_info->server_size = attach_info->size;
        mime_p = applib_mime_type_look_up(NULL, NULL, 
            (applib_mime_type_enum)attach_info->mime_type,
            (applib_mime_subtype_enum)attach_info->mime_subtype);
        if (mime_p != NULL)
        {
            if (strlen(mime_p->mime_string) >= EMAIL_STOR_CONT_TYPE_STR_LEN + 1)
            {
                memcpy(stor_attach_info->content_type, mime_p->mime_string, EMAIL_STOR_CONT_TYPE_STR_LEN + 1);
            }
            else
            {
                memcpy(stor_attach_info->content_type, mime_p->mime_string, strlen(mime_p->mime_string));
            }
        }
        stor_attach_info->download_flag = attach_info->downloaded;
        stor_attach_info->drm = attach_info->drm_object;
        mime_p = applib_mime_type_look_up(NULL, NULL, 
            (applib_mime_type_enum)attach_info->drm_type, (applib_mime_subtype_enum)attach_info->drm_subtype);
        if (mime_p != NULL)
        {
            if (strlen(mime_p->mime_string) >= EMAIL_STOR_CONT_TYPE_STR_LEN + 1)
            {
                memcpy(stor_attach_info->drm_content_type, mime_p->mime_string, EMAIL_STOR_CONT_TYPE_STR_LEN + 1);
            }
            else
            {
                memcpy(stor_attach_info->drm_content_type, mime_p->mime_string, strlen(mime_p->mime_string));
            }
        }
        result = EMAIL_ATTCH_FILE_NAME_LEN * 4 + 20 + 1;
        if (mmi_wcslen(attach_info->name) != 0)
        {
            temp_name = (CHAR*)get_ctrl_buffer(EMAIL_ATTCH_FILE_NAME_LEN * 4 + 1);
            memset(temp_name, 0, EMAIL_ATTCH_FILE_NAME_LEN * 4 + 1);
            stor_temp_name = (CHAR*)get_ctrl_buffer(EMAIL_ATTCH_FILE_NAME_LEN * 4 + 20 + 1);
            memset(stor_temp_name, 0, EMAIL_ATTCH_FILE_NAME_LEN * 4 + 20 + 1);
            mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (CHAR*)attach_info->name, temp_name, EMAIL_ATTCH_FILE_NAME_LEN * 4 + 1);
            rfc2047_encode_string((kal_int8*)temp_name, strlen(temp_name), (kal_int8*)stor_temp_name, &result, 0, CHSET_UTF8);
            memcpy(stor_attach_info->file_name, stor_temp_name, EMAIL_STOR_ENCOD_FILE_NAME_LEN);
            free_ctrl_buffer(temp_name);
            free_ctrl_buffer(stor_temp_name);
        }
        else
        {
            stor_attach_info->file_name[0] = 0;
        }
        if (attach_info->cid[0] == '<' && attach_info->cid[strlen(attach_info->cid) - 1] == '>')
        {
            memset(stor_attach_info->cid, 0, SRV_EMAIL_CID_MAX_LEN);
            memcpy(stor_attach_info->cid, attach_info->cid + 1, strlen(attach_info->cid) - 2);
        }
        else
        {
            memcpy(stor_attach_info->cid, attach_info->cid, SRV_EMAIL_CID_MAX_LEN);
        }
    }
    free_ctrl_buffer(attach_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_save_new_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_msg_save_new_callback(srv_email_result_enum res, EMAIL_MSG_ID msg_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_save_info_struct *save_info;
    srv_email_msg_info_struct *msg_object;
    EMAIL_REQ_ID req_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_info = (srv_email_msg_save_info_struct*)user_data;
    msg_object = save_info->msg_object;
    req_id = save_info->req_id;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE_NEW_CALLBACK, res, msg_id);
    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        if (save_info->msg_id)
        {
            *(save_info->msg_id) = msg_id;
        }
    }
    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_msg_result.result = MMI_TRUE;
    }
    else
    {
        srv_email_msg_result.result = MMI_FALSE;
        srv_email_msg_result.major = res;
        if (res == SRV_EMAIL_RESULT_FS_ERROR)
        {
            srv_email_msg_result.minor = srv_email_errno_get();
        }
    }
    srv_email_mem_free(save_info);
    srv_email_msg_clear_req_id(msg_object, req_id);
    if (msg_object->callback != NULL)
    {
        (*msg_object->callback)(
            &srv_email_msg_result,
            req_id,
            msg_object->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_save_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_msg_save_callback(srv_email_result_enum res, EMAIL_MSG_ID msg_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_save_info_struct *save_info;
    srv_email_msg_info_struct *msg_object;
    EMAIL_REQ_ID req_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_info = (srv_email_msg_save_info_struct*)user_data;
    msg_object = save_info->msg_object;
    req_id = save_info->req_id;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE_CALLBACK, res, msg_id);
    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_msg_result.result = MMI_TRUE;
    }
    else
    {
        srv_email_msg_result.result = MMI_FALSE;
        srv_email_msg_result.major = res;
        if (res == SRV_EMAIL_RESULT_FS_ERROR)
        {
            srv_email_msg_result.minor = srv_email_errno_get();
        }
    }
    srv_email_mem_free(save_info);
    srv_email_msg_clear_req_id(msg_object, req_id);
    if (msg_object->callback != NULL)
    {
        (*msg_object->callback)(
            &srv_email_msg_result,
            req_id,
            msg_object->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_str_encode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
//extern void srv_email_str_encode(
//                WCHAR *src_str,
//                MMI_BOOL src_type,
//                S32 charset,
//                WCHAR *dst_str,
//                MMI_BOOL dst_type,
//                S32 *len)
//{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    if (src_str == NULL ||
//        dst_str == NULL ||
//        len == NULL)
//    {
//        return;
//    }
//}


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
static void srv_email_msg_nwk_finish_callback(srv_email_nwk_finish_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_nwk_notify_struct *notify_data;
    srv_email_msg_info_struct *msg_object;
    MMI_BOOL move_to_sent;
    EMAIL_REQ_ID req_id;
    EMAIL_MSG_ID new_msg_id;
    EMAIL_FLDR_ID fldr_id;
    srv_email_result_enum result;
    srv_email_result_enum close_result;
    S32 action = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    notify_data = (srv_email_msg_nwk_notify_struct*)data->user_data;
    msg_object = (srv_email_msg_info_struct*)notify_data->msg_object;
    msg_object->access_state = notify_data->org_access_state;
    req_id = notify_data->req_id;
    move_to_sent = notify_data->move_to_sent;
    srv_email_mem_free(notify_data);
    for (i = 0; i < SRV_EMAIL_MESSAGE_REQ_MAX_NUMBER; i++)
    {
        if (msg_object->req_id_action_map_list[i].req_id == req_id)
        {
            action = msg_object->req_id_action_map_list[i].action;
            msg_object->req_id_action_map_list[i].req_id = 0;
            msg_object->req_id_action_map_list[i].action = SRV_EMAIL_MSG_OPERATION_NONE;
            break;
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_NWK_FINISH_CALLBACK,
        data->result.result,
        req_id,
        msg_object->req_id_action_map_list[i].action,
        move_to_sent);
    srv_email_nwk_destroy(msg_object->nwk_handle);
    msg_object->nwk_handle = EMAIL_NWK_INVALID_HANDLE;
    if (data->result.result && action == SRV_EMAIL_NWK_SEND)
    {
        if (move_to_sent)
        {
            fldr_id = srv_email_stor_fldr_get_id_by_type(msg_object->acct_id, SRV_EMAIL_FLDR_TYPE_SENT);
            result =  srv_email_stor_msg_move(msg_object->msg_id, msg_object->acct_id, fldr_id, &new_msg_id);
            if (result == SRV_EMAIL_RESULT_SUCC)
            {
                data->result.sub_result = MMI_TRUE;
                msg_object->fldr_id = fldr_id;
                msg_object->msg_id = new_msg_id;
            }
            else
            {
                data->result.sub_result = MMI_FALSE;
                data->result.major = result;
                if (result == SRV_EMAIL_RESULT_FS_ERROR)
                {
                    data->result.minor = srv_email_errno_get();
                }
            }
        }
        else
        {
            fldr_id = srv_email_stor_fldr_get_id_by_type(msg_object->acct_id, SRV_EMAIL_FLDR_TYPE_OUTBOX);
            result = srv_email_stor_fldr_del_msg_open(
                        SRV_EMAIL_FLDR_TYPE_INVALID,
                        msg_object->acct_id,
                        fldr_id,
                        MMI_TRUE,
                        MMI_TRUE,
                        &msg_object->stor_handle);
            if (result == SRV_EMAIL_RESULT_SUCC)
            {
                result = srv_email_stor_fldr_del_msg_next(
                            msg_object->stor_handle,
                            msg_object->msg_id);
                close_result = srv_email_stor_fldr_del_msg_close(msg_object->stor_handle);
                if (result == SRV_EMAIL_RESULT_SUCC && close_result == SRV_EMAIL_RESULT_SUCC)
                {
                    data->result.sub_result = MMI_TRUE;
                }
                else
                {
                    data->result.sub_result = MMI_FALSE;
                    data->result.major = result;
                    if (result == SRV_EMAIL_RESULT_FS_ERROR)
                    {
                        data->result.minor = srv_email_errno_get();
                    }
                }
            }
            else
            {
                data->result.sub_result = MMI_FALSE;
                data->result.major = result;
                if (result == SRV_EMAIL_RESULT_FS_ERROR)
                {
                    data->result.minor = srv_email_errno_get();
                }
            }
        }
    }
    if (msg_object->callback != NULL)
    {
        (*msg_object->callback)(
            &data->result,
            req_id,
            msg_object->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_copy_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_msg_copy_callback(
                srv_email_result_enum res,
                EMAIL_MSG_ID to_msg_id,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_msg_copy_notify_struct *notify_data;
    EMAIL_REQ_ID req_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    notify_data = (srv_email_msg_copy_notify_struct*)user_data;
    msg_object = notify_data->msg_object;
    req_id = notify_data->req_id;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_COPY_CALLBACK, res, to_msg_id);
    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_msg_result.result = MMI_TRUE;
    }
    else
    {
        srv_email_msg_result.result = MMI_FALSE;
        srv_email_msg_result.major = res;
        if (res == SRV_EMAIL_RESULT_FS_ERROR)
        {
            srv_email_msg_result.minor = srv_email_errno_get();
        }
    }
    srv_email_mem_free(notify_data);
    srv_email_msg_clear_req_id(msg_object, req_id);
    if (msg_object->callback != NULL)
    {
        (*msg_object->callback)(
            &srv_email_msg_result,
            req_id,
            msg_object->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static MMI_BOOL srv_email_msg_get_req_id(
                    srv_email_msg_info_struct *msg_object,
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
    for (i = 0; i < SRV_EMAIL_MESSAGE_REQ_MAX_NUMBER; i++)
    {
        if (msg_object->req_id_action_map_list[i].action == SRV_EMAIL_MSG_OPERATION_NONE)
        {
            msg_object->req_id_action_map_list[i].req_id = msg_req_id++;
            msg_object->req_id_action_map_list[i].action = action;
            msg_object->req_id_action_map_list[i].operation_info = operation_info;
            if (req_id_1 != NULL)
            {
                *req_id_1 = msg_object->req_id_action_map_list[i].req_id;
            }
            if (req_id_2 != NULL)
            {
                *req_id_2 = msg_object->req_id_action_map_list[i].req_id;
            }
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_msg_clear_req_id(srv_email_msg_info_struct *msg_object, EMAIL_REQ_ID req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_MESSAGE_REQ_MAX_NUMBER; i++)
    {
        if (msg_object->req_id_action_map_list[i].req_id == req_id)
        {
            msg_object->req_id_action_map_list[i].req_id = 0;
            msg_object->req_id_action_map_list[i].operation_info = NULL;
            msg_object->req_id_action_map_list[i].action = SRV_EMAIL_MSG_OPERATION_NONE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_acct_able_to_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_msg_mime_parser_callback(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_mime_parser_info_struct *parser_info;
    CHAR *dst_file_path;
    srv_email_msg_info_struct *msg_object;
    email_msg_info_struct *msg_info = NULL;
    WCHAR *file_path = NULL;
    FS_HANDLE file_handle;
    FS_HANDLE file_handle_2;
    FS_HANDLE drm_file_handle = -1;
    EMAIL_REQ_ID req_id;
    S32 local_result;
    U32 read;
    U16 i;
    U16 j;
    srv_email_result_enum result;
    email_mime_parser_rsp_struct *info = (email_mime_parser_rsp_struct*)inMsg;
    email_address_list addr_mime;
    srv_email_addr_struct addr;
    email_attach_struct *stor_attach_info;
    srv_email_attach_struct *attach_info;
    U16 object_index;
    FS_HANDLE attach_file_handle;
    email_drm_struct drm;
    WCHAR *temp_attach_name;
    email_mime_parser_error_cause error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = (srv_email_result_enum)info->result;
    dst_file_path = info->dst_file_path;
    srv_email_mem_free(dst_file_path);
    parser_info = (srv_email_msg_mime_parser_info_struct*)info->user_data;
    msg_object = parser_info->msg_object;
    req_id = parser_info->req_id;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_PARSR_CALLBACK, info->result, parser_info->canceled);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        email_get_error_cause(&error_cause);
        if (error_cause == EMAIL_MIME_PARSER_FORMAT_ERROR)
        {
            srv_email_msg_result.major = SRV_EMAIL_MAIL_ERROR;
            srv_email_msg_result.minor = SRV_EMAIL_RESULT_INVALID_FORMAT;
        }
        else if (error_cause == EMAIL_MIME_PARSER_FS_ERROR)
        {
            srv_email_msg_result.major = SRV_EMAIL_FS_ERROR;
            email_get_fs_error_code(&srv_email_msg_result.minor);
    }
        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
    srv_email_mem_free(dst_file_path);
        srv_email_mem_free(parser_info);
        if (msg_object->callback != NULL)
        {
            srv_email_msg_result.result = MMI_FALSE;
            (*msg_object->callback)(
                &srv_email_msg_result,
                req_id,
                msg_object->user_data);
        }
        return;
    }
    if (parser_info->canceled)
    {
        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
        srv_email_mem_free(parser_info);
        return;
    }
    file_path = (WCHAR*)srv_email_mem_alloc((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    if (file_path == NULL)
    {
        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
        srv_email_mem_free(parser_info);
        if (msg_object->callback != NULL)
        {
            srv_email_msg_result.major = SRV_EMAIL_MAIL_ERROR;
            srv_email_msg_result.minor = SRV_EMAIL_RESULT_NO_MEMORY;
            srv_email_msg_result.result = MMI_FALSE;
            (*msg_object->callback)(
                &srv_email_msg_result,
                req_id,
                msg_object->user_data);
        }
        return;
    }
    for (object_index = 0; object_index < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; object_index++)
    {
        if (&(srv_email_msg_cntx_p->msg_array[object_index]) == msg_object)
        {
            break;
        }
    }
    kal_wsprintf(file_path, "%s%s%d\\header_info", srv_email_get_root_path(), message_path, object_index + 1);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
        srv_email_mem_free(file_path);
        srv_email_mem_free(parser_info);
        if (msg_object->callback != NULL)
        {
            srv_email_msg_result.result = MMI_FALSE;
            (*msg_object->callback)(
                &srv_email_msg_result,
                req_id,
                msg_object->user_data);
        }
        return;
    }
    msg_info = (email_msg_info_struct*)srv_email_mem_alloc(sizeof(email_msg_info_struct));
    if (msg_info == NULL)
    {
        FS_Close(file_handle);
        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
        srv_email_mem_free(file_path);
        srv_email_mem_free(parser_info);
        if (msg_object->callback != NULL)
        {
            srv_email_msg_result.major = SRV_EMAIL_MAIL_ERROR;
            srv_email_msg_result.minor = SRV_EMAIL_RESULT_NO_MEMORY;
            srv_email_msg_result.result = MMI_FALSE;
            (*msg_object->callback)(
                &srv_email_msg_result,
                req_id,
                msg_object->user_data);
        }
        return;
    }
    local_result = FS_Read(file_handle, msg_info, sizeof(email_msg_info_struct), &read);
    FS_Close(file_handle);
    if (local_result != FS_NO_ERROR || read != sizeof(email_msg_info_struct))
    {
        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
        srv_email_mem_free(msg_info);
        srv_email_mem_free(file_path);
        srv_email_mem_free(parser_info);
        if (msg_object->callback != NULL)
        {
            srv_email_msg_result.major = SRV_EMAIL_FS_ERROR;
            srv_email_msg_result.minor = SRV_EMAIL_RESULT_FS_ERROR;
            srv_email_msg_result.result = MMI_FALSE;
            (*msg_object->callback)(
                &srv_email_msg_result,
                req_id,
                msg_object->user_data);
        }
        return;
    }
    msg_object->content_charset = msg_info->text_msgs[0].charset_text;
    msg_object->subject_charset = msg_info->charset_subject;
    msg_object->has_html = msg_info->text_msgs[0].has_html_part;
    msg_object->html_charset = msg_info->text_msgs[0].charset_html;
    msg_object->priority = msg_info->priority;
    msg_object->to_addr_num = msg_info->total_to_address;
    msg_object->remain_to_addr_num = msg_info->remain_to_address;
    msg_object->cc_addr_num = msg_info->total_cc_address;
    msg_object->remain_cc_addr_num = msg_info->remain_cc_address;
    msg_object->bcc_addr_num = msg_info->total_bcc_address;
    msg_object->remain_bcc_addr_num = msg_info->remain_bcc_address;
    msg_object->attach_num = msg_info->total_attachments;
    msg_object->remain_attach_num = msg_info->remain_attachment_num;
    msg_object->mail_date = msg_info->create_date_time;
    msg_object->recv_date = msg_info->send_date_time;
    msg_object->local_size = msg_info->local_size;
    msg_object->server_size = msg_info->server_size;
    msg_object->state = msg_info->state;
    msg_object->sender_addr.disp_name_len = SRV_EMAIL_MAX_DISP_NAME_LEN + 1;
    FS_Delete(file_path);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_PARSR_HEADER_INFO,
        msg_object->priority,
        msg_object->state);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_PARSR_TEXT_INFO,
        msg_object->subject_charset,
        msg_object->content_charset,
        msg_object->has_html,
        msg_object->html_charset);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_PARSR_ADDR_INFO,
        msg_object->to_addr_num,
        msg_object->cc_addr_num,
        msg_object->bcc_addr_num);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_MSG_PARSR_ATTACH_INFO,
        msg_object->attach_num);

    memset(&addr, 0, sizeof(srv_email_addr_struct));
    mmi_chset_convert(
        CHSET_UTF8,
        CHSET_UCS2,
        (CHAR*)msg_info->senders_address.email_address,
        (CHAR*)addr.email_addr,
        (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
    if (msg_info->senders_address.charset_disp > MMI_CHSET_BASE && msg_info->senders_address.charset_disp < MMI_CHSET_TOTAL)
    {
        addr.disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
        mmi_chset_convert(
            (mmi_chset_enum)msg_info->senders_address.charset_disp,
            CHSET_UCS2,
            msg_info->senders_address.display_name,
            (CHAR*)addr.disp_name,
            addr.disp_name_len);
        addr.disp_charset = CHSET_UCS2;
        addr.disp_name_len = mmi_wcslen(addr.disp_name);
    }
    else
    {
        addr.disp_name_len = strlen(msg_info->senders_address.display_name);
        addr.disp_charset = msg_info->senders_address.charset_disp;
        memcpy(addr.disp_name, msg_info->senders_address.display_name, addr.disp_name_len);
    }
    memcpy(&msg_object->sender_addr, &addr, sizeof(srv_email_addr_struct));

    memset(&addr, 0, sizeof(srv_email_addr_struct));
    mmi_chset_convert(
        CHSET_UTF8,
        CHSET_UCS2,
        (CHAR*)msg_info->reply_to_addr.email_address,
        (CHAR*)addr.email_addr,
        (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
    if (msg_info->senders_address.charset_disp > MMI_CHSET_BASE && msg_info->senders_address.charset_disp < MMI_CHSET_TOTAL)
    {
        addr.disp_name_len = (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2;
        mmi_chset_convert(
            (mmi_chset_enum)msg_info->reply_to_addr.charset_disp,
            CHSET_UCS2,
            msg_info->reply_to_addr.display_name,
            (CHAR*)addr.disp_name,
            addr.disp_name_len);
        addr.disp_charset = CHSET_UCS2;
        addr.disp_name_len = mmi_wcslen(addr.disp_name);
    }
    else
    {
        addr.disp_name_len = strlen(msg_info->senders_address.display_name);
        addr.disp_charset = msg_info->senders_address.charset_disp;
        memcpy(addr.disp_name, msg_info->senders_address.display_name, addr.disp_name_len);
    }
    memcpy(&msg_object->reply_to_addr, &addr, sizeof(srv_email_addr_struct));
    srv_email_mem_free(msg_info);
    /*S32 server_size;
    S32 local_size;
    S32 mail_date;
    S32 recv_date;
    U32 state;
    EMAIL_MSG_FLAG flag;*/
    /* address */
    /* NO ERROR HANDLING */
    kal_wsprintf(file_path, "%s%s%d\\to", srv_email_get_root_path(), message_path, object_index + 1);
    file_handle_2 = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (file_handle_2 >= 0)
    {
        kal_wsprintf(file_path, "%s%s%d\\to_t", srv_email_get_root_path(), message_path, object_index + 1);
        file_handle = FS_Open(file_path, FS_READ_ONLY);
        if (file_handle >= 0)
        {
            for (i = 0; i< msg_object->to_addr_num; i++)
            {
                memset(&addr, 0, sizeof(srv_email_addr_struct));
                FS_Read(file_handle, &addr_mime, sizeof(email_address_list), &read);
                mmi_chset_convert(
                    CHSET_UTF8,
                    CHSET_UCS2,
                    (CHAR*)&addr_mime.email_address,
                    (CHAR*)addr.email_addr,
                    (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
                if (addr_mime.charset_disp > MMI_CHSET_BASE && addr_mime.charset_disp < MMI_CHSET_TOTAL)
                {
                    mmi_chset_convert(
                        (mmi_chset_enum)addr_mime.charset_disp,
                        CHSET_UCS2,
                        addr_mime.display_name,
                        (CHAR*)addr.disp_name,
                        (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2);
                    addr.disp_charset = CHSET_UCS2;
                    addr.disp_name_len = mmi_wcslen(addr.disp_name);
                }
                else
                {
                    addr.disp_name_len = strlen(addr_mime.display_name);
                    memcpy(addr.disp_name, addr_mime.display_name, addr.disp_name_len);
                    addr.disp_charset = addr_mime.charset_disp;
                }
                local_result = FS_Write(file_handle_2, &addr, sizeof(srv_email_addr_struct), &read);
                if (local_result != FS_NO_ERROR)
                {
                    FS_Close(file_handle);
                    FS_Delete(file_path);
                    FS_Close(file_handle_2);
                    msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
                    srv_email_mem_free(file_path);
                    srv_email_mem_free(parser_info);
                    if (msg_object->callback != NULL)
                    {
                        srv_email_msg_result.major = SRV_EMAIL_MAIL_ERROR;
                        srv_email_msg_result.minor = SRV_EMAIL_RESULT_NO_MEMORY;
                        srv_email_msg_result.result = MMI_FALSE;
                        (*msg_object->callback)(
                            &srv_email_msg_result,
                            req_id,
                            msg_object->user_data);
                    }
                    return;
                }
            }
            FS_Close(file_handle);
        }
        FS_Delete(file_path);
    }
    FS_Close(file_handle_2);

    kal_wsprintf(file_path, "%s%s%d\\cc", srv_email_get_root_path(), message_path, object_index + 1);
    file_handle_2 = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (file_handle_2 >= 0)
    {
        kal_wsprintf(file_path, "%s%s%d\\cc_t", srv_email_get_root_path(), message_path, object_index + 1);
        file_handle = FS_Open(file_path, FS_READ_ONLY);
        if (file_handle >= 0)
        {
            for (i = 0; i< msg_object->cc_addr_num; i++)
            {
                memset(&addr, 0, sizeof(srv_email_addr_struct));
                FS_Read(file_handle, &addr_mime, sizeof(email_address_list), &read);
                mmi_chset_convert(
                    CHSET_UTF8,
                    CHSET_UCS2,
                    (CHAR*)&addr_mime.email_address,
                    (CHAR*)addr.email_addr,
                    (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
                if (addr_mime.charset_disp > MMI_CHSET_BASE && addr_mime.charset_disp < MMI_CHSET_TOTAL)
                {
                    mmi_chset_convert(
                        (mmi_chset_enum)addr_mime.charset_disp,
                        CHSET_UCS2,
                        addr_mime.display_name,
                        (CHAR*)addr.disp_name,
                        (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2);
                    addr.disp_charset = CHSET_UCS2;
                    addr.disp_name_len = mmi_wcslen(addr.disp_name);
                }
                else
                {
                    addr.disp_name_len = strlen(addr_mime.display_name);
                    memcpy(addr.disp_name, addr_mime.display_name, addr.disp_name_len);
                    addr.disp_charset = addr_mime.charset_disp;
                }
                local_result = FS_Write(file_handle_2, &addr, sizeof(srv_email_addr_struct), &read);
                if (local_result != FS_NO_ERROR)
                {
                    FS_Close(file_handle);
                    FS_Delete(file_path);
                    FS_Close(file_handle_2);
                    msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
                    srv_email_mem_free(file_path);
                    srv_email_mem_free(parser_info);
                    if (msg_object->callback != NULL)
                    {
                        srv_email_msg_result.major = SRV_EMAIL_MAIL_ERROR;
                        srv_email_msg_result.minor = SRV_EMAIL_RESULT_NO_MEMORY;
                        srv_email_msg_result.result = MMI_FALSE;
                        (*msg_object->callback)(
                            &srv_email_msg_result,
                            req_id,
                            msg_object->user_data);
                    }
                    return;
                }
            }
            FS_Close(file_handle);
        }
        FS_Delete(file_path);
    }
    FS_Close(file_handle_2);

    kal_wsprintf(file_path, "%s%s%d\\bcc", srv_email_get_root_path(), message_path, object_index + 1);
    file_handle_2 = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (file_handle_2 >= 0)
    {
        kal_wsprintf(file_path, "%s%s%d\\bcc_t", srv_email_get_root_path(), message_path, object_index + 1);
        file_handle = FS_Open(file_path, FS_READ_ONLY);
        if (file_handle >= 0)
        {
            for (i = 0; i< msg_object->bcc_addr_num; i++)
            {
                memset(&addr, 0, sizeof(srv_email_addr_struct));
                FS_Read(file_handle, &addr_mime, sizeof(email_address_list), &read);
                mmi_chset_convert(
                    CHSET_UTF8,
                    CHSET_UCS2,
                    (CHAR*)&addr_mime.email_address,
                    (CHAR*)addr.email_addr,
                    (SRV_EMAIL_MAX_ADDR_LEN + 1) * 2);
                if (addr_mime.charset_disp > MMI_CHSET_BASE && addr_mime.charset_disp < MMI_CHSET_TOTAL)
                {
                    mmi_chset_convert(
                        (mmi_chset_enum)addr_mime.charset_disp,
                        CHSET_UCS2,
                        addr_mime.display_name,
                        (CHAR*)addr.disp_name,
                        (SRV_EMAIL_MAX_DISP_NAME_LEN + 1) * 2);
                    addr.disp_charset = CHSET_UCS2;
                    addr.disp_name_len = mmi_wcslen(addr.disp_name);
                }
                else
                {
                    addr.disp_name_len = strlen(addr_mime.display_name);
                    memcpy(addr.disp_name, addr_mime.display_name, addr.disp_name_len);
                    addr.disp_charset = addr_mime.charset_disp;
                }
                local_result = FS_Write(file_handle_2, &addr, sizeof(srv_email_addr_struct), &read);
                if (local_result != FS_NO_ERROR)
                {
                    FS_Close(file_handle);
                    FS_Delete(file_path);
                    FS_Close(file_handle_2);
                    msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
                    srv_email_mem_free(file_path);
                    srv_email_mem_free(parser_info);
                    if (msg_object->callback != NULL)
                    {
                        srv_email_msg_result.major = SRV_EMAIL_MAIL_ERROR;
                        srv_email_msg_result.minor = SRV_EMAIL_RESULT_NO_MEMORY;
                        srv_email_msg_result.result = MMI_FALSE;
                        (*msg_object->callback)(
                            &srv_email_msg_result,
                            req_id,
                            msg_object->user_data);
                    }
                    return;
                }
            }
            FS_Close(file_handle);
        }
        FS_Delete(file_path);
    }
    FS_Close(file_handle_2);

    kal_wsprintf(file_path, "%s%s%d\\attach_info", srv_email_get_root_path(), message_path, object_index + 1);
    file_handle_2 = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (file_handle_2 >= 0)
    {
        kal_wsprintf(file_path, "%s%s%d\\attach_info_t", srv_email_get_root_path(), message_path, object_index + 1);
        file_handle = FS_Open(file_path, FS_READ_ONLY);
        if (file_handle >= 0)
        {
            kal_wsprintf(file_path, "%s%s%d\\drm", srv_email_get_root_path(), message_path, object_index + 1);
            drm_file_handle = FS_Open(file_path, FS_READ_ONLY);
            stor_attach_info = (email_attach_struct*)get_ctrl_buffer(sizeof(email_attach_struct));
            attach_info = (srv_email_attach_struct*)get_ctrl_buffer(sizeof(srv_email_attach_struct));
            for (j = 0; j < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; j++)
            {
                if (&srv_email_msg_cntx_p->msg_array[j] == msg_object)
                {
                    break;
                }
            }
            for (i = 0; i< msg_object->attach_num; i++)
            {
                memset(stor_attach_info, 0, sizeof(email_attach_struct));
                kal_wsprintf(
                    attach_info->path,
                    "%s%s%d\\%s%d",
                    srv_email_get_root_path(),
                    message_path,
                    j + 1,
                    "attach",
                    i + 1);
                attach_file_handle = FS_Open(attach_info->path, FS_READ_ONLY);
                if (attach_file_handle >= 0)
                {
                    FS_GetFileSize(attach_file_handle, (U32*)&attach_info->size);
                    FS_Close(attach_file_handle);
                    FS_Read(file_handle, stor_attach_info, sizeof(email_attach_struct), &read);
                    temp_attach_name = (WCHAR*)get_ctrl_buffer((strlen(stor_attach_info->attach_file_name) + 1) * 2);
                    mmi_chset_convert(
                        (mmi_chset_enum)stor_attach_info->charset_attach,
                        CHSET_UCS2,
                        stor_attach_info->attach_file_name,
                        (CHAR*)temp_attach_name,
                        (strlen(stor_attach_info->attach_file_name) + 1) * 2);
                    srv_email_handle_file_name(
                        attach_info->name,
                        temp_attach_name,
                        EMAIL_ATTCH_FILE_NAME_LEN);
                    free_ctrl_buffer(temp_attach_name);
                    attach_info->charset = CHSET_UCS2;
                    attach_info->downloaded = MMI_TRUE;
                    attach_info->drm_object = MMI_FALSE;
                    attach_info->mime_type = stor_attach_info->mime_type;
                    attach_info->mime_subtype = stor_attach_info->mime_subtype;
                    memcpy(&attach_info->cid, stor_attach_info->cid, SRV_EMAIL_CID_MAX_LEN + 1);
                    if (drm_file_handle >= 0)
                    {
                        FS_Read(drm_file_handle, &drm, sizeof(email_drm_struct), &read);
                        if (drm.is_valid == MMI_TRUE)
                        {
                            attach_info->drm_object = drm.is_valid;
                            attach_info->drm_type = drm.mime_type;
                            attach_info->drm_type = drm.mime_subtype;
                            attach_info->name_len = (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2;
                            srv_email_string_decode(
                                (WCHAR*)drm.attach_file_name,
                                attach_info->name,
                                &attach_info->name_len,
                                &attach_info->charset);
                        }
                    }
                    local_result = FS_Write(file_handle_2, attach_info, sizeof(srv_email_attach_struct), &read);
                    if (local_result != FS_NO_ERROR)
                    {
                        FS_Close(file_handle);
                        FS_Delete(file_path);
                        FS_Close(file_handle_2);
                        msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_INIT;
                        srv_email_mem_free(file_path);
                        srv_email_mem_free(parser_info);
                        free_ctrl_buffer(attach_info);
                        free_ctrl_buffer(stor_attach_info);
                        if (msg_object->callback != NULL)
                        {
                            srv_email_msg_result.major = SRV_EMAIL_MAIL_ERROR;
                            srv_email_msg_result.minor = SRV_EMAIL_RESULT_NO_MEMORY;
                            srv_email_msg_result.result = MMI_FALSE;
                            (*msg_object->callback)(
                                &srv_email_msg_result,
                                req_id,
                                msg_object->user_data);
                        }
                        return;
                    }
                }
            }
            free_ctrl_buffer(attach_info);
            free_ctrl_buffer(stor_attach_info);
            FS_Close(file_handle);
            if (drm_file_handle >= 0)
            {
                FS_Close(drm_file_handle);
            }
            FS_Delete(file_path);
        }
        kal_wsprintf(file_path, "%s%s%d\\attach_info_t", srv_email_get_root_path(), message_path, object_index + 1);
        FS_Delete(file_path);
    }
    FS_Close(file_handle_2);

    msg_object->access_state = SRV_EMAIL_MSG_ACCESS_STATE_EDIT;
    srv_email_mem_free(parser_info);
    srv_email_mem_free(file_path);
    if (msg_object->callback != NULL)
    {
        if (result == SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_msg_result.result = MMI_TRUE;
        }
        else
        {
            srv_email_msg_result.result = MMI_FALSE;
        }
        (*msg_object->callback)(
            &srv_email_msg_result,
            req_id,
            msg_object->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_acct_able_to_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_email_msg_acct_able_to_delete(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
    {
        if (srv_email_msg_cntx_p->msg_array[i].in_use &&
            srv_email_msg_cntx_p->msg_array[i].acct_id == acct_id)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern EMAIL_MSG_ID srv_email_msg_get_id(EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        return EMAIL_MSG_INVALID_ID;
    }
    return msg_object->msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_msg_by_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern void srv_email_msg_update_msg_by_handle(
                                EMAIL_MSG_ID msg_id,
                                EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    U16 i;
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        return;
    }
    for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
    {
        if (srv_email_msg_cntx_p->msg_array[i].in_use &&
            srv_email_msg_cntx_p->msg_array[i].msg_id == msg_id &&
            (EMAIL_MSG_HANDLE)(&srv_email_msg_cntx_p->msg_array[i]) != msg_handle)
        {
            break;
        }
    }
    if (i == SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER)
    {
        return;
    }
    for (j = 0; j < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; j++)
    {
        if (srv_email_msg_cntx_p->msg_array[j].in_use &&
            (EMAIL_MSG_HANDLE)(&srv_email_msg_cntx_p->msg_array[j]) == msg_handle)
        {
            break;
        }
    }
    if (j == SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER)
    {
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_UPDATE_MSG_BY_HANDLE, msg_handle, msg_id, j, i);

    msg_object->acct_id = srv_email_msg_cntx_p->msg_array[i].acct_id;
    msg_object->fldr_id = srv_email_msg_cntx_p->msg_array[i].fldr_id;
    msg_object->msg_id = srv_email_msg_cntx_p->msg_array[i].msg_id;

    srv_email_msg_cntx_p->msg_array[i].to_addr_num = srv_email_msg_cntx_p->msg_array[j].to_addr_num;
    srv_email_msg_cntx_p->msg_array[i].cc_addr_num = srv_email_msg_cntx_p->msg_array[j].cc_addr_num;
    srv_email_msg_cntx_p->msg_array[i].bcc_addr_num = srv_email_msg_cntx_p->msg_array[j].bcc_addr_num;
    srv_email_msg_cntx_p->msg_array[i].attach_num = srv_email_msg_cntx_p->msg_array[j].attach_num;
    srv_email_msg_cntx_p->msg_array[i].priority = srv_email_msg_cntx_p->msg_array[j].priority;
    srv_email_msg_cntx_p->msg_array[i].server_size = srv_email_msg_cntx_p->msg_array[j].server_size;
    srv_email_msg_cntx_p->msg_array[i].local_size = srv_email_msg_cntx_p->msg_array[j].local_size;
    srv_email_msg_cntx_p->msg_array[i].mail_date = srv_email_msg_cntx_p->msg_array[j].mail_date;
    srv_email_msg_cntx_p->msg_array[i].state = srv_email_msg_cntx_p->msg_array[j].state;
    srv_email_msg_cntx_p->msg_array[i].subject_charset = srv_email_msg_cntx_p->msg_array[j].subject_charset;
    srv_email_msg_cntx_p->msg_array[i].content_charset = srv_email_msg_cntx_p->msg_array[j].content_charset;
}



/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_cont_for_comp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The message handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_cont_for_comp(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_stor_msg_cont_type type,
                                srv_email_stor_cont_header_struct *cont_header,
                                WCHAR *path,
                                U32 *buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    WCHAR *file_path = NULL;
    FS_HANDLE file_handle;
    srv_email_msg_save_part_enum save_part;
    S32 result;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_GET_CONT_FOR_COMP, msg_handle, type);
    file_path = (WCHAR*)get_ctrl_buffer((SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2);
    if (type == SRV_EMAIL_STOR_MSG_CONT_TEXT)
    {
        save_part = SRV_EMAIL_MSG_SAVE_CONTENT;
    }
    else
    {
        save_part = SRV_EMAIL_MSG_SAVE_HTML;
    }
    file_handle = srv_email_msg_get_file_handle(msg_object, save_part, MMI_FALSE);
    if (file_handle < 0)
    {
        free_ctrl_buffer(file_path);
        srv_email_errno_set(file_handle);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    result = FS_GetFileSize(file_handle, &size);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR)
    {
        free_ctrl_buffer(file_path);
        srv_email_errno_set(result);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (cont_header != NULL)
    {
        cont_header->local_size = size;
        kal_sprintf(cont_header->charset, "ISO-10646-UCS-2"); /* UCS2 */
    }

    if (path != NULL && buff_size != NULL)
    {
        srv_email_msg_get_file_path(file_path, SRV_EMAIL_MAX_FILE_NAME_LEN + 1, msg_object, save_part);
        if (*buff_size >= (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2)
        {
            mmi_wcscpy(path, file_path);
        }
        else
        {
            memcpy(path, file_path, *buff_size - 2);
            path[(*buff_size - 2) / 2] = 0;
        }
        *buff_size = mmi_wcslen(path) * 2;
    }
    free_ctrl_buffer(file_path);
    return SRV_EMAIL_RESULT_SUCC;
}


static srv_email_result_enum srv_email_msg_save_int(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 *uidl,
                                U8 *acct_digest,
                                srv_email_msg_save_part_enum save_part,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_save_info_struct *save_info;
    srv_email_stor_msg_create_header_struct header;
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum result;
    srv_email_stor_msg_query_text_funcptr_type query_text_callback = NULL;
    srv_email_stor_msg_query_addr_funcptr_type query_addr_callback = NULL;
    srv_email_stor_msg_query_attch_funcptr_type query_attch_callback = NULL;
    FS_HANDLE file_handle;
    S32 fs_result;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE_INT, msg_handle, save_part);
    save_info = (srv_email_msg_save_info_struct*)srv_email_mem_alloc(sizeof(srv_email_msg_save_info_struct));
    if (save_info == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    save_info->msg_object = msg_object;
    save_info->save_new = MMI_FALSE;
    header.acct_id = msg_object->acct_id;
    header.fldr_id = msg_object->fldr_id;
    header.addr_to_num = msg_object->to_addr_num;
    header.addr_cc_num = msg_object->cc_addr_num;
    header.addr_bcc_num = msg_object->bcc_addr_num;
    header.remain_addr_to_num = msg_object->remain_to_addr_num;
    header.remain_addr_cc_num = msg_object->remain_cc_addr_num;
    header.remain_addr_bcc_num = msg_object->remain_bcc_addr_num;
    header.msg_id = msg_object->msg_id;
    header.state = msg_object->state;
    header.flag = msg_object->flag;
    header.priority = msg_object->priority;
    header.created_date = msg_object->mail_date;
    header.received_date = msg_object->recv_date;
    header.server_size = msg_object->server_size;
    header.local_size = msg_object->local_size;
    header.local_size = msg_object->local_size;
    header.attch_num = msg_object->attach_num;
    header.remain_attach_num = msg_object->remain_attach_num;
    if (uidl != NULL)
    {
        header.msg_type = SRV_EMAIL_STOR_MSG_TYPE_RECV;
        memcpy(header.uidl, uidl, SRV_EMAIL_MD5_DIGEST_LEN);
    }
    else
    {
        header.msg_type = SRV_EMIAL_STOR_MSG_TYPE_SENT;
    }
    if (acct_digest)
    {
        memcpy(header.acct_digest, acct_digest, SRV_EMAIL_MD5_DIGEST_LEN);
    }
    file_handle = srv_email_msg_get_file_handle(msg_object, SRV_EMAIL_MSG_SAVE_SUBJECT, MMI_FALSE);
    if (file_handle < 0)
    {
        header.subj_len = 0;
    }
    else
    {
        fs_result = FS_GetFileSize(file_handle, &size);
        if (fs_result != FS_NO_ERROR)
        {
            FS_Close(file_handle);
            header.subj_len = 0;
        }
        else
        {
            fs_result = FS_GetFileSize(file_handle, &size);
            if (fs_result != FS_NO_ERROR)
            {
                header.subj_len = 0;
                FS_Close(file_handle);
            }
            else
            {
                CHAR *temp_text = NULL;
                U32 read;
                U32 MaxSource = mmi_chset_get_char_size_of_charset((mmi_chset_enum)msg_object->subject_charset);
                U32 MaxDest = mmi_chset_get_char_size_of_charset(CHSET_UTF8);

                if (MaxSource == 0)
                {
                    MaxSource = 1;
                }
                header.subj_len = 2 * (MaxDest / MaxSource) * size + EMAIL_CHARSET_ENCODE_STRING_LEN;
                //header.subj_len = size * 2 + EMAIL_CHARSET_ENCODE_STRING_LEN; /* charset string and base64 encode */
                temp_text = (CHAR*)get_ctrl_buffer(size + 2);
                memset(temp_text, 0, size + 2);
                fs_result = FS_Read(file_handle, temp_text, size + 2, &read);
                FS_Close(file_handle);
                if (msg_object->subject_charset > MMI_CHSET_BASE && msg_object->subject_charset < MMI_CHSET_TOTAL)
                {
                    mmi_chset_convert((mmi_chset_enum)msg_object->subject_charset, CHSET_UCS2, (CHAR*)temp_text, (CHAR*)header.list_subj, (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2);
                }
                else
                {
                    if (strlen(temp_text) < EMAIL_MAX_LIST_SUBJ_LEN * 2)
                    {
                        memcpy(header.list_subj, temp_text, strlen(temp_text));
                    }
                    else
                    {
                        memcpy(header.list_subj, temp_text, EMAIL_MAX_LIST_SUBJ_LEN * 2);
                    }
                }
                free_ctrl_buffer(temp_text);
            }
        }
    }
    file_handle = srv_email_msg_get_file_handle(msg_object, SRV_EMAIL_MSG_SAVE_CONTENT, MMI_FALSE);
    if (file_handle < 0)
    {
        header.text_len = 0;
    }
    else
    {
        fs_result = FS_GetFileSize(file_handle, &size);
        FS_Close(file_handle);
        if (fs_result != FS_NO_ERROR)
        {
            header.text_len = 0;
        }
        else
        {
            header.text_len = (size / sizeof(WCHAR)) * 4 + EMAIL_CHARSET_ENCODE_STRING_LEN; /* charset string and base64 encode */
        }
    }
    file_handle = srv_email_msg_get_file_handle(msg_object, SRV_EMAIL_MSG_SAVE_HTML, MMI_FALSE);
    if (file_handle < 0)
    {
        header.html_len = 0;
    }
    else
    {
        fs_result = FS_GetFileSize(file_handle, &size);
        FS_Close(file_handle);
        if (fs_result != FS_NO_ERROR)
        {
            header.html_len = 0;
        }
        else
        {
            header.html_len = (size / sizeof(WCHAR)) * 4 + EMAIL_CHARSET_ENCODE_STRING_LEN; /* charset string and base64 encode */
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE_INT_TEXT_LEN, header.subj_len, header.text_len, header.html_len);

    if (save_part == SRV_EMAIL_MSG_SAVE_SUBJECT || save_part == SRV_EMAIL_MSG_SAVE_CONTENT)
    {
        query_text_callback = srv_email_msg_query_text_func;
    }
    else if (save_part == SRV_EMAIL_MSG_SAVE_ADDR_TO ||
             save_part == SRV_EMAIL_MSG_SAVE_ADDR_CC ||
             save_part == SRV_EMAIL_MSG_SAVE_ADDR_BCC)
    {
        query_addr_callback = srv_email_msg_query_addr_func;
    }
    else if (save_part == SRV_EMAIL_MSG_SAVE_ATTACHMENT_INFO)
    {
        query_attch_callback = srv_email_msg_query_attach_func;
    }
    else // SRV_EMAIL_MSG_SAVE_ALL
    {
        query_text_callback = srv_email_msg_query_text_func;
        query_addr_callback = srv_email_msg_query_addr_func;
        query_attch_callback = srv_email_msg_query_attach_func;
    }
    result = srv_email_stor_msg_update(
                &header,
                query_text_callback,
                query_addr_callback,
                query_attch_callback,
                srv_email_msg_save_callback,
                save_info,
                &msg_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (!srv_email_msg_get_req_id(
                    msg_object,
                    SRV_EMAIL_MSG_OPERATION_SAVE,
                    save_info,
                    req_id,
                    &save_info->req_id))
            {
                srv_email_mem_free(save_info);
                return SRV_EMAIL_RESULT_FAIL;
            }
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            srv_email_mem_free(save_info);
            return result;
        }
    }
    return SRV_EMAIL_RESULT_SUCC;
}


static srv_email_result_enum srv_email_msg_save_new_int(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 *uidl,
                                U8 *acct_digest,
                                EMAIL_ACCT_ID dest_acct_id,
                                EMAIL_FLDR_ID dest_fldr_id,
                                EMAIL_MSG_ID *msg_id,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_save_info_struct *save_info;
    srv_email_stor_msg_create_header_struct header;
    srv_email_msg_info_struct *msg_object;
    srv_email_result_enum result;
    FS_HANDLE file_handle;
    S32 fs_result;
    U32 size;
    applib_time_struct curr_time;
    applib_time_struct result_t;
    float home_tz = GetTimeZone(PhnsetGetHomeCity());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_date_time(&curr_time);
    applib_dt_utc_to_rtc((0 - home_tz), &curr_time, &result_t);
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE_NEW_INT, msg_handle, dest_acct_id, dest_fldr_id);
    save_info = (srv_email_msg_save_info_struct*)srv_email_mem_alloc(sizeof(srv_email_msg_save_info_struct));
    if (save_info == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    if (msg_object->acct_id == EMAIL_ACCT_INVALID_ID)
    {
        msg_object->acct_id = dest_acct_id;
    }
    if (msg_object->fldr_id == EMAIL_FLDR_INVALID_ID)
    {
        msg_object->fldr_id = dest_fldr_id;
    }

    memset(&header, 0, sizeof(srv_email_stor_msg_create_header_struct));
    save_info->msg_object = msg_object;
    save_info->save_new = MMI_TRUE;
    save_info->msg_id = msg_id;
    header.acct_id = dest_acct_id;
    header.fldr_id = dest_fldr_id;
    header.addr_to_num = msg_object->to_addr_num;
    header.addr_cc_num = msg_object->cc_addr_num;
    header.addr_bcc_num = msg_object->bcc_addr_num;
    header.remain_addr_to_num = msg_object->remain_to_addr_num;
    header.remain_addr_cc_num = msg_object->remain_cc_addr_num;
    header.remain_addr_bcc_num = msg_object->remain_bcc_addr_num;
    header.state = msg_object->state;
    header.flag = msg_object->flag;
    header.priority = msg_object->priority;
    header.received_date = applib_dt_mytime_2_utc_sec(&result_t, KAL_TRUE);
    header.server_size = msg_object->server_size;
    header.local_size = msg_object->local_size;
    header.attch_num = msg_object->attach_num;
    header.remain_attach_num = msg_object->remain_attach_num;
    header.local_size = msg_object->local_size;
    if (uidl != NULL)
    {
        header.msg_type = SRV_EMAIL_STOR_MSG_TYPE_RECV;
        memcpy(header.uidl, uidl, SRV_EMAIL_MD5_DIGEST_LEN);
        header.created_date = msg_object->mail_date;
    }
    else
    {
        header.msg_type = SRV_EMIAL_STOR_MSG_TYPE_SENT;
        header.created_date = header.received_date;
    }
    if (acct_digest)
    {
        memcpy(header.acct_digest, acct_digest, SRV_EMAIL_MD5_DIGEST_LEN);
    }
    file_handle = srv_email_msg_get_file_handle(msg_object, SRV_EMAIL_MSG_SAVE_SUBJECT, MMI_FALSE);
    if (file_handle < 0)
    {
        header.subj_len = 0;
        header.list_subj[0] = 0;
    }
    else
    {
        fs_result = FS_GetFileSize(file_handle, &size);
        if (fs_result != FS_NO_ERROR)
        {
            header.subj_len = 0;
            FS_Close(file_handle);
        }
        else
        {
            CHAR *temp_text = NULL;
            U32 read;
            U32 MaxSource = mmi_chset_get_char_size_of_charset((mmi_chset_enum)msg_object->subject_charset);
            U32 MaxDest = mmi_chset_get_char_size_of_charset(CHSET_UTF8);

            if (MaxSource == 0)
            {
                MaxSource = 1;
            }
            header.subj_len = 2 * (MaxDest / MaxSource) * size + EMAIL_CHARSET_ENCODE_STRING_LEN;
            //header.subj_len = size * 2 + EMAIL_CHARSET_ENCODE_STRING_LEN; /* charset string and base64 encode */
            temp_text = (CHAR*)get_ctrl_buffer(size + 2);
            memset(temp_text, 0, size + 2);
            fs_result = FS_Read(file_handle, temp_text, size + 2, &read);
            FS_Close(file_handle);
            if (msg_object->subject_charset > MMI_CHSET_BASE && msg_object->subject_charset < MMI_CHSET_TOTAL)
            {
                mmi_chset_convert((mmi_chset_enum)msg_object->subject_charset, CHSET_UCS2, (CHAR*)temp_text, (CHAR*)header.list_subj, (EMAIL_MAX_LIST_SUBJ_LEN + 1) * 2);
            }
            else
            {
                if (strlen(temp_text) < EMAIL_MAX_LIST_SUBJ_LEN * 2)
                {
                    memcpy(header.list_subj, temp_text, strlen(temp_text));
                }
                else
                {
                    memcpy(header.list_subj, temp_text, EMAIL_MAX_LIST_SUBJ_LEN * 2);
                }
            }
            free_ctrl_buffer(temp_text);
        }
    }
    file_handle = srv_email_msg_get_file_handle(msg_object, SRV_EMAIL_MSG_SAVE_CONTENT, MMI_FALSE);
    if (file_handle < 0)
    {
        header.text_len = 0;
    }
    else
    {
        fs_result = FS_GetFileSize(file_handle, &size);
        FS_Close(file_handle);
        if (fs_result != FS_NO_ERROR)
        {
            header.text_len = 0;
        }
        else
        {
            header.text_len = (size / sizeof(WCHAR)) * 4 + EMAIL_CHARSET_ENCODE_STRING_LEN; /* charset string and base64 encode */
        }
    }
    file_handle = srv_email_msg_get_file_handle(msg_object, SRV_EMAIL_MSG_SAVE_HTML, MMI_FALSE);
    if (file_handle < 0)
    {
        header.html_len = 0;
    }
    else
    {
        fs_result = FS_GetFileSize(file_handle, &size);
        FS_Close(file_handle);
        if (fs_result != FS_NO_ERROR)
        {
            header.html_len = 0;
        }
        else
        {
            header.html_len = (size / sizeof(WCHAR)) * 4 + EMAIL_CHARSET_ENCODE_STRING_LEN; /* charset string and base64 encode */
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE_NEW_INT_TEXT_LEN, header.subj_len, header.text_len, header.html_len);

    result = srv_email_stor_msg_create(
                &header,
                srv_email_msg_query_text_func,
                srv_email_msg_query_addr_func,
                srv_email_msg_query_attach_func,
                srv_email_msg_save_new_callback,
                save_info,
                &msg_object->stor_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (!srv_email_msg_get_req_id(
                    msg_object,
                    SRV_EMAIL_MSG_OPERATION_SAVE_NEW,
                    save_info,
                    req_id,
                    &save_info->req_id))
            {
                srv_email_mem_free(save_info);
                return SRV_EMAIL_RESULT_FAIL;
            }
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            srv_email_mem_free(save_info);
            return result;
        }
    }
    return SRV_EMAIL_RESULT_SUCC;
}


static void srv_email_msg_nwk_proc_func(srv_email_nwk_proc_struct *data)
{
    srv_email_msg_info_struct *msg_object;
    msg_object = (srv_email_msg_info_struct*)data->user_data;
    if (msg_object->proc_callback != NULL)
    {
        data->user_data = msg_object->proc_user_data;
        (*msg_object->proc_callback)(data);
    }
}


static void srv_email_msg_om_notify_callback(const srv_email_om_notify_struct *data)
{
    if (srv_email_msg_cntx_p->notify_func != NULL)
    {
        (*srv_email_msg_cntx_p->notify_func)((srv_email_om_notify_struct*)data, srv_email_msg_cntx_p->notify_user_data);
    }
}


extern srv_email_result_enum srv_email_msg_save_for_nwk(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 *uidl,
                                U8 *acct_digest,
                                srv_email_msg_save_part_enum save_part,
                                EMAIL_REQ_ID *req_id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAV_FOR_NWK, msg_handle);
    return srv_email_msg_save_int(msg_handle, uidl, acct_digest, save_part, req_id);
}


extern srv_email_result_enum srv_email_msg_save_new_for_nwk(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 *uidl,
                                S32 server_size,
                                U8 *acct_digest,
                                EMAIL_ACCT_ID dest_acct_id,
                                EMAIL_FLDR_ID dest_fldr_id,
                                EMAIL_MSG_ID *msg_id,
                                EMAIL_REQ_ID *req_id)
{
    srv_email_msg_info_struct *msg_object;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_SAVE_NEW_FOR_NWK, msg_handle);
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (msg_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    msg_object->server_size = server_size;
    return srv_email_msg_save_new_int(msg_handle, uidl, acct_digest, dest_acct_id, dest_fldr_id, msg_id, req_id);    
}


extern void srv_email_msg_nwk_pre_save(EMAIL_MSG_ID msg_id, EMAIL_MSG_HANDLE msg_handle)
{
    srv_email_msg_info_struct *msg_object;
    U16 i;

    for (i = 0; i < SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER; i++)
    {
        if (srv_email_msg_cntx_p->msg_array[i].in_use &&
            srv_email_msg_cntx_p->msg_array[i].msg_id == msg_id &&
            (EMAIL_MSG_HANDLE)(&srv_email_msg_cntx_p->msg_array[i]) != msg_handle)
        {
            break;
        }
    }
    if (i == SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER)
    {
        return;
    }

    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    msg_object->msg_id = msg_id;
    msg_object->fldr_id = srv_email_stor_msg_id_to_fldr_id(msg_id);
    msg_object->acct_id = srv_email_stor_msg_id_to_acct_id(msg_id);
    msg_object->recv_date = srv_email_msg_cntx_p->msg_array[i].recv_date;
    msg_object->flag = srv_email_msg_cntx_p->msg_array[i].flag;
}


#ifdef __SMS_CLOUD_SUPPORT__

srv_email_result_enum srv_email_msg_get_extra_field(
                        EMAIL_MSG_HANDLE msg_handle,
                        srv_email_msg_save_part_enum type,
                        CHAR **buff,
                        U32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    srv_email_msg_extra_field_struct *extra_field = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!buff || !len)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    *buff = NULL;
    *len = 0;

    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (!msg_object)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    if (type == SRV_EMAIL_MSG_SAVE_EXTRA_SMS_UID)
    {
        extra_field = &msg_object->sms_uid;
    }
    else if (type == SRV_EMAIL_MSG_SAVE_EXTRA_SMS_ADDR)
    {
        extra_field = &msg_object->sms_addr;
    }
    else if (type == SRV_EMAIL_MSG_SAVE_EXTRA_SMS_DATA)
    {
        extra_field = &msg_object->sms_data;
    }
    else
    {
        MMI_ASSERT(0);
    }

    *buff = extra_field->buff;
    *len = extra_field->buff_len;

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_msg_update_extra_field(
                        EMAIL_MSG_HANDLE msg_handle,
                        srv_email_msg_save_part_enum type,
                        CHAR *buff,
                        U32 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;
    void *temp_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!buff || buff_len == 0)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (!msg_object)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_UPDATE_EXTRA_FIELD, msg_handle, type, buff_len);

    temp_ptr = srv_email_mem_alloc(buff_len);
    if (!temp_ptr)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    memcpy(temp_ptr, buff, buff_len);

    if (type == SRV_EMAIL_MSG_SAVE_EXTRA_SMS_UID)
    {
        msg_object->sms_uid.buff = temp_ptr;
        msg_object->sms_uid.buff_len = buff_len;
    }
    else if (type == SRV_EMAIL_MSG_SAVE_EXTRA_SMS_ADDR)
    {
        msg_object->sms_addr.buff = temp_ptr;
        msg_object->sms_addr.buff_len = buff_len;
    }
    else if (type == SRV_EMAIL_MSG_SAVE_EXTRA_SMS_DATA)
    {
        msg_object->sms_data.buff = temp_ptr;
        msg_object->sms_data.buff_len = buff_len;
    }
    else
    {
        MMI_ASSERT(0);
    }

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_msg_update_date(EMAIL_MSG_HANDLE msg_handle, U32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_info_struct *msg_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_object = srv_email_msg_handle_to_addr(msg_handle);
    if (!msg_object)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (msg_object->access_state != SRV_EMAIL_MSG_ACCESS_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    //??? MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_MSG_UPDATE_EXTRA_FIELD, msg_handle, type, buff_len);

    msg_object->mail_date = (S32)date;

    return SRV_EMAIL_RESULT_SUCC;
}

#endif /* __SMS_CLOUD_SUPPORT__ */

