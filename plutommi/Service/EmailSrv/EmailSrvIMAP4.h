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
 *  EmailSrvIMAP4.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to define the Email IMAP4 service functions.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef EMAILSRVIMAP4_H
#define EMAILSRVIMAP4_H

#include "MMI_trc_Int.h"
#include "mmi_inet_app_trc.h"
#include "EmailSrvGprot.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvNetworkProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

#ifdef __MMI_EMAIL__

#define SRV_EMAIL_IMAP4_LIST_NUM_PER_TIME    (100)

#define SRV_EMAIL_IMAP4_SET_SUB_STATE(cntx_p, state) \
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_STATE_IMAP4_SET_SUB_STATE, cntx_p, state); \
            cntx_p->sub_state = state

void srv_email_imap4_cntx_init(srv_email_imap4_cntx_struct *cntx_p);
void srv_email_imap4_cntx_free(srv_email_imap4_cntx_struct *cntx_p);

srv_email_result_enum srv_email_imap4_update(
                        srv_email_imap4_cntx_struct *cntx_p,
                        EMAIL_FLDR_ID fldr_id,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

srv_email_result_enum srv_email_imap4_update_fsm(srv_email_imap4_cntx_struct *cntx_p);

srv_email_result_enum srv_email_imap4_receive(
                        srv_email_imap4_cntx_struct *cntx_p,
                        srv_email_nwk_recv_struct *recv_p,
                        S32 fldr_count,
                        S32 fldr_index,
                        srv_email_download_option_enum download_opt,
                        U32 download_size,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

srv_email_result_enum srv_email_imap4_retrieve(
                        srv_email_imap4_cntx_struct *cntx_p,
                        srv_email_nwk_retr_struct *retr_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

srv_email_result_enum srv_email_imap4_recv_fsm(srv_email_imap4_cntx_struct *cntx_p);

srv_email_result_enum srv_email_imap4_list_folder(
                        srv_email_imap4_cntx_struct *cntx_p,
                        srv_email_nwk_list_fldr_struct *list_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

srv_email_result_enum srv_email_imap4_list_fldr_fsm(srv_email_imap4_cntx_struct *cntx_p);

void srv_email_imap4_update_abort(srv_email_imap4_cntx_struct *cntx_p);
void srv_email_imap4_receive_abort(srv_email_imap4_cntx_struct *cntx_p);
void srv_email_imap4_list_fldr_abort(srv_email_imap4_cntx_struct *cntx_p);

srv_email_result_enum srv_email_imap4_sync(
                        srv_email_imap4_cntx_struct *cntx_p, 
                        srv_email_nwk_sync_struct *sync_p, 
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);
void srv_email_imap4_sync_fsm(srv_email_imap4_cntx_struct *cntx_p);
srv_email_result_enum srv_email_imap4_sync_abort(srv_email_imap4_cntx_struct *cntx_p);

MMI_BOOL srv_email_imap4_is_push_allowed(srv_email_imap4_cntx_struct *cntx_p);

srv_email_result_enum srv_email_imap4_refresh(
                        srv_email_imap4_cntx_struct *cntx_p,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

void srv_email_imap4_proc_om_notify(
        srv_email_imap4_cntx_struct *cntx_p,
        srv_email_om_notify_struct *notify_p);

#endif /* __MMI_EMAIL__ */

/* Common IMAP4 Func */
srv_email_msg_env_struct *srv_email_imap4_new_envelope(void);
void srv_email_imap4_free_envelope(srv_email_msg_env_struct **msg_env_p);
S32 srv_email_imap4_get_encode_type(const CHAR *enc_str);
srv_email_result_enum srv_email_imap4_read_body_struct(
                        const WCHAR *filename,
                        srv_email_msg_env_struct *msg_env_p,
                        S32 *major_error,
                        S32 *minor_error);
srv_email_result_enum srv_email_imap4_read_content(
                        const WCHAR *filename,
                        srv_email_cont_list_struct *cont_p,
                        S32 *major_error,
                        S32 *minor_error);

#endif /* EMAILSRVIMAP4_H */
