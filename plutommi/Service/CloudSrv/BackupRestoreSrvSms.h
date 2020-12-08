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
 *  BackupRestoreSrvSms.h
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
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BACKUP_RESTORE_SRV_SMS_H__
#define __BACKUP_RESTORE_SRV_SMS_H__

#ifdef __SMS_CLOUD_SUPPORT__

#include "CloudSrvGprot.h"
#include "CloudSrvIprot.h"
#include "BackupRestoreSrv.h"
#include "EmailSrvGprot.h"
//#include "EventsGprot.h"
#include "SsoSrvGprot.h"

#define SRV_CLD_MAX_SMS_LISTED_NUM      (0xffffffff)

S32 srv_cloud_sms_conn_info_malloc(
        srv_cloud_sms_ctx_struct *sms,
        srv_email_conn_opt_for_cld_srv_struct *conn);

void srv_cloud_sms_conn_info_free(srv_email_conn_opt_for_cld_srv_struct *conn);

void srv_cloud_sms_acct_conn_callback(
    srv_email_result_struct *result,
    EMAIL_REQ_ID req_id,
    void *user_data);

void srv_cloud_sms_acct_append_callback(
    srv_email_result_struct *result,
    EMAIL_REQ_ID req_id,
    void *user_data);

void srv_cloud_sms_acct_proc_callback(srv_email_nwk_proc_struct *data);

S32 srv_cloud_sms_op(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_op_fsm(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_op_init(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_op_cookie(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_op_conn(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_op_get_uid_list(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_op_mark_uid(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_op_get_msg(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_op_notify_app(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_retry(srv_cloud_sms_ctx_struct *sms);

void srv_cloud_sms_close(srv_cloud_sms_ctx_struct *sms);

void srv_cloud_sms_abort(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_get_data(srv_cloud_sms_ctx_struct *sms);

S32 srv_cloud_sms_put_data(srv_cloud_sms_ctx_struct *sms);

#endif /* __SMS_CLOUD_SUPPORT__ */

#endif /* __BACKUP_RESTORE_SRV_SMS_H__ */

