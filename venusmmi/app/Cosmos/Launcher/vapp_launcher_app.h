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
 *  vapp_launcher_app.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the launcher APP.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_APP_H
#define VAPP_LAUNCHER_APP_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vapp_launcher.h"
#include "vapp_ncenter.h"
#include "vapp_launcher_app_def.h"


/*****************************************************************************
 *
 *****************************************************************************/

class VappLauncherApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappLauncherApp);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherApp();

// Signal
public:
    // This signal is emitted when the launcher application is active. Internal
    // objects of the launcher applications can connect this signal.
    VfxSignal1 <VfxBool> m_signalActive;

    // This signal is emitted when the launcher application is inactive.
    // Internal objects of the launcher applications can connect this signal.
    VfxSignal1 <VfxBool> m_signalInactive;

    // This signal is emitted when press home key to back to idle process
    // Internal objects of the launcher applications can connect this signal.
    VfxSignal0 m_signalProcessHomeKey;

    // This signal is emitted when press launcher shuttle to switch launcher,
    // Internal objects of the launcher applications can connect this signal.
    // then reload new launcher
    VfxSignal0 m_signalReloadLauncher;

// Method
public:
    // This function displays the bottom screen.
    void displayBottomScreen();

// Override
protected:
    // Please refer to VfxApp.
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );

    // Please refer to VfxApp.
    virtual void onGroupTopActive();

    // Please refer to VfxApp.
    virtual void onGroupTopInactive();

    // Please refer to VfxApp.
    virtual void onGroupSnapshotActive();

    // Please refer to VfxApp.
    virtual void onGroupSnapshotInactive();

// Implementation
private:
    // This function emits the 'active' event.
    void emitEventActive();

    // This function emits the 'inactive' event.
    void emitEventInactive();
};


/*****************************************************************************
 * Launcher Main Screen
 *****************************************************************************/

class VappLauncherPage;

class VappLauncherScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappLauncherScreen);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherScreen();

// Signal
public:
    // This signal is emitted when screen onEntered for mainmenu
    // Internal objects of the launcher applications can connect this signal.
    VfxSignal1 <VfxBool> m_signalScreenOnEntered;

// Method
public:
    // This function displays the bottom page.
    void displayBottomPage();

// Override
protected:
    // Please refer to VfxScreen.
    virtual void processEnter(
        VfxBool isBackward
    );

    // Please refer to VfxMainScr.
    virtual void on1stReady();

    // Please refer to VfxScreen.
    virtual void onEntered(
        VfxBool isBackward
    );

    // Please refer to VfxFrame.
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

// Variable
private:
    // Main page.
    VappLauncherPage *m_mainPage;
};


/*****************************************************************************
 * Launcher Main Page
 *****************************************************************************/

class VappLauncherPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappLauncherPage);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherPage();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // Please refer to VfxPage.
    virtual void onEnter(
        VfxBool isBackward
    );

    // Please refer to VfxPage.
    virtual void onEntered();

    // Please refer to VfxPage.
    virtual void onExit(
        VfxBool isBackward
    );

// Method
public:
    // Call this API before we enter the screen to restore the launcher.
    void processBeforeEnter();

// Variable
private:
    // Launcher.
    VappLauncher *m_launcher;

    // Is home key pressed
    // If launcher is destroyed because of OOM in other screen, launcher status needs to adjust if home key is pressed,
    VfxBool m_isProcessHomeKey;

    // Is need restore launcer status,
    // If launcher is destroyed because of OOM in other screen, launcher status needs to restore,
    // but if launcher is restart because launcher changed, the status should be reset
    VfxBool m_isNeedRestoreStatus;

    // Is first time initialized.
    static VfxBool s_isFirstInit;

// Implementation
private:
    // Create launcher object.
    void createLauncher();

    // Release launcher object.
    void releaseLauncher();

    // Handle the 'volunteer-free' signal of the heap.
    void onVolunteerFree();

    // Post-handle the 'volunteer-free' signal.
    void onPostVolunteerFree();

    // Display the popup.
    void displayPopup(
        VfxWString string
    );

    // This function handles the signal to handle the abnormal reset of the
    // launcher.
    void onAbnormalReset(
        VappLauncher *launcher  // [IN] Launcher
    );

    // When the launcher becomes active, this function is called.
    void onAppActive(
        VfxBool isSnapshot      // [IN] If APP is active for the snapshot
    );

    // When the home APP becomes inactive, this function is called.
    void onAppInactive(
        VfxBool isSnapshot      // [IN] If APP is inactive for the snapshot
    );

#if defined(VAPP_LAUNCHER_CFG_CLOSE_ON_INACTIVE)
    // Handler to free the launcher in a post-invoke way when the launcher
    // application is inactive.
    void onPostInactiveFree();
#endif /* defined(VAPP_LAUNCHER_CFG_CLOSE_ON_INACTIVE) */

    // When home key is pressed to back to idle, this function is called.
    void onProcessHomeKey();

    // This function handles the launcher updated signal.
    void onLauncherUpdated();

    // This function handles the launcher updated signal.
    void onLauncherChanged();

    // set vrt meme factor for different wallpaper
    void onWallpaperChanged();

    // Handle the notification center events.
    void onNotificationCenterEvent(
        VappNCenterEventEnum event
    );

    // This function updates the launchers.
    void updateLauncher();

    // Post-handle the 'update-launcher' signal.
    void onPostUpdateLauncher();

    // Close all screens and pages until the APP has only one screen containing
    // one page.
    void closeScreenPageStack();

    // This function updates the VRT cache size.
    void updateVrtCacheSize();
};


#endif /* VAPP_LAUNCHER_APP_H */

