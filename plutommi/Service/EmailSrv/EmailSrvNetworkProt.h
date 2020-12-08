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
 *  EmailSrvNetworkProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to define the Email network internal functions.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifndef EMAILNETWORKPORT_H
#define EMAILNETWORKPORT_H

#include "app_base64.h"
#include "app_qp.h"

#include "EmailSrvComposer.h"
#include "email_ps_public.h"
#include "EmailSrvStorage.h"

#include "EmailSrvGprot.h"
#include "customer_ps_inc.h"
#include "MMI_trc_Int.h"
#include "mmi_inet_app_trc.h"
#include "EmailSrvNetwork.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "fs_gprot.h"
#include "EmailSrvProt.h"

#define SRV_EMAIL_MAX_MSG_NUM           SRV_EMAIL_GLOBAL_MAX_MSG_NUM
#define SRV_EMAIL_MAX_FLDR_NUM          MMI_EMAIL_MAX_REMOTE_FOLDER_NUM
#define SRV_EMAIL_MAX_ADDR_NUM          MMI_EMAIL_MAX_ADDR_NUM
#define SRV_EMAIL_MAX_ATTACH_NUM        MMI_EMAIL_MAX_ATTACH_NUMBER
#define SRV_EMAIL_GET_NUM_PER_TIME      (250)

#define SRV_EMAIL_NWK_CLOUD_DECODE_BUFF_SIZE    (1024)

#define SRV_EMAIL_MAX_CB_NUM            (10)

#define SRV_EMAIL_NWK_FILE_PATH         "Network\\"

#define SRV_EMAIL_INBOX_NAME            "INBOX"

#define SRV_EMAIL_NWK_CB_CONNECTED      0x01

#define SRV_EMAIL_NWK_SET_STATE(cntx_p, state) \
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_STATE_NWK_FSM_SET_STATE, cntx_p, state); \
            cntx_p->nwk_state = state

#define SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, state) \
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_SET_STATE, cntx_p, state); \
            cntx_p->nwk_state = state

#define SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, state) \
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_SET_SUB_STATE, cntx_p, state); \
            cntx_p->sub_state = state

/* The network context state enum */
typedef enum
{
    SRV_EMAIL_NWK_STATE_INIT,
    SRV_EMAIL_NWK_STATE_CREATING,
    SRV_EMAIL_NWK_STATE_CREATED,
    SRV_EMAIL_NWK_STATE_ACTIVATING,
    SRV_EMAIL_NWK_STATE_ACTIVATED,
    SRV_EMAIL_NWK_STATE_CONNECTING,
    SRV_EMAIL_NWK_STATE_AUTHORIZING,
    SRV_EMAIL_NWK_STATE_QUERYING,
    SRV_EMAIL_NWK_STATE_READY,
    SRV_EMAIL_NWK_STATE_UPDATING,
    SRV_EMAIL_NWK_STATE_UPDATED,
    SRV_EMAIL_NWK_STATE_SENDING,
    SRV_EMAIL_NWK_STATE_RECEIVING,
    SRV_EMAIL_NWK_STATE_SYNCING,
    SRV_EMAIL_NWK_STATE_LISTING_FOLDER,
    SRV_EMAIL_NWK_STATE_DISCONNECTING,
#if defined(__MMI_SSO__) || defined(__SMS_CLOUD_SUPPORT__)
    SRV_EMAIL_NWK_STATE_CLOUD_QUERYING,
    SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING,
    SRV_EMAIL_NWK_STATE_CLOUD_UPGRADING,
#endif /* defined(__MMI_SSO__) || defined(__SMS_CLOUD_SUPPORT__) */
    SRV_EMAIL_NWK_STATE_TOTAL
} srv_email_nwk_state_enum;

typedef enum
{
    SRV_EMAIL_NWK_SUB_STATE_NONE,

    SRV_EMAIL_NWK_SUB_STATE_SEND_INIT = 100,    /* The send related sub-states */
    SRV_EMAIL_NWK_SUB_STATE_SEND_LIST,
    SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE,
    SRV_EMAIL_NWK_SUB_STATE_SEND_SEND,
    SRV_EMAIL_NWK_SUB_STATE_SEND_APPEND,
    SRV_EMAIL_NWK_SUB_STATE_SEND_DONE,

    SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT = 200,  /* The update related sub-states */
    SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER,
    SRV_EMAIL_NWK_SUB_STATE_UPDATE_CREATE_FOLDER,
    SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_UID,
    SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_SIZE,
    SRV_EMAIL_NWK_SUB_STATE_UPDATE_LIST_FLAG,
    SRV_EMAIL_NWK_SUB_STATE_UPDATE_UPDATE_LOCAL,
    SRV_EMAIL_NWK_SUB_STATE_UPDATE_DONE,

    SRV_EMAIL_NWK_SUB_STATE_RECV_INIT = 300,    /* The receive related sub-states */
    SRV_EMAIL_NWK_SUB_STATE_RECV_UID,
    SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE,
    SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE,
    SRV_EMAIL_NWK_SUB_STATE_RECV_SAVE,
    SRV_EMAIL_NWK_SUB_STATE_RECV_DONE,

    SRV_EMAIL_NWK_SUB_STATE_DISC_INIT = 400,    /* The POP3 delete related sub-states */
    SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_SERVER,
    SRV_EMAIL_NWK_SUB_STATE_DISC_DISCONNECT,
    SRV_EMAIL_NWK_SUB_STATE_DISC_DEL_LOCAL,
    SRV_EMAIL_NWK_SUB_STATE_DISC_DONE,

    SRV_EMAIL_NWK_SUB_STATE_SYNC_INIT = 500,    /* The IMAP4 sync related sub-states */
    SRV_EMAIL_NWK_SUB_STATE_SYNC_FLAGS,
    SRV_EMAIL_NWK_SUB_STATE_SYNC_DELETE,
    SRV_EMAIL_NWK_SUB_STATE_SYNC_DONE,

    SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_INIT = 600,   /* The remote folder related sub-states */
    SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_SERVER,
    SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_LIST_LOCAL,
    SRV_EMAIL_NWK_SUB_STATE_LIST_FLDR_DONE,

    SRV_EMAIL_NWK_SUB_STATE_TOTAL
} srv_email_nwk_sub_state_enum;

typedef enum
{
    SRV_EMAIL_NWK_FLAG_IN_LOCAL      = 0x0001,
    SRV_EMAIL_NWK_FLAG_HEADER_ONLY   = 0x0002,
    SRV_EMAIL_NWK_FLAG_UPDATE_LOCAL  = 0x0010,
    SRV_EMAIL_NWK_FLAG_UPDATE_SERVER = 0x0020,
    SRV_EMAIL_NWK_FLAG_DELETE_LOCAL  = 0x0100,
    SRV_EMAIL_NWK_FLAG_DELETE_SERVER = 0x0200,
    SRV_EMAIL_NWK_FLAG_FLAG_VALID    = 0x1000,
    SRV_EMAIL_NWK_FLAG_TOTAL
} srv_email_nwk_flag_enum;

typedef enum
{
    SRV_EMAIL_IMAP4_FETCH_NONE,
    SRV_EMAIL_IMAP4_FETCH_ENVELOPE,
    SRV_EMAIL_IMAP4_FETCH_BODY_STRUCT,
    SRV_EMAIL_IMAP4_FETCH_CONTENT,
    SRV_EMAIL_IMAP4_FETCH_ATTACHMENT,
    SRV_EMAIL_IMAP4_FETCH_TOTAL
} srv_email_imap4_fetch_type_enum;

typedef enum
{
    SRV_EMAIL_IMAP4_PARSE_NONE,
    SRV_EMAIL_IMAP4_DECODE_CONTENT,
    SRV_EMAIL_IMAP4_DECODE_ATTACHMENT,
    SRV_EMAIL_IMAP4_PARSE_DRM,
    SRV_EMAIL_IMAP4_PARSE_READ_FILE,
    SRV_EMAIL_IMAP4_PARSE_WRITE_FILE,
    SRV_EMAIL_IMAP4_PARSE_TOTAL
} srv_email_imap4_parse_enum;

typedef struct _srv_email_addr_list_struct
{
    struct _srv_email_addr_list_struct *next;
    srv_email_stor_addr_struct addr;
} srv_email_addr_list_struct;

typedef struct _srv_email_cont_list_struct
{
    struct _srv_email_cont_list_struct *next;
    srv_email_stor_cont_header_struct cont;
    srv_email_stor_msg_cont_type type;
    WCHAR filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
} srv_email_cont_list_struct;

typedef struct _srv_email_attach_list_struct
{
    struct _srv_email_attach_list_struct *next;
    srv_email_stor_attch_struct attach;
    EMAIL_ATTCH_ID attach_id;
    WCHAR filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
} srv_email_attach_list_struct;

typedef struct
{
    srv_email_stor_msg_create_header_struct *msg_header_p;
    CHAR *subject_p;
    srv_email_stor_addr_struct *from_p;
    srv_email_stor_addr_struct *reply_to_p;
    srv_email_addr_list_struct *to_addr_p;
    srv_email_addr_list_struct *cc_addr_p;
    srv_email_addr_list_struct *bcc_addr_p;
    srv_email_cont_list_struct *cont_p;
    srv_email_attach_list_struct *attach_p;
} srv_email_msg_env_struct;

/* Network control block structure */
typedef struct _srv_email_nwk_cb_struct
{
    struct _srv_email_nwk_cb_struct *next;
    srv_email_nwk_action_enum action;
    void *action_data;
    srv_email_nwk_proc_funcptr_type proc_callback;
    void *proc_user_data;
    srv_email_nwk_finish_funcptr_type finish_callback;
    void *finish_user_data;
    EMAIL_FLDR_ID fldr_id[SRV_EMAIL_MAX_FLDR_NUM + 1];
    U16 fldr_index;
    U16 fldr_count;
    S32 state;
} srv_email_nwk_cb_struct;

#ifdef __MMI_EMAIL__

/* The Email connect context structure */
typedef struct
{
    srv_email_nwk_cb_struct *idle_cb_list_p;
    srv_email_nwk_cb_struct *pending_cb_list_p;
    srv_email_nwk_cb_struct *running_cb_p;
    srv_email_nwk_cb_struct *sync_cb_p;

    EMAIL_ACCT_ID acct_id;
    email_ps_protocol_type_enum protocol;

    EMAIL_ACCT_HANDLE acct_handle;
    //EMAIL_STOR_HANDLE stor_handle;
    EMAIL_PS_HANDLE ps_handle;

    U8 acct_digest[SRV_EMAIL_MD5_DIGEST_LEN];
    U32 wait_bearer_info;
    U32 nwk_acct_id;
    U32 capa_mask;
    CHAR from_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];
    srv_email_server_struct server_addr; /* The server info */
    srv_email_auth_struct auth;        /* The user info */
    srv_email_download_option_enum download_opt;
    U32 download_size;
    U32 retrieve_amount;

    srv_email_result_struct result;

    MMI_BOOL reauth_flag;
    MMI_BOOL destroy_flag;
    MMI_BOOL abort_flag;
    MMI_BOOL schdl_flag;
    EMAIL_REQ_ID req_id;

    MMI_BOOL refresh_result;
    MMI_BOOL refresh_notified;
    MMI_BOOL refresh_flag;
    U32 refresh_type;

#ifdef __MMI_SSO__
    U32 provider_id;
    U8 cloud_acct_id;
    S32 sso_req_id;
#endif /* __MMI_SSO__ */
} srv_email_comm_cntx_struct;

/* The Email network context structure */
typedef struct _srv_email_nwk_cntx_struct
{
    struct _srv_email_nwk_cntx_struct *next;
    srv_email_nwk_state_enum nwk_state;
    srv_email_nwk_state_enum prev_state;
    srv_email_nwk_sub_state_enum sub_state;
    email_ps_protocol_state_enum ps_state;
    srv_email_comm_cntx_struct common;
} srv_email_nwk_cntx_struct;

typedef struct _srv_email_smtp_item_struct
{
    struct _srv_email_smtp_item_struct *next;
    EMAIL_MSG_ID msg_id;
    U32 msg_time;
    MMI_BOOL is_sent;
} srv_email_smtp_item_struct;

typedef struct
{
    S32 record_num;
    srv_email_smtp_item_struct *record;
    srv_email_smtp_item_struct *curr_record;
} srv_email_smtp_list_struct;

typedef struct
{
    EMAIL_MSG_HANDLE msg_handle;
    EMAIL_MSG_ID msg_id;
    MMI_BOOL send_outbox;
    MMI_BOOL send_msg_handle;
    MMI_BOOL send_msg_id;
    MMI_BOOL move_to_sent;
    U32 total_count;
    U32 curr_count;
    srv_email_smtp_list_struct list;
} srv_email_smtp_session_struct;

typedef struct
{
    EMAIL_COMP_HANDLE comp_handle;
    EMAIL_STOR_HANDLE stor_handle;
    EMAIL_MSG_ID last_msg_id;

    CHAR from_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];               /* The from address */
    WCHAR rcpt_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];   /* The recipient file name */
    WCHAR msg_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];    /* The email file name */

    EMAIL_MSG_ID dst_msg_id;

    S32 total_count;    /* The count of the total mails */
    S32 sent_count;     /* The count of the mails sent successfully */
    S32 fail_count;     /* The count of the mails sent unsuccessfully */

    S32 major;
    S32 minor;
} srv_email_smtp_state_struct;

/* The Email SMTP context structure */
typedef struct
{
    struct _srv_email_nwk_cntx_struct *next;
    srv_email_nwk_state_enum nwk_state;
    srv_email_nwk_state_enum prev_state;
    srv_email_nwk_sub_state_enum sub_state;
    email_ps_protocol_state_enum ps_state;
    srv_email_comm_cntx_struct common;
    srv_email_smtp_session_struct session;
    srv_email_smtp_state_struct state;
    srv_email_nwk_funcptr_type callback;
    void *user_data;
} srv_email_smtp_cntx_struct;

typedef struct _srv_email_pop3_item_struct
{
    struct _srv_email_pop3_item_struct *next;
    U32 seq_no;
    U8 uid_digest[SRV_EMAIL_MD5_DIGEST_LEN];
    U32 size;
    U16 nwk_flag;
    //U16 msg_flag;
    EMAIL_MSG_ID msg_id;
} srv_email_pop3_item_struct;

typedef struct
{
    S32 record_num;
    srv_email_pop3_item_struct *record;
} srv_email_pop3_list_struct;

typedef struct
{
    MMI_BOOL sync_with_server;
    U32 total_msg_num;
    srv_email_pop3_list_struct list;
} srv_email_pop3_session_struct;

typedef struct
{
    EMAIL_STOR_HANDLE stor_handle;
    EMAIL_MSG_ID last_msg_id;

    EMAIL_MSG_HANDLE msg_handle;
    EMAIL_REQ_ID req_id;
    EMAIL_MSG_ID msg_id;

    MMI_BOOL batch_download;
    MMI_BOOL delete_fail;

    srv_email_receive_option_enum recv_opt;
    srv_email_download_option_enum download_opt;
    srv_email_retrieve_option_enum retr_opt;

    srv_email_pop3_item_struct *curr_rec_p;

    email_ps_fetch_type_enum fetch_type;

    U32 download_size;
    U32 retrieve_amount;
    U32 total_num;
    U32 received_num;
    U32 fail_num;

    U32 total_count;
    U32 curr_count;
    U32 start_index;
    U32 list_count;
    WCHAR req_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
    WCHAR rsp_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];

    S32 major;
    S32 minor;
} srv_email_pop3_state_struct;

/* The Email POP3 context structure */
typedef struct
{
    struct _srv_email_nwk_cntx_struct *next;
    srv_email_nwk_state_enum nwk_state;
    srv_email_nwk_state_enum prev_state;
    srv_email_nwk_sub_state_enum sub_state;
    email_ps_protocol_state_enum ps_state;
    srv_email_comm_cntx_struct common;
    srv_email_pop3_session_struct session;
    srv_email_pop3_state_struct state;
    srv_email_nwk_funcptr_type callback;
    void *user_data;
} srv_email_pop3_cntx_struct;

typedef struct _srv_email_imap4_item_struct
{
    struct _srv_email_imap4_item_struct *next;
    U32 seq_no;
    U32 uid;
    U32 size;
    U16 nwk_flag; /* See srv_email_nwk_flag_enum */
    U16 msg_flag; /* EMAIL_MSG_FLAG_SEEN */
    EMAIL_MSG_ID msg_id;
} srv_email_imap4_item_struct;

typedef struct
{
    S32 record_num;
    srv_email_imap4_item_struct *record;
} srv_email_imap4_list_struct;

typedef struct
{
    EMAIL_FLDR_ID fldr_id;
    MMI_BOOL sync_with_server;
    U32 total_msg_num;
    U32 uid_validity;
    srv_email_imap4_list_struct list;
} srv_email_imap4_session_struct;

typedef struct _srv_email_nwk_fldr_list_struct
{
    struct _srv_email_nwk_fldr_list_struct *next;
    srv_email_nwk_fldr_info_struct fldr_info;
} srv_email_nwk_fldr_list_struct;

typedef struct
{
    EMAIL_STOR_HANDLE stor_handle;
    EMAIL_MSG_ID last_msg_id;
    EMAIL_STOR_HANDLE msg_create_handle;

    //EMAIL_MSG_HANDLE msg_handle;
    //EMAIL_REQ_ID req_id;
    srv_email_msg_env_struct *msg_env_p;

    MMI_BOOL batch_download;
    MMI_BOOL subcribed_only;

    S32 fldr_count;
    S32 fldr_index;

    srv_email_receive_option_enum recv_opt;
    srv_email_download_option_enum download_opt;
    srv_email_retrieve_option_enum retr_opt;

    srv_email_imap4_item_struct *curr_rec_p;
    srv_email_cont_list_struct *curr_cont_p;
    srv_email_attach_list_struct *curr_att_p;
    srv_email_nwk_fldr_list_struct *fldr_list_p;
    srv_email_nwk_fldr_info_header_struct fldr_header;

    srv_email_imap4_fetch_type_enum fetch_type;

    CHAR *part_num;

    U32 download_size;
    U32 retrieve_amount;
    U32 total_num;
    U32 received_num;
    U32 fail_num;

    U32 fldr_num;
    U32 total_count;
    U32 curr_count;
    U32 start_index;
    U32 list_count;
    WCHAR *fldr_filename;

    WCHAR filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
    srv_email_imap4_parse_enum parse_state;
    FS_HANDLE src_fd;
    FS_HANDLE dst_fd;
    U32 total_size;
    U32 curr_size;
    applib_base64_part_context *base64_p;
    applib_qprint_context *qprint_p;
    U8 drm_serial;

    WCHAR req_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
    WCHAR rsp_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];

    CHAR *async_fs_data_buf;
    U32 async_fs_data_len;
    U32 async_fs_data_size;
    CHAR *async_fs_work_buf;
    fs_job_id async_fs_job_id;
    srv_email_imap4_parse_enum async_fs_state;

    /* Sync related */
    MMI_BOOL all_msg;
    EMAIL_MSG_ID msg_id;
    MMI_BOOL need_expunge;

    S32 major;
    S32 minor;
} srv_email_imap4_state_struct;

/* The Email IMAP4 context structure */
typedef struct
{
    struct _srv_email_nwk_cntx_struct *next;
    srv_email_nwk_state_enum nwk_state;
    srv_email_nwk_state_enum prev_state;
    srv_email_nwk_sub_state_enum sub_state;
    email_ps_protocol_state_enum ps_state;
    srv_email_comm_cntx_struct common;
    srv_email_imap4_session_struct session;
    srv_email_imap4_state_struct state;
    srv_email_nwk_funcptr_type callback;
    void *user_data;
} srv_email_imap4_cntx_struct;

typedef struct
{
    email_ps_imap_push_type_enum type;
    U32 seq_num;
    U32 new_flag;
} srv_email_imap4_push_struct;

// for send before sync
typedef struct _srv_email_app_id_reg_struct
{
    kal_uint16 app_str_id;
    kal_uint16 app_icon_id;
    U8 incoming_app_id;
    U8 outgoing_app_id;
    EMAIL_ACCT_ID acct_id;
    MMI_BOOL hold_incoming;    
    MMI_BOOL hold_outgoing;
    struct _srv_email_app_id_reg_struct *next;
} srv_email_app_id_reg_struct;

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__

typedef struct
{
    srv_email_nwk_cb_struct *idle_cb_list_p;
    srv_email_nwk_cb_struct *pending_cb_list_p;
    srv_email_nwk_cb_struct *running_cb_p;

    EMAIL_ACCT_ID acct_id;
    EMAIL_PS_HANDLE ps_handle;

    U32 wait_bearer_info;
    U32 nwk_acct_id;
    U32 capa_mask;

    U32 provider_id;
    U8 cloud_acct_id;
    S32 sso_req_id;

    CHAR from_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];
    srv_email_server_struct server_addr;
    srv_email_auth_struct auth;

    MMI_BOOL destroy_flag;
    MMI_BOOL abort_flag;
    MMI_BOOL schdl_flag;
    EMAIL_REQ_ID req_id;

    srv_email_result_struct result;
} srv_email_nwk_cloud_comm_cntx_struct;

typedef struct
{
    CHAR fldr_name[SRV_EMAIL_FLDR_NAME_LEN + 1];
    MMI_BOOL sync_with_server;
    U32 total_msg_num;
} srv_email_nwk_cloud_session_struct;

typedef struct
{
    EMAIL_COMP_HANDLE comp_handle;
    EMAIL_MSG_HANDLE msg_handle;

    U32 msg_part;
    U32 msg_uid;
    U32 uid_max_num;

    WCHAR filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
    WCHAR msg_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];    /* The email file name */
    WCHAR part_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
    WCHAR rsp_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];

    srv_email_msg_env_struct *msg_env_p;
    srv_email_cont_list_struct *curr_cont_p;
    srv_email_attach_list_struct *curr_att_p;
    CHAR *part_num;
    U32 fetch_type;

    U32 start_index;
    U32 list_count;

    srv_email_imap4_parse_enum parse_state;
    FS_HANDLE src_fd;
    FS_HANDLE dst_fd;
    U32 total_size;
    U32 curr_size;
    applib_base64_part_context *base64_p;
    applib_qprint_context *qprint_p;

    CHAR *async_fs_data_buf;
    U32 async_fs_data_len;
    U32 async_fs_data_size;
    CHAR *async_fs_work_buf;
    fs_job_id async_fs_job_id;
    srv_email_imap4_parse_enum async_fs_state;

    MMI_BOOL fldr_create_flag;
    MMI_BOOL fldr_open_fail_flag;

    S32 major;
    S32 minor;
} srv_email_nwk_cloud_state_struct;

/* The Cloud Email network context structure */
typedef struct _srv_email_nwk_cloud_cntx_struct
{
    struct _srv_email_nwk_cloud_cntx_struct *next;
    srv_email_nwk_state_enum nwk_state;
    srv_email_nwk_sub_state_enum sub_state;
    email_ps_protocol_state_enum ps_state;
    srv_email_nwk_cloud_comm_cntx_struct common;
    srv_email_nwk_cloud_session_struct session;
    srv_email_nwk_cloud_state_struct state;
    srv_email_nwk_funcptr_type callback;
    void *user_data;
} srv_email_nwk_cloud_cntx_struct;

#endif /* __SMS_CLOUD_SUPPORT__ */

typedef struct _srv_email_fs_async_struct
{
    struct _srv_email_fs_async_struct *next;
    fs_job_id job_id;
    void *work_buf;
    void *data_buf;
} srv_email_fs_async_struct;

EMAIL_SRV_HANDLE srv_email_get_int_srv_handle(void);

/* Set/Get error code */
void srv_email_set_error_cause(srv_email_result_struct *result, S32 major, S32 minor, CHAR *err_string);
void srv_email_get_ps_error(email_ps_result_struct *result_p, S32 *major, S32 *minor);
void srv_email_get_stor_error(S32 ret, S32 *major, S32 *minor);
void srv_email_get_acct_error(S32 ret, S32 *major, S32 *minor);
void srv_email_get_msg_error(S32 ret, S32 *major, S32 *minor);

/* Activate bearer */
srv_email_result_enum srv_email_nwk_activate_bearer(U32 nwk_acct_id, S32 *major, S32 *minor);
MMI_BOOL srv_email_nwk_is_bearer_activated(U32 nwk_acct_id);

void srv_email_compute_md5_digest(const CHAR *input, S32 input_len, U8 *digest);

void srv_email_add_fs_async_job(fs_job_id job_id, void *work_buf_p, void *data_buf_p);
MMI_BOOL srv_email_delete_fs_async_job(fs_job_id job_id);
void srv_email_fs_async_abort(fs_job_id *job_id_p, void **work_buf_p, void **data_buf_p);

MMI_BOOL srv_email_nwk_make_conn_req_file(
            U32 provider_id,
            const CHAR *from_addr_p,
            U32 protocol,
            srv_email_server_struct *server_p,
            const WCHAR *filename,
            S32 *errcode);

void srv_email_ps_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

/* Create the PS instance */
void srv_email_ps_create_instance_req(U32 req_id, email_ps_protocol_type_enum protocol);
void srv_email_ps_create_instance_rsp(void *inMsg);

/* Destroy the PS instance */
void srv_email_ps_destroy_instance_req(EMAIL_PS_HANDLE handle);
void srv_email_ps_destroy_instance_rsp(void *inMsg);

/* Connect the server */
void srv_email_ps_connect_req(
        EMAIL_PS_HANDLE handle,
        U32 nwk_acct_id,
        srv_email_server_struct *server_addr_p,
        const WCHAR *req_filename,
        const WCHAR *rsp_filename);
void srv_email_ps_connect_rsp(void *inMsg);

/* Disconnect the server */
void srv_email_ps_disconnect_req(EMAIL_PS_HANDLE handle);
void srv_email_ps_disconnect_rsp(void *inMsg);

/* Authorize with server */
void srv_email_ps_auth_req(EMAIL_PS_HANDLE handle, U32 capa_mask, srv_email_auth_struct *auth_p);
void srv_email_ps_auth_rsp(void *inMsg);

/* Open inbox or remote folder */
void srv_email_ps_open_folder_req(EMAIL_PS_HANDLE handle, const CHAR *mailbox);
void srv_email_ps_open_folder_rsp(void *inMsg);

/* List the UID */
void srv_email_ps_list_uid_req(EMAIL_PS_HANDLE handle, S32 start_index, S32 count, const WCHAR *filename, U32 ext_field);
void srv_email_ps_list_uid_rsp(void *inMsg);

/* Fetch email */
void srv_email_ps_fetch_mail_req(
        EMAIL_PS_HANDLE handle,
        U32 msg_uid,
        email_ps_fetch_type_enum type,
        S32 partial_count,
        const CHAR *part_num,
        const WCHAR *filename);
void srv_email_ps_fetch_mail_rsp(void *inMsg);

/* Abort */
void srv_email_ps_abort_req(EMAIL_PS_HANDLE handle);
void srv_email_ps_abort_rsp(void *inMsg);

/* Indication */
void srv_email_ps_disconnect_ind(void *inMsg);
void srv_email_ps_fetch_mail_ind(void *inMsg);
void srv_email_ps_imap4_push_ind(void *inMsg);

#ifdef __MMI_EMAIL__

srv_email_nwk_cntx_struct *srv_email_nwk_create_cntx(EMAIL_ACCT_ID acct_id, MMI_BOOL is_incoming, S32 *errcode);
srv_email_result_enum srv_email_nwk_run_cntx(srv_email_nwk_cntx_struct *cntx);
void srv_email_nwk_destroy_cntx(void *data);

MMI_BOOL srv_email_nwk_is_cntx_valid(srv_email_nwk_cntx_struct *cntx);
srv_email_nwk_cntx_struct *srv_email_nwk_get_cntx_list(void);

srv_email_nwk_cntx_struct *srv_email_nwk_get_cntx_by_id(EMAIL_ACCT_ID acct_id, MMI_BOOL is_incoming);
srv_email_nwk_cntx_struct *srv_email_nwk_get_cntx_by_cb(srv_email_nwk_cb_struct *cb);
srv_email_nwk_cntx_struct *srv_email_nwk_get_cntx_by_ps_handle(EMAIL_PS_HANDLE handle);

srv_email_nwk_cb_struct *srv_email_nwk_get_running_cb(srv_email_nwk_cntx_struct *cntx);
srv_email_nwk_cb_struct *srv_email_nwk_update_running_cb(srv_email_nwk_cntx_struct *cntx, MMI_BOOL notify_result);
srv_email_nwk_cb_struct *srv_email_nwk_update_running_cb_for_disc_ind(srv_email_nwk_cntx_struct *cntx);
MMI_BOOL srv_email_nwk_is_sync_cb(srv_email_nwk_cntx_struct *cntx, srv_email_nwk_cb_struct *cb);

MMI_BOOL srv_email_nwk_is_cb_full(srv_email_nwk_cntx_struct *cntx);
MMI_BOOL srv_email_nwk_is_cb_empty(srv_email_nwk_cntx_struct *cntx);
MMI_BOOL srv_email_nwk_is_pending_cb_empty(srv_email_nwk_cntx_struct *cntx);
MMI_BOOL srv_email_nwk_is_connected_cb_exist(srv_email_nwk_cntx_struct *cntx);

void srv_email_nwk_append_cb_to_idle_list(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb);
void srv_email_nwk_move_cb_to_pending(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb);
void srv_email_nwk_move_cb_to_idle(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb);
void srv_email_nwk_move_cb_running_to_idle(srv_email_nwk_cntx_struct *cntx);

void srv_email_nwk_remove_cb(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb,
        MMI_BOOL *cntx_valid);
void srv_email_nwk_abort_cb(srv_email_nwk_cntx_struct *cntx, srv_email_nwk_cb_struct *cb);

void srv_email_nwk_cb_process_notify(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb,
        srv_email_nwk_status_enum status,
        void *status_data);
void srv_email_nwk_cb_finish_notify(srv_email_nwk_cb_struct *cb, srv_email_result_struct *result);

srv_email_result_enum srv_email_nwk_fsm(void *ptr);
void srv_email_nwk_fsm_abort(srv_email_nwk_cntx_struct *cntx_p);
void srv_email_nwk_fsm_disconn_ind(srv_email_nwk_cntx_struct *cntx_p);
void srv_email_nwk_fsm_imap4_push_ind(srv_email_nwk_cntx_struct *cntx_p, email_ps_imap_push_ind_struct *ind_p);
void srv_email_nwk_fsm_schdl(void *user_data);
void srv_email_nwk_om_notify_callback(const srv_email_om_notify_struct *data);

void srv_email_nwk_start_job(srv_email_schdl_funcptr_type callback, srv_email_nwk_cntx_struct *cntx_p);
void srv_email_nwk_stop_job(srv_email_nwk_cntx_struct *cntx_p);

srv_email_result_enum srv_email_nwk_list_remote_fldr_id(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID *fldr_id,
                        U16 *fldr_cnt);

U8 srv_email_nwk_get_cbm_app_id(EMAIL_ACCT_ID acct_id, MMI_BOOL is_incoming, U32 dataacct_id, srv_email_nwk_cntx_struct *cntx_p);

/* Deactivate bearer */
void srv_email_nwk_deactivate_bearer(U32 nwk_acct_id,srv_email_nwk_cntx_struct *cntx);

void srv_email_compute_acct_digest(WCHAR *server_name, WCHAR *username, U8 *digest);

/* Send email (SMTP only) */
void srv_email_ps_send_mail_req(
        EMAIL_PS_HANDLE handle,
        const CHAR *from_addr,
        const WCHAR *rcpt_filename,
        const WCHAR *msg_filename);
void srv_email_ps_send_mail_rsp(void *inMsg);

/* List the size */
void srv_email_ps_list_size_req(EMAIL_PS_HANDLE handle, S32 start_index, S32 count, const WCHAR *filename);
void srv_email_ps_list_size_rsp(void *inMsg);

/* Delete email */
void srv_email_ps_delete_mail_req(EMAIL_PS_HANDLE handle, const WCHAR *filename);
void srv_email_ps_delete_mail_rsp(void *inMsg);

/* List remote folder (IMAP4 only) */
void srv_email_ps_list_folder_req(EMAIL_PS_HANDLE handle, MMI_BOOL subscribed_only, const WCHAR *filename);
void srv_email_ps_list_folder_rsp(void *inMsg);

/* Get email flag (IMAP4 only) */
void srv_email_ps_get_flag_req(EMAIL_PS_HANDLE handle, const WCHAR *req_filename, const WCHAR *rsp_filename);
void srv_email_ps_get_flag_rsp(void *inMsg);

/* Set email flag (IMAP4 only) */
void srv_email_ps_set_flag_req(EMAIL_PS_HANDLE handle, const WCHAR *req_filename);
void srv_email_ps_set_flag_rsp(void *inMsg);

/* Expunge email (IMAP4 only) */
void srv_email_ps_expunge_mail_req(EMAIL_PS_HANDLE handle);
void srv_email_ps_expunge_mail_rsp(void *inMsg);

/* Close folder (IMAP4 only) */
void srv_email_ps_close_folder_req(EMAIL_PS_HANDLE handle);
void srv_email_ps_close_folder_rsp(void *inMsg);

/* Indication */
void srv_email_ps_send_mail_ind(void *inMsg);

#ifdef __MMI_SSO__
srv_email_result_enum srv_email_nwk_upgrade_cloud_plugin(U32 provider_id);
MMI_BOOL srv_email_nwk_query_cloud_server_info(
            U32 provider_id,
            email_ps_protocol_type_enum protocol,
            srv_email_server_struct *server_p);
MMI_BOOL srv_email_nwk_query_cloud_dtcnt_id(U32 provider_id, U32 *dtcnt_id);
#endif /* __MMI_SSO__ */

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__

void srv_email_nwk_cloud_session_init(srv_email_nwk_cloud_session_struct *sess_p);
void srv_email_nwk_cloud_session_free(srv_email_nwk_cloud_session_struct *sess_p);

void srv_email_nwk_cloud_state_init(srv_email_nwk_cloud_state_struct *state_p);
void srv_email_nwk_cloud_state_free(srv_email_nwk_cloud_state_struct *state_p);

void srv_email_nwk_cloud_cntx_init(srv_email_nwk_cloud_cntx_struct *cntx_p);
void srv_email_nwk_cloud_cntx_free(srv_email_nwk_cloud_cntx_struct *cntx_p);

MMI_BOOL srv_email_nwk_cloud_is_cntx_valid(srv_email_nwk_cloud_cntx_struct *cntx_p);
srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_create_cntx(EMAIL_ACCT_ID acct_id, S32 *errcode);
void srv_email_nwk_cloud_destroy_cntx(void *data);

MMI_BOOL srv_email_nwk_cloud_is_cb_empty(srv_email_nwk_cloud_cntx_struct *cntx_p);
MMI_BOOL srv_email_nwk_cloud_is_pending_cb_empty(srv_email_nwk_cloud_cntx_struct *cntx_p);
MMI_BOOL srv_email_nwk_cloud_is_cb_full(srv_email_nwk_cloud_cntx_struct *cntx_p);

void srv_email_nwk_cloud_append_cb_to_idle_list(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p);
void srv_email_nwk_cloud_move_cb_to_idle(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p);
void srv_email_nwk_cloud_move_cb_to_pending(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p);

srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_get_cntx_by_cb(srv_email_nwk_cb_struct *cb_p);
srv_email_nwk_cb_struct *srv_email_nwk_cloud_get_running_cb(srv_email_nwk_cloud_cntx_struct *cntx_p);

void srv_email_nwk_cloud_abort_cb(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p);
void srv_email_nwk_cloud_remove_cb(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p,
        MMI_BOOL *cntx_valid);

void srv_email_nwk_cloud_start_job(
        srv_email_schdl_funcptr_type callback,
        srv_email_nwk_cloud_cntx_struct *cntx_p);
void srv_email_nwk_cloud_stop_job(srv_email_nwk_cloud_cntx_struct *cntx_p);

srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_get_cntx_by_id(EMAIL_ACCT_ID acct_id);
srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_get_cntx_by_ps_handle(EMAIL_PS_HANDLE handle);

srv_email_result_enum srv_email_nwk_cloud_run_cntx(srv_email_nwk_cloud_cntx_struct *cntx_p);

void srv_email_nwk_cloud_fsm_schdl(void *user_data);
void srv_email_nwk_cloud_fsm_abort(srv_email_nwk_cloud_cntx_struct *cntx_p);
srv_email_result_enum srv_email_nwk_cloud_fsm_retry(srv_email_nwk_cloud_cntx_struct *cntx_p);

MMI_BOOL srv_email_nwk_cloud_create_instance_rsp_hdlr(email_ps_create_instance_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_connect_rsp_hdlr(email_ps_conn_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_disconnect_rsp_hdlr(email_ps_disconn_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_auth_rsp_hdlr(email_ps_auth_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_fldr_open_rsp_hdlr(email_ps_fld_open_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_fldr_create_rsp_hdlr(email_ps_fld_create_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_append_mail_rsp_hdlr(email_ps_msg_append_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_list_uid_rsp_hdlr(email_ps_msg_uid_list_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_fetch_mail_rsp_hdlr(email_ps_msg_fetch_rsp_struct *rsp_p);
MMI_BOOL srv_email_nwk_cloud_disconnect_ind_hdlr(email_ps_disconn_ind_struct *ind_p);
MMI_BOOL srv_email_nwk_cloud_imap4_push_ind_hdlr(email_ps_imap_push_ind_struct *ind_p);

void srv_email_ps_create_folder_req(EMAIL_PS_HANDLE handle, const CHAR *mailbox);
void srv_email_ps_create_folder_rsp(void *inMsg);
void srv_email_ps_append_mail_req(
        EMAIL_PS_HANDLE handle,
        const CHAR *fldr_name_p,
        const WCHAR *msg_filename);
void srv_email_ps_append_mail_rsp(void *inMsg);

#endif /* __SMS_CLOUD_SUPPORT__ */

#endif /* EMAILNETWORKPORT_H */

