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
 *  vapp_desktop_page.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the page.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_DESKTOP_PAGE_H
#define VAPP_DESKTOP_PAGE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_app_widget_def.h"
#include "vapp_app_widget.h"
#include "vapp_desktop_def.h"


/*****************************************************************************
 * Page Class
 *****************************************************************************/

class VappDesktopPage : public VfxControl
{
    VFX_DECLARE_CLASS(VappDesktopPage);

// Constructor / Destructor
public:
    // Default constructor
    VappDesktopPage();

// Signal
public:
    // This signal is emitted when the active page is changed.
    //
    // SEE ALSO: getCurrentPageIndex
    VfxSignal1 <
        VappDesktopPage *       // [IN] Page object
    > m_signalPageChanged;

// Method
public:
    // This function handles the pen event.
    // RETURNS: On processed, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool doPenInput(
        VfxPenEvent &event      // [IN] Pen event
    );

public:
    // This function gets the current page index.
    // RETURNS: page index.
    VfxS32 getCurrentPageIndex() const;

    // This function returns the page index of the specified 'pos'.
    // RETURNS: the page index.
    VfxS32 getPageIndex(
        const VfxPoint &pos     // [IN] Position
    ) const;

    // This function gets the rectangle of the specified page's bounds.
    // RETURNS: bounds of the specified page.
    VfxRect getPageRect(
        VfxS32 pageIndex    // [IN] Page index
    ) const;

    VfxBool getPageRectExt(
        VfxS32 pageIndex,
        VfxRect &insideRect,
        VfxRect &outsideRect
    ) const;

public:
    // This function checks if the page should slide giving a pen input
    // position.
    // RETURNS: -1: slide to previous page
    //           0: do not slide
    //           1: slide to next page
    //
    // SEE ALSO: VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_LEFT_WIDTH
    // SEE ALSO: VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_LEFT_WIDTH
    VfxS32 getAutoSlideDirection(
        const VfxPoint &pos     // [IN] Pen input position
    ) const;

    // This function gets the distance, in pixels, to the next page.
    // RETURNS: distance.
    VfxS32 getDistanceToNext();

    // This function gets the distance, in pixels, to the previous page.
    // RETURNS: distance.
    VfxS32 getDistanceToPrevious();

    // This function gets the distance, in pixels, to the nearest page.
    // RETURNS: distance.
    VfxS32 getDistanceToNearest();

    // This function gets the animation duration, in msec, to the next page.
    // RETURNS: animation duration.
    VfxMsec getSlideDurationToNext();

    // This function gets the animation duration, in msec, to the previous page.
    // RETURNS: animation duration.
    VfxMsec getSlideDurationToPrevious();

    // This function gets the animation duration, in msec, to the nearest page.
    // RETURNS: animation duration.
    VfxMsec getSlideDurationToNearest();

    // This function slides to the next page.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: slideTo
    VfxBool slideToNext(
        VfxMsec duration = -1   // [IN] Animation duration
    );

    // This function slides to the previous page.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: slideTo
    VfxBool slideToPrevious(
        VfxMsec duration = -1   // [IN] Animation duration
    );

    // This function slides to the nearest page.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: slideTo
    VfxBool slideToNearest(
        VfxMsec duration = -1   // [IN] Animation duration
    );

    // This function slides to the centra page.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: slideTo
    VfxBool slideToCentra(
        VfxMsec duration = -1   // [IN] Animation duration
    );

    // Slide the desktop to the 'pageIndex' page. If the 'duration' is negative,
    // we use the default duration. If the 'duration' is 0, we do not animate
    // the sliding operation.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool slideTo(
        VfxS32 pageIndex,       // [IN] Page index
        VfxMsec duration = -1   // [IN] Animation duration
    );

public:
    // This function adds the widget to the specified page. We search the
    // location in the order from left to right and from top to bottom. When
    // the 'pageIndex' is -1, we add this widget to the page which it's
    // currently on.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool addToPage(
        VappAppWidget *widget,     // [IN] Widget
        VfxS32 pageIndex = -1   // [IN] Page index
    );

    // This function adds the widget to the page if we can find an avaiable one.
    // We search teh available page from the first page to the last page.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool addToPageIfAny(
        VappAppWidget *widget      // [IN] Widget
    );

    // This function adds the widget to the nearest location on the specified
    // page. We search the location which is closest to the widget' current
    // position. When the 'pageIndex' is -1, we add this widget to the page
    // which it's currently on.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool addToNearest(
        VappAppWidget *widget,     // [IN] Widget
        VfxS32 pageIndex = -1   // [IN] Page index
    );

    // This function adds the widget to the desktop by first trying to add it to
    // the current page. If failed, try to add it to any available page.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool addToDesktop(
        VappAppWidget *widget      // [IN] Widget
    );

    // This function removes the widget from the desktop.
    void removeFromPage(
        VappAppWidget *widget      // [IN] Widget
    );

    // This function gets all the widgets from the specified page.
    void getFromPage(
        VfxS32 pageIndex,       // [IN]  Page index
        VfxObjList &objList     // [OUT] Object list
    );

    // This function gets all the widget from all pages.
    void getFromAllPage(
        VfxObjList &objList     // [OUT] Object list
    );

    // This function checks if we can add this widget to the specified page.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: addToPage
    VfxBool canAddToPage(
        const VappAppWidget *widget,   // [IN] Widget
        VfxS32 pageIndex = -1       // [IN] Page index
    ) const;

    // This function adds the widget to the page if we can find an avaiable one.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: addToPageIfAny
    VfxBool canAddToPageIfAny(
        const VappAppWidget *widget    // [IN] Widget
    ) const;

    // This function adds the widget to the nearest location on the specified
    // page.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: addToNearest
    VfxBool canAddToNearest(
        const VappAppWidget *widget,   // [IN] Widget
        VfxS32 pageIndex = -1       // [IN] Page index
    ) const;

    // This fucntion adds the widget to the desktop.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: addToDesktop
    VfxBool canAddToDesktop(
        const VappAppWidget *widget    // [IN] Widget
    ) const;

    // This function searches any available room on the specified page.
    // RETURNS: On success, return the room's rectangle; otherwise, return a
    //          rectangle of zero size.
    VfxRect searchRoom(
        const VappAppWidget *widget,   // [IN] Widget
        VfxS32 pageIndex = -1       // [IN] Page index
    ) const;

    // This function searches any available room from all the pages.
    // RETURNS: On success, return the room's rectangle; otherwise, return a
    //          rectangle of zero size.
    VfxRect searchRoomIfAny(
        const VappAppWidget *widget    // [IN] Widget
    ) const;

    // This function searches the nearest available room from the specified
    // page.
    // RETURNS: On success, return the room's rectangle; otherwise, return a
    //          rectangle of zero size.
    VfxRect searchNearest(
        const VappAppWidget *widget,   // [IN] Widget
        VfxS32 pageIndex = -1       // [IN] Page index
    ) const;

protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // Please refer to VfxFrame.
    virtual void setBounds(
        const VfxRect &value
    );

    // Please refer to VfxFrame.
    virtual void onDraw(
        VfxDrawContext &dc
    );

private:
    enum
    {
        //  The distance, in x-axis, we consider the user swipes the desktop.
    #if defined(__MMI_MAINLCD_480X800__)
        SENSITIVITY = 24,
    #elif defined(__MMI_MAINLCD_320X480__)
        SENSITIVITY = 16,
    #elif defined(__MMI_MAINLCD_240X400__)
        SENSITIVITY = 12,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        SENSITIVITY = 12,
    #endif /* defined(__MMI_MAINLCD_240X320__) */

        // The time, in msec., we consider the user swipes the desktop.
        SWIPE_CRITERIA = 800,

        // The duration, in msec., that we animate the page sliding from one to
        // another.
        SLIDE_DEFAULT_DURATION = 150,
        SLIDE_MIN_DURATION     = 100,
        SLIDE_MAX_DURATION     = 250
    };

// Variable
private:
    // Vertical tile number.
    const static VfxS32 s_vertiTileNum;

    // Horizontal tile number side.
    const static VfxS32 s_horizTileNum;

    // Outer border width on the top side.
    const static VfxS32 s_outerBorderTopWidth;

    // Outer border width on the bottom side.
    const static VfxS32 s_outerBorderBottomWidth;

    // Outer border width on the left side
    const static VfxS32 s_outerBorderLeftWidth;

    // Outer border width on the right side.
    const static VfxS32 s_outerBorderRightWidth;

    // Border width on the left side that we will start the auto. sliding.
    const static VfxS32 s_autoSlideBorderLeftWidth;

    // Border width on the right side that we will start the auto. sliding.
    const static VfxS32 s_autoSlideBorderRightWidth;

// Variable
private:
    // Current page index.
    VfxS32 m_currentPageIndex;

    // Speed of the sliding animation in pixels per second.
    VfxS32 m_slideSpeed;

// Implementation
private:
    // This function calculates the distance between 'p1' and 'p2'.
    // RETURNS: distance.
    VfxS32 calcDistance(
        const VfxPoint &p1,     // [IN] Point 1
        const VfxPoint &p2      // [IN] Point 2
    ) const;

    // This function inits the mechanism to calculate the animation speed for
    // page sliding.
    void initSlideSpeed();

    // This function updates the animation speed for page sliding.
    void updateSlideSpeed(
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function clamps the animation duration for page sliding.
    // RETURNS: animation duration.
    VfxMsec clampSlideDuration(
        VfxMsec duration        // [IN] animation duration
    );

    // This function clamps the page index to their valid range.
    // RETURNS: the clampped page index.
    VfxS32 clampIndex(
        VfxS32 pageIndex        // [IN] Page index
    ) const;

    // This function gets the tile size.
    // RETURNS: tile size.
    static VfxSize getTileSize();

    // This function gets the room size suitable for the widget.
    // RETURNS: room size.
    static VfxSize getRoomSize(
        const VappAppWidget *widget    // [IN] Widget
    );

    // This functions gets the total room number on all pages if each room has
    // the specified size.
    // RETURNS: room number.
    static VfxS32 getTotalRoomNum(
        const VfxSize &roomSize     // [IN] Room size
    );

    // This function gets the total room number on one page if each room has the
    // specified size.
    // RETURNS: room number.
    static VfxS32 getPageRoomNum(
        const VfxSize &roomSize     // [IN] Room size
    );

    // This function gets the number of rooms in the horizontal direction on one
    // page if each room has the specified size.
    // RETURNS: room number.
    static VfxS32 getPageHorizRoomNum(
        const VfxSize &roomSize     // [IN] Room size
    );

    // This function gets the number of rooms in the vertical direction on one
    // page if each room has the specified size.
    // RETURNS: room number.
    static VfxS32 getPageVertiRoomNum(
        const VfxSize &roomSize     // [IN] Room size
    );

    // This function gets the index of the first room with the speicified size
    // on the specified page. Then, you can use 'getRoom' to get the rectangle
    // of this room.
    // RETURNS: room index.
    //
    // SEE ALSO: getLastRoomIndex
    // SEE ALSO: getRoom
    static VfxS32 getFirstRoomIndex(
        const VfxSize &roomSize,        // [IN] Room size
        VfxS32 pageIdx                  // [IN] Page index
    );

    // This function gets the index of the last room with the specified size on
    // the specified page. Then, you can use 'getRoom' to get the rectangle of
    // this room
    // RETURNS: room index.
    //
    // SEE ALSO: getFirstRoomIndex
    // SEE ALSO: getRoom
    static VfxS32 getLastRoomIndex(
        const VfxSize &roomSize,        // [IN] Room size
        VfxS32 pageIdx                  // [IN] Page index
    );

    // This function gets the room's rectangle. We identify the room by the page
    // index and the (x, y) coordination on this page. The range of 'x' and 'y'
    // can be obtained by 'getPageHorizRoomNum' and 'getPageVertiRoomNum'.
    // RETURNS: room rectangle.
    //
    // SEE ALSO: getPageHorizRoomNum
    // SEE ALSO: getPageVertiRoomNum
    static VfxRect getRoom(
        const VfxSize &roomSize,    // [IN] Room size
        VfxS32 pageIdx,             // [IN] Page index
        VfxS32 x,                   // [IN] index in the x-axis
        VfxS32 y                    // [IN] index in the y-axis
    );

    // This function gets the room's rectangle. We identify the room by the
    // room index. The range of 'idx' can be obtained by 'getTotalRoomNum'.
    // RETURNS: room rectangle.
    //
    // SEE ALSO: getTotalRoomNum
    static VfxRect getRoom(
        const VfxSize &roomSize,    // [IN] Room size
        VfxS32 idx                  // [IN] Index
    );

    // This function gets the widget which occupies this room.
    // RETURNS: If found, return the widget; otherwise, return NULL.
    VappAppWidget *getOccupiedWidget(
        const VfxRect &room     // [IN] Room
    ) const;

    // This function checks if this room is occupied by some widgets.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isOccupied(
        const VfxRect &room     // [IN] Room
    ) const;

    // This function sets the widget's position to be on this room.
    void setWidgetOnRoom(
        VappAppWidget *widget,     // [IN] Widget
        const VfxRect &room     // [IN] Room
    ) const;

    static VfxSize getScreenSize();

#if defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE)
    //
    // This block implements the debug panel related to page swipe.
    //

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        DEBUG_TEXT_POS_Y = 70
    #elif defined(__MMI_MAINLCD_320X480__)
        DEBUG_TEXT_POS_Y = 42
    #elif defined(__MMI_MAINLCD_240X400__)
        DEBUG_TEXT_POS_Y = 36
    #else /* defined(__MMI_MAINLCD_240X320__) */
        DEBUG_TEXT_POS_Y = 32
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    // Debug panel.
    VfxFrame *m_debugPanel;

    // Text on the debug panel.
    VfxTextFrame *m_debugText;

    // If the 'pen-move' event comes.
    VfxBool m_isPenMoved;

// Implementation
private:
    // This function sets the text on the debug panel.
    void setDebugText(
        const VfxWString &string,               // [IN] Text string
        const VfxColor &color = VFX_COLOR_WHITE // [IN] Color of the text
    );
#endif /* defined(VAPP_DESKTOP_UT_DESKTOP_SLIDE) */

#if defined(VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE)
    //
    // This block implements the debug panel related to the auto. sliding.
    //

// Variable
private:
    // The panel to provide a hint that auto sliding can start.
    VfxFrame *m_autoSlideHint;

// Implementation
private:
    // This function sets the hint. If 'location' is 0, turn off the hint. If
    // 'location' is 1, turn on the hint on the right side. If 'location' is -1,
    // turn on the hint on the left side.
    void setAutoSlideHint(
        VfxS32 location     // [IN] Location of the hint
    );
#endif /* defined(VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE) */
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_PAGE_H */

