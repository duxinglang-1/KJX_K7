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
 *  vapp_screen_lock_screen.cpp
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

#include "vapp_screen_lock_main.h"
#include "vapp_screen_lock_screen.h"
#include "vapp_screen_lock_cosmos_frame.h"
#include "vapp_screen_lock_cosmos_call_card.h"
#include "vapp_screen_lock_cosmos_msg_card.h"
#include "vapp_screen_lock_cosmos_unlock_card.h"
#include "vapp_screen_lock_cosmos_unlock_item_kit.h"
#include "vapp_screen_lock_cosmos_time.h"
#include "vapp_wallpaper_kit.h"
#include "vapp_widget_music_player.h"
#include "vapp_ncenter_gprot.h"
#include "mmi_rp_vapp_screen_lock_def.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_screen_lock_setting_provider.h"
#include "vapp_screen_lock_kit.h"


// for wallpaper setting api
#include "vapp_wallpaper_setting_method_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "PhoneSetupGprots.h"
#include "GpioSrvGProt.h"
#include "ShutdownSrvGprot.h"
#include "GlobalResDef.h"
#include "AppMgrSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "gpiosrvgprot.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_trc.h"

// for fm radio panel
#include "vapp_widget_fm_radio.h"

// memory context for screen lock
#include "vapp_platform_context.h"
#include "vapp_screen_lock_mem_cfg.h"

// To be removed
#include "ScrLockerGprot.h"
#include "ScrSaverGprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Function
 *****************************************************************************/

/*****************************************************************************
 * VappScreenLockScreen
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockScreen", VappScreenLockScreen, VfxMainScr);
VappScreenLockScreen::VappScreenLockScreen()
{
    setVrtCacheSize(VAPP_SCREEN_LOCK_VRT_CACHE_LIMIT);
}

VappScreenLockScreen::~VappScreenLockScreen()
{
}

void VappScreenLockScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappScreenLockPage *page;
    VFX_OBJ_CREATE(page, VappScreenLockPage, this);
    pushPage(0, page);
}


mmi_ret VappScreenLockScreen::onProc(mmi_event_struct * evt)
{
    if (evt->evt_id == EVT_ID_VAPP_NCENTER_DRAG)
    {
        return MMI_RET_ERR;
    }
    return VfxMainScr::onProc(evt);
}


/*****************************************************************************
 * VappScreenLockPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockPage", VappScreenLockPage, VfxPage);


VappScreenLockPage::VappScreenLockPage():
    m_screenLock(NULL)
{
    // Do nothing.
}


void VappScreenLockPage::onInit()
{
    VfxPage::onInit(); // call base class

    //
    // Get the default screen lock.
    //
    VappScreenLockSettingProvider *provider;
    provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);

    VappScreenLockId id = provider->getDefaultScreenLock();

    //
    // Create the default screen lock.
    //
    VappScreenLockKit *kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);

    VFX_ASSERT(!m_screenLock);
    m_screenLock = kit->createScreenLock(id, this);
    VFX_ASSERT(m_screenLock);

    m_screenLock->setSize(getSize());
    m_screenLock->createView();

    // If failed, get any other screen lock. We should guarantee this one can
    // create its view always.
    VfxWString errorMsg;

    if (m_screenLock->getCreateViewFailure(errorMsg))
    {
        VFX_OBJ_CLOSE(m_screenLock);

        id = provider->getScreenLockIfAny();
        provider->setDefaultScreenLock(id);

        m_screenLock = kit->createScreenLock(id, this);
        VFX_ASSERT(m_screenLock);

        m_screenLock->setSize(getSize());
        m_screenLock->createView();
        VFX_ASSERT(!m_screenLock->getCreateViewFailure(errorMsg));
    }

    m_screenLock->m_signalUnlock.connect(this, &VappScreenLockPage::onUnlockHandler);

    //
    // Status icon bar.
    //
    setTranslucent(m_screenLock->getStatusBarTranslucent());

    if(m_screenLock->getStatusBarBg() != VFX_RES_ID_NULL)
    {
        setStatusBarBg(m_screenLock->getStatusBarBg());
    }

    //
    // Adjust the position of the launcher.
    //
    if(!m_screenLock->getStatusBarTranslucent())
    {
        VfxMainScr *mainScr = getMainScr();
        VFX_ASSERT(mainScr);
        
        VfxPoint pageOrigin = mainScr->getClient(this).origin;
        m_screenLock->setPos(pageOrigin.x, -pageOrigin.y);
    }

    //
    // Signals.
    //
    VappScreenLockApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappScreenLockApp);
    VFX_ASSERT(app);

    app->m_signalActive.connect(this, &VappScreenLockPage::onAppActive);
    app->m_signalInactive.connect(this, &VappScreenLockPage::onAppInactive);

    app->m_signalSnapshotActive.connect(this, &VappScreenLockPage::onGroupSnapActive);
    app->m_signalSnapshotInactive.connect(this, &VappScreenLockPage::onGroupSnapInactive);    

    mmi_frm_cb_reg_event(EVT_ID_GPIO_LCD_SLEEP_IN, &VappScreenLockPage::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_GPIO_LCD_SLEEP_OUT, &VappScreenLockPage::eventHandler, this);
}


void VappScreenLockPage::onBack()
{
}


void VappScreenLockPage::onEnter(VfxBool isBackward)
{
    m_screenLock->processPageEnter();

    //MAUI_03138182
    //To make sure screen lock can receive pen from status icon bar
    getMainScr()->getStatusBar()->setIsUnhittable(VFX_TRUE);
}


void VappScreenLockPage::onExit(VfxBool isBackward)
{
    m_screenLock->processPageExit();
}


void VappScreenLockPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_IN, &VappScreenLockPage::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_OUT, &VappScreenLockPage::eventHandler, this);

    m_screenLock->m_signalUnlock.disconnect(this,&VappScreenLockPage::onUnlockHandler);
    m_screenLock->releaseView();

    //
    // Signals.
    //
    VappScreenLockApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappScreenLockApp);
    VFX_ASSERT(app);

    app->m_signalActive.disconnect(this, &VappScreenLockPage::onAppActive);
    app->m_signalInactive.disconnect(this, &VappScreenLockPage::onAppInactive);

    app->m_signalSnapshotActive.disconnect(this, &VappScreenLockPage::onGroupSnapActive);
    app->m_signalSnapshotInactive.disconnect(this, &VappScreenLockPage::onGroupSnapInactive);    

    VfxPage::onDeinit();
}


void VappScreenLockPage::onAppActive()
{
    //
    // Because we connect the "App-Active" signal in the "onInit" function,
    // "onAppActive" function will not be called at the first time the launcher
    // is launched. It will be called when the handset exits and enters the
    // launcher later on.
    //
    VFX_ASSERT(m_screenLock);
    m_screenLock->restoreView();
}


void VappScreenLockPage::onAppInactive()
{
    VFX_ASSERT(m_screenLock);
    m_screenLock->serializeView();
}


void VappScreenLockPage::onGroupSnapActive()
{
    VFX_ASSERT(m_screenLock);
    m_screenLock->restoreView();
}


void VappScreenLockPage::onGroupSnapInactive()
{
    VFX_ASSERT(m_screenLock);
    m_screenLock->serializeView();
}


void VappScreenLockPage::onUnlockHandler(VappScreenLock *frame)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_UNLOCK_HANDLER, 200);
    vapp_screen_lock_close();
}


mmi_ret VappScreenLockPage::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappScreenLockPage* instance = (VappScreenLockPage *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_GPIO_LCD_SLEEP_IN:
            instance->backlightOffHandler(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_OUT:
            instance->backlightOnHandler(event);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

mmi_ret VappScreenLockPage::backlightOffHandler(mmi_event_struct *event)
{
    m_screenLock->notifyBacklightOff();
    return MMI_RET_OK;
}


mmi_ret VappScreenLockPage::backlightOnHandler(mmi_event_struct *event)
{
    m_screenLock->notifyBacklightOn();
    return MMI_RET_OK;
}
