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
 *  NwInfoSrvAttach.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Handling of network-attach related info.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "NwInfoSrv.h"
#include "app_str.h"
#include "ps_public_enum.h"
#include "app_plmn.h"
#include "NetSetSrvGprot.h"         /* srv_netset_is_plmn_roaming */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_msg_struct.h"
#include "NwInfoSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "stack_config.h"
#include "MMI_features.h"
#include "SimCtrlSrvGprot.h"
#include "kal_public_api.h"
#include "mmi_frm_utility_gprot.h"
#ifdef __INVALID_SIM_RECOVERY__
extern void srv_sim_ctrl_invalid_sim_recovery_start(mmi_sim_enum sim);
#endif
/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_update_service_availability
 * DESCRIPTION
 *  Update service availability by NW_ATTACH_IND. If changed, it will emit
 *  SERVICE_AVAILABILITY_CHANGED event.
 * PARAMETERS
 *  cntx            [IN] Context
 *  sim             [IN] Which protocol layer
 *  nw_attach_ind   [IN] mmi_nw_attach_ind_struct*
 * RETURN VALUES
 *  MMI_TRUE    : Service availability changed
 *  MMI_FALSE   : The same as before
 *****************************************************************************/
static MMI_BOOL srv_nw_info_update_service_availability(
                    srv_nw_info_cntx_struct *cntx,
                    mmi_sim_enum sim,
                    const mmi_nw_attach_ind_struct *nw_attach_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_enum old_availability;
    srv_sim_ctrl_ua_cause_enum sim_ua_cause = srv_sim_ctrl_get_unavailable_cause(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_availability = cntx->service_availability;

    switch (nw_attach_ind->status)
    {
        case L4C_RAC_OK:
            cntx->service_availability = SRV_NW_INFO_SA_FULL_SERVICE;
            break;

        case L4C_RAC_SEARCHING:
            cntx->service_availability = SRV_NW_INFO_SA_SEARCHING;
            break;

        case L4C_RAC_NULL:
        case L4C_RAC_NO_CELL:
            cntx->service_availability = SRV_NW_INFO_SA_NO_SERVICE;
            break;

        case L4C_RAC_LIMITED_SERVICE:
        case L4C_RAC_ATTEMPT_TO_UPDATE:
            cntx->service_availability = SRV_NW_INFO_SA_LIMITED_SERVICE;
            break;

        case L4C_RAC_INVALID_SIM:
            cntx->service_availability = SRV_NW_INFO_SA_LIMITED_SERVICE;
            if (!cntx->sim_is_rejected
                && sim_ua_cause != SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED 
	#ifdef __SIM_RECOVERY_ENHANCEMENT__
			&& sim_ua_cause != SRV_SIM_CTRL_UA_CAUSE_RECOVERY
	#endif
                )
            {
                srv_nw_info_register_failed_evt_struct reg_failed_evt;
                
                cntx->sim_is_rejected = MMI_TRUE;
                
                MMI_FRM_INIT_EVENT(&reg_failed_evt, EVT_ID_SRV_NW_INFO_REGISTER_FAILED);
                reg_failed_evt.sim = sim;
                app_strlcpy(reg_failed_evt.nw_plmn, (CHAR*)(nw_attach_ind->plmn), sizeof(reg_failed_evt.nw_plmn));
                MMI_FRM_CB_EMIT_POST_EVENT(&reg_failed_evt);
            }
            break;

        default:
            /* Ignore */
            break;
    }

#ifdef __OP01_3G__
    // CMCC request UI not display nw unavailable in some temp status
    // Nw name and other modules need to check this flag
    if (srv_sim_ctrl_get_op(sim) == SRV_SIM_CTRL_OP_CMCC)
    {
        switch (nw_attach_ind->status)
        {
            case L4C_RAC_SEARCHING:
            {
                if (old_availability == SRV_NW_INFO_SA_FULL_SERVICE ||
                    cntx->display_fake_nw == MMI_TRUE)
                {
                    cntx->display_fake_nw = MMI_TRUE;
                }
                else
                {
                    cntx->display_fake_nw = MMI_FALSE;
                }
            }
            break;

            case L4C_RAC_ATTEMPT_TO_UPDATE:
            {
                cntx->display_fake_nw = MMI_TRUE;
            }
            break;

            default:
                cntx->display_fake_nw = MMI_FALSE;
                break;
        }
    }
#endif /* __OP01_3G__ */

    if (old_availability != cntx->service_availability ||
        !cntx->first_availability_emitted)
    {
        srv_nw_info_service_availability_changed_evt_struct changed_evt;
        
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_SERVICE_AVAI_CHANGED,
            sim, old_availability, cntx->service_availability);

        MMI_FRM_INIT_EVENT(&changed_evt, EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED);
        changed_evt.sim = sim;
        changed_evt.old_status = old_availability;
        changed_evt.new_status = cntx->service_availability;
        MMI_FRM_CB_EMIT_POST_EVENT(&changed_evt);

        cntx->first_availability_emitted = MMI_TRUE;
    
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_update_location_info
 * DESCRIPTION
 *  Update location information by NW_ATTACH_IND. If changed, it will emit
 *  LOCATION_CHANGED event.
 * PARAMETERS
 *  cntx            [IN] Context
 *  sim             [IN] Which protocol layer
 *  nw_attach_ind   [IN] mmi_nw_attach_ind_struct*
 * RETURN VALUES
 *  MMI_TRUE    : Location changed
 *  MMI_FALSE   : The same as before
 *****************************************************************************/
static MMI_BOOL srv_nw_info_update_location_info(
                    srv_nw_info_cntx_struct *cntx,
                    mmi_sim_enum sim,
                    const mmi_nw_attach_ind_struct *nw_attach_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_location_info_struct old_location;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nw_attach_ind->status)
    {
        case L4C_RAC_OK:
        case L4C_RAC_LIMITED_SERVICE:
        case L4C_RAC_ATTEMPT_TO_UPDATE:
        case L4C_RAC_INVALID_SIM:
            break;

        case L4C_RAC_NULL:
        case L4C_RAC_NO_CELL:
            /*
             * For NULL or NO_CELL, we don't emit location changed event.
             * If application querys, we answer previous location information.
             */
        default:
            return MMI_FALSE; /* Ignore */
    }

    memcpy(&old_location, &(cntx->location), sizeof(srv_nw_info_location_info_struct));
    app_strlcpy(cntx->location.plmn, (CHAR*)nw_attach_ind->plmn, sizeof(cntx->location.plmn));
    cntx->location.lac = ((nw_attach_ind->lac[0] << 8) | (nw_attach_ind->lac[1]));
    cntx->location.cell_id = nw_attach_ind->cell_id;

    if (memcmp(&old_location, &(cntx->location), sizeof(srv_nw_info_location_info_struct)) != 0)
    {
        srv_nw_info_location_changed_evt_struct location_evt;
		
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_LOCATION_CHANGED,
            sim, old_location.lac, old_location.cell_id, cntx->location.lac, cntx->location.cell_id, old_location.plmn, cntx->location.plmn);
        //MMI_PRINT(MOD_MMI_COMMON_APP, SRV_NW_INFO_TRC_GROUP, "[NwInfo] New PLMN = %s", cntx->location.plmn);
    
        MMI_FRM_INIT_EVENT(&location_evt, EVT_ID_SRV_NW_INFO_LOCATION_CHANGED);
        location_evt.sim = sim;
        memcpy(&(location_evt.old_location), &(location_evt.new_location), sizeof(srv_nw_info_location_info_struct));
        memcpy(&(location_evt.new_location), &(cntx->location), sizeof(srv_nw_info_location_info_struct));
        MMI_FRM_CB_EMIT_POST_EVENT(&location_evt);

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_update_protocol_capability
 * DESCRIPTION
 *  Update the protocol or the capability information of network by NW_ATTACH_IND.
 *  If one of them changed, it will emit PROTOCOL_CAPABILITY_CHANGED event.
 * PARAMETERS
 *  cntx            [IN] Context
 *  sim             [IN] Which protocol layer
 *  nw_attach_ind   [IN] mmi_nw_attach_ind_struct*
 *  out_protocol_changed    [OUT] Will be set to MMI_TRUE if protocol changed.
 *  out_capability_changed  [OUT] Will be set to MMI_TRUE if capability changed.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_info_update_protocol_capability(
                    srv_nw_info_cntx_struct *cntx,
                    mmi_sim_enum sim,
                    const mmi_nw_attach_ind_struct *nw_attach_ind,
                    MMI_BOOL *out_protocol_changed,
                    MMI_BOOL *out_capability_changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_network_enum old_protocol;
    srv_nw_info_capability_bit_set old_cell_cap;
    srv_nw_info_capability_bit_set old_channel_cap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *out_protocol_changed = MMI_FALSE;
    *out_capability_changed = MMI_FALSE;
    
    old_protocol = cntx->protocol;
    old_cell_cap = cntx->cell_capability;
    old_channel_cap = cntx->channel_capability;

    // CS domain
    if (nw_attach_ind->domain == CS_DOMAIN || nw_attach_ind->domain == CS_PS_DOMAIN)
    {
        switch (nw_attach_ind->status)
        {
            // Ignore searching
            case L4C_RAC_OK:
            case L4C_RAC_LIMITED_SERVICE:
            case L4C_RAC_ATTEMPT_TO_UPDATE:
            case L4C_RAC_INVALID_SIM:
            case L4C_RAC_NO_CELL:
            case L4C_RAC_NULL:
                break;

            default:
                return; /* Ignore */
        }

        /*
         * If we camp on a 2G network, we are unable to know if the
         * operator supports 3G. So even if this bit is not set,
         * 3G may be still available.
         */
        /* rat is valid for PS even if CS detached*/
        if (nw_attach_ind->rat == L4C_RAT_UMTS)
        {
            cntx->protocol = MMI_WCDMA;
        }
        else if (nw_attach_ind->rat == L4C_RAT_GSM)
        {
            cntx->protocol = MMI_GSM;
        }
        else
        {
            cntx->protocol = MMI_NETWORK_NONE;
        }

        /* Cell capability is CS info */
        cntx->cell_capability =
            srv_nw_info_map_cell_capability(cntx->protocol, nw_attach_ind->data_speed_support);
    }

    if (nw_attach_ind->domain == PS_DOMAIN || nw_attach_ind->domain == CS_PS_DOMAIN)
    {
        if (cntx->dn_status & SRV_NW_INFO_SIM_DN_STATUS_ATTACHED)
        {
            if (cntx->protocol == MMI_GSM)
            {
                cntx->channel_capability = cntx->cell_capability;
            }
            else
            {
                /*
                 * We don't need to update channel capability, bacause in 3G
                 * it is unrelated to cell capability but independent.
                 */
            }
        }
        else
        {
            cntx->channel_capability = MMI_NETWORK_CAPABILITY_NONE;
        }
    }

    if (old_protocol != cntx->protocol ||
        old_cell_cap != cntx->cell_capability ||
        old_channel_cap != cntx->channel_capability)
    {
        srv_nw_info_protocol_capability_changed_evt_struct protocol_evt;

        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_PROT_CAP_CHANGED,
            sim, old_protocol, old_cell_cap, old_channel_cap,
            cntx->protocol, cntx->cell_capability, cntx->channel_capability);

        MMI_FRM_INIT_EVENT(&protocol_evt, EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED);
        protocol_evt.sim = sim;
        protocol_evt.old_protocol = old_protocol;
        protocol_evt.old_cell_cap = old_cell_cap;
        protocol_evt.old_channel_cap = old_channel_cap;
        protocol_evt.new_protocol = cntx->protocol;
        protocol_evt.new_cell_cap = cntx->cell_capability;
        protocol_evt.new_channel_cap = cntx->channel_capability;
        MMI_FRM_CB_EMIT_POST_EVENT(&protocol_evt);
    }

    *out_protocol_changed = (old_protocol != cntx->protocol) ? MMI_TRUE : MMI_FALSE;
    *out_capability_changed =
        (old_cell_cap != cntx->cell_capability || old_channel_cap != cntx->channel_capability)? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_update_roaming_status
 * DESCRIPTION
 *  Update the roaming status of network by NW_ATTACH_IND.
 *  If changed, it will emit ROAMING_STATUS_CHANGED event.
 * PARAMETERS
 *  cntx            [IN] Context
 *  sim             [IN] Which protocol layer
 *  new_location    [IN] New location
 * RETURN VALUES
 *  MMI_TRUE    : Roaming status changed
 *  MMI_FALSE   : The same as before
 *****************************************************************************/
static MMI_BOOL srv_nw_info_update_roaming_status(
                    srv_nw_info_cntx_struct *cntx,
                    mmi_sim_enum sim,
                    MMI_BOOL is_on_hplmn_by_spec_criteria,
                    const srv_nw_info_location_info_struct *new_location)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const CHAR *nw_plmn;
    MMI_BOOL is_roaming_before;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nw_plmn = new_location->plmn;
    is_roaming_before = cntx->is_roaming;
    
    if (cntx->service_availability == SRV_NW_INFO_SA_FULL_SERVICE)
    {
        CHAR home_plmn[SRV_MAX_PLMN_LEN + 1];
        MMI_BOOL t_mobile_sim_in_t_mobile_network;
        MMI_BOOL same_pnn_by_phone_table;
        S32 nw_plmn_len;

        if (srv_sim_ctrl_get_home_plmn(sim, home_plmn, sizeof(home_plmn)))
        {
            t_mobile_sim_in_t_mobile_network =
                (srv_netset_is_t_mobile_us_sim(home_plmn) && (strncmp(nw_plmn, "31017", 5) == 0))? MMI_TRUE : MMI_FALSE;

            srv_sim_ctrl_get_home_plmn_for_network(sim, home_plmn, sizeof(home_plmn));
            nw_plmn_len = strlen(nw_plmn);
            if (nw_plmn_len > SRV_MAX_PLMN_LEN)
            {
                nw_plmn_len = SRV_MAX_PLMN_LEN;
            }
            home_plmn[nw_plmn_len] = '\0';

            same_pnn_by_phone_table = srv_netset_is_plmn_roaming(home_plmn, (CHAR*)nw_plmn)? MMI_FALSE : MMI_TRUE;
        }
        else
        {
            t_mobile_sim_in_t_mobile_network = MMI_FALSE;
            same_pnn_by_phone_table = MMI_FALSE;
        }

        cntx->is_roaming =
            (!is_on_hplmn_by_spec_criteria &&
            !t_mobile_sim_in_t_mobile_network &&
            !same_pnn_by_phone_table) ? MMI_TRUE : MMI_FALSE;

        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_ROAMING_CONDITION,
            sim, is_on_hplmn_by_spec_criteria, t_mobile_sim_in_t_mobile_network,
            same_pnn_by_phone_table, cntx->is_roaming);
    }
    else
    {
        cntx->is_roaming = MMI_FALSE;
    }

    if (is_roaming_before != cntx->is_roaming)
    {
        MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_ROAMING_CHANGED,
            is_roaming_before, cntx->is_roaming);

        srv_nw_info_post_roaming_changed(sim, cntx->is_roaming);

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_on_sim_availability_changed
 * DESCRIPTION
 *  Update roaming status on SIM availability changed.
 * PARAMETERS
 *  evt     [IN] srv_sim_ctrl_availability_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_nw_info_on_sim_availability_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *avai_evt;
    srv_nw_info_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avai_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
    cntx = srv_nw_info_get_cntx(avai_evt->sim);

    if (!avai_evt->is_available_now)
    {
        /* reset status */
        if (avai_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED ||
            avai_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_RECOVERY)
        {
            if (cntx->sim_is_rejected == MMI_TRUE)
            {
                cntx->first_availability_emitted = MMI_FALSE;
            }
            cntx->sim_is_rejected = MMI_FALSE;
        }
    
        if (cntx->is_roaming)
        {
            cntx->is_roaming = MMI_FALSE;
            MMI_TRACE(SRV_NW_INFO_TRC_GROUP, TRC_SRV_NW_INFO_ROAMING_CHANGED,
                MMI_TRUE, cntx->is_roaming);

            srv_nw_info_post_roaming_changed(avai_evt->sim, cntx->is_roaming);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_info_nw_attach_ind_hdlr
 * DESCRIPTION
 *  Handler of NW_ATTACH_IND.
 *  Update network status.
 * PARAMETERS
 *  sim     [IN] From which layer
 *  msg     [IN] mmi_nw_attach_ind_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
MMI_BOOL srv_nw_info_nw_attach_ind_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_nw_info_cntx_struct *cntx;
    mmi_nw_attach_ind_struct *nw_attach_ind;
    srv_nw_info_status_changed_evt_struct changed_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&changed_evt, 0, sizeof(changed_evt));

    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    cntx = srv_nw_info_get_cntx(sim);
    nw_attach_ind = (mmi_nw_attach_ind_struct*)msg;

    /********************************/
    /* CS: status,      gsm_state   */
    /* PS: gprs_status, gprs_state  */
    /********************************/

    if (nw_attach_ind->domain == CS_DOMAIN || nw_attach_ind->domain == CS_PS_DOMAIN)
    {
        if ((nw_attach_ind->status == L4C_RAC_OK && !srv_sim_ctrl_is_available(sim)) ||
            nw_attach_ind->status == L4C_RAC_ERROR)
        {
            return MMI_FALSE;
        }
    }

#ifdef __INVALID_SIM_RECOVERY__
    if (nw_attach_ind->domain == CS_DOMAIN || nw_attach_ind->domain == CS_PS_DOMAIN)
    {
        if (nw_attach_ind->status == L4C_RAC_OK)
        {
            memcpy(cntx->ivsr_info.plmn_cs, nw_attach_ind->plmn, MAX_PLMN_LEN+1);
        }
        else if (nw_attach_ind->status == L4C_RAC_INVALID_SIM)
        {
            if (cntx->ivsr_info.enable_ivsr == MMI_TRUE && // open this feature in EM
                is_test_sim(mmi_frm_sim_to_index(sim)) == MMI_FALSE && // not test sim
                cntx->ivsr_info.is_in_test_mode == MMI_FALSE && // not in test mode
                memcmp(cntx->ivsr_info.plmn_cs, nw_attach_ind->plmn, MAX_PLMN_LEN) == 0) // valid network
            {
                srv_sim_ctrl_invalid_sim_recovery_start(sim);
                cntx->ivsr_info.plmn_cs[0] = '\0';
                cntx->ivsr_info.plmn_ps[0] = '\0';
                return;
            }
        }
        else if (srv_sim_ctrl_is_inserted(sim) == MMI_FALSE)
        {
            cntx->ivsr_info.plmn_cs[0] = '\0';
            cntx->ivsr_info.plmn_ps[0] = '\0';
        }
    }

    if (nw_attach_ind->domain == PS_DOMAIN || nw_attach_ind->domain == CS_PS_DOMAIN)
    {
        if (nw_attach_ind->gprs_status == L4C_GPRS_ATTACHED)
        {
            memcpy(cntx->ivsr_info.plmn_ps, nw_attach_ind->plmn, MAX_PLMN_LEN+1);
        }
        else if (nw_attach_ind->gprs_status == L4C_INVALID_SIM)
        {
            if (cntx->ivsr_info.enable_ivsr == MMI_TRUE && // open this feature in EM
                is_test_sim(mmi_frm_sim_to_index(sim)) == MMI_FALSE && // not test sim
                cntx->ivsr_info.is_in_test_mode == MMI_FALSE && // not in test mode
                memcmp(cntx->ivsr_info.plmn_ps, nw_attach_ind->plmn, MAX_PLMN_LEN) == 0) // valid network
            {
                srv_sim_ctrl_invalid_sim_recovery_start(sim);
                cntx->ivsr_info.plmn_cs[0] = '\0';
                cntx->ivsr_info.plmn_ps[0] = '\0';
                return;
            }
        }
        else if (srv_sim_ctrl_is_inserted(sim) == MMI_FALSE)
        {
            cntx->ivsr_info.plmn_cs[0] = '\0';
            cntx->ivsr_info.plmn_ps[0] = '\0';
        }
    }
#endif /* __INVALID_SIM_RECOVERY__ */

    MMI_FRM_INIT_EVENT(&changed_evt, EVT_ID_SRV_NW_INFO_STATUS_CHANGED);
    changed_evt.sim = sim;
    if (nw_attach_ind->domain == CS_DOMAIN || nw_attach_ind->domain == CS_PS_DOMAIN)
    {
        changed_evt.service_availability_changed =
            srv_nw_info_update_service_availability(cntx, sim, nw_attach_ind);
        changed_evt.location_changed =
            srv_nw_info_update_location_info(cntx, sim, nw_attach_ind);

        /* Should be call after srv_nw_info_update_location_info() */
        srv_nw_info_update_roaming_status(
            cntx,
            sim,
            nw_attach_ind->is_on_hplmn,
            &(cntx->location));
    }
    
    if (nw_attach_ind->domain == PS_DOMAIN || nw_attach_ind->domain == CS_PS_DOMAIN)
    {
        changed_evt.dn_status_changed =
            srv_nw_info_update_sim_dn_status(cntx, sim, (l4c_gprs_status_enum)nw_attach_ind->gprs_status);
    }

    /* Protocol & capability */
    srv_nw_info_update_protocol_capability(
        cntx,
        sim,
        nw_attach_ind,
        &(changed_evt.protocol_changed),
        &(changed_evt.capability_changed));

    if (changed_evt.service_availability_changed ||
        changed_evt.location_changed ||
        changed_evt.dn_status_changed ||
        changed_evt.protocol_changed ||
        changed_evt.capability_changed)
    {
        MMI_FRM_CB_EMIT_POST_EVENT(&changed_evt);
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
srv_nw_info_service_availability_enum srv_nw_info_get_service_availability(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (cntx->service_availability);
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_info_sim_is_rejected(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (cntx->sim_is_rejected);
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_info_is_roaming(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (cntx->is_roaming);
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_info_get_location_info(
                mmi_sim_enum sim,
                srv_nw_info_location_info_struct *out_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_NW_INFO_SA_LIMITED_SERVICE == cntx->service_availability
		|| SRV_NW_INFO_SA_FULL_SERVICE == cntx->service_availability)
    {
		memcpy(out_info, &(cntx->location), sizeof(srv_nw_info_location_info_struct));		
		return MMI_TRUE;
    }
	else
    {
            memset(out_info, 0, sizeof(srv_nw_info_location_info_struct));
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_info_get_nw_plmn(mmi_sim_enum sim, CHAR *out_plmn_buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(buffer_size >= SRV_MAX_PLMN_LEN + 1);
        
    if (SRV_NW_INFO_SA_LIMITED_SERVICE == cntx->service_availability
        || SRV_NW_INFO_SA_FULL_SERVICE == cntx->service_availability)
    {
        app_strlcpy(out_plmn_buffer, cntx->location.plmn, buffer_size);
        return MMI_TRUE;
    }
    else
    {
            out_plmn_buffer[0] = L'\0';
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_info_cell_supports(mmi_sim_enum sim, mmi_network_capability_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (((cntx->cell_capability & type) != 0)? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_info_channel_supports(mmi_sim_enum sim, mmi_network_capability_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (((cntx->channel_capability & type) != 0)? MMI_TRUE : MMI_FALSE);
}

/*****************************************************************************
 * Please refer to NwInfoSrvGprot.h
 *****************************************************************************/
mmi_network_enum srv_nw_info_get_protocol(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (cntx->protocol);
}

#ifdef __OP01_3G__
MMI_BOOL srv_nw_info_is_need_display_fake_nw_status(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cntx_struct *cntx = srv_nw_info_get_cntx(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cntx->display_fake_nw;
}
#endif /*__OP01_3G__*/
