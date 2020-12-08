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
 *  vapp_hs_widget_bookmark.cpp
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

#ifdef __MMI_VUI_HOMESCREEN_BOOKMARK__
/* Venus MMI headers: */
#include "mmi_rp_app_venus_hs_wg_bkm_def.h"
#include "vapp_hs_widget_bookmark.h"

#include "ui_core\base\vfx_datatype.h"
#include "ui_core\base\vfx_string.h"
#include "ui_core\base\vfx_cpp_base.h"
#include "ui_core\base\vfx_basic_type.h"
#include "ui_core\mvc\vfx_primitive_frame.h"
#include "ui_core\base\vfx_sys_memory.h"
#include "ui_core\pme\vfx_object.h"
#include "ui_core\mvc\vfx_frame.h"
#include "vrt_datatype.h"
#include "ui_core\mvc\vfx_text_frame.h"
#include "ui_core\mvc\vfx_animation.h"
#include "vcp_base_menu.h"
#include "ui_core\mvc\vfx_input_event.h"
#include "vcp_scrollable.h"
#include "ui_core\pme\vfx_signal.h"
#include "vcp_button.h"
#ifdef __cplusplus
extern "C"
{
#endif

/* Pluto MMI headers: */
#include "stdlib.h"

/* Opera bookmark APIs */
#include "opera_api.h"
#include "OpDevBookmark.h"

/* Opera bookmark APIs adaptation layer */
#include "HomeScreen\vadp_v2p_hs_widget_bookmark.h"

/* FTE touch feedback */
#include "gui_touch_feedback.h"

#include "custom_mmi_default_value.h"
#include "GlobalResDef.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
VfxU32 VappHsWidgetBkmGetBookmarkThumbnailSize()
{
    if (VappHsWidgetBookmark::BKM_MENU_WIDTH > VappHsWidgetBookmark::BKM_MENU_HEIGHT)
    {
        return VappHsWidgetBookmark::BKM_MENU_WIDTH / VappHsWidgetBookmark::BKM_MENU_VIEW_REGION_COLUMN_NUM - VcpHsWidgetBookmarkMenuCell::BKM_CELL_MARGIN_WIDTH * 2;
    }
    else
    {
        return VappHsWidgetBookmark::BKM_MENU_HEIGHT / VappHsWidgetBookmark::BKM_MENU_VIEW_REGION_ROW_NUM - VcpHsWidgetBookmarkMenuCell::BKM_CELL_MARGIN_WIDTH * 2;
    }
}

/***************************************************************************** 
 * Class VcpHsWidgetBookmarkMenuCell
 *****************************************************************************/
VfxS32 VcpHsWidgetBookmarkMenuCell::getCellMarginWidth() const
{
    return BKM_CELL_MARGIN_WIDTH;
}

void VcpHsWidgetBookmarkMenuCell::setTitle(const VfxWString &string)
{
    m_title->setString(string);
}

void VcpHsWidgetBookmarkMenuCell::updatePos(const VfxRect &r, VfxBool isAnim)
{
    setAutoAnimate(isAnim);

    setPos(VfxPoint(r.getMidX(), r.getMidY()));
    setBounds(VfxRect(VfxPoint(0, 0), r.size));
    m_titleBackground->setPos(VfxPoint(0, r.size.height - BKM_TITLE_BACKGROUND_HEIGHT));
    m_titleBackground->setBounds(VfxRect(0, 0, r.size.width, BKM_TITLE_BACKGROUND_HEIGHT));
    m_title->setPos(VfxPoint(m_titleBackground->getBounds().getMidX(), m_titleBackground->getBounds().getMidY()));
    m_title->setBounds(VfxRect(0, 0, r.size.width - BKM_TITLE_MARGIN_WIDTH * 2, m_title->getBounds().getHeight()));
}

void VcpHsWidgetBookmarkMenuCell::enter(const VfxRect &r, VfxBool animation)
{
    if (animation)
    {
        // set the position without animation
        // But timeline will not be affect
        updatePos(r, VFX_FALSE);

        m_opacityTimeline->setFromValue(0.0f);
        m_opacityTimeline->setToValue(1.0f);
        m_opacityTimeline->start();

        m_sizeTimeline->setFromValue(VfxSize(0, 0));
        m_sizeTimeline->setToValue(r.size);
        m_sizeTimeline->start();
    }
    else
    {
        updatePos(r, VFX_FALSE);
        setOpacity(1.0f);
    }
}

void VcpHsWidgetBookmarkMenuCell::setHighlight(VfxBool isHighLight)
{
    if (isHighLight)
    {
        setBorderWidth(BKM_CELL_HIGHLIGHT_BORDER_WIDTH);
    }
    else
    {
        setBorderWidth(0);
    }
}

void VcpHsWidgetBookmarkMenuCell::onInit()
{
    VfxImageFrame::onInit();

    setAnchor(VfxFPoint(0.5f, 0.5f));
    setBorderColor(BKM_CELL_HIGHLIGHT_BORDER_COLOR);
    setIsCached(VFX_TRUE);

    VFX_OBJ_CREATE(m_titleBackground, VfxFrame, this);
    m_titleBackground->setBgColor(VFX_COLOR_BLACK);
    m_titleBackground->setOpacity(BKM_TITLE_OPACITY);
    
    VFX_OBJ_CREATE(m_title, VfxTextFrame, m_titleBackground);
    m_title->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_title->setFont(VfxFontDesc(g_vfxFontSmall));
    m_title->setColor(VFX_COLOR_WHITE);
    m_title->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    
    VFX_OBJ_CREATE(m_opacityTimeline, VfxFloatTimeline, this);
    m_opacityTimeline->setTarget(this);
    m_opacityTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_opacityTimeline->setDurationTime(BKM_CELL_ENTRANCE_ANIMATION_DURATION_TIME);

    VFX_OBJ_CREATE(m_sizeTimeline, VfxSizeTimeline, this);
    m_sizeTimeline->setTarget(this);
    m_sizeTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE);
    m_sizeTimeline->setDurationTime(BKM_CELL_ENTRANCE_ANIMATION_DURATION_TIME);

    setAutoAnimate(VFX_TRUE);
}

void VcpHsWidgetBookmarkMenuCell::onDeinit()
{
    m_opacityTimeline->stop();
    m_sizeTimeline->stop();
    
    VfxImageFrame::onDeinit();
}

/***************************************************************************** 
 * class VcpHsWidgetBookmarkMenuLayout
 *****************************************************************************/
VcpHsWidgetBookmarkMenuLayout::VcpHsWidgetBookmarkMenuLayout(VcpBaseMenu* menu) :
    VcpBaseMenuLayout(menu),
    m_cellNumber(0),
    m_cellWidth(0),
    m_cellHeight(0),
    m_viewRegionRowNumber(0),
    m_viewRegionColumnNumber(0)
{
}

void VcpHsWidgetBookmarkMenuLayout::setLayoutParameter(VfxS32 cellNumber, VfxS32 cellWidth, VfxS32 cellHeight, VfxS32 viewRegionRowNumber, VfxS32 viewRegionColumnNumber, ScrollDirEnum scrollDirection)
{
    m_cellNumber = cellNumber;
    m_cellWidth = cellWidth;
    m_cellHeight = cellHeight;
    m_viewRegionRowNumber = viewRegionRowNumber;
    m_viewRegionColumnNumber = viewRegionColumnNumber;
    m_scrollDirection = scrollDirection;
    
    update();
}

VcpBaseMenuLayout::ScrollDirEnum VcpHsWidgetBookmarkMenuLayout::getScrollDir()
{
    return m_scrollDirection;
}

VfxS32 VcpHsWidgetBookmarkMenuLayout::getCellCount(VfxS32 group)
{
    VFX_UNUSED(group);
    
    return m_cellNumber;
}

VfxS32 VcpHsWidgetBookmarkMenuLayout::getContentLength()
{
    if (m_scrollDirection == SCROLLDIR_HORZ)
    {
        return (m_cellNumber + m_viewRegionRowNumber * m_viewRegionColumnNumber - 1) / (m_viewRegionRowNumber * m_viewRegionColumnNumber) * (m_cellWidth * m_viewRegionColumnNumber);
    }
    else
    {
        return (m_cellNumber + m_viewRegionRowNumber * m_viewRegionColumnNumber - 1) / (m_viewRegionRowNumber * m_viewRegionColumnNumber) * (m_cellHeight * m_viewRegionRowNumber);
    }
}

VcpMenuRegion VcpHsWidgetBookmarkMenuLayout::queryRegion(const VfxRect &r)
{
    return VcpMenuRegion(getCellPosByPt(r.origin),
                         getCellPosByPt(VfxPoint(r.getMaxX(), r.getMaxY())));
}

VfxRect VcpHsWidgetBookmarkMenuLayout::queryCellRect(VcpMenuPos pos)
{
    if (pos.group != 0 || pos.pos < -1 || pos.pos >= m_cellNumber)
    {
        return VfxRect(-1, -1, 0, 0);
    }

    if (m_scrollDirection == SCROLLDIR_HORZ)
    {
        return VfxRect((pos.pos / m_viewRegionRowNumber) * m_cellWidth,
                       (pos.pos % m_viewRegionRowNumber) * m_cellHeight,
                       m_cellWidth,
                       m_cellHeight);
    }
    else
    {
        return VfxRect((pos.pos % m_viewRegionColumnNumber) * m_cellWidth,
                       (pos.pos / m_viewRegionColumnNumber) * m_cellHeight,
                       m_cellWidth,
                       m_cellHeight);
    }
}

VcpMenuPos VcpHsWidgetBookmarkMenuLayout::getCellPosByPt(VfxPoint pt)
{
    VcpMenuPos p;
    
    p.group = 0;
    VfxS32 row = pt.y / m_cellHeight;
    VfxS32 col = pt.x / m_cellWidth;
    if (m_scrollDirection == SCROLLDIR_HORZ)
    {
        p.pos = col * m_viewRegionRowNumber + row;
    }
    else
    {
        p.pos = row * m_viewRegionColumnNumber + col;
    }

    if (p.pos < 0)
    {
        p.pos = 0;
    }
    if (p.pos >= m_cellNumber)
    {
        p.pos = m_cellNumber - 1;
    }
    
    return p;
}

/***************************************************************************** 
 * Class VcpHsWidgetBookmarkMenuView
 *****************************************************************************/
VcpHsWidgetBookmarkMenu* VcpHsWidgetBookmarkMenuView::getMenu()
{
    return static_cast<VcpHsWidgetBookmarkMenu*>(getParentFrame());
}

VfxBool VcpHsWidgetBookmarkMenuView::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return VcpBaseMenuView::onPenInput(event);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP && event.pos == event.downPos)
    {
        // Cancel focus highlight
        VcpMenuPos tapCellPos = getMenu()->getLayout()->getFocusItem();
        VcpHsWidgetBookmarkMenuCell* item = (VcpHsWidgetBookmarkMenuCell*)(getMenu()->getCellIfPresent(tapCellPos.group, tapCellPos.pos));
        if (item)
        {
            item->setHighlight(VFX_FALSE);
        }
        getMenu()->getLayout()->clearFocusItem();
        
        return VcpBaseMenuView::onPenInput(event);
    }
    // Do not handle VFX_PEN_EVENT_TYPE_MOVE event in bookmark menu
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        // Cancel focus highlight
        VcpMenuPos tapCellPos = getMenu()->getLayout()->getFocusItem();
        VcpHsWidgetBookmarkMenuCell* item = (VcpHsWidgetBookmarkMenuCell*)(getMenu()->getCellIfPresent(tapCellPos.group, tapCellPos.pos));
        if (item)
        {
            item->setHighlight(VFX_FALSE);
        }
        getMenu()->getLayout()->clearFocusItem();
        
        return VFX_FALSE;
    }
    else
    {
        return VFX_FALSE;
    }
}

/***************************************************************************** 
 * Class VcpHsWidgetBookmarkMenu
 *****************************************************************************/
void VcpHsWidgetBookmarkMenu::setLayoutParameter(VfxS32 cellNumber, VfxS32 cellWidth, VfxS32 cellHeight, VfxS32 viewRegionRowNumber, VfxS32 viewRegionColumnNumber, VcpBaseMenuLayout::ScrollDirEnum scrollDirection)
{
    (static_cast<VcpHsWidgetBookmarkMenuLayout*>(m_layout))->setLayoutParameter(cellNumber, cellWidth, cellHeight, viewRegionRowNumber, viewRegionColumnNumber, scrollDirection);
}

void VcpHsWidgetBookmarkMenu::onInit()
{
    VcpBaseMenu::onInit();
    
    m_state = Opening;
}

VcpScrollableView *VcpHsWidgetBookmarkMenu::onCreateView()
{
    VcpHsWidgetBookmarkMenuView *view;

    VFX_OBJ_CREATE(view, VcpHsWidgetBookmarkMenuView, this);

    return view;
}

VcpBaseMenuLayout *VcpHsWidgetBookmarkMenu::createLayout()
{
    VcpHsWidgetBookmarkMenuLayout *layout;
    VFX_OBJ_CREATE_EX(layout, VcpHsWidgetBookmarkMenuLayout, this, (this));
    return layout;
}

VfxFrame* VcpHsWidgetBookmarkMenu::createCell(VfxS32 group, VfxS32 pos)
{
    VFX_UNUSED(group);

    VcpHsWidgetBookmarkMenuCell *bookmarkItem;
    VFX_OBJ_CREATE(bookmarkItem, VcpHsWidgetBookmarkMenuCell, this);

    // Title
    VfxU8 title[(VADP_HS_WIDGET_BOOKMARK_MAX_TITLE_LEN + 1) * ENCODING_LENGTH] = {0};
    vadp_v2p_hs_bkm_get_bookmark_title_by_index(pos, title);
    bookmarkItem->setTitle(VFX_WSTR_MEM((VfxWChar*)title));

    // Thumbnail
    VfxU8 *rawDataMemory;
    vadp_v2p_hs_bkm_get_bookmark_thumbnail_by_index(pos, &rawDataMemory);
    if (rawDataMemory)
    {
        bookmarkItem->loadFromMem(rawDataMemory);
    }
    else
    {
        bookmarkItem->setResId(VAPP_HS_IMG_WG_BOOKMARK_DEFAULT_THUMBNAIL_ICON);
    }

    return bookmarkItem;
}

void VcpHsWidgetBookmarkMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_UNUSED(group);
    VFX_UNUSED(pos);

    VFX_OBJ_CLOSE(cellFrame);
}

void VcpHsWidgetBookmarkMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
    VFX_UNUSED(group);
    VFX_UNUSED(pos);

    VcpHsWidgetBookmarkMenuCell* item = static_cast<VcpHsWidgetBookmarkMenuCell*>(cell);

    VfxRect r = rect;
    r.origin.x += item->getCellMarginWidth();
    r.origin.y += item->getCellMarginWidth();
    r.size.width -= item->getCellMarginWidth() * 2;
    r.size.height -= item->getCellMarginWidth() * 2;

    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        if (flag & VCP_CELL_FLAG_OPENING)
        {
            item->enter(r, VFX_TRUE);
        }
        else
        {
            item->enter(r, VFX_FALSE);
        }
    }
    else
    {
        item->updatePos(r, VFX_TRUE);
    }
}

void VcpHsWidgetBookmarkMenu::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{
    VFX_UNUSED(group);
    VFX_UNUSED(cell);

    vfxPostInvoke1(this, &VcpHsWidgetBookmarkMenu::launchBrowserWithBookmark, pos);
}

void VcpHsWidgetBookmarkMenu::onTouchCell(VcpMenuPos cellPos, CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell)
{
    VFX_UNUSED(pt);

    VcpHsWidgetBookmarkMenuCell* item = static_cast<VcpHsWidgetBookmarkMenuCell*>(cell);
    
    if (touchType == TouchDown)
    {
        item->setHighlight(VFX_TRUE);
        getLayout()->setFocusItem(cellPos);
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
    }
}

void VcpHsWidgetBookmarkMenu::launchBrowserWithBookmark(VfxS32 index)
{
    vadp_v2p_hs_bkm_tap_bookmark_thumbnail(index);
}

/***************************************************************************** 
 * Class VappHsWidgetBookmark
 *****************************************************************************/
VfxS32 VappHsWidgetBookmark::m_firstBookmarkID = 0;

VappHsWidgetBookmark::VappHsWidgetBookmark() :
    m_bgImg(NULL),
    m_widgetTitle(NULL),
    m_pageIndicater(NULL),
    m_helpText(NULL),
    m_pageUpButton(NULL),
    m_pageDownButton(NULL),
    m_bookmarkMenu(NULL),
    m_pageNumber(0),
    m_widgetState(0)
{
}

VfxU16 VappHsWidgetBookmark::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_BOOKMARK;
}

void VappHsWidgetBookmark::onCreateView()
{
    // Create background image
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setResId(VAPP_HS_IMG_WG_BOOKMARK_BG);

    // Create widget title
    VFX_OBJ_CREATE(m_widgetTitle, VfxTextFrame, this);
    m_widgetTitle->setFont(VfxFontDesc(g_vfxFontMedium));
    m_widgetTitle->setColor(VFX_COLOR_WHITE);
    m_widgetTitle->setString(VFX_WSTR_RES(VAPP_HS_STR_WG_BOOKMARKS));
    m_widgetTitle->setPos(VfxPoint(BKM_WIDGET_TITLE_POS_X, BKM_WIDGET_TITLE_POS_Y));
    
    // Create help text
    VFX_OBJ_CREATE(m_helpText, VfxTextFrame, this);
    m_helpText->setFont(VfxFontDesc(g_vfxFontMedium));
    m_helpText->setColor(VFX_COLOR_WHITE);
    m_helpText->setString(VFX_WSTR_RES(STR_GLOBAL_LOADING));
    m_helpText->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_helpText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_helpText->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_helpText->setPos(VfxPoint((BKM_MENU_POS_X + (BKM_MENU_POS_X + BKM_MENU_WIDTH)) >> 1,
                                (BKM_MENU_POS_Y + (BKM_MENU_POS_Y + BKM_MENU_HEIGHT)) >> 1));
    m_helpText->setSize(BKM_MENU_WIDTH, BKM_MENU_HEIGHT);

    // Create page up button
    VFX_OBJ_CREATE(m_pageUpButton, VcpButtonInternal, this);
    m_pageUpButtonUpImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_DIS);
    m_pageUpButton->setBackgroundUp(m_pageUpButtonUpImage, VFX_TRUE);
    m_pageUpButtonDownImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_DIS);
    m_pageUpButton->setBackgroundDown(m_pageUpButtonDownImage, VFX_TRUE);
    m_pageUpButton->setPos(VfxPoint(BKM_PAGE_UP_BUTTON_POS_X, BKM_PAGE_UP_BUTTON_POS_Y));
    
    // Create page down button
    VFX_OBJ_CREATE(m_pageDownButton, VcpButtonInternal, this);
    m_pageDownButtonUpImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_DIS);
    m_pageDownButton->setBackgroundUp(m_pageDownButtonUpImage, VFX_TRUE);
    m_pageDownButtonDownImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_DIS);
    m_pageDownButton->setBackgroundDown(m_pageDownButtonDownImage, VFX_TRUE);
    m_pageDownButton->setPos(VfxPoint(BKM_PAGE_DOWN_BUTTON_POS_X, BKM_PAGE_DOWN_BUTTON_POS_Y));
    
    // Bookmark widget
    setBounds(m_bgImg->getBounds());
    setIsCached(VFX_TRUE);
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

#ifdef __USB_IN_NORMAL_MODE__
    // Check if USB mass storage mode
    if (vadp_v2p_hs_bkm_usb_is_in_mass_storage_mode())
    {
        VfxResId string_id = (VfxResId)vadp_v2p_hs_bkm_usb_get_error_info();
        
        if (m_helpText)
        {
            m_helpText->setString(VFX_WSTR_RES(string_id));
        }
        
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    
    // Initialize Opera bookmark service
    vadp_v2p_hs_bkm_init_cntx();

    VfxS32 retval = vadp_v2p_hs_bkm_init_bookmark();
    if (retval == OPERA_API_OK)
    {
        retval = vadp_v2p_hs_bkm_get_bookmark(OPERA_BOOKMARK_DEFAULT);
        if (retval == OPERA_API_OK)
        {
            if (vadp_v2p_hs_bkm_get_bookmark_num() == 0)
            {
                m_helpText->setString(VFX_WSTR_RES(STR_GLOBAL_EMPTY));
            }
            else
            {
                m_helpText->setHidden(VFX_TRUE);
                createBookmarkMenu();
            }
        }
        else
        {
            if (m_helpText)
            {
                m_helpText->setString(VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE));
            }
        }
    }
    else
    {
        if (m_helpText)
        {
            m_helpText->setString(VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE));
        }
    }
}

void VappHsWidgetBookmark::onReleaseView()
{
    VFX_OBJ_CLOSE(m_bgImg);
    VFX_OBJ_CLOSE(m_widgetTitle);
    if (m_pageIndicater != NULL)
    {
        VFX_OBJ_CLOSE(m_pageIndicater);
    }
    VFX_OBJ_CLOSE(m_helpText);
    VFX_OBJ_CLOSE(m_pageUpButton);
    VFX_OBJ_CLOSE(m_pageDownButton);
    if (m_bookmarkMenu != NULL)
    {
        VFX_OBJ_CLOSE(m_bookmarkMenu);
    }

    // If user drag widget into widget bar, reset m_firstBookmarkID as 0
    if (m_widgetState & WIDGET_STATE_REMOVE_FROM_DESKTOP) 
    {
        m_firstBookmarkID = 0;
        m_widgetState &= ~WIDGET_STATE_REMOVE_FROM_DESKTOP;
    }
    else
    {
        // If bookmark is available
        if (m_pageNumber != 0)
        {
            vadp_v2p_hs_bkm_get_bookmark_id_by_index((m_pageNumber - 1) * BKM_MENU_VIEW_REGION_ROW_NUM * BKM_MENU_VIEW_REGION_COLUMN_NUM,
                                                     &m_firstBookmarkID);
        }
    }
    
    vadp_v2p_hs_bkm_exit_bookmark();
    vadp_v2p_hs_bkm_deinit_cntx();
}

void VappHsWidgetBookmark::onAddToDesktop()
{
    m_widgetState &= ~WIDGET_STATE_REMOVE_FROM_DESKTOP;
}

void VappHsWidgetBookmark::onRemoveFromDesktop()
{
    m_widgetState |= WIDGET_STATE_REMOVE_FROM_DESKTOP;
}

void VappHsWidgetBookmark::createBookmarkMenu()
{
    // Create bookmark menu
    VFX_OBJ_CREATE(m_bookmarkMenu, VcpHsWidgetBookmarkMenu, this);
    m_bookmarkMenu->setPos(VfxPoint(BKM_MENU_POS_X, BKM_MENU_POS_Y));
    m_bookmarkMenu->setBounds(VfxRect(0, 0, BKM_MENU_WIDTH, BKM_MENU_HEIGHT));
    if (BKM_MENU_SCROLL_DIRECTION == VcpBaseMenuLayout::SCROLLDIR_HORZ)
    {
        m_bookmarkMenu->setLayoutParameter(vadp_v2p_hs_bkm_get_bookmark_num(),
                                           BKM_MENU_WIDTH / BKM_MENU_VIEW_REGION_COLUMN_NUM,
                                           BKM_MENU_HEIGHT / BKM_MENU_VIEW_REGION_ROW_NUM,
                                           BKM_MENU_VIEW_REGION_ROW_NUM,
                                           BKM_MENU_VIEW_REGION_COLUMN_NUM,
                                           VcpBaseMenuLayout::SCROLLDIR_HORZ);
        m_bookmarkMenu->enableHorizontalScrollIndicator(VFX_FALSE);   
    }
    else
    {
        m_bookmarkMenu->setLayoutParameter(vadp_v2p_hs_bkm_get_bookmark_num(),
                                           BKM_MENU_WIDTH / BKM_MENU_VIEW_REGION_COLUMN_NUM,
                                           BKM_MENU_HEIGHT / BKM_MENU_VIEW_REGION_ROW_NUM,
                                           BKM_MENU_VIEW_REGION_ROW_NUM,
                                           BKM_MENU_VIEW_REGION_COLUMN_NUM,
                                           VcpBaseMenuLayout::SCROLLDIR_VERT);
        m_bookmarkMenu->enableVerticalScrollIndicator(VFX_FALSE);   
    }

    // Create page indicator
    VFX_OBJ_CREATE(m_pageIndicater, VfxTextFrame, this);
    m_pageIndicater->setFont(VfxFontDesc(g_vfxFontSmall));
    m_pageIndicater->setColor(VFX_COLOR_WHITE);
    m_pageIndicater->setAnchor(VfxFPoint(1.0f, 0.0f));
    m_pageIndicater->setPos(VfxPoint(BKM_PAGE_INDICATOR_POS_X, BKM_PAGE_INDICATOR_POS_Y));

    // Adjust page number when go back to home screen
    if (m_firstBookmarkID != 0)
    {
        VfxS32 index;
        if (vadp_v2p_hs_bkm_get_bookmark_index_by_id(m_firstBookmarkID, &index))
        {
            m_pageNumber = index / (BKM_MENU_VIEW_REGION_ROW_NUM * BKM_MENU_VIEW_REGION_COLUMN_NUM) + 1;

            if (BKM_MENU_SCROLL_DIRECTION == VcpBaseMenuLayout::SCROLLDIR_HORZ)
            {
                m_bookmarkMenu->scrollContent(VfxPoint((m_pageNumber - 1) * BKM_MENU_WIDTH, 0), VFX_FALSE);
            }
            else
            {
                m_bookmarkMenu->scrollContent(VfxPoint(0, (m_pageNumber - 1) * BKM_MENU_HEIGHT), VFX_FALSE);
            }
        }
        else
        {
            m_pageNumber = 1;
        }
    }
    else
    {
        m_pageNumber = 1;
    }
    updatePageIndAndButton();
}

void VappHsWidgetBookmark::updatePageIndAndButton()
{
    // Update page up button
    if (m_pageNumber == 1)
    {
        m_pageUpButtonUpImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_DIS);
        m_pageUpButtonDownImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_DIS);
        m_pageUpButton->m_eventUp.disconnect(this, &VappHsWidgetBookmark::pageUp);
        m_pageUpButton->m_eventDown.disconnect(this, &VappHsWidgetBookmark::buttonDownFeedback);
    }
    else
    {
        m_pageUpButtonUpImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_UP);
        m_pageUpButtonDownImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_DOWN);
        m_pageUpButton->m_eventUp.connect(this, &VappHsWidgetBookmark::pageUp);
        m_pageUpButton->m_eventDown.connect(this, &VappHsWidgetBookmark::buttonDownFeedback);
    }
    m_pageUpButton->invalidate();

    // Update page down button
    VfxS32 totalPageNumber = (vadp_v2p_hs_bkm_get_bookmark_num() + BKM_MENU_VIEW_REGION_ROW_NUM * BKM_MENU_VIEW_REGION_COLUMN_NUM - 1) / (BKM_MENU_VIEW_REGION_ROW_NUM * BKM_MENU_VIEW_REGION_COLUMN_NUM);
    if (m_pageNumber == totalPageNumber)
    {
        m_pageDownButtonUpImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_DIS);
        m_pageDownButtonDownImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_DIS);
        m_pageDownButton->m_eventUp.disconnect(this, &VappHsWidgetBookmark::pageDown);
        m_pageDownButton->m_eventDown.disconnect(this, &VappHsWidgetBookmark::buttonDownFeedback);
    }
    else
    {
        m_pageDownButtonUpImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_UP);
        m_pageDownButtonDownImage.setResId(VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_DOWN);
        m_pageDownButton->m_eventUp.connect(this, &VappHsWidgetBookmark::pageDown);
        m_pageDownButton->m_eventDown.connect(this, &VappHsWidgetBookmark::buttonDownFeedback);
    }
    m_pageDownButton->invalidate();

    // Update page indicator
    VfxWString indicator;
    indicator.format("%d/%d", m_pageNumber, totalPageNumber);
    m_pageIndicater->setString(indicator);
}

void VappHsWidgetBookmark::pageUp()
{
    m_pageNumber--;
    
    if (BKM_MENU_SCROLL_DIRECTION == VcpBaseMenuLayout::SCROLLDIR_HORZ)
    {
        m_bookmarkMenu->scrollContent(VfxPoint((m_pageNumber - 1) * BKM_MENU_WIDTH, 0), VFX_TRUE);
    }
    else
    {
        m_bookmarkMenu->scrollContent(VfxPoint(0, (m_pageNumber - 1) * BKM_MENU_HEIGHT), VFX_TRUE);
    }
    
    updatePageIndAndButton();
}

void VappHsWidgetBookmark::pageDown()
{
    m_pageNumber++;

    if (BKM_MENU_SCROLL_DIRECTION == VcpBaseMenuLayout::SCROLLDIR_HORZ)
    {
        m_bookmarkMenu->scrollContent(VfxPoint((m_pageNumber - 1) * BKM_MENU_WIDTH, 0), VFX_TRUE);
    }
    else
    {
        m_bookmarkMenu->scrollContent(VfxPoint(0, (m_pageNumber - 1) * BKM_MENU_HEIGHT), VFX_TRUE);
    }

    updatePageIndAndButton();
}

void VappHsWidgetBookmark::buttonDownFeedback()
{
    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
}

#endif /* __MMI_VUI_HOMESCREEN_BOOKMARK__ */

