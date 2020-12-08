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
 *  vapp_dtcnt_wlan_cmcc_ui.h
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

#ifndef __VAPP_DTCNT_WLAN_CMCC_UI_H__
#define __VAPP_DTCNT_WLAN_CMCC_UI_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_OP01_WIFI__
#include "vapp_dtcnt_wlan_core.h"
#include "vcp_menu_popup.h"
#include "mmi_rp_app_cosmos_global_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Declaration

// Constructor / Destructor

// Method

// Overridable

// Override

// Variable

// Implementation
class VappRememberedNetworkPage;
class RememberedNetworkContentProvider;

class VappBlockedNetworkPage;
class BlockedNetworkContentProvider;

class VappAdvancedPage;
class AdvancedContentProvider;

class VappNonProxyAddressesPage;
class NonProxyAddressesContentProvider;

class VappCMCCNetworkMgrPage;
class CMCCNetWorkMgrContentProvider;

class VappWLANToCellularSettingPage;  
class WLANToCellularContentProvider;

/***************************************************************************** 
 * Class VappCMCCNetworkMgrPage
 *****************************************************************************/
class VappCMCCNetworkMgrPage : public Observer
{
// Declaration
    // VFX_DECLARE_CLASS(VappCMCCNetworkMgrPage);
// Constructor / Destructor
public:
    VappCMCCNetworkMgrPage() :
        m_repository(NULL)
    {
        m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
	    // register page in the respository
	    m_repository->registerObserver (this);
    }   
        
    VappCMCCNetworkMgrPage(VappWlanRepository *repository);
    virtual ~VappCMCCNetworkMgrPage();
    
// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onEnter(VfxBool isBackward);
    virtual void UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);

// Variable
private:
    VcpTitleBar                         *m_titleBar;
    VcpListMenu                         *m_networksListMenu; 
    VcpToolBar                          *m_toolBar;
    VcpToolBar                          *m_deleteListToolBar;
    CMCCNetWorkMgrContentProvider       *m_contentProvider;
    VappWlanRepository                  *m_repository;
    VcpMenuPopup                        *m_menuPopup;
    VfxWeakPtr<VcpMenuPopup>            m_popupWeakPtr;
    VappWlanProfile                     *m_editProfile; 
    VappWlanProfile                     *m_tempProfile;
    VfxU32                              m_longTapApId;
    
// Enum
    enum ScrItemIdEnum
    {
        TOOLBAR_REMEMBERED_NETWORK,
        TOOLBAR_BLOCKED_NETWORK,
        TOTAL_ITEMS
    };

    enum
    {
        MENU_POPUP_REMEMBER_NETWORK,
        MENU_POPUP_BLOCK_NETWORK,
        MENU_POPUP_FORGET_NETWORK,
        MENU_POPUP_END
    } ;

// Implementation
private:
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onItemTapped(VcpListMenu *sender, VfxU32 id);
    void onLongItemTapped(VcpListMenu *sender, VfxU32 id);
    void onMenuPopupTapped(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item);
    VfxBool IsAllowEditPopup(VappWlanBaseInfo *ap);
};

class CMCCNetWorkMgrContentProvider : public VfxObject,
                                  public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    CMCCNetWorkMgrContentProvider() :
        m_repository(NULL)
    {
        VFX_TRACE(("====Default Constructor - CMCCNetWorkMgrContentProvider====\n"));
    }

    CMCCNetWorkMgrContentProvider(const VappWlanRepository* repository) :
        m_repository(repository)
    {
        VFX_TRACE(("====Constructor - CMCCNetWorkMgrContentProvider====\n"));
    }

    virtual ~CMCCNetWorkMgrContentProvider() {}
// Method

// Overridable

// Override
public:
    virtual void onInit()
    {
        VfxObject::onInit ();
    }

    virtual void onDeinit()
    {
        VfxObject::onDeinit ();
    }

    virtual VfxU32 getCount() const;

    virtual void setMenu(VcpListMenu *menu);

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,           // [IN] index of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        );
   
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        ) ;

// Variable
private:
    const VappWlanRepository            *m_repository;
    const VcpListMenuItemStateEnum      *m_itemStateArray;
    VcpListMenu                         *m_listMenu;
    
// Implementation
};

class VappRememberedNetworkPage : public Observer
{
// Declaration
    // VFX_DECLARE_CLASS(VappRememberedNetworkPage);
// Constructor / Destructor
public:
    VappRememberedNetworkPage()
    {}  
    VappRememberedNetworkPage(VappWlanRepository *repository);
    virtual ~VappRememberedNetworkPage();
    
// Method
public:

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onBack ();
    virtual void onEnter(VfxBool isBackward);
    virtual void UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);

// Variable
private:
    VfxBool                             m_isSelectAll;
    VcpTitleBar                         *m_titleBar;
    VcpListMenu                         *m_networksListMenu; 
    VcpToolBar                          *m_toolBar;
    VcpToolBar                          *m_deleteListToolBar;
    RememberedNetworkContentProvider    *m_contentProvider;
    VappWlanRepository                  *m_repository;
    VcpListMenuItemStateEnum            m_itemStateArray[WLAN_AP_LIST_NUM_MAX];
    
// Enum
    enum ScrItemIdEnum
    {
        TOOLBAR_ADD_NETWORK,
        TOOLBAR_CHANGE_PRIORITY,
        TOOLBAR_MULTI_DELETE,
        TOOLBAR_MULTI_DELETE_SELECT_ALL,
        TOOLBAR_MULTI_DELETE_DELETE,
        TOOLBAR_MULTI_DELETE_CANCEL,
        TOTAL_ITEMS
    };

// Implementation
private:
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onToolBarFolding (VfxObject *sender, VfxBool is_fold);
    void onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onItemTapped(VcpListMenu *, VfxU32);
    void markAllAPs();
    void removeApFromSavedList();
    void goToDeleteApList();
    void returnMgrScreen();
    void initStatusArray();
    void initToolbar();
    void setToolbarDeleteStatus();
    void setToolbarMarkAllStatus();
    void entryAddNewNetworkProc ();
};

class RememberedNetworkContentProvider : public VfxObject,
                                        public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    RememberedNetworkContentProvider() :
        m_repository(NULL)
    {
        VFX_TRACE(("====Default Constructor - RememberedNetworkContentProvider====\n"));
    }

    RememberedNetworkContentProvider(const VappWlanRepository* repository, const VcpListMenuItemStateEnum* itemStateArray) :
        m_repository(repository), m_itemStateArray(itemStateArray)
    {
        VFX_TRACE(("====Constructor - NetWorkMgrContentProvider====\n"));
    }

    virtual ~RememberedNetworkContentProvider() {}
// Method

// Overridable

// Override
public:
    virtual void onInit()
    {
        VfxObject::onInit ();
    }

    virtual void onDeinit()
    {
        VfxObject::onDeinit ();
    }

    virtual VfxU32 getCount() const;

    virtual void setMenu(VcpListMenu *menu);
    
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    
    virtual VcpListMenuCellClientBaseFrame* getItemCustomContentFrame(
        VfxU32 index,           // [IN] the index of item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index                    // [IN] index of the item
        ) const;

    virtual VfxBool getItemIsDisabled(
        VfxU32 index                    // [IN] the index of item
        ) const;

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
   
// Variable
private:
    const VappWlanRepository            *m_repository;
    const VcpListMenuItemStateEnum      *m_itemStateArray;
    VcpListMenu                         *m_listMenu;
    
// Implementation
};

class VappBlockedNetworkPage : public Observer
{
// Declaration
    // VFX_DECLARE_CLASS(VappBlockedNetworkPage);
// Constructor / Destructor
public:
    VappBlockedNetworkPage() 
    {}  
    VappBlockedNetworkPage(VappWlanRepository *repository);
    virtual ~VappBlockedNetworkPage();
    
// Method
public:

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onBack ();
    virtual void onEnter(VfxBool isBackward);
    virtual void UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);

// Variable
private:
    VfxBool                             m_isSelectAll;
    VcpTitleBar                         *m_titleBar;
    VcpListMenu                         *m_networksListMenu; 
    VcpToolBar                          *m_toolBar;
    VcpToolBar                          *m_deleteListToolBar;
    BlockedNetworkContentProvider       *m_contentProvider;
    VappWlanRepository                  *m_repository;
    VcpListMenuItemStateEnum            m_itemStateArray[WLAN_AP_LIST_NUM_MAX];
  
// Enum
    enum ScrItemIdEnum
    {
        TOOLBAR_ADD_NETWORK,
        TOOLBAR_MULTI_DELETE,
        TOOLBAR_MULTI_DELETE_SELECT_ALL,
        TOOLBAR_MULTI_DELETE_DELETE,
        TOOLBAR_MULTI_DELETE_CANCEL,
        TOTAL_ITEMS
    };

// Implementation
private:
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onToolBarFolding (VfxObject *sender, VfxBool is_fold);
    void onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onItemTapped(VcpListMenu *, VfxU32);
    void markAllAPs();
    void removeApFromSavedList();
    void goToDeleteApList();
    void returnMgrScreen();
    void initStatusArray();
    void initToolbar();
    void setToolbarDeleteStatus();
    void setToolbarMarkAllStatus();
    void entryAddNewNetworkProc ();
};

class BlockedNetworkContentProvider : public VfxObject,
                                       public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    BlockedNetworkContentProvider() :
        m_repository(NULL)
    {
        VFX_TRACE(("====Default Constructor - BlockedNetworkContentProvider====\n"));
    }

    BlockedNetworkContentProvider(const VappWlanRepository* repository, const VcpListMenuItemStateEnum* itemStateArray) :
        m_repository(repository), m_itemStateArray(itemStateArray)
    {
        VFX_TRACE(("====Constructor - BlockedNetworkContentProvider====\n"));
    }

    virtual ~BlockedNetworkContentProvider() {}
// Method

// Overridable

// Override
public:
    virtual void onInit()
    {
        VfxObject::onInit ();
    }

    virtual void onDeinit()
    {
        VfxObject::onDeinit ();
    }

    virtual VfxU32 getCount() const;

    virtual void setMenu(VcpListMenu *menu);

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,           // [IN] index of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        );
   
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index                    // [IN] index of the item
        ) const;

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
   
// Variable
private:
    const VappWlanRepository            *m_repository;
    const VcpListMenuItemStateEnum      *m_itemStateArray;
    VcpListMenu                         *m_listMenu;
    
// Implementation
};

class VappEditAddressPage : public Observer
{
// Declaration
    // VFX_DECLARE_CLASS(VappEditAddressPage);
// Constructor / Destructor
public:
    VappEditAddressPage() 
    {}  
    VappEditAddressPage(VfxU8 * address,VappWlanRepository *repository);
    virtual ~VappEditAddressPage();
    
// Method
public:

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onBack ();
    virtual void onEnter(VfxBool isBackward);

// Variable
private:
    VcpTitleBar                         *m_titleBar;
    VcpFunctionBar                      *m_functionBar;
    VcpToolBar                          *m_toolBar;
    VcpFormItemTextInput                *m_addressText;
    VappWlanRepository                  *m_repository;
    VfxWString                           m_addressStr; 
    U8                                   m_editAddress[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1];
  
// Enum
    enum ScrItemIdEnum
    {
        TOOLBAR_SAVE_OK,
        TOOLBAR_SAVE_CANCEL,
        TOTAL_ITEMS
    };

// Implementation
private:
    void onToolBarClick (VfxObject *sender, VfxId id);  
    void saveEditAddress ();   
    VfxBool verifyAddressValue ();  
    void onFuncBarBtnClick (VfxObject* sender, VfxId id);  
    void showWarningPopup(const VfxWString& prompt);
    void showAddNewAddressBallon();
};

class VappNonProxyAddressesPage : public Observer
{
// Declaration
    // VFX_DECLARE_CLASS(VappNonProxyAddressesPage);
// Constructor / Destructor
public:
    VappNonProxyAddressesPage() 
    {}  
    VappNonProxyAddressesPage(VappWlanRepository *repository);
    virtual ~VappNonProxyAddressesPage();
    
// Method
public:

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onBack ();
    virtual void onEnter(VfxBool isBackward);

// Variable
private:
    VfxBool                             m_isSelectAll;
    VcpTitleBar                         *m_titleBar;
    VcpListMenu                         *m_networksListMenu; 
    VcpToolBar                          *m_toolBar;
    VcpToolBar                          *m_deleteListToolBar;
    NonProxyAddressesContentProvider    *m_contentProvider;
    VappWlanRepository                  *m_repository;
    VcpListMenuItemStateEnum            m_itemStateArray[WLAN_PROXY_EXCLUSIVE_NUM_MAX];
    
// Enum
    enum ScrItemIdEnum
    {
        TOOLBAR_ADD_ADDRESS,
        TOOLBAR_MULTI_DELETE,
        TOOLBAR_MULTI_DELETE_SELECT_ALL,
        TOOLBAR_MULTI_DELETE_DELETE,
        TOOLBAR_MULTI_DELETE_CANCEL,
        TOTAL_ITEMS
    };

// Implementation
private:
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onItemTapped(VcpListMenu *listMenu, VfxU32 index);
    void markAllAPs();
    void removeApFromSavedList();
    void goToDeleteApList();
    void returnMgrScreen();
    void initStatusArray();
    void initToolbar();
    void setToolbarDeleteStatus();
    void setToolbarMarkAllStatus();
    void entryAddAddressProc ();
};

class NonProxyAddressesContentProvider : public VfxObject,
                                       public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    NonProxyAddressesContentProvider() :
        m_repository(NULL)
    {
        VFX_TRACE(("====Default Constructor - NonProxyAddressesContentProvider====\n"));
    }

    NonProxyAddressesContentProvider(const VappWlanRepository* repository, const VcpListMenuItemStateEnum* itemStateArray) :
        m_repository(repository), m_itemStateArray(itemStateArray)
    {
        VFX_TRACE(("====Constructor - NonProxyAddressesContentProvider====\n"));
    }

    virtual ~NonProxyAddressesContentProvider() {}
// Method

// Overridable

// Override
public:
    virtual void onInit()
    {
        VfxObject::onInit ();
    }

    virtual void onDeinit()
    {
        VfxObject::onDeinit ();
    }

    virtual VfxU32 getCount() const;

    virtual void setMenu(VcpListMenu *menu);
    
/*
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,           // [IN] index of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        );
 */
 
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index                    // [IN] index of the item
        ) const;

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    
    srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *getProxyExclusiveListPtr();

    void setProxyExclusiveListNum(VfxU8 num);

    VfxU8 getProxyExclusiveListNum() const;

// Variable
private:
    const VappWlanRepository            *m_repository;
    const VcpListMenuItemStateEnum      *m_itemStateArray;
    VcpListMenu                         *m_listMenu;
    srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct m_proxyExclusiveList;
    VfxU8                               m_proxyExclusiveListNum;
            
// Implementation
};

class VappWLANToCellularSettingPage : public Observer
{
// Declaration
    // VFX_DECLARE_CLASS(VappWLANToCellularSettingPage);

// Constructor / Destructor
public:
    VappWLANToCellularSettingPage() 
    {}  
    virtual ~VappWLANToCellularSettingPage(){}
    
// Method

// Overridable

// Override
public:
    virtual void onInit ();

// Variable
private:
    VcpTitleBar                         *m_titleBar;
    VcpListMenu                         *m_networksListMenu;  
    WLANToCellularContentProvider       *m_contentProvider;
    
// Enum

// Implementation
private:
    void onItemTapped(VcpListMenu *, VfxU32);   
};

class WLANToCellularContentProvider : public VfxObject,
                                public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    WLANToCellularContentProvider()
    {
        VFX_TRACE(("====Default Constructor - AdvancedContentProvider====\n"));
    }

    virtual ~WLANToCellularContentProvider() {}
    
// Method

// Overridable

// Override

// override from Provider
public:
    virtual void setMenu(VcpListMenu *menu);

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const ;

// Variable
private:    
    VcpListMenu *m_listMenu;

    enum WLAN_TO_CELLULAR_ITEM_ENUM
    {
        WLAN_TO_CELLULAR_ITEM_ALWAYS_ASK, 
        WLAN_TO_CELLULAR_ITEM_NO_MORE_ASK,
        WLAN_TO_CELLULAR_ITEM_TOTAL
    };
};

#endif /* __MMI_OP01_WIFI__ */

#endif // __VAPP_DTCNT_WLAN_CMCC_UI_H__
