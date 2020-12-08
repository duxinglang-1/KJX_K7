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
 *   GCallSrvPsInterface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  GSM / 3G call service
 *  Interfaces for protocol stack
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "ProtocolEvents.h"

#ifdef CS_NOTIFYDURATION
#undef CS_NOTIFYDURATION
#endif 

#include "csmcc_enums.h" /* csmcc_cpi_msg_type_enum */
#include "mmiapi_struct.h" /* mmi_make_call_req_ind_struct */
#ifdef __MMI_VIDEO_TELEPHONY__
#include "vt_mmi_struct.h" /* mmi_vt_start_counter_struct */
#endif /* __MMI_VIDEO_TELEPHONY__ */

#include "GCallSrvProt.h"

#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "kal_non_specific_general_types.h"
#include "MMIDataType.h"
#include "l4c_aux_struct.h"
#include "string.h"
#include "UcmSrvGprot.h"
#include "GCallSrvDef.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "csmcc_common_enums.h"
#include "UcmSrvIntProt.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "stack_ltlcom.h"
#include "l3_inc_enums.h"
#include "MMI_features.h"
#include "csmss_common_enums.h"
#include "mmi_frm_events_gprot.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"


/*****************************************************************************
 * FUNCTION
 *    srv_gcall_l4c_ata_req
 * DESCRIPTION
 *   
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_gcall_l4c_ata_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_ata_req_struct *ataReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ATA_REQ */
    ataReq = OslAllocDataPtr(mmi_cc_ata_req_struct);
    
    ataReq->source_id = cm_p->ucm_info.l4c_source;
    cm_p->ucm_info.l4c_source = L4C_SOURCE_ID_DEFAULT;
    
    cm_p->ps_info.rsp_event = PRT_INCOMINGCALL_ACCEPT_SUCCESS;
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_ata_rsp, cm_p->ps_info.rsp_event);

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PRT_INCOMINGCALL_ACCEPT_EVENT, (oslParaType *)ataReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_data_call_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op      [IN]    l4c_data_call_op_enum
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_data_call_res_req(U8 op, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_data_call_res_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = OslAllocDataPtr(mmi_data_call_res_req_struct);
    req->call_type = cm_p->data_call_info_p->call_type;
    memcpy(&(req->number), &(cm_p->data_call_info_p->number), sizeof(l4c_number_struct));
    req->opcode = op;
    req->result = result ? KAL_TRUE: KAL_FALSE;
    req->source_id = cm_p->data_call_info_p->source_id;

    /* free data_call_info */
    OslFreeDataPtr(cm_p->data_call_info_p);
    cm_p->data_call_info_p = NULL;

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), MSG_ID_MMI_DATA_CALL_RES_REQ, (oslParaType *)req, NULL);
  }


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_ss_parsing_string_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op      [IN]    l4c_data_call_op_enum
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_ss_parsing_string_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __IP_NUMBER__
    WCHAR ip_num_ucs2[SRV_UCM_MAX_IP_NUMBER_LEN + 1];
#endif /* __IP_NUMBER__ */
    mmi_ss_parsing_string_req_struct *req;
    srv_gcall_call_info_struct *call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(call_info);

#ifdef __IP_NUMBER__
    memset(ip_num_ucs2, 0, sizeof(ip_num_ucs2));
    if (cm_p->mo.is_ip_dial)
    {
        srv_gcall_util_get_curr_ip_number_ucs2(cm_p->interface, ip_num_ucs2);
    }
#endif /* __IP_NUMBER__ */ 

    /* PARSE_SS_REQ */
    req = OslAllocDataPtr(mmi_ss_parsing_string_req_struct);

    req->length = strlen((CHAR *)call_info->num);
    memcpy(req->input, call_info->num, req->length);

    req->dcs = 0x0f;

    req->ip_string[0] = 0;
#ifdef __IP_NUMBER__
    if (mmi_ucs2strlen((CHAR *)ip_num_ucs2))
    {
        mmi_ucs2_n_to_asc((CHAR *)req->ip_string, (CHAR *)ip_num_ucs2, SRV_UCM_MAX_IP_NUMBER_LEN * ENCODING_LENGTH);
    }
#endif /* __IP_NUMBER__ */

    req->source_id = cm_p->ucm_info.l4c_source;
    cm_p->ucm_info.l4c_source = L4C_SOURCE_ID_DEFAULT;

    req->call_type = call_info->call_type;

    req->als_type = ALS_DIAL_BY_SETTING;
    req->ecc_info = INFO_ECC_CHECK_BY_MODEM;

    cm_p->ps_info.rsp_event = PRT_USSDVSS_RSP;
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_ss_parsing_string_rsp, cm_p->ps_info.rsp_event);

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PRT_USSDVSS_REQ, (oslParaType *)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_chld_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op_code     [IN]       csmcc_crss_req_enum
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_chld_req(U8 op_code, U8 call_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_chld_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->ps_info.chld_type = op_code;

    req = OslAllocDataPtr(mmi_cc_chld_req_struct);

    req->opcode = op_code;

    req->call_id = call_id;

    req->source_id = cm_p->ucm_info.l4c_source;
    cm_p->ucm_info.l4c_source = L4C_SOURCE_ID_DEFAULT;
    
    if ((srv_gcall_util_op_need_rsp(cm_p->ucm_info.op)
        || srv_gcall_util_op_need_rsp(cm_p->ucm_info.bg_op))
    #ifdef __CCBS_SUPPORT__
        && (op_code != CSMCC_REL_CCBS) /* rejecting ccbs recall doesn't need to wait the rsp */
        && (cm_p->ccbs_info.state != SRV_GCALL_CCBS_STATE_ACTIVATE_CNF) /* ignoring ccbs activation cnf ind doesn't need to wait the rsp */
    #endif /* __CCBS_SUPPORT__ */
        )
    {
        /* wait for chld_rsp */
        cm_p->ps_info.rsp_event = PRT_END_CHLD_RSP;
        srv_gcall_set_ps_event_handler(srv_gcall_phdlr_chld_rsp, cm_p->ps_info.rsp_event);
    }

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), MSG_ID_MMI_CC_CHLD_REQ, (oslParaType *)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_rel_comp_req
 * DESCRIPTION
 *  Send relese complete message to L4C to strictly releasae the disconnecting call
 *  
 *  It is for drop call refinement
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_rel_comp_req(U8 call_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_rel_comp_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = OslAllocDataPtr(mmi_cc_rel_comp_req_struct);
    req->call_id = call_id;

    /* don't need to wait for rsp */
    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PRT_RELCOMP_EVENT, (oslParaType *)req, NULL);
}

#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_call_deflect_req
 * DESCRIPTION
 *  Makes call to Protcol Stack to deflect incoming Call
 *  
 *  The call back registers a handler with the event dynamically
 * PARAMETERS
 *  callBack                [?]         
 *  CallDeflectNumber       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_call_deflect_req(U8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_deflect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = OslAllocDataPtr(mmi_cc_call_deflect_req_struct);

    if (number[0] == '+')
    {
        req->dest.type = CSMCC_INTERNATIONAL_ADDR;
        strcpy((CHAR *)req->dest.number, (CHAR *)(number + 1));
    }
    else
    {
        req->dest.type = CSMCC_DEFAULT_ADDR_TYPE;
        strcpy((CHAR *) req->dest.number, (CHAR *)number);
    }
    req->dest.length = strlen((CHAR *)req->dest.number);

    req->sub_addr_flag = KAL_FALSE;
    memset(&(req->sub_dest), 0, sizeof(req->sub_dest));

    cm_p->ps_info.rsp_event = PRT_CALL_DEFLECT_RSP;
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_call_deflect_rsp, cm_p->ps_info.rsp_event);

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PRT_CALL_DEFLECT_REQ, (oslParaType *)req, NULL);
}
#endif /* __MMI_UCM_DEFLECT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_get_call_list_req
 * DESCRIPTION
 *  Makes call to Protcol Stack to deflect incoming Call
 *  
 *  The call back registers a handler with the event dynamically
 * PARAMETERS
 *  callBack                [?]         
 *  CallDeflectNumber       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_get_call_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gcall_set_ps_event_handler(srv_gcall_phdlr_get_call_list_rsp, PTR_GET_CALL_LIST_RSP);

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PTR_GET_CALL_LIST_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_start_dtmf_req
 * DESCRIPTION
 *  Helper function to start sending a dtmf tone
 * PARAMETERS
 *  MsgStruct       [?]         
 *  U8(?)           [IN]        * This contains digit to send to pstack
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_start_dtmf_req(U16 *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_start_dtmf_req_struct *dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmf = OslAllocDataPtr(mmi_cc_start_dtmf_req_struct);
    dtmf->digit = srv_gcall_util_convert_dtmf_to_ascii(MsgStruct);    /* the actuall digit */

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PRT_DTMF_START_REQ, (oslParaType *)dtmf, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_stop_dtmf_req
 * DESCRIPTION
 *  Helper function to stop dtmf tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_stop_dtmf_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_stop_dtmf_req_struct *dtmf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmf = OslAllocDataPtr(mmi_cc_stop_dtmf_req_struct);
    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PRT_DTMF_STOP_REQ, (oslParaType *)dtmf, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_start_auto_dtmf_req
 * DESCRIPTION
 *  Helper function to start sending a dtmf tone
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains digit to send to pstack
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_start_auto_dtmf_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_start_auto_dtmf_req_struct *dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmf = OslAllocDataPtr(mmi_cc_start_auto_dtmf_req_struct);
    strncpy((CHAR *)dtmf->digit, (CHAR *)cm_p->auto_dtmf_info.buf, 80);

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PRT_DTMF_CONFIRM_REQ, (oslParaType *)dtmf, NULL);
}


#ifdef __AUTO_CALL_REJECTION__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_call_present_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  approval    [IN]    l4c_mt_call_approval_enum
 *  call_id     [IN]    call id
 *  seq_num     [IN]    sequence number for present state calls
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_call_present_res_req(U8 approval, U8 call_id, U8 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_present_res_req_struct *mt_approve;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mt_approve = OslAllocDataPtr(mmi_cc_call_present_res_req_struct);
    mt_approve->is_mt_call_allowed = approval;
    mt_approve->call_id = call_id;
    mt_approve->seq_num = seq_num;

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), PRT_CC_CALL_PRESENT_RES_REQ, (oslParaType *)mt_approve, NULL);
 }
#endif /* __AUTO_CALL_REJECTION__ */


#ifdef __CPI_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_l4c_cpi_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_l4c_cpi_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_cpi_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = OslAllocDataPtr(mmi_cc_cpi_req_struct);
    req->mode = 768; /* the 9th and 10th bit is 1, for CSMCC_MO_CALL_ID_ASSIGN_MSG and CSMCC_STATE_CHANGE_HELD */

    mmi_frm_send_ilm(srv_gcall_get_l4c_mod_id(), MSG_ID_MMI_CC_CPI_REQ, (oslParaType *)req, NULL);
 }
#endif /* __CPI_SUPPORT__ */


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_vt_uii
 * DESCRIPTION
 *  Helper function to send a VT dtmf tone
 * PARAMETERS
 *  MsgStruct       [IN]  req
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_vt_uii(U16 *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vt_uii_struct *dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmf = OslAllocDataPtr(mmi_vt_uii_struct);
    dtmf->uiiLength = 1;
    dtmf->uiiString[0] = srv_gcall_util_convert_dtmf_to_ascii(MsgStruct);    /* the actuall digit */

    mmi_frm_send_ilm(MOD_VT, MSG_ID_MMI_VT_UII, (oslParaType *)dtmf, NULL);
}
#endif /* __MMI_VIDEO_TELEPHONY__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_call_ring_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_call_ring_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_ring_ind_struct *msg = (mmi_cc_call_ring_ind_struct*)info;
    srv_gcall_mt_alert_struct alert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    /* derive the alert struct */
    memset(&alert, 0, sizeof(srv_gcall_mt_alert_struct));
    alert.call_id = msg->call_id;
    alert.call_type = msg->call_type;
    alert.num_p = &(msg->num);
    alert.sub_addr_p = &(msg->sub_addr);
    alert.addr_ind_present = msg->addr_ind_present;
    alert.addr_ind = msg->addr_ind;
    alert.no_cli_cause_present = msg->no_cli_cause_present;
    alert.no_cli_cause = msg->no_cli_cause;
    alert.name_present = msg->name_present;
    alert.name = msg->name;
    alert.dcs = msg->dcs;
    alert.length = msg->length;

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MT_ALERT, &alert);

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_call_wait_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_call_wait_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_wait_ind_struct *msg = (mmi_cc_call_wait_ind_struct*)info;
    srv_gcall_mt_alert_struct alert;
    l4c_sub_addr_struct sub_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    /* derive the alert struct */
    memset(&alert, 0, sizeof(srv_gcall_mt_alert_struct));
    memset(&sub_addr, 0, sizeof(l4c_sub_addr_struct));
    alert.call_id = msg->call_id;
    alert.call_type = msg->call_mode;
    alert.num_p = &(msg->num);
    alert.sub_addr_p = &(sub_addr);
    alert.addr_ind_present = msg->addr_ind_present;
    alert.addr_ind = msg->addr_ind;
    alert.no_cli_cause_present = msg->no_cli_cause_present;
    alert.no_cli_cause = msg->no_cli_cause;
    alert.name_present = msg->name_present;
    alert.name = msg->name;
    alert.dcs = msg->dcs;
    alert.length = msg->length;

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MT_ALERT, &alert);

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_data_call_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_data_call_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_data_call_req_ind_struct *msg = (mmi_data_call_req_ind_struct*)info;
    srv_gcall_ps_event_enum event = SRV_GCALL_PS_EVENT_INVALID;
    srv_ucm_int_dial_cnf_struct cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(msg);

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    if (msg->call_type == CSMCC_CSD_CALL)
    {
        switch (msg->opcode)
        {
            case CALL_DIAL:
                event = SRV_GCALL_PS_EVENT_DIAL_CNF_IND;
                break;

            default:
                /* ignore */
                break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PHDLR_DATA_CALL_REQ_IND, event);

    /* keep data call info */
    cm_p->data_call_info_p = msg;
    OslHoldDataPtr(cm_p->data_call_info_p);

    if (event != SRV_GCALL_PS_EVENT_INVALID)
    {
        srv_gcall_proc_ps_event(event, info);
    }
    else
    {
        /* un-supported call type */
        cnf.result = MMI_FALSE;
        srv_gcall_proc_cm_event(SRV_GCALL_CM_EVENT_DIAL_CNF, &cnf);
    }

    srv_gcall_cntxt_reset_ptr();

}


#ifdef __CPI_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_cpi_ind
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  Incoming Call is accepted
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_cpi_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_cpi_ind_struct *msg = (mmi_cc_cpi_ind_struct*)info;
    srv_gcall_call_info_struct *call_info;
    srv_gcall_mo_id_assign_struct mo_id_ind;
    srv_gcall_change_call_state_struct change_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    switch (msg->msg_type)
    {
        case CSMCC_MO_CALL_ID_ASSIGN_MSG:
            if (msg->dir != CLCC_MO_CALL)
            {
                break;
            }
            if (msg->call_id != MO_CALL_ASSIGN_FAIL_CALLID)
            {
                memset(&mo_id_ind, 0, sizeof(mo_id_ind));
                mo_id_ind.call_id = msg->call_id;
                mo_id_ind.call_type = (srv_gcall_type_enum)msg->call_type;
                srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MO_ID_ASSIGNED, &mo_id_ind);
            }
            else
            {
                call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);
                if (!call_info)
                {
                    /* ignore, no such call */
                    srv_gcall_cntxt_reset_ptr();
                    return;
                }

                srv_gcall_phdlr_set_release_call_info(call_info, msg->disc_cause);

                srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_OUTGOING, call_info);
            }
            break;

        case CSMCC_STATE_CHANGE_HELD:
            /* In SAT MO case, CSM may hold the active call automatically */
            if (cm_p->mo.module_id == SRV_UCM_MODULE_ORIGIN_SAT)
            {
                memset(&change_ind, 0, sizeof(srv_gcall_change_call_state_struct));
                change_ind.call_id = msg->call_id;
                change_ind.state = SRV_GCALL_STATE_HOLD;
                srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_CHANGE_CALL_STATE, &change_ind);
            }
            break;

        default:
            break;
    }

    srv_gcall_cntxt_reset_ptr();

}
#endif /* __CPI_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_dial_ind
 * DESCRIPTION
 *  Helper function to get call list from PS to sync with MMI
 *  
 *  DIAL_IND from PS.
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_dial_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_dial_ind_struct *msg = (mmi_cc_dial_ind_struct*)info;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);
    if (!call_info)
    {
        /* ignore, no such call */
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    /* doesn't check call id in DIAL_IND since in failed cases, call_id may be 0
     * and in successful cases, do nothing when receiving DIAL_IND */

    if (msg->result.flag == L4C_OK)
    {
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MO_PROCEEDING, NULL);
    }
    else
    {
        srv_gcall_phdlr_set_release_call_info(call_info, msg->result.cause);
        if (call_info->status_flag & SRV_GCALL_STATUS_HANGUP_REQUESTED)
        {
            cm_p->release_call_info.is_abort = MMI_TRUE;
        }

        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_OUTGOING, call_info);
    }

    srv_gcall_cntxt_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_call_connect_ind
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_CALLCONNECTED
 *  with the Structure containing CM_CALL_HANDLE.
 *  
 *  We could have mapped void* to CM_CALL_HANDLE and passed it to the
 *  state m/c. CONNECT_IND from PS
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains CM_CALL_HANDLE passed by the stack when call is connected)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_call_connect_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MO_CONNECTED, info);

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_call_release_ind
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_CALLCONNECTED
 *  with the Structure containing CM_CALL_HANDLE.
 *  
 *  We could have mapped void* to CM_CALL_HANDLE and passed it to the
 *  state m/c. CONNECT_IND from PS
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains CM_CALL_HANDLE passed by the stack when call is connected)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_call_release_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_release_ind_struct *msg = (mmi_cc_call_release_ind_struct*)info;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, msg->call_id);

    if (call_info)
    {
        if (!msg->cause ||
            (call_info->disc_cause && 
             (call_info->disc_cause != SRV_GCALL_RESULT_NORMAL_CALL_CLR) &&
             (call_info->disc_cause != SRV_GCALL_RESULT_NORMAL_UNSPECIFIED)))
        {
            /* use the cause in disc_ind */
            srv_gcall_phdlr_set_release_call_info(call_info, call_info->disc_cause);
        }
        else
        {
            /* use the cause in rel_ind */
            srv_gcall_phdlr_set_release_call_info(call_info, msg->cause);
        }
        if (call_info->status_flag & SRV_GCALL_STATUS_HANGUP_REQUESTED)
        {
            cm_p->release_call_info.is_abort = MMI_TRUE;
        }

        switch (call_info->curr_state)
        {
            case SRV_GCALL_STATE_OUTGOING:
                srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_OUTGOING, call_info);
                break;

            case SRV_GCALL_STATE_INCOMING:
                srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_INCOMING, call_info);
                break;

            default:
                srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_OTHERS, call_info);
                break;
        }

    }
#ifdef __CCBS_SUPPORT__
    else if (msg->call_id == cm_p->ccbs_info.call_id)
    {
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_CCBS_RECALL_CANCEL, NULL);
    }
#endif /* __CCBS_SUPPORT__ */
#ifdef __AUTO_CALL_REJECTION__
    else if (msg->call_id == cm_p->mt.call_present_id)
    {
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_PRESENT_CALL, NULL);
    }
#endif /* __AUTO_CALL_REJECTION__ */

    srv_gcall_cntxt_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_call_disconnect_ind
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  is outgoing call disconnect indication(CCBS)
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_call_disconnect_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_disconnect_ind_struct *ind = (mmi_cc_call_disconnect_ind_struct*)info;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, ind->call_id);
    if (!call_info)
    {
        /* ignore */
        /* ignore disc_ind for present state calls */
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    call_info->disc_cause = ind->cause;

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_DISCONNECTING, call_info);

#ifdef __CCBS_SUPPORT__
    if (ind->ccbs == KAL_TRUE)
    {
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_CCBS_ACTIVATE_CNF_IND, call_info);
    }
#endif /* __CCBS_SUPPORT__ */

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_speech_ind
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  is outgoing call disconnect indication(CCBS)
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_speech_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_SPEECH, info);

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_internal_alert_ind
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  is outgoing call disconnect indication(CCBS)
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_internal_alert_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MO_ALERT, info);

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_start_auto_dtmf_ind
 * DESCRIPTION
 *  This is CBack for -- Indication
 * PARAMETERS
 *  info        [?]         
 *  data(?)     [IN]        From PS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_start_auto_dtmf_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_AUTO_DTMF, info);

    srv_gcall_cntxt_reset_ptr();

}


#ifdef __AOC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_ccm_ind
 * DESCRIPTION
 *  This is CBack for -- Indication
 * PARAMETERS
 *  info        [?]         
 *  data(?)     [IN]        From PS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_ccm_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    if (!info
        || !srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, ((mmi_cc_ccm_ind_struct*)info)->call_id)
       )
    {
        /* ignore */
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_UPDATE_CALL_COST, info);

    srv_gcall_cntxt_reset_ptr();

}
#endif /* __AOC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_notify_ss_ind
 * DESCRIPTION
 *  This is CBack for -- Indication
 * PARAMETERS
 *  info        [?]         
 *  data(?)     [IN]        From PS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_notify_ss_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_notify_ss_ind_struct *msg = (mmi_cc_notify_ss_ind_struct*)info;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, msg->call_id);

    if (!call_info)
    {
        /* ignore */
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    /* derive info */
    cm_p->ss_notify_info.event = msg->type;
    cm_p->ss_notify_info.notify_present = msg->notification_present;
    cm_p->ss_notify_info.notify = msg->notification;

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_SS_NOTIFY, call_info);

    srv_gcall_cntxt_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_make_call_req_ind
 * DESCRIPTION
 *  This is CBack for -- Indication
 * PARAMETERS
 *  info        [?]         
 *  data(?)     [IN]        From PS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_make_call_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* convert the source id */
    switch (mod_src)
    {
        case MOD_JAM:
            switch (((mmi_make_call_req_ind_struct*)info)->call_type)
            {
                case SRV_UCM_VOICE_CALL_TYPE:
                    mod_src = MOD_L4C;
                    break;
            #if (MMI_MAX_SIM_NUM >= 2)
                case SRV_UCM_VOICE_CALL_TYPE_SIM2:
                    mod_src = MOD_L4C_2;
                    break;
            #if (MMI_MAX_SIM_NUM >= 3)
                case SRV_UCM_VOICE_CALL_TYPE_SIM3:
                    mod_src = MOD_L4C_3;
                    break;
            #if (MMI_MAX_SIM_NUM == 4)
                case SRV_UCM_VOICE_CALL_TYPE_SIM4:
                    mod_src = MOD_L4C_4;
                    break;
            #endif /* (MMI_MAX_SIM_NUM == 4) */
            #endif /* (MMI_MAX_SIM_NUM >= 3) */
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
                default:
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PHDLR_MAKE_CALL_REQ_IND_NOT_SUPPORT);
                    return;
            }
            break;

        default:
            /* not support */
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_PHDLR_MAKE_CALL_REQ_IND_NOT_SUPPORT);
            return;
    }

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MAKE_CALL_REQ_IND, info);

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_call_sync_req_ind
 * DESCRIPTION
 *  This is CBack for -- Indication
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_call_sync_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_CALL_SYNC_REQ_IND, NULL);

    srv_gcall_cntxt_reset_ptr();

}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_nw_mmrr_service_status_ind
 * DESCRIPTION
 *  Dispatch protocol handlers from master side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_nw_mmrr_service_status_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_CHANGE_NW_STATUS, info);

    srv_gcall_cntxt_reset_ptr();

}
#endif /* (MMI_MAX_SIM_NUM >= 2) */


#ifdef __MMI_CM_CNAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_notify_ss_cnap_ind
 * DESCRIPTION
 *  This is CBack for -- Indication
 * PARAMETERS
 *  info        [?]         
 *  data(?)     [IN]        From PS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_notify_ss_cnap_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_notify_ss_cnap_ind_struct *msg = (mmi_cc_notify_ss_cnap_ind_struct*)info;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_ID, msg->call_id);
    if (!call_info
        || (call_info->curr_state != SRV_GCALL_STATE_INCOMING))
    {
        /* ignore */
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MT_UPDATE_NAME, info);

    srv_gcall_cntxt_reset_ptr();
}
#endif /* __MMI_CM_CNAP_SUPPORT__ */


#ifdef __AUTO_CALL_REJECTION__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_call_present_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_call_present_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MT_PRESENT, info);

    srv_gcall_cntxt_reset_ptr();

}
#endif /* __AUTO_CALL_REJECTION__ */


#ifdef __CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_notify_ss_ccbs_ind
 * DESCRIPTION
 *  This function is called back by the protocol stack when CCBS
 *  notification is there
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_notify_ss_ccbs_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_CCBS_RECALL, info);

    srv_gcall_cntxt_reset_ptr();

}
#endif /* __CCBS_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_ata_rsp
 * DESCRIPTION
 *  This function is called back by the protocol stack when there
 *  Incoming Call is accepted
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_ata_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    mmi_cc_ata_rsp_struct *rsp = (mmi_cc_ata_rsp_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    cm_p->ps_info.rsp_event = 0;
    srv_gcall_reset_ps_event_handler(PRT_INCOMINGCALL_ACCEPT_SUCCESS);

    /* derive the result */
    if (rsp->result.flag == L4C_OK)
    {
        result = SRV_GCALL_RESULT_OK;
    }
    else
    {
        /* can not answer MT data call thru MMI */
        if (rsp->result.cause == CM_L4C_GEN_CAUSE && rsp->call_mode == SINGLE_DATA_CALL)
        {
            result = SRV_GCALL_RESULT_MT_DATA_CALL_FAIL;
        }
        else
        {
            result = rsp->result.cause;
        }
    }
    MMI_TRACE(MMI_TRACE_G5_CM, TRC_SRV_GCALL_PHDLR_ATA_RSP_RESULT, result);

    /* trigger ps events */
    if (result == SRV_GCALL_RESULT_OK)
    {
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MT_CONNECTED, NULL);
    }
    else
    {
        /* accept fail doesn't imply call is disconnected */
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_MT_CONNECT_FAIL, &result);
    }

    srv_gcall_cntxt_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_ss_parsing_string_rsp
 * DESCRIPTION
 *  This Sets the features of the call as per
 * PARSING STR RSP
 *  
 *  
 *  PARSING_STRING_RSP from PS
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_ss_parsing_string_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_parsing_string_rsp_struct *rsp = (mmi_ss_parsing_string_rsp_struct*)info;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    cm_p->ps_info.rsp_event = 0;
    srv_gcall_reset_ps_event_handler(PRT_USSDVSS_RSP);

    if (rsp->result.flag == 1) /* success */
    {
        if (rsp->info.opcode != CC_OPERATION)
        {
            MMI_ASSERT(0);
            return;
        }

        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_DIAL_RSP, info);

    }
    else /* fail */
    {
        call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_STATE, (U8)SRV_GCALL_STATE_OUTGOING);
        if (!call_info)
        {
            /* ignore, no such call */
            srv_gcall_cntxt_reset_ptr();
            return;
        }

        srv_gcall_phdlr_set_release_call_info(call_info, rsp->result.cause);

        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_REL_OUTGOING, call_info);
    }

    srv_gcall_cntxt_reset_ptr();
}

#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_call_deflect_rsp
 * DESCRIPTION
 *  This Sets the features of the call as per
 * PARSING STR RSP
 *  
 *  
 *  PARSING_STRING_RSP from PS
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_call_deflect_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_call_deflect_rsp_struct *rsp = (mmi_cc_call_deflect_rsp_struct*)info;
    U16 result;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    cm_p->ps_info.rsp_event = 0;
    srv_gcall_reset_ps_event_handler(PRT_CALL_DEFLECT_RSP);

    /* modify the error cause */
    if (rsp->result != KAL_TRUE)
    {
        if (rsp->cause == SRV_GCALL_RESULT_NORMAL_CALL_CLR)
        {
            result = SRV_GCALL_RESULT_L4C_GEN_CAUSE;
        }
        else
        {
            result = rsp->cause;
        }
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_DEFLECT_FAIL, &result);

    }
    else
    {
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_DEFLECT_SUC, NULL);
    }

    srv_gcall_cntxt_reset_ptr();
}
#endif /* __MMI_UCM_DEFLECT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_chld_rsp
 * DESCRIPTION
 *  This Sets the features of the call as per
 * PARSING STR RSP
 *  
 *  
 *  PARSING_STRING_RSP from PS
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_chld_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_chld_rsp_struct *rsp = (mmi_cc_chld_rsp_struct*)info;
    srv_gcall_ps_event_enum event = SRV_GCALL_PS_EVENT_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    if (rsp->opcode != cm_p->ps_info.chld_type)
    {
        /* ignore */
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    cm_p->ps_info.chld_type = CSMCC_INVALID_CRSS_TYPE;
    cm_p->ps_info.rsp_event = 0;
    srv_gcall_reset_ps_event_handler(PRT_END_CHLD_RSP);

    switch (rsp->opcode)
    {
        case CSMCC_REL_SPECIFIC_CALL:
        case CSMCC_REL_ACTIVE:
        case CSMCC_REL_HELD:
        case CSMCC_REL_ALL:
        case CSMCC_REL_ALL_EXCEPT_WAITING_CALL:
    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case CSMCC_VT_FALL_TO_VOICE:
    #endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */
            if (rsp->result != KAL_TRUE)
            {
                event = SRV_GCALL_PS_EVENT_END_FAIL;
            }
            else
            {
                event = SRV_GCALL_PS_EVENT_END_SUC;
            }
            break;

        case CSMCC_SWAP_CALL:
            if (rsp->result != KAL_TRUE)
            {
                event = SRV_GCALL_PS_EVENT_SWAP_FAIL;
            }
            else
            {
                event = SRV_GCALL_PS_EVENT_SWAP_SUC;
            }
            break;

        case CSMCC_ADD_HELD_CALL:
            if (rsp->result != KAL_TRUE)
            {
                event = SRV_GCALL_PS_EVENT_CONF_FAIL;
            }
            else
            {
                event = SRV_GCALL_PS_EVENT_CONF_SUC;
            }
            break;

        case CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL:
            if (rsp->result != KAL_TRUE)
            {
                event = SRV_GCALL_PS_EVENT_SPLIT_FAIL;
            }
            else
            {
                event = SRV_GCALL_PS_EVENT_SPLIT_SUC;
            }
            break;

    #ifdef __MMI_UCM_ECT__
        case CSMCC_EXPLICIT_CALL_TRANSFER:
            if (rsp->result != KAL_TRUE)
            {
                event = SRV_GCALL_PS_EVENT_ECT_FAIL;
            }
            else
            {
                event = SRV_GCALL_PS_EVENT_ECT_SUC;
            }
            break;
    #endif /* __MMI_UCM_ECT__ */

    #ifdef __CCBS_SUPPORT__
        case CSMCC_HOLD_ACTIVE_AND_ACCEPT_CCBS:
            event = SRV_GCALL_PS_EVENT_CCBS_ACCEPT_RES;
            break;

        case CSMCC_ACTIVATE_CCBS_CALL:
            if (rsp->result != KAL_TRUE)
            {
                event = SRV_GCALL_PS_EVENT_CCBS_ACTIVATE_FAIL;
            }
            else
            {
                event = SRV_GCALL_PS_EVENT_CCBS_ACTIVATE_SUC;
            }
            break;
    #endif /* __CCBS_SUPPORT__ */

        default:
            break;
    }

#ifdef __CCBS_SUPPORT__
    if (rsp->opcode == CSMCC_HOLD_ACTIVE_AND_ACCEPT_CCBS)
    {
        srv_gcall_proc_ps_event(event, rsp);
    }
    else
#endif /* __CCBS_SUPPORT__ */
    {
        srv_gcall_proc_ps_event(event, &(rsp->cause));
    }

    srv_gcall_cntxt_reset_ptr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_get_call_list_rsp
 * DESCRIPTION
 *  This Sets the features of the call as per
 * PARSING STR RSP
 *  
 *  
 *  PARSING_STRING_RSP from PS
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_get_call_list_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_get_call_list_rsp_struct *rsp = (mmi_cc_get_call_list_rsp_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gcall_cntxt_set_ptr(srv_gcall_get_interface_with_src_mod(mod_src));

    srv_gcall_reset_ps_event_handler(PTR_GET_CALL_LIST_RSP);

    if (rsp->result != KAL_TRUE)
    {
        /* ignore */
    }
    else
    {
        srv_gcall_proc_ps_event(SRV_GCALL_PS_EVENT_SYNC_CALL_LIST, info);
    }

    srv_gcall_cntxt_reset_ptr();

}


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_phdlr_start_counter_ind
 * DESCRIPTION
 *  
 * PARSING STR RSP
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_start_counter_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim = MMI_SIM_NONE;
    U32 i = 0;
    mmi_vt_start_counter_struct *ind = (mmi_vt_start_counter_struct*)info;
    srv_gcall_call_info_struct *call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((mod_src != MOD_VT) ||
        (ind->start != KAL_TRUE))
    {
        /* ignore */
        return;
    }

    /* assume only one VT calls existed */
    sim = MMI_SIM1;
    for (i = 0 ; i < MMI_MAX_SIM_NUM ; i++, sim = sim << 1)
    {
        srv_gcall_cntxt_set_ptr(sim);
        call_info = srv_gcall_get_call_info(SRV_GCALL_CALL_INFO_BY_CALL_TYPE, (U8)CSMCC_VIDEO_CALL);
        if (call_info)
        {
            break;
        }
        srv_gcall_cntxt_reset_ptr();
    }

    if (!call_info || 
        (call_info->start_count == MMI_TRUE))
    {
        /* no call or start_count has been sent (ex. MO service numbers needs to send start_count right after connect_ind) */
        srv_gcall_cntxt_reset_ptr();
        return;
    }

    switch (call_info->curr_state)
    {
        case SRV_GCALL_STATE_INCOMING:
            /* ignore start_count in MT cases */
            break;

        case SRV_GCALL_STATE_OUTGOING:
            /* start_count was handled before connect_ind, 
             * primitive out of order due to VT task(start_count) has higher priority than L4C (connect_ind)
             */
            /* send start_count to UCM srv later to solve out of order problem */
            call_info->start_count = MMI_TRUE;
            break;

        case SRV_GCALL_STATE_ACTIVE:
            /* MO and active, normal case, start_count is handled after connect_ind */
            call_info->start_count = MMI_TRUE;
            srv_gcall_ucm_start_count_ind(call_info);
            break;

        default:
            /* ignore start_count in all other states */
            break;
    }
    srv_gcall_cntxt_reset_ptr();

}
#endif /* __MMI_VIDEO_TELEPHONY__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_interface_with_src_mod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sim_enum srv_gcall_get_interface_with_src_mod(int src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_frm_l4c_mod_to_sim((module_type)src_mod);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_l4c_mod_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  module id
 *****************************************************************************/
module_type srv_gcall_get_l4c_mod_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_frm_sim_to_l4c_mod(cm_p->interface);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_set_ps_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_set_ps_event_handler(PsExtFuncPtr func, U16 event)
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
 *  srv_gcall_reset_ps_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_reset_ps_event_handler(U16 event)
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
 *  srv_gcall_phdlr_set_release_call_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_phdlr_set_release_call_info(srv_gcall_call_info_struct *call_info, U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->release_call_info.cause = cause;
    cm_p->release_call_info.state = call_info->curr_state;
    cm_p->release_call_info.dir = call_info->dir;
    cm_p->release_call_info.call_id = call_info->call_id;
    cm_p->release_call_info.call_type = call_info->call_type;
    cm_p->release_call_info.group_id = call_info->group_id;
}


