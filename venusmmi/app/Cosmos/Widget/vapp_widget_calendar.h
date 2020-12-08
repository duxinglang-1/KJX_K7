/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_calendar.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the hello world widget.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_WIDGET_CALENDAR_H
#define VAPP_WIDGET_CALENDAR_H

#include "MMI_features.h"
/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vcp_base_menu.h"
#ifdef __cplusplus
extern "C"
#include "app_datetime.h"
#endif
{
#ifdef __cplusplus
}
#endif

#ifdef __MMI_VUI_WIDGET_CALENDAR__ 
class VappWidgetCalendarMenu;
/*****************************************************************************
 * Calendar Widget CP
 *****************************************************************************/
#define VAPP_CALENDAR_DEFAULT_X 0
#define VAPP_CALENDAR_DEFAULT_Y 0

#ifdef __MMI_MAINLCD_320X480__
	#define VAPP_CALENDAR_WIDGET_CELL_WIDTH 269
	#define VAPP_CLAENDAR_WIDGET_CELL_HEIGHT 32
	#define VAPP_HS_WIDGET_CALENDAR_MONTH_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(22)
	#define VAPP_HS_WIDGET_CALENDAR_WEEK_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(14)
	#define VCP_CALENDAR_NUMBER_FONT_SIZE             VFX_FONT_DESC_VF_SIZE(16)
#elif defined(__MMI_MAINLCD_480X800__)
	#define VAPP_CALENDAR_WIDGET_CELL_WIDTH 425
	#define VAPP_CLAENDAR_WIDGET_CELL_HEIGHT 50
	#define VAPP_HS_WIDGET_CALENDAR_MONTH_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(35)
	#define VAPP_HS_WIDGET_CALENDAR_WEEK_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(22)
	#define VCP_CALENDAR_NUMBER_FONT_SIZE             VFX_FONT_DESC_VF_SIZE(26)
#else
	#define VAPP_CALENDAR_WIDGET_CELL_WIDTH 182
	#define VAPP_CLAENDAR_WIDGET_CELL_HEIGHT 22
	#define VAPP_HS_WIDGET_CALENDAR_MONTH_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(16)
	#define VAPP_HS_WIDGET_CALENDAR_WEEK_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(10)
	#define VCP_CALENDAR_NUMBER_FONT_SIZE             VFX_FONT_DESC_VF_SIZE(11)
    #define VAPP_HS_WIDGET_CALENDAR_BUTTON_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(13)
#endif

#define VAPP_HS_CALENDAR_LAST_YEAR     (2030)
#define VAPP_HS_CALENDAR_FIRST_YEAR    (1970)


#define VCP_CALENDAR_LINE_COLOR  VRT_COLOR_MAKE(255, 195, 195, 195)

#define VAPP_CALENDAR_NUMBER_GREY_COLOR    VRT_COLOR_MAKE(255, 174, 174, 174)

/***************************************************************************** 
 * Class VappCalLineFrame
 *****************************************************************************/
class VappDateInterface : public VfxObject
{
public:
	VfxS32 getDay(VfxS32 month, VfxS32 year);
};
// Draw calendar background lines.
class VappCalLineFrame : public VfxFrame
{
// Constructor / Destructor
public:
	VappCalLineFrame();
//method
public:
	void setLineColor(const VfxColor &color);
// orerride
protected:
    virtual void onDraw(VfxDrawContext &dc);
private:
	VfxColor m_color;
};

class VappCalNumberFrame : public VfxFrame
{
// Constructor / Destructor
public:
	VappCalNumberFrame();
// Method
public:
	enum{
		NON_GREY,
		FIRST_GREY,
		LAST_GREY,
	};
public:
	void setDayMark(VfxS8 mark);
	void setDayNumber(VfxU8 index, VfxU8 number);
	void get_index_coordinate(VfxS32 i, VfxS32 *x, VfxS32 *y, VfxS32 *w, VfxS32 *h);
	void setHighlightDay(VfxPoint p);
	void setUnHighlightDay();
	void setCurrentDayIndex(VfxU8 index);
	void setColorStyle(VfxU8 style);
	void setEvent(VfxS32 index, VfxBool isEvent);
protected:
	virtual void onDraw(VfxDrawContext &dc);
    virtual void onInit();
    virtual void onDeinit();
private:
	VfxU8 m_day[7];
    VfxS8 m_mark;
	VfxS8 m_style;
	VfxU8 m_current_index;
	VfxImageFrame *m_rect;
	VfxBool m_event[7];
};


class VappWidgetCalendarCell : public VfxFrame
{
//    VFX_DECLARE_CLASS(VcpCalendar);
    // Constructor / Destructor
public:
	VappWidgetCalendarCell(applib_time_struct time);
// Method
public:
	applib_time_struct get_time(void)
	{
		return m_time;
	}
    applib_time_struct get_pos_time(VfxPoint pt);
	//void setCurrentDay(VfxS32 day);
	void setHighlight(VfxPoint point);
	void setUnHighlight();
	VfxPoint getHighlight();
	void setCurrentTime(applib_time_struct time);
	void setInvalidTime();
	void setEvent();
	void setCurrentDay();
	// Override
protected:    
    virtual void onInit();
    virtual void onDeinit();
private:
	VfxS32 m_column;
	VfxS32 m_row;
	VfxS32 m_day;
	VfxFont m_font;
	VfxColor m_color;
	VappCalLineFrame *m_line;
	VappCalNumberFrame *m_number;
	applib_time_struct m_time;
	VfxPoint m_highlight;

};

class VappWidgetCalendarMenuLayout : public VcpBaseMenuLayout
{
    // Constructor / Destructor
public:
    VappWidgetCalendarMenuLayout(VappWidgetCalendarMenu* menu);
    
    ~VappWidgetCalendarMenuLayout();
	// Method
public:
    VcpMenuPos getCellByPos(VfxPoint pt);
    VfxS32 getDay(VfxS32 month, VfxS32 year);
	void getWeekByPos(VfxS32 pos, applib_time_struct *time);
	VfxS32 getFirstItem();
	void setFirstItem(VfxS32 item);
    const VfxPoint& getCurrentViewPos() const
    {
        return m_viewRect.origin;
    }

    // Override
public:
    virtual void onInit();
    
    virtual ScrollDirEnum getScrollDir();
    
    virtual VfxS32 getCellCount(VfxS32 group);
    
    virtual VfxS32 getContentLength();
    
    virtual VcpMenuRegion queryRegion(const VfxRect& r);
	virtual VfxRect queryCellRect(VcpMenuPos pos);
    
    virtual void onViewChanged();
	virtual VfxBool navDir(NavDirEnum dir);
private:
	VfxS32 m_count;
	VfxS32 m_height;
	VfxS32 m_first_item;

};


class VappWidgetCalendarMenu : public VcpBaseMenu
{
// Constructor / Destructor
public:
    VappWidgetCalendarMenu();
//Method
public:
	void setViewItem(applib_time_struct time);
	void updateViewItem(const applib_time_struct *new_time, const applib_time_struct *old_time);
	void setUnSelected(void);
	VfxS32 getLaunchPos(void);
	void setLaunchPos(VfxS32 pos);
// Signal
public:    
    VfxSignal1 <applib_time_struct>    m_signalMonth;
	void onTimer(
        VfxTimer *source        //[IN] Timer source
        );
	void onLaunchCalendar(VcpMenuPos cellPos);
// Override
protected:
    virtual VcpBaseMenuLayout* createLayout();
    virtual VfxFrame* createCell(
            VfxS32 group,           // [IN] The group index
            VfxS32 pos              // [IN] The cell index
        );
    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    );
	virtual void onTapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
    );
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);

    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag);       
	virtual void onViewScrollEnd();
	virtual void onViewScrollStart();
	virtual VfxBool onKeyInput(VfxKeyEvent &event);
private:
	VfxTimer *m_timer;
	VfxS32 m_hl_pos;
	VfxS32 m_launch_pos;
	VfxBool m_scrollEnd;
};

/*****************************************************************************
 * Calendar Widget
 *****************************************************************************/
class VappWidgetCalendar : public VappWidget
{
	VAPP_WIDGET_DECLARE_CLASS(VappWidgetCalendar);

public:
    enum
    {
#ifdef __MMI_MAINLCD_320X480__
        WIDTH = 289,
        HEIGHT = 283, //280,

		WEEK_X = 11,
		WEEK_Y = 58,
		WEEK_WIDTH = 269,
		WEEK_HEIGHT = 25,
		WEEK_CELL_WIDTH = 38,

		MONTH_X = 105,
		MONTH_Y = 15,
		MONTH_WIDTH = 165,
		MONTH_HEIGHT = 43,

		CALENDAR_X = 10,
		CALENDAR_Y = 78,
		CALENDAR_WIDTH = 269,
		CALENDAR_HEIGHT = 192,

		BUTTON_X = 11,
		BUTTON_Y = 10,
		BUTTON_WIDTH = 90,
		BUTTON_HEIGHT = 35,

		DELETE_BUTTON_X = 277,
		DELETE_BUTTON_Y = 16
#elif defined(__MMI_MAINLCD_480X800__)
        WIDTH = 460,
        HEIGHT = 443,
		WEEK_X = 12,
		WEEK_Y = 88,
		WEEK_WIDTH = 425,
		WEEK_HEIGHT = 25,
		WEEK_CELL_WIDTH = 61,
		
		MONTH_X = 160,
		MONTH_Y = 21,
		MONTH_WIDTH = 260,
		MONTH_HEIGHT = 43,
		
		CALENDAR_X = 19,
		CALENDAR_Y = 117,
		CALENDAR_WIDTH = 425,
		CALENDAR_HEIGHT = 300, //302,

		BUTTON_X = 15,
		BUTTON_Y = 15,
		BUTTON_WIDTH = 140,
		BUTTON_HEIGHT = 60,

		DELETE_BUTTON_X = 433,
		DELETE_BUTTON_Y = 16
#else
		WIDTH = 194,
        HEIGHT = 191, //280,

		WEEK_X = 5,
		WEEK_Y = 38,
		WEEK_WIDTH = 182, //183,
		WEEK_HEIGHT = 15,
		WEEK_CELL_WIDTH = 26,

		MONTH_X = 65,
		MONTH_Y = 10,
		MONTH_WIDTH = 110,
		MONTH_HEIGHT = 23,

		CALENDAR_X = 5,
		CALENDAR_Y = 50,
		CALENDAR_WIDTH = 182, //183,
		CALENDAR_HEIGHT = 131, //132,

		BUTTON_X = 8,
		BUTTON_Y = 5,
		BUTTON_WIDTH = 55,
		BUTTON_HEIGHT = 25,

		DELETE_BUTTON_X = 183,
		DELETE_BUTTON_Y = 15
#endif		
    };

// Constructor / Destructor
public:
    VappWidgetCalendar();
// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

// Override
public:
    virtual void onCreateView();

    virtual void onReleaseView();

    virtual void onSerializeView(VfxArchive *ar);

    virtual void onRestoreView(VfxArchive *ar);

    virtual void onDrag(VfxPenEvent &event);

    virtual void onDrop(VfxPenEvent &event);
	virtual void onAbort(VfxPenEvent &event);
protected:
	virtual VfxPoint onGetEditButtonOffset();
//slot
public:
	void onMonthChange(applib_time_struct time);
	void onBtnClicked(VfxObject *obj, VfxId id);
	static mmi_ret onDataChangeCallBack(mmi_event_struct *param);
//solt
private:
	void onSystemTimeChanged(
        VfxU32 flag // [IN] Is the flag to notify the type of date change
    );
// Variable
private:
	VappWidgetCalendarMenu *m_menu;
	VfxTextFrame *m_text;
	applib_time_struct m_current_time;
	VfxImageFrame *m_bg;
	VfxTextFrame *m_week[7];
	VcpButton *m_button;
};

#endif /*__MMI_VUI_WIDGET_CALENDAR__ */

#endif /* VAPP_WIDGET_CALENDAR_H */
