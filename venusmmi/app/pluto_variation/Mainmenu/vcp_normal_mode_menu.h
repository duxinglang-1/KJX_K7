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
 *  vcp_normal_mode_menu.h
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

#ifndef __VCP_NORMAL_MODE_MENU_H__
#define __VCP_NORMAL_MODE_MENU_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_3D_MAINMENU__

 /*****************************************************************************
  * Include
  *****************************************************************************/
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vcp_page_menu_util.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_string.h"

 /*****************************************************************************
  * Define
  *****************************************************************************/

#if defined(__MMI_MAINLCD_240X320__)

#define VCP_NORMAL_MODE_MENU_MAX_APP 3*3*7

#elif defined(__MMI_MAINLCD_240X400__)

#define VCP_NORMAL_MODE_MENU_MAX_APP 4*3*7

#else // default and HVGA case

#define VCP_NORMAL_MODE_MENU_MAX_APP 4*4*10

#endif

class VfxTimer;

class VcpPageMenuCell;

class VcpPageMenuLayout;

class VcpPageMenuIndicator;

class VcpPageMenuView;

/*****************************************************************************
  * Class VappMmCell
  *****************************************************************************/
class VappMmCell : public VcpPageMenuCell
{
public:
    VappMmCell(VfxResId imageID, const VfxWString &title);
    virtual void onCellDisplay();

private:
    VfxBool m_firstDisplay;
    VfxResId m_imageID;
    VfxWString m_title;
};

/*****************************************************************************
  * Class VcpNormalModeMenu
  *****************************************************************************/

class VcpNormalModeMenu : public VfxControl
{
    VFX_DECLARE_CLASS(VcpNormalModeMenu);

// Constructor / Destructor
public:	
    // Default constructor.
    VcpNormalModeMenu();


// Properties
public:
    VfxS32 getCurrentPageIndex() const;
    void setCurrentPageIndex(VfxS32 pageIndex, VfxBool animated);
    VfxS32 getCurrentAppIndex() const;

    VfxS32 getPageCount() const;

    const VcpPageMenuLayout & getMenuLayout() const;
    void setMenuLayout(const VcpPageMenuLayout & layout);


// Method
public:
    void leaveOrganizationMode();

// Methods for builder
    VcpPageMenuCell * getMenuItem(VfxS32 index) const;
    void setMenuItem(VfxS32 index, VcpPageMenuCell * cell);

    void setCellIconSize(const VfxSize & size);

    void setPageCount(VfxS32 pageCount);
    VfxS32 getMenuItemCountPerPage() const;

// Events
public:
    VfxSignal1<VfxBool> m_organizationChanged;
    VfxSignal1<VfxS32> m_appClicked;
    VfxSignal1<VfxS32> m_pageChanged;

// Override
public:
    virtual void setBounds(const VfxRect &value);
protected:
    virtual void onInit();

    virtual void onUpdate();

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Implementation
private:

    // init data
    VfxS32                      m_pageCount;
    VfxS32                      m_stableCurrentPageIndex;

    // frame data
    VcpPageMenuView *         m_menuView;
    VcpPageMenuCell *         m_cells[VCP_NORMAL_MODE_MENU_MAX_APP];
    VcpPageMenuCell *         m_holdFrame;
    VcpPageMenuIndicator *    m_pageIndicator;

    // timer
    VfxTimer *                  m_longPressTimer;

    // menu state
    VfxS32                      m_hover;
    VfxBool                     m_startPen;
    VfxS32                      m_translateOrigX;

    // organize state
    VfxBool                     m_organizeMode;
    VfxS32                      m_organizeTo;
    VfxMsec                     m_lastAutoScrollTime;
    VfxBool                     m_leftExtended;
    VfxBool                     m_rightExtended;


    // private functions

    // property wrappers
    VfxBool getOrganizeMode() const;
    void setOrganizeMode(VfxBool organizeMode);
    VfxS32 getOrganizeTo() const;
    void setOrganizeTo(VfxS32 organizeTo);
    VfxS32 getHover() const;
    void setHover(VfxS32 hover);
    VcpPageMenuCell * getHoldFrame() const;
    void setHoldFrame(VcpPageMenuCell * holdFrame);

    // long press timer callback
    void onLongPressTimerTick(VfxTimer *source);

    void onPageIndicatorSelected(VfxS32 pageSelected);

    // helper functions
    VfxS32 cellHittest(VfxPoint clickPoint, VfxBool findLast) const;
    void scrollToPage(VfxS32 pageIndex, VfxS32 animTime);
    void updatePageIndicatorPos();

    // scroll handling
    VfxBool handlePenDown(const VfxPoint &touchDownPos);
    VfxBool handleScroll(const VfxPenEvent &event);
    void handleScrollEnd(VfxS32 diffX, VfxMsec elapse);
    void handleScrollMove(VfxS32 diffX, VfxS32 diffY);
    void handleScrollSwipe(VfxS32 diffX, VfxFloat speed);

    // organize handling
    VfxBool handleOrganize(VfxPenEventTypeEnum touchType, const VfxPoint &touchPos);
    void handleOrganizeStart();
    void handleOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void crossPageOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void switchOrganizePage(VfxS32 newPage, VfxS32 touchX, VfxS32 touchY);
    void inPageOrganizeMove(VfxS32 touchX, VfxS32 touchY);
    void handleOrganizePut();
    void handleOrganizeEnd();

    // organize helpers
    void compactPages();
    void putHoldFrame();
    VfxBool putHoldFrameAfterPage(VfxS32 page);
    VfxBool putHoldFrameBeforePage(VfxS32 page);

};


struct AppEntry
{
    VfxResId appIcon;
    VfxWString appTitle;
    VfxS32 entry;
};


/*****************************************************************************
  * Class VcpNormalModeMenuBuilder
  *****************************************************************************/

#define VCP_NORMAL_MODE_MENU_PAGE_BREAK 0xFFFFFFFF

class VcpNormalModeMenuBuilder : public VfxObject
{
public:
    VcpNormalModeMenuBuilder();

    void setAllAppData(AppEntry appEntry[], VfxS32 count);
    void setAppOrderData(VfxS32 appOrder[], VfxS32 count);

    void loadMenu(VcpNormalModeMenu * menu);
    void saveMenu(VcpNormalModeMenu * menu);

private:
    AppEntry             *  m_allAppData;
    VfxS32                  m_allAppCount;
    VfxS32               *  m_appOrderData;
    VfxS32                  m_appOrderCount;

    VcpPageMenuCell * createCell(VfxS32 index, VfxResId imageID, const VfxWString &title, VcpNormalModeMenu * menu);

    void initFrames(VcpNormalModeMenu * menu);
    void reorderFrames(VcpNormalModeMenu * menu);
    void checkCellState(VcpNormalModeMenu * menu);
    void initCell(VfxS32 index, VfxResId imageID, const VfxWString &title);
};


#endif // __MMI_VUI_3D_MAINMENU__

#endif // __VCP_NORMAL_MODE_MENU_H__
