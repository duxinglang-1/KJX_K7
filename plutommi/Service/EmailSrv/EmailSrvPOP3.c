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
 *  EmailSrvPOP3.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email POP3 functions.
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
#include "EmailSrvPOP3.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "EmailSrvStorage.h"
#include "string.h"
#include "kal_public_api.h"
#include "email_ps_public.h"
#include "fs_func.h"
#include "MMI_trc_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "mmi_frm_mem_gprot.h"

#define SRV_EMAIL_POP3_MAX_UIDL_LEN     (70)

static void srv_email_pop3_session_init(srv_email_pop3_session_struct *sess_p);
static void srv_email_pop3_session_free(srv_email_pop3_session_struct *sess_p);
static void srv_email_pop3_state_init(srv_email_pop3_state_struct *state_p);
static void srv_email_pop3_state_free(srv_email_pop3_state_struct *state_p);

static MMI_BOOL srv_email_pop3_add_record(
                    srv_email_pop3_list_struct *list_p,
                    srv_email_pop3_item_struct *record_p);
static srv_email_pop3_item_struct *srv_email_pop3_get_record_by_seqno(
                                    srv_email_pop3_list_struct *list_p,
                                    U32 seq_no);
static srv_email_pop3_item_struct *srv_email_pop3_get_record_by_uidl(
                                    srv_email_pop3_list_struct *list_p,
                                    U8 *uid_digest);
static srv_email_pop3_item_struct *srv_email_pop3_get_record_by_msgid(
                                    srv_email_pop3_list_struct *list_p,
                                    EMAIL_MSG_ID msg_id);
static srv_email_pop3_item_struct *srv_email_pop3_get_next_new_msg(
                                    srv_email_pop3_list_struct *list_p,
                                    srv_email_pop3_item_struct *curr_rec_p);
static U32 srv_email_pop3_calc_new_msg(srv_email_pop3_list_struct *list_p, U32 retrieve_amount);
static srv_email_result_enum srv_email_pop3_make_delete_req_file(
                                srv_email_pop3_cntx_struct *cntx_p,
                                U32 *msg_count);

static S32 srv_email_pop3_read_uid(FS_HANDLE fd, U32 *msg_seq_no, U8 *uid_digest);
static S32 srv_email_pop3_read_size(FS_HANDLE fd, U32 *msg_seq_no, U32 *msg_size);

static srv_email_result_enum srv_email_pop3_list_uid(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_list_size(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_match_msg(
                                srv_email_pop3_cntx_struct *cntx_p,
                                srv_email_stor_fldr_get_msg_id_struct *msg_info_p);

static void srv_email_pop3_load_local_msg(void *user_data);

static srv_email_result_enum srv_email_pop3_update_fsm_init(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_update_fsm_fldr_opened(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_update_fsm_uid_listed(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_update_fsm_size_listed(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_update_fsm_local_updated(srv_email_pop3_cntx_struct *cntx_p);
static void srv_email_pop3_update_fsm_done(srv_email_pop3_cntx_struct *cntx_p);

static void srv_email_pop3_parse_save_done(srv_email_result_struct *result_p, EMAIL_REQ_ID req_id, void *user_data);

static srv_email_result_enum srv_email_pop3_recv_fsm_init(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_recv_fsm_received(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_recv_fsm_parsed(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_recv_fsm_saved(srv_email_pop3_cntx_struct *cntx_p);
static void srv_email_pop3_recv_fsm_done(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_recv_mail_fail(srv_email_pop3_cntx_struct *cntx_p);

static srv_email_result_enum srv_email_pop3_disc_fsm_init(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_disc_fsm_server_deleted(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_disc_fsm_disconnected(srv_email_pop3_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_pop3_disc_fsm_local_deleted(srv_email_pop3_cntx_struct *cntx_p);
static void srv_email_pop3_disc_fsm_done(srv_email_pop3_cntx_struct *cntx_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_session_init
 * DESCRIPTION
 *  This function is used to initialize the POP3 session.
 * PARAMETERS
 *  sess_p          [IN]        The pointer point to the POP3 session
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_pop3_session_init(srv_email_pop3_session_struct *sess_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(sess_p, 0, sizeof(srv_email_pop3_session_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_session_free
 * DESCRIPTION
 *  This function is used to free the POP3 session.
 * PARAMETERS
 *  sess_p          [IN]        The pointer point to the POP3 session
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_pop3_session_free(srv_email_pop3_session_struct *sess_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_item_struct *ptr = NULL;

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

    srv_email_pop3_session_init(sess_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_state_init
 * DESCRIPTION
 *  This function is used to initialize the POP3 state.
 * PARAMETERS
 *  state_p         [IN]        The pointer point to the state structure
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_pop3_state_init(srv_email_pop3_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(state_p, 0, sizeof(srv_email_pop3_state_struct));

    state_p->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    state_p->last_msg_id = EMAIL_MSG_INVALID_ID;

    state_p->msg_handle = EMAIL_MSG_INVALID_HANDLE;
    state_p->req_id = EMAIL_REQ_INVALID_ID;

    kal_wsprintf(
        state_p->req_filename,
        "%s%sReq%08X.dat",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        state_p);

    kal_wsprintf(
        state_p->rsp_filename,
        "%s%sRsp%08X.dat",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        state_p);

    state_p->fetch_type = EMAIL_PS_FETCH_TYPE_HEADER;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_state_free
 * DESCRIPTION
 *  This function is used to free the POP3 state.
 * PARAMETERS
 *  state_p         [IN]        The pointer point to the state structure
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_pop3_state_free(srv_email_pop3_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state_p->stor_handle != EMAIL_STOR_INVALID_HANDLE)
    {
        srv_email_stor_fldr_sync_msg_close(&state_p->stor_handle);
    }

    if (state_p->msg_handle != EMAIL_MSG_INVALID_HANDLE)
    {
        if (state_p->req_id != EMAIL_REQ_INVALID_ID)
        {
            srv_email_msg_abort(state_p->msg_handle, state_p->req_id);
        }
        srv_email_msg_destroy(state_p->msg_handle);
    }

    FS_Delete((const WCHAR*)state_p->req_filename);
    FS_Delete((const WCHAR*)state_p->rsp_filename);

    srv_email_pop3_state_init(state_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_add_record
 * DESCRIPTION
 *  This function is used to insert a record into the list by the email sequence number.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  record_p        [IN]        The pointer point to the record
 * RETURNS
 *  MMI_TRUE/MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_email_pop3_add_record(
                    srv_email_pop3_list_struct *list_p,
                    srv_email_pop3_item_struct *record_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_item_struct *curr_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record_p->next = NULL;

    if (!list_p->record)
    {
        list_p->record = record_p;
    }
    else if (list_p->record->seq_no == record_p->seq_no)
    {
        return MMI_FALSE;
    }
    else if (list_p->record->seq_no < record_p->seq_no)
    {
        record_p->next = list_p->record;
        list_p->record = record_p;
    }
    else
    {
        curr_p = list_p->record;
        while (curr_p->next)
        {
            if (curr_p->next->seq_no == record_p->seq_no)
            {
                return MMI_FALSE;
            }
            else if (curr_p->next->seq_no < record_p->seq_no)
            {
                break;
            }
            curr_p = curr_p->next;
        }

        record_p->next = curr_p->next;
        curr_p->next = record_p;
    }

    list_p->record_num++;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_get_record_by_seqno
 * DESCRIPTION
 *  This function is used to get the record by the specified sequence number.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  seq_no          [IN]        The sequence number
 * RETURNS
 *  The pointer point to the record.
 *****************************************************************************/
static srv_email_pop3_item_struct *srv_email_pop3_get_record_by_seqno(
                                    srv_email_pop3_list_struct *list_p,
                                    U32 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_item_struct *curr_p = list_p->record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(seq_no > 0, seq_no, 0, 0);

    while (curr_p)
    {
        if (curr_p->seq_no == seq_no)
        {
            return curr_p;
        }

        curr_p = curr_p->next;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_get_record_by_uidl
 * DESCRIPTION
 *  This function is used to get the record by the specified uidl digest.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  uid_digest      [IN]        The uidl digest
 * RETURNS
 *  The pointer point to the record.
 *****************************************************************************/
static srv_email_pop3_item_struct *srv_email_pop3_get_record_by_uidl(
                                    srv_email_pop3_list_struct *list_p,
                                    U8 *uid_digest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_item_struct *curr_p = list_p->record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_ASSERT(uid_digest);

    while (curr_p)
    {
        if (!memcmp(curr_p->uid_digest, uid_digest, SRV_EMAIL_MD5_DIGEST_LEN))
        {
            return curr_p;
        }

        curr_p = curr_p->next;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_get_record_by_msgid
 * DESCRIPTION
 *  This function is used to get the record by the specified email local id.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  msg_id          [IN]        The email local id
 * RETURNS
 *  The pointer point to the record.
 *****************************************************************************/
static srv_email_pop3_item_struct *srv_email_pop3_get_record_by_msgid(
                                    srv_email_pop3_list_struct *list_p,
                                    EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_item_struct *curr_p = list_p->record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr_p)
    {
        if ((curr_p->nwk_flag & SRV_EMAIL_NWK_FLAG_IN_LOCAL) &&
            curr_p->msg_id == msg_id)
        {
            return curr_p;
        }

        curr_p = curr_p->next;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_get_next_new_msg
 * DESCRIPTION
 *  This function is used to get the record of the next new email.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  curr_rec_p      [IN]        The pointer point to the current record
 * RETURNS
 *  The pointer point to the record.
 *****************************************************************************/
static srv_email_pop3_item_struct *srv_email_pop3_get_next_new_msg(
                                    srv_email_pop3_list_struct *list_p,
                                    srv_email_pop3_item_struct *curr_rec_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_item_struct *curr_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!curr_rec_p)
    {
        curr_p = list_p->record;
    }
    else
    {
        curr_p = curr_rec_p->next;
    }

    while (curr_p)
    {
        if (!(curr_p->nwk_flag & SRV_EMAIL_NWK_FLAG_IN_LOCAL))
        {
            return curr_p;
        }

        curr_p = curr_p->next;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_calc_new_msg
 * DESCRIPTION
 *  This function is used to calculate the new email number.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  retrieve_amount [IN]        The retrieve amount
 * RETURNS
 *  The email number that can be downloaded.
 *****************************************************************************/
static U32 srv_email_pop3_calc_new_msg(srv_email_pop3_list_struct *list_p, U32 retrieve_amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_item_struct *curr_p = NULL;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_p = list_p->record;

    while (curr_p)
    {
        if (!(curr_p->nwk_flag & SRV_EMAIL_NWK_FLAG_IN_LOCAL))
        {
            count++;
        }

        curr_p = curr_p->next;
    }

    if (count > retrieve_amount)
    {
        return retrieve_amount;
    }
    else
    {
        return count;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_make_delete_req_file
 * DESCRIPTION
 *  This function is used to make the delete request file.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 *  msg_count       [OUT]       Used to store the number of emails can be deleted
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_make_delete_req_file(
                                srv_email_pop3_cntx_struct *cntx_p,
                                U32 *msg_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_pop3_item_struct *record_p = sess_p->list.record;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    FS_HANDLE fd = -1;
    S32 ret = 0;
    U32 wbyte = 0;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *msg_count = 0;

    fd = FS_Open(state_p->req_filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fd < 0)
    {
        ret = fd;
        goto EXIT_HANDLE;
    }

    ret = FS_Seek(fd, 4, FS_FILE_BEGIN);
    if (ret < 0)
    {
        goto EXIT_HANDLE;
    }

    while (record_p)
    {
        if (record_p->nwk_flag & SRV_EMAIL_NWK_FLAG_DELETE_SERVER)
        {
            ret = FS_Write(fd, &record_p->seq_no, 4, &wbyte);
            if (ret < 0 || wbyte != 4)
            {
                goto EXIT_HANDLE;
            }

            count++;
        }

        record_p = record_p->next;
    }

    if (count == 0)
    {
        FS_Close(fd);
        FS_Delete(state_p->req_filename);
        return SRV_EMAIL_RESULT_SUCC;
    }

    ret = FS_Seek(fd, 0, FS_FILE_BEGIN);
    if (ret < 0)
    {
        goto EXIT_HANDLE;
    }

    ret = FS_Write(fd, &count, 4, &wbyte);
    if (ret < 0 || wbyte != 4)
    {
        goto EXIT_HANDLE;
    }

    *msg_count = count;
    retval = SRV_EMAIL_RESULT_SUCC;

EXIT_HANDLE:
    if (fd >= 0)
    {
        FS_Close(fd);
    }

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        FS_Delete((const WCHAR*)state_p->req_filename);
        srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_FS_ERROR, ret, NULL);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_read_uid
 * DESCRIPTION
 *  This function is used to read the server email uid.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  msg_seq_no      [OUT]       Used to store the sequence number
 *  uid_digest      [OUT]       Used to store the uid's MD5 digest
 * RETURNS
 *  The FS code.
 *****************************************************************************/
static S32 srv_email_pop3_read_uid(FS_HANDLE fd, U32 *msg_seq_no, U8 *uid_digest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR uidl[SRV_EMAIL_POP3_MAX_UIDL_LEN + 1];
    U32 seq_no;
    S32 ret;
    U32 rbyte;
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Read(fd, &seq_no, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    EMAILSRV_EXT_ASSERT(
        len < SRV_EMAIL_POP3_MAX_UIDL_LEN,
        len,
        SRV_EMAIL_POP3_MAX_UIDL_LEN,
        0);

    ret = FS_Read(fd, uidl, len, &rbyte);
    if (ret < 0 || rbyte != len)
    {
        return ret;
    }
    uidl[len] = '\0';

    if (msg_seq_no)
    {
        *msg_seq_no = seq_no;
    }

    if (uid_digest)
    {
        srv_email_compute_md5_digest((const CHAR*)uidl, len, uid_digest);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_read_size
 * DESCRIPTION
 *  This function is used to read the server email size.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  msg_seq_no      [OUT]       Used to store the sequence number
 *  msg_size        [OUT]       Used to store the email size
 * RETURNS
 *  The FS code.
 *****************************************************************************/
static S32 srv_email_pop3_read_size(FS_HANDLE fd, U32 *msg_seq_no, U32 *msg_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 seq_no;
    U32 size;
    U32 rbyte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Read(fd, &seq_no, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    ret = FS_Read(fd, &size, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    if (msg_seq_no)
    {
        *msg_seq_no = seq_no;
    }

    if (msg_size)
    {
        *msg_size = size;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_list_uid
 * DESCRIPTION
 *  This function is used to list the server email uids.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_list_uid(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_pop3_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    MMI_BOOL ret = MMI_TRUE;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    FS_HANDLE fd = -1;
    U32 rbyte = 0;
    U32 count = 0;
    U32 i = 0;
    U32 min_req_seq = state_p->start_index;
    U32 max_req_seq = state_p->start_index + state_p->list_count - 1;
    U32 min_seq_no = 0xffffffff;
    U32 max_seq_no = 0;
    U32 valid_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open((const WCHAR*)state_p->rsp_filename, FS_READ_ONLY);
    if (fd < 0)
    {
        minor = fd;
        goto EXIT_HANDLE;
    }

    minor = FS_Read(fd, &count, 4, &rbyte);
    if (minor < 0 || rbyte != 4)
    {
        goto EXIT_HANDLE;
    }
    if (count < state_p->list_count)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_POP3_CMD_ERROR;
        goto EXIT_HANDLE;
    }

    //count = SRV_EMAIL_MIN(count, SRV_EMAIL_GET_NUM_PER_TIME);

    for (i = 0; i < count; i++)
    {
        record_p = (srv_email_pop3_item_struct*)srv_email_mem_alloc(sizeof(srv_email_pop3_item_struct));
        if (!record_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto EXIT_HANDLE;
        }

        memset(record_p, 0, sizeof(srv_email_pop3_item_struct));

        minor = srv_email_pop3_read_uid(fd, &record_p->seq_no, record_p->uid_digest);
        if (minor < 0)
        {
            goto EXIT_HANDLE;
        }

        if (record_p->seq_no < min_req_seq || record_p->seq_no > max_req_seq)
        {
            srv_email_mem_free(record_p);
            record_p = NULL;
            continue;
        }

        ret = srv_email_pop3_add_record(&sess_p->list, record_p);
        if (ret)
        {
            state_p->curr_count++;

            valid_count++;
            min_seq_no = SRV_EMAIL_MIN(min_seq_no, record_p->seq_no);
            max_seq_no = SRV_EMAIL_MAX(max_seq_no, record_p->seq_no);

            if (valid_count >= state_p->list_count)
            {
                record_p = NULL;
                break;
            }
        }
        else
        {
            srv_email_mem_free(record_p);
        }
        record_p = NULL;
    }

    if (valid_count != state_p->list_count ||
        min_seq_no != min_req_seq ||
        max_seq_no != max_req_seq)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_POP3_CMD_ERROR;
        goto EXIT_HANDLE;
    }

    retval = SRV_EMAIL_RESULT_SUCC;

EXIT_HANDLE:

    if (fd >= 0)
    {
        FS_Close(fd);
    }
    FS_Delete((const WCHAR*)state_p->rsp_filename);

    if (record_p)
    {
        srv_email_mem_free(record_p);
    }

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_list_size
 * DESCRIPTION
 *  This function is used to list the server email sizes.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_list_size(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_pop3_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    FS_HANDLE fd = -1;
    U32 rbyte = 0;
    U32 count = 0;
    U32 seq_no = 0;
    U32 size = 0;
    U32 i = 0;
    U32 min_req_seq = state_p->start_index;
    U32 max_req_seq = state_p->start_index + state_p->list_count - 1;
    U32 min_seq_no = 0xffffffff;
    U32 max_seq_no = 0;
    U32 valid_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open((const WCHAR*)state_p->rsp_filename, FS_READ_ONLY);
    if (fd < 0)
    {
        minor = fd;
        goto EXIT_HANDLE;
    }

    minor = FS_Read(fd, &count, 4, &rbyte);
    if (minor < 0 || rbyte != 4)
    {
        goto EXIT_HANDLE;
    }
    if (count < state_p->list_count)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_POP3_CMD_ERROR;
        goto EXIT_HANDLE;
    }

    //count = SRV_EMAIL_MIN(count, SRV_EMAIL_GET_NUM_PER_TIME);

    for (i = 0; i < count; i++)
    {
        minor = srv_email_pop3_read_size(fd, &seq_no, &size);
        if (minor < 0)
        {
            goto EXIT_HANDLE;
        }

        record_p = srv_email_pop3_get_record_by_seqno(&sess_p->list, seq_no);
        if (!record_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_INTERNAL_ERROR;
            goto EXIT_HANDLE;
        }

        if (record_p->seq_no < min_req_seq || record_p->seq_no > max_req_seq)
        {
            continue;
        }

        if (record_p->size == 0)
        {
            record_p->size = size;
            state_p->curr_count++;

            valid_count++;
            min_seq_no = SRV_EMAIL_MIN(min_seq_no, record_p->seq_no);
            max_seq_no = SRV_EMAIL_MAX(max_seq_no, record_p->seq_no);

            if (valid_count >= state_p->list_count)
            {
                break;
            }
        }
    }

    if (valid_count != state_p->list_count ||
        min_seq_no != min_req_seq ||
        max_seq_no != max_req_seq)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_POP3_CMD_ERROR;
        goto EXIT_HANDLE;
    }

    retval = SRV_EMAIL_RESULT_SUCC;

EXIT_HANDLE:

    if (fd >= 0)
    {
        FS_Close(fd);
    }
    FS_Delete((const WCHAR*)state_p->rsp_filename);

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_match_msg
 * DESCRIPTION
 *  This function is used to match the local and server emails.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 *  msg_info_p      [IN]        The pointer point to the local email information
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_match_msg(
                        srv_email_pop3_cntx_struct *cntx_p,
                        srv_email_stor_fldr_get_msg_id_struct *msg_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_pop3_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!memcmp(msg_info_p->acct_digest, comm_p->acct_digest, SRV_EMAIL_MD5_DIGEST_LEN))
    {
        record_p = srv_email_pop3_get_record_by_uidl(&sess_p->list, msg_info_p->uidl);
    }

    if (record_p)
    {
        record_p->msg_id = msg_info_p->msg_id;
        record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_IN_LOCAL;

        if (msg_info_p->state & SRV_EMAIL_MSG_STATE_HEADER_ONLY)
        {
            record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_HEADER_ONLY;
        }

        if (msg_info_p->state & SRV_EMAIL_MSG_STATE_DEL_SERVER)
        {
            record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_DELETE_SERVER;
        }
    }
    else
    {
        retval = srv_email_stor_fldr_sync_msg_del(state_p->stor_handle, msg_info_p->msg_id);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_ERROR_POP3_STOR_SYNC_MSG_DEL,
                cntx_p,
                msg_info_p->msg_id,
                retval);

            srv_email_get_stor_error(retval, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
            return SRV_EMAIL_RESULT_FAIL;
        }
    }

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_load_local_msg
 * DESCRIPTION
 *  This function is used to load the local emails.
 * PARAMETERS
 *  user_data       [IN]        The pointer point to the POP3 context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_pop3_load_local_msg(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_cntx_struct *cntx_p = (srv_email_pop3_cntx_struct*)user_data;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_LOAD_LOCAL_MSG, cntx_p);

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->common.schdl_flag)
    {
        cntx_p->common.schdl_flag = MMI_FALSE;

        if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
            cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_WARNING_NWK_STATE_INVALID,
                cntx_p,
                cntx_p->nwk_state,
                cntx_p->sub_state,
                SRV_EMAIL_NWK_STATE_UPDATING,
                SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL);
            return;
        }

        srv_email_pop3_update_fsm(cntx_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update_fsm_init
 * DESCRIPTION
 *  This function is used to initialize the POP3 UPDATE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_update_fsm_init(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_UPDATE_FSM_INIT, cntx_p);

    srv_email_ps_open_folder_req(comm_p->ps_handle, SRV_EMAIL_INBOX_NAME);

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update_fsm_fldr_opened
 * DESCRIPTION
 *  This function is used to process the case that opening folder successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_update_fsm_fldr_opened(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_UPDATE_FSM_FLDR_OPENED, cntx_p, sess_p->total_msg_num);

    if (sess_p->total_msg_num)
    {
        state_p->total_count = SRV_EMAIL_MIN(sess_p->total_msg_num, SRV_EMAIL_MAX_MSG_NUM);
        state_p->total_count = SRV_EMAIL_MIN(state_p->total_count, state_p->retrieve_amount);

        state_p->curr_count = 0;

        if (state_p->total_count == sess_p->total_msg_num &&
            state_p->total_count <= SRV_EMAIL_GET_NUM_PER_TIME)
        {
            state_p->list_count = sess_p->total_msg_num;
            state_p->start_index = 1;
        }
        else
        {
            state_p->list_count = SRV_EMAIL_MIN(state_p->total_count, SRV_EMAIL_GET_NUM_PER_TIME);
            state_p->start_index = sess_p->total_msg_num - state_p->list_count + 1;
        }

        srv_email_ps_list_uid_req(
            comm_p->ps_handle,
            state_p->start_index,
            state_p->list_count,
            state_p->rsp_filename,
            EMAIL_PS_FETCH_TYPE_NONE);

        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        state_p->curr_count = 0;
        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update_fsm_uid_listed
 * DESCRIPTION
 *  This function is used to process the case that listing server email uids successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_update_fsm_uid_listed(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_POP3_UPDATE_FSM_UID_LISTED,
        cntx_p,
        state_p->curr_count,
        state_p->total_count);

    retval = srv_email_pop3_list_uid(cntx_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_LIST_UID, cntx_p, retval);
        return retval;
    }

    if (state_p->total_count > state_p->curr_count)
    {
        state_p->list_count = SRV_EMAIL_MIN(state_p->total_count - state_p->curr_count, SRV_EMAIL_GET_NUM_PER_TIME);

        state_p->start_index = sess_p->total_msg_num - state_p->curr_count - state_p->list_count + 1;

        srv_email_ps_list_uid_req(
            comm_p->ps_handle,
            state_p->start_index,
            state_p->list_count,
            state_p->rsp_filename,
            EMAIL_PS_FETCH_TYPE_NONE);
    }
    else
    {
        state_p->curr_count = 0;

        if (state_p->total_count == sess_p->total_msg_num &&
            state_p->total_count <= SRV_EMAIL_GET_NUM_PER_TIME)
        {
            state_p->list_count = sess_p->total_msg_num;
            state_p->start_index = 1;
        }
        else
        {
            state_p->list_count = SRV_EMAIL_MIN(state_p->total_count, SRV_EMAIL_GET_NUM_PER_TIME);
            state_p->start_index = sess_p->total_msg_num - state_p->list_count + 1;
        }

        srv_email_ps_list_size_req(
            comm_p->ps_handle,
            state_p->start_index,
            state_p->list_count,
            state_p->rsp_filename);

        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE);
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update_fsm_size_listed
 * DESCRIPTION
 *  This function is used to process the case that listing email sizes successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_update_fsm_size_listed(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_POP3_UPDATE_FSM_SIZE_LISTED,
        cntx_p,
        state_p->curr_count,
        state_p->total_count);

    retval = srv_email_pop3_list_size(cntx_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_LIST_SIZE, cntx_p, retval);
        return retval;
    }

    if (state_p->total_count > state_p->curr_count)
    {
        state_p->list_count = SRV_EMAIL_MIN(state_p->total_count - state_p->curr_count, SRV_EMAIL_GET_NUM_PER_TIME);

        state_p->start_index = sess_p->total_msg_num - state_p->curr_count - state_p->list_count + 1;

        srv_email_ps_list_size_req(
            comm_p->ps_handle,
            state_p->start_index,
            state_p->list_count,
            state_p->rsp_filename);

        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        state_p->curr_count = 0;
        state_p->start_index = 0;

        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL);

        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update_fsm_local_updated
 * DESCRIPTION
 *  This function is used to process the case that updating local emails successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_update_fsm_local_updated(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_stor_fldr_get_msg_id_struct *msg_info_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_WOULDBLOCK;
    S32 count = 0;
    S32 major = 0;
    S32 minor = 0;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;
    EMAIL_STOR_HANDLE stor_handle = EMAIL_STOR_INVALID_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_UPDATE_FSM_LOCAL_UPDATED, cntx_p);

    fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

    if (state_p->curr_count)
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
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_STOR_SYNC_MSG_OPEN, cntx_p, fldr_id, retval);

        srv_email_get_stor_error(retval, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

    state_p->stor_handle = stor_handle;

    msg_info_p = (srv_email_stor_fldr_get_msg_id_struct*)
        OslMalloc(sizeof(srv_email_stor_fldr_get_msg_id_struct));

    for (count = 0; count < SRV_EMAIL_POP3_LIST_NUM_PER_TIME; count++)
    {
        retval = srv_email_stor_fldr_sync_msg_get_next(state_p->stor_handle, msg_info_p);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            retval = srv_email_pop3_match_msg(cntx_p, msg_info_p);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }
            state_p->curr_count++;
            state_p->last_msg_id = msg_info_p->msg_id;
            retval = SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else if (retval == SRV_EMAIL_RESULT_NO_MORE_RESULT)
        {
            SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_DONE);
            retval = SRV_EMAIL_RESULT_SUCC;
            break;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_STOR_SYNC_MSG_GET_NEXT, cntx_p, retval);

            srv_email_get_stor_error(retval, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
            retval = SRV_EMAIL_RESULT_FAIL;
            break;
        }
    }

    OslMfree(msg_info_p);

    srv_email_stor_fldr_sync_msg_close(&state_p->stor_handle);
    state_p->stor_handle = EMAIL_STOR_INVALID_HANDLE;

    if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        srv_email_nwk_start_job(srv_email_pop3_load_local_msg, (srv_email_nwk_cntx_struct*)cntx_p);
        retval = SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update_fsm_done
 * DESCRIPTION
 *  This function is used to process the case that updating connection successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static void srv_email_pop3_update_fsm_done(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_struct *result_p = &cntx_p->common.result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_POP3_UPDATE_FSM_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    if (!result_p->result)
    {
        srv_email_pop3_session_free(&cntx_p->session);
    }
    else
    {
        cntx_p->session.sync_with_server = MMI_TRUE;
    }

    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    srv_email_pop3_state_free(&cntx_p->state);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_parse_save_done
 * DESCRIPTION
 *  This function is used to process the result of parsing/saving email.
 * PARAMETERS
 *  result          [IN]        The result of parsing/saving
 *  req_id          [IN]        The async request id
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_pop3_parse_save_done(srv_email_result_struct *result_p, EMAIL_REQ_ID req_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_cntx_struct *cntx_p = (srv_email_pop3_cntx_struct*)user_data;
    srv_email_comm_cntx_struct *comm_p = NULL;
    srv_email_pop3_state_struct *state_p = NULL;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_POP3_MSG_PARSE_SAVE_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    comm_p = &cntx_p->common;
    state_p = &cntx_p->state;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE &&
         cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE))
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_RECEIVING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE);
        return;
    }

    EMAILSRV_EXT_ASSERT(state_p->req_id == req_id, state_p->req_id, req_id, 0);
    state_p->req_id = EMAIL_REQ_INVALID_ID;

    if (!result_p->result)
    {
        srv_email_set_error_cause(&comm_p->result, result_p->major, result_p->minor, NULL);
    }

    srv_email_pop3_recv_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_recv_fsm_init
 * DESCRIPTION
 *  This function is used to initialize the POP3 RECEIVE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_recv_fsm_init(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_RECV_FSM_INIT, cntx_p);

    srv_email_ps_fetch_mail_req(
        comm_p->ps_handle,
        state_p->curr_rec_p->seq_no,
        state_p->fetch_type,
        EMAIL_MSG_TEXT_DOWNLOAD_SIZE_FOR_POP3,    
        NULL,
        (const WCHAR*)state_p->rsp_filename);

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

    if (state_p->batch_download)
    {
        srv_email_receiving_data_struct recv_data;

        recv_data.fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);
        recv_data.total_num = state_p->total_num;
        recv_data.received_num = 0;
        recv_data.fail_num = 0;
        recv_data.total_size = state_p->curr_rec_p->size;
        recv_data.received_size = 0;
        recv_data.new_msg_received = MMI_FALSE;
        recv_data.new_msg_id = EMAIL_MSG_INVALID_ID;
        recv_data.new_msg_flag = 0;
        srv_email_nwk_cb_process_notify(
            (srv_email_nwk_cntx_struct*)cntx_p,
            NULL,
            SRV_EMAIL_NWK_RECEIVING,
            &recv_data);
    }
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_recv_fsm_received
 * DESCRIPTION
 *  This function is used to process the case that receiving email successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_recv_fsm_received(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    EMAIL_SRV_HANDLE srv_handle = EMAIL_SRV_INVALID_HANDLE;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    FS_HANDLE file_handle;
    MMI_BOOL parse_body = MMI_TRUE;
    S32 major = 0;
    S32 minor = 0;
    U32 download_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_RECV_FSM_RECEIVED, cntx_p);


    srv_handle = srv_email_get_int_srv_handle();

    retval = srv_email_msg_create(srv_handle, &state_p->msg_handle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_MSG_CREATE_HANDLE, cntx_p, retval);

        srv_email_get_msg_error(retval, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

    srv_email_msg_regist_callback(state_p->msg_handle, srv_email_pop3_parse_save_done, cntx_p);
    file_handle = FS_Open(state_p->rsp_filename, FS_READ_ONLY);

    if (file_handle < 0)
    {
        srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_FS_ERROR, file_handle, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

	FS_GetFileSize(file_handle, &download_size);
    FS_Close(file_handle);
    file_handle = -1;

	if (state_p->batch_download &&
        state_p->fetch_type == EMAIL_PS_FETCH_TYPE_HEADER &&
        download_size < state_p->curr_rec_p->size)
	{
        retval = srv_email_msg_parse_partial_file(
                    state_p->msg_handle,
                    state_p->rsp_filename,
                    parse_body,
                    parse_body,
                    &state_p->req_id);
    }
    else
    {
        retval = srv_email_msg_parse_file(
                    state_p->msg_handle,
                    state_p->rsp_filename,
                    parse_body,
                    parse_body,
                    &state_p->req_id);
    }

    if (retval == SRV_EMAIL_RESULT_SUCC || retval == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE);
        return retval;
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_MSG_PARSE, cntx_p, retval);

        srv_email_get_msg_error(retval, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_recv_fsm_parsed
 * DESCRIPTION
 *  This function is used to process the case that parsing email successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_recv_fsm_parsed(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_RECV_FSM_PARSED, cntx_p);

    fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

    if (state_p->batch_download)
    {
        retval = srv_email_msg_save_new_for_nwk(
                    state_p->msg_handle,
                    state_p->curr_rec_p->uid_digest,
                    state_p->curr_rec_p->size,
                    comm_p->acct_digest,
                    comm_p->acct_id,
                    fldr_id,
                    &state_p->msg_id,
                    &state_p->req_id);
    }
    else
    {
        srv_email_msg_nwk_pre_save(state_p->curr_rec_p->msg_id, state_p->msg_handle);

        retval = srv_email_msg_save_for_nwk(
                    state_p->msg_handle,
                    state_p->curr_rec_p->uid_digest,
                    comm_p->acct_digest,
                    SRV_EMAIL_MSG_SAVE_ALL,
                    &state_p->req_id);
    }

    if (retval == SRV_EMAIL_RESULT_SUCC || retval == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE);
        return retval;
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_MSG_SAVE, cntx_p, retval);

        srv_email_get_msg_error(retval, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_recv_fsm_saved
 * DESCRIPTION
 *  This function is used to process the case that saving email successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_recv_fsm_saved(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_receiving_data_struct recv_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_RECV_FSM_SAVED, cntx_p);

    if (state_p->batch_download)
    {
        state_p->curr_rec_p->msg_id = state_p->msg_id;
        state_p->curr_rec_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_IN_LOCAL;

        state_p->received_num++;

        recv_data.fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);
        recv_data.total_num = state_p->total_num;
        recv_data.received_num = state_p->received_num;
        recv_data.fail_num = state_p->fail_num;
        recv_data.total_size = state_p->curr_rec_p->size;
        recv_data.received_size = 0;
        recv_data.new_msg_received = MMI_TRUE;
        recv_data.new_msg_id = state_p->curr_rec_p->msg_id;
        recv_data.new_msg_flag = 0;
        srv_email_nwk_cb_process_notify(
            (srv_email_nwk_cntx_struct*)cntx_p,
            NULL,
            SRV_EMAIL_NWK_RECEIVING,
            &recv_data);
    }
    else
    {
        srv_email_msg_update_msg_by_handle(state_p->curr_rec_p->msg_id, state_p->msg_handle);
    }

    srv_email_msg_destroy(state_p->msg_handle);
    state_p->msg_handle = EMAIL_MSG_INVALID_HANDLE;

    if (!state_p->batch_download ||
        (state_p->received_num + state_p->fail_num == state_p->total_num))
    {
        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
        return SRV_EMAIL_RESULT_SUCC;
    }

    state_p->curr_rec_p = srv_email_pop3_get_next_new_msg(&sess_p->list, state_p->curr_rec_p);
    if (!state_p->curr_rec_p)
    {
        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
        return SRV_EMAIL_RESULT_SUCC;
    }

    switch (state_p->download_opt)
    {
        case SRV_EMAIL_DOWNLOAD_HEADER:
            state_p->fetch_type = EMAIL_PS_FETCH_TYPE_HEADER;
    	    break;

        case SRV_EMAIL_DOWNLOAD_ALL:
            if (state_p->curr_rec_p->size > state_p->download_size)
            {
                state_p->fetch_type = EMAIL_PS_FETCH_TYPE_HEADER;
            }
            else
            {
                state_p->fetch_type = EMAIL_PS_FETCH_TYPE_FULL;
            }
    	    break;

        default:
            EMAILSRV_EXT_ASSERT(0, state_p->download_opt, 0, 0);
            break;
    }

    srv_email_ps_fetch_mail_req(
        comm_p->ps_handle,
        state_p->curr_rec_p->seq_no,
        state_p->fetch_type,
        EMAIL_MSG_TEXT_DOWNLOAD_SIZE_FOR_POP3,             /*skyfyx*/
        NULL,
        (const WCHAR*)state_p->rsp_filename);

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_recv_fsm_done
 * DESCRIPTION
 *  This function is used to process the case that receiving successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static void srv_email_pop3_recv_fsm_done(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_result_struct *result_p = &cntx_p->common.result;
    srv_email_receive_done_data_struct recv_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_POP3_RECV_FSM_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    if (state_p->batch_download)
    {
        recv_data.fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);
        recv_data.fldr_count = 1;
        recv_data.fldr_index = 1;
        recv_data.total_num = state_p->total_num;
        recv_data.received_num = state_p->received_num;
        recv_data.fail_num = state_p->fail_num;
        recv_data.result = state_p->major ? MMI_FALSE : MMI_TRUE;
        recv_data.major = state_p->major;
        recv_data.minor = state_p->minor;
        srv_email_nwk_cb_process_notify(
            (srv_email_nwk_cntx_struct*)cntx_p,
            NULL,
            SRV_EMAIL_NWK_RECEIVE_DONE,
            &recv_data);
    }

    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    srv_email_pop3_state_free(&cntx_p->state);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_recv_mail_fail
 * DESCRIPTION
 *  This function is used to process the case that receiving email unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_recv_mail_fail(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_receiving_data_struct recv_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //trace: recv fail

    if (state_p->batch_download)
    {
        if (state_p->major == 0)
        {
            state_p->major = comm_p->result.major;
            state_p->minor = comm_p->result.minor;
        }
        comm_p->result.result = MMI_TRUE;

        state_p->fail_num++;

        recv_data.fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);
        recv_data.total_num = state_p->total_num;
        recv_data.received_num = state_p->received_num;
        recv_data.fail_num = state_p->fail_num;
        recv_data.total_size = state_p->curr_rec_p->size;
        recv_data.received_size = 0;
        recv_data.new_msg_received = MMI_FALSE;
        recv_data.new_msg_id = EMAIL_MSG_INVALID_ID;
        recv_data.new_msg_flag = 0;
        srv_email_nwk_cb_process_notify(
            (srv_email_nwk_cntx_struct*)cntx_p,
            NULL,
            SRV_EMAIL_NWK_RECEIVING,
            &recv_data);
    }

    srv_email_msg_destroy(state_p->msg_handle);
    state_p->msg_handle = EMAIL_MSG_INVALID_HANDLE;

    if (!state_p->batch_download ||
        (state_p->received_num + state_p->fail_num == state_p->total_num))
    {
        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
        return SRV_EMAIL_RESULT_SUCC;
    }

    state_p->curr_rec_p = srv_email_pop3_get_next_new_msg(&sess_p->list, state_p->curr_rec_p);
    if (!state_p->curr_rec_p)
    {
        SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
        return SRV_EMAIL_RESULT_SUCC;
    }

    srv_email_ps_fetch_mail_req(
        comm_p->ps_handle,
        state_p->curr_rec_p->seq_no,
        state_p->fetch_type,
        0,
        NULL,
        (const WCHAR*)state_p->rsp_filename);

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_disc_fsm_init
 * DESCRIPTION
 *  This function is used to initialize the POP3 DISCONNECT FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_disc_fsm_init(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_DISC_FSM_INIT, cntx_p);

    if (sess_p->total_msg_num == 0)
    {
        goto DISC_HANDLE;
    }

    retval = srv_email_pop3_make_delete_req_file(cntx_p, &count);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_MAKE_DISC_REQ_FILE, cntx_p, retval);
        goto DISC_HANDLE;
    }

    if (count == 0)
    {
        goto DISC_HANDLE;
    }

    srv_email_ps_delete_mail_req(comm_p->ps_handle, (const WCHAR*)state_p->req_filename);

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_SERVER);
    return SRV_EMAIL_RESULT_WOULDBLOCK;

DISC_HANDLE:
    srv_email_ps_disconnect_req(comm_p->ps_handle);
    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_DISC_DISCONNECT);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_disc_fsm_server_deleted
 * DESCRIPTION
 *  This function is used to process the case that deleting email successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_disc_fsm_server_deleted(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_DISC_FSM_SERVER_DELETED, cntx_p);

    srv_email_ps_disconnect_req(comm_p->ps_handle);

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_DISC_DISCONNECT);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_disc_fsm_disconnected
 * DESCRIPTION
 *  This function is used to process the case that disconnecting successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_disc_fsm_disconnected(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_pop3_item_struct *record_p = sess_p->list.record;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_DISC_FSM_DISCONNECTED, cntx_p, state_p->delete_fail);

    if (state_p->delete_fail)
    {
        goto EXIT_HANDLE;
    }

    fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

    retval = srv_email_stor_fldr_sync_msg_open(comm_p->acct_id, fldr_id, &state_p->stor_handle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_STOR_SYNC_MSG_OPEN, cntx_p, fldr_id, retval);
        goto EXIT_HANDLE;
    }

    while (record_p)
    {
        if ((record_p->nwk_flag & SRV_EMAIL_NWK_FLAG_IN_LOCAL) &&
            (record_p->nwk_flag & SRV_EMAIL_NWK_FLAG_DELETE_SERVER))
        {
            retval = srv_email_stor_fldr_sync_msg_del(state_p->stor_handle, record_p->msg_id);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_ERROR_POP3_STOR_SYNC_MSG_DEL,
                    cntx_p,
                    record_p->msg_id,
                    retval);
                goto EXIT_HANDLE;
            }
        }

        record_p = record_p->next;
    }

EXIT_HANDLE:
    if (state_p->stor_handle != EMAIL_STOR_INVALID_HANDLE)
    {
        srv_email_stor_fldr_sync_msg_close(&state_p->stor_handle);
        state_p->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    }

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_LOCAL);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_disc_fsm_local_deleted
 * DESCRIPTION
 *  This function is used to process the case that deleting local emails.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_pop3_disc_fsm_local_deleted(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_DISC_FSM_LOCAL_DELETED, cntx_p);

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_DISC_DONE);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_disc_fsm_done
 * DESCRIPTION
 *  This function is used to process the case that disconnecting successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static void srv_email_pop3_disc_fsm_done(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_struct *result_p = &cntx_p->common.result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_POP3_DISC_FSM_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    srv_email_pop3_cntx_free(cntx_p);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_cntx_init
 * DESCRIPTION
 *  This function is used to initialize the POP3 context.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_pop3_cntx_init(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(cntx_p, 0, sizeof(srv_email_pop3_cntx_struct));
    cntx_p->common.result.result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_cntx_free
 * DESCRIPTION
 *  This function is used to free the POP3 context.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_pop3_cntx_free(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_pop3_session_free(&cntx_p->session);
    srv_email_pop3_state_free(&cntx_p->state);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update
 * DESCRIPTION
 *  This function is used to update the POP3 connection.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 *  retrieve_amount [IN]        The retrieve amount
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_pop3_update(
                        srv_email_pop3_cntx_struct *cntx_p,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sess_p->sync_with_server)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_STATE;
        goto ERROR_HANDLE;
    }

    srv_email_pop3_session_init(sess_p);
    srv_email_pop3_state_init(state_p);

    state_p->retrieve_amount = retrieve_amount;

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT);

    retval = srv_email_pop3_update_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update_fsm
 * DESCRIPTION
 *  This function is used to run the POP3 UPDATE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_pop3_update_fsm(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL run_fsm = cntx_p->common.result.result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (run_fsm)
    {
        switch (cntx_p->sub_state)
        {
            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT:
                retval = srv_email_pop3_update_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER:
                retval = srv_email_pop3_update_fsm_fldr_opened(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID:
                retval = srv_email_pop3_update_fsm_uid_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE:
                retval = srv_email_pop3_update_fsm_size_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL:
                retval = srv_email_pop3_update_fsm_local_updated(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_DONE:
                run_fsm = MMI_FALSE;
                break;

            case SRV_EMAIL_NWK_SUB_STATE_NONE:
                return SRV_EMAIL_RESULT_SUCC;

            default:
                EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
                break;
        }

        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            run_fsm = MMI_FALSE;
        }
    }

    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK &&
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT)
    {
        srv_email_pop3_update_fsm_done(cntx_p);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_receive
 * DESCRIPTION
 *  This function is used to receive emails.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 *  recv_p          [IN]        The pointer point to the receive option
 *  download_opt    [IN]        The download option
 *  download_size   [IN]        The download size
 *  retrieve_amount [IN]        The retrieve amount
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_pop3_receive(
                        srv_email_pop3_cntx_struct *cntx_p,
                        srv_email_nwk_recv_struct *recv_p,
                        srv_email_download_option_enum download_opt,
                        U32 download_size,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_pop3_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sess_p->sync_with_server)
    {
        minor = SRV_EMAIL_RESULT_INVALID_OPERATION;
        goto ERROR_HANDLE;
    }

    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_STATE;
        goto ERROR_HANDLE;
    }

    if (sess_p->total_msg_num == 0)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    record_p = srv_email_pop3_get_next_new_msg(&sess_p->list, NULL);
    if (!record_p)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    srv_email_pop3_state_init(state_p);

    state_p->batch_download = MMI_TRUE;
    state_p->recv_opt = recv_p->recv_opt;
    state_p->download_opt = download_opt;
    state_p->download_size = download_size;
    state_p->retrieve_amount = retrieve_amount;
    state_p->total_num = srv_email_pop3_calc_new_msg(&sess_p->list, retrieve_amount);
    state_p->curr_rec_p = record_p;

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    switch (state_p->download_opt)
    {
        case SRV_EMAIL_DOWNLOAD_HEADER:
            state_p->fetch_type = EMAIL_PS_FETCH_TYPE_HEADER;
    	    break;

        case SRV_EMAIL_DOWNLOAD_ALL:
            if (state_p->curr_rec_p->size > state_p->download_size)
            {
                state_p->fetch_type = EMAIL_PS_FETCH_TYPE_HEADER;
            }
            else
            {
                state_p->fetch_type = EMAIL_PS_FETCH_TYPE_FULL;
            }
    	    break;

        default:
            EMAILSRV_EXT_ASSERT(0, state_p->download_opt, 0, 0);
            break;
    }

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_INIT);

    retval = srv_email_pop3_recv_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;

}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_retrieve
 * DESCRIPTION
 *  This function is used to retrieve email.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 *  retr_p          [IN]        The pointer point to the retrieve option
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_pop3_retrieve(
                        srv_email_pop3_cntx_struct *cntx_p,
                        srv_email_nwk_retr_struct *retr_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_pop3_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL is_valid = MMI_TRUE;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sess_p->sync_with_server)
    {
        minor = SRV_EMAIL_RESULT_INVALID_OPERATION;
        goto ERROR_HANDLE;
    }

    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_STATE;
        goto ERROR_HANDLE;
    }

    retval = srv_email_stor_msg_id_valid(retr_p->msg_id, &is_valid);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_stor_error(retval, &major, &minor);
        goto ERROR_HANDLE;
    }
    if (!is_valid)
    {
        minor = SRV_EMAIL_RESULT_MSG_NOT_EXIST;
        goto ERROR_HANDLE;
    }

    if (sess_p->total_msg_num == 0)
    {
        minor = SRV_EMAIL_RESULT_MSG_NOT_EXIST;
        goto ERROR_HANDLE;
    }

    record_p = srv_email_pop3_get_record_by_msgid(&sess_p->list, retr_p->msg_id);
    if (!record_p)
    {
        minor = SRV_EMAIL_RESULT_MSG_NOT_EXIST;
        goto ERROR_HANDLE;
    }

    if (!(record_p->nwk_flag & SRV_EMAIL_MSG_STATE_HEADER_ONLY))
    {
        minor = SRV_EMAIL_RESULT_MSG_IN_LOCAL;
        goto ERROR_HANDLE;
    }

    srv_email_pop3_state_init(state_p);

    state_p->curr_rec_p = record_p;

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    switch (retr_p->retr_opt)
    {
        case SRV_EMAIL_RETRIEVE_ALL_PARTS:
            state_p->fetch_type = EMAIL_PS_FETCH_TYPE_FULL;
    	    break;

        default:
            EMAILSRV_EXT_ASSERT(0, retr_p->retr_opt, 0, 0);
            break;
    }

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_INIT);

    retval = srv_email_pop3_recv_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_recv_fsm
 * DESCRIPTION
 *  This function is used to run the POP3 RECEIVE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_pop3_recv_fsm(srv_email_pop3_cntx_struct *cntx_p)
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
            case SRV_EMAIL_NWK_SUB_STATE_RECV_INIT:
                retval = srv_email_pop3_recv_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE:
                retval = srv_email_pop3_recv_fsm_received(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE:
                retval = srv_email_pop3_recv_fsm_parsed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE:
                retval = srv_email_pop3_recv_fsm_saved(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_DONE:
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

    if (cntx_p->sub_state == SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE &&
        !result_p->result &&
        result_p->major == SRV_EMAIL_MAIL_ERROR &&
        (result_p->minor == SRV_EMAIL_RESULT_INVALID_FORMAT))
    {
        retval = srv_email_pop3_recv_mail_fail(cntx_p);
    }

    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK &&
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_INIT)
    {
        srv_email_pop3_recv_fsm_done(cntx_p);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_disconnect
 * DESCRIPTION
 *  This function is used to disconnect the server.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_pop3_disconnect(
                        srv_email_pop3_cntx_struct *cntx_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sess_p->sync_with_server)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    srv_email_pop3_state_init(state_p);

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_DISC_INIT);

    retval = srv_email_pop3_disc_fsm(cntx_p);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_disc_fsm
 * DESCRIPTION
 *  This function is used to run the POP3 DISCONNECT FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_pop3_disc_fsm(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL run_fsm = cntx_p->common.result.result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (run_fsm)
    {
        switch (cntx_p->sub_state)
        {
            case SRV_EMAIL_NWK_SUB_STATE_DISC_INIT:
                retval = srv_email_pop3_disc_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_SERVER:
                retval = srv_email_pop3_disc_fsm_server_deleted(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_DISC_DISCONNECT:
                retval = srv_email_pop3_disc_fsm_disconnected(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_LOCAL:
                retval = srv_email_pop3_disc_fsm_local_deleted(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_DISC_DONE:
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

    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        srv_email_pop3_disc_fsm_done(cntx_p);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_update_abort
 * DESCRIPTION
 *  This function is used to stop the POP3 UPDATE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_pop3_update_abort(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_UPDATE_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER:
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID:
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL:
            srv_email_nwk_stop_job((srv_email_nwk_cntx_struct*)cntx_p);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_DONE:
            break;

        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;
    comm_p->result.result = MMI_FALSE;

    srv_email_pop3_update_fsm_done(cntx_p);

    comm_p->result.result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_receive_abort
 * DESCRIPTION
 *  This function is used to stop the POP3 RECEIVE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_pop3_receive_abort(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_POP3_RECV_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE:
        case SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE:
            break;

        case SRV_EMAIL_NWK_SUB_STATE_RECV_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_RECV_DONE:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;
    comm_p->result.result = MMI_FALSE;

    srv_email_pop3_recv_fsm_done(cntx_p);

    comm_p->result.result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_disconnect_abort
 * DESCRIPTION
 *  This function is used to stop the POP3 DISCONNECT FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_pop3_disconnect_abort(srv_email_pop3_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_SERVER:
        case SRV_EMAIL_NWK_SUB_STATE_DISC_DISCONNECT:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_DISC_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_LOCAL:
        case SRV_EMAIL_NWK_SUB_STATE_DISC_DONE:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;
    comm_p->result.result = MMI_FALSE;

    srv_email_pop3_disc_fsm_done(cntx_p);

    comm_p->result.result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_pop3_proc_om_notify
 * DESCRIPTION
 *  This function is used to process the Object Management notification.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the POP3 context
 *  notify_p        [IN]        The pointer point to the notification
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_pop3_proc_om_notify(
        srv_email_pop3_cntx_struct *cntx_p,
        srv_email_om_notify_struct *notify_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_pop3_session_struct *sess_p = &cntx_p->session;
    srv_email_pop3_item_struct *record_p = NULL;
    srv_email_om_notify_msg_struct *msg_p = (srv_email_om_notify_msg_struct*)notify_p->data;
    EMAIL_FLDR_ID inbox_id = EMAIL_FLDR_INVALID_ID;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (notify_p->notify_type != SRV_EMAIL_OM_NOTIFY_MSG_DEL &&
        notify_p->notify_type != SRV_EMAIL_OM_NOTIFY_MSG_UPDATE)
    {
        return;
    }

    inbox_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);
    fldr_id = srv_email_stor_msg_id_to_fldr_id(msg_p->msg_id);
    if (!sess_p->sync_with_server || fldr_id != inbox_id)
    {
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_POP3_PROC_OM_NOTIFY,
        cntx_p,
        notify_p->notify_type);

    record_p = srv_email_pop3_get_record_by_msgid(&sess_p->list, msg_p->msg_id);
    if (!record_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_POP3_OM_DEL_MSG_GET_RECORD, cntx_p);
        return;
    }

    switch (notify_p->notify_type)
    {
        case SRV_EMAIL_OM_NOTIFY_MSG_DEL:
            record_p->nwk_flag = SRV_EMAIL_NWK_FLAG_FLAG_VALID;
            break;

        case SRV_EMAIL_OM_NOTIFY_MSG_UPDATE:
            if (msg_p->chg_mask & SRV_EMAIL_OM_NOTIFY_MSG_CHG_STATE)
            {
                if (msg_p->state & SRV_EMAIL_MSG_STATE_DEL_SERVER)
                {
                    record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_DELETE_SERVER;
                }
                else
                {
                    record_p->nwk_flag &= ~SRV_EMAIL_NWK_FLAG_DELETE_SERVER;
                }
            }
            break;

        default:
            break;
    }
}

#endif /* __MMI_EMAIL__ */

