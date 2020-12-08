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
 *  EmailSrvNetworkPS.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email network PS related functions.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__)

/* Task Message Communication */
#include "stack_msgs.h"
#include "app_ltlcom.h"

#include "cbm_consts.h"
#include "cbm_api.h"

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvNetworkProt.h"

#include "MMIDataType.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_config.h"
#include "email_ps_public.h"
#include "MMI_trc_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "app_str.h"

#ifdef __MMI_EMAIL__

#include "CbmSrvGprot.h"

#include "EmailSrvSMTP.h"
#include "EmailSrvPOP3.h"
#include "EmailSrvIMAP4.h"

extern srv_email_app_id_reg_struct *srv_email_app_id_reg;

#endif /* __MMI_EMAIL__ */

/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_send_msg
 * DESCRIPTION
 *  This function is used to send the message to Email PS.
 * PARAMETERS
 *  msg_id              [IN]        The message id
 *  local_param_ptr     [IN]        The pointer point to the local parameter
 *  peer_buf_ptr        [IN]        The pointer point to the peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(
        MOD_EMAIL,
        (oslMsgType)msg_id,
        (oslParaType*)local_param_ptr,
        (oslPeerBuffType*)peer_buf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_convert_ps_error
 * DESCRIPTION
 *  This function is used to convert the Email PS error.
 * PARAMETERS
 *  errcode             [IN]        The PS error code
 * RETURNS
 *  The service error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_convert_ps_error(email_ps_error_code errcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (errcode)
    {
        case EMAIL_PS_ERRCODE_NOT_SUPPORT_STLS:
            return SRV_EMAIL_RESULT_SERVER_NOT_SUPPORT_STARTTLS;

        case EMAIL_PS_ERRCODE_NOT_SUPPORT_APOP:
            return SRV_EMAIL_RESULT_SERVER_NOT_SUPPORT_APOP;

        case EMAIL_PS_ERRCODE_NO_DATA_RETURN:
            return SRV_EMAIL_RESULT_SERVER_ERROR;

        case EMAIL_PS_ERRCODE_TOO_LARGER_DATA:
            return SRV_EMAIL_RESULT_CAPABILITY_LIMITATION;

        case EMAIL_PS_ERRCODE_INVALID_DATA_FORMAT:
            return SRV_EMAIL_RESULT_INVALID_FORMAT;

        case EMAIL_PS_ERRCODE_OUTOF_MEMORY:
            return SRV_EMAIL_RESULT_NO_MEMORY;

        case EMAIL_PS_NETWORK_TIMEOUT:
            return SRV_EMAIL_RESULT_NETWORK_TIMEOUT;

        case EMAIL_PS_ERRCODE_SMTP_CMD_FAIL_LOGIN:
        case EMAIL_PS_ERRCODE_SMTP_CMD_FAIL_USERNAME:
        case EMAIL_PS_ERRCODE_SMTP_CMD_FAIL_PASSWORD:
        case EMAIL_PS_ERRCODE_POP3_CMD_FAIL_USERNAME:
        case EMAIL_PS_ERRCODE_POP3_CMD_FAIL_PASSWORD:
        case EMAIL_PS_ERRCODE_POP3_CMD_FAIL_APOP:
        case EMAIL_PS_ERRCODE_IMAP4_CMD_FAIL_LOGIN:
            return SRV_EMAIL_RESULT_AUTH_FAIL;

        case EMAIL_PS_ERRCODE_IMAP4_CMD_FAIL_FLD_SELECT:
            return SRV_EMAIL_RESULT_SELECT_FOLDER_ERROR;

        case EMAIL_PS_ERRCODE_SMTP_CMD_FAIL_RCPT:
            return SRV_EMAIL_RESULT_RECIPIENTS_ERROR;

        case EMAIL_PS_ERRCODE_SMTP_CMD_FAIL_LOGIN_INVALID_COOKIE:
        case EMAIL_PS_ERRCODE_IMAP4_CMD_FAIL_LOGIN_INVALID_COOKIE:
            return SRV_EMAIL_RESULT_INVALID_AUTH_COOKIE;

        default:
            if (errcode >= EMAIL_PS_DNS_QUERY_FAIL &&
                errcode <= EMAIL_PS_SSL_HANDSHAKE_FAIL)
            {
                return SRV_EMAIL_RESULT_NETWORK_ERROR;
            }
            else if (errcode >= EMAIL_PS_ERRCODE_SMTP_CMD_FAIL &&
                     errcode <= EMAIL_PS_ERRCODE_SMTP_CMD_FAIL_MAX)
            {
                return SRV_EMAIL_RESULT_SMTP_CMD_ERROR;
            }
            else if (errcode >= EMAIL_PS_ERRCODE_POP3_CMD_FAIL &&
                     errcode <= EMAIL_PS_ERRCODE_POP3_CMD_MAX)
            {
                return SRV_EMAIL_RESULT_POP3_CMD_ERROR;
            }
            else if (errcode >= EMAIL_PS_ERRCODE_IMAP4_CMD_FAIL &&
                     errcode <= EMAIL_PS_ERRCODE_IMAP4_CMD_MAX)
            {
                return SRV_EMAIL_RESULT_IMAP4_CMD_ERROR;
            }
            else
            {
                return SRV_EMAIL_RESULT_INTERNAL_ERROR;
            }
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_ps_error
 * DESCRIPTION
 *  This function is used to get the Email PS error.
 * PARAMETERS
 *  result_p            [IN]        The pointer point to the result
 *  major               [OUT]       Used to store the major error
 *  minor               [OUT]       Used to store the minor error
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_get_ps_error(email_ps_result_struct *result_p, S32 *major, S32 *minor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result_p->errtype)
    {
        case EMAIL_PS_ERRTYPE_EMAIL:
        case EMAIL_PS_ERRTYPE_PROTOCOL:
            *major = SRV_EMAIL_MAIL_ERROR;
            *minor = (S32)srv_email_convert_ps_error((email_ps_error_code)result_p->errcode);
            break;

        case EMAIL_PS_ERRTYPE_FS:
            *major = SRV_EMAIL_FS_ERROR;
            *minor = result_p->errcode;
            break;

        case EMAIL_PS_ERRTYPE_SOCKET:
            *major = SRV_EMAIL_SOCKET_ERROR;
            *minor = result_p->errcode;
            break;

        case EMAIL_PS_ERRTYPE_SSL:
            *major = SRV_EMAIL_TLS_ERROR;
            *minor = result_p->errcode;
            break;

        default:
            *major = SRV_EMAIL_MAIL_ERROR;
            *minor = SRV_EMAIL_RESULT_INTERNAL_ERROR;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_activate_bearer
 * DESCRIPTION
 *  This function is used to activate the specified bearer.
 * PARAMETERS
 *  nwk_acct_id     [IN]        The data account id
 *  major           [OUT]       The major error when activating unsuccessfully
 *  minor           [OUT]       The minor error when activating unsuccessfully
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_activate_bearer(U32 nwk_acct_id, S32 *major, S32 *minor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (major)
    {
        *major = SRV_EMAIL_MAIL_ERROR;
    }
    if (minor)
    {
        *minor = SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL;
    }

    ret = cbm_open_bearer(nwk_acct_id);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_OPEN_BEARER, nwk_acct_id, ret);

    if (ret == CBM_OK)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }
    else if (ret == CBM_WOULDBLOCK)
    {
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        return SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_is_bearer_activated
 * DESCRIPTION
 *  This function is used to check if the bearer is activated.
 * PARAMETERS
 *  nwk_acct_id     [IN]        The data account id
 * RETURNS
 *  MMI_TRUE/MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_email_nwk_is_bearer_activated(U32 nwk_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = cbm_get_bearer_status(nwk_acct_id);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_GET_BEARER_STATUS, nwk_acct_id, ret);

    if (ret == CBM_ACTIVATED)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_create_instance_req
 * DESCRIPTION
 *  This function is used to send the CREATE_INSTANCE_REQ to Email PS.
 * PARAMETERS
 *  req_id          [IN]        The request id
 *  protocol        [IN]        The protocol type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_create_instance_req(U32 req_id, email_ps_protocol_type_enum protocol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_create_instance_req_struct *create_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_req_p = OslAllocDataPtr(email_ps_create_instance_req_struct);

    create_req_p->req_id = req_id;
    create_req_p->protocol = protocol;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_CREATE_INSTANCE_REQ, create_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_create_instance_rsp
 * DESCRIPTION
 *  This function is used to process the CREATE_INSTANCE_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_create_instance_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_create_instance_rsp_struct *create_rsp_p = (email_ps_create_instance_rsp_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)create_rsp_p->req_id;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;
#endif /* __MMI_EMAIL__ */
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (ret)
    {
        if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_CREATING)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                cntx_p->nwk_state,
                0,
                SRV_EMAIL_NWK_STATE_CREATING,
                0);
            return;
        }

        comm_p = &cntx_p->common;

        EMAILSRV_ASSERT_DBG(comm_p->protocol == create_rsp_p->protocol);

        if (create_rsp_p->result.ret)
        {
            comm_p->ps_handle = create_rsp_p->handle;
        }
        else
        {
            srv_email_get_ps_error(&create_rsp_p->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, create_rsp_p->result.err_string);
        }

        srv_email_nwk_fsm(cntx_p);
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        ret = srv_email_nwk_cloud_create_instance_rsp_hdlr(create_rsp_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_destroy_instance_req
 * DESCRIPTION
 *  This function is used to send the DESCROY_INSTANCE_REQ to Email PS.
 * PARAMETERS
 *  handle          [IN]        The Email PS handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_destroy_instance_req(EMAIL_PS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_destroy_instance_req_struct *destroy_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    destroy_req_p = OslAllocDataPtr(email_ps_destroy_instance_req_struct);

    destroy_req_p->handle = handle;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_DESTROY_INSTANCE_REQ, destroy_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_destroy_instance_rsp
 * DESCRIPTION
 *  This function is used to process the DESTROY_INSTANCE_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_destroy_instance_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_destroy_instance_rsp_struct *destroy_rsp_p = (email_ps_destroy_instance_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!destroy_rsp_p->result.ret)
    {
        EMAILSRV_ASSERT_DBG(0);
        //trace: error
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_connect_req
 * DESCRIPTION
 *  This function is used to send the CONN_REQ to Email PS.
 * PARAMETERS
 *  handle              [IN]        The Email PS handle
 *  nwk_acct_id         [IN]        The data account id
 *  server_addr_p       [IN]        The pointer point to the server address
 *  req_filename        [IN]        The request filename
 *  server_addr_p       [IN]        The response filename
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_connect_req(
        EMAIL_PS_HANDLE handle,
        U32 nwk_acct_id,
        srv_email_server_struct *server_addr_p,
        const WCHAR *req_filename,
        const WCHAR *rsp_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_conn_req_struct *connect_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    connect_req_p = OslAllocDataPtr(email_ps_conn_req_struct);

    connect_req_p->handle = handle;
    connect_req_p->data_account_id = nwk_acct_id;

    switch (server_addr_p->sec_mode)
    {
        case SRV_EMAIL_SEC_NONE:
            connect_req_p->connect_type = EMAIL_PS_SOCKET_NORMAL;
            connect_req_p->server_port = server_addr_p->port_num;
            break;

        case SRV_EMAIL_SEC_SSL_TLS:
            connect_req_p->connect_type = EMAIL_PS_SOCKET_SSL;
            connect_req_p->server_port = server_addr_p->sec_port_num;
            break;

        case SRV_EMAIL_SEC_STARTTLS:
            connect_req_p->connect_type = EMAIL_PS_SOCKET_TLS;
            connect_req_p->server_port = server_addr_p->port_num;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, server_addr_p->sec_mode, 0, 0);
            break;
    }

    mmi_ucs2_to_asc(connect_req_p->server_addr, (CHAR*)server_addr_p->server_name);
    if (req_filename)
    {
        mmi_ucs2cpy((CHAR*)connect_req_p->imap_id_input_file, (const CHAR*)req_filename);
    }
    if (rsp_filename)
    {
        mmi_ucs2cpy((CHAR*)connect_req_p->imap_id_output_file, (const CHAR*)rsp_filename);
    }

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_CONN_REQ, connect_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_connect_rsp
 * DESCRIPTION
 *  This function is used to process the CONN_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_connect_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_conn_rsp_struct *connect_rsp_p = (email_ps_conn_rsp_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;
#endif /* __MMI_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(connect_rsp_p->handle);
    if (cntx_p)
    {
        if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_CONNECTING)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                cntx_p->nwk_state,
                0,
                SRV_EMAIL_NWK_STATE_CONNECTING,
                0);
            return;
        }

        comm_p = &cntx_p->common;

        if (connect_rsp_p->result.ret)
        {
            comm_p->capa_mask = connect_rsp_p->capa_mask;

            if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3 &&
                comm_p->auth.auth_type == SRV_EMAIL_AUTH_APOP &&
                (comm_p->capa_mask & EMAIL_PS_CAPA_APOP) == 0)
            {
                srv_email_set_error_cause(
                    &comm_p->result,
                    SRV_EMAIL_MAIL_ERROR,
                    SRV_EMAIL_RESULT_SERVER_NOT_SUPPORT_APOP,
                    NULL);
            }
        }
        else
        {
            srv_email_get_ps_error(&connect_rsp_p->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, connect_rsp_p->result.err_string);
        }

        srv_email_nwk_fsm(cntx_p);
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        MMI_BOOL ret;
        ret = srv_email_nwk_cloud_connect_rsp_hdlr(connect_rsp_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, connect_rsp_p->handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_disconnect_req
 * DESCRIPTION
 *  This function is used to send the DISCONN_REQ to Email PS.
 * PARAMETERS
 *  handle              [IN]        The Email PS handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_disconnect_req(EMAIL_PS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_disconn_req_struct *disconn_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    disconn_req_p = OslAllocDataPtr(email_ps_disconn_req_struct);

    disconn_req_p->handle = handle;
    disconn_req_p->forcely = MMI_TRUE;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_DISCONN_REQ, disconn_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_disconnect_rsp
 * DESCRIPTION
 *  This function is used to process the DISCONN_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_disconnect_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_disconn_rsp_struct *disconn_rsp_p = (email_ps_disconn_rsp_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
#endif /* __MMI_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(disconn_rsp_p->handle);
    if (cntx_p)
    {
        if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_DISCONNECTING)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                cntx_p->nwk_state,
                0,
                SRV_EMAIL_NWK_STATE_DISCONNECTING,
                0);
            return;
        }

        comm_p = &cntx_p->common;

        if (!disconn_rsp_p->result.ret)
        {
            /* Process this case as success */
        }

        if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
        {
            srv_email_pop3_cntx_struct *pop3_cntx_p = (srv_email_pop3_cntx_struct*)cntx_p;

            if (pop3_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_DISC_DISCONNECT)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                    cntx_p,
                    pop3_cntx_p->nwk_state,
                    pop3_cntx_p->sub_state,
                    SRV_EMAIL_NWK_STATE_DISCONNECTING,
                    SRV_EMAIL_NWK_SUB_STATE_DISC_DISCONNECT);
                return;
            }

            srv_email_pop3_disc_fsm(pop3_cntx_p);
        }
        else
        {
            srv_email_nwk_fsm(cntx_p);
        }
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        MMI_BOOL ret;
        ret = srv_email_nwk_cloud_disconnect_rsp_hdlr(disconn_rsp_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, disconn_rsp_p->handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_auth_req
 * DESCRIPTION
 *  This function is used to send the AUTH_REQ to Email PS.
 * PARAMETERS
 *  handle          [IN]        The Email PS handle
 *  capa_mask       [IN]        The capability mask
 *  auth_p          [IN]        The pointer point to the authentication information
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_auth_req(EMAIL_PS_HANDLE handle, U32 capa_mask, srv_email_auth_struct *auth_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_auth_req_struct *auth_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    auth_req_p = OslAllocDataPtr(email_ps_auth_req_struct);

    auth_req_p->handle = handle;

    if (auth_p &&
        auth_p->auth_type == SRV_EMAIL_AUTH_APOP &&
        (capa_mask & EMAIL_PS_CAPA_APOP))
    {
        auth_req_p->method = EMAIL_PS_AUTH_METHOD_APOP;
    }

    mmi_ucs2_to_asc(auth_req_p->username, (CHAR*)auth_p->username);
    mmi_ucs2_to_asc(auth_req_p->password, (CHAR*)auth_p->password);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_AUTH_REQ, auth_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_auth_rsp
 * DESCRIPTION
 *  This function is used to process the AUTH_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_auth_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_auth_rsp_struct *auth_rsp_p = (email_ps_auth_rsp_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;
#endif /* __MMI_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(auth_rsp_p->handle);
    if (cntx_p)
    {
        if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_AUTHORIZING)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                cntx_p->nwk_state,
                0,
                SRV_EMAIL_NWK_STATE_AUTHORIZING,
                0);
            return;
        }

        comm_p = &cntx_p->common;

        if (!auth_rsp_p->result.ret)
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */
            {
                srv_email_get_ps_error(&auth_rsp_p->result, &major, &minor);
                srv_email_set_error_cause(&comm_p->result, major, minor, auth_rsp_p->result.err_string);
            }
        }

        srv_email_nwk_fsm(cntx_p);
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        MMI_BOOL ret;
        ret = srv_email_nwk_cloud_auth_rsp_hdlr(auth_rsp_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, auth_rsp_p->handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_open_folder_req
 * DESCRIPTION
 *  This function is used to send FLD_OPEN_REQ to Email PS.
 * PARAMETERS
 *  handle          [IN]        The Email PS handle
 *  mailbox         [IN]        The mailbox name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_open_folder_req(EMAIL_PS_HANDLE handle, const CHAR *mailbox)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_fld_open_req_struct *open_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    open_req_p = OslAllocDataPtr(email_ps_fld_open_req_struct);

    open_req_p->handle = handle;
    strcpy(open_req_p->boxname, mailbox);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_FLD_OPEN_REQ, open_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_open_folder_rsp
 * DESCRIPTION
 *  This function is used to process the FLD_OPEN_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_open_folder_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_fld_open_rsp_struct *open_rsp_p = (email_ps_fld_open_rsp_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;
#endif /* __MMI_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(open_rsp_p->handle);
    if (cntx_p)
    {
        comm_p = &cntx_p->common;

        if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
        {
            srv_email_pop3_cntx_struct *pop3_cntx_p = (srv_email_pop3_cntx_struct*)cntx_p;
            srv_email_pop3_session_struct *pop3_sess_p = &pop3_cntx_p->session;

            if (pop3_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
                pop3_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                    cntx_p,
                    pop3_cntx_p->nwk_state,
                    pop3_cntx_p->sub_state,
                    SRV_EMAIL_NWK_STATE_UPDATING,
                    SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER);
                return;
            }

            if (open_rsp_p->result.ret)
            {
                pop3_sess_p->total_msg_num = open_rsp_p->total_msg_num;
            }
            else
            {
                srv_email_get_ps_error(&open_rsp_p->result, &major, &minor);
                srv_email_set_error_cause(&comm_p->result, major, minor, open_rsp_p->result.err_string);
            }

            srv_email_pop3_update_fsm(pop3_cntx_p);
        }
        else if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
        {
            srv_email_imap4_cntx_struct *imap4_cntx_p = (srv_email_imap4_cntx_struct*)cntx_p;
            srv_email_imap4_session_struct *imap4_sess_p = &imap4_cntx_p->session;

            if (imap4_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
                imap4_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                    cntx_p,
                    imap4_cntx_p->nwk_state,
                    imap4_cntx_p->sub_state,
                    SRV_EMAIL_NWK_STATE_UPDATING,
                    SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER);
                return;
            }

            if (open_rsp_p->result.ret)
            {
                imap4_sess_p->total_msg_num = open_rsp_p->total_msg_num;
                imap4_sess_p->uid_validity = open_rsp_p->uid_validity;
            }
            else
            {
                srv_email_get_ps_error(&open_rsp_p->result, &major, &minor);
                srv_email_set_error_cause(&comm_p->result, major, minor, open_rsp_p->result.err_string);
            }

            srv_email_imap4_update_fsm(imap4_cntx_p);
        }
        else
        {
            EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
        }
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        MMI_BOOL ret;
        ret = srv_email_nwk_cloud_fldr_open_rsp_hdlr(open_rsp_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, open_rsp_p->handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_list_uid_req
 * DESCRIPTION
 *  This function is used to send MSG_UID_LIST_REQ to Email PS.
 * PARAMETERS
 *  handle          [IN]        The Email PS handle
 *  start_index     [IN]        The start index
 *  count           [IN]        The count
 *  filename        [IN]        The filename
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_list_uid_req(EMAIL_PS_HANDLE handle, S32 start_index, S32 count, const WCHAR *filename, U32 ext_field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_uid_list_req_struct *list_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_req_p = OslAllocDataPtr(email_ps_msg_uid_list_req_struct);

    list_req_p->handle = handle;
    list_req_p->start_number = start_index;
    list_req_p->total_number = count;
    mmi_ucs2cpy((CHAR*)list_req_p->filename, (const CHAR*)filename);
    list_req_p->extra_field_type = (email_ps_uid_list_extra_field_type_enum)ext_field;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_UID_LIST_REQ, list_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_list_uid_rsp
 * DESCRIPTION
 *  This function is used to process the MSG_UID_LIST_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_list_uid_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_uid_list_rsp_struct *list_rsp_p = (email_ps_msg_uid_list_rsp_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;
#endif /* __MMI_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(list_rsp_p->handle);
    if (cntx_p)
    {
        comm_p = &cntx_p->common;

        if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
        {
            srv_email_pop3_cntx_struct *pop3_cntx_p = (srv_email_pop3_cntx_struct*)cntx_p;

            if (pop3_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
                pop3_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                    cntx_p,
                    pop3_cntx_p->nwk_state,
                    pop3_cntx_p->sub_state,
                    SRV_EMAIL_NWK_STATE_UPDATING,
                    SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID);
                return;
            }

            if (!list_rsp_p->result.ret)
            {
                srv_email_get_ps_error(&list_rsp_p->result, &major, &minor);
                srv_email_set_error_cause(&comm_p->result, major, minor, list_rsp_p->result.err_string);
            }

            srv_email_pop3_update_fsm(pop3_cntx_p);
        }
        else if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
        {
            srv_email_imap4_cntx_struct *imap4_cntx_p = (srv_email_imap4_cntx_struct*)cntx_p;

            if (imap4_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
                imap4_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                    cntx_p,
                    imap4_cntx_p->nwk_state,
                    imap4_cntx_p->sub_state,
                    SRV_EMAIL_NWK_STATE_UPDATING,
                    SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID);
                return;
            }

            if (!list_rsp_p->result.ret)
            {
                srv_email_get_ps_error(&list_rsp_p->result, &major, &minor);
                srv_email_set_error_cause(&comm_p->result, major, minor, list_rsp_p->result.err_string);
            }

            srv_email_imap4_update_fsm(imap4_cntx_p);
        }
        else
        {
            EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
        }
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        MMI_BOOL ret;
        ret = srv_email_nwk_cloud_list_uid_rsp_hdlr(list_rsp_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, list_rsp_p->handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_fetch_mail_req
 * DESCRIPTION
 *  This function is used to send the MSG_FETCH_REQ to PS.
 * PARAMETERS
 *  handle          [IN]        The PS handle
 *  msg_uid         [IN]        The email sequence number (for POP3) or uid (for IMAP4)
 *  type            [IN]        The fetch type
 *  partial_count   [IN]        The partial count
 *  part_num        [IN]        The part number string
 *  filename        [IN]        The file name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_fetch_mail_req(
        EMAIL_PS_HANDLE handle,
        U32 msg_uid,
        email_ps_fetch_type_enum type,
        S32 partial_count,
        const CHAR *part_num,
        const WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_fetch_req_struct *fetch_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fetch_req_p = OslAllocDataPtr(email_ps_msg_fetch_req_struct);

    fetch_req_p->handle = handle;
    fetch_req_p->msg_id = msg_uid;
    fetch_req_p->type = type;
    fetch_req_p->partial_count = partial_count;
    if (part_num)
    {
        strcpy(fetch_req_p->part_number, part_num);
    }
    mmi_ucs2cpy((CHAR*)fetch_req_p->filename, (const CHAR*)filename);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_FETCH_REQ, fetch_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_fetch_mail_rsp
 * DESCRIPTION
 *  This function is used to process the MSG_FETCH_LIST_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_fetch_mail_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_fetch_rsp_struct *fetch_rsp_p = (email_ps_msg_fetch_rsp_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;
#endif /* __MMI_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(fetch_rsp_p->handle);
    if (cntx_p)
    {
        comm_p = &cntx_p->common;

        if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
        {
            srv_email_pop3_cntx_struct *pop3_cntx_p = (srv_email_pop3_cntx_struct*)cntx_p;

            if (pop3_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
                pop3_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                    cntx_p,
                    pop3_cntx_p->nwk_state,
                    pop3_cntx_p->sub_state,
                    SRV_EMAIL_NWK_STATE_RECEIVING,
                    SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);
                return;
            }

            if (!fetch_rsp_p->result.ret)
            {
                srv_email_get_ps_error(&fetch_rsp_p->result, &major, &minor);
                srv_email_set_error_cause(&comm_p->result, major, minor, fetch_rsp_p->result.err_string);
            }

            srv_email_pop3_recv_fsm(pop3_cntx_p);
        }
        else if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
        {
            srv_email_imap4_cntx_struct *imap4_cntx_p = (srv_email_imap4_cntx_struct*)cntx_p;

            if (imap4_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
                imap4_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                    cntx_p,
                    imap4_cntx_p->nwk_state,
                    imap4_cntx_p->sub_state,
                    SRV_EMAIL_NWK_STATE_RECEIVING,
                    SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);
                return;
            }

            if (!fetch_rsp_p->result.ret)
            {
                srv_email_get_ps_error(&fetch_rsp_p->result, &major, &minor);
                srv_email_set_error_cause(&comm_p->result, major, minor, fetch_rsp_p->result.err_string);
            }

            srv_email_imap4_recv_fsm(imap4_cntx_p);
        }
        else
        {
            EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
        }
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        MMI_BOOL ret;
        ret = srv_email_nwk_cloud_fetch_mail_rsp_hdlr(fetch_rsp_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, fetch_rsp_p->handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_abort_req
 * DESCRIPTION
 *  This function is used to send the ABORT_REQ to Email PS.
 * PARAMETERS
 *  handle          [IN]        The Email PS handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_abort_req(EMAIL_PS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_abort_req_struct *abort_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    abort_req_p = OslAllocDataPtr(email_ps_abort_req_struct);

    abort_req_p->handle = handle;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_ABORT_REQ, abort_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_abort_rsp
 * DESCRIPTION
 *  This function is used to process the ABORT_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_abort_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_abort_rsp_struct *abort_rsp_p = (email_ps_abort_rsp_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
#endif
#ifdef __SMS_CLOUD_SUPPORT__
    srv_email_nwk_cloud_cntx_struct *cloud_p = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(abort_rsp_p->handle);
    if (!cntx_p)
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        cloud_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(abort_rsp_p->handle);
        if (!cloud_p)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, abort_rsp_p->handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_disconnect_ind
 * DESCRIPTION
 *  This function is used to process the DISCONN_IND.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_disconnect_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_disconn_ind_struct *disconn_p = (email_ps_disconn_ind_struct*)inMsg;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(disconn_p->handle);
    if (cntx_p)
    {
        srv_email_nwk_fsm_disconn_ind(cntx_p);
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        MMI_BOOL ret;
        ret = srv_email_nwk_cloud_disconnect_ind_hdlr(disconn_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, disconn_p->handle);
        }
    }
}


void srv_email_ps_fetch_mail_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_fetch_ind_struct *ind_p = (email_ps_msg_fetch_ind_struct*)inMsg;
    email_ps_msg_fetch_cnf_struct *cnf_p = NULL;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
#endif
#ifdef __SMS_CLOUD_SUPPORT__
    srv_email_nwk_cloud_cntx_struct *cloud_p = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(ind_p->handle);
    if (!cntx_p)
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        cloud_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(ind_p->handle);
        if (!cloud_p)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, ind_p->handle);
            return;
        }
    }

    cnf_p = OslAllocDataPtr(email_ps_msg_fetch_cnf_struct);

    cnf_p->handle = ind_p->handle;
    cnf_p->ind_id = ind_p->ind_id;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_FETCH_CNF, cnf_p, NULL);
}


void srv_email_ps_imap4_push_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_imap_push_ind_struct *ind_p = (email_ps_imap_push_ind_struct*)inMsg;
    email_ps_imap_push_cnf_struct *cnf_p = NULL;
#ifdef __MMI_EMAIL__
    srv_email_nwk_cntx_struct *cntx_p = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(ind_p->handle);
    if (cntx_p)
    {
        srv_email_nwk_fsm_imap4_push_ind(cntx_p, ind_p);
    }
    else
#endif /* __MMI_EMAIL__ */
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        MMI_BOOL ret;
        ret = srv_email_nwk_cloud_imap4_push_ind_hdlr(ind_p);
        if (!ret)
    #endif /* __SMS_CLOUD_SUPPORT__ */
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, ind_p->handle);
        }
    }

    cnf_p = OslAllocDataPtr(email_ps_imap_push_cnf_struct);

    cnf_p->handle = ind_p->handle;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_IMAP_PUSH_CNF, cnf_p, NULL);
}

#ifdef __MMI_EMAIL__

/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_deactivate_bearer
 * DESCRIPTION
 *  This function is used to deactivate the specified bearer.
 * PARAMETERS
 *  nwk_acct_id     [IN]        The data account id
 * RETURNS
 *  The error code.
 *****************************************************************************/
void srv_email_nwk_deactivate_bearer(U32 nwk_acct_id, srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 app_id = CBM_INVALID_APP_ID;
    U8 temp_app_id = CBM_INVALID_APP_ID;
	MMI_BOOL ret = MMI_FALSE;
	srv_email_nwk_cntx_struct *cntx_p;
	//skyfyx11.2
	srv_email_app_id_reg_struct *app_id_reg_p;
	app_id_reg_p=srv_email_app_id_reg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_id = cbm_get_app_id(nwk_acct_id);

    cntx_p = srv_email_nwk_get_cntx_list();
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_RELEASE_BEARER, nwk_acct_id, app_id);
    if(app_id_reg_p)
    {
        while(app_id_reg_p)
	    {
		    if(app_id_reg_p->outgoing_app_id == app_id )
		    {
			    break;
		    }
		    if(app_id_reg_p->incoming_app_id == app_id )
		    {
			    break;
		    }
		    app_id_reg_p = app_id_reg_p->next;
	    }
        if (app_id_reg_p)
        {
            return;
        }
    }
	if(!app_id_reg_p)
	{  
	    while(cntx_p)
	    {
	    	if(cntx_p!=cntx)
	    	{
	    	    temp_app_id = cbm_get_app_id(cntx_p->common.nwk_acct_id);
		    	if(temp_app_id == app_id)
		        {
		            return;
		        }
	    	}
		    cntx_p = cntx_p->next;
	    }
	    
	}
	if(!app_id_reg_p && !cntx_p)
	{
	    srv_cbm_deregister_bearer_info(app_id);
        srv_cbm_deregister_bearer_event(app_id);
        cbm_release_bearer(app_id);
        ret = cbm_deregister_app_id(app_id);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_DEREGISTER_CBM_APP_ID, ret, app_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_send_mail_req
 * DESCRIPTION
 *  This function is used to send MSG_SEND_REQ to Email PS.
 * PARAMETERS
 *  handle          [IN]        The Email PS handle
 *  from_addr       [IN]        The from address
 *  rcpt_filename   [IN]        The recipient filename
 *  msg_filename    [IN]        The mail filename
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_send_mail_req(
        EMAIL_PS_HANDLE handle,
        const CHAR *from_addr,
        const WCHAR *rcpt_filename,
        const WCHAR *msg_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_send_req_struct *send_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_req_p = OslAllocDataPtr(email_ps_msg_send_req_struct);

    send_req_p->handle = handle;
    strcpy(send_req_p->from_addr, from_addr);
    mmi_ucs2cpy((CHAR*)send_req_p->rcpt_list_filename, (const CHAR*)rcpt_filename);
    mmi_ucs2cpy((CHAR*)send_req_p->msg_filename, (const CHAR*)msg_filename);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_SEND_REQ, send_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_send_mail_rsp
 * DESCRIPTION
 *  This function is used to process the AUTH_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_send_mail_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_send_rsp_struct *send_rsp_p = (email_ps_msg_send_rsp_struct*)inMsg;
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(send_rsp_p->handle);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, send_rsp_p->handle);
        return;
    }

    comm_p = &cntx_p->common;

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP)
    {
        srv_email_smtp_cntx_struct *smtp_cntx_p = (srv_email_smtp_cntx_struct*)cntx_p;

        if (smtp_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING ||
            smtp_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SEND_SEND)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                smtp_cntx_p->nwk_state,
                smtp_cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_SENDING,
                SRV_EMAIL_NWK_SUB_STATE_SEND_SEND);
            return;
        }

        if (!send_rsp_p->result.ret)
        {
            srv_email_get_ps_error(&send_rsp_p->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, send_rsp_p->result.err_string);
        }

        srv_email_smtp_send_fsm(smtp_cntx_p);
    }
    else
    {
        EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_list_size_req
 * DESCRIPTION
 *  This function is used to send the MSG_SIZE_LIST_REQ to Email PS.
 * PARAMETERS
 *  handle          [IN]        The Email PS handle
 *  start_index     [IN]        The start index
 *  count           [IN]        The count
 *  filename        [IN]        The filename
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_list_size_req(EMAIL_PS_HANDLE handle, S32 start_index, S32 count, const WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_size_list_req_struct *list_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_req_p = OslAllocDataPtr(email_ps_msg_size_list_req_struct);

    list_req_p->handle = handle;
    list_req_p->start_number = start_index;
    list_req_p->total_number = count;
    mmi_ucs2cpy((CHAR*)list_req_p->filename, (const CHAR*)filename);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_SIZE_LIST_REQ, list_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_list_size_rsp
 * DESCRIPTION
 *  This function is used to process the MSG_SIZE_LIST_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_list_size_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_size_list_rsp_struct *list_rsp_p = (email_ps_msg_size_list_rsp_struct*)inMsg;
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(list_rsp_p->handle);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, list_rsp_p->handle);
        return;
    }

    comm_p = &cntx_p->common;

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        srv_email_pop3_cntx_struct *pop3_cntx_p = (srv_email_pop3_cntx_struct*)cntx_p;

        if (pop3_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
            pop3_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                pop3_cntx_p->nwk_state,
                pop3_cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_UPDATING,
                SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE);
            return;
        }

        if (!list_rsp_p->result.ret)
        {
            srv_email_get_ps_error(&list_rsp_p->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, list_rsp_p->result.err_string);
        }

        srv_email_pop3_update_fsm(pop3_cntx_p);
    }
    else if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
    {
        srv_email_imap4_cntx_struct *imap4_cntx_p = (srv_email_imap4_cntx_struct*)cntx_p;

        if (imap4_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
            imap4_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                imap4_cntx_p->nwk_state,
                imap4_cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_UPDATING,
                SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE);
            return;
        }

        if (!list_rsp_p->result.ret)
        {
            srv_email_get_ps_error(&list_rsp_p->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, list_rsp_p->result.err_string);
        }

        srv_email_imap4_update_fsm(imap4_cntx_p);
    }
    else
    {
        EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_fetch_mail_req
 * DESCRIPTION
 *  This function is used to send the MSG_DELETE_REQ to PS.
 * PARAMETERS
 *  handle          [IN]        The PS handle
 *  filename        [IN]        The file name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_delete_mail_req(EMAIL_PS_HANDLE handle, const WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_delete_req_struct *del_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    del_req_p = OslAllocDataPtr(email_ps_msg_delete_req_struct);

    del_req_p->handle = handle;
    mmi_wcscpy(del_req_p->filename, filename);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_DELETE_REQ, del_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_fetch_mail_rsp
 * DESCRIPTION
 *  This function is used to process the MSG_FETCH_LIST_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_delete_mail_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_delete_rsp_struct *del_rsp_p = (email_ps_msg_delete_rsp_struct*)inMsg;
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(del_rsp_p->handle);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, del_rsp_p->handle);
        return;
    }

    comm_p = &cntx_p->common;

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        srv_email_pop3_cntx_struct *pop3_cntx_p = (srv_email_pop3_cntx_struct*)cntx_p;
        srv_email_pop3_state_struct *state_p = &pop3_cntx_p->state;

        if (pop3_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_DISCONNECTING ||
            pop3_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_SERVER)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                pop3_cntx_p->nwk_state,
                pop3_cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_DISCONNECTING,
                SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_SERVER);
            return;
        }

        if (!del_rsp_p->result.ret)
        {
            state_p->delete_fail = MMI_TRUE;
        }

        srv_email_pop3_disc_fsm(pop3_cntx_p);
    }
    else
    {
        EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_list_folder_req
 * DESCRIPTION
 *  This function is used to send the FLD_LIST_REQ to PS.
 * PARAMETERS
 *  handle          [IN]        The PS handle
 *  subscribed_only [IN]        If list the subscribed folder only or not
 *  filename        [IN]        The file name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_list_folder_req(EMAIL_PS_HANDLE handle, MMI_BOOL subscribed_only, const WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_fld_list_req_struct *list_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_req_p = OslAllocDataPtr(email_ps_fld_list_req_struct);

    list_req_p->handle = handle;
    list_req_p->only_subscribed = subscribed_only;
    list_req_p->recursion = MMI_TRUE;
    list_req_p->skip_inbox = MMI_TRUE;
    mmi_wcscpy(list_req_p->filename, filename);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_FLD_LIST_REQ, list_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_list_folder_rsp
 * DESCRIPTION
 *  This function is used to process the FLD_LIST_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_list_folder_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_fld_list_rsp_struct *list_rsp_p = (email_ps_fld_list_rsp_struct*)inMsg;
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(list_rsp_p->handle);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, list_rsp_p->handle);
        return;
    }

    comm_p = &cntx_p->common;

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
    {
        srv_email_imap4_cntx_struct *imap4_cntx_p = (srv_email_imap4_cntx_struct*)cntx_p;
        srv_email_imap4_state_struct *state_p = &imap4_cntx_p->state;

        if (imap4_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_LISTING_FOLDER ||
            imap4_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_SERVER)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                imap4_cntx_p->nwk_state,
                imap4_cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_LISTING_FOLDER,
                SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_SERVER);
            return;
        }

        if (!list_rsp_p->result.ret)
        {
            srv_email_get_ps_error(&list_rsp_p->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, list_rsp_p->result.err_string);
        }
        else
        {
            state_p->fldr_header.delimiter = list_rsp_p->delimiter;
        }

        srv_email_imap4_list_fldr_fsm(imap4_cntx_p);
    }
    else
    {
        EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_get_flag_req
 * DESCRIPTION
 *  This function is used to send the MSG_FLAGS_GET_REQ to Email PS.
 * PARAMETERS
 *  handle          [IN]        The Email PS handle
 *  req_filename    [IN]        The request filename
 *  rsp_filename    [IN]        The response filename
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_get_flag_req(EMAIL_PS_HANDLE handle, const WCHAR *req_filename, const WCHAR *rsp_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_flags_get_req_struct *get_req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_req_p = OslAllocDataPtr(email_ps_msg_flags_get_req_struct);

    get_req_p->handle = handle;
    mmi_ucs2cpy((CHAR*)get_req_p->req_uid_list_filename, (const CHAR*)req_filename);
    mmi_ucs2cpy((CHAR*)get_req_p->rsp_uid_list_filename, (const CHAR*)rsp_filename);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_FLAGS_GET_REQ, get_req_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_ps_get_flag_rsp
 * DESCRIPTION
 *  This function is used to process the MSG_FLAGS_GET_RSP.
 * PARAMETERS
 *  inMsg           [IN]        The pointer point to the response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_ps_get_flag_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_flags_get_rsp_struct *get_rsp_p = (email_ps_msg_flags_get_rsp_struct*)inMsg;
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(get_rsp_p->handle);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, get_rsp_p->handle);
        return;
    }

    comm_p = &cntx_p->common;

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
    {
        srv_email_imap4_cntx_struct *imap4_cntx_p = (srv_email_imap4_cntx_struct*)cntx_p;

        if (imap4_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
            imap4_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_FLAG)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                imap4_cntx_p->nwk_state,
                imap4_cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_UPDATING,
                SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_FLAG);
            return;
        }

        if (!get_rsp_p->result.ret)
        {
            srv_email_get_ps_error(&get_rsp_p->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, get_rsp_p->result.err_string);
        }

        srv_email_imap4_update_fsm(imap4_cntx_p);
    }
    else
    {
        EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
        return;
    }
}


/* Set email flag (IMAP4 only) */
void srv_email_ps_set_flag_req(EMAIL_PS_HANDLE handle, const WCHAR *req_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_flags_set_req_struct *set_req_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_req_p = OslAllocDataPtr(email_ps_msg_flags_set_req_struct);
    
    set_req_p->handle = handle;
    mmi_ucs2cpy((CHAR*)set_req_p->filename, (const CHAR*)req_filename);
    
    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_FLAGS_SET_REQ, set_req_p, NULL);
}


void srv_email_ps_set_flag_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_flags_set_rsp_struct* rsp = (email_ps_msg_flags_set_rsp_struct*)inMsg;
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(rsp->handle);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, rsp->handle);
        return;
    }
    
    comm_p = &cntx_p->common;
    
    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
    {
        srv_email_imap4_cntx_struct *imap4_cntx_p = (srv_email_imap4_cntx_struct*)cntx_p;
        
        if (imap4_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SYNCING ||
            imap4_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SYNC_FLAGS)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                imap4_cntx_p->nwk_state,
                imap4_cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_SYNCING,
                SRV_EMAIL_NWK_SUB_STATE_SYNC_FLAGS);
            return;
        }

        if (!rsp->result.ret)
        {
            srv_email_get_ps_error(&rsp->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, rsp->result.err_string);
        }

        imap4_cntx_p->ps_state = rsp->result.state;
        srv_email_imap4_sync_fsm(imap4_cntx_p);
    }
    else
    {
        EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
        return;
    }
}


/* Expunge email (IMAP4 only) */
void srv_email_ps_expunge_mail_req(EMAIL_PS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_expunge_req_struct *req_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = OslAllocDataPtr(email_ps_msg_expunge_req_struct);
    
    req_p->handle = handle;
   
    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_EXPUNGE_REQ, req_p, NULL);
}


void srv_email_ps_expunge_mail_rsp(void *inMsg)
{
    // TODO:
    //email_ps_msg_expunge_rsp_struct *rsp = (email_ps_msg_expunge_rsp_struct*)inMsg;
}

void srv_email_ps_close_folder_req(EMAIL_PS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_fld_close_req_struct *req_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = OslAllocDataPtr(email_ps_fld_close_req_struct);
    req_p->handle = handle;
    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_FLD_CLOSE_REQ, req_p, NULL);
}

void srv_email_ps_close_folder_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_fld_close_rsp_struct *rsp = (email_ps_fld_close_rsp_struct*)inMsg;
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(rsp->handle);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, rsp->handle);
        return;
    }

    comm_p = &cntx_p->common;
    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
    {
        srv_email_imap4_cntx_struct *imap4_cntx_p = (srv_email_imap4_cntx_struct*)cntx_p;
        
        if (imap4_cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SYNCING ||
            imap4_cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SYNC_DELETE)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                imap4_cntx_p->nwk_state,
                imap4_cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_SYNCING,
                SRV_EMAIL_NWK_SUB_STATE_SYNC_DELETE);
            return;
        }

        if (!rsp->result.ret)
        {
            srv_email_get_ps_error(&rsp->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, rsp->result.err_string);
        }

        imap4_cntx_p->ps_state = rsp->result.state;
        srv_email_imap4_sync_fsm(imap4_cntx_p);
    }
    else
    {
        EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
        return;
    }
}


void srv_email_ps_send_mail_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_send_ind_struct *ind_p = (email_ps_msg_send_ind_struct*)inMsg;
    email_ps_msg_send_cnf_struct *cnf_p = NULL;
    srv_email_nwk_cntx_struct *cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_get_cntx_by_ps_handle(ind_p->handle);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_WARNING_NWK_PS_HANDLE_INVALID, ind_p->handle);
        return;
    }

    cnf_p = OslAllocDataPtr(email_ps_msg_send_cnf_struct);

    cnf_p->handle = ind_p->handle;
    cnf_p->ind_id = ind_p->ind_id;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_SEND_CNF, cnf_p, NULL);
}

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__

void srv_email_ps_create_folder_req(EMAIL_PS_HANDLE handle, const CHAR *mailbox)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_fld_create_req_struct *req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = OslAllocDataPtr(email_ps_fld_create_req_struct);

    req_p->handle = handle;
    strcpy(req_p->fld_name, mailbox);

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_FLD_CREATE_REQ, req_p, NULL);
}


void srv_email_ps_create_folder_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_fld_create_rsp_struct *rsp_p = (email_ps_fld_create_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_fldr_create_rsp_hdlr(rsp_p);
}


void srv_email_ps_append_mail_req(
        EMAIL_PS_HANDLE handle,
        const CHAR *fldr_name_p,
        const WCHAR *msg_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_append_req_struct *req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = OslAllocDataPtr(email_ps_msg_append_req_struct);

    req_p->handle = handle;
    strcpy(req_p->fld_name, fldr_name_p);
    mmi_ucs2cpy((CHAR*)req_p->msg_filename, (const CHAR*)msg_filename);
    req_p->msg_flag = EMAIL_PS_MESSAGE_ATTR_READED;

    srv_email_ps_send_msg(MSG_ID_EMAIL_PS_MSG_APPEND_REQ, req_p, NULL);
}


void srv_email_ps_append_mail_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_ps_msg_append_rsp_struct *rsp_p = (email_ps_msg_append_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_append_mail_rsp_hdlr(rsp_p);
}

#endif /* __SMS_CLOUD_SUPPORT__ */

#endif /* defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__) */

