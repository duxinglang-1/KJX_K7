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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   GCallSrvCmEvent.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  GSM / 3G call service
 *  Process call management events
 *
 * Author:
 * -------
 *  
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


#include "SatSrvGprot.h"

#include "UcmSrvGprot.h"
#include "..\UcmSrv\UCMSrvIntProt.h"

#include "GCallSrvProt.h"

#include "GCallSrvDef.h"
#include "l3_inc_enums.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_release.h"
#include "kal_non_specific_general_types.h"
#include "l4c2abm_struct.h"
#include "mmi_msg_struct.h"
#include "csmcc_common_enums.h"
#include "string.h"
#include "l4c_aux_struct.h"


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_proc_cm_event
 * DESCRIPTION
 *  This is the Entry function for all the Events while the Call-Management application
 *  is Active.
 *  
 * PARAMETERS
 *  event           [IN]        event id
 *  info            [IN]        data
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_proc_cm_event(srv_gcall_cm_event_enum event, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __LOW_COST_SUPPORT_COMMON__
    U16 result = SRV_GCALL_RESULT_NOT_SUPPORT;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PROC_CM_EVENT, event);

    MMI_ASSERT(cm_p);

    switch (event)
    {
    #ifdef __CPI_SUPPORT__
        case SRV_GCALL_CM_EVENT_CPI_INIT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_cpi_init();
            break;
    #endif /* __CPI_SUPPORT__ */

    #ifdef __AUTO_CALL_REJECTION__
        case SRV_GCALL_CM_EVENT_MT_PRESENT_INIT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_mt_present_init();
            break;

        case SRV_GCALL_CM_EVENT_MT_PRESENT_CNF:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_mt_present_cnf(info);
            break;
    #endif /* __AUTO_CALL_REJECTION__ */

        case SRV_GCALL_CM_EVENT_ACCEPT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_accept(info);
            break;

        case SRV_GCALL_CM_EVENT_DIAL_CNF:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_dial_cnf(info);
            break;

        case SRV_GCALL_CM_EVENT_DIAL_NORMAL:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_dial_normal(info);
            break;

    #ifdef __SAT__
        case SRV_GCALL_CM_EVENT_DIAL_SAT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_dial_sat(info);
            break;
    #endif /* __SAT__ */

    #ifdef __CCBS_SUPPORT__
        case SRV_GCALL_CM_EVENT_DIAL_CCBS:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_dial_ccbs(info);
            break;

        case SRV_GCALL_CM_EVENT_CCBS_RECALL_ACCEPT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_ccbs_accept();
            break;

        case SRV_GCALL_CM_EVENT_CCBS_RECALL_REJECT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_ccbs_reject();
            break;

        case SRV_GCALL_CM_EVENT_CCBS_IGNORE:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_ccbs_ignore();
            break;
        
        case SRV_GCALL_CM_EVENT_CCBS_ACTIVATE:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_ccbs_activate();
            break;
    #endif /* __CCBS_SUPPORT__ */

        case SRV_GCALL_CM_EVENT_END_SINGLE:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_end_single(info);
            break;

        case SRV_GCALL_CM_EVENT_END_CONF:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_end_conf(info);
            break;

        case SRV_GCALL_CM_EVENT_END_ALL:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_end_all(info);
            break;

        case SRV_GCALL_CM_EVENT_AUTO_REJECT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_auto_reject(info);
            break;

        case SRV_GCALL_CM_EVENT_FORCE_RELEASE:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_force_release(info);
            break;

        case SRV_GCALL_CM_EVENT_SWAP:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_swap(info);
            break;

        case SRV_GCALL_CM_EVENT_CONF:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_conf(info);
            break;

        case SRV_GCALL_CM_EVENT_SPLIT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_split(info);
            break;

    #ifdef __MMI_UCM_ECT__
        case SRV_GCALL_CM_EVENT_ECT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_ect(info);
            break;
    #endif /* __MMI_UCM_ECT__ */

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_GCALL_CM_EVENT_DEFLECT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_deflect(info);
            break;
    #endif /* __MMI_UCM_DEFLECT__ */

        case SRV_GCALL_CM_EVENT_START_DTMF:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_start_dtmf(info);
            break;

        case SRV_GCALL_CM_EVENT_STOP_DTMF:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_stop_dtmf();
            break;

        case SRV_GCALL_CM_EVENT_AUTO_DTMF:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_auto_dtmf();
            break;

    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_GCALL_CM_EVENT_VT_FALLTO_VOICE_ACT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_cm_vt_fallto_voice(info);
            break;
    #endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */

         default:
            break;
    }

#ifndef __LOW_COST_SUPPORT_COMMON__
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PROC_CM_EVENT_RESULT, event, result);
#else
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PROC_CM_EVENT_RESULT, event, SRV_GCALL_RESULT_OK);
#endif

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cm_accept
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_cm_accept(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_set_l4c_source((U8)(((srv_ucm_int_single_call_act_req_struct*)info)->at_info.l4c_source));

    srv_gcall_l4c_ata_req();

    return SRV_GCALL_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cm_dial_cnf
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_cm_dial_cnf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_cnf_struct *cnf = (srv_ucm_int_dial_cnf_struct*)info;
    U16 result;
    U8 number[SRV_GCALL_MAX_NUMBER];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!cnf)
    {
        result = SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }
    else if (cnf->result)
    {
        if (srv_gcall_util_op_need_rsp(cm_p->ucm_info.op))
        {
            /* busy, cannot overwrite op */
            result = SRV_GCALL_RESULT_BUSY;
        }
        else
        {
            result = SRV_GCALL_RESULT_OK;
            srv_gcall_reset_ucm_info_except_bg_op();
            cm_p->ucm_info.op = SRV_UCM_INT_DIAL_ACT;
            cm_p->ucm_info.call_type = 
                srv_gcall_get_ucm_call_type((srv_gcall_type_enum)(cm_p->data_call_info_p->call_type));
            cm_p->ucm_info.l4c_source = cm_p->data_call_info_p->source_id;

            /* derive number */
            memset(number, 0, SRV_GCALL_MAX_NUMBER);
            if (cm_p->data_call_info_p->number.number[0] != '\0')
            {
                /* International number: the 5th bit is on, and 6th, 7th are both off */
                if ((0x10 & cm_p->data_call_info_p->number.type) && !(0x20 & cm_p->data_call_info_p->number.type) && !(0x40 & cm_p->data_call_info_p->number.type))
                {
                    strcpy((CHAR *)number, "+");
                }
                strcat((CHAR *)number, (CHAR *)(cm_p->data_call_info_p->number.number));
            }

            srv_gcall_add_new_call_info(number, 
                SRV_GCALL_STATE_OUTGOING, 
                SRV_GCALL_DIR_MO, SRV_GCALL_MO_TEMP_ID, 
                (srv_gcall_type_enum)(cm_p->data_call_info_p->call_type));
        }
    }
    else
    {
        result = SRV_GCALL_RESULT_DISALLOW_MORE_CALL;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CM_DIAL_CNF, result);

    if (result == SRV_GCALL_RESULT_OK)
    {
        srv_gcall_l4c_data_call_res_req(CALL_DIAL, MMI_TRUE);
    }
    else if (result == SRV_GCALL_RESULT_DISALLOW_MORE_CALL)
    {
        srv_gcall_l4c_data_call_res_req(CALL_DIAL, MMI_FALSE);
    }
    else
    {
        MMI_ASSERT(0);
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cm_dial_normal
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_cm_dial_normal(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_gcall_cm_dial(info);
    if (result != SRV_GCALL_RESULT_OK)
    {
        return result;
    }

    srv_gcall_l4c_ss_parsing_string_req();

    return SRV_GCALL_RESULT_OK;
}


#ifdef __SAT__
/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cm_dial_sat
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_cm_dial_sat(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_gcall_cm_dial(info);
    if (result != SRV_GCALL_RESULT_OK)
    {
        return result;
    }

    srv_sat_terminal_response_setup_call_stage1(cm_p->interface);

    return SRV_GCALL_RESULT_OK;
}
#endif /* __SAT__ */


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cm_dial
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_cm_dial(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_act_req_struct *msg = (srv_ucm_int_dial_act_req_struct*)info;
    srv_gcall_dir_enum dir;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check number validity */
    if (!(msg->num_uri[0]))
    {
        srv_gcall_ucm_error(cm_p->ucm_info.call_type, SRV_GCALL_RESULT_EMPTY_NUMBER);
        return SRV_GCALL_RESULT_EMPTY_NUMBER;
    }
    if ((msg->module_id != SRV_UCM_MODULE_ORIGIN_AT)
    #if (MMI_MAX_SIM_NUM >= 2)
        && (msg->module_id != SRV_UCM_MODULE_ORIGIN_AT_SIM2)
    #if (MMI_MAX_SIM_NUM >= 3)
        && (msg->module_id != SRV_UCM_MODULE_ORIGIN_AT_SIM3)
    #if (MMI_MAX_SIM_NUM == 4)
        && (msg->module_id != SRV_UCM_MODULE_ORIGIN_AT_SIM4)
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        && !srv_gcall_util_is_valid_number(cm_p->interface, msg->num_uri, (msg->module_id == SRV_UCM_MODULE_ORIGIN_SAT) ? SRV_GCALL_DIR_MO_STK : SRV_GCALL_DIR_MO))
    {
        /* don't check string format for ATD */
        /* ATD string must be in valid character set (0-9, *, #, p, P, i, I, g, G, +)
         * (may not be with valid telephone number format) 
         * and with valid length, which is guaranteed by L4 */
        srv_gcall_ucm_error(cm_p->ucm_info.call_type, SRV_GCALL_RESULT_INVALID_NUMBER_FORMAT);
        return SRV_GCALL_RESULT_INVALID_NUMBER_FORMAT;
    }

    srv_gcall_set_l4c_source((U8)(msg->at_info.l4c_source));

    /* keep the mo info */
    strncpy((CHAR *)cm_p->mo.num, (CHAR *)msg->num_uri, SRV_GCALL_MAX_NUMBER - 1);

    if (msg->module_id == SRV_UCM_MODULE_ORIGIN_SAT)
    {
        dir = SRV_GCALL_DIR_MO_STK;
    }
    else
    {
        dir = SRV_GCALL_DIR_MO;
    }

#ifdef __IP_NUMBER__
    cm_p->mo.is_ip_dial = msg->is_ip_dial;
    if (srv_gcall_util_is_valid_ecc(cm_p->interface, msg->num_uri, dir))
    {
        cm_p->mo.is_ip_dial = MMI_FALSE;
    }
#endif /* __IP_NUMBER__ */
    cm_p->mo.module_id = msg->module_id;

    if (cm_p->redial_info.phb_data
        && (cm_p->redial_info.phb_data != msg->phb_data))
    {
        /* clear kept phb_data if it is not a post action */
        srv_gcall_util_mgmt_phb_info(MMI_FALSE, cm_p->redial_info.phb_data);
        cm_p->redial_info.phb_data = NULL;
    }

    if (!cm_p->redial_info.phb_data)
    {
        /* keep phb_data for potential redial or post action */
        /* don't hold user data again if redial_info.user_data is not NULL (already hold user_data in the previous redial / post action */
        if (srv_gcall_util_mgmt_phb_info(MMI_TRUE, msg->phb_data))
        {
            cm_p->redial_info.phb_data = msg->phb_data;
        }
    }

    srv_gcall_add_new_call_info(msg->num_uri, 
        SRV_GCALL_STATE_OUTGOING, 
        dir, SRV_GCALL_MO_TEMP_ID, 
        srv_gcall_util_get_internal_call_type(cm_p->ucm_info.call_type));

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_end_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_end_single(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *req = (srv_ucm_int_single_call_act_req_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)req->action_uid.call_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    srv_gcall_set_l4c_source((U8)(req->at_info.l4c_source));

    call_info->status_flag |= (SRV_GCALL_STATUS_HANGUP_REQUESTED | SRV_GCALL_STATUS_DISCONNECTING);

    /* use REL_SPECIFIC_CALL
        release with cause 17 for incoming call or waiting call
        release with cause 16 for active call or held call */
    /* use REL_SPECIFIC_CALL instead of REL_UDUB to release the waiting call since
        in some race condition that the call is not a waiting call for the 
        protocol stack, it is not allowed to use REL_UDUB to release the call */

    srv_gcall_l4c_chld_req(CSMCC_REL_SPECIFIC_CALL, call_info->call_id);

    if (call_info->call_id != cm_p->auto_reject_call_id)
    {
        srv_gcall_ucm_disconnecting_ind(call_info);
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_end_conf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_end_conf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_group_act_req_struct *req = (srv_ucm_int_single_group_act_req_struct*)info;
    srv_gcall_call_info_struct *call_info;
    U8 count;
    srv_gcall_state_enum state = SRV_GCALL_STATE_IDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_set_l4c_source((U8)(req->at_info.l4c_source));

    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        call_info = &(cm_p->call_list[count]);

        if (call_info->group_id == req->action_group)
        {
            state = call_info->curr_state;
            break;
        }
    }

    switch (state)
    {
        case SRV_GCALL_STATE_ACTIVE:
            srv_gcall_l4c_chld_req(CSMCC_REL_ACTIVE, 0);
            break;

        case SRV_GCALL_STATE_HOLD:
            srv_gcall_l4c_chld_req(CSMCC_REL_HELD, 0);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        call_info = &(cm_p->call_list[count]);

        if (call_info->group_id == req->action_group)
        {
            /* action call */
            call_info->status_flag |= (SRV_GCALL_STATUS_HANGUP_REQUESTED | SRV_GCALL_STATUS_DISCONNECTING);
            srv_gcall_ucm_disconnecting_ind(call_info);
        }

    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_end_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_end_all(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_end_all_act_req_struct *req = (srv_ucm_int_end_all_act_req_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_set_l4c_source((U8)(req->at_info.l4c_source));

    if (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_INCOMING, (srv_gcall_type_enum)0))
    {
        srv_gcall_cm_end_all_ext(MMI_FALSE, info);
    }
    else
    {
        /* to prevent from releasing unknown mt call (the mt call which has not been processed by MMI yet) */
        srv_gcall_cm_end_all_ext(MMI_TRUE, info);
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_end_all_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_end_all_ext(MMI_BOOL excpt_wait, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_call_info_struct *call_info;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (excpt_wait)
    {
        srv_gcall_l4c_chld_req(CSMCC_REL_ALL_EXCEPT_WAITING_CALL, 0);
    }
    else
    {
        srv_gcall_l4c_chld_req(CSMCC_REL_ALL, 0);
    }

    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        call_info = &(cm_p->call_list[count]);

        if ((call_info->curr_state != SRV_GCALL_STATE_IDLE)
            && (!excpt_wait || (call_info->curr_state != SRV_GCALL_STATE_INCOMING)))
        {
            /* action call */
            call_info->status_flag |= (SRV_GCALL_STATUS_HANGUP_REQUESTED | SRV_GCALL_STATUS_DISCONNECTING);

            if (call_info->call_id != cm_p->auto_reject_call_id)
            {
                srv_gcall_ucm_disconnecting_ind(call_info);
            }
        }
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_auto_reject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_auto_reject(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *msg = (srv_ucm_int_single_call_act_req_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)msg->action_uid.call_id);
    srv_gcall_call_info_struct *out_call;
    srv_ucm_int_end_all_act_req_struct end_all_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    cm_p->auto_reject_call_id = call_info->call_id;

    if (cm_p->ucm_info.op == SRV_UCM_INT_NO_ACT)
    {
        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_END_SINGLE, msg);
    }
    else
    {
        /* UCM is not idle, release all since gsm call app cannot do multiple op simutenously */
        /* GSM protocol can only handle 1 action at 1 time, so use end all to drop all calls */

        if (cm_p->ucm_info.op == SRV_UCM_INT_DIAL_ACT)
        {
            /* run full call fail procedures to make sure the call table is valid */
            out_call = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);
            MMI_ASSERT(out_call);

            cm_p->release_call_info.cause = 0;
            cm_p->release_call_info.state = out_call->curr_state;
            cm_p->release_call_info.dir = out_call->dir;
            cm_p->release_call_info.call_id = out_call->call_id;
            cm_p->release_call_info.call_type = out_call->call_type;
            cm_p->release_call_info.group_id = out_call->group_id;

            srv_gcall_ps_rel_outgoing(out_call);
        }
        else
        {
            srv_gcall_ucm_error(cm_p->ucm_info.call_type, SRV_GCALL_RESULT_L4C_GEN_CAUSE);
        }

        memset(&end_all_req, 0, sizeof(srv_ucm_int_end_all_act_req_struct));
        memcpy(&(end_all_req.at_info), &(msg->at_info), sizeof(srv_ucm_int_at_info_struct));

        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_END_ALL, &end_all_req);
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_force_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_force_release(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *msg = (srv_ucm_int_single_call_act_req_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)msg->action_uid.call_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    cm_p->ps_info.chld_type = CSMCC_INVALID_CRSS_TYPE;

    srv_gcall_l4c_rel_comp_req((U8)msg->action_uid.call_id);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_swap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_swap(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_set_l4c_source(*((U8*)info));

    srv_gcall_l4c_chld_req(CSMCC_SWAP_CALL, 0);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_conf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_conf(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_multiple_group_act_req_struct *msg = (srv_ucm_int_multiple_group_act_req_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_set_l4c_source((U8)(msg->at_info.l4c_source));

    srv_gcall_l4c_chld_req(CSMCC_ADD_HELD_CALL, 0);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_split
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_split(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *msg = (srv_ucm_int_single_call_act_req_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)msg->action_uid.call_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    srv_gcall_set_l4c_source((U8)(msg->at_info.l4c_source));

    call_info->status_flag |= SRV_GCALL_STATUS_SPLIT_REQUESTED;

    srv_gcall_l4c_chld_req(CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL, (U8)msg->action_uid.call_id);

    return SRV_GCALL_RESULT_OK;
}


#ifdef __MMI_UCM_ECT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_ect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_ect(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_set_l4c_source((U8)(((srv_ucm_int_ect_act_req_struct*)info)->at_info.l4c_source));

    srv_gcall_l4c_chld_req(CSMCC_EXPLICIT_CALL_TRANSFER, 0);

    return SRV_GCALL_RESULT_OK;
}
#endif /* __MMI_UCM_ECT__ */


#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_deflect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_deflect(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_cd_or_ct_act_req_struct *msg = (srv_ucm_int_cd_or_ct_act_req_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_INCOMING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    srv_gcall_set_l4c_source((U8)(msg->at_info.l4c_source));

    if (srv_gcall_util_is_valid_number(cm_p->interface, msg->num_uri, call_info->dir))
    {
        call_info->status_flag |= SRV_GCALL_STATUS_DISCONNECTING;
        srv_gcall_l4c_call_deflect_req(msg->num_uri);
    }
    else
    {
        srv_gcall_ucm_error(cm_p->ucm_info.call_type, SRV_GCALL_RESULT_INVALID_NUMBER_FORMAT);
    }

    return SRV_GCALL_RESULT_OK;
}
#endif /* __MMI_UCM_DEFLECT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_start_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_start_dtmf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_ACTIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->dtmf_started = MMI_TRUE;

#ifdef __MMI_VIDEO_TELEPHONY__
    if (call_info && call_info->call_type == CSMCC_VIDEO_CALL)
    {
        srv_gcall_vt_uii(&(((srv_ucm_dtmf_struct*)info)->digit));
    }
    else
#endif /* __MMI_VIDEO_TELEPHONY__ */
    {
        srv_gcall_l4c_start_dtmf_req(&(((srv_ucm_dtmf_struct*)info)->digit));
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_stop_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_stop_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_ACTIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->dtmf_started = MMI_FALSE;

#ifdef __MMI_VIDEO_TELEPHONY__
    if (call_info && call_info->call_type == CSMCC_VIDEO_CALL)
    {
        return;
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    srv_gcall_l4c_stop_dtmf_req();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_auto_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_auto_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_l4c_start_auto_dtmf_req();
    srv_gcall_reset_auto_dtmf_info();

    return SRV_GCALL_RESULT_OK;
}


#ifdef __AUTO_CALL_REJECTION__
/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cm_mt_present_init
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  result code
 *****************************************************************************/
U16 srv_gcall_cm_mt_present_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_l4c_call_present_res_req((U8)MT_CALL_APPROVAL_ENABLE, 0, 0);

    return SRV_GCALL_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cm_mt_present_cnf
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_cm_mt_present_cnf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_call_present_cnf_struct *cnf = (srv_ucm_int_call_present_cnf_struct*)info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    if (!cnf || (cnf->uid_info.call_id != cm_p->mt.call_present_id))
    {
        /* ignore */
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    if (cnf->result == MMI_TRUE)
    {
        srv_gcall_l4c_call_present_res_req((U8)MT_CALL_ALLOW, cm_p->mt.call_present_id,
            cm_p->mt.seq_num);
    }
    else
    {
        srv_gcall_l4c_call_present_res_req((U8)MT_CALL_REJECT, cm_p->mt.call_present_id,
            cm_p->mt.seq_num);

        /* clear mt present call directly (CSM sends rel_comp to NW) */
        cm_p->mt.call_present_id = SRV_GCALL_INVALID_ID;
        cm_p->mt.seq_num = 0;
    }

    return SRV_GCALL_RESULT_OK;
}
#endif /* __AUTO_CALL_REJECTION__ */


#ifdef __CPI_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_cpi_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  result code
 *****************************************************************************/
U16 srv_gcall_cm_cpi_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_l4c_cpi_req();

    return SRV_GCALL_RESULT_OK;
}
#endif /* __CPI_SUPPORT__ */


#ifdef __CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cm_dial_ccbs
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_cm_dial_ccbs(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_GCALL_RESULT_OK;
    srv_gcall_mo_id_assign_struct mo_id_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_gcall_cm_dial(info);
    if (result != SRV_GCALL_RESULT_OK)
    {
        return result;
    }

    srv_gcall_l4c_chld_req(CSMCC_HOLD_ACTIVE_AND_ACCEPT_CCBS, cm_p->ccbs_info.call_id);

#ifdef __CPI_SUPPORT__
    memset(&mo_id_ind, 0, sizeof(mo_id_ind));
    mo_id_ind.call_id = cm_p->ccbs_info.call_id;
    mo_id_ind.call_type = CSMCC_VOICE_CALL;
    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MO_ID_ASSIGNED, &mo_id_ind);
#endif /* __CPI_SUPPORT__ */

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_ccbs_accept
 * DESCRIPTION
 *  This function is called by the state machine function
 *  to dial CCBS call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with ccbs
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_ccbs_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->ccbs_info.state = SRV_GCALL_CCBS_STATE_ACCEPTED;

    result = srv_gcall_ucm_make_voice_call((CHAR *)cm_p->ccbs_info.number, SRV_UCM_MODULE_ORIGIN_CCBS);

    if (result != SRV_GCALL_RESULT_OK)
    {
        cm_p->ccbs_info.state = SRV_GCALL_CCBS_STATE_RECALL;

        /* reject */
        /* reject notification */
        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_CCBS_RECALL_REJECT, NULL);

        srv_gcall_ucm_error(srv_gcall_get_ucm_call_type(CSMCC_VOICE_CALL), result);
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_ccbs_reject
 * DESCRIPTION
 *  This function is called by the state machine function
 *  to reject CCBS call
 * PARAMETERS
 *  info            [?]         
 *  any(?)          [IN]        Information associated with ccbs
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_ccbs_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_util_op_is_exclusive(cm_p->ucm_info.op)
        || srv_gcall_util_op_is_exclusive(cm_p->ucm_info.bg_op))
    {
        /* cannot use chld_req to reject ccbs recall since other chld op is proceeding */
        /* shall not happen! (shall be protected by processing screen) */
        /* cannot do release all here since it will overwrite the processing op (no rsp for the processing op will be sent to UCM srv!) */
        
        MMI_ASSERT(0);
    }

    srv_gcall_l4c_chld_req(CSMCC_REL_CCBS, cm_p->ccbs_info.call_id);

    srv_gcall_reset_ccbs_info();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_ccbs_ignore
 * DESCRIPTION
 *  To invoke the function that ignore the CCBS invoke
 *  
 *  yet to  implement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_ccbs_ignore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* doesn't need the rsp */
    /* take release_ind triggered by this msg as the nw initiated call clearing */
    srv_gcall_l4c_chld_req(CSMCC_REL_SPECIFIC_CALL, cm_p->ccbs_info.call_id);

    srv_gcall_reset_ccbs_info(); /* shall reset ccbs_info after l4c_chld_req */

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_ccbs_activate
 * DESCRIPTION
 *  To invoke the function that activates the CCBS
 *  
 *  yet to  implement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_ccbs_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_reset_ccbs_info(); 
    /* since ignore_ccbs_activation case re-uses ccbs state in srv_gcall_l4c_chld_req,
     * to distinct from ignore_ccbs_activation case, shall reset ccbs_info before l4c_chld_req 
     */

    srv_gcall_l4c_chld_req(CSMCC_ACTIVATE_CCBS_CALL, 0);

    return SRV_GCALL_RESULT_OK;
}

#endif /* __CCBS_SUPPORT__ */


#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cm_vt_fallto_voice
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_cm_vt_fallto_voice(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *req = (srv_ucm_int_single_call_act_req_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)req->action_uid.call_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    srv_gcall_set_l4c_source((U8)(req->at_info.l4c_source));

    call_info->status_flag |= (SRV_GCALL_STATUS_HANGUP_REQUESTED | SRV_GCALL_STATUS_DISCONNECTING);

    /* use CSMCC_VT_FALL_TO_VOICE
        release with specific cause (in cmcc, it is #88) 
        for incoming call or waiting call */

    srv_gcall_l4c_chld_req(CSMCC_VT_FALL_TO_VOICE, call_info->call_id);

    return SRV_GCALL_RESULT_OK;
}
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */


