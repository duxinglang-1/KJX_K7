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
 *  vapp_sso_sns_account_setting.cpp
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
#include "vapp_sso_sns_account_setting.h"
#include "mmi_rp_vapp_sns_sso_common_def.h"
#endif
#if defined(__MMI_SSO__)
#include "vapp_sso_prot.h"
#endif

#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#include "mmi_rp_vapp_usbmmi_def.h"
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
#ifdef __MMI_SSO__
#include "SsoSrvGprot.h"
#endif
#include "Browser_api.h"
#if defined(__SOCIAL_NETWORK_SUPPORT__)
#include "mmi_rp_vapp_sns_def.h"
#include "mmi_rp_srv_sns_def.h"
#endif
#if defined(__MMI_SSO__)
#include "mmi_rp_srv_sso_def.h"    
#endif
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#ifdef __cplusplus
}
#endif

mmi_ret vapp_sns_settings_close_page(mmi_event_struct *evt, VfxPage *page)
{
    if (page != NULL)
    {
        switch (evt->evt_id)
        {
        #ifdef __SOCIAL_NETWORK_SUPPORT__
            case EVT_ID_SRV_SNS_READY:
            {
                srv_sns_evt_ready_struct* sns_evt = (srv_sns_evt_ready_struct*)evt;
                if (!sns_evt->is_ready)
                {
                    page->exit();
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
                    page->exit();
                }
                break;
            }
        #endif
        }
    }

    return MMI_RET_OK;
}


#ifdef __MMI_SSO__
VFX_IMPLEMENT_CLASS("VappSsoAccountsCell",VappSsoAccountsCell,VcpFormItemCell);

VappSsoAccountsCell::VappSsoAccountsCell()
{
}

VappSsoAccountsCell::VappSsoAccountsCell(srv_sso_account_struct *account)
{
    m_ssoAccount = NULL;

    if (account)
    {
        VFX_ALLOC_MEM(m_ssoAccount, sizeof(srv_sso_account_struct), this);
        memcpy((void*)m_ssoAccount, (const void*)account, sizeof(srv_sso_account_struct));
    }
}

void VappSsoAccountsCell::ssoInit()
{
    VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
    VfxWChar *icon = srv_sso_get_provider_icon(m_ssoAccount->provider, SRV_SSO_ICON_SMALL);
    if (m_ssoAccount != NULL && icon != NULL)
    {
        m_icon->setImgContent(VfxImageSrc(VFX_WSTR_MEM(icon)));
    }

    if (m_icon)
    {
        m_icon->setRect(VfxRect(IMG_LEFT_GAPS, (getBounds().getHeight() - m_icon->getBounds().getHeight()) / 2,
                                      IMG_MAX_WIDTH, m_icon->getRect().getHeight()));

        m_icon->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                               VFX_FRAME_ALIGNER_MODE_SIDE,
                               VFX_FRAME_ALIGNER_MODE_SIDE,
                               VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    VfxChar *buffer = NULL;
    VFX_ALLOC_MEM(buffer, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar), this);
    memset(buffer, 0, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar));
    if (m_ssoAccount)
    {
        srv_sso_get_provider_name(m_ssoAccount->provider, (WCHAR*)buffer);
        setMainText(VFX_WSTR_MEM((VfxWChar*)buffer));
        m_mainText->setFont(VfxFontDesc(FONT_SIZE_MAIN, VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    }

    memset(buffer, 0, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar));
    if (srv_sso_get_account_name(m_ssoAccount->provider, m_ssoAccount->account, (WCHAR*)buffer) == MMI_TRUE)
    {
        setHintText(VFX_WSTR_MEM((VfxWChar*)buffer));
        m_hintText->setFont(VfxFontDesc(FONT_SIZE_HINT, VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    }
    VFX_FREE_MEM(buffer);

    if (!m_ssoAccount->is_login)
    {
        /* Disable icon */
        m_icon->setOpacity(0.5);
    }
    
    if (m_mainText)
    {
        m_mainText->setPos((TEXT1_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH), m_mainText->getPos().y);
    }

    if (m_hintText)
    {
        m_hintText->setPos((TEXT1_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH), m_hintText->getPos().y);
    }
}

void VappSsoAccountsCell::updateAccount(srv_sso_account_struct *account)
{
    if (account)
    {
        if (m_ssoAccount == NULL)
        {
            VFX_ALLOC_MEM(m_ssoAccount, sizeof(srv_sso_account_struct), this);
        }
        memcpy((void*)m_ssoAccount, (const void*)account, sizeof(srv_sso_account_struct));
    }
    else
    {
        VFX_FREE_MEM(m_ssoAccount);
    }
}

srv_sso_account_struct* VappSsoAccountsCell::getSsoAccount()
{
    return m_ssoAccount;
}

void VappSsoAccountsCell::onInit()
{
    m_mainText = NULL;
    m_hintText = NULL;

    VcpFormItemCell::onInit();
    
    m_icon = NULL;
    m_sync = NULL;
    m_doingSync = NULL;

    if (m_ssoAccount) ssoInit();
}

void VappSsoAccountsCell::onDeinit(void)
{
    if (m_ssoAccount) VFX_FREE_MEM(m_ssoAccount);
    VcpFormItemCell::onDeinit();
}

void VappSsoAccountsCell::onCellTap(VfxPenEvent &event)
{
    VcpFormItemCell::onCellTap(event);
    if(getIsDisabled())
    {
        return;
    }
    if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_signalTap.postEmit(this, m_id);
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        m_signalLongTap.postEmit(this, m_id);
    }    
}

void VappSsoAccountsCell::update(void)
{
    if (m_ssoAccount)
    {
        VfxChar* buffer = NULL;
        VFX_ALLOC_MEM(buffer, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar), this);
        memset(buffer, 0, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar));
        if (srv_sso_get_account_name(m_ssoAccount->provider, m_ssoAccount->account, (WCHAR*)buffer) == MMI_TRUE)
        {
            setHintText(VFX_WSTR_MEM((VfxWChar*)buffer));
            m_hintText->setFont(VfxFontDesc(FONT_SIZE_HINT, VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        }
        else
        {
            /* Destory hint text */
            setHintText(VFX_WSTR_NULL);
        }
        VFX_FREE_MEM(buffer);
        if (m_ssoAccount->is_login)
        {
            /* If account has logged */
            m_icon->setOpacity(1);
        }
        else
        {
            /* No account or user has logged out */
            m_icon->setOpacity(0.5);
        }
    }
}
#endif

#if defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)

VFX_IMPLEMENT_CLASS("VappAccountsSettingsPage", VappAccountsSettingsPage, VfxPage);

VappAccountsSettingsPage::VappAccountsSettingsPage()
{
}

VappAccountsSettingsPage::VappAccountsSettingsPage(VfxBool sns_only) :
m_sns_only(sns_only)
{
}

VappAccountsSettingsPage *VappAccountsSettingsPage::m_self = NULL;

mmi_ret VappAccountsSettingsPage::Listener(mmi_event_struct* evt)
{
    VappAccountsSettingsPage *pThis = (VappAccountsSettingsPage*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    return vapp_sns_settings_close_page(evt, pThis);
}

void VappAccountsSettingsPage::refresh()
{
    if (m_form)
    {
        VFX_OBJ_CLOSE(m_form);
    }

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setBounds(0, 0, getSize().width, getSize().height);
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    
    VfxS32 i = 0;
#ifdef __SOCIAL_NETWORK_SUPPORT__
    VappAccountsCell *cell = NULL;
    /* Get account by using getAccount, is_login is VFX_FALSE, category is SNS_PLUGIN_FEATURE_ANY, feature is 0 */
    m_listId = srv_sns_get_accounts(SRV_SNS_LOGIN_DONT_CARE, SRV_SNS_FEATURE_ANY, 0, &m_accCount);
    if (m_listId > 0)
    {
        srv_sns_account_struct *a;
        while(i < m_accCount)
        {
            srv_sns_get_item(m_listId, i, (void**)&a);
            VFX_OBJ_CREATE_EX(cell, VappAccountsCell, m_form, (a));
            cell->setId((i+1));
            cell->m_signalTap.connect(this, &VappAccountsSettingsPage::onItemTap);
            m_form->addItem(cell, (i+1));
            i++;
        }
    }
    VAPP_SNS_TRACE1(TRC_SNS_7b6ff5cb18ef43068245cbf998ca7ad2, m_accCount);
#endif
#ifdef __MMI_SSO__
    if (!m_sns_only)
    {
        m_ssoCount = srv_sso_get_provider_count();
        srv_sso_provider_struct *sso_provider;
        VFX_ALLOC_MEM(sso_provider, sizeof(srv_sso_provider_struct)*m_ssoCount, this);
        memset(sso_provider, 0, sizeof(srv_sso_provider_struct)*m_ssoCount);
        srv_sso_get_providers(sso_provider, m_ssoCount);
        i = 0;
        srv_sso_account_struct sso_account;
        VfxU8 account_num = 0;
        while(i < m_ssoCount)
        {
            memset(&sso_account, 0, sizeof(srv_sso_account_struct));
            if (sso_provider[i].accounts_total > 0)
            {
                account_num = srv_sso_get_accounts(sso_provider[i].provider, SRV_SSO_LOGIN_DONT_CARE, &sso_account, 1);
            }
            else
            {
                sso_account.provider = sso_provider[i].provider;
                sso_account.account = SRV_SSO_ACCOUNTS_PER_PROVIDER;
            }
            VappSsoAccountsCell *sso_cell;
            VFX_OBJ_CREATE_EX(sso_cell, VappSsoAccountsCell, m_form, (&sso_account));
            sso_cell->setId((i+m_accCount+1));
            sso_cell->m_signalTap.connect(this, &VappAccountsSettingsPage::onItemTap);
            m_form->addItem(sso_cell, (i+m_accCount+1));
            i++;
        }
        VFX_FREE_MEM(sso_provider);
        mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, VappAccountsSettingsPage::Listener, getObjHandle());
        VAPP_SSO_TRACE1(TRC_MMI_VAPP_SSO_7b6ff5cb18ef43068245cbf998ca7ad2, m_ssoCount);
    }
#endif
}

void VappAccountsSettingsPage::onInit()
{
    VfxPage::onInit();
#if defined(__SOCIAL_NETWORK_SUPPORT__)
    VAPP_SNS_TRACE1(TRC_SNS_1f5242836b7a46a8b6987f293803b1bd, 7);
    srv_sns_enter_app();
#endif
    m_self = this;
    m_form = NULL;
    m_ssoCount = 0;
    m_accCount = 0;
    m_listId = 0;
    /* Init is manual */
    m_intervalId = 6;

    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    title->setTitle(VFX_WSTR_RES(STR_ID_VAPP_ACCOUNTS_SETTINGS));
    setTopBar(title);
    
    refresh();

#ifdef __MMI_SSO__
    if (!m_sns_only)
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, VappAccountsSettingsPage::Listener, getObjHandle());
    }
#endif
    
#ifdef __SOCIAL_NETWORK_SUPPORT__
    VcpToolBar *toolbar;
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    toolbar->addItem(ID_SYNC_INTERVAL, VFX_WSTR_RES(STR_ID_VAPP_SNS_SYNCINTERVAL), IMG_ID_VAPP_SSO_TOOLBAR_SYNCINTERVAL);
    toolbar->m_signalButtonTap.connect(this, &VappAccountsSettingsPage::onMenuButtonTap);
    setBottomBar(toolbar);

    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_PROCESS_COMPLETE, &VappAccountsSettingsPage::onEvtHdlr, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, VappAccountsSettingsPage::Listener, getObjHandle());
#endif
}

void VappAccountsSettingsPage::onDeinit(void)
{
#ifdef __SOCIAL_NETWORK_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_PROCESS_COMPLETE, &VappAccountsSettingsPage::onEvtHdlr, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, VappAccountsSettingsPage::Listener, getObjHandle());
    srv_sns_release_list(m_listId, MMI_FALSE);
    m_listId = 0;
    VAPP_SNS_TRACE1(TRC_SNS_9ce1295c3be9428aa0964c907fa87290, 7);
    srv_sns_exit_app();
#endif
#ifdef __MMI_SSO__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SSO_READY, VappAccountsSettingsPage::Listener, getObjHandle());
#endif
    m_self = NULL;
    VfxPage::onDeinit();
}

void VappAccountsSettingsPage::onExited(void)
{
#ifdef __SOCIAL_NETWORK_SUPPORT__
    srv_sns_release_list(m_listId, MMI_FALSE);
    m_listId = 0;
#endif
    VfxPage::onExited();
}

void VappAccountsSettingsPage::onEnter(VfxBool isBackWard)
{
    VfxPage::onEnter(isBackWard);

    if (isBackWard)
    {
        refresh();
    }
}

mmi_ret VappAccountsSettingsPage::onEvtHdlr(mmi_event_struct *param)
{
    if (m_self != NULL)
    {
        m_self->handleEvtHdlr(param);
    }
    return MMI_RET_OK;
}

void VappAccountsSettingsPage::handleEvtHdlr(mmi_event_struct *param)
{
#ifdef __SOCIAL_NETWORK_SUPPORT__
    if (param->evt_id == EVT_ID_SRV_SNS_PROCESS_COMPLETE)
    {
        srv_sns_evt_process_start_struct *evt = (srv_sns_evt_process_start_struct *)param;
        if (evt->type == SRV_SNS_BKGD_PROCESS_SYNC_FRIENDS||
            evt->type == SRV_SNS_BKGD_PROCESS_SYNC_CALENDAR)
        {
            VfxS32 i = 0;
            for (i = 0; i < m_accCount; i++)
            {
                VappAccountsCell* accCell = (VappAccountsCell*)m_form->getItem((i+1));
                if (accCell)
                {
                    accCell->update();
                }
            }
        }
    }
#endif
}

VfxChar* VappAccountsSettingsPage::getProfileId(VfxS32 index)
{
    VfxChar *profileId = NULL;

    return profileId;
}

void VappAccountsSettingsPage::onMenuButtonTap(VfxObject *sender, VfxId id)
{
#ifdef __SOCIAL_NETWORK_SUPPORT__
    switch (id)
    {
        case ID_SYNC_INTERVAL:
            selectSyncInterval();
            break;
    }
#endif
}


void VappAccountsSettingsPage::onItemTap(VcpFormItemCell* cell, VfxId cell_id)
{
    switch (cell_id)
    {
        default:
        {
            if (cell_id > 0)
            {
                if (cell_id <= m_accCount)
                {
                #ifdef __SOCIAL_NETWORK_SUPPORT__
                    /* SNS cell */
                    VappAccountsCell* accCell = (VappAccountsCell*)cell;
                    srv_sns_account_struct* account = accCell->getAccount();
                    /* If the account is syncing, prompt user that he can't enter account setup page currently */
                    if (srv_sns_is_syncing_friends(account->provider) ||
                        srv_sns_is_syncing_calendar(account->provider))
                    {
                        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE));
                    }
                    else
                    {
                        if (srv_sns_is_login(account->provider))
                        {
                            VappAccountSetupPage *page;

                            VfxMainScr *scr = getMainScr();
                            VFX_OBJ_CREATE_EX(page, VappAccountSetupPage, scr, (account->provider, account->login_id, account->name, account->sync_contacts, account->sync_calendar));
                            scr->pushPage(VFX_ID_NULL, page);
                        }
                        else
                        {
                            VcuiSsoLoginPage *page;
                            VfxMainScr *scr = getMainScr();
                            VFX_OBJ_CREATE_EX(page, VcuiSsoLoginPage, scr, (account->provider, account->login_id, VFX_FALSE, VFX_FALSE));
                            page->m_signalLoginCb.connect(this, &VappAccountsSettingsPage::onLoginCb);
                            scr->pushPage(VFX_ID_NULL, page);
                        }
                    }
                #endif
                }
                else
                {
                #ifdef __MMI_SSO__
                    /* SSO cell */
                    VappSsoAccountsCell* accCell = (VappSsoAccountsCell*)cell;
                    srv_sso_account_struct* account = accCell->getSsoAccount();
                    if (account->is_login)
                    {
                        VappSsoAccountPage *page;

                        VfxMainScr *scr = getMainScr();
                        VFX_OBJ_CREATE_EX(page, VappSsoAccountPage, scr, (account->provider, account->account));
                        scr->pushPage(VFX_ID_NULL, page);
                    }
                    else
                    {
                        VcuiSsoLoginPage *page;
                        VfxMainScr *scr = getMainScr();
                        VFX_OBJ_CREATE_EX(page, VcuiSsoLoginPage, scr, (account->provider, account->account, VFX_TRUE, VFX_FALSE));
                        page->m_signalLoginCb.connect(this, &VappAccountsSettingsPage::onLoginCb);
                        scr->pushPage(VFX_ID_NULL, page);
                    }
                #endif
                }
            }
            break;
        }
    };
}

void VappAccountsSettingsPage::onLoginCb(VfxPage *page, vcui_sso_login_result_enum result, VfxS32 err)
{
    switch (result)
    {
        case VCUI_SSO_LOGIN_CANCEL:
        {
            page->exit();
            break;
        }
        case VCUI_SSO_LOGIN_ADD_SUCCESS:
        case VCUI_SSO_LOGIN_SUCCESS:
        {
            
            VcuiSsoLoginPage *loginPage = (VcuiSsoLoginPage*)page;
            VfxBool isSso = VFX_FALSE;
            VfxU32 providerId;
            VfxU8 accountId;
            loginPage->queryLoginInfo(&providerId, &accountId, &isSso);
            page->exit();
            refresh();
            if (!isSso)
            {
            #ifdef __SOCIAL_NETWORK_SUPPORT__
                /* SNS cell */
                /* Get account structure from provider id */
                srv_sns_account_struct account;
                memset(&account, 0, sizeof(srv_sns_account_struct));
                if (srv_sns_get_account(providerId, &account) == SRV_SNS_OK)
                {
                    VappAccountSetupPage *accpage;

                    VfxMainScr *scr = getMainScr();
                    VFX_OBJ_CREATE_EX(accpage, VappAccountSetupPage, scr, (account.provider, account.login_id, account.name, account.sync_contacts, account.sync_calendar));
                    scr->pushPage(VFX_ID_NULL, accpage);
                }
            #endif
            }
            else
            {
            #ifdef __MMI_SSO__
                /* SSO cell */
            #if defined(__CLOUD_SUPPORT__)
                if (result == VCUI_SSO_LOGIN_ADD_SUCCESS ||
                    result == VCUI_SSO_LOGIN_SUCCESS)
                {
                    VappSsoAccountPage *accpage;

                    VfxMainScr *scr = getMainScr();
                    VFX_OBJ_CREATE_EX(accpage, VappSsoAccountPage, scr, (providerId, accountId));
                    scr->pushPage(VFX_ID_NULL, accpage);
                }
            #endif /* __CLOUD_SUPPORT__ */
            #endif /* __MMI_SSO__ */
            }
            break;
         }
    }
}

void VappAccountsSettingsPage::selectSyncInterval(void)
{
#ifdef __SOCIAL_NETWORK_SUPPORT__
    VfxMainScr *scr = getMainScr();

    if (scr != NULL)
    {
        VappSyncIntervalPage *page;
        VfxU32 value = SRV_SNS_SYNC_INTERVAL_MANUAL;
        VfxU32 index = 0;

        srv_sns_get_global_setting(SRV_SNS_SETTING_SYNC_INTERVAL, &value);
        VfxWString text;
        index = VappSyncIntervalPage::secToIndex((srv_sns_sync_interval_enum)value, text);
        VFX_OBJ_CREATE_EX(page, VappSyncIntervalPage, scr, (index));
        scr->pushPage(VFX_ID_NULL, page);
    }
#endif
}

/* Only used in global settings */
extern "C" void vapp_sns_accouts_setting_cell(VfxMainScr *mainScr)
{
    VappAccountsSettingsPage *page;
    MMI_BOOL sns_ready = MMI_FALSE;
    MMI_BOOL sso_ready = MMI_FALSE;
    VfxBool showMsErr = VFX_FALSE;
    VfxS32  sso_err = 0;
    VfxS32  sns_err = 0;
#if defined(__MMI_SSO__)
    sso_ready = srv_sso_is_ready();
    sso_err = srv_sso_get_ready();
#endif
#if defined(__SOCIAL_NETWORK_SUPPORT__)
    sns_ready = srv_sns_is_ready();
    sns_err = srv_sns_get_ready();
#endif

    if (!sns_ready && !sso_ready)
    {
    #if defined(__MMI_SSO__) && defined(__SOCIAL_NETWORK_SUPPORT__)
        if (sns_err == SRV_SNS_USB_MS_MODE && sso_err == SRV_SSO_USB_MS_MODE)
        {
            showMsErr = VFX_TRUE;
        }
    #elif defined(__MMI_SSO__)
        if (sso_err == SRV_SSO_USB_MS_MODE)
        {
            showMsErr = VFX_TRUE;
        }
    #elif defined(__SOCIAL_NETWORK_SUPPORT__)
        if (sns_err == SRV_SNS_USB_MS_MODE)
        {
            showMsErr = VFX_TRUE;
        }
    #endif
        if (showMsErr)
        {
            /* Show mass storage mode general error string */
            #ifdef __MMI_USB_SUPPORT__
                vapp_usb_unavailable_popup(0);
            #endif
        }
        else
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE));
        }
        return;
    }
    VFX_OBJ_CREATE_EX(page, VappAccountsSettingsPage, mainScr, (VFX_FALSE));

    mainScr->pushPage(VFX_ID_NULL, page);
}

#endif /* defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__) */
#endif /* __COSMOS_MMI__ */
