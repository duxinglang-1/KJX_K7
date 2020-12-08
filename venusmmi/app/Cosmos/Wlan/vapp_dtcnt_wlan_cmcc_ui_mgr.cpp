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
 *  vapp_dtcnt_wlan_cmcc_ui_mgr.cpp
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
#include "vapp_dtcnt_wlan_ui.h"
#include "vapp_dtcnt_wlan_cmcc_ui.h"
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
// VFX_IMPLEMENT_CLASS ("VappCMCCNetworkMgrPage", VappCMCCNetworkMgrPage, VfxPage);
VappCMCCNetworkMgrPage::VappCMCCNetworkMgrPage(VappWlanRepository *repository) : 
    m_repository(repository),
	m_menuPopup(NULL),
	m_editProfile(NULL),
	m_tempProfile(NULL),
	m_longTapApId(NULL)
{
    // register page in the respository
    m_repository->registerObserver (this);
}
    
VappCMCCNetworkMgrPage::~VappCMCCNetworkMgrPage()
{
    // deregister page in the respository
    m_repository->removeObserver (this);
}

void VappCMCCNetworkMgrPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_INIT_MANAGER_PAGE);
    Observer::onInit ();

    // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_CONNECT_SUCCESS_MSG |
        SUBSCRIBE_DISCONNECT_MSG |
        SUBSCRIBE_SCAN_MSG |
		SUBSCRIBE_CONNECT_FAIL_MSG);
    
    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_MAIN_TEXT));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (TOOLBAR_REMEMBERED_NETWORK, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_REMEMBERED_NETWORK), IMG_ID_VAPP_WLAN_REMEMBER_NETWORK);
    m_toolBar->addItem (TOOLBAR_BLOCKED_NETWORK, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_BLOCKED_NETWORK), IMG_ID_VAPP_WLAN_BLOCK_NETWORK);
    m_toolBar->m_signalButtonTap.connect (this, &VappCMCCNetworkMgrPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Networks list menu
    VFX_OBJ_CREATE (m_networksListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX (m_contentProvider, CMCCNetWorkMgrContentProvider, this, (m_repository));
    m_contentProvider->setMenu (m_networksListMenu);
    m_networksListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_networksListMenu->setContentProvider (m_contentProvider);
    m_networksListMenu->setPos(0, 0);
    m_networksListMenu->setSize(getSize());
    m_networksListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_networksListMenu->m_signalItemTapped.connect (
                                this, &VappCMCCNetworkMgrPage::onItemTapped);
    m_networksListMenu->m_signalItemLongTapped.connect (
            					this, &VappCMCCNetworkMgrPage::onLongItemTapped);
}

void VappCMCCNetworkMgrPage::onEnter(VfxBool isBackward)
{
    if(isBackward)
    {
		m_networksListMenu->resetAllItems ();
    }
    else
    {

    }
}

void VappCMCCNetworkMgrPage::onDeinit ()
{  	
	if( m_popupWeakPtr.isValid())
	{
		VcpMenuPopup *tempPopup = m_popupWeakPtr.get(); 
		VFX_OBJ_CLOSE (tempPopup);
	}

    Observer::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_DEINIT_MANAGER_PAGE);
}

void VappCMCCNetworkMgrPage::UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{   
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_UPDATE_MANAGER_PAGE, msg);
    switch(msg)
    {
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:         /* connect event */
    case SUBSCRIBE_DISCONNECT_MSG:              /* disconnect event */
	case SUBSCRIBE_SCAN_MSG:					/* scan event */
	case SUBSCRIBE_CONNECT_FAIL_MSG:            /* connect fail event */		
	case SUBSCRIBE_CONNECT_REQUEST_MSG:		    /* Connect request event */  
	case SUBSCRIBE_BEARER_STATUS_MSG:	
		// close menuPopup
		if( m_popupWeakPtr.isValid())
		{
			VcpMenuPopup *tempPopup = m_popupWeakPtr.get(); 
			VFX_OBJ_CLOSE (tempPopup);
		}
		// if Conn num isn't 0
		if( m_repository->getAPConnNum() != 0 )
		{
			VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);				
		}
        m_networksListMenu->resetAllItems ();
        break;
    default:
        break;
    }
}

void VappCMCCNetworkMgrPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    VappRememberedNetworkPage* RememberedNetworkPage = NULL;
	VappBlockedNetworkPage* BlockedNetworkPage = NULL;
    
    switch(id)
    {
        case TOOLBAR_REMEMBERED_NETWORK:
            VFX_OBJ_CREATE_EX (
                RememberedNetworkPage, 
                VappRememberedNetworkPage, 
                getMainScr (), 
                (m_repository));
            getMainScr()->pushPage(0, RememberedNetworkPage);      
            break;
        case TOOLBAR_BLOCKED_NETWORK:
            VFX_OBJ_CREATE_EX (
                BlockedNetworkPage, 
                VappBlockedNetworkPage, 
                getMainScr (), 
                (m_repository));
            getMainScr()->pushPage(0, BlockedNetworkPage);
            break;
        default:
            break;
    }
}

void VappCMCCNetworkMgrPage::onItemTapped(VcpListMenu *sender, VfxU32 id)
{
    VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();
	
    // If the ap is in use or the ap is default network, then give a prompt 
	if(VFX_FALSE == IsAllowEditPopup(apList[id]))
	{
		return;
	}
		
 	VappWlanProfile *hiltProfile = NULL;
	VFX_OBJ_CREATE(hiltProfile, VappWlanProfile, this);
	VappWlanToolbox::getAppProfileByAppBaseInfo(apList[id], hiltProfile); 
	
    // set flag
    m_repository->setIsInsert (VFX_FALSE);

    VappEditProfilePage* editProfilePage = NULL;
    VFX_OBJ_CREATE_EX (
        editProfilePage, 
        VappEditProfilePage, 
        getMainScr (), 
        (hiltProfile, m_repository));
    getMainScr()->pushPage(0, editProfilePage);
}

void VappCMCCNetworkMgrPage::onLongItemTapped(VcpListMenu *sender, VfxU32 id)
{
	// if Conn num isn't 0 ,LongTap AP can't do nothing
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		return;			
	}

    VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray ();
	
	// If the ap is in use or the ap is default network, then give a prompt 
	if(VFX_FALSE == IsAllowEditPopup(apList[id]))
	{
		return;
	}

	// create edit profile and set it as copy of ap which is edited
    VFX_OBJ_CREATE (m_editProfile, VappWlanProfile, this);	
	VappWlanToolbox::getAppProfileByAppBaseInfo(apList[id], m_editProfile); 
	// create temp profile to edit
    VFX_OBJ_CREATE (m_tempProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (m_editProfile, m_tempProfile);
	// get the longTapApId
	m_longTapApId = id;
	
	switch( m_editProfile->getApMgrType() )
	{
	case SRV_DTCNT_WLAN_AP_DEFAULT:
		return;
    case SRV_DTCNT_WLAN_AP_BLACK_LIST:
    case SRV_DTCNT_WLAN_AP_END:
		VFX_ASSERT(NULL);
	default:
		break;
	}

    VFX_OBJ_CREATE (m_menuPopup, VcpMenuPopup, this);
    m_menuPopup->setTitle( VFX_WSTR_MEM((const VfxWChar *)m_editProfile->getApName()) );
	if(SRV_DTCNT_WLAN_AP_UNKNOW == m_editProfile->getApMgrType())
	{
    	m_menuPopup->addItem(MENU_POPUP_REMEMBER_NETWORK, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_REMEMBERED_NETWORK));
	}
	else if(SRV_DTCNT_WLAN_AP_USER_DEFINE == m_editProfile->getApMgrType())
	{
    	m_menuPopup->addItem(MENU_POPUP_FORGET_NETWORK, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_FORGET_NETWORK));
	}
    m_menuPopup->addItem(MENU_POPUP_BLOCK_NETWORK, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_BLOCKED_NETWORK));	
    m_menuPopup->m_signalMenuCallback.connect(this, &VappCMCCNetworkMgrPage::onMenuPopupTapped);
    m_menuPopup->setIsAutoClose (VFX_TRUE);	
    m_menuPopup->setIsAutoCancel (VFX_FALSE);
    m_menuPopup->show(VFX_TRUE);

	m_popupWeakPtr = m_menuPopup;
}		

void VappCMCCNetworkMgrPage::onMenuPopupTapped(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item)
{
    if( event != VCP_MENU_POPUP_EVENT_ITEM_SELECTED )
    {
    	return;
    }
	
	switch( item->getId() )
	{
	case MENU_POPUP_REMEMBER_NETWORK:
		// Decide whether the AP is supported.
		if((SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == m_editProfile->getNetworkType()) &&
			(SRV_DTCNT_WLAN_AUTH_MODE_TOTAL ==m_editProfile->getAuthMode()))
		{
	        VcpConfirmPopup *notEditConfirm;
	        VFX_OBJ_CREATE (notEditConfirm, VcpConfirmPopup, getMainScr ());
	        notEditConfirm->setInfoType (VCP_POPUP_TYPE_WARNING);
	        notEditConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVLALID_AUTH_MODE));
	        notEditConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
	        notEditConfirm->setAutoDestory(VFX_TRUE);
	        notEditConfirm->show (VFX_TRUE);
	        break;
	    }
		m_tempProfile->setApMgrType( SRV_DTCNT_WLAN_AP_USER_DEFINE  );
		m_repository->afterEditAp (m_editProfile, m_tempProfile);
		break;
	case MENU_POPUP_BLOCK_NETWORK:
		m_tempProfile->setApMgrType( SRV_DTCNT_WLAN_AP_BLACK_LIST  );
		m_repository->afterEditAp (m_editProfile, m_tempProfile);		
		break;
	case MENU_POPUP_FORGET_NETWORK:	
		m_repository->afterRemoveApFromList(m_longTapApId, m_repository->getUsefulApArray ());
		m_tempProfile->setApMgrType( SRV_DTCNT_WLAN_AP_UNKNOW );
		m_tempProfile->setApMatchType( WLAN_AP_SEARCH );
		m_tempProfile->setRssi(-110);// forget AP,CMCC request rssi >= -85.		
		m_repository->afterForgetAp(m_tempProfile);
		m_repository->updateApList();
		break;		
	}	
	m_networksListMenu->resetAllItems (VFX_TRUE);
}

VfxBool VappCMCCNetworkMgrPage::IsAllowEditPopup(VappWlanBaseInfo *ap)
{
	VAPP_WLAN_AP_CHANGE_ENUM  matchType = ap->getApMatchType();
	srv_dtcnt_wlan_ap_type_enum  mgrType = ap->getApMgrType();
	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_IS_ALLOW_EDIT_AP, matchType, mgrType, ap->getSsidLen());
    if(WLAN_AP_SEARCH_SAVED_CONNECTED == matchType ||WLAN_AP_SAVED_CONNECTED == matchType ||
       SRV_DTCNT_WLAN_AP_DEFAULT == mgrType) 
    {
        VcpConfirmPopup *notEditConfirm;
        VFX_OBJ_CREATE (notEditConfirm, VcpConfirmPopup, getMainScr ());
        notEditConfirm->setInfoType (VCP_POPUP_TYPE_WARNING);
		if(SRV_DTCNT_WLAN_AP_DEFAULT == mgrType)
		{
        	notEditConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERROR_EDIT_DEFAULT_AP));
		}
		else
		{
			notEditConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_NOT_ALLOW_EDIT));
		}
		notEditConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        notEditConfirm->setAutoDestory(VFX_TRUE);
        notEditConfirm->show (VFX_TRUE);
        return VFX_FALSE;
    }
	return VFX_TRUE;
}

/******************************************************************************/
// Implement the required content provider functions
void CMCCNetWorkMgrContentProvider::setMenu(VcpListMenu *menu)
{
    m_listMenu = menu;
}

VfxU32 CMCCNetWorkMgrContentProvider::getCount() const
{
    return ( m_repository->getUsefulApNum () );
}

VcpListMenuCellClientBaseFrame* CMCCNetWorkMgrContentProvider::getItemCustomContentFrame(
        VfxU32 index,           // [IN] the index of item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        )
{
    VappWlanApListMenuCell*  apListMenuCell;
    VFX_OBJ_CREATE (apListMenuCell, VappWlanApListMenuCell, parentFrame);
    return apListMenuCell;    
}

VfxBool CMCCNetWorkMgrContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    VfxWString description = VFX_WSTR_EMPTY;
    VappWlanBaseInfo* const * usefulApList = m_repository->getUsefulApArray ();

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
            text.loadFromMem ((const VfxWChar *)usefulApList[index]->getApName());
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT1:
            if(SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == usefulApList[index]->getNetworkType ())
            {
                description = usefulApList[index]->getNetworkTypeName ();
                description += VFX_WSTR(", ");
                description += usefulApList[index]->getAuthModeName ();
                text = description;            
            }
            else
                text = usefulApList[index]->getAuthModeName ();
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT2:
            break;
    }
    return VFX_TRUE;
}

VfxBool CMCCNetWorkMgrContentProvider::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    if(0 == m_repository->getUsefulApNum ())
    {
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_NO_NETWORK);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
        
    return VFX_FALSE;
}

VfxBool CMCCNetWorkMgrContentProvider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        ) 
{
    VfxBool isHighlight = VFX_FALSE;
    VcpListMenuCell* menuCell = m_listMenu->getCell (index);	
    VappWlanBaseInfo* const * usefulApList = m_repository->getUsefulApArray ();
	
    if(menuCell)
    {
        isHighlight = menuCell->m_isHighlight;
    }

	if(SRV_DTCNT_WLAN_AP_DEFAULT == usefulApList[index]->getApMgrType())
	{
		return VFX_TRUE;
	}
	
    switch(fieldType)
    {
    case VCP_LIST_MENU_FIELD_ICON:
        if(isHighlight)
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
        }
        else
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        }
        break;
    default:
        break;
    }
	
    return VFX_TRUE;
}

// VFX_IMPLEMENT_CLASS ("VappRememberedNetworkPage", VappRememberedNetworkPage, VfxPage);
VappRememberedNetworkPage::VappRememberedNetworkPage(VappWlanRepository *repository) : 
    m_isSelectAll(VFX_FALSE),
    m_repository(repository)
{
    // register page in the respository
    m_repository->registerObserver (this);
    // set flag
    m_repository->setIsDeleteApProc (VFX_FALSE);
}
    
VappRememberedNetworkPage::~VappRememberedNetworkPage()
{
    // deregister page in the respository
    m_repository->removeObserver (this);
}


void VappRememberedNetworkPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_INIT_REMEMBER_PAGE);
    Observer::onInit ();

    // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_CONNECT_SUCCESS_MSG |
        SUBSCRIBE_DISCONNECT_MSG |
        SUBSCRIBE_SCAN_MSG |
		SUBSCRIBE_CONNECT_FAIL_MSG);
    
    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_REMEMBER_MAIN_TEXT));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
	m_toolBar->addItem (TOOLBAR_ADD_NETWORK, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_ADD), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);	
    m_toolBar->addItem (TOOLBAR_MULTI_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	m_toolBar->addItem (TOOLBAR_CHANGE_PRIORITY, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_CHANGE_PRIORITY), IMG_ID_VAPP_WLAN_CHANGE_PRIORITY);
    m_toolBar->m_signalButtonTap.connect (this, &VappRememberedNetworkPage::onToolBarClick);
    setBottomBar(m_toolBar);
    if(0 == m_repository->getRememberedApNum ())
    {
        m_toolBar->setDisableItem (TOOLBAR_CHANGE_PRIORITY, VFX_TRUE);
        m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);
    }
    
    // Init delete list tool bar at first
    VFX_OBJ_CREATE (m_deleteListToolBar, VcpToolBar, this);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);
    m_deleteListToolBar->m_signalButtonTap.connect (this, &VappRememberedNetworkPage::onToolBarClick);

    // Networks list menu
    VFX_OBJ_CREATE (m_networksListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX (m_contentProvider, RememberedNetworkContentProvider, this, (m_repository, m_itemStateArray));
    m_contentProvider->setMenu (m_networksListMenu);
    m_networksListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_networksListMenu->setContentProvider (m_contentProvider);
    m_networksListMenu->setPos(0, 0);
    m_networksListMenu->setSize(getSize());
    m_networksListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_networksListMenu->m_signalItemSelectionStateChanged.connect (
            this, &VappRememberedNetworkPage::onItemStateChanged);

}

void VappRememberedNetworkPage::onEnter(VfxBool isBackward)
{
    if(isBackward)
    {
        if(m_repository->getIsDeleteApProc ())
        {
            initStatusArray ();
            setToolbarDeleteStatus();
            setToolbarMarkAllStatus();
        }
        else
        {
            initToolbar();
        }
        m_networksListMenu->resetAllItems ();
    }
    else
    {
        if(!m_repository->getIsDeleteApProc ())
        {
            initToolbar();
        }
    }
}

void VappRememberedNetworkPage::onBack ()
{
    if(m_repository->getIsDeleteApProc ())
    {
        returnMgrScreen ();
    }
    else
    {
        VfxPage::onBack ();
    }
}

void VappRememberedNetworkPage::onDeinit ()
{
    Observer::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_DEINIT_REMEMBER_PAGE);
}

void VappRememberedNetworkPage::UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{   
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_UPDATE_REMEMBER_PAGE, msg);
    switch(msg)
    {
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:         /* connect event */
    case SUBSCRIBE_DISCONNECT_MSG:              /* disconnect event */
	case SUBSCRIBE_SCAN_MSG:					/* scan event */
	case SUBSCRIBE_CONNECT_FAIL_MSG:            /* connect fail event */		
	case SUBSCRIBE_CONNECT_REQUEST_MSG: 		/* Connect request event */  
        if(m_repository->getIsDeleteApProc ())
        {
            initStatusArray();
            setToolbarDeleteStatus();
            setToolbarMarkAllStatus();
        }
		else
		{
			initToolbar();
		}
        m_networksListMenu->resetAllItems ();
        break;
    default:
        break;
    }
}

void VappRememberedNetworkPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    VappChangePriorityPage* priorityListPage = NULL;
    
    switch(id)
    {
    	case TOOLBAR_ADD_NETWORK:
			entryAddNewNetworkProc();
			break;
        case TOOLBAR_MULTI_DELETE:
            goToDeleteApList();         
            break;
        case TOOLBAR_CHANGE_PRIORITY:
            VFX_OBJ_CREATE_EX (
                priorityListPage, 
                VappChangePriorityPage, 
                getMainScr (), 
                (m_repository, this));
            getMainScr()->pushPage(0, priorityListPage);
            break;
        case TOOLBAR_MULTI_DELETE_SELECT_ALL:
            markAllAPs();
            break;
        case TOOLBAR_MULTI_DELETE_DELETE:
            removeApFromSavedList();
            break;
        case TOOLBAR_MULTI_DELETE_CANCEL:
            returnMgrScreen();
            break;
        default:
            break;
    }
}

void VappRememberedNetworkPage::entryAddNewNetworkProc ()
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
	m_repository->setAddApType(VAPP_WLAN_ADD_REMEMBER_AP);

    VappJoinNetworkPage* joinNetworkPage = NULL;
    
    VFX_OBJ_CREATE_EX (joinNetworkPage, VappJoinNetworkPage, getMainScr(), (m_repository, this));
    getMainScr ()->pushPage (0, joinNetworkPage);
}


void VappRememberedNetworkPage::onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VFX_TRACE(("=== Item %d's new status: %d\n", index, newState));
    m_itemStateArray[index] = newState;
    // Enable/Disable toolbar button "Delete"
    setToolbarDeleteStatus();
    setToolbarMarkAllStatus();
}

void VappRememberedNetworkPage::markAllAPs()
{
    VfxU8 total = m_repository->getRememberedApNum ();

    for(VfxU8 index = 0; index < total; index++)
    {
        if(m_itemStateArray[index] != VCP_LIST_MENU_ITEM_STATE_NONE)
        {
            VFX_TRACE(("===== Item %d's status changed =====\n", index));   
            if(m_isSelectAll)
            {
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
            }
            else
            {
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
        }
    }

    if(m_isSelectAll)   // Current status unselect all, go back to select all
    {
        m_isSelectAll = VFX_FALSE;
        m_deleteListToolBar->changeItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);
    }
    else
    {
        m_isSelectAll  = VFX_TRUE;
        m_deleteListToolBar->changeItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_FALSE);
    }
    
    // Refresh
    m_networksListMenu->updateAllItems ();
}

void VappRememberedNetworkPage::removeApFromSavedList()
{
    VfxU8 index = 0;
    VfxU8 deleteNum = 0;
    VfxU8 total = m_repository->getRememberedApNum ();
    
    for(index = 0; index < total; index++)
    {
        VFX_TRACE(("=== ITEM STATUS: %d ===\n", m_itemStateArray[index]));
        if(VCP_LIST_MENU_ITEM_STATE_SELECTED == m_itemStateArray[index])
        {
            // Todo: remove them from saved list
            deleteNum++;  
            m_repository->afterRemoveApFromList(index, m_repository->getRememberedApArray());
        }
    }

    VFX_TRACE(("=== Delete %d AP ===\n", deleteNum));
    
    // Refresh the display ap list and save ap pointer list
    m_repository->updateApList();
    returnMgrScreen();
}

void VappRememberedNetworkPage::goToDeleteApList()
{
    // initialize status array
    initStatusArray();
    // set flag that go to delete ap list
    m_repository->setIsDeleteApProc (VFX_TRUE);
    // Refresh list menu
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_DELETE_REMEMBER_AP));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_networksListMenu->setMenuMode (VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
    m_networksListMenu->resetAllItems(VFX_TRUE);
    setBottomBar(m_deleteListToolBar);
    setToolbarDeleteStatus();
    setToolbarMarkAllStatus();
}

void VappRememberedNetworkPage::returnMgrScreen()
{
    // set flag as not in the delete ap's proc
    m_repository->setIsDeleteApProc (VFX_FALSE);
    // Refresh list menu
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_REMEMBER_MAIN_TEXT));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_networksListMenu->setMenuMode (VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_networksListMenu->resetAllItems(VFX_TRUE);
    setBottomBar(m_toolBar);
    // set toolbar items' status
    initToolbar();
}

void VappRememberedNetworkPage::initStatusArray()
{
    VfxU8 index;
    VfxU8 total = m_repository->getRememberedApNum();
    VappWlanBaseInfo* const * apList = m_repository->getRememberedApArray();

    for(index = 0; index < total; index++)
    {
        switch(apList[index]->getApMatchType ())
        {
            case WLAN_AP_SEARCH:
            case WLAN_AP_SEARCH_SAVED_CONNECTED:
            case WLAN_AP_SAVED_CONNECTED:
                // Todo: set this ap's status as VCP_LIST_MENU_ITEM_STATE_NONE
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_NONE;
                break;
            default:
				if( SRV_DTCNT_WLAN_AP_DEFAULT == apList[index]->getApMgrType ())					
                	m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_NONE;
				else
                	m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
                break;
        }
    }
}

void VappRememberedNetworkPage::initToolbar()
{	
	//if Conn num isn't 0 ,disable  'Change priority' and 'Delete' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_toolBar->setDisableItem (TOOLBAR_CHANGE_PRIORITY, VFX_TRUE);		
		m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);	
		return;
	}

	VfxBool isAllDefaultAP = VFX_TRUE;	
	VfxU8	nonDefaultAPindex = 0;	
	VappWlanBaseInfo* const * apList = m_repository->getRememberedApArray();
	for(VfxU8 index = 0; index < m_repository->getRememberedApNum (); index++)
	{
		if(SRV_DTCNT_WLAN_AP_DEFAULT != apList[index]->getApMgrType ())
		{
			isAllDefaultAP = VFX_FALSE;
			nonDefaultAPindex = index;
			break;
		}
	}	

    // there are three saved APs and nonDefault AP is the connected one
    // Or all APs are default.
    m_toolBar->setDisableItem (TOOLBAR_CHANGE_PRIORITY, VFX_FALSE);		
    if((3 == m_repository->getRememberedApNum ()) &&
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()))
    {
    	if(VFX_TRUE == VappWlanToolbox::isSameAP(apList[nonDefaultAPindex], m_repository->getConnectedAP()))
    	{
        	m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);
   		}
    }
	else if(VFX_TRUE == isAllDefaultAP)
	{		
		m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);
	}
    else
    {
        m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_FALSE);
    }
}

void VappRememberedNetworkPage::setToolbarDeleteStatus()
{
    VfxU8 pos = 0;
    VfxU8 total = m_repository->getRememberedApNum ();
	
   	//if Conn num isn't 0 ,disable 'Delete' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);		
		return;
	}    

    for(; pos < total; pos++)
    {
        if(m_itemStateArray[pos] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
            break;
    }
    VFX_TRACE(("=== Position: %d \t Total: %d\n", pos, total));
    // Disable item "Delete" if no AP has been selected
    if(pos == total)
    {
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);
    }
    else
    {
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_FALSE);
    }
}

void VappRememberedNetworkPage::setToolbarMarkAllStatus()
{
    VfxU8 pos = 0;
    VfxU8 total = m_repository->getRememberedApNum ();
    VfxU8 totalDisableItem = 0, totalMarkItem = 0, totalUnmarkItem = 0;

	//if Conn num isn't 0 ,disable 'Delete' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_TRUE);						
		return;
	}
	
    for(pos = 0; pos < total; pos++)
    {
        if(m_itemStateArray[pos] == VCP_LIST_MENU_ITEM_STATE_NONE)
        {
            totalDisableItem++;
        }
        else if(m_itemStateArray[pos] == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
            totalUnmarkItem++;
        }
        else if(m_itemStateArray[pos] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            totalMarkItem++;
        }
    }

    if(totalMarkItem == (total - totalDisableItem))
    {
        m_isSelectAll = VFX_TRUE;
        m_deleteListToolBar->changeItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);   
    }
    else
    {
        m_isSelectAll = VFX_FALSE;
        m_deleteListToolBar->changeItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }
    
    VFX_TRACE(("=== Position: %d \t Total: %d\n", pos, total));
    if(totalDisableItem == total)
    {
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_TRUE);
    }
    else
    {
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_FALSE);
    }
}

/******************************************************************************/
// Implement the required content provider functions
void RememberedNetworkContentProvider::setMenu(VcpListMenu *menu)
{
    m_listMenu = menu;
}

VfxU32 RememberedNetworkContentProvider::getCount() const
{
    return m_repository->getRememberedApNum ();
}

VcpListMenuCellClientBaseFrame* RememberedNetworkContentProvider::getItemCustomContentFrame(
        VfxU32 index,           // [IN] the index of item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        )
{
	if(m_repository->getIsDeleteApProc ())
    {
    	VcpListMenuCellMultiTextFrame* funcListMenuCell;
        VFX_OBJ_CREATE (funcListMenuCell, VcpListMenuCellMultiTextFrame, parentFrame);
        return funcListMenuCell;
	}
	else
	{
	    VappWlanApListMenuCell*  apListMenuCell;
	    VFX_OBJ_CREATE (apListMenuCell, VappWlanApListMenuCell, parentFrame);
	    return apListMenuCell;  
	}  
}

VfxBool RememberedNetworkContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    VfxWString description = VFX_WSTR_EMPTY;
    VappWlanBaseInfo* const * RememberedApList = m_repository->getRememberedApArray ();

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
            text.loadFromMem ((const VfxWChar *)RememberedApList[index]->getApName());
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT1:
            if(SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == RememberedApList[index]->getNetworkType ())
            {
                description = RememberedApList[index]->getNetworkTypeName ();
                description += VFX_WSTR(", ");
                description += RememberedApList[index]->getAuthModeName ();
                text = description;            
            }
            else
                text = RememberedApList[index]->getAuthModeName ();
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT2:
            break;
    }

    return VFX_TRUE;
}

VcpListMenuItemStateEnum RememberedNetworkContentProvider::getItemState(
                            VfxU32 index   // [IN] index of the item
                            ) const 
{
    if(m_repository->getIsDeleteApProc ())
    {
        VFX_TRACE(("=== Item %d's status: %d\n", index, m_itemStateArray[index]));
        return m_itemStateArray[index];
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_NONE;
    }
}

VfxBool RememberedNetworkContentProvider::getItemIsDisabled(
                            VfxU32 index                    // [IN] the index of item
                            ) const
{
    if(m_repository->getIsDeleteApProc ())
    {
        VappWlanBaseInfo* const * RememberedApList = m_repository->getRememberedApArray ();
        VFX_TRACE(("Current Item(%d)'s match type: %d\n", index, RememberedApList[index]->getApMatchType ()));
        switch(RememberedApList[index]->getApMatchType ())
        {
            case WLAN_AP_SEARCH:
            case WLAN_AP_SEARCH_SAVED_CONNECTED:
            case WLAN_AP_SAVED_CONNECTED:
                return VFX_TRUE;
            default:
				if(SRV_DTCNT_WLAN_AP_DEFAULT == RememberedApList[index]->getApMgrType () )
					return VFX_TRUE;
				else
					return VFX_FALSE;
        }
    }
    else
    {
        return VFX_FALSE;    
    }
}

VfxBool RememberedNetworkContentProvider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        ) 
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return VFX_TRUE;
}

VfxBool RememberedNetworkContentProvider::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    if((VFX_FALSE == m_repository->getIsDeleteApProc ()) &&
       (0 == m_repository->getRememberedApNum ()))
    {
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_NO_NETWORK);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
        
    return VFX_FALSE;
}

// VFX_IMPLEMENT_CLASS ("VappBlockedNetworkPage", VappBlockedNetworkPage, VfxPage);
VappBlockedNetworkPage::VappBlockedNetworkPage(VappWlanRepository *repository) : 
	m_isSelectAll(VFX_FALSE),
    m_repository(repository)
{
    // register page in the respository
    m_repository->registerObserver (this);
    // set flag
    m_repository->setIsDeleteApProc (VFX_FALSE);
}
    
VappBlockedNetworkPage::~VappBlockedNetworkPage()
{
    // deregister page in the respository
    m_repository->removeObserver (this);
}

void VappBlockedNetworkPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_INIT_BLOCK_PAGE);
    Observer::onInit ();

    // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_CONNECT_SUCCESS_MSG |
        SUBSCRIBE_DISCONNECT_MSG |
        SUBSCRIBE_SCAN_MSG |
		SUBSCRIBE_CONNECT_FAIL_MSG);

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_BLOCK_MAIN_TEXT));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
	m_toolBar->addItem (TOOLBAR_ADD_NETWORK, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_ADD), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);	
    m_toolBar->addItem (TOOLBAR_MULTI_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolBar->m_signalButtonTap.connect (this, &VappBlockedNetworkPage::onToolBarClick);
    setBottomBar(m_toolBar);
    if(0 == m_repository->getBlockedApNum ())
    {
        m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);
    }
    
    // Init delete list tool bar at first
    VFX_OBJ_CREATE (m_deleteListToolBar, VcpToolBar, this);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);
    m_deleteListToolBar->m_signalButtonTap.connect (this, &VappBlockedNetworkPage::onToolBarClick);

    // Networks list menu
    VFX_OBJ_CREATE (m_networksListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX (m_contentProvider, BlockedNetworkContentProvider, this, (m_repository, m_itemStateArray));
    m_contentProvider->setMenu (m_networksListMenu);
    m_networksListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_networksListMenu->setContentProvider (m_contentProvider);
    m_networksListMenu->setPos(0, 0);
    m_networksListMenu->setSize(getSize());
    m_networksListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_networksListMenu->m_signalItemSelectionStateChanged.connect (
            this, &VappBlockedNetworkPage::onItemStateChanged);

}

void VappBlockedNetworkPage::onEnter(VfxBool isBackward)
{
    if(isBackward)
    {
        if(m_repository->getIsDeleteApProc ())
        {
            initStatusArray ();
            setToolbarDeleteStatus();
            setToolbarMarkAllStatus();
        }
        else
        {
            initToolbar();
        }
        m_networksListMenu->resetAllItems ();
    }
    else
    {
        if(!m_repository->getIsDeleteApProc ())
        {
            initToolbar();
        }
    }
}

void VappBlockedNetworkPage::onBack ()
{
    if(m_repository->getIsDeleteApProc ())
    {
        returnMgrScreen ();
    }
    else
    {
        VfxPage::onBack ();
    }
}

void VappBlockedNetworkPage::onDeinit ()
{  
    Observer::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_DEINIT_BLOCK_PAGE);
}

void VappBlockedNetworkPage::UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{   
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_UPDATE_BLOCK_PAGE, msg);
    switch(msg)
    {
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:         /* connect event */
    case SUBSCRIBE_DISCONNECT_MSG:              /* disconnect event */
	case SUBSCRIBE_SCAN_MSG:					/* scan event */
	case SUBSCRIBE_CONNECT_FAIL_MSG:            /* connect fail event */		
	case SUBSCRIBE_CONNECT_REQUEST_MSG: 		/* Connect request event */  
        if(m_repository->getIsDeleteApProc ())
        {
            initStatusArray();
            setToolbarDeleteStatus();
            setToolbarMarkAllStatus();
        }
		else
		{
			initToolbar();
		}
        m_networksListMenu->resetAllItems ();
        break;
    default:
        break;
    }
}

void VappBlockedNetworkPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
    	case TOOLBAR_ADD_NETWORK:
			entryAddNewNetworkProc();
			break;
        case TOOLBAR_MULTI_DELETE:
            goToDeleteApList();         
            break;
        case TOOLBAR_MULTI_DELETE_SELECT_ALL:
            markAllAPs();
            break;
        case TOOLBAR_MULTI_DELETE_DELETE:
            removeApFromSavedList();
            break;
        case TOOLBAR_MULTI_DELETE_CANCEL:
            returnMgrScreen();
            break;
        default:
            break;
    }
}

void VappBlockedNetworkPage::entryAddNewNetworkProc ()
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
	m_repository->setAddApType(VAPP_WLAN_ADD_BLOCKED_AP);

    VappJoinNetworkPage* joinNetworkPage = NULL;
    
    VFX_OBJ_CREATE_EX (joinNetworkPage, VappJoinNetworkPage, getMainScr(), (m_repository, this));
    getMainScr ()->pushPage (0, joinNetworkPage);
}


void VappBlockedNetworkPage::onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VFX_TRACE(("=== Item %d's new status: %d\n", index, newState));
    m_itemStateArray[index] = newState;
    // Enable/Disable toolbar button "Delete"
    setToolbarDeleteStatus();
    setToolbarMarkAllStatus();
}

void VappBlockedNetworkPage::markAllAPs()
{
    VfxU8 total = m_repository->getBlockedApNum ();

    for(VfxU8 index = 0; index < total; index++)
    {
        if(m_itemStateArray[index] != VCP_LIST_MENU_ITEM_STATE_NONE)
        {
            VFX_TRACE(("===== Item %d's status changed =====\n", index));   
            if(m_isSelectAll)
            {
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
            }
            else
            {
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
        }
    }

    if(m_isSelectAll)   // Current status unselect all, go back to select all
    {
        m_isSelectAll = VFX_FALSE;
        m_deleteListToolBar->changeItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);
    }
    else
    {
        m_isSelectAll  = VFX_TRUE;
        m_deleteListToolBar->changeItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_FALSE);
    }
    
    // Refresh
    m_networksListMenu->updateAllItems ();
}

void VappBlockedNetworkPage::removeApFromSavedList()
{
    VfxU8 index = 0;
    VfxU8 deleteNum = 0;
    VfxU8 total = m_repository->getBlockedApNum ();
    
    for(index = 0; index < total; index++)
    {
        VFX_TRACE(("=== ITEM STATUS: %d ===\n", m_itemStateArray[index]));
        if(VCP_LIST_MENU_ITEM_STATE_SELECTED == m_itemStateArray[index])
        {
            // Todo: remove them from saved list
            deleteNum++;  
            m_repository->afterRemoveApFromList(index, m_repository->getBlockedApArray());
        }
    }

    VFX_TRACE(("=== Delete %d AP ===\n", deleteNum));
    
    // Refresh the display ap list and save ap pointer list
    m_repository->updateApList();
    //m_repository->updateSavedApList();
    returnMgrScreen();

}

void VappBlockedNetworkPage::goToDeleteApList()
{
    // initialize status array
    initStatusArray();
    // set flag that go to delete ap list
    m_repository->setIsDeleteApProc (VFX_TRUE);
    // Refresh list menu
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_DELETE_BLOCK_AP));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_networksListMenu->setMenuMode (VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
    m_networksListMenu->resetAllItems(VFX_TRUE);
    setBottomBar(m_deleteListToolBar);
    setToolbarDeleteStatus();
    setToolbarMarkAllStatus();
}

void VappBlockedNetworkPage::returnMgrScreen()
{
    // set flag as not in the delete ap's proc
    m_repository->setIsDeleteApProc (VFX_FALSE);
    // Refresh list menu
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_BLOCK_MAIN_TEXT));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_networksListMenu->setMenuMode (VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_networksListMenu->resetAllItems(VFX_TRUE);
    setBottomBar(m_toolBar);
    // set toolbar items' status
    initToolbar();
}

void VappBlockedNetworkPage::initStatusArray()
{
    VfxU8 index = 0;
    VfxU8 total = m_repository->getBlockedApNum();
    
    for(index = 0; index < total; index++)
    {
    	m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

void VappBlockedNetworkPage::initToolbar()
{
	//if Conn num isn't 0 ,disable  'Change priority' and 'Delete' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);	
		m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);	
		return;
	}

    // No saved AP, disable item 'Delete'
    if(0 == m_repository->getBlockedApNum ())
    {
        m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);
    }
    // Otherwise, enable. 
    else
    {
		m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_FALSE);
    }
}

void VappBlockedNetworkPage::setToolbarDeleteStatus()
{
    VfxU8 pos = 0;
    VfxU8 total = m_repository->getBlockedApNum ();

   	//if Conn num isn't 0 ,disable 'Delete' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);		
		return;
	}  
	
    for(; pos < total; pos++)
    {
        if(m_itemStateArray[pos] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
            break;
    }
    VFX_TRACE(("=== Position: %d \t Total: %d\n", pos, total));
    // Disable item "Delete" if no AP has been selected
    if(pos == total)
    {
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);
    }
    else
    {
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_FALSE);
    }
}

void VappBlockedNetworkPage::setToolbarMarkAllStatus()
{
    VfxU8 pos = 0;
    VfxU8 total = m_repository->getBlockedApNum ();
    VfxU8 totalDisableItem = 0, totalMarkItem = 0, totalUnmarkItem = 0;

	//if Conn num isn't 0 ,disable 'Delete' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_TRUE);						
		return;
	}
	
    for(pos = 0; pos < total; pos++)
    {
        if(m_itemStateArray[pos] == VCP_LIST_MENU_ITEM_STATE_NONE)
        {
            totalDisableItem++;
        }
        else if(m_itemStateArray[pos] == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
            totalUnmarkItem++;
        }
        else if(m_itemStateArray[pos] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            totalMarkItem++;
        }
    }

    if(totalMarkItem == (total - totalDisableItem))
    {
        m_isSelectAll = VFX_TRUE;
        m_deleteListToolBar->changeItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);   
    }
    else
    {
        m_isSelectAll = VFX_FALSE;
        m_deleteListToolBar->changeItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }
    
    VFX_TRACE(("=== Position: %d \t Total: %d\n", pos, total));
    if(totalDisableItem == total)
    {
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_TRUE);
    }
    else
    {
        m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_FALSE);
    }
}

/******************************************************************************/
// Implement the required content provider functions
void BlockedNetworkContentProvider::setMenu(VcpListMenu *menu)
{
    m_listMenu = menu;
}

VfxU32 BlockedNetworkContentProvider::getCount() const
{
    return m_repository->getBlockedApNum ();
}

VcpListMenuCellClientBaseFrame* BlockedNetworkContentProvider::getItemCustomContentFrame(
        VfxU32 index,           // [IN] the index of item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        )
{
    VappWlanApListMenuCell*  apListMenuCell;
    VFX_OBJ_CREATE (apListMenuCell, VappWlanApListMenuCell, parentFrame);
    return apListMenuCell;    
}

VfxBool BlockedNetworkContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    VfxWString description = VFX_WSTR_EMPTY;
    VappWlanBaseInfo* const * BlockedApList = m_repository->getBlockedApArray ();

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
            text.loadFromMem ((const VfxWChar *)BlockedApList[index]->getApName());
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT1:
            if(SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == BlockedApList[index]->getNetworkType ())
            {
                description = BlockedApList[index]->getNetworkTypeName ();
                description += VFX_WSTR(", ");
                description += BlockedApList[index]->getAuthModeName ();
                text = description;            
            }
            else
                text = BlockedApList[index]->getAuthModeName ();
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT2:
            break;
    }

    return VFX_TRUE;
}

VcpListMenuItemStateEnum BlockedNetworkContentProvider::getItemState(
                            VfxU32 index   // [IN] index of the item
                            ) const 
{
    if(m_repository->getIsDeleteApProc ())
    {
        VFX_TRACE(("=== Item %d's status: %d\n", index, m_itemStateArray[index]));
        return m_itemStateArray[index];
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_NONE;
    }
}

VfxBool BlockedNetworkContentProvider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        ) 
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
    return VFX_TRUE;
}

VfxBool BlockedNetworkContentProvider::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    if((VFX_FALSE == m_repository->getIsDeleteApProc ()) &&
       (0 == m_repository->getBlockedApNum ()))
    {
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_NO_NETWORK);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
        
    return VFX_FALSE;
}

#endif // __MMI_OP01_WIFI__
#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__
