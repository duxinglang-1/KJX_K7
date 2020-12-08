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

/*******************************************************************************
 * Filename:
 * ---------
 *  SsSrvInterface.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS service interface
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "SsSrvGprot.h"
#include "SsSrvIprot.h"
#include "SsSrvProt.h"

#include "UcmSrvGprot.h" /* srv_ucm_query_call_count */


#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "kal_release.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "mmi_cb_mgr_gprot.h"
#include "stack_config.h"
#include "MMI_features.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"
#include "stack_msgs.h"
#include "Unicodexdcl.h"
#include "l3_inc_enums.h"
#include "l4c2csm_ss_struct.h"
#include "csmss_common_enums.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static MMI_BOOL srv_ss_init_rsp(srv_ss_rsp_struct *rsp, l4c_result_struct *result,	srv_ss_act_enum op, srv_ss_cntx_struct *cntx);

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ss_act_req
 * DESCRIPTION
 *  to request the ss action
 * PARAMETERS
 *  act_op : [IN] action operation code
 *  act_data : [IN] action parameters
 *  callback : [IN] callback to notify the result, srv_ss_rsp_evt_struct, can be NULL
 *  user_data : [IN] user data, can be NULL
 * RETURNS
 *  srv_ss_result_enum, not OK if the request is rejected directly by ss service
 *  The caller app shall handle the error pop-up if the request is rejected directly by ss service.
 *  Ss srv sends rsp but doesn't act start / act_end if the op is rejected directly by ss srv
 *  In other cases, ss app takes charge of the requesting and result display
 *****************************************************************************/
srv_ss_result_enum srv_ss_act_req(srv_ss_act_enum act_op, void *act_data, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_req_struct *req = (srv_ss_act_req_struct*)act_data;
    srv_ss_result_enum result;
    srv_ss_rsp_struct rsp;
    srv_ss_rsp_evt_struct evt;
    srv_ss_act_info_struct ori_act_info;
    MMI_BOOL is_busy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_ACT_REQ
        , act_op, act_data, callback, user_data);

    if ((req == NULL) || !srv_ss_is_valid_sim(req->sim))
    {
        if (callback != NULL)
        {
            /* doesn't send act start / act end if the op is rejected directly by ss srv */
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SS_ACT_RESPONSE); 
            memset(&(evt.rsp), 0, sizeof(evt.rsp));
            evt.rsp.sim = req ? req->sim : MMI_SIM_NONE;
            evt.rsp.source = req ? req->source : SRV_SS_SRC_COMMON;
            evt.rsp.result = SRV_SS_RESULT_INVALID_INPUT;
            evt.rsp.opcode = act_op;
            MMI_FRM_POST_EVENT_EX(
                &evt, 
                callback, 
                user_data, 
                srv_ss_post_evt_cb, 
                evt.rsp.data);
        }

        return SRV_SS_RESULT_INVALID_INPUT;
    }

    if (srv_ss_cntx_is_locked())
    {
        MMI_ASSERT(0);
    }

    srv_ss_cntx_set_ptr(req->sim);

    /* use original action info to check */
    is_busy = srv_ss_is_busy(act_op);

    /* backup ori action info and replace with new act info */
    memcpy(&ori_act_info, &(srv_ss_p->act_info), sizeof(srv_ss_act_info_struct));
    srv_ss_p->act_info.source = req->source;
    srv_ss_p->act_info.op = act_op;
    srv_ss_p->act_info.info = act_data;
    srv_ss_p->act_info.rsp_cb = callback;
    srv_ss_p->act_info.rsp_user_data = user_data;

    if ((act_op != SRV_SS_ACT_ABORT) && is_busy)
    {
        result = SRV_SS_RESULT_BUSY;
    }
    else if ((act_op != SRV_SS_ACT_ABORT) && !srv_ss_is_available(srv_ss_p->sim))
    {
        result = SRV_SS_RESULT_NOT_AVAILABLE;
    }
    else
    {
        switch (act_op)
        {
            case SRV_SS_ACT_CALL_FORWARD:
                result = srv_ss_op_call_forward(act_data);
                break;

            case SRV_SS_ACT_CALL_BAR:
                result = srv_ss_op_call_bar(act_data);
                break;

            case SRV_SS_ACT_CALL_WAIT:
                result = srv_ss_op_call_wait(act_data);
                break;

            case SRV_SS_ACT_SS_OPERATION:
                result = srv_ss_op_ss_operation(act_data, 0);
                break;

            case SRV_SS_ACT_ABORT:
                /* send the previous rsp */
                /* restore original action info */
                memcpy(&(srv_ss_p->act_info), &ori_act_info, sizeof(srv_ss_act_info_struct));
                if ((srv_ss_p->act_info.op != SRV_SS_ACT_IDLE) && 
                    (srv_ss_p->act_info.op != SRV_SS_ACT_ABORT))
                {
                    memset(&rsp, 0, sizeof(rsp));
                    rsp.sim = srv_ss_p->sim;
                    rsp.source = srv_ss_p->act_info.source;
                    rsp.result = SRV_SS_RESULT_ABORT;
                    rsp.opcode = srv_ss_p->act_info.op;
                    srv_ss_ps_ss_operation_done(&rsp, MMI_FALSE);
                }
                /* abort */
                /* replace with new action info */
                srv_ss_p->act_info.source = req->source;
                srv_ss_p->act_info.op = act_op;
                srv_ss_p->act_info.info = act_data;
                srv_ss_p->act_info.rsp_cb = callback;
                srv_ss_p->act_info.rsp_user_data = user_data;
                result = srv_ss_op_abort();
                break;

            default:
                result = SRV_SS_RESULT_INVALID_INPUT;
                break;
        }
    }

    if (result == SRV_SS_RESULT_OK)
    {
        srv_ss_post_act_notify_evt(SRV_SS_ACT_NOTIFY_START, NULL);
        
        /* send abort end and rsp */
        if (srv_ss_p->act_info.op == SRV_SS_ACT_ABORT)
        {
            memset(&rsp, 0, sizeof(rsp));
            rsp.sim = srv_ss_p->sim;
            rsp.source = srv_ss_p->act_info.source;
            rsp.result = SRV_SS_RESULT_OK;
            rsp.opcode = srv_ss_p->act_info.op;
            srv_ss_ps_ss_operation_done(&rsp, MMI_TRUE);
        }
    }
    else
    {
        /* doesn't send act start / act end if the op is rejected directly by ss srv */
        memset(&rsp, 0, sizeof(rsp));
        rsp.sim = srv_ss_p->sim;
        rsp.source = srv_ss_p->act_info.source;
        rsp.result = result;
        rsp.opcode = act_op;
        srv_ss_post_rsp_evt(&rsp);

        if (result == SRV_SS_RESULT_BUSY)
        {
            /* restore the original action info */
            memcpy(&(srv_ss_p->act_info), &ori_act_info, sizeof(srv_ss_act_info_struct));
        }
    }

    srv_ss_cntx_reset_ptr();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_post_rsp_evt
 * DESCRIPTION
 *  The function to post response to the caller
 * PARAMETERS
 *  op          [IN]    action op code
 *  info        [IN]    Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_post_rsp_evt(srv_ss_rsp_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_rsp_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_POST_RSP_EVT
        , srv_ss_p->act_info.rsp_cb, srv_ss_p->act_info.rsp_user_data
        , info->sim, info->result, info->ps_cause, info->opcode);

    if (srv_ss_p->act_info.rsp_cb)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SS_ACT_RESPONSE);
        
        memcpy(&(evt.rsp), info, sizeof(srv_ss_rsp_struct));
        evt.rsp.data = srv_ss_post_copy_act_rsp(info->opcode, info->data);
        
        MMI_FRM_POST_EVENT_EX(
            &evt, 
            srv_ss_p->act_info.rsp_cb, 
            srv_ss_p->act_info.rsp_user_data, 
            srv_ss_post_evt_cb, 
            evt.rsp.data);
    }

    memset(&(srv_ss_p->act_info), 0, sizeof(srv_ss_act_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_post_act_req_evt
 * DESCRIPTION
 *  post action event. postpone the action request to avoid re-entry problem
 * PARAMETERS
 *  op              [IN]    operation code
 *  info            [IN]    action parameters
 *  rsp_cb          [IN]    action response callback
 *  rsp_user_data   [IN]    response user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_post_act_req_evt(srv_ss_act_enum op, void *info, mmi_proc_func rsp_cb, void *rsp_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_POST_ACT_REQ_EVT
        , op, info, rsp_cb, rsp_user_data);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SS_INT_ACT);
    evt.op = op;
    evt.info = srv_ss_post_copy_act_req(op, info);
    evt.rsp_user_data = rsp_user_data;
    evt.rsp_cb = rsp_cb;
    
    MMI_FRM_POST_EVENT(&evt, srv_ss_post_act_req_evt_hdlr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_post_copy_act_req
 * DESCRIPTION
 *  copy action request structure for post action
 * PARAMETERS
 *  op              [IN]    operation code
 *  from            [IN]    data
 * RETURNS
 *  void*
 *****************************************************************************/
void *srv_ss_post_copy_act_req(srv_ss_act_enum op, void *from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *to;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op)
    {
        case SRV_SS_ACT_CALL_FORWARD:
            to = OslMalloc(sizeof(srv_ss_call_forward_req_struct));
            memcpy(to, from, sizeof(srv_ss_call_forward_req_struct));
            break;

        case SRV_SS_ACT_CALL_BAR:
            to = OslMalloc(sizeof(srv_ss_call_bar_req_struct));
            memcpy(to, from, sizeof(srv_ss_call_bar_req_struct));
            break;

        case SRV_SS_ACT_CALL_WAIT:
            to = OslMalloc(sizeof(srv_ss_call_wait_req_struct));
            memcpy(to, from, sizeof(srv_ss_call_wait_req_struct));
            break;

        case SRV_SS_ACT_SS_OPERATION:
            to = OslMalloc(sizeof(srv_ss_operation_req_struct));
            memcpy(to, from, sizeof(srv_ss_operation_req_struct));
            break;

        case SRV_SS_ACT_ABORT:
            to = OslMalloc(sizeof(srv_ss_abort_req_struct));
            memcpy(to, from, sizeof(srv_ss_abort_req_struct));
            break;

        default:
            to = NULL;
            break;
    }

    return to;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_post_copy_act_rsp
 * DESCRIPTION
 *  copy action request structure for post action
 * PARAMETERS
 *  op              [IN]    operation code
 *  from            [IN]    data
 * RETURNS
 *  void*
 *****************************************************************************/
void *srv_ss_post_copy_act_rsp(srv_ss_act_enum op, void *from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *to;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!from)
    {
        return NULL;
    }

    switch (op)
    {
        case SRV_SS_ACT_CALL_FORWARD:
            to = OslMalloc(sizeof(srv_ss_call_forward_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_call_forward_rsp_struct));
            break;

        case SRV_SS_ACT_CALL_BAR:
            to = OslMalloc(sizeof(srv_ss_call_bar_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_call_bar_rsp_struct));
            break;

        case SRV_SS_ACT_CALL_WAIT:
            to = OslMalloc(sizeof(srv_ss_call_wait_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_call_wait_rsp_struct));
            break;

        case SRV_SS_ACT_CALL_IDENTIFICATION:
            to = OslMalloc(sizeof(srv_ss_call_id_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_call_id_rsp_struct));
            break;

        case SRV_SS_ACT_CNAP:
            to = OslMalloc(sizeof(srv_ss_cnap_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_cnap_rsp_struct));
            break;

        case SRV_SS_ACT_CCBS:
            to = OslMalloc(sizeof(srv_ss_ccbs_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_ccbs_rsp_struct));
            break;

        case SRV_SS_ACT_EMLPP:
            to = OslMalloc(sizeof(srv_ss_emlpp_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_emlpp_rsp_struct));
            break;

        case SRV_SS_ACT_USSD:
            to = OslMalloc(sizeof(srv_ss_ussd_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_ussd_rsp_struct));
            break;

        default:
            to = NULL;
            break;
    }

    return to;
}




/*****************************************************************************
 * FUNCTION
 *  srv_ss_post_act_req_evt_hdlr
 * DESCRIPTION
 *  handler for action event
 * PARAMETERS
 *  para    [IN]    parameters
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_ss_post_act_req_evt_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_evt_struct *evt = (srv_ss_act_evt_struct*)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    srv_ss_act_req(evt->op, evt->info, evt->rsp_cb, evt->rsp_user_data);

    if (evt->info)
    {
        OslMfree(evt->info);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_post_ind_evt
 * DESCRIPTION
 *  The function to post indication to the caller
 * PARAMETERS
 *  op          [IN]    indication op code
 *  info        [IN]    Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_post_ind_evt(srv_ss_ind_enum op, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SS_INDICATION);
    evt.sim = srv_ss_p->sim;
    evt.ind_type = op;
    switch (op)
    {
        case SRV_SS_IND_USSN:
            evt.data = OslMalloc(sizeof(srv_ss_ussn_ind_struct));
            memcpy(evt.data, info, sizeof(srv_ss_ussn_ind_struct));
            break;

        case SRV_SS_IND_USSR:
            evt.data = OslMalloc(sizeof(srv_ss_ussr_ind_struct));
            memcpy(evt.data, info, sizeof(srv_ss_ussr_ind_struct));
            break;

        case SRV_SS_IND_ABORT:
            evt.data = OslMalloc(sizeof(srv_ss_abort_ind_struct));
            memcpy(evt.data, info, sizeof(srv_ss_abort_ind_struct));
            break;

        default:
            evt.data = NULL;
            break;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_POST_IND_EVT
        , evt.sim , evt.source, evt.ind_type, evt.data);

    MMI_FRM_CB_EMIT_POST_EVENT_EX(
        &evt, 
        srv_ss_post_evt_cb, 
        evt.data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_post_act_notify_evt
 * DESCRIPTION
 *  The function to post indication to the caller
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_post_act_notify_evt(srv_ss_act_notify_enum type, srv_ss_rsp_struct *rsp_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_notify_evt_struct evt;
    srv_ss_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SS_ACT_NOTIFY);
    evt.type = type;
    evt.act_op = srv_ss_p->act_info.op;

    switch (type)
    {
        case SRV_SS_ACT_NOTIFY_START:
            evt.info = srv_ss_post_copy_act_req(srv_ss_p->act_info.op, srv_ss_p->act_info.info);
            break;

        case SRV_SS_ACT_NOTIFY_END:
            rsp = OslMalloc(sizeof(srv_ss_rsp_struct));
            memcpy(rsp, rsp_info, sizeof(srv_ss_rsp_struct));
            rsp->data= srv_ss_post_copy_act_rsp(rsp_info->opcode, rsp_info->data);
            evt.info = (void*)rsp;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_POST_ACT_NOTIFY_EVT
        , evt.type , evt.act_op, evt.info);

    MMI_FRM_CB_EMIT_POST_EVENT_EX(
        &evt, 
        srv_ss_post_evt_cb, 
        evt.info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_post_evt_cb
 * DESCRIPTION
 *  The callback function after posting indication event is done
 * PARAMETERS
 *  result_evt:        [IN]        result structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_ss_post_evt_cb(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_notify_evt_struct *notify_evt;
    srv_ss_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_POST_EVT_CB
        , result_evt->user_data, result_evt->evt_p->evt_id);

    if (result_evt->user_data != NULL)
    {
        if (result_evt->evt_p->evt_id == EVT_ID_SRV_SS_ACT_NOTIFY)
        {
            notify_evt = (srv_ss_act_notify_evt_struct*)(result_evt->evt_p);
            if (notify_evt->type == SRV_SS_ACT_NOTIFY_END)
            {
                rsp = (srv_ss_rsp_struct*)(notify_evt->info);
                if (rsp->data)
                {
                    OslMfree(rsp->data);
                }
            }            
        }

        OslMfree(result_evt->user_data);
        result_evt->user_data = NULL;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_ss_set_ps_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_set_ps_event_handler(PsExtFuncPtr func, U16 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_set_protocol_event_handler(event, (PsIntFuncPtr)func, MMI_FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_reset_ps_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_reset_ps_event_handler(U16 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearProtocolEventHandler(event);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_l4c_ss_operation_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length  [IN]    string length
 *  str     [IN]    string in UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_l4c_ss_operation_req(U8 length, WCHAR *str, U8 cf_num_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_operation_req_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((length != 0) && (str != NULL))
    {
        req = OslAllocDataPtr(mmi_ss_operation_req_struct);

    #ifdef __MMI_USSD_REPLY_UCS2__
        if (srv_ss_check_ucs2(length, str))
        {
        	U32 i;
			U8 c;
            req->length = length * ENCODING_LENGTH;
            mmi_ucs2ncpy((CHAR*)req->input, (CHAR*)str, length);

            /* convert to big endian*/
            for (i = 0; i < length; i += 2)
            {
                c = req->input[i];
                req->input[i] = req->input[i+1];
                req->input[i+1]  = c;
            }
            req->dcs = 0x48;
        }
        else
    #endif /* __MMI_USSD_REPLY_UCS2__ */
        {
            req->length = length;
            mmi_ucs2_n_to_asc((CHAR*)req->input, (CHAR*)str, length * ENCODING_LENGTH);
            req->dcs = 0x0f;
        }
        req->cf_number_length = cf_num_len;

    }

    srv_ss_set_ps_event_handler(srv_ss_phdlr_ss_operation_rsp, MSG_ID_MMI_SS_OPERATION_RSP);
	
    mmi_frm_send_ilm((oslModuleType)mmi_frm_sim_to_l4c_mod(srv_ss_p->sim), MSG_ID_MMI_SS_OPERATION_REQ, (oslParaType*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  MakePsDropUSSDReq
 * DESCRIPTION
 *  Aborts SS string request
 * PARAMETERS
 *  callBack        [IN]        
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_l4c_ss_abort_req(PsExtFuncPtr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_set_ps_event_handler(cb, MSG_ID_MMI_SS_ABORT_RSP);

    mmi_frm_send_ilm((oslModuleType)mmi_frm_sim_to_l4c_mod(srv_ss_p->sim), MSG_ID_MMI_SS_ABORT_REQ, NULL, NULL);
}



#ifdef __USSD_AUTO_REJECT__
/*****************************************************************************
 * FUNCTION
 *  srv_ss_l4c_ussd_ack_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error cause to the network
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_l4c_ack_req(U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_ack_req_struct *ack;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ack = OslAllocDataPtr(mmi_ss_ack_req_struct);
    ack->cause = cause;

    srv_ss_set_ps_event_handler(srv_ss_phdlr_ussd_ack_rsp, MSG_ID_MMI_SS_ACK_RSP);
    mmi_frm_send_ilm((oslModuleType)mmi_frm_sim_to_l4c_mod(srv_ss_p->sim), MSG_ID_MMI_SS_ACK_REQ, (oslParaType*)ack, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_ussd_ack_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    mmi_ss_ack_rsp_struct *rsp = (mmi_ss_ack_rsp_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ss_reset_ps_event_handler(MSG_ID_MMI_SS_ACK_RSP);

    if (rsp->result != KAL_TRUE)
    {
        MMI_ASSERT(0);
    }
}
#endif /* __USSD_AUTO_REJECT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_ss_operation_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_ss_operation_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_operation_rsp_struct *rsp = (mmi_ss_operation_rsp_struct*)info;
    srv_ss_rsp_struct ss_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    srv_ss_reset_ps_event_handler(MSG_ID_MMI_SS_OPERATION_RSP);

    /* Its legacy problem, in this message, result.flag is kal_bool, not l4c_result_enum */
    if (!(kal_bool)rsp->result.flag)
    {
		l4c_result_struct l4c_result = rsp->result;
		
		l4c_result.flag = L4C_ERROR;
		srv_ss_init_rsp(&ss_rsp, &l4c_result, srv_ss_p->act_info.op, srv_ss_p);
		
        ss_rsp.data = NULL;
        srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    }

    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_call_forward_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_call_forward_rsp_struct *rsp = (mmi_ss_call_forward_rsp_struct*)info;
    srv_ss_call_forward_rsp_struct cf_rsp;
    srv_ss_rsp_struct ss_rsp;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if ((srv_ss_p->act_info.op != SRV_SS_ACT_CALL_FORWARD) &&
        (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION))
    {
        /* ignore */
        /* abnormal msg or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

    if (srv_ss_init_rsp(&ss_rsp, &rsp->result, SRV_SS_ACT_CALL_FORWARD, srv_ss_p))
    {
        ss_rsp.result = SRV_SS_RESULT_OK;
        ss_rsp.ps_cause = (srv_ss_ps_cause_enum)0;

        memset(&cf_rsp, 0, sizeof(srv_ss_call_forward_rsp_struct));
        cf_rsp.type = srv_ss_get_cf_type(rsp->type);
        cf_rsp.result_list_count = rsp->count;
        for (i = 0; i < ((rsp->count <= SRV_SS_MAX_BS_LIST_NUM) ? rsp->count : SRV_SS_MAX_BS_LIST_NUM); i++)
        {
            cf_rsp.result_list[i].bs_code = srv_ss_get_bs_code(rsp->list[i].bs_code);
            if (rsp->list[i].ss_status & SS_ABIT)
            {
                cf_rsp.result_list[i].status = SRV_SS_STATUS_ACTIVATED;
            }
            else if (rsp->opcode == SS_OP_INTERROGATESS)
            {
                if (rsp->list[i].ss_status & SS_PBIT)
                {
                    cf_rsp.result_list[i].status = SRV_SS_STATUS_DEACTIVATED;
                }
                else
                {
                    cf_rsp.result_list[i].status = SRV_SS_STATUS_NOT_PROVIDED;
                }
            }
            else
            {
                cf_rsp.result_list[i].status = SRV_SS_STATUS_DEACTIVATED;
            }

            mmi_asc_n_to_ucs2((CHAR*)cf_rsp.result_list[i].number, (CHAR*)rsp->list[i].address, SRV_UCM_MAX_NUM_URI_LEN);
            cf_rsp.result_list[i].no_reply_timer = rsp->list[i].no_reply_timer;
        }

        ss_rsp.data = (void*)(&cf_rsp);
    }   

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);

    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_call_bar_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_call_barring_rsp_struct *rsp = (mmi_ss_call_barring_rsp_struct*)info;
    srv_ss_call_bar_rsp_struct cb_rsp;
    srv_ss_rsp_struct ss_rsp;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if ((srv_ss_p->act_info.op != SRV_SS_ACT_CALL_BAR) &&
        (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION))
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }


    if (srv_ss_init_rsp(&ss_rsp, &rsp->result, SRV_SS_ACT_CALL_BAR, srv_ss_p))
    {
        memset(&cb_rsp, 0, sizeof(srv_ss_call_bar_rsp_struct));
        cb_rsp.type = srv_ss_get_cb_type(rsp->type);
        cb_rsp.result_list_count = rsp->count;
        for (i = 0; i < ((rsp->count <= SRV_SS_MAX_BS_LIST_NUM) ? rsp->count : SRV_SS_MAX_BS_LIST_NUM); i++)
        {
            cb_rsp.result_list[i].bs_code = srv_ss_get_bs_code(rsp->list[i].bs_code);
            if (rsp->list[i].ss_status & SS_ABIT)
            {
                cb_rsp.result_list[i].status = SRV_SS_STATUS_ACTIVATED;
            }
            else if (rsp->list[i].ss_status & SS_PBIT)
            {
                cb_rsp.result_list[i].status = SRV_SS_STATUS_DEACTIVATED;
            }
            else
            {
                cb_rsp.result_list[i].status = SRV_SS_STATUS_NOT_PROVIDED;
            }
        }

        ss_rsp.data = (void*)(&cb_rsp);
    }   

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);

    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_change_password_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_change_password_rsp_struct *rsp = (mmi_ss_change_password_rsp_struct*)info;
    srv_ss_call_bar_rsp_struct cb_rsp;
    srv_ss_rsp_struct ss_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if ((srv_ss_p->act_info.op != SRV_SS_ACT_CALL_BAR) &&
        (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION))
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

    if (srv_ss_init_rsp(&ss_rsp, &rsp->result, SRV_SS_ACT_CALL_BAR, srv_ss_p))
    {
        memset(&cb_rsp, 0, sizeof(srv_ss_call_bar_rsp_struct));
        cb_rsp.change_passwd = MMI_TRUE;
        ss_rsp.data = (void*)(&cb_rsp);
    }

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);

    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_call_wait_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_call_wait_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_call_wait_rsp_struct *rsp = (mmi_ss_call_wait_rsp_struct*)info;
    srv_ss_call_wait_rsp_struct cw_rsp;
    srv_ss_rsp_struct ss_rsp;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if ((srv_ss_p->act_info.op != SRV_SS_ACT_CALL_WAIT) &&
        (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION))
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

    if (srv_ss_init_rsp(&ss_rsp, &rsp->result, SRV_SS_ACT_CALL_WAIT, srv_ss_p))
    {
        memset(&cw_rsp, 0, sizeof(srv_ss_call_wait_rsp_struct));
        if (rsp->status & SS_ABIT)
        {
            cw_rsp.status = SRV_SS_STATUS_ACTIVATED;
        }
        else if (rsp->opcode == SS_OP_INTERROGATESS)
        {
            if (rsp->status & SS_PBIT)
            {
                cw_rsp.status = SRV_SS_STATUS_DEACTIVATED;
            }
            else
            {
                cw_rsp.status = SRV_SS_STATUS_NOT_PROVIDED;
            }
        }
        else /* rsp->opcode == SS_OP_INTERROGATESS */
        {
            cw_rsp.status = SRV_SS_STATUS_DEACTIVATED;
        }

        cw_rsp.bs_list_count = rsp->count;
        for (i = 0; i < ((rsp->count <= SRV_SS_MAX_BS_LIST_NUM) ? rsp->count : SRV_SS_MAX_BS_LIST_NUM); i++)
        {
            cw_rsp.bs_list[i] = srv_ss_get_bs_code(rsp->list[i]);
        }

        ss_rsp.data = (void*)(&cw_rsp);
    }
    

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);

    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_call_wait_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_ussd_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_ussd_rsp_struct *rsp = (mmi_ss_ussd_rsp_struct*)info;
    srv_ss_ussd_rsp_struct ussd_rsp;
    srv_ss_rsp_struct ss_rsp;
    srv_ss_abort_ind_struct abort_ind;
	srv_ss_act_enum op;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if ((srv_ss_p->act_info.op == SRV_SS_ACT_IDLE) &&
        srv_ss_p->in_ss_session)
    {
        /* waiting for ussr reply, send abort ind */
        abort_ind.result = srv_ss_ps_derive_result((srv_ss_ps_cause_enum)rsp->result.cause);

        if (abort_ind.result != SRV_SS_RESULT_ERROR_WITH_PS_CAUSE)
        {
            abort_ind.ps_cause = (srv_ss_ps_cause_enum)0;
        }
        else
        {
            abort_ind.ps_cause = (srv_ss_ps_cause_enum)rsp->result.cause;
        }

        srv_ss_post_ind_evt(SRV_SS_IND_ABORT, &abort_ind);
        srv_ss_p->in_ss_session = MMI_FALSE;

        srv_ss_cntx_reset_ptr();
        return;
    }

    if ((srv_ss_p->act_info.op == SRV_SS_ACT_IDLE) || /* mo / mt collision */
        ((srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION) &&
            (rsp->result.flag == L4C_OK))) /* abnormal */
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        /* other op (cf, cb..) may get ussd_rsp only in failure scenarios */
        srv_ss_cntx_reset_ptr();
        return;
    }

    op = (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION) ? srv_ss_p->act_info.op : SRV_SS_ACT_USSD;

	if (srv_ss_init_rsp(&ss_rsp, &rsp->result, op, srv_ss_p))
    {
        memset(&ussd_rsp, 0, sizeof(srv_ss_ussd_rsp_struct));
		
        ussd_rsp.end_of_session = MMI_TRUE;
        srv_ss_ps_derive_ussd(rsp->dcs, rsp->length, rsp->ussd_str, ussd_rsp.string);
        ss_rsp.data = (void*)(&ussd_rsp);
    }    

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);

    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_ussr_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_ussr_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_ussr_ind_struct *ind = (mmi_ss_ussr_ind_struct*)info;
    srv_ss_ussn_ussr_struct ussd_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    memset(&ussd_info, 0, sizeof(srv_ss_ussn_ussr_struct));
    ussd_info.ind = SRV_SS_IND_USSR;
    ussd_info.direction = srv_ss_get_direction(ind->direction);
    ussd_info.dcs = ind->dcs;
    srv_ss_ps_derive_ussd(ind->dcs, ind->length, ind->ussd_string, ussd_info.ussd_string);
    srv_ss_ps_receive_ussn_ussr(&ussd_info);

    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_ussn_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_ussn_ind_struct *ind = (mmi_ss_ussn_ind_struct*)info;
    srv_ss_ussn_ussr_struct ussd_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    memset(&ussd_info, 0, sizeof(srv_ss_ussn_ussr_struct));
    ussd_info.ind = SRV_SS_IND_USSN;
    ussd_info.direction = srv_ss_get_direction(ind->direction);
    ussd_info.dcs = ind->dcs;
    srv_ss_ps_derive_ussd(ind->dcs, ind->length, ind->ussd_string, ussd_info.ussd_string);
    srv_ss_ps_receive_ussn_ussr(&ussd_info);

    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_clip_interrogate_ind
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_clip_interrogate_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_clip_interrogate_ind_struct *ind = (mmi_ss_clip_interrogate_ind_struct*)info;
    srv_ss_call_id_rsp_struct cid_rsp;
    srv_ss_rsp_struct ss_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION)
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

    if (srv_ss_init_rsp(&ss_rsp, &ind->result, SRV_SS_ACT_CALL_IDENTIFICATION, srv_ss_p))
    {
        cid_rsp.type = SRV_SS_CALL_ID_CLIP;

        if (ind->status & SS_PBIT)
        {
            cid_rsp.status = SRV_SS_STATUS_PROVIDED;
        }
        else
        {
            cid_rsp.status = SRV_SS_STATUS_NOT_PROVIDED;
        }
        ss_rsp.data = (void*)(&cid_rsp);
    }   

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_clir_interrogate_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_clir_interrogate_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_clir_interrogate_ind_struct *ind = (mmi_ss_clir_interrogate_ind_struct*)info;
    srv_ss_call_id_rsp_struct cid_rsp;
    srv_ss_rsp_struct ss_rsp;
	static const srv_ss_status_enum status[] = 
	{
		SRV_SS_STATUS_ACTIVATED_PERMANTLY,
		SRV_SS_STATUS_ACTIVATED_BY_DEFAULT,
		SRV_SS_STATUS_DEACTIVATED_BY_DEFAULT
	};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION)
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

    if (srv_ss_init_rsp(&ss_rsp, &ind->result, SRV_SS_ACT_CALL_IDENTIFICATION, srv_ss_p))
    {
        cid_rsp.type = SRV_SS_CALL_ID_CLIR;

        if (ind->status & SS_PBIT)
        {
        	cid_rsp.status = (ind->clir_option <= 2) ? status[ind->clir_option] : SRV_SS_STATUS_PROVIDED;            
        }
        else
        {
            cid_rsp.status = SRV_SS_STATUS_NOT_PROVIDED;
        }

        ss_rsp.data = (void*)(&cid_rsp);
    }

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_colp_interrogate_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_colp_interrogate_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_colp_interrogate_ind_struct *ind = (mmi_ss_colp_interrogate_ind_struct*)info;
    srv_ss_call_id_rsp_struct cid_rsp;
    srv_ss_rsp_struct ss_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION)
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

    if (srv_ss_init_rsp(&ss_rsp, &ind->result, SRV_SS_ACT_CALL_IDENTIFICATION, srv_ss_p))
    {
        cid_rsp.type = SRV_SS_CALL_ID_COLP;

        if (ind->status & SS_PBIT)
        {
            cid_rsp.status = SRV_SS_STATUS_PROVIDED;
        }
        else
        {
            cid_rsp.status = SRV_SS_STATUS_NOT_PROVIDED;
        }
		
        ss_rsp.data = (void*)(&cid_rsp);
    }

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    srv_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_colr_interrogate_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_colr_interrogate_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_colr_interrogate_ind_struct *ind = (mmi_ss_colr_interrogate_ind_struct*)info;
    srv_ss_call_id_rsp_struct cid_rsp;
    srv_ss_rsp_struct ss_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION)
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

	if (srv_ss_init_rsp(&ss_rsp, &ind->result, SRV_SS_ACT_CALL_IDENTIFICATION, srv_ss_p))
    {
        cid_rsp.type = SRV_SS_CALL_ID_COLR;
        if (ind->status & SS_PBIT)
        {
            cid_rsp.status = SRV_SS_STATUS_PROVIDED;
        }
        else
        {
            cid_rsp.status = SRV_SS_STATUS_NOT_PROVIDED;
        }
        ss_rsp.data = (void*)(&cid_rsp);
    }    

    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    srv_ss_cntx_reset_ptr();
}


#ifdef __CNAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_cnap_interrogate_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_cnap_interrogate_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_cnap_interrogate_ind_struct *ind = (mmi_ss_cnap_interrogate_ind_struct*)info;
    srv_ss_cnap_rsp_struct cnap_rsp;
    srv_ss_rsp_struct ss_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION)
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

	if (srv_ss_init_rsp(&ss_rsp, &ind->result, SRV_SS_ACT_CNAP, srv_ss_p))
	{
        if (ind->status & SS_PBIT)
        {
            cnap_rsp.status = SRV_SS_STATUS_PROVIDED;
        }
        else
        {
            cnap_rsp.status = SRV_SS_STATUS_NOT_PROVIDED;
        }
        ss_rsp.data = (void*)(&cnap_rsp);
	}
    
    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    srv_ss_cntx_reset_ptr();
}
#endif /* __CNAP_SUPPORT__ */


#ifdef __CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_ccbs_rsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_ccbs_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_ccbs_rsp_struct *rsp = (mmi_ss_ccbs_rsp_struct*)info;
    srv_ss_ccbs_rsp_struct ccbs_rsp;
    srv_ss_rsp_struct ss_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION)
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

	if (srv_ss_init_rsp(&ss_rsp, &rsp->result, SRV_SS_ACT_CCBS, srv_ss_p))
	{
        if (rsp->opcode == SS_OP_ERASECCENTRY)
        {
            ccbs_rsp.status = SRV_SS_STATUS_DEACTIVATED;
        }
        else if (rsp->list.ss_status & SS_PBIT)
        {
            ccbs_rsp.status = SRV_SS_STATUS_PROVIDED;
        }
        else
        {
            ccbs_rsp.status = SRV_SS_STATUS_NOT_PROVIDED;
        }
        ss_rsp.data = (void*)(&ccbs_rsp);
	}
    
    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    srv_ss_cntx_reset_ptr();
}
#endif /* __CCBS_SUPPORT__ */


#ifdef __EMLPP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_ss_phdlr_emlpp_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_phdlr_emlpp_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_emlpp_rsp_struct *rsp = (mmi_ss_emlpp_rsp_struct*)info;
    srv_ss_emlpp_rsp_struct emlpp_rsp;
    srv_ss_rsp_struct ss_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (srv_ss_p->act_info.op != SRV_SS_ACT_SS_OPERATION)
    {
        /* ignore */
        /* abnormal or mo / mt collision (has sent ss op rsp to ss app when receiving mt ussx) */
        srv_ss_cntx_reset_ptr();
        return;
    }

	if (srv_ss_init_rsp(&ss_rsp, &rsp->result, SRV_SS_ACT_EMLPP, srv_ss_p))
	{
        emlpp_rsp.status = SRV_SS_STATUS_ACTIVATED;
        emlpp_rsp.default_pri = rsp->default_pri;
        emlpp_rsp.max_pri = rsp->max_pri;
        ss_rsp.data = (void*)(&emlpp_rsp);
	}
 
    srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    srv_ss_cntx_reset_ptr();
}
#endif /* __EMLPP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ss_init_rsp
 * DESCRIPTION
 *  helper function to init response  message
 * PARAMETERS
 *	rsp	 	[OUT]
 *	result	[IN]
 *	op		[IN]
 *	cntx		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_ss_init_rsp(
	srv_ss_rsp_struct *rsp, 
	l4c_result_struct *result,	 
	srv_ss_act_enum op,
	srv_ss_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (rsp == NULL || result == NULL || cntx == NULL)
	{
		return MMI_FALSE;
	}
	
	rsp->sim = cntx->sim;
    rsp->source = cntx->act_info.source;
    rsp->opcode = op;

    if (result->flag == L4C_OK)
    {
        rsp->result = SRV_SS_RESULT_OK;
        rsp->ps_cause = (srv_ss_ps_cause_enum)0;

		return MMI_TRUE;
    }

    rsp->result = srv_ss_ps_derive_result((srv_ss_ps_cause_enum)result->cause);

    if (rsp->result != SRV_SS_RESULT_ERROR_WITH_PS_CAUSE)
    {
        rsp->ps_cause = (srv_ss_ps_cause_enum)0;
    }
    else
    {
        rsp->ps_cause = (srv_ss_ps_cause_enum)result->cause;
    }

    rsp->data = NULL;
 
	return MMI_FALSE;
}

