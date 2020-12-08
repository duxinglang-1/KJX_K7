/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_launcher_robot_director.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the director page.
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

#ifndef VAPP_LAUNCHER_ROBOT_DIRECTOR_H
#define VAPP_LAUNCHER_ROBOT_DIRECTOR_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vapp_launcher_def.h"
#include "vapp_launcher.h"
#include "vapp_widget.h"
#include "vapp_wallpaper.h"
#include "vapp_launcher_robot_def.h"
#include "vapp_launcher_robot_desktop.h"
#include "vapp_launcher_robot_bar.h"
#include "vapp_launcher_robot_page_selector.h"
#include "vapp_launcher_robot_shortcut_selector.h"
#include "vapp_launcher_robot_widget_selector.h"
#include "vapp_ncenter.h"

#include "vapp_launcher_robot_mainmenu.h"


class VfxLauncherRobotPageSlideTransition;


/*****************************************************************************
 * Home Director Object
 *****************************************************************************/

class VappLauncherRobotDirector : public VappLauncher
{
    VAPP_LAUNCHER_DECLARE_CLASS(VappLauncherRobotDirector);

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherRobotDirector();

// Override
protected:
    // Please refer to VfxFrame.
    virtual void onDraw(
        VfxDrawContext &dc
    );

    // Please refer to VfxFrame.
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

// Enum
private:
    enum
    {
        PEN_DOWN_DELAY = 100,
        
        // Delayed time, in msec., to load the wallpaper. Because loading the
        // wallpaper takes time, if the handset will hang for a while when it
        // just enters the home screen, please tune this parameter.
        WALLPAPER_BOOTUP_DELAY_TIME = 4000,
        WALLPAPER_GOBACK_DELAY_TIME = 1250,
        WALLPAPER_NORMAL_DELAY_TIME = 450,
        WALLPAPER_SWIPE_DELAY_TIME = 50,

        // The offset in pixels that the desktop will capture the pen event and
        // start to slide when the user taps the touch screen.
        SLIDE_START_OFFSET = VAPP_WIDGET_DND_CRITERIA,

        // Delay time, in msec., to start to switch pages when the widget is
        // dragged to the boundary of the current page.
        DND_PAGE_SWITCH_START_DELAY = 450,

        // Delay time, in msec., to continue to switch pages when the widget is
        // dragged to the boundary of the current page.
        DND_PAGE_SWITCH_NEXT_DELAY = 900,

        // Time, in msec., to launch the page selector during Drag-and-Drop
        // (DnD) period.
        DND_PAGE_SELECTOR_START_DELAY = 400
    };

#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
// status for recover history because the launcher object may be free if OOM happens
private:
    static VfxBool s_isShowMainmenu;
    static VfxS32 s_curHSPageIndex;
#endif

    // use buffer to save widget setting, read from buffer instead of NVRAM to reduce launcher's response time 
    VfxMemArchiveSource *m_widgetArchiveSource;
    static VfxU8 *m_widgetSettingDataPtr;
    static VfxU32 m_widgetSettingDataSize;

//
// This block implements the handler for the pen input
//

// Override
protected:
    VfxBool isPenEventCaptureByComp();

    // Please refer to VfxControl.
    virtual VfxBool onPreviewPenInput(
        VfxPenEvent &event
    );

    // Please refer to VfxControl.
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

// Implementation
private:
    // This function captures the pen events from its child controls.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool capturePenEvent(
        const VfxObject *target     // [IN] Target object
    );

    // resume the delay pen event, transmit delay pen to child
    void onPenDownTimerTick(VfxTimer *source);

//
// This block implements the pure virtual of the launcher provider to provide
// meta information of this launcher.
//

// Override
protected:
    // Please refer to VappLauncher.
    virtual VappLauncherId getId() const;

    // Please refer to VappLauncher.
    virtual VfxS32 getName(
        VfxWChar *string,
        VfxS32 size
    ) const;

    // Please refer to VappLauncher.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

    virtual VfxS32 getScreenshotNum() const;

    virtual VfxFrame **createScreenshot(VfxObject *parentObj) const;

//
// This block implements the createView and releaseView of the launcher.
//

// Override
protected:
    // Please refer to VappLauncher.
    virtual void onCreateView();

    // Please refer to VappLauncher.
    virtual void onReleaseView();

//
// This block implements the serialization and restoration of the App.
//
// SCENARIO 1: ENTER APP
//
//  When the handset enters the launcher, the following functions are called.
//  If the UI components are retained after onEnter, they can be seen in the
//  first frame of the page transition effect.
//
//      onRestoreView => onEnter
//
// SCENARIO 2: EXIT APP
//
//  When the handset exits the launcher, the following functions are called.
//  If the UI components are retained after onExit, they can be seen in the
//  first frame of the page transition effect.
//
//      onExit => onSerializeView
//

// Implementation
protected:
    // Please refer to VappLauncher.
    virtual void onSerializeView(
        VfxArchive *ar
    );

    // Please refer to VappLauncher.
    virtual void onRestoreView(
        VfxArchive *ar
    );

    // Please refer to VappLauncher.
    virtual void onEnter();

    // Please refer to VappLauncher.
    virtual void onExit();

    // Override this virtual to use specific status bar bg
    // res: 9-slice image
    //
    virtual VfxResId onGetStatusBarBg();

    // Override this virtual to change status bar to translucent
    //
    virtual VfxBool onGetStatusBarTranslucent();

//
// This block implements the dummy Robot HS.
// MM is a component of Launcher, so needs to put each HS component to single node,
// it will help to cache whole HS when doing page transition between HS and MM
//

    VfxFrame *m_dummyRootHS;

//
// This block implements the launcher's settings.
//

// Method
private:
    // This function saves the launcher's setting.
    void save();

//
// This block implements the 2 pass activation to accelerate of the
// application's response time.
//

// Variable
private:
    // Timer to trigger the 2nd pass activation.
    VfxTimer *m_timer2ndPassLoader;

// Implementation
private:
    // This function creates the objects for the 2nd pass loader.
    void create2ndPassLoader();

    // This function releases the objects of the 2nd pass loader.
    void release2ndPassLoader();

    // This function starts the 2nd pass loader.
    void start2ndPassLoader();

    // This function stops the 2nd pass loader.
    void stop2ndPassLoader();

    // This function is the timeout function to load the 2nd pass components.
    void on2ndPassLoader(
        VfxTimer *timer         // [IN] Timer
    );

//
// This block implements the wallpaper.
//

// Variable
private:
    // Wallpaper.
    VappWallpaper *m_wallpaper;

    // Time to resume wallpaper after it is created.
    VfxTimer *m_timerResumeWallpaper;

    // If wallpaper is suspended because MM frame is on top active
    VfxBool m_isWallpaperSuspendForMM;

    // If wallpaper is suspended because the page exits.
    VfxBool m_isWallpaperSuspendForAppExit;

    // If wallpaper is suspended because notification center is shown.
    VfxBool m_isWallpaperSuspendForNcenter;

#if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
    // If wallpaper is suspended when the page is swipping.
    VfxBool m_isSuspendWallpaperForSwipe;

    // If wallpaper is suspended when the user touches the desktop.
    VfxBool m_isSuspendWallpaperForPenDown;
#endif /* defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE) */

// Implementation
private:
    // This function creates the wallpaper. The 'delayTime' controls the delay
    // time, in msec., that we will start to animate this wallpaper. If its
    // value is negative, we do not animate it. If its value is 0, we animate
    // it immediately.
    void createWallpaper(
        VfxMsec delayTime = 0   // [IN] Delay time to animate this wallpaper
    );

    // This function creates the wallpaper. This function will consider if we
    // should resume the wallpaper according to the current state of the home
    // screen.
    //
    // SEE ALSO: createWallpaper
    void createWallpaperExt(
        VfxMsec delayTime = 0   // [IN] Delay time to animate the wallpaper
    );

    // This function releases the wallpaper.
    void releaseWallpaper();

    // This function handles the wallpaper changed signal.
    virtual void onWallpaperChanged();

    // This function resumes the wallpaper after the specified time.
    void delayResumeWallpaper(
        VfxMsec delayTime           // [IN] Delay time to resume the wallpaper
    );

    // This function is the time-out handler to resume and animate the wallpaper
    // after we create it.
    void onResumeWallpaper(
        VfxTimer *timer         // [IN] Timer
    );

#if defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE)
    // This function suspends the wallpaper when the user starts to swipe the
    // desktop.
    void suspendWallpaperForSwipe();

    // This function resumes the wallpaper when the user stops swipping the
    // desktop.
    void resumeWallpaperForSwipe();

    // This function suspends the wallpaper when the user touches the desktop.
    void suspendWallpaperForPenDown();

    // This function resumes the wallpaper when the user stops touching the
    // desktop.
    void resumeWallpaperForPenDown();
#endif /* defined(VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE) */

    // This function is the signal handler when the notification center changes
    // its state.
    void onNotificationCenterChanged(
        VappNCenterEventEnum event  // [IN] State event
    );

//
// This block implements the desktop.
//

// Variable
private:
    // Desktop.
    VappLauncherRobotDesktop *m_desktop;

    // Timer to detect if we should auto. slide the desktop.
    VfxTimer *m_timerAutoSlideDesktop;

    // implement delay pen
    VfxTimer *m_penDownTimer;

    // If we capture the pen event.
    VfxBool m_isCaptured;

    // If pen event is captured, is it captured from other child control?
    VfxBool m_isCapturedFromOthers;

    // List of objects that request that we cannot swipe the desktop.
    VfxObjList m_cannotSwipeRequest;

    // List of objects that request that we cannot swipe the desktop if the pen
    // event is received by them or by their parent.
    VfxObjList m_cannotSwipeList;

    VfxFrame *m_dummyDesktop;

    VfxS32Timeline *m_tlSlideDummyDesktop;
    
// Implementation
private:
    // This function creates the desktop.
    void createDesktop();

    // This function releases the desktop.
    void releaseDesktop();

    // This function forbids to swipe the desktop.
    void forbidSwipe(
        VfxObject *requester    // [IN] Object that requests this operation
    );

    // This function permits to swipe the desktop.
    void permitSwipe(
        VfxObject *requester    // [IN] Object that requests this operation
    );

    // This function checks if we can swipe the desktop or not.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isSwipeForbidden();

    // This function forbids to swipe the desktop if the pen event is received
    // by the requester or their parent.
    void addFrameCannotSwipe(
        VfxFrame *frame     // [IN] Object that requests this operation
    );

    // This function permits to swipe the desktop if the pen event is received
    // by the requester or their parent.
    void removeFrameCannotSwipe(
        VfxFrame *frame     // [IN] Object that requests this operation
    );

    // This function checks if we can swipe the desktop, giving a frame that the
    // pen event is on it.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isFrameCannotSwipe(
        VfxFrame *frame     // [IN] Frame
    );

    // This function checks if we can swipe the desktop, giving a list of frames
    // that the pen event is on them.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isFrameCannotSwipe(
        VfxObjList &frameList   // [IN] List of frames
    );

    // This function checks if 'child' is a child frame of the 'parent'.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isChildFrame(
        const VfxFrame *parent,     // [IN] Parent
        const VfxFrame *child       // [IN] Child
    ) const;

    // This function handles the signal that the current page of the desktop is
    // changed.
    void onDesktopPageChanged(
        VappLauncherRobotDesktop *desktop    // [IN] Desktop
    );

    void onDesktopPageSlide(
        VappLauncherRobotDesktop *desktop,
        VfxS32 newDesktopBoundsOriginX,
        VfxS32 oldDesktopBoundsOriginX,
        VfxS32 duration
    );

    void onDesktopPageSlideEnd();

    // This function handles the signal that the bounds of the desktop is
    // changed.
    void onDesktopBoundsChanged(
        VfxFrame *frame,            // [IN] Desktop
        const VfxRect &oldBounds    // [IN] Old bounds
    );

    // This function handles the timer to auto slide the desktop.
    void onAutoSlideDesktop(
        VfxTimer *timer             // [IN] Timer
    );

//
// This block implements the shortcut bar.
//

// Variable
private:
    // andorid type
    VappLauncherRobotShortcutBar *m_shortcutBar;

    VappLauncherRobotMainmenuPage *m_mainmenu;

    VfxFloatTimeline *m_tlMMSSE;
    VfxFloatTimeline *m_tlHSSSE;

// Implementation
private:
    // This function creates the shortcut bar.
    void createShortcutBar();

    // This function releases the shortcut bar.
    void releaseShortcutBar();

    // This function create the main menu
    void createMainMenu();

    // release Main menu 
    void releaseMainmenu();

    // MM SSE callback
    void onMMSSEFinished(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted);

    // HS SSE callback
    void onHSSSEFinished(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted);

    // show MM component
    void showMainMenu(VfxBool isShow, VfxBool isAutoAnimate = VFX_TRUE);

    // This function handles the shortcut signal, used to launch 
    // corresponding application
    void onShortcutExecute(
            VappLauncherRobotShortcutBar::ButtonEnum buttonId);

    // This function handles the signal sent by MM 
    // used to notify that user touch Home key on MM
    void onClickedHomeOnMainMenu();

    // This function handles the MM signal which is emitted after long press MM's cell
    void onLongPressedMMCell(
            VfxChar *package, 
            VfxPoint offset);

    // This function handles the indicator long pressed signal.
    void onIndicatorLongPressed();

    // This function handles the indicator clicked signal.
    void onIndicatorClicked(VfxS32 direction);

    // This function examines if the shortcut is created on HS
    VfxBool isShortcutCreated(VappWidgetId widgetId);

//
// This block implements the toolbar.
//

// Variable
private:
    // Toolbar.
    VappLauncherRobotToolbar *m_toolbar;

    VfxBool m_isCreatWidgetFromMM;

// Implementation
private:
    // This function creates the toolbar.
    void createToolbar();

    // This function releases the toolbar.
    void releaseToolbar();

    // This function is the callback function when a button on the toolbar is
    // clicked.
    void onToolbarExecute(
        VappLauncherRobotToolbar *toolbar,           // [IN] Toolbar
        VappLauncherRobotToolbar::ButtonEnum button  // [IN] The clicked button
    );

    // This function is used to modify the SSE such that even if we launch the
    // setting application, the users will feel like we push a page on the home
    // screen. Just for a better user feeling.
    static void onPushWallpaperSettingPage(
        VfxMainScr *mainScr     // [IN] Main screen of setting applications
    );

//
// This block implements the trash can bar.
//

// Variable
private:
    // Toolbar.
    VappLauncherRobotTrashCanBar *m_trashCanBar;

// Implementation
private:
    // This function creates the trash can bar.
    void createTrashCanBar();

    // This function releases the trash can bar.
    void releaseTrashCanBar();

    //
    // This funciton is to toggle the widget edit mode, 
    // in this mode, it can change widget's postion and delete widget by move it to trash can
    //
    void toggleWidgetLayoutMode(VfxBool isOn, VfxBool isAnimatable);

//
// This block implements the edit mode.
//

// Variable
private:
    // If home is in the edit mode.
    VfxBool m_isInEditMode;

// Implementation
private:
    // This function toggles the edit mode.
    void toggleEditMode(
        VfxBool isOn,                   // [IN] Toggle to on or off
        VfxBool isAnimatable = VFX_TRUE // [IN] Animate it?
    );

//
// This block implements the page selector.
//

// Variable
private:
    // Page selector.
    VappLauncherRobotPageSelector *m_pageSelector;

    // Page selector used when there is out of space (OOS).
    VappLauncherRobotPageSelector *m_pageSelectorOos;

    // Page selector used when we drag the widget to touch a special control,
    // e.g., the page indicator. DnD stands for "Drag-and-Drop".
    VappLauncherRobotPageSelector *m_pageSelectorDnd;

    // Timer to launch the page selector when we drag the widget to touch a
    // special control, e.g., the page indicator.
    VfxTimer *m_timerLaunchPageSelectorDnd;

    // If page does not have space for the widget.
    VfxBool m_isPageFull[VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM];

// Implementation
private:
    // This function launches the page selector.
    void launchPageSelector();

    // This function handles the "assembled" signal.
    void onPageSelectorAssembled(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function handles the "selected" signal.
    void onPageSelectorSelected(
        VappLauncherRobotPageSelector *pageSelector, // [IN] Page selector
        VfxS32 idx                          // [IN] The selected page index
    );

    // This function handles the "aborted" signal.
    void onPageSelectorAborted(
        VappLauncherRobotPageSelector *pageSelector,         // [IN] Page selector
        VappLauncherRobotPageSelector::AbortCauseEnum cause  // [IN] Error cause
    );

    // This function handles the "dismissed" signal.
    void onPageSelectorDismissed(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function launches the page selector.
    void launchPageSelectorOos(
        VappWidget *widget      // [IN] Widget needing this page selector
    );

    // This function handles the "assembled" signal.
    void onPageSelectorOosAssembled(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function handles the "selected" signal.
    void onPageSelectorOosSelected(
        VappLauncherRobotPageSelector *pageSelector, // [IN] Page selector
        VfxS32 idx                          // [IN] The selected page index
    );

    // This function handles the "aborted" signal.
    void onPageSelectorOosAborted(
        VappLauncherRobotPageSelector *pageSelector,         // [IN] Page selector
        VappLauncherRobotPageSelector::AbortCauseEnum cause  // [IN] Error cause
    );

    // This function handles the "dismissed" signal.
    void onPageSelectorOosDismissed(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function launches the page selector.
    void launchPageSelectorDnd(
        VappWidget *widget      // [IN] Widget needing this page selector
    );

    // This function handles the "assembled" signal.
    void onPageSelectorDndAssembled(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function handles the "selected" signal.
    void onPageSelectorDndSelected(
        VappLauncherRobotPageSelector *pageSelector, // [IN] Page selector
        VfxS32 idx                          // [IN] The selected page index
    );

    // This function handles the "aborted" signal.
    void onPageSelectorDndAborted(
        VappLauncherRobotPageSelector *pageSelector,         // [IN] Page selector
        VappLauncherRobotPageSelector::AbortCauseEnum cause  // [IN] Error cause
    );

    // This function handles the "dismissed" signal.
    void onPageSelectorDndDismissed(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function creates a page selector.
    // RETURNS: page selector.
    VappLauncherRobotPageSelector *createPageSelector();

    // This function closes the page selector.
    void closePageSelector(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function packs all widgets from the desktop to the page selector.
    void packWidgetToPageSelector(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function unpacks all widgets from the page selector to the desktop.
    void unpackWidgetFromPageSelector(
        VappLauncherRobotPageSelector *pageSelector  // [IN] Page selector
    );

    // This function checks is any page selector present on the home screen.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isPageSelectorPresent();

    void closePageSelector(VappLauncherRobotPageSelector::AbortCauseEnum causeEnum);

//
// This block implements the widget selector and shortcut selector.
//

// Variable
private:
    VfxS32 m_numShortcut;

    // Shortcut selector.
    VappLauncherRobotShortcutSelector *m_shortcutSelector;

    // Widget selector.
    VappLauncherRobotWidgetSelector *m_widgetSelector;

    VfxWeakPtr <VfxLauncherRobotPageSlideTransition> m_pageSlideTransitionWeakPtr;

    // The selected widget or shortcut. Note that a shortcut is just a special
    // kind of widget (i.e., polymorphism).
    VappWidget *m_selectedWidget;

    // there may delete multiple widgets at a single primitive,
    // so needs to record by using obj list
    VfxObjList m_deleteWidgetList;

// Implementation
private:
    // This function launches the shortcut selector.
    void launchShortcutSelector();

    // This function handles the "page transition stop" signal to show the
    // shortcut selector's content.
    void onShowShortcutSelector(
        VfxObject *sender,              // [IN] Page
        VfxBool in,                     // [IN] In or out
        VfxS32 direction                // [IN] History direction
    );

    // clear specific page transition when go back to HS page
    void onLeaveLauncherPageTransition(VfxBool in, VfxS32 direction);

    // This function launches the widget selector.
    void launchWidgetSelector();

    // This function handles the "page transition stop" signal to show the
    // widget selector's content.
    void onShowWidgetSelector(
        VfxObject *sender,              // [IN] Page
        VfxBool in,                     // [IN] In or out
        VfxS32 direction                // [IN] History direction
    );

    // This function handles the signal that a widget or shortcut is selected.
    // Note that a shortcut is just a special kind of widget
    // (i.e., polymorphism).
    void onWidgetSelected(
        VfxPage *page,                  // [IN] Page
        const VappWidgetId &widgetId    // [IN] The selected widget's ID
    );

    // This function handles the signal emited when the shortcut or widget
    // selector page is closed completely. We add shortcut or widget to desktop
    // until the animation is finished for performance.
    void onInstallWidget(
        VfxObject *sender,      // [IN] Page
        VfxBool in,             // [IN] In or out
        VfxS32 direction        // [IN] History direction
    );

//
// This block implements the widgets.
//

// Variable
private:
    // Widget that is being dragged.
    VappWidget *m_dndWidget;

#if defined(__COSMOS_3D_V10__)
    // Color material.
    VappLauncherRobotColorMaterial *m_alertMaterial;
#else
    // Color filter.
    VappLauncherRobotColorFilter *m_alertFilter;
#endif /* defined(__COSMOS_3D_V10__) */

    // Pen offset from widget's centra to the pen down position.
    VfxPoint m_penOffset;

    // record origin widget page index when drag it.
    VfxS32 m_widgetPageIndex;

    // The list of widgets that are put on the desktop.
    VfxObjList m_widgetList;

    // Scaling ratio of the widget when it is under the drag-and-drap (DnD)
    // period. To disable it, set it to -1. Note that if the value is too large,
    // the performance will downgrade much. */
    const static VfxFloat s_dndScaleRatio;

    // Opacity of the widget when it is under the drag-and-drop (DnD) period.
    const static VfxFloat s_dndOpacity;

    // Starting opacity of the widget when the handset goes back to the home
    // screen.
    const static VfxFloat s_landingOpacity;

    // Min color of the alert color filter.
    const static VfxColor s_alertFilterMin;

    // Max color of the alert color filter.
    const static VfxColor s_alertFilterMax;

// Implementation
private:
    // This block implements the widgets related functionalities, including
    // Drag-and-Drop (DnD) and delete, and etc.

    // This function creates the widgets when we launch the home screen.
    void createWidget();

    // This function creates the pre-installed widget.
    void createPreInstalledWidget();

    // This function creates the widgets in the archive which stored with RAM.
    void createArchivedWidgetFromRAM();

    // This function creates the widgets in the archive.
    void createArchivedWidget();

    // This function releases all the created widgets.
    void releaseWidget();

    // This function handles the widget's "drag" signal.
    void onDragWidget(
        VappWidget *widget,     // [IN] Widget
        VfxPenEvent &event      // [IN] Pen event.
    );

    // This function handles the widget's "move" signal.
    void onMoveWidget(
        VappWidget *widget,     // [IN] Widget
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function handles the widget's "drop" signal.
    void onDropWidget(
        VappWidget *widget,     // [IN] Widget
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function handles the widget's "abort" signal.
    void onAbortWidget(
        VappWidget *widget,     // [IN] Widget
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function handles the widget's "deselect" signal.
    void onDeselectWidget(
        VappWidget *widget      // [IN] Widget
    );

    // This function handles the 2nd pass delete widget.
    void onDeleteWidget();

    // This function handles the widget's signal to forbid to swipe the desktop.
    void onForbidDesktopSwipe(
        VappWidget *widget      // [IN] Widget
    );

    // This function handles the widget's signal to permit to swipe the desktop.
    void onPermitDesktopSwipe(
        VappWidget *widget      // [IN] Widget
    );

    // This function handles the timer to launch the page selector when we drag
    // the widget to touch a special frame, e.g., the page indicator.
    void onLaunchPageSelectorDnd(
        VfxTimer *timer         // [IN] Timer
    );

    // This function activates the widget. If the "archiveFile" is NULL, it
    // means it is the first time we creates this widget. In this case, the
    // widget will generate a unique archive filename for itself.
    void activateWidget(
        VappWidget *widget         // [IN] Widget
    );

    // This function activates the widget on the specified page of the desktop.
    void activateWidgetOnDesktop(
        VappWidget *widget,     // [IN] Widget
        VfxS32 idx              // [IN] Page index
    );

    // This function serializes the all the created widgets to save memory.
    //
    // SEE ALSO: restoreWidget
    void serializeWidget();

    // This function restores all the created widget.
    //
    // SEE ALSO: serializeWidget
    void restoreWidget();

    // This function serializes the all the created widgets to save memory when page switch.
    //
    // SEE ALSO: restoreWidgetForPageSwitch
    void serializeWidgetForPageSwitch();

    // This function restores all the created widget.
    //
    // SEE ALSO: serializeWidgetForPageSwitch
    void restoreWidgetForPageSwitch();

    // This function suspends the all the created widgets to improve performance
    void suspendWidget();

    // This function resumes all the created widget.
    void resumeWidget();

    // This function updates the focus of all created widget.
    void updateWidgetFocus(
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function updates the visibility of all created widgets.
    void updateWidgetVisible();

    // This function sets all the created widgets to slim view or not.
    void setWidgetSlim(
        VfxBool isSlim      // [IN] Slim view or not
    );

    // This function sets the widget to have alert effect or not.
    void setWidgetAlertEffect(
        VappWidget *widget, // [IN] Widget
        VfxBool isOn        // [IN] Alert effect is on or not
    );

    // This function sets the widget to have drag-and-drop (DnD) effect or not.
    void setWidgetDndEffect(
        VappWidget *widget, // [IN] Widget
        VfxBool isOn        // [IN] DnD effect is on or not
    );

    // This function sets all the created widget to have landing effect. Landing
    // effect is used when we return to home screen from other applications.
    void setWidgetLandingEffect();

    // This function checks if the widget is visible.
    VfxBool isWidgetVisible(
        const VappWidget *widget    // [IN] Widget
    ) const;

    // This function calculates the offset from the centra of the frame to the
    // pen position.
    // RETURNS: the offset
    VfxPoint calcOffset(
        const VfxFrame *frame,      // [IN] Frame
        const VfxPenEvent &event    // [IN] Pen position
    ) const;

    // This function calculates the new position of the frame according to the
    // pen position minus the offset.
    // RETURNS: the position
    VfxPoint calcPosition(
        const VfxFrame *frame,      // [IN] Frame
        VfxPenEvent &event,         // [IN] Pen position
        const VfxPoint &offset      // [IN] Offset from centra to the pen pos.
    ) const;

// Implementation
private:
    // This block implements the launch function used in the post-invoke.

    // Launch the call log application.
    void launchCallLog(
        void *userData              // [IN] User data
    );

    // Launch the dialer application.
    void launchDialer(
        void *userData              // [IN] User data
    );

#ifdef __MMI_GB_WINGUO__
    //Launcher the winguo application.
    void launchWinguo(
        void *userData              // [IN] User_data
    );
#endif

    // Launch the dialer application.
    void launchDialerWithKey(
        void *userData              // [IN] User data
    );

    // Launch the browser application.
    // TODO: Browser can not use the app mgr to launch because it has two type (Q03C/OPERA)
    //       So it can not be registered in the shortcut callback table with package name,
    //       after it is supported with the same package name, these launch app function can be
    //       deleted by using app manager api: srv_appmgr_launch(package)
    void launchBrowser(void *userData);

// Implementation
private:
    // This block implements the archive functions used to save settings.

    // Is the setting is new? E.g., when the phone boots up at the first time,
    // the setting is new. E.g., after the factory reset, the setting is new.
    // RETURNS: on yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isNewSetting() const;

    // Set the flag, which is used to check if the setting is new or not.
    void setIsNewSetting(
        VfxBool value               // [IN] New or not
    );

    // Create the archive. 'mode' is 'r' for the read-only mode. 'mode' is 'w'
    // for the write-only mode.
    // RETURNS: archive.
    VfxArchive *createArchive(
        VfxU16 index,               // [IN] Index of the archive.
        VfxChar mode                // [IN] mode
    );

// Implementation
private:
    // This block implements the help functions.

    // This function displays the error popup.
    void displayErrorPopup(
        VcpPopupTypeEnum type,                      // [IN] Popup type
        VcpConfirmPopupButtonSetEnum buttonType,    // [IN] Button type
        const VfxWChar *string                      // [IN] Error message
    );

    // This function calculates the distance between these 2 points.
    VfxS32 calcDistance(
        const VfxPoint &p1,     // [IN] Point 1
        const VfxPoint &p2      // [IN] Point 2
    );

    // This function checks if the pen moves in horizontal direction.
    VfxBool isHorizontalPenMove(
        const VfxPenEvent &event    // [IN] Pen event
    );

    // This function changes the folding of the bars.
    void setBarFolding(
        VfxBool isFolded,                   // [IN] Fold bars or not
        VfxBool isAnimatable = VFX_FALSE    // [IN] Animate bar's folding or not
    );
};


/*****************************************************************************
 * Class VfxLauncherRobotPageSlideTransition
 *****************************************************************************/

class VfxLauncherRobotPageSlideTransition : public VfxPageSlideTransition
{
    VFX_DECLARE_CLASS(VfxLauncherRobotPageSlideTransition);
    
    virtual VfxBool customOuted();
};

#endif /* VAPP_LAUNCHER_ROBOT_DIRECTOR_H */

