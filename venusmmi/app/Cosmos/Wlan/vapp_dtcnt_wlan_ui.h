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
 *  vapp_dtcnt_wlan_ui.h
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
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_WLAN_UI_H__
#define __VAPP_DTCNT_WLAN_UI_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "vapp_dtcnt_wlan_core.h"
#include "vcp_menu_popup.h"
#include "mmi_rp_app_cosmos_global_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define  SSID_TEXT_EDITOR_LEN_MAX   WNDRV_SSID_MAX_LEN * ENCODING_LENGTH
#define  PROXY_PORT_VALUE_MAX       (65535)
#define  DEFAULT_ADDRESS_STR        "000.000.000.000"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define  EAP_TYPE_MAIN_PAGE_ITEM_COUNT  5
#define  EAP_TYPE_PEAP_PAGE_ITEM_COUNT  4
#define  EAP_TYPE_TTLS_PAGE_ITEM_COUNT  8

#ifndef __WPS_SUPPORT__
#define  WLAN_APP_MAIN_PAGE_ITEM_COUNT  0
#else
#define  WLAN_APP_MAIN_PAGE_ITEM_COUNT  1
#endif  /* __WPS_SUPPORT__ */

// Declaration

// Constructor / Destructor

// Method

// Overridable

// Override

// Variable

// Implementation
#ifndef WIFI_AUTH_PSK_ONLY
class VappWlanEAPTypesPage;
class VappWlanEAPUserInfoPage;
class VappWlanEAPMultiPage;
class VappWlanEAPTLSPage;
class VappWlanEAPTypesContentProvider;
#endif /* WIFI_AUTH_PSK_ONLY */

class VappPropertyPage;
class VappJoinNetworkPage;
class VappChangePriorityPage; 
class VappNetworkMgrPage;
class VappWifiSettingsPage;
class VappWepKeySettingPage;
class AdvancedContentProvider;
class VappAdvancedPage;
class SleepPolicyContentProvider;
class VappSleepPolicySettingPage;

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
class VappWaiCertSettingsPage;
class VappWaiPskSettingsPage;
#endif  /* __MMI_HIDE_WAPI__*/
#endif  /* __WAPI_SUPPORT__ */


#ifndef WIFI_AUTH_PSK_ONLY
/***************************************************************************** 
 * Class VappWlanEAPTypesContentProvider
 *****************************************************************************/
class VappWlanEAPTypesContentProvider : public VfxObject,
                                        public IVcpListMenuContentProvider
{
// Declaration

// Constructor / Destructor
public:
    VappWlanEAPTypesContentProvider()
    {}
    
    VappWlanEAPTypesContentProvider(
        VfxU32 itemCount, 
        VAPP_WLAN_EAP_TYPE_PAGE_ENUM pageEnum, 
        supc_abm_eap_type_enum* eapTypeArray, 
        VappWlanProfile* profile) :
                m_itemCount(itemCount), 
                m_eapTypeArray(eapTypeArray),                
                m_eapTypePageEnum(pageEnum),
                m_profile(profile) 
    {
    }
        
    virtual ~VappWlanEAPTypesContentProvider()
    {}

// Method

// Overridable
protected:
    virtual void onInit()
    {
        VfxObject::onInit ();
    }

    virtual void onDeinit()
    {
        VfxObject::onDeinit ();
    }

    virtual VfxU32 getCount() const;
    
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

// Override

// Variable
private:
    VfxU32                      m_itemCount;
    supc_abm_eap_type_enum*     m_eapTypeArray;
    VAPP_WLAN_EAP_TYPE_PAGE_ENUM m_eapTypePageEnum;
    VappWlanProfile             *m_profile;

// Implementation    
};

/***************************************************************************** 
 * Class VappWlanEAPTLSPage
 *****************************************************************************/
class VappWlanEAPTLSPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappWlanEAPTLSPage);

// Constructor / Destructor
public:
    VappWlanEAPTLSPage() 
    {
        m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        // register page in the respository
        m_repository->registerObserver (this);
    }
    
    VappWlanEAPTLSPage(VappWlanProfile* profile);
    virtual ~VappWlanEAPTLSPage() ;

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);

// Variable    
private:
    VappWlanProfile             *m_profile;
    
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpFormItemBigArrowButton   *m_caCertBtn;
    VcpFormItemBigArrowButton   *m_userCertBtn;
    VcpFormItemTextInput        *m_privateKeyText;
    VcpFormItemTextInput        *m_usernameText;
    VcpForm                     *m_form;
    VcpFunctionBar              *m_functionBar;
    VcpTextEditor               *m_prevEditor;
    VcpTextEditor               *m_nextEditor;
    VcpTextEditor               *m_curEditor;

    VfxU32                      m_tempRootCaId;          /* root ca id */
    VfxU32                      m_tempUserCaId;          /* user cert id */
    VfxU8                       m_tempCaCertName[SRV_DTCNT_PROF_MAX_USER_LEN + 1];
    VfxU8                       m_tempUserCertName[SRV_DTCNT_PROF_MAX_USER_LEN + 1];
    VfxWString                  m_privateKey;
    VfxWString                  m_username;
    VappWlanRepository          *m_repository;
    
    enum EAP_TLS_SETTING_TOOLBAR_ITEM_ENUM
    {
        EAP_TLS_SETTING_TOOLBAR_OK, 
        EAP_TLS_SETTING_TOOLBAR_CANCEL,
        EAP_TLS_SETTING_TOOLBAR_TOTAL
    };

    enum EAP_TLS_PAGE_FORM_ITEM_ENUM
    {
        EAP_TLS_PAGE_FORM_BUTTON_CA_CERT,
        EAP_TLS_PAGE_FORM_BUTTON_USER_CERT,
        EAP_TLS_PAGE_FORM_TEXT_PRIVATE_KEY,
        EAP_TLS_PAGE_FORM_TEXT_USERNAME,
        EAP_TLS_PAGE_FORM_FUNC_BAR_PREV,
        EAP_TLS_PAGE_FORM_FUNC_BAR_NEXT,
        EAP_TLS_PAGE_FORM_FUNC_BAR_OK,
        EAP_TLS_PAGE_FORM_NETWORK_TOTAL
    };

    void onToolBarClick(VfxObject* sender, VfxId id);
    void onPropertyBtnClick(VfxObject* sender, VfxId id);
    void onFuncBarBtnClick (VfxObject *sender, VfxId id);
    void onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive);
    void saveEapTlsSettings();
   
// Implementation    
};

/***************************************************************************** 
 * Class VappWlanEAPMultiPage
 *****************************************************************************/
class VappWlanEAPMultiPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappWlanEAPMultiPage);

// Constructor / Destructor
public:
    VappWlanEAPMultiPage()
    {
        m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        // Register messages which are interested
        m_repository->registerObserver (this);
    }
    
    VappWlanEAPMultiPage(
        VfxU32 itemCount, 
        VAPP_WLAN_EAP_TYPE_PAGE_ENUM pageEnum, 
        supc_abm_eap_type_enum* eapTypeArray, 
        VappWlanProfile* profile);

    virtual ~VappWlanEAPMultiPage() ;

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onEnter (VfxBool isBackward);
    virtual void onDeinit ();
    virtual void UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);

// Variable    
private:
    VfxU32                      m_itemCount;
    supc_abm_eap_type_enum*     m_eapTypeArray;
    VAPP_WLAN_EAP_TYPE_PAGE_ENUM m_eapTypePageEnum;
    VappWlanProfile             *m_profile;
    VappWlanProfile             *m_tempProfile;

    VfxU32                      m_tempRootCaId;          /* root ca id */
    VfxU8                       m_tempCaCertName[SRV_DTCNT_PROF_MAX_USER_LEN + 1];
    VappWlanRepository          *m_repository;
    
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpFormItemBigArrowButton   *m_caCertBtn;
    VcpFormItemBigArrowButton   *m_eapTypesBtn;
    VcpForm                     *m_form;
    
    enum MULTI_SETTING_TOOLBAR_ITEM_ENUM
    {
        MULTI_SETTING_TOOLBAR_OK, 
        MULTI_SETTING_TOOLBAR_CANCEL,
        MULTI_SETTING_TOOLBAR_TOTAL
    };

    enum EAP_MULTI_PAGE_FORM_ITEM_ENUM
    {
        EAP_MULTI_PAGE_FORM_BUTTON_CA_CERT,
        EAP_MULTI_PAGE_FORM_BUTTON_EAP_TYPES,
        EAP_MULTI_PAGE_FORM_NETWORK_TOTAL
    };

    void onToolBarClick(VfxObject* sender, VfxId id);
    void onPropertyBtnClick(VfxObject* sender, VfxId id);

    
// Implementation  
};

/***************************************************************************** 
 * Class VappWlanEAPUserInfoPage
 *****************************************************************************/
class VappWlanEAPUserInfoPage : public VfxPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappWlanEAPUserInfoPage);

// Constructor / Destructor
public:
    VappWlanEAPUserInfoPage() {}
    VappWlanEAPUserInfoPage(VappWlanProfile* profile);
    virtual ~VappWlanEAPUserInfoPage() {}

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();

// Variable    
private:
    VappWlanProfile             *m_profile;
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpFormItemTextInput        *m_usernameText;
    VcpFormItemTextInput        *m_passwordText;
    VcpForm                     *m_form;
    VcpFunctionBar              *m_functionBar;
    VcpTextEditor               *m_prevEditor;
    VcpTextEditor               *m_nextEditor;
    VcpTextEditor               *m_curEditor;
    VfxWString                  m_usernameStr;
    VfxWString                  m_passwordStr;

    enum USER_INFO_SETTING_TOOLBAR_ITEM_ENUM
    {
        USER_INFO_SETTING_TOOLBAR_OK, 
        USER_INFO_SETTING_TOOLBAR_CANCEL,
        USER_INFO_SETTING_TOOLBAR_TOTAL
    };

    enum USER_INFO_PAGE_FORM_ITEM_ENUM
    {
        USER_INFO_PAGE_FORM_BUTTON_USERNAME,
        USER_INFO_PAGE_FORM_BUTTON_PASSWORD,
        USER_INFO_PAGE_FORM_FUNC_PREV,
        USER_INFO_PAGE_FORM_FUNC_NEXT,
        USER_INFO_PAGE_FORM_FUNC_DONE,
        USER_INFO_PAGE_FORM_NETWORK_TOTAL
    };

    void onToolBarClick(VfxObject* sender, VfxId id);
    void onFuncBarBtnClick (VfxObject *sender, VfxId id);
    void onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive);
    
    void saveEapUserInfo();
    
// Implementation  

};

/***************************************************************************** 
 * Class VappWlanEAPTypesPage
 *****************************************************************************/
class VappWlanEAPTypesPage : public VfxPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappWlanEAPTypesPage);

// Constructor / Destructor
public:
    VappWlanEAPTypesPage() {}
    VappWlanEAPTypesPage(
        VfxU32 itemCount, 
        VAPP_WLAN_EAP_TYPE_PAGE_ENUM pageEnum, 
        supc_abm_eap_type_enum* eapTypeArray, 
        VappWlanProfile* profile);
    virtual ~VappWlanEAPTypesPage() {}

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();

// Variable    
private:
    VfxU32                      m_itemCount;
    supc_abm_eap_type_enum*     m_eapTypeArray;
    VAPP_WLAN_EAP_TYPE_PAGE_ENUM m_eapTypePageEnum;
    VappWlanProfile             *m_profile;
    
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpListMenu                         *m_eapTypeListMenu; 
    VappWlanEAPTypesContentProvider     *m_eapTypeContentProvider;

    supc_abm_eap_type_enum      m_eapPeapTypeArray[EAP_TYPE_PEAP_PAGE_ITEM_COUNT];
    supc_abm_eap_type_enum      m_eapTtlsTypeArray[EAP_TYPE_TTLS_PAGE_ITEM_COUNT];
    VcpListMenuItemStateEnum    m_itemStateArray[EAP_TYPE_TTLS_PAGE_ITEM_COUNT];

    enum EAP_TYPES_SETTING_TOOLBAR_ITEM_ENUM
    {
        EAP_TYPES_SETTING_TOOLBAR_OK, 
        EAP_TYPES_SETTING_TOOLBAR_CANCEL,
        EAP_TYPES_SETTING_TOOLBAR_TOTAL
    };
    void onCmdButtonClicked(VcpListMenu * sender, VfxU32 index);
    void onSelectStateChanged(VcpListMenu * sender,VfxU32 index, VcpListMenuItemStateEnum newState);
    void onToolBarClick(VfxObject* sender, VfxId id);
    VfxBool saveEapTypesSettings();
    void initEapTypesStatusArray();
    
// Implementation    
};

#endif /* WIFI_AUTH_PSK_ONLY */

/******************************************************************************/
/*                          Class VappAdvancedPage                     */
/******************************************************************************/
class VappAdvancedPage : public Observer
{
// Declaration
    // VFX_DECLARE_CLASS(VappAdvancedPage);

// Constructor / Destructor
public:
    VappAdvancedPage() 
    {}  
    VappAdvancedPage(VappWlanRepository *repository);
    virtual ~VappAdvancedPage();
    
// Method
public:
#ifdef __MMI_OP01_WIFI__ 
    static void responseCloseCMCCSettingPageEvent(mmi_event_struct* param);
#endif /* __MMI_OP01_WIFI__ */

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onEnter(VfxBool isBackward);
#ifdef __MMI_OP01_WIFI__ 
    virtual mmi_ret onProc(mmi_event_struct *evt);
#endif /* __MMI_OP01_WIFI__ */

// Variable
private:
    AdvancedContentProvider             *m_contentProvider;
    VappWlanRepository                  *m_repository;
    VcpTitleBar                         *m_titleBar;  
    VcpListMenu                         *m_networksListMenu;    
	mmi_id                               m_fsCuiId;
    
// Enum
    enum ADVANCED_PAGE_ITEM_ENUM
    {    
#ifdef __CBM_BEARER_SWITCH__ 
        ADVANCED_PAGE_ITEM_NETWORK_NOTIFICATION,
#endif /* __CBM_BEARER_SWITCH__ */ 

        ADVANCED_PAGE_ITEM_AUTO_CONNECTION,
        
#ifdef __MMI_OP01_WIFI__ 
        ADVANCED_PAGE_ITEM_CMCC_SETTING, 
        ADVANCED_PAGE_ITEM_NON_PROXY,
        ADVANCED_PAGE_ITEM_CERTMAN_LOAD,
        ADVANCED_PAGE_ITEM_CERTMAN_UNLOAD,
        ADVANCED_PAGE_ITEM_WLAN_TO_CELLULAR,
#endif /* __MMI_OP01_WIFI__ */

        ADVANCED_PAGE_ITEM_SLEEP_POLICY, 

        ADVANCED_PAGE_ITEM_TOTAL
    };

// Implementation
private:
    void onItemTapped(VcpListMenu *, VfxU32);   
#ifdef __MMI_OP01_WIFI__ 
    void entryLoadWAPICertProc();    
    void entryUnLoadWAPICertProc();
#endif /* __MMI_OP01_WIFI__ */
};

/******************************************************************************/
/*                          Class AdvancedContentProvider                     */
/******************************************************************************/
class AdvancedContentProvider : public VfxObject,
                                public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    AdvancedContentProvider() :
        m_repository(NULL)
    {
        VFX_TRACE(("====Default Constructor - AdvancedContentProvider====\n"));
    }

    AdvancedContentProvider(const VappWlanRepository* repository) :
        m_repository(repository)
    {
        VFX_TRACE(("====Constructor - AdvancedContentProvider====\n"));
    }

   virtual ~AdvancedContentProvider() {}
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
    
    virtual void setMenu(VcpListMenu *menu);

    virtual VfxU32 getCount() const;

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
    
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        ) ;
    
    virtual VfxBool getItemIsHighlightable(
            VfxU32 index    // [IN] the index of item
            ) const ;
        
// #ifdef	__CBM_BEARER_SWITCH__
    virtual VcpListMenuCellBaseControl* getItemCustomControl(
        VfxU32 index,                                       // [IN] index of the item
        VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
        VfxFrame *parentFrame                            // [IN] parent frame of the custom content frame
        );

    void OnRPSwitch(VappWlanSettingSwitchButton *sw, VfxBool isChecked);
// #endif

// Variable
private:
    const VappWlanRepository            *m_repository;
    VcpListMenu                         *m_listMenu;

//  Enum
    enum ADVANCED_CONTENT_PROVIDER_ENUM
    {    
#ifdef __CBM_BEARER_SWITCH__ 
        ADVANCED_CONTENT_PROVIDER_NETWORK_NOTIFICATION,
#endif /* __CBM_BEARER_SWITCH__ */ 

        ADVANCED_CONTENT_PROVIDER_AUTO_CONNECTION, 
 
#ifdef __MMI_OP01_WIFI__ 
        ADVANCED_CONTENT_PROVIDER_CMCC_SETTING, 
        ADVANCED_CONTENT_PROVIDER_NON_PROXY,
        ADVANCED_CONTENT_PROVIDER_CERTMAN_LOAD,
        ADVANCED_CONTENT_PROVIDER_CERTMAN_UNLOAD,
        ADVANCED_CONTENT_PROVIDER_WLAN_TO_CELLULAR,
#endif /* __MMI_OP01_WIFI__ */

        ADVANCED_CONTENT_PROVIDER_SLEEP_POLICY,

        ADVANCED_CONTENT_PROVIDER_TOTAL
    }; 

    enum SETTING_SWITCHBUTTON_ENUM
    {
        SETTING_SWITCHBUTTON_AUTOCONN ,
        SETTING_SWITCHBUTTON_NETWORKNOTI
    };

// Implementation
};

/******************************************************************************/
/*                          Class VappSleepPolicySettingPage                  */
/******************************************************************************/
class VappSleepPolicySettingPage : public Observer
{
// Declaration
    // VFX_DECLARE_CLASS(VappSleepPolicySettingPage);

// Constructor / Destructor
public:
    VappSleepPolicySettingPage() 
    {}  
    virtual ~VappSleepPolicySettingPage(){}
    
// Method

// Overridable

// Override
public:
    virtual void onInit ();

// Variable
private:
    VcpTitleBar                         *m_titleBar;
    VcpListMenu                         *m_networksListMenu;  
    SleepPolicyContentProvider          *m_contentProvider;
    
// Enum

// Implementation
private:
    void onItemTapped(VcpListMenu *, VfxU32);   
};

/******************************************************************************/
/*                          Class SleepPolicyContentProvider                  */
/******************************************************************************/
class SleepPolicyContentProvider : public VfxObject,
                                public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    SleepPolicyContentProvider()
    {
        VFX_TRACE(("====Default Constructor - SleepPolicyContentProvider====\n"));
    }

    virtual ~SleepPolicyContentProvider() {}
    
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

    enum SLEEP_POLICY_ITEM_ENUM
    {
        SLEEP_POLICY_ITEM_NEVER, 
        SLEEP_POLICY_ITEM_NEVER_USB_PLUG_IN,
        SLEEP_POLICY_ITEM_SCREEN_TURN_OFF,
        SLEEP_POLICY_ITEM_TOTAL
    };
};

/******************************************************************************/
/*                          Class VappSelectPopupBuilder                      */
/******************************************************************************/
class VappSelectPopupBuilder : public VfxObject
{
// Declaration

// Constructor / Destructor
public:
    VappSelectPopupBuilder()
    {}
    VappSelectPopupBuilder(
        VAPP_WLAN_AP_PROPERTY_TYPE_ENUM,
        VappWlanProfile *,
        VfxMainScr *,
        VappPropertyPage *);
    virtual ~VappSelectPopupBuilder()
    {}

// Method

// Overridable

// Override

// Variable
private:
    VfxBool                             m_clickOk;
    VAPP_WLAN_AP_PROPERTY_TYPE_ENUM     m_propertyType;
    VappWlanProfile                     *m_newProfile;
    VcpSelectPopup                      *m_selectPopup;
    VfxMainScr                          *m_mainScr;
    VappPropertyPage                    *m_parentPage;
    
// Implementation    
public:
    void createSelectPopup();

private:
    void onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    void onPopupButtonClicked(VfxObject* obj, VfxId id);
};

/******************************************************************************/
/*                          Class VappTcpIpSettingPage                        */
/******************************************************************************/
class VappTcpIpSettingPage : public VfxPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappTcpIpSettingPage);

// Constructor / Destructor
public:
    VappTcpIpSettingPage()
    {}
    VappTcpIpSettingPage(VappWlanProfile* );
    virtual ~VappTcpIpSettingPage()
    {}

// Method

// Overridable

// Override
public:
    virtual void onInit ();

// Variable    
private:
    VappWlanProfile             *m_profile;
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpFormItemSwitchCell       *m_dhcpSwitchCell;
    VcpForm                     *m_form;
    VcpFormItemTextInput        *m_ipAddrText;
    VcpFormItemTextInput        *m_netmaskText;
    VcpFormItemTextInput        *m_gatewayText;
    VcpFormItemTextInput        *m_dns1Text;
    VcpFormItemTextInput        *m_dns2Text;
    VcpFunctionBar              *m_functionBar;
    VcpTextEditor               *m_prevEditor;
    VcpTextEditor               *m_nextEditor;
    VcpTextEditor               *m_curEditor;
    VfxId                       m_currActiveId;  
    VfxId                       m_focusItemId;

    VfxU8                       m_tempIpAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];
    VfxU8                       m_tempNetmaskAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];
    VfxU8                       m_tempGatewayAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];
    VfxU8                       m_tempDns1Addr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];
    VfxU8                       m_tempDns2Addr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];
    
    VfxWString                  m_ipAddrStr;
    VfxWString                  m_netmaskStr;
    VfxWString                  m_gatewayStr;
    VfxWString                  m_dns1Str;
    VfxWString                  m_dns2Str;
    
    enum TCP_IP_SETTING_TOOLBAR_ITEM_ENUM
    {
        TCP_IP_SETTING_TOOLBAR_SAVE, 
        TCP_IP_SETTING_TOOLBAR_CANCEL,
        TCP_IP_SETTING_TOOLBAR_TOTAL
    };

    enum TCP_IP_PAGE_FORM_ITEM_ENUM
    {
        TCP_IP_PAGE_FORM_BUTTON_USE_DHCP,
        TCP_IP_PAGE_FORM_TEXT_IP_ADDR,
        TCP_IP_PAGE_FORM_TEXT_NETMASK,
        TCP_IP_PAGE_FORM_TEXT_GATEWAY,
        TCP_IP_PAGE_FORM_TEXT_DNS1,
        TCP_IP_PAGE_FORM_TEXT_DNS2,
        TCP_IP_PAGE_FORM_FUNC_BAR_PREV,
        TCP_IP_PAGE_FORM_FUNC_BAR_NEXT,
        TCP_IP_PAGE_FORM_FUNC_BAR_SAVE,
        TCP_IP_PAGE_FORM_NETWORK_TOTAL
    };

// Implementation    
    void saveTcpIpSettings();
    VfxWString initItemValue(const VfxU8* addr);
    VfxU8 checkItemValue(VcpFormItemTextInput* item, VfxU8* ipAddr, VfxU8* checkRes);
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onFuncBarBtnClick (VfxObject *sender, VfxId id);
    void onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive);
    void onSwitchStatusChanged(VcpFormItemSwitchCell* sender, VfxId id, VfxBool status);
};

/******************************************************************************/
/*                          Class VappAdvancedSettingPage                     */
/******************************************************************************/
class VappAdvancedSettingPage : public VfxPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappAdvancedSettingPage);

// Constructor / Destructor
public:
    VappAdvancedSettingPage()
    {}
    VappAdvancedSettingPage(VappWlanProfile* );
    virtual ~VappAdvancedSettingPage()
    {}

// Method

// Overridable

// Override
public:
    virtual void onInit ();

// Variable    
private:
    VappWlanProfile             *m_profile;
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpForm                     *m_form;
    VcpFormItemTextInput        *m_homePageText;
    VcpFormItemCaption          *m_useProxyCaption;
    VcpFormItemSwitchCell       *m_switchCell;
    VcpFormItemTextInput        *m_proxyAddrText;
    VcpFormItemTextInput        *m_proxyPortText;
    VcpFormItemTextInput        *m_proxyUserNameText;
    VcpFormItemTextInput        *m_proxyPasswordText;
    VcpFunctionBar              *m_functionBar;
    VcpTextEditor               *m_prevEditor;
    VcpTextEditor               *m_nextEditor;
    VcpTextEditor               *m_curEditor;

    VfxU8                       m_tempProxyAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];
    VfxWString                  m_homepageStr;
    VfxWString                  m_proxyAddrStr;
    VfxWString                  m_proxyPortStr;
    VfxWString                  m_proxyUserNameStr;
    VfxWString                  m_proxyPasswordStr;
    VfxId                       m_currActiveId;  
    VfxId                       m_focusItemId;
    
    enum ADVANCED_SETTING_TOOLBAR_ITEM_ENUM
    {
        ADVANCED_SETTING_TOOLBAR_SAVE, 
        ADVANCED_SETTING_TOOLBAR_CANCEL,
        ADVANCED_SETTING_TOOLBAR_TOTAL
    };

    enum ADVANCED_PAGE_FORM_ITEM_ENUM
    {
        ADVANCED_PAGE_FORM_TEXT_HOMEPAGE,
        ADVANCED_PAGE_FORM_BUTTON_USE_PROXY,
        ADVANCED_PAGE_FORM_CAPTION_USE_PROXY,
        ADVANCED_PAGE_FORM_TEXT_PROXY_ADDR,
        ADVANCED_PAGE_FORM_TEXT_PROXY_PORT,
        ADVANCED_PAGE_FORM_TEXT_PROXY_USERNAME,
        ADVANCED_PAGE_FORM_TEXT_PROXY_PASSWORD,
        ADVANCED_PAGE_FORM_FUNC_BAR_PREV,
        ADVANCED_PAGE_FORM_FUNC_BAR_NEXT,
        ADVANCED_PAGE_FORM_FUNC_BAR_SAVE,
        ADVANCED_PAGE_FORM_NETWORK_TOTAL
    };
    
// Implement
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onSwitchStatusChanged (VcpFormItemSwitchCell* sender, VfxId id, VfxBool status);
    void onFuncBarBtnClick (VfxObject *sender, VfxId id);
    void onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive);
    VfxBool verifyItemValue();
    void saveItemValue(ADVANCED_PAGE_FORM_ITEM_ENUM , VcpFormItemTextInput* );
    void saveAdvancedSettings();
    void showInvalidPopup(const VfxWString &prompt);
};

/******************************************************************************/
/*                          Class VappPropertyPage                            */
/******************************************************************************/
class VappPropertyPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappPropertyPage);

// Constructor / Destructor
public:
    VappPropertyPage();
    VappPropertyPage(VappWlanProfile* profile, VappWlanRepository* repository);
    virtual ~VappPropertyPage()
    {}
    
// Method

// Overridable
public: 
    virtual void onItemTapped (VfxU32);
    virtual void onSegmentBtnClick (VfxObject *sender, VfxId id);
    virtual void onPropertyBtnClick (VfxObject *sender, VfxId id);
    virtual void onWepKeyBtnClick (VfxObject *sender, VfxId id);   
    
#ifndef WIFI_AUTH_PSK_ONLY
    virtual void onEAPTypesBtnClick (VfxObject *sender, VfxId id);
#endif /* WIFI_AUTH_PSK_ONLY */

#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    virtual void onWAICertBtnClicked (VfxObject *sender, VfxId id);
    virtual void onWAIPSKBtnClicked (VfxObject *sender, VfxId id);
#endif  //__WAPI_SUPPORT__
#endif  //__MMI_HIDE_WAPI__

    virtual VfxBool saveProfile ();
    virtual void setFunctionBarItems();

// Override
public:
    void showWarningPopup(const VfxWString& prompt);
        
// Variable
protected:
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpForm                     *m_form;
    VcpFunctionBar              *m_functionBar;
    VcpFormItemTextInput        *m_ssidTextInput;
    VfxFrame                    *m_networkTypeFrame;
    VcpFormItemCustomFrame      *m_customFrame;
    VcpSegmentButton            *m_networkTypeBtn;
    VcpFormItemBigButton        *m_securityModeBtn;
    VcpFormItemBigButton        *m_encryptionModeBtn;
    VcpFormItemBigArrowButton   *m_eapTypesBtn;
    VcpFormItemBigArrowButton   *m_wepSettingsBtn;
    VcpFormItemBigArrowButton   *m_waiCertBtn;
    VcpFormItemBigArrowButton   *m_waiPskBtn;
    VcpFormItemTextInput        *m_passwordText;
    VcpTextEditor               *m_prevEditor;
    VcpTextEditor               *m_nextEditor;
    VcpTextEditor               *m_curEditor;
    VfxId                       m_currActiveId;  
    VfxId                       m_focusItemId;
    
    VfxWString                  m_ssidStr;
    VfxWString                  m_preSharedKeyStr;
    VappWlanProfile             *m_tempProfile;
    VAPP_WLAN_AP_PROPERTY_TYPE_ENUM m_propertyTypeEnum;
    supc_abm_eap_type_enum      m_eapTypeArray[EAP_TYPE_MAIN_PAGE_ITEM_COUNT];
    VappWlanRepository          *m_repository;


    enum SEGMENT_BTN_ID_ENUM
    {
        SEGMENT_BTN_ID_INFRASTRUCTURE,
        SEGMENT_BTN_ID_ADHOC,
        SEGMENT_BTN_ID_TOTAL
    };

    enum PROPERTY_PAGE_FORM_ITEM_ENUM
    {
        PROPERTY_PAGE_FORM_NETWORK_NAME,
        PROPERTY_PAGE_FORM_NETWORK_SSID,
        PROPERTY_PAGE_FORM_CAPTION_BASIC,
        PROPERTY_PAGE_FORM_NETWORK_TYPE,
        PROPERTY_PAGE_FORM_SECURITY_MODE,
        PROPERTY_PAGE_FORM_ENCRYPT_MODE,
        PROPERTY_PAGE_FORM_CAPTION_OTHERS,
        PROPERTY_PAGE_FORM_TCPIP_SETTINGS,
        PROPERTY_PAGE_FORM_ADVANCE_SETTINGS,
        PROPERTY_PAGE_FORM_BUTTON_JOIN,
        PROPERTY_PAGE_FORM_BUTTON_EAP_TYPES,
        PROPERTY_PAGE_FORM_BUTTON_WEP_KEY,
        PROPERTY_PAGE_FORM_TEXT_PASSWORD,
        PROPERTY_PAGE_FORM_BUTTON_WAI_CERT,
        PROPERTY_PAGE_FORM_BUTTON_WAI_PSK,
        PROPERTY_PAGE_FORM_FUNC_BAR_PREV,
        PROPERTY_PAGE_FORM_FUNC_BAR_NEXT,
        PROPERTY_PAGE_FORM_FUNC_BAR_SAVE,
        PROPERTY_PAGE_TOOLBAR_SAVE,
        PROPERTY_PAGE_TOOLBAR_CANCEL,
        PROPERTY_PAGE_FORM_NETWORK_TOTAL
    };

};

/******************************************************************************/
/*                          Class VappJoinNetworkPage                         */
/******************************************************************************/
class VappJoinNetworkPage : public VappPropertyPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappJoinNetworkPage);

// Constructor / Destructor
public:
    VappJoinNetworkPage()
    {
        m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        // Register messages which are interested
        m_repository->registerObserver (this);
        VFX_TRACE(("VappJoinNetworkPage - default constructor\n"));
    }

    VappJoinNetworkPage(VappWlanRepository*, Observer*);

    virtual ~VappJoinNetworkPage() ;
    
// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onEnter(VfxBool isBackward);
    virtual void UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);
    virtual void onItemTapped (VfxU32);
    virtual void onSegmentBtnClick (
            VfxObject *sender, 
            VfxId id);

// Variable
private:
    Observer        *m_parentPage;
    
// Implementation
public:
    void saveApName();
    void createFunctionBar();
    void arrangeSecuritySettings(
                        srv_dtcnt_wlan_auth_mode_enum curAuthMode,
                        srv_dtcnt_wlan_auth_mode_enum preAuthMode);
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onFuncBarBtnClick (VfxObject *sender, VfxId id);
    void onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive);   
    void showAddNewNetworkBallon();    
    void updateToolBar();
};

/******************************************************************************/
/*                          Class VappEditProfilePage                         */
/******************************************************************************/
class VappEditProfilePage : public VappPropertyPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappEditProfilePage);

// Constructor / Destructor
public:
    VappEditProfilePage();
    VappEditProfilePage(VappWlanProfile*, VappWlanRepository*);
    virtual ~VappEditProfilePage();
    
// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onEnter(VfxBool isBackward);
    virtual void UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);
    
    virtual void setFunctionBarItems();
    virtual void onItemTapped (VfxU32);
    virtual void onSegmentBtnClick (
            VfxObject *sender, 
            VfxId id);
    
// Variable
private:
    VcpFormItemTextInput        *m_nameTextInput;    
    VcpFormItemBigArrowButton   *m_tcpipSettingsBtn;
    VcpFormItemBigArrowButton   *m_advancedSettingsBtn;
    VcpFormItemCaption          *m_basicSettings;
    VcpFormItemCaption          *m_otherSettings;
    VappWlanProfile             *m_editProfile;
    // VappNetworkMgrPage          *m_parentPage;
    VfxWString                  m_nameStr;
    VfxId                       m_currActiveId;  
    
// Implementation
    // void onWepKeyBtnClick (VfxObject *sender, VfxId id);
    void saveEditProfile();
    void onFuncBarBtnClick (VfxObject *sender, VfxId id);
    void onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive);
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onTcpIpSettingBtnClick (VfxObject *sender, VfxU32 id);
    void onAdvancedSettingBtnClick (VfxObject *sender, VfxU32 id);
    void createFunctionBar();
    void arrangeSecuritySettings(
                        srv_dtcnt_wlan_auth_mode_enum curAuthMode,
                        srv_dtcnt_wlan_auth_mode_enum preAuthMode);
    void initPropertyStr();    
    void updateToolBar();
};

/******************************************************************************/
/*                          Class VappWepKeySettingPage                       */
/******************************************************************************/
class VappWepKeySettingPage : public VappPropertyPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappWepKeySettingPage);

// Constructor / Destructor
public:
    VappWepKeySettingPage()
    {}
    VappWepKeySettingPage(VappWlanProfile*, VappWlanRepository* );
    virtual ~VappWepKeySettingPage()
    {}

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onItemTapped (VfxU32 index);
    virtual void onPropertyBtnClick (VfxObject *sender, VfxId id);

// Variable
private:
    VcpToolBar                  *m_toolBar;
    VcpFormItemBigButton        *m_wepKeyIndexBtn;
    VcpFormItemBigButton        *m_wepKeyEncryptBtn;
    VcpFormItemBigButton        *m_wepKeyFormatBtn;
    VcpFormItemTextInput        *m_wepKeyText;
    
    VfxWString                  m_wepKeyStr;
    VappWlanProfile             *m_wepTempProfile;
    
    
    enum WEP_KEY_SETTING_TOOLBAR_ITEM_ENUM
    {
        WEP_KEY_SETTING_TOOLBAR_OK, 
        WEP_KEY_SETTING_TOOLBAR_CANCEL,
        WEP_KEY_SETTING_TOOLBAR_TOTAL
    };

    enum WEP_KEY_PAGE_FORM_ITEM_ENUM
    {
        WEP_KEY_PAGE_FORM_BUTTON_INDEX,
        WEP_KEY_PAGE_FORM_BUTTON_ENCRYPT,
        WEP_KEY_PAGE_FORM_BUTTON_FORMAT,
        WEP_KEY_PAGE_FORM_TEXT_STRING,
        WEP_KEY_PAGE_FORM_NETWORK_TOTAL
    };

// Implementation    
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onFuncBarBtnClick (VfxObject* sender, VfxId id);
    void adjustWepKeyEditor(VfxBool isInit);
    void saveWepKeySettings();
};

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
/******************************************************************************/
/*                          Class VappWaiCertSettings                         */
/******************************************************************************/
class VappWaiCertSettingsPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappWaiCertSettingsPage);

// Constructor / Destructor
public:
    VappWaiCertSettingsPage()
    {
    	// register page in the respository
        m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        m_repository->registerObserver (this);
        VFX_TRACE(("====Default constructor - VappWaiCertSettingsPage====\n"));
    }

    VappWaiCertSettingsPage(VappWlanProfile *profile);
    
    virtual ~VappWaiCertSettingsPage();

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);
    
// Variable
private:
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpFormItemBigArrowButton   *m_waiAseCert;
    VcpFormItemBigArrowButton   *m_waiUserCert;
    VcpFormItemTextInput        *m_waiPrivateKeyText;
    VcpFunctionBar              *m_functionBar;
    VcpForm                     *m_form;
    VappWlanProfile             *m_profile;
    VappWlanRepository          *m_repository;
    
    VfxU32                      m_tempWapiAseId;
    VfxU32                      m_tempWapiClientId;
    VfxWString                  m_tempAseCertName;
    VfxWString                  m_tempClientCertName;
    VfxWString                  m_waiPrivateKeyStr;

    enum WAI_CERT_TOOLBAR_ITEM_ENUM
    {
        WAI_CERT_TOOLBAR_OK, 
        WAI_CERT_TOOLBAR_CANCEL,
        WAI_CERT_TOOLBAR_TOTAL
    };

    enum WAI_CERT_PAGE_FORM_ITEM_ENUM
    {
        WAI_CERT_PAGE_FORM_BUTTON_ASE_CERT,
        WAI_CERT_PAGE_FORM_BUTTON_USER_CERT,
        WAI_CERT_PAGE_FORM_TEXT_PRIVATE_KEY,
        WAI_CERT_PAGE_FORM_FUNC_BAR_OK,
        WAI_CERT_PAGE_FORM_NETWORK_TOTAL
    };

// Implementation
    void saveWaiCertSettings();
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onFuncBarBtnClick (VfxObject *sender, VfxId id);
    void onPropertyBtnClick (VfxObject *sender, VfxId id);
};

/******************************************************************************/
/*                          Class VappWaiPskSettingsPage                      */
/******************************************************************************/
class VappWaiPskSettingsPage : public VappPropertyPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappWaiPskSettingsPage);

// Constructor / Destructor
public:
    VappWaiPskSettingsPage()
    {
        VFX_TRACE(("====Default constructor - VappWaiPskSettingsPage====\n"));
    }

    VappWaiPskSettingsPage(VappWlanProfile* profile, VappWlanRepository* repository);
    
    virtual ~VappWaiPskSettingsPage()
    {
        VFX_TRACE(("====Deconstructor - VappWaiPskSettingsPage====\n"));
    }

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onBack();
    virtual void onItemTapped (VfxU32 index);
    virtual void onPropertyBtnClick (VfxObject *sender, VfxId id);
    
// Variable
private:
    VcpToolBar                  *m_toolBar;
    VcpFormItemBigButton        *m_waiPskFormat;
    VcpFormItemTextInput        *m_waiPskText;
    VfxWString                  m_waiPskStr;
    VfxS32                      m_orignalFormat;

    enum WAI_PSK_TOOLBAR_ITEM_ENUM
    {
        WAI_PSK_TOOLBAR_OK, 
        WAI_PSK_TOOLBAR_CANCEL,
        WAI_PSK_TOOLBAR_TOTAL
    };

    enum WAI_PSK_PAGE_FORM_ITEM_ENUM
    {
        WAI_PSK_PAGE_FORM_BUTTON_PSK_FORMAT,
        WAI_PSK_PAGE_FORM_TEXT_PSK,
        WAI_PSK_PAGE_FORM_FUNC_BAR_OK,
        WAI_PSK_PAGE_FORM_NETWORK_TOTAL
    };

// Implementation
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onFuncBarBtnClick (VfxObject *sender, VfxId id);
    VfxBool saveWaiPskSettings();
};
#endif /* __WAPI_SUPPORT__ */
#endif /* __WAPI_SUPPORT__ */


/******************************************************************************/
/*                          Class ChangePriorityContentProvider               */
/******************************************************************************/
class ChangePriorityContentProvider : public VfxObject,
                                      public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    ChangePriorityContentProvider() :
        m_repository(NULL)
    {
        VFX_TRACE(("====Default Constructor - ChangePriorityContentProvider====\n"));
    }
    
    ChangePriorityContentProvider(const VappWlanRepository *repository, VappChangePriorityPage* parentPage) :
        m_repository(repository), m_parentPage(parentPage)
    {
        VFX_TRACE(("====Constructor - ChangePriorityContentProvider====\n"));
    }

    virtual ~ChangePriorityContentProvider() {}

// Method

// Overridable

// Override
protected:
    virtual VfxU32 getCount() const;
    
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

#if !defined(__VRE_SDK__)
    // <group DOM_ListMenu_IVcpListMenuContentProvider_Overridable>
    // Swap two items, user should update its internal data of the two items
    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        ) ;
#endif


// Variable
private:
    const VappWlanRepository        *m_repository;
    VappChangePriorityPage          *m_parentPage;
    
// Implementation
};

class VappChangePriorityPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappChangePriorityPage);

// Constructor / Destructor
public:
    VappChangePriorityPage() :
        m_repository(NULL)
    {
        m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        // Register messages which are interested
        m_repository->registerObserver (this);
    }
        
    VappChangePriorityPage(VappWlanRepository *repository, Observer* page);

    virtual ~VappChangePriorityPage();

// Method
public:
    VappWlanBaseInfo** getTempSavedApList()
    {
        return m_tempSavedApList;
    }

    VfxBool getIsModified()
    {
        return m_isModified;
    }

    void setIsModified(VfxBool isModified)
    {
        m_isModified = isModified;
    }
    
// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onEnter(VfxBool isBackward) ; 
    virtual void UpdatePage(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);

// Variable
private:
    VfxBool                 m_isModified;
    VcpTitleBar             *m_titleBar;
    VcpListMenu             *m_priorityListMenu; 
    VcpToolBar              *m_toolBar;
    VcpFormItemCaption      *m_caption;
    ChangePriorityContentProvider   *m_contentProvider;
    VappWlanRepository              *m_repository;
    VappWlanBaseInfo             *m_tempSavedApList[WLAN_SAVED_AP_LIST_NUM_MAX];
    VfxU8                            m_priorityList[WLAN_SAVED_AP_LIST_NUM_MAX];
    Observer                        *m_parentPage;
    
// Enum
    enum ScrItemIdEnum
    {
        TOOLBAR_OK,
        TOOLBAR_CANCEL,
        TOTAL_ITEMS
    };

// Implementation
    void onToolBarClick (VfxObject *sender, VfxId id);
    void updateApListPriority();
    void updateApListMenu();   
    void updateToolBar(); 
};

class NetWorkMgrContentProvider : public VfxObject,
                                  public IVcpListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    NetWorkMgrContentProvider() :
        m_repository(NULL)
    {
        VFX_TRACE(("====Default Constructor - NetWorkMgrContentProvider====\n"));
    }

    NetWorkMgrContentProvider(const VappWlanRepository* repository, const VcpListMenuItemStateEnum* itemStateArray) :
        m_repository(repository), m_itemStateArray(itemStateArray)
    {
        VFX_TRACE(("====Constructor - NetWorkMgrContentProvider====\n"));
    }

    virtual ~NetWorkMgrContentProvider() {}
// Method

// Overridable

// Override
public:
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

class VappNetworkMgrPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappNetworkMgrPage);

// Constructor / Destructor
public:
    VappNetworkMgrPage() :
        m_isSelectAll(VFX_FALSE),
        m_repository(NULL)
    {
        m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
	    // register page in the respository
	    m_repository->registerObserver (this);
    }  
        
    VappNetworkMgrPage(VappWlanRepository *repository);
    virtual ~VappNetworkMgrPage();
    
// Method
public:
    VcpListMenu* getNetworksListMenu()
    {
        return m_networksListMenu;
    }

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
    NetWorkMgrContentProvider           *m_contentProvider;
    VappWlanRepository                  *m_repository;
    VcpListMenuItemStateEnum            m_itemStateArray[WLAN_AP_LIST_NUM_MAX];
    VcpConfirmPopup                     *m_confirmPopup;
    VfxWeakPtr<VcpConfirmPopup>         m_popupWeakPtr;    
// Enum
    enum ScrItemIdEnum
    {
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
    void onConfirmBtnClick(VfxObject * obj, VfxId id);
    void goToDeleteApList();
    void returnMgrScreen();
    void initStatusArray();
    void initToolbar();
    void setToolbarDeleteStatus();
    void setToolbarMarkAllStatus();
};

class VappPasswordConfigPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappPasswordConfigPage);

// Constructor / Destructor
public:
    VappPasswordConfigPage() :
        m_hiltProfile(NULL)
    {}
        
    VappPasswordConfigPage(VappWlanProfile *profile);
    
    virtual ~VappPasswordConfigPage();

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onBack ();
    
// Variable
private:
    VfxWString                  m_password;
    VappWlanProfile             *m_hiltProfile;
    VcpFunctionBar              *m_functionBar;
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpFormItemTextInput        *m_passwordTextInput;

    enum PWD_CFG_FORM_ITEM_ENUM
    {
        PWD_CFG_FORM_PASSWORD,
        PWD_CFG_FORM_TOOLBAR_JOIN,
        PWD_CFG_FORM_TOOLBAR_CANCEL,
        PWD_CFG_FORM_FUNC_BAR_JOIN,
        PWD_CFG_FORM_TOTAL
    };

    enum CONNECT_AP_TYPE_ENUM
    {
        CONNECT_AP_WPA,
        CONNECT_AP_WEP_KEY,
        CONNECT_AP_TOTAL
    };
// Implementation
private:
    void onFuncBarBtnClick (VfxObject* sender, VfxId id);
    void onToolBarClick (VfxObject *sender, VfxId id);
    VfxBool verifyPasswordInput(CONNECT_AP_TYPE_ENUM apType);
    void connectToSecurityAp();
    void showInvalidKeyPopup();
};

#ifndef  WIFI_AUTH_PSK_ONLY
class VappDefaultConfigPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappDefaultConfigPage);

// Constructor / Destructor
public:
    VappDefaultConfigPage();
    
    VappDefaultConfigPage(VappWlanProfile *profile);    

    virtual ~VappDefaultConfigPage();

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onBack ();
    
// Variable
private:
    VappWlanProfile             *m_hiltProfile;
    VcpTextEditor               *m_prevEditor;
    VcpTextEditor               *m_nextEditor;
    VcpTextEditor               *m_curEditor;
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpFormItemTextInput        *m_userNameTextInput;
    VcpFormItemTextInput        *m_passwordTextInput;
    VcpFunctionBar              *m_functionBar;
    VcpForm                     *m_form;
    VfxWString                  m_userName;
    VfxWString                  m_password;

    enum DEFAULT_CFG_FORM_ITEM_ENUM
    {
        DEFAULT_CFG_FORM_USERNAME,
        DEFAULT_CFG_FORM_PASSWORD,
        DEFAULT_CFG_FORM_TOOLBAR_JOIN,
        DEFAULT_CFG_FORM_TOOLBAR_CANCEL,
        DEFAULT_CFG_FORM_FUNC_BAR_PREV,
        DEFAULT_CFG_FORM_FUNC_BAR_NEXT,
        DEFAULT_CFG_FORM_FUNC_BAR_JOIN,
        DEFAULT_CFG_FORM_TOTAL
    };
// Implementation
    void onFuncBarBtnClick (VfxObject* sender, VfxId id);
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive);
    void connectToSecurityAp();
};
#endif /* WIFI_AUTH_PSK_ONLY */

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
class VappWAIPSKConfigPage : public VappPropertyPage
{
// Declaration
//    VFX_DECLARE_CLASS(VappWAIPSKConfigPage);

// Constructor / Destructor
public:
    VappWAIPSKConfigPage();

    VappWAIPSKConfigPage(VappWlanProfile *profile);
    
    virtual ~VappWAIPSKConfigPage();

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onBack ();
    virtual void onItemTapped (VfxU32 index);
    virtual void onPropertyBtnClick (VfxObject *sender, VfxId id);   
    
// Variable
private:
    VfxWString                  m_waiPskStr;
    VappWlanProfile             *m_hiltProfile;
    VappWlanProfile             *m_tempProfile;
    VcpForm                     *m_form;
    VcpTitleBar                 *m_titleBar;
    VcpFormItemBigButton        *m_waiPskFormat;
    VcpFormItemTextInput        *m_waiPskTextInput;

    enum WAI_PSK_CFG_FORM_ITEM_ENUM
    {
        WAI_PSK_CFG_FORM_FORMAT,
        WAI_PSK_CFG_FORM_STRING,
        WAI_PSK_CFG_FORM_TOOLBAR_JOIN,
        WAI_PSK_CFG_FORM_TOOLBAR_CANCEL,
        WAI_PSK_CFG_FORM_FUNC_BAR_JOIN,
        WAI_PSK_CFG_FORM_TOTAL
    };
// Implementation
    void onFuncBarBtnClick (VfxObject* sender, VfxId id);
    void onToolBarClick (VfxObject *sender, VfxId id);
    void connectToSecurityAp();
};

class VappWAICertConfigPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappWAICertConfigPage);

// Constructor / Destructor
public:
    VappWAICertConfigPage();
    
    VappWAICertConfigPage(VappWlanProfile *profile);
    
    virtual ~VappWAICertConfigPage();

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onBack ();
    virtual void UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);
    
// Variable
private:
    VappWlanProfile             *m_hiltProfile;
    VappWlanRepository          *m_repository;
    VfxU32                      m_tempWapiAseId;
    VfxU32                      m_tempWapiClientId;
    VfxWString                  m_waiPrivateKey;
    VcpTitleBar                 *m_titleBar;
    VcpToolBar                  *m_toolBar;
    VcpFormItemBigArrowButton   *m_waiASECertSelector;
    VcpFormItemBigArrowButton   *m_waiUserCertSelector;
    VcpFormItemTextInput        *m_waiPrivateKeyTextInput;
    VcpFunctionBar              *m_functionBar;
    VcpForm                     *m_form;
    
    enum WAI_CERT_CFG_FORM_ITEM_ENUM
    {
        WAI_CERT_CFG_FORM_ASE,
        WAI_CERT_CFG_FORM_USER,
        WAI_CERT_CFG_FORM_PRIVATE_KEY,
        WAI_CERT_CFG_FORM_TOOLBAR_JOIN,
        WAI_CERT_CFG_FORM_TOOLBAR_CANCEL,
        WAI_CERT_CFG_FORM_FUNC_BAR_JOIN,
        WAI_CERT_CFG_FORM_TOTAL
    };
// Implementation
    void onToolBarClick (VfxObject *sender, VfxId id);
    void onFuncBarBtnClick (VfxObject* sender, VfxId id);
    void onPropertyBtnClick (VfxObject *sender, VfxId id);
    void connectToSecurityAp();
};
#endif /*__WAPI_SUPPORT__*/
#endif /*__MMI_HIDE_WAPI__*/

//W1203_UI_PERFORMANCE_BEGIN
class WifiSettingContentProvider : public VfxObject,
                              public IVcpGroupListMenuContentProvider
{
// Declaration
    
// Constructor / Destructor
public:
    WifiSettingContentProvider()
    {
        VFX_TRACE(("====Default Constructor - WifiSettingContentProvider====\n"));
    }
    WifiSettingContentProvider(const VappWlanRepository* s, VappWifiSettingsPage* parentPage) :
            m_repository(s), m_parentPage(parentPage)
    {
        VFX_TRACE(("====Constructor - WifiSettingContentProvider====\n"));
    }
    virtual ~WifiSettingContentProvider() {}

// Method

// Overridable

// Override
public:
    // Set the list menu pointer to content provider
    virtual void setMenu(VcpGroupListMenu *menu);

    // Get the group count of the group list menu
    virtual VfxU32 getGroupCount() const;

    // Get the item count of specified group
    virtual VfxU32 getCount(VfxU32 group) const;

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should create and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VcpMenuPos pos,         // [IN] position of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        );

    virtual VfxBool getItemText(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    
    virtual VfxBool getItemTextFrameFormat(
        VcpMenuPos pos,                 // [IN] the position of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxTextFrame *frame             // [OUT] the text frame
        );

    virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

    // Get if the specified group header is valid
    virtual VfxBool hasGroupHeader(VfxS32 group) const;

    virtual VfxBool getItemIsHighlightable(
        VcpMenuPos pos  // [IN] position of the item
        ) const ;

// Enum
private:
    enum SETTING_SCREEN_GROUP
    {
        SETTING_SCREEN_GROUP_ONE,
        SETTING_SCREEN_GROUP_TWO,
        SETTING_SCREEN_GROUP_THREE,
        SETTING_SCREEN_GROUP_TOTAL
    };
    
// Variable
private:
    const VappWlanRepository    *m_repository;
    VcpGroupListMenu            *m_groupListMenu;
    VappWifiSettingsPage        *m_parentPage;
// Implementation 

};
//W1203_UI_PERFORMANCE_END

class VappWifiSettingsPage : public Observer
{
// Declaration
//    VFX_DECLARE_CLASS(VappWifiSettingsPage);

// Constructor / Destructor
public:
    VappWifiSettingsPage() : 
        m_repository(NULL), m_isBackward(VFX_FALSE)
    {
        // register page in the respository
        m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
        m_repository->registerObserver (this);
    }

    VappWifiSettingsPage(VappWlanRepository *repository);
    virtual ~VappWifiSettingsPage();
    
// Method

// Overridable
    
// Override
protected:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);
    virtual void showConnectingPopup(VappWlanProfile* hiltAp);
    
// Variable
private:
    VcpTitleBar                *m_titleBar;
    VcpToolBar                 *m_toolBar;//wlan prefer
    VcpGroupListMenu           *m_settingGroupListMenu;
    WifiSettingContentProvider *m_contentProvider;
    VcpIndicatorPopup          *m_discWaitingPopup;
    VappProfileInfoPopup       *m_disconnecConfirm;
    VcpIndicatorPopup          *m_waitingPopup;
    VappWlanTimeLeftPopup      *m_timeLeftPopup;  
    VappWlanRepository         *m_repository;
    VappWlanProfile            *m_hiltProfile;
#ifdef __WPS_SUPPORT__    
    VfxTimer                   *m_connDurationTimer;
#endif
    VfxBool                     m_isBackward;
    VfxWeakPtr<VappProfileInfoPopup> m_disconnWeakPtr;
    VfxWeakPtr<VappWlanTimeLeftPopup> m_timerWeakPtr;
    VfxWeakPtr<VcpIndicatorPopup> m_discWaitingWeakPtr;
    VfxWeakPtr<VcpConfirmPopup> m_unableConnWeakPtr;  
    VfxWeakPtr<VcpIndicatorPopup> m_wpsWaitingWeakPtr;  
    
    /* index of item in menu list */
    VfxU32  m_menuListIndex;

// Enum
    enum SETTING_TOOLBAR_ENUM
    {
        SETTING_TOOLBAR_ADDNETWORK,
        SETTING_TOOLBAR_NETWORKMGR,  
        SETTING_TOOLBAR_REFRESH,
        SETTING_TOOLBAR_ADVANCED
    };

// Implementation
public:
// Logical
    void entryNetworkManageProc();
    void entryAddNewNetworkProc();
    void entryRefreshProc();
    void entryConnectProc();
    void entrySelectConnectTypeProc();
    void entryDisconnectProc();
    void entryWLANApDetail();     
    void entryAdvancedProc();
#ifdef __WPS_SUPPORT__
    void entryConfigConnectProc();
    void entryWPSConnectProc();
#endif
#ifdef __MMI_OP01_WIFI__      
    void entryCMCCConnectProc();   
    void entryCMCCDisconnectProc();   
    VfxBool VerifyNetWorkStatus();
#endif

    void connectToUnsavedAp(VappWlanProfile* );
    void onJoinNetwork(VfxBool isJoin, VappWlanProfile* network);
    void updateApListMenu();
    void showDisconnectingPopup();

    //W1203_UI_PERFORMANCE_BEGIN   
    void updateToolBar () ; 
    void page2ndEnter();
    //W1203_UI_PERFORMANCE_END

#ifdef __WPS_SUPPORT__
    void updateTimerLeftPopup(VAPP_WLAN_WPS_CONN_TYPE connType, VfxU32 leftTime, VfxU32 pinCode);
    void showTimeLeftPopup(VAPP_WLAN_WPS_CONN_TYPE connType, VfxU32 leftTime, VfxU32 pinCode);
    void showCancelWPSConnPopup();
    void closeTimeLeftPopup();   
    void showWPSWatingPopup();
#endif

private:        
// Handler
    void onItemTapped (VcpGroupListMenu *sender, VcpMenuPos pos);
    void onConfirmBtnClick (VfxObject *sender, VfxId id);
    void onToolBarClick (VfxObject *sender, VfxId id);
#ifdef __WPS_SUPPORT__
    void onTimerTick(VfxTimer* durationTimer);
    void onCancelWPSConnect (VfxObject *sender, VfxId id);
    void onHomeKeyClicked (VfxU8 status);
    void onConnTypeItemTapped (VcpMenuPopup* sender, VcpMenuPopupEventEnum evt, VcpMenuPopupItem* ap);
#endif

    VfxU32 getMenuListIndex() const;
    void setMenuListIndex(VfxU32 index);
    VappWlanBaseInfo* getCurrentSelectedAP();
};

//W1203_UI_PERFORMANCE_BEGIN
class VappWlanMainScrn : public VfxMainScr
{
// Declaration
//    VFX_DECLARE_CLASS(VappWlanMainScrn);

// Constructor / Destructor
public:
    VappWlanMainScrn() : 
        m_isOn2ndReady(VFX_FALSE),
        m_pageWeakPtr(NULL)
    { 
        setAppContextShareForVrt(VFX_TRUE);
    }

// Method

// Overridable

// Override
public:
    virtual void on1stReady ();   
    virtual void on2ndReady ();  //for WLAN APP to Page switch performance
    
// Variable
private:
    VfxBool m_isOn2ndReady;  //for WLAN APP to Page switch performance
    VfxWeakPtr<VappWifiSettingsPage> m_pageWeakPtr;
  
// Implementation
public:
    VfxBool getIsOn2ndReady();  //for WLAN APP to Page switch performance
};
//W1203_UI_PERFORMANCE_END


#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
/***************************************************************************** 
 * Class VappWlanSelectScrn
 *****************************************************************************/
class VappWlanSelectScrn : public VfxMainScr
{
// Declaration
//    VFX_DECLARE_CLASS(VappWlanSelectScrn);

// Constructor / Destructor
public:
    VappWlanSelectScrn() 
    {
        setIsSmallScreen ();
    }

// Method      
// Overridable
// Override
public:
    virtual void on1stReady(); 
    
// Implementation
private:
    void showConfirmPopupInFlightMode();
    void onButtonClick(VfxObject* sender, VfxU32 id);
};
#endif

/***************************************************************************** 
 * Class VappWlanEntryScrn
 *****************************************************************************/
class VappWlanEntryScrn : public VfxMainScr
{
// Declaration
//    VFX_DECLARE_CLASS(VappWlanEntryScrn);

// Constructor / Destructor
public:
    VappWlanEntryScrn() : 
        m_turnOffConfirm(NULL),
        m_waitingPopup(NULL)
    {
        setIsSmallScreen ();
    }
    
// Method
    static void afterStopTethering(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data);
    
// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    virtual void on1stReady();
    
private:
    VcpConfirmPopup             *m_turnOffConfirm;
    VcpIndicatorPopup           *m_waitingPopup;
    

// Implementation
private:
    void onConfirmBtnClicked(VfxObject* sender, VfxId id);
    void informWlanApp(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data);
};


/***************************************************************************** 
 * Class VappDtcntWlan
 *****************************************************************************/
/*
 * VappDtcntWlan is a class used to launch wlan wizard
 */
class VappDtcntWlan : public VfxApp
{
// Declaration
    VFX_DECLARE_CLASS(VappDtcntWlan);

// Constructor / Destructor
    VappDtcntWlan() : 
    m_mainScrn(NULL), m_mainScrnWeakPtr(NULL)
    {}
    
// Method

// Overridable

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRun(void* arg, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);

// Variable
public:
    VappWlanEntryScrn   *m_entryScrn;
    VappWlanMainScrn    *m_mainScrn;
    VfxWeakPtr<VappWlanMainScrn>  m_mainScrnWeakPtr;

    mmi_id              m_entryScrnId;
    mmi_id              m_mainScrnId;
   
#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
    VappWlanSelectScrn  *m_selectScrn;
    mmi_id              m_selectScrnId;
#endif

// Implementation
public:
    void onTryToStopTethering(VfxBool isStop);
    VappWlanMainScrn* getWlanMainScr();
    
#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
    void onTryToOpenWLANInFlightMode(VfxBool isSuccess);
#endif
};

#endif /* __VAPP_DTCNT_WLAN_UI_H__ */

