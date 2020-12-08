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
 *  EmailSrvPOP3.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to define the Email POP3 service functions.
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
#ifndef EMAILSRVPOP3_H
#define EMAILSRVPOP3_H

#include "MMI_trc_Int.h"
#include "mmi_inet_app_trc.h"
#include "EmailSrvGprot.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvNetworkProt.h"
#include "MMIDataType.h"

#define SRV_EMAIL_POP3_LIST_NUM_PER_TIME    (100)

#define SRV_EMAIL_POP3_SET_SUB_STATE(cntx_p, state) \
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_STATE_POP3_SET_SUB_STATE, cntx_p, state); \
            cntx_p->sub_state = state

void srv_email_pop3_cntx_init(srv_email_pop3_cntx_struct *cntx_p);
void srv_email_pop3_cntx_free(srv_email_pop3_cntx_struct *cntx_p);

srv_email_result_enum srv_email_pop3_update(
                        srv_email_pop3_cntx_struct *cntx_p,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

srv_email_result_enum srv_email_pop3_update_fsm(srv_email_pop3_cntx_struct *cntx_p);

srv_email_result_enum srv_email_pop3_receive(
                        srv_email_pop3_cntx_struct *cntx_p,
                        srv_email_nwk_recv_struct *recv_p,
                        srv_email_download_option_enum download_opt,
                        U32 download_size,
                        U32 retrieve_amount,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

srv_email_result_enum srv_email_pop3_retrieve(
                        srv_email_pop3_cntx_struct *cntx_p,
                        srv_email_nwk_retr_struct *retr_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

srv_email_result_enum srv_email_pop3_recv_fsm(srv_email_pop3_cntx_struct *cntx_p);

srv_email_result_enum srv_email_pop3_disconnect(
                        srv_email_pop3_cntx_struct *cntx_p,
                        srv_email_nwk_funcptr_type callback,
                        void *user_data);

srv_email_result_enum srv_email_pop3_disc_fsm(srv_email_pop3_cntx_struct *cntx_p);

void srv_email_pop3_update_abort(srv_email_pop3_cntx_struct *cntx_p);
void srv_email_pop3_receive_abort(srv_email_pop3_cntx_struct *cntx_p);
void srv_email_pop3_disconnect_abort(srv_email_pop3_cntx_struct *cntx_p);

void srv_email_pop3_proc_om_notify(
        srv_email_pop3_cntx_struct *cntx_p,
        srv_email_om_notify_struct *notify_p);

#endif /* EMAILSRVPOP3_H */
