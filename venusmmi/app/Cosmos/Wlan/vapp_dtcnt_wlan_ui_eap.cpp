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
 *  vapp_dtcnt_wlan_ui_eap.cpp
 *
 * Project:
 * --------
 *  Cosmos
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

#ifndef  WIFI_AUTH_PSK_ONLY
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
 * Class VappWlanEAPTypesPage
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWlanEAPTypesPage", VappWlanEAPTypesPage, VfxPage);
VappWlanEAPTypesPage::VappWlanEAPTypesPage(
        VfxU32 itemCount, 
        VAPP_WLAN_EAP_TYPE_PAGE_ENUM pageEnum, 
        supc_abm_eap_type_enum* eapTypeArray, 
        VappWlanProfile* profile) :
                m_itemCount(itemCount),                
                m_eapTypeArray(eapTypeArray), 
                m_eapTypePageEnum(pageEnum),
                m_profile(profile) 
{
    m_eapPeapTypeArray[0] = WLAN_EAP_TLS;
    m_eapPeapTypeArray[1] = WLAN_EAP_MSCHAV2;
    m_eapPeapTypeArray[2] = WLAN_EAP_GTC;
    m_eapPeapTypeArray[3] = WLAN_EAP_MD5;

    m_eapTtlsTypeArray[0] = WLAN_EAP_TLS;
    m_eapTtlsTypeArray[1] = WLAN_EAP_MSCHAV2;
    m_eapTtlsTypeArray[2] = WLAN_EAP_GTC;
    m_eapTtlsTypeArray[3] = WLAN_EAP_MD5;    
    m_eapTtlsTypeArray[4] = WLAN_MSCHAPV2;
    m_eapTtlsTypeArray[5] = WLAN_PAP;    
    m_eapTtlsTypeArray[6] = WLAN_EAP_SIM;
    m_eapTtlsTypeArray[7] = WLAN_EAP_AKA;
}

void VappWlanEAPTypesPage::onInit ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_INIT_EAP_TYPES_PAGE);
    VfxPage::onInit ();

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPES));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (EAP_TYPES_SETTING_TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (EAP_TYPES_SETTING_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWlanEAPTypesPage::onToolBarClick);
    setBottomBar(m_toolBar);

    // Networks list menu
    VFX_OBJ_CREATE (m_eapTypeListMenu, VcpListMenu, this);
    VFX_OBJ_CREATE_EX (m_eapTypeContentProvider, VappWlanEAPTypesContentProvider, this, (m_itemCount, m_eapTypePageEnum, m_eapTypeArray, m_profile));
    m_eapTypeListMenu->setBgColor (VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_eapTypeListMenu->setCellStyle (VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX2);
    m_eapTypeListMenu->setMenuMode (VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
    m_eapTypeListMenu->setMenuControlMode (VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);
    m_eapTypeListMenu->setContentProvider (m_eapTypeContentProvider);
    m_eapTypeListMenu->setPos(0, 0);
    m_eapTypeListMenu->setSize(getSize());
    m_eapTypeListMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_eapTypeListMenu->m_signalCmdButtonClicked.connect (
        this, &VappWlanEAPTypesPage::onCmdButtonClicked);
    m_eapTypeListMenu->m_signalItemSelectionStateChanged.connect (
        this, &VappWlanEAPTypesPage::onSelectStateChanged);

    initEapTypesStatusArray();
}

void VappWlanEAPTypesPage::onDeinit ()
{
    VFX_OBJ_CLOSE (m_titleBar);
    VFX_OBJ_CLOSE (m_toolBar);
    VFX_OBJ_CLOSE (m_eapTypeListMenu);
    VFX_OBJ_CLOSE (m_eapTypeContentProvider);

    VfxPage::onDeinit ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_DEINIT_EAP_TYPES_PAGE);
}

void VappWlanEAPTypesPage::onCmdButtonClicked(VcpListMenu * sender, VfxU32 index)
{
    VFX_TRACE(("===== Cmd button clicked! =====\n"));
    VappWlanEAPTLSPage* tlsEapPage = NULL;
    VappWlanEAPMultiPage* multiEapPage = NULL;
    VappWlanEAPUserInfoPage* userInfoPage = NULL;
        
    supc_abm_eap_type_enum eapType = m_eapTypeArray[index];
    VFX_TRACE(("===== EAP Type %d\n", eapType));

    switch(eapType)
    {
    case WLAN_EAP_TLS:
        VFX_OBJ_CREATE_EX(tlsEapPage, VappWlanEAPTLSPage, this, (m_profile));
        getMainScr ()->pushPage (0, tlsEapPage);
        break;
    case WLAN_EAP_PEAP:
        VFX_OBJ_CREATE_EX(multiEapPage, VappWlanEAPMultiPage, this, 
            (EAP_TYPE_PEAP_PAGE_ITEM_COUNT, WLAN_AP_EAP_TYPE_PAGE_TWO, (supc_abm_eap_type_enum*)m_eapPeapTypeArray, m_profile));
        getMainScr ()->pushPage (0, multiEapPage);
        break;
    case WLAN_EAP_TTLS:
        VFX_OBJ_CREATE_EX(multiEapPage, VappWlanEAPMultiPage, this, 
            (EAP_TYPE_TTLS_PAGE_ITEM_COUNT, WLAN_AP_EAP_TYPE_PAGE_THREE, (supc_abm_eap_type_enum*)m_eapTtlsTypeArray, m_profile));
        getMainScr ()->pushPage (0, multiEapPage);
        break;
    case WLAN_EAP_MD5:
    // case WLAN_EAP_SIM:
    case WLAN_EAP_FAST:
    case WLAN_EAP_MSCHAV2:
    case WLAN_EAP_GTC:
    case WLAN_PAP:
    case WLAN_CHAP:
    case WLAN_MSCHAP:
    case WLAN_MSCHAPV2:
        VFX_OBJ_CREATE_EX(userInfoPage, VappWlanEAPUserInfoPage, this, (m_profile));
        getMainScr ()->pushPage (0, userInfoPage);
        break;
    case WLAN_EAP_AKA:
        // new add        
    case WLAN_EAP_SIM:
        break;
    default:
        break;
    }
}

void VappWlanEAPTypesPage::onSelectStateChanged(
            VcpListMenu * sender,
            VfxU32        index,
            VcpListMenuItemStateEnum newState)
{
    VFX_TRACE(("===== Index: %d New state: %d =====\n", index, newState));
    m_itemStateArray[index] = newState;
}

void VappWlanEAPTypesPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    VFX_TRACE(("===== Toolbar item %d clicked! =====\n", id));
    switch(id)
    {
        case EAP_TYPES_SETTING_TOOLBAR_OK:
            if(VFX_TRUE == saveEapTypesSettings())
            {
                getMainScr ()->popPage ();
            }
            else
            {
                VcpConfirmPopup* invalidEapConfirm;
                VFX_OBJ_CREATE (invalidEapConfirm, VcpConfirmPopup, getMainScr ());
                invalidEapConfirm->setInfoType (VCP_POPUP_TYPE_WARNING);
                invalidEapConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_ERROR_AT_LEAST_ONE_TYPE));
                invalidEapConfirm->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
                invalidEapConfirm->setAutoDestory(VFX_TRUE);
                invalidEapConfirm->show (VFX_TRUE);
            }
            break;
        case EAP_TYPES_SETTING_TOOLBAR_CANCEL:
            getMainScr ()->popPage ();
            break;
        default:
            break;
    }
}

void VappWlanEAPTypesPage::initEapTypesStatusArray()
{
    VfxU32 index;

    VfxU32 curValue = m_profile->getEapAuthType ();
    VfxU32 curPeapValue = m_profile->getEapPeapAuthType ();
    VfxU32 curTtlsValue = m_profile->getEapTtlsAuthType ();
    VfxU32 eapValue;
    
    switch(m_eapTypePageEnum)
    {
    case WLAN_AP_EAP_TYPE_PAGE_ONE:
        VFX_TRACE(("EAP Auth Value %d\n", curValue));
        
        for(index = 0; index < m_itemCount; index++)
        {
            eapValue = m_eapTypeArray[index];
            
            if((eapValue & curValue) > 0)
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_SELECTED;
            else
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
        break;
    case WLAN_AP_EAP_TYPE_PAGE_TWO:
        VFX_TRACE(("EAP PEAP Auth Value %d\n", curPeapValue));
        
        for(index = 0; index < m_itemCount; index++)
        {
            eapValue = m_eapTypeArray[index];
            
            if((eapValue & curPeapValue) > 0)
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_SELECTED;
            else
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
        break;
    case WLAN_AP_EAP_TYPE_PAGE_THREE:
        VFX_TRACE(("EAP Auth Value %d\n", curTtlsValue));
        
        for(index = 0; index < m_itemCount; index++)
        {
            eapValue = m_eapTypeArray[index];
            
            if((eapValue & curTtlsValue) > 0)
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_SELECTED;
            else
                m_itemStateArray[index] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
        break;
    default:
        break;
    }
}

VfxBool VappWlanEAPTypesPage::saveEapTypesSettings()
{
    VfxU8   index = 0;
    VfxU32  eapValue = 0;
    VfxBool flag = VFX_FALSE;
    
    for(index = 0; index < m_itemCount; index++)
    {
        if(VCP_LIST_MENU_ITEM_STATE_SELECTED == m_itemStateArray[index])
        {
            eapValue |= m_eapTypeArray[index];
            flag = VFX_TRUE;
            
            VFX_TRACE (("Item value: %d EAP value: %d \n", m_eapTypeArray[index], eapValue));
        }
    }

    if(VFX_FALSE == flag)
        return VFX_FALSE;
    
    switch(m_eapTypePageEnum)
    {
    case WLAN_AP_EAP_TYPE_PAGE_ONE:
        m_profile->resetEapAuthType (eapValue);
        VFX_TRACE(("WLAN_AP_EAP_TYPE_PAGE_ONE %d\n", eapValue));
        break;
    case WLAN_AP_EAP_TYPE_PAGE_TWO:
        m_profile->resetEapPeapAuthType (eapValue);
        VFX_TRACE(("WLAN_AP_EAP_TYPE_PAGE_TWO %d\n", eapValue));
        break;
    case WLAN_AP_EAP_TYPE_PAGE_THREE:
        m_profile->resetEapTtlsAuthType (eapValue);
        VFX_TRACE(("WLAN_AP_EAP_TYPE_PAGE_THREE %d\n", eapValue));
        break;
    default:
        break;
    }

    return VFX_TRUE;
}

/***************************************************************************** 
 * Class VappWlanEAPTypesContentProvider
 *****************************************************************************/
VfxU32 VappWlanEAPTypesContentProvider::getCount() const
{
    return m_itemCount;
}

VfxBool VappWlanEAPTypesContentProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    supc_abm_eap_type_enum eapType = m_eapTypeArray[index];
    VFX_TRACE(("the value of eap type is %d\n", eapType));

    switch(eapType)
    {
    case WLAN_EAP_TLS:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_TLS);
        break;
    case WLAN_EAP_MD5:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_MD5);
        break;
    case WLAN_EAP_PEAP:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_PEAP);
        break;
    case WLAN_EAP_TTLS:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_TTLS);
        break;
    case WLAN_EAP_SIM:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_SIM);
        break;
    case WLAN_EAP_FAST:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_FAST);
        break;
    case WLAN_EAP_MSCHAV2:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_MSCHAP2);
        break;
    case WLAN_EAP_GTC:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_GTC);
        break;
    case WLAN_PAP:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_PAP);
        break;
    case WLAN_CHAP:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPE_CHAP);
        break;
    case WLAN_MSCHAP:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_MSCHAP);
        break;
    case WLAN_MSCHAPV2:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_MSCHAP2);
        break;
    case WLAN_EAP_AKA:
        text = VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_AKA);
    default:
        break;
    }
    
    return VFX_TRUE;
}

VcpListMenuItemStateEnum VappWlanEAPTypesContentProvider::getItemState(
        VfxU32 index   // [IN] index of the item
        ) const 
{
    VcpListMenuItemStateEnum state = VCP_LIST_MENU_ITEM_STATE_NONE;
    VfxU32 eapValue = m_eapTypeArray[index];
    VFX_TRACE(("the value of eap auth is %d\n", m_profile->getEapAuthType ()));
    VFX_TRACE(("item %d's eap value is %d\n", index, eapValue));
    switch(m_eapTypePageEnum)
    {
    case WLAN_AP_EAP_TYPE_PAGE_ONE:
        VFX_TRACE(("State: %d\n", (eapValue & (m_profile->getEapAuthType ()))));    
        if((eapValue & (m_profile->getEapAuthType ())) > 0)
            state = VCP_LIST_MENU_ITEM_STATE_SELECTED;
        else
            state = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        break;
    case WLAN_AP_EAP_TYPE_PAGE_TWO:
        if((eapValue & (m_profile->getEapPeapAuthType ())) > 0)
            state = VCP_LIST_MENU_ITEM_STATE_SELECTED;
        else
            state = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        break;
    case WLAN_AP_EAP_TYPE_PAGE_THREE:
        if((eapValue & (m_profile->getEapTtlsAuthType ())) > 0)
            state = VCP_LIST_MENU_ITEM_STATE_SELECTED;
        else
            state = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        break;
    default:
        break;
    }
    return state;
}

VfxBool VappWlanEAPTypesContentProvider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        ) 
{
    supc_abm_eap_type_enum eapType = m_eapTypeArray[index];
    
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
            if(WLAN_EAP_AKA != eapType && WLAN_EAP_SIM != eapType)
            {
                image.setResId(IMG_ID_VAPP_WLAN_EDIT_EAP_SETTING);
            }
            break;
        default:
            break;
    }

    return VFX_TRUE;
}


/***************************************************************************** 
 * Class VappWlanEAPTLSPage
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWlanEAPTLSPage", VappWlanEAPTLSPage, VfxPage);
VappWlanEAPTLSPage::VappWlanEAPTLSPage(VappWlanProfile* profile) :
        m_profile(profile),
        m_privateKey(VFX_WSTR_EMPTY),
        m_username(VFX_WSTR_EMPTY)
{
    VfxChar  *rootCertAscii;
    VfxChar  *userCertAscii;
    VfxWChar *rootCertName;
    VfxWChar *userCertName;
    VfxWChar *privateKeyPasswd;
    VfxWChar *username;
    VfxWString none = VFX_WSTR_RES(STR_GLOBAL_NONE);

    VFX_TRACE(("===== VappWlanEAPTLSPage constructor =====\n"));
    VFX_ALLOC_MEM(rootCertAscii, (SRV_DTCNT_PROF_MAX_USER_LEN + 1), this);
    VFX_ALLOC_MEM(userCertAscii, (SRV_DTCNT_PROF_MAX_USER_LEN + 1), this);
    VFX_ALLOC_MEM(rootCertName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(userCertName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(privateKeyPasswd, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(username, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH, this);
    
    memset(rootCertAscii, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1));
    memset(userCertAscii, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1));
    memset(rootCertName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    memset(userCertName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    memset(privateKeyPasswd, 0, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
    memset(username, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    memset(m_tempCaCertName, 0, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
    memset(m_tempUserCertName, 0, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
    VappWlanToolbox::convertStrToAscii((VfxChar*)m_tempCaCertName, none, none.getLength ());
    VappWlanToolbox::convertStrToAscii((VfxChar*)m_tempUserCertName, none, none.getLength ());
    
    m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    // register page in the respository
    m_repository->registerObserver (this);
    setSubscribe (
        SUBSCRIBE_SELECT_CA_MSG |
        SUBSCRIBE_SELECT_USER_MSG);
    
    // Get Root&User Cert. ID
    m_tempRootCaId = m_profile->getRootCaId ();
    m_tempUserCaId = m_profile->getClientCaId ();
#ifdef __CERTMAN_SUPPORT__    
    if (0 != m_tempRootCaId)
    {
        mmi_certman_get_cert_label(
            m_tempRootCaId , 
            (VfxU8*)rootCertName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        if(mmi_ucs2strlen((const CHAR *)rootCertName) > 0)
        {
            mmi_ucs2_n_to_asc((CHAR *)rootCertAscii, (CHAR *)rootCertName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1)* ENCODING_LENGTH);
            VFX_TRACE(("&&&&&&&& Root Cert.: %s \n", rootCertAscii));
            memcpy(m_tempCaCertName, rootCertAscii, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
        }
    }
    VFX_TRACE(("WAPI ASE: %s\n", rootCertAscii));
    
    if(0 != m_tempUserCaId)
    {
        mmi_certman_get_cert_label(
            m_tempUserCaId , 
            (VfxU8*)userCertName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        if(mmi_ucs2strlen((const CHAR *)userCertName) > 0)
        {
            mmi_ucs2_n_to_asc((CHAR *)userCertAscii, (CHAR *)userCertName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1)* ENCODING_LENGTH);
            VFX_TRACE(("&&&&&&&& Client: %s \n", userCertAscii));
            memcpy(m_tempUserCertName, userCertAscii, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
        }
    }
    VFX_TRACE(("WAPI Client: %s\n", userCertAscii));
#endif    
    VFX_TRACE(("===== Private key password: %s =====\n", m_profile->getPrivateKeyPasswd ()));
    if(strlen((const char *)m_profile->getPrivateKeyPasswd ()) > 0)
    {
        mmi_asc_to_ucs2 ((CHAR *)privateKeyPasswd, (CHAR *)m_profile->getPrivateKeyPasswd ());
        m_privateKey.loadFromMem ((const VfxWChar *)privateKeyPasswd);
    }

    VFX_TRACE(("===== Username: %s =====\n", m_profile->getUserName ()));
    if(strlen((const char *)m_profile->getUserName ()) > 0)
    {
        //mmi_asc_to_ucs2 ((CHAR *)username, (CHAR *)m_profile->getUserName ());
	    mmi_chset_convert(
		    MMI_CHSET_UTF8,
		    MMI_CHSET_UCS2, 
		    (CHAR *)m_profile->getUserName (), 
		    (CHAR *)username,
		    (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH)	;	    
        m_username.loadFromMem ((const VfxWChar *)username);
    }
    
    VFX_FREE_MEM(rootCertAscii);
    VFX_FREE_MEM(userCertAscii);
    VFX_FREE_MEM(rootCertName);
    VFX_FREE_MEM(userCertName);
    VFX_FREE_MEM(privateKeyPasswd);
    VFX_FREE_MEM(username);
}

VappWlanEAPTLSPage:: ~VappWlanEAPTLSPage() 
{
	// deregister page in the respository
    m_repository->removeObserver (this);
}

void VappWlanEAPTLSPage::onInit ()
{
    VfxU8 caCertName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    VfxU8 userCertName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    
    memset(caCertName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    memset(userCertName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    VfxWString caCertNameStr = VFX_WSTR_RES(STR_GLOBAL_NONE);
    VfxWString userCertNameStr = VFX_WSTR_RES(STR_GLOBAL_NONE);
    
    VFX_TRACE(("===== VappWlanEAPTLSPage initialization =====\n"));
    Observer::onInit ();

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TLS));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (EAP_TLS_SETTING_TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (EAP_TLS_SETTING_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWlanEAPTLSPage::onToolBarClick);
    setBottomBar(m_toolBar);
    
    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(EAP_TLS_PAGE_FORM_FUNC_BAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_PREV));
    m_functionBar->addItem(EAP_TLS_PAGE_FORM_FUNC_BAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_NEXT));
    m_functionBar->addItem(EAP_TLS_PAGE_FORM_FUNC_BAR_OK, VFX_WSTR_RES(STR_GLOBAL_DONE));
    m_functionBar->setItemSpecial (EAP_TLS_PAGE_FORM_FUNC_BAR_OK);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (
        this, &VappWlanEAPTLSPage::onFuncBarBtnClick);

    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // CA certificates
    VFX_OBJ_CREATE(m_caCertBtn, VcpFormItemBigArrowButton, this);
    m_caCertBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_CA_CERT));
    if(0 != m_tempRootCaId)
    {
        mmi_asc_to_ucs2 (
            (CHAR * )caCertName, 
            (CHAR * )m_tempCaCertName);
        caCertNameStr.loadFromMem ((const VfxWChar *) caCertName);
    }
    m_caCertBtn->setHintText (caCertNameStr);
    m_caCertBtn->getButton ()->setId (EAP_TLS_PAGE_FORM_BUTTON_CA_CERT);
    m_caCertBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappWlanEAPTLSPage::onPropertyBtnClick);
    
    // User certificates
    VFX_OBJ_CREATE(m_userCertBtn, VcpFormItemBigArrowButton, this);
    m_userCertBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_USER_CERT));
    if(0 != m_tempUserCaId)
    {
        mmi_asc_to_ucs2 (
            (CHAR * )userCertName, 
            (CHAR * )m_tempUserCertName);
        userCertNameStr.loadFromMem ((const VfxWChar *) userCertName);
    }
    m_userCertBtn->setHintText (userCertNameStr);
    m_userCertBtn->getButton ()->setId (EAP_TLS_PAGE_FORM_BUTTON_USER_CERT);
    m_userCertBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappWlanEAPTLSPage::onPropertyBtnClick);

    // Private key
    VFX_OBJ_CREATE(m_privateKeyText, VcpFormItemTextInput, this);
    m_privateKeyText->getTextBox ()->setText (m_privateKey, SRV_DTCNT_PROF_MAX_PW_LEN);
    m_privateKeyText->getTextBox ()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
    m_privateKeyText->getTextBox ()->setFunctionBar (m_functionBar);
    // m_privateKeyText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_privateKeyText->getTextBox ()->m_signalActivated.connect (this, &VappWlanEAPTLSPage::onTextEditorActivated);
    m_privateKeyText->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_PRIVATE_KEY));
    m_privateKeyText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Username
    VFX_OBJ_CREATE(m_usernameText, VcpFormItemTextInput, this);
    //m_usernameText->getTextBox ()->setText (m_username, SRV_DTCNT_PROF_MAX_USER_LEN);
    m_usernameText->getTextBox()->setText(
    				                m_username, 
            						SRV_DTCNT_PROF_MAX_USER_LEN,
            						VFX_FALSE,
            						VCP_TEXT_ENCODING_UTF8);
    m_usernameText->getTextBox ()->setFunctionBar (m_functionBar);
    // m_usernameText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_usernameText->getTextBox ()->m_signalActivated.connect (this, &VappWlanEAPTLSPage::onTextEditorActivated);
    m_usernameText->setLabelText(VFX_WSTR_RES(STR_GLOBAL_USERNAME));
    m_usernameText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Append item into form
    m_form->addItem (m_caCertBtn, EAP_TLS_PAGE_FORM_BUTTON_CA_CERT);
    m_form->addItem (m_userCertBtn, EAP_TLS_PAGE_FORM_BUTTON_USER_CERT);
    m_form->addItem (m_privateKeyText, EAP_TLS_PAGE_FORM_TEXT_PRIVATE_KEY);
    m_form->addItem (m_usernameText, EAP_TLS_PAGE_FORM_TEXT_USERNAME);
}

void VappWlanEAPTLSPage::onDeinit ()
{
    VFX_OBJ_CLOSE (m_titleBar);
    VFX_OBJ_CLOSE (m_toolBar);
    VFX_OBJ_CLOSE (m_caCertBtn);
    VFX_OBJ_CLOSE (m_userCertBtn);
    VFX_OBJ_CLOSE (m_privateKeyText);
    VFX_OBJ_CLOSE (m_usernameText);
    VFX_OBJ_CLOSE (m_form);

    Observer::onDeinit ();
    VFX_TRACE(("===== VappWlanEAPTLSPage deinitialization =====\n"));
}

void VappWlanEAPTLSPage::UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{    
    // if setting page is not in active status, return
    if(VFX_FALSE == getMainScr ()->isActive () || VFX_FALSE == isActive ())
    {
        return;
    }
	
    VfxWString certName = VFX_WSTR_RES(STR_GLOBAL_NONE);
    VfxU8 rootCaName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH]; 
    VfxU8 userCaName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
	
    VFX_TRACE(("===== Update VappWlanEAPTLSPage =====\n"));
    VFX_TRACE(("===== MSG: %d =====\n", msg));
    switch(msg)
    {
    case SUBSCRIBE_SELECT_CA_MSG:
        m_tempRootCaId = m_repository->getRootCAId ();		
		memset(rootCaName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    	mmi_certman_get_cert_label(
        	m_tempRootCaId, 
        	rootCaName, 
        	(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);  
		
        mmi_ucs2_n_to_asc (
            (CHAR*)m_tempCaCertName, 
            (CHAR*)rootCaName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        certName.loadFromMem ((const VfxWChar *) rootCaName);
        m_caCertBtn->setHintText (certName);
        break;
    case SUBSCRIBE_SELECT_USER_MSG:
        m_tempUserCaId = m_repository->getUserCAId ();
        memset(userCaName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);           
    	mmi_certman_get_cert_label(
            m_tempUserCaId, 
            userCaName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
	
        mmi_ucs2_n_to_asc (
            (CHAR*)m_tempUserCertName, 
            (CHAR*)userCaName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        certName.loadFromMem ((const VfxWChar *) userCaName);
        m_userCertBtn->setHintText (certName);
        break;
    default:
        break;
    }
   
}

void VappWlanEAPTLSPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    VFX_TRACE(("===== Toolbar item %d clicked! =====\n", id));

    switch(id)
    {
        case EAP_TLS_SETTING_TOOLBAR_OK:
            saveEapTlsSettings();
            break;
        case EAP_TLS_SETTING_TOOLBAR_CANCEL:
            break;
        default:
            break;
    }
    getMainScr ()->popPage ();
}

void VappWlanEAPTLSPage::onPropertyBtnClick(VfxObject* sender, VfxId id)
{
    VFX_TRACE(("===== Item %d clicked! =====\n", id));
    
    switch(id)
    {
    case EAP_TLS_PAGE_FORM_BUTTON_CA_CERT:
#ifdef __CERTMAN_SUPPORT__        
        VappWlanSentry::SendSelectCACertRequest(STR_ID_VAPP_WLAN_INPUT_WAPI_CA_CERT);
#endif
        break;
    case EAP_TLS_PAGE_FORM_BUTTON_USER_CERT:
#ifdef __CERTMAN_SUPPORT__        
        VappWlanSentry::SendSelectUserCertRequest(STR_ID_VAPP_WLAN_INPUT_WAPI_USER_CERT);
#endif
        break;
    default:
        break;
    }
}

void VappWlanEAPTLSPage::onFuncBarBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case EAP_TLS_PAGE_FORM_FUNC_BAR_PREV:
        if(m_prevEditor)
        {
            m_prevEditor->activate ();
        }
        break;
    case EAP_TLS_PAGE_FORM_FUNC_BAR_NEXT:
        if(m_nextEditor)
        {
            m_nextEditor->activate ();
        }
        break;        
    case EAP_TLS_PAGE_FORM_FUNC_BAR_OK:
        if(m_curEditor)
        {
            m_curEditor->deactivate ();
        }
        saveEapTlsSettings ();
        getMainScr ()->popPage ();
        break;
    default:
        break;
    }
}

void VappWlanEAPTLSPage::onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive)
{
    if(isActive)
    {
        VFX_TRACE(("Text editor activated!\n"));
        if(sender == m_privateKeyText->getTextBox ())
        {
            m_prevEditor = NULL;
            m_nextEditor = m_usernameText->getTextBox ();
        }
        else if(sender == m_usernameText->getTextBox ())
        {
            m_prevEditor = m_privateKeyText->getTextBox ();
            m_nextEditor = NULL;
        }
        m_curEditor = sender;
        
        m_functionBar->setDisableItem (EAP_TLS_PAGE_FORM_FUNC_BAR_PREV, m_prevEditor == NULL);
        m_functionBar->setDisableItem (EAP_TLS_PAGE_FORM_FUNC_BAR_NEXT, m_nextEditor == NULL);
    }
    else
    {
        VFX_TRACE(("Text editor deactivated!\n"));
    }
}

void VappWlanEAPTLSPage::saveEapTlsSettings()
{
    VfxWChar*   privateKeyUnicode;
    VfxChar*    privateKeyAscii;
    VfxWChar*   usernameUnicode;
    VfxChar*    usernameAscii;

    m_profile->setRootCaId (m_tempRootCaId);
    m_profile->setClientCaId (m_tempUserCaId);
    m_profile->setCaCertName (m_tempCaCertName);
    m_profile->setUserCertName (m_tempUserCertName);

    VFX_ALLOC_MEM(privateKeyUnicode, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(privateKeyAscii, SRV_DTCNT_PROF_MAX_PW_LEN + 1, this);
    VFX_ALLOC_MEM(usernameUnicode, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH, this);
    VFX_ALLOC_MEM(usernameAscii, SRV_DTCNT_PROF_MAX_USER_LEN + 1, this);

    memset(privateKeyUnicode, 0, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
    memset(privateKeyAscii, 0, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
    memset(usernameUnicode, 0, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
    memset(usernameAscii, 0, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
        
    if(m_privateKeyText->getText ().getLength () > 0)
    {
        memcpy(privateKeyUnicode, m_privateKeyText->getTextBox ()->getText (), (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
        mmi_wcs_n_to_asc(privateKeyAscii, privateKeyUnicode, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
        m_profile->setPrivateKeyPasswd ((const VfxU8 *) privateKeyAscii);
        VFX_TRACE(("===== Private key string: %s =====\n", m_profile->getPrivateKeyPasswd ()));
    }
    else
    {
        m_profile->clearPrivateKeyPasswd ();
    }
    
    if(m_usernameText->getText ().getLength () > 0)
    {
        memcpy(usernameUnicode, m_usernameText->getTextBox ()->getText (), (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        // mmi_wcs_n_to_asc(usernameAscii, usernameUnicode, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        mmi_chset_ucs2_to_utf8_string(
    	        (VfxU8 *)usernameAscii,(SRV_DTCNT_PROF_MAX_USER_LEN + 1),(VfxU8 *)usernameUnicode);
    	m_profile->setUserName ((const VfxU8 *) usernameAscii);        
        VFX_TRACE(("===== Username: %s =====\n", m_profile->getUserName ()));
    }
    else
    {
        m_profile->clearUserName ();
    }

    VFX_FREE_MEM (privateKeyUnicode);
    VFX_FREE_MEM (privateKeyAscii);
    VFX_FREE_MEM (usernameUnicode);
    VFX_FREE_MEM (usernameAscii);
}

/***************************************************************************** 
 * Class VappWlanEAPMultiPage
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWlanEAPMultiPage", VappWlanEAPMultiPage, VfxPage);
VappWlanEAPMultiPage::VappWlanEAPMultiPage(
        VfxU32 itemCount, 
        VAPP_WLAN_EAP_TYPE_PAGE_ENUM pageEnum, 
        supc_abm_eap_type_enum* eapTypeArray, 
        VappWlanProfile* profile) :
                m_itemCount(itemCount),                
                m_eapTypeArray(eapTypeArray), 
                m_eapTypePageEnum(pageEnum),
                m_profile(profile) 
{
    VfxChar  *rootCertAscii;
    VfxWChar *rootCertName;
    VfxWString none = VFX_WSTR_RES(STR_GLOBAL_NONE);

    VFX_TRACE(("===== VappWlanEAPTLSPage constructor =====\n"));
    VFX_ALLOC_MEM(rootCertAscii, (SRV_DTCNT_PROF_MAX_USER_LEN + 1), this);
    VFX_ALLOC_MEM(rootCertName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH, this);
    
    memset(rootCertAscii, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1));
    memset(rootCertName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    memset(m_tempCaCertName, 0, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
    VappWlanToolbox::convertStrToAscii((VfxChar*)m_tempCaCertName, none, none.getLength ());

    m_repository = VFX_OBJ_GET_INSTANCE(VappWlanRepository);
    // Register messages which are interested
    m_repository->registerObserver (this);
    setSubscribe (SUBSCRIBE_SELECT_CA_MSG);

    m_tempRootCaId = m_profile->getRootCaId ();
#ifdef __CERTMAN_SUPPORT__    
    if (0 != m_tempRootCaId)
    {
        mmi_certman_get_cert_label(
            m_tempRootCaId , 
            (VfxU8*)rootCertName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        if(mmi_ucs2strlen((const CHAR *)rootCertName) > 0)
        {
            mmi_ucs2_n_to_asc((CHAR *)rootCertAscii, (CHAR *)rootCertName, (SRV_DTCNT_PROF_MAX_USER_LEN + 1)* ENCODING_LENGTH);
            VFX_TRACE(("&&&&&&&& Root Cert.: %s \n", rootCertAscii));
            memcpy(m_tempCaCertName, rootCertAscii, (SRV_DTCNT_PROF_MAX_USER_LEN + 1));
            m_profile->setCaCertName (m_tempCaCertName);
        }
    }
    VFX_TRACE(("WAPI ASE: %s\n", rootCertAscii));
#endif
    VFX_OBJ_CREATE(m_tempProfile, VappWlanProfile, this);
    VappWlanToolbox::initWlanProfile (m_tempProfile);
    VappWlanToolbox::cloneWlanProfile (m_profile, m_tempProfile);

    VFX_FREE_MEM(rootCertAscii);
    VFX_FREE_MEM(rootCertName);
}
				
VappWlanEAPMultiPage:: ~VappWlanEAPMultiPage() 
{
	// deregister page in the respository
    m_repository->removeObserver (this);
}

void VappWlanEAPMultiPage::onInit ()
{
    VfxU8 caCertName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    VfxWString caCertNameStr = VFX_WSTR_RES(STR_GLOBAL_NONE);
    
    memset(caCertName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        
    VFX_TRACE(("===== VappWlanEAPMultiPage initialization =====\n"));
    Observer::onInit ();

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    if(WLAN_AP_EAP_TYPE_PAGE_TWO == m_eapTypePageEnum)
        m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_PEAP));
    else
        m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TTLS));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (MULTI_SETTING_TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (MULTI_SETTING_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWlanEAPMultiPage::onToolBarClick);
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

    // CA certificates
    VFX_OBJ_CREATE(m_caCertBtn, VcpFormItemBigArrowButton, this);
    m_caCertBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_WAPI_CA_CERT));
    if(0 != m_tempRootCaId)
    {
        mmi_asc_to_ucs2 (
            (CHAR * )caCertName, 
            (CHAR * )m_tempCaCertName);
        caCertNameStr.loadFromMem ((const VfxWChar *) caCertName);
    }
    m_caCertBtn->setHintText (caCertNameStr);
    m_caCertBtn->getButton ()->setId (EAP_MULTI_PAGE_FORM_BUTTON_CA_CERT);
    m_caCertBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappWlanEAPMultiPage::onPropertyBtnClick);

    // EAP types
    VFX_OBJ_CREATE(m_eapTypesBtn, VcpFormItemBigArrowButton, this);
    m_eapTypesBtn->setButtonText (VFX_WSTR_RES(STR_ID_VAPP_WLAN_EAP_TYPES));
    m_eapTypesBtn->getButton ()->setId (EAP_MULTI_PAGE_FORM_BUTTON_EAP_TYPES);
    m_eapTypesBtn->getButton ()->m_signalClicked.connect (
                                    this, &VappWlanEAPMultiPage::onPropertyBtnClick);
    // Append item into form
    m_form->addItem (m_caCertBtn, EAP_MULTI_PAGE_FORM_BUTTON_CA_CERT);
    m_form->addItem (m_eapTypesBtn, EAP_MULTI_PAGE_FORM_BUTTON_EAP_TYPES);
}

void VappWlanEAPMultiPage::onEnter (VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if(isBackward)
    {
        VfxU8 caCertName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
        memset(caCertName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        VfxWString caCertNameStr = VFX_WSTR_RES(STR_GLOBAL_NONE);
    
        // Refresh the CA certificates
        m_tempRootCaId = m_tempProfile->getRootCaId();
        if(m_tempRootCaId != 0)
        {
            memcpy(m_tempCaCertName, m_tempProfile->getCaCertName (), SRV_DTCNT_PROF_MAX_USER_LEN + 1);
            mmi_asc_to_ucs2 (
                (CHAR * )caCertName, 
                (CHAR * )m_tempCaCertName);
            caCertNameStr.loadFromMem ((const VfxWChar *) caCertName);    
        }
        m_caCertBtn->setHintText (caCertNameStr);
    }
}

void VappWlanEAPMultiPage::onDeinit ()
{
    VFX_OBJ_CLOSE (m_tempProfile);
    VFX_OBJ_CLOSE (m_titleBar);
    VFX_OBJ_CLOSE (m_toolBar);
    VFX_OBJ_CLOSE (m_caCertBtn);
    VFX_OBJ_CLOSE (m_eapTypesBtn);
    VFX_OBJ_CLOSE (m_form);
    
    Observer::onDeinit ();
    VFX_TRACE(("===== VappWlanEAPTLSPage deinitialization =====\n"));
}

void VappWlanEAPMultiPage::UpdatePage (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{
    // if setting page is not in active status, return
    if(VFX_FALSE == getMainScr ()->isActive () || VFX_FALSE == isActive ())
    {
        return;
    }

    VfxWString certName = VFX_WSTR_RES(STR_GLOBAL_NONE);
    VfxU8 rootCaName[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    
    VFX_TRACE(("===== Update VappWlanEAPMultiPage =====\n"));
    VFX_TRACE(("===== MSG: %d =====\n", msg));
    switch(msg)
    {
    case SUBSCRIBE_SELECT_CA_MSG:
        m_tempRootCaId = m_repository->getRootCAId ();		
		memset(rootCaName, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        mmi_certman_get_cert_label(
        	m_tempRootCaId, 
        	rootCaName, 
        	(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);  
		
        mmi_ucs2_n_to_asc (
            (CHAR*)m_tempCaCertName, 
            (CHAR*)rootCaName, 
            (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        certName.loadFromMem ((const VfxWChar *) rootCaName);
        m_caCertBtn->setHintText (certName);

        m_tempProfile->setRootCaId (m_tempRootCaId);
        m_tempProfile->setCaCertName (m_tempCaCertName);
        break;
    default:
        break;
    }
}

void VappWlanEAPMultiPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    VFX_TRACE(("===== Toolbar item %d clicked! =====\n", id));

    switch(id)
    {
        case MULTI_SETTING_TOOLBAR_OK:
            m_tempProfile->setRootCaId (m_tempRootCaId);
            m_tempProfile->setCaCertName (m_tempCaCertName);
            VappWlanToolbox::cloneWlanProfile (m_tempProfile, m_profile);
            break;
        case MULTI_SETTING_TOOLBAR_CANCEL:
            break;
        default:
            break;
    }
    getMainScr ()->popPage ();
}

void VappWlanEAPMultiPage::onPropertyBtnClick(VfxObject* sender, VfxId id)
{
    VFX_TRACE(("===== Toolbar item %d clicked! =====\n", id));
    VappWlanEAPTypesPage* eapTypesPage = NULL;
    
    switch(id)
    {
    case EAP_MULTI_PAGE_FORM_BUTTON_CA_CERT:
#ifdef __CERTMAN_SUPPORT__
        VappWlanSentry::SendSelectCACertRequest(STR_ID_VAPP_WLAN_INPUT_WAPI_CA_CERT);
#endif
        break;
    case EAP_MULTI_PAGE_FORM_BUTTON_EAP_TYPES:
        VFX_OBJ_CREATE_EX(eapTypesPage, VappWlanEAPTypesPage, this, 
            (m_itemCount, m_eapTypePageEnum, m_eapTypeArray, m_tempProfile));
        getMainScr ()->pushPage (0, eapTypesPage);
        break;
    default:
        break;
           
    }
}

/***************************************************************************** 
 * Class VappWlanEAPUserInfoPage
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS ("VappWlanEAPUserInfoPage", VappWlanEAPUserInfoPage, VfxPage);
VappWlanEAPUserInfoPage::VappWlanEAPUserInfoPage(VappWlanProfile* profile) :
        m_profile(profile),
        m_usernameStr(VFX_WSTR_EMPTY),
        m_passwordStr(VFX_WSTR_EMPTY)
{
    VfxWChar   username[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    VfxWChar   password[(SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH];

    memset(username, 0, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
    memset(password, 0, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
    
    VFX_TRACE(("===== VappWlanEAPUserInfoPage constructor =====\n"));
    VFX_TRACE(("===== user name: %s =====\n", m_profile->getUserName ()));
    if(strlen((const char *)m_profile->getUserName ()) > 0)
    {
        //mmi_asc_to_ucs2 ((CHAR *)username, (CHAR *)m_profile->getUserName ());
	    mmi_chset_convert(
		    MMI_CHSET_UTF8,
		    MMI_CHSET_UCS2, 
		    (CHAR *)m_profile->getUserName (), 
		    (CHAR *)username,
		    (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH)	;	    
        m_usernameStr.loadFromMem ((const VfxWChar *)username);
    }
    
    VFX_TRACE(("===== password: %s =====\n", m_profile->getPassword ()));
    if(strlen((const char *)m_profile->getPassword ()) > 0)
    {
        mmi_asc_to_ucs2 ((CHAR *)password, (CHAR *)m_profile->getPassword ());
        m_passwordStr.loadFromMem ((const VfxWChar *)password);
    }
}

void VappWlanEAPUserInfoPage::onInit ()
{
    VFX_TRACE(("===== VappWlanEAPUserInfoPage initialization =====\n"));
    VfxPage::onInit ();

    // Set background color as white    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // Title Bar
    VFX_OBJ_CREATE (m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle (VFX_WSTR_RES(STR_ID_VAPP_WLAN_INPUT_INDENTIFICATION));
    setTopBar (m_titleBar);
    
    // Tool bar
    VFX_OBJ_CREATE (m_toolBar, VcpToolBar, this);
    m_toolBar->addItem (USER_INFO_SETTING_TOOLBAR_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem (USER_INFO_SETTING_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect (this, &VappWlanEAPUserInfoPage::onToolBarClick);
    setBottomBar(m_toolBar);
    
    // Function Bar
    VFX_OBJ_CREATE (m_functionBar, VcpFunctionBar, this);
    m_functionBar->addItem(USER_INFO_PAGE_FORM_FUNC_PREV, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_PREV));
    m_functionBar->addItem(USER_INFO_PAGE_FORM_FUNC_NEXT, VFX_WSTR_RES(STR_ID_VAPP_WLAN_FUNC_BAR_NEXT));
    m_functionBar->addItem(USER_INFO_PAGE_FORM_FUNC_DONE, VFX_WSTR_RES(STR_GLOBAL_DONE));
    m_functionBar->setItemSpecial (USER_INFO_PAGE_FORM_FUNC_DONE);
//    m_functionBar->setBgColor (VfxColor(VFX_COLOR_BLACK));
    m_functionBar->m_signalButtonTap.connect (
        this, &VappWlanEAPUserInfoPage::onFuncBarBtnClick);
    
    // Form
    VFX_OBJ_CREATE (m_form, VcpForm, this);
    m_form->setPos (0, 0);
    m_form->setSize (getSize ());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // Username
    VFX_OBJ_CREATE(m_usernameText, VcpFormItemTextInput, this);
    //m_usernameText->getTextBox ()->setText (m_usernameStr, SRV_DTCNT_PROF_MAX_USER_LEN);
    m_usernameText->getTextBox()->setText(
    				                m_usernameStr, 
            						SRV_DTCNT_PROF_MAX_USER_LEN,
            						VFX_FALSE,
            						VCP_TEXT_ENCODING_UTF8);
    m_usernameText->getTextBox ()->setFunctionBar (m_functionBar);
    m_usernameText->getTextBox ()->setCursorIndex (0);
    m_usernameText->getTextBox ()->setAutoActivated (VFX_TRUE);
    // m_usernameText->getTextBox ()->setAutoDeactivated (VFX_TRUE);
    m_usernameText->getTextBox ()->m_signalActivated.connect (this, &VappWlanEAPUserInfoPage::onTextEditorActivated);
    m_usernameText->setLabelText(VFX_WSTR_RES(STR_GLOBAL_USERNAME));
    m_usernameText->setLabelPosition (VCPFORM_TOP_LEFT);

    // Password
    VFX_OBJ_CREATE(m_passwordText, VcpFormItemTextInput, this);
    m_passwordText->getTextBox ()->setText (m_passwordStr, SRV_DTCNT_PROF_MAX_PW_LEN);
    m_passwordText->getTextBox ()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
    m_passwordText->getTextBox ()->setFunctionBar (m_functionBar);
    // m_passwordText->getTextBox()->setAutoDeactivated (VFX_TRUE);
    m_passwordText->getTextBox ()->m_signalActivated.connect (this, &VappWlanEAPUserInfoPage::onTextEditorActivated);
    m_passwordText->setLabelText(VFX_WSTR_RES(STR_GLOBAL_PASSWORD));
    m_passwordText->setLabelPosition (VCPFORM_TOP_LEFT);
    
    // Append item into form
    m_form->addItem (m_usernameText, USER_INFO_PAGE_FORM_BUTTON_USERNAME);
    m_form->addItem (m_passwordText, USER_INFO_PAGE_FORM_BUTTON_PASSWORD);
}

void VappWlanEAPUserInfoPage::onDeinit ()
{
    VFX_OBJ_CLOSE (m_titleBar);
    VFX_OBJ_CLOSE (m_toolBar);
    VFX_OBJ_CLOSE (m_usernameText);
    VFX_OBJ_CLOSE (m_passwordText);
    VFX_OBJ_CLOSE (m_form);

    VfxPage::onDeinit ();
    VFX_TRACE(("===== VappWlanEAPTLSPage deinitialization =====\n"));
}

void VappWlanEAPUserInfoPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    VFX_TRACE(("===== Toolbar item %d clicked! =====\n", id));
    switch(id)
    {
    case USER_INFO_SETTING_TOOLBAR_OK:
        saveEapUserInfo();
        getMainScr ()->popPage ();
        break;
    case USER_INFO_SETTING_TOOLBAR_CANCEL:
        getMainScr ()->popPage ();
        break;
    default:
        break;
    }
}

void VappWlanEAPUserInfoPage::onFuncBarBtnClick (VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case USER_INFO_PAGE_FORM_FUNC_PREV:
        if(m_prevEditor)
        {
            m_prevEditor->activate ();
        }
        break;
    case USER_INFO_PAGE_FORM_FUNC_NEXT:
        if(m_nextEditor)
        {
            m_nextEditor->activate ();
        }
        break;        
    case USER_INFO_PAGE_FORM_FUNC_DONE:
        if(m_curEditor)
        {
            m_curEditor->deactivate ();
        }
        saveEapUserInfo();
        getMainScr ()->popPage ();
        break;
    default:
        break;
    }
}

void VappWlanEAPUserInfoPage::onTextEditorActivated(VcpTextEditor *sender, VfxBool isActive)
{
    if(isActive)
    {
        VFX_TRACE(("Text editor activated!\n"));
        if(sender == m_usernameText->getTextBox ())
        {
            m_prevEditor = NULL;
            m_nextEditor = m_passwordText->getTextBox ();
        }
        else if(sender == m_passwordText->getTextBox ())
        {
            m_prevEditor = m_usernameText->getTextBox ();
            m_nextEditor = NULL;
        }
        m_curEditor = sender;
        
        m_functionBar->setDisableItem (USER_INFO_PAGE_FORM_FUNC_PREV, m_prevEditor == NULL);
        m_functionBar->setDisableItem (USER_INFO_PAGE_FORM_FUNC_NEXT, m_nextEditor == NULL);
    }
    else
    {
        VFX_TRACE(("Text editor deactivated!\n"));
    }
}

void VappWlanEAPUserInfoPage::saveEapUserInfo()
{
    VfxWChar   usernameUnicode[(SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH];
    VfxChar    usernameAscii[SRV_DTCNT_PROF_MAX_USER_LEN + 1];
    VfxWChar   passwordUnicode[(SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH];
    VfxChar    passwordAscii[SRV_DTCNT_PROF_MAX_PW_LEN + 1];

    memset(passwordUnicode, 0, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
    memset(passwordAscii, 0, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
    memset(usernameUnicode, 0, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
    memset(usernameAscii, 0, SRV_DTCNT_PROF_MAX_PW_LEN + 1);

    if(m_passwordText->getText ().getLength () > 0)
    {
        vfx_sys_wcscpy(passwordUnicode, m_passwordText->getText ().getBuf ());
        mmi_wcs_n_to_asc(passwordAscii, passwordUnicode, (SRV_DTCNT_PROF_MAX_PW_LEN + 1) * ENCODING_LENGTH);
        m_profile->setPassword ((const VfxU8 *) passwordAscii);
    }
    else
    {
        memset(passwordAscii, 0, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
        m_profile->setPassword ((const VfxU8 *) passwordAscii);
    }
    VFX_TRACE(("===== Password: %s =====\n", m_profile->getPassword ()));
    
    if(m_usernameText->getText ().getLength () > 0)
    {
        vfx_sys_wcscpy(usernameUnicode, m_usernameText->getText ().getBuf ());
        // mmi_wcs_n_to_asc(usernameAscii, usernameUnicode, (SRV_DTCNT_PROF_MAX_USER_LEN + 1) * ENCODING_LENGTH);
        mmi_chset_ucs2_to_utf8_string(
    	        (VfxU8 *)usernameAscii,(SRV_DTCNT_PROF_MAX_USER_LEN + 1),(VfxU8 *)usernameUnicode);   	        
        m_profile->setUserName ((const VfxU8 *) usernameAscii);
    }
    else
    {
        memset(usernameAscii, 0, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
        m_profile->setUserName ((const VfxU8 *) usernameAscii);
    }
    VFX_TRACE(("===== Username: %s =====\n", m_profile->getUserName ()));

}

#endif  /* WIFI_AUTH_PSK_ONLY */

#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__


