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
 *  vapp_dtcnt_wlan_cmcc_ui_adv.cpp
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

// VFX_IMPLEMENT_CLASS ("VappNonProxyAddressesPage", VappNonProxyAddressesPage, VfxPage);
VappNonProxyAddressesPage::VappNonProxyAddressesPage(VappWlanRepository *repository) : 
	m_isSelectAll(VFX_FALSE),
    m_repository(repository)
{
    // register page in the respository
    m_repository->registerObserver (this);
    // set flag
    m_repository->setIsDeleteApProc (VFX_FALSE);
}
    
VappNonProxyAddressesPage::~VappNonProxyAddressesPage()
{
    // deregister page in the respository
    m_repository->removeObserver (this);
}

void VappNonProxyAddressesPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_INIT_NON_PROXY_ADDRESS_PAGE);
    Observer::onInit ();

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_NON_PROXY_ADDRESSES));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
	m_toolBar->addItem (TOOLBAR_ADD_ADDRESS, VFX_WSTR_RES(STR_ID_VAPP_WLAN_ADD_ADDRESS), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);	
    m_toolBar->addItem (TOOLBAR_MULTI_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolBar->m_signalButtonTap.connect (this, &VappNonProxyAddressesPage::onToolBarClick);
    setBottomBar(m_toolBar);
	
    // Init delete list tool bar at first
    VFX_OBJ_CREATE (m_deleteListToolBar, VcpToolBar, this);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_deleteListToolBar->addItem (TOOLBAR_MULTI_DELETE_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_deleteListToolBar->setDisableItem (TOOLBAR_MULTI_DELETE_DELETE, VFX_TRUE);
    m_deleteListToolBar->m_signalButtonTap.connect (this, &VappNonProxyAddressesPage::onToolBarClick);

    // Networks list menu
    VFX_OBJ_CREATE (m_networksListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX (m_contentProvider, NonProxyAddressesContentProvider, this, (m_repository, m_itemStateArray));
    m_contentProvider->setMenu (m_networksListMenu);
    m_networksListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
    m_networksListMenu->setContentProvider (m_contentProvider);
    m_networksListMenu->setPos(0, 0);
    m_networksListMenu->setSize(getSize());
    m_networksListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_networksListMenu->m_signalItemSelectionStateChanged.connect (
            					this, &VappNonProxyAddressesPage::onItemStateChanged);
    m_networksListMenu->m_signalItemTapped.connect (
                                this, &VappNonProxyAddressesPage::onItemTapped);
}

void VappNonProxyAddressesPage::onEnter(VfxBool isBackward)
{
	srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *ptr;
	ptr = (srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *)
		m_contentProvider->getProxyExclusiveListPtr();
	srv_dtcnt_wlan_qry_proxy_exclusive_ip_addr(ptr);
	m_contentProvider->setProxyExclusiveListNum(ptr->num_ips);

    if(isBackward)
    {
        if(m_repository->getIsDeleteApProc ())
        {
            //initStatusArray ();
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

void VappNonProxyAddressesPage::onBack ()
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

void VappNonProxyAddressesPage::onDeinit ()
{
    VFX_OBJ_CLOSE (m_titleBar);
    VFX_OBJ_CLOSE (m_networksListMenu);
    VFX_OBJ_CLOSE (m_contentProvider);
    if(m_deleteListToolBar != NULL)
    {
        VFX_OBJ_CLOSE (m_deleteListToolBar);
    }
    VFX_OBJ_CLOSE (m_toolBar);
    
    Observer::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_DEINIT_NON_PROXY_ADDRESS_PAGE);
}

void VappNonProxyAddressesPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
    	case TOOLBAR_ADD_ADDRESS:
			m_repository->setIsEditAddressProc(VFX_FALSE);
			entryAddAddressProc();
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

void VappNonProxyAddressesPage::entryAddAddressProc ()
{
    if(WLAN_PROXY_EXCLUSIVE_NUM_MAX == m_contentProvider->getProxyExclusiveListPtr()->num_ips)
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

    VappEditAddressPage* editAddressPage = NULL;
    
    VFX_OBJ_CREATE_EX (editAddressPage, VappEditAddressPage, getMainScr(), (NULL, m_repository));
    getMainScr ()->pushPage (0, editAddressPage);
}


void VappNonProxyAddressesPage::onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VFX_TRACE(("=== Item %d's new status: %d\n", index, newState));
    m_itemStateArray[index] = newState;
    // Enable/Disable toolbar button "Delete"
    setToolbarDeleteStatus();
    setToolbarMarkAllStatus();
}

void VappNonProxyAddressesPage::onItemTapped(VcpListMenu *sender, VfxU32 id)
{
    if(m_repository->getIsDeleteApProc () == VFX_TRUE)
    {
        return;
    }

    srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *
		nonProxyAddressList =  m_contentProvider->getProxyExclusiveListPtr();	

	m_repository->setIsEditAddressProc(VFX_TRUE);
	
    VappEditAddressPage* editAddressPage = NULL;
    VFX_OBJ_CREATE_EX (
        editAddressPage, 
        VappEditAddressPage, 
        getMainScr (), 
        (nonProxyAddressList->ips[id].ip_addr, m_repository));
    getMainScr()->pushPage(0, editAddressPage);
}

void VappNonProxyAddressesPage::markAllAPs()
{
    VfxU8 total = m_contentProvider->getProxyExclusiveListPtr()->num_ips;

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

void VappNonProxyAddressesPage::removeApFromSavedList()
{
    VfxU8 index = 0;
    VfxU8 deleteNum = 0;
    VfxU8 total = m_contentProvider->getProxyExclusiveListPtr()->num_ips;
	srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *
		nonProxyAddressList = m_contentProvider->getProxyExclusiveListPtr();	
    
    for(index = 0; index < total; index++)
    {
        VFX_TRACE(("=== ITEM STATUS: %d ===\n", m_itemStateArray[index]));
        if(VCP_LIST_MENU_ITEM_STATE_SELECTED == m_itemStateArray[index])
        {
            // Todo: remove them from saved list
            deleteNum++;         
            srv_dtcnt_wlan_delete_proxy_exclusive_ip_addr(&nonProxyAddressList->ips[index]);
        }
    }

    VFX_TRACE(("=== Delete %d AP ===\n", deleteNum));

	//update ProxyExclusiveList
	srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *ptr;
	ptr = (srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *)
		m_contentProvider->getProxyExclusiveListPtr();
	srv_dtcnt_wlan_qry_proxy_exclusive_ip_addr(ptr);
	m_contentProvider->setProxyExclusiveListNum(ptr->num_ips);
	
    returnMgrScreen();
}

void VappNonProxyAddressesPage::goToDeleteApList()
{
    // initialize status array
    initStatusArray();
    // set flag that go to delete ap list
    m_repository->setIsDeleteApProc (VFX_TRUE);
    // Refresh list menu
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_DELETE_ADDRESS));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_networksListMenu->setMenuMode (VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
    m_networksListMenu->updateAllItems ();
    setBottomBar(m_deleteListToolBar);
    setToolbarDeleteStatus();
    setToolbarMarkAllStatus();
}

void VappNonProxyAddressesPage::returnMgrScreen()
{
    // set flag as not in the delete ap's proc
    m_repository->setIsDeleteApProc (VFX_FALSE);
    // Refresh list menu
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_NON_PROXY_ADDRESSES));
    m_networksListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_networksListMenu->setMenuMode (VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_networksListMenu->updateAllItems ();
    setBottomBar(m_toolBar);
    // set toolbar items' status
    initToolbar();
}

void VappNonProxyAddressesPage::initStatusArray()
{
    VfxU8 index;
    VfxU8 total = m_contentProvider->getProxyExclusiveListPtr()->num_ips;
    
    for(index = 0; index < total; index++)
    {
        m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

void VappNonProxyAddressesPage::initToolbar()
{
    // No saved AP, disable item 'Change priority' and 'Delete'
    if(0 == m_contentProvider->getProxyExclusiveListPtr()->num_ips)
    {
        m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_TRUE);
    }
    // Otherwise, enable. 
    else
    {
		m_toolBar->setDisableItem (TOOLBAR_MULTI_DELETE, VFX_FALSE);
    }
}

void VappNonProxyAddressesPage::setToolbarDeleteStatus()
{
    VfxU8 pos = 0;
    VfxU8 total = m_contentProvider->getProxyExclusiveListPtr()->num_ips;
    
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

void VappNonProxyAddressesPage::setToolbarMarkAllStatus()
{
    VfxU8 pos = 0;
    VfxU8 total = m_contentProvider->getProxyExclusiveListPtr()->num_ips;
    VfxU8 totalDisableItem = 0, totalMarkItem = 0, totalUnmarkItem = 0;
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
void NonProxyAddressesContentProvider::setMenu(VcpListMenu *menu)
{
    m_listMenu = menu;
}

VfxU32 NonProxyAddressesContentProvider::getCount() const
{	
    return getProxyExclusiveListNum();
}

/*
VcpListMenuCellClientBaseFrame* NonProxyAddressesContentProvider::getItemCustomContentFrame(
        VfxU32 index,           // [IN] the index of item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        )
{
    VcpListMenuCellIconSingleTextFrameEx*  apListMenuCell;
    VFX_OBJ_CREATE (apListMenuCell, VcpListMenuCellIconSingleTextFrameEx, parentFrame);
    return apListMenuCell;    
}
*/

VfxBool NonProxyAddressesContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    VfxWString description = VFX_WSTR_EMPTY;
    srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *
		nonProxyAddressList = getProxyExclusiveListPtr();	
    VfxU8 *name;
    
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
			// convert ssid from ascii to unicode
    		VFX_ALLOC_MEM(name, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH, this);
    		memset(name, 0, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH);
    		mmi_asc_to_ucs2 ((CHAR *)name, (CHAR *)nonProxyAddressList->ips[index].ip_addr);
            text.loadFromMem ((const VfxWChar *)name);
			VFX_FREE_MEM(name);
            break;
    }

    return VFX_TRUE;
}

VcpListMenuItemStateEnum NonProxyAddressesContentProvider::getItemState(
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

VfxBool NonProxyAddressesContentProvider::getItemImage(
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

VfxBool NonProxyAddressesContentProvider::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    if((VFX_FALSE == m_repository->getIsDeleteApProc ()) &&
       (0 == getProxyExclusiveListPtr()->num_ips))
    {
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_NO_ADDRESS);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
        
    return VFX_FALSE;
}

srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *
	NonProxyAddressesContentProvider::getProxyExclusiveListPtr()
{
	return &m_proxyExclusiveList;
}

void NonProxyAddressesContentProvider::setProxyExclusiveListNum(VfxU8 num)
{
	m_proxyExclusiveListNum = num ;
}

VfxU8 NonProxyAddressesContentProvider::getProxyExclusiveListNum() const
{
	return m_proxyExclusiveListNum;
}

// VFX_IMPLEMENT_CLASS ("VappEditAddressPage", VappEditAddressPage, VfxPage);
VappEditAddressPage::VappEditAddressPage(VfxU8 *address, VappWlanRepository *repository) : 
    m_repository(repository)
{	
    // register page in the respository
    m_repository->registerObserver (this);
	
    m_addressStr = VFX_WSTR_EMPTY;	
    VfxWChar*   tempAddress;
	
	if( VFX_TRUE == m_repository->getIsEditAddressProc() )
	{			
		memcpy(m_editAddress, address, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
		VFX_ALLOC_MEM(tempAddress, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1) * ENCODING_LENGTH, this);
		//address
	    VfxU32 addressLen = strlen((const char *)address);
	    VFX_TRACE(("===== address: %d =====\n", addressLen));
	    if(addressLen > 0 && addressLen < SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1)
	    {
	        mmi_asc_to_ucs2 ((CHAR *)tempAddress, (CHAR *)address);
	        m_addressStr.loadFromMem ((const VfxWChar *)tempAddress);
	    }
		else
		{
	    	m_addressStr = VFX_WSTR("http://");
		}
		VFX_FREE_MEM(tempAddress);
	}
	else
	{
	    m_addressStr = VFX_WSTR("http://");
	}
}
    
VappEditAddressPage::~VappEditAddressPage()
{
    // deregister page in the respository
    m_repository->removeObserver (this);
}

void VappEditAddressPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_INIT_EDIT_ADDRESS_PAGE);
    Observer::onInit ();

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
	if( VFX_TRUE == m_repository->getIsEditAddressProc() )
    	m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EDIT_ADDRESS));
	else
    	m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ADD_ADDRESS));		
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
	m_toolBar->addItem (TOOLBAR_SAVE_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);	
    m_toolBar->addItem (TOOLBAR_SAVE_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappEditAddressPage::onToolBarClick);
    setBottomBar(m_toolBar);
	
    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(0, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_functionBar->setItemSpecial (0);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (this, &VappEditAddressPage::onFuncBarBtnClick);	

	// Input URL address
    VFX_OBJ_CREATE(m_addressText, VcpFormItemTextInput, this);
    m_addressText->getTextBox ()->setText (m_addressStr, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);
    m_addressText->getTextBox ()->setIME(IMM_INPUT_TYPE_URL);
	m_addressText->getTextBox ()->activate();
	// m_addressText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_addressText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_URL_ADDRESS));
    m_addressText->setLabelPosition (VCPFORM_TOP_LEFT);
    m_addressText->setPos (0, 0);
    m_addressText->getTextBox ()->setFunctionBar (m_functionBar);
}

void VappEditAddressPage::onEnter(VfxBool isBackward)
{
	Observer::onEnter(isBackward);
}

void VappEditAddressPage::onBack ()
{
    Observer::onBack ();
}

void VappEditAddressPage::onDeinit ()
{
    VFX_OBJ_CLOSE (m_titleBar);
    VFX_OBJ_CLOSE (m_toolBar);
    
    Observer::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_DEINIT_EDIT_ADDRESS_ADDRESS_PAGE);
}

void VappEditAddressPage::onToolBarClick (VfxObject *sender, VfxId id)
{
    VFX_TRACE(("Receive event from tool bar item %d\n", id));
    
    switch(id)
    {
    	case TOOLBAR_SAVE_OK:
			saveEditAddress();
			break;
        case TOOLBAR_SAVE_CANCEL:
            getMainScr ()->popPage ();         
            break;
        default:
            break;
    }
}

void VappEditAddressPage::onFuncBarBtnClick (VfxObject* sender, VfxId id)
{
    m_addressText->getTextBox ()->deactivate ();
    saveEditAddress();
}

VfxBool VappEditAddressPage::verifyAddressValue ()
{
    VfxChar*    itemAscii;
    VfxWString  address = VFX_WSTR_EMPTY;
	VfxBool		result = VFX_TRUE;

    // Verify address
    address = m_addressText->getText ();
    VFX_ALLOC_MEM(itemAscii, (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1), this);
    memset(itemAscii, 0, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
    VappWlanToolbox::convertStrToAscii (itemAscii, address, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);
    
    if(VFX_FALSE == VappWlanToolbox::isUrlValid(itemAscii))
    {
        result &= 0;
        m_addressText->setWarningText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_INVALID_ADDRESS));
        // m_addressText->setFocused (VFX_TRUE);  // Scroll to address item
    }
    else
    {
        result &= 1;
        m_addressText->setWarningText (VFX_WSTR_EMPTY);
    }
	
    VFX_FREE_MEM(itemAscii);
	return result;
}

void VappEditAddressPage::saveEditAddress()
{
	VfxWString  prompt = VFX_WSTR_EMPTY;
	VfxWString  address = VFX_WSTR_EMPTY;
	VfxBool isExist = VFX_FALSE;
    address = m_addressText->getText ();	
	
	srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *ptr;	
	srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct tempProxyAddr;	
    memset(tempProxyAddr.ip_addr, 0, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
    VappWlanToolbox::convertStrToAscii (
		(VfxChar *)tempProxyAddr.ip_addr, address, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);

	if( VFX_TRUE == verifyAddressValue () )
	{	
		VFX_ALLOC_MEM(ptr, sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct), this);		
		srv_dtcnt_wlan_qry_proxy_exclusive_ip_addr(ptr);

		for(U32 i = 0; i < ptr->num_ips; i++)
		{
			if(0 == strcmp((char *)ptr->ips[i].ip_addr, (char *)tempProxyAddr.ip_addr))
			{
				isExist = VFX_TRUE;
				break;
			}
		}
		
		if(VFX_TRUE == m_repository->getIsEditAddressProc())
		{		
			if(VFX_TRUE == isExist && 0 != strcmp((char *)m_editAddress, (char *)tempProxyAddr.ip_addr)) 
		    {
		        prompt = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_ADDRESS_EXISTED);
		        showWarningPopup(prompt);				
				VFX_FREE_MEM(ptr);
				return;
		    }	
			srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct editProxyAddr;
			memcpy(editProxyAddr.ip_addr, m_editAddress, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);
			srv_dtcnt_wlan_delete_proxy_exclusive_ip_addr(&editProxyAddr);
			srv_dtcnt_wlan_add_proxy_exclusive_ip_addr(&tempProxyAddr);
		}
		else
		{
			if(VFX_TRUE == isExist) 
		    {
		        prompt = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ERR_ADDRESS_EXISTED);
		        showWarningPopup(prompt);					
				VFX_FREE_MEM(ptr);
				return;
		    }	
			srv_dtcnt_wlan_add_proxy_exclusive_ip_addr(&tempProxyAddr);
			showAddNewAddressBallon();
		}
		VFX_FREE_MEM(ptr);
		getMainScr ()->popPage ();
	}
}

void VappEditAddressPage::showWarningPopup(const VfxWString& prompt)
{
    VcpConfirmPopup* invalidInputPopup = NULL;

    VFX_OBJ_CREATE (invalidInputPopup, VcpConfirmPopup, getMainScr());
    invalidInputPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
    invalidInputPopup->setText(prompt);
    invalidInputPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
    invalidInputPopup->setAutoDestory(VFX_TRUE);
    invalidInputPopup->show (VFX_TRUE);
}

void VappEditAddressPage::showAddNewAddressBallon()
{
    VfxWString hintText = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ADD_ADDRESS_HINT_TEXT);

    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_SUCCESS,
        (const WCHAR *)hintText.getBuf ());
}

// VFX_IMPLEMENT_CLASS ("VappWLANToCellularSettingPage", VappWLANToCellularSettingPage, VfxPage);
void VappWLANToCellularSettingPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_INIT_WLAN_TO_CELLULAR_SETTING_PAGE);
    Observer::onInit ();

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    
    // Title bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_NO_WLAN_TO_CELLULAR));
    setTopBar (m_titleBar);

    // Networks list menu
    VFX_OBJ_CREATE (m_networksListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE (m_contentProvider, WLANToCellularContentProvider, this);
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
                                this, &VappWLANToCellularSettingPage::onItemTapped);
}

void VappWLANToCellularSettingPage::onItemTapped (VcpListMenu *sender, VfxU32 id)
{
	srv_dtcnt_wlan_prefer_struct wlan_prefer_setting;
	srv_dtcnt_get_wlan_prefer_setting(&wlan_prefer_setting);	
	
	wlan_prefer_setting.cellular_switch = id;
	srv_dtcnt_set_wlan_prefer_setting(&wlan_prefer_setting);	
	
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_WLAN_TO_CELLULAR_STATUS, wlan_prefer_setting.cellular_switch);	
	getMainScr ()->popPage ();
}

/******************************************************************************/
// Implement the required content provider functions
void WLANToCellularContentProvider::setMenu(VcpListMenu *menu)
{
    m_listMenu = menu;
}

VfxU32 WLANToCellularContentProvider::getCount() const
{	
    return WLAN_TO_CELLULAR_ITEM_TOTAL;
}

VfxBool WLANToCellularContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
			if(WLAN_TO_CELLULAR_ITEM_ALWAYS_ASK == index)
			{
            	text.loadFromRes(STR_ID_VAPP_WLAN_ALWAYS_ASK);
			}
			else if(WLAN_TO_CELLULAR_ITEM_NO_MORE_ASK == index)
			{
				text.loadFromRes(STR_ID_VAPP_WLAN_NO_MORE_ASK);
			}
            break;
    }
    return VFX_TRUE;
}

VcpListMenuItemStateEnum WLANToCellularContentProvider::getItemState(
                            VfxU32 index   // [IN] index of the item
                            ) const 
{
	srv_dtcnt_wlan_prefer_struct wlan_prefer_setting;
	srv_dtcnt_get_wlan_prefer_setting(&wlan_prefer_setting);	

	if(WLAN_TO_CELLULAR_ITEM_ALWAYS_ASK == index)
	{
		if(0 == wlan_prefer_setting.cellular_switch)// always ask
		{		
        	return VCP_LIST_MENU_ITEM_STATE_SELECTED;
		}
		else
		{				
			return VCP_LIST_MENU_ITEM_STATE_NONE;
		}
	}
	else if(WLAN_TO_CELLULAR_ITEM_NO_MORE_ASK == index)
	{
		if(1 == wlan_prefer_setting.cellular_switch)// no more ask
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

#endif // __MMI_OP01_WIFI__
#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__

