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
 *  vapp_launcher_mm_page_menu.cpp
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher MM
 *
 * Description:
 * ------------
 *  Launcher MM Page Menu
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
 *
 * removed!
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

#ifdef __MMI_VUI_LAUNCHER_MM__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_adp_device.h"
#include "vfx_string.h"

#include "vcp_page_menu_util.h"
#include "vcp_page_menu_transition.h"
#include "vcp_text_editor.h"

#include "vapp_launcher_mm.h"
#include "vapp_launcher_mm_builder.h"   // for VappLauncherMmCell
#include "vapp_launcher_mm_default_order.h"
#include "vapp_launcher_mm_page_menu.h"
#include "mmi_rp_vapp_launcher_mm_def.h"

extern "C"
{
#include "notificationGprot.h"
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

//#define VAPP_LAUNCHER_MM_PAGE_LEFT_EXTENDABLE

//#define VAPP_LAUNCHER_MM_FPS_TEST

#define VAPP_LAUNCHER_MM_SHADOW_EDIT_MODE

// to avoid global class with constructor
#define VAPP_LAUNCHER_MM_NO_HOVER VcpPageMenuCellPos(-1, -1)

#define VAPP_LAUNCHER_MM_DEFAULT_FOLDER_NAME VFX_WSTR("Folder")


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

// mainmenu user interaction constatnt
static const VfxS32 VAPP_LAUNCHER_MM_LONG_SWIPE_THRESHOLD = 600;

// mainmenu animation constatnt
#ifdef VAPP_LAUNCHER_MM_FPS_TEST
static const VfxS32 VAPP_LAUNCHER_MM_ANIMTIME_INSTANT = 200;
static const VfxS32 VAPP_LAUNCHER_MM_ANIMTIME_RELEASE = 5000;
static const VfxS32 VAPP_LAUNCHER_MM_ANIMTIME_MIN_RELEASE = 3000;
static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_DURATION = 2000;
#else
static const VfxS32 VAPP_LAUNCHER_MM_ANIMTIME_INSTANT = 1;
static const VfxS32 VAPP_LAUNCHER_MM_ANIMTIME_RELEASE = 280;
static const VfxS32 VAPP_LAUNCHER_MM_ANIMTIME_MIN_RELEASE = 200;
static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_DURATION = 250;
#endif

static const VfxS32 VAPP_LAUNCHER_MM_LONG_PRESS_ENTER_ORGANIZE_DELAY = 800;
static const VfxS32 VAPP_LAUNCHER_MM_LONG_PRESS_ORGANIZE_ANOTHER_DELAY = 300;
static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_CD = 1000;
static const VfxS32 VAPP_LAUNCHER_MM_DELAY_MOVING_DELAY = 100;
static const VfxS32 VAPP_LAUNCHER_MM_START_TO_FOLDER_MODE_DELAY = 1000;

//static const VfxFloat VAPP_LAUNCHER_MM_ROTATION_LIMIT = 15.0f;

//static const VfxFloat VAPP_LAUNCHER_MM_BOUND_ROTATE_FACTOR = -0.09f;
static const VfxFloat VAPP_LAUNCHER_MM_BOUND_TRANSLATION_FACTOR = 0.5f;

static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT = 4;

static const VfxFloat VAPP_LAUNCHER_MM_EDITING_ALPHA = 0.5f;

static const VfxFloat VAPP_LAUNCHER_MM_FOLDER_INVALID_CELL_ALPHA = 0.2f;

static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_OFFSET_Y = MMI_STATUS_BAR_HEIGHT;

// page indicator layout constants
#if defined(__MMI_MAINLCD_480X800__)

static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_WIDTH = 480;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_HEIGHT = 42;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_BG_HEIGHT = 42;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_SPACING = 31;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 VAPP_LAUNCHER_MM_SWIPE_RANGE_THRESHOLD = 60;

#ifdef __TOUCH_PANEL_CAPACITY__
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_X = 10;
#else
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_X = 5;
#endif
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_Y = 80;

static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN = 30;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_WIDTH = 240;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_HEIGHT = 16;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_BG_HEIGHT = 16;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_SPACING = 20;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 VAPP_LAUNCHER_MM_SWIPE_RANGE_THRESHOLD = 30;

#ifdef __TOUCH_PANEL_CAPACITY__
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_X = 10;
#else
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_X = 5;
#endif
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_Y = 30;

static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN = 15;

#else

static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_WIDTH = 320;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_HEIGHT = 16;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_BG_HEIGHT = 16;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_SPACING = 25;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_OFFSET_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_INDICATOR_CELL_OFFSET_Y = 0;

static const VfxS32 VAPP_LAUNCHER_MM_SWIPE_RANGE_THRESHOLD = 30;

#ifdef __TOUCH_PANEL_CAPACITY__
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_X = 10;
#else
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_X = 5;
#endif
static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_Y = 40;

static const VfxS32 VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN = 20;

#endif

// folder editor layout constant
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_ROW_COUNT = 2;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_COLUMN_COUNT = 4;

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_START_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_X = 120;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_Y = 144;

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_MAIN_SHIFT_Y = 120;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN = 20;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_BOTTOM_MARGIN = 20;

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_ARROW_UP_POS_SHIFT_Y = 1;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_ARROW_DOWN_POS_SHIFT_Y = -1;

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_X = 12;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_Y = VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_HEIGHT = 40;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_START_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_X = 60;
#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_Y = 70;
#else
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_Y = 72;
#endif

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_MAIN_SHIFT_Y = 55;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN = 12;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_BOTTOM_MARGIN = 12;

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_ARROW_UP_POS_SHIFT_Y = 1;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_ARROW_DOWN_POS_SHIFT_Y = -1;

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_X = 7;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_Y = VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_HEIGHT = 24;

#else
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_START_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_X = 80;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_Y = 88;

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_MAIN_SHIFT_Y = 75;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN = 15;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_BOTTOM_MARGIN = 15;

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_ARROW_UP_POS_SHIFT_Y = 1;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_ARROW_DOWN_POS_SHIFT_Y = -1;

static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_X = 11;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_Y = VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_HEIGHT = 30;

#endif

static const VfxS32 VAPP_LAUNCHER_MM_CANCEL_EXIT_FOLDER_MODE_THRESHOLD = 20;


/*****************************************************************************
 * Class VappLauncherMmFolderEditor
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLuancherMmFolderEditor", VappLuancherMmFolderEditor, VfxFrame);

void VappLuancherMmFolderEditor::onObjectNotify(VfxId eventId, void *userData)
{
    switch (eventId)
    {
        case VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE:
        {
            *((VfxFrameImeModeEnum *)userData) = getImeMode();
            
            return;
        }
        case VFX_FRAME_NOTIFY_ID_ADJUST_IME_SHIFT:
        {
            VfxFrameAdjustImeShiftData *data = (VfxFrameAdjustImeShiftData *)userData;
            adjustImeShift(data->pos, data->focusFrame);
            ((VappLauncherMmPageMenu *)getParent())->adjustImeShift(data->pos, data->focusFrame);
            
            return;
        }       
        default:
        {
            VfxFrame::onObjectNotify(eventId, userData);
        }
    }
}

VfxFrameImeModeEnum VappLuancherMmFolderEditor::getImeMode()
{
    return VFX_FRAME_IME_MODE_SHIFT;
}


/*****************************************************************************
 * Class VcpLauncherMmPageMenuView
 *****************************************************************************/

class VcpLauncherMmPageMenuView : public VcpPageMenuView
{
protected:
    virtual void updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos);
};

void VcpLauncherMmPageMenuView::updateCellAttribute(VcpPageMenuCell * cell, VcpPageMenuCellPos pos)
{
#ifdef VAPP_LAUNCHER_MM_SHADOW_EDIT_MODE
    VfxAutoAnimate::begin();

    VfxFloat opacity;
    if (pos == getHover() && getOrganizeMode() == VFX_FALSE )
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
        opacity = VAPP_LAUNCHER_MM_EDITING_ALPHA;
    }
    else if ((getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE || getFolderState() == VCP_PAGE_MENU_FOLDER_MODE) &&
             pos != getFolderCellPos() &&
             cell != getDraggingFrame() &&
             cell->getCellGroup() != VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
    {
        opacity = VAPP_LAUNCHER_MM_FOLDER_INVALID_CELL_ALPHA;
    }
    else
    {
        if (cell->getOpacity() != VAPP_LAUNCHER_MM_FOLDER_INVALID_CELL_ALPHA)
        {
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }
        opacity = 1.0f;
    }
    cell->setOpacity(opacity);
    
    VfxAutoAnimate::commit();

    VappLauncherMmCell * mmCell = static_cast<VappLauncherMmCell*>(cell);
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
 * Class VappLauncherMmPageMenu
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherMmPageMenu", VappLauncherMmPageMenu, VfxControl);

VappLauncherMmPageMenu::VappLauncherMmPageMenu():
    m_pageCount(0),
    m_stableCurrentPageIndex(0),
    m_menuView(NULL),
    m_holdFrame(NULL),
    m_pageIndicator(NULL),
    m_invalidCellPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND),
    m_tempCellInFolderIcon(NULL),
    m_folderEditor(NULL),
    m_folderArrow(NULL),
    m_folderBg(NULL),
    m_folderNameTextFrame(NULL),
    m_folderNameTextEditor(NULL),
    m_adjustImeShiftY(0),
    m_canDragToExitFolderMode(VFX_FALSE),
    m_folderCount(0),
    m_longPressTimer(NULL),
    m_delayLoadCellTimer(NULL),
    m_delayMovingTimer(NULL),
    m_autoScrollPageTimer(NULL),
    m_startToFolderModeTimer(NULL),
    m_hover(VAPP_LAUNCHER_MM_NO_HOVER),
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
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER; ++i)
    {
        m_cells[i] = NULL;
        for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
        {
            m_cellsInFolderIcon[i][j] = NULL;
        }
    }
    
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_BOTTOM_BAR_FOLDER; ++i)
    {
        m_groupCells[i] = NULL;
        for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
        {
            m_groupCellsInFolderIcon[i][j] = NULL;
        }
    }
    
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
    {
        m_cellsInFolderEditor[i] = NULL;
        m_holdFrameInFolderIcon[i] = NULL;
        m_draggingFrameInFolderIcon[i] = NULL;
    }
}

VfxS32 VappLauncherMmPageMenu::getCurrentPageIndex() const
{
    return m_menuView->getNearestPage();
}

void VappLauncherMmPageMenu::setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated)
{
    if (animated)
    {
        scrollToPage(pageIndex, VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
    }
    else
    {
        scrollToPage(pageIndex, VAPP_LAUNCHER_MM_ANIMTIME_INSTANT);
    }
}

const VcpPageMenuLayout & VappLauncherMmPageMenu::getMenuLayout() const
{
    return m_menuView->getLayout();
}

void VappLauncherMmPageMenu::setMenuLayout(const VcpPageMenuLayout & layout)
{
    m_menuView->setLayout(layout);
    updatePageIndicatorPos();
}

void VappLauncherMmPageMenu::refreshMenu()
{
    m_updateCount = 0;
	m_menuView->setClickFrame(NULL);
    m_menuView->reset();
    setFocused(VFX_TRUE);
}

void VappLauncherMmPageMenu::setIsUninstallingMode(VfxBool isUninstalling)
{
    m_menuView->setIsUninstalling(isUninstalling);
}

void VappLauncherMmPageMenu::setIsEnterNCenter(VfxBool isEnterNCenter)
{
    m_menuView->setIsEnterNCenter(isEnterNCenter);
}

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
VcpPageMenuTransitionType VappLauncherMmPageMenu::getTransitionEffect() const
{
    return m_menuView->getTransitionEffect();
}

void VappLauncherMmPageMenu::setTransitionEffect(VcpPageMenuTransitionType transitionType)
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

void VappLauncherMmPageMenu::leaveOrganizationMode(VfxBool isCheckUpdate)
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

void VappLauncherMmPageMenu::enterOrganizationMode()
{
    setOrganizeMode(VFX_TRUE);
}

void VappLauncherMmPageMenu::forceDirty()
{
    m_menuView->forceDirty();
    checkUpdate();
}

VfxBool VappLauncherMmPageMenu::isHitCell(VfxPenEvent &event)
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

VcpPageMenuCell * VappLauncherMmPageMenu::getMenuItem(VfxS32 index) const
{
    return m_cells[index];
}

void VappLauncherMmPageMenu::setMenuItem(VfxS32 index, VcpPageMenuCell * cell)
{
    if (m_cells[index] != NULL)
    {
        m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
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

VcpPageMenuCell * VappLauncherMmPageMenu::getGroupMenuItem(VfxS32 index) const
{
    return m_groupCells[index];
}

void VappLauncherMmPageMenu::setGroupMenuItem(VfxS32 index, VcpPageMenuCell * cell)
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

void VappLauncherMmPageMenu::clearAllMenuItems()
{
    if (m_menuView->getDraggingFrame())
    {
        handleOrganizePut();
    }
    m_menuView->setClickFrame(NULL);

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER; ++i)
    {
        if (m_cells[i])
        {
            VFX_OBJ_CLOSE(m_cells[i]);
        }
        
        for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
        {
            if (m_cellsInFolderIcon[i][j])
            {
                VFX_OBJ_CLOSE(m_cellsInFolderIcon[i][j]);
            }
        }
    }
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_BOTTOM_BAR_FOLDER; ++i)
    {
        if (m_groupCells[i])
        {
            VFX_OBJ_CLOSE(m_groupCells[i]);
        }
        for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
        {
            if (m_groupCellsInFolderIcon[i][j])
            {
                VFX_OBJ_CLOSE(m_groupCellsInFolderIcon[i][j]);
            }
        }
    }
}

void VappLauncherMmPageMenu::setCellIconSize(const VfxSize & size)
{
    m_menuView->setCellIconSize(size);
}

VfxS32 VappLauncherMmPageMenu::getPageCount() const
{
    VFX_ASSERT(m_pageCount <= m_menuView->getMaxPageCount(VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER) );
    if (m_pageCount == 0)
    {
        // special case handling : no item on pages
        return 1;
    }
    return m_pageCount;
}

void VappLauncherMmPageMenu::setPageCount(VfxS32 pageCount, VfxBool isChceckUpdate)
{
    VFX_ASSERT(pageCount <= m_menuView->getMaxPageCount(VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER) );
    m_pageCount = pageCount;

    // some checks for menu initialization
    if (m_menuView->getNearestPage() >= getPageCount() )
    {
        scrollToPage(getPageCount() - 1, VAPP_LAUNCHER_MM_ORGANIZE_DURATION, isChceckUpdate);
    }
}

VfxS32 VappLauncherMmPageMenu::getMaxPageCount() const
{
    return m_menuView->getMaxPageCount(VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER);
}

VfxS32 VappLauncherMmPageMenu::getMenuItemCountPerPage() const
{
    return m_menuView->getPageItemCount();
}

VfxS32 VappLauncherMmPageMenu::getMenuItemCountPerGroup() const
{
    return 16;
}

void VappLauncherMmPageMenu::compactPages(VfxBool isCheckUpdate)
{
    m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
    
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
        // Need to check whether first cell in current page is invalid cell or not
        if ((m_invalidCellPos.group == VCP_PAGE_MENU_GROUP_MAIN && m_invalidCellPos.index == i * m_menuView->getPageItemCount()) ||
            !vcpPageMenuIsPageEmpty(m_cells, m_menuView->getPageItemCount(), i))
        {
            vcpPageMenuMovePageContent(m_cells, m_menuView->getPageItemCount(), i, nonemptyPageCount,
                                       &m_cellsInFolderIcon[0][0], VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);
            ++nonemptyPageCount;
        }
    }
    for (VfxS32 i = nonemptyPageCount; i < getPageCount(); ++i)
    {
        vcpPageMenuClearPageContent(m_cells, m_menuView->getPageItemCount(), i,
                                    &m_cellsInFolderIcon[0][0], VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);
    }

    if (pageIndexAfterCompact == nonemptyPageCount)
    {
        pageIndexAfterCompact = nonemptyPageCount - 1;
    }

    scrollToPage(pageIndexAfterCompact, VAPP_LAUNCHER_MM_ORGANIZE_DURATION, isCheckUpdate);
    setPageCount(nonemptyPageCount, isCheckUpdate);
}

void VappLauncherMmPageMenu::preLoadAndCacheNeighborPageCell()
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

VcpPageMenuCell *VappLauncherMmPageMenu::getMenuItemInFolderIcon(VfxS32 index, VfxS32 subIndex) const
{
    return m_cellsInFolderIcon[index][subIndex];
}

void VappLauncherMmPageMenu::setMenuItemInFolderIcon(VfxS32 index, VfxS32 subIndex, VcpPageMenuCell *cell)
{
    if (m_cellsInFolderIcon[index][subIndex] != NULL)
    {
        m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
    }

    m_cellsInFolderIcon[index][subIndex] = cell;
    if (cell == NULL)
    {
        return;
    }

    m_cells[index]->addChildFrame(cell);
    
    cell->setAutoAnimate(VFX_TRUE);

    m_menuView->initCellAnim(cell, VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON);

    checkUpdate();
}

VcpPageMenuCell *VappLauncherMmPageMenu::getGroupMenuItemInFolderIcon(VfxS32 index, VfxS32 subIndex) const
{
    return m_groupCellsInFolderIcon[index][subIndex];
}

void VappLauncherMmPageMenu::setGroupMenuItemInFolderIcon(VfxS32 index, VfxS32 subIndex, VcpPageMenuCell *cell)
{
    m_groupCellsInFolderIcon[index][subIndex] = cell;
    if (cell == NULL)
    {
        return;
    }

    m_groupCells[index]->addChildFrame(cell);
    
    cell->setAutoAnimate(VFX_TRUE);

    m_menuView->initCellAnim(cell, VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON);

    checkUpdate();
}

VcpPageMenuCell *VappLauncherMmPageMenu::getMenuItemInFolderEditor(VfxS32 index) const
{
    return m_cellsInFolderEditor[index];
}

void VappLauncherMmPageMenu::setMenuItemInFolderEditor(VfxS32 index, VcpPageMenuCell *cell)
{
    if (m_cellsInFolderEditor[index] != NULL)
    {
        m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
    }

    m_cellsInFolderEditor[index] = cell;
    if (cell == NULL)
    {
        return;
    }

    cell->setAutoAnimate(VFX_TRUE);

    m_menuView->initCellAnim(cell, VCP_PAGE_MENU_GROUP_FOLDER_EDITOR);

    checkUpdate();
}

VcpPageMenuFolderStateEnum VappLauncherMmPageMenu::getFolderState()
{
    return m_menuView->getFolderState();
}

void VappLauncherMmPageMenu::setFolderState(VcpPageMenuFolderStateEnum folderState)
{
    m_menuView->setFolderState(folderState);
}

VfxS32 VappLauncherMmPageMenu::getFolderCount()
{
    return m_folderCount;
}

void VappLauncherMmPageMenu::setFolderCount(VfxS32 folderCount)
{
    m_folderCount = folderCount;
}

VcpPageMenuCellPos VappLauncherMmPageMenu::getInvalidCellPos()
{
    return m_invalidCellPos;
}

void VappLauncherMmPageMenu::leaveFolderMode()
{
    exitFolderMode();
}

void VappLauncherMmPageMenu::reloadFolderEditor()
{
    if (getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
        getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
    {
        m_invalidCellPos = VcpPageMenuCellPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND);
        
        closeFolderEditor();
        
        VappLauncherMmCell *folderCell = static_cast<VappLauncherMmCell *>(getCell(m_menuView->getFolderCellPos()));
        if (folderCell && isFolderCell(m_menuView->getFolderCellPos()))
        {
            folderCell->setTextFrameHidden(VFX_TRUE);
            
            createFolderEditor(m_menuView->getFolderCellPos());
        }
        else
        {
            setFolderState(VCP_PAGE_MENU_NOT_FOLDER_MODE);
        }
    }
}

void VappLauncherMmPageMenu::adjustImeShift(const VfxPoint &pos, VfxFrame *focusFrame)
{
    VcpPageMenuFolderEditorLayout folderEditorLayout = m_menuView->getFolderEditorLayout();
    folderEditorLayout.folderEditorPosY = pos.y;
    m_menuView->setFolderEditorLayout(folderEditorLayout);
    
    m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
    checkUpdate();
}

void VappLauncherMmPageMenu::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    m_menuView->setSize(value.size.width, value.size.height );

    updatePageIndicatorPos();
}

void VappLauncherMmPageMenu::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_menuView, VcpLauncherMmPageMenuView, this);
    m_menuView->setClipMargin(0);

    VFX_OBJ_CREATE(m_pageIndicator, VcpPageMenuIndicator, this);
    m_pageIndicator->setAnchor(0.5f, 0.0f);

    // initial the page indicator
    VcpPageMenuIndicatorLayout indicatorLayout;
    indicatorLayout.indicatorWidthBase = VAPP_LAUNCHER_MM_INDICATOR_WIDTH;
    indicatorLayout.indicatorWidthIncrement = 0;
    indicatorLayout.indicatorHeight = VAPP_LAUNCHER_MM_INDICATOR_HEIGHT;
    indicatorLayout.bgOffsetY = 0;
    indicatorLayout.bgHeight = VAPP_LAUNCHER_MM_INDICATOR_BG_HEIGHT;
    indicatorLayout.cellSpacing = VAPP_LAUNCHER_MM_INDICATOR_CELL_SPACING;
    indicatorLayout.cellOffsetX = VAPP_LAUNCHER_MM_INDICATOR_CELL_OFFSET_X;
    indicatorLayout.cellOffsetY = VAPP_LAUNCHER_MM_INDICATOR_CELL_OFFSET_Y;
    VfxImageSrc normalDot(IMG_ID_VAPP_LAUNCHER_MM_INDICATOR_DOT_N);
    indicatorLayout.cellWidth = normalDot.getSize().width;
    indicatorLayout.cellHeight = normalDot.getSize().height;
    VfxImageSrc highlightDot(IMG_ID_VAPP_LAUNCHER_MM_INDICATOR_DOT_H);
    indicatorLayout.cellHighlightWidth = highlightDot.getSize().width;
    indicatorLayout.cellHighlightHeight = highlightDot.getSize().height;
    m_pageIndicator->setCellImage(normalDot, highlightDot);
    m_pageIndicator->setLayout(indicatorLayout);

    updatePageIndicatorPos();
    m_pageIndicator->m_pageSelected.connect(this, &VappLauncherMmPageMenu::onPageIndicatorSelected);

    VFX_OBJ_CREATE(m_longPressTimer, VfxTimer, this);
    m_longPressTimer->m_signalTick.connect(this, &VappLauncherMmPageMenu::onLongPressTimerTick);

    VFX_OBJ_CREATE(m_delayLoadCellTimer, VfxTimer, this);
    m_delayLoadCellTimer->m_signalTick.connect(this, &VappLauncherMmPageMenu::onDelayLoadCellTimerTick);

    VFX_OBJ_CREATE(m_delayMovingTimer, VfxTimer, this);
    m_delayMovingTimer->m_signalTick.connect(this, &VappLauncherMmPageMenu::onDelayMovingTimerTick);
    
    VFX_OBJ_CREATE(m_autoScrollPageTimer, VfxTimer, this);
    m_autoScrollPageTimer->m_signalTick.connect(this, &VappLauncherMmPageMenu::onAutoScrollPageTimerTick);
    
    VFX_OBJ_CREATE(m_startToFolderModeTimer, VfxTimer, this);
    m_startToFolderModeTimer->m_signalTick.connect(this, &VappLauncherMmPageMenu::onStartToFolderModeTimerTick);

    checkUpdate();
}

void VappLauncherMmPageMenu::onUpdate()
{
    VfxControl::onUpdate();
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM2", SA_start);
#endif

    if (m_menuView->getNearestPage() > getPageCount() - 1)
    {
        scrollToPage(getPageCount() - 1, VAPP_LAUNCHER_MM_ANIMTIME_INSTANT);
    }

    ++m_updateCount;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM2", SA_stop);
#endif

    m_menuView->updateEx(m_cells, VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER,
                         m_groupCells, VAPP_LAUNCHER_MM_MAX_BOTTOM_BAR_FOLDER,
                         &m_cellsInFolderIcon[0][0], VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER,
                         &m_groupCellsInFolderIcon[0][0], VAPP_LAUNCHER_MM_MAX_BOTTOM_BAR_FOLDER, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER,
                         m_cellsInFolderEditor, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM2", SA_start);
#endif

    if (m_stableCurrentPageIndex != m_pageIndicator->getCurrentPage() || getPageCount() != m_pageIndicator->getIndicatorPageCount() || m_updateCount == 1)
    {
        const VfxS32 currentPageIndex = m_menuView->getNearestPage();
        m_pageIndicator->setCurrentPage(currentPageIndex);
        VfxS32 indicatorPageCount = getPageCount();
        if (currentPageIndex + 1 > indicatorPageCount && currentPageIndex < m_menuView->getMaxPageCount(VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER) )
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

VfxBool VappLauncherMmPageMenu::onPreviewPenInput(VfxPenEvent &event)
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
        m_menuView->getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
    {
        switch (event.type)
        {
            case VFX_PEN_EVENT_TYPE_DOWN:
            case VFX_PEN_EVENT_TYPE_MOVE:
                m_canScroll = VFX_FALSE;
                break;
                
            case VFX_PEN_EVENT_TYPE_UP:
                if (m_menuView->getDraggingFrame() == NULL &&
                    !isHitFolderEditor(event.downPos.x, event.downPos.y) &&
                    VFX_ABS(event.downPos.x - event.pos.x) < VAPP_LAUNCHER_MM_CANCEL_EXIT_FOLDER_MODE_THRESHOLD &&
                    VFX_ABS(event.downPos.y - event.pos.y) < VAPP_LAUNCHER_MM_CANCEL_EXIT_FOLDER_MODE_THRESHOLD)
                {
                    exitFolderMode();
                    
                    return VFX_TRUE;
                }
                break;
                
            default:
                break;
        }
    }

    return VfxControl::onPreviewPenInput(event);
}

VfxBool VappLauncherMmPageMenu::onPenInput(VfxPenEvent &event)
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
        // long tap is ignored, VappLauncherMmPageMenu handle long tap behavior itself
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

VfxBool VappLauncherMmPageMenu::onKeyInput(VfxKeyEvent &event)
{
    if (getFolderState() == VCP_PAGE_MENU_NOT_FOLDER_MODE)
    {
        if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT &&
            (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT))
        {
            if (m_stableCurrentPageIndex > 0)
            {
                scrollToPage(m_stableCurrentPageIndex - 1, VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
            }
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT &&
                 (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT))
        {
            if (m_stableCurrentPageIndex < (m_pageCount - 1))
            {
                scrollToPage(m_stableCurrentPageIndex + 1, VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
            }
            return VFX_TRUE;
        }
    }
    
    return VfxControl::onKeyInput(event);
}

VfxBool VappLauncherMmPageMenu::getOrganizeMode() const
{
    return m_organizeMode;
}

void VappLauncherMmPageMenu::setOrganizeMode(VfxBool organizeMode)
{
    m_organizeMode = organizeMode;
    m_menuView->setOrganizeMode(organizeMode);

    // Support uninstall icon, query app to see if can be deleted.
    mmi_app_package_name_struct *installedAppArray = NULL;
    U32 installedAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (installedAppCount)
    {
        VFX_SYS_ALLOC_MEM(installedAppArray, sizeof(mmi_app_package_name_struct) * installedAppCount );
        mmi_ret result;
        result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installedAppArray, installedAppCount);
        VFX_ASSERT(result != MMI_RET_ERR);
    }
    
    VfxS32 count[3];
    count[0] = VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER;
    count[1] = VAPP_LAUNCHER_MM_MAX_BOTTOM_BAR_FOLDER;
    count[2] = VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER;

    for (VfxS32 j = 0; j < 3; ++j)
    {
        for (VfxS32 i = 0; i < count[j]; ++i)
        {
            VappLauncherMmCell *mmCell;
            if (j == 0)
                mmCell = static_cast<VappLauncherMmCell*>(m_cells[i]);
            else if (j == 1)
                mmCell = static_cast<VappLauncherMmCell*>(m_groupCells[i]);
            else
                mmCell = static_cast<VappLauncherMmCell*>(m_cellsInFolderEditor[i]);
            
            if (mmCell)
            {
                VfxBool isInstalled = VFX_FALSE;
                if (installedAppArray)
                {
                    mmi_app_package_name_struct appName;
                    mmCell->getCellAppName(appName);
                    isInstalled = vappLauncherMmIsInstalledApp(appName, installedAppArray, installedAppCount);
                }
                mmCell->setIsInstalled(isInstalled);
                mmCell->setUninstalledButtonHidden(!organizeMode);
            }
        }
    }
    
    if (installedAppArray)
    {
        VFX_SYS_FREE_MEM(installedAppArray);
    }      
    
    // update folder name
    if ((m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
         m_menuView->getFolderState() == VCP_PAGE_MENU_FOLDER_MODE) &&
        !organizeMode)
    {
        saveFolderName();
    }
    updateFolderEditorText(organizeMode);
}

VcpPageMenuCellPos VappLauncherMmPageMenu::getOrganizeTo() const
{
    return m_organizeTo;
}

void VappLauncherMmPageMenu::setOrganizeTo(VcpPageMenuCellPos organizeTo)
{
    m_organizeTo = organizeTo;
}

VcpPageMenuCellPos VappLauncherMmPageMenu::getHover() const
{
    return m_hover;
}

void VappLauncherMmPageMenu::setHover(VcpPageMenuCellPos hover)
{
    if (m_hover != hover)
    {
        m_hover = hover;
        m_menuView->setHover(m_hover);
    }
}

VcpPageMenuCell * VappLauncherMmPageMenu::getHoldFrame() const
{
    return m_holdFrame;
}

void VappLauncherMmPageMenu::setHoldFrame(VcpPageMenuCell * holdFrame)
{
    m_holdFrame = holdFrame;
    m_menuView->setHoldFrame(holdFrame);
}

void VappLauncherMmPageMenu::onLongPressTimerTick(VfxTimer *source)
{
    if (getHover().index == MAINMENU_HITTEST_NOT_FOUND)
    {
        return;
    }

    if (getOrganizeMode() )
    {
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
        
        m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
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

        m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
    }
}

void VappLauncherMmPageMenu::onDelayLoadCellTimerTick(VfxTimer *source)
{
    preLoadAndCacheNeighborPageCell();
}

void VappLauncherMmPageMenu::onDelayMovingTimerTick(VfxTimer *source)
{
    inPageOrganizeMove(m_delayMovingTouchPos.x, m_delayMovingTouchPos.y);
}

void VappLauncherMmPageMenu::onAutoScrollPageTimerTick(VfxTimer *source)
{
    VfxBool crossPageMove = VFX_FALSE;
    const VfxS32 currentPage = m_menuView->getNearestPage();
    if (m_lastAutoScrollTouchPos.x < VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        if (currentPage == 0)
        {
        #ifdef VAPP_LAUNCHER_MM_PAGE_LEFT_EXTENDABLE
            if (getPageCount() < m_menuView->getMaxPageCount(VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER) && m_leftExtended == VFX_FALSE)
            {
                // can add page
                crossPageMove = VFX_TRUE;
                m_leftExtended = VFX_TRUE;
            }
        #endif // VAPP_LAUNCHER_MM_PAGE_LEFT_EXTENDABLE
        }
        else
        {
            crossPageMove = VFX_TRUE;
        }
    }
    else if (m_lastAutoScrollTouchPos.x > getSize().width - VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        if ( (currentPage >= m_menuView->getMaxPageCount(VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER) - 1) )
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
        source->setStartDelay(VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_CD);
        source->start();
    }
}

void VappLauncherMmPageMenu::onStartToFolderModeTimerTick(VfxTimer *source)
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE &&
        getFolderCount() >= VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER_DATA)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_INFO,
                             VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_MM_CANNOT_CREATE_FOLDER).getBuf());
        
        cancelFolderMode();
        
        m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);

        checkUpdate();
    }
    else
    {
        enterFolderMode();
    }
}

void VappLauncherMmPageMenu::onPageIndicatorSelected(VfxS32 pageSelected)
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_NOT_FOLDER_MODE)
    {
        scrollToPage(pageSelected, VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
    }
}

void VappLauncherMmPageMenu::onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    VFX_OBJ_CLOSE(timeline);
}

VcpPageMenuCellPos VappLauncherMmPageMenu::cellHittest(VfxPoint clickPoint, VfxBool findLast, VcpPageMenuCellHitAreaEnum *hitArea) const
{
    const VcpPageMenuCellPos pos = m_menuView->baseCellHittest(clickPoint, VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER, hitArea);

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
        else if (pos.group == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
        {
            if (m_cellsInFolderEditor[pos.index] != NULL)
            {
                return pos;
            }
            return VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, MAINMENU_HITTEST_NOT_FOUND);
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

void VappLauncherMmPageMenu::scrollToPage(VfxS32 pageIndex, VfxS32 animTime, VfxBool isCheckUpdate)
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
    m_pageMoved.emit(m_menuView->getPageTranslateX(pageIndex) + getCurrentPageIndex() * m_menuView->getLayout().pageMargin, animTime);
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

    if (!getOrganizeMode() && animTime != VAPP_LAUNCHER_MM_ANIMTIME_INSTANT)
    {
        m_delayLoadCellTimer->setStartDelay(animTime);
        m_delayLoadCellTimer->start();
    }
}

void VappLauncherMmPageMenu::updatePageIndicatorPos()
{
    m_pageIndicator->setPos(getSize().width / 2, VAPP_LAUNCHER_MM_INDICATOR_OFFSET_Y);
}

VcpPageMenuCell *VappLauncherMmPageMenu::getCell(VcpPageMenuCellPos pos, VfxS32 subIndex) const
{
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        return m_cells[pos.index];
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        return m_groupCells[pos.index];
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON)
    {
        return m_cellsInFolderIcon[pos.index][subIndex];
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON)
    {
        return m_groupCellsInFolderIcon[pos.index][subIndex];
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
    {
        return m_cellsInFolderEditor[pos.index];
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
        return NULL;
    }
}

void VappLauncherMmPageMenu::setCell(VcpPageMenuCellPos pos, VcpPageMenuCell *cell, VfxS32 subIndex)
{
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        m_cells[pos.index] = cell;
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        m_groupCells[pos.index] = cell;
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON)
    {
        m_cellsInFolderIcon[pos.index][subIndex] = cell;
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON)
    {
        m_groupCellsInFolderIcon[pos.index][subIndex] = cell;
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
    {
        m_cellsInFolderEditor[pos.index] = cell;
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}

VfxBool VappLauncherMmPageMenu::handlePenDown(const VfxPoint &touchDownPos)
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
                if ((getHover().group == VCP_PAGE_MENU_GROUP_MAIN && getHover().index >= VAPP_LAUNCHER_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT) ||
                    (getHover().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && getHover().index < VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT) ||
                    getHover().group == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
                {
                    m_longPressTimer->setStartDelay(VAPP_LAUNCHER_MM_LONG_PRESS_ORGANIZE_ANOTHER_DELAY);
                    m_longPressTimer->start();
                }
            }
            else
            {
                m_longPressTimer->setStartDelay(VAPP_LAUNCHER_MM_LONG_PRESS_ENTER_ORGANIZE_DELAY);
                m_longPressTimer->start();
            }
        }
    }
    return VFX_TRUE;
}

VfxBool VappLauncherMmPageMenu::handleScroll(const VfxPenEvent &event)
{
    const VfxPoint touchPos = event.getRelPos(this);
    const VfxPoint touchDownPos = event.getRelDownPos(this);
    const VfxS32 diffOrigX = touchPos.x - touchDownPos.x;
    const VfxS32 diffOrigY = touchPos.y - touchDownPos.y;

    if (event.type == VFX_PEN_EVENT_TYPE_ABORT ||
            VFX_ABS(diffOrigX) > VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_X ||
            VFX_ABS(diffOrigY) > VAPP_LAUNCHER_MM_CANCEL_HOVER_THRESHOLD_Y)
    {
        m_longPressTimer->stop();
        setHover(VAPP_LAUNCHER_MM_NO_HOVER);
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
        const VfxS32 elapse = VAPP_LAUNCHER_MM_LONG_SWIPE_THRESHOLD * 2;
        const VfxS32 diffX = 0;
        handleScrollEnd(diffX, elapse);
    }

    return VFX_TRUE;
}

void VappLauncherMmPageMenu::handleScrollEnd(VfxS32 diffX, VfxMsec elapse)
{
    const VfxFloat speed = static_cast<VfxFloat>(diffX * 1000) / elapse;

//    m_menuView->setRotateAngle(0, VAPP_LAUNCHER_MM_ANIMTIME_RELEASE, VFX_TRUE);

    if (m_startPen && !m_menuView->isTransitioning())
    {
        // clicked
        if (getHover().index != MAINMENU_HITTEST_NOT_FOUND)
        {
            if (isFolderCell(getHover()))
            {
                m_menuView->setFolderCellPos(getHover());
                enterFolderMode();
            }
            else if (!getOrganizeMode())
            {
                m_appClicked.postEmit(getCell(getHover()));
            }
        }
    }
    else if (elapse < VAPP_LAUNCHER_MM_LONG_SWIPE_THRESHOLD)
    {
        if (m_canScroll)
        {
            handleScrollSwipe(diffX, speed);
        }
        else
        {
            scrollToPage(m_menuView->getNearestPage(), VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
        }
		m_menuView->setClickFrame(NULL);
        
        checkUpdate();
    }
    else
    {
        // scroll to the nearest page
        scrollToPage(m_menuView->getNearestPage(), VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
		m_menuView->setClickFrame(NULL);
        
        checkUpdate();
    }

    setHover(VAPP_LAUNCHER_MM_NO_HOVER);

    // limiting
    if (m_menuView->getTranslateX() > 0)
    {
        scrollToPage(0, VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
    }
    if (m_menuView->getTranslateX() < m_menuView->getPageTranslateX(getPageCount() - 1) )
    {
        scrollToPage(getPageCount() - 1, VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
    }
}

void VappLauncherMmPageMenu::handleScrollMove(VfxS32 diffOrigX, VfxS32 diffOrigY)
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
//            const VfxFloat rotateAngle = (translateX - 0) * VAPP_LAUNCHER_MM_BOUND_ROTATE_FACTOR;
//            m_menuView->setRotateAngle(rotateAngle , VAPP_LAUNCHER_MM_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = translateX * VAPP_LAUNCHER_MM_BOUND_TRANSLATION_FACTOR;
        }
        if (translateX < m_menuView->getPageTranslateX(getPageCount() - 1))
        {
//            const VfxFloat rotateAngle = (translateX -
//                        ( m_menuView->getPageTranslateX(getPageCount() - 1) ) ) *
//                        VAPP_LAUNCHER_MM_BOUND_ROTATE_FACTOR;
//            m_menuView->setRotateAngle(rotateAngle , VAPP_LAUNCHER_MM_ANIMTIME_INSTANT, VFX_FALSE);
            translateX = m_menuView->getPageTranslateX(getPageCount() - 1) + ((translateX - m_menuView->getPageTranslateX(getPageCount() - 1)) * VAPP_LAUNCHER_MM_BOUND_TRANSLATION_FACTOR);
        }
        m_menuView->setTranslateX(translateX, VAPP_LAUNCHER_MM_ANIMTIME_INSTANT);
        m_pageMoved.emit(translateX + getCurrentPageIndex() * m_menuView->getLayout().pageMargin, VAPP_LAUNCHER_MM_ANIMTIME_INSTANT);

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

void VappLauncherMmPageMenu::handleScrollSwipe(VfxS32 diffX, VfxFloat speed)
{
    if (diffX > VAPP_LAUNCHER_MM_SWIPE_RANGE_THRESHOLD)
    {
        const VfxS32 targetPage = m_menuView->getPreviousPage();
        const VfxS32 duration = calculateSwipeTime(targetPage, speed);
        scrollToPage(targetPage, duration);
    }
    else if (diffX < -VAPP_LAUNCHER_MM_SWIPE_RANGE_THRESHOLD)
    {
        const VfxS32 targetPage = m_menuView->getNextPage();
        const VfxS32 duration = calculateSwipeTime(targetPage, speed);
        scrollToPage(targetPage, duration);
    }
    else
    {
        scrollToPage(m_menuView->getNearestPage(), VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);
    }
}

VfxS32 VappLauncherMmPageMenu::calculateSwipeTime(VfxS32 targetPageIndex, VfxFloat speed)
{
    if (speed == 0)
    {
        return VAPP_LAUNCHER_MM_ANIMTIME_RELEASE;
    }

    const VfxS32 currentPos = m_menuView->getTranslateX();
    const VfxS32 targetPos = m_menuView->getPageTranslateX(targetPageIndex);
    const VfxS32 distance = vfxAbs(targetPos - currentPos);
	const VfxFloat absSpeed = vfxAbs(speed);
    const VfxS32 durationToKeepSpeed = static_cast<VfxS32>( (distance * 1000) / absSpeed + 0.5f);
    const VfxS32 minDuration = VAPP_LAUNCHER_MM_ANIMTIME_MIN_RELEASE;
    const VfxS32 maxDuration = VAPP_LAUNCHER_MM_ANIMTIME_RELEASE;
    return vfxMax(minDuration, vfxMin(maxDuration, durationToKeepSpeed));
}

VfxBool VappLauncherMmPageMenu::handleOrganize(VfxPenEventTypeEnum touchType, const VfxPoint &touchPos)
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

void VappLauncherMmPageMenu::handleOrganizeStart()
{
    if ((getHover().group == VCP_PAGE_MENU_GROUP_MAIN && getHover().index >= VAPP_LAUNCHER_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT) ||
        (getHover().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && getHover().index < VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT) ||
        getHover().group == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
    {
        setOrganizeTo(getHover() );
        m_menuView->setDraggingFrame(getCell(getHover() ) );
        m_delayMovingTo = getHover();
        
        if (getHover().group == VCP_PAGE_MENU_GROUP_MAIN)
        {
            VcpPageMenuCellPos pos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, getHover().index);
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                setDraggingFrameInFolderIcon(getCell(pos, i), i);
            }
            
            m_canDragToExitFolderMode = VFX_FALSE;
        }
        else if (getHover().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
        {
            VcpPageMenuCellPos pos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, getHover().index);
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                setDraggingFrameInFolderIcon(getCell(pos, i), i);
            }
            
            m_canDragToExitFolderMode = VFX_FALSE;
        }
        else
        {
            m_canDragToExitFolderMode = VFX_TRUE;
        }
    }
    else
    {
        setHover(VAPP_LAUNCHER_MM_NO_HOVER);
        setOrganizeTo(VAPP_LAUNCHER_MM_NO_HOVER);
        m_menuView->setDraggingFrame(NULL);
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            setDraggingFrameInFolderIcon(NULL, i);
        }
    }

    scrollToPage(m_menuView->getNearestPage(), VAPP_LAUNCHER_MM_ANIMTIME_INSTANT);
//    m_menuView->setRotateAngle(0, VAPP_LAUNCHER_MM_ANIMTIME_INSTANT, VFX_TRUE);

    checkUpdate();
}

void VappLauncherMmPageMenu::handleOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
        m_menuView->getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
    {
        inFolderOrganizeMove(touchX, touchY);
        
        return;
    }
    
    VfxBool crossPageMove = VFX_FALSE;
    const VfxMsec ctime = vrt_sys_get_time();
    if (ctime - m_lastAutoScrollTime > VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_CD)
    {
        if (touchX < VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if (currentPage == 0)
            {
#ifdef VAPP_LAUNCHER_MM_PAGE_LEFT_EXTENDABLE
                if (getPageCount() < m_menuView->getMaxPageCount(VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER) && m_leftExtended == VFX_FALSE)
                {
                    // can add page
                    crossPageMove = VFX_TRUE;
                    m_leftExtended = VFX_TRUE;
                }
#endif // VAPP_LAUNCHER_MM_PAGE_LEFT_EXTENDABLE
            }
            else
            {
                crossPageMove = VFX_TRUE;
            }
        }
        else if (touchX > getSize().width - VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
        {
            const VfxS32 currentPage = m_menuView->getNearestPage();
            if ( (currentPage >= m_menuView->getMaxPageCount(VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER) - 1) )
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

    if (touchX < VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN ||
        touchX > getSize().width - VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        m_lastAutoScrollTouchPos.x = touchX;
        m_lastAutoScrollTouchPos.y = touchY;
    }
    
    // Use cell center to decide cell position and prepared folder trigger area
    VfxS32 cellCenterX = touchX + m_menuView->getOrganizeDragOffset().x + m_menuView->getDraggingFrame()->getSize().width / 2;
    VfxS32 cellCenterY = touchY + m_menuView->getOrganizeDragOffset().y + m_menuView->getDraggingFrame()->getSize().height / 2;
    VcpPageMenuCellHitAreaEnum hitArea;
    const VcpPageMenuCellPos pos = cellHittest(VfxPoint(cellCenterX, cellCenterY), VFX_FALSE, &hitArea);
    if (crossPageMove && pos.group == VCP_PAGE_MENU_GROUP_MAIN && getOrganizeTo().group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        cancelFolderMode();
        
        crossPageOrganizeMove(touchX, touchY);
        
        m_lastAutoScrollTime = ctime;
        m_autoScrollPageTimer->setStartDelay(VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_CD);
        m_autoScrollPageTimer->start();
    }
    else
    {
        if (!(touchX < VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN ||
              touchX > getSize().width - VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN))
        {
            m_autoScrollPageTimer->stop();
        }
        
        if (pos != m_delayMovingTo || hitArea != m_delayMovingToHitArea)
        {
            cancelFolderMode();
            
            m_delayMovingTo = pos;
            m_delayMovingToHitArea = hitArea;
            m_delayMovingTimer->setStartDelay(VAPP_LAUNCHER_MM_DELAY_MOVING_DELAY);
            m_delayMovingTimer->start();

            m_delayMovingTouchPos.x = cellCenterX;
            m_delayMovingTouchPos.y = cellCenterY;
        }
        
        m_menuView->setDraggingFramePos(touchX, touchY);
        checkUpdate();
    }
}

void VappLauncherMmPageMenu::crossPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    // in this case, because the user touch move is usually slow, the animation shall be slower
    if (touchX < VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        switchOrganizePage(m_menuView->getPreviousPage(), touchX, touchY);
    }
    else if (touchX > getSize().width - VAPP_LAUNCHER_MM_ORGANIZE_AUTO_SCROLL_MARGIN)
    {
        switchOrganizePage(m_menuView->getNextPage(), touchX, touchY);
    }
}

void VappLauncherMmPageMenu::switchOrganizePage(VfxS32 newPage, VfxS32 touchX, VfxS32 touchY)
{
    if (getOrganizeTo().group != VCP_PAGE_MENU_GROUP_MAIN)
    {
        VFX_ASSERT(VFX_FALSE);
    }

#ifdef VAPP_LAUNCHER_MM_PAGE_LEFT_EXTENDABLE
    if (newPage == -1)
    {
        newPage = 0;
        for (VfxS32 i = getPageCount() - 1; i >= 0; --i)
        {
            vcpPageMenuMovePageContent(m_cells, m_menuView->getPageItemCount(), i, i+1,
                                       &m_cellsInFolderIcon[0][0], VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);
        }
        setPageCount(getPageCount() + 1);

        // adjust the cell pos
        VcpPageMenuCellPos target = getOrganizeTo();
        target.index += m_menuView->getPageItemCount();
        setOrganizeTo(target);
    }
#endif // VAPP_LAUNCHER_MM_PAGE_LEFT_EXTENDABLE

    scrollToPage(newPage, VAPP_LAUNCHER_MM_ANIMTIME_RELEASE);

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
        currentDirectPos.index < VAPP_LAUNCHER_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT)
    {
        currentDirectPos.index = VAPP_LAUNCHER_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT;
    }
    putCellTo(currentDirectPos, m_menuView->getDraggingFrame(), m_draggingFrameInFolderIcon, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);

    checkUpdate();
}

void VappLauncherMmPageMenu::inPageOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    VcpPageMenuCellHitAreaEnum hitArea;
    const VcpPageMenuCellPos currentTo = cellHittest(VfxPoint(touchX, touchY), VFX_TRUE, &hitArea);
    const VcpPageMenuCellPos prevOrganizeTo = getOrganizeTo();
    
    if (currentTo.group == prevOrganizeTo.group)
    {
        if (currentTo.index != MAINMENU_HITTEST_NOT_FOUND &&
            ((currentTo.group == VCP_PAGE_MENU_GROUP_MAIN && currentTo.index >= VAPP_LAUNCHER_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT) ||
             (currentTo.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && currentTo.index < VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)))
        {
            if (prevOrganizeTo != currentTo)
            {
                const VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
                
                if (hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_CENTER &&
                    !isFolderCell(prevOrganizeTo) &&
                    currentDirectPos.index != MAINMENU_HITTEST_NOT_FOUND &&
                    (currentTo.group == VCP_PAGE_MENU_GROUP_MAIN ||
                     (currentTo.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && isFolderCell(currentTo))))
                {
                    prepareFolderMode(currentTo);
                }
                else if ((currentTo.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && !isFolderCell(currentTo)) ||
                         isFolderCell(prevOrganizeTo) ||
                         currentDirectPos.index == MAINMENU_HITTEST_NOT_FOUND ||
                         (currentTo.index > prevOrganizeTo.index && (hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_TOP ||
                                                                     hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_CENTER ||
                                                                     hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_DOWN)) ||
                         (currentTo.index < prevOrganizeTo.index && (hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_TOP ||
                                                                     hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_CENTER ||
                                                                     hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_DOWN)))
                {
                    cancelFolderMode();
                    
                    setOrganizeTo(currentTo);
                    
                    if (getOrganizeTo().index > prevOrganizeTo.index)
                    {
                        compactCells(prevOrganizeTo, 1);
                    }
                    else
                    {
                        compactCells(prevOrganizeTo, -1);
                    }
                }
                else
                {
                    cancelFolderMode();
                }
            }
            else
            {
                cancelFolderMode();
            }
        }
    }
    else if (currentTo.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        const VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
        
        if (hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_CENTER &&
            !isFolderCell(prevOrganizeTo) &&
            currentDirectPos.index != MAINMENU_HITTEST_NOT_FOUND)
        {
            prepareFolderMode(currentTo);
        }
        else if (isFolderCell(prevOrganizeTo) ||
                 currentDirectPos.index == MAINMENU_HITTEST_NOT_FOUND ||
                 (hitArea != VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_DOWN &&
                  hitArea != VCP_PAGE_MENU_CELL_HIT_AREA_CENTER_DOWN &&
                  hitArea != VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_DOWN))
        {
            cancelFolderMode();
            
            // remove the dragging cell from the old page
            removeCellFrom(getOrganizeTo() );
            
            // put the dragging cell to the new page
            putCellTo(currentDirectPos, m_menuView->getDraggingFrame(), m_draggingFrameInFolderIcon, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);
        }
        else
        {
            cancelFolderMode();
        }
    }
    else if (currentTo.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        const VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
        
        if (hitArea == VCP_PAGE_MENU_CELL_HIT_AREA_CENTER &&
            !isFolderCell(prevOrganizeTo) &&
            currentDirectPos.index != MAINMENU_HITTEST_NOT_FOUND &&
            isFolderCell(currentTo))
        {
            prepareFolderMode(currentTo);
        }
        else if (isFolderCell(prevOrganizeTo) ||
                 currentDirectPos.index == MAINMENU_HITTEST_NOT_FOUND ||
                 !isFolderCell(currentTo) ||
                 (hitArea != VCP_PAGE_MENU_CELL_HIT_AREA_LEFT_TOP &&
                  hitArea != VCP_PAGE_MENU_CELL_HIT_AREA_CENTER_TOP &&
                  hitArea != VCP_PAGE_MENU_CELL_HIT_AREA_RIGHT_TOP))
        {
            cancelFolderMode();
            
            VfxBool isFull = VFX_TRUE;
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT; ++i)
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
                if (currentDirectPos.index < VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)
                {
                    removeCellFrom(getOrganizeTo() );
            
                    // put the dragging cell to the new page
                    putCellTo(currentDirectPos, m_menuView->getDraggingFrame(), m_draggingFrameInFolderIcon, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);
                }
            }
        }
        else
        {
            cancelFolderMode();
        }
    }

    m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
    checkUpdate();
}

void VappLauncherMmPageMenu::compactCells(VcpPageMenuCellPos prevOrganizeTo, VfxS32 direction)
{
    if (direction == 0)
        return;
	
    VfxS32 scrIndex = 0;
    for (VfxS32 i = prevOrganizeTo.index; ; )
    {
        scrIndex = i + direction;
        
        VcpPageMenuCellPos dest(prevOrganizeTo.group, i);
        VcpPageMenuCellPos src(prevOrganizeTo.group, scrIndex);
        setCell(dest, getCell(src) );
        if (getOrganizeTo().group == VCP_PAGE_MENU_GROUP_MAIN)
        {
            VcpPageMenuCellPos dest(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, i);
            VcpPageMenuCellPos src(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, scrIndex);
            for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
            {
                setCell(dest, getCell(src, j), j);
            }
        }
        else if (getOrganizeTo().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
        {
            VcpPageMenuCellPos dest(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, i);
            VcpPageMenuCellPos src(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, scrIndex);
            for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
            {
                setCell(dest, getCell(src, j), j);
            }
        }
        if (direction > 0)
        {
            ++i;
            if (i >= getOrganizeTo().index)
                break;
        }
        else
        {
            --i;
            if (i <= getOrganizeTo().index)
                break;
        }
    }
	
    setCell(getOrganizeTo(), m_menuView->getDraggingFrame());
	
    if (getOrganizeTo().group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        VcpPageMenuCellPos pos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, getOrganizeTo().index);
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            setCell(pos, m_draggingFrameInFolderIcon[i], i);
        }
    }
    else if (getOrganizeTo().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        VcpPageMenuCellPos pos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, getOrganizeTo().index);
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            setCell(pos, m_draggingFrameInFolderIcon[i], i);
        }
    }
}

void VappLauncherMmPageMenu::handleOrganizePut(VfxBool isCheckUpdate)
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
    
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE)
    {
        if (getFolderCount() >= VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER_DATA)
        {
            cancelFolderMode();
            
            m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), getOrganizeTo().group);
            
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                                 MMI_EVENT_INFO_BALLOON,
                                 MMI_NMGR_BALLOON_TYPE_INFO,
                                 VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_MM_CANNOT_CREATE_FOLDER).getBuf());
        }
        else
        {
            VcpPageMenuCellPos folderPos = m_menuView->getFolderCellPos();
            
            // reserve dragging cell space in main group
            m_invalidCellPos = getOrganizeTo();
            setCell(m_invalidCellPos, NULL);
            getCell(folderPos)->addChildFrame(m_menuView->getDraggingFrame());
            
            if (folderPos.group == VCP_PAGE_MENU_GROUP_MAIN)
            {
                // put the dragging cell to the folder icon
                putDraggingCell(folderPos, VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, 1, VFX_FALSE);
            }
            else if (folderPos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
            {
                // put the dragging cell to the folder icon
                putDraggingCell(folderPos, VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, 1, VFX_FALSE);
            }
            else
            {
                VFX_ASSERT(0);
            }
            
            enterFolderMode();
        }
    }
    else if (m_menuView->getFolderState() == VCP_PAGE_MENU_PREPARE_TO_FOLDER_MODE)
    {
        VfxBool isThrowIn = VFX_FALSE;
        VcpPageMenuCellPos folderPos = m_menuView->getFolderCellPos();
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            if (folderPos.group == VCP_PAGE_MENU_GROUP_MAIN)
            {
                if (getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, folderPos.index), i) == NULL)
                {
                    // put the dragging cell to the folder icon
                    putDraggingCell(folderPos, VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, i, VFX_TRUE);

                    isThrowIn = VFX_TRUE;
                    
                    break;
                }
            }
            else if (folderPos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
            {
                if (getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, folderPos.index), i) == NULL)
                {
                    // put the dragging cell to the folder icon
                    putDraggingCell(folderPos, VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, i, VFX_TRUE);
                    
                    isThrowIn = VFX_TRUE;
                    
                    break;
                }
            }
            else
            {
                VFX_ASSERT(0);
            }
        }

        if (!isThrowIn)
        {
            cancelFolderMode();
            m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), getOrganizeTo().group);
        }
    }
    else if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
             m_menuView->getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
    {
        if (m_menuView->getDraggingFrame() != NULL && !isInFolderEditor(m_menuView->getDraggingFrame()))
        {
            exitFolderMode();
        }
        else
        {
            refreshCellsInFolderIcon();
        }
        
        m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), getOrganizeTo().group);
    }
    else
    {
        m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), getOrganizeTo().group);
    }
    
    m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);

    putHoldFrame();
    setHover(VAPP_LAUNCHER_MM_NO_HOVER);
    m_menuView->setDraggingFrame(NULL);
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
    {
        setDraggingFrameInFolderIcon(NULL, i);
    }
    m_leftExtended = VFX_FALSE;
    m_rightExtended = VFX_FALSE;
    if (isCheckUpdate)
    {
        checkUpdate();
    }
}

void VappLauncherMmPageMenu::putDraggingCell(VcpPageMenuCellPos folderPos, VfxS32 group, VfxS32 subIndex, VfxBool isFolder)
{
    setCell(VcpPageMenuCellPos(group, folderPos.index), m_menuView->getDraggingFrame(), subIndex);
    m_menuView->changeCellGroup(m_menuView->getDraggingFrame(), group);
    if (isFolder)
    {
        getCell(folderPos)->addChildFrame(m_menuView->getDraggingFrame());
        
        cancelFolderMode();
        
        // remove dragging cell from main group
        removeCellFrom(getOrganizeTo());
    }
}

void VappLauncherMmPageMenu::handleOrganizeEnd(VfxBool isCheckUpdate)
{
    // ensure the dragging frame is put
    handleOrganizePut(isCheckUpdate);

    compactPages(isCheckUpdate);

    if (isCheckUpdate)
    {
        checkUpdate();
    }
}

void VappLauncherMmPageMenu::putHoldFrame()
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

VfxBool VappLauncherMmPageMenu::putHoldFrameAfterPage(VfxS32 page)
{
    const VfxS32 start = (page + 1) * m_menuView->getPageItemCount();
    for (VfxS32 index = start; index < VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER; ++index)
    {
        if (m_cells[index] == NULL)
        {
            const VfxS32 end = index;
            for (VfxS32 i = end; i > start; --i)
            {
                m_cells[i] = m_cells[i - 1];
                for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
                {
                    m_cellsInFolderIcon[i][j] = m_cellsInFolderIcon[i - 1][j];
                }
            }
            m_cells[start] = getHoldFrame();
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                m_cellsInFolderIcon[start][i] = getHoldFrameInFolderIcon(i);
            }
            
            if (end + 1 > getPageCount() * m_menuView->getPageItemCount() )
            {
                setPageCount(getPageCount() + 1);
            }
            setHoldFrame(NULL);
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                setHoldFrameInFolderIcon(NULL, i);
            }
            
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VfxBool VappLauncherMmPageMenu::putHoldFrameBeforePage(VfxS32 page)
{
    for (VfxS32 pageIndex = page - 1; pageIndex >= 0; --pageIndex)
    {
        for (VfxS32 i = 0; i < m_menuView->getPageItemCount(); ++i)
        {
            const VfxS32 index = pageIndex * m_menuView->getPageItemCount() + i;
            if (m_cells[index] == NULL)
            {
                m_cells[index] = getHoldFrame();
                for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
                {
                    m_cellsInFolderIcon[index][j] = getHoldFrameInFolderIcon(j);
                }
                
                setHoldFrame(NULL);
                for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
                {
                    setHoldFrameInFolderIcon(NULL, j);
                }
                
                return VFX_TRUE;
            }
        }
    }
    return VFX_FALSE;
}

void VappLauncherMmPageMenu::removeCellFrom(VcpPageMenuCellPos pos, VfxS32 subIndex)
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

            for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
            {
                VcpPageMenuCellPos dest(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, i);
                VcpPageMenuCellPos src(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, i+1);
                setCell(dest, getCell(src, j), j);
            }
        }
        if (getHoldFrame() != NULL)
        {
            m_cells[pageEnd - 1] = getHoldFrame();
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                m_cellsInFolderIcon[pageEnd - 1][i] = getHoldFrameInFolderIcon(i);
            }
            
            setHoldFrame(NULL);
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                setHoldFrameInFolderIcon(NULL, i);
            }
        }
        else
        {
            setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, pageEnd - 1), NULL);
            
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, pageEnd - 1), NULL, i);
            }
        }
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        const VfxS32 organizeIndex = pos.index;
        const VfxS32 pageEnd = VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT;
        for (VfxS32 i = organizeIndex; i < pageEnd - 1; ++i)
        {
            VcpPageMenuCellPos dest(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, i);
            VcpPageMenuCellPos src(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, i+1);
            setCell(dest, getCell(src) );

            for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
            {
                VcpPageMenuCellPos dest(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, i);
                VcpPageMenuCellPos src(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, i+1);
                setCell(dest, getCell(src, j), j);
            }
        }
        setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, pageEnd - 1), NULL);
        
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, pageEnd - 1), NULL, i);
        }
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON ||
             pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON)
    {
        for (VfxS32 i = subIndex; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER - 1; ++i)
        {
            setCell(pos,
                    getCell(pos, i + 1),
                    i);
        }
        setCell(pos, NULL, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER - 1);
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
    {
        const VfxS32 organizeIndex = pos.index;
        const VfxS32 folderEditorEnd = VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER;
        for (VfxS32 i = organizeIndex; i < folderEditorEnd - 1; ++i)
        {
            VcpPageMenuCellPos dest(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, i);
            VcpPageMenuCellPos src(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, i+1);
            setCell(dest, getCell(src) );
        }
        setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, folderEditorEnd - 1), NULL);
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}

void VappLauncherMmPageMenu::putCellTo(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell *cell, VcpPageMenuCell **cellInFolderIcon, VfxS32 cellInFolderIconCount)
{
    if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        putCellToMain(currentDirectPos, cell, cellInFolderIcon, cellInFolderIconCount);
    }
    else if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        putCellToBar(currentDirectPos, cell, cellInFolderIcon, cellInFolderIconCount);
    }
/*    else if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON)
    {
        putCellToMainFolderIcon(currentDirectPos, cell);
    }
    else if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON)
    {
        putCellToBarFolderIcon(currentDirectPos, cell);
    }*/
    else if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
    {
        putCellToFolderEditor(currentDirectPos, cell);
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }
}

void VappLauncherMmPageMenu::putCellToMain(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell *cell, VcpPageMenuCell **cellInFolderIcon, VfxS32 cellInFolderIconCount)
{
    const VfxS32 firstInPage = m_menuView->getNearestPage() * m_menuView->getPageItemCount();
    if (m_cells[firstInPage] == NULL)
    {
        m_cells[firstInPage] = cell;
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            m_cellsInFolderIcon[firstInPage][i] = cellInFolderIcon[i];
        }
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
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                setHoldFrameInFolderIcon(m_cellsInFolderIcon[currentPageEnd - 1][i], i);
                m_cellsInFolderIcon[currentPageEnd - 1][i] = NULL;
            }
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
                    for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
                    {
                        m_cellsInFolderIcon[i][j] = cellInFolderIcon[j];
                    }
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
                for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
                {
                    m_cellsInFolderIcon[i][j] = m_cellsInFolderIcon[i - 1][j];
                }
            }
            m_cells[currentDirect] = cell;
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
            {
                m_cellsInFolderIcon[currentDirect][i] = cellInFolderIcon[i];
            }
            setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN, currentDirect) );
        }
    }
}

void VappLauncherMmPageMenu::putCellToBar(VcpPageMenuCellPos currentDirectPos, VcpPageMenuCell *cell, VcpPageMenuCell **cellInFolderIcon, VfxS32 cellInFolderIconCount)
{
    if (currentDirectPos.index == MAINMENU_HITTEST_NOT_FOUND)
    {
        // append to the end of this bar
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT; ++i)
        {
            if (m_groupCells[i] == NULL)
            {
                m_groupCells[i] = cell;
                for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
                {
                    m_groupCellsInFolderIcon[i][j] = cellInFolderIcon[j];
                }
                setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR, i) );
                break;
            }
        }
    }
    else
    {
        // around cells
        for (VfxS32 i = VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT - 1; i > currentDirectPos.index; --i)
        {
            m_groupCells[i] = m_groupCells[i - 1];
            for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++j)
            {
                m_groupCellsInFolderIcon[i][j] = m_groupCellsInFolderIcon[i - 1][j];
            }
        }
        setCell(currentDirectPos, cell);
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            m_groupCellsInFolderIcon[currentDirectPos.index][i] = cellInFolderIcon[i];
        }
        setOrganizeTo(currentDirectPos);
    }
}

VfxBool VappLauncherMmPageMenu::isFolderCell(VcpPageMenuCellPos pos)
{
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        if (getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, pos.index), 0) != NULL)
        {
            return VFX_TRUE;
        }
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        if (getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, pos.index), 0) != NULL)
        {
            return VFX_TRUE;
        }
    }
    
    return VFX_FALSE;
}

VfxBool VappLauncherMmPageMenu::isInFolderIcon(VcpPageMenuCell *cell, VcpPageMenuCellPos pos)
{
    if (cell != NULL)
    {
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            if ((pos.group == VCP_PAGE_MENU_GROUP_MAIN && cell == m_cellsInFolderIcon[pos.index][i]) ||
                (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR && cell == m_groupCellsInFolderIcon[pos.index][i]))
            {
                return VFX_TRUE;
            }
        }
    }

    return VFX_FALSE;
}

VfxBool VappLauncherMmPageMenu::isInFolderEditor(VcpPageMenuCell *cell)
{
    if (cell != NULL)
    {
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            if (cell == m_cellsInFolderEditor[i])
            {
                return VFX_TRUE;
            }
        }
    }

    return VFX_FALSE;
}

VfxBool VappLauncherMmPageMenu::isHitFolderEditor(VfxS32 touchX, VfxS32 touchY)
{
    if (touchX < m_folderEditor->getPos().x ||
        touchX > m_folderEditor->getPos().x + m_folderEditor->getSize().width ||
        touchY < m_folderEditor->getPos().y ||
        touchY > m_folderEditor->getPos().y + m_folderEditor->getSize().height)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

void VappLauncherMmPageMenu::prepareFolderMode(VcpPageMenuCellPos toFolderModePos)
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_NOT_FOLDER_MODE)
    {
        VappLauncherMmCell *folderCell;
        if (!isFolderCell(toFolderModePos))
        {
            setFolderState(VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE);
            
            m_tempCellInFolderIcon = getCell(toFolderModePos);
            
            // Change original cell's group
            m_menuView->changeCellGroup(m_tempCellInFolderIcon, VCP_PAGE_MENU_GROUP_FOLDER_ICON_TEMP);
            VappLauncherMmCell *appCell = static_cast<VappLauncherMmCell *>(m_tempCellInFolderIcon);
            appCell->setTextFrameHidden(VFX_TRUE);
            appCell->setUninstalledButtonHidden(VFX_TRUE);
            setCell(toFolderModePos, NULL);
            
            // Create temp folder cell
            folderCell = ::vappLauncherMmCreateCellRaw(VfxImageSrc(), VAPP_LAUNCHER_MM_DEFAULT_FOLDER_NAME, this);
            folderCell->setIsUnhittable(VFX_TRUE);
            if (toFolderModePos.group == VCP_PAGE_MENU_GROUP_MAIN)
            {
                setMenuItem(toFolderModePos.index, folderCell);
            }
            else if (toFolderModePos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
            {
                setGroupMenuItem(toFolderModePos.index, folderCell);
            }
            else
            {
                VFX_ASSERT(0);
            }
            folderCell->onCellDisplay();
            folderCell->setFolderFrameHidden(VFX_FALSE);
            folderCell->addChildFrame(m_tempCellInFolderIcon);
            folderCell->sendToBack();
        }
        else
        {
            setFolderState(VCP_PAGE_MENU_PREPARE_TO_FOLDER_MODE);
            
            folderCell = static_cast<VappLauncherMmCell *>(getCell(toFolderModePos));
        }
        folderCell->setFolderFrameScale(VFX_TRUE);
        folderCell->setTextFrameHidden(VFX_TRUE);
        
        // Hide dragging frame's text
        VappLauncherMmCell *draggingCell = static_cast<VappLauncherMmCell *>(m_menuView->getDraggingFrame());
        draggingCell->setTextFrameHidden(VFX_TRUE);
        draggingCell->setUninstalledButtonHidden(VFX_TRUE);
        
        m_menuView->setFolderCellPos(toFolderModePos);
        
        m_startToFolderModeTimer->setStartDelay(VAPP_LAUNCHER_MM_START_TO_FOLDER_MODE_DELAY);
        m_startToFolderModeTimer->start();
    }
}

void VappLauncherMmPageMenu::cancelFolderMode()
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE ||
        m_menuView->getFolderState() == VCP_PAGE_MENU_PREPARE_TO_FOLDER_MODE)
    {
        // Get folder cell
        VappLauncherMmCell *folderCell = static_cast<VappLauncherMmCell *>(getCell(m_menuView->getFolderCellPos()));
        if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE)
        {
            // Change back to original group
            addChildFrame(m_tempCellInFolderIcon);
            m_tempCellInFolderIcon->sendToBack();
            m_menuView->changeCellGroup(m_tempCellInFolderIcon, m_menuView->getFolderCellPos().group);
            setCell(m_menuView->getFolderCellPos(), m_tempCellInFolderIcon);
            VappLauncherMmCell *appCell = static_cast<VappLauncherMmCell *>(m_tempCellInFolderIcon);
            appCell->setTextFrameHidden(VFX_FALSE);
            appCell->setUninstalledButtonHidden(VFX_FALSE);
            
            // Close temp folder cell
            VFX_OBJ_CLOSE(folderCell);
            
            m_tempCellInFolderIcon = NULL;
        }
        else if (m_menuView->getFolderState() == VCP_PAGE_MENU_PREPARE_TO_FOLDER_MODE)
        {
            folderCell->setFolderFrameScale(VFX_FALSE);
            folderCell->setTextFrameHidden(VFX_FALSE);
        }
        
        setFolderState(VCP_PAGE_MENU_NOT_FOLDER_MODE);
        
        // Show dragging frame's text
        if (!isInFolderIcon(m_menuView->getDraggingFrame(), m_menuView->getFolderCellPos()))
        {
            VappLauncherMmCell *draggingCell = static_cast<VappLauncherMmCell *>(m_menuView->getDraggingFrame());
            draggingCell->setTextFrameHidden(VFX_FALSE);
            draggingCell->setUninstalledButtonHidden(VFX_FALSE);
        }

        m_menuView->setFolderCellPos(VcpPageMenuCellPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND));
        
        m_startToFolderModeTimer->stop();
    }
}

void VappLauncherMmPageMenu::enterFolderMode()
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_NOT_FOLDER_MODE ||
        m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE ||
        m_menuView->getFolderState() == VCP_PAGE_MENU_PREPARE_TO_FOLDER_MODE)
    {
        // Get folder cell
        VappLauncherMmCell *folderCell = static_cast<VappLauncherMmCell *>(getCell(m_menuView->getFolderCellPos()));
        if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_PREPARE_TO_FOLDER_MODE)
        {
            setFolderState(VCP_PAGE_MENU_FIRST_FOLDER_MODE);
            
            // Change original cell's group
            VcpPageMenuCellPos cellInFolderPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND);
            if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_MAIN)
            {
                m_menuView->changeCellGroup(m_tempCellInFolderIcon, VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON);
                cellInFolderPos.group = VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON;
            }
            else if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
            {
                m_menuView->changeCellGroup(m_tempCellInFolderIcon, VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON);
                cellInFolderPos.group = VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON;
            }
            else
            {
                VFX_ASSERT(0);
            }
            cellInFolderPos.index = m_menuView->getFolderCellPos().index;
            setCell(cellInFolderPos, m_tempCellInFolderIcon, 0);
            VappLauncherMmCell *appCell = static_cast<VappLauncherMmCell *>(m_tempCellInFolderIcon);
            appCell->setTextFrameHidden(VFX_TRUE);
            
            folderCell->setFolderFrameScale(VFX_FALSE);
            
            // Show dragging frame's text
            if (!isInFolderIcon(m_menuView->getDraggingFrame(), m_menuView->getFolderCellPos()))
            {
                VappLauncherMmCell *draggingCell = static_cast<VappLauncherMmCell *>(m_menuView->getDraggingFrame());
                draggingCell->setTextFrameHidden(VFX_FALSE);
                draggingCell->setUninstalledButtonHidden(VFX_FALSE);
            }
            
            m_tempCellInFolderIcon = NULL;
            
            // Add folder count
            setFolderCount(getFolderCount() + 1);
        }
        else if (m_menuView->getFolderState() == VCP_PAGE_MENU_PREPARE_TO_FOLDER_MODE)
        {
            setFolderState(VCP_PAGE_MENU_FOLDER_MODE);
            
            folderCell->setFolderFrameScale(VFX_FALSE);
            
            // Show dragging frame's text
            if (!isInFolderIcon(m_menuView->getDraggingFrame(), m_menuView->getFolderCellPos()))
            {
                VappLauncherMmCell *draggingCell = static_cast<VappLauncherMmCell *>(m_menuView->getDraggingFrame());
                draggingCell->setTextFrameHidden(VFX_FALSE);
                draggingCell->setUninstalledButtonHidden(VFX_FALSE);
            }
        }
        else if (m_menuView->getFolderState() == VCP_PAGE_MENU_NOT_FOLDER_MODE)
        {
            setFolderState(VCP_PAGE_MENU_FOLDER_MODE);

            folderCell->setTextFrameHidden(VFX_TRUE);
        }

        if (m_startToFolderModeTimer->getIsEnabled())
        {
            m_startToFolderModeTimer->stop();
        }
        
        // Create folder editor UI
        createFolderEditor(m_menuView->getFolderCellPos());
        
        m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
        
        m_folderModeChanged.postEmit(VFX_TRUE);
        
        checkUpdate();
    }
}

void VappLauncherMmPageMenu::exitFolderMode()
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
        m_menuView->getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
    {
        // Get folder cell
        VappLauncherMmCell *folderCell = static_cast<VappLauncherMmCell *>(getCell(m_menuView->getFolderCellPos()));
        if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE)
        {
            VcpPageMenuCell *cellInFolderEditor;
            cellInFolderEditor = getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, 1));
            if (cellInFolderEditor == NULL)
            {
                // Change back to original group
                cellInFolderEditor = getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, m_menuView->getFolderCellPos().index), 0);
                setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, m_menuView->getFolderCellPos().index), NULL, 0);
                addChildFrame(cellInFolderEditor);
                cellInFolderEditor->sendToBack();
                m_menuView->changeCellGroup(cellInFolderEditor, m_menuView->getFolderCellPos().group);
                setCell(m_menuView->getFolderCellPos(), cellInFolderEditor);
                VappLauncherMmCell *appCell = static_cast<VappLauncherMmCell *>(cellInFolderEditor);
                appCell->setTextFrameHidden(VFX_FALSE);
                // Support uninstall icon, query app to see if can be deleted.
                mmi_app_package_name_struct *installedAppArray = NULL;
                U32 installedAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
                if (installedAppCount)
                {
                    VFX_SYS_ALLOC_MEM(installedAppArray, sizeof(mmi_app_package_name_struct) * installedAppCount);
                    mmi_ret result;
                    result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installedAppArray, installedAppCount);
                    VFX_ASSERT(result != MMI_RET_ERR);
                }
                mmi_app_package_name_struct appName;
                appCell->getCellAppName(appName);
                appCell->setIsInstalled(vappLauncherMmIsInstalledApp(appName, installedAppArray, installedAppCount));
                appCell->setUninstalledButtonHidden(VFX_FALSE);
                if (installedAppArray)
                {
                    VFX_SYS_FREE_MEM(installedAppArray);
                }      
                
                // Close temp folder cell
                VFX_OBJ_CLOSE(folderCell);
                
                // Minus folder count
                setFolderCount(getFolderCount() - 1);
            }
            else
            {
                folderCell->setTextFrameHidden(VFX_FALSE);
            }
        }
        else if (m_menuView->getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
        {
            VcpPageMenuCell *cellInFolderEditor;
            cellInFolderEditor = getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, 0));
            if (cellInFolderEditor == NULL)
            {
                // Close temp folder cell
                setCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, m_menuView->getFolderCellPos().index), NULL, 0);
                removeCellFrom(m_menuView->getFolderCellPos());
                VFX_OBJ_CLOSE(folderCell);
                
                // Minus folder count
                setFolderCount(getFolderCount() - 1);
            }
            else
            {
                folderCell->setTextFrameHidden(VFX_FALSE);
            }
        }
        
        setFolderState(VCP_PAGE_MENU_NOT_FOLDER_MODE);
        
        if (m_invalidCellPos != VcpPageMenuCellPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND))
        {
            // remove the dragging cell space from the main group when exiting folder mode
            removeCellFrom(m_invalidCellPos);
            m_invalidCellPos = VcpPageMenuCellPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND);
        }
        
        m_menuView->setFolderCellPos(VcpPageMenuCellPos(MAINMENU_HITTEST_NOT_FOUND, MAINMENU_HITTEST_NOT_FOUND));
        
        // Close folder editor UI
        closeFolderEditor();
        
        m_menuView->setAnimDirty(VAPP_LAUNCHER_MM_ORGANIZE_DURATION);
        
        m_folderModeChanged.postEmit(VFX_FALSE);
        
        checkUpdate();
    }
}

void VappLauncherMmPageMenu::createFolderEditor(VcpPageMenuCellPos pos)
{
    // Create folder editor frame
    VfxS32 cellCountInFolder = 0;
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
    {
        if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
        {
            if (m_cellsInFolderIcon[pos.index][i] == NULL)
            {
                break;
            }
        }
        else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
        {
            if (m_groupCellsInFolderIcon[pos.index][i] == NULL)
            {
                break;
            }
        }
        else
        {
            VFX_ASSERT(0);
        }
        
        ++cellCountInFolder;
    }
    VfxS32 contentHeight;
    if (m_menuView->getDraggingFrame() != NULL && cellCountInFolder < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER)
    {
        contentHeight = VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_Y *
                        (cellCountInFolder / VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_COLUMN_COUNT + 1);
    }
    else
    {
        contentHeight = VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_Y *
                        ((cellCountInFolder - 1) / VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_COLUMN_COUNT + 1);
    }
    VfxS32 folderEditorPosY = 0;
    VfxS32 folderEditorHeight = VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN +
                                VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_HEIGHT +
                                contentHeight + 
                                VAPP_LAUNCHER_MM_FOLDER_EDITOR_BOTTOM_MARGIN;
    VfxS32 cellInFolderEditorStartY = 0;
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        folderEditorHeight += VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW).getSize().height;
        folderEditorPosY = m_menuView->getLayout().cellStartY +
                           pos.index % m_menuView->getPageItemCount() / m_menuView->getLayout().columnCount * m_menuView->getLayout().cellOffsetY +
                           VAPP_LAUNCHER_MM_FOLDER_EDITOR_MAIN_SHIFT_Y;
        if (folderEditorPosY + folderEditorHeight > getSize().height)
        {
            folderEditorPosY = getSize().height - folderEditorHeight;
        }
        
        cellInFolderEditorStartY = folderEditorPosY +
                                   VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW).getSize().height +
                                   VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN +
                                   VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_HEIGHT;
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        folderEditorHeight += VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW_DOWN).getSize().height;
        folderEditorPosY = m_menuView->getLayout().bottomBarOffsetY - folderEditorHeight;
        
        cellInFolderEditorStartY = folderEditorPosY +
                                   VAPP_LAUNCHER_MM_FOLDER_EDITOR_TOP_MARGIN +
                                   VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_HEIGHT;
    }
    VFX_OBJ_CREATE(m_folderEditor, VappLuancherMmFolderEditor, this);
    m_folderEditor->setPos(0, folderEditorPosY);
    m_folderEditor->setSize(getSize().width, folderEditorHeight);
    m_folderEditor->setAutoAnimate(VFX_TRUE);

    // Create cells in folder editor
    createCellsInFolderEditor(cellInFolderEditorStartY);

    if (m_menuView->getDraggingFrame())
    {
        m_menuView->getDraggingFrame()->bringToFront();
    }
    
    // Create folder editor background frame
    VFX_OBJ_CREATE(m_folderBg, VfxFrame, m_folderEditor);
    m_folderBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_BG));
    m_folderBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        m_folderBg->setPos(0, VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW).getSize().height);
        m_folderBg->setSize(getSize().width,
                            folderEditorHeight - VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW).getSize().height);
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        m_folderBg->setPos(0, 0);
        m_folderBg->setSize(getSize().width,
                            folderEditorHeight - VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW_DOWN).getSize().height);
    }
    
    // Create folder arrow frame
    VfxS32 folderArrowPosX = m_menuView->getLayout().cellStartX +
                             pos.index % m_menuView->getLayout().columnCount * m_menuView->getLayout().cellOffsetX +
                             m_menuView->getLayout().cellOffsetX / 2;
    VFX_OBJ_CREATE(m_folderArrow, VfxImageFrame, m_folderEditor);
    m_folderArrow->setAnchor(0.5f, 0.0f);
    if (pos.group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        m_folderArrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW));
        m_folderArrow->setPos(folderArrowPosX, VAPP_LAUNCHER_MM_FOLDER_EDITOR_ARROW_UP_POS_SHIFT_Y);
    }
    else if (pos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        m_folderArrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW_DOWN));
        m_folderArrow->setPos(folderArrowPosX,
                              folderEditorHeight - VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW_DOWN).getSize().height + VAPP_LAUNCHER_MM_FOLDER_EDITOR_ARROW_DOWN_POS_SHIFT_Y);
    }

    // Create folder name text frame or text editor
    updateFolderEditorText(getOrganizeMode());
}

void VappLauncherMmPageMenu::updateFolderEditorText(VfxBool organizeMode)
{
    if (m_menuView->getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE ||
        m_menuView->getFolderState() == VCP_PAGE_MENU_FOLDER_MODE)
    {
        VfxWString folderName;
        VappLauncherMmCell *folderCell = static_cast<VappLauncherMmCell *>(getCell(m_menuView->getFolderCellPos()));
        folderCell->getCellTitle(&folderName);
        
        if (organizeMode)
        {
            if (m_folderNameTextEditor == NULL)
            {
                VFX_OBJ_CREATE(m_folderNameTextEditor, VcpTextEditor, m_folderBg);
                m_folderNameTextEditor->setPos(VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_X,
                                               VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_Y);
                m_folderNameTextEditor->setSize(getSize().width - VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_X * 2,
                                                VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_HEIGHT);
                m_folderNameTextEditor->setText(folderName, VAPP_LAUNCHER_MM_APP_FOLDER_LENGTH);
                VsrvInputBinding inputBinding(IMM_INPUT_TYPE_SENTENCE, IME_DISABLE_SETTING_ENTRY_BUTTON, 0, m_folderNameTextEditor->m_editing);
                m_folderNameTextEditor->setIME(inputBinding);
                m_folderNameTextEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
                m_folderNameTextEditor->setAutoDeactivated(VFX_TRUE);
                m_folderNameTextEditor->m_signalActivated.connect(this, &VappLauncherMmPageMenu::onFolderNameTextEditorActivated);
            }
        
            VFX_OBJ_CLOSE(m_folderNameTextFrame);
        }
        else
        {
            if (m_folderNameTextFrame == NULL)
            {
                VFX_OBJ_CREATE(m_folderNameTextFrame, VfxTextFrame, m_folderBg);
                m_folderNameTextFrame->setPos(VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_X,
                                              VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_Y);
                m_folderNameTextFrame->setSize(getSize().width - VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_POS_X * 2,
                                               VAPP_LAUNCHER_MM_FOLDER_EDITOR_NAME_HEIGHT);
                m_folderNameTextFrame->setString(folderName);
                m_folderNameTextFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
                m_folderNameTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            }
        
            VFX_OBJ_CLOSE(m_folderNameTextEditor);
        }
    }
}

void VappLauncherMmPageMenu::onFolderNameTextEditorActivated(VcpTextEditor *sender, VfxBool activated)
{
    if ((getFolderState() == VCP_PAGE_MENU_FIRST_FOLDER_MODE || getFolderState() == VCP_PAGE_MENU_FOLDER_MODE) &&
        getOrganizeMode() &&
        !activated)
    {
        saveFolderName();
    }
}

void VappLauncherMmPageMenu::saveFolderName()
{
    VappLauncherMmCell *folderCell = static_cast<VappLauncherMmCell *>(getCell(m_menuView->getFolderCellPos()));
    if (vfx_sys_wcslen(m_folderNameTextEditor->getText()) > 0)
    {
        folderCell->setCellTitle(VFX_WSTR_MEM(m_folderNameTextEditor->getText()));
    }
    else
    {
        VfxWString folderName;
        folderCell->getCellTitle(&folderName);
        m_folderNameTextEditor->setText(folderName, VAPP_LAUNCHER_MM_APP_FOLDER_LENGTH);
    }
}

void VappLauncherMmPageMenu::closeFolderEditor()
{
    // Close folder editor frame
    VFX_OBJ_CLOSE(m_folderNameTextFrame);
    VFX_OBJ_CLOSE(m_folderNameTextEditor);
    VFX_OBJ_CLOSE(m_folderEditor);
    
    m_menuView->setClickFrame(NULL);
    
    // Close cells in folder editor
    closeCellsInFolderEditor();
}

void VappLauncherMmPageMenu::createCellsInFolderEditor(VfxS32 cellInFolderEditorStartY)
{
    // Set layout for folder editor
    VcpPageMenuFolderEditorLayout folderEditorLayout;
    folderEditorLayout.folderEditorPosX = m_folderEditor->getPos().x;
    folderEditorLayout.folderEditorPosY = m_folderEditor->getPos().y;
    folderEditorLayout.folderEditorWidth = m_folderEditor->getSize().width;
    folderEditorLayout.folderEditorHeight = m_folderEditor->getSize().height;
    folderEditorLayout.folderEditorMainShiftY = VAPP_LAUNCHER_MM_FOLDER_EDITOR_MAIN_SHIFT_Y;
    folderEditorLayout.rowCountInFolderEditor = VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_ROW_COUNT;
    folderEditorLayout.columnCountInFolderEditor = VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_COLUMN_COUNT;
    folderEditorLayout.cellInFolderEditorStartX = VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_START_X;
    folderEditorLayout.cellInFolderEditorStartY = cellInFolderEditorStartY;
    folderEditorLayout.cellInFolderEditorOffsetX = VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_X;
    folderEditorLayout.cellInFolderEditorOffsetY = VAPP_LAUNCHER_MM_CELL_IN_FOLDER_EDITOR_OFFSET_Y;
    m_menuView->setFolderEditorLayout(folderEditorLayout);

    // Support uninstall icon, query app to see if can be deleted.
    mmi_app_package_name_struct *installedAppArray = NULL;
    U32 installedAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (installedAppCount)
    {
        VFX_SYS_ALLOC_MEM(installedAppArray, sizeof(mmi_app_package_name_struct) * installedAppCount );
        mmi_ret result;
        result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installedAppArray, installedAppCount);
        VFX_ASSERT(result != MMI_RET_ERR);
    }
    
    // Create cells
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
    {
        VcpPageMenuCell *cell = NULL;
        if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_MAIN)
        {
            cell = getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, m_menuView->getFolderCellPos().index), i);
        }
        else if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
        {
            cell = getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, m_menuView->getFolderCellPos().index), i);
        }
        if (cell != NULL)
        {
            VappLauncherMmCell *cellInFolderIcon = static_cast<VappLauncherMmCell *>(cell);
            mmi_app_package_name_struct cellAppName;
            cellInFolderIcon->getCellAppName(cellAppName);
            VappLauncherMmCell *cellInFolderEditor = ::vappLauncherMmCreateCell(cellAppName, this, cellInFolderIcon->getIsPreinstall());
            cellInFolderEditor->setIsUnhittable(VFX_TRUE);
            setMenuItemInFolderEditor(i, cellInFolderEditor);
            
            VfxBool isInstalled = VFX_FALSE;
            if (installedAppArray)
            {
                mmi_app_package_name_struct appName;
                cellInFolderEditor->getCellAppName(appName);
                isInstalled = vappLauncherMmIsInstalledApp(appName, installedAppArray, installedAppCount);
            }
            cellInFolderEditor->setIsInstalled(isInstalled);
        }
        else
        {
            break;
        }
    }
    
    if (installedAppArray)
    {
        VFX_SYS_FREE_MEM(installedAppArray);
    }      
}

void VappLauncherMmPageMenu::closeCellsInFolderEditor()
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
    {
        if (m_cellsInFolderEditor[i])
        {
            VFX_OBJ_CLOSE(m_cellsInFolderEditor[i]);
        }
        else
        {
            break;
        }
    }
}

void VappLauncherMmPageMenu::refreshCellsInFolderIcon()
{
    if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_MAIN)
    {
        // Close cells
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            if (m_cellsInFolderIcon[m_menuView->getFolderCellPos().index][i])
            {
                VFX_OBJ_CLOSE(m_cellsInFolderIcon[m_menuView->getFolderCellPos().index][i]);
            }
        }
        
        // Create cells
        createCellsInFolderIcon(VCP_PAGE_MENU_GROUP_MAIN);
    }
    else if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
    {
        // Close cells
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            if (m_groupCellsInFolderIcon[m_menuView->getFolderCellPos().index][i])
            {
                VFX_OBJ_CLOSE(m_groupCellsInFolderIcon[m_menuView->getFolderCellPos().index][i]);
            }
        }
        
        // Create cells
        createCellsInFolderIcon(VCP_PAGE_MENU_GROUP_BOTTOM_BAR);
    }
    else
    {
        VFX_ASSERT(0);
    }
}

void VappLauncherMmPageMenu::createCellsInFolderIcon(VfxS32 group)
{
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            VcpPageMenuCell *cell = getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, i));
            if (cell != NULL)
            {
                VappLauncherMmCell *cellInFolderEditor = static_cast<VappLauncherMmCell *>(cell);
                mmi_app_package_name_struct cellAppName;
                cellInFolderEditor->getCellAppName(cellAppName);
                VappLauncherMmCell *cellInFolderIcon = ::vappLauncherMmCreateCell(cellAppName,
                                                                                  this,
                                                                                  cellInFolderEditor->getIsPreinstall());
            cellInFolderIcon->setIsUnhittable(VFX_TRUE);
            cellInFolderIcon->setTextFrameHidden(VFX_TRUE);
            if (group == VCP_PAGE_MENU_GROUP_MAIN)
                setMenuItemInFolderIcon(m_menuView->getFolderCellPos().index, i, cellInFolderIcon);
            else
                setGroupMenuItemInFolderIcon(m_menuView->getFolderCellPos().index, i, cellInFolderIcon);
        }
        else
        {
            break;
        }
    }
}

VcpPageMenuCell *VappLauncherMmPageMenu::getHoldFrameInFolderIcon(VfxS32 index) const
{
    return m_holdFrameInFolderIcon[index];
}

void VappLauncherMmPageMenu::setHoldFrameInFolderIcon(VcpPageMenuCell *holdFrameInFolderIcon, VfxS32 index)
{
    m_holdFrameInFolderIcon[index] = holdFrameInFolderIcon;
}

VcpPageMenuCell *VappLauncherMmPageMenu::getDraggingFrameInFolderIcon(VfxS32 index) const
{
    return m_draggingFrameInFolderIcon[index];
}

void VappLauncherMmPageMenu::setDraggingFrameInFolderIcon(VcpPageMenuCell *draggingInFolderIcon, VfxS32 index)
{
    m_draggingFrameInFolderIcon[index] = draggingInFolderIcon;
}

void VappLauncherMmPageMenu::inFolderOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    if (isHitFolderEditor(touchX, touchY))
    {
        m_canDragToExitFolderMode = VFX_TRUE;
        
        // Use cell center to decide cell position
        VfxS32 cellCenterX = touchX + m_menuView->getOrganizeDragOffset().x + m_menuView->getDraggingFrame()->getSize().width / 2;
        VfxS32 cellCenterY = touchY + m_menuView->getOrganizeDragOffset().y + m_menuView->getDraggingFrame()->getSize().height / 2;
        inFolderEditorOrganizeMove(cellCenterX, cellCenterY);
    }
    else if (m_canDragToExitFolderMode == VFX_TRUE)
    {
        m_canDragToExitFolderMode = VFX_FALSE;
        
        // remove and close dragging cell from folder icon group if dragging cell is already put in folder icon group
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            VcpPageMenuCell *cell = NULL;
            if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_MAIN)
            {
                cell = getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, m_menuView->getFolderCellPos().index), i);
            }
            else if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
            {
                cell = getCell(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, m_menuView->getFolderCellPos().index), i);
            }
            if (cell == NULL)
            {
                break;
            }
            
            // use app package name to check if dragging is already put in folder icon group
            VappLauncherMmCell *draggingCell = static_cast<VappLauncherMmCell *>(m_menuView->getDraggingFrame());
            mmi_app_package_name_struct draggingCellAppName;
            draggingCell->getCellAppName(draggingCellAppName);
            
            VappLauncherMmCell *cellInFolderIcon = static_cast<VappLauncherMmCell *>(cell);
            mmi_app_package_name_struct cellInFolderIconAppName;
            cellInFolderIcon->getCellAppName(cellInFolderIconAppName);
            
            if (strncmp(cellInFolderIconAppName, draggingCellAppName, MMI_APP_NAME_MAX_LEN) == 0)
            {
                if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_MAIN)
                {
                    removeCellFrom(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_MAIN_FOLDER_ICON, m_menuView->getFolderCellPos().index), i);
                }
                else if (m_menuView->getFolderCellPos().group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
                {
                    removeCellFrom(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_BOTTOM_BAR_FOLDER_ICON, m_menuView->getFolderCellPos().index), i);
                }
                VFX_OBJ_CLOSE(cell);
    
                break;
            }
        }
        
        // remove dragging cell from folder editor group
        removeCellFrom(getOrganizeTo());
        
        exitFolderMode();
        
        // Use cell center to decide cell position
        VfxS32 cellCenterX = touchX + m_menuView->getOrganizeDragOffset().x + m_menuView->getDraggingFrame()->getSize().width / 2;
        VfxS32 cellCenterY = touchY + m_menuView->getOrganizeDragOffset().y + m_menuView->getDraggingFrame()->getSize().height / 2;
        
        // put the dragging cell to the new group
        VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(cellCenterX, cellCenterY), VFX_FALSE);
        if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_MAIN)
        {
            // put the dragging cell to the main page
            putCellTo(currentDirectPos, m_menuView->getDraggingFrame(), m_draggingFrameInFolderIcon, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);
        }
        else if (currentDirectPos.group == VCP_PAGE_MENU_GROUP_BOTTOM_BAR)
        {
            VfxBool isFull = VFX_TRUE;
            for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT; ++i)
            {
                if (m_groupCells[i] == NULL)
                {
                    isFull = VFX_FALSE;
                    break;
                }
            }
            
            if (!isFull)
            {
                if (currentDirectPos.index < VAPP_LAUNCHER_MM_ORGANIZE_CHANGABLE_BAR_ITEM_COUNT)
                {
                    // put the dragging cell to the bottom bar
                    putCellTo(currentDirectPos, m_menuView->getDraggingFrame(), m_draggingFrameInFolderIcon, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);
                }
            }
            else
            {
                // bottom bar is full, so put the dragging cell to the main page
                VfxS32 i;
                for (i = getCurrentPageIndex() * getMenuItemCountPerPage(); i < getMenuItemCountPerPage(); ++i)
                {
                    if (m_cells[i] == NULL)
                    {
                        break;
                    }
                }
                if (i == (getCurrentPageIndex() + 1) * getMenuItemCountPerPage())
                {
                    i -= 1;
                }
                currentDirectPos.index = i;
                currentDirectPos.group = VCP_PAGE_MENU_GROUP_MAIN;
                // put the dragging cell to the new page
                putCellTo(currentDirectPos, m_menuView->getDraggingFrame(), m_draggingFrameInFolderIcon, VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER);
            }
        }
        else
        {
            VFX_ASSERT(0);
        }
    }
    
    m_menuView->setDraggingFramePos(touchX, touchY);
}

void VappLauncherMmPageMenu::inFolderEditorOrganizeMove(VfxS32 touchX, VfxS32 touchY)
{
    const VcpPageMenuCellPos currentTo = cellHittest(VfxPoint(touchX, touchY), VFX_TRUE);
    const VcpPageMenuCellPos prevOrganizeTo = getOrganizeTo();
    
    if (currentTo.group == prevOrganizeTo.group)
    {
        if (currentTo.index != MAINMENU_HITTEST_NOT_FOUND)
        {
            if (prevOrganizeTo != currentTo)
            {
                setOrganizeTo(currentTo);
                
                if (getOrganizeTo().index > prevOrganizeTo.index)
                {
                    for (VfxS32 i = prevOrganizeTo.index; i < getOrganizeTo().index; ++i)
                    {
                        VcpPageMenuCellPos dest(prevOrganizeTo.group, i);
                        VcpPageMenuCellPos src(prevOrganizeTo.group, i+1);
                        setCell(dest, getCell(src) );
                    }
                    setCell(getOrganizeTo(), m_menuView->getDraggingFrame());
                }
                else
                {
                    for (VfxS32 i = prevOrganizeTo.index; i > getOrganizeTo().index; --i)
                    {
                        VcpPageMenuCellPos dest(prevOrganizeTo.group, i);
                        VcpPageMenuCellPos src(prevOrganizeTo.group, i-1);
                        setCell(dest, getCell(src) );
                    }
                    setCell(getOrganizeTo(), m_menuView->getDraggingFrame());
                }
            }
        }
    }
    else if (currentTo.group == VCP_PAGE_MENU_GROUP_FOLDER_EDITOR)
    {
        VfxBool isFull = VFX_TRUE;
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            if (m_cellsInFolderEditor[i] == NULL)
            {
                isFull = VFX_FALSE;
                break;
            }
        }
        
        if (!isFull)
        {
            const VcpPageMenuCellPos currentDirectPos = cellHittest(VfxPoint(touchX, touchY), VFX_FALSE);
            if (currentDirectPos.index < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER)
            {
                // reserve dragging cell space in main group
                m_invalidCellPos = getOrganizeTo();
                setCell(m_invalidCellPos, NULL);
        
                // put the dragging cell to the new page
                putCellTo(currentDirectPos, m_menuView->getDraggingFrame());
            }
        }
    }
    
    checkUpdate();
}

void VappLauncherMmPageMenu::putCellToMainFolderIcon(VcpPageMenuCellPos pos, VcpPageMenuCell *cell)
{
}

void VappLauncherMmPageMenu::putCellToBarFolderIcon(VcpPageMenuCellPos pos, VcpPageMenuCell *cell)
{
}

void VappLauncherMmPageMenu::putCellToFolderEditor(VcpPageMenuCellPos pos, VcpPageMenuCell *cell)
{
    if (pos.index == MAINMENU_HITTEST_NOT_FOUND)
    {
        // append to the end of folder editor
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++i)
        {
            if (m_cellsInFolderEditor[i] == NULL)
            {
                m_cellsInFolderEditor[i] = cell;
                setOrganizeTo(VcpPageMenuCellPos(VCP_PAGE_MENU_GROUP_FOLDER_EDITOR, i));
                break;
            }
        }
    }
    else
    {
        // around cells
        for (VfxS32 i = VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER - 1; i > pos.index; --i)
        {
            m_cellsInFolderEditor[i] = m_cellsInFolderEditor[i - 1];
        }
        setCell(pos, cell);
        setOrganizeTo(pos);
    }
}


#endif // __MMI_VUI_LAUNCHER_MM__

