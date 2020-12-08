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
 * EmailSrvMessage.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to declare the Email message function.
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _EMAIL_SRV_MESSAGE_H
#define _EMAIL_SRV_MESSAGE_H

#include "Conversions.h"

#include "EmailSrvGProt.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvNetwork.h"

#include "MMIDataType.h"
#include "kal_general_types.h"

#ifdef __SMS_CLOUD_SUPPORT__
#define SRV_EMAIL_MSG_FOR_CLOUD 1
#else
#define SRV_EMAIL_MSG_FOR_CLOUD 0
#endif

#define SRV_EMAIL_MESSAGE_HANLDE_MAX_NUMBER             (5+SRV_EMAIL_MSG_FOR_CLOUD)

#define SRV_EMAIL_MESSAGE_REQ_MAX_NUMBER                (10)

/* The enum used for indicate state of message object */
typedef enum
{
    SRV_EMAIL_MSG_ACCESS_STATE_INIT,
    SRV_EMAIL_MSG_ACCESS_STATE_PARSING,
    SRV_EMAIL_MSG_ACCESS_STATE_READ,
    SRV_EMAIL_MSG_ACCESS_STATE_EDIT,
    SRV_EMAIL_MSG_ACCESS_STATE_LOCAL_OPERATING,
    SRV_EMAIL_MSG_ACCESS_STATE_NET_OPERATING,
    SRV_EMAIL_MSG_ACCESS_STATE_TOTAL
} srv_email_msg_access_state_enum;

/* The enum used for indicate operation of message object */
typedef enum
{
    SRV_EMAIL_MSG_OPERATION_NONE,
    SRV_EMAIL_MSG_OPERATION_PARSE = SRV_EMAIL_NWK_TOTAL_ACTION,
    SRV_EMAIL_MSG_OPERATION_SAVE,
    SRV_EMAIL_MSG_OPERATION_SAVE_NEW,
    SRV_EMAIL_MSG_OPERATION_COPY,
    SRV_EMAIL_MSG_OPERATION_GET_HTML,
    SRV_EMAIL_MSG_OPERATION_TOTAL
} srv_email_msg_operation_enum;

#ifdef __SMS_CLOUD_SUPPORT__
typedef struct
{
    void *buff;
    U32 buff_len;
} srv_email_msg_extra_field_struct;
#endif /* __SMS_CLOUD_SUPPORT__ */

/* The email message information structure */
typedef struct
{
    MMI_BOOL in_use;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_MSG_ID msg_id;
    S32 to_addr_num;                        /* The number of the email address in filed To */
    S32 remain_to_addr_num;
    S32 cc_addr_num;                        /* The number of the email address in filed Cc */
    S32 remain_cc_addr_num;
    S32 bcc_addr_num;                       /* The number of the email address in filed Bcc */
    S32 remain_bcc_addr_num;
    S32 attach_num;                         /* The number of the attachment */
    S32 remain_attach_num;
    U8 priority;                            /* The priority of the email */
    S32 server_size;                        /* The server size of the email */
    S32 local_size;                         /* The local size of the email */
    S32 mail_date;                          /* The date and time (UTC) of the email in field Date */
    S32 recv_date;                          /* The date and time (UTC) that received this email */
    U32 state;                              /* srv_email_state_enum */
    EMAIL_MSG_FLAG flag;
    srv_email_msg_access_state_enum access_state;          /* Read write open or read only open */
    srv_email_addr_struct sender_addr;      /* The sender address of the email (valid when reading only) */
    srv_email_addr_struct reply_to_addr;    /* The reply to address of the email (valid when reading only) */
    S32 subject_charset;
    S32 content_charset;
    MMI_BOOL has_html;
    S32 html_charset;

#ifdef __SMS_CLOUD_SUPPORT__
    srv_email_msg_extra_field_struct sms_uid;
    srv_email_msg_extra_field_struct sms_addr;
    srv_email_msg_extra_field_struct sms_data;
#endif /* __SMS_CLOUD_SUPPORT__ */

    srv_email_msg_funcptr_type callback;
    void *user_data;
    srv_email_nwk_proc_funcptr_type proc_callback;
    void *proc_user_data;
    EMAIL_SRV_HANDLE srv_handle;
    EMAIL_STOR_HANDLE stor_handle;
    EMAIL_NWK_HANDLE nwk_handle;
    srv_email_msg_operation_enum operation;
    srv_email_req_id_action_map_struct req_id_action_map_list[SRV_EMAIL_MESSAGE_REQ_MAX_NUMBER];
} srv_email_msg_info_struct;

typedef struct
{
    srv_email_msg_info_struct *msg_object;
    MMI_BOOL save_new;
    EMAIL_REQ_ID req_id;
    EMAIL_MSG_ID *msg_id;
} srv_email_msg_save_info_struct;

typedef struct
{
    srv_email_msg_info_struct *msg_object;
    EMAIL_REQ_ID req_id;
    WCHAR html_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    WCHAR stor_html_path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    WCHAR *path_buff;
    U32 buff_len;

    MMI_BOOL copy_only;
    S32 fs_job_id;
    U32 convert_handle;
} srv_email_msg_get_html_path_struct;

typedef struct
{
    srv_email_msg_info_struct *msg_object;
    srv_email_msg_access_state_enum org_access_state;
    MMI_BOOL move_to_sent;
    EMAIL_REQ_ID req_id;
} srv_email_msg_nwk_notify_struct;

typedef struct
{
    srv_email_msg_info_struct *msg_object;
    void *user_data;
    EMAIL_REQ_ID req_id;
} srv_email_msg_copy_notify_struct;

typedef struct
{
    srv_email_msg_info_struct *msg_object;
    MMI_BOOL get_attach_info;
    MMI_BOOL save_attach;
    EMAIL_REQ_ID req_id;
    MMI_BOOL canceled;
    MMI_BOOL complete;
} srv_email_msg_mime_parser_info_struct;

srv_email_result_enum srv_email_msg_parse_file_int(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *file_path,
                                MMI_BOOL get_attach_info,
                                MMI_BOOL save_attach,
                                EMAIL_REQ_ID *req_id,
                                MMI_BOOL complete);


srv_email_result_enum srv_email_msg_get_cont_for_comp(
                        EMAIL_MSG_HANDLE msg_handle,
                        srv_email_stor_msg_cont_type type,
                        srv_email_stor_cont_header_struct *cont_header,
                        WCHAR *path,
                        U32 *buff_size);


void srv_email_msg_get_file_path(
                    WCHAR *buff,
                    U16 len,
                    srv_email_msg_info_struct *msg_object,
                    srv_email_msg_save_part_enum part);

srv_email_msg_info_struct *srv_email_msg_handle_to_addr(EMAIL_MSG_HANDLE msg_handle);

#endif /* _EMAIL_SRV_MESSAGE_H */

