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
 *  vapp_cal_main_view.h
 *
 * Project:
 * --------
 *  COSMOS
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CAL_MAIN_VIEW_H__
#define __VAPP_CAL_MAIN_VIEW_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "MMIDatatype.h"

#include "vfx_datatype.h"
#include "vfx_page.h"
#include "vfx_weak_ptr.h"
#include "vfx_signal.h"
#include "vfx_font_desc.h"
#include "vfx_control.h"
#include "vfx_date_time.h"

#include "vcp_base_menu.h"
#include "vcp_menu_popup.h"
#include "vcp_confirm_popup.h"
#include "vcp_list_menu.h"
#include "vcp_panel_bar.h"

#include "vapp_cal_prot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
// calendar paint position
#define VAPP_CAL_MONTHLY_COLUMN 7
#define VAPP_CAL_MONTHLY_ROW 6
#define VAPP_CAL_WEEKLY_TIME_INTERVAL 1
#define VAPP_CAL_WEEKLY_COLUMN 8
#define VAPP_CAL_WEEKLY_ROW (VAPP_CAL_HOURS_ONE_DAY / VAPP_CAL_WEEKLY_TIME_INTERVAL)


#if defined(__MMI_MAINLCD_320X480__)

    #define VAPP_CAL_TOP_BAR_HEIGHT                 51
    #define VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT         0
    #define VAPP_CAL_TOP_BAR_BUTTON_MARGIN          6
    #define VAPP_CAL_TOP_ARROW_OFFSIZE              -1, -1
    #ifndef __LOW_COST_SUPPORT_COMMON__
    #define VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT        26
	#else	
    #define VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT		33
	#endif
    #define VAPP_CAL_MONTHLY_WEEK_BAR_SHARDOW_H     2
    #define VAPP_CAL_MONTHLY_EDIVIDER_HEIGHT        4
    #define VAPP_CAL_MONTHLY_CELL_WIDTH             46      // 46*7 = 322
    #ifndef __LOW_COST_SUPPORT_COMMON__
    #define VAPP_CAL_MONTHLY_CELL_HEIGHT            36
	#else
    #define VAPP_CAL_MONTHLY_CELL_HEIGHT			54
	#endif
    #define VAPP_CAL_MONTHLY_MENU_POS_X             -1   // 320 - 46*7 = -2
    #define VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_WIDTH    (VAPP_CAL_MONTHLY_CELL_WIDTH + 2)
    #define VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT   (VAPP_CAL_MONTHLY_CELL_HEIGHT + 2)
    #define VAPP_CAL_WEEKLY_F_CELL_WIDTH            46
    #define VAPP_CAL_WEEKLY_CELL_WIDTH              39
    #define VAPP_CAL_WEEKLY_CELL_HEIGHT             31
    #define VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT         42
    #define VAPP_CAL_WEEKLY_WEEK_OFFSIZE_Y          2
    #define VAPP_CAL_DAILY_WEEKDAY_L_MARGIN         20
    #define VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT         36
    #define VAPP_CAL_DAILY_WEEKDAY_WIDTH            65
    #define VAPP_CAL_BOTTOM_BAR_HEIGHT              VCP_TOOL_BAR_HEIGHT
    #define VAPP_CAL_BOTTOM_BUTTON_WIDTH            VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH
    #define VAPP_CAL_BOTTOM_SEGMENT_HEIGHT          38
    #define VAPP_CAL_BOOTOM_SEGMENT_MARGIN          10
    #define VAPP_CAL_FINGER_TOUCH_SIZE              40
    #define VAPP_CAL_WEEKLY_MENU_EDGE               5
    #define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY_LEFT 2
	#define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY 0
	  #define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_HEIGHT_MODIFY 0

    #define VAPP_CAL_TITLE_SOLOAR_FONT      VFX_FONT_DESC_VF_SIZE(20)
    #define VAPP_CAL_TITLE_LUNAR_FONT       VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_MONTH_WEEKDAY_FONT     VFX_FONT_DESC_VF_SIZE(16)
    #define VAPP_CAL_MONTH_CELL_FONT        VFX_FONT_DESC_VF_SIZE(18)
    #define VAPP_CAL_WEEK_WEEKDAY_FONT      VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_WEEK_WEEKDATE_FONT     VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_WEEK_CELL_TIME_FONT    VFX_FONT_DESC_VF_SIZE(18)
    #define VAPP_CAL_DAY_WEEKDAY_FONT       VFX_FONT_DESC_VF_SIZE(18)
    #define VAPP_CAL_DAY_LUNAR_FONT         VFX_FONT_DESC_VF_SIZE(16)
    #define VAPP_CAL_SEGMENT_FONT           VFX_FONT_DESC_VF_SIZE(14)
    
#elif defined(__MMI_MAINLCD_480X800__)

    #define VAPP_CAL_TOP_BAR_HEIGHT                 98
    #define VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT         5
    #define VAPP_CAL_TOP_BAR_BUTTON_MARGIN          12
    #define VAPP_CAL_TOP_ARROW_OFFSIZE              -1, -3
    #define VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT        47
    #define VAPP_CAL_MONTHLY_WEEK_BAR_SHARDOW_H     4
    #define VAPP_CAL_MONTHLY_EDIVIDER_HEIGHT        8
    #define VAPP_CAL_MONTHLY_CELL_WIDTH             68      // 68*7 + 4 = 476 + 4 = 480
    #define VAPP_CAL_MONTHLY_CELL_HEIGHT            54
    #define VAPP_CAL_MONTHLY_MENU_POS_X             2   // (480-68*7)/2 = 4/2 = 2
    #define VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_WIDTH    (VAPP_CAL_MONTHLY_CELL_WIDTH + 2)
    #define VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT   (VAPP_CAL_MONTHLY_CELL_HEIGHT + 2)
    #define VAPP_CAL_WEEKLY_F_CELL_WIDTH            73
    #define VAPP_CAL_WEEKLY_CELL_WIDTH              58
    #define VAPP_CAL_WEEKLY_CELL_HEIGHT             52
    #define VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT         60
    #define VAPP_CAL_WEEKLY_WEEK_OFFSIZE_Y          (VAPP_CAL_WEEKLY_CELL_HEIGHT * 10 + 5)
    #define VAPP_CAL_DAILY_WEEKDAY_L_MARGIN         20
    #define VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT         54
    #define VAPP_CAL_DAILY_WEEKDAY_WIDTH            100
    #define VAPP_CAL_BOTTOM_BAR_HEIGHT              VCP_TOOL_BAR_HEIGHT
    #define VAPP_CAL_BOTTOM_BUTTON_WIDTH            VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH
    #define VAPP_CAL_BOTTOM_SEGMENT_HEIGHT          60
    #define VAPP_CAL_BOOTOM_SEGMENT_MARGIN          12
    #define VAPP_CAL_FINGER_TOUCH_SIZE              60
    #define VAPP_CAL_WEEKLY_MENU_EDGE               5
    #define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY_LEFT 0
    #define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY -2
    #define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_HEIGHT_MODIFY 0
    
    #define VAPP_CAL_TITLE_SOLOAR_FONT      VFX_FONT_DESC_VF_SIZE(35)
    #define VAPP_CAL_TITLE_LUNAR_FONT       VFX_FONT_DESC_VF_SIZE(24)
    #define VAPP_CAL_MONTH_WEEKDAY_FONT     VFX_FONT_DESC_VF_SIZE(23)
    #define VAPP_CAL_MONTH_CELL_FONT        VFX_FONT_DESC_VF_SIZE(26)
    #define VAPP_CAL_WEEK_WEEKDAY_FONT      VFX_FONT_DESC_VF_SIZE(20)
    #define VAPP_CAL_WEEK_WEEKDATE_FONT     VFX_FONT_DESC_VF_SIZE(20)
    #define VAPP_CAL_WEEK_CELL_TIME_FONT    VFX_FONT_DESC_VF_SIZE(26)
    #define VAPP_CAL_DAY_WEEKDAY_FONT       VFX_FONT_DESC_VF_SIZE(28)
    #define VAPP_CAL_DAY_LUNAR_FONT         VFX_FONT_DESC_VF_SIZE(24)
    #define VAPP_CAL_SEGMENT_FONT           VFX_FONT_DESC_VF_SIZE(22)

#elif (defined(__MMI_MAINLCD_240X320__) || defined  (__MMI_MAINLCD_240X400__))

    #define VAPP_CAL_TOP_BAR_HEIGHT                 41
    #define VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT         0
    #define VAPP_CAL_TOP_BAR_BUTTON_MARGIN          6
    #define VAPP_CAL_TOP_ARROW_OFFSIZE              -1, -1
    #define VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT        31
    #define VAPP_CAL_MONTHLY_WEEK_BAR_SHARDOW_H     1
    #define VAPP_CAL_MONTHLY_EDIVIDER_HEIGHT        4
    #define VAPP_CAL_MONTHLY_CELL_WIDTH             34      // 34*7 = 238
    #define VAPP_CAL_MONTHLY_CELL_HEIGHT            30
    #define VAPP_CAL_MONTHLY_MENU_POS_X             1       // 240 - 34*7 = 1
    #define VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_WIDTH    (VAPP_CAL_MONTHLY_CELL_WIDTH + 2)
    #define VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT   (VAPP_CAL_MONTHLY_CELL_HEIGHT + 2)
    #define VAPP_CAL_WEEKLY_F_CELL_WIDTH            36
    #define VAPP_CAL_WEEKLY_CELL_WIDTH              29
    #define VAPP_CAL_WEEKLY_CELL_HEIGHT             30
    #define VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT         33
    #define VAPP_CAL_WEEKLY_WEEK_OFFSIZE_Y          260
    #define VAPP_CAL_DAILY_WEEKDAY_L_MARGIN         8
    #define VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT         26
    #define VAPP_CAL_DAILY_WEEKDAY_WIDTH            50
    #define VAPP_CAL_BOTTOM_BAR_HEIGHT              VCP_TOOL_BAR_HEIGHT
    #define VAPP_CAL_BOTTOM_BUTTON_WIDTH            VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH
    #define VAPP_CAL_BOTTOM_SEGMENT_HEIGHT          30
    #define VAPP_CAL_BOOTOM_SEGMENT_MARGIN          7
    #define VAPP_CAL_FINGER_TOUCH_SIZE              30
    #define VAPP_CAL_WEEKLY_MENU_EDGE               3
    #define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY_LEFT 0
    #define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY -2
    #define VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_HEIGHT_MODIFY -2

    #define VAPP_CAL_TITLE_SOLOAR_FONT      VFX_FONT_DESC_VF_SIZE(16)
    #define VAPP_CAL_TITLE_LUNAR_FONT       VFX_FONT_DESC_VF_SIZE(12)
    #define VAPP_CAL_MONTH_WEEKDAY_FONT     VFX_FONT_DESC_VF_SIZE(13)
    #define VAPP_CAL_MONTH_CELL_FONT        VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_WEEK_WEEKDAY_FONT      VFX_FONT_DESC_VF_SIZE(10)
    #define VAPP_CAL_WEEK_WEEKDATE_FONT     VFX_FONT_DESC_VF_SIZE(13)
    #define VAPP_CAL_WEEK_CELL_TIME_FONT    VFX_FONT_DESC_VF_SIZE(13)
    #define VAPP_CAL_DAY_WEEKDAY_FONT       VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_DAY_LUNAR_FONT         VFX_FONT_DESC_VF_SIZE(11)
    #define VAPP_CAL_SEGMENT_FONT           VFX_FONT_DESC_VF_SIZE(13)

#else // temp value

    #define VAPP_CAL_TOP_BAR_HEIGHT                 51
    #define VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT         0
    #define VAPP_CAL_TOP_BAR_BUTTON_MARGIN          6
    #define VAPP_CAL_TOP_ARROW_OFFSIZE              -1, -1
    #define VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT        26
    #define VAPP_CAL_MONTHLY_WEEK_BAR_SHARDOW_H     0
    #define VAPP_CAL_MONTHLY_EDIVIDER_HEIGHT        4
    #define VAPP_CAL_MONTHLY_CELL_WIDTH             46      // 46*7 = 322
    #define VAPP_CAL_MONTHLY_CELL_HEIGHT            36
    #define VAPP_CAL_MONTHLY_MENU_POS_X             -1   // 320 - 46*7 = -2
    #define VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_WIDTH    (VAPP_CAL_MONTHLY_CELL_WIDTH + 2)
    #define VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT   (VAPP_CAL_MONTHLY_CELL_HEIGHT + 2)
    #define VAPP_CAL_WEEKLY_F_CELL_WIDTH            46
    #define VAPP_CAL_WEEKLY_CELL_WIDTH              39
    #define VAPP_CAL_WEEKLY_CELL_HEIGHT             31
    #define VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT         42   
    #define VAPP_CAL_WEEKLY_WEEK_OFFSIZE_Y          2
    #define VAPP_CAL_DAILY_WEEKDAY_L_MARGIN         20
    #define VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT         36
    #define VAPP_CAL_DAILY_WEEKDAY_WIDTH            65
    #define VAPP_CAL_BOTTOM_BAR_HEIGHT              50
    #define VAPP_CAL_BOTTOM_BUTTON_WIDTH            VCP_TOOL_BAR_SEGMENT_BUTTON_PORTRAIT_WIDTH
    #define VAPP_CAL_BOTTOM_SEGMENT_HEIGHT          38
    #define VAPP_CAL_BOOTOM_SEGMENT_MARGIN          10
    #define VAPP_CAL_FINGER_TOUCH_SIZE              40
    #define VAPP_CAL_WEEKLY_MENU_EDGE               3

    #define VAPP_CAL_TITLE_SOLOAR_FONT      VFX_FONT_DESC_VF_SIZE(20)
    #define VAPP_CAL_TITLE_LUNAR_FONT       VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_MONTH_WEEKDAY_FONT     VFX_FONT_DESC_VF_SIZE(16)
    #define VAPP_CAL_MONTH_CELL_FONT        VFX_FONT_DESC_VF_SIZE(18)
    #define VAPP_CAL_WEEK_WEEKDAY_FONT      VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_WEEK_WEEKDATE_FONT     VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_WEEK_CELL_TIME_FONT    VFX_FONT_DESC_VF_SIZE(18)
    #define VAPP_CAL_DAY_WEEKDAY_FONT       VFX_FONT_DESC_VF_SIZE(18)
    #define VAPP_CAL_DAY_LUNAR_FONT         VFX_FONT_DESC_VF_SIZE(16)
    #define VAPP_CAL_SEGMENT_FONT           VFX_FONT_DESC_VF_SIZE(14)   
    
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VcpImageButton;
class VfxTextFrame;
class VfxImageFrame;
class VfxPointTimeline;
class VfxFrame;
class VfxBaseTimeline;
class VfxDateTime;
class VfxWString;
class VfxPenEvent;

class VappCalBaseMenu;
class VappCalBaseLayout;
class VappCalWeeklyCell;
class VappCalMonthlyCell;
class VappCalDailyList;
class VappCalViwerSwitchBar;
class VappCalGroupListPage;
class VappCalEditPage;
class VappCalListMgr;

/***************************************************************************** 
 * Class VappCalMainViewPage
 *****************************************************************************/
class VappCalMainViewPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappCalMainViewPage);

public:
    enum VappCalViewTypeEnum
    {
        VAPP_CAL_MONTHLY_VIEW,
        VAPP_CAL_WEEKLY_VIEW,
        VAPP_CAL_DAILY_VIEW,
        VAPP_CAL_VIEW_TOTAL
    };
    enum VappCalButtonEnum
    {
        VAPP_CAL_PRE_BUTTON,
        VAPP_CAL_NEXT_BUTTON,
        VAPP_CAL_TITLE_BUTTON
    };

public:
    VappCalMainViewPage();
    VappCalMainViewPage(const VfxDateTime &dateTime);

    void updateChanged(void);
    void creatpage(); 

    #ifndef __LOW_COST_SUPPORT_COMMON__
    void creatEventBox();
    #endif

    void setDataChangeState(VfxBool isMultiDelete);

    VfxBool getDataChangeState();



// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

// Implement
private:        
      
    void onTopPanelClick(VfxObject* sender, VfxId id);
    void onBottomPanelClick(VfxObject* sender, VfxId id);
    void onMonthlyMenuClick(VfxObject* sender, VfxS32 posIdx);
    void onWeeklyMenuClick(VfxObject* sender, VfxS32 posIdx);
    void onDailyMenuClick(VcpListMenu* sender, VfxId menuId);
    void onTimeLineStart(VfxBaseTimeline *timeline);
    void onTimeLineStop(VfxBaseTimeline *timeline, VfxBool is_stop);
    void onJumpToDateClicked(VfxObject* sender, VfxId id);
    void onDailyMenuLongTap(VcpListMenu *sender, VfxId id);
    void onOptionListClicked(VcpMenuPopup* sender, VcpMenuPopupEventEnum evtEnum, VcpMenuPopupItem* item);
    void onLongPressDelConfirm(VfxObject* sender, VfxId id);
    void onTimeChanged(VfxU32 flag);
    
    void enterNewViewMode();
    void enterWeekly();
    void enterMonthly();
    void enterDaily();
    void shiftToNextMenu(VfxBool is_next);
    void jumpToDate();
    VfxBool computeNextDateTime(VfxBool is_next);
    void updateTitle();
    void updateArrowState();
    void updateTitleLunarStr();
    void updateHighlightBox(VfxId posIdx);
    void createMenu(VfxFrame *parent);
#ifndef __LOW_COST_SUPPORT_COMMON__
    void updateEvtList(void);
#endif
    void checkImageButton(void);

    static mmi_ret updateEvtInfo(mmi_event_struct *param);
    static mmi_ret onEventReady(mmi_event_struct *param);


public:
    VfxWeakPtr<VcpMenuPopup> m_opListWeakPtr;
    VfxWeakPtr<VcpConfirmPopup> m_confirmPopupWeakPtr;

    #ifndef __LOW_COST_SUPPORT_COMMON__
    VfxWeakPtr<VappCalDailyList> m_evtInfoBoxWeakPtr;
    #endif
    
private:
    VfxFrame *m_contentFrame;       // a parent frame for three viewer mode
    VfxFrame *m_menuFrame;          // a parent frame for three menu view
    VfxFrame *m_menuFrame2;         // temp frame will enter for monthly view swiching

    VappCalBaseMenu *m_viewMenu;    // monthly/weekly viewer base menu pointer
    VappCalDailyList *m_dailyMenu;  // daily viewer list menu pointer
        
    VfxDateTime m_highlightDT;      // higlighted date and time
    
    VcpImageButton *m_topTxBg;      // jump to date image button on monthly view
    VfxTextFrame *m_titleSolar;     // solar text frame on monthly viewer
    VfxTextFrame *m_titleLunar;     // lunar text frame on monthly viewer
    
    VfxTextFrame *m_dailyWeek;      // day of week text frame on daily viewer
    VfxTextFrame *m_dailyLunar;     // lunar text frame on daily viewer
    VfxTextFrame *m_weeklydate[VAPP_CAL_MAX_DAYS_PER_WEEK]; // week of day for weekly view
    
    VfxImageFrame *m_hightlightBox; // higlight frame
    
    VfxPointTimeline *m_timeLine;
    VfxPointTimeline *m_timeLine2;
    
    VappCalViewTypeEnum m_viewType; // current view mode
    VfxU16 m_typeSelected;          // selected type on switch bar 
    VfxU16 m_selIdx;
    
    #ifndef __LOW_COST_SUPPORT_COMMON__
    VappCalDailyList *m_evtInfoBox; // the event info menu on monthly view
    #endif
    VfxS32 m_contentH; 

    VcpImageButton *m_preButton;
    VcpImageButton *m_nextButton;
    VfxU32 m_nActiveTimeline;
    VfxS32 m_jobId; 
    VfxU32 m_count;
    srv_tdl_event_id_struct *m_eventbuffer ;
    VfxBool m_multiDelete;


};


/***************************************************************************** 
 * Class VappCalBaseMenu
 *****************************************************************************/
class VappCalBaseMenu : public VcpBaseMenu
{
    VFX_DECLARE_CLASS(VappCalBaseMenu);

public:
    VappCalBaseMenu() {}
    VappCalBaseMenu(VappCalMainViewPage::VappCalViewTypeEnum viewType, applib_time_struct dateTime) 
    {
        m_viewType = viewType;
        m_dateTime = dateTime;
    }
    


    void updateChangedCell(srv_tdl_event_id_struct* m_eventbuffer, VfxU32 m_count);


    VfxS32 computeDate2Pos(applib_time_struct *date);
    void computePos2Date(VfxS32 pos, applib_time_struct *date);
    
    VappCalMainViewPage::VappCalViewTypeEnum getMenuViewType();

protected:
    virtual void onInit();
    virtual VcpBaseMenuLayout* createLayout();
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);
    virtual void onAfterCreateLayout();  
  
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );

    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
    );

    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    );

private:

    void setMonthlyCellEvtFlag(srv_tdl_event_id_struct* m_eventbuffer, VfxU32 m_count);



    void setWeeklyCellEvtFlag(srv_tdl_event_id_struct* m_eventbuffer, VfxU32 m_count);

    
    void setWeeklyCellEvtFlagInt(void* pEvent, VfxU8 dow, VfxBool startCheck);
    void setMonthlyCellDisable();
    VfxBool checkCellIsWeekend(VfxU8 pos);
    VfxBool checkCellIsToday(VfxU8 pos);    

    void updateEvtFlag(srv_tdl_event_id_struct* m_eventbuffer, VfxU32 m_count);

   

public:
    static void getFirstDayOfWeek(const applib_time_struct* date, applib_time_struct* dateOutPut);
    static void getWeeklyDate(const applib_time_struct *currDT, VfxU8 *dateArray);

public:
    VfxSignal2 <VfxObject*, VfxS32> m_signalCellClicked;

private:
    applib_time_struct m_dateTime;
    VappCalMainViewPage::VappCalViewTypeEnum m_viewType;
    VfxBool m_isExistEvt[VAPP_CAL_WEEKLY_ROW * VAPP_CAL_WEEKLY_COLUMN];
    VfxBool m_isDisabled[VAPP_CAL_MONTHLY_ROW * VAPP_CAL_MONTHLY_COLUMN];
    VfxU8 m_day[VAPP_CAL_MONTHLY_ROW * VAPP_CAL_MONTHLY_COLUMN];
};


/***************************************************************************** 
 * Class VappCalBaseLayout
 *****************************************************************************/
class VappCalBaseLayout : public VcpBaseMenuLayout
{

public:
    VappCalBaseLayout() : VcpBaseMenuLayout(NULL) {};
    VappCalBaseLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {};
    
public:
    virtual void onInit();
    virtual VfxS32 getCellCount(VfxS32 group);
    virtual ScrollDirEnum getScrollDir();
    virtual VfxS32 getContentLength();
    virtual VfxRect queryCellRect(VcpMenuPos pos);
    virtual VcpMenuRegion queryRegion(const VfxRect& r);
    
public:
    VcpMenuPos getPosByPoint(VfxPoint pt);

private:
    VfxS32 m_firstCellWidth;
    VfxS32 m_cellWidth;
    VfxS32 m_cellHeight;
    VfxS32 m_columnCount;
    VappCalBaseMenu *m_menu;
};


class VappCalMonthlyCell : public VfxControl
{

public:
    VappCalMonthlyCell() {}
    
    VappCalMonthlyCell(VfxS32 pos) : m_posId(pos) 
    {
        m_isExistEvt = VFX_FALSE;
        m_isToday = VFX_FALSE;
        m_isDisabled = VFX_FALSE;
        m_isWeekend = VFX_FALSE;
    }

public:
    virtual void onInit();
    virtual void onUpdate();
    
public:
    void setEvtExist(VfxBool isExistEvt);
    void setDisabled(VfxBool isDisabled);
    void setWeekend(VfxBool isWeekend);
    void setToday(VfxBool isToday);
    void setDate(VfxU8 day);
    
    VfxBool getEvtExist() const
    {
        return m_isExistEvt;
    }
    VfxBool getDisabled() const
    {
        return m_isDisabled;
    }
    VfxU8 getDate() const
    {
        return m_day;
    }
    
private:
    VfxBool m_isExistEvt;
    VfxBool m_isToday;
    VfxBool m_isDisabled;
    VfxBool m_isWeekend;
    VfxU8   m_day;
    VfxS32  m_posId;
};

/***************************************************************************** 
 * Class VappCalWeeklyCell
 *****************************************************************************/
class VappCalWeeklyCell : public VfxControl
{

public:
    VappCalWeeklyCell() {}
    
    VappCalWeeklyCell(VfxS32 pos)
    {
        m_posId = pos;
        m_isExistEvt = VFX_FALSE;
    }

public:
    virtual void onInit();
    virtual void onUpdate();

public:
    void setEvtExist(VfxBool isExistEvt);
    
    VfxBool getEvtExist() const
    {
        return m_isExistEvt;
    }
    
private:
    VfxBool m_isExistEvt;
    VfxS32  m_posId;
};

/***************************************************************************** 
 * Class VappCalDailyList
 *****************************************************************************/
class VappCalDailyList : public VcpListMenu, IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappCalDailyList);

public:
    VappCalDailyList() {};
    VappCalDailyList(VfxU16 viewType, applib_time_struct dateTime) 
        : m_viewType(viewType),
        m_dateTime(dateTime),
        m_jobId(-1),
        m_count(0),
        m_eventbuffer(NULL),
        m_stringId(STR_GLOBAL_LOADING)
        {};

public:
    enum VAPP_CAL_ICON_ENUM
    {
        VAPP_CAL_NO_ICON,
        VAPP_CAL_ONLY_ALARM_ICON,
        VAPP_CAL_ONLY_REPEAT_ICON,
        VAPP_CAL_TWO_ICON,
        VAPP_CAL_ICON_TOTAL
    };

public:
    virtual void onInit();

    virtual void onDeinit();
    srv_tdl_event_id_struct *GetEventbuffer() const;


    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    
    virtual VfxU32 getCount() const;
    
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

    virtual VfxBool getMenuEmptyText(
                        VfxWString &text,               
                        VcpListMenuTextColorEnum &color);

public:
    VappCalListMgr *getListMgr();

public:
    static mmi_ret onEventReady(mmi_event_struct *param);
   

    static void setItemImagebyIdx(srv_tdl_event_id_struct event_id, VcpListMenuFieldEnum fieldType, VfxImageSrc &image, VfxObject* pram);	

    
private:
    VappCalListMgr *m_listMgr;
    VfxU16 m_viewType;
    applib_time_struct m_dateTime;
    VfxS32 m_jobId; 
    VfxU32 m_count;
    srv_tdl_event_id_struct *m_eventbuffer ;
    VfxU16 m_stringId;


};


/***************************************************************************** 
 * Class  VappCalViwerSwitchBar
 *****************************************************************************/
class VcpSegmentButton;
class VcpButton;
class VappCalViwerSwitchBar : public VcpPanelBar
{

public:
enum VappCalSwitchTypeEnum
{
    VAPP_CAL_SWITCH_TYPE_LIST,
    VAPP_CAL_SWITCH_TYPE_ADD,
    VAPP_CAL_SWITCH_TYPE_MONTH,
    VAPP_CAL_SWITCH_TYPE_WEEK,
    VAPP_CAL_SWITCH_TYPE_DAY,

    VAPP_CAL_SWITCH_TYPE_TOTAL
};

public:
    void onAddItem();
    void setSegmentPressed(VfxId id);
    
public:
    VfxSignal2 <VfxObject*, VfxId> m_signalClicked;

private:
    void onClick(VfxObject *sender, VfxId id);

private:
    VcpButton *m_listButton;
    VcpButton *m_addButton;
    VcpSegmentButton *m_segButton;
};

#endif //__VAPP_CAL_MAIN_VIEW_H__

