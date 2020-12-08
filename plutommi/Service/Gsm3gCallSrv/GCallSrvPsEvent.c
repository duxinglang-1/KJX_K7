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
 *   GCallSrvPsEvent.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  GSM / 3G call service
 *  Process protocol stack events
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



#include "mmiapi_struct.h" /* mmi_make_call_req_ind_struct */

#include "SatSrvGprot.h"
#include "Custom_ecc.h" /* ecc_call_type_enum */

#include "CallSetSrvGprot.h" /* srv_callset_auto_redial_get_mode */

#include "Mdi_audio.h" /* MDI_AUDIO_SPEECH_APP_ID_ENUM */

#include "UcmSrvGprot.h"
#include "..\UcmSrv\UCMSrvIntProt.h"

#include "GCallSrvProt.h"

#include "GCallSrvDef.h"
#include "Ps_public_enum.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_release.h"
#include "kal_non_specific_general_types.h"
#include "MMI_features.h"
#include "csmcc_common_enums.h"
#include "mmi_msg_struct.h"
#include "l4c2abm_struct.h"
#include "string.h"
#include "l4c_aux_struct.h"
#include "Unicodexdcl.h"
#include "mmi_frm_timer_gprot.h"
#include "gui.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_gcall_def.h"
#include "custom_phb_config.h"
#include "wgui_categories_util.h"
#include "PhbSrvGprot.h"
#include "stdio.h"
#include "GlobalResDef.h"
#include "sim_public_api.h" /* is_test_sim */
#include "Ps_public_utility.h" /* l4c_gemini_get_switched_sim_id */
#include "Sim_public_enum.h" /* sim_interface_enum */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_proc_ps_event
 * DESCRIPTION
 *  This is the Entry function for all the Events while the Call-Management application
 *  is Active.
 *  
 *  This function handles the events from both keyboard and protocol stack.
 *  The keyboard events have KB in there defination and Protocol has PS.
 * PARAMETERS
 *  inEvenType      [IN]        
 *  MsgStruct       [?]         
 *  pointer(?)      [IN]        To the event's associated structure)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_proc_ps_event(srv_gcall_ps_event_enum event, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __LOW_COST_SUPPORT_COMMON__
    U16 result = SRV_GCALL_RESULT_UNSPECIFIED_ERR;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PROC_PS_EVENT, event);

    MMI_ASSERT(cm_p);

    switch (event)
    {
    #ifdef __AUTO_CALL_REJECTION__
        case SRV_GCALL_PS_EVENT_MT_PRESENT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_mt_present(info);
            break;
    #endif /* __AUTO_CALL_REJECTION__ */

    #ifdef __MMI_CM_CNAP_SUPPORT__
        case SRV_GCALL_PS_EVENT_MT_UPDATE_NAME:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_mt_update_name(info);
            break;
    #endif /* __MMI_CM_CNAP_SUPPORT__ */

    #ifdef __CPI_SUPPORT__
        case SRV_GCALL_PS_EVENT_MO_ID_ASSIGNED:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_mo_id_assigned(info);
            break;
        
        case SRV_GCALL_PS_EVENT_CHANGE_CALL_STATE:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_change_call_state(info);
            break;
    #endif /* __CPI_SUPPORT__ */

        case SRV_GCALL_PS_EVENT_MT_ALERT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_mt_alert(info);
            break;

        case SRV_GCALL_PS_EVENT_DIAL_CNF_IND:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_dial_cnf_ind(info);
            break;

        case SRV_GCALL_PS_EVENT_MT_CONNECTED:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_mt_connected();
            break;

        case SRV_GCALL_PS_EVENT_MO_CONNECTED:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_mo_connected(info);
            break;

        case SRV_GCALL_PS_EVENT_REL_OUTGOING:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_rel_outgoing(info);
            break;

        case SRV_GCALL_PS_EVENT_REL_INCOMING:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_rel_incoming(info);
            break;

    #ifdef __AUTO_CALL_REJECTION__
        case SRV_GCALL_PS_EVENT_REL_PRESENT_CALL:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_rel_present_call();
            break;
    #endif /* __AUTO_CALL_REJECTION__ */

        case SRV_GCALL_PS_EVENT_REL_OTHERS:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_rel_others(info);
            break;

        case SRV_GCALL_PS_EVENT_SWAP_SUC:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_swap_suc();
            break;

        case SRV_GCALL_PS_EVENT_SWAP_FAIL:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_swap_fail(*((U16*)info));
            break;

        case SRV_GCALL_PS_EVENT_CONF_SUC:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_conf_suc();
            break;

        case SRV_GCALL_PS_EVENT_SPLIT_SUC:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_split_suc();
            break;

        case SRV_GCALL_PS_EVENT_SPLIT_FAIL:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_split_fail(*((U16*)info));
            break; 

        case SRV_GCALL_PS_EVENT_SYNC_CALL_LIST:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_sync_call_list(info);
            break;

        case SRV_GCALL_PS_EVENT_DISCONNECTING:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_disconnecting(info);
            break;

        case SRV_GCALL_PS_EVENT_SPEECH:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_speech(info);
            break;

        case SRV_GCALL_PS_EVENT_MO_ALERT:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_mo_alert(info);
            break;

        case SRV_GCALL_PS_EVENT_AUTO_DTMF:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_auto_dtmf(info);
            break;

    #ifdef __AOC_SUPPORT__
        case SRV_GCALL_PS_EVENT_UPDATE_CALL_COST:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_update_call_cost(info);
            break;
    #endif /* __AOC_SUPPORT__ */

        case SRV_GCALL_PS_EVENT_SS_NOTIFY:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_ss_notify(info);
            break;

        case SRV_GCALL_PS_EVENT_MAKE_CALL_REQ_IND:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_make_call_req_ind(info);
            break;

        case SRV_GCALL_PS_EVENT_CALL_SYNC_REQ_IND:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_call_sync_req_ind();
            break;

        case SRV_GCALL_PS_EVENT_CHANGE_NW_STATUS:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_change_nw_status(info);
            break;
    #ifdef __MMI_UCM_DEFLECT__
        case SRV_GCALL_PS_EVENT_DEFLECT_SUC:
    #endif /* __MMI_UCM_DEFLECT__ */
        case SRV_GCALL_PS_EVENT_END_SUC:
    #ifdef __MMI_UCM_ECT__
        case SRV_GCALL_PS_EVENT_ECT_SUC:
    #endif /* __MMI_UCM_ECT__ */
            srv_gcall_ucm_act_rsp(SRV_GCALL_RESULT_OK, NULL);
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result = SRV_GCALL_RESULT_OK;
        #endif
            break;

        case SRV_GCALL_PS_EVENT_DIAL_RSP:
        case SRV_GCALL_PS_EVENT_MO_PROCEEDING:
            /* do nothing */
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result = SRV_GCALL_RESULT_OK;
        #endif
            break;
        
        case SRV_GCALL_PS_EVENT_MT_CONNECT_FAIL:
    #ifdef __MMI_UCM_DEFLECT__
        case SRV_GCALL_PS_EVENT_DEFLECT_FAIL:
    #endif /* __MMI_UCM_DEFLECT__ */
        case SRV_GCALL_PS_EVENT_END_FAIL:
        case SRV_GCALL_PS_EVENT_CONF_FAIL:
    #ifdef __MMI_UCM_ECT__
        case SRV_GCALL_PS_EVENT_ECT_FAIL:
    #endif /* __MMI_UCM_ECT__ */
            srv_gcall_ucm_error(cm_p->ucm_info.call_type, *((U16*)info));
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result = SRV_GCALL_RESULT_OK;
        #endif
            break;

    #ifdef __CCBS_SUPPORT__
        case SRV_GCALL_PS_EVENT_CCBS_RECALL:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_ccbs_recall(info);
            break;
        
        case SRV_GCALL_PS_EVENT_CCBS_RECALL_CANCEL:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_ccbs_recall_cancel();
            break;

        case SRV_GCALL_PS_EVENT_CCBS_ACCEPT_RES:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_ccbs_accept_res(info);
            break;

        case SRV_GCALL_PS_EVENT_CCBS_ACTIVATE_CNF_IND:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_ccbs_activate_cnf_ind(info);
            break;

        case SRV_GCALL_PS_EVENT_CCBS_ACTIVATE_FAIL:
            srv_gcall_ucm_error(srv_gcall_get_ucm_call_type(CSMCC_VOICE_CALL), *((U16*)info));
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result = SRV_GCALL_RESULT_OK;
        #endif
            break;

        case SRV_GCALL_PS_EVENT_CCBS_ACTIVATE_SUC:
        #ifndef __LOW_COST_SUPPORT_COMMON__
            result =
        #endif
            srv_gcall_ps_ccbs_activate_suc();
            break;
    #endif /* __CCBS_SUPPORT__ */

         default:
            break;
    }

#ifndef __LOW_COST_SUPPORT_COMMON__
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PROC_PS_EVENT_RESULT, event, result);
#else
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PROC_PS_EVENT_RESULT, event, SRV_GCALL_RESULT_OK);
#endif

}


#ifdef __AUTO_CALL_REJECTION__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_mt_present
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_mt_present(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_present_ind_struct *msg = (mmi_cc_call_present_ind_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(info);

    if (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_INCOMING, (srv_gcall_type_enum)0)
        || (cm_p->mt.call_present_id))
    {
        /* mt call or mt present call already exists */
        srv_gcall_l4c_call_present_res_req((U8)MT_CALL_REJECT, msg->call_id, msg->seq_num);
    }
    else
    {
        cm_p->mt.call_present_id = msg->call_id;
        cm_p->mt.seq_num = msg->seq_num;
        srv_gcall_ucm_call_present_cnf_ind(info);
    }
    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_rel_present_call
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_rel_present_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->mt.call_present_id = SRV_GCALL_INVALID_ID;
    cm_p->mt.seq_num = 0;

    return SRV_GCALL_RESULT_OK;
}
#endif /* __AUTO_CALL_REJECTION__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_mt_alert
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_mt_alert(srv_gcall_mt_alert_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[SRV_GCALL_MAX_NUMBER];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(cm_p->mt), 0, sizeof(srv_gcall_mt_info_struct));

#ifdef __AUTO_CALL_REJECTION__
    cm_p->mt.call_present_id = SRV_GCALL_INVALID_ID;
    cm_p->mt.seq_num = 0;
#endif /* __AUTO_CALL_REJECTION__ */

    memset(number, 0, SRV_GCALL_MAX_NUMBER);

    memcpy(&(cm_p->mt.l4c_number), info->num_p, sizeof(l4c_number_struct));

    /* addr */
    if (info->num_p->number[0] != '\0')
    {
        /* International number: the 5th bit is on, and 6th, 7th are both off */
        if ((0x10 & info->num_p->type) && !(0x20 & info->num_p->type) && !(0x40 & info->num_p->type))
        {
            strcpy((CHAR *)number, "+");
        }
        strcat((CHAR *)number, (CHAR *)(info->num_p->number));

    #ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
        cm_p->mt.no_cli_cuase = CSMCC_INVALID_NO_CLI_CAUSE;
    #endif
    }
#ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
    else /* no cli cause */
    {
        if (info->no_cli_cause_present != 0)
        {
            cm_p->mt.no_cli_cuase = info->no_cli_cause;
        }
        else
        {
            cm_p->mt.no_cli_cuase = CSMCC_CLI_UNAVAILABLE;
        }
    }
#endif /* __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__ */

    /* sub addr */
    if ((info->sub_addr_p->number[0] != '\0')
        && ((strlen((CHAR *)(info->sub_addr_p->number)) + strlen((CHAR *)number)) < (SRV_GCALL_MAX_NUMBER - 1)))
    {
        strcat((CHAR *) number, "-");
        strcat((CHAR *) number, (CHAR *)(info->sub_addr_p->number));
    }

    /* presentation indicator */
    if(info->addr_ind_present)
    {
        cm_p->mt.presentation_ind = info->addr_ind & 0x60;
    }
    else
    {
        /* if presentation indicator is omitted, "00 prsentation allowed" is assumed */
    }

    srv_gcall_add_new_call_info(
        number,
        SRV_GCALL_STATE_INCOMING,
        SRV_GCALL_DIR_MT,
        info->call_id,
        (srv_gcall_type_enum)info->call_type);

#ifdef __MMI_CM_CNAP_SUPPORT__
    if(info->name_present)
    {
        srv_gcall_set_cnap_name(info->call_id,
                    info->dcs,
                    info->length,
                    info->name);
    }
#endif /* __MMI_CM_CNAP_SUPPORT__ */

    srv_gcall_ucm_ring_ind();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_dial_cnf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_dial_cnf_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_data_call_req_ind_struct *msg = (mmi_data_call_req_ind_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_ucm_dial_cnf_ind((srv_gcall_type_enum)msg->call_type, msg->number.number);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_mt_connected
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_mt_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_INCOMING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    call_info->curr_state = SRV_GCALL_STATE_ACTIVE;

#ifdef __MMI_VIDEO_TELEPHONY__    
    if (call_info->call_type == CSMCC_VIDEO_CALL)
    {
        /* Turn on speech */
        srv_gcall_ucm_speech_ind(MMI_TRUE, MDI_AUDIO_SPEECH_APP_ID_3G324M, CSMCC_VIDEO_CALL);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    srv_gcall_ucm_act_rsp(SRV_GCALL_RESULT_OK, NULL);

#ifdef __MMI_VIDEO_TELEPHONY__
    if (call_info->call_type == CSMCC_VIDEO_CALL)
    {
        /* always start counter right after MT VT call is connected */
        call_info->start_count = MMI_TRUE;
        srv_gcall_ucm_start_count_ind(call_info);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    return SRV_GCALL_RESULT_OK;
}


#ifdef __CPI_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_mo_id_assigned
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_mo_id_assigned(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_mo_id_assign_struct *msg = (srv_gcall_mo_id_assign_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!call_info)
    {
        /* ignore, no such call */
        return SRV_GCALL_RESULT_IGNORE;
    }

    call_info->call_id = msg->call_id;
    call_info->group_id = srv_gcall_get_free_group_id();

    if (cm_p->ucm_info.op == SRV_UCM_DIAL_ACT)
    {
        if (call_info->call_type != CSMCC_CSD_CALL) /* check the oringal call type(before the call type is changed by L4) */
        {
            call_info->call_type = msg->call_type; /* may change call type by protocol, ex. change to AUX_VOICE_ALL */
            srv_gcall_ucm_dial_rsp(SRV_GCALL_RESULT_OK, NULL);
        }
        else
        {
            call_info->call_type = msg->call_type; /* may change call type by protocol, ex. change CSD to emergency call */
            srv_gcall_ucm_dial_ind(SRV_GCALL_RESULT_OK, NULL);
        }
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_change_call_state
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_ps_change_call_state(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_change_call_state_struct *msg = (srv_gcall_change_call_state_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, msg->call_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!call_info
        || (call_info->curr_state == msg->state))
    {
        return SRV_GCALL_RESULT_IGNORE;
    }

    call_info->curr_state = msg->state;
    
    if (call_info->curr_state == SRV_GCALL_STATE_HOLD)
    {
        srv_gcall_ucm_cancel_query_ind_by_call_id(call_info->call_id, call_info->call_type);
    }

    srv_gcall_ucm_sync_call_list_ind();
    
    return SRV_GCALL_RESULT_OK;
}
#endif /* __CPI_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_mo_connected
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_mo_connected(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_connect_ind_struct *msg = (mmi_cc_call_connect_ind_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info || !call_info || (call_info->call_id != msg->call_id))
    {
        /* ignore */
        return SRV_GCALL_RESULT_IGNORE;
    }

    /* if SAT didn't provide name (alpha id 2 is NULL or empty), don't update number and name */ 
#if defined(__SAT__) && defined(__MMI_UCM_HIDE_SAT_MO_NUMBER__)
    if ((call_info->dir != SRV_GCALL_DIR_MO_STK)
        || (!mmi_ucs2strlen((CHAR *)call_info->name)))
#endif /* defined(__SAT__) && defined(__MMI_UCM_HIDE_SAT_MO_NUMBER__) */
    {
        srv_gcall_update_number(call_info, info);
    }
    
    call_info->curr_state = SRV_GCALL_STATE_ACTIVE;

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    cm_p->release_call_info.post_action = MMI_TRUE; /* reserve phb_data for MO VT fallback */
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */
    srv_gcall_reset_redial_info();
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    cm_p->release_call_info.post_action = MMI_FALSE; /* reserve phb_data for MO VT fallback */
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */

    srv_gcall_reset_mo_info();

    srv_gcall_ucm_connect_ind(call_info);

#ifdef __MMI_VIDEO_TELEPHONY__
    if ((call_info->call_type == CSMCC_VIDEO_CALL) &&
        (call_info->start_count
        #ifdef __OP01__ /* for service numbers which need to send start_count right after connect_ind */
            || !strcmp((CHAR *)call_info->num2, "12531")
            || !strcmp((CHAR *)call_info->num2, "12535")
            || !strcmp((CHAR *)call_info->num2, "13800100011")
        #endif /* __OP01__ */
            )
        )
    {
    #ifdef __OP01__
        /* case1, for service numbers which don't trigger start_count  */
        call_info->start_count = MMI_TRUE;
    #endif /* __OP01__ */

        /* case 1, for service number which don't trigger start_count, send to UCM srv directly */
        /* case 2, start_count has been received before connect_ind, send to UCM srv directly */
        srv_gcall_ucm_start_count_ind(call_info);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_rel_outgoing
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_rel_outgoing(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
#ifdef __SAT__            
    if (call_info->dir == SRV_GCALL_DIR_MO_STK)
    {
        srv_sat_set_call_disconnect_cause(cm_p->interface, 
            SRV_SAT_CALL_DISCONNECT_BEFORE_CONNECT);
    }
#endif /* __SAT__ */

    /* check for post action */
    if (MMI_FALSE
    #ifdef __MMI_VIDEO_TELEPHONY__ 
        || (call_info->call_type == CSMCC_VIDEO_CALL)
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    #ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
        || ((call_info->call_type == CSMCC_VOICE_CALL)
            && (srv_callset_redial_get_mode() == SRV_CALLSET_REDIAL_CONFIRM))
    #endif /* __MMI_UCM_MO_FAIL_POST_ACTION__ */
        )
    {
        /* consider post action (impossible to do auto redial) */
        if (!(cm_p->release_call_info.is_abort))
        {
            /* do the post action */
            cm_p->release_call_info.post_action = MMI_TRUE;
        }
        else if (cm_p->redial_info.phb_data)
        {
            /* no post action (and impossible to do auto redial), clear the kept phb data */
            srv_gcall_util_mgmt_phb_info(MMI_FALSE, cm_p->redial_info.phb_data);
            cm_p->redial_info.phb_data = NULL;
        }
    }

    srv_gcall_ps_release(call_info);
    /* call_info has been reset; use release_call_info */

    /* dial_rsp for non-CSD calls; dial_ind for CSD calls */
    if (cm_p->ucm_info.op == SRV_UCM_INT_DIAL_ACT)
    {
        srv_gcall_reset_redial_info();
        srv_gcall_ucm_error(cm_p->ucm_info.call_type, cm_p->release_call_info.cause);
    }
#ifdef __CCBS_SUPPORT__
    else if ((cm_p->release_call_info.call_id == cm_p->ccbs_info.call_id)
        && (cm_p->ccbs_info.state == SRV_GCALL_CCBS_STATE_ACTIVATE_CNF))
    {
        /* cancel ccbs activation confirm if the call is released */
        srv_gcall_reset_redial_info();
        srv_gcall_ucm_cancel_query_cnf_ind(CSMCC_VOICE_CALL);
        srv_gcall_reset_ccbs_info();
    }
#endif /* __CCBS_SUPPORT__ */
    else
    {
        /* auto redial only after CC__SETUP is sent to the network */

        /* ccbs call which is in activate cnf state 
         * is not allowed to redial (wait for cnf) 
         */
        srv_gcall_redial();
    }

    srv_gcall_reset_release_call_info();
    srv_gcall_reset_mo_info();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_rel_incoming
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_rel_incoming(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_ps_release(call_info);

    srv_gcall_reset_release_call_info();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_rel_others
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_rel_others(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SAT__            
    if (call_info->dir == SRV_GCALL_DIR_MO_STK)
    {
        srv_sat_set_call_disconnect_cause(cm_p->interface, 
            SRV_SAT_CALL_DISCONNECT_AFTER_CONNECT);
    }
#endif /* __SAT__ */

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    /* check for post action, for the temp state that VT MO is connected but not start count (remote is not connected) */
    if ((call_info->call_type == CSMCC_VIDEO_CALL) &&
         !call_info->start_count &&
         !(call_info->status_flag & SRV_GCALL_STATUS_HANGUP_REQUESTED)
        )
    {
        /* do the post action */
        cm_p->release_call_info.post_action = MMI_TRUE;
    }
    else if (cm_p->redial_info.phb_data)
    {
        /* no post action (and impossible to do auto redial), clear the kept phb data */
        srv_gcall_util_mgmt_phb_info(MMI_FALSE, cm_p->redial_info.phb_data);
        cm_p->redial_info.phb_data = NULL;
    }
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */

    srv_gcall_ps_release(call_info);
    /* call_info has been reset; use release_call_info */

    srv_gcall_ucm_cancel_query_ind_by_call_id(cm_p->release_call_info.call_id, cm_p->release_call_info.call_type);

    srv_gcall_reset_release_call_info();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_release
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_release(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_reset_call_info(call_info);

    /* call is already cleared from the call table */

#ifdef __MMI_VIDEO_TELEPHONY__
    if ((cm_p->release_call_info.call_id != SRV_GCALL_MO_TEMP_ID)
        && (cm_p->release_call_info.call_type == CSMCC_VIDEO_CALL)
        && !(srv_gcall_get_call_count(MMI_FALSE, (srv_gcall_state_enum)0, CSMCC_VIDEO_CALL) &&
                srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_ACTIVE, (srv_gcall_type_enum)0)))
    {
        /* turn off speech only when there is no active vt call  */
        srv_gcall_ucm_speech_ind(MMI_FALSE, MDI_AUDIO_SPEECH_APP_ID_3G324M, CSMCC_VIDEO_CALL);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    if (cm_p->release_call_info.call_id != cm_p->auto_reject_call_id)
    {
        if (cm_p->release_call_info.call_id != SRV_GCALL_MO_TEMP_ID)
        {
            srv_gcall_ucm_release_ind();
        }
        /* MO fail before getting call_id, dons't send release_ind to ucm */
    }
    else
    {
        /* auto rejected call, dons't send release_ind to ucm */
        cm_p->auto_reject_call_id = SRV_GCALL_INVALID_ID;
        cm_p->ucm_info.bg_op = SRV_UCM_INT_NO_ACT;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_swap_suc
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_swap_suc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_call_info_struct *call_info;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        call_info = &(cm_p->call_list[count]);
        if (call_info->curr_state == SRV_GCALL_STATE_ACTIVE)
        {
            call_info->curr_state = SRV_GCALL_STATE_HOLD;

            srv_gcall_ucm_cancel_query_ind_by_call_id(call_info->call_id, call_info->call_type);
        }
        else if (call_info->curr_state == SRV_GCALL_STATE_HOLD)
        {
            call_info->curr_state = SRV_GCALL_STATE_ACTIVE;
        }
    }

    srv_gcall_ucm_act_rsp(SRV_GCALL_RESULT_OK, NULL);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_swap_fail
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_swap_fail(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* swap failed because 1 of the calls is dropped, the remaining one becomes hold or not? */
    /* doesn't need to sync call list if hold fail or retrieve fail */
    if (cm_p->ucm_info.op == SRV_UCM_INT_SWAP_ACT)
    {
        srv_gcall_l4c_get_call_list_req();
    }

    srv_gcall_ucm_error(cm_p->ucm_info.call_type, result);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_sync_call_list
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_sync_call_list(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4c_call_list_struct *list = &(((mmi_cc_get_call_list_rsp_struct*)info)->call_list);
    U8 count;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (count = 0; (count < list->length) && (count < SRV_GCALL_MAX_CALL) && (list->list[count].call_id != 0); count++)
    {
        call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, list->list[count].call_id);

        if (!call_info)
        {
            /* ignore the call info which MMI isn't aware of */
            continue;
        }

        switch (list->list[count].call_state)
        {
            case CLCC_CALL_ACTIVE:
                call_info->curr_state = SRV_GCALL_STATE_ACTIVE;
                break;

            case CLCC_CALL_HELD:
                call_info->curr_state = SRV_GCALL_STATE_HOLD;

                srv_gcall_ucm_cancel_query_ind_by_call_id(call_info->call_id, call_info->call_type);
                break;

            case CLCC_CALL_DIALING:
                call_info->curr_state = SRV_GCALL_STATE_OUTGOING;
                break;

            case CLCC_CALL_ALERTING:
                call_info->curr_state = SRV_GCALL_STATE_OUTGOING;
                break;

            case CLCC_CALL_INCOMING:
                call_info->curr_state = SRV_GCALL_STATE_INCOMING;
                break;

            case CLCC_CALL_WAITING:
                call_info->curr_state = SRV_GCALL_STATE_INCOMING;
                break;

            default:
                break;
        }   /* End of Switch */
    }   /* End of for */

    srv_gcall_ucm_sync_call_list_ind();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_conf_suc
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_conf_suc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    srv_gcall_call_info_struct *call_info;
    srv_gcall_call_info_struct *active_call = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_ACTIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* it is normal that there is no active call while receiving conference rsp successes.
     * (the active call is released before receiving conference rsp successes)
     */
    /* MMI_ASSERT(active_call); */

    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        call_info = &(cm_p->call_list[count]);

        if (call_info->curr_state == SRV_GCALL_STATE_HOLD)
        {
            /* conference makes held -> active, active remains active */
            if (active_call)
            {
                call_info->group_id = active_call->group_id;
            }

            call_info->curr_state = SRV_GCALL_STATE_ACTIVE;
        }
    }

    srv_gcall_ucm_act_rsp(SRV_GCALL_RESULT_OK, NULL);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_split_suc
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_split_suc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    srv_gcall_call_info_struct *call_info;
    U8 gid = srv_gcall_get_free_group_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(gid != SRV_GCALL_INVALID_ID);

    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        call_info = &(cm_p->call_list[count]);
        if (call_info->curr_state == SRV_GCALL_STATE_ACTIVE)
        {
            if (call_info->status_flag & SRV_GCALL_STATUS_SPLIT_REQUESTED)
            {
                call_info->status_flag &= ~SRV_GCALL_STATUS_SPLIT_REQUESTED;
                call_info->group_id = gid;
            }
            else
            {
                call_info->curr_state = SRV_GCALL_STATE_HOLD;
            }
        }
    }

    srv_gcall_ucm_act_rsp(SRV_GCALL_RESULT_OK, NULL);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_split_fail
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_split_fail(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        call_info = &(cm_p->call_list[count]);
        if (call_info->status_flag & SRV_GCALL_STATUS_SPLIT_REQUESTED)
        {
            call_info->status_flag &= ~SRV_GCALL_STATUS_SPLIT_REQUESTED;
            break;
        }
    }

    srv_gcall_ucm_error(cm_p->ucm_info.call_type, result);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_disconnecting
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_disconnecting(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    call_info->status_flag |= SRV_GCALL_STATUS_DISCONNECTING;

    if (call_info->call_id != cm_p->auto_reject_call_id)
    {
        /* the call is being auto rejected and at the meanwhile is being disconnected by the remote side */
        srv_gcall_ucm_disconnecting_ind(call_info);
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_speech
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_speech(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_speech_ind_struct *ind = (mmi_cc_speech_ind_struct*)info;
    MDI_AUDIO_SPEECH_APP_ID_ENUM type = MDI_AUDIO_SPEECH_APP_ID_GSM;
    MDI_AUDIO_SPEECH_APP_ID_ENUM app_id = mdi_audio_speech_get_app_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__GSM_RAT__) || defined(__UMTS_RAT__) 
    switch (ind->rat)
    {
        case L4C_RAT_UMTS:
            type = MDI_AUDIO_SPEECH_APP_ID_WCDMA;
            break;

        default:
            break;
    }
#endif
    
    if (ind->on_off != KAL_TRUE)
    {
        /* turn off */
        if (type != app_id)
        {
            /* already handover between 2G and 3G */
            mdi_audio_speech_set_app_id(type);
        }

        srv_gcall_ucm_speech_ind(MMI_FALSE, type, CSMCC_VOICE_CALL);
    }
    else
    {
        /* turn on */
        if (type != app_id)
        {
            srv_gcall_ucm_speech_ind(MMI_TRUE, type, CSMCC_VOICE_CALL);
        }
        else
        {
            /* do nothing (already turned on) */
        }
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_mo_alert
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_mo_alert(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!call_info)
    {
        /* ignore */
        return SRV_GCALL_RESULT_IGNORE;
    }

    srv_gcall_ucm_alert_ind(call_info, ((mmi_cc_internal_alert_ind_struct*)info)->alert);

    return SRV_GCALL_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_auto_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_auto_dtmf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_start_auto_dtmf_ind_struct *msg = (mmi_cc_start_auto_dtmf_ind_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, msg->call_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!call_info
        || (call_info->curr_state != SRV_GCALL_STATE_ACTIVE))
    {
        /* only allow to send auto dtmf in an active call */
        /* ignore */
        return SRV_GCALL_RESULT_IGNORE;
    }
    
    /* auto_dtmf_info */
    cm_p->auto_dtmf_info.call_id = msg->call_id;
    strncpy((CHAR *)cm_p->auto_dtmf_info.buf, (CHAR *)msg->digits, SRV_GCALL_MAX_DTMF_DIGITS - 1);

    srv_gcall_ucm_auto_dtmf_cnf_ind(); 


    return SRV_GCALL_RESULT_OK;
}


#ifdef __AOC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_update_call_cost
 * DESCRIPTION
 *  This function is called by the state machine function in
 *  to make call to protocol stack to get call list to sync with MMI
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_update_call_cost(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_ccm_ind_struct *msg = (mmi_cc_ccm_ind_struct*)info;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    call_info = srv_gcall_get_call_info(
                    SRV_GCALL_CALL_INFO_BY_CALL_ID, 
                    ((mmi_cc_ccm_ind_struct*)info)->call_id);

    call_info->total_cost_unit += msg->ccm;
    msg->total_ccm = call_info->total_cost_unit;

    srv_gcall_ucm_call_cost_ind(info);

    return SRV_GCALL_RESULT_OK;
}
#endif /* __AOC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_ss_notify
 * DESCRIPTION
 *  This function derives SS information from PS and calls necessary
 *  entry function to show string
 * PARAMETERS
 *  info        [?]         
 *  data(?)     [IN]        From PS
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_ss_notify(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
#if 0 /* don't display detail info */
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (IsMyTimerExist(SS_NOTIFY_TIMER))
    {
        /* ignore contiguous ss notify */
        return SRV_GCALL_RESULT_IGNORE;
    }

    StartTimer(SS_NOTIFY_TIMER, 100, UI_dummy_function);

    str_id = srv_gcall_util_get_ss_notify_str_id(cm_p->ss_notify_info.event);
    if (!str_id)
    {
        /* ignore known ss notify event */
        return SRV_GCALL_RESULT_IGNORE;
    }

#if 0 /* don't display detail info */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    srv_gcall_ucm_notify_ind(call_info->call_type, (PU8)GetString(str_id), 0, 0);
#endif

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_make_call_req_ind
 * DESCRIPTION
 *  Need to revise (temp solution)
 * PARAMETERS
 * MsgStruct(?)       [IN]        Which needs to make the outgoing call.              
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_make_call_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_make_call_req_ind_struct *msg = (mmi_make_call_req_ind_struct*)info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_util_get_internal_call_type((srv_ucm_call_type_enum)msg->call_type) != CSMCC_VOICE_CALL)
    {
        /* not support for now */
        return SRV_GCALL_RESULT_NOT_SUPPORT;
    }
    else
    {
        return srv_gcall_ucm_make_voice_call((CHAR *)msg->strNumber, SRV_UCM_MODULE_ORIGIN_COMMON);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_call_sync_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_call_sync_req_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_l4c_get_call_list_req();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_change_nw_status
 * DESCRIPTION
 *  Need to revise (temp solution)
 * PARAMETERS
 * MsgStruct(?)       [IN]        Which needs to make the outgoing call.              
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_change_nw_status(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_mmrr_service_status_ind_struct *msg = (mmi_nw_mmrr_service_status_ind_struct*)info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (msg->service_status)
    {
        cm_p->nw_available = MMI_TRUE;
    }
    else
    {
        cm_p->nw_available = MMI_FALSE;
    }

    return SRV_GCALL_RESULT_OK;
}


#ifdef __MMI_CM_CNAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_mt_update_name
 * DESCRIPTION
 *  Need to revise (temp solution)
 * PARAMETERS
 * MsgStruct(?)       [IN]        Which needs to make the outgoing call.              
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_mt_update_name(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_notify_ss_cnap_ind_struct *msg = (mmi_cc_notify_ss_cnap_ind_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, msg->call_id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (msg->name_present)
    {
        srv_gcall_set_cnap_name(msg->call_id, msg->dcs, msg->length, msg->name);
        srv_gcall_ucm_replace_ind(call_info);
    }
    else
    {
        if (mmi_ucs2strlen((CHAR *)call_info->cnap_name))
        {
            memset(call_info->cnap_name, 0, SRV_GCALL_MAX_NAME);
            srv_gcall_ucm_replace_ind(call_info);
        }
    }

    return SRV_GCALL_RESULT_OK;
}
#endif /* __MMI_CM_CNAP_SUPPORT__ */


#ifdef __CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_ccbs_recall
 * DESCRIPTION
 *  This function is called when CCBS
 *  invoked notification is there
 * PARAMETERS
 *  info            [?]         
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_ccbs_recall(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_notify_ss_ccbs_ind_struct *msg = (mmi_cc_notify_ss_ccbs_ind_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->ccbs_info.call_id = msg->call_id;
    cm_p->ccbs_info.state = SRV_GCALL_CCBS_STATE_RECALL;

    if (msg->number_present)
    {
        /* International number: the 5th bit is on, and 6th, 7th are both off */
        if ((0x10 & msg->addr.type) && !(0x20 & msg->addr.type) && !(0x40 & msg->addr.type))
        {
            strcpy((CHAR *)cm_p->ccbs_info.number, "+");
        }
        strcat((CHAR *)cm_p->ccbs_info.number, (CHAR *)(msg->addr.number));
    }

    if ((msg->sub_addr_present)
        && ((strlen((CHAR *)msg->sub_addr.number) + strlen((CHAR *)cm_p->ccbs_info.number)) < (SRV_GCALL_MAX_NUMBER - 1)))
    {
        strcat((CHAR *)cm_p->ccbs_info.number, "-");
        strcat((CHAR *)cm_p->ccbs_info.number, (CHAR *)msg->sub_addr.number);
    }

    srv_gcall_ucm_ccbs_recall_cnf_ind();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_ccbs_recall_cancel
 * DESCRIPTION
 *  This function is called when CCBS
 *  invoked notification is there
 * PARAMETERS
 *  info            [?]         
 *  result(?)       [OUT]       Of execution of function which may be success or failure
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_ccbs_recall_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_reset_ccbs_info();

    srv_gcall_ucm_cancel_query_cnf_ind(CSMCC_VOICE_CALL);

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_ccbs_accept_res
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_ccbs_accept_res(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_chld_rsp_struct *rsp = (mmi_cc_chld_rsp_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, cm_p->ccbs_info.call_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!call_info || (call_info->curr_state != SRV_GCALL_STATE_OUTGOING))
    {
        /* the call has been released */
        /* ignore */
        return SRV_GCALL_RESULT_IGNORE;
    }

    if (rsp->result != KAL_TRUE)
    {
        srv_gcall_phdlr_set_release_call_info(call_info, rsp->cause);

        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_OUTGOING, call_info);
    }
    else
    {
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MO_PROCEEDING, NULL);
    }

    srv_gcall_reset_ccbs_info();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_ccbs_activate_cnf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_ccbs_activate_cnf_ind(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->ccbs_info.call_id = call_info->call_id;
    cm_p->ccbs_info.state = SRV_GCALL_CCBS_STATE_ACTIVATE_CNF;

    srv_gcall_ucm_ccbs_activation_cnf_ind();

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ps_ccbs_activate_suc
 * DESCRIPTION
 *  This is a notification which does not have history and used when the
 *  ccbs activation is success with a timeout of CM_NOTIFY_TIMEOUT.
 *  
 *  This has to display the time,we need to have the time display catefory function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ps_ccbs_activate_suc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_ucm_notify_ind(CSMCC_VOICE_CALL, (PU8)get_string(STR_GLOBAL_ACTIVATED), 0, 0);

    return SRV_GCALL_RESULT_OK;
}
#endif /* __CCBS_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_update_number
 * DESCRIPTION
 *  Sets called number alongwith type field
 * PARAMETERS
 *  index       [IN]        
 *  msg         [?]         
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_update_number(srv_gcall_call_info_struct *call_info, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_connect_ind_struct *msg = (mmi_cc_call_connect_ind_struct*)info;
    srv_phb_caller_info_struct phb_data;
    srv_phb_cm_number_struct phb_num;    
    U8 temp_str[SRV_GCALL_MAX_NUMBER * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* call_info and info is not NULL, which is guaranteed by srv_gcall_ps_mo_connected */

    memset(call_info->num2, 0, sizeof(call_info->num2));
    if (msg->num.length)
    {
        /* addr */
        if ((0x10 & msg->num.type) && !(0x20 & msg->num.type) && !(0x40 & msg->num.type))
        {
            strcpy((CHAR *)call_info->num2, "+");
        }
        strncat((CHAR *)call_info->num2, (CHAR *)msg->num.number, SRV_GCALL_MAX_NUMBER - 1 - strlen((CHAR *)call_info->num2));

        /* sub addr */
        if ((msg->sub_addr.length)
            && ((msg->sub_addr.length + strlen((CHAR *)call_info->num2)) < (SRV_GCALL_MAX_NUMBER - 1)))
        {
            strcat((CHAR *)call_info->num2, "-");
            strcat((CHAR *)call_info->num2, (CHAR *)(msg->sub_addr.number));
        }
    }
    
    if (!strcmp((CHAR *)call_info->num, (CHAR *)call_info->num2) ||
        call_info->dir == SRV_GCALL_DIR_MO_STK)
    {
        /* number is not changed */
        /* SAT call / call control by sim don't update display name after connect_ind */
        return;
    }

    if (msg->num.length)
    {
    #ifdef __IP_NUMBER__
        /* ip dial doesn't update phb_data */
        if (!(cm_p->mo.is_ip_dial))
    #endif /* __IP_NUMBER__ */
        {
            memset(&phb_data, 0, sizeof(srv_phb_caller_info_struct));
            memset(&phb_num, 0, sizeof(srv_phb_cm_number_struct));
            memset(temp_str, 0, SRV_GCALL_MAX_NUMBER * ENCODING_LENGTH);
            mmi_asc_to_ucs2((CHAR *)temp_str, (CHAR *)call_info->num2);
            phb_num.number = (PU16)temp_str;
            phb_num.is_mo_call = MMI_TRUE;
            phb_num.sim_interface = srv_gcall_get_sim_interface(cm_p->interface);
            phb_num.call_type = srv_gcall_util_get_ecc_type(cm_p->interface, call_info->dir);
            if (phb_num.call_type == ECC_ALL_CALL)
            {
                MMI_ASSERT(0);
            }

            /* doesn't use user_data */

            srv_phb_get_caller_info_by_number(&phb_num, &phb_data);
            memcpy(&(cm_p->phb_data), &phb_data, sizeof(srv_phb_caller_info_struct));
            mmi_ucs2cpy((CHAR *)call_info->name, (CHAR *)cm_p->phb_data.name);   
        #ifdef __MMI_UCM_NUMBER_TYPE__
            call_info->number_type = cm_p->phb_data.number_type;
        #endif /* __MMI_UCM_NUMBER_TYPE__ */

            memset(&(call_info->phb_res_id), 0, sizeof(srv_phb_caller_res_id_struct));
            call_info->phb_res_id.image_id = phb_data.image_id;
            call_info->phb_res_id.video_id = phb_data.video_id;
            call_info->phb_res_id.ringtone_id = phb_data.ringtone_id;
            call_info->phb_res_id.res_type = phb_data.res_type;
            call_info->phb_res_id.call_type = srv_gcall_get_ucm_call_type(call_info->call_type);
        }
    }
    else
    {
        mmi_ucs2cpy((CHAR *)call_info->name, GetString(STR_ID_GCALL_UNKNOWN_CALLER));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_redial
 * DESCRIPTION
 *  Sets called number alongwith type field
 * PARAMETERS
 *  index       [IN]        
 *  msg         [?]         
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_redial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL redial = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* is redial set */
    if (!srv_gcall_redial_is_set())
    {
        redial = MMI_FALSE;
    }

    /* is user abort */
    else if (cm_p->release_call_info.is_abort)
    {
        redial = MMI_FALSE;
    }

    /* there is no call */
    else if (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_TOTAL, (srv_gcall_type_enum)0))
    {
        redial = MMI_FALSE;
    }

    /* only voice call can redial */
    else if ((cm_p->release_call_info.call_type != CSMCC_VOICE_CALL)
        && (cm_p->release_call_info.call_type != CSMCC_AUX_VOICE_CALL))
    {
        redial = MMI_FALSE;
    }

    else if (!srv_gcall_redial_set_max_attempt(cm_p->release_call_info.cause))
    {
        redial = MMI_FALSE;
    }

    else if (!srv_gcall_redial_set_backoff(cm_p->release_call_info.cause))
    {
        redial = MMI_FALSE;
    }

    if (!redial)
    {
        srv_gcall_reset_redial_info();
        return;
    }

    /* auto redial */
    srv_gcall_ucm_auto_redial_ind();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_is_redial_set
 * DESCRIPTION
 *  This function checks if the redial flag is set
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       /FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL srv_gcall_redial_is_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
    if (cm_p->release_call_info.dir == SRV_GCALL_DIR_MO_STK)
    {
        return MMI_FALSE;
    }
#endif /* __SAT__ */
    return srv_callset_auto_redial_get_mode();
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_redial_set_max_attempt
 * DESCRIPTION
 *  This function checks if the error cause needs
 *  to redial
 * PARAMETERS
 *  response        [IN]        
 *  TRUE(?)         [OUT]       /FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL srv_gcall_redial_set_max_attempt(U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (cause)
    {
        case SRV_GCALL_RESULT_USER_BUSY:
        case SRV_GCALL_RESULT_NO_USER_RESPONDING:
        case SRV_GCALL_RESULT_DEST_OUT_OF_ORDER:
        case SRV_GCALL_RESULT_NO_ANSWER_ON_ALERT:
        case SRV_GCALL_RESULT_NO_CIRCUIT_CHANNEL_AVAIL:
        case SRV_GCALL_RESULT_TEMPORARY_FAILURE:
        case SRV_GCALL_RESULT_SWITCH_EQUIPMENT_CONGESTION:
        case SRV_GCALL_RESULT_REQUESTED_CKT_CHANEL_NOT_AVIL:
        case SRV_GCALL_RESULT_RESOURCE_UNAVAIL_UNSPECIFIED:
            cm_p->redial_info.max_attempt = 10;
            return MMI_TRUE;
    
        case SRV_GCALL_RESULT_UNASSIGNED_NUM:
        case SRV_GCALL_RESULT_NO_ROUTE_TO_DESTINATION:
        case SRV_GCALL_RESULT_NUMBER_CHANGED:
        case SRV_GCALL_RESULT_INVALID_NUMBER_FORMAT:
        case SRV_GCALL_RESULT_NETWORK_OUT_OF_ORDER:
            cm_p->redial_info.max_attempt = 1;
            return MMI_TRUE;
    
        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_redial_set_backoff
 * DESCRIPTION
 *  Checks if number must be redialed or error
 *  must be shown
 * PARAMETERS
 *  response        [IN]        
 *  Number(?)       [IN]        To show on screen
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_gcall_redial_set_backoff(U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL minFlag = MMI_FALSE;
    U8 timer, dispTimer;
    CHAR temp[10], temp2[20];
    MMI_BOOL is_test_setting = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->redial_info.curr_attempt++;

    /* exceed redial attempt */
    if (cm_p->redial_info.curr_attempt > cm_p->redial_info.max_attempt)
    {
        return MMI_FALSE;
    }

#if (MMI_MAX_SIM_NUM == 1)
    if (KAL_TRUE == is_test_sim())
    {
        is_test_setting = MMI_TRUE;
    }
#else /* MMI_MAX_SIM_NUM == 1 */
    if (KAL_TRUE == is_test_sim(l4c_gemini_get_switched_sim_id(SIM1)))
    {
        is_test_setting = MMI_TRUE;
    }
    if (KAL_TRUE == is_test_sim(l4c_gemini_get_switched_sim_id(SIM2)))
    {
        is_test_setting = MMI_TRUE;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (KAL_TRUE == is_test_sim(l4c_gemini_get_switched_sim_id(SIM3)))
    {
        is_test_setting = MMI_TRUE;
    }
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    if (KAL_TRUE == is_test_sim(l4c_gemini_get_switched_sim_id(SIM4)))
    {
        is_test_setting = MMI_TRUE;
    }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 2 */

    switch (cm_p->redial_info.curr_attempt)
    {
        case 1:
            timer = 5;
            dispTimer = 5;
            break;

        case 2:
        case 3:
        case 4:
            timer = 60;
            dispTimer = 1;
            minFlag = MMI_TRUE;
            break;
        default:
            timer = 180;
            dispTimer = 3;
            minFlag = MMI_TRUE;
            break;
    }

    /* because Anite machine timer issue, we add 2 seconds to pass the 28.3 28.3 */
    if (MMI_TRUE == is_test_setting)
    {
        timer += 2;
    }

    memset(cm_p->redial_info.msg, 0, sizeof(cm_p->redial_info.msg));
    mmi_ucs2cpy((CHAR *)cm_p->redial_info.msg, GetString(STR_ID_GCALL_REDIAL));

    sprintf((CHAR *) temp, "\n%d \0", cm_p->redial_info.curr_attempt);
    mmi_asc_to_ucs2((CHAR *)temp2, (CHAR *)temp);
    mmi_ucs2cat((CHAR *)cm_p->redial_info.msg, (CHAR *)temp2);

    mmi_ucs2cat((CHAR *)cm_p->redial_info.msg, GetString(STR_ID_GCALL_REDIAL_TIMES));
    mmi_ucs2cat((CHAR *)cm_p->redial_info.msg, GetString(STR_ID_GCALL_REDIAL_NEXT_ATTEMPT));

    sprintf((CHAR *) temp, "\n%d \0", dispTimer);
    mmi_asc_to_ucs2((CHAR *) temp2, (CHAR *) temp);
    mmi_ucs2cat((CHAR *)cm_p->redial_info.msg, (CHAR *)temp2);

    if (minFlag == MMI_FALSE)
    {
        mmi_ucs2cat((CHAR *)cm_p->redial_info.msg, GetString(STR_ID_GCALL_REDIAL_SEC));
    }
    else
    {
        mmi_ucs2cat((CHAR *)cm_p->redial_info.msg, GetString(STR_ID_GCALL_REDIAL_MIN));
    }

    cm_p->redial_info.timer = timer;
    
    return MMI_TRUE;
}


