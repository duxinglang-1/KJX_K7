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
 *  vapp_dtcnt_wlan_settings.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "mmi_features.h"
#ifdef __MMI_WLAN_FEATURES__
#include "vcp_global_popup.h"
#include "vapp_dtcnt_wlan_settings.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappWiFiSwitchCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWiFiSwitchCell", VappWiFiSwitchCell, VcpFormItemSwitchCell);

VappWiFiSwitchCell::VappWiFiSwitchCell() :
    m_turnOffConfirm(NULL)
{
    m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    m_repository->setSettingSwitchCellInstance (this);
}

VappWiFiSwitchCell::~VappWiFiSwitchCell()
{
    m_repository->setSettingSwitchCellInstance (NULL);
}

void VappWiFiSwitchCell::onInit ()
{
    VcpFormItemSwitchCell::onInit();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_SWITCH, srv_dtcnt_wlan_switch_state());
    setIsTappable (VFX_FALSE);
    // Get current wifi status to decide the status of switch
/*    
    if(SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status ())
    {
        setSwitchStatus(VFX_FALSE);
    }
    else
    {
        setSwitchStatus(VFX_TRUE);
    }
 */
    switch(srv_dtcnt_wlan_switch_state())
    {
    case SRV_DTCNT_WLAN_SWITCH_STATE_OPEN:    
        setSwitchStatus(VFX_TRUE);
        break;
    case SRV_DTCNT_WLAN_SWITCH_STATE_OPENING:    
        setSwitchStatus(VFX_FALSE);
        // show processing icon
        showProcessInd();    
        break;
    case SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE:
        setSwitchStatus(VFX_FALSE);
        break;
    case SRV_DTCNT_WLAN_SWITCH_STATE_CLOSING:
        setSwitchStatus(VFX_TRUE);
        // show processing icon
        showProcessInd();  
        break;
    default:
        break;
    }
    
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_WLAN));
    m_signalSwitchChangeReq.connect(this, &VappWiFiSwitchCell::onSwitch);
    VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalStopTethering.connect(
		this, &VappWiFiSwitchCell::onStopWiFiTethering);

#ifndef __COSMOS_WLAN_IN_FLGHT_MODE__
    /* Disable setting cell when in flight mode */     
    MMI_BOOL switching = srv_mode_switch_is_switching ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_RSP, switching);
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE || switching == MMI_TRUE)
    {
        setIsDisabled (VFX_TRUE);
    }
    else
    {
        setIsDisabled (VFX_FALSE);
    }
#endif

	if(VFX_TRUE == m_repository->getIsWLANByOffTethering())
	{
        // show processing icon
        showProcessInd();
	}
}

void VappWiFiSwitchCell::onDeinit ()
{
    VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalStopTethering.disconnect(
		this, &VappWiFiSwitchCell::onStopWiFiTethering);

    VcpFormItemSwitchCell::onDeinit();
}

void VappWiFiSwitchCell::onSwitch (
        VcpFormItemSwitchCell* sender,  // Sender
        VfxId   senderId,               // Sender id
        VfxBool switchValue             // new switch value
    )
{
    VfxBool isTetheringOff;
    
    VFX_TRACE(("New switch value: %d\n", switchValue));
	
#ifdef __FLIGHT_MODE_SUPPORT__ 
    MMI_BOOL switching = srv_mode_switch_is_switching ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_RSP, switching);
    if(switching == MMI_TRUE)
    {
    	return;
    }
#endif

	// Not to change during switching wlan tethering
	if(VappWlanToolbox::isTetheringInSwitching ())
	{
		return;
	}
	
    // send init/deinit message to service
    if(switchValue == VFX_TRUE)
    {
        // If it's busy, then close it, send init event in the end
        isTetheringOff = ((MMI_TRUE == srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS))? VFX_TRUE: VFX_FALSE);
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SWITCH_TETHERING_QRY, isTetheringOff);
        if(VFX_FALSE == isTetheringOff)
        {
            // show confrim popup to turn off wifi tethering
            /* VappWiFiSwitchCell::m_confirmPopupGroupId = vcp_global_popup_show_confirm_two_button_id(
                            GRP_ID_ROOT,
                            VCP_POPUP_TYPE_QUESTION, 
                            STR_ID_VAPP_WLAN_TURN_OFF_HOT_SPOT, 
                            STR_GLOBAL_OK, 
                            STR_GLOBAL_CANCEL,
                            VCP_POPUP_BUTTON_TYPE_NORMAL,
                            VCP_POPUP_BUTTON_TYPE_CANCEL,
                            onConfirmBtnClicked,
                            NULL); */
            VFX_OBJ_CREATE (m_turnOffConfirm, VcpConfirmPopup, VfxMainScr::findMainScr(getParentFrame()));
            m_turnOffConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_turnOffConfirm->setCustomButton (
                VFX_WSTR_RES(STR_GLOBAL_OK), 
                VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_turnOffConfirm->setInfoType (VCP_POPUP_TYPE_QUESTION);
            m_turnOffConfirm->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_TURN_OFF_HOT_SPOT));
            m_turnOffConfirm->m_signalButtonClicked.connect (this, &VappWiFiSwitchCell::onConfirmBtnClicked);
            m_turnOffConfirm->setAutoDestory(VFX_TRUE);
            m_turnOffConfirm->show (VFX_TRUE);
        }
        else
        {
#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
			if(srv_mode_switch_is_network_service_available() == MMI_FALSE)
			{		
				showConfirmPopupInFlightMode();
			}
			else		
#endif	
			{
            	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_SWITCH_ING, srv_dtcnt_wlan_status ());
            	srv_dtcnt_wlan_init (NULL, NULL);
            	// show processing icon
            	showProcessInd();
			}
        }
    }
    else
    {
        // To do: Query current wifi tethering's status
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_SWITCH_ING, srv_dtcnt_wlan_status ());
#ifdef __MMI_OP01_WIFI__
		VappWlanCMCCMgr::entryCMCCDeinitProc ();
#else
		VappWlanSentry::SendDeinitRequest ();
#endif		
		// show processing icon
		showProcessInd();
    }
}

void VappWiFiSwitchCell::stopWiFiTetheringCallback(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
	VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SWITCH_TETHERING_CALLBACK);
    VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalStopTethering.postEmit(((MMI_TRUE ==result)? VFX_TRUE: VFX_FALSE));	
	if(MMI_TRUE == result)
    {   
    	// no need to showConfirmPopupInFlightMode,because user want to used wlan in flight mode.
    	// wifi tethering must judge this case.
        srv_dtcnt_wlan_init (NULL, NULL);
        // setSwitchStatus (VFX_TRUE);
    }
	repository->setIsWLANByOffTethering(VFX_FALSE);
}

void VappWiFiSwitchCell::onStopWiFiTethering(VfxBool result)
{    
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_SWITCH_ING, srv_dtcnt_wlan_status ());
    if(VFX_FALSE == result)
    {
        setSwitchStatus (VFX_FALSE);
    }
}

void VappWiFiSwitchCell::onConfirmBtnClicked(VfxObject* sender, VfxId id)
{
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SWITCH_TETHERING_CONFIRM_BY_SETTING);

    VfxBool isTetheringOff;
	isTetheringOff = ((MMI_TRUE == srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS))? VFX_TRUE: VFX_FALSE);
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SWITCH_TETHERING_QRY, isTetheringOff);
	if(VFX_TRUE == isTetheringOff)
    {
    	return;
	}
	// Not to change during switching wlan tethering
	if(VappWlanToolbox::isTetheringInSwitching ())
	{
		return;
	}

    switch(id)
    {
    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SWITCH_STOP_TETHERING);
        srv_tethering_stop (SRV_TETHERING_TYPE_WIFI_HS, stopWiFiTetheringCallback, NULL);
        // show processing icon
        showProcessInd();
		m_repository->setIsWLANByOffTethering(VFX_TRUE);
        break;
    case VCP_CONFIRM_POPUP_BUTTON_USER_2:
    case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
        setSwitchStatus (VFX_FALSE);
        break;
    default:
        break;
    }
}

#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__		
void VappWiFiSwitchCell::showConfirmPopupInFlightMode()
{
	VcpConfirmPopup *confirmPopup;
	VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, VfxMainScr::findMainScr(getParentFrame()));
	confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
	confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_IN_FLIGHT_MODE_ASK));
	confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	confirmPopup->setCustomButton(
					VFX_WSTR_RES(STR_ID_VAPP_WLAN_IN_FLIGHT_MODE_TURN_ON),
					VFX_WSTR_RES(STR_GLOBAL_CANCEL),
					VCP_POPUP_BUTTON_TYPE_NORMAL,
					VCP_POPUP_BUTTON_TYPE_CANCEL);		
	confirmPopup->setAutoDestory(VFX_TRUE);
	confirmPopup->m_signalButtonClicked.connect(this, &VappWiFiSwitchCell::onButtonClick);
	confirmPopup->show(VFX_TRUE);
}

void VappWiFiSwitchCell::onButtonClick(VfxObject* sender, VfxU32 id)
{
    VappWlanRepository* repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:			
        	srv_dtcnt_wlan_init (NULL, NULL);			
			showProcessInd();
            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:			
		case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
            break;
    }
}
#endif

/***************************************************************************** 
 * Class VappWiFiSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWiFiSettingCell", VappWiFiSettingCell, VcpFormItemLauncherCell);
VappWiFiSettingCell::VappWiFiSettingCell()
{
    m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    m_repository->setSettingCellInstance (this);
}

VappWiFiSettingCell::~VappWiFiSettingCell()
{
    m_repository->setSettingCellInstance (NULL);
}

void VappWiFiSettingCell::onInit ()
{
    VcpFormItemLauncherCell::onInit();
    
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_SETTING_MAIN_TEXT));
    setHintText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_SETTING_HINT_TEXT));
    setAccessory (VCPFORM_NEXT_ITEM_ICON);
    /* Disable setting cell when wifi is turned off */
    VFX_TRACE(("==============================================\n"));
    VFX_TRACE(("VappWiFiSettingCell WLAN status: %d\n", srv_dtcnt_wlan_status ()));
    VFX_TRACE(("==============================================\n"));
    m_signalTap.connect(this, &VappWiFiSettingCell::onTap);

#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__	
/*
	if(SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status ())
	{
		setIsDisabled (VFX_TRUE);
	}
	else
	{
		setIsDisabled (VFX_FALSE);
	}
 */
    switch(srv_dtcnt_wlan_switch_state())
    {
    case SRV_DTCNT_WLAN_SWITCH_STATE_OPEN:      
    case SRV_DTCNT_WLAN_SWITCH_STATE_CLOSING:
        setIsDisabled(VFX_FALSE);
        break;       
    case SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE:
    case SRV_DTCNT_WLAN_SWITCH_STATE_OPENING:    
        setIsDisabled(VFX_TRUE);  
        break;
    default:
        break;
    }
#else
    /* Disable setting cell when in flight mode */      
    MMI_BOOL switching = srv_mode_switch_is_switching ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_RSP, switching);
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE || switching == MMI_TRUE)
    {
        setIsDisabled (VFX_TRUE);
    }
    else
    {
        switch(srv_dtcnt_wlan_switch_state())
        {
        case SRV_DTCNT_WLAN_SWITCH_STATE_OPEN:      
        case SRV_DTCNT_WLAN_SWITCH_STATE_CLOSING:
            setIsDisabled(VFX_FALSE);
            break;       
        case SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE:
        case SRV_DTCNT_WLAN_SWITCH_STATE_OPENING:    
            setIsDisabled(VFX_TRUE);  
            break;
        default:
            break;
        }
    }
#endif
    
}

void VappWiFiSettingCell::onDeinit ()
{
    VcpFormItemLauncherCell::onDeinit();
}

void VappWiFiSettingCell::onTap (VcpFormItemCell* sender, VfxId senderId)
{
    // Not to change during switching wlan tethering
    if(VappWlanToolbox::isTetheringInSwitching ())
    {
        return;
    }
	
#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
	if(srv_mode_switch_is_switching ())
	{
		return;
	}
#else	
    // Not to change during switching flight mode
    if(VappWlanToolbox::isFlightModeOn ())
    {
        return;
    }
#endif

    // Launch WLAN setting CUI
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if(mainScr)
    {
        mmi_id vcuiId = NULL;
        vcuiId = vcui_dtcnt_wlan_setting_create(mainScr->getApp()->getGroupId(), NULL);
        vcui_dtcnt_wlan_setting_run(vcuiId);
    }
}
#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__

