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
 *   GCallSrvCmInterface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  GSM / 3G call service
 *  Interfaces for UCM service 
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


#include "Custom_events_notify.h" /* mmi_get_event_based_image, mmi_get_int_event_based_sound */

#include "CphsSrvGprot.h"

#include "Resource_audio.h" /* TONE_BUSY_CALL_GSM */

#include "ProfilesSrvGprot.h" /* srv_prof_get_current_profile_value */

#include "custom_phb_config.h" /* MMI_PHB_NAME_LENGTH */

#include "Mdi_audio.h" /* MDI_AUDIO_SPEECH_APP_ID_ENUM */

#include "UcmSrvGprot.h"
#include "..\UcmSrv\UCMSrvIntProt.h"

#include "GCallSrvProt.h"

#include "MMIDataType.h"
#include "GCallSrvDef.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "l3_inc_enums.h"
#include "string.h"
#include "kal_non_specific_general_types.h"
#include "kal_release.h"
#include "MMI_features.h"
#include "mmi_rp_srv_gcall_def.h"
#include "GlobalResDef.h"
#include "csmcc_common_enums.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "PhbSrvGprot.h"
#include "mmi_msg_struct.h"
#include "l4c_aux_struct.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "l4c2abm_struct.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_utility_gprot.h"


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_act_req
 * DESCRIPTION
 *  UCM action request handler
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_cmhdlr_act_req(srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum act_op, void *ptr, void *user_data, srv_ucm_int_act_rsp_callback_func_ptr rsp_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    srv_gcall_cm_event_enum event = SRV_GCALL_CM_EVENT_INVALID;
    srv_gcall_ucm_info_struct prev_ucm_info;
    mmi_sim_enum interface;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_cntxt_is_locked())
    {
        MMI_ASSERT(srv_gcall_post_act_evt(call_type, act_op, ptr, user_data, rsp_callback));
        return;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_ACT_REQ, call_type, act_op);

        srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_ucm_call_type(call_type));

        /* backup ucm_info */
        memcpy(&prev_ucm_info, &(cm_p->ucm_info), sizeof(srv_gcall_ucm_info_struct));
        interface = cm_p->interface;

        /* set call type for dial prmt */
        cm_p->ucm_info.call_type = call_type;

        /* permit check */
        result = srv_gcall_prmt((srv_ucm_int_prmt_opcode_enum)act_op, ptr);

    }

    /* re-assign ucm_info */
    /* if it is not background op (auto reject), overwrite the previous ucm info */
    if (act_op != SRV_UCM_INT_AUTO_REJECT_ACT)
    {
        srv_gcall_reset_ucm_info_except_bg_op();
    }
    cm_p->ucm_info.call_type = call_type;
    if (srv_gcall_util_op_need_rsp(act_op))
    {
        cm_p->ucm_info.op = act_op;
        cm_p->ucm_info.rsp_cb = rsp_callback;
        cm_p->ucm_info.user_data = user_data;
    }

    if (result != SRV_GCALL_RESULT_OK)
    {
        if (srv_gcall_util_op_need_rsp(act_op))
        {
            /* don't send notify_ind to ucm */
            srv_gcall_ucm_error(cm_p->ucm_info.call_type, result);
        }

        /* restore ucm info */
        srv_gcall_cntxt_reset_ptr();
        srv_gcall_cntxt_set_ptr(interface);
        memcpy(&(cm_p->ucm_info), &prev_ucm_info, sizeof(srv_gcall_ucm_info_struct));
        srv_gcall_cntxt_reset_ptr();

        return;
    }

    if ((srv_gcall_util_op_need_rsp(act_op))
        && (prev_ucm_info.op != SRV_UCM_INT_NO_ACT))
    {
        /* overwrite the previous op, ex. end processing calls */
        /* clear the waiting event handlr since the op has been overwritten
         * don't care the rsp since UCM srv guarentees all the processing calls is released
         */
        srv_gcall_reset_ps_event_handler(cm_p->ps_info.rsp_event);
        cm_p->ps_info.rsp_event = 0;
    }

    /* do action */
    switch (act_op)
    {
        case SRV_UCM_INT_DIAL_ACT:
            switch (((srv_ucm_int_dial_act_req_struct*)ptr)->module_id)
            {
            #ifdef __SAT__
                case SRV_UCM_MODULE_ORIGIN_SAT:
                    event = SRV_GCALL_CM_EVENT_DIAL_SAT;
                    break;
            #endif /* __SAT__ */

            #ifdef __CCBS_SUPPORT__
                case SRV_UCM_MODULE_ORIGIN_CCBS:
                    if (cm_p->ccbs_info.state == SRV_GCALL_CCBS_STATE_ACCEPTED)
                    {
                        event = SRV_GCALL_CM_EVENT_DIAL_CCBS;
                    }
                    break;
            #endif /* __CCBS_SUPPORT__ */ 

                default:
                    event = SRV_GCALL_CM_EVENT_DIAL_NORMAL;
                    break;
            }
            break;

        case SRV_UCM_INT_ACCEPT_ACT:
            event = SRV_GCALL_CM_EVENT_ACCEPT;
            break;

        case SRV_UCM_INT_HOLD_ACT:
        case SRV_UCM_INT_RETRIEVE_ACT:
            ptr = &(((srv_ucm_int_single_group_act_req_struct*)ptr)->at_info.l4c_source);
            event = SRV_GCALL_CM_EVENT_SWAP;
            break;

        case SRV_UCM_INT_SWAP_ACT:
            ptr = &(((srv_ucm_int_multiple_group_act_req_struct*)ptr)->at_info.l4c_source);
            event = SRV_GCALL_CM_EVENT_SWAP;
            break;

        case SRV_UCM_INT_CONFERENCE_ACT:
            event = SRV_GCALL_CM_EVENT_CONF;
            break;

        case SRV_UCM_INT_SPLIT_ACT:
            event = SRV_GCALL_CM_EVENT_SPLIT;
            break;

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT:
            event = SRV_GCALL_CM_EVENT_ECT;
            break;
    #endif /* __MMI_UCM_ECT__ */

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_INT_DEFLECT_ACT:
            event = SRV_GCALL_CM_EVENT_DEFLECT;
            break;
    #endif /* __MMI_UCM_DEFLECT__ */

        case SRV_UCM_INT_END_SINGLE_ACT:
            event = SRV_GCALL_CM_EVENT_END_SINGLE;
            break;

        case SRV_UCM_INT_END_CONFERENCE_ACT:
            event = SRV_GCALL_CM_EVENT_END_CONF;

            if (prev_ucm_info.op == SRV_UCM_INT_CONFERENCE_ACT
                || prev_ucm_info.op == SRV_UCM_INT_SPLIT_ACT
                || prev_ucm_info.op == SRV_UCM_INT_HOLD_ACT
                || prev_ucm_info.op == SRV_UCM_INT_RETRIEVE_ACT
                || prev_ucm_info.op == SRV_UCM_INT_SWAP_ACT)
            {
                /* conflict *//* the conf call is active or held? */
                event = SRV_GCALL_CM_EVENT_END_ALL;
            }
            break;

        case SRV_UCM_INT_END_ALL_ACT:
            event = SRV_GCALL_CM_EVENT_END_ALL;
            break;

        case SRV_UCM_INT_FORCE_RELEASE_ACT:
            /* abort the previous op (don't wait for rsp anymore) */
            srv_gcall_reset_ps_event_handler(cm_p->ps_info.rsp_event);
            cm_p->ps_info.rsp_event = 0;

            event = SRV_GCALL_CM_EVENT_FORCE_RELEASE;
            break;

        case SRV_UCM_INT_AUTO_REJECT_ACT:
            cm_p->ucm_info.bg_op = SRV_UCM_INT_AUTO_REJECT_ACT;
            event = SRV_GCALL_CM_EVENT_AUTO_REJECT;
            break;

        case SRV_UCM_INT_START_DTMF_ACT:
            event = SRV_GCALL_CM_EVENT_START_DTMF;
            break;

        case SRV_UCM_INT_STOP_DTMF_ACT:
            event = SRV_GCALL_CM_EVENT_STOP_DTMF;
            break;

    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_INT_VT_FALLTO_VOICE_ACT:
            event = SRV_GCALL_CM_EVENT_VT_FALLTO_VOICE_ACT;
            break;
    #endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */

        default:
            break;
    }

    srv_gcall_proc_cm_event(event, ptr);

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_prmt
 * DESCRIPTION
 *  permit function for UCM srv
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
srv_ucm_result_enum srv_gcall_cmhdlr_prmt(srv_ucm_call_type_enum call_type, srv_ucm_int_prmt_opcode_enum prmt_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gcall_result;
    mmi_sim_enum ori_sim = MMI_SIM_NONE;
    srv_ucm_call_type_enum ori_call_type = SRV_UCM_CALL_TYPE_END_OF_ENUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_PRMT, call_type, prmt_type);

    if (srv_gcall_cntxt_is_locked())
    {
        /* allow permit when cntxt is locked since permit function doesn't modify the context */
        /* backup interface and call type */
        ori_sim = cm_p->interface;
        ori_call_type = cm_p->ucm_info.call_type; /* reuse ucm_info.call_type for call type available and dial permit */
        srv_gcall_cntxt_reset_ptr();
    }

    /* allow bitwised call type */
    /* convert bitwised call type to single call type */
    call_type = srv_gcall_util_get_ucm_single_call_type(call_type);

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_ucm_call_type(call_type));

    cm_p->ucm_info.call_type = call_type; /* reuse ucm_info.call_type for dial permit */
    gcall_result = srv_gcall_prmt(prmt_type, ptr);
    cm_p->ucm_info.call_type = SRV_UCM_CALL_TYPE_END_OF_ENUM;

    srv_gcall_cntxt_reset_ptr();

    if (ori_sim != MMI_SIM_NONE)
    {
        /* restore cntxt */
        srv_gcall_cntxt_set_ptr(ori_sim);
        cm_p->ucm_info.call_type = ori_call_type; /* reuse ucm_info.call_type for call type available and dial permit */
    }

    return srv_gcall_util_get_ucm_result(gcall_result);

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_query
 * DESCRIPTION
 *  function which is called by UCM
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_gcall_cmhdlr_query(srv_ucm_call_type_enum call_type, srv_ucm_int_query_enum query_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    mmi_sim_enum ori_sim = MMI_SIM_NONE;
    srv_ucm_call_type_enum ori_call_type = SRV_UCM_CALL_TYPE_END_OF_ENUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_cntxt_is_locked())
    {
        /* allow query when cntxt is locked since query function doesn't modify the context */
        /* backup interface and call type */
        ori_sim = cm_p->interface;
        ori_call_type = cm_p->ucm_info.call_type; /* reuse ucm_info.call_type for call type available */
        srv_gcall_cntxt_reset_ptr();
    }

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_ucm_call_type(call_type));

    cm_p->ucm_info.call_type = call_type; /* reuse ucm_info.call_type for call type available */

    if (cm_p->interface != MMI_SIM_NONE)
    {
        switch (query_type)
        {
            case SRV_UCM_INT_NUMBER:
                result = srv_gcall_util_is_valid_number(cm_p->interface, 
                            ((srv_ucm_int_query_number_struct*)ptr)->num_uri,
                            (((srv_ucm_int_query_number_struct*)ptr)->module == SRV_UCM_MODULE_ORIGIN_SAT) ? SRV_GCALL_DIR_MO_STK : SRV_GCALL_DIR_MO);
                break;

            case SRV_UCM_INT_ECC_NUMBER:
                result = srv_gcall_util_is_valid_ecc(cm_p->interface, 
                            ((srv_ucm_int_query_number_struct*)ptr)->num_uri,
                            (((srv_ucm_int_query_number_struct*)ptr)->module == SRV_UCM_MODULE_ORIGIN_SAT) ? SRV_GCALL_DIR_MO_STK : SRV_GCALL_DIR_MO);
                break;

            case SRV_UCM_INT_DTMF_DIGIT:
                result = srv_gcall_util_is_valid_dtmf(((srv_ucm_dtmf_struct*)ptr)->digit);
                break;

            case SRV_UCM_INT_CALL_SRV_AVAILABLE:
                result = srv_gcall_util_type_available(call_type, MMI_TRUE);
                break;

            case SRV_UCM_INT_CALL_SRV_TMP_UNAVAILABLE:
                result = srv_gcall_is_tmp_not_available();
                break;

            case SRV_UCM_INT_CALLER_RES:
                result = srv_gcall_get_caller_res_info(ptr);
                break;

            default:
                break;
        }
    }

    cm_p->ucm_info.call_type = SRV_UCM_CALL_TYPE_END_OF_ENUM;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_QUERY, call_type, query_type, result);

    srv_gcall_cntxt_reset_ptr();

    if (ori_sim != MMI_SIM_NONE)
    {
        /* restore cntxt */
        srv_gcall_cntxt_set_ptr(ori_sim);
        cm_p->ucm_info.call_type = ori_call_type; /* reuse ucm_info.call_type for call type available */
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_cmhdlr_cnf(srv_ucm_call_type_enum call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_cntxt_is_locked())
    {
        if (!srv_gcall_post_cnf_evt(call_type, cnf_type, ptr, srv_gcall_cmhdlr_cnf))
        {
            /* the result code is reserved */
        }
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_CNF, call_type, cnf_type);

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_ucm_call_type(call_type));

    switch (cnf_type)
    {
        case SRV_UCM_INT_QUERY_CNF:
            break;

        case SRV_UCM_INT_DIAL_CNF:
            srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_DIAL_CNF, ptr);
            break;

        case SRV_UCM_INT_CALL_PRESENT_CNF:
            srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_MT_PRESENT_CNF, ptr);
            break;

        default:
            /* ignore */
            break;    
    }

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_cnf_auto_dtmf
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
void srv_gcall_cmhdlr_cnf_auto_dtmf(srv_ucm_call_type_enum ucm_call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_cnf_struct *cnf = (srv_ucm_int_query_cnf_struct*)ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(cnf_type == SRV_UCM_INT_QUERY_CNF);

    if (srv_gcall_cntxt_is_locked())
    {
        if (!srv_gcall_post_cnf_evt(ucm_call_type, cnf_type, ptr, srv_gcall_cmhdlr_cnf_auto_dtmf))
        {
            /* the result code is reserved */
        }
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_CNF_AUTO_DTMF, ucm_call_type);

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_ucm_call_type(ucm_call_type));

    if (cm_p->auto_dtmf_info.call_id == SRV_GCALL_INVALID_ID)
    {
        /* ignore, normal case. 
         * The user presses the key almost at the same time as the call is released.
         *     (release_ind is handled before the key event))
         */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_CNF_AUTO_DTMF_IGNORE);
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    if (cnf->result != SRV_UCM_QUERY_CNF_YES)
    {
        srv_gcall_reset_auto_dtmf_info();
    }
    else
    {
        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_AUTO_DTMF, NULL);
    }

    srv_gcall_cntxt_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_abort_redial_sim1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_cmhdlr_abort_redial_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cmhdlr_abort_auto_redial(MMI_SIM1);

}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_abort_redial_sim2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_cmhdlr_abort_redial_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cmhdlr_abort_auto_redial(MMI_SIM2);

}


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_abort_redial_sim3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_cmhdlr_abort_redial_sim3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cmhdlr_abort_auto_redial(MMI_SIM3);

}

#if (MMI_MAX_SIM_NUM == 4)
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_abort_redial_sim4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_cmhdlr_abort_redial_sim4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cmhdlr_abort_auto_redial(MMI_SIM4);

}
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_abort_auto_redial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_cmhdlr_abort_auto_redial(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum ori_sim = MMI_SIM_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cm_p)
    {
        ori_sim = cm_p->interface;
        srv_gcall_cntxt_reset_ptr();
    }

    srv_gcall_cntxt_set_ptr(sim);
    srv_gcall_reset_redial_info();
    srv_gcall_cntxt_reset_ptr();

    if (ori_sim != MMI_SIM_NONE)
    {
        srv_gcall_cntxt_set_ptr(ori_sim);
    }
}


#ifdef __CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_cnf_ccbs_recall
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
void srv_gcall_cmhdlr_cnf_ccbs_recall(srv_ucm_call_type_enum ucm_call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_cnf_struct *cnf = (srv_ucm_int_query_cnf_struct*)ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(cnf_type == SRV_UCM_INT_QUERY_CNF);

    if (srv_gcall_cntxt_is_locked())
    {
        if (!srv_gcall_post_cnf_evt(ucm_call_type, cnf_type, ptr, srv_gcall_cmhdlr_cnf_ccbs_recall))
        {
            /* the result code is reserved */
        }
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_CNF_CCBS_RECALL, ucm_call_type);

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_ucm_call_type(ucm_call_type));

    if (cm_p->ccbs_info.state != SRV_GCALL_CCBS_STATE_RECALL)
    {
        /* ignore, normal case. 
         * The user presses the key almost at the same time as the ccbs recall is released.
         *     (release_ind is handled before the key event))
         */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_CNF_CCBS_RECALL_IGNORE, cm_p->ccbs_info.state);
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    if (cnf->result != SRV_UCM_QUERY_CNF_YES)
    {
        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_CCBS_RECALL_REJECT, NULL);
    }
    else
    {
        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_CCBS_RECALL_ACCEPT, NULL);
    }

    srv_gcall_cntxt_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cmhdlr_cnf_ccbs_activate
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
void srv_gcall_cmhdlr_cnf_ccbs_activate(srv_ucm_call_type_enum ucm_call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_cnf_struct *cnf = (srv_ucm_int_query_cnf_struct*)ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(cnf_type == SRV_UCM_INT_QUERY_CNF);

    if (srv_gcall_cntxt_is_locked())
    {
        if (!srv_gcall_post_cnf_evt(ucm_call_type, cnf_type, ptr, srv_gcall_cmhdlr_cnf_ccbs_activate))
        {
            /* the result code is reserved */
        }
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_CNF_CCBS_ACTIVATE, ucm_call_type);

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_ucm_call_type(ucm_call_type));

    if (cm_p->ccbs_info.state != SRV_GCALL_CCBS_STATE_ACTIVATE_CNF)
    {
        /* ignore, normal case. 
         * The user presses the key almost at the same time as the call is released.
         *     (release_ind is handled before the key event))
         */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CMHDLR_CNF_CCBS_ACTIVATE_IGNORE, cm_p->ccbs_info.state);
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    if (cnf->result != SRV_UCM_QUERY_CNF_YES)
    {
        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_CCBS_IGNORE, NULL);
    }
    else
    {
        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_CCBS_ACTIVATE, NULL);
    }

    srv_gcall_cntxt_reset_ptr();

}

#endif /* __CCBS_SUPPORT__ */



/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_error
 * DESCRIPTION
 *  deside tone_id and error_cause; send rsp to UCM according to ucm_op
 *  error response or notification
 * PARAMETERS
 *  cause       [IN]        
 *  call_type   [IN]    may need different info for different call_type
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void srv_gcall_ucm_error(srv_ucm_call_type_enum ucm_call_type, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = STR_ID_GCALL_OP_FAIL;
    U16 img_id = IMG_GLOBAL_FAIL;
    U16 tone_id = ERROR_TONE_IN_CALL;
    srv_gcall_type_enum call_type = srv_gcall_util_get_internal_call_type(ucm_call_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UCM_DETAIL_ERROR_MSG__
    switch (result)
    {
        case SRV_GCALL_RESULT_UNASSIGNED_NUM:
            tone_id = NUM_UNOBTAIN_TONE;
        case SRV_GCALL_RESULT_INVALID_NUMBER_FORMAT:
            msg_id = STR_ID_GCALL_UNRECOGNIZED_NUMBER;
            break;

        case SRV_GCALL_RESULT_SWITCH_EQUIPMENT_CONGESTION:
            tone_id = CONGESTION_TONE;
            break;

        case SRV_GCALL_RESULT_CALL_REJECTED:
            tone_id= AUTH_FAIL_TONE;
            break;

        case SRV_GCALL_RESULT_CHANNEL_UN_ACCP:
        case SRV_GCALL_RESULT_NETWORK_OUT_OF_ORDER:
        case SRV_GCALL_RESULT_QOS_UNAVAIL:
        case SRV_GCALL_RESULT_INVALID_TRANSIT_NW_SEL:
        case SRV_GCALL_RESULT_CSMCC_NO_RESPONSE_FROM_NW:
        case SRV_GCALL_RESULT_NETWORK_FAILURE:
    #if !(defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_GCALL_RESULT_CM_MM_RR_CONN_RELEASE:
    #endif /* !(defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
        case SRV_GCALL_RESULT_IMSI_UNKNOWN_IN_VLR:
            msg_id = STR_ID_GCALL_NETWORK_FAIL;
            break;

        case SRV_GCALL_RESULT_ACCESS_CLASS_BARRED:
        case SRV_GCALL_RESULT_CM_MM_ACCESS_BARRED:
            msg_id = STR_ID_GCALL_BUSY_NETWORK_TRY_LATER;
            break;

        case SRV_GCALL_RESULT_USER_BUSY:
            /* voice call shows user busy, csd call shows network busy */
            if (call_type == CSMCC_VOICE_CALL)
            {
                msg_id = STR_ID_GCALL_USER_BUSY;
                tone_id = TONE_BUSY_CALL_GSM;
            }
            else
            {
                msg_id = STR_ID_GCALL_NETWORK_BUSY;
            }
            break;

        case SRV_GCALL_RESULT_NO_CIRCUIT_CHANNEL_AVAIL:
        case SRV_GCALL_RESULT_REQUESTED_CKT_CHANEL_NOT_AVIL:
        case SRV_GCALL_RESULT_RESOURCE_UNAVAIL_UNSPECIFIED:
            msg_id = STR_ID_GCALL_NETWORK_BUSY;
            break;

        case SRV_GCALL_RESULT_NO_USER_RESPONDING:
            msg_id = STR_ID_GCALL_NOT_RESPONDING;
            break;

        case SRV_GCALL_RESULT_NO_ANSWER_ON_ALERT:
            msg_id = STR_ID_GCALL_NO_ANSWER;
            break;

        case SRV_GCALL_RESULT_ACM_EXCEEDED:
            msg_id = STR_ID_GCALL_ACM_EXCEEDED;
            break;

        case SRV_GCALL_RESULT_REQ_FACILITY_UNAVAIL:
        case SRV_GCALL_RESULT_IE_NOT_IMPLEMENTED:
        case SRV_GCALL_RESULT_CONDITIONAL_MM_IE_ERROR:
        case SRV_GCALL_RESULT_CM_MM_ASSIGNMENT_REJECT:
            msg_id = STR_ID_GCALL_UNAVAILABLE;
            break;

        case SRV_GCALL_RESULT_CSMCC_ILLEGAL_DTMF_TONE:
        case SRV_GCALL_RESULT_CSMCC_CALL_ACCEPT_NOT_ALLOW:
        case SRV_GCALL_RESULT_MS_ID_NOT_DERIVED_BY_NW:
        case SRV_GCALL_RESULT_IMPLICIT_DETACH:
        case SRV_GCALL_RESULT_MSG_NOT_COMPAT_WITH_PROTO_STATE:
        case SRV_GCALL_RESULT_PROTO_ERROR_UNSPECIFIED:
            msg_id = STR_ID_GCALL_UNEXPECTED_ERROR;
            break;
/*
        case SRV_GCALL_RESULT_IMEI_NOT_ACCEPTED:
            msg_id = STR_ID_GCALL_IMEI_ERROR;
            break;
*/
        case SRV_GCALL_RESULT_GPRS_NOT_ALLOWED:
        case SRV_GCALL_RESULT_GPRS_NON_GPRS_NOT_ALLOWED:
            msg_id = STR_ID_GCALL_GPRS_NOT_ALLOWED;
            break;

        case SRV_GCALL_RESULT_MT_DATA_CALL_FAIL:
            msg_id = STR_ID_GCALL_MT_DATA_CALL_FAIL;
            break;

        case SRV_GCALL_RESULT_REQ_FAC_NOT_SUBS:
        case SRV_GCALL_RESULT_PLMN_NOT_ALLOWED:
        case SRV_GCALL_RESULT_LOCATION_AREA_NOT_ALLOWED:
        case SRV_GCALL_RESULT_ROAMING_AREA_NOT_ALLOWED:
        case SRV_GCALL_RESULT_GPRS_NOT_ALLOWED_IN_PLMN:
        case SRV_GCALL_RESULT_NO_SUITABLE_CELLS_IN_LA:
        case SRV_GCALL_RESULT_MSC_TEMP_NOT_REACHABLE:
        case SRV_GCALL_RESULT_CM_MM_ABORT_BY_NW:
        case SRV_GCALL_RESULT_BEARER_CAP_NOT_AUTHORISED:
        case SRV_GCALL_RESULT_SERV_OPTION_TEMP_OUT_OF_ORDER:
            msg_id = STR_ID_GCALL_NETWORK_NOT_ALLOWED;
            break;

        case SRV_GCALL_RESULT_CSMCC_CMD_NOT_ALLOW:
        case SRV_GCALL_RESULT_SERV_OPTION_NOT_SUPPORTED:
        case SRV_GCALL_RESULT_REQ_SERV_OPTION_NOT_SUBSCRIBED:
        case SRV_GCALL_RESULT_CALL_CANNOT_BE_IDENTIFIED:
            msg_id = STR_ID_GCALL_COMMAND_NOT_SUPPORTED;
            break;

        case SRV_GCALL_RESULT_NO_PDP_CONTEXT_ACTIVATED:
        case SRV_GCALL_RESULT_SEMANTICALLY_INCORRECT_MSG:
        case SRV_GCALL_RESULT_INVALID_MM_MAND_INFO:
            msg_id = STR_ID_GCALL_DATA_ERROR;
            break;

        case SRV_GCALL_RESULT_MSG_TYPE_NON_EXISTENT:
        case SRV_GCALL_RESULT_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE:
            msg_id = STR_ID_GCALL_MESSAGE_TYPE_ERROR;
            break;

        case SRV_GCALL_RESULT_CM_MM_RANDOM_ACCES_FAILURE:
            msg_id = STR_ID_GCALL_ACCESS_FAIL;
            break;

        case SRV_GCALL_RESULT_CM_MM_CONN_TIMEOUT:
            msg_id = STR_ID_GCALL_TIMER_EXPIRED;
            break;

        case SRV_GCALL_RESULT_L4C_FDN_FAIL:
            msg_id = STR_ID_GCALL_FDN_FAIL;
            break;

        case SRV_GCALL_RESULT_L4C_LOCAL_DISCONNECT_CSD:
            msg_id = STR_ID_GCALL_CSD_DISCONNECTING;
            break;

        case SRV_GCALL_RESULT_DISALLOW_MORE_CALL:
            msg_id = STR_ID_GCALL_INVALID_COMMAND;
            break;

        default:
            break;
    }   /* End of Switch */
#else /* __MMI_UCM_DETAIL_ERROR_MSG__ */
    switch (result)
    {
        case SRV_GCALL_RESULT_L4C_FDN_FAIL:
            msg_id = STR_ID_GCALL_FDN_FAIL;
            break;

        default:
            break;
    }   /* End of Switch */
#endif /* __MMI_UCM_DETAIL_ERROR_MSG__ */

    switch (cm_p->ucm_info.op)
    {
        case SRV_UCM_INT_DIAL_ACT:
            if (call_type != CSMCC_CSD_CALL)
            {
                srv_gcall_ucm_dial_rsp(result, (PU8)get_string(msg_id));
            }
            else
            {
                srv_gcall_ucm_dial_ind(result, (PU8)get_string(msg_id));
            }
            break;
            
        case SRV_UCM_INT_NO_ACT:
            srv_gcall_ucm_notify_ind(call_type, (PU8)get_string(msg_id), img_id, tone_id);
            break;
            
        default:
            srv_gcall_ucm_act_rsp(result, (PU8)get_string(msg_id));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_dial_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_dial_rsp(U16 result, U8 *error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_act_rsp_struct rsp;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&rsp, 0, sizeof(srv_ucm_int_dial_act_rsp_struct));

    /* call list */
    rsp.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    /* Be sure to clear outgoing call info before ucm_dial_rsp */
    srv_gcall_get_ucm_call_list(rsp.call_list);

    rsp.result_info.result = srv_gcall_util_get_ucm_result(result);
    if (error_msg)
    {
        mmi_ucs2ncpy((CHAR *)rsp.result_info.error_msg, (CHAR *)error_msg, SRV_UCM_MAX_ERR_MSG_LEN);
    }

    if ((result == SRV_GCALL_RESULT_OK)
        && (call_info))
    {
        /* uid info */
        rsp.uid_info.call_id = call_info->call_id;
        rsp.uid_info.group_id = call_info->group_id;
        rsp.uid_info.call_type = cm_p->ucm_info.call_type;

        /* remote info */
        strncpy((CHAR *)rsp.remote_info.num_uri,
            (CHAR *)call_info->num2,
            SRV_UCM_MAX_NUM_URI_LEN);

        srv_gcall_derive_display_name(call_info, (PU8)rsp.remote_info.disp_name, SRV_UCM_MAX_DISP_NAME_LEN);
        mmi_ucs2ncpy((CHAR *)rsp.remote_info.log_name, (CHAR *)srv_gcall_get_call_log_name(call_info), MMI_PHB_NAME_LENGTH);

        srv_gcall_set_remote_line_icon(call_info, &rsp.remote_info);

    #ifdef __MMI_UCM_NUMBER_TYPE__
        rsp.remote_info.number_type = call_info->number_type;
        rsp.remote_info.num_type_icon = srv_gcall_derive_number_type_icon(call_info->number_type);
    #endif /* __MMI_UCM_NUMBER_TYPE__ */

        rsp.remote_info.phb_id = cm_p->phb_data.phb_id;

        /* display info */
        /* Not allow caller video for outgoing call */
                    
    #ifdef __IP_NUMBER__
        if (cm_p->mo.is_ip_dial)
        {
            srv_gcall_util_get_curr_ip_number_ucs2(cm_p->interface, (WCHAR*)(rsp.display_info.ip_num));
        }
    #endif /* __IP_NUMBER__ */ 
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UCM_DIAL_RSP_INFO,
        rsp.result_info.result, 
        rsp.remote_info.num_uri[0], rsp.remote_info.num_uri[1], rsp.remote_info.num_uri[2],
        rsp.remote_info.num_uri[3], rsp.remote_info.num_uri[4]);

    (*(cm_p->ucm_info.rsp_cb))(rsp.uid_info.call_type, SRV_UCM_INT_DIAL_ACT, &rsp, cm_p->ucm_info.user_data);

    srv_gcall_reset_ucm_info_except_bg_op();
    
    srv_ucm_int_mfree(rsp.call_list);

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_act_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_act_rsp(U16 result, U8 *error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_act_rsp_struct rsp;
#ifdef __MMI_VIDEO_TELEPHONY__
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_ACTIVE);
#endif /* __MMI_VIDEO_TELEPHONY__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(cm_p->ucm_info.op != SRV_UCM_INT_NO_ACT);

    memset(&rsp, 0, sizeof(srv_ucm_int_act_rsp_struct));

    rsp.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(rsp.call_list);

    rsp.result_info.result = srv_gcall_util_get_ucm_result(result);
    if (error_msg)
    {
        mmi_ucs2ncpy((CHAR *)rsp.result_info.error_msg, (CHAR *)error_msg, SRV_UCM_MAX_ERR_MSG_LEN);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    /* Turn on speech */
    if (call_info && call_info->call_type == CSMCC_VIDEO_CALL)
    {
        rsp.no_counter = MMI_TRUE;
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UCM_ACT_RSP_INFO,
    cm_p->ucm_info.op,
    rsp.result_info.result);

    (*(cm_p->ucm_info.rsp_cb))(cm_p->ucm_info.call_type, cm_p->ucm_info.op, (void*)&rsp, cm_p->ucm_info.user_data);

    srv_gcall_reset_ucm_info_except_bg_op();

    srv_ucm_int_mfree(rsp.call_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_call_present_cnf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_call_present_cnf_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_present_ind_struct *msg = (mmi_cc_call_present_ind_struct*)info;
    srv_ucm_int_call_present_cnf_ind_struct cnf_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&cnf_ind, 0, sizeof(srv_ucm_int_call_present_cnf_ind_struct));

    /* uid info */
    srv_gcall_set_uid_info(&cnf_ind.uid_info, msg->call_id, SRV_UCM_INVALID_ID, (srv_gcall_type_enum)msg->call_type);

    strncpy((CHAR *)cnf_ind.num_uri, (CHAR *)msg->num.number, SRV_UCM_MAX_NUM_URI_LEN);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UCM_CALL_PRESENT_CNF_IND_INFO,
    msg->call_id,
    msg->call_type,
    msg->num.number[0], msg->num.number[1], msg->num.number[2],
    msg->num.number[3], msg->num.number[4]);

    srv_ucm_int_cnf_indication(cnf_ind.uid_info.call_type, SRV_UCM_INT_CALL_PRESENT_CNF_IND, &cnf_ind, srv_gcall_cmhdlr_cnf);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_ring_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_ring_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_ring_ind_struct ring_ind;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_INCOMING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    memset(&ring_ind, 0, sizeof(srv_ucm_int_ring_ind_struct));

    /* uid info */
    srv_gcall_set_uid_info(&ring_ind.uid_info, call_info->call_id, call_info->group_id, call_info->call_type);
    
    /* at info */
    ring_ind.at_info.l4c_type = call_info->call_type;
    memcpy(&ring_ind.at_info.l4c_number, &cm_p->mt.l4c_number, sizeof(l4c_number_struct));

    /* display info */
    ring_ind.display_info.alert_type = cm_p->mt.alert_type;
    ring_ind.display_info.light_id = cm_p->mt.backlight_pattern_id;

    /* remote info*/
    srv_gcall_derive_display_name(call_info, (PU8)ring_ind.remote_info.disp_name, SRV_UCM_MAX_DISP_NAME_LEN);
#ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
    if (cm_p->mt.no_cli_cuase != CSMCC_INVALID_NO_CLI_CAUSE)
    {
        U8 length = (SRV_UCM_MAX_DISP_NAME_LEN - mmi_ucs2strlen((CHAR *)ring_ind.remote_info.disp_name)) * ENCODING_LENGTH;
        PU8 no_cli_msg = NULL;

        no_cli_msg = OslMalloc(length);
        memset(no_cli_msg, 0, length);
        srv_gcall_util_get_no_cli_display_text(cm_p->mt.no_cli_cuase, no_cli_msg);
        mmi_ucs2cat((CHAR *)ring_ind.remote_info.disp_name, GetString(STR_ID_GCALL_LEFT_PARENTHESIS));
        mmi_ucs2ncat((CHAR *)ring_ind.remote_info.disp_name, (CHAR *)no_cli_msg, mmi_ucs2strlen((CHAR *)no_cli_msg));
        mmi_ucs2cat((CHAR *)ring_ind.remote_info.disp_name, GetString(STR_ID_GCALL_RIGHT_PARENTHESIS));
        OslMfree(no_cli_msg);
    }
#endif /* __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__ */

    mmi_ucs2ncpy((CHAR *)ring_ind.remote_info.log_name, (CHAR *)srv_gcall_get_call_log_name(call_info), MMI_PHB_NAME_LENGTH);
    strncpy((CHAR *)ring_ind.remote_info.num_uri, (CHAR *)srv_gcall_get_call_log_number(call_info), SRV_UCM_MAX_NUM_URI_LEN);

    srv_gcall_set_remote_line_icon(call_info, &ring_ind.remote_info);

#ifdef __MMI_UCM_NUMBER_TYPE__
    ring_ind.remote_info.number_type = call_info->number_type;
    ring_ind.remote_info.num_type_icon = srv_gcall_derive_number_type_icon(call_info->number_type);
#endif /* __MMI_UCM_NUMBER_TYPE__ */

    ring_ind.remote_info.phb_id = cm_p->phb_data.phb_id;

    /*call list*/
    ring_ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(ring_ind.call_list);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UCM_RING_IND_REMOTE_INFO,
        call_info->call_id,
        ring_ind.remote_info.disp_name[0], ring_ind.remote_info.disp_name[1],
        ring_ind.remote_info.disp_name[2], ring_ind.remote_info.disp_name[3],
        ring_ind.remote_info.disp_name[4],
        ring_ind.remote_info.log_name[0], ring_ind.remote_info.log_name[1],
        ring_ind.remote_info.log_name[2], ring_ind.remote_info.log_name[3], 
        ring_ind.remote_info.log_name[4],
        ring_ind.remote_info.num_uri[0], ring_ind.remote_info.num_uri[1],
        ring_ind.remote_info.num_uri[2], ring_ind.remote_info.num_uri[3],
        ring_ind.remote_info.num_uri[4]);

    srv_ucm_int_indication(ring_ind.uid_info.call_type, SRV_UCM_INT_RING_IND, (void*)&ring_ind);
    srv_ucm_int_mfree(ring_ind.call_list);

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_dial_cnf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_dial_cnf_ind(srv_gcall_type_enum call_type, U8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_cnf_ind_struct cnf_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&cnf_ind, 0, sizeof(srv_ucm_int_dial_cnf_ind_struct));

    strncpy((CHAR *)cnf_ind.num_uri, (CHAR *)number, SRV_UCM_MAX_NUM_URI_LEN);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UCM_DIAL_CNF_IND, 
        cnf_ind.num_uri[0], cnf_ind.num_uri[1], cnf_ind.num_uri[2],
        cnf_ind.num_uri[3], cnf_ind.num_uri[4]);

    srv_ucm_int_cnf_indication(srv_gcall_get_ucm_call_type(call_type), 
        SRV_UCM_INT_DIAL_CNF_IND, &cnf_ind, srv_gcall_cmhdlr_cnf);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_dial_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_dial_ind(U16 result, U8 *error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_ind_struct ind;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* similar procedure as ucm_dial_rsp */

    memset(&ind, 0, sizeof(srv_ucm_int_dial_ind_struct));

    /* result info */
    ind.result_info.result = srv_gcall_util_get_ucm_result(result);
    if (error_msg)
    {
        mmi_ucs2ncpy((CHAR *)ind.result_info.error_msg, (CHAR *)error_msg, SRV_UCM_MAX_ERR_MSG_LEN);
    }

    /* call list */
    ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(ind.call_list);
    
    if ((result == SRV_GCALL_RESULT_OK)
        && (call_info))
    {
        /* uid info */
        srv_gcall_set_uid_info(&ind.uid_info, call_info->call_id, call_info->group_id, call_info->call_type);

        /* remote info */
        strncpy((CHAR *)ind.remote_info.num_uri,
            (CHAR *)call_info->num2,
            SRV_UCM_MAX_NUM_URI_LEN);

        srv_gcall_derive_display_name(call_info, (PU8)ind.remote_info.disp_name, SRV_UCM_MAX_DISP_NAME_LEN);
        mmi_ucs2ncpy((CHAR *)ind.remote_info.log_name, (CHAR *)srv_gcall_get_call_log_name(call_info), MMI_PHB_NAME_LENGTH);

        srv_gcall_set_remote_line_icon(call_info, &ind.remote_info);

    #ifdef __MMI_UCM_NUMBER_TYPE__
        ind.remote_info.number_type = call_info->number_type;
        ind.remote_info.num_type_icon = srv_gcall_derive_number_type_icon(call_info->number_type);
    #endif /* __MMI_UCM_NUMBER_TYPE__ */

        ind.remote_info.phb_id = cm_p->phb_data.phb_id;

        /* display info */
    #ifdef __IP_NUMBER__
        if (cm_p->mo.is_ip_dial)
        {
            srv_gcall_util_get_curr_ip_number_ucs2(cm_p->interface, (WCHAR*)ind.display_info.ip_num);
        }
    #endif /* __IP_NUMBER__ */ 
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UCM_DIAL_IND,
        ind.result_info.result,
        ind.remote_info.disp_name[0], ind.remote_info.disp_name[1],
        ind.remote_info.disp_name[2], ind.remote_info.disp_name[3],
        ind.remote_info.disp_name[4],
        ind.remote_info.log_name[0], ind.remote_info.log_name[1],
        ind.remote_info.log_name[2], ind.remote_info.log_name[3], 
        ind.remote_info.log_name[4],
        ind.remote_info.num_uri[0], ind.remote_info.num_uri[1],
        ind.remote_info.num_uri[2], ind.remote_info.num_uri[3],
        ind.remote_info.num_uri[4]);

    srv_ucm_int_indication(ind.uid_info.call_type, SRV_UCM_INT_DIAL_IND, (void*)&ind);
    
    srv_gcall_reset_ucm_info_except_bg_op();

    srv_ucm_int_mfree(ind.call_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_notify_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_notify_ind(srv_gcall_type_enum call_type, PU8 error_msg, U16 image_id, U16 tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_notify_ind_struct notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&notify, 0, sizeof(srv_ucm_int_notify_ind_struct));

    notify.call_type = srv_gcall_get_ucm_call_type(call_type);

    /*display*/
    if (image_id)
    {
        /* error */
        notify.image_id = image_id;
        notify.tone_id = tone_id;
    }
    else
    {
        /* information */
        notify.image_id = mmi_get_event_based_image(MMI_EVENT_INFO);
        notify.tone_id = (U16)mmi_get_event_based_sound(MMI_EVENT_INFO);
    }

    if (error_msg)
    {
        mmi_ucs2ncpy((CHAR *)notify.disp_msg, (CHAR *)error_msg, SRV_UCM_MAX_DISP_MSG_LEN);
    }

    /*call list*/
    notify.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(notify.call_list);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UCM_NOTIFY_IND);

    srv_ucm_int_indication(notify.call_type, SRV_UCM_INT_NOTIFY_IND, &notify);

    srv_ucm_int_mfree(notify.call_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_connect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_connect_ind(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_connect_ind_struct ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&ind, 0, sizeof(srv_ucm_int_connect_ind_struct));

    /*uid info*/
    srv_gcall_set_uid_info(&ind.uid_info, call_info->call_id, call_info->group_id, call_info->call_type);

    /*remote info*/
    srv_gcall_derive_display_name(call_info, (PU8)ind.remote_info.disp_name, SRV_UCM_MAX_DISP_NAME_LEN);    
    mmi_ucs2ncpy((CHAR *)ind.remote_info.log_name, (CHAR *)srv_gcall_get_call_log_name(call_info), MMI_PHB_NAME_LENGTH);
    strncpy((CHAR *)ind.remote_info.num_uri, (CHAR *)srv_gcall_get_call_log_number(call_info), SRV_UCM_MAX_NUM_URI_LEN);

    srv_gcall_set_remote_line_icon(call_info, &ind.remote_info);

#ifdef __MMI_UCM_NUMBER_TYPE__
    ind.remote_info.number_type = call_info->number_type;
    ind.remote_info.num_type_icon = srv_gcall_derive_number_type_icon(call_info->number_type);
#endif /* __MMI_UCM_NUMBER_TYPE__ */

    ind.remote_info.phb_id = cm_p->phb_data.phb_id;

    /*call list*/
    ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(ind.call_list);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UCM_CONNECT_IND,
        call_info->call_id,
        ind.remote_info.disp_name[0], ind.remote_info.disp_name[1],
        ind.remote_info.disp_name[2], ind.remote_info.disp_name[3],
        ind.remote_info.disp_name[4],
        ind.remote_info.log_name[0], ind.remote_info.log_name[1],
        ind.remote_info.log_name[2], ind.remote_info.log_name[3], 
        ind.remote_info.log_name[4],
        ind.remote_info.num_uri[0], ind.remote_info.num_uri[1],
        ind.remote_info.num_uri[2], ind.remote_info.num_uri[3],
        ind.remote_info.num_uri[4]);

#ifdef __MMI_VIDEO_TELEPHONY__
    /* Turn on speech */
    if (call_info->call_type == CSMCC_VIDEO_CALL)
    {
        srv_gcall_ucm_speech_ind(MMI_TRUE, (U8)MDI_AUDIO_SPEECH_APP_ID_3G324M, CSMCC_VIDEO_CALL);
        ind.no_counter = MMI_TRUE;
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    srv_ucm_int_indication(ind.uid_info.call_type, SRV_UCM_INT_CONNECT_IND, &ind);

    srv_ucm_int_mfree(ind.call_list);
}

#if defined(__GGT_TASK__)
#if defined(__OLED_BW_MMI__)
extern void mmi_set_sos_status(U8 s);
extern U8 mmi_get_sos_status(void);
extern void mmi_set_sos_call_alert(U8 s);
extern U8 mmi_get_sos_call_alert(void);
extern void mmi_idle_start_remake_sos_call(void);
#endif /* __OLED_BW_MMI__ */
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_speech_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_speech_ind(MMI_BOOL turn_on, U8 rat, srv_gcall_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_speech_ind_struct speech_ind;
    srv_ucm_int_session_ind_struct session_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&speech_ind, 0, sizeof(srv_ucm_int_speech_ind_struct));
    memset(&session_ind, 0, sizeof(srv_ucm_int_session_ind_struct));

    /*call type*/
    speech_ind.call_type = srv_gcall_get_ucm_call_type(call_type);

    /*session type*/
    speech_ind.session_type = rat;
    session_ind.session_type = rat;
    
    /*switch*/
    speech_ind.local_switch = turn_on;
    speech_ind.remote_switch = turn_on;
    session_ind.session_switch = turn_on;

    /*call list*/
    speech_ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(speech_ind.call_list);

    session_ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(session_ind.call_list);

    if (turn_on == MMI_TRUE)
    {
        /* start session */
        srv_ucm_int_indication(speech_ind.call_type, SRV_UCM_INT_SESSION_IND, &session_ind);
        srv_ucm_int_mfree(session_ind.call_list);

        /* turn on codec */
        srv_ucm_int_indication(speech_ind.call_type, SRV_UCM_INT_SPEECH_IND, &speech_ind);
        srv_ucm_int_mfree(speech_ind.call_list);
#if defined(__OLED_BW_MMI__)
		//mmi_set_sos_status(1);	
#endif /* __OLED_BW_MMI__ */
    }
    else
    {
        /* turn off codec */
        srv_ucm_int_indication(speech_ind.call_type, SRV_UCM_INT_SPEECH_IND, &speech_ind);
        srv_ucm_int_mfree(speech_ind.call_list);

        /* stop session */
        srv_ucm_int_indication(speech_ind.call_type, SRV_UCM_INT_SESSION_IND, &session_ind);
        srv_ucm_int_mfree(session_ind.call_list);
#if defined(__GGT_TASK__)
{
	extern void cityeasy_set_outcall_monitor_state(U8 state);
	cityeasy_set_outcall_monitor_state(0);
}
#endif /* __GGT_TASK__ */

#if defined(__GGT_TASK__)
#if defined(__OLED_BW_MMI__)
	if(mmi_get_sos_call_alert() == 1)
	{
		mmi_set_sos_call_alert(0);
	}
	else
	{
		if(mmi_get_sos_status() == 1)
		{
			mmi_idle_start_remake_sos_call();
		}
	}
	mmi_set_sos_status(0);	
#endif /* __OLED_BW_MMI__ */
#endif

#ifdef __SLC_FUNC__

	{
		extern void slc_set_outcall_monitor_state(U8 state);
		slc_set_outcall_monitor_state(0);
	}
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_cancel_query_cnf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_cancel_query_cnf_ind(srv_gcall_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ucm_int_indication(srv_gcall_get_ucm_call_type(call_type), 
        SRV_UCM_INT_CANCEL_QUERY_IND, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_cancel_query_ind_by_call_id
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_cancel_query_ind_by_call_id(U8 call_id, srv_gcall_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (call_id == cm_p->auto_dtmf_info.call_id)
    {
        /* cancel auto dtmf */
        srv_gcall_ucm_cancel_query_cnf_ind(call_type);
        srv_gcall_reset_auto_dtmf_info();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_release_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_release_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_release_ind_struct release_ind; 
    PU8 disp_msg;
#ifdef __OP21__
    U8 tmp_str[10];
    WCHAR ucs2_tmp_str[10];
#endif /* __OP21__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&release_ind, 0, sizeof(srv_ucm_int_release_ind_struct));

    /* uid info */
    srv_gcall_set_uid_info(&release_ind.uid_info, cm_p->release_call_info.call_id, cm_p->release_call_info.group_id, cm_p->release_call_info.call_type);

    /* post action */
    if (cm_p->release_call_info.post_action)
    {
        release_ind.post_action.action = cm_p->release_call_info.post_action;
    #ifdef __IP_NUMBER__
        release_ind.post_action.is_ip_dial = cm_p->mo.is_ip_dial;
    #endif /* __IP_NUMBER__ */

        release_ind.post_action.phb_data = cm_p->redial_info.phb_data;
    }

    /*display info*/
    release_ind.image_id = IMG_GLOBAL_FAIL;
    release_ind.tone_id = CALL_DROP_TONE;
    disp_msg = (PU8)GetString(STR_ID_GCALL_CALL_ENDED);  /*default error message*/

    switch (cm_p->release_call_info.cause)
    {
    #ifdef __MMI_UCM_DETAIL_ERROR_MSG__
        case SRV_GCALL_RESULT_UNASSIGNED_NUM:
            release_ind.tone_id = NUM_UNOBTAIN_TONE;
        case SRV_GCALL_RESULT_INVALID_NUMBER_FORMAT:
    #ifdef __OP21__
        case SRV_GCALL_RESULT_NUMBER_CHANGED:
            disp_msg = (PU8)GetString(STR_ID_GCALL_NUMBER_NOT_AVAILABLE);
    #else /* __OP21__ */
            disp_msg = (PU8)GetString(STR_ID_GCALL_UNRECOGNIZED_NUMBER);
    #endif /* __OP21__ */
            break;

    #ifndef __OP21__
        case SRV_GCALL_RESULT_SWITCH_EQUIPMENT_CONGESTION:
            release_ind.tone_id = CONGESTION_TONE;

        case SRV_GCALL_RESULT_CHANNEL_UN_ACCP:
        case SRV_GCALL_RESULT_NETWORK_OUT_OF_ORDER:
        case SRV_GCALL_RESULT_QOS_UNAVAIL:
        case SRV_GCALL_RESULT_INVALID_TRANSIT_NW_SEL:
    #endif /* __OP21__ */
        case SRV_GCALL_RESULT_CSMCC_NO_RESPONSE_FROM_NW:
        case SRV_GCALL_RESULT_NETWORK_FAILURE:
    #if !(defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_GCALL_RESULT_CM_MM_RR_CONN_RELEASE:
    #endif /* !(defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
        case SRV_GCALL_RESULT_IMSI_UNKNOWN_IN_VLR:
            disp_msg = (PU8)GetString(STR_ID_GCALL_NETWORK_FAIL);
            break;

    #ifndef __OP21__
        case SRV_GCALL_RESULT_NO_CIRCUIT_CHANNEL_AVAIL:
        case SRV_GCALL_RESULT_REQUESTED_CKT_CHANEL_NOT_AVIL:
        case SRV_GCALL_RESULT_RESOURCE_UNAVAIL_UNSPECIFIED:
            disp_msg = (PU8)GetString(STR_ID_GCALL_NETWORK_BUSY);
            break;
    #endif /* __OP21__ */

        case SRV_GCALL_RESULT_ACCESS_CLASS_BARRED:
        case SRV_GCALL_RESULT_CM_MM_ACCESS_BARRED:
            disp_msg = (PU8)GetString(STR_ID_GCALL_BUSY_NETWORK_TRY_LATER);
            break;

        case SRV_GCALL_RESULT_CALL_REJECTED:
            release_ind.tone_id= AUTH_FAIL_TONE;
    #ifdef __OP21__
        case SRV_GCALL_RESULT_DEST_OUT_OF_ORDER:
            disp_msg = (PU8)GetString(STR_ID_GCALL_NOT_AVAILABLE_USER);
    #endif /* __OP21__ */
            break;

    #ifndef __OP21__
        case SRV_GCALL_RESULT_IC_BAR_CUG:
        case SRV_GCALL_RESULT_BEARER_CAP_NOT_AVAIL:
    #endif /* __OP21__ */
        case SRV_GCALL_RESULT_OPR_DTR_BARRING:
        case SRV_GCALL_RESULT_CALL_BARRED:
    #ifdef __OP21__
            disp_msg = (PU8)GetString(STR_ID_GCALL_NOT_AVAILABLE_USER);
    #else /* __OP21__ */
            disp_msg = (PU8)GetString(STR_ID_GCALL_BARRED_CALL);
    #endif /* __OP21__ */
            break;
        
        case SRV_GCALL_RESULT_NO_USER_RESPONDING:
    #ifndef __OP21__
            disp_msg = (PU8)GetString(STR_ID_GCALL_NOT_RESPONDING);
            break;
    #endif /* __OP21__ */

        case SRV_GCALL_RESULT_NO_ANSWER_ON_ALERT:
    #ifdef __OP21__
            disp_msg = (PU8)GetString(STR_ID_GCALL_NOT_ANSWER_FROM_USER);
    #else /* __OP21__ */
            disp_msg = (PU8)GetString(STR_ID_GCALL_NO_ANSWER);
    #endif /* __OP21__ */
            break;
        
    #ifndef __OP21__
        case SRV_GCALL_RESULT_REQ_FACILITY_UNAVAIL:
    #endif /* __OP21__ */
        case SRV_GCALL_RESULT_IE_NOT_IMPLEMENTED:
        case SRV_GCALL_RESULT_CONDITIONAL_MM_IE_ERROR:
        case SRV_GCALL_RESULT_CM_MM_ASSIGNMENT_REJECT:
            disp_msg = (PU8)GetString(STR_ID_GCALL_UNAVAILABLE);
            break;
        
        case SRV_GCALL_RESULT_IMSI_UNKNOWN_IN_HLR:
        case SRV_GCALL_RESULT_CM_MM_IMSI_DETACH:
        case SRV_GCALL_RESULT_CM_MM_AUTH_FAILURE:
        case SRV_GCALL_RESULT_CM_MM_STATE_NOT_ALLOWED_CM:
            disp_msg = (PU8)GetString(STR_GLOBAL_FAILED);
            break;
/*        
        case SRV_GCALL_RESULT_IMEI_NOT_ACCEPTED:
            disp_msg = (PU8)GetString(STR_ID_GCALL_IMEI_ERROR);
            break;
*/        
    #ifndef __OP21__
        case SRV_GCALL_RESULT_REQ_FAC_NOT_SUBS:
        case SRV_GCALL_RESULT_BEARER_CAP_NOT_AUTHORISED:
    #endif /* __OP21__ */
        case SRV_GCALL_RESULT_PLMN_NOT_ALLOWED:
        case SRV_GCALL_RESULT_LOCATION_AREA_NOT_ALLOWED:
        case SRV_GCALL_RESULT_ROAMING_AREA_NOT_ALLOWED:
        case SRV_GCALL_RESULT_GPRS_NOT_ALLOWED_IN_PLMN:
        case SRV_GCALL_RESULT_NO_SUITABLE_CELLS_IN_LA:
        case SRV_GCALL_RESULT_MSC_TEMP_NOT_REACHABLE:
        case SRV_GCALL_RESULT_CM_MM_ABORT_BY_NW:
        case SRV_GCALL_RESULT_SERV_OPTION_TEMP_OUT_OF_ORDER:
            disp_msg = (PU8)GetString(STR_ID_GCALL_NETWORK_NOT_ALLOWED);
            break;
        
        case SRV_GCALL_RESULT_SERV_OPTION_NOT_SUPPORTED:
        case SRV_GCALL_RESULT_REQ_SERV_OPTION_NOT_SUBSCRIBED:
        case SRV_GCALL_RESULT_CALL_CANNOT_BE_IDENTIFIED:
            disp_msg = (PU8)GetString(STR_ID_GCALL_COMMAND_NOT_SUPPORTED);
            break;
        
    #ifndef __OP21__
        case SRV_GCALL_RESULT_ACM_EXCEEDED:
            disp_msg = (PU8)GetString(STR_ID_GCALL_ACM_EXCEEDED);
            break;
    #endif /* __OP21__ */
        
        case SRV_GCALL_RESULT_USER_BUSY:
    #ifdef __OP21__
            disp_msg = (PU8)GetString(STR_ID_GCALL_BUSY_NUMBER);
    #else /* __OP21__ */
            disp_msg = (PU8)GetString(STR_ID_GCALL_USER_BUSY);
    #endif /* __OP21__ */
            release_ind.tone_id = TONE_BUSY_CALL_GSM;
            break;

    #ifdef __OP21__
        case SRV_GCALL_RESULT_NO_ROUTE_TO_DESTINATION:
            disp_msg = (PU8)GetString(STR_ID_GCALL_CALLER_USER_NOT_AVAILABLE);
            break;
    #endif /* __OP21__ */
    #endif /* __MMI_UCM_DETAIL_ERROR_MSG__ */
    
        case SRV_GCALL_RESULT_L4C_FDN_FAIL:
            disp_msg = (PU8)GetString(STR_ID_GCALL_FDN_FAIL);
            break;

        default:
            if (MMI_FALSE)
            {
            }
    #ifndef __OP21__
            /* mo fail */
            else if ((cm_p->release_call_info.state == SRV_GCALL_STATE_OUTGOING) &&
                        !(cm_p->release_call_info.is_abort))
            {
                disp_msg = (PU8)GetString(STR_ID_GCALL_UNABLE_TO_CONNECT);
            }
    #endif /* __OP21__ */
            /* normal call end */
            else
            {
                disp_msg = (PU8)GetString(STR_ID_GCALL_CALL_ENDED); 
            }
            release_ind.image_id = IMG_ID_GCALL_CALL_ENDED;
            break;
    }

    /* take as normal call clearing */
    if (cm_p->release_call_info.is_abort)
    {
        cm_p->release_call_info.cause = SRV_GCALL_RESULT_NORMAL_CALL_CLR;
        if (cm_p->release_call_info.state != SRV_GCALL_STATE_OUTGOING)
        {
            disp_msg = (PU8)GetString(STR_ID_GCALL_CALL_ENDED); 
        }
        else
        {
            disp_msg = (PU8)GetString(STR_ID_GCALL_CALL_ABORTED);
            release_ind.error_cause = SRV_UCM_RESULT_USER_ABORT;
        }
        release_ind.image_id = IMG_ID_GCALL_CALL_ENDED;
    }

    mmi_ucs2ncpy((CHAR *)release_ind.disp_msg, (CHAR *)disp_msg, SRV_UCM_MAX_ERR_MSG_LEN);

#ifdef __OP21__
    if (cm_p->release_call_info.cause &&
        cm_p->release_call_info.cause != SRV_GCALL_RESULT_NORMAL_CALL_CLR &&
        cm_p->release_call_info.cause != SRV_GCALL_RESULT_USER_BUSY &&
        cm_p->release_call_info.cause < 10000)
    {
        memset(tmp_str, 0, sizeof(tmp_str));
        memset(ucs2_tmp_str, 0, sizeof(ucs2_tmp_str));
        sprintf((CHAR *)tmp_str, " -%02d-", cm_p->release_call_info.cause);
        mmi_asc_to_ucs2((CHAR *)ucs2_tmp_str, (CHAR *)tmp_str);
        mmi_ucs2ncat((CHAR *)release_ind.disp_msg, (CHAR *)ucs2_tmp_str, SRV_UCM_MAX_ERR_MSG_LEN - mmi_ucs2strlen((CHAR *)release_ind.disp_msg));
    }
#endif /* __OP21__ */

    if (release_ind.error_cause != SRV_UCM_RESULT_USER_ABORT)
    {
        release_ind.error_cause = srv_gcall_util_get_ucm_result(cm_p->release_call_info.cause);
    }

    if (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_TOTAL, (srv_gcall_type_enum)0)
        || srv_gcall_util_is_data_csd(cm_p->release_call_info.call_type))
    {
        release_ind.tone_id = 0;
    }

    /*call list*/
    release_ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(release_ind.call_list);

    /* do not reset cntxt ptr (not allow ucm to to other request in ind handler) */

    srv_ucm_int_indication(release_ind.uid_info.call_type, SRV_UCM_INT_RELEASE_IND, &release_ind);

    srv_ucm_int_mfree(release_ind.call_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_auto_redial_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_auto_redial_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_auto_redial_ind_struct ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&ind, 0, sizeof(srv_ucm_int_auto_redial_ind_struct));

    ind.call_type = srv_gcall_get_ucm_call_type(cm_p->release_call_info.call_type);
    mmi_ucs2ncpy((CHAR *)ind.display_msg, (CHAR *)cm_p->redial_info.msg, SRV_UCM_MAX_AUTO_REDIAL_MSG_LEN);
    strncpy((CHAR *)ind.num_uri, (CHAR *)cm_p->mo.num, SRV_UCM_MAX_NUM_URI_LEN);

#ifdef __IP_NUMBER__
     ind.is_ip_dial = cm_p->mo.is_ip_dial;
#endif /* __IP_NUMBER__ */

    ind.attempt = cm_p->redial_info.curr_attempt; 
    ind.time = cm_p->redial_info.timer;

    switch (cm_p->interface)
    {
        case MMI_SIM1:
            ind.abort_hdlr = srv_gcall_cmhdlr_abort_redial_sim1;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            ind.abort_hdlr = srv_gcall_cmhdlr_abort_redial_sim2;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            ind.abort_hdlr = srv_gcall_cmhdlr_abort_redial_sim3;
            break;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            ind.abort_hdlr = srv_gcall_cmhdlr_abort_redial_sim4;
            break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            break;
    }

    ind.phb_data = cm_p->redial_info.phb_data;

    srv_ucm_int_indication(ind.call_type, SRV_UCM_INT_AUTO_REDIAL_IND, &ind);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_disconnecting_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_disconnecting_ind(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_disconnecting_ind_struct ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&ind, 0, sizeof(srv_ucm_int_disconnecting_ind_struct));

    /* uid */
    srv_gcall_set_uid_info(&ind.uid_info, call_info->call_id, call_info->group_id, call_info->call_type);

    /* call list */
    ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(ind.call_list);

    srv_ucm_int_indication(ind.uid_info.call_type, SRV_UCM_INT_DISCONNECTING_IND, &ind);

    srv_ucm_int_mfree(ind.call_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_sync_call_list_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_sync_call_list_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_sync_call_list_ind_struct ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* call list */
    ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(ind.call_list);

    srv_ucm_int_indication(ind.call_list->call_type, SRV_UCM_INT_SYNC_CALL_LIST_IND, &ind);

    srv_ucm_int_mfree(ind.call_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_alert_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_alert_ind(srv_gcall_call_info_struct *call_info, U8 gen_tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_alert_ind_struct alert_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&alert_ind, 0, sizeof(srv_ucm_int_alert_ind_struct));

    /* uid */
    srv_gcall_set_uid_info(&alert_ind.uid_info, call_info->call_id, call_info->group_id, call_info->call_type);

    /* generate tone or not */
    alert_ind.local_gen = gen_tone;

    /* call list */
    alert_ind.call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    srv_gcall_get_ucm_call_list(alert_ind.call_list);

    srv_ucm_int_indication(alert_ind.uid_info.call_type, SRV_UCM_INT_ALERT_IND, &alert_ind);

    srv_ucm_int_mfree(alert_ind.call_list);

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_auto_dtmf_cnf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_auto_dtmf_cnf_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_cnf_ind_struct cnf_ind;
    U8 tmp_buf[SRV_GCALL_MAX_DTMF_DIGITS * ENCODING_LENGTH + 40];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&cnf_ind, 0, sizeof(srv_ucm_int_query_cnf_ind_struct));
    memset(tmp_buf, 0, sizeof(tmp_buf));

    /* content */
    mmi_ucs2cpy((CHAR *)tmp_buf, GetString(STR_ID_GCALL_DTMF_CONFIRMATION));
    mmi_asc_to_ucs2((CHAR *)tmp_buf + (mmi_ucs2strlen((CHAR *)tmp_buf) * ENCODING_LENGTH), (CHAR *)cm_p->auto_dtmf_info.buf);

    mmi_ucs2ncpy((CHAR *)cnf_ind.content, (CHAR *)tmp_buf, SRV_UCM_MAX_DISP_MSG_LEN);
    cnf_ind.disp_condition = SRV_UCM_DISP_ECC; /* Auto DTMF is also available for ECC */

    srv_ucm_int_cnf_indication(srv_gcall_get_ucm_call_type(CSMCC_VOICE_CALL), 
        SRV_UCM_INT_QUERY_CNF_IND, &cnf_ind, srv_gcall_cmhdlr_cnf_auto_dtmf);
}


#ifdef __AOC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_call_cost_ind
 * DESCRIPTION
 *  This function is called by the state machine function in
 *  to make call to protocol stack to get call list to sync with MMI
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_call_cost_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_ccm_ind_struct *msg = (mmi_cc_ccm_ind_struct*)info;
    srv_ucm_int_call_cost_ind_struct ind;

    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, msg->call_id);
    /* ccm_ind is ignored if there is no such call */

    U8 currency[4];
    U8 currency2[4 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&ind, 0, sizeof(srv_ucm_int_call_cost_ind_struct));

    /* uid info */
    srv_gcall_set_uid_info(&ind.uid_info, call_info->call_id, call_info->group_id, call_info->call_type);

    /* currency symbol */
    memset(currency, 0, 4 * sizeof(U8));
    memset(currency2, 0, 4 * ENCODING_LENGTH * sizeof(U8));
    memcpy(currency, msg->currency, 3 * sizeof(U8));
    mmi_asc_to_ucs2((CHAR *)currency2, (CHAR *)currency);
    ind.currency_symbol = currency2;

    ind.cost_unit = msg->ccm;

    ind.total_cost_unit = msg->total_ccm;

    ind.price_per_unit = (U32)msg->ppu;

    ind.warning = (MMI_BOOL)msg->warning;

    srv_ucm_int_indication(ind.uid_info.call_type, SRV_UCM_INT_CALL_COST_IND, &ind);
}
#endif /* __AOC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_make_voice_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_ucm_make_voice_call(CHAR *number, U8 module_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dial_act_req_struct dial_req;
    srv_ucm_call_type_enum ucm_call_type = srv_gcall_get_ucm_call_type(CSMCC_VOICE_CALL);
    srv_ucm_hold_and_dial_act_req_struct hold_and_dial_req;
    S32 active_grp_indx[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct active_grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* use ucm service external api */

    /* dial */
    memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));
    dial_req.call_type = ucm_call_type;
#ifdef __IP_NUMBER__
    dial_req.is_ip_dial = MMI_FALSE;
#endif /* __IP_NUMBER__ */
    dial_req.module_id = (srv_ucm_module_origin_enum)module_id;
    mmi_ucs2ncpy((CHAR *)dial_req.num_uri, number, SRV_UCM_MAX_NUM_URI_LEN);

    if (srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, &dial_req) == SRV_UCM_RESULT_OK)
    {
        srv_ucm_act_request(SRV_UCM_DIAL_ACT, &dial_req, NULL, NULL);
        
        return SRV_GCALL_RESULT_OK;
    }

    /* hold and dial */
    if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, active_grp_indx) > 0)
    {
        MMI_ASSERT(srv_ucm_query_group_data(active_grp_indx[0], &active_grp) > 0);
 
        memset(&hold_and_dial_req, 0, sizeof(srv_ucm_hold_and_dial_act_req_struct));
        hold_and_dial_req.active_call_type = active_grp.call_type;
        hold_and_dial_req.active_group = active_grp.group_id;
        hold_and_dial_req.dial_call_type = ucm_call_type;
    #ifdef __IP_NUMBER__
        hold_and_dial_req.is_ip_dial = MMI_FALSE;
    #endif /* __IP_NUMBER__ */
        hold_and_dial_req.module_id = (srv_ucm_module_origin_enum)module_id;
        mmi_asc_n_to_ucs2((CHAR *)hold_and_dial_req.num_uri, number, SRV_UCM_MAX_NUM_URI_LEN);

        if (srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_DIAL_ACT, &hold_and_dial_req) == SRV_UCM_RESULT_OK)
        {
            srv_ucm_act_request(SRV_UCM_HOLD_AND_DIAL_ACT, &hold_and_dial_req, NULL, NULL);

            return SRV_GCALL_RESULT_OK;
        }

    }

    return SRV_GCALL_RESULT_UNSPECIFIED_ERR;

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_replace_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_replace_ind(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_replace_ind_struct ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&ind, 0, sizeof(srv_ucm_int_replace_ind_struct));

    /* old uid info */
    srv_gcall_set_uid_info(&ind.old_uid_info, call_info->call_id, call_info->group_id, call_info->call_type);

    memcpy(&ind.new_uid_info, &ind.old_uid_info, sizeof(srv_ucm_id_info_struct));

    ind.call_origin = srv_gcall_util_get_ucm_origin(call_info->dir);
    
    /*remote info*/
    srv_gcall_derive_display_name(call_info, (PU8)ind.remote_info.disp_name, SRV_UCM_MAX_DISP_NAME_LEN);    
    mmi_ucs2ncpy((CHAR *)ind.remote_info.log_name, (CHAR *)srv_gcall_get_call_log_name(call_info), MMI_PHB_NAME_LENGTH);
    strncpy((CHAR *)ind.remote_info.num_uri, (CHAR *)srv_gcall_get_call_log_number(call_info), SRV_UCM_MAX_NUM_URI_LEN);

    srv_gcall_set_remote_line_icon(call_info, &ind.remote_info);

#ifdef __MMI_UCM_NUMBER_TYPE__
    ind.remote_info.number_type = call_info->number_type;
    ind.remote_info.num_type_icon = srv_gcall_derive_number_type_icon(call_info->number_type);
#endif /* __MMI_UCM_NUMBER_TYPE__ */

    ind.remote_info.phb_id = cm_p->phb_data.phb_id;

    srv_ucm_int_indication(ind.old_uid_info.call_type, SRV_UCM_INT_REPLACE_IND, &ind);
}


#ifdef __CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_ccbs_recall_cnf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_ccbs_recall_cnf_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_cnf_ind_struct cnf_ind;
    U8 temp_str[(SRV_GCALL_MAX_NUMBER + 6) * ENCODING_LENGTH];
    U8 temp_str_2[SRV_GCALL_MAX_NUMBER * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&cnf_ind, 0, sizeof(srv_ucm_int_query_cnf_ind_struct));

    mmi_ucs2cpy((CHAR *)temp_str, (CHAR *)L"Dial ");
    mmi_asc_to_ucs2((CHAR *)temp_str_2, (CHAR *)cm_p->ccbs_info.number);
    mmi_ucs2cat((CHAR *)temp_str, (CHAR *)temp_str_2);
    mmi_ucs2cat((CHAR *)temp_str, (CHAR *)L"?");

    mmi_ucs2ncpy((CHAR *)cnf_ind.content, (CHAR *)temp_str, SRV_UCM_MAX_DISP_MSG_LEN);
    cnf_ind.disp_condition = (srv_ucm_int_disp_condition_enum)0;

    srv_ucm_int_cnf_indication(srv_gcall_get_ucm_call_type(CSMCC_VOICE_CALL), 
        SRV_UCM_INT_QUERY_CNF_IND, &cnf_ind, srv_gcall_cmhdlr_cnf_ccbs_recall);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_ccbs_activation_cnf_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_ccbs_activation_cnf_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_cnf_ind_struct ccbs_activation_conf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&ccbs_activation_conf, 0, sizeof(srv_ucm_int_query_cnf_ind_struct));

    mmi_ucs2ncpy((CHAR *)ccbs_activation_conf.content, (CHAR *)get_string(STR_ID_GCALL_CCBS_NFY), SRV_UCM_MAX_DISP_MSG_LEN);
    ccbs_activation_conf.disp_condition = SRV_UCM_DISP_OUTGOING; /*show confirm popup in outgoing call screen*/

    srv_ucm_int_cnf_indication(srv_gcall_get_ucm_call_type(CSMCC_VOICE_CALL), 
        SRV_UCM_INT_QUERY_CNF_IND, &ccbs_activation_conf, srv_gcall_cmhdlr_cnf_ccbs_activate);
}
#endif /* __CCBS_SUPPORT__ */


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_ucm_start_count_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_ucm_start_count_ind(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ucm_int_indication(
        srv_gcall_get_ucm_call_type(call_info->call_type), 
        SRV_UCM_INT_START_COUNT_IND, NULL);
}
#endif /* __MMI_VIDEO_TELEPHONY__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_sat_notify_mo_number_change
 * DESCRIPTION
 *  This function displays number change notification
 * PARAMETERS
 *  newNumber               [IN]        
 *  ptrDisplayString        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_sat_notify_mo_number_change(U8 *number, U8 *disp_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    srv_gcall_call_info_struct *call_info;
    mmi_sim_enum sim_id[] = {MMI_SIM1, MMI_SIM2, MMI_SIM3, MMI_SIM4};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
        srv_gcall_cntxt_set_ptr(sim_id[index]);
        call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);
        if (!call_info)
        {
            srv_gcall_cntxt_reset_ptr();
        }
        else
        {
            break;
        }
    }

    if (!call_info)
    {
        /* no outgoing call, ignore */
        return;
    }

    if (disp_str && mmi_ucs2strlen((CHAR *)disp_str))
    {
        /* Case1: alpha_id is present and not empty, display alpha_id */
        mmi_ucs2_n_to_asc((CHAR *)(call_info->num2), (CHAR *)number, (SRV_GCALL_MAX_NUMBER - 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy((CHAR *)call_info->name, (CHAR *)disp_str, SRV_GCALL_MAX_NAME - 1);
        srv_gcall_ucm_notify_ind(call_info->call_type, disp_str, 0, 0);
        srv_gcall_ucm_replace_ind(call_info);

        /* don't update display name after connect_ind */
        call_info->dir = SRV_GCALL_DIR_MO_STK;
    }
    else if (disp_str && !mmi_ucs2strlen((CHAR *)disp_str))
    {
        /* Case2: alpha_id is present but empty, don't modify the display name */

        if (!mmi_ucs2strlen((CHAR *)call_info->name))
        {
            /* if there is no name, use original number as the name in case the number is changed in connect_ind */
            /* hide *31#, #31# prefix string  */
            if ((strncmp((CHAR *)call_info->num, "*31#", 4) == 0) ||
                (strncmp((CHAR *)call_info->num, "#31#", 4) == 0))
            {
                mmi_asc_n_to_ucs2((CHAR *)call_info->name, (CHAR *)&(call_info->num[4]), (U32)SRV_GCALL_MAX_NAME);
            }
            else
            {
                mmi_asc_n_to_ucs2((CHAR *)call_info->name, (CHAR *)call_info->num, (U32)SRV_GCALL_MAX_NAME);
            }
        }

        /* don't update display name after connect_ind */
        call_info->dir = SRV_GCALL_DIR_MO_STK;
    }
    /* Case3: alpha_id is not present, ignore all call control by sim attributes, take as normal MO call  */

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_sat_notify_mo_fail
 * DESCRIPTION
 *  Removes outgoing call screen
 * PARAMETERS
 *  void
 *  Number(?)       [IN]        To show on screen
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_sat_notify_mo_fail(U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    srv_gcall_call_info_struct *call_info;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        srv_gcall_cntxt_set_ptr(sim_id);
        call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);
        if (!call_info)
        {
            srv_gcall_cntxt_reset_ptr();
        }
        else
        {
            break;
        }
    }

    if (!call_info)
    {
        /* no outgoing call, ignore */
        return;
    }

    srv_gcall_phdlr_set_release_call_info(call_info, cause);
    
    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_OUTGOING, call_info);
    srv_gcall_cntxt_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_post_act_evt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  result
 *****************************************************************************/
MMI_BOOL srv_gcall_post_act_evt(srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum act_op, void *ptr, void *user_data, srv_ucm_int_act_rsp_callback_func_ptr rsp_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_act_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&evt, 0, sizeof(srv_gcall_act_evt_struct));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_GCALL_ACT);
    evt.call_type = call_type;
    evt.act_op = act_op;
    evt.ptr = srv_gcall_post_copy_act_data(act_op, ptr);
    evt.int_user_data = user_data;
    evt.rsp_callback = rsp_callback;
    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_post_cnf_evt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  result
 *****************************************************************************/
MMI_BOOL srv_gcall_post_cnf_evt(srv_ucm_call_type_enum call_type, srv_ucm_int_cnf_opcode_enum cnf_type, void *ptr, srv_ucm_int_cnf_callback_func_ptr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_cnf_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&evt, 0, sizeof(srv_gcall_cnf_evt_struct));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_GCALL_CNF);
    evt.cb = cb;
    evt.call_type = call_type;
    evt.cnf_type = cnf_type;
    evt.ptr = srv_gcall_post_copy_cnf_data(cnf_type, ptr);
    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_post_copy_act_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  data pointer
 *****************************************************************************/
void* srv_gcall_post_copy_act_data(srv_ucm_int_act_opcode_enum act_op, void *from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *to = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!from)
    {
        return NULL;
    }

    switch (act_op)
    {
        case SRV_UCM_INT_DIAL_ACT:
            to = OslMalloc(sizeof(srv_ucm_int_dial_act_req_struct));
            memcpy(to, from, sizeof(srv_ucm_int_dial_act_req_struct));
            break;

        case SRV_UCM_INT_ACCEPT_ACT:
        case SRV_UCM_INT_SPLIT_ACT:
        case SRV_UCM_INT_END_SINGLE_ACT:
        case SRV_UCM_INT_FORCE_RELEASE_ACT:
        case SRV_UCM_INT_AUTO_REJECT_ACT:
            to = OslMalloc(sizeof(srv_ucm_int_single_call_act_req_struct));
            memcpy(to, from, sizeof(srv_ucm_int_single_call_act_req_struct));
            break;

        case SRV_UCM_INT_HOLD_ACT:
        case SRV_UCM_INT_RETRIEVE_ACT:
        case SRV_UCM_INT_SWAP_ACT:
        case SRV_UCM_INT_END_CONFERENCE_ACT:
            to = OslMalloc(sizeof(srv_ucm_int_single_group_act_req_struct));
            memcpy(to, from, sizeof(srv_ucm_int_single_group_act_req_struct));
            break;

        case SRV_UCM_INT_CONFERENCE_ACT:
            to = OslMalloc(sizeof(srv_ucm_int_multiple_group_act_req_struct));
            memcpy(to, from, sizeof(srv_ucm_int_multiple_group_act_req_struct));
            break;

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_INT_DEFLECT_ACT:
            to = OslMalloc(sizeof(srv_ucm_int_cd_or_ct_act_req_struct));
            memcpy(to, from, sizeof(srv_ucm_int_cd_or_ct_act_req_struct));            
            break;
    #endif /* __MMI_UCM_DEFLECT__ */

        case SRV_UCM_INT_END_ALL_ACT:
            to = OslMalloc(sizeof(srv_ucm_int_end_all_act_req_struct));
            memcpy(to, from, sizeof(srv_ucm_int_end_all_act_req_struct));              
            break;

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT:
            to = OslMalloc(sizeof(srv_ucm_int_ect_act_req_struct));
            memcpy(to, from, sizeof(srv_ucm_int_ect_act_req_struct));    
            break;
    #endif /* __MMI_UCM_ECT__ */

        case SRV_UCM_INT_START_DTMF_ACT:
            to = OslMalloc(sizeof(srv_ucm_dtmf_struct));
            memcpy(to, from, sizeof(srv_ucm_dtmf_struct)); 
            break;

        default:
             break;
    }

    MMI_ASSERT(to); /* get buffer fails or op is not supported */
    
    return to;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_post_copy_cnf_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  data pointer
 *****************************************************************************/
void* srv_gcall_post_copy_cnf_data(srv_ucm_int_cnf_opcode_enum cnf_type, void *from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *to = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!from)
    {
        return NULL;
    }

    switch (cnf_type)
    {
        case SRV_UCM_INT_QUERY_CNF:
            to = OslMalloc(sizeof(srv_ucm_int_query_cnf_struct));
            memcpy(to, from, sizeof(srv_ucm_int_query_cnf_struct));
            break;

        case SRV_UCM_INT_DIAL_CNF:
            to = OslMalloc(sizeof(srv_ucm_int_dial_cnf_struct));
            memcpy(to, from, sizeof(srv_ucm_int_dial_cnf_struct));
            break;

        case SRV_UCM_INT_CALL_PRESENT_CNF:
            to = OslMalloc(sizeof(srv_ucm_int_call_present_cnf_struct));
            memcpy(to, from, sizeof(srv_ucm_int_call_present_cnf_struct));
            break;

        default:
             break;
    }

    MMI_ASSERT(to); /* get buffer fails or op is not supported */
    
    return to;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_post_act_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_gcall_post_act_evt_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_act_evt_struct *info = (srv_gcall_act_evt_struct*)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    srv_gcall_cmhdlr_act_req(info->call_type, info->act_op, 
        info->ptr, info->int_user_data, info->rsp_callback);

    if (info->ptr)
    {
        OslMfree(info->ptr);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_post_cnf_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_gcall_post_cnf_evt_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_gcall_cnf_evt_struct *info = (srv_gcall_cnf_evt_struct*)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    (*(info->cb))(info->call_type, info->cnf_type, 
        info->ptr);

    OslMfree(info->ptr);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_interface_with_ucm_call_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type   [IN]    ucm call type
 * RETURNS
 *  sim interface
 *****************************************************************************/
mmi_sim_enum srv_gcall_get_interface_with_ucm_call_type(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (call_type)
    {
        case SRV_UCM_VOICE_CALL_TYPE:
        case SRV_UCM_DATA_CALL_TYPE:
        case SRV_UCM_CSD_CALL_TYPE:
        case SRV_UCM_VIDEO_CALL_TYPE:
            return MMI_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case SRV_UCM_VOICE_CALL_TYPE_SIM2:
        case SRV_UCM_DATA_CALL_TYPE_SIM2:
        case SRV_UCM_CSD_CALL_TYPE_SIM2:
        case SRV_UCM_VIDEO_CALL_TYPE_SIM2:
            return MMI_SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_UCM_VOICE_CALL_TYPE_SIM3:
        case SRV_UCM_DATA_CALL_TYPE_SIM3:
        case SRV_UCM_CSD_CALL_TYPE_SIM3:
            return MMI_SIM3;
    #if (MMI_MAX_SIM_NUM == 4)
        case SRV_UCM_VOICE_CALL_TYPE_SIM4:
        case SRV_UCM_DATA_CALL_TYPE_SIM4:
        case SRV_UCM_CSD_CALL_TYPE_SIM4:
            return MMI_SIM4;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_GET_INTERFACE_WITH_UCM_CALL_TYPE_NOT_SUPPORT, call_type);
            return MMI_SIM_NONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_ucm_call_list
 * DESCRIPTION
 *  Gets GSM call list for UCM
 * PARAMETERS
 *        
 * RETURNS
 * 
 *****************************************************************************/
void srv_gcall_get_ucm_call_list(srv_ucm_int_call_list_struct *call_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    srv_gcall_call_info_struct *from;
    srv_ucm_int_call_list_entry_info_struct *to;
#ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
    PU8 no_cli_msg;
    U16 length;
#endif /* __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(call_list, 0, sizeof(srv_ucm_int_call_list_struct));

    /* call type */
    switch (cm_p->interface)
    {
        case MMI_SIM1:
            call_list->call_type = (srv_ucm_call_type_enum)SRV_UCM_SIM1_CALL_TYPE_ALL;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            call_list->call_type = (srv_ucm_call_type_enum)SRV_UCM_SIM2_CALL_TYPE_ALL;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            call_list->call_type = (srv_ucm_call_type_enum)SRV_UCM_SIM3_CALL_TYPE_ALL;
            break;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            call_list->call_type = (srv_ucm_call_type_enum)SRV_UCM_SIM4_CALL_TYPE_ALL;
            break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            break;
    }
    
    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        from = &(cm_p->call_list[count]);
        to = &(call_list->call_info[call_list->total_num]);

        if (from->call_id == SRV_GCALL_INVALID_ID)
        {
            /* ignore unused call info */
            continue;
        }

        if ((cm_p->ucm_info.bg_op == SRV_UCM_INT_AUTO_REJECT_ACT)
                && (cm_p->auto_reject_call_id == from->call_id))
        {
            /* UCM has already auto rejected the call, so don't let her know. */
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_GET_UCM_CALL_LIST_IGNORE, from->call_id);
            continue;
        }

        /* REMOTE INFO */
        strncpy((CHAR *)to->remote_info.num_uri, (CHAR *)from->num, SRV_UCM_MAX_NUM_URI_LEN);

        srv_gcall_derive_display_name(from, (PU8)to->remote_info.disp_name, SRV_UCM_MAX_DISP_NAME_LEN);
        
        mmi_ucs2ncpy((CHAR *)to->remote_info.log_name,
                    (CHAR *)srv_gcall_get_call_log_name(from),
                    MMI_PHB_NAME_LENGTH);
        
        srv_gcall_set_remote_line_icon(from, &to->remote_info);

    #ifdef __MMI_UCM_NUMBER_TYPE__
        to->remote_info.number_type = from->number_type;
        to->remote_info.num_type_icon = srv_gcall_derive_number_type_icon(from->number_type);
    #endif /* __MMI_UCM_NUMBER_TYPE__ */

        to->remote_info.phb_id = cm_p->phb_data.phb_id;

    #ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
        length = (SRV_UCM_MAX_DISP_NAME_LEN - mmi_ucs2strlen((CHAR *)to->remote_info.disp_name)) * ENCODING_LENGTH;

        if ((from->curr_state == SRV_GCALL_STATE_INCOMING)
            && (cm_p->mt.no_cli_cuase != CSMCC_INVALID_NO_CLI_CAUSE))
        {
            no_cli_msg = OslMalloc(length);
            memset(no_cli_msg, 0, length);
            srv_gcall_util_get_no_cli_display_text(cm_p->mt.no_cli_cuase, no_cli_msg);
            mmi_ucs2cat((CHAR *)to->remote_info.disp_name, GetString(STR_ID_GCALL_LEFT_PARENTHESIS));
            mmi_ucs2ncat((CHAR *)to->remote_info.disp_name, (CHAR *)no_cli_msg, mmi_ucs2strlen((CHAR *)no_cli_msg));
            mmi_ucs2cat((CHAR *)to->remote_info.disp_name, GetString(STR_ID_GCALL_RIGHT_PARENTHESIS));
            OslMfree(no_cli_msg);
        }
    #endif /* __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__ */

        /*UID info*/
        srv_gcall_set_uid_info(&to->uid_info, from->call_id, from->group_id, from->call_type);
        
        /*STATE info*/
        to->call_state = srv_gcall_util_get_ucm_call_state(from->curr_state);
        
        /*print info*/
        if (from->call_id != SRV_GCALL_INVALID_ID)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_GET_UCM_CALL_LIST_INFO,
            call_list->total_num, 
            to->uid_info.group_id,
            to->uid_info.call_id,
            to->uid_info.call_type,
            to->call_state);
        }
        
        call_list->total_num++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_ucm_call_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_call_type_enum srv_gcall_get_ucm_call_type(srv_gcall_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cm_p->interface == MMI_SIM1)
    {
        switch (call_type)
        {
            case CSMCC_VOICE_CALL:
            case CSMCC_AUX_VOICE_CALL:
                return SRV_UCM_VOICE_CALL_TYPE;
                 
            case CSMCC_DATA_CALL:
            case CSMCC_FAX_CALL:
            case CSMCC_SAT_DATA_CALL:            
                return SRV_UCM_DATA_CALL_TYPE;

            case CSMCC_CSD_CALL:
                return SRV_UCM_CSD_CALL_TYPE;
            
            case CSMCC_VIDEO_CALL:
                return SRV_UCM_VIDEO_CALL_TYPE;
                 
            default:
                break;
        }
    }
#if (MMI_MAX_SIM_NUM >= 2)    
    else if (cm_p->interface == MMI_SIM2)
    {
        switch (call_type)
        {
            case CSMCC_VOICE_CALL:
            case CSMCC_AUX_VOICE_CALL:
                return SRV_UCM_VOICE_CALL_TYPE_SIM2;
                 
            case CSMCC_DATA_CALL:
            case CSMCC_FAX_CALL:
            case CSMCC_SAT_DATA_CALL:            
                return SRV_UCM_DATA_CALL_TYPE_SIM2;

            case CSMCC_CSD_CALL:
                return SRV_UCM_CSD_CALL_TYPE_SIM2;

            case CSMCC_VIDEO_CALL:
                return SRV_UCM_VIDEO_CALL_TYPE_SIM2;
                 
            default: /* doesn't support video call */
                break;
        }
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (cm_p->interface == MMI_SIM3)
    {
        switch (call_type)
        {
            case CSMCC_VOICE_CALL:
            case CSMCC_AUX_VOICE_CALL:
                return SRV_UCM_VOICE_CALL_TYPE_SIM3;
                 
            case CSMCC_DATA_CALL:
            case CSMCC_FAX_CALL:
            case CSMCC_SAT_DATA_CALL:            
                return SRV_UCM_DATA_CALL_TYPE_SIM3;

            case CSMCC_CSD_CALL:
                return SRV_UCM_CSD_CALL_TYPE_SIM3;
                 
            default: /* doesn't support video call */
                break;
        }
    }
#if (MMI_MAX_SIM_NUM == 4)    
    else if (cm_p->interface == MMI_SIM4)
    {
        switch (call_type)
        {
            case CSMCC_VOICE_CALL:
            case CSMCC_AUX_VOICE_CALL:
                return SRV_UCM_VOICE_CALL_TYPE_SIM4;
                 
            case CSMCC_DATA_CALL:
            case CSMCC_FAX_CALL:
            case CSMCC_SAT_DATA_CALL:            
                return SRV_UCM_DATA_CALL_TYPE_SIM4;

            case CSMCC_CSD_CALL:
                return SRV_UCM_CSD_CALL_TYPE_SIM4;
                 
            default: /* doesn't support video call */
                break;
        }
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    MMI_ASSERT(0);

    return SRV_UCM_CALL_TYPE_END_OF_ENUM;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_set_remote_line_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_set_remote_line_icon(srv_gcall_call_info_struct *from, srv_ucm_remote_info_struct *remote_info)
{
    remote_info->line_icon = 0;
    if (!srv_gcall_util_is_reset_csp_group_service(cm_p->interface, SRV_CPHS_GROUP_CPHS_TELESERVICES, SRV_CPHS_SERVICE_ALS))
    {
    #if defined(__COSMOS_MMI_PACKAGE__) || !defined(__MMI_UCM_SLIM__)
        if (from->call_type == CSMCC_AUX_VOICE_CALL)
        {
            remote_info->line_icon = IMG_ID_GCALL_LINE2;
        }
        else if (from->call_type == CSMCC_VOICE_CALL)
        {
            remote_info->line_icon = IMG_ID_GCALL_LINE1;
        }
    #endif /*defined(__COSMOS_MMI_PACKAGE__) || !defined(__MMI_UCM_SLIM__) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_set_uid_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_set_uid_info(srv_ucm_id_info_struct *uid_info, U8 call_id, U8 group_id, srv_gcall_type_enum call_type)
{
    uid_info->call_id = call_id;
    uid_info->group_id = group_id;
    uid_info->call_type = srv_gcall_get_ucm_call_type(call_type);
}

