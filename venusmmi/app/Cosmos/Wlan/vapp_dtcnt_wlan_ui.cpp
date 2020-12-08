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
 *  vapp_dtcnt_wlan_ui.cpp
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

#ifdef __MMI_OP01_WIFI__
#include "vapp_dtcnt_wlan_cmcc_ui.h"
#endif
#include "vapp_dtcnt_wlan_ui.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"

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
#ifdef __cplusplus
extern "C" {
#endif
MMI_ID vapp_dtcnt_wlan_launch(void* param, U32 param_size)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_LAUNCH_APP_START);
#ifndef __MTK_TARGET__
    VFX_TRACE(("===== CANNOT RUN WIFI APP IN MODIS  =====\n"));
    /* VappWlanSentry::showGlobalPopup (GRP_ID_ROOT, NULL, STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR);
    return GRP_ID_INVALID; */
#else 
// TODO: Add a popup not support
#endif  /* __MTK_TARGET__ */

    // Get current wifi status 
    srv_dtcnt_wlan_state_enum wifiStatus = srv_dtcnt_wlan_state();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_LAUNCH_APP_STATUS, wifiStatus);

    if(VappWlanToolbox::isTetheringInSwitching ())
    {
        return GRP_ID_INVALID;
    }
    
    if(VappWlanToolbox::isFlightModeOn ())
    {
        return GRP_ID_INVALID;
    }
    
    // Launch WLAN application
    MMI_ID  appId = 0;
    VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);

    appId = VfxAppLauncher::launch( 
                VAPP_DATA_ACCOUNT_WLAN,
                VFX_OBJ_CLASS_INFO(VappDtcntWlan),
                GRP_ID_ROOT);

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_LAUNCH_APP_END, appId);

    return appId;
}

VfxApp* vapp_dtcnt_wlan_find_app(void)
{
    return VfxAppLauncher::findApp(
                VAPP_DATA_ACCOUNT_WLAN, 
                VFX_OBJ_CLASS_INFO(VappDtcntWlan), 
                VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 
                0);        
}

#ifdef __cplusplus
}
#endif


VFX_IMPLEMENT_CLASS ("VappDtcntWlan", VappDtcntWlan, VfxApp);

void VappDtcntWlan::onInit ()
{
    VfxApp::onInit ();

    // Connect siganl to judge whether wifi tethering is turned off or not
    VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalStopTethering.connect (
        this, &VappDtcntWlan::onTryToStopTethering);
	
#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__		
    // Connect siganl to judge whether wifi can open in flight mode
    VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalOpenWLANInFlightMode.connect (
        this, &VappDtcntWlan::onTryToOpenWLANInFlightMode);
#endif

    VFX_TRACE(("===== Application Initialization =====\n"));
}

void VappDtcntWlan::onRun (void * arg, VfxU32 argSize)
{
    VfxApp::onRun (arg, argSize);

    MMI_BOOL isTetheringOff;
    isTetheringOff = srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SWITCH_TETHERING_QRY, isTetheringOff);  
    
    if(MMI_FALSE == isTetheringOff)
    {
        // Create small screen
        // Put turn off tethering popup into it
        VFX_OBJ_CREATE (m_entryScrn, VappWlanEntryScrn, this);
        m_entryScrnId = m_entryScrn->show ();
    }	
#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
	else if(srv_mode_switch_is_network_service_available() == MMI_FALSE &&
			SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status ())
	{
        // Create small screen
        // Put turn on wlan popup into it in flight mode
        VFX_OBJ_CREATE (m_selectScrn, VappWlanSelectScrn, this);
        m_selectScrnId = m_selectScrn->show ();	
	}
#endif	
    else
    {    
        // Show WLAN main screen
        VFX_OBJ_CREATE (m_mainScrn, VappWlanMainScrn, this);
        m_mainScrnWeakPtr = m_mainScrn;
        m_mainScrnId = m_mainScrn->show ();
    }
    VFX_TRACE(("===== Run Application =====\n"));
}

void VappDtcntWlan::onTryToStopTethering(VfxBool isStop)
{
    if(isStop)
    {
	   	// no need to showConfirmPopupInFlightMode,because user want to used wlan in flight mode.
    	// wifi tethering must judge this case.
    	
        VFX_TRACE(("===== Show Main Screen =====\n"));
        // Show WLAN main screen
        VFX_OBJ_CREATE (m_mainScrn, VappWlanMainScrn, this);        
        m_mainScrnWeakPtr = m_mainScrn;
        m_mainScrnId = m_mainScrn->show ();
        
        // Exit entry screen
        m_entryScrn->exit ();
        VFX_TRACE(("===== Exit Entry Screen =====\n"));
    }
    else
    {
        // Quit application
        exit ();
        VFX_TRACE(("===== Exit WLAN application =====\n"));
    }
}

void VappDtcntWlan::onDeinit ()
{
    VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_APP_CLOSE_DONE);

	VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalStopTethering.disconnect(
		this, &VappDtcntWlan::onTryToStopTethering);
	
#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__	
	VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalOpenWLANInFlightMode.disconnect(
		this, &VappDtcntWlan::onTryToOpenWLANInFlightMode);
#endif
	
    VfxApp::onDeinit ();
    VFX_TRACE(("===== Deinitailization =====\n"));
}

mmi_ret VappDtcntWlan::onProc(mmi_event_struct *evt)
{    VFX_TRACE(("===== Dtcnt Wlan App's proc function =====\n"));
    return MMI_RET_OK;
}

VappWlanMainScrn* VappDtcntWlan::getWlanMainScr()
{
	if(m_mainScrnWeakPtr.isValid())
	{		
	    return m_mainScrnWeakPtr.get();				
	}	
	return NULL;
}

#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
void VappDtcntWlan::onTryToOpenWLANInFlightMode(VfxBool isSuccess)
{
    if(isSuccess)
    {   	
        VFX_TRACE(("===== Show Main Screen =====\n"));
        // Show WLAN main screen
        VFX_OBJ_CREATE (m_mainScrn, VappWlanMainScrn, this);       
        m_mainScrnWeakPtr = m_mainScrn;
        m_mainScrnId = m_mainScrn->show ();
        
        // Exit entry screen
        m_selectScrn->exit ();
        VFX_TRACE(("===== Exit select Screen =====\n"));
    }
    else
    {
        // Quit application
        exit ();
        VFX_TRACE(("===== Exit WLAN application =====\n"));
    }
}
#endif

//VFX_IMPLEMENT_CLASS ("VappWlanEntryScrn", VappWlanEntryScrn, VfxMainScr);

void VappWlanEntryScrn::onInit ()
{
    VFX_TRACE(("===== Entry screen initialization =====\n"));
    VfxMainScr::onInit ();
	
	VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalInformWLAN.connect (
		this, &VappWlanEntryScrn::informWlanApp);
}

void VappWlanEntryScrn::onDeinit ()
{
	VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalInformWLAN.disconnect (
		this, &VappWlanEntryScrn::informWlanApp);

    VfxMainScr::onDeinit ();
    VFX_TRACE(("===== Entry screen deinitialization =====\n"));
}

void VappWlanEntryScrn::on1stReady ()
{
    VfxMainScr::on1stReady ();

    setBgColor (VFX_COLOR_TRANSPARENT);

    // show confrim popup to turn off wifi tethering
    VFX_OBJ_CREATE (m_turnOffConfirm, VcpConfirmPopup, this);
    m_turnOffConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_turnOffConfirm->setCustomButton (
        VFX_WSTR_RES(STR_GLOBAL_OK), 
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_turnOffConfirm->setInfoType (VCP_POPUP_TYPE_QUESTION);
    m_turnOffConfirm->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_TURN_OFF_HOT_SPOT));
    m_turnOffConfirm->m_signalButtonClicked.connect (this, &VappWlanEntryScrn::onConfirmBtnClicked);
    m_turnOffConfirm->setAutoDestory(VFX_TRUE);
    m_turnOffConfirm->show (VFX_TRUE);
    VFX_TRACE(("===== Entry screen get ready =====\n"));
}

void VappWlanEntryScrn::onConfirmBtnClicked(VfxObject* sender, VfxId id)
{  
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_TETHERING_CONFIRM_BY_APP);
	
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
        // informWlanApp (SRV_TETHERING_TYPE_WIFI_HS, MMI_TRUE, NULL);
        // Show please waiting popup
        VFX_OBJ_CREATE(m_waitingPopup, VcpIndicatorPopup, this);
        m_waitingPopup->setInfoType (VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_waitingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
        m_waitingPopup->setAutoDestory(VFX_FALSE);
        m_waitingPopup->show (VFX_TRUE);

        // Stop Wi-Fi tethering
        srv_tethering_stop (SRV_TETHERING_TYPE_WIFI_HS, afterStopTethering, NULL);
        break;
    case VCP_CONFIRM_POPUP_BUTTON_USER_2:
    case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
        VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalStopTethering.postEmit (VFX_FALSE);  // Wi-Fi thethering is on and user choose not to turn off
        break;
    default:
        break;
    }
}

void VappWlanEntryScrn::afterStopTethering(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
    VFX_TRACE(("----------------------------\n"));
    VFX_TRACE(("After stop Wi-Fi Tethering!\n"));
    VFX_TRACE(("----------------------------\n"));
    VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalInformWLAN.postEmit(tethering_type, result, user_data);
}

void VappWlanEntryScrn::informWlanApp(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
    VFX_TRACE(("Inform application the result - %d!\n", result));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_AFTER_STOP_TETHERING_CB, result);
    if(m_waitingPopup != NULL)
    {
        m_waitingPopup->exit (VFX_TRUE);
        if(m_waitingPopup != NULL)
        {
            VFX_OBJ_CLOSE (m_waitingPopup);
            m_waitingPopup = NULL;
        }
    }

    if(MMI_TRUE == result)
    {
        VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalStopTethering.postEmit (VFX_TRUE);  // Wi-Fi thethering is turned off
    }
    else
    {
        VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalStopTethering.postEmit (VFX_FALSE);  // Wi-Fi thethering is on and user choose not to turn off
    }
}

#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
//VFX_IMPLEMENT_CLASS ("VappWlanSelectScrn", VappWlanSelectScrn, VfxMainScr);

void VappWlanSelectScrn::on1stReady ()
{
    VfxMainScr::on1stReady ();
	
    setBgColor (VFX_COLOR_TRANSPARENT);
	
	showConfirmPopupInFlightMode();

    VFX_TRACE(("===== Select screen get ready =====\n"));
}
void VappWlanSelectScrn::showConfirmPopupInFlightMode()
{		
	VcpConfirmPopup *confirmPopup;
	VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
	confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
	confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_IN_FLIGHT_MODE_ASK));
	confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	confirmPopup->setCustomButton(
					VFX_WSTR_RES(STR_ID_VAPP_WLAN_IN_FLIGHT_MODE_TURN_ON),
					VFX_WSTR_RES(STR_GLOBAL_CANCEL),
					VCP_POPUP_BUTTON_TYPE_NORMAL,
					VCP_POPUP_BUTTON_TYPE_CANCEL);		
	confirmPopup->setAutoDestory(VFX_TRUE);
	confirmPopup->m_signalButtonClicked.connect(this, &VappWlanSelectScrn::onButtonClick);
	confirmPopup->show(VFX_TRUE);
}

void VappWlanSelectScrn::onButtonClick(VfxObject* sender, VfxU32 id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:	
			// user choose to turn on WLAN in flight mode
			VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalOpenWLANInFlightMode.postEmit (VFX_TRUE);  			
            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:			
		case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
			// user don't choose to turn on WLAN in flight mode
			VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalOpenWLANInFlightMode.postEmit (VFX_FALSE);  
            break;
    }
}
#endif

//VFX_IMPLEMENT_CLASS ("VappWlanMainScrn", VappWlanMainScrn, VfxMainScr);

//W1203_UI_PERFORMANCE_BEGIN
void VappWlanMainScrn::on1stReady ()
{
    VfxMainScr::on1stReady ();

    VappWlanRepository* repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    VappWifiSettingsPage* wifiSettingsPage = NULL;
    
    VFX_OBJ_CREATE_EX (
        wifiSettingsPage, 
        VappWifiSettingsPage, 
        this, 
        (repository));
    pushPage (0, wifiSettingsPage);

    m_pageWeakPtr = wifiSettingsPage;
	m_isOn2ndReady = VFX_FALSE;  //for WLAN APP to Page switch performance

    VFX_TRACE(("===== Main screen get ready =====\n"));
}

void VappWlanMainScrn::on2ndReady()
{	
	VfxMainScr::on2ndReady();
	
	m_isOn2ndReady = VFX_TRUE;  //for WLAN APP to Page switch performance

	if(m_pageWeakPtr.isValid())
	{		
		// performance for scrn to scrn		
		VappWifiSettingsPage *tempPage = m_pageWeakPtr.get(); 
		tempPage->page2ndEnter();					
	}	
}

VfxBool VappWlanMainScrn::getIsOn2ndReady() //for WLAN APP to Page switch performance
{
	return m_isOn2ndReady;
}

//VFX_IMPLEMENT_CLASS ("VappWifiSettingsPage", VappWifiSettingsPage, VfxPage);

VappWifiSettingsPage::VappWifiSettingsPage(VappWlanRepository *repository): 
		m_settingGroupListMenu(NULL),
        m_discWaitingPopup(NULL),
        m_disconnecConfirm(NULL),
        m_waitingPopup(NULL),
        m_timeLeftPopup(NULL),
        m_repository(repository),       
        m_hiltProfile(NULL),
#ifdef __WPS_SUPPORT__
        m_connDurationTimer(NULL),
#endif        
        m_isBackward(VFX_FALSE),
        m_disconnWeakPtr(NULL),
        m_timerWeakPtr(NULL),
        m_discWaitingWeakPtr(NULL),
        m_unableConnWeakPtr(NULL),
        m_wpsWaitingWeakPtr(NULL)
{
    // register page in the respository
    m_repository->registerObserver (this);
}

VappWifiSettingsPage:: ~VappWifiSettingsPage()
{
	// deregister page in the respository
	m_repository->removeObserver (this);
}

void VappWifiSettingsPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INIT_SETTING_PAGE);
    Observer::onInit ();
	
    // Set background color as WHITE
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_SETTING_MAIN_TEXT));
    setTopBar (m_titleBar);
	// Tool Bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
	m_toolBar->addItem (SETTING_TOOLBAR_ADDNETWORK, VFX_WSTR_RES(STR_GLOBAL_ADD), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    m_toolBar->addItem (SETTING_TOOLBAR_NETWORKMGR, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_MAIN_TEXT), VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
    m_toolBar->addItem (SETTING_TOOLBAR_REFRESH, VFX_WSTR_RES(STR_GLOBAL_REFRESH), VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH);
//#ifdef __MMI_OP01_WIFI__  
	m_toolBar->addItem (SETTING_TOOLBAR_ADVANCED, VFX_WSTR_RES(STR_GLOBAL_ADVANCED), VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);
//#endif
	m_toolBar->m_signalButtonTap.connect (this, &VappWifiSettingsPage::onToolBarClick);
    setBottomBar(m_toolBar);
    // Group List Menu
    VFX_OBJ_CREATE (m_settingGroupListMenu, VcpGroupListMenu, this);
    VFX_OBJ_CREATE_EX (m_contentProvider, WifiSettingContentProvider, this, (m_repository, this));
    m_contentProvider->setMenu (m_settingGroupListMenu);
    m_settingGroupListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_settingGroupListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_settingGroupListMenu->m_signalItemTapped.connect (this, &VappWifiSettingsPage::onItemTapped); // Signal
    m_settingGroupListMenu->setContentProvider (m_contentProvider);
    m_settingGroupListMenu->setPos(0, 0);
    m_settingGroupListMenu->setSize(getSize());
    m_settingGroupListMenu->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE); 
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INIT_SETTING_PAGE_END);
}

void VappWifiSettingsPage::onEnter(VfxBool isBackward)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_ENTER_SETTING_PAGE, isBackward);
    VfxPage::onEnter(isBackward);
    m_isBackward = isBackward;

#ifdef __WPS_SUPPORT__
	if(VFX_FALSE == m_isBackward)
	{
		supc_connection_type_enum connType = ALL_PROFILE_ENABLE;   

		for(VfxS32 temp = 0; temp < m_repository->getAPConnNum() ; temp++)
		{
			connType = m_repository->getAPConnTypeSequence(temp);
			if( START_WPS_PIN == connType || START_WPS_PBC == connType)
			{
				// WPS status machine
				m_repository->setWpsStatus(WLAN_WPS_STATUS_NULL);
				// send disconnect request
				VappWlanSentry::SendDisconnectRequest ();				
				break;
			}
		}
    }
#endif		
}

void VappWifiSettingsPage::onEntered()
{
    VfxPage::onEntered ();	    
    VappWlanMainScrn *mainScrn = (VappWlanMainScrn *)this->getMainScr();
	if(mainScrn->getIsOn2ndReady())
	{
		if(m_isBackward)
	    {
	        updateApListMenu();	
			//if Conn num isn't 0 ,disable network mgr bar
			updateToolBar () ;
	    }
	}
}

void VappWifiSettingsPage::onDeinit ()
{	
#ifdef __WPS_SUPPORT__
    VfxBool inWpsConn = VFX_FALSE;
	supc_connection_type_enum connType = ALL_PROFILE_ENABLE;   

	for(VfxS32 temp = 0; temp < m_repository->getAPConnNum() ; temp++)
	{
		connType = m_repository->getAPConnTypeSequence(temp);
		if( START_WPS_PIN == connType || START_WPS_PBC == connType)
		{
			inWpsConn = VFX_TRUE;
			break;
		}
	}

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_CANCEL_WPS_CONNECT_IN_DEINIT, inWpsConn);
    if(inWpsConn)
    {
        // stop timer
        if(m_connDurationTimer)
        {
            m_connDurationTimer->stop ();
        }
		// WPS status machine
		m_repository->setWpsStatus(WLAN_WPS_STATUS_NULL);
        // send disconnect request
        VappWlanSentry::SendDisconnectRequest ();
    }
#endif    
	
	//if CertMan APP open, need to close it before terminate WLAN app
	VfxBool isCertListShow = m_repository->getIsCertListShow ();
	VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_IS_CERT_LIST_SHOW, isCertListShow);   
	if(isCertListShow)
	{
		m_repository->setIsCertListShow (VFX_FALSE);
#ifdef __CERTMAN_SUPPORT__        
		VappCertmanInterfaces::vapp_certman_select_certificates_ind(
			MOD_MMI,
			VAPP_CERTMAN_ACTION_CANCEL,
			KAL_FALSE,
			0,
			STR_GLOBAL_CANCEL,
			VAPP_CERTMAN_CERT_GROUP_ROOT_CA,
			VAPP_CERTMAN_PUBKEY_TYPE_EC_SIGN);
#endif
	}

    /* if WLAN status is inactive, User enter WLAN APP and quickly back,
       so that WLAN APP mainScrn can't 2ndReady and send scan request to srv.
       So In ondeinit() function, MMI send Scan request to open WLAN in that special case */
    if(SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status ())
    {
        if(0 == m_repository->getWlanSettingCuiId()) // Enter Page from wlan APP
        {
            VappWlanMainScrn *mainScrn = (VappWlanMainScrn *)this->getMainScr();
    		if(VFX_FALSE == mainScrn->getIsOn2ndReady())
    		{
    		    entryRefreshProc();
    		}
    	}
    }

    Observer::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_DEINIT_SETTING_PAGE);
}

void VappWifiSettingsPage::page2ndEnter()
{	
	//update listMenu
	updateApListMenu(); 
	//if Conn num isn't 0 ,disable network mgr bar
	updateToolBar () ;

    // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_INIT_MSG |
        SUBSCRIBE_SCAN_MSG | 
        SUBSCRIBE_CONNECT_SUCCESS_MSG | 
        SUBSCRIBE_DISCONNECT_MSG | 
        SUBSCRIBE_CONNECT_FAIL_MSG |
        SUBSCRIBE_CURR_AP_INFO_MSG |
        SUBSCRIBE_WPS_INFO_MSG |
        SUBSCRIBE_BEARER_STATUS_MSG |
        SUBSCRIBE_CONNECT_REQUEST_MSG); 

#ifdef __WPS_SUPPORT__
	// Create a timer for WPS connection
	VFX_OBJ_CREATE (m_connDurationTimer, VfxTimer, this);
	m_connDurationTimer->setStartDelay (1000);	//	Delay 1 second to emit signal
	m_connDurationTimer->setDuration (1000);	//	emit signal per second
	m_connDurationTimer->m_signalTick.connect(this, &VappWifiSettingsPage::onTimerTick); 
#endif 

	// searching for new networks when first enter
	entryRefreshProc ();	
}

void VappWifiSettingsPage::UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg) 
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_UPDATE_SETTING_PAGE, msg);
	supc_abm_cause_enum connFailtype = SUPC_ABM_CONNECT_FAIL;
	VcpConfirmPopup *unableConnectPopup = NULL;
	
    switch(msg)
    {
    case SUBSCRIBE_INIT_MSG:                        /* init event */
        m_repository->updateMacAddress();
        updateApListMenu ();
        break;
    case SUBSCRIBE_SCAN_MSG:                        /* scan event */		
        if(SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS == m_repository->getScanRresult ())
        {
            updateApListMenu ();
        }
        break;
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:             /* connect event */
        /* close disconnecting popup */
		if(m_disconnWeakPtr.isValid())
		{
			VappProfileInfoPopup *tempPopup = m_disconnWeakPtr.get(); 
			VFX_OBJ_CLOSE (tempPopup);
		}
#ifdef __WPS_SUPPORT__        
        /* close time left popup */
        closeTimeLeftPopup();
#endif
        updateApListMenu ();
        break;
    case SUBSCRIBE_CONNECT_FAIL_MSG:		
 		if( ONE_PROFILE_SELECT == m_repository->getCnfConnType() )
 		{
 			/* close unableConnect popup */
			if(m_unableConnWeakPtr.isValid())
			{
				VcpConfirmPopup *tempPopup = m_unableConnWeakPtr.get(); 
				VFX_OBJ_CLOSE (tempPopup);
			}
            VFX_OBJ_CREATE (unableConnectPopup, VcpConfirmPopup, getMainScr());
            unableConnectPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
			unableConnectPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
            unableConnectPopup->setAutoDestory(VFX_TRUE);
#ifdef __MMI_OP01_WIFI__
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
			if(SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT == m_repository->getApToBeActivated()->getAuthMode())
			{
				unableConnectPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERROR_CONNECT_WAPI_NETWORK_FAIL));
			    unableConnectPopup->show (VFX_TRUE);			
				m_unableConnWeakPtr = unableConnectPopup;
				break;
			}
#endif /* __MMI_HIDE_WAPI__ */
#endif /* __WAPI_SUPPORT__ */
#endif /* __MMI_OP01_WIFI__ */
			connFailtype = m_repository->getConnFailType();
			switch(connFailtype)
			{
			case SUPC_ABM_AUTH_FAIL:
            	unableConnectPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CONN_FAIL_AUTH));
            	break;
        	case SUPC_ABM_WRONG_USER_INFO:
            	unableConnectPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CONN_FAIL_INPUT));
            	break;
        	case SUPC_ABM_UNSUPPORTED_EAP_TYPE:
            	unableConnectPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CONN_FAIL_EAP));
            	break;
        	default:
            	unableConnectPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CONN_FAIL_DEFAULT));
            	break;  
			}
            unableConnectPopup->show (VFX_TRUE);			
			m_unableConnWeakPtr = unableConnectPopup;
        }
		else if(ALL_PROFILE_ENABLE == m_repository->getCnfConnType())
		{
			//do nothing

		}
#ifdef __WPS_SUPPORT__
        else if(START_WPS_PIN == m_repository->getCnfConnType() ||
				START_WPS_PBC == m_repository->getCnfConnType() )
        {
            if(m_timerWeakPtr.isValid())
            {
            	/* close unableConnect popup */
				if(m_unableConnWeakPtr.isValid())
				{
					VcpConfirmPopup *tempPopup = m_unableConnWeakPtr.get(); 
					VFX_OBJ_CLOSE (tempPopup);
				}
                VFX_OBJ_CREATE (unableConnectPopup, VcpConfirmPopup, getMainScr());
                unableConnectPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
                unableConnectPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_CONN_FAIL_DEFAULT));
                unableConnectPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
                unableConnectPopup->setAutoDestory(VFX_TRUE);
                unableConnectPopup->show (VFX_TRUE);  				
				m_unableConnWeakPtr = unableConnectPopup;
            }
            /* close time left popup */
            closeTimeLeftPopup();
        }
#endif
        updateApListMenu ();
        break;    
    case SUBSCRIBE_DISCONNECT_MSG:                  /* disconnect event */
        /* close disconnecting waiting popup */
		if(m_discWaitingWeakPtr.isValid())
		{
			VcpIndicatorPopup *tempPopup = m_discWaitingWeakPtr.get(); 
			VFX_OBJ_CLOSE (tempPopup);
		}
#ifdef __WPS_SUPPORT__        
        /* close time left popup */
        closeTimeLeftPopup();
#endif	
        updateApListMenu ();
        break;
    case SUBSCRIBE_CURR_AP_INFO_MSG:
        // if setting page is not in active status, return
        if(getMainScr ()->isActive () && isActive ())
        {
            VcpMenuPos pos(1, 0);
            m_settingGroupListMenu->updateItem (pos);   /* refresh */
        }
        break;
#ifdef __WPS_SUPPORT__
    case SUBSCRIBE_WPS_INFO_MSG:
        showTimeLeftPopup(
            m_repository->getWPSConnType (), 
            m_repository->getConnDuration (),
            m_repository->getPinCode ());
        break;
#endif  
	case SUBSCRIBE_BEARER_STATUS_MSG:
		if(SRV_DTCNT_WLAN_STATE_CONNECTED != srv_dtcnt_wlan_state())
		{
			if(m_disconnWeakPtr.isValid())
			{
				VappProfileInfoPopup *tempPopup = m_disconnWeakPtr.get(); 
				VFX_OBJ_CLOSE (tempPopup);
			}
		}
		
		if(m_discWaitingWeakPtr.isValid())
		{
			VcpIndicatorPopup *tempPopup = m_discWaitingWeakPtr.get(); 
			VFX_OBJ_CLOSE (tempPopup);
		}
		updateApListMenu ();
		break;
	case SUBSCRIBE_CONNECT_REQUEST_MSG:
		break;
    default:
        break;
    }
	
	//if Conn num isn't 0 ,disable network mgr bar
	updateToolBar () ;
}

void VappWifiSettingsPage::updateToolBar () 
{
	//if Conn num isn't 0 ,disable network mgr bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_toolBar->setDisableItem (SETTING_TOOLBAR_ADDNETWORK, VFX_TRUE);		
		m_toolBar->setDisableItem (SETTING_TOOLBAR_NETWORKMGR, VFX_TRUE);
		m_toolBar->setDisableItem (SETTING_TOOLBAR_REFRESH, VFX_TRUE);	
//#ifdef __MMI_OP01_WIFI__  
		m_toolBar->setDisableItem (SETTING_TOOLBAR_ADVANCED, VFX_TRUE);
//#endif
	}
	else
	{
		m_toolBar->setDisableItem (SETTING_TOOLBAR_ADDNETWORK, VFX_FALSE);		
		m_toolBar->setDisableItem (SETTING_TOOLBAR_NETWORKMGR, VFX_FALSE);
		m_toolBar->setDisableItem (SETTING_TOOLBAR_REFRESH, VFX_FALSE);	
//#ifdef __MMI_OP01_WIFI__  
		m_toolBar->setDisableItem (SETTING_TOOLBAR_ADVANCED, VFX_FALSE);
//#endif
	}
}

void VappWifiSettingsPage::onToolBarClick (VfxObject *sender, VfxId id)
{    
	switch(id)
    {
        case SETTING_TOOLBAR_ADDNETWORK:
            entryAddNewNetworkProc();
            break;
		case SETTING_TOOLBAR_NETWORKMGR:
			entryNetworkManageProc();
			break;
        case SETTING_TOOLBAR_REFRESH:
           	entryRefreshProc();					
			break;
//#ifdef __MMI_OP01_WIFI__  			
        case SETTING_TOOLBAR_ADVANCED:
			entryAdvancedProc();
			break;
//#endif
        default:
            break;
    }	
}

void VappWifiSettingsPage::onItemTapped (VcpGroupListMenu *sender, VcpMenuPos pos)
{
    VAPP_WLAN_AP_CHANGE_ENUM    apMatchType;
	srv_dtcnt_wlan_ap_type_enum	apMgrType;
    VfxS32 id;
	VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();	
	VappWlanBaseInfo *baseInfo = NULL;

    VFX_TRACE(("=====Item tapped=====\n"));
    switch(pos.group)
    {    
    case 0:
        switch(pos.pos)
        {
#ifdef __WPS_SUPPORT__
		case 0:
			VFX_TRACE(("=====Select Connection Type=====\n"));				
			// send WPS-PBC connect request to Dtcnt SRV
			m_repository->setWPSConnType (VAPP_WLAN_WPS_PBC);
			entryWPSConnectProc();
			break;			
#endif /* __WPS_SUPPORT__ */  
        }
        break;
    case 1:
        id = pos.pos;
        if(id < 0)
        {
            return;     // tap caption item, return 
        }
        // set index of menu list
        setMenuListIndex (id);		
		baseInfo = apList[getMenuListIndex()];	
        apMatchType = baseInfo->getApMatchType ();
        apMgrType = baseInfo->getApMgrType ();			
  		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_SETTING_SELECT_AP_DETAIL,
			baseInfo->getSsidLen(), apMatchType, apMgrType,
			srv_dtcnt_wlan_state());      
		if(apMatchType == WLAN_AP_SEARCH_SAVED_CONNECTED ||
           apMatchType == WLAN_AP_SAVED_CONNECTED)
        {
            entryWLANApDetail();
        }
        else
        {
            entrySelectConnectTypeProc();
        }
        break;
    case 2:
        break;
    }
}

void VappWifiSettingsPage::onConfirmBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {        
        case CONNECTED_AP_INFO_POPUP_BTN_OK:
            // Exit disconnect confirm popup
			if(m_disconnWeakPtr.isValid())
			{
				VappProfileInfoPopup *tempPopup = m_disconnWeakPtr.get(); 
				VFX_OBJ_CLOSE (tempPopup);
			}
#ifdef __MMI_OP01_WIFI__ 	
			entryCMCCDisconnectProc();
#else
			entryDisconnectProc();
#endif	
            break;
        case CONNECTED_AP_INFO_POPUP_BTN_CANCEL:
            // Exit disconnect confirm popup
			if(m_disconnWeakPtr.isValid())
			{
				VappProfileInfoPopup *tempPopup = m_disconnWeakPtr.get(); 
				VFX_OBJ_CLOSE (tempPopup);
			}
            break;
        default:
            break;
    }
}

#ifdef __WPS_SUPPORT__
void VappWifiSettingsPage::onCancelWPSConnect (VfxObject *sender, VfxId id)
{
    switch(id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
            showCancelWPSConnPopup();
            break;
        default:
            break;
    }
}

void VappWifiSettingsPage::onHomeKeyClicked (VfxU8 status)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_CANCEL_WPS_CONNECT_ON_HOME_KEY);
    // stop timer
    if(m_connDurationTimer)
    {
        m_connDurationTimer->stop ();
    }	
	// WPS status machine
	m_repository->setWpsStatus(WLAN_WPS_STATUS_NULL);
    // send disconnect request
    VappWlanSentry::SendDisconnectRequest ();
}

void VappWifiSettingsPage::onConnTypeItemTapped (VcpMenuPopup* sender, VcpMenuPopupEventEnum evt, VcpMenuPopupItem* ap)
{   
    switch(evt)
    {
    case VCP_MENU_POPUP_EVENT_ITEM_SELECTED:    // a menu item is selected
        VFX_TRACE(("====================================\n"));
        VFX_TRACE(("Tap item %d \n", ap->getId ()));
        VFX_TRACE(("====================================\n"));
		switch( ap->getId () )
		{
		case VAPP_WLAN_WPS_PIN:		    			
			// send WPS-PIN connect request to Dtcnt SRV
			m_repository->setWPSConnType (VAPP_WLAN_WPS_PIN);
			entryWPSConnectProc();
			break; 
		case VAPP_WLAN_WPS_NONE:			
			// send manual connect request to Dtcnt SRV
			m_repository->setWPSConnType (VAPP_WLAN_WPS_NONE);
			entryConnectProc();
			break;
		}
        break;
    case VCP_MENU_POPUP_EVENT_MENU_CANCEL:      // the menu is cancelled by click outside or the close button
        VFX_TRACE(("====================================\n"));
        VFX_TRACE(("CANCEL POPUP \n"));
        VFX_TRACE(("====================================\n"));
        break;
    case VCP_MENU_POPUP_EVENT_MENU_CLOSE:       // the menu is to be closed
        VFX_TRACE(("====================================\n"));
        VFX_TRACE(("CLOSE POPUP \n"));
        VFX_TRACE(("====================================\n"));
        break;
    }
}

void VappWifiSettingsPage::onTimerTick(VfxTimer* durationTimer)
{
    VfxS32 leftTime = m_repository->getConnDuration ();
    VfxMsec lastTime = m_repository->getCurrentSystemTime ();
    VFX_TRACE(("Update - Left time: %d previous time: %d\n", leftTime, lastTime));
    if(leftTime <= 0)
    {
        showCancelWPSConnPopup();
    }
    else
    {
        // set current system time
        VfxMsec curTime = durationTimer->getCurrentSystemTime ();
        m_repository->setCurrentSystemTime (curTime);
        VfxS32 diff = (curTime - lastTime) / 1000;
        VfxS32 deviation = curTime - lastTime - (diff * 1000);
        if(deviation > 500)     /* the maximum uncertainty is 500ms */
        {
            diff += 1;
        }
        
        VFX_TRACE(("Update - Current time: %d diff: %d\n", curTime, diff));
        // decrease left time
        leftTime -= diff;
        m_repository->setConnDuration (leftTime);
        // update time left popup
        updateTimerLeftPopup(
            m_repository->getWPSConnType (), 
            leftTime, 
            m_repository->getPinCode ());
    }
}
#endif

void VappWifiSettingsPage::entryNetworkManageProc ()
{
#ifdef __MMI_OP01_WIFI__	
    VappCMCCNetworkMgrPage* CMCCNetworkMgrPage = NULL;	
    VFX_OBJ_CREATE_EX (
        CMCCNetworkMgrPage, 
        VappCMCCNetworkMgrPage, 
        getMainScr(), 
        (m_repository));
    getMainScr()->pushPage(0, CMCCNetworkMgrPage);
#else
	VappNetworkMgrPage* networkMgrPage = NULL;		
	VFX_OBJ_CREATE_EX (
		networkMgrPage, 
		VappNetworkMgrPage, 
		getMainScr(), 
		(m_repository));
	getMainScr()->pushPage(0, networkMgrPage);
#endif
}

void VappWifiSettingsPage::entryAddNewNetworkProc ()
{
    if(WLAN_SAVED_AP_LIST_NUM_MAX == m_repository->getSavedApNum ())
    {
    	VcpConfirmPopup * invalidInputPopup;
        VFX_OBJ_CREATE (invalidInputPopup, VcpConfirmPopup, getMainScr());
        invalidInputPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
        invalidInputPopup->setText(VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL));
        invalidInputPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        invalidInputPopup->setAutoDestory(VFX_TRUE);
        invalidInputPopup->show (VFX_TRUE);
        return;
    }

    // Set flag 
    m_repository->setIsInsert (VFX_TRUE);
	
	// set add AP type
	m_repository->setAddApType(VAPP_WLAN_ADD_SAVED_AP);

    VappJoinNetworkPage* joinNetworkPage = NULL;
    
    VFX_OBJ_CREATE_EX (joinNetworkPage, VappJoinNetworkPage, getMainScr(), (m_repository, this));
    getMainScr ()->pushPage (0, joinNetworkPage);
}

#ifdef __WPS_SUPPORT__
void VappWifiSettingsPage::entryConfigConnectProc()
{
    VcpMenuPopup*   connTypePopup;
    
    VFX_OBJ_CREATE(connTypePopup, VcpMenuPopup, getMainScr ());
    connTypePopup->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_CONNECT_TYPE_POPUP_TITLE));
	connTypePopup->setIsAutoCancel (VFX_FALSE);
    connTypePopup->setIsAutoClose (VFX_TRUE);
    connTypePopup->m_signalMenuCallback.connect(this, &VappWifiSettingsPage::onConnTypeItemTapped);
    connTypePopup->addItem (VAPP_WLAN_WPS_NONE, VFX_WSTR_RES(STR_ID_VAPP_WLAN_SELECT));
    connTypePopup->addItem (VAPP_WLAN_WPS_PIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_PIN));
    connTypePopup->show (VFX_TRUE);
}


void VappWifiSettingsPage::entryWPSConnectProc()
{
	if(VAPP_WLAN_WPS_PBC == m_repository->getWPSConnType ())
	{		
		// send WPS-PBC connect request to Dtcnt SRV	
    	VappWlanProfile* appProfile = NULL;
		VFX_OBJ_CREATE (appProfile, VappWlanProfile, this);
		VappWlanToolbox::initWlanProfile (appProfile);
		appProfile->setConnType (START_WPS_PBC);
    	m_repository->setApToBeActivated(appProfile);		
	}
	else if(VAPP_WLAN_WPS_PIN == m_repository->getWPSConnType ())
	{
		if(VFX_FALSE == m_repository->findInApList (m_hiltProfile))
		{
		    VcpConfirmPopup* notFoundPopup;
		    VFX_OBJ_CREATE (notFoundPopup, VcpConfirmPopup, getMainScr());
		    notFoundPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
		    notFoundPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
		    notFoundPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
		    notFoundPopup->setAutoDestory(VFX_TRUE);
		    notFoundPopup->show (VFX_TRUE);
		    return;
		}
		// send WPS-PIN connect request to Dtcnt SRV
		m_hiltProfile->setConnType (START_WPS_PIN);
        m_repository->setApToBeActivated(m_hiltProfile);
	}

#ifdef __MMI_OP01_WIFI__  
	entryCMCCConnectProc();
#else
	showWPSWatingPopup();
	VappWlanSentry::SendWPSConnectRequest ();
#endif
}

void VappWifiSettingsPage::showWPSWatingPopup()
{
	// show waiting popup
	VFX_OBJ_CREATE(m_waitingPopup, VcpIndicatorPopup, getMainScr ());
	m_waitingPopup->setInfoType (VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
	m_waitingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
	m_waitingPopup->setAutoDestory(VFX_TRUE);
	m_waitingPopup->show (VFX_TRUE);
	m_wpsWaitingWeakPtr = m_waitingPopup;
}

void VappWifiSettingsPage::showTimeLeftPopup(VAPP_WLAN_WPS_CONN_TYPE connType, VfxU32 leftTime, VfxU32 pinCode)
{	
    VAPP_WLAN_WPS_STATUS wpsStatus = m_repository->getWpsStatus();
	if(WLAN_WPS_STATUS_OVERLAP_ON == wpsStatus || WLAN_WPS_STATUS_OVERLAP_OFF == wpsStatus)
	{
		if(m_timerWeakPtr.isValid())
		{
			/* set text */
    		updateTimerLeftPopup(connType, leftTime, pinCode);
		}
		return;
	}
	else if(WLAN_WPS_STATUS_INIT == wpsStatus )
	{
		if(m_timerWeakPtr.isValid())
		{
			/*  m_timeLeftPopup has displayed, so don't show it again*/
			return;
		}
		
		if(VFX_FALSE == m_wpsWaitingWeakPtr.isValid())
   		{
			// wpsWaitingPopup is NULL, so send disconnect request
			VappWlanSentry::SendDisconnectRequest ();
			return;
   		}
	}
		
	if(m_wpsWaitingWeakPtr.isValid())
	{
		VcpIndicatorPopup *tempPopup = m_wpsWaitingWeakPtr.get(); 
		VFX_OBJ_CLOSE (tempPopup);
	}
	
    /* show pin/pbc connectting popup */
    VFX_OBJ_CREATE(m_timeLeftPopup, VappWlanTimeLeftPopup, getMainScr ());
    m_timeLeftPopup->setInfoType (VCP_POPUP_TYPE_INFO);
    m_timeLeftPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_CANCEL);
    m_timeLeftPopup->m_signalButtonClicked.connect (this, &VappWifiSettingsPage::onCancelWPSConnect);
    m_timeLeftPopup->m_signalHomeKeyClicked.connect (this, &VappWifiSettingsPage::onHomeKeyClicked);
    m_timeLeftPopup->setAutoDestory(VFX_TRUE);
	m_timerWeakPtr = m_timeLeftPopup;
	
    /* set text */
    updateTimerLeftPopup(connType, leftTime, pinCode);
    m_timerWeakPtr->show (VFX_TRUE);
    /* start timer */
    m_connDurationTimer->start ();
    m_repository->setCurrentSystemTime (vrt_sys_get_time());
    /* turn on the backlight */
    srv_backlight_turn_on (SRV_BACKLIGHT_PERMANENT);
}

/* Cancel WPS connection */
void VappWifiSettingsPage::showCancelWPSConnPopup()
{
    closeTimeLeftPopup ();
    // show please wait popup
    VFX_OBJ_CREATE(m_discWaitingPopup, VcpIndicatorPopup, getMainScr ());
    m_discWaitingPopup->setInfoType (VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_discWaitingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_DISCONNECTING));
    m_discWaitingPopup->setAutoDestory(VFX_FALSE);
    m_discWaitingPopup->show (VFX_TRUE);
	m_discWaitingWeakPtr = m_discWaitingPopup;
    // send disconnect request
    VappWlanSentry::SendDisconnectRequest ();
}

void VappWifiSettingsPage::closeTimeLeftPopup()
{   
    // stop timer
    m_connDurationTimer->stop ();
	// WPS status machine
	m_repository->setWpsStatus(WLAN_WPS_STATUS_NULL);
    // close time left popup
	if(m_timerWeakPtr.isValid())
	{	
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_WPS_CLOSE_POPUP);
		VappWlanTimeLeftPopup *tempPopup = m_timerWeakPtr.get(); 
		VFX_OBJ_CLOSE (tempPopup);
	}
    /* switch to GPIO backlight mechanism */
    srv_backlight_turn_off ();
}

void VappWifiSettingsPage::updateTimerLeftPopup(VAPP_WLAN_WPS_CONN_TYPE connType, VfxU32 leftTime, VfxU32 pinCode)
{
    VfxWString connInfo = VFX_WSTR_EMPTY;
    VfxU8 mins = 0;
    VfxU8 seconds = 0;
    VAPP_WLAN_WPS_STATUS wpsStatus = m_repository->getWpsStatus();
	
    mins = leftTime/60;
    seconds = leftTime - mins * 60;

    VfxWString pinCodeDesc(VFX_WSTR_RES(STR_ID_VAPP_WLAN_PIN));
    VfxWString pbcCodeDesc(VFX_WSTR_RES(STR_ID_VAPP_WLAN_PBC));
    VfxWString timeLeftStr(VFX_WSTR_RES(STR_ID_VAPP_WLAN_TIME_LEFT));
    VfxWString minsStr(VFX_WSTR_RES(STR_ID_VAPP_WLAN_TIME_MINS));
    VfxWString minStr(VFX_WSTR_RES(STR_ID_VAPP_WLAN_TIME_MIN));
    VfxWString secsStr(VFX_WSTR_RES(STR_ID_VAPP_WLAN_TIME_SECS));
    VfxWString secStr(VFX_WSTR_RES(STR_ID_VAPP_WLAN_TIME_SEC));
    VfxWString pinDesc(VFX_WSTR_RES(STR_ID_VAPP_WLAN_PIN_DESCRIPTION));
    VfxWString wpsOverLap(VFX_WSTR_RES(STR_ID_VAPP_WLAN_WPS_OVERLAP));
	
    VfxWString pinCodeValue;
    pinCodeValue.format ("%08d\n", pinCode);
    VfxWString minValue;
    minValue.format ("%d", mins);
    VfxWString secValue;
    secValue.format ("%d", seconds);
    VfxWString newLine;
    newLine.format ("\n");
    VfxWString colon;
    colon.format (": ");

    switch(connType)
    {
    case VAPP_WLAN_WPS_PIN:
        if((mins > 0) && (seconds > 0))
        {
            connInfo += pinCodeDesc;
            connInfo += colon;
            connInfo += pinCodeValue;
            connInfo += timeLeftStr;
            connInfo += minValue;
            if(mins > 1)
            {
                connInfo += minsStr;
            }
            else
            {
                connInfo += minStr;
            }
            connInfo += secValue;
            if(seconds > 1)
            {
                connInfo += secsStr;
            }
            else
            {
                connInfo += secStr;    
            }
        }
        else if(mins == 0)
        {
            connInfo += pinCodeDesc;
            connInfo += colon;
            connInfo += pinCodeValue;
            connInfo += timeLeftStr;
            connInfo += secValue;
            if(seconds > 1)
            {
                connInfo += secsStr;
            }
            else
            {
                connInfo += secStr;    
            }
        }
        else if(seconds == 0)
        {
            connInfo += pinCodeDesc;
            connInfo += colon;
            connInfo += pinCodeValue;
            connInfo += timeLeftStr;
            connInfo += minValue;
            if(mins > 1)
            {
                connInfo += minsStr;
            }
            else
            {
                connInfo += minStr;
            }
        }
		if(WLAN_WPS_STATUS_OVERLAP_ON == wpsStatus)
		{
			connInfo += newLine;
            connInfo += wpsOverLap;
            connInfo += newLine;
		}
		else
		{
		    connInfo += newLine;
            connInfo += pinDesc;
            connInfo += newLine;
		}
        break;
    case VAPP_WLAN_WPS_PBC:
        if((mins > 0) && (seconds > 0))
        {
            connInfo += timeLeftStr;
            connInfo += minValue;
            if(mins > 1)
            {
                connInfo += minsStr;
            }
            else
            {
                connInfo += minStr;
            }
            connInfo += secValue;
            if(seconds > 1)
            {
                connInfo += secsStr;
            }
            else
            {
                connInfo += secStr;    
            }
            connInfo += newLine;
        }
        else if(mins == 0)
        {
            connInfo += timeLeftStr;
            connInfo += secValue;
            if(seconds > 1)
            {
                connInfo += secsStr;
            }
            else
            {
                connInfo += secStr;    
            }
            connInfo += newLine;
        }
        else if(seconds == 0)
        {
            connInfo += timeLeftStr;
            connInfo += minValue;
            if(mins > 1)
            {
                connInfo += minsStr;
            }
            else
            {
                connInfo += minStr;
            }
            connInfo += newLine;
        }
		if(WLAN_WPS_STATUS_OVERLAP_ON == wpsStatus)
		{
            connInfo += wpsOverLap;
            connInfo += newLine;
		}
        break;
    default:
        break;
    }
	if(m_timerWeakPtr.isValid())
    {
        m_timerWeakPtr->setText(connInfo);
    }
}

#endif

void VappWifiSettingsPage::entryRefreshProc ()
{	
    VappWlanSentry::SendScanRequest ();
}

void VappWifiSettingsPage::entrySelectConnectTypeProc()
{
	VappWlanBaseInfo *baseInfo = NULL;
	VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();
	baseInfo = apList[getMenuListIndex()];
	
	// Decide whether the AP is supported.
	if((SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == baseInfo->getNetworkType()) &&
		(SRV_DTCNT_WLAN_AUTH_MODE_TOTAL ==baseInfo->getAuthMode()))
	{
		VcpConfirmPopup *errorPopup = NULL;
		VFX_OBJ_CREATE (errorPopup, VcpConfirmPopup, getMainScr());
        errorPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
        errorPopup->setText(VFX_WSTR_RES(STR_GLOBAL_NOT_SUPPORTED));
        errorPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        errorPopup->setAutoDestory(VFX_TRUE);
        errorPopup->show (VFX_TRUE);
		return;
	}	

	if(NULL == m_hiltProfile)
	{
	    VFX_OBJ_CREATE(m_hiltProfile, VappWlanProfile, this);
    }
    VappWlanToolbox::getAppProfileByAppBaseInfo(baseInfo, m_hiltProfile);

#ifdef __WPS_SUPPORT__
	if(SRV_DTCNT_WLAN_AP_DEFAULT == m_hiltProfile->getApMgrType())
	{	
		entryConnectProc();
	}
	else
	{
		entryConfigConnectProc();
	}
#else
	entryConnectProc();
#endif

}

void VappWifiSettingsPage::entryConnectProc()
{
    if(WLAN_AP_SEARCH == m_hiltProfile->getApMatchType ())
    {
        connectToUnsavedAp(m_hiltProfile);
    }
    else
    {
        showConnectingPopup(m_hiltProfile);
    }
}

void VappWifiSettingsPage::entryDisconnectProc()
{	
	showDisconnectingPopup();
	VappWlanSentry::SendDisconnectRequest ();
}

void VappWifiSettingsPage::entryWLANApDetail()
{
    VfxWString connInfo = VFX_WSTR_EMPTY;
    VfxWString apName = VFX_WSTR_EMPTY;
	
	VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();	
    VappWlanBaseInfo *baseInfo = apList[getMenuListIndex()];
	
	VappWlanProfile *currentAp = NULL;
	VFX_OBJ_CREATE(currentAp, VappWlanProfile, this);
	VappWlanToolbox::getAppProfileByAppBaseInfo(baseInfo, currentAp);
	
    if(NULL != currentAp)
    {
#ifdef __MMI_OP01_WIFI__    
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE);
        connInfo += VFX_WSTR(": "); 
        connInfo += currentAp->getAuthModeName ();
		connInfo += VFX_WSTR("\n");

		connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_SIGNAL_STRENGTH);
        connInfo += VFX_WSTR(": ");
        connInfo += currentAp->getRssiStr ();
        connInfo += VFX_WSTR("\n"); 
		
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_LINK_SPEED);
        connInfo += VFX_WSTR(": ");
        connInfo += currentAp->getSpeedStr ();
        connInfo += VFX_WSTR("\n"); 
		
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_CHANNEL);
        connInfo += VFX_WSTR(": ");
        connInfo += currentAp->getChannelStr ();
        connInfo += VFX_WSTR("\n"); 

		connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE);
		connInfo += VFX_WSTR(": "); 
		connInfo += currentAp->getEncryptionModeName ();	
		connInfo += VFX_WSTR("\n"); 
	
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_IP_ADDR);
        connInfo += VFX_WSTR(": "); 
        connInfo += currentAp->getIpAddrStr ();
		connInfo += VFX_WSTR("\n");
		
		connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_GATEWAY);
        connInfo += VFX_WSTR(": "); 
        connInfo += currentAp->getGatewayStr ();		
		connInfo += VFX_WSTR("\n");
		
		connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_NETMASK);
        connInfo += VFX_WSTR(": "); 
        connInfo += currentAp->getNetmaskStr ();	
#else
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_LINK_SPEED);
        connInfo += VFX_WSTR(": ");
        connInfo += currentAp->getSpeedStr ();
        connInfo += VFX_WSTR("\n"); 
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_CHANNEL);
        connInfo += VFX_WSTR(": ");
        connInfo += currentAp->getChannelStr ();
        connInfo += VFX_WSTR("\n"); 
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_SIGNAL_STRENGTH);
        connInfo += VFX_WSTR(": ");
        connInfo += currentAp->getRssiStr ();
        connInfo += VFX_WSTR("\n"); 
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE);
        connInfo += VFX_WSTR(": "); 
        connInfo += currentAp->getAuthModeName ();
        connInfo += VFX_WSTR("\n");
        connInfo += VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_IP_ADDR);
        connInfo += VFX_WSTR(": "); 
        connInfo += currentAp->getIpAddrStr ();
#endif
        apName.loadFromMem ((const VfxWChar *)currentAp->getApName ()); 
    }

    VFX_OBJ_CREATE(m_disconnecConfirm, VappProfileInfoPopup, this);
    m_disconnecConfirm->setAutoDestory(VFX_TRUE);
    m_disconnecConfirm->setTitle (apName);
    m_disconnecConfirm->setText (connInfo);
    m_disconnecConfirm->m_signalButtonClicked.connect (
        this, &VappWifiSettingsPage::onConfirmBtnClick);
    m_disconnecConfirm->show (VFX_TRUE);
	m_disconnWeakPtr = m_disconnecConfirm;
}

void VappWifiSettingsPage::connectToUnsavedAp(VappWlanProfile* hiltAp)
{
	VFX_OBJ_ASSERT_VALID(hiltAp);
	
	srv_dtcnt_wlan_network_type_enum networkType = hiltAp->getNetworkType();
	srv_dtcnt_wlan_auth_mode_enum authMode = hiltAp->getAuthMode();
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_CONN_NO_SAVE_AP, networkType, authMode);
  
	if(SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == networkType)
	{ 
		if(SRV_DTCNT_WLAN_AUTH_MODE_OPEN == authMode)
		{
        	showConnectingPopup(hiltAp);
		}
		else //WPA_NONE or WEP
		{		
			VappPasswordConfigPage* pwdConfigPage = NULL;
        	VFX_OBJ_CREATE_EX (pwdConfigPage, VappPasswordConfigPage, this, (hiltAp));
        	pwdConfigPage->m_signalJoinNetwork.connect (this, &VappWifiSettingsPage::onJoinNetwork);
        	getMainScr()->pushPage (0, pwdConfigPage);
		}
	}
	else if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == networkType)
	{	
		if(SRV_DTCNT_WLAN_AUTH_MODE_OPEN == authMode)
		{
        	showConnectingPopup(hiltAp);
		}		
#ifndef  WIFI_AUTH_PSK_ONLY
		else if(SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY == authMode ||
			SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY == authMode)
		{		
			VappDefaultConfigPage* defaultConfigPage = NULL;
            VFX_OBJ_CREATE_EX (defaultConfigPage, VappDefaultConfigPage, this, (hiltAp));
            defaultConfigPage->m_signalJoinNetwork.connect (this, &VappWifiSettingsPage::onJoinNetwork);
            getMainScr()->pushPage (0, defaultConfigPage);
		}
#endif	/* WIFI_AUTH_PSK_ONLY */
		else if(SRV_DTCNT_WLAN_AUTH_MODE_WEP == authMode ||
			SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK == authMode ||
			SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK == authMode)
		{		
			VappPasswordConfigPage* pwdConfigPage = NULL;
			VFX_OBJ_CREATE_EX (pwdConfigPage, VappPasswordConfigPage, this, (hiltAp));
			pwdConfigPage->m_signalJoinNetwork.connect (this, &VappWifiSettingsPage::onJoinNetwork);
			getMainScr()->pushPage (0, pwdConfigPage);
		}
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    	else if(SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK == authMode)
    	{
            VappWAIPSKConfigPage* waiPskConfigPage = NULL;
            VFX_OBJ_CREATE_EX (waiPskConfigPage, VappWAIPSKConfigPage, this, (hiltAp));
            waiPskConfigPage->m_signalJoinNetwork.connect (this, &VappWifiSettingsPage::onJoinNetwork);
            getMainScr()->pushPage (0, waiPskConfigPage);
        }
        else if(SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT == authMode)
        {
            VappWAICertConfigPage* waiCertConfigPage = NULL;
            VFX_OBJ_CREATE_EX (waiCertConfigPage, VappWAICertConfigPage, this, (hiltAp));
            waiCertConfigPage->m_signalJoinNetwork.connect (this, &VappWifiSettingsPage::onJoinNetwork);
            getMainScr()->pushPage (0, waiCertConfigPage);
        }
#endif  /* __MMI_HIDE_WAPI__ */
#endif
	}
}

void VappWifiSettingsPage::onJoinNetwork(VfxBool isJoin, VappWlanProfile* network)
{   
    if(isJoin && (network != NULL))
    {
        VappWlanProfile* profile;    
        VFX_OBJ_CREATE (profile, VappWlanProfile, this);
        VappWlanToolbox::cloneWlanProfile (network, profile);
        
        showConnectingPopup(profile);

        VFX_OBJ_CLOSE (profile);
    }
    // Quit
    getMainScr ()->popPage ();
}

void VappWifiSettingsPage::showConnectingPopup(VappWlanProfile* hiltAp)
{   
    VfxBool isFound = m_repository->findInApList (hiltAp);
    
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_CONN_REQ_BEFORE_START, isFound);
    if(VFX_FALSE == isFound)
    {
        VcpConfirmPopup* notFoundPopup;
        VFX_OBJ_CREATE (notFoundPopup, VcpConfirmPopup, getMainScr());
        notFoundPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
        notFoundPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
        notFoundPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        notFoundPopup->setAutoDestory(VFX_TRUE);
        notFoundPopup->show (VFX_TRUE);
        return;
    }
	
	hiltAp->setConnType (ONE_PROFILE_SELECT);
    m_repository->setApToBeActivated (hiltAp);
#ifdef __MMI_OP01_WIFI__  
	entryCMCCConnectProc();
#else
	VappWlanSentry::SendConnectRequest ();
#endif

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void VappWifiSettingsPage::showDisconnectingPopup()
{
    VFX_OBJ_CREATE(m_discWaitingPopup, VcpIndicatorPopup, getMainScr ());
    m_discWaitingPopup->setInfoType (VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_discWaitingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_DISCONNECTING));
    m_discWaitingPopup->setAutoDestory(VFX_FALSE);
    m_discWaitingPopup->show (VFX_TRUE);
	m_discWaitingWeakPtr = m_discWaitingPopup;
}

void VappWifiSettingsPage::updateApListMenu()
{
    // if setting page is not in active status, return
    if(getMainScr ()->isActive () && isActive ())
    {
    	if(m_settingGroupListMenu != NULL)
    	{
        	m_settingGroupListMenu->resetAllItems (VFX_TRUE);
    	}
    }
}

void VappWifiSettingsPage::entryAdvancedProc ()
{   
	VappAdvancedPage* advancedPage = NULL;
    
    VFX_OBJ_CREATE_EX (
        advancedPage, 
        VappAdvancedPage, 
        getMainScr(), 
        (m_repository));
    getMainScr()->pushPage(0, advancedPage);
}

#ifdef __MMI_OP01_WIFI__  
VfxBool VappWifiSettingsPage::VerifyNetWorkStatus()
{
	MMI_BOOL isAutoAuth = vapp_dtcnt_wlan_is_auto_auth();

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_CURRENT_STATUS,
			m_repository->getWlanUiFlow (), srv_dtcnt_wlan_status(), isAutoAuth);  
	
    if((WLAN_UI_DISC_AFTER_LOGIN_FAILED == m_repository->getWlanUiFlow ()) ||
	    ((WLAN_UI_WAIT_FOR_IP_UPDATE == m_repository->getWlanUiFlow ()) &&
	   	(MMI_TRUE == isAutoAuth)))
    {
    	VcpConfirmPopup * invalidInputPopup;
        VFX_OBJ_CREATE (invalidInputPopup, VcpConfirmPopup, getMainScr());
        invalidInputPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
        invalidInputPopup->setText(VFX_WSTR_RES(STR_GLOBAL_BUSY_TRY_LATER));
        invalidInputPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        invalidInputPopup->setAutoDestory(VFX_TRUE);
        invalidInputPopup->show (VFX_TRUE);
        return VFX_FALSE;
    }	
	return VFX_TRUE;
}

void VappWifiSettingsPage::entryCMCCConnectProc ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_CONN_PROC); 
			
	if(VFX_FALSE == VerifyNetWorkStatus())
	{
		return;
	}
	
    if((WLAN_UI_PORTAL_LOGOUT != m_repository->getWlanUiFlow ()) &&  /* not in the logout proc */
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
		SRV_DTCNT_WLAN_AP_DEFAULT == m_repository->getConnectedAP()->getApMgrType())
    {  	
    	if(ONE_PROFILE_SELECT == m_repository->getApToBeActivated()->getConnType())
    	{    	
    		m_repository->setActionAfterLogout(WLAN_AP_CMCC_LOGOUT_MANUAL_CONN);	
    	}   	
#ifdef __WPS_SUPPORT__
		else
		{		
			showWPSWatingPopup();
			m_repository->setActionAfterLogout(WLAN_AP_CMCC_LOGOUT_WPS_CONN);
		}
#endif /* __WPS_SUPPORT__ */		
        VappWlanCMCCMgr::entryCMCCPortalCertLogoutStart ();
    }
	else
	{	
	    if(ONE_PROFILE_SELECT == m_repository->getApToBeActivated()->getConnType())
    	{    	
			VappWlanSentry::SendConnectRequest ();
    	}
#ifdef __WPS_SUPPORT__    	
		else
		{		
			showWPSWatingPopup();
			VappWlanSentry::SendWPSConnectRequest ();
		}
#endif /* __WPS_SUPPORT__ */		
	}
}

void VappWifiSettingsPage::entryCMCCDisconnectProc()
{	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_DISCONN_PROC); 

	if(VFX_FALSE == VerifyNetWorkStatus())
	{
		return;
	}

    if((WLAN_UI_PORTAL_LOGOUT != m_repository->getWlanUiFlow ()) &&  /* not in the logout proc */
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
		SRV_DTCNT_WLAN_AP_DEFAULT == m_repository->getConnectedAP()->getApMgrType())
    {
    	m_repository->setActionAfterLogout(WLAN_AP_CMCC_LOGOUT_DISCONN);		
        VappWlanCMCCMgr::entryCMCCPortalCertLogoutStart ();
    }
    else
    {
		entryDisconnectProc();
    }	
}
#endif

VfxU32 VappWifiSettingsPage::getMenuListIndex() const
{
    return m_menuListIndex;
}
void VappWifiSettingsPage::setMenuListIndex(VfxU32 index)
{
    m_menuListIndex = index;
}

/******************************************************************************/
// Implement the required content provider functions
void WifiSettingContentProvider::setMenu(VcpGroupListMenu *menu)
{
    m_groupListMenu = menu;
}

VfxU32 WifiSettingContentProvider::getGroupCount() const
{
 	return SETTING_SCREEN_GROUP_TOTAL;
}

VfxU32 WifiSettingContentProvider::getCount(VfxU32 group) const
{
    VfxU32 count = 0;
    switch(group)
    {
    case SETTING_SCREEN_GROUP_ONE:
        count = WLAN_APP_MAIN_PAGE_ITEM_COUNT;
        break;
    case SETTING_SCREEN_GROUP_TWO:	
        {
        	VappWlanMainScrn *mainScrn = (VappWlanMainScrn *)m_parentPage->getMainScr();
    		if(mainScrn->getIsOn2ndReady())
    		{
    			count = m_repository->getUsefulApNum ();	
    		}
    		else
    		{
    			// if count = 0, it can't call getItemText()... when group = 2.
    			count = 0; // for UI performance
    		}
		}
		break;
    case SETTING_SCREEN_GROUP_THREE:
        count = 1;
        break;        
    default:
        break;
    }
    return count;
}

VcpListMenuCellClientBaseFrame* WifiSettingContentProvider::getItemCustomContentFrame(
        VcpMenuPos pos,         // [IN] position of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        )
{
    VappWlanApListMenuCell*  apListMenuCell;
    VcpListMenuCellSingleTextFrame* funcListMenuCell;
    
    switch(pos.group)
    {
    case SETTING_SCREEN_GROUP_ONE:
        switch(pos.pos)
        {
#ifdef __WPS_SUPPORT__
		case 0:
			VFX_OBJ_CREATE (apListMenuCell, VappWlanApListMenuCell, parentFrame);
			return apListMenuCell;
#endif
        }
        break;
    case SETTING_SCREEN_GROUP_TWO:
        VFX_OBJ_CREATE (apListMenuCell, VappWlanApListMenuCell, parentFrame);
        return apListMenuCell;    
    case SETTING_SCREEN_GROUP_THREE:
        VFX_OBJ_CREATE (funcListMenuCell, VcpListMenuCellSingleTextFrame, parentFrame);
        return funcListMenuCell;
    }
    
    return NULL;
}

VfxBool WifiSettingContentProvider::getItemText(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    VfxWString description = VFX_WSTR_EMPTY;
    VAPP_WLAN_AP_CHANGE_ENUM curType;
    VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();
    VfxU32 index = pos.pos; 
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    switch(pos.group)
    {
    case SETTING_SCREEN_GROUP_ONE:
        switch(pos.pos)
        {
#ifdef __WPS_SUPPORT__
		// Add WPS Menu Item
		case 0:
			switch(fieldType)
			{
			case VCP_LIST_MENU_FIELD_TEXT:
				text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WPS_CONNECT);
				// text = VFX_WSTR("WPS connect");
				break;
			case VCP_LIST_MENU_FIELD_SUB_TEXT1:
				text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_WPS_CONNECT_DESCRIPTION);
				// text = VFX_WSTR("Use Wi-Fi protected setup to connect");
				break;
			}
			break;
#endif
        }
        break;
    case SETTING_SCREEN_GROUP_TWO: 
        switch(fieldType)
        {
        case VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT:
            text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_CAPTION);
            break;
        case VCP_LIST_MENU_FIELD_TEXT:
            text.loadFromMem ((const VfxWChar *)apList[index]->getApName());
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT1:
            curType = apList[index]->getApMatchType ();
            if(WLAN_AP_SAVED_CONNECTED == curType ||
               WLAN_AP_SEARCH_SAVED_CONNECTED == curType)
            {
                text.loadFromRes(STR_ID_VAPP_WLAN_CONNECTED);
                color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
            }
            else
            {
                if(SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == apList[index]->getNetworkType ())
                {
                    description = apList[index]->getNetworkTypeName ();
                    description += VFX_WSTR(", ");
                    description += apList[index]->getAuthModeName ();
                    text = description;            
                }
                else
                {
                    text = apList[index]->getAuthModeName ();
                }
            } 
            break;
        }
        break;
    case SETTING_SCREEN_GROUP_THREE:
        text = m_repository->getMacInfoStr ();
        break;
    }

    return VFX_TRUE;
}

VfxBool WifiSettingContentProvider::getItemTextFrameFormat(
        VcpMenuPos pos,                 // [IN] the position of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxTextFrame *frame             // [OUT] the text frame
        )
{
	if(pos.group == SETTING_SCREEN_GROUP_ONE)
	{
		return VFX_FALSE;
	}

    if (pos.group == SETTING_SCREEN_GROUP_THREE)
    {
        VfxFontDesc fontDesc;

        fontDesc.size = VFX_FONT_DESC_VF_SIZE(MAC_ADDR_INFO_FONT_SIZE);
        frame->setFont (fontDesc);
        frame->setColor (VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
        frame->setAlignMode (VfxTextFrame::ALIGN_MODE_CENTER);
        return VFX_TRUE;
    }

    VfxBool isHighlight = VFX_FALSE;
    VcpListMenuCell* menuCell = m_groupListMenu->getCell (pos);
    if(menuCell)
    {
        isHighlight = menuCell->m_isHighlight;
    }
	if( !isHighlight )
	{
    	if ((pos.group == SETTING_SCREEN_GROUP_TWO) && (fieldType == VCP_LIST_MENU_FIELD_TEXT))
    	{
        	VfxU32 index = pos.pos;
        	VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();
        	VAPP_WLAN_AP_CHANGE_ENUM curType = apList[index]->getApMatchType ();

        	if(WLAN_AP_SAVED_CONNECTED == curType ||
           		WLAN_AP_SEARCH_SAVED_CONNECTED == curType)
        	{
            	frame->setColor (VFX_COLOR_RES(CLR_COSMOS_TEXT_LINK));
            	return VFX_TRUE;
        	}
    	}
	}

    return VFX_FALSE;
}

VfxBool WifiSettingContentProvider::getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        ) 
{
	if(pos.group == SETTING_SCREEN_GROUP_ONE ||
		pos.group == SETTING_SCREEN_GROUP_THREE)
	{
		return VFX_FALSE;
	}
    
    if(pos.group == SETTING_SCREEN_GROUP_TWO && 
		fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();
        VfxResId  resId = apList[pos.pos]->getNetworkTypeIcon ();
        if(0 != resId)
        	image.setResId(resId);
		return VFX_TRUE;
    }
	return VFX_TRUE;
}


VfxBool WifiSettingContentProvider::hasGroupHeader(VfxS32 group) const
{
	return ((group == SETTING_SCREEN_GROUP_TWO) ? VFX_TRUE : VFX_FALSE);
}
//W1203_UI_PERFORMANCE_END

VfxBool WifiSettingContentProvider::getItemIsHighlightable(
        VcpMenuPos pos  // [IN] position of the item
        ) const 
{
    switch(pos.group)
    {
    case SETTING_SCREEN_GROUP_THREE:
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

/*******************************************************************************/
/* CLASS VappPasswordConfigPage */
/*******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappPasswordConfigPage", VappPasswordConfigPage, VfxPage);
VappPasswordConfigPage::VappPasswordConfigPage(VappWlanProfile *profile) :
        m_password(VFX_WSTR_EMPTY)
{
    VFX_TRACE(("====constructor - VappPasswordConfigPage====\n"));
    VFX_OBJ_CREATE(m_hiltProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (profile, m_hiltProfile);
}

VappPasswordConfigPage::~VappPasswordConfigPage()
{
    VFX_TRACE(("====Deconstructor - VappPasswordConfigPage====\n"));
}

void VappPasswordConfigPage::onInit ()
{
    VFX_TRACE(("===== VappPasswordConfigPage initialization =====\n"));
    Observer::onInit ();

    setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(PWD_CFG_FORM_FUNC_BAR_JOIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_JOIN));
    m_functionBar->setItemSpecial (PWD_CFG_FORM_FUNC_BAR_JOIN);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (this, &VappPasswordConfigPage::onFuncBarBtnClick);

    // Title Bar
    VfxWString title = VFX_WSTR_RES(STR_ID_VAPP_WLAN_PASSWORD_FOR_NETWORK);
    VfxWString name = VFX_WSTR_EMPTY;
    name.loadFromMem ((const VfxWChar *)m_hiltProfile->getApName());
    title += name;
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (title);
    setTopBar (m_titleBar);

    // Tool Bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (PWD_CFG_FORM_TOOLBAR_JOIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_JOIN), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (PWD_CFG_FORM_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappPasswordConfigPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Password
    VFX_OBJ_CREATE(m_passwordTextInput, VcpFormItemTextInput, this);
    m_passwordTextInput->setLabelText(VFX_WSTR_RES(STR_GLOBAL_PASSWORD));
    m_passwordTextInput->setLabelPosition (VCPFORM_TOP_LEFT);
    if(SRV_DTCNT_WLAN_AUTH_MODE_WEP == m_hiltProfile->getAuthMode())
    {
        VsrvInputBinding inputBind(
            IMM_INPUT_TYPE_ASCII_PASSWORD,
            0,
            IME_INPUT_STYLE_NONE,
            static_cast<InputConnection*>(m_passwordTextInput->getTextBox ()->m_editing));
        inputBind.setAllowedChars (VFX_WSTR ("\'+\\\\_\\-.@!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9"));
        m_passwordTextInput->getTextBox ()->setIME (inputBind);
        m_passwordTextInput->getTextBox ()->setText (m_password, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN);
    }
    else
    {
        m_passwordTextInput->getTextBox ()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
        m_passwordTextInput->getTextBox ()->setText (m_password, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
    }
    m_passwordTextInput->getTextBox ()->setFunctionBar (m_functionBar);
    m_passwordTextInput->getTextBox ()->setAutoActivated (VFX_TRUE);
    m_passwordTextInput->setPos (0, 0);
}

void VappPasswordConfigPage::onBack ()
{
    VFX_TRACE(("===================================================\n"));
    VFX_TRACE(("===== VappPasswordConfigPage onBack =====\n"));
    VFX_TRACE(("===================================================\n"));
    // Emit signal to inform its parent
    m_signalJoinNetwork.emit (VFX_FALSE, m_hiltProfile);
}

void VappPasswordConfigPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
        case PWD_CFG_FORM_TOOLBAR_JOIN:
            connectToSecurityAp();
            break;
        case PWD_CFG_FORM_TOOLBAR_CANCEL:
            // Emit signal to inform its parent
            m_signalJoinNetwork.emit (VFX_FALSE, m_hiltProfile);
            break;
        default:
            break;
    }
}

void VappPasswordConfigPage::onFuncBarBtnClick (VfxObject* sender, VfxId id)
{
    m_passwordTextInput->getTextBox ()->deactivate ();
    connectToSecurityAp();
}

void VappPasswordConfigPage::showInvalidKeyPopup()
{
    // Clean incorrect password
    m_password = VFX_WSTR_EMPTY;
	VfxS32 maxLen = m_passwordTextInput->getTextBox ()->getMaxLength();
	m_passwordTextInput->getTextBox ()->setText (m_password, maxLen);
    m_passwordTextInput->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INVALID_KEY));
}

VfxBool VappPasswordConfigPage::verifyPasswordInput(CONNECT_AP_TYPE_ENUM apType)
{
    VfxBool    isValid = VFX_FALSE;
    VfxWString text = m_passwordTextInput->getText ();
    VfxU32     length = text.getLength ();
    VfxChar*   password;
    VfxChar*   passphrase;
    VfxChar*   psk;
    
    VFX_ALLOC_MEM(passphrase, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1, this);
    VFX_ALLOC_MEM(password, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1, this);
    VFX_ALLOC_MEM(psk, SRV_DTCNT_PROF_MAX_PSK_LEN, this);
    
    memset(passphrase, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
    memset(password, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
    memset(psk, 0, SRV_DTCNT_PROF_MAX_PSK_LEN);
    
    switch(apType)
    {
    case CONNECT_AP_WPA:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_PASSWORD_CONFIG_PSK, length);
        if(length >= PASSPHRASE_KEY_LEN_MIN)
        {
            if(SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN == length)
            {
                VappWlanToolbox::convertStrToAscii (password, text, length);
                VFX_TRACE(("===> Password user inputed: %s\n", password));

                if(VappWlanToolbox::checkHexString ((const VfxU8 *) password, length))
                {
                    // remove the conversion logic into dtcnt wlan service
                    VappWlanToolbox::convertHexToStr (psk, password, length);
                    m_hiltProfile->setPsk ((const VfxU8*)psk);
                    m_hiltProfile->setPassphrase ((const VfxU8*)password);
                    VFX_TRACE(("===> PSK: %s \n", m_hiltProfile->getPsk ()));
                    isValid = VFX_TRUE;
                }
                else
                {
                    isValid = VFX_FALSE;
                }
            }
            else
            {
                if(length < SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN)
                    VappWlanToolbox::convertStrToAscii (password, text, length);
                else
                    VappWlanToolbox::convertStrToAscii (password, text, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
                VFX_TRACE(("===> Password user inputed: %s\n", password));

                m_hiltProfile->setPassphrase ((const VfxU8*)password);
                isValid = VFX_TRUE;
            }
        }
        break;
    case CONNECT_AP_WEP_KEY:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_PASSWORD_CONFIG_WEP, length);
        if(0 == length || length > WEP_KEY_LENGTH_128BITS_HEX)
        {
            isValid = VFX_FALSE;
        }
        else
        {   
            VappWlanToolbox::convertStrToAscii (password, text, length);
            switch (length)
            {
                case AP_WEP_KEY_LEN_FIVE:
                    m_hiltProfile->setWepKeyLen (SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64);
                    m_hiltProfile->setWepKeyFormat (SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII);
                    m_hiltProfile->setWepKey ((const VfxU8*)password);
                    isValid = VFX_TRUE;
                    break;
                case AP_WEP_KEY_LEN_THIRTEEN:
                    m_hiltProfile->setWepKeyLen (SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128);
                    m_hiltProfile->setWepKeyFormat (SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII);
                    m_hiltProfile->setWepKey ((const VfxU8*)password);
                    isValid = VFX_TRUE;
                    break;
                case AP_WEP_KEY_LEN_TEN:
                    isValid = VappWlanToolbox::convertHexToStr (passphrase, password, length);
                    if(isValid == VFX_TRUE)
                    {
                        m_hiltProfile->setWepKeyLen (SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64);
                        m_hiltProfile->setWepKeyFormat (SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX);
                        m_hiltProfile->setWepKey ((const VfxU8*)password);
                    }
                    break;
                case AP_WEP_KEY_LEN_TWENTY_SIX:
                {
                    isValid = VappWlanToolbox::convertHexToStr (passphrase, password, length);
                    if(isValid == VFX_TRUE)
                    {
                        m_hiltProfile->setWepKeyLen (SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128);
                        m_hiltProfile->setWepKeyFormat (SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX);
                        m_hiltProfile->setWepKey ((const VfxU8*)password);
                    }
                    break;
                }
                default:
                    isValid = VFX_FALSE;
                    break;
            }
            VFX_TRACE(("===> WEP Index: %d \n", m_hiltProfile->getWepKeyIndex ()));
            VFX_TRACE(("===> WEP Length: %d \n", m_hiltProfile->getWepKeyLen ()));
            VFX_TRACE(("===> WEP Format: %d \n", m_hiltProfile->getWepKeyFormat ()));
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_CONN_WEP_INPUT, 
                m_hiltProfile->getWepKeyIndex (),
                m_hiltProfile->getWepKeyLen (),
                m_hiltProfile->getWepKeyFormat (),
                strlen((const char*)m_hiltProfile->getWepKey ()));
        }
        break;
    default:
        break;
    }

    VFX_FREE_MEM (password);
    VFX_FREE_MEM (psk);
    VFX_FREE_MEM (passphrase);
    
    return isValid;
}

void VappPasswordConfigPage::connectToSecurityAp()
{
    if(SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK == m_hiltProfile->getAuthMode() ||
		SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK == m_hiltProfile->getAuthMode() ) 
    {
        if(VFX_TRUE == verifyPasswordInput (CONNECT_AP_WPA))
        {
            VFX_TRACE(("===> Passphrase: %s \n", m_hiltProfile->getPassphrase ()));
        }
        else
        {   
            showInvalidKeyPopup();
            return;
        }

    }
    /* WEP */
    else if(SRV_DTCNT_WLAN_AUTH_MODE_WEP == m_hiltProfile->getAuthMode())
    {
        if(VFX_TRUE == verifyPasswordInput (CONNECT_AP_WEP_KEY))
        {
            VFX_TRACE(("===> WEP key: %s \n", m_hiltProfile->getWepKey ()));
        }
        else
        {
            showInvalidKeyPopup();
            return;
        }
    }
    // Emit signal to inform its parent
    m_signalJoinNetwork.emit (VFX_TRUE, m_hiltProfile);;
}

#ifndef  WIFI_AUTH_PSK_ONLY
/*******************************************************************************/
/* CLASS VappDefaultConfigPage */
/*******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappDefaultConfigPage", VappDefaultConfigPage, VfxPage);

VappDefaultConfigPage::VappDefaultConfigPage()
{
    VFX_TRACE(("====Default constructor - VappDefaultConfigPage====\n"));
}
    
VappDefaultConfigPage::VappDefaultConfigPage(VappWlanProfile *profile) :
        m_userName(VFX_WSTR_EMPTY),
        m_password(VFX_WSTR_EMPTY)
{
    VFX_TRACE(("====Constructor - VappDefaultConfigPage====\n"));
    VFX_OBJ_CREATE(m_hiltProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (profile, m_hiltProfile);
}   

VappDefaultConfigPage::~VappDefaultConfigPage()
{
    VFX_TRACE(("====Deconstructor - VappDefaultConfigPage====\n"));
}


void VappDefaultConfigPage::onInit ()
{
    VFX_TRACE(("===== VappDefaultConfigPage initialization =====\n"));
    Observer::onInit ();

    setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(DEFAULT_CFG_FORM_FUNC_BAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_PREV));
    m_functionBar->addItem(DEFAULT_CFG_FORM_FUNC_BAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_NEXT));
    m_functionBar->addItem(DEFAULT_CFG_FORM_FUNC_BAR_JOIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_JOIN));
    m_functionBar->setItemSpecial (DEFAULT_CFG_FORM_FUNC_BAR_JOIN);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (this, &VappDefaultConfigPage::onFuncBarBtnClick);
    
    // Title Bar
    VfxWString title = VFX_WSTR_RES(STR_ID_VAPP_WLAN_PASSWORD_FOR_NETWORK);
    VfxWString name = VFX_WSTR_EMPTY;
    name.loadFromMem ((const VfxWChar *)m_hiltProfile->getApName());
    title += name;
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (title);
    setTopBar (m_titleBar);

    // Tool Bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (DEFAULT_CFG_FORM_TOOLBAR_JOIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_JOIN), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (DEFAULT_CFG_FORM_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappDefaultConfigPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Input username
    VFX_OBJ_CREATE(m_userNameTextInput, VcpFormItemTextInput, this);
    m_userNameTextInput->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_USERNAME));
    m_userNameTextInput->setLabelPosition (VCPFORM_TOP_LEFT);
    //m_userNameTextInput->getTextBox()->setText (m_userName, SRV_DTCNT_PROF_MAX_USER_LEN);
    m_userNameTextInput->getTextBox()->setText(
    				                    m_userName, 
            						    SRV_DTCNT_PROF_MAX_USER_LEN,
            						    VFX_FALSE,
            						    VCP_TEXT_ENCODING_UTF8);
    m_userNameTextInput->getTextBox()->setCursorIndex (0);
    m_userNameTextInput->getTextBox()->setAutoActivated (VFX_TRUE);
    // m_userNameTextInput->getTextBox()->setAutoDeactivated (VFX_TRUE);
    m_userNameTextInput->getTextBox()->setFunctionBar (m_functionBar);
    m_userNameTextInput->getTextBox ()->m_signalActivated.connect (
        this, &VappDefaultConfigPage::onTextEditorActivated);

    // Input password
    VFX_OBJ_CREATE(m_passwordTextInput, VcpFormItemTextInput, this);
    m_passwordTextInput->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_PASSWORD));
    m_passwordTextInput->setLabelPosition (VCPFORM_TOP_LEFT);
    m_passwordTextInput->getTextBox()->setText (m_password, SRV_DTCNT_PROF_MAX_PW_LEN);
    // m_passwordTextInput->getTextBox()->setAutoDeactivated (VFX_TRUE);
    m_passwordTextInput->getTextBox ()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
    m_passwordTextInput->getTextBox ()->setFunctionBar (m_functionBar);
    m_passwordTextInput->getTextBox ()->m_signalActivated.connect (
        this, &VappDefaultConfigPage::onTextEditorActivated);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Append item into form
    m_form->addItem (m_userNameTextInput, DEFAULT_CFG_FORM_USERNAME);
    m_form->addItem (m_passwordTextInput, DEFAULT_CFG_FORM_PASSWORD);
}

void VappDefaultConfigPage::onDeinit ()
{
    VFX_OBJ_CLOSE(m_hiltProfile);
    
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_toolBar);
    VFX_OBJ_CLOSE(m_userNameTextInput);
    VFX_OBJ_CLOSE(m_passwordTextInput);
    VFX_OBJ_CLOSE(m_form);

    Observer::onDeinit ();
    VFX_TRACE(("===== VappDefaultConfigPage deinitialization =====\n"));
}

void VappDefaultConfigPage::onBack ()
{
    VFX_TRACE(("===================================================\n"));
    VFX_TRACE(("===== VappPasswordConfigPage onBack =====\n"));
    VFX_TRACE(("===================================================\n"));
    // Emit signal to inform its parent
    m_signalJoinNetwork.emit (VFX_FALSE, m_hiltProfile);
}

void VappDefaultConfigPage::onFuncBarBtnClick (VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case DEFAULT_CFG_FORM_FUNC_BAR_PREV:
        if(m_prevEditor)
        {
            m_prevEditor->activate ();
        }
        break;
    case DEFAULT_CFG_FORM_FUNC_BAR_NEXT:
        if(m_nextEditor)
        {
            m_nextEditor->activate ();
        }
        break;        
    case DEFAULT_CFG_FORM_FUNC_BAR_JOIN:
        if(m_curEditor)
        {
            m_curEditor->deactivate ();
        }
        connectToSecurityAp();
        break;
    default:
        break;
    }
}

void VappDefaultConfigPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
        case DEFAULT_CFG_FORM_TOOLBAR_JOIN:
            connectToSecurityAp();
            break;
        case DEFAULT_CFG_FORM_TOOLBAR_CANCEL:
            m_signalJoinNetwork.emit (VFX_FALSE, m_hiltProfile);
            break;
        default:
            break;
    }
}

void VappDefaultConfigPage::onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive)
{
    if(isActive)
    {
        VFX_TRACE(("Text editor activated!\n"));
        if(sender == m_userNameTextInput->getTextBox ())
        {
            m_prevEditor = NULL;
            m_nextEditor = m_passwordTextInput->getTextBox ();
        }
        else if(sender == m_passwordTextInput->getTextBox ())
        {
            m_prevEditor = m_userNameTextInput->getTextBox ();
            m_nextEditor = NULL;
        }
        m_curEditor = sender;
        
        m_functionBar->setDisableItem (DEFAULT_CFG_FORM_FUNC_BAR_PREV, m_prevEditor == NULL);
        m_functionBar->setDisableItem (DEFAULT_CFG_FORM_FUNC_BAR_NEXT, m_nextEditor == NULL);
    }
    else
    {
        VFX_TRACE(("Text editor deactivated!\n"));
    }
}

void VappDefaultConfigPage::connectToSecurityAp()
{
    VfxChar* username;
    VfxChar* pwd;
    VfxWChar usernameUnicode[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    VfxWString pwdText = m_passwordTextInput->getText ();
    VfxU32     usernameLen = 0;
    VfxU32     pwdLen = pwdText.getLength ();

    VFX_ALLOC_MEM (username, SRV_DTCNT_PROF_MAX_USER_LEN + 1, this);
    VFX_ALLOC_MEM (pwd, SRV_DTCNT_PROF_MAX_PW_LEN + 1, this);
    memset(username, 0, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
    memset(pwd, 0, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
    memset(usernameUnicode, 0, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);

    if(m_userNameTextInput->getText ().getLength () > 0)
    {       
        memcpy(usernameUnicode, m_userNameTextInput->getTextBox ()->getText (), (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        mmi_chset_ucs2_to_utf8_string(
                (VfxU8 *)username,(SRV_DTCNT_PROF_MAX_USER_LEN + 1),(VfxU8 *)usernameUnicode);
        usernameLen = mmi_charset_ucs2_to_utf8_length_in_bytes((VfxU8 *)usernameUnicode);
    }
    else
    {
        memset(username, 0, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
        usernameLen = 0;
    }

    if(pwdLen < SRV_DTCNT_PROF_MAX_PW_LEN + 1)
        VappWlanToolbox::convertStrToAscii (pwd, pwdText, pwdLen);
    else
        VappWlanToolbox::convertStrToAscii (pwd, pwdText, SRV_DTCNT_PROF_MAX_PW_LEN);

    m_hiltProfile->setUserName ((const VfxU8*)username);
    m_hiltProfile->setPassword ((const VfxU8*)pwd);
    // Assign default EAP value to AP
    VappWlanToolbox::initAppProfileWithDefaultEapValue (m_hiltProfile);
    VFX_TRACE(("===> After EAP %d \n", m_hiltProfile->getEapAuthType ()));
    VFX_TRACE(("===> After PEAP %d \n", m_hiltProfile->getEapPeapAuthType ()));
    VFX_TRACE(("===> After TTLS %d \n", m_hiltProfile->getEapTtlsAuthType ()));
    VFX_TRACE(("Username: %s \t Password: %s\n", m_hiltProfile->getUserName (), m_hiltProfile->getPassword ()));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_DEFAULT_CONFIG, 
        usernameLen, pwdLen, m_hiltProfile->getEapAuthType (), m_hiltProfile->getEapPeapAuthType (), m_hiltProfile->getEapTtlsAuthType ());
    VFX_FREE_MEM (username);
    VFX_FREE_MEM (pwd);
        
    // Emit signal to inform its parent
    m_signalJoinNetwork.emit (VFX_TRUE, m_hiltProfile);
}
#endif /* WIFI_AUTH_PSK_ONLY */

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
/*******************************************************************************/
/* CLASS VappWAIPSKConfigPage */
/*******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWAIPSKConfigPage", VappWAIPSKConfigPage, VfxPage);

VappWAIPSKConfigPage::VappWAIPSKConfigPage()
{
    VFX_TRACE(("====Default constructor - VappWAIPSKConfigPage====\n"));
}

VappWAIPSKConfigPage::VappWAIPSKConfigPage(VappWlanProfile *profile) :
        m_waiPskStr(VFX_WSTR_EMPTY)
{
    VFX_TRACE(("====Constructor - VappWAIPSKConfigPage====\n"));
    VFX_OBJ_CREATE(m_hiltProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (profile, m_hiltProfile);
}
        
VappWAIPSKConfigPage::~VappWAIPSKConfigPage()
{
    VFX_TRACE(("====Deconstructor - VappWAIPSKConfigPage====\n"));
}


void VappWAIPSKConfigPage::onInit ()
{
    VFX_TRACE(("===== VappWAIPSKConfigPage initialization =====\n"));
    VappPropertyPage::onInit ();

    VFX_OBJ_CREATE (m_tempProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (m_hiltProfile, m_tempProfile);

    setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_CONN_TO_NETWORK));
    setTopBar (m_titleBar);

    // Tool Bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (WAI_PSK_CFG_FORM_TOOLBAR_JOIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_JOIN), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (WAI_PSK_CFG_FORM_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWAIPSKConfigPage::onToolBarClick);
    setBottomBar(m_toolBar);
    
    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(WAI_PSK_CFG_FORM_FUNC_BAR_JOIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_JOIN));
    m_functionBar->setItemSpecial (WAI_PSK_CFG_FORM_FUNC_BAR_JOIN);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (this, &VappWAIPSKConfigPage::onFuncBarBtnClick);
    
    // WAI PSK Format
    VFX_OBJ_CREATE(m_waiPskFormat, VcpFormItemBigButton, this);
    m_waiPskFormat->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAI_PSK_FORMAT));
    m_waiPskFormat->setHintText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_HEX));
    m_waiPskFormat->getButton ()->m_signalClicked.connect (
                                this, &VappWAIPSKConfigPage::onPropertyBtnClick);

    // Input password
    VFX_OBJ_CREATE(m_waiPskTextInput, VcpFormItemTextInput, this);
    m_waiPskTextInput->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAI_PSK));
    m_waiPskTextInput->setLabelPosition (VCPFORM_TOP_LEFT);
    VsrvInputBinding inputBind(
                        IMM_INPUT_TYPE_ASCII_PASSWORD,
                        0,
                        IME_INPUT_STYLE_NONE,
                        static_cast<InputConnection*>(m_waiPskTextInput->getTextBox ()->m_editing));
    inputBind.setAllowedChars (VFX_WSTR ("\'+\\\\_\\-.@!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9"));
    m_waiPskTextInput->getTextBox()->setIME (inputBind);
    m_waiPskTextInput->getTextBox()->setText(m_waiPskStr, SRV_DTCNT_WAPI_PSK_STR_LEN - 1);
    m_waiPskTextInput->getTextBox()->setFunctionBar (m_functionBar);
    // m_waiPskTextInput->getTextBox()->setAutoDeactivated (VFX_TRUE);
    
    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    // Append item into form
    m_form->addItem (m_waiPskFormat, WAI_PSK_CFG_FORM_FORMAT);
    m_form->addItem (m_waiPskTextInput, WAI_PSK_CFG_FORM_STRING);
}

void VappWAIPSKConfigPage::onDeinit ()
{
    VFX_OBJ_CLOSE(m_hiltProfile);
    
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_toolBar);
    VFX_OBJ_CLOSE(m_waiPskFormat);
    VFX_OBJ_CLOSE(m_waiPskTextInput);
    VFX_OBJ_CLOSE(m_form);

    VappPropertyPage::onDeinit ();
    VFX_TRACE(("===== VappWAIPSKConfigPage deinitialization =====\n"));
}

void VappWAIPSKConfigPage::onBack ()
{
    VFX_TRACE(("===================================================\n"));
    VFX_TRACE(("===== VappPasswordConfigPage onBack =====\n"));
    VFX_TRACE(("===================================================\n"));
    // Emit signal to inform its parent
    m_signalJoinNetwork.emit (VFX_FALSE, m_hiltProfile);
}

void VappWAIPSKConfigPage::onPropertyBtnClick (VfxObject *sender, VfxId id)
{
    m_propertyTypeEnum = WLAN_AP_PROPERTY_WAI_KEY_FORMAT;

    VappSelectPopupBuilder* selectPopupBuilder = NULL;
        
    VFX_OBJ_CREATE_EX (
        selectPopupBuilder, 
        VappSelectPopupBuilder, 
        this, 
        (m_propertyTypeEnum, m_tempProfile, getMainScr (), this));

    selectPopupBuilder->createSelectPopup ();

}

void VappWAIPSKConfigPage::onItemTapped (VfxU32 index)
{
    VFX_TRACE(("WAI PSK index - %d", index));

    m_tempProfile->setWapiPskFormat (VappWlanToolbox::getWaiKeyFormat (index));
    m_waiPskFormat->setHintText (VappWlanToolbox::getWaiKeyFormatStr (index));
}

void VappWAIPSKConfigPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
        case WAI_PSK_CFG_FORM_TOOLBAR_JOIN:
            connectToSecurityAp();
            break;
        case WAI_PSK_CFG_FORM_TOOLBAR_CANCEL:
            m_signalJoinNetwork.emit (VFX_FALSE, m_hiltProfile);
            break;
        default:
            break;
    }
}

void VappWAIPSKConfigPage::onFuncBarBtnClick (VfxObject* sender, VfxId id)
{
    m_waiPskTextInput->getTextBox ()->deactivate ();
    connectToSecurityAp();
}

void VappWAIPSKConfigPage::connectToSecurityAp()
{
    VfxBool isValid = VFX_FALSE;
    VfxChar wapiPsk[SRV_DTCNT_WAPI_PSK_STR_LEN];
    memset(wapiPsk, 0, SRV_DTCNT_WAPI_PSK_STR_LEN);
    
    VfxWString wapiPskText = m_waiPskTextInput->getText ();
    VfxU32     wapiPskLen  = wapiPskText.getLength ();

    if(wapiPskLen < SRV_DTCNT_WAPI_PSK_STR_LEN)
        VappWlanToolbox::convertStrToAscii (wapiPsk, wapiPskText, wapiPskLen);
    else
        VappWlanToolbox::convertStrToAscii (wapiPsk, wapiPskText, SRV_DTCNT_WAPI_PSK_STR_LEN - 1);
    m_hiltProfile->setWapiPskFormat(m_tempProfile->getWapiPskFormat());
    m_hiltProfile->setWapiPskStr ((const VfxU8 *)wapiPsk);


    if(0 == m_hiltProfile->getWapiPskFormat ())
    {
        if(VFX_FALSE == VappWlanToolbox::checkHexString((const VfxU8*)wapiPsk, wapiPskLen))
        {
            isValid = VFX_FALSE;
        }
        else
        {
            isValid = VFX_TRUE;
        }
    }
    else if(1 == m_tempProfile->getWapiPskFormat ())
    {
        if(VFX_FALSE == VappWlanToolbox::checkAsciiString((const VfxU8*)wapiPsk, wapiPskLen))
        {
            isValid = VFX_FALSE;
        }
        else
        {
            isValid = VFX_TRUE;
        }
    }

    if(isValid)
    {
        // Emit signal to inform its parent
        m_signalJoinNetwork.emit (VFX_TRUE, m_hiltProfile);
    }
    else
    {
        // VappWlanToolbox::showInvalidPopup (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INVALID_KEY), getMainScr ());
        m_hiltProfile->clearWapiPskStr ();
        // Clean incorrect WEP key string
        m_waiPskStr = VFX_WSTR_EMPTY;
        VfxS32 maxLen = m_waiPskTextInput->getTextBox ()->getMaxLength();
        m_waiPskTextInput->getTextBox ()->setText (m_waiPskStr, maxLen);
        m_waiPskTextInput->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INVALID_KEY));
    }

    
}

/*******************************************************************************/
/* CLASS VappWAICertConfigPage */
/*******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWAICertConfigPage", VappWAICertConfigPage, VfxPage);

VappWAICertConfigPage::VappWAICertConfigPage()
{
    // register page in the respository
	m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    m_repository->registerObserver (this);
    VFX_TRACE(("====Default constructor - VappWAICertConfigPage====\n"));
}

VappWAICertConfigPage::VappWAICertConfigPage(VappWlanProfile *profile) :
        m_waiPrivateKey(VFX_WSTR_EMPTY)
{
    VFX_TRACE(("====Constructor - VappWAICertConfigPage====\n"));
    VFX_OBJ_CREATE(m_hiltProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (profile, m_hiltProfile);
    
    m_tempWapiAseId = m_hiltProfile->getWapiAseId ();
    m_tempWapiClientId = m_hiltProfile->getWapiClientId ();
	
    // register page in the respository
	m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    m_repository->registerObserver (this);
}

VappWAICertConfigPage::~VappWAICertConfigPage()
{
    VFX_TRACE(("====Deconstructor - VappWAICertConfigPage====\n"));	
	// deregister page in the respository
	m_repository->removeObserver (this);

}

void VappWAICertConfigPage::onInit ()
{
    VFX_TRACE(("===== VappWAICertConfigPage initialization =====\n"));
    Observer::onInit ();
   
    // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_SELECT_ASE_MSG |
        SUBSCRIBE_SELECT_CLIENT_MSG);

    setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_CONN_TO_NETWORK));
    setTopBar (m_titleBar);

    // Tool Bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (WAI_CERT_CFG_FORM_TOOLBAR_JOIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_JOIN), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (WAI_CERT_CFG_FORM_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWAICertConfigPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(WAI_CERT_CFG_FORM_FUNC_BAR_JOIN, VFX_WSTR_RES(STR_ID_VAPP_WLAN_JOIN));
    m_functionBar->setItemSpecial (WAI_CERT_CFG_FORM_FUNC_BAR_JOIN);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (this, &VappWAICertConfigPage::onFuncBarBtnClick);

    // ASE certificates
    VFX_OBJ_CREATE(m_waiASECertSelector, VcpFormItemBigArrowButton, this);
    m_waiASECertSelector->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_ASE_CERT));
    m_waiASECertSelector->setHintText (VFX_WSTR_RES(STR_GLOBAL_NONE));
    m_waiASECertSelector->getButton ()->setId (WAI_CERT_CFG_FORM_ASE);
    m_waiASECertSelector->getButton ()->m_signalClicked.connect (
        this, &VappWAICertConfigPage::onPropertyBtnClick);

    // User certificates
    VFX_OBJ_CREATE(m_waiUserCertSelector, VcpFormItemBigArrowButton, this);
    m_waiUserCertSelector->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_USER_CERT));
    m_waiUserCertSelector->setHintText (VFX_WSTR_RES(STR_GLOBAL_NONE));
    m_waiUserCertSelector->getButton ()->setId (WAI_CERT_CFG_FORM_USER);
    m_waiUserCertSelector->getButton ()->m_signalClicked.connect (
        this, &VappWAICertConfigPage::onPropertyBtnClick);

    // Private key
    VFX_OBJ_CREATE(m_waiPrivateKeyTextInput, VcpFormItemTextInput, this);
    m_waiPrivateKeyTextInput->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_PRIVATE_KEY));
    m_waiPrivateKeyTextInput->setLabelPosition (VCPFORM_TOP_LEFT);
    m_waiPrivateKeyTextInput->getTextBox ()->setText(m_waiPrivateKey, SRV_DTCNT_PROF_MAX_PW_LEN + 1);//MAUI_03127784
    m_waiPrivateKeyTextInput->getTextBox ()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);    
    // m_waiPrivateKeyTextInput->getTextBox()->setAutoDeactivated (VFX_TRUE);
    m_waiPrivateKeyTextInput->getTextBox()->setFunctionBar (m_functionBar);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    // Append item into form
    m_form->addItem (m_waiASECertSelector, WAI_CERT_CFG_FORM_ASE);
    m_form->addItem (m_waiUserCertSelector, WAI_CERT_CFG_FORM_USER);
    m_form->addItem (m_waiPrivateKeyTextInput, WAI_CERT_CFG_FORM_PRIVATE_KEY);
}

void VappWAICertConfigPage::onDeinit ()
{
    VFX_OBJ_CLOSE(m_hiltProfile);
    
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_toolBar);
    VFX_OBJ_CLOSE(m_waiASECertSelector);
    VFX_OBJ_CLOSE(m_waiUserCertSelector);
    VFX_OBJ_CLOSE(m_waiPrivateKeyTextInput);
    VFX_OBJ_CLOSE(m_form);

    Observer::onDeinit ();
    VFX_TRACE(("===== VappWAICertConfigPage deinitialization =====\n"));
}

void VappWAICertConfigPage::onBack ()
{
    VFX_TRACE(("===================================================\n"));
    VFX_TRACE(("===== VappPasswordConfigPage onBack =====\n"));
    VFX_TRACE(("===================================================\n"));
    // Emit signal to inform its parent
    m_signalJoinNetwork.emit (VFX_FALSE, m_hiltProfile);
}

void VappWAICertConfigPage::UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{
    // if setting page is not in active status, return
    if(VFX_FALSE == getMainScr ()->isActive () || VFX_FALSE == isActive ())
    {
        return;
    }
	
    VfxWString  certName = VFX_WSTR_RES(STR_GLOBAL_NONE);
    VfxU8 wapiClientName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    VfxU8 wapiAseName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    
    VFX_TRACE(("===== Update VappWAICertConfigPage =====\n"));
    VFX_TRACE(("===== MSG: %d =====\n", msg));
    
    switch(msg)
    {
    case SUBSCRIBE_SELECT_ASE_MSG:
        m_tempWapiAseId = m_repository->getWapiAseId ();		
		memset(wapiAseName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        mmi_certman_get_cert_label(
            m_tempWapiAseId,
            wapiAseName,
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);			
		certName.loadFromMem ((const VfxWChar *) wapiAseName);
        m_waiASECertSelector->setHintText (certName);
        break;
    case SUBSCRIBE_SELECT_CLIENT_MSG:
        m_tempWapiClientId = m_repository->getWapiClientId ();
		memset(wapiClientName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);		
        mmi_certman_get_cert_label(
            m_tempWapiClientId,
            wapiClientName,
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    	certName.loadFromMem ((const VfxWChar *) wapiClientName);
        m_waiUserCertSelector->setHintText (certName);
        break;
    default:
        break;
    }
}


void VappWAICertConfigPage::onPropertyBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case WAI_CERT_CFG_FORM_ASE:
#ifdef __CERTMAN_SUPPORT__        
        VappWlanSentry::SendSelectASECertRequest(STR_ID_VAPP_WLAN_INPUT_WAPI_ASE_CERT);
#endif
        break;
    case WAI_CERT_CFG_FORM_USER:
#ifdef __CERTMAN_SUPPORT__        
        VappWlanSentry::SendSelectClientCertRequest(STR_ID_VAPP_WLAN_INPUT_WAPI_USER_CERT);
#endif
        break;
    default:
        break;
    }
}

void VappWAICertConfigPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
        case WAI_CERT_CFG_FORM_TOOLBAR_JOIN:
            connectToSecurityAp();
            break;
        case WAI_CERT_CFG_FORM_TOOLBAR_CANCEL:
            m_signalJoinNetwork.emit (VFX_FALSE, m_hiltProfile);
            break;
        default:
            break;
    }
}

void VappWAICertConfigPage::onFuncBarBtnClick (VfxObject* sender, VfxId id)
{
    // Close VK
    m_waiPrivateKeyTextInput->getTextBox ()->deactivate ();
    connectToSecurityAp();
}

void VappWAICertConfigPage::connectToSecurityAp()
{
    VfxChar waiPrivateKey[SRV_DTCNT_PROF_MAX_PW_LEN + 2];
    memset(waiPrivateKey, 0, SRV_DTCNT_PROF_MAX_PW_LEN + 2);
    
    VfxWString waiPrivateKeyText = m_waiPrivateKeyTextInput->getText ();
    VfxU32     waiPrivateKeyLen  = waiPrivateKeyText.getLength ();

    if(waiPrivateKeyLen < SRV_DTCNT_PROF_MAX_PW_LEN + 2)
        VappWlanToolbox::convertStrToAscii (waiPrivateKey, waiPrivateKeyText, waiPrivateKeyLen);
    else
        VappWlanToolbox::convertStrToAscii (waiPrivateKey, waiPrivateKeyText, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
    
    m_hiltProfile->setWapiAseId (m_tempWapiAseId);
    m_hiltProfile->setWapiClientId (m_tempWapiClientId);
    m_hiltProfile->setWapiPrivateKeyPasswdStr ((const VfxS8*)waiPrivateKey);

    VFX_TRACE(("WAPI Private key: %s!\n", waiPrivateKey));

    // Emit signal to inform its parent
    m_signalJoinNetwork.emit (VFX_TRUE, m_hiltProfile);
}
#endif /*__WAPI_SUPPORT__*/
#endif /*__MMI_HIDE_WAPI__*/

#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__

