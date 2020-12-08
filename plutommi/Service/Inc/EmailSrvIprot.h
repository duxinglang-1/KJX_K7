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
 *  EmailSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the Email APIs
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _EMAIL_SRV_IPROT_H_
#define _EMAIL_SRV_IPROT_H_

#include "MMI_include.h"
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"

#include "EmailSrvGprot.h"
 
/*************************************************************************
* Constant values
*************************************************************************/

#define SRV_EMAIL_CLOUD_ACCT_ID     (100)
    
/* CBM service event id definition */
typedef enum
{
    EVT_ID_SRV_EMAIL_CLOUD_IND = SRV_EMAIL_BASE + 1,
    EVT_ID_SRV_EMAIL_BACKUP_RESTORE_IND,
    EVT_ID_SRV_EMAIL_TOTAL
} srv_email_event_id_enum;


/*************************************************************************
* Structures
*************************************************************************/

typedef void (*srv_email_cloud_funcptr_type)(MMI_BOOL result, void *user_data);

typedef enum
{
    SRV_EMAIL_CLOUD_NOT_LOGIN,
    SRV_EMAIL_CLOUD_COOKIE_EXPIRY,
    SRV_EMAIL_CLOUD_TOTAL,
} srv_email_cloud_type_enum;

/* Event structure for EVT_ID_SRV_EMAIL_CLOUD_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    U32 provider_id;
    U8 cloud_acct_id;
    srv_email_cloud_type_enum type;
    srv_email_cloud_funcptr_type callback;
} srv_email_evt_cloud_ind_struct;

/* Event structure for EVT_ID_SRV_EMAIL_BACKUP_RESTORE_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_email_cloud_type_enum type;
} srv_email_evt_backup_restore_ind_struct;


typedef struct
{
    U32   provider_id;
    U8    cloud_acct_id;
    CHAR *conn_mailbox;
} srv_email_conn_opt_for_cld_srv_struct;

typedef enum
{
    SRV_EMAIL_ACCT_CONN_NORMAL = 0,
    SRV_EMAIL_ACCT_CONN_SMS,
} srv_email_acct_conn_type;

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_connect_for_cloud
 * DESCRIPTION
 *  This function is used to mark the connction type, it's optional.
 *  The default value is SRV_EMAIL_ACCT_CONN_NORMAL.
 *  It should be called after create account handle.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  connect         : [IN]      Connection information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_set_type(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_conn_type type);

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_set_cloud_acct
 * DESCRIPTION
 *  This function is used to mark whether the account is cloud account.
 *  It should be called after create account handle.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  connect         : [IN]      Connection information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_set_cloud_acct(
                                EMAIL_ACCT_ID acct_id,
                                MMI_BOOL is_cloud_acct);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_connect_for_cloud
 * DESCRIPTION
 *  This function is used to connect the  server.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  connect         : [IN]      Connection information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_conn_set_cld_srv_opt(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_conn_opt_for_cld_srv_struct *connect);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_append_msg
 * DESCRIPTION
 *  This function is used to append one email in the currenct selected mailbox. (ONLY for IMAP4)
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  msg_handle      : [IN]      MSG handle, which will be used to compose the eml file
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_append_msg(
                                EMAIL_ACCT_HANDLE acct_handle,
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_receive_for_cloud
 * DESCRIPTION
 *  This function is used to receive the emails of this account from server.
 *  After get the result notify, result will be stored in this filename
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  filename        : [IN]      The file to store <imap_uid(U32), sms_uid(CHAR*)> list
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_receive_uid_list_for_cloud(
                                EMAIL_ACCT_HANDLE acct_handle,
                                const WCHAR *filename,
                                U32 uid_max_num,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_receive_for_cloud
 * DESCRIPTION
 *  This function is used to receive the emails of this account from server.
 *  After get the result notify, please call srv_email_msg_get_*() to ge MSG info
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  imap_uid        : [IN]      The receive option
 *  msg_handle      : [IN]      The MSG handle, used to store the msg content
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_receive_msg_for_cloud(
                                EMAIL_ACCT_HANDLE acct_handle,
                                U32 imap_uid,
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_REQ_ID *req_id);

extern srv_email_result_enum srv_email_acct_cloud_retry(
                                EMAIL_ACCT_HANDLE acct_handle,
                                U32 provider_id,
                                U8 cloud_acct_id);

extern srv_email_result_enum srv_email_msg_get_extra_field(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_save_part_enum type,
                                CHAR **buff,
                                U32 *len);

extern srv_email_result_enum srv_email_msg_update_extra_field(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_save_part_enum type,
                                CHAR *buff,
                                U32 buff_len);

extern srv_email_result_enum srv_email_msg_update_date(EMAIL_MSG_HANDLE msg_handle, U32 date);

extern EMAIL_ACCT_ID srv_email_acct_create_for_cloud(CHAR *email_addr);
extern srv_email_result_enum srv_email_acct_get_info_for_cloud(EMAIL_ACCT_ID acct_id, CHAR *email_addr, U32 *addr_buflen);
extern srv_email_result_enum srv_email_acct_delete_for_cloud(EMAIL_ACCT_ID acct_id);

#endif /* _EMAIL_SRV_IPROT_H_ */

