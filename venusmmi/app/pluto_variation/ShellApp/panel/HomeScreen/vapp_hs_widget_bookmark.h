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
 *  vapp_hs_widget_bookmark.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: bookmark
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_BOOKMARK_H__
#define __VAPP_HS_WIDGET_BOOKMARK_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
    
#ifdef __MMI_VUI_HOMESCREEN_BOOKMARK__
#include "vapp_hs_widget_base.h"
#include "vcp_base_menu.h"
#include "vcp_button.h"
#include "ui_core\mvc\vfx_primitive_frame.h"
#include "ui_core\base\vfx_datatype.h"
#include "ui_core\base\vfx_string.h"
#include "ui_core\base\vfx_cpp_base.h"
#include "ui_core\base\vfx_basic_type.h"
#include "ui_core\mvc\vfx_frame.h"
#include "ui_core\mvc\vfx_text_frame.h"
#include "ui_core\mvc\vfx_animation.h"
#include "ui_core\mvc\vfx_input_event.h"
#include "vcp_scrollable.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "ui_core\base\vfx_sys_memory.h"
#include "ui_core\pme\vfx_object.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VcpHsWidgetBookmarkMenu;

/***************************************************************************** 
 * Class VcpHsWidgetBookmarkMenuCell
 *****************************************************************************/
class VcpHsWidgetBookmarkMenuCell : public VfxImageFrame
{
    friend VfxU32 VappHsWidgetBkmGetBookmarkThumbnailSize();

// Declaration
private:
    // Opacity of the bookmark title
    #define BKM_TITLE_OPACITY (0.7f)

    // Color of highlight border
    #define BKM_CELL_HIGHLIGHT_BORDER_COLOR VfxColor(255, 255, 136, 12)
    
    enum
    {
        // Margin width of bookmark cell
        BKM_CELL_MARGIN_WIDTH = 1,
        
        // Duration time of bookmark cell entrance animation
        BKM_CELL_ENTRANCE_ANIMATION_DURATION_TIME = 500,
        
        // Highlight border width of bookmark cell
        BKM_CELL_HIGHLIGHT_BORDER_WIDTH = 2,

        // Height of the bookmark title background
        BKM_TITLE_BACKGROUND_HEIGHT = 20,

        // Margin width of the bookmark title
        BKM_TITLE_MARGIN_WIDTH = 5
    };

// Constructor / Destructor
public:
    // Default constructor
    VcpHsWidgetBookmarkMenuCell(){}

    // Destructor
    virtual ~VcpHsWidgetBookmarkMenuCell(){}

// Method
public:
    // Get margin width of bookmark cell
    VfxS32 getCellMarginWidth() const;

    // Set bookmark title
    void setTitle(const VfxWString &string);

    // Update position of bookmark cell
    void updatePos(const VfxRect &r, VfxBool isAnim);

    // Enter bookmark cell
    void enter(const VfxRect &r, VfxBool animation);

    // Set bookmark cell highlight
    void setHighlight(VfxBool isHighLight);

// Override
public:
    // Initialize object
    virtual void onInit();

    // De-initialize object
    virtual void onDeinit();

// Variable
private:
    // Bookmark title background
    VfxFrame            *m_titleBackground;

    // Bookmark title
    VfxTextFrame        *m_title;

    // Timeline for opacity animation of bookmark cell
    VfxFloatTimeline    *m_opacityTimeline;

    // Timeline for size animation of bookmark cell
    VfxSizeTimeline     *m_sizeTimeline;
};

/***************************************************************************** 
 * class VcpHsWidgetBookmarkMenuLayout
 *****************************************************************************/
class VcpHsWidgetBookmarkMenuLayout : public VcpBaseMenuLayout
{
// Constructor / Destructor
public:
    // Constructor
    VcpHsWidgetBookmarkMenuLayout(VcpBaseMenu *menu);

    // Destructor
    virtual ~VcpHsWidgetBookmarkMenuLayout(){}

// Method
public:
    // Set layout parameter
    void setLayoutParameter(VfxS32 cellNumber, VfxS32 cellWidth, VfxS32 cellHeight, VfxS32 viewRegionRowNumber, VfxS32 viewRegionColumnNumber, ScrollDirEnum scrollDirection);

// Override
public:
    // Return the scroll direction
    virtual ScrollDirEnum getScrollDir();

    // Return the number of cells of a group.
    virtual VfxS32 getCellCount(VfxS32 group);

    // Return the whole size of the menu.
    virtual VfxS32 getContentLength();

    // Return the region within a rectangle.
    virtual VcpMenuRegion queryRegion(const VfxRect &r);

    // Return a cell rect
    virtual VfxRect queryCellRect(VcpMenuPos pos);

// Variable
private:
    // Number of bookmark cell
    VfxS32 m_cellNumber;

    // Width of bookmark cell
    VfxS32 m_cellWidth;

    // Height of bookmark cell
    VfxS32 m_cellHeight;

    // Row number in view region
    VfxS32 m_viewRegionRowNumber;

    // Column number in view region
    VfxS32 m_viewRegionColumnNumber;

    // Scroll direction
    ScrollDirEnum m_scrollDirection;

//Implementation
private:
    // Query the menu cell position that the point hit.
    VcpMenuPos getCellPosByPt(VfxPoint pt);
};

/***************************************************************************** 
 * Class VcpHsWidgetBookmarkMenuView
 *****************************************************************************/
class VcpHsWidgetBookmarkMenuView : public VcpBaseMenuView
{
// Constructor / Destructor
public:
    // Default constructor
    VcpHsWidgetBookmarkMenuView(){}

    // Destructor
    virtual ~VcpHsWidgetBookmarkMenuView(){}

// Method
public:
    // Get bookmark menu object
    VcpHsWidgetBookmarkMenu *getMenu();

// Override
public:
    // Override to handle the pen input event.
    virtual VfxBool onPenInput(VfxPenEvent &event);
};

/***************************************************************************** 
 * Class VcpHsWidgetBookmarkMenu
 *****************************************************************************/
class VcpHsWidgetBookmarkMenu : public VcpBaseMenu
{
// Constructor / Destructor
public:
    // Default constructor
    VcpHsWidgetBookmarkMenu(){}

    // Destructor
    virtual ~VcpHsWidgetBookmarkMenu(){}

// Method
public:
    // Set menu layout parameters
    void setLayoutParameter(VfxS32 cellNumber, VfxS32 cellWidth, VfxS32 cellHeight, VfxS32 viewRegionRowNumber, VfxS32 viewRegionColumnNumber, VcpBaseMenuLayout::ScrollDirEnum scrollDirection);

// Override
public:
    // Initialize object
    virtual void onInit();

    // Creates the view
    virtual VcpScrollableView *onCreateView();

    // Create a layout object for menu.
    virtual VcpBaseMenuLayout *createLayout();
    
    // Create a cell object.
    virtual VfxFrame* createCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index
    );

    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );

    // Notify to update a cell's attributes
    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
    );

    // Notify when a cell is clicked
    virtual void onTapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
    );

    // Notify when a cell or header is interact.
    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    );
    
// Implementation
private:
    // Launch browser to visit bookmark tapped by touch
    void launchBrowserWithBookmark(VfxS32 index);
};

/***************************************************************************** 
 * Class VappHsWidgetBookmark
 *****************************************************************************/
class VappHsWidgetBookmark : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetBookmark);

    friend VfxU32 VappHsWidgetBkmGetBookmarkThumbnailSize();
    
// Declaration
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        // X-axis position of the bookmark widget title
        BKM_WIDGET_TITLE_POS_X  = 9,
        
        // Y-axis position of the bookmark widget title
        BKM_WIDGET_TITLE_POS_Y  = 7,
        
        // X-axis position of the page indicator
        BKM_PAGE_INDICATOR_POS_X  = 185,
        
        // Y-axis position of the page indicator
        BKM_PAGE_INDICATOR_POS_Y  = 10,
        
        // X-axis position of the bookmark menu
        BKM_MENU_POS_X  = 7,
        
        // Y-axis position of the bookmark menu
        BKM_MENU_POS_Y  = 29,
        
        // Width of the bookmark menu
        BKM_MENU_WIDTH  = 148,
        
        // Height of the bookmark menu
        BKM_MENU_HEIGHT = 148,
        
        // Row number of bookmark menu in view region
        BKM_MENU_VIEW_REGION_ROW_NUM = 2,
        
        // Column number of bookmark menu in view region
        BKM_MENU_VIEW_REGION_COLUMN_NUM = 2,
        
        // Scroll direction of bookmark menu
        BKM_MENU_SCROLL_DIRECTION = VcpBaseMenuLayout::SCROLLDIR_VERT,
        
        // X-axis position of the page up button
        BKM_PAGE_UP_BUTTON_POS_X  = 157,
        
        // Y-axis position of the page up button
        BKM_PAGE_UP_BUTTON_POS_Y  = 30,
        
        // X-axis position of the page down button
        BKM_PAGE_DOWN_BUTTON_POS_X  = 157,
        
        // Y-axis position of the page down button
        BKM_PAGE_DOWN_BUTTON_POS_Y  = 105
    #else
        // X-axis position of the bookmark widget title
        BKM_WIDGET_TITLE_POS_X  = 9,

        // Y-axis position of the bookmark widget title
        BKM_WIDGET_TITLE_POS_Y  = 6,

        // X-axis position of the page indicator
        BKM_PAGE_INDICATOR_POS_X  = 160,

        // Y-axis position of the page indicator
        BKM_PAGE_INDICATOR_POS_Y  = 9,

        // X-axis position of the bookmark menu
        BKM_MENU_POS_X  = 7,

        // Y-axis position of the bookmark menu
        BKM_MENU_POS_Y  = 26,

        // Width of the bookmark menu
        BKM_MENU_WIDTH  = 124,

        // Height of the bookmark menu
        BKM_MENU_HEIGHT = 124,

        // Row number of bookmark menu in view region
        BKM_MENU_VIEW_REGION_ROW_NUM = 2,
        
        // Column number of bookmark menu in view region
        BKM_MENU_VIEW_REGION_COLUMN_NUM = 2,
        
        // Scroll direction of bookmark menu
        BKM_MENU_SCROLL_DIRECTION = VcpBaseMenuLayout::SCROLLDIR_VERT,
        
        // X-axis position of the page up button
        BKM_PAGE_UP_BUTTON_POS_X  = 134,

        // Y-axis position of the page up button
        BKM_PAGE_UP_BUTTON_POS_Y  = 27,

        // X-axis position of the page down button
        BKM_PAGE_DOWN_BUTTON_POS_X  = 134,

        // Y-axis position of the page down button
        BKM_PAGE_DOWN_BUTTON_POS_Y  = 89
    #endif
    };

    // Widget state
    enum WidgetState
    {
        WIDGET_STATE_REMOVE_FROM_DESKTOP = 0x01
    };

// Constructor / Destructor    
public:
    // Default constructor
    VappHsWidgetBookmark();

// Override
public:
    // Get image icon resource ID for widget bar
    // RETURNS: image ID
    virtual VfxU16 getIcon();

    // Start to drag to desktop, widget can create its own window and service
    virtual void onCreateView();

    // No longer existed on desktop, widget should close all objects created in onCreateView()
    virtual void onReleaseView();

    // Widget is added to desktop (after createView and is sure to put on desktop)
    virtual void onAddToDesktop();
    
    // Widget is removed from desktop (not yet releaseView while dragging)
    virtual void onRemoveFromDesktop();

// Variable
private:
    // Background image
    VfxImageFrame           *m_bgImg;

    // Widget title
    VfxTextFrame            *m_widgetTitle;

    // Page indicator
    VfxTextFrame            *m_pageIndicater;

    // Help text
    VfxTextFrame            *m_helpText;

    // Page up button
    VcpButtonInternal       *m_pageUpButton;

    // Image of page up button which is not pressed
    VfxImageSrc             m_pageUpButtonUpImage;
    
    // Image of page up button which is pressed
    VfxImageSrc             m_pageUpButtonDownImage;
    
    // Page down button
    VcpButtonInternal       *m_pageDownButton;

    // Image of page down button which is not pressed
    VfxImageSrc             m_pageDownButtonUpImage;
    
    // Image of page down button which is pressed
    VfxImageSrc             m_pageDownButtonDownImage;
    
    // Bookmark menu
    VcpHsWidgetBookmarkMenu *m_bookmarkMenu;

    // Page number
    VfxS32                  m_pageNumber;

    // Widget state
    VfxS32                  m_widgetState;

    // ID of first bookmark in current page
    static VfxS32           m_firstBookmarkID;

// Implementation
private:
    // Create bookmark menu
    void createBookmarkMenu();

    // Update page indicator and button status
    void updatePageIndAndButton();
    
    // This function is the event handler when the page up button is clicked
    void pageUp();

    // This function is the event handler when the page down button is clicked
    void pageDown();

    // This function is the event handler when page up/down button is pressed
    void buttonDownFeedback();
};

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern VfxU32 VappHsWidgetBkmGetBookmarkThumbnailSize();

#endif /* __MMI_VUI_HOMESCREEN_BOOKMARK__ */

#endif /* __VAPP_HS_WIDGET_BOOKMARK_H__ */

