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
 *  BootupSrvProtocol.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mode & L4C power-on controller of bootup.
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "BootupSrv.h"
#include "UtilitySrvGprot.h"
#include "mmi_msg_struct.h"
#include "ModeSwitchAppGProt.h"
#include "ModeSwitchSrvGProt.h"
#include "PhoneSetup.h"


#include "MMIDataType.h"
#include "kal_general_types.h"
#include "BootupSrvIprot.h"
#include "stack_config.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_common.h"
#include "kal_public_api.h"
#include "l4c_nw_cmd.h"
#include "mmi_frm_utility_gprot.h"
#include "SimCtrlSrvGprot.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
#if (MMI_MAX_SIM_NUM >= 2)
    U8 dual_sim_mode_setting;
#endif

    MMI_BOOL sim_inited;
    srv_bootup_protocol_query_enum query_setting;

    struct
    {
        /* The bit set of SIMs which need to send CFUN_STATE_REQ with 1 */
        srv_bootup_sim_bit_set to_be_enabled;
        /* The bit set of SIMs which CFUN_STATE_REQ was sent */
        srv_bootup_sim_bit_set cfun_sent;
        /* The bit set of SIMs which is being waited for response */
        srv_bootup_sim_bit_set waiting;
        /* The bit set of SIMs which CFUN_STATE_RSP was received */
        srv_bootup_sim_bit_set cfun_rsp;
    } control;

    void *user_data;
    srv_bootup_work_completed_callback completed_callback;
} srv_bootup_protocol_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static srv_bootup_protocol_cntx_struct g_srv_bootup_protocol_cntx;


/****************************************************************************
 * Local functions
 ****************************************************************************/

#if (MMI_MAX_SIM_NUM >= 2)
static U8 srv_bootup_sim_status_update_ind_received(void *msg);
static void srv_bootup_protocol_boot_multiple_sims(srv_bootup_protocol_mode_enum mode);
#endif

static MMI_BOOL srv_bootup_protocol_l4_response_hdlr(void *msg, S32 src_mod);

#if (MMI_MAX_SIM_NUM == 1)
static MMI_BOOL srv_bootup_protocol_cfun_state_rsp_hdlr(void *msg, S32 src_mod);
#else
static MMI_BOOL srv_bootup_protocol_efun_state_rsp_hdlr(void *msg, S32 src_mod);
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_init
 * DESCRIPTION
 *  Initialize the protocol module of bootup service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bootup_protocol_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * Do not set protocol event handlers here because the bootup main flow
     * will clean all of them.
     */

    g_srv_bootup_protocol_cntx.query_setting = SRV_BOOTUP_PROTOCOL_QUERY_INVALID;
    
#if (MMI_MAX_SIM_NUM >= 2)
    g_srv_bootup_protocol_cntx.sim_inited = MMI_FALSE;
#endif
    g_srv_bootup_protocol_cntx.control.cfun_sent = 0;

    srv_boootup_cv_init();

#if (MMI_MAX_SIM_NUM >= 2)
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_IND, srv_bootup_sim_status_update_ind_received, MMI_TRUE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_emit_sim_slot_ready_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_emit_sim_slot_ready_event(void)
{
#if (MMI_MAX_SIM_NUM >= 2)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    S32 i;
    S32 n_inserted;
    U32 inserted_sims_bit_set;
    srv_bootup_sim_slot_ready_evt_struct ready_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_inserted = 0;
    inserted_sims_bit_set = 0;

    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        srv_bootup_sim_cntx_struct *sim_cntx = srv_bootup_get_sim_cntx(sim);
        if (sim_cntx->is_inserted)
        {
            n_inserted++;
            inserted_sims_bit_set |= sim;
        }
    }

    MMI_FRM_INIT_EVENT(&ready_evt, EVT_ID_SRV_BOOTUP_SIM_SLOT_READY);
    ready_evt.n_inserted = n_inserted;
    ready_evt.inserted_sims = inserted_sims_bit_set;
    /* srv_bootup_emit_sim_slot_ready_event() will not be called in app's callstack */
    MMI_FRM_CB_EMIT_EVENT(&ready_evt);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_init_sim_callback_proc
 * DESCRIPTION
 *  Callback the completed callback
 * PARAMETERS
 *  *evt        [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_bootup_init_sim_callback_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_bootup_protocol_cntx.completed_callback != NULL)
    {
        srv_bootup_work_completed_callback callback;
        void *user_data;
        
        callback = g_srv_bootup_protocol_cntx.completed_callback;
        user_data = g_srv_bootup_protocol_cntx.user_data;
        g_srv_bootup_protocol_cntx.completed_callback = NULL;
        g_srv_bootup_protocol_cntx.user_data = NULL;
        
        srv_bootup_emit_sim_slot_ready_event();
        callback(user_data);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
void srv_bootup_init_sim_module(
        srv_bootup_work_completed_callback completed_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_INIT_SIM_MODULE, (U32)completed_callback);

    g_srv_bootup_protocol_cntx.user_data = user_data;
    g_srv_bootup_protocol_cntx.completed_callback = completed_callback;

    if (g_srv_bootup_protocol_cntx.sim_inited)
    {
        mmi_event_struct evt;
            
        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, srv_bootup_init_sim_callback_proc, NULL);
    }
}


/* mmi_smu_sim_status_update_ind_struct is not available on single SIM project */
#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sim_status_update_ind_received
 * DESCRIPTION
 *  The handler of SMU_SIM_STATUS_UPDATE_IND.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_bootup_sim_status_update_ind_received(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_cntx_struct *sim_cntx;
    mmi_smu_sim_status_update_ind_struct *sim_status_update_ind;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_status_update_ind = (mmi_smu_sim_status_update_ind_struct*)msg;

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        sim_cntx = srv_bootup_get_sim_cntx(sim);
        if ((sim_status_update_ind->sim_inserted_status & sim) != 0)
        {
            sim_cntx->is_inserted = MMI_TRUE;
        }
        else
        {
            sim_cntx->is_inserted = MMI_FALSE;
        }
    }

    /* We don't callback again if SIM already inited */
    if (!g_srv_bootup_protocol_cntx.sim_inited)
    {
        g_srv_bootup_protocol_cntx.sim_inited = MMI_TRUE;

        /*
         * Post callback, so that SimCtrl status can be updated first,
         * then continue booting.
         */
        if (g_srv_bootup_protocol_cntx.completed_callback != NULL)
        {
            mmi_event_struct evt;
                
            MMI_FRM_INIT_EVENT(&evt, 0);
            MMI_FRM_POST_EVENT(&evt, srv_bootup_init_sim_callback_proc, NULL);
        }
    }

    return (U8)MMI_FALSE;
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
MMI_BOOL srv_bootup_sim_is_inserted(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * This status is known only after srv_bootup_init_sim_module()
     * was called.
     */
    MMI_ASSERT(g_srv_bootup_protocol_cntx.sim_inited);

    sim_cntx = srv_bootup_get_sim_cntx(sim);

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_SIM_IS_INSERTED, sim, sim_cntx->is_inserted);
    
    return (sim_cntx->is_inserted);
}


#if (MMI_MAX_SIM_NUM == 1)
/*****************************************************************************
 * FUNCTION
 *  srv_bootup_active_l4
 * DESCRIPTION
 *  Send CFUN_STATE_REQ to specified module.
 * PARAMETERS
 *  l4_mod      [IN] MOD_L4C or MOD_L4C_2
 *  enable_rf   [IN] Enable RF
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_activate_l4(U16 l4_mod, MMI_BOOL enable_rf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));

    cfun_state_req->cfun_state = (enable_rf ? 1 : 4);
    mmi_frm_send_ilm(
        l4_mod,
        MSG_ID_MMI_NW_CFUN_STATE_REQ,
        (oslParaType*)cfun_state_req,
        NULL);
}
#endif /* (MMI_MAX_SIM_NUM == 1) */


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_efun_state_rsp_hdlr
 * DESCRIPTION
 *  The handler of EFUN_STATE_RSP.
 *  This function only sets the flag of EFUN_STATE_RSP received.
 * PARAMETERS
 *  sim     [IN] Which protocol
 *  msg     [IN] Unused
 * RETURNS
 *  Always MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_bootup_protocol_efun_state_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_protocol_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_srv_bootup_protocol_cntx;

    cntx->control.cfun_rsp = MMI_SIM_ALL;

    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_NW_EFUN_STATE_RSP, (PsIntFuncPtr)srv_bootup_protocol_efun_state_rsp_hdlr); // Gemini+
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_activate_l4_ext
 * DESCRIPTION
 *  Send EFUN_STATE_REQ to specified module.
 * PARAMETERS
 *  user_mode    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_activate_l4_ext(srv_bootup_sim_bit_set user_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_efun_state_req_struct *efun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    efun_state_req = OslConstructDataPtr(sizeof(mmi_nw_efun_state_req_struct));

    efun_state_req->efun_state = user_mode;
    mmi_frm_send_ilm(
        MOD_L4C,
        MSG_ID_MMI_NW_EFUN_STATE_REQ,
        (oslParaType*)efun_state_req,
        NULL);
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_is_activated
 * DESCRIPTION
 *  The protocol layer is activated.
 *  That is, CFUN_STATE_REQ was sent. If not, we should ignore
 *  SMU_PASSWORD_REQUIRED_IND or SMU_FAIL_IND from the layer.
 *
 *  [MAUI_01782781] SMU_FAIL_IND arrives before animation.
 *  SMU_FAIL_IND may be received right after SMU_RESET_REQ, before the 
 *  CFUN_STATE_REQ. We should ignore the SMU_FAIL_IND. After mode is decided
 *  and CFUN_STATE_REQ is sent, another SMU_FAIL_IND will be received.
 *  This way may result less rick than modifying PowerOnNormalMode() or other
 *  place; let SMU_FAIL_IND will be found and processed once as previous.
 * PARAMETERS
 *  sim     [IN] Protocol layer
 * RETURNS
 *  CFUN_STATE_REQ of the protocol layer was sent.
 *****************************************************************************/
MMI_BOOL srv_bootup_protocol_is_activated(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)((g_srv_bootup_protocol_cntx.control.cfun_sent & sim) != 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_get_query_setting
 * DESCRIPTION
 *  Get query setting for dual SIM project.
 * PARAMETERS
 *  void
 * RETURNS
 *  Query setting
 *****************************************************************************/
srv_bootup_protocol_query_enum srv_bootup_protocol_get_query_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_bootup_protocol_cntx.query_setting == SRV_BOOTUP_PROTOCOL_QUERY_INVALID)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        switch (srv_mode_switch_get_switch_type())
        {
            case SRV_MODE_SWITCH_STATIC_MODE:
                g_srv_bootup_protocol_cntx.query_setting = SRV_BOOTUP_PROTOCOL_QUERY_APPLY_DEFAULT;
                break;

            case SRV_MODE_SWITCH_DYNAMIC_MODE:
                g_srv_bootup_protocol_cntx.query_setting = SRV_BOOTUP_PROTOCOL_QUERY_ASK_USER;
                break;

            default:
                g_srv_bootup_protocol_cntx.query_setting = SRV_BOOTUP_PROTOCOL_QUERY_ASK_USER;
                break;
        }
    
#else /* Single SIM */

    #ifdef __FLIGHT_MODE_SUPPORT__
        if (srv_mode_switch_is_query_mode_enabled())
        {
            g_srv_bootup_protocol_cntx.query_setting = SRV_BOOTUP_PROTOCOL_QUERY_ASK_USER;
        }
        else
        {
            g_srv_bootup_protocol_cntx.query_setting = SRV_BOOTUP_PROTOCOL_QUERY_APPLY_DEFAULT;
        }
    #else /* __FLIGHT_MODE_SUPPORT__ */
        g_srv_bootup_protocol_cntx.query_setting = SRV_BOOTUP_PROTOCOL_QUERY_APPLY_DEFAULT;
    #endif /* __FLIGHT_MODE_SUPPORT__ */

#endif
    }

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_QUERY_SETTING, g_srv_bootup_protocol_cntx.query_setting);

    return g_srv_bootup_protocol_cntx.query_setting;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_write_mode_selection_to_system
 * DESCRIPTION
 *  Write mode selection to system
 * PARAMETERS
 *  mode    [IN] Bootup ptococol mode.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_write_mode_selection_to_system(
                srv_bootup_protocol_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum setting_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_mode = SRV_MODE_SWITCH_ALL_OFF;
    
    switch (mode)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        default:
            MMI_ASSERT(mode <= SRV_BOOTUP_PROTOCOL_MODE_ALL_SIM);
            setting_mode = (srv_mode_switch_type_enum)mode; /* Gemini+: bit operation for mode setting so it has to be the same in bootup module and mode switch module */
            break;

#else /* (MMI_MAX_SIM_NUM >= 2) */

#ifdef __FLIGHT_MODE_SUPPORT__
        case SRV_BOOTUP_PROTOCOL_MODE_FLIGHT_MODE:
            setting_mode = SRV_MODE_SWITCH_FLIGHT_MODE;
            break;
#endif /* __FLIGHT_MODE_SUPPORT__ */

        case SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE:
            setting_mode = SRV_MODE_SWITCH_NORMAL_MODE;
            break;

        default:
            MMI_ASSERT(MMI_FALSE);
            break;

#endif /* (MMI_MAX_SIM_NUM >= 2) */
    }

	srv_mode_switch_set_current_mode(setting_mode);
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_get_to_be_enabled_sim_set
 * DESCRIPTION
 *  This function returns the control flags of the contract to L4C/L4C_2
 *  by bootup mode.
 * PARAMETERS
 *  mode    [IN] Bootup mode.
 * RETURNS
 *  Control flags which controls the modes of L4C & L4C_2.
 *****************************************************************************/
static srv_bootup_sim_bit_set srv_bootup_protocol_get_to_be_enabled_sim_set(
                                srv_bootup_protocol_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_bit_set to_be_enabled;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    to_be_enabled = 0;

#if (MMI_MAX_SIM_NUM == 2)
    if (mode == SRV_BOOTUP_PROTOCOL_MODE_DUAL_SIM)
    {
        /*
         * Refer to the mode table in Bootup HLD
         */
        if (srv_bootup_sim_is_inserted(MMI_SIM1))
        {
            to_be_enabled |= MMI_SIM1;
        }
        if (srv_bootup_sim_is_inserted(MMI_SIM2))
        {
            to_be_enabled |= MMI_SIM2;
        }
        if (to_be_enabled == 0)
        {
            /* To enable emergency call through SIM1 */
            to_be_enabled = MMI_SIM1;
        }
    }
    else
#endif /* (MMI_MAX_SIM_NUM == 2) */
    {
        to_be_enabled = mode;
    }

    return to_be_enabled;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_dual_sim_start_bootup_by_mode
 * DESCRIPTION
 *  Start bootup procedure by the mode. It will start to send request to L4C
 *  and L4C_2.
 * PARAMETERS
 *  Mode    [IN] Bootup SIM mode.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_protocol_boot_multiple_sims(srv_bootup_protocol_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_bit_set to_be_enabled;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    to_be_enabled = srv_bootup_protocol_get_to_be_enabled_sim_set(mode);
    g_srv_bootup_protocol_cntx.control.to_be_enabled = to_be_enabled;

    srv_bootup_activate_l4_ext(to_be_enabled);
    g_srv_bootup_protocol_cntx.control.cfun_sent = MMI_SIM_ALL;

    /*
     * waiting flag will be cleaned once the SMU_PASSWORD_REQUIRED_IND or
     * SMU_FAIL_IND arrived. If all waiting flags are cleaned, the callback
     * will be called to notify completion of L4C power-on.
     */
    g_srv_bootup_protocol_cntx.control.waiting = MMI_SIM_ALL;

    g_srv_bootup_protocol_cntx.control.cfun_rsp = 0;

#if (MMI_MAX_SIM_NUM == 1)
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_CFUN_STATE_RSP, (PsIntFuncPtr)srv_bootup_protocol_cfun_state_rsp_hdlr, MMI_FALSE); // Gemini+
#else
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_EFUN_STATE_RSP, (PsIntFuncPtr)srv_bootup_protocol_efun_state_rsp_hdlr, MMI_FALSE); // Gemini+
#endif
}

#endif /* (MMI_MAX_SIM_NUM >= 2) */


#if (MMI_MAX_SIM_NUM == 1)
/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_boot_single_sim
 * DESCRIPTION
 *  Bootup protocol on single SIM project.
 * PARAMETERS
 *  mode    [IN] Protocol mode
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_protocol_boot_single_sim(srv_bootup_protocol_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FLIGHT_MODE_SUPPORT__
    if (mode == SRV_BOOTUP_PROTOCOL_MODE_FLIGHT_MODE)
    {
        g_srv_bootup_protocol_cntx.control.to_be_enabled = 0;
        srv_bootup_activate_l4(MOD_L4C, MMI_FALSE);
    }
    else /* SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE */
#endif
    {
        g_srv_bootup_protocol_cntx.control.to_be_enabled = MMI_SIM1;
        srv_bootup_activate_l4(MOD_L4C, MMI_TRUE);
    }

    /*
     * waiting flag will be cleaned once the SMU_PASSWORD_REQUIRED_IND or
     * SMU_FAIL_IND arrived. If it is cleaned, the callback will be called
     * to notify the completion of L4C power-on.
     */
    g_srv_bootup_protocol_cntx.control.waiting = MMI_SIM1;
    g_srv_bootup_protocol_cntx.control.cfun_rsp = 0;
    g_srv_bootup_protocol_cntx.control.cfun_sent = MMI_SIM1;

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_CFUN_STATE_RSP, (PsIntFuncPtr)srv_bootup_protocol_cfun_state_rsp_hdlr, MMI_FALSE);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_l4_response_hdlr
 * DESCRIPTION
 *  Handler for the ready notification from L4C or L4C_2.
 *  The ready notification is via SMU_PASSWORD_REQUIRED_IND or 
 *  SMU_FAIL_IND. This handler is used to listen to them.
 * PARAMETERS
 *  sim     [IN] Which protocol
 *  msg     [IN] Unused. The content may be smu_password_required_ind or
 *               smu_fail_ind, don't assume its type.
 * RETURNS
 *  Always MMI_FALSE; means continue message routing.
 *****************************************************************************/
static MMI_BOOL srv_bootup_protocol_l4_response_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);

    #ifdef __INVALID_SIM_RECOVERY__
    if(srv_sim_ctrl_invalid_sim_recovery_get_status(sim) == MMI_TRUE)
    {
        return MMI_FALSE;
    }
    #endif

    if ((g_srv_bootup_protocol_cntx.control.waiting & sim) == 0)
    {
        /* Already arrived before or we are not waiting for it. */
        return MMI_FALSE;
    }

    /* The protocol layer we are waiting for arrived, clear the corresponding bit */
    g_srv_bootup_protocol_cntx.control.waiting &= ~sim;

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_PROTOCOL_L4_RESPONSE,
        sim, g_srv_bootup_protocol_cntx.control.waiting);

    if (g_srv_bootup_protocol_cntx.control.waiting == 0 && /* all arrived */
        g_srv_bootup_protocol_cntx.completed_callback != NULL)
    {
        /* Notify client protocol layers are ready */
        g_srv_bootup_protocol_cntx.completed_callback(
            g_srv_bootup_protocol_cntx.user_data);
    }

    return MMI_FALSE;
}


#if (MMI_MAX_SIM_NUM == 1)
/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_cfun_state_rsp_hdlr
 * DESCRIPTION
 *  The handler of CFUN_STATE_RSP.
 *  This function only sets the flag of CFUN_STATE_RSP received.
 * PARAMETERS
 *  sim     [IN] Which protocol
 *  msg     [IN] Unused
 * RETURNS
 *  Always MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_bootup_protocol_cfun_state_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_bootup_protocol_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim(src_mod);
    cntx = &g_srv_bootup_protocol_cntx;

    if (cntx->control.cfun_rsp & sim)
    {
        /* We already received the CFUN_STATE_RSP from the protocol layer */
        return MMI_FALSE;
    }

    cntx->control.cfun_rsp |= sim;

    if (cntx->control.cfun_sent != 0 &&     /* CFUN_STATE_REQ has been sent */
        cntx->control.cfun_rsp == cntx->control.cfun_sent) /* All CFUN_STATE_RSP arrived */
    {
        mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_NW_CFUN_STATE_RSP, (PsIntFuncPtr)srv_bootup_protocol_cfun_state_rsp_hdlr);
    }

    return MMI_FALSE;
}
#endif /* (MMI_MAX_SIM_NUM == 1) */ 


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_protocol_is_ready
 * DESCRIPTION
 *  To query whether all CFUN_STATE_RSPs are received.
 * PARAMETERS
 *  void
 * RETURNS
 *  All CFUN_STATE_RSPs are received.
 *****************************************************************************/
MMI_BOOL srv_bootup_protocol_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_protocol_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_srv_bootup_protocol_cntx;
    
    return (MMI_BOOL)(cntx->control.cfun_sent != 0 &&     /* CFUN_STATE_REQ has been sent */
        cntx->control.waiting == 0 &&           /* L4C responded completely */
        cntx->control.cfun_rsp == cntx->control.cfun_sent); /* All CFUN_STATE_RSP arrived */
}


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
void srv_bootup_boot_protocol(
        srv_bootup_protocol_mode_enum mode,
        srv_bootup_work_completed_callback completed_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We can not boot protocol twice */
    MMI_ASSERT(g_srv_bootup_protocol_cntx.control.cfun_sent == 0);

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_BOOT_PROTOCOL, mode);

#if !defined(__FLIGHT_MODE_SUPPORT__) && (MMI_MAX_SIM_NUM == 1)
    /* Normal mode only */
    mode = SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE;
#endif
    
    g_srv_bootup_protocol_cntx.completed_callback = completed_callback;
    g_srv_bootup_protocol_cntx.user_data = user_data;

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_PASSWORD_REQUIRED_IND, (PsIntFuncPtr)srv_bootup_protocol_l4_response_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_FAIL_IND, (PsIntFuncPtr)srv_bootup_protocol_l4_response_hdlr, MMI_TRUE);

#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_mode_switch_is_network_service_available()) // if not power on with flight mode directly, then update the user setting to nvram
#else
    if (srv_bootup_protocol_get_query_setting() == SRV_BOOTUP_PROTOCOL_QUERY_ASK_USER) // for single sim project, update user setting to memory
#endif
    {
        /* Inform mode switching user's selection */
        srv_bootup_write_mode_selection_to_system(mode);
    }

#if (MMI_MAX_SIM_NUM >= 2)
    srv_bootup_protocol_boot_multiple_sims(mode);
#else
    srv_bootup_protocol_boot_single_sim(mode);
#endif

    srv_bootup_sec_init_for_protocol();
}

