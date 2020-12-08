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
 *  vapp_hs_scr.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen APP category
 *
 * Author:
 * -------
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
 *
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
 *
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
 *
 *
 * removed!
 * removed!
 *
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

#ifndef __VAPP_HS_SCR_H__
#define __VAPP_HS_SCR_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_timer.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"
#include "vfx_frame.h"
#include "vfx_control.h"
#include "vdat_network_info.h"
#include "vapp_hs_widget_base.h"        // for base widget class define
#include "vapp_hs_cp.h"                 // for home screen components define
#include "vapp_hs_shortcut_panel.h"
#include "vapp_hs_widget_mgr.h"
#include "vapp_shell_panel.h"


class VappWallpaper;


/*****************************************************************************
 * Class VappHsScr
 *****************************************************************************/

/*
 * This class implements the Venus home screen.
 *
 * EXAMPLE
 * <code>
 *  VappHsScr *category;
 *
 *  void mmi_entry_screen(void)
 *  {
 *      EntryNewScreen(SCREEN_ID, mmi_entry_screen, mmi_exit_screen, NULL);
 *
 *      VcpAppScr::initalize();
 *
 *      VFX_OBJ_CREATE_EX(
 *          category,
 *          VappHsScr,
 *          VcpAppScr::getContext(),
 *          (setting, history));    // constructor parameters
 *
 *      category->registerSettingChangedHandler(cbf);
 *  }
 *
 *
 *  void mmi_exit_screen(void)
 *  {
 *      VFX_OBJ_CLOSE(category);
 *
 *      VcpAppScr::deinitalize();
 *  }
 * </code>
 */
class VappHsScr : public VappShellPanel
{
    VAPP_SHELL_PANEL_CREATE(VappHsScr, VFX_FALSE);

// Constructor / Destructor
public:
    // Default constructor
    VappHsScr();

// Method
public:
    // This function checks if both the widget bar and the shortcut pool are
    // close.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isAllFold();

    // This function closes both the widget bar and the shortcut pool.
    void foldAll();

    // This function rotates the desktop. If the active desktop is the last one,
    // it changes the active desktop to the first one.
    void rotateDesktop();

// Method
private:
    
    // This function is used to resume wallpaper when timeout after bootup
    // only callback once
    void onResumeWallpaper(VfxTimer *timer);

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onInitView();

    virtual void onDeinitView();

    virtual void onEnterView();

    virtual void onExitView(ShellExitCauseEnum cause);

    virtual void onScreenEnter(VfxBool isBackward);

    virtual void onScreenExit(VfxBool isBackward);

    virtual void onSwitchBegin(VfxBool isSwitchOut);

    virtual void onSwitchEnd();

    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Declaration
private:
    enum
    {
        DEFAULT_AUTO_ANIMATE_TIME   = 250,
        IDLE_MODE_TEXT_GAP_Y        = 15,
        INDICATOR_GAP_X             = 7,
    #if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__)
        INDICATOR_GAP_Y             = 67,
    #else
        INDICATOR_GAP_Y             = 53,
    #endif
        END_OF_ENUM
    };

    // Wallpaper setting confirm enum
    enum
    {
        WALLPAPER_LIVE,
        WALLPAPER_GALLERY,
        WALLPAPER_FMGR,
        WALLPAPER_CANCEL,
        WALLPAPER_TOTAL
    };

// Variable
private:
    // This block declares the variables related to the setting and history.

    // If widget bar is open, it is VFX_TRUE; otherwise, it is VFX_FALSE.
    static VfxBool          s_is_widget_bar_opened;

    // wallpaper will resume after bootup Initiation (1 sec)
    static VfxBool           s_bootupInit;

    // The horizontal position of the desktop.
    static VfxS32           s_desktop_pos;

    // The vertical position of the widget bar.
    static VfxS32           s_widget_bar_pos;
 
// Variable
private:
    // This block declares the UI component of the App category.

    // Background image frame
    VappWallpaper          *m_wallpaper;

    // Idle mode text and icon
    VappHsIdleModeText     *m_idleModeText;

    // Widget bar
    VappHsWidgetBar        *m_widgetBar;

    // Desktop
    VappHsDesktop          *m_desktop;

#if defined(VAPP_HS_CFG_MULTI_DESKTOP)
    // Desktop indicator (or called navigation dot)
    VappHsDesktopIndicator *m_desktopIndicator;
#endif

#if defined(VAPP_HS_CFG_SHORTCUT_PANEL)
    // Shortcut panel
    VappHsShortcutPanel    *m_shortcutPanel;
#endif

#if defined(__MMI_SEARCH_WEB_GOOGLE__)
    VappHsSearchBar        *m_searchBar;
#endif

    // Widget manager
    VappHsWidgetMgr        *m_widgetMgr;

// Variable
private:
    // This block declares the variables related to the Drag-and-Drop.

    // Moving frame (icon view)
    VappHsDndImage         *m_movingFrameS;

    // Moving frame (widget view)
    VappHsWidget           *m_movingFrameL;

    // Parent of the moving frame (e.g., widget bar, shortcut bar / pool)
    VappHsInteractiveImageArray *m_movingFrameOriParent;

    // Offset from the icon view centra point to the clicked point
    VfxPoint                m_penPointOffsetS;

    // Offset from the widget view centra point to the clicked point
    VfxPoint                m_penPointOffsetL;

    // Transform matrx from icon view to the widget view (for morphing)
    VfxTransform            m_trS2l;

    // Transform matrix from widget view to the icon view (for morphing)
    VfxTransform            m_trL2s;

    // Timer to add the widget into the widget bar (for dropping)
    VfxTimer               *m_timerAddWidget;

    // Timer to lock the widget on the desktop
    VfxTimer               *m_timerLockWidget;

    // Timer to resume wallpaper after bootup initiation
    VfxTimer               *m_timerResumeWallpaper;
    
    // Delay time to lock the widget on the desktop
    static const VfxS32     s_lockWidgetDelayedTime;

    // Max. number of widgets on the desktop
    static const VfxS32     s_maxDeskTopWidget;

    // The opacity when the widget or shortcut is moving
    static const VfxFloat   s_moveOpacity;

// Variable
private:
    // This block declares the variable related to the "auto. close of the
    // widget bar" feature.

    // Timer to close the widget bar automatically
    VfxTimer               *m_timerCloseWidgetBar;

    // The delay to close the widget bar automatically
    static const VfxS32     s_closeWidgetBarDelay;

// Variable
private:
    // This block declares the variables related to reset a widget. "Reset a 
    // widget" means it will be put back to the widget bar on the next time.

    // Widget Type
    VfxS32                  m_widgetType;

    // Widget Id
    VfxS32                  m_widgetId;

    // Error string ID
    VfxS32                  m_errStrId;

// Variable
private:
    // This block declares the variables related to the pen event handler.

    // If long-press is workable for the wallpaper setting option menu.
    VfxBool                 m_longPressEnable;

    // If the pen down event is received.
    VfxBool                 m_isRecvPenDown;

    // The max. allowable offset that the long-press event can still work.
    static const VfxS32     s_penOffsetThreshold;

// Variable
private:
    // If wallpaper suspends when the screen exits.
    VfxBool m_isSuspendForScreenExit;

// Implementation
private:
    // This block implements the functions to init / deinit components.

    // This function initializes the wallpaper.
    void initWallpaper();

    // This function deinitializes the wallpaper.
    void deinitWallpaper();

    // This function initializes the idle mode text.
    void initIdleModeText();

    // This function deinitializes the idle mode text.
    void deinitIdleModeText();

    // This function initializes the desktop.
    void initDesktop();

    // This function deinitializes the desktop.
    void deinitDesktop();

    // This function initializes the desktop indicator.
    void initDesktopIndicator();

    // This function deinitializes the desktop indicator.
    void deinitDesktopIndicator();

    // This function initializes the shortcut panel.
    void initShortcutPanel();

    // This function deinitializes the shortcut panel.
    void deinitShortcutPanel();

    // This function initializes the search bar.
    void initSearchBar();

    // This function deinitializes the search bar.
    void deinitSearchBar();

    // This function initializes the timer.
    void initTimer();

    // This function deinitializes the timer.
    void deinitTimer();

    // This function initializes the widget bar.
    void initWidget();

    // This function deinitializes the widget bar.
    void deinitWidget();

    // This function initializes the widget.
    void activateWidget();

    // This function deinitializes the widget.
    void deactivateWidget();
    
// Implementation
private:
    // This block implements the help functions for the Drag-and-Drop mechanism
    // of the widget and shortcut.

    // This function gets the number of widgets on the desktop.
    // RETURNS: the number of active widgets.
    VfxS32 getActiveWidgetNum();

    // Generally, the anchor point of the widget or the shortcut is located
    // in the centra point of the frame. But, when the user starts to drag the
    // object, we change the anchor point to the point that the user clicks. In
    // this way, the transformation, e.g. zoom-out, can be applied from the
    // position that the user clicks.
    void setAnchor(
        VfxFrame *frame,    // [IN]  Frame to be changed
        VfxPoint &offset    // [IN]  Offset of the new anchor from the centra
    );

    // This function resets the anchor of the widget or the shortcut to its
    // centra point.
    void resetAnchor(
        VfxFrame *frame,    // [IN]  Frame to be changed
        VfxPoint &offset    // [IN]  Offset of the anchor from the centra
    );

    // This function calculates the scaling ratio from the frame "from" to the
    // frame "to". The result is stored in "x" and "y" for the horizontal and
    // vertical scaling ratio.
    void getScaleRatio(
        VfxFrame *to,       // [IN]  From this frame
        VfxFrame *from,     // [IN]  To this frame
        VfxFloat &x,        // [OUT] Horizontal scaling ratio
        VfxFloat &y         // [OUT] Vertical scaling ratio
    );

    // This function calculates the offset from the centra of the frame to the
    // pen position.
    void getOffset(
        VfxControl *frame,  // [IN]  Frame
        VfxPenEvent &event, // [IN]  Pen position
        VfxPoint &offset    // [OUT] Offset from the centra to the pen position
    );

// Implementation:
private:
    // This block implements the help functions related to the dropping
    // mechanism of the widget and shortcut.
    //
    // Basically, we first preview the position if the object is dropped.
    // Then, we animate the object in the App category from its current position
    // to its final position such that the object is not clipped by its final
    // parent. When the timer fires, it adds to its final parent actually.

    // This function previews the position after the moving frame is dropped.
    // The 'currentPos' and 'finalPos' are the positions on the App category.
    void previewDrop(
        VappHsInteractiveImageArray *dst, // [IN]   Dest. object for dropping
        VfxPenEvent &event,               // [IN]   Pen event
        VfxPoint &currentPos,             // [OUT]  Position before dropping
        VfxPoint &finalPos                // [OUT]  Position after dropping
    );

    // This function previews the position after the moving frame is aborted for
    // the Drag-and-Drop operation. The 'currentPos' and 'finalPos' are the
    // positions on the App category.
    void previewDropExt(
        VfxPoint &currentPos,   // [OUT] Position before dropping
        VfxPoint &finalPos      // [OUT] Position after dropping
    );

    // This function is the event handler when it is time to add the widget from
    // App category to the widget bar.
    void onTimerAddWidget(
        VfxTimer *timer     // [IN]  "Add widget" timer
    );

    // This function is the event handler when it is time to lock the widget on
    // the desktop.
    void onTimerLockWidget(
        VfxTimer *timer     // [IN]  "Lock widget" timer
    );

// Implementation
private:
    // This block implements the core functions related to the Drag-and-Drop of
    // the widgets.

    // This function sets a widget to begin the Drag-and-Drop process.
    void setWidgetDrag(
        VappHsDndImage *image,  // [IN] Moving frame (icon)
        VappHsWidget *widget,   // [IN] Moving frame (widget)
        VfxPenEvent &event,     // [IN] Pen event
        VfxBool isFromImage     // [IN] Drag from icon or from widget
    );

    // This function sets a widget to move according to the pen move event.
    void setWidgetMove(
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function sets a widget to terminate the Drag-and-Drop process. If
    // the "isRestore" is VFX_TRUE, it means the process is aborted.
    void setWidgetDrop(
        VfxPenEvent &event,     // [IN] Pen event
        VfxBool isRestore);     // [IN] Restore to previous position or not

    // This function is the event handler when the user wants to drag a widget
    // from the widget bar.
    // RETURNS: event handler result
    void onControlWidgetBarDrag(
        VappHsDndImage *image,  // [IN] Moving frame (icon)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is the event handler when the user is moving the widget
    // from the widget bar.
    // RETURNS: event handler result
    void onControlWidgetBarMove(
        VappHsDndImage *image,  // [IN] Moving frame (icon)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is the event handler when the user drops the widget from
    // the widget bar.
    // RETURNS: event handler result
    void onControlWidgetBarDrop(
        VappHsDndImage *image,  // [IN] Moving frame (icon)
        VfxPenEvent &event);    // [IN] Pen event

    // This function is the event handler when the user aborts the Drag-and-Drop
    // process of the widget. For example, when the user actually wants to
    // scroll the widget bar, the widget bar will notify this event.
    // RETURNS: event handler result
    void onControlWidgetBarAbort(
        VappHsDndImage *image,  // [IN] Moving frame (icon)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is the event handler when the user wants to drag a widget
    // from the desktop.
    // RETURNS: event handler result
    void onControlDesktopDrag(
        VappHsWidget *widget,   // [IN] Moving frame (widget)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is the event handler when the user is moving the widget
    // from the desktop.
    // RETURNS: event handler result
    void onControlDesktopMove(
        VappHsWidget *widget,   // [IN] Moving frame (widget)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is the event handler when the user drops the widget from
    // the desktop.
    // RETURNS: event handler result
    void onControlDesktopDrop(
        VappHsWidget *widget,   // [IN] Moving frame (widget)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is the common event handler for the widget.
    // RETURNS: event handler result
    void onControlWidgetRequest(
        VappHsWidget *widget,               // [IN] Widget
        VappHsWidget::RequestId requestId   // [IN] Event Id
    );

    // This function is the handler to reset the widget.
    void onControlWidgetReset(
        VappHsWidget *widget,               // [IN] Widget
        VfxU16 errStringId                  // [IN] Error string ID
    );

// Implementation
private:
    // This block implements the core functions related to the "auto. close of
    // the widget bar" feature.

    // This function is the event handler when the folding of the widget bar is
    // updated.
    // RETURNS: event handler result
    void onWidgetBarUpdateFolding(
        VfxBool isFold          // [IN] the updated folding state
    );

    // This function is the event handler when the "auto. close of the widget
    // bar" timer fires.
    // RETURNS: event handler result
    void onCloseWidgetBar(
        VfxTimer *timer         // [IN] Timer of the auto. close widget bar
    );

// Implementation
private:
    // This block implements the function related to the shortcut panel.

#if defined(VAPP_HS_CFG_SHORTCUT_PANEL)
    // This function is the event handler when teh shortcut panel's folding is
    // changed.
    void onShortcutPanelFolded(
        VappHsShortcutPanel *panel
    );
#endif /* defined(VAPP_HS_CFG_SHORTCUT_PANEL) */

// Implementation
private:
    // This block implements function to rotate the wallpaper when the desktop
    // changes its bounds.

    // This function rotates the wallpaper and highlights the corresponding
    // navigation dot when the desktop changes its bounds.
    void onDesktopBoundsChanged(
        VfxFrame *source,
        const VfxRect &oldBounds
    );

// Implementation
private:
    // This block implements the event handler when the text or icon on the home
    // screen change.

    // This function is the event handler when the idle mode text changes.
    // RETURNS: event handler result
    void onIdleModeTextChanged(
        VdatNetworkInfo *networkSrv // [IN] Network info service instance
    );

    // This function is the event handler when the idle mode icon changes.
    // RETURNS: event handler result
    void onIdleModeIconChanged(
        VdatNetworkInfo *networkSrv // [IN] Network info service instance
    );


// Implementation
private:
    // This block implements the function related to the "delayed widget
    // creation" feature. When the home screen is shown, we will not create all
    // the widgets at the same time. We start a timer to create widgets one by
    // one. The benefits is the entry time of the home screen will be quicker.

    // This function creates all the widgets on the desktop which have not
    // created its widget view.
    void createAllDelayedWidget();

    // This function is the event handler to create the next widgets on the
    // desktop which has not created its widget view.
    // RETURNS: event handler result
    void onTimerCreateWidget(
        VfxTimer *timer         // [IN] Delayed widget creation timer
    );

// Implementation
private:
    // This block implements some misc. functions for the App category.

    // This function gets the screen size.
    // RETURNS: screen size
    VfxSize getScreenSize();

    // This function is the post invoke handler to display a error popup.
    void popupError(
        void *data          // [IN] Error string ID
    );

#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__)
// Implementation
private:
    // This block implements wallpaper setting confirm popup after long press HS

    // This function show wallpaper setting popup confirm
    void showWallpaperConfirm(void);

    // This function determine and excute callback function
    void onCommandPopCallback(VfxObject *obj, VfxId id);
#endif /* defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) */
};

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VAPP_HS_SCR_H__ */

