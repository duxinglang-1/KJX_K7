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
 *  vapp_nw_info_signal_custom.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Customized signal icon of network information for __OP02__
 *
 *	Rule.1 Empty slot will show Red X.
 *	Rule.2 Non-empty slot will show signal grid 0 under mode-switch off / no service / limited service 
 *	Rule.3 Non-empty slot will show signal grid under full service
 *	Rule.4 Non-empty slot will keep the previous grid under searching.
 *	Rule.5 Don't support sim hotswap
 * -------
 *  Wen Wu (MTK54103)
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

#ifdef VAPP_CUSTOM_SIGNAL

/****************************************************************************
 * Icon configuration
 ****************************************************************************/

static const vapp_nw_info_signal_image_config_struct VAPP_NW_INFO_SIGNAL_CUST_IMAGE_CONFIG[MMI_SIM_TOTAL] = 
{
#if (MMI_MAX_SIM_NUM == 1)
    { STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH, IMG_SI_SIGNAL_NO_SIM},
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
	return &VAPP_NW_INFO_SIGNAL_CUST_IMAGE_CONFIG[sim];
}

#if (MMI_MAX_SIM_NUM >= 2)

static void vapp_nw_info_signal_set_image(void)
{  
    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        const vapp_nw_info_signal_image_config_struct *image_config = vapp_nw_info_signal_get_icon_cfg(i);
		
        if (srv_sim_ctrl_is_inserted(sim))
        {
            wgui_status_icon_bar_change_icon_image(image_config->iconID, image_config->normalImage);
        }
        else
        {
            wgui_status_icon_bar_change_icon_image(image_config->iconID, image_config->closedImage);
        }
    }
    
}
#endif // MMI_MAX_SIM_NUM 


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
		case SRV_NW_INFO_SA_LIMITED_SERVICE:
			strength_in_percentage = 0;
            break;

        case SRV_NW_INFO_SA_FULL_SERVICE:
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
        service_availability != SRV_NW_INFO_SA_SEARCHING &&
        service_availability != SRV_NW_INFO_SA_LIMITED_SERVICE)
    {
        vapp_nw_info_signal_set_icon(strength_evt->sim, strength_evt->new_percentage);
    }
    else
    {
        /*
         * The strength icon will be updated from NO_SERVICE/SEARCHING to
         * FULL/LIMITED_SERVICE by mmi_nw_info_signal_on_service_avai_changed()
         */
    }

    return MMI_RET_OK;
}


extern "C"
mmi_ret vapp_nw_info_signal_on_sim_slot_ready(mmi_event_struct *evt)
{
#if (MMI_MAX_SIM_NUM >= 2)
    srv_bootup_sim_slot_ready_evt_struct *slot_ready_evt = (srv_bootup_sim_slot_ready_evt_struct*)evt;

    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
		const vapp_nw_info_signal_image_config_struct *image_config = vapp_nw_info_signal_get_icon_cfg(i);

		// Rule .1
        if (slot_ready_evt->inserted_sims & sim)
        {
            wgui_status_icon_bar_change_icon_image(image_config->iconID, image_config->normalImage);
        }
		else
		{
			wgui_status_icon_bar_change_icon_image(image_config->iconID, image_config->closedImage);
		}
		
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
            srv_nw_info_service_availability_enum service_availability = srv_nw_info_get_service_availability(sim);
            
            if (service_availability != SRV_NW_INFO_SA_NO_SERVICE &&
                service_availability != SRV_NW_INFO_SA_SEARCHING &&
                service_availability != SRV_NW_INFO_SA_LIMITED_SERVICE)
            {
                VfxS32 strength;

				if (srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_ON)
				{
                	strength = srv_nw_info_get_signal_strength_in_percentage(sim);
				}
				else
				{
					strength = 0;
				}
				
                vapp_nw_info_signal_set_icon(sim, strength);
            }
			

            const vapp_nw_info_signal_image_config_struct *image_config = vapp_nw_info_signal_get_icon_cfg(i);
            wgui_status_icon_bar_set_icon_display(image_config->iconID);
        }
		
    }
	else
	{
		vapp_nw_info_signal_hide_icon();
	}

    return MMI_RET_OK;
}

#endif /* VAPP_CUSTOM_SIGNAL */

