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
 *  vcp_normal_mode_menu.cpp
 *
 * Project:
 * --------
 *  3D Main Menu
 *
 * Description:
 * ------------
 *  3D Main Menu
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_3D_MAINMENU__

#include "vcp_normal_mode_menu.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vfx_timer.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vrt_system.h"
#include "kal_public_api.h"
#include "vrt_datatype.h"
#include "kal_general_types.h"
#include "vfx_string.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vcp_page_menu_util.h"
#include "mmi_rp_srv_venus_component_normal_mode_menu_def.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

#define MAINMENU_PAGE_LEFT_EXTENDABLE
//#define MAINMENU_FPS_TEST

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

// normal mode menu layout constants

#if defined(__MMI_MAINLCD_240X320__)

// cell layout
static const VfxS32 MAINMENU_PAGE_ROW_COUNT = 3;
static const VfxS32 MAINMENU_PAGE_COLUMN_COUNT = 3;

static const VfxS32 MAINMENU_CELL_START_X = 15;
static const VfxS32 MAINMENU_CELL_START_Y = 6;

static const VfxS32 MAINMENU_CELL_OFFSET_X = 52+18;
static const VfxS32 MAINMENU_CELL_OFFSET_Y = 52+25;

static const VfxS32 MAINMENU_PAGE_MARGIN = 20;

// cell content layout
static const VfxS32 MAINMENU_CELL_VISIBLE_WIDTH = 52+18;
static const VfxS32 MAINMENU_CELL_VISIBLE_HEIGHT = 52+25;

static const VfxS32 MAINMENU_CELL_ICON_WIDTH = 52;
static const VfxS32 MAINMENU_CELL_ICON_HEIGHT = 52;
static const VfxS32 MAINMENU_CELL_ICON_OFFSET_X = 9;
static const VfxS32 MAINMENU_CELL_ICON_OFFSET_Y = 0;

static const VfxS32 MAINMENU_CELL_TITLE_OFFSET_X = 1;
static const VfxS32 MAINMENU_CELL_TITLE_OFFSET_Y = 52+4;
static const VfxS32 MAINMENU_CELL_TITLE_WIDTH = 60;
static const VfxS32 MAINMENU_CELL_TITLE_HEIGHT = 20;

static const VfxS32 MAINMENU_CELL_TITLE_FONT_SIZE = 13;

#elif defined(__MMI_MAINLCD_240X400__)

// cell layout
static const VfxS32 MAINMENU_PAGE_ROW_COUNT = 4;
static const VfxS32 MAINMENU_PAGE_COLUMN_COUNT = 3;

static const VfxS32 MAINMENU_CELL_START_X = 15;
static const VfxS32 MAINMENU_CELL_START_Y = 6;

static const VfxS32 MAINMENU_CELL_OFFSET_X = 52+18;
static const VfxS32 MAINMENU_CELL_OFFSET_Y = 52+28;

static const VfxS32 MAINMENU_PAGE_MARGIN = 20;

// cell content layout
static const VfxS32 MAINMENU_CELL_VISIBLE_WIDTH = 52+18;
static const VfxS32 MAINMENU_CELL_VISIBLE_HEIGHT = 52+25;

static const VfxS32 MAINMENU_CELL_ICON_WIDTH = 52;
static const VfxS32 MAINMENU_CELL_ICON_HEIGHT = 52;
static const VfxS32 MAINMENU_CELL_ICON_OFFSET_X = 9;
static const VfxS32 MAINMENU_CELL_ICON_OFFSET_Y = 0;

static const VfxS32 MAINMENU_CELL_TITLE_OFFSET_X = 1;
static const VfxS32 MAINMENU_CELL_TITLE_OFFSET_Y = 52+4;
static const VfxS32 MAINMENU_CELL_TITLE_WIDTH = 60;
static const VfxS32 MAINMENU_CELL_TITLE_HEIGHT = 20;

static const VfxS32 MAINMENU_CELL_TITLE_FONT_SIZE = 13;

#else // default and HVGA case

// cell layout
static const VfxS32 MAINMENU_PAGE_ROW_COUNT = 4;
static const VfxS32 MAINMENU_PAGE_COLUMN_COUNT = 4;

static const VfxS32 MAINMENU_CELL_START_X = 9;
static const VfxS32 MAINMENU_CELL_START_Y = 11;

static const VfxS32 MAINMENU_CELL_OFFSET_X = 65+11;
static const VfxS32 MAINMENU_CELL_OFFSET_Y = 65+2+20+5;

static const VfxS32 MAINMENU_PAGE_MARGIN = 20;

// cell content layout
static const VfxS32 MAINMENU_CELL_VISIBLE_WIDTH = 65+11;
static const VfxS32 MAINMENU_CELL_VISIBLE_HEIGHT = 65+2+20;

static const VfxS32 MAINMENU_CELL_ICON_WIDTH = 65;
static const VfxS32 MAINMENU_CELL_ICON_HEIGHT = 65;
static const VfxS32 MAINMENU_CELL_ICON_OFFSET_X = 5;
static const VfxS32 MAINMENU_CELL_ICON_OFFSET_Y = 0;

static const VfxS32 MAINMENU_CELL_TITLE_OFFSET_X = 1;
static const VfxS32 MAINMENU_CELL_TITLE_OFFSET_Y = 65+2+4;
static const VfxS32 MAINMENU_CELL_TITLE_WIDTH = 73;
static const VfxS32 MAINMENU_CELL_TITLE_HEIGHT = 20-4;

static const VfxS32 MAINMENU_CELL_TITLE_FONT_SIZE = 13;

#endif


// mainmenu user interaction constatnt
static const VfxS32 MAINMENU_CANCEL_HOVER_THRESHOLD_X = 15;
static const VfxS32 MAINMENU_CANCEL_HOVER_THRESHOLD_Y = 40;

static const VfxS32 MAINMENU_LONG_SWIPE_THRESHOLD = 600;

static const VfxS32 MAINMENU_SWIPE_RANGE_THRESHOLD = 15;
static const VfxS32 MAINMENU_MIDIUM_SWIPE_RANGE_THRESHOLD = 100;
static const VfxS32 MAINMENU_BIG_SWIPE_RANGE_THRESHOLD = 200;

static const VfxS32 MAINMENU_BIG_SWIPE_SPEED_THRESHOLD = 1000;
static const VfxS32 MAINMENU_NO_HOVER = -1;
static const VfxS32 MAINMENU_NO_CELL = -1;

// mainmenu animation constatnt
#ifdef MAINMENU_FPS_TEST
static const VfxS32 MAINMENU_ANIMTIME_INSTANT = 200;
static const VfxS32 MAINMENU_ANIMTIME_RELEASE = 5000;
static const VfxS32 MAINMENU_ORGANIZE_DURATION = 2000;
#else
static const VfxS32 MAINMENU_ANIMTIME_INSTANT = 1;
static const VfxS32 MAINMENU_ANIMTIME_RELEASE = 250;
static const VfxS32 MAINMENU_ORGANIZE_DURATION = 250;
#endif

static const VfxS32 MAINMENU_LONG_PRESS_DELAY = 1000;
static const VfxS32 MAINMENU_ORGANIZE_AUTO_SCROLL_CD = 2000;
static const VfxS32 MAINMENU_ORGANIZE_AUTO_SCROLL_MARGIN = 30;

static const VfxFloat MAINMENU_ROTATION_LIMIT = 15.0f;

static const VfxFloat MAINMENU_BOUND_ROTATE_FACTOR = -0.09f;

// page indicator layout constants
#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 MAINMENU_INDICATOR_OFFSET_Y = -5;
#elif defined(__MMI_MAINLCD_240X400__)
static const VfxS32 MAINMENU_INDICATOR_OFFSET_Y = -10;
#else // default and HVGA case
static const VfxS32 MAINMENU_INDICATOR_OFFSET_Y = 0;
#endif

/*****************************************************************************
  * Class VappMmCell
  *****************************************************************************/
VappMmCell::VappMmCell(VfxResId imageID, const VfxWString &title):
m_firstDisplay(VFX_TRUE),
m_imageID(imageID),
m_title(title)
{
}

void VappMmCell::onCellDisplay()
{
    if (!m_firstDisplay)
    {
        return;
    }
    m_firstDisplay = VFX_FALSE;

    // add image frame
    VfxImageFrame * imageFrame;
    VFX_OBJ_CREATE(imageFrame, VfxImageFrame, this);
    imageFrame->setResId(m_imageID);
    imageFrame->setSize(MAINMENU_CELL_ICON_WIDTH, MAINMENU_CELL_ICON_HEIGHT);
    imageFrame->setPos(MAINMENU_CELL_ICON_OFFSET_X, MAINMENU_CELL_ICON_OFFSET_Y);

    // add text frame
    VfxTextFrame * textFrame;
    VFX_OBJ_CREATE(textFrame, VfxTextFrame, this);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(MAINMENU_CELL_TITLE_FONT_SIZE);
    textFrame->setFont(fontDesc);
    textFrame->setFullLineHeightMode(VFX_TRUE);
    textFrame->setPos(MAINMENU_CELL_TITLE_OFFSET_X, MAINMENU_CELL_TITLE_OFFSET_Y);
    textFrame->setSize(MAINMENU_CELL_TITLE_WIDTH, MAINMENU_CELL_TITLE_HEIGHT);
    textFrame->setAnchor(0.0f, 0.0f);
    textFrame->setString(m_title);
    textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    textFrame->setAutoResized(VFX_FALSE);
    textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
}

/*****************************************************************************
 * Class VcpNormalModeMenu
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcpNormalModeMenu", VcpNormalModeMenu, VfxControl);

/*****************************************************************************
 * FUNCTION
 *  VcpNormalModeMenu::VcpNormalModeMenu
 * DESCRIPTION
 *  Constructor of VcpNormalModeMenu class
 * PARAMETERS
 *
 * RETURNS
 *  *****************************************************************************/
VcpNormalModeMenu::VcpNormalModeMenu():
    m_pageCount(0),
    m_stableCurrentPageIndex(0),
    m_menuView(NULL),
    m_holdFrame(NULL),
    m_pageIndicator(NULL),
    m_longPressTimer(NULL),
    m_hover(MAINMENU_NO_HOVER),
    m_startPen(VFX_FALSE),
    m_translateOrigX(0),
    m_organizeMode(VFX_FALSE),
    m_organizeTo(MAINMENU_NO_CELL),
    m_lastAutoScrollTime(0),
    m_leftExtended(VFX_FALSE),
    m_rightExtended(VFX_FALSE)
{
    for (VfxS32 i = 0; i < VCP_NORMAL_MODE_MENU_MAX_APP; ++i)
    {
        m_cells[i] = NULL;
    }
}

void VcpNormalModeMenu::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_menuView, VcpPageMenuView, this);

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    setCacheMode(VFX_CACHE_MODE_PREVENT_PARENTS);
#endif
    vcpPageMenuApplyFrameRenderHints(this);

    // set default layout
    VcpPageMenuLayout layout;
    layout.rowCount = MAINMENU_PAGE_ROW_COUNT;
    layout.columnCount = MAINMENU_PAGE_COLUMN_COUNT;
    layout.cellStartX = MAINMENU_CELL_START_X;
    layout.cellStartY = MAINMENU_CELL_START_Y;
    layout.cellOffsetX = MAINMENU_CELL_OFFSET_X;
    layout.cellOffsetY = MAINMENU_CELL_OFFSET_Y;
    layout.pageMargin = MAINMENU_PAGE_MARGIN;
    m_menuView->setLayout(layout);

    VFX_OBJ_CREATE(m_pageIndicator, VcpPageMenuIndicator, this);
    m_pageIndicator->setBgImage(VfxImageSrc(VAPP_3D_MAINMENU_INDICATOR_BG) );
    m_pageIndicator->setCellImage(VfxImageSrc(VAPP_3D_MAINMENU_INDICATOR_BLACK_DOT),
            VfxImageSrc(VAPP_3D_MAINMENU_INDICATOR_HIGHLIGHT));

    m_pageIndicator->setAnchor(0.5f, 0.0f);

    updatePageIndicatorPos();
    m_pageIndicator->m_pageSelected.connect(this, &VcpNormalModeMenu::onPageIndicatorSelected);

    VFX_OBJ_CREATE(m_longPressTimer, VfxTimer, this);
    m_longPressTimer->m_signalTick.connect(this, &VcpNormalModeMenu::onLongPressTimerTick);

    checkUpdate();
}

void VcpNormalModeMenu::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    m_menuView->setSize(value.size.width, value.size.height );

    updatePageIndicatorPos();
}

void VcpNormalModeMenu::setMenuItem(VfxS32 index, VcpPageMenuCell * cell)
{
    if (m_cells[index] != NULL)
    {
        m_menuView->setAnimDirty(MAINMENU_ORGANIZE_DURATION);
    }

    m_cells[index] = cell;
    if (cell == NULL)
    {
        return;
    }

    cell->setAutoAnimate(VFX_TRUE);
    cell->setCacheMode(VFX_CACHE_MODE_FORCE);
    
#if defined(__MMI_FTE_SUPPORT_SLIM__)
    cell->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_COLOR_KEY);
#endif
    vcpPageMenuApplyFrameRenderHints(cell);


    m_menuView->initCellAnim(cell, VCP_PAGE_MENU_GROUP_MAIN);
}

void VcpNormalModeMenu::setCellIconSize(const VfxSize & size)
{
    m_menuView->setCellIconSize(size);
}

VcpPageMenuCell * VcpNormalModeMenu::getMenuItem(VfxS32 index) const
{
    return m_cells[index];
}

VfxS32 VcpNormalModeMenu::getMenuItemCountPerPage() const
{
    return m_menuView->getPageItemCount();
}

VfxS32 VcpNormalModeMenu::getCurrentPageIndex() const
{
    return m_menuView->getNearestPage();
}

void VcpNormalModeMenu::setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated)
{
    if (animated)
    {
        scrollToPage(pageIndex, MAINMENU_ANIMTIME_RELEASE);
    }
    else
    {
        scrollToPage(pageIndex, MAINMENU_ANIMTIME_INSTANT);
    }
}

VfxS32 VcpNormalModeMenu::getCurrentAppIndex() const
{
    VfxS32 page = m_menuView->getNearestPage();
    VfxS32 count = 0;
    for (VfxS32 i = 0; i < page; ++i)
    {
        for (VfxS32 j = 0; j < m_menuView->getPageItemCount(); ++j)
        {
            if (m_cells[i * m_menuView->getPageItemCount() + j] != NULL)
            {
                count += 1;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

const VcpPageMenuLayout & VcpNormalModeMenu::getMenuLayout() const
{
    return m_menuView->getLayout();
}

void VcpNormalModeMenu::setMenuLayout(const VcpPageMenuLayout & layout)
{
    m_menuView->setLayout(layout);
    updatePageIndicatorPos();
}

void VcpNormalModeMenu::leaveOrganizationMode()
{
    if (!getOrganizeMode() )
    {
        return;
    }

    handleOrganizeEnd();

    // set organized state
    setOrganizeMode(VFX_FALSE);
    m_organizationChanged.postEmit(VFX_FALSE);
}

void VcpNormalModeMenu::onUpdate()
{
    VfxControl::onUpdate();

    if (m_menuView->getNearestPage() > getPageCount() - 1)
    {
        scrollToPage(getPageCount() - 1, MAINMENU_ANIMTIME_INSTANT);
    }

    const VfxS32 currentPageIndex = m_menuView->getNearestPage();
    m_pageIndicator->setCurrentPage(currentPageIndex);
    VfxS32 indicatorPageCount = getPageCount();
    if (currentPageIndex + 1 > indicatorPageCount && currentPageIndex < m_menuView->getMaxPageCount(VCP_NORMAL_MODE_MENU_MAX_APP) )
    {
        indicatorPageCount = currentPageIndex + 1;
    }
    m_pageIndicator->setIndicatorPageCount(indicatorPageCount);
    m_pageIndicator->update();

    m_menuView->update(m_cells, VCP_NORMAL_MODE_MENU_MAX_APP, NULL, 0);
}

void VcpNormalModeMenu::onLongPressTimerTick(VfxTimer *source)
{
    if (getHover() == MAINMENU_NO_HOVER)
    {
        return;
    }

    setOrganizeMode(VFX_TRUE);
    m_organizationChanged.postEmit(VFX_TRUE);
    m_startPen = VFX_FALSE;

    handleOrganizeStart();

    m_menuView->setAnimDirty(MAINMENU_ORGANIZE_DURATION);
}

void VcpNormalModeMenu::onPageIndicatorSelected(VfxS32 pageSelected)
{
    scrollToPage(pageSelected, MAINMENU_ANIMTIME_RELEASE);
}

VfxBool VcpNormalModeMenu::onPenInput(VfxPenEvent &event)
{
    // default animation parameters
    m_menuView->setDragOnIndicator(VFX_FALSE);

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return handlePenDown(event.getRelPos(this) );
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        // long tap is ignored, VcpNormalModeMenu handle long tap behavior itself
    }
    else if (getOrganizeMode() && m_menuView->getDraggingFrame() != NULL)
    {
        return handleOrganize(event.type, event.getRelPos(this) );
    }
    else
    {
        return handleScroll(event);
    }

    return VfxControl::onPenInput(event);
}

VfxBool VcpNormalModeMenu::handlePenDown(const VfxPoint &touchDownPos)
{
    // to stop translate anim
    m_menuView->syncTranslateX();

    m_translateOrigX = m_menuView->getTranslateX();
    m_startPen = VFX_TRUE;
    if (!m_menuView->isTransitioning() )
    {
        setHover(cellHittest(touchDownPos, VFX_FALSE) );
        if (getHover() != MAINMENU_NO_HOVER)
        {
            m_menuView->initDraggingFramePos(m_cells[getHover() ], VCP_PAGE_MENU_GROUP_MAIN, touchDownPos.x, touchDownPos.y);

            if (getOrganizeMode() )
            {
                handleOrganizeStart();
            }
            else
            {
                m_longPressTimer->setStartDelay(MAINMENU_LONG_PRESS_DELAY);
                m_longPressTimer->start();
            }
        }
    }
    checkUpdate();
    return VFX_TRUE;
}

VfxBool VcpNormalModeMenu::handleScroll(const VfxPenEvent &event)
{
    const VfxPoint touchPos = event.getRelPos(this);
    const VfxPoint touchDownPos = event.getRelDownPos(this);
    const VfxS32 diffOrigX = touchPos.x - touchDownPos.x;
    const VfxS32 diffOrigY = touchPos.y - touchDownPos.y;

    if (VFX_ABS(diffOrigX) > MAINMENU_CANCEL_HOVER_THRESHOLD_X ||
            VFX_ABS(diffOrigY) > MAINMENU_CANCEL_HOVER_THRESHOLD_Y)
    {
        m_longPressTimer->stop();
        setHover(MAINMENU_NO_HOVER);
        if (m_startPen)
        {
            m_startPen = VFX_FALSE;
        }
        checkUpdate();
    }

    if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        handleScrollMove(diffOrigX, diffOrigY);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        const VfxS32 elapse = event.timeStamp - event.downTimeStamp;
        handleScrollEnd(diffOrigX, elapse);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        const VfxS32 elapse = MAINMENU_LONG_SWIPE_THRESHOLD * 2;
        const VfxS32 diffX = 0;
        m_startPen = VFX_FALSE;
        handleScrollEnd(diffX, elapse);
    }

    return VFX_TRUE;
}

void VcpNormalModeMenu::handleScrollMove(VfxS32 diffOrigX, VfxS32 diffOrigY)
{
    if (!m_startPen)
    {
        // limit for modis
        if (diffOrigX > getSize().width)
        {
            diffOrigX = getSize().width;
        }
        else if (diffOrigX < -getSize().width)
        {
            diffOrigX = -getSize().width;
        }
        VfxS32 translateX = m_translateOrigX + diffOrigX;

        // limiting
        if (translateX > 0)
        {
            const VfxFloat rotateAngle = (translateX - 0) * MAINMENU_BOUND_ROTATE_FACTOR;
            m_menuView->setRotateAngle(rotateAngle , MAINMENU_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = 0;
        }
        if (translateX < m_menuView->getPageTranslateX(getPageCount() - 1) )
        {
            const VfxFloat rotateAngle = (translateX -
                        ( m_menuView->getPageTranslateX(getPageCount() - 1) ) ) *
                        MAINMENU_BOUND_ROTATE_FACTOR;
            m_menuView->setRotateAngle(rotateAngle , MAINMENU_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = m_menuView->getPageTranslateX(getPageCount() - 1);
        }
        m_menuView->setTranslateX(translateX, MAINMENU_ANIMTIME_INSTANT);

        checkUpdate();
    }
}

void VcpNormalModeMenu::handleScrollEnd(VfxS32 diffX, VfxMsec elapse)
{
    const VfxFloat speed = static_cast<VfxFloat>(diffX * 1000) / elapse;

    m_menuView->setRotateAngle(0, MAINMENU_ANIMTIME_RELEASE, VFX_TRUE);

    if (m_startPen && !m_menuView->isTransitioning() )
    {
        // clicked
        if (getHover() != MAINMENU_NO_HOVER)
        {
            m_appClicked.postEmit(m_cells[getHover() ]->getCellIndex() );
        }
    }
    else if (elapse < MAINMENU_LONG_SWIPE_THRESHOLD)
    {
        handleScrollSwipe(diffX, speed);
    }
    else
    {
        // scroll to the nearest page
        scrollToPage(m_menuView->getNearestPage(), MAINMENU_ANIMTIME_RELEASE);
    }

    setHover(MAINMENU_NO_HOVER);

    // limiting
    if (m_menuView->getTranslateX() > 0)
    {
        scrollToPage(0, MAINMENU_ANIMTIME_RELEASE);
    }
    if (m_menuView->getTranslateX() < m_menuView->getPageTranslateX(getPageCount() - 1) )
    {
        scrollToPage(getPageCount() - 1, MAINMENU_ANIMTIME_RELEASE);
    }

    checkUpdate();
}

void VcpNormalModeMenu::handleScrollSwipe(VfxS32 diffX, VfxFloat speed)
{
    if (diffX > MAINMENU_SWIPE_RANGE_THRESHOLD)
    {
        if (diffX > MAINMENU_BIG_SWIPE_RANGE_THRESHOLD &&
                speed > MAINMENU_BIG_SWIPE_SPEED_THRESHOLD &&
                (m_menuView->getTranslateX() < m_menuView->getPageTranslateX(1) ) )
        {
            scrollToPage(m_menuView->getPreviousPage() - 1, MAINMENU_ANIMTIME_RELEASE * 2);
            m_menuView->setRotateAngle(MAINMENU_ROTATION_LIMIT, MAINMENU_ANIMTIME_RELEASE * 3, VFX_TRUE);
        }
        else if (diffX > MAINMENU_MIDIUM_SWIPE_RANGE_THRESHOLD)
        {
            scrollToPage(m_menuView->getPreviousPage(), MAINMENU_ANIMTIME_RELEASE);
        }
        else
        {
            scrollToPage(m_menuView->getPreviousPage(), MAINMENU_ANIMTIME_RELEASE * 2);
        }
    }
    else if (diffX < -MAINMENU_SWIPE_RANGE_THRESHOLD)
    {
        if (diffX < -MAINMENU_BIG_SWIPE_RANGE_THRESHOLD &&
                speed < -MAINMENU_BIG_SWIPE_SPEED_THRESHOLD &&
                (m_menuView->getTranslateX() > ( m_menuView->getPageTranslateX(getPageCount() - 2) ) ) )
        {
            scrollToPage(m_menuView->getNextPage() + 1, MAINMENU_ANIMTIME_RELEASE * 2);
            m_menuView->setRotateAngle(-MAINMENU_ROTATION_LIMIT, MAINMENU_ANIMTIME_RELEASE * 3, VFX_TRUE);
        }
        else if (diffX < -MAINMENU_MIDIUM_SWIPE_RANGE_THRESHOLD)
        {
            scrollToPage(m_menuView->getNextPage(), MAINMENU_ANIMTIME_RELEASE);
        }
        else
        {
            scrollToPage(m_menuView->getNextPage(), MAINMENU_ANIMTIME_RELEASE * 2);
        }
    }
    else
    {
        scrollToPage(m_menuView->getNearestPage(), MAINMENU_ANIMTIME_RELEASE);
    }
}

VfxBool VcpNormalModeMenu::handleOrganize(VfxPenEventTypeEnum touchType, const VfxPoint &touchPos)
{
    if (touchType == VFX_PEN_EVENT_TYPE_MOVE)
    {
        handleOrganizeMove(touchPos.x, touchPos.y);
    }
    else if (touchType == VFX_PEN_EVENT_TYPE_UP)
    {
        handleOrganizePut();
    }
    else if (touchType == VFX_PEN_EVENT_TYPE_ABORT)
    {
        handleOrganizePut();
    }

    return VFX_TRUE;
}

void VcpNormalModeMenu::handleOrganizeStart()
{
    setOrganizeTo(getHover() );
    m_menuView->setDraggingFrame(m_cells[getHover() ] );

    scrollToPage(m_menuView->getNearestPage(), MAINMENU_ANIMTIME_INSTANT);
    m_menuView->setRotateAngle(0, MAINMENU_ANIMTIME_INSTANT, VFX_TRUE);

    checkUpdate();
}

void VcpNormalModeMenu::handleOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    const VfxPoint indicatorPoint = convertPointTo(VfxPoint(touchX, touchY), m_pageIndicator);

    // if the dragging frame is near the page indicator, make it translucent
    const VfxS32 dragOnIndicatorBarMargin = m_menuView->getLayout().cellOffsetX / 2;
    VfxRect extendedIndicatorBound = m_pageIndicator->getBounds();
    extendedIndicatorBound.origin.x -= dragOnIndicatorBarMargin;
    extendedIndicatorBound.origin.y -= dragOnIndicatorBarMargin;
    extendedIndicatorBound.size.width += dragOnIndicatorBarMargin * 2;
    extendedIndicatorBound.size.height += dragOnIndicatorBarMargin * 2;
    if (extendedIndicatorBound.contains(indicatorPoint) )
    {
        m_menuView->setDragOnIndicator(VFX_TRUE);
    }

    if (m_pageIndicator->getBounds().contains(indicatorPoint) )
    {
        const VfxS32 newPage = m_pageIndicator->getTouchPageIndex(indicatorPoint);
        switchOrganizePage(newPage, touchX, touchY);
        return;
    }
    VfxBool crossPageMove = VFX_FALSE;
    const VfxMsec ctime = vrt_sys_get_time();
    if (ctime - m_lastAutoScrollTime > MAINMENU_ORGANIZE_AUTO_SCROLL_CD)
    {
        if (touchX < MAINMENU_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if (currentPage == 0)
            {
#ifdef MAINMENU_PAGE_LEFT_EXTENDABLE
                if (getPageCount() < m_menuView->getMaxPageCount(VCP_NORMAL_MODE_MENU_MAX_APP) && m_leftExtended == VFX_FALSE)
                {
                    // can add page
                    crossPageMove = VFX_TRUE;
                    m_leftExtended = VFX_TRUE;
                }
#endif // MAINMENU_PAGE_LEFT_EXTENDABLE
            }
            else
            {
                crossPageMove = VFX_TRUE;
            }
        }
        else if (touchX > getSize().width - MAINMENU_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if ( (currentPage >= m_menuView->getMaxPageCount(VCP_NORMAL_MODE_MENU_MAX_APP) - 1) )
            {
                // max page cap reached
                crossPageMove = VFX_FALSE;
            }
            else if (currentPage == getPageCount() - 1 && m_rightExtended == VFX_TRUE)
            {
                // can only add 1 page when dragging a app
                crossPageMove = VFX_FALSE;
            }
            else
            {
                crossPageMove = VFX_TRUE;
            }
        }
    }

    if (crossPageMove)
    {
        crossPageOrganizeMove(touchX, touchY);
        m_lastAutoScrollTime = ctime;
    }
    else
    {
        inPageOrganizeMove(touchX, touchY);
    }
}

void VcpNormalModeMenu::crossPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    // in this case, because the user touch move is usually slow, the animation shall be slower
    if (touchX < MAINMENU_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        switchOrganizePage(m_menuView->getPreviousPage(), touchX, touchY);
    }
    else if (touchX > getSize().width - MAINMENU_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        switchOrganizePage(m_menuView->getNextPage(), touchX, touchY);
    }
}

void VcpNormalModeMenu::switchOrganizePage(VfxS32 newPage, VfxS32 touchX, VfxS32 touchY)
{
#ifdef MAINMENU_PAGE_LEFT_EXTENDABLE
    if (newPage == -1)
    {
        newPage = 0;
        for (VfxS32 i = getPageCount() - 1; i >= 0; --i)
        {
            vcpPageMenuMovePageContent(m_cells, m_menuView->getPageItemCount(), i, i+1);
        }
        setPageCount(getPageCount() + 1);
        setOrganizeTo(getOrganizeTo() + m_menuView->getPageItemCount() );
    }
#endif // MAINMENU_PAGE_LEFT_EXTENDABLE

    scrollToPage(newPage, MAINMENU_ORGANIZE_DURATION * 2);

    m_menuView->setDraggingFramePos(touchX, touchY);

    // remove the dragging cell from the old page
    const VfxS32 pageEnd = (getOrganizeTo() + m_menuView->getPageItemCount() ) /
        m_menuView->getPageItemCount() * m_menuView->getPageItemCount();
    for (VfxS32 i = getOrganizeTo(); i < pageEnd - 1; ++i)
    {
        m_cells[i] = m_cells[i + 1];
    }
    if (getHoldFrame() != NULL)
    {
        m_cells[pageEnd - 1] = getHoldFrame();
        setHoldFrame(NULL);
    }
    else
    {
        m_cells[pageEnd - 1] = NULL;
    }

    // adjust the page count if added new page
    if (m_menuView->getNearestPage() >= getPageCount() )
    {
        setPageCount(m_menuView->getNearestPage() + 1);
        m_rightExtended = VFX_TRUE;
    }

    // put the dragging cell to the new page
    const VfxS32 firstInPage = m_menuView->getNearestPage() * m_menuView->getPageItemCount();
    if (m_cells[firstInPage] == NULL)
    {
        m_cells[firstInPage] = m_menuView->getDraggingFrame();
        setOrganizeTo(firstInPage);
    }
    else
    {
        const VfxS32 currentPageEnd = firstInPage + m_menuView->getPageItemCount();
        if (m_cells[currentPageEnd - 1] != NULL)
        {
            setHoldFrame(m_cells[currentPageEnd - 1] );
            m_cells[currentPageEnd - 1] = NULL;
        }

        VfxS32 currentDirect = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
        if (currentDirect ==  MAINMENU_HITTEST_NOT_FOUND &&
                touchY >= m_menuView->getLayout().cellStartY)
        {
            // append to the end of this page
            for (VfxS32 i = firstInPage; i < firstInPage + m_menuView->getPageItemCount(); ++i)
            {
                if (m_cells[i] == NULL)
                {
                    m_cells[i] = m_menuView->getDraggingFrame();
                    setOrganizeTo(i);
                    break;
                }
            }
        }
        else
        {
            if (currentDirect ==  MAINMENU_HITTEST_NOT_FOUND)
            {
                currentDirect = firstInPage;
            }
            // around cells
            for (VfxS32 i = currentPageEnd - 1; i > currentDirect; --i)
            {
                m_cells[i] = m_cells[i - 1];
            }
            m_cells[currentDirect] = m_menuView->getDraggingFrame();
            setOrganizeTo(currentDirect);
        }
    }
    checkUpdate();
}

void VcpNormalModeMenu::inPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    const VfxS32 currentTo = cellHittest(VfxPoint(touchX, touchY), VFX_TRUE);
    if (currentTo != MAINMENU_HITTEST_NOT_FOUND)
    {
        const VfxS32 prevOrganizeTo = getOrganizeTo();
        setOrganizeTo(currentTo);
        if (prevOrganizeTo != getOrganizeTo() )
        {
            if (getOrganizeTo() > prevOrganizeTo)
            {
                for (VfxS32 i = prevOrganizeTo; i < getOrganizeTo(); ++i)
                {
                    m_cells[i] = m_cells[i + 1];
                }
                m_cells[getOrganizeTo() ] = m_menuView->getDraggingFrame();
            }
            else
            {
                for (VfxS32 i = prevOrganizeTo; i > getOrganizeTo(); --i)
                {
                    m_cells[i] = m_cells[i - 1];
                }
                m_cells[getOrganizeTo() ] = m_menuView->getDraggingFrame();
            }
        }
    }
    m_menuView->setDraggingFramePos(touchX, touchY);
    checkUpdate();
}

void VcpNormalModeMenu::handleOrganizePut()
{
    m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), VCP_PAGE_MENU_GROUP_MAIN);
    putHoldFrame();
    setHover(MAINMENU_NO_HOVER);
    m_menuView->setDraggingFrame(NULL);
    m_leftExtended = VFX_FALSE;
    m_rightExtended = VFX_FALSE;

    checkUpdate();
}

void VcpNormalModeMenu::handleOrganizeEnd()
{
    // ensure the dragging frame is put
    handleOrganizePut();

    compactPages();

    checkUpdate();
}

void VcpNormalModeMenu::compactPages()
{
    // remove empty pages
    const VfxS32 currentPageIndex = m_menuView->getNearestPage();
    VfxS32 nonemptyPageCount = 0;
    VfxS32 pageIndexAfterCompact = 0;
    for (VfxS32 i = 0; i < getPageCount(); ++i)
    {
        // set page index to the next page of the last nonempty page
        if (i == currentPageIndex)
        {
            pageIndexAfterCompact = nonemptyPageCount;
        }
        if (!vcpPageMenuIsPageEmpty(m_cells, m_menuView->getPageItemCount(), i) )
        {
            vcpPageMenuMovePageContent(m_cells, m_menuView->getPageItemCount(), i, nonemptyPageCount);
            ++nonemptyPageCount;
        }
    }
    for (VfxS32 i = nonemptyPageCount; i < getPageCount(); ++i)
    {
        vcpPageMenuClearPageContent(m_cells, m_menuView->getPageItemCount(), i);
    }

    if (pageIndexAfterCompact == nonemptyPageCount)
    {
        pageIndexAfterCompact = nonemptyPageCount - 1;
    }

    scrollToPage(pageIndexAfterCompact, MAINMENU_ORGANIZE_DURATION);
    setPageCount(nonemptyPageCount);
}

void VcpNormalModeMenu::putHoldFrame()
{
    if (getHoldFrame() == NULL)
    {
        return;
    }

    const VfxS32 page = m_menuView->getNearestPage();
    if (!putHoldFrameAfterPage(page) )
    {
        // no space to push back, search previous pages for space
        VfxBool result = putHoldFrameBeforePage(page);
        VFX_ASSERT(result);
    }
}

VfxBool VcpNormalModeMenu::putHoldFrameAfterPage(VfxS32 page)
{
    const VfxS32 start = (page + 1) * m_menuView->getPageItemCount();
    for (VfxS32 index = start; index < VCP_NORMAL_MODE_MENU_MAX_APP; ++index)
    {
        if (m_cells[index] == NULL)
        {
            const VfxS32 end = index;
            for (VfxS32 i = end; i > start; --i)
            {
                m_cells[i] = m_cells[i - 1];
            }
            m_cells[start] = getHoldFrame();
            if (end + 1 > getPageCount() * m_menuView->getPageItemCount() )
            {
                setPageCount(getPageCount() + 1);
            }
            setHoldFrame(NULL);
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VfxBool VcpNormalModeMenu::putHoldFrameBeforePage(VfxS32 page)
{
    for (VfxS32 pageIndex = page - 1; pageIndex >= 0; --pageIndex)
    {
        for (VfxS32 i = 0; i < m_menuView->getPageItemCount(); ++i)
        {
            const VfxS32 index = pageIndex * m_menuView->getPageItemCount() + i;
            if (m_cells[index] == NULL)
            {
                m_cells[index] = getHoldFrame();
                setHoldFrame(NULL);
                return VFX_TRUE;
            }
        }
    }
    return VFX_FALSE;
}

void VcpNormalModeMenu::scrollToPage(VfxS32 pageIndex, VfxS32 animTime)
{
    m_menuView->setTranslateX(m_menuView->getPageTranslateX(pageIndex), animTime);
    checkUpdate();

    if (pageIndex != m_stableCurrentPageIndex)
    {
        m_stableCurrentPageIndex = pageIndex;
        m_pageChanged.postEmit(m_stableCurrentPageIndex);
    }
}

void VcpNormalModeMenu::updatePageIndicatorPos()
{
    m_pageIndicator->setPos(getSize().width / 2,
            m_menuView->getLayout().cellStartY +
            m_menuView->getLayout().rowCount * m_menuView->getLayout().cellOffsetY +
            MAINMENU_INDICATOR_OFFSET_Y);
}

VfxBool VcpNormalModeMenu::getOrganizeMode() const
{
    return m_organizeMode;
}

void VcpNormalModeMenu::setOrganizeMode(VfxBool organizeMode)
{
    m_organizeMode = organizeMode;
    m_menuView->setOrganizeMode(organizeMode);
}

VfxS32 VcpNormalModeMenu::getOrganizeTo() const
{
    return m_organizeTo;
}

void VcpNormalModeMenu::setOrganizeTo(VfxS32 organizeTo)
{
    m_organizeTo = organizeTo;
}

VfxS32 VcpNormalModeMenu::getHover() const
{
    return m_hover;
}

void VcpNormalModeMenu::setHover(VfxS32 hover)
{
    m_hover = hover;
    m_menuView->setHover(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, hover) );
}

VfxS32 VcpNormalModeMenu::getPageCount() const
{
    VFX_ASSERT(m_pageCount <= m_menuView->getMaxPageCount(VCP_NORMAL_MODE_MENU_MAX_APP) );
    return m_pageCount;
}

void VcpNormalModeMenu::setPageCount(VfxS32 pageCount)
{
    VFX_ASSERT(pageCount <= m_menuView->getMaxPageCount(VCP_NORMAL_MODE_MENU_MAX_APP) );
    m_pageCount = pageCount;

    // some checks for menu initialization
    if (m_menuView->getNearestPage() >= getPageCount() )
    {
        scrollToPage(getPageCount() - 1, MAINMENU_ORGANIZE_DURATION);
    }
}

VcpPageMenuCell * VcpNormalModeMenu::getHoldFrame() const
{
    return m_holdFrame;
}

void VcpNormalModeMenu::setHoldFrame(VcpPageMenuCell * holdFrame)
{
    m_holdFrame = holdFrame;
    m_menuView->setHoldFrame(holdFrame);
}

VfxS32 VcpNormalModeMenu::cellHittest(VfxPoint clickPoint, VfxBool findLast) const
{
    const VcpPageMenuCellPos pos = m_menuView->baseCellHittest(clickPoint, VCP_NORMAL_MODE_MENU_MAX_APP);

    if (pos.group != VCP_PAGE_MENU_GROUP_MAIN)
    {
        return MAINMENU_HITTEST_NOT_FOUND;
    }

    const VfxS32 index = pos.index;

    if (m_cells[index] != NULL)
    {
        return index;
    }
    else if (findLast)
    {
        // if the clicked cell is NULL,
        // decrease the index and find non-NULL cell
        const VfxS32 firstInPanel = index / m_menuView->getPageItemCount() *
            m_menuView->getPageItemCount();
        VfxS32 countDownIndex = index;
        while (countDownIndex >= firstInPanel)
        {
            if (m_cells[countDownIndex] != NULL)
            {
                return countDownIndex;
            }
            --countDownIndex;
        }
    }
    return MAINMENU_HITTEST_NOT_FOUND;
}

/*****************************************************************************
 * Class VcpNormalModeMenuBuilder
 *****************************************************************************/

VcpNormalModeMenuBuilder::VcpNormalModeMenuBuilder():
    m_allAppData(NULL),
    m_allAppCount(0),
    m_appOrderData(NULL),
    m_appOrderCount(0)
{
}

void VcpNormalModeMenuBuilder::setAllAppData(AppEntry appEntry[], VfxS32 count)
{
    m_allAppData = appEntry;
    m_allAppCount = count;
}

void VcpNormalModeMenuBuilder::setAppOrderData(VfxS32 appOrder[], VfxS32 count)
{
    m_appOrderData = appOrder;
    m_appOrderCount = count;
}

void VcpNormalModeMenuBuilder::loadMenu(VcpNormalModeMenu * menu)
{
    VfxBool firstInit = VFX_TRUE;
    for (VfxS32 i = 0; i < VCP_NORMAL_MODE_MENU_MAX_APP; ++i)
    {
        if (menu->getMenuItem(i) != NULL)
        {
            firstInit = VFX_FALSE;
            break;
        }
    }

    if (firstInit)
    {
        initFrames(menu);
        firstInit = VFX_FALSE;
    }
    else
    {
        reorderFrames(menu);
    }

    // set menu cell icon size
    menu->setCellIconSize(VfxSize(MAINMENU_CELL_ICON_WIDTH, MAINMENU_CELL_ICON_HEIGHT) );
}

void VcpNormalModeMenuBuilder::initFrames(VcpNormalModeMenu * menu)
{
    VfxS32 cellIndex = 0;
    for (VfxS32 i = 0; i < m_appOrderCount; ++i)
    {
        const VfxS32 index = m_appOrderData[i];
        if (index == VCP_NORMAL_MODE_MENU_PAGE_BREAK)
        {
            if (i > 0 && m_appOrderData[i - 1] == VCP_NORMAL_MODE_MENU_PAGE_BREAK)
            {
                break;
            }
            cellIndex = (cellIndex + menu->getMenuItemCountPerPage() - 1) / menu->getMenuItemCountPerPage() * menu->getMenuItemCountPerPage();
            continue;
        }

        VcpPageMenuCell * cell = createCell(index, m_allAppData[index].appIcon, m_allAppData[index].appTitle, menu);
        menu->setMenuItem(cellIndex, cell);

        ++cellIndex;
    }
    menu->setPageCount( (cellIndex + menu->getMenuItemCountPerPage() - 1) / menu->getMenuItemCountPerPage() );
}

void VcpNormalModeMenuBuilder::reorderFrames(VcpNormalModeMenu * menu)
{
    // checks
    checkCellState(menu);

    VcpPageMenuCell ** cellMap = NULL;
    VFX_ALLOC_MEM(cellMap, sizeof(VcpPageMenuCell *) * m_allAppCount, this);

    for (VfxS32 i = 0; i < m_allAppCount; ++i)
    {
        cellMap[i] = NULL;
    }
    // create cellMap data and clear cells data
    for (VfxS32 i = 0; i < VCP_NORMAL_MODE_MENU_MAX_APP; ++i)
    {
        if (menu->getMenuItem(i) == NULL)
        {
            continue;
        }
        if (menu->getMenuItem(i)->getCellIndex() < m_allAppCount)
        {
            cellMap[menu->getMenuItem(i)->getCellIndex() ] = menu->getMenuItem(i);
        }
        menu->setMenuItem(i, NULL);
    }

    for (VfxS32 i = 0; i < m_allAppCount; ++i)
    {
        if (cellMap[i] == NULL)
        {
            VFX_ASSERT(VFX_FALSE);
        }
    }

    // reset the cells data
    VfxS32 cellIndex = 0;
    for (VfxS32 i = 0; i < m_appOrderCount; ++i)
    {
        const VfxS32 index = m_appOrderData[i];
        if (index == VCP_NORMAL_MODE_MENU_PAGE_BREAK)
        {
            if (i > 0 && m_appOrderData[i - 1] == VCP_NORMAL_MODE_MENU_PAGE_BREAK)
            {
                break;
            }
            cellIndex = (cellIndex + menu->getMenuItemCountPerPage() - 1) / menu->getMenuItemCountPerPage() * menu->getMenuItemCountPerPage();
            continue;
        }

        menu->setMenuItem(cellIndex, cellMap[index] );

        ++cellIndex;
    }

    menu->setPageCount( (cellIndex + menu->getMenuItemCountPerPage() - 1) / menu->getMenuItemCountPerPage() );

    VFX_FREE_MEM(cellMap);

    // checks
    checkCellState(menu);
}

void VcpNormalModeMenuBuilder::saveMenu(VcpNormalModeMenu * menu)
{
    // checks
    checkCellState(menu);

    VfxS32 orderIndex = 0;
    for (VfxS32 i = 0; i < menu->getPageCount(); ++i)
    {
        for (VfxS32 j = 0; j < menu->getMenuItemCountPerPage(); ++j)
        {
            VcpPageMenuCell * cell = menu->getMenuItem(i * menu->getMenuItemCountPerPage() + j);
            if (cell == NULL)
            {
                break;
            }
            m_appOrderData[orderIndex] = cell->getCellIndex();
            ++orderIndex;
        }
        m_appOrderData[orderIndex] = VCP_NORMAL_MODE_MENU_PAGE_BREAK;
        ++orderIndex;
    }

    // fill the remaining order data with VCP_NORMAL_MODE_MENU_PAGE_BREAK
    for (VfxS32 i = orderIndex; i < m_appOrderCount; ++i)
    {
        m_appOrderData[i] = VCP_NORMAL_MODE_MENU_PAGE_BREAK;
    }

    // checks
    checkCellState(menu);
}

VcpPageMenuCell * VcpNormalModeMenuBuilder::createCell(VfxS32 index, VfxResId imageID, const VfxWString &title, VcpNormalModeMenu * menu)
{
    // create the cell
    VcpPageMenuCell * cell;
    VFX_OBJ_CREATE_EX(cell, VappMmCell, menu, (imageID, title));
    cell->setCellIndex(index);
    cell->setSize(MAINMENU_CELL_VISIBLE_WIDTH, MAINMENU_CELL_VISIBLE_HEIGHT);

    return cell;
}

void VcpNormalModeMenuBuilder::checkCellState(VcpNormalModeMenu * menu)
{
    VfxS32 * cellCount = NULL;
    VFX_ALLOC_MEM(cellCount, sizeof(VfxS32) * m_allAppCount, this);

    for (VfxS32 i = 0; i < m_allAppCount; ++i)
    {
        cellCount[i] = 0;
    }

    // create cellMap data and clear cells data
    for (VfxS32 i = 0; i < VCP_NORMAL_MODE_MENU_MAX_APP; ++i)
    {
        if (menu->getMenuItem(i) == NULL)
        {
            continue;
        }
        if (menu->getMenuItem(i)->getCellIndex() >= m_allAppCount)
        {
            VFX_ASSERT(VFX_FALSE);
        }
        cellCount[menu->getMenuItem(i)->getCellIndex() ] += 1;
    }

    for (VfxS32 i = 0; i < m_allAppCount; ++i)
    {
        if (cellCount[i] != 1)
        {
            VFX_ASSERT(VFX_FALSE);
        }
    }

    VFX_FREE_MEM(cellCount);
}

#endif // __MMI_VUI_3D_MAINMENU__
