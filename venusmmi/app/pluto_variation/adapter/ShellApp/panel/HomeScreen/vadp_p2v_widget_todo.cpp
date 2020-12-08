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
 *  vadp_p2v_widget_photo.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Pluto MMI to the Venus
 *  MMI.
 *
 *      Pluto APP ---> p2v adaptor ---> Venus APP
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_TODO__

#include "trc/vadp_app_trc.h"

extern "C"
{

#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif

#include "TodolistGprot.h"
#include "TodolistSrvGprot.h"
#include "TodolistProt.h"

#include "CalendarGprot.h"
#include "AlarmframeworkProt.h"

#include "gui_effect_oem.h"

#include "ReminderSrvGprot.h"
}

#include "Vadp_p2v_widget_todo.h"
    #include "vfx_cpp_base.h"
    #include "kal_trace.h"
    #include "vfx_system.h"
    #include "vfx_datatype.h"
    #include "vfx_date_time.h"
    #include "custom_mmi_default_value.h"
    #include "kal_general_types.h"
    #include "vfx_string.h"
    #include "MMIDataType.h"
    #include "string.h"
    #include "app_datetime.h"
    #include "kal_public_api.h"
    #include "vrt_datatype.h"
    #include "DateTimeType.h"
/*****************************************************************************
 * Local Variable 
 *****************************************************************************/
// test code on modis
#ifndef __MTK_TARGET__
static VfxU16 count = 0;
#endif

/*****************************************************************************
 * Local Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_todo_is_available
 * DESCRIPTION
 *  This function is to check whether the sync is going on.
 * PARAMETERS
 *	void
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool vadp_p2v_todo_is_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
	if (count != 0)
	{
		count--;
		return VFX_FALSE;
	}
#endif

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_tdl_sync_now())
    {
    	VFX_LOG(VFX_INFO2, VAPP_HS_TODO_AVAILABLE, 0);
		
        return VFX_FALSE;
    }
#endif /*__SYNCML_SUPPORT__*/
	VFX_LOG(VFX_INFO2, VAPP_HS_TODO_AVAILABLE, 1);

    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_todo_show_view
 * DESCRIPTION
 *  This function is to check whether the sync is going on.
 * PARAMETERS
 *  type        : [IN] event or todo
 *	index		: [IN] The event or task index
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_todo_show_view(const VfxU16 &index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_tdl_view_vcalendar(SRV_TDL_VCAL_EVENT, index);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_todo_show_calendar
 * DESCRIPTION
 *  This function is to check whether the sync is going on.
 * PARAMETERS
 *  focusTime   : [IN] event or todo
 *	index		: [IN] The event or task index
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_todo_show_calendar(const VfxDateTime &focusTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxU32 uYear, uMonth, uDay, uHour, uMin, uSec;
	VfxDateTime::DayOfWeekEnum dayIndex;
	MYTIME calTime;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	focusTime.getDate(&uYear, &uMonth, &uDay);
	focusTime.getTime(&uHour, &uMin, &uSec);
	focusTime.getDayOfWeek(&dayIndex);

	calTime.nYear  = (kal_uint16)uYear;
	calTime.nMonth = (kal_uint8)uMonth;
	calTime.nDay   = (kal_uint8)uDay;
	calTime.nHour  = (kal_uint8)uHour;
	calTime.nMin   = (kal_uint8)uMin;
	calTime.nSec   = (kal_uint8)uSec;
	
	calTime.DayIndex = (kal_uint8)dayIndex;
	
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif

	mmi_entry_calendar(calTime);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_get_todo_info
 * DESCRIPTION
 *  This function is to check whether the sync is going on.
 * PARAMETERS
 *  startTime   : [OUT]      The start time
 *  endTime     : [OUT]      The end time
 *  subject		: [OUT]      Subject
 *  location    : [OUT]      Cattegory
 *  index   	: [IN]      index
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool vadp_p2v_get_todo_info(VfxDateTime  &startTime,
									  VfxDateTime  &endTime,
									  VfxWString   &subject,
									  VfxWString   &location,
									  const VfxU16 &index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 ret;
	FREQ_ALARM repeat;
	MYTIME start_time, end_time;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	srv_tdl_event_struct event;
	ret = srv_tdl_get(&event, 
					   sizeof(srv_tdl_event_struct), 
					   SRV_TDL_VCAL_EVENT, 
					   index);
	
	if (ret == SRV_TDL_RESULT_OK)
	{
		subject.loadFromMem((VfxWChar *)event.subject);
		location.loadFromMem((VfxWChar *)event.location);
	
		// temp start time
		repeat = (FREQ_ALARM)mmi_tdl_conv_repeat_type(event.repeat.rule);
		if (repeat == ALM_FREQ_ONCE)
		{
			memcpy(&start_time, &event.start_time, sizeof(MYTIME));
		}
		else
		{
			start_time = srv_reminder_calc_time(&event.start_time, (srv_reminder_repeat_enum)repeat, event.repeat.dows);
		}
		
	
		startTime.setDate(start_time.nYear, start_time.nMonth, start_time.nDay);
		startTime.setTime(start_time.nHour, start_time.nMin, start_time.nSec);

		// temp end time
		memcpy(&end_time, &event.end_time, sizeof(MYTIME));
		end_time.nYear  = start_time.nYear + (event.end_time.nYear - event.start_time.nYear);
		end_time.nMonth = start_time.nMonth + (event.end_time.nMonth - event.start_time.nMonth);
		end_time.nDay   = start_time.nDay + (event.end_time.nDay - event.start_time.nDay);

		endTime.setDate(end_time.nYear, end_time.nMonth, end_time.nDay);
		endTime.setTime(end_time.nHour, end_time.nMin, end_time.nSec);

		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  Vadp_p2v_todo_search_callback
 * DESCRIPTION
 *  This function is to check whether the data will be showed
 * PARAMETERS
 *  data        	: [IN]	event or todo data structure
 *  vcal_type     	: [IN]	event or todo
 *  search_filter	: [IN]	filter infomation
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern "C"
MMI_BOOL Vadp_p2v_todo_search_callback(
                                 const void *data, 
                                 const srv_tdl_vcal_enum vcal_type,
                                 const srv_tdl_search_filter_struct search_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MYTIME refTime;	
    FREQ_ALARM repeat = ALM_FREQ_OFF;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!applib_dt_is_valid((applib_time_struct *)&search_filter.u.date_time))
    {
        goto ret;
    }
	
	// only care event.
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_short_struct *pEvent = (srv_tdl_event_short_struct *)data;
	if (!pEvent->present)
	{
		goto ret;
	}
	// todolist repeat type is diffrent from the standard alarm framework repeat type
	repeat = (FREQ_ALARM)mmi_tdl_conv_repeat_type(pEvent->repeat.rule);
	if (repeat == ALM_FREQ_ONCE)
	{
	    memcpy(&refTime, &pEvent->start_time, sizeof(MYTIME));
	}
	else
	{
	    refTime = srv_reminder_calc_time(&pEvent->start_time, (srv_reminder_repeat_enum)repeat, pEvent->repeat.dows);
	}
    }
    else
    {
	VFX_ASSERT(!"Don't care this vCalendar type");
    }
                
    VFX_LOG(VFX_INFO2, 
	VAPP_HS_TODO_SEARCH_CALLBACK,
	refTime.nYear,
	refTime.nMonth,
	refTime.nDay,
	refTime.nHour,
	refTime.nMin,
	refTime.nSec,
	repeat);
                
    if (CompareTime(refTime, search_filter.u.date_time, NULL) >= 0)
    {
 	result = MMI_TRUE;
    }
 
ret:

    VFX_LOG(VFX_INFO2, VAPP_HS_TODO_SEARCH_CALLBACK_RET, result);
	
    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  Vadp_p2v_todo_sort_callback
 * DESCRIPTION
 *  Compare two data. if data1 > data2, the index will be swapped.
 * PARAMETERS
 *  data1     : [IN] The first data to be checked.
 *  data2     : [IN] The first data to be checked.
 *  sort_type : [IN] The check criterion.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  +1 : data1 > data2.
 *  0  : data1 == data2.
 *  -1 : data1 < data2.
 *****************************************************************************/ 
static srv_tdl_compare_result_enum Vadp_p2v_todo_sort_callback(
                                          const U16 index1,
                                          const U16 type1, 
                                          const U16 index2, 
                                          const U16 type2, 
                                          const srv_tdl_sort_type_enum sort_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_compare_result_enum result;
    srv_tdl_event_short_struct *pevent1, *pevent2;
    FREQ_ALARM repeat;
    MYTIME refTime1, refTime2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_UNUSED(sort_type);
    if (type1 != SRV_TDL_VCAL_EVENT || type2 != SRV_TDL_VCAL_EVENT)
    {
        return SRV_TDL_COMPARE_END_OF_ENUM;
    }
    
    pevent1 = (srv_tdl_event_short_struct *)mmi_tdl_get_event_node(index1);
    pevent2 = (srv_tdl_event_short_struct *)mmi_tdl_get_event_node(index2);
	
    // todolist repeat type is diffrent from the standard alarm framework repeat type
    repeat = (FREQ_ALARM)mmi_tdl_conv_repeat_type(pevent1->repeat.rule);
    refTime1 = srv_reminder_calc_time(&pevent1->start_time,(srv_reminder_repeat_enum) repeat, pevent1->repeat.dows);

    repeat = (FREQ_ALARM)mmi_tdl_conv_repeat_type(pevent2->repeat.rule);
    refTime2 = srv_reminder_calc_time(&pevent2->start_time, (srv_reminder_repeat_enum)repeat, pevent2->repeat.dows);

    result = (srv_tdl_compare_result_enum)CompareTime(refTime1, refTime2, NULL);

    /* If have the same start time, the earlier one will be at the fore place.*/
    if (result == DT_TIME_EQUAL)
    {
        result = (srv_tdl_compare_result_enum)CompareTime(pevent1->created_time, pevent2->created_time, NULL);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Vadp_p2v_todo_get_recent
 * DESCRIPTION
 *  This function is to get recent item
 * PARAMETERS
 *  buffer      : [OUT] The id index buffer
 * RETURNS
 *  1	-> OK
 *	0	-> No event
 *****************************************************************************/
VfxBool Vadp_p2v_todo_get_recent(VfxU16* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxU16 cnt_vevent;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tdl_get_all_index(NULL, 0, SRV_TDL_VCAL_EVENT, &cnt_vevent);

	if (cnt_vevent == 0)
	{
		return VFX_FALSE;
	}

	srv_tdl_event_task_struct *list;
	VfxU16 size = sizeof(srv_tdl_event_task_struct) * NUM_OF_TDL;
	
    list = (srv_tdl_event_task_struct *)VfxBase::allocSysMemory(size);
	
	srv_tdl_search_filter_struct filter;
	
	GetDateTime(&filter.u.date_time);
	// clear the nSec field, because event and task has no second field.
	filter.u.date_time.nSec = 0;
	
	VFX_LOG(VFX_INFO2, 
			VAPP_HS_TODO_SEARCH_TIME, 
			filter.u.date_time.nYear,
			filter.u.date_time.nMonth,
			filter.u.date_time.nDay,
			filter.u.date_time.nHour,
			filter.u.date_time.nMin,
			filter.u.date_time.nSec);
	
	VfxU16 count;

    srv_tdl_search_ext(list, 
                       NUM_OF_TDL, 
                       SRV_TDL_VCAL_EVENT, 
                       filter, 
                       &count, 
                       Vadp_p2v_todo_search_callback);

	if (count > 1)
	{
		srv_tdl_sort_ext(list, 
						 count,
						 SRV_TDL_SORT_TYPE_ENTRY_TIME, 
						 Vadp_p2v_todo_sort_callback);
	}

	// the first position.	
	*index = list[0].index;
	
    VfxBase::freeSysMemory(list);
 
    return (count != 0);
}

#endif /* __MMI_VUI_HOMESCREEN_TODO__ */

