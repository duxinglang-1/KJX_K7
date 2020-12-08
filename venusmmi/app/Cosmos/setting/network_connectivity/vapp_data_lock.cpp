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
 *  Vapp_data_lock.cpp
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
#include "mmi_rp_vapp_setting_def.h"
#include "vapp_setting_data_lock_gprot.h"
#include "Vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"
extern "C"
{
#ifdef __MMI_DATA_LOCK__
#include "DataLockSrvGprot.h"
#endif /* __MMI_DATA_LOCK__ */
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
#include "PushSwitchSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#endif
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
void vapp_setting_push_switch_on_confirm_popup_clicked(VfxId id, void *userData)
{
    if (id == 'USR2')
	{
	    srv_push_switch_set_mode(SRV_PUSH_SWITCH_MODE_OFF);
	}
    else
    {
        srv_push_switch_set_mode(SRV_PUSH_SWITCH_MODE_ON);
    }
}

extern "C"
{
mmi_ret vapp_push_switch_notify_hdlr(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_PUSH_SWITCH_NOTIFY)
	{
	    // TODO: replace the API with nmgr global popup
	    vapp_nmgr_global_popup_show_confirm_two_button_id(
	        MMI_SCENARIO_ID_DEFAULT,
            VCP_POPUP_TYPE_WARNING, 
            STR_ID_VAPP_SETTING_PUSH_LOCK_QUERY,
            STR_GLOBAL_YES,
            STR_GLOBAL_NO,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL,
            &vapp_setting_push_switch_on_confirm_popup_clicked,
            NULL);
	}
	return MMI_RET_OK;
}
}
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappSettingPushLockSwitchCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingPushLockSwitchCell", VappSettingPushLockSwitchCell, VcpFormItemSwitchCell); 
void VappSettingPushLockSwitchCell::onInit()
{
    VcpFormItemSwitchCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_PUSH_LOCK);
    if (srv_push_switch_get_mode() == SRV_PUSH_SWITCH_MODE_OFF)
    {
        m_status = VFX_FALSE;
    }
    else
    {
        m_status = VFX_TRUE;
    }
    if (srv_mode_switch_is_network_service_available())
    {
        setSwitchStatus(m_status);
    }
    else
    {
        setSwitchStatus(VFX_FALSE); 
        setIsDisabled(VFX_TRUE);
    }

    m_signalSwitchChangeReq.connect(this, &VappSettingPushLockSwitchCell::onSwitch);

    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappSettingPushLockSwitchCell::flightModeSwitchHdlr, this);
}

void VappSettingPushLockSwitchCell::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappSettingPushLockSwitchCell::flightModeSwitchHdlr, this);
    VcpFormItemSwitchCell::onDeinit();
}

VfxBool VappSettingPushLockSwitchCell::getStatus() const
{
    return m_status;
}
mmi_ret VappSettingPushLockSwitchCell::flightModeSwitchHdlr(mmi_event_struct *evt)
{
    VappSettingPushLockSwitchCell *cell = VFX_OBJ_DYNAMIC_CAST(((VfxObject*)evt->user_data), VappSettingPushLockSwitchCell);
    if (NULL == cell)
    {
        return MMI_RET_OK;
    }
    
    if (!srv_mode_switch_is_network_service_available())
    {
        cell->setSwitchStatus(VFX_FALSE);
        cell->setIsDisabled(VFX_TRUE);
    }
    else
    {
        cell->setSwitchStatus(cell->getStatus());
        cell->setIsDisabled(VFX_FALSE);        
    }
    
    return MMI_RET_OK;
}

void VappSettingPushLockSwitchCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status)
{
    if (!srv_push_switch_check_service_ready())
	{
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_WARNING, 
            VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
        return;
	}
    m_status = status;
    srv_push_switch_set_mode(m_status ? SRV_PUSH_SWITCH_MODE_ON : SRV_PUSH_SWITCH_MODE_OFF);
    setSwitchStatus(m_status);
}
#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */
#ifdef __MMI_DATA_LOCK__
/***************************************************************************** 
 * VappSettingDataLockSwitchCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingDataLockSwitchCell", VappSettingDataLockSwitchCell, VcpFormItemSwitchCell);
void VappSettingDataLockSwitchCell::onInit()
{
    VcpFormItemSwitchCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_DATA_LOCK);
    setSwitchStatus(srv_data_lock_get_setting());
    m_signalSwitchChangeReq.connect(this, &VappSettingDataLockSwitchCell::onSwitch);
}

void VappSettingDataLockSwitchCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status)
{
    srv_data_lock_set_setting((MMI_BOOL)status);
    setSwitchStatus(status);
}

/***************************************************************************** 
 * VappSettingNetworkRoamingSwitchCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingNetworkRoamingSwitchCell", VappSettingNetworkRoamingSwitchCell, VcpFormItemSwitchCell);
void VappSettingNetworkRoamingSwitchCell::onInit()
{
    VcpFormItemSwitchCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_NETWORK_ROAMING);
    setSwitchStatus(srv_data_lock_network_roaming_get_setting());
    m_signalSwitchChangeReq.connect(this, &VappSettingNetworkRoamingSwitchCell::onSwitch);

    updateCell();

    mmi_frm_cb_reg_event(EVT_ID_SRV_DATA_LOCK_UPDATE, &VappSettingNetworkRoamingSwitchCell::onProc, this);
}

void VappSettingNetworkRoamingSwitchCell::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DATA_LOCK_UPDATE, &VappSettingNetworkRoamingSwitchCell::onProc, this);    
    VcpFormItemSwitchCell::onDeinit();
}

void VappSettingNetworkRoamingSwitchCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status)
{
    srv_data_lock_network_roaming_set_setting((MMI_BOOL)status);
    setSwitchStatus(status);
}

void VappSettingNetworkRoamingSwitchCell::updateCell()
{
    setIsDisabled(!srv_data_lock_get_setting());
    if (srv_data_lock_get_setting() == MMI_FALSE)
    {
        setSwitchStatus(VFX_FALSE);
    }
    else
    {
        setSwitchStatus(srv_data_lock_network_roaming_get_setting() == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
    }
}

mmi_ret VappSettingNetworkRoamingSwitchCell::onProc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_DATA_LOCK_UPDATE && evt->user_data)
	{
	    VappSettingNetworkRoamingSwitchCell *cell = VFX_OBJ_DYNAMIC_CAST((VfxObject*)evt->user_data, VappSettingNetworkRoamingSwitchCell);
        if (cell)
    	{
    	    cell->updateCell();
    	}
	}
    return MMI_RET_OK;
}
#endif /* __MMI_DATA_LOCK__ */
