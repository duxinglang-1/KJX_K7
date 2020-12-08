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
 * EmailSrvAccount.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email account function.
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "customer_ps_inc.h"
#include "Conversions.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "fs_gprot.h"
#include "DebugInitDef_Int.h"
#include "mmi_inet_app_trc.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "EmailSrvAccount.h"
#include "emailsrvgprot.h"
#include "EmailSrvIprot.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvMessage.h"
#include "email_ps_public.h"

#ifdef __SMS_CLOUD_SUPPORT__
#include "CloudSrvGprot.h"
#include "app_base64.h"
#include "app_datetime.h"
#include "app_usedetails.h"
#endif /* __SMS_CLOUD_SUPPORT__ */

typedef struct
{
    U16 valid_number;
    srv_email_acct_object_info_struct account_array[SRV_EMAIL_ACCOUNT_HANDLE_MAX_NUMBER];
} srv_email_acct_cntx_struct;


srv_email_acct_cntx_struct g_srv_email_acct_cntx;
srv_email_acct_cntx_struct *srv_email_acct_cntx_p;
U32 acct_req_id = 1;
CHAR remote_path[] = "RemoteFolder\\";
CHAR remote[] = "remote";
srv_email_result_struct result_data;


static srv_email_acct_object_info_struct *srv_email_acct_handle_to_addr(EMAIL_ACCT_HANDLE acct_handle);
static void srv_email_acct_nwk_finish_notify(srv_email_nwk_finish_struct *data);
static srv_email_result_enum srv_email_acct_pre_connect(
                                srv_email_acct_object_info_struct *account_object,
                                MMI_BOOL incoming,
                                void *user_data);
static MMI_BOOL srv_email_acct_get_req_id(
                    srv_email_acct_object_info_struct *account_object,
                    S32 action,
                    void *operation_info,
                    EMAIL_REQ_ID *req_id_1,
                    EMAIL_REQ_ID *req_id_2);
static void srv_email_acct_clear_req_id(srv_email_acct_object_info_struct *account_object, EMAIL_REQ_ID req_id);
static MMI_BOOL srv_email_acct_read_remote_fldr_info(srv_email_acct_object_info_struct *account_object);
static void srv_email_acct_nwk_proc_notify(srv_email_nwk_proc_struct *data);

#ifdef __SMS_CLOUD_SUPPORT__
static srv_email_result_enum srv_email_acct_cld_get_msg(
                                srv_email_acct_object_info_struct *acct_obj);

static CHAR srv_email_cloud_acct_email_addr[SRV_EMAIL_MAX_ADDR_LEN + 1] = {0};
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_init
 * DESCRIPTION
 *  Account inialiazation
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 res;
    WCHAR dst_file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_acct_cntx_p = &g_srv_email_acct_cntx;
    kal_wsprintf(
        dst_file_path,
        "%s%s",
        srv_email_get_root_path(),
        remote_path);
    FS_XDelete(dst_file_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    if ((res = FS_CreateDir(dst_file_path)) != FS_NO_ERROR)
    {
        srv_email_init_errno_set(res);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_init_acct_info
 * DESCRIPTION
 *  This function is used to initialize the account information.
 * PARAMETERS
 *  acct_info_p     : [OUT]     The pointer point to the account information structure
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_init_acct_info(srv_email_acct_info_struct *acct_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_server_struct *in_server_p = NULL;
    srv_email_server_struct *out_server_p = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INIT_ACCT_INFO);

    memset(acct_info_p, 0, sizeof(srv_email_acct_info_struct));

    /* use customer function to init data like port server addr etc. */
    in_server_p = &acct_info_p->in_server;
    out_server_p = &acct_info_p->out_server;

    for (i = 0; i < MMI_SIM_TOTAL; ++i)
    {
        in_server_p->data_acct[i] = cbm_encode_data_account_id(
                                        CBM_DEFAULT_ACCT_ID,
                                        (cbm_sim_id_enum)(CBM_SIM_ID_SIM1 + i),
                                        0,
                                        MMI_FALSE);
        out_server_p->data_acct[i] = in_server_p->data_acct[i];
    }

    acct_info_p->in_auth.auth_type = SRV_EMAIL_AUTH_USER;
    acct_info_p->out_auth.auth_type = SRV_EMAIL_AUTH_NONE;
    acct_info_p->send_option = SRV_EMAIL_SEND_IMMEDIATELY;
    acct_info_p->download_option = SRV_EMAIL_DOWNLOAD_HEADER;
    acct_info_p->download_size = MMI_EMAIL_MAX_MSG_SIZE;
    acct_info_p->retrieve_amount = SRV_EMAIL_GLOBAL_MAX_MSG_NUM;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_check_valid
 * DESCRIPTION
 *  This function is used to check if the account is valid.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  is_valid        : [OUT]     Return the validity
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_check_valid(EMAIL_ACCT_ID acct_id, MMI_BOOL *is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID acct_id_array[EMAIL_STOR_ACCT_NUM_MAX];
    U32 num;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_valid == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    if (acct_id == EMAIL_ACCT_INVALID_ID)
    {
        *is_valid = MMI_FALSE;
        return SRV_EMAIL_RESULT_SUCC;
    }
    num = srv_email_stor_acct_id_get(acct_id_array);
    for (i = 0; i < num; i++)
    {
        if (acct_id_array[i] == acct_id)
        {
            *is_valid = MMI_TRUE;
            break;
        }
    }
    if (i == num)
    {
        *is_valid = MMI_FALSE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_ID_VALID,
        acct_id,
        *is_valid);
    return SRV_EMAIL_RESULT_SUCC;
}

/************************* Account list related APIs *************************/

/************************* Account ID related APIs **************************/

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_num
 * DESCRIPTION
 *  This function is used to get the number of email account.
 * PARAMETERS
 *  acct_num        : [OUT]     Return the account's number
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_num(U32 *acct_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID acct_id_array[EMAIL_STOR_ACCT_NUM_MAX];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_num == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    *acct_num = srv_email_stor_acct_id_get(acct_id_array);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_acct_id
 * DESCRIPTION
 *  This function is used to get the account's id in the specified scope.
 * PARAMETERS
 *  start_index     : [IN]      The account index start to get (from 1)
 *  acct_cnt        : [IN/OUT]  IN  - The length of account id buffer
 *                              OUT - The account number returned
 *  acct_id         : [OUT]     The pointer point to the account id buffer
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_acct_id(
                                S32 start_index,
                                S32 *acct_cnt,
                                EMAIL_ACCT_ID *acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID acct_id_array[EMAIL_STOR_ACCT_NUM_MAX];
    S32 num;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_cnt == NULL || acct_id == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    num = srv_email_stor_acct_id_get(acct_id_array);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_GET_ACCT_ID,
        start_index,
        *acct_cnt,
        num);
    if (num <= start_index)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    for (i = 0; i < *acct_cnt; i++)
    {
        if (i >= num - start_index)
        {
            *acct_cnt = num;
            return SRV_EMAIL_RESULT_SUCC;
        }
        acct_id[i] = acct_id_array[i + start_index];
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_name
 * DESCRIPTION
 *  This function is used to get the name of the specified account.
 * PARAMETERS
 *  acct_id         : [IN]      The account index start to get (from 1)
 *  acct_name       : [OUT]     Used to store the account name (WCHAR string)
 *  name_len        : [IN]      The length of the account name buffer (WCHAR)
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_name(EMAIL_ACCT_ID acct_id, WCHAR *acct_name, S32 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_info_struct *acct_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_name == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    acct_info = (srv_email_acct_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_info_struct));
    if (acct_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_info->acct_id = acct_id;
    result = srv_email_stor_acct_info_read(acct_info);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_mem_free(acct_info);
        return result;
    }
    if (name_len >= SRV_EMAIL_MAX_ACCT_NAME_LEN + 1)
    {
        memcpy(acct_name, acct_info->acct_name, (SRV_EMAIL_MAX_ACCT_NAME_LEN + 1) * 2);
    }
    else
    {
        memcpy(acct_name, acct_info->acct_name, name_len * 2);
    }
    srv_email_mem_free(acct_info);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_set_default
 * DESCRIPTION
 *  This function is used to set an account as default account.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_set_default(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    MMI_BOOL is_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_id == EMAIL_ACCT_INVALID_ID)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    result = srv_email_acct_check_valid(acct_id, &is_valid);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_DEFAULT,
        MMI_TRUE,
        acct_id,
        is_valid);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    if (!is_valid)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    return srv_email_stor_acct_default_id_set(acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_del_default
 * DESCRIPTION
 *  This function is used to delete the default account(NOT delete the account).
 * PARAMETERS
 *
 * RETURNS
 *  void
 ****************************************************************************/
srv_email_result_enum srv_email_acct_del_default(void)
{
    return srv_email_stor_acct_default_id_del();
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_default
 * DESCRIPTION
 *  This function is used to get the default account.
 * PARAMETERS
 *  acct_id         : [OUT]     Return the account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_default(EMAIL_ACCT_ID *acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_id == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    res = srv_email_stor_acct_default_id_get(acct_id);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_DEFAULT,
        MMI_FALSE,
        *acct_id);
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_delete
 * DESCRIPTION
 *  This function is used to delete the specified account.
 *  The account must meet the following conditions at the same time:
 *   1. it is not opened by any instance.
 *   2. it is not used now.
 *  When deleting account, all emails in it will be deleted at the same time.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  req_id          : [OUT]     Return the request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_delete(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_id == EMAIL_ACCT_INVALID_ID)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    /* Can't be deleted when account handle is created base on this account */
    for (i = 0; i < SRV_EMAIL_ACCOUNT_HANDLE_MAX_NUMBER; i++)
    {
        if (srv_email_acct_cntx_p->account_array[i].in_use &&
            srv_email_acct_cntx_p->account_array[i].acct_id == acct_id)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_ACCT_DELETE_IN_USE,
                acct_id);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_DELETE,
        acct_id);
    return srv_email_stor_acct_del(acct_id);
}


/********************** Account instance related APIs ***********************/

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_create
 * DESCRIPTION
 *  This function is used to create a new account instance for the specified account.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 *  acct_handle     : [OUT]     Used to store the account instance handle
 * RETURNS
 *  The account handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_create(
    EMAIL_SRV_HANDLE srv_handle, EMAIL_ACCT_HANDLE *acct_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_handle == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    for (i = 0; i < SRV_EMAIL_ACCOUNT_HANDLE_MAX_NUMBER; i++)
    {
        if (!srv_email_acct_cntx_p->account_array[i].in_use)
        {
            srv_email_acct_cntx_p->account_array[i].in_use = MMI_TRUE;
            srv_email_acct_cntx_p->account_array[i].srv_handle = srv_handle;
            srv_email_acct_cntx_p->account_array[i].state = SRV_EMAIL_ACCT_STATE_INIT;
        #ifdef __SMS_CLOUD_SUPPORT__
            srv_email_acct_cntx_p->account_array[i].conn_type = SRV_EMAIL_ACCT_CONN_NORMAL;
        #endif
            srv_email_acct_cntx_p->valid_number++;
            *acct_handle = (EMAIL_ACCT_HANDLE)&srv_email_acct_cntx_p->account_array[i];
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_ACCT_CREATE_SUCC,
                srv_email_acct_cntx_p->valid_number,
                *acct_handle);
            return SRV_EMAIL_RESULT_SUCC;
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_CREATE_FAIL,
        srv_email_acct_cntx_p->valid_number);
    return SRV_EMAIL_RESULT_CREATE_INSTANCE_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified account instance.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_destroy(EMAIL_ACCT_HANDLE acct_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->account_info != NULL)
    {
        srv_email_mem_free(account_object->account_info);
    }
    if (account_object->nwk_incoming_handle != EMAIL_NWK_INVALID_HANDLE)
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
        }
        else
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
        }
    }
    if (account_object->nwk_outgoing_handle != EMAIL_NWK_INVALID_HANDLE)
    {
        srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
    }

#ifdef __SMS_CLOUD_SUPPORT__
    if (account_object->conn.conn_mailbox)
    {
        srv_email_mem_free(account_object->conn.conn_mailbox);
    }
    if (account_object->cld_msg_hd != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(account_object->cld_msg_hd);
    }
#endif /* __SMS_CLOUD_SUPPORT__ */

    memset(account_object, 0, sizeof(srv_email_acct_object_info_struct));
    srv_email_acct_cntx_p->valid_number--;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_DESTROY,
        srv_email_acct_cntx_p->valid_number,
        acct_handle);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_new
 * DESCRIPTION
 *  This function is used to create a new account.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  acct_id         : [OUT]     Return the new account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_new(
    EMAIL_ACCT_HANDLE acct_handle, EMAIL_ACCT_ID *acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_id == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_INIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    result = srv_email_stor_acct_create_request(acct_id);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_NEW,
        result,
        *acct_id);
    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        account_object->acct_id = *acct_id;
        account_object->state = SRV_EMAIL_ACCT_STATE_EDIT;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_cancel
 * DESCRIPTION
 *  This function is used to cancel creating an account (MUST called before acct_save).
 * PARAMETERS
 *  acct_id         : [OUT]     Return the new account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_cancel(EMAIL_ACCT_ID acct_id)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_NEW_CANCEL,
        acct_id);
    return srv_email_stor_acct_create_cancel(acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_open
 * DESCRIPTION
 *  This function is used to open the specified account.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  acct_id         : [IN]      The account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_open(
                                EMAIL_ACCT_HANDLE acct_handle,
                                EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_INIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    account_object->acct_id = acct_id;
    account_object->state = SRV_EMAIL_ACCT_STATE_READ;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_OPEN,
        acct_id);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_permission
 * DESCRIPTION
 *  This function is used to get the editable permission.
 *  If the instance wants to get the permission,
 *  the account in it must meet the following conditions at the same time:
 *   1. it is opened by this instance only.
 *   2. it is not used now.
 *  After getting successfully, the permission can not be released until the handle is destroyed.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_permission(EMAIL_ACCT_HANDLE acct_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state == SRV_EMAIL_ACCT_STATE_EDIT)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    if (srv_email_om_get_acct_permission(account_object->acct_id, SRV_EMAIL_OM_PERMISSION_WRITE))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_ACCT_GET_PERMISSION,
            account_object->acct_id,
            MMI_TRUE);
        account_object->state = SRV_EMAIL_ACCT_STATE_EDIT;
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_ACCT_GET_PERMISSION,
            account_object->acct_id,
            MMI_FALSE);
        return SRV_EMAIL_RESULT_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_edit
 * DESCRIPTION
 *  This function is used to edit the account information.
 *  The instance with the permission can edit the account's information only.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  acct_info_p     : [IN]      The pointer point to the parameter struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_edit(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_info_struct *acct_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_EDIT,
        account_object->acct_id,
        acct_info_p);

    if (account_object->account_info == NULL)
    {
        account_object->account_info =
            (srv_email_acct_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_info_struct));
        if (account_object->account_info == NULL)
        {
            return SRV_EMAIL_RESULT_NO_MEMORY;
        }
    }
    memcpy(account_object->account_info, acct_info_p, sizeof(srv_email_acct_info_struct));
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_save
 * DESCRIPTION
 *  This function is used to save the account information into storage.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_save(EMAIL_ACCT_HANDLE acct_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_SAVE, acct_handle);

    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    if (account_object->account_info == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    return srv_email_stor_acct_info_write(account_object->account_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_save_async
 * DESCRIPTION
 *  This function is used to save the account information into storage.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_save_async(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_async_save_acct_callback callback,
                                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_SAVE,
        acct_handle);

    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_EDIT)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    if (account_object->account_info == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    return srv_email_stor_acct_info_write_async(
            account_object->account_info,
            (srv_email_stor_acct_write_funcptr_type)callback, user_data);
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_save_async_abort
 * DESCRIPTION
 *  This function is used to abort async saving operation.
 * PARAMETERS
 *
 * RETURNS
 *  void
 ****************************************************************************/
extern void srv_email_acct_save_async_abort(void)
{
    srv_email_stor_acct_info_write_async_abort();
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_read
 * DESCRIPTION
 *  This function is used to read the information of the specified account.
 *  The instance without the permission can also read the account's information.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  acct_info_p     : [OUT]     Used to store the account information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_read(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_info_struct *acct_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_info_p == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_READ,
        acct_handle,
        account_object->state,
        account_object->acct_id);
    if (account_object->state == SRV_EMAIL_ACCT_STATE_EDIT)
    {
        if (account_object->account_info != NULL)
        {
            memcpy(acct_info_p, account_object->account_info, sizeof(srv_email_acct_info_struct));
        }
        else
        {
            memset(acct_info_p, 0, sizeof(srv_email_acct_info_struct));
        }
        return SRV_EMAIL_RESULT_SUCC;
    }
    else if (account_object->state == SRV_EMAIL_ACCT_STATE_READ)
    {
        acct_info_p->acct_id = account_object->acct_id;
        return srv_email_stor_acct_info_read(acct_info_p);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_register_callback
 * DESCRIPTION
 *  This function is used to register the callback function
 *  for the specified account instance.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  callback        : [IN]      The callback function
 *  user_data       : [IN]      The user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_register_callback(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_funcptr_type callback,
                                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_REGISTER_CALLBACK,
        MMI_FALSE,
        acct_handle,
        callback,
        user_data);
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    account_object->callback = callback;
    account_object->user_data = user_data;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_clear_callback
 * DESCRIPTION
 *  clear account's callback & userdata
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_clear_callback(EMAIL_ACCT_HANDLE acct_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_CLEAR_CALLBACK,
        MMI_FALSE,
        acct_handle);
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    account_object->callback = NULL;
    account_object->user_data = NULL;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_register_proc_callback
 * DESCRIPTION
 *  Register account's proc callback & userdata
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  proc_callback   : [IN]      Callback
 *  proc_user_data  : [IN]      Userdata
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_register_proc_callback(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_nwk_proc_funcptr_type proc_callback,
                                void *proc_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_REGISTER_CALLBACK,
        MMI_TRUE,
        acct_handle,
        proc_callback,
        proc_user_data);
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    account_object->proc_callback = proc_callback;
    account_object->proc_user_data = proc_user_data;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_clear_proc_callback
 * DESCRIPTION
 *  Clear account's proc callback & userdata
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_clear_proc_callback(
    EMAIL_ACCT_HANDLE acct_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_CLEAR_CALLBACK,
        MMI_TRUE,
        acct_handle);
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    account_object->proc_callback = NULL;
    account_object->proc_user_data = NULL;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_nwk_test
 * DESCRIPTION
 *  This function is used to test the connection with incoming/outgoing server.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  incoming_server : [IN]      Connect incoming(TRUE)/outgoing(FALSE) server
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_nwk_test(
                                EMAIL_ACCT_HANDLE acct_handle,
                                MMI_BOOL incoming_server,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    if ((incoming_server && account_object->incoming_connected) ||
        (!incoming_server && account_object->outgoing_connected))
    {
        return SRV_EMAIL_RESULT_SUCC;
    }
    acct_nwk_info = (srv_email_acct_nwk_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (acct_nwk_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_nwk_info->account_object = account_object;
    acct_nwk_info->incoming_server = incoming_server;
    result = srv_email_acct_pre_connect(account_object, incoming_server, acct_nwk_info);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_mem_free(acct_nwk_info);
        return result;
    }
    if (incoming_server)
    {
        result = srv_email_nwk_test_nwk(account_object->nwk_incoming_handle);
    }
    else
    {
        result = srv_email_nwk_test_nwk(account_object->nwk_outgoing_handle);
    }

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (incoming_server)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            else
            {
                srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return result;
        }
        else
        {
            if (!srv_email_acct_get_req_id(
                    account_object,
                    SRV_EMAIL_NWK_TEST_NWK,
                    acct_nwk_info,
                    req_id,
                    &acct_nwk_info->req_id))
            {
                if (incoming_server)
                {
                    srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                    account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
                }
                else
                {
                    srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                    account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
                }
                srv_email_mem_free(acct_nwk_info);
                return SRV_EMAIL_RESULT_FAIL;
            }
            else
            {
                return SRV_EMAIL_RESULT_WOULDBLOCK;
            }
        }
    }
    srv_email_mem_free(acct_nwk_info);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_connect
 * DESCRIPTION
 *  This function is used to connect the incoming/outgoing server.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  incoming_server : [IN]      Connect the incoming/outgoing server
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_connect(
                                EMAIL_ACCT_HANDLE acct_handle,
                                MMI_BOOL incoming_server,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_CONNECT,
        acct_handle,
        incoming_server,
        account_object->incoming_connected,
        account_object->outgoing_connected);
    if ((incoming_server && account_object->incoming_connected) ||
        (!incoming_server && account_object->outgoing_connected))
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    acct_nwk_info = (srv_email_acct_nwk_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (acct_nwk_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_nwk_info->account_object = account_object;
    acct_nwk_info->incoming_server = incoming_server;

    result = srv_email_acct_pre_connect(account_object, incoming_server, acct_nwk_info);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_mem_free(acct_nwk_info);
        return result;
    }

#ifdef __SMS_CLOUD_SUPPORT__
    if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
    {
        result = srv_email_nwk_cloud_connect(
                    account_object->nwk_incoming_handle,
                    account_object->conn.conn_mailbox,
                    MMI_TRUE);
    }
    else
#endif /* __SMS_CLOUD_SUPPORT__ */
    {
        if (incoming_server)
        {
            result = srv_email_nwk_connect(account_object->nwk_incoming_handle);
        }
        else
        {
            result = srv_email_nwk_connect(account_object->nwk_outgoing_handle);
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_CONNECT, result);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
        #ifdef __SMS_CLOUD_SUPPORT__
            if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
            {
                srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            else
        #endif /* __SMS_CLOUD_SUPPORT__ */
            {
                if (incoming_server)
                {
                    srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                    account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
                }
                else
                {
                    srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                    account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
                }
            }
            srv_email_mem_free(acct_nwk_info);
            return result;
        }
        else
        {
            if (!srv_email_acct_get_req_id(
                    account_object,
                    SRV_EMAIL_NWK_CONNECT,
                    acct_nwk_info,
                    req_id,
                    &acct_nwk_info->req_id))
            {
            #ifdef __SMS_CLOUD_SUPPORT__
                if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
                {
                    srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
                    account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
                }
                else
            #endif /* __SMS_CLOUD_SUPPORT__ */
                {
                    if (incoming_server)
                    {
                        srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                        account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
                    }
                    else
                    {
                        srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                        account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
                    }
                }
                srv_email_mem_free(acct_nwk_info);
                return SRV_EMAIL_RESULT_FAIL;
            }
            else
            {
                return SRV_EMAIL_RESULT_WOULDBLOCK;
            }
        }
    }

    if (incoming_server)
    {
        account_object->incoming_connected = MMI_TRUE;
    }
    else
    {
        account_object->outgoing_connected = MMI_TRUE;
    }

    srv_email_mem_free(acct_nwk_info);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_disconnect
 * DESCRIPTION
 *  This function is used to disconnect the incoming/outgoing server.
 * PARAMETERS
 *  acct_handle         : [IN]      The account handle
 *  incoming_server     : [IN]      Disconnect the incoming/outgoing server
 *  force_disconnect    : [IN]      Disconnect forcedly or not
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_disconnect(
                                EMAIL_ACCT_HANDLE acct_handle,
                                MMI_BOOL incoming_server,
                                MMI_BOOL force_disconnect,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_DISCONNECT,
        acct_handle,
        incoming_server,
        force_disconnect,
        account_object->incoming_connected,
        account_object->outgoing_connected);

    if (force_disconnect)
    {
        if (incoming_server)
        {
            if (account_object->nwk_incoming_handle != EMAIL_NWK_INVALID_HANDLE)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            return SRV_EMAIL_RESULT_SUCC;
        }
        else
        {
            if (account_object->nwk_outgoing_handle != EMAIL_NWK_INVALID_HANDLE)
            {
                srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_SUCC;
            }
        }
    }

    if ((incoming_server && account_object->nwk_incoming_handle == EMAIL_NWK_INVALID_HANDLE) ||
        (!incoming_server && account_object->nwk_outgoing_handle == EMAIL_NWK_INVALID_HANDLE))
    {
        return SRV_EMAIL_RESULT_SUCC;
    }
    acct_nwk_info = (srv_email_acct_nwk_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (acct_nwk_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_nwk_info->account_object = account_object;
    acct_nwk_info->incoming_server = incoming_server;

    srv_email_nwk_set_finish_notify(
        account_object->nwk_incoming_handle,
        srv_email_acct_nwk_finish_notify,
        acct_nwk_info);
    if (incoming_server)
    {
        result = srv_email_nwk_disconnect(account_object->nwk_incoming_handle);
    }
    else
    {
        result = srv_email_nwk_disconnect(account_object->nwk_outgoing_handle);
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_DISCONNECT, result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (srv_email_acct_get_req_id(
                    account_object,
                    SRV_EMAIL_NWK_DISCONNECT,
                    acct_nwk_info,
                    req_id,
                    &acct_nwk_info->req_id))
            {
                return SRV_EMAIL_RESULT_WOULDBLOCK;
            }
            else
            {
                srv_email_mem_free(acct_nwk_info);
                return SRV_EMAIL_RESULT_FAIL;
            }
        }
        else
        {
            srv_email_mem_free(acct_nwk_info);
            return result;
        }
    }
    else
    {
        srv_email_mem_free(acct_nwk_info);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_send
 * DESCRIPTION
 *  This function is used to send the emails in the outbox of this account.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  move_to_sent    : [IN]      Move to sent box or not after send successfully
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_send(
                        EMAIL_ACCT_HANDLE acct_handle,
                        MMI_BOOL move_to_sent,
                        EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_nwk_send_struct send_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_id == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_SEND,
        acct_handle,
        move_to_sent,
        account_object->outgoing_connected);
    acct_nwk_info = (srv_email_acct_nwk_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (acct_nwk_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_nwk_info->account_object = account_object;
    acct_nwk_info->incoming_server = MMI_FALSE;
    if (!account_object->outgoing_connected)
    {
        result = srv_email_acct_pre_connect(account_object, MMI_FALSE, acct_nwk_info);
    }
    else
    {
        result = srv_email_nwk_set_finish_notify(
                    account_object->nwk_outgoing_handle,
                    srv_email_acct_nwk_finish_notify,
                    acct_nwk_info);
    }
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        /* outgoing server will not be connected */
        if (account_object->outgoing_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
            account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        srv_email_mem_free(acct_nwk_info);
        return result;
    }
    send_info.move_to_sent = move_to_sent;
    send_info.send_outbox = MMI_TRUE;
    send_info.msg_handle = (EMAIL_MSG_HANDLE)NULL;
    send_info.msg_id = EMAIL_MSG_INVALID_ID;
    result = srv_email_nwk_send(account_object->nwk_outgoing_handle, &send_info);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_SEND, result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (account_object->outgoing_connected == MMI_FALSE)
            {
                srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return result;
        }
        if (srv_email_acct_get_req_id(
                account_object,
                SRV_EMAIL_NWK_SEND,
                acct_nwk_info,
                req_id,
                &acct_nwk_info->req_id))
        {
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            if (account_object->outgoing_connected == MMI_FALSE)
            {
                srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    else
    {
        if (account_object->outgoing_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
            account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        srv_email_mem_free(acct_nwk_info);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_receive
 * DESCRIPTION
 *  This function is used to receive the emails of this account from server.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  recv_opt        : [IN]      The receive option
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_receive(
                        EMAIL_ACCT_HANDLE acct_handle,
                        srv_email_receive_option_enum recv_opt,
                        EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_nwk_recv_struct recv_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_id == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_RECEIVE,
        acct_handle,
        recv_opt,
        account_object->incoming_connected);
    acct_nwk_info = (srv_email_acct_nwk_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (acct_nwk_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_nwk_info->account_object = account_object;
    acct_nwk_info->incoming_server = MMI_TRUE;
    if (!account_object->incoming_connected)
    {
        result = srv_email_acct_pre_connect(account_object, MMI_TRUE, acct_nwk_info);
    }
    else
    {
        result = srv_email_nwk_set_finish_notify(
            account_object->nwk_incoming_handle,
            srv_email_acct_nwk_finish_notify,
            acct_nwk_info);
    }
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        srv_email_mem_free(acct_nwk_info);
        return result;
    }
    recv_info.recv_opt = recv_opt;
    recv_info.all_fldr = MMI_TRUE;
    recv_info.fldr_id = EMAIL_FLDR_INVALID_ID;
    result = srv_email_nwk_receive(account_object->nwk_incoming_handle, &recv_info);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_RECEIVE, result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (account_object->incoming_connected == MMI_FALSE)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return result;
        }
        if (srv_email_acct_get_req_id(
                account_object,
                SRV_EMAIL_NWK_RECEIVE,
                acct_nwk_info,
                req_id,
                &acct_nwk_info->req_id))
        {
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            if (account_object->incoming_connected == MMI_FALSE)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    else
    {
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        srv_email_mem_free(acct_nwk_info);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_sync
 * DESCRIPTION
 *  This function is used to sync the emails of this account with server.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_sync(
                        EMAIL_ACCT_HANDLE acct_handle,
                        EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_nwk_sync_struct sync_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_id == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_SYNC,
        acct_handle,
        account_object->incoming_connected);
    acct_nwk_info = (srv_email_acct_nwk_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (acct_nwk_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_nwk_info->account_object = account_object;
    acct_nwk_info->incoming_server = MMI_TRUE;
    if (!account_object->incoming_connected)
    {
        result = srv_email_acct_pre_connect(account_object, MMI_TRUE, acct_nwk_info);
    }
    else
    {
        result = srv_email_nwk_set_finish_notify(
                    account_object->nwk_incoming_handle,
                    srv_email_acct_nwk_finish_notify,
                    acct_nwk_info);
    }
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        srv_email_mem_free(acct_nwk_info);
        return result;
    }
    sync_info.all_fldr = MMI_TRUE;
    sync_info.all_msg = MMI_TRUE;
    sync_info.fldr_id = EMAIL_FLDR_INVALID_ID;
    sync_info.msg_id = EMAIL_MSG_INVALID_ID;
    result = srv_email_nwk_sync(account_object->nwk_incoming_handle, &sync_info);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_SYNC, result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (account_object->incoming_connected == MMI_FALSE)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return result;
        }
        if (srv_email_acct_get_req_id(
                account_object,
                SRV_EMAIL_NWK_SYNC,
                acct_nwk_info,
                req_id,
                &acct_nwk_info->req_id))
        {
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            if (account_object->incoming_connected == MMI_FALSE)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    else
    {
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        srv_email_mem_free(acct_nwk_info);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_fldr_num
 * DESCRIPTION
 *  This function is used to get the folder's number.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  fldr_type       : [IN]      
 *  fldr_num        : [OUT]     Return the folder's number
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_fldr_num(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_fldr_type_enum fldr_type,
                                S32 *fldr_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_fldr_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fldr_num == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (fldr_type == SRV_EMAIL_ACCT_FLDR_TYPE_BASIC)
    {
        type = SRV_EMAIL_FLDR_TYPE_BASICS;
    }
    else
    {
        type = SRV_EMAIL_FLDR_TYPE_REMOTE;
    }
    *fldr_num = srv_email_stor_acct_get_fldr_num(
                    account_object->acct_id,
                    type);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_GET_FLDR_NUM,
        account_object->acct_id,
        type,
        *fldr_num);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_fldr_id
 * DESCRIPTION
 *  This function is used to get the folder's id.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  local_fldr      : [IN]      The local folder or not
 *  start_index     : [IN]      The folder index start to get (from 0)
 *  fldr_cnt        : [IN/OUT]  IN  - The length of folder id buffer
 *                              OUT - The folder number returned
 *  fldr_id         : [OUT]     The pointer point to the folder id buffer
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_fldr_id(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_fldr_type_enum fldr_type,
                                S32 start_index,
                                S32 *fldr_cnt,
                                EMAIL_FLDR_ID *fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_result_enum result;
    EMAIL_FLDR_ID temp_fldr_id;
    U16 i;
    S32 get_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fldr_cnt == NULL || *fldr_cnt == 0 || fldr_id == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    if (fldr_type == SRV_EMAIL_ACCT_FLDR_TYPE_BASIC && start_index >= SRV_EMAIL_FLDR_TYPE_BASICS)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_GET_FLDR_ID,
        account_object->acct_id,
        fldr_type,
        start_index,
        *fldr_cnt);
    if (fldr_type == SRV_EMAIL_ACCT_FLDR_TYPE_BASIC)
    {
        for (i = start_index; i < SRV_EMAIL_FLDR_TYPE_BASICS_CNT; i++)
        {
            if (i - start_index >= *fldr_cnt)
            {
                return SRV_EMAIL_RESULT_SUCC;
            }
            fldr_id[i - start_index] = srv_email_stor_fldr_get_id_by_type(account_object->acct_id, (srv_email_fldr_type_enum)i);
        }
        *fldr_cnt = i - start_index;
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        result = srv_email_stor_acct_get_fldr_id_open(account_object->acct_id, SRV_EMAIL_FLDR_TYPE_REMOTE, &account_object->stor_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            return result;
        }
        for (i = 0; i < start_index + *fldr_cnt; i++)
        {
            result = srv_email_stor_acct_get_fldr_id_next(account_object->stor_handle, &temp_fldr_id);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_stor_acct_get_fldr_id_close(account_object->stor_handle);
                account_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
                if (result == SRV_EMAIL_RESULT_NO_MORE_RESULT)
                {
                    *fldr_cnt = get_count;
                    return SRV_EMAIL_RESULT_SUCC;
                }
                return result;
            }
            if (i >= start_index)
            {
                get_count++;
                fldr_id[i - start_index] = temp_fldr_id;
            }
        }
        srv_email_stor_acct_get_fldr_id_close(account_object->stor_handle);
        account_object->stor_handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_fldr_info
 * DESCRIPTION
 *  This function is used to get the folder's information.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  fldr_id         : [IN]      The folder id
 *  fldr_info_p     : [OUT]     Used to store the folder's information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_fldr_info(
                                EMAIL_ACCT_HANDLE acct_handle,
                                EMAIL_FLDR_ID fldr_id,
                                srv_email_acct_folder_struct *fldr_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_stor_fldr_struct stor_fldr_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fldr_info_p == NULL || fldr_id == EMAIL_FLDR_INVALID_ID)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    result = srv_email_stor_fldr_get_by_id(
                account_object->acct_id,
                fldr_id,
                &stor_fldr_info);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_GET_FLDR_INFO,
        account_object->acct_id,
        fldr_id,
        stor_fldr_info.unread_count,
        stor_fldr_info.total_count,
        result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    if (stor_fldr_info.fldr_type == SRV_EMAIL_FLDR_TYPE_REMOTE)
    {
        fldr_info_p->fldr_type = SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL;
    }
    else
    {
        fldr_info_p->fldr_type = SRV_EMAIL_ACCT_FLDR_TYPE_BASIC;
    }
    fldr_info_p->msg_count = stor_fldr_info.total_count;
    fldr_info_p->unread_count = stor_fldr_info.unread_count;
    fldr_info_p->fldr_name_separator = stor_fldr_info.fldr_name_separator;
    mmi_chset_convert(
        CHSET_UTF8,
        MMI_CHSET_UCS2,
        stor_fldr_info.fldr_name,
        (CHAR*)fldr_info_p->folder_name,
        (SRV_EMAIL_FLDR_NAME_LEN + 1));
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_list_remote_fldr
 * DESCRIPTION
 *  This function is used to get the folder's number.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  fldr_cnt        : [IN]      The count of the folder can be listed
 *  req_id          : [OUT]     Return the request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_list_remote_fldr(
                                EMAIL_ACCT_HANDLE acct_handle,
                                S32 fldr_cnt,
                                EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_nwk_list_fldr_struct list_remote_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_id == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_LIST_REMOTE_FLDR,
        account_object->acct_id,
        fldr_cnt);
    acct_nwk_info = (srv_email_acct_nwk_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (acct_nwk_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_nwk_info->account_object = account_object;
    acct_nwk_info->incoming_server = MMI_TRUE;
    if (!account_object->incoming_connected)
    {
        result = srv_email_acct_pre_connect(account_object, MMI_TRUE, acct_nwk_info);
    }
    else
    {
        result = srv_email_nwk_set_finish_notify(
                    account_object->nwk_incoming_handle,
                    srv_email_acct_nwk_finish_notify,
                    acct_nwk_info);
    }
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        srv_email_mem_free(acct_nwk_info);
        return result;
    }
    list_remote_info.subscribed_only = MMI_FALSE;
    list_remote_info.fldr_num = SRV_EMAIL_ACCOUNT_MAX_REMOTE_FLDR_NUMBER;
    kal_wsprintf(
        list_remote_info.filename,
        "%s%s%s%d",
        srv_email_get_root_path(),
        remote_path,
        remote,
        account_object->acct_id);
    result = srv_email_nwk_list_folder(account_object->nwk_incoming_handle, &list_remote_info);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_LIST_FOLDER, result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            if (account_object->incoming_connected == MMI_FALSE)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return result;
        }
        if (srv_email_acct_get_req_id(
            account_object,
            SRV_EMAIL_NWK_LIST_FOLDER,
            acct_nwk_info,
            req_id,
            &acct_nwk_info->req_id))
        {
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            if (account_object->incoming_connected == MMI_FALSE)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            srv_email_mem_free(acct_nwk_info);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    else
    {
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        srv_email_mem_free(acct_nwk_info);
        //return SRV_EMAIL_RESULT_SUCC;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_subscribe_remote_fldr
 * DESCRIPTION
 *  This function is used to subscribe the IMAP4 remote folders
 *  (used for IMAP4 remote folder only).
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  index           : [IN]      The folder index
 *  subscribe       : [IN]      Subscribe/Unsubscribe the folder
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_subscribe_remote_fldr(
                                EMAIL_ACCT_HANDLE acct_handle,
                                U32 index,
                                MMI_BOOL subscribe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    //if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    //{
    //    return SRV_EMAIL_RESULT_INVALID_STATE;
    //}
    if (index >= account_object->remote_fldr_num)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_SUBSCRIBE, account_object->acct_id, index, subscribe);
    account_object->remote_fldr_sub[index] = subscribe;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_remote_fldr_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_acct_get_remote_fldr_num(
                        EMAIL_ACCT_HANDLE acct_handle,
                        U32 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    //if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    //{
    //    return SRV_EMAIL_RESULT_INVALID_STATE;
    //}
    *num = account_object->remote_fldr_num;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_GET_REMOTE_FLDR_NUM, account_object->acct_id, *num);
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_remote_fldr_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_acct_get_remote_fldr_info(
                        EMAIL_ACCT_HANDLE acct_handle,
                        U32 start_index,
                        U32 *fldr_cnt,
                        srv_email_acct_remote_fldr_info_strcut *remote_fldr_info_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_nwk_fldr_info_struct nwk_remote_info;
    WCHAR dst_file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE file_handle;
    U32 num;
    U32 index;
    S32 result;
    U32 read;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_GET_REMOTE_FLDR_INFO,
        account_object->acct_id,
        start_index,
        *fldr_cnt);

    //if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    //{
    //    return SRV_EMAIL_RESULT_INVALID_STATE;
    //}
    kal_wsprintf(
        dst_file_path,
        "%s%s%s%d",
        srv_email_get_root_path(),
        remote_path,
        remote,
        account_object->acct_id);
    file_handle = FS_Open(dst_file_path, FS_READ_ONLY);
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
    num = (size - sizeof(srv_email_nwk_fldr_info_header_struct)) / sizeof(srv_email_nwk_fldr_info_struct);
    if (num <= start_index)
    {
        FS_Close(file_handle);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    result = FS_Seek(
                file_handle,
                start_index * sizeof(srv_email_nwk_fldr_info_struct) + sizeof(srv_email_nwk_fldr_info_header_struct),
                FS_FILE_BEGIN);
    if (result < 0)
    {
        FS_Close(file_handle);
        srv_email_errno_set(result);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    for (index = start_index; index < start_index + *fldr_cnt && index < num; index++)
    {
        result = FS_Read(
                    file_handle,
                    &nwk_remote_info,
                    sizeof(srv_email_nwk_fldr_info_struct),
                    &read);
        if (result != FS_NO_ERROR || read != sizeof(srv_email_nwk_fldr_info_struct))
        {
            FS_Close(file_handle);
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        remote_fldr_info_list[index - start_index].subscribed = nwk_remote_info.subscribed;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_ACCT_GET_REMOTE_FLDR_INFO_SUB,
            account_object->acct_id,
            index,
            nwk_remote_info.subscribed);
        mmi_chset_convert(
            CHSET_UTF8,
            CHSET_UCS2,
            (CHAR*)nwk_remote_info.folder_name,
            (CHAR*)remote_fldr_info_list[index - start_index].folder_name,
            (SRV_EMAIL_FLDR_NAME_LEN + 1) * 2);
        remote_fldr_info_list[index - start_index].fldr_name_separator = account_object->remote_fldr_seperator;
    }
    *fldr_cnt = index - start_index;
    FS_Close(file_handle);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_remote_fldr_submit_subscribe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_acct_remote_fldr_submit_subscribe(EMAIL_ACCT_HANDLE acct_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_nwk_fldr_info_struct *nwk_remote_info = NULL;
    srv_email_stor_fldr_create_info_struct *fldr_create_info = NULL;
    srv_email_result_enum stor_result;
    WCHAR file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    EMAIL_FLDR_ID fldr_id;
    FS_HANDLE file_handle;
    U32 read;
    S32 result;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_REMOTE_FLDR_SUBMIT,
        account_object->acct_id);
    kal_wsprintf(
        file_path,
        "%s%s%s%d",
        srv_email_get_root_path(),
        remote_path,
        remote,
        account_object->acct_id);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    if (file_handle < 0)
    {
        srv_email_errno_set(file_handle);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    result = FS_Seek(file_handle, sizeof(srv_email_nwk_fldr_info_header_struct), FS_FILE_BEGIN);
    if (result < 0)
    {
        FS_Close(file_handle);
        srv_email_errno_set(result);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    nwk_remote_info = (srv_email_nwk_fldr_info_struct*)get_ctrl_buffer(sizeof(srv_email_nwk_fldr_info_struct));
    fldr_create_info = (srv_email_stor_fldr_create_info_struct*)get_ctrl_buffer(sizeof(srv_email_stor_fldr_create_info_struct));
    for (index = 0; index < account_object->remote_fldr_num; index++)
    {
        result = FS_Read(
                    file_handle,
                    nwk_remote_info,
                    sizeof(srv_email_nwk_fldr_info_struct),
                    &read);
        if (result != FS_NO_ERROR || read != sizeof(srv_email_nwk_fldr_info_struct))
        {
            free_ctrl_buffer(nwk_remote_info);
            free_ctrl_buffer(fldr_create_info);
            FS_Close(file_handle);
            srv_email_errno_set(result);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_ACCT_REMOTE_FLDR_SUBMIT_INFO,
            index,
            account_object->remote_fldr_sub[index],
            nwk_remote_info->subscribed,
            nwk_remote_info->fldr_id);
        if (account_object->remote_fldr_sub[index])
        {
            if (!nwk_remote_info->subscribed)
            {
                fldr_create_info->fldr_type = SRV_EMAIL_FLDR_TYPE_REMOTE;
                fldr_create_info->fldr_name_separator = (CHAR)account_object->remote_fldr_seperator;
                memcpy(fldr_create_info->fldr_name, nwk_remote_info->folder_name, SRV_EMAIL_MAX_FOLDER_NAME_LEN);
                stor_result = srv_email_stor_fldr_create(account_object->acct_id, fldr_create_info, &fldr_id);
                if (stor_result != SRV_EMAIL_RESULT_SUCC)
                {
                    free_ctrl_buffer(nwk_remote_info);
                    free_ctrl_buffer(fldr_create_info);
                    FS_Close(file_handle);
                    return stor_result;
                }
                nwk_remote_info->subscribed = MMI_TRUE;
                nwk_remote_info->fldr_id = fldr_id;
                result = FS_Seek(
                            file_handle,
                            index * sizeof(srv_email_nwk_fldr_info_struct) + sizeof(srv_email_nwk_fldr_info_header_struct),
                            FS_FILE_BEGIN);
                if (result < 0)
                {
                    free_ctrl_buffer(nwk_remote_info);
                    free_ctrl_buffer(fldr_create_info);
                    FS_Close(file_handle);
                    srv_email_errno_set(result);
                    return SRV_EMAIL_RESULT_FS_ERROR;
                }
                result = FS_Write(file_handle, nwk_remote_info, sizeof(srv_email_nwk_fldr_info_struct), &read);
                if (result != FS_NO_ERROR || read != sizeof(srv_email_nwk_fldr_info_struct))
                {
                    free_ctrl_buffer(nwk_remote_info);
                    free_ctrl_buffer(fldr_create_info);
                    FS_Close(file_handle);
                    srv_email_errno_set(result);
                    return SRV_EMAIL_RESULT_FS_ERROR;
                }
            }
        }
        else
        {
            if (nwk_remote_info->subscribed)
            {
                stor_result = srv_email_stor_fldr_del(account_object->acct_id, &nwk_remote_info->fldr_id, 1);
                if (stor_result == SRV_EMAIL_RESULT_SUCC)
                {
                    nwk_remote_info->subscribed = MMI_FALSE;
                    nwk_remote_info->fldr_id = EMAIL_FLDR_INVALID_ID;
                    result = FS_Seek(
                                file_handle,
                                index * sizeof(srv_email_nwk_fldr_info_struct) + sizeof(srv_email_nwk_fldr_info_header_struct),
                                FS_FILE_BEGIN);
                    if (result < 0)
                    {
                        free_ctrl_buffer(nwk_remote_info);
                        free_ctrl_buffer(fldr_create_info);
                        FS_Close(file_handle);
                        srv_email_errno_set(result);
                        return SRV_EMAIL_RESULT_FS_ERROR;
                    }
                    result = FS_Write(file_handle, nwk_remote_info, sizeof(srv_email_nwk_fldr_info_struct), &read);
                    if (result != FS_NO_ERROR || read != sizeof(srv_email_nwk_fldr_info_struct))
                    {
                        free_ctrl_buffer(nwk_remote_info);
                        free_ctrl_buffer(fldr_create_info);
                        FS_Close(file_handle);
                        srv_email_errno_set(result);
                        return SRV_EMAIL_RESULT_FS_ERROR;
                    }
                }
            }
        }
    }
    free_ctrl_buffer(nwk_remote_info);
    free_ctrl_buffer(fldr_create_info);
    FS_Close(file_handle);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_abort
 * DESCRIPTION
 *  This function is used to abort async request for the specified account instance.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  req_id          : [IN]      The async request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_abort(EMAIL_ACCT_HANDLE acct_handle, EMAIL_REQ_ID req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object = NULL;
    srv_email_acct_nwk_info_struct *acct_nwk_info = NULL;
    //srv_email_acct_del_remote_fldr_info_struct *remote_fldr_info = NULL;
    S32 action = SRV_EMAIL_NWK_NONE;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    for (i = 0; i < SRV_EMAIL_ACCOUNT_REQ_MAX_NUMBER; i++)
    {
        if (account_object->req_id_action_map_list[i].req_id == req_id)
        {
            action = account_object->req_id_action_map_list[i].action;
            if (action != SRV_EMAIL_NWK_NONE)
            {
                acct_nwk_info = (srv_email_acct_nwk_info_struct*)account_object->req_id_action_map_list[i].operation_info;
            }
            else
            {
                //remote_fldr_info = (srv_email_acct_del_remote_fldr_info_struct*)account_object->req_id_action_map_list[i].operation_info;
            }
            account_object->req_id_action_map_list[i].operation_info = NULL;
            break;
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_ABORT,
        account_object->acct_id,
        req_id,
        action);
    if (i == SRV_EMAIL_ACCOUNT_REQ_MAX_NUMBER)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_PARAMETER, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    srv_email_acct_clear_req_id(account_object, req_id);
    switch (action)
    {
    case SRV_EMAIL_NWK_TEST_NWK:
    case SRV_EMAIL_NWK_CONNECT:
        if (acct_nwk_info->incoming_server)
        {
        #ifdef __SMS_CLOUD_SUPPORT__
            if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
            {
                srv_email_nwk_cloud_abort(account_object->nwk_incoming_handle);
                srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            }
            else
        #endif /* __SMS_CLOUD_SUPPORT__ */
            {
                srv_email_nwk_abort(account_object->nwk_incoming_handle);
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            }
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        else
        {
            srv_email_nwk_abort(account_object->nwk_outgoing_handle);
            srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
            account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        break;
    case SRV_EMAIL_NWK_DISCONNECT:
        if (acct_nwk_info->incoming_server)
        {
        #ifdef __SMS_CLOUD_SUPPORT__
            if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
            {
                srv_email_nwk_cloud_abort(account_object->nwk_incoming_handle);
            }
            else
        #endif /* __SMS_CLOUD_SUPPORT__ */
            {
                srv_email_nwk_abort(account_object->nwk_incoming_handle);
            }
        }
        else
        {
            srv_email_nwk_abort(account_object->nwk_outgoing_handle);
        }
        break;
    case SRV_EMAIL_NWK_SEND:
        srv_email_nwk_abort(account_object->nwk_outgoing_handle);
        if (!account_object->outgoing_connected)
        {
            srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
            account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        break;
    case SRV_EMAIL_NWK_RECEIVE:
    case SRV_EMAIL_NWK_SYNC:
    case SRV_EMAIL_NWK_LIST_FOLDER:
    case SRV_EMAIL_NWK_REFRESH:
        srv_email_nwk_abort(account_object->nwk_incoming_handle);
        if (!account_object->incoming_connected)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        break;

#ifdef __SMS_CLOUD_SUPPORT__
    case SRV_EMAIL_NWK_CLD_APPEND:
    case SRV_EMAIL_NWK_CLD_GET_UID:
    case SRV_EMAIL_NWK_CLD_GET_MSG:
        srv_email_nwk_cloud_abort(account_object->nwk_incoming_handle);
        if (!account_object->incoming_connected)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        break;
#endif /* __SMS_CLOUD_SUPPORT__ */

    default:
        break;
    }

    if (acct_nwk_info != NULL)
    {
        srv_email_mem_free(acct_nwk_info);
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_handle_to_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static srv_email_acct_object_info_struct *srv_email_acct_handle_to_addr(
    EMAIL_ACCT_HANDLE acct_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = (srv_email_acct_object_info_struct*)acct_handle;
    for (i = 0; i < SRV_EMAIL_ACCOUNT_HANDLE_MAX_NUMBER; i++)
    {
        if (account_object == &srv_email_acct_cntx_p->account_array[i] &&
            account_object->in_use)
        {
            return account_object;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_nwk_proc_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_acct_nwk_proc_notify(srv_email_nwk_proc_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = (srv_email_acct_object_info_struct*)data->user_data;
    if (account_object->proc_callback)
    {
        data->user_data = account_object->proc_user_data;
        (*account_object->proc_callback)(data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_nwk_finish_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_acct_nwk_finish_notify(srv_email_nwk_finish_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    EMAIL_REQ_ID req_id;
    MMI_BOOL incoming_server;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    acct_nwk_info = (srv_email_acct_nwk_info_struct*)data->user_data;
    account_object = acct_nwk_info->account_object;
    incoming_server = acct_nwk_info->incoming_server;
    req_id = acct_nwk_info->req_id;
    srv_email_mem_free(acct_nwk_info);
    srv_email_acct_clear_req_id(account_object, req_id);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_NWK_CALLBACK,
        account_object->acct_id,
        req_id,
        data->action,
        data->result.result);
    switch (data->action)
    {
    case SRV_EMAIL_NWK_TEST_NWK:
        if (incoming_server)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        else
        {
            srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
            account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        break;
    case SRV_EMAIL_NWK_CONNECT:
        if (data->result.result)
        {
            if (incoming_server)
            {
                account_object->incoming_connected = MMI_TRUE;
            }
            else
            {
                account_object->outgoing_connected = MMI_TRUE;
            }
        }
        else
        {
        #ifdef __SMS_CLOUD_SUPPORT__
            if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
            {
                srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            else
        #endif /* __SMS_CLOUD_SUPPORT__ */
            {
                if (incoming_server)
                {
                    srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                    account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
                }
                else
                {
                    srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                    account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
                }
            }
        }
        break;
    case SRV_EMAIL_NWK_DISCONNECT:
        /* disconnect will always return success */
    #ifdef __SMS_CLOUD_SUPPORT__
        if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        else
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            if (incoming_server)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
                account_object->incoming_connected = MMI_FALSE;
            }
            else
            {
                srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
                account_object->outgoing_connected = MMI_FALSE;
            }
        }
        break;
    case SRV_EMAIL_NWK_SEND:
        if (account_object->outgoing_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
            account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        break;
    case SRV_EMAIL_NWK_RECEIVE:
    case SRV_EMAIL_NWK_SYNC:
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        break;
    case SRV_EMAIL_NWK_LIST_FOLDER:
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        if (data->result.result)
        {
            srv_email_acct_read_remote_fldr_info(account_object);
        }
        break;

    case SRV_EMAIL_NWK_REFRESH:
        break;

#ifdef __SMS_CLOUD_SUPPORT__
    case SRV_EMAIL_NWK_CLD_APPEND:
    case SRV_EMAIL_NWK_CLD_GET_UID:
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        break;

    case SRV_EMAIL_NWK_CLD_GET_MSG:
        if (account_object->incoming_connected == MMI_FALSE)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }
        if (data->result.result)
        {
            srv_email_acct_cld_get_msg(account_object);
        }
        break;
#endif /* __SMS_CLOUD_SUPPORT__ */

    default:
        break;
    }
    if (*account_object->callback != NULL)
    {
        (*account_object->callback)(
            &data->result,
            req_id,
            account_object->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_pre_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static srv_email_result_enum srv_email_acct_pre_connect(
                                srv_email_acct_object_info_struct *account_object,
                                MMI_BOOL incoming,
                                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_CLOUD_SUPPORT__
    if (account_object->conn_type == SRV_EMAIL_ACCT_CONN_SMS)
    {
        if (account_object->nwk_incoming_handle != EMAIL_NWK_INVALID_HANDLE)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
        }

        result = srv_email_nwk_cloud_create(
                    account_object->acct_id,
                    &account_object->nwk_incoming_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            return result;
        }

        result = srv_email_nwk_cloud_set_process_notify(
                    account_object->nwk_incoming_handle,
                    srv_email_acct_nwk_proc_notify,
                    account_object);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            return result;
        }

        result = srv_email_nwk_cloud_set_finish_notify(
                    account_object->nwk_incoming_handle,
                    srv_email_acct_nwk_finish_notify,
                    user_data);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            return result;
        }

        result = srv_email_nwk_cloud_set_option(
                    account_object->nwk_incoming_handle,
					account_object->conn.provider_id,
                    account_object->conn.cloud_acct_id);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_nwk_cloud_destroy(account_object->nwk_incoming_handle);
            account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            return result;
        }

        return SRV_EMAIL_RESULT_SUCC;
    }
    else
#endif /* __SMS_CLOUD_SUPPORT__ */
    {
        if (incoming)
        {
            if (account_object->nwk_incoming_handle != EMAIL_NWK_INVALID_HANDLE)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            result = srv_email_nwk_create(
                        account_object->acct_id,
                        incoming,
                        &account_object->nwk_incoming_handle);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                return result;
            }
            result = srv_email_nwk_set_process_notify(
                        account_object->nwk_incoming_handle,
                        srv_email_acct_nwk_proc_notify,
                        account_object);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
                return result;
            }
            result = srv_email_nwk_set_finish_notify(
                        account_object->nwk_incoming_handle,
                        srv_email_acct_nwk_finish_notify,
                        user_data);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_nwk_destroy(account_object->nwk_incoming_handle);
                account_object->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
                return result;
            }
            return SRV_EMAIL_RESULT_SUCC;
        }
        else
        {
            if (account_object->nwk_outgoing_handle != EMAIL_NWK_INVALID_HANDLE)
            {
                srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
            }
            result = srv_email_nwk_create(
                        account_object->acct_id,
                        incoming,
                        &account_object->nwk_outgoing_handle);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                return result;
            }
            result = srv_email_nwk_set_process_notify(
                        account_object->nwk_outgoing_handle,
                        srv_email_acct_nwk_proc_notify,
                        account_object);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
                return result;
            }
            result = srv_email_nwk_set_finish_notify(
                        account_object->nwk_outgoing_handle,
                        srv_email_acct_nwk_finish_notify,
                        user_data);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_nwk_destroy(account_object->nwk_outgoing_handle);
                account_object->nwk_outgoing_handle = EMAIL_NWK_INVALID_HANDLE;
                return result;
            }
            return SRV_EMAIL_RESULT_SUCC;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static MMI_BOOL srv_email_acct_get_req_id(
                    srv_email_acct_object_info_struct *account_object,
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
    for (i = 0; i < SRV_EMAIL_ACCOUNT_REQ_MAX_NUMBER; i++)
    {
        if (account_object->req_id_action_map_list[i].req_id == 0)
        {
            account_object->req_id_action_map_list[i].req_id = acct_req_id++;
            account_object->req_id_action_map_list[i].action = action;
            account_object->req_id_action_map_list[i].operation_info = operation_info;
            if (req_id_1 != NULL)
            {
                *req_id_1 = account_object->req_id_action_map_list[i].req_id;
            }
            if (req_id_2 != NULL)
            {
                *req_id_2 = account_object->req_id_action_map_list[i].req_id;
            }
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_clear_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void srv_email_acct_clear_req_id(srv_email_acct_object_info_struct *account_object, EMAIL_REQ_ID req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_ACCOUNT_REQ_MAX_NUMBER; i++)
    {
        if (account_object->req_id_action_map_list[i].req_id == req_id)
        {
            account_object->req_id_action_map_list[i].req_id = 0;
            account_object->req_id_action_map_list[i].operation_info = NULL;
            account_object->req_id_action_map_list[i].action = SRV_EMAIL_NWK_NONE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_able_to_get_permission
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_email_acct_able_to_get_permission(
                    EMAIL_ACCT_ID acct_id,
                    srv_email_om_permission_type_enum permision_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL flag = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (permision_type == SRV_EMAIL_OM_PERMISSION_WRITE)
    {
        for (i = 0; i < SRV_EMAIL_ACCOUNT_HANDLE_MAX_NUMBER; i++)
        {
            if (srv_email_acct_cntx_p->account_array[i].in_use &&
                srv_email_acct_cntx_p->account_array[i].acct_id == acct_id)
            {
                if (flag)
                {
                    flag = MMI_FALSE;
                }
                else
                {
                    // if more than 1 acct obj match the expression, return false
                    return MMI_FALSE;
                }
            }
        }
    }
    else // permision_type == SRV_EMAIL_OM_PERMISSION_READ
    {
        for (i = 0; i < SRV_EMAIL_ACCOUNT_HANDLE_MAX_NUMBER; i++)
        {
            if (srv_email_acct_cntx_p->account_array[i].in_use &&
                srv_email_acct_cntx_p->account_array[i].acct_id == acct_id &&
                srv_email_acct_cntx_p->account_array[i].state != SRV_EMAIL_ACCT_STATE_READ)
            {
                return MMI_FALSE;
            }
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_read_remote_fldr_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_email_acct_read_remote_fldr_info(srv_email_acct_object_info_struct *account_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR dst_file_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    srv_email_nwk_fldr_info_header_struct info_header;
    srv_email_nwk_fldr_info_struct *remote_fldr_info = NULL;
    FS_HANDLE file_handle;
    S32 result;
    U32 read;
    U32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        dst_file_path,
        "%s%s%s%d",
        srv_email_get_root_path(),
        remote_path,
        remote,
        account_object->acct_id);
    file_handle = FS_Open(dst_file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        return MMI_FALSE;
    }
    result = FS_Read(file_handle, &info_header, sizeof(srv_email_nwk_fldr_info_header_struct), &read);
    if (result != FS_NO_ERROR || read != sizeof(srv_email_nwk_fldr_info_header_struct))
    {
        account_object->remote_fldr_num = 0;
        FS_Close(file_handle);
        return MMI_FALSE;
    }
    account_object->remote_fldr_num = info_header.fldr_num;
    account_object->remote_fldr_seperator = info_header.delimiter;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_READ_REMOTE_FLDR_INFO,
        account_object->acct_id,
        account_object->remote_fldr_num,
        account_object->remote_fldr_seperator);
    remote_fldr_info = (srv_email_nwk_fldr_info_struct*)get_ctrl_buffer(sizeof(srv_email_nwk_fldr_info_struct));
    for (index = 0; index < account_object->remote_fldr_num; index++)
    {
        result = FS_Read(file_handle, remote_fldr_info, sizeof(srv_email_nwk_fldr_info_struct), &read);
        if (result != FS_NO_ERROR || read != sizeof(srv_email_nwk_fldr_info_struct))
        {
            free_ctrl_buffer(remote_fldr_info);
            FS_Close(file_handle);
            return MMI_FALSE;
        }
        account_object->remote_fldr_sub[index] = remote_fldr_info->subscribed;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_ACCT_READ_REMOTE_FLDR_INFO_DETAIL,
            index,
            account_object->remote_fldr_sub[index],
            remote_fldr_info->fldr_id);
    }
    free_ctrl_buffer(remote_fldr_info);
    FS_Close(file_handle);
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_cache_notify_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_email_acct_cache_notify_set(
    srv_email_all_msg_unread_notify_funcptr callback, void* userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_stor_acct_cache_notify_set(callback, userdata);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_cache_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_email_acct_cache_get(EMAIL_ACCT_ID acct_id, srv_email_acct_info_cache_struct *acct_info_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_stor_acct_cache_get(acct_id, acct_info_cache);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern srv_email_result_enum srv_email_acct_refresh(
                                 EMAIL_ACCT_HANDLE acct_handle,
                                 srv_email_receive_option_enum recv_opt,
                                 EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_nwk_refresh_struct refresh_info;
    srv_email_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (account_object == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_REFRESH,
        acct_handle,
        recv_opt,
        account_object->incoming_connected);
    acct_nwk_info = (srv_email_acct_nwk_info_struct*)srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (acct_nwk_info == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    acct_nwk_info->account_object = account_object;
    acct_nwk_info->incoming_server = MMI_TRUE;
    if (!account_object->incoming_connected)
    {
        srv_email_mem_free(acct_nwk_info);
        return SRV_EMAIL_RESULT_FAIL;
    }
    result = srv_email_nwk_set_finish_notify(
                account_object->nwk_incoming_handle,
                srv_email_acct_nwk_finish_notify,
                acct_nwk_info);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_mem_free(acct_nwk_info);
        return result;
    }
    refresh_info.recv_opt = recv_opt;
    result = srv_email_nwk_refresh(account_object->nwk_incoming_handle, &refresh_info);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_REFRESH, result);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            srv_email_mem_free(acct_nwk_info);
            return result;
        }
        if (srv_email_acct_get_req_id(
                account_object,
                SRV_EMAIL_NWK_REFRESH,
                acct_nwk_info,
                req_id,
                &acct_nwk_info->req_id))
        {
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            srv_email_mem_free(acct_nwk_info);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    else
    {
        srv_email_mem_free(acct_nwk_info);
        return SRV_EMAIL_RESULT_SUCC;
    }
}

#if defined(__MMI_SSO__) || defined(__SMS_CLOUD_SUPPORT__)

srv_email_result_enum srv_email_acct_set_cloud_acct(
                        EMAIL_ACCT_ID acct_id,
                        MMI_BOOL is_cloud_acct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_email_stor_acct_set_cloud_acct(acct_id, is_cloud_acct);
}

#ifdef __SMS_CLOUD_SUPPORT__

static S32 srv_email_acct_cld_skip_string(FS_HANDLE hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 len;
    U32 rw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Read(hd, &len, sizeof(U32), &rw);
    if (ret < 0 || rw != sizeof(U32))
    {
        if (ret >= 0)
        {
            ret = FS_GENERAL_FAILURE;
        }
        return ret;
    }

    if (len > 0)
    {
        ret = FS_Seek(hd, len, FS_FILE_CURRENT);
    }
    return ret;
}


static S32 srv_email_acct_cld_skip_address(FS_HANDLE hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip display name */
    ret = srv_email_acct_cld_skip_string(hd);
    if (ret < 0)
    {
        return ret;
    }

    /* Skip email address */
    ret = srv_email_acct_cld_skip_string(hd);
    return ret;
}

/*----------------------------------------
kal_uint32 uid;
kal_uint32 size;
kal_uint32 priority; // SEE email_ps_priority_enum
email_ps_data_time_struct date;
email_ps_string_struct subject;
email_ps_email_address_struct from;
email_ps_email_address_struct sender;
email_ps_email_address_struct reply_to;
kal_uint32 to_number;
email_ps_email_address_struct to1,
email_ps_email_address_struct to2,
...
email_ps_email_address_struct toN,
kal_uint32 cc_number;
email_ps_email_address_struct cc1,
email_ps_email_address_struct cc2,
...
email_ps_email_address_struct ccN,
kal_uint32 bcc_number;
email_ps_email_address_struct bcc1,
email_ps_email_address_struct bcc2,
...
email_ps_email_address_struct bccN,
email_ps_string_struct in_reply_to;
email_ps_string_struct msg_id;
SMS_UID
SMS_ADDR
SMS_DATA
srv_email_stor_cont_header_struct cont_header;

----------------------------------------*/
static srv_email_result_enum srv_email_acct_cld_get_msg(
                                srv_email_acct_object_info_struct *acct_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result = SRV_EMAIL_RESULT_FS_ERROR;
    S32 ret;
    WCHAR *env_file = NULL;
    WCHAR *cont_file = NULL;
    WCHAR *cont_file_cnvt = NULL;
    CHAR  *cont_buff = NULL;
    CHAR  *cont_buff_cnvt = NULL;
    CHAR  *email_addr = NULL;
    CHAR  *addr_p = NULL;
    FS_HANDLE fhd = -1;
    U32 file_size;
    U32 rw;
    U32 i;
    U32 j;
    U32 num;
    U32 len;
    U32 to_num;
    U32 to_len = 0;
    email_ps_data_time_struct data_time;
    applib_time_struct utc;
    applib_time_struct mytime;
    float time_zone_float = 0.0;
    U32 created_date;
    srv_email_msg_update_content_struct cont;
    srv_email_stor_cont_header_struct cont_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    env_file = (WCHAR*)OslMalloc((SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1) * sizeof(WCHAR));
    srv_email_msg_get_file_path(
        env_file,
        SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1, 
        srv_email_msg_handle_to_addr(acct_obj->cld_msg_hd),
        SRV_EMAIL_MSG_SAVE_ENVELOP_TMP);

    fhd = FS_Open(env_file, FS_READ_ONLY);

    OslMfree(env_file);

    if (fhd < 0)
    {
        ret = fhd;
        goto ERROR_HANDLE;
    }

    /* Skip the UID + Size + Priority */
    ret = FS_Seek(fhd, sizeof(U32) * 3, FS_FILE_BEGIN);
    if (ret < 0)
    {
        goto ERROR_HANDLE;
    }

    ret = FS_Read(fhd, &data_time, sizeof(email_ps_data_time_struct), &rw);
    if (ret < 0 || rw != sizeof(email_ps_data_time_struct))
    {
        goto ERROR_HANDLE;
    }

    /* Change the time to UTC seconds */
    utc.nYear = (U16)data_time.year;
    utc.nMonth = (U8)data_time.month;
    utc.nDay = (U8)data_time.day;
    utc.nHour = (U8)data_time.hour;
    utc.nMin = (U8)data_time.minute;
    utc.nSec = (U8)data_time.second;
    if (!srv_email_is_date_time_valid(&utc))
    {
        srv_email_set_default_date_time(&utc);
        data_time.time_zone_min = 0;
    }
    time_zone_float = (float)data_time.time_zone_min / 60;
    applib_dt_utc_to_rtc((float)(0 - time_zone_float), &utc, &mytime);
    srv_email_revise_date_time(&mytime);
    created_date = applib_dt_mytime_2_utc_sec(&mytime, MMI_FALSE);
    result = srv_email_msg_update_date(acct_obj->cld_msg_hd, created_date);

    /* Skip the Subject */
    ret = srv_email_acct_cld_skip_string(fhd);
    if (ret < 0)
    {
        goto ERROR_HANDLE;
    }

    /* Skip the From + Sender + Reply-to */
    for (i = 0; i < 3; i++)
    {
        ret = srv_email_acct_cld_skip_address(fhd);
        if (ret < 0)
        {
            goto ERROR_HANDLE;
        }
    }

    /* To number */
    ret = FS_Read(fhd, &to_num, sizeof(U32), &rw);
    if (ret < 0 || rw != sizeof(U32))
    {
        goto ERROR_HANDLE;
    }

    /* To */
    if (to_num > 0)
    {
	    num = to_num > MMI_EMAIL_MAX_ADDR_NUM ? MMI_EMAIL_MAX_ADDR_NUM : to_num;
        cont_buff = (CHAR*)srv_email_mem_alloc((SRV_EMAIL_MAX_ADDR_LEN + 1) * num);
        if (!cont_buff)
        {
            result = SRV_EMAIL_RESULT_NO_MEMORY;
            goto ERROR_HANDLE;
        }

    	for (i = 0; i < to_num; i++)
        {
            if (i < MMI_EMAIL_MAX_ADDR_NUM)
            {
        		/* Skip the display name */
                ret = srv_email_acct_cld_skip_string(fhd);
        	    if (ret < 0)
        	    {
        	        goto ERROR_HANDLE;
        	    }

        		/* Handle the email address */
                ret = FS_Read(fhd, &len, sizeof(U32), &rw);
        	    if (ret < 0 || rw != sizeof(U32))
        	    {
        	        goto ERROR_HANDLE;
        	    }

                if (len > 0)
                {
                    email_addr = (CHAR*)srv_email_mem_alloc(len + 1);
                    if (!email_addr)
                    {
                        result = SRV_EMAIL_RESULT_NO_MEMORY;
                        goto ERROR_HANDLE;
                    }

                    ret = FS_Read(fhd, email_addr, len, &rw);
                    if (ret < 0 || rw != len)
                    {
                        goto ERROR_HANDLE;
                    }

                    if (len > SRV_EMAIL_MAX_ADDR_LEN)
                    {
                        email_addr[SRV_EMAIL_MAX_ADDR_LEN] = 0;
                    }
                    else
                    {
                        email_addr[len] = 0;
                    }

                    addr_p = strchr(email_addr, '@');
                    if (addr_p)
                    {
                        *addr_p = 0;
                    }

                    if (to_len > 0)
                    {
                        to_len += kal_sprintf(cont_buff + to_len, "%c%s", NUMBER_SEPERATOR_CHAR, email_addr);
                    }
                    else
                    {
                        to_len += kal_sprintf(cont_buff + to_len, "%s", email_addr);
                    }

                    srv_email_mem_free(email_addr);
                    email_addr = NULL;
                }
            }
            else
            {
                ret = srv_email_acct_cld_skip_address(fhd);
                if (ret < 0)
                {
                    goto ERROR_HANDLE;
                }
            }
        }

        if (to_len > 0)
        {
            result = srv_email_msg_update_extra_field(
                        acct_obj->cld_msg_hd,
                        SRV_EMAIL_MSG_SAVE_EXTRA_SMS_ADDR,
                        cont_buff,
                        to_len);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                goto ERROR_HANDLE;
            }
        }

        srv_email_mem_free(cont_buff);
        cont_buff = NULL;
    }

    /* Skip the Cc + Bcc */
    for (i = 0; i < 2; i++)
    {
        ret = FS_Read(fhd, &num, sizeof(U32), &rw);
        if (ret < 0 || rw != sizeof(U32))
        {
            goto ERROR_HANDLE;
        }

        for (j = 0; j < num; ++i)
        {
            ret = srv_email_acct_cld_skip_address(fhd);
            if (ret < 0)
            {
                goto ERROR_HANDLE;
            }
        }
    }

    /* Skip the In-reply-to + Message-id */
    for (i = 0; i < 2; i++)
    {
        ret = srv_email_acct_cld_skip_string(fhd);
        if (ret < 0)
        {
            goto ERROR_HANDLE;
        }
    }

    /* SMS UID */
    ret = FS_Read(fhd, &len, sizeof(U32), &rw);
    if (ret < 0 || rw != sizeof(U32))
    {
        goto ERROR_HANDLE;
    }
    EMAILSRV_ASSERT(len > 0);

    cont_buff = (CHAR*)srv_email_mem_alloc(len + 1);
    if (!cont_buff)
    {
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto ERROR_HANDLE;
    }

    ret = FS_Read(fhd, cont_buff, len, &rw);
    if (ret < 0 || rw != len)
    {
        goto ERROR_HANDLE;
    }
    cont_buff[len] = 0;

    result = srv_email_msg_update_extra_field(
                acct_obj->cld_msg_hd,
                SRV_EMAIL_MSG_SAVE_EXTRA_SMS_UID,
                cont_buff,
                len);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto ERROR_HANDLE;
    }

    srv_email_mem_free(cont_buff);
	cont_buff = NULL;

    /* SMS DATA */
    ret = FS_Read(fhd, &len, sizeof(U32), &rw);
    if (ret < 0 || rw != sizeof(U32))
    {
        goto ERROR_HANDLE;
    }

    if (len > 0)
    {
        cont_buff = (CHAR*)srv_email_mem_alloc(len + 1);
        if (!cont_buff)
        {
            result = SRV_EMAIL_RESULT_NO_MEMORY;
            goto ERROR_HANDLE;
        }

        ret = FS_Read(fhd, cont_buff, len, &rw);
        if (ret < 0 || rw != len)
        {
            goto ERROR_HANDLE;
        }
        cont_buff[len] = 0;

        cont_buff_cnvt = (CHAR*)srv_email_mem_alloc(len + 1);
        if (!cont_buff_cnvt)
        {
            result = SRV_EMAIL_RESULT_NO_MEMORY;
            goto ERROR_HANDLE;
        }

        len = applib_base64_decode_basic(cont_buff, len, cont_buff_cnvt, len + 1);
        cont_buff_cnvt[len] = 0;

        result = srv_email_msg_update_extra_field(
                    acct_obj->cld_msg_hd,
                    SRV_EMAIL_MSG_SAVE_EXTRA_SMS_DATA,
                    cont_buff_cnvt,
                    len);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            goto ERROR_HANDLE;
        }

        srv_email_mem_free(cont_buff);
        srv_email_mem_free(cont_buff_cnvt);
		cont_buff = NULL;
		cont_buff_cnvt = NULL;
    }

    /* Content header */
    ret = FS_Read(fhd, &cont_header, sizeof(cont_header), &rw);
    if (ret < 0 || rw != sizeof(cont_header))
    {
        goto ERROR_HANDLE;
    }

    FS_Close(fhd);
    fhd = -1;

    /* Content */
    if (cont_header.this_part_exist && cont_header.download_flag && cont_header.local_size > 0)
    {
        cont_file = OslMalloc((SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1) * sizeof(WCHAR));
        cont_file_cnvt = OslMalloc((SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1) * sizeof(WCHAR));

        srv_email_msg_get_file_path(
            cont_file,
            SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1, 
            srv_email_msg_handle_to_addr(acct_obj->cld_msg_hd),
            SRV_EMAIL_MSG_SAVE_CONTENT_TMP);
        srv_email_msg_get_file_path(
            cont_file_cnvt,
            SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1, 
            srv_email_msg_handle_to_addr(acct_obj->cld_msg_hd),
            SRV_EMAIL_MSG_SAVE_CONTENT_TMP);
        mmi_wcscat(cont_file_cnvt, L"_");

        result = srv_email_file_chset_convert(
                    cont_file,
                    cont_header.charset,
                    cont_file_cnvt,
                    (CHAR*)chset_get_preferred_mime_name(CHSET_UCS2),
                    &ret);

        fhd = FS_Open(cont_file_cnvt, FS_READ_ONLY | FS_OPEN_SHARED);

        OslMfree(cont_file);
        OslMfree(cont_file_cnvt);

        if (fhd < FS_NO_ERROR)
        {
            ret = fhd;
            fhd = -1;
            goto ERROR_HANDLE;
        }

        ret = FS_GetFileSize(fhd, &file_size);
        if (ret < 0)
        {
            goto ERROR_HANDLE;
        }

        if (file_size > 0)
        {
            cont_buff = (CHAR*)srv_email_mem_alloc(file_size);
            if (!cont_buff)
            {
                result = SRV_EMAIL_RESULT_NO_MEMORY;
                goto ERROR_HANDLE;
            }

            ret = FS_Read(fhd, cont_buff, file_size, &rw);
            if (ret < 0 || rw != file_size)
            {
                goto ERROR_HANDLE;
            }

            cont.buff_type  = MMI_TRUE;
            cont.buff       = cont_buff;
            cont.buff_len   = file_size / sizeof(WCHAR);
            cont.charset    = CHSET_UCS2;

            result = srv_email_msg_update_content(acct_obj->cld_msg_hd, &cont);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                goto ERROR_HANDLE;
            }

            srv_email_mem_free(cont_buff);
            cont_buff = NULL;
        }

        FS_Close(fhd);
        fhd = -1;
    }

    return SRV_EMAIL_RESULT_SUCC;

ERROR_HANDLE:
    if (fhd >= 0)
    {
        FS_Close(fhd);
    }
	if (cont_buff)
	{
		srv_email_mem_free(cont_buff);
	}
	if (cont_buff_cnvt)
	{
		srv_email_mem_free(cont_buff_cnvt);
	}
	if (email_addr)
	{
		srv_email_mem_free(email_addr);
	}
	if (result == SRV_EMAIL_RESULT_FS_ERROR)
	{
    	srv_email_errno_set(ret);
	}
    return result;
}


srv_email_result_enum srv_email_acct_set_type(
                        EMAIL_ACCT_HANDLE acct_handle,
                        srv_email_acct_conn_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (!account_object)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    account_object->conn_type = type;
    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_acct_conn_set_cld_srv_opt(
                        EMAIL_ACCT_HANDLE acct_handle,
                        srv_email_conn_opt_for_cld_srv_struct *connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *account_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!connect || !connect->conn_mailbox)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    account_object = srv_email_acct_handle_to_addr(acct_handle);
    if (!account_object)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (account_object->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    if (account_object->conn_type != SRV_EMAIL_ACCT_CONN_SMS)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    if (account_object->conn.conn_mailbox)
    {
        srv_email_mem_free(account_object->conn.conn_mailbox);
    }

    account_object->conn.conn_mailbox = srv_email_mem_alloc(strlen(connect->conn_mailbox) + 1);
    if (!account_object->conn.conn_mailbox)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

	account_object->conn.provider_id = connect->provider_id;
	account_object->conn.cloud_acct_id = connect->cloud_acct_id;
	strcpy(account_object->conn.conn_mailbox, connect->conn_mailbox);
    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_acct_append_msg(
                        EMAIL_ACCT_HANDLE acct_handle,
                        EMAIL_MSG_HANDLE msg_handle,
                        EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *acct_obj;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!req_id)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    acct_obj = srv_email_acct_handle_to_addr(acct_handle);
    if (!acct_obj)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (acct_obj->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_APPEND, acct_handle, acct_obj->incoming_connected);

    acct_nwk_info = srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (!acct_nwk_info)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    acct_nwk_info->account_object = acct_obj;
    acct_nwk_info->incoming_server = MMI_TRUE;

    MMI_ASSERT(acct_obj->conn_type == SRV_EMAIL_ACCT_CONN_SMS);

    if (!acct_obj->incoming_connected)
    {
        result = srv_email_acct_pre_connect(acct_obj, MMI_TRUE, acct_nwk_info);
    }
    else
    {
        result = srv_email_nwk_cloud_set_finish_notify(
                    acct_obj->nwk_incoming_handle,
                    srv_email_acct_nwk_finish_notify,
                    acct_nwk_info);
    }

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    result = srv_email_nwk_cloud_append(acct_obj->nwk_incoming_handle, msg_handle);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_CLD_APPEND, result);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            goto EXIT_HANDLE;
        }

        if (srv_email_acct_get_req_id(
                acct_obj,
                SRV_EMAIL_NWK_CLD_APPEND,
                acct_nwk_info,
                req_id,
                &acct_nwk_info->req_id))
        {
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            result = SRV_EMAIL_RESULT_FAIL;
            goto EXIT_HANDLE;
        }
    }

EXIT_HANDLE:
    if (!acct_obj->incoming_connected)
    {
        srv_email_nwk_cloud_destroy(acct_obj->nwk_incoming_handle);
        acct_obj->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
    }
    srv_email_mem_free(acct_nwk_info);
    return result;
}


srv_email_result_enum srv_email_acct_receive_uid_list_for_cloud(
                        EMAIL_ACCT_HANDLE acct_handle,
                        const WCHAR *filename,
                        U32 uid_max_num,
                        EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *acct_obj;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_result_enum result;
    srv_email_nwk_cloud_retr_struct nwk_retr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!req_id || !filename || uid_max_num == 0)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    acct_obj = srv_email_acct_handle_to_addr(acct_handle);
    if (!acct_obj)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (acct_obj->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_RETRIEVE_UID_LIST_CLOUD,
        acct_handle,
        acct_obj->incoming_connected,
        uid_max_num);

    acct_nwk_info = srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (!acct_nwk_info)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    acct_nwk_info->account_object = acct_obj;
    acct_nwk_info->incoming_server = MMI_TRUE;

    if (!acct_obj->incoming_connected)
    {
        result = srv_email_acct_pre_connect(acct_obj, MMI_TRUE, acct_nwk_info);
    }
    else
    {
        result = srv_email_nwk_cloud_set_finish_notify(
                    acct_obj->nwk_incoming_handle,
                    srv_email_acct_nwk_finish_notify,
                    acct_nwk_info);
    }

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    nwk_retr.msg_part = SRV_EMAIL_NWK_CLOUD_MSG_ALL_UID;
    nwk_retr.uid_max_num = uid_max_num;
    mmi_wcscpy(nwk_retr.filename, filename);

    result = srv_email_nwk_cloud_retrieve(acct_obj->nwk_incoming_handle, &nwk_retr);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_CLD_APPEND, result);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            goto EXIT_HANDLE;
        }

        if (srv_email_acct_get_req_id(
                acct_obj,
                SRV_EMAIL_NWK_CLD_APPEND,
                acct_nwk_info,
                req_id,
                &acct_nwk_info->req_id))
        {
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            result = SRV_EMAIL_RESULT_FAIL;
            goto EXIT_HANDLE;
        }
    }

EXIT_HANDLE:
    if (!acct_obj->incoming_connected)
    {
        srv_email_nwk_cloud_destroy(acct_obj->nwk_incoming_handle);
        acct_obj->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
    }
    srv_email_mem_free(acct_nwk_info);
    return result;
}


srv_email_result_enum srv_email_acct_receive_msg_for_cloud(
                        EMAIL_ACCT_HANDLE acct_handle,
                        U32 imap_uid,
                        EMAIL_MSG_HANDLE msg_handle,
                        EMAIL_REQ_ID *req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *acct_obj;
    srv_email_acct_nwk_info_struct *acct_nwk_info;
    srv_email_result_enum result;
    srv_email_nwk_cloud_retr_struct nwk_retr;
    WCHAR* path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!req_id)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    acct_obj = srv_email_acct_handle_to_addr(acct_handle);
    if (!acct_obj)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (acct_obj->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    acct_obj->cld_msg_hd = msg_handle;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_ACCT_RETRIEVE_MSG_CLOUD,
        acct_handle,
        acct_obj->incoming_connected,
        imap_uid);

    acct_nwk_info = srv_email_mem_alloc(sizeof(srv_email_acct_nwk_info_struct));
    if (!acct_nwk_info)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    acct_nwk_info->account_object = acct_obj;
    acct_nwk_info->incoming_server = MMI_TRUE;

    if (!acct_obj->incoming_connected)
    {
        result = srv_email_acct_pre_connect(acct_obj, MMI_TRUE, acct_nwk_info);
    }
    else
    {
        result = srv_email_nwk_cloud_set_finish_notify(
                    acct_obj->nwk_incoming_handle,
                    srv_email_acct_nwk_finish_notify,
                    acct_nwk_info);
    }

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    nwk_retr.msg_part = SRV_EMAIL_NWK_CLOUD_MSG_SMS;
    nwk_retr.msg_uid = imap_uid;

    path = srv_email_mem_alloc((SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1) * sizeof(WCHAR));
    if (!path)
    {
        goto EXIT_HANDLE;
    }

    srv_email_msg_get_file_path(
        path,
        SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1,
        srv_email_msg_handle_to_addr(msg_handle),
        SRV_EMAIL_MSG_SAVE_ENVELOP_TMP);
    mmi_wcscpy(nwk_retr.filename, path);

    srv_email_msg_get_file_path(
        path,
        SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1,
        srv_email_msg_handle_to_addr(msg_handle),
        SRV_EMAIL_MSG_SAVE_CONTENT_TMP);
    mmi_wcscpy(nwk_retr.part_filename, path);

    srv_email_mem_free(path);

    result = srv_email_nwk_cloud_retrieve(acct_obj->nwk_incoming_handle, &nwk_retr);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_NWK_RESULT, SRV_EMAIL_NWK_CLD_APPEND, result);

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            goto EXIT_HANDLE;
        }

        if (srv_email_acct_get_req_id(
                acct_obj,
                SRV_EMAIL_NWK_CLD_APPEND,
                acct_nwk_info,
                req_id,
                &acct_nwk_info->req_id))
        {
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            result = SRV_EMAIL_RESULT_FAIL;
            goto EXIT_HANDLE;
        }
    }

EXIT_HANDLE:
    if (!acct_obj->incoming_connected)
    {
        srv_email_nwk_cloud_destroy(acct_obj->nwk_incoming_handle);
        acct_obj->nwk_incoming_handle = EMAIL_NWK_INVALID_HANDLE;
    }
    srv_email_mem_free(acct_nwk_info);
    return result;
}


srv_email_result_enum srv_email_acct_cloud_retry(
                        EMAIL_ACCT_HANDLE acct_handle,
                        U32 provider_id,
                        U8 cloud_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_object_info_struct *acct_obj;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    acct_obj = srv_email_acct_handle_to_addr(acct_handle);
    if (!acct_obj)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_HANDLE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (acct_obj->state != SRV_EMAIL_ACCT_STATE_READ)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ACCT_INVALID_STATE, __LINE__);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    result = srv_email_nwk_cloud_set_option(acct_obj->nwk_incoming_handle, provider_id, cloud_acct_id);
    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        result = srv_email_nwk_cloud_retry(acct_obj->nwk_incoming_handle);
    }

    return result;
}


EMAIL_ACCT_ID srv_email_acct_create_for_cloud(CHAR *email_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 addr_len;
    kal_bool is_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_valid = applib_is_valid_email_address(email_addr);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_INVALID_EMAIL_ADDR);
        return EMAIL_ACCT_INVALID_ID;
    }

    addr_len = strlen(srv_email_cloud_acct_email_addr);
    MMI_ASSERT(addr_len == 0);

    if (!email_addr)
    {
        return EMAIL_ACCT_INVALID_ID;
    }

    addr_len = strlen(email_addr);
    if (addr_len == 0 || addr_len > SRV_EMAIL_MAX_ADDR_LEN)
    {
        return EMAIL_ACCT_INVALID_ID;
    }

    strcpy(srv_email_cloud_acct_email_addr, email_addr);

    return SRV_EMAIL_CLOUD_ACCT_ID;
}


srv_email_result_enum srv_email_acct_get_info_for_cloud(EMAIL_ACCT_ID acct_id, CHAR *email_addr, U32 *addr_buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_addr || !addr_buflen)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }
    if (acct_id != SRV_EMAIL_CLOUD_ACCT_ID)
    {
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }

    len = strlen(srv_email_cloud_acct_email_addr);
    if (len >= *addr_buflen)
    {
        *addr_buflen = len + 1;
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    strcpy(email_addr, srv_email_cloud_acct_email_addr);

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_acct_delete_for_cloud(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_id != SRV_EMAIL_CLOUD_ACCT_ID)
    {
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }

    srv_email_cloud_acct_email_addr[0] = 0;

    return SRV_EMAIL_RESULT_SUCC;
}

#endif /* __SMS_CLOUD_SUPPORT__ */

#endif /* defined(__MMI_SSO__) || defined(__SMS_CLOUD_SUPPORT__) */

