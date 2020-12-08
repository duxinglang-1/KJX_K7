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
 *  CallSetSrvStructMgmt.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting service context management
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "CallSetSrvProt.h"
#include "CallSetSrvIprot.h"
#include "mmi_rp_srv_callset_def.h"

#include "UcmSrvGprot.h" /* SRV_UCM_MAX_NUM_URI_LEN */
#include "PhbSrvGprot.h" /* srv_phb_sse_convert_number_to_int */
#include "GpioSrvGprot.h" /* srv_earphone_is_plug_in */
#include "SsSrvGprot.h" /* srv_ss_check_capability */
#include "SsSrvProt.h"  /* srv_ss_is_valid_sim */
#include "sim_public_api.h" /* is_test_sim */
#include "Ps_public_utility.h" /* l4c_gemini_get_switched_sim_id */
#include "Sim_public_enum.h" /* sim_interface_enum */


#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "string.h"
#include "MMI_features.h"
#include "stack_msgs.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "nvram_enums.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#include "Unicodexdcl.h"
#include "sim_common_enums.h"
#include "mmi_frm_events_gprot.h"
#include "kal_release.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __IP_NUMBER__
static const U16 srv_callset_ipnum_cache_id[] = 
{
	NVRAM_CALLSET_IP_NUMBER_SETTING,
#if (MMI_MAX_SIM_NUM >= 2)
	NVRAM_CALLSET_IP_NUMBER_SETTING_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
	NVRAM_CALLSET_IP_NUMBER_SETTING_SIM3,
#if (MMI_MAX_SIM_NUM >= 4)
	NVRAM_CALLSET_IP_NUMBER_SETTING_SIM4
#endif /*MMI_MAX_SIM_NUM>=4*/
#endif /*MMI_MAX_SIM_NUM>=3*/
#endif /* (MMI_MAX_SIM_NUM >= 2) */

};
#endif /* __IP_NUMBER__ */

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
static srv_callset_context_struct g_srv_callset_context;
srv_callset_context_struct *srv_callset_p = &g_srv_callset_context;
srv_callset_sim_cntx_struct *srv_callset_sim_p;



/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_callset_is_busy
 * DESCRIPTION
 *  check if call setting service is busy
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if it is busy
 *****************************************************************************/
MMI_BOOL srv_callset_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_p->act_info.op != SRV_CALLSET_OP_IDLE)
    {
        /* callset service is waiting for response */
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_early_init
 * DESCRIPTION
 *  call setting service initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_early_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	// TODO: remove memset
    memset(srv_callset_p, 0, sizeof(srv_callset_context_struct));

	for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
		srv_callset_init_sim(mmi_frm_index_to_sim(i));	
	}

#ifdef __MMI_CALLSET_CALLER_ID__
    srv_callset_set_ps_event_handler(srv_callset_phdlr_set_clir_flag_rsp, MSG_ID_MMI_SS_SET_CLIR_FLAG_RSP);
#endif /* __MMI_CALLSET_CALLER_ID__ */
#ifdef __MMI_CALLSET_CUG__
    srv_callset_set_ps_event_handler(srv_callset_phdlr_set_cug_rsp, MSG_ID_MMI_CC_SET_CUG_RSP);
#endif /* __MMI_CALLSET_CUG__ */
    srv_callset_set_ps_event_handler(srv_callset_phdlr_display_als_ind, MSG_ID_MMI_CPHS_DISPLAY_ALS_IND);
    srv_callset_set_ps_event_handler(srv_callset_phdlr_display_cfu_ind, MSG_ID_MMI_CPHS_DISPLAY_CFU_IND);	
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_init
 * DESCRIPTION
 *  call setting service initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if	defined(__MMI_CALLSET_CALLER_ID__) || defined(__MMI_CALLSET_CUG__)
	U32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if	defined(__MMI_CALLSET_CALLER_ID__) || defined(__MMI_CALLSET_CUG__)
	for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
#ifdef __MMI_CALLSET_CALLER_ID__
		srv_callset_init_caller_id(mmi_frm_index_to_sim(i));
#endif
#ifdef __MMI_CALLSET_CUG__
		srv_callset_init_cug(mmi_frm_index_to_sim(i));
#endif
	}
#endif /* defined */
	
#ifdef __CTM_SUPPORT__
    srv_callset_init_ctm();
#endif /* __CTM_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_sim
 * DESCRIPTION
 *  call setting service sim-related initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_sim(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_callset_sim_cntx_set_ptr(sim);
	
    srv_callset_sim_p->sim = sim;
#ifdef __MMI_CALLSET_CALLER_ID__
    srv_callset_sim_p->caller_id = SRV_CALLSET_CALLER_ID_TOTAL;
    srv_callset_sim_p->caller_id_tmp = SRV_CALLSET_CALLER_ID_TOTAL;
#endif /* __MMI_CALLSET_CALLER_ID__ */

    srv_callset_sim_p->line_id = SRV_CALLSET_LINE_NOT_SUPPORT;
    srv_callset_sim_p->line_id_tmp = SRV_CALLSET_LINE_END_OF_ENUM;
    srv_callset_sim_p->cfu_status = SRV_CALLSET_CFU_NOT_SUPPORT;
	
#ifdef __MMI_CALLSET_CUG__
    srv_callset_sim_p->cug_activated_id = 0xff;
    srv_callset_sim_p->cug_temp_id = 0xff;
#endif /* __MMI_CALLSET_CUG__ */

    srv_callset_sim_cntx_reset_ptr();
}


#ifdef __MMI_CALLSET_CALLER_ID__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_caller_id
 * DESCRIPTION
 *  initialiation for caller id, lazy init
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_caller_id(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

	U16 cache[] = 
	{
		NVRAM_CALLSET_CALLERID,
#if (MMI_MAX_SIM_NUM >= 2)
		NVRAM_CALLSET_SIM2_CALLERID,
#if (MMI_MAX_SIM_NUM>=3)
		NVRAM_CALLSET_SIM3_CALLERID,
#if (MMI_MAX_SIM_NUM>=4)
		NVRAM_CALLSET_SIM4_CALLERID
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
	};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_callset_sim_cntx_set_ptr(sim);

    ReadValue(cache[mmi_frm_sim_to_index(srv_callset_sim_p->sim)],
				&(srv_callset_sim_p->caller_id_tmp),
				DS_BYTE, 
				&error);

    if (srv_callset_sim_p->caller_id_tmp >= SRV_CALLSET_CALLER_ID_TOTAL)
    {
        srv_callset_sim_p->caller_id_tmp = SRV_CALLSET_CALLER_ID_BY_NETWORK;
    }

    srv_callset_l4c_set_clir_flag_req(srv_callset_sim_p->caller_id_tmp);

    srv_callset_sim_cntx_reset_ptr();
}



/*****************************************************************************
 * FUNCTION
 *  srv_callset_caller_id_set_mode
 * DESCRIPTION
 *  to set caller id mode.
 * PARAMETERS
 *  info : [IN] parameters
 *  callback : [IN] scallback to notify the result. srv_callset_rsp_evt_struct(srv_callset_result_struct)
 *  user_data : [IN] user data
 * RETURNS
 *  srv_callset_result_enum, not OK if the request is rejected directly by callset service
 *****************************************************************************/
srv_callset_result_enum srv_callset_caller_id_set_mode(srv_callset_cid_set_mode_struct *info, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_enum result;
    srv_callset_act_info_struct ori_act;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_is_busy() || srv_callset_sim_cntx_is_locked())
    {
        result = SRV_CALLSET_RESULT_BUSY;
        /* ori op */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CALLER_ID_SET_MODE
            , result, info, srv_callset_p->act_info.op, srv_callset_sim_p);

        /* use new op for rsp */
        memcpy(&ori_act, &srv_callset_p->act_info, sizeof(srv_callset_act_info_struct));
        srv_callset_p->act_info.op = SRV_CALLSET_OP_CID;
        srv_callset_p->act_info.rsp_cb = callback;
        srv_callset_p->act_info.rsp_user_data = user_data;

        srv_callset_post_rsp_evt(SRV_CALLSET_OP_CID, &result);

        /* restore ori op */
        memcpy(&srv_callset_p->act_info, &ori_act, sizeof(srv_callset_act_info_struct));

        return result;
    }

    srv_callset_p->act_info.op = SRV_CALLSET_OP_CID;
    srv_callset_p->act_info.rsp_cb = callback;
    srv_callset_p->act_info.rsp_user_data = user_data;

    if (!info ||
  		!srv_ss_is_valid_sim(info->sim) ||
        (info->mode >= SRV_CALLSET_CALLER_ID_TOTAL))
    {
        result = SRV_CALLSET_RESULT_INVALID_INPUT;
        if (info)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CALLER_ID_SET_MODE
                , result, info, info->sim, info->mode);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CALLER_ID_SET_MODE
                , result, info, 0, 0);
        }

        srv_callset_post_rsp_evt(SRV_CALLSET_OP_CID, &result);
    }
    else
    {
        srv_callset_sim_cntx_set_ptr(info->sim);
        srv_callset_sim_p->caller_id_tmp = info->mode;
        srv_callset_l4c_set_clir_flag_req(info->mode);
        srv_callset_sim_cntx_reset_ptr();

        result = SRV_CALLSET_RESULT_OK;
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CALLER_ID_SET_MODE
            , result, info, info->sim, info->mode);
    }

    return result;
}
                     

/*****************************************************************************
 * FUNCTION
 *  srv_callset_caller_id_get_mode
 * DESCRIPTION
 *  to get caller id mode.
 * PARAMETERS
 *  sim : [IN] which sim
 * RETURNS
 *  srv_callset_caller_id_mode_enum : caller id mode
 *****************************************************************************/
srv_callset_caller_id_mode_enum srv_callset_caller_id_get_mode(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_callset_p->sim_cntx[mmi_frm_sim_to_index(sim)].caller_id; 
}
#endif /* __MMI_CALLSET_CALLER_ID__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_line_switch_get_id
 * DESCRIPTION
 *  to get line switch mode.
 * PARAMETERS
 *  sim : [IN] which sim
 * RETURNS
 *  srv_callset_line_id_enum : line id
 *****************************************************************************/
srv_callset_line_id_enum srv_callset_line_switch_get_id(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_line_id_enum line_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	line_id = srv_callset_p->sim_cntx[mmi_frm_sim_to_index(sim)].line_id;

    if (!srv_callset_is_available(sim) ||
         !srv_callset_is_line_switch_supported(sim))
    {
        /* srv not available or doesn't support ALS */
        /* need to check if als is supported due to L4 still sends DISPLAY_ALS_IND
         * and assign line id event when als is not supported) */
        return SRV_CALLSET_LINE_NOT_SUPPORT;
    }
    else
    {
        return line_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cfu_get_status
 * DESCRIPTION
 *  to get cfu status.
 * PARAMETERS
 *  sim : [IN] which sim
 * RETURNS
 *  srv_callset_cfu_status_enum : cfu status
 *****************************************************************************/
srv_callset_cfu_status_enum srv_callset_cfu_get_status(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_cfu_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	status = srv_callset_p->sim_cntx[mmi_frm_sim_to_index(sim)].cfu_status;

    if (!srv_callset_is_available(sim) ||
         !srv_ss_check_capability(
            sim, 
            SRV_SS_ACT_CALL_FORWARD, 
            SRV_SS_CALL_FORWARD_CFU, 
            SRV_SS_ALL_CALL))
    {
        /* srv not available or doesn't support CFU */
        /* need to check if cfu is supported due to L4 still sends DISPLAY_CFU_IND 
         * and assign cfu_status even when cfu is not supported */
        return SRV_CALLSET_CFU_NOT_SUPPORT;
    }
    else
    {
        return status;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_line_switch_set_id
 * DESCRIPTION
 *  to set line switch mode.
 * PARAMETERS
 *  info : [IN] parameters
 *  callback : [IN] callback to notify the result. srv_callset_rsp_evt_struct(srv_callset_result_struct)
 *  user_data : [IN] user data
 * RETURNS
 *  srv_callset_result_enum, not OK if the request is rejected directly by callset service
 *****************************************************************************/
srv_callset_result_enum srv_callset_line_switch_set_id(srv_callset_line_switch_struct *info, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_enum result;
    srv_callset_result_struct rsp;
    srv_callset_act_info_struct ori_act;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_is_busy() || srv_callset_sim_cntx_is_locked())
    {
        /* ori op */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_LINE_SWITCH_SET_ID
            , SRV_CALLSET_RESULT_BUSY, info, srv_callset_p->act_info.op, srv_callset_sim_p);

        /* use new op for rsp */
        memcpy(&ori_act, &srv_callset_p->act_info, sizeof(srv_callset_act_info_struct));
        srv_callset_p->act_info.op = SRV_CALLSET_OP_LINE_SWITCH;
        srv_callset_p->act_info.rsp_cb = callback;
        srv_callset_p->act_info.rsp_user_data = user_data;

        memset(&rsp, 0, sizeof(srv_callset_result_struct));
        rsp.sim = info->sim;
        rsp.result = SRV_CALLSET_RESULT_BUSY;
        srv_callset_post_rsp_evt(SRV_CALLSET_OP_LINE_SWITCH, &rsp);

        /* restore ori op */
        memcpy(&srv_callset_p->act_info, &ori_act, sizeof(srv_callset_act_info_struct));

        return SRV_CALLSET_RESULT_BUSY;
    }

    srv_callset_p->act_info.op = SRV_CALLSET_OP_LINE_SWITCH;
    srv_callset_p->act_info.rsp_cb = callback;
    srv_callset_p->act_info.rsp_user_data = user_data;

    if (!info ||
        !srv_ss_is_valid_sim(info->sim) ||
        ((info->line_id != SRV_CALLSET_LINE1) && (info->line_id != SRV_CALLSET_LINE2)))
    {
        result =  SRV_CALLSET_RESULT_INVALID_INPUT;
        if (info)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_LINE_SWITCH_SET_ID
                , result, info, info->sim, info->line_id);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_LINE_SWITCH_SET_ID
                , result, info, 0, 0);
        }
    }
    else if (!srv_callset_is_line_switch_supported(info->sim))
    {
        result = SRV_CALLSET_RESULT_NOT_AVAILABLE;
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_LINE_SWITCH_SET_ID
            , result, info, info->sim, info->line_id);
    }
    else if (info->line_id == srv_callset_line_switch_get_id(info->sim))
    {
        result = SRV_CALLSET_RESULT_OK;

        /* do nothing */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_LINE_SWITCH_SET_ID_IGNORE);

        /* send rsp directly */
        memset(&rsp, 0, sizeof(srv_callset_result_struct));
        rsp.sim = info->sim;
        rsp.result = result;
        srv_callset_post_rsp_evt(SRV_CALLSET_OP_LINE_SWITCH, &rsp);
    }
    else
    {
        srv_callset_sim_cntx_set_ptr(info->sim);
        srv_callset_sim_p->line_id_tmp = info->line_id;
        srv_callset_l4c_update_als_req(info->line_id);
        srv_callset_sim_cntx_reset_ptr();

        result = SRV_CALLSET_RESULT_OK;
        /* success scenario, need to wait for rsp from L4C */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_LINE_SWITCH_SET_ID
            , result, info, info->sim, info->line_id);
    }

    if (result != SRV_CALLSET_RESULT_OK)
    {
        memset(&rsp, 0, sizeof(srv_callset_result_struct));
        rsp.sim = info->sim;
        rsp.result = result;
        srv_callset_post_rsp_evt(SRV_CALLSET_OP_LINE_SWITCH, &rsp);
    }

    return result;
}


#ifdef __MMI_CALLSET_CUG__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_cug
 * DESCRIPTION
 *  closed user group initialization
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_cug(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    U32 i;
    nvram_lid_enum lid;
    U16 id;

	static const U16 group_list_id[] = 
	{
		NVRAM_EF_GROUPLIST_LID,
#if (MMI_MAX_SIM_NUM >= 2)
		NVRAM_EF_GROUPLIST_SIM2_LID,
#endif
#if (MMI_MAX_SIM_NUM>=3)
		NVRAM_EF_GROUPLIST_SIM3_LID,
#endif
#if (MMI_MAX_SIM_NUM>=4)
		NVRAM_EF_GROUPLIST_SIM4_LID
#endif
	};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_callset_sim_cntx_set_ptr(sim);

	lid = group_list_id[mmi_frm_sim_to_index(srv_callset_sim_p->sim)];
	id = NVRAM_CALLSET_CUG_ACTIVATED_ID + mmi_frm_sim_to_index(srv_callset_sim_p->sim);
	
    for (i = 0; i < SRV_CALLSET_CUG_MAX_GROUP_NUM; i++)
    {
        ReadRecord(
            lid,
            (U16)(i + 1),
            &(srv_callset_sim_p->cug_list[i]),
            sizeof(srv_callset_cug_item_struct),
            &error);
    }

    ReadValue(id, &data, DS_BYTE, &error);   
    if (data < SRV_CALLSET_CUG_MAX_GROUP_NUM)
    {
        srv_callset_sim_p->cug_activated_id = data;
        srv_callset_l4c_set_cug_req(data, MMI_TRUE);
    }
    else if (data == 0xff)
    {
        srv_callset_sim_p->cug_activated_id = data;
        srv_callset_sim_p->cug_initiated = MMI_TRUE;
    }
    else
    {
        data = 0xff;
        srv_callset_sim_p->cug_activated_id = data;
        WriteValue(id, &data, DS_BYTE, &error);
        srv_callset_sim_p->cug_initiated = MMI_TRUE;
    }

    srv_callset_sim_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_modify
 * DESCRIPTION
 *  to modify the CUG name of a specific CUG index
 * PARAMETERS
 *  sim : [IN] which sim
 *  item : [IN] new CUG name and cug_id, index is used to find the target CUG item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_cug_set_item(mmi_sim_enum sim, srv_callset_cug_set_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_lid_enum lid;
	
	static const U16 group_list_id[] = 
	{
		NVRAM_EF_GROUPLIST_LID,
#if (MMI_MAX_SIM_NUM >= 2)
		NVRAM_EF_GROUPLIST_SIM2_LID,
#endif
#if (MMI_MAX_SIM_NUM>=3)
		NVRAM_EF_GROUPLIST_SIM3_LID,
#endif
#if (MMI_MAX_SIM_NUM>=4)
		NVRAM_EF_GROUPLIST_SIM4_LID
#endif
	};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*For gemini plus we need to modify the below check AMIT UPDATE HERE FOR GEMINI PLUS*/
    if (!srv_ss_is_valid_sim(sim) ||
        !item ||
        (item->cug_id >= SRV_CALLSET_CUG_MAX_GROUP_NUM))
    {
        if (item)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_SET_ITEM
                , SRV_CALLSET_RESULT_INVALID_INPUT, sim, item, item->cug_id);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_SET_ITEM
                , SRV_CALLSET_RESULT_INVALID_INPUT, sim, item, 0);
        }
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    srv_callset_sim_cntx_set_ptr(sim);

	lid = group_list_id[mmi_frm_sim_to_index(sim)];

    if (WriteRecord(lid, (U16)(item->cug_id + 1), item->name,
                 NVRAM_MAX_GROUP_NAME_SIZE, &error) < sizeof(item->name))
    {
        srv_callset_sim_cntx_reset_ptr();
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_SET_ITEM
            , SRV_CALLSET_RESULT_UNKNOWN_ERROR, sim, item, item->cug_id);
        return SRV_CALLSET_RESULT_UNKNOWN_ERROR;
    }
    else
    {
        memcpy(&(srv_callset_sim_p->cug_list[item->cug_id]), item->name, sizeof(item->name));

        srv_callset_sim_cntx_reset_ptr();
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_SET_ITEM
            , SRV_CALLSET_RESULT_OK, sim, item, item->cug_id);
        return SRV_CALLSET_RESULT_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_get_item
 * DESCRIPTION
 *  to get the cug item by index
 * PARAMETERS
 *  sim : [IN] which sim
 *  cug_id : [IN] CUG ID
 *  item : [OUT] CUG item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_cug_get_item(mmi_sim_enum sim, U8 cug_id, srv_callset_cug_get_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (item)
    {
        memset(item, 0, sizeof(srv_callset_cug_get_item_struct));
    }
	/*AMIT UPDATE HERE FOR GEMINI PLUS*/
    if (!srv_ss_is_valid_sim(sim) ||
        (cug_id >= SRV_CALLSET_CUG_MAX_GROUP_NUM) ||
        !item)
    {

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_GET_ITEM
                , SRV_CALLSET_RESULT_INVALID_INPUT, sim, cug_id, item);
		
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    srv_callset_sim_cntx_set_ptr(sim);

    if (!(srv_callset_sim_p->cug_initiated))
    {
        srv_callset_sim_cntx_reset_ptr();
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_GET_ITEM
            , SRV_CALLSET_RESULT_UNKNOWN_ERROR, sim, cug_id, item);
        return SRV_CALLSET_RESULT_UNKNOWN_ERROR;
    }

    mmi_ucs2ncpy((CHAR*)(item->name), (CHAR*)(srv_callset_sim_p->cug_list[cug_id].name), SRV_CALLSET_CUG_MAX_NAME_LENGTH);
    item->status = (cug_id == srv_callset_sim_p->cug_activated_id) ?
                        SRV_CALLSET_CUG_ACTIVATED : SRV_CALLSET_CUG_DEACTIVATED;

    srv_callset_sim_cntx_reset_ptr();

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_GET_ITEM
        , SRV_CALLSET_RESULT_OK, sim, cug_id, item);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_get_actviated_item
 * DESCRIPTION
 *  to get the activated CUG ID
 * PARAMETERS
 *  sim : [IN] which sim 
 * RETURNS
 *  U8 : activated index (0~9), 0xff if no activated item
 *****************************************************************************/
U8 srv_callset_cug_get_actviated_id(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return srv_callset_p->sim_cntx[mmi_frm_sim_to_index(sim)].cug_activated_id;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_activate
 * DESCRIPTION
 *  to activate the CUG index. the original activated CUG will be deactivated as well.
 * PARAMETERS
 *  info : [IN] parameters
 *  callback : [IN] callback to notify the result. srv_callset_rsp_evt_struct(srv_callset_result_struct)
 *  user_data : [IN] user data
 * RETURNS
 *  srv_callset_result_enum, not OK if the request is rejected directly by callset service
 *****************************************************************************/
srv_callset_result_enum srv_callset_cug_activate(srv_callset_cug_activate_struct *info, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/*AMIT UPDATE HERE FOR GEMINI PLUS*/
    if (!info ||
        !srv_ss_is_valid_sim(info->sim) || 
        (info->cug_id >= SRV_CALLSET_CUG_MAX_GROUP_NUM))
    {

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_ACTIVATE
                , SRV_CALLSET_RESULT_INVALID_INPUT, info, info->sim, info->cug_id);

        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (srv_callset_is_busy() || srv_callset_sim_cntx_is_locked())
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_ACTIVATE
            , SRV_CALLSET_RESULT_BUSY, info, srv_callset_p->act_info.op, srv_callset_sim_p);
        return SRV_CALLSET_RESULT_BUSY;
    }

    srv_callset_sim_cntx_set_ptr(info->sim);

    srv_callset_p->act_info.op = SRV_CALLSET_OP_CUG_ACTIVATE;
    srv_callset_p->act_info.rsp_cb = callback;
    srv_callset_p->act_info.rsp_user_data = user_data;
    srv_callset_sim_p->cug_temp_id = info->cug_id;
    srv_callset_l4c_set_cug_req(info->cug_id, MMI_TRUE);

    srv_callset_sim_cntx_reset_ptr();

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_ACTIVATE
        , SRV_CALLSET_RESULT_OK, info, info->sim, info->cug_id);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_deactivate
 * DESCRIPTION
 *  to deactivate the CUG index
 * PARAMETERS
 *  info : [IN] parameters
 *  callback : [IN] callback to notify the result. srv_callset_rsp_evt_struct(srv_callset_result_struct)
 *  user_data : [IN] user data
 * RETURNS
 *  srv_callset_result_enum, not OK if the request is rejected directly by callset service
 *****************************************************************************/
srv_callset_result_enum srv_callset_cug_deactivate(srv_callset_cug_deactivate_struct *info, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/*AMIT UPDATE HERE FOR GEMINI PLUS*/
    if (!info ||
        !srv_ss_is_valid_sim(info->sim) ||
        (info->cug_id >= SRV_CALLSET_CUG_MAX_GROUP_NUM))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_DEACTIVATE
                , SRV_CALLSET_RESULT_INVALID_INPUT, info, info->sim, info->cug_id);

        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (srv_callset_is_busy() || srv_callset_sim_cntx_is_locked())
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_DEACTIVATE
            , SRV_CALLSET_RESULT_BUSY, info, srv_callset_p->act_info.op, srv_callset_sim_p);
        return SRV_CALLSET_RESULT_BUSY;
    }

    srv_callset_sim_cntx_set_ptr(info->sim);

    srv_callset_p->act_info.op = SRV_CALLSET_OP_CUG_DEACTIVATE;
    srv_callset_p->act_info.rsp_cb = callback;
    srv_callset_p->act_info.rsp_user_data = user_data;
    srv_callset_sim_p->cug_temp_id = info->cug_id;
    srv_callset_l4c_set_cug_req(info->cug_id, MMI_FALSE);

    srv_callset_sim_cntx_reset_ptr();

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CUG_DEACTIVATE
        , SRV_CALLSET_RESULT_OK, info, info->sim, info->cug_id);
    return SRV_CALLSET_RESULT_OK;
}
#endif /* __MMI_CALLSET_CUG__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_ctr
 * DESCRIPTION
 *  initialiation for call time reminder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_ctr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode = 0;
    U16 time = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_CTR_MODE, &mode, DS_BYTE, &error);
    ReadValue(NVRAM_CALLSET_CTR_TIME, &time, DS_SHORT, &error);

    if (mode >= SRV_CALLSET_CTR_MODE_TOTAL)
    {
        mode = 0;
        WriteValue(NVRAM_CALLSET_CTR_MODE, &mode, DS_BYTE, &error);
    }

    if (mode == (U8)SRV_CALLSET_CTR_MODE_SINGLE)
    {
        if ((time < SRV_CALLSET_CTR_MIN_SINGLE_TIME) ||
            (time > SRV_CALLSET_CTR_MAX_SINGLE_TIME))
        {
            mode = 0;
            WriteValue(NVRAM_CALLSET_CTR_MODE, &mode, DS_BYTE, &error);
            time = 0;
            WriteValue(NVRAM_CALLSET_CTR_TIME, &time, DS_SHORT, &error);
        }
    }
    else if (mode == (U8)SRV_CALLSET_CTR_MODE_PERIODIC)
    {
        if ((time < SRV_CALLSET_CTR_MIN_PERIODIC_TIME) ||
            (time > SRV_CALLSET_CTR_MAX_PERIODIC_TIME))
        {
            mode = 0;
            WriteValue(NVRAM_CALLSET_CTR_MODE, &mode, DS_BYTE, &error);
            time = 0;
            WriteValue(NVRAM_CALLSET_CTR_TIME, &time, DS_SHORT, &error);
        }
    }
    else if (mode == (U8)SRV_CALLSET_CTR_MODE_OFF)
    {
        if (time)
        {
            time = 0;
            WriteValue(NVRAM_CALLSET_CTR_TIME, &time, DS_SHORT, &error);
        }
    }

    srv_callset_p->ctr.mode = (srv_callset_ctr_mode_enum)mode;
    srv_callset_p->ctr.time = time;

    srv_callset_p->ctr_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctr_set_mode
 * DESCRIPTION
 *  to set call time reminder mode and time
 * PARAMETERS
 *  info : [IN] parameters
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ctr_set_mode(srv_callset_ctr_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTR_SET_MODE
            , SRV_CALLSET_RESULT_INVALID_INPUT, info, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!(srv_callset_p->ctr_initiated))
    {
        srv_callset_init_ctr();
    }

    if (info->mode == SRV_CALLSET_CTR_MODE_SINGLE)
    {
        if ((info->time < SRV_CALLSET_CTR_MIN_SINGLE_TIME) ||
            (info->time > SRV_CALLSET_CTR_MAX_SINGLE_TIME))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTR_SET_MODE
                , SRV_CALLSET_RESULT_INVALID_INPUT, info, info->mode, info->time);
            return SRV_CALLSET_RESULT_INVALID_INPUT;
        }
    }
    else if (info->mode == SRV_CALLSET_CTR_MODE_PERIODIC)
    {
        if ((info->time < SRV_CALLSET_CTR_MIN_PERIODIC_TIME) ||
            (info->time > SRV_CALLSET_CTR_MAX_PERIODIC_TIME))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTR_SET_MODE
                , SRV_CALLSET_RESULT_INVALID_INPUT, info, info->mode, info->time);
            return SRV_CALLSET_RESULT_INVALID_INPUT;
        }
    }
    else if (info->mode == (U8)SRV_CALLSET_CTR_MODE_OFF)
    {
        if (info->time)
        {
            info->time = 0;
        }
    }

    if (info->mode != srv_callset_p->ctr.mode)
    {
        WriteValue(NVRAM_CALLSET_CTR_MODE, &(info->mode), DS_BYTE, &error);
        srv_callset_p->ctr.mode = info->mode;
    }
    if (info->time != srv_callset_p->ctr.time)
    {
        WriteValue(NVRAM_CALLSET_CTR_TIME, &(info->time), DS_SHORT, &error);
        srv_callset_p->ctr.time = info->time;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTR_SET_MODE
        , SRV_CALLSET_RESULT_OK, info, info->mode, info->time);
    return SRV_CALLSET_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctr_get_time
 * DESCRIPTION
 *  to get call time reminder time in sec.
 * PARAMETERS
 *  info : [OUT] ctr mode and time
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ctr_get_mode(srv_callset_ctr_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTR_GET_MODE
            , SRV_CALLSET_RESULT_INVALID_INPUT, info, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }
    else
    {
        memset(info, 0, sizeof(info));
    }

    if (!(srv_callset_p->ctr_initiated))
    {
        srv_callset_init_ctr();
    }

    memcpy(info, &(srv_callset_p->ctr), sizeof(srv_callset_ctr_struct));

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTR_GET_MODE
        , SRV_CALLSET_RESULT_OK, info, info->mode, info->time);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_answer_mode
 * DESCRIPTION
 *  initialiation for answer mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_answer_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_ANSWER_MODE, &mode, DS_BYTE, &error);

    if (mode >= SRV_CALLSET_ANSWER_MODE_END_OF_ENUM)
    {
        mode = 0;
        WriteValue(NVRAM_CALLSET_ANSWER_MODE, &mode, DS_BYTE, &error);
    }

    srv_callset_p->answer_mode = (srv_callset_answer_mode_enum)mode;
    srv_callset_p->answer_mode_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_answer_mode_set_mode
 * DESCRIPTION
 *  to set answer mode
 * PARAMETERS
 *  mode : [IN] answer mode (bitwised)
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_answer_mode_set_mode(srv_callset_answer_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (MMI_FALSE
    #ifndef __MMI_CLAMSHELL__
        || (mode & SRV_CALLSET_ANSWER_MODE_CLAMSHELL)
    #endif /* __MMI_CLAMSHELL__ */
        )
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_ANSWER_MODE_SET_MODE
            , SRV_CALLSET_RESULT_INVALID_INPUT, mode);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!(srv_callset_p->answer_mode_initiated))
    {
        srv_callset_init_answer_mode();
    }

    if (mode != srv_callset_p->answer_mode)
    {
        WriteValue(NVRAM_CALLSET_ANSWER_MODE, &mode, DS_BYTE, &error);
        srv_callset_p->answer_mode = mode;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_ANSWER_MODE_SET_MODE
        , SRV_CALLSET_RESULT_OK, mode);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_answer_mode_get_status
 * DESCRIPTION
 *  to check the answer mode status
 *      - Answer when clamshell on is allowed when clamshell setting is turnned on
 *      - Answer by any key is allowed when anykey setting is turnned on
 *      - Auto answer is allowed ONLY when both the following criteria are met:
 *          1. Auto answer setting is turned on
 *          2. The earphone is plugged in OR test SIM is used
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_answer_mode_enum (bitwised)
 *****************************************************************************/
srv_callset_answer_mode_enum srv_callset_answer_mode_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_test_sim1 = MMI_FALSE;
    MMI_BOOL is_test_sim2 = MMI_FALSE;
	MMI_BOOL is_test_sim3 = MMI_FALSE;
    MMI_BOOL is_test_sim4 = MMI_FALSE;
    srv_callset_answer_mode_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    status = srv_callset_answer_mode_get_mode();

#ifdef __GEMINI__
    is_test_sim1 = (MMI_BOOL)(is_test_sim(l4c_gemini_get_switched_sim_id(SIM1)) && srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE), NULL));
    is_test_sim2 = (MMI_BOOL)(is_test_sim(l4c_gemini_get_switched_sim_id(SIM2)) && srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_SIM2 | SRV_UCM_VIDEO_CALL_TYPE_SIM2), NULL));
	#if (MMI_MAX_SIM_NUM>=3) /*assuming 0x02 and 0x03 for SIM3 and SIM4*/
		is_test_sim3 = (MMI_BOOL)(is_test_sim(l4c_gemini_get_switched_sim_id(SIM3)) && srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM3, NULL));
	#if (MMI_MAX_SIM_NUM>=4)
		is_test_sim4 = (MMI_BOOL)(is_test_sim(l4c_gemini_get_switched_sim_id(SIM4)) && srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM4, NULL));
	#endif /*MMI_MAX_SIM_NUM>=4*/
	#endif /*MMI_MAX_SIM_NUM>=3*/
#else
    is_test_sim1 = (MMI_BOOL)(is_test_sim() && srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE), NULL));
#endif

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_ANSWER_MODE_GET_STATUS
        , srv_callset_p->answer_mode, is_test_sim1, is_test_sim2, srv_earphone_is_plug_in());

    if (!srv_earphone_is_plug_in() && !is_test_sim1 && !is_test_sim2 && !is_test_sim3 && !is_test_sim4 )
    {
        /* not allow auto answer no matter the setting is off or on */
        status &= ~SRV_CALLSET_ANSWER_MODE_AUTO;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_answer_mode_get_mode
 * DESCRIPTION
 *  to get answer mode (bitwised)
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_answer_mode_enum (bitwised)
 *  Please note that auto mode is on ONLY means the setting is turned on
 *  Auto answer is allowed when both the following criteria are met:
 *      1. Auto mode is turned on
 *      2. The earphone is plugged in OR test SIM is used
 *  To check auto answer is allowed, please use srv_callset_answer_mode_get_status instead
 *****************************************************************************/
srv_callset_answer_mode_enum srv_callset_answer_mode_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->answer_mode_initiated))
    {
        srv_callset_init_answer_mode();
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_ANSWER_MODE_GET_MODE , srv_callset_p->answer_mode);

    return srv_callset_p->answer_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_answer_mode_switch_mode
 * DESCRIPTION
 *  to turn on or turn off the specific answer mode
 * PARAMETERS
 *  mode    [IN]    the specific mode (bitwised)
 *  switch_on [IN]    MMI_TRUE for switch on; MMI_FALSE for switch off
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_answer_mode_switch_mode(srv_callset_answer_mode_enum mode, MMI_BOOL switch_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_answer_mode_enum new_mode, ori_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ori_mode = srv_callset_answer_mode_get_mode();
    new_mode = ori_mode;

    if (switch_on)
    {
        new_mode |= mode;
    }
    else
    {
        new_mode &= (~mode);
    }

    if (new_mode != ori_mode)
    {
        return srv_callset_answer_mode_set_mode(new_mode);
    }
    else
    {
        return SRV_CALLSET_RESULT_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_redial
 * DESCRIPTION
 *  initialiation for redial mode, lazy init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_redial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_REDIAL, &data, DS_BYTE, &error);

    if (data < SRV_CALLSET_REDIAL_UNKNOWN)
    {
        srv_callset_p->redial_mode = (srv_callset_redial_mode_enum)data;
    }
    else
    {
        data = 0x00;
        srv_callset_p->redial_mode = SRV_CALLSET_REDIAL_OFF;
        WriteValue(NVRAM_CALLSET_REDIAL, &data, DS_BYTE, &error);
    }

    srv_callset_p->redial_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_redial_get_mode
 * DESCRIPTION
 *  to get redial mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: TRUE if on, FALSE if off
 *****************************************************************************/
srv_callset_redial_mode_enum srv_callset_redial_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->redial_initiated))
    {
        srv_callset_init_redial();
    }

    return srv_callset_p->redial_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_redial_set_mode
 * DESCRIPTION
 *  to set redial mode
 * PARAMETERS
 *  srv_callset_redial_mode : [IN] redial mode
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_redial_set_mode(srv_callset_redial_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->redial_initiated))
    {
        srv_callset_init_redial();
    }

    if (mode != srv_callset_p->redial_mode)
    {
        data = (U8)mode;
        WriteValue(NVRAM_CALLSET_REDIAL, &data, DS_BYTE, &error);
        srv_callset_p->redial_mode = mode;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_redial_get_mode
 * DESCRIPTION
 *  to get auto redial mode, off/on
 *  redial automatically according to the call release cause
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: TRUE if on, FALSE if off
 *  equivalent to the return value SRV_CALLSET_REDIAL_OFF / SRV_CALLSET_REDIAL_AUTO in srv_callset_redial_get_mode()
 *  only for backward compatible
 *****************************************************************************/
MMI_BOOL srv_callset_auto_redial_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (srv_callset_redial_get_mode() == SRV_CALLSET_REDIAL_AUTO) ?
                MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_redial_set_mode
 * DESCRIPTION
 *  to set auto redial mode, off/on
 *  redial automatically according to the call release cause
 *  equivalent to srv_callset_redial_set_mode(SRV_CALLSET_REDIAL_OFF / SRV_CALLSET_REDIAL_AUTO)
 *  only for backward compatible
 * PARAMETERS
 *  MMI_BOOL : [IN] MMI_TRUE for on, MMI_FALSE for off
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_auto_redial_set_mode(MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_callset_redial_set_mode(mode ?
        SRV_CALLSET_REDIAL_AUTO : SRV_CALLSET_REDIAL_OFF);
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_ctd
 * DESCRIPTION
 *  initialiation for call time display, lazy init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_ctd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_CALL_TIME_DISPLAY, &data, DS_BYTE, &error);

    if (data == 0x01)
    {
        srv_callset_p->ctd_mode = MMI_TRUE;
    }
    else if (data == 0x00)
    {
        srv_callset_p->ctd_mode = MMI_FALSE;
    }
    else
    {
        data = 0x01;   /* Default =ON */
        srv_callset_p->ctd_mode = MMI_TRUE;
        WriteValue(NVRAM_CALLSET_CALL_TIME_DISPLAY, &data, DS_BYTE, &error);
    }

    srv_callset_p->ctd_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_call_time_display_get_mode
 * DESCRIPTION
 *  to get call time display status, off/on
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if the mode is on, MMI_FALSE if the mode is off or not available
 *****************************************************************************/
MMI_BOOL srv_callset_call_time_display_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->ctd_initiated))
    {
        srv_callset_init_ctd();
    }

    return srv_callset_p->ctd_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_call_time_display_set_mode
 * DESCRIPTION
 *  to set call time display status, off/on
 * PARAMETERS
 *  mode : [IN] call time display mode, MMI_TRUE for on
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_call_time_display_set_mode(MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->ctd_initiated))
    {
        srv_callset_init_ctd();
    }

    if (mode != srv_callset_p->ctd_mode)
    {
        data = mode ? 1 : 0;
        WriteValue(NVRAM_CALLSET_CALL_TIME_DISPLAY, &data, DS_BYTE, &error);
        srv_callset_p->ctd_mode = mode;
    }
}


#ifdef __MMI_UCM_REJECT_BY_SMS__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_rej_by_sms
 * DESCRIPTION
 *  initialiation for reject by sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_rej_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_REJ_BY_SMS, &data, DS_BYTE, &error);

    if (data == 0x01)
    {
        srv_callset_p->rej_by_sms_mode = MMI_TRUE;
    }
    else if (data == 0x00)
    {
        srv_callset_p->rej_by_sms_mode = MMI_FALSE;
    }
    else
    {
        data = 0x00;
        srv_callset_p->rej_by_sms_mode = MMI_FALSE;
        WriteValue(NVRAM_CALLSET_REJ_BY_SMS, &data, DS_BYTE, &error);
    }


    ReadValue(NVRAM_CALLSET_REJ_BY_SMS_SETTING, &data, DS_BYTE, &error);

    if (data < (U8)SRV_CALLSET_REJ_BY_SMS_UNKNOWN)
    {
        srv_callset_p->rej_by_sms_setting = (srv_callset_rej_by_sms_setting_enum)data;
    }
    else
    {
        data = 0x00; /* default */
        srv_callset_p->rej_by_sms_setting = SRV_CALLSET_REJ_BY_SMS_DEFAULT;
        WriteValue(NVRAM_CALLSET_REJ_BY_SMS_SETTING, &data, DS_BYTE, &error);
    }

    srv_callset_p->rej_by_sms_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_reject_by_sms_get_mode
 * DESCRIPTION
 *  to set the reject by sms mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE if the mode is on; MMI_FALSE if the mode is off or not available
 *****************************************************************************/
MMI_BOOL srv_callset_reject_by_sms_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->rej_by_sms_initiated))
    {
        srv_callset_init_rej_by_sms();
    }

    return srv_callset_p->rej_by_sms_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_reject_by_sms_set_mode
 * DESCRIPTION
 *  to set the reject by sms mode
 * PARAMETERS
 *  mode : [IN] MMI_TRUE if on, MMI_FALSE if off
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_callset_reject_by_sms_set_mode(MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->rej_by_sms_initiated))
    {
        srv_callset_init_rej_by_sms();
    }

    if (mode != srv_callset_p->rej_by_sms_mode)
    {
        data = mode ? 1 : 0;
        WriteValue(NVRAM_CALLSET_REJ_BY_SMS, &data, DS_BYTE, &error);
        srv_callset_p->rej_by_sms_mode = mode;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_reject_by_sms_get_setting
 * DESCRIPTION
 *  to set the reject by sms setting
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_rej_by_sms_setting_enum
 *****************************************************************************/
srv_callset_rej_by_sms_setting_enum srv_callset_reject_by_sms_get_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->rej_by_sms_initiated))
    {
        srv_callset_init_rej_by_sms();
    }

    return srv_callset_p->rej_by_sms_setting;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_reject_by_sms_set_setting
 * DESCRIPTION
 *  to set the reject by sms setting
 * PARAMETERS
 *  setting : [IN] srv_callset_rej_by_sms_setting_enum
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_reject_by_sms_set_setting(srv_callset_rej_by_sms_setting_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (setting >= SRV_CALLSET_REJ_BY_SMS_UNKNOWN)
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!(srv_callset_p->rej_by_sms_initiated))
    {
        srv_callset_init_rej_by_sms();
    }

    if (setting != srv_callset_p->rej_by_sms_setting)
    {
        data = (U8)setting;
        WriteValue(NVRAM_CALLSET_REJ_BY_SMS_SETTING, &data, DS_BYTE, &error);
        srv_callset_p->rej_by_sms_setting = setting;
    }

    return SRV_CALLSET_RESULT_OK;
}
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


#ifdef __MMI_CONNECT_NOTICE__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_connect_notice
 * DESCRIPTION
 *  initialiation for connect notice
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_connect_notice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_CONNECT_NOTICE, &data, DS_BYTE, &error);

    if (data == 0x01)
    {
        srv_callset_p->connect_notice_mode = MMI_TRUE;
    }
    else if (data == 0x00)
    {
        srv_callset_p->connect_notice_mode = MMI_FALSE;
    }
    else
    {
        data = 0x01;
        srv_callset_p->connect_notice_mode = MMI_TRUE;
        WriteValue(NVRAM_CALLSET_CONNECT_NOTICE, &data, DS_BYTE, &error);
    }

    srv_callset_p->connect_notice_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_connect_notice_get_mode
 * DESCRIPTION
 *  to set the connect notice mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE if the mode is on; MMI_FALSE if the mode is off or not available
 *****************************************************************************/
MMI_BOOL srv_callset_connect_notice_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->connect_notice_initiated))
    {
        srv_callset_init_connect_notice();
    }

    return srv_callset_p->connect_notice_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_connect_notice_set_mode
 * DESCRIPTION
 *  to set the connect notice mode
 * PARAMETERS
 *  mode : [IN] MMI_TRUE if on, MMI_FALSE if off
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_callset_connect_notice_set_mode(MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->connect_notice_initiated))
    {
        srv_callset_init_connect_notice();
    }

    if (mode != srv_callset_p->connect_notice_mode)
    {
        data = mode ? 1 : 0;
        WriteValue(NVRAM_CALLSET_CONNECT_NOTICE, &data, DS_BYTE, &error);
        srv_callset_p->connect_notice_mode = mode;
    }
}
#endif /* __MMI_CONNECT_NOTICE__ */


#ifdef __IP_NUMBER__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_ip_number
 * DESCRIPTION
 *  ip number initialization, lazy initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_ip_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U32 i;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadRecord(NVRAM_EF_IP_NUMBER_LID, 1, srv_callset_p->ip_number, sizeof(srv_callset_p->ip_number), &error);
    for (i = 0; i < SRV_CALLSET_MAX_IP_NUMBER; i++)
    {
        srv_callset_p->ip_number[i][SRV_CALLSET_MAX_IP_NUMBER_LEN] = L'\0';
    }

	for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
		ReadValue(srv_callset_ipnum_cache_id[i], &(srv_callset_p->ip_setting[i]), DS_BYTE, &error);
		if (((srv_callset_p->ip_setting[i] != 0xff) && 
			 (srv_callset_p->ip_setting[i] >= SRV_CALLSET_MAX_IP_NUMBER)) || 
			((srv_callset_p->ip_setting[i] != 0xff) && 
			 !mmi_ucs2strlen((CHAR*)srv_callset_p->ip_number[srv_callset_p->ip_setting[i]])))
		{
			srv_callset_p->ip_setting[i] = 0xff;
			WriteValue(srv_callset_ipnum_cache_id[i], &(srv_callset_p->ip_setting[i]), DS_BYTE, &error);
		}		
	}
	
    srv_callset_p->ip_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_get_item
 * DESCRIPTION
 *  to get the ip number item
 * PARAMETERS
 *  index : [IN] index, 0~(SRV_CALLSET_MAX_IP_NUMBER-1)
 *  item : [OUT] ip number item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_ip_number_get_item(U8 index, srv_callset_ip_number_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	static const srv_callset_ip_number_status_enum status[] = 
    {
    	SRV_CALLSET_IP_NUMBER_SIM1_ACTIVATED,
#if (MMI_MAX_SIM_NUM >= 2)
		SRV_CALLSET_IP_NUMBER_SIM2_ACTIVATED,
#if (MMI_MAX_SIM_NUM >= 3)
		SRV_CALLSET_IP_NUMBER_SIM3_ACTIVATED,
#if (MMI_MAX_SIM_NUM >= 4)
		SRV_CALLSET_IP_NUMBER_SIM4_ACTIVATED
#endif /*MMI_MAX_SIM_NUM>=4*/
#endif /*MMI_MAX_SIM_NUM>=3*/
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    };
	
	U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!item)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_GET_ITEM
            , SRV_CALLSET_RESULT_INVALID_INPUT, index, item, 0, 0, 0, 0, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    memset(item, 0, sizeof(srv_callset_ip_number_item_struct));

    if (index >= SRV_CALLSET_MAX_IP_NUMBER)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_GET_ITEM
            , SRV_CALLSET_RESULT_INVALID_INPUT, index, item, 0, 0, 0, 0, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!(srv_callset_p->ip_initiated))
    {
        srv_callset_init_ip_number();
    }

    item->index = index;
    mmi_ucs2ncpy((CHAR*)(item->number), (CHAR*)(srv_callset_p->ip_number[index]), SRV_CALLSET_MAX_IP_NUMBER_LEN);

    item->status = SRV_CALLSET_IP_NUMBER_OFF;

	for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
	    if (srv_callset_p->ip_setting[i] == index)
	    {
	        item->status |= status[i];
	    }
	}

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_GET_ITEM
        , SRV_CALLSET_RESULT_OK, index, item
        , item->number[0], item->number[1], item->number[2], item->number[3], item->number[4]
        , item->status);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_activate
 * DESCRIPTION
 *  to actviate an specific ip number with ip_index
 * PARAMETERS
 *  sim: [IN] apply to which SIM.
 *  index: [IN] the index of the ip number, 1~SRV_CALLSET_MAX_IP_NUMBER
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ip_number_activate(mmi_sim_enum sim, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	U32 sim_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (index >= SRV_CALLSET_MAX_IP_NUMBER || !srv_ss_is_valid_sim(sim))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_ACTIVATE
            , SRV_CALLSET_RESULT_INVALID_INPUT, sim, index);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!mmi_ucs2strlen((CHAR*)(srv_callset_p->ip_number[index])))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_ACTIVATE
            , SRV_CALLSET_RESULT_EMPTY, sim, index);
        return SRV_CALLSET_RESULT_EMPTY;
    }

	sim_index = mmi_frm_sim_to_index(sim);
	if (srv_callset_p->ip_setting[sim_index] != index)
	{
		srv_callset_p->ip_setting[sim_index] = index;
		WriteValue(srv_callset_ipnum_cache_id[sim_index], (void *)&index, DS_BYTE, &error);
	}
	
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_ACTIVATE
        , SRV_CALLSET_RESULT_OK, sim, index);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_deactivate
 * DESCRIPTION
 *  to deactviate an specific ip number with ip_index, will deactivate the original activated number first
 * PARAMETERS
 *  sim: [IN] apply to which SIM.
 *  index: [IN] the index of the ip number, 1~SRV_CALLSET_MAX_IP_NUMBER
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ip_number_deactivate(mmi_sim_enum sim, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	U32 sim_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (index >= SRV_CALLSET_MAX_IP_NUMBER || !srv_ss_is_valid_sim(sim))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_DEACTIVATE
            , SRV_CALLSET_RESULT_INVALID_INPUT, sim, index);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!mmi_ucs2strlen((CHAR*)(srv_callset_p->ip_number[index])))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_DEACTIVATE
            , SRV_CALLSET_RESULT_EMPTY, sim, index);
        return SRV_CALLSET_RESULT_EMPTY;
    }

	sim_index = mmi_frm_sim_to_index(sim);
	if (srv_callset_p->ip_setting[sim_index] == index)
	{
		srv_callset_p->ip_setting[sim_index] = 0xff;
		
		WriteValue(srv_callset_ipnum_cache_id[sim_index], (void *)&srv_callset_p->ip_setting[sim_index], DS_BYTE, &error);
	}
   

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_DEACTIVATE
        , SRV_CALLSET_RESULT_OK, sim, index);
    return SRV_CALLSET_RESULT_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_set_num
 * DESCRIPTION
 *  to set an ip number.
 * PARAMETERS
 *  index : [IN] index of the ip number, 0~(SRV_CALLSET_MAX_IP_NUMBER-1)
 *  length : [IN] length of the ip number, must <= SRV_CALLSET_MAX_IP_NUMBER_LEN
 *  ip_num : [IN] the point for the ip number string, shall not be NULL; can be empty string
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ip_number_set_number(U8 index, U8 length, WCHAR *ip_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((index >= SRV_CALLSET_MAX_IP_NUMBER) ||
        (length > SRV_CALLSET_MAX_IP_NUMBER_LEN) ||
        !ip_num)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_SET_NUMBER
            , SRV_CALLSET_RESULT_INVALID_INPUT, index, length, ip_num);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

	if (length == 0)
	{
		for (i = 0; i < MMI_SIM_TOTAL; i++)
		{
			if (index == srv_callset_p->ip_setting[i])
			{
		        /* not allow to clear the activated ip number */
		        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_SET_NUMBER
		            , SRV_CALLSET_RESULT_EMPTY, index, length, ip_num);
				
		        return SRV_CALLSET_RESULT_EMPTY;
			}
		}
	}

    if (!(srv_callset_p->ip_initiated))
    {
        srv_callset_init_ip_number();
    }

    if (mmi_ucs2ncmp((CHAR*)ip_num, (CHAR*)(srv_callset_p->ip_number[index]), SRV_CALLSET_MAX_IP_NUMBER_LEN))
    {
        /* different number, set */
        mmi_ucs2ncpy((CHAR*)(srv_callset_p->ip_number[index]), (CHAR*)ip_num, length);
        if (WriteRecord(NVRAM_EF_IP_NUMBER_LID, 
                        1, 
                        srv_callset_p->ip_number, 
                        sizeof(srv_callset_p->ip_number), 
                        &error) < 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_SET_NUMBER
                , SRV_CALLSET_RESULT_UNKNOWN_ERROR, index, length, ip_num);
            return SRV_CALLSET_RESULT_UNKNOWN_ERROR;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_SET_NUMBER
        , SRV_CALLSET_RESULT_OK, index, length, ip_num);
	
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_get_activated_number
 * DESCRIPTION
 *  to get current activated ip number.
 * PARAMETERS
 *  sim : [IN] apply to which SIM.
 *  ip_num : [OUT] the point for the returned ip number, in UCS2
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ip_number_get_activated_number(mmi_sim_enum sim, srv_callset_ip_number_struct *ip_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 sim_index;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!ip_num || !srv_ss_is_valid_sim(sim))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_GET_ACTIVATED_NUMBER
            , SRV_CALLSET_RESULT_INVALID_INPUT, sim, ip_num, 0, 0, 0, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    memset(ip_num, 0, sizeof(srv_callset_ip_number_struct));

    if (!(srv_callset_p->ip_initiated))
    {
        srv_callset_init_ip_number();
    }

	sim_index = mmi_frm_sim_to_index(sim);
	if (srv_callset_p->ip_setting[sim_index] < SRV_CALLSET_MAX_IP_NUMBER)
	{
		mmi_ucs2cpy((CHAR*)ip_num, (CHAR*)(srv_callset_p->ip_number[srv_callset_p->ip_setting[sim_index]]));
	}

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IP_NUMBER_GET_ACTIVATED_NUMBER
        , SRV_CALLSET_RESULT_OK, sim, ip_num
        , ip_num->number[0], ip_num->number[1], ip_num->number[2], ip_num->number[3], ip_num->number[4]);
    return SRV_CALLSET_RESULT_OK;
}

#endif /* __IP_NUMBER__ */


#ifdef __MMI_CM_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_blacklist
 * DESCRIPTION
 *  initialiation for blacklist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_blacklist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_BLACKLIST_MODE, &(srv_callset_p->blacklist_mode), DS_BYTE, &error);

    if (srv_callset_p->blacklist_mode >= SRV_CALLSET_BLACKLIST_MODE_END_OF_ENUM)
    {
        srv_callset_p->blacklist_mode = SRV_CALLSET_BLACKLIST_OFF;
        WriteValue(NVRAM_CALLSET_BLACKLIST_MODE, &(srv_callset_p->blacklist_mode), DS_BYTE, &error);
    }

    ReadRecord(NVRAM_EF_BLACK_LIST_LID, 1, srv_callset_p->blacklist_num, sizeof(srv_callset_p->blacklist_num), &error);

#ifdef __MMI_CM_BLACK_LIST_EXT__
#ifdef __MMI_VIDEO_TELEPHONY__
    ReadValue(NVRAM_CALLSET_BLACKLIST_MODE_VIDEO, &(srv_callset_p->blacklist_mode_video), DS_BYTE, &error);

    if (srv_callset_p->blacklist_mode_video >= SRV_CALLSET_BLACKLIST_MODE_END_OF_ENUM)
    {
        srv_callset_p->blacklist_mode_video = SRV_CALLSET_BLACKLIST_OFF;
        WriteValue(NVRAM_CALLSET_BLACKLIST_MODE_VIDEO, &(srv_callset_p->blacklist_mode_video), DS_BYTE, &error);
    }

    ReadRecord(NVRAM_EF_BLACK_LIST_VIDEO_LID, 1, srv_callset_p->blacklist_num_video, sizeof(srv_callset_p->blacklist_num_video), &error);
#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif/* __MMI_CM_BLACK_LIST_EXT__ */

    srv_callset_p->blacklist_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_init_advanced_param
 * DESCRIPTION
 *  to initialize the blacklist advanced parameters for the next operation
 * PARAMETERS
 *  adv_param : [OUT] pointer for advanced parameter structure
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_blacklist_init_advanced_param(srv_callset_blacklist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!adv_param)
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

#ifdef __MMI_CM_BLACK_LIST_EXT__
    adv_param->call_type = SRV_CALLSET_ALL_CALL;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    return SRV_CALLSET_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_get_mode
 * DESCRIPTION
 *  to get blacklist mode
 * PARAMETERS
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_blacklist_mode_enum, bitwise
 *****************************************************************************/ 
srv_callset_blacklist_mode_enum srv_callset_blacklist_get_mode(srv_callset_blacklist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_mode_enum mode = SRV_CALLSET_BLACKLIST_OFF;
    srv_callset_blacklist_adv_param_struct tmp_para;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->blacklist_initiated))
    {
        srv_callset_init_blacklist();
    }

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_blacklist_adv_param_struct));
    }
    else
    {
        srv_callset_blacklist_init_advanced_param(&tmp_para);
    }

    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        mode |= srv_callset_p->blacklist_mode;
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        mode |= srv_callset_p->blacklist_mode_video;
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    return mode;

#else /* __MMI_CM_BLACK_LIST_EXT__ */
    return srv_callset_p->blacklist_mode;

#endif /* __MMI_CM_BLACK_LIST_EXT__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_switch_mode
 * DESCRIPTION
 *  to turn on or turn off the specific blacklist mode
 * PARAMETERS
 *  mode :   [IN]    the specific mode
 *  switch_on : [IN]    MMI_TRUE for switch on; MMI_FALSE for switch off
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_blacklist_switch_mode(srv_callset_blacklist_mode_enum mode, MMI_BOOL switch_on, srv_callset_blacklist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_blacklist_mode_enum new_mode, ori_mode;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_result_enum result = SRV_CALLSET_RESULT_OK;
    srv_callset_result_enum tmp_result;
    srv_callset_blacklist_adv_param_struct tmp_para;
    srv_callset_blacklist_adv_param_struct input_para;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_blacklist_adv_param_struct));
    }
    else
    {
        srv_callset_blacklist_init_advanced_param(&tmp_para);
    }

    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        srv_callset_blacklist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VOICE_CALL;
        ori_mode = srv_callset_blacklist_get_mode(&input_para);
        new_mode = ori_mode;
        
        if (switch_on)
        {
            new_mode |= mode;
        }
        else
        {
            new_mode &= (~mode);
        }
        
        if (new_mode != ori_mode)
        {
            result = srv_callset_blacklist_set_mode(new_mode, &input_para);
        }
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        srv_callset_blacklist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VIDEO_CALL;
        ori_mode = srv_callset_blacklist_get_mode(&input_para);
        new_mode = ori_mode;
        
        if (switch_on)
        {
            new_mode |= mode;
        }
        else
        {
            new_mode &= (~mode);
        }
        
        if (new_mode != ori_mode)
        {
            tmp_result = srv_callset_blacklist_set_mode(new_mode, &input_para);
            result = (result != SRV_CALLSET_RESULT_OK) ? result : tmp_result;
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    return result;
   
#else /* __MMI_CM_BLACK_LIST_EXT__ */
    ori_mode = srv_callset_blacklist_get_mode(adv_param);
    new_mode = ori_mode;

    if (switch_on)
    {
        new_mode |= mode;
    }
    else
    {
        new_mode &= (~mode);
    }

    if (new_mode != ori_mode)
    {
        return srv_callset_blacklist_set_mode(new_mode, adv_param);
    }
    else
    {
        return SRV_CALLSET_RESULT_OK;
    }
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_set_mode
 * DESCRIPTION
 *  to set the blacklist mode to the input value (turn on or turn off)
 * PARAMETERS
 *  mode : [IN] mode, bitwise
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_blacklist_set_mode(srv_callset_blacklist_mode_enum mode, srv_callset_blacklist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct tmp_para;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((mode >= SRV_CALLSET_BLACKLIST_MODE_END_OF_ENUM)
    #ifndef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
        && (mode & SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER)
    #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
        )
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_SET_MODE
            , SRV_CALLSET_RESULT_INVALID_INPUT, mode);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!(srv_callset_p->blacklist_initiated))
    {
        srv_callset_init_blacklist();
    }

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_blacklist_adv_param_struct));
    }
    else
    {
        srv_callset_blacklist_init_advanced_param(&tmp_para);
    }

    if ((tmp_para.call_type & SRV_CALLSET_VOICE_CALL) &&
        (mode != srv_callset_p->blacklist_mode))
    {
        srv_callset_p->blacklist_mode = mode;
        WriteValue(NVRAM_CALLSET_BLACKLIST_MODE, &(srv_callset_p->blacklist_mode), DS_BYTE, &error);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if ((tmp_para.call_type & SRV_CALLSET_VIDEO_CALL) &&
        (mode != srv_callset_p->blacklist_mode_video))
    {
        srv_callset_p->blacklist_mode_video = mode;
        WriteValue(NVRAM_CALLSET_BLACKLIST_MODE_VIDEO, &(srv_callset_p->blacklist_mode_video), DS_BYTE, &error);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#else /* __MMI_CM_BLACK_LIST_EXT__ */
    if (mode != srv_callset_p->blacklist_mode)
    {
        srv_callset_p->blacklist_mode = mode;
        WriteValue(NVRAM_CALLSET_BLACKLIST_MODE, &(srv_callset_p->blacklist_mode), DS_BYTE, &error);
    }
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_SET_MODE
        , SRV_CALLSET_RESULT_OK, mode);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_get_item
 * DESCRIPTION
 *  to get the blacklist item by index
 * PARAMETERS
 *  item : [IN][OUT] number item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_blacklist_get_item(srv_callset_bl_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (item)
    {
        memset(item->number, 0, sizeof(item->number));
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_GET_ITEM
            , SRV_CALLSET_RESULT_INVALID_INPUT, -1, item, 0, 0, 0, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (item->index >= SRV_CALLSET_BLACKLIST_MAX_ITEM)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_GET_ITEM
            , SRV_CALLSET_RESULT_INVALID_INPUT, item->index, item, 0, 0, 0, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!(srv_callset_p->blacklist_initiated))
    {
        srv_callset_init_blacklist();
    }

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if (item->adv_param)
    {
        switch (item->adv_param->call_type)
        {
            case SRV_CALLSET_VOICE_CALL:
                mmi_ucs2ncpy((CHAR*)(item->number), (CHAR*)(srv_callset_p->blacklist_num[item->index]), SRV_UCM_MAX_NUM_URI_LEN);
                break;

        #ifdef __MMI_VIDEO_TELEPHONY__
            case SRV_CALLSET_VIDEO_CALL:
                mmi_ucs2ncpy((CHAR*)(item->number), (CHAR*)(srv_callset_p->blacklist_num_video[item->index]), SRV_UCM_MAX_NUM_URI_LEN);
                break;
        #endif /* __MMI_VIDEO_TELEPHONY__ */

            default:
                return SRV_CALLSET_RESULT_INVALID_INPUT;
        }
    }
    else
#else /* __MMI_CM_BLACK_LIST_EXT__ */
    {
        mmi_ucs2ncpy((CHAR*)(item->number), (CHAR*)(srv_callset_p->blacklist_num[item->index]), SRV_UCM_MAX_NUM_URI_LEN);
    }
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_GET_ITEM
        , SRV_CALLSET_RESULT_OK, item->index, item
        , item->number[0], item->number[1], item->number[2], item->number[3], item->number[4]);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_set_number
 * DESCRIPTION
 *  to set a blacklist number
 * PARAMETERS
 *  item : [IN] number item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_blacklist_set_number(srv_callset_bl_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    CHAR asc_num[SRV_UCM_MAX_NUM_URI_LEN + 1];
    srv_callset_bl_item_struct tmp_item;
    U32 i;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct tmp_para;
    srv_callset_blacklist_adv_param_struct input_para;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!item ||
        (item->index >= SRV_CALLSET_BLACKLIST_MAX_ITEM))
    {
        if (item)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_SET_NUMBER
                , SRV_CALLSET_RESULT_INVALID_INPUT, item, item->index, 0, 0, 0, 0, 0);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_SET_NUMBER
                , SRV_CALLSET_RESULT_INVALID_INPUT, item, 0, 0, 0, 0, 0, 0);
        }
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    memset(asc_num, 0, sizeof(asc_num));
    mmi_ucs2_n_to_asc((CHAR*)asc_num, (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if (item->adv_param)
    {
        memcpy(&tmp_para, item->adv_param, sizeof(srv_callset_blacklist_adv_param_struct));
    }
    else
    {
        srv_callset_blacklist_init_advanced_param(&tmp_para);
    }
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    if (mmi_ucs2strlen((CHAR*)item->number))
    {
        if (!srv_ucm_is_valid_number((srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, (PU8)asc_num))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_SET_NUMBER
                , SRV_CALLSET_RESULT_INVALID_FORMAT, item, item->index
                , asc_num[0], asc_num[1], asc_num[2], asc_num[3], asc_num[4]);
            return SRV_CALLSET_RESULT_INVALID_FORMAT;
        }

    #ifdef __MMI_CM_BLACK_LIST_EXT__
        if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
        {
            srv_callset_blacklist_init_advanced_param(&input_para);
            input_para.call_type = SRV_CALLSET_VOICE_CALL;
            tmp_item.adv_param = &input_para;
            
            for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
            {
                tmp_item.index = i;
            
                if ((srv_callset_blacklist_get_item(&tmp_item) == SRV_CALLSET_RESULT_OK) &&
                     srv_phb_compare_number(tmp_item.number, item->number))
                {
                    return SRV_CALLSET_RESULT_DUPLICATE;
                }
            }
        }

    #ifdef __MMI_VIDEO_TELEPHONY__
        if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
        {
            srv_callset_blacklist_init_advanced_param(&input_para);
            input_para.call_type = SRV_CALLSET_VIDEO_CALL;
            tmp_item.adv_param = &input_para;
            
            for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
            {
                tmp_item.index = i;
            
                if ((srv_callset_blacklist_get_item(&tmp_item) == SRV_CALLSET_RESULT_OK) &&
                     srv_phb_compare_number(tmp_item.number, item->number))
                {
                    return SRV_CALLSET_RESULT_DUPLICATE;
                }
            }
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */

    #else /* __MMI_CM_BLACK_LIST_EXT__ */
        tmp_item.adv_param = item->adv_param;
        for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
        {
            tmp_item.index = i;

            if ((srv_callset_blacklist_get_item(&tmp_item) == SRV_CALLSET_RESULT_OK) &&
                 srv_phb_compare_number(tmp_item.number, item->number))
            {
                return SRV_CALLSET_RESULT_DUPLICATE;
            }
        }
    #endif /* __MMI_CM_BLACK_LIST_EXT__ */

    }

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if ((tmp_para.call_type & SRV_CALLSET_VOICE_CALL) &&
        (mmi_ucs2ncmp((CHAR*)srv_callset_p->blacklist_num[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN)))
    {
        mmi_ucs2ncpy((CHAR*)srv_callset_p->blacklist_num[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN);
        WriteRecord(NVRAM_EF_BLACK_LIST_LID, 1, srv_callset_p->blacklist_num, sizeof(srv_callset_p->blacklist_num), &error);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if ((tmp_para.call_type & SRV_CALLSET_VIDEO_CALL) &&
        (mmi_ucs2ncmp((CHAR*)srv_callset_p->blacklist_num_video[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN)))
    {
        mmi_ucs2ncpy((CHAR*)srv_callset_p->blacklist_num_video[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN);
        WriteRecord(NVRAM_EF_BLACK_LIST_VIDEO_LID, 1, srv_callset_p->blacklist_num_video, sizeof(srv_callset_p->blacklist_num_video), &error);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#else /* __MMI_CM_BLACK_LIST_EXT__ */
    if (mmi_ucs2ncmp((CHAR*)srv_callset_p->blacklist_num[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN))
    {
        mmi_ucs2ncpy((CHAR*)srv_callset_p->blacklist_num[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN);
        WriteRecord(NVRAM_EF_BLACK_LIST_LID, 1, srv_callset_p->blacklist_num, sizeof(srv_callset_p->blacklist_num), &error);
    }
#endif /* __MMI_CM_BLACK_LIST_EXT__ */


    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_SET_NUMBER
        , SRV_CALLSET_RESULT_OK, item, item->index
        , asc_num[0], asc_num[1], asc_num[2], asc_num[3], asc_num[4]);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_add_number
 * DESCRIPTION
 *  to add a number into black list
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN
 *  number : [IN] the point for the blocked number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 *  index : [OUT] assigned index, can be NULL (don't care about the index)
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_blacklist_add_number(U8 length, WCHAR *number, srv_callset_blacklist_adv_param_struct *adv_param, PU8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_callset_bl_item_struct item;
    srv_callset_result_enum result = SRV_CALLSET_RESULT_FULL;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_result_enum tmp_result;
    srv_callset_blacklist_adv_param_struct tmp_para;
    srv_callset_blacklist_adv_param_struct input_para;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!length || !number)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_ADD_NUMBER
            , SRV_CALLSET_RESULT_EMPTY, length, number, index);
        return SRV_CALLSET_RESULT_EMPTY;
    }

    if (length > SRV_UCM_MAX_NUM_URI_LEN)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_ADD_NUMBER
            , SRV_CALLSET_RESULT_TOO_LONG, length, number, index);
        return SRV_CALLSET_RESULT_TOO_LONG;
    }

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_blacklist_adv_param_struct));
    }
    else
    {
        srv_callset_blacklist_init_advanced_param(&tmp_para);
    }
    
    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        srv_callset_blacklist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VOICE_CALL;
        item.adv_param = &input_para;
        for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
        {
            item.index = i;
        
            if ((srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                !mmi_ucs2strlen((CHAR*)item.number))
            {
                if (index)
                {
                    *index = i;
                }
        
                mmi_ucs2ncpy((CHAR*)item.number, (CHAR*)number, length);
        
                result = srv_callset_blacklist_set_number(&item);
                break;
            }
        }
    }
    
#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        srv_callset_blacklist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VIDEO_CALL;
        item.adv_param = &input_para;
        for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
        {
            item.index = i;
        
            if ((srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                !mmi_ucs2strlen((CHAR*)item.number))
            {
                if (index)
                {
                    *index = i;
                }
        
                mmi_ucs2ncpy((CHAR*)item.number, (CHAR*)number, length);
        
                tmp_result = srv_callset_blacklist_set_number(&item);
                result = (result != SRV_CALLSET_RESULT_OK) ? result : tmp_result;
                break;
            }
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    
#else /* __MMI_CM_BLACK_LIST_EXT__ */
    item.adv_param = adv_param;
    for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
    {
        item.index = i;

        if ((srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
            !mmi_ucs2strlen((CHAR*)item.number))
        {
            if (index)
            {
                *index = i;
            }

            mmi_ucs2ncpy((CHAR*)item.number, (CHAR*)number, length);

            result = srv_callset_blacklist_set_number(&item);
            break;
        }
    }
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_ADD_NUMBER
        , result, length, number, index);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_delete_number
 * DESCRIPTION
 *  to delete a number from black list
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN
 *  number : [IN] the point for the blocked number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior       
 *                   call type is allowed to be bitwised (add number to each call type),
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 *  index : [OUT] index of delete target, can be NULL (don't care about the index)
 *                   index is invalid when call type is bitwised
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_blacklist_delete_number(U8 length, WCHAR *number, srv_callset_blacklist_adv_param_struct *adv_param, PU8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_callset_bl_item_struct item;
    srv_callset_result_enum result = SRV_CALLSET_RESULT_NOT_FOUND;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_result_enum tmp_result;
    srv_callset_blacklist_adv_param_struct tmp_para;
    srv_callset_blacklist_adv_param_struct input_para;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (index)
    {
        *index = 0xff;
    }

    if (!length || !number)
    {
//        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_ADD_NUMBER
//            , SRV_CALLSET_RESULT_EMPTY, length, number, index);
        return SRV_CALLSET_RESULT_EMPTY;
    }

    if (length > SRV_UCM_MAX_NUM_URI_LEN)
    {
//        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_ADD_NUMBER
//            , SRV_CALLSET_RESULT_TOO_LONG, length, number, index);
        return SRV_CALLSET_RESULT_TOO_LONG;
    }

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_blacklist_adv_param_struct));
    }
    else
    {
        srv_callset_blacklist_init_advanced_param(&tmp_para);
    }
    
    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        srv_callset_blacklist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VOICE_CALL;
        item.adv_param = &input_para;
        for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
        {
            item.index = i;
        
            if ((srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                srv_phb_compare_number(number, item.number))
            {
                if (index)
                {
                    *index = i;
                }
        
                memset(item.number, 0, sizeof(item.number));
        
                result = srv_callset_blacklist_set_number(&item);
                break;
            }
        }
    }
    
#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        srv_callset_blacklist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VIDEO_CALL;
        item.adv_param = &input_para;
        for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
        {
            item.index = i;
        
            if ((srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                srv_phb_compare_number(number, item.number))
            {
                if (index)
                {
                    *index = i;
                }
        
                memset(item.number, 0, sizeof(item.number));
        
                tmp_result = srv_callset_blacklist_set_number(&item);
                result = (result != SRV_CALLSET_RESULT_OK) ? result : tmp_result;
                break;
            }
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    
#else /* __MMI_CM_BLACK_LIST_EXT__ */
    item.adv_param = adv_param;
    for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
    {
        item.index = i;

        if ((srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
             srv_phb_compare_number(number, item.number))
        {
            if (index)
            {
                *index = i;
            }

            memset(item.number, 0, sizeof(item.number));

            result = srv_callset_blacklist_set_number(&item);
            break;
        }
    }
#endif /* __MMI_CM_BLACK_LIST_EXT__ */



//    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_ADD_NUMBER
//        , SRV_CALLSET_RESULT_NOT_FOUND, length, number, index);
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_is_blocked_number
 * DESCRIPTION
 *  to check if the number is a blocked number
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN; allowed to be 0 (Unknown number)
 *  number : [IN] the point for the blocked number, in UCS2; allowed to be NULL (Unknown number)
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  MMI_BOOL : TRUE if yes, FALSE if no
 *****************************************************************************/
MMI_BOOL srv_callset_blacklist_is_blocked_number(U8 length, WCHAR *number, srv_callset_blacklist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_callset_bl_item_struct item;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct tmp_para;
    srv_callset_blacklist_adv_param_struct input_para;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* rej all */
    if (srv_callset_blacklist_get_mode(adv_param) & SRV_CALLSET_BLACKLIST_REJECT_ALL)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_TRUE, 1);
        return MMI_TRUE;
    }

    /* empty number */
    if (!length)
    {
    #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
        /* rej unknown number */
        if (srv_callset_blacklist_get_mode(adv_param) & SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_TRUE, 2);
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_FALSE, 1);
            return MMI_FALSE;
        }
    #else /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_FALSE, 2);
        return MMI_FALSE;
    #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
    }

    /* rej number in the list */
    if (length &&
        !(srv_callset_blacklist_get_mode(adv_param) & SRV_CALLSET_BLACKLIST_FROM_LIST))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_FALSE, 3);
        return MMI_FALSE;
    }

#ifdef __MMI_CM_BLACK_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_blacklist_adv_param_struct));
    }
    else
    {
        srv_callset_blacklist_init_advanced_param(&tmp_para);
    }
    
    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        srv_callset_blacklist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VOICE_CALL;
        item.adv_param = &input_para;

        if (srv_callset_blacklist_get_mode(&input_para) & SRV_CALLSET_BLACKLIST_FROM_LIST)
        {
            for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
            {
                item.index = i;
            
                if (srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK)
                {
                    if (srv_phb_compare_number(number, item.number))
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_TRUE, 3);
                        return MMI_TRUE;
                    }
                }
            }
        }
    }
    
#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        srv_callset_blacklist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VIDEO_CALL;
        item.adv_param = &input_para;

        if (srv_callset_blacklist_get_mode(&input_para) & SRV_CALLSET_BLACKLIST_FROM_LIST)
        {
            for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
            {
                item.index = i;
            
                if (srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK)
                {
                    if (srv_phb_compare_number(number, item.number))
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_TRUE, 4);
                        return MMI_TRUE;
                    }
                }
            }
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    
#else /* __MMI_CM_BLACK_LIST_EXT__ */
    item.adv_param = adv_param;
    for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
    {
        item.index = i;

        if (srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK)
        {
            if (srv_phb_compare_number(number, item.number))
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_TRUE, 3);
                return MMI_TRUE;
            }
        }
    }
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_BLACKLIST_IS_BLOCKED_NUMBER, MMI_FALSE, 4);
    return MMI_FALSE;

}


#endif /* __MMI_CM_BLACK_LIST__ */


#ifdef __MMI_CM_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_whitelist
 * DESCRIPTION
 *  initialiation for whitelist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_whitelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_WHITELIST_MODE, &(srv_callset_p->whitelist_mode), DS_BYTE, &error);

    if (srv_callset_p->whitelist_mode >= SRV_CALLSET_WHITELIST_MODE_END_OF_ENUM)
    {
        srv_callset_p->whitelist_mode = SRV_CALLSET_WHITELIST_OFF;
        WriteValue(NVRAM_CALLSET_WHITELIST_MODE, &(srv_callset_p->whitelist_mode), DS_BYTE, &error);
    }

    ReadRecord(NVRAM_EF_WHITE_LIST_LID, 1, srv_callset_p->whitelist_num, sizeof(srv_callset_p->whitelist_num), &error);

#ifdef __MMI_CM_WHITE_LIST_EXT__
#ifdef __MMI_VIDEO_TELEPHONY__
        ReadValue(NVRAM_CALLSET_WHITELIST_MODE_VIDEO, &(srv_callset_p->whitelist_mode_video), DS_BYTE, &error);
    
        if (srv_callset_p->whitelist_mode_video >= SRV_CALLSET_WHITELIST_MODE_END_OF_ENUM)
        {
            srv_callset_p->whitelist_mode_video = SRV_CALLSET_WHITELIST_OFF;
            WriteValue(NVRAM_CALLSET_WHITELIST_MODE_VIDEO, &(srv_callset_p->whitelist_mode_video), DS_BYTE, &error);
        }
    
        ReadRecord(NVRAM_EF_WHITE_LIST_VIDEO_LID, 1, srv_callset_p->whitelist_num_video, sizeof(srv_callset_p->whitelist_num_video), &error);
#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif/* __MMI_CM_WHITE_LIST_EXT__ */

    srv_callset_p->whitelist_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_init_advanced_param
 * DESCRIPTION
 *  to initialize the whitelist advanced parameters for the next operation
 * PARAMETERS
 *  adv_param : [OUT] pointer for advanced parameter structure
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_whitelist_init_advanced_param(srv_callset_whitelist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!adv_param)
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

#ifdef __MMI_CM_WHITE_LIST_EXT__
    adv_param->call_type = SRV_CALLSET_ALL_CALL;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_get_mode
 * DESCRIPTION
 *  to get whitelist mode
 * PARAMETERS
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_whitelist_mode_enum, bitwise
 *****************************************************************************/ 
srv_callset_whitelist_mode_enum srv_callset_whitelist_get_mode(srv_callset_whitelist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_whitelist_mode_enum mode = SRV_CALLSET_WHITELIST_OFF;
    srv_callset_whitelist_adv_param_struct tmp_para;
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->whitelist_initiated))
    {
        srv_callset_init_whitelist();
    }

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_whitelist_adv_param_struct));
    }
    else
    {
        srv_callset_whitelist_init_advanced_param(&tmp_para);
    }

    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        mode |= srv_callset_p->whitelist_mode;
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        mode |= srv_callset_p->whitelist_mode_video;
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    return mode;

#else /* __MMI_CM_WHITE_LIST_EXT__ */
    return srv_callset_p->whitelist_mode;

#endif /* __MMI_CM_WHITE_LIST_EXT__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_switch_mode
 * DESCRIPTION
 *  to turn on or turn off the specific whitelist mode
 * PARAMETERS
 *  mode    [IN]    the specific mode
 *  switch_on [IN]    MMI_TRUE for switch on; MMI_FALSE for switch off
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_whitelist_switch_mode(srv_callset_whitelist_mode_enum mode, MMI_BOOL switch_on, srv_callset_whitelist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_whitelist_mode_enum new_mode, ori_mode;
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_result_enum result = SRV_CALLSET_RESULT_OK;
    srv_callset_result_enum tmp_result;
    srv_callset_whitelist_adv_param_struct tmp_para;
    srv_callset_whitelist_adv_param_struct input_para;
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_whitelist_adv_param_struct));
    }
    else
    {
        srv_callset_whitelist_init_advanced_param(&tmp_para);
    }

    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        srv_callset_whitelist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VOICE_CALL;
        ori_mode = srv_callset_whitelist_get_mode(&input_para);
        new_mode = ori_mode;
        
        if (switch_on)
        {
            new_mode |= mode;
        }
        else
        {
            new_mode &= (~mode);
        }
        
        if (new_mode != ori_mode)
        {
            result = srv_callset_whitelist_set_mode(new_mode, &input_para);
        }
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        srv_callset_whitelist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VIDEO_CALL;
        ori_mode = srv_callset_whitelist_get_mode(&input_para);
        new_mode = ori_mode;
        
        if (switch_on)
        {
            new_mode |= mode;
        }
        else
        {
            new_mode &= (~mode);
        }
        
        if (new_mode != ori_mode)
        {
            tmp_result = srv_callset_whitelist_set_mode(new_mode, &input_para);
            result = (result != SRV_CALLSET_RESULT_OK) ? result : tmp_result;
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    return result;
   
#else /* __MMI_CM_WHITE_LIST_EXT__ */
    ori_mode = srv_callset_whitelist_get_mode(adv_param);
    new_mode = ori_mode;

    if (switch_on)
    {
        new_mode |= mode;
    }
    else
    {
        new_mode &= (~mode);
    }

    if (new_mode != ori_mode)
    {
        return srv_callset_whitelist_set_mode(new_mode, adv_param);
    }
    else
    {
        return SRV_CALLSET_RESULT_OK;
    }
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_set_mode
 * DESCRIPTION
 *  to set whitelist mode
 * PARAMETERS
 *  mode : [IN] mode, bitwise
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_whitelist_set_mode(srv_callset_whitelist_mode_enum mode, srv_callset_whitelist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_whitelist_adv_param_struct tmp_para;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mode >= SRV_CALLSET_WHITELIST_MODE_END_OF_ENUM)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_SET_MODE
            , SRV_CALLSET_RESULT_INVALID_INPUT, mode);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!(srv_callset_p->whitelist_initiated))
    {
        srv_callset_init_whitelist();
    }

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_whitelist_adv_param_struct));
    }
    else
    {
        srv_callset_whitelist_init_advanced_param(&tmp_para);
    }

    if ((tmp_para.call_type & SRV_CALLSET_VOICE_CALL) &&
        (mode != srv_callset_p->whitelist_mode))
    {
        srv_callset_p->whitelist_mode = mode;
        WriteValue(NVRAM_CALLSET_WHITELIST_MODE, &(srv_callset_p->whitelist_mode), DS_BYTE, &error);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if ((tmp_para.call_type & SRV_CALLSET_VIDEO_CALL) &&
        (mode != srv_callset_p->whitelist_mode_video))
    {
        srv_callset_p->whitelist_mode_video = mode;
        WriteValue(NVRAM_CALLSET_WHITELIST_MODE_VIDEO, &(srv_callset_p->whitelist_mode_video), DS_BYTE, &error);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#else /* __MMI_CM_WHITE_LIST_EXT__ */
    if (mode != srv_callset_p->whitelist_mode)
    {
        srv_callset_p->whitelist_mode = mode;
        WriteValue(NVRAM_CALLSET_WHITELIST_MODE, &(srv_callset_p->whitelist_mode), DS_BYTE, &error);
    }
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_SET_MODE
        , SRV_CALLSET_RESULT_OK, mode);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_get_item
 * DESCRIPTION
 *  to get the whitelist item by index
 * PARAMETERS
 *  item : [IN][OUT] whitelist item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_whitelist_get_item(srv_callset_wl_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (item)
    {
        memset(item->number, 0, sizeof(item->number));
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_GET_ITEM
            , SRV_CALLSET_RESULT_INVALID_INPUT, -1, item, 0, 0, 0, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (item->index >= SRV_CALLSET_WHITELIST_MAX_ITEM)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_GET_ITEM
            , SRV_CALLSET_RESULT_INVALID_INPUT, item->index, item, 0, 0, 0, 0, 0);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!(srv_callset_p->whitelist_initiated))
    {
        srv_callset_init_whitelist();
    }

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (item->adv_param)
    {
        switch (item->adv_param->call_type)
        {
            case SRV_CALLSET_VOICE_CALL:
                mmi_ucs2ncpy((CHAR*)(item->number), (CHAR*)(srv_callset_p->whitelist_num[item->index]), SRV_UCM_MAX_NUM_URI_LEN);
                break;

    #ifdef __MMI_VIDEO_TELEPHONY__
            case SRV_CALLSET_VIDEO_CALL:
                mmi_ucs2ncpy((CHAR*)(item->number), (CHAR*)(srv_callset_p->whitelist_num_video[item->index]), SRV_UCM_MAX_NUM_URI_LEN);
                break;
    #endif /* __MMI_VIDEO_TELEPHONY__ */

            default:
                return SRV_CALLSET_RESULT_INVALID_INPUT;
        }
    }
    else
#else /* __MMI_CM_WHITE_LIST_EXT__ */
    {
        mmi_ucs2ncpy((CHAR*)(item->number), (CHAR*)(srv_callset_p->whitelist_num[item->index]), SRV_UCM_MAX_NUM_URI_LEN);
    }
#endif /* __MMI_CM_WHITE_LIST_EXT__ */


    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_GET_ITEM
        , SRV_CALLSET_RESULT_OK, item->index, item
        , item->number[0], item->number[1], item->number[2], item->number[3], item->number[4]);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_set_number
 * DESCRIPTION
 *  to set a whitelist number
 * PARAMETERS
 *  item : [IN] number item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_whitelist_set_number(srv_callset_wl_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    CHAR asc_num[SRV_UCM_MAX_NUM_URI_LEN + 1];
    srv_callset_wl_item_struct tmp_item;
    U32 i;
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_whitelist_adv_param_struct tmp_para;
    srv_callset_whitelist_adv_param_struct input_para;
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!item ||
        (item->index >= SRV_CALLSET_WHITELIST_MAX_ITEM))
    {
        if (item)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_SET_NUMBER
                , SRV_CALLSET_RESULT_INVALID_INPUT, item, item->index, 0, 0, 0, 0, 0);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_SET_NUMBER
                , SRV_CALLSET_RESULT_INVALID_INPUT, item, 0, 0, 0, 0, 0, 0);
        }
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    memset(asc_num, 0, sizeof(asc_num));
    mmi_ucs2_n_to_asc((CHAR*)asc_num, (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (item->adv_param)
    {
        memcpy(&tmp_para, item->adv_param, sizeof(srv_callset_whitelist_adv_param_struct));
    }
    else
    {
        srv_callset_whitelist_init_advanced_param(&tmp_para);
    }
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    if (mmi_ucs2strlen((CHAR*)item->number))
    {
        if (!srv_ucm_is_valid_number((srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, (PU8)asc_num))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_SET_NUMBER
                , SRV_CALLSET_RESULT_INVALID_FORMAT, item, item->index
                , asc_num[0], asc_num[1], asc_num[2], asc_num[3], asc_num[4]);
            return SRV_CALLSET_RESULT_INVALID_FORMAT;
        }

    #ifdef __MMI_CM_WHITE_LIST_EXT__
        if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
        {
            srv_callset_whitelist_init_advanced_param(&input_para);
            input_para.call_type = SRV_CALLSET_VOICE_CALL;
            tmp_item.adv_param = &input_para;
            
            for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
            {
                tmp_item.index = i;
            
                if ((srv_callset_whitelist_get_item(&tmp_item) == SRV_CALLSET_RESULT_OK) &&
                     srv_phb_compare_number(tmp_item.number, item->number))
                {
                    return SRV_CALLSET_RESULT_DUPLICATE;
                }
            }
        }
    
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
        {
            srv_callset_whitelist_init_advanced_param(&input_para);
            input_para.call_type = SRV_CALLSET_VIDEO_CALL;
            tmp_item.adv_param = &input_para;
            
            for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
            {
                tmp_item.index = i;
            
                if ((srv_callset_whitelist_get_item(&tmp_item) == SRV_CALLSET_RESULT_OK) &&
                     srv_phb_compare_number(tmp_item.number, item->number))
                {
                    return SRV_CALLSET_RESULT_DUPLICATE;
                }
            }
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    
    #else /* __MMI_CM_WHITE_LIST_EXT__ */
        tmp_item.adv_param = item->adv_param;
        for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
        {
            tmp_item.index = i;
    
            if ((srv_callset_whitelist_get_item(&tmp_item) == SRV_CALLSET_RESULT_OK) &&
                 srv_phb_compare_number(tmp_item.number, item->number))
            {
                return SRV_CALLSET_RESULT_DUPLICATE;
            }
        }
    #endif /* __MMI_CM_WHITE_LIST_EXT__ */
    }

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (item->adv_param)
    {
        memcpy(&tmp_para, item->adv_param, sizeof(srv_callset_whitelist_adv_param_struct));
    }
    else
    {
        srv_callset_whitelist_init_advanced_param(&tmp_para);
    }

    if ((tmp_para.call_type & SRV_CALLSET_VOICE_CALL) &&
        (mmi_ucs2ncmp((CHAR*)srv_callset_p->whitelist_num[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN)))
    {
        mmi_ucs2ncpy((CHAR*)srv_callset_p->whitelist_num[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN);
        WriteRecord(NVRAM_EF_WHITE_LIST_LID, 1, srv_callset_p->whitelist_num, sizeof(srv_callset_p->whitelist_num), &error);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if ((tmp_para.call_type & SRV_CALLSET_VIDEO_CALL) &&
        (mmi_ucs2ncmp((CHAR*)srv_callset_p->whitelist_num_video[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN)))
    {
        mmi_ucs2ncpy((CHAR*)srv_callset_p->whitelist_num_video[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN);
        WriteRecord(NVRAM_EF_WHITE_LIST_VIDEO_LID, 1, srv_callset_p->whitelist_num_video, sizeof(srv_callset_p->whitelist_num_video), &error);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#else /* __MMI_CM_WHITE_LIST_EXT__ */
    if (mmi_ucs2ncmp((CHAR*)srv_callset_p->whitelist_num[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN))
    {
        mmi_ucs2ncpy((CHAR*)srv_callset_p->whitelist_num[item->index], (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN);
        WriteRecord(NVRAM_EF_WHITE_LIST_LID, 1, srv_callset_p->whitelist_num, sizeof(srv_callset_p->whitelist_num), &error);
    }
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_SET_NUMBER
        , SRV_CALLSET_RESULT_OK, item, item->index
        , asc_num[0], asc_num[1], asc_num[2], asc_num[3], asc_num[4]);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_add_number
 * DESCRIPTION
 *  to add a number into white list
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN
 *  number : [IN] the point for the blocked number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior       
 *                   call type is allowed to be bitwised (add number to each call type),
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 *  index : [OUT] assigned index, can be NULL (don't care about the index)
 *                   index is invalid when call type is bitwised
 * RETURNS
 *  srv_callset_result_enum
 *      result is the first invalid value when call type is bitwised
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_whitelist_add_number(U8 length, WCHAR *number, srv_callset_whitelist_adv_param_struct *adv_param, PU8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    srv_callset_wl_item_struct item;
    srv_callset_result_enum result = SRV_CALLSET_RESULT_FULL;
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_result_enum tmp_result;
    srv_callset_whitelist_adv_param_struct tmp_para;
    srv_callset_whitelist_adv_param_struct input_para;
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!length || !number)
    {
//        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_ADD_NUMBER
//            , SRV_CALLSET_RESULT_EMPTY, length, number, index);
        return SRV_CALLSET_RESULT_EMPTY;
    }

    if (length > SRV_UCM_MAX_NUM_URI_LEN)
    {
//        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_ADD_NUMBER
//            , SRV_CALLSET_RESULT_TOO_LONG, length, number, index);
        return SRV_CALLSET_RESULT_TOO_LONG;
    }

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_whitelist_adv_param_struct));
    }
    else
    {
        srv_callset_whitelist_init_advanced_param(&tmp_para);
    }
    
    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        srv_callset_whitelist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VOICE_CALL;
        item.adv_param = &input_para;
        for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
        {
            item.index = i;
        
            if ((srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                !mmi_ucs2strlen((CHAR*)item.number))
            {
                if (index)
                {
                    *index = i;
                }
        
                mmi_ucs2ncpy((CHAR*)item.number, (CHAR*)number, length);
        
                result = srv_callset_whitelist_set_number(&item);
                break;
            }
        }
    }
    
#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        srv_callset_whitelist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VIDEO_CALL;
        item.adv_param = &input_para;
        for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
        {
            item.index = i;
        
            if ((srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                !mmi_ucs2strlen((CHAR*)item.number))
            {
                if (index)
                {
                    *index = i;
                }
        
                mmi_ucs2ncpy((CHAR*)item.number, (CHAR*)number, length);
        
                tmp_result = srv_callset_whitelist_set_number(&item);
                result = (result != SRV_CALLSET_RESULT_OK) ? result : tmp_result;
                break;
            }
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    
#else /* __MMI_CM_WHITE_LIST_EXT__ */
    item.adv_param = adv_param;
    for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
    {
        item.index = i;

        if ((srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
            !mmi_ucs2strlen((CHAR*)item.number))
        {
            if (index)
            {
                *index = i;
            }

            mmi_ucs2ncpy((CHAR*)item.number, (CHAR*)number, length);

            result = srv_callset_whitelist_set_number(&item);
            break;
        }
    }
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

//    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_ADD_NUMBER
//        , SRV_CALLSET_RESULT_FULL, length, number, index);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_delete_number
 * DESCRIPTION
 *  to delete a number from white list
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN
 *  number : [IN] the point for the auto answer number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior       
 *                   call type is allowed to be bitwised (add number to each call type),
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 *  index : [OUT] index of delete target, can be NULL (don't care about the index)
 *                   index is invalid when call type is bitwised
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
srv_callset_result_enum srv_callset_whitelist_delete_number(U8 length, WCHAR *number, srv_callset_whitelist_adv_param_struct *adv_param, PU8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    srv_callset_wl_item_struct item;
    srv_callset_result_enum result = SRV_CALLSET_RESULT_NOT_FOUND;
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_result_enum tmp_result;
    srv_callset_whitelist_adv_param_struct tmp_para;
    srv_callset_whitelist_adv_param_struct input_para;
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (index)
    {
        *index = 0xff;
    }

    if (!length || !number)
    {
//        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_ADD_NUMBER
//            , SRV_CALLSET_RESULT_EMPTY, length, number, index);
        return SRV_CALLSET_RESULT_EMPTY;
    }

    if (length > SRV_UCM_MAX_NUM_URI_LEN)
    {
//        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_ADD_NUMBER
//            , SRV_CALLSET_RESULT_TOO_LONG, length, number, index);
        return SRV_CALLSET_RESULT_TOO_LONG;
    }

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_whitelist_adv_param_struct));
    }
    else
    {
        srv_callset_whitelist_init_advanced_param(&tmp_para);
    }
    
    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        srv_callset_whitelist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VOICE_CALL;
        item.adv_param = &input_para;
        for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
        {
            item.index = i;
        
            if ((srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                srv_phb_compare_number(number, item.number))
            {
                if (index)
                {
                    *index = i;
                }
        
                memset(item.number, 0, sizeof(item.number));
        
                result = srv_callset_whitelist_set_number(&item);
                break;
            }
        }
    }
    
#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        srv_callset_whitelist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VIDEO_CALL;
        item.adv_param = &input_para;
        for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
        {
            item.index = i;
        
            if ((srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                srv_phb_compare_number(number, item.number))
            {
                if (index)
                {
                    *index = i;
                }
        
                memset(item.number, 0, sizeof(item.number));
        
                tmp_result = srv_callset_whitelist_set_number(&item);
                result = (result != SRV_CALLSET_RESULT_OK) ? result : tmp_result;
                break;
            }
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    
#else /* __MMI_CM_WHITE_LIST_EXT__ */
    item.adv_param = adv_param;
    for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
    {
        item.index = i;

        if ((srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
             srv_phb_compare_number(number, item.number))
        {
            if (index)
            {
                *index = i;
            }

            memset(item.number, 0, sizeof(item.number));

            result = srv_callset_whitelist_set_number(&item);
            break;
        }
    }
#endif /* __MMI_CM_WHITE_LIST_EXT__ */


//    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_ADD_NUMBER
//        , SRV_CALLSET_RESULT_NOT_FOUND, length, number, index);
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_is_auto_answer_number
 * DESCRIPTION
 *  to check if the number is an auto answer number
 * PARAMETERS
 *  length : [IN] number length, shall <= 41
 *  number : [IN] the point for the blocked number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  MMI_BOOL : TRUE if yes, FALSE if no
 *****************************************************************************/ 
MMI_BOOL srv_callset_whitelist_is_auto_answer_number(U8 length, WCHAR *number, srv_callset_whitelist_adv_param_struct *adv_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_callset_wl_item_struct item;
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_whitelist_adv_param_struct tmp_para;
    srv_callset_whitelist_adv_param_struct input_para;
#endif /* __MMI_CM_WHITE_LIST_EXT__ */
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* empty number */
    if (!length)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_IS_AUTO_ANSWER_NUMBER, MMI_FALSE, 1);
        return MMI_FALSE;
    }

    /* auto answer number in the list */
    if (!(srv_callset_whitelist_get_mode(adv_param) & SRV_CALLSET_WHITELIST_FROM_LIST))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_IS_AUTO_ANSWER_NUMBER, MMI_FALSE, 2);
        return MMI_FALSE;
    }

#ifdef __MMI_CM_WHITE_LIST_EXT__
    if (adv_param)
    {
        memcpy(&tmp_para, adv_param, sizeof(srv_callset_whitelist_adv_param_struct));
    }
    else
    {
        srv_callset_whitelist_init_advanced_param(&tmp_para);
    }
    
    if (tmp_para.call_type & SRV_CALLSET_VOICE_CALL)
    {
        srv_callset_whitelist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VOICE_CALL;
        item.adv_param = &input_para;

        if (srv_callset_whitelist_get_mode(&input_para) & SRV_CALLSET_WHITELIST_FROM_LIST)
        {
            for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
            {
                item.index = i;
            
                if (srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK)
                {
                    if (srv_phb_compare_number(number, item.number))
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_IS_AUTO_ANSWER_NUMBER, MMI_TRUE, 1);
                        return MMI_TRUE;
                    }
                }
            }
        }
    }
    
#ifdef __MMI_VIDEO_TELEPHONY__
    if (tmp_para.call_type & SRV_CALLSET_VIDEO_CALL)
    {
        srv_callset_whitelist_init_advanced_param(&input_para);
        input_para.call_type = SRV_CALLSET_VIDEO_CALL;
        item.adv_param = &input_para;

        if (srv_callset_whitelist_get_mode(&input_para) & SRV_CALLSET_WHITELIST_FROM_LIST)
        {
            for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
            {
                item.index = i;
            
                if (srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK)
                {
                    if (srv_phb_compare_number(number, item.number))
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_IS_AUTO_ANSWER_NUMBER, MMI_TRUE, 2);
                        return MMI_TRUE;
                    }
                }
            }
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    
#else /* __MMI_CM_WHITE_LIST_EXT__ */
    item.adv_param = adv_param;
    for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
    {
        item.index = i;

        if (srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK)
        {
            if (srv_phb_compare_number(number, item.number))
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_IS_AUTO_ANSWER_NUMBER, MMI_TRUE, 1);
                return MMI_TRUE;
            }
        }
    }
#endif /* __MMI_CM_WHITE_LIST_EXT__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_WHITELIST_IS_AUTO_ANSWER_NUMBER, MMI_FALSE, 3);
    return MMI_FALSE;
}


#endif /* __MMI_CM_WHITE_LIST__ */


#ifdef __MMI_CH_QUICK_END__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_auto_quick_end
 * DESCRIPTION
 *  initialiation for auto quick end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_auto_quick_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_QUICK_END_FLAG, &flag, DS_BYTE, &error);
    if ((flag != 0x00) && (flag != 0x01))
    {
        flag = 0;
        WriteValue(NVRAM_CALLSET_QUICK_END_FLAG, &flag, DS_BYTE, &error);
    }

    ReadValue(NVRAM_CALLSET_QUICK_END_TIME, &(srv_callset_p->quick_end_time), DS_SHORT, &error);
    if ((srv_callset_p->quick_end_time < SRV_CALLSET_AUTO_QUICK_END_MIN) ||
        (srv_callset_p->quick_end_time > SRV_CALLSET_AUTO_QUICK_END_MAX))
    {
        flag = 0;
        WriteValue(NVRAM_CALLSET_QUICK_END_FLAG, &flag, DS_BYTE, &error);

        srv_callset_p->quick_end_time = 0;
        WriteValue(NVRAM_CALLSET_QUICK_END_TIME, &(srv_callset_p->quick_end_time), DS_SHORT, &error);
    }

    srv_callset_p->quick_end_mode = (MMI_BOOL)flag;

    srv_callset_p->quick_end_initiated = MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_quick_end_set_mode
 * DESCRIPTION
 *  to set  auto quick end mode and time
 * PARAMETERS
 *  mode : [IN] auto quick end mode, MMI_TRUE if mode is on
 *  time : [IN] auto quick end time, SRV_CALLSET_AUTO_QUICK_END_MIN ~ SRV_CALLSET_AUTO_QUICK_END_MAX
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_auto_quick_end_set_mode(MMI_BOOL mode, U16 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((mode && (time < SRV_CALLSET_AUTO_QUICK_END_MIN)) ||
        (time > SRV_CALLSET_AUTO_QUICK_END_MAX)
        )
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_AUTO_QUICK_END_SET_MODE
            , SRV_CALLSET_RESULT_INVALID_INPUT, mode, time);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if ((srv_callset_p->quick_end_mode != mode) &&
        (WriteValue(NVRAM_CALLSET_QUICK_END_FLAG, (U8*)&mode, DS_BYTE, &error) < 0))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_AUTO_QUICK_END_SET_MODE
            , SRV_CALLSET_RESULT_UNKNOWN_ERROR, mode, time);
        return SRV_CALLSET_RESULT_UNKNOWN_ERROR;
    }

    if ((srv_callset_p->quick_end_time != time) &&
        (WriteValue(NVRAM_CALLSET_QUICK_END_TIME, &time, DS_SHORT, &error) < 0))
    {
        if (srv_callset_p->quick_end_mode != mode)
        {
            WriteValue(NVRAM_CALLSET_QUICK_END_FLAG, (U8*)&(srv_callset_p->quick_end_mode), DS_BYTE, &error);
        }
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_AUTO_QUICK_END_SET_MODE
            , SRV_CALLSET_RESULT_UNKNOWN_ERROR, mode, time);
        return SRV_CALLSET_RESULT_UNKNOWN_ERROR;
    }

    srv_callset_p->quick_end_mode = mode;
    srv_callset_p->quick_end_time = time;

    if (!(srv_callset_p->quick_end_initiated))
    {
        srv_callset_p->quick_end_initiated = MMI_TRUE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_AUTO_QUICK_END_SET_MODE
        , SRV_CALLSET_RESULT_OK, mode, time);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_quick_end_get_mode
 * DESCRIPTION
 *  to get auto quick end mode and time
 * PARAMETERS
 *  mode : [OUT] auto quick end mode, MMI_TRUE if mode is on
 *  time : [OUT] auto quick end time, SRV_CALLSET_AUTO_QUICK_END_MIN ~ SRV_CALLSET_AUTO_QUICK_END_MAX
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_auto_quick_end_get_mode(MMI_BOOL *mode, U16 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mode || !time)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_AUTO_QUICK_END_GET_MODE
            , SRV_CALLSET_RESULT_INVALID_INPUT, mode, time);
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    

    if (!(srv_callset_p->quick_end_initiated))
    {
        srv_callset_init_auto_quick_end();
    }

    *mode = srv_callset_p->quick_end_mode;
    *time = srv_callset_p->quick_end_time;

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_AUTO_QUICK_END_GET_MODE
        , SRV_CALLSET_RESULT_OK, *mode, *time);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_quick_end_get_time
 * DESCRIPTION
 *  to get auto quick end time in sec.
 * PARAMETERS
 *  void
 * RETURNS
 *  auto quick end time; 0 if the mode is off; 
 *****************************************************************************/
U16 srv_callset_auto_quick_end_get_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL mode;
    U16 time;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_auto_quick_end_get_mode(&mode, &time) != SRV_CALLSET_RESULT_OK)
    {
        return 0;
    }

    if (mode)
    {
        return time;
    }
    else
    {
        return 0;
    }
}
#endif /* __MMI_CH_QUICK_END__ */


#ifdef __CTM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void    
 * RETURNS
 *  mode
 *****************************************************************************/
void srv_callset_init_ctm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadValue(NVRAM_CALLSET_CTM_MODE, &flag, DS_BYTE, &error);
    if ((flag != 0x00) && (flag != 0x01))
    {
        flag = 0;
        WriteValue(NVRAM_CALLSET_CTM_MODE, &flag, DS_BYTE, &error);
    }

    ReadValue(NVRAM_CALLSET_CTM_SETTING, &(srv_callset_p->ctm_setting), DS_BYTE, &error);
    if (srv_callset_p->ctm_setting >= SRV_CALLSET_CTM_SETTING_UNKNOWN)
    {
        flag = 0;
        WriteValue(NVRAM_CALLSET_CTM_MODE, &flag, DS_BYTE, &error);

        srv_callset_p->ctm_setting = (srv_callset_ctm_setting_enum)0;
        WriteValue(NVRAM_CALLSET_CTM_SETTING, &(srv_callset_p->ctm_setting), DS_BYTE, &error);
    }

    srv_callset_p->ctm_mode = (MMI_BOOL)flag;

    srv_callset_post_ctm_setting_changed_ind_evt();

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_get_mode
 * DESCRIPTION
 *  get CTM mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if ctm is on
 *****************************************************************************/
MMI_BOOL srv_callset_ctm_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_callset_p->ctm_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_get_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void    
 * RETURNS
 *  mode
 *****************************************************************************/
srv_callset_ctm_setting_enum srv_callset_ctm_get_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_callset_p->ctm_setting;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_permit_set_mode
 * DESCRIPTION
 *  check if it is allowed to switch CTM setting
 * PARAMETERS
 *  
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ctm_permit_switch_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ctm_setting_struct setting;
    srv_callset_result_enum result;
	U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    setting.mode = MMI_TRUE;

	for (i = 0; i < SRV_CALLSET_CTM_SETTING_UNKNOWN; i++)
	{
		setting.setting = (srv_callset_ctm_setting_enum)i;
		result = srv_callset_ctm_permit_set_mode(&setting);
		if (result == SRV_CALLSET_RESULT_OK)
		{
			return SRV_CALLSET_RESULT_OK;
		}
	}
	
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_permit_set_mode
 * DESCRIPTION
 *  check if change CTM mode or setting is allowed
 * PARAMETERS
 *  info    [IN]    srv_callset_ctm_setting_struct    
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ctm_permit_set_mode(srv_callset_ctm_setting_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info ||
        (info->setting >= SRV_CALLSET_CTM_SETTING_UNKNOWN))
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!srv_ucm_query_call_count(
            (srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, 
            (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, 
            NULL))
    {
        return SRV_CALLSET_RESULT_OK;
    }

    /* there are calls */
    if ((srv_ucm_query_call_count(
            (srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, 
            (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, 
            NULL) != 1) ||
        !srv_ucm_query_call_count(
            SRV_UCM_ACTIVE_STATE, 
            (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, 
            NULL))
    {
        return SRV_CALLSET_RESULT_NOT_AVAILABLE_INCALL;
    }

    /* there is only 1 active call */
    if (!srv_callset_p->ctm_mode ||
        !info->mode ||
        (srv_callset_p->ctm_setting == SRV_CALLSET_CTM_SETTING_MANUAL_DIRECT) ||
        (srv_callset_p->ctm_setting == SRV_CALLSET_CTM_SETTING_AUTO_DIRECT) ||
        (info->setting == SRV_CALLSET_CTM_SETTING_MANUAL_DIRECT) ||
        (info->setting == SRV_CALLSET_CTM_SETTING_AUTO_DIRECT))
    {
        return SRV_CALLSET_RESULT_NOT_AVAILABLE_INCALL;
    }


    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_set_mode
 * DESCRIPTION
 *  set CTM setting
 * PARAMETERS
 *  info    [IN]    srv_callset_ctm_setting_struct    
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_ctm_set_mode(srv_callset_ctm_setting_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_enum result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_callset_ctm_permit_set_mode(info);
    if (result != SRV_CALLSET_RESULT_OK)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTM_SET_MODE
            , result, info ? info->mode : 0, info ? info->setting : 0);
        return result;
    }

    if ((info->mode == srv_callset_p->ctm_mode) &&
        (info->setting == srv_callset_p->ctm_setting))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTM_SET_MODE_IGNORE);
        return SRV_CALLSET_RESULT_OK;
    }

    if (srv_callset_p->ctm_mode != info->mode)
    {
        srv_callset_p->ctm_mode = info->mode;
        WriteValue(NVRAM_CALLSET_CTM_MODE, &(srv_callset_p->ctm_mode), DS_BYTE, &error);
    }
    if (info->setting != srv_callset_p->ctm_setting)
    {
        srv_callset_p->ctm_setting = info->setting;
        WriteValue(NVRAM_CALLSET_CTM_SETTING, &(srv_callset_p->ctm_setting), DS_BYTE, &error);
    }
    srv_callset_post_ctm_setting_changed_ind_evt();

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_CTM_SET_MODE
        , SRV_CALLSET_RESULT_OK, info ? info->mode : 0, info ? info->setting : 0);
    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_is_tty_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_callset_ctm_is_tty_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TTY on depends on status and setting */
    /* TTY status depends on status and earphone plug in or not */
    if (srv_callset_p->ctm_mode && 
        (srv_callset_p->ctm_setting == SRV_CALLSET_CTM_SETTING_BAUDOT ||
         srv_callset_p->ctm_setting == SRV_CALLSET_CTM_SETTING_HCO ||
         srv_callset_p->ctm_setting == SRV_CALLSET_CTM_SETTING_VCO))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __CTM_SUPPORT__ */


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_vt
 * DESCRIPTION
 *  Init vt setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_vt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    S16 errorCode = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* answer mode */
    ReadValue(NVRAM_CALLSET_VT_ANSWER_MODE, &index, DS_BYTE, &errorCode);
    
    if (index >= (U8)SRV_CALLSET_VT_ANSWER_MODE_END_OF_ENUM)
    {
        index = (U8)SRV_CALLSET_VT_ANSWER_MODE_PROMPT;
        WriteValue(NVRAM_CALLSET_VT_ANSWER_MODE, &index, DS_BYTE, &errorCode);
    }
    srv_callset_p->vt_setting.answer_mode = (srv_callset_vt_answer_mode_enum)index;


    /* dial mode */
    ReadValue(NVRAM_CALLSET_VT_DIAL_MODE, &index, DS_BYTE, &errorCode);
    
    if (index >= (U8)SRV_CALLSET_VT_DIAL_MODE_END_OF_ENUM)
    {
        index = (U8)SRV_CALLSET_VT_DIAL_MODE_START_CAMERA;
        WriteValue(NVRAM_CALLSET_VT_DIAL_MODE, &index, DS_BYTE, &errorCode);
    }
    srv_callset_p->vt_setting.dial_mode = (srv_callset_vt_dial_mode_enum)index;


    /* mic */
    ReadValue(NVRAM_CALLSET_VT_MIC, &index, DS_BYTE, &errorCode);
    if (index > 1)
    {
        index = 1;
        WriteValue(NVRAM_CALLSET_VT_MIC, &index, DS_BYTE, &errorCode);
    }
    srv_callset_p->vt_setting.mic= (MMI_BOOL)index;

    /* speaker */
    ReadValue(NVRAM_CALLSET_VT_SPEAKER, &index, DS_BYTE, &errorCode);
    if (index > 1)
    {
        index = 1;
        WriteValue(NVRAM_CALLSET_VT_SPEAKER, &index, DS_BYTE, &errorCode);
    }
    srv_callset_p->vt_setting.speaker = (MMI_BOOL)index;


    /* incall image */
    memset(srv_callset_p->vt_setting.incall_image_file_path, 0, sizeof(srv_callset_p->vt_setting.incall_image_file_path));
    ReadRecord(
        NVRAM_EF_VT_SETTING_LID,
        1,
        (void*)&srv_callset_p->vt_setting.incall_image_file_path,
        (SRV_FMGR_PATH_MAX_LEN+1)*ENCODING_LENGTH,
        &errorCode);


    /* camera mode */
    ReadValue(NVRAM_CALLSET_VT_CAMERA, &index, DS_BYTE, &errorCode);
    if (index >= (U8)SRV_CALLSET_VT_CAMERA_END_OF_ENUM)
    {
        index = (U8)SRV_CALLSET_VT_CAMERA_FRONT;
        WriteValue(NVRAM_CALLSET_VT_CAMERA, &index, DS_BYTE, &errorCode);
    }
    srv_callset_p->vt_setting.camera_mode = (srv_callset_vt_camera_mode_enum)index;


    /* night mode */
    ReadValue(NVRAM_CALLSET_VT_NIGHT_FRONT, &index, DS_BYTE, &errorCode);
    if (index > 1)
    {
        index = 0;
        WriteValue(NVRAM_CALLSET_VT_NIGHT_FRONT, &index, DS_BYTE, &errorCode);
    }
    srv_callset_p->vt_setting.night_mode_front = (MMI_BOOL)index;

    ReadValue(NVRAM_CALLSET_VT_NIGHT_BACK, &index, DS_BYTE, &errorCode);
    if (index > 1)
    {
        index = 0;
        WriteValue(NVRAM_CALLSET_VT_NIGHT_BACK, &index, DS_BYTE, &errorCode);
    }
    srv_callset_p->vt_setting.night_mode_back = (MMI_BOOL)index;


    /* ev */
    ReadValue(NVRAM_CALLSET_VT_EV_FRONT, &index, DS_BYTE, &errorCode);
    srv_callset_p->vt_setting.ev_front = (srv_callset_vt_ev_enum)index;

    ReadValue(NVRAM_CALLSET_VT_EV_BACK, &index, DS_BYTE, &errorCode);
    srv_callset_p->vt_setting.ev_back = (srv_callset_vt_ev_enum)index;


    /* zoom */
    ReadValue(NVRAM_CALLSET_VT_ZOOM_FRONT, &index, DS_BYTE, &errorCode);
    srv_callset_p->vt_setting.zoom_front = index;

    ReadValue(NVRAM_CALLSET_VT_ZOOM_BACK, &index, DS_BYTE, &errorCode);
    srv_callset_p->vt_setting.zoom_back = index;


    srv_callset_p->vt_setting.initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_dial_mode
 * DESCRIPTION
 *  get vt dial mode
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_vt_dial_mode_enum
 *****************************************************************************/
srv_callset_vt_dial_mode_enum srv_callset_vt_get_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    return srv_callset_p->vt_setting.dial_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_dial_mode
 * DESCRIPTION
 *  set vt dial mode
 * PARAMETERS
 *  mode    [IN]    srv_callset_result_enum
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_dial_mode(srv_callset_vt_dial_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mode >= SRV_CALLSET_VT_DIAL_MODE_END_OF_ENUM)
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    if (mode != srv_callset_p->vt_setting.dial_mode)
    {
        data = (U8)mode;
        WriteValue(NVRAM_CALLSET_VT_DIAL_MODE, &data, DS_BYTE, &error);
        srv_callset_p->vt_setting.dial_mode = mode;
    }

    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_answer_mode
 * DESCRIPTION
 *  get vt answer mode
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_vt_answer_mode_enum
 *****************************************************************************/
srv_callset_vt_answer_mode_enum srv_callset_vt_get_answer_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    return srv_callset_p->vt_setting.answer_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_answer_mode
 * DESCRIPTION
 *  set vt answer mode
 * PARAMETERS
 *  mode    [IN]    srv_callset_result_enum
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_answer_mode(srv_callset_vt_answer_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mode >= SRV_CALLSET_VT_ANSWER_MODE_END_OF_ENUM)
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    if (mode != srv_callset_p->vt_setting.answer_mode)
    {
        data = (U8)mode;
        WriteValue(NVRAM_CALLSET_VT_ANSWER_MODE, &data, DS_BYTE, &error);
        srv_callset_p->vt_setting.answer_mode = mode;
    }

    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_mic_mode
 * DESCRIPTION
 *  get vt mic mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means mic is on
 *****************************************************************************/
MMI_BOOL srv_callset_vt_get_mic_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    return srv_callset_p->vt_setting.mic;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_mic_mode
 * DESCRIPTION
 *  set vt mic mode
 * PARAMETERS
 *  mode    [IN]    MMI_BOOL, MMI_TRUE means mic is on
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_mic_mode(MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    if (mode != srv_callset_p->vt_setting.mic)
    {
        data = (U8)mode;
        WriteValue(NVRAM_CALLSET_VT_MIC, &data, DS_BYTE, &error);
        srv_callset_p->vt_setting.mic = mode;
    }

    return SRV_CALLSET_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_speaker_mode
 * DESCRIPTION
 *  get vt speaker mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means speaker is on
 *****************************************************************************/
MMI_BOOL srv_callset_vt_get_speaker_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    return srv_callset_p->vt_setting.speaker;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_speaker_mode
 * DESCRIPTION
 *  set vt speaker mode
 * PARAMETERS
 *  mode    [IN]    MMI_BOOL, MMI_TRUE means speaker is on
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_speaker_mode(MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    if (mode != srv_callset_p->vt_setting.speaker)
    {
        data = (U8)mode;
        WriteValue(NVRAM_CALLSET_VT_SPEAKER, &data, DS_BYTE, &error);
        srv_callset_p->vt_setting.speaker = mode;
    }

    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_night_mode
 * DESCRIPTION
 *  get vt night mode
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 * RETURNS
 *  MMI_TRUE means night mode is on
 *****************************************************************************/
MMI_BOOL srv_callset_vt_get_night_mode(srv_callset_vt_camera_mode_enum cam_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    switch (cam_mode)
    {
        case SRV_CALLSET_VT_CAMERA_FRONT:
            return srv_callset_p->vt_setting.night_mode_front;

        case SRV_CALLSET_VT_CAMERA_BACK:
            return srv_callset_p->vt_setting.night_mode_back;

        default:
            return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_night_mode
 * DESCRIPTION
 *  set vt night mode
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 *  mode    [IN]    MMI_BOOL, MMI_TRUE means night mode is on
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_night_mode(srv_callset_vt_camera_mode_enum cam_mode, MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    switch (cam_mode)
    {
        case SRV_CALLSET_VT_CAMERA_FRONT:
            if (mode != srv_callset_p->vt_setting.night_mode_front)
            {
                WriteValue(NVRAM_CALLSET_VT_NIGHT_FRONT, &mode, DS_BYTE, &error);
                srv_callset_p->vt_setting.night_mode_front = mode;
            }
            break;

        case SRV_CALLSET_VT_CAMERA_BACK:
            if (mode != srv_callset_p->vt_setting.night_mode_back)
            {
                WriteValue(NVRAM_CALLSET_VT_NIGHT_BACK, &mode, DS_BYTE, &error);
                srv_callset_p->vt_setting.night_mode_back = mode;
            }
            break;

        default:
            return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    return SRV_CALLSET_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_ev
 * DESCRIPTION
 *  get vt ev
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 * RETURNS
 *  EV value for the specific camera mode
 *****************************************************************************/
srv_callset_vt_ev_enum srv_callset_vt_get_ev(srv_callset_vt_camera_mode_enum cam_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    switch (cam_mode)
    {
        case SRV_CALLSET_VT_CAMERA_FRONT:
            return srv_callset_p->vt_setting.ev_front;

        case SRV_CALLSET_VT_CAMERA_BACK:
            return srv_callset_p->vt_setting.ev_back;

        default:
            return SRV_CALLSET_VT_EV_INVALID;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_ev
 * DESCRIPTION
 *  set vt ev
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 *  ev    [IN]    ev value
 * RETURNS
 *  result
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_ev(srv_callset_vt_camera_mode_enum cam_mode, srv_callset_vt_ev_enum ev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    switch (cam_mode)
    {
        case SRV_CALLSET_VT_CAMERA_FRONT:
            if (ev != srv_callset_p->vt_setting.ev_front)
            {
                WriteValue(NVRAM_CALLSET_VT_EV_FRONT, &ev, DS_BYTE, &error);
                srv_callset_p->vt_setting.ev_front = ev;
            }
            break;

        case SRV_CALLSET_VT_CAMERA_BACK:
            if (ev != srv_callset_p->vt_setting.ev_back)
            {
                WriteValue(NVRAM_CALLSET_VT_EV_BACK, &ev, DS_BYTE, &error);
                srv_callset_p->vt_setting.ev_back = ev;
            }
            break;

        default:
            return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_zoom
 * DESCRIPTION
 *  get vt zoom
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 * RETURNS
 *  Zoom value for the specific camera mode, 0xff if invalid
 *****************************************************************************/
U8 srv_callset_vt_get_zoom(srv_callset_vt_camera_mode_enum cam_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    switch (cam_mode)
    {
        case SRV_CALLSET_VT_CAMERA_FRONT:
            return srv_callset_p->vt_setting.zoom_front;

        case SRV_CALLSET_VT_CAMERA_BACK:
            return srv_callset_p->vt_setting.zoom_back;

        default:
            return 0xff;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_zoom
 * DESCRIPTION
 *  set vt zoom
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 *  zoom    [IN]    zoom value
 * RETURNS
 *  result
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_zoom(srv_callset_vt_camera_mode_enum cam_mode, U8 zoom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    switch (cam_mode)
    {
        case SRV_CALLSET_VT_CAMERA_FRONT:
            if (zoom != srv_callset_p->vt_setting.zoom_front)
            {
                WriteValue(NVRAM_CALLSET_VT_ZOOM_FRONT, &zoom, DS_BYTE, &error);
                srv_callset_p->vt_setting.zoom_front = zoom;
            }
            break;

        case SRV_CALLSET_VT_CAMERA_BACK:
            if (zoom != srv_callset_p->vt_setting.zoom_back)
            {
                WriteValue(NVRAM_CALLSET_VT_ZOOM_BACK, &zoom, DS_BYTE, &error);
                srv_callset_p->vt_setting.zoom_back = zoom;
            }
            break;

        default:
            return SRV_CALLSET_RESULT_INVALID_INPUT;
    }
    return SRV_CALLSET_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_camera_mode
 * DESCRIPTION
 *  get vt camera mode
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_vt_camera_mode_enum
 *****************************************************************************/
srv_callset_vt_camera_mode_enum srv_callset_vt_get_camera_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    return srv_callset_p->vt_setting.camera_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_camera_mode
 * DESCRIPTION
 *  set vt camera mode
 * PARAMETERS
 *  mode    [IN]    srv_callset_result_enum
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_camera_mode(srv_callset_vt_camera_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mode >= SRV_CALLSET_VT_CAMERA_END_OF_ENUM)
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    if (mode != srv_callset_p->vt_setting.camera_mode)
    {
        data = (U8)mode;
        WriteValue(NVRAM_CALLSET_VT_CAMERA, &data, DS_BYTE, &error);
        srv_callset_p->vt_setting.camera_mode = mode;
    }

    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_incall_image_path
 * DESCRIPTION
 *  set vt incall image path
 * PARAMETERS
 *  length  [IN]    path length in characters (NOT bytes and NOT including the null terminater)
 *  path    [IN]    file path
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_set_incall_image_path(U32 length, PU16 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!length || !path || (length > SRV_FMGR_PATH_MAX_LEN))
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    if (mmi_ucs2ncmp((CHAR*)path, (CHAR*)srv_callset_p->vt_setting.incall_image_file_path, length))
    {
        mmi_ucs2ncpy((CHAR*)srv_callset_p->vt_setting.incall_image_file_path, (CHAR*)path, length);
        WriteRecord(
            NVRAM_EF_VT_SETTING_LID,
            1,
            srv_callset_p->vt_setting.incall_image_file_path,
            (SRV_FMGR_PATH_MAX_LEN+1)*ENCODING_LENGTH,
            &error);
    }

    return SRV_CALLSET_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_incall_image_path
 * DESCRIPTION
 *  set vt incall image path
 * PARAMETERS
 *  length  [IN]    path length in characters (NOT bytes and NOT including the null terminater)
 *  path    [OUT]    file path buffer, shall be allocated by the caller
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
srv_callset_result_enum srv_callset_vt_get_incall_image_path(U32 length, PU16 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!length || !path || (length > SRV_FMGR_PATH_MAX_LEN))
    {
        return SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    if (!srv_callset_p->vt_setting.initiated)
    {
        srv_callset_init_vt();
    }

    mmi_ucs2ncpy((CHAR*)path, (CHAR*)srv_callset_p->vt_setting.incall_image_file_path, length);

    return SRV_CALLSET_RESULT_OK;
}

#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_delay_dial
 * DESCRIPTION
 *  Init delay dial setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_delay_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    S16 errorCode = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadValue(NVRAM_CALLSET_DELAY_DIAL_TIME, &index, DS_BYTE, &errorCode);
    srv_callset_p->delay_dial_time = index;

    srv_callset_p->delay_dial_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_delay_dial_get_time
 * DESCRIPTION
 *  get delay dial time
 * PARAMETERS
 *  void
 * RETURNS
 *  delay dial time (dial after 1~255 seconds, 0 means OFF)
 *****************************************************************************/
U8 srv_callset_delay_dial_get_time(void)
{
    if (!srv_callset_p->delay_dial_initiated)
    {
        srv_callset_init_delay_dial();
    }

    return srv_callset_p->delay_dial_time;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_delay_dial_set_time
 * DESCRIPTION
 *  set delay dial time
 * PARAMETERS
 *  time [IN] delay dial time (dial after 1~255 seconds, 0 means OFF)
 * RETURNS
 *  result
 *****************************************************************************/
srv_callset_result_enum srv_callset_delay_dial_set_time(U8 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->delay_dial_initiated)
    {
        srv_callset_init_delay_dial();
    }

    if (time != srv_callset_p->delay_dial_time)
    {
        WriteValue(NVRAM_CALLSET_DELAY_DIAL_TIME, &time, DS_BYTE, &error);
        srv_callset_p->delay_dial_time = time;
    }

    return SRV_CALLSET_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_fwp
 * DESCRIPTION
 *  Init Fixed Wireless telePhone features
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_fwp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    S16 errorCode = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadValue(NVRAM_CALLSET_OFFHOOK_REMINDER_TIMEOUT, &index, DS_BYTE, &errorCode);
    srv_callset_p->offhook_reminder_timeout = index;

    ReadValue(NVRAM_CALLSET_OFFHOOK_REMINDER_DURATION, &index, DS_BYTE, &errorCode);
    srv_callset_p->offhook_reminder_duration = index;

    srv_callset_p->fwp_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_fwp_get_offhook_reminder
 * DESCRIPTION
 *  Fixed Wireless telePhone feature: get offhook reminder setting
 * PARAMETERS
 *  timeout [OUT] off-hook timeout in seconds to start the reminder, could be NULL
 *  duration [OUT] off-hook reminder duration in seconds, could be NULL
 * RETURNS
 *  result
 *****************************************************************************/
srv_callset_result_enum srv_callset_fwp_get_offhook_reminder(U8 *timeout, U8 *duration)
{
    if (!srv_callset_p->fwp_initiated)
    {
        srv_callset_init_fwp();
    }

    if (timeout)
    {
        *timeout = srv_callset_p->offhook_reminder_timeout;
    }

    if (duration)
    {
        *duration = srv_callset_p->offhook_reminder_duration;
    }

    return SRV_CALLSET_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_fwp_set_offhook_reminder
 * DESCRIPTION
 *  Fixed Wireless telePhone feature: set offhook reminder setting
 * PARAMETERS
 *  timeout [IN] off-hook timeout in seconds to start the reminder
 *  duration [IN] off-hook reminder duration in seconds
 * RETURNS
 *  result
 *****************************************************************************/
srv_callset_result_enum srv_callset_fwp_set_offhook_reminder(U8 timeout, U8 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_callset_p->fwp_initiated)
    {
        srv_callset_init_fwp();
    }

    if (timeout != srv_callset_p->offhook_reminder_timeout)
    {
        WriteValue(NVRAM_CALLSET_OFFHOOK_REMINDER_TIMEOUT, &timeout, DS_BYTE, &error);
        srv_callset_p->offhook_reminder_timeout = timeout;
    }

    if (duration != srv_callset_p->offhook_reminder_duration)
    {
        WriteValue(NVRAM_CALLSET_OFFHOOK_REMINDER_DURATION, &duration, DS_BYTE, &error);
        srv_callset_p->offhook_reminder_duration = duration;
    }

    return SRV_CALLSET_RESULT_OK;

}

#endif /* __OP01_FWPBW__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_sim_cntx_set_ptr
 * DESCRIPTION
 *  reset sim context pointer (unlock sim context) 
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_sim_cntx_set_ptr(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_callset_sim_p)
    {
        MMI_ASSERT(0);
    }

    /* lock srv_callset_sim_p */
	srv_callset_sim_p = &g_srv_callset_context.sim_cntx[mmi_frm_sim_to_index(sim)];

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_SIM_CNTX_SET_PTR, sim);
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_sim_cntx_reset_ptr
 * DESCRIPTION
 *  reset sim context pointer (unlock sim context)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_sim_cntx_reset_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* unlock */
    /* Shall reset cntxt ptr after all cntxt related operation is done */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_SIM_CNTX_RESET_PTR);

    srv_callset_sim_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_sim_cntx_is_locked
 * DESCRIPTION
 *  check if sim context is locked
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if it is locked
 *****************************************************************************/
MMI_BOOL srv_callset_sim_cntx_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_callset_sim_p ? MMI_TRUE : MMI_FALSE;
}

#ifdef MOTION_SENSOR_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_flip_to_mute_call
 * DESCRIPTION
 *  initialiation for flip to mute call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_flip_to_mute_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_FLIP_TO_MUTE_CALL, &data, DS_BYTE, &error);

    if (data == 0x01)
    {
        srv_callset_p->flip_to_mute_call_mode = MMI_TRUE;
    }
    else if (data == 0x00)
    {
        srv_callset_p->flip_to_mute_call_mode = MMI_FALSE;
    }
    else
    {
        data = 0x01;
        srv_callset_p->flip_to_mute_call_mode = MMI_TRUE;
        WriteValue(NVRAM_CALLSET_FLIP_TO_MUTE_CALL, &data, DS_BYTE, &error);
    }

    srv_callset_p->flip_to_mute_call_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_flip_to_mute_call_get_mode
 * DESCRIPTION
 *  to set the flip to mute call mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE if the mode is on; MMI_FALSE if the mode is off or not available
 *****************************************************************************/
MMI_BOOL srv_callset_flip_to_mute_call_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->flip_to_mute_call_initiated))
    {
        srv_callset_init_flip_to_mute_call();
    }

    return srv_callset_p->flip_to_mute_call_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_flip_to_mute_call_set_mode
 * DESCRIPTION
 *  to set the flip to mute call mode, if the new mode is not same as old emit a event
 * PARAMETERS
 *  mode : [IN] MMI_TRUE if on, MMI_FALSE if off
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_callset_flip_to_mute_call_set_mode(MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    srv_callset_flip_to_mute_call_changed_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->flip_to_mute_call_initiated))
    {
        srv_callset_init_flip_to_mute_call();
    }

    if (mode != srv_callset_p->flip_to_mute_call_mode)
    {
        data = mode ? 1 : 0;
        WriteValue(NVRAM_CALLSET_FLIP_TO_MUTE_CALL, &data, DS_BYTE, &error);
        srv_callset_p->flip_to_mute_call_mode = mode;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_FLIP_TO_MUTE_CALL);
        MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct*)(&evt));
    }
}
/* #endif  __MMI_CONNECT_NOTICE__ */


/* #ifdef __MMI_TAP_TAP_TO_RECORD_IN_CALL__ */
/*****************************************************************************
 * FUNCTION
 *  srv_callset_init_tap_tap_to_record_in_call
 * DESCRIPTION
 *  initialiation for tap-tap to record in-call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_callset_init_tap_tap_to_record_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CALLSET_TAP_TAP_TO_RECORD_IN_CALL, &data, DS_BYTE, &error);

    if (data == 0x01)
    {
        srv_callset_p->tap_tap_to_record_in_call_mode= MMI_TRUE;
    }
    else if (data == 0x00)
    {
        srv_callset_p->tap_tap_to_record_in_call_mode = MMI_FALSE;
    }
    else
    {
        data = 0x01;
        srv_callset_p->tap_tap_to_record_in_call_mode = MMI_TRUE;
        WriteValue(NVRAM_CALLSET_TAP_TAP_TO_RECORD_IN_CALL, &data, DS_BYTE, &error);
    }

    srv_callset_p->tap_tap_to_record_in_call_initiated = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_tap_tap_to_record_in_call_get_mode
 * DESCRIPTION
 *  to set the tap-tap to record in-call mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE if the mode is on; MMI_FALSE if the mode is off or not available
 *****************************************************************************/
MMI_BOOL srv_callset_tap_tap_to_record_in_call_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->tap_tap_to_record_in_call_initiated))
    {
        srv_callset_init_tap_tap_to_record_in_call();
    }

    return srv_callset_p->tap_tap_to_record_in_call_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_tap_tap_to_record_in_call_set_mode
 * DESCRIPTION
 *  to set the flip to mute call mode, if the new mode is not same as old emit a event
 * PARAMETERS
 *  mode : [IN] MMI_TRUE if on, MMI_FALSE if off
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_callset_tap_tap_to_record_in_call_set_mode(MMI_BOOL mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
    srv_callset_tap_tap_to_record_in_call_changed_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_callset_p->tap_tap_to_record_in_call_initiated))
    {
        srv_callset_init_tap_tap_to_record_in_call();
    }

    if (mode != srv_callset_p->tap_tap_to_record_in_call_mode)
    {
        data = mode ? 1 : 0;
        WriteValue(NVRAM_CALLSET_TAP_TAP_TO_RECORD_IN_CALL, &data, DS_BYTE, &error);
        srv_callset_p->tap_tap_to_record_in_call_mode = mode;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_TAP_TAP_TO_RECORD_IN_CALL);
        MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct*)(&evt));
    }
}
#endif

