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
 *  EmailSrvNetwork.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email network external functions.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__)
#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvNetworkProt.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_trc_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "string.h"

#ifdef __MMI_EMAIL__
#include "EmailSrvStorage.h"
#include "customer_ps_inc.h"
#include "fs_errcode.h"

/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_create
 * DESCRIPTION
 *  This function is used to create a network instance.
 * PARAMETERS
 *  acct_id         [IN]        The account id
 *  is_incoming     [IN]        This network is used for receiving or not
 *  handle          [OUT]       Used to store the network instance handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_create(
                        EMAIL_ACCT_ID acct_id,
                        MMI_BOOL is_incoming,
                        EMAIL_NWK_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL ret = MMI_FALSE;
    MMI_BOOL is_new_cntx = MMI_FALSE;
    S32 errcode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_CREATE, acct_id, is_incoming, handle);

    if (!handle)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    retval = srv_email_acct_check_valid(acct_id, &ret);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        return retval;
    }
    if (!ret)
    {
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }

    cntx_p = srv_email_nwk_get_cntx_by_id(acct_id, is_incoming);
    if (!cntx_p)
    {
        cntx_p = srv_email_nwk_create_cntx(acct_id, is_incoming, &errcode);
        if (!cntx_p)
        {
            return (srv_email_result_enum)errcode;
        }
        is_new_cntx = MMI_TRUE;
    }

    ret = srv_email_nwk_is_cb_full(cntx_p);
    if (ret)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    cb_p = (srv_email_nwk_cb_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_cb_struct));
    if (!cb_p)
    {
        if (is_new_cntx)
        {
            srv_email_nwk_destroy_cntx(cntx_p);
        }
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    memset(cb_p, 0, sizeof(srv_email_nwk_cb_struct));

    srv_email_nwk_append_cb_to_idle_list(cntx_p, cb_p);

    *handle = (EMAIL_NWK_HANDLE)cb_p;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified network instance.
 * PARAMETERS
 *  handle      [IN]        The network handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_destroy(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    MMI_BOOL valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_DESTROY, handle);

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    srv_email_nwk_remove_cb(cntx_p, cb_p, &valid);
    if (!valid)
    {
        if (cntx_p->common.acct_handle != EMAIL_ACCT_INVALID_HANDLE)
        {
            srv_email_acct_destroy(cntx_p->common.acct_handle);
            cntx_p->common.acct_handle = EMAIL_ACCT_INVALID_HANDLE;
        }
        cntx_p->common.acct_id = EMAIL_ACCT_INVALID_ID;
        srv_email_nwk_stop_job(cntx_p);
        srv_email_nwk_start_job(srv_email_nwk_destroy_cntx, cntx_p);
    }

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_set_process_notify
 * DESCRIPTION
 *  This function is used to set the notify callback for the specified network instance.
 * PARAMETERS
 *  handle          [IN]        The network handle
 *  callback        [IN]        The notify callback function
 *  user_data       [IN]        The user data
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_set_process_notify(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_proc_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_SET_PROC_NOTIFY, handle, callback, user_data);

    if (!callback)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    cb_p->proc_callback = callback;
    cb_p->proc_user_data = user_data;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_set_finish_notify
 * DESCRIPTION
 *  This function is used to set the notify callback for the specified network instance.
 * PARAMETERS
 *  handle          [IN]        The network handle
 *  callback        [IN]        The notify callback function
 *  user_data       [IN]        The user data
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_set_finish_notify(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_finish_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_SET_FINISH_NOTIFY, handle, callback, user_data);

    if (!callback)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    cb_p->finish_callback = callback;
    cb_p->finish_user_data = user_data;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_test_nwk
 * DESCRIPTION
 *  This function is used to test the network connection.
 * PARAMETERS
 *  handle      [IN]        The network handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_test_nwk(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_CONNECT, handle);

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    cb_p->action = SRV_EMAIL_NWK_TEST_NWK;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_connect
 * DESCRIPTION
 *  This function is used to connect the server.
 * PARAMETERS
 *  handle      [IN]        The network handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_connect(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_CONNECT, handle);

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    cb_p->action = SRV_EMAIL_NWK_CONNECT;

    /* Get the INBOX id */
    cb_p->fldr_id[0] = srv_email_stor_fldr_get_id_by_type(
                        cntx_p->common.acct_id,
                        SRV_EMAIL_FLDR_TYPE_INBOX);
    cb_p->fldr_index = 0;
    cb_p->fldr_count = 1;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_disconnect
 * DESCRIPTION
 *  This function is used to disconnect the server.
 * PARAMETERS
 *  handle      [IN]        The network handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_disconnect(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMIAL_FUNC_NWK_DISCONNECT, handle);

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    if (!(cb_p->state & SRV_EMAIL_NWK_CB_CONNECTED))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_STATE_WRONG, handle, cb_p->state);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    cb_p->action = SRV_EMAIL_NWK_DISCONNECT;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_send
 * DESCRIPTION
 *  This function is used to send emails.
 * PARAMETERS
 *  handle          [IN]        The network handle
 *  nwk_send_p      [IN]        The send option
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_send(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_send_struct *nwk_send_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_send_struct *send_opt_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL valid = MMI_FALSE;
    EMAIL_MSG_ID msg_id = EMAIL_MSG_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_SEND, handle, nwk_send_p);

    if (!nwk_send_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_INFO_NWK_SEND_OPTION,
        nwk_send_p->send_outbox,
        nwk_send_p->msg_handle,
        nwk_send_p->msg_id,
        nwk_send_p->move_to_sent);

    if (!nwk_send_p->send_outbox)
    {
        if (nwk_send_p->msg_handle == EMAIL_MSG_INVALID_HANDLE)
        {
            msg_id = nwk_send_p->msg_id;
        }
        else
        {
            msg_id = srv_email_msg_get_id(nwk_send_p->msg_handle);
        }

        if (msg_id != EMAIL_MSG_INVALID_ID)
        {
            retval = srv_email_stor_msg_id_valid_ext(nwk_send_p->msg_id, MMI_TRUE, &valid);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                return retval;
            }
            else
            {
                if (!valid)
                {
                    srv_email_errno_set(FS_FILE_NOT_FOUND);
                    return SRV_EMAIL_RESULT_FS_ERROR;
                }
            }
        }
    }

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    send_opt_p = (srv_email_nwk_send_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_send_struct));
    if (!send_opt_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memcpy(send_opt_p, nwk_send_p, sizeof(srv_email_nwk_send_struct));

    cb_p->action = SRV_EMAIL_NWK_SEND;
    cb_p->action_data = send_opt_p;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_retrieve
 * DESCRIPTION
 *  This function is used to retrieve the email.
 * PARAMETERS
 *  handle          [IN]        The network handle
 *  nwk_retr_p      [IN]        The retrieve option
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_retrieve(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_retr_struct *nwk_retr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_retr_struct *retr_opt_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_RETRIEVE, handle, nwk_retr_p);

    if (!nwk_retr_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_INFO_NWK_RETRIEVE_OPTION,
        nwk_retr_p->fldr_id,
        nwk_retr_p->msg_id,
        nwk_retr_p->retr_opt,
        nwk_retr_p->attach_id);

    if (nwk_retr_p->retr_opt >= SRV_EMAIL_RETRIEVE_TOTAL)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    retval = srv_email_msg_check_valid(nwk_retr_p->msg_id, &valid);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        return retval;
    }
    else
    {
        if (!valid)
        {
            return SRV_EMAIL_RESULT_INVALID_MSG;
        }
    }

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    retr_opt_p = (srv_email_nwk_retr_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_retr_struct));
    if (!retr_opt_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memcpy(retr_opt_p, nwk_retr_p, sizeof(srv_email_nwk_retr_struct));

    cb_p->action = SRV_EMAIL_NWK_RETRIEVE;
    cb_p->action_data = retr_opt_p;

    cb_p->fldr_id[0] = retr_opt_p->fldr_id;
    cb_p->fldr_index = 0;
    cb_p->fldr_count = 1;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_receive
 * DESCRIPTION
 *  This function is used to receive the emails.
 * PARAMETERS
 *  handle          [IN]        The network handle
 *  nwk_recv_p      [IN]        The receive option
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_receive(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_recv_struct *nwk_recv_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_recv_struct *recv_opt_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    U16 fldr_cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_RECEIVE, handle, nwk_recv_p);

    if (!nwk_recv_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_INFO_NWK_RECEIVE_OPTION,
        nwk_recv_p->all_fldr,
        nwk_recv_p->fldr_id,
        nwk_recv_p->recv_opt);

    if (nwk_recv_p->recv_opt >= SRV_EMAIL_RECEIVE_TOTAL)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    recv_opt_p = (srv_email_nwk_recv_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_recv_struct));
    if (!recv_opt_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memcpy(recv_opt_p, nwk_recv_p, sizeof(srv_email_nwk_recv_struct));

    if (recv_opt_p->all_fldr)
    {
        cb_p->fldr_id[0] = srv_email_stor_fldr_get_id_by_type(
                            cntx_p->common.acct_id,
                            SRV_EMAIL_FLDR_TYPE_INBOX);
        cb_p->fldr_index = 0;
        cb_p->fldr_count = 1;

        retval = srv_email_nwk_list_remote_fldr_id(cntx_p->common.acct_id, &cb_p->fldr_id[1], &fldr_cnt);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_mem_free(recv_opt_p);
            memset(cb_p->fldr_id, 0, sizeof(EMAIL_FLDR_ID) * (SRV_EMAIL_MAX_FLDR_NUM + 1));
            cb_p->fldr_index = 0;
            cb_p->fldr_count = 0;
            return retval;
        }

        cb_p->fldr_count += fldr_cnt;
    }
    else
    {
        cb_p->fldr_id[0] = recv_opt_p->fldr_id;
        cb_p->fldr_index = 0;
        cb_p->fldr_count = 1;
    }

    cb_p->action = SRV_EMAIL_NWK_RECEIVE;
    cb_p->action_data = recv_opt_p;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_sync
 * DESCRIPTION
 *  This function is used to sync the emails.
 * PARAMETERS
 *  handle          [IN]        The network handle
 *  nwk_sync_p      [IN]        The sync option
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_sync(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_sync_struct *nwk_sync_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_sync_struct *sync_opt_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    U16 fldr_cnt = 0;
    MMI_BOOL valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_SYNC, handle, nwk_sync_p);

    if (!nwk_sync_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_INFO_NWK_SYNC_OPTION,
        nwk_sync_p->all_fldr,
        nwk_sync_p->fldr_id,
        nwk_sync_p->all_msg,
        nwk_sync_p->msg_id);

    if (!nwk_sync_p->all_msg)
    {
        retval = srv_email_msg_check_valid(nwk_sync_p->msg_id, &valid);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            return retval;
        }
        else
        {
            if (!valid)
            {
                return SRV_EMAIL_RESULT_INVALID_MSG;
            }
        }
    }

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    sync_opt_p = (srv_email_nwk_sync_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_sync_struct));
    if (!sync_opt_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memcpy(sync_opt_p, nwk_sync_p, sizeof(srv_email_nwk_sync_struct));

    if (sync_opt_p->all_fldr)
    {
        cb_p->fldr_id[0] = srv_email_stor_fldr_get_id_by_type(
                            cntx_p->common.acct_id,
                            SRV_EMAIL_FLDR_TYPE_INBOX);
        cb_p->fldr_index = 0;
        cb_p->fldr_count = 1;

        retval = srv_email_nwk_list_remote_fldr_id(cntx_p->common.acct_id, &cb_p->fldr_id[1], &fldr_cnt);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_mem_free(sync_opt_p);
            memset(cb_p->fldr_id, 0, sizeof(EMAIL_FLDR_ID) * (SRV_EMAIL_MAX_FLDR_NUM + 1));
            cb_p->fldr_index = 0;
            cb_p->fldr_count = 0;
            return retval;
        }

        cb_p->fldr_count += fldr_cnt;
    }
    else
    {
        cb_p->fldr_id[0] = sync_opt_p->fldr_id;
        cb_p->fldr_index = 0;
        cb_p->fldr_count = 1;
    }

    cb_p->action = SRV_EMAIL_NWK_SYNC;
    cb_p->action_data = sync_opt_p;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_list_folder
 * DESCRIPTION
 *  This function is used to list the remote folder from server.
 * PARAMETERS
 *  handle          [IN]        The network handle
 *  list_fldr_p     [IN]        The list folder option
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_list_folder(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_list_fldr_struct *list_fldr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_list_fldr_struct *list_opt_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_LIST_FOLDER, handle, list_fldr_p);

    if (!list_fldr_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_INFO_NWK_LIST_FOLDER_OPTION,
        list_fldr_p->fldr_num,
        list_fldr_p->subscribed_only);

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    list_opt_p = (srv_email_nwk_list_fldr_struct*)
        srv_email_mem_alloc(sizeof(srv_email_nwk_list_fldr_struct));
    if (!list_opt_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memcpy(list_opt_p, list_fldr_p, sizeof(srv_email_nwk_list_fldr_struct));

    cb_p->action = SRV_EMAIL_NWK_LIST_FOLDER;
    cb_p->action_data = list_opt_p;

    /* Get the INBOX id */
    cb_p->fldr_id[0] = srv_email_stor_fldr_get_id_by_type(
		                cntx_p->common.acct_id,
		                SRV_EMAIL_FLDR_TYPE_INBOX);
    cb_p->fldr_index = 0;
    cb_p->fldr_count = 1;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_refresh
 * DESCRIPTION
 *  This function is used to refresh the inbox.
 * PARAMETERS
 *  handle          [IN]        The network handle
 *  refresh_p       [IN]        The refresh option
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_refresh(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_refresh_struct *refresh_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_refresh_struct *refresh_opt_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_REFRESH, handle, refresh_p);

    if (!refresh_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_REFRESH_OPTION, refresh_p->recv_opt);

    if (refresh_p->recv_opt >= SRV_EMAIL_RECEIVE_TOTAL)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    refresh_opt_p = (srv_email_nwk_refresh_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_refresh_struct));
    if (!refresh_opt_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memcpy(refresh_opt_p, refresh_p, sizeof(srv_email_nwk_refresh_struct));

    cb_p->action = SRV_EMAIL_NWK_REFRESH;
    cb_p->action_data = refresh_opt_p;

    cb_p->fldr_id[0] = srv_email_stor_fldr_get_id_by_type(
                        cntx_p->common.acct_id,
                        SRV_EMAIL_FLDR_TYPE_INBOX);
    cb_p->fldr_index = 0;
    cb_p->fldr_count = 1;

    srv_email_nwk_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_abort
 * DESCRIPTION
 *  This function is used to abort the network operation.
 * PARAMETERS
 *  handle      [IN]        The network handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_abort(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_ABORT, handle);

    cntx_p = srv_email_nwk_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action == SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_NO_OPERATION, handle);
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    srv_email_nwk_abort_cb(cntx_p, cb_p);

    return SRV_EMAIL_RESULT_SUCC;
}

#endif /* __MMI_EMAIL__ */ 

#ifdef __SMS_CLOUD_SUPPORT__

srv_email_result_enum srv_email_nwk_cloud_create(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_NWK_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = NULL;
    MMI_BOOL ret = MMI_FALSE;
    MMI_BOOL is_new_cntx = MMI_FALSE;
    S32 errcode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CREATE, acct_id, handle);

    if (!handle)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_cloud_get_cntx_by_id(acct_id);
    if (!cntx_p)
    {
        cntx_p = srv_email_nwk_cloud_create_cntx(acct_id, &errcode);
        if (!cntx_p)
        {
            return (srv_email_result_enum)errcode;
        }
        is_new_cntx = MMI_TRUE;
    }

    ret = srv_email_nwk_cloud_is_cb_full(cntx_p);
    if (ret)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    cb_p = (srv_email_nwk_cb_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_cb_struct));
    if (!cb_p)
    {
        if (is_new_cntx)
        {
            srv_email_nwk_cloud_destroy_cntx(cntx_p);
        }
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    memset(cb_p, 0, sizeof(srv_email_nwk_cb_struct));

    srv_email_nwk_cloud_append_cb_to_idle_list(cntx_p, cb_p);

    *handle = (EMAIL_NWK_HANDLE)cb_p;

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_nwk_cloud_destroy(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    MMI_BOOL valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_DESTROY, handle);

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    srv_email_nwk_cloud_remove_cb(cntx_p, cb_p, &valid);
    if (!valid)
    {
        cntx_p->common.acct_id = EMAIL_ACCT_INVALID_ID;
        srv_email_nwk_cloud_stop_job(cntx_p);
        srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_destroy_cntx, cntx_p);
    }

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_nwk_cloud_set_option(
                        EMAIL_NWK_HANDLE handle,
                        U32 provider_id,
                        U8 cloud_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_SET_OPTION, handle, provider_id, cloud_acct_id);

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    comm_p = &cntx_p->common;

    comm_p->provider_id = provider_id;
    comm_p->cloud_acct_id = cloud_acct_id;

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_nwk_cloud_set_process_notify(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_proc_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_SET_PROCESS_NOTIFY, handle, callback, user_data);

    if (!callback)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    cb_p->proc_callback = callback;
    cb_p->proc_user_data = user_data;

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_nwk_cloud_set_finish_notify(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_finish_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_SET_FINISH_NOTIFY, handle, callback, user_data);

    if (!callback)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    cb_p->finish_callback = callback;
    cb_p->finish_user_data = user_data;

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_nwk_cloud_connect(
                        EMAIL_NWK_HANDLE handle,
                        CHAR *fldr_name_p,
                        MMI_BOOL fldr_create)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_cloud_conn_struct *conn_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CONNECT, handle, fldr_name_p, fldr_create);

    if (!fldr_name_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    conn_p = (srv_email_nwk_cloud_conn_struct*)
        srv_email_mem_alloc(sizeof(srv_email_nwk_cloud_conn_struct));
    if (!conn_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    strcpy(conn_p->fldr_name, fldr_name_p);
    conn_p->fldr_create = fldr_create;

    cb_p->action = SRV_EMAIL_NWK_CONNECT;
    cb_p->action_data = conn_p;

    srv_email_nwk_cloud_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_cloud_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


srv_email_result_enum srv_email_nwk_cloud_disconnect(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_DISCONNECT, handle);

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    if (!(cb_p->state & SRV_EMAIL_NWK_CB_CONNECTED))
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    cb_p->action = SRV_EMAIL_NWK_DISCONNECT;

    srv_email_nwk_cloud_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_cloud_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


srv_email_result_enum srv_email_nwk_cloud_append(
                        EMAIL_NWK_HANDLE handle,
                        EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_send_struct *send_opt_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_APPEND, handle, msg_handle);

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    send_opt_p = (srv_email_nwk_send_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_send_struct));
    if (!send_opt_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    send_opt_p->send_outbox = MMI_FALSE;
    send_opt_p->msg_handle = msg_handle;
    send_opt_p->msg_id = EMAIL_MSG_INVALID_ID;
    send_opt_p->move_to_sent = MMI_FALSE;

    cb_p->action = SRV_EMAIL_NWK_CLD_APPEND;
    cb_p->action_data = send_opt_p;

    srv_email_nwk_cloud_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_cloud_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


srv_email_result_enum srv_email_nwk_cloud_retrieve(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_cloud_retr_struct *nwk_retr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_nwk_cloud_retr_struct *retr_opt_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_RETRIEVE, handle, nwk_retr_p);

    if (!nwk_retr_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (nwk_retr_p->msg_part >= SRV_EMAIL_NWK_CLOUD_MSG_TOTAL)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action != SRV_EMAIL_NWK_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_IN_PROGRESS, handle, cb_p->action);
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    retr_opt_p = (srv_email_nwk_cloud_retr_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_cloud_retr_struct));
    if (!retr_opt_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memcpy(retr_opt_p, nwk_retr_p, sizeof(srv_email_nwk_cloud_retr_struct));

    if (nwk_retr_p->msg_part == SRV_EMAIL_NWK_CLOUD_MSG_ALL_UID)
    {
        cb_p->action = SRV_EMAIL_NWK_CLD_GET_UID;
    }
    else
    {
        cb_p->action = SRV_EMAIL_NWK_CLD_GET_MSG;
    }
    cb_p->action_data = retr_opt_p;

    srv_email_nwk_cloud_move_cb_to_pending(cntx_p, cb_p);

    retval = srv_email_nwk_cloud_run_cntx(cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
    }

    return retval;
}


srv_email_result_enum srv_email_nwk_cloud_abort(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_ABORT, handle);

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action == SRV_EMAIL_NWK_NONE)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    srv_email_nwk_cloud_abort_cb(cntx_p, cb_p);

    return SRV_EMAIL_RESULT_SUCC;
}


srv_email_result_enum srv_email_nwk_cloud_retry(EMAIL_NWK_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cb_struct *cb_p = (srv_email_nwk_cb_struct*)handle;
    srv_email_result_enum retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_RETRY, handle);

    cntx_p = srv_email_nwk_cloud_get_cntx_by_cb(cb_p);
    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_HANDLE_INVALID, handle);
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cb_p->action == SRV_EMAIL_NWK_NONE)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    retval = srv_email_nwk_cloud_fsm_retry(cntx_p);
    return retval;
}

#endif /* __SMS_CLOUD_SUPPORT__ */

#endif /* defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__) */

