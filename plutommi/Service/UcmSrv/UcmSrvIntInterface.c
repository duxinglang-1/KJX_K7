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
 *  UcmSrvIntInterface.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM service internal interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "string.h"
#include "UcmSrvGprot.h"
#include "UcmSrvIntProt.h"
#include "UcmSrvProt.h"

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_indication
 * DESCRIPTION
 *  The function provided by UCM for call srv to send inication
 * PARAMETERS
 *  call_type:       [IN]        Call type
 *  op_code:         [IN]        Indication op code
 *  ind_data:        [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_int_indication(srv_ucm_call_type_enum call_type, srv_ucm_int_ind_opcode_enum op_code, void *ind_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_INT_INDICATION, call_type, op_code);
    
    switch (op_code)
    {
        case SRV_UCM_INT_SYNC_CALL_LIST_IND:
            srv_ucm_sync_call_list(((srv_ucm_int_sync_call_list_ind_struct *)ind_data)->call_list);
            break;
        case SRV_UCM_INT_ALERT_IND:
            srv_ucm_alert_ind(ind_data);
            break;
        case SRV_UCM_INT_CONNECT_IND:
            srv_ucm_connect_ind(ind_data);
            break;
        case SRV_UCM_INT_NOTIFY_IND:            
            srv_ucm_notify_ind(ind_data);
            break;
        case SRV_UCM_INT_SESSION_IND:            
            srv_ucm_session_ind(ind_data);
            break;
        case SRV_UCM_INT_SPEECH_IND:           
            srv_ucm_speech_ind(ind_data);
            break;
        case SRV_UCM_INT_RING_IND:
            srv_ucm_ring_ind(ind_data);
            break;
        case SRV_UCM_INT_DISCONNECTING_IND:
            srv_ucm_disconnecting_ind(ind_data);
            break;
        case SRV_UCM_INT_RELEASE_IND:            
            srv_ucm_release_ind(ind_data);
            break;
        case SRV_UCM_INT_CALL_COST_IND:
            srv_ucm_call_cost_ind(ind_data);
            break;
        case SRV_UCM_INT_AUTO_REDIAL_IND:
            srv_ucm_auto_redial_ind(ind_data);
            break;
    #ifdef __MMI_VOIP__
        case SRV_UCM_INT_START_PROCESSING_IND:
            srv_ucm_start_processing_ind(ind_data);
            break;
        case SRV_UCM_INT_STOP_PROCESSING_IND:
            srv_ucm_stop_processing_ind(ind_data);
            break;
    #endif /* __MMI_VOIP__ */
        case SRV_UCM_INT_REPLACE_IND:
            srv_ucm_replace_ind(ind_data);
            break;
        case SRV_UCM_INT_CANCEL_QUERY_IND:
            srv_ucm_cancel_query_ind(call_type);
            break;
        case SRV_UCM_INT_DIAL_IND:
            srv_ucm_dial_ind(ind_data);
            break;
    #ifdef __MMI_VIDEO_TELEPHONY__
        case SRV_UCM_INT_START_COUNT_IND:
            srv_ucm_start_count_ind(ind_data);
            break;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        default:
            MMI_ASSERT(0); /* not valid indication op_code */
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_cnf_indication
 * DESCRIPTION
 *  The function provided by UCM for call srv to send confirm inication
 * PARAMETERS
 *  call_type:       [IN]        Call type
 *  op_code:         [IN]        Indication op code
 *  ind_data:        [IN]        Data pointer
 *  callback:        [IN]        Confirm callback function provided by call srv
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_int_cnf_indication(srv_ucm_call_type_enum call_type, srv_ucm_int_cnf_ind_opcode_enum op_code, void *ind_data, srv_ucm_int_cnf_callback_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_INT_CNF_INDICATION, call_type, op_code);
    
    switch (op_code)
    {    
        case SRV_UCM_INT_DIAL_CNF_IND:
            srv_ucm_dial_cnf_ind(call_type, ind_data, callback);
            break;
        case SRV_UCM_INT_CALL_PRESENT_CNF_IND:
            srv_ucm_call_present_cnf_ind(call_type, ind_data, callback);
            break;
        case SRV_UCM_INT_QUERY_CNF_IND:
            srv_ucm_query_cnf_ind(call_type, ind_data, callback);
            break;
        default:
            MMI_ASSERT(0); /* not valid indication op_code */
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_register_call_srv_act_callback
 * DESCRIPTION
 *  Call srv can register the action callback to UCM service
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 *  callback:        [IN]        Callback function
 * RETURNS
 *  MMI_TRUE means the callback registration succeeds.
 *  MMI_FALSE means the callback registration fails.
 *****************************************************************************/
MMI_BOOL srv_ucm_int_register_call_srv_act_callback(srv_ucm_call_type_enum call_type, srv_ucm_int_act_callback_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_act_cb[index].call_type == call_type)
        {
            g_ucm_srv_p->call_srv_act_cb[index].act_callback = callback;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_INT_REG_ACT_CALLBACK, index, call_type, callback);
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_unregister_call_srv_act_callback
 * DESCRIPTION
 *  Call srv can unregister the action function
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 *  callback:        [IN]        Callback function
 * RETURNS
 *  MMI_TRUE means the callback registration succeeds.
 *  MMI_FALSE means the callback registration fails.
 *****************************************************************************/
MMI_BOOL srv_ucm_int_unregister_call_srv_act_callback(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_act_cb[index].call_type == call_type)
        {
            g_ucm_srv_p->call_srv_act_cb[index].act_callback = NULL;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_query_call_srv_act_callback
 * DESCRIPTION
 *  Get call service action callback by call type
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 * RETURNS
 *  srv_ucm_int_act_callback_func_ptrs
 *  NULL means no callback is registered
 *****************************************************************************/
srv_ucm_int_act_callback_func_ptr srv_ucm_int_query_call_srv_act_callback(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_act_cb[index].call_type == call_type)
        {
            return g_ucm_srv_p->call_srv_act_cb[index].act_callback;
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_register_call_srv_query_callback
 * DESCRIPTION
 * Call srv can register the query callback to UCM service
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 *  callback:        [IN]        Callback function
 * RETURNS
 *  MMI_TRUE means the callback registration succeeds.
 *  MMI_FALSE means the callback registration fails.
 *****************************************************************************/
MMI_BOOL srv_ucm_int_register_call_srv_query_callback(srv_ucm_call_type_enum call_type, srv_ucm_int_query_callback_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_query_cb[index].call_type == call_type)
        {
            g_ucm_srv_p->call_srv_query_cb[index].query_callback = callback;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_INT_REG_QUERY_CALLBACK, index, call_type, callback);
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_unregister_call_srv_query_callback
 * DESCRIPTION
 *  Call srv can unregister query function
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 * RETURNS
 *  MMI_TRUE means the callback unregistration succeeds.
 *  MMI_FALSE means the callback unregistration fails.
 *****************************************************************************/
MMI_BOOL srv_ucm_int_unregister_call_srv_query_callback(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_query_cb[index].call_type == call_type)
        {
            g_ucm_srv_p->call_srv_query_cb[index].query_callback = NULL;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_query_call_srv_query_callback
 * DESCRIPTION
 *  Call srv can query if the query function is registered
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, no bitwise
 * RETURNS
 *  srv_ucm_int_query_callback_func_ptr
 *  NULL means no callback is registered
 *****************************************************************************/
srv_ucm_int_query_callback_func_ptr srv_ucm_int_query_call_srv_query_callback(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_query_cb[index].call_type == call_type)
        {
            return g_ucm_srv_p->call_srv_query_cb[index].query_callback;
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_register_call_srv_permit_callback
 * DESCRIPTION
 * Call srv can register the permit callback to UCM service
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, can be bitwise
 *  callback:        [IN]        Callback function
 * RETURNS
 *  MMI_TRUE means the callback registration succeeds.
 *  MMI_FALSE means the callback registration fails.
 *****************************************************************************/
MMI_BOOL srv_ucm_int_register_call_srv_permit_callback(srv_ucm_call_type_enum call_type, srv_ucm_int_permit_callback_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_prmt_cb[index].call_type & call_type)
        {
            /* Already exists callback for any of input call types */
            return MMI_FALSE;
        }
    }

    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_prmt_cb[index].call_type == 0)
        {
            /* Find the first empty slot */
            g_ucm_srv_p->call_srv_prmt_cb[index].call_type = call_type;
            g_ucm_srv_p->call_srv_prmt_cb[index].prmt_callback = callback;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_INT_REG_PRMT_CALLBACK, index, call_type, callback);
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_unregister_call_srv_permit_callback
 * DESCRIPTION
 *  Call srv can unregister action permit function
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, can be bitwise
 * RETURNS
 *  MMI_TRUE means the callback unregistration succeeds.
 *  MMI_FALSE means the callback unregistration fails.
 *****************************************************************************/
MMI_BOOL srv_ucm_int_unregister_call_srv_permit_callback(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        if (g_ucm_srv_p->call_srv_prmt_cb[index].call_type == call_type)
        {
            g_ucm_srv_p->call_srv_prmt_cb[index].call_type = SRV_UCM_INVALID_CALL_TYPE;
            g_ucm_srv_p->call_srv_prmt_cb[index].prmt_callback = NULL;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_query_call_srv_permit_callback
 * DESCRIPTION
 *  Call srv can query if the action permit function is registered
 * PARAMETERS
 *  call_type:       [IN]        Call type type, only for single call type, can be bitwise
 * RETURNS
 *  srv_ucm_int_permit_callback_func_ptr
 *  NULL means no callback is registered
 *****************************************************************************/
srv_ucm_int_permit_callback_func_ptr srv_ucm_int_query_call_srv_permit_callback(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_UCM_TOTAL_CALL_TYPE ; index++)
    {
        /* The input call type should be subset of the call type in the cb table */
        if ((g_ucm_srv_p->call_srv_prmt_cb[index].call_type & call_type) == call_type)
        {
            return g_ucm_srv_p->call_srv_prmt_cb[index].prmt_callback;
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_act_request
 * DESCRIPTION
 *  General function for sending action request to call service
 * PARAMETERS
 *  op_code         [IN]            Action op-code
 *  first_ptr       [IN]            First call, usually the current active call
 *  other_ptr       [IN]            Other call, valid for multiple call operation
 *  dial_ptr        [IN]            Dial information, valid for DIAL, DEFLECT and TRANSFER 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_int_act_request(srv_ucm_int_act_opcode_enum int_op_code, srv_ucm_id_info_struct *first, srv_ucm_id_info_struct *other, srv_ucm_dial_info_struct *dial_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_opcode_enum op_code = SRV_UCM_NO_ACT;
    srv_ucm_dial_act_req_struct dial_req;
    srv_ucm_int_dial_act_req_struct int_dial_req;
    srv_ucm_single_call_act_req_struct single_call_req;
    srv_ucm_int_single_call_act_req_struct int_single_call_req;
    srv_ucm_single_group_act_req_struct single_group_req;
    srv_ucm_int_single_group_act_req_struct int_single_group_req;
    srv_ucm_multiple_group_act_req_struct multiple_group_req;
    srv_ucm_int_multiple_group_act_req_struct int_multiple_group_req;
#if (defined(__MMI_UCM_DEFLECT__) || defined(__MMI_UCM_TRANSFER__))
    srv_ucm_cd_or_ct_act_req_struct dt_ct_req;
    srv_ucm_int_cd_or_ct_act_req_struct int_dt_ct_req;
#endif
#ifdef __MMI_UCM_ECT__
    srv_ucm_ect_act_req_struct ect_req;
    srv_ucm_int_ect_act_req_struct int_ect_req;
#endif
    srv_ucm_int_end_all_act_req_struct int_end_all_req;
    srv_ucm_int_act_rsp_callback_func_ptr rsp_callback = srv_ucm_int_act_rsp_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((int_op_code != SRV_UCM_INT_FORCE_RELEASE_ACT) &&
        (int_op_code != SRV_UCM_INT_AUTO_REJECT_ACT))
    {
        op_code = srv_ucm_query_act_op(int_op_code);
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_INT_ACT_REQUEST, first->call_type, int_op_code);    

    switch (int_op_code)
    {
        case SRV_UCM_INT_DIAL_ACT:

            /* Send action start notify */
            memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));
            dial_req.call_type = g_ucm_srv_p->dial_info.dial_type;
            dial_req.is_ip_dial = g_ucm_srv_p->dial_info.is_ip_dial;
            dial_req.module_id = g_ucm_srv_p->dial_info.module_id;
            memcpy(&dial_req.num_uri, &g_ucm_srv_p->dial_info.num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_START, (void *)&dial_req);
            
            /* Send action request to call service */
            memset(&int_dial_req, 0, sizeof(srv_ucm_int_dial_act_req_struct));
            memcpy(&int_dial_req.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));           
            int_dial_req.module_id = dial_ptr->module_id; 
            memcpy(int_dial_req.num_uri, dial_ptr->num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            int_dial_req.is_ip_dial = dial_ptr->is_ip_dial;
            int_dial_req.phb_data = dial_ptr->phb_data;
            srv_ucm_int_query_call_srv_act_callback(first->call_type)
                (first->call_type, int_op_code, (void *)&int_dial_req, (void *)g_ucm_srv_p->call_misc.user_data, rsp_callback);
            break;

        case SRV_UCM_INT_ACCEPT_ACT:
        case SRV_UCM_INT_SPLIT_ACT:
        case SRV_UCM_INT_END_SINGLE_ACT:
        case SRV_UCM_INT_FORCE_RELEASE_ACT:
        case SRV_UCM_INT_AUTO_REJECT_ACT:
    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_INT_VT_FALLTO_VOICE_ACT:
    #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */

            /* Send action start notify */
            if (((int_op_code != SRV_UCM_INT_END_SINGLE_ACT) &&
                (int_op_code != SRV_UCM_INT_FORCE_RELEASE_ACT) &&
                (int_op_code != SRV_UCM_INT_AUTO_REJECT_ACT)) ||
                ((int_op_code == SRV_UCM_INT_END_SINGLE_ACT) &&
                (g_ucm_srv_p->call_misc.is_pending_end_act == MMI_FALSE) &&
                (g_ucm_srv_p->call_misc.end_processing_count == 0)))
            {
                memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
                memcpy(&single_call_req.action_uid, first, sizeof(srv_ucm_id_info_struct));
                srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_START, (void *)&single_call_req);
            }

            /* Send action request to call service */
            memset(&int_single_call_req, 0, sizeof(srv_ucm_int_single_call_act_req_struct));
            memcpy(&int_single_call_req.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            memcpy(&int_single_call_req.action_uid, first, sizeof(srv_ucm_id_info_struct));
            srv_ucm_int_query_call_srv_act_callback(first->call_type)
                (first->call_type, int_op_code, (void *)&int_single_call_req, NULL, rsp_callback);
            break;

        case SRV_UCM_INT_HOLD_ACT:
        case SRV_UCM_INT_RETRIEVE_ACT:
        case SRV_UCM_INT_END_CONFERENCE_ACT:

            /* Send action start notify */
            if ((int_op_code != SRV_UCM_INT_END_CONFERENCE_ACT) ||
                ((int_op_code == SRV_UCM_INT_END_CONFERENCE_ACT) && (g_ucm_srv_p->call_misc.is_pending_end_act == MMI_FALSE)))
            { 
                memset(&single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
                single_group_req.action_group = first->group_id;
                single_group_req.call_type = first->call_type;
                srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_START, (void *)&single_group_req);
            }

            /* Send action request to call service */
            memset(&int_single_group_req, 0, sizeof(srv_ucm_int_single_group_act_req_struct));
            memcpy(&int_single_group_req.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            int_single_group_req.action_group = first->group_id;
            srv_ucm_int_query_call_srv_act_callback(first->call_type)
                (first->call_type, int_op_code, (void *)&int_single_group_req, NULL, rsp_callback);
            break;

        case SRV_UCM_INT_SWAP_ACT:
        case SRV_UCM_INT_CONFERENCE_ACT:

            /* Send action start notify */
            memset(&multiple_group_req, 0, sizeof(srv_ucm_multiple_group_act_req_struct));
            multiple_group_req.active_group = first->group_id;
            multiple_group_req.active_call_type = first->call_type;
            multiple_group_req.other_group = other->group_id;
            multiple_group_req.other_call_type = other->call_type;
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_START, (void *)&multiple_group_req);
            
            /* Send action request to call service */
            memset(&int_multiple_group_req, 0, sizeof(srv_ucm_int_multiple_group_act_req_struct));
            memcpy(&int_multiple_group_req.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            int_multiple_group_req.active_group = first->group_id;
            int_multiple_group_req.other_group = other->group_id;
            srv_ucm_int_query_call_srv_act_callback(first->call_type)
                (first->call_type, int_op_code, (void *)&int_multiple_group_req, NULL, rsp_callback);
            break;

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_INT_DEFLECT_ACT:
    #endif /* __MMI_UCM_DEFLECT__ */
    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_INT_TRANSFER_ACT:
    #endif /* __MMI_UCM_TRANSFER__ */

        #if (defined(__MMI_UCM_DEFLECT__) || defined(__MMI_UCM_TRANSFER__))
            /* Send action start notify */
            memset(&dt_ct_req, 0, sizeof(srv_ucm_cd_or_ct_act_req_struct));
            memcpy(&dt_ct_req.action_uid, first, sizeof(srv_ucm_id_info_struct));
            memcpy(dt_ct_req.num_uri, dial_ptr->num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_START, (void *)&dt_ct_req);
            
            /* Send action request to call service */
            memset(&int_dt_ct_req, 0, sizeof(srv_ucm_int_cd_or_ct_act_req_struct));
            memcpy(&int_dt_ct_req.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            memcpy(&int_dt_ct_req.action_uid, first, sizeof(srv_ucm_id_info_struct));
            memcpy(int_dt_ct_req.num_uri, dial_ptr->num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            srv_ucm_int_query_call_srv_act_callback(first->call_type)
                (first->call_type, int_op_code, (void *)&int_dt_ct_req, NULL, rsp_callback);
            break;
        #endif /* (defined(__MMI_UCM_DEFLECT__) || defined(__MMI_UCM_TRANSFER__)) */

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT:

            /* Send action start notify */
            memset(&ect_req, 0, sizeof(srv_ucm_ect_act_req_struct));
            ect_req.first_group = first->group_id;
            ect_req.first_call_type = first->call_type;
            ect_req.second_group = other->group_id;
            ect_req.second_call_type = other->call_type;
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_START, (void *)&ect_req);

            /* Send action request to call service */
            memset(&int_ect_req, 0, sizeof(srv_ucm_int_ect_act_req_struct));
            memcpy(&int_ect_req.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            int_ect_req.first_group = first->group_id;
            int_ect_req.second_group = other->group_id;
            srv_ucm_int_query_call_srv_act_callback(first->call_type)
                (first->call_type, int_op_code, (void *)&int_ect_req, NULL, rsp_callback);
            break;
    #endif /* __MMI_UCM_ECT__ */

        case SRV_UCM_INT_END_ALL_ACT:

            /* Send action start notify */
            if (g_ucm_srv_p->call_misc.is_pending_end_act == MMI_FALSE)
            { 
                srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_START, NULL);
            }

            /* Send action request to call service */
            memset(&int_end_all_req, 0, sizeof(srv_ucm_int_end_all_act_req_struct));
            memcpy(&int_end_all_req.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            srv_ucm_int_query_call_srv_act_callback(first->call_type)
                (first->call_type, int_op_code, (void *)&int_end_all_req, NULL, rsp_callback);
            break;
    
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_act_rsp_hdlr
 * DESCRIPTION
 *  UCM service action response handler
 * PARAMETERS
 *  op_code:         [IN]            Operation code
 *  call_type:       [IN]            Call type
 *  rsp_struct:      [IN]            Response structure
 *  user_data:       [IN]            User data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_int_act_rsp_hdlr(srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum int_op_code, void *rsp_struct, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_INT_ACT_RESPONSE, call_type, int_op_code);  

    if ((g_ucm_srv_p->call_misc.curr_action == SRV_UCM_NO_ACT) ||
        (g_ucm_srv_p->call_misc.end_processing_count > 0))
    {
        /* No action is performing or during end all processing */
        return;
    }

    switch (int_op_code)
    {
        case SRV_UCM_INT_DIAL_ACT:
            srv_ucm_dial_act_rsp(rsp_struct);
            break;
        case SRV_UCM_INT_ACCEPT_ACT:
            srv_ucm_accept_act_rsp(rsp_struct);
            break;
        case SRV_UCM_INT_HOLD_ACT:
        case SRV_UCM_INT_SPLIT_ACT:
        case SRV_UCM_INT_RETRIEVE_ACT:
        case SRV_UCM_INT_CONFERENCE_ACT:
    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_INT_DEFLECT_ACT:
    #endif /* __MMI_UCM_DEFLECT__ */
    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_INT_TRANSFER_ACT:
    #endif /* __MMI_UCM_TRANSFER__ */
    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT:
    #endif /* __MMI_UCM_ECT__ */
    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_INT_VT_FALLTO_VOICE_ACT:
    #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
            srv_ucm_act_rsp(int_op_code, rsp_struct);
            break;
        case SRV_UCM_INT_SWAP_ACT:
            srv_ucm_swap_act_rsp(rsp_struct);
            break;
        case SRV_UCM_INT_END_SINGLE_ACT:
        case SRV_UCM_INT_END_CONFERENCE_ACT:
        case SRV_UCM_INT_END_ALL_ACT:
            srv_ucm_end_act_rsp(int_op_code, rsp_struct);
            break;
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_permit
 * DESCRIPTION
 *  General function to use call service permit function
 * PARAMETERS
 *  op_code         [IN]            Operation code
 *  first_ptr       [IN]            First call, usually the current active call
 *  other_ptr       [IN]            Other call, valid for multiple call operation
 *  dial_ptr        [IN]            Dial information, valid for DIAL, DEFLECT and TRANSFER 
 * RETURNS
 *  srv_ucm_result_enum
 *****************************************************************************/
srv_ucm_result_enum srv_ucm_int_permit(srv_ucm_int_prmt_opcode_enum prmt_code, srv_ucm_id_info_struct *first, srv_ucm_id_info_struct *other, srv_ucm_dial_info_struct *dial_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_act_prmt_struct dial_prmt;
    srv_ucm_int_single_call_act_prmt_struct single_call_prmt;
    srv_ucm_int_single_group_act_prmt_struct single_group_prmt;
    srv_ucm_int_multiple_group_act_prmt_struct multiple_group_prmt;
#if (defined(__MMI_UCM_DEFLECT__) || defined(__MMI_UCM_TRANSFER__))
    srv_ucm_int_cd_or_ct_act_prmt_struct dt_ct_prmt;
#endif
#ifdef __MMI_UCM_ECT__
    srv_ucm_int_ect_act_prmt_struct ect_prmt;
#endif
    srv_ucm_int_end_all_act_prmt_struct end_all_prmt;
    srv_ucm_int_hold_and_dial_act_prmt_struct hold_and_dial_prmt;
    srv_ucm_int_hold_and_accept_act_prmt_struct hold_and_accept_prmt;
    srv_ucm_result_enum result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (prmt_code)
    {
        case SRV_UCM_INT_DIAL_PRMT:
        case SRV_UCM_INT_END_ALL_AND_DIAL_PRMT:
            memset(&dial_prmt, 0, sizeof(srv_ucm_int_dial_act_prmt_struct));
            memcpy(&dial_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));           
            dial_prmt.module_id = dial_ptr->module_id; 
            memcpy(dial_prmt.num_uri, dial_ptr->num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            dial_prmt.is_ip_dial = dial_ptr->is_ip_dial;
            result = srv_ucm_int_query_call_srv_permit_callback(dial_ptr->dial_type)(dial_ptr->dial_type, prmt_code, (void *)&dial_prmt);
            break;

        case SRV_UCM_INT_ACCEPT_PRMT:
        case SRV_UCM_INT_SPLIT_PRMT:
        case SRV_UCM_INT_END_SINGLE_PRMT:
        case SRV_UCM_INT_FORCE_RELEASE_PRMT:
        case SRV_UCM_INT_AUTO_REJECT_PRMT:
        case SRV_UCM_INT_END_ALL_AND_ACCEPT_PRMT:
        case SRV_UCM_INT_END_ALL_ACTIVE_AND_ACCEPT_PRMT:
    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_INT_VT_FALLTO_VOICE_PRMT:
    #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
            memset(&single_call_prmt, 0, sizeof(srv_ucm_int_single_call_act_prmt_struct));
            memcpy(&single_call_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            memcpy(&single_call_prmt.action_uid, first, sizeof(srv_ucm_id_info_struct));
            result = srv_ucm_int_query_call_srv_permit_callback(first->call_type)(first->call_type, prmt_code, (void *)&single_call_prmt);
            break;

        case SRV_UCM_INT_HOLD_PRMT:
        case SRV_UCM_INT_RETRIEVE_PRMT:
        case SRV_UCM_INT_END_CONFERENCE_PRMT:
        case SRV_UCM_INT_END_ALL_ACTIVE_AND_RETRIEVE_PRMT:
            memset(&single_group_prmt, 0, sizeof(srv_ucm_int_single_group_act_prmt_struct));
            memcpy(&single_group_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            single_group_prmt.action_group = first->group_id;
            result = srv_ucm_int_query_call_srv_permit_callback(first->call_type)(first->call_type, prmt_code, (void *)&single_group_prmt);
            break;

        case SRV_UCM_INT_SWAP_PRMT:
        case SRV_UCM_INT_CONFERENCE_PRMT:
            memset(&multiple_group_prmt, 0, sizeof(srv_ucm_int_multiple_group_act_prmt_struct));
            memcpy(&multiple_group_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            multiple_group_prmt.active_group = first->group_id;
            multiple_group_prmt.other_group = other->group_id;
            result = srv_ucm_int_query_call_srv_permit_callback(first->call_type)(first->call_type, prmt_code, (void *)&multiple_group_prmt);
            break;

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_INT_DEFLECT_PRMT:
    #endif /* __MMI_UCM_DEFLECT__ */
    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_INT_TRANSFER_PRMT:
    #endif /* __MMI_UCM_TRANSFER__ */

        #if (defined(__MMI_UCM_DEFLECT__) || defined(__MMI_UCM_TRANSFER__))
            memset(&dt_ct_prmt, 0, sizeof(srv_ucm_int_cd_or_ct_act_prmt_struct));
            memcpy(&dt_ct_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            memcpy(&dt_ct_prmt.action_uid, first, sizeof(srv_ucm_id_info_struct));
            memcpy(dt_ct_prmt.num_uri, dial_ptr->num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            result = srv_ucm_int_query_call_srv_permit_callback(first->call_type)(first->call_type, prmt_code, (void *)&dt_ct_prmt);
            break;
        #endif /* (defined(__MMI_UCM_DEFLECT__) || defined(__MMI_UCM_TRANSFER__)) */

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_PRMT:
            memset(&ect_prmt, 0, sizeof(srv_ucm_int_ect_act_prmt_struct));
            memcpy(&ect_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            ect_prmt.first_group = first->group_id;
            ect_prmt.second_group = other->group_id;
            result = srv_ucm_int_query_call_srv_permit_callback(first->call_type)(first->call_type, prmt_code, (void *)&ect_prmt);
            break;
    #endif /* __MMI_UCM_ECT__ */

        case SRV_UCM_INT_END_ALL_PRMT:
            memset(&end_all_prmt, 0, sizeof(srv_ucm_int_end_all_act_prmt_struct));
            memcpy(&end_all_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            result = srv_ucm_int_query_call_srv_permit_callback(first->call_type)(first->call_type, prmt_code, (void *)&end_all_prmt);
            break;

        case SRV_UCM_INT_HOLD_AND_DIAL_PRMT:
            memset(&hold_and_dial_prmt, 0, sizeof(srv_ucm_int_hold_and_dial_act_prmt_struct));
            memcpy(&hold_and_dial_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));           
            hold_and_dial_prmt.active_group = first->group_id;
            hold_and_dial_prmt.module_id = dial_ptr->module_id;
            hold_and_dial_prmt.dial_type = dial_ptr->dial_type; 
            memcpy(hold_and_dial_prmt.num_uri, dial_ptr->num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            hold_and_dial_prmt.is_ip_dial = dial_ptr->is_ip_dial;
            result= srv_ucm_int_query_call_srv_permit_callback(dial_ptr->dial_type)(dial_ptr->dial_type, prmt_code, (void *)&hold_and_dial_prmt);
            break;

        case SRV_UCM_INT_HOLD_AND_ACCEPT_PRMT:
            memset(&hold_and_accept_prmt, 0, sizeof(srv_ucm_int_hold_and_accept_act_prmt_struct));
            memcpy(&hold_and_accept_prmt.at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
            hold_and_accept_prmt.action_group = first->group_id;
            memcpy(&hold_and_accept_prmt.mt_call_uid, other, sizeof(srv_ucm_id_info_struct));
            result = srv_ucm_int_query_call_srv_permit_callback(other->call_type)(other->call_type, prmt_code, (void *)&hold_and_accept_prmt);
            break;

        case SRV_UCM_INT_START_DTMF_PRMT:            
        case SRV_UCM_INT_STOP_DTMF_PRMT:
            /* Under construction */
            break;
    
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_int_query
 * DESCRIPTION
 *  General function to use call service query function
 * PARAMETERS
 *  call_type       [IN]            Call type
 *  query_type      [IN]            Query type
 *  ptr             [IN]            Data pointer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_ucm_int_query(srv_ucm_call_type_enum call_type, srv_ucm_int_query_enum query_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_number_struct number;
    srv_ucm_dtmf_struct digit;
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ucm_int_query_call_srv_query_callback(call_type) == NULL)
    {
        return result;
    }

    switch (query_type)
    {
        case SRV_UCM_INT_NUMBER:
        case SRV_UCM_INT_ECC_NUMBER:
            memset(&number, 0, sizeof(srv_ucm_int_query_number_struct));
            memcpy(&number, ptr, sizeof(srv_ucm_int_query_number_struct));         
            result = srv_ucm_int_query_call_srv_query_callback(call_type)(call_type, query_type, (void *)&number);
            break;

        case SRV_UCM_INT_DTMF_DIGIT:
            memset(&digit, 0, sizeof(srv_ucm_dtmf_struct));
            memcpy(&digit, ptr, sizeof(srv_ucm_dtmf_struct));           
            result = srv_ucm_int_query_call_srv_query_callback(call_type)(call_type, query_type, (void *)&digit);
            break;

        case SRV_UCM_INT_CALL_SRV_AVAILABLE:
        case SRV_UCM_INT_CALL_SRV_TMP_UNAVAILABLE:  
            result = srv_ucm_int_query_call_srv_query_callback(call_type)(call_type, query_type, NULL);
            break;

        case SRV_UCM_INT_CALLER_RES:
            result = srv_ucm_int_query_call_srv_query_callback(call_type)(call_type, query_type, ptr);
            break;

        default:
            MMI_ASSERT(0); /* not valid query type */
            break;
    }

    return result;
}


