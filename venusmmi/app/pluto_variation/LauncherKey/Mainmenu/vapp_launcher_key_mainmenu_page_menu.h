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
 *  vapp_kmm_page_menu.h
 *
 * Project:
 * --------
 *  Key Launcher
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef __VAPP_LAUNCHER_KEY_MAINMENU_PAGE_MENU_H__
#define __VAPP_LAUNCHER_KEY_MAINMENU_PAGE_MENU_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_KEY__

#include "vcp_page_menu_util.h"

 /*****************************************************************************
  * Include
  *****************************************************************************/

 /*****************************************************************************
  * Define
  *****************************************************************************/
/*******
 *
 * VAPP_LAUNCHER_KEY_MM_MAX_CELL = 
 * VAPP_KEY_MAINMENU_SAVED_DATA_COUNT - VAPP_KEY_MAINMENU_SAVED_DATA_COUNT/(row * clolumn)
 *
 ********/

 
#if defined(__MMI_MAINLCD_240X320__)

#define VAPP_LAUNCHER_KEY_MM_MAX_CELL 96

#elif defined(__MMI_MAINLCD_240X400__)

#define VAPP_LAUNCHER_KEY_MM_MAX_CELL 100

#elif defined(__MMI_MAINLCD_320X240__)
#define VAPP_LAUNCHER_KEY_MM_MAX_CELL 90

#else // default HVGA 320X480

#define VAPP_LAUNCHER_KEY_MM_MAX_CELL 96

#endif

//#define DRAWER_ICON_BACKGROUND
#define DRAWER_SHADOW_EDIT_MODE

/*****************************************************************************
  * Class VappDrawerPageMenu
  *****************************************************************************/

class VappKeyMainmenuPageMenu : public VfxControl
{
    VFX_DECLARE_CLASS(VappKeyMainmenuPageMenu);

// Constructor / Destructor
public:
    // Default constructor.
    VappKeyMainmenuPageMenu();

//Enum
public:
    enum{
        ENTRY_ANIM_DURATION = 200,
		ENTRY_HIGHLIGHT_START = 200


    };
// Properties
public:
    VfxS32 getCurrentPageIndex() const;
    void setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated);

    VfxS32 getPageCount() const;

    const VcpPageMenuLayout & getMenuLayout() const;
    void setMenuLayout(const VcpPageMenuLayout & layout);
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
    void setTransitionEffect(VcpPageMenuTransitionType transitionType);
#endif


// Method
public:
    void leaveOrganizationMode(VfxBool isCheckUpdate = VFX_TRUE);

    void forceDirty();

    void showMenuItems(VfxBool isAnim);
    void showEntryAnim();
    void setEnableMenuAnim(VfxBool enable);

    void cancelOrganization();
    void entryOrganization();
// Methods for builder
    VcpPageMenuCell * getMenuItem(VfxS32 index) const;
    void setMenuItem(VfxS32 index, VcpPageMenuCell * cell);

    void clearAllMenuItems();
    void setCellIconSize(const VfxSize & size);

    void setPageCount(VfxS32 pageCount, VfxBool isCheckUpdate = VFX_TRUE);

    VfxS32 getMaxPageCount() const;
    VfxS32 getMenuItemCountPerPage() const;
    VfxS32 getMenuItemCountPerGroup() const;

    void setHighlightIndex(VfxS32 index, VfxBool isUpdate);
    VfxS32 getHighlightIndex();
    VfxBool changeHighlightIndex(VfxS32 newIndex);
	VfxFrame *getContainer(void)
	{
		return m_container;
	}
    void registerCellEvent();
// Events
public:
    VfxSignal1<VfxBool> m_organizationChanged;
    VfxSignal1<VcpPageMenuCell *> m_appClicked;
    VfxSignal1<VfxS32> m_pageChanged;
    VfxSignal1<VcpPageMenuCell *> m_highlightChanged;
	VfxSignal1<VfxBool> m_suspendWallpaper;

// Override
public:
    virtual void setBounds(const VfxRect &value);
    virtual void setHidden(VfxBool value);
protected:
    virtual void onInit();

    virtual void onUpdate();

    virtual VfxBool onPenInput(VfxPenEvent &event);
    
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Implementation
private:

    // init data
    VfxS32                      m_pageCount;
	VfxS32						m_backupPageCount;
    VfxS32                      m_stableCurrentPageIndex;

    // frame data
    VcpPageMenuView *         m_menuView;
    VcpPageMenuCell *         m_cells[VAPP_LAUNCHER_KEY_MM_MAX_CELL];
    VcpPageMenuCell *         m_backupCells[VAPP_LAUNCHER_KEY_MM_MAX_CELL];
    VcpPageMenuCell *         m_holdFrame;
    VcpPageMenuIndicator *    m_pageIndicator;

    // timer
    VfxTimer *                  m_delayPenDownTimer;
    VfxTimer *                  m_longPressTimer;
    VfxTimer *                  m_delayMovingTimer;
    VfxTimer *                  m_delayLoadCellTimer;
    VfxTimer *                  m_cancelOrganizationTimer;
	VfxTimer *					m_resumeWallpaperTimer;
    VfxTimer *                  m_resumeMenuEffectTimer;

    // menu state
    VcpPageMenuCellPos          m_hover;
    VfxBool                     m_startPen;
    VfxBool                     m_canScroll;
    VfxS32                      m_translateOrigX;
    VfxBool                     m_showMenuItems;
    VfxBool                     m_enableMenuAnim;
    VfxS32                      m_updateCount;
    VfxS32                      m_highlightIndex;
    
    // organize state
    VfxBool                     m_organizeMode;
    VcpPageMenuCellPos          m_organizeTo;
    VcpPageMenuCellPos          m_delayPenDownCellPos;
    VcpPageMenuCellPos          m_delayMovingTo;
    VfxPoint                    m_delayMovingTouchPos;
    VfxMsec                     m_lastAutoScrollTime;
    VfxBool                     m_leftExtended;
    VfxBool                     m_rightExtended;

	// show state
	VfxBool						m_isHidden;

	// anim state
	VfxBool						m_isAmiation;
    // supspend wallpaper count
    VfxS32  m_suspendWallpaperCount;

	VfxFrame *m_container;


    // private functions

    // property wrappers
    VfxBool getOrganizeMode() const;
    void setOrganizeMode(VfxBool organizeMode);
    VcpPageMenuCellPos getOrganizeTo() const;
    void setOrganizeTo(VcpPageMenuCellPos organizeTo);
    VcpPageMenuCellPos getHover() const;
    void setHover(VcpPageMenuCellPos hover);
    VcpPageMenuCell * getHoldFrame() const;
    void setHoldFrame(VcpPageMenuCell * holdFrame);

    // long press timer callback
    void onDelayPenDownTimerTick(VfxTimer *source);
    void onLongPressTimerTick(VfxTimer *source);
    void onDelayMovingTimerTick(VfxTimer *source);
    void onDelayLoadCellTimerTick(VfxTimer *source);
    void onCancelTimerTick(VfxTimer *source);
#ifdef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
    void onResumeMenuEffectTimerTick(VfxTimer *source);

#endif
    void onRegisterBadgeTimer(VfxTimer *source);
	void onEntryAnimTimer(VfxTimer *source);
	void onResumeWallpaperTimerTick(VfxTimer *source);
	void onHighlightTimer(VfxTimer *source);

    void onPageIndicatorSelected(VfxS32 pageSelected);
    void onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop);

    // helper functions
    VcpPageMenuCellPos cellHittest(VfxPoint clickPoint, VfxBool findLast) const;
    void scrollToPage(VfxS32 pageIndex, VfxS32 animTime, VfxBool isCheckUpdate = VFX_TRUE);
    void updatePageIndicatorPos();
    VcpPageMenuCell * getCell(VcpPageMenuCellPos pos) const;
    void setCell(VcpPageMenuCellPos pos, VcpPageMenuCell * cell);

    // scroll handling
    VfxBool handlePenDown(const VfxPoint &touchDownPos);
    VfxBool handleScroll(const VfxPenEvent &event);
    void handleScrollEnd(VfxS32 diffX, VfxMsec elapse);
    void handleScrollMove(VfxS32 diffX, VfxS32 diffY);
    void handleScrollSwipe(VfxS32 diffX, VfxFloat speed);

    // organize handling
    VfxBool handleOrganize(VfxPenEventTypeEnum touchType, const VfxPoint &touchPos);
    void handleOrganizeStart(VfxBool isByPen);
    void handleOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void crossPageOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void switchOrganizePage(VfxS32 newPage, VfxS32 touchX, VfxS32 touchY);
    void inPageOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void handleOrganizePut(VfxBool isCheckUpdate = VFX_TRUE);
    void handleOrganizeEnd(VfxBool isCheckUpdate = VFX_TRUE);

    // organize helpers
    void compactPages(VfxBool isCheckUpdate = VFX_TRUE);
    void putHoldFrame();
    VfxBool putHoldFrameAfterPage(VfxS32 page);
    VfxBool putHoldFrameBeforePage(VfxS32 page);
    void removeCellFrom(VcpPageMenuCellPos pos);
    void putCellTo(VcpPageMenuCellPos pos, VcpPageMenuCell * cell);
    void putCellToMain(VcpPageMenuCellPos pos, VcpPageMenuCell * cell);

    // highlight 
    VfxS32 findNextHighlightIndex(VfxKeyEvent &event);
    VfxS32 getPageIndex(VfxS32 index);
	// reorder index
    void reorderIndex(VfxKeyEvent &event);
	void reorderByLeftArrowKey();
	void reorderByRightArrowKey();
	void reorderByUpArrowKey(VfxKeyEvent &event);
	void reorderByDownArrowKey(VfxKeyEvent &event);
    void swapCell(VfxS32 index1, VfxS32 index2);
};

#endif // __MMI_VUI_LAUNCHER_KEY__

#endif // __VAPP_LAUNCHER_KEY_MAINMENU_PAGE_MENU_H__

