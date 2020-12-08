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
 *  CallSetSrvUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting service interface
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
 * removed!
 * removed!
 * removed!
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
#include "CallSetSrvGprot.h"
#include "CallSetSrvIprot.h"
#include "CallSetSrvProt.h"
#include "SsSrvGprot.h"
#include "mmi_rp_srv_callset_def.h"

#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_available_evt_struct */
#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_notify_struct */

#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "MMI_features.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"
#include "stack_config.h"
#include "rmmi_common_enum.h"
#include "kal_release.h"
#include "stack_msgs.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "csmcc_enums.h"
#include "DebugInitDef_Int.h"
#include "l4c_common_enum.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_callset_set_ps_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_set_ps_event_handler(PsExtFuncPtr func, U16 event)
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
 *  srv_callset_reset_ps_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_reset_ps_event_handler(U16 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearProtocolEventHandler(event);
}


#ifdef __MMI_CALLSET_CALLER_ID__
/*****************************************************************************
 * FUNCTION
 *  SetCallerIdReq
 * DESCRIPTION
 *  Sends caller id request to stack
 * PARAMETERS
 *  void
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_l4c_set_clir_flag_req(srv_callset_caller_id_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_set_clir_flag_req_struct *pMsgReq = NULL;

	static const rmmi_clir_enum flag[] = 
	{
		CLIR_INVOKE,   /* SRV_CALLSET_CALLER_ID_HIDE */
		CLIR_SUPPRESS, /* SRV_CALLSET_CALLER_ID_SHOW */
		CLIR_AUTO, 	   /* SRV_CALLSET_CALLER_ID_BY_NETWORK */
	};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    pMsgReq = OslAllocDataPtr(mmi_ss_set_clir_flag_req_struct);
	ASSERT(mode < SRV_CALLSET_CALLER_ID_TOTAL);
	pMsgReq->clir_flag = flag[mode];
	
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(srv_callset_sim_p->sim), MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ, (oslParaType*)pMsgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_phdlr_update_als_rsp
 * DESCRIPTION
 *  response handler for update als rsp
 * PARAMETERS
 *  info            [IN]    information
 *  mod_src         [IN]    source module id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_phdlr_set_clir_flag_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_set_clir_flag_rsp_struct *local = (mmi_ss_set_clir_flag_rsp_struct*)info;
    srv_callset_result_struct result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_callset_sim_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (srv_callset_sim_p->caller_id_initiated &&
        (srv_callset_p->act_info.op != SRV_CALLSET_OP_CID))
    {
        /* abnormal msg, ignore */
        srv_callset_sim_cntx_reset_ptr();
        return;
    }

    //memset(&result, 0, sizeof(srv_callset_result_struct));
    result.sim = srv_callset_sim_p->sim;
    if (local->result)
    {
        result.result = SRV_CALLSET_RESULT_OK;
		
        if (srv_callset_sim_p->caller_id != srv_callset_sim_p->caller_id_tmp)
        {
        	U16 cache[4] =
			{
				NVRAM_CALLSET_CALLERID,
				#if (MMI_MAX_SIM_NUM >= 2)
				NVRAM_CALLSET_SIM2_CALLERID,
				#if (MMI_MAX_SIM_NUM >= 3)
				NVRAM_CALLSET_SIM3_CALLERID,
				#if (MMI_MAX_SIM_NUM >= 4)
				NVRAM_CALLSET_SIM4_CALLERID
				#endif // 4
				#endif // 3
				#endif // 2
			};
			
			WriteValue(cache[mmi_frm_sim_to_index(srv_callset_sim_p->sim)], 
						&(srv_callset_sim_p->caller_id_tmp), 
						DS_BYTE,
						&error);
			
			srv_callset_sim_p->caller_id = srv_callset_sim_p->caller_id_tmp;
		}
    }
    else
    {
        result.result = SRV_CALLSET_RESULT_UNKNOWN_ERROR;
    }

    srv_callset_sim_p->caller_id_tmp = SRV_CALLSET_CALLER_ID_TOTAL;

    /*amit update here for gemini plus*/
    if (srv_callset_sim_p->caller_id_initiated)
    {
        srv_callset_post_rsp_evt(SRV_CALLSET_OP_CID, &result);
    }
    else
    {
        srv_callset_sim_p->caller_id_initiated = MMI_TRUE;
    }

    srv_callset_sim_cntx_reset_ptr();
}
#endif /* __MMI_CALLSET_CALLER_ID__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_l4c_update_als_req
 * DESCRIPTION
 *  send update als request to l4c
 * PARAMETERS
 *  line_id     [IN]    line id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_l4c_update_als_req(srv_callset_line_id_enum line_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_update_als_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = OslAllocDataPtr(mmi_cphs_update_als_req_struct);

    msg->line_id = (line_id == SRV_CALLSET_LINE1) ? 0 : 1;

    srv_callset_set_ps_event_handler(srv_callset_phdlr_update_als_rsp, MSG_ID_MMI_CPHS_UPDATE_ALS_RSP);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(srv_callset_sim_p->sim), MSG_ID_MMI_CPHS_UPDATE_ALS_REQ, (oslParaType*)msg, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_phdlr_update_als_rsp
 * DESCRIPTION
 *  response handler for update als rsp
 * PARAMETERS
 *  info            [IN]    information
 *  mod_src         [IN]    source module id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_phdlr_update_als_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_update_als_rsp_struct *local;
    srv_callset_result_struct result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = (mmi_cphs_update_als_rsp_struct*)info;

    srv_callset_sim_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    srv_callset_reset_ps_event_handler(MSG_ID_MMI_CPHS_UPDATE_ALS_RSP);

    memset(&result, 0, sizeof(srv_callset_result_struct));
    result.sim = srv_callset_sim_p->sim;
    if (local->res == MMI_TRUE)
    {
        result.result = SRV_CALLSET_RESULT_OK;
        srv_callset_sim_p->line_id = srv_callset_sim_p->line_id_tmp;
        srv_callset_sim_p->line_id_tmp = SRV_CALLSET_LINE_END_OF_ENUM;
    }
    else
    {
        result.result = SRV_CALLSET_RESULT_UNKNOWN_ERROR;
    }

    srv_callset_post_lsw_ind_evt(srv_callset_sim_p->sim, srv_callset_sim_p->line_id);

    srv_callset_post_rsp_evt(SRV_CALLSET_OP_LINE_SWITCH, &result);

    srv_callset_sim_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_phdlr_display_als_ind
 * DESCRIPTION
 *  handler for display als indication
 * PARAMETERS
 *  info            [IN]    information
 *  mod_src         [IN]    source module id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_phdlr_display_als_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_display_als_ind_struct *localPtr = (mmi_cphs_display_als_ind_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* report the status even when callset is not available. 
     * APP decides how to handle the indication (ex. display status icon or not) */

    srv_callset_sim_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (localPtr->line == 1)
    {
        srv_callset_sim_p->line_id = SRV_CALLSET_LINE2;
    }
    else
    {
        srv_callset_sim_p->line_id = SRV_CALLSET_LINE1;
    }

    if (srv_callset_is_available(srv_callset_sim_p->sim) &&
         srv_callset_is_line_switch_supported(srv_callset_sim_p->sim))
    {
        /* need to check if als is supported due to L4 still sends DISPLAY_ALS_IND
         * and assign line id event when als is not supported) */
        srv_callset_post_lsw_ind_evt(srv_callset_sim_p->sim, srv_callset_sim_p->line_id);
    }
    /* don't send line_switch_ind if als is not support or not available */

    srv_callset_sim_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_phdlr_display_cfu_ind
 * DESCRIPTION
 *  handler for display cfu indication
 * PARAMETERS
 *  info            [IN]    information
 *  mod_src         [IN]    source module id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_phdlr_display_cfu_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_display_cfu_ind_struct *ind = (mmi_cphs_display_cfu_ind_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* report the status even when callset is not available. 
     * APP decides how to handle the indication (ex. display status icon or not) */

    srv_callset_sim_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

    if (ind->action)
    {
        if (ind->line_num == 1)
        {
            srv_callset_sim_p->cfu_status |= SRV_CALLSET_CFU_LINE2_ACTIVATED;
        }
        else
        {
            srv_callset_sim_p->cfu_status |= SRV_CALLSET_CFU_LINE1_ACTIVATED;
        }
    
    }
    else
    {
        if (ind->line_num == 1)
        {
            srv_callset_sim_p->cfu_status &= ~SRV_CALLSET_CFU_LINE2_ACTIVATED;
        }
        else
        {
            srv_callset_sim_p->cfu_status &= ~SRV_CALLSET_CFU_LINE1_ACTIVATED;
        }
    }

    if (srv_callset_is_available(srv_callset_sim_p->sim) &&
         srv_ss_check_capability(
            srv_callset_sim_p->sim, 
            SRV_SS_ACT_CALL_FORWARD, 
            SRV_SS_CALL_FORWARD_CFU, 
            SRV_SS_ALL_CALL))
    {
        /* need to check if cfu is supported due to L4 still sends DISPLAY_CFU_IND 
         * and assign cfu_status even when cfu is not supported */
        srv_callset_post_cfu_status_evt(srv_callset_sim_p->sim, srv_callset_sim_p->cfu_status);
    }
    /* don't send cfu_status_ind if cfu is not support or not available */

    srv_callset_sim_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_hdlr_sim_availability_changed
 * DESCRIPTION
 *  handler for sim availability changed event
 * PARAMETERS
 *  info    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_callset_hdlr_sim_availability_changed(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *evt = (srv_sim_ctrl_availability_changed_evt_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->is_available_before == evt->is_available_now)
    {
        return MMI_RET_OK;
    }

    srv_callset_post_lsw_ind_evt(evt->sim, srv_callset_line_switch_get_id(evt->sim));
    srv_callset_post_cfu_status_evt(evt->sim, srv_callset_cfu_get_status(evt->sim));

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_hdlr_mode_switched
 * DESCRIPTION
 *  handler for mode switched event
 * PARAMETERS
 *  info    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_callset_hdlr_mode_switched(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *evt = (srv_mode_switch_notify_struct*)info;
	srv_mode_switch_type_enum switch_bits;
	mmi_sim_enum sim;
	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
		sim = mmi_frm_index_to_sim(i);
		/* SRV_MOD_SWITCH_SIMX must have  the same bit value with MMI_SIMX. */
		switch_bits = (srv_mode_switch_type_enum)sim;
	    if ((switch_bits & evt->gsm_curr_mode) != (switch_bits & evt->gsm_select_mode))
	    {
	        srv_callset_post_lsw_ind_evt(sim, srv_callset_line_switch_get_id(sim));
	        srv_callset_post_cfu_status_evt(sim, srv_callset_cfu_get_status(sim));
	    }
	}
	
    return MMI_RET_OK;
}


#ifdef __MMI_CALLSET_CUG__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_l4c_set_cug_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cug_id  [IN]    CUG ID
 *  activate    [IN] MMI_FALSE if deactivate
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_l4c_set_cug_req(U8 cug_id, MMI_BOOL activate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_set_cug_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dataPtr = OslAllocDataPtr(mmi_cc_set_cug_req_struct);
    dataPtr->index = cug_id;
    dataPtr->mode = activate ? CSMCC_ENABLE_CUG_TEMPORARY_MODE : CSMCC_DISABLE_CUG_TEMPORARY_MODE;
    dataPtr->info = 0;

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(srv_callset_sim_p->sim), MSG_ID_MMI_CC_SET_CUG_REQ, (oslParaType*)dataPtr, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_phdlr_set_cug_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info            [IN]    information
 *  mod_src         [IN]    source module id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_phdlr_set_cug_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_set_cug_rsp_struct *rsp = (mmi_cc_set_cug_rsp_struct*)info;
    srv_callset_result_struct result;
    S16 error;
    U16 id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_callset_sim_cntx_set_ptr(mmi_frm_l4c_mod_to_sim((module_type)mod_src));

	id = NVRAM_CALLSET_CUG_ACTIVATED_ID + mmi_frm_sim_to_index(srv_callset_sim_p->sim);

    if (srv_callset_sim_p->cug_initiated)
    {
        memset(&result, 0, sizeof(srv_callset_result_struct));
        result.sim = srv_callset_sim_p->sim;
        if (rsp->result)
        {
            result.result = SRV_CALLSET_RESULT_OK;

            if (srv_callset_p->act_info.op == SRV_CALLSET_OP_CUG_ACTIVATE)
            {
                srv_callset_sim_p->cug_activated_id = srv_callset_sim_p->cug_temp_id;
            }
            else if (srv_callset_p->act_info.op == SRV_CALLSET_OP_CUG_DEACTIVATE)
            {
                srv_callset_sim_p->cug_activated_id = 0xff;
            }
            else
            {
                MMI_ASSERT(0);
            }
            WriteValue(id, &(srv_callset_sim_p->cug_activated_id), DS_BYTE, &error);
        }
        else
        {
            result.result = SRV_CALLSET_RESULT_UNKNOWN_ERROR;
        }

        srv_callset_sim_p->cug_temp_id = 0xff;
        srv_callset_post_rsp_evt(srv_callset_p->act_info.op, &result);
    }
    else /* (srv_callset_sim_p->cug_initiated) */
    {
        if (!rsp->result)
        {
            srv_callset_sim_p->cug_activated_id = 0xff;
            WriteValue(id, &(srv_callset_sim_p->cug_activated_id), DS_BYTE, &error);
        }
        srv_callset_sim_p->cug_initiated = MMI_TRUE;
    }

    srv_callset_sim_cntx_reset_ptr();
}

#endif /* __MMI_CALLSET_CUG__ */


#ifdef __CTM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_post_ctm_setting_changed_ind_evt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 * RETURNS
 *  result
 *****************************************************************************/
void srv_callset_post_ctm_setting_changed_ind_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ctm_setting_changed_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_POST_CTM_SETTING_CHANGED_IND_EVT, srv_callset_ctm_get_mode(), srv_callset_ctm_get_setting());

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CALLSET_CTM_SETTING_CHANGED);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

#endif /* __CTM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_post_rsp_evt
 * DESCRIPTION
 *  The function to post response to the caller
 * PARAMETERS
 *  op          [IN]    action op code
 *  info        [IN]    Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_post_rsp_evt(srv_callset_op_enum op, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_rsp_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_p->act_info.op == SRV_CALLSET_OP_IDLE)
    {
        MMI_ASSERT(0);
    }
    
    if (!(srv_callset_p->act_info.rsp_cb))
    {
        memset(&(srv_callset_p->act_info), 0, sizeof(srv_callset_p->act_info));
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_POST_RSP_EVT_IGNORE);
        return;
    }

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CALLSET_ACT_RESPONSE);

    switch (op)
    {
        case SRV_CALLSET_OP_CID:
        case SRV_CALLSET_OP_LINE_SWITCH:
        case SRV_CALLSET_OP_CUG_ACTIVATE:
        case SRV_CALLSET_OP_CUG_DEACTIVATE:
            evt.data = OslMalloc(sizeof(srv_callset_result_struct));
            memset(evt.data, 0, sizeof(srv_callset_result_struct));
            memcpy(evt.data, info, sizeof(srv_callset_result_struct));
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_POST_RSP_EVT,
                ((srv_callset_result_struct*)(evt.data))->sim,
                ((srv_callset_result_struct*)(evt.data))->result);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    MMI_FRM_POST_EVENT_EX(
        (mmi_event_struct*)&evt, 
        srv_callset_p->act_info.rsp_cb, 
        srv_callset_p->act_info.rsp_user_data, 
        srv_callset_post_rsp_evt_cb, 
        evt.data);

    memset(&(srv_callset_p->act_info), 0, sizeof(srv_callset_p->act_info));
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_post_rsp_evt_cb
 * DESCRIPTION
 *  The callback function after posting resposne event is done
 * PARAMETERS
 *  result_evt:        [IN]        result structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_callset_post_rsp_evt_cb(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_POST_RSP_EVT_CB, result_evt->user_data);

    if (result_evt->user_data != NULL)
    {
        OslMfree(result_evt->user_data);
        result_evt->user_data = NULL;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_gcall_post_act_evt
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
void srv_callset_post_act_evt(srv_callset_op_enum op, void *info, mmi_proc_func rsp_cb, void *rsp_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_act_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CALLSET_INT_ACT);
    evt.op = op;
    switch (op)
    {
        case SRV_CALLSET_OP_LINE_SWITCH:
            evt.info = OslMalloc(sizeof(srv_callset_line_switch_struct));
            memcpy(evt.info, info, sizeof(srv_callset_line_switch_struct));
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_POST_ACT_EVT
                , op
                , rsp_cb
                , rsp_user_data
                , ((srv_callset_line_switch_struct*)(evt.info))->sim
                , ((srv_callset_line_switch_struct*)(evt.info))->line_id);
            break;

        default:
            evt.info = NULL;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_POST_ACT_EVT
                , op
                , rsp_cb
                , rsp_user_data
                , 0
                , 0);
            break;
    }
    evt.rsp_user_data = rsp_user_data;
    evt.rsp_cb = rsp_cb;
    
    MMI_FRM_POST_EVENT(&evt, srv_callset_post_act_evt_hdlr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_post_act_evt_hdlr
 * DESCRIPTION
 *  handler for action event
 * PARAMETERS
 *  para    [IN]    parameters
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_callset_post_act_evt_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_act_evt_struct *evt = (srv_callset_act_evt_struct*)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, 
    		TRC_SRV_CALLSET_POST_ACT_EVT_HDLR, 
    		evt->op, 
    		evt->rsp_cb, 
    		evt->rsp_user_data,
    		evt->info);

    if (evt->op == SRV_CALLSET_OP_LINE_SWITCH)
    {
        srv_callset_line_switch_set_id(
            (srv_callset_line_switch_struct*)evt->info, 
            evt->rsp_cb, 
            evt->rsp_user_data);
    }

    if (evt->info)
    {
        OslMfree(evt->info);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_post_lsw_ind_evt
 * DESCRIPTION
 *  post line switched indication event
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_callset_post_lsw_ind_evt(mmi_sim_enum sim, srv_callset_line_id_enum line_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_line_switched_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CALLSET_LINE_SWITCHED);
    evt.sim = sim;
    evt.active_line = line_id;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_POST_LSW_IND_EVT, evt.sim, evt.active_line);
    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_post_cfu_status_evt
 * DESCRIPTION
 *  post CFU status indication event
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_callset_post_cfu_status_evt(mmi_sim_enum sim, srv_callset_cfu_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_cfu_status_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CALLSET_CFU_STATUS_IND);

    evt.sim = sim;
    evt.status = status;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_POST_CFU_STATUS_EVT, evt.sim, evt.status);

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

