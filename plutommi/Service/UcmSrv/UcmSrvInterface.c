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
 *  UcmSrvInterface.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM service external interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "string.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_cb_mgr_gprot.h"
#include "UcmSrvGprot.h"
#include "UcmSrvProt.h"

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_act_permit_fail_action_notify
 * DESCRIPTION
 *  The function to perform actions in srv_ucm_act_opcode_enum
 * PARAMETERS
 *  act_op:          [IN]        Current action
 *  act_req_data:    [IN]        Action request data
 *  permit_result:   [IN]        Permit result
 *  is_notify_stat:  [IN]        MMI_TRUE : need to notify start
 *                               MMI_FALSE: do NOT need to notify start
 *  is_intercept:    [IN]        MMI_TRUE: because it is intercepped by other
 *                               service/app, same as permit fail just print
 *                               different TRACE
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_act_permit_fail_action_notify(
                srv_ucm_act_opcode_enum act_op, 
                void *act_req_data, 
                srv_ucm_result_enum permit_result, 
                MMI_BOOL is_notify_start, 
                MMI_BOOL is_intercept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_rsp_struct act_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_intercept)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_INTERCEPTED);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_FAIL, permit_result);
    }

    memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

    /* Action start notify */
    if (MMI_TRUE == is_notify_start)
    {
        srv_ucm_send_act_notify(act_op, act_op, SRV_UCM_ACT_NOTIFY_TYPE_START, act_req_data);
    }

    /* Action end notify */
    act_rsp.result_info.result = permit_result;
    if (SRV_UCM_RESULT_OK != permit_result)
    {
        /* copy it */
        mmi_ucs2ncpy(
            (CHAR *)act_rsp.result_info.error_msg, 
            (CHAR *)GetString(srv_ucm_query_error_message(permit_result)), 
            SRV_UCM_MAX_ERR_MSG_LEN);
    }
    srv_ucm_send_act_notify(act_op, act_op, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&act_rsp);

    /* Action response callback */
    srv_ucm_send_act_response(act_op, (void *)&act_rsp);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_act_request
 * DESCRIPTION
 *  The function to perform actions in srv_ucm_act_opcode_enum
 * PARAMETERS
 *  act_op:          [IN]        Action op-code
 *  act_data:        [IN]        Action data
 *  user_data:       [IN]        User data
 *  result_callback: [IN]        Result callback function
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_act_request(srv_ucm_act_opcode_enum act_op, void *act_data, void *user_data, mmi_proc_func result_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dial_act_req_struct *dial_req = NULL;
    srv_ucm_single_call_act_req_struct *single_call_req = NULL;
    srv_ucm_single_group_act_req_struct *single_group_req = NULL;
    srv_ucm_multiple_group_act_req_struct *multiple_group_req = NULL;
#if (defined(__MMI_UCM_DEFLECT__) || defined(__MMI_UCM_TRANSFER__))
    srv_ucm_cd_or_ct_act_req_struct *cd_or_ct_req = NULL;
#endif
#ifdef __MMI_UCM_ECT__
    srv_ucm_ect_act_req_struct *ect_req = NULL;
#endif
    srv_ucm_hold_and_dial_act_req_struct *hold_and_dial_req = NULL;
    srv_ucm_hold_and_accept_act_req_struct *hold_and_accept_req = NULL;
    srv_ucm_dtmf_struct *start_dtmf_req = NULL;
    srv_ucm_act_rsp_struct act_rsp;
    srv_ucm_result_enum permit = SRV_UCM_RESULT_OK;
    srv_ucm_index_info_struct index;
    srv_ucm_index_info_struct other_index;
    srv_ucm_act_result_evt_struct evt;
    srv_ucm_dtmf_digits_struct *send_dtmf_digits_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST, act_op, result_callback);

    /* If there is any action in progress, only END_ALL_PROCESSING is allowed when permitted */
    if (((act_op != SRV_UCM_END_ALL_PROCESSING_ACT) &&
        (g_ucm_srv_p->call_misc.curr_action != SRV_UCM_NO_ACT)) ||
        ((act_op == SRV_UCM_END_ALL_PROCESSING_ACT) &&
        (srv_ucm_end_all_processing_act_permit() != SRV_UCM_RESULT_OK)))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_BUSY, g_ucm_srv_p->call_misc.curr_action);

        if (result_callback != NULL)
        {
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));
            act_rsp.result_info.result = SRV_UCM_RESULT_UCM_BUSY;
            mmi_ucs2ncpy((CHAR *)act_rsp.result_info.error_msg, (CHAR *)GetString(srv_ucm_query_error_message(act_rsp.result_info.result)), SRV_UCM_MAX_ERR_MSG_LEN);
            
            /* Send post event to notify the action result */
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_ACTION_RESULT);
            evt.act_op = act_op;
            evt.act_result = OslMalloc(sizeof(srv_ucm_act_rsp_struct));
            memset(evt.act_result, 0, sizeof(srv_ucm_act_rsp_struct));
            MMI_FRM_POST_EVENT_EX((mmi_event_struct *)&evt, result_callback, (void *)user_data, srv_ucm_post_event_callback, (void *)evt.act_result);
        }
        return;
    }

    if ((act_op != SRV_UCM_START_DTMF_ACT) && (act_op != SRV_UCM_STOP_DTMF_ACT))
    {
        g_ucm_srv_p->act_result_callback = result_callback;
        g_ucm_srv_p->call_misc.curr_action = act_op;
    }

    switch (act_op)
    {
        case SRV_UCM_DIAL_ACT:

            dial_req = (srv_ucm_dial_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Interception */
            if ((dial_req->is_ip_dial == MMI_FALSE) &&
                (srv_ucm_intercept(dial_req->call_type, (U16 *)dial_req->num_uri, dial_req->module_id) == MMI_TRUE))
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_DIAL_ACT, 
                        dial_req, 
                        SRV_UCM_RESULT_OK, 
                        MMI_TRUE, 
                        MMI_TRUE);
                return;
            }

            /* Permit */
            permit = srv_ucm_dial_act_permit(dial_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_DIAL_ACT, 
                        dial_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Abort the ongoing auto redial action */
            srv_ucm_auto_redial_abort();

            /* Perform the dial action */
            g_ucm_srv_p->dial_info.module_id = dial_req->module_id;
            g_ucm_srv_p->dial_info.dial_type = dial_req->call_type;
            g_ucm_srv_p->dial_info.is_ip_dial= dial_req->is_ip_dial;
            g_ucm_srv_p->dial_info.phb_data = dial_req->phb_data;
            memset(g_ucm_srv_p->dial_info.num_uri, 0, SRV_UCM_MAX_NUM_URI_LEN + 1);
            mmi_ucs2_n_to_asc((CHAR *)g_ucm_srv_p->dial_info.num_uri, (CHAR *)dial_req->num_uri, SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
            srv_ucm_dial_action();
            break;

        case SRV_UCM_ACCEPT_ACT:

            single_call_req = (srv_ucm_single_call_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_accept_act_permit(single_call_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_ACCEPT_ACT, 
                        single_call_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the accept action */
            srv_ucm_accept_action();
            break;

        case SRV_UCM_HOLD_ACT:

            single_group_req = (srv_ucm_single_group_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_hold_act_permit(single_group_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_HOLD_ACT, 
                        single_group_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the hold action */
            srv_ucm_query_group_index_by_group_id(single_group_req->action_group, single_group_req->call_type, &index.group_index);
            srv_ucm_hold_action(index.group_index);
            break;

        case SRV_UCM_RETRIEVE_ACT:

            single_group_req = (srv_ucm_single_group_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_retrieve_act_permit(single_group_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_RETRIEVE_ACT, 
                        single_group_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the retrieve action */
            srv_ucm_query_group_index_by_group_id(single_group_req->action_group, single_group_req->call_type, &index.group_index);
            srv_ucm_retrieve_action(index.group_index);
            break;

        case SRV_UCM_SWAP_ACT:

            multiple_group_req = (srv_ucm_multiple_group_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Compound action start notify */
            if (!(multiple_group_req->active_call_type & multiple_group_req->other_call_type))
            {
                srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_SWAP_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, multiple_group_req);
            }

            /* Permit */
            permit = srv_ucm_swap_act_permit(multiple_group_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                MMI_BOOL is_notify_start = MMI_FALSE;
                if (multiple_group_req->active_call_type & multiple_group_req->other_call_type)
                {
                    is_notify_start = MMI_TRUE;
                }
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_SWAP_ACT, 
                        multiple_group_req, 
                        permit, 
                        is_notify_start, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the swap action */
            srv_ucm_query_group_index_by_group_id(multiple_group_req->active_group, multiple_group_req->active_call_type, &index.group_index);
            srv_ucm_query_group_index_by_group_id(multiple_group_req->other_group, multiple_group_req->other_call_type, &other_index.group_index);
            srv_ucm_swap_action(index.group_index, other_index.group_index);

            /* Action start notify */
            if (multiple_group_req->active_call_type & multiple_group_req->other_call_type)
            {
                single_group_req = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                memset(single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
                single_group_req->call_type = multiple_group_req->active_call_type;
                single_group_req->action_group = multiple_group_req->active_group;
                srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_HOLD_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, single_group_req);
                OslMfree(single_group_req);
            }
            break;

        case SRV_UCM_CONFERENCE_ACT:

            multiple_group_req = (srv_ucm_multiple_group_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_conference_act_permit(multiple_group_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_CONFERENCE_ACT, 
                        multiple_group_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the conference action */
            srv_ucm_query_group_index_by_group_id(multiple_group_req->active_group, multiple_group_req->active_call_type, &index.group_index);
            srv_ucm_query_group_index_by_group_id(multiple_group_req->other_group, multiple_group_req->other_call_type, &other_index.group_index);
            srv_ucm_conference_action(index.group_index, other_index.group_index);
            break;

        case SRV_UCM_SPLIT_ACT:

            single_call_req = (srv_ucm_single_call_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_split_act_permit(single_call_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_SPLIT_ACT, 
                        single_call_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the split action */
            srv_ucm_query_index_by_id(&single_call_req->action_uid, &index);
            srv_ucm_split_action(index.group_index, index.call_index);
            break;

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_DEFLECT_ACT:

            cd_or_ct_req = (srv_ucm_cd_or_ct_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_deflect_act_permit(cd_or_ct_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_DEFLECT_ACT, 
                        cd_or_ct_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the deflect action */
            memset(g_ucm_srv_p->dial_info.num_uri, 0, SRV_UCM_MAX_NUM_URI_LEN + 1);
            mmi_ucs2_n_to_asc((CHAR *)g_ucm_srv_p->dial_info.num_uri, (CHAR *)cd_or_ct_req->num_uri, SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
            srv_ucm_deflect_action();
            break;
    #endif /* __MMI_UCM_DEFLECT__ */

    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_TRANSFER_ACT:

            cd_or_ct_req = (srv_ucm_cd_or_ct_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_transfer_act_permit(cd_or_ct_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_TRANSFER_ACT, 
                        cd_or_ct_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the transfer action */
            memset(g_ucm_srv_p->dial_info.num_uri, 0, SRV_UCM_MAX_NUM_URI_LEN + 1);
            mmi_ucs2_n_to_asc((CHAR *)g_ucm_srv_p->dial_info.num_uri, (CHAR *)cd_or_ct_req->num_uri, SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
            srv_ucm_query_index_by_id(&cd_or_ct_req->action_uid, &index);
            srv_ucm_transfer_action(index.group_index, index.call_index);
            break;
    #endif /* __MMI_UCM_TRANSFER__ */

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT:

            ect_req = (srv_ucm_ect_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_ect_act_permit(ect_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, 
                        ect_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the ect action */
            srv_ucm_query_group_index_by_group_id(ect_req->first_group, ect_req->first_call_type, &index.group_index);
            srv_ucm_query_group_index_by_group_id(ect_req->second_group, ect_req->second_call_type, &other_index.group_index);
            srv_ucm_ect_action(index.group_index, other_index.group_index);
            break;
    #endif /* __MMI_UCM_ECT__ */

        case SRV_UCM_END_SINGLE_ACT:

            single_call_req = (srv_ucm_single_call_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_end_single_act_permit(single_call_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_SINGLE_ACT, 
                        single_call_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the end single action */
            srv_ucm_query_index_by_id(&single_call_req->action_uid, &index);
            srv_ucm_end_single_action(index.group_index, index.call_index);
            break;

        case SRV_UCM_END_CONFERENCE_ACT:

            single_group_req = (srv_ucm_single_group_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_end_conference_act_permit(single_group_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_CONFERENCE_ACT, 
                        single_group_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the conference action */
            srv_ucm_query_group_index_by_group_id(single_group_req->action_group, single_group_req->call_type, &index.group_index);
            srv_ucm_end_conference_action(index.group_index);
            break;

        case SRV_UCM_END_ALL_ACT:

            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_end_all_act_permit();

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_ACT, 
                        NULL, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the end all action */
            srv_ucm_end_all_action();
            break;

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
        case SRV_UCM_END_ALL_ACTIVE_ACT:

            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            /* Permit */
            permit = srv_ucm_end_all_active_act_permit();

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_ACTIVE_ACT, 
                        NULL, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the end all active action */
            srv_ucm_end_all_active_action();
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__ */

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
        case SRV_UCM_END_ALL_HELD_ACT:

            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_end_all_held_act_permit();
            
            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_HELD_ACT, 
                        NULL, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);
            
            /* Perform the end all held action */
            srv_ucm_end_all_held_action();
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__ */

        case SRV_UCM_END_ALL_PROCESSING_ACT:

            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_end_all_processing_act_permit();

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_PROCESSING_ACT, 
                        NULL, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the end all processing action */
            srv_ucm_end_all_processing_action();
            break;

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__
        case SRV_UCM_END_ALL_AND_DIAL_ACT:

            dial_req = (srv_ucm_dial_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Compound action start notify */
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_END_ALL_AND_DIAL_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, dial_req);

            /* Interception */
            if ((dial_req->is_ip_dial == MMI_FALSE) &&
                (srv_ucm_intercept(dial_req->call_type, (U16 *)dial_req->num_uri, dial_req->module_id) == MMI_TRUE))
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_AND_DIAL_ACT, 
                        NULL, 
                        SRV_UCM_RESULT_OK, 
                        MMI_FALSE, 
                        MMI_TRUE);
                return;
            }

            /* Permit */
            permit = srv_ucm_end_all_and_dial_act_permit(dial_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_AND_DIAL_ACT, 
                        NULL, 
                        permit, 
                        MMI_FALSE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Abort the ongoing auto redial action */
            srv_ucm_auto_redial_abort();

            /* Perform the end all and dial action */
            g_ucm_srv_p->dial_info.module_id = dial_req->module_id;
            g_ucm_srv_p->dial_info.dial_type = dial_req->call_type;
            g_ucm_srv_p->dial_info.is_ip_dial= dial_req->is_ip_dial;
            memset(g_ucm_srv_p->dial_info.num_uri, 0, SRV_UCM_MAX_NUM_URI_LEN + 1);
            mmi_ucs2_n_to_asc((CHAR *)g_ucm_srv_p->dial_info.num_uri, (CHAR *)dial_req->num_uri, SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
            g_ucm_srv_p->dial_info.is_wait_dial = MMI_TRUE;
            g_ucm_srv_p->dial_info.phb_data = dial_req->phb_data;

            srv_ucm_end_all_action();
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__ */

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__
        case SRV_UCM_END_ALL_AND_ACCEPT_ACT:

            single_call_req = (srv_ucm_single_call_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Compound action start notify */
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_END_ALL_AND_ACCEPT_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, single_call_req);

            /* Permit */
            permit = srv_ucm_end_all_and_accept_act_permit(single_call_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_AND_ACCEPT_ACT, 
                        NULL, 
                        permit, 
                        MMI_FALSE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the end all and accept action */
            srv_ucm_end_all_and_accept_action();
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__ */

    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
        case SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT:

            single_group_req = (srv_ucm_single_group_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Compound action start notify */
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, single_group_req);

            /* Permit */
            permit = srv_ucm_end_all_active_and_retrieve_act_permit(single_group_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, 
                        NULL, 
                        permit, 
                        MMI_FALSE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the end all active and retrieve action */
            srv_ucm_query_group_index_by_group_id(single_group_req->action_group, single_group_req->call_type, &index.group_index);
            srv_ucm_end_all_active_and_retrieve_action(index.group_index);
            break;
    #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */

        case SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT:

            single_call_req = (srv_ucm_single_call_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Compound action start notify */
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, single_call_req);

            /* Permit */
            permit = srv_ucm_end_all_active_and_accept_act_permit(single_call_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, 
                        NULL, 
                        permit, 
                        MMI_FALSE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the end all active and accept action */
            srv_ucm_end_all_active_and_accept_action();
            break;

        case SRV_UCM_HOLD_AND_DIAL_ACT:

            hold_and_dial_req = (srv_ucm_hold_and_dial_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Compound action start notify */
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_HOLD_AND_DIAL_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, hold_and_dial_req);

            /* Interception */
            if ((hold_and_dial_req->is_ip_dial == MMI_FALSE) &&
                (srv_ucm_intercept(hold_and_dial_req->dial_call_type, (U16 *)hold_and_dial_req->num_uri, hold_and_dial_req->module_id) == MMI_TRUE))
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_HOLD_AND_DIAL_ACT, 
                        NULL, 
                        SRV_UCM_RESULT_OK, 
                        MMI_FALSE, 
                        MMI_TRUE);
                return;
            }

            /* Permit */
            permit = srv_ucm_hold_and_dial_act_permit(hold_and_dial_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_HOLD_AND_DIAL_ACT, 
                        NULL, 
                        permit, 
                        MMI_FALSE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Abort the ongoing auto redial action */
            srv_ucm_auto_redial_abort();

            /* Perform the hold and dial action */
            g_ucm_srv_p->dial_info.module_id = hold_and_dial_req->module_id;
            g_ucm_srv_p->dial_info.dial_type = hold_and_dial_req->dial_call_type;
            g_ucm_srv_p->dial_info.is_ip_dial= hold_and_dial_req->is_ip_dial;
            memset(g_ucm_srv_p->dial_info.num_uri, 0, SRV_UCM_MAX_NUM_URI_LEN + 1);
            mmi_ucs2_n_to_asc((CHAR *)g_ucm_srv_p->dial_info.num_uri, (CHAR *)hold_and_dial_req->num_uri, SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
            g_ucm_srv_p->dial_info.is_wait_dial = MMI_TRUE;
            g_ucm_srv_p->dial_info.phb_data = hold_and_dial_req->phb_data;

            srv_ucm_query_group_index_by_group_id(hold_and_dial_req->active_group, hold_and_dial_req->active_call_type, &index.group_index);
            srv_ucm_hold_action(index.group_index);
            break;

        case SRV_UCM_HOLD_AND_ACCEPT_ACT:

            hold_and_accept_req = (srv_ucm_hold_and_accept_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Compound action start notify */
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_HOLD_AND_ACCEPT_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, hold_and_accept_req);

            /* Permit */
            permit = srv_ucm_hold_and_accept_act_permit(hold_and_accept_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_HOLD_AND_ACCEPT_ACT, 
                        NULL, 
                        permit, 
                        MMI_FALSE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the hold and accept action */
            srv_ucm_query_group_index_by_group_id(hold_and_accept_req->active_group, hold_and_accept_req->active_call_type, &index.group_index);
            srv_ucm_hold_and_accept_action(index.group_index);
            break;

        case SRV_UCM_START_DTMF_ACT:

            start_dtmf_req = (srv_ucm_dtmf_struct *)act_data;

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_start_dtmf_act_permit(start_dtmf_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_FAIL, permit);
            
                /* No need to send action notify */
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the start dtmf action */
            srv_ucm_start_dtmf_action(start_dtmf_req->digit);
            break;

        case SRV_UCM_STOP_DTMF_ACT:

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_stop_dtmf_act_permit();
        
            if (permit != SRV_UCM_RESULT_OK)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_FAIL, permit);
            
                /* No need to send action notify */
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);
        
            /* Perform the stop dtmf action */
            if (g_ucm_srv_p->call_misc.curr_action == SRV_UCM_SEND_DTMF_DIGITS_ACT)
            {
                srv_ucm_stop_dtmf_digits();
            }
            else
            {
                srv_ucm_stop_dtmf_action();
            }
            break;

        case SRV_UCM_SEND_DTMF_DIGITS_ACT:

            send_dtmf_digits_req = (srv_ucm_dtmf_digits_struct *)act_data;

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Compound action start notify */
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_SEND_DTMF_DIGITS_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, send_dtmf_digits_req);

            /* Permit */
            permit = srv_ucm_send_dtmf_digits_act_permit(send_dtmf_digits_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_SEND_DTMF_DIGITS_ACT, 
                        NULL, 
                        permit, 
                        MMI_FALSE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the send dtmf digits action */
            srv_ucm_send_dtmf_digits_action(send_dtmf_digits_req);
            break;

    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_VT_FALLTO_VOICE_ACT:

            single_call_req = (srv_ucm_single_call_act_req_struct *)act_data;
            memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

            g_ucm_srv_p->call_misc.user_data = user_data;

            /* Permit */
            permit = srv_ucm_vt_fallto_voice_act_permit(single_call_req);

            if (permit != SRV_UCM_RESULT_OK)
            {
                srv_ucm_act_permit_fail_action_notify(
                        SRV_UCM_VT_FALLTO_VOICE_ACT, 
                        single_call_req, 
                        permit, 
                        MMI_TRUE, 
                        MMI_FALSE);
                return;
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACT_REQUEST_PRMT_OK);

            /* Perform the vt fallback to voice action */
            srv_ucm_vt_fallto_voice_action();
            break;
    #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */

        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_send_act_response
 * DESCRIPTION
 *  The function to invoke action response callback
 * PARAMETERS
 *  act_op:          [IN]        Action op-code
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_send_act_response(srv_ucm_act_opcode_enum act_op, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_result_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACTION_RESPONSE, act_op, g_ucm_srv_p->act_result_callback);

    if (g_ucm_srv_p->act_result_callback != NULL)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_ACTION_RESULT);

        /* Send post event to notify the action result */
        evt.act_op = act_op;
        evt.act_result = OslMalloc(sizeof(srv_ucm_act_rsp_struct));
        memcpy(evt.act_result, ptr, sizeof(srv_ucm_act_rsp_struct));

        MMI_FRM_POST_EVENT_EX((mmi_event_struct *)&evt,
            g_ucm_srv_p->act_result_callback,
            g_ucm_srv_p->call_misc.user_data,
            srv_ucm_post_event_callback,
            (void *)evt.act_result);

        g_ucm_srv_p->act_result_callback = NULL;
    }
    g_ucm_srv_p->call_misc.curr_action = SRV_UCM_NO_ACT;
    g_ucm_srv_p->call_misc.user_data = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_send_act_notify
 * DESCRIPTION
 *  The function to notify action in progress
 *  Second op-code must be subset of the first op-code, they determine the action type
 * PARAMETERS
 *  comp_act_op:           [IN]        Compound action op-code
 *  curr_act_op:       [IN]        Current action op-code
 *  notify_type:       [IN]        Start or end
 *  ptr:               [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_send_act_notify(srv_ucm_act_opcode_enum comp_act_op, srv_ucm_act_opcode_enum curr_act_op, srv_ucm_act_notify_type_enum notify_type , void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_type_enum act_type;
    srv_ucm_act_notify_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((comp_act_op != curr_act_op) &&
        ((curr_act_op == SRV_UCM_END_ALL_ACT) ||
        (curr_act_op == SRV_UCM_END_SINGLE_ACT) ||
        (curr_act_op == SRV_UCM_END_CONFERENCE_ACT)))
    {
        /* UCM service may use INT_END_ALL, INT_END_SINGLE or INT_END_CONF to END_ALL or END_ALL_ACTIVE,
           which upper layer doesn't need to aware */
        curr_act_op = srv_ucm_query_first_end_act_op(comp_act_op, curr_act_op);
    }

    act_type = srv_ucm_query_act_type(comp_act_op, curr_act_op);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_ACTION_NOTIFY, comp_act_op, curr_act_op, act_type, notify_type);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_ACTION_NOTIFY);
    evt.comp_act_op = comp_act_op;
    evt.act_op = curr_act_op;
    evt.act_type = act_type;
    evt.notify_type = notify_type;

    if (notify_type == SRV_UCM_ACT_NOTIFY_TYPE_START)
    {
        switch (curr_act_op)
        {
            case SRV_UCM_DIAL_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_dial_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_dial_act_req_struct));
                break;
            case SRV_UCM_ACCEPT_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_call_act_req_struct));
                break;
            case SRV_UCM_HOLD_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_group_act_req_struct));
                break;
            case SRV_UCM_RETRIEVE_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_group_act_req_struct));
                break;
            case SRV_UCM_SWAP_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_multiple_group_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_multiple_group_act_req_struct));
                break;
            case SRV_UCM_CONFERENCE_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_multiple_group_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_multiple_group_act_req_struct));
                break;
            case SRV_UCM_SPLIT_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_call_act_req_struct));
                break;
        #ifdef __MMI_UCM_DEFLECT__
            case SRV_UCM_DEFLECT_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_cd_or_ct_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_cd_or_ct_act_req_struct));
                break;
        #endif /* __MMI_UCM_DEFLECT__ */
        #ifdef __MMI_UCM_TRANSFER__
            case SRV_UCM_TRANSFER_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_cd_or_ct_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_cd_or_ct_act_req_struct));
                break;
        #endif /* __MMI_UCM_TRANSFER__ */
        #ifdef __MMI_UCM_ECT__
            case SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_ect_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_ect_act_req_struct));
                break;
        #endif /* __MMI_UCM_ECT__ */
            case SRV_UCM_END_SINGLE_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_call_act_req_struct));
                break;
            case SRV_UCM_END_CONFERENCE_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_group_act_req_struct));
                break;
            case SRV_UCM_END_ALL_ACT:
            case SRV_UCM_END_ALL_ACTIVE_ACT:
        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
            case SRV_UCM_END_ALL_HELD_ACT:
        #endif
            case SRV_UCM_END_ALL_PROCESSING_ACT:
                evt.ptr = NULL;
                break;
        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__
            case SRV_UCM_END_ALL_AND_DIAL_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_dial_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_dial_act_req_struct));
                break;
        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__ */
        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__
            case SRV_UCM_END_ALL_AND_ACCEPT_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_call_act_req_struct));
                break;
        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__ */
        #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
            case SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_group_act_req_struct));
                break;
        #endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */
            case SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_call_act_req_struct));
                break;
            case SRV_UCM_HOLD_AND_DIAL_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_hold_and_dial_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_hold_and_dial_act_req_struct));
                break;
            case SRV_UCM_HOLD_AND_ACCEPT_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_hold_and_accept_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_hold_and_accept_act_req_struct));
                break;
            case SRV_UCM_START_DTMF_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_dtmf_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_dtmf_struct));
                break;
            case SRV_UCM_STOP_DTMF_ACT:
                evt.ptr = NULL;
                break;
            case SRV_UCM_SEND_DTMF_DIGITS_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_dtmf_digits_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_dtmf_digits_struct));
                break;
        #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
            case SRV_UCM_VT_FALLTO_VOICE_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_single_call_act_req_struct));
                break;
        #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
            default:
                MMI_ASSERT(0); /* not valid op_code */
                break;
        }
    }
    else if (notify_type == SRV_UCM_ACT_NOTIFY_TYPE_END)
    {
        evt.ptr = OslMalloc(sizeof(srv_ucm_act_rsp_struct));
        memcpy(evt.ptr, ptr, sizeof(srv_ucm_act_rsp_struct));
    }
    else
    {
        MMI_ASSERT(0);
    }

    MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_ucm_post_event_callback, (void *)evt.ptr);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_send_indication
 * DESCRIPTION
 *  The function to send indication
 * PARAMETERS
 *  ind_op:          [IN]        Indication op-code
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_send_indication(srv_ucm_ind_opcode_enum ind_op, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_INDICATION, ind_op);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_INDICATION);
    evt.ind_type = ind_op;

    switch (ind_op)
    {
        case SRV_UCM_INCOMING_CALL_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_incoming_call_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_incoming_call_ind_struct));
            break;
        case SRV_UCM_OUTGOING_CALL_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_outgoing_call_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_outgoing_call_ind_struct));
            break;
        case SRV_UCM_ALERT_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_alert_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_alert_ind_struct));
            break;
        case SRV_UCM_NOTIFY_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_notify_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_notify_ind_struct));
            break;
        case SRV_UCM_CONNECT_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_connect_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_connect_ind_struct));
            break;
        case SRV_UCM_DISCONNECTING_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_disconnecting_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_disconnecting_ind_struct));
            break;
        case SRV_UCM_RELEASE_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_release_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_release_ind_struct));
            break;
        case SRV_UCM_CALL_COST_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_call_cost_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_call_cost_ind_struct));
            break;
        case SRV_UCM_AUTO_REDIAL_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_auto_redial_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_auto_redial_ind_struct));
            break;
        case SRV_UCM_AUTO_REDIAL_CANCEL_IND:
            evt.ptr = NULL;
            break;
    #ifdef __MMI_VOIP__
        case SRV_UCM_START_PROCESSING_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_start_processing_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_start_processing_ind_struct));
            break;
        case SRV_UCM_STOP_PROCESSING_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_stop_processing_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_stop_processing_ind_struct));
            break;
    #endif /* __MMI_VOIP__ */
        case SRV_UCM_QUERY_CANCEL_IND:
        case SRV_UCM_REFRESH_IND:
    #ifdef __MMI_VIDEO_TELEPHONY__
        case SRV_UCM_START_COUNT_IND:
    #endif
            evt.ptr = NULL;
            break;
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }

    MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_ucm_ind_post_evt_callback, (void *)evt.ptr);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_send_cnf_indication
 * DESCRIPTION
 *  The function to send confirm indication
 * PARAMETERS
 *  ind_op:          [IN]        Indication op-code
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_send_cnf_indication(srv_ucm_cnf_ind_opcode_enum cnf_ind_op, void *ptr, srv_ucm_cnf_callback_func_ptr cnf_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_cnf_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_CNF_INDICATION, cnf_ind_op);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_CNF_INDICATION);
    evt.op_code = cnf_ind_op;
    evt.cnf_callback = cnf_callback;

    switch (cnf_ind_op)
    {
        case SRV_UCM_QUERY_CNF_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_query_cnf_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_query_cnf_ind_struct));
            break;
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }

    MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_ucm_post_event_callback, (void *)evt.ptr);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_post_event_callback
 * DESCRIPTION
 *  The callback function after post event is done
 *  Including action response, action notify and confirm indication
 * PARAMETERS
 *  result_evt:        [IN]        result structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_ucm_post_event_callback(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (result_evt->user_data != NULL)
    {
        OslMfree(result_evt->user_data);
        result_evt->user_data = NULL;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_ind_post_evt_callback
 * DESCRIPTION
 *  The callback function after post event is done, only for indication
 * PARAMETERS
 *  result_evt:        [IN]        result structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_ucm_ind_post_evt_callback(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *)result_evt->evt_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (ind->ind_type)
    {
        case SRV_UCM_RELEASE_IND:
            srv_ucm_release_ind_post_callback(ind);
            break;

        default:
            break;
    }

    return srv_ucm_post_event_callback(result_evt);
}


