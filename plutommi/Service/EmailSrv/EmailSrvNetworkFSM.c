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
 *  EmailSrvNetworkFSM.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email network FSM functions.
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

#include "cbm_api.h"
#include "CbmSrvGprot.h"

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvNetworkProt.h"
#include "EmailSrvIMAP4.h"
#include "EmailSrvSso.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_trc_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "kal_public_api.h"
#include "email_ps_public.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "cbm_consts.h"
#include "mmi_frm_mem_gprot.h"

#include "DtcntSrvGprot.h"

#if defined(__MMI_SSO__) || defined(__SMS_CLOUD_SUPPORT__)
#include "CloudSrvGprot.h"
#include "SsoSrvGprot.h"
#include "EmailSrvIprot.h"
#ifdef __MMI_CLOUD_VPP_UPGRADE__
#include "UpgradeSrvGprot.h"
#endif
#endif /* defined(__MMI_SSO__) || defined(__SMS_CLOUD_SUPPORT__) */

#ifdef __MMI_EMAIL__

#include "EmailSrvSMTP.h"
#include "EmailSrvPOP3.h"
#include "EmailSrvStorage.h"

extern srv_email_app_id_reg_struct *srv_email_app_id_reg;

static mmi_ret srv_email_nwk_fsm_bearer_info_ind(mmi_event_struct *param);
#ifdef __MMI_SSO__
static void srv_email_nwk_sso_query_done(MMI_BOOL result, void *user_data);
static void srv_email_nwk_sso_refresh_done(S32 req_id, srv_sso_result result, void *user_data);
#endif /* __MMI_SSO__ */

static srv_email_result_enum srv_email_nwk_fsm_send(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_send_struct *send_p);
static srv_email_result_enum srv_email_nwk_fsm_update(
                                srv_email_nwk_cntx_struct *cntx_p,
                                EMAIL_FLDR_ID fldr_id);
static srv_email_result_enum srv_email_nwk_fsm_retrieve(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_retr_struct *retr_p);
static srv_email_result_enum srv_email_nwk_fsm_receive(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_recv_struct *recv_p,
                                S32 fldr_count,
                                S32 fldr_index);
static srv_email_result_enum srv_email_nwk_fsm_sync(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_sync_struct *sync_p);
static srv_email_result_enum srv_email_nwk_fsm_list_folder(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_list_fldr_struct *list_p);
static srv_email_result_enum srv_email_nwk_fsm_refresh(srv_email_nwk_cntx_struct *cntx_p);

static srv_email_result_enum srv_email_nwk_fsm_init(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_created(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_activated(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_connected(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_authorized(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_queried(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_ready(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_updated(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_sent(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_received(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_synced(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_folder_listed(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_disconnected(srv_email_nwk_cntx_struct *cntx_p);

static void srv_email_nwk_fsm_init_fail(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_create_fail(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_activate_fail(srv_email_nwk_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_fsm_connect_fail(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_update_fail(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_send_fail(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_recv_fail(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_sync_fail(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_list_rf_fail(srv_email_nwk_cntx_struct *cntx_p);

static srv_email_result_enum srv_email_nwk_err_rsp(srv_email_nwk_cntx_struct *cntx_p);

static srv_email_result_enum srv_email_nwk_fsm_query_done(
                                MMI_BOOL result,
                                const WCHAR *username,
                                const WCHAR *password,
                                void *user_data);
static void srv_email_nwk_fsm_send_done(void *user_data);
static void srv_email_nwk_fsm_update_done(void *user_data);
static void srv_email_nwk_fsm_receive_done(void *user_data);
static void srv_email_nwk_fsm_sync_done(void *user_data);
static void srv_email_nwk_fsm_list_fldr_done(void *user_data);
static void srv_email_nwk_fsm_disconnect_done(void *user_data);
static void srv_email_nwk_fsm_refresh_done(void *user_data);

static void srv_email_nwk_fsm_send_abort(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_update_abort(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_receive_abort(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_sync_abort(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_list_folder_abort(srv_email_nwk_cntx_struct *cntx_p);
static void srv_email_nwk_fsm_disconnect_abort(srv_email_nwk_cntx_struct *cntx_p);

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__

static void srv_email_nwk_cloud_decode_base64_qprint(void *user_data);

static srv_email_result_enum srv_email_nwk_cloud_appd_fsm(srv_email_nwk_cloud_cntx_struct *cntx_p);
static srv_email_result_enum srv_email_nwk_cloud_retr_fsm(srv_email_nwk_cloud_cntx_struct *cntx_p);

static srv_email_result_enum srv_email_nwk_cloud_fsm(void *ptr);

#endif /* __SMS_CLOUD_SUPPORT__ */

#ifdef __MMI_EMAIL__

/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_bearer_info_ind
 * DESCRIPTION
 *  This function is used to process the bearer info.
 * PARAMETERS
 *  param           [IN]        The bearer info parameter
 * RETURNS
 *  MMI_RET_OK.
 *****************************************************************************/
static mmi_ret srv_email_nwk_fsm_bearer_info_ind(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_bearer_info_struct *bearer_info_p = (srv_cbm_bearer_info_struct*)param;
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)bearer_info_p->user_data;
    srv_email_nwk_cntx_struct *cntx = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    MMI_BOOL ret = MMI_FALSE;
    U8 app_id = 0;
    kal_int32 state = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_BEARER_INFO_IND,
        cntx_p,
        bearer_info_p->account_id,
        bearer_info_p->state);

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return MMI_RET_OK;
    }

    comm_p = &cntx_p->common;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_INFO_NWK_CNTX_BEARER_STATE,
        cntx_p,
        cntx_p->nwk_state,
        comm_p->wait_bearer_info);

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_ACTIVATING ||
        !(comm_p->wait_bearer_info & bearer_info_p->state))
    {
        return MMI_RET_OK;
    }

    switch (bearer_info_p->state)
    {
        case SRV_CBM_ACTIVATING:
            comm_p->wait_bearer_info = SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED;
            return MMI_RET_OK;

        case SRV_CBM_ACTIVATED:
            app_id = cbm_get_app_id(comm_p->nwk_acct_id);
            cbm_hold_bearer(app_id);
            break;

        case SRV_CBM_DEACTIVATED:
            srv_email_set_error_cause(
                &comm_p->result,
                SRV_EMAIL_MAIL_ERROR,
                SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL,
                NULL);
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, bearer_info_p->state, 0, 0);
            return MMI_RET_OK;
    }

    comm_p->wait_bearer_info = 0;
    srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
    cntx = srv_email_nwk_get_cntx_list();
    while(cntx)
    {
        state=cbm_get_bearer_status(cntx_p->common.nwk_acct_id);
    	if(cntx->common.acct_id == cntx_p->common.acct_id&&
    	    cntx != cntx_p && state==SRV_CBM_ACTIVATING)//check 
         {
    		srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx);
         }
	cntx = cntx->next;
    }
    return MMI_RET_OK;
}


#ifdef __MMI_SSO__

static void srv_email_nwk_sso_query_done(MMI_BOOL result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_valid = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!is_valid)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_CLOUD_QUERYING)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_CLOUD_QUERYING,
            0);
        return;
    }

    if (!result)
    {
        srv_email_set_error_cause(
            &cntx_p->common.result,
            SRV_EMAIL_MAIL_ERROR,
            SRV_EMAIL_RESULT_AUTH_FAIL,
            NULL);
    }

    srv_email_nwk_fsm(cntx_p);
}


static void srv_email_nwk_sso_refresh_done(S32 req_id, srv_sso_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_valid = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!is_valid)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING ||
        cntx_p->common.sso_req_id != req_id)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_WARNING_NWK_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->common.sso_req_id,
            SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING,
            req_id);
        return;
    }

    if (result != SRV_SSO_OK)
    {
        srv_email_set_error_cause(
            &cntx_p->common.result,
            SRV_EMAIL_MAIL_ERROR,
            SRV_EMAIL_RESULT_AUTH_FAIL,
            NULL);
    }

    srv_email_nwk_fsm(cntx_p);
}

#endif /* __MMI_SSO__ */


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_send
 * DESCRIPTION
 *  This function is used to send the emails.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 *  send_p          [IN]        The pointer point to the send option
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_send(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_send_struct *send_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_smtp_cntx_struct *smtp_cntx_p = (srv_email_smtp_cntx_struct*)cntx_p;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_ASSERT(send_p);

    retval = srv_email_smtp_send(
                smtp_cntx_p,
                send_p,
                srv_email_nwk_fsm_send_done,
                smtp_cntx_p);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_FSM_SEND, cntx_p, retval);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_update
 * DESCRIPTION
 *  This function is used to update the network connection.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 *  fldr_id         [IN]        The folder id
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_update(
                                srv_email_nwk_cntx_struct *cntx_p,
                                EMAIL_FLDR_ID fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_FLDR_ID inbox_id = EMAIL_FLDR_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(
        (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3 ||
         comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4),
        comm_p->protocol,
        0,
        0);

    inbox_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        retval = srv_email_pop3_update(
                    (srv_email_pop3_cntx_struct*)cntx_p,
                    comm_p->retrieve_amount,
                    srv_email_nwk_fsm_update_done,
                    cntx_p);
    }
    else
    {
        if (fldr_id == inbox_id)
        {
            retval = srv_email_nwk_fsm_refresh(cntx_p);
        }
        else
        {
            retval = srv_email_imap4_update(
                        (srv_email_imap4_cntx_struct*)cntx_p,
                        fldr_id,
                        comm_p->retrieve_amount,
                        srv_email_nwk_fsm_update_done,
                        cntx_p);
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_FSM_UPDATE, cntx_p, fldr_id, retval);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_retrieve
 * DESCRIPTION
 *  This function is used to retrieve the specified email.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 *  retr_p          [IN]        The pointer point to the retrieve option
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_retrieve(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_retr_struct *retr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(
        (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3 ||
         comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4),
        comm_p->protocol,
        0,
        0);

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        retval = srv_email_pop3_retrieve(
                    (srv_email_pop3_cntx_struct*)cntx_p,
                    retr_p,
                    srv_email_nwk_fsm_receive_done,
                    cntx_p);
    }
    else
    {
        retval = srv_email_imap4_retrieve(
                    (srv_email_imap4_cntx_struct*)cntx_p,
                    retr_p,
                    srv_email_nwk_fsm_receive_done,
                    cntx_p);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_FSM_RETRIEVE, cntx_p, retval);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_receive
 * DESCRIPTION
 *  This function is used to receive the emails.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 *  recv_p          [IN]        The pointer point to the receive option
 *  fldr_count      [IN]        The number of the folders
 *  fldr_index      [IN]        The index of the current folder
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_receive(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_recv_struct *recv_p,
                                S32 fldr_count,
                                S32 fldr_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(
        (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3 ||
         comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4),
        comm_p->protocol,
        0,
        0);
    
    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        retval = srv_email_pop3_receive(
                    (srv_email_pop3_cntx_struct*)cntx_p,
                    recv_p,
                    comm_p->download_opt,
                    comm_p->download_size,
                    comm_p->retrieve_amount,
                    srv_email_nwk_fsm_receive_done,
                    cntx_p);
    }
    else
    {
        retval = srv_email_imap4_receive(
                    (srv_email_imap4_cntx_struct*)cntx_p,
                    recv_p,
                    fldr_count,
                    fldr_index,
                    comm_p->download_opt,
                    comm_p->download_size,
                    comm_p->retrieve_amount,
                    srv_email_nwk_fsm_receive_done,
                    cntx_p);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_FSM_RECEIVE, cntx_p, retval);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_sync
 * DESCRIPTION
 *  This function is used to sync the specified email.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 *  sync_p          [IN]        The pointer point to the sync option
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_sync(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_sync_struct *sync_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(
        comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4,
        comm_p->protocol,
        0,
        0);

    retval = srv_email_imap4_sync(
                (srv_email_imap4_cntx_struct*)cntx_p,
                sync_p,
                srv_email_nwk_fsm_sync_done,
                cntx_p);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_FSM_SYNC, cntx_p, retval);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_list_folder
 * DESCRIPTION
 *  This function is used to list the remote folders.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 *  list_p          [IN]        The pointer point to the list folder option
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_list_folder(
                                srv_email_nwk_cntx_struct *cntx_p,
                                srv_email_nwk_list_fldr_struct *list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(
        comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4,
        comm_p->protocol,
        0,
        0);

    retval = srv_email_imap4_list_folder(
                (srv_email_imap4_cntx_struct*)cntx_p,
                list_p,
                srv_email_nwk_fsm_list_fldr_done,
                cntx_p);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_FSM_LIST_FOLDER, cntx_p, retval);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_refresh
 * DESCRIPTION
 *  This function is used to refresh the Network connection.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_refresh(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_FLDR_ID fldr_id = EMAIL_FLDR_INVALID_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(
        comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4,
        comm_p->protocol,
        0,
        0);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_FSM_REFRESH,
        cntx_p,
        comm_p->refresh_flag,
        comm_p->refresh_type);

    if (comm_p->refresh_flag)
    {
        retval = srv_email_imap4_refresh(
                    (srv_email_imap4_cntx_struct*)cntx_p,
                    comm_p->retrieve_amount,
                    srv_email_nwk_fsm_refresh_done,
                    cntx_p);

        comm_p->refresh_flag = MMI_FALSE;
        comm_p->refresh_type = 0;
        comm_p->refresh_result = MMI_FALSE;
    }
    else
    {
        fldr_id = srv_email_stor_fldr_get_id_by_type(comm_p->acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

        retval = srv_email_imap4_update(
                    (srv_email_imap4_cntx_struct*)cntx_p,
                    fldr_id,
                    comm_p->retrieve_amount,
                    srv_email_nwk_fsm_update_done,
                    cntx_p);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_FSM_REFRESH, cntx_p, retval);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_init
 * DESCRIPTION
 *  This function is used to initialize the Network FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_init(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    EMAIL_SRV_HANDLE srv_handle = EMAIL_SRV_INVALID_HANDLE;
    EMAIL_ACCT_HANDLE acct_handle = EMAIL_ACCT_INVALID_HANDLE;
    srv_email_acct_info_struct *acct_info_p = NULL;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;
    S32 trc_idx= 0;
#ifdef __MMI_CLOUD_VPP_UPGRADE__
    MMI_BOOL need_upgrade = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_INIT, cntx_p);

#if 1
    EMAILSRV_EXT_ASSERT(
        comm_p->ps_handle == EMAIL_PS_INVALID_HANDLE &&
        comm_p->acct_handle == EMAIL_ACCT_INVALID_HANDLE,
        comm_p->ps_handle,
        comm_p->acct_handle,
        0);
#else
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
#endif

    srv_handle = srv_email_get_int_srv_handle();

    minor = srv_email_acct_create(srv_handle, &acct_handle);
    if (minor != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_acct_error(minor, &major, &minor);
        goto ERROR_HANDLE;
    }
    trc_idx++;

    minor = srv_email_acct_open(acct_handle, comm_p->acct_id);
    if (minor != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_acct_error(minor, &major, &minor);
        goto ERROR_HANDLE;
    }
    trc_idx++;

    acct_info_p = (srv_email_acct_info_struct*)
        srv_email_mem_alloc(sizeof(srv_email_acct_info_struct));
    if (!acct_info_p)
    {
        minor = SRV_EMAIL_RESULT_NO_MEMORY;
        goto ERROR_HANDLE;
    }
    trc_idx++;

    minor = srv_email_acct_read(acct_handle, acct_info_p);
    if (minor != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_acct_error(minor, &major, &minor);
        goto ERROR_HANDLE;
    }

#ifdef __MMI_SSO__
    if (acct_info_p->is_cloud_acct)
    {
        /* Get the cloud provider_id and cloud_acct_id here. */
        srv_sso_provider_struct *sso_prov_p;
        srv_sso_account_struct *sso_acct_p;
        WCHAR *sso_acct_name_ws;
        U8 sso_prov_num;
        U8 sso_acct_num;
        U8 i;
        U8 j;
        MMI_BOOL is_valid;

        sso_prov_p = (srv_sso_provider_struct*)
            OslMalloc(sizeof(srv_sso_provider_struct) * SRV_SSO_PROVIDER_MAX);
        sso_acct_p = (srv_sso_account_struct*)
            OslMalloc(sizeof(srv_sso_account_struct) * SRV_SSO_ACCOUNTS_PER_PROVIDER);
        sso_acct_name_ws = (WCHAR*)OslMalloc(sizeof(WCHAR) * (SRV_SSO_NAME_SIZE + 1));

        sso_prov_num = srv_sso_get_providers(sso_prov_p, SRV_SSO_PROVIDER_MAX);
        for (i = 0; i < sso_prov_num; i++)
        {
            is_valid = srv_email_sso_is_provider_valid(sso_prov_p[i].provider);
            if (is_valid)
            {
                if (sso_prov_p[i].accounts_total)
                {
                    sso_acct_num = srv_sso_get_accounts(
                                    sso_prov_p[i].provider,
                                    SRV_SSO_LOGIN_DONT_CARE,
                                    sso_acct_p,
                                    SRV_SSO_ACCOUNTS_PER_PROVIDER);

                    for (j = 0; j < sso_acct_num; j++)
                    {
                        srv_sso_get_account_name(
                            sso_acct_p[j].provider,
                            sso_acct_p[j].account,
                            sso_acct_name_ws);

                        if (mmi_wcsicmp(sso_acct_name_ws, acct_info_p->email_addr.email_addr) == 0)
                        {
                            comm_p->provider_id = sso_acct_p[j].provider;
                            comm_p->cloud_acct_id = sso_acct_p[j].account;
                            break;
                        }
                    }

                    if (j < sso_acct_num)
                    {
                        break;
                    }
                }
            }
        }

        OslMfree(sso_prov_p);
        OslMfree(sso_acct_p);
        OslMfree(sso_acct_name_ws);
    }
    else
    {
        comm_p->provider_id = 0;
        comm_p->cloud_acct_id = SRV_SSO_INVALID_ACC_ID;
    }

    if (comm_p->cloud_acct_id != SRV_SSO_INVALID_ACC_ID)
    {
        MMI_BOOL is_valid;
        srv_email_server_struct *server_p;
        srv_email_auth_struct *auth_p;

        if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP)
        {
            server_p = &acct_info_p->out_server;
            auth_p = &acct_info_p->out_auth;
        }
        else
        {
            server_p = &acct_info_p->in_server;
            auth_p = &acct_info_p->in_auth;
        }

    #ifdef __MMI_CLOUD_VPP_UPGRADE__
        minor = srv_email_nwk_upgrade_cloud_plugin(comm_p->provider_id);
        if (minor == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            need_upgrade = MMI_TRUE;
        }
        else
    #endif /* __MMI_CLOUD_VPP_UPGRADE__ */
        {
            is_valid = srv_email_nwk_query_cloud_server_info(
                        comm_p->provider_id,
                        comm_p->protocol,
                        server_p);
            if (!is_valid)
            {
                minor = SRV_EMAIL_RESULT_SERVER_ERROR;
                goto ERROR_HANDLE;
            }
        }

        if (auth_p->auth_type == SRV_EMAIL_AUTH_NONE)
        {
            auth_p->auth_type = SRV_EMAIL_AUTH_USER;
        }
    }
#endif /* __MMI_SSO__ */

    mmi_ucs2_to_asc(comm_p->from_addr, (CHAR*)acct_info_p->email_addr.email_addr);

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP)
    {
        memcpy(&comm_p->server_addr, &acct_info_p->out_server, sizeof(srv_email_server_struct));
        memcpy(&comm_p->auth, &acct_info_p->out_auth, sizeof(srv_email_auth_struct));
    }
    else
    {
        memcpy(&comm_p->server_addr, &acct_info_p->in_server, sizeof(srv_email_server_struct));
        memcpy(&comm_p->auth, &acct_info_p->in_auth, sizeof(srv_email_auth_struct));
        comm_p->download_opt = acct_info_p->download_option;
        comm_p->download_size = acct_info_p->download_size;
        comm_p->retrieve_amount = acct_info_p->retrieve_amount;
    }

    srv_email_mem_free(acct_info_p);
    acct_info_p = NULL;

    comm_p->acct_handle = acct_handle;
    
#ifdef __MMI_CLOUD_VPP_UPGRADE__
    if (need_upgrade)
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CLOUD_UPGRADING);
    }
    else
#endif /* __MMI_CLOUD_VPP_UPGRADE__ */
    {
        srv_email_compute_acct_digest(
            comm_p->server_addr.server_name,
            comm_p->auth.username,
            comm_p->acct_digest);

        srv_email_ps_create_instance_req((U32)cntx_p, comm_p->protocol);
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATING);
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;

ERROR_HANDLE:

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_FSM_INIT, cntx_p, trc_idx, major, minor);

    if (acct_info_p)
    {
        srv_email_mem_free(acct_info_p);
    }

    if (acct_handle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acct_handle);
    }

    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_created
 * DESCRIPTION
 *  This function is used to process the case that creating PS instance successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_created(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    srv_cbm_result_error_enum ret = SRV_CBM_OK;
    MMI_BOOL is_incoming = MMI_TRUE;
    U8 app_id = CBM_INVALID_APP_ID;
    U8 temp_app_id = CBM_INVALID_APP_ID;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;
    S32 trc_idx = 0;
    kal_int32 state = 0;
    srv_email_nwk_cntx_struct *cntx;
    U32 dtcnt_id;
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_FSM_CREATED,
        cntx_p,
        comm_p->destroy_flag,
        comm_p->abort_flag);

    if (comm_p->destroy_flag)
    {
        // TODO: what should be done here?
        comm_p->destroy_flag = MMI_FALSE;
        return SRV_EMAIL_RESULT_FAIL;
    }

    if (comm_p->abort_flag)
    {
        comm_p->abort_flag = MMI_FALSE;
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP)
    {
        is_incoming = MMI_FALSE;
    }

    srv_dtcnt_get_sim_preference(&sim_type);

#ifdef __MMI_SSO__
    if (comm_p->cloud_acct_id != SRV_SSO_INVALID_ACC_ID)
    {
        MMI_BOOL is_valid;
        cbm_sim_id_enum sim_id = CBM_SIM_ID_SIM1;

        if (sim_type != SRV_DTCNT_SIM_TYPE_NONE)
        {
            sim_id = (cbm_sim_id_enum)(sim_type - SRV_DTCNT_SIM_TYPE_1);
        }

        is_valid = srv_email_nwk_query_cloud_dtcnt_id(comm_p->provider_id, &dtcnt_id);
        if (!is_valid)
        {
            dtcnt_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, sim_id, 0, MMI_FALSE);
        }
    }
    else
#endif /* __MMI_SSO__ */
    {
        if (sim_type != SRV_DTCNT_SIM_TYPE_NONE)
        {
            dtcnt_id = comm_p->server_addr.data_acct[sim_type - SRV_DTCNT_SIM_TYPE_1];
        }
        else
        {
            dtcnt_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, 0, MMI_FALSE);
        }
    }

    app_id = srv_email_nwk_get_cbm_app_id(
                comm_p->acct_id,
                is_incoming,
                dtcnt_id,
                cntx_p);
    if (app_id == CBM_INVALID_APP_ID)
    {
        minor = SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL;
        goto EXIT_HANDLE;
    }
    trc_idx++;

    comm_p->nwk_acct_id = cbm_set_app_id(dtcnt_id, app_id);
    state = cbm_get_bearer_status(comm_p->nwk_acct_id);
	if (state == CBM_ACTIVATED || state == CBM_ACTIVATING)
	{
		if (state == CBM_ACTIVATED)
		{
			retval = SRV_EMAIL_RESULT_SUCC;
		}	
		else
		{
			comm_p->nwk_acct_id = cbm_set_app_id(dtcnt_id, app_id);
			retval = SRV_EMAIL_RESULT_WOULDBLOCK;
		}
		goto EXIT_HANDLE;
	}

    ret = srv_cbm_register_bearer_info(
            app_id,
            SRV_CBM_ACTIVATING | SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
            SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
            srv_email_nwk_fsm_bearer_info_ind,
            cntx_p);
    if (ret != SRV_CBM_OK)
    {
        minor = SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL;
        goto EXIT_HANDLE;
    }
    trc_idx++;

    retval = srv_email_nwk_activate_bearer(comm_p->nwk_acct_id, &major, &minor);

EXIT_HANDLE:

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATING);
    }
    else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        comm_p->wait_bearer_info = SRV_CBM_ACTIVATING | SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED;

        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATING);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_FSM_CREATED, cntx_p, trc_idx, major, minor);

        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATING);

        if (app_id != CBM_INVALID_APP_ID)
        {
            cntx = srv_email_nwk_get_cntx_list();
            while (cntx)
            {
                temp_app_id = cbm_get_app_id(cntx->common.nwk_acct_id);
                if (cntx != cntx_p && temp_app_id == app_id)
                {
                    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
                    return retval; 
                }
                cntx = cntx->next;
            }
            srv_cbm_deregister_bearer_info(app_id);
            srv_cbm_deregister_bearer_event(app_id);
            cbm_deregister_app_id(app_id);
        }

        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_activated
 * DESCRIPTION
 *  This function is used to process the case that activating bearer successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_activated(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    U32 len = sizeof(WCHAR) * (SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1);
    WCHAR *filename = NULL;
    MMI_BOOL is_file_needed = MMI_FALSE;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_WOULDBLOCK;
    S32 errcode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_ACTIVATED, cntx_p, comm_p->abort_flag);

    if (comm_p->abort_flag)
    {
        comm_p->abort_flag = MMI_FALSE;
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

#ifdef __MMI_SSO__
    if (comm_p->cloud_acct_id != SRV_SSO_INVALID_ACC_ID)
    {
        srv_sso_account_struct sso_acct;
        MMI_BOOL is_valid;

        is_valid = srv_sso_get_account(comm_p->provider_id, comm_p->cloud_acct_id, &sso_acct);
        if (!is_valid)
        {
            srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_MAIL_ERROR, SRV_EMAIL_RESULT_INVALID_ACCT, NULL);
            return SRV_EMAIL_RESULT_FAIL;
        }

        if (!sso_acct.is_login)
        {
            srv_email_evt_cloud_ind_struct evt;

            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_EMAIL_CLOUD_IND);
            evt.provider_id = comm_p->provider_id;
            evt.cloud_acct_id = comm_p->cloud_acct_id;
            evt.type = SRV_EMAIL_CLOUD_NOT_LOGIN;
            evt.callback = srv_email_nwk_sso_query_done;
            evt.user_data = cntx_p;
            MMI_FRM_CB_EMIT_POST_EVENT(&evt);

            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CLOUD_QUERYING);
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
    }
#endif /* __MMI_SSO__ */

    filename = (WCHAR*)OslMalloc(len);

    kal_wsprintf(
        filename,
        "%s%sReq%08X.dat",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        cntx_p);

#ifdef __MMI_SSO__
    is_file_needed = srv_email_nwk_make_conn_req_file(
                        comm_p->cloud_acct_id != SRV_SSO_INVALID_ACC_ID ? comm_p->provider_id : 0,
                        (const CHAR*)comm_p->from_addr,
                        comm_p->protocol,
                        comm_p->cloud_acct_id != SRV_SSO_INVALID_ACC_ID ? NULL : &comm_p->server_addr,
                        filename,
                        &errcode);
#else /* __MMI_SSO__ */
    is_file_needed = srv_email_nwk_make_conn_req_file(
                        0,
                        (const CHAR*)comm_p->from_addr,
                        comm_p->protocol,
                        &comm_p->server_addr,
                        filename,
                        &errcode);
#endif /* __MMI_SSO__ */

    if (is_file_needed)
    {
        if (errcode)
        {
            srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_FS_ERROR, errcode, NULL);
            retval = SRV_EMAIL_RESULT_FAIL;
        }
        else
        {
            srv_email_ps_connect_req(comm_p->ps_handle, comm_p->nwk_acct_id, &comm_p->server_addr, filename, NULL);
        }
    }
    else
    {
        srv_email_ps_connect_req(comm_p->ps_handle, comm_p->nwk_acct_id, &comm_p->server_addr, NULL, NULL);
    }

    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CONNECTING);
    srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_CONNECTING, NULL);

    OslMfree(filename);

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_connected
 * DESCRIPTION
 *  This function is used to process the case that connecting server successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_connected(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_FSM_CONNECTED,
        cntx_p,
        comm_p->protocol,
        comm_p->auth.auth_type);

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP)
    {
        if (comm_p->auth.auth_type == SRV_EMAIL_AUTH_NONE)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);
            return SRV_EMAIL_RESULT_SUCC;
        }
    }

#ifdef __MMI_SSO__
    if (comm_p->cloud_acct_id != SRV_SSO_INVALID_ACC_ID)
    {
        srv_email_sso_auth_struct sso_auth;
        srv_sso_account_struct sso_acct;
        MMI_BOOL is_valid;

        is_valid = srv_sso_get_account(comm_p->provider_id, comm_p->cloud_acct_id, &sso_acct);
        if (!is_valid)
        {
            srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_MAIL_ERROR, SRV_EMAIL_RESULT_INVALID_ACCT, NULL);
            return SRV_EMAIL_RESULT_FAIL;
        }

        if (!sso_acct.is_login)
        {
            srv_email_ps_disconnect_req(comm_p->ps_handle);
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
            return SRV_EMAIL_RESULT_SUCC;
        }

        sso_auth.provider_id = comm_p->provider_id;
        sso_auth.cloud_acct_id = comm_p->cloud_acct_id;
        sso_auth.ps_handle = comm_p->ps_handle;
        sso_auth.capa_mask = comm_p->capa_mask;
        sso_auth.from_addr_p = comm_p->from_addr;
        sso_auth.username_p = comm_p->auth.username;
        sso_auth.password_p = comm_p->auth.password;

        srv_email_sso_send_auth_req(&sso_auth);
    }
    else
#endif /* __MMI_SSO__ */
    {
        srv_email_ps_auth_req(comm_p->ps_handle, comm_p->capa_mask, &comm_p->auth);
    }

    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_AUTHORIZING);
    srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_AUTHORIZING, NULL);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_authorized
 * DESCRIPTION
 *  This function is used to process the case that authorizing successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_authorized(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_FSM_AUTHORIZED,
        cntx_p,
        comm_p->reauth_flag,
        comm_p->protocol);

    cb_p = srv_email_nwk_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    if (comm_p->reauth_flag)
    {
        srv_email_querying_data_struct *query_data_p = NULL;

        comm_p->reauth_flag = MMI_FALSE;

        query_data_p = (srv_email_querying_data_struct*)
            OslMalloc(sizeof(srv_email_querying_data_struct));

        mmi_ucs2cpy((CHAR*)query_data_p->username, (const CHAR*)comm_p->auth.username);
        mmi_ucs2cpy((CHAR*)query_data_p->password, (const CHAR*)comm_p->auth.password);
        query_data_p->callback = srv_email_nwk_fsm_query_done;
        query_data_p->user_data = cntx_p;

        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_QUERYING);
        srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_QUERYING, query_data_p);

        OslMfree(query_data_p);

        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        srv_email_pop3_cntx_struct *pop3_p = (srv_email_pop3_cntx_struct*)cntx_p;

        pop3_p->session.sync_with_server = MMI_FALSE;
    }
    else if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
    {
        srv_email_imap4_cntx_struct *imap4_p = (srv_email_imap4_cntx_struct*)cntx_p;

        imap4_p->session.fldr_id = EMAIL_FLDR_INVALID_ID;
        imap4_p->session.sync_with_server = MMI_FALSE;
    }

    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP ||
        cb_p->action == SRV_EMAIL_NWK_LIST_FOLDER ||
        cb_p->action == SRV_EMAIL_NWK_TEST_NWK)
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[0]);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
        }
        else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
            srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_UPDATING, NULL);
        }

        return retval;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_queried
 * DESCRIPTION
 *  This function is used to process the case that querying successfully
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_queried(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_QUERIED, cntx_p);

    srv_email_ps_auth_req(comm_p->ps_handle, comm_p->capa_mask, &comm_p->auth);
    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_AUTHORIZING);
    srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_AUTHORIZING, NULL);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_ready
 * DESCRIPTION
 *  This function is used to process the ready state.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context     
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_ready(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_p = srv_email_nwk_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_READY, cntx_p, cb_p->action);

    switch (cb_p->action)
    {
        case SRV_EMAIL_NWK_CONNECT:
            if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP)
            {
                cb_p->state |= SRV_EMAIL_NWK_CB_CONNECTED;
                cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
                if (cb_p)
                {
                    srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
                }

                return SRV_EMAIL_RESULT_WOULDBLOCK;
            }
            else
            {
                retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[0]);
                if (retval == SRV_EMAIL_RESULT_SUCC)
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
                }
                else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
                    srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_UPDATING, NULL);
                }

                return retval;
            }

        case SRV_EMAIL_NWK_SEND:
            retval = srv_email_nwk_fsm_send(cntx_p, (srv_email_nwk_send_struct*)cb_p->action_data);
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_SENDING);
            return retval;

        case SRV_EMAIL_NWK_RETRIEVE:
        case SRV_EMAIL_NWK_RECEIVE:
        case SRV_EMAIL_NWK_SYNC:
            retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[cb_p->fldr_index]);
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
            }
            else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_UPDATING, NULL);
            }
            return retval;

        case SRV_EMAIL_NWK_LIST_FOLDER:
            retval = srv_email_nwk_fsm_list_folder(cntx_p, (srv_email_nwk_list_fldr_struct*)cb_p->action_data);
            cntx_p->prev_state = cntx_p->nwk_state;
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_LISTING_FOLDER);
            if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_LISTING_FOLDER, NULL);
            }
            return retval;

        case SRV_EMAIL_NWK_REFRESH:
            retval = srv_email_nwk_fsm_refresh(cntx_p);
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
            }
            else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_UPDATING, NULL);
            }
            return retval;

        case SRV_EMAIL_NWK_DISCONNECT:
            ret = srv_email_nwk_is_pending_cb_empty(cntx_p);
            if (!ret)
            {
                cb_p->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;
                srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
                srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
            }
            else
            {
                srv_email_ps_disconnect_req(comm_p->ps_handle);
                SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_DISCONNECTING);
                srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_DISCONNECTING, NULL);
            }
            return SRV_EMAIL_RESULT_WOULDBLOCK;

        case SRV_EMAIL_NWK_TEST_NWK:
            cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
            if (cb_p)
            {
                srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
            }
            return SRV_EMAIL_RESULT_WOULDBLOCK;

        default:
            EMAILSRV_EXT_ASSERT(0, cb_p->action, 0, 0);
            break;
    }

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_updated
 * DESCRIPTION
 *  This function is used to process the case that updating successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_updated(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_nwk_recv_struct *recv_p = NULL;
    srv_email_nwk_sync_struct *sync_p = NULL;
    srv_email_nwk_refresh_struct *refresh_p = NULL;
    srv_email_nwk_recv_struct recv_opt;
    srv_email_nwk_sync_struct sync_opt;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_p = srv_email_nwk_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_UPDATED, cntx_p, cb_p->action);

    switch (cb_p->action)
    {
        case SRV_EMAIL_NWK_CONNECT:
            EMAILSRV_EXT_ASSERT(
                (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3 ||
                 comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4),
                comm_p->protocol,
                0,
                0);

            ret = srv_email_nwk_is_sync_cb(cntx_p, cb_p);
            if (ret)
            {
                retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[0]);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                    {
                        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
                    }
                    return retval;
                }
            }
            else
            {
                if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
                {
                    sync_opt.all_fldr = MMI_FALSE;
                    sync_opt.fldr_id = cb_p->fldr_id[0];
                    sync_opt.all_msg = MMI_TRUE;
                    sync_opt.msg_id = EMAIL_MSG_INVALID_ID;

                    retval = srv_email_nwk_fsm_sync(cntx_p, &sync_opt);
                    if (retval != SRV_EMAIL_RESULT_SUCC)
                    {
                        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_SYNCING);
                        return retval;
                    }
                }

                cb_p->state |= SRV_EMAIL_NWK_CB_CONNECTED;
            }

            cb_p = srv_email_nwk_update_running_cb(cntx_p, (ret ? MMI_FALSE : MMI_TRUE));
            if (cb_p)
            {
                srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
            }

            return SRV_EMAIL_RESULT_WOULDBLOCK;

        case SRV_EMAIL_NWK_RETRIEVE:
            if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
            {
                retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[0]);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                    {
                        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
                    }
                    return retval;
                }

                sync_opt.all_fldr = MMI_FALSE;
                sync_opt.fldr_id = cb_p->fldr_id[0];
                sync_opt.all_msg = MMI_TRUE;
                sync_opt.msg_id = EMAIL_MSG_INVALID_ID;

                retval = srv_email_nwk_fsm_sync(cntx_p, &sync_opt);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_SYNCING);
                    return retval;
                }
            }

            retval = srv_email_nwk_fsm_retrieve(cntx_p, (srv_email_nwk_retr_struct*)cb_p->action_data);
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_RECEIVING);
            return retval;

        case SRV_EMAIL_NWK_RECEIVE:
            if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4)
            {
                retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[cb_p->fldr_index]);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                    {
                        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
                    }
                    return retval;
                }

                sync_opt.all_fldr = MMI_FALSE;
                sync_opt.fldr_id = cb_p->fldr_id[cb_p->fldr_index];
                sync_opt.all_msg = MMI_TRUE;
                sync_opt.msg_id = EMAIL_MSG_INVALID_ID;

                retval = srv_email_nwk_fsm_sync(cntx_p, &sync_opt);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_SYNCING);
                    return retval;
                }
            }

            recv_p = (srv_email_nwk_recv_struct*)cb_p->action_data;

            recv_opt.all_fldr = MMI_FALSE;
            recv_opt.fldr_id = cb_p->fldr_id[cb_p->fldr_index];
            recv_opt.recv_opt = recv_p->recv_opt;

            retval = srv_email_nwk_fsm_receive(
                        cntx_p,
                        &recv_opt,
                        cb_p->fldr_count,
                        cb_p->fldr_index + 1);
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_RECEIVING);
            return retval;

        case SRV_EMAIL_NWK_SYNC:
            retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[cb_p->fldr_index]);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
                }
                return retval;
            }

            sync_p = (srv_email_nwk_sync_struct*)cb_p->action_data;

            sync_opt.all_fldr = MMI_FALSE;
            sync_opt.fldr_id = cb_p->fldr_id[cb_p->fldr_index];
            sync_opt.all_msg = sync_p->all_msg;
            sync_opt.msg_id = sync_p->msg_id;

            retval = srv_email_nwk_fsm_sync(cntx_p, &sync_opt);
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_SYNCING);
            return retval;

        case SRV_EMAIL_NWK_LIST_FOLDER:
            retval = srv_email_nwk_fsm_list_folder(cntx_p, (srv_email_nwk_list_fldr_struct*)cb_p->action_data);
            cntx_p->prev_state = cntx_p->nwk_state;
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_LISTING_FOLDER);
            if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_LISTING_FOLDER, NULL);
            }
            return retval;

        case SRV_EMAIL_NWK_REFRESH:
            retval = srv_email_nwk_fsm_refresh(cntx_p);
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                sync_opt.all_fldr = MMI_FALSE;
                sync_opt.fldr_id = cb_p->fldr_id[0];
                sync_opt.all_msg = MMI_TRUE;
                sync_opt.msg_id = EMAIL_MSG_INVALID_ID;

                retval = srv_email_nwk_fsm_sync(cntx_p, &sync_opt);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_SYNCING);
                    return retval;
                }

                refresh_p = (srv_email_nwk_refresh_struct*)cb_p->action_data;

                recv_opt.all_fldr = MMI_FALSE;
                recv_opt.fldr_id = cb_p->fldr_id[0];
                recv_opt.recv_opt = refresh_p->recv_opt;

                retval = srv_email_nwk_fsm_receive(cntx_p, &recv_opt, 1, 1);
                SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_RECEIVING);
                return retval;
            }
            else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_UPDATING, NULL);
            }
            return retval;

        case SRV_EMAIL_NWK_DISCONNECT:
            ret = srv_email_nwk_is_pending_cb_empty(cntx_p);
            if (!ret)
            {
                cb_p->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;
                srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
                srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
            }
            else
            {
                if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
                {
                    retval = srv_email_pop3_disconnect(
                                (srv_email_pop3_cntx_struct*)cntx_p,
                                srv_email_nwk_fsm_disconnect_done,
                                cntx_p);

                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_DISCONNECTING);
                    srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_DISCONNECTING, NULL);
                    return SRV_EMAIL_RESULT_WOULDBLOCK;
                }
                else
                {
                    srv_email_imap4_cntx_free((srv_email_imap4_cntx_struct*)cntx_p);
                }

                srv_email_ps_disconnect_req(comm_p->ps_handle);
                SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_DISCONNECTING);
                srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_DISCONNECTING, NULL);
            }
            return SRV_EMAIL_RESULT_WOULDBLOCK;

        case SRV_EMAIL_NWK_TEST_NWK:
            cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
            if (cb_p)
            {
                srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
            }
            return SRV_EMAIL_RESULT_WOULDBLOCK;

        default:
            EMAILSRV_EXT_ASSERT(0, cb_p->action, 0, 0);
            break;
    }

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_sent
 * DESCRIPTION
 *  This function is used to process the case that sending successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_sent(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_SENT, cntx_p);

    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);

    cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
    if (cb_p)
    {
        srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_received
 * DESCRIPTION
 *  This function is used to process the case that receiving successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_received(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_p = srv_email_nwk_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_FSM_RECEIVED,
        cntx_p,
        cb_p->fldr_index,
        cb_p->fldr_count);

    cb_p->fldr_index++;

    if (cb_p->fldr_index < cb_p->fldr_count)
    {
        retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[cb_p->fldr_index]);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
        }
        else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
            srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_UPDATING, NULL);
        }
        return retval;
    }
    else
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);

        cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
        if (cb_p)
        {
            srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
        }

        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_synced
 * DESCRIPTION
 *  This function is used to process the case that syncing successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_synced(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_p = srv_email_nwk_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_FSM_SYNCED,
        cntx_p,
        cb_p->action,
        cb_p->fldr_index,
        cb_p->fldr_count);

    if (cb_p->action == SRV_EMAIL_NWK_CONNECT ||
        cb_p->action == SRV_EMAIL_NWK_RETRIEVE ||
        cb_p->action == SRV_EMAIL_NWK_RECEIVE ||
        cb_p->action == SRV_EMAIL_NWK_REFRESH)
    {
        retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[cb_p->fldr_index]);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
        }
        else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
        }

        return retval;
    }

    cb_p->fldr_index++;

    if (cb_p->fldr_index < cb_p->fldr_count)
    {
        retval = srv_email_nwk_fsm_update(cntx_p, cb_p->fldr_id[cb_p->fldr_index]);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
        }
        else if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
        }
        return retval;
    }
    else
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);

        cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
        if (cb_p)
        {
            srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
        }

        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_folder_listed
 * DESCRIPTION
 *  This function is used to process the case that listing remote folder successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_folder_listed(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_FOLDER_LISTED, cntx_p, cntx_p->prev_state);

    SRV_EMAIL_NWK_SET_STATE(cntx_p, cntx_p->prev_state);
    cntx_p->prev_state = SRV_EMAIL_NWK_STATE_INIT;

    cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
    if (cb_p)
    {
        srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_disconnected
 * DESCRIPTION
 *  This function is used to process the case that disconnecting successfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_disconnected(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_DISCONNECTED, cntx_p);

    cb_p = srv_email_nwk_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    cb_p->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;

    cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
    if (cb_p)
    {
        srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
    }

    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_init_fail
 * DESCRIPTION
 *  This function is used to process the case that initializing unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_init_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Back to INIT state */
    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_INIT);

    /* Finish all related network operations */
    cb_p = srv_email_nwk_get_running_cb(cntx_p);

    while (cb_p)
    {
        cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_create_fail
 * DESCRIPTION
 *  This function is used to process the case that creating PS handle unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_create_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Back to INIT state */
    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_INIT);

    /* Finish all related network operations */
    cb_p = srv_email_nwk_get_running_cb(cntx_p);

    while (cb_p)
    {
        cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_activate_fail
 * DESCRIPTION
 *  This function is used to process the case that activating bearer unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_activate_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Back to CREATED state */
    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);

    /* Finish all related network operations */
    cb_p = srv_email_nwk_get_running_cb(cntx_p);

    while (cb_p)
    {
        cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_connect_fail
 * DESCRIPTION
 *  This function is used to process the case that connecting unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_connect_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SSO__
    if (comm_p->cloud_acct_id != SRV_SSO_INVALID_ACC_ID &&
        cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_AUTHORIZING)
    {
        if (comm_p->result.major == SRV_EMAIL_MAIL_ERROR &&
            comm_p->result.minor == SRV_EMAIL_RESULT_INVALID_AUTH_COOKIE)
        {
            srv_email_ps_disconnect_req(comm_p->ps_handle);

            comm_p->sso_req_id = srv_sso_refresh_credentials(
                                    comm_p->provider_id,
                                    comm_p->cloud_acct_id,
                                    srv_email_nwk_sso_refresh_done,
                                    cntx_p);

            memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
            comm_p->result.result = MMI_TRUE;

            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING);
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
    }
#endif /* __MMI_SSO__ */

    ret = srv_email_nwk_is_bearer_activated(comm_p->nwk_acct_id);
    if (ret)
    {
    #ifdef __MMI_SSO__
        if (cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING)
        {
            srv_email_evt_cloud_ind_struct evt;

            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_EMAIL_CLOUD_IND);
            evt.provider_id = comm_p->provider_id;
            evt.cloud_acct_id = comm_p->cloud_acct_id;
            evt.type = SRV_EMAIL_CLOUD_COOKIE_EXPIRY;
            evt.callback = srv_email_nwk_sso_query_done;
            evt.user_data = cntx_p;
            MMI_FRM_CB_EMIT_POST_EVENT(&evt);

            memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
            comm_p->result.result = MMI_TRUE;

            SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CLOUD_QUERYING);
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
    #endif /* __MMI_SSO__ */

        /* Back to ACTIVATED state */
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
    }
    else
    {
        /* Back to CREATED state */
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
    }

    /* Finish all related network operations */
    cb_p = srv_email_nwk_get_running_cb(cntx_p);

    while (cb_p)
    {
        cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
    }

    memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
    comm_p->result.result = MMI_TRUE;

    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_update_fail
 * DESCRIPTION
 *  This function is used to process the case that updating unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_update_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_struct *result_p = &comm_p->result;
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result_p->major == SRV_EMAIL_MAIL_ERROR &&
        result_p->minor == SRV_EMAIL_RESULT_SELECT_FOLDER_ERROR)
    {
        cb_p = srv_email_nwk_get_running_cb(cntx_p);
        EMAILSRV_ASSERT(cb_p);

        if (cb_p->action == SRV_EMAIL_NWK_RECEIVE ||
            cb_p->action == SRV_EMAIL_NWK_SYNC)
        {
            if (cb_p->fldr_count > 1)
            {
                result_p->result = MMI_TRUE;
                cb_p->fldr_index++;
                if (cb_p->fldr_index < cb_p->fldr_count)
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);
                    return;
                }
            }
        }
    }

    /* Back to READY state */
    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);

    srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_send_fail
 * DESCRIPTION
 *  This function is used to process the case that sending unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_send_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Back to READY state */
    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);

    srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_recv_fail
 * DESCRIPTION
 *  This function is used to process the case that receiving unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_recv_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Back to UPDATED state */
    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);

    srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_sync_fail
 * DESCRIPTION
 *  This function is used to process the case that syncing unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_sync_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Back to UPDATED state */
    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);

    srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_list_rf_fail
 * DESCRIPTION
 *  This function is used to process the case that listing the remote folder unsuccessfully.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_list_rf_fail(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Back to previous state */
    SRV_EMAIL_NWK_SET_STATE(cntx_p, cntx_p->prev_state);
    cntx_p->prev_state = SRV_EMAIL_NWK_STATE_INIT;

    srv_email_nwk_update_running_cb(cntx_p, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_err_rsp
 * DESCRIPTION
 *  This function is used to process the error cases.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_err_rsp(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_FSM_ERROR,
        cntx_p,
        cntx_p->nwk_state,
        comm_p->result.major,
        comm_p->result.minor);

    switch (cntx_p->nwk_state)
    {
    #ifdef __MMI_CLOUD_VPP_UPGRADE__
        case SRV_EMAIL_NWK_STATE_CLOUD_UPGRADING:
    #endif
        case SRV_EMAIL_NWK_STATE_INIT:
            srv_email_nwk_fsm_init_fail(cntx_p);
            break;

        case SRV_EMAIL_NWK_STATE_CREATING:
        case SRV_EMAIL_NWK_STATE_CREATED:
            srv_email_nwk_fsm_create_fail(cntx_p);
            break;

        case SRV_EMAIL_NWK_STATE_ACTIVATING:
        case SRV_EMAIL_NWK_STATE_ACTIVATED:
            srv_email_nwk_fsm_activate_fail(cntx_p);
            break;

        case SRV_EMAIL_NWK_STATE_CONNECTING:
        case SRV_EMAIL_NWK_STATE_AUTHORIZING:
        case SRV_EMAIL_NWK_STATE_QUERYING:
        case SRV_EMAIL_NWK_STATE_READY:
    #ifdef __MMI_SSO__
        case SRV_EMAIL_NWK_STATE_CLOUD_QUERYING:
        case SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING:
    #endif /* __MMI_SSO__ */
            retval = srv_email_nwk_fsm_connect_fail(cntx_p);
            return retval;

        case SRV_EMAIL_NWK_STATE_UPDATING:
            srv_email_nwk_fsm_update_fail(cntx_p);
            break;

        case SRV_EMAIL_NWK_STATE_UPDATED:
            break;

        case SRV_EMAIL_NWK_STATE_SENDING:
            srv_email_nwk_fsm_send_fail(cntx_p);
            break;

        case SRV_EMAIL_NWK_STATE_RECEIVING:
            srv_email_nwk_fsm_recv_fail(cntx_p);
            break;

        case SRV_EMAIL_NWK_STATE_SYNCING:
            srv_email_nwk_fsm_sync_fail(cntx_p);
            break;

        case SRV_EMAIL_NWK_STATE_LISTING_FOLDER:
            srv_email_nwk_fsm_list_rf_fail(cntx_p);
            break;

        case SRV_EMAIL_NWK_STATE_DISCONNECTING:
            break;

        default:
            break;
    }

    cb_p = srv_email_nwk_get_running_cb(cntx_p);
    if (cb_p)
    {
        srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
    }

    memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
    comm_p->result.result = MMI_TRUE;

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_query_done
 * DESCRIPTION
 *  This function is used to process the result of querying username/password.
 * PARAMETERS
 *  result          [IN]        The result of querying
 *  username        [IN]        The pointer point to the new username
 *  password        [IN]        The pointer point to the new password
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  The error code.
 *****************************************************************************/
static srv_email_result_enum srv_email_nwk_fsm_query_done(
                                MMI_BOOL result,
                                const WCHAR *username,
                                const WCHAR *password,
                                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    srv_email_comm_cntx_struct *comm_p = NULL;
    MMI_BOOL ret = MMI_FALSE;
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_QUERY_DONE);

    if (!username)
    {
        return SRV_EMAIL_RESULT_INVALID_USERNAME;
    }
    else
    {
        len = mmi_ucs2strlen((const CHAR*)username);
        if (len > SRV_EMAIL_MAX_USERNAME_LEN)
        {
            return SRV_EMAIL_RESULT_INVALID_USERNAME;
        }
    }

    if (!password)
    {
        return SRV_EMAIL_RESULT_INVALID_PASSWORD;
    }
    else
    {
        len = mmi_ucs2strlen((const CHAR*)password);
        if (len > SRV_EMAIL_MAX_PASSWORD_LEN)
        {
            return SRV_EMAIL_RESULT_INVALID_PASSWORD;
        }
    }

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_QUERYING)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    comm_p = &cntx_p->common;

    if (result)
    {
        memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
        comm_p->result.result = MMI_TRUE;

        mmi_ucs2cpy((CHAR*)comm_p->auth.username, (const CHAR*)username);
        mmi_ucs2cpy((CHAR*)comm_p->auth.password, (const CHAR*)password);
    }
    else
    {
        comm_p->result.result = MMI_FALSE;
    }

    srv_email_nwk_fsm(cntx_p);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_send_done
 * DESCRIPTION
 *  This function is used to process the result of sending.
 * PARAMETERS
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_send_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_SEND_DONE);

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING)
    {
        return;
    }

    srv_email_nwk_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_update_done
 * DESCRIPTION
 *  This function is used to process the result of updating connection.
 * PARAMETERS
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_update_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_UPDATE_DONE);

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING)
    {
        //trace: error state
        return;
    }

    srv_email_nwk_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_receive_done
 * DESCRIPTION
 *  This function is used to process the result of receiving/retrieving.
 * PARAMETERS
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_receive_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_RECEIVE_DONE);

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING)
    {
        //trace: error state
        return;
    }

    srv_email_nwk_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_sync_done
 * DESCRIPTION
 *  This function is used to process the result of syncing.
 * PARAMETERS
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_sync_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_SYNC_DONE);

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SYNCING)
    {
        //trace: error state
        return;
    }

    srv_email_nwk_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_list_fldr_done
 * DESCRIPTION
 *  This function is used to process the result of listing remote folder.
 * PARAMETERS
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_list_fldr_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_LIST_FOLDER_DONE);

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_LISTING_FOLDER)
    {
        //trace: error state
        return;
    }

    srv_email_nwk_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_disconnect_done
 * DESCRIPTION
 *  This function is used to process the result of disconnecting.
 * PARAMETERS
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_disconnect_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_DISCONNECT_DONE);

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_DISCONNECTING)
    {
        //trace: error state
        return;
    }

    srv_email_nwk_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_refresh_done
 * DESCRIPTION
 *  This function is used to process the result of refreshing connection.
 * PARAMETERS
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_refresh_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    srv_email_comm_cntx_struct *comm_p = NULL;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_REFRESH_DONE);

    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING)
    {
        //trace: error state
        return;
    }

    comm_p = &cntx_p->common;
    comm_p->refresh_result = comm_p->result.result;

    srv_email_nwk_fsm(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_send_abort
 * DESCRIPTION
 *  This function is used to abort the sending.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_send_abort(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_smtp_send_abort((srv_email_smtp_cntx_struct*)cntx_p);

    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_update_abort
 * DESCRIPTION
 *  This function is used to abort the updating.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_update_abort(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        srv_email_pop3_update_abort((srv_email_pop3_cntx_struct*)cntx_p);
    }
    else
    {
        srv_email_imap4_update_abort((srv_email_imap4_cntx_struct*)cntx_p);
    }

    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_receive_abort
 * DESCRIPTION
 *  This function is used to abort the updating.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_receive_abort(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        srv_email_pop3_receive_abort((srv_email_pop3_cntx_struct*)cntx_p);
    }
    else
    {
        srv_email_imap4_receive_abort((srv_email_imap4_cntx_struct*)cntx_p);
    }

    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_sync_abort
 * DESCRIPTION
 *  This function is used to abort the updating.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_sync_abort(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_imap4_sync_abort((srv_email_imap4_cntx_struct*)cntx_p);

    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_list_folder_abort
 * DESCRIPTION
 *  This function is used to abort the updating.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_list_folder_abort(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_imap4_list_fldr_abort((srv_email_imap4_cntx_struct*)cntx_p);

    SRV_EMAIL_NWK_SET_STATE(cntx_p, cntx_p->prev_state);
    cntx_p->prev_state = SRV_EMAIL_NWK_STATE_INIT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_disconnect_abort
 * DESCRIPTION
 *  This function is used to abort the disconnecting.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_nwk_fsm_disconnect_abort(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        srv_email_pop3_disconnect_abort((srv_email_pop3_cntx_struct*)cntx_p);
    }
    else
    {
        srv_email_ps_abort_req(comm_p->ps_handle);
    }

    ret = srv_email_nwk_is_bearer_activated(comm_p->nwk_acct_id);
    if (ret)
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
    }
    else
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm
 * DESCRIPTION
 *  The function is used to run the Network FSM.
 * PARAMETERS
 *  ptr             [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_fsm(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)ptr;
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    MMI_BOOL run_fsm = comm_p->result.result;
#ifdef __MMI_SSO__
    MMI_BOOL ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (run_fsm)
    {
        switch (cntx_p->nwk_state)
        {
            case SRV_EMAIL_NWK_STATE_INIT:
                retval = srv_email_nwk_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_CREATING:
            case SRV_EMAIL_NWK_STATE_CREATED:
                retval = srv_email_nwk_fsm_created(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_ACTIVATING:
            case SRV_EMAIL_NWK_STATE_ACTIVATED:
                retval = srv_email_nwk_fsm_activated(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_CONNECTING:
                retval = srv_email_nwk_fsm_connected(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_AUTHORIZING:
                retval = srv_email_nwk_fsm_authorized(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_QUERYING:
                retval = srv_email_nwk_fsm_queried(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_READY:
                retval = srv_email_nwk_fsm_ready(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_UPDATING:
                SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
                /* No break here */

            case SRV_EMAIL_NWK_STATE_UPDATED:
                retval = srv_email_nwk_fsm_updated(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_SENDING:
                retval = srv_email_nwk_fsm_sent(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_RECEIVING:
                retval = srv_email_nwk_fsm_received(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_SYNCING:
                retval = srv_email_nwk_fsm_synced(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_LISTING_FOLDER:
                retval = srv_email_nwk_fsm_folder_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_DISCONNECTING:
                retval = srv_email_nwk_fsm_disconnected(cntx_p);
                break;

        #ifdef __MMI_SSO__
            case SRV_EMAIL_NWK_STATE_CLOUD_QUERYING:
            case SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING:
                ret = srv_email_nwk_is_bearer_activated(comm_p->nwk_acct_id);
                if (ret)
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
                }
                else
                {
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
                }
                retval = SRV_EMAIL_RESULT_SUCC;
                break;

        #ifdef __MMI_CLOUD_VPP_UPGRADE__
            case SRV_EMAIL_NWK_STATE_CLOUD_UPGRADING:
                ret = srv_email_nwk_query_cloud_server_info(
                        comm_p->provider_id,
                        comm_p->protocol,
                        &comm_p->server_addr);
                if (ret)
                {
                    srv_email_compute_acct_digest(
                        comm_p->server_addr.server_name,
                        comm_p->auth.username,
                        comm_p->acct_digest);

                    srv_email_ps_create_instance_req((U32)cntx_p, comm_p->protocol);
                    SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATING);
                    retval = SRV_EMAIL_RESULT_WOULDBLOCK;
                }
                else
                {
                    retval = SRV_EMAIL_RESULT_SERVER_ERROR;
                }
                break;
        #endif /* __MMI_CLOUD_VPP_UPGRADE__ */
        #endif /* __MMI_SSO__ */

            default:
                break;
        }

        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            run_fsm = MMI_FALSE;
        }
    }

    if (retval != SRV_EMAIL_RESULT_SUCC &&
        retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        retval = srv_email_nwk_err_rsp(cntx_p);
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_abort
 * DESCRIPTION
 *  The function is used to abort the Network FSM.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_fsm_abort(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_ABORT, cntx_p, cntx_p->nwk_state);

    cb_p = srv_email_nwk_update_running_cb(cntx_p, MMI_FALSE);

    switch (cntx_p->nwk_state)
    {
        case SRV_EMAIL_NWK_STATE_CREATING:
        case SRV_EMAIL_NWK_STATE_ACTIVATING:
            if (!cb_p)
            {
                comm_p->abort_flag = MMI_TRUE;
            }
            break;

        case SRV_EMAIL_NWK_STATE_CONNECTING:
        case SRV_EMAIL_NWK_STATE_AUTHORIZING:
            if (!cb_p)
            {
                srv_email_ps_abort_req(comm_p->ps_handle);
                srv_email_ps_disconnect_req(comm_p->ps_handle);
                SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
            }
            break;

    #ifdef __MMI_SSO__
        case SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING:
            srv_sso_cancel(comm_p->sso_req_id);
            /* No break */
        case SRV_EMAIL_NWK_STATE_CLOUD_QUERYING:
    #endif /* __MMI_SSO__ */
        case SRV_EMAIL_NWK_STATE_QUERYING:
            if (!cb_p)
            {
                srv_email_ps_disconnect_req(comm_p->ps_handle);
                SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
            }
            break;
            
    #ifdef __MMI_CLOUD_VPP_UPGRADE__
        case SRV_EMAIL_NWK_STATE_CLOUD_UPGRADING:
            srv_upgrade_cancel(SRV_UPGRADE_ORIGINATOR_CLOUD_EMAIL);
            /* No break */
    #endif /* __MMI_CLOUD_VPP_UPGRADE__ */
        case SRV_EMAIL_NWK_STATE_INIT:
        case SRV_EMAIL_NWK_STATE_CREATED:
        case SRV_EMAIL_NWK_STATE_ACTIVATED:
        case SRV_EMAIL_NWK_STATE_READY:
        case SRV_EMAIL_NWK_STATE_UPDATED:
        case SRV_EMAIL_NWK_STATE_UPDATING:
        case SRV_EMAIL_NWK_STATE_SENDING:
        case SRV_EMAIL_NWK_STATE_RECEIVING:
        case SRV_EMAIL_NWK_STATE_SYNCING:
        case SRV_EMAIL_NWK_STATE_LISTING_FOLDER:
            switch (cntx_p->nwk_state)
            {
                case SRV_EMAIL_NWK_STATE_UPDATING:
                    srv_email_nwk_fsm_update_abort(cntx_p);
            	    break;

                case SRV_EMAIL_NWK_STATE_SENDING:
                    srv_email_nwk_fsm_send_abort(cntx_p);
            	    break;

                case SRV_EMAIL_NWK_STATE_RECEIVING:
                    srv_email_nwk_fsm_receive_abort(cntx_p);
                    break;

                case SRV_EMAIL_NWK_STATE_SYNCING:
                    srv_email_nwk_fsm_sync_abort(cntx_p);
                    break;

                case SRV_EMAIL_NWK_STATE_LISTING_FOLDER:
                    srv_email_nwk_fsm_list_folder_abort(cntx_p);
                    break;

                default:
                    srv_email_nwk_stop_job(cntx_p);
                    break;
            }

            if (cb_p)
            {
                srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
            }
            break;

        case SRV_EMAIL_NWK_STATE_DISCONNECTING:
            srv_email_nwk_fsm_disconnect_abort(cntx_p);
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->nwk_state, 0, 0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_disconn_ind
 * DESCRIPTION
 *  The function is used to process the DISCONNECT indication.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_fsm_disconn_ind(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    MMI_BOOL ret = MMI_TRUE;
    MMI_BOOL need_update = MMI_FALSE;
    MMI_BOOL proc_as_succ = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_FSM_DISCONNECT_IND, cntx_p, cntx_p->nwk_state);

    switch (cntx_p->nwk_state)
    {
        case SRV_EMAIL_NWK_STATE_AUTHORIZING:
        case SRV_EMAIL_NWK_STATE_UPDATING:
        case SRV_EMAIL_NWK_STATE_SENDING:
        case SRV_EMAIL_NWK_STATE_RECEIVING:
        case SRV_EMAIL_NWK_STATE_SYNCING:
        case SRV_EMAIL_NWK_STATE_LISTING_FOLDER:
        case SRV_EMAIL_NWK_STATE_DISCONNECTING:
            switch (cntx_p->nwk_state)
            {
                case SRV_EMAIL_NWK_STATE_UPDATING:
                    srv_email_nwk_fsm_update_abort(cntx_p);
            	    break;

                case SRV_EMAIL_NWK_STATE_SENDING:
                    srv_email_nwk_fsm_send_abort(cntx_p);
            	    break;

                case SRV_EMAIL_NWK_STATE_RECEIVING:
                    srv_email_nwk_fsm_receive_abort(cntx_p);
                    break;

                case SRV_EMAIL_NWK_STATE_SYNCING:
                    srv_email_nwk_fsm_sync_abort(cntx_p);
                    break;

                case SRV_EMAIL_NWK_STATE_LISTING_FOLDER:
                    srv_email_nwk_fsm_list_folder_abort(cntx_p);
                    break;

                case SRV_EMAIL_NWK_STATE_DISCONNECTING:
                    srv_email_nwk_fsm_disconnect_abort(cntx_p);
                    proc_as_succ = MMI_TRUE;
                    break;

                default:
                    break;
            }

            need_update = MMI_TRUE;
            break;

        default:
            break;
    }

    ret = srv_email_nwk_is_bearer_activated(comm_p->nwk_acct_id);
    if (ret)
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
    }
    else
    {
        SRV_EMAIL_NWK_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
    }

    if (need_update)
    {
        if (!proc_as_succ)
        {
            srv_email_set_error_cause(
                &comm_p->result,
                SRV_EMAIL_MAIL_ERROR,
                SRV_EMAIL_RESULT_NETWORK_ERROR,
                NULL);
        }

        cb_p = srv_email_nwk_update_running_cb_for_disc_ind(cntx_p);
        if (cb_p)
        {
            srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx_p);
        }
        comm_p->result.result = MMI_TRUE;
    }

    srv_email_nwk_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_DISCONNECTED, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_imap4_push_ind
 * DESCRIPTION
 *  The function is used to process the IMAP_PUSH indication.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 *  ind_p           [IN]        The pointer point to the IMAP4 push indication
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_fsm_imap4_push_ind(
        srv_email_nwk_cntx_struct *cntx_p,
        email_ps_imap_push_ind_struct *ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_need_refresh_data_struct refresh_data;
    MMI_BOOL is_allowed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_FUNC_NWK_FSM_IMAP4_PUSH_IND,
        cntx_p,
        ind_p->type,
        cntx_p->nwk_state,
        comm_p->refresh_flag,
        comm_p->refresh_type);

    EMAILSRV_EXT_ASSERT(
        comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_IMAP4,
        comm_p->protocol,
        0,
        0);

    if (ind_p->type != EMAIL_PS_IMAP_PUSH_TYPE_NEWMSG &&
        ind_p->type != EMAIL_PS_IMAP_PUSH_TYPE_EXPUNGED &&
        ind_p->type != EMAIL_PS_IMAP_PUSH_TYPE_EXIST)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING &&
        cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATED &&
        cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING &&
        cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SYNCING &&
        cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_LISTING_FOLDER)
    {
        if (cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_READY &&
            ind_p->type == EMAIL_PS_IMAP_PUSH_TYPE_NEWMSG)
        {
            refresh_data.refresh_type = SRV_EMAIL_NWK_REFRESH_NEW_MSG;
            srv_email_nwk_cb_process_notify(
                cntx_p,
                NULL,
                SRV_EMAIL_NWK_NEED_REFRESH,
                &refresh_data);
        }
        return;
    }

    is_allowed = srv_email_imap4_is_push_allowed((srv_email_imap4_cntx_struct*)cntx_p);
    if (!is_allowed)
    {
        return;
    }

    if (ind_p->type == EMAIL_PS_IMAP_PUSH_TYPE_NEWMSG)
    {
        comm_p->refresh_type |= SRV_EMAIL_NWK_REFRESH_NEW_MSG;
    }
    else if (ind_p->type == EMAIL_PS_IMAP_PUSH_TYPE_EXPUNGED)
    {
        comm_p->refresh_type |= SRV_EMAIL_NWK_REFRESH_MSG_DELETED;
    }
    else
    {
        comm_p->refresh_type |= SRV_EMAIL_NWK_REFRESH_MSG_NUMBER;
    }

    if (comm_p->refresh_flag)
    {
        return;
    }
    comm_p->refresh_flag = MMI_TRUE;

    cb_p = srv_email_nwk_get_running_cb(cntx_p);
    if (!cb_p && !comm_p->refresh_notified)
    {
        refresh_data.refresh_type = comm_p->refresh_type;
        srv_email_nwk_cb_process_notify(
            cntx_p,
            NULL,
            SRV_EMAIL_NWK_NEED_REFRESH,
            &refresh_data);

        comm_p->refresh_notified = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_fsm_schdl
 * DESCRIPTION
 *  This function is used to process the follow network operation.
 * PARAMETERS
 *  user_data       [IN]        The related user_data
 * RETURNS
 *  The error code.
 *****************************************************************************/
void srv_email_nwk_fsm_schdl(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = (srv_email_nwk_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_email_nwk_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->common.schdl_flag)
    {
        cntx_p->common.schdl_flag = MMI_FALSE;
        srv_email_nwk_fsm(cntx_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_om_notify_callback
 * DESCRIPTION
 *  This function is used to register the object management notify callback function.
 * PARAMETERS
 *  data            [IN]        The notify data
 * RETURNS
 *  void
 ****************************************************************************/
void srv_email_nwk_om_notify_callback(const srv_email_om_notify_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = srv_email_nwk_get_cntx_list();
    srv_email_comm_cntx_struct *comm_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->notify_type != SRV_EMAIL_OM_NOTIFY_MSG_ADD &&
        data->notify_type != SRV_EMAIL_OM_NOTIFY_MSG_DEL &&
        data->notify_type != SRV_EMAIL_OM_NOTIFY_MSG_UPDATE)
    {
        return;
    }

    while (cntx_p)
    {
        comm_p = &cntx_p->common;

        switch (comm_p->protocol)
        {
            case EMAIL_PS_PRTOTOCOL_TYPE_SMTP:
                if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING)
                {
                    return;
                }

                srv_email_smtp_proc_om_notify(
                    (srv_email_smtp_cntx_struct*)cntx_p,
                    (srv_email_om_notify_struct*)data);
                break;

            case EMAIL_PS_PRTOTOCOL_TYPE_POP3:
            case EMAIL_PS_PRTOTOCOL_TYPE_IMAP4:
                if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING &&
                    cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATED &&
                    cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING &&
                    cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SYNCING &&
                    cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_LISTING_FOLDER)
                {
                    return;
                }

                if (comm_p->protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
                {
                    srv_email_pop3_proc_om_notify(
                        (srv_email_pop3_cntx_struct*)cntx_p,
                        (srv_email_om_notify_struct*)data);
                }
                else
                {
                    srv_email_imap4_proc_om_notify(
                        (srv_email_imap4_cntx_struct*)cntx_p,
                        (srv_email_om_notify_struct*)data);
                }
                break;

            default:
                EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
        }

        cntx_p = cntx_p->next;
    }
}

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__

#define SRV_EMAIL_NWK_CLOUD_INT_FUNC

static void srv_email_nwk_cloud_cb_process_notify(
                srv_email_nwk_cloud_cntx_struct *cntx_p,
                srv_email_nwk_cb_struct *cb_p,
                srv_email_nwk_status_enum status,
                void *status_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    srv_email_nwk_cb_struct *p_next = NULL;
    srv_email_nwk_proc_struct process;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status != SRV_EMAIL_NWK_DISCONNECTED)
    {
        if (!cb_p)
        {
            cb_p = srv_email_nwk_cloud_get_running_cb(cntx_p);
        }

        if (cb_p && cb_p->proc_callback)
        {
            process.status = status;
            process.status_data = status_data;
            process.user_data = cb_p->proc_user_data;

            cb_p->proc_callback(&process);
        }
    }
    else
    {
        if (cb_p)
        {
            if ((cb_p->state & SRV_EMAIL_NWK_CB_CONNECTED) &&
                cb_p->proc_callback)
            {
                cb_p->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;

                process.status = status;
                process.status_data = status_data;
                process.user_data = cb_p->proc_user_data;

                cb_p->proc_callback(&process);
            }
            return;
        }

        comm_p = &cntx_p->common;
        cb_p = comm_p->pending_cb_list_p;

        for (i = 0; i < 2; i++)
        {
            while (cb_p)
            {
                p_next = cb_p->next;

                if ((cb_p->state & SRV_EMAIL_NWK_CB_CONNECTED) &&
                    cb_p->proc_callback)
                {
                    cb_p->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;

                    process.status = status;
                    process.status_data = status_data;
                    process.user_data = cb_p->proc_user_data;

                    cb_p->proc_callback(&process);
                }

                cb_p = p_next;
            }

            cb_p = comm_p->idle_cb_list_p;
        }
    }
}


static void srv_email_nwk_cloud_cb_finish_notify(srv_email_nwk_cb_struct *cb_p, srv_email_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_finish_struct *result_p = NULL;
    srv_email_nwk_finish_funcptr_type callback = cb_p->finish_callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_p = (srv_email_nwk_finish_struct*)OslMalloc(sizeof(srv_email_nwk_finish_struct));

    memcpy(&result_p->result, result, sizeof(srv_email_result_struct));
    result_p->action = cb_p->action;
    result_p->user_data = cb_p->finish_user_data;

    cb_p->action = SRV_EMAIL_NWK_NONE;

    if (callback)
    {
        callback(result_p);
    }

    OslMfree(result_p);
}


static srv_email_nwk_cb_struct *srv_email_nwk_cloud_update_running_cb(
                                    srv_email_nwk_cloud_cntx_struct *cntx_p,
                                    MMI_BOOL notify_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = comm_p->running_cb_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_p)
    {
        srv_email_nwk_cloud_append_cb_to_idle_list(cntx_p, cb_p);
        if (!notify_result)
        {
            cb_p->action = SRV_EMAIL_NWK_NONE;
        }
        if (cb_p->action_data)
        {
            srv_email_mem_free(cb_p->action_data);
            cb_p->action_data = NULL;
        }
    }

    if (comm_p->pending_cb_list_p)
    {
        comm_p->running_cb_p = comm_p->pending_cb_list_p;
        comm_p->pending_cb_list_p = comm_p->pending_cb_list_p->next;
    }
    else
    {
        comm_p->running_cb_p = NULL;
    }

    if (notify_result)
    {
        srv_email_nwk_cloud_cb_finish_notify(cb_p, &comm_p->result);
    }

    return comm_p->running_cb_p;
}


srv_email_nwk_cb_struct *srv_email_nwk_cloud_update_running_cb_for_disc_ind(srv_email_nwk_cloud_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *cb_p = comm_p->running_cb_p;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_p)
    {
        srv_email_nwk_cloud_append_cb_to_idle_list(cntx, cb_p);
        ret = MMI_TRUE;
    }

    if (comm_p->pending_cb_list_p)
    {
        comm_p->running_cb_p = comm_p->pending_cb_list_p;
        comm_p->pending_cb_list_p = comm_p->pending_cb_list_p->next;
    }
    else
    {
        comm_p->running_cb_p = NULL;
    }

    if (ret)
    {
        srv_email_nwk_cloud_cb_finish_notify(cb_p, &comm_p->result);
    }

    return comm_p->running_cb_p;
}


#define SRV_EMAIL_NWK_CLOUD_SUB_FSM_INT_FUNC

static void srv_email_nwk_cloud_appd_fsm_compose_done(MMI_BOOL ret, S32 major, S32 minor, U32 size, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)user_data;
    srv_email_result_struct *result_p = NULL;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_APPEND_COMPOSE_DONE, cntx_p, ret, major, minor);

    is_valid = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_SENDING,
            SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE);
        return;
    }

    result_p = &cntx_p->common.result;

    result_p->result = ret;
    result_p->major = major;
    result_p->minor = minor;

    srv_email_nwk_cloud_appd_fsm(cntx_p);
}


static kal_int32 srv_email_nwk_cloud_parse_async_fs_callback(fs_job_id job_id, kal_int64 result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fs_async_callback_data_struct *fs_data = (fs_async_callback_data_struct*)data;
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)fs_data->param;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    srv_email_nwk_cloud_state_struct *state_p = NULL;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_PARSE_ASYNC_FS_CALLBACK, cntx_p, job_id, result);

    if (srv_email_delete_fs_async_job(job_id))
    {
        return 0;
    }

    is_valid = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CONTEXT_INVALID, cntx_p);
        return 0;
    }

    comm_p = &cntx_p->common;
    state_p = &cntx_p->state;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE ||
        state_p->parse_state != SRV_EMAIL_IMAP4_DECODE_CONTENT ||
        state_p->async_fs_job_id != fs_data->id)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
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
        srv_email_nwk_cloud_decode_base64_qprint(cntx_p);
    }
    else
    {
        state_p->parse_state = SRV_EMAIL_IMAP4_PARSE_NONE;

        srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_FS_ERROR, (S32)result, NULL);
        srv_email_nwk_cloud_retr_fsm(cntx_p);
    }

    return 0;
}



static void srv_email_nwk_cloud_decode_base64_qprint(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)user_data;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    srv_email_nwk_cloud_state_struct *state_p = NULL;
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
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_DECODE_B64QP, cntx_p);

    is_valid = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CONTEXT_INVALID, cntx_p);
        return;
    }

    comm_p = &cntx_p->common;
    state_p = &cntx_p->state;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE ||
        state_p->parse_state != SRV_EMAIL_IMAP4_DECODE_CONTENT)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_RECEIVING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE);
        return;
    }

    fn = state_p->curr_cont_p->filename;
    enc_type = srv_email_imap4_get_encode_type(state_p->curr_cont_p->cont.encoding);

    fs_overlapped.priority = FS_PRIORITY_DEFAULT;
    fs_overlapped.priority_value = 0;
    fs_overlapped.callback = srv_email_nwk_cloud_parse_async_fs_callback;
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
                            SRV_EMAIL_NWK_CLOUD_DECODE_BUFF_SIZE);
            }
            else
            {
                dec_size = applib_qprint_part_decode_append(
                            state_p->qprint_p,
                            state_p->async_fs_data_buf + offset,
                            &enc_size,
                            state_p->async_fs_data_buf,
                            SRV_EMAIL_NWK_CLOUD_DECODE_BUFF_SIZE);
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
            rw_size = SRV_EMAIL_MIN(rw_size, (SRV_EMAIL_NWK_CLOUD_DECODE_BUFF_SIZE - offset));

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
        state_p->curr_cont_p->cont.local_size = file_size;
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

    state_p->parse_state = SRV_EMAIL_IMAP4_PARSE_NONE;

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_set_error_cause(&comm_p->result, major, ret, NULL);
    }

    srv_email_nwk_cloud_retr_fsm(cntx_p);
}


static srv_email_result_enum srv_email_nwk_cloud_read_body_struct(
                                const WCHAR *filename,
                                srv_email_msg_env_struct *msg_env_p,
                                S32 *major_error,
                                S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retval = srv_email_imap4_read_body_struct(filename, msg_env_p, major_error, minor_error);
    return retval;
}


static srv_email_result_enum srv_email_nwk_cloud_read_content(
                                const WCHAR *filename,
                                srv_email_cont_list_struct *cont_p,
                                S32 *major_error,
                                S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retval = srv_email_imap4_read_content(filename, cont_p, major_error, minor_error);
    return retval;
}


static srv_email_result_enum srv_email_nwk_cloud_parse_content(
                                srv_email_nwk_cloud_cntx_struct *cntx_p,
                                srv_email_cont_list_struct *cont_p,
                                S32 *major_error,
                                S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;
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
        cont_p->cont.local_size = 0;
        return SRV_EMAIL_RESULT_SUCC;
    }

    enc_type = srv_email_imap4_get_encode_type(cont_p->cont.encoding);
    if (enc_type != EMAIL_MIME_ENCBASE64 && enc_type != EMAIL_MIME_ENCQUOTPRINT)
    {
        FS_Close(fd1);
        cont_p->cont.local_size = file_size;
        return SRV_EMAIL_RESULT_SUCC;
    }

    async_fs_data_buf_p = srv_email_mem_alloc(SRV_EMAIL_NWK_CLOUD_DECODE_BUFF_SIZE);
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

    srv_email_schdl_start_job(srv_email_nwk_cloud_decode_base64_qprint, cntx_p);

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
    FS_Delete(cont_p->filename);
    FS_Delete(state_p->filename);

    *major_error = major;
    *minor_error = minor;

    return SRV_EMAIL_RESULT_FAIL;
}


static srv_email_result_enum srv_email_nwk_cloud_update_retr_file(
                                srv_email_nwk_cloud_state_struct *state_p,
                                S32 *major_error,
                                S32 *minor_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    U32 wbyte = 0;
    S32 major = SRV_EMAIL_FS_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state_p->msg_part == SRV_EMAIL_NWK_CLOUD_MSG_ALL_UID)
    {
        fd = FS_Open(state_p->msg_filename, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (fd < 0)
        {
            minor = fd;
            goto ERROR_HANDLE;
        }

        minor = FS_Write(fd, &state_p->list_count, 4, &wbyte);
        if (minor < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }

        FS_Close(fd);

        return SRV_EMAIL_RESULT_SUCC;
    }
    else if (state_p->msg_part & SRV_EMAIL_NWK_CLOUD_MSG_CONTENT)
    {
        srv_email_stor_cont_header_struct *cont_p = NULL;

        EMAILSRV_ASSERT(state_p->curr_cont_p);

        cont_p = &state_p->curr_cont_p->cont;

        if (cont_p->local_size)
        {
            FS_Delete(state_p->part_filename);
            minor = FS_Rename(state_p->curr_cont_p->filename, state_p->part_filename);
            if (minor < 0)
            {
                goto ERROR_HANDLE;
            }
        }

        cont_p->this_part_exist = cont_p->local_size ? MMI_TRUE : MMI_FALSE;

        fd = FS_Open(state_p->msg_filename, FS_READ_WRITE);
        if (fd < 0)
        {
            minor = fd;
            goto ERROR_HANDLE;
        }

        minor = FS_Seek(fd, 0, FS_FILE_END);
        if (minor < 0)
        {
            goto ERROR_HANDLE;
        }

        minor = FS_Write(fd, cont_p, sizeof(srv_email_stor_cont_header_struct), &wbyte);
        if (minor < 0 || wbyte != sizeof(srv_email_stor_cont_header_struct))
        {
            goto ERROR_HANDLE;
        }

        FS_Close(fd);
    }

    return SRV_EMAIL_RESULT_SUCC;

ERROR_HANDLE:
    if (fd >= 0)
    {
        FS_Close(fd);
    }

    *major_error = major;
    *minor_error = minor;

    return SRV_EMAIL_RESULT_FAIL;
}


static srv_email_nwk_cloud_abort_parse(srv_email_nwk_cloud_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_PARSE_ABORT, state_p->parse_state);

    switch (state_p->parse_state)
    {
        case SRV_EMAIL_IMAP4_DECODE_CONTENT:
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

        default:
            break;
    }
}


static void srv_email_nwk_cloud_sso_refresh_done(S32 req_id, srv_sso_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)user_data;
    MMI_BOOL is_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_SSO_REFRESH_DONE, cntx_p, result);

    is_valid = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CONTEXT_INVALID, cntx_p);
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING ||
        cntx_p->common.sso_req_id != req_id)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->common.sso_req_id,
            SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING,
            req_id);
        return;
    }

    if (result != SRV_SSO_OK)
    {
        srv_email_set_error_cause(
            &cntx_p->common.result,
            SRV_EMAIL_MAIL_ERROR,
            SRV_EMAIL_RESULT_AUTH_FAIL,
            NULL);
    }

    srv_email_nwk_cloud_fsm(cntx_p);
}


#define SRV_EMAIL_NWK_CLOUD_SUB_FSM

static srv_email_result_enum srv_email_nwk_cloud_conn_fsm_init(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_session_struct *sess_p = &cntx_p->session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CONN_FSM_INIT, cntx_p);

    srv_email_ps_open_folder_req(cntx_p->common.ps_handle, sess_p->fldr_name);

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


static srv_email_result_enum srv_email_nwk_cloud_conn_fsm_fldr_opened(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_session_struct *sess_p = &cntx_p->session;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CONN_FSM_OPENED, cntx_p, state_p->fldr_open_fail_flag);

    if (state_p->fldr_open_fail_flag)
    {
        state_p->fldr_open_fail_flag = MMI_FALSE;
        srv_email_ps_create_folder_req(cntx_p->common.ps_handle, sess_p->fldr_name);
        SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_CREATE_FOLDER);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_DONE);
        return SRV_EMAIL_RESULT_SUCC;
    }
}


static srv_email_result_enum srv_email_nwk_cloud_conn_fsm_fldr_created(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_session_struct *sess_p = &cntx_p->session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_CONN_FSM_CREATED, cntx_p);

    srv_email_ps_open_folder_req(cntx_p->common.ps_handle, sess_p->fldr_name);

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


static void srv_email_nwk_cloud_conn_fsm_done(srv_email_nwk_cloud_cntx_struct *cntx_p)
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
        SRV_EMAIL_CLD_CONN_FSM_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    if (!result_p->result)
    {
        srv_email_nwk_cloud_session_free(&cntx_p->session);
    }
    else
    {
        cntx_p->session.sync_with_server = MMI_TRUE;
    }

    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    srv_email_nwk_cloud_state_free(&cntx_p->state);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


static srv_email_result_enum srv_email_nwk_cloud_conn_fsm(srv_email_nwk_cloud_cntx_struct *cntx_p)
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
                retval = srv_email_nwk_cloud_conn_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER:
                retval = srv_email_nwk_cloud_conn_fsm_fldr_opened(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_CREATE_FOLDER:
                retval = srv_email_nwk_cloud_conn_fsm_fldr_created(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_UPDATE_DONE:
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
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT)
    {
        srv_email_nwk_cloud_conn_fsm_done(cntx_p);
    }

    return retval;
}


static srv_email_result_enum srv_email_nwk_cloud_appd_fsm_init(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_APPD_FSM_INIT, cntx_p);

    kal_wsprintf(
        state_p->filename,
        "%s%s%08X.eml",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        state_p);

    retval = srv_email_comp_create(&state_p->comp_handle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_get_compose_error(retval, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return retval;
    }

    retval = srv_email_comp_start_by_msg_handle(
                state_p->comp_handle,
                state_p->msg_handle,
                MMI_FALSE,
                state_p->filename,
                srv_email_nwk_cloud_appd_fsm_compose_done,
                cntx_p);

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE);

    return retval;
}


static srv_email_result_enum srv_email_nwk_cloud_appd_fsm_composed(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_APPD_FSM_COMPOSED, cntx_p);

    srv_email_ps_append_mail_req(
        cntx_p->common.ps_handle,
        (const CHAR*)cntx_p->session.fldr_name,
        (const WCHAR*)cntx_p->state.filename);

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_APPEND);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


static srv_email_result_enum srv_email_nwk_cloud_appd_fsm_appended(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_APPD_FSM_APPENDED, cntx_p);

    cntx_p->state.msg_handle = EMAIL_MSG_INVALID_HANDLE;
    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_DONE);
    return SRV_EMAIL_RESULT_SUCC;
}


static void srv_email_nwk_cloud_appd_fsm_done(srv_email_nwk_cloud_cntx_struct *cntx_p)
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
        SRV_EMAIL_CLD_APPD_FSM_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    srv_email_nwk_cloud_state_free(&cntx_p->state);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


static srv_email_result_enum srv_email_nwk_cloud_appd_fsm(srv_email_nwk_cloud_cntx_struct *cntx_p)
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
            case SRV_EMAIL_NWK_SUB_STATE_SEND_INIT:
                retval = srv_email_nwk_cloud_appd_fsm_init(cntx_p);
        	    break;

            case SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE:
                retval = srv_email_nwk_cloud_appd_fsm_composed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_SEND_APPEND:
                retval = srv_email_nwk_cloud_appd_fsm_appended(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_SEND_DONE:
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
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SEND_INIT)
    {
        srv_email_nwk_cloud_appd_fsm_done(cntx_p);
    }

    return retval;
}


static srv_email_result_enum srv_email_nwk_cloud_retr_fsm_init(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cloud_session_struct *sess_p = &cntx_p->session;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;
    srv_email_stor_msg_create_header_struct *msg_header_p = NULL;
    email_ps_fetch_type_enum fetch_type = EMAIL_PS_FETCH_TYPE_ENVELOP_EXT;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_RETR_FSM_INIT, cntx_p, state_p->msg_part);

    if (state_p->msg_part == SRV_EMAIL_NWK_CLOUD_MSG_ALL_UID)
    {
        EMAILSRV_ASSERT(sess_p->total_msg_num);

        if (state_p->uid_max_num >= sess_p->total_msg_num)
        {
            state_p->list_count = sess_p->total_msg_num;
            state_p->start_index = 1;
        }
        else
        {
            state_p->list_count = state_p->uid_max_num;
            state_p->start_index = sess_p->total_msg_num - state_p->uid_max_num + 1;
        }

        srv_email_ps_list_uid_req(
            comm_p->ps_handle,
            state_p->start_index,
            state_p->list_count,
            state_p->msg_filename,
            EMAIL_PS_FETCH_TYPE_SMS_UID);

        SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_UID);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    switch (state_p->fetch_type)
    {
        case SRV_EMAIL_IMAP4_FETCH_BODY_STRUCT:
            fetch_type = EMAIL_PS_FETCH_TYPE_BODYSTRUCTURE;
            /* No break */

        case SRV_EMAIL_IMAP4_FETCH_ENVELOPE:
            EMAILSRV_ASSERT(!state_p->msg_env_p->msg_header_p);

            msg_header_p = (srv_email_stor_msg_create_header_struct*)
                srv_email_mem_alloc(sizeof(srv_email_stor_msg_create_header_struct));
            if (!msg_header_p)
            {
                minor = SRV_EMAIL_RESULT_NO_MEMORY;
                goto EXIT_HANDLE;
            }
            memset(msg_header_p, 0, sizeof(srv_email_stor_msg_create_header_struct));

            state_p->msg_env_p->msg_header_p = msg_header_p;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, state_p->fetch_type, 0, 0);
            break;
    }

    srv_email_ps_fetch_mail_req(
        comm_p->ps_handle,
        state_p->msg_uid,
        fetch_type,
        0,
        NULL,
        (const WCHAR*)state_p->msg_filename);

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);

    return SRV_EMAIL_RESULT_WOULDBLOCK;

EXIT_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


static srv_email_result_enum srv_email_nwk_cloud_retr_fsm_uid_listed(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_RETR_FSM_UID_LISTED, cntx_p);

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
    return SRV_EMAIL_RESULT_SUCC;
}


static srv_email_result_enum srv_email_nwk_cloud_retr_fsm_received(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;
    srv_email_msg_env_struct *msg_env_p = state_p->msg_env_p;
    srv_email_cont_list_struct *cont_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = 0;
    S32 minor = 0;
    srv_email_cont_list_struct *text_cont_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_RETR_FSM_RECEIVED, cntx_p, state_p->fetch_type);

    switch (state_p->fetch_type)
    {
        case SRV_EMAIL_IMAP4_FETCH_ENVELOPE:
            if (!(state_p->msg_part & SRV_EMAIL_NWK_CLOUD_MSG_CONTENT))
            {
                SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
                return SRV_EMAIL_RESULT_SUCC;
            }
            break;

        case SRV_EMAIL_IMAP4_FETCH_BODY_STRUCT:
            retval = srv_email_nwk_cloud_read_body_struct(
                        (const WCHAR*)state_p->rsp_filename,
                        msg_env_p,
                        &major,
                        &minor);

            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                cont_p = msg_env_p->cont_p;
                while (cont_p)
                {
                    if (cont_p->type == SRV_EMAIL_STOR_MSG_CONT_TEXT)
                    {
                        text_cont_p = cont_p;
                    }

                    cont_p = cont_p->next;
                }

                if (state_p->msg_part & SRV_EMAIL_NWK_CLOUD_MSG_CONTENT)
                {
                    if (text_cont_p && text_cont_p->cont.server_size)
                    {
                        state_p->curr_cont_p = text_cont_p;
                    }
                    else
                    {
                        state_p->curr_cont_p = (srv_email_cont_list_struct*)
                            OslMalloc(sizeof(srv_email_cont_list_struct));
                        memset(state_p->curr_cont_p, 0, sizeof(srv_email_cont_list_struct));

                        retval = srv_email_nwk_cloud_update_retr_file(state_p, &major, &minor);

                        OslMfree(state_p->curr_cont_p);
                        state_p->curr_cont_p = NULL;
                    }
                }
            }
            break;

        case SRV_EMAIL_IMAP4_FETCH_CONTENT:
            retval = srv_email_nwk_cloud_read_content(
                        (const WCHAR*)state_p->rsp_filename,
                        state_p->curr_cont_p,
                        &major,
                        &minor);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                retval = srv_email_nwk_cloud_parse_content(cntx_p, state_p->curr_cont_p, &major, &minor);
                if (retval == SRV_EMAIL_RESULT_SUCC)
                {
                    retval = srv_email_nwk_cloud_update_retr_file(state_p, &major, &minor);
                    state_p->curr_cont_p = NULL;
                }
                else
                {
                    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE);
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
                state_p->msg_uid,
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

            srv_email_ps_fetch_mail_req(
                comm_p->ps_handle,
                state_p->msg_uid,
                EMAIL_PS_FETCH_TYPE_PART,
                0,
                state_p->part_num,
                (const WCHAR*)state_p->rsp_filename);

            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        else
        {
            SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
            return SRV_EMAIL_RESULT_SUCC;
        }
    }
    else
    {
        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
        return retval;
    }
}


static srv_email_result_enum srv_email_nwk_cloud_retr_fsm_parsed(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_RETR_FSM_PARSED, cntx_p, state_p->fetch_type);

    switch (state_p->fetch_type)
    {
        case SRV_EMAIL_IMAP4_FETCH_CONTENT:
            retval = srv_email_nwk_cloud_update_retr_file(state_p, &major, &minor);
            state_p->curr_cont_p = NULL;
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, state_p->fetch_type, 0, 0);
            break;
    }

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_DONE);
    }
    return retval;
}


static void srv_email_nwk_cloud_retr_fsm_done(srv_email_nwk_cloud_cntx_struct *cntx_p)
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
        SRV_EMAIL_CLD_RETR_FSM_DONE,
        cntx_p,
        result_p->result,
        result_p->major,
        result_p->minor);

    cntx_p->sub_state = SRV_EMAIL_NWK_SUB_STATE_NONE;

    srv_email_nwk_cloud_state_free(&cntx_p->state);

    if (cntx_p->callback)
    {
        (cntx_p->callback)(cntx_p->user_data);
    }
}


static srv_email_result_enum srv_email_nwk_cloud_retr_fsm(srv_email_nwk_cloud_cntx_struct *cntx_p)
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
                retval = srv_email_nwk_cloud_retr_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_UID:
                retval = srv_email_nwk_cloud_retr_fsm_uid_listed(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE:
                retval = srv_email_nwk_cloud_retr_fsm_received(cntx_p);
                break;

            case SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE:
                retval = srv_email_nwk_cloud_retr_fsm_parsed(cntx_p);
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

    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK &&
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_INIT)
    {
        srv_email_nwk_cloud_retr_fsm_done(cntx_p);
    }

    return retval;
}


static void srv_email_nwk_cloud_fsm_connect_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_CONNECT_DONE, cntx_p);

    ret = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING)
    {
        return;
    }

    srv_email_nwk_cloud_fsm(cntx_p);
}


static void srv_email_nwk_cloud_fsm_append_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_APPEND_DONE, cntx_p);

    ret = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING)
    {
        return;
    }

    srv_email_nwk_cloud_fsm(cntx_p);
}


static void srv_email_nwk_cloud_fsm_retrieve_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_RETRIEVE_DONE, cntx_p);

    ret = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING)
    {
        return;
    }

    srv_email_nwk_cloud_fsm(cntx_p);
}


static void srv_email_nwk_cloud_fsm_connect_abort(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_CONNECT_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER:
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_CREATE_FOLDER:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_UPDATE_DONE:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;
    comm_p->result.result = MMI_FALSE;

    srv_email_nwk_cloud_conn_fsm_done(cntx_p);

    comm_p->result.result = MMI_TRUE;

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);
}


static void srv_email_nwk_cloud_fsm_append_abort(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_APPEND_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_SEND_COMPOSE:
            srv_email_comp_stop(state_p->comp_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_SEND_APPEND:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_SEND_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_SEND_DONE:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;

    srv_email_nwk_cloud_appd_fsm_done(cntx_p);

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
}


static void srv_email_nwk_cloud_fsm_retrieve_abort(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_RETRIEVE_ABORT, cntx_p, cntx_p->sub_state);

    switch (cntx_p->sub_state)
    {
        case SRV_EMAIL_NWK_SUB_STATE_RECV_UID:
        case SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE:
            srv_email_ps_abort_req(comm_p->ps_handle);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_RECV_PARSE:
            srv_email_nwk_cloud_abort_parse(state_p);
            break;

        case SRV_EMAIL_NWK_SUB_STATE_RECV_INIT:
        case SRV_EMAIL_NWK_SUB_STATE_RECV_DONE:
        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->sub_state, 0, 0);
            break;
    }

    cntx_p->callback = NULL;

    srv_email_nwk_cloud_retr_fsm_done(cntx_p);

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_connect(
                                srv_email_nwk_cloud_cntx_struct *cntx_p,
                                srv_email_nwk_cloud_conn_struct *conn_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cloud_session_struct *sess_p = &cntx_p->session;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_FSM_CONNECT_START,
        cntx_p,
        sess_p->sync_with_server,
        cntx_p->sub_state);

    if (sess_p->sync_with_server &&
        strcmp(sess_p->fldr_name, conn_p->fldr_name) == 0)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_STATE;
        goto ERROR_HANDLE;
    }

    srv_email_nwk_cloud_session_free(sess_p);
    srv_email_nwk_cloud_state_init(state_p);

    sess_p->sync_with_server = MMI_FALSE;
    strcpy(sess_p->fldr_name, conn_p->fldr_name);
    state_p->fldr_create_flag = conn_p->fldr_create;

    cntx_p->callback = srv_email_nwk_cloud_fsm_connect_done;
    cntx_p->user_data = cntx_p;

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_UPDATE_INIT);

    retval = srv_email_nwk_cloud_conn_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_append(
                                srv_email_nwk_cloud_cntx_struct *cntx_p,
                                srv_email_nwk_send_struct *send_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cloud_session_struct *sess_p = &cntx_p->session;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_FSM_APPEND_START,
        cntx_p,
        sess_p->sync_with_server,
        cntx_p->sub_state);

    if (!cntx_p->session.sync_with_server)
    {
        minor = SRV_EMAIL_RESULT_INVALID_OPERATION;
        goto ERROR_HANDLE;
    }

    if (cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_NONE)
    {
        minor = SRV_EMAIL_RESULT_INVALID_OPERATION;
        goto ERROR_HANDLE;
    }

    srv_email_nwk_cloud_state_init(state_p);

    state_p->msg_handle = send_p->msg_handle;

    cntx_p->callback = srv_email_nwk_cloud_fsm_append_done;
    cntx_p->user_data = cntx_p;

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_SEND_INIT);

    retval = srv_email_nwk_cloud_appd_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_retrieve(
                                srv_email_nwk_cloud_cntx_struct *cntx_p,
                                srv_email_nwk_cloud_retr_struct *retr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cloud_session_struct *sess_p = &cntx_p->session;
    srv_email_nwk_cloud_state_struct *state_p = &cntx_p->state;
    srv_email_msg_env_struct *msg_env_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_FSM_RETRIEVE_START,
        cntx_p,
        sess_p->sync_with_server,
        cntx_p->sub_state,
        sess_p->total_msg_num,
        retr_p->msg_part);

    if (!sess_p->sync_with_server)
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
        if (retr_p->msg_part != SRV_EMAIL_NWK_CLOUD_MSG_ALL_UID)
        {
            minor = SRV_EMAIL_RESULT_MSG_NOT_EXIST;
            goto ERROR_HANDLE;
        }

        mmi_wcscpy(state_p->msg_filename, retr_p->filename);

        retval = srv_email_nwk_cloud_update_retr_file(state_p, &major, &minor);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            return SRV_EMAIL_RESULT_SUCC;
        }
        else
        {
            goto ERROR_HANDLE;
        }
    }

    srv_email_nwk_cloud_state_init(state_p);

    state_p->msg_part = retr_p->msg_part;
    mmi_wcscpy(state_p->msg_filename, retr_p->filename);

    if (state_p->msg_part == SRV_EMAIL_NWK_CLOUD_MSG_ALL_UID)
    {
        state_p->uid_max_num = retr_p->uid_max_num;
    }
    else
    {
        state_p->msg_uid = retr_p->msg_uid;
        mmi_wcscpy(state_p->part_filename, retr_p->part_filename);

        msg_env_p = srv_email_imap4_new_envelope();
        if (!msg_env_p)
        {
            minor = SRV_EMAIL_RESULT_NO_MEMORY;
            goto ERROR_HANDLE;
        }
        state_p->msg_env_p = msg_env_p;

        if (state_p->msg_part & SRV_EMAIL_NWK_CLOUD_MSG_ENVELOPE)
        {
            state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_ENVELOPE;
        }
        else
        {
            state_p->fetch_type = SRV_EMAIL_IMAP4_FETCH_BODY_STRUCT;
        }
    }

    cntx_p->callback = srv_email_nwk_cloud_fsm_retrieve_done;
    cntx_p->user_data = cntx_p;

    SRV_EMAIL_NWK_CLOUD_SET_SUB_STATE(cntx_p, SRV_EMAIL_NWK_SUB_STATE_RECV_INIT);

    retval = srv_email_nwk_cloud_retr_fsm(cntx_p);

    return retval;

ERROR_HANDLE:
    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


#define SRV_EMAIL_NWK_CLOUD_FSM

static mmi_ret srv_email_nwk_cloud_fsm_bearer_info_ind(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_bearer_info_struct *bearer_info_p = (srv_cbm_bearer_info_struct*)param;
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)bearer_info_p->user_data;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    MMI_BOOL ret = MMI_FALSE;
    U8 app_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_BEARER_INFO_IND,
        cntx_p,
        bearer_info_p->account_id,
        bearer_info_p->state);

    ret = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return MMI_RET_OK;
    }

    comm_p = &cntx_p->common;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_BEARER_STATE,
        cntx_p,
        cntx_p->nwk_state,
        comm_p->wait_bearer_info);

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_ACTIVATING ||
        !(comm_p->wait_bearer_info & bearer_info_p->state))
    {
        return MMI_RET_OK;
    }

    switch (bearer_info_p->state)
    {
        case SRV_CBM_ACTIVATING:
            comm_p->wait_bearer_info = SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED;
            return MMI_RET_OK;

        case SRV_CBM_ACTIVATED:
            app_id = cbm_get_app_id(comm_p->nwk_acct_id);
            cbm_hold_bearer(app_id);
            break;

        case SRV_CBM_DEACTIVATED:
            srv_email_set_error_cause(
                &comm_p->result,
                SRV_EMAIL_MAIL_ERROR,
                SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL,
                NULL);
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, bearer_info_p->state, 0, 0);
            return MMI_RET_OK;
    }

    comm_p->wait_bearer_info = 0;
    srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
    return MMI_RET_OK;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_init(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    U32 len = SRV_EMAIL_MAX_ADDR_LEN + 1;
    srv_email_server_struct *server_p = &comm_p->server_addr;
    cloud_plugin_server_info_struct *info_p = NULL;
    MMI_BOOL is_valid;
    U8 i;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_INIT, cntx_p);

    EMAILSRV_ASSERT(comm_p->ps_handle == EMAIL_PS_INVALID_HANDLE);

    minor = srv_email_acct_get_info_for_cloud(comm_p->acct_id, comm_p->from_addr, &len);
    if (minor != SRV_EMAIL_RESULT_SUCC)
    {
        goto ERROR_HANDLE;
    }

    info_p = (cloud_plugin_server_info_struct*)OslMalloc(sizeof(cloud_plugin_server_info_struct));
    is_valid = srv_cloud_query_server_info(
                comm_p->provider_id,
                CLOUD_PLUGIN_FEATURE_TYPE_SMS_BACKUP_RESTORE | CLOUD_PLUGIN_PROTOCOL_IMAP,
                info_p);
    if (!is_valid)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_QUERY_SERVER_INFO_FAIL, cntx_p, comm_p->provider_id);
        minor = SRV_EMAIL_RESULT_SERVER_ERROR;
        goto ERROR_HANDLE;
    }

    mmi_asc_n_to_wcs(
        server_p->server_name,
        (CHAR*)info_p->server,
        SRV_EMAIL_MAX_SERVER_NAME_LEN);
    switch (info_p->sec_mode)
    {
        case CLOUD_PLUGIN_SEC_NONE:
            server_p->port_num = info_p->port_num;
            server_p->sec_mode = SRV_EMAIL_SEC_NONE;
            break;

        case CLOUD_PLUGIN_SEC_SSL_TLS:
            server_p->sec_port_num = info_p->port_num;
            server_p->sec_mode = SRV_EMAIL_SEC_SSL_TLS;
            break;

        case CLOUD_PLUGIN_SEC_STARTTLS:
            server_p->port_num = info_p->port_num;
            server_p->sec_mode = SRV_EMAIL_SEC_STARTTLS;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    OslMfree(info_p);

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        server_p->data_acct[i] = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, (cbm_sim_id_enum)i, 0, KAL_FALSE);
    }

    srv_email_ps_create_instance_req((U32)cntx_p, EMAIL_PS_PRTOTOCOL_TYPE_IMAP4);

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATING);

    return SRV_EMAIL_RESULT_WOULDBLOCK;

ERROR_HANDLE:

    if (info_p)
    {
        OslMfree(info_p);
    }

    srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    return SRV_EMAIL_RESULT_FAIL;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_created(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    srv_cbm_result_error_enum ret = SRV_CBM_OK;
    U8 app_id = CBM_INVALID_APP_ID;
    S32 major = SRV_EMAIL_MAIL_ERROR;
    S32 minor = 0;
    U32 dtcnt_id = comm_p->server_addr.data_acct[0];
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_NONE;
    cbm_app_info_struct app_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_FSM_CREATED,
        cntx_p,
        comm_p->destroy_flag,
        comm_p->abort_flag);

    if (comm_p->destroy_flag)
    {
        comm_p->destroy_flag = MMI_FALSE;
        return SRV_EMAIL_RESULT_FAIL;
    }

    if (comm_p->abort_flag)
    {
        comm_p->abort_flag = MMI_FALSE;
        SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    srv_dtcnt_get_sim_preference(&sim_type);
    if (sim_type != SRV_DTCNT_SIM_TYPE_NONE)
    {
        dtcnt_id = comm_p->server_addr.data_acct[sim_type - SRV_DTCNT_SIM_TYPE_1];
    }
    else
    {
        dtcnt_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, 0, MMI_FALSE);
    }

    app_info.app_icon_id = 0;
    app_info.app_str_id = 0;
    app_info.app_type = DTCNT_APPTYPE_EMAIL;

    cbm_register_app_id_with_app_info(&app_info, &app_id);
    if (app_id == CBM_INVALID_APP_ID)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_REGISTER_BEARER_INFO_FAIL, cntx_p, app_id, ret);
        minor = SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL;
        goto EXIT_HANDLE;
    }

    ret = srv_cbm_register_bearer_info(
            app_id,
            SRV_CBM_ACTIVATING | SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
            SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
            srv_email_nwk_cloud_fsm_bearer_info_ind,
            cntx_p);
    if (ret != SRV_CBM_OK)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_REGISTER_BEARER_INFO_FAIL, cntx_p, app_id, ret);
        minor = SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL;
        goto EXIT_HANDLE;
    }

    comm_p->nwk_acct_id = cbm_set_app_id(dtcnt_id, app_id);
    retval = srv_email_nwk_activate_bearer(comm_p->nwk_acct_id, &major, &minor);

EXIT_HANDLE:

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATING);

    if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        comm_p->wait_bearer_info = SRV_CBM_ACTIVATING | SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED;
    }
    else if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        if (app_id != CBM_INVALID_APP_ID)
        {
            srv_cbm_deregister_bearer_info(app_id);
            srv_cbm_deregister_bearer_event(app_id);
            cbm_deregister_app_id(app_id);
        }

        srv_email_set_error_cause(&comm_p->result, major, minor, NULL);
    }

    return retval;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_activated(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_sso_account_struct sso_acct;
    U32 len = sizeof(WCHAR) * (SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1);
    WCHAR *filename = NULL;
    MMI_BOOL is_file_needed = MMI_FALSE;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_WOULDBLOCK;
    S32 errcode = 0;
    MMI_BOOL is_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_ACTIVATED, cntx_p, comm_p->abort_flag);

    if (comm_p->abort_flag)
    {
        comm_p->abort_flag = MMI_FALSE;
        SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    is_valid = srv_sso_get_account(comm_p->provider_id, comm_p->cloud_acct_id, &sso_acct);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_GET_SSO_ACCOUNT,
        cntx_p,
        comm_p->provider_id,
        comm_p->cloud_acct_id,
        is_valid,
        sso_acct.is_login);

    if (!is_valid)
    {
        srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_MAIL_ERROR, SRV_EMAIL_RESULT_INVALID_ACCT, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

    if (!sso_acct.is_login)
    {
        srv_email_evt_backup_restore_ind_struct evt;

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_EMAIL_BACKUP_RESTORE_IND);
        evt.type = SRV_EMAIL_CLOUD_NOT_LOGIN;
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);

        SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CLOUD_QUERYING);
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    filename = (WCHAR*)OslMalloc(len);

    kal_wsprintf(
        filename,
        "%s%sReq%08X.dat",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        cntx_p);

    is_file_needed = srv_email_nwk_make_conn_req_file(
                        comm_p->provider_id,
                        (const CHAR*)comm_p->from_addr,
                        EMAIL_PS_PRTOTOCOL_TYPE_IMAP4,
                        NULL,
                        filename,
                        &errcode);

    if (is_file_needed)
    {
        if (errcode)
        {
            srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_FS_ERROR, errcode, NULL);
            retval = SRV_EMAIL_RESULT_FAIL;
        }
        else
        {
            srv_email_ps_connect_req(comm_p->ps_handle, comm_p->nwk_acct_id, &comm_p->server_addr, filename, NULL);
        }
    }
    else
    {
        srv_email_ps_connect_req(comm_p->ps_handle, comm_p->nwk_acct_id, &comm_p->server_addr, NULL, NULL);
    }

    OslMfree(filename);

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CONNECTING);
    srv_email_nwk_cloud_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_CONNECTING, NULL);

    return retval;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_connected(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_sso_auth_struct sso_auth;
    srv_sso_account_struct sso_acct;
    MMI_BOOL is_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_CONNECTED, cntx_p);

    is_valid = srv_sso_get_account(comm_p->provider_id, comm_p->cloud_acct_id, &sso_acct);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_GET_SSO_ACCOUNT,
        cntx_p,
        comm_p->provider_id,
        comm_p->cloud_acct_id,
        is_valid,
        sso_acct.is_login);

    if (!is_valid)
    {
        srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_MAIL_ERROR, SRV_EMAIL_RESULT_INVALID_ACCT, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

    if (!sso_acct.is_login)
    {
        srv_email_ps_disconnect_req(comm_p->ps_handle);
        SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
        return SRV_EMAIL_RESULT_SUCC;
    }
    
    sso_auth.provider_id = comm_p->provider_id;
    sso_auth.cloud_acct_id = comm_p->cloud_acct_id;
    sso_auth.ps_handle = comm_p->ps_handle;
    sso_auth.capa_mask = comm_p->capa_mask;
    sso_auth.from_addr_p = comm_p->from_addr;
    sso_auth.username_p = comm_p->auth.username;
    sso_auth.password_p = comm_p->auth.password;

    is_valid = srv_email_sso_send_auth_req(&sso_auth);

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_GET_SSO_CREDENTIAL,
        cntx_p,
        comm_p->provider_id,
        comm_p->cloud_acct_id,
        is_valid);

    if (!is_valid)
    {
        srv_email_set_error_cause(&comm_p->result, SRV_EMAIL_MAIL_ERROR, SRV_EMAIL_RESULT_AUTH_FAIL, NULL);
        return SRV_EMAIL_RESULT_FAIL;
    }

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_AUTHORIZING);
    srv_email_nwk_cloud_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_AUTHORIZING, NULL);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_authorized(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_AUTHORIZED, cntx_p);

    cntx_p->session.fldr_name[0] = 0;
    cntx_p->session.sync_with_server = MMI_FALSE;

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);
    return SRV_EMAIL_RESULT_SUCC;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_ready(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_READY, cntx_p);

    cb_p = srv_email_nwk_cloud_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    switch (cb_p->action)
    {
        case SRV_EMAIL_NWK_CONNECT:
            retval = srv_email_nwk_cloud_fsm_connect(cntx_p, (srv_email_nwk_cloud_conn_struct*)cb_p->action_data);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
            }
            else
            {
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);

                if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                {
                    srv_email_nwk_cloud_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_UPDATING, NULL);
                }
            }
            return retval;

        case SRV_EMAIL_NWK_CLD_APPEND:
        case SRV_EMAIL_NWK_CLD_GET_UID:
        case SRV_EMAIL_NWK_CLD_GET_MSG:
            if (cb_p->action == SRV_EMAIL_NWK_CLD_APPEND)
            {
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_SENDING);
            }
            else
            {
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_RECEIVING);
            }

            srv_email_set_error_cause(
                &comm_p->result,
                SRV_EMAIL_MAIL_ERROR,
                SRV_EMAIL_RESULT_SELECT_FOLDER_ERROR,
                NULL);
            return SRV_EMAIL_RESULT_FAIL;

        case SRV_EMAIL_NWK_DISCONNECT:
            ret = srv_email_nwk_cloud_is_pending_cb_empty(cntx_p);
            if (!ret)
            {
                cb_p->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;
                srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
                srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
            }
            else
            {
                srv_email_ps_disconnect_req(comm_p->ps_handle);
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_DISCONNECTING);
                srv_email_nwk_cloud_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_DISCONNECTING, NULL);
            }
            return SRV_EMAIL_RESULT_WOULDBLOCK;

        default:
            EMAILSRV_EXT_ASSERT(0, cb_p->action, 0, 0);
            break;
    }

    return SRV_EMAIL_RESULT_SUCC;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_updated(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_UPDATED, cntx_p);

    cb_p = srv_email_nwk_cloud_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    switch (cb_p->action)
    {
        case SRV_EMAIL_NWK_CONNECT:
            retval = srv_email_nwk_cloud_fsm_connect(cntx_p, (srv_email_nwk_cloud_conn_struct*)cb_p->action_data);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATING);
                return retval;
            }

            cb_p->state |= SRV_EMAIL_NWK_CB_CONNECTED;

            cb_p = srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
            if (cb_p)
            {
                srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
            }

            return SRV_EMAIL_RESULT_WOULDBLOCK;

        case SRV_EMAIL_NWK_CLD_APPEND:
            retval = srv_email_nwk_cloud_fsm_append(cntx_p, (srv_email_nwk_send_struct*)cb_p->action_data);
            SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_SENDING);
            return retval;

        case SRV_EMAIL_NWK_CLD_GET_UID:
        case SRV_EMAIL_NWK_CLD_GET_MSG:
            retval = srv_email_nwk_cloud_fsm_retrieve(cntx_p, (srv_email_nwk_cloud_retr_struct*)cb_p->action_data);
            SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_RECEIVING);
            return retval;

        case SRV_EMAIL_NWK_DISCONNECT:
            ret = srv_email_nwk_cloud_is_pending_cb_empty(cntx_p);
            if (!ret)
            {
                cb_p->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;
                srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
                srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
            }
            else
            {
                srv_email_nwk_cloud_cntx_free(cntx_p);
                srv_email_ps_disconnect_req(comm_p->ps_handle);
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_DISCONNECTING);
                srv_email_nwk_cloud_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_DISCONNECTING, NULL);
            }
            return SRV_EMAIL_RESULT_WOULDBLOCK;

        default:
            EMAILSRV_EXT_ASSERT(0, cb_p->action, 0, 0);
            break;
    }

    return SRV_EMAIL_RESULT_SUCC;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_sent(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_SENT, cntx_p);

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);

    cb_p = srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
    if (cb_p)
    {
        srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_received(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_RECEIVED, cntx_p);

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);

    cb_p = srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
    if (cb_p)
    {
        srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm_disconnected(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_DISCONNECTED, cntx_p);

    cb_p = srv_email_nwk_cloud_get_running_cb(cntx_p);
    EMAILSRV_ASSERT(cb_p);

    cb_p->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;

    cb_p = srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
    if (cb_p)
    {
        srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
    }

    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


static srv_email_result_enum srv_email_nwk_cloud_err_rsp(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        SRV_EMAIL_CLD_FSM_ERROR,
        cntx_p,
        cntx_p->nwk_state,
        comm_p->result.major,
        comm_p->result.minor);

    switch (cntx_p->nwk_state)
    {
        case SRV_EMAIL_NWK_STATE_AUTHORIZING:
            if (comm_p->result.major == SRV_EMAIL_MAIL_ERROR &&
                comm_p->result.minor == SRV_EMAIL_RESULT_INVALID_AUTH_COOKIE)
            {
                srv_email_ps_disconnect_req(comm_p->ps_handle);

                comm_p->sso_req_id = srv_sso_refresh_credentials(
                                        comm_p->provider_id,
                                        comm_p->cloud_acct_id,
                                        srv_email_nwk_cloud_sso_refresh_done,
                                        cntx_p);

                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    SRV_EMAIL_CLD_REFRESH_SSO_CREDENTIAL,
                    cntx_p,
                    comm_p->provider_id,
                    comm_p->cloud_acct_id,
                    comm_p->sso_req_id);

                memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
                comm_p->result.result = MMI_TRUE;

                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING);
                return SRV_EMAIL_RESULT_WOULDBLOCK;
            }
            /* No break */

        case SRV_EMAIL_NWK_STATE_INIT:
        case SRV_EMAIL_NWK_STATE_CREATING:
        case SRV_EMAIL_NWK_STATE_CREATED:
        case SRV_EMAIL_NWK_STATE_ACTIVATING:
        case SRV_EMAIL_NWK_STATE_ACTIVATED:
        case SRV_EMAIL_NWK_STATE_CONNECTING:
        case SRV_EMAIL_NWK_STATE_READY:
        case SRV_EMAIL_NWK_STATE_CLOUD_QUERYING:
        case SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING:
            if (cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_INIT ||
                cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_CREATING ||
                cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_CREATED)
            {
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_INIT);
            }
            else if (cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_ACTIVATING ||
                     cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_ACTIVATED)
            {
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
            }
            else
            {
                ret = srv_email_nwk_is_bearer_activated(comm_p->nwk_acct_id);
                if (ret)
                {
                    if (cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING)
                    {
                        srv_email_evt_backup_restore_ind_struct evt;

                        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_EMAIL_BACKUP_RESTORE_IND);
                        evt.type = SRV_EMAIL_CLOUD_COOKIE_EXPIRY;
                        MMI_FRM_CB_EMIT_POST_EVENT(&evt);

                        memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
                        comm_p->result.result = MMI_TRUE;

                        SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CLOUD_QUERYING);
                        return SRV_EMAIL_RESULT_WOULDBLOCK;
                    }

                    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
                }
                else
                {
                    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
                }
            }

            cb_p = srv_email_nwk_cloud_get_running_cb(cntx_p);
            while (cb_p)
            {
                cb_p = srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
            }
            break;

        case SRV_EMAIL_NWK_STATE_UPDATING:
            SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_READY);
            srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
            break;

        case SRV_EMAIL_NWK_STATE_SENDING:
        case SRV_EMAIL_NWK_STATE_RECEIVING:
            SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
            srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_TRUE);
            break;

        case SRV_EMAIL_NWK_STATE_UPDATED:
        case SRV_EMAIL_NWK_STATE_DISCONNECTING:
        default:
            break;
    }

    cb_p = srv_email_nwk_cloud_get_running_cb(cntx_p);
    if (cb_p)
    {
        srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
    }

    memset(&comm_p->result, 0, sizeof(srv_email_result_struct));
    comm_p->result.result = MMI_TRUE;

    return SRV_EMAIL_RESULT_FAIL;
}


static srv_email_result_enum srv_email_nwk_cloud_fsm(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)ptr;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_FAIL;
    MMI_BOOL run_fsm = cntx_p->common.result.result;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (run_fsm)
    {
        switch (cntx_p->nwk_state)
        {
            case SRV_EMAIL_NWK_STATE_INIT:
                retval = srv_email_nwk_cloud_fsm_init(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_CREATING:
            case SRV_EMAIL_NWK_STATE_CREATED:
                retval = srv_email_nwk_cloud_fsm_created(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_ACTIVATING:
            case SRV_EMAIL_NWK_STATE_ACTIVATED:
                retval = srv_email_nwk_cloud_fsm_activated(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_CONNECTING:
                retval = srv_email_nwk_cloud_fsm_connected(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_AUTHORIZING:
                retval = srv_email_nwk_cloud_fsm_authorized(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_READY:
                retval = srv_email_nwk_cloud_fsm_ready(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_UPDATING:
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_UPDATED);
                /* No break here */

            case SRV_EMAIL_NWK_STATE_UPDATED:
                retval = srv_email_nwk_cloud_fsm_updated(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_SENDING:
                retval = srv_email_nwk_cloud_fsm_sent(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_RECEIVING:
                retval = srv_email_nwk_cloud_fsm_received(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_DISCONNECTING:
                retval = srv_email_nwk_cloud_fsm_disconnected(cntx_p);
                break;

            case SRV_EMAIL_NWK_STATE_CLOUD_QUERYING:
            case SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING:
                ret = srv_email_nwk_is_bearer_activated(cntx_p->common.nwk_acct_id);
                if (ret)
                {
                    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
                }
                else
                {
                    SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
                }
                retval = SRV_EMAIL_RESULT_SUCC;
                break;

            default:
                break;
        }

        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            run_fsm = MMI_FALSE;
        }
    }

    if (retval != SRV_EMAIL_RESULT_SUCC &&
        retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        retval = srv_email_nwk_cloud_err_rsp(cntx_p);
    }

    return retval;
}

#define SRV_EMAIL_NWK_CLOUD_EXT_FUNC

void srv_email_nwk_cloud_fsm_schdl(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)user_data;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return;
    }

    if (cntx_p->common.schdl_flag)
    {
        cntx_p->common.schdl_flag = MMI_FALSE;
        srv_email_nwk_cloud_fsm(cntx_p);
    }
}


void srv_email_nwk_cloud_fsm_abort(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_ABORT, cntx_p, cntx_p->nwk_state);

    cb_p = srv_email_nwk_cloud_update_running_cb(cntx_p, MMI_FALSE);

    switch (cntx_p->nwk_state)
    {
        case SRV_EMAIL_NWK_STATE_CREATING:
        case SRV_EMAIL_NWK_STATE_ACTIVATING:
            if (!cb_p)
            {
                comm_p->abort_flag = MMI_TRUE;
            }
            break;

        case SRV_EMAIL_NWK_STATE_CONNECTING:
        case SRV_EMAIL_NWK_STATE_AUTHORIZING:
            if (!cb_p)
            {
                srv_email_ps_abort_req(comm_p->ps_handle);
                srv_email_ps_disconnect_req(comm_p->ps_handle);
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
            }
            break;

        case SRV_EMAIL_NWK_STATE_CLOUD_REFRESHING:
            srv_sso_cancel(comm_p->sso_req_id);
            /* No break */
        case SRV_EMAIL_NWK_STATE_CLOUD_QUERYING:
        case SRV_EMAIL_NWK_STATE_QUERYING:
            if (!cb_p)
            {
                srv_email_ps_disconnect_req(comm_p->ps_handle);
                SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
            }
            break;

        case SRV_EMAIL_NWK_STATE_INIT:
        case SRV_EMAIL_NWK_STATE_CREATED:
        case SRV_EMAIL_NWK_STATE_ACTIVATED:
        case SRV_EMAIL_NWK_STATE_READY:
        case SRV_EMAIL_NWK_STATE_UPDATED:
        case SRV_EMAIL_NWK_STATE_UPDATING:
        case SRV_EMAIL_NWK_STATE_SENDING:
        case SRV_EMAIL_NWK_STATE_RECEIVING:
        case SRV_EMAIL_NWK_STATE_DISCONNECTING:
            switch (cntx_p->nwk_state)
            {
                case SRV_EMAIL_NWK_STATE_UPDATING:
                    srv_email_nwk_cloud_fsm_connect_abort(cntx_p);
            	    break;

                case SRV_EMAIL_NWK_STATE_SENDING:
                    srv_email_nwk_cloud_fsm_append_abort(cntx_p);
            	    break;

                case SRV_EMAIL_NWK_STATE_RECEIVING:
                    srv_email_nwk_cloud_fsm_retrieve_abort(cntx_p);
                    break;

                default:
                    srv_email_nwk_cloud_stop_job(cntx_p);
                    break;
            }

            if (cb_p)
            {
                srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
            }
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, cntx_p->nwk_state, 0, 0);
            break;
    }
}


srv_email_result_enum srv_email_nwk_cloud_fsm_retry(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_RETRY, cntx_p, cntx_p->nwk_state);

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_CLOUD_QUERYING)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_CLOUD_QUERYING,
            0);
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


MMI_BOOL srv_email_nwk_cloud_create_instance_rsp_hdlr(email_ps_create_instance_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = (srv_email_nwk_cloud_cntx_struct*)rsp_p->req_id;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    MMI_BOOL ret = MMI_FALSE;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_email_nwk_cloud_is_cntx_valid(cntx_p);
    if (!ret)
    {
        return MMI_FALSE;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_CREATING)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            0,
            SRV_EMAIL_NWK_STATE_CREATING,
            0);
        return MMI_TRUE;
    }

    comm_p = &cntx_p->common;

    if (rsp_p->result.ret)
    {
        comm_p->ps_handle = rsp_p->handle;
    }
    else
    {
        srv_email_get_ps_error(&rsp_p->result, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, rsp_p->result.err_string);
    }

    srv_email_nwk_cloud_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_connect_rsp_hdlr(email_ps_conn_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(rsp_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_CONNECTING)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            0,
            SRV_EMAIL_NWK_STATE_CONNECTING,
            0);
        return MMI_TRUE;
    }

    comm_p = &cntx_p->common;

    if (rsp_p->result.ret)
    {
        comm_p->capa_mask = rsp_p->capa_mask;
    }
    else
    {
        srv_email_get_ps_error(&rsp_p->result, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, rsp_p->result.err_string);
    }

    srv_email_nwk_cloud_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_disconnect_rsp_hdlr(email_ps_disconn_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(rsp_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_DISCONNECTING)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            0,
            SRV_EMAIL_NWK_STATE_DISCONNECTING,
            0);
        return MMI_TRUE;
    }

    if (!rsp_p->result.ret)
    {
        /* Process this case as success */
    }

    srv_email_nwk_cloud_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_auth_rsp_hdlr(email_ps_auth_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(rsp_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_AUTHORIZING)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            0,
            SRV_EMAIL_NWK_STATE_AUTHORIZING,
            0);
        return MMI_TRUE;
    }

    comm_p = &cntx_p->common;

    if (!rsp_p->result.ret)
    {
        srv_email_get_ps_error(&rsp_p->result, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, rsp_p->result.err_string);
    }

    srv_email_nwk_cloud_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_fldr_open_rsp_hdlr(email_ps_fld_open_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    srv_email_nwk_cloud_session_struct *sess_p = NULL;
    srv_email_nwk_cloud_state_struct *state_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(rsp_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    comm_p = &cntx_p->common;
    sess_p = &cntx_p->session;
    state_p = &cntx_p->state;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_UPDATING,
            SRV_EMAIL_NWK_SUB_STATE_UPDATE_OPEN_FOLDER);
        return MMI_TRUE;
    }

    if (rsp_p->result.ret)
    {
        sess_p->total_msg_num = rsp_p->total_msg_num;
    }
    else
    {
        if (state_p->fldr_create_flag)
        {
            state_p->fldr_open_fail_flag = MMI_TRUE;
            state_p->fldr_create_flag = MMI_FALSE;
        }
        else
        {
            srv_email_get_ps_error(&rsp_p->result, &major, &minor);
            srv_email_set_error_cause(&comm_p->result, major, minor, rsp_p->result.err_string);
        }
    }

    srv_email_nwk_cloud_conn_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_fldr_create_rsp_hdlr(email_ps_fld_create_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(rsp_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    comm_p = &cntx_p->common;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_UPDATING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_UPDATE_CREATE_FOLDER)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_UPDATING,
            SRV_EMAIL_NWK_SUB_STATE_UPDATE_CREATE_FOLDER);
        return MMI_TRUE;
    }

    if (!rsp_p->result.ret)
    {
        srv_email_get_ps_error(&rsp_p->result, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, rsp_p->result.err_string);
    }

    srv_email_nwk_cloud_conn_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_append_mail_rsp_hdlr(email_ps_msg_append_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(rsp_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    comm_p = &cntx_p->common;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_SENDING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_SEND_APPEND)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_SENDING,
            SRV_EMAIL_NWK_SUB_STATE_SEND_APPEND);
        return MMI_TRUE;
    }

    if (!rsp_p->result.ret)
    {
        srv_email_get_ps_error(&rsp_p->result, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, rsp_p->result.err_string);
    }

    srv_email_nwk_cloud_appd_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_list_uid_rsp_hdlr(email_ps_msg_uid_list_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(rsp_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    comm_p = &cntx_p->common;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_UID)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_UPDATING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_UID);
        return MMI_TRUE;
    }

    if (!rsp_p->result.ret)
    {
        srv_email_get_ps_error(&rsp_p->result, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, rsp_p->result.err_string);
    }

    srv_email_nwk_cloud_retr_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_fetch_mail_rsp_hdlr(email_ps_msg_fetch_rsp_struct *rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(rsp_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    comm_p = &cntx_p->common;

    if (cntx_p->nwk_state != SRV_EMAIL_NWK_STATE_RECEIVING ||
        cntx_p->sub_state != SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE)
    {
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL,
            SRV_EMAIL_CLD_STATE_INVALID,
            cntx_p,
            cntx_p->nwk_state,
            cntx_p->sub_state,
            SRV_EMAIL_NWK_STATE_RECEIVING,
            SRV_EMAIL_NWK_SUB_STATE_RECV_RECEIVE);
        return MMI_TRUE;
    }

    if (!rsp_p->result.ret)
    {
        srv_email_get_ps_error(&rsp_p->result, &major, &minor);
        srv_email_set_error_cause(&comm_p->result, major, minor, rsp_p->result.err_string);
    }

    srv_email_nwk_cloud_retr_fsm(cntx_p);
    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_disconnect_ind_hdlr(email_ps_disconn_ind_struct *ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = NULL;
    srv_email_nwk_cb_struct *cb_p = NULL;
    MMI_BOOL ret = MMI_TRUE;
    MMI_BOOL need_update = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(ind_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_CLD_FSM_DISCONNECT_IND, cntx_p, cntx_p->nwk_state);

    comm_p = &cntx_p->common;

    switch (cntx_p->nwk_state)
    {
        case SRV_EMAIL_NWK_STATE_AUTHORIZING:
        case SRV_EMAIL_NWK_STATE_UPDATING:
        case SRV_EMAIL_NWK_STATE_SENDING:
        case SRV_EMAIL_NWK_STATE_RECEIVING:
            switch (cntx_p->nwk_state)
            {
                case SRV_EMAIL_NWK_STATE_UPDATING:
                    srv_email_nwk_cloud_fsm_connect_abort(cntx_p);
            	    break;

                case SRV_EMAIL_NWK_STATE_SENDING:
                    srv_email_nwk_cloud_fsm_append_abort(cntx_p);
            	    break;

                case SRV_EMAIL_NWK_STATE_RECEIVING:
                    srv_email_nwk_cloud_fsm_retrieve_abort(cntx_p);
                    break;

                default:
                    break;
            }

            need_update = MMI_TRUE;
            break;

        default:
            break;
    }

    ret = srv_email_nwk_is_bearer_activated(comm_p->nwk_acct_id);
    if (ret)
    {
        SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_ACTIVATED);
    }
    else
    {
        SRV_EMAIL_NWK_CLOUD_SET_STATE(cntx_p, SRV_EMAIL_NWK_STATE_CREATED);
    }

    if (need_update)
    {
        srv_email_set_error_cause(
            &comm_p->result,
            SRV_EMAIL_MAIL_ERROR,
            SRV_EMAIL_RESULT_NETWORK_ERROR,
            NULL);

        cb_p = srv_email_nwk_cloud_update_running_cb_for_disc_ind(cntx_p);
        if (cb_p)
        {
            srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);
        }
        comm_p->result.result = MMI_TRUE;
    }

    srv_email_nwk_cloud_cb_process_notify(cntx_p, NULL, SRV_EMAIL_NWK_DISCONNECTED, NULL);

    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_imap4_push_ind_hdlr(email_ps_imap_push_ind_struct *ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = srv_email_nwk_cloud_get_cntx_by_ps_handle(ind_p->handle);
    if (!cntx_p)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

#endif /* __SMS_CLOUD_SUPPORT__ */

#endif /* defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__) */

