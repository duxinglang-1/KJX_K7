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
 *  vcp_page_grid.cpp
 *
 * Project:
 * --------
 *  Venus CP
 *
 * Description:
 * ------------
 *  Venus CP
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __COSMOS_MMI__

#include "vcp_page_grid.h"
#include "vcp_page_menu_util.h"
#include "mmi_rp_srv_venus_component_page_grid_def.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

//#define PAGEGRID_ENABLE_EXPAND_EFFECT

/*****************************************************************************
 * Global Variable
 *****************************************************************************/


// page grid layout constants
// cell layout

static const VfxS32 PAGEGRID_PAGE_ROW_COUNT_DEFAULT = 4;
static const VfxS32 PAGEGRID_PAGE_COLUMN_COUNT_DEFAULT = 4;

static const VfxS32 PAGEGRID_CELL_OFFSET_X_DEFAULT = 65+11;
static const VfxS32 PAGEGRID_CELL_OFFSET_Y_DEFAULT = 65+2+20+5;

static const VfxS32 PAGEGRID_PAGE_MARGIN_DEFAULT = 20;
static const VfxS32 PAGEGRID_CELL_X_START_DEFAULT = 9;
static const VfxS32 PAGEGRID_CELL_Y_START_DEFAULT = 11 + 25;

static const VfxS32 PAGEGRID_INDICATOR_OFFSET_Y_DEFAULT = 0;

// page grid user interaction constatnt
static const VfxS32 PAGEGRID_TRANSITIONING_THRESHOLD = 15;

static const VfxS32 PAGEGRID_LONG_SWIPE_THRESHOLD = 600;

static const VfxS32 PAGEGRID_HITTEST_NOT_FOUND = -1;
static const VfxS32 PAGEGRID_NO_HOVER = -1;

// page grid animation constatnt
static const VfxS32 PAGEGRID_ANIMTIME_INSTANT = 1;
static const VfxS32 PAGEGRID_ANIMTIME_RELEASE = 250;

static const VfxFloat PAGEGRID_EDITING_ALPHA = 0.5f;

// page indicator layout default
#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 PAGEGRID_INDICATOR_WIDTH = 480;
static const VfxS32 PAGEGRID_INDICATOR_HEIGHT = 26;
static const VfxS32 PAGEGRID_INDICATOR_BG_HEIGHT = 26;
static const VfxS32 PAGEGRID_INDICATOR_CELL_SPACING = 24;
static const VfxS32 PAGEGRID_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 PAGEGRID_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 PAGEGRID_SWIPE_RANGE_THRESHOLD = 60;
static const VfxS32 PAGEGRID_MIDIUM_SWIPE_RANGE_THRESHOLD = 200;
static const VfxS32 PAGEGRID_BIG_SWIPE_RANGE_THRESHOLD = 20000; // 20000 : disable big swipe

static const VfxS32 PAGEGRID_CANCEL_HOVER_THRESHOLD_X = 60;
static const VfxS32 PAGEGRID_CANCEL_HOVER_THRESHOLD_Y = 80;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 PAGEGRID_INDICATOR_WIDTH = 240;
static const VfxS32 PAGEGRID_INDICATOR_HEIGHT = 16;
static const VfxS32 PAGEGRID_INDICATOR_BG_HEIGHT = 16;
static const VfxS32 PAGEGRID_INDICATOR_CELL_SPACING = 12;
static const VfxS32 PAGEGRID_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 PAGEGRID_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 PAGEGRID_SWIPE_RANGE_THRESHOLD = 30;
static const VfxS32 PAGEGRID_MIDIUM_SWIPE_RANGE_THRESHOLD = 80;
static const VfxS32 PAGEGRID_BIG_SWIPE_RANGE_THRESHOLD = 20000; // 20000 : disable big swipe

static const VfxS32 PAGEGRID_CANCEL_HOVER_THRESHOLD_X = 20;
static const VfxS32 PAGEGRID_CANCEL_HOVER_THRESHOLD_Y = 30;

#else
static const VfxS32 PAGEGRID_INDICATOR_WIDTH = 320;
static const VfxS32 PAGEGRID_INDICATOR_HEIGHT = 20;
static const VfxS32 PAGEGRID_INDICATOR_BG_HEIGHT = 20;
static const VfxS32 PAGEGRID_INDICATOR_CELL_SPACING = 12;
static const VfxS32 PAGEGRID_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 PAGEGRID_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 PAGEGRID_SWIPE_RANGE_THRESHOLD = 30;
static const VfxS32 PAGEGRID_MIDIUM_SWIPE_RANGE_THRESHOLD = 100;
static const VfxS32 PAGEGRID_BIG_SWIPE_RANGE_THRESHOLD = 20000; // 20000 : disable big swipe

static const VfxS32 PAGEGRID_CANCEL_HOVER_THRESHOLD_X = 30;
static const VfxS32 PAGEGRID_CANCEL_HOVER_THRESHOLD_Y = 40;

#endif

VcpPageGridLayout::VcpPageGridLayout():
rowCount(PAGEGRID_PAGE_ROW_COUNT_DEFAULT),
columnCount(PAGEGRID_PAGE_COLUMN_COUNT_DEFAULT),
cellStartX(PAGEGRID_CELL_X_START_DEFAULT),
cellStartY(PAGEGRID_CELL_Y_START_DEFAULT),
cellOffsetX(PAGEGRID_CELL_OFFSET_X_DEFAULT),
cellOffsetY(PAGEGRID_CELL_OFFSET_Y_DEFAULT),
pageMargin(PAGEGRID_PAGE_MARGIN_DEFAULT),
pageIndicatorOffsetY(PAGEGRID_INDICATOR_OFFSET_Y_DEFAULT)
{
}

VcpPageGridCell::VcpPageGridCell()
{
}

void VcpPageGridCell::onInit()
{
    VfxFrame::onInit();
    setAutoAnimate(VFX_TRUE);
}

void VcpPageGridCell::onShowCell()
{
}


/*****************************************************************************
 * Class VcpPageGrid
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcpPageGrid", VcpPageGrid, VfxControl);

/*****************************************************************************
 * FUNCTION
 *  VcpPageGrid::VcpPageGrid
 * DESCRIPTION
 *  Constructor of VcpPageGrid class
 * PARAMETERS
 *
 * RETURNS
 *  *****************************************************************************/
VcpPageGrid::VcpPageGrid():
    m_itemCount(0),
    m_itemDataDirty(VFX_FALSE),
    m_pageCount(0),
    m_stableCurrentPageIndex(0),
    m_pageIndicator(NULL),
    m_translateX(0),
    m_extraGap(0),
    m_hover(PAGEGRID_NO_HOVER),
    m_startPen(VFX_FALSE),
    m_translateDuration(PAGEGRID_ANIMTIME_INSTANT),
    m_translateOrigX(0)
{

    for (VfxS32 i = 0; i < VCP_PAGEGRID_MAX_ITEM; ++i)
    {
        m_cells[i] = NULL;
    }
}

void VcpPageGrid::onInit()
{
    VfxControl::onInit();

    // initial the page indicator
    VFX_OBJ_CREATE(m_pageIndicator, VcpPageMenuIndicator, this);
    m_pageIndicator->setAnchor(0.5f, 0.0f);

    VcpPageMenuIndicatorLayout indicatorLayout;
    indicatorLayout.indicatorWidthBase = PAGEGRID_INDICATOR_WIDTH;
    indicatorLayout.indicatorWidthIncrement = 0;
    indicatorLayout.indicatorHeight = PAGEGRID_INDICATOR_HEIGHT;
    indicatorLayout.bgOffsetY = 0;
    indicatorLayout.bgHeight = PAGEGRID_INDICATOR_BG_HEIGHT;
    indicatorLayout.cellSpacing = PAGEGRID_INDICATOR_CELL_SPACING;
    indicatorLayout.cellOffsetX = PAGEGRID_INDICATOR_CELL_OFFSET_X;
    indicatorLayout.cellOffsetY = PAGEGRID_INDICATOR_CELL_OFFSET_Y;
    VfxImageSrc normalDot(VCP_IMG_PAGE_GRID_INDICATOR_DOT_N);
    indicatorLayout.cellWidth = normalDot.getSize().width;
    indicatorLayout.cellHeight = normalDot.getSize().height;
    VfxImageSrc highlightDot(VCP_IMG_PAGE_GRID_INDICATOR_DOT_H);
    indicatorLayout.cellHighlightWidth = highlightDot.getSize().width;
    indicatorLayout.cellHighlightHeight = highlightDot.getSize().height;
    m_pageIndicator->setBgImage(VfxImageSrc(VCP_IMG_PAGE_GRID_INDICATOR_BG) );
    m_pageIndicator->setCellImage(normalDot, highlightDot);
    m_pageIndicator->setLayout(indicatorLayout);

    m_pageIndicator->m_pageSelected.connect(this, &VcpPageGrid::onPageIndicatorSelected);

    registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);

    checkUpdate();
}

void VcpPageGrid::resetCells()
{
    for (VfxS32 i = 0; i < m_itemCount; ++i)
    {
        VFX_OBJ_CLOSE(m_cells[i]);
    }
    m_itemCount = 0;
    m_pageCount = 0;
}

void VcpPageGrid::appendCell(VcpPageGridCell * cell)
{
    if (cell == NULL)
    {
        return;
    }

    addChildFrame(cell);
    m_cells[m_itemCount] = cell;
    ++m_itemCount;
    m_pageCount = (m_itemCount + getPageItemCount() - 1 ) / getPageItemCount();
    m_itemDataDirty = VFX_TRUE;
    checkUpdate();

    cell->setSize(m_layout.cellOffsetX, m_layout.cellOffsetY);
    cell->onShowCell();
}

void VcpPageGrid::setLayout(const VcpPageGridLayout & layout)
{
    m_layout = layout;
    m_itemDataDirty = VFX_TRUE;
    checkUpdate();
}

VcpPageGridLayout VcpPageGrid::getLayout() const
{
    return m_layout;
}

void VcpPageGrid::setIndicatorLayout(const VcpPageMenuIndicatorLayout & indicatorLayout)
{
    m_pageIndicator->setLayout(indicatorLayout);
}

VcpPageMenuIndicatorLayout VcpPageGrid::getIndicatorLayout() const
{
    return m_pageIndicator->getLayout();
}

VfxS32 VcpPageGrid::getCurrentPageIndex() const
{
    return getNearestPage();
}

void VcpPageGrid::setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated)
{
    if (animated)
    {
        setTranslateDuration(PAGEGRID_ANIMTIME_RELEASE);
    }
    else
    {
        setTranslateDuration(PAGEGRID_ANIMTIME_INSTANT);
    }
    scrollToPage(pageIndex);
}

void VcpPageGrid::onUpdate()
{
    VfxControl::onUpdate();
    if (m_itemDataDirty)
    {
        m_pageIndicator->setPos(getSize().width / 2, m_layout.pageIndicatorOffsetY);
        m_itemDataDirty = VFX_FALSE;
    }

    VfxS32 currentPageIndex = getNearestPage();
    m_pageIndicator->setCurrentPage(currentPageIndex);
    VfxS32 indicatorPageCount = getPageCount();
    if (currentPageIndex + 1 > indicatorPageCount && currentPageIndex < getMaxPageCount() )
    {
        indicatorPageCount = currentPageIndex + 1;
    }
    m_pageIndicator->setIndicatorPageCount(indicatorPageCount);
    m_pageIndicator->update();
    updateTranslateX(getTranslateDuration() );

    updateCells();
}

VfxBool VcpPageGrid::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
        if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
        {
            if (getCurrentPageIndex() > 0)
            {
                setCurrentPageIndex(getCurrentPageIndex() - 1, VFX_TRUE);
                return VFX_TRUE;
            }
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
        {
            if (getCurrentPageIndex() < getPageCount() - 1)
            {
                setCurrentPageIndex(getCurrentPageIndex() + 1, VFX_TRUE);
                return VFX_TRUE;
            }
        }
    }
    return VFX_FALSE;
}

void VcpPageGrid::updateCells()
{
    for (VfxS32 i = 0; i < VCP_PAGEGRID_MAX_ITEM; ++i)
    {
        if (m_cells[i] == NULL)
        {
            continue;
        }

        VfxAutoAnimate::begin();

        // use ease out for all pos animation
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        updateCellPos(i);

        // no animation for alpha
        VfxAutoAnimate::setDisable(VFX_TRUE);
        updateCellAlpha(i);

        VfxAutoAnimate::commit();
    }
}

void VcpPageGrid::updateCellPos(VfxS32 index)
{
    VfxS32 x = index % m_layout.columnCount * m_layout.cellOffsetX + m_layout.cellStartX;

#ifdef PAGEGRID_ENABLE_EXPAND_EFFECT
    if (m_extraGap >= 0)
    {
        x += m_extraGap * (index % m_layout.columnCount);
    }
    else
    {
        x += m_extraGap * (m_layout.columnCount - 1 - (index % m_layout.columnCount) );
    }
#endif // PAGEGRID_ENABLE_EXPAND_EFFECT

    x += index / getPageItemCount() * (getSize().width + m_layout.pageMargin);
    VfxS32 y = (index % getPageItemCount() ) / m_layout.columnCount * m_layout.cellOffsetY + m_layout.cellStartY;
    setCellPos(m_cells[index], x + getTranslateX(), y);
}

void VcpPageGrid::updateCellAlpha(VfxS32 index)
{
    VfxFloat opacity;
    if (index == getHover() )
    {
        opacity = PAGEGRID_EDITING_ALPHA;
    }
    else
    {
        opacity = 1.0f;
    }

    m_cells[index]->setOpacity(opacity);
}

void VcpPageGrid::onPageIndicatorSelected(VfxS32 pageSelected)
{
    setTranslateDuration(PAGEGRID_ANIMTIME_RELEASE);
    scrollToPage(pageSelected);
}

VfxBool VcpPageGrid::onPenInput(VfxPenEvent &event)
{
    // default animation parameters
    setTranslateDuration(PAGEGRID_ANIMTIME_INSTANT);

#ifdef PAGEGRID_ENABLE_EXPAND_EFFECT
    m_extraGap = 0;
#endif

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return handlePenDown(event.getRelPos(this) );
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        // long tap is ignored, VcpPageGrid handle long tap behavior itself
    }
    else
    {
        return handleScroll(event);
    }

    return VfxControl::onPenInput(event);
}

VfxBool VcpPageGrid::handlePenDown(const VfxPoint &touchDownPos)
{
    setTranslateX(getCurrentTranslateX() );
    m_translateOrigX = getTranslateX();
    m_startPen = VFX_TRUE;
    if (!isTransitioning() )
    {
        setHover(cellHittest(touchDownPos, VFX_FALSE) );
        if (getHover() != PAGEGRID_NO_HOVER)
        {
            const VfxS32 hoverPosX = getCellPosX(m_cells[getHover() ] ) - getTranslateX();
            const VfxS32 hoverPosY = getCellPosY(m_cells[getHover() ] );
        }
    }
    checkUpdate();
    return VFX_TRUE;
}

VfxBool VcpPageGrid::handleScroll(const VfxPenEvent &event)
{
    const VfxPoint touchPos = event.getRelPos(this);
    const VfxPoint touchDownPos = event.getRelDownPos(this);
    const VfxS32 diffOrigX = touchPos.x - touchDownPos.x;
    const VfxS32 diffOrigY = touchPos.y - touchDownPos.y;

    if (event.type == VFX_PEN_EVENT_TYPE_ABORT ||
            VFX_ABS(diffOrigX) > PAGEGRID_CANCEL_HOVER_THRESHOLD_X ||
            VFX_ABS(diffOrigY) > PAGEGRID_CANCEL_HOVER_THRESHOLD_Y)
    {
        setHover(PAGEGRID_NO_HOVER);
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
        const VfxS32 elapse = PAGEGRID_LONG_SWIPE_THRESHOLD * 2;
        const VfxS32 diffX = 0;
        handleScrollEnd(diffX, elapse);
    }

    // limiting
    limitTranslateX();

    return VFX_TRUE;
}

void VcpPageGrid::handleScrollMove(VfxS32 diffOrigX, VfxS32 diffOrigY)
{
    if (!m_startPen)
    {
        // limit for modis
        if (diffOrigX > getSize().width)
        {
            setTranslateX(m_translateOrigX + getSize().width);
        }
        else if (diffOrigX < -getSize().width)
        {
            setTranslateX(m_translateOrigX - getSize().width);
        }
        else
        {
            setTranslateX(m_translateOrigX + diffOrigX);
        }

        // limiting
        if (getTranslateX() > 0)
        {
#ifdef PAGEGRID_ENABLE_EXPAND_EFFECT
            m_extraGap = getTranslateX() / (m_layout.columnCount - 1) / 4;
#endif
            setTranslateX(0);
        }
        const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
        if (getTranslateX() < -(getPageCount() - 1) * pageLevel)
        {
#ifdef PAGEGRID_ENABLE_EXPAND_EFFECT
            m_extraGap = (getTranslateX() - ( -(getPageCount() - 1) * pageLevel ) ) / (m_layout.columnCount - 1) / 4;
#endif
            setTranslateX(-(getPageCount() - 1) * pageLevel);
        }

        checkUpdate();
    }
}

void VcpPageGrid::handleScrollEnd(VfxS32 diffX, VfxMsec elapse)
{
    const VfxFloat speed = static_cast<VfxFloat>(diffX * 1000) / elapse;

    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;

    setTranslateDuration(PAGEGRID_ANIMTIME_RELEASE);

    if (m_startPen && !isTransitioning() )
    {
        // clicked
        if (getHover() != PAGEGRID_NO_HOVER)
        {
            m_itemClicked.postEmit(getHover() );
        }
    }
    else if (elapse < PAGEGRID_LONG_SWIPE_THRESHOLD)
    {
        handleScrollSwipe(diffX, speed);
    }
    else
    {
        // scroll to the nearest page
        scrollToPage(getNearestPage() );
    }

    setHover(PAGEGRID_NO_HOVER);

    checkUpdate();
}

void VcpPageGrid::handleScrollSwipe(VfxS32 diffX, VfxFloat speed)
{
    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
    if (diffX > PAGEGRID_SWIPE_RANGE_THRESHOLD)
    {
        if (diffX > PAGEGRID_BIG_SWIPE_RANGE_THRESHOLD && (getTranslateX() < -1.0f * pageLevel) )
        {
            scrollToPage(getPreviousPage() - 1);
            setTranslateDuration(PAGEGRID_ANIMTIME_RELEASE * 2);
        }
        else if (diffX > PAGEGRID_MIDIUM_SWIPE_RANGE_THRESHOLD)
        {
            scrollToPage(getPreviousPage() );
        }
        else
        {
            scrollToPage(getPreviousPage() );
            setTranslateDuration(PAGEGRID_ANIMTIME_RELEASE * 2);
        }
    }
    else if (diffX < -PAGEGRID_SWIPE_RANGE_THRESHOLD)
    {
        if (diffX < -PAGEGRID_BIG_SWIPE_RANGE_THRESHOLD && (getTranslateX() > ( -(getPageCount() - 2) * pageLevel) ) )
        {
            scrollToPage(getNextPage() + 1);
            setTranslateDuration(PAGEGRID_ANIMTIME_RELEASE * 2);
        }
        else if (diffX < -PAGEGRID_MIDIUM_SWIPE_RANGE_THRESHOLD)
        {
            scrollToPage(getNextPage() );
        }
        else
        {
            scrollToPage(getNextPage() );
            setTranslateDuration(PAGEGRID_ANIMTIME_RELEASE * 2);
        }
    }
    else
    {
        scrollToPage(getNearestPage() );
    }
}

void VcpPageGrid::scrollToPage(VfxS32 pageIndex)
{
    if (pageIndex < 0)
    {
        pageIndex = 0;
    }
    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
    setTranslateX(pageIndex * -pageLevel);
    checkUpdate();

    if (pageIndex != m_stableCurrentPageIndex)
    {
        m_stableCurrentPageIndex = pageIndex;
        m_pageChanged.postEmit(m_stableCurrentPageIndex);
    }
}

VfxS32 VcpPageGrid::getNearestPage() const
{
    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
    // use the center of the margin between 2 pages as the separation of pages
    const VfxS32 andHalf = getTranslateX() + getSize().width / 2 + m_layout.pageMargin / 4;
    if (andHalf > 0)
    {
        return -(andHalf / pageLevel);
    }
    else
    {
        return -( (andHalf - pageLevel + 1) / pageLevel);
    }
}

VfxS32 VcpPageGrid::getNextPage() const
{
    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
    const VfxS32 shift = getTranslateX() - 10;
    if (shift > 0)
    {
        return -( shift / pageLevel);
    }
    else
    {
        return -( (shift - pageLevel + 1) / pageLevel);
    }
}

VfxS32 VcpPageGrid::getPreviousPage() const
{
    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
    const VfxS32 shift = getTranslateX() + 10;
    if (shift > 0)
    {
        return -( (shift + pageLevel - 1) / pageLevel);
    }
    else
    {
        return -( shift / pageLevel);
    }
}

void VcpPageGrid::limitTranslateX()
{
    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
    if (getTranslateX() > 0)
    {
        scrollToPage(0);
    }
    if (getTranslateX() < -(getPageCount() - 1) * pageLevel)
    {
        scrollToPage(getPageCount() - 1);
    }
}

VfxBool VcpPageGrid::isTransitioning() const
{
    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
    const VfxS32 page = getNearestPage();
    const VfxS32 targetTranslateX = page * -pageLevel;
    const VfxS32 diffTranslateX = VFX_ABS(targetTranslateX - getTranslateX() );
    const VfxS32 diffCurrentTranslateX = VFX_ABS(targetTranslateX - getCurrentTranslateX() );
    if (diffTranslateX < PAGEGRID_TRANSITIONING_THRESHOLD && diffCurrentTranslateX < PAGEGRID_TRANSITIONING_THRESHOLD)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxS32 VcpPageGrid::getTranslateX() const
{
    return m_translateX;
}

void VcpPageGrid::setTranslateX(VfxS32 translateX)
{
    m_translateX = translateX;
}

VfxS32 VcpPageGrid::getHover() const
{
    return m_hover;
}

void VcpPageGrid::setHover(VfxS32 hover)
{
    m_hover = hover;
}

VfxS32 VcpPageGrid::getPageCount() const
{
    VFX_ASSERT(m_pageCount <= getMaxPageCount() );
    return m_pageCount;
}

VfxMsec VcpPageGrid::getTranslateDuration() const
{
    return m_translateDuration;
}

void VcpPageGrid::setTranslateDuration(VfxMsec translateDuration)
{
    m_translateDuration = translateDuration;
}

VfxS32 VcpPageGrid::getCurrentTranslateX() const
{
    if (m_itemCount > 0)
    {
        return m_cells[0]->forceGetPos().x - m_layout.cellStartX;
    }
    else
    {
        return 0;
    }
}

VfxS32 VcpPageGrid::getCellPosX(VcpPageGridCell * cell) const
{
    return cell->getPos().x;
}

VfxS32 VcpPageGrid::getCellPosY(VcpPageGridCell * cell) const
{
    return cell->getPos().y;
}

void VcpPageGrid::setCellPos(VcpPageGridCell * cell, VfxS32 posX, VfxS32 posY)
{
    cell->setPos(posX, posY);
}

VfxS32 VcpPageGrid::getPageItemCount() const
{
    return m_layout.rowCount * m_layout.columnCount;
}

VfxS32 VcpPageGrid::getMaxPageCount() const
{
    return (VCP_PAGEGRID_MAX_ITEM + getPageItemCount() - 1) / getPageItemCount();
}

void VcpPageGrid::updateTranslateX(VfxS32 duration)
{
}

VfxS32 VcpPageGrid::cellHittest(VfxPoint clickPoint, VfxBool findLast) const
{
    if (clickPoint.x < m_layout.cellStartX || clickPoint.x > m_layout.cellOffsetX * m_layout.columnCount + m_layout.cellStartX)
    {
        return PAGEGRID_HITTEST_NOT_FOUND;
    }
    if (clickPoint.y < m_layout.cellStartY || clickPoint.y > m_layout.cellOffsetY * m_layout.rowCount + m_layout.cellStartY)
    {
        return PAGEGRID_HITTEST_NOT_FOUND;
    }

    const VfxS32 x = (clickPoint.x - m_layout.cellStartX) / m_layout.cellOffsetX;
    const VfxS32 y = (clickPoint.y - m_layout.cellStartY ) / m_layout.cellOffsetY;

    // XXX : the following 4 lines are redundant checks
    if (x < 0 || x >= m_layout.columnCount)
    {
        return PAGEGRID_HITTEST_NOT_FOUND;
    }
    if (y < 0 || y >= m_layout.rowCount)
    {
        return PAGEGRID_HITTEST_NOT_FOUND;
    }

    const VfxS32 pageLevel = getSize().width + m_layout.pageMargin;
    const VfxS32 panelIndex = -1 * ( (getTranslateX() - pageLevel / 2) / pageLevel );
    const VfxS32 index = x + m_layout.columnCount * y + getPageItemCount() * panelIndex;

    if (index < 0 || index >= VCP_PAGEGRID_MAX_ITEM)
    {
        return PAGEGRID_HITTEST_NOT_FOUND;
    }

    if (m_cells[index] != NULL)
    {
        return index;
    }
    else if (findLast)
    {
        // if the clicked cell is NULL,
        // decrease the index and find non-NULL cell
        const VfxS32 firstInPanel = index / getPageItemCount() * getPageItemCount();
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
    return PAGEGRID_HITTEST_NOT_FOUND;
}

#endif // __COSMOS_MMI__
