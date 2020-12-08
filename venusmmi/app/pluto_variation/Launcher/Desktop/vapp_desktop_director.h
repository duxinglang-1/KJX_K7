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
 *  vapp_desktop_director.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the desktop director.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_DESKTOP_DIRECTOR_H
#define VAPP_DESKTOP_DIRECTOR_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_status_icon_bar.h"
#include "vapp_app_widget.h"
#include "vapp_app_widget_archive.h"
#include "vapp_wallpaper.h"
#include "vapp_desktop.h"
#include "vapp_desktop_def.h"
#include "vapp_desktop_page.h"
#include "vapp_desktop_bar.h"
#include "vapp_desktop_page_selector.h"
#include "vapp_desktop_shortcut_selector.h"
#include "vapp_desktop_widget_selector.h"


/*****************************************************************************
 * Desktop Director Object
 *****************************************************************************/

class VappDesktopDirector : public VfxAppCatScr
{
    VFX_DECLARE_CLASS(VappDesktopDirector);

// Constructor / Destructor
public:
    // Default constructor
    VappDesktopDirector();

// Variable
private:
    static VfxBool s_isHistoryValid;
    static VfxBool s_isInEditMode;
    static VfxS32 s_pageIndex;

public:
    MMI_ID m_groupId;

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // While leaving the screen to be inactive
    virtual void onExit(VfxBool isBackward);

    // Please refer to VfxFrame.
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    // revise for rarely used virtual function
    void onAfterInit();

    // revise for rarely used virtual function
    void onBeforeDeinit();

    // revise for rarely used virtual function
    void onAfterDeinit();

    // revise for rarely used virtual function
    virtual void onObjectNotify(VfxId id,void * userData);

// Enum
private:
    enum
    {
        // Delayed time, in msec., to load the wallpaper. Because loading the
        // wallpaper takes time, if the handset will hang for a while when it
        // just enters the home screen, please tune this parameter.
        WALLPAPER_CREATE_DELAY_TIME = 600,
        WALLPAPER_NORMAL_DELAY_TIME = 300,
        WALLPAPER_SWIPE_DELAY_TIME = 500,

        // The offset in pixels that the desktop will capture the pen event and
        // start to slide when the user taps the touch screen.
        SLIDE_START_OFFSET = VAPP_APP_WIDGET_DND_CRITERIA,

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

//
// This block implements the handler for the pen input
//

// Override
protected:
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

// Implementation
private:
    // This function creates the wallpaper. The 'delayTime' controls the delay
    // time, in msec., that we will start to animate this wallpaper. If its
    // value is negative, we do not animate it. If its value is 0, we animate
    // it immediately.
    void createWallpaper(
        VfxMsec delayTime = 0   // [IN] Delay time to animate this wallpaper
    );

    // This function releases the wallpaper.
    void releaseWallpaper();

    // This function resumes the wallpaper after the specified time.
    void delayResumeWallpaper(
        VfxMsec delayTime       // [IN] Delay time to resume the wallpaper
    );

    // This function is the time-out handler to resume and animate the wallpaper
    // after we create it.
    void onResumeWallpaper(
        VfxTimer *timer         // [IN] Timer
    );

//
// This block implements the desktop.
//

// Variable
private:
    // Page.
    VappDesktopPage *m_desktop;

    // Timer to detect if we should auto. slide the desktop.
    VfxTimer *m_timerAutoSlidePage;

    // If we capture the pen event.
    VfxBool m_isCaptured;

    // If pen event is captured, is it captured from other child control?
    VfxBool m_isCapturedFromOthers;

    // When desktop is swipped, suspend the wallpaper for performance.
    VfxBool m_isSuspendWallpaperForSwipe;

    // List of objects that request that we cannot swipe the desktop.
    VfxObjList m_cannotSwipeRequest;

    // List of objects that request that we cannot swipe the desktop if the pen
    // event is received by them or by their parent.
    VfxObjList m_cannotSwipeList;

// Implementation
private:
    // This function creates the desktop.
    void createPage();

    // This function releases the desktop.
    void releasePage();

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
        VappDesktopPage *desktop    // [IN] Page
    );

    // This function handles the signal that the bounds of the desktop is
    // changed.
    void onDesktopBoundsChanged(
        VfxFrame *frame,            // [IN] Desktop
        const VfxRect &oldBounds    // [IN] Old bounds
    );

    // This function handles the timer to auto slide the desktop.
    void onAutoSlidePage(
        VfxTimer *timer             // [IN] Timer
    );

//
// This block implements the page indicator bar.
//

// Variable
private:
    // Indicator.
    VappDesktopPageIndicator *m_indicator;

// Implementation
private:
    // This function creates the page indicator.
    void createPageIndicator();

    // This function releases the page indicator.
    void releasePageIndicator();

    // This function handles the indicator clicked signal.
    void onIndicatorClicked(
        VappDesktopPageIndicator *indicator    // [IN] Indicator
    );

//
// This block implements the shortcut bar.
//

// Variable
private:
    // Shortcut bar.
    VappDesktopShortcutBar *m_shortcutBar;

// Implementation
private:
    // This function creates the shortcut bar.
    void createShortcutBar();

    // This function releases the shortcut bar.
    void releaseShortcutBar();

//
// This block implements the toolbar.
//

// Variable
private:
    // Toolbar.
    VappDesktopToolbar *m_toolbar;

// Implementation
private:
    // This function creates the toolbar.
    void createToolbar();

    // This function releases the toolbar.
    void releaseToolbar();

    // This function is the callback function when a button on the toolbar is
    // clicked.
    void onToolbarExecute(
        VappDesktopToolbar *toolbar,           // [IN] Toolbar
        VappDesktopToolbar::ButtonEnum button  // [IN] The clicked button
    );

// Implementation
private:
    // Status icon bar.
    VcpStatusIconBar *m_statusIconBar;

// Implementation
private:
    // This function creates the status icon bar.
    void createStatusIconBar();

    // This function releases the status icon bar.
    void releaseStatusIconBar();

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
    VappDesktopPageSelector *m_pageSelector;

    // Page selector used when there is out of space (OOS).
    VappDesktopPageSelector *m_pageSelectorOos;

    // Page selector used when we drag the widget to touch a special control,
    // e.g., the page indicator. DnD stands for "Drag-and-Drop".
    VappDesktopPageSelector *m_pageSelectorDnd;

    // Timer to launch the page selector when we drag the widget to touch a
    // special control, e.g., the page indicator.
    VfxTimer *m_timerLaunchPageSelectorDnd;

    // If page does not have space for the widget.
    VfxBool m_isPageFull[VAPP_DESKTOP_MAX_PAGE_NUM];

// Implementation
private:
    // This function launches the page selector.
    void launchPageSelector();

    // This function handles the "assembled" signal.
    void onPageSelectorAssembled(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

    // This function handles the "selected" signal.
    void onPageSelectorSelected(
        VappDesktopPageSelector *pageSelector, // [IN] Page selector
        VfxS32 idx                          // [IN] The selected page index
    );

    // This function handles the "aborted" signal.
    void onPageSelectorAborted(
        VappDesktopPageSelector *pageSelector,         // [IN] Page selector
        VappDesktopPageSelector::AbortCauseEnum cause  // [IN] Error cause
    );

    // This function handles the "dismissed" signal.
    void onPageSelectorDismissed(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

    // This function launches the page selector.
    void launchPageSelectorOos(
        VappAppWidget *widget      // [IN] Widget needing this page selector
    );

    // This function handles the "assembled" signal.
    void onPageSelectorOosAssembled(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

    // This function handles the "selected" signal.
    void onPageSelectorOosSelected(
        VappDesktopPageSelector *pageSelector, // [IN] Page selector
        VfxS32 idx                          // [IN] The selected page index
    );

    // This function handles the "aborted" signal.
    void onPageSelectorOosAborted(
        VappDesktopPageSelector *pageSelector,         // [IN] Page selector
        VappDesktopPageSelector::AbortCauseEnum cause  // [IN] Error cause
    );

    // This function handles the "dismissed" signal.
    void onPageSelectorOosDismissed(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

    // This function launches the page selector.
    void launchPageSelectorDnd(
        VappAppWidget *widget      // [IN] Widget needing this page selector
    );

    // This function handles the "assembled" signal.
    void onPageSelectorDndAssembled(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

    // This function handles the "selected" signal.
    void onPageSelectorDndSelected(
        VappDesktopPageSelector *pageSelector, // [IN] Page selector
        VfxS32 idx                          // [IN] The selected page index
    );

    // This function handles the "aborted" signal.
    void onPageSelectorDndAborted(
        VappDesktopPageSelector *pageSelector,         // [IN] Page selector
        VappDesktopPageSelector::AbortCauseEnum cause  // [IN] Error cause
    );

    // This function handles the "dismissed" signal.
    void onPageSelectorDndDismissed(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

    // This function creates a page selector.
    // RETURNS: page selector.
    VappDesktopPageSelector *createPageSelector();

    // This function closes the page selector.
    void closePageSelector(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

    // This function packs all widgets from the desktop to the page selector.
    void packWidgetToPageSelector(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

    // This function unpacks all widgets from the page selector to the desktop.
    void unpackWidgetFromPageSelector(
        VappDesktopPageSelector *pageSelector  // [IN] Page selector
    );

//
// This block implements the widget selector and shortcut selector.
//

// Variable
private:
    // Shortcut selector.
    VappDesktopShortcutSelector *m_shortcutSelector;

    // Widget selector.
    VappDesktopWidgetSelector *m_widgetSelector;

    // The selected widget.
    VappAppWidget *m_selectedWidget;

	// The widget which will be deleted after deselect timer callback
	VappAppWidget *m_deleteWidget;

    // The selected widget or shortcut. Note that a shortcut is just a special
    // kind of widget (i.e., polymorphism).
    static VappAppWidgetId s_selectedWidgetId;

// Implementation
private:
    // This function handles the case that a widget is selected from the widget
    // or shortcut selector.
    static void onWidgetSelected(
        const VappAppWidgetId &id   // [IN] The selected widget Id.
    );

    // This function layouts the selected widget.
    void layoutWidget();

    // This function handles the signal emited when the shortcut or widget
    // selector page is closed completely. We add shortcut or widget to desktop
    // until the animation is finished for performance.
    void onPostLayoutWidget();

//
// This block implements the widgets.
//

// Variable
private:
    // Widget that is being dragged.
    VappAppWidget *m_dndWidget;

    // Color filter.
    VappDesktopColorFilter *m_alertFilter;

    // Pen offset from widget's centra to the pen down position.
    VfxPoint m_penOffset;

    VfxTimer *m_timerWidgetFly;

    // The list of widgets that are put on the desktop.
    VfxObjList m_widgetList;

    // Scaling ratio of the widget when it is pulled out from the desktop.
    const static VfxFloat s_dndScaleRatio;

    // Opacity of the widget when it is under the drag-and-drop (DnD) period.
    const static VfxFloat s_dndOpacity;

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

    // This function creates the widgets in the archive.
    void createArchivedWidget();

    // This function releases all the created widgets.
    void releaseWidget();

    // This function saves the widget to the archive file.
    void saveArchivedWidget();

    void onFlyingFinished(
        VfxTimer *timer
    );

    // This function handles the widget's "drag" signal.
    void onDragWidget(
        VappAppWidget *widget,     // [IN] Widget
        VfxPenEvent &event      // [IN] Pen event.
    );

    // This function handles the widget's "move" signal.
    void onMoveWidget(
        VappAppWidget *widget,     // [IN] Widget
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function handles the widget's "drop" signal.
    void onDropWidget(
        VappAppWidget *widget,     // [IN] Widget
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function handles the widget's "abort" signal.
    void onAbortWidget(
        VappAppWidget *widget,     // [IN] Widget
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function handles the widget's "deselect" signal.
    void onDeselectWidget(
        VappAppWidget *widget      // [IN] Widget
    );

    // This function delete widget
    void onDeleteWidget();

    // This function handles the timer to launch the page selector when we drag
    // the widget to touch a special frame, e.g., the page indicator.
    void onLaunchPageSelectorDnd(
        VfxTimer *timer         // [IN] Timer
    );

    // This function activates the widget. If the "archiveFile" is NULL, it
    // means it is the first time we creates this widget. In this case, the
    // widget will generate a unique archive filename for itself.
    void activateWidget(
        VappAppWidget *widget       // [IN] Widget
    );

    // This function activates the widget on the specified page of the desktop.
    void installWidgetOnPage(
        VfxBool activate,           // [IN] Activate the widget or not
        VappAppWidget *widget,      // [IN] Widget
        VfxS32 idx                  // [IN] Page index
    );

    // This function sets all the created widgets to slim view or not.
    void setWidgetSlim(
        VfxBool isSlim      // [IN] Slim view or not
    );

    // This function sets all the created widgets to edit mode or not.
    void setWidgetEditMode(
        VfxBool isOn        // [IN] Edit mode or not
    );

    // This function sets the widget to have alert effect or not.
    void setWidgetAlertEffect(
        VappAppWidget *widget, // [IN] Widget
        VfxBool isOn        // [IN] Alert effect is on or not
    );

    // This function sets the widget to have drag-and-drop (DnD) effect or not.
    void setWidgetDndEffect(
        VappAppWidget *widget, // [IN] Widget
        VfxBool isOn        // [IN] DnD effect is on or not
    );

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
        const VfxPenEvent &event,   // [IN] Pen position
        const VfxPoint &offset      // [IN] Offset from centra to the pen pos.
    ) const;

//
// This block implements the mechanism to provide additional memory for VRT's
// cache.
//

// Struct
private:
    class PopupContext : public VfxBase
    {
    public:
        VfxResId stringId;
        mmi_event_notify_enum type;
    };

// This block implements the help functions.

// Implementation
private:

    // This function displays the error popup.
    void displayErrorPopup(
        PopupContext *userData  // [IN] User data
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

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_DIRECTOR_H */

