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
 *  EmailSrvStorage.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef EMAILSRVSTORAGE_H
#define EMAILSRVSTORAGE_H

#include "MMIDataType.h"
#include "emailsrvgprot.h"
#include "customer_ps_inc.h"
#include "kal_general_types.h"
#include "EmailSrvProt.h"

typedef U32 EMAIL_UID;
typedef U8 EMAIL_MIME_TYPE;
typedef U8 EMAIL_MIME_SUB_TYPE;
typedef void *EMAIL_STOR_HANDLE;

#define EMAIL_FLDR_NAME_LEN             (SRV_EMAIL_MAX_FOLDER_NAME_LEN)

#define EMAIL_STOR_ENCOD_FILE_NAME_LEN  (EMAIL_ATTCH_FILE_NAME_LEN * 4 + 20)    /* =?UTF-8?B?%s?= */

#define EMAIL_STOR_CONT_TYPE_STR_LEN    (50)
#define EMAIL_STOR_CONT_CHARSET_STR_LEN (50)

#define EMAIL_STOR_INVALID_HANDLE       (NULL)

#define EMAIL_STOR_INVALID_FS_HANDLE    (-1)

#define EMAIL_STOR_ACCT_NUM_MAX         (MMI_EMAIL_MAX_ACCTS)

#define EMAIL_STOR_PART_NUM_LEN         (16)

#define EMAIL_STOR_ENCODING_LEN         (30)

#define EMAIL_STOR_FS_HANDLE_INVALID(h) ((h) < FS_NO_ERROR)

typedef enum
{
    SRV_EMAIL_STOR_STATE_AVAILABLE = 1,     /* initialization completed, every thing's OK */
    SRV_EMAIL_STOR_STATE_NOT_START = 0,     /* before initialize */
    SRV_EMAIL_STOR_STATE_INITING = -1,      /* start initializing */
    SRV_EMAIL_STOR_STATE_FS_ERROR = -2,     /* FS error, interrupt initialization */
    SRV_EMAIL_STOR_STATE_NO_MEMORY = -3,    /* no memory, interrupt initialization */
    SRV_EMAIL_STOR_STATE_TOTAL
} srv_email_stor_state_enum;

/* buffer type */
typedef enum
{
    SRV_EMAIL_STOR_BUFF_TYPE_PATH = 0,  /* to get content file path */
    SRV_EMAIL_STOR_BUFF_TYPE_BUFF,      /* to get content */
    SRV_EMAIL_STOR_BUFF_TYPE_NONE,      /* to get content-header, NO content body */
    SRV_EMAIL_STOR_BUFF_TYPE_TOTAL
} srv_email_stor_buff_type_enum;

/* flag to be set */
typedef enum
{
    SRV_EMAIL_STOR_SET_FLAG_SEEN = 0,
    SRV_EMAIL_STOR_SET_FLAG_UNSEEN,
    SRV_EMAIL_STOR_SET_FLAG_ANSWERED,
    SRV_EMAIL_STOR_SET_FLAG_UNANSWERED,
    SRV_EMAIL_STOR_SET_FLAG_FLAGGED,
    SRV_EMAIL_STOR_SET_FLAG_UNFLAGGED,
    SRV_EMAIL_STOR_SET_FLAG_TOTAL
} srv_email_stor_set_flag_type_enum;

/* content type */
typedef enum
{
    SRV_EMAIL_STOR_MSG_CONT_TEXT = 0,   /* text content */
    SRV_EMAIL_STOR_MSG_CONT_HTML,       /* HTML content */
    SRV_EMAIL_STOR_MSG_CONT_TYPE_TOTAL
} srv_email_stor_msg_cont_type;

/* MSG type */
typedef enum
{
    SRV_EMAIL_STOR_MSG_TYPE_RECV = 0,   /* received MSG */
    SRV_EMIAL_STOR_MSG_TYPE_SENT,       /* sent MSG */
    SRV_EMIAL_STOR_MSG_TYPE_TOTAL
} srv_email_stor_msg_type_enum;

/* attach query type */
typedef enum
{
    SRV_EMAIL_STOR_ATTCH_QUERY_PATH = 0,    /* to get attach path */
    SRV_EMAIL_STOR_ATTCH_QUERY_HEADER,      /* to get attach header */
    SRV_EMAIL_STOR_ATTCH_QUERY_TOTAL
} srv_email_stor_attch_query_type_enum;

/* content header */
typedef struct
{
    MMI_BOOL this_part_exist;                               /* filled by create/update MSG */
    MMI_BOOL download_flag;                                 /* whether exist in FS */
    U32 local_size;
    U32 server_size;
    CHAR content_type[EMAIL_STOR_CONT_TYPE_STR_LEN + 1];    /* MIME */
    CHAR charset[EMAIL_STOR_CONT_CHARSET_STR_LEN + 1];      /* CHARSET */
    CHAR part_num[EMAIL_STOR_PART_NUM_LEN + 1];             /* part number */
    CHAR encoding[EMAIL_STOR_ENCODING_LEN + 1];             /* encoding type */
} srv_email_stor_cont_header_struct;

/* address */
typedef struct
{
    CHAR disp_name[EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1];
    CHAR email_addr[EMAIL_MAX_ENCODED_ADDR_LEN + 1];
} srv_email_stor_addr_struct;

/* used for getting folder info */
typedef struct
{
    U32 total_count;
    U32 unread_count;
    U32 uid_validity;
    CHAR fldr_name[EMAIL_FLDR_NAME_LEN + 1];
    CHAR fldr_name_separator;
    srv_email_fldr_type_enum fldr_type;
} srv_email_stor_fldr_struct;

/* used for creating folder */
typedef struct
{
    U32 uid_validity;
    CHAR fldr_name[EMAIL_FLDR_NAME_LEN + 1];
    CHAR fldr_name_separator;
    srv_email_fldr_type_enum fldr_type;
} srv_email_stor_fldr_create_info_struct;

typedef struct
{
    EMAIL_ATTCH_ID attch_id;
    U32 local_size;
    U32 server_size;
    CHAR file_name[EMAIL_STOR_ENCOD_FILE_NAME_LEN + 1];
    CHAR content_type[EMAIL_STOR_CONT_TYPE_STR_LEN + 1];    /* MIME type */
    CHAR charset[EMAIL_STOR_CONT_CHARSET_STR_LEN + 1];
    MMI_BOOL download_flag;                                 /* local */

    MMI_BOOL drm;
    CHAR drm_content_type[EMAIL_STOR_CONT_TYPE_STR_LEN + 1];    /* DO NOT change the position of DRM!! */

    CHAR cid[SRV_EMAIL_CID_MAX_LEN + 1];
    CHAR part_num[EMAIL_STOR_PART_NUM_LEN + 1];
    CHAR encoding[EMAIL_STOR_ENCODING_LEN + 1];
} srv_email_stor_attch_struct;

/* used to get msg header */
typedef struct
{
    EMAIL_MSG_ID msg_id;
    U32 uid_validity;
    EMAIL_UID uid;
    U8 uidl[SRV_EMAIL_MD5_DIGEST_LEN];
    U8 acct_digest[SRV_EMAIL_MD5_DIGEST_LEN];
    EMAIL_MSG_FLAG flag;
    EMAIL_MSG_PRIO priority;
    EMAIL_MSG_STATE state;
    U32 created_date;
    U32 received_date;
    U32 local_size;
    U32 server_size;
    U16 attch_num;
    U16 remain_attach_num;
    U16 addr_to_num;
    U16 remain_addr_to_num;
    U16 addr_cc_num;
    U16 remain_addr_cc_num;
    U16 addr_bcc_num;
    U16 remain_addr_bcc_num;
    MMI_BOOL addr_reply_to;
    MMI_BOOL addr_from;
    MMI_BOOL has_text;
    MMI_BOOL has_html;
    CHAR disp_name[EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1];
    CHAR email_addr[EMAIL_MAX_ENCODED_ADDR_LEN + 1];
} srv_email_stor_msg_get_header_struct;

/* used to create a msg */
typedef struct
{
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_MSG_ID msg_id;
    U32 uid_validity;
    EMAIL_UID uid;
    U8 uidl[SRV_EMAIL_MD5_DIGEST_LEN];
    U8 acct_digest[SRV_EMAIL_MD5_DIGEST_LEN];
    EMAIL_MSG_FLAG flag;
    EMAIL_MSG_PRIO priority;
    EMAIL_MSG_STATE state;
    U32 created_date;
    U32 received_date;
    U32 local_size;
    U32 server_size;
    U16 attch_num;
    U16 remain_attach_num;
    U16 addr_to_num;
    U16 remain_addr_to_num;
    U16 addr_cc_num;
    U16 remain_addr_cc_num;
    U16 addr_bcc_num;
    U16 remain_addr_bcc_num;
    U32 subj_len;
    U32 text_len;
    U32 html_len;
    srv_email_stor_msg_type_enum msg_type;
    WCHAR list_subj[EMAIL_MAX_LIST_SUBJ_LEN + 1];
} srv_email_stor_msg_create_header_struct;

/* used to list msg */
typedef struct
{
    EMAIL_MSG_ID msg_id;
    CHAR disp_name[EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1];
    CHAR email_addr[EMAIL_MAX_ENCODED_ADDR_LEN + 1];
    CHAR *buff_p;
    U32 server_size;
    U32 local_size;
    U32 has_attach;
    U32 time;
    EMAIL_MSG_FLAG flag;
    EMAIL_MSG_PRIO priority;
    EMAIL_MSG_STATE state;
    WCHAR list_subj[EMAIL_MAX_LIST_SUBJ_LEN + 1];
} srv_email_stor_msg_list_header_struct;

/* used to sync msg */
typedef struct
{
    EMAIL_MSG_ID msg_id;
    EMAIL_MSG_FLAG flag_latest;
    EMAIL_MSG_FLAG flag_orig;
    U32 uid_validity;
    EMAIL_UID uid;
    U8 uidl[SRV_EMAIL_MD5_DIGEST_LEN];
    U8 acct_digest[SRV_EMAIL_MD5_DIGEST_LEN];
    EMAIL_MSG_STATE state;
    U32 created_date;
    U32 received_date;
} srv_email_stor_fldr_get_msg_id_struct;

typedef void (*srv_email_stor_res_funcptr_type) (srv_email_result_enum res, void *user_data);

/*
 * switch (MSG_TYPE)
 * * case SUBJ    :   fill buff with subject, and ignore cont_header. 
 * * case TEXT    :   fill buff with text path, if cont_header don't needed, fill it with NULL
 * * case HTML    :   fill buff with HTML path, if cont_header don't needed, fill it with NULL
 */
typedef void (*srv_email_stor_msg_query_text_funcptr_type) (srv_eamil_msg_text_type_enum type,
                                                            srv_email_stor_cont_header_struct *cont_header,
                                                            void *buff, U32 buff_size, S32 *keep_src, void *user_data);

typedef void (*srv_email_stor_msg_query_addr_funcptr_type) (srv_email_addr_type_enum type, U16 index,
                                                            srv_email_stor_addr_struct *data, void *user_data);

/* if query_type is PAHT, this function is used to query attach path, otherwise,
   it's used to query attach header(srv_email_stor_attch_struct). */
typedef void (*srv_email_stor_msg_query_attch_funcptr_type) (U16 index, void *buff, U32 buff_size, S32 *keep_src,
                                                             srv_email_stor_attch_query_type_enum type,
                                                             void *user_data);

typedef void (*srv_email_stor_msg_create_funcptr_type) (srv_email_result_enum res, EMAIL_MSG_ID msg_id,
                                                        void *user_data);

typedef srv_email_stor_msg_create_funcptr_type srv_email_stor_msg_update_funcptr_type;

typedef void (*srv_email_stor_fldr_del_funcptr_type) (srv_email_result_enum res, void *user_data);

typedef void (*srv_email_stor_msg_copy_funcptr_type) (srv_email_result_enum res, EMAIL_MSG_ID to_msg_id,
                                                      void *user_data);

typedef srv_email_stor_res_funcptr_type srv_email_stor_fldr_clear_funcptr_type;

typedef srv_email_stor_res_funcptr_type srv_email_stor_sys_dir_chg_funcptr_type;

typedef srv_email_stor_res_funcptr_type srv_email_stor_acct_write_funcptr_type;

/****************************************************************************/
/******************************** ACCOUNT ***********************************/
/****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_id_get
 * DESCRIPTION
 *  Used to query valid account id, the array filled with valid acct_id in order of created time, or ACCT_INVALID_ID
 * PARAMETERS
 *  acct_info       : [OUT]         Acct_id array, buffer size = sizeof(EMAIL_ACCT_ID) * EMAIL_STOR_ACCT_NUM_MAX
 * RETURNS
 *  Total valid account id number.
 ****************************************************************************/
U32 srv_email_stor_acct_id_get(EMAIL_ACCT_ID *acct_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_default_id_get
 * DESCRIPTION
 *  Used to query the default account id,
 * PARAMETERS
 *  void
 * RETURNS
 *  Default account id. (return ACCT_INVALID_ID if no default acct id)
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_default_id_get(EMAIL_ACCT_ID *default_acct_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_default_id_set
 * DESCRIPTION
 *  Used to query valid account id, the array filled with valid acct_id in order of created time, or ACCT_INVALID_ID
 * PARAMETERS
 *  acct_id         : [IN]         New default acct id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_default_id_set(EMAIL_ACCT_ID acct_id);
srv_email_result_enum srv_email_stor_acct_default_id_del(void);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_setting_read
 * DESCRIPTION
 *
 * PARAMETERS
 *  acct_info       : [IN/OUT]     Account info struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_info_read(srv_email_acct_info_struct *acct_info);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_setting_write
 * DESCRIPTION
 *
 * PARAMETERS
 *  acct_info       : [IN]     Account info struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_info_write(const srv_email_acct_info_struct *acct_info);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_info_write_async
 * DESCRIPTION
 *
 * PARAMETERS
 *  acct_info       : [IN]     Account info struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_info_write_async(const srv_email_acct_info_struct *acct_info,
                         srv_email_stor_acct_write_funcptr_type callback, void* user_data);

void srv_email_stor_acct_info_write_async_abort(void);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_create
 * DESCRIPTION
 *  Generate an Account Id, Create the account's FS folder
 * PARAMETERS
 *  acct_id         : [OUT]     The acct_id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_create_request(EMAIL_ACCT_ID *acct_id);

srv_email_result_enum srv_email_stor_acct_create_cancel(EMAIL_ACCT_ID acct_id);

srv_email_result_enum srv_email_stor_acct_pre_install_open(EMAIL_STOR_HANDLE *handle);

srv_email_result_enum srv_email_stor_acct_pre_install_create(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_acct_info_struct *acct_info);

srv_email_result_enum srv_email_stor_acct_pre_install_close(EMAIL_STOR_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_del
 * DESCRIPTION
 *  Delete an account.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  req_id          : [OUT]     Used to return the request id
 *  callback        : [IN]      The pointer point to the callback function
 *  user_data       : [IN]      User data
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_del(EMAIL_ACCT_ID acct_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_get_fldr_num
 * DESCRIPTION
 *  To query folder number under this account.
 * PARAMETERS
 *  acct_id         : [IN]      account id
 *  type            : [IN]      Folder type, only SRV_EMAIL_FLDR_TYPE_BASIC & SRV_EMAIL_FLDR_TYPE_REMOTE supported
 * RETURNS
 *  The result code.
 ****************************************************************************/
S32 srv_email_stor_acct_get_fldr_num(EMAIL_ACCT_ID acct_id, srv_email_fldr_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_get_fldr_id_open
 * DESCRIPTION
 *  Query Folders' number under the Account.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  type            : [IN]      Folder type, only SRV_EMAIL_FLDR_TYPE_REMOTE & SRV_EMAIL_FLDR_TYPE_ALL supported
 *  fldr_ids        : [OUT]     Fldr_id(s)
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_get_fldr_id_open(
                        EMAIL_ACCT_ID acct_id,
                        srv_email_fldr_type_enum type,
                        EMAIL_STOR_HANDLE *handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_get_fldr_id_next
 * DESCRIPTION
 *  Get fldr_id.
 * PARAMETERS
 *  handle          : [IN]      Handle
 *  fldr_id         : [IN]      Folder id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_get_fldr_id_next(EMAIL_STOR_HANDLE handle, EMAIL_FLDR_ID *fldr_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_get_fldr_id_close
 * DESCRIPTION
 *  Release resources.
 * PARAMETERS
 *  handle          : [IN]      Handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_acct_get_fldr_id_close(EMAIL_STOR_HANDLE handle);

/****************************************************************************/
/******************************** FOLDER ************************************/
/****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_get_id_by_type
 * DESCRIPTION
 *  Get fldr-id
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 * RETURNS
 *  EMAIL_FLDR_ID.
 ****************************************************************************/
EMAIL_FLDR_ID srv_email_stor_fldr_get_id_by_type(EMAIL_ACCT_ID acct_id, srv_email_fldr_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_get_by_id
 * DESCRIPTION
 *  Get a Folder's Info.
 *  1. If the Folder ID is valid, fill the Folder Info, otherwise, return fail.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  fldr_id         : [IN]      The folder id
 *  fldr_info       : [OUT]     The pointer point to folder info struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_get_by_id(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_email_stor_fldr_struct *fldr_info);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_get_by_type
 * DESCRIPTION
 *
 *  NOT SUPPORTED NOW, ONLY FOR UM!
 * 
 *  Get a Folder's Info by TYPE.
 *  Supported folder type:
 *
 *  EMAIL_STOR_FLDR_TYPE_INBOX,
 *  EMAIL_STOR_FLDR_TYPE_OUTBOX,
 *  EMAIL_STOR_FLDR_TYPE_SENT,
 *  EMAIL_STOR_FLDR_TYPE_DRAFT,
 *  EMAIL_STOR_FLDR_TYPE_TRASH,
 *
 * PARAMETERS
 *  fldr_info       : [IN/OUT]  The pointer point to folder info struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_get_by_type(
                        srv_email_fldr_type_enum fldr_type,
                        srv_email_stor_fldr_struct *fldr_info);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_open
 * DESCRIPTION
 *
 * PARAMETERS
 *  acct_id         : [IN]      Account id
 *  fldr_id         : [IN]      Folder id
 *  handle          : [OUT]     Handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_open(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_HANDLE *handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_open_ext
 * DESCRIPTION
 *
 * PARAMETERS
 *  acct_id         : [IN]      Account id
 *  fldr_id         : [IN]      Folder id
 *  handle          : [OUT]     Handle
 *  last_msg_id     : [IN]      The MSG ID user get
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_open_ext(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_HANDLE *handle,
                        EMAIL_MSG_ID last_msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_get_next
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle          : [IN]      Handle
 *  msg_info        : [OUT]     MSG info
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_get_next(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_stor_fldr_get_msg_id_struct *msg_info);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_set_flag
 * DESCRIPTION
 *  Set a msg's flag, it must belong to the current floder.
 * PARAMETERS
 *  handle          : [IN]      Handle
 *  msg_id          : [IN]      MSG id
 *  new_flag        : [IN]      new flag
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_set_flag(
                        EMAIL_STOR_HANDLE handle,
                        EMAIL_MSG_ID msg_id,
                        EMAIL_MSG_FLAG new_flag);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_del
 * DESCRIPTION
 *  Delete a msg, it must belong to the current floder.
 * PARAMETERS
 *  handle          : [IN]      Handle
 *  msg_id          : [IN]      MSG id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_del(EMAIL_STOR_HANDLE handle, EMAIL_MSG_ID msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_close
 * DESCRIPTION
 *  Release resources.
 * PARAMETERS
 *  handle          : [IN]      Handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_close(EMAIL_STOR_HANDLE *handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_del
 * DESCRIPTION
 *  Delete all the MSG under this folder, include the Folder.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  fldr_id         : [IN]      The folder id array pointer
 *  fldr_id_num     : [IN]      The folder id array's size
 *  req_id          : [OUT]     Used to return the request id
 *  callback        : [IN]      The pointer point to the callback function
 *  user_data       : [IN]      User data
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_del(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID *fldr_id_array,
                        U32 fldr_id_num);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_create
 * DESCRIPTION
 *  Create a new folder.
 *  1. Generate a fldr-id, create the Index File and Backup File.
 * PARAMETERS
 *  acct_id         : [IN]      The async request id
 *  type            : [IN]      Folder type
 *  fldr_id         : [OUT]     Folder id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_create(
                        EMAIL_ACCT_ID acct_id,
                        const srv_email_stor_fldr_create_info_struct *fldr_info,
                        EMAIL_FLDR_ID *fldr_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_list_open
 * DESCRIPTION
 *  Start to get the MSG list.
 * PARAMETERS
 *  fldr_type   : [IN]      For UM, SRV_EMAIL_FLDR_TYPE_BASICS_BGN to SRV_EMAIL_FLDR_TYPE_BASICS_END are supported,
                            acct_id & fldr_id will be ignored. Otherwise, please make it SRV_EMAIL_FLDR_TYPE_INVALID.
 *  acct_id     : [IN]
 *  fldr_id     : [IN]      Folder id
 *  text_type   : [IN]      Text type
 *  date_type   : [IN]      Date type
 *  base_index  : [IN]      Start index
 *  handle      : [OUT]     The handle for NEXT & CLOSE operation.
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_list_msg_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_eamil_msg_text_type_enum text_type,
                        srv_email_msg_date_type_enum date_type,
                        S32 base_index,
                        EMAIL_STOR_HANDLE *handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_list_get_next
 * DESCRIPTION
 *  Get next MSG header.
 * PARAMETERS
 *  handle          : [IN]      The handle
 *  header          : [OUT]     The read data
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_list_msg_next(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_stor_msg_list_header_struct *header);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_list_close
 * DESCRIPTION
 *  Close the get action.
 * PARAMETERS
 *  handle          : [IN]      The MSG list read handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_list_msg_close(EMAIL_STOR_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_del_muti
 * DESCRIPTION
 *  Delete muti-MSG.
 * PARAMETERS
 *  fldr_type   : [IN]      For UM, SRV_EMAIL_FLDR_TYPE_BASICS_BGN to SRV_EMAIL_FLDR_TYPE_BASICS_END are supported,
                            acct_id & fldr_id will be ignored. Otherwise, please make it SRV_EMAIL_FLDR_TYPE_INVALID.
 *  acct_id     : [IN]      The account id
 *  fldr_id     : [IN]      The folder id
 *  type        : [IN]      The delete MSG type, body or all
 *  del_header  : [IN]      If MMI_TRUE, all things will be deleted (HEADER & BODY), and del_server will not be cared!
                            If MMI_FALSE, only BODY will be deleted, and del_server will be marked to MSG.
 *  del_server  : [IN]      If this flag is set, Storage will mark this MSG need deleted from server next SYNC.
 *  handle      : [OUT]     Handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_del_msg_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        MMI_BOOL del_header,
                        MMI_BOOL del_server,
                        EMAIL_STOR_HANDLE *handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_del_msg_next
 * DESCRIPTION
 *  Delete a msg
 * PARAMETERS
 *  handle      : [IN]      The handle
 *  msg_id      : [IN]      MSG LID
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_del_msg_next(EMAIL_STOR_HANDLE handle, EMAIL_MSG_ID msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_del_msg_close
 * DESCRIPTION
 *  Close the handle to terminate setting flags.
 * PARAMETERS
 *  handle      : [IN]      The handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_del_msg_close(EMAIL_STOR_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_set_msg_flag_open
 * DESCRIPTION
 *  Get a handle to set MSG(s)' flags.
 * PARAMETERS
 *  fldr_type   : [IN]      For UM, SRV_EMAIL_FLDR_TYPE_BASICS_BGN to SRV_EMAIL_FLDR_TYPE_BASICS_END are supported,
                            acct_id & fldr_id will be ignored. Otherwise, please make it SRV_EMAIL_FLDR_TYPE_INVALID.
 *  acct_id     : [IN]      The account id
 *  fldr_id     : [IN]      The folder id
 *  type        : [IN]      Set flag type
 *  handle      : [OUT]     The handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_set_msg_flag_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        U8 mask,
                        EMAIL_MSG_FLAG flag,
                        EMAIL_STOR_HANDLE *handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_set_msg_flag_next
 * DESCRIPTION
 *  Set MSG(s)' flags.
 * PARAMETERS
 *  acct_id     : [IN]      The account id
 *  fldr_id     : [IN]      The folder id
 *  msg_id     : [IN]      The pointer point to MSG lid linked list
 *  clear_all   : [IN]      If it's true, clear all flags before setting new flag
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_set_msg_flag_next(EMAIL_STOR_HANDLE handle, EMAIL_MSG_ID msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_set_msg_flag_close
 * DESCRIPTION
 *  Close the handle to terminate setting flags.
 * PARAMETERS
 *  handle      : [IN]      The handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_set_msg_flag_close(EMAIL_STOR_HANDLE handle);

/****************************************************************************/
/******************************* MESSAGE ************************************/
/****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_id_valid
 * DESCRIPTION
 *  To Query whether the MSG is valid in storage.
 * PARAMETERS
 *  msg_id      : [IN]      The handle
 * RETURNS
 *  MMI_TURE or MMI_FALSE
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_id_valid(EMAIL_MSG_ID msg_id, MMI_BOOL *is_valid);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_id_valid_ext
 * DESCRIPTION
 *  To Query whether the MSG is valid in storage.
 * PARAMETERS
 *  msg_id      : [IN]      The handle
 *  chk_attch   : [IN]      Whether check attachments
 * RETURNS
 *  MMI_TURE or MMI_FALSE
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_id_valid_ext(EMAIL_MSG_ID msg_id, MMI_BOOL chk_attch, MMI_BOOL *is_valid);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_create_abort
 * DESCRIPTION
 *  Abort creating a new MSG.
 * PARAMETERS
 *  msg_create_handle   : [IN]      
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_create_abort(EMAIL_STOR_HANDLE msg_create_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_create
 * DESCRIPTION
 *  Create a new MSG, account id and folder id MUST be provided.
 * PARAMETERS
 *  header              : [IN]      The pointer point to MSG data
 *  query_text_callback : [IN]      Used to query subj/cont/html
 *  query_addr_callback : [IN]      Used to query addr
 *  query_attch_callback: [IN]      Used to query attch
 *  callback            : [IN]
 *  user_data           : [IN]
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_create(
                        srv_email_stor_msg_create_header_struct *header,
                        srv_email_stor_msg_query_text_funcptr_type query_text_callback,
                        srv_email_stor_msg_query_addr_funcptr_type query_addr_callback,
                        srv_email_stor_msg_query_attch_funcptr_type query_attch_callback,
                        srv_email_stor_msg_create_funcptr_type callback,
                        void *user_data,
                        EMAIL_STOR_HANDLE *msg_create_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_update_abort
 * DESCRIPTION
 *  Abort creating a new MSG.
 * PARAMETERS
 *  msg_update_handle   : [IN]      
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_update_abort(EMAIL_STOR_HANDLE msg_update_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_update
 * DESCRIPTION
 *  Update a MSG, account id and folder id MUST be provided.
 * PARAMETERS
 *  header              : [IN]      The pointer point to MSG data
 *  query_text_callback : [IN]      Used to query subj/cont/html
 *  query_addr_callback : [IN]      Used to query addr
 *  query_attch_callback: [IN]      Used to query attch
 *  callback            : [IN]
 *  user_data           : [IN]
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_update(
                        srv_email_stor_msg_create_header_struct *header,
                        srv_email_stor_msg_query_text_funcptr_type query_text_callback,
                        srv_email_stor_msg_query_addr_funcptr_type query_addr_callback,
                        srv_email_stor_msg_query_attch_funcptr_type query_attch_callback,
                        srv_email_stor_msg_update_funcptr_type callback,
                        void *user_data,
                        EMAIL_STOR_HANDLE msg_update_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_move
 * DESCRIPTION
 *  Move a msg to a new mailbox .
 * PARAMETERS
 *  from_msg_id     : [IN]      The from MSG lid
 *  to_acct_id      : [IN]      The to account id
 *  to_fldr_id      : [IN]      The to folder id
 *  to_msg_id       : [OUT]     The to MSG id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_move(
                        EMAIL_MSG_ID from_msg_id,
                        EMAIL_ACCT_ID to_acct_id,
                        EMAIL_FLDR_ID to_fldr_id,
                        EMAIL_MSG_ID *to_msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_copy
 * DESCRIPTION
 *  Copy a msg to a new mailbox.
 * PARAMETERS
 *  from_msg_id     : [IN]      The from MSG lid
 *  to_acct_id      : [IN]      The to account id
 *  to_fldr_id      : [IN]      The to folder id
 *  to_msg_id       : [OUT]     The to MSG id
 *  req_id          : [OUT]     Request id
 *  callback        : [IN]      Callback
 *  user_data       : [IN]      User data
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_copy(
                        EMAIL_MSG_ID from_msg_id,
                        EMAIL_ACCT_ID to_acct_id,
                        EMAIL_FLDR_ID to_fldr_id,
                        EMAIL_MSG_ID *to_msg_id,
                        EMAIL_REQ_ID *req_id,
                        srv_email_stor_msg_copy_funcptr_type callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_copy_abort
 * DESCRIPTION
 *  Abort the copy action.
 * PARAMETERS
 *  req_id         : [IN]       The async request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_copy_abort(EMAIL_REQ_ID req_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_part_info
 * DESCRIPTION
 *  Get the MSG part info, the relationship of PART and Structure of data_p as below:
 * PARAMETERS
 *  acct_id     : [IN]      The account id
 *  fldr_id     : [IN]      The folder id
 *  msg_id      : [IN]      The pointer point to MSG lid linked list
 *  part        : [IN]      The MSG part
 *  data_p      : [OUT]     MSG data
 *  size        : [OUT]     Out size
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_header(EMAIL_MSG_ID msg_id, srv_email_stor_msg_get_header_struct *header);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_cont_exist
 * DESCRIPTION
 *  To query whether TEXT/HTML exist
 * PARAMETERS
 *  msg_id      : [OUT]     MSG id
 *  text_exist  : [OUT]     Whether TEXT exist
 *  html_exist  : [OUT]     Whether HTML exist
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_cont_exist(EMAIL_MSG_ID msg_id, S8 *text_exist_mask, S8 *html_exist_mask);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_cont_size
 * DESCRIPTION
 *  To query whether TEXT/HTML exist
 * PARAMETERS
 *  msg_id      : [OUT]     MSG id
 *  text_size  : [OUT]     Whether TEXT exist
 *  html_size  : [OUT]     Whether HTML exist
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_cont_size(EMAIL_MSG_ID msg_id, U32 *text_size, U32 *html_size);


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_subj_len
 * DESCRIPTION
 *  To query subject length
 * PARAMETERS
 *  msg_id      : [IN]      MSG id
 * RETURNS
 *  Subject length, negative means subject not exist.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_subj_len(EMAIL_MSG_ID msg_id, U32 *subj_len);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_subj
 * DESCRIPTION
 *  To query whether TEXT/HTML exist
 * PARAMETERS
 *  msg_id          : [IN]      Whether TEXT exist
 *  subj            : [OUT]     Subject(Encoded)
 *  buffer_size     : [IN/OUT]  Buffer size
 * RETURNS
 *  voud
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_subj(EMAIL_MSG_ID msg_id, CHAR *subj, U32 *buff_size);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_cont_len
 * DESCRIPTION
 *  To query Cont length
 * PARAMETERS
 *  msg_id      : [IN]      MSG id
 *  type        : [IN]      Content type, text/html
 * RETURNS
 *  Content length, negative means content not exist.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_cont_len(EMAIL_MSG_ID msg_id, srv_email_stor_msg_cont_type type, U32 *cont_len);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_cont
 * DESCRIPTION
 *  To query whether TEXT/HTML exist
 * PARAMETERS
 *  msg_id          : [IN]      Whether TEXT exist
 *  type            : [OUT]     Subject
 *  cont_header     : [OUT]     Content header, can be NULL
 *  buff            : [OUT]     Buffer
 *  buff_type       : [IN]      Buffer type
 *  buff_size       : [IN]      Buffer size
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_cont(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_cont_type type,
                        srv_email_stor_cont_header_struct *cont_header,
                        WCHAR *path,
                        U32 *buff_size);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_addr_open
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_id          : [IN]      MSG id
 *  base_index      : [IN]      Base index
 *  addr_type       : [IN]      Address type
 *  handle          : [OUT]     Handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_addr_open(
                        EMAIL_MSG_ID msg_id,
                        U32 base_index,
                        /* start from this INDEX to get */ srv_email_addr_type_enum addr_type,
                        EMAIL_STOR_HANDLE *handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_addr_next
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle          : [IN]      Handle
 *  disp_name_len   : [IN]      Display name length, 0 means you do NOT care "display name" and disp_name can be NULL
 *  addr_len        : [IN]      Email address length
 *  disp_name       : [IN]      Display name buffer
 *  addr            : [IN]      Email address buffer
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_addr_next(
                        EMAIL_STOR_HANDLE handle,
                        U32 disp_name_buff_len,
                        U32 addr_buff_len,
                        CHAR *disp_name,
                        CHAR *addr);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_addr_close
 * DESCRIPTION
 *  To release resources.
 * PARAMETERS
 *  handle      : [IN]      The handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_addr_close(EMAIL_STOR_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_load_cont
 * DESCRIPTION
 *  Add content to the MSG.
 * PARAMETERS
 *  msg_id      : [IN]      The pointer point to MSG lid linked list
 *  attch_path  : [IN]      The attach file path
 *  keep_src    : [IN]      If source file need kept, pass MMI_TRUE
 *  addr        : [IN]      Email address buffer
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_load_cont(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_cont_type type,
                        const WCHAR *cont_path,
                        MMI_BOOL keep_src);

/****************************************************************************/
/******************************* ATTACH *************************************/
/****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_open
 * DESCRIPTION
 *  To get a handle.
 * PARAMETERS
 *  msg_id      : [IN]      The attch id
 *  base_index   : [IN]      The attch base index
 *  handle       : [OUT]     Buffer size
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_open(
                        EMAIL_MSG_ID msg_id,
                        U32 base_index,
                        EMAIL_STOR_HANDLE *handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_next
 * DESCRIPTION
 *  To get next valid attch.
 * PARAMETERS
 *  handle      : [IN]      The handle
 *  attch       : [OUT]     The attach info
 * RETURNS
 *  The result code. (If return value is not SUCC, please call CLOSE to release resources.)
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_next(EMAIL_STOR_HANDLE handle, srv_email_stor_attch_struct *attch);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_close
 * DESCRIPTION
 *  To release resources.
 * PARAMETERS
 *  handle      : [IN]      The handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_close(EMAIL_STOR_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_info
 * DESCRIPTION
 *  To get attch header info by msg_id and attch_id.
 * PARAMETERS
 *  msg_id      : [IN]      The handle
 *  attch_id    : [IN]      The attach info
 *  attch       : [OUT]     Attach header info
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_info(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_ATTCH_ID attch_id,
                        srv_email_stor_attch_struct *attch);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_set_flags_muti
 * DESCRIPTION
 *  Check whether attch_id is valid. Get the full file path of an attachment.
 * PARAMETERS
 *  attch_id     : [IN]      The attch id
 *  attch_path   : [OUT]     The attach file path
 *  buff_size    : [IN]      Buffer size
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_path(EMAIL_ATTCH_ID attch_id, WCHAR *attch_path, U32 buff_size);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_load_attch
 * DESCRIPTION
 *  Add an attachment to the MSG.
 * PARAMETERS
 *  msg_id     : [IN]      The pointer point to MSG lid linked list
 *  attch_id    : [IN]      The attach id
 *  attch_path  : [IN]      The attach file path
 *  keep_src    : [IN]      If source file need kept, pass MMI_TRUE
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_msg_load_attch(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_ATTCH_ID attch_id,
                        const WCHAR *attch_path,
                        MMI_BOOL keep_src,
                        MMI_BOOL drm,
                        const CHAR *drm_content_type,
                        const CHAR *new_filename,
                        const CHAR *new_charset);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_sys_dir_chg
 * DESCRIPTION
 *  Reset the Email system directory.
 * PARAMETERS
 *  new_dir     : [IN]      The new system directory
 *  del_orig    : [IN]      Whether delete original directory
 *  copy_orig   : [IN]      Whether copy original directory files to new directory
 *  callback    : [IN]      The call back function
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_sys_dir_chg(
                        const WCHAR *new_dir,
                        MMI_BOOL del_orig,
                        MMI_BOOL copy_orig,
                        srv_email_stor_sys_dir_chg_funcptr_type callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_sys_init
 * DESCRIPTION
 *  Initialize storage, check all the Index File and Backup File, call this function when booting.(Async)
 * PARAMETERS
 *  void
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_init(srv_email_stor_res_funcptr_type callback, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_init_state
 * DESCRIPTION
 *  Query whether storage initialization complete.
 * PARAMETERS
 *  void
 * RETURNS
 *  storage state
 ****************************************************************************/
srv_email_stor_state_enum srv_email_stor_init_state(void);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_get_detail_errno
 * DESCRIPTION
 *  Get detail error number, only FS error supported now.
 * PARAMETERS
 *  void
 * RETURNS
 *  The detail error code.
 ****************************************************************************/
S32 srv_email_stor_get_detail_errno(srv_email_result_enum res);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_inbox_get_recent_list
 * DESCRIPTION
 *  Get detail error number, only FS error supported now.
 * PARAMETERS
 *  acct_id         :   [IN]
 *  start_index     :   [IN]
 *  count           :   [IN/OUT]
 *  type            :   [IN]
 *  msg_id_array    :   [OUT]
 * RETURNS
 *  The detail error code.
 ****************************************************************************/
srv_email_result_enum srv_email_stor_inbox_get_recent_list(
                        EMAIL_ACCT_ID acct_id,
                        S32 start_index,
                        U32 *count,
                        U8 flag_mask,
                        EMAIL_MSG_FLAG matched_flag,
                        srv_email_inbox_index_msg_struct *msg_array);

srv_email_result_enum srv_email_stor_get_all_msg_id(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        U8 flag_mask, 
                        EMAIL_MSG_FLAG matched_flag,
                        U32 *count,
                        EMAIL_MSG_ID *msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_id_to_acct_id
 * DESCRIPTION
 *  Convert msg id to account id
 * PARAMETERS
 *  msg_id          :   [IN]
 * RETURNS
 *  The detail error code.
 ****************************************************************************/
EMAIL_ACCT_ID srv_email_stor_msg_id_to_acct_id(EMAIL_MSG_ID msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_id_to_fldr_id
 * DESCRIPTION
 *  Convert msg id to folder id
 * PARAMETERS
 *  msg_id          :   [IN]
 * RETURNS
 *  The detail error code.
 ****************************************************************************/
EMAIL_FLDR_ID srv_email_stor_msg_id_to_fldr_id(EMAIL_MSG_ID msg_id);

EMAIL_MSG_ID srv_email_stor_attch_id_to_msg_id(EMAIL_ATTCH_ID attch_id);

void srv_email_stor_acct_cache_notify_set(srv_email_all_msg_unread_notify_funcptr callback, void* userdata);

void srv_email_stor_acct_cache_get(EMAIL_ACCT_ID acct_id, srv_email_acct_info_cache_struct *acct_info_cache);

srv_email_result_enum srv_email_stor_msg_get_flag_state(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_MSG_FLAG *flag,
                        EMAIL_MSG_STATE *state);

srv_email_result_enum srv_email_stor_acct_set_cloud_acct(EMAIL_ACCT_ID acct_id, MMI_BOOL is_cloud_acct);

#endif /* EMAILSRVSTORAGE_H */ 

