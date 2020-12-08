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
 *  EmailSrvIMAP4.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email IMAP4 functions.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__)
#include "app_str.h"

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvNetworkProt.h"
#include "EmailSrvIMAP4.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_trc_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "string.h"

#ifdef __MMI_EMAIL__
#include "app_mine.h"
#include "app_datetime.h"
#include "app_base64.h"
#include "app_qp.h"
#include "conversions.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif

#include "emlst_miscell.h"

#include "EmailSrvStorage.h"
#include "mmi_frm_mem_gprot.h"
#include "drm_errcode.h"
#include "email_ps_public.h"
#include "Unicodexdcl.h"
#include "customer_ps_inc.h"

#define SRV_EMAIL_IMAP4_DECODE_BUFF_SIZE    4096

typedef enum
{
    SRV_EMAIL_IMAP4_NONE,
    SRV_EMAIL_IMAP4_GET_FLAG,
    SRV_EMAIL_IMAP4_SET_FLAG,
    SRV_EMAIL_IMAP4_TOTAL
} srv_email_imap4_action_enum;
#endif /* __MMI_EMAIL__ */

/* Encoding Types */
const CHAR *const srv_email_imap4_encodings[EMAIL_MIME_ENCMAX] =
{
    "7BIT", "8BIT", "BINARY", "BASE64", "QUOTED-PRINTABLE"
};

static srv_email_cont_list_struct *srv_email_imap4_add_cont(
                                    srv_email_cont_list_struct *header_p,
                                    srv_email_cont_list_struct *cont_p);
static srv_email_attach_list_struct *srv_email_imap4_add_attach(
                                        srv_email_attach_list_struct *header_p,
                                        srv_email_attach_list_struct *attach_p);

static S32 srv_email_imap4_read_cont_header(FS_HANDLE fd, srv_email_stor_cont_header_struct *cont_p);
static S32 srv_email_imap4_read_attach_header(FS_HANDLE fd, srv_email_stor_attch_struct *attach_p, S32 *major);

#ifdef __MMI_EMAIL__

static void srv_email_imap4_decode_base64_qprint(void *user_data);
#ifdef __DRM_SUPPORT__
static void srv_email_imap4_parse_drm_done(U8 serial, S32 result, applib_mime_type_struct *mime_type);
#endif
static void srv_email_imap4_abort_parse(srv_email_imap4_state_struct *state_p);

static void srv_email_imap4_session_init(srv_email_imap4_session_struct *sess_p);
static void srv_email_imap4_session_free(srv_email_imap4_session_struct *sess_p);
static void srv_email_imap4_state_init(srv_email_imap4_state_struct *state_p);
static void srv_email_imap4_state_free(srv_email_imap4_state_struct *state_p);

static srv_email_result_enum srv_email_imap4_make_req_file(
                                srv_email_imap4_cntx_struct *cntx_p,
                                srv_email_imap4_action_enum action);
static srv_email_result_enum srv_email_imap4_list_attach(
                                EMAIL_MSG_ID msg_id,
                                srv_email_attach_list_struct **attach_list_p);

static MMI_BOOL srv_email_imap4_add_record(
                    srv_email_imap4_list_struct *list_p,
                    srv_email_imap4_item_struct *record_p);
static srv_email_imap4_item_struct *srv_email_imap4_get_record_by_uid(
                                        srv_email_imap4_list_struct *list_p,
                                        U32 uid);
static srv_email_imap4_item_struct *srv_email_imap4_get_record_by_msgid(
                                        srv_email_imap4_list_struct *list_p,
                                        EMAIL_MSG_ID msg_id);
static srv_email_imap4_item_struct *srv_email_imap4_get_next_new_msg(
                                        srv_email_imap4_list_struct *list_p,
                                        srv_email_imap4_item_struct *curr_rec_p);
static U32 srv_email_imap4_calc_new_msg(srv_email_imap4_list_struct *list_p, U32 retrieve_amount);

static S32 srv_email_imap4_read_data(FS_HANDLE fd, U32 *data1, U32 *data2);
static S32 srv_email_imap4_read_uid(FS_HANDLE fd, U32 *msg_seq_no, U32 *msg_uid);
static S32 srv_email_imap4_read_size(FS_HANDLE fd, U32 *msg_seq_no, U32 *msg_size);
static S32 srv_email_imap4_read_flag(FS_HANDLE fd, U32 *msg_uid, U32 *msg_flag);

static srv_email_result_enum srv_email_imap4_list_uid(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_list_size(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_list_flag(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_match_msg(
                        srv_email_imap4_cntx_struct *cntx_p,
                        srv_email_stor_fldr_get_msg_id_struct *msg_info_p);

static void srv_email_imap4_load_local_msg(void *user_data);

static srv_email_result_enum srv_email_imap4_update_fsm_init(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_update_fsm_fldr_opened(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_update_fsm_uid_listed(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_update_fsm_size_listed(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_update_fsm_flag_listed(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_update_fsm_local_updated(srv_email_imap4_cntx_struct *cntx_p);
static void srv_email_imap4_update_fsm_done(srv_email_imap4_cntx_struct *cntx_p);

static void srv_email_imap4_query_text(
                srv_eamil_msg_text_type_enum type,
                srv_email_stor_cont_header_struct *cont_header,
                void *buff,
                U32 buff_size,
                S32 *keep_src,
                void *user_data);

static void srv_email_imap4_query_addr(
                srv_email_addr_type_enum type,
                U16 index,
                srv_email_stor_addr_struct *data,
                void *user_data);

static void srv_email_imap4_query_attach(
                U16 index,
                void *buff,
                U32 buff_size,
                S32 *keep_src,
                srv_email_stor_attch_query_type_enum type,
                void *user_data);

static void srv_email_imap4_save_done(srv_email_result_enum result, EMAIL_MSG_ID msg_id, void *user_data);

static srv_email_result_enum srv_email_imap4_save_mail(srv_email_imap4_cntx_struct *cntx_p);

static S32 srv_email_imap4_read_addr(FS_HANDLE fd, srv_email_stor_addr_struct *addr_p);

static srv_email_addr_list_struct *srv_email_imap4_add_addr(
                                    srv_email_addr_list_struct *header_p,
                                    srv_email_addr_list_struct *addr_p);

static srv_email_result_enum srv_email_imap4_read_envelope(
                                const WCHAR *filename,
                                srv_email_msg_env_struct *msg_env_p,
                                S32 *major_error,
                                S32 *minor_error);
static srv_email_result_enum srv_email_imap4_read_attachment(
                                const WCHAR *filename,
                                srv_email_attach_list_struct *attach_p,
                                S32 *major_error,
                                S32 *minor_error);
static srv_email_result_enum srv_email_imap4_parse_content(
                                srv_email_imap4_cntx_struct *cntx_p,
                                srv_email_cont_list_struct *cont_p,
                                S32 *major_error,
                                S32 *minor_error);
static srv_email_result_enum srv_email_imap4_parse_attachment(
                                srv_email_imap4_cntx_struct *cntx_p,
                                srv_email_attach_list_struct *attach_p,
                                S32 *major_error,
                                S32 *minor_error);

static srv_email_result_enum srv_email_imap4_recv_fsm_init(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_recv_fsm_received(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_recv_fsm_parsed(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_recv_fsm_saved(srv_email_imap4_cntx_struct *cntx_p);
static void srv_email_imap4_recv_fsm_done(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_recv_mail_fail(srv_email_imap4_cntx_struct *cntx_p);

static srv_email_nwk_fldr_list_struct *srv_email_imap4_add_fldr(
                                        srv_email_nwk_fldr_list_struct *header_p,
                                        srv_email_nwk_fldr_list_struct *fldr_p,
                                        MMI_BOOL *is_valid);
static MMI_BOOL srv_email_imap4_match_fldr(
                    srv_email_nwk_fldr_list_struct *header_p,
                    srv_email_stor_fldr_struct *fldr_p,
                    EMAIL_FLDR_ID fldr_id);

static srv_email_result_enum srv_email_imap4_list_fldr_fsm_init(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_list_fldr_fsm_server_listed(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_imap4_list_fldr_fsm_local_listed(srv_email_imap4_cntx_struct *cntx_p);
static void srv_email_imap4_list_fldr_fsm_done(srv_email_imap4_cntx_struct *cntx_p);

/* Sync related */
static FS_HANDLE imap4_sync_reqfile_open(WCHAR* filename);
static S32 imap4_sync_reqfile_write(FS_HANDLE fd, U32 id, U32 opt, U32 flags);
static S32 imap4_sync_reqfile_close(FS_HANDLE fd, U32 cnt);
static void imap4_sync_reqfile_delete(WCHAR* filename);
static void imap4_sync_get_command(srv_email_imap4_item_struct *item_p, U32 *opt, U32 *flags, MMI_BOOL *need_expunge);
static srv_email_result_enum imap4_sync_update_item(EMAIL_STOR_HANDLE stor_handle, srv_email_imap4_item_struct *record_p);

static srv_email_result_enum imap4_sync_init(srv_email_imap4_cntx_struct *cntx_p);
static srv_email_result_enum imap4_sync_update_local(srv_email_imap4_cntx_struct *cntx_p);
static void imap4_sync_done(srv_email_imap4_cntx_struct *cntx_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_parse_async_fs_callback
 * DESCRIPTION
 *  This function is used to handle the async FS operation when parsing content/attachment.
 * PARAMETERS
 *  job_id          [IN]        The async FS job id
 *  result          [IN]        The async FS operation's reault
 *  data            [IN]        The FS callback data
 * RETURNS
 *  The 
 *****************************************************************************/
static kal_int32 srv_email_imap4_parse_async_fs_callback(fs_job_id job_id, kal_int64 result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fs_async_callback_data_struct *fs_data = (fs_async_callback_data_struct*)data;
    srv_email_imap4_cntx_struct *cntx_p = (srv_email_imap4_cntx_struct*)fs_data->param;
    srv_email_comm_cntx_struct *comm_p = NULL;
    srv_email_imap4_state_struct *state_p = NULL;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_DECODE, cntx_p);

    if (srv_email_delete_fs_async_job(job_id))
    {
        return 0;
    }

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return 0;
    }

    comm_p = &cntx_p->common;
    state_p = &cntx_p->state;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE ||
        (state_p->parse_state != SRV_EMAIL_IMAP4_DECODE_CONTENT &&
         state_p->parse_state != SRV_EMAIL_IMAP4_DECODE_ATTACHMENT) ||
        state_p->async_fs_job_id != fs_data->id)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_RECEIVING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE);
        return 0;
    }

    state_p->async_fs_job_id = -1;

    if (result >= 0 && state_p->async_fs_data_len == state_p->async_fs_data_size)
    {
        srv_email_imap4_decode_base64_qprint(cntx_p);
    }
    else
    {
        state_p->parse_state = SRV_EMAIL_IMAP4_PARSE_NONE;

        srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_FS_ERROR, (S32)result, NULL);
        srv_email_imap4_recv_fsm(cntx_p);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_decode_base64_qprint
 * DESCRIPTION
 *  This function is used to decode the BASE64 and QPRINT.
 * PARAMETERS
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_decode_base64_qprint(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_cntx_struct *cntx_p = (srv_email_imap4_cntx_struct*)user_data;
    srv_email_comm_cntx_struct *comm_p = NULL;
    srv_email_imap4_state_struct *state_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FS_ERROR;
    MMI_BOOL is_valid = MMI_FALSE;
    WCHAR *fn = NULL;
    S32 enc_type = 0;
    U32 rw_size = 0;
    S32 enc_size = 0;
    S32 dec_size = 0;
    S32 ret = 0;
    S32 major = SRV_EMAIL_FS_ERROR;
    U32 offset = 2;
    U32 file_size = 0;
    fs_overlapped_struct fs_overlapped;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_DECODE, cntx_p);

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    comm_p = &cntx_p->common;
    state_p = &cntx_p->state;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE ||
        (state_p->parse_state != SRV_EMAIL_IMAP4_DECODE_CONTENT &&
         state_p->parse_state != SRV_EMAIL_IMAP4_DECODE_ATTACHMENT))
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

    if (state_p->parse_state == SRV_EMAIL_IMAP4_DECODE_CONTENT)
    {
        fn = state_p->curr_cont_p->filename;
        enc_type = srv_email_imap4_get_encode_type(state_p->curr_cont_p->cont.encoding);
    }
    else
    {
        fn = state_p->curr_att_p->filename;
        enc_type = srv_email_imap4_get_encode_type(state_p->curr_att_p->attach.encoding);
    }

    fs_overlapped.priority = FS_PRIORITY_DEFAULT;
    fs_overlapped.priority_value = 0;
    fs_overlapped.response_flag = 0;
    fs_overlapped.callback = srv_email_imap4_parse_async_fs_callback;
    fs_overlapped.param = cntx_p;
    fs_overlapped.buf = state_p->async_fs_work_buf;
    fs_overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;

    switch (state_p->async_fs_state)
    {
        case SRV_EMAIL_IMAP4_PARSE_READ_FILE:
            enc_size = (S32)state_p->async_fs_data_size;
            if (enc_type == EMAIL_MIME_ENCBASE64)
            {
                dec_size = applib_base64_part_decode_append(
                            state_p->base64_p,
                            state_p->async_fs_data_buf + offset,
                            &enc_size,
                            state_p->async_fs_data_buf,
                            SRV_EMAIL_IMAP4_DECODE_BUFF_SIZE);
            }
            else
            {
                dec_size = applib_qprint_part_decode_append(
                            state_p->qprint_p,
                            state_p->async_fs_data_buf + offset,
                            &enc_size,
                            state_p->async_fs_data_buf,
                            SRV_EMAIL_IMAP4_DECODE_BUFF_SIZE);
            }

            if (dec_size <= 0)
            {
                ret = FS_GetFileSize(state_p->dst_fd, &file_size);
                if (ret < 0)
                {
                    goto EXIT_HANDLE;
                }
                else
                {
                    goto DONE_HANDLE;
                }
            }

            state_p->curr_size += enc_size;

            rw_size = (U32)dec_size;
            ret = fs_async_write(
                    state_p->dst_fd,
                    state_p->async_fs_data_buf,
                    rw_size,
                    &state_p->async_fs_data_size,
                    &fs_overlapped);
            if (ret <= 0)
            {
                goto EXIT_HANDLE;
            }

            state_p->async_fs_job_id = (fs_job_id)ret;
            state_p->async_fs_data_len = rw_size;
            state_p->async_fs_state = SRV_EMAIL_IMAP4_PARSE_WRITE_FILE;
            return;

        case SRV_EMAIL_IMAP4_PARSE_WRITE_FILE:
            if (state_p->curr_size >= state_p->total_size)
            {
                ret = FS_GetFileSize(state_p->dst_fd, &file_size);
                if (ret < 0)
                {
                    goto EXIT_HANDLE;
                }
                else
                {
                    goto DONE_HANDLE;
                }
            }
            /* No break here */

        case SRV_EMAIL_IMAP4_PARSE_NONE:
            EMAILSRV_EXT_ASSERT(
                state_p->total_size > state_p->curr_size,
                state_p->total_size,
                state_p->curr_size,
                0);

            ret = FS_Seek(state_p->src_fd, state_p->curr_size, FS_FILE_BEGIN);
            if (ret < 0)
            {
                goto EXIT_HANDLE;
            }

            rw_size = state_p->total_size - state_p->curr_size;
            rw_size = SRV_EMAIL_MIN(rw_size, (SRV_EMAIL_IMAP4_DECODE_BUFF_SIZE - offset));

            ret = fs_async_read(
                    state_p->src_fd,
                    state_p->async_fs_data_buf + offset,
                    rw_size,
                    &state_p->async_fs_data_size,
                    &fs_overlapped);
            if (ret <= 0)
            {
                goto EXIT_HANDLE;
            }

            state_p->async_fs_job_id = (fs_job_id)ret;
            state_p->async_fs_data_len = rw_size;
            state_p->async_fs_state = SRV_EMAIL_IMAP4_PARSE_READ_FILE;
            return;

        default:
            EMAILSRV_EXT_ASSERT(0, state_p->async_fs_state, 0, 0);
            break;
    }

DONE_HANDLE:
    FS_Close(state_p->src_fd);
    state_p->src_fd = -1;
    FS_Close(state_p->dst_fd);
    state_p->dst_fd = -1;

    FS_Delete(fn);
    ret = FS_Rename(state_p->filename, fn);
    if (ret >= 0)
    {
        retval = SRV_EMAIL_RESULT_SUCC;
    }

EXIT_HANDLE:
    if (state_p->async_fs_data_buf)
    {
        srv_email_mem_free(state_p->async_fs_data_buf);
        state_p->async_fs_data_buf = NULL;
    }
    if (state_p->async_fs_work_buf)
    {
        srv_email_mem_free(state_p->async_fs_work_buf);
        state_p->async_fs_work_buf = NULL;
    }

    if (state_p->base64_p)
    {
        srv_email_mem_free(state_p->base64_p);
        state_p->base64_p = NULL;
    }
    if (state_p->qprint_p)
    {
        srv_email_mem_free(state_p->qprint_p);
        state_p->qprint_p = NULL;
    }

    if (state_p->src_fd >= 0)
    {
        FS_Close(state_p->src_fd);
        state_p->src_fd = -1;
    }
    if (state_p->dst_fd >= 0)
    {
        FS_Close(state_p->dst_fd);
        state_p->dst_fd = -1;
    }

    FS_Delete(state_p->filename);
    state_p->total_size = 0;
    state_p->curr_size = 0;

#ifdef __DRM_SUPPORT__
    if (retval == SRV_EMAIL_RESULT_SUCC &&
        file_size > 0 &&
        state_p->parse_state == SRV_EMAIL_IMAP4_DECODE_ATTACHMENT)
    {
        srv_email_attach_list_struct *attach_p = state_p->curr_att_p;
        applib_mime_type_struct *mime_p = NULL;
        U8 serial = 0;

        mime_p = applib_mime_type_look_up(
                    (kal_char*)attach_p->attach.content_type,
                    NULL,
                    MIME_TYPE_NONE,
                    MIME_SUBTYPE_NONE);
        if (mime_p &&
            mime_p->mime_type == MIME_TYPE_APPLICATION &&
            (mime_p->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
            mime_p->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE))
        {
            ret = DRM_install_object(
                    (U8*)attach_p->attach.content_type,
                    attach_p->filename,
                    MMI_FALSE,
                    state_p->filename,
                    (SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1) * 2,
                    &serial,
                    &mime_p,
                    srv_email_imap4_parse_drm_done);

            if (ret == DRM_RESULT_OK)
            {
                FS_Delete(attach_p->filename);
                ret = FS_Rename(state_p->filename, attach_p->filename);
                if (ret >= 0)
                {
                    attach_p->attach.drm = MMI_TRUE;
                    if (mime_p)
                    {
                        strcpy(attach_p->attach.drm_content_type, mime_p->mime_string);
                        srv_email_transform_filename(
                            attach_p->attach.file_name,
                            attach_p->attach.file_name,
                            EMAIL_STOR_ENCOD_FILE_NAME_LEN + 1,
                            mime_p->file_ext);
                    }
                    else
                    {
                        srv_email_transform_filename(
                            attach_p->attach.file_name,
                            attach_p->attach.file_name,
                            EMAIL_STOR_ENCOD_FILE_NAME_LEN + 1,
                            "tmp");
                    }
                }
                else
                {
                    retval = SRV_EMAIL_RESULT_FS_ERROR;
                }
            }
            else if (ret == DRM_PROC_ENCRYPT_BUSY)
            {
                state_p->parse_state = SRV_EMAIL_IMAP4_PARSE_DRM;
                state_p->drm_serial = serial;
                return;
            }
            else
            {
                /* Parse DRM unsuccessfully, process it as normal attachment */
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_PARSE_DRM, cntx_p, ret);
            }
        }
    }
#endif /* __DRM_SUPPORT__ */

    state_p->parse_state = SRV_EMAIL_IMAP4_PARSE_NONE;

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_set_error_cause(&comm_p->result, major, ret, NULL);
    }

    srv_email_imap4_recv_fsm(cntx_p);
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_parse_drm_done
 * DESCRIPTION
 *  This function is used to process the result of parsing DRM object.
 * PARAMETERS
 *  serial          [IN]        The serial
 *  result          [IN]        The result of parsing
 *  mime_type       [IN]        The pointer point to the mime type of the media object
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_parse_drm_done(U8 serial, S32 result, applib_mime_type_struct *mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_cntx_struct *cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    srv_email_imap4_state_struct *state_p = NULL;
    srv_email_attach_list_struct *attach_p = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_PARSE_DRM, cntx_p, result);

    cntx_p = (srv_email_imap4_cntx_struct*)srv_email_nwk_get_cntx_list();
    while (cntx_p)
    {
        if (cntx_p->common.protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4 &&
            cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_RECEIVING &&
            cntx_p->sub_state == SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE &&
            cntx_p->state.parse_state == SRV_EMAIL_IMAP4_PARSE_DRM &&
            cntx_p->state.drm_serial == serial)
        {
            break;
        }

        cntx_p = (srv_email_imap4_cntx_struct*)cntx_p->next;
    }

    if (!cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_INVALID_DRM_SERIAL, cntx_p, serial);
        return;
    }

    comm_p = &cntx_p->common;
    state_p = &cntx_p->state;
    attach_p = state_p->curr_att_p;
    EMAILSRV_ASSERT(attach_p);

    state_p->drm_serial = 0;
    state_p->parse_state = SRV_EMAIL_IMAP4_PARSE_NONE;

    if (result == DRM_RESULT_OK)
    {
        FS_Delete(attach_p->filename);
        ret = FS_Rename(state_p->filename, attach_p->filename);
        if (ret < 0)
        {
            srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_FS_ERROR, ret, NULL);
        }
        else
        {
            attach_p->attach.drm = MMI_TRUE;
            if (mime_type)
            {
                strcpy(attach_p->attach.drm_content_type, mime_type->mime_string);
                srv_email_transform_filename(
                    attach_p->attach.file_name,
                    attach_p->attach.file_name,
                    EMAIL_STOR_ENCOD_FILE_NAME_LEN + 1,
                    mime_type->file_ext);
            }
            else
            {
                srv_email_transform_filename(
                    attach_p->attach.file_name,
                    attach_p->attach.file_name,
                    EMAIL_STOR_ENCOD_FILE_NAME_LEN + 1,
                    "tmp");
            }
        }
    }
    else
    {
        /* Parse DRM unsuccessfully, process it as normal attachment */
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_PARSE_DRM, cntx_p, result);
    }

    srv_email_imap4_recv_fsm(cntx_p);
}
#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_abort_parse
 * DESCRIPTION
 *  This function is used to abort the parsing.
 * PARAMETERS
 *  state_p         [IN]        The pointer point to the state structure
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_abort_parse(srv_email_imap4_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_PARSE_ABORT, state_p->parse_state);

    switch (state_p->parse_state)
    {
        case SRV_EMAIL_IMAP4_DECODE_CONTENT:
        case SRV_EMAIL_IMAP4_DECODE_ATTACHMENT:
            FS_Close(state_p->src_fd);
            state_p->src_fd = -1;
            FS_Close(state_p->dst_fd);
            state_p->dst_fd = -1;
            FS_Delete(state_p->filename);

            if (state_p->base64_p)
            {
                srv_email_mem_free(state_p->base64_p);
                state_p->base64_p = NULL;
            }

            if (state_p->qprint_p)
            {
                srv_email_mem_free(state_p->qprint_p);
                state_p->qprint_p = NULL;
            }

            srv_email_fs_async_abort(
                &state_p->async_fs_job_id,
                (void**)&state_p->async_fs_work_buf,
                (void**)&state_p->async_fs_data_buf);
            break;

    #ifdef __DRM_SUPPORT__
        case SRV_EMAIL_IMAP4_PARSE_DRM:
            DRM_async_cancel_process(state_p->drm_serial);
            state_p->drm_serial = 0;
            break;
    #endif /* __DRM_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_session_init
 * DESCRIPTION
 *  This function is used to initialize the IMAP4 session.
 * PARAMETERS
 *  sess_p          [IN]        The pointer point to the IMAP4 session
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_session_init(srv_email_imap4_session_struct *sess_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(sess_p, 0, sizeof(srv_email_imap4_session_struct));

    sess_p->fldr_id = EMAIL_FLDR_INVALID_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_session_free
 * DESCRIPTION
 *  This function is used to free the IMAP4 session.
 * PARAMETERS
 *  sess_p          [IN]        The pointer point to the IMAP4 session
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_session_free(srv_email_imap4_session_struct *sess_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_item_struct *ptr = NULL;

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

    srv_email_imap4_session_init(sess_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_state_init
 * DESCRIPTION
 *  This function is used to initialize the IMAP4 state.
 * PARAMETERS
 *  state_p         [IN]        The pointer point to the state structure
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_state_init(srv_email_imap4_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(state_p, 0, sizeof(srv_email_imap4_state_struct));

    state_p->stor_handle = EMAIL_STOR_INVALID_HANDLE;
    state_p->last_msg_id = EMAIL_MSG_INVALID_ID;
    state_p->msg_create_handle = EMAIL_STOR_INVALID_HANDLE;

    state_p->src_fd = -1;
    state_p->dst_fd = -1;
    state_p->async_fs_job_id = -1;

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

    state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_state_free
 * DESCRIPTION
 *  This function is used to free the IMAP4 state.
 * PARAMETERS
 *  state_p         [IN]        The pointer point to the state structure
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_state_free(srv_email_imap4_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_fldr_list_struct *fldr_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state_p->stor_handle != EMAIL_STOR_INVALID_HANDLE)
    {
        srv_email_stor_fldr_sync_msg_close(&state_p->stor_handle);
    }
    if (state_p->msg_create_handle != EMAIL_STOR_INVALID_HANDLE)
    {
        srv_email_stor_msg_create_abort(state_p->msg_create_handle);
    }

    if (state_p->msg_env_p)
    {
        srv_email_imap4_free_envelope(&state_p->msg_env_p);
    }

    while (state_p->fldr_list_p)
    {
        fldr_p = state_p->fldr_list_p;
        state_p->fldr_list_p = fldr_p->next;
        srv_email_mem_free(fldr_p);
    }

    if (state_p->src_fd >= 0)
    {
        FS_Close(state_p->src_fd);
    }

    if (state_p->dst_fd >= 0)
    {
        FS_Close(state_p->dst_fd);
    }

    if (state_p->base64_p)
    {
        srv_email_mem_free(state_p->base64_p);
    }

    if (state_p->qprint_p)
    {
        srv_email_mem_free(state_p->qprint_p);
    }

#ifdef __DRM_SUPPORT__
    if (state_p->drm_serial)
    {
        DRM_async_cancel_process(state_p->drm_serial);
    }
#endif /* __DRM_SUPPORT__ */

    srv_email_fs_async_abort(
        &state_p->async_fs_job_id,
        (void**)&state_p->async_fs_work_buf,
        (void**)&state_p->async_fs_data_buf);

    if (state_p->fldr_filename)
    {
        srv_email_mem_free(state_p->fldr_filename);
    }

    FS_Delete((const WCHAR*)state_p->req_filename);
    FS_Delete((const WCHAR*)state_p->rsp_filename);

    srv_email_imap4_state_init(state_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_make_req_file
 * DESCRIPTION
 *  This function is used to make the request file.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  action          [IN]        The request type
 * RETURNS
 *  MMI_TRUE or MMI_FALSE.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_make_req_file(
                                srv_email_imap4_cntx_struct *cntx_p,
                                srv_email_imap4_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_imap4_item_struct *record_p = sess_p->list.record;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    S32 flag_mask = 0;
    MMI_BOOL need_and = MMI_FALSE;
    U32 flag = 0;
    FS_HANDLE fd = -1;
    S32 ret = 0;
    U32 wbyte = 0;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (action)
    {
        case SRV_EMAIL_IMAP4_GET_FLAG:
            flag_mask = SRV_EMAIL_NWK_FLAG_FLAG_VALID;
            need_and = MMI_FALSE;
            break;

        case SRV_EMAIL_IMAP4_SET_FLAG:
            flag_mask = SRV_EMAIL_NWK_FLAG_UPDATE_SERVER;
            need_and = MMI_TRUE;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, action, 0, 0);
            break;
    }

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
        if ((need_and && (record_p->nwk_flag & flag_mask)) ||
            (!need_and && !(record_p->nwk_flag & flag_mask)))
        {
            ret = FS_Write(fd, &record_p->uid, 4, &wbyte);
            if (ret < 0 || wbyte != 4)
            {
                goto EXIT_HANDLE;
            }

            if (action == SRV_EMAIL_IMAP4_SET_FLAG)
            {
                if ((record_p->msg_flag & EMAIL_MSG_FLAG_SEEN))
                {
                    flag = EMAIL_PS_MESSAGE_ATTR_READED;
                }
                else
                {
                    flag = 0;
                }

                ret = FS_Write(fd, &flag, 4, &wbyte);
                if (ret < 0 || wbyte != 4)
                {
                    goto EXIT_HANDLE;
                }
            }

            count++;

            if (count >= SRV_EMAIL_GET_NUM_PER_TIME)
            {
                break;
            }
        }

        record_p = record_p->next;
    }

    EMAILSRV_ASSERT(count > 0);

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
        return SRV_EMAIL_RESULT_FAIL;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_attach
 * DESCRIPTION
 *  This function is used to list the attachments of the specified email.
 * PARAMETERS
 *  msg_id          [IN]        The email id
 *  attach_list_p   [IN/OUT]    The address of the pointer point to the attachment list
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_list_attach(
                                EMAIL_MSG_ID msg_id,
                                srv_email_attach_list_struct **attach_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_attach_list_struct *attach_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_STOR_HANDLE handle = EMAIL_STOR_INVALID_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retval = srv_email_stor_msg_get_attch_open(msg_id, 0, &handle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_GET_ATTACH_OPEN, msg_id, retval);
        return retval;
    }

    while (1)
    {
        attach_p = (srv_email_attach_list_struct*)srv_email_mem_alloc(sizeof(srv_email_attach_list_struct));
        if (!attach_p)
        {
            retval = SRV_EMAIL_RESULT_NO_MEMORY;
            goto EXIT_HANDLE;
        }
        memset(attach_p, 0, sizeof(srv_email_attach_list_struct));

        retval = srv_email_stor_msg_get_attch_next(handle, &attach_p->attach);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            if (!attach_p->attach.download_flag)
            {
                attach_p->attach_id = attach_p->attach.attch_id;
                attach_p->filename[0] = 0;

                *attach_list_p = srv_email_imap4_add_attach(*attach_list_p, attach_p);
            }
            else
            {
                srv_email_mem_free(attach_p);
            }
        }
        else if (retval == SRV_EMAIL_RESULT_NO_MORE_RESULT)
        {
            srv_email_mem_free(attach_p);
            break;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_GET_ATTACH_NEXT, retval);
            srv_email_mem_free(attach_p);
            goto EXIT_HANDLE;
        }
    }

    retval = SRV_EMAIL_RESULT_SUCC;

EXIT_HANDLE:

    srv_email_stor_msg_get_attch_close(handle);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_add_record
 * DESCRIPTION
 *  This function is used to insert a record into the list by the email sequence number.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  record_p        [IN]        The pointer point to the record
 * RETURNS
 *  MMI_TRUE/MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_email_imap4_add_record(
                    srv_email_imap4_list_struct *list_p,
                    srv_email_imap4_item_struct *record_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_item_struct *curr_p = NULL;

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
 *  srv_email_imap4_get_record_by_uid
 * DESCRIPTION
 *  This function is used to get the record by the specified uid.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  uid             [IN]        The uid
 * RETURNS
 *  The pointer point to the record.
 *****************************************************************************/
static srv_email_imap4_item_struct *srv_email_imap4_get_record_by_uid(
                                        srv_email_imap4_list_struct *list_p,
                                        U32 uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_item_struct *curr_p = list_p->record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(uid > 0, uid, 0, 0);

    while (curr_p)
    {
        if (curr_p->uid == uid)
        {
            return curr_p;
        }

        curr_p = curr_p->next;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_get_record_by_msgid
 * DESCRIPTION
 *  This function is used to get the record by the specified email local id.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  msg_id          [IN]        The email local id
 * RETURNS
 *  The pointer point to the record.
 *****************************************************************************/
static srv_email_imap4_item_struct *srv_email_imap4_get_record_by_msgid(
                                        srv_email_imap4_list_struct *list_p,
                                        EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_item_struct *curr_p = list_p->record;

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
 *  srv_email_imap4_get_next_new_msg
 * DESCRIPTION
 *  This function is used to get the record of the next new email.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  curr_rec_p      [IN]        The pointer point to the current record
 * RETURNS
 *  The pointer point to the record.
 *****************************************************************************/
static srv_email_imap4_item_struct *srv_email_imap4_get_next_new_msg(
                                        srv_email_imap4_list_struct *list_p,
                                        srv_email_imap4_item_struct *curr_rec_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_item_struct *curr_p = NULL;

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
 *  srv_email_imap4_calc_new_msg
 * DESCRIPTION
 *  This function is used to calculate the new email number.
 * PARAMETERS
 *  list_p          [IN]        The pointer point to the list
 *  retrieve_amount [IN]        The retrieve amount
 * RETURNS
 *  The email number that can be downloaded.
 *****************************************************************************/
static U32 srv_email_imap4_calc_new_msg(srv_email_imap4_list_struct *list_p, U32 retrieve_amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_item_struct *curr_p = NULL;
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
 *  srv_email_imap4_read_data
 * DESCRIPTION
 *  This function is used to read the two data from file.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  data1           [OUT]       Used to store the data1
 *  data2           [OUT]       Used to store the data2
 * RETURNS
 *  The FS code.
 *****************************************************************************/
static S32 srv_email_imap4_read_data(FS_HANDLE fd, U32 *data1, U32 *data2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rbyte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Read(fd, data1, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    ret = FS_Read(fd, data2, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_uid
 * DESCRIPTION
 *  This function is used to read the server email uid.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  msg_seq_no      [OUT]       Used to store the sequence number
 *  msg_uid         [OUT]       Used to store the uid
 * RETURNS
 *  The FS code.
 *****************************************************************************/
static S32 srv_email_imap4_read_uid(FS_HANDLE fd, U32 *msg_seq_no, U32 *msg_uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 seq_no;
    U32 uid;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_email_imap4_read_data(fd, &seq_no, &uid);
    if (ret < 0)
    {
        return ret;
    }

    if (msg_seq_no)
    {
        *msg_seq_no = seq_no;
    }

    if (msg_uid)
    {
        *msg_uid = uid;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_size
 * DESCRIPTION
 *  This function is used to read the server email size.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  msg_seq_no      [OUT]       Used to store the sequence number
 *  msg_size        [OUT]       Used to store the email size
 * RETURNS
 *  The FS code.
 *****************************************************************************/
static S32 srv_email_imap4_read_size(FS_HANDLE fd, U32 *msg_seq_no, U32 *msg_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 seq_no;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_email_imap4_read_data(fd, &seq_no, &size);
    if (ret < 0)
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
 *  srv_email_imap4_read_flag
 * DESCRIPTION
 *  This function is used to read the server email flag.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  msg_uid         [OUT]       Used to store the sequence number
 *  msg_flag        [OUT]       Used to store the email flag
 * RETURNS
 *  The FS code.
 *****************************************************************************/
static S32 srv_email_imap4_read_flag(FS_HANDLE fd, U32 *msg_uid, U32 *msg_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 uid;
    U32 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_email_imap4_read_data(fd, &uid, &flag);
    if (ret < 0)
    {
        return ret;
    }

    /* Currently, we support the READED and DELETED flags only */
    flag &= EMAIL_PS_MESSAGE_ATTR_READED | EMAIL_PS_MESSAGE_ATTR_DELETE;

    if (msg_uid)
    {
        *msg_uid = uid;
    }

    if (msg_flag)
    {
        *msg_flag = flag;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_uid
 * DESCRIPTION
 *  This function is used to list the server email uids.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_list_uid(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_imap4_item_struct *record_p = NULL;
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
        minor = SRV_EMAIL_RESULT_IMAP4_CMD_ERROR;
        goto EXIT_HANDLE;
    }

    //count = SRV_EMAIL_MIN(count, SRV_EMAIL_GET_NUM_PER_TIME);

    for (i = 0; i < count; i++)
    {
        record_p = (srv_email_imap4_item_struct*)srv_email_mem_alloc(sizeof(srv_email_imap4_item_struct));
        if (!record_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto EXIT_HANDLE;
        }

        memset(record_p, 0, sizeof(srv_email_imap4_item_struct));

        minor = srv_email_imap4_read_uid(fd, &record_p->seq_no, &record_p->uid);
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

        ret = srv_email_imap4_add_record(&sess_p->list, record_p);
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
        minor = SRV_EMAIL_RESULT_IMAP4_CMD_ERROR;
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
 *  srv_email_imap4_list_size
 * DESCRIPTION
 *  This function is used to list the server email sizes.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_list_size(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_imap4_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    FS_HANDLE fd = -1;
    U32 rbyte = 0;
    U32 count = 0;
    U32 uid = 0;
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
        minor = SRV_EMAIL_RESULT_IMAP4_CMD_ERROR;
        goto EXIT_HANDLE;
    }

    //count = SRV_EMAIL_MIN(count, SRV_EMAIL_GET_NUM_PER_TIME);

    for (i = 0; i < count; i++)
    {
        minor = srv_email_imap4_read_size(fd, &uid, &size);
        if (minor < 0)
        {
            goto EXIT_HANDLE;
        }

        record_p = srv_email_imap4_get_record_by_uid(&sess_p->list, uid);
        if (record_p)
        {
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
    }

    if (valid_count != state_p->list_count ||
        min_seq_no != min_req_seq ||
        max_seq_no != max_req_seq)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_IMAP4_CMD_ERROR;
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
 *  srv_email_imap4_list_flag
 * DESCRIPTION
 *  This function is used to list the server email flags.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_list_flag(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_imap4_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    FS_HANDLE fd = -1;
    U32 rbyte = 0;
    U32 count = 0;
    U32 uid = 0;
    U32 flag = 0;
    U32 i = 0;

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

    count = SRV_EMAIL_MIN(count, SRV_EMAIL_GET_NUM_PER_TIME);

    for (i = 0; i < count; i++)
    {
        minor = srv_email_imap4_read_flag(fd, &uid, &flag);
        if (minor < 0)
        {
            goto EXIT_HANDLE;
        }

        record_p = srv_email_imap4_get_record_by_uid(&sess_p->list, uid);
        if (record_p)
        {
            if (flag & EMAIL_PS_MESSAGE_ATTR_READED)
            {
                record_p->msg_flag |= EMAIL_MSG_FLAG_SEEN;
            }
            if (flag & EMAIL_PS_MESSAGE_ATTR_DELETE)
            {
                record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_DELETE_LOCAL;
            }
            record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_FLAG_VALID;
        }

        state_p->curr_count++;
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
 *  srv_email_imap4_match_msg
 * DESCRIPTION
 *  This function is used to match the local and server emails.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  msg_info_p      [IN]        The pointer point to the local email information
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_match_msg(
                        srv_email_imap4_cntx_struct *cntx_p,
                        srv_email_stor_fldr_get_msg_id_struct *msg_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_imap4_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sess_p->uid_validity == msg_info_p->uid_validity &&
        !memcmp(msg_info_p->acct_digest, comm_p->acct_digest, SRV_EMAIL_MD5_DIGEST_LEN))
    {
        record_p = srv_email_imap4_get_record_by_uid(&sess_p->list, msg_info_p->uid);
    }

    if (record_p)
    {
        record_p->msg_id = msg_info_p->msg_id;
        record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_IN_LOCAL;

        /* Currently, we support READ/UNREAD flag only */
        msg_info_p->flag_latest &= EMAIL_MSG_FLAG_SEEN;
        msg_info_p->flag_orig &= EMAIL_MSG_FLAG_SEEN;

        if (msg_info_p->flag_latest != msg_info_p->flag_orig ||
            msg_info_p->flag_latest != record_p->msg_flag)
        {
            record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_UPDATE_LOCAL;
        }

        if (msg_info_p->flag_latest != msg_info_p->flag_orig &&
            msg_info_p->flag_latest != record_p->msg_flag)
        {
            record_p->msg_flag = msg_info_p->flag_latest;
            record_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_UPDATE_SERVER;
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
                SRV_EMAIL_ERROR_IMAP4_STOR_SYNC_MSG_DEL,
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
 *  srv_email_imap4_load_local_msg
 * DESCRIPTION
 *  This function is used to load the local emails.
 * PARAMETERS
 *  user_data       [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_load_local_msg(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_cntx_struct *cntx_p = (srv_email_imap4_cntx_struct*)user_data;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_LOAD_LOCAL_MSG, cntx_p);

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

        srv_email_imap4_update_fsm(cntx_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_fsm_init
 * DESCRIPTION
 *  This function is used to initialize the IMAP4 UPDATE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_update_fsm_init(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_stor_fldr_struct *fldr_info_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_FLDR_ID inbox = EMAIL_FLDR_INVALID_ID;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_UPDATE_FSM_INIT, cntx_p, sess_p->fldr_id);

    inbox = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

    if (sess_p->fldr_id == inbox)
    {
        srv_email_ps_open_folder_req(cntx_p->common.ps_handle, SRV_EMAIL_INBOX_NAME);
    }
    else
    {
        fldr_info_p = (srv_email_stor_fldr_struct*)OslMalloc(sizeof(srv_email_stor_fldr_struct));

        retval = srv_email_stor_fldr_get_by_id(comm_p->acct_id, sess_p->fldr_id, fldr_info_p);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_GET_FLDR_INFO, cntx_p, sess_p->fldr_id, retval);

            OslMfree(fldr_info_p);
            srv_email_get_stor_error(retval, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
            return SRV_EMAIL_RESULT_FAIL;
        }

        srv_email_ps_open_folder_req(
            cntx_p->common.ps_handle,
            (const CHAR*)fldr_info_p->fldr_name);

        OslMfree(fldr_info_p);
    }

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_fsm_fldr_opened
 * DESCRIPTION
 *  This function is used to process the case that opening folder successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_update_fsm_fldr_opened(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_UPDATE_FSM_FLDR_OPENED, cntx_p, sess_p->total_msg_num);

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

        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        state_p->curr_count = 0;
        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_fsm_uid_listed
 * DESCRIPTION
 *  This function is used to process the case that listing server email uids successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_update_fsm_uid_listed(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_IMAP4_UPDATE_FSM_UID_LISTED,
        cntx_p,
        state_p->curr_count,
        state_p->total_count);

    retval = srv_email_imap4_list_uid(cntx_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_LIST_UID, cntx_p, retval);
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

        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE);
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_fsm_size_listed
 * DESCRIPTION
 *  This function is used to process the case that listing email sizes successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_update_fsm_size_listed(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_IMAP4_UPDATE_FSM_SIZE_LISTED,
        cntx_p,
        state_p->curr_count,
        state_p->total_count);

    retval = srv_email_imap4_list_size(cntx_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_LIST_SIZE, cntx_p, retval);
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
    }
    else
    {
        state_p->curr_count = 0;
        state_p->start_index = 1;

        retval = srv_email_imap4_make_req_file(cntx_p, SRV_EMAIL_IMAP4_GET_FLAG);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_MAKE_REQ_FILE, cntx_p, retval);
            return retval;
        }

        srv_email_ps_get_flag_req(
            comm_p->ps_handle,
            (const WCHAR*)state_p->req_filename,
            (const WCHAR*)state_p->rsp_filename);

        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_FLAG);
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_fsm_flag_listed
 * DESCRIPTION
 *  This function is used to process the case that listing email flags successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_update_fsm_flag_listed(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_IMAP4_UPDATE_FSM_FLAG_LISTED,
        cntx_p,
        state_p->curr_count,
        state_p->total_count);

    retval = srv_email_imap4_list_flag(cntx_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_LIST_FLAG, cntx_p, retval);
        return retval;
    }

    if (state_p->total_count > state_p->curr_count)
    {
        retval = srv_email_imap4_make_req_file(cntx_p, SRV_EMAIL_IMAP4_GET_FLAG);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_MAKE_REQ_FILE, cntx_p, retval);
            return retval;
        }

        srv_email_ps_get_flag_req(
            comm_p->ps_handle,
            (const WCHAR*)state_p->req_filename,
            (const WCHAR*)state_p->rsp_filename);

        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        state_p->curr_count = 0;
        state_p->start_index = 0;

        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL);

        return SRV_EMAIL_RESULT_SUCC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_fsm_local_updated
 * DESCRIPTION
 *  This function is used to process the case that updating local emails successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_update_fsm_local_updated(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_stor_fldr_get_msg_id_struct *msg_info_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_WOULDBLOCK;
    S32 count = 0;
    S32 major = 0;
    S32 minor = 0;
    EMAIL_STOR_HANDLE stor_handle = EMAIL_STOR_INVALID_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_UPDATE_FSM_LOCAL_UPDATED, cntx_p);

    if (state_p->curr_count)
    {
        retval = srv_email_stor_fldr_sync_msg_open_ext(
                    comm_p->acct_id,
                    sess_p->fldr_id,
                    &stor_handle,
                    state_p->last_msg_id);
    }
    else
    {
        retval = srv_email_stor_fldr_sync_msg_open(comm_p->acct_id, sess_p->fldr_id, &stor_handle);
    }

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_SYNC_MSG_OPEN, cntx_p, sess_p->fldr_id, retval);

        srv_email_get_stor_error(retval, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

    state_p->stor_handle = stor_handle;

    msg_info_p = (srv_email_stor_fldr_get_msg_id_struct*)
        OslMalloc(sizeof(srv_email_stor_fldr_get_msg_id_struct));

    for (count = 0; count < SRV_EMAIL_IMAP4_LIST_NUM_PER_TIME; count++)
    {
        retval = srv_email_stor_fldr_sync_msg_get_next(state_p->stor_handle, msg_info_p);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            retval = srv_email_imap4_match_msg(cntx_p, msg_info_p);
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
            SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_DONE);
            retval = SRV_EMAIL_RESULT_SUCC;
            break;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_SYNC_MSG_GET_NEXT, cntx_p, retval);

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
        srv_email_nwk_start_job(srv_email_imap4_load_local_msg, (srv_email_nwk_cntx_struct*)cntx_p);
        retval = SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_fsm_done
 * DESCRIPTION
 *  This function is used to process the case that updating connection successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static void srv_email_imap4_update_fsm_done(srv_email_imap4_cntx_struct *cntx_p)
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
        SRV_EMAIL_FUNC_IMAP4_UPDATE_FSM_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    if (!result_p->result)
    {
        srv_email_imap4_session_free(&cntx_p->session);
    }
    else
    {
        cntx_p->session.sync_with_server = MMI_TRUE;
    }

    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    srv_email_imap4_state_free(&cntx_p->state);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_query_text
 * DESCRIPTION
 *  This function is used to query the content information of the mail.
 * PARAMETERS
 *  type            [IN]        The content type
 *  cont_header     [OUT]       Used to store the content header
 *  buff            [OUT]       Used to store the content file path or content
 *  buff_size       [IN]        The size of the path_buff
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_query_text(
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
    srv_email_imap4_cntx_struct *cntx_p = (srv_email_imap4_cntx_struct*)user_data;
    srv_email_imap4_state_struct *state_p = NULL;
    srv_email_msg_env_struct *msg_env_p = NULL;
    srv_email_cont_list_struct *cont_p = NULL;
    srv_email_stor_msg_cont_type cont_type = SRV_EMAIL_STOR_MSG_CONT_TEXT;
    MMI_BOOL is_valid = MMI_FALSE;
    U32 len = 0;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_STOR_QUERY_TEXT, cntx_p, type);

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_RECEIVING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE);
        return;
    }

    state_p = &cntx_p->state;
    msg_env_p = state_p->msg_env_p;

    switch (type)
    {
        case SRV_EMAIL_MSG_TEXT_SUBJ:
        {
            if (msg_env_p->subject_p)
            {
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
#else /* 0 */
                {
                    CHAR *subj_p = (CHAR*)buff;

                    len = msg_env_p->msg_header_p->subj_len;
                    if (len + 1 > buff_size)
                    {
                        len = buff_size - 1;
                    }

                    memcpy(subj_p, msg_env_p->subject_p, len);
                    subj_p[len] = '\0';
                }
#endif /* 0 */
            }

            break;
        }

        case SRV_EMAIL_MSG_TEXT_CONT_HTML:
            cont_type = SRV_EMAIL_STOR_MSG_CONT_HTML;
            /* No break here */

        case SRV_EMAIL_MSG_TEXT_CONT_TEXT:
            cont_p = msg_env_p->cont_p;

            while (cont_p)
            {
                if (cont_p->type == cont_type)
                {
                    break;
                }

                cont_p = cont_p->next;
            }

            if (cont_p)
            {
                memcpy(cont_header, &cont_p->cont, sizeof(srv_email_stor_cont_header_struct));

                len = mmi_ucs2strlen((const CHAR*)cont_p->filename);
                EMAILSRV_EXT_ASSERT((len + 1) * 2 <= buff_size, len, buff_size, 0);
                mmi_ucs2cpy((CHAR*)buff, (const CHAR*)cont_p->filename);
            }
            *keep_src = 0;

            break;

        default:
            EMAILSRV_EXT_ASSERT(0, type, 0, 0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_query_addr
 * DESCRIPTION
 *  This function is used to query the email address information of the mail.
 * PARAMETERS
 *  type            [IN]        The address type
 *  index           [IN]        The address index
 *  data            [OUT]       Used to store the address information
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_query_addr(
                srv_email_addr_type_enum type,
                U16 index,
                srv_email_stor_addr_struct *data,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_cntx_struct *cntx_p = (srv_email_imap4_cntx_struct*)user_data;
    srv_email_imap4_state_struct *state_p = NULL;
    srv_email_msg_env_struct *msg_env_p = NULL;
    srv_email_addr_list_struct *addr_list_p = NULL;
    srv_email_stor_addr_struct *addr_p = NULL;
    MMI_BOOL is_valid = MMI_FALSE;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_STOR_QUERY_ADDR, cntx_p, type, index);

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_RECEIVING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE);
        return;
    }

    state_p = &cntx_p->state;
    msg_env_p = state_p->msg_env_p;
    addr_p = msg_env_p->from_p;

    switch (type)
    {
        case SRV_EMAIL_ADDR_TYPE_REPLY_TO:
            addr_p = msg_env_p->reply_to_p;
            /* No break here */

        case SRV_EMAIL_ADDR_TYPE_FROM:
            if (addr_p)
            {
                memcpy(data, addr_p, sizeof(srv_email_stor_addr_struct));
            }
            return;

        case SRV_EMAIL_ADDR_TYPE_TO:
            addr_list_p = msg_env_p->to_addr_p;
            break;

        case SRV_EMAIL_ADDR_TYPE_CC:
            addr_list_p = msg_env_p->cc_addr_p;
            break;

        case SRV_EMAIL_ADDR_TYPE_BCC:
            addr_list_p = msg_env_p->bcc_addr_p;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, type, 0, 0);
            break;
    }

    while (addr_list_p)
    {
        if (i >= index)
        {
            break;
        }

        addr_list_p = addr_list_p->next;
        i++;
    }

    if (addr_list_p)
    {
        memcpy(data, &addr_list_p->addr, sizeof(srv_email_stor_addr_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_query_attach
 * DESCRIPTION
 *  This function is used to query the attachment information of the mail.
 * PARAMETERS
 *  index           [IN]        The attachment index
 *  buff            [OUT]       Used to store the attachment header or file path
 *  buff_size       [IN]        The size of the buff
 *  type            [IN]        The type of the buff
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_query_attach(
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
    srv_email_imap4_cntx_struct *cntx_p = (srv_email_imap4_cntx_struct*)user_data;
    srv_email_imap4_state_struct *state_p = NULL;
    srv_email_msg_env_struct *msg_env_p = NULL;
    srv_email_attach_list_struct *attach_list_p = NULL;
    MMI_BOOL is_valid = MMI_FALSE;
    U32 len = 0;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_STOR_QUERY_ATTACH, cntx_p, index);

    if (keep_src != NULL)
    {
        *keep_src = 0;
    }
    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_RECEIVING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE);
        return;
    }

    state_p = &cntx_p->state;
    msg_env_p = state_p->msg_env_p;
    attach_list_p = msg_env_p->attach_p;

    while (attach_list_p)
    {
        if (i >= index)
        {
            break;
        }

        attach_list_p = attach_list_p->next;
        i++;
    }

    if (attach_list_p)
    {
        if (type == SRV_EMAIL_STOR_ATTCH_QUERY_PATH)
        {
            len = mmi_ucs2strlen((const CHAR*)attach_list_p->filename);
            EMAILSRV_EXT_ASSERT((len + 1) * 2 < buff_size, len, buff_size, 0);
            mmi_ucs2cpy((CHAR*)buff, (const CHAR*)attach_list_p->filename);
        }
        else
        {
            memcpy(buff, &attach_list_p->attach, sizeof(srv_email_stor_attch_struct));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_save_done
 * DESCRIPTION
 *  This function is used to process the result of saving email.
 * PARAMETERS
 *  result          [IN]        The result of saving
 *  msg_id          [IN]        The msg id of new email
 *  user_data       [IN]        The related user_data of this callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_imap4_save_done(srv_email_result_enum result, EMAIL_MSG_ID msg_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_cntx_struct *cntx_p = (srv_email_imap4_cntx_struct*)user_data;
    srv_email_comm_cntx_struct *comm_p = NULL;
    srv_email_imap4_state_struct *state_p = NULL;
    srv_email_stor_msg_create_header_struct *msg_header_p = NULL;
    MMI_BOOL is_valid = MMI_FALSE;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_MSG_SAVE_DONE, cntx_p, result, msg_id);

    is_valid = srv_email_nwk_is_cntx_valid((srv_email_nwk_cntx_struct*)cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_CONTEXT_INVALID, cntx_p);
        return;
    }

    comm_p = &cntx_p->common;
    state_p = &cntx_p->state;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_RECEIVING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE);
        return;
    }

    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_stor_error(result, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    }

    EMAILSRV_ASSERT(state_p->msg_env_p && state_p->msg_env_p->msg_header_p);
    state_p->msg_create_handle = EMAIL_STOR_INVALID_HANDLE;

    msg_header_p = state_p->msg_env_p->msg_header_p;
    msg_header_p->msg_id = msg_id;

    srv_email_imap4_recv_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_save_mail
 * DESCRIPTION
 *  This function is used to save email into local.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_save_mail(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_msg_env_struct *msg_env_p = state_p->msg_env_p;
    srv_email_cont_list_struct *cont_p = msg_env_p->cont_p;
    srv_email_attach_list_struct *attach_p = msg_env_p->attach_p;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_STOR_HANDLE msg_create_handle = EMAIL_STOR_INVALID_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state_p->batch_download)
    {
        retval = srv_email_stor_msg_create(
                    msg_env_p->msg_header_p,
                    srv_email_imap4_query_text,
                    srv_email_imap4_query_addr,
                    srv_email_imap4_query_attach,
                    srv_email_imap4_save_done,
                    cntx_p,
                    &msg_create_handle);

        if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            state_p->msg_create_handle = msg_create_handle;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_CREATE_MSG, cntx_p, retval);
        }
    }
    else
    {
        while (cont_p)
        {
            retval = srv_email_stor_msg_load_cont(
                        state_p->curr_rec_p->msg_id,
                        cont_p->type,
                        (const WCHAR*)cont_p->filename,
                        MMI_FALSE);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_ERROR_IMAP4_STOR_LOAD_CONTENT,
                    cntx_p,
                    cont_p->type,
                    retval);
                goto EXIT_HANDLE;
            }

            cont_p = cont_p->next;
        }

        while (attach_p)
        {
            retval = srv_email_stor_msg_load_attch(
                        state_p->curr_rec_p->msg_id,
                        attach_p->attach_id,
                        (const WCHAR*)attach_p->filename,
                        MMI_FALSE,
                        attach_p->attach.drm,
                        attach_p->attach.drm_content_type,
                        attach_p->attach.file_name,
                        NULL);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_LOAD_ATTACH, cntx_p, retval);
                goto EXIT_HANDLE;
            }

            attach_p = attach_p->next;
        }
    }

EXIT_HANDLE:

    if (retval != SRV_EMAIL_RESULT_SUCC && retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_MAIL_ERROR, retval, NULL);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_addr
 * DESCRIPTION
 *  This function is used to read the envelope structure of the email.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  addr_p          [IN]        Used to store the address information when not null
 * RETURNS
 *  The error code.
 *****************************************************************************/
static S32 srv_email_imap4_read_addr(FS_HANDLE fd, srv_email_stor_addr_struct *addr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    U32 len = 0;
    U32 rbyte = 0;
    U32 offset = 0;
    CHAR *buff_p = NULL;
    CHAR *email_addr_p = NULL;
    U32 i = 0;
    S32 quote_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read display name */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    if (addr_p)
    {
        memset(addr_p, 0, sizeof(srv_email_stor_addr_struct));
    }
    if (len > 0)
    {
        if (addr_p)
        {
            if (len > EMAIL_MAX_ENCODED_DISP_NAME_LEN)
            {
                offset = len - EMAIL_MAX_ENCODED_DISP_NAME_LEN;
                len = EMAIL_MAX_ENCODED_DISP_NAME_LEN;
            }
            else
            {
                offset = 0;
            }

            ret = FS_Read(fd, &addr_p->disp_name, len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                return ret;
            }

            addr_p->disp_name[len] = '\0';

            if (offset > 0)
            {
                ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
                if (ret < 0)
                {
                    return ret;
                }
            }
        }
        else
        {
            ret = FS_Seek(fd, len, FS_FILE_CURRENT);
            if (ret < 0)
            {
                return ret;
            }
        }
    }

    /* Read email address */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    if (len > 0)
    {
        if (addr_p)
        {
            buff_p = (CHAR*)OslMalloc(len + 1);
            email_addr_p = buff_p;

            ret = FS_Read(fd, buff_p, len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                OslMfree(buff_p);
                return ret;
            }

            buff_p[len] = '\0';

            for (i = 0; i < len / 2; i++)
            {
                if (buff_p[i] == '"' && buff_p[len - 1 - i] == '"')
                {
                    quote_num++;
                }
                else
                {
                    break;
                }
            }

            if (quote_num)
            {
                buff_p[len - quote_num] = '\0';
                email_addr_p = buff_p + quote_num;
                len -= quote_num * 2;
            }

            if (len > EMAIL_MAX_ENCODED_ADDR_LEN)
            {
                len = EMAIL_MAX_ENCODED_ADDR_LEN;
            }

            memcpy(addr_p->email_addr, email_addr_p, len);
            addr_p->email_addr[len] = '\0';

            OslMfree(buff_p);
        }
        else
        {
            ret = FS_Seek(fd, len, FS_FILE_CURRENT);
            if (ret < 0)
            {
                return ret;
            }
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_add_addr
 * DESCRIPTION
 *  This function is used to add the address into the list.
 * PARAMETERS
 *  header_p        [IN]        The pointer point to the address list header
 *  addr_p          [IN]        The pointer point to the new address
 * RETURNS
 *  The new address list header pointer.
 *****************************************************************************/
static srv_email_addr_list_struct *srv_email_imap4_add_addr(
                                    srv_email_addr_list_struct *header_p,
                                    srv_email_addr_list_struct *addr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_addr_list_struct *ptr = header_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr_p->next = NULL;

    if (!header_p)
    {
        return addr_p;
    }

    while (ptr->next)
    {
        ptr = ptr->next;
    }

    ptr->next = addr_p;

    return header_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_envelope
 * DESCRIPTION
 *  This function is used to read the envelope structure of the email.
 * PARAMETERS
 *  filename        [IN]        The filename
 *  msg_env_p       [OUT]       Used to store the envelop information
 *  major_error     [OUT]       The major error
 *  minor_error     [OUT]       The minor error
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_read_envelope(
                                const WCHAR *filename,
                                srv_email_msg_env_struct *msg_env_p,
                                S32 *major_error,
                                S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_stor_msg_create_header_struct *msg_header_p = msg_env_p->msg_header_p;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    email_ps_data_time_struct data_time;
    applib_time_struct utc;
    applib_time_struct mytime;
    srv_email_addr_list_struct *addr_p = NULL;
    srv_email_addr_list_struct **last_addr_p = NULL;
    U32 priority;
    U16 *addr_num_p = NULL;
    U16 *remain_addr_num_p = NULL;
    U32 addr_count = 0;
    FS_HANDLE fd = -1;
    U32 rbyte;
    U32 addr_num;
    U32 i;
	U32 j;
    S32 len = 0;
    S32 chset = 0;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    float time_zone_float = 0.0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open(filename, FS_READ_ONLY);
    if (fd < 0)
    {
        minor = fd;
        goto EXIT_HANDLE;
    }

    /* Read the UID */
    minor = FS_Read(fd, &msg_header_p->uid, 4, &rbyte);
    if (minor < 0 || rbyte != 4)
    {
        goto EXIT_HANDLE;
    }

    /* Read the server size */
    minor = FS_Read(fd, &msg_header_p->server_size, 4, &rbyte);
    if (minor < 0 || rbyte != 4)
    {
        goto EXIT_HANDLE;
    }

    /* Read the priority */
    minor = FS_Read(fd, &priority, 4, &rbyte);
    if (minor < 0 || rbyte != 4)
    {
        goto EXIT_HANDLE;
    }
    if (priority == EMAIL_PS_PRIORITY_LOW)
    {
        msg_header_p->priority = EMAIL_MSG_PRIO_LOW;
    }
    else if (priority == EMAIL_PS_PRIORITY_HIGH)
    {
        msg_header_p->priority = EMAIL_MSG_PRIO_HIGH;
    }
    else
    {
        msg_header_p->priority = EMAIL_MSG_PRIO_MED;
    }

    /* Read the date and time */
    minor = FS_Read(fd, &data_time, sizeof(email_ps_data_time_struct), &rbyte);
    if (minor < 0 || rbyte != sizeof(email_ps_data_time_struct))
    {
        goto EXIT_HANDLE;
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
    msg_header_p->created_date = applib_dt_mytime_2_utc_sec(&mytime, MMI_FALSE);

    /* Read the subject len */
    minor = FS_Read(fd, &msg_header_p->subj_len, 4, &rbyte);
    if (minor < 0 || rbyte != 4)
    {
        goto EXIT_HANDLE;
    }
    if (msg_header_p->subj_len > 0)
    {
        msg_env_p->subject_p = (CHAR*)srv_email_mem_alloc(msg_header_p->subj_len + 1);
        if (!msg_env_p->subject_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto EXIT_HANDLE;
        }

        /* Read the subject string */
        minor = FS_Read(fd, msg_env_p->subject_p, msg_header_p->subj_len, &rbyte);
        if (minor < 0 || rbyte != msg_header_p->subj_len)
        {
            goto EXIT_HANDLE;
        }

        msg_env_p->subject_p[msg_header_p->subj_len] = '\0';

        /* Fill the subject in msg header structure */
        len = sizeof(msg_header_p->list_subj);
        srv_email_string_decode(
            (kal_wchar*)msg_env_p->subject_p,
            (kal_wchar*)msg_header_p->list_subj,
            &len,
            &chset);

        minor = FS_Seek(fd, 0 - msg_header_p->subj_len, FS_FILE_CURRENT);
        if (minor < 0)
        {
            goto EXIT_HANDLE;
        }

        minor = FS_Read(fd, msg_env_p->subject_p, msg_header_p->subj_len, &rbyte);
        if (minor < 0 || rbyte != msg_header_p->subj_len)
        {
            goto EXIT_HANDLE;
        }

        msg_env_p->subject_p[msg_header_p->subj_len] = '\0';
    }

    /* Read the From */
    msg_env_p->from_p = (srv_email_stor_addr_struct*)srv_email_mem_alloc(sizeof(srv_email_stor_addr_struct));
    if (!msg_env_p->from_p)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_NO_MEMORY;
        goto EXIT_HANDLE;
    }

    minor = srv_email_imap4_read_addr(fd, msg_env_p->from_p);
    if (minor < 0)
    {
        goto EXIT_HANDLE;
    }

    /* Skip the Sender */
    minor = srv_email_imap4_read_addr(fd, NULL);
    if (minor < 0)
    {
        goto EXIT_HANDLE;
    }

    /* Read the Reply-To */
    msg_env_p->reply_to_p = (srv_email_stor_addr_struct*)srv_email_mem_alloc(sizeof(srv_email_stor_addr_struct));
    if (!msg_env_p->reply_to_p)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_NO_MEMORY;
        goto EXIT_HANDLE;
    }

    minor = srv_email_imap4_read_addr(fd, msg_env_p->reply_to_p);
    if (minor < 0)
    {
        goto EXIT_HANDLE;
    }

    /* Read the To/Cc/Bcc address */
    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
            case 0:
                last_addr_p = &msg_env_p->to_addr_p;
                addr_num_p = &msg_header_p->addr_to_num;
                remain_addr_num_p = &msg_header_p->remain_addr_to_num;
                break;

            case 1:
                last_addr_p = &msg_env_p->cc_addr_p;
                addr_num_p = &msg_header_p->addr_cc_num;
                remain_addr_num_p = &msg_header_p->remain_addr_cc_num;
                break;

            case 2:
                last_addr_p = &msg_env_p->bcc_addr_p;
                addr_num_p = &msg_header_p->addr_bcc_num;
                remain_addr_num_p = &msg_header_p->remain_addr_bcc_num;
                break;

            default:
                break;
        }

        minor = FS_Read(fd, &addr_num, 4, &rbyte);
        if (minor < 0 || rbyte != 4)
        {
            goto EXIT_HANDLE;
        }

        *remain_addr_num_p = (U16)addr_num;
        if (addr_num > 0)
        {
            for (j = 0; j < addr_num; j++)
            {
                if (addr_count < SRV_EMAIL_MAX_ADDR_NUM)
                {
                    addr_p = (srv_email_addr_list_struct*)srv_email_mem_alloc(sizeof(srv_email_addr_list_struct));
                    if (!addr_p)
                    {
                        major = SRV_EMAIL_MAIL_ERROR;
                        major = SRV_EMAIL_RESULT_NO_MEMORY;
                        goto EXIT_HANDLE;
                    }
                    memset(addr_p, 0, sizeof(srv_email_addr_list_struct));

                    /* Read the recipient */
                    minor = srv_email_imap4_read_addr(fd, &addr_p->addr);
                    if (minor < 0)
                    {
                        srv_email_mem_free(addr_p);
                        goto EXIT_HANDLE;
                    }

                    *last_addr_p = srv_email_imap4_add_addr(*last_addr_p, addr_p);

                    (*remain_addr_num_p)--;
                    (*addr_num_p)++;
                    addr_count++;
                }
                else
                {
                    /* Skip the recipient */
                    minor = srv_email_imap4_read_addr(fd, NULL);
                    if (minor < 0)
                    {
                        goto EXIT_HANDLE;
                    }
                }
            }
        }
    }

    /* Read envelope successfully */
    retval = SRV_EMAIL_RESULT_SUCC;

EXIT_HANDLE:

    if (fd >= 0)
    {
        FS_Close(fd);
    }
    FS_Delete(filename);

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_READ_ENVELOPE, retval, major, minor);

        if (major_error)
        {
            *major_error = major;
        }
        if (minor_error)
        {
            *minor_error = minor;
        }
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_attachment
 * DESCRIPTION
 *  This function is used to read the attachment of the email.
 * PARAMETERS
 *  filename        [IN]        The filename
 *  attach_p        [OUT]       Used to store the attachment information
 *  major_error     [OUT]       The major error
 *  minor_error     [OUT]       The minor error
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_read_attachment(
                                const WCHAR *filename,
                                srv_email_attach_list_struct *attach_p,
                                S32 *major_error,
                                S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        attach_p->filename,
        "%s%s%08X.part",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        attach_p);

    FS_Delete(attach_p->filename);
    ret = FS_Rename(filename, attach_p->filename);
    if (ret < 0)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_ERROR_IMAP4_READ_ATTACH,
            SRV_EMAIL_RESULT_FAIL,
            SRV_EMAIL_FS_ERROR,
            ret);
 
        if (major_error)
        {
            *major_error = SRV_EMAIL_FS_ERROR;
        }
        if (minor_error)
        {
            *minor_error = ret;
        }

        return SRV_EMAIL_RESULT_FAIL;
    }

    attach_p->attach.download_flag = MMI_TRUE;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_parse_content
 * DESCRIPTION
 *  This function is used to parse the content of the email.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  cont_p          [IN]        The pointer point to the content information
 *  major_error     [OUT]       The major error
 *  minor_error     [OUT]       The minor error
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_parse_content(
                                srv_email_imap4_cntx_struct *cntx_p,
                                srv_email_cont_list_struct *cont_p,
                                S32 *major_error,
                                S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    S32 enc_type = 0;
    FS_HANDLE fd1 = -1;
    FS_HANDLE fd2 = -1;
    U32 file_size = 0;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    void *async_fs_data_buf_p = NULL;
    void *async_fs_work_buf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        state_p->filename,
        "%s%s%08X.part2",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        cont_p);

    enc_type = srv_email_imap4_get_encode_type(cont_p->cont.encoding);
    if (enc_type != EMAIL_MIME_ENCBASE64 && enc_type != EMAIL_MIME_ENCQUOTPRINT)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    fd1 = FS_Open(cont_p->filename, FS_READ_ONLY);
    if (fd1 < 0)
    {
        minor = fd1;
        goto ERROR_HANDLE;
    }

    minor = FS_GetFileSize(fd1, &file_size);
    if (minor < 0)
    {
        goto ERROR_HANDLE;
    }

    if (file_size == 0)
    {
        FS_Close(fd1);
        return SRV_EMAIL_RESULT_SUCC;
    }

    async_fs_data_buf_p = srv_email_mem_alloc(SRV_EMAIL_IMAP4_DECODE_BUFF_SIZE);
    if (!async_fs_data_buf_p)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_NO_MEMORY;
        goto ERROR_HANDLE;
    }

    async_fs_work_buf_p = srv_email_mem_alloc(FS_ASYNC_WORKING_BUFFER_SIZE);
    if (!async_fs_work_buf_p)
    {
        major = SRV_EMAIL_MAIL_ERROR;
        minor = SRV_EMAIL_RESULT_NO_MEMORY;
        goto ERROR_HANDLE;
    }

    fd2 = FS_Open(state_p->filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fd2 < 0)
    {
        minor = fd2;
        goto ERROR_HANDLE;
    }

    if (enc_type == EMAIL_MIME_ENCBASE64)
    {
        state_p->base64_p = (applib_base64_part_context*)
            srv_email_mem_alloc(sizeof(applib_base64_part_context));
        if (!state_p->base64_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto ERROR_HANDLE;
        }

        applib_base64_part_decode_init(state_p->base64_p, 0);
    }
    else
    {
        state_p->qprint_p = (applib_qprint_context*)
            srv_email_mem_alloc(sizeof(applib_qprint_context));
        if (!state_p->qprint_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto ERROR_HANDLE;
        }

        applib_qprint_part_decode_init(state_p->qprint_p, 0, 0);
    }

    state_p->parse_state = SRV_EMAIL_IMAP4_DECODE_CONTENT;
    state_p->src_fd = fd1;
    state_p->dst_fd = fd2;
    state_p->total_size = file_size;
    state_p->curr_size = 0;
    state_p->async_fs_data_buf = async_fs_data_buf_p;
    state_p->async_fs_work_buf = async_fs_work_buf_p;
    state_p->async_fs_job_id = -1;
    state_p->async_fs_state = SRV_EMAIL_IMAP4_PARSE_NONE;

    srv_email_schdl_start_job(srv_email_imap4_decode_base64_qprint, cntx_p);

    return SRV_EMAIL_RESULT_WOULDBLOCK;

ERROR_HANDLE:
    if (async_fs_data_buf_p)
    {
        srv_email_mem_free(async_fs_data_buf_p);
    }
    if (async_fs_work_buf_p)
    {
        srv_email_mem_free(async_fs_work_buf_p);
    }

    if (fd1 >= 0)
    {
        FS_Close(fd1);
    }
    if (fd2 >= 0)
    {
        FS_Close(fd2);
    }
    FS_Delete((const WCHAR*)cont_p->filename);
    FS_Delete((const WCHAR*)state_p->filename);

    *major_error = major;
    *minor_error = minor;

    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_parse_attachment
 * DESCRIPTION
 *  This function is used to parse the attachment of the email.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  attach_p        [IN]        The pointer point to the attachment information
 *  major_error     [OUT]       The major error
 *  minor_error     [OUT]       The minor error
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_parse_attachment(
                                srv_email_imap4_cntx_struct *cntx_p,
                                srv_email_attach_list_struct *attach_p,
                                S32 *major_error,
                                S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    S32 enc_type = 0;
    FS_HANDLE fd1 = -1;
    FS_HANDLE fd2 = -1;
    U32 file_size = 0;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    void *async_fs_data_buf_p = NULL;
    void *async_fs_work_buf_p = NULL;
#ifdef __DRM_SUPPORT__
    applib_mime_type_struct *mime_p = NULL;
    S32 ret = 0;
    U8 serial = 0;
#endif /* __DRM_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        state_p->filename,
        "%s%s%08X.part2",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        attach_p);

    enc_type = srv_email_imap4_get_encode_type(attach_p->attach.encoding);
    if (enc_type == EMAIL_MIME_ENCBASE64 || enc_type == EMAIL_MIME_ENCQUOTPRINT)
    {
        fd1 = FS_Open(attach_p->filename, FS_READ_ONLY);
        if (fd1 < 0)
        {
            minor = fd1;
            goto ERROR_HANDLE;
        }

        minor = FS_GetFileSize(fd1, &file_size);
        if (minor < 0)
        {
            goto ERROR_HANDLE;
        }

        if (file_size == 0)
        {
            FS_Close(fd1);
            return SRV_EMAIL_RESULT_SUCC;
        }

        async_fs_data_buf_p = srv_email_mem_alloc(SRV_EMAIL_IMAP4_DECODE_BUFF_SIZE);
        if (!async_fs_data_buf_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto ERROR_HANDLE;
        }

        async_fs_work_buf_p = srv_email_mem_alloc(FS_ASYNC_WORKING_BUFFER_SIZE);
        if (!async_fs_work_buf_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto ERROR_HANDLE;
        }

        fd2 = FS_Open(state_p->filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (fd2 < 0)
        {
            minor = fd2;
            goto ERROR_HANDLE;
        }

        if (enc_type == EMAIL_MIME_ENCBASE64)
        {
            state_p->base64_p = (applib_base64_part_context*)
                srv_email_mem_alloc(sizeof(applib_base64_part_context));
            if (!state_p->base64_p)
            {
                major = SRV_EMAIL_MAIL_ERROR;
                minor = SRV_EMAIL_RESULT_NO_MEMORY;
                goto ERROR_HANDLE;
            }

            applib_base64_part_decode_init(state_p->base64_p, 0);
        }
        else
        {
            state_p->qprint_p = (applib_qprint_context*)
                srv_email_mem_alloc(sizeof(applib_qprint_context));
            if (!state_p->qprint_p)
            {
                major = SRV_EMAIL_MAIL_ERROR;
                minor = SRV_EMAIL_RESULT_NO_MEMORY;
                goto ERROR_HANDLE;
            }

            applib_qprint_part_decode_init(state_p->qprint_p, 0, 0);
        }

        state_p->parse_state = SRV_EMAIL_IMAP4_DECODE_ATTACHMENT;
        state_p->src_fd = fd1;
        state_p->dst_fd = fd2;
        state_p->total_size = file_size;
        state_p->curr_size = 0;
        state_p->async_fs_data_buf = async_fs_data_buf_p;
        state_p->async_fs_work_buf = async_fs_work_buf_p;
        state_p->async_fs_job_id = -1;
        state_p->async_fs_state = SRV_EMAIL_IMAP4_PARSE_NONE;

        srv_email_schdl_start_job(srv_email_imap4_decode_base64_qprint, cntx_p);

        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
    #ifdef __DRM_SUPPORT__
        mime_p = applib_mime_type_look_up(
                    (kal_char*)attach_p->attach.content_type,
                    NULL,
                    MIME_TYPE_NONE,
                    MIME_SUBTYPE_NONE);
        if (!mime_p ||
            mime_p->mime_type != MIME_TYPE_APPLICATION ||
            (mime_p->mime_subtype != MIME_SUBTYPE_DRM_CONTENT &&
             mime_p->mime_subtype != MIME_SUBTYPE_DRM_MESSAGE))
        {
            return SRV_EMAIL_RESULT_SUCC;
        }

        ret = DRM_install_object(
                (U8*)attach_p->attach.content_type,
                attach_p->filename,
                MMI_FALSE,
                state_p->filename,
                (SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1) * 2,
                &serial,
                &mime_p,
                srv_email_imap4_parse_drm_done);

        if (ret == DRM_RESULT_OK)
        {
            FS_Delete(attach_p->filename);
            minor = FS_Rename(state_p->filename, attach_p->filename);
            if (minor < 0)
            {
                goto ERROR_HANDLE;
            }

            attach_p->attach.drm = MMI_TRUE;
            if (mime_p)
            {
                strcpy(attach_p->attach.drm_content_type, mime_p->mime_string);
                srv_email_transform_filename(
                    attach_p->attach.file_name,
                    attach_p->attach.file_name,
                    EMAIL_STOR_ENCOD_FILE_NAME_LEN + 1,
                    mime_p->file_ext);
            }
            else
            {
                srv_email_transform_filename(
                    attach_p->attach.file_name,
                    attach_p->attach.file_name,
                    EMAIL_STOR_ENCOD_FILE_NAME_LEN + 1,
                    "tmp");
            }
            return SRV_EMAIL_RESULT_SUCC;
        }
        else if (ret == DRM_PROC_ENCRYPT_BUSY)
        {
            state_p->parse_state = SRV_EMAIL_IMAP4_PARSE_DRM;
            state_p->drm_serial = serial;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            /* Parse DRM unsuccessfully, process it as normal attachment */
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_PARSE_DRM, cntx_p, ret);
            return SRV_EMAIL_RESULT_SUCC;
        }
    #else /* __DRM_SUPPORT__ */
        return SRV_EMAIL_RESULT_SUCC;
    #endif /* __DRM_SUPPORT__ */
    }

ERROR_HANDLE:
    if (async_fs_data_buf_p)
    {
        srv_email_mem_free(async_fs_data_buf_p);
    }
    if (async_fs_work_buf_p)
    {
        srv_email_mem_free(async_fs_work_buf_p);
    }

    if (fd1 >= 0)
    {
        FS_Close(fd1);
    }
    if (fd2 >= 0)
    {
        FS_Close(fd2);
    }
    FS_Delete((const WCHAR*)attach_p->filename);
    FS_Delete((const WCHAR*)state_p->filename);

    *major_error = major;
    *minor_error = minor;

    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_recv_fsm_init
 * DESCRIPTION
 *  This function is used to initialize the imap4 RECEIVE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_recv_fsm_init(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_stor_msg_create_header_struct *msg_header_p = NULL;
    email_ps_fetch_type_enum fetch_type = EMAIL_PS_FETCH_TYPE_HEADER;
    CHAR *part_num_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_RECV_FSM_INIT, cntx_p, state_p->fetch_type);

    switch (state_p->fetch_type)
    {
        case SRV_EMAIL_IMAP4_FETCH_ENVELOPE:
            EMAILSRV_ASSERT(!state_p->msg_env_p->msg_header_p);

            msg_header_p = (srv_email_stor_msg_create_header_struct*)
                srv_email_mem_alloc(sizeof(srv_email_stor_msg_create_header_struct));
            if (!msg_header_p)
            {
                srv_email_set_error_cause(
                    &comm_p->result,
                    SRV_EMAIL_MAIL_ERROR,
                    SRV_EMAIL_RESULT_NO_MEMORY,
                    NULL);
                return SRV_EMAIL_RESULT_FAIL;
            }
            memset(msg_header_p, 0, sizeof(srv_email_stor_msg_create_header_struct));
            memcpy(msg_header_p->acct_digest, comm_p->acct_digest, SRV_EMAIL_MD5_DIGEST_LEN);
            msg_header_p->uid_validity = cntx_p->session.uid_validity;

            state_p->msg_env_p->msg_header_p = msg_header_p;

            fetch_type = EMAIL_PS_FETCH_TYPE_ENVELOP;
            break;

        case SRV_EMAIL_IMAP4_FETCH_CONTENT:
        case SRV_EMAIL_IMAP4_FETCH_ATTACHMENT:
            fetch_type = EMAIL_PS_FETCH_TYPE_PART;
            part_num_p = state_p->part_num;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, state_p->fetch_type, 0, 0);
            break;
    }

    srv_email_ps_fetch_mail_req(
        comm_p->ps_handle,
        state_p->curr_rec_p->uid,
        fetch_type,
        0,
        part_num_p,
        (const WCHAR*)state_p->rsp_filename);

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

    if (fetch_type == EMAIL_PS_FETCH_TYPE_ENVELOP)
    {
        srv_email_receiving_data_struct recv_data;

        recv_data.fldr_id = cntx_p->session.fldr_id;
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
 *  srv_email_imap4_recv_fsm_received
 * DESCRIPTION
 *  This function is used to process the case that receiving email successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_recv_fsm_received(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_msg_env_struct *msg_env_p = state_p->msg_env_p;
    srv_email_stor_msg_create_header_struct *msg_header_p = msg_env_p->msg_header_p;
    srv_email_cont_list_struct *cont_p = NULL;
    srv_email_imap4_item_struct *record_p = state_p->curr_rec_p;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = 0;
    S32 minor = 0;
    srv_email_cont_list_struct *text_cont_p = NULL;
    srv_email_cont_list_struct *html_cont_p = NULL;
    MMI_BOOL partial_fetch = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_RECV_FSM_RECEIVED, cntx_p, state_p->fetch_type);

    switch (state_p->fetch_type)
    {
        case SRV_EMAIL_IMAP4_FETCH_ENVELOPE:
            retval = srv_email_imap4_read_envelope(
                        (const WCHAR*)state_p->rsp_filename,
                        msg_env_p,
                        &major,
                        &minor);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                msg_header_p->acct_id = comm_p->acct_id;
                msg_header_p->fldr_id = cntx_p->session.fldr_id;
                msg_header_p->flag = (EMAIL_MSG_FLAG)record_p->msg_flag;
                msg_header_p->received_date = app_getcurrtime();
                msg_header_p->server_size = record_p->size;
                msg_header_p->msg_type = SRV_EMAIL_STOR_MSG_TYPE_RECV;
            }
            break;

        case SRV_EMAIL_IMAP4_FETCH_BODY_STRUCT:
            retval = srv_email_imap4_read_body_struct(
                        (const WCHAR*)state_p->rsp_filename,
                        msg_env_p,
                        &major,
                        &minor);

            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                /* Set the text length and html length */
                cont_p = msg_env_p->cont_p;
                while (cont_p)
                {
                    if (cont_p->type == SRV_EMAIL_STOR_MSG_CONT_TEXT)
                    {
                        text_cont_p = cont_p;
                        msg_header_p->text_len = cont_p->cont.server_size;
                    }
                    else if (cont_p->type == SRV_EMAIL_STOR_MSG_CONT_HTML)
                    {
                        html_cont_p = cont_p;
                        msg_header_p->html_len = cont_p->cont.server_size;
                    }

                    cont_p = cont_p->next;
                }

                if (!msg_env_p->cont_p && !msg_env_p->attach_p)
                {
                    msg_header_p->state = SRV_EMAIL_MSG_STATE_DOWN_ALL;
                }
                else if (state_p->download_opt == SRV_EMAIL_DOWNLOAD_HEADER ||
                         record_p->size > state_p->download_size)
                {
                    msg_header_p->state = SRV_EMAIL_MSG_STATE_HEADER_ONLY;

                    if (text_cont_p &&
                        text_cont_p->cont.server_size > EMAIL_MSG_TEXT_DOWNLOAD_SIZE_FOR_IMAP4)
                    {
                        partial_fetch = MMI_TRUE;
                        msg_header_p->state |= SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH;
                    }
                    else if (html_cont_p)
                    {
                        //msg_header_p->state |= SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH;
                    }
                    else if (!msg_env_p->attach_p)
                    {
                        msg_header_p->state = SRV_EMAIL_MSG_STATE_DOWN_ALL;
                    }
                }
                else if (state_p->download_opt == SRV_EMAIL_DOWNLOAD_HEADER_TEXT)
                {
                    if (!msg_env_p->attach_p)
                    {
                        msg_header_p->state = SRV_EMAIL_MSG_STATE_DOWN_ALL;
                    }
                }
                else
                {
                    msg_header_p->state = SRV_EMAIL_MSG_STATE_DOWN_ALL;
                }

                if (state_p->download_opt == SRV_EMAIL_DOWNLOAD_HEADER ||
                    record_p->size > state_p->download_size)
                {
                    if (text_cont_p && text_cont_p->cont.server_size)
                    {
                        state_p->curr_cont_p = text_cont_p;
                    }
                }
                else
                {
                    if (state_p->download_opt == SRV_EMAIL_DOWNLOAD_HEADER_TEXT ||
                        state_p->download_opt == SRV_EMAIL_DOWNLOAD_ALL)
                    {
                        if (text_cont_p && text_cont_p->cont.server_size)
                        {
                            state_p->curr_cont_p = text_cont_p;
                        }
                        else
                        {
                            state_p->curr_cont_p = html_cont_p;
                        }
                    }
                    if (state_p->download_opt == SRV_EMAIL_DOWNLOAD_ALL)
                    {
                        state_p->curr_att_p = msg_env_p->attach_p;
                    }
                }
            }
            break;

        case SRV_EMAIL_IMAP4_FETCH_CONTENT:
            retval = srv_email_imap4_read_content(
                        (const WCHAR*)state_p->rsp_filename,
                        state_p->curr_cont_p,
                        &major,
                        &minor);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                retval = srv_email_imap4_parse_content(cntx_p, state_p->curr_cont_p, &major, &minor);
                if (retval == SRV_EMAIL_RESULT_SUCC)
                {
                    if (state_p->batch_download &&
                        (state_p->download_opt == SRV_EMAIL_DOWNLOAD_HEADER ||
                         record_p->size > state_p->download_size))
                    {
                        state_p->curr_cont_p = NULL;
                    }
                    else
                    {
                        state_p->curr_cont_p = state_p->curr_cont_p->next;
                    }
                }
                else
                {
                    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE);
                    if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                    {
                        return retval;
                    }
                }
            }
            break;

        case SRV_EMAIL_IMAP4_FETCH_ATTACHMENT:
            retval = srv_email_imap4_read_attachment(
                        (const WCHAR*)state_p->rsp_filename,
                        state_p->curr_att_p,
                        &major,
                        &minor);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                retval = srv_email_imap4_parse_attachment(cntx_p, state_p->curr_att_p, &major, &minor);
                if (retval == SRV_EMAIL_RESULT_SUCC)
                {
                    state_p->curr_att_p = state_p->curr_att_p->next;
                }
                else
                {
                    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE);
                    if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                    {
                        return retval;
                    }
                }
            }
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, state_p->fetch_type, 0, 0);
            break;
    }

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        if (state_p->fetch_type == SRV_EMAIL_IMAP4_FETCH_ENVELOPE)
        {
            state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_BODY_STRUCT;

            srv_email_ps_fetch_mail_req(
                comm_p->ps_handle,
                record_p->uid,
                EMAIL_PS_FETCH_TYPE_BODYSTRUCTURE,
                0,
                NULL,
                (const WCHAR*)state_p->rsp_filename);

            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else if (state_p->curr_cont_p)
        {
            state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_CONTENT;
            state_p->part_num = state_p->curr_cont_p->cont.part_num;

            if (partial_fetch)
            {
                srv_email_ps_fetch_mail_req(
                    comm_p->ps_handle,
                    record_p->uid,
                    EMAIL_PS_FETCH_TYPE_PART,
                    EMAIL_MSG_TEXT_DOWNLOAD_SIZE_FOR_IMAP4,
                    state_p->part_num,
                    (const WCHAR*)state_p->rsp_filename);
            }
            else
            {
                srv_email_ps_fetch_mail_req(
                    comm_p->ps_handle,
                    record_p->uid,
                    EMAIL_PS_FETCH_TYPE_PART,
                    0,
                    state_p->part_num,
                    (const WCHAR*)state_p->rsp_filename);
            }

            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else if (state_p->curr_att_p)
        {
            state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_ATTACHMENT;
            state_p->part_num = state_p->curr_att_p->attach.part_num;

            srv_email_ps_fetch_mail_req(
                comm_p->ps_handle,
                record_p->uid,
                EMAIL_PS_FETCH_TYPE_PART,
                0,
                state_p->part_num,
                (const WCHAR*)state_p->rsp_filename);

            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            retval = srv_email_imap4_save_mail(cntx_p);
            if (retval == SRV_EMAIL_RESULT_SUCC || retval == SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE);
            }

            return retval;
        }
    }
    else
    {
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return retval;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_recv_fsm_parsed
 * DESCRIPTION
 *  This function is used to process the case that parsing content/attachment successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_recv_fsm_parsed(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_imap4_item_struct *record_p = state_p->curr_rec_p;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_RECV_FSM_PARSED, cntx_p, state_p->fetch_type);

    switch (state_p->fetch_type)
    {
        case SRV_EMAIL_IMAP4_FETCH_CONTENT:
            if (state_p->batch_download &&
                (state_p->download_opt == SRV_EMAIL_DOWNLOAD_HEADER ||
                 record_p->size > state_p->download_size))
            {
                state_p->curr_cont_p = NULL;
            }
            else
            {
                state_p->curr_cont_p = state_p->curr_cont_p->next;
            }
            break;

        case SRV_EMAIL_IMAP4_FETCH_ATTACHMENT:
            state_p->curr_att_p = state_p->curr_att_p->next;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, state_p->fetch_type, 0, 0);
            break;
    }

    if (state_p->curr_cont_p)
    {
        state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_CONTENT;
        state_p->part_num = state_p->curr_cont_p->cont.part_num;

        srv_email_ps_fetch_mail_req(
            comm_p->ps_handle,
            record_p->uid,
            EMAIL_PS_FETCH_TYPE_PART,
            0,
            state_p->part_num,
            (const WCHAR*)state_p->rsp_filename);

        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else if (state_p->curr_att_p)
    {
        state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_ATTACHMENT;
        state_p->part_num = state_p->curr_att_p->attach.part_num;

        srv_email_ps_fetch_mail_req(
            comm_p->ps_handle,
            record_p->uid,
            EMAIL_PS_FETCH_TYPE_PART,
            0,
            state_p->part_num,
            (const WCHAR*)state_p->rsp_filename);

        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        retval = srv_email_imap4_save_mail(cntx_p);
        if (retval == SRV_EMAIL_RESULT_SUCC || retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE);
        }

        return retval;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_recv_fsm_saved
 * DESCRIPTION
 *  This function is used to process the case that saving email successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_recv_fsm_saved(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_stor_msg_create_header_struct *msg_header_p = state_p->msg_env_p->msg_header_p;
    srv_email_receiving_data_struct recv_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_RECV_FSM_SAVED, cntx_p);

    if (state_p->batch_download)
    {
        state_p->curr_rec_p->msg_id = msg_header_p->msg_id;
        state_p->curr_rec_p->nwk_flag |= SRV_EMAIL_NWK_FLAG_IN_LOCAL;

        state_p->received_num++;

        recv_data.fldr_id = sess_p->fldr_id;
        recv_data.total_num = state_p->total_num;
        recv_data.received_num = state_p->received_num;
        recv_data.fail_num = state_p->fail_num;
        recv_data.total_size = state_p->curr_rec_p->size;
        recv_data.received_size = 0;
        recv_data.new_msg_received = MMI_TRUE;
        recv_data.new_msg_id = state_p->curr_rec_p->msg_id;
        recv_data.new_msg_flag = state_p->curr_rec_p->msg_flag;
        srv_email_nwk_cb_process_notify(
            (srv_email_nwk_cntx_struct*)cntx_p,
            NULL,
            SRV_EMAIL_NWK_RECEIVING,
            &recv_data);
    }

    srv_email_imap4_free_envelope(&state_p->msg_env_p);

    if (!state_p->batch_download ||
        (state_p->received_num + state_p->fail_num == state_p->total_num))
    {
        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
        return SRV_EMAIL_RESULT_SUCC;
    }

    state_p->curr_rec_p = srv_email_imap4_get_next_new_msg(&sess_p->list, state_p->curr_rec_p);
    if (!state_p->curr_rec_p)
    {
        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
        return SRV_EMAIL_RESULT_SUCC;
    }

    state_p->msg_env_p = srv_email_imap4_new_envelope();
    if (!state_p->msg_env_p)
    {
        srv_email_set_error_cause(
            &comm_p->result,
            SRV_EMAIL_MAIL_ERROR,
            SRV_EMAIL_RESULT_NO_MEMORY,
            NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

    msg_header_p = (srv_email_stor_msg_create_header_struct*)
        srv_email_mem_alloc(sizeof(srv_email_stor_msg_create_header_struct));
    if (!msg_header_p)
    {
        srv_email_set_error_cause(
            &comm_p->result,
            SRV_EMAIL_MAIL_ERROR,
            SRV_EMAIL_RESULT_NO_MEMORY,
            NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }
    memset(msg_header_p, 0, sizeof(srv_email_stor_msg_create_header_struct));
    memcpy(msg_header_p->acct_digest, comm_p->acct_digest, SRV_EMAIL_MD5_DIGEST_LEN);
    msg_header_p->uid_validity = sess_p->uid_validity;

    state_p->msg_env_p->msg_header_p = msg_header_p;

    state_p->curr_cont_p = NULL;
    state_p->curr_att_p = NULL;

    state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_ENVELOPE;

    srv_email_ps_fetch_mail_req(
        comm_p->ps_handle,
        state_p->curr_rec_p->uid,
        EMAIL_PS_FETCH_TYPE_ENVELOP,
        0,
        NULL,
        (const WCHAR*)state_p->rsp_filename);

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_recv_fsm_done
 * DESCRIPTION
 *  This function is used to process the case that receiving successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static void srv_email_imap4_recv_fsm_done(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_result_struct *result_p = &cntx_p->common.result;
    srv_email_receive_done_data_struct recv_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_IMAP4_RECV_FSM_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    if (state_p->batch_download)
    {
        recv_data.fldr_id = cntx_p->session.fldr_id;
        recv_data.fldr_count = state_p->fldr_count;
        recv_data.fldr_index = state_p->fldr_index;
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

    srv_email_imap4_state_free(&cntx_p->state);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_recv_mail_fail
 * DESCRIPTION
 *  This function is used to process the case that receiving email unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_recv_mail_fail(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_stor_msg_create_header_struct *msg_header_p = state_p->msg_env_p->msg_header_p;
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

        recv_data.fldr_id = sess_p->fldr_id;
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

    srv_email_imap4_free_envelope(&state_p->msg_env_p);

    if (!state_p->batch_download ||
        (state_p->received_num + state_p->fail_num == state_p->total_num))
    {
        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
        return SRV_EMAIL_RESULT_FAIL;
    }

    state_p->curr_rec_p = srv_email_imap4_get_next_new_msg(&sess_p->list, state_p->curr_rec_p);
    if (!state_p->curr_rec_p)
    {
        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
        return SRV_EMAIL_RESULT_SUCC;
    }

    state_p->msg_env_p = srv_email_imap4_new_envelope();
    if (!state_p->msg_env_p)
    {
        srv_email_set_error_cause(
            &comm_p->result,
            SRV_EMAIL_MAIL_ERROR,
            SRV_EMAIL_RESULT_NO_MEMORY,
            NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

    msg_header_p = (srv_email_stor_msg_create_header_struct*)
        srv_email_mem_alloc(sizeof(srv_email_stor_msg_create_header_struct));
    if (!msg_header_p)
    {
        srv_email_set_error_cause(
            &comm_p->result,
            SRV_EMAIL_MAIL_ERROR,
            SRV_EMAIL_RESULT_NO_MEMORY,
            NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }
    memset(msg_header_p, 0, sizeof(srv_email_stor_msg_create_header_struct));
    memcpy(msg_header_p->acct_digest, comm_p->acct_digest, SRV_EMAIL_MD5_DIGEST_LEN);
    msg_header_p->uid_validity = sess_p->uid_validity;

    state_p->msg_env_p->msg_header_p = msg_header_p;

    state_p->curr_cont_p = NULL;
    state_p->curr_att_p = NULL;

    state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_ENVELOPE;

    srv_email_ps_fetch_mail_req(
        comm_p->ps_handle,
        state_p->curr_rec_p->uid,
        EMAIL_PS_FETCH_TYPE_ENVELOP,
        0,
        NULL,
        (const WCHAR*)state_p->rsp_filename);

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_add_fldr
 * DESCRIPTION
 *  This function is used to add the folder info into the list.
 * PARAMETERS
 *  header_p        [IN]        The pointer point to the folder list header
 *  attach_p        [IN]        The pointer point to the new folder
 *  is_valid        [OUT]       If the folder is valid or not
 * RETURNS
 *  The new folder list header pointer
 *****************************************************************************/
static srv_email_nwk_fldr_list_struct *srv_email_imap4_add_fldr(
                                        srv_email_nwk_fldr_list_struct *header_p,
                                        srv_email_nwk_fldr_list_struct *fldr_p,
                                        MMI_BOOL *is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_fldr_list_struct *ptr = header_p;
    srv_email_nwk_fldr_list_struct *prev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fldr_p->next = NULL;
    *is_valid = MMI_TRUE;

    if (!header_p)
    {
        return fldr_p;
    }

    while (ptr)
    {
        if (!strcmp(ptr->fldr_info.folder_name, fldr_p->fldr_info.folder_name))
        {
            *is_valid = MMI_FALSE;
            return header_p;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = fldr_p;

    return header_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_match_fldr
 * DESCRIPTION
 *  This function is used to match the local and server folders.
 * PARAMETERS
 *  header_p        [IN]        The pointer point to the folder list
 *  fldr_info_p     [IN]        The pointer point to the local folder information
 *  fldr_id         [IN]        The local folder id
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_email_imap4_match_fldr(
                    srv_email_nwk_fldr_list_struct *header_p,
                    srv_email_stor_fldr_struct *fldr_info_p,
                    EMAIL_FLDR_ID fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_fldr_list_struct *fldr_p = header_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (fldr_p)
    {
        if (!strcmp(fldr_p->fldr_info.folder_name, fldr_info_p->fldr_name))
        {
            fldr_p->fldr_info.subscribed = MMI_TRUE;
            fldr_p->fldr_info.fldr_id = fldr_id;
            return MMI_TRUE;
        }
        fldr_p = fldr_p->next;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_fldr_fsm_init
 * DESCRIPTION
 *  This function is used to initialize the imap4 LISTING FOLDER FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_list_fldr_fsm_init(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_LIST_FLDR_FSM_INIT, cntx_p);

    srv_email_ps_list_folder_req(
        comm_p->ps_handle,
        state_p->subcribed_only,
        (const WCHAR*)state_p->rsp_filename);

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_SERVER);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_fldr_fsm_server_listed
 * DESCRIPTION
 *  This function is used to process the case that listing remote folder successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_list_fldr_fsm_server_listed(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_nwk_fldr_list_struct *fldr_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    FS_HANDLE fd = -1;
    U32 count = 0;
    U32 len = 0;
    U32 rw_byte = 0;
    U32 i = 0;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_LIST_FLDR_FSM_SERVER_LISTED, cntx_p);

    fd = FS_Open(state_p->rsp_filename, FS_READ_ONLY);
    if (fd < 0)
    {
        minor = fd;
        goto EXIT_HANDLE;
    }

    minor = FS_Read(fd, &count, 4, &rw_byte);
    if (minor < 0 || rw_byte != 4)
    {
        goto EXIT_HANDLE;
    }

    for (i = 0; i < count; i++)
    {
        fldr_p = (srv_email_nwk_fldr_list_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_fldr_list_struct));
        if (!fldr_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto EXIT_HANDLE;
        }
        memset(fldr_p, 0, sizeof(srv_email_nwk_fldr_list_struct));

        minor = FS_Seek(fd, 4, FS_FILE_CURRENT);
        if (minor < 0)
        {
            goto EXIT_HANDLE;
        }

        minor = FS_Read(fd, &len, 4, &rw_byte);
        if (minor < 0 || rw_byte != 4)
        {
            goto EXIT_HANDLE;
        }

        if (len > SRV_EMAIL_FLDR_NAME_LEN)
        {
            minor = FS_Seek(fd, len, FS_FILE_CURRENT);
            if (minor < 0)
            {
                goto EXIT_HANDLE;
            }
        }
        else
        {
            minor = FS_Read(fd, fldr_p->fldr_info.folder_name, len, &rw_byte);
            if (minor < 0 || rw_byte != len)
            {
                goto EXIT_HANDLE;
            }

            if (fldr_p->fldr_info.folder_name[len - 1] == (CHAR)state_p->fldr_header.delimiter)
            {
                fldr_p->fldr_info.folder_name[len - 1] = 0;
            }

            state_p->fldr_list_p = srv_email_imap4_add_fldr(state_p->fldr_list_p, fldr_p, &is_valid);
            if (is_valid)
            {
			    fldr_p = NULL;
                state_p->fldr_header.fldr_num++;
                if (state_p->fldr_header.fldr_num == state_p->fldr_num)
                {
                    break;
                }
            }
            else
            {
		        srv_email_mem_free(fldr_p);
			    fldr_p = NULL;
            }
        }
    }

    retval = SRV_EMAIL_RESULT_SUCC;

EXIT_HANDLE:
	if (fldr_p)
	{
		srv_email_mem_free(fldr_p);
	}

    if (fd >= 0)
    {
        FS_Close(fd);
    }
    FS_Delete((const WCHAR*)state_p->rsp_filename);

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_LOCAL);
    }
    else
    {
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_fldr_fsm_local_listed
 * DESCRIPTION
 *  This function is used to process the case that listing local folder successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_imap4_list_fldr_fsm_local_listed(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_nwk_fldr_list_struct *fldr_p = NULL;
    srv_email_stor_fldr_struct *fldr_info_p = NULL;
    EMAIL_STOR_HANDLE stor_handle = EMAIL_STOR_INVALID_HANDLE;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;
    FS_HANDLE fd = -1;
    U32 rw_byte = 0;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_LIST_FLDR_FSM_LOCAL_LISTED, cntx_p);

    fldr_info_p = (srv_email_stor_fldr_struct*)OslMalloc(sizeof(srv_email_stor_fldr_struct));

    minor = srv_email_stor_acct_get_fldr_id_open(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_REMOTE, &stor_handle);
    if (minor != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_GET_FLDR_ID_OPEN, cntx_p, minor);
        goto EXIT_HANDLE;
    }

    while (1)
    {
        minor = srv_email_stor_acct_get_fldr_id_next(stor_handle, &fldr_id);
        if (minor == SRV_EMAIL_RESULT_SUCC)
        {
            minor = srv_email_stor_fldr_get_by_id(comm_p->acct_id, fldr_id, fldr_info_p);
            if (minor != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_GET_FLDR_INFO, cntx_p, fldr_id, retval);
                goto EXIT_HANDLE;
            }

            ret = srv_email_imap4_match_fldr(state_p->fldr_list_p, fldr_info_p, fldr_id);
            if (!ret)
            {
                minor = srv_email_stor_fldr_del(comm_p->acct_id, &fldr_id, 1);
                if (minor != SRV_EMAIL_RESULT_SUCC)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_FLDR_DEL, cntx_p, fldr_id, minor);
                    goto EXIT_HANDLE;
                }
            }
        }
        else if (minor == SRV_EMAIL_RESULT_NO_MORE_RESULT)
        {
            break;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_GET_FLDR_ID_NEXT, cntx_p, minor);
            goto EXIT_HANDLE;
        }
    }

    srv_email_stor_acct_get_fldr_id_close(stor_handle);
    stor_handle = EMAIL_STOR_INVALID_HANDLE;

    OslMfree(fldr_info_p);
    fldr_info_p = NULL;

    major = SRV_EMAIL_FS_ERROR;

    fd = FS_Open(state_p->fldr_filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fd < 0)
    {
        minor = fd;
        goto EXIT_HANDLE;
    }

    minor = FS_Write(fd, &state_p->fldr_header, sizeof(srv_email_nwk_fldr_info_header_struct), &rw_byte);
    if (minor < 0 || rw_byte != sizeof(srv_email_nwk_fldr_info_header_struct))
    {
        goto EXIT_HANDLE;
    }

    fldr_p = state_p->fldr_list_p;
    while (fldr_p)
    {
        minor = FS_Write(fd, &fldr_p->fldr_info, sizeof(srv_email_nwk_fldr_info_struct), &rw_byte);
        if (minor < 0 || rw_byte != sizeof(srv_email_nwk_fldr_info_struct))
        {
            goto EXIT_HANDLE;
        }

        fldr_p = fldr_p->next;
    }

    retval = SRV_EMAIL_RESULT_SUCC;

EXIT_HANDLE:
    if (fldr_info_p)
    {
        OslMfree(fldr_info_p);
    }

    if (stor_handle != EMAIL_STOR_INVALID_HANDLE)
    {
        srv_email_stor_acct_get_fldr_id_close(stor_handle);
    }

    if (fd >= 0)
    {
        FS_Close(fd);
    }

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_DONE);
    }
    else
    {
        FS_Delete((const WCHAR*)state_p->fldr_filename);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_fldr_fsm_done
 * DESCRIPTION
 *  This function is used to process the case that listing folder successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static void srv_email_imap4_list_fldr_fsm_done(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    srv_email_imap4_state_free(&cntx_p->state);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_cntx_init
 * DESCRIPTION
 *  This function is used to initialize the IMAP4 context.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_imap4_cntx_init(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(cntx_p, 0, sizeof(srv_email_imap4_cntx_struct));
    cntx_p->common.result.result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_cntx_free
 * DESCRIPTION
 *  This function is used to free the IMAP4 context.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_imap4_cntx_free(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_imap4_session_free(&cntx_p->session);
    srv_email_imap4_state_free(&cntx_p->state);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update
 * DESCRIPTION
 *  This function is used to update the IMAP4 connection.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  fldr_id         [IN]        The folder id want to update the connection
 *  retrieve_amount [IN]        The retrieve amount
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_update(
                        srv_email_imap4_cntx_struct *cntx_p,
                        EMAIL_FLDR_ID fldr_id,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sess_p->sync_with_server && sess_p->fldr_id == fldr_id)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_STATE;
        goto ERROR_HANDLE;
    }

    srv_email_imap4_session_free(sess_p);
    srv_email_imap4_state_init(state_p);

    sess_p->fldr_id = fldr_id;
    state_p->retrieve_amount = retrieve_amount;

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT);

    retval = srv_email_imap4_update_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;

}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_fsm
 * DESCRIPTION
 *  This function is used to run the IMAP4 UPDATE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_update_fsm(srv_email_imap4_cntx_struct *cntx_p)
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
                retval = srv_email_imap4_update_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER:
                retval = srv_email_imap4_update_fsm_fldr_opened(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID:
                retval = srv_email_imap4_update_fsm_uid_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE:
                retval = srv_email_imap4_update_fsm_size_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_FLAG:
                retval = srv_email_imap4_update_fsm_flag_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL:
                retval = srv_email_imap4_update_fsm_local_updated(cntx_p);
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
        srv_email_imap4_update_fsm_done(cntx_p);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_receive
 * DESCRIPTION
 *  This function is used to receive emails.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  recv_p          [IN]        The pointer point to the receive option
 *  fldr_count      [IN]        The number of the folders
 *  fldr_index      [IN]        The index of the current folder
 *  download_opt    [IN]        The download option
 *  download_size   [IN]        The download size
 *  retrieve_amount [IN]        The retrieve amount
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_receive(
                        srv_email_imap4_cntx_struct *cntx_p,
                        srv_email_nwk_recv_struct *recv_p,
                        S32 fldr_count,
                        S32 fldr_index,
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
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_imap4_item_struct *record_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sess_p->sync_with_server || sess_p->fldr_id != recv_p->fldr_id)
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

    record_p = srv_email_imap4_get_next_new_msg(&sess_p->list, NULL);
    if (!record_p)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    srv_email_imap4_state_init(state_p);

    state_p->msg_env_p = srv_email_imap4_new_envelope();
    if (!state_p->msg_env_p)
    {
        minor = SRV_EMAIL_RESULT_NO_MEMORY;
        goto ERROR_HANDLE;
    }

    state_p->batch_download = MMI_TRUE;
    state_p->fldr_count = fldr_count;
    state_p->fldr_index = fldr_index;
    state_p->recv_opt = recv_p->recv_opt;
    state_p->download_opt = download_opt;
    state_p->download_size = download_size;
    state_p->retrieve_amount = retrieve_amount;
    state_p->total_num = srv_email_imap4_calc_new_msg(&sess_p->list, retrieve_amount);
    state_p->curr_rec_p = record_p;

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    switch (download_opt)
    {
        case SRV_EMAIL_DOWNLOAD_HEADER:
        case SRV_EMAIL_DOWNLOAD_HEADER_TEXT:
        case SRV_EMAIL_DOWNLOAD_ALL:
            state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_ENVELOPE;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, download_opt, 0, 0);
            break;
    }

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_INIT);

    retval = srv_email_imap4_recv_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_retrieve
 * DESCRIPTION
 *  This function is used to retrieve email.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  retr_p          [IN]        The pointer point to the retrieve option
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_retrieve(
                        srv_email_imap4_cntx_struct *cntx_p,
                        srv_email_nwk_retr_struct *retr_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_imap4_item_struct *record_p = NULL;
    srv_email_msg_env_struct *msg_env_p = NULL;
    srv_email_cont_list_struct *cont_p = NULL;
    srv_email_attach_list_struct *attach_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    srv_email_stor_msg_cont_type cont_type = SRV_EMAIL_STOR_MSG_CONT_TEXT;
    MMI_BOOL is_valid = MMI_TRUE;
    S32 i = 0;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;
    EMAIL_MSG_FLAG flag = 0;
    EMAIL_MSG_STATE state = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sess_p->sync_with_server || sess_p->fldr_id != retr_p->fldr_id)
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
        minor = SRV_EMAIL_RESULT_INVALID_MSG;
        goto ERROR_HANDLE;
    }

    if (sess_p->total_msg_num == 0)
    {
        minor = SRV_EMAIL_RESULT_MSG_NOT_EXIST;
        goto ERROR_HANDLE;
    }

    record_p = srv_email_imap4_get_record_by_msgid(&sess_p->list, retr_p->msg_id);
    if (!record_p)
    {
        minor = SRV_EMAIL_RESULT_MSG_NOT_EXIST;
        goto ERROR_HANDLE;
    }

    srv_email_imap4_state_init(state_p);

    msg_env_p = srv_email_imap4_new_envelope();
    if (!msg_env_p)
    {
        minor = SRV_EMAIL_RESULT_NO_MEMORY;
        goto ERROR_HANDLE;
    }
    state_p->msg_env_p = msg_env_p;

    state_p->curr_rec_p = record_p;
    state_p->retr_opt = retr_p->retr_opt;
    state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_CONTENT;

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    switch (retr_p->retr_opt)
    {
        case SRV_EMAIL_RETRIEVE_HTML_CONTENT:
            cont_type = SRV_EMAIL_STOR_MSG_CONT_HTML;
            /* No break here */

        case SRV_EMAIL_RETRIEVE_TEXT_CONTENT:
            cont_p = (srv_email_cont_list_struct*)srv_email_mem_alloc(sizeof(srv_email_cont_list_struct));
            if (!cont_p)
            {
                minor = SRV_EMAIL_RESULT_NO_MEMORY;
                goto ERROR_HANDLE;
            }
            memset(cont_p, 0, sizeof(srv_email_cont_list_struct));

            retval = srv_email_stor_msg_get_cont(
                        retr_p->msg_id,
                        cont_type,
                        &cont_p->cont,
                        NULL,
                        NULL);

            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_GET_CONTENT, cntx_p, retval);

                srv_email_mem_free(cont_p);
                srv_email_get_stor_error(retval, &major, &minor);
                goto ERROR_HANDLE;
            }

            if (!cont_p->cont.this_part_exist)
            {
                srv_email_mem_free(cont_p);
                minor = SRV_EMAIL_RESULT_CONT_NOT_EXIST;
                goto ERROR_HANDLE;
            }
            else if (cont_p->cont.download_flag)
            {
                srv_email_mem_free(cont_p);
                minor = SRV_EMAIL_RESULT_CONT_IN_LOCAL;
                goto ERROR_HANDLE;
            }
            else
            {
                cont_p->type = cont_type;
                cont_p->filename[0] = 0;

                msg_env_p->cont_p = srv_email_imap4_add_cont(msg_env_p->cont_p, cont_p);

                state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_CONTENT;
                state_p->curr_cont_p = msg_env_p->cont_p;
                state_p->part_num = state_p->curr_cont_p->cont.part_num;
            }
            break;

        case SRV_EMAIL_RETRIEVE_ALL_CONTENT:
        case SRV_EMAIL_RETRIEVE_ALL_ATTACHMENT:
        case SRV_EMAIL_RETRIEVE_ALL_PARTS:
            if (retr_p->retr_opt == SRV_EMAIL_RETRIEVE_ALL_CONTENT ||
                retr_p->retr_opt == SRV_EMAIL_RETRIEVE_ALL_PARTS)
            {
                srv_email_stor_msg_get_flag_state(retr_p->msg_id, &flag, &state);
                for (i = 0; i < 2; i++)
                {
                    cont_p = (srv_email_cont_list_struct*)srv_email_mem_alloc(sizeof(srv_email_cont_list_struct));
                    if (!cont_p)
                    {
                        minor = SRV_EMAIL_RESULT_NO_MEMORY;
                        goto ERROR_HANDLE;
                    }
                    memset(cont_p, 0, sizeof(srv_email_cont_list_struct));

                    retval = srv_email_stor_msg_get_cont(
                                retr_p->msg_id,
                                cont_type,
                                &cont_p->cont,
                                NULL,
                                NULL);

                    if (retval != SRV_EMAIL_RESULT_SUCC &&
                        retval != SRV_EMAIL_RESULT_CONT_NOT_EXIST)
                    {
                        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_GET_CONTENT, cntx_p, retval);

                        srv_email_mem_free(cont_p);
                        srv_email_get_stor_error(retval, &major, &minor);
                        goto ERROR_HANDLE;
                    }

                    if (retval == SRV_EMAIL_RESULT_SUCC &&
                        cont_p->cont.this_part_exist &&
                        !cont_p->cont.download_flag)
                    {
                        cont_p->type = cont_type;
                        cont_p->filename[0] = 0;

                        msg_env_p->cont_p = srv_email_imap4_add_cont(msg_env_p->cont_p, cont_p);
                    }
                    else if (retval == SRV_EMAIL_RESULT_SUCC &&
                             cont_p->cont.this_part_exist &&
                             cont_p->cont.download_flag &&
                             (state & SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH))
                    {
                        cont_p->type = cont_type;
                        cont_p->filename[0] = 0;

                        msg_env_p->cont_p = srv_email_imap4_add_cont(msg_env_p->cont_p, cont_p);
                    }
                    else
                    {
                        srv_email_mem_free(cont_p);
                    }

                    cont_type = SRV_EMAIL_STOR_MSG_CONT_HTML;
                }
            }

            if (retr_p->retr_opt == SRV_EMAIL_RETRIEVE_ALL_ATTACHMENT ||
                retr_p->retr_opt == SRV_EMAIL_RETRIEVE_ALL_PARTS)
            {
                retval = srv_email_imap4_list_attach(retr_p->msg_id, &msg_env_p->attach_p);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    minor = retval;
                    goto ERROR_HANDLE;
                }
            }

            if (!msg_env_p->cont_p && !msg_env_p->attach_p)
            {
                minor = SRV_EMAIL_RESULT_MSG_IN_LOCAL;
                goto ERROR_HANDLE;
            }

            if (msg_env_p->cont_p)
            {
                state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_CONTENT;
                state_p->curr_cont_p = msg_env_p->cont_p;
                state_p->part_num = state_p->curr_cont_p->cont.part_num;
            }

            if (msg_env_p->attach_p)
            {
                state_p->curr_att_p = msg_env_p->attach_p;

                if (!msg_env_p->cont_p)
                {
                    state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_ATTACHMENT;
                    state_p->part_num = state_p->curr_att_p->attach.part_num;
                }
            }
            break;

        case SRV_EMAIL_RETRIEVE_SINGLE_ATTACHMENT:
            attach_p = (srv_email_attach_list_struct*)srv_email_mem_alloc(sizeof(srv_email_attach_list_struct));
            if (!attach_p)
            {
                minor = SRV_EMAIL_RESULT_NO_MEMORY;
                goto ERROR_HANDLE;
            }
            memset(attach_p, 0, sizeof(srv_email_attach_list_struct));

            retval = srv_email_stor_msg_get_attch_info(retr_p->msg_id, retr_p->attach_id, &attach_p->attach);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_STOR_GET_ATTACH_INFO, cntx_p, retval);

                srv_email_mem_free(attach_p);
                srv_email_get_stor_error(retval, &major, &minor);
                goto ERROR_HANDLE;
            }

            if (attach_p->attach.download_flag)
            {
                srv_email_mem_free(attach_p);
                minor = SRV_EMAIL_RESULT_ATTACH_IN_LOCAL;
                goto ERROR_HANDLE;
            }

            attach_p->attach_id = retr_p->attach_id;
            attach_p->filename[0] = 0;

            msg_env_p->attach_p = srv_email_imap4_add_attach(msg_env_p->attach_p, attach_p);

            state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_ATTACHMENT;
            state_p->curr_att_p = msg_env_p->attach_p;
            state_p->part_num = state_p->curr_att_p->attach.part_num;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, retr_p->retr_opt, 0, 0);
            break;
    }

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_INIT);

    retval = srv_email_imap4_recv_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_imap4_free_envelope(&state_p->msg_env_p);
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_recv_fsm
 * DESCRIPTION
 *  This function is used to run the IMAP4 RECEIVE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_recv_fsm(srv_email_imap4_cntx_struct *cntx_p)
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
                retval = srv_email_imap4_recv_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE:
                retval = srv_email_imap4_recv_fsm_received(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE:
                retval = srv_email_imap4_recv_fsm_parsed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE:
                retval = srv_email_imap4_recv_fsm_saved(cntx_p);
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

    if (cntx_p->sub_state == SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE &&
        !result_p->result &&
        result_p->major == SRV_EMAIL_MAIL_ERROR &&
        (result_p->minor == SRV_EMAIL_RESULT_CAPABILITY_LIMITATION ||
         result_p->minor == SRV_EMAIL_RESULT_SERVER_ERROR ||
         result_p->minor == SRV_EMAIL_RESULT_INVALID_FORMAT))
    {
        retval = srv_email_imap4_recv_mail_fail(cntx_p);
    }

    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK &&
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_INIT)
    {
        srv_email_imap4_recv_fsm_done(cntx_p);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_folder
 * DESCRIPTION
 *  This function is used to list the remote folder.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  list_p          [IN]        The pointer point to the list folder option
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_list_folder(
                        srv_email_imap4_cntx_struct *cntx_p,
                        srv_email_nwk_list_fldr_struct *list_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;
    WCHAR *filename = NULL;
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_STATE;
        goto ERROR_HANDLE;
    }

    len = mmi_wcslen((const WCHAR*)list_p->filename);
    filename = (WCHAR*)srv_email_mem_alloc((len + 1) * 2);
    if (!filename)
    {
        minor = SRV_EMAIL_RESULT_NO_MEMORY;
        goto ERROR_HANDLE;
    }

    srv_email_imap4_state_init(state_p);

    mmi_wcscpy(filename, list_p->filename);
    filename[len] = 0;
    state_p->fldr_filename = filename;
    state_p->fldr_num = list_p->fldr_num;
    state_p->subcribed_only = list_p->subscribed_only;

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_INIT);

    retval = srv_email_imap4_list_fldr_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_fldr_fsm
 * DESCRIPTION
 *  This function is used to run the IMAP4 LISTING FOLDER FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_list_fldr_fsm(srv_email_imap4_cntx_struct *cntx_p)
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
            case SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_INIT:
                retval = srv_email_imap4_list_fldr_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_SERVER:
                retval = srv_email_imap4_list_fldr_fsm_server_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_LOCAL:
                retval = srv_email_imap4_list_fldr_fsm_local_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_DONE:
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

    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK &&
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_INIT)
    {
        srv_email_imap4_list_fldr_fsm_done(cntx_p);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_update_abort
 * DESCRIPTION
 *  This function is used to stop the IMAP4 UPDATE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_imap4_update_abort(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_UPDATE_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER:
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID:
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE:
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_FLAG:
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

    srv_email_imap4_update_fsm_done(cntx_p);

    comm_p->result.result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_receive_abort
 * DESCRIPTION
 *  This function is used to stop the IMAP4 RECEIVE FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_imap4_receive_abort(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_RECV_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE:
            srv_email_imap4_abort_parse(state_p);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE:
            srv_email_stor_msg_create_abort(state_p->msg_create_handle);
            state_p->msg_create_handle = EMAIL_STOR_INVALID_HANDLE;
            break;

        case SRV_EMAIL_NWK_SUB_STATE_RECV_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_RECV_DONE:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;
    comm_p->result.result = MMI_FALSE;

    srv_email_imap4_recv_fsm_done(cntx_p);

    comm_p->result.result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_list_fldr_abort
 * DESCRIPTION
 *  This function is used to stop the IMAP4 LISTING FOLDER FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_imap4_list_fldr_abort(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_IMAP4_LIST_FLDR_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_SERVER:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_LOCAL:
            break;

        case SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_DONE:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;
    comm_p->result.result = MMI_FALSE;

    srv_email_imap4_list_fldr_fsm_done(cntx_p);

    comm_p->result.result = MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_reqfile_open
 * DESCRIPTION 
 *  imap4 sync reqfile open
 * PARAMETERS 
 *  WCHAR* filename
 * RETURNS 
 *  static FS_HANDLE 
*****************************************************************************/
static FS_HANDLE imap4_sync_reqfile_open(WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    S32 ret = 0;
    U32 cnt = 0;
    U32 wbyte = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open(filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fd < 0)
    {
        return fd;
    }

    cnt = 0;
    ret = FS_Write(fd, &cnt, sizeof(U32), &wbyte);
    if (ret < 0 || wbyte != sizeof(U32))
    {
        FS_Close(fd);
        fd = ret;
    }

    return fd;
}


/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_reqfile_write
 * DESCRIPTION 
 *  imap4 sync reqfile write
 * PARAMETERS 
 *  FS_HANDLE fd
 *  U32 id
 *  U32 opt
 *  U32 flags
 * RETURNS 
 *  static S32 
*****************************************************************************/
static S32 imap4_sync_reqfile_write(FS_HANDLE fd, U32 id, U32 opt, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 arr[3];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arr[0] = id;
    arr[1] = opt;
    arr[2] = flags;

    ret = FS_Write(fd, arr, sizeof(U32) * 3, NULL);
    return ret;
}


/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_reqfile_close
 * DESCRIPTION 
 *  imap4 sync reqfile close
 * PARAMETERS 
 *  FS_HANDLE fd
 *  U32 cnt
 * RETURNS 
 *  static S32 
*****************************************************************************/
static S32 imap4_sync_reqfile_close(FS_HANDLE fd, U32 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Seek(fd, 0, FS_FILE_BEGIN);
    if (ret >= 0)
    {
        ret = FS_Write(fd, &cnt, sizeof(U32), NULL);
    }

    FS_Close(fd);

    return ret;
}


/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_reqfile_delete
 * DESCRIPTION 
 *  imap4 sync reqfile delete
 * PARAMETERS 
 *  WCHAR* filename
 * RETURNS 
 *  static void 
*****************************************************************************/
static void imap4_sync_reqfile_delete(WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Delete(filename);
}


/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_get_command
 * DESCRIPTION 
 *  imap4 sync get command
 * PARAMETERS 
 *  srv_email_imap4_item_struct *item_p
 *  U32 *opt
 *  U32 *flags
 *  MMI_BOOL *need_expunge
 * RETURNS 
 *  static void 
*****************************************************************************/
static void imap4_sync_get_command(srv_email_imap4_item_struct *item_p, 
                U32 *opt, U32 *flags, MMI_BOOL *need_expunge)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_p->nwk_flag & SRV_EMAIL_NWK_FLAG_DELETE_SERVER)
    {
        *flags = EMAIL_PS_MESSAGE_ATTR_DELETE;
        *opt = EMAIL_PS_MESSAGE_ATTR_OPT_ADD;
        *need_expunge = MMI_TRUE;
    }
    else
    {
        ASSERT(item_p->nwk_flag & SRV_EMAIL_NWK_FLAG_UPDATE_SERVER);

        *flags = EMAIL_PS_MESSAGE_ATTR_READED;
        if (item_p->msg_flag & EMAIL_MSG_FLAG_SEEN)
        {
            *opt = EMAIL_PS_MESSAGE_ATTR_OPT_ADD;
        }
        else
        {
            *opt = EMAIL_PS_MESSAGE_ATTR_OPT_CLS;
        }
    }
}


/*****************************************************************************
 * FUNCTION 
 *  srv_email_imap4_sync_abort
 * DESCRIPTION 
 *  srv email imap4 sync abort
 * PARAMETERS 
 *  srv_email_imap4_cntx_struct *cntx_p
 * RETURNS 
 *  srv_email_result_enum 
*****************************************************************************/
srv_email_result_enum srv_email_imap4_sync_abort(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
        SRV_EMAIL_INFO_IMAP4_SYNC_ABORT, 
        cntx_p->sub_state);

    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SYNC_FLAGS &&
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SYNC_DELETE)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    /* Send request to PS */
    srv_email_ps_abort_req(cntx_p->common.ps_handle);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION 
 *  srv_email_imap4_sync
 * DESCRIPTION 
 *  srv email imap4 sync
 * PARAMETERS 
 *  srv_email_imap4_cntx_struct *cntx_p
 *  srv_email_nwk_sync_struct *sync_p
 *  srv_email_nwk_funcptr_type callback
 *  void *user_data
 * RETURNS 
 *  srv_email_result_enum 
*****************************************************************************/
srv_email_result_enum srv_email_imap4_sync(
                        srv_email_imap4_cntx_struct *cntx_p, 
                        srv_email_nwk_sync_struct *sync_p, 
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_IMAP4_SYNC,
        sync_p->all_msg, sync_p->msg_id);

    ASSERT(cntx_p != NULL);
    ASSERT(sess_p != NULL);

    srv_email_imap4_state_init(state_p);

    state_p->all_msg = sync_p->all_msg;
    state_p->msg_id = sync_p->msg_id;
    state_p->need_expunge = KAL_FALSE;

    cntx_p->callback = callback;
    cntx_p->user_data = user_data;

    /* check if need to communicate with PS */
    ret = imap4_sync_init(cntx_p);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_INFO_IMAP4_SYNC_INIT_DONE,
        ret);

    if (ret == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        /* Enter FSM */
        srv_email_imap4_sync_fsm(cntx_p);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    if (ret == SRV_EMAIL_RESULT_SUCC)
    {
        ret = imap4_sync_update_local(cntx_p);
    }

    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        // TRACE here
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_ERROR_IMAP4_SYNC_INIT,
            ret);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION 
 *  srv_email_imap4_sync_fsm
 * DESCRIPTION 
 *  srv email imap4 sync fsm
 * PARAMETERS 
 *  srv_email_imap4_cntx_struct *cntx_p
 * RETURNS 
 *  void 
*****************************************************************************/
void srv_email_imap4_sync_fsm(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
        SRV_EMAIL_INFO_IMAP4_SYNC_FSM,
        cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
    case SRV_EMAIL_NWK_SUB_STATE_SYNC_INIT:
        srv_email_ps_set_flag_req(cntx_p->common.ps_handle,
            cntx_p->state.req_filename);
        cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_SYNC_FLAGS;
        break;

    case SRV_EMAIL_NWK_SUB_STATE_SYNC_FLAGS:
        if (cntx_p->common.result.result && cntx_p->state.need_expunge)
        {
            srv_email_ps_close_folder_req(cntx_p->common.ps_handle);
            cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_SYNC_DELETE;
        }
        else
        {
            imap4_sync_done(cntx_p);
        }
        break;

    case SRV_EMAIL_NWK_SUB_STATE_SYNC_DELETE:
        imap4_sync_done(cntx_p);
        break;

    default:
        EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
        break;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_init
 * DESCRIPTION 
 *  imap4 sync init
 * PARAMETERS 
 *  srv_email_imap4_cntx_struct *cntx_p
 * RETURNS 
 *  static srv_email_result_enum 
*****************************************************************************/
static srv_email_result_enum imap4_sync_init(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_state_struct *state_p = &cntx_p->state;    
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_list_struct *list_p = &cntx_p->session.list;
    srv_email_imap4_item_struct *record_p = NULL;

    U32 num;
    S32 ret;
    FS_HANDLE fd;
    U32 opt, flags = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* INIT */
    memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
    comm_p->result.result = MMI_TRUE;
    state_p->need_expunge = MMI_FALSE;

    /* Open */
    fd = imap4_sync_reqfile_open(state_p->req_filename);
    if (fd < 0)
    {
        // TRACH here
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_SYNC_OPEN_FILE, fd);

        comm_p->result.result = MMI_FALSE;
        comm_p->result.major = SRV_EMAIL_FS_ERROR;
        comm_p->result.minor = fd;
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    num = 0;
    ret = 0;
    if (state_p->all_msg)
    {
        record_p = list_p->record;
        while (record_p != NULL)
        {
            // TRACE here...
            /*
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
                SRV_EMAIL_INFO_IMAP4_SYNC_LIST_RECORD, 
                record_p->seq_no,
                record_p->uid,
                record_p->nwk_flag);
            */

            if (record_p->nwk_flag & (SRV_EMAIL_NWK_FLAG_DELETE_LOCAL))
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
                    SRV_EMAIL_INFO_IMAP4_SYNC_LIST_RECORD, 
                    record_p->seq_no,
                    record_p->uid,
                    record_p->nwk_flag);

                state_p->need_expunge = MMI_TRUE;
                record_p = record_p->next;
                continue;
            }

            if (!(record_p->nwk_flag & (SRV_EMAIL_NWK_FLAG_UPDATE_SERVER | SRV_EMAIL_NWK_FLAG_DELETE_SERVER)))
            {
                record_p = record_p->next;
                continue;
            }

            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
                SRV_EMAIL_INFO_IMAP4_SYNC_LIST_RECORD, 
                record_p->seq_no,
                record_p->uid,
                record_p->nwk_flag);

            imap4_sync_get_command(record_p, &opt, &flags, &state_p->need_expunge);
            ret = imap4_sync_reqfile_write(fd, record_p->uid, opt, flags);
            if (ret < 0)
            {
                // TRACE here
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_SYNC_WRITE_FILE, ret);
                break;
            }
            num++;
            record_p = record_p->next;
        }
    }
    else
    {
        record_p = srv_email_imap4_get_record_by_msgid(list_p, state_p->msg_id);
        if (record_p != NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
                SRV_EMAIL_INFO_IMAP4_SYNC_GET_RECORD, 
                state_p->msg_id, 
                record_p->seq_no,
                record_p->msg_id,
                record_p->nwk_flag);
            imap4_sync_get_command(record_p, &opt, &flags, &state_p->need_expunge);
            ret = imap4_sync_reqfile_write(fd, record_p->uid, opt, flags);
            if (ret < 0)
            {
                // TRACE here
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_SYNC_WRITE_FILE, ret);
            }
            else
            {
            num++;
        }
    }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_SYNC_GET_RECORD, state_p->msg_id);
        }
    }

    if (ret >= 0)
    {
        ret = imap4_sync_reqfile_close(fd, num);
        fd = -1;
    }
    else
    {
        imap4_sync_reqfile_close(fd, num);
    }

    if (ret < 0)
    {
        imap4_sync_reqfile_delete(state_p->req_filename);

        comm_p->result.result = MMI_FALSE;
        comm_p->result.major = SRV_EMAIL_MAIL_ERROR;
        comm_p->result.minor = SRV_EMAIL_RESULT_FS_ERROR;

        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (num == 0)
    {
        /* No need this file any more */
        imap4_sync_reqfile_delete(state_p->req_filename);
    }

    if (state_p->all_msg)
    {
        if (num == 0)
        {
            if (state_p->need_expunge)
            {
                cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_SYNC_FLAGS;
                return SRV_EMAIL_RESULT_WOULDBLOCK;
            }
            else
            {
                return SRV_EMAIL_RESULT_SUCC;
            }
        }
        else
        {
            cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_SYNC_INIT;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
    }
    else
    {
        if (num == 0)
        {
            /* The requested message can NOT be found */
            comm_p->result.result = MMI_FALSE;
            comm_p->result.major = SRV_EMAIL_MAIL_ERROR;
            comm_p->result.minor = SRV_EMAIL_RESULT_MSG_NOT_EXIST;

            return SRV_EMAIL_RESULT_MSG_NOT_EXIST;
        }
        else
        {
            cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_SYNC_INIT;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
    }
}


/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_update_item
 * DESCRIPTION 
 *  imap4 sync update item
 * PARAMETERS 
 *  EMAIL_STOR_HANDLE stor_handle
 *  srv_email_imap4_item_struct *record_p
 * RETURNS 
 *  static srv_email_result_enum 
*****************************************************************************/
static srv_email_result_enum imap4_sync_update_item(
                                EMAIL_STOR_HANDLE stor_handle, 
                                srv_email_imap4_item_struct *record_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum ret = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(record_p->nwk_flag & SRV_EMAIL_NWK_FLAG_IN_LOCAL) || 
        (record_p->msg_id == EMAIL_MSG_INVALID_ID))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_IMAP4_SYNC_UPDATE_LOCAL, -100);
        return SRV_EMAIL_RESULT_SUCC;
    }

    if ((record_p->nwk_flag & SRV_EMAIL_NWK_FLAG_DELETE_SERVER) ||
        (record_p->nwk_flag & SRV_EMAIL_NWK_FLAG_DELETE_LOCAL))
    {
        /* remove from storage */
        ret = srv_email_stor_fldr_sync_msg_del(stor_handle, record_p->msg_id);
    }
    else
    {
        ret = srv_email_stor_fldr_sync_msg_set_flag(
            stor_handle,
            record_p->msg_id,
            (EMAIL_MSG_FLAG)record_p->msg_flag);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_IMAP4_SYNC_UPDATE_LOCAL, ret);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_update_local
 * DESCRIPTION 
 *  imap4 sync update local
 * PARAMETERS 
 *  srv_email_imap4_cntx_struct *cntx_p
 * RETURNS 
 *  static srv_email_result_enum 
*****************************************************************************/
static srv_email_result_enum imap4_sync_update_local(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_state_struct *state_p = &cntx_p->state;
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_list_struct *list_p = &cntx_p->session.list;
    srv_email_imap4_item_struct *prev_p = NULL;
    srv_email_imap4_item_struct *record_p = NULL;
    EMAIL_STOR_HANDLE handle = EMAIL_STOR_INVALID_HANDLE;
    srv_email_result_enum ret = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL del_item = MMI_FALSE;
    S32 major, minor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_email_stor_fldr_sync_msg_open(
            comm_p->acct_id, 
            sess_p->fldr_id, 
            &handle);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_stor_error(ret, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);

        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_SYNC_STORAGE_OPEN, ret, major, minor);
        return SRV_EMAIL_RESULT_FAIL;
    }

    state_p->stor_handle = handle;

    if (state_p->all_msg)
    {
        prev_p = list_p->record;
        record_p = list_p->record;
        while (record_p != NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
                SRV_EMAIL_INFO_IMAP4_SYNC_UPDATE_RECORD, 
                record_p->seq_no,
                record_p->uid,
                record_p->nwk_flag);

            del_item = MMI_FALSE;
            if (record_p->nwk_flag & 
                (SRV_EMAIL_NWK_FLAG_UPDATE_LOCAL | 
                 SRV_EMAIL_NWK_FLAG_UPDATE_SERVER |
                 SRV_EMAIL_NWK_FLAG_DELETE_SERVER |
                 SRV_EMAIL_NWK_FLAG_DELETE_LOCAL))
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
                    SRV_EMAIL_INFO_IMAP4_SYNC_LIST_RECORD, 
                    record_p->seq_no,
                    record_p->uid,
                    record_p->nwk_flag);
                ret = imap4_sync_update_item(state_p->stor_handle, record_p);
                if (ret != SRV_EMAIL_RESULT_SUCC)
                {
                    // TRACE here
                    break;
                }

                if (record_p->nwk_flag & 
                    (SRV_EMAIL_NWK_FLAG_DELETE_SERVER | 
                     SRV_EMAIL_NWK_FLAG_DELETE_LOCAL))
                {
                    del_item = MMI_TRUE;
                }

                record_p->nwk_flag &= ~(SRV_EMAIL_NWK_FLAG_UPDATE_LOCAL | 
                    SRV_EMAIL_NWK_FLAG_UPDATE_SERVER |
                    SRV_EMAIL_NWK_FLAG_DELETE_SERVER | 
                    SRV_EMAIL_NWK_FLAG_DELETE_LOCAL);
            }

            /* delete it */
            if (del_item)
            {
                if (record_p == list_p->record)
                {
                    list_p->record = record_p->next;
                    srv_email_mem_free(record_p);
                    prev_p = list_p->record;
                    record_p = list_p->record;
                }
                else
                {
                    prev_p->next = record_p->next;
                    srv_email_mem_free(record_p);
                    record_p = prev_p->next;
                }
            }
            else
            {
                prev_p = record_p;
                record_p = record_p->next;
            }
        }
    }
    else
    {
        record_p = srv_email_imap4_get_record_by_msgid(list_p, state_p->msg_id);
        if (record_p != NULL)
        {
            ret = imap4_sync_update_item(cntx_p, record_p);
        }
    }

    if (ret == SRV_EMAIL_RESULT_SUCC)
    {
        ret = srv_email_stor_fldr_sync_msg_close(&state_p->stor_handle);
    }
    else
    {
        srv_email_stor_fldr_sync_msg_close(&state_p->stor_handle);
    }
    state_p->stor_handle = EMAIL_STOR_INVALID_HANDLE;

    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_stor_error(ret, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_SYNC_STORAGE_XXX, ret, major, minor);
        return SRV_EMAIL_RESULT_FAIL;
    }

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION 
 *  imap4_sync_done
 * DESCRIPTION 
 *  imap4 sync done
 * PARAMETERS 
 *  srv_email_imap4_cntx_struct *cntx_p
 * RETURNS 
 *  static void 
*****************************************************************************/
static void imap4_sync_done(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;
    if (cntx_p->common.result.result)
    {
        imap4_sync_update_local(cntx_p);
    }

    /* delete temp file */
    imap4_sync_reqfile_delete(cntx_p->state.req_filename);

    if (!cntx_p->common.result.result || 
        cntx_p->ps_state != EMAIL_PS_PROTOCOL_STATE_SELECTED)
    {
        srv_email_imap4_session_free(&cntx_p->session);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
        SRV_EMAIL_INFO_IMAP4_SYNC_DONE, 
        cntx_p->common.result.result, 
        cntx_p->callback, 
        cntx_p->user_data);

    if (cntx_p->callback)
    {
        cntx_p->callback(cntx_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_is_push_allowed
 * DESCRIPTION
 *  This function is used to check if the IMAP4 push is allowed or not.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_email_imap4_is_push_allowed(srv_email_imap4_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

    if (sess_p->fldr_id != fldr_id)
    {
        return MMI_FALSE;
    }

    if (sess_p->sync_with_server ||
        (cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_UPDATING &&
         cntx_p->sub_state > SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER))
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
 *  srv_email_imap4_refresh
 * DESCRIPTION
 *  This function is used to refresh the IMAP4 inbox connection.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  retrieve_amount [IN]        The retrieve amount
 *  callback        [IN]        The callback function
 *  user_data       [IN]        The callback related user data
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_refresh(
                        srv_email_imap4_cntx_struct *cntx_p,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_STATE;
        goto ERROR_HANDLE;
    }

    srv_email_imap4_session_free(sess_p);

    fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

    retval = srv_email_imap4_update(cntx_p, fldr_id, retrieve_amount, callback, user_data);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_proc_om_notify
 * DESCRIPTION
 *  This function is used to process the Object Management notification.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the IMAP4 context
 *  notify_p        [IN]        The pointer point to the notification
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_imap4_proc_om_notify(
        srv_email_imap4_cntx_struct *cntx_p,
        srv_email_om_notify_struct *notify_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_imap4_session_struct *sess_p = &cntx_p->session;
    srv_email_imap4_item_struct *record_p = NULL;
    srv_email_om_notify_msg_struct *msg_p = (srv_email_om_notify_msg_struct*)notify_p->data;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (notify_p->notify_type != SRV_EMAIL_OM_NOTIFY_MSG_DEL &&
        notify_p->notify_type != SRV_EMAIL_OM_NOTIFY_MSG_UPDATE)
    {
        return;
    }

    fldr_id = srv_email_stor_msg_id_to_fldr_id(msg_p->msg_id);
    if (!sess_p->sync_with_server || fldr_id != sess_p->fldr_id)
    {
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_IMAP4_PROC_OM_NOTIFY,
        cntx_p,
        notify_p->notify_type);

    record_p = srv_email_imap4_get_record_by_msgid(&sess_p->list, msg_p->msg_id);
    if (!record_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_OM_DEL_MSG_GET_RECORD, cntx_p);
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


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_add_cont
 * DESCRIPTION
 *  This function is used to add the content into the list.
 * PARAMETERS
 *  header          [IN]        The pointer point to the content list header
 *  cont_p          [IN]        The pointer point to the new content
 * RETURNS
 *  The new content list header pointer.
 *****************************************************************************/
static srv_email_cont_list_struct *srv_email_imap4_add_cont(
                                    srv_email_cont_list_struct *header_p,
                                    srv_email_cont_list_struct *cont_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_cont_list_struct *ptr = header_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cont_p->next = NULL;

    if (!header_p)
    {
        return cont_p;
    }

    while (ptr->next)
    {
        ptr = ptr->next;
    }

    ptr->next = cont_p;

    return header_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_add_attach
 * DESCRIPTION
 *  This function is used to add the attachment into the list.
 * PARAMETERS
 *  header_p        [IN]        The pointer point to the attachment list header
 *  attach_p        [IN]        The pointer point to the new attachment
 * RETURNS
 *  The new attachment list header pointer.
 *****************************************************************************/
static srv_email_attach_list_struct *srv_email_imap4_add_attach(
                                        srv_email_attach_list_struct *header_p,
                                        srv_email_attach_list_struct *attach_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_attach_list_struct *ptr = header_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attach_p->next = NULL;

    if (!header_p)
    {
        return attach_p;
    }

    while (ptr->next)
    {
        ptr = ptr->next;
    }

    ptr->next = attach_p;

    return header_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_cont_header
 * DESCRIPTION
 *  This function is used to read the content header of the email.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  cont_p          [IN]        Used to store the content header when not null
 * RETURNS
 *  The error code.
 *****************************************************************************/
static S32 srv_email_imap4_read_cont_header(FS_HANDLE fd, srv_email_stor_cont_header_struct *cont_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR part_num[EMAIL_PS_MAX_PART_NUMBER_LEN + 1];
    S32 ret = -1;
    U32 len = 0;
    U32 rbyte = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read the subtype length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the subtype string */
    if (cont_p)
    {
        if (len > 0)
        {
            /* Fill the content type */
            strcpy(cont_p->content_type, "text/");

            if (len > EMAIL_STOR_CONT_TYPE_STR_LEN - 5)
            {
                offset = len - (EMAIL_STOR_CONT_TYPE_STR_LEN - 5);
                len = EMAIL_STOR_CONT_TYPE_STR_LEN - 5;
            }

            ret = FS_Read(fd, &cont_p->content_type[5], len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                return ret;
            }
        }
    }
    else
    {
        offset = len;
    }

    if (offset)
    {
        ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
        offset = 0;
    }

    /* Read the encoding type length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the encoding type string */
    if (cont_p)
    {
        if (len > 0)
        {
            if (len > EMAIL_STOR_ENCODING_LEN)
            {
                offset = len - EMAIL_STOR_ENCODING_LEN;
                len = EMAIL_STOR_ENCODING_LEN;
            }

            ret = FS_Read(fd, cont_p->encoding, len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                return ret;
            }
            cont_p->encoding[len] = '\0';
        }
        else
        {
            strcpy(cont_p->encoding, "7bit");
        }
    }
    else
    {
        offset = len;
    }

    if (offset > 0)
    {
        ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
        offset = 0;
    }

    /* Read the charset length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the charset string */
    if (cont_p)
    {
        if (len > 0)
        {
            if (len > EMAIL_STOR_CONT_CHARSET_STR_LEN)
            {
                offset = len - EMAIL_STOR_CONT_CHARSET_STR_LEN;
                len = EMAIL_STOR_CONT_CHARSET_STR_LEN;
            }

            ret = FS_Read(fd, cont_p->charset, len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                return ret;
            }
            cont_p->charset[len] = '\0';
        }
        else
        {
            strcpy(cont_p->charset, "us-ascii");
        }
    }
    else
    {
        offset = len;
    }

    if (offset > 0)
    {
        ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
        offset = 0;
    }

    /* Read the part number */
    len = EMAIL_PS_MAX_PART_NUMBER_LEN + 1;
    if (cont_p)
    {
        ret = FS_Read(fd, part_num, len, &rbyte);
        if (ret < 0 || rbyte != len)
        {
            return ret;
        }
        len = strlen(part_num);
        EMAILSRV_EXT_ASSERT(len <= EMAIL_STOR_PART_NUM_LEN, len, EMAIL_STOR_PART_NUM_LEN, 0);
        strcpy(cont_p->part_num, part_num);
    }
    else
    {
        ret = FS_Seek(fd, len, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
    }

    /* Read the server size */
    if (cont_p)
    {
        ret = FS_Read(fd, &cont_p->server_size, 4, &rbyte);
        if (ret < 0 || rbyte != 4)
        {
            return ret;
        }
    }
    else
    {
        ret = FS_Seek(fd, 4, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
    }

    /* Convert content type, charset and encoding type to lower */
    if (cont_p)
    {
        app_strtolower(cont_p->content_type);
        app_strtolower(cont_p->charset);
        app_strtolower(cont_p->encoding);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_attach_header
 * DESCRIPTION
 *  This function is used to read the attachment header of the email.
 * PARAMETERS
 *  fd              [IN]        The file handle
 *  cont_p          [OUT]       Used to store the content header when not null
 *  major           [OUT]       Used to store the major error
 * RETURNS
 *  The error code.
 *****************************************************************************/
static S32 srv_email_imap4_read_attach_header(FS_HANDLE fd, srv_email_stor_attch_struct *attach_p, S32 *major)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR part_num[EMAIL_PS_MAX_PART_NUMBER_LEN + 1];
    CHAR cid[SRV_EMAIL_CID_MAX_LEN + 1];
    CHAR *ptr = cid;
    S32 ret = -1;
    U32 len = 0;
    U32 rbyte = 0;
    U32 type_len = 0;
    S32 chset_id;
    CHAR *tmpbuf = NULL;
    WCHAR *convbuf = NULL;
    WCHAR *convptr = NULL;
    CHAR *utf8buf = NULL;
    S32 convlen = 0;
    S32 utf8len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *major = SRV_EMAIL_FS_ERROR;

    /* Read the type length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the content type string */
    if (attach_p)
    {
        if (len > 0)
        {
            if (len > EMAIL_STOR_CONT_TYPE_STR_LEN)
            {
                offset = len - EMAIL_STOR_CONT_TYPE_STR_LEN;
                len = EMAIL_STOR_CONT_TYPE_STR_LEN;
            }

            ret = FS_Read(fd, attach_p->content_type, len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                return ret;
            }
            attach_p->content_type[len] = '/';
            type_len = len + 1;
        }
    }
    else
    {
        offset = len;
    }

    if (offset)
    {
        ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
        offset = 0;
    }

    /* Read the subtype length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the subtype string */
    if (attach_p)
    {
        if (len > 0)
        {
            if (len > EMAIL_STOR_CONT_TYPE_STR_LEN - type_len)
            {
                offset = len;
                strcpy(attach_p->content_type, "application/octet-stream");
            }
            else
            {
                ret = FS_Read(fd, &attach_p->content_type[type_len], len, &rbyte);
                if (ret < 0 || rbyte != len)
                {
                    return ret;
                }
            }
        }
    }
    else
    {
        offset = len;
    }

    if (offset)
    {
        ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
        offset = 0;
    }

    /* Read the encoding type length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the encoding type string */
    if (attach_p)
    {
        if (len > 0)
        {
            if (len > EMAIL_STOR_ENCODING_LEN)
            {
                offset = len - EMAIL_STOR_ENCODING_LEN;
                len = EMAIL_STOR_ENCODING_LEN;
            }

            ret = FS_Read(fd, attach_p->encoding, len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                return ret;
            }
            attach_p->encoding[len] = '\0';
        }
        else
        {
            strcpy(attach_p->encoding, "7bit");
        }
    }
    else
    {
        offset = len;
    }

    if (offset > 0)
    {
        ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
        offset = 0;
    }

    /* Read the charset length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the charset string */
    if (attach_p)
    {
        if (len > 0)
        {
            if (len > EMAIL_STOR_CONT_CHARSET_STR_LEN)
            {
                offset = len - EMAIL_STOR_CONT_CHARSET_STR_LEN;
                len = EMAIL_STOR_CONT_CHARSET_STR_LEN;
            }

            ret = FS_Read(fd, attach_p->charset, len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                return ret;
            }
            attach_p->charset[len] = '\0';
        }
        else
        {
            strcpy(attach_p->charset, "US-ASCII");
        }
    }
    else
    {
        offset = len;
    }

    if (offset > 0)
    {
        ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
        offset = 0;
    }

    /* Read the part number */
    len = EMAIL_PS_MAX_PART_NUMBER_LEN + 1;
    if (attach_p)
    {
        ret = FS_Read(fd, part_num, len, &rbyte);
        if (ret < 0 || rbyte != len)
        {
            return ret;
        }
        len = strlen(part_num);
        EMAILSRV_EXT_ASSERT(len <= EMAIL_STOR_PART_NUM_LEN, len, EMAIL_STOR_PART_NUM_LEN, 0);
        strcpy(attach_p->part_num, part_num);
    }
    else
    {
        ret = FS_Seek(fd, len, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
    }

    /* Read the server size */
    if (attach_p)
    {
        ret = FS_Read(fd, &attach_p->server_size, 4, &rbyte);
        if (ret < 0 || rbyte != 4)
        {
            return ret;
        }
    }
    else
    {
        ret = FS_Seek(fd, 4, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
    }

    /* Read the attachment name length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the attachment name string */
    if (len > 0)
    {
        if (attach_p)
        {
            tmpbuf = (CHAR*)srv_email_mem_alloc(len + 2);
            if (!tmpbuf)
            {
                *major = SRV_EMAIL_MAIL_ERROR;
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }

            convlen = (len + 2) * 2;
            convbuf = (WCHAR*)srv_email_mem_alloc(convlen);
            if (!convbuf)
            {
                srv_email_mem_free(tmpbuf);
                *major = SRV_EMAIL_MAIL_ERROR;
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }

            ret = FS_Read(fd, tmpbuf, len, &rbyte);
            if (ret < 0 || rbyte != len)
            {
                srv_email_mem_free(tmpbuf);
                srv_email_mem_free(convbuf);
                return ret;
            }
            tmpbuf[len] = '\0';
            tmpbuf[len + 1] = '\0';

            srv_email_string_decode((WCHAR*)tmpbuf, convbuf, &convlen, &chset_id);
            if (convlen)
            {
                WCHAR *temp_conv_buf = NULL;
                if (convlen > EMAIL_ATTCH_FILE_NAME_LEN)
                {
                    temp_conv_buf = OslMalloc(EMAIL_ATTCH_FILE_NAME_LEN * 2 + 2);
                    srv_email_handle_file_name(temp_conv_buf, convbuf, EMAIL_ATTCH_FILE_NAME_LEN);
                    convptr = temp_conv_buf;
                }
                else
                {
                    convptr = convbuf;
                }

                utf8len = EMAIL_ATTCH_FILE_NAME_LEN * 3 + 1;
                utf8buf = (CHAR*)OslMalloc(utf8len);
                memset(utf8buf, 0, utf8len);
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (CHAR*)convptr, utf8buf, utf8len);
                len = EMAIL_STOR_ENCOD_FILE_NAME_LEN + 1;
                rfc2047_encode_string(
                    (kal_int8*)utf8buf,
                    strlen(utf8buf),
                    (kal_int8*)attach_p->file_name,
                    (kal_int32*)&len,
                    0,
                    MMI_CHSET_UTF8);
                OslMfree(utf8buf);
                if (convlen > EMAIL_ATTCH_FILE_NAME_LEN)
                {
                    OslMfree(temp_conv_buf);
                }
            }
            else
            {
                email_get_file_name(
                    attach_p->file_name,
                    EMAIL_STOR_ENCOD_FILE_NAME_LEN - 1,
                    0,
                    &attach_p->content_type[type_len]);
            }

            srv_email_mem_free(tmpbuf);
            srv_email_mem_free(convbuf);
        }
        else
        {
            ret = FS_Seek(fd, len, FS_FILE_CURRENT);
            if (ret < 0)
            {
                return ret;
            }
        }
    }
    else
    {
        if (attach_p)
        {
            email_get_file_name(
                attach_p->file_name,
                EMAIL_STOR_ENCOD_FILE_NAME_LEN - 1,
                0,
                &attach_p->content_type[type_len]);
        }
    }

    /* Read the attachment CID length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Read the attachment CID string */
    if (attach_p)
    {
        if (len > 0)
        {
            if (len > SRV_EMAIL_CID_MAX_LEN)
            {
                offset = len;
            }
            else
            {
                ret = FS_Read(fd, cid, len, &rbyte);
                if (ret < 0 || rbyte != len)
                {
                    return ret;
                }
                cid[len] = '\0';

                len = strlen(cid);
                if (cid[0] == '<' && cid[len - 1] == '>')
                {
                    cid[len - 1] = '\0';
                    ptr++;
                    len -= 2;
                }

                memcpy(attach_p->cid, ptr, len);
                attach_p->cid[len] = '\0';
            }
        }
    }
    else
    {
        offset = len;
    }

    if (offset)
    {
        ret = FS_Seek(fd, offset, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
        offset = 0;
    }

    /* Read the location length */
    ret = FS_Read(fd, &len, 4, &rbyte);
    if (ret < 0 || rbyte != 4)
    {
        return ret;
    }

    /* Skip the location */
    if (len > 0)
    {
        ret = FS_Seek(fd, len, FS_FILE_CURRENT);
        if (ret < 0)
        {
            return ret;
        }
    }

    /* Convert content type, charset and encoding type to lower */
    if (attach_p)
    {
        app_strtolower(attach_p->content_type);
        app_strtolower(attach_p->drm_content_type);
        app_strtolower(attach_p->charset);
        app_strtolower(attach_p->encoding);
    }

    *major = 0;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_new_envelope
 * DESCRIPTION
 *  This function is used to alloc the new email envelope structure.
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer of the envelope structure.
 *****************************************************************************/
srv_email_msg_env_struct *srv_email_imap4_new_envelope(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_env_struct *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = (srv_email_msg_env_struct*)srv_email_mem_alloc(sizeof(srv_email_msg_env_struct));
    if (!ptr)
    {
        return NULL;
    }

    memset(ptr, 0, sizeof(srv_email_msg_env_struct));

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_free_envelope
 * DESCRIPTION
 *  This function is used to free the envelope structure.
 * PARAMETERS
 *  msg_env_p       [IN/OUT]    The address of the pointer point to the envelope structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_imap4_free_envelope(srv_email_msg_env_struct **msg_env_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_msg_env_struct *env_p = *msg_env_p;
    srv_email_addr_list_struct *addr_p = NULL;
    srv_email_addr_list_struct *addr_next_p = NULL;
    srv_email_cont_list_struct *cont_p = NULL;
    srv_email_attach_list_struct *attach_p = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!env_p)
    {
        return;
    }

    if (env_p->msg_header_p)
    {
        srv_email_mem_free(env_p->msg_header_p);
    }

    if (env_p->subject_p)
    {
        srv_email_mem_free(env_p->subject_p);
    }

    if (env_p->from_p)
    {
        srv_email_mem_free(env_p->from_p);
    }

    if (env_p->reply_to_p)
    {
        srv_email_mem_free(env_p->reply_to_p);
    }

    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
            case 0:
                addr_p = env_p->to_addr_p;
                break;

            case 1:
                addr_p = env_p->cc_addr_p;
                break;

            case 2:
                addr_p = env_p->bcc_addr_p;
                break;

            default:
                break;
        }

        while (addr_p)
        {
            addr_next_p = addr_p->next;
            srv_email_mem_free(addr_p);
            addr_p = addr_next_p;
        }
    }

    cont_p = env_p->cont_p;
    while (cont_p)
    {
        env_p->cont_p = cont_p->next;
        FS_Delete((const WCHAR*)cont_p->filename);
        srv_email_mem_free(cont_p);
        cont_p = env_p->cont_p;
    }

    attach_p = env_p->attach_p;
    while (attach_p)
    {
        env_p->attach_p = attach_p->next;
        FS_Delete((const WCHAR*)attach_p->filename);
        srv_email_mem_free(attach_p);
        attach_p = env_p->attach_p;
    }

    srv_email_mem_free(env_p);

    *msg_env_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_get_encode_type
 * DESCRIPTION
 *  This function is used to get the encoding type.
 * PARAMETERS
 *  enc_str         [IN]        The encoding string
 * RETURNS
 *  The encoding type
 *****************************************************************************/
S32 srv_email_imap4_get_encode_type(const CHAR *enc_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EMAIL_MIME_ENCMAX; i++)
    {
        if (!app_stricmp((kal_char*)enc_str, (kal_char*)srv_email_imap4_encodings[i]))
        {
            return i;
        }
    }

    return EMAIL_MIME_ENCOTHER;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_body_struct
 * DESCRIPTION
 *  This function is used to read the body structure of the email.
 * PARAMETERS
 *  filename        [IN]        The filename
 *  msg_env_p       [OUT]       Used to store the body structure information
 *  major_error     [OUT]       The major error
 *  minor_error     [OUT]       The minor error
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_read_body_struct(
                        const WCHAR *filename,
                        srv_email_msg_env_struct *msg_env_p,
                        S32 *major_error,
                        S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_stor_msg_create_header_struct *msg_header_p = msg_env_p->msg_header_p;
    srv_email_cont_list_struct *cont_p = NULL;
    srv_email_attach_list_struct *attach_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    FS_HANDLE fd = -1;
    U32 rbyte = 0;
    U32 cont_cnt = 0;
    U32 attach_cnt = 0;
    U32 i = 0;
    U32 count = 0;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;
    S32 errcode = 0;
    srv_email_cont_list_struct *text_cont_p = NULL;
    srv_email_cont_list_struct *html_cont_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open(filename, FS_READ_ONLY);
    if (fd < 0)
    {
        minor = fd;
        goto EXIT_HANDLE; 
    }

    /* Read the content number */
    minor = FS_Read(fd, &cont_cnt, 4, &rbyte);
    if (minor < 0 || rbyte != 4)
    {
        goto EXIT_HANDLE;
    }

    /* Read the attachment number */
    minor = FS_Read(fd, &attach_cnt, 4, &rbyte);
    if (minor < 0 || rbyte != 4)
    {
        goto EXIT_HANDLE;
    }

    /* Read the content */
    for (i = 0; i < cont_cnt; i++)
    {
        cont_p = (srv_email_cont_list_struct*)srv_email_mem_alloc(sizeof(srv_email_cont_list_struct));
        if (!cont_p)
        {
            major = SRV_EMAIL_MAIL_ERROR;
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto EXIT_HANDLE;
        }
        memset(cont_p, 0, sizeof(srv_email_cont_list_struct));
        cont_p->cont.this_part_exist = MMI_TRUE;

        minor = srv_email_imap4_read_cont_header(fd, &cont_p->cont);
        if (minor < 0)
        {
            srv_email_mem_free(cont_p);
            goto EXIT_HANDLE;
        }

        if (!strcmp(cont_p->cont.content_type, "text/plain"))
        {
            cont_p->type = SRV_EMAIL_STOR_MSG_CONT_TEXT;
            text_cont_p = cont_p;
        }
        else if (!strcmp(cont_p->cont.content_type, "text/html") && cont_p->cont.server_size)
        {
            cont_p->type = SRV_EMAIL_STOR_MSG_CONT_HTML;
            html_cont_p = cont_p;
        }
        else
        {
            srv_email_mem_free(cont_p);
        }
    }

    if (text_cont_p)
    {
        msg_env_p->cont_p = srv_email_imap4_add_cont(msg_env_p->cont_p, text_cont_p);
    }
    if (html_cont_p)
    {
        msg_env_p->cont_p = srv_email_imap4_add_cont(msg_env_p->cont_p, html_cont_p);
    }

    if (text_cont_p && text_cont_p->cont.server_size == 0)
    {
        kal_wsprintf(
            text_cont_p->filename,
            "%s%s%08X.part",
            srv_email_get_root_path(),
            SRV_EMAIL_NWK_FILE_PATH,
            text_cont_p);

        minor = FS_Open(text_cont_p->filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (minor < 0)
        {
            goto EXIT_HANDLE;
        }
        FS_Close(minor);

        text_cont_p->cont.download_flag = MMI_TRUE;
    }

    /* Read the attachment */
    for (i = 0; i < attach_cnt; i++)
    {
        if (count < SRV_EMAIL_MAX_ATTACH_NUM)
        {
            attach_p = (srv_email_attach_list_struct*)srv_email_mem_alloc(sizeof(srv_email_attach_list_struct));
            if (!attach_p)
            {
                major = SRV_EMAIL_MAIL_ERROR;
                minor = SRV_EMAIL_RESULT_NO_MEMORY;
                goto EXIT_HANDLE;
            }
            memset(attach_p, 0, sizeof(srv_email_attach_list_struct));

            minor = srv_email_imap4_read_attach_header(fd, &attach_p->attach, &errcode);
            if (errcode != 0)
            {
                major = errcode;
                srv_email_mem_free(attach_p);
                goto EXIT_HANDLE;
            }

            msg_env_p->attach_p = srv_email_imap4_add_attach(msg_env_p->attach_p, attach_p);
            msg_header_p->attch_num++;
            count++;
        }
        else
        {
            minor = srv_email_imap4_read_attach_header(fd, NULL, &errcode);
            if (errcode != 0)
            {
                major = errcode;
                goto EXIT_HANDLE;
            }
            msg_header_p->remain_attach_num++;
        }
    }

    retval = SRV_EMAIL_RESULT_SUCC;

EXIT_HANDLE:

    if (fd >= 0)
    {
        FS_Close(fd);
    }
    FS_Delete(filename);

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_IMAP4_READ_BODYSTRUCT, retval, major, minor);

        if (major_error)
        {
            *major_error = major;
        }
        if (minor_error)
        {
            *minor_error = minor;
        }
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_imap4_read_content
 * DESCRIPTION
 *  This function is used to read the content of the email.
 * PARAMETERS
 *  filename        [IN]        The filename
 *  cont_p          [OUT]       Used to store the content information
 *  major_error     [OUT]       The major error
 *  minor_error     [OUT]       The minor error
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_imap4_read_content(
                        const WCHAR *filename,
                        srv_email_cont_list_struct *cont_p,
                        S32 *major_error,
                        S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        cont_p->filename,
        "%s%s%08X.part",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        cont_p);

    FS_Delete(cont_p->filename);
    ret = FS_Rename(filename, cont_p->filename);
    if (ret < 0)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_ERROR_IMAP4_READ_CONTENT,
            SRV_EMAIL_RESULT_FAIL,
            SRV_EMAIL_FS_ERROR,
            ret);

        if (major_error)
        {
            *major_error = SRV_EMAIL_FS_ERROR;
        }
        if (minor_error)
        {
            *minor_error = ret;
        }

        return SRV_EMAIL_RESULT_FAIL;
    }

    cont_p->cont.download_flag = MMI_TRUE;

    return SRV_EMAIL_RESULT_SUCC;
}

#endif /* defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__) */

