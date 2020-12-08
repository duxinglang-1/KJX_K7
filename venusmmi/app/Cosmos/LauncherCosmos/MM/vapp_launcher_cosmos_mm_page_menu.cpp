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
 *  vapp_launcher_cosmos_mm_page_menu.cpp
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher Cosmos
 *
 * Description:
 * ------------
 *  Launcher Cosmos Main Menu Page Menu
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
 *****************************************************************************/


#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_COSMOS__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_adp_device.h"

#include "vcp_page_menu_util.h"
#include "vcp_page_menu_transition.h"

#include "vapp_launcher_cosmos_mm.h" // for VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
#include "vapp_launcher_cosmos_mm_builder.h" // for VappLauncherCosmosMmCell
#include "vapp_launcher_cosmos_mm_default_order.h"
#include "vapp_launcher_cosmos_mm_page_menu.h"
#include "mmi_rp_vapp_launcher_cosmos_mm_def.h"

extern "C"
{
#include "Wgui.h"   // for MMI_STATUS_BAR_HEIGHT
}

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/*****************************************************************************
 * Define
 *****************************************************************************/

//#define VAPP_LAUNCHER_COSMOS_MM_PAGE_LEFT_EXTENDABLE

//#define VAPP_LAUNCHER_COSMOS_MM_FPS_TEST

#define VAPP_LAUNCHER_COSMOS_MM_SHADOW_EDIT_MODE

// to avoid global class with constructor
#define VAPP_LAUNCHER_COSMOS_MM_NO_HOVER VcpPageMenuCellPos(-1, -1)


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

// mainmenu user interaction constatnt
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_LONG_SWIPE_THRESHOLD = 600;

// mainmenu animation constatnt
#ifdef VAPP_LAUNCHER_COSMOS_MM_FPS_TEST
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT = 200;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE = 5000;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_MIN_RELEASE = 3000;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION = 2000;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT = 1;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE = 280;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_MIN_RELEASE = 200;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION = 200;
#endif

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_LONG_PRESS_ENTER_ORGANIZE_DELAY = 800;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_LONG_PRESS_ORGANIZE_ANOTHER_DELAY = 300;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_CD = 1000;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_DELAY_MOVING_DELAY = 100;

//static const VfxFloat VAPP_LAUNCHER_COSMOS_MM_ROTATION_LIMIT = 15.0f;

//static const VfxFloat VAPP_LAUNCHER_COSMOS_MM_BOUND_ROTATE_FACTOR = -0.09f;
static const VfxFloat VAPP_LAUNCHER_COSMOS_MM_BOUND_TRANSLATION_FACTOR = 0.5f;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT = 3;

static const VfxFloat VAPP_LAUNCHER_COSMOS_MM_EDITING_ALPHA = 0.5f;

// page indicator layout constants
#if defined(__MMI_MAINLCD_480X800__)

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_WIDTH = 480;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_HEIGHT = 50;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_BG_HEIGHT = 50;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_SPACING = 30;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SWIPE_RANGE_THRESHOLD = 60;

#ifdef __TOUCH_PANEL_CAPACITY__
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_X = 10;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_X = 5;
#endif
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_Y = 80;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN = 30;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_WIDTH = 240;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_HEIGHT = 25;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_BG_HEIGHT = 25;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_SPACING = 20;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SWIPE_RANGE_THRESHOLD = 30;

#ifdef __TOUCH_PANEL_CAPACITY__
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_X = 10;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_X = 5;
#endif
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_Y = 30;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN = 15;

#else

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_WIDTH = 320;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_HEIGHT = 28;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_BG_HEIGHT = 28;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_SPACING = 20;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SWIPE_RANGE_THRESHOLD = 30;

#ifdef __TOUCH_PANEL_CAPACITY__
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_X = 10;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_X = 5;
#endif
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_Y = 40;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN = 20;

#endif

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_HIGHLIGHT_COUNT = 10;


/*****************************************************************************
 * Class VcpLauncherCosmosMmPageMenuView
 *****************************************************************************/

class VcpLauncherCosmosMmPageMenuView : public VcpPageMenuView
{
protected:
    virtual void updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos);
};

void VcpLauncherCosmosMmPageMenuView::updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos)
{
#ifdef VAPP_LAUNCHER_COSMOS_MM_SHADOW_EDIT_MODE
    VfxFloat opacity;
    if (pos == getHover() && getOrganizeMode() == VFX_FALSE )
    {
        opacity = VAPP_LAUNCHER_COSMOS_MM_EDITING_ALPHA;
    }
    else
    {
        opacity = 1.0f;
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    cell->setOpacity(opacity);
    VfxAutoAnimate::commit();

    VappLauncherCosmosMmCell * mmCell = static_cast<VappLauncherCosmosMmCell*>(cell);
    if (mmCell == NULL)
    {
        return;
    }
    mmCell->setEditMode(getOrganizeMode() );

#else
    VcpPageMenuView::updateCellAttribute(cell, pos);
#endif
}


/*****************************************************************************
 * Class VappLauncherCosmosMmPageMenu
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmPageMenu", VappLauncherCosmosMmPageMenu, VfxControl);

VappLauncherCosmosMmPageMenu::VappLauncherCosmosMmPageMenu():
    m_pageCount(0),
    m_stableCurrentPageIndex(0),
    m_menuView(NULL),
    m_holdFrame(NULL),
    m_pageIndicator(NULL),
    m_longPressTimer(NULL),
    m_delayLoadCellTimer(NULL),
    m_delayMovingTimer(NULL),
    m_autoScrollPageTimer(NULL),
    m_hover(VAPP_LAUNCHER_COSMOS_MM_NO_HOVER),
    m_startPen(VFX_FALSE),
    m_canScroll(VFX_FALSE),
    m_translateOrigX(0),
    m_updateCount(0),
    m_organizeMode(VFX_FALSE),
    m_organizeTo(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_delayMovingTo(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_delayMovingToHitArea(VCP_PAGE_MENU_CELL_HIT_AREA_INVALID),
    m_lastAutoScrollTime(0),
    m_leftExtended(VFX_FALSE),
    m_rightExtended(VFX_FALSE)
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_APP; ++i)
    {
        m_cells[i] = NULL;
    }

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP; ++i)
    {
        m_groupCells[i] = NULL;
    }
}

VfxS32 VappLauncherCosmosMmPageMenu::getCurrentPageIndex() const
{
    return m_menuView->getNearestPage();
}

void VappLauncherCosmosMmPageMenu::setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated)
{
    if (animated)
    {
        scrollToPage(pageIndex, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
    }
    else
    {
        scrollToPage(pageIndex, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT);
    }
}

const VcpPageMenuLayout & VappLauncherCosmosMmPageMenu::getMenuLayout() const
{
    return m_menuView->getLayout();
}

void VappLauncherCosmosMmPageMenu::setMenuLayout(const VcpPageMenuLayout & layout)
{
    m_menuView->setLayout(layout);
    updatePageIndicatorPos();
}

void VappLauncherCosmosMmPageMenu::refreshMenu()
{
    m_updateCount = 0;
    m_menuView->setClickFrame(NULL);
    m_menuView->reset();
    setFocused(VFX_TRUE);
}

void VappLauncherCosmosMmPageMenu::serializeMenu()
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_APP; ++i)
    {
        VfxS32 currentPageCellStartIndex = getCurrentPageIndex() * getMenuItemCountPerPage();
        VfxS32 currentPageCellEndIndex = currentPageCellStartIndex + getMenuItemCountPerPage() - 1;
        if ((i < currentPageCellStartIndex || i > currentPageCellEndIndex) &&
            m_cells[i])
        {
            VappLauncherCosmosMmCell *mmCell = static_cast<VappLauncherCosmosMmCell *>(m_cells[i]);
            mmCell->onCellSerialize();
            mmCell->setHidden(VFX_TRUE);
        }
    }
}

void VappLauncherCosmosMmPageMenu::setIsUninstallingMode(VfxBool isUninstalling)
{
    m_menuView->setIsUninstalling(isUninstalling);
}

void VappLauncherCosmosMmPageMenu::setIsEnterNCenter(VfxBool isEnterNCenter)
{
    m_menuView->setIsEnterNCenter(isEnterNCenter);
}

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
VcpPageMenuTransitionType VappLauncherCosmosMmPageMenu::getTransitionEffect() const
{
    return m_menuView->getTransitionEffect();
}

void VappLauncherCosmosMmPageMenu::setTransitionEffect(VcpPageMenuTransitionType transitionType)
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
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

void VappLauncherCosmosMmPageMenu::leaveOrganizationMode(VfxBool isCheckUpdate)
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

void VappLauncherCosmosMmPageMenu::enterOrganizationMode()
{
    setOrganizeMode(VFX_TRUE);
}

void VappLauncherCosmosMmPageMenu::forceDirty()
{
    m_menuView->forceDirty();
    checkUpdate();
}

VfxBool VappLauncherCosmosMmPageMenu::isHitCell(VfxPenEvent &event)
{
    const VfxPoint &touchDownPos = event.getRelPos(this);
    const VcpPageMenuCellPos pos = cellHittest(touchDownPos, VFX_FALSE);
    if (pos.index == MAINMENU_HITTEST_NOT_FOUND)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

VcpPageMenuCell * VappLauncherCosmosMmPageMenu::getMenuItem(VfxS32 index) const
{
    return m_cells[index];
}

void VappLauncherCosmosMmPageMenu::setMenuItem(VfxS32 index, VcpPageMenuCell * cell)
{
    if (m_cells[index] != NULL)
    {
        m_menuView->setAnimDirty(VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION);
    }

    m_cells[index] = cell;
    if (cell == NULL)
    {
        return;
    }

    cell->setAutoAnimate(VFX_TRUE);

    m_menuView->initCellAnim(cell, VCP_PAGE_MENU_GROUP_MAIN);

    checkUpdate();
}

VcpPageMenuCell * VappLauncherCosmosMmPageMenu::getGroupMenuItem(VfxS32 index) const
{
    return m_groupCells[index];
}

void VappLauncherCosmosMmPageMenu::setGroupMenuItem(VfxS32 index, VcpPageMenuCell * cell)
{
    m_groupCells[index] = cell;
    if (cell == NULL)
    {
        return;
    }

    cell->setAutoAnimate(VFX_TRUE);

    m_menuView->initCellAnim(cell, VCP_PAGE_MENU_GROUP_BOTTOM_BAR);

    checkUpdate();
}

void VappLauncherCosmosMmPageMenu::clearAllMenuItems()
{
    if (m_menuView->getDraggingFrame())
    {
        handleOrganizePut();
    }
    m_menuView->setClickFrame(NULL);

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_APP; ++i)
    {
        if (m_cells[i])
        {
            VFX_OBJ_CLOSE(m_cells[i]);
        }
    }
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP; ++i)
    {
        if (m_groupCells[i])
        {
            VFX_OBJ_CLOSE(m_groupCells[i]);
        }
    }
}

void VappLauncherCosmosMmPageMenu::setCellIconSize(const VfxSize & size)
{
    m_menuView->setCellIconSize(size);
}

VfxS32 VappLauncherCosmosMmPageMenu::getPageCount() const
{
    VFX_ASSERT(m_pageCount <= m_menuView->getMaxPageCount(VAPP_LAUNCHER_COSMOS_MM_MAX_APP) );
    if (m_pageCount == 0)
    {
        // special case handling : no item on pages
        return 1;
    }
    return m_pageCount;
}

void VappLauncherCosmosMmPageMenu::setPageCount(VfxS32 pageCount, VfxBool isCheckUpdate)
{
    VFX_ASSERT(pageCount <= m_menuView->getMaxPageCount(VAPP_LAUNCHER_COSMOS_MM_MAX_APP) );
    m_pageCount = pageCount;

    // some checks for menu initialization
    if (m_menuView->getNearestPage() >= getPageCount() )
    {
        scrollToPage(getPageCount() - 1, VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION, isCheckUpdate);
    }
}

VfxS32 VappLauncherCosmosMmPageMenu::getMaxPageCount() const
{
    return m_menuView->getMaxPageCount(VAPP_LAUNCHER_COSMOS_MM_MAX_APP);
}

VfxS32 VappLauncherCosmosMmPageMenu::getMenuItemCountPerPage() const
{
    return m_menuView->getPageItemCount();
}

VfxS32 VappLauncherCosmosMmPageMenu::getMenuItemCountPerGroup() const
{
    return 16;
}

void VappLauncherCosmosMmPageMenu::compactPages(VfxBool isCheckUpdate)
{
    m_menuView->setAnimDirty(VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION * 2);
    
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

    scrollToPage(pageIndexAfterCompact, VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION, isCheckUpdate);
    setPageCount(nonemptyPageCount, isCheckUpdate);
}

void VappLauncherCosmosMmPageMenu::preLoadAndCacheNeighborPageCell()
{
    VfxS32 prevPageStartIndex = (getCurrentPageIndex() - 1) * getMenuItemCountPerPage();
    VfxBool needCachePrevPage = VFX_TRUE;
    if (getCurrentPageIndex() == 0 ||
        m_cells[prevPageStartIndex] == NULL)
    {
        needCachePrevPage = VFX_FALSE;
    }
    
    VfxS32 nextPageStartIndex = (getCurrentPageIndex() + 1) * getMenuItemCountPerPage();
    VfxBool needCacheNextPage = VFX_TRUE;
    if (getCurrentPageIndex() == (getMaxPageCount() - 1) ||
        m_cells[nextPageStartIndex] == NULL)
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
        }
        
        cellIndex = nextPageStartIndex + i;
        if (needCacheNextPage && m_cells[cellIndex])
        {
            m_cells[cellIndex]->onCellDisplay();
        }
    }
    
    // Cache cell which is outside the screen
    preCacheChildren();
}

void VappLauncherCosmosMmPageMenu::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    m_menuView->setSize(value.size.width, value.size.height );

    updatePageIndicatorPos();
}

void VappLauncherCosmosMmPageMenu::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_menuView, VcpLauncherCosmosMmPageMenuView, this);
    m_menuView->setClipMargin(0);

    VFX_OBJ_CREATE(m_pageIndicator, VcpPageMenuIndicator, this);
    m_pageIndicator->setAnchor(0.5f, 0.0f);

    // initial the page indicator
    VcpPageMenuIndicatorLayout indicatorLayout;
    indicatorLayout.indicatorWidthBase = VAPP_LAUNCHER_COSMOS_MM_INDICATOR_WIDTH;
    indicatorLayout.indicatorWidthIncrement = 0;
    indicatorLayout.indicatorHeight = VAPP_LAUNCHER_COSMOS_MM_INDICATOR_HEIGHT;
    indicatorLayout.bgOffsetY = 0;
    indicatorLayout.bgHeight = VAPP_LAUNCHER_COSMOS_MM_INDICATOR_BG_HEIGHT;
    indicatorLayout.cellSpacing = VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_SPACING;
    indicatorLayout.cellOffsetX = VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_OFFSET_X;
    indicatorLayout.cellOffsetY = VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_OFFSET_Y;
    VfxImageSrc normalDot(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_INDICATOR_DOT_N);
    indicatorLayout.cellWidth = normalDot.getSize().width;
    indicatorLayout.cellHeight = normalDot.getSize().height;
    VfxImageSrc highlightDot(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_INDICATOR_DOT_H1);
    indicatorLayout.cellHighlightWidth = highlightDot.getSize().width;
    indicatorLayout.cellHighlightHeight = highlightDot.getSize().height;
    m_pageIndicator->setCellImage(normalDot, highlightDot, VAPP_LAUNCHER_COSMOS_MM_INDICATOR_CELL_HIGHLIGHT_COUNT);
    m_pageIndicator->setLayout(indicatorLayout);

    updatePageIndicatorPos();
    m_pageIndicator->m_pageSelected.connect(this, &VappLauncherCosmosMmPageMenu::onPageIndicatorSelected);

    VFX_OBJ_CREATE(m_longPressTimer, VfxTimer, this);
    m_longPressTimer->m_signalTick.connect(this, &VappLauncherCosmosMmPageMenu::onLongPressTimerTick);

    VFX_OBJ_CREATE(m_delayLoadCellTimer, VfxTimer, this);
    m_delayLoadCellTimer->m_signalTick.connect(this, &VappLauncherCosmosMmPageMenu::onDelayLoadCellTimerTick);

    VFX_OBJ_CREATE(m_delayMovingTimer, VfxTimer, this);
    m_delayMovingTimer->m_signalTick.connect(this, &VappLauncherCosmosMmPageMenu::onDelayMovingTimerTick);
    
    VFX_OBJ_CREATE(m_autoScrollPageTimer, VfxTimer, this);
    m_autoScrollPageTimer->m_signalTick.connect(this, &VappLauncherCosmosMmPageMenu::onAutoScrollPageTimerTick);
    
    checkUpdate();
}

void VappLauncherCosmosMmPageMenu::onUpdate()
{
    VfxControl::onUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM2", SA_start);
#endif

    if (m_menuView->getNearestPage() > getPageCount() - 1)
    {
        scrollToPage(getPageCount() - 1, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT);
    }

    ++m_updateCount;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM2", SA_stop);
#endif

    m_menuView->update(m_cells, VAPP_LAUNCHER_COSMOS_MM_MAX_APP, m_groupCells, VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM2", SA_start);
#endif

    if (m_stableCurrentPageIndex != m_pageIndicator->getCurrentPage() || getPageCount() != m_pageIndicator->getIndicatorPageCount() || m_updateCount == 1)
    {
        const VfxS32 currentPageIndex = m_menuView->getNearestPage();
        m_pageIndicator->setCurrentPage(currentPageIndex);
        VfxS32 indicatorPageCount = getPageCount();
        if (currentPageIndex + 1 > indicatorPageCount && currentPageIndex < m_menuView->getMaxPageCount(VAPP_LAUNCHER_COSMOS_MM_MAX_APP) )
        {
            indicatorPageCount = currentPageIndex + 1;
        }
        m_pageIndicator->setIndicatorPageCount(indicatorPageCount);
        m_pageIndicator->update();
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM2", SA_stop);
#endif
}

VfxBool VappLauncherCosmosMmPageMenu::onPenInput(VfxPenEvent &event)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MMT", SA_start);
#endif
    if (event.type == VFX_PEN_EVENT_TYPE_UP || event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        // make sure the timer is stopped
        m_longPressTimer->stop();
    }

    // default animation parameters
    m_menuView->setDragOnIndicator(VFX_FALSE);

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VfxBool result = handlePenDown(event.getRelPos(this) );
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MMT", SA_stop);
#endif
        return result;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        // long tap is ignored, VappLauncherCosmosMmPageMenu handle long tap behavior itself
    }
    else if (getOrganizeMode() && m_menuView->getDraggingFrame() != NULL)
    {
        VfxBool result = handleOrganize(event.type, event.getRelPos(this) );
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MMT", SA_stop);
#endif
        return result;
    }
    else
    {
        VfxBool result = handleScroll(event);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MMT", SA_stop);
#endif
        return result;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MMT", SA_stop);
#endif
    return VfxControl::onPenInput(event);
}

VfxBool VappLauncherCosmosMmPageMenu::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT &&
        (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (m_stableCurrentPageIndex > 0)
        {
            scrollToPage(m_stableCurrentPageIndex - 1, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
        }
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT &&
             (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (m_stableCurrentPageIndex < (m_pageCount - 1))
        {
            scrollToPage(m_stableCurrentPageIndex + 1, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
        }
        return VFX_TRUE;
    }
    
    return VfxControl::onKeyInput(event);
}

VfxBool VappLauncherCosmosMmPageMenu::getOrganizeMode() const
{
    return m_organizeMode;
}

void VappLauncherCosmosMmPageMenu::setOrganizeMode(VfxBool organizeMode)
{
    m_organizeMode = organizeMode;
    m_menuView->setOrganizeMode(organizeMode);

    // Support uninstall icon, query app to see if can be deleted.
    
    mmi_app_package_name_struct *installedAppArray = NULL;
    U32 installedAppCount = 
    srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (installedAppCount)
    {
        VFX_SYS_ALLOC_MEM(installedAppArray, sizeof(mmi_app_package_name_struct) * installedAppCount );
        mmi_ret result;
        result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installedAppArray, installedAppCount);
        VFX_ASSERT(result != MMI_RET_ERR);
    }
    
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_APP; ++i)
    {
        if (m_cells[i])
        {
            VappLauncherCosmosMmCell *mmCell = static_cast<VappLauncherCosmosMmCell*>(m_cells[i]);
            VfxBool isInstalled = VFX_FALSE;
            if (installedAppArray)
            {
                mmi_app_package_name_struct appName;
                mmCell->getCellAppName(appName);
                isInstalled = vappLauncherCosmosMmIsInstalledApp(appName, installedAppArray, installedAppCount);
            }
            mmCell->setIsInstalled(isInstalled);
        }
    }
    
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP; ++i)
    {
        if (m_groupCells[i])
        {
            VappLauncherCosmosMmCell *mmCell = static_cast<VappLauncherCosmosMmCell*>(m_groupCells[i]);
            VfxBool isInstalled = VFX_FALSE;
            if (installedAppArray)
            {
                mmi_app_package_name_struct appName;
                mmCell->getCellAppName(appName);
                isInstalled = vappLauncherCosmosMmIsInstalledApp(appName, installedAppArray, installedAppCount);
            }
            mmCell->setIsInstalled(isInstalled);
        }
    }
    
    if (installedAppArray)
    {
        VFX_SYS_FREE_MEM(installedAppArray);
    }        
}

VcpPageMenuCellPos VappLauncherCosmosMmPageMenu::getOrganizeTo() const
{
    return m_organizeTo;
}

void VappLauncherCosmosMmPageMenu::setOrganizeTo(VcpPageMenuCellPos organizeTo)
{
    m_organizeTo = organizeTo;
}

VcpPageMenuCellPos VappLauncherCosmosMmPageMenu::getHover() const
{
    return m_hover;
}

void VappLauncherCosmosMmPageMenu::setHover(VcpPageMenuCellPos hover)
{
    if (m_hover != hover)
    {
        m_hover = hover;
        m_menuView->setHover(m_hover);
    }
}

VcpPageMenuCell * VappLauncherCosmosMmPageMenu::getHoldFrame() const
{
    return m_holdFrame;
}

void VappLauncherCosmosMmPageMenu::setHoldFrame(VcpPageMenuCell * holdFrame)
{
    m_holdFrame = holdFrame;
    m_menuView->setHoldFrame(holdFrame);
}

void VappLauncherCosmosMmPageMenu::onLongPressTimerTick(VfxTimer *source)
{
    if (getHover().index == MAINMENU_HITTEST_NOT_FOUND)
    {
        return;
    }

    if (getOrganizeMode() )
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
        
        m_menuView->setAnimDirty(VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION);
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

        m_menuView->setAnimDirty(VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION);
    }
}

void VappLauncherCosmosMmPageMenu::onDelayLoadCellTimerTick(VfxTimer *source)
{
    preLoadAndCacheNeighborPageCell();
}

void VappLauncherCosmosMmPageMenu::onDelayMovingTimerTick(VfxTimer *source)
{
    inPageOrganizeMove(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
}

void VappLauncherCosmosMmPageMenu::onAutoScrollPageTimerTick(VfxTimer *source)
{
    VfxBool crossPageMove = VFX_FALSE;
    const VfxS32 currentPage = m_menuView->getNearestPage();
    if (m_lastAutoScrollTouchPos.x < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        if (currentPage == 0)
        {
        #ifdef VAPP_LAUNCHER_COSMOS_MM_PAGE_LEFT_EXTENDABLE
            if (getPageCount() < m_menuView->getMaxPageCount(VAPP_LAUNCHER_COSMOS_MM_MAX_APP) && m_leftExtended == VFX_FALSE)
            {
                // can add page
                crossPageMove = VFX_TRUE;
                m_leftExtended = VFX_TRUE;
            }
        #endif // VAPP_LAUNCHER_COSMOS_MM_PAGE_LEFT_EXTENDABLE
        }
        else
        {
            crossPageMove = VFX_TRUE;
        }
    }
    else if (m_lastAutoScrollTouchPos.x > getSize().width - VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        if ( (currentPage >= m_menuView->getMaxPageCount(VAPP_LAUNCHER_COSMOS_MM_MAX_APP) - 1) )
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

    if (crossPageMove)
    {
        crossPageOrganizeMove(m_lastAutoScrollTouchPos.x, m_lastAutoScrollTouchPos.y);
        
        m_lastAutoScrollTime = vrt_sys_get_time();
        source->setStartDelay(VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_CD);
        source->start();
    }
}

void VappLauncherCosmosMmPageMenu::onPageIndicatorSelected(VfxS32 pageSelected)
{
    scrollToPage(pageSelected, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
}

void VappLauncherCosmosMmPageMenu::onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    VFX_OBJ_CLOSE(timeline);
}

VcpPageMenuCellPos VappLauncherCosmosMmPageMenu::cellHittest(VfxPoint clickPoint, VfxBool findLast) const
{
    const VcpPageMenuCellPos pos = m_menuView->baseCellHittest(clickPoint, VAPP_LAUNCHER_COSMOS_MM_MAX_APP);

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

void VappLauncherCosmosMmPageMenu::scrollToPage(VfxS32 pageIndex, VfxS32 animTime, VfxBool isCheckUpdate)
{
    if (pageIndex == -1)
    {
        // special case handling : no item on pages
        pageIndex = 0;
    }
    if (pageIndex == getPageCount() && m_menuView->getDraggingFrame() == NULL)
    {
        // special case handling : no item on pages
        pageIndex = getPageCount() - 1;
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
    #endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
        
        m_stableCurrentPageIndex = pageIndex;
        m_pageChanged.postEmit(m_stableCurrentPageIndex);
    }

    if (!getOrganizeMode() && animTime != VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT)
    {
        m_delayLoadCellTimer->setStartDelay(animTime);
        m_delayLoadCellTimer->start();
    }
}

void VappLauncherCosmosMmPageMenu::updatePageIndicatorPos()
{
    m_pageIndicator->setPos(getSize().width / 2, 
                            getMenuLayout().bottomBarOffsetY - VAPP_LAUNCHER_COSMOS_MM_INDICATOR_HEIGHT);
}

VcpPageMenuCell *VappLauncherCosmosMmPageMenu::getCell(VcpPageMenuCellPos pos) const
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

void VappLauncherCosmosMmPageMenu::setCell(VcpPageMenuCellPos pos, VcpPageMenuCell * cell)
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

VfxBool VappLauncherCosmosMmPageMenu::handlePenDown(const VfxPoint &touchDownPos)
{
    // to stop translate anim
    if (m_menuView->isTransitioning() )
    {
        m_menuView->syncTranslateX();
        checkUpdate();
    }

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
        setHover(pos);
        if (getHover().index != MAINMENU_HITTEST_NOT_FOUND)
        {
            m_menuView->initDraggingFramePos(getCell(getHover() ), getHover().group, touchDownPos.x, touchDownPos.y);
            m_menuView->setClickFrame(getCell(pos));

            if (getOrganizeMode() )
            {
                if ((getHover().group == VCP_PAGE_MENU_GROUP_MAIN && getHover().index >= VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT) ||
                    (getHover().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && getHover().index < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT))
                {
                    m_longPressTimer->setStartDelay(VAPP_LAUNCHER_COSMOS_MM_LONG_PRESS_ORGANIZE_ANOTHER_DELAY);
                    m_longPressTimer->start();
                }
            }
            else
            {
                m_longPressTimer->setStartDelay(VAPP_LAUNCHER_COSMOS_MM_LONG_PRESS_ENTER_ORGANIZE_DELAY);
                m_longPressTimer->start();
            }
        }
    }
    return VFX_TRUE;
}

VfxBool VappLauncherCosmosMmPageMenu::handleScroll(const VfxPenEvent &event)
{
    const VfxPoint touchPos = event.getRelPos(this);
    const VfxPoint touchDownPos = event.getRelDownPos(this);
    const VfxS32 diffOrigX = touchPos.x - touchDownPos.x;
    const VfxS32 diffOrigY = touchPos.y - touchDownPos.y;

    if (event.type == VFX_PEN_EVENT_TYPE_ABORT ||
            VFX_ABS(diffOrigX) > VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_X ||
            VFX_ABS(diffOrigY) > VAPP_LAUNCHER_COSMOS_MM_CANCEL_HOVER_THRESHOLD_Y)
    {
        m_longPressTimer->stop();
        setHover(VAPP_LAUNCHER_COSMOS_MM_NO_HOVER);
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
        const VfxS32 elapse = VAPP_LAUNCHER_COSMOS_MM_LONG_SWIPE_THRESHOLD * 2;
        const VfxS32 diffX = 0;
        handleScrollEnd(diffX, elapse);
    }

    return VFX_TRUE;
}

void VappLauncherCosmosMmPageMenu::handleScrollEnd(VfxS32 diffX, VfxMsec elapse)
{
    const VfxFloat speed = static_cast<VfxFloat>(diffX * 1000) / elapse;

//    m_menuView->setRotateAngle(0, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE, VFX_TRUE);

    if (m_startPen && !m_menuView->isTransitioning() && !getOrganizeMode() )
    {
        // clicked
        if (getHover().index != MAINMENU_HITTEST_NOT_FOUND)
        {
            m_appClicked.postEmit(getCell(getHover() ) );
        }
    }
    else if (elapse < VAPP_LAUNCHER_COSMOS_MM_LONG_SWIPE_THRESHOLD)
    {
        if (m_canScroll)
        {
            handleScrollSwipe(diffX, speed);
        }
        else
        {
            scrollToPage(m_menuView->getNearestPage(), VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
        }
		m_menuView->setClickFrame(NULL);
        
        checkUpdate();
    }
    else
    {
        // scroll to the nearest page
        scrollToPage(m_menuView->getNearestPage(), VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
		m_menuView->setClickFrame(NULL);
        
        checkUpdate();
    }

    setHover(VAPP_LAUNCHER_COSMOS_MM_NO_HOVER);

    // limiting
    if (m_menuView->getTranslateX() > 0)
    {
        scrollToPage(0, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
    }
    if (m_menuView->getTranslateX() < m_menuView->getPageTranslateX(getPageCount() - 1) )
    {
        scrollToPage(getPageCount() - 1, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
    }
}

void VappLauncherCosmosMmPageMenu::handleScrollMove(VfxS32 diffOrigX, VfxS32 diffOrigY)
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

        // limiting to make damping effect
        VfxS32 pageLevel = getSize().width + m_menuView->getLayout().pageMargin;
        if (translateX > 0)
        {
//            const VfxFloat rotateAngle = (translateX - 0) * VAPP_LAUNCHER_COSMOS_MM_BOUND_ROTATE_FACTOR;
//            m_menuView->setRotateAngle(rotateAngle , VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = translateX * VAPP_LAUNCHER_COSMOS_MM_BOUND_TRANSLATION_FACTOR;
        }
        if (translateX < m_menuView->getPageTranslateX(getPageCount() - 1))
        {
//            const VfxFloat rotateAngle = (translateX -
//                        ( m_menuView->getPageTranslateX(getPageCount() - 1) ) ) *
//                        VAPP_LAUNCHER_COSMOS_MM_BOUND_ROTATE_FACTOR;
//            m_menuView->setRotateAngle(rotateAngle , VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = m_menuView->getPageTranslateX(getPageCount() - 1) + ((translateX - m_menuView->getPageTranslateX(getPageCount() - 1)) * VAPP_LAUNCHER_COSMOS_MM_BOUND_TRANSLATION_FACTOR);
        }
        m_menuView->setTranslateX(translateX, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT);

    #if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
        if (diffOrigX < 0)
        {
            m_menuView->setTransitionDirection(1);
        }
        else if (diffOrigX > 0)
        {
            m_menuView->setTransitionDirection(-1);
        }
    #endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
        
        checkUpdate();
    }
}

void VappLauncherCosmosMmPageMenu::handleScrollSwipe(VfxS32 diffX, VfxFloat speed)
{
    if (diffX > VAPP_LAUNCHER_COSMOS_MM_SWIPE_RANGE_THRESHOLD)
    {
        const VfxS32 targetPage = m_menuView->getPreviousPage();
        const VfxS32 duration = calculateSwipeTime(targetPage, speed);
        scrollToPage(targetPage, duration);
    }
    else if (diffX < -VAPP_LAUNCHER_COSMOS_MM_SWIPE_RANGE_THRESHOLD)
    {
        const VfxS32 targetPage = m_menuView->getNextPage();
        const VfxS32 duration = calculateSwipeTime(targetPage, speed);
        scrollToPage(targetPage, duration);
    }
    else
    {
        scrollToPage(m_menuView->getNearestPage(), VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE);
    }
}

VfxS32 VappLauncherCosmosMmPageMenu::calculateSwipeTime(VfxS32 targetPageIndex, VfxFloat speed)
{
    if (speed == 0)
    {
        return VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE;
    }

    const VfxS32 currentPos = m_menuView->getTranslateX();
    const VfxS32 targetPos = m_menuView->getPageTranslateX(targetPageIndex);
    const VfxS32 distance = vfxAbs(targetPos - currentPos);
	const VfxFloat absSpeed = vfxAbs(speed);
    const VfxS32 durationToKeepSpeed = static_cast<VfxS32>( (distance * 1000) / absSpeed + 0.5f);
    const VfxS32 minDuration = VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_MIN_RELEASE;
    const VfxS32 maxDuration = VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_RELEASE;
    return vfxMax(minDuration, vfxMin(maxDuration, durationToKeepSpeed));
}

VfxBool VappLauncherCosmosMmPageMenu::handleOrganize(VfxPenEventTypeEnum touchType, const VfxPoint &touchPos)
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

void VappLauncherCosmosMmPageMenu::handleOrganizeStart()
{
    if ((getHover().group == VCP_PAGE_MENU_GROUP_MAIN && getHover().index >= VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT) ||
        (getHover().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && getHover().index < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT))
    {
        setOrganizeTo(getHover() );
        m_menuView->setDraggingFrame(getCell(getHover() ) );
        m_delayMovingTo = getHover();
    }
    else
    {
        setHover(VAPP_LAUNCHER_COSMOS_MM_NO_HOVER);
        setOrganizeTo(VAPP_LAUNCHER_COSMOS_MM_NO_HOVER);
        m_menuView->setDraggingFrame(NULL);
    }

    scrollToPage(m_menuView->getNearestPage(), VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT);
//    m_menuView->setRotateAngle(0, VAPP_LAUNCHER_COSMOS_MM_ANIMTIME_INSTANT, VFX_TRUE);

    checkUpdate();
}

void VappLauncherCosmosMmPageMenu::handleOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    VfxBool crossPageMove = VFX_FALSE;
    const VfxMsec ctime = vrt_sys_get_time();
    if (ctime - m_lastAutoScrollTime > VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_CD)
    {
        if (touchX < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if (currentPage == 0)
            {
#ifdef VAPP_LAUNCHER_COSMOS_MM_PAGE_LEFT_EXTENDABLE
                if (getPageCount() < m_menuView->getMaxPageCount(VAPP_LAUNCHER_COSMOS_MM_MAX_APP) && m_leftExtended == VFX_FALSE)
                {
                    // can add page
                    crossPageMove = VFX_TRUE;
                    m_leftExtended = VFX_TRUE;
                }
#endif // VAPP_LAUNCHER_COSMOS_MM_PAGE_LEFT_EXTENDABLE
            }
            else
            {
                crossPageMove = VFX_TRUE;
            }
        }
        else if (touchX > getSize().width - VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if ( (currentPage >= m_menuView->getMaxPageCount(VAPP_LAUNCHER_COSMOS_MM_MAX_APP) - 1) )
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

    if (touchX < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN ||
        touchX > getSize().width - VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        m_lastAutoScrollTouchPos.x = touchX;
        m_lastAutoScrollTouchPos.y = touchY;
    }
    
    // Use cell center to decide cell position and prepared folder trigger area
    VfxS32 cellCenterX = touchX + m_menuView->getOrganizeDragOffset().x + m_menuView->getDraggingFrame()->getSize().width / 2;
    VfxS32 cellCenterY = touchY + m_menuView->getOrganizeDragOffset().y + m_menuView->getDraggingFrame()->getSize().height / 2;
    const VcpPageMenuCellPos pos = cellHittest(VfxPoint(cellCenterX, cellCenterY), VFX_FALSE);
    if (crossPageMove && pos.group == VCP_PAGE_MENU_GROUP_MAIN && getOrganizeTo().group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        crossPageOrganizeMove(touchX, touchY);
        
        m_lastAutoScrollTime = ctime;
        m_autoScrollPageTimer->setStartDelay(VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_CD);
        m_autoScrollPageTimer->start();
    }
    else
    {
        if (!(touchX < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN ||
              touchX > getSize().width - VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN))
        {
            m_autoScrollPageTimer->stop();
        }
        
        if (pos != m_delayMovingTo)
        {
            m_delayMovingTo = pos;
            m_delayMovingTimer->setStartDelay(VAPP_LAUNCHER_COSMOS_MM_DELAY_MOVING_DELAY);
            m_delayMovingTimer->start();

            m_delayMovingTouchPos.x = cellCenterX;
            m_delayMovingTouchPos.y = cellCenterY;
        }
        
        m_menuView->setDraggingFramePos(touchX, touchY);
        checkUpdate();
    }
}

void VappLauncherCosmosMmPageMenu::crossPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    // in this case, because the user touch move is usually slow, the animation shall be slower
    if (touchX < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        switchOrganizePage(m_menuView->getPreviousPage(), touchX, touchY);
    }
    else if (touchX > getSize().width - VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        switchOrganizePage(m_menuView->getNextPage(), touchX, touchY);
    }
}

void VappLauncherCosmosMmPageMenu::switchOrganizePage(VfxS32 newPage, VfxS32 touchX, VfxS32 touchY)
{
    if (getOrganizeTo().group != VCP_PAGE_MENU_GROUP_MAIN)
    {
        VFX_ASSERT(VFX_FALSE);
    }

#ifdef VAPP_LAUNCHER_COSMOS_MM_PAGE_LEFT_EXTENDABLE
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
#endif // VAPP_LAUNCHER_COSMOS_MM_PAGE_LEFT_EXTENDABLE

    scrollToPage(newPage, VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION * 2);

    m_menuView->setDraggingFramePos(touchX, touchY);

    // remove the dragging cell from the old page
    removeCellFrom(getOrganizeTo() );

    // adjust the page count if added new page
    if (m_menuView->getNearestPage() >= getPageCount() )
    {
        setPageCount(m_menuView->getNearestPage() + 1);
        m_rightExtended = VFX_TRUE;
    }

    // Use cell center to decide cell position
    VfxS32 cellCenterX = touchX + m_menuView->getOrganizeDragOffset().x + m_menuView->getDraggingFrame()->getSize().width / 2;
    VfxS32 cellCenterY = touchY + m_menuView->getOrganizeDragOffset().y + m_menuView->getDraggingFrame()->getSize().height / 2;
    
    // put the dragging cell to the new page
    VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(cellCenterX, cellCenterY), VFX_FALSE);
    if (currentDirectPos.index != MAINMENU_HITTEST_NOT_FOUND &&
        currentDirectPos.index < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT)
    {
        currentDirectPos.index = VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT;
    }
    putCellTo(currentDirectPos, m_menuView->getDraggingFrame() );

    checkUpdate();
}

void VappLauncherCosmosMmPageMenu::inPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    const VcpPageMenuCellPos currentTo = cellHittest(VfxPoint(touchX, touchY), VFX_TRUE);
        const VcpPageMenuCellPos prevOrganizeTo = getOrganizeTo();
    if (currentTo.group == prevOrganizeTo.group)
    {
        if (currentTo.index != MAINMENU_HITTEST_NOT_FOUND &&
            ((currentTo.group == VCP_PAGE_MENU_GROUP_MAIN && currentTo.index >= VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT) ||
             (currentTo.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && currentTo.index < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)))
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
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT; ++i)
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
            if (currentDirectPos.index < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)
            {
                removeCellFrom(getOrganizeTo() );

                // put the dragging cell to the new page
                putCellTo(currentDirectPos, m_menuView->getDraggingFrame() );
            }
        }
    }

    m_menuView->setAnimDirty(VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION);
    checkUpdate();
}

void VappLauncherCosmosMmPageMenu::handleOrganizePut(VfxBool isCheckUpdate)
{
    if (m_delayMovingTimer->getIsEnabled())
    {
        m_delayMovingTimer->stop();
        inPageOrganizeMove(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
    }
    
    if (m_autoScrollPageTimer->getIsEnabled())
    {
        m_autoScrollPageTimer->stop();
    }
    
    m_menuView->setAnimDirty(VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_DURATION * 2);
    m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), getOrganizeTo().group);

    putHoldFrame();
    setHover(VAPP_LAUNCHER_COSMOS_MM_NO_HOVER);
    m_menuView->setDraggingFrame(NULL);
    m_leftExtended = VFX_FALSE;
    m_rightExtended = VFX_FALSE;

    if (isCheckUpdate)
    {
        checkUpdate();
    }
}

void VappLauncherCosmosMmPageMenu::handleOrganizeEnd(VfxBool isCheckUpdate)
{
    // ensure the dragging frame is put
    handleOrganizePut(isCheckUpdate);

    compactPages(isCheckUpdate);

    if (isCheckUpdate)
    {
        checkUpdate();
    }
}

void VappLauncherCosmosMmPageMenu::putHoldFrame()
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
        // VFX_ASSERT(result);
        if (result == VFX_FALSE)
        {
            VcpPageMenuCell *cell = getHoldFrame();
            VFX_OBJ_CLOSE(cell);
            setHoldFrame(NULL);
        }
    }
}

VfxBool VappLauncherCosmosMmPageMenu::putHoldFrameAfterPage(VfxS32 page)
{
    const VfxS32 start = (page + 1) * m_menuView->getPageItemCount();
    for (VfxS32 index = start; index < VAPP_LAUNCHER_COSMOS_MM_MAX_APP; ++index)
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

VfxBool VappLauncherCosmosMmPageMenu::putHoldFrameBeforePage(VfxS32 page)
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

void VappLauncherCosmosMmPageMenu::removeCellFrom(VcpPageMenuCellPos pos)
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
        const VfxS32 pageEnd = VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT;
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

void VappLauncherCosmosMmPageMenu::putCellTo(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell * cell)
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

void VappLauncherCosmosMmPageMenu::putCellToMain(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell * cell)
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

void VappLauncherCosmosMmPageMenu::putCellToBar(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell * cell)
{
    if (currentDirectPos.index == MAINMENU_HITTEST_NOT_FOUND)
    {
        // append to the end of this bar
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT; ++i)
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
        for (VfxS32 i = VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT - 1; i > currentDirectPos.index; --i)
        {
            m_groupCells[i] = m_groupCells[i - 1];
        }
        setCell(currentDirectPos, cell);
        setOrganizeTo(currentDirectPos);
    }
}


#endif // __MMI_VUI_LAUNCHER_COSMOS__

