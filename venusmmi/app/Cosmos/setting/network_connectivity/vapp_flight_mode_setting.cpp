/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_flight_mode_setting.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_flight_mode_setting.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vapp_network_checking.h"
extern "C"
{
#include "ModeSwitchSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "Wgui_categories_util.h"
#include "Nvram_data_items.h"
#include "L4c_common_enum.h"
#include "Gui_typedef.h"
#include "UcmSrvGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
VfxBool VappFlightModeSettingCell::m_cellIsAvailable = VFX_FALSE;
VappFlightModeSettingCell *VappFlightModeSettingCell::m_cell = NULL;
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
void vapp_flight_mode_update_icon()
{
    if(!srv_mode_switch_is_network_service_available())
    {
        wgui_status_icon_bar_show_icon(STATUS_ICON_FLIGHT_MODE);
    }
    else
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_FLIGHT_MODE);
    }
}
extern "C"
{
mmi_ret vapp_flight_mode_setting_init(mmi_event_struct *evt)
{
    vapp_flight_mode_update_icon();
    return MMI_RET_OK;
}

mmi_ret vapp_flight_mode_switch_finish_hdlr(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY)
    {
        if (!VappFlightModeSettingCell::isCellAvailable())
    	{
    	    vapp_flight_mode_update_icon();
    	    return MMI_RET_OK;
    	}
        VappFlightModeSettingCell *settingCell = VappFlightModeSettingCell::getCell();
        if (settingCell)
    	{
      	    settingCell->setFlightModeStatus(srv_mode_switch_is_network_service_available() == MMI_TRUE ? VFX_FALSE : VFX_TRUE);
    	}
    }
    #ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__    
    {
        srv_mode_switch_notify_struct *notify_evt = (srv_mode_switch_notify_struct*)evt;
        if (notify_evt->curr_flight_mode != notify_evt->select_flight_mode
            && notify_evt->select_flight_mode == SRV_MODE_SWITCH_OFF)
    	{
            VappNetworkCheckingController *networkCheckingController = VFX_OBJ_GET_INSTANCE(VappNetworkCheckingController);
            networkCheckingController->enableNetworkCheckingforAllSim();
    	}
    }
    #endif /* __MMI_DUAL_SIM_DYNAMIC_MODE__ */
    vapp_flight_mode_update_icon();
    return MMI_RET_OK;
}
}
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappFlightModeSettingCell
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"

VFX_IMPLEMENT_CLASS("VappFlightModeSettingCell", VappFlightModeSettingCell, VcpFormItemSwitchCell);
void VappFlightModeSettingCell::onInit()
{
	VcpFormItemSwitchCell::onInit();

    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_FLIGHT_MODE));
    m_signalSwitchChangeReq.connect(this, &VappFlightModeSettingCell::onSwitch);
    m_status = (VfxBool)!srv_mode_switch_is_network_service_available();
    setSwitchStatus(m_status);

    m_cellIsAvailable = VFX_TRUE;
    m_cell = this;
    setIsTappable(VFX_FALSE);
    if (srv_mode_switch_is_switching())
    {
        showProcessInd();
        m_status = !m_status;
    }
}

void VappFlightModeSettingCell::onDeinit()
{
    VcpFormItemSwitchCell::onDeinit();
    m_cellIsAvailable = VFX_FALSE;
    m_cell = NULL;
}

void VappFlightModeSettingCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status)
{
    if (srv_ucm_is_any_call())
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
	    return;
    }
    showProcessInd();
    if (m_status != status)
	{
		m_status = status;
        srv_mode_switch_switch_flight_mode( 
            ((status == VFX_TRUE) ? MMI_TRUE : MMI_FALSE),
            MMI_TRUE, 
            &VappFlightModeSettingCell::updateCellProc, 
            this);
	}
}

void VappFlightModeSettingCell::setFlightModeStatus(VfxBool isFlightModeOn)
{
    m_status = isFlightModeOn;
    setSwitchStatus(m_status);
}

mmi_ret VappFlightModeSettingCell::updateCellProc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
#pragma arm section code, rodata

 
