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
 *   GCallSrvStructMgmt.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  GSM / 3G call service
 *  Context management
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

#include "ProtocolEvents.h"

#include "GSM7BitDefaultAlphabet.h"

#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"
#include "ProfilesSrvGprot.h" /* srv_prof_get_current_profile_value */
#include "mmi_rp_srv_prof_def.h" /* AUD_ID_PROF_RING1 */
#include "SatSrvGprot.h"
#include "SmsSrvGprot.h" /* srv_sms_get_mailbox_name */
#include "CphsSrvGprot.h"

#include "Mncc_enums.h" /* cc_presentation_ind_enum */


#include "NwInfoSrvGprot.h" /* srv_nw_info_get_service_availability */
#include "Custom_ecc.h" /* ecc_call_type_enum */

#include "UcmSrvGprot.h"
#include "..\UcmSrv\UCMSrvIntProt.h"

#include "GCallSrvProt.h"

#include "MMI_features.h"
#include "GCallSrvDef.h"
#include "string.h"
#include "csmcc_common_enums.h"
#include "kal_non_specific_general_types.h"
#include "MMIDataType.h"
#include "stack_msgs.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "l3_inc_enums.h"
#include "l4c2abm_struct.h"
#include "mmi_rp_srv_phb_def.h"
#include "custom_phb_config.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_gcall_def.h"
#include "sim_common_enums.h" /* sim_interface_enum */
#include "custom_srv_prof_defs.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "mmi_frm_utility_gprot.h"

static srv_gcall_cntxt_struct g_gcall_cntxt;
#if (MMI_MAX_SIM_NUM >= 2)
static srv_gcall_cntxt_struct g_gcall_2_cntxt;
#if (MMI_MAX_SIM_NUM >= 3)
static srv_gcall_cntxt_struct g_gcall_3_cntxt;
#if (MMI_MAX_SIM_NUM == 4)
static srv_gcall_cntxt_struct g_gcall_4_cntxt;
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
srv_gcall_cntxt_struct *cm_p;


/*****************************************************************************
 * FUNCTION
 *    gcall_srv_init
 * DESCRIPTION
 *  Initialize GSM3G call service 
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        srv_gcall_cntxt_set_ptr(sim_id);
        srv_gcall_init_cntxt(sim_id);
        srv_gcall_init_phdlr();
        srv_gcall_init_cmhdlr();
        srv_gcall_cntxt_reset_ptr();
    }
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_init_cntxt
 * DESCRIPTION
 *  Initialize context for GSM3G call service 
 * PARAMETERS
 *  interface   [IN]    sim interface 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_init_cntxt(mmi_sim_enum interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset (cm_p, 0, sizeof(srv_gcall_cntxt_struct));
    cm_p->interface = interface;
    cm_p->ps_info.chld_type = CSMCC_INVALID_CRSS_TYPE;
    cm_p->nw_available = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_init_phdlr
 * DESCRIPTION
 *  Initialize protocol event handlers for GSM3G call service
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_init_phdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* incoming call */
#ifdef __AUTO_CALL_REJECTION__
    srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_MT_PRESENT_INIT, NULL);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_call_present_ind, MSG_ID_MMI_CC_CALL_PRESENT_IND);
#endif /* __AUTO_CALL_REJECTION__ */
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_call_ring_ind, PRT_INCOMINGCALL_EVENT);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_call_wait_ind, PRT_INCOMING_CALL_WAIT);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_data_call_req_ind, MSG_ID_MMI_DATA_CALL_REQ_IND);

    /* outgoing call */
#ifdef __CPI_SUPPORT__
    srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_CPI_INIT, NULL);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_cpi_ind, MSG_ID_MMI_CC_CPI_IND);
#endif /* __CPI_SUPPORT__ */
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_make_call_req_ind, PRT_MMI_MAKE_CALL_REQ_IND);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_dial_ind, MSG_ID_MMI_CC_DIAL_IND);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_internal_alert_ind, PRT_PLAY_GSM_TONE);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_call_connect_ind, PRT_OUTGOINGCALL_CONNECTED);

    /* general */
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_speech_ind, PRT_SPEECH_IND_EVENT);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_call_disconnect_ind, MSG_ID_MMI_CC_CALL_DISCONNECT_IND);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_call_release_ind, MSG_ID_MMI_CC_CALL_RELEASE_IND);
#ifdef __AOC_SUPPORT__
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_ccm_ind, PRT_AOC_EVENT_IND);
#endif /* __AOC_SUPPORT__ */
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_notify_ss_ind, PRT_NOTIFY_SS_EVENT);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_start_auto_dtmf_ind, PRT_DTMF_CONFIRM_IND);
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_call_sync_req_ind, PRT_MSG_ID_MMI_CC_SYNC_TABLE_REQ_IND);
#if (MMI_MAX_SIM_NUM >= 2)
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_nw_mmrr_service_status_ind, MSG_ID_MMI_NW_MMRR_SERVICE_STATUS_IND);
#endif /* (MMI_MAX_SIM_NUM == 2) */
#ifdef __MMI_CM_CNAP_SUPPORT__
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_notify_ss_cnap_ind, PRT_NOTIFY_SS_CNAP_EVENT);
#endif /* __MMI_CM_CNAP_SUPPORT__ */
#ifdef __CCBS_SUPPORT__
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_notify_ss_ccbs_ind, PRT_CCBS_NOTIFY_IND);
#endif  /* __CCBS_SUPPORT__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_start_counter_ind, MSG_ID_MMI_VT_START_COUNTER_IND);
#endif /* __MMI_VIDEO_TELEPHONY__ */
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_init_cmhdlr
 * DESCRIPTION
 *  Initialize GSM3G call service 
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_init_cmhdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    srv_gcall_type_enum type[] = {  CSMCC_VOICE_CALL, /* CSMCC_AUX_VOICE_CALL */
                                    CSMCC_DATA_CALL, /* CSMCC_FAX_CALL, CSMCC_SAT_DATA_CALL */
                                    CSMCC_CSD_CALL,
                                    CSMCC_VIDEO_CALL,
                                    CSMCC_INVALID_CALL_TYPE
                                    };
    srv_ucm_call_type_enum ucm_call_type = (srv_ucm_call_type_enum)0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* UCM srv registration */

    for (i = 0; type[i] != CSMCC_INVALID_CALL_TYPE; i++)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        if ((type[i] == CSMCC_VIDEO_CALL) && 
            ((cm_p->interface == MMI_SIM3) ||
            (cm_p->interface == MMI_SIM4)))
        {
            continue;
        }
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        ucm_call_type = srv_gcall_get_ucm_call_type(type[i]);

        /* action */
        if (!srv_ucm_int_register_call_srv_act_callback(ucm_call_type, srv_gcall_cmhdlr_act_req))
        {
            MMI_ASSERT(0);
        }

        /* query */
        if (!srv_ucm_int_register_call_srv_query_callback(ucm_call_type, srv_gcall_cmhdlr_query))
        {
            MMI_ASSERT(0);
        }

    }

    /* permit */
    if (cm_p->interface == MMI_SIM1)
    {
        ucm_call_type = (srv_ucm_call_type_enum)SRV_UCM_SIM1_CALL_TYPE_ALL;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (cm_p->interface == MMI_SIM2)
    {
        ucm_call_type = (srv_ucm_call_type_enum)SRV_UCM_SIM2_CALL_TYPE_ALL;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (cm_p->interface == MMI_SIM3)
    {
        ucm_call_type = (srv_ucm_call_type_enum)SRV_UCM_SIM3_CALL_TYPE_ALL;
    }
#if (MMI_MAX_SIM_NUM == 4)
    else if (cm_p->interface == MMI_SIM4)
    {
        ucm_call_type = (srv_ucm_call_type_enum)SRV_UCM_SIM4_CALL_TYPE_ALL;
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    else
    {
        MMI_ASSERT(0);
    }

    if (!srv_ucm_int_register_call_srv_permit_callback(ucm_call_type, srv_gcall_cmhdlr_prmt))
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cntxt_set_ptr
 * DESCRIPTION
 *   
 * PARAMETERS
 *  interface      [IN]    sim interface
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_cntxt_set_ptr(mmi_sim_enum interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cm_p)
    {
        MMI_ASSERT(0);
    }

    /* lock cm_p */

    switch (interface)
    {
        case MMI_SIM1:
            cm_p = &g_gcall_cntxt;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            cm_p = &g_gcall_2_cntxt;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            cm_p = &g_gcall_3_cntxt;
            break;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            cm_p = &g_gcall_4_cntxt;
            break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            break;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CNTXT_SET_PTR, interface);
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_cntxt_reset_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void srv_gcall_cntxt_reset_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* unlock cm_p */
    /* Shall reset cntxt ptr after all cntxt related operation is done */

    /* It's recommened to reset cntxt ptr before call UCM srv's callbacks, 
     *     thus UCM srv can call gcall srv directly in their apis / callbacks.
     * However, it's essential to make sure there is NO cntxt related op 
     * after UCM srv callbacks return  */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_CNTXT_RESET_PTR);

    cm_p = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_cntxt_is_locked
 * DESCRIPTION
 *  
 * PARAMETERS
 *   void
 * RETURNS
 *  MMI_TRUE: is locked
 *****************************************************************************/
MMI_BOOL srv_gcall_cntxt_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return cm_p ? MMI_TRUE : MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  result code
 *****************************************************************************/
U16 srv_gcall_prmt(srv_ucm_int_prmt_opcode_enum prmt_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_op_is_busy(prmt_type))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PRMT_BUSY, prmt_type, cm_p->ucm_info.op, cm_p->ucm_info.bg_op);
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    switch (prmt_type)
    {
        case SRV_UCM_INT_DIAL_PRMT:
            result = srv_gcall_prmt_dial(ptr);
            break;
            
        case SRV_UCM_INT_HOLD_AND_DIAL_PRMT:
            result = srv_gcall_prmt_hold_and_dial(ptr);
            break;

        case SRV_UCM_INT_ACCEPT_PRMT:
            result = srv_gcall_prmt_accept(ptr);
            break;

        case SRV_UCM_INT_HOLD_PRMT:
            result = srv_gcall_prmt_hold(ptr);
            break;

        case SRV_UCM_INT_RETRIEVE_PRMT:
            result = srv_gcall_prmt_retrieve(ptr);
            break;

        case SRV_UCM_INT_SWAP_PRMT:
            result = srv_gcall_prmt_swap(ptr);
            break;

        case SRV_UCM_INT_CONFERENCE_PRMT:
            result = srv_gcall_prmt_conf(ptr);
            break;

        case SRV_UCM_INT_SPLIT_PRMT:
            result = srv_gcall_prmt_split(ptr);
            break;

    #ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_INT_DEFLECT_PRMT:
            result = srv_gcall_prmt_deflect(ptr);
            break;            
    #endif /* __MMI_UCM_DEFLECT__ */

        case SRV_UCM_INT_END_SINGLE_PRMT:
            result = srv_gcall_prmt_end_single(ptr);
            break;

        case SRV_UCM_INT_END_CONFERENCE_PRMT:
            result = srv_gcall_prmt_end_conf(ptr);
            break;

        case SRV_UCM_INT_END_ALL_PRMT:
            result = srv_gcall_prmt_end_all();
            break;

        case SRV_UCM_INT_FORCE_RELEASE_PRMT:
            result = srv_gcall_prmt_force_release(ptr);
            break;

        case SRV_UCM_INT_AUTO_REJECT_PRMT:
            result = srv_gcall_prmt_auto_reject(ptr);
            break;

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_PRMT:
            result = srv_gcall_prmt_ect(ptr);
            break;
    #endif /* __MMI_UCM_ECT__ */

        case SRV_UCM_INT_START_DTMF_PRMT:
            result = srv_gcall_prmt_start_dtmf(ptr);
            break;

        case SRV_UCM_INT_STOP_DTMF_PRMT:
            result = srv_gcall_prmt_stop_dtmf();
            break;

        case SRV_UCM_INT_END_ALL_AND_DIAL_PRMT:
            result = srv_gcall_prmt_end_all_and_dial(ptr);
            break;
            
        case SRV_UCM_INT_END_ALL_AND_ACCEPT_PRMT:
            result = srv_gcall_prmt_end_all_and_accept(ptr);
            break;

        case SRV_UCM_INT_END_ALL_ACTIVE_AND_RETRIEVE_PRMT:
            result = srv_gcall_prmt_end_all_active_and_retrieve(ptr);
            break;

        case SRV_UCM_INT_END_ALL_ACTIVE_AND_ACCEPT_PRMT:
            result = srv_gcall_prmt_end_all_active_and_accept(ptr);
            break;

        case SRV_UCM_INT_HOLD_AND_ACCEPT_PRMT:
            result = srv_gcall_prmt_hold_and_accept(ptr);
            break;

    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_INT_VT_FALLTO_VOICE_PRMT:
            result = srv_gcall_prmt_vt_fallto_voice(ptr);
            break;
    #endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */

        default:
            result = SRV_GCALL_RESULT_NOT_SUPPORT;
            break;

    }

    if (result != SRV_GCALL_RESULT_OK)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PRMT_RESULT, prmt_type, result);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_accept(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_gcall_prmt_accept_ext(MMI_FALSE, ptr);
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_accept_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_accept_ext(MMI_BOOL is_compond_op, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *info = (srv_ucm_int_single_call_act_prmt_struct*)ptr;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    if (!is_compond_op
        && srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_ACTIVE, (srv_gcall_type_enum)0))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)(info->action_uid.call_id));

    if (!call_info
        || (call_info->curr_state != SRV_GCALL_STATE_INCOMING)
        || (call_info->status_flag & SRV_GCALL_STATUS_DISCONNECTING))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_dial(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_act_prmt_struct *msg = (srv_ucm_int_dial_act_prmt_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SAT__
    if (msg->module_id == SRV_UCM_MODULE_ORIGIN_SAT)
    {
        if (!srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_OUTGOING, (srv_gcall_type_enum)0)
            && (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_TOTAL, (srv_gcall_type_enum)0) < (SRV_GCALL_MAX_CALL - 1)))
        {
            /* SAT did the dial operation; CSM may do hold_and_dial or end_all_and_dial implicitly */
            return SRV_GCALL_RESULT_OK;
        }
        else
        {
            return SRV_GCALL_RESULT_DISALLOW_MORE_CALL;
        }
    }
#endif /* __SAT__ */

    return srv_gcall_prmt_dial_ext(SRV_UCM_INT_DIAL_PRMT, cm_p->ucm_info.call_type, 
        msg->num_uri, (msg->module_id == SRV_UCM_MODULE_ORIGIN_SAT) ? SRV_GCALL_DIR_MO_STK : SRV_GCALL_DIR_MO);
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_dial_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_dial_ext(srv_ucm_int_prmt_opcode_enum op, srv_ucm_call_type_enum ucm_call_type, PU8 number, srv_gcall_dir_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* doesn't support CSD call dialed from UCM srv */
    if (srv_gcall_util_get_internal_call_type(ucm_call_type) == CSMCC_CSD_CALL)
    {
        return SRV_GCALL_RESULT_NOT_SUPPORT;
    }

    /* check call type available */
    if (!srv_gcall_util_type_available(ucm_call_type, MMI_TRUE))
    {
        /* ecc and normal calls are all disallowed */
        return SRV_GCALL_RESULT_SER_UNAVAILABLE;
    }
    else if ((!srv_gcall_util_is_valid_ecc(cm_p->interface, number, dir)
            && !srv_gcall_util_type_available(cm_p->ucm_info.call_type, MMI_FALSE))
        || (srv_gcall_util_is_valid_ecc(cm_p->interface, number, dir)
            && (ucm_call_type == SRV_UCM_VIDEO_CALL_TYPE || ucm_call_type == SRV_UCM_VIDEO_CALL_TYPE_SIM2))
        )
    {
        /* ecc is not allowed to be a VT call */
        return SRV_GCALL_RESULT_ECC_ONLY;
    }

    /* check call state / count */
    switch (op)
    {
        case SRV_UCM_INT_END_ALL_AND_DIAL_PRMT:
            /* end all and dial doesn't care about the incoming call / outgoign call */
            /* end all and dial doesn't care about active call or max call count */
            break;

        case SRV_UCM_INT_DIAL_PRMT:
            /* dial needs to check incoming / outgoing / active / total call count */
            /* dial: rule 1 + rule 2 */
            /* rule 1 */
            if ((srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_ACTIVE, (srv_gcall_type_enum)0)
                    || (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_TOTAL, (srv_gcall_type_enum)0) >= (SRV_GCALL_MAX_CALL - 1)))
                )
            {
                return SRV_GCALL_RESULT_DISALLOW_MORE_CALL;
            }

        case SRV_UCM_INT_HOLD_AND_DIAL_PRMT:
            /* hold and dial doesn't care about active call or max call count */
            /* ex. 5A1H -> not allowed to hold, thus doesn't care about the max call count */
            /* hold and dial: rule 2 */
            /* rule 2 */
            if ((srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_INCOMING, (srv_gcall_type_enum)0)
                    || srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_OUTGOING, (srv_gcall_type_enum)0))
                )
            {
                return SRV_GCALL_RESULT_DISALLOW_MORE_CALL;
            }
            break;

        default:
            return SRV_GCALL_RESULT_NOT_SUPPORT;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_end_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_end_single(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *req = (srv_ucm_int_single_call_act_prmt_struct*)ptr;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)(req->action_uid.call_id));
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((!call_info)
        || (call_info->call_id == SRV_GCALL_MO_TEMP_ID))
    {
        /* not allow to end the mo call before getting valid id */
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_end_conf
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_end_conf(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_group_act_prmt_struct *req = (srv_ucm_int_single_group_act_prmt_struct*)ptr;
    srv_gcall_call_info_struct *act_call = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_ACTIVE);
    srv_gcall_call_info_struct *held_call = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_HOLD);
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_ACTIVE, (srv_gcall_type_enum)0) < 2)
        && (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_HOLD, (srv_gcall_type_enum)0) < 2))
    {
        /* no conference call */
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    if (((!act_call) || (act_call->group_id != (U8)req->action_group))
        && ((!held_call) || (held_call->group_id != (U8)req->action_group)))
    {
        /* no such call */
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_end_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_end_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_TOTAL, (srv_gcall_type_enum)0))
    {
        return SRV_GCALL_RESULT_OK;
    }
    else
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_end_all_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_end_all_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_ACTIVE, (srv_gcall_type_enum)0))
    {
        return SRV_GCALL_RESULT_OK;
    }
    else
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_auto_reject
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_auto_reject(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *msg = (srv_ucm_int_single_call_act_req_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)(msg->action_uid.call_id));
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allow to auto reject incoming calls and outgoing data calls */
    if (!call_info 
        || ((call_info->curr_state != SRV_GCALL_STATE_INCOMING)
            && !(srv_gcall_util_is_data_csd(call_info->call_type)
                && call_info->curr_state == SRV_GCALL_STATE_OUTGOING)))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_force_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_force_release(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *msg = (srv_ucm_int_single_call_act_prmt_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)(msg->action_uid.call_id));
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* only allow ucm srv to use end_xxx_act + force release */

    if (!call_info 
        || !(call_info->status_flag & SRV_GCALL_STATUS_HANGUP_REQUESTED))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_hold
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_hold(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_group_act_prmt_struct *msg = (srv_ucm_int_single_group_act_prmt_struct*)info;
    srv_gcall_call_info_struct *call_info;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_util_is_reset_csp_group_service(cm_p->interface, SRV_CPHS_GROUP_CALL_COMPLETION, SRV_CPHS_SERVICE_HOLD))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_ACTIVE);

    if (!call_info
        || (call_info->group_id != (U8)msg->action_group)
        || srv_gcall_util_is_valid_ecc(cm_p->interface, call_info->num, call_info->dir)
        || (call_info->call_type == CSMCC_VIDEO_CALL)
        || srv_gcall_util_is_data_csd(call_info->call_type)
        || srv_gcall_is_any_disconnecting(call_info->group_id)
        || srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_HOLD, (srv_gcall_type_enum)0))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_retrieve
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_retrieve(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_gcall_prmt_retrieve_ext(MMI_FALSE, info);
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_retrieve_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_retrieve_ext(MMI_BOOL is_compond_op, void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_group_act_prmt_struct *msg = (srv_ucm_int_single_group_act_prmt_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_HOLD);
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!is_compond_op
        && srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_ACTIVE, (srv_gcall_type_enum)0))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    if (!call_info
        || (call_info->group_id != (U8)msg->action_group)
        || srv_gcall_is_any_disconnecting(call_info->group_id))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_swap
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_swap(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_multiple_group_act_prmt_struct *msg = (srv_ucm_int_multiple_group_act_prmt_struct*)info;
    srv_gcall_call_info_struct *act_call = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_ACTIVE);
    srv_gcall_call_info_struct *held_call = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_HOLD);
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!act_call
        || !held_call
        || (act_call->group_id != (U8)msg->active_group)
        || (held_call->group_id != (U8)msg->other_group)
        || srv_gcall_is_any_disconnecting(act_call->group_id)
        || srv_gcall_is_any_disconnecting(held_call->group_id))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_conf
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_conf(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_multiple_group_act_prmt_struct *msg = (srv_ucm_int_multiple_group_act_prmt_struct*)info;
    srv_gcall_call_info_struct *act_call;
    srv_gcall_call_info_struct *held_call;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_util_is_reset_csp_group_service(cm_p->interface, SRV_CPHS_GROUP_OTHER_SUPP_SERVICES, SRV_CPHS_SERVICE_MPTY))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    act_call = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_ACTIVE);
    held_call = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_HOLD);
    if (!act_call
        || !held_call
        || (act_call->group_id != (U8)msg->active_group)
        || (held_call->group_id != (U8)msg->other_group)
        || srv_gcall_is_any_disconnecting(act_call->group_id)
        || srv_gcall_is_any_disconnecting(held_call->group_id)
        || !(srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_ACTIVE, (srv_gcall_type_enum)0)< SRV_GCALL_MAX_CONF_CALL))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_split
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_split(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *msg = (srv_ucm_int_single_call_act_prmt_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)(msg->action_uid.call_id));
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!call_info
        || (call_info->curr_state != SRV_GCALL_STATE_ACTIVE)
        || (call_info->status_flag & SRV_GCALL_STATUS_DISCONNECTING)
        || (srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_ACTIVE, (srv_gcall_type_enum)0) < 2)
        || srv_gcall_get_call_count(MMI_TRUE, SRV_GCALL_STATE_HOLD, (srv_gcall_type_enum)0))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


#ifdef __MMI_UCM_ECT__
/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_ect
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_ect(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_ect_act_prmt_struct *msg = (srv_ucm_int_ect_act_prmt_struct*)info;
    srv_gcall_call_info_struct *call_1;
    srv_gcall_call_info_struct *call_2;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_util_is_reset_csp_group_service(cm_p->interface, SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CT))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    call_1 = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_GROUP_ID, (U8)(msg->first_group));
    call_2 = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_GROUP_ID, (U8)(msg->second_group));

    /* in our design, not allow incoming call to do ect */

    if (!call_1
        || !call_2
        || (call_1->curr_state == SRV_GCALL_STATE_INCOMING)
        || (call_2->curr_state == SRV_GCALL_STATE_INCOMING)
        || (srv_gcall_get_call_count(MMI_TRUE, call_1->curr_state, (srv_gcall_type_enum)0) > 1)
        || (srv_gcall_get_call_count(MMI_TRUE, call_2->curr_state, (srv_gcall_type_enum)0) > 1)
        || (call_1->status_flag & SRV_GCALL_STATUS_DISCONNECTING)
        || (call_2->status_flag & SRV_GCALL_STATUS_DISCONNECTING))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}
#endif /*__MMI_UCM_ECT__ */


#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_deflect
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_deflect(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_cd_or_ct_act_prmt_struct *msg = (srv_ucm_int_cd_or_ct_act_prmt_struct*)info;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)(msg->action_uid.call_id));
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!call_info 
        || (call_info->curr_state != SRV_GCALL_STATE_INCOMING)
        || (call_info->status_flag & SRV_GCALL_STATUS_DISCONNECTING))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}
#endif /* __MMI_UCM_DEFLECT__ */


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_start_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_start_dtmf(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cm_p->dtmf_started)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    if (!srv_gcall_util_is_valid_dtmf(((srv_ucm_dtmf_struct*)info)->digit))
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return SRV_GCALL_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_stop_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_stop_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cm_p->dtmf_started)
    {
        return SRV_GCALL_RESULT_OK;
    }
    else
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }
   
}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_hold_and_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_hold_and_dial(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_hold_and_dial_act_prmt_struct *msg = (srv_ucm_int_hold_and_dial_act_prmt_struct*)ptr;
    srv_ucm_int_single_group_act_prmt_struct hold_prmt;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&hold_prmt, 0, sizeof(srv_ucm_int_single_group_act_prmt_struct));
    hold_prmt.action_group = msg->active_group;
    memcpy(&(hold_prmt.at_info), &(msg->at_info), sizeof(srv_ucm_int_at_info_struct));

    if (srv_gcall_prmt_hold(&hold_prmt) != SRV_GCALL_RESULT_OK)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return srv_gcall_prmt_dial_ext(SRV_UCM_INT_HOLD_AND_DIAL_PRMT, 
                                    msg->dial_type, 
                                    msg->num_uri, 
                                    (msg->module_id == SRV_UCM_MODULE_ORIGIN_SAT) ? SRV_GCALL_DIR_MO_STK : SRV_GCALL_DIR_MO);

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_hold_and_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_hold_and_accept(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_hold_and_accept_act_prmt_struct *msg = (srv_ucm_int_hold_and_accept_act_prmt_struct*)ptr;
    srv_ucm_int_single_group_act_prmt_struct hold_prmt;
    srv_ucm_int_single_call_act_prmt_struct accept_prmt;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&hold_prmt, 0, sizeof(srv_ucm_int_single_group_act_prmt_struct));
    hold_prmt.action_group = msg->action_group;
    memcpy(&(hold_prmt.at_info), &(msg->at_info), sizeof(srv_ucm_int_at_info_struct));

    if (srv_gcall_prmt_hold(&hold_prmt) != SRV_GCALL_RESULT_OK)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    memset(&accept_prmt, 0, sizeof(srv_ucm_int_single_call_act_prmt_struct));
    memcpy(&(accept_prmt.action_uid), &(msg->mt_call_uid), sizeof(srv_ucm_id_info_struct));
    memcpy(&(accept_prmt.at_info), &(msg->at_info), sizeof(srv_ucm_int_at_info_struct));

    return srv_gcall_prmt_accept_ext(MMI_TRUE, &accept_prmt);

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_end_all_and_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_end_all_and_dial(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_act_prmt_struct *msg = (srv_ucm_int_dial_act_prmt_struct*)ptr;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_prmt_end_all() != SRV_GCALL_RESULT_OK)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return srv_gcall_prmt_dial_ext(SRV_UCM_INT_END_ALL_AND_DIAL_PRMT, 
                                    cm_p->ucm_info.call_type, 
                                    msg->num_uri,
                                    (msg->module_id == SRV_UCM_MODULE_ORIGIN_SAT) ? SRV_GCALL_DIR_MO_STK : SRV_GCALL_DIR_MO);

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_end_all_and_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_end_all_and_accept(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_prmt_end_all() != SRV_GCALL_RESULT_OK)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return srv_gcall_prmt_accept_ext(MMI_TRUE, ptr);

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_end_all_active_and_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_end_all_active_and_accept(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_prmt_end_all_active() != SRV_GCALL_RESULT_OK)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return srv_gcall_prmt_accept_ext(MMI_TRUE, ptr);

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_end_all_active_and_retrieve
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_end_all_active_and_retrieve(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_gcall_prmt_end_all_active() != SRV_GCALL_RESULT_OK)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    return srv_gcall_prmt_retrieve_ext(MMI_TRUE, ptr);

}


#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
/*****************************************************************************
 * FUNCTION
 *    srv_gcall_prmt_vt_fallto_voice
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_prmt_vt_fallto_voice(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *req = (srv_ucm_int_single_call_act_prmt_struct*)ptr;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)(req->action_uid.call_id));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!call_info)
    {
        return SRV_GCALL_RESULT_UNSPECIFIED_ERR;
    }

    if ((call_info->call_type != CSMCC_VIDEO_CALL) ||
        (call_info->curr_state != SRV_GCALL_STATE_INCOMING)
        )
    {
        /* only allow for incoming video call */
        return SRV_GCALL_RESULT_NOT_SUPPORT;
    }

    return SRV_GCALL_RESULT_OK;
}
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_add_new_call_info
 * DESCRIPTION
 *   
 * PARAMETERS
 *  number                  [IN]        number in ascii
 *  currentstate            [IN]        Current state of call wether incoming/outgoing
 *  prevstate               [IN]        Previous state of the call
 *  MOflag                  [IN]        Whether call is coming or outgoing
 *  currentCallHandle       [IN]        Call handle of the call
 *  callType                [IN]        
 *  pBname(?)               [IN]        Name of the caller
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_add_new_call_info( 
        PU8 number,
        srv_gcall_state_enum curr_state,
        srv_gcall_dir_enum dir,
        U8 call_id,
        srv_gcall_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    srv_phb_caller_info_struct phb_data;
    srv_phb_cm_number_struct phb_num;
    CHAR* sat_name;
    U8 ucs2_num[SRV_GCALL_MAX_NUMBER * ENCODING_LENGTH];
    U8 mailbox_name[(SRV_SMS_MAX_PROFILE_NAME_LEN + 1) * ENCODING_LENGTH];
    MMI_BOOL result;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_gcall_get_free_index();

    if (index == SRV_GCALL_INVALID_INDEX)
    {
        MMI_ASSERT(0); /* shall reject mt or mo if too many calls */
    }

    call_info = &(cm_p->call_list[index]);

    memset(&cm_p->phb_data, 0, sizeof(cm_p->phb_data));
    srv_phb_set_invalid_number_id(&(cm_p->phb_data.phb_id));

    memset(call_info, 0, sizeof(srv_gcall_call_info_struct));
    cm_p->phb_data.image_id = IMG_PHB_DEFAULT;

    call_info->call_id = call_id;  
    call_info->curr_state = curr_state;
    call_info->status_flag = 0;
    call_info->dir = dir;
    call_info->call_type = call_type;

    /* group id */
    if (call_id == SRV_GCALL_MO_TEMP_ID)
    {
        call_info->group_id = SRV_GCALL_MO_TEMP_ID;
    }
    else
    {
        call_info->group_id = srv_gcall_get_free_group_id(); 
    }

    /* number, alert_info, name */
    if (number[0] != '\0')
    {
        /* number existed, search phonebook if necessary */

        strncpy((CHAR *)call_info->num, (CHAR *)number, SRV_GCALL_MAX_NUMBER - 1);
        strncpy((CHAR *)call_info->num2, (CHAR *)number, SRV_GCALL_MAX_NUMBER - 1);

    #ifdef __SAT__
        if (dir == SRV_GCALL_DIR_MO_STK)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_ADD_NEW_CALL_INFO_FROM_SAT);

            sat_name = (CHAR *)srv_sat_get_call_display_text(cm_p->interface);
            if (sat_name != NULL)
            {
                /* SAT provides name, doesn't search phb */
                /* SAT name length (no_alpha_id_2) may be longer than SRV_GCALL_MAX_NAME */
                mmi_ucs2ncpy((CHAR *)call_info->name, sat_name, SRV_GCALL_MAX_NAME - 1);

                return;
            }
        #ifdef __MMI_UCM_HIDE_SAT_MO_NUMBER__
            else
            {
                /* if SAT didn't provide name (alpha id 2 is NULL or empty), hide the number */
                memset(call_info->num, 0, sizeof(call_info->num));
                memset(call_info->num2, 0, sizeof(call_info->num2));

                return;
            }
        #endif /* __MMI_UCM_HIDE_SAT_MO_NUMBER__ */

        }
    #endif /* __SAT__ */

        /* Scenarios:
         *     1. Normal MO
         *     2. SAT MO, no SAT name, and not hide MO number
         *     3. MT
         */

        /* search phb */
        memset(&phb_data, 0, sizeof(srv_phb_caller_info_struct));
        memset(&phb_num, 0, sizeof(srv_phb_cm_number_struct));

        phb_num.is_mo_call = ((dir == SRV_GCALL_DIR_MO) || (dir == SRV_GCALL_DIR_MO_STK)) ? MMI_TRUE : MMI_FALSE;

        memset(ucs2_num, 0, SRV_GCALL_MAX_NUMBER * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2((CHAR *)ucs2_num, (CHAR *)number, SRV_GCALL_MAX_NUMBER - 1);
        phb_num.number = (PU16)ucs2_num;
        phb_num.sim_interface = srv_gcall_get_sim_interface(cm_p->interface);
        phb_num.call_type = srv_gcall_util_get_ecc_type(cm_p->interface, dir);
        if (phb_num.call_type == ECC_ALL_CALL)
        {
            MMI_ASSERT(0);
        }

        if (dir == SRV_GCALL_DIR_MO)
        {
            /* for now, SAT MO doesn't use user_data for phb */
            phb_num.user_data = cm_p->redial_info.phb_data;
        }

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
        call_info->phb_res_id.call_type = srv_gcall_get_ucm_call_type(call_type);

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_ADD_NEW_CALL_INFO_PHB,
            phb_data.ringtone_id,
            phb_data.image_id,
            phb_data.video_id,
            phb_data.res_type
        #ifdef __MMI_UCM_NUMBER_TYPE__
            , phb_data.number_type
        #endif /* __MMI_UCM_NUMBER_TYPE__ */
            );

        /* dial from voicemail: must display voicemail name */
        /* NOT dial from voicemail: display voicemail name if phb name is empty */
        /* data/csd and ecc calls don't look up voicemail name */
        if ((dir == SRV_GCALL_DIR_MO)
        #ifdef __IP_NUMBER__
            && !(cm_p->mo.is_ip_dial)
        #endif /* __IP_NUMBER__ */
            && !srv_gcall_util_is_data_csd(call_info->call_type)
            && !srv_gcall_util_is_valid_ecc(cm_p->interface, number, dir)
            && ((cm_p->mo.module_id == SRV_UCM_MODULE_ORIGIN_VOICE_MAIL)
                || (!mmi_ucs2strlen((CHAR *)cm_p->phb_data.name))))
        {
            /* get voicemail name */
            memset(ucs2_num, 0, SRV_GCALL_MAX_NUMBER * ENCODING_LENGTH);
            memset(mailbox_name, 0, SRV_SMS_MAX_PROFILE_NAME_LEN * ENCODING_LENGTH);
            mmi_asc_n_to_ucs2((CHAR *)ucs2_num, (CHAR *)number, SRV_GCALL_MAX_NUMBER);
            result = srv_sms_get_mailbox_name(
                (srv_sms_sim_enum)srv_gcall_get_sms_sim_interface(cm_p->interface), 
                (PU16)ucs2_num, (PU16)mailbox_name);

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_ADD_NEW_CALL_INFO_VOICE_MAIL, cm_p->mo.module_id, result, mmi_ucs2strlen((CHAR *)mailbox_name));

            if (result && mmi_ucs2strlen((CHAR *)mailbox_name))
            {
                mmi_ucs2ncpy((CHAR *)call_info->name,
                    (CHAR *)mailbox_name, (U32)SRV_GCALL_MAX_NAME);
                srv_phb_set_invalid_number_id(&(cm_p->phb_data.phb_id));
            }
        }
    }
    else
    {
        /* no mt number */

        /* display presentation indicator info if exists */
        switch(cm_p->mt.presentation_ind)
        {
            case CC_PRESENTATION_RESTRICTED:
                mmi_ucs2cpy((CHAR *)call_info->name, GetString(STR_ID_GCALL_RESTRICTED));
                break;
            case CC_NUMBER_UNAVAILABLE:
                mmi_ucs2cpy((CHAR *)call_info->name, GetString(STR_ID_GCALL_UNAVAILABLE));
                break;
            default:
                mmi_ucs2cpy((CHAR *)call_info->name, GetString(STR_ID_GCALL_UNKNOWN_CALLER));
                break;
        }
    }

    if (dir == SRV_GCALL_DIR_MT)
    {
        srv_gcall_set_alert_info(call_info);
        
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_ADD_NEW_CALL_INFO_ALERT,
            cm_p->mt.alert_type,
            cm_p->mt.backlight_pattern_id);
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_ADD_NEW_CALL_INFO,
        call_info->call_id,
        call_info->group_id,
        call_info->call_type,
        call_info->dir,
        call_info->curr_state,
        call_info->num[0], call_info->num[1], 
        call_info->num[2], call_info->num[3], 
        call_info->num[4], 
        call_info->name[0], call_info->name[2], 
        call_info->name[4], call_info->name[6], 
        call_info->name[8]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_call_info
 * DESCRIPTION
 *  Gets the call index in the array for a specified index
 * PARAMETERS
 *  use_id      MMI_TRUE is use call_id
 *  call_id     0 if not use call_id (don't care call_id)
 *  state       0 if not use state (don't care state)
 *  Index(?)        [OUT]       
 * RETURNS
 *  U16
 *****************************************************************************/
srv_gcall_call_info_struct *srv_gcall_get_call_info(srv_gcall_call_info_op_enum op, U8 info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (index = 0; index < SRV_GCALL_MAX_CALL; index++)
    {
        call_info = &(cm_p->call_list[index]);

        switch (op)
        {
            case SRV_GCALL_CALL_INFO_BY_CALL_ID:
                if (call_info->call_id == info)
                {
                    return call_info;
                }
                break;
        
            case SRV_GCALL_CALL_INFO_BY_STATE:
                if (((call_info->call_id != SRV_GCALL_INVALID_ID) && ((srv_gcall_state_enum)info == SRV_GCALL_STATE_TOTAL))
                    || (call_info->curr_state == (srv_gcall_state_enum)info))
                {
                    return call_info;
                }
                break;
        
            case SRV_GCALL_CALL_INFO_BY_GROUP_ID:
                if (call_info->group_id == info)
                {
                    return call_info;
                }
                break;
        
            case SRV_GCALL_CALL_INFO_BY_CALL_TYPE:
                if (((srv_gcall_type_enum)info == CSMCC_NO_CALL_TYPE)
                    ||(call_info->call_type == (srv_gcall_type_enum)info))
                {
                    return call_info;
                }
                break;
        
            default:
                break;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_call_count
 * DESCRIPTION
 *  get call count with call current state or call type
 * PARAMETERS
 *  with_state      [IN]    count with state
 *  state           [IN]    0 if not with state
 *  call_type       [IN]    0 if not with call_type
 * RETURNS
 *  call count
 *****************************************************************************/
U8 srv_gcall_get_call_count(MMI_BOOL with_state, srv_gcall_state_enum state, srv_gcall_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < SRV_GCALL_MAX_CALL; i++)
    {
        if ((with_state && (((cm_p->call_list[i].call_id != SRV_GCALL_INVALID_ID) 
                && (state == SRV_GCALL_STATE_TOTAL)) 
                || (cm_p->call_list[i].curr_state == state)))
            || (!with_state && (cm_p->call_list[i].call_type == call_type)))
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_sim_interface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  interface   [IN]    gcall srv sim interface
 * RETURNS
 * sim_interface_enum
 *****************************************************************************/
U8 srv_gcall_get_sim_interface(mmi_sim_enum interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (U8)mmi_frm_sim_to_index(interface);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_sms_sim_interface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  interface   [IN]    gcall srv sim interface
 * RETURNS
 * srv_sms_sim_enum
 *****************************************************************************/
U16 srv_gcall_get_sms_sim_interface(mmi_sim_enum interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (interface)
    {
        case MMI_SIM1:
            return (U16)SRV_SMS_SIM_1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return (U16)SRV_SMS_SIM_2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return (U16)SRV_SMS_SIM_3;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return (U16)SRV_SMS_SIM_4;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            ASSERT(0);
            break;
    }

    return (U16)SRV_SMS_SIM_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_set_alert_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_set_alert_info(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_led_pattern_enum led_pattern = SRV_PROF_LED_NONE;
    srv_prof_alert_type_enum alert_type = SRV_PROF_ALERT_TYPE_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_prof_get_current_profile_value(
            SRV_PROF_SETTINGS_STATUS_LED, &led_pattern) != SRV_PROF_RET_SUCCESS)
    {
        cm_p->mt.backlight_pattern_id = 0; /* default: SRV_PROF_LED_NONE */
    }
    else
    {
        cm_p->mt.backlight_pattern_id = (U16)led_pattern; /* default: SRV_PROF_LED_NONE */
    }

    if (cm_p->mt.alert_type == SRV_PROF_ALERT_TYPE_INVALID)
    {
        /* alert type is not assigned by other source, ex. phonebook */
        /* set alert type in phb caller group has been phased out since 10A */
        if (srv_prof_get_current_profile_value(
                SRV_PROF_SETTINGS_ALERT_TYPE, &alert_type) != SRV_PROF_RET_SUCCESS)
        {
            cm_p->mt.alert_type = SRV_PROF_ALERT_TYPE_INVALID;
        }
        else
        {
            cm_p->mt.alert_type = (U8)alert_type;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_set_l4c_source
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_set_l4c_source(U8 src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->ucm_info.l4c_source = src;
}



/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_free_index
 * DESCRIPTION
 *  This function iterates over the calls strcutre to locate
 *  an index to a location where call info can be stored
 * PARAMETERS
 *  void
 *  Index(?)        [OUT]       To the location where the call can be stored
 * RETURNS
 *  Index
 *****************************************************************************/
U8 srv_gcall_get_free_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* must make change here to retrieve call index from PS */
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        if (cm_p->call_list[count].call_id == SRV_GCALL_INVALID_ID)
        {
            return count;
        }
    }

    return SRV_GCALL_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_free_group_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  0: no free group id
 *****************************************************************************/
U8 srv_gcall_get_free_group_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U8 count = 0;
    U8 group_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (group_id = 1; group_id < (SRV_GCALL_MAX_CALL + 1); group_id++)
    {
        for (index = 0; index < SRV_GCALL_MAX_CALL; index++)
        {
            if (cm_p->call_list[index].group_id != group_id)
            {
                count++;
            }
        }
        if (count == SRV_GCALL_MAX_CALL)
        {
            return group_id;
        }
        count = 0;
    }

    return SRV_GCALL_INVALID_ID;
}


#ifdef __MMI_CM_CNAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_set_cnap_name
 * DESCRIPTION
 *  Sets CNAP number
 * PARAMETERS
 *  call handle        
 *  msg    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_set_cnap_name(U8 call_id, U8 dcs, U8 length, U8 *cnap_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nameLen = 0;
    U8 *tempStr = NULL;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (count = 0; count < SRV_GCALL_MAX_CALL; count++)
    {
        if (cm_p->call_list[count].call_id == call_id)
        {
            memset(cm_p->call_list[count].cnap_name, 0, sizeof(cm_p->call_list[count].cnap_name));
            nameLen = length;

            if (nameLen >= SRV_GCALL_MAX_NAME)
            {
                if (dcs == MMI_UCS2_DCS)
                {
                    nameLen = SRV_GCALL_MAX_NAME - 2;
                }
                else
                {
                    nameLen = SRV_GCALL_MAX_NAME - 1;
                }
            }

            if (dcs == MMI_8BIT_DCS)
            {
                tempStr = CovertStringForPlatform(cnap_name, length, dcs, &nameLen);
            }
            else
            {
                tempStr = OslMalloc(SRV_GCALL_MAX_NAME);
                memset(tempStr, 0, (SRV_GCALL_MAX_NAME));
                cnap_name[nameLen] = 0; /*InputboxConvertGSMToDeviceEncoding requirement*/
                cnap_name[nameLen+1] = 0;
                InputboxConvertGSMToDeviceEncoding(cnap_name, tempStr, (U8)nameLen, (S32)SRV_GCALL_MAX_NAME, (S32)dcs, 0, 1);
            }
            if (tempStr != NULL)
            {
                mmi_ucs2ncpy((CHAR *) cm_p->call_list[count].cnap_name, (CHAR *) tempStr, SRV_GCALL_MAX_NAME - 1);
                OslMfree(tempStr);
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_SET_CNAP_NAME_SET);

            return;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_SET_CNAP_NAME_NO_MATCH);
}
#endif /* __MMI_CM_CNAP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_derive_display_name
 * DESCRIPTION
 *  Function gets the name or number of incoming call
 * PARAMETERS
 *  handle          [IN]        
 *  Pointer(?)      [OUT]       To buffer containing name or number
 * RETURNS
 *  PS8
 *****************************************************************************/
void srv_gcall_derive_display_name(srv_gcall_call_info_struct *call_info, PU8 out_str, U16 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    /* no number, display cnap name instead of Unknown Caller */   
#ifdef __MMI_CM_CNAP_SUPPORT__
    if((strlen((CHAR *)call_info->num) == 0) && 
       (mmi_ucs2strlen((CHAR *)call_info->cnap_name) != 0))
    {
        mmi_ucs2ncpy((CHAR *)out_str, (CHAR *)call_info->cnap_name, (U32)max_len);
        return;
    }
#endif /* __MMI_CM_CNAP_SUPPORT__ */

    /* no ip number, dial from voice mail: voice mail name > SAT/PHB/Log name > CNAP name > number (hide *31#, #31# prefix) */
    /* no ip number, NOT dial from voice mail: SAT/PHB/Log name > voice mail name > CNAP name > number (hide *31#, #31# prefix) */
    /* with IP number: CNAP name > IP number, don't use phb name */
    if ((mmi_ucs2strlen((CHAR *)call_info->name) != 0)
        #ifdef __IP_NUMBER__
        && !((call_info->curr_state == SRV_GCALL_STATE_OUTGOING) && (cm_p->mo.is_ip_dial))
        #endif /* __IP_NUMBER__ */
        )
    {
        mmi_ucs2ncpy((CHAR *)out_str, (CHAR *)call_info->name, (U32)max_len);
        return;
    }
#ifdef __MMI_CM_CNAP_SUPPORT__
    else if (mmi_ucs2strlen((CHAR *)call_info->cnap_name) != 0)
    {
        mmi_ucs2ncpy((CHAR *)out_str, (CHAR *)call_info->cnap_name, (U32)max_len);
        return;
    }
#endif /* __MMI_CM_CNAP_SUPPORT__ */
    else
    {
        /* no name, show number (use modified number) */
        /* hide *31#, #31# prefix string  */
        if ((strncmp((CHAR *)call_info->num2, "*31#", 4) == 0) ||
            (strncmp((CHAR *)call_info->num2, "#31#", 4) == 0))
        {
            mmi_asc_n_to_ucs2((CHAR *)out_str, (CHAR *)&(call_info->num2[4]), (U32)max_len);
            return;
        }
        else
        {
            mmi_asc_n_to_ucs2((CHAR *)out_str, (CHAR *)call_info->num2, (U32)max_len);
            return;
        }
    }
}


#ifdef __MMI_UCM_NUMBER_TYPE__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_derive_number_type_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_gcall_derive_number_type_icon(mmi_phb_num_type_enum number_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(number_type)
    {
        case MMI_PHB_NUM_TYPE_MOBILE:
            return IMG_ID_GCALL_NUMBER_MOBILE;

        case MMI_PHB_NUM_TYPE_HOME:
            return IMG_ID_GCALL_NUMBER_HOME;

        case MMI_PHB_NUM_TYPE_OFFICE:
            return IMG_ID_GCALL_NUMBER_OFFICE;

        case MMI_PHB_NUM_TYPE_FAX:
            return IMG_ID_GCALL_NUMBER_FAX;

        default:
            return 0;
    }
}
#endif /* __MMI_UCM_NUMBER_TYPE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_call_log_name
 * DESCRIPTION
 *  Returns number for outgoing call
 * PARAMETERS
 *  handle          [IN]        
 *  Cause(?)        [OUT]       Value
 * RETURNS
 *  void
 *****************************************************************************/
PU8 srv_gcall_get_call_log_name(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    return call_info->name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_call_log_number
 * DESCRIPTION
 *  Returns number for outgoing call
 * PARAMETERS
 *  handle          [IN]        
 *  Cause(?)        [OUT]       Value
 * RETURNS
 *  void
 *****************************************************************************/
PU8 srv_gcall_get_call_log_number(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

    /* use the original number */
    return call_info->num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_caller_res_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN/OUT] caller resource info
 * RETURNS
 *  MMI_FALSE if fails
 *****************************************************************************/
MMI_BOOL srv_gcall_get_caller_res_info(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_caller_res_struct *ucm_res_info = (srv_ucm_int_query_caller_res_struct*)info;
    srv_gcall_call_info_struct *call_info;
    srv_phb_caller_res_id_struct res_id;
    srv_phb_caller_res_info_struct *phb_res_info;
    srv_prof_settings_enum profile_setting = SRV_PROF_SETTINGS_END_OF_ENUM;
    srv_prof_audio_id prof_audio_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info)
    {
        return MMI_FALSE;
    }

    call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, (U8)ucm_res_info->uid_info.call_id);
    if (!call_info)
    {
        return MMI_FALSE;
    }

    phb_res_info = OslMalloc(sizeof(srv_phb_caller_res_info_struct));
    memcpy(&res_id, &(call_info->phb_res_id), sizeof(srv_phb_caller_res_id_struct));

    srv_phb_get_caller_res_info_by_id(&res_id, phb_res_info);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_GET_CALLER_RES_INFO_PHB,
        phb_res_info->res_type,
        phb_res_info->pic_id,
        phb_res_info->pic_path[0], phb_res_info->pic_path[1], phb_res_info->pic_path[2], phb_res_info->pic_path[3], phb_res_info->pic_path[4],
        phb_res_info->ringtone_id,
        phb_res_info->ringtone_path[0], phb_res_info->ringtone_path[1], phb_res_info->ringtone_path[2], phb_res_info->ringtone_path[3], phb_res_info->ringtone_path[4]
        );

    /* decide image id */
    if (!phb_res_info->pic_id || !(phb_res_info->res_type & SRV_PHB_RES_TYPE_IMAGE_ID))
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (call_info->call_type == CSMCC_VIDEO_CALL)
        {
            phb_res_info->pic_id = IMG_PHB_VIDEO_DEFAULT;
        }
        else
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        {
            phb_res_info->pic_id = IMG_PHB_DEFAULT;
        }              
    }
    if ((call_info->dir == SRV_GCALL_DIR_MO || 
          call_info->dir == SRV_GCALL_DIR_MO_STK) &&
         (phb_res_info->pic_id == IMG_PHB_DEFAULT
        #ifdef __MMI_VIDEO_TELEPHONY__
            || phb_res_info->pic_id == IMG_PHB_VIDEO_DEFAULT
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            ))
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (call_info->call_type == CSMCC_VIDEO_CALL)
        {
            ucm_res_info->pic_id = IMG_ID_GCALL_VT_OUTGOING_CALL;
        }
        else
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        {
            ucm_res_info->pic_id = IMG_ID_GCALL_OUTGOING;
        }                
    }
    else
    {
        ucm_res_info->pic_id = phb_res_info->pic_id;
    }

    /* decide tone id */
    if ((phb_res_info->res_type & SRV_PHB_RES_TYPE_RING_ID) && phb_res_info->ringtone_id)
    {
        ucm_res_info->tone_id = phb_res_info->ringtone_id;
    }
    else
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (call_info->call_type == CSMCC_VIDEO_CALL)
        {
            prof_audio_id = 0;
            if (srv_prof_get_current_profile_value(
                    SRV_PROF_SETTINGS_VT_CALL_TONE, 
                    &prof_audio_id) != SRV_PROF_RET_SUCCESS)
            {
                ucm_res_info->tone_id = AUD_ID_PROF_RING1;
            }
            else
            {
                ucm_res_info->tone_id = (U16)prof_audio_id;
            }
        }
        else
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        {
            switch (cm_p->interface)
            {
                case MMI_SIM1:
                    profile_setting = SRV_PROF_SETTINGS_MT_CALL_TONE;
                    break;
            #if (MMI_MAX_SIM_NUM >= 2)
                case MMI_SIM2:
                    profile_setting = SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE;
                    break;
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMI_SIM3:
                    profile_setting = SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE;
                    break;
            #if (MMI_MAX_SIM_NUM == 4)
                case MMI_SIM4:
                    profile_setting = SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE;
                    break;
            #endif /* (MMI_MAX_SIM_NUM == 4) */
            #endif /* (MMI_MAX_SIM_NUM >= 3) */
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
                default:
                    MMI_ASSERT(0);
                    break;
            }

            prof_audio_id = 0;
            if (srv_prof_get_current_profile_value(
                     profile_setting,
                     &prof_audio_id) != SRV_PROF_RET_SUCCESS)
            {
                ucm_res_info->tone_id = AUD_ID_PROF_RING1;
            }
            else
            {
                ucm_res_info->tone_id = (U16)prof_audio_id;
            }
        }
    }

    /* decide video id */
#ifdef __MMI_PHB_CALLER_VIDEO__
    if (phb_res_info->res_type & SRV_PHB_RES_TYPE_VIDEO_ID)
    {
        ucm_res_info->video_id = phb_res_info->video_id;
    }
    else
#endif /* __MMI_PHB_CALLER_VIDEO__ */
    {
        ucm_res_info->video_id = 0;
    }

    /* image path */
    if (phb_res_info->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
    {
        memcpy(ucm_res_info->pic_path, phb_res_info->pic_path, sizeof(ucm_res_info->pic_path));
    }
    else
    {
        ucm_res_info->pic_path[0] = L'\0';
    }

    /* tone path */
    if (phb_res_info->res_type & SRV_PHB_RES_TYPE_AUDIO_RING_FILE)
    {
        memcpy(ucm_res_info->tone_path, phb_res_info->ringtone_path, sizeof(ucm_res_info->tone_path));
    }
    else
    {
        ucm_res_info->tone_path[0] = L'\0';
    }

    /* video path */
#ifdef __MMI_PHB_CALLER_VIDEO__
    if (phb_res_info->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
    {
        memcpy(ucm_res_info->video_path, phb_res_info->video_path, sizeof(ucm_res_info->video_path));
    }
    else
#endif /* __MMI_PHB_CALLER_VIDEO__ */
    {
        ucm_res_info->video_path[0] = L'\0';
    }

    ucm_res_info->is_video_sound = (phb_res_info->res_type & SRV_PHB_RES_TYPE_VIDEO_SOUND_ON) ? MMI_TRUE : MMI_FALSE;

    /* decide res type */
    ucm_res_info->res_type = (srv_ucm_res_type_enum)0;
    ucm_res_info->res_type |= SRV_UCM_RES_TYPE_TONE_ID;
    ucm_res_info->res_type |= SRV_UCM_RES_TYPE_IMAGE_ID;
    if (ucm_res_info->video_id)
    {
        ucm_res_info->res_type |= SRV_UCM_RES_TYPE_VIDEO_ID;
    }
    if (ucm_res_info->tone_path[0] != L'\0')
    {
        ucm_res_info->res_type |= SRV_UCM_RES_TYPE_TONE_PATH;
    }
    if (ucm_res_info->pic_path[0] != L'\0')
    {
        ucm_res_info->res_type |= SRV_UCM_RES_TYPE_IMAGE_PATH;
    }
#ifdef __MMI_PHB_CALLER_VIDEO__
    if (ucm_res_info->video_path[0] != L'\0')
    {
        ucm_res_info->res_type |= SRV_UCM_RES_TYPE_VIDEO_PATH;
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_GET_CALLER_RES_INFO,
        ucm_res_info->uid_info.call_type,
        ucm_res_info->uid_info.group_id,
        ucm_res_info->uid_info.call_id,
        ucm_res_info->res_type,
        ucm_res_info->pic_id,
        ucm_res_info->pic_path[0], ucm_res_info->pic_path[1], ucm_res_info->pic_path[2], ucm_res_info->pic_path[3], ucm_res_info->pic_path[4],
        ucm_res_info->tone_id,
        ucm_res_info->tone_path[0], ucm_res_info->tone_path[1], ucm_res_info->tone_path[2], ucm_res_info->tone_path[3], ucm_res_info->tone_path[4],
        ucm_res_info->video_id,
        ucm_res_info->video_path[0], ucm_res_info->video_path[1], ucm_res_info->video_path[2], ucm_res_info->video_path[3], ucm_res_info->video_path[4],
        ucm_res_info->is_video_sound
        );

    OslMfree(phb_res_info);

    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_gcall_op_is_busy
 * DESCRIPTION
 *  Returns number for outgoing call
 * PARAMETERS
 *  handle          [IN]        
 *  Cause(?)        [OUT]       Value
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_gcall_op_is_busy(srv_ucm_int_prmt_opcode_enum act_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_gcall_util_op_need_rsp((srv_ucm_int_act_opcode_enum)act_op))
    {
        return MMI_FALSE;
    }

    if (cm_p->ucm_info.bg_op == SRV_UCM_INT_AUTO_REJECT_ACT)
    {
        /* not allow any op when auto reject is proceeding */
        return MMI_TRUE;
    }

    switch (act_op)
    {
        case SRV_UCM_INT_END_SINGLE_PRMT:
        case SRV_UCM_INT_END_CONFERENCE_PRMT:
        case SRV_UCM_INT_END_ALL_PRMT:
        case SRV_UCM_INT_END_ALL_AND_DIAL_PRMT:
        case SRV_UCM_INT_END_ALL_AND_ACCEPT_PRMT:
        case SRV_UCM_INT_END_ALL_ACTIVE_AND_RETRIEVE_PRMT:
        case SRV_UCM_INT_END_ALL_ACTIVE_AND_ACCEPT_PRMT:
            return MMI_FALSE;

        default:
            if (cm_p->ucm_info.op == SRV_UCM_INT_NO_ACT)
            {
                return MMI_FALSE;
            }
            else
            {
                return MMI_TRUE;
            }
    }

}


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_is_any_disconnecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_gcall_is_any_disconnecting(U8 group_id)
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

        if ((call_info->group_id == group_id)
            && (call_info->status_flag & SRV_GCALL_STATUS_DISCONNECTING))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_is_tmp_not_available
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  MMI_TRUE: temporarily not available
 *****************************************************************************/
MMI_BOOL srv_gcall_is_tmp_not_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_gcall_util_type_available(cm_p->ucm_info.call_type, MMI_TRUE))
    {
        /* permanently unavailable */
        return MMI_FALSE;
    }

    if (!cm_p->nw_available
        || ((cm_p->interface == MMI_SIM1)
            && ((srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_NO_SERVICE)
                || (srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_SEARCHING)))
    #if (MMI_MAX_SIM_NUM >= 2)
        || ((cm_p->interface == MMI_SIM2)
            && ((srv_nw_info_get_service_availability(MMI_SIM2) == SRV_NW_INFO_SA_NO_SERVICE)
                || (srv_nw_info_get_service_availability(MMI_SIM2) == SRV_NW_INFO_SA_SEARCHING)))
    #if (MMI_MAX_SIM_NUM >= 3)
        || ((cm_p->interface == MMI_SIM3)
            && ((srv_nw_info_get_service_availability(MMI_SIM3) == SRV_NW_INFO_SA_NO_SERVICE)
                || (srv_nw_info_get_service_availability(MMI_SIM3) == SRV_NW_INFO_SA_SEARCHING)))
    #if (MMI_MAX_SIM_NUM == 4)
        || ((cm_p->interface == MMI_SIM4)
            && ((srv_nw_info_get_service_availability(MMI_SIM4) == SRV_NW_INFO_SA_NO_SERVICE)
                || (srv_nw_info_get_service_availability(MMI_SIM4) == SRV_NW_INFO_SA_SEARCHING)))
    #endif /* (MMI_MAX_SIM_NUM == 4) */ 
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        )
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_reset_redial_info
 * DESCRIPTION
 *  This function resets redial counter for call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_reset_redial_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data = cm_p->redial_info.phb_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(cm_p->redial_info), 0, sizeof(srv_gcall_redial_struct));

    if (user_data)
    {
        if (cm_p->release_call_info.post_action)
        {
            /* reserve phb data for post action */
            cm_p->redial_info.phb_data = user_data;
        }
        else
        {
            /* only destory phb_data when post action is not triggered */
            srv_gcall_util_mgmt_phb_info(MMI_FALSE, user_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_reset_call_info
 * DESCRIPTION
 *  This function resets redial counter for call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_reset_call_info(srv_gcall_call_info_struct *call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(call_info, 0, sizeof(srv_gcall_call_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_reset_release_call_info
 * DESCRIPTION
 *  This function resets redial counter for call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_reset_release_call_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(cm_p->release_call_info), 0, sizeof(srv_gcall_release_call_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_reset_mo_info
 * DESCRIPTION
 *  This function resets redial counter for call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_reset_mo_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(cm_p->mo), 0, sizeof(srv_gcall_mo_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_reset_ucm_info_except_bg_op
 * DESCRIPTION
 *  This function resets redial counter for call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_reset_ucm_info_except_bg_op(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_act_opcode_enum bg_op = cm_p->ucm_info.bg_op;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(cm_p->ucm_info), 0, sizeof(srv_gcall_ucm_info_struct));
    cm_p->ucm_info.bg_op = bg_op;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_reset_auto_dtmf_info
 * DESCRIPTION
 *  This function resets redial counter for call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_reset_auto_dtmf_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(cm_p->auto_dtmf_info), 0, sizeof(srv_gcall_auto_dtmf_struct));
}


#ifdef __CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_reset_ccbs_info
 * DESCRIPTION
 *  This function resets redial counter for call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_reset_ccbs_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(cm_p->ccbs_info), 0, sizeof(srv_gcall_ccbs_struct));
}
#endif /* __CCBS_SUPPORT__ */


