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
 *  vapp_sso.cpp
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
 *
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#if defined(__COSMOS_MMI__) && defined(__MMI_SSO__)
#include "vapp_sso_prot.h"
#include "vcui_sso_prot.h"
#include "mmi_rp_vcui_sso_setting_def.h"
#include "mmi_rp_vapp_sns_sso_common_def.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_rp_vapp_sso_def.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#include "vapp_usb_gprot.h"
#include "mmi_rp_vapp_usbmmi_def.h"
#endif
#include "FileMgrSrvGprot.h"
#include "app_str.h"
#include "mmi_rp_srv_sso_def.h"
#ifdef __cplusplus
}
#endif

mmi_ret vapp_sso_create_wizard(mmi_event_struct *param)
{
    U8 temp;
    S16 error;
    vapp_sso_wizard_args arg;

    ReadValue(NVRAM_SSO_WIZARD_FLAG, &temp, DS_BYTE, &error);
    if(error == NVRAM_READ_SUCCESS && temp == 0)
    {
        if (srv_sso_get_provider_count() == 1)
        {
            srv_sso_provider_struct sso_provider;
            memset(&sso_provider, 0, sizeof(srv_sso_provider_struct));
            srv_sso_get_providers(&sso_provider, 1);
            memset(&arg, 0, sizeof(vapp_sso_wizard_args));
            arg.provider = sso_provider.provider;
            arg.accountId = SRV_SSO_INVALID_ACC_ID;
            VfxAppLauncher::launch( 
                VAPP_SSO,
                VFX_OBJ_CLASS_INFO(VappSso),
                GRP_ID_ROOT,
                &arg,
                sizeof(vapp_sso_wizard_args));
        }
        temp = 1;
        WriteValue(NVRAM_SSO_WIZARD_FLAG, &temp, DS_BYTE, &error);
    }
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_sso_upgrade_result_handler(mmi_event_struct *param)
{
    srv_sso_evt_plugins_upgraded_struct *upgradeEvt = (srv_sso_evt_plugins_upgraded_struct *)param;

    VAPP_SSO_TRACE1(TRC_MMI_VAPP_SSO_694dbd1b11d54306ae7a3036975e9734, upgradeEvt->is_successful);

    VfxWString string = VFX_WSTR_RES(STR_ID_VAPP_SSO_UPDATED);

    if (upgradeEvt->is_successful == MMI_FALSE)
    {
        string = VFX_WSTR_RES(STR_ID_VAPP_SSO_FAILED_TO_UPDATED);
    }

    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, string.getBuf());

    return MMI_RET_OK;
}

static mmi_ret vapp_sso_close_page(mmi_event_struct *evt, VfxPage *page)
{
    if (page != NULL)
    {
        switch (evt->evt_id)
        {
        #ifdef __MMI_USB_SUPPORT__
            case EVT_ID_USB_ENTER_MS_MODE:
            {
                VAPP_SSO_TRACE0(TRC_MMI_VAPP_SSO_434fcb37a3954c649a606a505a6d6809);
                vapp_usb_unavailable_popup(0);
                page->exit();
                break;
            }
        #endif
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            {
                VAPP_SSO_TRACE0(TRC_MMI_VAPP_SSO_ee426a0ec141409da85ed000328424aa);
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(STR_ID_VAPP_SSO_NO_MEMORY_CARD));
                page->exit();
                break;    
            }
            case EVT_ID_SRV_SSO_READY:
            {
                srv_sso_evt_ready_struct* sso_evt = (srv_sso_evt_ready_struct*)evt;
                if (!sso_evt->is_ready)
                {
                    VAPP_SSO_TRACE0(TRC_MMI_VAPP_SSO_7b0cd8f126af4117bc86bd3b0aa126eb);
                    page->exit();
                }
                break;
            }
        }
    }

    return MMI_RET_OK;
}

VFX_IMPLEMENT_CLASS("VappSso", VappSso, VfxApp);

void VappSso::onInit()
{
    VfxApp::onInit();

    mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, VappSso::Listener, getObjHandle());
}

void VappSso::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SSO_READY, VappSso::Listener, getObjHandle());

    VfxApp::onDeinit();
}

mmi_ret VappSso::Listener(mmi_event_struct* evt)
{
    VappSso *pThis = (VappSso*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if (pThis != NULL)
    {
        pThis->handleListener(evt);
    }
    return MMI_RET_OK;
}

void VappSso::handleListener(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SSO_READY:
        {
            srv_sso_evt_ready_struct* sso_evt = (srv_sso_evt_ready_struct*)evt;
            if (!sso_evt->is_ready)
            {
                exit();
            }
            break;
        }
    }
}

void VappSso::onRun(void * args,VfxU32 argSize)
{
    vapp_sso_wizard_args *sso_wizard = (vapp_sso_wizard_args*)args;
    m_provider = sso_wizard->provider;
    m_account = sso_wizard->accountId;

    VcuiSsoLoginPage *page = NULL;
    VFX_OBJ_CREATE(m_scr, VfxMainScr, this);
    
    VFX_OBJ_CREATE_EX(page, VcuiSsoLoginPage, m_scr, (m_provider, m_account, VFX_TRUE, VFX_FALSE));
    page->m_signalLoginCb.connect(this, &VappSso::onLoginCb);
    m_scr->pushPage(VFX_ID_NULL, page);
    m_scr->show();
}

void VappSso::onLoginCb(VfxPage *page, vcui_sso_login_result_enum result, VfxS32 err)
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
        #if defined(SSO_SUPPORT_CONTACTS) || defined(SSO_SUPPORT_SMS)
            VappSsoBackupRestorePage *page;

            VFX_OBJ_CREATE_EX(page, VappSsoBackupRestorePage, m_scr, (m_provider, accountId, VFX_FALSE, VFX_TRUE));
            m_scr->pushPage(VFX_ID_NULL, page);
        #endif
            break;
         }
    }
}

VFX_IMPLEMENT_CLASS("VappSsoAccountPage", VappSsoAccountPage, VfxPage);

VappSsoAccountPage::VappSsoAccountPage() :
m_provider(0),
m_accountId(0)
{
}

VappSsoAccountPage::VappSsoAccountPage(VfxU32 provider, VfxU8 accountId) :
m_provider(provider),
m_accountId(accountId)
{
}

void VappSsoAccountPage::onInit()
{
    VfxPage::onInit();

    m_reqId = 0;
    m_form = NULL;
    m_backup = NULL;
    m_restore = NULL;
    m_logout = NULL;
    m_processing = NULL;

    /* Title bar */
    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    VfxChar *buffer = NULL;
    VfxWString service;
    VFX_ALLOC_MEM(buffer, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar), this);
    memset(buffer, 0, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar));
    if (srv_sso_get_provider_name(m_provider, (WCHAR*)buffer) == MMI_TRUE)
    {
        service = VFX_WSTR_MEM((VfxWChar*)buffer);
        title->setTitle(service);
    }
    setTopBar(title);
    
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setBounds(0, 0, getSize().width, getSize().height);
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VfxWString text;
#if defined(SSO_SUPPORT_CONTACTS) || defined(SSO_SUPPORT_SMS)
    /* Create backup cell */
    VFX_OBJ_CREATE(m_backup, VcpFormItemLauncherCell, m_form);
    text = VFX_WSTR_RES(STR_ID_VCUI_SSO_BACKUP_TO);
    if (buffer) text += service;
    m_backup->setMainText(text);
    m_backup->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_backup->m_signalTap.connect(this, &VappSsoAccountPage::onItemTap);
    m_form->addItem(m_backup, ID_SSO_BACKUP);

    /* Create restore cell */
    VFX_OBJ_CREATE(m_restore, VcpFormItemLauncherCell, m_form);
    m_restore->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    text = VFX_WSTR_RES(STR_ID_VCUI_SSO_RESTORE_FROM);
    if (buffer) text += service;
    m_restore->setMainText(text);
    m_restore->m_signalTap.connect(this, &VappSsoAccountPage::onItemTap);
    m_form->addItem(m_restore, ID_SSO_RESTORE);
#endif
    /* Create logout cell */
    VFX_OBJ_CREATE(m_logout, VcpFormItemLauncherCell, m_form);
    m_logout->setMainText(VFX_WSTR_RES(STR_ID_VCUI_SSO_LOGOUT));
    memset(buffer, 0, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar));
    if (srv_sso_get_account_name(m_provider, m_accountId, (WCHAR*)buffer) != MMI_TRUE)
    {
        VFX_FREE_MEM(buffer);
    }
    if (buffer) m_logout->setHintText(VFX_WSTR_MEM((VfxWChar*)buffer));
    m_logout->m_signalTap.connect(this, &VappSsoAccountPage::onItemTap);
    m_form->addItem(m_logout, ID_SSO_LOGOUT);
    VFX_FREE_MEM(buffer);

    mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, VappSsoAccountPage::Listener, getObjHandle());
}

void VappSsoAccountPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SSO_READY, VappSsoAccountPage::Listener, getObjHandle());
    if (m_reqId > 0)
    {
        srv_sso_cancel(m_reqId);
        m_reqId = 0;
    }
    VfxPage::onDeinit();
}

mmi_ret VappSsoAccountPage::Listener(mmi_event_struct* evt)
{
    VappSsoAccountPage *pThis = (VappSsoAccountPage*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    return vapp_sso_close_page(evt, pThis);
}

void VappSsoAccountPage::onItemTap(VcpFormItemCell* cell, VfxId cell_id)
{
#if defined(__CLOUD_SUPPORT__)
    VappSsoBackupRestorePage *page;
#endif
    VfxMainScr *scr = getMainScr();

    switch (cell_id)
    {
    #if defined(SSO_SUPPORT_CONTACTS) || defined(SSO_SUPPORT_SMS)
        case ID_SSO_BACKUP:
        {
            VFX_OBJ_CREATE_EX(page, VappSsoBackupRestorePage, scr, (m_provider, m_accountId, VFX_TRUE, VFX_FALSE));
            scr->pushPage(VFX_ID_NULL, page);
            break;
        }
        case ID_SSO_RESTORE:
        {
            VFX_OBJ_CREATE_EX(page, VappSsoBackupRestorePage, scr, (m_provider, m_accountId, VFX_FALSE, VFX_FALSE));
            scr->pushPage(VFX_ID_NULL, page);
            break;
        }
    #endif
        case ID_SSO_LOGOUT:
        {
            VfxS32 reqId = 0;
            reqId = srv_sso_logout_account(m_provider, m_accountId, &VappSsoAccountPage::onSsoLogoutCb, getObjHandle());
            if (reqId > 0)
            {
                m_reqId = reqId;
                showProcessingPop(VFX_WSTR_RES(STR_ID_VCUI_SSO_LOGGINGOUT));
            }
            break;
        }
    };
}

void VappSsoAccountPage::onSsoLogoutCb(S32 reg_id, srv_sso_result result, void *userdata)
{
    VappSsoAccountPage *pThis = (VappSsoAccountPage*)VfxObject::handleToObject((VfxObjHandle)userdata);
    if (pThis != NULL)
    {
        pThis->handleSsoLogoutCb(result);
    }
}

void VappSsoAccountPage::handleSsoLogoutCb(srv_sso_result result)
{
    m_reqId = 0;
    
    if (result == SRV_SNS_OK)
    {
        exit();
    }
    else
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(srv_sso_get_error_string(result)));
    }

    if (m_processing)
    {
        VFX_OBJ_CLOSE(m_processing);
    }
}

void VappSsoAccountPage::showProcessingPop(VfxWString str)
{
    if (m_processing == NULL)
    {
        VFX_OBJ_CREATE(m_processing, VcpIndicatorPopup, this);
        m_processing->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        m_processing->setText(str);
        m_processing->m_signalCanceled.connect(this, &VappSsoAccountPage::onCancelProcessing);
        m_processing->setAutoDestory(VFX_FALSE);
        m_processing->show(VFX_TRUE);
    }
}

void VappSsoAccountPage::onCancelProcessing(VfxObject *obj, VfxFloat processing)
{
    if (m_reqId > 0)
    {
        /* cancel login or logout */
        srv_sso_cancel(m_reqId);
    }
    m_reqId = 0;
    VFX_OBJ_CLOSE(m_processing);
}

#if defined(__CLOUD_SUPPORT__)
VFX_IMPLEMENT_CLASS("VappSsoBackupRestorePage", VappSsoBackupRestorePage, VfxPage);

VappSsoBackupRestorePage* VappSsoBackupRestorePage::m_context = NULL;

VappSsoBackupRestorePage::VappSsoBackupRestorePage() :
m_provider(0),
m_accountId(0),
m_wizard(VFX_FALSE),
m_isBackup(VFX_TRUE)
{
}

VappSsoBackupRestorePage::VappSsoBackupRestorePage(VfxU32 provider, VfxU8 accountId, VfxBool isBackup, VfxBool wizard) :
m_provider(provider),
m_accountId(accountId),
m_wizard(wizard),
m_isBackup(isBackup)
{
}

void VappSsoBackupRestorePage::onInit()
{
    VfxPage::onInit();

    m_context = this;
    m_serviceName = NULL;
    m_list = NULL;
    m_phbHdlr = 0;
    m_smsHdlr = SRV_SMS_INVALID_HANDLE;
    m_processing = NULL;
    m_phbErr = SRV_PHB_NO_ERROR;
    m_smsErr = SRV_SMS_CAUSE_NO_ERROR;
    /* Default selected all */
    m_selected = 0;
    m_done = 0;

    VFX_ALLOC_MEM(m_serviceName, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar), this);
    memset(m_serviceName, 0, (SRV_SSO_NAME_SIZE+1)*sizeof(VfxWChar));
    if (srv_sso_get_provider_name(m_provider, (WCHAR*)m_serviceName) != MMI_TRUE)
    {
        VFX_FREE_MEM(m_serviceName);
    }
    /* Title bar */
    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    /* TODO: Get title from provider id */
    if (m_serviceName) title->setTitle(VFX_WSTR_MEM((VfxWChar*)m_serviceName));
    setTopBar(title);
    
    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION);
    VfxRect rect(0, 0, getSize().width, getSize().height);
    m_list->setBounds(rect);
    m_list->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->m_signalItemTapped.connect(this, &VappSsoBackupRestorePage::onItemTapped);
    m_list->setContentProvider(this);

    /* TODO: Query the count via provider id */
#if defined(SSO_SUPPORT_CONTACTS) && defined(SSO_SUPPORT_SMS)
    m_appCount = 2;
#else
    m_appCount = 1;
#endif

    VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
    if (m_isBackup)
    {
        m_toolbar->addItem(ID_SSO_TOOLBAR_BACKUP, VFX_WSTR_RES(STR_ID_VCUI_SSO_TOOLBAR_BACKUP), IMG_ID_VAPP_SSO_TOOLBAR_BACKUP);
        m_toolbar->setDisableItem(ID_SSO_TOOLBAR_BACKUP, VFX_TRUE);
    }
    else
    {
        m_toolbar->addItem(ID_SSO_TOOLBAR_RESTORE, VFX_WSTR_RES(STR_ID_VCUI_SSO_TOOLBAR_RESTORE), IMG_ID_VAPP_SSO_TOOLBAR_RESTORE);
        m_toolbar->setDisableItem(ID_SSO_TOOLBAR_RESTORE, VFX_TRUE);
    }
    m_toolbar->addItem(ID_SSO_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolbar->m_signalButtonTap.connect(this, &VappSsoBackupRestorePage::onMenuButtonTap);
    setBottomBar(m_toolbar);

    mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, VappSsoBackupRestorePage::Listener, getObjHandle());
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, VappSsoBackupRestorePage::Listener, getObjHandle());
#endif
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappSsoBackupRestorePage::Listener, getObjHandle());
}

void VappSsoBackupRestorePage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SSO_READY, VappSsoBackupRestorePage::Listener, getObjHandle());
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, VappSsoBackupRestorePage::Listener, getObjHandle());
#endif
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappSsoBackupRestorePage::Listener, getObjHandle());

    if (m_serviceName) VFX_FREE_MEM(m_serviceName);
    cancelBackRestore();
    m_context = NULL;
    VAPP_SSO_TRACE0(TRC_MMI_VAPP_SSO_4ddd93cb669348898ca049e24d9632a9);
    VfxPage::onDeinit();
}

void* VappSsoBackupRestorePage::onAsmMallocCB(VfxU32 size)
{
    VfxU8 *buffer = NULL;
    VAPP_SSO_TRACE2(TRC_MMI_VAPP_SSO_10ebfaa16aeb4b479d7a27a3d576d5e7, (m_context != NULL)? 1 : 0, size);
    if (m_context)
    {
        buffer = m_context->handleAsmMallocCB(size);
    }
    return buffer;
}

U8* VappSsoBackupRestorePage::handleAsmMallocCB(VfxU32 size)
{
    VfxU8 *buffer = NULL;
    mmi_id group_id = getApp()->getGroupId();

    buffer = (U8*)applib_asm_alloc_r(group_id, size);
    return buffer;
}

void VappSsoBackupRestorePage::onAsmFreeCB(void* ptr)
{
    VAPP_SSO_TRACE1(TRC_MMI_VAPP_SSO_abc8d61cceed464a802d3f4ebc64b937, (m_context != NULL)? 1 : 0);
    if (m_context)
    {
        m_context->handleAsmFreeCB(ptr);
    }
}

void VappSsoBackupRestorePage::handleAsmFreeCB(void* ptr)
{
    mmi_id group_id = getApp()->getGroupId();
    if (ptr) applib_asm_free_r(group_id, ptr);
}

mmi_ret VappSsoBackupRestorePage::Listener(mmi_event_struct* evt)
{
    VappSsoBackupRestorePage *pThis = (VappSsoBackupRestorePage*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    return vapp_sso_close_page(evt, pThis);
}

VfxBool VappSsoBackupRestorePage::getItemText(
    VfxU32 index,                   // [IN] the index of item
    VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
    VfxWString &text,               // [OUT] the text resource
    VcpListMenuTextColorEnum &color // [OUT] the text color
    ) 
{
    VfxBool result = VFX_FALSE;
    /* TODO: query supportted App via provider id */
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        switch (index)
        {
        #ifdef SSO_SUPPORT_CONTACTS
            case ID_CLOUD_CONTACTS:
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_CONTACTS);
                break;
        #endif
        #ifdef SSO_SUPPORT_SMS
            case ID_CLOUD_SMS:
                text = VFX_WSTR_RES(STR_GLOBAL_SMS);
                break;
        #endif
        }
        return VFX_TRUE;
    }
    return result;
}

VcpListMenuItemStateEnum VappSsoBackupRestorePage::getItemState(VfxU32 index) const
{
    if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, index))
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

VfxU32 VappSsoBackupRestorePage::getCount() const 
{
    return m_appCount;
}

void VappSsoBackupRestorePage::onItemTapped(VcpListMenu *list_menu, VfxU32 index)
{
    if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, index))
    {
        SSO_BACKUP_RESTORE_SELECTED_CLEAR(m_selected, index);
    }
    else
    {
        SSO_BACKUP_RESTORE_SELECTED_SET(m_selected, index);
    }

    VfxBool disable = VFX_TRUE;
    VfxU32 i = 0;
    while (i < m_appCount)
    {
        if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, i))
        {
            disable = VFX_FALSE;
            break;
        }
        i++;
    }
    if (m_isBackup)
        m_toolbar->setDisableItem(ID_SSO_TOOLBAR_BACKUP, disable);
    else
        m_toolbar->setDisableItem(ID_SSO_TOOLBAR_RESTORE, disable);
}

#ifdef SSO_SUPPORT_CONTACTS
void VappSsoBackupRestorePage::onPhbBackupCb(srv_phb_async_op_cb_struct* info)
{
    VappSsoBackupRestorePage *pThis = (VappSsoBackupRestorePage*)VfxObject::handleToObject((VfxObjHandle)info->user_data);
    if (pThis != NULL)
    {
        pThis->handlePhbBackupCb(info);
    }
}

void VappSsoBackupRestorePage::handlePhbBackupCb(srv_phb_async_op_cb_struct* info)
{
    srv_phb_backup_cb_struct* phb = (srv_phb_backup_cb_struct *)info;
    VAPP_SSO_TRACE4(TRC_MMI_VAPP_SSO_d9297b4e495542ceb351a112022cd9c0, (phb->handle == m_phbHdlr)? 1 : 0, phb->type, phb->result, m_done);
    if (phb->handle == m_phbHdlr && phb->type == SRV_PHB_OP_CB_TYPE_BACKUP)
    {
        if (m_done > 0) m_done--;
        m_phbHdlr = 0;
        m_phbErr = phb->result;

        if (m_done == 0)
        {
            showErrorMsg();

            if (m_processing != NULL) VFX_OBJ_CLOSE(m_processing);
        }
    }
}

void VappSsoBackupRestorePage::onPhbRestoreCb(srv_phb_async_op_cb_struct* info)
{
    VappSsoBackupRestorePage *pThis = (VappSsoBackupRestorePage*)VfxObject::handleToObject((VfxObjHandle)info->user_data);
    if (pThis != NULL)
    {
        pThis->handlePhbRestoreCb(info);
    }
}

void VappSsoBackupRestorePage::handlePhbRestoreCb(srv_phb_async_op_cb_struct* info)
{
    srv_phb_restore_cb_struct* phb = (srv_phb_backup_cb_struct *)info;
    VAPP_SSO_TRACE4(TRC_MMI_VAPP_SSO_52eecb35d4524d0290f3e7334f1e87c7, (phb->handle == m_phbHdlr)? 1 : 0, phb->type, phb->result, m_done);
    if (phb->handle == m_phbHdlr && phb->type == SRV_PHB_OP_CB_TYPE_RESTORE)
    {
        if (m_done > 0) m_done--;
        m_phbHdlr = 0;
        m_phbErr = phb->result;

        if (m_done == 0)
        {
            showErrorMsg();

            if (m_processing != NULL) VFX_OBJ_CLOSE(m_processing);
        }
    }
}

#endif

#ifdef SSO_SUPPORT_SMS
void VappSsoBackupRestorePage::onSmsBackupCb(srv_sms_callback_struct* callback_data)
{
    VappSsoBackupRestorePage *pThis = (VappSsoBackupRestorePage*)VfxObject::handleToObject((VfxObjHandle)callback_data->user_data);
    if (pThis != NULL)
    {
        pThis->handleSmsBackupCb(callback_data);
    }
}

void VappSsoBackupRestorePage::handleSmsBackupCb(srv_sms_callback_struct* callback_data)
{
    VAPP_SSO_TRACE4(TRC_MMI_VAPP_SSO_b1fd1b5d34c9445f85b891afbede7edd, callback_data->action, callback_data->result, callback_data->cause, m_done);
    if (m_done > 0) m_done--;
    m_smsHdlr = SRV_SMS_INVALID_HANDLE;
    if (!callback_data->result && callback_data->action == SRV_SMS_ACTION_BACKUP) m_smsErr = callback_data->cause;

    if (m_done == 0)
    {
        showErrorMsg();

        if (m_processing != NULL) VFX_OBJ_CLOSE(m_processing);
    }
}

void VappSsoBackupRestorePage::onSmsRestoreCb(srv_sms_callback_struct* callback_data)
{
    VappSsoBackupRestorePage *pThis = (VappSsoBackupRestorePage*)VfxObject::handleToObject((VfxObjHandle)callback_data->user_data);
    if (pThis != NULL)
    {
        pThis->handleSmsRestoreCb(callback_data);
    }
}

void VappSsoBackupRestorePage::handleSmsRestoreCb(srv_sms_callback_struct* callback_data)
{
    VAPP_SSO_TRACE4(TRC_MMI_VAPP_SSO_a084df4b549846a685024e494fc88078, callback_data->action, callback_data->result, callback_data->cause, m_done);
    if (m_done > 0) m_done--;
    m_smsHdlr = SRV_SMS_INVALID_HANDLE;
    if (!callback_data->result && callback_data->action == SRV_SMS_ACTION_RESTORE) m_smsErr = callback_data->cause;

    if (m_done == 0)
    {
        showErrorMsg();

        if (m_processing != NULL) VFX_OBJ_CLOSE(m_processing);
    }
}

#endif

void VappSsoBackupRestorePage::showErrorMsg()
{
    if ((m_phbErr == SRV_PHB_NO_ERROR) && (m_smsErr == SRV_SMS_CAUSE_NO_ERROR)) return;

    VcpConfirmPopup *popup;
    VfxWString text;

    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setAutoDestory(VFX_TRUE);

    /* Check error code "No need to sync" */
    if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, ID_CLOUD_CONTACTS) && SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, ID_CLOUD_SMS))
    {
        /* Both apps */
        if (m_phbErr == SRV_PHB_CLOUD_NO_NEED_SYNC && m_smsErr == SRV_SMS_CAUSE_CLOUD_NO_NEED_SYNC)
        {
            if (m_isBackup)
            {
                text = VFX_WSTR_RES(STR_ID_VAPP_SSO_NO_APP_DATA_TO_BACKUP);
            }
            else
            {
                text = VFX_WSTR_RES(STR_ID_VAPP_SSO_NO_APP_DATA_TO_RESTORE);
            }
        }
        else if (m_phbErr == SRV_PHB_CLOUD_NO_NEED_SYNC)
        {
            m_phbErr = SRV_PHB_NO_ERROR;
        }
        else if (m_smsErr == SRV_SMS_CAUSE_CLOUD_NO_NEED_SYNC)
        {
            m_smsErr = SRV_SMS_CAUSE_NO_ERROR;
        }

        if ((m_phbErr == SRV_PHB_NO_ERROR) && (m_smsErr == SRV_SMS_CAUSE_NO_ERROR)) return;
    }
    else if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, ID_CLOUD_CONTACTS))
    {
        /* Contacts */
        if (m_phbErr == SRV_PHB_CLOUD_NO_NEED_SYNC)
        {
            if (m_isBackup)
            {
                text = VFX_WSTR_RES(STR_ID_VAPP_SSO_NO_APP_DATA_TO_BACKUP);
            }
            else
            {
                text = VFX_WSTR_RES(STR_ID_VAPP_SSO_NO_APP_DATA_TO_RESTORE);
            }
        }
    }
    else if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, ID_CLOUD_SMS))
    {
        /* SMS*/
        if (m_smsErr == SRV_SMS_CAUSE_CLOUD_NO_NEED_SYNC)
        {
            if (m_isBackup)
            {
                text = VFX_WSTR_RES(STR_ID_VAPP_SSO_NO_APP_DATA_TO_BACKUP);
            }
            else
            {
                text = VFX_WSTR_RES(STR_ID_VAPP_SSO_NO_APP_DATA_TO_RESTORE);
            }
        }
    }

    if (text.isEmpty() || text.isNull())
    {
        if (m_phbErr == SRV_PHB_STORAGE_FULL || m_phbErr == SRV_PHB_CLOUD_DISK_FULL)
        {
            /* Both error */
            if (m_isBackup)
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_PHB_INSUFFICIENT_STORAGE);
            }
            else
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_PHB_RESTORE_ERR);
            }
        }
        else if (m_smsErr == SRV_SMS_CAUSE_MEM_FULL || m_smsErr == SRV_SMS_CAUSE_CLOUD_DISK_FULL)
        {
            if (m_isBackup)
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_SMS_INSUFFICIENT_STORAGE);
            }
            else
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_SMS_RESTORE_ERR);
            }
        }
        else if (m_smsErr == SRV_SMS_CAUSE_CLOUD_NO_STORAGE || m_phbErr == SRV_PHB_CLOUD_NO_STORAGE)
        {
            text = VFX_WSTR_RES(STR_ID_VAPP_SSO_NO_MEMORY_CARD);
        }
        else if (m_smsErr == SRV_SMS_CAUSE_CLOUD_NWK_ERROR || m_phbErr == SRV_PHB_CLOUD_NETWORK_ERROR)
        {
            text = VFX_WSTR_RES(STR_ID_VAPP_SSO_NO_NETWORK_CONNECTION);
        }
        else if (m_phbErr < 0 && m_smsErr != SRV_SMS_CAUSE_NO_ERROR)
        {
            if (m_isBackup)
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_PHB_AND_SMS_BACKUP_ERR);
            }
            else
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_PHB_AND_SMS_RESTORE_ERR);
            }
        }
        else if (m_phbErr < 0)
        {
            if (m_isBackup)
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_PHB_BACKUP_ERR);
            }
            else
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_PHB_RESTORE_ERR);
            }
        }
        else if (m_smsErr != SRV_SMS_CAUSE_NO_ERROR)
        {
            if (m_isBackup)
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_SMS_BACKUP_ERR);
            }
            else
            {
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_SMS_RESTORE_ERR);
            }
        }
        else
        {
            /* Should get error string from service */
            text = VFX_WSTR_RES(STR_GLOBAL_FAILED);
        }
    }
    popup->setText(text);
    popup->show(VFX_TRUE);
}

void VappSsoBackupRestorePage::showProcessing(VfxWString &str)
{
    if (m_processing == NULL)
    {
        VFX_OBJ_CREATE(m_processing, VcpIndicatorPopup, this);
        m_processing->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        m_processing->setText(str);
        m_processing->m_signalCanceled.connect(this, &VappSsoBackupRestorePage::onCancel);
        m_processing->setAutoDestory(VFX_FALSE);
        m_processing->show(VFX_TRUE);
    }
}

void VappSsoBackupRestorePage::cancelBackRestore()
{
    VAPP_SSO_TRACE0(TRC_MMI_VAPP_SSO_c67db25d34664584b931aa3a4c6689b5);
#ifdef SSO_SUPPORT_CONTACTS
    /* Cancel backup/restore contacts */
    srv_phb_free_handle(m_phbHdlr);
    m_phbHdlr = 0;
#endif
#ifdef SSO_SUPPORT_SMS
    srv_sms_abort_cloud(m_smsHdlr, NULL, NULL);
    m_smsHdlr = SRV_SMS_INVALID_HANDLE;
#endif
    if (m_processing != NULL) VFX_OBJ_CLOSE(m_processing);
}

void VappSsoBackupRestorePage::onCancel(VfxObject *obj, VfxFloat processing)
{
    cancelBackRestore();
}

void VappSsoBackupRestorePage::onMenuButtonTap(VfxObject *sender, VfxId id)
{
    VfxWString text;
    switch (id)
    {
        case ID_SSO_TOOLBAR_BACKUP:
        {
            m_done = 0;
        #ifdef SSO_SUPPORT_CONTACTS
            if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, ID_CLOUD_CONTACTS))
            {
                /* backup contacts */
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_BACKUP_PHB_POP);
                srv_phb_backup_req_struct req;
                memset(&req, 0, sizeof(srv_phb_backup_req_struct));
                req.account = m_accountId;
                req.provider = m_provider;
                req.storage = PHB_STORAGE_NVRAM;
                req.mode = SRV_PHB_BACKUP_RESTORE_MODE_CLOUD;
                req.user_data = getObjHandle();
                req.cb = &VappSsoBackupRestorePage::onPhbBackupCb;
                req.malloc_func = &VappSsoBackupRestorePage::onAsmMallocCB;
                req.free_func = &VappSsoBackupRestorePage::onAsmFreeCB;
                m_phbHdlr = srv_phb_backup_contact(&req);
                if (m_phbHdlr != NULL) m_done++;
            }
        #endif
        #ifdef SSO_SUPPORT_SMS
            if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, ID_CLOUD_SMS))
            {
                /* backup SMS */
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_BACKUP_SMS_POP);
                srv_sms_backup_restore_info_struct restore_info;
                srv_cloud_set_opt_acct_info_struct account_info;
    
                memset(&restore_info, 0, sizeof(srv_sms_backup_restore_info_struct));
                memset(&account_info, 0, sizeof(srv_cloud_set_opt_acct_info_struct));
                restore_info.account_info = &account_info;
                /* now only inbox */
                restore_info.box_type = SRV_SMS_BOX_INBOX;
                restore_info.backup_restore_type = SRV_SMS_BACKUP_RESTORE_CLOUD;
                restore_info.account_info->account_id = m_accountId;
                restore_info.account_info->provider = m_provider;
                m_smsHdlr = srv_sms_backup_msg(restore_info, &VappSsoBackupRestorePage::onSmsBackupCb, getObjHandle());
                if (m_smsHdlr != NULL) m_done++;
            }
        #endif
            if (m_done == 2) text = VFX_WSTR_RES(STR_ID_VCUI_SSO_BACKUP_PHB_SMS_POP);
            //text += VFX_WSTR_MEM((VfxWChar*)m_serviceName);
            showProcessing(text);
            break;
        }
        case ID_SSO_TOOLBAR_RESTORE:
        {
            m_done = 0;
        #ifdef SSO_SUPPORT_CONTACTS
            if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, ID_CLOUD_CONTACTS))
            {
                /* restore contacts */
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_RESTORE_PHB_POP);
                srv_phb_restore_req_struct req;
                memset(&req, 0, sizeof(srv_phb_restore_req_struct));
                req.cb = &VappSsoBackupRestorePage::onPhbRestoreCb;
                req.provider = m_provider;
                req.account = m_accountId;
                req.user_data = getObjHandle();
                req.mode = SRV_PHB_BACKUP_RESTORE_MODE_CLOUD;
                req.malloc_func = &VappSsoBackupRestorePage::onAsmMallocCB;
                req.free_func = &VappSsoBackupRestorePage::onAsmFreeCB;
                m_phbHdlr = srv_phb_restore_contact(&req);
                if (m_phbHdlr != NULL) m_done++;
            }
        #endif
        #ifdef SSO_SUPPORT_SMS
            if (SSO_BACKUP_RESTORE_SELECTED_IS_SET(m_selected, ID_CLOUD_SMS))
            {
                /* restore SMS */
                text = VFX_WSTR_RES(STR_ID_VCUI_SSO_RESTORE_SMS_POP);
                srv_sms_backup_restore_info_struct restore_info;
                srv_cloud_set_opt_acct_info_struct account_info;

                memset(&restore_info, 0, sizeof(srv_sms_backup_restore_info_struct));
                memset(&account_info, 0, sizeof(srv_cloud_set_opt_acct_info_struct));
                /* now only inbox */
                restore_info.account_info = &account_info;
                restore_info.box_type = SRV_SMS_BOX_INBOX;
                restore_info.backup_restore_type = SRV_SMS_BACKUP_RESTORE_CLOUD;
                restore_info.account_info->account_id = m_accountId;
                restore_info.account_info->provider = m_provider;
                m_smsHdlr = srv_sms_restore_msg(restore_info, &VappSsoBackupRestorePage::onSmsRestoreCb, getObjHandle());
                if (m_smsHdlr != NULL) m_done++;
            }
        #endif
            if (m_done == 2) text = VFX_WSTR_RES(STR_ID_VCUI_SSO_RESTORE_PHB_SMS_POP);
            //text += VFX_WSTR_MEM((VfxWChar*)m_serviceName);
            showProcessing(text);
            break;
        }
        case ID_SSO_TOOLBAR_CANCEL:
        {
            exit();
            break;
        }
    }
}
#endif
#endif /* __COSMOS_MMI__ */
