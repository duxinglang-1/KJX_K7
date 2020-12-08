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
 *  vapp_dtcnt_wlan_ui_mgr.cpp
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
#include "vapp_dtcnt_wlan_ui.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"

#ifdef __MMI_OP01_WIFI__
#include "vapp_dtcnt_wlan_cmcc_ui.h"
#include "vcui_dtcnt_wlan_ui.h"
#include "vapp_fmgr_cui_gprot.h"
#ifdef __CERTMAN_SUPPORT__
#include "vapp_certman_gprot_ex.h"
#include "vapp_certman_pluto_adaptor.h"
#endif
extern "C"
{
#include "FileMgrType.h"
}
#endif /* __MMI_OP01_WIFI__ */

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_OP01_WIFI__ 
    #define CMCC_WLAN_SETTING_PAGE_ID 0xABCD // pageId must set big number.
#endif /* __MMI_OP01_WIFI__ */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" mmi_ret VappDtcntWlanClosePageEvent(mmi_event_struct *param)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_HDLR, param->evt_id);
    
#ifdef __MMI_OP01_WIFI__
    switch(param->evt_id)
    {           
    case EVT_ID_VAPP_WLAN_CMCC_CLOSE_PAGE:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_CLOSE_CMCC_SETTING_PAGE);
        VappAdvancedPage::responseCloseCMCCSettingPageEvent (param);
        break;           
    default:
        break;
    } 
#endif /* __MMI_OP01_WIFI__ */  

    return MMI_RET_OK;
}

//VFX_IMPLEMENT_CLASS ("VappNetworkMgrPage", VappNetworkMgrPage, VfxPage);
VappNetworkMgrPage::VappNetworkMgrPage(VappWlanRepository *repository) : 
    m_isSelectAll(VFX_FALSE),    
    m_repository(repository),
	m_confirmPopup(NULL),	
	m_popupWeakPtr(NULL)	
{
    // register page in the respository
    m_repository->registerObserver (this);
    // set flag
    m_repository->setIsDeleteApProc (VFX_FALSE);
}
    
VappNetworkMgrPage::~VappNetworkMgrPage()
{
    // deregister page in the respository
    m_repository->removeObserver (this);
}


void VappNetworkMgrPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INIT_MANAGER_PAGE);
    Observer::onInit ();

    // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_CONNECT_SUCCESS_MSG |
        SUBSCRIBE_DISCONNECT_MSG |
        SUBSCRIBE_SCAN_MSG |
        SUBSCRIBE_CONNECT_FAIL_MSG |
        SUBSCRIBE_CONNECT_REQUEST_MSG);
    
    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_MAIN_TEXT));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (TOOLBAR_CHANGE_PRIORITY, VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_CHANGE_PRIORITY), IMG_ID_VAPP_WLAN_CHANGE_PRIORITY);
    m_toolBar->addItem (TOOLBAR_MULTI_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolBar->m_signalButtonTap.connect (this, &VappNetworkMgrPage::onToolBarClick);
    m_toolBar->m_signalBarFolded.connect (this, &VappNetworkMgrPage::onToolBarFolding);
    setBottomBar(m_toolBar);
    if(0 == m_repository->getUsefulApNum())
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
    m_deleteListToolBar->m_signalButtonTap.connect (this, &VappNetworkMgrPage::onToolBarClick);

    // Networks list menu
    VFX_OBJ_CREATE (m_networksListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX (m_contentProvider, NetWorkMgrContentProvider, this, (m_repository, m_itemStateArray));
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
                                this, &VappNetworkMgrPage::onItemTapped);
    m_networksListMenu->m_signalItemSelectionStateChanged.connect (
            this, &VappNetworkMgrPage::onItemStateChanged);

}

void VappNetworkMgrPage::onEnter(VfxBool isBackward)
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
	
	if(m_popupWeakPtr.isValid())
	{	
		VcpConfirmPopup *tempPopup = m_popupWeakPtr.get(); 
		VFX_OBJ_CLOSE (tempPopup);
	}
}

void VappNetworkMgrPage::onBack ()
{
    if(m_repository->getIsDeleteApProc ())
    {
        returnMgrScreen ();
    }
    else
    {
        VfxPage::onBack ();
    }
	if(m_popupWeakPtr.isValid())
	{	
		VcpConfirmPopup *tempPopup = m_popupWeakPtr.get(); 
		VFX_OBJ_CLOSE (tempPopup);
	}
}

void VappNetworkMgrPage::onDeinit ()
{
	if(m_popupWeakPtr.isValid())
	{	
		VcpConfirmPopup *tempPopup = m_popupWeakPtr.get(); 
		VFX_OBJ_CLOSE (tempPopup);
	}
    
    Observer::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_DEINIT_MANAGER_PAGE);
}

void VappNetworkMgrPage::UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{   
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_UPDATE_MANAGER_PAGE, msg);
    switch(msg)
    {
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:         /* connect event */
    case SUBSCRIBE_DISCONNECT_MSG:              /* disconnect event */
	case SUBSCRIBE_SCAN_MSG:					/* scan event */
	case SUBSCRIBE_CONNECT_FAIL_MSG:            /* connect fail event */
	case SUBSCRIBE_CONNECT_REQUEST_MSG:			/* connect request event */
		if(m_popupWeakPtr.isValid())
		{	
			VcpConfirmPopup *tempPopup = m_popupWeakPtr.get(); 
			VFX_OBJ_CLOSE (tempPopup);
		}
		
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

void VappNetworkMgrPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    VappChangePriorityPage* priorityListPage = NULL;
    
    switch(id)
    {
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

void VappNetworkMgrPage::onToolBarFolding (VfxObject *sender, VfxBool is_fold)
{
    VFX_TRACE(("Receive folding event\n"));
}

void VappNetworkMgrPage::onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VFX_TRACE(("=== Item %d's new status: %d\n", index, newState));
    m_itemStateArray[index] = newState;
    // Enable/Disable toolbar button "Delete"
    setToolbarDeleteStatus();
    setToolbarMarkAllStatus();
}


void VappNetworkMgrPage::onItemTapped(VcpListMenu *sender, VfxU32 id)
{
    if(m_repository->getIsDeleteApProc () == VFX_TRUE)
    {
        return;
    }
    
    VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray();
    // If the ap is in use, then give a prompt 
    if(WLAN_AP_SEARCH_SAVED_CONNECTED == apList[id]->getApMatchType () ||
       WLAN_AP_SAVED_CONNECTED == apList[id]->getApMatchType ()) 
    {
        VcpConfirmPopup *notEditConfirm;
        VFX_OBJ_CREATE (notEditConfirm, VcpConfirmPopup, getMainScr ());
        notEditConfirm->setInfoType (VCP_POPUP_TYPE_WARNING);
        notEditConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_NOT_ALLOW_EDIT));
        notEditConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        notEditConfirm->setAutoDestory(VFX_TRUE);
        notEditConfirm->show (VFX_TRUE);
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

void VappNetworkMgrPage::markAllAPs()
{
    VfxU8 total = m_repository->getUsefulApNum();

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

void VappNetworkMgrPage::removeApFromSavedList()
{
	VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);	
    m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_DELETE_SELECTED_AP));
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    m_confirmPopup->setCustomButton(
                VFX_WSTR_RES(STR_GLOBAL_DELETE), 
                VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
                VCP_POPUP_BUTTON_TYPE_WARNING, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappNetworkMgrPage::onConfirmBtnClick);
    m_confirmPopup->show(VFX_TRUE);
	m_popupWeakPtr = m_confirmPopup;
}

void VappNetworkMgrPage::onConfirmBtnClick(VfxObject * obj, VfxId id)
{

    VfxU8 index = 0;
    VfxU8 deleteNum = 0;
    VfxU8 total = m_repository->getUsefulApNum();
	VcpConfirmPopup *tempPopup = NULL;

    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_YES:
			if(m_popupWeakPtr.isValid())
			{	
				tempPopup = m_popupWeakPtr.get(); 
				VFX_OBJ_CLOSE (tempPopup);
			}	
            /* start to process */    
		    for(index = 0; index < total; index++)
		    {
		        VFX_TRACE(("=== ITEM STATUS: %d ===\n", m_itemStateArray[index]));
		        if(VCP_LIST_MENU_ITEM_STATE_SELECTED == m_itemStateArray[index])
		        {
		            // Todo: remove them from saved list
		            deleteNum++;  
		            m_repository->afterRemoveApFromList(index, m_repository->getUsefulApArray ());
		        }
		    }		    
		    // Refresh the display ap list and save ap pointer list
		    m_repository->updateApList();
		    returnMgrScreen();
	        break;
			
	    case VCP_CONFIRM_POPUP_BUTTON_NO:
			if(m_popupWeakPtr.isValid())
			{	
				tempPopup = m_popupWeakPtr.get(); 
				VFX_OBJ_CLOSE (tempPopup);
			}
			returnMgrScreen();
	        break;
			
	    default:
	        break;
	}
}

void VappNetworkMgrPage::goToDeleteApList()
{
    // initialize status array
    initStatusArray();
    // set flag that go to delete ap list
    m_repository->setIsDeleteApProc (VFX_TRUE);
    // Refresh list menu
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_DELETE_AP));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_networksListMenu->setMenuMode (VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
    m_networksListMenu->resetAllItems(VFX_TRUE);
    setBottomBar(m_deleteListToolBar);
    setToolbarDeleteStatus();
    setToolbarMarkAllStatus();
}

void VappNetworkMgrPage::returnMgrScreen()
{
    // set flag as not in the delete ap's proc
    m_repository->setIsDeleteApProc (VFX_FALSE);
    // Refresh list menu
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_MAIN_TEXT));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_networksListMenu->setMenuMode (VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_networksListMenu->resetAllItems(VFX_TRUE);
    setBottomBar(m_toolBar);
    // set toolbar items' status
    initToolbar();
}

void VappNetworkMgrPage::initStatusArray()
{
    VfxU8 index;
    VfxU8 total = m_repository->getUsefulApNum();
    VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray();
    
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
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
                break;
        }
    }
}

void VappNetworkMgrPage::initToolbar()
{
	//if Conn num isn't 0 ,disable  'Change priority' and 'Delete' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_toolBar->setDisableItem (TOOLBAR_CHANGE_PRIORITY, VFX_TRUE);		
		m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);	
		return;
	}

    // No saved AP, disable item 'Change priority' and 'Delete'
    if(0 == m_repository->getRememberedApNum())
    {
        m_toolBar->setDisableItem (TOOLBAR_CHANGE_PRIORITY, VFX_TRUE);
        m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);
    }
    // Otherwise, enable. 
    // Except that there is one saved AP and it's the connected one
    else
    {
        m_toolBar->setDisableItem (TOOLBAR_CHANGE_PRIORITY, VFX_FALSE);
        if((1 == m_repository->getRememberedApNum ()) &&
           (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()))
        {
            m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);
        }
        else
        {
            m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_FALSE);
        }
    }
}

void VappNetworkMgrPage::setToolbarDeleteStatus()
{
    VfxU8 pos = 0;
    VfxU8 total = m_repository->getUsefulApNum();
	
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

void VappNetworkMgrPage::setToolbarMarkAllStatus()
{
    VfxU8 pos = 0;
    VfxU8 total = m_repository->getUsefulApNum();
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
void NetWorkMgrContentProvider::setMenu(VcpListMenu *menu)
{
    m_listMenu = menu;
}

VfxU32 NetWorkMgrContentProvider::getCount() const
{
    return m_repository->getUsefulApNum();
}

VcpListMenuCellClientBaseFrame* NetWorkMgrContentProvider::getItemCustomContentFrame(
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

VfxBool NetWorkMgrContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    VfxWString description = VFX_WSTR_EMPTY;
    VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray();

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
            text.loadFromMem ((const VfxWChar *)apList[index]->getApName());
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT1:
            if(SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == apList[index]->getNetworkType ())
            {
                description = apList[index]->getNetworkTypeName ();
                description += VFX_WSTR(", ");
                description += apList[index]->getAuthModeName ();
                text = description;            
            }
            else
                text = apList[index]->getAuthModeName ();
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT2:
            break;
    }

    return VFX_TRUE;
}

VcpListMenuItemStateEnum NetWorkMgrContentProvider::getItemState(
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

VfxBool NetWorkMgrContentProvider::getItemIsDisabled(
                            VfxU32 index                    // [IN] the index of item
                            ) const
{
    if(m_repository->getIsDeleteApProc ())
    {
        VappWlanBaseInfo* const * apList = m_repository->getUsefulApArray();
        VFX_TRACE(("Current Item(%d)'s match type: %d\n", index, apList[index]->getApMatchType ()));
        switch(apList[index]->getApMatchType ())
        {
            case WLAN_AP_SEARCH:
            case WLAN_AP_SEARCH_SAVED_CONNECTED:
            case WLAN_AP_SAVED_CONNECTED:
                return VFX_TRUE;
            default:
                return VFX_FALSE;
        }
    }
    else
    {
        return VFX_FALSE;    
    }
}

VfxBool NetWorkMgrContentProvider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        ) 
{
    VfxBool isHighlight = VFX_FALSE;
    VcpListMenuCell* menuCell = m_listMenu->getCell (index);
    if(menuCell)
    {
        isHighlight = menuCell->m_isHighlight;
    }
    
    if(VFX_FALSE == m_repository->getIsDeleteApProc ())
    {
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
    }

    return VFX_TRUE;
}

VfxBool NetWorkMgrContentProvider::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    if((VFX_FALSE == m_repository->getIsDeleteApProc ()) &&
       (0 == m_repository->getUsefulApNum()))
    {
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_NO_NETWORK);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
        
    return VFX_FALSE;
}

/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappChangePriorityPage", VappChangePriorityPage, VfxPage);

VappChangePriorityPage::VappChangePriorityPage
    (VappWlanRepository *repository, Observer* page) :
        m_isModified(VFX_FALSE), 
        m_repository(repository), 
        m_parentPage(page)
{
	// register page in the respository
	m_repository->registerObserver (this);
}

VappChangePriorityPage::~VappChangePriorityPage() 
{
	// deregister page in the respository
    m_repository->removeObserver (this);
}

void VappChangePriorityPage::onInit ()
{
    VFX_TRACE(("===== Change priority page initialization =====\n"));
    VfxPage::onInit ();
	
     // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_CONNECT_SUCCESS_MSG |
        SUBSCRIBE_CONNECT_FAIL_MSG |
        SUBSCRIBE_CONNECT_REQUEST_MSG); 
	 
    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_MAIN_TEXT));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem (TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappChangePriorityPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Caption
    VFX_OBJ_CREATE (m_caption, VcpFormItemCaption, this);
    m_caption->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_REMEMBERED_NETWORK));  //"Remembered networks"
    m_caption->setPos (0, 0);
    
    // Networks list menu
    VFX_OBJ_CREATE (m_priorityListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX (m_contentProvider, ChangePriorityContentProvider, this, (m_repository, this));
    m_priorityListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_priorityListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_priorityListMenu->setMenuMode (VCP_LIST_MENU_MODE_REORDER, VFX_TRUE);
    m_priorityListMenu->setContentProvider (m_contentProvider);
    m_priorityListMenu->setPos(0, m_caption->getRect ().getHeight ());
    if(getSize ().height > (m_toolBar->getRect ().getHeight () * 2 + m_caption->getRect ().getHeight ()))
    {
        m_priorityListMenu->setSize(getSize().width, getSize ().height - (2 * m_toolBar->getRect ().getHeight () + m_caption->getRect ().getHeight ()));
    }
    else
    {
        m_priorityListMenu->setSize(getSize ());
    }
    m_priorityListMenu->setItemHighlightHidden (VFX_TRUE);
}

void VappChangePriorityPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

	//if Conn num isn't 0 ,disable 'OK' bar
	updateToolBar();	

	// update Aplist and priority
	updateApListPriority();
}

void VappChangePriorityPage::UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{   
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_UPDATE_CHANGE_PRIORITY_PAGE, msg);
    switch(msg)
    {
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:         /* connect event */
		updateApListPriority();		
		updateApListMenu();
	case SUBSCRIBE_CONNECT_FAIL_MSG:            /* connect fail event */
	case SUBSCRIBE_CONNECT_REQUEST_MSG:			/* connect request event */
		updateToolBar();		
		break;
    }
}

void VappChangePriorityPage::updateToolBar() 
{
	//if Conn num isn't 0 ,disable 'OK' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_toolBar->setDisableItem (TOOLBAR_OK, VFX_TRUE);		
	}
	else
	{		
		if(0 == m_repository->getRememberedApNum ())
	    {
	        m_toolBar->setDisableItem (TOOLBAR_OK, VFX_TRUE);
	    }
	    else
	    {
	        m_toolBar->setDisableItem (TOOLBAR_OK, VFX_FALSE);
	    }		
	}
}

void VappChangePriorityPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    switch(id)
    {
        case TOOLBAR_OK:
            if(VFX_TRUE == getIsModified ())
            {
                VFX_TRACE(("==> Priority change\n"));
                m_repository->afterChangePriority (m_tempSavedApList, m_priorityList);
                m_repository->updateApList ();
            }
            break;
        case TOOLBAR_CANCEL:
            break;
        default:
            break;
    }
    getMainScr ()->popPage ();
}

void VappChangePriorityPage::updateApListPriority()
{
	VfxBool isModified = VFX_FALSE;
	VfxS8 index, pos, total = m_repository->getRememberedApNum ();
	VappWlanBaseInfo *temp = NULL;
	VappWlanBaseInfo * const *savedApList = m_repository->getRememberedApArray();


	for(index = 0; index < total; index++)
	{
		m_tempSavedApList[index] = savedApList[index];
	}

	//priority from 1 to N
	for(index = total - 1; index >= 0; index--)
	{
		for(pos = 0; pos < index; pos++)
		{
			if(m_tempSavedApList[pos]->getPriority () > m_tempSavedApList[pos + 1]->getPriority ())
			{
				temp = m_tempSavedApList[pos];
				m_tempSavedApList[pos] = m_tempSavedApList[pos + 1];
				m_tempSavedApList[pos + 1] = temp;
				
				isModified = VFX_TRUE;
			}
		}

		if(VFX_FALSE == isModified)
		{
			break;
		}
		else
		{
			isModified = VFX_FALSE;
		}
	}

	for(index = total - 1; index >= 0; index--)
	{
		m_priorityList[index] = m_tempSavedApList[index]->getPriority ();
	}
}

void VappChangePriorityPage::updateApListMenu()
{
   m_priorityListMenu->resetAllItems (VFX_TRUE);
}

/******************************************************************************/
// Implement the required content provider functions
VfxU32 ChangePriorityContentProvider::getCount() const
{
    return m_repository->getRememberedApNum ();
}

VfxBool ChangePriorityContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    VfxWString description = VFX_WSTR_EMPTY;
    VappWlanBaseInfo** savedApList = m_parentPage->getTempSavedApList ();

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
            text.loadFromMem ((const VfxWChar *)savedApList[index]->getApName());
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT1:
            if(SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == savedApList[index]->getNetworkType ())
            {
                description = savedApList[index]->getNetworkTypeName ();
                description += VFX_WSTR(", ");
                description += savedApList[index]->getAuthModeName ();
                text = description;            
            }
            else
                text = savedApList[index]->getAuthModeName ();
            break;
        case VCP_LIST_MENU_FIELD_SUB_TEXT2:
            break;
    }

    return VFX_TRUE;
}

#if !defined(__VRE_SDK__)
VfxBool ChangePriorityContentProvider::swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        )
{
    VappWlanBaseInfo *profile;
    VappWlanBaseInfo **tempList = m_parentPage->getTempSavedApList ();
        
    VFX_TRACE(("==== Swap Item from %d to %d ====\n", index1, index2));
    VFX_TRACE(("==== Before changed ====\n"));
    VFX_TRACE(("==== Pre: %s Cur: %s ====\n", 
        tempList[index1]->getSsid (),
        tempList[index2]->getSsid ()));

    profile = tempList[index1];
    tempList[index1] = tempList[index2];
    tempList[index2] = profile;

    VFX_TRACE(("==== After changed ====\n"));
    VFX_TRACE(("==== Pre: %s Cur: %s ====\n", 
        tempList[index1]->getSsid (),
        tempList[index2]->getSsid ()));

    m_parentPage->setIsModified (VFX_TRUE);
    return VFX_TRUE;
}
#endif

/******************************************************************************/
/*                          Class VappSelectPopupBuilder                      */
/******************************************************************************/

VappSelectPopupBuilder::VappSelectPopupBuilder(
        VAPP_WLAN_AP_PROPERTY_TYPE_ENUM typeEnum,
        VappWlanProfile* profile,
        VfxMainScr* mainScr,
        VappPropertyPage* parentPage):
        m_clickOk(VFX_FALSE),       
        m_propertyType(typeEnum), m_newProfile(profile), 
        m_selectPopup(NULL), 
        m_mainScr(mainScr), m_parentPage(parentPage)
{
    
}

void VappSelectPopupBuilder::createSelectPopup()
{
    // 1. Get number of items want to be showed
    VfxU32 itemCount = 0;
    VFX_TRACE(("=====Property Type: %d Network type: %d   Auth Mode: %d ======\n", 
        m_propertyType, m_newProfile->getNetworkType (), m_newProfile->getAuthMode ()));
    switch(m_propertyType)
    {
    case WLAN_AP_PROPERTY_NETWORK_TYPE:
        break;
    case WLAN_AP_PROPERTY_AUTH_MODE:
        itemCount = VappWlanToolbox::getSecurityModeNum (m_newProfile->getNetworkType ());
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_INDEX:
        itemCount = VappWlanToolbox::getWepKeyIndexNum ();
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_ENCRYPT:
        itemCount = VappWlanToolbox::getWepKeyEncryptNum ();
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_FORMAT:
        itemCount = VappWlanToolbox::getWepKeyFormatNum ();
        break;
    case WLAN_AP_PROPERTY_WAI_KEY_FORMAT:
        itemCount = VappWlanToolbox::getWaiPskFormatNum ();
        break;
    default:
        break;
    }
    VFX_TRACE(("===== COUNT: %d ======\n", itemCount));

    // 2. create popup
    if(m_selectPopup != NULL)
        VFX_OBJ_CLOSE(m_selectPopup);
    VFX_OBJ_CREATE (m_selectPopup, VcpSelectPopup, m_mainScr);
    m_selectPopup->setType (VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    
    // 3. Set title and register event
    switch(m_propertyType)
    {
    case WLAN_AP_PROPERTY_NETWORK_TYPE:
        break;
    case WLAN_AP_PROPERTY_AUTH_MODE:
        m_selectPopup->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE));
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_INDEX:
        m_selectPopup->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_IN_USE));
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_ENCRYPT:
        m_selectPopup->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_ENCRYPT));
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_FORMAT:
        m_selectPopup->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT));
        break;
    case WLAN_AP_PROPERTY_WAI_KEY_FORMAT:
        m_selectPopup->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAI_PSK_FORMAT));
        break;
    default:
        break;
    }
    m_selectPopup->m_signalPopupState.connect (
        this, &VappSelectPopupBuilder::onPopupStateChanged);
    m_selectPopup->m_signalButtonClicked.connect (
        this, &VappSelectPopupBuilder::onPopupButtonClicked);
    
    // 4. Add item
    VfxU32 index = 0, pos = 0;
    VfxWString itemText;
    VFX_TRACE(("===== Add item ======\n"));
    switch(m_propertyType)
    {
    case WLAN_AP_PROPERTY_NETWORK_TYPE:
        break;
    case WLAN_AP_PROPERTY_AUTH_MODE:
        pos = VappWlanToolbox::getSecurityModeIndex (m_newProfile->getAuthMode ());
        VFX_TRACE(("===== ITEM SELECTED: %d ======\n", pos));
        for(index = 0; index < itemCount; index++)
        {
            itemText = VappWlanToolbox::getSecurityModeStr (index, m_newProfile->getNetworkType ());
            if(index == pos)
            {
                m_selectPopup->addItem (index, itemText, VFX_TRUE);
            }
            else
            {
                m_selectPopup->addItem (index, itemText, VFX_FALSE);
            }
        }
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_INDEX:
        //VappWlanToolbox::setWepKeyIndex();
        pos = VappWlanToolbox::getWepKeyIndex (m_newProfile->getWepKeyIndex ());
        VFX_TRACE(("===== ITEM SELECTED: %d ======\n", pos));
        for(index = 0; index < itemCount; index++)
        {
            itemText = VappWlanToolbox::getWepKeyIndexStr (index);
            if(index == pos)
            {
                m_selectPopup->addItem (index, itemText, VFX_TRUE);
            }
            else
            {
                m_selectPopup->addItem (index, itemText, VFX_FALSE);
            }
        }
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_ENCRYPT:
        //VappWlanToolbox::setWepKeyEncrypt();
        pos = VappWlanToolbox::getWepKeyEncryptIndex (m_newProfile->getWepKeyLen ());
        VFX_TRACE(("===== ITEM SELECTED: %d ======\n", pos));
        for(index = 0; index < itemCount; index++)
        {
            itemText = VappWlanToolbox::getWepKeyEncryptStr (index);
            if(index == pos)
            {
                m_selectPopup->addItem (index, itemText, VFX_TRUE);
            }
            else
            {
                m_selectPopup->addItem (index, itemText, VFX_FALSE);
            }
        }
        break;
    case WLAN_AP_PROPERTY_WEP_KEY_FORMAT:
        //VappWlanToolbox::setWepKeyFormat();
        pos = VappWlanToolbox::getWepKeyFormatIndex(m_newProfile->getWepKeyFormat ());
        VFX_TRACE(("===== ITEM SELECTED: %d ======\n", pos));
        for(index = 0; index < itemCount; index++)
        {
            itemText = VappWlanToolbox::getWepKeyFormatStr (index);
            if(index == pos)
            {
                m_selectPopup->addItem (index, itemText, VFX_TRUE);
            }
            else
            {
                m_selectPopup->addItem (index, itemText, VFX_FALSE);
            }
        }
        break;
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    case WLAN_AP_PROPERTY_WAI_KEY_FORMAT:
        //VappWlanToolbox::setWaiKeyFormat();
        pos = VappWlanToolbox::getWaiPskFormatIndex(m_newProfile->getWapiPskFormat ());
        VFX_TRACE(("===== ITEM SELECTED: %d ======\n", pos));
        for(index = 0; index < itemCount; index++)
        {
            itemText = VappWlanToolbox::getWaiKeyFormatStr (index);
            if(index == pos)
            {
                m_selectPopup->addItem (index, itemText, VFX_TRUE);
            }
            else
            {
                m_selectPopup->addItem (index, itemText, VFX_FALSE);
            }
        }
        break;
#endif  /*__MMI_HIDE_WAPI__*/
#endif  /*__WAPI_SUPPORT__*/
    default:
        break;
    }
    m_selectPopup->show (VFX_TRUE);
    VFX_TRACE(("===== End ======\n"));
}

void VappSelectPopupBuilder::onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    VfxChar    outStr[20];
    VfxWString authModeStr;
    VfxWString encryptModeStr;
    
    VFX_TRACE(("===== onPopupStateChanged state: %d======\n", state));
    if((VFX_FALSE == m_clickOk) || (state != VFX_BASE_POPUP_AFTER_END_ANIMATION))
        return;
    
    switch(m_propertyType)
    {
    case WLAN_AP_PROPERTY_NETWORK_TYPE:
        break;
    case WLAN_AP_PROPERTY_AUTH_MODE:
        authModeStr = VappWlanToolbox::getSecurityModeStr (m_selectPopup->getFirstSeletedId (), m_newProfile->getNetworkType ());
        memset(outStr, 0, 20);
        VappWlanToolbox::convertStrToAscii ((VfxChar *) outStr, authModeStr, authModeStr.getLength ());
        VFX_TRACE(("===== Auth Mode: %s======\n", outStr));

        m_parentPage->onItemTapped (m_selectPopup->getFirstSeletedId ());
        break;
#if 0 		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    case WLAN_AP_PROPERTY_WEP_KEY_INDEX:
    case WLAN_AP_PROPERTY_WEP_KEY_ENCRYPT:
    case WLAN_AP_PROPERTY_WEP_KEY_FORMAT:
        VFX_TRACE(("===== WEP KEY INDEX %d======\n", m_selectPopup->getFirstSeletedId ()));
        m_parentPage->onItemTapped (m_selectPopup->getFirstSeletedId ());
        break;
    case WLAN_AP_PROPERTY_WAI_KEY_FORMAT:
        VFX_TRACE(("===== WAI PSK INDEX %d======\n", m_selectPopup->getFirstSeletedId ()));
        m_parentPage->onItemTapped (m_selectPopup->getFirstSeletedId ());
        break;
    default:
        break;
    }
}

void VappSelectPopupBuilder::onPopupButtonClicked(VfxObject* obj, VfxId id)
{
    VFX_TRACE(("===== onPopupButtonClicked %d======\n", id));
    if(VCP_SELECT_POPUP_BUTTON_OK == id)
    {
        VFX_TRACE(("===== VCP_SELECT_POPUP_BUTTON_OK======\n"));
        m_clickOk = VFX_TRUE;
    }
    else
    {
        m_clickOk = VFX_FALSE;
    }
}

/******************************************************************************/
/*                          Class VappPropertyPage                            */
/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappPropertyPage", VappPropertyPage, VfxPage);
VappPropertyPage::VappPropertyPage() :
        m_titleBar(NULL),
        m_toolBar(NULL), 
        m_functionBar(NULL),
        //m_encryptionModeBtn(NULL),
        m_eapTypesBtn(NULL),
        m_wepSettingsBtn(NULL),
        m_passwordText(NULL),
        m_prevEditor(NULL),
        m_nextEditor(NULL),
        m_curEditor(NULL),
        m_currActiveId(NULL),
        m_focusItemId(NULL),        
        m_tempProfile(NULL)
        
{
    VFX_TRACE(("VappPropertyPage - default constructor\n"));
    m_ssidStr = VFX_WSTR_EMPTY;
    m_preSharedKeyStr = VFX_WSTR_EMPTY;
    m_eapTypeArray[0] = WLAN_EAP_TLS;
    m_eapTypeArray[1] = WLAN_EAP_PEAP;
    m_eapTypeArray[2] = WLAN_EAP_TTLS;
    m_eapTypeArray[3] = WLAN_EAP_SIM;
    m_eapTypeArray[4] = WLAN_EAP_AKA;
}

VappPropertyPage::VappPropertyPage(VappWlanProfile* profile, VappWlanRepository* repository) :
        m_titleBar(NULL),
        m_toolBar(NULL), 
        m_functionBar(NULL),
        //m_encryptionModeBtn(NULL),
        m_eapTypesBtn(NULL),
        m_wepSettingsBtn(NULL),
        m_passwordText(NULL),    
        m_prevEditor(NULL),
        m_nextEditor(NULL),
        m_curEditor(NULL),
        m_tempProfile(profile),
        m_repository(repository)
{
    VFX_TRACE(("VappPropertyPage - constructor\n"));
    m_ssidStr = VFX_WSTR_EMPTY;
    m_preSharedKeyStr = VFX_WSTR_EMPTY;
    m_eapTypeArray[0] = WLAN_EAP_TLS;
    m_eapTypeArray[1] = WLAN_EAP_PEAP;
    m_eapTypeArray[2] = WLAN_EAP_TTLS;
    m_eapTypeArray[3] = WLAN_EAP_SIM;
    m_eapTypeArray[4] = WLAN_EAP_AKA;
}

void VappPropertyPage::onSegmentBtnClick (VfxObject *sender, VfxId id)
{
    srv_dtcnt_wlan_network_type_enum curNetwork = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
    
    VFX_TRACE(("===== Segment Button Clicked (%d)=====\n", id));
    switch(id)
    {
    case SEGMENT_BTN_ID_INFRASTRUCTURE:
        curNetwork = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
        break;
    case SEGMENT_BTN_ID_ADHOC:
        curNetwork = SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC;
        break;
    default:
        break;
    }
    VappWlanToolbox::handleSegmentBtnEvent(curNetwork, m_tempProfile);
    
    // UE
    m_securityModeBtn->setHintText (m_tempProfile->getAuthModeName ());
}

void VappPropertyPage::onPropertyBtnClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Button %d clicked!\n", id));
    
    switch(id)
    {
        case PROPERTY_PAGE_FORM_SECURITY_MODE:
            VappWlanToolbox::setSecurityMode (m_tempProfile->getNetworkType ());
            m_propertyTypeEnum = WLAN_AP_PROPERTY_AUTH_MODE;
            break;
        default:
            break;
    }
    
    // create select popup
    VappSelectPopupBuilder* selectPopupBuilder = NULL;
    
    VFX_OBJ_CREATE_EX (
        selectPopupBuilder, 
        VappSelectPopupBuilder, 
        this,               //getMainScr (),
        (m_propertyTypeEnum, m_tempProfile, getMainScr (), this));

    selectPopupBuilder->createSelectPopup ();
}

void VappPropertyPage::onItemTapped (VfxU32 index)
{
    srv_dtcnt_wlan_auth_mode_enum curAuthMode = VappWlanToolbox::getSecurityMode (index);
    srv_dtcnt_wlan_auth_mode_enum preAuthMode = m_tempProfile->getAuthMode ();
    srv_dtcnt_wlan_encrypt_mode_enum encryptMode = m_tempProfile->getEncryptMode ();

    VFX_TRACE(("===== VappPropertyPage: Tap item %d  =====\n", index));
    switch(m_propertyTypeEnum)
    {
        case WLAN_AP_PROPERTY_AUTH_MODE:
            if(curAuthMode != preAuthMode)
            {
                // Reset encrypt mode if auth. mode changed
                VappWlanToolbox::updateEncryptionMode (curAuthMode, preAuthMode, encryptMode);
                m_tempProfile->setEncryptMode (encryptMode);
                m_tempProfile->setAuthMode (curAuthMode);
                // UE
                VappWlanToolbox::setEncryptionMode (curAuthMode);
                m_securityModeBtn->setHintText (m_tempProfile->getAuthModeName ());
            }
            break;
#if 0			
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        default:
            break;
    }

}

void VappPropertyPage::onWepKeyBtnClick (VfxObject *sender, VfxId id)
{
    VappWepKeySettingPage* wepKeySettingPage = NULL;
    
    VFX_OBJ_CREATE_EX (
        wepKeySettingPage, 
        VappWepKeySettingPage, 
        getMainScr (), 
        (m_tempProfile, m_repository));
    getMainScr ()->pushPage (0, wepKeySettingPage);
}

#ifndef WIFI_AUTH_PSK_ONLY
void VappPropertyPage::onEAPTypesBtnClick (VfxObject *sender, VfxId id)
{
    VappWlanEAPTypesPage* eapTypesPage = NULL;;
    
    VFX_OBJ_CREATE_EX (
        eapTypesPage, 
        VappWlanEAPTypesPage, 
        getMainScr (), 
        (EAP_TYPE_MAIN_PAGE_ITEM_COUNT, WLAN_AP_EAP_TYPE_PAGE_ONE, (supc_abm_eap_type_enum*)m_eapTypeArray, m_tempProfile));
    getMainScr ()->pushPage (0, eapTypesPage);
}
#endif /* WIFI_AUTH_PSK_ONLY */

#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
void VappPropertyPage::onWAICertBtnClicked (VfxObject *sender, VfxId id)
{
    VappWaiCertSettingsPage* waiCertSettingsPage = NULL;
    
    VFX_OBJ_CREATE_EX (
        waiCertSettingsPage, 
        VappWaiCertSettingsPage, 
        this, 
        (m_tempProfile));
    getMainScr ()->pushPage (0, waiCertSettingsPage);
}

void VappPropertyPage::onWAIPSKBtnClicked (VfxObject *sender, VfxId id)
{
    VappWaiPskSettingsPage* waiPskSettingsPage = NULL;
    
    VFX_OBJ_CREATE_EX (
        waiPskSettingsPage, 
        VappWaiPskSettingsPage, 
        this, 
        (m_tempProfile, m_repository));
    getMainScr ()->pushPage (0, waiPskSettingsPage);
}
#endif  // __WAPI_SUPPORT__
#endif  // __MMI_HIDE_WAPI__


void VappPropertyPage::showWarningPopup(const VfxWString& prompt)
{
    VcpConfirmPopup* invalidInputPopup = NULL;

    VFX_OBJ_CREATE (invalidInputPopup, VcpConfirmPopup, getMainScr());
    invalidInputPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
    invalidInputPopup->setText(prompt);
    invalidInputPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
    invalidInputPopup->setAutoDestory(VFX_TRUE);
    invalidInputPopup->show (VFX_TRUE);
}

void VappPropertyPage::setFunctionBarItems()
{
    if(m_curEditor == m_ssidTextInput->getTextBox ())
    {
        m_prevEditor = NULL;
        if(m_passwordText != NULL)
        {
            m_nextEditor = m_passwordText->getTextBox ();
        }
        else
        {
            m_nextEditor = NULL;
        }
    }
    else if(m_passwordText != NULL && 
                    (m_curEditor == m_passwordText->getTextBox ()))
    {
        m_prevEditor = m_ssidTextInput->getTextBox ();
        m_nextEditor = NULL;
    }
    
    m_functionBar->setDisableItem (PROPERTY_PAGE_FORM_FUNC_BAR_PREV, m_prevEditor == NULL);
    m_functionBar->setDisableItem (PROPERTY_PAGE_FORM_FUNC_BAR_NEXT, m_nextEditor == NULL);
}

VfxBool VappPropertyPage::saveProfile ()
{
    VfxU8       totalSavedNum = m_repository->getSavedApNum ();
    VfxWChar*   ssidUnicode;
    VfxWChar*   ssidUnicodeBeforeEdit;	
    VfxChar*    ssidAscii;
    VfxWChar*   passphraseUnicode;
    VfxChar*    passphraseAscii;
    VfxWString  prompt;
    VfxU32      ssidLength;
    VfxU32      passwordLength;
	VfxU32		ssidLengthBytes;
	VfxBool     focus = VFX_FALSE; // use to get the first error item

	// reset the focusItemId, focus the first item 
	m_focusItemId = NULL;
		
    // 1. Verification
    VFX_TRACE(("1. whether the number of account reaches maxinum - 30\n"));
    VFX_TRACE(("2. whether the ssid is null or empty\n"));
    VFX_TRACE(("3. whether the key is legal or not\n"));
    VFX_TRACE(("4. whether exist same access point in the list\n"));
    if(WLAN_SAVED_AP_LIST_NUM_MAX == totalSavedNum && m_repository->getIsInsert () == VFX_TRUE)
    {
        prompt = VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL);
        showWarningPopup(prompt);
        return VFX_FALSE;
    }
    
    m_ssidTextInput->setWarningText (VFX_WSTR_EMPTY);
    if((NULL != m_form->getItem (PROPERTY_PAGE_FORM_TEXT_PASSWORD)) &&
       m_passwordText != NULL)
    {
        m_passwordText->setWarningText (VFX_WSTR_EMPTY);
    }

    ssidLength = m_ssidTextInput->getText ().getLength ();
    if(0 == ssidLength)
    {
        m_ssidTextInput->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_SSID));
        // m_ssidTextInput->setFocused (VFX_TRUE);
        if (!focus)
        {
            focus = VFX_TRUE;
            m_focusItemId = PROPERTY_PAGE_FORM_NETWORK_SSID;
        }			
        return VFX_FALSE;
    }
    
    VFX_ALLOC_MEM (ssidUnicode, (WNDRV_SSID_MAX_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM (ssidUnicodeBeforeEdit, (WNDRV_SSID_MAX_LEN + 1) * ENCODING_LENGTH, this);	
    VFX_ALLOC_MEM (ssidAscii, (WNDRV_SSID_MAX_LEN + 1), this);
    memset(ssidUnicode, 0, (WNDRV_SSID_MAX_LEN + 1) * ENCODING_LENGTH);   
    memset(ssidUnicodeBeforeEdit, 0, (WNDRV_SSID_MAX_LEN + 1) * ENCODING_LENGTH);   	
    memset(ssidAscii, 0, (WNDRV_SSID_MAX_LEN + 1));

    // get ssid of AP
    memcpy(ssidUnicode, m_ssidTextInput->getTextBox ()->getText (), ssidLength * ENCODING_LENGTH);
    mmi_chset_ucs2_to_utf8_string(
    	(VfxU8 *)ssidAscii,(WNDRV_SSID_MAX_LEN + 1),(VfxU8 *)ssidUnicode);
	ssidLengthBytes = mmi_charset_ucs2_to_utf8_length_in_bytes((VfxU8 *)ssidUnicode);

	//get ssid in unicode before edit
	mmi_chset_convert(
		m_tempProfile->getApCharset(),
		MMI_CHSET_UCS2, 
		(CHAR *)m_tempProfile->getSsid (), 
		(CHAR *)ssidUnicodeBeforeEdit,
		(WNDRV_SSID_MAX_LEN + 1) * ENCODING_LENGTH)	;
	
	if((vfx_sys_wcscmp(ssidUnicodeBeforeEdit, ssidUnicode) == 0))
	{
		//do noting.
	}
	else
	{
		m_tempProfile->setSsid((VfxU8 *)ssidAscii, WNDRV_SSID_MAX_LEN);
		m_tempProfile->setSsidLen (ssidLengthBytes);
		m_tempProfile->setApCharset(CHSET_UTF8);
	}
    VFX_TRACE(("===> EDIT PROFILE's SSID: %s LENGTH: %d\n", m_tempProfile->getSsid (), m_tempProfile->getSsidLen ()));

    if(VFX_TRUE == m_repository->checkIsApExisted (m_tempProfile))
    {
        VFX_FREE_MEM(ssidUnicode);
		VFX_FREE_MEM(ssidUnicodeBeforeEdit);
        VFX_FREE_MEM(ssidAscii);
        prompt = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_AP_EXISTED);
        showWarningPopup(prompt);
        return VFX_FALSE;
    }

#ifdef __MMI_OP01_WIFI__	
    // Cannot add default profile in APlist
	if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == m_tempProfile->getNetworkType () &&
	   SRV_DTCNT_WLAN_AUTH_MODE_OPEN == m_tempProfile->getAuthMode () &&
	   custom_wlan_is_operator_network((const char*)m_tempProfile->getSsid ()))
    {
        VFX_FREE_MEM(ssidUnicode);
		VFX_FREE_MEM(ssidUnicodeBeforeEdit);
        VFX_FREE_MEM(ssidAscii);
        VcpConfirmPopup *notEditConfirm;
        VFX_OBJ_CREATE (notEditConfirm, VcpConfirmPopup, getMainScr ());
        notEditConfirm->setInfoType (VCP_POPUP_TYPE_WARNING);
        notEditConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERROR_ADD_DEFAULT_AP));
        notEditConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        notEditConfirm->setAutoDestory(VFX_TRUE);
        notEditConfirm->show (VFX_TRUE);
        return VFX_FALSE;
    }
#endif

    // Check Pre-Share key's validity
    if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_TEXT_PASSWORD))
    {
        if(m_passwordText != NULL)
        {
            VfxU32 length= m_passwordText->getText ().getLength ();
            if(length < PASSPHRASE_KEY_LEN_MIN)
            {
                VFX_FREE_MEM(ssidUnicode);
				VFX_FREE_MEM(ssidUnicodeBeforeEdit);
                VFX_FREE_MEM(ssidAscii);
                m_passwordText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INVALID_KEY));
                // m_passwordText->setFocused (VFX_TRUE);
                m_preSharedKeyStr = VFX_WSTR_EMPTY;
                m_passwordText->getTextBox ()->setText(m_preSharedKeyStr, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
				if (!focus)
				{
					focus = VFX_TRUE;
					m_focusItemId = PROPERTY_PAGE_FORM_TEXT_PASSWORD;
				}	
				return VFX_FALSE;    
            }
        }
    }
    
    // Get value of password text input
    if(m_passwordText != NULL)
    {
        passwordLength = m_passwordText->getText ().getLength ();
        
        if(passwordLength > 0)
        {
            VFX_ALLOC_MEM (passphraseUnicode, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH, this);
            VFX_ALLOC_MEM (passphraseAscii, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1, this);
            memset(passphraseUnicode, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
            memset(passphraseAscii, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);

            // vfx_sys_wcscpy(passphraseUnicode, m_passwordText->getText ().getBuf ());
            memcpy(passphraseUnicode, m_passwordText->getTextBox ()->getText (), passwordLength * ENCODING_LENGTH);
            mmi_wcs_n_to_asc(
                passphraseAscii, passphraseUnicode, 
                passwordLength * ENCODING_LENGTH);
            VFX_TRACE(("===> Passphrase: %s\n", passphraseAscii));
			
			if(strlen ((const char *)m_tempProfile->getPassphrase ()) == 0 &&
			   strlen ((const char *)m_tempProfile->getPsk ()) > 0)
			{
				// WPS connect, APP record psk and clear passphrase,
				// if m_passwordText don't modify, APP will not setPassphrase, 
				// keeping passPhraseLength 0 and psk value. 
				// Dtcnt srv has an encrytion algorithm to manage passphrase or psk value.
				if(0 == strncmp((const char*)passphraseAscii, (const char *)m_tempProfile->getPsk (), SRV_DTCNT_PROF_MAX_PSK_LEN))
				{
					m_tempProfile->clearPassphrase();
				}
				else
				{				
					m_tempProfile->setPassphrase ((const VfxU8 *)passphraseAscii);
				}				
			}
			else
			{			
				m_tempProfile->setPassphrase ((const VfxU8 *)passphraseAscii);
			}
			
            VFX_FREE_MEM(passphraseUnicode);
            VFX_FREE_MEM(passphraseAscii);
        }
    }

    // Check WEP key's validity
    if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY))
    {
        if(VFX_FALSE == VappWlanToolbox::checkWepKey(m_tempProfile))
        {
            VFX_FREE_MEM(ssidUnicode);
			VFX_FREE_MEM(ssidUnicodeBeforeEdit);
            VFX_FREE_MEM(ssidAscii);
            prompt = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_WEP_KEY);
            showWarningPopup(prompt);
            return VFX_FALSE;
        }
    }

   
    VFX_FREE_MEM(ssidUnicode);
    VFX_FREE_MEM(ssidUnicodeBeforeEdit);	
    VFX_FREE_MEM(ssidAscii);

    return VFX_TRUE;
}

/******************************************************************************/
/*                          Class VappJoinNetworkPage                         */
/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappJoinNetworkPage", VappJoinNetworkPage, VfxPage);

VappJoinNetworkPage::VappJoinNetworkPage(VappWlanRepository* repository, Observer* page) : 
    VappPropertyPage(NULL, repository),
    m_parentPage(page)
{	
	// register page in the respository
	m_repository->registerObserver (this);
    VFX_TRACE(("VappJoinNetworkPage - constructor\n"));
}

VappJoinNetworkPage::~VappJoinNetworkPage() 
{
	// deregister page in the respository
    m_repository->removeObserver (this);
}

void VappJoinNetworkPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INIT_JOIN_PAGE);
    VappPropertyPage::onInit ();
	
     // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_CONNECT_SUCCESS_MSG |
        SUBSCRIBE_CONNECT_FAIL_MSG |
        SUBSCRIBE_CONNECT_REQUEST_MSG); 

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    VFX_OBJ_CREATE (m_tempProfile, VappWlanProfile, this);
    VappWlanToolbox::initWlanProfile (m_tempProfile);

    // set the profile's match type as saved one
    m_tempProfile->setApMatchType (WLAN_AP_SAVED);

    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ADD_AP_TITLE));
    setTopBar (m_titleBar);

    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (PROPERTY_PAGE_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem (PROPERTY_PAGE_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappJoinNetworkPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Function Bar
    createFunctionBar();

    // Network SSID
    VFX_OBJ_CREATE(m_ssidTextInput, VcpFormItemTextInput, this);
    VsrvInputBinding inputBind(
                        IMM_INPUT_TYPE_ASCII_CHAR,
                        0,
                        IME_INPUT_STYLE_NONE,
                        static_cast<InputConnection*>(m_ssidTextInput->getTextBox ()->m_editing));
    inputBind.setAllowedChars (VFX_WSTR ("\'+\\\\_\\-. @!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9"));
    m_ssidTextInput->getTextBox ()->setIME (inputBind);
    m_ssidTextInput->getTextBox()->setText(
    								m_ssidStr, 
            						WNDRV_SSID_MAX_LEN,
            						VFX_FALSE,
            						VCP_TEXT_ENCODING_UTF8);
    m_ssidTextInput->getTextBox ()->setFunctionBar (m_functionBar, VFX_FALSE);
    // m_ssidTextInput->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_ssidTextInput->getTextBox ()->m_signalActivated.connect (this, &VappJoinNetworkPage::onTextEditorActivated);
    m_ssidTextInput->setLabelText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ADD_AP_SSID));
    m_ssidTextInput->setLabelPosition (VCPFORM_TOP_LEFT);

    // Network Type
    VFX_OBJ_CREATE (m_networkTypeFrame, VfxFrame, m_form);
    m_networkTypeFrame->setSize (m_form->getSize ().width, 
        SEGMENT_BTN_MAX_HEIGTH + SEGMENT_BTN_TOP_GAPS + SEGMENT_BTN_BOTTOM_GAPS);
    
    VFX_OBJ_CREATE (m_networkTypeBtn, VcpSegmentButton, m_networkTypeFrame);
    m_networkTypeBtn->setPos (
        SEGMENT_BTN_LEFT_GAPS, 
        SEGMENT_BTN_TOP_GAPS);
    if(m_networkTypeFrame->getSize ().width > (SEGMENT_BTN_LEFT_GAPS + SEGMENT_BTN_RIGHT_GAPS))
    {
        m_networkTypeBtn->setSize (
            m_networkTypeFrame->getSize ().width - SEGMENT_BTN_LEFT_GAPS - SEGMENT_BTN_RIGHT_GAPS, 
            SEGMENT_BTN_MAX_HEIGTH);
    }
    else
    {
        m_networkTypeBtn->setSize (
            m_networkTypeFrame->getSize ().width,
            SEGMENT_BTN_MAX_HEIGTH);
    }
    m_networkTypeBtn->setType (VCP_SEGMENT_BUTTON_TYPE_RADIO);
    m_networkTypeBtn->setStyle (VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
    m_networkTypeBtn->addButton (SEGMENT_BTN_ID_INFRASTRUCTURE, NULL, VFX_WSTR_RES(STR_ID_VAPP_WLAN_NETWORK_TYPE_INFRA));
    m_networkTypeBtn->addButton (SEGMENT_BTN_ID_ADHOC, NULL, VFX_WSTR_RES(STR_ID_VAPP_WLAN_NETWORK_TYPE_ADHOC));
    m_networkTypeBtn->setButtonIsHighlighted (SEGMENT_BTN_ID_INFRASTRUCTURE, VFX_TRUE);    
    m_networkTypeBtn->m_signalButtonClicked.connect (
                                    this, &VappJoinNetworkPage::onSegmentBtnClick);
    
    VFX_OBJ_CREATE (m_customFrame, VcpFormItemCustomFrame, this);
    m_customFrame->attachCustomFrame (m_networkTypeFrame); 

    // Security Mode
    VFX_OBJ_CREATE(m_securityModeBtn, VcpFormItemBigButton, this);
    m_securityModeBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE));
    m_securityModeBtn->setHintText (m_tempProfile->getAuthModeName ());
    m_securityModeBtn->getButton ()->setId (PROPERTY_PAGE_FORM_SECURITY_MODE);
    m_securityModeBtn->getButton ()->m_signalClicked.connect (
        this, &VappPropertyPage::onPropertyBtnClick);

    // Append item into form
    m_form->addItem (m_ssidTextInput, PROPERTY_PAGE_FORM_NETWORK_SSID);
    m_form->addItem (m_customFrame, PROPERTY_PAGE_FORM_NETWORK_TYPE);
    m_form->addItem (m_securityModeBtn, PROPERTY_PAGE_FORM_SECURITY_MODE);
}

void VappJoinNetworkPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

	//if Conn num isn't 0 ,disable 'Save' bar
	updateToolBar();
}

void VappJoinNetworkPage::UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{   
    // if setting page is not in active status, return
    if(VFX_FALSE == getMainScr ()->isActive () || VFX_FALSE == isActive ())
    {
        return;
    }

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_UPDATE_JOIN_NETWORK_PAGE, msg);
    switch(msg)
    {
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:         /* connect event */
	case SUBSCRIBE_CONNECT_FAIL_MSG:            /* connect fail event */
	case SUBSCRIBE_CONNECT_REQUEST_MSG:			/* connect request event */
		//if Conn num isn't 0 ,disable 'Save' bar
		updateToolBar();
		break;
    }
}

void VappJoinNetworkPage::updateToolBar()
{
	//if Conn num isn't 0 ,disable 'Save' bar
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_toolBar->setDisableItem (PROPERTY_PAGE_TOOLBAR_SAVE, VFX_TRUE);	
		m_functionBar->setDisableItem (PROPERTY_PAGE_FORM_FUNC_BAR_SAVE, VFX_TRUE); 
	}
	else
	{
		m_toolBar->setDisableItem (PROPERTY_PAGE_TOOLBAR_SAVE, VFX_FALSE);	
		m_functionBar->setDisableItem (PROPERTY_PAGE_FORM_FUNC_BAR_SAVE, VFX_FALSE);
	}
}

void VappJoinNetworkPage::onDeinit ()
{
    VappPropertyPage::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_DEINIT_JOIN_PAGE);
}

void VappJoinNetworkPage::onSegmentBtnClick (VfxObject *sender, VfxId id)
{
    srv_dtcnt_wlan_auth_mode_enum preAuthMode = m_tempProfile->getAuthMode ();
    VappPropertyPage::onSegmentBtnClick (sender, id);
    srv_dtcnt_wlan_auth_mode_enum curAuthMode = m_tempProfile->getAuthMode ();
    arrangeSecuritySettings (curAuthMode, preAuthMode);
}

void VappJoinNetworkPage::onItemTapped (VfxU32 index)
{
    srv_dtcnt_wlan_auth_mode_enum preAuthMode = m_tempProfile->getAuthMode ();
    VappPropertyPage::onItemTapped (index);
    srv_dtcnt_wlan_auth_mode_enum curAuthMode = m_tempProfile->getAuthMode ();

    // To rearrange the display of settings if necessary
    if(WLAN_AP_PROPERTY_AUTH_MODE == m_propertyTypeEnum &&
       curAuthMode != preAuthMode)
    {
        arrangeSecuritySettings (curAuthMode, preAuthMode);
    }
}

void VappJoinNetworkPage::onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive)
{
    if(isActive)
    {
        VFX_TRACE(("Text editor activated!\n"));
        m_curEditor = sender;

        VappPropertyPage::setFunctionBarItems();
    }
    else
    {
        VFX_TRACE(("Text editor deactivated!\n"));
    }
}

void VappJoinNetworkPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
        case PROPERTY_PAGE_TOOLBAR_SAVE:
            // save user input
            if(VFX_TRUE == VappPropertyPage::saveProfile ())
            {
                // Save ap's name
                saveApName();				
                // Add new ap into saved ap list
                m_repository->afterInsertApIntoSavedList (m_tempProfile);
                // m_parentPage->getListMenu ()->reset();
                showAddNewNetworkBallon();
                getMainScr ()->popPage ();
            }
            break;
        case PROPERTY_PAGE_TOOLBAR_CANCEL:
            getMainScr ()->popPage ();
            break;
        default:
            break;
    }
}


void VappJoinNetworkPage::onFuncBarBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case PROPERTY_PAGE_FORM_FUNC_BAR_PREV:
        if(m_prevEditor)
        {
            m_prevEditor->activate ();
        }
        break;
    case PROPERTY_PAGE_FORM_FUNC_BAR_NEXT:
        if(m_nextEditor)
        {
            m_nextEditor->activate ();
        }
        break;        
    case PROPERTY_PAGE_FORM_FUNC_BAR_SAVE:
        if(m_curEditor)
        {
            m_curEditor->deactivate ();
        }
        // save user input
        if(VFX_TRUE == VappPropertyPage::saveProfile ())
        {
            // Save ap's name
            saveApName();
            // Add new ap into saved ap list
            m_repository->afterInsertApIntoSavedList (m_tempProfile);
            showAddNewNetworkBallon();
            getMainScr ()->popPage ();
        }
        break;
    default:
        break;
    }
}

void VappJoinNetworkPage::saveApName()
{
    VfxU8   *name;

    VFX_ALLOC_MEM (name, WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH, this);
    memset(name, 0, WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH);
	
	// convert ssid from UFT8 to unicode, and set it as name by default
	mmi_chset_utf8_to_ucs2_string(
		name,WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH,(VfxU8 *)m_tempProfile->getSsid ());
    m_tempProfile->setApName (name);

    VFX_FREE_MEM(name);
}

void VappJoinNetworkPage::createFunctionBar()
{
    if(m_functionBar != NULL)
    {
        VFX_TRACE(("Function bar has already created!"));
    }
    else
    {
        VFX_TRACE(("Function bar not existed!"));
        VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
        m_functionBar->addItem(PROPERTY_PAGE_FORM_FUNC_BAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
        m_functionBar->setItemSpecial (PROPERTY_PAGE_FORM_FUNC_BAR_SAVE);
        m_functionBar->m_signalButtonTap.connect (
            this, &VappJoinNetworkPage::onFuncBarBtnClick);
    }
}

void VappJoinNetworkPage::arrangeSecuritySettings(
                        srv_dtcnt_wlan_auth_mode_enum curAuthMode,
                        srv_dtcnt_wlan_auth_mode_enum preAuthMode)
{
    if(preAuthMode == curAuthMode)
    {
        return;
    }
    else /* reset */
    {
 #if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        // Remove property - EAP types
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES);
            m_eapTypesBtn = NULL;
        }
        // Remove property - PAK settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_TEXT_PASSWORD))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_TEXT_PASSWORD);
            m_passwordText = NULL;
        }
        // Remove property - WEP KEY settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
            m_wepSettingsBtn = NULL;
        }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__        
        // Remove property - WAI PSK settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WAI_CERT))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_WAI_CERT);
            m_waiCertBtn = NULL;
        }
        // Remove property - WAI Cert. settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WAI_PSK))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_WAI_PSK);
            m_waiPskBtn = NULL;
        }
#endif /* __MMI_HIDE_WAPI__ */
#endif /* __WAPI_SUPPORT__ */

        // Reset function bar
        m_functionBar->removeItem(PROPERTY_PAGE_FORM_FUNC_BAR_PREV);
        m_functionBar->removeItem(PROPERTY_PAGE_FORM_FUNC_BAR_NEXT);
    }

    VsrvInputBinding inputBind;
    
    switch(curAuthMode)
    {
    /* shared */
    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:    
        VFX_OBJ_CREATE(m_wepSettingsBtn, VcpFormItemBigArrowButton, this);
        m_wepSettingsBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_SETTINGS));
        m_wepSettingsBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
        m_wepSettingsBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onWepKeyBtnClick); 
        
        m_form->insertItem (m_wepSettingsBtn, PROPERTY_PAGE_FORM_SECURITY_MODE, PROPERTY_PAGE_FORM_BUTTON_WEP_KEY, VFX_FALSE);
        break;
		
#ifndef WIFI_AUTH_PSK_ONLY	        
    /* 802.1x */
    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X: 
        // EAP typs selection button
        VFX_OBJ_CREATE(m_eapTypesBtn, VcpFormItemBigArrowButton, this);
        m_eapTypesBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPES));
        m_eapTypesBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES);
        m_eapTypesBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onEAPTypesBtnClick);
        
        m_form->insertItem (m_eapTypesBtn, PROPERTY_PAGE_FORM_SECURITY_MODE, PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES, VFX_FALSE);
        break;
        
    /* WPA WPA2 WPAWPA2 */
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:		       
        // EAP typs selection button
        VFX_OBJ_CREATE(m_eapTypesBtn, VcpFormItemBigArrowButton, this);
        m_eapTypesBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPES));
        m_eapTypesBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES);
        m_eapTypesBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onEAPTypesBtnClick);
        
        m_form->insertItem (m_eapTypesBtn, PROPERTY_PAGE_FORM_SECURITY_MODE, PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES, VFX_FALSE);
        break;
#endif /* WIFI_AUTH_PSK_ONLY */

    /* WPAPSK WPA2PSK WPAWPA2PSK*/
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:	
        // Security Settings
        m_functionBar->addItem(PROPERTY_PAGE_FORM_FUNC_BAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_PREV));
        m_functionBar->addItem(PROPERTY_PAGE_FORM_FUNC_BAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_NEXT));

        VFX_OBJ_CREATE(m_passwordText, VcpFormItemTextInput, this);
        inputBind = VsrvInputBinding(
                    IMM_INPUT_TYPE_ASCII_PASSWORD,
                    0,
                    IME_INPUT_STYLE_NONE,
                    static_cast<InputConnection*>(m_passwordText->getTextBox ()->m_editing));
        inputBind.setAllowedChars (VFX_WSTR ("\'+\\\\_\\-. @!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9"));
        m_passwordText->getTextBox ()->setIME(inputBind);
        m_passwordText->getTextBox ()->setText(m_preSharedKeyStr, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
        m_passwordText->getTextBox ()->setFunctionBar (m_functionBar, VFX_FALSE);
        // m_passwordText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
        m_passwordText->getTextBox ()->m_signalActivated.connect (this, &VappJoinNetworkPage::onTextEditorActivated);
        m_passwordText->setLabelText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_PRE_SHARE_KEY));
        m_passwordText->setLabelPosition (VCPFORM_TOP_LEFT);
        
        m_form->insertItem (m_passwordText, PROPERTY_PAGE_FORM_SECURITY_MODE, PROPERTY_PAGE_FORM_TEXT_PASSWORD, VFX_FALSE);
        break;

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__        
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:  /* WAPICERT */
        VFX_OBJ_CREATE(m_waiCertBtn, VcpFormItemBigArrowButton, this);
        m_waiCertBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WAPI_CERT_SETTINGS));
        m_waiCertBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_WAI_CERT);
        m_waiCertBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onWAICertBtnClicked);
        
        m_form->insertItem (m_waiCertBtn, PROPERTY_PAGE_FORM_SECURITY_MODE, PROPERTY_PAGE_FORM_BUTTON_WAI_CERT, VFX_FALSE);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:   
        VFX_OBJ_CREATE(m_waiPskBtn, VcpFormItemBigArrowButton, this);
        m_waiPskBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WAPI_PSK_SETTINGS));
        m_waiPskBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_WAI_PSK);
        m_waiPskBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onWAIPSKBtnClicked);
        
        m_form->insertItem (m_waiPskBtn, PROPERTY_PAGE_FORM_SECURITY_MODE, PROPERTY_PAGE_FORM_BUTTON_WAI_PSK, VFX_FALSE);
        break;
#endif /* __MMI_HIDE_WAPI__ */
#endif /* __WAPI_SUPPORT__ */
    default:
        break;
    }

    VappPropertyPage::setFunctionBarItems();
}

void VappJoinNetworkPage::showAddNewNetworkBallon()
{
    VfxWString hintText = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ADD_AP_HINT_TEXT);

    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_SUCCESS,
        (const WCHAR *)hintText.getBuf ());
}

/******************************************************************************/
/*                          Class VappEditProfilePage                         */
/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappEditProfilePage", VappEditProfilePage, VfxPage);
VappEditProfilePage::VappEditProfilePage()
{
    m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
	// register page in the respository
	m_repository->registerObserver (this);

    VFX_TRACE(("VappEditProfilePage - default constructor\n"));
}

VappEditProfilePage::VappEditProfilePage(VappWlanProfile* profile, VappWlanRepository* repository)
{
    VFX_TRACE(("VappEditProfilePage - constructor\n"));
    // create temp profile and set it as copy of ap which is edited
    VFX_OBJ_CREATE (m_tempProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (profile, m_tempProfile);
    // BSSID is unique for each access point
    // If this ap is SE_SA, then empty the BSSID
    m_tempProfile->clearBssid ();                       
    // Initialize the EAP types if AP's auth. mode is SRV_DTCNT_WLAN_AUTH_MODE_WPA
    if((WLAN_AP_SEARCH == m_tempProfile->getApMatchType ()) &&
       ( (SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY == m_tempProfile->getAuthMode ())  ||
         (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY == m_tempProfile->getAuthMode ()) ))  
    {
        VappWlanToolbox::initAppProfileWithDefaultEapValue (m_tempProfile);
    }
	// Initialize the Charset
	if(profile->getApCharset () == NULL)
	{
		m_tempProfile->setApCharset(CHSET_UTF8);
	}
	else
	{
		m_tempProfile->setApCharset (profile->getApCharset ());
	}
	// save the pointer of ap which would be edited
    VFX_OBJ_CREATE (m_editProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (profile, m_editProfile);
    
    initPropertyStr();
	
	m_repository = repository;
	// register page in the respository
	m_repository->registerObserver (this);
}

VappEditProfilePage::~VappEditProfilePage()
{
	// deregister page in the respository
    m_repository->removeObserver (this);

    VFX_TRACE(("VappEditProfilePage - deconstructor\n"));
}

void VappEditProfilePage::initPropertyStr()
{
    VfxWChar ssidStr[(WNDRV_SSID_MAX_LEN + 1) * ENCODING_LENGTH];
    VfxWChar passwordStr[(SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH];

    memset (ssidStr, 0, sizeof(VfxWChar)*((WNDRV_SSID_MAX_LEN + 1) * ENCODING_LENGTH));
    memset (passwordStr, 0, sizeof(VfxWChar)*((SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH));

	mmi_chset_convert(
		m_tempProfile->getApCharset(),
		MMI_CHSET_UCS2, 
		(CHAR *)m_tempProfile->getSsid (), 
		(CHAR *)ssidStr,
		(WNDRV_SSID_MAX_LEN + 1) * ENCODING_LENGTH)	;
	    
    m_ssidStr.loadFromMem ((const VfxWChar *)ssidStr);
    m_nameStr.loadFromMem ((const VfxWChar *)m_tempProfile->getApName ());

    if(strlen ((const char *)m_tempProfile->getPassphrase ()) > 0)
    {
        mmi_asc_to_ucs2 ((CHAR *)passwordStr, (CHAR *)m_tempProfile->getPassphrase ());
    }
    else if(strlen ((const char *)m_tempProfile->getPsk ()) > 0)
    {
        mmi_asc_to_ucs2 ((CHAR *)passwordStr, (CHAR *)m_tempProfile->getPsk ());
    }
        
    m_preSharedKeyStr.loadFromMem ((const VfxWChar *)passwordStr);
}

    
void VappEditProfilePage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INIT_EDIT_PAGE);
    VappPropertyPage::onInit ();
	
     // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_CONNECT_SUCCESS_MSG |
        SUBSCRIBE_CONNECT_FAIL_MSG |
        SUBSCRIBE_CONNECT_REQUEST_MSG); 

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_AP_TITLE));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (PROPERTY_PAGE_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem (PROPERTY_PAGE_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappEditProfilePage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Function Bar
    createFunctionBar();
    
    // Network Name
    VFX_OBJ_CREATE(m_nameTextInput, VcpFormItemTextInput, this);
    m_nameTextInput->getTextBox ()->setText (m_nameStr, WLAN_PROF_NAME_LEN_MAX - 1);
    m_nameTextInput->getTextBox ()->setFunctionBar (m_functionBar, VFX_FALSE);
    // m_nameTextInput->getTextBox()->setAutoDeactivated (VFX_TRUE);
    m_nameTextInput->getTextBox()->setId(PROPERTY_PAGE_FORM_NETWORK_NAME);
    m_nameTextInput->getTextBox ()->m_signalActivated.connect (this, &VappEditProfilePage::onTextEditorActivated);
    m_nameTextInput->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_AP_NAME));
    m_nameTextInput->setLabelPosition (VCPFORM_TOP_LEFT);

    // Network SSID
    VFX_OBJ_CREATE(m_ssidTextInput, VcpFormItemTextInput, this);
    VsrvInputBinding inputBind(
                    IMM_INPUT_TYPE_ASCII_CHAR,
                    0,
                    IME_INPUT_STYLE_NONE,
                    static_cast<InputConnection*>(m_ssidTextInput->getTextBox ()->m_editing));
    inputBind.setAllowedChars (VFX_WSTR ("\'+\\\\_\\-. @!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9"));
    m_ssidTextInput->getTextBox ()->setIME (inputBind);
    //m_ssidTextInput->getTextBox ()->setText (m_ssidStr, WNDRV_SSID_MAX_LEN);
    m_ssidTextInput->getTextBox()->setText(
    								m_ssidStr, 
            						WNDRV_SSID_MAX_LEN,
            						VFX_FALSE,
            						VCP_TEXT_ENCODING_UTF8);
    m_ssidTextInput->getTextBox ()->setFunctionBar (m_functionBar, VFX_FALSE);
	m_ssidTextInput->getTextBox()->setId(PROPERTY_PAGE_FORM_NETWORK_SSID);
    // m_ssidTextInput->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_ssidTextInput->getTextBox ()->m_signalActivated.connect (this, &VappEditProfilePage::onTextEditorActivated);
    m_ssidTextInput->setLabelText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ADD_AP_SSID));
    m_ssidTextInput->setLabelPosition (VCPFORM_TOP_LEFT);

    // Caption: Network type & security
    VFX_OBJ_CREATE(m_basicSettings, VcpFormItemCaption, this);
    m_basicSettings->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_BASIC_SETTING));
    m_basicSettings->setStyle (VCPFORM_STYLE2);
    
    // Network Type
    VFX_OBJ_CREATE (m_networkTypeFrame, VfxFrame, m_form);
    m_networkTypeFrame->setSize (m_form->getSize ().width, 
        SEGMENT_BTN_MAX_HEIGTH + SEGMENT_BTN_TOP_GAPS + SEGMENT_BTN_BOTTOM_GAPS);
    
    VFX_OBJ_CREATE (m_networkTypeBtn, VcpSegmentButton, m_networkTypeFrame);
    m_networkTypeBtn->setPos (
        SEGMENT_BTN_LEFT_GAPS, 
        SEGMENT_BTN_TOP_GAPS);
    if(m_networkTypeFrame->getSize ().width > (SEGMENT_BTN_LEFT_GAPS + SEGMENT_BTN_RIGHT_GAPS))
    {
        m_networkTypeBtn->setSize (
            m_networkTypeFrame->getSize ().width - SEGMENT_BTN_LEFT_GAPS - SEGMENT_BTN_RIGHT_GAPS, 
            SEGMENT_BTN_MAX_HEIGTH);
    }
    else
    {
        m_networkTypeBtn->setSize (
            m_networkTypeFrame->getSize ().width,
            SEGMENT_BTN_MAX_HEIGTH);
    }
    m_networkTypeBtn->setType (VCP_SEGMENT_BUTTON_TYPE_RADIO);
    m_networkTypeBtn->setStyle (VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
    m_networkTypeBtn->addButton (SEGMENT_BTN_ID_INFRASTRUCTURE, NULL, VFX_WSTR_RES(STR_ID_VAPP_WLAN_NETWORK_TYPE_INFRA));
    m_networkTypeBtn->addButton (SEGMENT_BTN_ID_ADHOC, NULL, VFX_WSTR_RES(STR_ID_VAPP_WLAN_NETWORK_TYPE_ADHOC));
    if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == m_tempProfile->getNetworkType ())
        m_networkTypeBtn->setButtonIsHighlighted (SEGMENT_BTN_ID_INFRASTRUCTURE, VFX_TRUE);    
    else
        m_networkTypeBtn->setButtonIsHighlighted (SEGMENT_BTN_ID_ADHOC, VFX_TRUE);
    m_networkTypeBtn->m_signalButtonClicked.connect (
                                    this, &VappEditProfilePage::onSegmentBtnClick);
    
    VFX_OBJ_CREATE (m_customFrame, VcpFormItemCustomFrame, this);
    m_customFrame->attachCustomFrame (m_networkTypeFrame); 

    // Security Mode
    VFX_OBJ_CREATE(m_securityModeBtn, VcpFormItemBigButton, this);
    m_securityModeBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE));
    m_securityModeBtn->setHintText (m_tempProfile->getAuthModeName ());
    m_securityModeBtn->getButton ()->setId (PROPERTY_PAGE_FORM_SECURITY_MODE);
    m_securityModeBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappPropertyPage::onPropertyBtnClick);

    // Caption: Others
    VFX_OBJ_CREATE(m_otherSettings, VcpFormItemCaption, this);
    m_otherSettings->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_OTHER_SETTING));
    m_otherSettings->setStyle (VCPFORM_STYLE2);

    // TCP/IP settings
    VFX_OBJ_CREATE(m_tcpipSettingsBtn, VcpFormItemBigArrowButton, this);
    m_tcpipSettingsBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_TCPIP_SETTING));
    m_tcpipSettingsBtn->getButton ()->setId (PROPERTY_PAGE_FORM_TCPIP_SETTINGS);
    m_tcpipSettingsBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappEditProfilePage::onTcpIpSettingBtnClick);

    // Advanced settings
    VFX_OBJ_CREATE(m_advancedSettingsBtn, VcpFormItemBigArrowButton, this);
    m_advancedSettingsBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_ADVANCED_SETTING));
    m_advancedSettingsBtn->getButton ()->setId (PROPERTY_PAGE_FORM_ADVANCE_SETTINGS);
    m_advancedSettingsBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappEditProfilePage::onAdvancedSettingBtnClick); 

    // Append item into form
    m_form->addItem (m_nameTextInput, PROPERTY_PAGE_FORM_NETWORK_NAME);
    m_form->addItem (m_ssidTextInput, PROPERTY_PAGE_FORM_NETWORK_SSID);
    m_form->addItem (m_basicSettings, PROPERTY_PAGE_FORM_CAPTION_BASIC);
    m_form->addItem (m_customFrame, PROPERTY_PAGE_FORM_NETWORK_TYPE);
    m_form->addItem (m_securityModeBtn, PROPERTY_PAGE_FORM_SECURITY_MODE);
    m_form->addItem (m_otherSettings, PROPERTY_PAGE_FORM_CAPTION_OTHERS);
    m_form->addItem (m_tcpipSettingsBtn, PROPERTY_PAGE_FORM_TCPIP_SETTINGS);
    m_form->addItem (m_advancedSettingsBtn, PROPERTY_PAGE_FORM_ADVANCE_SETTINGS);
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	

    arrangeSecuritySettings(m_tempProfile->getAuthMode (), SRV_DTCNT_WLAN_AUTH_MODE_TOTAL);

    if(SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP == m_tempProfile->getEncryptMode () &&
       SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X != m_tempProfile->getAuthMode ())
    {
        if(NULL == m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY))
        {
            VFX_OBJ_CREATE(m_wepSettingsBtn, VcpFormItemBigArrowButton, this);
            m_wepSettingsBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_SETTINGS));
            m_wepSettingsBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
            m_wepSettingsBtn->getButton ()->m_signalClicked.connect (
                                this, &VappPropertyPage::onWepKeyBtnClick); 
            m_form->insertItem (m_wepSettingsBtn, PROPERTY_PAGE_FORM_CAPTION_OTHERS, PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
        }
    }
}

void VappEditProfilePage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

	//if Conn num isn't 0 ,disable 'Save' bar
	updateToolBar();
}

void VappEditProfilePage::UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{   
    // if setting page is not in active status, return
    if(VFX_FALSE == getMainScr ()->isActive () || VFX_FALSE == isActive ())
    {
        return;
    }

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_UPDATE_EDIT_NETWORK_PAGE, msg);
    switch(msg)
    {
    case SUBSCRIBE_CONNECT_SUCCESS_MSG:         /* connect event */
	case SUBSCRIBE_CONNECT_FAIL_MSG:            /* connect fail event */
	case SUBSCRIBE_CONNECT_REQUEST_MSG:			/* connect request event */
		updateToolBar();
		break;
    }
}

void VappEditProfilePage::updateToolBar()
{
	if( m_repository->getAPConnNum() != 0 )
	{
		VappWlanSentry::updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
		m_toolBar->setDisableItem (PROPERTY_PAGE_TOOLBAR_SAVE, VFX_TRUE);		
		m_functionBar->setDisableItem (PROPERTY_PAGE_FORM_FUNC_BAR_SAVE, VFX_TRUE); 	
	}
	else
	{
		m_toolBar->setDisableItem (PROPERTY_PAGE_TOOLBAR_SAVE, VFX_FALSE);		
		m_functionBar->setDisableItem (PROPERTY_PAGE_FORM_FUNC_BAR_SAVE, VFX_FALSE);
	}
}

void VappEditProfilePage::onDeinit ()
{
    VappPropertyPage::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_DEINIT_EDIT_PAGE);
}

void VappEditProfilePage::onSegmentBtnClick (VfxObject *sender, VfxId id)
{
    srv_dtcnt_wlan_auth_mode_enum preAuthMode = m_tempProfile->getAuthMode ();
    VappPropertyPage::onSegmentBtnClick (sender, id);
    srv_dtcnt_wlan_auth_mode_enum curAuthMode = m_tempProfile->getAuthMode ();
    // UE
    arrangeSecuritySettings (curAuthMode, preAuthMode);
}

void VappEditProfilePage::onTcpIpSettingBtnClick (VfxObject *sender, VfxU32 id)
{
    VappTcpIpSettingPage* tcpipSettingPage = NULL;
    
    VFX_OBJ_CREATE_EX (
        tcpipSettingPage, 
        VappTcpIpSettingPage, 
        getMainScr (), 
        (m_tempProfile));
    getMainScr ()->pushPage (0, tcpipSettingPage);
}

void VappEditProfilePage::onAdvancedSettingBtnClick (VfxObject *sender, VfxU32 id)
{
    VappAdvancedSettingPage* advancedSettingPage = NULL;
    
    VFX_OBJ_CREATE_EX (
        advancedSettingPage, 
        VappAdvancedSettingPage, 
        getMainScr (), 
        (m_tempProfile));
    getMainScr ()->pushPage (0, advancedSettingPage);
}


void VappEditProfilePage::onItemTapped (VfxU32 id)
{
    srv_dtcnt_wlan_auth_mode_enum preAuthMode = m_tempProfile->getAuthMode ();
    srv_dtcnt_wlan_encrypt_mode_enum preEncryptMode = m_tempProfile->getEncryptMode ();
    VappPropertyPage::onItemTapped (id);
    srv_dtcnt_wlan_auth_mode_enum curAuthMode = m_tempProfile->getAuthMode ();
    srv_dtcnt_wlan_encrypt_mode_enum curEncryptMode = m_tempProfile->getEncryptMode ();

    // To rearrange the display of settings if necessary
    if(WLAN_AP_PROPERTY_AUTH_MODE == m_propertyTypeEnum &&
       curAuthMode != preAuthMode)
    {
        arrangeSecuritySettings (curAuthMode, preAuthMode);
    }
    else if(WLAN_AP_PROPERTY_ENCRYPTION_MODE == m_propertyTypeEnum && 
       curEncryptMode != preEncryptMode)
    {
        // Remove property - WEP KEY settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
            m_wepSettingsBtn = NULL;
        }
        
        switch(curEncryptMode)
        {
            /* shared */
            case SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP:    
                VFX_OBJ_CREATE(m_wepSettingsBtn, VcpFormItemBigArrowButton, this);
                m_wepSettingsBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_SETTINGS));
                m_wepSettingsBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
                m_wepSettingsBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappPropertyPage::onWepKeyBtnClick); 
                m_form->insertItem (m_wepSettingsBtn, PROPERTY_PAGE_FORM_CAPTION_OTHERS, PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
                break;
            default:
                break;
        }
    }
}

void VappEditProfilePage::onFuncBarBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case PROPERTY_PAGE_FORM_FUNC_BAR_PREV:
        if(m_prevEditor)
        {
            m_prevEditor->activate ();
        }
		// scroll to top
		if(PROPERTY_PAGE_FORM_NETWORK_SSID == m_curEditor->getId())
		{
			m_form->scrollItemToView(PROPERTY_PAGE_FORM_NETWORK_NAME, 
				VCPFORM_SCROLL_TOP, VFX_TRUE);
		}
		else if(PROPERTY_PAGE_FORM_TEXT_PASSWORD == m_curEditor->getId())
		{	
			m_form->scrollItemToView(PROPERTY_PAGE_FORM_NETWORK_SSID, 
				VCPFORM_SCROLL_TOP, VFX_TRUE);			
		}
       	break;
    case PROPERTY_PAGE_FORM_FUNC_BAR_NEXT:
        if(m_nextEditor)
        {
            m_nextEditor->activate ();
        }
        break;        
    case PROPERTY_PAGE_FORM_FUNC_BAR_SAVE:
        if(m_curEditor)
        {
            m_curEditor->deactivate ();
        }
        saveEditProfile();
        break;
    default:
        break;
    }
}

void VappEditProfilePage::onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive)
{
    if(isActive)
    {
        VFX_TRACE(("Text editor activated!\n"));
        m_curEditor = sender;
        
        setFunctionBarItems();
    }
    else
    {
        VFX_TRACE(("Text editor deactivated!\n"));
    }
}

void VappEditProfilePage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
        case PROPERTY_PAGE_TOOLBAR_SAVE:
            saveEditProfile();
            break;
        case PROPERTY_PAGE_TOOLBAR_CANCEL:
            // m_parentPage->getNetworksListMenu ()->reset ();
            getMainScr ()->popPage ();
            break;
        default:
            break;
    }
}

void VappEditProfilePage::setFunctionBarItems()
{
    if(m_curEditor == m_nameTextInput->getTextBox ())
    {
        m_prevEditor = NULL;
        m_nextEditor = m_ssidTextInput->getTextBox ();
    }
    else if(m_curEditor == m_ssidTextInput->getTextBox ())
    {
        m_prevEditor = m_nameTextInput->getTextBox ();
        if(m_passwordText != NULL)
        {
            m_nextEditor = m_passwordText->getTextBox ();
        }
        else
        {
            m_nextEditor = NULL;
        }
    }
    else if(m_passwordText != NULL && 
                    m_curEditor == m_passwordText->getTextBox ())
    {
        m_prevEditor = m_ssidTextInput->getTextBox ();
        m_nextEditor = NULL;
    }
    
    m_functionBar->setDisableItem (PROPERTY_PAGE_FORM_FUNC_BAR_PREV, m_prevEditor == NULL);
    m_functionBar->setDisableItem (PROPERTY_PAGE_FORM_FUNC_BAR_NEXT, m_nextEditor == NULL);
}

void VappEditProfilePage::saveEditProfile()
{
	// Decide whether the AP is supported.
	if((SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC == m_tempProfile->getNetworkType()) &&
		(SRV_DTCNT_WLAN_AUTH_MODE_TOTAL ==m_tempProfile->getAuthMode()))
	{
        VcpConfirmPopup *notEditConfirm;
        VFX_OBJ_CREATE (notEditConfirm, VcpConfirmPopup, getMainScr ());
        notEditConfirm->setInfoType (VCP_POPUP_TYPE_WARNING);
        notEditConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVLALID_AUTH_MODE));
        notEditConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        notEditConfirm->setAutoDestory(VFX_TRUE);
        notEditConfirm->show (VFX_TRUE);
        return;
    }

    // Cannot edit profile if it is activated in background once again
    if(SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status() &&
       m_repository->getConnectedAP ()->getProfileId () == m_editProfile->getProfileId ()) 
    {
        VcpConfirmPopup *notEditConfirm;
        VFX_OBJ_CREATE (notEditConfirm, VcpConfirmPopup, getMainScr ());
        notEditConfirm->setInfoType (VCP_POPUP_TYPE_WARNING);
        notEditConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_MGR_NOT_ALLOW_EDIT));
        notEditConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
        notEditConfirm->setAutoDestory(VFX_TRUE);
        notEditConfirm->show (VFX_TRUE);
        return;
    }
	
    m_nameTextInput->setWarningText (VFX_WSTR_EMPTY);
    m_ssidTextInput->setWarningText (VFX_WSTR_EMPTY);
    if(m_passwordText != NULL)
    {
        m_passwordText->setWarningText (VFX_WSTR_EMPTY);
    }
    
    VfxU32 nameLength = m_nameTextInput->getText ().getLength ();
    // Check AP's name
    if(nameLength == 0)
    {
        m_nameTextInput->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_NAME));
        // m_nameTextInput->setFocused (VFX_TRUE);
        m_focusItemId = PROPERTY_PAGE_FORM_NETWORK_NAME;
		m_form->scrollItemToView(m_focusItemId, VCPFORM_SCROLL_TOP);
    }
    else
    {
        // save user input
        if(VFX_TRUE == VappPropertyPage::saveProfile ())
        {
            m_tempProfile->setApName ((const VfxU8*)m_nameTextInput->getText ().getBuf ());
			// set Mgr type
			m_tempProfile->setApMgrType(SRV_DTCNT_WLAN_AP_USER_DEFINE);
            // Add new ap into saved ap list
            m_repository->afterEditAp (m_editProfile, m_tempProfile);
            // m_parentPage->getNetworksListMenu ()->reset ();
            getMainScr ()->popPage ();
        }
		else
		{
			m_form->scrollItemToView(m_focusItemId, VCPFORM_SCROLL_TOP);
		}
    }
}

void VappEditProfilePage::createFunctionBar()
{
    if(m_functionBar != NULL)
    {
        VFX_TRACE(("Function bar has already created!"));
    }
    else
    {
        VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
        m_functionBar->addItem(PROPERTY_PAGE_FORM_FUNC_BAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_PREV));
        m_functionBar->addItem(PROPERTY_PAGE_FORM_FUNC_BAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_NEXT));
        m_functionBar->addItem(PROPERTY_PAGE_FORM_FUNC_BAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
        m_functionBar->setItemSpecial (PROPERTY_PAGE_FORM_FUNC_BAR_SAVE);
        m_functionBar->m_signalButtonTap.connect (
            this, &VappEditProfilePage::onFuncBarBtnClick);
    }
}

void VappEditProfilePage::arrangeSecuritySettings(
                        srv_dtcnt_wlan_auth_mode_enum curAuthMode,
                        srv_dtcnt_wlan_auth_mode_enum preAuthMode)
{
    if(preAuthMode == curAuthMode)
    {
        return;
    }
    
    else /* reset */
    {
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		// Remove property - EAP types
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES);
            m_eapTypesBtn = NULL;
        }
        // Remove property - PAK settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_TEXT_PASSWORD))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_TEXT_PASSWORD);        
            m_passwordText = NULL;
        }
        // Remove property - WEP KEY settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
            m_wepSettingsBtn = NULL;
        }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__        
        // Remove property - WAI PSK settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WAI_CERT))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_WAI_CERT);
            m_waiCertBtn = NULL;
        }
        // Remove property - WAI Cert. settings
        if(NULL != m_form->getItem (PROPERTY_PAGE_FORM_BUTTON_WAI_PSK))
        {
            m_form->removeItem (PROPERTY_PAGE_FORM_BUTTON_WAI_PSK);
            m_waiPskBtn = NULL;
        }
#endif /* __MMI_HIDE_WAPI__ */
#endif
    }

    VsrvInputBinding inputBind;
        
    switch(curAuthMode)
    {
    /* shared */
    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:    
        VFX_OBJ_CREATE(m_wepSettingsBtn, VcpFormItemBigArrowButton, this);
        m_wepSettingsBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_SETTINGS));
        m_wepSettingsBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);
        m_wepSettingsBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappPropertyPage::onWepKeyBtnClick); 
        
        m_form->insertItem (m_wepSettingsBtn, PROPERTY_PAGE_FORM_CAPTION_OTHERS, PROPERTY_PAGE_FORM_BUTTON_WEP_KEY);

        break;

#ifndef WIFI_AUTH_PSK_ONLY			
    /* 802.1x */
    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X: 
        // EAP typs selection button
        VFX_OBJ_CREATE(m_eapTypesBtn, VcpFormItemBigArrowButton, this);
        m_eapTypesBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPES));
        m_eapTypesBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES);
        m_eapTypesBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onEAPTypesBtnClick);
        
        m_form->insertItem (m_eapTypesBtn, PROPERTY_PAGE_FORM_CAPTION_OTHERS, PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES);
        break;
        
    /* WPA WPA2 WPAWPA2 */
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:     
        // EAP typs selection button
        VFX_OBJ_CREATE(m_eapTypesBtn, VcpFormItemBigArrowButton, this);
        m_eapTypesBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPES));
        m_eapTypesBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES);
        m_eapTypesBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onEAPTypesBtnClick);
        
        m_form->insertItem (m_eapTypesBtn, PROPERTY_PAGE_FORM_CAPTION_OTHERS, PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES);
        break;
#endif /* WIFI_AUTH_PSK_ONLY */

    /* WPAPSK WPA2PSK WPAWPA2PSK*/
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
        // Security Settings
        VFX_OBJ_CREATE(m_passwordText, VcpFormItemTextInput, this);
        inputBind = VsrvInputBinding(
                    IMM_INPUT_TYPE_ASCII_PASSWORD,
                    0,
                    IME_INPUT_STYLE_NONE,
                    static_cast<InputConnection*>(m_passwordText->getTextBox ()->m_editing));
        inputBind.setAllowedChars (VFX_WSTR ("\'+\\\\_\\-. @!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9"));
        m_passwordText->getTextBox ()->setIME(inputBind);
        m_passwordText->getTextBox ()->setText(m_preSharedKeyStr, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
        m_passwordText->getTextBox ()->setFunctionBar (m_functionBar, VFX_FALSE);
        // m_passwordText->getTextBox()->setAutoDeactivated (VFX_TRUE);
        m_passwordText->getTextBox ()->setId(PROPERTY_PAGE_FORM_TEXT_PASSWORD);
        m_passwordText->getTextBox ()->m_signalActivated.connect (this, &VappEditProfilePage::onTextEditorActivated);
        m_passwordText->setLabelText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_PRE_SHARE_KEY));
        m_passwordText->setLabelPosition (VCPFORM_TOP_LEFT);
        m_form->insertItem (m_passwordText, PROPERTY_PAGE_FORM_CAPTION_OTHERS, PROPERTY_PAGE_FORM_TEXT_PASSWORD);
        break;

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__        
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:  /* WAPICERT */
        VFX_OBJ_CREATE(m_waiCertBtn, VcpFormItemBigArrowButton, this);
        m_waiCertBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WAPI_CERT_SETTINGS));
        m_waiCertBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_WAI_CERT);
        m_waiCertBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onWAICertBtnClicked);
        
        m_form->insertItem (m_waiCertBtn, PROPERTY_PAGE_FORM_CAPTION_OTHERS, PROPERTY_PAGE_FORM_BUTTON_WAI_CERT);
        break;
        
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:   
        VFX_OBJ_CREATE(m_waiPskBtn, VcpFormItemBigArrowButton, this);
        m_waiPskBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WAPI_PSK_SETTINGS));
        m_waiPskBtn->getButton ()->setId (PROPERTY_PAGE_FORM_BUTTON_WAI_PSK);
        m_waiPskBtn->getButton ()->m_signalClicked.connect (
            this, &VappPropertyPage::onWAIPSKBtnClicked);
        
        m_form->insertItem (m_waiPskBtn, PROPERTY_PAGE_FORM_CAPTION_OTHERS, PROPERTY_PAGE_FORM_BUTTON_WAI_PSK);
        break;
#endif /* __MMI_HIDE_WAPI__ */
#endif        
    default:
        break;
    }

    setFunctionBarItems();
}

/******************************************************************************/
/*                          Class VappWepKeySettingPage                       */
/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWepKeySettingPage", VappWepKeySettingPage, VfxPage);

VappWepKeySettingPage::VappWepKeySettingPage(VappWlanProfile* profile, VappWlanRepository* repository) :
    VappPropertyPage(profile, repository), m_wepTempProfile(NULL)
{
    VFX_TRACE(("===== VappWepKeySettingPage constructor =====\n"));

    VFX_OBJ_CREATE (m_wepTempProfile, VappWlanProfile, this);
    VappWlanToolbox::cloneWlanProfile (m_tempProfile, m_wepTempProfile);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_WEP_KEY_SETTING_PAGE,
            m_wepTempProfile->getWepKeyIndex (),
            m_wepTempProfile->getWepKeyLen (),
            m_wepTempProfile->getWepKeyFormat ());
}

void VappWepKeySettingPage::onInit ()
{
    VFX_TRACE(("===== VappWepKeySettingPage initialization =====\n"));
    VappPropertyPage::onInit ();

    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_SETTINGS));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (WEP_KEY_SETTING_TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (WEP_KEY_SETTING_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWepKeySettingPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(PROPERTY_PAGE_FORM_FUNC_BAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_OK));
    m_functionBar->setItemSpecial (PROPERTY_PAGE_FORM_FUNC_BAR_SAVE);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (
        this, &VappWepKeySettingPage::onFuncBarBtnClick);

    // WEP key in use
    VFX_OBJ_CREATE(m_wepKeyIndexBtn, VcpFormItemBigButton, this);
    m_wepKeyIndexBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_IN_USE));
    m_wepKeyIndexBtn->setHintText (m_wepTempProfile->getWepKeyIndexStr ());
    m_wepKeyIndexBtn->getButton ()->setId (WEP_KEY_PAGE_FORM_BUTTON_INDEX);
    m_wepKeyIndexBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappWepKeySettingPage::onPropertyBtnClick);

    // WEP encryption
    VFX_OBJ_CREATE(m_wepKeyEncryptBtn, VcpFormItemBigButton, this);
    m_wepKeyEncryptBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_ENCRYPT));
    m_wepKeyEncryptBtn->setHintText (m_wepTempProfile->getWepKeyEncryptStr ());
    m_wepKeyEncryptBtn->getButton ()->setId (WEP_KEY_PAGE_FORM_BUTTON_ENCRYPT);
    m_wepKeyEncryptBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappWepKeySettingPage::onPropertyBtnClick);

    // WEP format
    VFX_OBJ_CREATE(m_wepKeyFormatBtn, VcpFormItemBigButton, this);
    m_wepKeyFormatBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT));
    m_wepKeyFormatBtn->setHintText (m_wepTempProfile->getWepKeyFormatStr ());
    m_wepKeyFormatBtn->getButton ()->setId (WEP_KEY_PAGE_FORM_BUTTON_FORMAT);
    m_wepKeyFormatBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappWepKeySettingPage::onPropertyBtnClick);
    
    // WEP key 
    VFX_OBJ_CREATE(m_wepKeyText, VcpFormItemTextInput, this);
    m_wepKeyText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_KEY));
    m_wepKeyText->setLabelPosition (VCPFORM_TOP_LEFT);
    VsrvInputBinding inputBind(
                        IMM_INPUT_TYPE_ASCII_PASSWORD,
                        0,
                        IME_INPUT_STYLE_NONE,
                        static_cast<InputConnection*>(m_wepKeyText->getTextBox ()->m_editing));
    inputBind.setAllowedChars (VFX_WSTR ("\'+\\\\_\\-. @!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9"));
    m_wepKeyText->getTextBox ()->setIME (inputBind);
    // m_wepKeyText->getTextBox ()->setText (m_wepKeyStr, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN);
    m_wepKeyText->getTextBox ()->setFunctionBar (m_functionBar);
    // m_wepKeyText->getTextBox()->setAutoDeactivated (VFX_TRUE);
    adjustWepKeyEditor(VFX_TRUE);
    
    // Append item into form
    m_form->addItem (m_wepKeyIndexBtn, WEP_KEY_PAGE_FORM_BUTTON_INDEX);
    m_form->addItem (m_wepKeyEncryptBtn, WEP_KEY_PAGE_FORM_BUTTON_ENCRYPT);
    m_form->addItem (m_wepKeyFormatBtn, WEP_KEY_PAGE_FORM_BUTTON_FORMAT);
    m_form->addItem (m_wepKeyText, WEP_KEY_PAGE_FORM_TEXT_STRING);
}

void VappWepKeySettingPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
        case WEP_KEY_SETTING_TOOLBAR_OK:
            saveWepKeySettings();
            break;
        case WEP_KEY_SETTING_TOOLBAR_CANCEL:
            getMainScr ()->popPage ();
            break;
        default:
            break;
    }
}

void VappWepKeySettingPage::onPropertyBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case WEP_KEY_PAGE_FORM_BUTTON_INDEX:
        m_propertyTypeEnum = WLAN_AP_PROPERTY_WEP_KEY_INDEX;
        break;
    case WEP_KEY_PAGE_FORM_BUTTON_ENCRYPT:
        m_propertyTypeEnum = WLAN_AP_PROPERTY_WEP_KEY_ENCRYPT;
        break;
    case WEP_KEY_PAGE_FORM_BUTTON_FORMAT:
        m_propertyTypeEnum = WLAN_AP_PROPERTY_WEP_KEY_FORMAT;
        break;
    default:
        break;
    }
    
    // create select popup
    VappSelectPopupBuilder* selectPopupBuilder = NULL;
    VFX_OBJ_CREATE_EX (
        selectPopupBuilder, 
        VappSelectPopupBuilder, 
        this, 
        (m_propertyTypeEnum, m_wepTempProfile, getMainScr (), this));

    selectPopupBuilder->createSelectPopup ();
}

void VappWepKeySettingPage::onItemTapped (VfxU32 index)
{
    VFX_TRACE(("WEP KEY SETTINGS PAGE - %d\n", m_propertyTypeEnum));
    switch(m_propertyTypeEnum)
    {
        case WLAN_AP_PROPERTY_WEP_KEY_INDEX:
            VFX_TRACE(("WLAN_AP_PROPERTY_WEP_KEY_INDEX\n"));
            m_wepTempProfile->setWepKeyIndex (VappWlanToolbox::getWepKeyInUse (index));
            m_wepKeyIndexBtn->setHintText (m_wepTempProfile->getWepKeyIndexStr ());
            break;
        case WLAN_AP_PROPERTY_WEP_KEY_ENCRYPT:
            VFX_TRACE(("WLAN_AP_PROPERTY_WEP_KEY_ENCRYPT\n"));
            m_wepTempProfile->setWepKeyLen (VappWlanToolbox::getWepKeyEncrypt(index));
            m_wepKeyEncryptBtn->setHintText (m_wepTempProfile->getWepKeyEncryptStr ());
            break;
        case WLAN_AP_PROPERTY_WEP_KEY_FORMAT:
            VFX_TRACE(("WLAN_AP_PROPERTY_WEP_KEY_FORMAT\n"));
            m_wepTempProfile->setWepKeyFormat (VappWlanToolbox::getWepKeyFormat(index));
            m_wepKeyFormatBtn->setHintText (m_wepTempProfile->getWepKeyFormatStr ());
            break;
        default:
            break;
    }
    // Adjust WEP key editor's max length user input
    adjustWepKeyEditor(VFX_FALSE);
}

void VappWepKeySettingPage::onFuncBarBtnClick (VfxObject* sender, VfxId id)
{
    // Close VK
    m_wepKeyText->getTextBox ()->deactivate ();
    // Save WEP key string
    if(id == PROPERTY_PAGE_FORM_FUNC_BAR_SAVE)
    {
        saveWepKeySettings();
    }
}

void VappWepKeySettingPage::adjustWepKeyEditor(VfxBool isInit)
{
    VfxS32 wepKeyMaxLen = 1;
    VfxS32 oldWepKeyLen = 0;
    m_wepKeyStr = VFX_WSTR_EMPTY;
    
    switch (m_wepTempProfile->getWepKeyLen ())
    {
        case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64:
            if (m_wepTempProfile->getWepKeyFormat () == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
            {
                wepKeyMaxLen = AP_WEP_KEY_LEN_TEN;
            }
            else
            {
                wepKeyMaxLen = AP_WEP_KEY_LEN_FIVE;
                
            }
            break;
        case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128:
            if (m_wepTempProfile->getWepKeyFormat () == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
            {
                wepKeyMaxLen = AP_WEP_KEY_LEN_TWENTY_SIX;
            }
            else
            {
                wepKeyMaxLen = AP_WEP_KEY_LEN_THIRTEEN;
            }
            break;
        default:
            VFX_ASSERT(0);
            break;
    }

    VfxWChar   wepKeyStr[(SRV_DTCNT_PROF_MAX_WEP_KEY_LEN+1) * ENCODING_LENGTH];
    memset(wepKeyStr, 0, (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN+1) * ENCODING_LENGTH);
    
    if(isInit)
    {
        oldWepKeyLen = strlen((const char *)m_wepTempProfile->getWepKey ());
        if(oldWepKeyLen > 0)
        {
            VFX_TRACE(("WEP key: %s\n", m_wepTempProfile->getWepKey ()));
            mmi_asc_to_ucs2 ((CHAR *)wepKeyStr, (CHAR *)m_wepTempProfile->getWepKey ());
        }
    }
    else
    {
        oldWepKeyLen = mmi_ucs2strlen((const CHAR *)m_wepKeyText->getTextBox ()->getText ());
        if(oldWepKeyLen > 0)
        {
            if (oldWepKeyLen > wepKeyMaxLen)
            {
                mmi_ucs2ncpy((CHAR *)wepKeyStr, (const CHAR *)m_wepKeyText->getTextBox ()->getText (), wepKeyMaxLen);
            }
            else
            {
                mmi_ucs2cpy((CHAR *)wepKeyStr, (const CHAR *)m_wepKeyText->getTextBox ()->getText ());    
            }
        }
    }
    m_wepKeyStr.loadFromMem ((const VfxWChar *)wepKeyStr);
    m_wepKeyText->getTextBox ()->setText (m_wepKeyStr, wepKeyMaxLen);
}

void VappWepKeySettingPage::saveWepKeySettings()
{
    VfxWChar*   wepKeyUnicode;
    VfxChar*    wepKeyAscii;

    if(m_wepKeyText->getText ().getLength () > 0)
    {
        VFX_ALLOC_MEM (wepKeyUnicode, (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1)* ENCODING_LENGTH, this);
        VFX_ALLOC_MEM (wepKeyAscii, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1, this);
        memset(wepKeyUnicode, 0, (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1)* ENCODING_LENGTH);
        memset(wepKeyAscii, 0, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
    
        memcpy(wepKeyUnicode, m_wepKeyText->getTextBox ()->getText (), (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1)* ENCODING_LENGTH);
        mmi_wcs_n_to_asc(wepKeyAscii, wepKeyUnicode, (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1) * ENCODING_LENGTH);
        m_wepTempProfile->setWepKey ((const VfxU8 *) wepKeyAscii);

        VFX_FREE_MEM (wepKeyUnicode);
        VFX_FREE_MEM (wepKeyAscii);
    }
    else
    {
        m_wepTempProfile->clearWepKey ();
    }
    
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_WEP_KEY_SETTING_PAGE,
            m_wepTempProfile->getWepKeyIndex (),
            m_wepTempProfile->getWepKeyLen (),
            m_wepTempProfile->getWepKeyFormat ());
    if(VFX_TRUE == VappWlanToolbox::checkWepKey(m_wepTempProfile))
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_VALID_WEP_KEY_SETTING);
        m_tempProfile->setWepKeyIndex (m_wepTempProfile->getWepKeyIndex ());
        m_tempProfile->setWepKeyLen (m_wepTempProfile->getWepKeyLen ());
        m_tempProfile->setWepKeyFormat (m_wepTempProfile->getWepKeyFormat ());
        m_tempProfile->setWepKey (m_wepTempProfile->getWepKey ());

        getMainScr ()->popPage ();
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INVALID_WEP_KEY_SETTING);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
        // Clean incorrect WEP key string
        m_wepKeyStr = VFX_WSTR_EMPTY;
        VfxS32 maxLen = m_wepKeyText->getTextBox ()->getMaxLength();
        m_wepKeyText->getTextBox ()->setText (m_wepKeyStr, maxLen);
        m_wepKeyText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_WEP_KEY));
    }
}

#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
/******************************************************************************/
/*                          Class VappWaiCertSettingsPage                     */
/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWaiCertSettingsPage", VappWaiCertSettingsPage, VfxPage);
VappWaiCertSettingsPage::VappWaiCertSettingsPage(VappWlanProfile *profile) :
    m_profile(profile),   
    m_waiPrivateKeyStr(VFX_WSTR_EMPTY)
{
    VFX_TRACE(("====Constructor - VappWaiCertSettingsPage====\n"));
    VfxChar*  wapiAse;
    VfxChar*  wapiClient;
    VfxWChar* wapiAseName;
    VfxWChar* wapiClientName;
    VfxWChar* waiPrivateKeyStr;

    VFX_ALLOC_MEM(wapiAse, (SRV_DTCNT_PROF_MAX_USER_LEN + 1), this);
    VFX_ALLOC_MEM(wapiClient, (SRV_DTCNT_PROF_MAX_USER_LEN + 1), this);
    VFX_ALLOC_MEM(wapiAseName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1)* ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(wapiClientName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(waiPrivateKeyStr, (SRV_DTCNT_PROF_MAX_PW_LEN + 2) * ENCODING_LENGTH, this);
    
    memset(wapiAse, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1));
    memset(wapiClient, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1));
    memset(wapiAseName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    memset(wapiClientName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    memset(waiPrivateKeyStr, 0, (SRV_DTCNT_PROF_MAX_PW_LEN + 2) * ENCODING_LENGTH);

    m_tempAseCertName = VFX_WSTR_RES(STR_GLOBAL_NONE);
    m_tempClientCertName = VFX_WSTR_RES(STR_GLOBAL_NONE);

    VFX_TRACE(("Private Key: %s\n", m_profile->getWapiPrivateKeyPasswdStr()));
    if(strlen((const char *)m_profile->getWapiPrivateKeyPasswdStr()) > 0)
    {
        mmi_asc_to_ucs2 ((CHAR *)waiPrivateKeyStr, (CHAR *)m_profile->getWapiPrivateKeyPasswdStr());
        m_waiPrivateKeyStr.loadFromMem ((const VfxWChar *)waiPrivateKeyStr);
    }
    // Get WAPI ASE and Client ID
    m_tempWapiAseId = m_profile->getWapiAseId ();
    m_tempWapiClientId = m_profile->getWapiClientId ();
#ifdef __CERTMAN_SUPPORT__        
    if (0 != m_tempWapiAseId)
    {
        mmi_certman_get_cert_label(
            m_tempWapiAseId , 
            (VfxU8*)wapiAseName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        if(mmi_ucs2strlen((const CHAR *)wapiAseName) > 0)
        {
            mmi_ucs2_n_to_asc((CHAR *)wapiAse, (CHAR *)wapiAseName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1)* ENCODING_LENGTH);
            VFX_TRACE(("&&&&&&&& ASE: %s \n", wapiAse));
            m_tempAseCertName.loadFromMem (wapiAseName);
        }
    }
    VFX_TRACE(("WAPI ASE: %s\n", wapiAse));
    
    if(0 != m_tempWapiClientId)
    {
        mmi_certman_get_cert_label(
            m_tempWapiClientId , 
            (VfxU8*)wapiClientName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        if(mmi_ucs2strlen((const CHAR *)wapiClientName) > 0)
        {
            mmi_ucs2_n_to_asc((CHAR *)wapiClient, (CHAR *)wapiClientName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1)* ENCODING_LENGTH);
            VFX_TRACE(("&&&&&&&& Client: %s \n", wapiClient));
            m_tempClientCertName.loadFromMem (wapiClientName);
        }
    }
    VFX_TRACE(("WAPI Client: %s\n", wapiClient));
#endif

	// register page in the respository
    m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    m_repository->registerObserver (this);

    VFX_FREE_MEM(wapiAse);
    VFX_FREE_MEM(wapiClient);
    VFX_FREE_MEM(wapiAseName);
    VFX_FREE_MEM(wapiClientName);
    VFX_FREE_MEM(waiPrivateKeyStr);
}

VappWaiCertSettingsPage:: ~VappWaiCertSettingsPage()
{
	// deregister page in the respository
    m_repository->removeObserver (this);
}

void VappWaiCertSettingsPage::onInit ()
{
    VFX_TRACE(("===== VappWaiCertSettingsPage initialization =====\n"));
    Observer::onInit ();
  
    // Register messages which are interested
    setSubscribe (
        SUBSCRIBE_SELECT_ASE_MSG |
        SUBSCRIBE_SELECT_CLIENT_MSG);
        
    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WAPI_CERT_SETTINGS));
    setTopBar (m_titleBar);

    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (WAI_CERT_TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (WAI_CERT_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWaiCertSettingsPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(WAI_CERT_PAGE_FORM_FUNC_BAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK));
    m_functionBar->setItemSpecial (WAI_CERT_PAGE_FORM_FUNC_BAR_OK);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (
        this, &VappWaiCertSettingsPage::onFuncBarBtnClick);

    // ASE certificates
    VFX_OBJ_CREATE(m_waiAseCert, VcpFormItemBigArrowButton, this);
    m_waiAseCert->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_ASE_CERT));
    m_waiAseCert->setHintText (m_tempAseCertName);
    m_waiAseCert->getButton ()->setId (WAI_CERT_PAGE_FORM_BUTTON_ASE_CERT);
    m_waiAseCert->getButton ()->m_signalClicked.connect (
        this, &VappWaiCertSettingsPage::onPropertyBtnClick);

    // User certificates
    VFX_OBJ_CREATE(m_waiUserCert, VcpFormItemBigArrowButton, this);
    m_waiUserCert->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_USER_CERT));
    m_waiUserCert->setHintText (m_tempClientCertName);
    m_waiUserCert->getButton ()->setId (WAI_CERT_PAGE_FORM_BUTTON_USER_CERT);
    m_waiUserCert->getButton ()->m_signalClicked.connect (
        this, &VappWaiCertSettingsPage::onPropertyBtnClick);

    // Private key
    VFX_OBJ_CREATE(m_waiPrivateKeyText, VcpFormItemTextInput, this);
    m_waiPrivateKeyText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_PRIVATE_KEY));
    m_waiPrivateKeyText->setLabelPosition (VCPFORM_TOP_LEFT);
    m_waiPrivateKeyText->getTextBox ()->setText(m_waiPrivateKeyStr, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
    m_waiPrivateKeyText->getTextBox ()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);    
    m_waiPrivateKeyText->getTextBox ()->setFunctionBar (m_functionBar);
    // m_waiPrivateKeyText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    
    // Append item into form
    m_form->addItem (m_waiAseCert, WAI_CERT_PAGE_FORM_BUTTON_ASE_CERT);
    m_form->addItem (m_waiUserCert, WAI_CERT_PAGE_FORM_BUTTON_USER_CERT);
    m_form->addItem (m_waiPrivateKeyText, WAI_CERT_PAGE_FORM_TEXT_PRIVATE_KEY);
}

void VappWaiCertSettingsPage::onDeinit ()
{
    VFX_OBJ_CLOSE (m_titleBar);
    VFX_OBJ_CLOSE (m_toolBar);
    VFX_OBJ_CLOSE (m_waiAseCert);
    VFX_OBJ_CLOSE (m_waiUserCert);
    VFX_OBJ_CLOSE (m_waiPrivateKeyText);
    VFX_OBJ_CLOSE (m_form);
    
    Observer::onDeinit ();
    VFX_TRACE(("===== VappWaiCertSettingsPage deinitialization =====\n"));
}

void VappWaiCertSettingsPage::UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{
    // if setting page is not in active status, return
    if(VFX_FALSE == getMainScr ()->isActive () || VFX_FALSE == isActive ())
    {
        return;
    }

    VfxWString  certName = VFX_WSTR_RES(STR_GLOBAL_NONE);
    VfxU8 wapiClientName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    VfxU8 wapiAseName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    
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
        m_waiAseCert->setHintText (certName);
        break;
    case SUBSCRIBE_SELECT_CLIENT_MSG:
		m_tempWapiClientId = m_repository->getWapiClientId ();
		memset(wapiClientName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);		
        mmi_certman_get_cert_label(
            m_tempWapiClientId,
            wapiClientName,
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    	certName.loadFromMem ((const VfxWChar *) wapiClientName);
        m_waiUserCert->setHintText (certName);
        break;
    default:
        break;
    }
}


void VappWaiCertSettingsPage::onPropertyBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case WAI_CERT_PAGE_FORM_BUTTON_ASE_CERT:
#ifdef __CERTMAN_SUPPORT__        
        VappWlanSentry::SendSelectASECertRequest(STR_ID_VAPP_WLAN_INPUT_WAPI_ASE_CERT);
#endif
        break;
    case WAI_CERT_PAGE_FORM_BUTTON_USER_CERT:
#ifdef __CERTMAN_SUPPORT__        
        VappWlanSentry::SendSelectClientCertRequest(STR_ID_VAPP_WLAN_INPUT_WAPI_USER_CERT);
#endif
        break;
    default:
        break;
    }
}

void VappWaiCertSettingsPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    switch(id)
    {
        case WAI_CERT_TOOLBAR_OK:
            saveWaiCertSettings();
            break;
        case WAI_CERT_TOOLBAR_CANCEL:
            break;
        default:
            break;
    }
    getMainScr ()->popPage ();
}

void VappWaiCertSettingsPage::onFuncBarBtnClick (VfxObject *sender, VfxId id)
{
    // Close VK
    m_waiPrivateKeyText->getTextBox ()->deactivate ();

    if(id == WAI_CERT_PAGE_FORM_FUNC_BAR_OK)
    {
        saveWaiCertSettings();
        getMainScr ()->popPage ();
    }
}

void VappWaiCertSettingsPage::saveWaiCertSettings()
{
    VfxChar* waiPrivateKey;
    
    VFX_ALLOC_MEM(waiPrivateKey, SRV_DTCNT_PROF_MAX_PW_LEN + 2, this);
    memset(waiPrivateKey, 0, SRV_DTCNT_PROF_MAX_PW_LEN + 2);
    
    VfxWString waiPrivateKeyText = m_waiPrivateKeyText->getText ();
    VfxU32     waiPrivateKeyLen  = waiPrivateKeyText.getLength ();

    if(waiPrivateKeyLen < SRV_DTCNT_PROF_MAX_PW_LEN + 2)
        VappWlanToolbox::convertStrToAscii (waiPrivateKey, waiPrivateKeyText, waiPrivateKeyLen);
    else
        VappWlanToolbox::convertStrToAscii (waiPrivateKey, waiPrivateKeyText, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
    
    m_profile->setWapiAseId (m_tempWapiAseId);
    m_profile->setWapiClientId (m_tempWapiClientId);
    m_profile->setWapiPrivateKeyPasswdStr ((const VfxS8*)waiPrivateKey);

    VFX_TRACE(("WAPI Private key: %s!\n", waiPrivateKey));
    VFX_FREE_MEM (waiPrivateKey);
}

/******************************************************************************/
/*                          Class VappWaiPskSettingsPage                      */
/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWaiPskSettingsPage", VappWaiPskSettingsPage, VfxPage);
VappWaiPskSettingsPage::VappWaiPskSettingsPage(VappWlanProfile* profile, VappWlanRepository* repository) :
    VappPropertyPage(profile, repository), 
    m_waiPskStr(VFX_WSTR_EMPTY)
{
    VfxWChar   waiPskStr[(SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1) * ENCODING_LENGTH];
    memset(waiPskStr, 0, (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1) * ENCODING_LENGTH);
    
    if(strlen((const char *)m_tempProfile->getWapiPskStr ()) > 0)
    {
        mmi_asc_to_ucs2 ((CHAR *)waiPskStr, (CHAR *)m_tempProfile->getWapiPskStr ());
        m_waiPskStr.loadFromMem ((const VfxWChar *)waiPskStr);
    }
}

void VappWaiPskSettingsPage::onInit ()
{
    VFX_TRACE(("===== VappWaiPskSettingsPage initialization =====\n"));
    VappPropertyPage::onInit ();

    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_WAPI_PSK_SETTINGS));
    setTopBar (m_titleBar);

    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (WAI_PSK_TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (WAI_PSK_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWaiPskSettingsPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(WAI_PSK_PAGE_FORM_FUNC_BAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK));
    m_functionBar->setItemSpecial (WAI_PSK_PAGE_FORM_FUNC_BAR_OK);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (
        this, &VappWaiPskSettingsPage::onFuncBarBtnClick);

    // WAI PSK 
    VFX_OBJ_CREATE(m_waiPskFormat, VcpFormItemBigButton, this);
    m_waiPskFormat->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAI_PSK_FORMAT));
    m_waiPskFormat->setHintText (m_tempProfile->getWaiKeyFormatStr());
    m_waiPskFormat->getButton ()->setId (WAI_PSK_PAGE_FORM_BUTTON_PSK_FORMAT);
    m_waiPskFormat->getButton ()->m_signalClicked.connect (
                                    this, &VappWaiPskSettingsPage::onPropertyBtnClick);
    m_orignalFormat = m_tempProfile->getWapiPskFormat ();

    // Input password
    VFX_OBJ_CREATE(m_waiPskText, VcpFormItemTextInput, this);
    m_waiPskText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAI_PSK));
    m_waiPskText->setLabelPosition (VCPFORM_TOP_LEFT);
    VsrvInputBinding inputBind(
                        IMM_INPUT_TYPE_ASCII_PASSWORD,
                        0,
                        IME_INPUT_STYLE_NONE,
                        static_cast<InputConnection*>(m_waiPskText->getTextBox ()->m_editing));
    inputBind.setAllowedChars (VFX_WSTR ("\'+\\\\_\\-. @!#$%&*/=?(),:;[]<>\"^`{|}~A-Za-z0-9"));
    m_waiPskText->getTextBox ()->setIME (inputBind);
    m_waiPskText->getTextBox ()->setText(m_waiPskStr, SRV_DTCNT_PROF_MAX_USER_LEN);
    m_waiPskText->getTextBox ()->setFunctionBar (m_functionBar);

    // Append item into form
    m_form->addItem (m_waiPskFormat, WAI_PSK_PAGE_FORM_BUTTON_PSK_FORMAT);
    m_form->addItem (m_waiPskText, WAI_PSK_PAGE_FORM_TEXT_PSK);
}

void VappWaiPskSettingsPage::onDeinit ()
{
    VFX_OBJ_CLOSE (m_titleBar);
    VFX_OBJ_CLOSE (m_toolBar);
    VFX_OBJ_CLOSE (m_waiPskFormat);
    VFX_OBJ_CLOSE (m_waiPskText);
    VFX_OBJ_CLOSE (m_form);

    VappPropertyPage::onDeinit ();
    VFX_TRACE(("===== VappWaiPskSettingsPage deinitialization =====\n"));
}

void VappWaiPskSettingsPage::onBack ()
{
    VFX_TRACE(("===== Back to property page =====\n"));
    m_tempProfile->setWapiPskFormat (m_orignalFormat);   
    
    VfxPage::onBack ();
}

void VappWaiPskSettingsPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
        case WAI_PSK_TOOLBAR_OK:
            if(saveWaiPskSettings())
                getMainScr ()->popPage ();
            else
            {
                m_waiPskStr = VFX_WSTR_EMPTY;
                VfxS32 maxLen = m_waiPskText->getTextBox ()->getMaxLength();
                m_waiPskText->getTextBox ()->setText (m_waiPskStr, maxLen);
                m_waiPskText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INVALID_KEY));
            }
            break;
        case WAI_PSK_TOOLBAR_CANCEL:
            m_tempProfile->setWapiPskFormat (m_orignalFormat);
            getMainScr ()->popPage ();
            break;
        default:
            break;
    }
}

void VappWaiPskSettingsPage::onPropertyBtnClick (VfxObject *sender, VfxId id)
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

void VappWaiPskSettingsPage::onItemTapped (VfxU32 index)
{
    m_tempProfile->setWapiPskFormat (VappWlanToolbox::getWaiKeyFormat (index));
    m_waiPskFormat->setHintText (m_tempProfile->getWaiKeyFormatStr ());
}

void VappWaiPskSettingsPage::onFuncBarBtnClick (VfxObject *sender, VfxId id)
{
    // Close VK
    m_waiPskText->getTextBox ()->deactivate ();

    if(id == WAI_PSK_PAGE_FORM_FUNC_BAR_OK)
    {
        if(saveWaiPskSettings())
            getMainScr ()->popPage ();
        else
        {
            // VappWlanToolbox::showInvalidPopup (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INVALID_KEY), getMainScr ());

            m_waiPskStr = VFX_WSTR_EMPTY;
            VfxS32 maxLen = m_waiPskText->getTextBox ()->getMaxLength();
            m_waiPskText->getTextBox ()->setText (m_waiPskStr, maxLen);
            m_waiPskText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INVALID_KEY));
        }
    }
}


VfxBool VappWaiPskSettingsPage::saveWaiPskSettings()
{
    VfxChar* wapiPsk;
    VfxBool  isValid = VFX_FALSE;

    VFX_ALLOC_MEM (wapiPsk, SRV_DTCNT_PROF_MAX_USER_LEN + 1, this);
    memset(wapiPsk, 0, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
    
    VfxWString wapiPskText = m_waiPskText->getText ();
    VfxU32     wapiPskLen  = wapiPskText.getLength ();

    if(wapiPskLen < SRV_DTCNT_PROF_MAX_USER_LEN + 1)
    {
        VappWlanToolbox::convertStrToAscii (wapiPsk, wapiPskText, wapiPskLen);
    }
    else
    {
        VappWlanToolbox::convertStrToAscii (wapiPsk, wapiPskText, SRV_DTCNT_PROF_MAX_USER_LEN);
    }

    if(0 == m_tempProfile->getWapiPskFormat ())
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
        m_tempProfile->setWapiPskStr ((const VfxU8 *)wapiPsk);
        VFX_FREE_MEM (wapiPsk);
        return VFX_TRUE;
    }
    else
    {
        VFX_FREE_MEM (wapiPsk);
        return VFX_FALSE;
    }
}
#endif   //__WAPI_SUPPORT__
#endif   // __MMI_HIDE_WAPI__

/******************************************************************************/
/*                          Class VappTcpIpSettingPage                        */
/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappTcpIpSettingPage", VappTcpIpSettingPage, VfxPage);

VappTcpIpSettingPage::VappTcpIpSettingPage(VappWlanProfile* profile):
    m_profile(profile),
	m_currActiveId(TCP_IP_PAGE_FORM_NETWORK_TOTAL),
	m_focusItemId(TCP_IP_PAGE_FORM_NETWORK_TOTAL)
{
    VFX_TRACE(("===== VappTcpIpSettingPage constructor =====\n"));
    m_ipAddrStr = initItemValue(m_profile->getIpAddr ());
    m_netmaskStr = initItemValue(m_profile->getNetmask ());
    m_gatewayStr = initItemValue(m_profile->getGateway ());
    m_dns1Str = initItemValue(m_profile->getDns1 ());
    m_dns2Str = initItemValue(m_profile->getDns2 ());
}

void VappTcpIpSettingPage::onInit ()
{
    VFX_TRACE(("===== VappTcpIpSettingPage initialization =====\n"));
    VfxPage::onInit ();

    setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_TCPIP_SETTING));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (TCP_IP_SETTING_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem (TCP_IP_SETTING_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappTcpIpSettingPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Use DHCP
    VFX_OBJ_CREATE (m_dhcpSwitchCell, VcpFormItemSwitchCell, this);
    m_dhcpSwitchCell->setIsTappable (VFX_FALSE);
    m_dhcpSwitchCell->setMainText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_USE_DHCP));
    m_dhcpSwitchCell->m_signalSwitchChangeReq.connect (
        this, &VappTcpIpSettingPage::onSwitchStatusChanged);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(TCP_IP_PAGE_FORM_FUNC_BAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_PREV));
    m_functionBar->addItem(TCP_IP_PAGE_FORM_FUNC_BAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_NEXT));
    m_functionBar->addItem(TCP_IP_PAGE_FORM_FUNC_BAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_functionBar->setItemSpecial (TCP_IP_PAGE_FORM_FUNC_BAR_SAVE);
    m_functionBar->m_signalButtonTap.connect (
        this, &VappTcpIpSettingPage::onFuncBarBtnClick);
    
    // IP address
    VFX_OBJ_CREATE(m_ipAddrText, VcpFormItemTextInput, this);
    VsrvInputBinding ipInputBind(
        IMM_INPUT_TYPE_DECIMAL_NUMERIC, 
        IME_SKIP_DECIMAL_CHECK, 
        0, 
        m_ipAddrText->getTextBox()->m_editing);
    m_ipAddrText->getTextBox ()->setText (m_ipAddrStr, TCP_IP_ADDR_LEN_MAX - 1);
    m_ipAddrText->getTextBox ()->setIME(ipInputBind);
    m_ipAddrText->getTextBox ()->setFunctionBar (m_functionBar);
    // m_ipAddrText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_ipAddrText->getTextBox()->setId(TCP_IP_PAGE_FORM_TEXT_IP_ADDR);
    m_ipAddrText->getTextBox ()->m_signalActivated.connect (this, &VappTcpIpSettingPage::onTextEditorActivated);
    m_ipAddrText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_IP_ADDR));
    m_ipAddrText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Subnet mask
    VFX_OBJ_CREATE(m_netmaskText, VcpFormItemTextInput, this);
    VsrvInputBinding subnetInputBind(
        IMM_INPUT_TYPE_DECIMAL_NUMERIC, 
        IME_SKIP_DECIMAL_CHECK, 
        0, 
        m_netmaskText->getTextBox()->m_editing);
    m_netmaskText->getTextBox ()->setText (m_netmaskStr, TCP_IP_ADDR_LEN_MAX - 1);
    m_netmaskText->getTextBox ()->setIME(subnetInputBind);
    m_netmaskText->getTextBox ()->setFunctionBar (m_functionBar);
    // m_netmaskText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_netmaskText->getTextBox()->setId(TCP_IP_PAGE_FORM_TEXT_NETMASK);
    m_netmaskText->getTextBox ()->m_signalActivated.connect (this, &VappTcpIpSettingPage::onTextEditorActivated);
    m_netmaskText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_NETMASK));
    m_netmaskText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Default gateway
    VFX_OBJ_CREATE(m_gatewayText, VcpFormItemTextInput, this);
    VsrvInputBinding gatewayInputBind(
        IMM_INPUT_TYPE_DECIMAL_NUMERIC, 
        IME_SKIP_DECIMAL_CHECK, 
        0, 
        m_gatewayText->getTextBox()->m_editing);
    m_gatewayText->getTextBox ()->setText (m_gatewayStr, TCP_IP_ADDR_LEN_MAX - 1);
    m_gatewayText->getTextBox ()->setIME(gatewayInputBind);
    m_gatewayText->getTextBox ()->setFunctionBar (m_functionBar);
    // m_gatewayText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_gatewayText->getTextBox()->setId(TCP_IP_PAGE_FORM_TEXT_GATEWAY);
    m_gatewayText->getTextBox ()->m_signalActivated.connect (this, &VappTcpIpSettingPage::onTextEditorActivated);
    m_gatewayText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_GATEWAY));
    m_gatewayText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Primary DNS
    VFX_OBJ_CREATE(m_dns1Text, VcpFormItemTextInput, this);
    VsrvInputBinding dns1InputBind(
        IMM_INPUT_TYPE_DECIMAL_NUMERIC, 
        IME_SKIP_DECIMAL_CHECK, 
        0, 
        m_dns1Text->getTextBox()->m_editing);
    m_dns1Text->getTextBox ()->setText (m_dns1Str, TCP_IP_ADDR_LEN_MAX - 1);
    m_dns1Text->getTextBox ()->setIME(dns1InputBind);
    m_dns1Text->getTextBox ()->setFunctionBar (m_functionBar);
    // m_dns1Text->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_dns1Text->getTextBox()->setId(TCP_IP_PAGE_FORM_TEXT_DNS1);
    m_dns1Text->getTextBox ()->m_signalActivated.connect (this, &VappTcpIpSettingPage::onTextEditorActivated);
    m_dns1Text->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_DNS1));
    m_dns1Text->setLabelPosition (VCPFORM_TOP_LEFT);

    // Secondary DNS
    VFX_OBJ_CREATE(m_dns2Text, VcpFormItemTextInput, this);
    VsrvInputBinding dns2InputBind(
        IMM_INPUT_TYPE_DECIMAL_NUMERIC, 
        IME_SKIP_DECIMAL_CHECK, 
        0, 
        m_dns2Text->getTextBox()->m_editing);
    m_dns2Text->getTextBox ()->setText (m_dns2Str, TCP_IP_ADDR_LEN_MAX - 1);
    m_dns2Text->getTextBox ()->setIME(dns2InputBind);
    m_dns2Text->getTextBox ()->setFunctionBar (m_functionBar);
    // m_dns2Text->getTextBox ()->setAutoDeactivated (VFX_TRUE);  
    m_dns2Text->getTextBox()->setId(TCP_IP_PAGE_FORM_TEXT_DNS2);
    m_dns2Text->getTextBox ()->m_signalActivated.connect (this, &VappTcpIpSettingPage::onTextEditorActivated);
    m_dns2Text->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_DNS2));
    m_dns2Text->setLabelPosition (VCPFORM_TOP_LEFT);

    // Set status
    if(VFX_TRUE == m_profile->getUseDhcp ())
    {
        m_dhcpSwitchCell->setSwitchStatus (VFX_TRUE);
        m_ipAddrText->setIsDisabled (VFX_TRUE);
        m_netmaskText->setIsDisabled (VFX_TRUE);
        m_gatewayText->setIsDisabled (VFX_TRUE);
        m_dns1Text->setIsDisabled (VFX_TRUE);
        m_dns2Text->setIsDisabled (VFX_TRUE);
    }
    else
    {
        m_dhcpSwitchCell->setSwitchStatus (VFX_FALSE);
        m_ipAddrText->setIsDisabled (VFX_FALSE);
        m_netmaskText->setIsDisabled (VFX_FALSE);
        m_gatewayText->setIsDisabled (VFX_FALSE);
        m_dns1Text->setIsDisabled (VFX_FALSE);
        m_dns2Text->setIsDisabled (VFX_FALSE);
    }
    
    // Append item into form
    m_form->addItem (m_dhcpSwitchCell, TCP_IP_PAGE_FORM_BUTTON_USE_DHCP);
    m_form->addItem (m_ipAddrText, TCP_IP_PAGE_FORM_TEXT_IP_ADDR);
    m_form->addItem (m_netmaskText, TCP_IP_PAGE_FORM_TEXT_NETMASK);
    m_form->addItem (m_gatewayText, TCP_IP_PAGE_FORM_TEXT_GATEWAY);
    m_form->addItem (m_dns1Text, TCP_IP_PAGE_FORM_TEXT_DNS1);
    m_form->addItem (m_dns2Text, TCP_IP_PAGE_FORM_TEXT_DNS2);
}

void VappTcpIpSettingPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VfxU8 checkRes = 1;
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
        case TCP_IP_SETTING_TOOLBAR_SAVE:
            checkItemValue (m_ipAddrText, m_tempIpAddr, &checkRes);
            checkItemValue (m_netmaskText, m_tempNetmaskAddr, &checkRes);
            checkItemValue (m_gatewayText, m_tempGatewayAddr, &checkRes);
            checkItemValue (m_dns1Text, m_tempDns1Addr, &checkRes);
            checkItemValue (m_dns2Text, m_tempDns2Addr, &checkRes);
			
			// save TCP/IP settings
			if((VFX_FALSE == m_dhcpSwitchCell->getSwitchStatus ()) && (checkRes == 0))
			{
				m_form->scrollItemToView(m_focusItemId, VCPFORM_SCROLL_TOP);
			}
            if(VFX_TRUE == m_dhcpSwitchCell->getSwitchStatus () ||
              ((VFX_FALSE == m_dhcpSwitchCell->getSwitchStatus ()) && (checkRes == 1)))
            {
                saveTcpIpSettings ();
                getMainScr ()->popPage ();
            }
            break;
        case TCP_IP_SETTING_TOOLBAR_CANCEL:
            getMainScr ()->popPage ();
            break;
        default:
            break;
    }
}

void VappTcpIpSettingPage::onSwitchStatusChanged(
        VcpFormItemSwitchCell* sender,      // Sender
        VfxId id,                           // Sender id
        VfxBool status                      // new switch value
        )
{
    VFX_TRACE(("===== Switch status as %d=====\n", status));

	if( m_currActiveId != TCP_IP_PAGE_FORM_NETWORK_TOTAL)
	{
		// de-active editor
    	VcpFormItemTextInput* textInput;
    	VcpTextEditor *editor;
    	textInput = (VcpFormItemTextInput*)(m_form->getItem(m_currActiveId));
    	editor = textInput->getTextBox();
    	editor->deactivate();
		m_currActiveId = TCP_IP_PAGE_FORM_NETWORK_TOTAL;
	}
	
    if(status == VFX_TRUE)
    {
        m_dhcpSwitchCell->setSwitchStatus (VFX_TRUE);
        m_ipAddrText->setIsDisabled (VFX_TRUE);
        m_netmaskText->setIsDisabled (VFX_TRUE);
        m_gatewayText->setIsDisabled (VFX_TRUE);
        m_dns1Text->setIsDisabled (VFX_TRUE);
        m_dns2Text->setIsDisabled (VFX_TRUE);
    }
    else
    {
        m_dhcpSwitchCell->setSwitchStatus (VFX_FALSE);
        m_ipAddrText->setIsDisabled (VFX_FALSE);
        m_netmaskText->setIsDisabled (VFX_FALSE);
        m_gatewayText->setIsDisabled (VFX_FALSE);
        m_dns1Text->setIsDisabled (VFX_FALSE);
        m_dns2Text->setIsDisabled (VFX_FALSE);
    }
}

void VappTcpIpSettingPage::onFuncBarBtnClick (VfxObject *sender, VfxId id)
{
    VfxU8 checkRes = 1;
    
    switch(id)
    {
    case TCP_IP_PAGE_FORM_FUNC_BAR_PREV:
        if(m_prevEditor)
        {
            m_prevEditor->activate ();
        }
        break;
    case TCP_IP_PAGE_FORM_FUNC_BAR_NEXT:
        if(m_nextEditor)
        {
            m_nextEditor->activate ();
        }
        break;        
    case TCP_IP_PAGE_FORM_FUNC_BAR_SAVE:
        if(m_curEditor)
        {
            m_curEditor->deactivate ();
        }

        checkItemValue (m_ipAddrText, m_tempIpAddr, &checkRes);
        checkItemValue (m_netmaskText, m_tempNetmaskAddr, &checkRes);
        checkItemValue (m_gatewayText, m_tempGatewayAddr, &checkRes);
        checkItemValue (m_dns1Text, m_tempDns1Addr, &checkRes);
        checkItemValue (m_dns2Text, m_tempDns2Addr, &checkRes);
		
        // save TCP/IP settings
		if((VFX_FALSE == m_dhcpSwitchCell->getSwitchStatus ()) && (checkRes == 0))
		{
			m_form->scrollItemToView(m_focusItemId, VCPFORM_SCROLL_TOP);
		}
        if((VFX_TRUE == m_dhcpSwitchCell->getSwitchStatus ()) ||
          ((VFX_FALSE == m_dhcpSwitchCell->getSwitchStatus ()) && (checkRes == 1)))
        {
            saveTcpIpSettings ();
            getMainScr ()->popPage ();
        }
        break;
    default:
        break;
    }
}

void VappTcpIpSettingPage::onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive)
{
    if(isActive)
    {
    	m_currActiveId = sender->getId();
        VFX_TRACE(("Text editor activated!\n"));
        if(sender == m_ipAddrText->getTextBox ())
        {
            m_prevEditor = NULL;
            m_nextEditor = m_netmaskText->getTextBox ();
        }
        else if(sender == m_netmaskText->getTextBox ())
        {
            m_prevEditor = m_ipAddrText->getTextBox ();
            m_nextEditor = m_gatewayText->getTextBox ();
        }
        else if(sender == m_gatewayText->getTextBox ())
        {
            m_prevEditor = m_netmaskText->getTextBox ();
            m_nextEditor = m_dns1Text->getTextBox ();
        }
        else if(sender == m_dns1Text->getTextBox ())
        {
            m_prevEditor = m_gatewayText->getTextBox ();
            m_nextEditor = m_dns2Text->getTextBox ();
        }
        else if(sender == m_dns2Text->getTextBox ())
        {
            m_prevEditor = m_dns1Text->getTextBox ();
            m_nextEditor = NULL;
        }
        m_curEditor = sender;
        
        m_functionBar->setDisableItem (TCP_IP_PAGE_FORM_FUNC_BAR_PREV, m_prevEditor == NULL);
        m_functionBar->setDisableItem (TCP_IP_PAGE_FORM_FUNC_BAR_NEXT, m_nextEditor == NULL);
    }
    else
    {
        VFX_TRACE(("Text editor deactivated!\n"));
    }
}

VfxWString VappTcpIpSettingPage::initItemValue(const VfxU8* addr)
{

    VfxWString  addrStr = VFX_WSTR_EMPTY;
    VfxChar*    tempBuf;
    VfxWChar*   tempBufUnicode;

    VFX_ALLOC_MEM(tempBuf, TCP_IP_ADDR_LEN_MAX, this);
    VFX_ALLOC_MEM(tempBufUnicode, TCP_IP_ADDR_LEN_MAX * ENCODING_LENGTH, this);
    memset(tempBuf, 0, TCP_IP_ADDR_LEN_MAX);
    memset(tempBufUnicode, 0, TCP_IP_ADDR_LEN_MAX * ENCODING_LENGTH);
    
    sprintf(tempBuf, 
        "%03d.%03d.%03d.%03d",
        addr[0], addr[1], addr[2], addr[3]);
    VFX_TRACE(("ADDRESS: %s\n", tempBuf));
    mmi_asc_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)tempBuf);
    addrStr.loadFromMem (tempBufUnicode);

    VFX_FREE_MEM(tempBuf);
    VFX_FREE_MEM(tempBufUnicode);

    return addrStr;
}

VfxU8 VappTcpIpSettingPage::checkItemValue(VcpFormItemTextInput* item, VfxU8* ipAddr, VfxU8* checkRes)
{
    VfxBool isValid;
    VfxU8 result = 0;
    VfxU8 temp[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN] = {0};

    isValid = VappWlanToolbox::checkAddress(item->getTextBox ()->getText (), temp, VFX_FALSE, VFX_TRUE);
    VFX_TRACE(("%d.%d.%d.%d\n", temp[0], temp[1], temp[2], temp[3]));
    
    if(!isValid)
    {
        // VappWlanToolbox::showInvalidPopup (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_IP_ADDR), getMainScr ());
        switch(item->getId ())
        {
        case TCP_IP_PAGE_FORM_TEXT_IP_ADDR:
            item->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_IP_ADDR));
            break;
        case TCP_IP_PAGE_FORM_TEXT_NETMASK:
            item->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_NETMASK));
            break;
        case TCP_IP_PAGE_FORM_TEXT_GATEWAY:
            item->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_GATEWAY));
            break;
        case TCP_IP_PAGE_FORM_TEXT_DNS1:
            item->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_PRIMARY_DNS));
            break;
        case TCP_IP_PAGE_FORM_TEXT_DNS2:
            item->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_SECONDARY_DNS));
            break;
        default:
            break;
        }
    }
    else
    {
        ipAddr[0] = temp[0];
        ipAddr[1] = temp[1];
        ipAddr[2] = temp[2];
        ipAddr[3] = temp[3];

        item->setWarningText (VFX_WSTR_EMPTY);
        result = 1;
    }

    if((*checkRes == 1) && (result == 0))
    {
        // item->setFocused (VFX_TRUE);
        m_focusItemId = item->getId ();
    }
    *checkRes &= result;

    return result;
}

void VappTcpIpSettingPage::saveTcpIpSettings()
{
    if(VFX_TRUE == m_dhcpSwitchCell->getSwitchStatus ())
    {
        m_profile->setUseDhcp (VFX_TRUE);
    }
    else
    {
        m_profile->setUseDhcp (VFX_FALSE);

        m_profile->setIpAddr (m_tempIpAddr);
        m_profile->setNetmask (m_tempNetmaskAddr);
        m_profile->setGateway (m_tempGatewayAddr);
        m_profile->setDns1 (m_tempDns1Addr);
        m_profile->setDns2 (m_tempDns2Addr);
    }   
}


/******************************************************************************/
/*                          Class VappAdvancedSettingPage                     */
/******************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappAdvancedSettingPage", VappAdvancedSettingPage, VfxPage);

VappAdvancedSettingPage::VappAdvancedSettingPage(VappWlanProfile* profile) :
    m_profile(profile),
	m_currActiveId(ADVANCED_PAGE_FORM_NETWORK_TOTAL),
	m_focusItemId(ADVANCED_PAGE_FORM_NETWORK_TOTAL)
{
    VfxWChar*   pxPort;
    VfxWChar*   pxAuthId;
    VfxWChar*   pxAuthPw;
    VfxWChar*   homePage;
    // VfxChar*    tempBuf;
    VfxWChar*   tempBufUnicode;

    VFX_TRACE(("===== VappAdvancedSettingPage constructor =====\n"));
    // 1. Proxy Address
    VFX_ALLOC_MEM(tempBufUnicode, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1) * ENCODING_LENGTH, this);
    memset(tempBufUnicode, 0, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1) * ENCODING_LENGTH);    
	m_proxyAddrStr = VFX_WSTR_EMPTY;
    VfxU32 proxyAddressLen = strlen((const char *)m_profile->getPxAddr ());
    VFX_TRACE(("===== proxyAddressLen: %d =====\n", proxyAddressLen));
    if(proxyAddressLen > 0 && proxyAddressLen < SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1)
    {
        mmi_asc_to_ucs2 ((CHAR *)tempBufUnicode, (CHAR *)m_profile->getPxAddr ());
        m_proxyAddrStr.loadFromMem ((const VfxWChar *)tempBufUnicode);
    }
    VFX_FREE_MEM(tempBufUnicode);
    
    m_homepageStr = VFX_WSTR_EMPTY;
    m_proxyPortStr = VFX_WSTR_EMPTY;
    m_proxyUserNameStr = VFX_WSTR_EMPTY;
    m_proxyPasswordStr = VFX_WSTR_EMPTY;
    
    VFX_ALLOC_MEM(pxPort, 5 * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(pxAuthId, (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(pxAuthPw, (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(homePage, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH, this);

    // 2. Proxy Port
    VFX_TRACE(("===== Proxy Port: %d =====\n", m_profile->getPxPort ()));
    if(m_profile->getPxPort () > 0 && m_profile->getPxPort () <= PROXY_PORT_VALUE_MAX)
    {
        memset(pxPort, 0, 5 * ENCODING_LENGTH);
        app_ucs2_itow ((kal_int32)m_profile->getPxPort (), (kal_wchar*)pxPort, 10);
        m_proxyPortStr.loadFromMem ((const VfxWChar *) pxPort);
    }

    // 3. Proxy username
    VfxU32 authIdLen = strlen((const char *)m_profile->getAuthId ());
    VFX_TRACE(("===== Proxy username: %d =====\n", authIdLen));
    if(authIdLen > 0 && authIdLen < SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1)
    {
        mmi_asc_to_ucs2 ((CHAR *)pxAuthId, (CHAR *)m_profile->getAuthId ());
        m_proxyUserNameStr.loadFromMem ((const VfxWChar *)pxAuthId);
    }

    // 4. Proxy password
    VfxU32 authPwLen = strlen((const char *)m_profile->getAuthPw ());
    VFX_TRACE(("===== Proxy password: %d =====\n", authPwLen));
    if(authPwLen > 0 && authPwLen < SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1)
    {
        mmi_asc_to_ucs2 ((CHAR *)pxAuthPw, (CHAR *)m_profile->getAuthPw ());
        m_proxyPasswordStr.loadFromMem ((const VfxWChar *)pxAuthPw);
    }

    // 5. Homepage
    VfxU32 homePageLen = strlen((const char *)m_profile->getHomePage ());
    VFX_TRACE(("===== Homepage: %d =====\n", homePageLen));
    if(homePageLen > 0 && homePageLen < SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1)
    {
        mmi_asc_to_ucs2 ((CHAR *)homePage, (CHAR *)m_profile->getHomePage ());
        m_homepageStr.loadFromMem ((const VfxWChar *)homePage);
    }
    else
    {
        m_homepageStr = VFX_WSTR("http://");
    }

    VFX_FREE_MEM (pxPort);
    VFX_FREE_MEM (pxAuthId);
    VFX_FREE_MEM (pxAuthPw);
    VFX_FREE_MEM (homePage);
    
}

void VappAdvancedSettingPage::onInit ()
{
    VFX_TRACE(("===== VappAdvancedSettingPage initialization =====\n"));
    VfxPage::onInit ();

    setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_ADVANCED_SETTING));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (ADVANCED_SETTING_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem (ADVANCED_SETTING_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappAdvancedSettingPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(ADVANCED_PAGE_FORM_FUNC_BAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_PREV));
    m_functionBar->addItem(ADVANCED_PAGE_FORM_FUNC_BAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_NEXT));
    m_functionBar->addItem(ADVANCED_PAGE_FORM_FUNC_BAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_functionBar->setItemSpecial (ADVANCED_PAGE_FORM_FUNC_BAR_SAVE);
    m_functionBar->m_signalButtonTap.connect (
        this, &VappAdvancedSettingPage::onFuncBarBtnClick);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Homepage
    VFX_OBJ_CREATE(m_homePageText, VcpFormItemTextInput, this);
    m_homePageText->getTextBox ()->setText (m_homepageStr, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);
    m_homePageText->getTextBox ()->setIME(IMM_INPUT_TYPE_URL);
    m_homePageText->getTextBox ()->setFunctionBar (m_functionBar);
	m_homePageText->getTextBox()->setId(ADVANCED_PAGE_FORM_TEXT_HOMEPAGE);
    // m_homePageText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_homePageText->getTextBox ()->m_signalActivated.connect (this, &VappAdvancedSettingPage::onTextEditorActivated);
    m_homePageText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_HOME_PAGE));
    m_homePageText->setLabelPosition (VCPFORM_TOP_LEFT);
    m_homePageText->setPos (
        m_titleBar->getRect().getMinX (), 
        m_titleBar->getRect().getMaxY ());

    // Use proxy cation
    VFX_OBJ_CREATE(m_useProxyCaption, VcpFormItemCaption, this);
    m_useProxyCaption->setText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_USE_PROXY));
    m_useProxyCaption->setStyle (VCPFORM_STYLE2);
    m_useProxyCaption->setPos (
        m_homePageText->getRect().getMinX (), 
        m_homePageText->getRect().getMaxY ());

    // Use proxy
    VFX_OBJ_CREATE (m_switchCell, VcpFormItemSwitchCell, this);
    m_switchCell->setMainText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_USE_PROXY));
    m_switchCell->setIsTappable (VFX_FALSE);
    m_switchCell->m_signalSwitchChangeReq.connect (
        this, &VappAdvancedSettingPage::onSwitchStatusChanged);

    // Proxy Address
    VFX_OBJ_CREATE(m_proxyAddrText, VcpFormItemTextInput, this);
    m_proxyAddrText->getTextBox ()->setText (m_proxyAddrStr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
    m_proxyAddrText->getTextBox ()->setIME(IMM_INPUT_TYPE_URL);
    m_proxyAddrText->getTextBox ()->setFunctionBar (m_functionBar);
    m_proxyAddrText->getTextBox ()->setId(ADVANCED_PAGE_FORM_TEXT_PROXY_ADDR);
    // m_proxyAddrText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_proxyAddrText->getTextBox ()->m_signalActivated.connect (this, &VappAdvancedSettingPage::onTextEditorActivated);
    m_proxyAddrText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_PROXY_ADDR));
    m_proxyAddrText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Proxy port
    VFX_OBJ_CREATE(m_proxyPortText, VcpFormItemTextInput, this);
    m_proxyPortText->getTextBox ()->setText (m_proxyPortStr, 5);
    m_proxyPortText->getTextBox ()->setIME(IMM_INPUT_TYPE_NUMERIC);
    m_proxyPortText->getTextBox ()->setFunctionBar (m_functionBar);
	m_proxyPortText->getTextBox ()->setId(ADVANCED_PAGE_FORM_TEXT_PROXY_PORT);
    // m_proxyPortText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_proxyPortText->getTextBox ()->m_signalActivated.connect (this, &VappAdvancedSettingPage::onTextEditorActivated);
    m_proxyPortText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_PROXY_PORT));
    m_proxyPortText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Proxy username
    VFX_OBJ_CREATE(m_proxyUserNameText, VcpFormItemTextInput, this);
    m_proxyUserNameText->getTextBox ()->setText (m_proxyUserNameStr, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN);
    m_proxyUserNameText->getTextBox ()->setIME(IMM_INPUT_TYPE_ENGLISH_SENTENCE);
    m_proxyUserNameText->getTextBox ()->setFunctionBar (m_functionBar);
	m_proxyUserNameText->getTextBox ()->setId(ADVANCED_PAGE_FORM_TEXT_PROXY_USERNAME);	
    // m_proxyUserNameText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_proxyUserNameText->getTextBox ()->m_signalActivated.connect (this, &VappAdvancedSettingPage::onTextEditorActivated);
    m_proxyUserNameText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_PROXY_USER_NAME));
    m_proxyUserNameText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Proxy password
    VFX_OBJ_CREATE(m_proxyPasswordText, VcpFormItemTextInput, this);
    m_proxyPasswordText->getTextBox ()->setText (m_proxyPasswordStr, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN);
    m_proxyPasswordText->getTextBox ()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
    m_proxyPasswordText->getTextBox ()->setFunctionBar (m_functionBar);
	m_proxyPasswordText->getTextBox ()->setId(ADVANCED_PAGE_FORM_TEXT_PROXY_PASSWORD);		
    // m_proxyPasswordText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_proxyPasswordText->getTextBox ()->m_signalActivated.connect (this, &VappAdvancedSettingPage::onTextEditorActivated);
    m_proxyPasswordText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_PROXY_PASSWORD));
    m_proxyPasswordText->setLabelPosition (VCPFORM_TOP_LEFT);
    
    if(m_profile->getUseProxy () == VFX_FALSE)
    {
        m_switchCell->setSwitchStatus (VFX_FALSE);
        m_proxyAddrText->setIsDisabled (VFX_TRUE);
        m_proxyPortText->setIsDisabled (VFX_TRUE);
        m_proxyUserNameText->setIsDisabled (VFX_TRUE);
        m_proxyPasswordText->setIsDisabled (VFX_TRUE);
    }
    else
    {
        m_switchCell->setSwitchStatus (VFX_TRUE);
        m_proxyAddrText->setIsDisabled (VFX_FALSE);
        m_proxyPortText->setIsDisabled (VFX_FALSE);
        m_proxyUserNameText->setIsDisabled (VFX_FALSE);
        m_proxyPasswordText->setIsDisabled (VFX_FALSE);
    }

    // Append item into form
    m_form->addItem (m_homePageText, ADVANCED_PAGE_FORM_TEXT_HOMEPAGE);
    m_form->addItem (m_useProxyCaption, ADVANCED_PAGE_FORM_CAPTION_USE_PROXY);
    m_form->addItem (m_switchCell, ADVANCED_PAGE_FORM_BUTTON_USE_PROXY);
    m_form->addItem (m_proxyAddrText, ADVANCED_PAGE_FORM_TEXT_PROXY_ADDR);
    m_form->addItem (m_proxyPortText, ADVANCED_PAGE_FORM_TEXT_PROXY_PORT);
    m_form->addItem (m_proxyUserNameText, ADVANCED_PAGE_FORM_TEXT_PROXY_USERNAME);
    m_form->addItem (m_proxyPasswordText, ADVANCED_PAGE_FORM_TEXT_PROXY_PASSWORD); 
    
}

void VappAdvancedSettingPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
        case ADVANCED_SETTING_TOOLBAR_SAVE:
            if(verifyItemValue () == VFX_TRUE)
            {
                saveAdvancedSettings();
                getMainScr ()->popPage ();
            }
            break;
        case ADVANCED_SETTING_TOOLBAR_CANCEL:
            getMainScr ()->popPage ();
            break;
        default:
            break;
    }
}

void VappAdvancedSettingPage::onSwitchStatusChanged(
        VcpFormItemSwitchCell* sender,      // Sender
        VfxId id,                           // Sender id
        VfxBool status                      // new switch value
    )
{
    VFX_TRACE(("===== Switch status as %d=====\n", status));

	if(ADVANCED_PAGE_FORM_NETWORK_TOTAL != m_currActiveId)
	{
    	// de-active editor
    	VcpFormItemTextInput* textInput;
    	VcpTextEditor *editor;
    	textInput = (VcpFormItemTextInput*)(m_form->getItem(m_currActiveId));
    	editor = textInput->getTextBox();
    	editor->deactivate();
		m_currActiveId = ADVANCED_PAGE_FORM_NETWORK_TOTAL;
	}
	
    if(status == VFX_FALSE)
    {
        m_proxyAddrText->setIsDisabled (VFX_TRUE);
        m_proxyPortText->setIsDisabled (VFX_TRUE);
        m_proxyUserNameText->setIsDisabled (VFX_TRUE);
        m_proxyPasswordText->setIsDisabled (VFX_TRUE);
        m_switchCell->setSwitchStatus (VFX_FALSE);
    }
    else
    {
        m_proxyAddrText->setIsDisabled (VFX_FALSE);
        m_proxyPortText->setIsDisabled (VFX_FALSE);
        m_proxyUserNameText->setIsDisabled (VFX_FALSE);
        m_proxyPasswordText->setIsDisabled (VFX_FALSE);
        m_switchCell->setSwitchStatus (VFX_TRUE);
    }
}

void VappAdvancedSettingPage::onFuncBarBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case ADVANCED_PAGE_FORM_FUNC_BAR_PREV:
        if(m_prevEditor)
        {
            m_prevEditor->activate ();
        }
		// if current id is proxy address and tap prev bar, scroll to top
		if(ADVANCED_PAGE_FORM_TEXT_PROXY_ADDR == m_curEditor->getId())
		{
			m_form->scrollItemToView(ADVANCED_PAGE_FORM_TEXT_HOMEPAGE, 
				VCPFORM_SCROLL_TOP, VFX_TRUE);
		}
        break;
    case ADVANCED_PAGE_FORM_FUNC_BAR_NEXT:
        if(m_nextEditor)
        {
            m_nextEditor->activate ();
        }
        break;        
    case ADVANCED_PAGE_FORM_FUNC_BAR_SAVE:
        if(m_curEditor)
        {
            m_curEditor->deactivate ();
        }
        if(verifyItemValue () == VFX_TRUE)
        {
            saveAdvancedSettings();
            getMainScr ()->popPage ();
        }
        break;
    default:
        break;
    }
}

void VappAdvancedSettingPage::onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive)
{
    if(isActive)
    {
    	m_currActiveId = sender->getId();
        VFX_TRACE(("Text editor activated!\n"));
        if(sender == m_homePageText->getTextBox ())
        {
            m_prevEditor = NULL;
            if(VFX_FALSE == m_proxyAddrText->getIsDisabled ())
            {
                m_nextEditor = m_proxyAddrText->getTextBox ();
            }
            else
            {
                m_nextEditor = NULL;
            }
        }
        else if(sender == m_proxyAddrText->getTextBox ())
        {
            m_prevEditor = m_homePageText->getTextBox ();
            m_nextEditor = m_proxyPortText->getTextBox ();
        }
        else if(sender == m_proxyPortText->getTextBox ())
        {
            m_prevEditor = m_proxyAddrText->getTextBox ();
            m_nextEditor = m_proxyUserNameText->getTextBox ();
        }
        else if(sender == m_proxyUserNameText->getTextBox ())
        {
            m_prevEditor = m_proxyPortText->getTextBox ();
            m_nextEditor = m_proxyPasswordText->getTextBox ();
        }
        else if(sender == m_proxyPasswordText->getTextBox ())
        {
            m_prevEditor = m_proxyUserNameText->getTextBox ();
            m_nextEditor = NULL;
        }
        m_curEditor = sender;
        
        m_functionBar->setDisableItem (ADVANCED_PAGE_FORM_FUNC_BAR_PREV, m_prevEditor == NULL);
        m_functionBar->setDisableItem (ADVANCED_PAGE_FORM_FUNC_BAR_NEXT, m_nextEditor == NULL);
    }
    else
    {
        VFX_TRACE(("Text editor deactivated!\n"));
    }
}

VfxBool VappAdvancedSettingPage::verifyItemValue()
{
    VfxS32      portValue;
    VfxS32      portLen;
    VfxWChar*   itemUnicode;
    VfxChar*    itemAscii;
    VfxWString  homePage = VFX_WSTR_EMPTY;
    VfxU8       result = 1;
    VfxWString  proxyAddr = VFX_WSTR_EMPTY;	
	VfxBool     focus = VFX_FALSE; // use to get the first error item
    VfxWString  proxyAddress = VFX_WSTR_EMPTY;

    // 1. Verify homepage
    homePage = m_homePageText->getText ();
    VFX_ALLOC_MEM(itemAscii, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1), this);
    memset(itemAscii, 0, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
    VappWlanToolbox::convertStrToAscii (itemAscii, homePage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);
    
    if(VFX_FALSE == VappWlanToolbox::isUrlValid(itemAscii))
    {
        result &= 0;
        m_homePageText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_HOMEPAGE));
        // m_homePageText->setFocused (VFX_TRUE);  // Scroll to homepage item
        if (!focus)
        {
            focus = VFX_TRUE;
            m_focusItemId = ADVANCED_PAGE_FORM_TEXT_HOMEPAGE;
        }
    }
    else
    {
        result &= 1;
        m_homePageText->setWarningText (VFX_WSTR_EMPTY);
    }
    VFX_FREE_MEM(itemAscii);

    if(VFX_FALSE == m_switchCell->getSwitchStatus ())   // Not use proxy
    {
        if(result == 1)
            return VFX_TRUE;
        else
        {
        	if(focus == VFX_TRUE)
        	{
        		m_form->scrollItemToView(m_focusItemId, VCPFORM_SCROLL_TOP);
        	}
			return VFX_FALSE;
        }
    }

    // 2. Verify proxy's address    
    //if( 0 == mmi_ucs2strlen((const CHAR *)m_proxyAddrText->getTextBox ()->getText ()))
    proxyAddress = m_proxyAddrText->getText ();
    VFX_ALLOC_MEM(itemAscii, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1), this);
    memset(itemAscii, 0, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1);    
    VappWlanToolbox::convertStrToAscii (itemAscii, proxyAddress, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);   
    if(applib_url_is_valid_ext(itemAscii, KAL_TRUE, KAL_FALSE))
    {
        m_proxyAddrText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_PROXY_ADDR));
        if(result == 1)
        {
            // m_proxyAddrText->setFocused (VFX_TRUE);
        }
        result &= 0;
		if (!focus)
        {
            focus = VFX_TRUE;
            m_focusItemId = ADVANCED_PAGE_FORM_TEXT_PROXY_ADDR;
        }
    }
    else
    {
        m_proxyAddrText->setWarningText (VFX_WSTR_EMPTY);
        result &= 1;
    }
    VFX_FREE_MEM(itemAscii);
    
    // 3. Verify proxy's port
    portLen = mmi_ucs2strlen((const CHAR *)m_proxyPortText->getTextBox ()->getText ());
    if(portLen == 0 || portLen > 5)
    {
        m_proxyPortText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_EMPTY_PROXY_PORT));
        if(result == 1)
        {
            // m_proxyPortText->setFocused (VFX_TRUE);
        }
        result &= 0;
		if (!focus)
        {
            focus = VFX_TRUE;
            m_focusItemId = ADVANCED_PAGE_FORM_TEXT_PROXY_PORT;
        }
    }
    else
    {   
        VFX_ALLOC_MEM(itemUnicode, 5 * ENCODING_LENGTH, this);
        memset(itemUnicode, 0, 5 * ENCODING_LENGTH);
        memcpy(itemUnicode, m_proxyPortText->getTextBox ()->getText (), 5 * ENCODING_LENGTH);
        
        mmi_ucs2toi ((const CHAR *)itemUnicode, &portValue, &portLen);
        VFX_FREE_MEM(itemUnicode);
        if(portValue == 0 || portValue > PROXY_PORT_VALUE_MAX)
        {
            m_proxyPortText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_PROXY_PORT));
            if(result == 1)
            {
                // m_proxyPortText->setFocused (VFX_TRUE);
            }
            result &= 0;
			if (!focus)
        	{
           	 	focus = VFX_TRUE;
            	m_focusItemId = ADVANCED_PAGE_FORM_TEXT_PROXY_PORT;
        	}
        }
        else
        {
            m_proxyPortText->setWarningText (VFX_WSTR_EMPTY);
            result &= 1;
        }
    }

    if(result == 1)
    {
        return VFX_TRUE;
    }
    else
    {
		if(focus == VFX_TRUE)
		{
			m_form->scrollItemToView(m_focusItemId, VCPFORM_SCROLL_TOP);
		}
        return VFX_FALSE;
    }
}

void VappAdvancedSettingPage::saveItemValue(ADVANCED_PAGE_FORM_ITEM_ENUM itemEnum, VcpFormItemTextInput* item)
{
    VfxWChar*   itemUnicode;
    VfxChar*    itemAscii;
    VfxU32      strLen;
    VfxS32      portValue;
    VfxS32      portLen;
    
    strLen = item->getText ().getLength ();
    if(strLen > 0)
    {
        switch(itemEnum)
        {
        case ADVANCED_PAGE_FORM_TEXT_PROXY_ADDR:
			VFX_ALLOC_MEM(itemUnicode, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1) * ENCODING_LENGTH, this);
            VFX_ALLOC_MEM(itemAscii, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1), this);
            memset(itemUnicode, 0, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1) * ENCODING_LENGTH);
            memset(itemAscii, 0, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1));

            memcpy(itemUnicode, item->getTextBox ()->getText (), (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1) * ENCODING_LENGTH);
            if(strLen < (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1))
            {
                mmi_wcs_n_to_asc(itemAscii, itemUnicode, strLen * ENCODING_LENGTH);
            }
            else
            {   
                mmi_wcs_n_to_asc(itemAscii, itemUnicode, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN * ENCODING_LENGTH);
            }

            m_profile->setPxAddr ((const VfxU8 *) itemAscii);
            VFX_FREE_MEM(itemUnicode);
            VFX_FREE_MEM(itemAscii);
            break;
        case ADVANCED_PAGE_FORM_TEXT_PROXY_PORT:
            VFX_ALLOC_MEM(itemUnicode, 5 * ENCODING_LENGTH, this);
            memset(itemUnicode, 0, 5 * ENCODING_LENGTH);
            memcpy(itemUnicode, item->getTextBox ()->getText (), 5 * ENCODING_LENGTH);
                
            mmi_ucs2toi ((const CHAR *)itemUnicode, &portValue, &portLen);
            m_profile->setPxPort ((VfxU16)portValue);
            VFX_FREE_MEM(itemUnicode);
            break;
        case ADVANCED_PAGE_FORM_TEXT_PROXY_USERNAME:
            VFX_ALLOC_MEM(itemUnicode, (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1) * ENCODING_LENGTH, this);
            VFX_ALLOC_MEM(itemAscii, (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1), this);
            memset(itemUnicode, 0, (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1) * ENCODING_LENGTH);
            memset(itemAscii, 0, (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1));

            // vfx_sys_wcscpy(itemUnicode, item->getText ().getBuf ());
            memcpy(itemUnicode, item->getTextBox ()->getText (), (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1) * ENCODING_LENGTH);
            if(strLen < (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1))
            {
                mmi_wcs_n_to_asc(itemAscii, itemUnicode, strLen * ENCODING_LENGTH);
            }
            else
            {   
                mmi_wcs_n_to_asc(itemAscii, itemUnicode, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN * ENCODING_LENGTH);
            }

            m_profile->setPxAuthId ((const VfxU8 *) itemAscii);
            VFX_FREE_MEM(itemUnicode);
            VFX_FREE_MEM(itemAscii);
            break;
        case ADVANCED_PAGE_FORM_TEXT_PROXY_PASSWORD:
            VFX_ALLOC_MEM(itemUnicode, (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1) * ENCODING_LENGTH, this);
            VFX_ALLOC_MEM(itemAscii, (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1), this);
            memset(itemUnicode, 0, (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1) * ENCODING_LENGTH);
            memset(itemAscii, 0, (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1));

            // vfx_sys_wcscpy(itemUnicode, item->getText ().getBuf ());
            memcpy(itemUnicode, item->getTextBox ()->getText (), (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1) * ENCODING_LENGTH);
            if(strLen < (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1))
            {
                mmi_wcs_n_to_asc(itemAscii, itemUnicode, strLen * ENCODING_LENGTH);
            }
            else
            {   
                mmi_wcs_n_to_asc(itemAscii, itemUnicode, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN * ENCODING_LENGTH);
            }

            m_profile->setPxAuthPw ((const VfxU8 *) itemAscii);
            VFX_FREE_MEM(itemUnicode);
            VFX_FREE_MEM(itemAscii);
            break;
        case ADVANCED_PAGE_FORM_TEXT_HOMEPAGE:
            VFX_ALLOC_MEM(itemUnicode, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH, this);
            VFX_ALLOC_MEM(itemAscii, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1), this);
            memset(itemUnicode, 0, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH);
            memset(itemAscii, 0, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1));

            memcpy(itemUnicode, m_homePageText->getTextBox ()->getText (), (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH);
            if(strLen < (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1))
            {
                mmi_wcs_n_to_asc(itemAscii, itemUnicode, strLen * ENCODING_LENGTH);
            }
            else
            {   
                mmi_wcs_n_to_asc(itemAscii, itemUnicode, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN * ENCODING_LENGTH);
            }

            m_profile->setHomePage ((const VfxU8 *) itemAscii);
            VFX_FREE_MEM(itemUnicode);
            VFX_FREE_MEM(itemAscii);
            break;
        default:
            break;
        }
    }
	else
	{
	 	switch(itemEnum)
        {
        case ADVANCED_PAGE_FORM_TEXT_PROXY_USERNAME:		
            m_profile->clearPxAuthId();
			break;
		case ADVANCED_PAGE_FORM_TEXT_PROXY_PASSWORD:
			m_profile->clearPxAuthPw();
			break;
		default:
			break;
	 	}
	}
}

void VappAdvancedSettingPage::saveAdvancedSettings()
{
    /* homepage */
    saveItemValue (ADVANCED_PAGE_FORM_TEXT_HOMEPAGE, m_homePageText);

    if(VFX_TRUE == m_switchCell->getSwitchStatus ())
    {
        m_profile->setUseProxy (VFX_TRUE);
        /* proxy address */
        saveItemValue (ADVANCED_PAGE_FORM_TEXT_PROXY_ADDR, m_proxyAddrText);
        /* proxy port */
        saveItemValue (ADVANCED_PAGE_FORM_TEXT_PROXY_PORT, m_proxyPortText);
        /* proxy user name */
        saveItemValue (ADVANCED_PAGE_FORM_TEXT_PROXY_USERNAME, m_proxyUserNameText);
        /* proxy password */
        saveItemValue (ADVANCED_PAGE_FORM_TEXT_PROXY_PASSWORD, m_proxyPasswordText);
    }
    else
    {
        m_profile->setUseProxy (VFX_FALSE);
    }
}

void VappAdvancedSettingPage::showInvalidPopup(const VfxWString &prompt)
{
	VcpConfirmPopup *invalidInputPopup;
    VFX_OBJ_CREATE (invalidInputPopup, VcpConfirmPopup, getMainScr ());
    invalidInputPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
    invalidInputPopup->setText(prompt);
    invalidInputPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
    invalidInputPopup->setAutoDestory(VFX_TRUE);
    invalidInputPopup->show (VFX_TRUE);
}

/***************************************************************************** 
 * Class VappAdvancedPage
 *****************************************************************************/
// VFX_IMPLEMENT_CLASS ("VappAdvancedPage", VappAdvancedPage, VfxPage);
VappAdvancedPage::VappAdvancedPage(VappWlanRepository *repository) : 
    m_repository(repository)
{
    // register page in the respository
    m_repository->registerObserver (this);
}
    
VappAdvancedPage::~VappAdvancedPage()
{
    // deregister page in the respository
    m_repository->removeObserver (this);
}

void VappAdvancedPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INIT_ADVANCE_PAGE);
    Observer::onInit ();
   
    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_GLOBAL_ADVANCED));
    setTopBar (m_titleBar);

    // Networks list menu
    VFX_OBJ_CREATE (m_networksListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX (m_contentProvider, AdvancedContentProvider, this, (m_repository));
    m_networksListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);	
    m_networksListMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_networksListMenu->setContentProvider (m_contentProvider);
    m_networksListMenu->setPos(0, 0);
    m_networksListMenu->setSize(getSize());
    m_networksListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_networksListMenu->m_signalItemTapped.connect (
                                this, &VappAdvancedPage::onItemTapped);	
}

void VappAdvancedPage::onEnter(VfxBool isBackward)
{
	Observer::onEnter(isBackward);
    if(isBackward)
    {	
		m_networksListMenu->resetAllItems ();
    }
}

void VappAdvancedPage::onItemTapped(VcpListMenu *listMenu, VfxU32 index)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_SELECT_ADVANCE_PAGE, index);

    switch(index)
    {
    case ADVANCED_PAGE_ITEM_SLEEP_POLICY:
    	{
    		// sleep policy setting		
            VappSleepPolicySettingPage* sleepPolicySettingPage = NULL;
    		VFX_OBJ_CREATE(sleepPolicySettingPage, VappSleepPolicySettingPage, getMainScr());
    		getMainScr ()->pushPage(0, sleepPolicySettingPage);
    	}  
        break;
#ifdef __MMI_OP01_WIFI__ 
    case ADVANCED_PAGE_ITEM_CMCC_SETTING:
    	{
    		// CMCC setting		
            VappCmccWlanSettingPage* cmccWlanSettingPage = NULL;
    		VFX_OBJ_CREATE(cmccWlanSettingPage, VappCmccWlanSettingPage, getMainScr());
    		getMainScr ()->pushPage(CMCC_WLAN_SETTING_PAGE_ID, cmccWlanSettingPage);
    	}     	
        break;
	case ADVANCED_PAGE_ITEM_NON_PROXY:
    	{	
            // non-proxy
            VappNonProxyAddressesPage* nonProxyAddressesPage = NULL;    
    		VFX_OBJ_CREATE_EX (
    			nonProxyAddressesPage, VappNonProxyAddressesPage, 
    			getMainScr(), (m_repository));
    		getMainScr ()->pushPage (0, nonProxyAddressesPage);
    	}	    	
        break;
    case ADVANCED_PAGE_ITEM_CERTMAN_LOAD:
 		// CertMan. load
		entryLoadWAPICertProc();
		break;
	case ADVANCED_PAGE_ITEM_CERTMAN_UNLOAD:
		// CertMan. unload		
		entryUnLoadWAPICertProc();
		break;
	case ADVANCED_PAGE_ITEM_WLAN_TO_CELLULAR:
    	{
    		// WLAN to Cellular network		
            VappWLANToCellularSettingPage* WLANToCellularSettingPage = NULL;
    		VFX_OBJ_CREATE(
    			WLANToCellularSettingPage, VappWLANToCellularSettingPage, 
    			getMainScr());
    		getMainScr ()->pushPage (0, WLANToCellularSettingPage);
    	}
    	break;   	
#endif /* __MMI_OP01_WIFI__ */
    default :
        break;
    }
}

#ifdef __MMI_OP01_WIFI__ 
mmi_ret VappAdvancedPage::onProc(mmi_event_struct *evt)
{
	vcui_file_selector_result_event_struct *fmgrEvt;
	fmgrEvt = (vcui_file_selector_result_event_struct*)evt;
    S32 result = 0;
	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_PROC_ADVANCE_PAGE, evt->evt_id, fmgrEvt->result);

	switch (evt->evt_id)
    {
    case EVT_ID_VCUI_FILE_SELECTOR_RESULT:  // event from file manager
    {			
        if (fmgrEvt->result > 0)
        {
            srv_fmgr_fileinfo_struct info;
            memset(&info, 0, sizeof(info));
            VfxU32 buffSize = (SRV_FMGR_PATH_MAX_LEN+1) * sizeof(VfxWChar);
			WCHAR selectedFilePath[SRV_FMGR_PATH_MAX_LEN + 1];
            result = vcui_file_selector_get_selected_filepath(
                		m_fsCuiId, &info, selectedFilePath, buffSize);
			VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_CERT_PATH_ADVANCE_PAGE, result);
			if(result == 0)
			{
#ifdef __CERTMAN_SUPPORT__
				vapp_certman_install_cert_file((VfxWChar *)selectedFilePath);
#endif /* __CERTMAN_SUPPORT__ */
			}
			else
			{
				vcui_file_selector_close(m_fsCuiId);
			}
		}
		else
		{
			vcui_file_selector_close(m_fsCuiId);
		}
    }
	default:
		break;
	}
	return MMI_RET_OK;
}

void VappAdvancedPage::entryLoadWAPICertProc()
{
	FMGR_FILTER filter;
	U32 option_flag = VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON |
	                  VCUI_FILE_SELECTOR_OPT_ARCHIVE_AS_UNKNOWN |
	                  VCUI_FILE_SELECTOR_OPT_FIXED_PATH_ON;
		
	FMGR_FILTER_INIT(&filter);
	
    FMGR_FILTER_SET(&filter, FMGR_TYPE_CER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PFX);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_DER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PEM);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_P7B);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_CRT);    
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

	m_fsCuiId = vcui_file_selector_create(
					getMainScr()->getGroupId(),
					VFX_WSTR("root"),
					&filter,
					VCUI_FILE_SELECTOR_STYLE_FILE_ONLY,
					option_flag);
		
    if (m_fsCuiId != GRP_ID_INVALID)
    {    
		vfxSetCuiCallerScr(m_fsCuiId, getMainScr());
		vcui_file_selector_run(m_fsCuiId);	
    }	
}

void VappAdvancedPage::entryUnLoadWAPICertProc()
{
#ifdef __CERTMAN_SUPPORT__
	VfxMainScr *mainScr = this->getMainScr();	
	vapp_certman_launch_cert_setting(mainScr);
#endif /* __CERTMAN_SUPPORT__ */
}

void VappAdvancedPage::responseCloseCMCCSettingPageEvent(mmi_event_struct* param)
{
    VappWlanRepository *houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 
    mmi_id  wlanSettingCuiId = GRP_ID_INVALID;
    VappDtcntWlan *wlanAppInstance = NULL;
    VcuiDtcntWlanSetting *wlanSettingCuiInstance = NULL;

    VfxApp *app = vapp_dtcnt_wlan_find_app();       
    wlanSettingCuiId = houseKeeper->getWlanSettingCuiId ();
    if(app)
    {        
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_CLOSE_CMCC_SETTING_PAGE, 0, app->getGroupId()); 
        wlanAppInstance = (VappDtcntWlan *)VfxApp::getObject(app->getGroupId());
        if(NULL != wlanAppInstance)
        {
            wlanAppInstance->getWlanMainScr()->closePage(CMCC_WLAN_SETTING_PAGE_ID);
        }
    }
    else if(0 != wlanSettingCuiId)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_CLOSE_CMCC_SETTING_PAGE, 1, wlanSettingCuiId); 
        wlanSettingCuiInstance = (VcuiDtcntWlanSetting *)VfxCui::getObject(wlanSettingCuiId); 
        if(NULL != wlanSettingCuiId)
        {
           wlanSettingCuiInstance->getWlanMainScreen()->closePage(CMCC_WLAN_SETTING_PAGE_ID);                  
        }
    }
}
#endif /* __MMI_OP01_WIFI__ */

/******************************************************************************/
// Implement the required content provider functions
void AdvancedContentProvider::setMenu(VcpListMenu *menu)
{
    m_listMenu = menu;
}

VfxU32 AdvancedContentProvider::getCount() const
{
    return ADVANCED_CONTENT_PROVIDER_TOTAL;
}

VcpListMenuCellClientBaseFrame* AdvancedContentProvider::getItemCustomContentFrame(
        VfxU32 index,           // [IN] the index of item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        )
{
    VappWlanApListMenuCell*  apListMenuCell;
    VcpListMenuCellSingleTextFrame* funcListMenuCell;

    switch(index)
    {    
#ifdef __CBM_BEARER_SWITCH__ 
    case ADVANCED_CONTENT_PROVIDER_NETWORK_NOTIFICATION:
#endif /* __CBM_BEARER_SWITCH__ */  

    case ADVANCED_CONTENT_PROVIDER_AUTO_CONNECTION:
        VFX_OBJ_CREATE (funcListMenuCell, VcpListMenuCellSingleTextFrame, parentFrame);
        return funcListMenuCell;
       
#ifdef __MMI_OP01_WIFI__ 
    case ADVANCED_CONTENT_PROVIDER_CMCC_SETTING:
    case ADVANCED_CONTENT_PROVIDER_NON_PROXY:
    case ADVANCED_CONTENT_PROVIDER_CERTMAN_LOAD:
    case ADVANCED_CONTENT_PROVIDER_CERTMAN_UNLOAD:
    case ADVANCED_CONTENT_PROVIDER_WLAN_TO_CELLULAR:
    	VFX_OBJ_CREATE (apListMenuCell, VappWlanApListMenuCell, parentFrame);
    	return apListMenuCell;  
#endif /* __MMI_OP01_WIFI__ */


    case ADVANCED_CONTENT_PROVIDER_SLEEP_POLICY:
        VFX_OBJ_CREATE (apListMenuCell, VappWlanApListMenuCell, parentFrame);
        return apListMenuCell;  

    default:
        return NULL;
    }
	
}

VfxBool AdvancedContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{    
    switch(fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:  
        switch(index)
        {          
#ifdef __CBM_BEARER_SWITCH__ 
        case ADVANCED_CONTENT_PROVIDER_NETWORK_NOTIFICATION:       
        	text.loadFromRes(STR_ID_VAPP_WLAN_NETWORK_NOTI);
            break;            
#endif /* __CBM_BEARER_SWITCH__ */ 
        case ADVANCED_CONTENT_PROVIDER_AUTO_CONNECTION:       
        	text.loadFromRes(STR_ID_VAPP_WLAN_AUTO_CONN);
            break;
#ifdef __MMI_OP01_WIFI__ 
        case ADVANCED_CONTENT_PROVIDER_CMCC_SETTING:       
        	text.loadFromRes(STR_ID_VAPP_WLAN_CHINA_MOBILE);
            break;
        case ADVANCED_CONTENT_PROVIDER_NON_PROXY:         
            text.loadFromRes(STR_ID_VAPP_WLAN_NON_PROXY_ADDRESSES);
            break;
        case ADVANCED_CONTENT_PROVIDER_CERTMAN_LOAD:       
			text.loadFromRes(STR_ID_VAPP_WLAN_LOAD_WAPI_CERT);
            break;
        case ADVANCED_CONTENT_PROVIDER_CERTMAN_UNLOAD:       
			text.loadFromRes(STR_ID_VAPP_WLAN_UNLOAD_WAPI_CERT);
            break;
        case ADVANCED_CONTENT_PROVIDER_WLAN_TO_CELLULAR:       
			text.loadFromRes(STR_ID_VAPP_WLAN_NO_WLAN_TO_CELLULAR);
            break;
#endif /* __MMI_OP01_WIFI__ */	
        case ADVANCED_CONTENT_PROVIDER_SLEEP_POLICY:       
            text.loadFromRes(STR_ID_VAPP_WLAN_SLEEP_POLICY);
            break;  
        default :
            break;
        }
        break;
	case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        switch(index)
        {
        case ADVANCED_CONTENT_PROVIDER_SLEEP_POLICY:
    		{		
    			srv_dtcnt_wlan_prefer_struct wlan_prefer_setting;
    			srv_dtcnt_get_wlan_prefer_setting(&wlan_prefer_setting);
    			switch(wlan_prefer_setting.sleep_mode)
    			{
    			case SRV_DTCNT_WLAN_SLEEP_MODE_NEVER_SLEEP:
                    text.loadFromRes(STR_ID_VAPP_WLAN_SLEEP_POLICY_NEVER);
                    break;
                case SRV_DTCNT_WLAN_SLEEP_MODE_CHARGEIN_NEVER_SLEEP:                
                    text.loadFromRes(STR_ID_VAPP_WLAN_SLEEP_POLICY_NEVER_USB_PLUG_IN);                   
                    break;
                case SRV_DTCNT_WLAN_SLEEP_MODE_LCD_OFF_SLEEP:                
                    text.loadFromRes(STR_ID_VAPP_WLAN_SLEEP_POLICY_SCREEN_TURN_OFF);                   
                    break;   			    
    			}
		    }
            break;            
#ifdef __MMI_OP01_WIFI__ 
        case ADVANCED_CONTENT_PROVIDER_WLAN_TO_CELLULAR:
    		{		
    			srv_dtcnt_wlan_prefer_struct wlan_prefer_setting;
    			srv_dtcnt_get_wlan_prefer_setting(&wlan_prefer_setting);	
    			if(0 == wlan_prefer_setting.cellular_switch)

    			{
    				text.loadFromRes(STR_ID_VAPP_WLAN_ALWAYS_ASK);
    			}
    			else
    			{					
    				text.loadFromRes(STR_ID_VAPP_WLAN_NO_MORE_ASK);
    			}
		    }
		    break;        
#endif /* __MMI_OP01_WIFI__ */
        default :
            return VFX_FALSE; // VappWlanApListMenuCell m_textFrame2 is NULL, update m_textFrame1 positon.        
        }
        break;
    case VCP_LIST_MENU_FIELD_SUB_TEXT2:
        break;
    }
    return VFX_TRUE;
}

VfxBool AdvancedContentProvider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        ) 
{
    VfxBool isHighlight = VFX_FALSE;
    VcpListMenuCell* menuCell = m_listMenu->getCell (index);
    if(menuCell)
    {
        isHighlight = menuCell->m_isHighlight;
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

VfxBool AdvancedContentProvider::getItemIsHighlightable(
        VfxU32 index    // [IN] the index of item
        ) const 
{
    switch(index)
    {
#ifdef	__CBM_BEARER_SWITCH__ 
    case ADVANCED_CONTENT_PROVIDER_NETWORK_NOTIFICATION:    
#endif /* __CBM_BEARER_SWITCH__ */
    case ADVANCED_CONTENT_PROVIDER_AUTO_CONNECTION:
		return VFX_FALSE;   
    }
    return VFX_TRUE;
}

VcpListMenuCellBaseControl* AdvancedContentProvider::getItemCustomControl(
    VfxU32 index,                                       // [IN] index of the item
    VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
    VfxFrame *parentFrame                            // [IN] parent frame of the custom content frame
    )
{    
    VappWlanSettingSwitchButton* ListMenuControl = NULL;
	srv_dtcnt_wlan_prefer_struct wlan_prefer_setting;
	srv_dtcnt_get_wlan_prefer_setting(&wlan_prefer_setting);	
#ifdef	__CBM_BEARER_SWITCH__
	VfxBool temp;
#endif /* __CBM_BEARER_SWITCH__ */
	
    if (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
    {   
#ifdef	__CBM_BEARER_SWITCH__
        if (index == ADVANCED_CONTENT_PROVIDER_NETWORK_NOTIFICATION)
        {
            VFX_OBJ_CREATE(ListMenuControl, VappWlanSettingSwitchButton, parentFrame);
			ListMenuControl->setId( SETTING_SWITCHBUTTON_NETWORKNOTI );
			temp = (VfxBool) ((wlan_prefer_setting.network_switch> 0) ? 1: 0);
			ListMenuControl->setSwitchStatus(temp);
            ListMenuControl->m_signalSwitchChanged.connect(this, &AdvancedContentProvider::OnRPSwitch);
        }
#endif /* __CBM_BEARER_SWITCH__ */

		if (index == ADVANCED_CONTENT_PROVIDER_AUTO_CONNECTION)
        {
            VFX_OBJ_CREATE(ListMenuControl, VappWlanSettingSwitchButton, parentFrame);
			ListMenuControl->setId( SETTING_SWITCHBUTTON_AUTOCONN );
            ListMenuControl->setSwitchStatus( ((MMI_TRUE == wlan_prefer_setting.is_auto_conn)? VFX_TRUE: VFX_FALSE) );
            ListMenuControl->m_signalSwitchChanged.connect(this, &AdvancedContentProvider::OnRPSwitch);
        }
				
        if (ListMenuControl)
        {
            ListMenuControl->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_MID);
        }
    }
    return ListMenuControl;
}

void AdvancedContentProvider::OnRPSwitch(VappWlanSettingSwitchButton *sw, VfxBool isChecked)
{
	srv_dtcnt_wlan_prefer_struct wlan_prefer_setting;
	srv_dtcnt_get_wlan_prefer_setting(&wlan_prefer_setting);

	switch( sw->getId() )
	{	
#ifdef	__CBM_BEARER_SWITCH__
		case SETTING_SWITCHBUTTON_NETWORKNOTI :		
			wlan_prefer_setting.network_switch= 
				(isChecked == MMI_TRUE) ? 1 : 0;
			srv_dtcnt_set_wlan_prefer_setting(&wlan_prefer_setting);
			VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_SWITCHBAR_STATE, 
				wlan_prefer_setting.is_auto_conn, wlan_prefer_setting.network_switch, __LINE__);
			break;			
#endif /* __CBM_BEARER_SWITCH__ */
		case SETTING_SWITCHBUTTON_AUTOCONN : 		
			wlan_prefer_setting.is_auto_conn = 
				(isChecked == MMI_TRUE) ? MMI_TRUE : MMI_FALSE;
			srv_dtcnt_set_wlan_prefer_setting(&wlan_prefer_setting);
			VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_SWITCHBAR_STATE, 
				wlan_prefer_setting.is_auto_conn, wlan_prefer_setting.network_switch, __LINE__);
			break;	
	}
}

// VFX_IMPLEMENT_CLASS ("VappSleepPolicySettingPage", VappSleepPolicySettingPage, VfxPage);
void VappSleepPolicySettingPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INIT_SLEEP_POLICY_SETTING_PAGE);
    Observer::onInit ();

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_SLEEP_POLICY));
    setTopBar (m_titleBar);

    // Networks list menu
    VFX_OBJ_CREATE (m_networksListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE (m_contentProvider, SleepPolicyContentProvider, this);
    m_contentProvider->setMenu (m_networksListMenu);
    m_networksListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);	
    m_networksListMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);	
    m_networksListMenu->setContentProvider (m_contentProvider);
    m_networksListMenu->setPos(0, 0);
    m_networksListMenu->setSize(getSize());
    m_networksListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
	m_networksListMenu->m_signalItemTapped.connect (
                                this, &VappSleepPolicySettingPage::onItemTapped);
}

void VappSleepPolicySettingPage::onItemTapped (VcpListMenu *sender, VfxU32 id)
{
	srv_dtcnt_wlan_prefer_struct wlan_prefer_setting;
	srv_dtcnt_get_wlan_prefer_setting(&wlan_prefer_setting);	
	
	wlan_prefer_setting.sleep_mode = (srv_dtcnt_wlan_sleep_mode_enum)id;
	srv_dtcnt_set_wlan_prefer_setting(&wlan_prefer_setting);	

	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_SETTING_SLEEP_POLICY, wlan_prefer_setting.sleep_mode);	
    getMainScr ()->popPage ();
}

/******************************************************************************/
// Implement the required content provider functions
void SleepPolicyContentProvider::setMenu(VcpListMenu *menu)
{
    m_listMenu = menu;
}

VfxU32 SleepPolicyContentProvider::getCount() const
{	
    return SLEEP_POLICY_ITEM_TOTAL;
}

VfxBool SleepPolicyContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
			if(SLEEP_POLICY_ITEM_NEVER == index)
			{
            	text.loadFromRes(STR_ID_VAPP_WLAN_SLEEP_POLICY_NEVER);
			}
			else if(SLEEP_POLICY_ITEM_NEVER_USB_PLUG_IN == index)
			{
				text.loadFromRes(STR_ID_VAPP_WLAN_SLEEP_POLICY_NEVER_USB_PLUG_IN);
			}
			else if(SLEEP_POLICY_ITEM_SCREEN_TURN_OFF == index)
			{
				text.loadFromRes(STR_ID_VAPP_WLAN_SLEEP_POLICY_SCREEN_TURN_OFF);
			}
            break;
    }
    return VFX_TRUE;
}

VcpListMenuItemStateEnum SleepPolicyContentProvider::getItemState(
                            VfxU32 index   // [IN] index of the item
                            ) const 
{
	srv_dtcnt_wlan_prefer_struct wlan_prefer_setting;
	srv_dtcnt_get_wlan_prefer_setting(&wlan_prefer_setting);	

	if(SLEEP_POLICY_ITEM_NEVER == index)
	{
		if(SRV_DTCNT_WLAN_SLEEP_MODE_NEVER_SLEEP == wlan_prefer_setting.sleep_mode)
		{		
        	return VCP_LIST_MENU_ITEM_STATE_SELECTED;
		}
		else
		{				
			return VCP_LIST_MENU_ITEM_STATE_NONE;
		}
	}
	else if(SLEEP_POLICY_ITEM_NEVER_USB_PLUG_IN == index)
	{
		if(SRV_DTCNT_WLAN_SLEEP_MODE_CHARGEIN_NEVER_SLEEP == wlan_prefer_setting.sleep_mode)
		{		
        	return VCP_LIST_MENU_ITEM_STATE_SELECTED;
		}
		else
		{				
			return VCP_LIST_MENU_ITEM_STATE_NONE;
		}
	}
	else if(SLEEP_POLICY_ITEM_SCREEN_TURN_OFF == index)
	{
		if(SRV_DTCNT_WLAN_SLEEP_MODE_LCD_OFF_SLEEP == wlan_prefer_setting.sleep_mode)
		{		
        	return VCP_LIST_MENU_ITEM_STATE_SELECTED;
		}
		else
		{				
			return VCP_LIST_MENU_ITEM_STATE_NONE;
		}
	}	
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}

#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__

