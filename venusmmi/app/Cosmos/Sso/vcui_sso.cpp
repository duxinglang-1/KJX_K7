/*  Copyright Statement:
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
 *  vcui_sso.cpp
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#if defined(__COSMOS_MMI__)

#include "vcui_sso_prot.h"
#include "vcui_sso_gprot.h"
#if defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)
#include "mmi_rp_vapp_sns_sso_common_def.h"
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#include "app_str.h"
#include "SnsSrvGprot.h"
#include "SsoSrvGprot.h"
#include "Browser_api.h"
#if defined(__SOCIAL_NETWORK_SUPPORT__)
#include "mmi_rp_srv_sns_def.h"
#endif
#if defined(__MMI_SSO__)
#include "mmi_rp_srv_sso_def.h"    
#endif
#ifdef __cplusplus
}
#endif
mmi_id vcui_sso_login_create(mmi_id caller, U32 provider, U8 accountId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcui_sso_login_args arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: Verify accountId */

	memset(&arg, 0, sizeof(vcui_sso_login_args));
	
	arg.accountId = accountId;
    arg.provider = provider;
    
    return VfxAppLauncher::createCui( 
        VCUI_SSO_SETTING,
        VFX_OBJ_CLASS_INFO(VcuiSsoLogin),
        caller,
        &arg,
        sizeof(vcui_sso_login_args));
}    

void vcui_sso_login_run(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VfxAppLauncher::runCui(cui_id);
}

void vcui_sso_login_close(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VfxApp *app = VfxApp::getObject(cui_id);
	if (app != NULL)
	{
		app->exit();
	}
}

VFX_IMPLEMENT_CLASS("VcuiSsoLogin", VcuiSsoLogin, VfxCui);

void VcuiSsoLogin::onRun(void * args,VfxU32 argSize)
{
#if defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)
    vcui_sso_login_args *sso_login = (vcui_sso_login_args*)args;
    VfxMainScr *scr;
    VcuiSsoLoginPage *page = NULL;
    
    VFX_OBJ_CREATE(scr, VfxMainScr, this);
    
    if (sso_login != NULL)
    {
        VFX_OBJ_CREATE_EX(page, VcuiSsoLoginPage, scr, (sso_login->provider, sso_login->accountId, VFX_TRUE, VFX_TRUE));
        scr->pushPage(VFX_ID_NULL, page);
    }

    scr->show();
#endif
}

#if defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)
VFX_IMPLEMENT_CLASS("VcuiSsoItemCell", VcuiSsoItemCell, VcpFormItemBase);

VcuiSsoItemCell::VcuiSsoItemCell() :
m_parent(NULL),
m_addAcc(VFX_FALSE),
m_need_signup(VFX_TRUE)
{
}

VcuiSsoItemCell::VcuiSsoItemCell(VfxPage *page, VfxBool addAcc, VfxBool need_signup) :
m_parent(page),
m_addAcc(addAcc),
m_need_signup(need_signup)
{
}

void VcuiSsoItemCell::onInit()
{
    VcpFormItemBase::onInit();
    m_login = NULL;
    m_signup = NULL;
    
    setSize(PAGE_WIDTH, VCPFRM_STD_UI_CNTRL_HEIGHT);
    VfxS32 y = (getSize().height - BUTTON_HEIGHT)/2;
    VFX_OBJ_CREATE(m_login, VcpButton, this);
    m_login->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    if (m_need_signup)
    {
        m_login->setPos(BUTTON_L_GAP, y);
    }
    else
    {
        m_login->setAnchor(0.5, 0);
        m_login->setPos(getSize().width/2, y);
    }
    m_login->setText(VFX_WSTR_RES(STR_ID_VCUI_SSO_LOGIN));
    m_login->setId(VcuiSsoLoginPage::ID_BUTTON_LOGIN);
    m_login->m_signalClicked.connect(m_parent, &VcuiSsoLoginPage::onClicked);
    m_login->setIsDisabled(m_addAcc);

    if (m_need_signup)
    {
        VFX_OBJ_CREATE(m_signup, VcpButton, this);
        m_signup->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
        m_signup->setPos((BUTTON_L_GAP+BUTTON_WIDTH+BUTTON_GAP), y);
        m_signup->setText(VFX_WSTR_RES(STR_ID_VCUI_SSO_SIGNUP));
        m_signup->setId(VcuiSsoLoginPage::ID_BUTTON_SIGNUP);
        m_signup->m_signalClicked.connect(m_parent, &VcuiSsoLoginPage::onClicked);
    }

    setHeight(VCPFRM_STD_UI_CNTRL_HEIGHT);
}

void VcuiSsoItemCell::disableLogin(VfxBool disable)
{
    if (m_login) m_login->setIsDisabled(disable);
}

VFX_IMPLEMENT_CLASS("VcuiSsoLoginPage", VcuiSsoLoginPage, VfxPage);

VcuiSsoLoginPage::VcuiSsoLoginPage() :
m_user(NULL),
m_accountId(0),
m_provider(0),
m_isCui(VFX_FALSE),
m_isSso(VFX_FALSE)
{
}

VcuiSsoLoginPage::VcuiSsoLoginPage(VfxU32 provider, VfxU8 accountId, VfxBool isSso, VfxBool isCui) :
m_user(NULL),
m_accountId(accountId),
m_provider(provider),
m_isCui(isCui),
m_isSso(isSso)
{
}

VcuiSsoLoginPage::VcuiSsoLoginPage(VfxU32 provider, VfxWChar *user, VfxBool isSso,VfxBool isCui) :
m_user((VfxChar*)user),
m_provider(provider),
m_isCui(isCui),
m_isSso(isSso)
{
}

void VcuiSsoLoginPage::onInit()
{
    VfxPage::onInit();
    m_processing = NULL;
    m_ignoreCB = VFX_FALSE;
    m_reqId = 0;
    m_oldAccName = NULL;

    if (m_isSso)
    {
        m_addAcc = (m_accountId != SRV_SSO_INVALID_ACC_ID)? VFX_FALSE : VFX_TRUE;
        if (m_accountId > 0)
        {
            /* Caller pass account id so to verify it. If it is a invalid account id, ex: non-existing , then it should be scenario "add account" */
            m_addAcc = VFX_TRUE;
        }
    }
    else
    {
        m_addAcc = VFX_TRUE;
    }
    //VFX_OBJ_CREATE(m_logo, VfxImageFrame, this);
    //m_logo->setSize(LOGO_WIDTH, LOGO_HEIGHT);
    //m_logo->setPos(LOGO_X, LOGO_Y);
    //m_logo->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setPos(0, 0);
    m_form->setSize(getSize().width, getSize().height);
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);


    VfxWString str;
    VcpFunctionBar *functionBar;
    VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
    str.loadFromRes(STR_GLOBAL_PREV);
    functionBar->addItem(ID_FUNC_BAR_PREV, str);
    str.loadFromRes(STR_GLOBAL_NEXT);
    functionBar->addItem(ID_FUNC_BAR_NEXT, str);
    str.loadFromRes(STR_ID_VCUI_SSO_LOGIN);
    functionBar->addItem(ID_FUNC_BAR_LOGIN, str);
    functionBar->setItemSpecial(ID_FUNC_BAR_LOGIN);
    functionBar->m_signalButtonTap.connect(this, &VcuiSsoLoginPage::onFunctionBarTap);

    VcpTextEditor *textEditor;
    VFX_OBJ_CREATE(m_account, VcpFormItemTextInput, m_form);
    m_account->setLabelPosition(VCPFORM_TOP_LEFT);
    m_account->setLabelText(VFX_WSTR_RES(STR_ID_VCUI_SSO_ACCOUNT));
    textEditor = m_account->getTextBox();
    //textEditor->setIME(IMM_INPUT_TYPE_ASCII_CHAR);
    textEditor->setIME(IMM_INPUT_TYPE_EMAIL);
    textEditor->setId(ID_ACCOUNT);
    textEditor->setMaxLength(64);
    textEditor->setAutoActivated(m_addAcc);
    textEditor->m_signalActivated.connect(this, &VcuiSsoLoginPage::onTextActivated);
    textEditor->m_signalTextChanged.connect(this, &VcuiSsoLoginPage::onTextChanged);
    textEditor->setFunctionBar((VfxFrame*)functionBar);
    m_form->addItem(m_account, ID_ACCOUNT);
#if defined(__MMI_SSO__)
    if (m_isSso)
    {
        if (m_addAcc)
        {
            functionBar->setDisableItem(ID_FUNC_BAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ID_FUNC_BAR_LOGIN, VFX_TRUE);
        }
        else
        {
            /* Get account from the valid account id to display on account editor */
            VFX_ALLOC_MEM(m_oldAccName, sizeof(VfxWChar)*(SRV_SSO_NAME_SIZE+1), this);
            memset(m_oldAccName, 0, sizeof(VfxWChar)*(SRV_SSO_NAME_SIZE+1));
            if (srv_sso_get_account_name(m_provider, m_accountId, (WCHAR*)m_oldAccName) == MMI_TRUE)
            {
                textEditor->setText(VFX_WSTR_MEM((VfxWChar*)m_oldAccName), SRV_SSO_NAME_SIZE);
            }
            functionBar->setDisableItem(ID_FUNC_BAR_NEXT, VFX_TRUE);
        }
    }
    else
#endif
    {
        if (m_user)
        {
            VfxChar *tmpStr = m_user;
            VfxS32 strlen = app_ucs2_strlen((const kal_int8*)tmpStr);
            VFX_ALLOC_MEM(m_user, (strlen+1)*sizeof(VfxWChar), this);
            memset(m_user, 0, (strlen+1)*sizeof(VfxWChar));
            app_ucs2_strncpy((kal_int8*)m_user, (const kal_int8*)tmpStr, strlen);
            m_account->setText(VFX_WSTR_MEM((VfxWChar*)m_user));
            functionBar->setDisableItem(ID_FUNC_BAR_NEXT, VFX_TRUE);
        }
        else
        {
            functionBar->setDisableItem(ID_FUNC_BAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ID_FUNC_BAR_LOGIN, VFX_TRUE);
        }
    }

    VFX_OBJ_CREATE(m_password, VcpFormItemTextInput, m_form);
    m_password->setLabelPosition(VCPFORM_TOP_LEFT);
    m_password->setLabelText(VFX_WSTR_RES(STR_GLOBAL_PASSWORD));
    textEditor = m_password->getTextBox();
    textEditor->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
    textEditor->setId(ID_PASSWORD);
    textEditor->setMaxLength(64);
    textEditor->setAutoActivated((m_account->getText().getLength() == 0)? VFX_FALSE : VFX_TRUE);
    textEditor->m_signalActivated.connect(this, &VcuiSsoLoginPage::onTextActivated);
    textEditor->m_signalTextChanged.connect(this, &VcuiSsoLoginPage::onTextChanged);
    textEditor->setFunctionBar((VfxFrame*)functionBar);
    m_form->addItem(m_password, ID_PASSWORD);

    VfxBool need_signup = m_isSso;
#ifndef BROWSER_SUPPORT
    need_signup = VFX_FALSE;
#endif
    VFX_OBJ_CREATE_EX(m_cell, VcuiSsoItemCell, m_form, (this, m_addAcc, need_signup));
    m_form->addItem(m_cell, ID_CELL);
#if defined(__MMI_SSO__)
    mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, VcuiSsoLoginPage::Listener, getObjHandle());
#endif
#if defined(__SOCIAL_NETWORK_SUPPORT__)
    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, VcuiSsoLoginPage::Listener, getObjHandle());
#endif
}

void VcuiSsoLoginPage::onDeinit()
{
    m_ignoreCB = VFX_TRUE;
#if defined(__MMI_SSO__)
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SSO_READY, VcuiSsoLoginPage::Listener, getObjHandle());
    if (m_isSso && m_reqId > 0)
    {
        srv_sso_cancel(m_reqId);
        m_reqId = 0;
    }
#endif
#if defined(__SOCIAL_NETWORK_SUPPORT__)
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, VcuiSsoLoginPage::Listener, getObjHandle());
    if (!m_isSso && m_reqId > 0)
    {
        srv_sns_cancel(m_reqId);
        m_reqId = 0;
    }
#endif

    if (m_oldAccName) VFX_FREE_MEM(m_oldAccName);
    if (m_user) VFX_FREE_MEM(m_user);

    VfxPage::onDeinit();
}

mmi_ret VcuiSsoLoginPage::Listener(mmi_event_struct* evt)
{
    VcuiSsoLoginPage *pThis = (VcuiSsoLoginPage*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if (pThis != NULL)
    {
        pThis->handleListener(evt);
    }
    return MMI_RET_OK;
}

void VcuiSsoLoginPage::handleListener(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
    #ifdef __SOCIAL_NETWORK_SUPPORT__
        case EVT_ID_SRV_SNS_READY:
        {
            srv_sns_evt_ready_struct* sns_evt = (srv_sns_evt_ready_struct*)evt;
            if (!sns_evt->is_ready)
            {
                if (m_isCui)
                    notifyCaller(VCUI_SSO_LOGIN_CANCEL, sns_evt->result);
                else
                    exit();
            }
            break;
        }
    #endif
    #ifdef __MMI_SSO__
        case EVT_ID_SRV_SSO_READY:
        {
            srv_sso_evt_ready_struct* sso_evt = (srv_sso_evt_ready_struct*)evt;
            if (!sso_evt->is_ready)
            {
                if (m_isCui)
                    notifyCaller(VCUI_SSO_LOGIN_CANCEL, sso_evt->reason);
                else
                    exit();
            }
            break;
        }
    #endif
    }
}

void VcuiSsoLoginPage::onBack()
{
    notifyCaller(VCUI_SSO_LOGIN_CANCEL, 0);
}

void VcuiSsoLoginPage::onExit(VfxBool isBackward)
{
#ifndef __MMI_SSO_BACKGROUND_LOGIN__
    if (m_reqId > 0)
    {
        /* cancel login or logout */
        if (!m_isSso)
        {
        #if defined(__SOCIAL_NETWORK_SUPPORT__)
            srv_sns_cancel(m_reqId);
        #endif
        }
        else
        {
        #if defined(__MMI_SSO__)
            srv_sso_cancel(m_reqId);
        #endif
        }
    }
    m_reqId = 0;
    if (m_processing != NULL)
    {
        VFX_OBJ_CLOSE(m_processing);
    }
#endif
}

void VcuiSsoLoginPage::queryLoginInfo(VfxU32 *providerId, VfxU8 *accountId, VfxBool *isSso)
{
    (*providerId) = m_provider;
    (*accountId) = m_accountId;
    (*isSso) = m_isSso;
}

void VcuiSsoLoginPage::notifyCaller(vcui_sso_login_result_enum result, VfxS32 err)
{
    if (m_isCui)
    {
        VfxCui *cui = (VfxCui*)getApp();
        if (cui != NULL)
        {
            /* post event to callser */
            vcui_sso_login_result_event_struct evt;

            memset(&evt, 0, sizeof(vcui_sso_login_result_event_struct));
            evt.evt_id = EVT_ID_VCUI_SSO_LOGIN_RESULT;
            evt.size = sizeof(evt);
            evt.user_data = NULL;
            evt.sender_id = cui->getGroupId();
            evt.result = result;
            evt.accountId = m_accountId;
            evt.providerId = m_provider;
            evt.err = err;
            
            cui->postToCaller((mmi_group_event_struct*)&evt);
        }
    }
    else
    {
        m_signalLoginCb.postEmit((VfxPage*)this, result, err);
    }
}

void VcuiSsoLoginPage::onTextActivated(VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
        switch (sender->getId())
        {
            case ID_ACCOUNT:
            {
                /* Disable prev */
                VcpFunctionBar *functionBar = (VcpFunctionBar*)sender->getFunctionBar();
                functionBar->setDisableItem(ID_FUNC_BAR_PREV, VFX_TRUE);
                functionBar->setDisableItem(ID_FUNC_BAR_NEXT, VFX_FALSE);
                break;
            }
            case ID_PASSWORD:
            {
                if (app_ucs2_strncmp((kal_int8*)sender->getText(), (const kal_int8*)SSO_PW_MASK_STR.getBuf(), SSO_PW_MASK_STR.getLength()) == 0)
                {
                    sender->deleteAll();
                }
                /* Disable next */
                VcpFunctionBar *functionBar = (VcpFunctionBar*)sender->getFunctionBar();
                functionBar->setDisableItem(ID_FUNC_BAR_PREV, VFX_FALSE);
                functionBar->setDisableItem(ID_FUNC_BAR_NEXT, VFX_TRUE);
                break;
            }
        }
    }
}

void VcuiSsoLoginPage::onTextChanged(VcpTextEditor *sender)
{
    VcpFunctionBar *functionBar = (VcpFunctionBar*)sender->getFunctionBar();
    if (!m_account->getText().isEmpty() && !m_password->getText().isEmpty())
    {
        /* Enable login on function bar and toolbar */
        functionBar->setDisableItem(ID_FUNC_BAR_LOGIN, VFX_FALSE);
        m_cell->disableLogin(VFX_FALSE);
    }
    else
    {
        /* Disable login on function bar and toolbar */
        functionBar->setDisableItem(ID_FUNC_BAR_LOGIN, VFX_TRUE);
        m_cell->disableLogin(VFX_TRUE);
    }
}


void VcuiSsoLoginPage::onFunctionBarTap(VfxObject *sender, VfxId id)
{
    switch (id)
    {
        case ID_FUNC_BAR_PREV:
        {
            /* Active account editor */
            VcpTextEditor *textEdit;
            textEdit = m_account->getTextBox();
            textEdit->activate();

            /* Disable prev */
            VcpFunctionBar *functionBar = (VcpFunctionBar*)sender;
            functionBar->setDisableItem(ID_FUNC_BAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ID_FUNC_BAR_NEXT, VFX_FALSE);
            break;
        }
        
        case ID_FUNC_BAR_NEXT:
        {
            /* Active password editor */
            VcpTextEditor *textEdit;
            textEdit = m_password->getTextBox();
            textEdit->activate();

            /* Disable next */
            VcpFunctionBar *functionBar = (VcpFunctionBar*)sender;
            functionBar->setDisableItem(ID_FUNC_BAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ID_FUNC_BAR_NEXT, VFX_TRUE);
            break;
        }
        
        case ID_FUNC_BAR_LOGIN:
        {
            login();
            break;
        }
        default:
            break;
    }
}

void VcuiSsoLoginPage::onSsoLoginCb(S32 reg_id, srv_sso_result result, U32 provider, U8 account, void *userdata)
{
    VcuiSsoLoginPage *pThis = (VcuiSsoLoginPage*)VfxObject::handleToObject((VfxObjHandle)userdata);
    if (pThis != NULL)
    {
        pThis->handleSsoLoginCb(result, provider, account);
    }
}

void VcuiSsoLoginPage::handleSsoLoginCb(srv_sso_result result, U32 provider, U8 account)
{
    m_reqId = 0;
    
    if (result == SRV_SSO_OK)
    {
        m_account->getTextBox()->setIsDisabled(VFX_TRUE);
        m_cell->disableLogin(VFX_TRUE);;
        VcpFunctionBar *functionBar = (VcpFunctionBar*)m_password->getTextBox()->getFunctionBar();
        functionBar->setDisableItem(ID_FUNC_BAR_LOGIN, VFX_TRUE);
        m_password->getTextBox()->deactivate();
        if (m_addAcc)
        {
            m_accountId = account;
            notifyCaller(VCUI_SSO_LOGIN_ADD_SUCCESS, result);
        }
        else
            notifyCaller(VCUI_SSO_LOGIN_SUCCESS, result);
    }
    else
    {
        if (!m_isSso)
        {
        #if defined(__SOCIAL_NETWORK_SUPPORT__)
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(srv_sns_get_error_string(result)));
        #endif
        }
        else
        {
        #if defined(__MMI_SSO__)
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(srv_sso_get_error_string(result)));
        #endif
        }
        if (result == SRV_SSO_CANCELLED)
        {
            notifyCaller(VCUI_SSO_LOGIN_CANCEL, 0);
        }
        else
        {
            if (m_addAcc)
                notifyCaller(VCUI_SSO_LOGIN_ADD_FAIL, result);
            else
                notifyCaller(VCUI_SSO_LOGIN_FAIL, result);
        }
    }

    if (!m_ignoreCB && m_processing != NULL)
    {
        VFX_OBJ_CLOSE(m_processing);
    }
}

mmi_ret VcuiSsoLoginPage::onLoginCb(mmi_event_struct *param)
{
    VcuiSsoLoginPage *pThis = (VcuiSsoLoginPage*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    if (pThis != NULL)
    {
        pThis->handleLoginCb(param);
    }
    return MMI_RET_OK;
}

void VcuiSsoLoginPage::handleLoginCb(mmi_event_struct *param)
{
    m_reqId = 0;
  
    srv_sns_evt_result_struct *evt = (srv_sns_evt_result_struct *)param;
    
    if (evt->result == SRV_SNS_OK)
    {
        m_account->getTextBox()->setIsDisabled(VFX_TRUE);
        m_cell->disableLogin(VFX_TRUE);;
        VcpFunctionBar *functionBar = (VcpFunctionBar*)m_password->getTextBox()->getFunctionBar();
        functionBar->setDisableItem(ID_FUNC_BAR_LOGIN, VFX_TRUE);
        m_password->getTextBox()->deactivate();
        /* TODO: check it is add account or login account */
        notifyCaller(VCUI_SSO_LOGIN_SUCCESS, evt->result);
    }
    else
    {
        if (!m_isSso)
        {
        #if defined(__SOCIAL_NETWORK_SUPPORT__)
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(srv_sns_get_error_string(evt->result)));
        #endif
        }
        else
        {
        #if defined(__MMI_SSO__)
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(srv_sso_get_error_string(evt->result)));
        #endif
        }
        if (evt->result == SRV_SNS_CANCELLED)
        {
            notifyCaller(VCUI_SSO_LOGIN_CANCEL, evt->result);
        }
        else
        {
            notifyCaller(VCUI_SSO_LOGIN_FAIL, evt->result);
        }
    }

    if (!m_ignoreCB && m_processing != NULL)
    {
        VFX_OBJ_CLOSE(m_processing);
    }
}

void VcuiSsoLoginPage::doLogin(VfxWString account, VfxWString password)
{
    VfxS32 reqId = 0;
    
    if (!m_isSso)
    {
    #if defined(__SOCIAL_NETWORK_SUPPORT__)
        reqId = srv_sns_login(m_provider, (WCHAR*)account.getBuf(), (WCHAR*)password.getBuf(), VcuiSsoLoginPage::onLoginCb, getObjHandle());
    #endif
    }
    else
    {
    #if defined(__MMI_SSO__)
        /* Case SSO */
        if (m_addAcc)
        {
            reqId = srv_sso_add_account(m_provider, (WCHAR*)account.getBuf(), (WCHAR*)password.getBuf(), VcuiSsoLoginPage::onSsoLoginCb, getObjHandle());
        }
        else
        {
            reqId = srv_sso_login_account(m_provider, m_accountId, (WCHAR*)password.getBuf(), VcuiSsoLoginPage::onSsoLoginCb, getObjHandle());
        }
    #endif
    }
    if (reqId > 0)
    {
        m_reqId = reqId;
        showProcessingPop(VFX_WSTR_RES(STR_ID_VCUI_SSO_LOGGINGIN));
    }
    else
    {
        if (!m_isSso)
        {
        #if defined(__SOCIAL_NETWORK_SUPPORT__)
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(srv_sns_get_error_string(reqId)));
        #endif
        }
        else
        {
        #if defined(__MMI_SSO__)
            /* Case SSO */
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(srv_sso_get_error_string(reqId)));
        #endif
        }
    }
}

void VcuiSsoLoginPage::onDelAccCb(S32 reg_id, srv_sso_result result, void *userdata)
{
    VcuiSsoLoginPage *pThis = (VcuiSsoLoginPage*)VfxObject::handleToObject((VfxObjHandle)userdata);
    if (pThis != NULL)
    {
        pThis->handleDelAccCb(result);
    }
}

void VcuiSsoLoginPage::handleDelAccCb(srv_sso_result result)
{
#if defined(__MMI_SSO__)
    if (result == SRV_SSO_OK)
    {
        VfxWString account = m_account->getText();
        VfxWString password = m_password->getText();
        doLogin(account, password);
    }
    else
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(srv_sso_get_error_string(result)));
    }
#endif
}

void VcuiSsoLoginPage::login()
{
    VfxS32 reqId = 0;
    
    VfxWString account = m_account->getText();
    VfxWString password = m_password->getText();
#if defined(__MMI_SSO__)
    VfxWString old_account = VFX_WSTR_MEM((VfxWChar*)m_oldAccName);
    if (m_isSso && !m_addAcc && old_account != account)
    {
        /* Delete old account */
        srv_sso_del_account(m_provider, m_accountId, VcuiSsoLoginPage::onDelAccCb, getObjHandle());
        m_addAcc = VFX_TRUE;
    }
    else
#endif
    {
        doLogin(account, password);
    }    
}

void VcuiSsoLoginPage::showProcessingPop(VfxWString str)
{
    if (m_processing == NULL)
    {
        VFX_OBJ_CREATE(m_processing, VcpIndicatorPopup, this);
        m_processing->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        m_processing->setText(str);
        m_processing->m_signalCanceled.connect(this, &VcuiSsoLoginPage::onCancelProcessing);
        m_processing->setAutoDestory(VFX_FALSE);
        m_processing->show(VFX_TRUE);
    }
}

void VcuiSsoLoginPage::onCancelProcessing(VfxObject *obj, VfxFloat processing)
{
    if (m_reqId > 0)
    {
        /* cancel login or logout */
        if (!m_isSso)
        {
        #if defined(__SOCIAL_NETWORK_SUPPORT__)
            srv_sns_cancel(m_reqId);
        #endif
        }
        else
        {
        #if defined(__MMI_SSO__)
            srv_sso_cancel(m_reqId);
        #endif
        }
    }
    m_reqId = 0;
    if (m_processing != NULL)
    {
        VFX_OBJ_CLOSE(m_processing);
    }
}

void VcuiSsoLoginPage::onClicked(VfxObject* obj, VfxId id)
{
    VfxS8 i = 0;
    switch(id)
    {
        case ID_BUTTON_LOGIN:
            login();
            break;
        case ID_BUTTON_SIGNUP:
        {
        #if defined(BROWSER_SUPPORT) && defined(__MMI_SSO__)
            VfxChar *buffer;
            VFX_ALLOC_MEM(buffer, SRV_SSO_URL_SIZE, this);
            memset(buffer, 0, SRV_SSO_URL_SIZE);
            if (srv_sso_get_provider_signup_url(m_provider, (WCHAR*)buffer))
            {
                wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)buffer);
            }
            VFX_FREE_MEM(buffer);
        #endif
            break;
        }
    }
}
#endif
#endif /* __COSMOS_MMI__ */
