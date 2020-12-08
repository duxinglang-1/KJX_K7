/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_launcher.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the launcher APP.
 *
 * Author:
 * -------
 * -------
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

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "BootupSrvGprot.h"
#include "IdleGprot.h"                      // Pluto Adapter: Idle
#include "IdleNotificationManagerGprot.h"   // Pluto Adapter: Idle NMGR
}

//
// Framework:
//
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"

//
// Widget
//
#include "vapp_widget_system.h"

//
// Launcher
//
#include "vapp_launcher.h"
#include "vapp_launcher_primitive.h"
#include "vapp_launcher_kit.h"
#include "vapp_launcher_system.h"
#include "vapp_launcher_setting_provider.h"
#include "vapp_launcher_heap.h"
#include "vapp_launcher_app.h"
#include "vapp_launcher_gprot.h"
#include "vapp_launcher_mem_cfg.h"
#include "mmi_rp_vapp_launcher_def.h"

//
// Misc.
//
#include "vapp_platform_context.h"
#include "vapp_wallpaper.h"
#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_setting_method_gprot.h"

// force prepare fg memory when enter Launcher app
#include "vadp_asm.h"


/*****************************************************************************
 * Launcher APP
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherApp", VappLauncherApp, VfxApp);


VappLauncherApp::VappLauncherApp()
{
    // Do nothing.
}


void VappLauncherApp::onRun(void *args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // force prepare fg memory when enter Launcher app
    VadpAsmProperty p;
    VadpAsm::getProperty(getGroupId(), p);
    p.f_prepare_w_reserve = 1;
    VadpAsm::setProperty(getGroupId(), p);

    VappLauncherScreen *mainScr;
    VFX_OBJ_CREATE(mainScr, VappLauncherScreen, this);

    VappWallpaper *wallpaper = VappWallpaperKit::createWallpaperWithoutSetup(this, VAPP_WALLPAPER_SRC_HOMESCREEN);
    if(wallpaper->getVrtMemFactor() == 0)
    {
        mainScr->setVrtCacheSize(VAPP_LAUNCHER_VRT_CACHE_LIMIT);
    }
    else
    {
        mainScr->setVrtCacheSize(wallpaper->getVrtMemFactor());
    }
    VFX_OBJ_CLOSE(wallpaper);

    mainScr->show();
}


void VappLauncherApp::onGroupTopActive()
{
    VfxApp::onGroupTopActive();

    emitEventActive();

    m_signalActive.emit(VFX_FALSE);
}


void VappLauncherApp::onGroupTopInactive()
{
    m_signalInactive.emit(VFX_FALSE);

    emitEventInactive();

    VfxApp::onGroupTopInactive();
}


void VappLauncherApp::onGroupSnapshotActive()
{
    VfxApp::onGroupSnapshotActive();

    // Only emit internal signal. Do not emit the event for external APP because
    // this is a background redrewing for "small screen goes back" case. We do
    // not consider launcher App is active or inactive in this case.
    m_signalActive.emit(VFX_TRUE);
}


void VappLauncherApp::onGroupSnapshotInactive()
{
    // Only emit internal signal. Do not emit the event for external APP because
    // this is a background redrewing for "small screen goes back" case. We do
    // not consider launcher App is active or inactive in this case.
    m_signalInactive.emit(VFX_TRUE);

    VfxApp::onGroupSnapshotInactive();
}


void VappLauncherApp::emitEventActive()
{
    vapp_launcher_active_evt_struct evt;

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_LAUNCHER_ACTIVE);

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


void VappLauncherApp::emitEventInactive()
{
    vapp_launcher_inactive_evt_struct evt;

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_LAUNCHER_INACTIVE);

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


void VappLauncherApp::displayBottomScreen()
{
    const mmi_id bottomScrId = getBottomScreenId();

    //
    // Fine-tune the bottom screen.
    //
    VfxAppScr *scr = getScreen(bottomScrId);
    if (!scr)
    {
        return; // No screen is available yet.
    }

    VappLauncherScreen *screen = VFX_OBJ_DYNAMIC_CAST(scr, VappLauncherScreen);
    VFX_ASSERT(screen);

    screen->displayBottomPage();

    //
    // Close all screens upon the bottom screen.
    //
    for (mmi_id topScrId = getTopScreenId();
         topScrId != bottomScrId;
         topScrId = getTopScreenId())
    {
        closeScreen(topScrId);
    }
}


/*****************************************************************************
 * Launcher Main Screen
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherScreen", VappLauncherScreen, VfxMainScr);


VappLauncherScreen::VappLauncherScreen() :
    m_mainPage(NULL)
{
    setVrtCacheLimitSize(VAPP_LAUNCHER_VRT_CACHE_LIMIT);

#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
    setAppContextShareForVrt(VFX_TRUE);
#endif
}


void VappLauncherScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    VFX_OBJ_CREATE(m_mainPage, VappLauncherPage, this);
    pushPage(0, m_mainPage);
}


void VappLauncherScreen::processEnter(VfxBool isBackward)
{
    if (m_mainPage)
    {
        m_mainPage->processBeforeEnter();
    }

    VfxMainScr::processEnter(isBackward);
}


void VappLauncherScreen::onEntered(VfxBool isBackward)
{
    VfxMainScr::onEntered(isBackward);

    // Cosmos mainmenu use this signal to prepare next page cache
    // TODO: cosmos mainmenu should get this timing from launcher base class
    m_signalScreenOnEntered.emit(isBackward);
}


VfxBool VappLauncherScreen::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_HOME &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        displayBottomPage();
        return VFX_TRUE;
    }

    return VfxMainScr::onKeyInput(event);
}


void VappLauncherScreen::displayBottomPage()
{
    const VfxId bottomPageId = getBottomPageId();

    //
    // Fine-tune the bottom page.
    //
    VfxPage *page = getPage(bottomPageId);
    if (!page)
    {
        return; // No page is available yet.
    }

    //
    // Close all other pages upon the bottom page.
    //
    for (VfxId topPageId = getTopPageId();
         topPageId != bottomPageId;
         topPageId = getTopPageId())
    {
        closePage(topPageId);
    }

    //
    // Unlike other APP that their popups will be closed when we closes these
    // APP, launcher APP should close its popup by itself because launcher APP
    // is never closed.
    //
    clearPopupStack();
}


/*****************************************************************************
 * Launcher Main Page
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherPage", VappLauncherPage, VfxPage);


VfxBool VappLauncherPage::s_isFirstInit = VFX_TRUE;


VappLauncherPage::VappLauncherPage() :
    m_launcher(NULL),
    m_isProcessHomeKey(VFX_FALSE),
    m_isNeedRestoreStatus(VFX_FALSE)
{
    // Do nothing.
}


void VappLauncherPage::onInit()
{
    VfxPage::onInit();

    //
    // Page Property & Create Launcher.
    //
    setAllowDelete(VFX_FALSE);

    createLauncher();
    s_isFirstInit = VFX_FALSE;

    //
    // Launcher APP Signals.
    //
    VappLauncherApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappLauncherApp);
    VFX_ASSERT(app);

    app->m_signalActive.connect(this, &VappLauncherPage::onAppActive);
    app->m_signalInactive.connect(this, &VappLauncherPage::onAppInactive);
    app->m_signalProcessHomeKey.connect(this, &VappLauncherPage::onProcessHomeKey);

    //
    // Launcher Updated Signal.
    //
    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
    provider->m_signalLauncherUpdated.connect(this, &VappLauncherPage::onLauncherUpdated);
    provider->m_signalDefaultLauncherChanged.connect(this, &VappLauncherPage::onLauncherChanged);

    //
    // Wallpaper Changed Signal.
    //
    // Help to set VRT mem factor when wallpaper changed.
    //
    // [MAUI_03154209] [Launcher] Workaround VRT mem factor and video memory concurrency issue.
    // vrt factor is used to reserve memory for vrt to do cache or provide resource to GPU,
    // so if wallpaper no needs to set vrt cache size for gpu resource (EX. 3D wallpaper)
    // set the default vrt factor to VRT to do the cache
    // set vrt cache size of HS screen variable when wallpaper changed
    // so that screen will set vrt factor before vrt init
    //
    VappWallpaperSettingInterface *setting;

    setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    setting->m_signalWallpaperIsUpdated.connect(this, &VappLauncherPage::onWallpaperChanged);

    //
    // Notification Enter / Exited events.
    //
    VappNCenter *nCenter;

    nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    nCenter->m_signalEvent.connect(this, &VappLauncherPage::onNotificationCenterEvent);
}


void VappLauncherPage::onDeinit()
{
    //
    // Notification Enter / Exited events.
    //
    VappNCenter *nCenter;

    nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    nCenter->m_signalEvent.disconnect(this, &VappLauncherPage::onNotificationCenterEvent);

    //
    // Wallpaper changed signal.
    //
    VappWallpaperSettingInterface *setting;

    setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    setting->m_signalWallpaperIsUpdated.disconnect(this, &VappLauncherPage::onWallpaperChanged);

    //
    // Launcher updated signal.
    //
    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
    provider->m_signalLauncherUpdated.disconnect(this, &VappLauncherPage::onLauncherUpdated);

    //
    // Launcher APP Signals.
    //
    VappLauncherApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappLauncherApp);
    VFX_ASSERT(app);

    app->m_signalActive.disconnect(this, &VappLauncherPage::onAppActive);
    app->m_signalInactive.disconnect(this, &VappLauncherPage::onAppInactive);
    app->m_signalProcessHomeKey.disconnect(this, &VappLauncherPage::onProcessHomeKey);

    //
    // Release the launcher.
    //
    releaseLauncher();

    VfxPage::onDeinit();
}


void VappLauncherPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (m_launcher)
    {
        m_launcher->setIsProcessHomeKey(m_isProcessHomeKey);
        m_launcher->enter();
    }

    m_isProcessHomeKey = VFX_FALSE;
}


void VappLauncherPage::onEntered()
{
    VfxPage::onEntered();

    if (m_launcher)
    {
        m_launcher->entered();
    }
}


void VappLauncherPage::onExit(VfxBool isBackward)
{
    if (m_launcher)
    {
        m_launcher->exit();
    }

    VfxPage::onExit(isBackward);
}


void VappLauncherPage::processBeforeEnter()
{
    if (!m_launcher)
    {
        // It is possible that we voluntarily release the launcher, e.g., OOM or
        // APP inactive. In this case, we need to re-create it here.
        createLauncher();

        // Update VRT cache because the wallpaper could change now.
        updateVrtCacheSize();
    }
}


void VappLauncherPage::createLauncher()
{
    //
    // Get the default launcher.
    //
    VappLauncherSettingProvider *provider;
    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

    VappLauncherId id = provider->getDefaultLauncher();

    //
    // Get the heap.
    //
    VappLauncherHeap *heap = VFX_OBJ_GET_INSTANCE(VappLauncherHeap);
    heap->m_signalVolunteerFree.connect(this, &VappLauncherPage::onVolunteerFree);

    //
    // Create the launcher.
    //
    // Note that we need to call 'addChildFrame' because the parent of the
    // launcher is a VfxContext object, rather than this page object.
    //
    VappLauncherKit *kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);
    VfxBool isFailed = VFX_TRUE;
    VfxWString errorMsg;

    VFX_ASSERT(!m_launcher);
    m_launcher = kit->createLauncher(id, heap->createContext());

    if (m_launcher)
    {
        addChildFrame(m_launcher);

        m_launcher->setFirstInit(s_isFirstInit);

        if(m_isNeedRestoreStatus)
        {
            m_launcher->setIsRestoreStatus(m_isNeedRestoreStatus);
            m_isNeedRestoreStatus = VFX_FALSE;
        }

        m_launcher->setIsProcessHomeKey(m_isProcessHomeKey);

        m_launcher->createView();

        isFailed = m_launcher->getCreateViewFailure(errorMsg);
    }

    // If failed, get any other launcher. We should guarantee this one can
    // always create its view successfully.
    if (isFailed)
    {
        VFX_OBJ_CLOSE(m_launcher);
        heap->releaseContext();

        // Update the launcher setting.
        id = provider->getLauncherIfAny();
        provider->setDefaultLauncher(id);

        // Create launcher.
        m_launcher = kit->createLauncher(id, heap->createContext());
        VFX_ASSERT(m_launcher);

        addChildFrame(m_launcher);

        m_launcher->setFirstInit(s_isFirstInit);
        m_launcher->createView();
        VFX_ASSERT(!m_launcher->getCreateViewFailure(errorMsg));

        // Display the popup.
        //vfxPostInvoke1(this, &VappLauncherPage::displayPopup, errorMsg);
    }

    m_launcher->m_signalAbnormalReset.connect(this, &VappLauncherPage::onAbnormalReset);

    //
    // Status icon bar.
    //
    setTranslucent(m_launcher->getStatusBarTranslucent());

    if(m_launcher->getStatusBarBg() != VFX_RES_ID_NULL)
    {
        setStatusBarBg(m_launcher->getStatusBarBg());
    }

    //
    // Adjust the position of the launcher.
    //
    if(!m_launcher->getStatusBarTranslucent())
    {
        VfxMainScr *mainScr = getMainScr();
        VFX_ASSERT(mainScr);

        VfxPoint pageOrigin = mainScr->getClient(this).origin;
        m_launcher->setPos(pageOrigin.x, -pageOrigin.y);
    }
}


void VappLauncherPage::releaseLauncher()
{
    VappLauncherHeap *heap = VFX_OBJ_GET_INSTANCE(VappLauncherHeap);

    if (m_launcher)
    {
        m_launcher->releaseView();
        VFX_OBJ_CLOSE(m_launcher);

        heap->releaseContext();
    }

    heap->m_signalVolunteerFree.disconnect(this, &VappLauncherPage::onVolunteerFree);
}


void VappLauncherPage::onVolunteerFree()
{
    m_isNeedRestoreStatus = VFX_TRUE;
        
    //
    // Close all until the APP has only one screen containing one page.
    //
    closeScreenPageStack();

    //
    // Release and close the current launcher.
    //
    // Note that because closing the screen and page stack could be executed
    // in an async way, we cannot release the launcher immediately here. We use
    // post-invoke to make sure when we release the launcher, all the screen and
    // page stack are closed.
    //
    // TODO: VfxPage should provide a way to let us know it's really closed.
    //
    vfxPostInvoke0(this, &VappLauncherPage::onPostVolunteerFree);
}


void VappLauncherPage::onPostVolunteerFree()
{
    releaseLauncher();
}


void VappLauncherPage::displayPopup(VfxWString string)
{
    VcpConfirmPopup *popup;

    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->setInfoType(VCP_POPUP_TYPE_WARNING);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setText(string);
    popup->setAutoDestory(VFX_TRUE);
    popup->setStaticShelter(VFX_TRUE);
    popup->show(VFX_TRUE);
}


void VappLauncherPage::onAbnormalReset(VappLauncher *launcher)
{
    VFX_ASSERT(launcher == m_launcher);

    // Set the default launcher to a native launcher.
    VappLauncherSettingProvider *provider;
    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
    provider->setDefaultLauncher(provider->getLauncherIfAny());

    // Update launcher.
    updateLauncher();
}


void VappLauncherPage::onAppActive(VfxBool isSnapshot)
{
    //
    // Because we connect the "App-Active" signal in the "onInit" function,
    // "onAppActive" function will not be called at the first time the launcher
    // is launched. It will be called when the handset exits and enters the
    // launcher later on.
    //
    VFX_UNUSED(isSnapshot);

    if (m_launcher)
    {
        m_launcher->restoreView();
    }
}


void VappLauncherPage::onAppInactive(VfxBool isSnapshot)
{
    VFX_UNUSED(isSnapshot);

#if defined(VAPP_LAUNCHER_CFG_CLOSE_ON_INACTIVE)
    //
    // Release and close the current launcher.
    //
    // Please read the comments at "onVolunteerFree" to know why we need to use
    // pose-invoke here.
    //
    m_isNeedRestoreStatus = VFX_TRUE;
    closeScreenPageStack();
    vfxPostInvoke0(this, &VappLauncherPage::onPostInactiveFree);
#else
    if (m_launcher)
    {
        m_launcher->serializeView();
    }
#endif /* defined(VAPP_LAUNCHER_CFG_CLOSE_ON_INACTIVE) */
}


#if defined(VAPP_LAUNCHER_CFG_CLOSE_ON_INACTIVE)
void VappLauncherPage::onPostInactiveFree()
{
    releaseLauncher();
}
#endif /* defined(VAPP_LAUNCHER_CFG_CLOSE_ON_INACTIVE) */


void VappLauncherPage::onProcessHomeKey()
{
    m_isProcessHomeKey = VFX_TRUE;
}


void VappLauncherPage::onLauncherChanged()
{
    m_isNeedRestoreStatus = VFX_FALSE;
    m_isProcessHomeKey = VFX_FALSE;
}


void VappLauncherPage::onLauncherUpdated()
{
    updateLauncher();
}


void VappLauncherPage::onWallpaperChanged()
{
    //
    // VRT cache size for wallpaper.
    //
    updateVrtCacheSize();

    //
    // Notify the launcher the wallpaper changed event.
    //
    if (m_launcher)
    {
        m_launcher->notifyWallpaperChanged();
    }
}


void VappLauncherPage::onNotificationCenterEvent(VappNCenterEventEnum event)
{
    switch (event)
    {
        case VAPP_NCENTER_EVENT_ENTER:
        {
            if (m_launcher)
            {
                m_launcher->notifyNotificationCenterEnter();
            }
            break;
        }
        case VAPP_NCENTER_EVENT_EXITED:
        {
            if (m_launcher)
            {
                m_launcher->notifyNotificationCenterExited();
            }
            break;
        }
        default:
            break;
    }
}

class VappLauncherNullTransition : public VfxPageTransition
{
// Override
protected:
    virtual void customStart(VfxBool in, VfxS32 direction, VfxMsec duration) 
    {
        getTarget()->setOpacity(1.0f);
    }

    virtual void customStop(VfxBool in, VfxS32 direction, VfxMsec duration)
    {
        vfxPostInvoke0(this, &VappLauncherNullTransition::suicide);
    }

private:
    void suicide()
    {
        VappLauncherNullTransition *ptr = this;
        VFX_OBJ_CLOSE(ptr);
    }
};

void VappLauncherPage::updateLauncher()
{
    //
    // page transition flow: set unhittable -> customStart -> set hittable -> customStop
    //
    // Launcher object (ex. Cosmos MM) will override page transition effect, but
    // the page transition may be deleted between customStart and customStop,
    // so there will not reset the page property if customStop is not executed.
    // Needs to use the no effect page transition effect before launcher updated,
    // Accordingly, page transition will not be deleted during the animation (page transition flow)
    //
    
    VappLauncherNullTransition *trans;
    VFX_OBJ_CREATE(trans, VappLauncherNullTransition, this);
    setTransition(trans);

    //
    // Release and close the current launcher.
    //
    // Please read the comments at "onVolunteerFree" to know why we need to use
    // pose-invoke here.
    //

    closeScreenPageStack();
    vfxPostInvoke0(this, &VappLauncherPage::onPostUpdateLauncher);
}


void VappLauncherPage::onPostUpdateLauncher()
{
    releaseLauncher();

    //
    // Create the new launcher.
    //
    // Be careful. If this page isn't the current active page, we are actually
    // in the serialized state. That means the memory could be insufficient
    // if we directly create the full state of the launcher. In this case, we
    // delay the creation of the launcher until the page becomes active.
    //
    VfxMainScr *mainScr = getMainScr();
    VFX_ASSERT(mainScr);

    if (mainScr->isActive() && isActive())
    {
        // Generally, the launcher is created when the notification center is
        // closed. To avoid from the complication, close it here.
        VappNCenter *nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
        nCenter->leave();

        // Create new launcher.
        createLauncher();

        // Update VRT cache because the wallpaper could change now.
        updateVrtCacheSize();

        // Simulate the 'onEnter' and 'onEntered' virtual functions.
        m_launcher->enter();
        m_launcher->entered();
    }
}


void VappLauncherPage::closeScreenPageStack()
{
    VfxApp *app = VfxAppLauncher::findApp(
                    VAPP_LAUNCHER,
                    VFX_OBJ_CLASS_INFO(VappLauncherApp),
                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (app)
    {
        VappLauncherApp *launcher = VFX_OBJ_DYNAMIC_CAST(app, VappLauncherApp);
        VFX_ASSERT(launcher);

        launcher->displayBottomScreen();
    }
}


void VappLauncherPage::updateVrtCacheSize()
{
    VfxMainScr *mainScr = getMainScr();
    VFX_ASSERT(mainScr);

    VappWallpaper *wallpaper;

    wallpaper = VappWallpaperKit::createWallpaperWithoutSetup(
                    this,
                    VAPP_WALLPAPER_SRC_HOMESCREEN);

    if(wallpaper->getVrtMemFactor() == 0)
    {
        mainScr->setVrtCacheSize(VAPP_LAUNCHER_VRT_CACHE_LIMIT);
    }
    else
    {
        mainScr->setVrtCacheSize(wallpaper->getVrtMemFactor());
    }

    VFX_OBJ_CLOSE(wallpaper);
}


/*****************************************************************************
 * Function
 *****************************************************************************/

extern "C" mmi_ret vapp_launcher_app_notify_active_idle_in_end_key(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;
    VappLauncherApp *launcher;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    app = VfxAppLauncher::findApp(
            VAPP_LAUNCHER,
            VFX_OBJ_CLASS_INFO(VappLauncherApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (app)
    {
        launcher = (VappLauncherApp *)app;
        launcher->m_signalProcessHomeKey.emit();
    }

    return MMI_RET_OK;
}


/* For the detail information, please refer to the vapp_launcher_gprot.h */
mmi_ret vapp_launcher_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_PRE_ACTIVE_IDLE_APP_IN_END_KEY:
        {
            ret = vapp_launcher_app_notify_active_idle_in_end_key(event);
            break;
        }
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
        {
        #ifdef __MMI_VUI_WIDGET_FACTORY__
            /* Initialize the widget system. */
            vapp_widget_sys_init();
        #endif
        
            /* Initialize the launcher system. */
            vapp_launcher_sys_init();

            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}


/* For the detail information, please refer to the vapp_launcher_gprot.h */
MMI_ID vapp_launcher_launch(void *param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_launcher_launch_param_struct *p_in;
    VfxAppLauncherParam p_out(VAPP_LAUNCHER, VFX_OBJ_CLASS_INFO(VappLauncherApp));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Input parameter from caller: */
    VFX_ASSERT(param && param_size == sizeof(vapp_launcher_launch_param_struct));
    p_in = (vapp_launcher_launch_param_struct *)param;

    /* Output parameter for APP launcher: */
    p_out.setMemSource(VFX_OBJ_GET_INSTANCE(VappPlatformContext));
    p_out.setPlacement(VFX_APP_LAUNCHER_PLACE_AFTER, p_in->base_app_id);

    return VfxAppLauncher::launchEx(p_out);
}


/* For the detail information, please refer to the vapp_launcher_gprot.h */
void vapp_launcher_display()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;
    VappLauncherApp *launcher;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //
    // Close until the bottom screen is shown. If some other APP blocks the
    // handset to go back to the launcher APP, we do not need to close to the
    // buttom screen. So, we need to check if launcher APP is active.
    //
    app = VfxAppLauncher::findApp(
            VAPP_LAUNCHER,
            VFX_OBJ_CLASS_INFO(VappLauncherApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (app)
    {
        launcher = VFX_OBJ_DYNAMIC_CAST(app, VappLauncherApp);
        VFX_ASSERT(launcher);

        launcher->displayBottomScreen();
    }

    //
    // Close until the bottom group is shown.
    //
    mmi_frm_close_to_idle_group();

    //
    // Close the notification center (MAUI_02455418).
    //
    // TODO: it is better to emit an event for all other applications.
    //
    VappNCenter *nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    nCenter->leave();
}


/* For the detail information, please refer to the vapp_launcher_gprot.h */
MMI_ID vapp_launcher_restart()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;
    VappLauncherApp *launcher;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //
    // Close all background APP.
    //
    mmi_frm_close_all_background_groups();

    //
    // Close until the bottom group is shown.
    //
    mmi_frm_close_to_idle_group();

    //
    // Terminate the old launcher APP.
    //
    app = VfxAppLauncher::findApp(
            VAPP_LAUNCHER,
            VFX_OBJ_CLASS_INFO(VappLauncherApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (app)
    {
        launcher = VFX_OBJ_DYNAMIC_CAST(app, VappLauncherApp);
        VFX_ASSERT(launcher);
        launcher->displayBottomScreen();

        VfxAppLauncher::terminate(app->getGroupId());
    }

    //
    // Launch launcher App.
    //
    VfxContext *cntx = VFX_OBJ_GET_INSTANCE(VappPlatformContext);

    return VfxAppLauncher::launchWithCtx(
            VAPP_LAUNCHER,
            VFX_OBJ_CLASS_INFO(VappLauncherApp),
            GRP_ID_ROOT,
            cntx);
}


/* For the detail information, please refer to the vapp_launcher_gprot.h */
MMI_ID vapp_launcher_reload()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //
    // Terminate the old launcher APP.
    // it can not just close launcher object, because there may have push page in the launcher object,
    // it will cause page stack unsync problem if delete launcher object directly,
    // ex: cosmos launcher->cosmos mm -> close launcher object
    //     => cosmos launcher mm page will be deleted, but main screen did not know this thing
    //
    app = VfxAppLauncher::findApp(
            VAPP_LAUNCHER,
            VFX_OBJ_CLASS_INFO(VappLauncherApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }

    //
    // Launch launcher App.
    //
    VfxContext *cntx = VFX_OBJ_GET_INSTANCE(VappPlatformContext);

    return VfxAppLauncher::launchWithCtx(
            VAPP_LAUNCHER,
            VFX_OBJ_CLASS_INFO(VappLauncherApp),
            GRP_ID_ROOT,
            cntx);
}


/* For the detail information, please refer to the vapp_launcher_gprot.h */
MMI_BOOL vapp_launcher_is_active()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app = VfxAppLauncher::findApp(
            VAPP_LAUNCHER,
            VFX_OBJ_CLASS_INFO(VappLauncherApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (app && app->isActive())
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Pluto Adapter: Idle
 *
 * TEMP SOLUTION ONLY. SHALL BE REMOVED LATER.
 *****************************************************************************/

mmi_ret mmi_idle_main_evt_hdlr(mmi_event_struct *event)
{
    return MMI_RET_OK;
}


void mmi_idle_display(void)
{
    vapp_launcher_display();
}


MMI_BOOL mmi_idle_is_active(void)
{
    return MMI_FALSE;
}


void mmi_idle_disable_lock_by_end_key(void)
{
    // Do nothing.
}


/*
 * wgui_categories_idlescreen.obj will use mmi_idle_shell_update_idle_text
 * in function idle_screen_show_network_details.
 */
extern "C" void mmi_idle_shell_update_idle_text(void)
{
    // Do nothing.
}


/*****************************************************************************
 * Pluto Adapter: Idle Notification
 *
 * TEMP SOLUTION ONLY. SHALL BE REMOVED LATER.
 *****************************************************************************/

void mmi_nmgr_answer(
    U32 type,
    mmi_nmgr_result_enum result,
    mmi_nmgr_info_struct *info,
    mmi_nmgr_hdlr_func_t hdlr)
{
    // Do nothing.
}


MMI_BOOL mmi_nmgr_notify(U32 type, U32 flag)
{
    return MMI_TRUE;
}


MMI_BOOL mmi_nmgr_is_active(void)
{
    return MMI_FALSE;
}

