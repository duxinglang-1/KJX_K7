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
 *  vapp_launcher_key_page_menu.cpp
 *
 * Project:
 * --------
 *  Launcher key
 *
 * Description:
 * ------------
 *  Key launcher mainmenu
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"

#include "vfx_uc_include.h"
#include "vfx_adp_device.h"
#include "vapp_launcher_key_mainmenu_page_menu.h"
#include "vapp_launcher_key_mainmenu_builder.h"
#include "vcp_page_menu_util.h"
#include "mmi_rp_vapp_key_mainmenu_def.h"
#include "vapp_launcher_key_mainmenu.h"

#include "Wgui.h" // for MMI_STATUS_BAR_HEIGHT
#include "vcp_page_menu_transition.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C" {
#include "AppMgrSrvGprot.h"
#include "mmi_common_app_trc.h"
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif 
}


/*****************************************************************************
 * Define
 *****************************************************************************/

#define DRAWER_PAGE_LEFT_EXTENDABLE
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
static const VfxS32 DRAWER_ANIMTIME_RELEASE = 350;
static const VfxS32 DRAWER_ORGANIZE_DURATION = 350;
#endif
static const VfxS32 DRAWER_CANCEL_DURATION = 400;
static const VfxS32 DRAWER_ANIMTIME_INSTANT_3 = 3;

static const VfxS32 DRAWER_PEN_DOWN_DELAY = 200;
static const VfxS32 DRAWER_LONG_PRESS_ENTER_ORGANIZE_DELAY = 1000;
static const VfxS32 DRAWER_LONG_PRESS_ORGANIZE_ANOTHER_DELAY = 300;
static const VfxS32 DRAWER_ORGANIZE_AUTO_SCROLL_CD = 2000;
static const VfxS32 DRAWER_ORGANIZE_AUTO_SCROLL_MARGIN = 30;

static const VfxS32 DRAWER_LOAD_CELL_DELAY = 200;

static const VfxS32 DRAWER_ANIMTIME_LOOP_RELEASE = 500;
//static const VfxFloat DRAWER_ROTATION_LIMIT = 15.0f;

//static const VfxFloat DRAWER_BOUND_ROTATE_FACTOR = -0.09f;

static const VfxFloat DRAWER_EDITING_ALPHA = 0.5f;

static const VfxFloat MAINMENU_DRAGGING_SCALE = 0.8f;
static const VfxFloat VAPP_KMM_BOUND_TRANSITION_FACTOR = 0.2f;
// page indicator layout constants
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

static const VfxS32 DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT = 2;

static const VfxS32 DRAWER_INDICATOR_WIDTH = 240;
static const VfxS32 DRAWER_INDICATOR_HEIGHT = 16;
static const VfxS32 DRAWER_INDICATOR_BG_HEIGHT = 16;
static const VfxS32 DRAWER_INDICATOR_CELL_SPACING = 2; //12;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_Y = 0;
#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 DRAWER_INDICATOR_OFFSET_Y = 280;
#else
static const VfxS32 DRAWER_INDICATOR_OFFSET_Y = 360;
#endif
static const VfxS32 DRAWER_SWIPE_RANGE_THRESHOLD = 30;
static const VfxS32 DRAWER_MIDIUM_SWIPE_RANGE_THRESHOLD = 80;
static const VfxS32 DRAWER_BIG_SWIPE_RANGE_THRESHOLD = 20000; // 20000 : disable big swipe

static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_X = 5;
static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_Y = 30;
#elif defined(__MMI_MAINLCD_320X240__)

static const VfxS32 DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT = 2;

static const VfxS32 DRAWER_INDICATOR_WIDTH = 240;
static const VfxS32 DRAWER_INDICATOR_HEIGHT = 16;
static const VfxS32 DRAWER_INDICATOR_BG_HEIGHT = 16;
static const VfxS32 DRAWER_INDICATOR_CELL_SPACING = 2;//12;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 DRAWER_INDICATOR_OFFSET_Y = 200;

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
static const VfxS32 DRAWER_INDICATOR_CELL_SPACING = 2;//16;//12;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 DRAWER_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 DRAWER_INDICATOR_OFFSET_Y = 4;

static const VfxS32 DRAWER_SWIPE_RANGE_THRESHOLD = 30;
static const VfxS32 DRAWER_MIDIUM_SWIPE_RANGE_THRESHOLD = 100;
static const VfxS32 DRAWER_BIG_SWIPE_RANGE_THRESHOLD = 20000; // 20000 : disable big swipe

static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_X = 5;
static const VfxS32 DRAWER_CANCEL_HOVER_THRESHOLD_Y = 40;

#endif

#define VUI_KMM_ENTRY_ANIMATION_SHIFT_0  (10)
#define VUI_KMM_ENTRY_ANIMATION_SHIFT_1  (20)

#define VUI_KMM_ARROW_KEY_Z_LOOP 

class VcpKeyMainmenuPageMenuView : public VcpPageMenuView
{
protected:
    virtual void updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos);
};


void VcpKeyMainmenuPageMenuView::updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos)
{
#ifdef DRAWER_SHADOW_EDIT_MODE
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
#else
    VcpPageMenuView::updateCellAttribute(cell, pos);
#endif

    VappKeyMainmenuCell * mmCell = static_cast<VappKeyMainmenuCell*>(cell);
    if (mmCell == NULL)
    {
        return;
    }
    mmCell->setEditMode(getOrganizeMode() );
}

/*****************************************************************************
 * Class VappKeyMainmenuPageMenu
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappKeyMainmenuPageMenu", VappKeyMainmenuPageMenu, VfxControl);

/*****************************************************************************
 * FUNCTION
 *  VappKeyMainmenuPageMenu::VappKeyMainmenuPageMenu
 * DESCRIPTION
 *  Constructor of VappKeyMainmenuPageMenu class
 * PARAMETERS
 *
 * RETURNS
 *  *****************************************************************************/
VappKeyMainmenuPageMenu::VappKeyMainmenuPageMenu():
    m_pageCount(0),
    m_stableCurrentPageIndex(0),
    m_menuView(NULL),
    m_holdFrame(NULL),
    m_pageIndicator(NULL),
    m_delayPenDownTimer(NULL),
    m_longPressTimer(NULL),
    m_delayMovingTimer(NULL),
    m_delayLoadCellTimer(NULL),
    m_cancelOrganizationTimer(NULL),
    m_resumeMenuEffectTimer(NULL),
    m_hover(DRAWER_NO_HOVER),
    m_startPen(VFX_FALSE),
    m_canScroll(VFX_FALSE),
    m_translateOrigX(0),
    m_showMenuItems(VFX_FALSE),
    m_enableMenuAnim(VFX_TRUE),
    m_updateCount(0),
    m_highlightIndex(0),
    m_organizeMode(VFX_FALSE),
    m_organizeTo(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_delayPenDownCellPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_delayMovingTo(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_lastAutoScrollTime(0),
    m_leftExtended(VFX_FALSE),
    m_rightExtended(VFX_FALSE),
	m_isHidden(VFX_FALSE),
	m_isAmiation(VFX_FALSE),
    m_suspendWallpaperCount(0),
	m_container(NULL)
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++i)
    {
        m_cells[i] = NULL;
    }
}

void VappKeyMainmenuPageMenu::onHighlightTimer(VfxTimer *source)
{
	static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->startScroll();
	VFX_OBJ_CLOSE(source);
}

void VappKeyMainmenuPageMenu::onInit()
{
    VfxControl::onInit();

    vcpPageMenuApplyFrameRenderHints(this);
    
    VFX_OBJ_CREATE(m_menuView, VcpKeyMainmenuPageMenuView, this);
    m_menuView->setClipMargin(0);

    VFX_OBJ_CREATE(m_pageIndicator, VcpPageMenuIndicator, this);
    m_pageIndicator->setAnchor(0.5f, 0.0f);

	VFX_OBJ_CREATE(m_container, VfxFrame, this);

    // initial the page indicator
    VcpPageMenuIndicatorLayout indicatorLayout;
    indicatorLayout.indicatorWidthBase = DRAWER_INDICATOR_WIDTH;
    indicatorLayout.indicatorWidthIncrement = 0;
    indicatorLayout.indicatorHeight = DRAWER_INDICATOR_HEIGHT;
    indicatorLayout.bgOffsetY = 0;
    indicatorLayout.bgHeight = DRAWER_INDICATOR_BG_HEIGHT;
	VfxImageSrc highlightDot(IMG_ID_VAPP_KMM_INDICATOR_DOT_H);
	VfxImageSrc normalDot(IMG_ID_VAPP_KMM_INDICATOR_DOT_N);
    indicatorLayout.cellSpacing = normalDot.getSize().width + DRAWER_INDICATOR_CELL_SPACING;
    indicatorLayout.cellOffsetX = DRAWER_INDICATOR_CELL_OFFSET_X;
    indicatorLayout.cellOffsetY = DRAWER_INDICATOR_CELL_OFFSET_Y;
    indicatorLayout.cellWidth = normalDot.getSize().width;
    indicatorLayout.cellHeight = normalDot.getSize().height;
    
    indicatorLayout.cellHighlightWidth = highlightDot.getSize().width;
    indicatorLayout.cellHighlightHeight = highlightDot.getSize().height;
  //  m_pageIndicator->setBgImage(VfxImageSrc(IMG_ID_VAPP_KMM_INDICATOR_BG) );
    m_pageIndicator->setCellImage(normalDot,highlightDot);
    m_pageIndicator->setLayout(indicatorLayout);

    updatePageIndicatorPos();
    //m_pageIndicator->m_pageSelected.connect(this, &VappKeyMainmenuPageMenu::onPageIndicatorSelected);

    VFX_OBJ_CREATE(m_delayPenDownTimer, VfxTimer, this);
    m_delayPenDownTimer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onDelayPenDownTimerTick);

    VFX_OBJ_CREATE(m_longPressTimer, VfxTimer, this);
    m_longPressTimer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onLongPressTimerTick);

    VFX_OBJ_CREATE(m_delayMovingTimer, VfxTimer, this);
    m_delayMovingTimer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onDelayMovingTimerTick);

    VFX_OBJ_CREATE(m_delayLoadCellTimer, VfxTimer, this);
    m_delayLoadCellTimer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onDelayLoadCellTimerTick);
    m_delayLoadCellTimer->setStartDelay(DRAWER_LOAD_CELL_DELAY);
    m_delayLoadCellTimer->start();

	VFX_OBJ_CREATE(m_cancelOrganizationTimer, VfxTimer, this);
	m_cancelOrganizationTimer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onCancelTimerTick);
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	VFX_OBJ_CREATE(m_resumeMenuEffectTimer, VfxTimer, this);
	m_resumeMenuEffectTimer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onResumeMenuEffectTimerTick);
#endif    
	VFX_OBJ_CREATE(m_resumeWallpaperTimer, VfxTimer, this);
	m_resumeWallpaperTimer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onResumeWallpaperTimerTick);
	registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_UP);
    registerKeyHandler(VFX_KEY_CODE_ARROW_DOWN);
	registerKeyHandler(VFX_KEY_CODE_END);
    VfxTimer *timer;
	VFX_OBJ_CREATE(timer, VfxTimer, this);
	timer->setStartDelay(ENTRY_HIGHLIGHT_START);
	timer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onHighlightTimer);
	timer->start();
    checkUpdate();
}
void VappKeyMainmenuPageMenu::setHidden(VfxBool value)
{
	m_isHidden = value;
	if(value)
		m_isAmiation = VFX_FALSE;
}
void VappKeyMainmenuPageMenu::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    m_menuView->setSize(value.size.width, value.size.height );

    updatePageIndicatorPos();
}

void VappKeyMainmenuPageMenu::setMenuItem(VfxS32 index, VcpPageMenuCell * cell)
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

void VappKeyMainmenuPageMenu::clearAllMenuItems()
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++i)
    {
        if (m_cells[i])
        {
            VFX_OBJ_CLOSE(m_cells[i]);
        }
    }
}

void VappKeyMainmenuPageMenu::setHighlightIndex(VfxS32 index, VfxBool isUpdate)
{
	if(m_cells[index] == NULL)
	{
		while(index > 0)
		{
			if(m_cells[index] != NULL)
				break;
			index--;
		}
	}
	m_highlightIndex = index;
	static_cast<VappKeyMainmenuCell*>(m_cells[index])->setIsHighlighted(VFX_TRUE, isUpdate);
	m_highlightChanged.postEmit(m_cells[m_highlightIndex]);
}

VfxS32 VappKeyMainmenuPageMenu::getHighlightIndex()
{
	return m_highlightIndex;
}
void VappKeyMainmenuPageMenu::setCellIconSize(const VfxSize & size)
{
    m_menuView->setCellIconSize(size);
}

VcpPageMenuCell * VappKeyMainmenuPageMenu::getMenuItem(VfxS32 index) const
{
    return m_cells[index];
}

VfxS32 VappKeyMainmenuPageMenu::getMaxPageCount() const
{
    return m_menuView->getMaxPageCount(VAPP_LAUNCHER_KEY_MM_MAX_CELL);
}

VfxS32 VappKeyMainmenuPageMenu::getMenuItemCountPerPage() const
{
    return m_menuView->getPageItemCount();
}

VfxS32 VappKeyMainmenuPageMenu::getMenuItemCountPerGroup() const
{
    return 16;
}

VfxS32 VappKeyMainmenuPageMenu::getCurrentPageIndex() const
{
    return m_menuView->getNearestPage();
}

void VappKeyMainmenuPageMenu::setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated)
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

const VcpPageMenuLayout & VappKeyMainmenuPageMenu::getMenuLayout() const
{
    return m_menuView->getLayout();
}

void VappKeyMainmenuPageMenu::setMenuLayout(const VcpPageMenuLayout & layout)
{
	m_container->setPos(layout.cellStartX, layout.cellStartY);
	m_container->setSize(layout.cellOffsetX * layout.columnCount, layout.cellOffsetY * layout.rowCount);
	m_container->setCacheMode(VFX_CACHE_MODE_PREVENT);
	VcpPageMenuLayout new_layout = layout;
	new_layout.cellStartY = 0;
    m_menuView->setLayout(new_layout);
    updatePageIndicatorPos();
}

void VappKeyMainmenuPageMenu::cancelOrganization()
{
    if (!getOrganizeMode() )
    {
        return;
    }
	VcpPageMenuCell *highlightCell = m_cells[m_highlightIndex];
	
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++i)
    {
		m_cells[i] = m_backupCells[i];
		if(highlightCell == m_backupCells[i])
			m_highlightIndex = i;
    }
	m_pageCount = m_backupPageCount; // restore old page count;
	compactPages(VFX_TRUE);
	
    setOrganizeMode(VFX_FALSE);
	setHover(DRAWER_NO_HOVER);
	MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_0);
    m_organizationChanged.postEmit(VFX_FALSE);
	scrollToPage(m_highlightIndex/m_menuView->getPageItemCount(),DRAWER_ORGANIZE_DURATION,VFX_TRUE);
	m_menuView->update(m_cells, VAPP_LAUNCHER_KEY_MM_MAX_CELL, NULL, 0);
	m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
	m_cancelOrganizationTimer->setStartDelay(DRAWER_CANCEL_DURATION);
	m_cancelOrganizationTimer->start();
	checkUpdate();

}
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
void VappKeyMainmenuPageMenu::setTransitionEffect(VcpPageMenuTransitionType transitionType)
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
void VappKeyMainmenuPageMenu::leaveOrganizationMode(VfxBool isCheckUpdate)
{
    if (!getOrganizeMode() )
    {
        return;
    }
	VcpPageMenuCell *highlightCell = m_cells[m_highlightIndex];
	

    handleOrganizeEnd(isCheckUpdate);
    // set organized state
    setOrganizeMode(VFX_FALSE);
	if(isCheckUpdate == VFX_FALSE)
	m_suspendWallpaper.emit(VFX_FALSE);
	MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_1);

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++i)
    {
		if(highlightCell == m_cells[i])
		{
			m_highlightIndex = i;
			break;
		}
    }
	scrollToPage(m_highlightIndex/m_menuView->getPageItemCount(),DRAWER_ORGANIZE_DURATION,VFX_TRUE);
    m_organizationChanged.postEmit(VFX_FALSE);
	if(isCheckUpdate == VFX_TRUE) // press csk / lsk
	{
	    m_cancelOrganizationTimer->setStartDelay(DRAWER_CANCEL_DURATION);
	    m_cancelOrganizationTimer->start();
	}

}

void VappKeyMainmenuPageMenu::forceDirty()
{
    m_menuView->forceDirty();
    checkUpdate();
}

void VappKeyMainmenuPageMenu::showEntryAnim()
{
	VfxS32 currPage = getCurrentPageIndex();

	VfxS32 firstIndex = currPage * m_menuView->getPageItemCount();

	VfxAutoAnimate::initAnimateBegin();
	VfxAutoAnimate::begin(); 
	VfxAutoAnimate::setDisable(VFX_TRUE);//(ENTRY_ANIM_DURATION/2);
	for(VfxS32 index = firstIndex; index < firstIndex + m_menuView->getPageItemCount(); index ++)
	{
		// avoid fpe show
		if(m_cells[index] == NULL)
			break;
		VfxS32 pageLevel = m_menuView->getPageLevel();
		m_cells[index]->setCellGroup(VCP_PAGE_MENU_GROUP_ANIM);
		//m_menuView->changeCellGroup(m_cells[index], VCP_PAGE_MENU_GROUP_ANIM);
		//m_cells[index]->changeCellGroup(VCP_PAGE_MENU_GROUP_ANIM);
		VfxS32 x = index % m_menuView->getLayout().columnCount * m_menuView->getLayout().cellOffsetX + m_menuView->getLayout().cellStartX;
		VfxS32 y = (index % m_menuView->getPageItemCount() ) / m_menuView->getLayout().columnCount * m_menuView->getLayout().cellOffsetY + m_menuView->getLayout().cellStartY;
		VfxS32 row = (index % m_menuView->getPageItemCount() ) / m_menuView->getLayout().columnCount;
#if defined(__MMI_MAINLCD_240X400__)
		if(row == 0)
		{
			y += VUI_KMM_ENTRY_ANIMATION_SHIFT_1;
		}
		else if(row == 1)
		{
			y +=VUI_KMM_ENTRY_ANIMATION_SHIFT_0;
		}
		else if(row == 2)
		{
			y = y;
		}
		else if(row ==3)
		{
			y -=VUI_KMM_ENTRY_ANIMATION_SHIFT_0;
		}
		else  // row == 4
		{
			y -= VUI_KMM_ENTRY_ANIMATION_SHIFT_1;
		}
#else
		if(row == 0)
		{
			y += VUI_KMM_ENTRY_ANIMATION_SHIFT_1;
		}
		else if(row == 1)
		{
			y +=VUI_KMM_ENTRY_ANIMATION_SHIFT_0;
		}
		else if (row == 2)
		{
			y -=VUI_KMM_ENTRY_ANIMATION_SHIFT_0;
		}
		else // row == 3
		{
			y -= VUI_KMM_ENTRY_ANIMATION_SHIFT_1;
		}
#endif
		m_cells[index]->setPos(x,y);
		m_cells[index]->setOpacity(0.1f);
		m_cells[index]->setAutoAnimate(VFX_TRUE);  	
	}

	VfxAutoAnimate::setDisable(VFX_FALSE);//(ENTRY_ANIM_DURATION/2);
	VfxAutoAnimate::setDuration(ENTRY_ANIM_DURATION/2);
	for(VfxS32 index = firstIndex; index < firstIndex + m_menuView->getPageItemCount(); index++)
	{
		if(m_cells[index] == NULL)
			break;
		VfxS32 pageLevel = m_menuView->getPageLevel();
		VfxS32 x = index % m_menuView->getLayout().columnCount * m_menuView->getLayout().cellOffsetX + m_menuView->getLayout().cellStartX;
		VfxS32 y = (index % m_menuView->getPageItemCount() ) / m_menuView->getLayout().columnCount * m_menuView->getLayout().cellOffsetY + m_menuView->getLayout().cellStartY;
		VfxS32 row = (index % m_menuView->getPageItemCount() ) / m_menuView->getLayout().columnCount;
#if defined(__MMI_MAINLCD_240X400__)		
		if(row == 1 || row == 3)
		{
			m_cells[index]->setPos(x, y);
			m_cells[index]->setOpacity(1.0f);

		}
		if(row == 2)
		{
			m_cells[index]->setOpacity(1.0f);
		}
#else
		if(row == 1 || row == 2)
		{
			m_cells[index]->setPos(x, y);
			m_cells[index]->setOpacity(1.0f);

		}
#endif
	}
	VfxAutoAnimate::commit();	 
	VfxAutoAnimate::initAnimateEnd();
	
	VfxAutoAnimate::initAnimateBegin();
	VfxAutoAnimate::begin(); 
	VfxAutoAnimate::setDuration(ENTRY_ANIM_DURATION);
	VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
	for(VfxS32 index = firstIndex; index < firstIndex + m_menuView->getPageItemCount(); index++)
	{
		if(m_cells[index] == NULL)
			break;
		VfxS32 pageLevel = m_menuView->getPageLevel();
		VfxS32 x = index % m_menuView->getLayout().columnCount * m_menuView->getLayout().cellOffsetX + m_menuView->getLayout().cellStartX;
		VfxS32 y = (index % m_menuView->getPageItemCount() ) / m_menuView->getLayout().columnCount * m_menuView->getLayout().cellOffsetY + m_menuView->getLayout().cellStartY;
		VfxS32 row = (index % m_menuView->getPageItemCount() ) / m_menuView->getLayout().columnCount;
#if defined(__MMI_MAINLCD_240X400__)	
		if(row == 0 || row == 4)
		{
			m_cells[index]->setPos(x, y);
			m_cells[index]->setOpacity(1.0f);

		}
#else
		if(row == 0 || row == 3)
		{
			m_cells[index]->setPos(x, y);
			m_cells[index]->setOpacity(1.0f);

		}
#endif
	}
	VfxAutoAnimate::commit();	 
	VfxAutoAnimate::initAnimateEnd();
	m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
	m_isAmiation = VFX_TRUE;
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(ENTRY_ANIM_DURATION);
    timer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onEntryAnimTimer);
    timer->start();
}

void VappKeyMainmenuPageMenu::onEntryAnimTimer(VfxTimer *source)
{
	VfxS32 currPage = getCurrentPageIndex();

	VfxS32 firstIndex = currPage * m_menuView->getPageItemCount();
	for(VfxS32 index = firstIndex; index < firstIndex + m_menuView->getPageItemCount(); index++)
	{
		if(m_cells[index] == NULL)
			break;
		m_cells[index]->setCellGroup(VCP_PAGE_MENU_GROUP_MAIN);
		//m_cells[index]->changeCellGroup(VCP_PAGE_MENU_GROUP_MAIN);
		//m_menuView->changeCellGroup(m_cells[index], VCP_PAGE_MENU_GROUP_MAIN);
	}
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	setTransitionEffect(VappKeyMainmenu::m_animType);
#endif
	m_suspendWallpaper.emit(VFX_FALSE);
	m_isAmiation = VFX_FALSE;
	VFX_OBJ_CLOSE(source);
}

void VappKeyMainmenuPageMenu::showMenuItems(VfxBool isAnim)
{
    if (!m_showMenuItems)
    {
        m_showMenuItems = VFX_TRUE;
		if(isAnim)
		{
			m_suspendWallpaper.emit(VFX_TRUE);
		    showEntryAnim();
			forceDirty();
		}
        checkUpdate();
    }
	else if(isAnim)
	{
		m_suspendWallpaper.emit(VFX_TRUE);
		showEntryAnim();
		forceDirty();
	}
}

void VappKeyMainmenuPageMenu::registerCellEvent()
{
	VfxTimer *timer;
	VFX_OBJ_CREATE(timer, VfxTimer, this);
	timer->setStartDelay(ENTRY_ANIM_DURATION);
	timer->m_signalTick.connect(this, &VappKeyMainmenuPageMenu::onRegisterBadgeTimer);
	timer->start();
}

void VappKeyMainmenuPageMenu::onRegisterBadgeTimer(VfxTimer *source)
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++i)
    {
		if(m_cells[i])
			static_cast<VappKeyMainmenuCell*>(m_cells[i])->registerBadgeEvent();
    }

	VFX_OBJ_CLOSE(source);
}

void VappKeyMainmenuPageMenu::setEnableMenuAnim(VfxBool enable)
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

void VappKeyMainmenuPageMenu::onUpdate()
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
        if (currentPageIndex + 1 > indicatorPageCount && currentPageIndex < m_menuView->getMaxPageCount(VAPP_LAUNCHER_KEY_MM_MAX_CELL) )
        {
            indicatorPageCount = currentPageIndex + 1;
        }
        m_pageIndicator->setIndicatorPageCount(indicatorPageCount);
        m_pageIndicator->update();


        ++m_updateCount;
        if (m_updateCount == 2)
        {
            // set force cache on the 2nd time onUpdate()
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++i)
            {
                if (m_cells[i] != NULL)// && (m_organizeMode == VFX_FALSE))
                {
                    m_cells[i]->setCacheMode(VFX_CACHE_MODE_FORCE);
                }
            }
        }

        if (m_showMenuItems)
        {
            m_menuView->update(m_cells, VAPP_LAUNCHER_KEY_MM_MAX_CELL, NULL, 0);
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOU", SA_stop);
#endif
}

void VappKeyMainmenuPageMenu::onDelayPenDownTimerTick(VfxTimer *source)
{
    setHover(m_delayPenDownCellPos);
	
	if(m_delayPenDownCellPos.index != -1)
	{
		static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->setIsHighlighted(VFX_FALSE, VFX_TRUE);
		setHighlightIndex(m_delayPenDownCellPos.index, VFX_TRUE);
	}
    checkUpdate();
}

void VappKeyMainmenuPageMenu::entryOrganization()
{
	setOrganizeMode(VFX_TRUE);
	m_suspendWallpaper.emit(VFX_TRUE);
	MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_0);
	m_organizationChanged.postEmit(VFX_TRUE);
	m_startPen = VFX_FALSE;
	setHover(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, m_highlightIndex));
	handleOrganizeStart(VFX_FALSE);
	
	m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);

}

void VappKeyMainmenuPageMenu::onLongPressTimerTick(VfxTimer *source)
{
    if (getHover().index == MAINMENU_HITTEST_NOT_FOUND)
    {
        return;
    }

    if (getOrganizeMode() )
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
        
        m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
        handleOrganizeStart(VFX_TRUE);
        checkUpdate();
    }
    else
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
        
        setOrganizeMode(VFX_TRUE);
		m_suspendWallpaper.emit(VFX_TRUE);
		MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_1);
        m_organizationChanged.postEmit(VFX_TRUE);
        m_startPen = VFX_FALSE;

        handleOrganizeStart(VFX_TRUE);

        m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
    }
}

void VappKeyMainmenuPageMenu::onDelayMovingTimerTick(VfxTimer *source)
{
    inPageOrganizeMove(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
}

void VappKeyMainmenuPageMenu::onDelayLoadCellTimerTick(VfxTimer *source)
{
    VfxS32 prevPageStartIndex = (getCurrentPageIndex() - 1) * getMenuItemCountPerPage();
    VfxBool needCachePrevPage = VFX_TRUE;
    if (getCurrentPageIndex() == 0 ||
        m_cells[prevPageStartIndex] == NULL ||
        static_cast<VappKeyMainmenuCell*>(m_cells[prevPageStartIndex])->isFirstDisplay() == VFX_FALSE)
    {
        needCachePrevPage = VFX_FALSE;
    }
    
    VfxS32 nextPageStartIndex = (getCurrentPageIndex() + 1) * getMenuItemCountPerPage();
    VfxBool needCacheNextPage = VFX_TRUE;
    if (getCurrentPageIndex() == (getMaxPageCount() - 1) ||
        m_cells[nextPageStartIndex] == NULL ||
        static_cast<VappKeyMainmenuCell*>(m_cells[nextPageStartIndex])->isFirstDisplay() == VFX_FALSE)
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
            opacityTl->m_signalStopped.connect(this, &VappKeyMainmenuPageMenu::onTimelineStop);
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
            opacityTl->m_signalStopped.connect(this, &VappKeyMainmenuPageMenu::onTimelineStop);
            opacityTl->start();
        }
    }
}

void VappKeyMainmenuPageMenu::onCancelTimerTick(VfxTimer *source)
{
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	setTransitionEffect(VappKeyMainmenu::m_animType);
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	m_suspendWallpaper.emit(VFX_FALSE);
}

#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
void VappKeyMainmenuPageMenu::onResumeMenuEffectTimerTick(VfxTimer *source)
{
	setTransitionEffect(VappKeyMainmenu::m_animType);
}

#endif

void VappKeyMainmenuPageMenu::onResumeWallpaperTimerTick(VfxTimer *source)
{
	MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_6, m_suspendWallpaperCount);
	while(m_suspendWallpaperCount)
	{
		m_suspendWallpaperCount--;
		m_suspendWallpaper.emit(VFX_FALSE);
	}
	static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->startScroll(); // ppp

}

void VappKeyMainmenuPageMenu::onPageIndicatorSelected(VfxS32 pageSelected)
{
    scrollToPage(pageSelected, DRAWER_ANIMTIME_RELEASE);
}

void VappKeyMainmenuPageMenu::onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    VFX_OBJ_CLOSE(timeline);
}

VfxBool VappKeyMainmenuPageMenu::onPenInput(VfxPenEvent &event)
{
    // default animation parameters
	if(m_isAmiation)
		return VfxControl::onPenInput(event);
    m_menuView->setDragOnIndicator(VFX_FALSE);

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
		m_suspendWallpaper.emit(VFX_TRUE);
		//VAPP_KEYLAUNCHER_LOG(TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_2);
		MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_2);

        return handlePenDown(event.getRelPos(this) );
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        // long tap is ignored, VappKeyMainmenuPageMenu handle long tap behavior itself
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

VfxS32 VappKeyMainmenuPageMenu::getPageIndex(VfxS32 index)
{
	return index / m_menuView->getPageItemCount();
}

VfxS32 VappKeyMainmenuPageMenu::findNextHighlightIndex(VfxKeyEvent &event)
{
	switch (event.keyCode)
	{
		case VFX_KEY_CODE_ARROW_LEFT :
		{
			VfxS32 index = -1;
			#if defined(VUI_KMM_ARROW_KEY_Z_LOOP)
			if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				VfxS32 pageItemCount = m_menuView->getPageItemCount();
				VfxS32 pre_count = (m_stableCurrentPageIndex - 0) * pageItemCount;

				VfxS32 column = (m_highlightIndex - pre_count) % getMenuLayout().columnCount;
				VfxS32 row = (m_highlightIndex - pre_count) / getMenuLayout().columnCount;
					
				if(column == 0)
				{
					if(m_stableCurrentPageIndex == 0)
					{
						VfxS32 start_index = m_menuView->getPageItemCount() * (getPageCount() - 1);
						while(start_index < VAPP_LAUNCHER_KEY_MM_MAX_CELL && m_cells[start_index] != NULL)
						{
							start_index++;
						}
					  index = start_index - 1;

						return index;
					}
					else
					{
						VfxS32 item_index = (m_stableCurrentPageIndex-1) * m_menuView->getPageItemCount();
						for(index = item_index + (row+1) *getMenuLayout().columnCount - 1; index >= 0; index--)
						{
							if(m_cells[index] != NULL)
								return index;
						}
							
					}
				}
				else
				{
					return m_highlightIndex - 1;
				}

			}
			#else /*defined(VUI_KMM_ARROW_KEY_Z_LOOP) */
			if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				index = m_highlightIndex - 1;

				while(index > -1)
				{
					if(m_cells[index] != NULL)
						break;
					index--;
				}
				if(m_highlightIndex == 0) // loop to last items
				{
					VfxS32 start_index = m_menuView->getPageItemCount() * (getPageCount() - 1);
					while(start_index < VAPP_LAUNCHER_KEY_MM_MAX_CELL && m_cells[start_index] != NULL)
					{
						start_index++;
					}
					index = start_index - 1;
				}
			}
			#endif /* defined(VUI_KMM_ARROW_KEY_Z_LOOP) */
			if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
			{
				if(getPageIndex(m_highlightIndex) == 0)
					index = -1;
				else
				{
					if(m_cells[m_highlightIndex - m_menuView->getPageItemCount()] != NULL)
					{
						index = m_highlightIndex - m_menuView->getPageItemCount();
					}
					else // find nearst item
					{
						VfxS32 start_index = m_menuView->getPageItemCount() * (getPageIndex(m_highlightIndex) - 1);
						VfxS32 end_index = m_highlightIndex - m_menuView->getPageItemCount();
						index = start_index;
						for(index = end_index; index >= start_index; index--)
						{
							if(m_cells[index] != NULL)
								break;
						}
					}
				}
			}
			return index;	
		}
		
		case VFX_KEY_CODE_ARROW_RIGHT :
		{
			VfxS32 index = -1;
			#if defined(VUI_KMM_ARROW_KEY_Z_LOOP)
			if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				VfxS32 pageItemCount = m_menuView->getPageItemCount();
				VfxS32 pre_count = (m_stableCurrentPageIndex - 0) * pageItemCount;

				VfxS32 column = (m_highlightIndex - pre_count) % getMenuLayout().columnCount;
				VfxS32 row = (m_highlightIndex - pre_count) / getMenuLayout().columnCount;
					
				if(column == getMenuLayout().columnCount - 1 || \
					m_cells[m_highlightIndex + 1] == NULL)
				{
					if(m_stableCurrentPageIndex == getPageCount() - 1)
					{
					   // if(row == getMenuLayout().rowCount - 1)
							index = 0;
						  return index;
					}
					else
					{
						for(VfxS32 i = row; i >= 0; i--)
						{
							index = (m_stableCurrentPageIndex + 1) * pageItemCount + i*getMenuLayout().columnCount;
							if(m_cells[index] != NULL)
								return index;
						}
							
					}
				}
				else
				{
					return m_highlightIndex + 1;
				}

			}
			#else /* defined(VUI_KMM_ARROW_KEY_Z_LOOP) */
			if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				index = m_highlightIndex + 1;

				while(index < VAPP_LAUNCHER_KEY_MM_MAX_CELL)
				{
					if(m_cells[index] != NULL)
						break;
					index++;
				}
				if(index == VAPP_LAUNCHER_KEY_MM_MAX_CELL)
				{
					//index = -1;
					index = 0; // loop to the first index.
				}
			}
			#endif /* defined(VUI_KMM_ARROW_KEY_Z_LOOP) */
			if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
			{
				if(getPageIndex(m_highlightIndex) == getPageCount() - 1)
					index = -1;
				else
				{
					if(m_cells[m_highlightIndex + m_menuView->getPageItemCount()] != NULL)
					{
						index = m_highlightIndex + m_menuView->getPageItemCount();
					}
					else
					{
						VfxS32 start_index = m_menuView->getPageItemCount() * (getPageIndex(m_highlightIndex) + 1);
						VfxS32 end_index = m_highlightIndex + m_menuView->getPageItemCount();
						index = start_index;
						for(index = end_index; index >= start_index; index--)
						{
							if(m_cells[index] != NULL)
								break;
						}
					}
				}
			}

			return index;
		}
		case VFX_KEY_CODE_ARROW_UP :
		{
			VfxS32 index = -1;
			if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				VfxS32 pageItemCount = m_menuView->getPageItemCount();
				VfxS32 pre_count = (m_stableCurrentPageIndex - 0) * pageItemCount;

				if((m_highlightIndex - pre_count) / getMenuLayout().columnCount > 0)
					index = m_highlightIndex - getMenuLayout().columnCount;
				else
				{
					index = m_highlightIndex ;
					while(m_cells[index + getMenuLayout().columnCount] != NULL)
					{
						index += getMenuLayout().columnCount;
						if(index - m_highlightIndex >= pageItemCount)
						{
							index -= getMenuLayout().columnCount;
							break;
						}
					}
					if(index == m_highlightIndex)
						index = -1;
				}
			}
			else if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
			{
				VfxS32 pageItemCount = m_menuView->getPageItemCount();
				VfxS32 pre_count = (m_stableCurrentPageIndex - 0) * pageItemCount;

				if((m_highlightIndex - pre_count) / getMenuLayout().columnCount > 0)
					index = m_highlightIndex - getMenuLayout().columnCount;
				else
					index = -1;
			}
			return index;

		}
		case VFX_KEY_CODE_ARROW_DOWN :
		{
			VfxS32 index = -1;
			if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				VfxS32 pageItemCount = m_menuView->getPageItemCount();
				VfxS32 pre_count = (m_stableCurrentPageIndex - 0) * pageItemCount;

				if((m_cells[m_highlightIndex + getMenuLayout().columnCount] != NULL) && \
					((m_highlightIndex + getMenuLayout().columnCount) < pre_count + pageItemCount))
				{
					index = m_highlightIndex + getMenuLayout().columnCount;
				}
				else if(m_highlightIndex >= pre_count + getMenuLayout().columnCount)
				{
					index = pre_count +  (m_highlightIndex-pre_count)%getMenuLayout().columnCount;
				}
			}
			else if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
			{
				VfxS32 pageItemCount = m_menuView->getPageItemCount();
				VfxS32 pre_count = (m_stableCurrentPageIndex - 0) * pageItemCount;

				if((m_cells[m_highlightIndex + getMenuLayout().columnCount] != NULL) && \
						((m_highlightIndex + getMenuLayout().columnCount) < pre_count + pageItemCount))
				{
					index = m_highlightIndex + getMenuLayout().columnCount;
				}
				else
				{
					index = -1;
				}
			}
			return index;

		}	
		default:
				return -1;
	}
}

VfxBool VappKeyMainmenuPageMenu::changeHighlightIndex(VfxS32 nextHighlightIndex)
{
	VfxBool isPageChange = VFX_FALSE;
	VfxS32 pageItemCount = m_menuView->getPageItemCount();

	if(nextHighlightIndex != -1)
	{
		if(getPageIndex(nextHighlightIndex) != m_stableCurrentPageIndex)
			isPageChange = VFX_TRUE;
		if(isPageChange)
			m_cells[nextHighlightIndex]->onCellDisplay();
		static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->setIsHighlighted(VFX_FALSE, VFX_TRUE); 
		setHighlightIndex(nextHighlightIndex, VFX_TRUE);// avoid delayloadcell timer is not come
	//	if(getPageIndex(nextHighlightIndex) != m_stableCurrentPageIndex)
	//		isPageChange = VFX_TRUE;

		checkUpdate();
	}
	return isPageChange;

}

void VappKeyMainmenuPageMenu::swapCell(VfxS32 index1, VfxS32 index2)
{
  	VcpPageMenuCell *highlight_cell = m_cells[index1];
	VcpPageMenuCellPos next_pos(VCP_PAGE_MENU_GROUP_MAIN, index2);
	VcpPageMenuCellPos pos(VCP_PAGE_MENU_GROUP_MAIN, index1);

	setCell(pos, m_cells[index2]);
	setCell(next_pos, highlight_cell);
}

void VappKeyMainmenuPageMenu::reorderByLeftArrowKey()
{
	VfxS32 index = m_highlightIndex - 1;
	VfxS32 curr_page = m_stableCurrentPageIndex;

	if(getPageIndex(m_highlightIndex) != m_stableCurrentPageIndex)
	{
		// back to highlight item first
		scrollToPage(getPageIndex(m_highlightIndex), DRAWER_ANIMTIME_RELEASE);
		return;
	}

	while(index > -1)
	{
		if(m_cells[index] != NULL)
			break;
		index--;
	}
#ifdef DRAWER_PAGE_LEFT_EXTENDABLE
	if(m_highlightIndex == 0) // first index, need add new page
	{
		if(getPageCount()== getMaxPageCount())
		{
			return; // page reach max count
		}

		if(m_cells[m_highlightIndex+1] == NULL)
		{
			return; // only 1 item in current page.
		}

		VcpPageMenuCell *cell = m_cells[0];
		VfxS32 cell_index;

		for(cell_index = 0; cell_index < m_menuView->getPageItemCount() - 1; cell_index++)
		{
			m_cells[cell_index] = m_cells[cell_index + 1];   // let index move to preivous in first page.
		}
		m_cells[cell_index] = NULL;
		setPageCount(getPageCount() + 1); // add one page
		for(VfxS32 page = getPageCount() - 1; page > 0; page --)
		{
			VfxS32 cell_index = page*m_menuView->getPageItemCount();
			for(VfxS32 i = 0; i <m_menuView->getPageItemCount(); i++)
			{
				m_cells[cell_index] = m_cells[cell_index - m_menuView->getPageItemCount()];
				cell_index ++;
			}
		}
		for(VfxS32 i = 0; i < m_menuView->getPageItemCount(); i++)
		{
			m_cells[i] = NULL;
		}
		m_cells[0] = cell;
		setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN,m_highlightIndex));
		m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
		checkUpdate();
		return;
	}
#endif
	if(index == -1 && curr_page == 0)
	{
	 	return;
	}
	if(index == m_highlightIndex - 1)
	{
		swapCell(index, m_highlightIndex);
		m_highlightIndex = index;
		if(m_cells[index+1] == 0)
			compactPages(VFX_FALSE);
		m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
		checkUpdate();
	}
	else // page change & has empty cell between the two cells
	{
		VfxS32 new_index = index + 1; 
		if(getPageIndex(m_highlightIndex) - getPageIndex(index) > 1)
		{	
			new_index = m_highlightIndex - m_menuView->getPageItemCount();  // previous page is empty
		}
		m_cells[new_index] = m_cells[m_highlightIndex];
		VfxS32 temp_index;
		for(temp_index =  m_highlightIndex; temp_index < m_highlightIndex + m_menuView->getPageItemCount() - 1; temp_index++)
		{
			m_cells[temp_index] = m_cells[temp_index + 1]; // move 1 index after highlight item
		}
		m_cells[temp_index] = NULL;
		m_highlightIndex = new_index;
	}
	setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN,m_highlightIndex));
	if(curr_page != getPageIndex(m_highlightIndex))
		scrollToPage(getPageIndex(m_highlightIndex), DRAWER_ANIMTIME_RELEASE);
	return;
}

void VappKeyMainmenuPageMenu::reorderByRightArrowKey()
{
	VfxS32 index = m_highlightIndex + 1;
	if(m_highlightIndex == VAPP_LAUNCHER_KEY_MM_MAX_CELL - 1)
		return;
	if(getPageIndex(m_highlightIndex) != m_stableCurrentPageIndex)
	{
		// back to highlight item first
		scrollToPage(getPageIndex(m_highlightIndex), DRAWER_ANIMTIME_RELEASE);
		return;
	}

	if((m_cells[index] != NULL) && (getPageIndex(index) == getPageIndex(m_highlightIndex)))
	{
		swapCell(index, m_highlightIndex);
		m_highlightIndex = index;
		setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN,m_highlightIndex));
		m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
		checkUpdate();
		return;
	}

	if(m_highlightIndex == (m_stableCurrentPageIndex  * m_menuView->getPageItemCount() )&& (m_cells[index] == NULL) && (getPageCount()== m_stableCurrentPageIndex+1))
	{
		return;  // last page, only one item
	}
	const VfxS32 start = (m_stableCurrentPageIndex + 1) * m_menuView->getPageItemCount();

	for (VfxS32 index = start; index < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++index)
    {
        if (m_cells[index] == NULL)
        {
            const VfxS32 end = index;
            for (VfxS32 i = end; i > start; --i)
            {
                m_cells[i] = m_cells[i - 1];
            }
            m_cells[start] = m_cells[m_highlightIndex];
			m_cells[m_highlightIndex] = NULL;
			m_highlightIndex = start;
			setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN,m_highlightIndex));
            if (end + 1 > getPageCount() * m_menuView->getPageItemCount() )
            {
                setPageCount(getPageCount() + 1);
            }
			scrollToPage(getPageIndex(m_highlightIndex), DRAWER_ANIMTIME_RELEASE);
            return;
        }
    }
}

void VappKeyMainmenuPageMenu::reorderByUpArrowKey(VfxKeyEvent &event)
{
	VfxS32 index = -1;
	VfxS32 pageItemCount = m_menuView->getPageItemCount();
	VfxS32 pre_count = (m_stableCurrentPageIndex - 0) * pageItemCount;

	if((m_highlightIndex - pre_count) / getMenuLayout().columnCount > 0)
		index = m_highlightIndex - getMenuLayout().columnCount;
	else
	{
		if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
			return; // stop if reach first line.
		index = m_highlightIndex ;
		while(m_cells[index + getMenuLayout().columnCount] != NULL)
		{
			index += getMenuLayout().columnCount;
			if(index - m_highlightIndex >= pageItemCount)
			{
				index -= getMenuLayout().columnCount;
				break;
			}
		}
		if(index == m_highlightIndex)
			return;
	}
	VcpPageMenuCell *highlight_cell = m_cells[m_highlightIndex];
	VcpPageMenuCellPos next_pos(VCP_PAGE_MENU_GROUP_MAIN, index);
	VcpPageMenuCellPos pos(VCP_PAGE_MENU_GROUP_MAIN, m_highlightIndex);
	m_highlightIndex = index;
	setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN,m_highlightIndex));
	if(pos.index > next_pos.index)
	{
		for( ; pos.index > next_pos.index; pos.index--)
		    if(m_cells[pos.index - 1] != NULL)
			    setCell(pos, m_cells[pos.index - 1]);
		setCell(next_pos, highlight_cell);
	}
	else
	{
		for(; pos.index < next_pos.index; pos.index++)
			if(m_cells[pos.index + 1] != NULL)
				setCell(pos, m_cells[pos.index + 1]);
		setCell(next_pos, highlight_cell);
	}
	m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
	checkUpdate();
	return;
}

void VappKeyMainmenuPageMenu::reorderByDownArrowKey(VfxKeyEvent &event)
{
	VfxS32 index = -1;
	VfxS32 pageItemCount = m_menuView->getPageItemCount();
	VfxS32 pre_count = (m_stableCurrentPageIndex - 0) * pageItemCount;

	if((m_cells[m_highlightIndex + getMenuLayout().columnCount] != NULL) && \
		((m_highlightIndex + getMenuLayout().columnCount) < pre_count + pageItemCount))
	{
		index = m_highlightIndex + getMenuLayout().columnCount;
	}
	else if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
	{
		return;
	}
	else if(m_highlightIndex >= pre_count + getMenuLayout().columnCount)
	{
		index = pre_count +  (m_highlightIndex-pre_count)%getMenuLayout().columnCount;
	}
	if(index != -1)
	{
		VcpPageMenuCell *highlight_cell = m_cells[m_highlightIndex];
		VcpPageMenuCellPos next_pos(VCP_PAGE_MENU_GROUP_MAIN, index);
		VcpPageMenuCellPos pos(VCP_PAGE_MENU_GROUP_MAIN, m_highlightIndex);
		m_highlightIndex = index;
		setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN,m_highlightIndex));
		if(pos.index > next_pos.index)
		{
			for( ; pos.index > next_pos.index; pos.index--)
				if(m_cells[pos.index - 1] != NULL)
					setCell(pos, m_cells[pos.index - 1]);
			setCell(next_pos, highlight_cell);
		}
		else
		{
			for(; pos.index < next_pos.index; pos.index++)
				if(m_cells[pos.index + 1] != NULL)
					setCell(pos, m_cells[pos.index + 1]);
			setCell(next_pos, highlight_cell);
		}
		m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
		checkUpdate();
	}
}
void VappKeyMainmenuPageMenu::reorderIndex(VfxKeyEvent &event)
{
	if(event.type != VFX_KEY_EVENT_TYPE_DOWN && event.type != VFX_KEY_EVENT_TYPE_FULL_PRESS_DOWN && \
		event.type != VFX_KEY_EVENT_TYPE_REPEAT)
		return;
	
	switch (event.keyCode)
	{
		case VFX_KEY_CODE_END:
		{
			cancelOrganization();
			break;
		}
		case VFX_KEY_CODE_ARROW_LEFT :
		{
			reorderByLeftArrowKey();
			break;
		}
		
		case VFX_KEY_CODE_ARROW_RIGHT :
		{
			reorderByRightArrowKey();
			break;
		}

		case VFX_KEY_CODE_ARROW_UP :
		{
			reorderByUpArrowKey(event);
			break;
	
		}
		case VFX_KEY_CODE_ARROW_DOWN :
		{
			reorderByDownArrowKey(event);
			break;

		}	
		default:
				return;
	}
}

VfxBool VappKeyMainmenuPageMenu::onKeyInput(VfxKeyEvent &event)
{
	if(m_isHidden || m_isAmiation)
		return VFX_FALSE;

	if(getOrganizeMode())
	{
		reorderIndex(event);
		return VfxControl::onKeyInput(event);
	}
	if(m_menuView->isTransitioning())
		return VfxControl::onKeyInput(event);  // avoid fatal error in menu effect.
	VfxS32 nextHighlightIndex = findNextHighlightIndex(event);
	VfxBool isPageChanged = VFX_FALSE;
	
	isPageChanged = changeHighlightIndex(nextHighlightIndex);

    if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT &&
        (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS|| event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
		if (isPageChanged)
        {
        	VfxS32 animTime = DRAWER_ANIMTIME_RELEASE;
			if(getPageIndex(nextHighlightIndex) > m_stableCurrentPageIndex)
			{
				animTime = DRAWER_ANIMTIME_LOOP_RELEASE;
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
				m_resumeMenuEffectTimer->setStartDelay(animTime);
				m_resumeMenuEffectTimer->start();
				setTransitionEffect(VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL);
#endif
			}
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
			else
			{
				 m_menuView->setTransitionDirection(-1);
			}
#endif
			m_suspendWallpaper.emit(VFX_TRUE);
			m_suspendWallpaperCount ++;
			//VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_4, m_suspendWallpaperCount));
			MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_4, m_suspendWallpaperCount);
			m_resumeWallpaperTimer->setStartDelay(animTime);
			m_resumeWallpaperTimer->start();

            scrollToPage(getPageIndex(m_highlightIndex), animTime);
        }
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT &&
              (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS|| event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (isPageChanged)
        {
			if(getPageIndex(nextHighlightIndex) < m_stableCurrentPageIndex)
			{
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
                VfxS32 animTime = DRAWER_ANIMTIME_LOOP_RELEASE;
				m_resumeMenuEffectTimer->setStartDelay(animTime);
				m_resumeMenuEffectTimer->start();
				setTransitionEffect(VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL);
#endif
			}
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
			else
			{
				 m_menuView->setTransitionDirection(1);
			}
#endif

			m_suspendWallpaper.emit(VFX_TRUE);
			m_suspendWallpaperCount++;
			//VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_5, m_suspendWallpaperCount));
			MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_5, m_suspendWallpaperCount);
			m_resumeWallpaperTimer->setStartDelay(DRAWER_ANIMTIME_RELEASE);
			m_resumeWallpaperTimer->start();

            scrollToPage(getPageIndex(m_highlightIndex), DRAWER_ANIMTIME_RELEASE);
        }
        return VFX_TRUE;
    }

    return VfxControl::onKeyInput(event);
}

VfxBool VappKeyMainmenuPageMenu::handlePenDown(const VfxPoint &touchDownPos)
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
				
			//	static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->setIsHighlighted(VFX_FALSE, VFX_TRUE);
			//	setHighlightIndex(m_delayPenDownCellPos.index, VFX_TRUE);
            }
        }
    }
    checkUpdate();
    return VFX_TRUE;
}

VfxBool VappKeyMainmenuPageMenu::handleScroll(const VfxPenEvent &event)
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
            static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->stopScroll(); // ppp
        }
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        const VfxS32 elapse = event.timeStamp - event.downTimeStamp;
		m_suspendWallpaper.emit(VFX_FALSE);
		//VAPP_KEYLAUNCHER_LOG(TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_3);
		MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_3);
		static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->startScroll(); // ppp
        handleScrollEnd(diffOrigX, elapse);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        const VfxS32 elapse = DRAWER_LONG_SWIPE_THRESHOLD * 2;
        const VfxS32 diffX = 0;
		m_suspendWallpaper.emit(VFX_FALSE);
		//VAPP_KEYLAUNCHER_LOG(TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_4);
		MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_4);
		static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->startScroll(); // ppp
        handleScrollEnd(diffX, elapse);
    }

    return VFX_TRUE;
}

void VappKeyMainmenuPageMenu::handleScrollMove(VfxS32 diffOrigX, VfxS32 diffOrigY)
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
		VfxS32 pageLevel = getSize().width + m_menuView->getLayout().pageMargin;
        if (translateX > (pageLevel * VAPP_KMM_BOUND_TRANSITION_FACTOR))
        {
//            const VfxFloat rotateAngle = (translateX - 0) * DRAWER_BOUND_ROTATE_FACTOR;
//            m_menuView->setRotateAngle(rotateAngle , DRAWER_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = pageLevel * VAPP_KMM_BOUND_TRANSITION_FACTOR;
        }
        if (translateX < m_menuView->getPageTranslateX(getPageCount() - 1) - (pageLevel * VAPP_KMM_BOUND_TRANSITION_FACTOR))
        {
//            const VfxFloat rotateAngle = (translateX -
//                        ( m_menuView->getPageTranslateX(getPageCount() - 1) ) ) *
//                        DRAWER_BOUND_ROTATE_FACTOR;
//            m_menuView->setRotateAngle(rotateAngle , DRAWER_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = m_menuView->getPageTranslateX(getPageCount() - 1) - (pageLevel * VAPP_KMM_BOUND_TRANSITION_FACTOR);
        }
        m_menuView->setTranslateX(translateX, DRAWER_ANIMTIME_INSTANT);
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
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

void VappKeyMainmenuPageMenu::handleScrollEnd(VfxS32 diffX, VfxMsec elapse)
{
    const VfxFloat speed = static_cast<VfxFloat>(diffX * 1000) / elapse;

//    m_menuView->setRotateAngle(0, DRAWER_ANIMTIME_RELEASE, VFX_TRUE);
	VfxS32 currPage = m_stableCurrentPageIndex;

    if (m_startPen && !m_menuView->isTransitioning() && !getOrganizeMode() )
    {
        // clicked
        if (m_delayPenDownCellPos.index != MAINMENU_HITTEST_NOT_FOUND)
        {
            m_enableMenuAnim = VFX_FALSE;
           // setHighlightIndex(m_delayPenDownCellPos.index, VFX_FALSE);
			if(m_highlightIndex != m_delayPenDownCellPos.index)
			{
			    static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->setIsHighlighted(VFX_FALSE, VFX_TRUE);
			    setHighlightIndex(m_delayPenDownCellPos.index, VFX_TRUE);
			}
			#if !defined(__MMI_FTE_SUPPORT_SLIM__)  // for entry app performance
            m_menuView->setClickFrame(getCell(m_delayPenDownCellPos));
			#endif
			m_appClicked.emit(getCell(m_delayPenDownCellPos) );
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

	// change highlight
	VfxS32 nextHighlightIndex = m_stableCurrentPageIndex*m_menuView->getPageItemCount();
	if((m_highlightIndex != nextHighlightIndex) && (currPage != m_stableCurrentPageIndex) && !getOrganizeMode())
	{
		static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->setIsHighlighted(VFX_FALSE, VFX_TRUE);
		//static_cast<VappKeyMainmenuCell*>(m_cells[nextHighlightIndex])->setIsHighlighted(VFX_TRUE, VFX_TRUE);
		//m_highlightIndex = nextHighlightIndex;
		setHighlightIndex(nextHighlightIndex, VFX_TRUE);
		static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->stopScroll(); // ppp
	}

	m_suspendWallpaper.emit(VFX_TRUE);
	m_suspendWallpaperCount ++;
	//VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_3, m_suspendWallpaperCount));
	MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_SUSPEND_WALLPAPER_3, m_suspendWallpaperCount);

	m_resumeWallpaperTimer->setStartDelay(DRAWER_ANIMTIME_RELEASE);
	m_resumeWallpaperTimer->start();
    checkUpdate();
}

void VappKeyMainmenuPageMenu::handleScrollSwipe(VfxS32 diffX, VfxFloat speed)
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

VfxBool VappKeyMainmenuPageMenu::handleOrganize(VfxPenEventTypeEnum touchType, const VfxPoint &touchPos)
{
    if (touchType == VFX_PEN_EVENT_TYPE_MOVE)
    {
        handleOrganizeMove(touchPos.x, touchPos.y);
    }
    else if (touchType == VFX_PEN_EVENT_TYPE_UP)
    {
    	m_suspendWallpaper.emit(VFX_FALSE);
		//VAPP_KEYLAUNCHER_LOG(TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_3);
		MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_3);

        handleOrganizePut();
    }
    else if (touchType == VFX_PEN_EVENT_TYPE_ABORT)
    {
    	m_suspendWallpaper.emit(VFX_FALSE);
		//VAPP_KEYLAUNCHER_LOG(TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_2);
		MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_VAPP_LAUNCHER_KEY_MM_RESUME_WALLPAPER_2);
        handleOrganizePut();
    }

    return VFX_TRUE;
}

void VappKeyMainmenuPageMenu::handleOrganizeStart(VfxBool isByPen)
{
    if (getHover().group != VCP_PAGE_MENU_GROUP_BOTTOM_BAR ||
            getHover().index < DRAWER_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)
    {
        setOrganizeTo(getHover() );
		if(isByPen)
		{
        	m_menuView->setDraggingFrame(getCell(getHover() ) );
			m_menuView->setDraggingFramePos(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
		}
        m_delayMovingTo = getHover();
			// change highlight
		if((m_highlightIndex != getHover().index) && isByPen)

		{
			//static_cast<VappKeyMainmenuCell*>(m_cells[getHover().index])->setIsHighlighted(VFX_TRUE, VFX_TRUE);
			static_cast<VappKeyMainmenuCell*>(m_cells[m_highlightIndex])->setIsHighlighted(VFX_FALSE, VFX_TRUE);
			//m_highlightIndex = getHover().index;
			setHighlightIndex(getHover().index, VFX_TRUE);
		}
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

void VappKeyMainmenuPageMenu::handleOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    VfxBool crossPageMove = VFX_FALSE;
    const VfxMsec ctime = vrt_sys_get_time();
	m_menuView->getDraggingFrame()->setCellGroup(VCP_PAGE_MENU_GROUP_ANIM); // for frame pos, not use last transform
    if (ctime - m_lastAutoScrollTime > DRAWER_ORGANIZE_AUTO_SCROLL_CD)
    {
        if (touchX < DRAWER_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if (currentPage == 0)
            {
#ifdef DRAWER_PAGE_LEFT_EXTENDABLE
                if (getPageCount() < m_menuView->getMaxPageCount(VAPP_LAUNCHER_KEY_MM_MAX_CELL) && m_leftExtended == VFX_FALSE)
                {
                    // can add page
                    crossPageMove = VFX_TRUE;
                    m_leftExtended = VFX_TRUE;
                }
				if ((m_highlightIndex == 0 )&& (m_cells[m_highlightIndex + 1] == NULL))
				{
					 crossPageMove = VFX_FALSE;
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
            if ( (currentPage >= m_menuView->getMaxPageCount(VAPP_LAUNCHER_KEY_MM_MAX_CELL) - 1) )
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
			if (currentPage == getPageCount() - 1 && m_highlightIndex == (m_stableCurrentPageIndex  * m_menuView->getPageItemCount() )&& (m_cells[m_highlightIndex + 1] == NULL))
			{
				 crossPageMove = VFX_FALSE;
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

void VappKeyMainmenuPageMenu::crossPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
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

void VappKeyMainmenuPageMenu::switchOrganizePage(VfxS32 newPage, VfxS32 touchX, VfxS32 touchY)
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

void VappKeyMainmenuPageMenu::removeCellFrom(VcpPageMenuCellPos pos)
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

void VappKeyMainmenuPageMenu::putCellTo(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell * cell)
{
    if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        putCellToMain(currentDirectPos, cell);
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}

void VappKeyMainmenuPageMenu::putCellToMain(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell * cell)
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

void VappKeyMainmenuPageMenu::inPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
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

    m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
    checkUpdate();
}

void VappKeyMainmenuPageMenu::handleOrganizePut(VfxBool isCheckUpdate)
{
    if (m_delayMovingTimer->getIsEnabled())
    {
        m_delayMovingTimer->stop();
        inPageOrganizeMove(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
    }
    
    m_menuView->setAnimDirty(DRAWER_ORGANIZE_DURATION);
    m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), getOrganizeTo().group);
    VappKeyMainmenuCell * mmCell = static_cast<VappKeyMainmenuCell*>(m_menuView->getDraggingFrame() );
    putHoldFrame();
    setHover(DRAWER_NO_HOVER);
    m_menuView->setDraggingFrame(NULL);
    m_leftExtended = VFX_FALSE;
    m_rightExtended = VFX_FALSE;
	// change highlgiht index
	//m_highlightIndex = getOrganizeTo().index;
	setHighlightIndex(getOrganizeTo().index, VFX_FALSE);
    if (isCheckUpdate)
    {
        checkUpdate();
    }
}

void VappKeyMainmenuPageMenu::handleOrganizeEnd(VfxBool isCheckUpdate)
{
    // ensure the dragging frame is put
    handleOrganizePut(isCheckUpdate);

    compactPages(isCheckUpdate);

    if (isCheckUpdate)
    {
        checkUpdate();
    }
}

void VappKeyMainmenuPageMenu::compactPages(VfxBool isCheckUpdate)
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

void VappKeyMainmenuPageMenu::putHoldFrame()
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

VfxBool VappKeyMainmenuPageMenu::putHoldFrameAfterPage(VfxS32 page)
{
    const VfxS32 start = (page + 1) * m_menuView->getPageItemCount();
    for (VfxS32 index = start; index < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++index)
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

VfxBool VappKeyMainmenuPageMenu::putHoldFrameBeforePage(VfxS32 page)
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

void VappKeyMainmenuPageMenu::scrollToPage(VfxS32 pageIndex, VfxS32 animTime, VfxBool isCheckUpdate)
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
        m_stableCurrentPageIndex = pageIndex;
        m_pageChanged.postEmit(m_stableCurrentPageIndex);
    }
    
    m_delayLoadCellTimer->setStartDelay(DRAWER_LOAD_CELL_DELAY);
    m_delayLoadCellTimer->start();
}

VcpPageMenuCell * VappKeyMainmenuPageMenu::getCell(VcpPageMenuCellPos pos) const
{
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        return m_cells[pos.index];
    }
    return NULL;
}

void VappKeyMainmenuPageMenu::setCell(VcpPageMenuCellPos pos, VcpPageMenuCell * cell)
{
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        m_cells[pos.index] = cell;
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}

void VappKeyMainmenuPageMenu::updatePageIndicatorPos()
{
	VfxS32 temp = getSize().height;
    m_pageIndicator->setPos(getSize().width / 2, DRAWER_INDICATOR_OFFSET_Y);
}

VfxBool VappKeyMainmenuPageMenu::getOrganizeMode() const
{
    return m_organizeMode;
}

void VappKeyMainmenuPageMenu::setOrganizeMode(VfxBool organizeMode)
{
    m_organizeMode = organizeMode;
    m_menuView->setOrganizeMode(organizeMode);
    if(organizeMode == VFX_TRUE)
    {
	    mmi_app_package_name_struct *installedAppArray = NULL;
	    U32 installedAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
	    if (installedAppCount)
	    {
	        VFX_SYS_ALLOC_MEM(installedAppArray, sizeof(mmi_app_package_name_struct) * installedAppCount );
	        mmi_ret result;
	        result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installedAppArray, installedAppCount);
	        VFX_ASSERT(result != MMI_RET_ERR);
	    }
	    
	    for (VfxS32 i = 0; i < VAPP_LAUNCHER_KEY_MM_MAX_CELL; ++i)
	    {
	        if (m_cells[i])
	        {
	            VappKeyMainmenuCell *mmCell = static_cast<VappKeyMainmenuCell*>(m_cells[i]);
	            VfxBool isInstalled = VFX_FALSE;
	            if (installedAppArray)
	            {
	                mmi_app_package_name_struct appName;
	                mmCell->getCellAppName(appName);
	                isInstalled = isKmmInstalledApp(appName, installedAppArray, installedAppCount);
	            }
	            mmCell->setIsInstalled(isInstalled);
	
		       // m_cells[i]->setCacheMode(VFX_CACHE_MODE_AUTO);
	
	        }
			m_backupCells[i] = m_cells[i];
			m_backupPageCount = m_pageCount;
	    }
	    
	    if (installedAppArray)
	    {
	        VFX_SYS_FREE_MEM(installedAppArray);
	    }
	#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
		if(organizeMode)
			setTransitionEffect(VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL);
	#endif
	}
}

VcpPageMenuCellPos VappKeyMainmenuPageMenu::getOrganizeTo() const
{
    return m_organizeTo;
}

void VappKeyMainmenuPageMenu::setOrganizeTo(VcpPageMenuCellPos organizeTo)
{
    m_organizeTo = organizeTo;
}

VcpPageMenuCellPos VappKeyMainmenuPageMenu::getHover() const
{
    return m_hover;
}

void VappKeyMainmenuPageMenu::setHover(VcpPageMenuCellPos hover)
{
    m_hover = hover;
    m_menuView->setHover(hover);
}

VfxS32 VappKeyMainmenuPageMenu::getPageCount() const
{
    VFX_ASSERT(m_pageCount <= m_menuView->getMaxPageCount(VAPP_LAUNCHER_KEY_MM_MAX_CELL) );
    if (m_pageCount == 0)
    {
        // special case handling : no item on pages
        return 1;
    }
    return m_pageCount;
}

void VappKeyMainmenuPageMenu::setPageCount(VfxS32 pageCount, VfxBool isCheckUpdate)
{
    VFX_ASSERT(pageCount <= m_menuView->getMaxPageCount(VAPP_LAUNCHER_KEY_MM_MAX_CELL) );
    m_pageCount = pageCount;

    // some checks for menu initialization
    if (m_menuView->getNearestPage() >= getPageCount() )
    {
        scrollToPage(getPageCount() - 1, DRAWER_ORGANIZE_DURATION, isCheckUpdate);
    }
}

VcpPageMenuCell * VappKeyMainmenuPageMenu::getHoldFrame() const
{
    return m_holdFrame;
}

void VappKeyMainmenuPageMenu::setHoldFrame(VcpPageMenuCell * holdFrame)
{
    m_holdFrame = holdFrame;
    m_menuView->setHoldFrame(holdFrame);
}

VcpPageMenuCellPos VappKeyMainmenuPageMenu::cellHittest(VfxPoint clickPoint, VfxBool findLast) const
{
    const VcpPageMenuCellPos pos = m_menuView->baseCellHittest(clickPoint, VAPP_LAUNCHER_KEY_MM_MAX_CELL);

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

