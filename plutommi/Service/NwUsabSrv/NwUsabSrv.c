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
 *  NwUsabSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Service to wrap network usability information.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "NwUsabSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NetSetSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
/* auto add by kw_check end */


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    SRV_NW_USAB_STATE_INVALID = 0,
    SRV_NW_USAB_STATE_TRUE,
    SRV_NW_USAB_STATE_FALSE,

    SRV_NW_USAB_STATE_END_OF_ENUM
} srv_nw_usab_state_enum;

typedef struct
{
    srv_nw_usab_state_enum state[MMI_SIM_TOTAL];
} srv_nw_usab_cntx_struct;


/****************************************************************************
 * Global variable
 ****************************************************************************/

static srv_nw_usab_cntx_struct g_nw_usab_cntx =
{
    /* Zero init */
    { SRV_NW_USAB_STATE_INVALID }
}; 


/****************************************************************************
 * Functions
 ****************************************************************************/

#define srv_nw_usab_to_state(bool_v) \
    ( (bool_v) ? SRV_NW_USAB_STATE_TRUE : SRV_NW_USAB_STATE_FALSE )


/*****************************************************************************
 * FUNCTION
 *  srv_nw_usab_is_usable_int
 * DESCRIPTION
 *  Given a SIM and mode, determine the usability.
 * PARAMETERS
 *  sim     [IN] SIM ID
 *  mode    [IN] Mode
 * RETURNS
 *  Usability
 *****************************************************************************/
static MMI_BOOL srv_nw_usab_is_usable_int(mmi_sim_enum sim, srv_mode_switch_type_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL usable;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    usable = MMI_FALSE;

    if (srv_sim_ctrl_is_available(sim) == MMI_TRUE && (mode & sim) != 0)
    {
        usable = MMI_TRUE;
    }

    return usable;
}


/*****************************************************************************
 * Refer to NwUsabSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_usab_is_usable(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_nw_usab_is_usable_int(sim, srv_mode_switch_get_current_mode());
}


/*****************************************************************************
 * Refer to NwUsabSrvGprot.h
 *****************************************************************************/
mmi_sim_enum srv_nw_usab_get_one_usable_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_sim_enum usable_sim;
    srv_mode_switch_type_enum curr_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    usable_sim = MMI_SIM_NONE;
    curr_mode = srv_mode_switch_get_current_mode();
    
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_nw_usab_is_usable_int(mmi_frm_index_to_sim(i), curr_mode))
        {
            usable_sim = mmi_frm_index_to_sim(i);
            break;
        }
    }

    return usable_sim;
}


/*****************************************************************************
 * Refer to NwUsabSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_nw_usab_is_any_network_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If in flight mode, there is no any network vailable. */
    if (!srv_mode_switch_is_network_service_available())
    {
        return MMI_FALSE;
    }

    /* On WLAN project, if WLAN is not GSM only, network is always available. */
#ifdef __MMI_WLAN_FEATURES__
    if (srv_netset_get_pref_mode() != SRV_NETSET_PREF_MODE_GSM_ONLY)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    /* Then, check the SIM service usablility */
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_usab_get_one_usable_sim() != MMI_SIM_NONE)
    {
        return MMI_TRUE;
    }
#else
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {
        return MMI_TRUE;
    }
#endif

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_usab_on_mode_switch_finished
 * DESCRIPTION
 *  Subscribe the change of mode, emit usability change event.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_nw_usab_on_mode_switch_finished(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL usable;
    srv_nw_usab_state_enum usab_state;
    srv_nw_usab_changed_evt_struct changed_evt;
    srv_mode_switch_type_enum curr_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_mode = srv_mode_switch_get_current_mode();
    
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        usable = srv_nw_usab_is_usable_int(mmi_frm_index_to_sim(i), curr_mode);
        usab_state = srv_nw_usab_to_state(usable);
        
        if (usab_state != g_nw_usab_cntx.state[i])
        {
            /* Emit event only if usability changed */
            g_nw_usab_cntx.state[i] = usab_state;

            MMI_FRM_INIT_EVENT(&changed_evt, EVT_ID_SRV_NW_USAB_CHANGED);
            changed_evt.sim = mmi_frm_index_to_sim(i);
            changed_evt.is_usable = usable;
            MMI_FRM_CB_EMIT_POST_EVENT(&changed_evt);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_usab_on_sim_availability_changed
 * DESCRIPTION
 *  Subscribe the change of SIM availability, emit usability change event.
 * PARAMETERS
 *  evt     [IN] srv_sim_ctrl_availability_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_nw_usab_on_sim_availability_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *avai_evt;
    srv_nw_usab_changed_evt_struct changed_evt;
    MMI_BOOL usable;
    srv_nw_usab_state_enum usab_state;
    S32 sim_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avai_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;

    usable = srv_nw_usab_is_usable_int(avai_evt->sim, srv_mode_switch_get_current_mode());
    usab_state = srv_nw_usab_to_state(usable);
    sim_index = mmi_frm_sim_to_index(avai_evt->sim); // Gemini+
    if (usab_state != g_nw_usab_cntx.state[sim_index])
    {
        /* Emit event only if usability changed */
        g_nw_usab_cntx.state[sim_index] = usab_state;

        if (srv_bootup_is_completed())
        {
            /*
             * SIM_AVAILABILITY_CHANGED will always be emitted on BEFORE_IDLE.
             * This event is not used for initialization, so not need to
             * emit during booting to reduce the overhead of BEFORE_IDLE.
             */
            MMI_FRM_INIT_EVENT(&changed_evt, EVT_ID_SRV_NW_USAB_CHANGED);
            changed_evt.sim = avai_evt->sim;
            changed_evt.is_usable = usable;
            MMI_FRM_CB_EMIT_POST_EVENT(&changed_evt);
        }
    }

    return MMI_RET_OK;
}

