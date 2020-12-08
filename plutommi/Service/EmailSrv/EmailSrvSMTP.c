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
 *  EmailSrvSMTP.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email SMTP functions.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvNetworkProt.h"
#include "EmailSrvSMTP.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "string.h"
#include "EmailSrvComposer.h"
#include "EmailSrvStorage.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "MMI_trc_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "customer_ps_inc.h"
#include "mmi_frm_mem_gprot.h"
#include "Unicodexdcl.h"
#include "fs_errcode.h"

static void srv_email_smtp_session_init(srv_email_smtp_session_struct *sess_p);
static void srv_email_smtp_session_free(srv_email_smtp_session_struct *sess_p);
static void srv_email_smtp_state_init(srv_email_smtp_state_struct *state_p);
static void srv_email_smtp_state_free(srv_email_smtp_state_struct *state_p);

static void srv_email_smtp_add_record(srv_email_smtp_list_struct *list_p, srv_email_smtp_item_struct *record_p);
static srv_email_smtp_item_struct *srv_email_smtp_get_record(srv_email_smtp_list_struct *list_p, EMAIL_MSG_ID msg_id);
static void srv_email_smtp_remvoe_record(srv_email_smtp_list_struct *list_p, srv_email_smtp_item_struct *record_p);
static void srv_email_smtp_load_local_msg(void *user_data);
static void srv_email_smtp_compose_done(MMI_BOOL ret, S32 major, S32 minor, U32 size, void *user_data);

static S32 srv_email_smtp_write_rcpt_addr(FS_HANDLE fd, CHAR *rcpt_addr_p);
static srv_email_result_enum srv_email_smtp_compose_mail(srv_email_smtp_cntx_struct *cntx_p, MMI_BOOL first);

static srv_email_result_enum srv_email_smtp_send_fsm_init(srv_email_smtp_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_smtp_send_fsm_listed(srv_email_smtp_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_smtp_send_fsm_composed(srv_email_smtp_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_smtp_send_fsm_sent(srv_email_smtp_cntx_struct *cntx_p);
static void srv_email_smtp_send_fsm_done(srv_email_smtp_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_smtp_send_mail_fail(srv_email_smtp_cntx_struct *cntx_p);

static void srv_email_smtp_send_fsm_start_job(void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_session_init
 * DESCRIPTION
 *  This function is used to initialize the SMTP session.
 * PARAMETERS
 *  sess_p          [IN]        The pointer point to the session
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_session_init(srv_email_smtp_session_struct *sess_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(sess_p, 0, sizeof(srv_email_smtp_session_struct));

    sess_p->msg_handle = EMAIL_MSG_INVALID_HANDLE;
    sess_p->msg_id = EMAIL_MSG_INVALID_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_session_free
 * DESCRIPTION
 *  This function is used to free the SMTP session.
 * PARAMETERS
 *  sess_p          [IN]        The pointer point to the session
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_session_free(srv_email_smtp_session_struct *sess_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_item_struct *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = sess_p->list.record;
    while (ptr)
    {
        sess_p->list.record = ptr->next;
        srv_email_mem_free(ptr);
        ptr = sess_p->list.record;
    }

    srv_email_smtp_session_init(sess_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_state_init
 * DESCRIPTION
 *  This function is used to initialize the SMTP state.
 * PARAMETERS
 *  state_p         [IN]        The pointer point to the state structure
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_state_init(srv_email_smtp_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(state_p, 0, sizeof(srv_email_smtp_state_struct));
    
    state_p->comp_handle = SRV_EMAIL_COMP_INVALID_HANDLE;
    state_p->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    state_p->last_msg_id = EMAIL_MSG_INVALID_ID;

    kal_wsprintf(
        state_p->rcpt_filename,
        "%s%sRcpt%08X.dat",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        state_p);

    kal_wsprintf(
        state_p->msg_filename,
        "%s%sMsg%08X.eml",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        state_p);

    state_p->dst_msg_id = EMAIL_MSG_INVALID_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_state_free
 * DESCRIPTION
 *  This function is used to free the SMTP state.
 * PARAMETERS
 *  state_p         [IN]        The pointer point to the state structure
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_state_free(srv_email_smtp_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state_p->comp_handle != SRV_EMAIL_COMP_INVALID_HANDLE)
    {
        srv_email_comp_destroy(state_p->comp_handle);
    }

    if (state_p->stor_handle != EMAIL_STOR_INVALID_HANDLE)
    {
        srv_email_stor_fldr_sync_msg_close(&state_p->stor_handle);
    }

    FS_Delete((const WCHAR*)state_p->rcpt_filename);
    FS_Delete((const WCHAR*)state_p->msg_filename);

    srv_email_smtp_state_init(state_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_add_record
 * DESCRIPTION
 *  This function is used to insert a record into the list by the email time.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  record_p        [IN]        The pointer point to the record
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_add_record(
                srv_email_smtp_list_struct *list_p,
                srv_email_smtp_item_struct *record_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_item_struct *curr_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record_p->next = NULL;

    if (!list_p->record)
    {
        list_p->record = record_p;
    }
    else if (list_p->record->msg_time > record_p->msg_time)
    {
        record_p->next = list_p->record;
        list_p->record = record_p;
    }
    else
    {
        curr_p = list_p->record;
        while (curr_p->next)
        {
            if (curr_p->next->msg_time > record_p->msg_time)
            {
                break;
            }
            curr_p = curr_p->next;
        }

        record_p->next = curr_p->next;
        curr_p->next = record_p;
    }

    list_p->record_num++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_get_record
 * DESCRIPTION
 *  This function is used to get the record by the msg id.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  msg_id          [IN]        The msg id
 * RETURNS
 *  The pointer point to the record.
 *****************************************************************************/
static srv_email_smtp_item_struct *srv_email_smtp_get_record(
                                    srv_email_smtp_list_struct *list_p,
                                    EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_item_struct *curr_p = list_p->record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr_p)
    {
        if (curr_p->msg_id == msg_id)
        {
            return curr_p;
        }

        curr_p = curr_p->next;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_remvoe_record
 * DESCRIPTION
 *  This function is used to remove the record.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  record_p        [IN]        The pointer point to the record
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_remvoe_record(
                srv_email_smtp_list_struct *list_p,
                srv_email_smtp_item_struct *record_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_item_struct *curr_p = list_p->record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_p == list_p->record)
    {
        list_p->record = record_p->next;
    }
    else
    {
        while (curr_p)
        {
            if (curr_p->next == record_p)
            {
                curr_p->next = record_p->next;
                break;
            }

            curr_p = curr_p->next;
        }
    }

    srv_email_mem_free(record_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_load_local_msg
 * DESCRIPTION
 *  This function is used to load the local emails continuously.
 * PARAMETERS
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_load_local_msg(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_cntx_struct *cntx_p = (srv_email_smtp_cntx_struct*)user_data;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_SMTP_LOAD_LOCAL_MSG, cntx_p);

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->common.schdl_flag)
    {
        cntx_p->common.schdl_flag = MMI_FALSE;

        if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING ||
            cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SEND_LIST)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                cntx_p->nwk_state,
                cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_SENDING,
                SRV_EMAIL_NWK_SUB_STATE_SEND_LIST);
            return;
        }

        srv_email_smtp_send_fsm(cntx_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_compose_done
 * DESCRIPTION
 *  This function is used to process the result of composing email.
 * PARAMETERS
 *  ret             [IN]        The result of composing
 *  major           [IN]        The major error when composing unsuccessfully
 *  minor           [IN]        The minor error when composing unsuccessfully
 *  size            [IN]        The size of the email
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_compose_done(MMI_BOOL ret, S32 major, S32 minor, U32 size, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_cntx_struct *cntx_p = (srv_email_smtp_cntx_struct*)user_data;
    srv_email_result_struct *result_p = NULL;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_SMTP_COMPOSE_MSG_DONE, cntx_p, ret, major, minor);

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_SENDING,
            SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE);
        return;
    }

    result_p = &cntx_p->common.result;

    result_p->result = ret;
    result_p->major = major;
    result_p->minor = minor;

    srv_email_smtp_send_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_write_rcpt_addr
 * DESCRIPTION
 *  This function is used to write the recipient email address into file.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  rcpt_addr_p     [IN]        The pointer point to the recipient address
 * RETURNS
 *  The error code.
 *****************************************************************************/
static S32 srv_email_smtp_write_rcpt_addr(FS_HANDLE fd, CHAR *rcpt_addr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 len = 0;
    U32 wbyte = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(rcpt_addr_p);

    ret = FS_Write(fd, &len, 4, &wbyte);
    if (ret < 0 || wbyte != 4)
    {
        return ret;
    }

    ret = FS_Write(fd, rcpt_addr_p, len, &wbyte);
    if (ret < 0 || wbyte != len)
    {
        return ret;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_compose_mail
 * DESCRIPTION
 *  This function is used to compose the mail.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 *  first           [IN]        If the first composing
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_smtp_compose_mail(
                                srv_email_smtp_cntx_struct *cntx_p,
                                MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_session_struct *sess_p = &cntx_p->session;
    srv_email_smtp_state_struct *state_p = &cntx_p->state;
    srv_email_msg_get_basic_info_struct *basic_info_p = NULL;
    srv_email_msg_get_recipient_struct *get_rcpt_p = NULL;
    srv_email_stor_msg_get_header_struct *msg_header_p = NULL;
    srv_email_addr_type_enum addr_type = SRV_EMAIL_ADDR_TYPE_TO;
    EMAIL_STOR_HANDLE handle = EMAIL_STOR_INVALID_HANDLE;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    CHAR *asc_addr_p = NULL;
    FS_HANDLE fd = -1;
    U32 wbyte = 0;
    U32 total_addr_num = 0;
    U32 to_addr_num = 0;
    U32 cc_addr_num = 0;
    U32 bcc_addr_num = 0;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    U32 i = 0;
    U32 j = 0;
    CHAR *disp_name_p = NULL;
    MMI_BOOL valid = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_SMTP_COMPOSE_MSG, cntx_p, first);

    fd = FS_Open((const WCHAR*)state_p->rcpt_filename, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (fd < 0)
    {
        minor = fd;
        goto ERROR_HANDLE;
    }

    asc_addr_p = (CHAR*)OslMalloc(SRV_EMAIL_MAX_ADDR_LEN + 1);

    if (first)
    {
        if (sess_p->send_msg_handle)
        {
            basic_info_p = (srv_email_msg_get_basic_info_struct*)
                OslMalloc(sizeof(srv_email_msg_get_basic_info_struct));

            retval = srv_email_msg_get_basic_info(sess_p->msg_handle, basic_info_p);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_GET_BASIC_FLDR_INFO, cntx_p, retval);

                srv_email_get_msg_error(retval, &major, &minor);
                goto ERROR_HANDLE;
            }

            to_addr_num = basic_info_p->to_addr_num;
            cc_addr_num = basic_info_p->cc_addr_num;
            bcc_addr_num = basic_info_p->bcc_addr_num;

            OslMfree(basic_info_p);
            basic_info_p = NULL;

            total_addr_num = to_addr_num + cc_addr_num + bcc_addr_num;

            minor = FS_Write(fd, &total_addr_num, 4, &wbyte);
            if (minor < 0 || wbyte != 4)
            {
                goto ERROR_HANDLE;
            }

            get_rcpt_p = (srv_email_msg_get_recipient_struct*)
                OslMalloc(sizeof(srv_email_msg_get_recipient_struct) + sizeof(srv_email_addr_struct));

            get_rcpt_p->addr_list = (srv_email_addr_struct*)
                ((U8*)get_rcpt_p + sizeof(srv_email_msg_get_recipient_struct));
            get_rcpt_p->number = 1;

            for (i = 0; i < 3; i++)
            {
                switch (i)
                {
                    case 0:
                        get_rcpt_p->type = SRV_EMAIL_ADDR_TYPE_TO;
                        total_addr_num = to_addr_num;
                	    break;

                    case 1:
                        get_rcpt_p->type = SRV_EMAIL_ADDR_TYPE_CC;
                        total_addr_num = cc_addr_num;
                	    break;

                    case 2:
                        get_rcpt_p->type = SRV_EMAIL_ADDR_TYPE_BCC;
                        total_addr_num = bcc_addr_num;
                        break;

                    default:
                        EMAILSRV_EXT_ASSERT(0, i, 0, 0);
                        break;
                }

                for (j = 0; j < total_addr_num; j++)
                {
                    get_rcpt_p->start_index = j;

                    retval = srv_email_msg_get_recipient(sess_p->msg_handle, get_rcpt_p);
                    if (retval != SRV_EMAIL_RESULT_SUCC)
                    {
                        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_MSG_GET_RCPT, cntx_p, retval);

                        srv_email_get_msg_error(retval, &major, &minor);
                        goto ERROR_HANDLE;
                    }

                    mmi_ucs2_to_asc(asc_addr_p, (CHAR*)get_rcpt_p->addr_list->email_addr);

                    minor = srv_email_smtp_write_rcpt_addr(fd, asc_addr_p);
                    if (minor < 0)
                    {
                        goto ERROR_HANDLE;
                    }
                }
            }

            OslMfree(get_rcpt_p);
            get_rcpt_p = NULL;

            OslMfree(asc_addr_p);
            asc_addr_p = NULL;

            FS_Close(fd);
            fd = -1;

            retval = srv_email_comp_start_by_msg_handle(
                        state_p->comp_handle,
                        sess_p->msg_handle,
                        MMI_FALSE,
                        state_p->msg_filename,
                        srv_email_smtp_compose_done,
                        cntx_p);

            if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_COMPOSE_BY_MSG_HANDLE, cntx_p, retval);

                srv_email_get_compose_error(retval, &major, &minor);
                goto ERROR_HANDLE;
            }

            return retval;
        }
        else
        {
            sess_p->list.curr_record = sess_p->list.record;
            EMAILSRV_ASSERT(sess_p->list.curr_record);

            sess_p->msg_id = sess_p->list.curr_record->msg_id;
        }
    }
    else
    {
        sess_p->list.curr_record = sess_p->list.curr_record->next;
        EMAILSRV_ASSERT(sess_p->list.curr_record);

        sess_p->msg_id = sess_p->list.curr_record->msg_id;
    }

    retval = srv_email_stor_msg_id_valid_ext(sess_p->msg_id, MMI_TRUE, &valid);

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_stor_error(retval, &major, &minor);
        goto ERROR_HANDLE;
    }

    if (!valid)
    {
        major = SRV_EMAIL_FS_ERROR;
        minor = FS_FILE_NOT_FOUND;
        goto ERROR_HANDLE;
    }

    msg_header_p = (srv_email_stor_msg_get_header_struct*)
        OslMalloc(sizeof(srv_email_stor_msg_get_header_struct));

    retval = srv_email_stor_msg_get_header(sess_p->msg_id, msg_header_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_STOR_GET_MSG_HEADER, cntx_p, retval);

        srv_email_get_stor_error(retval, &major, &minor);
        goto ERROR_HANDLE;
    }

    to_addr_num = msg_header_p->addr_to_num;
    cc_addr_num = msg_header_p->addr_cc_num;
    bcc_addr_num = msg_header_p->addr_bcc_num;

    OslMfree(msg_header_p);
    msg_header_p = NULL;

    total_addr_num = to_addr_num + cc_addr_num + bcc_addr_num;

    minor = FS_Write(fd, &total_addr_num, 4, &wbyte);
    if (minor < 0 || wbyte != 4)
    {
        goto ERROR_HANDLE;
    }

    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
            case 0:
                addr_type = SRV_EMAIL_ADDR_TYPE_TO;
                total_addr_num = to_addr_num;
                break;

            case 1:
                addr_type = SRV_EMAIL_ADDR_TYPE_CC;
                total_addr_num = cc_addr_num;
                break;

            case 2:
                addr_type = SRV_EMAIL_ADDR_TYPE_BCC;
                total_addr_num = bcc_addr_num;
                break;

            default:
                EMAILSRV_EXT_ASSERT(0, i, 0, 0);
                break;
        }

        if (total_addr_num > 0)
        {
            retval = srv_email_stor_msg_get_addr_open(sess_p->msg_id, 0, addr_type, &handle);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_STOR_GET_MSG_ADDR_OPEN, cntx_p, retval);

                srv_email_get_stor_error(retval, &major, &minor);
                goto ERROR_HANDLE;
            }

            disp_name_p = (CHAR*)OslMalloc(EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1);

            for (j = 0; j < total_addr_num; j++)
            {
                retval = srv_email_stor_msg_get_addr_next(
                            handle,
                            EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1,
                            SRV_EMAIL_MAX_ADDR_LEN + 1,
                            disp_name_p,
                            asc_addr_p);

                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_STOR_GET_MSG_ADDR_NEXT, cntx_p, retval);

                    srv_email_get_stor_error(retval, &major, &minor);
                    goto ERROR_HANDLE;
                }

                minor = srv_email_smtp_write_rcpt_addr(fd, asc_addr_p);
                if (minor < 0)
                {
                    goto ERROR_HANDLE;
                }
            }

            OslMfree(disp_name_p);
            disp_name_p = NULL;

            srv_email_stor_msg_get_addr_close(handle);
            handle = EMAIL_STOR_INVALID_HANDLE;
        }
    }

    OslMfree(asc_addr_p);
    asc_addr_p = NULL;

    FS_Close(fd);
    fd = -1;

    retval = srv_email_comp_start_by_msg_id(
                state_p->comp_handle,
                sess_p->msg_id,
                MMI_FALSE,
                state_p->msg_filename,
                srv_email_smtp_compose_done,
                cntx_p);

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_COMPOSE_BY_MSG_ID, cntx_p, retval);

        srv_email_get_compose_error(retval, &major, &minor);
        goto ERROR_HANDLE;
    }
    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_SMTP_COMPOSE_MSG, cntx_p, retval);

    return retval;

ERROR_HANDLE:

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_COMPOSE_MSG, cntx_p, major, minor);

    if (disp_name_p)
    {
        OslMfree(disp_name_p);
    }

    if (basic_info_p)
    {
        OslMfree(basic_info_p);
    }

    if (get_rcpt_p)
    {
        OslMfree(get_rcpt_p);
    }

    if (msg_header_p)
    {
        OslMfree(msg_header_p);
    }

    if (asc_addr_p)
    {
        OslMfree(asc_addr_p);
    }

    if (handle != EMAIL_STOR_INVALID_HANDLE)
    {
        srv_email_stor_msg_get_addr_close(handle);
    }

    if (fd >= 0)
    {
        FS_Close(fd);
    }
    FS_Delete((const WCHAR*)state_p->rcpt_filename);

    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_fsm_init
 * DESCRIPTION
 *  This function is used to initialize the SMTP send FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_smtp_send_fsm_init(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_session_struct *sess_p = &cntx_p->session;
    srv_email_stor_fldr_struct *fldr_info_p = NULL;
    srv_email_smtp_item_struct *record_p = NULL;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_SMTP_SEND_FSM_INIT,
        cntx_p,
        sess_p->send_outbox,
        sess_p->send_msg_handle,
        sess_p->send_msg_id);

    if (sess_p->send_outbox)
    {
        fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_OUTBOX);

        fldr_info_p = (srv_email_stor_fldr_struct*)OslMalloc(sizeof(srv_email_stor_fldr_struct));

        retval = srv_email_stor_fldr_get_by_id(comm_p->acct_id, fldr_id, fldr_info_p);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_GET_FLDR_INFO, cntx_p, fldr_id, retval);

            OslMfree(fldr_info_p);
            srv_email_get_stor_error(retval, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
            return SRV_EMAIL_RESULT_FAIL;
        }

        sess_p->total_count = fldr_info_p->total_count;

        OslMfree(fldr_info_p);

        if (sess_p->total_count == 0)
        {
            srv_email_set_error_cause(
                &comm_p->result,
                SRV_EMAIL_MAIL_ERROR,
                SRV_EMAIL_RESULT_FLDR_EMPTY,
                NULL);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }
    else
    {
        sess_p->total_count = 1;
        sess_p->curr_count = 1;

        if (sess_p->send_msg_id)
        {
            record_p = (srv_email_smtp_item_struct*)
                srv_email_mem_alloc(sizeof(srv_email_smtp_item_struct));

            if (!record_p)
            {
                srv_email_set_error_cause(
                    &comm_p->result,
                    SRV_EMAIL_MAIL_ERROR,
                    SRV_EMAIL_RESULT_NO_MEMORY,
                    NULL);
                return SRV_EMAIL_RESULT_FAIL;
            }

            memset(record_p, 0, sizeof(srv_email_smtp_item_struct));

            record_p->msg_id = sess_p->msg_id;

            srv_email_smtp_add_record(&sess_p->list, record_p);
        }
    }

    SRV_EMAIL_SMTP_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_LIST);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_fsm_listed
 * DESCRIPTION
 *  This function is used to process the result of listing local emails. 
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_smtp_send_fsm_listed(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_session_struct *sess_p = &cntx_p->session;
    srv_email_smtp_state_struct *state_p = &cntx_p->state;
    srv_email_stor_fldr_get_msg_id_struct *msg_header_p = NULL;
    srv_email_smtp_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    srv_email_sending_data_struct send_data;
    S32 major = 0;
    S32 minor = 0;
    S32 i = 0;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;
    EMAIL_STOR_HANDLE stor_handle = EMAIL_STOR_INVALID_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_STMP_SEND_FSM_LISTED,
        cntx_p,
        sess_p->curr_count,
        sess_p->total_count);

    if (sess_p->curr_count < sess_p->total_count)
    {
        fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_OUTBOX);

        if (sess_p->curr_count)
        {
            retval = srv_email_stor_fldr_sync_msg_open_ext(
                        comm_p->acct_id,
                        fldr_id,
                        &stor_handle,
                        state_p->last_msg_id);
        }
        else
        {
            retval = srv_email_stor_fldr_sync_msg_open(comm_p->acct_id, fldr_id, &stor_handle);
        }

        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_STOR_GET_MSG_OPEN, cntx_p, retval);

            srv_email_get_stor_error(retval, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
            return SRV_EMAIL_RESULT_FAIL;
        }

        state_p->stor_handle = stor_handle;

        msg_header_p = (srv_email_stor_fldr_get_msg_id_struct*)
            OslMalloc(sizeof(srv_email_stor_fldr_get_msg_id_struct));

        memset(msg_header_p, 0, sizeof(srv_email_stor_fldr_get_msg_id_struct));

        for (i = 0; i < SRV_EMAIL_SMTP_LIST_NUM_PER_TIME; i++)
        {
            retval = srv_email_stor_fldr_sync_msg_get_next(state_p->stor_handle, msg_header_p);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                record_p = (srv_email_smtp_item_struct*)
                    srv_email_mem_alloc(sizeof(srv_email_smtp_item_struct));

                if (!record_p)
                {
                    OslMfree(msg_header_p);
                    srv_email_set_error_cause(
                        &comm_p->result,
                        SRV_EMAIL_MAIL_ERROR,
                        SRV_EMAIL_RESULT_NO_MEMORY,
                        NULL);
                    return SRV_EMAIL_RESULT_FAIL;
                }

                memset(record_p, 0, sizeof(srv_email_smtp_item_struct));

                record_p->msg_id = msg_header_p->msg_id;
                record_p->msg_time = msg_header_p->created_date;

                srv_email_smtp_add_record(&sess_p->list, record_p);

                sess_p->curr_count++;
                state_p->last_msg_id = msg_header_p->msg_id;
            }
            else if (retval == SRV_EMAIL_RESULT_NO_MORE_RESULT)
            {
                EMAILSRV_EXT_ASSERT(
                    sess_p->curr_count == sess_p->total_count,
                    sess_p->total_count,
                    sess_p->curr_count,
                    0);
                break;
            }
            else
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_ERROR_SMTP_STOR_GET_MSG_NEXT,
                    cntx_p,
                    retval,
                    sess_p->curr_count);

                OslMfree(msg_header_p);
                srv_email_get_stor_error(retval, &major, &minor);
                srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
                return SRV_EMAIL_RESULT_FAIL;
            }
        }

        OslMfree(msg_header_p);

        srv_email_stor_fldr_sync_msg_close(&state_p->stor_handle);
        state_p->stor_handle = EMAIL_STOR_INVALID_HANDLE;

        if (sess_p->curr_count < sess_p->total_count)
        {
            srv_email_nwk_start_job(srv_email_smtp_load_local_msg, (srv_email_nwk_cntx_struct*)cntx_p);
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
    }

    state_p->total_count = sess_p->total_count;

    send_data.total_num = state_p->total_count;
    send_data.sent_num = state_p->sent_count;
    send_data.fail_num = state_p->fail_count;
    send_data.total_size = 0;
    send_data.sent_size = 0;
    if (!sess_p->send_msg_handle)
    {
        send_data.msg_id = sess_p->list.record->msg_id;
    }
    else
    {
        send_data.msg_id = srv_email_msg_get_id(sess_p->msg_handle);
    }
    send_data.result = MMI_FALSE;
    srv_email_nwk_cb_process_notify(
        (srv_email_nwk_cntx_struct*)cntx_p,
        NULL,
        SRV_EMAIL_NWK_SENDING,
        &send_data);

    sess_p->curr_count = 0;

    retval = srv_email_comp_create(&state_p->comp_handle);

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_COMP_CREATE_HANDLE, cntx_p, retval);

        srv_email_get_compose_error(retval, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return retval;
    }

    retval = srv_email_smtp_compose_mail(cntx_p, MMI_TRUE);

    //if (retval == SRV_EMAIL_RESULT_SUCC || retval == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        SRV_EMAIL_SMTP_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_fsm_composed
 * DESCRIPTION
 *  This function is used to process the result of composing email.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_smtp_send_fsm_composed(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_SMTP_SEND_FSM_COMPOSED, cntx_p);

    srv_email_ps_send_mail_req(
        comm_p->ps_handle,
        (const CHAR*)state_p->from_addr,
        (const WCHAR*)state_p->rcpt_filename,
        (const WCHAR*)state_p->msg_filename);

    SRV_EMAIL_SMTP_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_SEND);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_fsm_sent
 * DESCRIPTION
 *  This function is used to process the result of sending email.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_smtp_send_fsm_sent(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_session_struct *sess_p = &cntx_p->session;
    srv_email_smtp_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;
    EMAIL_STOR_HANDLE stor_handle = EMAIL_STOR_INVALID_HANDLE;
    srv_email_sending_data_struct send_data;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_SMTP_SEND_FSM_SENT, cntx_p);

    if (!sess_p->send_msg_handle)
    {
        if (sess_p->send_outbox)
        {
            sess_p->list.curr_record->is_sent = MMI_TRUE;
        }

        if (sess_p->move_to_sent)
        {
            fldr_id = srv_email_stor_fldr_get_id_by_type(
                        comm_p->acct_id,
                        SRV_EMAIL_FLDR_TYPE_SENT);

            retval = srv_email_stor_msg_move(
                        sess_p->msg_id,
                        comm_p->acct_id,
                        fldr_id,
                        &state_p->dst_msg_id);

            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_STOR_MOVE_MSG, cntx_p, retval);

                srv_email_get_stor_error(retval, &major, &minor);
            }
        }
        else
        {
            fldr_id = srv_email_stor_fldr_get_id_by_type(
                        comm_p->acct_id,
                        SRV_EMAIL_FLDR_TYPE_OUTBOX);

            retval = srv_email_stor_fldr_del_msg_open(
                        SRV_EMAIL_FLDR_TYPE_OUTBOX,
                        comm_p->acct_id,
                        fldr_id,
                        MMI_TRUE,
                        MMI_FALSE,
                        &stor_handle);

            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                retval = srv_email_stor_fldr_del_msg_next(stor_handle, sess_p->msg_id);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_STOR_DEL_MSG_NEXT, cntx_p, retval);

                    srv_email_get_stor_error(retval, &major, &minor);
                }

                srv_email_stor_fldr_del_msg_close(stor_handle);
            }
            else
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_STOR_DEL_MSG_OPEN, cntx_p, retval);

                srv_email_get_stor_error(retval, &major, &minor);
            }
        }

        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
            return SRV_EMAIL_RESULT_FAIL;
        }

        state_p->sent_count++;

        send_data.total_num = state_p->total_count;
        send_data.sent_num = state_p->sent_count;
        send_data.fail_num = state_p->fail_count;
        send_data.total_size = 0;
        send_data.sent_size = 0;
        send_data.msg_id =
            sess_p->list.curr_record->next ?
            sess_p->list.curr_record->next->msg_id :
            EMAIL_MSG_INVALID_ID;
        send_data.result = MMI_TRUE;
        srv_email_nwk_cb_process_notify(
            (srv_email_nwk_cntx_struct*)cntx_p,
            NULL,
            SRV_EMAIL_NWK_SENDING,
            &send_data);
    }

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        sess_p->curr_count++;

        if (sess_p->curr_count < sess_p->total_count)
        {
            retval = srv_email_smtp_compose_mail(cntx_p, MMI_FALSE);

            //if (retval == SRV_EMAIL_RESULT_SUCC || retval == SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                SRV_EMAIL_SMTP_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE);
            }
        }
        else
        {
            SRV_EMAIL_SMTP_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_DONE);
        }
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_fsm_done
 * DESCRIPTION
 *  This function is used to process the result of sending finish.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_send_fsm_done(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_session_struct *sess_p = &cntx_p->session;
    srv_email_smtp_state_struct *state_p = &cntx_p->state;
    srv_email_result_struct *result_p = &cntx_p->common.result;
    srv_email_send_done_data_struct send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state_p->major)
    {
        result_p->result = MMI_FALSE;
        result_p->major = state_p->major;
        result_p->minor = state_p->minor;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_SMTP_SEND_FSM_DONE,
        cntx_p,
        cntx_p->callback,
        result_p->result,
        result_p->major,
        result_p->minor);

    if (sess_p->send_outbox)
    {
        send_data.total_num = state_p->total_count;
        send_data.sent_num = state_p->sent_count;
        send_data.fail_num = state_p->fail_count;
        send_data.result = state_p->major ? MMI_FALSE : MMI_TRUE;
        send_data.major = state_p->major;
        send_data.minor = state_p->minor;
        srv_email_nwk_cb_process_notify(
            (srv_email_nwk_cntx_struct*)cntx_p,
            NULL,
            SRV_EMAIL_NWK_SEND_DONE,
            &send_data);
    }

    srv_email_smtp_session_free(&cntx_p->session);
    srv_email_smtp_state_free(&cntx_p->state);

    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_mail_fail
 * DESCRIPTION
 *  This function is used to process the case that sending email unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_smtp_send_mail_fail(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_session_struct *sess_p = &cntx_p->session;
    srv_email_smtp_state_struct *state_p = &cntx_p->state;
    srv_email_result_struct *result_p = &comm_p->result;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    srv_email_sending_data_struct send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //trace: send fail

    if (sess_p->send_outbox)
    {
        if (!state_p->major)
        {
            state_p->major = result_p->major;
            state_p->minor = result_p->minor;
        }
        result_p->result = MMI_TRUE;

        sess_p->list.curr_record->is_sent = MMI_TRUE;

        state_p->fail_count++;

        send_data.total_num = state_p->total_count;
        send_data.sent_num = state_p->sent_count;
        send_data.fail_num = state_p->fail_count;
        send_data.total_size = 0;
        send_data.sent_size = 0;
        send_data.msg_id =
            sess_p->list.curr_record->next ?
            sess_p->list.curr_record->next->msg_id :
            EMAIL_MSG_INVALID_ID;
        send_data.result = MMI_FALSE;
        srv_email_nwk_cb_process_notify(
            (srv_email_nwk_cntx_struct*)cntx_p,
            NULL,
            SRV_EMAIL_NWK_SENDING,
            &send_data);
    }

    sess_p->curr_count++;

    if (sess_p->curr_count < sess_p->total_count)
    {
        retval = srv_email_smtp_compose_mail(cntx_p, MMI_FALSE);

        //if (retval == SRV_EMAIL_RESULT_SUCC || retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            SRV_EMAIL_SMTP_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE);
        }

        if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            srv_email_nwk_start_job(srv_email_smtp_send_fsm_start_job, (srv_email_nwk_cntx_struct*)cntx_p);
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
    }
    else
    {
        SRV_EMAIL_SMTP_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_DONE);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_fsm_start_job
 * DESCRIPTION
 *  This function is used to re-schedule the SMTP SEND FSM.
 * PARAMETERS
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_smtp_send_fsm_start_job(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_cntx_struct *cntx_p = (srv_email_smtp_cntx_struct*)user_data;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->common.schdl_flag)
    {
        cntx_p->common.schdl_flag = MMI_FALSE;

        if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                cntx_p->nwk_state,
                cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_SENDING,
                0);
            return;
        }

        srv_email_smtp_send_fsm(cntx_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_cntx_init
 * DESCRIPTION
 *  This function is used to initialize the SMTP context.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_smtp_cntx_init(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(cntx_p, 0, sizeof(srv_email_smtp_cntx_struct));
    cntx_p->common.result.result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_cntx_free
 * DESCRIPTION
 *  This function is used to free the SMTP context.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_smtp_cntx_free(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_smtp_session_free(&cntx_p->session);
    srv_email_smtp_state_free(&cntx_p->state);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send
 * DESCRIPTION
 *  This function is used to send emails.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 *  send_p          [IN]        The pointer point to the sending parameter
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code
 *****************************************************************************/
srv_email_result_enum srv_email_smtp_send(
                        srv_email_smtp_cntx_struct *cntx_p,
                        srv_email_nwk_send_struct *send_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_session_struct *sess_p = &cntx_p->session;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL valid = MMI_TRUE;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_OPERATION;
        goto ERROR_HANDLE;
    }

    srv_email_smtp_session_init(sess_p);
    srv_email_smtp_state_init(&cntx_p->state);

    strcpy(cntx_p->state.from_addr, cntx_p->common.from_addr);
    sess_p->move_to_sent = send_p->move_to_sent;
    sess_p->send_outbox = send_p->send_outbox;
    sess_p->msg_handle = send_p->msg_handle;
    sess_p->msg_id = send_p->msg_id;

    if (!sess_p->send_outbox)
    {
        if (sess_p->msg_handle != EMAIL_MSG_INVALID_HANDLE)
        {
            sess_p->send_msg_handle = MMI_TRUE;
        }
        else
        {
            retval = srv_email_stor_msg_id_valid_ext(sess_p->msg_id, MMI_TRUE, &valid);

            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_get_stor_error(retval, &major, &minor);
                goto ERROR_HANDLE;
            }

            if (!valid)
            {
                major = SRV_EMAIL_FS_ERROR;
                minor = FS_FILE_NOT_FOUND;
                goto ERROR_HANDLE;
            }

            sess_p->send_msg_id = MMI_TRUE;
        }
    }

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    SRV_EMAIL_SMTP_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_INIT);

    retval = srv_email_smtp_send_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_fsm
 * DESCRIPTION
 *  This function is used to run the SMTP SEND FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_smtp_send_fsm(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    srv_email_result_struct *result_p = &cntx_p->common.result;
    MMI_BOOL run_fsm = result_p->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (run_fsm)
    {
        switch (cntx_p->sub_state)
        {
            case SRV_EMAIL_NWK_SUB_STATE_SEND_INIT:
                retval = srv_email_smtp_send_fsm_init(cntx_p);
        	    break;

            case SRV_EMAIL_NWK_SUB_STATE_SEND_LIST:
                retval = srv_email_smtp_send_fsm_listed(cntx_p);
        	    break;

            case SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE:
                retval = srv_email_smtp_send_fsm_composed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_SEND_SEND:
                retval = srv_email_smtp_send_fsm_sent(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_SEND_DONE:
                run_fsm = MMI_FALSE;
        	    break;

            default:
                EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
                break;
        }

        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            run_fsm = MMI_FALSE;
        }
    }

    if (!result_p->result &&
        ((cntx_p->sub_state == SRV_EMAIL_NWK_SUB_STATE_SEND_SEND &&
          result_p->major == SRV_EMAIL_MAIL_ERROR &&
          (result_p->minor == SRV_EMAIL_RESULT_RECIPIENTS_ERROR ||
           result_p->minor == SRV_EMAIL_RESULT_SMTP_CMD_ERROR)) ||
         (cntx_p->sub_state == SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE &&
          result_p->major == SRV_EMAIL_FS_ERROR &&
          result_p->minor == FS_FILE_NOT_FOUND)))
    {
        retval = srv_email_smtp_send_mail_fail(cntx_p);
    }

    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK &&
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SEND_INIT)
    {
        srv_email_smtp_send_fsm_done(cntx_p);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_send_abort
 * DESCRIPTION
 *  This function is used to stop the SMTP SEND FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_smtp_send_abort(srv_email_smtp_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_SMTP_SEND_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_SEND_LIST:
            srv_email_nwk_stop_job((srv_email_nwk_cntx_struct*)cntx_p);
    	    break;

        case SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE:
            srv_email_nwk_stop_job((srv_email_nwk_cntx_struct*)cntx_p);
            srv_email_comp_stop(state_p->comp_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_SEND_SEND:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_SEND_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_SEND_DONE:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;

    srv_email_smtp_send_fsm_done(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_smtp_proc_om_notify
 * DESCRIPTION
 *  This function is used to process the Object Management notification.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the SMTP context
 *  notify_p        [IN]        The pointer point to the notification
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_smtp_proc_om_notify(
        srv_email_smtp_cntx_struct *cntx_p,
        srv_email_om_notify_struct *notify_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_smtp_session_struct *sess_p = &cntx_p->session;
    srv_email_smtp_state_struct *state_p = &cntx_p->state;
    srv_email_smtp_item_struct *record_p = NULL;
    srv_email_om_notify_msg_struct *msg_p = (srv_email_om_notify_msg_struct*)notify_p->data;
    EMAIL_FLDR_ID outbox_id = EMAIL_FLDR_INVALID_ID;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    outbox_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_OUTBOX);
    fldr_id = srv_email_stor_msg_id_to_fldr_id(msg_p->msg_id);
    if (fldr_id != outbox_id)
    {
        return;
    }

    if (!sess_p->send_outbox)
    {
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_SMTP_PROC_OM_NOTIFY,
        cntx_p,
        cntx_p->sub_state,
        notify_p->notify_type);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE:
        case SRV_EMAIL_NWK_SUB_STATE_SEND_SEND:
            switch (notify_p->notify_type)
            {
                case SRV_EMAIL_OM_NOTIFY_MSG_ADD:
                    record_p = (srv_email_smtp_item_struct*)
                        srv_email_mem_alloc(sizeof(srv_email_smtp_item_struct));
                    if (!record_p)
                    {
                        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_OM_ADD_MSG, cntx_p);
                        return;
                    }

                    memset(record_p, 0, sizeof(srv_email_smtp_item_struct));
                    record_p->msg_id = msg_p->msg_id;
                    record_p->msg_time = 0xFFFFFFFF;

                    srv_email_smtp_add_record(&sess_p->list, record_p);
                    state_p->total_count++;
                    sess_p->total_count++;
            	    break;

                case SRV_EMAIL_OM_NOTIFY_MSG_DEL:
                    record_p = srv_email_smtp_get_record(&sess_p->list, msg_p->msg_id);
                    if (!record_p)
                    {
                        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_SMTP_OM_DEL_MSG_GET_RECORD, cntx_p);
                        return;
                    }

                    if (record_p == sess_p->list.curr_record)
                    {
                        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_SMTP_OM_DEL_MSG_CURR_RECORD, cntx_p);
                        return;
                    }

                    if (!record_p->is_sent)
                    {
                        srv_email_smtp_remvoe_record(&sess_p->list, record_p);
                        state_p->total_count--;
                        sess_p->total_count--;
                    }
                    else
                    {
                        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_SMTP_OM_DEL_MSG_ALREADY_SENT, cntx_p);
                    }
                    break;

                default:
                    break;
            }
            break;

        case SRV_EMAIL_NWK_SUB_STATE_SEND_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_SEND_LIST:
        case SRV_EMAIL_NWK_SUB_STATE_SEND_DONE:
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }
}

#endif /* __MMI_EMAIL__ */

