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
 *  NwInfoSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Service of network infomation.
 *  This module provides network service availability, protocol, signal strength
 *  and information from protocol.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "NwInfoSrv.h"
#include "GSM7BitDefaultAlphabet.h"  /* CovertStringForPlatform */
#include "ModeSwitchSrvGprot.h"
#include "NetworkSetupGProt.h"       /* MMI_BAND_900 */
#include "NwInfoSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "UtilitySrvGprot.h"
#include "MMI_features.h"
#include "string.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "ps_public_enum.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_msg_struct.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_utility_gprot.h"
#if defined(__TCPIP__) && defined(__MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__)
#include "CnmgrSrvGprot.h"
#endif // #if defined(__TCPIP__) && defined(__MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__)
/****************************************************************************
 * Global variables
 ****************************************************************************/

static srv_nw_info_cntx_struct g_srv_nw_info_cntx[SRV_SIM_CTRL_MAX_SIM_NUM];


/****************************************************************************
 * Local functions
 ****************************************************************************/
#if 0
/* under construction !*/
#endif
#ifdef __MMI_GPRS_FEATURES__
static MMI_BOOL srv_nw_info_gprs_status_update_ind_hdlr(void *msg, S32 src_mod);
#endif

#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
static MMI_BOOL srv_nw_info_smu_cipher_ind_hdlr(void *msg, S32 src_mod);
#endif

#if defined(__INVALID_SIM_RECOVERY__) && defined(__MMI_EM_CTM_CTA_TDD__)
#include "mmi_rp_app_engineermode1_def.h"
static void srv_nw_info_get_conf_test_param_rsp_hdlr(void *msg);
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_init
 * DESCRIPTION
 *  Initialize network info service
 * PARAMETERS
 *  evt     [IN] srv_bootup_early_init_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_nw_info_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_nw_info_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        cntx = &(g_srv_nw_info_cntx[i]);

        cntx->service_availability = SRV_NW_INFO_SA_NO_SERVICE;
    #ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
        cntx->cipher_info.cs_status = SRV_NW_INFO_CIPHER_STATUS_INVALID;
        cntx->cipher_info.ps_status = SRV_NW_INFO_CIPHER_STATUS_INVALID;
    #endif
    }

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_ATTACH_IND, (PsIntFuncPtr)srv_nw_info_nw_attach_ind_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_RX_LEVEL_IND, (PsIntFuncPtr)srv_nw_info_rx_level_ind_hdlr, MMI_TRUE);
#ifdef __MMI_GPRS_FEATURES__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_PS_GPRS_STATUS_UPDATE_IND, (PsIntFuncPtr)srv_nw_info_gprs_status_update_ind_hdlr, MMI_TRUE);
#endif
#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_CIPHER_IND, (PsIntFuncPtr)srv_nw_info_smu_cipher_ind_hdlr, MMI_TRUE);
#endif

#if defined(__INVALID_SIM_RECOVERY__) && defined(__MMI_EM_CTM_CTA_TDD__)
    {
        mmi_em_set_conform_test_param_req_struct  *msg_set_req;
        S8 value;
        S16 error;
        msg_set_req = OslConstructDataPtr(sizeof(mmi_em_set_conform_test_param_req_struct));
        ReadValue(NVRAM_EM_IVSR, &value, DS_BYTE, &error);

        mmi_frm_send_ilm(
            MOD_L4C,
            MSG_ID_MMI_EM_GET_CONFORM_TEST_PARAM_REQ,
            NULL,
            NULL);
        srv_nw_info_enable_ivsr((MMI_BOOL)value);
        mmi_frm_set_protocol_event_handler(
            MSG_ID_MMI_EM_GET_CONFORM_TEST_PARAM_RSP,
            (PsIntFuncPtr)srv_nw_info_get_conf_test_param_rsp_hdlr,
            MMI_FALSE);
    }
#endif /* __INVALID_SIM_RECOVERY__ && __MMI_EM_CTM_CTA_TDD__ */
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_cntx
 * DESCRIPTION
 *  Get the context of the specified protocol layer of SIM.
 * PARAMETERS
 *  sim     [IN] Which protocol layer
 * RETURNS
 *  The context.
 *****************************************************************************/
srv_nw_info_cntx_struct *srv_nw_info_get_cntx(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (&g_srv_nw_info_cntx[mmi_frm_sim_to_index(sim)]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_map_cell_capability
 * DESCRIPTION
 *  Map L4 cell capability bit set to MMI bit set.
 * PARAMETERS
 *  protocol        [IN] Protocol system
 *  l4_bit_set      [IN] Bit set from L4
 * RETURN VALUES
 *  Capability bit set
 *****************************************************************************/
srv_nw_info_capability_bit_set srv_nw_info_map_cell_capability(
    mmi_network_enum protocol,
    U32 l4_bit_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_capability_bit_set capability = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (protocol == MMI_GSM)
    {
        if (l4_bit_set & L4C_GPRS_SUPPORT)
        {
            capability |= MMI_GPRS;
        }
        if (l4_bit_set & L4C_EDGE_SUPPORT)
        {
            capability |= MMI_EDGE;
        }
    }
    else if (protocol == MMI_WCDMA)
    {
        if (l4_bit_set & L4C_HSDPA_SUPPORT)
        {
            capability |= MMI_HSDPA;
        }
        if (l4_bit_set & L4C_HSUPA_SUPPORT)
        {
            capability |= MMI_HSUPA;
        }
    }

    return capability;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_map_cell_capability
 * DESCRIPTION
 *  Map L4 channel capability enum to MMI bit set.
 * PARAMETERS
 *  protocol        [IN] Protocol system
 *  l4_bit_set      [IN] Bit set from L4
 * RETURN VALUES
 *  Capability bit set
 *****************************************************************************/
static srv_nw_info_capability_bit_set srv_nw_info_map_channel_capability(
    mmi_network_enum protocol,
    l4c_data_bearer_capablility_enum l4_ch_cap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_capability_bit_set capability = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (protocol == MMI_GSM)
    {
        if (l4_ch_cap == L4C_GPRS_CAPABILITY)
        {
            capability = MMI_GPRS;
        }
        else if (l4_ch_cap == L4C_EDGE_CAPABILITY)
        {
            capability = MMI_EDGE;
        }
    }
    else if (protocol == MMI_WCDMA)
    {
        if (l4_ch_cap == L4C_HSDPA_CAPABILITY)
        {
            capability = MMI_HSDPA;
        }
        else if (l4_ch_cap == L4C_HSUPA_CAPABILITY)
        {
            capability = MMI_HSUPA;
        }
        else if (l4_ch_cap == L4C_HSDPA_HSUPA_CAPABILITY)
        {
            capability = (MMI_HSDPA | MMI_HSUPA);
        }
    }

    return capability;
}

static void srv_nw_info_post_dn_status_changed(mmi_sim_enum sim, srv_nw_info_sim_dn_status_bit_set old_status, srv_nw_info_sim_dn_status_bit_set new_status)
{
	MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_DN_STATUS_CHANGED,
		sim, old_status, new_status);

	/* Emit data network status changed event */
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif /*As there is no receiver, so will not be implement new*/
}
/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_update_sim_dn_status
 * DESCRIPTION
 *  Update the status of data network by the l4c_gprs_status_enum from L4C.
 *  If changed, it will emit SIM_DN_STATUS_CHANGED event.
 * PARAMETERS
 *  cntx            [IN] Context
 *  sim             [IN] Which protocol layer
 *  gprs_status     [IN] l4c_gprs_status_enum from L4C
 * RETURN VALUES
 *  MMI_TRUE    : Data network status changed
 *  MMI_FALSE   : The same as before
 *****************************************************************************/
MMI_BOOL srv_nw_info_update_sim_dn_status(
            srv_nw_info_cntx_struct *cntx,
            mmi_sim_enum sim,
            l4c_gprs_status_enum gprs_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_sim_dn_status_bit_set old_dn_status = cntx->dn_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gprs_status)
    { 
        case L4C_GPRS_COVERAGE:
            cntx->dn_status |= SRV_NW_INFO_SIM_DN_STATUS_COVERAGE;
            break;

        case L4C_NONE_GPRS:
            cntx->dn_status &=
                ~(SRV_NW_INFO_SIM_DN_STATUS_COVERAGE | SRV_NW_INFO_SIM_DN_STATUS_ATTACHED);
            break;

        case L4C_INVALID_SIM:
            cntx->dn_status &=
                ~(SRV_NW_INFO_SIM_DN_STATUS_ATTACHED | SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED);
            break;

        case L4C_GPRS_ATTACHED:
            cntx->dn_status |=
                (SRV_NW_INFO_SIM_DN_STATUS_COVERAGE | SRV_NW_INFO_SIM_DN_STATUS_ATTACHED);
            break;
            
        case L4C_GPRS_DETACHED:
            cntx->dn_status &= ~(SRV_NW_INFO_SIM_DN_STATUS_ATTACHED);
            break;
            
        case L4C_PDP_ACTIVED:
            cntx->dn_status |= SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED;
            break;
            
        case L4C_PDP_DEACTIVED:
            cntx->dn_status &= ~(SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED);
            break;

        default:
            /* Ignore */
            break;
    }

    if (old_dn_status != cntx->dn_status)
    {
		srv_nw_info_post_dn_status_changed(sim, old_dn_status, cntx->dn_status);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_gprs_status_update_ind_hdlr
 * DESCRIPTION
 *  Handler of PS_GPRS_STATUS_UPDATE_IND.
 *  Update the capability and the status of data network.
 * PARAMETERS
 *  sim     [IN] From which layer
 *  msg     [IN] mmi_ps_gprs_status_update_ind_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_nw_info_gprs_status_update_ind_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_nw_info_cntx_struct *cntx;
    mmi_ps_gprs_status_update_ind_struct *update_ind;
    srv_nw_info_status_changed_evt_struct changed_evt;
    srv_nw_info_capability_bit_set old_cell_cap;
    srv_nw_info_capability_bit_set old_channel_cap;
    MMI_BOOL dn_status_changed;
    MMI_BOOL capability_changed;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    cntx = srv_nw_info_get_cntx(sim);
    update_ind = (mmi_ps_gprs_status_update_ind_struct*)msg;

    dn_status_changed = srv_nw_info_update_sim_dn_status(cntx, sim, (l4c_gprs_status_enum)update_ind->status);
    capability_changed = MMI_FALSE;
    
    old_cell_cap = cntx->cell_capability;
    old_channel_cap = cntx->channel_capability;
    cntx->cell_capability = srv_nw_info_map_cell_capability(cntx->protocol, update_ind->data_speed_support);
    if (cntx->dn_status & SRV_NW_INFO_SIM_DN_STATUS_ATTACHED)
    {
        if (cntx->protocol == MMI_GSM)
        {
            cntx->channel_capability = cntx->cell_capability;
        }
        else
        {
            cntx->channel_capability = srv_nw_info_map_channel_capability(
                cntx->protocol,
                (l4c_data_bearer_capablility_enum)update_ind->data_bearer_capability);
        }
    }
    else
    {
        cntx->channel_capability = 0;
    }

    if (old_cell_cap != cntx->cell_capability ||
        old_channel_cap != cntx->channel_capability)
    {
        srv_nw_info_protocol_capability_changed_evt_struct protocol_evt;
    
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_PROT_CAP_CHANGED,
            sim, cntx->protocol, old_cell_cap, old_channel_cap,
            cntx->protocol, cntx->cell_capability, cntx->channel_capability);
    
        MMI_FRM_INIT_EVENT(&protocol_evt, EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED);
        protocol_evt.sim = sim;
        protocol_evt.old_protocol = cntx->protocol;
        protocol_evt.old_cell_cap = old_cell_cap;
        protocol_evt.old_channel_cap = old_channel_cap;
        protocol_evt.new_protocol = cntx->protocol;
        protocol_evt.new_cell_cap = cntx->cell_capability;
        protocol_evt.new_channel_cap = cntx->channel_capability;
        MMI_FRM_CB_EMIT_POST_EVENT(&protocol_evt);

        capability_changed = MMI_TRUE;
    }

    MMI_FRM_INIT_EVENT(&changed_evt, EVT_ID_SRV_NW_INFO_STATUS_CHANGED);
    changed_evt.sim = sim;
    changed_evt.service_availability_changed = MMI_FALSE;
    changed_evt.location_changed = MMI_FALSE;
    changed_evt.dn_status_changed = dn_status_changed;
    changed_evt.protocol_changed = MMI_FALSE;
    changed_evt.capability_changed = capability_changed;

    if (changed_evt.dn_status_changed ||
        changed_evt.capability_changed)
    {
        MMI_FRM_CB_EMIT_POST_EVENT(&changed_evt);
    }

    return MMI_FALSE;
}
#endif /* __MMI_GPRS_FEATURES__ */


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_is_enabled
 * DESCRIPTION
 *  Query whether the network of the SIM is enabled or not.
 * PARAMETERS
 *  sim     [IN] Which protocol layer of SIM
 * RETURNS
 *  MMI_TRUE if the network is enabled by settings
 *****************************************************************************/
MMI_BOOL srv_nw_info_is_enabled(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum mode = srv_mode_switch_get_current_mode();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* If it is flight mode, return false */
    if (mode == SRV_MODE_SWITCH_ALL_OFF)
    {
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_IS_ENABLED, sim, 0, 10);
        return MMI_FALSE;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    /* If the SIM is not turned on, return false */
    if ((sim & mode) == 0)
    {
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_IS_ENABLED, sim, 0, 30);
        return MMI_FALSE;
    }
#endif

    MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_IS_ENABLED, sim, 1, 99);

    return MMI_TRUE;
}

void srv_nw_info_post_roaming_changed(mmi_sim_enum sim, MMI_BOOL is_roaming_now)
{
	srv_nw_info_roaming_status_changed_evt_struct roaming_evt;

	MMI_FRM_INIT_EVENT(&roaming_evt, EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED);
	roaming_evt.sim = sim;
	roaming_evt.is_roaming_now = is_roaming_now;
	MMI_FRM_CB_EMIT_POST_EVENT(&roaming_evt);
}
/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_set_enabled
 * DESCRIPTION
 *  Notify the enabled property to change status and emit events.
 * PARAMETERS
 *  sim     [IN] Which protocol layer of SIM
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_info_set_enabled(mmi_sim_enum sim, MMI_BOOL enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx;
    srv_nw_info_service_availability_enum old_service_availability;
    srv_nw_info_sim_dn_status_bit_set old_dn_status;
    mmi_network_enum old_protocol;
    srv_nw_info_capability_bit_set old_cell_cap;
    srv_nw_info_capability_bit_set old_channel_cap;
    MMI_BOOL old_is_roaming;
    srv_nw_info_status_changed_evt_struct changed_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enabled)
    {
        /* Will update by new indications */
        return;
    }
    
    cntx = srv_nw_info_get_cntx(sim);

    MMI_FRM_INIT_EVENT(&changed_evt, EVT_ID_SRV_NW_INFO_STATUS_CHANGED);
    changed_evt.sim = sim;

    /* Service availability */
    old_service_availability = cntx->service_availability;
    cntx->service_availability = SRV_NW_INFO_SA_NO_SERVICE;
    if (old_service_availability != cntx->service_availability)
    {
        srv_nw_info_service_availability_changed_evt_struct avai_evt;

        MMI_FRM_INIT_EVENT(&avai_evt, EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED);
        avai_evt.sim = sim;
        avai_evt.old_status = old_service_availability;
        avai_evt.new_status = cntx->service_availability;
        MMI_FRM_CB_EMIT_POST_EVENT(&avai_evt);

        changed_evt.service_availability_changed = MMI_TRUE;
    }
    else
    {
        changed_evt.service_availability_changed = MMI_FALSE;
    }
    
    /* Protocol / capability */
    old_protocol = cntx->protocol;
    old_cell_cap = cntx->cell_capability;
    old_channel_cap = cntx->channel_capability;
    cntx->protocol = MMI_NETWORK_NONE;
    cntx->cell_capability = MMI_NETWORK_CAPABILITY_NONE;
    cntx->channel_capability = MMI_NETWORK_CAPABILITY_NONE;
    if (old_protocol != cntx->protocol ||
        old_cell_cap != cntx->cell_capability ||
        old_channel_cap != cntx->channel_capability)
    {
        srv_nw_info_protocol_capability_changed_evt_struct prot_capa_evt;
        
        MMI_FRM_INIT_EVENT(&prot_capa_evt, EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED);
        prot_capa_evt.sim = sim;
        prot_capa_evt.old_protocol = old_protocol;
        prot_capa_evt.old_cell_cap = old_cell_cap;
        prot_capa_evt.old_channel_cap = old_channel_cap;
        prot_capa_evt.new_protocol = cntx->protocol;
        prot_capa_evt.new_cell_cap = cntx->cell_capability;
        prot_capa_evt.new_channel_cap = cntx->channel_capability;
        MMI_FRM_CB_EMIT_POST_EVENT(&prot_capa_evt);

        changed_evt.protocol_changed = (old_protocol != cntx->protocol)? MMI_TRUE : MMI_FALSE;
        changed_evt.capability_changed =
            (old_cell_cap != cntx->cell_capability || old_channel_cap != cntx->channel_capability)? MMI_TRUE : MMI_FALSE;
    }
    else
    {
        changed_evt.protocol_changed = MMI_FALSE;
        changed_evt.capability_changed = MMI_FALSE;
    }

    /* Data network status */
    old_dn_status = cntx->dn_status;
    cntx->dn_status = SRV_NW_INFO_SIM_DN_STATUS_NONE;
    if (old_dn_status != cntx->dn_status)
    {
		srv_nw_info_post_dn_status_changed(sim, old_dn_status, cntx->dn_status);
        changed_evt.dn_status_changed = MMI_TRUE;
    }
    else
    {
        changed_evt.dn_status_changed = MMI_FALSE;
    }

    /* Roaming */
    old_is_roaming = cntx->is_roaming;
    cntx->is_roaming = MMI_FALSE;
    if (old_is_roaming != cntx->is_roaming)
    {
        srv_nw_info_post_roaming_changed(sim, cntx->is_roaming);
    }

    changed_evt.location_changed = MMI_FALSE;

    /* Status changed event */
    if (changed_evt.service_availability_changed ||
        changed_evt.protocol_changed ||
        changed_evt.capability_changed ||
        changed_evt.dn_status_changed)
    {
        MMI_FRM_CB_EMIT_POST_EVENT(&changed_evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_notify_mode_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_nw_info_notify_mode_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_NOTIFY_MODE_CHANGED);
    
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        srv_nw_info_set_enabled(sim, srv_nw_info_is_enabled(sim));
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
srv_nw_info_sim_dn_status_bit_set srv_nw_info_get_sim_dn_status(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (cntx->dn_status);
}


#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_convert_to_cipher_status
 * DESCRIPTION
 *  Convert native cipher status to service interface.
 * PARAMETERS
 *  native_value    [IN] Native value
 * RETURNS
 *  srv_nw_info_cipher_status_enum
 *****************************************************************************/
static srv_nw_info_cipher_status_enum srv_nw_info_convert_to_cipher_status(kal_uint8 native_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cipher_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = SRV_NW_INFO_CIPHER_STATUS_INVALID;
    
    switch (native_value)
    {
        case GMMREG_CIPHER_OFF:
            status = SRV_NW_INFO_CIPHER_STATUS_OFF;
            break;

        case GMMREG_CIPHER_ON:
            status = SRV_NW_INFO_CIPHER_STATUS_ON;
            break;

        case GMMREG_CIPHER_INVALID:
        default:
            status = SRV_NW_INFO_CIPHER_STATUS_INVALID;
            break;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_smu_cipher_ind_hdlr
 * DESCRIPTION
 *  Handler of SMU_CIPHER_IND.
 *  Update the cipher information of network.
 * PARAMETERS
 *  sim     [IN] From which layer
 *  msg     [IN] mmi_smu_cipher_ind_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_nw_info_smu_cipher_ind_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_nw_info_cntx_struct *cntx;
    mmi_smu_cipher_ind_struct *cipher_ind;
    srv_nw_info_cipher_info_struct old_cipher_status;
    srv_nw_info_cipher_status_changed_evt_struct cipher_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    cntx = srv_nw_info_get_cntx(sim);
    cipher_ind = (mmi_smu_cipher_ind_struct*)msg;

    old_cipher_status = cntx->cipher_info;

    cntx->cipher_info.is_supported_by_network =
        (cipher_ind->cipher_ind ? MMI_TRUE : MMI_FALSE);
        
    cntx->cipher_info.cs_connection_exists =
        (cipher_ind->is_gsm_conn_exist ? MMI_TRUE : MMI_FALSE);

    cntx->cipher_info.cs_status =
        srv_nw_info_convert_to_cipher_status(cipher_ind->gsm_cipher_cond);

    cntx->cipher_info.ps_status =
        srv_nw_info_convert_to_cipher_status(cipher_ind->gprs_cipher_cond);

    if (memcmp(&old_cipher_status, &(cntx->cipher_info), sizeof(srv_nw_info_cipher_info_struct)) != 0)
    {
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_CIPHER_CHANGED,
            sim, cntx->cipher_info.is_supported_by_network, cntx->cipher_info.cs_connection_exists,
            cntx->cipher_info.cs_status, cntx->cipher_info.ps_status);
    
        MMI_FRM_INIT_EVENT(&cipher_evt, EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED);
        cipher_evt.sim = sim;
        cipher_evt.status = cntx->cipher_info;
        MMI_FRM_CB_EMIT_POST_EVENT(&cipher_evt);
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_info_get_cipher_info(mmi_sim_enum sim, srv_nw_info_cipher_info_struct *out_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = srv_nw_info_get_cntx(sim);
    
    MMI_ASSERT(out_info != NULL);
    *out_info = cntx->cipher_info;

    return MMI_TRUE;
}

#endif /* __SRV_NW_INFO_CIPHER_SUPPORT__ */


#ifdef __HOMEZONE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_get_gsm7bit_upper_bound
 * DESCRIPTION
 *  Get the valid data length(index bound) of a GSM 7-bit string.
 * PARAMETERS
 *  gsm7bit_str     [IN] GSM 7-bit data array
 *  max_upper_bound [IN] Maximum data upper index
 * RETURNS
 *  Upper index bound
 *****************************************************************************/
static S32 srv_nw_info_get_gsm7bit_upper_bound(const U8 *gsm7bit_str, S32 max_upper_bound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < max_upper_bound; i++)
    {
        if (gsm7bit_str[i] == 0xff)
        {
            return i;
        }
    }

    return max_upper_bound;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_hz_tag_ind_hdlr
 * DESCRIPTION
 *  Handler of HZ_TAG_IND.
 *  Update the homezone information of network.
 * PARAMETERS
 *  sim     [IN] From which layer
 *  msg     [IN] mmi_hz_tag_ind_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_nw_info_hz_tag_ind_hdlr(mmi_sim_enum sim, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx;
    mmi_hz_tag_ind_struct *hz_tag_ind;
    srv_nw_info_homezone_info_struct old_homezone_info;
    srv_nw_info_homezone_status_changed_evt_struct homezone_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = srv_nw_info_get_cntx(sim);
    hz_tag_ind = (mmi_hz_tag_ind_struct*)msg;

    memcpy(&old_homezone_info, &(cntx->homezone_info), sizeof(srv_nw_info_homezone_info_struct));

    cntx->homezone_info.is_in_homezone =
        (hz_tag_ind->is_hz ? MMI_TRUE : MMI_FALSE);

    if (hz_tag_ind->is_hz && hz_tag_ind->action)
    {
        U8 *converted_ucs2_string;
        U16 out_len;
    
        converted_ucs2_string =
            CovertStringForPlatform(
                hz_tag_ind->tag,
                (U16)srv_nw_info_get_gsm7bit_upper_bound(hz_tag_ind->tag, sizeof(hz_tag_ind->tag)),
                MMI_DEFAULT_DCS,
                &out_len);
    
        mmi_wcsncpy(
            cntx->homezone_info.tag,
            converted_ucs2_string,
            SRV_NW_INFO_MAX_HOMEZONE_TAG_LEN);
        
        OslMfree(converted_ucs2_string);
    }
    else
    {
        cntx->homezone_info.tag[0] = L'\0';
    }

    if (hz_tag_ind->action ||
        memcmp(&old_homezone_info, &(cntx->homezone_info), sizeof(srv_nw_info_homezone_info_struct)) != 0)
    {
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_HOMEZONE_CHANGED,
            sim, hz_tag_ind->action, cntx->homezone_info.is_in_homezone);
    
        MMI_FRM_INIT_EVENT(&homezone_evt, EVT_ID_SRV_NW_INFO_HOMEZONE_STATUS_CHANGED);
        homezone_evt.sim = sim;
        homezone_evt.notify_user = hz_tag_ind->action ? MMI_TRUE : MMI_FALSE;
        memcpy(&(homezone_evt.info), &(cntx->homezone_info), sizeof(srv_nw_info_homezone_info_struct));
        MMI_FRM_CB_EMIT_POST_EVENT(&homezone_evt);
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_info_get_homezone_info(
            mmi_sim_enum sim,
            srv_nw_info_homezone_info_struct *out_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (out_info != NULL)
    {
        memcpy(out_info, &(cntx->homezone_info), sizeof(srv_nw_info_homezone_info_struct));
    }

    return (cntx->homezone_info.is_in_homezone);
}

#endif /* __HOMEZONE_SUPPORT__ */

#ifdef __INVALID_SIM_RECOVERY__
/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
void srv_nw_info_enable_ivsr(MMI_BOOL enable_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        g_srv_nw_info_cntx[i].ivsr_info.enable_ivsr = enable_flag;
    }
}


#ifdef __MMI_EM_CTM_CTA_TDD__
void srv_nw_info_get_conf_test_param_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_get_conform_test_param_rsp_struct *param =
        (mmi_em_get_conform_test_param_rsp_struct*)msg;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (param->conf_test_mode != PS_CONF_TEST_CTA &&
        param->conf_test_mode != PS_CONF_TEST_FTA &&
        param->conf_test_mode != PS_CONF_TEST_IOT)
    {
        for (i = 0; i < MMI_MAX_SIM_NUM; i++)
        {
            g_srv_nw_info_cntx[i].ivsr_info.is_in_test_mode = MMI_FALSE;
        }
    }
    else
    {
        for (i = 0; i < MMI_MAX_SIM_NUM; i++)
        {
            g_srv_nw_info_cntx[i].ivsr_info.is_in_test_mode = MMI_TRUE;
        }
    }

    // EM will reg this msg
    mmi_frm_clear_protocol_event_handler(
        MSG_ID_MMI_EM_GET_CONFORM_TEST_PARAM_RSP,
        srv_nw_info_get_conf_test_param_rsp_hdlr);
}
#endif /* __MMI_EM_CTM_CTA_TDD__ */
#endif /* __INVALID_SIM_RECOVERY__ */

#if defined(__TCPIP__) && defined(__MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__)
mmi_ret srv_nw_info_cnmgr_notify_nwinfo_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_nw_info_cntx_struct *cntx;
    srv_cnmgr_notify_nwinfo_evt_struct *nwinfo;
    srv_nw_info_status_changed_evt_struct changed_evt;
    srv_nw_info_sim_dn_status_bit_set old_dn_status;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nwinfo = (srv_cnmgr_notify_nwinfo_evt_struct*)evt;

    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        sim = mmi_frm_index_to_sim(i);
        cntx = srv_nw_info_get_cntx(sim);
        old_dn_status = cntx->dn_status;
        MMI_TRACE(
            SRV_NW_INFO_TRC_GROUP,
            TRC_SRV_NW_INFO_CNMGR_NOTIFY_NWINFO_HDLR,
            sim,
            old_dn_status,
            nwinfo->flag[i].uplink,
            nwinfo->flag[i].downlink);

        if (cntx->dn_status & SRV_NW_INFO_SIM_DN_STATUS_ATTACHED ||
            cntx->dn_status & SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED)
        {
            if (nwinfo->flag[i].uplink == MMI_TRUE)
            {
                cntx->dn_status |= SRV_NW_INFO_SIM_DN_STATUS_UPLINK;
            }
            else
            {
                cntx->dn_status &= ~(SRV_NW_INFO_SIM_DN_STATUS_UPLINK);
            }

            if (nwinfo->flag[i].downlink == MMI_TRUE)
            {
                cntx->dn_status |= SRV_NW_INFO_SIM_DN_STATUS_DOWNLINK;
            }
            else
            {
                cntx->dn_status &= ~(SRV_NW_INFO_SIM_DN_STATUS_DOWNLINK);
            }
        }
        else
        {
            cntx->dn_status &= ~(SRV_NW_INFO_SIM_DN_STATUS_UPLINK);
            cntx->dn_status &= ~(SRV_NW_INFO_SIM_DN_STATUS_DOWNLINK);
        }

        if (old_dn_status != cntx->dn_status)
        {
            MMI_FRM_INIT_EVENT(&changed_evt, EVT_ID_SRV_NW_INFO_STATUS_CHANGED);
            changed_evt.sim = sim;
            changed_evt.service_availability_changed = MMI_FALSE;
            changed_evt.location_changed = MMI_FALSE;
            changed_evt.dn_status_changed = MMI_TRUE;
            changed_evt.protocol_changed = MMI_FALSE;
            changed_evt.capability_changed = MMI_FALSE;
            MMI_FRM_CB_EMIT_POST_EVENT(&changed_evt);
        }
    }

    return MMI_RET_OK;
}
#endif // #if defined(__TCPIP__) && defined(__MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__)
