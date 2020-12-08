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
 *  EmailSrvNetwork.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to define the Email network service functions.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef EMAILNETWORKSRV_H
#define EMAILNETWORKSRV_H

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "EmailSrvGprot.h"

/* The Email network handle type */
typedef U32     EMAIL_NWK_HANDLE;

#define EMAIL_NWK_INVALID_HANDLE            (0)

#define SRV_EMAIL_NWK_MAX_FILE_NAME_LEN     (64)

/* The Email network action */
typedef enum
{
    SRV_EMAIL_NWK_NONE,             /* None */
    SRV_EMAIL_NWK_CONNECT,          /* Connect the server, no data structure */
    SRV_EMAIL_NWK_SEND,             /* Send email(s) to server, srv_email_nwk_send_struct */
    SRV_EMAIL_NWK_RETRIEVE,         /* Retrieve single email from server, srv_email_nwk_retr_struct */
    SRV_EMAIL_NWK_RECEIVE,          /* Batch receive emails from server, srv_email_nwk_recv_struct */
    SRV_EMAIL_NWK_SYNC,             /* Sync email(s) with server, srv_email_nwk_sync_struct */
    SRV_EMAIL_NWK_LIST_FOLDER,      /* List remote folders from server, no data structure */
    SRV_EMAIL_NWK_REFRESH,          /* Refresh the inbox, srv_email_nwk_refresh_struct */
    SRV_EMAIL_NWK_DISCONNECT,       /* Disconnect the server, no data structure */
    SRV_EMAIL_NWK_TEST_NWK,         /* Test the network connection, no data structure */
    SRV_EMAIL_NWK_CLD_APPEND,
    SRV_EMAIL_NWK_CLD_GET_UID,
    SRV_EMAIL_NWK_CLD_GET_MSG,
    SRV_EMAIL_NWK_TOTAL_ACTION      /* Total */
} srv_email_nwk_action_enum;

typedef void (*srv_email_nwk_funcptr_type)(void *user_data);

/* The Email operation finish callback data structure */
typedef struct
{
    srv_email_result_struct result;
    S32 action;
    void *user_data;
} srv_email_nwk_finish_struct;

typedef void (*srv_email_nwk_finish_funcptr_type)(srv_email_nwk_finish_struct *data);

/* The send option structure */
typedef struct
{
    MMI_BOOL send_outbox;
    EMAIL_MSG_HANDLE msg_handle;
    EMAIL_MSG_ID msg_id;
    MMI_BOOL move_to_sent;
} srv_email_nwk_send_struct;

#ifdef __MMI_EMAIL__

/* The retrieve option structure */
typedef struct
{
    EMAIL_FLDR_ID fldr_id;
    EMAIL_MSG_ID msg_id;
    srv_email_retrieve_option_enum retr_opt;
    EMAIL_ATTCH_ID attach_id;
} srv_email_nwk_retr_struct;

/* The receive option structure */
typedef struct
{
    MMI_BOOL all_fldr;
    EMAIL_FLDR_ID fldr_id;
    srv_email_receive_option_enum recv_opt;
} srv_email_nwk_recv_struct;

/* The sync option structure */
typedef struct
{
    MMI_BOOL all_fldr;
    EMAIL_FLDR_ID fldr_id;
    MMI_BOOL all_msg;
    EMAIL_MSG_ID msg_id;
} srv_email_nwk_sync_struct;

typedef struct 
{
    WCHAR filename[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
    U32 fldr_num;
    MMI_BOOL subscribed_only;
} srv_email_nwk_list_fldr_struct;

/* The refresh option structure */
typedef struct
{
    srv_email_receive_option_enum recv_opt;
} srv_email_nwk_refresh_struct;

typedef struct
{
    U32 fldr_num;
    WCHAR delimiter;
} srv_email_nwk_fldr_info_header_struct;

typedef struct
{
    CHAR folder_name[SRV_EMAIL_FLDR_NAME_LEN + 1];
    EMAIL_FLDR_ID fldr_id;
    MMI_BOOL subscribed;
} srv_email_nwk_fldr_info_struct;

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__

typedef struct
{
    CHAR fldr_name[SRV_EMAIL_FLDR_NAME_LEN + 1];
    MMI_BOOL fldr_create;
} srv_email_nwk_cloud_conn_struct;

typedef enum
{
    SRV_EMAIL_NWK_CLOUD_MSG_ALL_UID     = 0x00,
    SRV_EMAIL_NWK_CLOUD_MSG_ENVELOPE    = 0x01,
    SRV_EMAIL_NWK_CLOUD_MSG_CONTENT     = 0x02,
    SRV_EMAIL_NWK_CLOUD_MSG_SMS         = SRV_EMAIL_NWK_CLOUD_MSG_ENVELOPE | SRV_EMAIL_NWK_CLOUD_MSG_CONTENT,
    SRV_EMAIL_NWK_CLOUD_MSG_TOTAL
} srv_email_nwk_cloud_msg_part_enum;

typedef struct
{
    U32 msg_part;
    U32 msg_uid;
    U32 uid_max_num;
    WCHAR filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
    WCHAR part_filename[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
} srv_email_nwk_cloud_retr_struct;

#endif /* __SMS_CLOUD_SUPPORT__ */

#ifdef __MMI_EMAIL__

/* Create Email network instance */
srv_email_result_enum srv_email_nwk_create(
                        EMAIL_ACCT_ID acct_id,
                        MMI_BOOL is_incoming,
                        EMAIL_NWK_HANDLE *handle);

/* Destroy Email network instance */
srv_email_result_enum srv_email_nwk_destroy(EMAIL_NWK_HANDLE handle);

/* Set the process notify function */
srv_email_result_enum srv_email_nwk_set_process_notify(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_proc_funcptr_type callback,
                        void *user_data);

/* Set the finish notify function */
srv_email_result_enum srv_email_nwk_set_finish_notify(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_finish_funcptr_type callback,
                        void *user_data);

/* The network operation */
srv_email_result_enum srv_email_nwk_test_nwk(EMAIL_NWK_HANDLE handle);
srv_email_result_enum srv_email_nwk_connect(EMAIL_NWK_HANDLE handle);
srv_email_result_enum srv_email_nwk_disconnect(EMAIL_NWK_HANDLE handle);
srv_email_result_enum srv_email_nwk_send(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_send_struct *nwk_send_p);
srv_email_result_enum srv_email_nwk_retrieve(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_retr_struct *nwk_retr_p);
srv_email_result_enum srv_email_nwk_receive(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_recv_struct *nwk_recv_p);
srv_email_result_enum srv_email_nwk_sync(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_sync_struct *nwk_sync_p);
srv_email_result_enum srv_email_nwk_list_folder(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_list_fldr_struct *list_fldr_p);
srv_email_result_enum srv_email_nwk_refresh(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_refresh_struct *refresh_p);

/* Abort do the operation */
srv_email_result_enum srv_email_nwk_abort(EMAIL_NWK_HANDLE handle);

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__

srv_email_result_enum srv_email_nwk_cloud_create(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_NWK_HANDLE *handle);
srv_email_result_enum srv_email_nwk_cloud_destroy(EMAIL_NWK_HANDLE handle);
srv_email_result_enum srv_email_nwk_cloud_set_option(
                        EMAIL_NWK_HANDLE handle,
                        U32 provider_id,
                        U8 cloud_acct_id);
srv_email_result_enum srv_email_nwk_cloud_set_process_notify(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_proc_funcptr_type callback,
                        void *user_data);
srv_email_result_enum srv_email_nwk_cloud_set_finish_notify(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_finish_funcptr_type callback,
                        void *user_data);
srv_email_result_enum srv_email_nwk_cloud_connect(
                        EMAIL_NWK_HANDLE handle,
                        CHAR *fldr_name_p,
                        MMI_BOOL fldr_create);
srv_email_result_enum srv_email_nwk_cloud_disconnect(EMAIL_NWK_HANDLE handle);
srv_email_result_enum srv_email_nwk_cloud_append(
                        EMAIL_NWK_HANDLE handle,
                        EMAIL_MSG_HANDLE msg_handle);
srv_email_result_enum srv_email_nwk_cloud_retrieve(
                        EMAIL_NWK_HANDLE handle,
                        srv_email_nwk_cloud_retr_struct *nwk_retr_p);
srv_email_result_enum srv_email_nwk_cloud_abort(EMAIL_NWK_HANDLE handle);
srv_email_result_enum srv_email_nwk_cloud_retry(EMAIL_NWK_HANDLE handle);

#endif /* __SMS_CLOUD_SUPPORT__ */

#endif /* EMAILNETWORKSRV_H */
