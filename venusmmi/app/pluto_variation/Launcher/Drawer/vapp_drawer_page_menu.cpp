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
 *  vapp_drawer_page_menu.cpp
 *
 * Project:
 * --------
 *  Launcher
 *
 * Description:
 * ------------
 *  Launcher drawer
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"

#include "vfx_uc_include.h"
#include "vfx_adp_device.h"
#include "vapp_drawer_page_menu.h"
#include "vapp_drawer_builder.h"
#include "vcp_page_menu_util.h"
#include "vcp_page_menu_transition.h"
#include "mmi_rp_vapp_drawer_def.h"
#include "Wgui.h" // for MMI_STATUS_BAR_HEIGHT

extern "C" {
#include "AppMgrSrvGprot.h"
}

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/*****************************************************************************
 * Define
 *****************************************************************************/

//#define DRAWER_PAGE_LEFT_EXTENDABLE
//#define DRAWER_FPS_TEST

/*****************************************************************************
 * Global Variable
 *****************************************************************************/


// mainmenu user interaction constatnt
static const VfxS32 DRAWER_LONG_SWIPE_THRESHOLD = 600;

static const VfxS32 DRAWER_BIG_SWIPE_SPEED_THRESHOLD = 1000;
// to avoid global class with constructor
#define DRAWER_NO_HOVER VcpPageMenuCellPos(-1, -1)

// mainmenu animation constatnt
#ifdef DRAWER_FPS_TEST
static const VfxS32 DRAWER_ANIMTIME_INSTANT = 200;
static const VfxS32 DRAWER_ANIMTIME_RELEASE = 5000;
static const VfxS32 DRAWER_ORGANIZE_DURATION = 2000;
#else
static const VfxS32 DRAWER_ANIMTIME_INSTANT = 1;
static const VfxS32 DRAWER_ANIMTIME_RELEASE = 250;
static const VfxS32 DRAWER_ORGANIZE_DURATION = 250;
#endif
static const VfxS32 DRAWER_ANIMTIME_INSTANT_3 = 3;

static const VfxS32 DRAWER_PEN_DOWN_DELAY = 200;
static const VfxS32 DRAWER_LONG_PRESS_ENTER_ORGANIZE_DELAY = 1000;
static const VfxS32 DRAWER_LONG_PRESS_ORGANIZE_ANOTHER_DELAY = 300;
static const VfxS32 DRAWER_ORGANIZE_AUTO_SCROLL_CD = 2000;
static const VfxS32 DRAWER_ORGANIZE_AUTO_SCROLL_MARGIN = 30;

static const VfxS32 DRAWER_LOAD_CELL_DELAY = 200;

//static const VfxFloat DRAWER_ROTATION_LIMIT = 15.0f;

//static const VfxFloat DRAWER_BOUND_ROTATE_FACTOR = -0.09f;

static const VfxFloat DRAWER_EDITING_ALPHA = 0.5f;

static const VfxS32 DRAWER_INDICATOR_OFFSET_Y = MMI_STATUS_BAR_HEIGHT;

static const VfxFloat MAINMENU_DRAGGING_SCALE = 0.8f;

// page indicator layout constants
#if defined(__MMI_MAINLCD_480X800__)

static const VfxS32 DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT = 3;

static const VfxS32 DRAWER_INDICATOR_WIDTH = 480;
static const VfxS32 DRAWER_INDICATOR_HEIGHT = 26;
static const VfxS32 DRAWER_INDICATOR_BG_HEIGHT = 26;
static const VfxS32 DRAWER_INDICATOR_CELL_SPACING = 24;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 DRAWER_SWIPE_RANGE_THRESHOLD = 60;
static const VfxS32 DRAWER_MIDIUM_SWIPE_RANGE_THRESHOLD = 200;
static const VfxS32 DRAWER_BIG_SWIPE_RANGE_THRESHOLD = 20000; // 20000 : disable big swipe

static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_X = 5;
static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_Y = 80;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

static const VfxS32 DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT = 2;

static const VfxS32 DRAWER_INDICATOR_WIDTH = 240;
static const VfxS32 DRAWER_INDICATOR_HEIGHT = 16;
static const VfxS32 DRAWER_INDICATOR_BG_HEIGHT = 16;
static const VfxS32 DRAWER_INDICATOR_CELL_SPACING = 12;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 DRAWER_SWIPE_RANGE_THRESHOLD = 30;
static const VfxS32 DRAWER_MIDIUM_SWIPE_RANGE_THRESHOLD = 80;
static const VfxS32 DRAWER_BIG_SWIPE_RANGE_THRESHOLD = 20000; // 20000 : disable big swipe

static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_X = 5;
static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_Y = 30;

#else

static const VfxS32 DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT = 3;

static const VfxS32 DRAWER_INDICATOR_WIDTH = 320;
static const VfxS32 DRAWER_INDICATOR_HEIGHT = 20;
static const VfxS32 DRAWER_INDICATOR_BG_HEIGHT = 20;
static const VfxS32 DRAWER_INDICATOR_CELL_SPACING = 12;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 DRAWER_SWIPE_RANGE_THRESHOLD = 30;
static const VfxS32 DRAWER_MIDIUM_SWIPE_RANGE_THRESHOLD = 100;
static const VfxS32 DRAWER_BIG_SWIPE_RANGE_THRESHOLD = 20000; // 20000 : disable big swipe

static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_X = 5;
static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_Y = 40;

#endif


class VcpDrawerPageMenuView : public VcpPageMenuView
{
protected:
    virtual void updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos);
};


void VcpDrawerPageMenuView::updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos)
{
    VfxFloat opacity;
    if ((pos == getHover() && getOrganizeMode() == VFX_FALSE) ||
        cell == getDraggingFrame())
    {
        opacity = DRAWER_EDITING_ALPHA;
    }
    else
    {
        opacity = 1.0f;
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    cell->setOpacity(opacity);
    VfxAutoAnimate::commit();

    VappDrawerCell * mmCell = static_cast<VappDrawerCell*>(cell);
    if (mmCell == NULL)
    {
        return;
    }
    mmCell->setEditMode(getOrganizeMode() );
}

/*****************************************************************************
 * Class VappDrawerPageMenu
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDrawerPageMenu", VappDrawerPageMenu, VfxControl);

/*****************************************************************************
 * FUNCTION
 *  VappDrawerPageMenu::VappDrawerPageMenu
 * DESCRIPTION
 *  Constructor of VappDrawerPageMenu class
 * PARAMETERS
 *
 * RETURNS
 *  *****************************************************************************/
VappDrawerPageMenu::VappDrawerPageMenu():
    m_pageCount(0),
    m_stableCurrentPageIndex(0),
    m_menuView(NULL),
    m_holdFrame(NULL),
    m_pageIndicator(NULL),
    m_delayPenDownTimer(NULL),
    m_longPressTimer(NULL),
    m_delayMovingTimer(NULL),
    m_delayLoadCellTimer(NULL),
    m_hover(DRAWER_NO_HOVER),
    m_startPen(VFX_FALSE),
    m_canScroll(VFX_FALSE),
    m_translateOrigX(0),
    m_showMenuItems(VFX_FALSE),
    m_enableMenuAnim(VFX_TRUE),
    m_updateCount(0),
    m_organizeMode(VFX_FALSE),
    m_organizeTo(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_delayPenDownCellPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_delayMovingTo(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_lastAutoScrollTime(0),
    m_leftExtended(VFX_FALSE),
    m_rightExtended(VFX_FALSE)
{
    for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_APP; ++i)
    {
        m_cells[i] = NULL;
    }

    for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_GROUP_APP; ++i)
    {
        m_groupCells[i] = NULL;
    }
}

void VappDrawerPageMenu::onInit()
{
    VfxControl::onInit();

    vcpPageMenuApplyFrameRenderHints(this);
    
    VFX_OBJ_CREATE(m_menuView, VcpDrawerPageMenuView, this);
    m_menuView->setClipMargin(0);

    VFX_OBJ_CREATE(m_pageIndicator, VcpPageMenuIndicator, this);
    m_pageIndicator->setAnchor(0.5f, 0.0f);

    // initial the page indicator
    VcpPageMenuIndicatorLayout indicatorLayout;
    indicatorLayout.indicatorWidthBase = DRAWER_INDICATOR_WIDTH;
    indicatorLayout.indicatorWidthIncrement = 0;
    indicatorLayout.indicatorHeight = DRAWER_INDICATOR_HEIGHT;
    indicatorLayout.bgOffsetY = 0;
    indicatorLayout.bgHeight = DRAWER_INDICATOR_BG_HEIGHT;
    indicatorLayout.cellSpacing = DRAWER_INDICATOR_CELL_SPACING;
    indicatorLayout.cellOffsetX = DRAWER_INDICATOR_CELL_OFFSET_X;
    indicatorLayout.cellOffsetY = DRAWER_INDICATOR_CELL_OFFSET_Y;
    VfxImageSrc normalDot(IMG_ID_VAPP_DRAWER_INDICATOR_DOT_N);
    indicatorLayout.cellWidth = normalDot.getSize().width;
    indicatorLayout.cellHeight = normalDot.getSize().height;
    VfxImageSrc highlightDot(IMG_ID_VAPP_DRAWER_INDICATOR_DOT_H);
    indicatorLayout.cellHighlightWidth = highlightDot.getSize().width;
    indicatorLayout.cellHighlightHeight = highlightDot.getSize().height;
    m_pageIndicator->setCellImage(normalDot, highlightDot);
    m_pageIndicator->setLayout(indicatorLayout);

    updatePageIndicatorPos();
    m_pageIndicator->m_pageSelected.connect(this, &VappDrawerPageMenu::onPageIndicatorSelected);

    VFX_OBJ_CREATE(m_delayPenDownTimer, VfxTimer, this);
    m_delayPenDownTimer->m_signalTick.connect(this, &VappDrawerPageMenu::onDelayPenDownTimerTick);

    VFX_OBJ_CREATE(m_longPressTimer, VfxTimer, this);
    m_longPressTimer->m_signalTick.connect(this, &VappDrawerPageMenu::onLongPressTimerTick);

    VFX_OBJ_CREATE(m_delayMovingTimer, VfxTimer, this);
    m_delayMovingTimer->m_signalTick.connect(this, &VappDrawerPageMenu::onDelayMovingTimerTick);

    VFX_OBJ_CREATE(m_delayLoadCellTimer, VfxTimer, this);
    m_delayLoadCellTimer->m_signalTick.connect(this, &VappDrawerPageMenu::onDelayLoadCellTimerTick);
    m_delayLoadCellTimer->setStartDelay(DRAWER_LOAD_CELL_DELAY);
    m_delayLoadCellTimer->start();

    registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);
    
    checkUpdate();
}

void VappDrawerPageMenu::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    m_menuView->setSize(value.size.width, value.size.height );

    updatePageIndicatorPos();
}

void VappDrawerPageMenu::setMenuItem(VfxS32 index, VcpPageMenuCell * cell)
{
    if (m_cells[index] != NULL)
    {
        m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
    }

    m_cells[index] = cell;
    if (cell == NULL)
    {
        return;
    }

    cell->setAutoAnimate(VFX_TRUE);
    if (m_updateCount > 0)
    {
        cell->setCacheMode(VFX_CACHE_MODE_FORCE);
    }

    vcpPageMenuApplyFrameRenderHints(cell);
    
    m_menuView->initCellAnim(cell, VCP_PAGE_MENU_GROUP_MAIN);

    checkUpdate();
}

void VappDrawerPageMenu::clearAllMenuItems()
{
    for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_APP; ++i)
    {
        if (m_cells[i])
        {
            VFX_OBJ_CLOSE(m_cells[i]);
        }
    }
    for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_GROUP_APP; ++i)
    {
        if (m_groupCells[i])
        {
            VFX_OBJ_CLOSE(m_groupCells[i]);
        }
    }
}

VcpPageMenuCell * VappDrawerPageMenu::getGroupMenuItem(VfxS32 index) const
{
    return m_groupCells[index];
}

void VappDrawerPageMenu::setGroupMenuItem(VfxS32 index, VcpPageMenuCell * cell)
{
    m_groupCells[index] = cell;
    if (cell == NULL)
    {
        return;
    }

    cell->setAutoAnimate(VFX_TRUE);
    if (m_updateCount > 0)
    {
        cell->setCacheMode(VFX_CACHE_MODE_FORCE);
    }

    vcpPageMenuApplyFrameRenderHints(cell);
    
    m_menuView->initCellAnim(cell, VCP_PAGE_MENU_GROUP_BOTTOM_BAR);

    checkUpdate();
}

void VappDrawerPageMenu::setCellIconSize(const VfxSize & size)
{
    m_menuView->setCellIconSize(size);
}

VcpPageMenuCell * VappDrawerPageMenu::getMenuItem(VfxS32 index) const
{
    return m_cells[index];
}

VfxS32 VappDrawerPageMenu::getMaxPageCount() const
{
    return m_menuView->getMaxPageCount(VAPP_DRAWER_MAX_APP);
}

VfxS32 VappDrawerPageMenu::getMenuItemCountPerPage() const
{
    return m_menuView->getPageItemCount();
}

VfxS32 VappDrawerPageMenu::getMenuItemCountPerGroup() const
{
    return 16;
}

void VappDrawerPageMenu::compactPages(VfxBool isCheckUpdate)
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

    scrollToPage(pageIndexAfterCompact, DRAWER_ORGANIZE_DURATION, isCheckUpdate);
    setPageCount(nonemptyPageCount, isCheckUpdate);
}

VfxS32 VappDrawerPageMenu::getCurrentPageIndex() const
{
    return m_menuView->getNearestPage();
}

void VappDrawerPageMenu::setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated)
{
    if (animated)
    {
        scrollToPage(pageIndex, DRAWER_ANIMTIME_RELEASE);
    }
    else
    {
        scrollToPage(pageIndex, DRAWER_ANIMTIME_INSTANT);
    }
}

const VcpPageMenuLayout & VappDrawerPageMenu::getMenuLayout() const
{
    return m_menuView->getLayout();
}

void VappDrawerPageMenu::setMenuLayout(const VcpPageMenuLayout & layout)
{
    m_menuView->setLayout(layout);
    updatePageIndicatorPos();
}

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
void VappDrawerPageMenu::setTransitionEffect(VcpPageMenuTransitionType transitionType)
{
    m_menuView->setTransitionEffect(transitionType);
    if (transitionType == VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL)
    {
        setIsZSortChild(VFX_FALSE);
    }
    else
    {
        setIsZSortChild(VFX_TRUE);
    }
}
#endif

void VappDrawerPageMenu::leaveOrganizationMode(VfxBool isCheckUpdate)
{
    if (!getOrganizeMode() )
    {
        return;
    }

    handleOrganizeEnd(isCheckUpdate);

    // set organized state
    setOrganizeMode(VFX_FALSE);
    m_organizationChanged.postEmit(VFX_FALSE);
}

void VappDrawerPageMenu::enterOrganizationMode()
{
    setOrganizeMode(VFX_TRUE);
}

void VappDrawerPageMenu::forceDirty()
{
    m_menuView->forceDirty();
    checkUpdate();
}

void VappDrawerPageMenu::showMenuItems()
{
    if (!m_showMenuItems)
    {
        m_showMenuItems = VFX_TRUE;
        checkUpdate();
    }
}

void VappDrawerPageMenu::setEnableMenuAnim(VfxBool enable)
{
    if (m_enableMenuAnim != enable)
    {
        m_enableMenuAnim = enable;
        if (m_enableMenuAnim)
        {
            checkUpdate();
        }
    }
}

void VappDrawerPageMenu::onUpdate()
{
    VfxControl::onUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOU", SA_start);
#endif

    if (m_enableMenuAnim == VFX_TRUE)
    {
        if (m_menuView->getNearestPage() > getPageCount() - 1)
        {
            scrollToPage(getPageCount() - 1, DRAWER_ANIMTIME_INSTANT);
        }

        const VfxS32 currentPageIndex = m_menuView->getNearestPage();
        m_pageIndicator->setCurrentPage(currentPageIndex);
        VfxS32 indicatorPageCount = getPageCount();
        if (currentPageIndex + 1 > indicatorPageCount && currentPageIndex < m_menuView->getMaxPageCount(VAPP_DRAWER_MAX_APP) )
        {
            indicatorPageCount = currentPageIndex + 1;
        }
        m_pageIndicator->setIndicatorPageCount(indicatorPageCount);
        m_pageIndicator->update();


        ++m_updateCount;
        if (m_updateCount == 2)
        {
            // set force cache on the 2nd time onUpdate()
            for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_APP; ++i)
            {
                if (m_cells[i] != NULL)
                {
                    m_cells[i]->setCacheMode(VFX_CACHE_MODE_FORCE);
                }
            }
            for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_GROUP_APP; ++i)
            {
                if (m_groupCells[i] != NULL)
                {
                    m_groupCells[i]->setCacheMode(VFX_CACHE_MODE_FORCE);
                }
            }
        }

        if (m_showMenuItems)
        {
            m_menuView->update(m_cells, VAPP_DRAWER_MAX_APP, m_groupCells, VAPP_DRAWER_MAX_GROUP_APP);
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOU", SA_stop);
#endif
}

void VappDrawerPageMenu::onDelayPenDownTimerTick(VfxTimer *source)
{
    setHover(m_delayPenDownCellPos);
    checkUpdate();
}

void VappDrawerPageMenu::onLongPressTimerTick(VfxTimer *source)
{
    if (getHover().index == MAINMENU_HITTEST_NOT_FOUND)
    {
        return;
    }

    if (getOrganizeMode() )
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
        
        m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
        handleOrganizeStart();
        checkUpdate();
    }
    else
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
        
        setOrganizeMode(VFX_TRUE);
        m_organizationChanged.postEmit(VFX_TRUE);
        m_startPen = VFX_FALSE;

        handleOrganizeStart();

        m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
    }
}

void VappDrawerPageMenu::onDelayMovingTimerTick(VfxTimer *source)
{
    inPageOrganizeMove(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
}

void VappDrawerPageMenu::onDelayLoadCellTimerTick(VfxTimer *source)
{
    VfxS32 prevPageStartIndex = (getCurrentPageIndex() - 1) * getMenuItemCountPerPage();
    VfxBool needCachePrevPage = VFX_TRUE;
    if (getCurrentPageIndex() == 0 ||
        m_cells[prevPageStartIndex] == NULL ||
        static_cast<VappDrawerCell*>(m_cells[prevPageStartIndex])->isFirstDisplay() == VFX_FALSE)
    {
        needCachePrevPage = VFX_FALSE;
    }
    
    VfxS32 nextPageStartIndex = (getCurrentPageIndex() + 1) * getMenuItemCountPerPage();
    VfxBool needCacheNextPage = VFX_TRUE;
    if (getCurrentPageIndex() == (getMaxPageCount() - 1) ||
        m_cells[nextPageStartIndex] == NULL ||
        static_cast<VappDrawerCell*>(m_cells[nextPageStartIndex])->isFirstDisplay() == VFX_FALSE)
    {
        needCacheNextPage = VFX_FALSE;
    }
    
    for (VfxS32 i = 0; i < getMenuItemCountPerPage(); ++i)
    {
        VfxS32 cellIndex;

        cellIndex = prevPageStartIndex + i;
        if (needCachePrevPage && m_cells[cellIndex])
        {
            m_cells[cellIndex]->onCellDisplay();
            
            // Start timeline in order to cache cell which is outside the screen
            VfxFloatTimeline *opacityTl;
            VFX_OBJ_CREATE(opacityTl, VfxFloatTimeline, this);
            opacityTl->setTarget(m_cells[cellIndex]);
            opacityTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
            opacityTl->setDurationTime(DRAWER_ANIMTIME_INSTANT_3);
            opacityTl->setFromValue(0.99f);
            opacityTl->setToValue(1.0f);
            opacityTl->m_signalStopped.connect(this, &VappDrawerPageMenu::onTimelineStop);
            opacityTl->start();
        }
        
        cellIndex = nextPageStartIndex + i;
        if (needCacheNextPage && m_cells[cellIndex])
        {
            m_cells[cellIndex]->onCellDisplay();
            
            // Start timeline in order to cache cell which is outside the screen
            VfxFloatTimeline *opacityTl;
            VFX_OBJ_CREATE(opacityTl, VfxFloatTimeline, this);
            opacityTl->setTarget(m_cells[cellIndex]);
            opacityTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
            opacityTl->setDurationTime(DRAWER_ANIMTIME_INSTANT_3);
            opacityTl->setFromValue(0.99f);
            opacityTl->setToValue(1.0f);
            opacityTl->m_signalStopped.connect(this, &VappDrawerPageMenu::onTimelineStop);
            opacityTl->start();
        }
    }
}

void VappDrawerPageMenu::onPageIndicatorSelected(VfxS32 pageSelected)
{
    scrollToPage(pageSelected, DRAWER_ANIMTIME_RELEASE);
}

void VappDrawerPageMenu::onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    VFX_OBJ_CLOSE(timeline);
}

VfxBool VappDrawerPageMenu::onPenInput(VfxPenEvent &event)
{
    // default animation parameters
    m_menuView->setDragOnIndicator(VFX_FALSE);

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return handlePenDown(event.getRelPos(this) );
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        // long tap is ignored, VappDrawerPageMenu handle long tap behavior itself
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

VfxBool VappDrawerPageMenu::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT &&
        (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (m_stableCurrentPageIndex > 0)
        {
            scrollToPage(m_stableCurrentPageIndex - 1, DRAWER_ANIMTIME_RELEASE);
        }
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT &&
             (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (m_stableCurrentPageIndex < (m_pageCount - 1))
        {
            scrollToPage(m_stableCurrentPageIndex + 1, DRAWER_ANIMTIME_RELEASE);
        }
        return VFX_TRUE;
    }
    
    return VfxControl::onKeyInput(event);
}

VfxBool VappDrawerPageMenu::handlePenDown(const VfxPoint &touchDownPos)
{
    // to stop translate anim
    m_menuView->syncTranslateX();

    m_translateOrigX = m_menuView->getTranslateX();
    m_startPen = VFX_TRUE;
    const VcpPageMenuCellPos pos = cellHittest(touchDownPos, VFX_FALSE);

    if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        m_canScroll = VFX_FALSE;
    }
    else
    {
        m_canScroll = VFX_TRUE;
    }

    if (!m_menuView->isTransitioning() )
    {
        m_delayPenDownCellPos.group = pos.group;
        m_delayPenDownCellPos.index = pos.index;
        m_delayPenDownTimer->setStartDelay(DRAWER_PEN_DOWN_DELAY);
        m_delayPenDownTimer->start();
        
        if (m_delayPenDownCellPos.index != MAINMENU_HITTEST_NOT_FOUND)
        {
            m_delayMovingTouchPos.x = touchDownPos.x;
            m_delayMovingTouchPos.y = touchDownPos.y;
            
            m_menuView->initDraggingFramePos(getCell(m_delayPenDownCellPos), m_delayPenDownCellPos.group, touchDownPos.x, touchDownPos.y);
            m_menuView->setClickFrame(getCell(pos) );

            if (getOrganizeMode() )
            {
                if (m_delayPenDownCellPos.group != VCP_PAGE_MENU_GROUP_BOTTOM_BAR ||
                        m_delayPenDownCellPos.index < DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)
                {
                    m_longPressTimer->setStartDelay(DRAWER_LONG_PRESS_ORGANIZE_ANOTHER_DELAY);
                    m_longPressTimer->start();
                }
            }
            else
            {
                m_longPressTimer->setStartDelay(DRAWER_LONG_PRESS_ENTER_ORGANIZE_DELAY);
                m_longPressTimer->start();
            }
        }
    }
    checkUpdate();
    return VFX_TRUE;
}

VfxBool VappDrawerPageMenu::handleScroll(const VfxPenEvent &event)
{
    m_delayPenDownTimer->stop();
    
    const VfxPoint touchPos = event.getRelPos(this);
    const VfxPoint touchDownPos = event.getRelDownPos(this);
    const VfxS32 diffOrigX = touchPos.x - touchDownPos.x;
    const VfxS32 diffOrigY = touchPos.y - touchDownPos.y;

    if (event.type == VFX_PEN_EVENT_TYPE_ABORT ||
            VFX_ABS(diffOrigX) > DRAWER_CANCEL_HOVER_THRESHOLD_X ||
            VFX_ABS(diffOrigY) > DRAWER_CANCEL_HOVER_THRESHOLD_Y)
    {
        m_longPressTimer->stop();
        setHover(DRAWER_NO_HOVER);
        m_menuView->setClickFrame(NULL);
        if (m_startPen)
        {
            m_startPen = VFX_FALSE;
        }
        checkUpdate();
    }

    if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (m_canScroll && !m_startPen)
        {
            handleScrollMove(diffOrigX, diffOrigY);
        }
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        const VfxS32 elapse = event.timeStamp - event.downTimeStamp;
        handleScrollEnd(diffOrigX, elapse);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        const VfxS32 elapse = DRAWER_LONG_SWIPE_THRESHOLD * 2;
        const VfxS32 diffX = 0;
        handleScrollEnd(diffX, elapse);
    }

    return VFX_TRUE;
}

void VappDrawerPageMenu::handleScrollMove(VfxS32 diffOrigX, VfxS32 diffOrigY)
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
//            const VfxFloat rotateAngle = (translateX - 0) * DRAWER_BOUND_ROTATE_FACTOR;
//            m_menuView->setRotateAngle(rotateAngle , DRAWER_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = 0;
        }
        if (translateX < m_menuView->getPageTranslateX(getPageCount() - 1) )
        {
//            const VfxFloat rotateAngle = (translateX -
//                        ( m_menuView->getPageTranslateX(getPageCount() - 1) ) ) *
//                        DRAWER_BOUND_ROTATE_FACTOR;
//            m_menuView->setRotateAngle(rotateAngle , DRAWER_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = m_menuView->getPageTranslateX(getPageCount() - 1);
        }
        m_menuView->setTranslateX(translateX, DRAWER_ANIMTIME_INSTANT);

    #if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
        if (diffOrigX < 0)
        {
            m_menuView->setTransitionDirection(1);
        }
        else if (diffOrigX > 0)
        {
            m_menuView->setTransitionDirection(-1);
        }
    #endif
        
        checkUpdate();
    }
}

void VappDrawerPageMenu::handleScrollEnd(VfxS32 diffX, VfxMsec elapse)
{
    const VfxFloat speed = static_cast<VfxFloat>(diffX * 1000) / elapse;

//    m_menuView->setRotateAngle(0, DRAWER_ANIMTIME_RELEASE, VFX_TRUE);

    if (m_startPen && !m_menuView->isTransitioning() && !getOrganizeMode() )
    {
        // clicked
        if (m_delayPenDownCellPos.index != MAINMENU_HITTEST_NOT_FOUND)
        {
            m_enableMenuAnim = VFX_FALSE;
            m_appClicked.postEmit(getCell(m_delayPenDownCellPos) );
            
            m_menuView->setClickFrame(getCell(m_delayPenDownCellPos));
            return;
        }
    }
    else if (elapse < DRAWER_LONG_SWIPE_THRESHOLD)
    {
        if (m_canScroll)
        {
            handleScrollSwipe(diffX, speed);
        }
        else
        {
            scrollToPage(m_menuView->getNearestPage(), DRAWER_ANIMTIME_RELEASE);
        }
    }
    else
    {
        // scroll to the nearest page
        scrollToPage(m_menuView->getNearestPage(), DRAWER_ANIMTIME_RELEASE);
    }

    setHover(DRAWER_NO_HOVER);
    m_menuView->setClickFrame(NULL);

    // limiting
    if (m_menuView->getTranslateX() > 0)
    {
        scrollToPage(0, DRAWER_ANIMTIME_RELEASE);
    }
    if (m_menuView->getTranslateX() < m_menuView->getPageTranslateX(getPageCount() - 1) )
    {
        scrollToPage(getPageCount() - 1, DRAWER_ANIMTIME_RELEASE);
    }

    checkUpdate();
}

void VappDrawerPageMenu::handleScrollSwipe(VfxS32 diffX, VfxFloat speed)
{
    if (diffX > DRAWER_SWIPE_RANGE_THRESHOLD)
    {
        if (diffX > DRAWER_BIG_SWIPE_RANGE_THRESHOLD &&
                speed > DRAWER_BIG_SWIPE_SPEED_THRESHOLD &&
                (m_menuView->getTranslateX() < m_menuView->getPageTranslateX(1) ) )
        {
            scrollToPage(m_menuView->getPreviousPage() - 1, DRAWER_ANIMTIME_RELEASE * 2);
//            m_menuView->setRotateAngle(DRAWER_ROTATION_LIMIT, DRAWER_ANIMTIME_RELEASE * 3, VFX_TRUE);
        }
        else if (diffX > DRAWER_MIDIUM_SWIPE_RANGE_THRESHOLD)
        {
            scrollToPage(m_menuView->getPreviousPage(), DRAWER_ANIMTIME_RELEASE);
        }
        else
        {
            scrollToPage(m_menuView->getPreviousPage(), DRAWER_ANIMTIME_RELEASE);
        }
    }
    else if (diffX < -DRAWER_SWIPE_RANGE_THRESHOLD)
    {
        if (diffX < -DRAWER_BIG_SWIPE_RANGE_THRESHOLD &&
                speed < -DRAWER_BIG_SWIPE_SPEED_THRESHOLD &&
                (m_menuView->getTranslateX() > ( m_menuView->getPageTranslateX(getPageCount() - 2) ) ) )
        {
            scrollToPage(m_menuView->getNextPage() + 1, DRAWER_ANIMTIME_RELEASE * 2);
//            m_menuView->setRotateAngle(-DRAWER_ROTATION_LIMIT, DRAWER_ANIMTIME_RELEASE * 3, VFX_TRUE);
        }
        else if (diffX < -DRAWER_MIDIUM_SWIPE_RANGE_THRESHOLD)
        {
            scrollToPage(m_menuView->getNextPage(), DRAWER_ANIMTIME_RELEASE);
        }
        else
        {
            scrollToPage(m_menuView->getNextPage(), DRAWER_ANIMTIME_RELEASE);
        }
    }
    else
    {
        scrollToPage(m_menuView->getNearestPage(), DRAWER_ANIMTIME_RELEASE);
    }
}

VfxBool VappDrawerPageMenu::handleOrganize(VfxPenEventTypeEnum touchType, const VfxPoint &touchPos)
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

void VappDrawerPageMenu::handleOrganizeStart()
{
    if (getHover().group != VCP_PAGE_MENU_GROUP_BOTTOM_BAR ||
            getHover().index < DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)
    {
        setOrganizeTo(getHover() );
        m_menuView->setDraggingFrame(getCell(getHover() ) );
        m_delayMovingTo = getHover();
        
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        VfxTransform trans;
        trans.init(VRT_TRANSFORM_TYPE_AFFINE);
        trans.data.affine.sx = MAINMENU_DRAGGING_SCALE;
        trans.data.affine.sy = MAINMENU_DRAGGING_SCALE;
        getCell(getHover())->setTransform(trans);

        VfxAutoAnimate::commit();

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_DAMPING_OUT);

        getCell(getHover())->setTransform(VFX_TRANSFORM_IDENTITY);

        VfxAutoAnimate::commit();
        
        m_menuView->setDraggingFramePos(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
    }
    else
    {
        setHover(DRAWER_NO_HOVER);
        setOrganizeTo(DRAWER_NO_HOVER);
        m_menuView->setDraggingFrame(NULL);
    }

    scrollToPage(m_menuView->getNearestPage(), DRAWER_ANIMTIME_INSTANT);
//    m_menuView->setRotateAngle(0, DRAWER_ANIMTIME_INSTANT, VFX_TRUE);

    checkUpdate();
}

void VappDrawerPageMenu::handleOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    VfxBool crossPageMove = VFX_FALSE;
    const VfxMsec ctime = vrt_sys_get_time();
    if (ctime - m_lastAutoScrollTime > DRAWER_ORGANIZE_AUTO_SCROLL_CD)
    {
        if (touchX < DRAWER_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if (currentPage == 0)
            {
#ifdef DRAWER_PAGE_LEFT_EXTENDABLE
                if (getPageCount() < m_menuView->getMaxPageCount(VAPP_DRAWER_MAX_APP) && m_leftExtended == VFX_FALSE)
                {
                    // can add page
                    crossPageMove = VFX_TRUE;
                    m_leftExtended = VFX_TRUE;
                }
#endif // DRAWER_PAGE_LEFT_EXTENDABLE
            }
            else
            {
                crossPageMove = VFX_TRUE;
            }
        }
        else if (touchX > getSize().width - DRAWER_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if ( (currentPage >= m_menuView->getMaxPageCount(VAPP_DRAWER_MAX_APP) - 1) )
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

    const VcpPageMenuCellPos pos = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
    if (crossPageMove && pos.group == VCP_PAGE_MENU_GROUP_MAIN && getOrganizeTo().group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        crossPageOrganizeMove(touchX, touchY);
        m_lastAutoScrollTime = ctime;
    }
    else
    {
        if (pos != m_delayMovingTo)
        {
            m_delayMovingTo = pos;
            m_delayMovingTimer->setStartDelay(DRAWER_ANIMTIME_INSTANT);
            m_delayMovingTimer->start();

            m_delayMovingTouchPos.x = touchX;
            m_delayMovingTouchPos.y = touchY;
        }
        
        m_menuView->setDraggingFramePos(touchX, touchY);
        checkUpdate();
    }
}

void VappDrawerPageMenu::crossPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    // in this case, because the user touch move is usually slow, the animation shall be slower
    if (touchX < DRAWER_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        switchOrganizePage(m_menuView->getPreviousPage(), touchX, touchY);
    }
    else if (touchX > getSize().width - DRAWER_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        switchOrganizePage(m_menuView->getNextPage(), touchX, touchY);
    }
}

void VappDrawerPageMenu::switchOrganizePage(VfxS32 newPage, VfxS32 touchX, VfxS32 touchY)
{
    if (getOrganizeTo().group != VCP_PAGE_MENU_GROUP_MAIN)
    {
        VFX_ASSERT(VFX_FALSE);
    }

#ifdef DRAWER_PAGE_LEFT_EXTENDABLE
    if (newPage == -1)
    {
        newPage = 0;
        for (VfxS32 i = getPageCount() - 1; i >= 0; --i)
        {
            vcpPageMenuMovePageContent(m_cells, m_menuView->getPageItemCount(), i, i+1);
        }
        setPageCount(getPageCount() + 1);

        // adjust the cell pos
        VcpPageMenuCellPos target = getOrganizeTo();
        target.index += m_menuView->getPageItemCount();
        setOrganizeTo(target);
    }
#endif // DRAWER_PAGE_LEFT_EXTENDABLE

    scrollToPage(newPage, DRAWER_ORGANIZE_DURATION);

    m_menuView->setDraggingFramePos(touchX, touchY);

    // remove the dragging cell from the old page
    removeCellFrom(getOrganizeTo() );

    // adjust the page count if added new page
    if (m_menuView->getNearestPage() >= getPageCount() )
    {
        setPageCount(m_menuView->getNearestPage() + 1);
        m_rightExtended = VFX_TRUE;
    }

    // put the dragging cell to the new page
    const VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
    putCellTo(currentDirectPos, m_menuView->getDraggingFrame() );

    checkUpdate();
}

void VappDrawerPageMenu::removeCellFrom(VcpPageMenuCellPos pos)
{
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        const VfxS32 organizeIndex = pos.index;
        const VfxS32 pageEnd = (organizeIndex + m_menuView->getPageItemCount() ) /
            m_menuView->getPageItemCount() * m_menuView->getPageItemCount();
        for (VfxS32 i = organizeIndex; i < pageEnd - 1; ++i)
        {
            VcpPageMenuCellPos dest(VCP_PAGE_MENU_GROUP_MAIN, i);
            VcpPageMenuCellPos src(VCP_PAGE_MENU_GROUP_MAIN, i+1);
            setCell(dest, getCell(src) );
        }
        if (getHoldFrame() != NULL)
        {
            m_cells[pageEnd - 1] = getHoldFrame();
            setHoldFrame(NULL);
        }
        else
        {
            setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, pageEnd - 1), NULL);
        }
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        const VfxS32 organizeIndex = pos.index;
        const VfxS32 pageEnd = DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT;
        for (VfxS32 i = organizeIndex; i < pageEnd - 1; ++i)
        {
            VcpPageMenuCellPos dest(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, i);
            VcpPageMenuCellPos src(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, i+1);
            setCell(dest, getCell(src) );
        }
        setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, pageEnd - 1), NULL);
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}

void VappDrawerPageMenu::putCellTo(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell * cell)
{
    if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        putCellToMain(currentDirectPos, cell);
    }
    else if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        putCellToBar(currentDirectPos, cell);
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}

void VappDrawerPageMenu::putCellToMain(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell * cell)
{
    const VfxS32 firstInPage = m_menuView->getNearestPage() * m_menuView->getPageItemCount();
    if (m_cells[firstInPage] == NULL)
    {
        m_cells[firstInPage] = cell;
        setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, firstInPage) );
    }
    else
    {
        // set hold frame
        const VfxS32 currentPageEnd = firstInPage + m_menuView->getPageItemCount();
        if (m_cells[currentPageEnd - 1] != NULL)
        {
            setHoldFrame(m_cells[currentPageEnd - 1] );
            m_cells[currentPageEnd - 1] = NULL;
        }

        VfxS32 currentDirect = currentDirectPos.index;
//        if (currentDirectPos == MAINMENU_HITTEST_NOT_FOUND &&
//                touchY >= m_menuView->getLayout().cellStartY)
        if (currentDirectPos.index == MAINMENU_HITTEST_NOT_FOUND)
        {
            // append to the end of this page
            for (VfxS32 i = firstInPage; i < firstInPage + m_menuView->getPageItemCount(); ++i)
            {
                if (m_cells[i] == NULL)
                {
                    m_cells[i] = cell;
                    setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, i) );
                    break;
                }
            }
        }
        else
        {
            if (currentDirectPos.index == MAINMENU_HITTEST_NOT_FOUND)
            {
                currentDirect = firstInPage;
            }
            // around cells
            for (VfxS32 i = currentPageEnd - 1; i > currentDirect; --i)
            {
                m_cells[i] = m_cells[i - 1];
            }
            m_cells[currentDirect] = cell;
            setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, currentDirect) );
        }
    }
}

void VappDrawerPageMenu::putCellToBar(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell * cell)
{
    if (currentDirectPos.index == MAINMENU_HITTEST_NOT_FOUND)
    {
        // append to the end of this bar
        for (VfxS32 i = 0; i < DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT; ++i)
        {
            if (m_groupCells[i] == NULL)
            {
                m_groupCells[i] = cell;
                setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, i) );
                break;
            }
        }
    }
    else
    {
        // around cells
        for (VfxS32 i = DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT - 1; i > currentDirectPos.index; --i)
        {
            m_groupCells[i] = m_groupCells[i - 1];
        }
        setCell(currentDirectPos, cell);
        setOrganizeTo(currentDirectPos);
    }
}

void VappDrawerPageMenu::inPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    const VcpPageMenuCellPos currentTo = cellHittest(VfxPoint(touchX, touchY), VFX_TRUE);
        const VcpPageMenuCellPos prevOrganizeTo = getOrganizeTo();
    if (currentTo.group == prevOrganizeTo.group)
    {
        if (currentTo.index != MAINMENU_HITTEST_NOT_FOUND &&
                (currentTo.group != VCP_PAGE_MENU_GROUP_BOTTOM_BAR ||
                 currentTo.index < DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT) )
        {
            setOrganizeTo(currentTo);
            if (prevOrganizeTo != getOrganizeTo() )
            {
                if (getOrganizeTo().index > prevOrganizeTo.index)
                {
                    for (VfxS32 i = prevOrganizeTo.index; i < getOrganizeTo().index; ++i)
                    {
                        VcpPageMenuCellPos dest(prevOrganizeTo.group, i);
                        VcpPageMenuCellPos src(prevOrganizeTo.group, i+1);
                        setCell(dest, getCell(src) );
                    }
                    setCell(getOrganizeTo(), m_menuView->getDraggingFrame() );
                }
                else
                {
                    for (VfxS32 i = prevOrganizeTo.index; i > getOrganizeTo().index; --i)
                    {
                        VcpPageMenuCellPos dest(prevOrganizeTo.group, i);
                        VcpPageMenuCellPos src(prevOrganizeTo.group, i-1);
                        setCell(dest, getCell(src) );
                    }
                    setCell(getOrganizeTo(), m_menuView->getDraggingFrame() );
                }
            }
        }
    }
    else if (currentTo.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        // remove the dragging cell from the old page
        removeCellFrom(getOrganizeTo() );

        // put the dragging cell to the new page
        const VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
        putCellTo(currentDirectPos, m_menuView->getDraggingFrame() );
    }
    else if (currentTo.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        VfxBool isFull = VFX_TRUE;
        for (VfxS32 i = 0; i < DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT; ++i)
        {
            if (m_groupCells[i] == NULL)
            {
                isFull = VFX_FALSE;
                break;
            }
        }

        if (!isFull)
        {
            // remove the dragging cell from the old page
            const VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
            if (currentDirectPos.index < DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)
            {
                removeCellFrom(getOrganizeTo() );

                // put the dragging cell to the new page
                putCellTo(currentDirectPos, m_menuView->getDraggingFrame() );
            }
        }
    }

    m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
    checkUpdate();
}

void VappDrawerPageMenu::handleOrganizePut(VfxBool isCheckUpdate)
{
    if (m_delayMovingTimer->getIsEnabled())
    {
        m_delayMovingTimer->stop();
        inPageOrganizeMove(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
    }
    
    m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
    m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), getOrganizeTo().group);
    VappDrawerCell * mmCell = static_cast<VappDrawerCell*>(m_menuView->getDraggingFrame() );
    if (mmCell != NULL)
    {
        if (getOrganizeTo().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
        {
            mmCell->setOnBottomBar(VFX_TRUE);
        }
        else
        {
            mmCell->setOnBottomBar(VFX_FALSE);
        }
    }

    putHoldFrame();
    setHover(DRAWER_NO_HOVER);
    m_menuView->setDraggingFrame(NULL);
    m_leftExtended = VFX_FALSE;
    m_rightExtended = VFX_FALSE;

    if (isCheckUpdate)
    {
        checkUpdate();
    }
}

void VappDrawerPageMenu::handleOrganizeEnd(VfxBool isCheckUpdate)
{
    // ensure the dragging frame is put
    handleOrganizePut(isCheckUpdate);

    compactPages(isCheckUpdate);

    if (isCheckUpdate)
    {
        checkUpdate();
    }
}

void VappDrawerPageMenu::putHoldFrame()
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

VfxBool VappDrawerPageMenu::putHoldFrameAfterPage(VfxS32 page)
{
    const VfxS32 start = (page + 1) * m_menuView->getPageItemCount();
    for (VfxS32 index = start; index < VAPP_DRAWER_MAX_APP; ++index)
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

VfxBool VappDrawerPageMenu::putHoldFrameBeforePage(VfxS32 page)
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

void VappDrawerPageMenu::scrollToPage(VfxS32 pageIndex, VfxS32 animTime, VfxBool isCheckUpdate)
{
    if (pageIndex == -1)
    {
        // special case handling : no item on pages
        pageIndex = 0;
    }
    m_menuView->setTranslateX(m_menuView->getPageTranslateX(pageIndex), animTime);
    if (isCheckUpdate)
    {
        checkUpdate();
    }

    if (pageIndex != m_stableCurrentPageIndex)
    {
    #if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
        if (pageIndex > m_stableCurrentPageIndex)
        {
            m_menuView->setTransitionDirection(1);
        }
        else if (pageIndex < m_stableCurrentPageIndex)
        {
            m_menuView->setTransitionDirection(-1);
        }
    #endif
        
        m_stableCurrentPageIndex = pageIndex;
        m_pageChanged.postEmit(m_stableCurrentPageIndex);
    }
    
    m_delayLoadCellTimer->setStartDelay(DRAWER_LOAD_CELL_DELAY);
    m_delayLoadCellTimer->start();
}

VcpPageMenuCell * VappDrawerPageMenu::getCell(VcpPageMenuCellPos pos) const
{
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        return m_cells[pos.index];
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        return m_groupCells[pos.index];
    }
    VFX_ASSERT(VFX_FALSE);
    return NULL;
}

void VappDrawerPageMenu::setCell(VcpPageMenuCellPos pos, VcpPageMenuCell * cell)
{
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        m_cells[pos.index] = cell;
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        m_groupCells[pos.index] = cell;
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}

void VappDrawerPageMenu::updatePageIndicatorPos()
{
    m_pageIndicator->setPos(getSize().width / 2, DRAWER_INDICATOR_OFFSET_Y);
}

VfxBool VappDrawerPageMenu::getOrganizeMode() const
{
    return m_organizeMode;
}

void VappDrawerPageMenu::setOrganizeMode(VfxBool organizeMode)
{
    m_organizeMode = organizeMode;
    m_menuView->setOrganizeMode(organizeMode);
    
    mmi_app_package_name_struct *installedAppArray = NULL;
    U32 installedAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (installedAppCount)
    {
        VFX_SYS_ALLOC_MEM(installedAppArray, sizeof(mmi_app_package_name_struct) * installedAppCount );
        mmi_ret result;
        result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installedAppArray, installedAppCount);
        VFX_ASSERT(result != MMI_RET_ERR);
    }
    
    for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_APP; ++i)
    {
        if (m_cells[i])
        {
            VappDrawerCell *mmCell = static_cast<VappDrawerCell*>(m_cells[i]);
            VfxBool isInstalled = VFX_FALSE;
            if (installedAppArray)
            {
                mmi_app_package_name_struct appName;
                mmCell->getCellAppName(appName);
                isInstalled = isInstalledApp(appName, installedAppArray, installedAppCount);
            }
            mmCell->setIsInstalled(isInstalled);
        }
    }
    
    for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_GROUP_APP; ++i)
    {
        if (m_groupCells[i])
        {
            VappDrawerCell *mmCell = static_cast<VappDrawerCell*>(m_groupCells[i]);
            VfxBool isInstalled = VFX_FALSE;
            if (installedAppArray)
            {
                mmi_app_package_name_struct appName;
                mmCell->getCellAppName(appName);
                isInstalled = isInstalledApp(appName, installedAppArray, installedAppCount);
            }
            mmCell->setIsInstalled(isInstalled);
        }
    }
    
    if (installedAppArray)
    {
        VFX_SYS_FREE_MEM(installedAppArray);
    }
}

VcpPageMenuCellPos VappDrawerPageMenu::getOrganizeTo() const
{
    return m_organizeTo;
}

void VappDrawerPageMenu::setOrganizeTo(VcpPageMenuCellPos organizeTo)
{
    m_organizeTo = organizeTo;
}

VcpPageMenuCellPos VappDrawerPageMenu::getHover() const
{
    return m_hover;
}

void VappDrawerPageMenu::setHover(VcpPageMenuCellPos hover)
{
    m_hover = hover;
    m_menuView->setHover(hover);
}

VfxS32 VappDrawerPageMenu::getPageCount() const
{
    VFX_ASSERT(m_pageCount <= m_menuView->getMaxPageCount(VAPP_DRAWER_MAX_APP) );
    if (m_pageCount == 0)
    {
        // special case handling : no item on pages
        return 1;
    }
    return m_pageCount;
}

void VappDrawerPageMenu::setPageCount(VfxS32 pageCount, VfxBool isCheckUpdate)
{
    VFX_ASSERT(pageCount <= m_menuView->getMaxPageCount(VAPP_DRAWER_MAX_APP) );
    m_pageCount = pageCount;

    // some checks for menu initialization
    if (m_menuView->getNearestPage() >= getPageCount() )
    {
        scrollToPage(getPageCount() - 1, DRAWER_ORGANIZE_DURATION, isCheckUpdate);
    }
}

VcpPageMenuCell * VappDrawerPageMenu::getHoldFrame() const
{
    return m_holdFrame;
}

void VappDrawerPageMenu::setHoldFrame(VcpPageMenuCell * holdFrame)
{
    m_holdFrame = holdFrame;
    m_menuView->setHoldFrame(holdFrame);
}

VcpPageMenuCellPos VappDrawerPageMenu::cellHittest(VfxPoint clickPoint, VfxBool findLast) const
{
    const VcpPageMenuCellPos pos = m_menuView->baseCellHittest(clickPoint, VAPP_DRAWER_MAX_APP);

    if (pos.group != VCP_PAGE_MENU_GROUP_MAIN)
    {
        if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
        {
            if (m_groupCells[pos.index] != NULL)
            {
                return pos;
            }
            return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, MAINMENU_HITTEST_NOT_FOUND);
        }
        else
        {
            VFX_ASSERT(VFX_FALSE);
        }
    }

    if (pos.index == MAINMENU_HITTEST_NOT_FOUND)
    {
        return pos;
    }

    if (getCell(pos) != NULL)
    {
        return pos;
    }
    else if (findLast)
    {
        // if the clicked cell is NULL,
        // decrease the index and find non-NULL cell
        const VfxS32 firstInPanel = pos.index / m_menuView->getPageItemCount() *
            m_menuView->getPageItemCount();
        VcpPageMenuCellPos countDownPos = pos;

        while (countDownPos.index >= firstInPanel)
        {
            if (getCell(countDownPos) != NULL)
            {
                return countDownPos;
            }
            --countDownPos.index;
        }
    }
    return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, MAINMENU_HITTEST_NOT_FOUND);
}

