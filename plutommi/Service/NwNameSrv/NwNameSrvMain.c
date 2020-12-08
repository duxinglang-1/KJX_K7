/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  NwNameSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This header implements the network name service.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "NwNameSrvProt.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "BootupSrvGprot.h"
#include "app_plmn.h"
#include "NetSetSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "SatSrvGprot.h"
#include "mmi_frm_gprot.h"
#include "ImeiSrvGprot.h"
#include "wgui_categories_util.h"
#include "NetSetAppGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "NwNameSrvGprot.h"
#include "NwNameSrvMain.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "Unicodexdcl.h"
#include "mmi_rp_srv_nw_name_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "NwNameSrvCphs.h"
#include "NwNameSrvSpdi.h"

#include "sim_common_enums.h"
#include "PixcomFontEngine.h"
#include "GlobalResDef.h"

#if defined(__MMI_EONS_SRV__)
#include "mmi_rp_srv_eons_def.h"
#include "EonsSrvGprot.h"
#endif

#if defined(__MMI_NITZ__)
// for nitz event
#include "NITZSrvGprot.h"
#endif


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef MMI_BOOL (*srv_nw_name_is_feasible_cb)(mmi_sim_enum sim, MMI_BOOL is_spec_required);

typedef const WCHAR *(*srv_nw_name_get_name_cb)(mmi_sim_enum sim);

typedef struct
{
    srv_nw_name_type_enum           type;
    srv_nw_name_is_feasible_cb      is_feasible;
    srv_nw_name_get_name_cb         get_name;
} srv_nw_name_cfg_struct;


/****************************************************************************
 * Prototype
 ****************************************************************************/

#if defined(__MMI_NITZ__)
/*
 * TODO: NITZ does not follow the App / Srv split guideline.
 */
extern void srv_nitz_get_nitz_nw_name(U8 sim_id, U8* plmn, U8* nwname, U8 len, BOOL* add_ci);
#endif /* defined(__MMI_NITZ__) */

static void srv_nw_name_update(mmi_sim_enum sim);

static void srv_nw_name_reset(mmi_sim_enum sim);

static MMI_BOOL srv_nw_name_is_feasible_by_common(mmi_sim_enum sim, MMI_BOOL is_spec_required);

static MMI_BOOL srv_nw_name_is_feasible_by_cphs(mmi_sim_enum sim, MMI_BOOL is_spec_required);

static const WCHAR *srv_nw_name_get_name_by_eons(mmi_sim_enum sim);

static const WCHAR *srv_nw_name_get_name_by_nitz(mmi_sim_enum sim);

static const WCHAR *srv_nw_name_get_name_by_cphs(mmi_sim_enum sim);

static const WCHAR *srv_nw_name_get_name_by_rom(mmi_sim_enum sim);


/****************************************************************************
 * Global variable
 ****************************************************************************/

/*
 * Register the different sources of the network name here.
 *
 * Note that both "is_feasible" and 'get_name" cannot be NULL.
 */
const static srv_nw_name_cfg_struct g_srv_nw_name_cfg_tbl[] =
{
#if defined(__MMI_EONS_SRV__)
    {
        SRV_NW_NAME_TYPE_EONS,
        srv_nw_name_is_feasible_by_common,
        srv_nw_name_get_name_by_eons
    }
    ,
#endif
    {
        SRV_NW_NAME_TYPE_NITZ,
        srv_nw_name_is_feasible_by_common,
        srv_nw_name_get_name_by_nitz
    }
    ,
    {
        SRV_NW_NAME_TYPE_CPHS,
        srv_nw_name_is_feasible_by_cphs,
        srv_nw_name_get_name_by_cphs
    }
    ,
    {
        SRV_NW_NAME_TYPE_ROM,
        srv_nw_name_is_feasible_by_common,
        srv_nw_name_get_name_by_rom
    }
    ,

    /* Last element, used to determine the end of the configuration. */
    {SRV_NW_NAME_TYPE_TOTAL, NULL, NULL}
};


static srv_nw_name_cntx_struct g_srv_nw_name_cntx;


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_print_debug_info
 * DESCRIPTION
 *  This function prints the debug info.
 * PARAMETERS
 *  sim             : [IN]          SIM id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_print_debug_info(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);
    CHAR trc_name[SRV_NW_NAME_MAX_BUF_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_PRINT_DISPLAY_CONDITION,
                    cntx->is_rplmn_required_in_home,
                    cntx->is_spn_required_in_roaming));

#if defined(__MMI_EONS_SRV__)
    mmi_wcs_n_to_asc(trc_name, cntx->eons, SRV_NW_NAME_MAX_STR_LEN);
    SRV_NWNAME_PRINT(("[NWNAME][MAIN] EONS: %s", trc_name));
#endif

    mmi_wcs_n_to_asc(trc_name, cntx->nitz, SRV_NW_NAME_MAX_STR_LEN);
    SRV_NWNAME_PRINT(("[NWNAME][MAIN] NITZ: %s", trc_name));

    mmi_wcs_n_to_asc(trc_name, cntx->ons, SRV_NW_NAME_MAX_STR_LEN);
    SRV_NWNAME_PRINT(("[NWNAME][MAIN] ONS: %s", trc_name));

    mmi_wcs_n_to_asc(trc_name, cntx->short_ons, SRV_NW_NAME_MAX_STR_LEN);
    SRV_NWNAME_PRINT(("[NWNAME][MAIN] Short ONS: %s", trc_name));

    mmi_wcs_n_to_asc(trc_name, cntx->rom, SRV_NW_NAME_MAX_STR_LEN);
    SRV_NWNAME_PRINT(("[NWNAME][MAIN] ROM: %s", trc_name));

    mmi_wcs_n_to_asc(trc_name, cntx->spn, SRV_NW_NAME_MAX_STR_LEN);
    SRV_NWNAME_PRINT(("[NWNAME][MAIN] SPN: %s", trc_name));
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_emit_changed
 * DESCRIPTION
 *  This function emits the changed event.
 * PARAMETERS
 *  sim           : [IN]      SIM id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_emit_changed(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_changed_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_EMIT_CHANGED, sim));

    srv_nw_name_print_debug_info(sim);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_NW_NAME_CHANGED);
    evt.sim = sim;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

#if defined(__MMI_EONS_SRV__)
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_emit_changed
 * DESCRIPTION
 *  This function emits the changed event.
 * PARAMETERS
 *  sim           : [IN]      SIM id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_emit_sim_changed_by_sat(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_changed_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_NWNAME_LOG((TRC_SRV_NW_NAME_SIM_CHANGED_BY_SAT, sim));
    
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_NW_NAME_SIM_CHANGED_BY_SAT);
    evt.sim = sim;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_handle_bootup_early_init
 * DESCRIPTION
 *  This function handles the bootup early init.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_nw_name_handle_bootup_early_init(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_srv_nw_name_cntx, 0, sizeof(srv_nw_name_cntx_struct));

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        cntx = &(g_srv_nw_name_cntx.nw_name[i]);

        cntx->sim = mmi_frm_index_to_sim(i);

        /*
         * Module waiting for initialization.
         */
        srv_nw_name_set_mod_waiting(cntx->sim, SRV_NW_NAME_MOD_CPHS);
        srv_nw_name_set_mod_waiting(cntx->sim, SRV_NW_NAME_MOD_SPDI);
    #if defined(__MMI_EONS_SRV__)
        srv_nw_name_set_mod_waiting(cntx->sim, SRV_NW_NAME_MOD_EONS);
    #endif
    }

    srv_nw_name_cphs_bootup_early_init_hdlr();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_handle_bootup_before_idle
 * DESCRIPTION
 *  This function handles the bootup before idle event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_nw_name_handle_bootup_before_idle(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_BEFORE_IDLE));

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        cntx = srv_nw_name_get_context(mmi_frm_index_to_sim(i));
        MMI_ASSERT(cntx);
        
        if (cntx->module_init_mask == 0)
        {
            // already initialize
            continue;
        }
    
        if (srv_sim_ctrl_is_available(mmi_frm_index_to_sim(i)))
        {
            srv_nw_name_spdi_init_module(mmi_frm_index_to_sim(i));
        }
        else
        {
            srv_nw_name_set_mod_ready(mmi_frm_index_to_sim(i), SRV_NW_NAME_MOD_CPHS);
            srv_nw_name_set_mod_ready(mmi_frm_index_to_sim(i), SRV_NW_NAME_MOD_SPDI);
        #if defined(__MMI_EONS_SRV__)
            srv_nw_name_set_mod_ready(mmi_frm_index_to_sim(i), SRV_NW_NAME_MOD_EONS);
        #endif
        }
    }

    return MMI_RET_OK;
}

#if defined(__MMI_EONS_SRV__)
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_handle_eons_updated
 * DESCRIPTION
 *  This function handles the EONS update event.
 * PARAMETERS
 *  event           : [IN]     Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_nw_name_handle_eons_updated(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_updated_evt_struct *evt = (srv_eons_updated_evt_struct *)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_HANDLE_EONS_UPDATED, evt->sim));

    srv_nw_name_set_mod_ready(evt->sim, SRV_NW_NAME_MOD_EONS);

    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_handle_sim_state_changed
 * DESCRIPTION
 *  This function handles the SIM availability changed event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_nw_name_handle_sim_state_changed(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_sim_ctrl_availability_changed_evt_struct *)event;
    MMI_ASSERT(evt);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_HANDLE_SIM_STATE_CHANGED,
                    evt->is_available_before,
                    evt->is_available_now,
                    evt->sim));

    /* Refresh EF_SPDI if the SIM card changes from unavailable to available
       after the handset has already booted-up. */
    if (srv_bootup_is_completed() &&
        evt->is_available_now && !evt->is_available_before)
    {
        srv_nw_name_spdi_init_module(evt->sim);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_handle_location_changed
 * DESCRIPTION
 *  This function handles the location changed event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_nw_name_handle_location_changed(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_location_changed_evt_struct *evt;
    CHAR *plmn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_nw_info_location_changed_evt_struct *)event;
    MMI_ASSERT(evt);

    plmn = evt->new_location.plmn;
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_HANDLE_LOCATION_CHANGED,
                    plmn[0], plmn[1], plmn[2], plmn[3], plmn[4], plmn[5],
                    evt->sim));

    srv_nw_name_update(evt->sim);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_handle_service_availability_changed
 * DESCRIPTION
 *  This function handles the service availability changed event.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_nw_name_handle_service_availability_changed(
    mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *evt;
    srv_nw_name_struct *cntx;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_nw_info_service_availability_changed_evt_struct *)event;
    MMI_ASSERT(evt);

    cntx = srv_nw_name_get_context(evt->sim);
    MMI_ASSERT(cntx);

    /* [MAUI_02646105] Service availability changed event may be received 
     * before enter idle, need to initial sim first if receive this event 
     * during bootup, 
     */
    if (evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE && 
            cntx->module_init_mask != 0 && srv_bootup_is_booting())
    {
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_HANDLE_AVAILABILITY_CHANGED,
                evt->old_status, evt->new_status, 500, evt->sim));
        
        if (srv_sim_ctrl_is_available(evt->sim))
        {
            srv_nw_name_spdi_init_module(evt->sim);
            
            SRV_NWNAME_LOG((TRC_SRV_NWNAME_HANDLE_AVAILABILITY_CHANGED,
                evt->old_status, evt->new_status, 501, evt->sim));
        }
        return MMI_RET_OK;
    }

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_HANDLE_AVAILABILITY_CHANGED,
                    evt->old_status, evt->new_status, 200, evt->sim));

    srv_nw_name_update(evt->sim);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_sim_ctrl_event_detected
 * DESCRIPTION
 *  This function handles the sim hot swap event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_nw_name_sim_ctrl_event_detected(mmi_event_struct * event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *evt;
#ifdef __VSIM__
    srv_nw_name_struct *cntx;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_sim_ctrl_event_detected_evt_struct *)event;
    MMI_ASSERT(evt);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_HANDLE_SIM_CTRL_EVENT_DETECTED,
                    evt->sim, evt->type, evt->change_check));

#ifdef __VSIM__
    cntx = srv_nw_name_get_context(evt->sim);
    if (evt->type == SRV_SIM_CTRL_EVENT_DET_VSIM_ON)
    {
        cntx->is_vsim_on = MMI_TRUE;
    }
    else if (evt->type == SRV_SIM_CTRL_EVENT_DET_VSIM_OFF)
    {
        cntx->is_vsim_on = MMI_FALSE;
    }
#endif

    srv_nw_name_update(evt->sim);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_sim_refresh_start
 * DESCRIPTION
 *  This function start to refresh sim file
 * PARAMETERS
 *  mmi_event_struct       : [IN]          srv_sat_sim_refresh_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_nw_name_sim_refresh_start(mmi_event_struct *event)
{
    srv_sat_sim_refresh_event_struct *evt = (srv_sat_sim_refresh_event_struct *)event;
    S32 i;
    if(evt->refresh_type == SRV_SAT_REFRESH_FILE_CHANGE)
    {
        for(i=0; i < evt->num_of_file; i++)
        {
            if(evt->file_list[i] == FILE_SPN_IDX)
            {
                SRV_NWNAME_LOG((TRC_SRV_NWNAME_SIM_REFRESH_START,
                    evt->sim_id, evt->file_list[i], 201));
                srv_nw_name_set_mod_waiting(evt->sim_id, SRV_NW_NAME_MOD_CPHS);
                srv_nw_name_read_spn(evt->sim_id); /* transparent EF, read data directly */
            }
        #if defined(__MMI_EONS_SRV__)
            else if(evt->file_list[i] == FILE_OPL_IDX || evt->file_list[i] == FILE_PNN_IDX)
            {
                SRV_NWNAME_LOG((TRC_SRV_NWNAME_SIM_REFRESH_START,
                    evt->sim_id, evt->file_list[i], 200));
                srv_nw_name_set_mod_waiting(evt->sim_id, SRV_NW_NAME_MOD_EONS);
                srv_nw_name_emit_sim_changed_by_sat(evt->sim_id);            
            }
        #endif
        }
    }
    return MMI_RET_OK;
}

mmi_ret srv_nw_name_handle_mode_switch_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *evt = (srv_mode_switch_notify_struct*)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* OFF --> ON */
    if (evt->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
        evt->select_flight_mode == SRV_MODE_SWITCH_ON)
    {
        if (MMI_SIM_ALL & MMI_SIM1)
        {
            srv_nw_name_emit_changed(MMI_SIM1);
        }
        if (MMI_SIM_ALL & MMI_SIM2)
        {
            srv_nw_name_emit_changed(MMI_SIM2);
        }
        if (MMI_SIM_ALL & MMI_SIM3)
        {
            srv_nw_name_emit_changed(MMI_SIM3);
        }
        if (MMI_SIM_ALL & MMI_SIM4)
        {
            srv_nw_name_emit_changed(MMI_SIM4);
        }
    }
    return MMI_RET_OK;
}


#if defined(__MMI_NITZ__)
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_handle_nitz_nw_name_changed
 * DESCRIPTION
 *  This function handles the nitz network name changed event, but the plmn id is the same
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_nw_name_handle_nitz_nw_name_changed(
    mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nitz_nw_name_update_event_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_nitz_nw_name_update_event_struct *)event;
    MMI_ASSERT(evt);

    srv_nw_name_update(evt->sim_id);

    return MMI_RET_OK;
}
#endif


/* For the detail information, please refer to the NwNameSrvGprot.h */
mmi_ret srv_nw_name_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
            ret = srv_nw_name_handle_bootup_early_init(event);
            break;

        case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
            ret = srv_nw_name_handle_bootup_before_idle(event);
            break;
    #if defined(__MMI_EONS_SRV__)
        case EVT_ID_SRV_EONS_UPDATED:
            ret = srv_nw_name_handle_eons_updated(event);
            break;
    #endif
        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
            ret = srv_nw_name_handle_sim_state_changed(event);
            break;

        case EVT_ID_SRV_NW_INFO_LOCATION_CHANGED:
            ret = srv_nw_name_handle_location_changed(event);
            break;

        case EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED:
            ret = srv_nw_name_handle_service_availability_changed(event);
            break;

        case EVT_ID_SRV_SAT_SIM_REFRESH:
            ret = srv_nw_name_sim_refresh_start(event);
            break;

        case EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED:
            ret = srv_nw_name_sim_ctrl_event_detected(event);
            break;

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
            ret = srv_nw_name_handle_mode_switch_hdlr(event);
            break;
            
    #if defined(__MMI_NITZ__)
        case EVT_ID_NITZ_NW_NAME_UPDATE_NOTIFY:
            ret = srv_nw_name_handle_nitz_nw_name_changed(event);
    #endif
    
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_context
 * DESCRIPTION
 *  This function gets the context.
 * PARAMETERS
 *  sim           : [IN]      SIM id
 * RETURNS
 *  Context.
 *****************************************************************************/
srv_nw_name_struct *srv_nw_name_get_context(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        cntx = &g_srv_nw_name_cntx.nw_name[i];

        if (cntx->sim == sim)
        {
            return cntx;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_set_mod_waiting
 * DESCRIPTION
 *  This function sets the module waiting.
 * PARAMETERS
 *  sim             : [IN]          SIM id
 *  module          : [IN]          Module
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nw_name_set_mod_waiting(mmi_sim_enum sim, U8 module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    SRV_NW_NAME_SET(cntx->module_init_mask, module);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_SET_MODULE_WAITING,
                    module, cntx->module_init_mask, sim));
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_set_mod_ready
 * DESCRIPTION
 *  This function sets the module ready.
 * PARAMETERS
 *  sim             : [IN]          SIM id
 *  module          : [IN]          Module
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nw_name_set_mod_ready(mmi_sim_enum sim, U8 module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    SRV_NW_NAME_CLR(cntx->module_init_mask, module);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_SET_MODULE_READY,
                    module, cntx->module_init_mask, sim));

    srv_nw_name_update(sim);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_update_by_rom
 * DESCRIPTION
 *  This function updates the network name from the device's ROM.
 * PARAMETERS
 *  cntx                : [IN]          Network name
 *  location            : [IN]          Location
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_update_by_rom(
    srv_nw_name_struct *cntx,
    srv_nw_info_location_info_struct *location)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_network_enum protocol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx && location);

    /*
     * TODO: This API should check the buffer size of cntx->rom.
     */
    mmi_netset_retrieve_opname_from_plmn((U8 *)location->plmn, (U8 *)cntx->rom);

    /*
     * Specify for CMCC,  
     * Requirement is that append "3G" in the end of operator name 
     * if camp on TD network (check NW_ATTACH_IND : rat = 2)
     * TODO: plmnlist.txt should support 2G/3G directly
     */    
    protocol = srv_nw_info_get_protocol(cntx->sim);
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_UPDATE_BY_ROM,
                    200, cntx->sim, protocol));
    
#if defined(__OP01_3G__)    // wrap CMCC compile option
#if (!defined(__OP01_FWPBW__) && !defined(__OP01_FWPCOLOR__)) // wrap FWP compile option
    if (protocol == MMI_WCDMA)
    {
        if (memcmp(location->plmn, "46000", SRV_MAX_PLMN_LEN) ||
            memcmp(location->plmn, "46002", SRV_MAX_PLMN_LEN) || 
            memcmp(location->plmn, "46007", SRV_MAX_PLMN_LEN) ||
            memcmp(location->plmn, "45412", SRV_MAX_PLMN_LEN))
        {
            SRV_NWNAME_LOG((TRC_SRV_NWNAME_UPDATE_BY_ROM,
                    300, cntx->sim, protocol));
            kal_wstrcat(cntx->rom, L" 3G");
        }
    }
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_update_by_nitz
 * DESCRIPTION
 *  This function updates the network name from NITZ.
 *
 *  TODO: country initials, e.g., US, should be supported.
 *
 * PARAMETERS
 *  cntx                : [IN]          Network name
 *  location            : [IN]          Location
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_update_by_nitz(
    srv_nw_name_struct *cntx,
    srv_nw_info_location_info_struct *location)
{
#if defined(__MMI_NITZ__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[SRV_NW_NAME_MAX_BUF_SIZE];
    CHAR plmn[SRV_MAX_PLMN_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx && location);

    kal_wsprintf(name, "");

    /* Must reset plmn[] since NITZ API will not help us append '\0'. */
    kal_mem_set(plmn, 0, sizeof(plmn));

    /*
     * TODO: Ask NITZ to provide proper API and header to get the name.
     */
    srv_nitz_get_nitz_nw_name(
        (U8)cntx->sim,
        (U8 *)plmn,
        (U8 *)name,
        SRV_NW_NAME_MAX_STR_LEN,
        NULL);

    if (memcmp(plmn, location->plmn, SRV_MAX_PLMN_LEN))
    {
        kal_wsprintf(cntx->nitz, "");
    }
    else
    {
        mmi_wcsncpy(cntx->nitz, name, SRV_NW_NAME_MAX_STR_LEN);
    }
#endif /* defined(__MMI_NITZ__) */
}


#if defined(__MMI_EONS_SRV__)
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_update_by_eons_hdlr
 * DESCRIPTION
 *  This function is the callback function of getting EONS.
 * PARAMETERS
 *  name                : [IN]          EONS name
 *  user_data           : [IN]          User data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_update_by_eons_hdlr(
    const srv_eons_name_struct *name,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = (srv_nw_name_struct *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx && name && name->sim == cntx->sim);

    mmi_wcsncpy(cntx->eons, name->full_name, SRV_NW_NAME_MAX_STR_LEN);

    srv_nw_name_emit_changed(cntx->sim);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_update_by_eons
 * DESCRIPTION
 *  This function updates the EONS network name.
 * PARAMETERS
 *  cntx                : [IN]          Network name
 *  location            : [IN]          Location
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_update_by_eons(
    srv_nw_name_struct *cntx,
    srv_nw_info_location_info_struct *location)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx && location);

    kal_wsprintf(cntx->eons, "");

    ret = srv_eons_get_name(
            cntx->sim,
            location->plmn,
            location->lac,
            srv_nw_name_update_by_eons_hdlr,
            cntx);

    /*
     * [Release 7] TS31.102
     * If the EF OPL is not present, then the first record in EF PNN is used
     * for the default network name when registered in the HPLMN or an EHPLMN
     */
    if(!ret && srv_eons_default_network_name_is_needed(cntx->sim))
    {
        ret = srv_eons_get_default_network_name(
                cntx->sim,
                srv_nw_name_update_by_eons_hdlr,
                cntx);
    }

    if (ret)
    {
        return; /* Wait for EONS's callback. */
    }

    srv_nw_name_emit_changed(cntx->sim);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_update
 * DESCRIPTION
 *  This function updates the network name.
 * PARAMETERS
 *  sim           : [IN]        SIM id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_update(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);
    srv_nw_info_location_info_struct location;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    if (cntx->module_init_mask != 0)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_UPDATE, 500, sim));
        return;
    }

    ret = srv_nw_info_get_location_info(sim, &location);
    if (!ret)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_UPDATE, 501, sim));

        srv_nw_name_reset(sim);

        return;
    }

    /*
     * Update the name which are changed according to the network.
     */
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_UPDATE, 200, sim));

    srv_nw_name_update_by_nitz(cntx, &location);

    srv_nw_name_update_by_rom(cntx, &location);

#if defined(__MMI_EONS_SRV__)
    /* EVT_ID_SRV_NW_NAME_CHANGED will be sent after receive eons callback */
    srv_nw_name_update_by_eons(cntx, &location);
#else
    /* Send EVT_ID_SRV_NW_NAME_CHANGED directly when no necessary to wail for eons callback. */
    srv_nw_name_emit_changed(cntx->sim);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_reset
 * DESCRIPTION
 *  This function resets the network name.
 * PARAMETERS
 *  sim           : [IN]        SIM id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_reset(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    /* Reset the network name that are changed according to the PLMN. */
#if defined(__MMI_EONS_SRV__)
    kal_wsprintf(cntx->eons, "");
#endif
    kal_wsprintf(cntx->nitz, "");
    kal_wsprintf(cntx->rom, "");

    srv_nw_name_emit_changed(sim);
}


/* For the detail information, please refer to the NwNameSrvGprot.h */
MMI_BOOL srv_nw_name_is_ready(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);
    srv_nw_info_service_availability_enum service_availability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_NOT_READY_ERROR, 400, sim));
        return MMI_FALSE;
    }

    service_availability = srv_nw_info_get_service_availability(sim);
    if (service_availability != SRV_NW_INFO_SA_FULL_SERVICE &&
        service_availability != SRV_NW_INFO_SA_LIMITED_SERVICE)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_NOT_READY_ERROR, 401, sim));
        return MMI_FALSE;
    }

    if (cntx->module_init_mask)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_SUB_MODULE_NOT_READY,
                        cntx->module_init_mask, sim));
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/* For the detail information, please refer to the NwNameSrvGprot.h */
MMI_BOOL srv_nw_name_is_rplmn_required(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Invalid parameter or service is not ready. Display RPLMN by default.
     */
    if (!cntx || !srv_nw_name_is_ready(sim))
    {
        return MMI_TRUE;
    }

    /*
     * Roaming and PLMN is not in EF_SPDI list. Display RPLMN by default.
     */
    if (srv_nw_info_is_roaming(sim) && !srv_nw_name_spdi_is_present(sim))
    {
        return MMI_TRUE;
    }

    /*
     * 'Display Condition' byte in the EF_SPN.
     */
    return cntx->is_rplmn_required_in_home;
}


/* For the detail information, please refer to the NwNameSrvGprot.h */
MMI_BOOL srv_nw_name_is_spn_required(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Invalid parameter or service is not ready. Display SPN by default.
     */
    if (!cntx || !srv_nw_name_is_ready(sim))
    {
        return MMI_TRUE;
    }

    /*
     * In home or in the EF_SPDI list. Display SPN by default.
     */
    if (!srv_nw_info_is_roaming(sim) || srv_nw_name_spdi_is_present(sim))
    {
        return MMI_TRUE;
    }

    /*
     * 'Display Condition' byte in the EF_SPN.
     */
    return cntx->is_spn_required_in_roaming;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_first_cfg
 * DESCRIPTION
 *  This function gets the first name configuration.
 * PARAMETERS
 *  void
 * RETURNS
 *  First name configuration.
 *****************************************************************************/
static const srv_nw_name_cfg_struct *srv_nw_name_get_first_cfg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_nw_name_cfg_tbl[0].type >= SRV_NW_NAME_TYPE_TOTAL)
    {
        return NULL;
    }

    return &(g_srv_nw_name_cfg_tbl[0]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_next_cfg
 * DESCRIPTION
 *  This function gets the next name configuration.
 * PARAMETERS
 *  cfg           : [IN]        Name configuration
 * RETURNS
 *  Next name configuration.
 *****************************************************************************/
static const srv_nw_name_cfg_struct *
srv_nw_name_get_next_cfg(const srv_nw_name_cfg_struct *cfg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cfg || cfg[1].type >= SRV_NW_NAME_TYPE_TOTAL)
    {
        return NULL;
    }

    return &(cfg[1]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_is_feasible_by_common
 * DESCRIPTION
 *  This function checks if the name is feasible.
 * PARAMETERS
 *  sim           : [IN]        SIM id
 * RETURNS
 *  On feasible, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_is_feasible_by_common(mmi_sim_enum sim, MMI_BOOL is_spec_required)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(is_spec_required)
    {
        return srv_nw_name_is_rplmn_required(sim);
    }

    return MMI_TRUE;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_is_feasible_by_cphs
 * DESCRIPTION
 *  This function is the CPHS name is feasible.
 * PARAMETERS
 *  sim           : [IN]        SIM id
 * RETURNS
 *  On feasible, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_is_feasible_by_cphs(mmi_sim_enum sim, MMI_BOOL is_spec_required)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_chinese_network = MMI_FALSE;
    CHAR plmn[SRV_MAX_PLMN_LEN + 1];
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Roaming. Do not use CPHS network name, which is only for home network. */
    if (srv_nw_info_is_roaming(sim))
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_NO_CPHS_IN_ROAMING, sim));
        return MMI_FALSE;
    }

    /*
     * Since CPHS OPN and short OPN is only ASCII string, we disable it if the
     * current network and language are both Chinese.
     */
    ret = srv_nw_info_get_nw_plmn(sim, plmn, SRV_MAX_PLMN_LEN + 1);
    if (ret)
    {
        if (memcmp(plmn, "460", 3) == 0 ||  /* CN */
            memcmp(plmn, "466", 3) == 0 ||  /* TW */
            memcmp(plmn, "454", 3) == 0)    /* HK */
        {
            is_chinese_network = MMI_TRUE;
        }
    }

    if (IsChineseSet() && is_chinese_network)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_NO_CPHS_IN_CHINESE_NETWORK, sim));
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


#if defined(__MMI_EONS_SRV__)
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_name_by_eons
 * DESCRIPTION
 *  This function gets the EONS network name.
 *
 *  TODO: support the short form of the EONS.
 *
 * PARAMETERS
 *  sim             : [IN]          SIM id
 * RETURNS
 *  Name string.
 *****************************************************************************/
static const WCHAR *srv_nw_name_get_name_by_eons(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cntx ? cntx->eons : NULL;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_name_by_nitz
 * DESCRIPTION
 *  This function gets the NITZ network name.
 *
 *  TODO: support the short form of the NITZ.
 *
 * PARAMETERS
 *  sim             : [IN]          SIM id
 * RETURNS
 *  Name string.
 *****************************************************************************/
static const WCHAR *srv_nw_name_get_name_by_nitz(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);
    srv_nw_info_location_info_struct location;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        return NULL;
    }

    /*
     * Since NITZ does not provide the event when NITZ is received, we need to
     * refresh the NITZ name each time we want to get it.
     *
     * TODO: it is better to have an event to notify this.
     */
    if (srv_nw_info_get_location_info(sim, &location))
    {
        srv_nw_name_update_by_nitz(cntx, &location);
    }

    return cntx->nitz;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_name_by_cphs
 * DESCRIPTION
 *  This function gets the CPHS network name.
 * PARAMETERS
 *  sim             : [IN]          SIM id
 * RETURNS
 *  Name string.
 *****************************************************************************/
static const WCHAR *srv_nw_name_get_name_by_cphs(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        return NULL;
    }

    if (mmi_wcslen(cntx->ons))
    {
        return cntx->ons;
    }

    return cntx->short_ons;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_name_by_rom
 * DESCRIPTION
 *  This function gets the ROM network name.
 * PARAMETERS
 *  sim             : [IN]          SIM id
 * RETURNS
 *  Name string.
 *****************************************************************************/
static const WCHAR *srv_nw_name_get_name_by_rom(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);
    srv_nw_info_location_info_struct location;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        return NULL;
    }

    /*
     * Since network name in the handset's ROM might change when the handset's
     * language is changed, we need to refresh the NITZ name each time we want
     * to get it.
     *
     * TODO: it is better to have an event to notify this.
     */
    if (srv_nw_info_get_location_info(sim, &location))
    {
        srv_nw_name_update_by_rom(cntx, &location);
    }

    return cntx ? cntx->rom : NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_name_by_priority
 * DESCRIPTION
 *  This function gets the name according to their priority.
 * PARAMETERS
 *  sim                         : [IN]          SIM id
 *  name                        : [OUT]         Output name buffer
 *  size                        : [IN]          Name buffer size in WCHAR
 *  is_spec_required            : [IN]          Is feasible by spec or not
 * RETURNS
 *  Length of the network name.
 *****************************************************************************/
static S32 srv_nw_name_get_name_by_priority(
    mmi_sim_enum sim,
    WCHAR *name,
    S32 size,
    MMI_BOOL is_spec_required)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const srv_nw_name_cfg_struct *cfg;
    const WCHAR *src_name;
    CHAR trc_name[SRV_NW_NAME_MAX_BUF_SIZE];
    S32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_nw_name_is_ready(sim))
    {
        return 0;
    }

    for (cfg = srv_nw_name_get_first_cfg();
         cfg != NULL;
         cfg = srv_nw_name_get_next_cfg(cfg))
    {
        MMI_ASSERT(cfg->is_feasible && cfg->get_name);

        if (!cfg->is_feasible(sim, is_spec_required))
        {
            SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_BY_PRIORITY, cfg->type, 400, sim));
            continue;
        }

        src_name = cfg->get_name(sim);
        if (!src_name || (length = mmi_wcslen(src_name)) == 0)
        {
            SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_BY_PRIORITY, cfg->type, 401, sim));
            continue;
        }

        if (name && size > 0)
        {
            mmi_wcsncpy(name, src_name, size - 1);
        }

        SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_BY_PRIORITY, cfg->type, 200, sim));

        mmi_wcs_n_to_asc(trc_name, (WCHAR *)src_name, SRV_NW_NAME_MAX_STR_LEN);
        SRV_NWNAME_PRINT(("[NWNAME][MAIN]     Network name: %s", trc_name));

        return length;
    }

    return 0;
}


/* For the detail information, please refer to the NwNameSrvGprot.h */
S32 srv_nw_name_get_name_ex(
    mmi_sim_enum sim,
    srv_nw_name_type_enum type,
    WCHAR *name,
    S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const srv_nw_name_cfg_struct *cfg;
    const WCHAR *src_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_nw_name_is_ready(sim))
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_EX, type, 500, sim));
        return 0;
    }

    /*
     * Find the associated configuration.
     */
    for (cfg = srv_nw_name_get_first_cfg();
         cfg != NULL;
         cfg = srv_nw_name_get_next_cfg(cfg))
    {
        MMI_ASSERT(cfg->is_feasible && cfg->get_name);

        if (cfg->type == type)
        {
            break;
        }
    }

    /*
     * Copy the name to the output buffer.
     */
    if (!cfg || (src_name = cfg->get_name(sim)) == NULL)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_EX, type, 501, sim));
        return 0;
    }

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_EX, type, 200, sim));

    if (name && size > 0)
    {
        mmi_wcsncpy(name, src_name, size - 1);
    }

    return mmi_wcslen(src_name);
}


/* For the detail information, please refer to the NwNameSrvGprot.h */
S32 srv_nw_name_get_name(mmi_sim_enum sim, WCHAR *name, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_BEGIN, sim));

    len = srv_nw_name_get_name_by_priority(sim, name, size, MMI_TRUE);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_END, sim));

    return len;
}


/* For the detail information, please refer to the NwNameSrvGprot.h */
S32 srv_nw_name_get_name_if_any(mmi_sim_enum sim, WCHAR *name, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_IF_ANY_BEGIN, sim));

    len = srv_nw_name_get_name_by_priority(sim, name, size, MMI_FALSE);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NAME_IF_ANY_END, sim));

    return len;
}


/* For the detail information, please refer to the NwNameSrvGprot.h */
S32 srv_nw_name_get_spn(mmi_sim_enum sim, WCHAR *name, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx || !srv_nw_name_is_ready(sim) ||
        !srv_nw_name_is_spn_required(sim))
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_SPN_ERR,
                        srv_nw_name_is_spn_required(sim), sim));
        return 0;
    }

    if (name && size > 0)
    {
        mmi_wcsncpy(name, cntx->spn, size - 1);
    }

    return mmi_wcslen(cntx->spn);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_sim_unavailable_string
 * DESCRIPTION
 *  This function gets the string for the unavailable SIM.
 * PARAMETERS
 *  sim             : [IN]          SIM ID
 * RETURNS
 *  String ID.
 *****************************************************************************/
static U16 srv_nw_name_get_sim_unavailable_string(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_ua_cause_enum cause;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(sim))
    {
        cause = srv_sim_ctrl_get_unavailable_cause(sim);

        switch (cause)
        {
            case SRV_SIM_CTRL_UA_CAUSE_INITIALIZING:
                str_id = STR_ID_NWNAME_PREPAREING_SIM_CARD;
                break;

            case SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE:
                str_id = STR_ID_NWNAME_SIM_ACCESS_PROFILE;
                break;

            case SRV_SIM_CTRL_UA_CAUSE_DISCONNECTED:
                str_id = STR_ID_NWNAME_SIM_DISCONNECTED;
                break;

            case SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR:
                str_id = STR_ID_NWNAME_SIM_ACCESS_ERROR;
                break;

            case SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED:
            case SRV_SIM_CTRL_UA_CAUSE_PERSON_BLOCKED:
                str_id = STR_ID_NWNAME_SIM_BLOCKED;
                break;

            case SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED:
            case SRV_SIM_CTRL_UA_CAUSE_RECOVERY:
                str_id = STR_ID_NWNAME_INSERT_SIM;
                break;

            default:
                str_id = 0;
                break;
        }
    }

    return str_id;
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_is_sim_closed
 * DESCRIPTION
 *  This function checks if the SIM is closed. Note that flight mode means both
 *  SIM are closed.
 * PARAMETERS
 *  sim             : [IN]          SIM ID.
 * RETURNS
 *  On closed, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_is_sim_closed(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // initial value to solve build warning
    srv_mode_switch_type_enum  status = SRV_MODE_SWITCH_ALL_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sim)
    {
        case MMI_SIM1:
            status = SRV_MODE_SWITCH_SIM1;
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            status = SRV_MODE_SWITCH_SIM2;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            status = SRV_MODE_SWITCH_SIM3;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            status = SRV_MODE_SWITCH_SIM4;
            break;
    #endif
    }
    return ((srv_mode_switch_get_current_mode() & status) == status) ? MMI_FALSE : MMI_TRUE;
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */



#if defined(__MTK_TARGET__)
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_invalid_imei_string
 * DESCRIPTION
 *  This function gets the string when the handset IMEI is invalid.
 * PARAMETERS
 *  sim                 : [IN]              SIM ID
 *  service_indication  : [OUT]             srv_nw_name_service_indication_struct
 * RETURNS
 *  On invalid IMEI, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_get_invalid_imei_string(
    mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_imei_is_valid(sim))
    {
        mmi_wcsncpy(
            service_indication->line1,
            (const WCHAR *)get_string(STR_ID_NWNAME_INVALID_IMEI),
            SRV_NW_NAME_MAX_STR_LEN);

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_same_imei_string
 * DESCRIPTION
 *  This function gets the string when the handset has the same IMEI for
 *  SIM 1 and SIM 2.
 * PARAMETERS
 *  sim                 : [IN]              SIM ID
 *  service_indication  : [OUT]             srv_nw_name_service_indication_struct
 * RETURNS
 *  On same IMEI, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_get_same_imei_string(
    mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_imei_same_config_on_any_pair(sim))
    {
        mmi_wcsncpy(
            service_indication->line1,
            (const WCHAR *)get_string(STR_ID_NWNAME_SAME_IMEI),
            SRV_NW_NAME_MAX_STR_LEN);

        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* defined(__MTK_TARGET__) */

#ifdef __VSIM__
/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_handle_vsim_string
 * DESCRIPTION
 *  This function is used to determine whether VISM string is needed.
 * PARAMETERS
 *  sim                 : [IN]              SIM ID
 *  service_indication  : [OUT]             srv_nw_name_service_indication_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_handle_vsim_string(mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication)
{
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    if (cntx->is_vsim_on)
    {
        kal_wsprintf(service_indication->line2, "Virtual SIM ON");
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_searching_string
 * DESCRIPTION
 *  This function gets the service string in the searching situation.
 * PARAMETERS
 *  sim                 : [IN]              SIM ID
 *  service_indication  : [OUT]             srv_nw_name_service_indication_struct
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_get_searching_string(
    mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_wcsncpy(
        service_indication->line1,
        (const WCHAR *)get_string(STR_GLOBAL_SEARCHING),
        SRV_NW_NAME_MAX_STR_LEN);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_no_service_string
 * DESCRIPTION
 *  This function gets the service string in the no-service situation.
 * PARAMETERS
 *  sim                 : [IN]              SIM ID
 *  service_indication  : [OUT]             srv_nw_name_service_indication_struct
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_get_no_service_string(
    mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // [MAUI_02954200]: 
    // BT can access sim card in SIM Closed state,
    // so it needs to show "SIM ACCESS PROFILE" instead of SIM Closed
    if(!srv_sim_ctrl_is_available(sim) && 
        srv_sim_ctrl_get_unavailable_cause(sim) == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE)
    {
        str_id = STR_ID_NWNAME_SIM_ACCESS_PROFILE;
    }
    else
#if defined(__FLIGHT_MODE_SUPPORT__)
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        str_id = STR_ID_NWNAME_FLIGHT_MODE;
    }
    else
#endif /* defined(__FLIGHT_MODE_SUPPORT__) */
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_sim_ctrl_is_inserted(sim) && srv_nw_name_is_sim_closed(sim))
    {
        str_id = STR_ID_NWNAME_SIM_CLOSED;
    }
    else
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    if (!srv_sim_ctrl_is_available(sim))
    {
        str_id = srv_nw_name_get_sim_unavailable_string(sim);
    }

    /* If there is no special cause, use the default string. */
    if (!str_id)
    {
        str_id = STR_ID_NWNAME_NO_SERVICE;
    }

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_NO_SERVICE_STRING, 200, sim));
    mmi_wcsncpy(
        service_indication->line1,
        (const WCHAR *)get_string(str_id),
        SRV_NW_NAME_MAX_STR_LEN);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_limited_service_string
 * DESCRIPTION
 *  This function gets the service string in the limited-service situation.
 * PARAMETERS
 *  sim                 : [IN]              SIM ID
 *  service_indication  : [OUT]             srv_nw_name_service_indication_struct
 * RETURNS
 *  On success, return MMI_TRUE; otherwies, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_get_limited_service_string(
    mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(sim))
    {
        str_id = srv_nw_name_get_sim_unavailable_string(sim);
    }
    else if (srv_nw_info_sim_is_rejected(sim))
    {
        str_id = STR_ID_NWNAME_INVALID_SIM;
    }
    else if (srv_netset_get_nw_selection_mode(sim) == SRV_NETSET_MANUAL_SEL)
    {
        str_id = STR_ID_NWNAME_SELECT_NETWORK;
    }

    /* If there is no special cause, use the default string. */
    if (!str_id)
    {
        str_id = STR_ID_NWNAME_LIMITED_SERVICE;
    }

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_LIMITED_SERVICE_STRING, 200, sim));
    mmi_wcsncpy(
        service_indication->line1,
        (const WCHAR *)get_string(str_id),
        SRV_NW_NAME_MAX_STR_LEN);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_full_service_string
 * DESCRIPTION
 *  This function gets the service string in the full-service situation.
 * PARAMETERS
 *  sim                 : [IN]              SIM ID
 *  service_indication  : [OUT]             srv_nw_name_service_indication_struct
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_get_full_service_string(
    mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication,
    MMI_BOOL get_cache)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OP01_3G__
    if (get_cache)
    {
        mmi_wcscpy(service_indication->line1, cntx->srv_ind_cache.line1);
        mmi_wcscpy(service_indication->line2, cntx->srv_ind_cache.line2);
        return MMI_TRUE;
    }
#endif

    if (!srv_nw_name_is_ready(sim))
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_FULL_SERVICE_STRING, 500, sim));
        return MMI_FALSE; /* When it is ready, it will notify the APP. */
    }

    srv_nw_name_get_name(sim, service_indication->line1, SRV_NW_NAME_MAX_STR_LEN);
    srv_nw_name_get_spn(sim, service_indication->line2, SRV_NW_NAME_MAX_STR_LEN);

    /*
     * Fine-tune for the better UI display.
     *
     * If SPN is the same as network name, do not display SPN.
     */
    if (mmi_wcslen(service_indication->line2) > 0 &&
        mmi_wcscmp(service_indication->line1, service_indication->line2) == 0)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_FULL_SERVICE_STRING, 201, sim));
        kal_wsprintf(service_indication->line2, "");
    }

    /*
     * Fine tune for the better UI display.
     *
     * If network name is empty, set the SPN as the network name.
     */
    if (mmi_wcslen(service_indication->line1) == 0 &&
        mmi_wcslen(service_indication->line2) > 0)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_FULL_SERVICE_STRING, 202, sim));
        mmi_wcsncpy(
            service_indication->line1,
            service_indication->line2,
            SRV_NW_NAME_MAX_STR_LEN);

        kal_wsprintf(service_indication->line2, "");
    }

    /*
     * Fine tune for the better UI display.
     *
     * If the network name is still empty, get the name if anyone is present
     * and do not follow the rules of the spec.
     */
    if (mmi_wcslen(service_indication->line1) == 0)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_FULL_SERVICE_STRING, 203, sim));
        srv_nw_name_get_name_if_any(
            sim,
            service_indication->line1,
            SRV_NW_NAME_MAX_STR_LEN);
    }

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_GET_FULL_SERVICE_STRING, 200, sim));

    // for OP01 signal change from 3G to 2G
#ifdef __OP01_3G__
    mmi_wcscpy(cntx->srv_ind_cache.line1, service_indication->line1);
    mmi_wcscpy(cntx->srv_ind_cache.line2, service_indication->line2);
#endif
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_get_service_indication_string
 * DESCRIPTION
 *  This function gets the service indication string of the specified SIM in the idle.
 * PARAMETERS
 *  sim                 : [IN]              SIM ID
 *  service_indication  : [OUT]             srv_nw_name_service_indication_struct
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nw_name_get_service_indication_string(
    mmi_sim_enum sim,
    srv_nw_name_service_indication_struct *service_indication)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_enum service_availability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(service_indication->line1, "");
    kal_wsprintf(service_indication->line2, "");

#if defined(__MTK_TARGET__)
    /*
     * Invalid IMEI.
     */
    if (srv_nw_name_get_invalid_imei_string(sim, service_indication))
    {
    #ifdef __VSIM__
        srv_nw_name_handle_vsim_string(sim, service_indication);
    #endif
    
        return;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    /*
     * Same IMEI. (The handset uses the same IMEI for SIM 1 and SIM 2.)
     */
    if (srv_nw_name_get_same_imei_string(sim, service_indication))
    {
    #ifdef __VSIM__
        srv_nw_name_handle_vsim_string(sim, service_indication);
    #endif

        return;
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* defined(__MTK_TARGET__) */

    if (!srv_sim_ctrl_is_available(sim))
    {
        srv_nw_name_get_no_service_string(sim, service_indication);
    #ifdef __VSIM__
        srv_nw_name_handle_vsim_string(sim, service_indication);
    #endif
    
        return;
    }

    /*
     * Network availablity.
     */
    service_availability = srv_nw_info_get_service_availability(sim);

    switch (service_availability)
    {
        case SRV_NW_INFO_SA_SEARCHING:
        #ifdef __OP01_3G__
            if (srv_nw_info_is_need_display_fake_nw_status(sim) == MMI_TRUE)
            {
                srv_nw_name_get_full_service_string(sim, service_indication, MMI_TRUE);
            }
            else
        #endif
            {
                srv_nw_name_get_searching_string(sim, service_indication);
            }
            break;

        case SRV_NW_INFO_SA_NO_SERVICE:
            srv_nw_name_get_no_service_string(sim, service_indication);
            break;

        case SRV_NW_INFO_SA_LIMITED_SERVICE:
        #ifdef __OP01_3G__
            if (srv_nw_info_is_need_display_fake_nw_status(sim) == MMI_TRUE)
            {
                srv_nw_name_get_full_service_string(sim, service_indication, MMI_TRUE);
            }
            else
        #endif
            {
                srv_nw_name_get_limited_service_string(sim, service_indication);
            }
            break;

        case SRV_NW_INFO_SA_FULL_SERVICE:
            srv_nw_name_get_full_service_string(sim, service_indication, MMI_FALSE);
            break;

        default:
            break;
    }

#ifdef __VSIM__
    srv_nw_name_handle_vsim_string(sim, service_indication);
#endif
}
