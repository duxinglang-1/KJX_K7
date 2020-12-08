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
 * EmailSrvAccount.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to declare the Email service function.
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _EMAIL_SRV_ACCOUNT_H
#define _EMAIL_SRV_ACCOUNT_H

#include "EmailSrvGProt.h"
#include "EmailSrvIprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvStorage.h"

#include "MMIDataType.h"
#include "kal_general_types.h"

#ifdef __SMS_CLOUD_SUPPORT__
#define SRV_EMAIL_ACCT_FOR_CLOUD 1
#else
#define SRV_EMAIL_ACCT_FOR_CLOUD 0
#endif

#ifdef __MMI_EMAIL_IMAP_PUSH__
#define SRV_EMAIL_ACCOUNT_HANDLE_MAX_NUMBER             (7+SRV_EMAIL_ACCT_FOR_CLOUD)
#else
#define SRV_EMAIL_ACCOUNT_HANDLE_MAX_NUMBER             (5+SRV_EMAIL_ACCT_FOR_CLOUD)
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

#define SRV_EMAIL_ACCOUNT_REQ_MAX_NUMBER                (10)
#define SRV_EMAIL_ACCOUNT_MAX_REMOTE_FLDR_NUMBER        (20)


typedef enum
{
    SRV_EMAIL_ACCT_STATE_INVALID,
    SRV_EMAIL_ACCT_STATE_INIT,
    SRV_EMAIL_ACCT_STATE_READ,
    SRV_EMAIL_ACCT_STATE_EDIT,
    SRV_EMAIL_ACCT_STATE_TOTAL
} srv_email_acct_state_enum;


typedef struct
{
    MMI_BOOL in_use;
    EMAIL_ACCT_ID acct_id;
    srv_email_acct_info_struct *account_info;
    srv_email_acct_state_enum state;
    srv_email_acct_funcptr_type callback;
    void *user_data;
    srv_email_nwk_proc_funcptr_type proc_callback;
    void *proc_user_data;
    EMAIL_SRV_HANDLE srv_handle;
    EMAIL_STOR_HANDLE stor_handle;
    MMI_BOOL incoming_connected;
    MMI_BOOL outgoing_connected;
    EMAIL_NWK_HANDLE nwk_incoming_handle;
    EMAIL_NWK_HANDLE nwk_outgoing_handle;
    srv_email_req_id_action_map_struct req_id_action_map_list[SRV_EMAIL_ACCOUNT_REQ_MAX_NUMBER];
    WCHAR remote_fldr_seperator;
    U32 remote_fldr_num;
    MMI_BOOL remote_fldr_sub[SRV_EMAIL_ACCOUNT_MAX_REMOTE_FLDR_NUMBER];
#ifdef __SMS_CLOUD_SUPPORT__
    srv_email_acct_conn_type conn_type;
    srv_email_conn_opt_for_cld_srv_struct conn;
    EMAIL_MSG_HANDLE cld_msg_hd;    // used to store MSG info for cloud
#endif /* __SMS_CLOUD_SUPPORT__ */
} srv_email_acct_object_info_struct;

typedef struct
{
    srv_email_acct_object_info_struct *account_object;
    MMI_BOOL incoming_server;                           /* for connect operation only */
    EMAIL_REQ_ID req_id;
} srv_email_acct_nwk_info_struct;

typedef struct
{
    srv_email_acct_object_info_struct *account_object;
    EMAIL_FLDR_ID del_fldr_id_list[SRV_EMAIL_ACCOUNT_MAX_REMOTE_FLDR_NUMBER];
    U16 remote_fldr_index_list[SRV_EMAIL_ACCOUNT_MAX_REMOTE_FLDR_NUMBER];
    U16 del_fldr_num;
    EMAIL_REQ_ID req_id;
} srv_email_acct_del_remote_fldr_info_struct;

#endif /* _EMAIL_SRV_ACCOUNT_H */
