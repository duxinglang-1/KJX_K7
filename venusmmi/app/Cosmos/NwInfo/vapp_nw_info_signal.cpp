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
 *  vapp_nw_info_signal.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Signal icon of network information
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
extern "C"
{
#include "NwInfoProt.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "NwInfoProt.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "MMIDataType.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "NwInfoSrvGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_utility_gprot.h"
#include "GlobalResDef.h"
#include "BootupSrvGprot.h"
}
#include "vfx_datatype.h"
#include "vapp_nw_info.h"


/****************************************************************************
 * Icon configuration
 ****************************************************************************/
#ifndef VAPP_CUSTOM_SIGNAL

static const vapp_nw_info_signal_image_config_struct VAPP_NW_INFO_SIGNAL_IMAGE_CONFIG[MMI_SIM_TOTAL] = 
{
#if (MMI_MAX_SIM_NUM == 1)
    { STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH },
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    { STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED },
    { STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED },
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    { STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_CLOSED },
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    { STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_CLOSED },
#endif
};


/****************************************************************************
 * Functions
 ****************************************************************************/
const vapp_nw_info_signal_image_config_struct *vapp_nw_info_signal_get_icon_cfg(VfxU32 sim)
{
	return &VAPP_NW_INFO_SIGNAL_IMAGE_CONFIG[sim];
}


#if (MMI_MAX_SIM_NUM >= 2)
static void vapp_nw_info_signal_set_image(void)
{
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        srv_mode_switch_type_enum mode = srv_mode_switch_get_current_mode();
        
        for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
        {
            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            const vapp_nw_info_signal_image_config_struct *image_config =
                &VAPP_NW_INFO_SIGNAL_IMAGE_CONFIG[i];
            if (mode & sim) // enabled
            {
                wgui_status_icon_bar_change_icon_image(image_config->iconID, image_config->normalImage);
            }
            else
            {
                wgui_status_icon_bar_change_icon_image(image_config->iconID, image_config->closedImage);
            }
        }
    }
    else
    {
        // Set the corresponding signal icon as same as single SIM
        mmi_sim_enum signal_sim = vapp_nw_info_get_one_inserted_sim(); 
        if (signal_sim == MMI_SIM_NONE)
        {
            // No SIM is inserted, show SIM1 signal icon
            signal_sim = MMI_SIM1;
        }
        const vapp_nw_info_signal_image_config_struct *image_config =
            &VAPP_NW_INFO_SIGNAL_IMAGE_CONFIG[mmi_frm_sim_to_index(signal_sim)];
        wgui_status_icon_bar_change_icon_image(image_config->iconID, IMG_SI_SIGNAL_STRENGTH);
    }
}
#endif // (MMI_MAX_SIM_NUM >= 2)


/*****************************************************************************
 * FUNCTION
 *  vapp_nw_info_signal_on_service_avai_changed
 * DESCRIPTION
 *  Handler for service availability chahnged.
 *  To update signal strength icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_service_availability_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
extern "C"
mmi_ret vapp_nw_info_signal_on_service_avai_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *availability_evt;
    VfxS32 strength_in_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED);
    
    availability_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;

    strength_in_percentage = 0;
    switch (availability_evt->new_status)
    {
        case SRV_NW_INFO_SA_NO_SERVICE:
            strength_in_percentage = 0;
            break;

        case SRV_NW_INFO_SA_FULL_SERVICE:
        case SRV_NW_INFO_SA_LIMITED_SERVICE:
            strength_in_percentage =
                srv_nw_info_get_signal_strength_in_percentage(availability_evt->sim);
            break;
            
        case SRV_NW_INFO_SA_SEARCHING:
            /* Don't change; go through to return */
        default:
            /* Ignore */
            return MMI_RET_OK;
    }

    vapp_nw_info_signal_set_icon(availability_evt->sim, strength_in_percentage);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_strength_changed
 * DESCRIPTION
 *  Handler for signal strength changed.
 *  Update signal strength icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_signal_strength_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
extern "C"
mmi_ret vapp_nw_info_signal_on_strength_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_signal_strength_changed_evt_struct *strength_evt;
    srv_nw_info_service_availability_enum service_availability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED);

    strength_evt = (srv_nw_info_signal_strength_changed_evt_struct*)evt;

    service_availability = srv_nw_info_get_service_availability(strength_evt->sim);
    if (service_availability != SRV_NW_INFO_SA_NO_SERVICE &&
        service_availability != SRV_NW_INFO_SA_SEARCHING)
    {
        vapp_nw_info_signal_set_icon(strength_evt->sim, strength_evt->new_percentage);
    }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    return MMI_RET_OK;
}


extern "C"
mmi_ret vapp_nw_info_signal_on_sim_slot_ready(mmi_event_struct *evt)
{
#if (MMI_MAX_SIM_NUM >= 2)
    srv_bootup_sim_slot_ready_evt_struct *slot_ready_evt =
        reinterpret_cast<srv_bootup_sim_slot_ready_evt_struct*>(evt);

    if (slot_ready_evt->n_inserted >= 2)
    {
        for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
        {
            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            if (slot_ready_evt->inserted_sims & sim)
            {
                const vapp_nw_info_signal_image_config_struct *image_config =
                    &VAPP_NW_INFO_SIGNAL_IMAGE_CONFIG[i];
                wgui_status_icon_bar_change_icon_image(image_config->iconID, image_config->closedImage);
                wgui_status_icon_bar_set_icon_display(image_config->iconID);
            }
        }
    }
    else
    {
        mmi_sim_enum signal_sim = static_cast<mmi_sim_enum>(slot_ready_evt->inserted_sims);
        if (signal_sim == MMI_SIM_NONE)
        {
            // No SIM is inserted, show SIM1 signal
            signal_sim = MMI_SIM1;
        }
        
        VfxS32 sim_index = mmi_frm_sim_to_index(signal_sim);
        const vapp_nw_info_signal_image_config_struct *image_config =
            &VAPP_NW_INFO_SIGNAL_IMAGE_CONFIG[sim_index];
            
        wgui_status_icon_bar_change_icon_image(image_config->iconID, IMG_SI_SIGNAL_STRENGTH);
        wgui_status_icon_bar_set_icon_display(image_config->iconID);
    }
    
#else // Single SIM project

    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIGNAL_STRENGTH);
    
#endif

    return MMI_RET_OK;
}


extern "C"
mmi_ret vapp_nw_info_signal_on_mode_decided(mmi_event_struct *evt)
{
#if (MMI_MAX_SIM_NUM >= 2)
    vapp_nw_info_signal_set_image();
#endif

	if (!srv_mode_switch_is_network_service_available())
	{
		vapp_nw_info_signal_hide_icon();
	}
	
    return MMI_RET_OK;
}


extern "C"
mmi_ret vapp_nw_info_signal_on_mode_switched(mmi_event_struct *evt)
{
    if (srv_mode_switch_is_network_service_available())
    {
#if (MMI_MAX_SIM_NUM >= 2)
        vapp_nw_info_signal_set_image();
#endif
    
        for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
        {
            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            srv_nw_info_service_availability_enum service_availability =
                srv_nw_info_get_service_availability(sim);
            
            if (srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_ON &&
                service_availability != SRV_NW_INFO_SA_NO_SERVICE &&
                service_availability != SRV_NW_INFO_SA_SEARCHING)
            {
                VfxS32 strength;

                strength = srv_nw_info_get_signal_strength_in_percentage(sim);
                vapp_nw_info_signal_set_icon(sim, strength);
            }

            const vapp_nw_info_signal_image_config_struct *image_config = &VAPP_NW_INFO_SIGNAL_IMAGE_CONFIG[i];

            // Normal mode, show all signal icons
            if (srv_sim_ctrl_is_inserted(sim))
            {

                wgui_status_icon_bar_set_icon_display(image_config->iconID);
            }
            else
            {
                wgui_status_icon_bar_hide_icon(image_config->iconID);
            }
        }

        if (srv_sim_ctrl_get_num_of_inserted() == 0)
        {
            const vapp_nw_info_signal_image_config_struct *image_config = &VAPP_NW_INFO_SIGNAL_IMAGE_CONFIG[0];
            wgui_status_icon_bar_set_icon_display(image_config->iconID);
        }
    }
	else
	{
		vapp_nw_info_signal_hide_icon();
	}

    return MMI_RET_OK;
}

#endif /*  VAPP_CUSTOM_SIGNAL */

/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_get_icon_id
 * DESCRIPTION
 *  Get signal strength icon ID of SIM.
 * PARAMETERS
 *  sim             [IN]  Which SIM
 *  mainlcd_icon_id [OUT] Icon ID of main LCD
 *  sublcd_icon_id  [OUT] Icon ID of sub LCD
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_nw_info_signal_get_icon_id(
                mmi_sim_enum sim,
                VfxS32 *mainlcd_icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim)
    {
        case MMI_SIM1:
            *mainlcd_icon_id = STATUS_ICON_SIGNAL_STRENGTH;
            break;
            
#if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            *mainlcd_icon_id = STATUS_ICON_SLAVE_SIGNAL_STRENGTH;
            break;
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            *mainlcd_icon_id = STATUS_ICON_SIM3_SIGNAL_STRENGTH;
            break;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            *mainlcd_icon_id = STATUS_ICON_SIM4_SIGNAL_STRENGTH;
            break;
#endif
        default:
            *mainlcd_icon_id = 0;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_set_icon
 * DESCRIPTION
 *  Set the icon of signal strength by given value
 * PARAMETERS
 *  sim                     [IN] Which SIM
 *  strength_in_percentage  [IN] Signal strength
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_nw_info_signal_set_icon(
                mmi_sim_enum sim,
                VfxS32 strength_in_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 mainlcd_icon_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mainlcd_icon_id = STATUS_ICON_INVALID_ID;
    
    vapp_nw_info_signal_get_icon_id(sim, &mainlcd_icon_id);

    MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_SIGNAL_ICON_CHANGED,
        sim, strength_in_percentage);
        
    wgui_status_icon_bar_change_icon_level(mainlcd_icon_id, strength_in_percentage);

    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  vapp_nw_info_signal_hide_icon
 * DESCRIPTION
 *  Hide signal icon at flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_nw_info_signal_hide_icon(void)
{
	for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
	{
		const vapp_nw_info_signal_image_config_struct *image_config = vapp_nw_info_signal_get_icon_cfg(i);
		
		wgui_status_icon_bar_hide_icon(image_config->iconID);
	}
}

