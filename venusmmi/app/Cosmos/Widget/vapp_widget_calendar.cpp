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
 *  vapp_widget_calendar.cpp
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
 * removed!
 * removed!
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
 ****************************************************************************/
#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_calendar.h"
#include "vcp_include.h"
#include "vfx_uc_include.h"
#include "vcp_res.h"
#include "vapp_cal_gprot.h"
#include "data\vdat_systime.h"
#include "vfx_adp_device.h"
extern "C"
{
	#include "TodolistSrvGprot.h"
	#include "GeneralSettingSrvGprot.h"
	#include "mmi_cb_mgr_gprot.h"

}

#ifdef __MMI_VUI_WIDGET_CALENDAR__ 
#include "mmi_rp_vapp_widget_calendar_def.h"

static VfxBool g_calendar_event_dirty;
/*****************************************************************************
 * Calendar Widget
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetCalendar, VAPP_WIDGET_TYPE_CALENDAR, VappWidgetCalendarPublisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetCalendar, VappWidget);

VappWidgetCalendar::VappWidgetCalendar()
{
    // Do nothing.
}

VappWidgetId VappWidgetCalendar::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_CALENDAR);
}


VfxSize VappWidgetCalendar::getMaxSize() const
{
    return VfxSize(WIDTH, HEIGHT);
}

VfxS32 VappWidgetCalendar::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_WIDGET_CALENDAR_NAME);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}

VfxFrame *VappWidgetCalendar::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_CALENDAR_WIDGET_ICON);

    return icon;
}


void VappWidgetCalendar::onCreateView()
{
    VappWidget::onCreateView();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

	// background image
	VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bg->setResId(IMG_CALENDAR_WIDGET_BG);
    m_bg->setHidden(VFX_FALSE);
	m_bg->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

	// calendar menu
	applib_dt_get_date_time(&m_current_time);
	VFX_OBJ_CREATE(m_menu, VappWidgetCalendarMenu, this);
    m_menu->setPos(VfxPoint(CALENDAR_X, CALENDAR_Y));
    m_menu->setBounds(VfxRect(0, 0, CALENDAR_WIDTH, CALENDAR_HEIGHT));
	m_menu->setViewItem(m_current_time);
	m_menu->m_signalMonth.connect(this, &VappWidgetCalendar::onMonthChange);
	m_menu->setBgColor(VFX_COLOR_WHITE);
	m_menu->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
	m_menu-> enableVerticalScrollIndicator(VFX_FALSE);
	// week name
	for(VfxS32 i = 0; i < 7; i++)
	{
		VfxWString str;
		if(i == 0)
			str.loadFromRes(STR_ID_WIDGET_CALENDAR_SUN);
		else
		    str.loadFromRes(STR_ID_WIDGET_CALENDAR_MON + i - 1);
		VFX_OBJ_CREATE(m_week[i], VfxTextFrame, m_bg);
		m_week[i]->setFont(VfxFontDesc(VAPP_HS_WIDGET_CALENDAR_WEEK_FONT_SIZE));
		m_week[i]->setPos(VfxPoint(WEEK_X + WEEK_CELL_WIDTH*i, WEEK_Y));
		m_week[i]->setString(str);
		m_week[i]->setBounds(VfxRect(0, 0, WEEK_CELL_WIDTH, WEEK_HEIGHT));
		m_week[i]->setColor(VFX_COLOR_WHITE);
		m_week[i]->setAutoResized(VFX_FALSE);
		m_week[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	}
	// month time
	VfxWString str;
	VfxWString month_str, space_str;
	srv_setting_date_format_enum date_format;
	srv_setting_date_seperator_enum date_seperator;

	date_format = srv_setting_get_date_format();
	date_seperator = srv_setting_get_date_seperator();

	str.format("%d", m_current_time.nYear);
	if(m_current_time.nMonth < 10)
	{
		VfxWString zero_str;
		month_str.format("%d", 0);
		zero_str.format("%d", m_current_time.nMonth);
		month_str += zero_str;
	}
	else
	{
		month_str.format("%d", m_current_time.nMonth);
	}
	if(date_seperator == SETTING_DATE_SEPERATOR_DOT)
		space_str.loadFromMem((VfxWChar*)L".");
	else if(date_seperator == SETTING_DATE_SEPERATOR_COLON)
		space_str.loadFromMem((VfxWChar*)L":");
	else if(date_seperator == SETTING_DATE_SEPERATOR_SLOPE)
		space_str.loadFromMem((VfxWChar*)L"/");
	else if(date_seperator == SETTING_DATE_SEPERATOR_LINE)
		space_str.loadFromMem((VfxWChar*)L"-");
	if(date_format == SETTING_DATE_FORMAT_DD_MM_YYYY || date_format == SETTING_DATE_FORMAT_MM_DD_YYYY)
	{
		month_str += space_str;
	    month_str += str;
	}
	else
	{
		str += space_str;
		str +=month_str;
	}
 
	VFX_OBJ_CREATE(m_text, VfxTextFrame, m_bg);
	m_text->setPos(VfxPoint(MONTH_X, MONTH_Y));
	if(date_format == SETTING_DATE_FORMAT_DD_MM_YYYY || date_format == SETTING_DATE_FORMAT_MM_DD_YYYY)
	    m_text->setString(month_str);
	else
		m_text->setString(str);
	m_text->setBounds(VfxRect(0, 0, MONTH_WIDTH, MONTH_HEIGHT));
	m_text->setColor(VFX_COLOR_WHITE);
	m_text->setFont(VfxFontDesc(VAPP_HS_WIDGET_CALENDAR_MONTH_FONT_SIZE));
	m_text->setAutoResized(VFX_FALSE);
	m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

	// button , back to today
	VfxWString button_str;
	button_str.loadFromRes(STR_ID_WIDGET_CALENDAR_TODAY);
	VFX_OBJ_CREATE(m_button, VcpButton, m_bg);
	VcpStateImage image(IMG_CALENDAR_WIDGET_BUTTON_N, IMG_CALENDAR_WIDGET_BUTTON_P, NULL, NULL);
	m_button->setPos(VfxPoint(BUTTON_X, BUTTON_Y));
	m_button->setBounds((VfxRect(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT)));
	m_button->setBgImageList(image);
    m_button->setText(button_str);
	m_button->setTextColor(VFX_COLOR_BLACK);
#if (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
	m_button->setTextFont(VfxFontDesc(VAPP_HS_WIDGET_CALENDAR_BUTTON_FONT_SIZE));
#endif
	m_button->getButtonTextFrame()->setFullLineHeightMode(VFX_FALSE);
    m_button->m_signalClicked.connect(this, &VappWidgetCalendar::onBtnClicked);

// update date
	VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWidgetCalendar::onSystemTimeChanged);

	g_calendar_event_dirty = VFX_FALSE;
	mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_OP, onDataChangeCallBack, this);	
	mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_OP, onDataChangeCallBack, this);	

}

mmi_ret VappWidgetCalendar::onDataChangeCallBack(mmi_event_struct *param)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	g_calendar_event_dirty = VFX_TRUE;
	return MMI_RET_OK;

}
void VappWidgetCalendar::onSystemTimeChanged(VfxU32 flag)
{
	if (flag & VDAT_SYSTIME_CHANGED_DAY)
	{
		applib_time_struct old_time;
		old_time = m_current_time;
		applib_dt_get_date_time(&m_current_time);
		m_menu->updateViewItem(&m_current_time, &old_time);  
	}
}

void VappWidgetCalendar::onBtnClicked(VfxObject *obj, VfxId id)
{
	m_menu->setViewItem(m_current_time);   
}

void VappWidgetCalendar::onReleaseView()
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_OP, onDataChangeCallBack, this);	    
	mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_OP, onDataChangeCallBack, this);	 
	VFX_OBJ_CLOSE(m_menu);
	VFX_OBJ_CLOSE(m_bg);
    VappWidget::onReleaseView();
}


void VappWidgetCalendar::onSerializeView(VfxArchive *ar)
{
	VfxS32 first_pos;
	VfxS32 launch_pos;

	first_pos = ((VappWidgetCalendarMenuLayout*)m_menu->getLayout())->getFirstItem();
	ar->writeU32(first_pos);

	launch_pos = m_menu->getLaunchPos();
	ar->writeU16(launch_pos);
	VFX_OBJ_CLOSE(m_menu);
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappWidgetCalendar::onSystemTimeChanged);
}


void VappWidgetCalendar::onRestoreView(VfxArchive *ar)
{
	applib_time_struct time, old_time;
	VfxS32 first_pos, launch_pos, pos;
	VfxBool is_update = VFX_FALSE;

	pos = first_pos = ar->readU32();
	launch_pos = ar->readU16();

	if ((launch_pos)&&(launch_pos > pos + 5 || launch_pos < pos - 5))
	{
		pos = launch_pos;
	}


	if(1)  //g_calendar_event_dirty || is_update)
	{
		//VFX_OBJ_CLOSE(m_menu);
	    VFX_OBJ_CREATE(m_menu, VappWidgetCalendarMenu, this);
        m_menu->setPos(VfxPoint(CALENDAR_X, CALENDAR_Y));
        m_menu->setBounds(VfxRect(0, 0, CALENDAR_WIDTH, CALENDAR_HEIGHT));
	    m_menu->m_signalMonth.connect(this, &VappWidgetCalendar::onMonthChange);
	    m_menu->setBgColor(VFX_COLOR_WHITE);
	    m_menu->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
	    m_menu->enableVerticalScrollIndicator(VFX_FALSE);
		g_calendar_event_dirty = VFX_FALSE;
	}
	((VappWidgetCalendarMenuLayout*)m_menu->getLayout())->getWeekByPos(pos+1, &time);

	old_time = m_current_time;
	applib_dt_get_date_time(&m_current_time);
	if((old_time.nYear != m_current_time.nYear) || (old_time.nMonth != m_current_time.nMonth) || 
		(old_time.nDay != m_current_time.nDay))
	{
		is_update = VFX_TRUE;
		time = m_current_time;	
	}
	m_menu->setViewItem(time);
	m_menu->setLaunchPos(0);
	VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWidgetCalendar::onSystemTimeChanged);

 }


void VappWidgetCalendar::onDrag(VfxPenEvent &event)
{
    VappWidget::onDrag(event);
}

void VappWidgetCalendar::onDrop(VfxPenEvent &event)
{
	m_menu->setUnSelected();
    VappWidget::onDrop(event);
}

void VappWidgetCalendar::onAbort(VfxPenEvent &event)
{
	m_menu->setUnSelected();
    VappWidget::onAbort(event);
}

void VappWidgetCalendar::onMonthChange(applib_time_struct time)
{
	VfxWString year_str;
	VfxWString month_str, space_str;
	srv_setting_date_format_enum date_format;
	srv_setting_date_seperator_enum date_seperator;

	date_format = srv_setting_get_date_format();
	date_seperator = srv_setting_get_date_seperator();

	year_str.format("%d", time.nYear);
	if(time.nMonth < 10)
	{
		VfxWString zero_str;
		month_str.format("%d", 0);
		zero_str.format("%d", time.nMonth);
		month_str += zero_str;
	}
	else
	{
		month_str.format("%d", time.nMonth);
	}
	if(date_seperator == SETTING_DATE_SEPERATOR_DOT)
		space_str.loadFromMem((VfxWChar*)L".");
	else if(date_seperator == SETTING_DATE_SEPERATOR_COLON)
		space_str.loadFromMem((VfxWChar*)L":");
	else if(date_seperator == SETTING_DATE_SEPERATOR_SLOPE)
		space_str.loadFromMem((VfxWChar*)L"/");
	else if(date_seperator == SETTING_DATE_SEPERATOR_LINE)
		space_str.loadFromMem((VfxWChar*)L"-");
	if(date_format == SETTING_DATE_FORMAT_DD_MM_YYYY || date_format == SETTING_DATE_FORMAT_MM_DD_YYYY)
	{ 
		month_str += space_str;
	    month_str += year_str;
	    m_text->setString(month_str);
    }
 	else
	{
		year_str += space_str;
		year_str += month_str;
		m_text->setString(year_str);
	}
}

VfxPoint VappWidgetCalendar::onGetEditButtonOffset()
{
	return VfxPoint(DELETE_BUTTON_X, DELETE_BUTTON_Y); 
}

/*****************************************************************************
 * Calendar Widget CP
 *****************************************************************************/
VappWidgetCalendarCell::VappWidgetCalendarCell(applib_time_struct time)
{
	m_column = 7;
	m_row = 6;
	m_day = 1;
	m_time = time;
    m_highlight = VFX_POINT_ZERO;
}

void VappWidgetCalendarCell::setEvent()
{
	VfxU16 ret, count;
	srv_tdl_search_filter_struct filter;
	VfxS32 last_day;
	applib_time_struct temp_time;
	VappDateInterface dateInterface;

	temp_time = m_time;

	filter.type = SRV_TDL_SEARCH_TYPE_DAILY;
	last_day = dateInterface.getDay(temp_time.nMonth, temp_time.nYear);
	for(VfxS32 i = 0; i < 7; i++)
	{
	    temp_time.nDay =m_time.nDay + i;
		temp_time.nMonth = m_time.nMonth;
		temp_time.nYear = m_time.nYear;
		if(temp_time.nDay >last_day)
		{
			temp_time.nDay = temp_time.nDay - last_day;
			temp_time.nMonth ++;
			if(temp_time.nMonth > 12)
			{
				temp_time.nMonth = 1;
				temp_time.nYear++;
			}
		}
		filter.u.date_time.nYear = temp_time.nYear;
		filter.u.date_time.nMonth = temp_time.nMonth;
		filter.u.date_time.nDay = temp_time.nDay;

		ret = srv_tdl_search(NULL, NUM_OF_CAL, SRV_TDL_VCAL_EVENT, filter, &count);

		if((ret == SRV_TDL_RESULT_OK) && (count>0))
			m_number->setEvent(i, VFX_TRUE);
		else
		    m_number->setEvent(i, VFX_FALSE);

	}
}

applib_time_struct VappWidgetCalendarCell::get_pos_time(VfxPoint pt)
{
	VfxS32 i = VAPP_CALENDAR_WIDGET_CELL_WIDTH / 7;

	VfxS32 pos = pt.x / i;

	applib_time_struct time;

	VfxS32 last_day;
	VappDateInterface dateInterface;
	
	last_day = dateInterface.getDay(m_time.nMonth, m_time.nYear);
	
	time = m_time;

	time.nDay += pos;

	if(time.nDay > last_day)
	{
		time.nDay = time.nDay - last_day;

		time.nMonth++;
		if(time.nMonth > 12)
		{
			time.nYear ++;
			time.nMonth = 1;
		}
	}

	return time;

}

void VappWidgetCalendarCell::onInit()
{
	VfxFrame::onInit();

	// draw line
	VFX_OBJ_CREATE(m_line, VappCalLineFrame, this);
	m_line->setBounds(VfxRect(VAPP_CALENDAR_DEFAULT_X, VAPP_CALENDAR_DEFAULT_Y, VAPP_CALENDAR_WIDGET_CELL_WIDTH, VAPP_CLAENDAR_WIDGET_CELL_HEIGHT));
	m_line->setLineColor(VCP_CALENDAR_LINE_COLOR);
	m_line->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

    // draw number
	VFX_OBJ_CREATE(m_number, VappCalNumberFrame, this);

	m_number->setDayMark(-1);
	m_number->setPos(VfxPoint(0, 0));
	m_number->setBounds(VfxRect(0, 0, VAPP_CALENDAR_WIDGET_CELL_WIDTH, VAPP_CLAENDAR_WIDGET_CELL_HEIGHT));
	
	setEvent();
	setCurrentDay();
}

void VappWidgetCalendarCell::setCurrentDay()
{
	VfxS32 i;
	VfxS32 last_day;
	VappDateInterface dateInterface;
	applib_time_struct current_time, temp_time;
	applib_dt_get_date_time(&current_time);
	temp_time = m_time;

	last_day = dateInterface.getDay(m_time.nMonth, m_time.nYear);
	// set pre day number
	VfxS32 curr_day;
	curr_day = m_time.nDay;
	m_number->setCurrentDayIndex(-1);
	if(last_day - curr_day >= 7)
	{
		for(i = 0 ; i < 7; i++)
		{
			if((curr_day == current_time.nDay) && (m_time.nMonth == current_time.nMonth) && (m_time.nYear == current_time.nYear))
				m_number->setCurrentDayIndex(i);
			m_number->setDayNumber(i, curr_day++);
			
		}
		m_number->setDayMark(7);
	}
	else
	{
		VfxS32 j = m_time.nDay;
		for(i = 0; i < last_day - m_time.nDay + 1; i++)
		{
			if((j == current_time.nDay)&& (temp_time.nMonth == current_time.nMonth) && (temp_time.nYear == current_time.nYear))
				m_number->setCurrentDayIndex(i);
			m_number->setDayNumber(i, m_time.nDay+i);
			j++;
		}
		m_number->setDayMark(i-1);

		if(temp_time.nMonth == 12)
		{
			temp_time.nMonth = 1;
			temp_time.nYear ++;
		}
		else
		{
			temp_time.nMonth++;
		}
		
		j = 1;
		for(; i < 7; i++)
		{
			if((j == current_time.nDay)&& (temp_time.nMonth == current_time.nMonth) && (temp_time.nYear == current_time.nYear))
				m_number->setCurrentDayIndex(i);
			m_number->setDayNumber(i, j);
			j++;

		}
	}	
}

void VappWidgetCalendarCell::onDeinit()
{
	VfxFrame::onDeinit();
	VFX_OBJ_CLOSE(m_line);
	VFX_OBJ_CLOSE(m_number);
}

void VappWidgetCalendarCell::setHighlight(VfxPoint p)
{
	m_number->setHighlightDay(p);
    m_highlight = p;
}

void VappWidgetCalendarCell::setUnHighlight()
{
	m_number->setUnHighlightDay();
}
VfxPoint VappWidgetCalendarCell::getHighlight()
{
	return m_highlight;
}
void VappWidgetCalendarCell::setCurrentTime(applib_time_struct time)
{
	if(time.nMonth == m_time.nMonth)
	{
       // Last grey
		m_number->setColorStyle(VappCalNumberFrame::LAST_GREY);
	}
	else
	{
		// first grey
		m_number->setColorStyle(VappCalNumberFrame::FIRST_GREY);
	}
}

void VappWidgetCalendarCell::setInvalidTime()
{
	m_number->setColorStyle(VappCalNumberFrame::NON_GREY);
}
VcpBaseMenuLayout* VappWidgetCalendarMenu::createLayout()
{
    VappWidgetCalendarMenuLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VappWidgetCalendarMenuLayout, this, (this));
    return layout;
}

VappWidgetCalendarMenu::VappWidgetCalendarMenu() : m_timer(NULL),m_scrollEnd(VFX_FALSE),m_launch_pos(0)
{
}

VfxFrame* VappWidgetCalendarMenu::createCell(VfxS32 group, VfxS32 pos)
{
	VappWidgetCalendarCell *CalendarCell;
	applib_time_struct time;

	((VappWidgetCalendarMenuLayout*)getLayout())->getWeekByPos(pos, &time);
	VFX_OBJ_CREATE_EX(
				CalendarCell,
				VappWidgetCalendarCell,
				this,
				(time));
	CalendarCell->setBgColor(VFX_COLOR_WHITE);
	CalendarCell->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
	CalendarCell->setBounds(VfxRect(VAPP_CALENDAR_DEFAULT_X, VAPP_CALENDAR_DEFAULT_Y, VAPP_CALENDAR_WIDGET_CELL_WIDTH, VAPP_CLAENDAR_WIDGET_CELL_HEIGHT));
	return CalendarCell;
}

void VappWidgetCalendarMenu::updateViewItem(const applib_time_struct *new_time, const applib_time_struct *old_time)
{
	VfxPoint pos = ((VappWidgetCalendarMenuLayout*)getLayout())->getCurrentViewPos();

	VcpMenuPos p = ((VappWidgetCalendarMenuLayout*)getLayout())->getCellByPos(VfxPoint(pos.x,pos.y));
	if(new_time->nMonth != old_time->nMonth)
	{
		for(VfxS32 i = 0; i<7; i++)
		{
			VfxU32 flag = 0;
			VappWidgetCalendarCell *cell;
			cell = (VappWidgetCalendarCell*)getCell(p, flag);
			if(cell)
				cell->setCurrentDay();
			p.pos++;
		}
		setViewItem(*new_time);
		invalidate();
	}
	else
	{	
		for(VfxS32 i = 0; i<6; i++)
		{
			VfxU32 flag = 0;
			VappWidgetCalendarCell *cell;
			cell = (VappWidgetCalendarCell*)getCell(p, flag);
			if(cell)
				cell->setCurrentDay();
			p.pos++;
		}
		invalidate();
	}
}
void VappWidgetCalendarMenu::setViewItem(applib_time_struct time)
{
    VfxS32 total_day_count = 0;
	VappDateInterface dateInter;
	VfxS32 first_day;
	VfxS32 pos;
	VfxS32 height;

	if(m_isScrolling)
		stopScrolling();
	for(VfxS32 i = VAPP_HS_CALENDAR_FIRST_YEAR; i < time.nYear; i++)
	{
		total_day_count += 365;
		if(i%4 == 0)
			total_day_count++;
	}
	for(VfxS32 i = 1; i < time.nMonth; i++)
	{
		if(time.nMonth == 1)
			break;
		VfxS32 day;
		day = dateInter.getDay(i, time.nYear);
		total_day_count += day;
	}
	total_day_count += 1;
	if(total_day_count < 7) // first month,
	{
		pos = 0;
	}
	else
	{
	    first_day = applib_dt_dow(VAPP_HS_CALENDAR_FIRST_YEAR, 1, 1);
	    pos = (total_day_count - (7 - first_day)) / 7 + 1;
	    if((total_day_count - (7 - first_day))%7)
		    pos++;
	    pos--;
	}
	VcpMenuPos p(0, pos);
	((VappWidgetCalendarMenuLayout*)getLayout())->setFirstItem(pos);
	height = VAPP_CLAENDAR_WIDGET_CELL_HEIGHT*6;
	if(height > (getBounds()).size.height)
		height = (getBounds()).size.height;
	makeVisible(VfxRect(0, p.pos*VAPP_CLAENDAR_WIDGET_CELL_HEIGHT, VAPP_CALENDAR_WIDGET_CELL_WIDTH, height), VFX_FALSE);
	m_signalMonth.emit(time);
	invalidate();
}

void VappWidgetCalendarMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_UNUSED(group);
    VFX_UNUSED(pos);
    VFX_OBJ_CLOSE(cellFrame);
}

void VappWidgetCalendarMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
    VFX_UNUSED(group);
    VFX_UNUSED(pos);

    cell->setRect(rect);
	applib_time_struct time;

	((VappWidgetCalendarMenuLayout*)getLayout())->getWeekByPos(pos, &time);
	VfxS32 first_pos = ((VappWidgetCalendarMenuLayout*)getLayout())->getFirstItem();
	if((pos >= first_pos) && (pos < first_pos+6))
	{
		if(pos == first_pos)
		{
			if(time.nDay != 1)
				time.nMonth++;
			if(time.nMonth >12)
			{
				time.nMonth = 1;
				time.nYear++;
			}
		}
		else
		{
			((VappWidgetCalendarMenuLayout*)getLayout())->getWeekByPos(first_pos+1, &time);
		}
		((VappWidgetCalendarCell*)cell)->setCurrentTime(time);
	}
}

void VappWidgetCalendarMenu::onTimer( VfxTimer *source)
{
	VfxU32 flag = 0;
	VfxS32 i;
	VappWidgetCalendarCell *cell;
	applib_time_struct time;
	VappDateInterface dateInterface;
	VfxS32 p1, p2;
	p1 =  ((VappWidgetCalendarMenuLayout*)getLayout())->getFirstItem();
	
	getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_NONE);
	VcpMenuPos p = getLayout()->getFocusItem();

	p2 = ((VappWidgetCalendarMenuLayout*)getLayout())->getFirstItem();

	if(p1 != p2)
	makeVisible(VfxRect(0, p.pos*VAPP_CLAENDAR_WIDGET_CELL_HEIGHT, VAPP_CALENDAR_WIDGET_CELL_WIDTH, VAPP_CLAENDAR_WIDGET_CELL_HEIGHT*6));
	((VappWidgetCalendarMenuLayout*)getLayout())->setFirstItem(p.pos);
	cell = (VappWidgetCalendarCell*)getCell(p, flag);

	if(cell == NULL)
		return;
	time = cell->get_time();

	if(time.nDay != 1)
	{
		time.nMonth++;
	}
	if(time.nMonth == 13)
	{
		time.nMonth = 1;
		time.nYear++;
	}
	cell->setCurrentTime(time);
	VfxS32 cell_count = ((VappWidgetCalendarMenuLayout*)getLayout())->getCellCount(0);
	if(p.pos > cell_count - 6)
	{
		VcpMenuPos temp_p;
		temp_p.pos = p.pos - 1;
		temp_p.group = 0;
		cell = (VappWidgetCalendarCell*)getCell(temp_p,flag);
		if(cell != NULL)
			cell->setCurrentTime(time);
	}
	for(i = 1; i < 6; i++)
	{
		p.pos++;
		cell = (VappWidgetCalendarCell*)getCell(p,flag);
		if(cell != NULL)
		cell->setCurrentTime(time);
	}
	invalidate();
	m_timer->stop();

}
VfxBool VappWidgetCalendarMenu::onKeyInput(VfxKeyEvent &event)
{
	return VFX_FALSE;
}
void VappWidgetCalendarMenu::onViewScrollStart()
{
	if(m_timer)
		m_timer->stop();
}
void VappWidgetCalendarMenu::onViewScrollEnd()
{
	if(m_timer)
	{
		m_timer->stop();
		VFX_OBJ_CLOSE(m_timer);
	}
	m_scrollEnd = VFX_TRUE;

	VfxS32 old_first_item;
	VfxPoint pos;

	pos = ((VappWidgetCalendarMenuLayout*)getLayout())->getCurrentViewPos();

	VcpMenuPos p = ((VappWidgetCalendarMenuLayout*)getLayout())->getCellByPos(VfxPoint(pos.x,pos.y));
	VcpMenuPos temp_p = getLayout()->getFocusItem();
	old_first_item = temp_p.pos*VAPP_CLAENDAR_WIDGET_CELL_HEIGHT;

    if(pos.y == old_first_item)
		return;

	VFX_OBJ_CREATE(m_timer, VfxTimer, this);
	m_timer->setStartDelay(50);
	m_timer->m_signalTick.connect(this, &VappWidgetCalendarMenu::onTimer);
	m_timer->start();

	VfxU32 flag = 0;
	VappWidgetCalendarCell *cell;
	applib_time_struct time;
	VappDateInterface dateInterface;
	
	VfxS32 first_day;

	p.pos +=2;   // make most month area to focus
	((VappWidgetCalendarMenuLayout*)getLayout())->getWeekByPos(p.pos, &time);

	if((time.nYear == VAPP_HS_CALENDAR_FIRST_YEAR) && (time.nMonth == 1) ||(time.nYear == VAPP_HS_CALENDAR_FIRST_YEAR-1) )
	{
		p.pos = 0;
	}

	first_day = applib_dt_dow(time.nYear, time.nMonth, 1);
	p.pos =  p.pos- (time.nDay + first_day) / 7;

	if(p.pos < 0)
		p.pos = 0;

	cell = (VappWidgetCalendarCell*)getCell(p, flag);

	if(cell == NULL)
		return;
	time = cell->get_time();

	if(time.nDay != 1)
	{
		time.nMonth++;
	}
	if(time.nMonth == 13)
	{
		time.nMonth = 1;
		time.nYear++;
	}
	m_signalMonth.emit(time);
}

void VappWidgetCalendarMenu::onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    )
{
	if(touchType == TouchDown)
	{
		vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
		VappWidgetCalendarCell *calendar = (VappWidgetCalendarCell*)cell;
		calendar->setHighlight(pt);
		m_hl_pos = cellPos.pos;
		if(m_timer)
			m_timer->stop();
	}
	if(touchType == TouchUp)
	{
		VappWidgetCalendarCell *calendar = (VappWidgetCalendarCell*)cell;
		calendar->setUnHighlight();
	}
}
VfxS32 VappWidgetCalendarMenu::getLaunchPos(void)
{
	return m_launch_pos;
}

void VappWidgetCalendarMenu::setLaunchPos(VfxS32 pos)
{
	m_launch_pos = pos;
}
void VappWidgetCalendarMenu::onLaunchCalendar(VcpMenuPos cellPos)
{
	VfxU32 flag = 0;
	VappWidgetCalendarCell *calendar = (VappWidgetCalendarCell*)getCell(cellPos, flag);
	applib_time_struct time;
	
    if(calendar)
    {
		VfxPoint pt;
		pt = calendar->getHighlight();
	    time = calendar->get_pos_time(pt);
	    time.nHour = 0;
	    time.nMin = 0;
	    time.nSec = 0;
	    time.DayIndex = 0;
		if((time.nYear > VAPP_HS_CALENDAR_LAST_YEAR)  || (time.nYear < VAPP_HS_CALENDAR_FIRST_YEAR))
			return;
		m_launch_pos = cellPos.pos;
	    vapp_calendar_launch_by_widget(&time);
	}
}

void VappWidgetCalendarMenu::onTapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
    )
{
        VFX_UNUSED(group);
        VFX_UNUSED(cell);
		VcpMenuPos p(0, pos);
		vfxPostInvoke1(this, &VappWidgetCalendarMenu::onLaunchCalendar,p);
}

void VappWidgetCalendarMenu::setUnSelected()
{
	VcpMenuPos pos;
	VfxU32 flag = 0;
	VappWidgetCalendarCell *cal;
	pos.group = 0;
	pos.pos = m_hl_pos;
	VfxS32 total_count;

	total_count = getLayout()->getCellCount(0);
	if(pos.pos < 0 || pos.pos >= total_count)
		return;
	cal = (VappWidgetCalendarCell*)getCell(pos, flag);
	if(cal)
	    cal->setUnHighlight();
}
VappWidgetCalendarMenuLayout::VappWidgetCalendarMenuLayout(VappWidgetCalendarMenu* menu) :
    VcpBaseMenuLayout(menu)
{
}

VappWidgetCalendarMenuLayout::~VappWidgetCalendarMenuLayout()
{

}

VcpBaseMenuLayout::ScrollDirEnum VappWidgetCalendarMenuLayout::getScrollDir()
{
    return SCROLLDIR_VERT;
}

void VappWidgetCalendarMenuLayout::onInit()
{
    VcpBaseMenuLayout::onInit();

	VfxS32 total_cell_count = 0;
	VfxS32 i = 0, j = 0;
	VfxU8 first_day;

	for(i = VAPP_HS_CALENDAR_FIRST_YEAR; i <= VAPP_HS_CALENDAR_LAST_YEAR; i++)
	{
		if(i%4 == 0)
		{
			j++;
		}
	}

	total_cell_count = (VAPP_HS_CALENDAR_LAST_YEAR - VAPP_HS_CALENDAR_FIRST_YEAR + 1)*365 + j;

	first_day = applib_dt_dow(VAPP_HS_CALENDAR_FIRST_YEAR, 1, 1);

	m_count = (total_cell_count - ( 7 - first_day))/ 7 + 1;

	i = (total_cell_count - ( 7 - first_day))% 7;
    if( i > 0)
	{
		m_count++;
	}

	m_height = VAPP_CLAENDAR_WIDGET_CELL_HEIGHT;
}


void VappWidgetCalendarMenuLayout::getWeekByPos(VfxS32 pos, applib_time_struct *time)
{

	if(pos == 0)
	{
		time->nYear = VAPP_HS_CALENDAR_FIRST_YEAR;
		time->nMonth = 1;
		time->nDay = 1;

		VfxU8 first_day;
		first_day = applib_dt_dow(VAPP_HS_CALENDAR_FIRST_YEAR, 1, 1);

		if(first_day > 0)
		{
			time->nYear = VAPP_HS_CALENDAR_FIRST_YEAR - 1;
			time->nMonth = 12;
			time->nDay = 31 - first_day + 1;
		}
	}
	else
	{
		VfxS32 total_day_count = 0;
		VfxU8 first_day, last_day;
		VfxS32 year_pos;
	    first_day = applib_dt_dow(VAPP_HS_CALENDAR_FIRST_YEAR, 1, 1);

		pos++;

		// find year
		for(VfxS32 i = VAPP_HS_CALENDAR_FIRST_YEAR; i <= VAPP_HS_CALENDAR_LAST_YEAR; i++)
		{
				total_day_count += 365;
				if(i%4 == 0)
					total_day_count++;
				year_pos = (total_day_count - ( 7 - first_day))/7 + 1;

				if((total_day_count - ( 7 - first_day))%7 != 0)
					year_pos++;
				if(year_pos >= pos)
				{
					time->nYear = i;
					break;
				}

		}
        // find month
		if(year_pos == pos)
		{
			last_day = applib_dt_dow(time->nYear, 12, 31);
			time->nMonth = 12;
			time->nDay = 31 - last_day;
		}
		else
		{
			VfxS32 day = 365;
			VfxS32 pos_day;
			VfxS32 total_day = 0;
			VappDateInterface dateInterface;

			last_day = applib_dt_dow(time->nYear, 12, 31);

			if(time->nYear % 4 == 0)
				day = 366;

			pos_day = day - (year_pos - pos + 1) * 7 + (7 - last_day - 1) + 1;

			for(VfxS32 i = 1; i <= 12; i++)
			{
				total_day += dateInterface.getDay(i, time->nYear);
				if(total_day >= pos_day)
				{
					time->nMonth = i;
					break;
				}
			}
			time->nDay = dateInterface.getDay(time->nMonth, time->nYear) - (total_day - pos_day);
			// find day

		}

	}


}
VfxS32 VappDateInterface::getDay(VfxS32 month, VfxS32 year)
{
	if((month == 1) || (month == 3) || ( month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		return 31;
	else if(month == 2)
	{
		if(year % 4 == 0)
			return 29;
		else
			return 28;
	}
	else
		return 30;
}

VfxS32 VappWidgetCalendarMenuLayout::getCellCount(VfxS32 group)
{
    VFX_UNUSED(group);
	return m_count;
}

VfxS32 VappWidgetCalendarMenuLayout::getContentLength()
{
	return m_count * m_height;
}

VcpMenuPos VappWidgetCalendarMenuLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p;
	VfxU32 i;

    p.group = 0;
	i = pt.y/m_height;
    p.pos = i;
    return p;
}

VcpMenuRegion VappWidgetCalendarMenuLayout::queryRegion(const VfxRect &r)
{
    return VcpMenuRegion(getCellByPos(r.origin),
                         getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY())));
}

VfxRect VappWidgetCalendarMenuLayout::queryCellRect(VcpMenuPos pos)
{
	return VfxRect(0, m_height*(pos.pos), VAPP_CALENDAR_WIDGET_CELL_WIDTH, m_height);
}

void VappWidgetCalendarMenuLayout::onViewChanged()
{

}

VfxS32 VappWidgetCalendarMenuLayout::getFirstItem()
{
	return m_first_item;
}
void VappWidgetCalendarMenuLayout::setFirstItem(VfxS32 item)
{
	m_first_item = item;
}
VfxBool VappWidgetCalendarMenuLayout::navDir(NavDirEnum dir)
{
	VfxS32 x, y;
	applib_time_struct time;
	VfxS32 first_day;

	x = m_viewRect.origin.x;
	y = m_viewRect.origin.y;

    VcpMenuPos p = getCellByPos(VfxPoint(x,y));
	setFirstItem(p.pos);
	p.pos +=2;   // make most month area to focus
	getWeekByPos(p.pos, &time);

	if((time.nYear == VAPP_HS_CALENDAR_FIRST_YEAR) && (time.nMonth == 1) ||(time.nYear == VAPP_HS_CALENDAR_FIRST_YEAR-1) )
	{
		p.pos = 0;
		setFocusItem(p);
		return VFX_TRUE;
	}
	
	first_day = applib_dt_dow(time.nYear, time.nMonth, 1);

	p.pos =  p.pos- (time.nDay + first_day) / 7;
    setFocusItem(p);
    return VFX_TRUE;
}

VappCalLineFrame::VappCalLineFrame()
{

}

void VappCalLineFrame::setLineColor(const VfxColor &color)
{
    if (m_color != color)
    {
        m_color = color;
        
    }
}


void VappCalLineFrame::onDraw(VfxDrawContext &dc)
{
	VfxSize size;
	VfxS32 cell_width;
	VfxPoint pos1, pos2;
	VfxS32 column_gap;
	VfxS32 i;

	size = (getBounds()).size;
	cell_width = size.width / 7;
	column_gap = (size.width - cell_width*7)>>1;

	dc.setStrokeColor(m_color);

	pos1.x = 0;
	pos1.y = size.height - 1;

	pos2.x = size.width;
	pos2.y = pos1.y;

	dc.drawLine(pos1, pos2);

	for(i = 1; i <7; i++)
	{
		pos1.x = column_gap + cell_width*i;
		pos1.y = 0;

		pos2.x = pos1.x;
		pos2.y = size.height;

		dc.drawLine(pos1, pos2);
	}
}

VappCalNumberFrame::VappCalNumberFrame()
{
	m_current_index = -1;
	m_style = -1;
}
void VappCalNumberFrame::get_index_coordinate(VfxS32 i, VfxS32 *x, VfxS32 *y, VfxS32 *w, VfxS32 *h)
{
	VfxSize size, temp;
	VfxS32 cell_width, cell_height;
	VfxS32 cell_gap = 0;

	size = (getBounds()).size;
	cell_width = size.width / 7;
	cell_height = size.height;

	cell_gap = size.width % 7;

	if(i == 0)
	{
		*x = 0;
		*y = 0;
		*w = cell_width + cell_gap/2;
		*h = size.height;
	}
	else if( i == 6)
	{
		*x = cell_width * i + cell_gap/2;
		*y = 0;
		*w = cell_width + cell_gap/2;
		*h = size.height;
	}
	else
	{
		*x = cell_width * i + cell_gap/2;
	    *y = 0;
	    *w = cell_width;
	    *h = size.height;
    }
}
void VappCalNumberFrame::onInit(void)
{
	VfxFrame::onInit();

	VFX_OBJ_CREATE(m_rect, VfxImageFrame, this);
	m_rect->setPos(VfxPoint(0, 0));
	m_rect->setResId(IMG_CALENDAR_WIDGET_SEL);
	m_rect->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_rect->setHidden(VFX_TRUE);
	addChildFrame(m_rect);
}

void VappCalNumberFrame::onDeinit(void)
{
	VfxFrame::onDeinit();
	VFX_OBJ_CLOSE(m_rect);
}

void VappCalNumberFrame::setHighlightDay(VfxPoint p)
{
	VfxSize size;
	VfxS32 i;
	VfxS32 x, y, w, h;

	size = (getBounds()).size;
	i = p.x /(size.width / 7);

	get_index_coordinate(i, &x, &y, &w, &h);
	m_rect->setPos(VfxPoint(x, y));
	m_rect->setBounds(VfxRect(0, 0, w, h));
	m_rect->setHidden(VFX_FALSE);
}

void VappCalNumberFrame::setUnHighlightDay()
{
	m_rect->setHidden(VFX_TRUE);
}

void VappCalNumberFrame::setCurrentDayIndex(VfxU8 index)
{
	m_current_index = index;
}

void VappCalNumberFrame::setDayNumber(VfxU8 index, VfxU8 number)
{
	m_day[index] = number;
}
void VappCalNumberFrame::setDayMark(VfxS8 mark)
{
	m_mark = mark;
}

void VappCalNumberFrame::setColorStyle(VfxU8 style)
{
	m_style = style;
	if(style != NON_GREY)
	invalidate();
}

void VappCalNumberFrame::setEvent(VfxS32 index, VfxBool isEvent)
{
	m_event[index] = isEvent;
}

static VfxU8 g_calNumWidth[31] = {0};
static VfxU8 g_calNumHeight = 0;

void VappCalNumberFrame::onDraw(VfxDrawContext &dc)
{
	VfxS32 i;
	VfxS32 x, y, w, h;
	VfxSize size, temp;

	for(i = 0; i < 7; i++)
	{
		 const VfxWChar *buf;
		 VfxWString day_str;
		 get_index_coordinate(i, &x, &y, &w, &h);

		 if(i <= m_mark)
		 {
			 if(m_style == FIRST_GREY)
				dc.setFillColor(VAPP_CALENDAR_NUMBER_GREY_COLOR);
			 else
				dc.setFillColor(VFX_COLOR_BLACK);
		 }
		 if(i > m_mark)
		 {
			 if(m_style == LAST_GREY)
				dc.setFillColor(VAPP_CALENDAR_NUMBER_GREY_COLOR);
			 else
				dc.setFillColor(VFX_COLOR_BLACK);
		 }
			
		 day_str.format("%d", m_day[i]);
		 buf = day_str.getBuf();
		 if(i == m_current_index)
		 {
			 dc.drawResizedImageFromRes(VfxRect(x+1, y, w-1, h-1), IMG_CALENDAR_WIDGET_HL);
			 dc.setFillColor(VFX_COLOR_WHITE);
		 }
		 if(m_event[i] && (((i > m_mark) && (m_style == FIRST_GREY)) || ((i <= m_mark) && (m_style == LAST_GREY) || (m_style == NON_GREY))))
		 {
		 	 VfxSize image_size = VfxImageSrc(IMG_CALENDAR_WIDGET_TIP).getSize();

			 dc.drawImageFromRes(
				 x+w-image_size.width, y,
				 IMG_CALENDAR_WIDGET_TIP);
			 
		 }
		 dc.setFont(VfxFontDesc(VCP_CALENDAR_NUMBER_FONT_SIZE));
		 if(g_calNumWidth[m_day[i]] != 0)
		 {
			 temp.width = g_calNumWidth[m_day[i]];
			 temp.height = g_calNumHeight;
		 }
		 else
		 {
		    temp = VfxFontDesc(VCP_CALENDAR_NUMBER_FONT_SIZE).measureStr(buf);
			g_calNumWidth[m_day[i]] = temp.width;
			g_calNumHeight = temp.height;
		 }

		 if(vrt_sys_get_text_dir() == MG_TEXT_DIR_TYPE_R2L)  // arbic laguage
		 {
			 x = x + (w + temp.width) /2;
			 y = y + (h - temp.height)/2;
		 }
		 else
		 {
 		     x = x + (w - temp.width) / 2;
		     y = y + (h - temp.height) / 2;
		 }
	    
		 dc.drawText(x, y, buf);
	}
}
#endif /* __MMI_VUI_WIDGET_CALENDAR__ */
