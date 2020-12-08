/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_hs_widget_todo.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget:  todo
 *						 view the incoming event, only show the event in calendar.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_TODO__
#include "GlobalResDef.h"
#include "vapp_hs_widget_todo.h"
#include "HomeScreen\vadp_p2v_widget_todo.h"
#include "vdat_include.h"

    #include "vfx_control.h"
    #include "vfx_cpp_base.h"
    #include "vfx_sys_memory.h"
    #include "vfx_object.h"
    #include "vfx_primitive_frame.h"
    #include "vfx_date_time.h"
    #include "mmi_rp_app_venus_hs_todo_def.h"
    #include "vfx_basic_type.h"
    #include "vfx_datatype.h"
    #include "vfx_timer.h"
    #include "vfx_signal.h"
    #include "vfx_text_frame.h"
    #include "vrt_datatype.h"
    #include "vfx_font_desc.h"
    #include "vfx_string.h"
    #include "vdat_systime.h"
    #include "vfx_async_signal.h"
    #include "vfx_input_event.h"
    #include "vapp_hs_widget_base.h"
/***************************************************************************** 
 * VappHsWidgetTodoImage Implement 
 *****************************************************************************/
VappHsWidgetTodoImage::VappHsWidgetTodoImage() :
	m_imgMonth(NULL),
	m_imgDayL(NULL),
	m_imgDayR(NULL)
{
	
}

void VappHsWidgetTodoImage::onInit()
{
	VfxControl::onInit();

	// Add local init
	VFX_OBJ_CREATE(m_imgMonth, VfxImageFrame, this);
	VFX_OBJ_CREATE(m_imgDayL,  VfxImageFrame, this);
	VFX_OBJ_CREATE(m_imgDayR,  VfxImageFrame, this);
}
void VappHsWidgetTodoImage::setTime(const VfxDateTime & date)
{
	m_imgMonth->setResId(VAPP_HS_IMG_WG_TODO_MONTH1 + date.getMonth() - 1);
	m_imgMonth->setPos(VfxPoint(VappHsWidgetTodo::MON_POS_X, VappHsWidgetTodo::MON_POS_y));

	m_imgDayL->setResId(VAPP_HS_IMG_WG_TODO_NUM0 + date.getDay() / 10);
	m_imgDayL->setPos(VfxPoint(VappHsWidgetTodo::DAY_LEFT_POS_X, VappHsWidgetTodo::DAY_LEFT_POS_Y));

	m_imgDayR->setResId(VAPP_HS_IMG_WG_TODO_NUM0 + date.getDay() % 10);
	m_imgDayR->setPos(VfxPoint(VappHsWidgetTodo::DAY_RIGHT_POS_X, VappHsWidgetTodo::DAY_RIGHT_POS_Y));
}

void VappHsWidgetTodoImage::clearAll(void)
{
	m_imgMonth->setNull();
	m_imgDayL->setNull();
	m_imgDayR->setNull();
}

/***************************************************************************** 
 * VappHsTodoAnimateControl Implement 
 *****************************************************************************/
VappHsTodoAnimateControl::VappHsTodoAnimateControl() : 
	m_frmImage(NULL),
	m_timerTick(NULL),						
	m_sStartResId(-1),
	m_nCount(-1),
	m_nDuration(100)
{
}

VappHsTodoAnimateControl::VappHsTodoAnimateControl(const VfxS32 &startResId, const VfxS32 &resCount) :
	m_frmImage(NULL),
	m_timerTick(NULL),
	m_sStartResId(startResId),
	m_nCount(resCount),
	m_nDuration(100)
{
}

void VappHsTodoAnimateControl::onInit(void)
{
	// loading animation frame
	VfxControl::onInit();

	// loading animation frame
	VFX_OBJ_CREATE(m_frmImage, VfxImageFrame, this);
	m_frmImage->setResId(m_sStartResId);
	setBounds(m_frmImage->getBounds());
	m_frmImage->setPos(VFX_POINT_ZERO);
}

void VappHsTodoAnimateControl::startAnimate(void)
{
	if (m_timerTick == NULL)
	{
		VFX_OBJ_CREATE(m_timerTick, VfxTimer, this);
		m_timerTick->setDuration(m_nDuration);
		m_timerTick->m_signalTick.connect(this, &VappHsTodoAnimateControl::onTimerExpire);
	}
	m_timerTick->start();
}

void VappHsTodoAnimateControl::stopAnimate(void)
{
	if (m_timerTick != NULL)
	{
		m_timerTick->stop();
		VFX_OBJ_CLOSE(m_timerTick);
	}
}

void VappHsTodoAnimateControl::setDuration(const VfxU16 & mesc)
{
	m_nDuration = mesc;
}
void VappHsTodoAnimateControl::setRes(const VfxS32 &startResId, const VfxS32 &resCount)
{
	m_sStartResId = startResId;
	m_nCount = resCount;
}

void VappHsTodoAnimateControl::onTimerExpire(VfxTimer * source)
{
	VFX_UNUSED(source);
	
	VfxS32 resId = m_frmImage->getResId() - m_sStartResId;
	VfxS32 newId = ++resId % m_nCount;
	
	m_frmImage->setResId(newId + m_sStartResId);
}


/***************************************************************************** 
 * Home screen widget: VappHsWidgetTodo
 *****************************************************************************/
 VappHsWidgetTodo::VappHsWidgetTodo() : 
	m_imgDate(NULL),
	m_animLoad(NULL),
	m_txtLocation(NULL),
	m_txtSubject(NULL),
	m_txtTime(NULL),
	m_imgBg(NULL),
	m_imgCalBg(NULL),
	m_txtLoading(NULL),
	m_timerCheck(NULL),
	m_uIndex(0xFFFF),
	m_eViewMode(VIEW_TOTAL)
{
	m_tmCurr.setCurrentTime();
}

void VappHsWidgetTodo::onCreateView()
{
	VFX_OBJ_CREATE(m_imgBg, VfxImageFrame, this);
	m_imgBg->setResId(VAPP_HS_IMG_WG_TODO_BG);
	m_imgBg->setIsCached(VFX_TRUE);
	setBounds(m_imgBg->getBounds());
	
	if (!vadp_p2v_todo_is_available())
	{
		VfxU16 count = VAPP_HS_IMG_WG_TODO_LOADING_TOTAL - VAPP_HS_IMG_WG_TODO_LOADING0;
		VFX_OBJ_CREATE_EX(m_animLoad, 
					   	  VappHsTodoAnimateControl, 
					      this, 
					      (VAPP_HS_IMG_WG_TODO_LOADING0, count));

		m_animLoad->setPos(VfxPoint(ANIM_LOADING_POX_X, ANIM_LOADING_POX_Y));
		
		// Loading text
		VFX_OBJ_CREATE(m_txtLoading, VfxTextFrame, this);
		m_txtLoading->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		m_txtLoading->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		m_txtLoading->setColor(VFX_COLOR_WHITE);
		m_txtLoading->setFont(VFX_FONT_DESC_LARGE);
		
		VfxWString strLoading;
		strLoading.loadFromRes(STR_GLOBAL_LOADING);
		VfxSize size = m_txtLoading->getFont().measureStr(strLoading.getBuf());
		VfxS32 y = ANIM_LOADING_POX_Y + (m_animLoad->getBounds().getHeight() - size.height)/2;
		m_txtLoading->setPos(VfxPoint(TXT_LOADING_POX_X, y));
		m_txtLoading->setBounds(VfxRect(VfxPoint(0, 0), VfxSize(TXT_LOADING_WIDTH, TXT_LOADING_HEIGHT)));
		m_txtLoading->setString(strLoading);
		
		// start animation
		m_animLoad->startAnimate();

		// Timer will check whether the Todo is availble again and again.		
		VFX_OBJ_CREATE(m_timerCheck, VfxTimer, this);
	    m_timerCheck->setDuration(2000);
	    m_timerCheck->m_signalTick.connect(this, &VappHsWidgetTodo::onTimerExpire);
		m_timerCheck->start();
		
		return;
	}	

	initContent();
}

void VappHsWidgetTodo::initContent(void)
{
	VFX_OBJ_CREATE(m_imgCalBg, VfxImageFrame, this);
	m_imgCalBg->setResId(VAPP_HS_IMG_WG_TODO_CAL_BG);
	m_imgCalBg->setIsCached(VFX_TRUE);
	m_imgCalBg->setPos(VFX_POINT_ZERO);
	
	VFX_OBJ_CREATE(m_imgDate, 	  VappHsWidgetTodoImage, this);
	m_imgDate->setBounds(VfxRect(VfxPoint(0, 0), VfxSize(DATE_WIDTH, DATE_HEIGHT)));
	m_imgDate->setPos(VfxPoint(DATE_POS_X, DATE_POS_Y));
	
	VFX_OBJ_CREATE(m_txtTime, 	  VfxTextFrame, this);
	m_txtTime->setPos(VfxPoint(TXT_POS_X, TIME_POS_Y));
	m_txtTime->setBounds(VfxRect(VfxPoint(0, 0), VfxSize(STRING_WIDTH, STRING_HEIGHT)));
	m_txtTime->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_txtTime->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	m_txtTime->setColor(VFX_COLOR_WHITE);
	m_txtTime->setFont(VFX_FONT_DESC_SMALL);
	
	VFX_OBJ_CREATE(m_txtSubject,  VfxTextFrame, this);
	m_txtSubject->setPos(VfxPoint(TXT_POS_X, SUB_POS_Y));
	m_txtSubject->setBounds(VfxRect(VfxPoint(0, 0), VfxSize(STRING_WIDTH, STRING_HEIGHT)));
	m_txtSubject->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	m_txtSubject->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_txtSubject->setColor(VFX_COLOR_WHITE);
	m_txtSubject->setFont(VFX_FONT_DESC_MEDIUM);
	
	VFX_OBJ_CREATE(m_txtLocation, VfxTextFrame, this);	
	m_txtLocation->setPos(VfxPoint(TXT_POS_X, LOC_POS_Y));
	m_txtLocation->setBounds(VfxRect(VfxPoint(0, 0), VfxSize(STRING_WIDTH, STRING_HEIGHT)));
	m_txtLocation->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	m_txtLocation->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_txtLocation->setColor(VFX_COLOR_WHITE);
	m_txtLocation->setFont(VFX_FONT_DESC_SMALL);
	
    // Refresh timer
    VdatTimeNotification *sysTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    sysTimeSrv->m_signalTimeChanged.connect(this, &VappHsWidgetTodo::onTimeChanged);

	query();
}

void VappHsWidgetTodo::onReleaseView()
{
    VdatTimeNotification *sysTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    sysTimeSrv->m_signalTimeChanged.disconnect(this, &VappHsWidgetTodo::onTimeChanged);

	// the widget object will not close even if it is dragged out of the desktop
	// so every widget must clean all its content.
	VFX_OBJ_CLOSE(m_txtTime);
	VFX_OBJ_CLOSE(m_txtSubject);
	VFX_OBJ_CLOSE(m_txtLocation);
	VFX_OBJ_CLOSE(m_imgDate);
	VFX_OBJ_CLOSE(m_imgCalBg);
	VFX_OBJ_CLOSE(m_imgBg);

	VFX_OBJ_CLOSE(m_timerCheck);
	VFX_OBJ_CLOSE(m_txtLoading);
	VFX_OBJ_CLOSE(m_animLoad);
}

void VappHsWidgetTodo::onTimerExpire(VfxTimer * source)
{
	if (vadp_p2v_todo_is_available())
	{
		VFX_OBJ_CLOSE(source);
		
		m_animLoad->stopAnimate();
		VFX_OBJ_CLOSE(m_animLoad);
		VFX_OBJ_CLOSE(m_txtLoading);
		
		initContent();
	}
}
VfxWString VappHsWidgetTodo::formatTimeString(const VfxDateTime &startTime, const VfxDateTime &endTime)
{
	VfxDateTime todayStart, todayEnd;
	VfxDateTime::CompareEnum ret;
	VfxWString strTime;

	todayStart = startTime;
	todayEnd = todayStart;
	todayStart.setTime(0, 0, 0);
	todayEnd.setTime(23, 59, 59);

	VfxWChar buffer[MAX_TEXT_LEN];

	startTime.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE, 
								buffer, 
								MAX_TEXT_LEN);
	
	strTime.loadFromMem(buffer);
	
	//start time >= current time

	VfxWString strEndTime;
	VfxWString strToken;
	strToken.format(" - ");
	
	ret = endTime.compareWith(todayEnd);
	if (ret == VfxDateTime::LESS) // end time < today end
	{
		endTime.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE, 
								  buffer, 
								  MAX_TEXT_LEN);
		
		strEndTime.loadFromMem(buffer);
		
		strTime += strToken;
		strTime += strEndTime;
	}
	else
	{
		endTime.getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY, 
								  buffer, 
								  MAX_TEXT_LEN);
		// show start time -> end date.
		strEndTime.loadFromMem(buffer);
		
		strTime += strToken;
		strTime += strEndTime;

	}
	
	return strTime;
}


void VappHsWidgetTodo::query(void)
{
	if (Vadp_p2v_todo_get_recent(&m_uIndex))
	{
		VfxDateTime startTime, endTime;
		VfxWString strSubject, strLocation;
		
		vadp_p2v_get_todo_info(startTime, endTime, strSubject, strLocation, m_uIndex);

		m_imgDate->setTime(startTime);
		m_txtTime->setString(formatTimeString(startTime, endTime));
		m_txtSubject->setString(strSubject);
		m_txtLocation->setString(strLocation);

		m_tmCurr = startTime;
	}
	else
	{
		m_imgDate->clearAll();
		m_txtTime->setString(VFX_WSTR_NULL);
		//m_txtSubject->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		VfxWString string;
		string.loadFromRes(VAPP_HS_STR_WG_TODO_NO_EVENTS);
		m_txtSubject->setString(string);
		m_txtLocation->setString(VFX_WSTR_NULL);
		m_uIndex = 0xFFFF;
		m_tmCurr.setCurrentTime();
	}
}

void VappHsWidgetTodo::onTimeChanged(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_MIN)
    {
    	query();
	}
}

void VappHsWidgetTodo::onDirectLaunch(void)
{
	if (m_eViewMode == VIEW_CALENDAR)
	{
		vfxPostInvoke(this, &VappHsWidgetTodo::showCalendar);
	}
	else if (m_eViewMode == VIEW_DETAIL)
	{
		vfxPostInvoke(this, &VappHsWidgetTodo::viewEvent);
	}
	
	m_eViewMode = VIEW_TOTAL;
}

VfxBool VappHsWidgetTodo::onPenInput(VfxPenEvent & event)
{
	VfxPoint point;
	
	switch(event.type)
	{
	case VFX_PEN_EVENT_TYPE_DOWN:
	case VFX_PEN_EVENT_TYPE_MOVE:
		break;
		
	case VFX_PEN_EVENT_TYPE_UP:
		// on Loading, don't reponse to any pen event.
		if (isLoading())
		{
			break;
		}
		// hit on date
		point = event.getRelPos(this);
		if (isInCalendar(point))
		{
			m_eViewMode = VIEW_CALENDAR;
			break;
		}
		
		// hit on detail
		if (isInDetail(point))
		{
			if (m_uIndex != 0xFFFF)
			{
				m_eViewMode = VIEW_DETAIL;
			}
			else
			{
				m_eViewMode = VIEW_CALENDAR;
			}
			break;
		}

		break;

	default:
		break;
	}
	
	return VappHsWidget::onPenInput(event);
}

VfxBool VappHsWidgetTodo::isInCalendar(const VfxPoint &point) const
{
	if (point.x >= CAL_HOT_POS_LEFT_X && 
		point.x <= CAL_HOT_POS_RIGHT_X &&
		point.y >= CAL_HOT_POS_LEFT_Y && 
		point.y <= CAL_HOT_POS_RIGHT_Y)
	{
		return VFX_TRUE;
	}
	
	return VFX_FALSE;
}

VfxBool VappHsWidgetTodo::isInDetail(const VfxPoint &point) const
{
	if (point.x >= TXT_POS_X && 
		point.x <= (TXT_POS_X + STRING_WIDTH) &&
		point.y >= TIME_POS_Y &&
		point.y <= (LOC_POS_Y + 20))
	{
		return VFX_TRUE;
	}
	
	return VFX_FALSE;
}

VfxBool VappHsWidgetTodo::isLoading(void) const
{
	return (m_animLoad != NULL);
}

void VappHsWidgetTodo::showCalendar(void *data)
{
	VFX_UNUSED(data);

	vadp_v2p_todo_show_calendar(m_tmCurr);
}

void VappHsWidgetTodo::viewEvent(void *data)
{
	VFX_UNUSED(data);
	vadp_v2p_todo_show_view(m_uIndex);
}

#endif /* __MMI_VUI_HOMESCREEN_TODO__ */

