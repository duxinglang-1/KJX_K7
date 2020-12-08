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
 *  vcui_dtcnt_wlan_ui.cpp
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
#include "vcui_dtcnt_wlan_ui.h"
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
 *                      CLASS   VcuiDtcntWlanCui
 *****************************************************************************/ 
VFX_IMPLEMENT_CLASS("VcuiDtcntWlanSetting", VcuiDtcntWlanSetting, VfxCui);
void VcuiDtcntWlanSetting::onRun(void * args,VfxU32 argSize)
{  
    VfxCui::onRun(args, argSize);

    VFX_OBJ_CREATE(m_wlanSettingScr, VappWlanMainScrn, this);
    m_wlanSettingScr->show();
}

void VcuiDtcntWlanSetting::onDeinit()
{
    VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_SETTING_CUI_CLOSE_DONE, repository->getWlanSettingCuiId());
    repository->setWlanSettingCuiId (0);
    
    VfxCui::onDeinit();
}

VappWlanMainScrn* VcuiDtcntWlanSetting::getWlanMainScreen(void)
{
    return m_wlanSettingScr;
}

/***************************************************************************** 
 *                      CLASS   VcuiDtcntWlanCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcuiDtcntWlanCui", VcuiDtcntWlanCui, VfxCui);

void VcuiDtcntWlanCui::onRun(void * args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);
    
    VFX_OBJ_CREATE(m_dtcntWlanScr, VcuiDtcntWlanScr, this);
    m_dtcntWlanScr->show();
}

void VcuiDtcntWlanCui::onDeinit()
{
    VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_CUI_CLOSE_DONE, repository->getWlanCuiId());

    repository->setWlanCuiId (0);

    VfxCui::onDeinit();    
}

//VFX_IMPLEMENT_CLASS("VcuiDtcntWlanScr", VcuiDtcntWlanScr, VfxAppScr);

VcuiDtcntWlanScr::VcuiDtcntWlanScr() :
    m_isScanCompleted(VFX_FALSE),    
    m_waitingPopup(NULL),   
    m_wlanSatellite(NULL),    
    m_repository(NULL),    
    m_inputScr(NULL),
    m_searchingPopup(NULL),   
    m_scrWeakPtr(NULL),
    m_pageWeakPtr(NULL),
    m_popupWeakPtr(NULL),
    m_apListPopup(NULL),
    m_menuWeakPtr(NULL),
    m_apNum(NULL)
{
	m_dir = VFX_SCR_ROTATE_TYPE_NORMAL;
    setIsSmallScreen ();
    m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
}

void VcuiDtcntWlanScr::onInit()
{
    VfxAppScr::onInit();
    
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
    setBgColor (VFX_COLOR_TRANSPARENT);
	
	// show confrim popup to turn off wifi tethering
	VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalInformWLAN.connect (
		this, &VcuiDtcntWlanScr::informWlanCui);
	
    VFX_TRACE(("=====================================\n"));
    VFX_TRACE(("====== Init   VcuiDtcntWlanScr=======\n"));
    VFX_TRACE(("=====================================\n"));
}

void VcuiDtcntWlanScr::onEnter (VfxBool isBackward)
{
	// keep screen rotate type
	VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
	m_dir = renderer->getPreScreenRotateType();

    if(isBackward == VFX_FALSE)
    {
        MMI_BOOL isTetheringOff;
        isTetheringOff = srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS);
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SWITCH_TETHERING_QRY, isTetheringOff);
        if(MMI_FALSE == isTetheringOff)
        {
			VcpConfirmPopup* turnOffConfirm = NULL;
			VFX_OBJ_CREATE (turnOffConfirm, VcpConfirmPopup, this);
            turnOffConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            turnOffConfirm->setCustomButton (
                VFX_WSTR_RES(STR_GLOBAL_OK), 
                VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            turnOffConfirm->setInfoType (VCP_POPUP_TYPE_QUESTION);
            turnOffConfirm->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_TURN_OFF_HOT_SPOT));
            turnOffConfirm->m_signalButtonClicked.connect (this, &VcuiDtcntWlanScr::onConfirmBtnClicked);
            turnOffConfirm->setAutoDestory(VFX_TRUE);
            turnOffConfirm->show (VFX_TRUE);
        }
        else
        {
            start();
        }
    }
}

void VcuiDtcntWlanScr::onDeinit()
{
    // Release
    end();
	VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalInformWLAN.disconnect(
		this, &VcuiDtcntWlanScr::informWlanCui);
    VfxAppScr::onDeinit ();
}

void VcuiDtcntWlanScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
	param.rotateTo = m_dir;
}

void VcuiDtcntWlanScr::onConfirmBtnClicked(VfxObject* sender, VfxId id)
{
	switch(id)
    {
    case VCP_CONFIRM_POPUP_BUTTON_USER_1://choose to close wlan hospot.
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
    case VCP_CONFIRM_POPUP_BUTTON_CANCEL://choose to open wlan hospot still. 		
		VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_CANNOT_DISPLAY, __LINE__);
		CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
        break;
    default:
        break;
    }
}

void VcuiDtcntWlanScr::onItemTapped (VcpMenuPopup* sender, VcpMenuPopupEventEnum evt, VcpMenuPopupItem* ap)
{
	VappWlanBaseInfo *baseInfo = NULL;
	VappWlanProfile  *hiltAp = NULL;	
	VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();

    switch(evt)
    {
    case VCP_MENU_POPUP_EVENT_ITEM_SELECTED:    // a menu item is selected
        // Send connect request to dtcnt service        
		baseInfo = apList[ap->getId ()];	
		VFX_OBJ_CREATE(hiltAp, VappWlanProfile, this);
		VappWlanToolbox::getAppProfileByAppBaseInfo(baseInfo, hiltAp);		
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_CONN_TO_AP, ap->getId (), hiltAp->getProfileId (), hiltAp->getSsidLen ());
        if(hiltAp) 
        {
            connectToAp(hiltAp);
        }
		else
		{	
			VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_SELECT_NONE, __LINE__);
			CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
		}
        break;
    case VCP_MENU_POPUP_EVENT_MENU_CANCEL:      // the menu is cancelled by click outside or the close button
        VFX_TRACE(("====================================\n"));
        VFX_TRACE(("CANCEL POPUP \n"));
        VFX_TRACE(("====================================\n"));
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_ABORT_CONN_CB);	
		VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_SELECT_CANCEL, __LINE__);
		CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
        break;
    case VCP_MENU_POPUP_EVENT_MENU_CLOSE:       // the menu is to be closed
        VFX_TRACE(("====================================\n"));
        VFX_TRACE(("CLOSE POPUP \n"));
        VFX_TRACE(("====================================\n"));
        break;
    }
}

void VcuiDtcntWlanScr::onAfterJoinNetwork(VfxBool isJoin, VappWlanProfile* network)
{
     // 1. Close input screen	
	if(m_scrWeakPtr.isValid())
	{
		VcuiWlanInputScr *tempScr = m_scrWeakPtr.get();
		if(tempScr->isShown ())
		{
		    tempScr->exit ();
        	tempScr = NULL;
		}
	}

	// 2. Show connecting popup if available
    if(isJoin && (network != NULL) )
    {
        VappWlanProfile* profile;    
        VFX_OBJ_CREATE (profile, VappWlanProfile, this);
        VappWlanToolbox::cloneWlanProfile (network, profile);

        showConnectingPopup(profile);

        //VFX_OBJ_CLOSE (profile);
    }
    else
    {
        showApListContextPopup();
    }

}

/*
void VcuiDtcntWlanScr::informDtcntService(srv_dtcnt_wlan_search_ap_open_rsp_enum action)
{
    srv_dtcnt_wlan_search_ap_open_ind_cb_func_ptr cbFunc = NULL;

    // For each event only inform service once
    cbFunc = m_repository->getApListCallbackFunc ();
    if(NULL != cbFunc)
    {
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_INFORM_DTCNT_SRV_RES, action);
        cbFunc(action);
        m_repository->setApListCallbackFunc (NULL);
    }
}
*/


void VcuiDtcntWlanScr::onNoApExistConfirm (VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case VCP_CONFIRM_POPUP_BUTTON_OK://click the button
		VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_NO_AP, __LINE__);
		CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
        break;
	case VCP_POPUP_BUTTON_NO_PRESSED://back key.  
    	//The function onItemTapped() will receiver backkey event.	
		CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
	    break;
    default:
        break;
    }
}

void VcuiDtcntWlanScr::onPopupSpecialKeyClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
        case VCP_POPUP_BUTTON_CANCEL_PRESSED://cancel key,back key.
            VFX_TRACE(("CANCEL BUTTON PRESSED!\n"));
            if(sender && m_searchingPopup && sender == m_searchingPopup
               && (m_isScanCompleted == VFX_FALSE))
            {
                VFX_TRACE(("SEARCHING POPUP!\n"));
                abortScanRequest(sender);
				
				VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_CANCEL_SEARCH, __LINE__);
				CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
            }
            break;
        default:
            break;
    }
}

void VcuiDtcntWlanScr::onWpaNoneConfirmBtnClick (VfxObject *sender, VfxId id)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_FAIL_CONFIRM_POPUP, id);
    switch(id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_OK://click the button.		
            VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_CHOOSE_AP_ONCE_AGAIN);
            showApListContextPopup();
			break;
		case VCP_POPUP_BUTTON_NO_PRESSED://back key.
			//The function onItemTapped() will receiver backkey event.
			CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
            break;
        default:
            break;
    }
}


/*
void VcuiDtcntWlanScr::onFailConfirmBtnClick (VfxObject *sender, VfxId id)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_FAIL_CONFIRM_POPUP, id);
    switch(id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
            VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_CHOOSE_AP_ONCE_AGAIN);
            showApListContextPopup();
            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
            VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_ABORT_CONN_CB);
            informDtcntService(SRV_DTCNT_WLAN_SEARCH_AP_OPEN_CANCEL);
            // close wifi ap list cui for caller
            vcui_wifi_ap_list_close(m_repository->getWlanCuiId ());
            break;
        default:
            break;
    }
}
*/

void VcuiDtcntWlanScr::afterStopTethering(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
    VFX_TRACE(("----------------------------\n"));
    VFX_TRACE(("After stop Wi-Fi Tethering!\n"));
    VFX_TRACE(("----------------------------\n"));
    VFX_OBJ_GET_INSTANCE(VappWlanRepository)->m_signalInformWLAN.postEmit(tethering_type, result, user_data);
}

void VcuiDtcntWlanScr::informWlanCui(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
    VFX_TRACE(("Inform application the result - %d!\n", result));
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
    	//wlan hospot stop success, and start AP list
        start();
    }
    else
    {
    	//user to close wlan hospot,but it cannot stop.
		VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_DISPLAY_FAIL, __LINE__);
		CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
    }
}

void VcuiDtcntWlanScr::abortScanRequest(VfxObject *sender)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_ABORT_SCAN_ACTION);
    // set abort scan request to dtcnt service
    VappWlanSentry::SendAbortScanRequest ();
    // exit popup
    if(m_searchingPopup != NULL)
    {
        m_searchingPopup->exit (VFX_TRUE);
        if(m_searchingPopup != NULL)
        {
            VFX_OBJ_CLOSE (m_searchingPopup);
            m_searchingPopup = NULL;
        }
    }
}

void VcuiDtcntWlanScr::connectToAp(VappWlanProfile* hiltAp)
{
	// Decide whether the AP is supported.
	if((SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == hiltAp->getNetworkType()) &&
		(SRV_DTCNT_WLAN_AUTH_MODE_TOTAL ==hiltAp->getAuthMode()))
	{
		VcpConfirmPopup *errorPopup = NULL;
		VFX_OBJ_CREATE (errorPopup, VcpConfirmPopup, this);
		errorPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
		errorPopup->setText(VFX_WSTR_RES(STR_GLOBAL_NOT_SUPPORTED));
		errorPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
		errorPopup->setAutoDestory(VFX_TRUE);
		errorPopup->show (VFX_TRUE);			
		return;
	}

    if(WLAN_AP_SEARCH == hiltAp->getApMatchType ())
    {
		if (SRV_DTCNT_WLAN_AUTH_MODE_OPEN == hiltAp->getAuthMode()) 
		{
			showConnectingPopup(hiltAp);
		}
        else
        {
			if(m_scrWeakPtr.isValid())
			{
				VcuiWlanInputScr *tempScr = m_scrWeakPtr.get();
				if(tempScr->isShown ())
				{
					tempScr->exit ();
					tempScr = NULL;
				}
			}
			
            VFX_OBJ_CREATE_EX (m_inputScr, VcuiWlanInputScr, getApp (), (hiltAp));
            m_inputScr->m_signalAfterInput.connect(this, &VcuiDtcntWlanScr::onAfterJoinNetwork);
            m_inputScr->show ();
			m_scrWeakPtr = m_inputScr;
        }
    }
    else
    {
        showConnectingPopup(hiltAp);
    }
}

void VcuiDtcntWlanScr::showConnectingPopup(VappWlanProfile* hiltAp)
{
    // Set the connect flag
	hiltAp->setConnType (ONE_PROFILE_SELECT);
    m_repository->setApToBeActivated(hiltAp);
					
#ifdef __MMI_OP01_WIFI__
	entryCMCCConnectProcByCui();
#else
	VappWlanSentry::SendConnectRequest ();
	VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_CHOOSE_ONE, __LINE__);
	CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_OK);
#endif
}

void VcuiDtcntWlanScr::showApListContextPopup()
{
    VfxResId resId;
    VfxImageSrc imageSrc;
    VfxWString description = VFX_WSTR_EMPTY;

	m_apNum = m_repository->getUsefulApNum ();
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_SHOW_AP_LIST, m_apNum);
    if(m_apNum == 0)
    {   
    	VcpConfirmPopup* noApConfirmPopup = NULL;
        VFX_OBJ_CREATE (noApConfirmPopup, VcpConfirmPopup, this);
        noApConfirmPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
        noApConfirmPopup->setText(VFX_WSTR_RES(STR_ID_VCUI_WLAN_NO_AVAILABLE_AP));
        noApConfirmPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        noApConfirmPopup->setAutoDestory(VFX_TRUE);
        noApConfirmPopup->m_signalButtonClicked.connect (this, &VcuiDtcntWlanScr::onNoApExistConfirm);
        noApConfirmPopup->show (VFX_TRUE);
        return;
    }
    
    VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();

    VFX_OBJ_CREATE(m_apListPopup, VcpMenuPopup, this);
    m_apListPopup->setTitle (VFX_WSTR_RES(STR_ID_VCUI_WLAN_TITLE));
    m_apListPopup->setIsAutoCancel (VFX_FALSE);
    m_apListPopup->setIsAutoClose (VFX_TRUE);
    m_apListPopup->m_signalMenuCallback.connect(
                        this, &VcuiDtcntWlanScr::onItemTapped);
    m_menuWeakPtr = m_apListPopup;
    
    for(VfxS8 index = 0; index < m_apNum; index++)
    {
        resId = apList[index]->getNetworkTypeIcon ();
        if(0 != resId)
        {
            imageSrc = VfxImageSrc(resId);
        }
        else
        {
            imageSrc = VFX_IMAGE_SRC_NULL;
        }
        
        m_apListPopup->addItem (
            index,
            VfxWString().loadFromMem ((const VfxWChar *)apList[index]->getApName ()),
            imageSrc);

        VFX_TRACE(("Add profile - ID: %d SSID: %s Priority: %d\n", 
            apList[index]->getProfileId (), apList[index]->getSsid (), apList[index]->getPriority ()));
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_ADD_PROFILE_INTO_AP_LIST, 
            apList[index]->getProfileId (), apList[index]->getSsidLen (), apList[index]->getPriority ());
    }

    m_apListPopup->show (VFX_TRUE);
    VFX_TRACE(("====================================\n"));
    VFX_TRACE(("SHOW AP SELECTIONG LIST END\n"));
    VFX_TRACE(("====================================\n"));
}

void VcuiDtcntWlanScr::refreshAplist()
{
    VfxResId resId;
    VfxImageSrc imageSrc;
    VfxWString description = VFX_WSTR_EMPTY;
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_SHOW_AP_LIST, m_repository->getUsefulApNum ());
    if(m_repository->getUsefulApNum () == 0)
    {   
    	VcpConfirmPopup* noApConfirmPopup = NULL;
        VFX_OBJ_CREATE (noApConfirmPopup, VcpConfirmPopup, this);
        noApConfirmPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
        noApConfirmPopup->setText(VFX_WSTR_RES(STR_ID_VCUI_WLAN_NO_AVAILABLE_AP));
        noApConfirmPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        noApConfirmPopup->setAutoDestory(VFX_TRUE);
        noApConfirmPopup->m_signalButtonClicked.connect (this, &VcuiDtcntWlanScr::onNoApExistConfirm);
        noApConfirmPopup->show (VFX_TRUE);
        return;
    }
	
	for(VfxS8 index = 0; index < m_apNum; index++)
    {
    	m_apListPopup->removeItem(m_apListPopup->getItemById(index));
	}
	
    VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();		
	for(VfxS8 index = 0; index < m_repository->getUsefulApNum (); index++)
    {
        resId = apList[index]->getNetworkTypeIcon ();
        if(0 != resId)
        {
            imageSrc = VfxImageSrc(resId);
        }
        else
        {
            imageSrc = VFX_IMAGE_SRC_NULL;
        }
        
        m_apListPopup->addItem (
            index,
            VfxWString().loadFromMem ((const VfxWChar *)apList[index]->getApName ()),
            imageSrc);

        VFX_TRACE(("Add profile - ID: %d SSID: %s Priority: %d\n", 
            apList[index]->getProfileId (), apList[index]->getSsid (), apList[index]->getPriority ()));
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_ADD_PROFILE_INTO_AP_LIST, 
            apList[index]->getProfileId (), apList[index]->getSsidLen (), apList[index]->getPriority ());
    }
    m_apListPopup->onUpdate();
}

void VcuiDtcntWlanScr::start()
{
    // 1. Create one observer to subscribe relevant event
    VFX_OBJ_CREATE_EX (
            m_wlanSatellite, 
            VcuiWlanSatellite, 
            this, 
            (m_repository));
    m_wlanSatellite->m_signalReceiveDtcntMsg.connect (this, &VcuiDtcntWlanScr::run);
	m_pageWeakPtr = m_wlanSatellite;
    
    // 2. Start to search networks
    VFX_OBJ_CREATE (m_searchingPopup, VcpIndicatorPopup, this);
    m_searchingPopup->setInfoType (VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    m_searchingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_SEARCHING));
    m_searchingPopup->m_signalButtonClicked.connect (this, &VcuiDtcntWlanScr::onPopupSpecialKeyClick);
    m_searchingPopup->setAutoDestory(VFX_FALSE);
    m_searchingPopup->show (VFX_TRUE);
    m_popupWeakPtr = m_searchingPopup ;
	
    VappWlanSentry::SendScanRequest ();
    // 3. Wait for notification
}

void VcuiDtcntWlanScr::run(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{
    VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);

    VFX_TRACE(("===== Update page VcuiDtcntWlanScr =====\n"));
    VFX_TRACE(("===== MSG: %d =====\n", msg));
    switch(msg)
    {
    case SUBSCRIBE_SCAN_MSG:          /* scan event */
        if(SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS == repository->getScanRresult ())
        {
            VFX_TRACE(("===== Show AP list =====\n"));
            showApListContextPopup();
        }
        else if(SRV_DTCNT_WLAN_SCAN_RESULT_ABORTED == repository->getScanRresult ())
        {      
            return;
        }
        /* close searching popup */
        if(NULL != m_searchingPopup )
        {
            m_isScanCompleted = VFX_TRUE;     /* set flag */
            if(m_searchingPopup != NULL)
            {
                m_searchingPopup->exit (VFX_TRUE);
                if(m_searchingPopup != NULL)
                {
                    VFX_OBJ_CLOSE (m_searchingPopup);
                    m_searchingPopup = NULL;
                }
            }
        }
        break;
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:       /* connect event */
		//VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_CONN_SUCCESS, __LINE__);
		//CuiSendEventToApp( EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_OK);
        break;
    case SUBSCRIBE_CONNECT_FAIL_MSG:
        break;    
    case SUBSCRIBE_DISCONNECT_MSG:    /* disconnect event */
        // TODO: Refresh ap list screen
        refreshAplist();
        break;
	case SUBSCRIBE_DEINIT_MSG:	  /* disconnect event */
		//VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_NEED_CLOSE, __LINE__);
		//CuiSendEventToApp( EVT_ID_VCUI_WLAN_LIST_EVENT_CLOSE );	
		break;		
    default:
        break;
    }    
}

void VcuiDtcntWlanScr::end()
{
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

	if(m_pageWeakPtr.isValid())
	{
		VcuiWlanSatellite *tempPage = m_pageWeakPtr.get();				
        VFX_OBJ_CLOSE (tempPage);
    }

	if(m_scrWeakPtr.isValid())
	{
		VcuiWlanInputScr *tempScr = m_scrWeakPtr.get();				
        VFX_OBJ_CLOSE (tempScr);
    }
		
	if(m_popupWeakPtr.isValid())
	{
		VcpIndicatorPopup *tempPopup = m_popupWeakPtr.get(); 			
		VFX_OBJ_CLOSE (tempPopup);
	}

    if(m_menuWeakPtr != NULL)
    {
		VcpMenuPopup *tempPopup = m_menuWeakPtr.get(); 			
		VFX_OBJ_CLOSE (tempPopup);
    }    
}

void VcuiDtcntWlanScr::CuiSendEventToApp(VCUI_WLAN_AP_LIST_EVENT_ENUM evt_id)
{
	if( 0 != m_repository->getWlanCuiId ())
	{
		vcui_wlan_list_event_struct evt;
		VcuiDtcntWlanCui *Cui;
		evt.sender_id = m_repository->getWlanCuiId ();
		MMI_FRM_INIT_GROUP_EVENT(&evt, evt_id, m_repository->getWlanCuiId ());
		Cui = (VcuiDtcntWlanCui *)VfxApp::getObject(m_repository->getWlanCuiId ());
		Cui->sendToCaller((mmi_group_event_struct*)&evt);
	}
}

#ifdef __MMI_OP01_WIFI__
VfxBool VcuiDtcntWlanScr::VerifyNetWorkStatus()
{
	MMI_BOOL isAutoAuth = vapp_dtcnt_wlan_is_auto_auth();

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_CURRENT_STATUS,
			m_repository->getWlanUiFlow (), srv_dtcnt_wlan_status(), isAutoAuth);  
	
    if((WLAN_UI_DISC_AFTER_LOGIN_FAILED == m_repository->getWlanUiFlow ()) ||
	    ((WLAN_UI_WAIT_FOR_IP_UPDATE == m_repository->getWlanUiFlow ()) &&
	   	(MMI_TRUE == isAutoAuth)))
    {
    	VcpConfirmPopup * invalidInputPopup;
        VFX_OBJ_CREATE (invalidInputPopup, VcpConfirmPopup, this);
        invalidInputPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
        invalidInputPopup->setText(VFX_WSTR_RES(STR_GLOBAL_BUSY_TRY_LATER));
        invalidInputPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        invalidInputPopup->setAutoDestory(VFX_TRUE);
        invalidInputPopup->show (VFX_TRUE);
        return VFX_FALSE;
    }	
	return VFX_TRUE;
}

void VcuiDtcntWlanScr::entryCMCCConnectProcByCui ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_CONN_PROC_BY_CUI); 
	
	if(VFX_FALSE == VerifyNetWorkStatus())
	{
		CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL);
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
        VappWlanCMCCMgr::entryCMCCPortalCertLogoutStart ();
    }
	else
	{	
	    if(ONE_PROFILE_SELECT == m_repository->getApToBeActivated()->getConnType())
    	{    	
			VappWlanSentry::SendConnectRequest ();
	    }
	}
	VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_CHOOSE_ONE, __LINE__);
	CuiSendEventToApp(EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_OK);
}
#endif

//VFX_IMPLEMENT_CLASS("VcuiWlanInputScr", VcuiWlanInputScr, VfxMainScr);

VcuiWlanInputScr::VcuiWlanInputScr() :
    m_ap(NULL)
{

}

VcuiWlanInputScr::VcuiWlanInputScr(VappWlanProfile* hiltAp) :
    m_ap(hiltAp)
 {
    VFX_TRACE(("==========================================\n"));
    VFX_TRACE(("===== VcuiWlanInputScr Constructor! =====\n"));
    VFX_TRACE(("==========================================\n"));
}

void VcuiWlanInputScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
	// doNothing
}

void VcuiWlanInputScr::on1stReady()
{
    VfxMainScr::on1stReady ();

    // setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
    // setBgColor (VFX_COLOR_TRANSPARENT);

    inputSecurityInfo();
    
    VFX_TRACE(("==========================================\n"));
    VFX_TRACE(("===== VcuiWlanInputScr Ready! =====\n"));
    VFX_TRACE(("==========================================\n"));
}

void VcuiWlanInputScr::inputSecurityInfo()
{
	srv_dtcnt_wlan_network_type_enum networkType = m_ap->getNetworkType();
	srv_dtcnt_wlan_auth_mode_enum authMode = m_ap->getAuthMode();
	VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_UI_INPUT_SECURITY_INFO, networkType, authMode);
  
	if(SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == networkType)
	{ 
		if(SRV_DTCNT_WLAN_AUTH_MODE_OPEN == authMode)
		{
			m_signalAfterInput.emit(VFX_TRUE, m_ap);
		}
		else //WPA_NONE or WEP
		{		
			VappPasswordConfigPage* pwdConfigPage = NULL;
			VFX_OBJ_CREATE_EX (pwdConfigPage, VappPasswordConfigPage, this, (m_ap));
			pwdConfigPage->m_signalJoinNetwork.connect (this, &VcuiWlanInputScr::onJoinNetwork);
			pushPage (0, pwdConfigPage);
		}
	}
	else if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == networkType)
	{	
		if(SRV_DTCNT_WLAN_AUTH_MODE_OPEN == authMode)
		{
			m_signalAfterInput.emit(VFX_TRUE, m_ap);
		}		
#ifndef  WIFI_AUTH_PSK_ONLY
		else if(SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY == authMode ||
			SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY == authMode)
		{		
			VappDefaultConfigPage* defaultConfigPage = NULL;
            VFX_OBJ_CREATE_EX (defaultConfigPage, VappDefaultConfigPage, this, (m_ap));
            defaultConfigPage->m_signalJoinNetwork.connect (this, &VcuiWlanInputScr::onJoinNetwork);
            pushPage (0, defaultConfigPage);
		}
#endif	/* WIFI_AUTH_PSK_ONLY */
		else if(SRV_DTCNT_WLAN_AUTH_MODE_WEP == authMode ||
			SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK == authMode ||
			SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK == authMode)
		{		
			VappPasswordConfigPage* pwdConfigPage = NULL;
			VFX_OBJ_CREATE_EX (pwdConfigPage, VappPasswordConfigPage, this, (m_ap));
			pwdConfigPage->m_signalJoinNetwork.connect (this, &VcuiWlanInputScr::onJoinNetwork);
			pushPage (0, pwdConfigPage);
		}
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    	else if(SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK == authMode)
    	{
            VappWAIPSKConfigPage* waiPskConfigPage = NULL;
            VFX_OBJ_CREATE_EX (waiPskConfigPage, VappWAIPSKConfigPage, this, (m_ap));
            waiPskConfigPage->m_signalJoinNetwork.connect (this, &VcuiWlanInputScr::onJoinNetwork);
            pushPage (0, waiPskConfigPage);
        }
        else if(SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT == authMode)
        {
            VappWAICertConfigPage* waiCertConfigPage = NULL;
            VFX_OBJ_CREATE_EX (waiCertConfigPage, VappWAICertConfigPage, this, (m_ap));
            waiCertConfigPage->m_signalJoinNetwork.connect (this, &VcuiWlanInputScr::onJoinNetwork);
            pushPage (0, waiCertConfigPage);
        }
#endif  /* __MMI_HIDE_WAPI__ */
#endif
	}	
}

void VcuiWlanInputScr::onJoinNetwork(VfxBool isJoin, VappWlanProfile* network)
{
    m_signalAfterInput.emit(isJoin, network);
}

//VFX_IMPLEMENT_CLASS ("VcuiWlanSatellite", VcuiWlanSatellite, VfxPage);

VcuiWlanSatellite::VcuiWlanSatellite() : 
    m_repository(NULL)
{
	// register page in the respository
	m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
	m_repository->registerObserver (this);
}

VcuiWlanSatellite::VcuiWlanSatellite(VappWlanRepository *repository) : 
    m_repository(repository)
{
    VFX_TRACE(("==========================================\n"));
    VFX_TRACE(("===== VcuiWlanSatellite Constructor! =====\n"));
    VFX_TRACE(("==========================================\n"));
    // register page in the respository
    m_repository->registerObserver (this);
}

VcuiWlanSatellite::~VcuiWlanSatellite()
{
    // deregister page in the respository
    m_repository->removeObserver (this);
    VFX_TRACE(("==========================================\n"));
    VFX_TRACE(("===== VcuiWlanSatellite Deconstructor! =====\n"));
    VFX_TRACE(("==========================================\n"));

}

void VcuiWlanSatellite::onInit ()
{
    VFX_TRACE(("===== Init VcuiWlanSatellite =====\n"));
    Observer::onInit ();
    
    // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_SCAN_MSG | 
        SUBSCRIBE_CONNECT_SUCCESS_MSG | 
        SUBSCRIBE_DISCONNECT_MSG | 
        SUBSCRIBE_CONNECT_FAIL_MSG |
        SUBSCRIBE_DEINIT_MSG
        );
}

void VcuiWlanSatellite::UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{
    VFX_TRACE(("===== MSG: %d =====\n", msg));
    m_signalReceiveDtcntMsg.postEmit (msg);
}

#ifdef __cplusplus
extern "C" {
#endif

    mmi_id vcui_wifi_ap_list_create(mmi_id parent_gid, void *user_data)
    {
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_CREATE_AP_LIST_START);
        VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
/*
#ifdef __FLIGHT_MODE_SUPPORT__    
		// query the status of switching flight mode
    	MMI_BOOL switching = srv_mode_switch_is_switching ();
    	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_RSP, switching);
		// Not to change during switching flight mode
		if((MMI_TRUE == switching) || (srv_mode_switch_is_network_service_available() == MMI_FALSE))
		{
			VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AP_LIST_NO_FLIGHT_MODE, __LINE__);
		 	return GRP_ID_INVALID;
		}
#endif
*/
    	// Not to change during switching wlan tethering
    	if(VappWlanToolbox::isTetheringInSwitching ())
    	{
        	return GRP_ID_INVALID;
    	}
    
    	// Not to change during switching flight mode
    	if(VappWlanToolbox::isFlightModeOn ())
    	{
        	return GRP_ID_INVALID;
    	}	
		
        // Use the way of lanuching application instead of creating CUI
        /* mmi_id cui_id  = VfxAppLauncher::launch( 
                                            VCUI_DATA_ACCOUNT_WLAN,
                                            VFX_OBJ_CLASS_INFO(VcuiDtcntWlanCui),
                                            parent_gid);*/
        
        mmi_id cui_id = VfxAppLauncher::createCui(
                                            VCUI_DATA_ACCOUNT_WLAN,
                                            VFX_OBJ_CLASS_INFO(VcuiDtcntWlanCui),
                                            parent_gid,
                                            NULL, 
                                            0); 
        repository->setWlanCuiId (cui_id);
        VFX_TRACE(("===== Set wlan CUI id as %d =====\n", repository->getWlanCuiId ()));
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_CREATE_AP_LIST_END, parent_gid, cui_id);
        return cui_id;
    }

    void vcui_wifi_ap_list_run(mmi_id cui_gid)
    {
    	VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_RUN_AP_LIST_START, cui_gid);
    	VfxAppLauncher::runCui(cui_gid);
    	VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_RUN_AP_LIST_END);
    }

    void vcui_wifi_ap_list_close(mmi_id cui_gid)
    {
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_CLOSE_AP_LIST_START, cui_gid);
        VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        if(repository->getWlanCuiId () != 0)
        {
        	repository->setWlanCuiId (0);
            VfxAppLauncher::terminate(cui_gid);           
        }
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_CLOSE_AP_LIST_END);
    }

    U32 vcui_wlan_auto_conn_networks(vcui_wlan_auto_conn_cb_func_ptr cb)
    {
        VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_CB_FUNC, cb != NULL , __LINE__);
        repository->autoConnStart(cb);
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_SCAN_ID);            
        return repository->getScanJobId ();
    }
	
	void vapp_wlan_send_cmcc_deinit()
	{	
#ifdef __MMI_OP01_WIFI__
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_DEINIT_PROC_BY_WIDGET); 
        VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
		MMI_BOOL isAutoAuth = vapp_dtcnt_wlan_is_auto_auth();
	
    	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_CURRENT_STATUS,
				repository->getWlanUiFlow (), srv_dtcnt_wlan_status(), isAutoAuth);  

    	if((WLAN_UI_PORTAL_LOGOUT != repository->getWlanUiFlow ()) &&  /* not in the logout proc */
       		(SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
			SRV_DTCNT_WLAN_AP_DEFAULT == repository->getConnectedAP()->getApMgrType())
    	{  	
    		repository->setActionAfterLogout(WLAN_AP_CMCC_LOGOUT_DEINIT);		
        	VappWlanCMCCMgr::entryCMCCPortalCertLogoutStart ();
    	}
		else
		{		
			VappWlanSentry::SendDeinitRequest ();
		}		
#endif /* __MMI_OP01_WIFI__ */
	}
	
    mmi_id vcui_dtcnt_wlan_setting_create(mmi_id parent_gid, void *user_data)
    {
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_SETTING_CUI_CREATE_START);
        VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        
        mmi_id cui_id = VfxAppLauncher::createCui(
                                            VCUI_DATA_ACCOUNT_WLAN_SETTING,
                                            VFX_OBJ_CLASS_INFO(VcuiDtcntWlanSetting),
                                            parent_gid,
                                            user_data,
                                            sizeof(user_data));
                                            
        repository->setWlanSettingCuiId (cui_id);
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_SETTING_CUI_CREATE_END, parent_gid, cui_id);
        return cui_id;
    }

    void vcui_dtcnt_wlan_setting_run(mmi_id cui_gid)
    {
        VfxAppLauncher::runCui(cui_gid);
    }


    void vcui_dtcnt_wlan_setting_close(mmi_id cui_gid)
    {
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_SETTING_CUI_CLOSE_START, cui_gid);
        VappWlanRepository *repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        if(cui_gid != 0)
        {
        	repository->setWlanSettingCuiId (0);
            VfxAppLauncher::terminate(cui_gid);           
        }
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_SETTING_CUI_CLOSE_END);
    } 
    
#ifdef __cplusplus
}
#endif

#endif  // __MMI_WLAN_FEATURES__
#endif  // __TCP_IP__
