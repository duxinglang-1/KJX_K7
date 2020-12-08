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
 *  vapp_hs_shortcut_panel.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the classes for the shortcut panel.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_HS_SHORTCUT_PANEL_H__
#define __VAPP_HS_SHORTCUT_PANEL_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

#include "vfx_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_control.h"
#include "vfx_basic_type.h"
#include "vfx_datatype.h"
#include "vfx_primitive_frame.h"
#include "vfx_timer.h"
#include "vfx_input_event.h"
#include "vapp_hs_cp.h"
#include "vapp_hs_shortcut_mgr.h"


/*****************************************************************************
 * Venus home screen shortcut (base class)
 *****************************************************************************/

class VappHsShortcutPanel : public VfxFrame
{
public:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        SHORTCUT_BAR_HEIGHT = 62
    #else
        SHORTCUT_BAR_HEIGHT = 47
    #endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsShortcutPanel();

// Signal
public:
    VfxSignal1 <VappHsShortcutPanel *> m_signalFolded;

// Method
public:
    static void foldState();

    void fold();

    VfxBool isUnFold();

    void hide(VfxBool isHidden, VfxBool isEnforced = VFX_FALSE);

    VfxBool isHidden();

    VfxControl *getFirstShortcut();

    VfxControl *getNextShortcut();

    VfxSize getBarSize();

    void cancelShortcutDrop();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onContainPoint(const VfxPoint &point) const;

// Declaration
private:
    enum
    {
        DEFAULT_AUTO_ANIMATE_TIME   = 250,
    #if defined(__MMI_MAINLCD_320X240__)
        MAX_SHORTCUT_IN_BAR         = 7,
    #else
        MAX_SHORTCUT_IN_BAR         = 5,
    #endif /* defined(__MMI_MAINLCD_320X240__) */
        END_OF_ENUM
    };

// Variable
private:
    // The opacity when the widget or shortcut is moving
    static const VfxFloat   s_moveOpacity;

    VfxImageFrame          *m_bgImg;

    // Black screen used when the shortcut pool is open
    VappHsBlackScreen      *m_blackScreen;

    // Shortcut bar
    VappHsShortcutBar      *m_shortcutBar;

    // Shortcut pool
    VappHsShortcutPool     *m_shortcutPool;

    // Shortcut manager
    VappHsShortcutMgr      *m_shortcutMgr;

    // Moving frame (icon view)
    VappHsDndImage         *m_movingFrameS;

    // Parent of the moving frame (e.g., widget bar, shortcut bar / pool)
    VappHsInteractiveImageArray *m_movingFrameOriParent;

    // Offset from the icon view centra point to the clicked point
    VfxPoint                m_penPointOffsetS;

    // Timer to add the shortcut into the shortcut bar / pool (for dropping)
    VfxTimer               *m_timerAddShortcut;

    static VfxBool          s_isPoolOpened;

    static VfxBool          s_isHidden;

// Implementation
private:
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

    // This function calculates the offset from the centra of the frame to the
    // pen position.
    void getOffset(
        VfxControl *frame,  // [IN]  Frame
        VfxPenEvent &event, // [IN]  Pen position
        VfxPoint &offset    // [OUT] Offset from the centra to the pen position
    );

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

    // This function is the event handler when it is time to add the shortcut
    // from App category to the shortcut bar or shortcut pool.
    void onTimerAddShortcut(
        VfxTimer *timer     // [IN]  "Add shortcut" timer
    );

// Implementation
private:
    // This block implements the core functions related to the Drag-and-Drop of
    // the shortcut.

    // This function is the event handler when the user wants to drag a shortcut
    // from the shortcut bar or shortcut pool.
    // RETURNS: event handler result
    void onControlShortcutDrag(
        VappHsDndImage *image,  // [IN] Moving frame (icon)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is the event handler when the user is moving the shortcut.
    // RETURNS: event handler result
    void onControlShortcutMove(
        VappHsDndImage *image,  // [IN] Moving frame (icon)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function is the event handler when the user drops the shortuct.
    // RETURNS: event handler result
    void onControlShortcutDrop(
        VappHsDndImage *image,  // [IN] Moving frame (icon)
        VfxPenEvent &event      // [IN] Pen event
    );

// Implementation
private:
    // This block implements the function to close the shortcut pool when the
    // shortcut pool is open and the user clicks the area out of the shortcut
    // pool.

    // This function is the event handler when the area out of the shortcut pool
    // is clicked by the user.
    // RETURNS: event handler result
    void onBlackScreenDown();

    // This function sets the shortcut history.
    void setHistoryShortcut();

    // This function opens or closes the shortcut pool.
    void foldShortcutPool(
        VfxBool isFold          // [IN] VFX_TRUE: close; VFX_FLASE: open
    );

    // This function executes the action associated with this shortcut.
    void executeShortcut(
        VappHsDndImage *image   // [IN] Shortcut image
    );

    // This function initializes the shortcut.
    void initShortcut();

    // This function gets the screen size.
    // RETURNS: screen size
    VfxSize getScreenSize();
};

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VAPP_HS_SHORTCUT_PANEL_H__ */

