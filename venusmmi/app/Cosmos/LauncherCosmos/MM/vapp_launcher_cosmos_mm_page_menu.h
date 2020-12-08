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
 *  vapp_launcher_cosmos_mm_page_menu.h
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


#ifndef __VAPP_LAUNCHER_COSMOS_MM_PAGE_MENU_H__
#define __VAPP_LAUNCHER_COSMOS_MM_PAGE_MENU_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_COSMOS__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_page_menu_util.h"


/*****************************************************************************
 * Static Constant
 *****************************************************************************/

#define VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP 4

#ifdef __LOW_COST_SUPPORT_COMMON__

#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_LAUNCHER_COSMOS_MM_MAX_APP 96
#else
#define VAPP_LAUNCHER_COSMOS_MM_MAX_APP 128
#endif

#else // __LOW_COST_SUPPORT_COMMON__

#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_LAUNCHER_COSMOS_MM_MAX_APP 120
#else
#define VAPP_LAUNCHER_COSMOS_MM_MAX_APP 160
#endif

#endif // __LOW_COST_SUPPORT_COMMON__


/*****************************************************************************
 * Class VappLauncherCosmosMmPageMenu
 *****************************************************************************/

class VappLauncherCosmosMmPageMenu : public VfxControl
{
    VFX_DECLARE_CLASS(VappLauncherCosmosMmPageMenu);

// Constructor / Destructor
public:
    // Default constructor.
    VappLauncherCosmosMmPageMenu();

// Method
public:
    VfxS32 getCurrentPageIndex() const;
    void setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated);

    const VcpPageMenuLayout & getMenuLayout() const;
    void setMenuLayout(const VcpPageMenuLayout & layout);

    void refreshMenu();
    void serializeMenu();

    void setIsUninstallingMode(VfxBool isUninstalling);
    void setIsEnterNCenter(VfxBool isEnterNCenter);
    
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    VcpPageMenuTransitionType getTransitionEffect() const;
    void setTransitionEffect(VcpPageMenuTransitionType transitionType);
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

    void leaveOrganizationMode(VfxBool isCheckUpdate = VFX_TRUE);
    void enterOrganizationMode();

    void forceDirty();

    VfxBool isHitCell(VfxPenEvent &event);

    VcpPageMenuCell * getMenuItem(VfxS32 index) const;
    void setMenuItem(VfxS32 index, VcpPageMenuCell * cell);
    VcpPageMenuCell * getGroupMenuItem(VfxS32 index) const;
    void setGroupMenuItem(VfxS32 index, VcpPageMenuCell * cell);
    void clearAllMenuItems();

    void setCellIconSize(const VfxSize & size);

    VfxS32 getPageCount() const;
    void setPageCount(VfxS32 pageCount, VfxBool isCheckUpdate = VFX_TRUE);
    VfxS32 getMaxPageCount() const;
    VfxS32 getMenuItemCountPerPage() const;
    VfxS32 getMenuItemCountPerGroup() const;
    
    void compactPages(VfxBool isCheckUpdate = VFX_TRUE);

    void preLoadAndCacheNeighborPageCell();

// Override
public:
    virtual void setBounds(const VfxRect &value);
    
protected:
    virtual void onInit();

    virtual void onUpdate();

    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Variable
private:
    // init data
    VfxS32                  m_pageCount;
    VfxS32                  m_stableCurrentPageIndex;

    // frame data
    VcpPageMenuView         *m_menuView;
    VcpPageMenuCell         *m_cells[VAPP_LAUNCHER_COSMOS_MM_MAX_APP];
    VcpPageMenuCell         *m_groupCells[VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP];
    VcpPageMenuCell         *m_holdFrame;
    VcpPageMenuIndicator    *m_pageIndicator;

    // timer
    VfxTimer                *m_longPressTimer;
    VfxTimer                *m_delayLoadCellTimer;
    VfxTimer                *m_delayMovingTimer;
    VfxTimer                *m_autoScrollPageTimer;

    // menu state
    VcpPageMenuCellPos      m_hover;
    VfxBool                 m_startPen;
    VfxBool                 m_canScroll;
    VfxS32                  m_translateOrigX;
    VfxS32                  m_updateCount;

    // organize state
    VfxBool                     m_organizeMode;
    VcpPageMenuCellPos          m_organizeTo;
    VcpPageMenuCellPos          m_delayMovingTo;
    VcpPageMenuCellHitAreaEnum  m_delayMovingToHitArea;
    VfxPoint                    m_delayMovingTouchPos;
    VfxPoint                    m_lastAutoScrollTouchPos;
    VfxMsec                     m_lastAutoScrollTime;
    VfxBool                     m_leftExtended;
    VfxBool                     m_rightExtended;

// Implementation
private:
    // property wrappers
    VfxBool getOrganizeMode() const;
    void setOrganizeMode(VfxBool organizeMode);
    VcpPageMenuCellPos getOrganizeTo() const;
    void setOrganizeTo(VcpPageMenuCellPos organizeTo);
    VcpPageMenuCellPos getHover() const;
    void setHover(VcpPageMenuCellPos hover);
    VcpPageMenuCell *getHoldFrame() const;
    void setHoldFrame(VcpPageMenuCell *holdFrame);

    // long press timer callback
    void onLongPressTimerTick(VfxTimer *source);
    void onDelayLoadCellTimerTick(VfxTimer *source);
    void onDelayMovingTimerTick(VfxTimer *source);
    void onAutoScrollPageTimerTick(VfxTimer *source);

    void onPageIndicatorSelected(VfxS32 pageSelected);
    void onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop);

    // helper functions
    VcpPageMenuCellPos cellHittest(VfxPoint clickPoint, VfxBool findLast) const;
    void scrollToPage(VfxS32 pageIndex, VfxS32 animTime, VfxBool isCheckUpdate = VFX_TRUE);
    void updatePageIndicatorPos();
    VcpPageMenuCell *getCell(VcpPageMenuCellPos pos) const;
    void setCell(VcpPageMenuCellPos pos, VcpPageMenuCell * cell);
    void updateCellsCacheMode();

    // scroll handling
    VfxBool handlePenDown(const VfxPoint &touchDownPos);
    VfxBool handleScroll(const VfxPenEvent &event);
    void handleScrollEnd(VfxS32 diffX, VfxMsec elapse);
    void handleScrollMove(VfxS32 diffX, VfxS32 diffY);
    void handleScrollSwipe(VfxS32 diffX, VfxFloat speed);
    VfxS32 calculateSwipeTime(VfxS32 targetPageIndex, VfxFloat speed);

    // organize handling
    VfxBool handleOrganize(VfxPenEventTypeEnum touchType, const VfxPoint &touchPos);
    void handleOrganizeStart();
    void handleOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void crossPageOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void switchOrganizePage(VfxS32 newPage, VfxS32 touchX, VfxS32 touchY);
    void inPageOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void handleOrganizePut(VfxBool isCheckUpdate = VFX_TRUE);
    void handleOrganizeEnd(VfxBool isCheckUpdate = VFX_TRUE);

    // organize helpers
    void putHoldFrame();
    VfxBool putHoldFrameAfterPage(VfxS32 page);
    VfxBool putHoldFrameBeforePage(VfxS32 page);
    void removeCellFrom(VcpPageMenuCellPos pos);
    void putCellTo(VcpPageMenuCellPos pos, VcpPageMenuCell *cell);
    void putCellToMain(VcpPageMenuCellPos pos, VcpPageMenuCell *cell);
    void putCellToBar(VcpPageMenuCellPos pos, VcpPageMenuCell *cell);

// Signal
public:
    VfxSignal1<VfxBool>             m_organizationChanged;
    VfxSignal1<VcpPageMenuCell *>   m_appClicked;
    VfxSignal1<VfxS32>              m_pageChanged;
};


#endif // __MMI_VUI_LAUNCHER_COSMOS__


#endif // __VAPP_LAUNCHER_COSMOS_MM_PAGE_MENU_H__

